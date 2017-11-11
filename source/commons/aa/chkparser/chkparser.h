//
//  symparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef chkparser_h
#define chkparser_h

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


class t_chkParser : public t_parser {
private:
    
    
public:
    t_chkParser();
    
    
    // returns a #e_hatom_types indicating the inferred type for the text
    // tct is a pointer to #e_typecheck_traits
    long parse(char *buf);
    void reset();
    t_bool wantsBacktick(t_symbol *s);
    
    t_symbol *addQuoteIfNeeded(t_symbol *sym);
};

#endif /* chkparser_h */
