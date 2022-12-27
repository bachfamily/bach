/*
 *  pitchparser.h
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef pitchparser_h
#define pitchparser_h

#include "parsers/bach_parser.hpp"
#include "foundation/llll_commons.h"

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
