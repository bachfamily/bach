/*
 *  codebox.c
 *
 * Copyright (C) 2010-2025 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 @file
 codebox.c

 @name
 bach.codebox

 @realname
 bach.codebox

 @type
 object

 @module
 bach

 @author
 bachproject

 @digest
 Evaluate bell code typed in a code box

 @description
 Like <o>bach.eval</o>, evaluates bell code with variables, branching, loops and user-defined functions,
 but the code is typed directly inside the object box, in a syntax-highlighted editor.

 @discussion
 The code is compiled when the hammer button at the bottom of the object is clicked,
 or when Cmd+Return (Ctrl+Enter on Windows) is pressed while editing.
 Inlets and outlets are automatically added or removed according to the
 pseudovariables used in the code (<m>$i1</m>, <m>$o2</m>, <m>directin()</m>...).

 @category
 bach, bach objects, bach llll, bach math, bach interface

 @keywords
 expression, evaluate, variable, number, calculate, compute, function, code, if, branching, editor, codebox

 @seealso
 bach.eval, bach.expr, bach.value, bach.pv

 @owner
 Daniele Ghisi
 */

#include "foundation/llllobj.h"
#include "foundation/llll_commons_ext.h"
#include "graphics/bach_graphics.h"
#include "bell/bach_codableobj.hpp"
#include "bell/ast.hpp"
#include "bell/pvManager.hpp"
#include "bell/ownedFunction.hpp"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"

#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cstdio>
#include <cmath>

#ifdef WIN_VERSION
#include <windows.h>
#endif


////////////////////////////////////////////////////////////////////////
// SYNTAX HIGHLIGHTING
//
// The rules below are a 1:1 transcription of bell.tmLanguage,
// with the same order and the same TextMate semantics:
// at each position, the first rule (in order) matching there wins.
// The lookahead (?=[\s\(\)...]) is the same as in the grammar;
// to make it work at the end of the text, a '\n' is appended before tokenizing.
////////////////////////////////////////////////////////////////////////

enum e_cbScope {
    CB_SCOPE_TEXT = 0,          // no scope (plain text)
    CB_SCOPE_CONSTANT_OTHER,    // constant.other.bell
    CB_SCOPE_NUMBER,            // constant.numeric.bell
    CB_SCOPE_PSEUDOVARIABLE,    // variable.language.bell
    CB_SCOPE_PARAMETER,         // variable.parameter.bell
    CB_SCOPE_CONTROL,           // keyword.control.bell
    CB_SCOPE_STORAGE,           // storage.modifier.bell
    CB_SCOPE_FUNCTION,          // support.function.general.bell
    CB_SCOPE_OPERATOR,          // keyword.operator.bell
    CB_SCOPE_KEYWORD_OTHER,     // keyword.other.bell
    CB_SCOPE_CONSTANT_LANGUAGE, // constant.language.bell
    CB_SCOPE_COMMENT,           // comment.line.bell, comment.block.bell
    CB_SCOPE_STRING,            // string.bell, string.unquoted.bell
    CB_SCOPE_MAXMESSAGE,        // support.function.max.bell
    CB_SCOPE_VARIABLE,          // variable.other.bell
    CB_NUM_SCOPES
};

struct t_cbRule {
    std::regex re;          // the match regex, or the begin regex for begin/end rules
    std::regex endRe;       // only for begin/end rules
    bool beginEnd;
    int scope;              // "name"
    int contentScope;       // "contentName", only for begin/end rules
    bool firstChar[256];    // quick filter: bytes that can start a match
};

struct t_cbSpan {
    long start;
    long end;
    int scope;
};

static std::vector<t_cbRule> *s_cbRules = nullptr;

#define CB_DELIM R"RX((?=[\s\(\)\[\]+\-*/%!=~_<>;,.:]))RX"

static t_cbRule cb_makeRule(const std::string &re, int scope, const char *firstChars, bool letters, bool digits)
{
    t_cbRule r;
    r.re = std::regex(re, std::regex::ECMAScript | std::regex::optimize);
    r.beginEnd = false;
    r.scope = scope;
    r.contentScope = scope;
    for (int i = 0; i < 256; i++) {
        r.firstChar[i] = (letters && isalpha(i)) || (digits && isdigit(i));
    }
    for (const char *c = firstChars; c && *c; c++)
        r.firstChar[(unsigned char) *c] = true;
    return r;
}

static t_cbRule cb_makeBeginEndRule(const std::string &begin, const std::string &end, int scope, int contentScope, const char *firstChars)
{
    t_cbRule r = cb_makeRule(begin, scope, firstChars, false, false);
    r.endRe = std::regex(end, std::regex::ECMAScript | std::regex::optimize);
    r.beginEnd = true;
    r.contentScope = contentScope;
    return r;
}

static void cb_buildRules()
{
    if (s_cbRules)
        return;
    s_cbRules = new std::vector<t_cbRule>;
    std::vector<t_cbRule> &R = *s_cbRules;
    const std::string D = CB_DELIM;

    // pitches with tones, e.g. C#4+1/2t
    R.push_back(cb_makeRule(R"RX(([a-g]|[A-G])([#bxdq\^v]+)?[-+]?[0-9]+[-+](([0-9]+(/[0-9])?)|((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE]([-+]?)[0-9]+))t)RX" + D,
                            CB_SCOPE_CONSTANT_OTHER, "abcdefgABCDEFG", false, false));
    // pitches, accidentals after the octave
    R.push_back(cb_makeRule(R"RX(([a-g]|[A-G])([-+]?)([0-9]+)([#bxdq\^v]+))RX" + D,
                            CB_SCOPE_NUMBER, "abcdefgABCDEFG", false, false));
    // pitches
    R.push_back(cb_makeRule(R"RX(([a-g]|[A-G])([#bxdq\^v]+)?[-+]?[0-9]+)RX" + D,
                            CB_SCOPE_NUMBER, "abcdefgABCDEFG", false, false));
    // rationals
    R.push_back(cb_makeRule(R"RX([0-9]+/[0-9]+)RX" + D,
                            CB_SCOPE_NUMBER, nullptr, false, true));
    // floats (NB: as in the grammar, the lookahead only applies to the second alternative)
    R.push_back(cb_makeRule(R"RX(((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE]([-+]?)[0-9]+))RX" + D,
                            CB_SCOPE_NUMBER, ".", false, true));
    // integers
    R.push_back(cb_makeRule(R"RX([0-9]+)RX" + D,
                            CB_SCOPE_NUMBER, nullptr, false, true));
    // pseudovariables
    R.push_back(cb_makeRule(R"RX(\$(i|r|f|p|x|l|o|dx|do)[0-9]+)RX" + D,
                            CB_SCOPE_PSEUDOVARIABLE, "$", false, false));
    // named parameters
    R.push_back(cb_makeRule(R"RX(@[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?)RX" + D,
                            CB_SCOPE_PARAMETER, "@", false, false));
    // control keywords
    R.push_back(cb_makeRule(R"RX((for|in|do|collect|with|as|while|if|then|else))RX" + D,
                            CB_SCOPE_CONTROL, "fidcwate", false, false));
    // storage modifiers
    R.push_back(cb_makeRule(R"RX((keep|unkeep|init))RX" + D,
                            CB_SCOPE_STORAGE, "kui", false, false));
    // functions (1)
    R.push_back(cb_makeRule(R"RX((length|depth|is|nth|sort|contains|rev|rot|trans|flat|slice|left|right|subs|insert|find|finditems|findaddrs|scramble|minmax|perm|comb|cartesianprod|wrap|group|delace|thin|classify|union|intersection|symdiff|diff|primeser|arithmser|geomser|map|reduce|apply|sum|prod))RX" + D,
                            CB_SCOPE_FUNCTION, nullptr, true, false));
    // functions (2)
    R.push_back(cb_makeRule(R"RX((cos|sin|tan|exp|log|acos|asin|atan|cosh|sinh|tanh|exp2|log2|sqrt|ceil|acosh|asinh|atanh|log10|floor|round|trunc|fmod|atan2|hypot|pow|int|rat|num|den|abs|sgn|float|pitch|degree|octave|alter|cents|pow|mod|min|max|random|bessel|approx|enharm|makepitch|makepitchsc|outlet|inlet|\$args|directin|directout|print|\$argcount|minimum|maximum|mc2f|f2mc))RX" + D,
                            CB_SCOPE_FUNCTION, "$", true, false));
    // operators (transcribed verbatim, including the missing '|' between "|||=" and "|||<<=")
    R.push_back(cb_makeRule(R"RX(\+=|-=|->|\+|-|\*=|\*|\*\*=|\*\*|/=|/|//=|//|%=|%|=|==|!|~|!=|<|>|<=|>=|&=|&|\^=|\^|\|=|\||&&=|&&|&&&=|&&&|\^\^=|\^\^|\|\|=|\|\||\|\|\|=|\|\|\|<<=|<<|>>=|>>|:=|::|:|\.=|_=|!_=|\.\.\.|:\*|\.)RX",
                            CB_SCOPE_OPERATOR, "+-*/%=!~<>&^|:._", false, false));
    // operators as functions
    R.push_back(cb_makeRule(R"RX(#\+|#-|#u-|#\*|#/|#//|#%|#==|#!=|#<|#>|#<=|#>=|#&|#\^|#\||#&&|#\^\^|#\|\||#&&&|#\|\|\||#<<|#>>)RX",
                            CB_SCOPE_FUNCTION, "#", false, false));
    // other keywords
    R.push_back(cb_makeRule(R"RX(<\.\.\.>|-\^)RX",
                            CB_SCOPE_KEYWORD_OTHER, "<-", false, false));
    // separators
    R.push_back(cb_makeRule(R"RX(;|\[|\]|\.)RX",
                            CB_SCOPE_OPERATOR, ";[].", false, false));
    // language constants
    R.push_back(cb_makeRule(R"RX((null|nil|pi))RX" + D,
                            CB_SCOPE_CONSTANT_LANGUAGE, "np", false, false));
    // line comments
    R.push_back(cb_makeRule(R"RX((##|#!).*)RX",
                            CB_SCOPE_COMMENT, "#", false, false));
    // include(...)
    R.push_back(cb_makeBeginEndRule(R"RX(include\()RX", R"RX(\))RX",
                                    CB_SCOPE_KEYWORD_OTHER, CB_SCOPE_STRING, "i"));
    // {max messages}
    R.push_back(cb_makeBeginEndRule(R"RX(\{)RX", R"RX(\})RX",
                                    CB_SCOPE_FUNCTION, CB_SCOPE_MAXMESSAGE, "{"));
    // block comments
    R.push_back(cb_makeBeginEndRule(R"RX(#\()RX", R"RX(\)#)RX",
                                    CB_SCOPE_COMMENT, CB_SCOPE_COMMENT, "#"));
    // variables
    R.push_back(cb_makeRule(R"RX([\$#]?([a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?))RX" + D,
                            CB_SCOPE_VARIABLE, "$#", true, false));
    // backtick symbols
    R.push_back(cb_makeRule(R"RX(`[^\s]+)RX" + D,
                            CB_SCOPE_STRING, "`", false, false));
    // double-quoted strings
    R.push_back(cb_makeRule(R"RX(["]("\\\""|[^"])*[^\\]["])RX" + D,
                            CB_SCOPE_STRING, "\"", false, false));
    // single-quoted strings
    R.push_back(cb_makeRule(R"RX([']("\\'"|[^'])*[^\\]['])RX" + D,
                            CB_SCOPE_STRING, "'", false, false));
}

static void cb_highlight(const std::string &text, std::vector<t_cbSpan> &spans)
{
    spans.clear();
    if (!s_cbRules)
        return;
    const std::string s = text + "\n";
    const char *base = s.c_str();
    const char *end = base + s.size();
    const long n = (long) text.size();
    long p = 0;
    std::cmatch m;

    while (p < n) {
        unsigned char c = (unsigned char) s[p];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            p++;
            continue;
        }
        bool matched = false;
        for (const t_cbRule &r : *s_cbRules) {
            if (!r.firstChar[c])
                continue;
            if (!std::regex_search(base + p, end, m, r.re, std::regex_constants::match_continuous))
                continue;
            long len = (long) m.length(0);
            if (len <= 0)
                continue;
            if (!r.beginEnd) {
                long e = std::min(p + len, n);
                spans.push_back({p, e, r.scope});
                p = e;
            } else {
                long cs = std::min(p + len, n); // content start
                long ce = n, e = n;             // content end, rule end
                std::cmatch me;
                if (std::regex_search(base + cs, end, me, r.endRe)) {
                    ce = std::min(cs + (long) me.position(0), n);
                    e = std::min(ce + (long) me.length(0), n);
                }
                spans.push_back({p, cs, r.scope});
                if (ce > cs)
                    spans.push_back({cs, ce, r.contentScope});
                if (e > ce)
                    spans.push_back({ce, e, r.scope});
                p = e;
            }
            matched = true;
            break;
        }
        if (!matched) {
            // skip one UTF-8 character
            p++;
            while (p < n && (((unsigned char) s[p]) & 0xC0) == 0x80)
                p++;
        }
    }
}


