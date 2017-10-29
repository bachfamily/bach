//
//  alterparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef alterparser_h
#define alterparser_h

#include "parsers_commons.h"
#include "llll_commons.h"

#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif


typedef struct _alterparser_wrapper {
    void *scanner;
    t_shortRational *a;
} t_alterparser_wrapper;

void alterparser_new(t_alterparser_wrapper *apw);
t_shortRational alterparser_scan_string(t_alterparser_wrapper *apw, char *buf);
void alterparser_free(t_alterparser_wrapper *apw);

#endif /* alterparser_h */
