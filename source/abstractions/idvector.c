/*
 *  idvector.c
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

/**
	@file
	idvector.c
	
	@name 
	bach.idvector
	
	@realname 
	bach.idvector

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Build cartesian versors and combinations
	
	@description
	Builds versors having all 0's as entries, except for a 1 in a given position (or combinations of such versors).
	
	@discussion
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	vector, identity, versor, unitary, build, combination, entry

	@seealso
	bach.idmatrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Function depends on inlet
// @description An integer in the first inlet outputs the cartesian vector having
// all 0's and just a 1 in the position specified by the incoming index. For instance,
// if the incoming index is 2, and the length of the vector is 5, the vector will be
// <b>0 1 0 0 0</b>. It also works with negative indices, as elsewhere in bach, indicating 
// elements right-to-left (-1 being the last, -2 the one-but-last...).<br />
// An integer in the second inlet sets a new length of the vector.


// @method list @digest Output combination of cartesian versors
// @description A list in the first inlet is considered as a list of indices corresponding to 
// 1's elements in the vector, while every other index is considered to be 0. As for the 
// <m>int</m> case, negative indices are allowed indicating elements to be counted right-to-left
// (-1 being the last, -2 the one-but-last...). For instance, if the length of the vector is 5,
// a list of <b>2 -2 -1</b> will trigger the output of the vector <b>0 1 0 1 1</b>.

// @method bang @digest Build the vector
// @description Builds the vector according to the most recently input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int/list @digest Position(s) of the 1('s)
// @description The index or indices corresponding to the 1's in the vector is expected
// in the first inlet

// @in 1 @type int @digest Change the output vector length


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The built vector



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name size @optional 1 @type int @digest Length of the vector  
// @description The length of the output vector (defaults to 1)

// @arg 1 @name position-of-ones @optional 1 @type list @digest Position(s) of the 1('s)
// @description The index or indices corresponding to the 1's in the vector can be listed
// as second argument (by default the 1st element of the vector is the 1).