////////////////////////////////////////////////////////////////////////
// CLIPBOARD
// The Max SDK doesn't expose the system text clipboard, so we go native.
////////////////////////////////////////////////////////////////////////

static std::string s_cbClipboardFallback;

static void cb_clipboard_set(const std::string &s)
{
    s_cbClipboardFallback = s;
#ifdef MAC_VERSION
    if (FILE *p = popen("LANG=en_US.UTF-8 /usr/bin/pbcopy", "w")) {
        fwrite(s.data(), 1, s.size(), p);
        pclose(p);
    }
#endif
#ifdef WIN_VERSION
    int wlen = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);
    if (wlen > 0 && OpenClipboard(NULL)) {
        EmptyClipboard();
        HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, wlen * sizeof(wchar_t));
        if (h) {
            wchar_t *w = (wchar_t *) GlobalLock(h);
            MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, w, wlen);
            GlobalUnlock(h);
            if (!SetClipboardData(CF_UNICODETEXT, h))
                GlobalFree(h);
        }
        CloseClipboard();
    }
#endif
}

static std::string cb_clipboard_get()
{
    std::string out;
    bool ok = false;
#ifdef MAC_VERSION
    if (FILE *p = popen("LANG=en_US.UTF-8 /usr/bin/pbpaste", "r")) {
        char buf[4096];
        size_t r;
        while ((r = fread(buf, 1, sizeof(buf), p)) > 0)
            out.append(buf, r);
        ok = pclose(p) == 0;
    }
#endif
#ifdef WIN_VERSION
    if (OpenClipboard(NULL)) {
        if (HANDLE h = GetClipboardData(CF_UNICODETEXT)) {
            if (const wchar_t *w = (const wchar_t *) GlobalLock(h)) {
                int len = WideCharToMultiByte(CP_UTF8, 0, w, -1, NULL, 0, NULL, NULL);
                if (len > 1) {
                    out.resize(len - 1);
                    WideCharToMultiByte(CP_UTF8, 0, w, -1, &out[0], len, NULL, NULL);
                }
                GlobalUnlock(h);
                ok = true;
            }
        }
        CloseClipboard();
    }
#endif
    return ok ? out : s_cbClipboardFallback;
}


////////////////////////////////////////////////////////////////////////
// EDITOR STATE
// Everything that doesn't need to be an attribute lives here, on the heap,
// as the codableobj struct is already big (and bach asserts classes < 16KB).
////////////////////////////////////////////////////////////////////////

struct t_cbSnapshot {
    std::string text;
    long caret;
    long anchor;
};

enum e_cbEditKind {
    CB_EDIT_OTHER = 0,
    CB_EDIT_TYPING,
    CB_EDIT_DELETING
};

static bool cb_isWordChar(unsigned char c)
{
    return isalnum(c) || c == '_' || c == '$' || c == '@' || c >= 0x80;
}

class t_cbState {
public:
    // text
    std::string text;
    std::vector<long> lineStarts { 0 };
    long caret = 0;
    long anchor = 0;
    double preferredCol = -1;   // for up/down movements
    long tabSize = 4;

    // view
    double scrollX = 0, scrollY = 0;
    double charW = 7., lineH = 14., ascent = 11.;
    t_symbol *metricsFont = nullptr;
    double metricsSize = 0;
    double boxW = 100, boxH = 100;
    bool dragging = false;

    // highlighting
    std::vector<t_cbSpan> spans;
    bool spansDirty = true;

    // undo
    std::vector<t_cbSnapshot> undoStack, redoStack;
    int lastEditKind = CB_EDIT_OTHER;
    bool modified = false;  // text changed since the last compilation

    // ports
    std::vector<void *> proxies;    // proxies[i] is inlet i + 1
    std::vector<long> proxyIds;     // the id each proxy was created with
    long nextProxyId = 1;
    t_atom_long parsedIO[4] = { -1, -1, -1, -1 }; // as found in the code at the last successful compilation

    // triggers
    std::vector<long> triggerInlets { 1 };

    // --- lines ---
    void rebuildLines() {
        lineStarts.assign(1, 0);
        for (long i = 0; i < (long) text.size(); i++)
            if (text[i] == '\n')
                lineStarts.push_back(i + 1);
    }
    long numLines() const { return (long) lineStarts.size(); }
    long lineOf(long pos) const {
        return (long) (std::upper_bound(lineStarts.begin(), lineStarts.end(), pos) - lineStarts.begin()) - 1;
    }
    long lineStart(long line) const { return lineStarts[line]; }
    long lineEnd(long line) const {
        return line + 1 < numLines() ? lineStarts[line + 1] - 1 : (long) text.size();
    }

    // visual column of pos (tabs expanded, one column per UTF-8 code point)
    long colOf(long pos) const {
        long col = 0;
        for (long i = lineStart(lineOf(pos)); i < pos; i++) {
            unsigned char c = text[i];
            if (c == '\t')
                col = (col / tabSize + 1) * tabSize;
            else if ((c & 0xC0) != 0x80)
                col++;
        }
        return col;
    }

    // position on line closest to the visual column col
    long posAtCol(long line, double col) const {
        long i = lineStart(line), e = lineEnd(line);
        long c0 = 0;
        while (i < e) {
            unsigned char c = text[i];
            long c1 = c == '\t' ? (c0 / tabSize + 1) * tabSize : c0 + 1;
            if (col < (c0 + c1) / 2.)
                return i;
            i = nextCharPos(i);
            c0 = c1;
        }
        return e;
    }

    long maxCols() const {
        long m = 0;
        for (long l = 0; l < numLines(); l++)
            m = std::max(m, colOf(lineEnd(l)));
        return m;
    }

    // --- UTF-8 aware movements ---
    long prevCharPos(long pos) const {
        if (pos <= 0) return 0;
        pos--;
        while (pos > 0 && (((unsigned char) text[pos]) & 0xC0) == 0x80)
            pos--;
        return pos;
    }
    long nextCharPos(long pos) const {
        long n = (long) text.size();
        if (pos >= n) return n;
        pos++;
        while (pos < n && (((unsigned char) text[pos]) & 0xC0) == 0x80)
            pos++;
        return pos;
    }
    long prevWordPos(long pos) const {
        while (pos > 0 && !cb_isWordChar(text[pos - 1]))
            pos--;
        while (pos > 0 && cb_isWordChar(text[pos - 1]))
            pos--;
        return pos;
    }
    long nextWordPos(long pos) const {
        long n = (long) text.size();
        while (pos < n && !cb_isWordChar(text[pos]))
            pos++;
        while (pos < n && cb_isWordChar(text[pos]))
            pos++;
        return pos;
    }

    // --- selection ---
    bool hasSelection() const { return caret != anchor; }
    long selStart() const { return std::min(caret, anchor); }
    long selEnd() const { return std::max(caret, anchor); }
    std::string selectedText() const { return text.substr(selStart(), selEnd() - selStart()); }
    void moveCaret(long pos, bool extend) {
        caret = std::max(0L, std::min(pos, (long) text.size()));
        if (!extend)
            anchor = caret;
    }

    // --- editing ---
    void pushUndo(int kind) {
        if (kind == CB_EDIT_OTHER || kind != lastEditKind || undoStack.empty()) {
            undoStack.push_back({ text, caret, anchor });
            if (undoStack.size() > 500)
                undoStack.erase(undoStack.begin());
        }
        lastEditKind = kind;
        redoStack.clear();
    }
    void changed() {
        rebuildLines();
        spansDirty = true;
        modified = true;
        preferredCol = -1;
    }
    void replace(long a, long b, const std::string &s) {
        text.replace(a, b - a, s);
        caret = anchor = a + (long) s.size();
        changed();
    }
    void insert(const std::string &s, int kind) {
        pushUndo(kind);
        replace(selStart(), selEnd(), s);
    }
    void setText(const std::string &s, bool undoable) {
        if (undoable)
            pushUndo(CB_EDIT_OTHER);
        text = s;
        caret = anchor = std::min(caret, (long) text.size());
        changed();
    }
    bool undo() {
        if (undoStack.empty()) return false;
        redoStack.push_back({ text, caret, anchor });
        t_cbSnapshot s = undoStack.back();
        undoStack.pop_back();
        text = s.text; caret = s.caret; anchor = s.anchor;
        lastEditKind = CB_EDIT_OTHER;
        changed();
        return true;
    }
    bool redo() {
        if (redoStack.empty()) return false;
        undoStack.push_back({ text, caret, anchor });
        t_cbSnapshot s = redoStack.back();
        redoStack.pop_back();
        text = s.text; caret = s.caret; anchor = s.anchor;
        lastEditKind = CB_EDIT_OTHER;
        changed();
        return true;
    }

    std::string leadingWhitespace(long line) const {
        long i = lineStart(line), e = lineEnd(line), j = i;
        while (j < e && (text[j] == ' ' || text[j] == '\t'))
            j++;
        return text.substr(i, j - i);
    }

    // indent (dir > 0) or unindent (dir < 0) all the lines touched by the selection
    void indentLines(int dir) {
        pushUndo(CB_EDIT_OTHER);
        long l0 = lineOf(selStart());
        long l1 = lineOf(selEnd());
        if (l1 > l0 && selEnd() == lineStart(l1))
            l1--;
        long newCaret = caret, newAnchor = anchor;
        const std::string unit(tabSize, ' ');
        for (long l = l1; l >= l0; l--) {
            long s = lineStart(l);
            long delta;
            if (dir > 0) {
                text.insert(s, unit);
                delta = tabSize;
            } else {
                long k = 0;
                if (s < (long) text.size() && text[s] == '\t')
                    k = 1;
                else
                    while (k < tabSize && s + k < (long) text.size() && text[s + k] == ' ')
                        k++;
                text.erase(s, k);
                delta = -k;
            }
            if (newCaret > s) newCaret = std::max(s, newCaret + delta);
            if (newAnchor > s) newAnchor = std::max(s, newAnchor + delta);
        }
        caret = newCaret;
        anchor = newAnchor;
        changed();
    }

    // toggle "## " line comments on all the lines touched by the selection
    void toggleComment() {
        pushUndo(CB_EDIT_OTHER);
        long l0 = lineOf(selStart());
        long l1 = lineOf(selEnd());
        if (l1 > l0 && selEnd() == lineStart(l1))
            l1--;
        bool allCommented = true;
        for (long l = l0; l <= l1; l++) {
            long s = lineStart(l) + (long) leadingWhitespace(l).size();
            if (text.compare(s, 2, "##") != 0) { allCommented = false; break; }
        }
        for (long l = l1; l >= l0; l--) {
            long s = lineStart(l) + (long) leadingWhitespace(l).size();
            if (allCommented) {
                long k = text.compare(s, 3, "## ") == 0 ? 3 : 2;
                text.erase(s, k);
            } else {
                text.insert(s, "## ");
            }
        }
        long a = lineStart(l0);
        rebuildLines();
        caret = lineEnd(std::min(l1, numLines() - 1));
        anchor = a;
        changed();
    }
};


////////////////////////////////////////////////////////////////////////
// THE OBJECT
////////////////////////////////////////////////////////////////////////

enum e_cbStatus {
    CB_STATUS_EMPTY = 0,
    CB_STATUS_OK,
    CB_STATUS_ERROR
};

enum e_cbCompileMode {
    CB_COMPILE_USER = 0,    // the user asked for it: run if auto is on
    CB_COMPILE_SILENT       // the code was changed from outside, don't run
};

#define CB_TOOLBAR_H    20.
#define CB_PAD          4.
#define CB_HAMMER_W     22.
#define CB_MAX_DATA_OUTLETS     127
#define CB_MAX_DIRECT_OUTLETS   126

