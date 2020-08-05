/*
 *  exprparser.h
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

#ifndef exprparser_h
#define exprparser_h

#include "parsers/bach_parser.hpp"
#include "foundation/llll_commons.h"
#include "math/lexpr.h"

#ifndef parserpost
#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif
#endif

typedef struct _exprparser_data {
    t_lexpr_lexeme *lexeme;
    short *numvars;
    long subs_count;
    const char **substitutions;
    char **offending;
    method lastfunction;
} t_exprparser_data;

class t_exprParser : public t_parser {
private:
    void *buffer;
public:
    t_exprParser(t_exprparser_data *data);
    void setBuffer(char *buf);
    void setStartCondition(int condition);
    void reset();
    int lex();
};


#endif /* exprparser_h */
