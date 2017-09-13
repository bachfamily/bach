%option noyywrap nodefault

SEPARATOR ([ \t\n\(\)\[\]\{\}+\-*/\:])
INTEGER ([+-]?[0-9]+)
FLOAT ([+-]?(((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+)))
SYMBOL [^$ \t\n\r\f\v\(\)\[\]\{\}+\-*/][^ \t\n\r\f\v\(\)\[\]\{\}+\-*/]*+

%s NOUNARY

%{
	//#define BACH_MAX
	#ifdef BACH_MAX
    #include "llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #else
    #include <stdio.h>
    #define post printf
    #endif
    
    #include "scrispast.h"
    
    #include "scrispsimp.tab.h"
    
    static YY_BUFFER_STATE bp;
%}

%%


\[	{
    post("lex: OPEN\n");
    BEGIN INITIAL;
    return OPEN;
}

\] {
    post("lex: CLOSED\n");
    BEGIN NOUNARY;
    return CLOSED;
}

\( {
    post("lex: PUSH\n");
    BEGIN INITIAL;
    return PUSH;
}

\) {
    post("lex: POP\n");
    BEGIN NOUNARY;
    return POP;
}

\{ {
    post("lex: START PARAMETERS");
    BEGIN INITIAL;
    return STARTPARAMS;
}

\} {
    post("lex: END PARAMETERS");
    BEGIN INITIAL;
    return ENDPARAMS;
}

<INITIAL>\+/[^ \t\n\r\f\v] {
    post("lex: OPERATOR UNARY +\n");
    BEGIN INITIAL;
    return UPLUS;
}

<INITIAL>\-/[^ \t\n\r\f\v] {
    post("lex: OPERATOR UNARY -\n");
    BEGIN INITIAL;
    return UMINUS;
}

"+" {
    post("lex: OPERATOR BINARY +\n");
    BEGIN INITIAL;
    return PLUS;
}

"-" {
    post("lex: OPERATOR BINARY -\n");
    BEGIN INITIAL;
    return MINUS;
}

"*" {
    post("lex: OPERATOR *\n");
    BEGIN INITIAL;
    return TIMES;
}

"/" {
    post("lex: OPERATOR /\n");
    BEGIN INITIAL;
    return DIV;
}


":=" {
    post("lex: ASSIGNMENT\n");
    BEGIN INITIAL;
    return ASSIGN;
}

"==" {
    post("lex: OPERATOR ==\n");
    BEGIN INITIAL;
    return EQUAL;
}

"!=" {
    post("lex: OPERATOR !=\n");
    BEGIN INITIAL;
    return NEQ;
}

"<" {
    post("lex: OPERATOR <\n");
    BEGIN INITIAL;
    return LT;
}


">" {
    post("lex: OPERATOR >\n");
    BEGIN INITIAL;
    return GT;
}

"<=" {
    post("lex: OPERATOR <=\n");
    BEGIN INITIAL;
    return LEQ;
}


">=" {
    post("lex: OPERATOR >=\n");
    BEGIN INITIAL;
    return GEQ;
}

"&&" {
    post("lex: OPERATOR &&\n");
    BEGIN INITIAL;
    return LOGAND;
}

"&&&" {
    post("lex: OPERATOR &&&\n");
    BEGIN INITIAL;
    return LOGANDEXT;
}

"||" {
    post("lex: OPERATOR ||\n");
    BEGIN INITIAL;
    return LOGOR;
}

"|||" {
    post("lex: OPERATOR |||\n");
    BEGIN INITIAL;
    return LOGOREXT;
}

"if"/{SEPARATOR} {
    post("lex: IF\n");
    BEGIN INITIAL;
    return IF;
}

"then"/{SEPARATOR} {
    post("lex: THEN\n");
    BEGIN INITIAL;
    return THEN;
}

"else"/{SEPARATOR} {
    post("lex: ELSE\n");
    BEGIN INITIAL;
    return ELSE;
}

"length"/{SEPARATOR} {
    post("lex: BIF length\n");
    yylval.bif = (method) scrisp_length;
    return BIF1;
}

"depth"/{SEPARATOR} {
    post("lex: BIF depth\n");
    yylval.bif = (method) scrisp_depth;
    return BIF1;
}

":" {
    post("lex: :");
    BEGIN INITIAL;
    return SEQ;
}

\\$l[0-9]+/{SEPARATOR} {
    post("lex: INLET VARIABLE %d\n", atoi(yytext + 3));
    yylval.i = atoi(yytext + 3);
    BEGIN NOUNARY;
    return INLET;
}

$l[0-9]+/{SEPARATOR} {
    post("lex: INLET VARIABLE %d\n", atoi(yytext + 2));
    yylval.i = atoi(yytext + 2);
    BEGIN NOUNARY;
    return INLET;
}

\\$[a-zA-Z_][a-zA-Z_0-9]*/{SEPARATOR} {
    post("lex: GLOBAL VARIABLE %s\n", yytext + 1);
    yylval.str = (char *) bach_newptr((strlen(yytext)) * sizeof(char));
    strcpy(yylval.str, yytext + 1);
    BEGIN NOUNARY;
    return GLOBALVAR;
}

$[a-zA-Z_][a-zA-Z_0-9]*/{SEPARATOR} {
    post("lex: GLOBAL VARIABLE %s\n", yytext);
    yylval.str = (char *) bach_newptr((strlen(yytext) + 1) * sizeof(char));
    strcpy(yylval.str, yytext);
    BEGIN INITIAL;
    return GLOBALVAR;
}

{INTEGER}/{SEPARATOR} {
    post("lex: INTEGER %d\n", atoi(yytext));
    BEGIN NOUNARY;
    yylval.i = atoi(yytext);
    return INT;
}

{FLOAT}/{SEPARATOR} {
    post("lex: DOUBLE %lf\n", atof(yytext));
    BEGIN NOUNARY;
    yylval.d = atof(yytext);
    return DOUBLE;
}

\'[^ \t\n\r\f\v]+/{SEPARATOR} {
    post("lex: BACKTICKED ELEMENT %s\n", yytext + 1);
    BEGIN NOUNARY;
    yylval.sym = gensym(yytext + 1);
    return SYMBOL;
}

["]("\\\""|[^" \t\n\r\f\v])*[^\\ \t\n\r\f\v]["]/{SEPARATOR} {
    post("lex: QUOTED NON-WHITESPACED SYMBOL %s\n", yytext);
    BEGIN NOUNARY;
    yylval.sym = gensym(yytext);
    return SYMBOL;
}

["]("\\\""|[^"])*[^\\]["]/{SEPARATOR} {
    post("lex: QUOTED WHITESPACED SYMBOL %s\n", yytext);
    BEGIN NOUNARY;
    yylval.sym = gensym(yytext);
    return SYMBOL;
}

"null"/{SEPARATOR} {
    post("lex: null");
    BEGIN INITIAL;
    return BACHNULL;
}

"nil"/{SEPARATOR} {
    post("lex: nil");
    BEGIN INITIAL;
    return BACHNIL;
}

[ \t\n] {
	post("lex: Whitespace\n");
    BEGIN INITIAL;
}

. {
    post("lex: UNRECOGNIZED CHARACTER %s\n", yytext);
    BEGIN INITIAL;
}

%%

void scan_string(char *buf) 
{
    bp = yy_scan_string(buf);
    yy_switch_to_buffer(bp);
}

void delete_buffer(void)
{
    yy_flush_buffer(bp);
    yy_delete_buffer(bp);
}
