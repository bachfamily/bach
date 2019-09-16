/*
 *  ownedFunction.cpp
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

#include "bell/ownedFunction.hpp"



t_fnDirectout::t_fnDirectout(t_eval *owner) : t_ownedFunction("directout", true, reinterpret_cast<t_object *>(owner))
{
    setArgument("outlets");
}

t_llll* t_fnDirectout::call(const t_execEnv &context)
{
    long argc = context.argc;
    t_llll **argv = context.argv;
    t_llllelem *outletsElem;
    long arg;
    long dataOutlets = reinterpret_cast<t_eval *>(owner)->n_dataOutlets;
    long directOutlets = reinterpret_cast<t_eval *>(owner)->n_directOutlets;
    long totOutlets = dataOutlets + directOutlets; // which doesn't actually include the result outlet
    for (arg = 1, outletsElem = argv[1]->l_head;
         arg < argc && outletsElem;
         arg++, outletsElem = outletsElem->l_next) {
        long outNum = hatom_getlong(&outletsElem->l_hatom);
        if (outNum <= 0)
            outNum = totOutlets + outNum;
        else
            outNum += dataOutlets;
        if (outNum >= totOutlets)
            outNum = totOutlets;
        // usually after outputting an llll we should free it
        // here we don't because it will be freed by the caller of the function
        llllobj_outlet_llll((t_object *) owner, LLLL_OBJ_VANILLA, outNum, argv[arg + 1]);
    }
    return llll_clone(argv[argc]);
}


///////////////

t_fnDirectout_dummy::t_fnDirectout_dummy(t_object *owner) : t_fnDirectout(reinterpret_cast<t_eval *>(owner))
{
    
}

t_llll* t_fnDirectout_dummy::call(const t_execEnv &context)
{
    object_warn((t_object *) context.obj, "Can't call the directout function");
    return llll_clone(context.argv[context.argc]);
}

///////////////



t_fnDirectin::t_fnDirectin(t_eval *owner) : t_ownedFunction("directin", false, reinterpret_cast<t_object *>(owner))
{
    setArgument("inlet");
}

t_llll* t_fnDirectin::call(const t_execEnv &context)
{
    t_llll **argv = context.argv;
    t_llllelem *inletElem = argv[1]->l_head;
    long dataInlets = reinterpret_cast<t_eval *>(owner)->n_dataInlets;
    long directInlets = reinterpret_cast<t_eval *>(owner)->n_directInlets;
    long totInlets = dataInlets + directInlets;
    long inNum = hatom_getlong(&inletElem->l_hatom);
    if (inNum < 0)
        inNum = totInlets + inNum;
    else
        inNum += dataInlets - 1;
    if (inNum >= totInlets)
        inNum = totInlets - 1;
    if (inNum < 1) {
        object_error((t_object *) owner, "Bad inlet number for function directin");
        return llll_get();
    }
    t_llll *v = llllobj_get_store_contents((t_object *) owner, LLLL_OBJ_VANILLA, inNum, 1);
    
    return v;
}


///////////////


t_fnDirectin_dummy::t_fnDirectin_dummy(t_object *owner) : t_fnDirectin(reinterpret_cast<t_eval *>(owner))
{
    
}

t_llll* t_fnDirectin_dummy::call(const t_execEnv &context)
{
    object_warn((t_object *) context.obj, "Can't call the directin function");
    return llll_get();
}

///////////////


t_fnPrint::t_fnPrint(t_object *owner) : t_ownedFunction("print", false, owner)
{
    setArgument("llll");
    setArgument("prepend");
    setArgument("maxdecimals", new astConst(6l, (t_codableobj *) owner));
    setArgument("error", new astConst(0l, (t_codableobj *) owner));
}

t_llll* t_fnPrint::call(const t_execEnv &context)
{
    t_llll **argv = context.argv;
    t_llll *ll = argv[1];
    t_llll *prepend = argv[2];
    long maxdecimals = llll_getlong(argv[3]);
    long error = llll_getlong(argv[4]);
    if (prepend->l_size) {
        t_llll *printMe = llll_clone(prepend);
        t_llll *data = llll_clone(ll);
        llll_chain(printMe, data);
        llll_print(printMe, owner, error, maxdecimals, nullptr);
        bell_release_llll(printMe);
    } else {
        llll_print(ll, owner, error, maxdecimals, nullptr);
    }
    return llll_clone(ll);
}


///////////////
