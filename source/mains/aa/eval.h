//
//  eval.h
//  bach
//
//  Created by Andrea Agostini on 30/03/18.
//
//

#ifndef eval_h
#define eval_h

#include <unordered_map>
#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "bach_codableobj.hpp"

typedef struct _eval
{
    t_codableobj n_ob;
    
    long n_proxies;
    void **n_proxy;
    long n_in;
    
    t_atom_long n_dataInlets;
    t_atom_long n_dataOutlets;
    t_atom_long n_directInlets;
    t_atom_long n_directOutlets;

    short n_path;
} t_eval;

#endif /* eval_h */
