/*
 *  norm.c
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
	norm.c
	
	@name 
	bach.norm
	
	@realname 
	bach.norm

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the norm of a vector
	
	@description
	Finds the p-norm of a plain llll. For p = 2 (default case),
	such norm is the euclidean norm, 
	i.e. the square root of the sum of the squares of the elements.
	
	@discussion
	In general, the p-norm of a vector is calculated by 
	raising all the absolute values of the elements 
	to the <m>p</m>-th power, summing all values, and taking
	the <m>p</m>-th root (i.e. raising to 1/<m>p</m>).
	The inf-norm, on the other hand, is the absolute value
	of the maximum element in the llll.

	@category
	bach, bach abstractions, bach math

	@keywords
	norm, calculate, compute, distance, square, element, sum, square root

	@seealso
	bach.normalize, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output norm of vector
// @description Any llll will trigger the computation of its norm
// (non-numbers are ignored), which is then output from the outlet.

// @method bang @digest Compute norm
// @description Computes the norm on most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_ATOM(c, "p", 0, t_norm, p); 
CLASS_ATTR_STYLE_LABEL(c,"p",0,"text","Value of p");
CLASS_ATTR_BASIC(c,"p",0);
// @description @copy BACH_DOC_NORM_P_ATTRIBUTE_FOR_VECTORS

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The vector as plain llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The norm of the vector



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name p @optional 1 @type atom @digest Value of p
// @description The optional argument sets the value of p
// (the index of the norm). See the <m>p</m> attribute for more information. 
