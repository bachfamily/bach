%option noyywrap nodefault reentrant
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
    return lexpr_append_lexeme_CLOSED(epd->lexeme);
}

\, {
    BEGIN INITIAL;
    return lexpr_append_lexeme_COMMA(epd->lexeme);
}

\$[ifrpx][0-9]+ {
    BEGIN BINARY;
    return lexpr_append_lexeme_VAR(epd->lexeme, *(yytext + 1), atol(yytext + 2) - 1, epd->numvars, yytext, epd->offending);
}

"|" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_BITOR(epd->lexeme);
}

"||" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_LOGOR(epd->lexeme);
}

"&" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_BITAND(epd->lexeme);
}

"&&" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_LOGAND(epd->lexeme);
}

"^" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_BITXOR(epd->lexeme);
}

"^^" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_LOGXOR(epd->lexeme);
}

"~" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_BITNOT(epd->lexeme);
}

"!" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_LOGNOT(epd->lexeme);
}

"!=" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_NEQ(epd->lexeme);
}

"!==" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_NEQMATCH(epd->lexeme);
}

"==" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_EQ(epd->lexeme);
}

"===" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_EQMATCH(epd->lexeme);
}

"<" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_LT(epd->lexeme);
}

"<<" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_LSHIFT(epd->lexeme);
}

"<=" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_LE(epd->lexeme);
}

">" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_GT(epd->lexeme);
}

">>" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_RSHIFT(epd->lexeme);
}

">=" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_GE(epd->lexeme);
}

"*" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_TIMES(epd->lexeme);
}

"**" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_POW(epd->lexeme);
}

"%" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_MOD(epd->lexeme);
}

"/" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_DIV(epd->lexeme);
}

"//" {
    BEGIN INITIAL;
    return lexpr_append_lexeme_DIVDIV(epd->lexeme);
}

<BINARY>"+" {
    BEGIN INITIAL;
    parserpost(" lex: binary +");
    return lexpr_append_lexeme_PLUS(epd->lexeme);
}

<INITIAL>"+"/[^ /n/t] {
    parserpost(" lex: unary + (ignored)");
}

<BINARY>"-" {
    BEGIN INITIAL;
    parserpost(" lex: binary -");
    return lexpr_append_lexeme_MINUS(epd->lexeme);
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
	long degree = t_pitch::text2degree(*yytext);
	char *next = yytext + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
	long octave = strtol(next, NULL, 10);
	parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(degree, alter, octave));
}

{NOTENAME}[-+]?{UINT}{ACCIDENTAL} {
	long degree = t_pitch::text2degree(*yytext);
	char *acc;
	long octave = strtol(yytext + 1, &acc, 10);
	t_shortRational alter = t_pitch::text2alter(&acc);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(degree, alter, octave));
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}+t {
    long degree = t_pitch::text2degree(*yytext);
    char *next = yytext + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
    long octave = strtol(next, &next, 10);
    alter += t_shortRational(strtol(next, NULL, 10), 1);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(degree, alter, octave));
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}[/][-+]?{UINT}t {
    long degree = t_pitch::text2degree(*yytext);
    char *next = yytext + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
    long octave = strtol(next, &next, 10);
    alter += t_shortRational(strtol(next, &next, 10),  strtol(next + 1, NULL, 10));

    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(degree, alter, octave));
}

{UINT}t {
    t_shortRational alter = t_shortRational(atoi(yytext), 1);
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, alter, 0));
}

{URAT}t {
    char *textend;
    long num = strtol(yytext, &textend, 10);
    long den = strtol(textend + 1, NULL, 10);
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, t_shortRational(num, den), 0));
}

{UFLOAT}t {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, t_shortRational(atof(yytext)), 0));
}

t {
    BEGIN BINARY;
    return lexpr_append_lexeme_PITCH(epd->lexeme, t_pitch(0, t_pitch::dblsharp, 0));
}

"cos" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, cos); }
"sin" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sin); }
"tan" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, tan); }
"exp" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, exp); }
"log" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log); }
"pow" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_pow); }
"int" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_int); }
"rat" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_rat); }
"num" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_num); }
"den" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_den); }
"abs" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_abs); }
"sgn" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_sgn); }
"mod" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_mod); }

"acos" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, acos); }
"asin" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, asin); }
"atan" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, atan); }
"cosh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, cosh); }
"sinh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sinh); }
"tanh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, tanh); }
"exp2" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, exp2); }
"log2" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log2); }
"sqrt" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, sqrt); }
"ceil" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, ceil); }
"fmod" { return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, fmod); }

"atan2" { return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, atan2); }
"acosh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, acosh); }
"asinh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, asinh); }
"atanh" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, atanh); }
"log10" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, log10); }
"hypot" { return lexpr_append_lexeme_FUNC_binary_DOUBLE(epd->lexeme, hypot); }
"floor" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, floor); }
"round" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, round); }
"trunc" { return lexpr_append_lexeme_FUNC_unary_DOUBLE(epd->lexeme, trunc); }
"float" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_float); }

"random" { return lexpr_append_lexeme_FUNC_binary_ALL_dontfold(epd->lexeme, hatom_fn_random); }
"bessel" { return lexpr_append_lexeme_FUNC_binary_ALL(epd->lexeme, hatom_fn_jn); }

"pitch" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_pitch); }
"degree" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_degree); }
"octave" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_octave); }
"alter" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_alter); }
"cents" { return lexpr_append_lexeme_FUNC_unary_ALL(epd->lexeme, hatom_fn_cents); }
"makepitch" { return lexpr_append_lexeme_FUNC_ternary_ALL(epd->lexeme, hatom_fn_makepitch); }

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

void *exprparser_new(t_exprparser_data *data)
{
    yyscan_t scanner;
    yylex_init_extra(data, &scanner);
    return (void *) scanner;
}

void *exprparser_scan_string(void *myscanner, char *buf)
{
    YY_BUFFER_STATE bp = yy_scan_string(buf, (yyscan_t) myscanner);
    yy_switch_to_buffer(bp, (yyscan_t) myscanner);
    return (void *) bp;
}

void exprparser_flush_and_delete_buffer(void *myscanner, void *bp)
{
    yy_flush_buffer((YY_BUFFER_STATE) bp, (yyscan_t) myscanner);
    yy_delete_buffer((YY_BUFFER_STATE) bp, (yyscan_t) myscanner);
}

void exprparser_free(void *myscanner)
{
    exprparser_lex_destroy((yyscan_t) myscanner);
}

void exprparser_set_start_condition(void *myscanner, int condition)
{
    struct yyguts_t *yyg = (struct yyguts_t*) myscanner;
    BEGIN condition;
}




