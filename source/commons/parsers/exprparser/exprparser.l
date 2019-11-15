%{
    /*
     *  exprparser.l
     *
     * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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
%}

%option noyywrap nodefault reentrant
%option noyyalloc noyyrealloc noyyfree
%option never-interactive
%option header-file="exprparser.lex.h"
%option outfile="exprparser.c"
%option prefix="exprparser_"

%s BINARY

SEPARATOR ([ \t\n\r\(\)\[\]\{\}])
UINT ([0-9]+)
UFLOAT (((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+))
URAT ({UINT}[/][+-]?{UINT})
NOTENAME ([a-g]|[A-G])
ACCIDENTAL ([#bxdq\^v]+)

%{
    #ifndef BACH_MAX
    #define BACH_MAX
    #endif
    #ifdef BACH_MAX
    #include "foundation/llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #include "parsers/exprparser/exprparser.h"
    #include "math/lexpr.h"
    #include "math/llll_math.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif

    #define YY_NO_UNISTD_H
%}

%option extra-type = "t_exprparser_data *"

%%

%{
    t_exprparser_data *epd = yyextra;
%}

\( {
    BEGIN INITIAL;
    return lexpr_append_lexeme_OPEN(epd->lexeme);
}

\) {
    BEGIN BINARY;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_CLOSED(epd->lexeme);
    return err;
}

\, {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
    err = lexpr_append_lexeme_COMMA(epd->lexeme);
    return err;
}

\$[ifrpx][0-9]+ {
    BEGIN BINARY;
    return lexpr_append_lexeme_VAR(epd->lexeme, *(yytext + 1), atol(yytext + 2) - 1, epd->numvars, yytext, epd->offending);
}

"|" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
    err = lexpr_append_lexeme_BITOR(epd->lexeme);
    return err;
}

"||" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_LOGOR(epd->lexeme);
    return err;
}

"&" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_BITAND(epd->lexeme);
    return err;
}

"&&" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_LOGAND(epd->lexeme);
    return err;
}

"^" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_BITXOR(epd->lexeme);
    return err;
}

"^^" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_LOGXOR(epd->lexeme);
    return err;
}

"~" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_BITNOT(epd->lexeme);
    return err;
}

"!" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_LOGNOT(epd->lexeme);
    return err;
}

"!=" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_NEQ(epd->lexeme);
    return err;
}

"!==" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_NEQMATCH(epd->lexeme);
    return err;
}

"==" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_EQ(epd->lexeme);
    return err;
}

"===" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_EQMATCH(epd->lexeme);
    return err;
}

"<" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_LT(epd->lexeme);
    return err;
}

"<<" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_LSHIFT(epd->lexeme);
    return err;
}

"<=" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_LE(epd->lexeme);
    return err;
}

">" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_GT(epd->lexeme);
    return err;
}

">>" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_RSHIFT(epd->lexeme);
    return err;
}

">=" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_GE(epd->lexeme);
    return err;
}

"*" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_TIMES(epd->lexeme);
    return err;
}

"**" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_POW(epd->lexeme);
    return err;
}

"%" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_MOD(epd->lexeme);
    return err;
}

"/" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
        err = lexpr_append_lexeme_DIV(epd->lexeme);
    return err;
}

"//" {
    BEGIN INITIAL;
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
    err = lexpr_append_lexeme_DIVDIV(epd->lexeme);
    return err;
}

<BINARY>"+" {
    BEGIN INITIAL;
    parserpost(" lex: binary +");
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
    err = lexpr_append_lexeme_PLUS(epd->lexeme);
    return err;
}

<INITIAL>"+"/[^ \n\r\t] {
    parserpost(" lex: unary + (ignored)");
}

<BINARY>"-" {
    BEGIN INITIAL;
    parserpost(" lex: binary -");
    long err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(epd->lexeme - 1, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
    if (err == E_OK)
    err = lexpr_append_lexeme_MINUS(epd->lexeme);
    return err;
}

<INITIAL>"-" {
    parserpost(" lex: unary -");
    return lexpr_append_lexeme_UMINUS(epd->lexeme);
}

{UINT} {
    parserpost(" lex: UINT %d\n", atoi(yytext));
    BEGIN BINARY;
    return lexpr_append_lexeme_LONG(epd->lexeme, atol(yytext));
}


{UFLOAT} {
    parserpost(" lex: BACH_DOUBLE %lf\n", atof(yytext));
    BEGIN BINARY;
    return lexpr_append_lexeme_FLOAT(epd->lexeme, atof(yytext));
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT} {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_parser::eatPitchAsNameAccInt(yytext));
}

{NOTENAME}[-+]?{UINT}{ACCIDENTAL} {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_parser::eatPitchAsNameIntAcc(yytext));
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}+t {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_parser::eatPitchAsNameAccIntIntT(yytext));
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}[/][-+]?{UINT}t {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_parser::eatPitchAsNameAccIntRatT(yytext));
}

{UINT}t {
    t_shortRational alter = t_shortRational(atoi(yytext), 1);
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, alter, 0));
}

{URAT}t {
    char *textend;
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, t_shortRational(t_parser::eatRational(yytext)), 0));
}

{UFLOAT}t {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, t_shortRational(atof(yytext)), 0));
}

t {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, t_pitch::dblsharp, 0));
}

"pi"  { BEGIN BINARY; return lexpr_append_lexeme_FLOAT(epd->lexeme, M_PI); }

"cos" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, cos, "cos"); }
"sin" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sin, "sin"); }
"tan" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, tan, "tan"); }
"exp" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, exp, "exp"); }
"log" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log, "log"); }
"pow" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_op_pow, "pow"); }
"int" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_int, "int"); }
"rat" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_rat, "rat"); }
"num" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_num, "num"); }
"den" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_den, "den"); }
"abs" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_abs, "abs"); }
"sgn" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_sgn, "sgn"); }
"mod" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_mod, "mod"); }
"min" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_min, "min"); }
"max" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_max, "max"); }

"acos" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, acos, "acos"); }
"asin" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, asin, "asin"); }
"atan" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, atan, "atan"); }
"cosh" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, cosh, "cosh"); }
"sinh" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sinh, "sinh"); }
"tanh" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, tanh, "tanh"); }
"exp2" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, exp2, "exp2"); }
"log2" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log2, "log2"); }
"sqrt" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sqrt, "sqrt"); }
"ceil" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, ceil, "ceil"); }
"fmod" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, fmod, "fmod"); }

"atan2" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, atan2, "atan2"); }
"acosh" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, acosh, "acosh"); }
"asinh" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, asinh, "asinh"); }
"atanh" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, atanh, "atanh"); }
"log10" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log10, "log10"); }
"hypot" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, hypot, "hypot"); }
"floor" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, floor, "floor"); }
"round" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, round, "round"); }
"trunc" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, trunc, "trunc"); }
"float" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_float, "float"); }

"random" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL_dontfold(epd->lexeme, hatom_fn_random, "random"); }
"bessel" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_jn, "bessel"); }

"pitch" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_pitch, "pitch"); }
"degree" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_degree, "degree"); }
"octave" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_octave, "octave"); }
"alter" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_alter, "alter"); }
"cents" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_cents, "cents"); }
"makepitch" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_ternary_ALL(epd->lexeme, hatom_fn_makepitch, "makepitch"); }
"approx" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_approx, "approx"); }
"enharm" { BEGIN BINARY; return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_enharm, "enharm"); }



([A-Z]|[a-z]|_)+ {
    BEGIN BINARY;
    return lexpr_append_lexeme_VAR_substitution(epd->lexeme, yytext, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
}

[ \t\n\r] {
    parserpost(" lex: whitespace\n");
}

. {
    parserpost(" lex: unrecognized character %s", yytext);
    return E_BAD_EXPR;
}

%%

#ifndef BACH_MAX
int main(int argc, char **argv)
{
    yylex();
}
#endif

t_exprParser::t_exprParser(t_exprparser_data *data) : t_parser()
{
    struct yyguts_t dummy_yyguts;
    exprparser_set_extra(data, &dummy_yyguts);
    
    setPtr(sizeof(struct yyguts_t));
    setBasePtr();

    /* By setting to 0xAA, we expose bugs in
     yy_init_globals. Leave at 0x00 for releases. */
    reset();
    exprparser_set_extra (data, (yyscan_t) this);
}

