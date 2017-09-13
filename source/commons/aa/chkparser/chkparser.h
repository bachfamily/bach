//
//  symparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef chkparser_h
#define chkparser_h

#include "llll_commons.h"

#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif

// returns true if the symbol has to be quoted
t_bool typecheck_parse(char *buf);

#endif /* chkparser_h */
