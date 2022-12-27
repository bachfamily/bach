/*
 *  ifunc.c
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

/**
	@file
	ifunc.c
	
	@name 
	bach.ifunc
	
	@realname 
	bach.ifunc

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute interval function of two pitch-class sets
	
	@description
	Reports the interval function of two pitch-class sets. The interval function between
	two sets A and B is defined as ifunc(A, B)_k = #{(x, y), x in A, y in B such that x-y = k}, roughly
	equivalent to saying that it is a vector where the k entry tells how many intervals of k steps
	can be formed by taking the first note from set A and the second note from set B.
	
	@discussion
	Interval function is related to interval vector: by plugging the same set as A and B, one obtains
	a redundant copy of the interval vector (in this case, 
	interval vector coincides with entries 2 to 7 of interval function, up to the possibility to 
	divide the 7th entry by two, see the <m>countperiodicsubsetsonce</m> attribute of <o>bach.ivec</o>).
	<br /> <br />
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	
	@category
	bach, bach abstractions, bach set theory

	@keywords
	interval function, interval vector, pitch-class, interval, combination

	@seealso
	bach.primeform, bach.circle, bach.mod+, bach.mod-, bach.modtimes, bach.period, bach.ivec, bach.histo
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set the pitch-class set (and output)
// @description In the first inlet, a llll will set the first pitch-class set (A) and output the resulting interval function <br />
// In the second inlet, a llll will set the second pitch-class set (B).

// @method bang @digest Output the interval function
// @description Gets the interval function of the most recently received input data.

// @method int @digest Set modulo 
// @description An integer in the right inlet will set the modulo. <br />
// @copy BACH_DOC_SETTHEORY_MODULO



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Pitch-class set A
// @in 1 @type llll @digest Pitch-class set B
// @in 2 @type int @digest Modulo



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Interval function



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
// @description @copy BACH_DOC_SETTHEORY_MODULO
