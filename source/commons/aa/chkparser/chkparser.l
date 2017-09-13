%option noyywrap nodefault reentrant
%option outfile="chkparser.c"
%option prefix="chkparser_"

RESERVED ([ \t\n\\,\;)
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
    #include "chkparser.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif


    typedef struct _typecheck_res {
        t_bool t_reserved;
        t_bool t_wishesbt;
    } t_typecheck_res;
%}

%option extra-type="t_typecheck_res *"

%%

%{
    t_typecheck_res *tcr = yyextra;
%}

^` {
    parserpost("typecheck: starting backtick");
    tcr->t_wishesbt = true;
}

\(|\) {
    parserpost("typecheck: paren");
    tcr->t_wishesbt = true;
}

{INTEGER}|{RATIONAL}|{FLOAT} {
    parserpost("typecheck: number");
    tcr->t_wishesbt = true;
}

{NOTENAME}{ACCIDENTAL}?{INTEGER} {
    parserpost("typecheck: pitch");
    tcr->t_wishesbt = true;
}

{NOTENAME}{INTEGER}{ACCIDENTAL} {
    parserpost("typecheck: pitch");
    tcr->t_wishesbt = true;
}

{NOTENAME}{INTEGER}[+|-][0-9]+t {
    parserpost("typecheck: pitch");
    tcr->t_wishesbt = true;
}

{NOTENAME}{INTEGER}[+|-][0-9]+[/]{INTEGER}t {
    parserpost("typecheck: pitch");
    tcr->t_wishesbt = true;
}

[ \t\n\,\;] {
    parserpost("typecheck: reserved char");
    tcr->t_reserved = true;
    return 0;
}

[^\(\) \t\n]* {
    parserpost(" typecheck: symbol");
}


%%

#ifndef BACH_MAX
int main(int argc, char **argv)
{
	yylex();
}
#endif

void chkparser_flush_and_delete_buffer(yyscan_t myscanner, YY_BUFFER_STATE bp)
{
    yy_flush_buffer(bp, myscanner);
    yy_delete_buffer(bp, myscanner);
}

t_bool typecheck_parse(char *buf)
{
    yyscan_t myscanner;
    YY_BUFFER_STATE bp;
    t_typecheck_res res = {false, false};
    chkparser_lex_init_extra(&res, &myscanner);
    bp = yy_scan_string(buf, myscanner);
    yylex(myscanner);
    chkparser_flush_and_delete_buffer(myscanner, bp);
    chkparser_lex_destroy(myscanner);
    return res.t_wishesbt && !res.t_reserved;
}

YY_BUFFER_STATE chkparser_scan_string(yyscan_t myscanner, char *buf)
{
    YY_BUFFER_STATE bp = yy_scan_string(buf, myscanner);
    yy_switch_to_buffer(bp, myscanner);
    return bp;
}

