/*
 *  llll_hatom_change.c
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

#include "foundation/llll_hatom_change.h"
#include "bell/function.hpp"


t_llllelem *llll_hatom2elem(const t_hatom *hatom)
{
    return (t_llllelem *) (((char *) hatom) - ((t_ptr_int) &((t_llllelem *) 0)->l_hatom));
}

// returns the old llll, if any
t_llll *hatom_change_to_llll(t_hatom *hatom, t_llll *llll)
{
    t_llllelem *elem = llll_hatom2elem(hatom);
    if (hatom->h_type != H_LLLL) {
        hatom->h_type = H_LLLL;
        hatom->h_w.w_llll = llll;
        llll->l_owner = elem;
        llll_upgrade_depth(llll);
        pedantic_llll_check(llll);
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        t_atom_long old_depth = old_ll->l_depth;
        t_atom_long new_depth = llll->l_depth;
        old_ll->l_owner = NULL;
        hatom->h_w.w_llll = llll;
        llll->l_owner = elem;
        if (old_depth < new_depth)
            llll_upgrade_depth(llll);
        else if (old_depth > new_depth)
            llll_downgrade_depth(elem->l_parent);
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_long(t_hatom *hatom, const t_atom_long l)
{
    if (hatom->h_type != H_LLLL) {
        hatom->h_type = H_LONG;
        hatom->h_w.w_long = l;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        hatom->h_type = H_LONG;
        hatom->h_w.w_long = l;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_rat(t_hatom *hatom, const t_rational rat)
{
    if (hatom->h_type != H_LLLL) {
        hatom->h_type = H_RAT;
        hatom->h_w.w_rat = rat;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        hatom->h_type = H_RAT;
        hatom->h_w.w_rat = rat;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_double(t_hatom *hatom, const double d)
{
    if (hatom->h_type != H_LLLL) {
        hatom->h_type = H_DOUBLE;
        hatom->h_w.w_double = d;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        hatom->h_type = H_DOUBLE;
        hatom->h_w.w_double = d;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_sym(t_hatom *hatom, const t_symbol *s)
{
    if (hatom->h_type != H_LLLL) {
        hatom->h_type = H_SYM;
        hatom->h_w.w_sym = (t_symbol *) s;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        hatom->h_type = H_SYM;
        hatom->h_w.w_sym = (t_symbol *) s;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_obj(t_hatom *hatom, const void *o)
{
    if (hatom->h_type != H_LLLL) {
        hatom->h_type = H_OBJ;
        hatom->h_w.w_obj = (void *) o;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        hatom->h_type = H_OBJ;
        hatom->h_w.w_obj = (t_object *) o;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_func(t_hatom *hatom, t_function *fn)
{
    if (hatom->h_type != H_LLLL) {
        hatom->h_type = H_FUNCTION;
        hatom->h_w.w_func->decrease();
        fn->increase();
        hatom->h_w.w_func = fn;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        hatom->h_type = H_FUNCTION;
        hatom->h_w.w_func->decrease();
        fn->increase();
        hatom->h_w.w_func = (t_function *) fn;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_hatom(t_hatom *hatom, const t_hatom *h)
{
    if (h->h_type == H_LLLL)
        return hatom_change_to_llll(hatom, h->h_w.w_llll);
    if (hatom->h_type != H_LLLL) {
        if (h->h_type == H_FUNCTION)
            h->h_w.w_func->increase();
        if (hatom->h_type == H_FUNCTION)
            h->h_w.w_func->decrease();
        *hatom = *h;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        *hatom = *h;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

t_llll *hatom_change_to_hatom_clone(t_hatom *hatom, const t_hatom *h)
{
    if (h->h_type == H_LLLL)
        return hatom_change_to_llll(hatom, llll_clone(h->h_w.w_llll));
    if (hatom->h_type != H_LLLL) {
        if (h->h_type == H_FUNCTION)
            h->h_w.w_func->increase();
        if (hatom->h_type == H_FUNCTION)
            h->h_w.w_func->decrease();
        *hatom = *h;
        return NULL;
    } else {
        t_llll *old_ll = hatom->h_w.w_llll;
        *hatom = *h;
        llll_downgrade_depth(old_ll->l_owner->l_parent);
        old_ll->l_owner = NULL;
        pedantic_llll_check(old_ll);
        return old_ll;
    }
}

void hatom_change_to_llll_and_free(t_hatom *hatom, t_llll *llll)
{
    llll_free(hatom_change_to_llll(hatom, llll));
}

void hatom_change_to_long_and_free(t_hatom *hatom, const t_atom_long l)
{
    llll_free(hatom_change_to_long(hatom, l));
}

void hatom_change_to_rat_and_free(t_hatom *hatom, const t_rational rat)
{
    llll_free(hatom_change_to_rat(hatom, rat));
}

void hatom_change_to_double_and_free(t_hatom *hatom, const double d)
{
    llll_free(hatom_change_to_double(hatom, d));
}

void hatom_change_to_sym_and_free(t_hatom *hatom, const t_symbol *s)
{
    llll_free(hatom_change_to_sym(hatom, s));
}

void hatom_change_to_obj_and_free(t_hatom *hatom, const void *o)
{
    llll_free(hatom_change_to_obj(hatom, o));
}

void hatom_change_to_func_and_free(t_hatom *hatom, t_function *fn)
{
    llll_free(hatom_change_to_func(hatom, fn));
}

void hatom_change_to_hatom_and_free(t_hatom *hatom, const t_hatom *h)
{
    llll_free(hatom_change_to_hatom(hatom, h));
}

void hatom_change_to_hatom_clone_and_free(t_hatom *hatom, const t_hatom *h)
{
    llll_free(hatom_change_to_hatom_clone(hatom, h));
}
