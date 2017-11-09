//
//  exprparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef exprparser_h
#define exprparser_h

#include "bach_parser.hpp"
#include "llll_commons.h"
#include "lexpr.h"

#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif

typedef struct _exprparser_data {
    t_lexpr_lexeme *lexeme;
    short *numvars;
    long subs_count;
    const char **substitutions;
    char **offending;
    method lastfunction;
} t_exprparser_data;

class t_exprParser : public t_parser {
private:
    void *buffer;
public:
    t_exprParser(t_exprparser_data *data);
    void setBuffer(char *buf);
    void setStartCondition(int condition);
    void reset();
    int lex();
};


#endif /* exprparser_h */
