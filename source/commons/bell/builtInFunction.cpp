/*
 *  builtInFunction.cpp
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

#include "bell/builtInFunction.hpp"
#include "math/bach_math_utilities.h"

t_fnLength::t_fnLength() : t_builtInFunction("length") {
    setArgument("llll");
}

t_llll* t_fnLength::call(const t_execEnv &context) {
    t_llll *res = llll_get();
    llll_appendlong(res, context.argv[1]->l_size);
    return res;
}


///////////////


t_fnIs::t_fnIs() : t_builtInFunction("is") {
    setArgument("llll");
}

t_llll* t_fnIs::call(const t_execEnv &context) {
    t_llll *res = llll_get();
    t_symbol *s;
    switch(context.argv[1]->l_size) {
        case 0: s = _llllobj_sym_null;  break;
        case 1: {
            switch(hatom_gettype(&context.argv[1]->l_head->l_hatom)) {
                case H_LONG:        s = gensym("integer");      break;
                case H_RAT:         s = gensym("rational");     break;
                case H_DOUBLE:      s = gensym("real");         break;
                case H_SYM:         s = gensym("symbol");       break;
                case H_PITCH:       s = _llllobj_sym_pitch;     break;
                case H_FUNCTION:    s = gensym("function");     break;
                case H_LLLL:        s = _llllobj_sym_llll;      break;
                default:            s = gensym("UNKNOWN");      break;
            }
            break;
        }
        default: s = _llllobj_sym_llll;  break;
    }
    llll_appendsym(res, s);
    return res;
}


///////////////


t_fnArgs::t_fnArgs() : t_builtInFunction("$args") {
    setArgument("indices");
}

t_llll* t_fnArgs::call(const t_execEnv &context) {
    t_llll *res = llll_get();
    t_llll *indices = context.argv[1];
    t_llllelem **elempile = new t_llllelem* [indices->l_depth - 1];
    t_llllelem **thisElempile = elempile;
    t_llllelem *idxelem = indices->l_head;
    t_llll *newll = res;
    
    while (1) {
        while (idxelem) {
            t_hatom *idxhatom = &idxelem->l_hatom;
            switch (hatom_gettype(idxhatom)) {
                case H_LONG:
                case H_RAT:
                case H_DOUBLE:
                case H_PITCH: {
                    t_atom_long idx = hatom_getlong(idxhatom);
                    if (idx < 1 || idx > context.parent->argc) {
                        llll_appendllll(res, llll_get());
                    } else {
                        llll_chain(res, llll_clone(context.parent->argv[idx]));
                    }
                    idxelem = idxelem->l_next;
                    break;
                }
                case H_LLLL: {
                    newll = llll_get();
                    llll_appendllll(res, newll);
                    res = newll;
                    *thisElempile = idxelem;
                    thisElempile++;
                    idxelem = hatom_getllll(idxhatom)->l_head;
                    break;
                }
                default: {
                    llll_appendllll(res, llll_get());
                    idxelem = idxelem->l_next;
                    break;
                }
            }
        }
        if (thisElempile == elempile)
            break;
        res = newll->l_owner->l_parent;
        idxelem = (*--thisElempile)->l_next;
    }
    delete[] elempile;
    return res;
}


///////////////


t_fnArgcount::t_fnArgcount() : t_builtInFunction() {
}

t_llll* t_fnArgcount::call(const t_execEnv &context) {
    return get_long_ll(context.parent->argc);
}


///////////////

t_fnOutlet::t_fnOutlet() : t_builtInFunction("outlet", true) {
    setArgument("outlets");
}

t_llll* t_fnOutlet::call(const t_execEnv &context) {
    t_function *caller = context.parent->owner;
    long argc = context.argc;
    t_llll **argv = context.argv;
    t_llllelem *outletsElem;
    long arg;
    for (arg = 2, outletsElem = argv[1]->l_head;
         arg <= argc && outletsElem;
         arg++, outletsElem = outletsElem->l_next) {
        long outNum = hatom_getlong(&outletsElem->l_hatom);
        
        caller->setOutletData(outNum - 1, argv[arg]); // retained because it will go to an outlet
    }

    return llll_clone(argv[argc]);
}


///////////////

t_fnInlet::t_fnInlet() : t_builtInFunction("inlet", true) { }

t_llll* t_fnInlet::call(const t_execEnv &context) {
    t_llll *in = get_long_ll(context.mainFunc->getInlet());
    return llll_clone(in);
}

///////////////


t_fnRev::t_fnRev() : t_builtInFunction("rev")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll* t_fnRev::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    llll_rev(ll, mindepth, maxdepth);
    return ll;
}


///////////////


t_fnRot::t_fnRot() : t_builtInFunction("rot")
{
    setArgument("llll");
    setArgument("shift", 1);
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll* t_fnRot::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long shift = llll_getlong(context.argv[2]);
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[3], context.argv[4], context.argv[5], &mindepth, &maxdepth);
    llll_rot(ll, mindepth, maxdepth, shift);
    return ll;
}


///////////////


t_fnContains::t_fnContains() : t_builtInFunction("contains")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll* t_fnContains::call(const t_execEnv &context)
{
    t_llll *ll = context.argv[1];
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    t_atom_long contains = llll_contains(ll, mindepth, maxdepth);
    return get_long_ll(contains);
}


///////////////


t_fnTrans::t_fnTrans() : t_builtInFunction("trans")
{
    setArgument("llll");
    setArgument("depths", 1);
    setArgument("iterationmode", 1);
}

t_llll* t_fnTrans::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    long iterationmode = llll_getlong(context.argv[2]);
    t_llll *depths = context.argv[3];
    llll_trans_extended(ll, depths, iterationmode);
    //bell_release_llll(context.argv[1]);
    //bell_release_llll(depths);
    return ll;
}


///////////////


t_fnFlat::t_fnFlat() : t_builtInFunction("flat")
{
    setArgument("llll");
    setArgument("level");
    setArgument("minlevel", 1);
    setArgument("maxlevel", -1);
    setArgument("spikemode", 0l);
}

t_llll* t_fnFlat::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long minlevel, maxlevel;
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &minlevel, &maxlevel);
    long spikemode = llll_getlong(context.argv[5]);
    llll_flat(ll, minlevel, maxlevel, spikemode);
    return ll;
}


///////////////


t_fnSlice::t_fnSlice() : t_builtInFunction("slice")
{
    setArgument("llll");
    setArgument("index", 1);
}

t_llll* t_fnSlice::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    long index = llll_getlong(context.argv[2]);
    t_llll *right = llll_slice(ll, index);
    t_llll *res = llll_get();
    llll_appendllll(res, ll);
    if (right)
        llll_appendllll(res, right);
    else
        llll_appendllll(res, llll_get());
    return res;
}


///////////////


t_fnLeft::t_fnLeft() : t_builtInFunction("left")
{
    setArgument("llll");
    setArgument("index", 1);
}

t_llll* t_fnLeft::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    long index = llll_getlong(context.argv[2]);
    t_llll *right = llll_slice(ll, index);
    bell_release_llll(right);
    return ll;
}


///////////////


t_fnRight::t_fnRight() : t_builtInFunction("right")
{
    setArgument("llll");
    setArgument("index", -1);
}

t_llll* t_fnRight::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    long index = llll_getlong(context.argv[2]);
    t_llll *right = llll_slice(ll, index);
    bell_release_llll(ll);
    return right;
}


///////////////


t_fnSubs::t_fnSubs() : t_builtInFunction("subs")
{
    setArgument("llll");
    setArgument("address", 1);
    setArgument("model", llll_get());
    setArgument("multi", 0L);
    setArgument("sizes", 0L);
}

t_llll* t_fnSubs::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_llll *address;
    t_llll *model;
    t_atom_long multi = llll_getlong(context.argv[4]);
    t_llll *sizes = llll_clone(context.argv[5]);

    if (multi == 0) {
        llll_appendllll(address = llll_get(), llll_clone(context.argv[2]));
        llll_appendllll(model = llll_get(), llll_clone(context.argv[3]));
    } else {
        address = llll_clone(context.argv[2]);
        model = llll_clone(context.argv[3]);
    }
    
    if (llllobj_check_llll_address((t_object *) context.obj, address, true, false) != MAX_ERR_NONE) {
        bell_release_llll(address);
        bell_release_llll(model);
        bell_release_llll(sizes);
        return ll;
    }
    llll_multisubs(ll, address, model, sizes);
    return ll;
}


///////////////


t_fnInsert::t_fnInsert() : t_builtInFunction("insert")
{
    setArgument("llll");
    setArgument("address", 1);
    setArgument("model");
    setArgument("mode", 0l);
    setArgument("multi", 0l);
}

t_llll* t_fnInsert::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_llll *address;
    t_llll *model;
    t_atom_long mode = llll_getlong(context.argv[4]);
    t_atom_long multi = llll_getlong(context.argv[5]);
    
    if (multi == 0) {
        llll_appendllll(address = llll_get(), llll_clone(context.argv[2]));
        llll_appendllll(model = llll_get(), llll_clone(context.argv[3]));
    } else {
        address = llll_clone(context.argv[4]);
        model = llll_clone(context.argv[5]);
    }
    
    if (mode == 0 && multi == 1)
        llll_multiinsert_a(ll, address, model);
    else
        llll_multiinsert_b(ll, address, model);
    
    bell_release_llll(address);
    bell_release_llll(model);
    
    return ll;
}


///////////////

// UNUSED
t_fnKeysubs::t_fnKeysubs() : t_builtInFunction("keysubs")
{
    setArgument("llll");
    setArgument("keys");
    setArgument("model");
    //setArgument("multi", 0L);
}

t_llll* t_fnKeysubs::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_llll *keys;
    t_llll *model;

    keys = context.argv[2];
    model = context.argv[3];

    llll_keysubs(ll, keys, model);
    return ll;
}
///////////////


t_fnScramble::t_fnScramble() : t_builtInFunction("scramble")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll* t_fnScramble::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    llll_scramble(ll, mindepth, maxdepth);
    return ll;
}


///////////////


t_fnMinmax::t_fnMinmax() : t_builtInFunction("minmax")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll *t_fnMinmax::call(const t_execEnv &context)
{
    t_llll *ll = context.argv[1];
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    t_hatom *min, *max;
    t_llll *minaddress = llll_get();
    t_llll *maxaddress = llll_get();
    llll_minmax(ll, &min, &max, minaddress, maxaddress, mindepth, maxdepth);
    t_llll *res = llll_get();
    if (min->h_type != H_NOTHING) {
        llll_appendhatom_clone(res, min);
        llll_appendllll(res, minaddress);
        llll_appendhatom_clone(res, max);
        llll_appendllll(res, maxaddress);
    }
    return res;
}


///////////////


t_fnMinimum::t_fnMinimum() : t_builtInFunction("minimum")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll *t_fnMinimum::call(const t_execEnv &context)
{
    t_llll *ll = context.argv[1];
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    t_hatom *min;
    llll_minmax(ll, &min, nullptr, nullptr, nullptr, mindepth, maxdepth);
    t_llll *res = llll_get();
    if (min->h_type != H_NOTHING) {
        llll_appendhatom_clone(res, min);
    }
    return res;
}


///////////////


t_fnMaximum::t_fnMaximum() : t_builtInFunction("minimum")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll *t_fnMaximum::call(const t_execEnv &context)
{
    t_llll *ll = context.argv[1];
    t_atom_long mindepth, maxdepth;
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    t_hatom *max;
    llll_minmax(ll, nullptr, &max, nullptr, nullptr, mindepth, maxdepth);
    t_llll *res = llll_get();
    if (max->h_type != H_NOTHING) {
        llll_appendhatom_clone(res, max);
    }
    return res;
}


///////////////

t_fnPerm::t_fnPerm() : t_builtInFunction("perm")
{
    setArgument("llll");
    setArgument("maxcount", 0l);
}

t_llll *t_fnPerm::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long maxcount = llll_getlong(context.argv[2]);
    t_llll *res = llll_perm(ll, maxcount);
    return res;
}


///////////////


t_fnComb::t_fnComb() : t_builtInFunction("comb")
{
    setArgument("llll");
    setArgument("kstart", 0l);
    setArgument("kend", gensym("none"));
    setArgument("maxcount", 0l);
}

t_llll *t_fnComb::call(const t_execEnv &context)
{
    t_llll *ll = context.argv[1];
    t_atom_long kstart = llll_getlong(context.argv[2]);
    t_atom_long kend;
    if (hatom_gettype(&context.argv[3]->l_head->l_hatom) != H_SYM)
        kend = llll_getlong(context.argv[3]);
    else
        kend = -1;
    t_atom_long maxcount = llll_getlong(context.argv[4]);
    t_llll *res = llll_comb(ll, kstart, kend, maxcount);
    return res;
}


///////////////


t_fnCartesianprod::t_fnCartesianprod() : t_builtInFunction("cartesianprod")
{
    setArgument("llll");
}

t_llll *t_fnCartesianprod::call(const t_execEnv &context)
{
    t_atom_long count = context.argv[1]->l_size;
    t_llll **lists = (t_llll **) bach_newptr(count * sizeof(t_llll *));
    t_llllelem *elem;
    int i;
    for (elem = context.argv[1]->l_head, i = 0; elem;
         elem = elem->l_next, i++) {
        t_llll *onelist = hatom_getllll(&elem->l_hatom);
        if (onelist)
            lists[i] = onelist;
        else {
            lists[i] = llll_get();
            llll_appendhatom(lists[i], &elem->l_hatom);
        }
    }
    t_llll *res = llll_cartesianprod(lists, count);
    for (elem = context.argv[1]->l_head, i = 0; elem;
         elem = elem->l_next, i++) {
        if (hatom_gettype(&elem->l_hatom) != H_LLLL)
            bell_release_llll(lists[i]);
    }
    bach_freeptr(lists);
    return res;
}


///////////////


t_fnDepth::t_fnDepth() : t_builtInFunction("depth") {
    setArgument("llll");
}

t_llll* t_fnDepth::call(const t_execEnv &context) {
    t_llll *res = llll_get();
    llll_appendlong(res, context.argv[1]->l_depth);
    return res;
}


///////////////


t_fnNth::t_fnNth() : t_builtInFunction("nth") {
    setArgument("llll");
    setArgument("address", 1);
    setArgument("placeholder");
}

t_llll* t_fnNth::call(const t_execEnv &context) {
    t_llll *res = llll_nth(context.argv[1], context.argv[2], context.argv[3]);
    return res;
}


///////////////


t_fnWrap::t_fnWrap() : t_builtInFunction("wrap") {
    setArgument("llll");
    setArgument("levels", 1);
}

t_llll* t_fnWrap::call(const t_execEnv &context) {
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long levels = llll_getlong(context.argv[2]);
    llll_wrap(&ll, levels);
    return ll;
}


///////////////


t_fnDelace::t_fnDelace() : t_builtInFunction("delace") {
    setArgument("llll");
    setArgument("count", 2);
}

t_llll* t_fnDelace::call(const t_execEnv &context) {
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long count = llll_getlong(context.argv[2]);
    if (count < 1) {
        object_error((t_object *) context.obj, "bad count argument for delace, setting to 2");
        count = 2;
    }
    return llll_mdelace(ll, count);
}


///////////////


t_fnGroup::t_fnGroup() : t_builtInFunction("group") {
    setArgument("llll");
    setArgument("modulos", get_long_ll(1));
    setArgument("overlap", 0l);
}

t_llll* t_fnGroup::call(const t_execEnv &context) {
    t_llll *ll = llll_clone(context.argv[1]);
    t_llll *modulos = context.argv[2];
    t_atom_long overlap = llll_getlong(context.argv[3]);
    
    llll_multigroupllll(ll, modulos, overlap, 1);
    return ll;
}

///////////////


t_fnPrimeser::t_fnPrimeser() : t_builtInFunction("primeser") {
    setArgument("min", -1);
    setArgument("max", -1);
    setArgument("maxcount", 0l);
}

t_llll* t_fnPrimeser::call(const t_execEnv &context) {
    long min = llll_getlong(context.argv[1]);
    long max = context.argv[2]->l_size && hatom_is_number(&context.argv[2]->l_head->l_hatom) ?  llll_getlong(context.argv[2]) : -1;
    long maxcount = llll_getlong(context.argv[3]);
    t_llll *ll = llll_primeser(min, max, maxcount);
    return ll;
}


///////////////


t_fnArithmser::t_fnArithmser() : t_builtInFunction("arithmser") {
    setArgument("start", llll_get());
    setArgument("end", llll_get());
    setArgument("step", llll_get());
    setArgument("maxcount", 0L);
}

t_llll* t_fnArithmser::call(const t_execEnv &context) {
    const static t_hatom nothing = {{A_NOTHING}};
    //nothing.h_type = A_NOTHING;
    t_hatom start = context.argv[1]->l_size ? context.argv[1]->l_head->l_hatom : nothing;
    t_hatom end = context.argv[2]->l_size ? context.argv[2]->l_head->l_hatom : nothing;
    t_hatom step = context.argv[3]->l_size ? context.argv[3]->l_head->l_hatom : nothing;
    long maxcount = llll_getlong(context.argv[4]);
    
    t_llll *ll = llll_arithmser(start, end, step, maxcount, (t_object *) context.obj);
    
    return ll;
}


///////////////


t_fnGeomser::t_fnGeomser() : t_builtInFunction("geomser") {
    setArgument("start", llll_get());
    setArgument("end", llll_get());
    setArgument("factor", llll_get());
    setArgument("maxcount", 0L);
}

t_llll* t_fnGeomser::call(const t_execEnv &context) {
    t_hatom nothing;
    nothing.h_type = A_NOTHING;
    t_hatom start = context.argv[1]->l_size ? context.argv[1]->l_head->l_hatom : nothing;
    t_hatom end = context.argv[2]->l_size ? context.argv[2]->l_head->l_hatom : nothing;
    t_hatom factor = context.argv[3]->l_size ? context.argv[3]->l_head->l_hatom : nothing;
    long maxcount = llll_getlong(context.argv[4]);
    long err = 0;
    
    t_llll *ll = llll_geomser((t_object *) context.obj, start, end, factor, maxcount, &err);
        
    return ll;
}


///////////////

t_fnSum::t_fnSum() : t_builtInFunction("sum")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll* t_fnSum::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long mindepth, maxdepth;
    t_hatom sum_hatom;
    t_llll *sum_ll = llll_get();
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    llll_sum(ll, &sum_hatom, mindepth, maxdepth);
    llll_appendhatom_clone(sum_ll, &sum_hatom);
    return ll;
}


///////////////

t_fnProd::t_fnProd() : t_builtInFunction("prod")
{
    setArgument("llll");
    setArgument("depth");
    setArgument("mindepth", 1);
    setArgument("maxdepth", 1);
}

t_llll* t_fnProd::call(const t_execEnv &context)
{
    t_llll *ll = llll_clone(context.argv[1]);
    t_atom_long mindepth, maxdepth;
    t_hatom prod_hatom;
    t_llll *prod_ll = llll_get();
    getDepthsFromArguments(context.argv[2], context.argv[3], context.argv[4], &mindepth, &maxdepth);
    llll_prod(ll, &prod_hatom, mindepth, maxdepth);
    llll_appendhatom_clone(prod_ll, &prod_hatom);
    return ll;
}


///////////////



t_fnMc2f::t_fnMc2f() : t_builtInFunction("mc2f") {
    setArgument("mc", llll_get());
    setArgument("basefreq", 440.);
    setArgument("basepitch", 6900.);
}

t_llll* t_fnMc2f::call(const t_execEnv &context) {
    
    t_llll *mc = context.argv[1];
    double basefreq = llll_getdouble(context.argv[2], 440.);
    double basepitch = llll_getdouble(context.argv[3], 6900.);

    t_llll *ll = llll_mc2f(mc, basefreq, basepitch);
    //llll_free(mc);
    return ll;
}


///////////////


t_fnF2mc::t_fnF2mc() : t_builtInFunction("f2mc") {
    setArgument("mc", llll_get());
    setArgument("basefreq", 440.);
    setArgument("basepitch", 6900.);
}

t_llll* t_fnF2mc::call(const t_execEnv &context) {
    
    t_llll *f = context.argv[1];
    double basefreq = llll_getdouble(context.argv[2], 440.);
    double basepitch = llll_getdouble(context.argv[3], 6900.);
    
    t_llll *ll = llll_f2mc(f, basefreq, basepitch);
    //llll_free(f);
    return ll;
}
