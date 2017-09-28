//
//  symparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef symparser_h
#define symparser_h

#include "llll_commons.h"

#ifdef CONFIGURATION_Development
#define parserpost post
//#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif

void symbol_parse(char *buf, t_llll **ll, t_llll_stack *stack, long *depth);


#endif /* symparser_h */
