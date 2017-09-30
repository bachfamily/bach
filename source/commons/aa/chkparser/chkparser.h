//
//  symparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef chkparser_h
#define chkparser_h

#include "llll_commons.h"

#ifdef CONFIGURATION_Development
//#define parserpost post
#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif

typedef enum _typecheck_traits {
    E_TT_PAREN = 0x01, // contains at least one paren
    E_TT_RESERVED = 0x02, // contains whitespace, comma, semicolon
    E_TT_BACKTICK = 0x04, // begins with a backtick
} e_typecheck_traits;

// returns an #e_hatom_types indicating the inferred type for the text
// tct is a pointer to #e_typecheck_traits
long typecheck_parse(char *buf, long *tct);

#endif /* chkparser_h */
