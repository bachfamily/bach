//
//  symparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef strparser_h
#define strparser_h

#include "parsers_commons.h"
#include "llll_commons.h"

#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif

void string_parse(char *buf, t_llll **ll, t_llll_stack *stack, long *depth);


#endif /* strparser_h */