typedef struct _codebox
{
    t_codableobj n_ob;  // must be the first field; its header is used as a t_llllobj_jbox

    t_cbState *n_state;
    long n_in;

    // the current number of ports
    t_atom_long n_dataInlets;
    t_atom_long n_dataOutlets;
    t_atom_long n_directInlets;
    t_atom_long n_directOutlets;

    // the minimum number of ports (attributes)
    t_atom_long n_minDataInlets;
    t_atom_long n_minDataOutlets;
    t_atom_long n_minDirectInlets;
    t_atom_long n_minDirectOutlets;

    t_llll *n_triggers;

    char n_ioReady;
    char n_status;
    char n_hasFocus;
    char n_hammerHover;
    char n_hammerPressed;
    char n_linenumbers;
    t_atom_long n_tabsize;

    t_jrgba n_bgcolor;
    t_jrgba n_textcolor;
    t_jrgba n_bordercolor;
    t_jrgba n_focusbordercolor;
    t_jrgba n_guttercolor;
    t_jrgba n_linenumcolor;
    t_jrgba n_selcolor;
    t_jrgba n_curlinecolor;
    t_jrgba n_caretcolor;
    t_jrgba n_toolbarcolor;
    t_jrgba n_hammercolor;
    t_jrgba n_modifiedcolor;
    t_jrgba n_okcolor;
    t_jrgba n_errorcolor;
    t_jrgba n_syntaxcolor[CB_NUM_SCOPES];
} t_codebox;


t_class *codebox_class;

void *codebox_new(t_symbol *s, long argc, t_atom *argv);
void codebox_free(t_codebox *x);

void codebox_assist(t_codebox *x, void *b, long m, long a, char *s);
void codebox_inletinfo(t_codebox *x, void *b, long a, char *t);
long codebox_ishot(t_codebox *x, long inlet);
long codebox_getinlet(t_codebox *x);

void codebox_bang(t_codebox *x);
void codebox_int(t_codebox *x, t_atom_long v);
void codebox_float(t_codebox *x, double v);
void codebox_anything(t_codebox *x, t_symbol *msg, long ac, t_atom *av);
void codebox_run(t_codebox *x, long inlet);
void codebox_triggerfromclient(t_codebox *x, long dummy);
void codebox_deferbang(t_codebox *x, t_symbol *msg, long ac, t_atom *av);

void codebox_expr(t_codebox *x, t_symbol *msg, long ac, t_atom *av);
void codebox_compilemsg(t_codebox *x);
void codebox_compile(t_codebox *x, long mode);
void codebox_bellcodechanged(t_codebox *x);
void codebox_dblclick(t_codebox *x);

void codebox_update_io(t_codebox *x);
void codebox_resize_io(t_codebox *x, long di, long dout, long dri, long dro);

void codebox_jsave(t_codebox *x, t_dictionary *d);
t_max_err codebox_notify(t_codebox *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

void codebox_paint(t_codebox *x, t_object *view);
void codebox_mousedown(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers);
void codebox_mousedrag(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers);
void codebox_mouseup(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers);
void codebox_mousemove(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers);
void codebox_mouseleave(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers);
void codebox_mousedoubleclick(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers);
void codebox_mousewheel(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers, double x_inc, double y_inc);
long codebox_key(t_codebox *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);
void codebox_focusgained(t_codebox *x, t_object *patcherview);
void codebox_focuslost(t_codebox *x, t_object *patcherview);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_codebox, n_triggers, codebox_getattr_triggers);
t_max_err codebox_setattr_triggers(t_codebox *x, t_object *attr, long ac, t_atom *av);
t_max_err codebox_setattr_tabsize(t_codebox *x, t_object *attr, long ac, t_atom *av);

void codebox_ownedFunctionsSetup(t_codebox *x);


////////////////////////////////////////////////////////////////////////
// OWNED FUNCTIONS
// Same as t_fnDirectout / t_fnDirectin, but for a UI object
////////////////////////////////////////////////////////////////////////

class t_fnCodeboxDirectout : public t_ownedFunction
{
public:
    t_fnCodeboxDirectout(t_codebox *owner) : t_ownedFunction("directout", true, (t_object *) owner) {
        setArgument("outlets");
    }

    t_llll* call(t_execEnv const &context) {
        long argc = context.argc;
        t_llll **argv = context.argv;
        t_codebox *x = (t_codebox *) owner;
        long dataOutlets = x->n_dataOutlets;
        long directOutlets = x->n_directOutlets;
        long totOutlets = dataOutlets + directOutlets; // which doesn't actually include the result outlet
        t_llllelem *outletsElem;
        long arg;
        for (arg = 1, outletsElem = argv[1]->l_head;
             arg < argc && outletsElem;
             arg++, outletsElem = outletsElem->l_next) {
            long outNum = hatom_getlong(&outletsElem->l_hatom);
            if (outNum <= 0)
                outNum = totOutlets + outNum;
            else
                outNum += dataOutlets;
            if (outNum >= totOutlets)
                outNum = totOutlets;
            llllobj_outlet_llll((t_object *) owner, LLLL_OBJ_UI, outNum, argv[arg + 1]);
        }
        return llll_clone(argv[argc]);
    }
};

class t_fnCodeboxDirectin : public t_ownedFunction
{
public:
    t_fnCodeboxDirectin(t_codebox *owner) : t_ownedFunction("directin", false, (t_object *) owner) {
        setArgument("inlet");
    }

    t_llll* call(t_execEnv const &context) {
        t_llll **argv = context.argv;
        t_codebox *x = (t_codebox *) owner;
        t_llllelem *inletElem = argv[1]->l_head;
        long dataInlets = x->n_dataInlets;
        long directInlets = x->n_directInlets;
        long totInlets = dataInlets + directInlets;
        long inNum = inletElem ? hatom_getlong(&inletElem->l_hatom) : 1;
        if (inNum < 0)
            inNum = totInlets + inNum;
        else
            inNum += dataInlets - 1;
        if (inNum >= totInlets)
            inNum = totInlets - 1;
        if (inNum < 1) {
            object_error((t_object *) owner, "Bad inlet number for function directin");
            return llll_get();
        }
        return llllobj_get_store_contents((t_object *) owner, LLLL_OBJ_UI, inNum, 1);
    }
};

void codebox_ownedFunctionsSetup(t_codebox *x)
{
    (*x->n_ob.c_ofTable)["directout"] = new t_fnCodeboxDirectout(x);
    (*x->n_ob.c_ofTable)["directin"] = new t_fnCodeboxDirectin(x);
    (*x->n_ob.c_ofTable)["print"] = new t_fnPrint((t_object *) x);
}


////////////////////////////////////////////////////////////////////////
// CLASS
////////////////////////////////////////////////////////////////////////

#define CB_SYNTAX_COLOR_ATTR(SCOPE, NAME, LABEL, DEFAULT) \
    CLASS_ATTR_RGBA(c, NAME, 0, t_codebox, n_syntaxcolor[SCOPE]); \
    CLASS_ATTR_STYLE_LABEL(c, NAME, 0, "rgba", LABEL); \
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, NAME, 0, DEFAULT);

#define CB_COLOR_ATTR(NAME, FIELD, LABEL, DEFAULT) \
    CLASS_ATTR_RGBA(c, NAME, 0, t_codebox, FIELD); \
    CLASS_ATTR_STYLE_LABEL(c, NAME, 0, "rgba", LABEL); \
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, NAME, 0, DEFAULT);

#define CB_MIN_IO_SETTER(FNAME, FIELD) \
t_max_err FNAME(t_codebox *x, t_object *attr, long ac, t_atom *av) \
{ \
    if (ac && av) { \
        x->FIELD = MAX(0, atom_getlong(av)); \
        if (x->n_ioReady) \
            codebox_update_io(x); \
    } \
    return MAX_ERR_NONE; \
}

CB_MIN_IO_SETTER(codebox_setattr_inlets, n_minDataInlets)
CB_MIN_IO_SETTER(codebox_setattr_extraoutlets, n_minDataOutlets)
CB_MIN_IO_SETTER(codebox_setattr_directins, n_minDirectInlets)
CB_MIN_IO_SETTER(codebox_setattr_directouts, n_minDirectOutlets)


