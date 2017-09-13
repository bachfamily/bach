%option noyywrap nodefault

SEPARATOR ([ \t\n\(\)\[\]\{\}+\-*/])
INTEGER ([0-9]+)
FLOAT (((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]*[eE][-+]?[0-9]*))
SYMBOL [^$ \t\n\r\f\v\(\)\[\]\{\}+\-*/][^ \t\n\r\f\v\(\)\[\]\{\}+\-*/]*+

%s NOUNARY

%{
    #include "llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
%}

%%

\(	{
    post("OPEN PAREN\n");
    BEGIN INITIAL;
}

\) {
    post("CLOSED PAREN\n");
    BEGIN NOUNARY;
}

\[	{
    post("OPEN CROTCHET\n");
    BEGIN INITIAL;
}

\] {
    post("CLOSED CROTCHET\n");
    BEGIN NOUNARY;
}

\{	{
    post("OPEN BRACE\n");
    BEGIN INITIAL;
}

\} {
    post("CLOSED BRACE\n");
    BEGIN NOUNARY;
}

<INITIAL>\+/[^ \t\n\r\f\v] {
    post("OPERATOR UNARY +\n");
    BEGIN INITIAL;
}

<INITIAL>\-/[^ \t\n\r\f\v] {
    post("OPERATOR UNARY -\n");
    BEGIN INITIAL;
}

"+" {
    post("OPERATOR BINARY +\n");
    BEGIN INITIAL;
}

"-" {
    post("OPERATOR BINARY -\n");
    BEGIN INITIAL;
}

"*" {
    post("OPERATOR *\n");
    BEGIN INITIAL;
}

"**" {
    post("OPERATOR **\n");
    BEGIN INITIAL;
}

"/" {
    post("OPERATOR /\n");
    BEGIN INITIAL;
}

"//" {
    post("OPERATOR //\n");
    BEGIN INITIAL;
}

(if)|(else) {
    post("KEYWORD %s\n", yytext);
    BEGIN INITIAL; 
}

$[0-9]+/{SEPARATOR} {
    post("INLET VARIABLE %d\n", atoi(yytext + 1));
    BEGIN NOUNARY;
}

$[_0-9a-zA-Z]+/{SEPARATOR} {
    post("IDENTIFIER %s\n", yytext + 1);
    BEGIN NOUNARY;
}

$/{SEPARATOR} {
    post("BAD EMPTY IDENTIFIER\n");
    BEGIN NOUNARY;
}

$[^ \t\n\(\)]+/{SEPARATOR} {
    post("BAD IDENTIFIER %s\n", yytext + 1);
}

{INTEGER}/{SEPARATOR} {
    post("INTEGER %d\n", atoi(yytext));
    BEGIN NOUNARY;
}

{FLOAT}/{SEPARATOR} {
    post("FLOAT %f\n", atof(yytext));
    BEGIN NOUNARY;
}

\'[^ \t\n\r\f\v]+/{SEPARATOR} {
post("BACKTICKED ELEMENT %s\n", yytext + 1);
BEGIN NOUNARY;
}

["]("\\\""|[^" \t\n\r\f\v])*[^\\ \t\n\r\f\v]["]/{SEPARATOR} {
    printf("QUOTED NON-WHITESPACED SYMBOL %s\n", yytext);
    BEGIN NOUNARY;
}

["]("\\\""|[^"])*[^\\]["]/{SEPARATOR} {
    post("QUOTED WHITESPACED SYMBOL %s\n", yytext);
    BEGIN NOUNARY;
}

{SYMBOL}/{SEPARATOR} {
    post("SYMBOL %s\n", yytext);
    BEGIN NOUNARY;
}

[ \t\n]		{
    BEGIN INITIAL;
}

. {
    post("UNRECOGNIZED CHARACTER %s\n", yytext);
    BEGIN INITIAL;
}

%%


void flexlex(char *buf)
{
    YY_BUFFER_STATE bp;
    bp = yy_scan_string(buf);
    yy_switch_to_buffer(bp);
    yylex();
    yy_flush_buffer(bp);
    yy_delete_buffer(bp);
}
