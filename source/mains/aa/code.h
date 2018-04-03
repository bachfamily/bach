//
//  code.h
//  bach
//
//  Created by Andrea Agostini on 30/03/18.
//
//

#ifndef code_h
#define code_h


#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

class t_mainFunction;
class t_ownedFunction;

typedef struct _code
{
    t_llllobj_object n_ob;
    long n_proxies;
    void **n_proxy;
    long n_in;
    t_mainFunction *n_main;
    t_ownedFunction *n_directin;
    t_ownedFunction *n_directout;
    t_atom_long n_inlets;
    t_atom_long n_outlets;
    char *n_text;
    t_bach_atomic_lock n_lock;
    
    char *text;
    t_object *n_editor;
    
} t_code;

#endif /* code_h */
