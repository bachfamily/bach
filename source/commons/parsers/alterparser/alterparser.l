%{
    /*
     *  alterparser.l
     *
     * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

%option noyywrap nodefault reentrant
%option noyyalloc noyyrealloc noyyfree
%option never-interactive
%option outfile="alterparser.c"
%option prefix="alterparser_"


SEPARATOR ([ \t\n\r\(\)\[\]\{\}])
UINT ([0-9]+)
UFLOAT (((([0-9]*\.[0-9]+)|([0-9]+\.))([eE][-+]?[0-9]+)?)|([0-9]+[eE][-+]?[0-9]+))
URAT ({UINT}[/][+-]?{UINT})
NOTENAME ([a-g]|[A-G])
ACCIDENTAL ([n#bxdq+-\^v]+)

%{
    #ifndef BACH_MAX
    #define BACH_MAX
    #endif
    #ifdef BACH_MAX
    #include "foundation/llllobj.h"
    #include "ext_common.h"
    #include "ext_globalsymbol.h"
    #include "parsers/alterparser/alterparser.h"
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
    
    #define YY_NO_UNISTD_H
    
%}

%option extra-type = "t_shortRational *"

%%

%{
    t_shortRational *a = yyextra;
%}

^{ACCIDENTAL} {
    char *next = yytext;
    *a = t_pitch::text2alter_legacy(&next);
    parserpost(" lex: ALTER: %ld/%ld\n", a->num(), a->den());
    return A_MORE;
}

{ACCIDENTAL}[-+]{UINT}+t {
    char *next = yytext;
    *a = t_pitch::text2alter_legacy(&next);
    *a += t_shortRational(strtol(next, NULL, 10), 1);
    parserpost(" lex: ALTER: %ld/%ld\n", a->num(), a->den());
    return A_MORE;
}

{ACCIDENTAL}[-+]{UINT}[/][-+]?{UINT}t {
    char *next = yytext;
    *a = t_pitch::text2alter_legacy(&next);
    *a += t_shortRational(strtol(next, &next, 10), strtol(next + 1, NULL, 10));
    parserpost(" lex: ALTER: %ld/%ld\n", a->num(), a->den());
    return A_MORE;
}

[-+]?{UINT}+t {
    *a = t_shortRational(strtol(yytext, NULL, 10), 1);
    parserpost(" lex: ALTER: %ld/%ld\n", a->num(), a->den());
    return A_MORE;
}

[-+]{UINT}[/][-+]?{UINT}t {
    char *next = yytext;
    *a = t_shortRational(strtol(next, &next, 10), strtol(next + 1, NULL, 10));
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

t_alterParser::t_alterParser() : t_parser()
{
    
    a = new(t_shortRational);
    
    struct yyguts_t dummy_yyguts;
    alterparser_set_extra(a, &dummy_yyguts);
    
    setPtr(sizeof(struct yyguts_t));
    setBasePtr();
    
    reset();
    alterparser_set_extra (a, (yyscan_t) this);
}


void t_alterParser::reset()
{
    t_parser::reset();
    //memset(this,0x00,sizeof(struct yyguts_t));
    yy_init_globals ((yyscan_t) this);
    
}

t_shortRational t_alterParser::parse(char *buf)
{
    parserpost("alterparser: parsing %s", buf);
    YY_BUFFER_STATE bp = yy_scan_string(buf, (yyscan_t) this);
    yy_switch_to_buffer(bp, (yyscan_t) this);
    switch (yylex((yyscan_t) this)) {
        case A_ERROR:
        case A_END:
            *a = t_pitch::illegal;
            break;
        case A_MORE:
            if (yylex((yyscan_t) this) != A_END)
                *a = t_pitch::illegal;
            break;
    }
    yy_flush_buffer(bp, (yyscan_t) this);
    yy_delete_buffer(bp, (yyscan_t) this);
    return *a;
}




void *alterparser_alloc(size_t bytes, void *yyscanner)
{
    void *b = ((t_alterParser *) yyscanner)->getPtr(bytes);
    parserpost(" alterparser_alloc: %d bytes requested, returning %p", bytes, b);
    return b;
}

void *alterparser_realloc(void *ptr,size_t bytes, void *yyscanner)
{
    parserpost(" alterparser_realloc: %d bytes requested for pointer %p, returning %p", bytes, ptr, ptr);
    return ptr;
}

void alterparser_free(void *ptr,void *yyscanner)
{
    return;
}
