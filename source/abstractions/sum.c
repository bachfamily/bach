/*
 *  sum.c
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
	sum.c
	
	@name 
	bach.sum
	
	@realname 
	bach.sum

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Sum all numbers in an llll
	
	@description
	Sums all the numbers of the incoming llll.
	
	@discussion
	<o>bach.sum</o> only operates on numbers; each 
	non-number element is simply ignored.

	@category
	bach, bach abstractions, bach math

	@keywords
	sum, number, calculate, compute, add, summation

	@seealso
	bach.prod, bach.mean, bach.+, zl
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Sum all numbers and output result
// @description All the numbers of the incoming llll are
// summed, the number of such addends is output through
// the right outlet, and the result of the summation is output through the left outlet. 
// Non-numbers are simply ignored.
// The number of summed elements also depends on the
// <m>maxdepth</m> attribute.

// @method bang @digest Output result
// @description Outputs the number of addends and the result of calculation 
// performed on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_sum, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
//  	numbers must be considered for the summation. The default is 0, meaning: all levels. <br />
// 	@copy BACH_DOC_MAXDEPTH

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll whose numbers must be summed



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Sum of all numbers
// @out 1 @type int @digest Number of addends



// ---------------
// ARGUMENTS
// ---------------

// (none)