void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;

    common_symbols_init();
    llllobj_common_symbols_init();

    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }

    cb_buildRules();

    CLASS_NEW_CHECK_SIZE(c, "bach.codebox", (method)codebox_new, (method)codebox_free, (long) sizeof(t_codebox), 0L, A_GIMME, 0);

    c->c_flags |= CLASS_FLAG_NEWDICTIONARY;
    jbox_initclass(c, JBOX_FONTATTR);

    codableclass_add_standard_methods_and_attrs(c);

    // UI
    class_addmethod(c, (method)codebox_paint,            "paint",            A_CANT, 0);
    class_addmethod(c, (method)codebox_mousedown,        "mousedown",        A_CANT, 0);
    class_addmethod(c, (method)codebox_mousedrag,        "mousedrag",        A_CANT, 0);
    class_addmethod(c, (method)codebox_mouseup,          "mouseup",          A_CANT, 0);
    class_addmethod(c, (method)codebox_mousemove,        "mousemove",        A_CANT, 0);
    class_addmethod(c, (method)codebox_mouseleave,       "mouseleave",       A_CANT, 0);
    class_addmethod(c, (method)codebox_mousedoubleclick, "mousedoubleclick", A_CANT, 0);
    class_addmethod(c, (method)codebox_mousewheel,       "mousewheel",       A_CANT, 0);
    class_addmethod(c, (method)codebox_key,              "key",              A_CANT, 0);
    class_addmethod(c, (method)codebox_focusgained,      "focusgained",      A_CANT, 0);
    class_addmethod(c, (method)codebox_focuslost,        "focuslost",        A_CANT, 0);
    class_addmethod(c, (method)codebox_notify,           "notify",           A_CANT, 0);

    // saving: the code saved is the one in the editor, even if it has not been compiled
    class_addmethod(c, (method)codebox_jsave,            "jsave",            A_CANT, 0);
    class_addmethod(c, (method)codebox_jsave,            "appendtodictionary", A_CANT, 0); // overrides the codableobj one

    // @method llll @digest Store values for the inlet variables
    // @description
    // The lllls provide the data to the code.
    // An llll received in a hot inlet will trigger the evaluation and cause the result to be output.
    class_addmethod(c, (method)codebox_anything,    "anything",     A_GIMME,    0);
    class_addmethod(c, (method)codebox_anything,    "list",         A_GIMME,    0);
    class_addmethod(c, (method)codebox_int,         "int",          A_LONG,     0);
    class_addmethod(c, (method)codebox_float,       "float",        A_FLOAT,    0);

    // @method bang @digest Perform the last operation
    // @description Run the compiled code on the most recently received lllls.
    class_addmethod(c, (method)codebox_bang,        "bang",         0);

    // @method expr @digest Set and compile new code
    // @description The <m>expr</m> message, followed by bell code,
    // replaces the code in the editor and compiles it.
    class_addmethod(c, (method)codebox_expr,        "expr",         A_GIMME,    0);

    // @method compile @digest Compile the code in the editor
    // @description Compiles the code currently in the editor,
    // exactly as clicking on the hammer button.
    // If the code is valid, the number of inlets and outlets is updated accordingly.
    class_addmethod(c, (method)codebox_compilemsg,  "compile",      0);

    // @method (doubleclick) @digest Open external text editor
    // @description In an unlocked patcher, double-clicking on the object opens the code in an external text editor.
    class_addmethod(c, (method)codebox_dblclick,    "dblclick",     A_CANT, 0);

    class_addmethod(c, (method)codebox_assist,      "assist",       A_CANT, 0);
    class_addmethod(c, (method)codebox_inletinfo,   "inletinfo",    A_CANT, 0);
    class_addmethod(c, (method)codebox_triggerfromclient, "triggerfromclient", A_CANT, 0);
    class_addmethod(c, (method)codebox_bellcodechanged, "bellcodechanged", A_CANT, 0);


    CLASS_STICKY_ATTR(c, "category", 0, "Behavior");

    CLASS_ATTR_ATOM_LONG(c, "inlets", 0, t_codebox, n_minDataInlets);
    CLASS_ATTR_LABEL(c, "inlets", 0, "Minimum Number of Data Inlets");
    CLASS_ATTR_ACCESSORS(c, "inlets", NULL, codebox_setattr_inlets);
    CLASS_ATTR_SAVE(c, "inlets", 0);
    // @description Minimum number of data inlets.
    // The actual number of data inlets is the maximum between this and the one required by the code.

    CLASS_ATTR_ATOM_LONG(c, "extraoutlets", 0, t_codebox, n_minDataOutlets);
    CLASS_ATTR_LABEL(c, "extraoutlets", 0, "Minimum Number of Extra Outlets");
    CLASS_ATTR_ACCESSORS(c, "extraoutlets", NULL, codebox_setattr_extraoutlets);
    CLASS_ATTR_SAVE(c, "extraoutlets", 0);
    // @description Minimum number of data outlets.
    // The actual number of data outlets is the maximum between this and the one required by the code.

    CLASS_ATTR_ATOM_LONG(c, "directins", 0, t_codebox, n_minDirectInlets);
    CLASS_ATTR_LABEL(c, "directins", 0, "Minimum Number of Direct Inlets");
    CLASS_ATTR_ACCESSORS(c, "directins", NULL, codebox_setattr_directins);
    CLASS_ATTR_SAVE(c, "directins", 0);
    // @description Minimum number of direct inlets.

    CLASS_ATTR_ATOM_LONG(c, "directouts", 0, t_codebox, n_minDirectOutlets);
    CLASS_ATTR_LABEL(c, "directouts", 0, "Minimum Number of Direct Outlets");
    CLASS_ATTR_ACCESSORS(c, "directouts", NULL, codebox_setattr_directouts);
    CLASS_ATTR_SAVE(c, "directouts", 0);
    // @description Minimum number of direct outlets.

    CLASS_ATTR_ATOM_LONG(c, "embed", 0, t_codableobj, c_embed);
    CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
    CLASS_ATTR_LABEL(c, "embed", 0, "Save Code With Patcher");
    CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
    CLASS_ATTR_SAVE(c, "embed", 0);
    // @description When set to 1, the code in the editor is saved with the patcher.

    CLASS_ATTR_ATOM_LONG(c, "auto", 0, t_codableobj, c_auto);
    CLASS_ATTR_LABEL(c, "auto", 0, "Automatically Run Code");
    CLASS_ATTR_STYLE(c, "auto", 0, "onoff");
    CLASS_ATTR_SAVE(c, "auto", 0);
    // @description When set to 1, the code is run at startup and every time it is successfully compiled.

    CLASS_ATTR_LLLL(c, "triggers", 0, t_codebox, n_triggers, codebox_getattr_triggers, codebox_setattr_triggers);
    CLASS_ATTR_LABEL(c, "triggers", 0, "Triggers");
    CLASS_ATTR_SAVE(c, "triggers", 0);
    // @description Same as <o>bach.eval</o>'s <m>triggers</m> attribute.

    CLASS_ATTR_LLLL(c, "params", 0, t_codableobj, c_paramsll, codableobj_params_get, codableobj_params_set);
    CLASS_ATTR_LABEL(c, "params", 0, "Extra Parameters");
    // @description Same as <o>bach.eval</o>'s <m>params</m> attribute.

    CLASS_STICKY_ATTR_CLEAR(c, "category");


    CLASS_STICKY_ATTR(c, "category", 0, "Appearance");

    CLASS_ATTR_CHAR(c, "linenumbers", 0, t_codebox, n_linenumbers);
    CLASS_ATTR_STYLE_LABEL(c, "linenumbers", 0, "onoff", "Show Line Numbers");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "linenumbers", 0, "1");
    // @description Toggles the display of line numbers.

    CLASS_ATTR_ATOM_LONG(c, "tabsize", 0, t_codebox, n_tabsize);
    CLASS_ATTR_LABEL(c, "tabsize", 0, "Tab Size");
    CLASS_ATTR_ACCESSORS(c, "tabsize", NULL, codebox_setattr_tabsize);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "tabsize", 0, "4");
    // @description Number of spaces inserted by the Tab key, and width of tab characters.

    CLASS_STICKY_ATTR_CLEAR(c, "category");


    CLASS_STICKY_ATTR(c, "category", 0, "Color");

    CB_COLOR_ATTR("bgcolor",            n_bgcolor,          "Background Color",             "1. 1. 1. 1.");
    CLASS_ATTR_BASIC(c, "bgcolor", 0);
    CB_COLOR_ATTR("textcolor",          n_textcolor,        "Text Color",                   "0.12 0.12 0.12 1.");
    CLASS_ATTR_BASIC(c, "textcolor", 0);
    CB_COLOR_ATTR("bordercolor",        n_bordercolor,      "Border Color",                 "0.6 0.6 0.6 1.");
    CB_COLOR_ATTR("focusbordercolor",   n_focusbordercolor, "Border Color When Editing",    "0.25 0.5 0.85 1.");
    CB_COLOR_ATTR("guttercolor",        n_guttercolor,      "Line Numbers Background Color","0.95 0.95 0.95 1.");
    CB_COLOR_ATTR("linenumcolor",       n_linenumcolor,     "Line Numbers Color",           "0.6 0.6 0.6 1.");
    CB_COLOR_ATTR("selectioncolor",     n_selcolor,         "Selection Color",              "0.71 0.84 1. 1.");
    CB_COLOR_ATTR("currentlinecolor",   n_curlinecolor,     "Current Line Color",           "0.96 0.97 1. 1.");
    CB_COLOR_ATTR("caretcolor",         n_caretcolor,       "Caret Color",                  "0. 0. 0. 1.");
    CB_COLOR_ATTR("toolbarcolor",       n_toolbarcolor,     "Toolbar Color",                "0.91 0.91 0.91 1.");
    CB_COLOR_ATTR("hammercolor",        n_hammercolor,      "Compile Button Color",         "0.35 0.35 0.35 1.");
    CB_COLOR_ATTR("modifiedcolor",      n_modifiedcolor,    "Modified Code Color",          "0.93 0.55 0.1 1.");
    CB_COLOR_ATTR("okcolor",            n_okcolor,          "Compiled Code Color",          "0.25 0.65 0.3 1.");
    CB_COLOR_ATTR("errorcolor",         n_errorcolor,       "Syntax Error Color",           "0.85 0.2 0.2 1.");

    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_COMMENT,           "commentcolor",     "Comments Color",               "0.42 0.53 0.42 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_CONTROL,           "keywordcolor",     "Control Keywords Color",       "0.67 0.05 0.57 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_STORAGE,           "storagecolor",     "Storage Modifiers Color",      "0.55 0.15 0.65 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_OPERATOR,          "operatorcolor",    "Operators Color",              "0.45 0.32 0.1 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_KEYWORD_OTHER,     "otherkeywordcolor","Other Keywords Color",         "0.6 0.3 0.05 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_NUMBER,            "numbercolor",      "Numbers Color",                "0.11 0.0 0.81 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_CONSTANT_OTHER,    "pitchcolor",       "Pitches With Tones Color",     "0.0 0.42 0.62 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_CONSTANT_LANGUAGE, "constantcolor",    "Language Constants Color",     "0.67 0.05 0.57 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_STRING,            "stringcolor",      "Strings Color",                "0.77 0.1 0.09 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_MAXMESSAGE,        "maxmessagecolor",  "Max Messages Color",           "0.24 0.43 0.45 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_FUNCTION,          "functioncolor",    "Functions Color",              "0.24 0.43 0.45 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_VARIABLE,          "variablecolor",    "Variables Color",              "0.15 0.25 0.45 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_PSEUDOVARIABLE,    "pseudovarcolor",   "Pseudovariables Color",        "0.0 0.5 0.3 1.");
    CB_SYNTAX_COLOR_ATTR(CB_SCOPE_PARAMETER,         "parametercolor",   "Named Parameters Color",       "0.45 0.3 0.6 1.");

    CLASS_STICKY_ATTR_CLEAR(c, "category");

#ifdef MAC_VERSION
    CLASS_ATTR_DEFAULT(c, "fontname", 0, "Menlo");
#else
    CLASS_ATTR_DEFAULT(c, "fontname", 0, "Consolas");
#endif
    CLASS_ATTR_DEFAULT(c, "fontsize", 0, "11");
    CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0. 0. 300. 160.");

    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_UI);

    class_register(CLASS_BOX, c);
    codebox_class = c;

    dev_post("bach.codebox compiled %s %s", __DATE__, __TIME__);
}


////////////////////////////////////////////////////////////////////////
// TRIGGERS (as in bach.eval)
////////////////////////////////////////////////////////////////////////

t_max_err codebox_check_triggers_llll(t_codebox *x, t_llll *ll)
{
    if (ll->l_depth > 2)
        goto codebox_check_triggers_llll_error;
    for (t_llllelem *elem = ll->l_head; elem; elem = elem->l_next) {
        if (!hatom_is_number(&elem->l_hatom)) {
            if (t_llll *sub_ll = hatom_getllll(&elem->l_hatom); sub_ll) {
                if (sub_ll->l_size > 2)
                    goto codebox_check_triggers_llll_error;
                if (t_symbol *s = hatom_getsym(&sub_ll->l_head->l_hatom);
                    !s || *(s->s_name) == '$') {
                    object_error((t_object *) x, "Bad trigger variable");
                    goto codebox_check_triggers_llll_error;
                }
                if (sub_ll->l_size == 2 && !hatom_is_number(&sub_ll->l_tail->l_hatom))
                    goto codebox_check_triggers_llll_error;
            } else if (elem->l_hatom.h_type != H_SYM) {
                goto codebox_check_triggers_llll_error;
            }
        }
    }
    return MAX_ERR_NONE;

codebox_check_triggers_llll_error:
    object_error((t_object *) x, "Bad triggers llll");
    return MAX_ERR_GENERIC;
}

void codebox_parse_all_triggers(t_codebox *x)
{
    t_codableobj *cx = &x->n_ob;
    codableobj_removeAllVarTriggers(cx);
    x->n_state->triggerInlets.clear();

    for (t_llllelem *elem = x->n_triggers->l_head; elem; elem = elem->l_next) {
        t_hatom *h = &elem->l_hatom;
        if (hatom_is_number(h)) {
            x->n_state->triggerInlets.push_back(hatom_getlong(h));
        } else {
            t_symbol *varname;
            long priority = 0;
            if (t_llll *subll = hatom_getllll(h); subll) {
                varname = hatom_getsym(&subll->l_head->l_hatom);
                if (subll->l_size == 2)
                    priority = hatom_getlong(&subll->l_tail->l_hatom);
            } else
                varname = hatom_getsym(h);
            if (varname == gensym("*") && !cx->c_main) {
                // codableobj_register_trigger_variable() would need a main function:
                // just set the flags, the clients will be added when the code is compiled
                cx->c_allGVTrigger = cx->c_allPVTrigger = true;
                cx->c_allGVPriority = cx->c_allPVPriority = priority;
            } else
                codableobj_register_trigger_variable(cx, varname, priority);
        }
    }
}

t_max_err codebox_setattr_triggers(t_codebox *x, t_object *attr, long ac, t_atom *av)
{
    if (ac == 0 || av) {
        if (t_llll *ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_UI, ac, av); ll) {
            if (codebox_check_triggers_llll(x, ll) != MAX_ERR_NONE) {
                llll_free(ll);
                return MAX_ERR_NONE;
            }
            bach_atomic_lock(&x->n_ob.c_triggers_lock);
            t_llll *free_me = x->n_triggers;
            x->n_triggers = ll;
            if (x->n_ioReady) // during the instantiation, this is done once the code is built
                codebox_parse_all_triggers(x);
            bach_atomic_unlock(&x->n_ob.c_triggers_lock);
            llll_free(free_me);
            if (x->n_ob.c_ready)
                codableobj_resolve_trigger_vars((t_codableobj *) x, NULL, 0, NULL);
        }
    }
    return MAX_ERR_NONE;
}

long codebox_ishot(t_codebox *x, long inlet)
{
    long hot = 0;
    bach_atomic_lock(&x->n_ob.c_triggers_lock);
    long numinlets = x->n_dataInlets;
    for (long this_trigger : x->n_state->triggerInlets) {
        if ((this_trigger == 0 && inlet < numinlets) ||
            this_trigger == inlet + 1 ||
            (this_trigger < 0 && this_trigger == inlet - numinlets))
            hot = 1;
    }
    bach_atomic_unlock(&x->n_ob.c_triggers_lock);
    return hot;
}


////////////////////////////////////////////////////////////////////////
// RUNNING THE CODE (as in bach.eval)
////////////////////////////////////////////////////////////////////////

// the position of the inlet a message arrived from.
// Proxies created after the instantiation don't have their position as their id,
// so we look the id up.
long codebox_getinlet(t_codebox *x)
{
    long id = proxy_getinlet((t_object *) x);
    if (id == 0)
        return 0;
    const std::vector<long> &ids = x->n_state->proxyIds;
    for (size_t i = 0; i < ids.size(); i++)
        if (ids[i] == id)
            return (long) i + 1;
    return 0;
}

void codebox_bang_deferred(t_codebox *x, t_symbol *s, long ac, t_atom *av)
{
    if (x->n_ob.c_ready)
        codebox_run(x, atom_getlong(av));
    else
        defer_low(x, (method) codebox_bang_deferred, _sym_int, 1, av);
}

void codebox_bang(t_codebox *x)
{
    long inlet = codebox_getinlet(x) + 1;
    if (x->n_ob.c_ready)
        codebox_run(x, inlet);
    else {
        t_atom a;
        atom_setlong(&a, inlet);
        defer_low(x, (method) codebox_bang_deferred, _sym_int, 1, &a);
    }
}

void codebox_deferbang(t_codebox *x, t_symbol *msg, long ac, t_atom *av)
{
    codebox_bang(x);
}

