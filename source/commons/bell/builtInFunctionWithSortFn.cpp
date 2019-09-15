/*
 *  builtInFunctionWithSortFn.cpp
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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

#include "builtInFunctionWithSortFn.hpp"



long t_builtInFunctionWithSortFn::lambdaFunction(t_fnData *lambdaData, t_llllelem *a, t_llllelem *b)
{
    t_function *fn = lambdaData->func;
    t_execEnv *context = &lambdaData->context;

    context->argv[1] = llll_get();
    context->argv[2] = llll_get();
    llll_appendhatom_clone(context->argv[1], &a->l_hatom);
    llll_appendhatom_clone(context->argv[2], &b->l_hatom);
    context->resetFnNamedArgs(fn, 2);
    t_llll *resLl = fn->call(lambdaData->context);
    long res = llll_istrue(resLl);
    bell_release_llll(resLl);
    return res;
}


///////////////


t_fnSort::t_fnSort() : t_builtInFunctionWithSortFn("sort") {
    setArgument("llll");
    setArgument("function", llll_get());
}

t_llll* t_fnSort::call(const t_execEnv &context) {
    t_llll *res = NULL;
    t_llll *ll = llll_clone(context.argv[1]);
    t_function *fn = context.argv[2]->l_size ? (t_function *) hatom_getfunc(&context.argv[2]->l_head->l_hatom) : nullptr;
    if (!fn) {
        llll_mergesort(ll, &res, llll_leq_elem, nullptr);
        return res;
    }
    t_fnData lambdaData(fn, &context, this);
    
    llll_mergesort(ll, &res, (sort_fn) lambdaFunction, &lambdaData);
    
    return res;
}

///////////////


t_fnThin::t_fnThin() : t_builtInFunctionWithSortFn("thin")
{
    setArgument("llll");
    setArgument("function", llll_get());
}

t_llll* t_fnThin::call(const t_execEnv &context)
{
    t_function *fn = context.argv[2]->l_size ? (t_function *) hatom_getfunc(&context.argv[2]->l_head->l_hatom) : nullptr;
    if (!fn) {
        t_llll *ll = llll_clone(context.argv[1]);
        ll = llll_thin_simple(ll, 0);
        return ll;
    }
    
    t_fnData lambdaData(fn, &context, this);
    
    t_llll *ll = llll_clone(context.argv[1]);
    llll_thin(ll, (sort_fn) lambdaFunction, &lambdaData);
    
    return ll;
}


///////////////


t_fnClassify::t_fnClassify() : t_builtInFunctionWithSortFn("classify")
{
    setArgument("llll");
    setArgument("function", llll_get());
}

t_llll* t_fnClassify::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_function *fn = context.argv[2]->l_size ? (t_function *) hatom_getfunc(&context.argv[2]->l_head->l_hatom) : nullptr;
    if (!fn) {
        ll = llll_classify_simple(ll, 0);
        return ll;
    }
    
    t_fnData lambdaData(fn, &context, this);
    
    llll_classify(ll, (sort_fn) lambdaFunction, &lambdaData);
    
    return ll;
}


///////////////


t_fnUnion::t_fnUnion() : t_builtInFunctionWithSortFn("union")
{
    setArgument("llll1");
    setArgument("llll2");
    setArgument("function", llll_get());
}

t_llll* t_fnUnion::call(const t_execEnv &context)
{
    t_llll *ll1 = llll_clone(context.argv[1]);
    t_llll *ll2 = llll_clone(context.argv[2]);
    t_function *fn = context.argv[3]->l_size ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    if (!fn) {

        llll_union(ll1, ll2);
        return ll1;
    }
    
    t_fnData lambdaData(fn, &context, this);

    llll_union(ll1, ll2, (sort_fn) lambdaFunction, &lambdaData);
    return ll1;
}


///////////////


t_fnIntersection::t_fnIntersection() : t_builtInFunctionWithSortFn("intersection") {
    setArgument("llll1");
    setArgument("llll2");
    setArgument("function", llll_get());
}

t_llll* t_fnIntersection::call(const t_execEnv &context)
{
    t_llll *ll1 = llll_clone(context.argv[1]);
    t_llll *ll2 = llll_clone(context.argv[2]);
    t_function *fn = context.argv[3]->l_size ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    if (!fn) {
        llll_intersection(ll1, ll2);
        return ll1;
    }
    
    t_fnData lambdaData(fn, &context, this);
    
    llll_intersection(ll1, ll2, (sort_fn) lambdaFunction, &lambdaData);
    return ll1;
}


///////////////


t_fnSymdiff::t_fnSymdiff() : t_builtInFunctionWithSortFn("symdiff")
{
    setArgument("llll1");
    setArgument("llll2");
    setArgument("function", llll_get());
}

t_llll* t_fnSymdiff::call(const t_execEnv &context)
{
    t_llll *ll1 = llll_clone(context.argv[1]);
    t_llll *ll2 = llll_clone(context.argv[2]);
    t_function *fn = context.argv[3]->l_size ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    if (!fn) {
        llll_symdiff(ll1, ll2);
        return ll1;
    }
    
    t_fnData lambdaData(fn, &context, this);
    
    llll_symdiff(ll1, ll2, (sort_fn) lambdaFunction, &lambdaData);
    return ll1;
}


///////////////


t_fnDiff::t_fnDiff() : t_builtInFunctionWithSortFn("diff") {
    setArgument("llll1");
    setArgument("llll2");
    setArgument("function", llll_get());
}

t_llll* t_fnDiff::call(const t_execEnv &context)
{
    t_llll *ll1 = llll_clone(context.argv[1]);
    t_llll *ll2 = llll_clone(context.argv[2]);
    t_function *fn = context.argv[3]->l_size ? (t_function *) hatom_getfunc(&context.argv[3]->l_head->l_hatom) : nullptr;
    if (!fn) {
        llll_diff(ll1, ll2);
        return ll1;
    }
    
    t_fnData lambdaData(fn, &context, this);
    llll_diff(ll1, ll2, (sort_fn) lambdaFunction, &lambdaData);
    return ll1;
}




