%option noyywrap nodefault reentrant bison-bridge
%option header-file="symparser.lex.h"
%option outfile="symparser.c"
%option prefix="symparser_"
SEPARATOR ([ \t\n\(\)\[\]\{\}])
INTEGER ([+-]?[0-9]+)
FLOAT ([+-]?(((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+)))
RATIONAL ({INTEGER}[/]{INTEGER})
NOTENAME ([a-g]|[A-G])
ACCIDENTAL ([#bxdq]+)

%{
	#define BACH_MAX
	#ifdef BACH_MAX
    #include "llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #include "symparser.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
    
    #include "symparser.tab.h"
    #define YY_DECL int yylex \
            (YYSTYPE *yylval_param, yyscan_t yyscanner)
%}

%%

\( {
    parserpost(" lex: PUSH\n");
    return PUSH;
}

\) {
    parserpost(" lex: POPPE\n");
    return POP;
}

{INTEGER} {
    parserpost(" lex: INTEGER %d\n", atoi(yytext));
    yylval->l = atol(yytext);
    return LONG;
}

{RATIONAL} {
    char *textend;
	long num = strtol(yytext, &textend, 10);
	long den = strtol(textend + 1, NULL, 10);
    parserpost(" lex: RATIONAL %ld / %ld\n", num, den);
    yylval->r = t_rational(num, den);
    return RAT;
}

{FLOAT} {
    parserpost(" lex: DOUBLE %lf\n", atof(yytext));
    yylval->d = atof(yytext);
    return DOUBLE;
}

{NOTENAME}{ACCIDENTAL}?{INTEGER} {
	long degree = t_pitch::text2degree(*yytext);
	char *pos = yytext + 1;
    t_shortRational alter = t_pitch::text2alter(&pos);
	long octave = strtol(pos, NULL, 10);
	parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
	yylval->p = t_pitch(degree, alter, octave);
	return PITCH;
}

{NOTENAME}{INTEGER}{ACCIDENTAL} {
	long degree = t_pitch::text2degree(*yytext);
	char *acc;
	long octave = strtol(yytext + 1, &acc, 10);
	t_shortRational alter = t_pitch::text2alter(&acc);
	parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
	yylval->p = t_pitch(degree, alter, octave);
	return PITCH;
}

{NOTENAME}{INTEGER}[+|-][0-9]+t {
	long degree = t_pitch::text2degree(*yytext);
	char *next;
	long octave = strtol(yytext + 1, &next, 10);
	t_shortRational alter = t_shortRational(strtol(next, NULL, 10), 1);
	parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
	yylval->p = t_pitch(degree, alter, octave);
	return PITCH;
}

{NOTENAME}{INTEGER}[+|-][0-9]+[/]{INTEGER}t {
	long degree = t_pitch::text2degree(*yytext);
	char *next;
	long octave = strtol(yytext + 1, &next, 10);
	t_shortRational alter = t_shortRational(strtol(next, &next, 10), 1);
	alter /= strtol(next + 1, NULL, 10);
	parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
	yylval->p = t_pitch(degree, alter, octave);
	return PITCH;
}

\`.* {
    parserpost(" lex: BACKTICKED ELEMENT %s\n", yytext + 1);
    yylval->sym = gensym(yytext + 1);
    return SYMBOL;
}

\"\" {
    parserpost(" lex: QUOTED EMPTY SYMBOL %s\n", yytext);
    yylval->sym = gensym("");
    return SYMBOL;
}

["]("\\\""|[^"` \t\n\r\f\v])("\\\""|[^" \t\n\r\f\v])*[^\\ \t\n\r\f\v]["] {
    parserpost(" lex: QUOTED NON-WHITESPACED SYMBOL %s\n", yytext);
    yylval->sym = gensym(yytext);
    return SYMBOL;
}

["]("\\\""|[^"])*[^\\]["] {
    parserpost(" lex: QUOTED WHITESPACED SYMBOL %s\n", yytext);
    yylval->sym = gensym(yytext);
    return SYMBOL;
}

"null" {
    parserpost(" lex: null\n");
    return BACHNULL;
}

"nil" {
    parserpost(" lex: nil\n");
    return BACHNIL;
}

[^\(\)]* {
    parserpost(" lex: SYMBOL %s\n", yytext);
    yylval->sym = gensym(yytext);
    return SYMBOL;
}

[^ \t\n\,\;]*[ \t\n\,\;].* {
    parserpost(" lex: SYMBOL %s\n", yytext);
    yylval->sym = gensym(yytext);
    return SYMBOL;
}

%%

#ifndef BACH_MAX
int main(int argc, char **argv)
{
	yylex();
}
#endif

YY_BUFFER_STATE symparser_scan_string(yyscan_t myscanner, char *buf)
{
    YY_BUFFER_STATE bp = yy_scan_string(buf, myscanner);
    yy_switch_to_buffer(bp, myscanner);
    return bp;
}

void symparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp)
{
    yy_flush_buffer(bp, myscanner);
    yy_delete_buffer(bp, myscanner);
}