void codebox_triggerfromclient(t_codebox *x, long dummy)
{
    codebox_run(x, 0);
}

void codebox_run(t_codebox *x, long inlet)
{
    t_mainFunction *main = x->n_ob.c_main;
    if (!main)
        return;
    main->increase(); // the code might be recompiled while running
    main->setInlet(inlet);
    t_execEnv context((t_llllobj_object *) x, main);
    long dataInlets = x->n_dataInlets;

    for (int i = 0; i < dataInlets; i++)
        context.argv[i + 1] = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_UI, i);
    context.argc = dataInlets;

    long outlets = x->n_dataOutlets;
    main->setOutlets(outlets);
    main->clearOutletData();
    t_llll *result = codableobj_run((t_codableobj *) x, context);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, outlets, result);
    llll_free(result);
    for (long i = outlets - 1; i >= 0; i--) {
        if (t_llll *outll = main->getOutletData(i); outll)
            llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, i, outll);
    }

    for (int i = 1; i <= dataInlets; i++)
        llll_release(context.argv[i]);
    main->decrease();
}

void codebox_int(t_codebox *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    codebox_anything(x, _sym_int, 1, &outatom);
}

void codebox_float(t_codebox *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    codebox_anything(x, _sym_float, 1, &outatom);
}

void codebox_anything(t_codebox *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = codebox_getinlet(x);
    llllobj_parse_and_store((t_object *) x, LLLL_OBJ_UI, msg, ac, av, inlet);
    if (codebox_ishot(x, inlet))
        codebox_bang(x);
}

void codebox_inletinfo(t_codebox *x, void *b, long a, char *t)
{
    *t = !codebox_ishot(x, a);
}

void codebox_assist(t_codebox *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a < x->n_dataInlets)
            snprintf(s, 512, "llll: Data Inlet %ld", a + 1); // @in 0 @loop 1 @type llll @digest llll to be assigned to inlet pseudovariables
        else
            snprintf(s, 512, "llll: Direct Inlet %ld", (long) (a - x->n_dataInlets + 1)); // @in 1 @type llll @digest llll to be assigned to direct inlet pseudovariables
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
        if (a < x->n_dataOutlets)
            snprintf(s, 512, "llll (%s): Data Outlet %ld", type, a + 1); // @out 0 @loop 1 @type llll @digest Values assigned to outlet pseudovariables
        else if (a == x->n_dataOutlets)
            snprintf(s, 512, "llll (%s): Evaluation Result", type); // @out 1 @type llll @digest Final result of the evaluation
        else
            snprintf(s, 512, "llll (%s): Direct Outlet %ld", type, (long) (a - x->n_dataOutlets)); // @out 2 @loop 1 @type llll @digest Values assigned to direct outlet pseudovariables
    }
}


////////////////////////////////////////////////////////////////////////
// DYNAMIC INLETS AND OUTLETS
////////////////////////////////////////////////////////////////////////

static void cb_init_llll_out(t_llllobj_out *o, char type)
{
    t_llll *empty = llll_get();
    switch (type) {
        case 't': case 'T':
            o->b_msg = _llllobj_sym_null;
            o->b_ll = empty;
            o->b_type = LLLL_O_TEXT;
            break;
        case 'm': case 'M':
            o->b_msg = _llllobj_sym_null;
            o->b_ll = empty;
            o->b_type = LLLL_O_MAX;
            break;
        default:
            o->b_msg = LLLL_NATIVE_MSG;
            o->b_ac = 1;
            o->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
            o->b_ll = empty;
            atom_setlong(o->b_av, llll_phonenumber(empty));
            o->b_type = LLLL_O_NATIVE;
            break;
    }
}

static void cb_free_llll_out(t_llllobj_out *o)
{
    if (o->b_ll)
        llll_release(o->b_ll);
    if (o->b_type == LLLL_O_NATIVE && o->b_av)
        bach_freeptr(o->b_av);
    else if (o->b_type == LLLL_O_TEXT)
        object_free_debug(o->b_aa);
}

// Changes the number of ports, keeping the surviving ones (and their patch cords) in place:
// - data outlets are inserted/removed just before the result outlet,
// - direct outlets are appended/removed at the right,
// - data inlets are inserted/removed just before the first direct inlet,
// - direct inlets are appended/removed at the right.
void codebox_resize_io(t_codebox *x, long di, long dout, long dri, long dro)
{
    t_llllobj_jbox *b = &x->n_ob.c_box;
    t_cbState *st = x->n_state;
    const long odi = x->n_dataInlets, odo = x->n_dataOutlets, odri = x->n_directInlets, odro = x->n_directOutlets;

    if (di == odi && dout == odo && dri == odri && dro == odro)
        return;

    // ---------- outlets ----------
    if (dout != odo || dro != odro) {
        const long newN = dout + 1 + dro;
        t_llllobj_out *oldOut = b->l_out;
        t_llllobj_out *newOut = (t_llllobj_out *) bach_newptrclear(newN * sizeof(t_llllobj_out));
        const char *oldTypes = b->l_outtypes ? b->l_outtypes->s_name : "";
        const long oldTypesLen = (long) strlen(oldTypes);
        std::string newTypes(newN, odo < oldTypesLen ? oldTypes[odo] : 'n');

        // remove the outlets that disappear
        for (long i = dout; i < odo; i++) {
            outlet_delete(oldOut[i].b_outlet);
            cb_free_llll_out(&oldOut[i]);
        }
        for (long j = dro; j < odro; j++) {
            long i = odo + 1 + j;
            outlet_delete(oldOut[i].b_outlet);
            cb_free_llll_out(&oldOut[i]);
        }

        // move the surviving ones to their new positions
        for (long k = 0; k < newN; k++) {
            long o;
            if (k < dout)
                o = k < odo ? k : -1;
            else if (k == dout)
                o = odo;
            else
                o = k - dout - 1 < odro ? odo + 1 + (k - dout - 1) : -1;
            if (o >= 0) {
                newOut[k] = oldOut[o];
                if (o < oldTypesLen)
                    newTypes[k] = oldTypes[o];
            }
        }

        // new data outlets, from left to right, each one after the previous
        for (long k = odo; k < dout; k++) {
            if (k == 0)
                newOut[k].b_outlet = outlet_new(x, NULL); // outlet_new() adds the outlet at the left
            else
                newOut[k].b_outlet = outlet_insert_after((t_object *) x, NULL, NULL, newOut[k - 1].b_outlet);
            cb_init_llll_out(&newOut[k], newTypes[k]);
        }

        // new direct outlets, at the right
        for (long j = odro; j < dro; j++) {
            long k = dout + 1 + j;
            newOut[k].b_outlet = outlet_append((t_object *) x, NULL, NULL);
            cb_init_llll_out(&newOut[k], newTypes[k]);
        }

        bach_freeptr(oldOut);
        b->l_out = newOut;
        b->l_numouts = (t_uint32) newN;
        b->l_numllllouts = (t_uint32) newN;
        b->l_outtypes = gensym(newTypes.c_str());
    }

    // ---------- inlets ----------
    if (di != odi || dri != odri) {
        const long newN = di + dri;
        t_llllobj_store *oldS = b->l_incache;
        t_llllobj_store *newS = (t_llllobj_store *) bach_newptrclear(newN * sizeof(t_llllobj_store));
        std::vector<void *> newP(newN - 1, nullptr);
        std::vector<long> newIds(newN - 1, 0);

        // remove the inlets that disappear (inlet 0 is never removed, as di >= 1)
        for (long i = di; i < odi; i++) {
            proxy_delete(st->proxies[i - 1]);
            llll_release(oldS[i].s_ll);
        }
        for (long j = dri; j < odri; j++) {
            long i = odi + j;
            proxy_delete(st->proxies[i - 1]);
            llll_release(oldS[i].s_ll);
        }

        // move the surviving ones
        for (long k = 0; k < newN; k++) {
            long o;
            if (k < di)
                o = k < odi ? k : -1;
            else
                o = k - di < odri ? odi + (k - di) : -1;
            if (o >= 0) {
                newS[k] = oldS[o];
                if (k >= 1) {
                    newP[k - 1] = st->proxies[o - 1];
                    newIds[k - 1] = st->proxyIds[o - 1];
                }
            }
        }

        // new data inlets, from left to right, each one after the previous
        for (long k = odi; k < di; k++) {
            long id = st->nextProxyId++;
            void *p;
            if (k == 1)
                p = proxy_new(x, id, &x->n_in); // proxy_new() adds the inlet just after the leftmost one
            else
                p = proxy_insert((t_object *) x, id, &x->n_in, newP[k - 2]);
            newP[k - 1] = p;
            newIds[k - 1] = id;
            newS[k].s_ll = llll_get();
        }

        // new direct inlets, at the right
        for (long j = odri; j < dri; j++) {
            long k = di + j;
            long id = st->nextProxyId++;
            newP[k - 1] = proxy_append((t_object *) x, id, &x->n_in);
            newIds[k - 1] = id;
            newS[k].s_ll = llll_get();
        }

        bach_freeptr(oldS);
        b->l_incache = newS;
        b->l_numstores = (t_uint32) newN;
        st->proxies = newP;
        st->proxyIds = newIds;
    }

    x->n_dataInlets = di;
    x->n_dataOutlets = dout;
    x->n_directInlets = dri;
    x->n_directOutlets = dro;

    jbox_redraw((t_jbox *) x);
}

static void cb_compute_io(t_codebox *x, const t_atom_long *parsed, const t_atom_long *saved,
                          long *di, long *dout, long *dri, long *dro)
{
    t_atom_long p[4] = { -1, -1, -1, -1 }, s[4] = { 0, 0, 0, 0 };
    if (parsed) std::copy(parsed, parsed + 4, p);
    if (saved) std::copy(saved, saved + 4, s);
    *di = std::max<long>({ (long) p[0], (long) x->n_minDataInlets, (long) s[0], 1L });
    *dout = std::max<long>({ (long) p[1], (long) x->n_minDataOutlets, (long) s[1], 0L });
    *dri = std::max<long>({ (long) p[2], (long) x->n_minDirectInlets, (long) s[2], 0L });
    *dro = std::max<long>({ (long) p[3], (long) x->n_minDirectOutlets, (long) s[3], 0L });
    *dout = std::min<long>(*dout, CB_MAX_DATA_OUTLETS);
    *dro = std::min<long>(*dro, CB_MAX_DIRECT_OUTLETS);
    *di = std::min<long>(*di, LLLL_MAX_INLETS - 1);
    *dri = std::min<long>(*dri, LLLL_MAX_INLETS - 1 - *di);
}

void codebox_update_io(t_codebox *x)
{
    long di, dout, dri, dro;
    cb_compute_io(x, x->n_state->parsedIO, nullptr, &di, &dout, &dri, &dro);
    codebox_resize_io(x, di, dout, dri, dro);
}


////////////////////////////////////////////////////////////////////////
// COMPILATION
////////////////////////////////////////////////////////////////////////

static bool cb_is_blank(const std::string &s)
{
    return std::all_of(s.begin(), s.end(), [](unsigned char c) { return isspace(c); });
}

void codebox_compile(t_codebox *x, long mode)
{
    t_codableobj *cx = &x->n_ob;
    t_cbState *st = x->n_state;
    const std::string &t = st->text;

    // the parsers like a trailing space
    char *newCode = sysmem_newptr((t_ptr_size) t.size() + 2);
    memcpy(newCode, t.data(), t.size());
    newCode[t.size()] = ' ';
    newCode[t.size() + 1] = 0;

    bach_atomic_lock(&cx->c_lock);
    char *oldCode = cx->c_text;
    cx->c_text = newCode;
    bach_atomic_unlock(&cx->c_lock);
    if (oldCode)
        sysmem_freeptr(oldCode);

    t_atom_long io[4] = { -1, -1, -1, -1 };
    t_max_err err = MAX_ERR_NONE;

    if (cb_is_blank(t)) {
        if (cx->c_main)
            cx->c_main->decrease();
        cx->c_main = nullptr;
        x->n_status = CB_STATUS_EMPTY;
    } else {
        long codeac = -1;
        // on success, the previous main function is released by codableobj_buildAst;
        // on failure, it is kept
        err = codableobj_buildAst(cx, &codeac, io, io + 1, io + 2, io + 3);
        x->n_status = err == MAX_ERR_NONE ? CB_STATUS_OK : CB_STATUS_ERROR;
    }
    st->modified = false;

    if (err == MAX_ERR_NONE) {
        std::copy(io, io + 4, st->parsedIO);
        codebox_update_io(x);
        if (cx->c_main) {
            cx->c_main->setOutlets(x->n_dataOutlets);
            codableobj_resolvepatchervars(cx, NULL, 0, NULL);
            codableobj_resolve_trigger_vars(cx, NULL, 0, NULL);
            if (cx->c_watch)
                codableobj_start_all_filewatchers(cx);
        }
        if (mode == CB_COMPILE_USER && cx->c_auto && cx->c_main)
            codebox_bang(x);
    } else {
        object_error((t_object *) x, "Invalid code: keeping the previously compiled version");
    }

    jbox_redraw((t_jbox *) x);
}

