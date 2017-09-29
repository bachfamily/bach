%option noyywrap nodefault reentrant
%option header-file="pitchparser.lex.h"
%option outfile="pitchparser.c"
%option prefix="pitchparser_"


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
    #include "pitchparser.h"
    #include "lexpr.h"
    #include "llll_math.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
%}

%option extra-type = "t_pitch *"

%%

%{
    t_pitch *p = yyextra;
%}

^{NOTENAME}{ACCIDENTAL}?[-+]?{UINT} {
    long degree = t_pitch::text2degree(*yytext);
    char *next = yytext + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
    long octave = strtol(next, NULL, 10);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    p->set(degree, alter, octave);
    return P_MORE;
}

^{NOTENAME}[-+]?{UINT}{ACCIDENTAL} {
    long degree = t_pitch::text2degree(*yytext);
    char *acc;
    long octave = strtol(yytext + 1, &acc, 10);
    t_shortRational alter = t_pitch::text2alter(&acc);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    p->set(degree, alter, octave);
    return P_MORE;
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}+t {
    long degree = t_pitch::text2degree(*yytext);
    char *next = yytext + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
    long octave = strtol(next, &next, 10);
    alter += t_shortRational(strtol(next, NULL, 10), 1);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    p->set(degree, alter, octave);
    return P_MORE;
}

{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}[/][-+]?{UINT}t {
    long degree = t_pitch::text2degree(*yytext);
    char *next = yytext + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
    long octave = strtol(next, &next, 10);
    alter += t_shortRational(strtol(next, &next, 10),  strtol(next + 1, NULL, 10));
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    p->set(degree, alter, octave);
    return P_MORE;
}

. {
    parserpost(" lex: unrecognized character %s", yytext);
    return P_ERROR;
}

\n {
    parserpost(" lex: unrecognized character \\n", yytext);
    return P_ERROR;
}

%%

#ifndef BACH_MAX
int main(int argc, char **argv)
{
    yylex();
}
#endif

void pitchparser_new(t_pitchparser_wrapper *ppw)
{
    ppw->p = new(t_pitch);
    yylex_init_extra(ppw->p, (yyscan_t *) &ppw->scanner);
}

t_pitch pitchparser_scan_string(t_pitchparser_wrapper *ppw, char *buf)
{
    t_pitch p;
    yyscan_t scanner = (yyscan_t) ppw->scanner;
    YY_BUFFER_STATE bp = yy_scan_string(buf, scanner);
    yy_switch_to_buffer(bp, scanner);
    switch (yylex(scanner)) {
        case P_ERROR:
        case P_END:
            p = t_pitch::NaP;
            break;
        case P_MORE:
            p = *ppw->p;
            if (yylex(scanner) != P_END)
                p = t_pitch::NaP;
            break;
    }
    yy_flush_buffer(bp, scanner);
    yy_delete_buffer(bp, scanner);
    return p;
}

void pitchparser_free(t_pitchparser_wrapper *ppw)
{
    delete ppw->p;
    pitchparser_lex_destroy(ppw->scanner);
}




