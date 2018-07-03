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

class t_mainFunction;
class t_ownedFunction;

typedef struct _code
{
    t_llllobj_object n_ob;
    long n_proxies;
    void **n_proxy;
    long n_in;
    t_mainFunction *n_main;

    char *n_text;
    t_bach_atomic_lock n_lock;
    t_atom_long n_auto;
    
    t_atom_long n_dataInlets;
    t_atom_long n_dataOutlets;
    t_atom_long n_directInlets;
    t_atom_long n_directOutlets;
    std::unordered_map<std::string, t_ownedFunction *> n_ofTable;

    t_object *n_editor;
    
} t_code;

#endif /* code_h */