void codebox_compile_deferred(t_codebox *x, t_symbol *s, long ac, t_atom *av)
{
    codebox_compile(x, CB_COMPILE_USER);
}

void codebox_compilemsg(t_codebox *x)
{
    defer(x, (method) codebox_compile_deferred, NULL, 0, NULL);
}

static std::string cb_normalize_newlines(const std::string &s)
{
    std::string out;
    out.reserve(s.size());
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '\r') {
            out += '\n';
            if (i + 1 < s.size() && s[i + 1] == '\n')
                i++;
        } else
            out += s[i];
    }
    return out;
}

void codebox_expr_do(t_codebox *x, t_symbol *msg, long ac, t_atom *av)
{
    char *buf = nullptr;
    bach_atoms2text(ac, av, &buf);
    std::string s = buf ? buf : "";
    if (buf)
        sysmem_freeptr(buf);
    while (!s.empty() && s.back() == ' ')
        s.pop_back();
    x->n_state->setText(cb_normalize_newlines(s), true);
    codebox_compile(x, CB_COMPILE_USER);
}

void codebox_expr(t_codebox *x, t_symbol *msg, long ac, t_atom *av)
{
    defer(x, (method) codebox_expr_do, msg, ac, av);
}

// called by the codableobj machinery when the code has been changed
// by "read", the file watcher or the external editor
void codebox_bellcodechanged_do(t_codebox *x, t_symbol *s, long ac, t_atom *av)
{
    std::string code = x->n_ob.c_text ? x->n_ob.c_text : "";
    if (!code.empty() && code.back() == ' ') // the trailing space added by codableobj
        code.pop_back();
    x->n_state->setText(cb_normalize_newlines(code), true);
    // recompile to update the ports (and the status)
    codebox_compile(x, CB_COMPILE_SILENT);
}

void codebox_bellcodechanged(t_codebox *x)
{
    defer_low(x, (method) codebox_bellcodechanged_do, NULL, 0, NULL);
}

void codebox_dblclick(t_codebox *x)
{
    // let the external editor see the current text, even if not compiled
    if (x->n_state->modified)
        codebox_compile(x, CB_COMPILE_SILENT);
    codableobj_dblclick_helper((t_codableobj *) x, gensym("code"));
}


////////////////////////////////////////////////////////////////////////
// LIFE CYCLE
////////////////////////////////////////////////////////////////////////

void *codebox_new(t_symbol *s, long argc, t_atom *argv)
{
    t_dictionary *d = object_dictionaryarg(argc, argv);
    if (!d)
        return NULL;

    t_codebox *x = (t_codebox *) object_alloc_debug(codebox_class);
    if (!x) {
        error(BACH_CANT_INSTANTIATE);
        return NULL;
    }

    long flags = 0
    | JBOX_DRAWFIRSTIN
    | JBOX_NODRAWBOX
    | JBOX_DRAWINLAST
    | JBOX_GROWBOTH
    | JBOX_HILITE
    ;
    jbox_new(&x->n_ob.c_box.l_box, flags, argc, argv);
    x->n_ob.c_box.l_box.b_firstin = (t_object *) x;

    t_codableobj *cx = &x->n_ob;
    t_cbState *st = x->n_state = new t_cbState;
    cx->c_isUI = true;
    cx->c_ofTable = new t_ofTable;
    codebox_ownedFunctionsSetup(x);
    cx->c_embed = 1;
    cx->c_maxtime = 60000;
    cx->c_watch = 1;
    cx->c_text = (char *) bach_newptr(2);
    strncpy_zero(cx->c_text, " ", 2);

    x->n_triggers = llll_get();
    llll_appendlong(x->n_triggers, 1);
    x->n_linenumbers = 1;
    x->n_tabsize = 4;

    attr_dictionary_process(x, d);
    st->tabSize = std::max<long>(1, (long) x->n_tabsize);

    // the code, as typed in the editor
    const char *code = nullptr;
    if (dictionary_getstring(d, gensym("code"), &code) == MAX_ERR_NONE && code)
        st->text = cb_normalize_newlines(code);
    st->rebuildLines();
    st->spansDirty = true;

    // the ports the object had when it was saved:
    // if the saved code is not valid, we still want the patch cords to be restored
    t_atom_long savedIO[4] = { 0, 0, 0, 0 };
    {
        long ac = 0;
        t_atom *av = nullptr;
        if (dictionary_getatoms(d, gensym("bellio"), &ac, &av) == MAX_ERR_NONE && ac >= 4)
            for (int i = 0; i < 4; i++)
                savedIO[i] = atom_getlong(av + i);
    }

    // build the code
    if (!cb_is_blank(st->text)) {
        sysmem_freeptr(cx->c_text);
        cx->c_text = sysmem_newptr((t_ptr_size) st->text.size() + 2);
        memcpy(cx->c_text, st->text.data(), st->text.size());
        cx->c_text[st->text.size()] = ' ';
        cx->c_text[st->text.size() + 1] = 0;
        long codeac = -1;
        t_atom_long *io = st->parsedIO;
        if (codableobj_buildAst(cx, &codeac, io, io + 1, io + 2, io + 3) == MAX_ERR_NONE) {
            x->n_status = CB_STATUS_OK;
        } else {
            x->n_status = CB_STATUS_ERROR;
            std::fill(io, io + 4, -1);
            object_error((t_object *) x, "Invalid code");
        }
    }

    // the ports
    long di, dout, dri, dro;
    cb_compute_io(x, st->parsedIO, savedIO, &di, &dout, &dri, &dro);
    x->n_dataInlets = di;
    x->n_dataOutlets = dout;
    x->n_directInlets = dri;
    x->n_directOutlets = dro;

    long totInlets = di + dri;
    std::string outlets(dout + dro + 1, '4');
    llllobj_jbox_setup((t_llllobj_jbox *) x, totInlets, outlets.c_str());

    st->proxies.assign(totInlets - 1, nullptr);
    st->proxyIds.assign(totInlets - 1, 0);
    for (long i = totInlets - 1; i > 0; i--) {
        st->proxies[i - 1] = proxy_new(x, i, &x->n_in);
        st->proxyIds[i - 1] = i;
    }
    st->nextProxyId = totInlets;
    x->n_ioReady = true;

    bach_atomic_lock(&cx->c_triggers_lock);
    codebox_parse_all_triggers(x);
    bach_atomic_unlock(&cx->c_triggers_lock);

    if (cx->c_main) {
        cx->c_main->setOutlets(x->n_dataOutlets);
        if (cx->c_watch)
            codableobj_start_all_filewatchers(cx);
        defer_low(x, (method)codableobj_resolvepatchervars, NULL, 0, NULL);
    }
    defer_low(x, (method)codableobj_resolve_trigger_vars, NULL, 0, NULL);
    defer_low(x, (method)codableobj_setready, NULL, 0, NULL);

    jbox_ready(&x->n_ob.c_box.l_box);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_UI);

    if (cx->c_auto)
        defer_low(x, (method) codebox_deferbang, _sym_bang, 0, nullptr);

    return x;
}

void codebox_free(t_codebox *x)
{
    jbox_free(&x->n_ob.c_box.l_box);
    for (void *p : x->n_state->proxies)
        object_free(p);
    llll_free(x->n_triggers);
    codableobj_free((t_codableobj *) x); // also frees the llllobj stuff
    delete x->n_state;
}

void codebox_jsave(t_codebox *x, t_dictionary *d)
{
    if (x->n_ob.c_embed && !x->n_state->text.empty())
        dictionary_appendstring(d, gensym("code"), x->n_state->text.c_str());
    t_atom io[4];
    atom_setlong(io, x->n_dataInlets);
    atom_setlong(io + 1, x->n_dataOutlets);
    atom_setlong(io + 2, x->n_directInlets);
    atom_setlong(io + 3, x->n_directOutlets);
    dictionary_appendatoms(d, gensym("bellio"), 4, io);
}

t_max_err codebox_setattr_tabsize(t_codebox *x, t_object *attr, long ac, t_atom *av)
{
    if (ac && av) {
        x->n_tabsize = CLAMP(atom_getlong(av), 1, 16);
        if (x->n_state)
            x->n_state->tabSize = x->n_tabsize;
        jbox_redraw((t_jbox *) x);
    }
    return MAX_ERR_NONE;
}

t_max_err codebox_notify(t_codebox *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
    if (msg == _sym_attr_modified) {
        t_symbol *name = (t_symbol *) object_method((t_object *) data, _sym_getname);
        if (name == _sym_fontname || name == _sym_fontsize || name == gensym("fontface")) {
            x->n_state->metricsFont = nullptr; // force the font metrics to be recomputed
            jbox_redraw((t_jbox *) x);
        }
    }
    return jbox_notify((t_jbox *) x, s, msg, sender, data);
}


////////////////////////////////////////////////////////////////////////
// GEOMETRY
////////////////////////////////////////////////////////////////////////

struct t_cbGeom {
    double w, h;
    double gutterW;
    double textX, textY, textW, textH;  // the text area
    double toolbarY;
    t_rect hammer;
};

static void cb_update_metrics(t_codebox *x)
{
    t_cbState *st = x->n_state;
    t_symbol *fontname = jbox_get_fontname((t_object *) x);
    double fontsize = jbox_get_fontsize((t_object *) x);
    if (fontname == st->metricsFont && fontsize == st->metricsSize)
        return;
    t_jfont *f = jfont_create(fontname->s_name,
                              (t_jgraphics_font_slant) jbox_get_font_slant((t_object *) x),
                              (t_jgraphics_font_weight) jbox_get_font_weight((t_object *) x),
                              fontsize);
    if (!f)
        return;
    double w, h;
    const char *probe = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM"; // 50 chars
    jfont_text_measure(f, probe, &w, &h);
    t_jgraphics_font_extents ext;
    jfont_extents(f, &ext);
    jfont_destroy(f);
    st->charW = w / 50.;
    st->ascent = ext.ascent;
    st->lineH = ceil(std::max(ext.height, ext.ascent + ext.descent)) + 1;
    st->metricsFont = fontname;
    st->metricsSize = fontsize;
}

static t_cbGeom cb_geom(t_codebox *x, double w, double h)
{
    t_cbState *st = x->n_state;
    t_cbGeom g;
    g.w = w;
    g.h = h;
    if (x->n_linenumbers) {
        long digits = std::max(2L, (long) std::to_string(st->numLines()).size());
        g.gutterW = digits * st->charW + 12;
    } else
        g.gutterW = 0;
    g.toolbarY = h - CB_TOOLBAR_H;
    g.textX = g.gutterW + CB_PAD;
    g.textY = CB_PAD;
    g.textW = std::max(1., w - g.textX - CB_PAD);
    g.textH = std::max(1., g.toolbarY - g.textY);
    g.hammer = { 3, g.toolbarY + 2, CB_HAMMER_W, CB_TOOLBAR_H - 4 };
    return g;
}

static bool cb_in_rect(t_pt pt, const t_rect &r)
{
    return pt.x >= r.x && pt.x <= r.x + r.width && pt.y >= r.y && pt.y <= r.y + r.height;
}

static void cb_clamp_scroll(t_codebox *x)
{
    t_cbState *st = x->n_state;
    t_cbGeom g = cb_geom(x, st->boxW, st->boxH);
    double maxY = std::max(0., st->numLines() * st->lineH - g.textH + CB_PAD);
    double maxX = std::max(0., (st->maxCols() + 2) * st->charW - g.textW);
    st->scrollY = std::max(0., std::min(st->scrollY, maxY));
    st->scrollX = std::max(0., std::min(st->scrollX, maxX));
}

static void cb_scroll_to_caret(t_codebox *x)
{
    t_cbState *st = x->n_state;
    t_cbGeom g = cb_geom(x, st->boxW, st->boxH);
    long line = st->lineOf(st->caret);
    double y = line * st->lineH;
    if (y < st->scrollY)
        st->scrollY = y;
    else if (y + st->lineH > st->scrollY + g.textH)
        st->scrollY = y + st->lineH - g.textH;
    double cx = st->colOf(st->caret) * st->charW;
    if (cx < st->scrollX)
        st->scrollX = std::max(0., cx - 4 * st->charW);
    else if (cx > st->scrollX + g.textW - st->charW)
        st->scrollX = cx - g.textW + 4 * st->charW;
    cb_clamp_scroll(x);
}

