/*
 *  abs.c
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
	abs.c
	
	@name 
	bach.abs
	
	@realname 
	bach.abs

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quick absolute value of lllls
	
	@description
	Takes the absolute value of an incoming llll.
	
	@discussion
	The abstraction is equivalent to the <b>abs</b> function called
	in a <o>bach.expr</o> object.

	@category
	bach, bach abstractions, bach math

	@keywords
	absolute value, modulo, magnitude, radius, calculate, compute, sign

	@seealso
	bach.expr, abs 
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output the absolute value
// @description For each number of the incoming llll is 
// taken the absolute (non-negative) value, and the llll
// containing the absolute values (having the same shape
// as the original one) is output through the outlet.
// Non-numbers are kept as they are.

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Original llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing absolute values



// ---------------
// ARGUMENTS
// ---------------

// (none)
