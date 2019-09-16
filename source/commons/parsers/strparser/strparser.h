/*
 *  strparser.h
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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

#ifndef strparser_h
#define strparser_h

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


class t_strParser : public t_parser {
private:
    t_bool big;
    long startCondition;
public:
    t_strParser(t_bool bigString = false, long ignore = 0);
    void parse(const char *buf, t_llll **ll, t_llll_stack *stack, long *depth);
    void reset();
    t_bool isBig() { return big; }
    void makeBig() { big = 1; }
    long getStartCondition() { return startCondition; }
    void setStartCondition(long s) { startCondition = s; }
};

#endif /* strparser_h */
