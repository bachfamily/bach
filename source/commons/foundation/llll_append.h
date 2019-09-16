/*
 *  llll_append.h
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

#ifndef llll_append_h
#define llll_append_h

#include "foundation/llll_lifecycle.h"

// - DESTRUCTIVE - inplace
// check the depth of a list taking into account a newly-added sub-llll (son)
// it updates all the depths of the super-lists of son, if needed
// you only need to call it if you add an H_LLLL llllelem not using the provided functions
// NB: the depth of son must _already be correct. llll_upgrade_depth will only adjust the depths of its super-lists.
void llll_upgrade_depth(t_llll *son);

// - DESTRUCTIVE - inplace
// check the depth of a list (dad), and decrease it if needed
// it updates all the depths of the super-lists of dad, if needed
// you only need have to call it only if you remove an H_LLLL llllelem from dad without using the provided functions
void llll_downgrade_depth(t_llll *dad);


// only used for debugging purposes -- returns the root llll
t_llll *llll_root(const t_llll *ll);


///////////////////////////////////////////////////////////////////////
// ADDING ELEMENTS TO lllls

// IN ALL THE FOLLOWING FUNCTIONS,
// 1. if adopter is WHITENULL the new element is owned by the list it is appended (or prepended) to
//		otherwise, the new element is owned by adopter
// 2. the llll depth is always correctly updated
// 3. flags (when present) are the new llllelem flags
// 4. return value (when present) is the newly inserted element
//
// the llll_append... and llll_prepend... families work exactly the same
// except that in the former the new element becomes the tail of the list
// in the latter it becomes the head
//
// the llll_insert_...._before and llll_insert_...._after work similarly, too
// except of course for the placement of the new element
//
// NB: none of these functions is thread-safe.

// append a llllelem to a llll
void llll_append(t_llll *where, t_llllelem *what, t_llll *adopter = WHITENULL_llll);

// a new llllelem is created, and the incoming hatom is copied
t_llllelem *llll_appendhatom(t_llll *where, const t_hatom *what, const long flags = 0, t_llll *adopter = WHITENULL_llll); // duplicates the incoming atom!

// a new llllelem is created, the incoming hatom is copied
// if it contains a llll, the llll is also cloned
t_llllelem *llll_appendhatom_clone(t_llll *where, const t_hatom *what, const long flags = 0, t_llll *adopter = WHITENULL_llll); // duplicates the incoming atom, and clones the llll it possibly contains

// a new llllelem is created
t_llllelem *llll_appendlong(t_llll *where, t_atom_long what, long flags = 0, t_llll *adopter = WHITENULL_llll);

// a new llllelem is created, and the rational is reduced
t_llllelem *llll_appendrat(t_llll *where, t_rational what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_appendrat_from_elems(t_llll *where, t_atom_long what_num, t_atom_long what_den, long flags = 0, t_llll *adopter = WHITENULL_llll);

// a new llllelem is created
t_llllelem *llll_appendpitch(t_llll *where, t_pitch what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_appendpitch_from_elems(t_llll *where, t_atom_short degree, t_shortRational alter, t_atom_short octave, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_appenddouble(t_llll *where, double what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_appendsym(t_llll *where, t_symbol *what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_appendobj(t_llll *where, void *what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_appendfunc(t_llll *where, t_function *what, long flags = 0, t_llll *adopter = WHITENULL_llll);

// a new llllelem is created. the llll is not cloned
t_llllelem *llll_appendllll(t_llll *where, t_llll *what, long flags = 0, t_llll *adopter = WHITENULL_llll);

// a new llllelem is created. the llll is cloned
t_llllelem *llll_appendllll_clone(t_llll *where, t_llll *what, long flags = 0, t_llll *adopter = WHITENULL_llll, llll_clone_fn fn = NULL);

// see above
void llll_prepend(t_llll *where, t_llllelem *what, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependhatom(t_llll *where, const t_hatom *what, long flags = 0, t_llll *adopter = WHITENULL_llll); // duplicates the incoming atom!
t_llllelem *llll_prependhatom_clone(t_llll *where, const t_hatom *what, long flags = 0, t_llll *adopter = WHITENULL_llll); // duplicates the incoming atom, and clones the llll it possibly contains
t_llllelem *llll_prependlong(t_llll *where, t_atom_long what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependrat(t_llll *where, t_rational what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependrat_from_elems(t_llll *where, long what_num, long what_den, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependpitch(t_llll *where, t_pitch what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependpitch_from_elems(t_llll *where, t_atom_short degree, t_shortRational alter, t_atom_short octave, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependdouble(t_llll *where, double what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependsym(t_llll *where, t_symbol *what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependobj(t_llll *where, void *what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependfunc(t_llll *where, t_function *what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependllll(t_llll *where, t_llll *what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_prependllll_clone(t_llll *where, t_llll *what, long flags = 0, t_llll *adopter = WHITENULL_llll, llll_clone_fn fn = NULL);

// see above
void llll_insert_before(t_llllelem *what, t_llllelem *before_what, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_inserthatom_before(const t_hatom *what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_inserthatom_before_clone(const t_hatom *what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll); // duplicates the incoming atom, and clones the llll it possibly contains
t_llllelem *llll_insertlong_before(t_atom_long what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertrat_before(t_rational what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertrat_from_elems_before(long what_num, long what_den, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertdouble_before(double what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertpitch_before(t_pitch what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertpitch_from_elems_before(t_atom_short degree, t_shortRational alter, t_atom_short octave, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertsym_before(t_symbol *what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertobj_before(void *what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertfunc_before(t_function *what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertllll_before(t_llll *what, t_llllelem *before_what, long flags = 0, t_llll *adopter = WHITENULL_llll);

void llll_insert_after(t_llllelem *what, t_llllelem *after_what, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_inserthatom_after(t_hatom *what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_inserthatom_after_clone(t_hatom *what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll); // duplicates the incoming atom, and clones the llll it possibly contains
t_llllelem *llll_insertlong_after(t_atom_long what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertrat_after(t_rational what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertrat_from_elems_after(long what_num, long what_den, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertdouble_after(double what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertsym_after(t_symbol *what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertobj_after(void *what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertfunc_after(t_function *what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);
t_llllelem *llll_insertllll_after(t_llll *what, t_llllelem *after_what, long flags = 0, t_llll *adopter = WHITENULL_llll);

#endif /* llll_append_h */
