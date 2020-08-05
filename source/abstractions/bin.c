/*
 *  bin.c
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

/**
	@file
	bin.c
	
	@name 
	bach.bin
	
	@realname 
	bach.bin

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute binomial coefficient
	
	@description
	Computes the binomial coefficient (N K) = N! / (K! * (N-K)!),
	corresponding to the number K-element subsets in a set containing N elements.
	
	@discussion
	The algorithm applies the definition (with a slightly cleverer implementation).
	
	@category
	bach, bach abstractions, bach math

	@keywords
	compute, calculate, binomial coefficient, combinations
	
	@seealso
	bach.fact, bach.prod	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Set either N or K, output result
// @description In the first inlet, an integer will set the number N (number of elements of the set), 
// and output the binomial coefficient (N K).<br />
// In the second inlet, an integer will set the number K (number of elements of the subsets).

// @method list @digest Set both N and K and output result
// @description A list of two integers in the first inlet will set both N (number of elements of the set) 
// and K (number of elements of the subsets) at the same time, and output the binomial coefficial (N K).

// @method bang @digest Output last obtained result
// @description Outputs the result obtained from the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The number N, or the list N K
// @description Number N is the number of elements of the set.
// Number K is the number of elements of the subsets.
// @in 1 @type int @digest The number K 
// #description Number K is the number of elements of the subsets.



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest Binomial coefficient (N K)



// ---------------
// ARGUMENTS
// ---------------

// (none)
