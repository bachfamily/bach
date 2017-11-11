//
//  pitchparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef pitchparser_h
#define pitchparser_h

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

class t_pitchParser : public t_parser {
private:
    t_pitch *p;
public:
    t_pitchParser();
    ~t_pitchParser() { delete p; };
    t_pitch parse(char *buf);
    void reset();
};

#endif /* pitchparser_h */