static long cb_pos_from_point(t_codebox *x, t_pt pt)
{
    t_cbState *st = x->n_state;
    t_cbGeom g = cb_geom(x, st->boxW, st->boxH);
    double yy = pt.y - g.textY + st->scrollY;
    long line = yy < 0 ? 0 : (long) (yy / st->lineH);
    if (line >= st->numLines())
        return (long) st->text.size();
    double col = (pt.x - g.textX + st->scrollX) / st->charW;
    return st->posAtCol(line, col);
}

static void cb_get_box_size(t_codebox *x, t_object *patcherview)
{
    t_rect rect;
    jbox_get_rect_for_view((t_object *) x, patcherview, &rect);
    x->n_state->boxW = rect.width;
    x->n_state->boxH = rect.height;
}


////////////////////////////////////////////////////////////////////////
// PAINT
////////////////////////////////////////////////////////////////////////

static void cb_paint_hammer(t_jgraphics *g, const t_rect &r, t_jrgba *color)
{
    double cx = r.x + r.width / 2., cy = r.y + r.height / 2.;
    jgraphics_save(g);
    jgraphics_translate(g, cx, cy);
    jgraphics_rotate(g, -M_PI / 4.);
    jgraphics_set_source_jrgba(g, color);
    // handle
    jgraphics_rectangle(g, -1.1, -1.5, 2.2, 8.5);
    jgraphics_fill(g);
    // head
    jgraphics_rectangle_rounded(g, -5., -5.5, 10., 4.2, 1., 1.);
    jgraphics_fill(g);
    jgraphics_restore(g);
}

