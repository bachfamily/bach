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
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
    
    typedef enum {
        P_END = 0,
        P_MORE,
        P_ERROR
    } e_pitchparser_rv;
%}

%option extra-type = "t_pitch *"

%%

%{
    t_pitch *p = yyextra;
%}

^[-+]?{NOTENAME}{ACCIDENTAL}?[-+]?{UINT} {
    *p = parse_pitch_as_name_acc_int(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", degree, alter.num(), alter.den(), octave);
    return P_MORE;
}

^[-+]?{NOTENAME}[-+]?{UINT}{ACCIDENTAL} {
    *p = parse_pitch_as_name_int_acc(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
    return P_MORE;
}

^[-+]?{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}+t {
    *p = parse_pitch_as_name_acc_int_int_t(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
    return P_MORE;
}

^{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}[/][-+]?{UINT}t {
    *p = parse_pitch_as_name_acc_int_rat_t(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", yylval->p.degree(), yylval->p.alter().num(), yylval->p.alter().den(), yylval->p.octave());
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




