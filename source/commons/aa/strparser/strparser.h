//
//  symparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef strparser_h
#define strparser_h

#include "bach_parser.hpp"
#include "llll_commons.h"

#ifndef parserpost
#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif
#endif


class t_strParser : public t_parser {
private:
    t_bool big;
public:
    t_strParser(t_bool bigString = false);
    void parse(const char *buf, t_llll **ll, t_llll_stack *stack, long *depth);
    void reset();
    t_bool isBig() { return big; }
};

#endif /* strparser_h */
