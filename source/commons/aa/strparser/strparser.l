%option noyywrap nodefault reentrant bison-bridge
%option noyyalloc noyyrealloc noyyfree
%option header-file="strparser.lex.h"
%option outfile="strparser.c"
%option prefix="strparser_"
SEPARATOR ([ \t\n\(\)\[\]\{\}])
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
    #include "strparser.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
    
    #include "strparser.tab.h"
    #define YY_DECL int yylex \
            (YYSTYPE *yylval_param, yyscan_t yyscanner)
%}

%%

\( {
    parserpost(" lex: PUSH\n");
    return PUSH;
}

\) {
    parserpost(" lex: POP\n");
    return POP;
}

{INTEGER} {
    parserpost(" lex: INTEGER %d\n", atoi(yytext));
    yylval->l = atol(yytext);
    return LONG;
}

{RATIONAL} {
    yylval->r = t_parser::eatRational(yytext);
    parserpost(" lex: RATIONAL %ld / %ld\n", yylval->r.num(), yylval->r.den());
    return RAT;
}

{FLOAT} {
    yylval->d = atof(yytext);
    parserpost(" lex: DOUBLE %lf\n", yylval->d);
    return DOUBLE;
}

[-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER} {
    yylval->p = t_parser::eatPitchAsNameAccInt(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
    return PITCH;
}

[-+]?{NOTENAME}{INTEGER}{ACCIDENTAL} {
    yylval->p = t_parser::eatPitchAsNameIntAcc(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
	return PITCH;
}

[-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER}[+|-][0-9]+t {
    yylval->p = t_parser::eatPitchAsNameAccIntIntT(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
    return PITCH;
}

[-+]?{NOTENAME}{ACCIDENTAL}?{INTEGER}[+|-][0-9]+[/]{INTEGER}t {
    yylval->p = t_parser::eatPitchAsNameAccIntRatT(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
    return PITCH;
}

\`[^ \t\n\r\f\v]+ {
    parserpost(" lex: BACKTICKED ELEMENT %s\n", yytext + 1);
    yylval->sym = gensym(yytext + 1);
    return SYMBOL;
}

["]("\\\""|[^" \t\n\r\f\v])*[^\\ \t\n\r\f\v]["] {
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

[ \t\n] {
	parserpost(" lex: Whitespace\n");
}

[^\(\) \t\n]* {
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


t_strParser::t_strParser() : t_parser()
{
    setPtr(sizeof(struct yyguts_t));
    setBasePtr();
    
    /* By setting to 0xAA, we expose bugs in yy_init_globals. Leave at 0x00 for releases. */
    memset(this,0x00,sizeof(struct yyguts_t));
    
    return yy_init_globals ((yyscan_t) this);
}

YY_BUFFER_STATE strparser_scan_string(yyscan_t myscanner, char *buf)
{
    YY_BUFFER_STATE bp = yy_scan_string(buf, myscanner);
    yy_switch_to_buffer(bp, myscanner);
    return bp;
}

void strparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp)
{
    yy_flush_buffer(bp, myscanner);
    yy_delete_buffer(bp, myscanner);
}



void *strparser_alloc(size_t bytes, void *yyscanner)
{
    void *b = ((t_strParser *) yyscanner)->getPtr(bytes);
    post(" strparser_alloc: %d bytes requested, returning %p", bytes, b);
    return b;
}

void *strparser_realloc(void *ptr,size_t bytes, void *yyscanner)
{
    post(" strparser_realloc: %d bytes requested for pointer %p, returning %p", bytes, ptr, ptr);
    return ptr;
}

void strparser_free(void *ptr,void *yyscanner)
{
    return;
}