void codebox_paint(t_codebox *x, t_object *view)
{
    t_cbState *st = x->n_state;
    t_rect rect;
    jbox_get_rect_for_view((t_object *) x, view, &rect);
    t_jgraphics *g = (t_jgraphics *) patcherview_get_jgraphics(view);

    cb_update_metrics(x);
    st->boxW = rect.width;
    st->boxH = rect.height;
    if (st->spansDirty) {
        cb_highlight(st->text, st->spans);
        st->spansDirty = false;
    }
    cb_clamp_scroll(x);

    const t_cbGeom gm = cb_geom(x, rect.width, rect.height);
    t_symbol *fontname = jbox_get_fontname((t_object *) x);
    const double fontsize = jbox_get_fontsize((t_object *) x);
    const t_jgraphics_font_slant slant = (t_jgraphics_font_slant) jbox_get_font_slant((t_object *) x);
    const t_jgraphics_font_weight weight = (t_jgraphics_font_weight) jbox_get_font_weight((t_object *) x);
    const double charW = st->charW, lineH = st->lineH;
    const long nLines = st->numLines();
    const long caretLine = st->lineOf(st->caret);
    const long selS = st->selStart(), selE = st->selEnd();

    // background
    jgraphics_set_source_jrgba(g, &x->n_bgcolor);
    jgraphics_rectangle(g, 0, 0, rect.width, rect.height);
    jgraphics_fill(g);

    // ------- text area -------
    jgraphics_save(g);
    jgraphics_clip(g, gm.gutterW, 0, rect.width - gm.gutterW, gm.toolbarY);

    long first = std::max(0L, (long) (st->scrollY / lineH) - 1);
    long last = std::min(nLines - 1, (long) ((st->scrollY + gm.textH) / lineH) + 1);
    auto lineY = [&](long l) { return gm.textY + l * lineH - st->scrollY; };
    auto colX = [&](long col) { return gm.textX + col * charW - st->scrollX; };

    // current line
    if (x->n_hasFocus && !st->hasSelection() && caretLine >= first && caretLine <= last) {
        jgraphics_set_source_jrgba(g, &x->n_curlinecolor);
        jgraphics_rectangle(g, gm.gutterW, lineY(caretLine), rect.width - gm.gutterW, lineH);
        jgraphics_fill(g);
    }

    // selection
    if (st->hasSelection()) {
        jgraphics_set_source_jrgba(g, &x->n_selcolor);
        for (long l = std::max(first, st->lineOf(selS)); l <= std::min(last, st->lineOf(selE)); l++) {
            long a = std::max(selS, st->lineStart(l));
            long b = std::min(selE, st->lineEnd(l));
            double x1 = colX(st->colOf(a));
            double x2 = colX(st->colOf(b));
            if (selE > st->lineEnd(l)) // the newline is selected too
                x2 += charW / 2.;
            if (x2 > x1) {
                jgraphics_rectangle(g, x1, lineY(l), x2 - x1, lineH);
                jgraphics_fill(g);
            }
        }
    }

    // text
    jgraphics_select_font_face(g, fontname->s_name, slant, weight);
    jgraphics_set_font_size(g, fontsize);
    const std::vector<t_cbSpan> &spans = st->spans;
    for (long l = first; l <= last; l++) {
        const long ls = st->lineStart(l), le = st->lineEnd(l);
        const double baseline = lineY(l) + st->ascent;
        // the first span that ends after the line start
        size_t si = std::lower_bound(spans.begin(), spans.end(), ls,
                                     [](const t_cbSpan &sp, long pos) { return sp.end <= pos; }) - spans.begin();
        long pos = ls;
        long col = 0;
        while (pos < le) {
            long segEnd;
            int scope;
            if (si < spans.size() && spans[si].start <= pos) {
                segEnd = std::min(spans[si].end, le);
                scope = spans[si].scope;
            } else {
                segEnd = si < spans.size() ? std::min(spans[si].start, le) : le;
                scope = CB_SCOPE_TEXT;
            }
            if (segEnd <= pos) { // shouldn't happen, but let's be safe
                si++;
                continue;
            }
            jgraphics_set_source_jrgba(g, scope == CB_SCOPE_TEXT ? &x->n_textcolor : &x->n_syntaxcolor[scope]);
            // draw the segment, run by run, expanding the tabs
            long runStart = pos, runCol = col;
            for (long i = pos; i <= segEnd; i++) {
                bool atEnd = i == segEnd;
                unsigned char c = atEnd ? 0 : st->text[i];
                if (atEnd || c == '\t') {
                    if (i > runStart) {
                        double xx = colX(runCol);
                        if (xx < rect.width) {
                            std::string run = st->text.substr(runStart, i - runStart);
                            jgraphics_move_to(g, xx, baseline);
                            jgraphics_show_text(g, run.c_str());
                        }
                    }
                    if (!atEnd) {
                        col = (col / st->tabSize + 1) * st->tabSize;
                        runStart = i + 1;
                        runCol = col;
                    }
                } else if ((c & 0xC0) != 0x80) {
                    col++;
                }
            }
            pos = segEnd;
            if (si < spans.size() && spans[si].end <= pos)
                si++;
        }
    }

    // caret
    if (x->n_hasFocus && caretLine >= first && caretLine <= last) {
        double cx = colX(st->colOf(st->caret));
        jgraphics_set_source_jrgba(g, &x->n_caretcolor);
        jgraphics_set_line_width(g, 1.5);
        jgraphics_move_to(g, cx, lineY(caretLine) + 1);
        jgraphics_line_to(g, cx, lineY(caretLine) + lineH - 1);
        jgraphics_stroke(g);
    }

    jgraphics_restore(g);

    // ------- gutter -------
    if (x->n_linenumbers) {
        jgraphics_set_source_jrgba(g, &x->n_guttercolor);
        jgraphics_rectangle(g, 0, 0, gm.gutterW, gm.toolbarY);
        jgraphics_fill(g);
        jgraphics_set_source_jrgba(g, &x->n_bordercolor);
        jgraphics_set_line_width(g, 0.5);
        jgraphics_move_to(g, gm.gutterW - 0.5, 0);
        jgraphics_line_to(g, gm.gutterW - 0.5, gm.toolbarY);
        jgraphics_stroke(g);

        jgraphics_save(g);
        jgraphics_clip(g, 0, 0, gm.gutterW, gm.toolbarY);
        jgraphics_select_font_face(g, fontname->s_name, slant, JGRAPHICS_FONT_WEIGHT_NORMAL);
        jgraphics_set_font_size(g, fontsize);
        for (long l = first; l <= last; l++) {
            std::string num = std::to_string(l + 1);
            t_jrgba col = x->n_linenumcolor;
            if (l == caretLine && x->n_hasFocus)
                col = x->n_textcolor;
            jgraphics_set_source_jrgba(g, &col);
            jgraphics_move_to(g, gm.gutterW - 6 - num.size() * charW, lineY(l) + st->ascent);
            jgraphics_show_text(g, num.c_str());
        }
        jgraphics_restore(g);
    }

    // ------- toolbar -------
    jgraphics_set_source_jrgba(g, &x->n_toolbarcolor);
    jgraphics_rectangle(g, 0, gm.toolbarY, rect.width, CB_TOOLBAR_H);
    jgraphics_fill(g);
    jgraphics_set_source_jrgba(g, &x->n_bordercolor);
    jgraphics_set_line_width(g, 0.5);
    jgraphics_move_to(g, 0, gm.toolbarY + 0.25);
    jgraphics_line_to(g, rect.width, gm.toolbarY + 0.25);
    jgraphics_stroke(g);

    // the hammer button
    if (x->n_hammerHover || x->n_hammerPressed) {
        t_jrgba hb = jgraphics_jrgba_darker(&x->n_toolbarcolor, x->n_hammerPressed ? 0.2 : 0.1);
        jgraphics_set_source_jrgba(g, &hb);
        jgraphics_rectangle_rounded(g, gm.hammer.x, gm.hammer.y, gm.hammer.width, gm.hammer.height, 4, 4);
        jgraphics_fill(g);
    }
    cb_paint_hammer(g, gm.hammer, st->modified ? &x->n_modifiedcolor : &x->n_hammercolor);

    // status
    const char *status;
    t_jrgba *dotcolor;
    if (st->modified) {
#ifdef MAC_VERSION
        status = "modified (Cmd+Return to compile)";
#else
        status = "modified (Ctrl+Enter to compile)";
#endif
        dotcolor = &x->n_modifiedcolor;
    } else switch (x->n_status) {
        case CB_STATUS_OK:      status = "compiled";                            dotcolor = &x->n_okcolor;       break;
        case CB_STATUS_ERROR:   status = "syntax error (see the Max Console)";  dotcolor = &x->n_errorcolor;    break;
        default:                status = "no code";                             dotcolor = &x->n_linenumcolor;  break;
    }
    double sx = gm.hammer.x + gm.hammer.width + 6;
    double sy = gm.toolbarY + CB_TOOLBAR_H / 2.;
    jgraphics_set_source_jrgba(g, dotcolor);
    jgraphics_ellipse(g, sx, sy - 3, 6, 6);
    jgraphics_fill(g);

    jgraphics_select_font_face(g, "Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL);
    jgraphics_set_font_size(g, 10);
    char iobuf[64];
    snprintf(iobuf, 64, "in %ld+%ld  out %ld+%ld",
             (long) x->n_dataInlets, (long) x->n_directInlets,
             (long) x->n_dataOutlets, (long) x->n_directOutlets);
    double iow, ioh, stw, sth;
    jgraphics_text_measure(g, iobuf, &iow, &ioh);
    jgraphics_text_measure(g, status, &stw, &sth);
    jgraphics_set_source_jrgba(g, &x->n_linenumcolor);
    if (sx + 10 + stw + 12 + iow < rect.width) {
        jgraphics_move_to(g, rect.width - iow - 6, sy + 3.5);
        jgraphics_show_text(g, iobuf);
    }
    jgraphics_set_source_jrgba(g, &x->n_textcolor);
    jgraphics_save(g);
    jgraphics_clip(g, sx, gm.toolbarY, std::max(0., rect.width - sx), CB_TOOLBAR_H);
    jgraphics_move_to(g, sx + 10, sy + 3.5);
    jgraphics_show_text(g, status);
    jgraphics_restore(g);

    // ------- border -------
    if (x->n_hasFocus) {
        jgraphics_set_source_jrgba(g, &x->n_focusbordercolor);
        jgraphics_set_line_width(g, 2);
        jgraphics_rectangle(g, 1, 1, rect.width - 2, rect.height - 2);
    } else {
        jgraphics_set_source_jrgba(g, &x->n_bordercolor);
        jgraphics_set_line_width(g, 1);
        jgraphics_rectangle(g, 0.5, 0.5, rect.width - 1, rect.height - 1);
    }
    jgraphics_stroke(g);
}


////////////////////////////////////////////////////////////////////////
// MOUSE
////////////////////////////////////////////////////////////////////////

void codebox_mousedown(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_cbState *st = x->n_state;
    cb_get_box_size(x, patcherview);
    t_cbGeom gm = cb_geom(x, st->boxW, st->boxH);

    if (cb_in_rect(pt, gm.hammer)) {
        x->n_hammerPressed = 1;
        x->n_hammerHover = 1;
        jbox_redraw((t_jbox *) x);
        return;
    }
    if (pt.y >= gm.toolbarY)
        return;

    long pos;
    if (pt.x < gm.gutterW) { // click on the line numbers: select the line
        double yy = pt.y - gm.textY + st->scrollY;
        long line = std::max(0L, std::min(st->numLines() - 1, (long) (yy / st->lineH)));
        if (!(modifiers & eShiftKey))
            st->anchor = st->lineStart(line);
        pos = line + 1 < st->numLines() ? st->lineStart(line + 1) : st->lineEnd(line);
        st->moveCaret(pos, true);
    } else {
        pos = cb_pos_from_point(x, pt);
        st->moveCaret(pos, modifiers & eShiftKey);
    }
    st->preferredCol = -1;
    st->dragging = true;
    st->lastEditKind = CB_EDIT_OTHER;
    jbox_redraw((t_jbox *) x);
}

void codebox_mousedoubleclick(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_cbState *st = x->n_state;
    cb_get_box_size(x, patcherview);
    t_cbGeom gm = cb_geom(x, st->boxW, st->boxH);
    if (pt.y >= gm.toolbarY || pt.x < gm.gutterW)
        return;
    long pos = cb_pos_from_point(x, pt);
    long a = pos, b = pos;
    while (a > 0 && cb_isWordChar(st->text[a - 1]))
        a--;
    while (b < (long) st->text.size() && cb_isWordChar(st->text[b]))
        b++;
    if (a == b && b < (long) st->text.size())
        b = st->nextCharPos(b);
    st->anchor = a;
    st->caret = b;
    st->dragging = false;
    jbox_redraw((t_jbox *) x);
}

void codebox_mousedrag(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_cbState *st = x->n_state;
    cb_get_box_size(x, patcherview);
    t_cbGeom gm = cb_geom(x, st->boxW, st->boxH);

    if (x->n_hammerPressed) {
        char hover = cb_in_rect(pt, gm.hammer);
        if (hover != x->n_hammerHover) {
            x->n_hammerHover = hover;
            jbox_redraw((t_jbox *) x);
        }
        return;
    }
    if (!st->dragging)
        return;

    // autoscroll
    if (pt.y < gm.textY)
        st->scrollY -= st->lineH;
    else if (pt.y > gm.toolbarY)
        st->scrollY += st->lineH;
    if (pt.x < gm.textX)
        st->scrollX -= st->charW * 2;
    else if (pt.x > gm.w)
        st->scrollX += st->charW * 2;
    cb_clamp_scroll(x);

    t_pt clamped = pt;
    clamped.y = std::max(gm.textY, std::min(pt.y, gm.toolbarY - 1));
    st->moveCaret(cb_pos_from_point(x, clamped), true);
    jbox_redraw((t_jbox *) x);
}

void codebox_mouseup(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_cbState *st = x->n_state;
    if (x->n_hammerPressed) {
        cb_get_box_size(x, patcherview);
        t_cbGeom gm = cb_geom(x, st->boxW, st->boxH);
        x->n_hammerPressed = 0;
        if (cb_in_rect(pt, gm.hammer))
            codebox_compile(x, CB_COMPILE_USER);
        jbox_redraw((t_jbox *) x);
    }
    st->dragging = false;
}

void codebox_mousemove(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_cbState *st = x->n_state;
    cb_get_box_size(x, patcherview);
    t_cbGeom gm = cb_geom(x, st->boxW, st->boxH);
    char hover = cb_in_rect(pt, gm.hammer);
    if (hover != x->n_hammerHover) {
        x->n_hammerHover = hover;
        jbox_redraw((t_jbox *) x);
    }
    if (pt.y < gm.toolbarY && pt.x >= gm.gutterW)
        jmouse_setcursor(patcherview, (t_object *) x, JMOUSE_CURSOR_IBEAM);
    else if (hover)
        jmouse_setcursor(patcherview, (t_object *) x, JMOUSE_CURSOR_POINTINGHAND);
    else
        jmouse_setcursor(patcherview, (t_object *) x, JMOUSE_CURSOR_ARROW);
}

void codebox_mouseleave(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers)
{
    if (x->n_hammerHover) {
        x->n_hammerHover = 0;
        jbox_redraw((t_jbox *) x);
    }
    jmouse_setcursor(patcherview, (t_object *) x, JMOUSE_CURSOR_ARROW);
}

void codebox_mousewheel(t_codebox *x, t_object *patcherview, t_pt pt, long modifiers, double x_inc, double y_inc)
{
    t_cbState *st = x->n_state;
    cb_get_box_size(x, patcherview);
    st->scrollY -= y_inc * st->lineH * 4;
    st->scrollX -= x_inc * st->charW * 4;
    cb_clamp_scroll(x);
    jbox_redraw((t_jbox *) x);
}

void codebox_focusgained(t_codebox *x, t_object *patcherview)
{
    x->n_hasFocus = 1;
    jbox_redraw((t_jbox *) x);
}

void codebox_focuslost(t_codebox *x, t_object *patcherview)
{
    x->n_hasFocus = 0;
    x->n_state->dragging = false;
    jbox_redraw((t_jbox *) x);
}


////////////////////////////////////////////////////////////////////////
// KEYBOARD
////////////////////////////////////////////////////////////////////////

static std::string cb_utf8(long cp)
{
    std::string s;
    if (cp < 0x80) {
        s += (char) cp;
    } else if (cp < 0x800) {
        s += (char) (0xC0 | (cp >> 6));
        s += (char) (0x80 | (cp & 0x3F));
    } else if (cp < 0x10000) {
        s += (char) (0xE0 | (cp >> 12));
        s += (char) (0x80 | ((cp >> 6) & 0x3F));
        s += (char) (0x80 | (cp & 0x3F));
    } else {
        s += (char) (0xF0 | (cp >> 18));
        s += (char) (0x80 | ((cp >> 12) & 0x3F));
        s += (char) (0x80 | ((cp >> 6) & 0x3F));
        s += (char) (0x80 | (cp & 0x3F));
    }
    return s;
}

// vertical movement, keeping the preferred column
static void cb_move_vertically(t_cbState *st, long dLines, bool extend)
{
    if (st->preferredCol < 0)
        st->preferredCol = st->colOf(st->caret);
    long line = st->lineOf(st->caret) + dLines;
    long pos;
    if (line < 0)
        pos = 0;
    else if (line >= st->numLines())
        pos = (long) st->text.size();
    else
        pos = st->posAtCol(line, st->preferredCol);
    double keep = st->preferredCol;
    st->moveCaret(pos, extend);
    st->preferredCol = keep;
}

long codebox_key(t_codebox *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
    t_cbState *st = x->n_state;
    const bool shift = modifiers & eShiftKey;
    const bool cmd = modifiers & eCommandKey; // Cmd on Mac, Ctrl on Windows
    const bool alt = modifiers & eAltKey;
#ifdef MAC_VERSION
    const bool wordMod = alt;
    const bool lineMod = cmd;
#else
    const bool wordMod = cmd;
    const bool lineMod = false;
#endif
    const long n = (long) st->text.size();
    bool vertical = false;

    switch (keycode) {
        case JKEY_RETURN:
            if (cmd || (modifiers & eControlKey)) {
                codebox_compile(x, CB_COMPILE_USER);
                return 1;
            } else {
                // newline, keeping the indentation of the current line
                std::string indent = st->leadingWhitespace(st->lineOf(st->selStart()));
                st->insert("\n" + indent, CB_EDIT_OTHER);
            }
            break;

        case JKEY_TAB:
            if (shift)
                st->indentLines(-1);
            else if (st->lineOf(st->selStart()) != st->lineOf(st->selEnd()))
                st->indentLines(1);
            else {
                long col = st->colOf(st->selStart());
                long nSpaces = st->tabSize - (col % st->tabSize);
                st->insert(std::string(nSpaces, ' '), CB_EDIT_TYPING);
            }
            break;

        case JKEY_BACKSPACE:
            if (st->hasSelection())
                st->insert("", CB_EDIT_DELETING);
            else if (st->caret > 0) {
                long from = wordMod ? st->prevWordPos(st->caret)
                          : lineMod ? st->lineStart(st->lineOf(st->caret))
                          : st->prevCharPos(st->caret);
                if (from == st->caret) from = st->prevCharPos(st->caret);
                st->anchor = from;
                st->insert("", CB_EDIT_DELETING);
            }
            break;

        case JKEY_DELETE:
            if (st->hasSelection())
                st->insert("", CB_EDIT_DELETING);
            else if (st->caret < n) {
                long to = wordMod ? st->nextWordPos(st->caret) : st->nextCharPos(st->caret);
                st->anchor = to;
                st->insert("", CB_EDIT_DELETING);
            }
            break;

        case JKEY_LEFTARROW:
            if (st->hasSelection() && !shift)
                st->moveCaret(st->selStart(), false);
            else if (lineMod)
                st->moveCaret(st->lineStart(st->lineOf(st->caret)), shift);
            else if (wordMod)
                st->moveCaret(st->prevWordPos(st->caret), shift);
            else
                st->moveCaret(st->prevCharPos(st->caret), shift);
            break;

        case JKEY_RIGHTARROW:
            if (st->hasSelection() && !shift)
                st->moveCaret(st->selEnd(), false);
            else if (lineMod)
                st->moveCaret(st->lineEnd(st->lineOf(st->caret)), shift);
            else if (wordMod)
                st->moveCaret(st->nextWordPos(st->caret), shift);
            else
                st->moveCaret(st->nextCharPos(st->caret), shift);
            break;

        case JKEY_UPARROW:
            if (lineMod)
                st->moveCaret(0, shift);
            else {
                cb_move_vertically(st, -1, shift);
                vertical = true;
            }
            break;

        case JKEY_DOWNARROW:
            if (lineMod)
                st->moveCaret(n, shift);
            else {
                cb_move_vertically(st, 1, shift);
                vertical = true;
            }
            break;

        case JKEY_PAGEUP:
        case JKEY_PAGEDOWN: {
            t_cbGeom gm = cb_geom(x, st->boxW, st->boxH);
            long page = std::max(1L, (long) (gm.textH / st->lineH) - 1);
            st->scrollY += (keycode == JKEY_PAGEUP ? -1 : 1) * page * st->lineH;
            cb_move_vertically(st, keycode == JKEY_PAGEUP ? -page : page, shift);
            vertical = true;
            break;
        }

        case JKEY_HOME:
            st->moveCaret(cmd ? 0 : st->lineStart(st->lineOf(st->caret)), shift);
            break;

        case JKEY_END:
            st->moveCaret(cmd ? n : st->lineEnd(st->lineOf(st->caret)), shift);
            break;

        case JKEY_ESC:
            return 0;

        default:
            if (cmd && !alt && keycode > 0) {
                switch (tolower((int) (keycode & 0xFF))) {
                    case 'a':
                        st->anchor = 0;
                        st->caret = n;
                        break;
                    case 'c':
                        if (st->hasSelection())
                            cb_clipboard_set(st->selectedText());
                        return 1;
                    case 'x':
                        if (st->hasSelection()) {
                            cb_clipboard_set(st->selectedText());
                            st->insert("", CB_EDIT_OTHER);
                        }
                        break;
                    case 'v': {
                        std::string s = cb_normalize_newlines(cb_clipboard_get());
                        if (!s.empty())
                            st->insert(s, CB_EDIT_OTHER);
                        break;
                    }
                    case 'z':
                        if (shift) st->redo(); else st->undo();
                        break;
                    case 'y':
                        st->redo();
                        break;
                    case '/':
                        st->toggleComment();
                        break;
                    case 'b': // like a build command
                        codebox_compile(x, CB_COMPILE_USER);
                        return 1;
                    default:
                        return 0; // let Max handle its own shortcuts
                }
            } else if (textcharacter >= 32 && textcharacter != 127) {
                st->insert(cb_utf8(textcharacter), textcharacter == ' ' ? CB_EDIT_OTHER : CB_EDIT_TYPING);
            } else
                return 0;
            break;
    }

    if (!vertical)
        st->preferredCol = -1;
    // caret movements break the coalescing of consecutive typing/deleting in the undo history
    switch (keycode) {
        case JKEY_LEFTARROW: case JKEY_RIGHTARROW: case JKEY_UPARROW: case JKEY_DOWNARROW:
        case JKEY_PAGEUP: case JKEY_PAGEDOWN: case JKEY_HOME: case JKEY_END:
            st->lastEditKind = CB_EDIT_OTHER;
            break;
        default:
            break;
    }
    cb_scroll_to_caret(x);
    jbox_redraw((t_jbox *) x);
    return 1;
}
