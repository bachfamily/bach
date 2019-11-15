/*
 *  llll_lifecycle.h
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

#ifndef llll_lifecycle_h
#define llll_lifecycle_h

#include "foundation/hatom.h"
#include "foundation/bach_mem.h"

///////////////////////////////////////////////////////////////////////
///// MEMORY STUFF


///////////////////////////////////////////////////////////////////////
// the free_direct API
//
// a set of functions to manage the lifecycle of lllls and llllelems


// used by llll_flat and llll_splatter
typedef enum {
    LLLL_FREETHING_DONT    = 0,    // don't free l_thing when removing a pair of parentheses
    LLLL_FREETHING_MEM,            // free l_thing with bach_freeptr()
    LLLL_FREETHING_OBJ,            // free l_thing with object_free_debug()
    LLLL_FREETHING_LLLL,        // free l_thing with llll_free()
    LLLL_FREETHING_LLLLELEM        // free l_thing with llllelem_free()
} e_freething_modes;



// call this before llll_free if you need an llll that is a sublist of something else
// this should happen very rarely
void llll_fix_owner_for_check(t_llll *ll);

// free a llll without calling llll_check() - DEPRECATED
void llll_free_nocheck(t_llll *ll);

// call llll_check() and free the llll (even if llll_check() returns an error)
void llll_free(t_llll *ll);

void llll_dispose(t_llll *x);


// increment/decrement the reference count of ll
t_llll *llll_retain(t_llll *ll);
t_llll *llll_retain_nocheck(t_llll *ll);
void llll_release(t_llll *ll);

// non-threadsafe versions of the above---USE CAUTIOUSLY
t_llll *llll_retain_unsafe(t_llll *ll); // doesn't perform the check either
void llll_release_unsafe(t_llll *ll); // doesn't take into account the llll flags

// free a llll without calling llll_check; all the l_thing fields will be freed according to freething - DEPRECATED
void llll_free_nocheck_freethings(t_llll *ll, e_freething_modes freething);

// ... and so on
void llll_free_freethings(t_llll *ll, e_freething_modes freething);

void llllelem_dispose(t_llllelem *x);

void llllelem_free_nocheck(t_llllelem *elem); //  - DEPRECATED
void llllelem_free_nocheck_freethings(t_llllelem *elem, e_freething_modes freething); //  - DEPRECATED
void llllelem_free(t_llllelem *elem);
void llllelem_free_freethings(t_llllelem *elem, e_freething_modes freething);

// only free all the l_things of a llll
void llll_freethings(t_llll *ll, e_freething_modes freething);

// return a clean llll from the pool
// if necessary, it will allocate a new page in the pool
t_llll *llll_get(void);

// same as above (should be cleaned up)
t_llll *llll_make(void);

// return a clean llllelem from the pool
// if necessary, it will allocate a new page in the pool
t_llllelem *llllelem_get(void);

// same as above (should be cleaned up)
t_llllelem *llllelem_make(void);


// called by llll_clone
typedef void* (*llll_clone_fn)(void *x);


// clone an llll
t_llll *llll_clone(const t_llll *inll);

// clone inll to outll (which is assumed to be empty)
t_max_err llll_clone_upon(const t_llll *inll, t_llll *outll);


// clone an llll, with some extended options
// adopter is the list that will appear as the owner of the elements of the base level of the newly-created list
// this is useful in some exotic situations
// WHITENULL means that the new list's elements will have the default owner (in this case, it's the same as NULL)
// fn: every time a llll's l_thing is != 0, it is passed to fn for appropriate cloning.
// whatever fn returns, it will be put in the l_thing field of the corresponding destination llll
// if fn == NULL the l_thing field itself is copied
// alloc is unused
t_llll *llll_clone_extended(const t_llll *inll, t_llll *adopter = WHITENULL_llll, long alloc = 0, llll_clone_fn fn = NULL);



// check that everything is fine in ll: prevs, nexts, ownerships, parenthoods, lengths, depths, magic numbers
t_max_err llll_check(const t_llll *ll);

#endif /* llll_lifecycle_h */
