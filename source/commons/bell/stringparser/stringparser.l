%{
    /*
     *  stringparser.l
     *
     * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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

%option noyywrap nodefault yylineno reentrant bison-bridge
%option never-interactive
%option outfile="stringparser.c"
%option header-file="stringparser.lex.h"
%option prefix="stringparser_"

SEPARATOR           ([[:space:]\(\)\[\]+\-*/%!=~_<>;,.:\\\x01])
SEPARATOR_STRICT    ([[:space:]\)\]+\-*/%!=~_<>;,:\\\x01])
NO_SPACES ([^ \t\n\r\f\v\x01])
RAT_LITERAL ({INTEGER}[/]{INTEGER})
UINT ([0-9]+)
UFLOAT_LEADINGDIGIT (((([0-9]+\.[0-9]+)|([0-9]+\.))(([eE]([-+]?)[0-9]+)?))|([0-9]+[eE]([-+]?)[0-9]+))
UFLOAT_LEADINGDOT (\.[0-9]+)
URAT ({UINT}[/][+-]?{UINT})
NOTENAME ([a-g]|[A-G])
ACCIDENTAL ([#bxdq\^v]+)
FLOAT ([+-]?(((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+)))
SYMBOL_LITERAL [^$[:space:]\r\f\v\(\)\[\]+\-*/][^[:space:]\r\f\v\(\)\[\]+\-*/]*+

%s NOUNARY_NOARGS NOUNARY_ARGS UNARY_ARGS
%x IFILE LINECOMMENT BLOCKCOMMENT

%{
    
    
    #ifdef CONFIGURATION_Development
    //#define code_dev_post post  // UNCOMMENT THIS TO TURN ON VERBOSE LEXING
    #endif
    
    #ifndef code_dev_post
    #define code_dev_post(...) ((void) 0)
    #endif
    
    //#define BACH_MAX
    #ifdef BACH_MAX
    #include "foundation/llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #else
    #include <stdio.h>
    #define code_dev_post printf
    #endif
    
    #include "parsers/bach_parser.hpp"
    #include "bell/ast.hpp"
    #include "stringparser.h"
    
    #include "stringparser_tab_nolines.h"
    
    #define YY_DECL int yylex \
    (YYSTYPE *yylval_param, yyscan_t yyscanner, struct _parseParams *params)
    
    #define YY_NO_UNISTD_H



    int stringparser_newfile(yyscan_t myscanner, char *s);
    int stringparser_popfile(yyscan_t myscanner);
    
    #define UNARY_NOARGS (INITIAL)
    
    #define YY_USER_ACTION { yycolumn += yyleng; code_dev_post("yycolumn = %d", yycolumn); }
    
    struct t_bufstack {
        YY_BUFFER_STATE bs; /* saved buffer */
        char *name; /* name of this file */
        char *text;
        int *state;
        int line;
    };
    

    t_lexparams::t_lexparams() {
        bufstack = (t_bufstack*) bach_newptr(256 * sizeof(t_bufstack));
        this_bs = bufstack;
        this_bs->text = nullptr;
        this_bs->name = nullptr;
        state = 0;
    }
    
    t_lexparams::~t_lexparams() {
        bach_freeptr(bufstack);
    }
    
    int t_lexparams::setState(int s) {
        return state = s;
    }
    
    int t_lexparams::getState() {
        return state;
    }

    
%}

%option extra-type = "t_lexparams*"

%%



%{
    t_lexparams *lexparams = yyextra;
%}

<NOUNARY_NOARGS,INITIAL>{
    \(    {
        code_dev_post("lex: OPEN\n");
        BEGIN lexparams->setState(UNARY_NOARGS);
        // was: BEGIN (*((*bs)->state) = UNARY_NOARGS);
        return OPEN;
    }
}


<UNARY_ARGS,NOUNARY_ARGS>{
    \( {
        code_dev_post("lex: START PARAMETERS");
        BEGIN lexparams->setState(UNARY_NOARGS);
        return STARTPARAMS;
    }
}

\) {
    code_dev_post("lex: CLOSED\n");
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return CLOSEDROUND;
}

\[ {
    code_dev_post("lex: PUSH\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return PUSH;
}

\] {
    code_dev_post("lex: POP\n");
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return POP;
}

"+=" {
    code_dev_post("lex: OPERATOR +=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return APLUS;
}

"-=" {
    code_dev_post("lex: OPERATOR -=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return AMINUS;
}

"->" {
    code_dev_post("lex: FUNCTION DEFINITION\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return FUNDEF;
}

"-^" {
    code_dev_post("lex: LIFT\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LIFT;
}

<INITIAL,UNARY_ARGS>\+/{NO_SPACES} {
    code_dev_post("lex: OPERATOR UNARY +\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return UPLUS;
}

<INITIAL,UNARY_ARGS>\-/{NO_SPACES} {
    code_dev_post("lex: OPERATOR UNARY -\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return UMINUS;
}

"+" {
    code_dev_post("lex: OPERATOR BINARY +\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return PLUS;
}

"-" {
    code_dev_post("lex: OPERATOR BINARY -\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return MINUS;
}

"*=" {
    code_dev_post("lex: OPERATOR *=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ATIMES;
}

"*" {
    code_dev_post("lex: OPERATOR *\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return TIMES;
}

"**=" {
    code_dev_post("lex: OPERATOR **=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return APOWOP;
}

"**" {
    code_dev_post("lex: OPERATOR **\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return POWOP;
}

"/=" {
    code_dev_post("lex: OPERATOR /=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ADIV;
}

"/" {
    code_dev_post("lex: OPERATOR /\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return DIV;
}

"//=" {
    code_dev_post("lex: OPERATOR //\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ADIVDIV;
}

"//" {
    code_dev_post("lex: OPERATOR //\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return DIVDIV;
}

"%=" {
    code_dev_post("lex: OPERATOR %=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return AREM;
}

"%" {
    code_dev_post("lex: OPERATOR %\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return REM;
}

"=" {
    code_dev_post("lex: ASSIGNMENT\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ASSIGN;
}

"==" {
    code_dev_post("lex: OPERATOR ==\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return EQUAL;
}

"!" {
    code_dev_post("lex: OPERATOR !\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LOGNOT;
}

"~" {
    code_dev_post("lex: OPERATOR !\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return BITNOT;
}

"!=" {
    code_dev_post("lex: OPERATOR !=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return NEQ;
}

"<" {
    code_dev_post("lex: OPERATOR <\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LT;
}


">" {
    code_dev_post("lex: OPERATOR >\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return GT;
}

"<=" {
    code_dev_post("lex: OPERATOR <=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LEQ;
}


">=" {
    code_dev_post("lex: OPERATOR >=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return GEQ;
}

"&=" {
    code_dev_post("lex: OPERATOR &=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ABITAND;
}

"&" {
    code_dev_post("lex: OPERATOR &\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return BITAND;
}

"^=" {
    code_dev_post("lex: OPERATOR ^=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ABITXOR;
}

"^" {
    code_dev_post("lex: OPERATOR ^\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return BITXOR;
}

"|=" {
    code_dev_post("lex: OPERATOR |=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ABITOR;
}

"|" {
    code_dev_post("lex: OPERATOR |\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return BITOR;
}

"&&=" {
    code_dev_post("lex: OPERATOR &&=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ALOGAND;
}

"&&" {
    code_dev_post("lex: OPERATOR &&\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LOGAND;
}

"&&&=" {
    code_dev_post("lex: OPERATOR &&&=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ALOGANDEXT;
}

"&&&" {
    code_dev_post("lex: OPERATOR &&&\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LOGANDEXT;
}

"^^=" {
    code_dev_post("lex: OPERATOR ^^=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ALOGXOR;
}

"^^" {
    code_dev_post("lex: OPERATOR ^^\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LOGXOR;
}

"||=" {
    code_dev_post("lex: OPERATOR ||=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ALOGOR;
}

"||" {
    code_dev_post("lex: OPERATOR ||\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LOGOR;
}

"|||=" {
    code_dev_post("lex: OPERATOR |||=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ALOGOREXT;
}

"|||" {
    code_dev_post("lex: OPERATOR |||\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LOGOREXT;
}

"<<=" {
    code_dev_post("lex: OPERATOR <<=\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ALSHIFT;
}

"<<" {
    code_dev_post("lex: OPERATOR <<\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return LSHIFT;
}

">>=" {
    code_dev_post("lex: OPERATOR >>\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ARSHIFT;
}

">>" {
    code_dev_post("lex: OPERATOR >>\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return RSHIFT;
}

"<...>" {
    code_dev_post("lex: ELLIPSIS\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ELLIPSIS;
}

":=" {
    code_dev_post("lex: ANTHOP\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ANTHOP;
}

"::" {
    code_dev_post("lex: PICKOP\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return PICKOP;
}

":" {
    code_dev_post("lex: NTHOP\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return NTHOP;
}

".=" {
    code_dev_post("lex: ASSIGN APPLY\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return AAPPLY;
}

"_=" {
    code_dev_post("lex: ASSIGN CONCAT\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ACONCAT;
}

"!_=" {
    code_dev_post("lex: ASSIGN REVERSE CONCAT\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ARCONCAT;
}

"..." {
    code_dev_post("lex: RANGE\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return RANGE;
}

":*" {
    code_dev_post("lex: REPEAT\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return REPEAT;
}

"." {
    code_dev_post("lex: ACCESS\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return APPLY;
}

"include"[ \t\n]*\( {
    code_dev_post("lex: include directive");
    BEGIN IFILE;
}

<IFILE>[^\)]+ {
    int c;
    while ((c = yyinput(yyscanner)) && c != ')') ;
    code_dev_post("lex: switching to file %s", yytext);
    if (stringparser_newfile(yyscanner, yytext))
        yyterminate();
    BEGIN lexparams->getState();
}

<<EOF>> {
    if (stringparser_popfile(yyscanner))
        yyterminate();
}

"##"|"#!" {
    code_dev_post("lex: start line comment");
    BEGIN LINECOMMENT;
}

<LINECOMMENT>[^\n\r\f]* {
    int c;
    //while ((c = yyinput(yyscanner)) && c != '\r' && c != '\n' && c != '\f') ;
    code_dev_post("lex: line comment: %s", yytext);
    //BEGIN UNARY_NOARGS;
}

<LINECOMMENT>[\n\r\f] {
    code_dev_post("lex: line comment ends", yytext);
    BEGIN UNARY_NOARGS;
}

"#(" {
    code_dev_post("lex: start block comment");
    BEGIN BLOCKCOMMENT;
}

<BLOCKCOMMENT>[^\)]* {
    code_dev_post("lex: block comment [^\\)]* : %s", yytext);
}

<BLOCKCOMMENT>")"[^\)\#]* {
    code_dev_post("lex: block comment \")\"[^\\#]+ : )%s", yytext);
}

<BLOCKCOMMENT>")#" {
    code_dev_post("lex: end block comment");
    BEGIN lexparams->getState();
}


"if"/{SEPARATOR} {
    code_dev_post("lex: IF_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return IF_KW;
}

"then"/{SEPARATOR} {
    code_dev_post("lex: THEN_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return THEN_KW;
}

"else"/{SEPARATOR} {
    code_dev_post("lex: ELSE_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return ELSE_KW;
}

"for"/{SEPARATOR} {
    code_dev_post("lex: FOR_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return FOR_KW;
}

"in"/{SEPARATOR} {
    code_dev_post("lex: IN_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return IN_KW;
}

"with"/{SEPARATOR} {
    code_dev_post("lex: IN_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return WITH_KW;
}

"as"/{SEPARATOR} {
    code_dev_post("lex: AS_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return AS_KW;
}

"while"/{SEPARATOR} {
    code_dev_post("lex: WHILE_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return WHILE_KW;
}

"do"/{SEPARATOR} {
    code_dev_post("lex: DO_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return DO_KW;
}

"collect"/{SEPARATOR} {
    code_dev_post("lex: COLLECT_KW\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return COLLECT_KW;
}

("$args")/{SEPARATOR} {
    code_dev_post("lex: BIF %s", yytext);
    yylval->sym = gensym(yytext);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return BIF;
}

("length"|"depth"|"is"|"nth"|"sort"|"contains"|"rev"|"rot"|"trans"|"flat"|"slice"|"left"|"right"|"subs"|"insert"|"find"|"finditems"|"findaddrs"|"scramble"|"minmax"|"perm"|"comb"|"cartesianprod"|"wrap"|"group"|"delace"|"thin"|"classify"|"union"|"intersection"|"symdiff"|"diff"|"primeser"|"arithmser"|"geomser"|"map"|"reduce"|"apply")/{SEPARATOR} {
    code_dev_post("lex: BIF %s", yytext);
    yylval->sym = gensym(yytext);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return BIF;
}

("cos"|"sin"|"tan"|"exp"|"log"|"acos"|"asin"|"atan"|"cosh"|"sinh"|"tanh"|"exp2"|"log2"|"sqrt"|"ceil"|"acosh"|"asinh"|"atanh"|"log10"|"floor"|"round"|"trunc"|"fmod"|"atan2"|"hypot"|"pow"|"int"|"rat"|"num"|"den"|"abs"|"sgn"|"float"|"pitch"|"degree"|"octave"|"alter"|"cents"|"pow"|"mod"|"min"|"max"|"random"|"bessel"|"approx"|"enharm"|"makepitch"|"makepitchsc"|"mc2f"|"f2mc"|"minimum"|"maximum")/{SEPARATOR} {
    code_dev_post("lex: BIF %s", yytext);
    yylval->sym = gensym(yytext);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return BIF;
}

("outlet"|"inlet")/{SEPARATOR} {
    code_dev_post("lex: BIF %s", yytext);
    yylval->sym = gensym(yytext);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return BIF;
}

("#+"|"#-"|"#u-"|"#*"|"#/"|"#//"|"#%"|"#=="|"#!="|"#<"|"#>"|"#<="|"#>="|"#&"|"#^"|"#|"|"#&&"|"#^^"|"#||"|"#&&&"|"#|||"|"#<<"|"#>>")/{SEPARATOR} {
    code_dev_post("lex: BIF %s", yytext);
    yylval->sym = gensym(yytext);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return BIF;
}

("directout"|"directin"|"print")/{SEPARATOR} {
    code_dev_post("lex: OWNED FUNCTION %s", yytext);
    yylval->sym = gensym(yytext);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return OF;
}

"keep"/{SEPARATOR} {
    code_dev_post("lex: KEEP");
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    return KEEP;
}

"unkeep"/{SEPARATOR} {
    code_dev_post("lex: UNKEEP");
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    return UNKEEP;
}

"init"/{SEPARATOR} {
    code_dev_post("lex: INIT");
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    return INIT;
}

";"|"\\;" {
    code_dev_post("lex: ;");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return NULLIFY;
}

","|"\\," {
    code_dev_post("lex: ,");
    BEGIN lexparams->setState(UNARY_NOARGS);
    return COMMA;
}

"null"/{SEPARATOR} {
    code_dev_post("lex: null");
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return BACHNULL;
}

"nil"/{SEPARATOR} {
    code_dev_post("lex: nil");
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return BACHNIL;
}

{UINT}/{SEPARATOR} {
    code_dev_post("lex: INTEGER %d\n", atoi(yytext));
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->l = atoi(yytext);
    return LONG_LITERAL;
}

"$argcount"/{SEPARATOR} {
    code_dev_post("lex: ARGCOUNT\n");
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    return ARGCOUNT;
}

"pi"/{SEPARATOR} {
    code_dev_post("lex: PI\n", atof(yytext));
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->d = M_PI;
    return DOUBLE_LITERAL;
}

{UFLOAT_LEADINGDIGIT}/{SEPARATOR_STRICT} {
    code_dev_post("lex: DOUBLE_LITERAL %lf\n", atof(yytext));
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->d = atof(yytext);
    return DOUBLE_LITERAL;
}

<INITIAL,UNARY_ARGS>{UFLOAT_LEADINGDOT}/{SEPARATOR_STRICT} {
    code_dev_post("lex: DOUBLE_LITERAL %lf\n", atof(yytext));
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->d = atof(yytext);
    return DOUBLE_LITERAL;
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}/{SEPARATOR} {
    code_dev_post("lex: PITCH_LITERAL %s\n", yytext);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->p = t_parser::eatPitchAsNameAccInt(yytext);
    return PITCH_LITERAL;
}

{NOTENAME}[-+]?{UINT}{ACCIDENTAL}/{SEPARATOR} {
    code_dev_post("lex: PITCH_LITERAL %s\n", yytext);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->p = t_parser::eatPitchAsNameIntAcc(yytext);
    return PITCH_LITERAL;
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}t/{SEPARATOR} {
    code_dev_post("lex: PITCH_LITERAL %s\n", yytext);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->p = t_parser::eatPitchAsNameAccIntIntT(yytext);
    return PITCH_LITERAL;
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}"/"{UINT}t/{SEPARATOR} {
    code_dev_post("lex: PITCH_LITERAL %s\n", yytext);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->p = t_parser::eatPitchAsNameAccIntRatT(yytext);
    return PITCH_LITERAL;
}

\\$[lx][0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return INLET;
}

$[lx][0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 2);
    code_dev_post("lex: INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return INLET;
}

\\$i[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: INT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return INTINLET;
}

$i[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 2);
    code_dev_post("lex: INT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return INTINLET;
}

\\$r[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: RAT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return RATINLET;
}

$r[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 2);
    code_dev_post("lex: RAT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return RATINLET;
}

\\$f[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: FLOAT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return FLOATINLET;
}

$f[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 2);
    code_dev_post("lex: FLOAT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return FLOATINLET;
}

\\$p[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: FLOAT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return PITCHINLET;
}

$p[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 2);
    code_dev_post("lex: FLOAT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return PITCHINLET;
}

\\$o[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: OUTLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return OUTLET;
}

$o[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 2);
    code_dev_post("lex: OUTLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return OUTLET;
}

\\$dx[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 4);
    code_dev_post("lex: DIRECT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return DIRINLET;
}

$dx[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: DIRECT INLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return DIRINLET;
}


\\$do[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 4);
    code_dev_post("lex: DIRECT OUTLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return DIROUTLET;
}

$do[0-9]+/{SEPARATOR} {
    yylval->l = atoi(yytext + 3);
    code_dev_post("lex: DIRECT OUTLET VARIABLE %d\n", yylval->l);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return DIROUTLET;
}

$[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?/{SEPARATOR} {
    code_dev_post("lex: LOCAL VARIABLE %s\n", yytext + 1);
    yylval->sym = gensym(yytext + 1);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return LOCALVAR;
}

\\$[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?/{SEPARATOR} {
    code_dev_post("lex: LOCAL VARIABLE %s\n", yytext + 2);
    yylval->sym = gensym(yytext + 2);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return LOCALVAR;
}

\@[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?/{SEPARATOR} {
    code_dev_post("lex: NAMED FUNCTION PARAMETER %s\n", yytext + 1);
    yylval->sym = gensym(yytext + 1);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    return NAMEDPARAM;
}

#[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?/{SEPARATOR} {
    code_dev_post("lex: PATCHER VARIABLE %s\n", yytext + 1);
    yylval->sym = gensym(yytext + 1);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return PATCHERVAR;
}

[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9])?/{SEPARATOR} {
    code_dev_post("lex: GLOBAL VARIABLE %s\n", yytext);
    yylval->sym = gensym(yytext);
    BEGIN lexparams->setState(NOUNARY_ARGS);
    return GLOBALVAR;
}

\`{NO_SPACES}+/{SEPARATOR} {
    code_dev_post("lex: BACKTICKED SYMBOL_LITERAL %s\n", yytext + 1);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->sym = gensym(yytext + 1);
    return SYMBOL_LITERAL;
}

["]("\\\""|[^"])*[^\\]["]/{SEPARATOR} {
    code_dev_post("lex: DOUBLE-QUOTED SYMBOL_LITERAL %s\n", yytext);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    char *s = (char *) bach_newptr(yyleng - 1);
    strncpy_zero(s, yytext + 1, yyleng - 1);
    for (char *c = s; *c; c++) {
        if (*c == 1) {
            *c = ' ';
            (*params->codeac)++;
        }
    }
    yylval->sym = gensym(s);
    bach_freeptr(s);
    return SYMBOL_LITERAL;
}

[']("\\\'"|[^'])*[^\\][']/{SEPARATOR} {
    code_dev_post("lex: SINGLE-QUOTED SYMBOL_LITERAL %s\n", yytext);
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    char *s = (char *) bach_newptr(yyleng - 1);
    strncpy_zero(s, yytext + 1, yyleng - 1);
    for (char *c = s; *c; c++) {
        if (*c == 1) {
            *c = ' ';
            (*params->codeac)++;
        }
    }
    yylval->sym = gensym(s);
    bach_freeptr(s);
    return SYMBOL_LITERAL;
}

"\"\""/{SEPARATOR} {
    code_dev_post("lex: EMPTY DOUBLE-QUOTED SYMBOL_LITERAL\n");
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->sym = gensym("");
    return SYMBOL_LITERAL;
}

"''"/{SEPARATOR} {
    code_dev_post("lex: EMPTY SINGLE-QUOTED SYMBOL_LITERAL\n");
    BEGIN lexparams->setState(NOUNARY_NOARGS);
    yylval->sym = gensym("");
    return SYMBOL_LITERAL;
}


\n {
    code_dev_post("lex: Newline: %d\n", yylineno);
    code_dev_post("lex: that is: %d\n", yyget_lineno(yyscanner));
    BEGIN lexparams->setState(UNARY_NOARGS);
}

[[:space:]] {
    code_dev_post("lex: Whitespace\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
}

\x01 {
    code_dev_post("lex: Atom Separator\n");
    BEGIN lexparams->setState(UNARY_NOARGS);
    (*params->codeac)++;
}

<*>. {
    code_dev_post("lex: UNRECOGNIZED CHARACTER %s (%d)\n", yytext, *yytext);
    BEGIN lexparams->setState(UNARY_NOARGS);
    return UNRECOGNIZED;
}

%%

YY_BUFFER_STATE stringparser_scan_string(yyscan_t myscanner, const char *buf)
{
    YY_BUFFER_STATE bp;
    bp = yy_scan_string(buf, myscanner);
    yy_switch_to_buffer(bp, myscanner);
    t_lexparams *lexparams = yyget_extra(myscanner);
    lexparams->this_bs->bs = bp;
    yyset_lineno(1, myscanner);
    return bp;
}

void stringparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp)
{
    yy_flush_buffer(bp, myscanner);
    yy_delete_buffer(bp, myscanner);
}

int stringparser_newfile(yyscan_t myscanner, char *s)
{
    t_fourcc filetype[] = {'TEXT', 'BELL'};
    t_fourcc outtype;
    char *filename = (char *) bach_newptr(MAX_PATH_CHARS + 1);
    short path;
    
    strncpy_zero(filename, s, MAX_PATH_CHARS);    // must copy symbol before calling locatefile_extended
    if (locatefile_extended(filename, &path, &outtype, filetype, 2)) { // non-zero: not found
        object_error(nullptr, "include(%s): file not found", s);
        return -1;
    }
    
    t_filehandle fh;
    char **texthandle;
    if (path_opensysfile(filename, path, &fh, READ_PERM)) {
        object_error(nullptr, "error opening %s", filename);
        return -1;
    }
    // allocate some empty memory to receive text
    texthandle = sysmem_newhandle(0);
    sysfile_readtextfile(fh, texthandle, 0, TEXT_NULL_TERMINATE);     // see flags explanation below
    size_t size = sysmem_handlesize(texthandle);
    code_dev_post("the file has %ld characters", size);
    sysfile_close(fh);
    
    char *text = (char *) bach_newptr((size + 1) * sizeof(char));
    strncpy_zero(text, *texthandle, size);
    sysmem_freehandle(texthandle);
    if (!isspace(text[size - 2])) {
        text[size - 1] = ' ';
        text[size] = 0;
    }
    t_lexparams *lexparams = yyget_extra(myscanner);
    lexparams->this_bs->line = yyget_lineno(myscanner);
    (lexparams->this_bs)++;
    //yyset_lineno(1, myscanner);
    lexparams->this_bs->name = filename;
    lexparams->this_bs->text = text;
    lexparams->this_bs->bs = stringparser_scan_string(myscanner, text);
    lexparams->files.insert({path, filename});
    return 0;
}

int stringparser_popfile(yyscan_t myscanner)
{
    t_lexparams *lexparams = yyget_extra(myscanner);
    
    stringparser_flush_and_delete_buffer(myscanner, lexparams->this_bs->bs);
    if (!lexparams->this_bs->name)
        return 1;
    bach_freeptr(lexparams->this_bs->name);
    bach_freeptr(lexparams->this_bs->text);
    --(lexparams->this_bs);
    yy_switch_to_buffer(lexparams->this_bs->bs, myscanner);
    yyset_lineno(lexparams->this_bs->line, myscanner);
    return 0;
}


int stringparser_error(yyscan_t myscanner, t_parseParams *params, const char *s)
{
    params->ast = nullptr;
    int line = yyget_lineno(myscanner);
    if (line) {
        std::string errorString = s;
        for (int i = 0; i < (sizeof(tokenNames) / sizeof(t_tokenNames)); i++) {
            size_t pos = errorString.find(tokenNames[i].original);
            if (pos != std::string::npos) {
                errorString.replace(pos, tokenNames[i].original.size(), tokenNames[i].replacement);
            }
        }
        object_error((t_object *) params->owner, "Line %d: %s", yyget_lineno(myscanner), errorString.c_str());
    } else {
        object_error((t_object *) params->owner, "Unexpected end of code");
    }
    cpost("error: %s\n", s);
    
    return 0;
}









