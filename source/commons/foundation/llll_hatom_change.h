/*
 *  llll_hatom_change.h
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

#ifndef llll_hatom_change_h
#define llll_hatom_change_h

#include "foundation/llll_append.h"


// retrieve the address of an llllelem from the address of its hatom
t_llllelem *llll_hatom2elem(const t_hatom *hatom);

// the following functions change the contents of an hatom
// they also update the depths of the lllls containing the elem containing the hatom
// IMPORTANT: for this reason, these functions can only be called on hatom contained in elems belonging to correctly-formed lllls
// otherwise, bad things will happen
// return value for all these functions: the llll previously contained in the hatom, or NULL of none
t_llll *hatom_change_to_llll(t_hatom *hatom, t_llll *llll);
t_llll *hatom_change_to_long(t_hatom *hatom, const t_atom_long l);
t_llll *hatom_change_to_rat(t_hatom *hatom, const t_rational rat);
t_llll *hatom_change_to_double(t_hatom *hatom, const double d);
t_llll *hatom_change_to_sym(t_hatom *hatom, const t_symbol *s);
t_llll *hatom_change_to_obj(t_hatom *hatom, const void *o);
t_llll *hatom_change_to_func(t_hatom *hatom, t_function *fn);
t_llll *hatom_change_to_hatom(t_hatom *hatom, const t_hatom *h);
t_llll *hatom_change_to_hatom_clone(t_hatom *hatom, const t_hatom *h); // if the new hatom contains an llll, the llll is cloned

// as above, but if the hatom contained an llll, the llll is freed
void hatom_change_to_long_and_free(t_hatom *hatom, const t_atom_long l);
void hatom_change_to_rat_and_free(t_hatom *hatom, const t_rational rat);
void hatom_change_to_double_and_free(t_hatom *hatom, const double d);
void hatom_change_to_sym_and_free(t_hatom *hatom, const t_symbol *s);
void hatom_change_to_obj_and_free(t_hatom *hatom, const void *o);
void hatom_change_to_func_and_free(t_hatom *hatom, t_function *fn);
void hatom_change_to_llll_and_free(t_hatom *hatom, t_llll *llll);
void hatom_change_to_hatom_and_free(t_hatom *hatom, const t_hatom *h);
void hatom_change_to_hatom_clone_and_free(t_hatom *hatom, const t_hatom *h); // if the new hatom contains an llll, the llll is cloned

#endif /* llll_hatom_change_h */
