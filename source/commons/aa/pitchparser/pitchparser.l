%option noyywrap nodefault reentrant
%option noyyalloc noyyrealloc noyyfree
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
    *p = t_parser::eatPitchAsNameAccInt(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", p->degree(), p->alter().num(), p->alter().den(), p->octave());
    return P_MORE;
}

^[-+]?{NOTENAME}[-+]?{UINT}{ACCIDENTAL} {
    *p = t_parser::eatPitchAsNameIntAcc(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", p->degree(), p->alter().num(), p->alter().den(), p->octave());
    return P_MORE;
}

^[-+]?{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}+t {
    *p = t_parser::eatPitchAsNameAccIntIntT(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", p->degree(), p->alter().num(), p->alter().den(), p->octave());
    return P_MORE;
}

^[-+]?{NOTENAME}{ACCIDENTAL}?[-+]?{UINT}[-+]{UINT}[/][-+]?{UINT}t {
    *p = t_parser::eatPitchAsNameAccIntRatT(yytext);
    parserpost(" lex: NOTE: degree %ld, alter %ld/%ld, octave %ld\n", p->degree(), p->alter().num(), p->alter().den(), p->octave());
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


t_pitchParser::t_pitchParser() : t_parser()
{
    
    p = new(t_pitch);
    
    struct yyguts_t dummy_yyguts;
    pitchparser_set_extra(p, &dummy_yyguts);
    
    setPtr(sizeof(struct yyguts_t));
    setBasePtr();
    
    reset();
    
    pitchparser_set_extra (p, (yyscan_t) this);
    
}


void t_pitchParser::reset()
{
    t_parser::reset();
    //memset(this,0x00,sizeof(struct yyguts_t));
    yy_init_globals ((yyscan_t) this);
    
}

t_pitch t_pitchParser::parse(char *buf)
{
    parserpost("pitchparser: parsing %s", buf);
    YY_BUFFER_STATE bp = yy_scan_string(buf, (yyscan_t) this);
    yy_switch_to_buffer(bp, (yyscan_t) this);
    switch (yylex((yyscan_t) this)) {
        case P_ERROR:
        case P_END:
            *p = t_pitch::NaP;
            break;
        case P_MORE:
            if (yylex((yyscan_t) this) != P_END)
                *p = t_pitch::NaP;
            break;
    }
    yy_flush_buffer(bp, (yyscan_t) this);
    yy_delete_buffer(bp, (yyscan_t) this);
    return *p;
}



void *pitchparser_alloc(size_t bytes, void *yyscanner)
{
    void *b = ((t_pitchParser *) yyscanner)->getPtr(bytes);
    parserpost(" pitchparser_alloc: %d bytes requested, returning %p", bytes, b);
    return b;
}

void *pitchparser_realloc(void *ptr,size_t bytes, void *yyscanner)
{
    parserpost(" pitchparser_realloc: %d bytes requested for pointer %p, returning %p", bytes, ptr, ptr);
    return ptr;
}

void pitchparser_free(void *ptr,void *yyscanner)
{
    return;
}
