//
//  alterparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef alterparser_h
#define alterparser_h

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


class t_alterParser : public t_parser {
private:
    t_shortRational *a;
public:
    t_alterParser();
    ~t_alterParser() { delete a; };
    t_shortRational parse(char *buf);
    void reset();
};


#endif /* alterparser_h */
