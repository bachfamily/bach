%option noyywrap nodefault reentrant
%option header-file="alterparser.lex.h"
%option outfile="alterparser.c"
%option prefix="alterparser_"


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
    #include "alterparser.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
    
    typedef enum {
        A_END = 0,
        A_MORE,
        A_ERROR
    } e_alterparser_rv;
%}

%option extra-type = "t_shortRational *"

%%

%{
    t_shortRational *a = yyextra;
%}

^{ACCIDENTAL} {
    char *next = yytext;
    *a = t_pitch::text2alter(&next);
    parserpost(" lex: ALTER: %ld/%ld\n", a->num(), a->den());
    return A_MORE;
}

{ACCIDENTAL}?[-+]{UINT}+t {
    char *next = yytext;
    *a = t_pitch::text2alter(&next);
    *a += t_shortRational(strtol(next, NULL, 10), 1);
    parserpost(" lex: ALTER: %ld/%ld\n", a->num(), a->den());
    return A_MORE;
}

{ACCIDENTAL}?[-+]{UINT}[/][-+]?{UINT}t {
    char *next = yytext;
    *a = t_pitch::text2alter(&next);
    *a += t_shortRational(strtol(next, &next, 10), strtol(next + 1, NULL, 10));
    parserpost(" lex: ALTER: %ld/%ld\n", a->num(), a->den());
    return A_MORE;
}

. {
    parserpost(" lex: unrecognized character %s", yytext);
    return A_ERROR;
}

\n {
    parserpost(" lex: unrecognized character \\n", yytext);
    return A_ERROR;
}

%%

#ifndef BACH_MAX
int main(int argc, char **argv)
{
    yylex();
}
#endif

void alterparser_new(t_alterparser_wrapper *apw)
{
    apw->a = new(t_shortRational);
    yylex_init_extra(apw->a, (yyscan_t *) &apw->scanner);
}

t_shortRational alterparser_scan_string(t_alterparser_wrapper *apw, char *buf)
{
    t_shortRational a;
    yyscan_t scanner = (yyscan_t) apw->scanner;
    YY_BUFFER_STATE bp = yy_scan_string(buf, scanner);
    yy_switch_to_buffer(bp, scanner);
    switch (yylex(scanner)) {
        case A_ERROR:
        case A_END:
            a = t_shortRational(0, 0);
            break;
        case A_MORE:
            a = *apw->a;
            if (yylex(scanner) != A_END)
                a = t_shortRational(0, 0);
            break;
    }
    yy_flush_buffer(bp, scanner);
    yy_delete_buffer(bp, scanner);
    return a;
}

void alterparser_free(t_alterparser_wrapper *apw)
{
    delete apw->a;
    alterparser_lex_destroy(apw->scanner);
}