void t_exprParser::setBuffer(char *buf)
{
    parserpost("exprparser: setting to buffer %s", buf);
    buffer = yy_scan_string(buf, (yyscan_t) this);
    yy_switch_to_buffer((YY_BUFFER_STATE) buffer, (yyscan_t) this);
}

void t_exprParser::setStartCondition(int condition)
{
    struct yyguts_t *yyg = (struct yyguts_t*) this;
    BEGIN condition;
}

void t_exprParser::reset()
{
    t_parser::reset();
    //memset(this,0x00,sizeof(struct yyguts_t));
    yy_init_globals ((yyscan_t) this);
    
}

int t_exprParser::lex()
{
    return exprparser_lex((yyscan_t) this);
}

void *exprparser_alloc(size_t bytes, void *yyscanner)
{
    void *b = ((t_exprParser *) yyscanner)->getPtr(bytes);
    parserpost(" exprparser_alloc: %d bytes requested, returning %p", bytes, b);
    return b;
}

void *exprparser_realloc(void *ptr,size_t bytes, void *yyscanner)
{
    parserpost(" exprparser_realloc: %d bytes requested for pointer %p, returning %p", bytes, ptr, ptr);
    return ptr;
}

void exprparser_free(void *ptr,void *yyscanner)
{
    return;
}
