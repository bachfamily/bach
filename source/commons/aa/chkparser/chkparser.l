%option noyywrap nodefault reentrant
%option outfile="chkparser.c"
%option prefix="chkparser_"

RESERVED ([ \t\n\\,\;)
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
    #include "chkparser.h"
    #else
    #include <stdio.h>
    #include <ctype.h>
    #define parserpost printf
    #endif
%}

%option extra-type="long *"

%%

%{
    long *tct = yyextra;
%}

^` {
    parserpost("typecheck: starting backtick");
    *tct |= E_TT_BACKTICK;
    return H_SYM; // because backtick wins, if we're here we don't need to scan any longer
}

\(|\) {
    parserpost("typecheck: paren");
    *tct |= E_TT_PAREN;
}

^{INTEGER} {
    parserpost("typecheck: long");
    return H_LONG;
}

^{FLOAT} {
    parserpost("typecheck: double");
    return H_DOUBLE;
}

^{RATIONAL} {
    parserpost("typecheck: rational");
    return H_RAT;
}

^{NOTENAME}{ACCIDENTAL}?{INTEGER} {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

^{NOTENAME}{INTEGER}{ACCIDENTAL} {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

^{NOTENAME}{ACCIDENTAL}?{INTEGER}[+|-][0-9]+t {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

^{NOTENAME}{ACCIDENTAL}?{INTEGER}[+|-][0-9]+[/]{INTEGER}t {
    parserpost("typecheck: pitch");
    return H_PITCH;
}

[ \t\n\,\;] {
    parserpost("typecheck: reserved char");
    *tct |= E_TT_RESERVED;
    return H_SYM; // if we're here, it means that the first char was not a backtick, in which case reserved chars win and we can return
}

[^\(\) \t\n] {
    parserpost("easy stuff");
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

long typecheck_parse(char *buf, long *tct)
{
    yyscan_t myscanner;
    YY_BUFFER_STATE bp;
    *tct = 0;
    chkparser_lex_init_extra(tct, &myscanner);
    bp = yy_scan_string(buf, myscanner);
    long t = yylex(myscanner);
    if (t == H_NOTHING)
        t = H_SYM;
    chkparser_flush_and_delete_buffer(myscanner, bp);
    chkparser_lex_destroy(myscanner);
    return t;
}

YY_BUFFER_STATE chkparser_scan_string(yyscan_t myscanner, char *buf)
{
    YY_BUFFER_STATE bp = yy_scan_string(buf, myscanner);
    yy_switch_to_buffer(bp, myscanner);
    return bp;
}

