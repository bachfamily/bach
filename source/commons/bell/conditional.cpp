/*
 *  conditional.cpp
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

#include "bell/conditional.hpp"


t_llll *astLogNot::eval(t_execEnv const &context) {
    long res;
    t_llll *v = n1->TCOEval(context);
    res = !llll_istrue(v);
    bell_release_llll(v);
    return get_long_ll(res);
}


//////////////////

t_bool astLogXor_core(t_llll *first, astNode *second, t_execEnv const &context)
{
    t_llll *v2 = second->TCOEval(context);
    long t1 = llll_istrue(first);
    long t2 = llll_istrue(v2);
    llll_release(first);
    llll_release(v2);
    return t1 ^ t2;
}

t_llll *astLogXor_run(t_llll *first, astNode *second, t_execEnv const &context)
{
    return get_long_ll(astLogXor_core(first, second, context));
}

t_bool astLogXor_hatom(const t_hatom *first, astNode *second, t_execEnv const &context)
{
    t_llll *v2 = second->TCOEval(context);
    long t1 = hatom_istrue(first);
    long t2 = llll_istrue(v2);
    llll_release(v2);
    return t1 ^ t2;
}

//////////////////

t_bool astSCOr_core(t_llll *first, astNode *second, t_execEnv const &context)
{
    if (llll_istrue(first)) {
        llll_release(first);
        return true;
    } else {
        bell_release_llll(first);
        t_llll *v2 = second->TCOEval(context);
        if (llll_istrue(v2)) {
            llll_release(v2);
            return true;
        } else {
            llll_release(v2);
            return false;
        }
    }
}

t_llll* astSCOr_run(t_llll *first, astNode *second, t_execEnv const &context)
{
    return get_long_ll(astSCOr_core(first, second, context));
}

t_bool astSCOr_hatom(const t_hatom *first, astNode *second, t_execEnv const &context)
{
    if (hatom_istrue(first)) {
        return true;
    } else {
        t_llll *v2 = second->TCOEval(context);
        if (llll_istrue(v2)) {
            llll_release(v2);
            return true;
        } else {
            llll_release(v2);
            return false;
        }
    }
}

//////////////////

t_bool astSCAnd_core(t_llll *first, astNode *second, t_execEnv const &context)
{
    if (!llll_istrue(first)) {
        bell_release_llll(first);
        return false;
    } else {
        bell_release_llll(first);
        t_llll *v2 = second->TCOEval(context);
        if (!llll_istrue(v2)) {
            bell_release_llll(v2);
            return false;
        } else {
            bell_release_llll(v2);
            return true;
        }
    }
}

t_llll *astSCAnd_run(t_llll *first, astNode *second, t_execEnv const &context)
{
    return get_long_ll(astSCAnd_core(first, second, context));
}

t_bool astSCAnd_hatom(const t_hatom *first, astNode *second, t_execEnv const &context)
{
    if (!hatom_istrue(first)) {
        return false;
    } else {
        t_llll *v2 = second->TCOEval(context);
        if (!llll_istrue(v2)) {
            llll_release(v2);
            return false;
        } else {
            llll_release(v2);
            return true;
        }
    }
}

//////////////////

t_llll *astSCOrExt_run(t_llll *first, astNode *second, t_execEnv const &context)
{
    if (first->l_size) {
        return first;
    } else {
        return second->TCOEval(context);
    }
}

//////////////////

t_llll* astSCAndExt_run(t_llll *first, astNode *second, t_execEnv const &context)
{
    if (first->l_size == 0) {
        return first;
    } else {
        return second->TCOEval(context);
    }
}

//////////////////


astIfThenElse::~astIfThenElse() {
    delete ifNode;
    delete thenNode;
    delete elseNode;
}

t_llll *astIfThenElse::eval(t_execEnv const &context) {
    t_llll *cond = ifNode->TCOEval(context);
    if (llll_istrue(cond)) {
        bell_release_llll(cond);
        t_llll *v = llll_get();
        llll_appendobj(v, thenNode);
        return v;
    } else {
        bell_release_llll(cond);
        t_llll *v = llll_get();
        if (elseNode)
            llll_appendobj(v, elseNode);
        return v;
    }
}


//////////////////


//////////////////


