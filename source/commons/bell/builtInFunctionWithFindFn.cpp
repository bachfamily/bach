/*
 *  builtInFunctionWithFindFn.cpp
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

#include "bell/builtInFunctionWithFindFn.hpp"

/*
long t_builtInFunctionWithFindFn::lambdaDefault(t_fnData *lambdaData, t_llll *ll)
{
    return llll_eq_ignoretype(ll, lambdaData->context.argv[1]);
}
*/
long t_builtInFunctionWithFindFn::lambdaFunction(t_fnData *lambdaData, t_llll *ll)
{
    t_function *fn = lambdaData->func;
    t_execEnv *context = &lambdaData->context;
    context->argv[1] = ll;
    context->resetFnNamedArgs(fn, 2);
    t_llll *resLl = fn->call(lambdaData->context);
    long res = llll_istrue(resLl);
    return res;
}

t_fnFind::t_fnFind() : t_builtInFunctionWithFindFn("find")
{
    setArgument("llll");
    setArgument("items", llll_get());
    setArgument("function", llll_get());
    setArgument("size", 0l);
    setArgument("depth");
    setArgument("minidx", 1);
    setArgument("maxidx", -1);
    setArgument("idxreject", 0l);
    setArgument("depthreject", 0l);
    setArgument("maxcount", 0l);
    setArgument("unwrap", 0l);
    setArgument("depthpolicy", 0l);
    setArgument("recursive", 0l);
    setArgument("mindepth", 1);
    setArgument("maxdepth", -1);
}

t_llll* t_fnFind::call(t_execEnv &context)
{
    t_llll *ll = context.argv[1];
    t_llll *items = llll_clone(context.argv[2]); // may be nullptr as well
    t_function *fn = context.argv[3]->l_size ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    t_atom_long size = llll_getlong(context.argv[4]);
    t_atom_long minidx = llll_getlong(context.argv[6]);
    t_atom_long maxidx = llll_getlong(context.argv[7]);
    t_atom_long idxreject = llll_getlong(context.argv[8]);
    t_atom_long depthreject = llll_getlong(context.argv[9]);
    t_atom_long maxcount = llll_getlong(context.argv[10]);
    t_atom_long unwrap = llll_getlong(context.argv[11]);
    t_atom_long depthpolicy = llll_getlong(context.argv[12]);
    t_atom_long recursive = llll_getlong(context.argv[13]);

    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[5], context.argv[14], context.argv[15], &mindepth, &maxdepth);
    
    if (size == 0) {
        size = items->l_size;
        if (size == 0)
            size = 1;
    }
    
    t_llll *found, *addresses;
    
    if (fn) {
        addresses = llll_get();
        t_fnData lambdaData(fn, &context, this, items);
            
        found = llll_find(ll, addresses, size, mindepth, maxdepth, minidx, maxidx, idxreject, depthreject, maxcount, recursive, unwrap, depthpolicy, 0, (find_fn) lambdaFunction, &lambdaData);
    } else {
        addresses = llll_get();
        found = llll_find(ll, addresses, size, mindepth, maxdepth, minidx, maxidx, idxreject, depthreject, maxcount, recursive, unwrap, depthpolicy, 0, (find_fn) llll_eq_ignoretype, items);
    }
    
    t_llll *rv = llll_get();
    
    llll_appendllll(rv, found ? found : llll_get());
    llll_appendllll(rv, addresses ? addresses : llll_get());
    return rv;
}


///////////////


t_fnFinditems::t_fnFinditems() : t_builtInFunctionWithFindFn("finditems")
{
    setArgument("llll");
    setArgument("items", llll_get());
    setArgument("function", llll_get());
    setArgument("size", 0l);
    setArgument("depth");
    setArgument("minidx", 1l);
    setArgument("maxidx", -1);
    setArgument("idxreject", 0l);
    setArgument("depthreject", 0l);
    setArgument("maxcount", 0l);
    setArgument("unwrap", 0l);
    setArgument("depthpolicy", 0l);
    setArgument("recursive", 0l);
    setArgument("mindepth", 1l);
    setArgument("maxdepth", -1);
}

