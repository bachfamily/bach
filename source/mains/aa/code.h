//
//  code.h
//  bach
//
//  Created by Andrea Agostini on 30/03/18.
//
//

#ifndef code_h
#define code_h

#include <unordered_map>
#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "bach_codableobj.hpp"

typedef struct _code
{
    t_codableobj n_ob;
    
    long n_proxies;
    void **n_proxy;
    long n_in;
    
    t_atom_long n_dataInlets;
    t_atom_long n_dataOutlets;
    t_atom_long n_directInlets;
    t_atom_long n_directOutlets;
    
    t_atom_long n_dummyEmbed;
    t_atom_long n_dummyAuto;

    short n_path;
} t_code;

#endif /* code_h */
