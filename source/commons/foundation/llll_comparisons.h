/*
 *  llll_comparisons.h
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

#ifndef _LLLL_COMPARISONS_H_
#define _LLLL_COMPARISONS_H_

/*
 *  llll_comparisons.h
 *  bach
 *
 *  Created by andrea agostini on 25/4/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "foundation/hatom.h"

/////////////////////////////////////////////////////////////////////////////////////
// INEQUALITY COMPARISONS 
// leq <=, geq >=, lt <, gt >
// the dummy parameter for the ..._elem versions is ignored (it will usually be NULL)
// it's there for allowing the usage as sort_fn
// comparison rules:
// numbers are compared by value (regardless of type)
// symbols are compared by lexicographic order
// lllls are compared element by element, recursively
// objects are always considered equal to each other
// numbers < symbols < lllls < objects
long llll_leq(t_llll *ll1, t_llll *ll2);
long llll_geq(t_llll *ll1, t_llll *ll2);
long llll_lt(t_llll *ll1, t_llll *ll2);
long llll_gt(t_llll *ll1, t_llll *ll2);
long llll_leq_elem(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_geq_elem(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_lt_elem(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_gt_elem(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_leq_hatom(t_hatom *a_hatom, t_hatom *b_hatom);
long llll_geq_hatom(t_hatom *a_hatom, t_hatom *b_hatom);
long llll_lt_hatom(t_hatom *a_hatom, t_hatom *b_hatom);
long llll_gt_hatom(t_hatom *a_hatom, t_hatom *b_hatom);

// "MATCHTYPE" INEQUALITY COMPARISONS
// These are versions of leq and geq useful for sorting.
// they establish a hierarchy between data types, and equal values with different types 
// are considered leq (or geq) only if their respective types are leq (or geq)
// This allows sorting an llll so that same-value numbers are sorted by type.
long llll_leq_elem_matchtype(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_geq_elem_matchtype(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_leq_hatom_matchtype(t_hatom *a_hatom, t_hatom *b_hatom);
long llll_geq_hatom_matchtype(t_hatom *a_hatom, t_hatom *b_hatom);

// EQUALITY COMPARISONS 
// no dummy parameters here (you will never use them as sort_fn's)
// ignoretype and matchtype are only relevant for numbers:
// ignoretype means that 2 == 2., matchtype means that 2 != 2.
long llll_eq_matchtype(t_llll *ll1, t_llll *ll2);
long llll_eq_ignoretype(t_llll *ll1, t_llll *ll2);
long llll_neq_matchtype(t_llll *ll1, t_llll *ll2);
long llll_neq_ignoretype(t_llll *ll1, t_llll *ll2);
long llll_eq_elem_matchtype(t_llllelem *el1, t_llllelem *el2);
long llll_eq_elem_ignoretype(t_llllelem *el1, t_llllelem *el2);
long llll_eq_hatom_matchtype(t_hatom *h1, t_hatom *h2);
long llll_eq_hatom_ignoretype(t_hatom *h1, t_hatom *h2);

#endif // _LLLL_COMPARISONS_H_