t_llll* t_fnFinditems::call(t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_llll *items = llll_clone(context.argv[2]); // may be nullptr as well
    t_function *fn = context.argv[3]->l_size ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    t_atom_long size = llll_getlong(context.argv[4]);
    t_atom_long minidx = llll_getlong(context.argv[6]);
    t_atom_long maxidx = llll_getlong(context.argv[7]);
    t_atom_long idxreject = llll_getlong(context.argv[8]);
    t_atom_long depthreject = llll_getlong(context.argv[9]);
    t_atom_long maxcount = llll_getlong(context.argv[10]);
    t_atom_long unwrap = llll_getlong(context.argv[11]);
    t_atom_long depthpolicy = llll_getlong(context.argv[12]);
    t_atom_long recursive = llll_getlong(context.argv[13]);
    
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[5], context.argv[14], context.argv[15], &mindepth, &maxdepth);
    
    if (size == 0) {
        size = items->l_size;
        if (size == 0)
            size = 1;
    }
    
    t_llll *found;

    if (fn) {
        t_fnData lambdaData(fn, &context, this, items);
        found = llll_find(ll, nullptr, size, mindepth, maxdepth, minidx, maxidx, idxreject, depthreject, maxcount, recursive, unwrap, depthpolicy, 0, (find_fn) lambdaFunction, &lambdaData);
    } else {
        found = llll_find(ll, nullptr, size, mindepth, maxdepth, minidx, maxidx, idxreject, depthreject, maxcount, recursive, unwrap, depthpolicy, 0, (find_fn) llll_eq_ignoretype, items);
    }
    
    return found;
}


///////////////


t_fnFindaddrs::t_fnFindaddrs() : t_builtInFunctionWithFindFn("findaddrs")
{
    setArgument("llll");
    setArgument("items", llll_get());
    setArgument("function", llll_get());
    setArgument("size", 0l);
    setArgument("depth");
    setArgument("minidx", 1l);
    setArgument("maxidx", -1);
    setArgument("idxreject", 0l);
    setArgument("depthreject", 0l);
    setArgument("maxcount", 0l);
    setArgument("depthpolicy", 0l);
    setArgument("recursive", 0l);
    setArgument("mindepth", 1l);
    setArgument("maxdepth", -1);
}

t_llll* t_fnFindaddrs::call(t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_llll *items = llll_clone(context.argv[2]); // may be nullptr as well
    t_function *fn = context.argv[3] ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    t_atom_long size = llll_getlong(context.argv[4]);
    t_atom_long minidx = llll_getlong(context.argv[6]);
    t_atom_long maxidx = llll_getlong(context.argv[7]);
    t_atom_long idxreject = llll_getlong(context.argv[8]);
    t_atom_long depthreject = llll_getlong(context.argv[9]);
    t_atom_long maxcount = llll_getlong(context.argv[10]);
    t_atom_long depthpolicy = llll_getlong(context.argv[11]);
    t_atom_long recursive = llll_getlong(context.argv[12]);

    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[5], context.argv[13], context.argv[14], &mindepth, &maxdepth);
    
    if (size == 0) {
        size = items->l_size;
        if (size == 0)
            size = 1;
    }
    
    t_llll *found, *addresses = nullptr;

    if (fn) {
        addresses = llll_get();
        t_fnData lambdaData(fn, &context, this, items);
        found = llll_find(ll, addresses, size, mindepth, maxdepth, minidx, maxidx, idxreject, depthreject, maxcount, recursive, 0, depthpolicy, 0, (find_fn) lambdaFunction, &lambdaData);
    } else {
        addresses = llll_get();
        found = llll_find(ll, addresses, size, mindepth, maxdepth, minidx, maxidx, idxreject, depthreject, maxcount, recursive, 0, depthpolicy, 0, (find_fn) llll_eq_ignoretype, items);
    }
    
    bell_release_llll(found);
    return addresses;
}


///////////////
