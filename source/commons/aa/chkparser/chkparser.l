%option noyywrap nodefault reentrant
%option noyyalloc noyyrealloc noyyfree
%option debug
%option outfile="chkparser.c"
%option prefix="chkparser_"

RESERVED ([ \t\n\\,\;)
INTEGER ([+-]?[0-9]+)
FLOAT ([+-]?(((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+)))
RATIONAL ({INTEGER}[/]{INTEGER})
NOTENAME ([a-g]|[A-G])
ACCIDENTAL ([#bxdq\^v]+)

%{
	#define BACH_MAX
	#ifdef BACH_MAX
    #include "llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #include "chkparser.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
%}

%%


^` {
    parserpost("typecheck: starting backtick");
    return H_SYM | H_BACKTICK; // because backtick wins, if we're here we don't need to scan any longer
}

^{INTEGER} {
    parserpost("typecheck: long");
    return H_LONG;
}

^{FLOAT} {
    parserpost("typecheck: double");
    return H_DOUBLE;
}

^{RATIONAL} {
    parserpost("typecheck: rational");
    return H_RAT;
}

^[-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER} {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

^[-+]?{NOTENAME}{INTEGER}{ACCIDENTAL} {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

^[-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER}[-+][0-9]+t {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

^[-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER}[-+][0-9]+[/]{INTEGER}t {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

^[^`\(\) \t\n\,\;][^\(\) \t\n\,\;]* {
    parserpost("typecheck: plain old symbol");
    return H_SYM;
}

^[^` \t\n\,\;][^ \t\n\,\;]* {
    parserpost("typecheck: parens, no reserved chars");
    return H_SYM | H_PAREN;
}

^[^`\(\)][^\(\)]* {
    parserpost("typecheck: reserved chars, no parens");
    return H_SYM | H_RESERVED;
}

^[^`](.|\n|\r)* {
    parserpost("typecheck: reserved chars parens");
    return H_SYM | H_PAREN | H_RESERVED;
}

%%

#ifndef BACH_MAX
int main(int argc, char **argv)
{
	yylex();
}
#endif




t_chkParser::t_chkParser() : t_parser()
{

    setPtr(sizeof(struct yyguts_t));
    setBasePtr();
    reset();
}

void t_chkParser::reset()
{
    t_parser::reset();
    /* By setting to 0xAA, we expose bugs in
     yy_init_globals. Leave at 0x00 for releases. */
    memset(this,0x00,sizeof(struct yyguts_t));
    //yy_init_globals ((yyscan_t) this);
}

long t_chkParser::parse(char *buf)
{
    parserpost("chkparser: parsing %s", buf);
    long type;
    YY_BUFFER_STATE bp = chkparser__scan_string(buf, (yyscan_t) this);
    chkparser__switch_to_buffer(bp, (yyscan_t) this);
    type = chkparser_lex((yyscan_t) this);
    reset();
    return type != H_NOTHING ? type : H_SYM;
}

t_bool t_chkParser::wantsBacktick(t_symbol *s)
{
    if (s == _llllobj_sym_nil || s == _llllobj_sym_null) {
        return true;
    } else {
        long type = parse(s->s_name);
        long mods = type & H_MODIFIERS;
        if ((type & H_PLAINTYPE) != H_SYM ||
            (mods & H_BACKTICK) ||
            ((mods & H_PAREN) && !(mods & H_RESERVED))) {
            return true;
        } else
            return false;
    }
}

t_symbol *t_chkParser::addQuoteIfNeeded(t_symbol *s)
{
    if (wantsBacktick(s))
        return sym_addquote(s->s_name);
    else
        return s;
}




void *chkparser_alloc(size_t bytes, void *yyscanner)
{
    void *b = ((t_chkParser *) yyscanner)->getPtr(bytes);
    parserpost(" chkparser_alloc: %d bytes requested, returning %p", bytes, b);
    return b;
}

void *chkparser_realloc(void *ptr,size_t bytes, void *yyscanner)
{
    parserpost(" chkparser_realloc: %d bytes requested for pointer %p, returning %p", bytes, ptr, ptr);
    return ptr;
}

void chkparser_free(void *ptr,void *yyscanner)
{
    return;
}
