//
//  exprparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef exprparser_h
#define exprparser_h

#include "parsers_commons.h"
#include "llll_commons.h"
#include "lexpr.h"

#ifdef CONFIGURATION_Development
#define parserpost post
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


void *exprparser_new(t_exprparser_data *data);
void *exprparser_scan_string(void *myscanner, char *buf);
void exprparser_flush_and_delete_buffer(void *myscanner, void *bp);
void exprparser_free(void *myscanner);
void exprparser_set_start_condition(void *myscanner, int condition);


#endif /* exprparser_h */
