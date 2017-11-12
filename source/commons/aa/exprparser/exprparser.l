%option noyywrap nodefault reentrant
%option noyyalloc noyyrealloc noyyfree
%option header-file="exprparser.lex.h"
%option outfile="exprparser.c"
%option prefix="exprparser_"

%s BINARY

SEPARATOR ([ \t\n\(\)\[\]\{\}])
UINT ([0-9]+)
UFLOAT (((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+))
URAT ({UINT}[/][+-]?{UINT})
NOTENAME ([a-g]|[A-G])
ACCIDENTAL ([#bxdq\^v]+)

%{
	#define BACH_MAX
	#ifdef BACH_MAX
    #include "llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #include "exprparser.h"
    #include "lexpr.h"
    #include "llll_math.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
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

<INITIAL>"+"/[^ /n/t] {
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

{URAT} {
    char *textend;
	long num = strtol(yytext, &textend, 10);
	long den = strtol(textend + 1, NULL, 10);
    parserpost(" lex: URAT %ld / %ld\n", num, den);
    BEGIN BINARY;
    return lexpr_append_lexeme_RATIONAL(epd->lexeme, t_rational(num, den));
}

{UFLOAT} {
    parserpost(" lex: DOUBLE %lf\n", atof(yytext));
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

"cos" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, cos, "cos"); }
"sin" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sin, "sin"); }
"tan" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, tan, "tan"); }
"exp" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, exp, "exp"); }
"log" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log, "log"); }
"pow" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_pow, "pow"); }
"int" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_int, "int"); }
"rat" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_rat, "rat"); }
"num" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_num, "num"); }
"den" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_den, "den"); }
"abs" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_abs, "abs"); }
"sgn" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_sgn, "sgn"); }
"mod" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_mod, "mod"); }

"acos" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, acos, "acos"); }
"asin" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, asin, "asin"); }
"atan" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, atan, "atan"); }
"cosh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, cosh, "cosh"); }
"sinh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sinh, "sinh"); }
"tanh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, tanh, "tanh"); }
"exp2" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, exp2, "exp2"); }
"log2" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log2, "log2"); }
"sqrt" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sqrt, "sqrt"); }
"ceil" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, ceil, "ceil"); }
"fmod" { return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, fmod, "fmod"); }

"atan2" { return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, atan2, "atan2"); }
"acosh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, acosh, "acosh"); }
"asinh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, asinh, "asinh"); }
"atanh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, atanh, "atanh"); }
"log10" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log10, "log10"); }
"hypot" { return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, hypot, "hypot"); }
"floor" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, floor, "floor"); }
"round" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, round, "round"); }
"trunc" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, trunc, "trunc"); }
"float" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_float, "float"); }

"random" { return lexpr_append_lexeme_FUNC_binary_ALL_dontfold(epd->lexeme, hatom_fn_random, "random"); }
"bessel" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_jn, "bessel"); }

"pitch" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_pitch, "pitch"); }
"degree" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_degree, "degree"); }
"octave" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_octave, "octave"); }
"alter" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_alter, "alter"); }
"cents" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_cents, "cents"); }
"makepitch" { return lexpr_append_lexeme_FUNC_ternary_ALL(epd->lexeme, hatom_fn_makepitch, "makepitch"); }
"approx" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_approx, "approx"); }
"enharm" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_enharm, "enharm"); }



([A-Z]|[a-z]|_)+ {
    BEGIN BINARY;
    return lexpr_append_lexeme_VAR_substitution(epd->lexeme, yytext, epd->subs_count, epd->substitutions, epd->numvars, epd->offending);
}

[ \t\n] {
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
