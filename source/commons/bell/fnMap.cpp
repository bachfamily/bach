/*
 *  fnMap.cpp
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

#include "bell/fnMap.hpp"

long t_fnMap::lambdaAsk(t_fnData *lambdaData, t_llll *ll, t_llll *old_address, t_llll *new_address)
{
    t_function *fn = lambdaData->funcAsk;
    t_execEnv *context = &lambdaData->fnAskContext;
    long numargs = context->argc;
    t_llll **lists = context->argv;
    switch (numargs) {
        case 3:     lists[3] = llll_clone(new_address);
        case 2:     lists[2] = llll_clone(old_address);
        default:    lists[1] = ll;  break;
    }
    context->resetFnNamedArgs(fn, numargs);
    t_llll *res = fn->call(*context);
    long res_long = llll_istrue(res);
    bell_release_llll(lists[3]);
    bell_release_llll(lists[2]);
    bell_release_llll(res);
    return !res_long;
}

t_llll* t_fnMap::lambdaMod(t_fnData *lambdaData, t_llll *ll, t_llll *old_address, t_llll *new_address)
{
    t_function *fn = lambdaData->funcMod;
    t_execEnv *context = &lambdaData->fnModContext;
    long numargs = context->argc;
    t_llll **lists = context->argv;
    switch (numargs) {
        case 3:     lists[3] = llll_clone(new_address);
        case 2:     lists[2] = llll_clone(old_address);
        default:    lists[1] = ll;  break;
    }
    context->resetFnNamedArgs(fn, numargs);
    t_llll *res = fn->call(*context);
    bell_release_llll(lists[3]);
    bell_release_llll(lists[2]);
    t_llll *res_clone = llll_clone(res);
    bell_release_llll(res);
    return res_clone;
}

t_fnMap::t_fnMap() : t_builtInFunction("map")
{
    setArgument("llll");
    setArgument("modfunction", llll_get());
    setArgument("askfunction", llll_get());
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll* t_fnMap::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_function *modFunction = context.argv[2]->l_size ? (t_function *) hatom_getfunc(&context.argv[2]->l_head->l_hatom) : nullptr;
    t_function *askFunction = context.argv[3]->l_size ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[4], context.argv[5], context.argv[6], &mindepth, &maxdepth);
    
    if (!modFunction)
        return ll;
    
    t_fnData lambdaData(askFunction, modFunction, &context, this);
    
    if (modFunction->isVariadic())
        lambdaData.fnModContext.argc = 3;
    else
        lambdaData.fnModContext.argc = modFunction->getNamedArgumentsCount();
    if (lambdaData.fnModContext.argc > 3)
        lambdaData.fnModContext.argc = 3;
    
    if (askFunction) {
        if (askFunction->isVariadic())
            lambdaData.fnAskContext.argc = 3;
        else
            lambdaData.fnAskContext.argc = modFunction->getNamedArgumentsCount();
        if (lambdaData.fnAskContext.argc > 3)
            lambdaData.fnAskContext.argc = 3;
    }
        
    llll_funall_extended(ll,
                         askFunction ? (fun_ext_ask_fn) lambdaAsk : nullptr,
                         (fun_ext_mod_fn) lambdaMod,
                         &lambdaData, mindepth, maxdepth);
    
    return ll;
}


///////////////////


t_llll* t_fnReduce::lambdaFunction(t_fnData *lambdaData, t_llll *accum, const t_hatom *h, t_atom_long address)
{
    t_function *fn = lambdaData->fn;
    t_execEnv *context = &lambdaData->context;
    long numargs = context->argc;
    t_llll **lists = context->argv;
    context->resetFnNamedArgs(fn, numargs);
    lists[1] = accum;
    t_llll *res;
    switch (numargs) {
        case 3:
            llll_appendlong(lists[3] = llll_get(), address);
            llll_appendhatom_clone(lists[2] = llll_get(), h);
            res = fn->call(*context);
            bell_release_llll(lists[3]);
            lists[3] = nullptr;
            break;
        default:
            llll_appendhatom_clone(lists[2] = llll_get(), h);
            res = fn->call(*context);
            break;
    }
    bell_release_llll(lists[2]);
    lists[2] = nullptr;
    lists[1] = nullptr; // the caller owns it, so we don't release it here
    return res;
}

t_fnReduce::t_fnReduce() : t_builtInFunction("reduce")
{
    setArgument("llll");
    setArgument("function");
}

t_llll* t_fnReduce::call(const t_execEnv &context)
{
    t_function *function = context.argv[2]->l_size ? (t_function *) hatom_getfunc(&context.argv[2]->l_head->l_hatom) : nullptr;
    
    if (!function)
        return llll_clone(context.argv[1]);
    
    t_fnData lambdaData(function, &context, this);
    
    t_llll *res;
    
    if (function->isVariadic())
        lambdaData.context.argc = 3;
    else {
        lambdaData.context.argc = function->getNamedArgumentsCount();
        if (lambdaData.context.argc > 3)
            lambdaData.context.argc = 3;
    }
    
    res = llll_reduce(context.argv[1], (reduce_fn) lambdaFunction, &lambdaData);

    return res;
}


///////////////////


t_fnApply::t_fnApply() : t_builtInFunction("apply")
{
    setArgument("function");
    setArgument("argsbyposition");
    setArgument("argsbyname");
}

t_llll* t_fnApply::call(const t_execEnv &context)
{
    t_function *function = context.argv[1]->l_size ? (t_function *) hatom_getfunc(&context.argv[1]->l_head->l_hatom) : nullptr;
    if (!function)
        return llll_get();
    t_llll *res = astFunctionCall::callFunction(function, context.argv[2], context.argv[3], context);
    return res;
}


