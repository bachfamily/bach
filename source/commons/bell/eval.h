/*
 *  eval.h
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "bell/bach_codableobj.hpp"

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
    
    t_llll *n_triggers;
    long n_triggerInlets[256];
    long n_triggerInletsCount;
    
} t_eval;

#endif /* eval_h */
