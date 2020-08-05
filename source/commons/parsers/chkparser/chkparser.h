/*
 *  chkparser.h
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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

#ifndef chkparser_h
#define chkparser_h

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


class t_chkParser : public t_parser {
private:
    
public:
    t_chkParser();
    
    // returns a #e_hatom_types indicating the inferred type for the text
    long parse(const char *buf);
    void reset();
    t_bool wantsBacktick(t_symbol *s);
    
    t_symbol *addQuoteIfNeeded(t_symbol *sym);
};

#endif /* chkparser_h */
