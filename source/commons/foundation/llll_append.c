/*
 *  llll_append.c
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

#include "foundation/llll_append.h"
#include "bell/function.hpp"

// check the depth of a list taking into account a newly-added sub-llll (son)
// it updates all the depths of the super-lists of son, if needed
// you only need to call it if you add an H_LLLL llllelem without using the provided functions
void llll_upgrade_depth(t_llll *son)
{
    t_atom_long rise, abyss;
    t_llll *dad = NULL;
    if (!son)
        return;
    rise = 1;
    abyss = son->l_depth;
    if (son->l_owner)
        dad = son->l_owner->l_parent;
    while (dad && son->l_depth >= dad->l_depth) {
        dad->l_depth = abyss + rise;
        rise++;
        if (!dad->l_owner)
            break;
        son = dad;
        dad = son->l_owner->l_parent;
    }
}

// check the depth of a list (dad), and decrease it if needed
// it updates all the depths of the super-lists of dad, if needed
// you only need have to call it only if you remove an A_LLLL llllelem from dad without using the provided functions
void llll_downgrade_depth(t_llll *dad)
{
    t_llll *son;
    t_llllelem *elem;
    t_int32 maxdepth;
    //    long go_on = 1;
    if (!dad)
        return;
    do {
        son = dad;
        if (son->l_owner) {
            dad = son->l_owner->l_parent;
            //            go_on = dad && dad->l_depth <= son->l_depth + 1;
        } else
            dad = NULL;
        
        maxdepth = 0;
        for (elem = son->l_head; elem; elem = elem->l_next) {
            if (elem->l_hatom.h_type == H_LLLL && elem->l_hatom.h_w.w_llll->l_depth > maxdepth)
                maxdepth = elem->l_hatom.h_w.w_llll->l_depth;        
        }
        son->l_depth = maxdepth + 1;
    } while (dad);
}


// IN ALL THE FOLLOWING FUNCTIONS,
// 1. if adopter is WHITENULL the new element is owned by the list it is appended (or prepended) to
//        otherwise, the new element is owned by adopter
// 2. the llll depth is always correctly updated
// 3. flags (when present) are the new llllelem flags
//
// the llll_append and llll_prepend family work exactly the same
// except that in the former the new element becomes the tail of the list
// in the latter it becomes the head

// append a llllelem to a llll
void llll_append(t_llll *where, t_llllelem *what, t_llll *adopter)
{
    if (!where || !what)
        return;
    what->l_next = NULL;
    what->l_parent = adopter != WHITENULL ? adopter : where;
    if (where->l_size == 0) {
        where->l_head = where->l_tail = what;
        what->l_prev = NULL;
        where->l_size = 1;
        if (what->l_hatom.h_type == H_LLLL)
            llll_upgrade_depth(what->l_hatom.h_w.w_llll);
        else {
            where->l_depth = 1;
            llll_upgrade_depth(where);
        }
    } else {
        what->l_prev = where->l_tail;
        where->l_tail->l_next = what;
        where->l_tail = what;
        where->l_size ++;
        if (what->l_hatom.h_type == H_LLLL)
            llll_upgrade_depth(what->l_hatom.h_w.w_llll);
    }
    return;
}

// a new llllelem is created, and the incoming hatom is copied
t_llllelem *llll_appendhatom(t_llll *where, const t_hatom *what, const long flags, t_llll *adopter) // duplicates the incoming atom!
{
    t_llllelem *outelem;
    if (!where || !what)
        return NULL;
    if (what->h_type == H_LLLL)
        outelem = llll_appendllll(where, what->h_w.w_llll, flags, adopter);
    else {
        if (what->h_type == H_FUNCTION)
            what->h_w.w_func->increase();
        outelem = llllelem_get();
        outelem->l_hatom = *what;
        outelem->l_flags = flags;
        llll_append(where, outelem, adopter);
    }
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created, the incoming hatom is copied
// if it contains a llll, the llll is also cloned
t_llllelem *llll_appendhatom_clone(t_llll *where, const t_hatom *what, const long flags, t_llll *adopter) // duplicates the incoming atom, and clones the llll it possibly contains
{
    if (!where || !what)
        return NULL;
    if (what->h_type == H_LLLL) {
        return llll_appendllll(where, llll_clone(what->h_w.w_llll), flags, adopter);
    } else
        return llll_appendhatom(where, what, flags, adopter);
}

// a new llllelem is created
t_llllelem *llll_appendlong(t_llll *where, t_atom_long what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setlong(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    return outelem;
}

// a new llllelem is created, and the rational is reduced
t_llllelem *llll_appendrat(t_llll *where, t_rational what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created, and the rational is reduced
t_llllelem *llll_appendrat_from_elems(t_llll *where, t_atom_long what_num, t_atom_long what_den, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational_from_elems(&outelem->l_hatom, what_num, what_den);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_appenddouble(t_llll *where, double what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setdouble(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_appendpitch(t_llll *where, t_pitch what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_appendpitch_from_elems(t_llll *where, t_atom_short degree, t_shortRational alter, t_atom_short octave, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch_from_elems(&outelem->l_hatom, degree, alter, octave);
    //hatom_setrational_from_elems(&outelem->l_hatom, what_num, what_den);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_appendsym(t_llll *where, t_symbol *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setsym(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_appendobj(t_llll *where, void *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setobj(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_appendfunc(t_llll *where, t_function *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setfunc(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created. the llll is not cloned
t_llllelem *llll_appendllll(t_llll *where, t_llll *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setllll(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    what->l_owner = outelem;
    llll_append(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_appendllll_clone(t_llll *where, t_llll *what, long flags, t_llll *adopter, llll_clone_fn fn)
{
    return llll_appendllll(where, llll_clone_extended(what, adopter, 0, fn), flags, adopter);
}

void llll_prepend(t_llll *where, t_llllelem *what, t_llll *adopter)
{
    if (!where || !what)
        return;
    what->l_prev = NULL;
    what->l_parent = adopter != WHITENULL ? adopter : where;
    if (!where) {
        where = llll_get();
    }
    if (where->l_size == 0) {
        where->l_head = where->l_tail = what;
        what->l_next = NULL;
        where->l_size = 1;
        if (what->l_hatom.h_type == H_LLLL)
            llll_upgrade_depth(what->l_hatom.h_w.w_llll);
        else {
            where->l_depth = 1;
            llll_upgrade_depth(where);
        }
        pedantic_llll_check(where);
        return;
    }
    what->l_next = where->l_head;
    where->l_head->l_prev = what;
    where->l_head = what;
    where->l_size++;
    if (what->l_hatom.h_type == H_LLLL)
        llll_upgrade_depth(what->l_hatom.h_w.w_llll);
    pedantic_llll_check(where);
    return;
}

t_llllelem *llll_prependhatom(t_llll *where, const t_hatom *what, long flags, t_llll *adopter) // duplicates the incoming atom!
{
    t_llllelem *outelem;
    if (!where || !what)
        return NULL;
    if (what->h_type == H_LLLL)
        outelem = llll_prependllll(where, what->h_w.w_llll, flags, adopter);
    else {
        if (what->h_type == H_FUNCTION)
            what->h_w.w_func->increase();
        outelem = llllelem_get();
        outelem->l_hatom = *what;
        outelem->l_flags = flags;
        llll_prepend(where, outelem, adopter);
    }
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependhatom_clone(t_llll *where, const t_hatom *what, long flags, t_llll *adopter) // duplicates the incoming atom, and clones the llll it possibly contains
{
    if (!where || !what)
        return NULL;
    if (what->h_type == H_LLLL) {
        return llll_prependllll(where, llll_clone(what->h_w.w_llll), flags, adopter);
    } else
        return llll_prependhatom(where, what, flags, adopter);
}

t_llllelem *llll_prependlong(t_llll *where, t_atom_long what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setlong(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependrat(t_llll *where, t_rational what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependrat_from_elems(t_llll *where, t_atom_long what_num, t_atom_long what_den, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational_from_elems(&outelem->l_hatom, what_num, what_den);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependdouble(t_llll *where, double what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setdouble(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_prependpitch(t_llll *where, t_pitch what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

// a new llllelem is created
t_llllelem *llll_prependpitch_from_elems(t_llll *where, t_atom_short degree, t_shortRational alter, t_atom_short octave, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch_from_elems(&outelem->l_hatom, degree, alter, octave);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependsym(t_llll *where, t_symbol *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setsym(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependobj(t_llll *where, void *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setobj(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependfunc(t_llll *where, t_function *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setfunc(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}

t_llllelem *llll_prependllll(t_llll *where, t_llll *what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!where)
        return NULL;
    outelem = llllelem_get();
    hatom_setllll(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    what->l_owner = outelem;
    llll_prepend(where, outelem, adopter);
    pedantic_llll_check(where);
    return outelem;
}


t_llllelem *llll_prependllll_clone(t_llll *where, t_llll *what, long flags, t_llll *adopter, llll_clone_fn fn)
{
    return llll_prependllll(where, llll_clone_extended(what, adopter, 0, fn), 0, adopter);
}

// IN ALL THE FOLLOWING FUNCTIONS,
// 1. if adopter is WHITENULL the new element is owned by the list it is appended (or prepended) to
//        otherwise, the new element is owned by adopter
// 2. the llll depth is always correctly updated
// 3. flags (when present) are the new llllelem flags
//
// the llll_append and llll_prepend family work exactly the same
// except that in the former the new element becomes the tail of the list
// in the latter it becomes the head

// append a llllelem to a llll
void llll_insert_before(t_llllelem *what, t_llllelem *before_what, t_llll *adopter)
{
    t_llll *where;
    
    if (!what || !before_what)
        return;
    
    where = before_what->l_parent;
    what->l_parent = adopter != WHITENULL ? adopter : where;
    
    if (where->l_size == 0 || before_what == where->l_head) {
        llll_prepend(where, what, adopter);
        pedantic_llll_check(where);
        return;
    }
    
    before_what->l_prev->l_next = what;
    what->l_prev = before_what->l_prev;
    what->l_next = before_what;
    before_what->l_prev = what;
    
    where->l_size ++;
    if (what->l_hatom.h_type == H_LLLL)
        llll_upgrade_depth(what->l_hatom.h_w.w_llll);
    pedantic_llll_check(where);
    return;
}

// a new llllelem is created, and the incoming hatom is copied
t_llllelem *llll_inserthatom_before(const t_hatom *what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what || !what)
        return NULL;
    if (what->h_type == H_LLLL)
        outelem = llll_insertllll_before(what->h_w.w_llll, before_what, flags, adopter);
    else {
        if (what->h_type == H_FUNCTION)
            what->h_w.w_func->increase();
        outelem = llllelem_get();
        outelem->l_hatom = *what;
        outelem->l_flags = flags;
        llll_insert_before(outelem, before_what, adopter);
    }
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

// a new llllelem is created, the incoming hatom is copied
// if it contains a llll, the llll is also cloned
t_llllelem *llll_inserthatom_before_clone(const t_hatom *what, t_llllelem *before_what, long flags, t_llll *adopter) // duplicates the incoming atom, and clones the llll it possibly contains
{
    t_llll *sub_llll;
    if (!before_what || !what)
        return NULL;
    if ((sub_llll = hatom_getllll(what))) {
        return llll_insertllll_before(llll_clone(sub_llll), before_what, flags, adopter);
    } else
        return llll_inserthatom_before(what, before_what, 0, adopter);
}

// a new llllelem is created
t_llllelem *llll_insertlong_before(t_atom_long what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setlong(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertrat_before(t_rational what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertrat_from_elems_before(t_atom_long what_num, t_atom_long what_den, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational_from_elems(&outelem->l_hatom, what_num, what_den);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertdouble_before(double what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setdouble(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertpitch_before(t_pitch what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertpitch_from_elems_before(t_atom_short degree, t_shortRational alter, t_atom_short octave, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch_from_elems(&outelem->l_hatom, degree, alter, octave);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertsym_before(t_symbol *what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setsym(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertobj_before(void *what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setobj(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertfunc_before(t_function *what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setfunc(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertllll_before(t_llll *what, t_llllelem *before_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!before_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setllll(&outelem->l_hatom,  what);
    outelem->l_flags = flags;
    what->l_owner = outelem;
    llll_insert_before(outelem, before_what, adopter);
    pedantic_llll_check(before_what->l_parent);
    return outelem;
}

void llll_insert_after(t_llllelem *what, t_llllelem *after_what, t_llll *adopter)
{
    t_llll *where;
    
    if (!what || !after_what)
        return;
    
    where = after_what->l_parent;
    what->l_parent = adopter != WHITENULL ? adopter : where;
    
    if (where->l_size == 0 || after_what == where->l_tail) {
        llll_append(where, what, adopter);
        pedantic_llll_check(after_what->l_parent);
        return;
    }
    
    after_what->l_next->l_prev = what;
    what->l_next = after_what->l_next;
    what->l_prev = after_what;
    after_what->l_next = what;
    
    where->l_size ++;
    if (what->l_hatom.h_type == H_LLLL)
        llll_upgrade_depth(what->l_hatom.h_w.w_llll);
    pedantic_llll_check(after_what->l_parent);
    return;
}

// a new llllelem is created, and the incoming hatom is copied
t_llllelem *llll_inserthatom_after(t_hatom *what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what || !what)
        return NULL;
    if (what->h_type == H_LLLL)
        outelem = llll_insertllll_after(what->h_w.w_llll, after_what, flags, adopter);
    else {
        if (what->h_type == H_FUNCTION)
            what->h_w.w_func->increase();
        outelem = llllelem_get();
        outelem->l_hatom = *what;
        outelem->l_flags = flags;
        llll_insert_after(outelem, after_what, adopter);
    }
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

// a new llllelem is created, the incoming hatom is copied
// if it contains a llll, the llll is also cloned
t_llllelem *llll_inserthatom_after_clone(t_hatom *what, t_llllelem *after_what, long flags, t_llll *adopter) // duplicates the incoming atom, and clones the llll it possibly contains
{
    t_llll *sub_llll;
    if (!after_what || !what)
        return NULL;
    if ((sub_llll = hatom_getllll(what))) {
        return llll_insertllll_after(llll_clone(sub_llll), after_what, flags, adopter);
    } else
        return llll_inserthatom_after(what, after_what, 0, adopter);
}

// a new llllelem is created
t_llllelem *llll_insertlong_after(t_atom_long what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setlong(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertrat_after(t_rational what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertrat_from_elems_after(t_atom_long what_num, t_atom_long what_den, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setrational_from_elems(&outelem->l_hatom, what_num, what_den);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertdouble_after(double what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setdouble(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertpitch_after(t_pitch what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertpitch_from_elems_after(t_atom_short degree, t_shortRational alter, t_atom_short octave, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setpitch_from_elems(&outelem->l_hatom, degree, alter, octave);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertsym_after(t_symbol *what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setsym(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertobj_after(void *what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setobj(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertfunc_after(t_function *what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setfunc(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}

t_llllelem *llll_insertllll_after(t_llll *what, t_llllelem *after_what, long flags, t_llll *adopter)
{
    t_llllelem *outelem;
    if (!after_what)
        return NULL;
    outelem = llllelem_get();
    hatom_setllll(&outelem->l_hatom, what);
    outelem->l_flags = flags;
    what->l_owner = outelem;
    llll_insert_after(outelem, after_what, adopter);
    pedantic_llll_check(after_what->l_parent);
    return outelem;
}
