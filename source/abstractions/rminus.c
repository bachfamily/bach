/*
 *  rminus.c
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
	rminus.c
	
	@name 
	bach.!-
	
	@realname 
	bach.rminus

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quick llll subtraction (inlets reversed)
	
	@description
	Performs subtractions between lllls or
	between lllls and numbers, with reversed inlets:
	Left operand goes in right inlet and right operand goes in left inlet.
	
	@discussion
	The abstraction is equivalent to a (reverse) subtraction performed
	in a <o>bach.expr</o> object, with the <m>scalarmode</m>
	attribute set to 1.

	@category
	bach, bach abstractions, bach math

	@keywords
	difference, calculate, compute, subtraction, number

	@seealso
	bach.expr, bach.-, !-, bach.mod-
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the right
// llll for the subtraction, and will output the result; an llll
// in the second inlet will set the left llll for the subtraction,
// without outputting any result. <br />
// @copy BACH_DOC_OPERATION_ABSTRACTIONS_LLLL_AND_NUMBERS_REMARK

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input lllls.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Right operand llll
// @in 1 @type llll @digest Left operand llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The (reverse) subtraction of the two operands



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name left_operand @optional 1 @type llll @digest Left operand llll
// @description The optional argument is the left operand llll.
