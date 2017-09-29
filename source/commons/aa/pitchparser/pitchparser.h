//
//  pitchparser.h
//  bach
//
//  Created by Andrea Agostini on 29/08/17.
//
//

#ifndef pitchparser_h
#define pitchparser_h

#include "llll_commons.h"

#ifdef CONFIGURATION_Development
#define parserpost post
//#define parserpost(...) ((void) 0)
#else
#define parserpost(...) ((void) 0)
#endif

typedef enum {
    P_END = 0,
    P_MORE,
    P_ERROR
} e_pitchparser_rv;

typedef struct _pitchparser_wrapper {
    void *scanner;
    t_pitch *p;
} t_pitchparser_wrapper;

void pitchparser_new(t_pitchparser_wrapper *ppw);
t_pitch pitchparser_scan_string(t_pitchparser_wrapper *ppw, char *buf);
void pitchparser_free(t_pitchparser_wrapper *ppw);

#endif /* pitchparser_h */
