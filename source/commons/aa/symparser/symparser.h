//
//  symparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef symparser_h
#define symparser_h

#include "bach_parser.hpp"
#include "llll_commons.h"

#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif

class t_symParser : public t_parser {
public:
    t_symParser();
    void parse(char *buf, t_llll **ll, t_llll_stack *stack, long *depth);
};


#endif /* symparser_h */
