/*
 *  modtimes.c
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
	modtimes.c
	
	@name 
	bach.mod*
	
	@realname 
	bach.modtimes

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Modular arithmetic multiplication
	
	@description
	Performs multiplications modulo a certain integer.
	
	@discussion

	@category
	bach, bach abstractions, bach set theory

	@keywords
	modulo, multiplication, times, number, pitch-class

	@seealso
	bach.*, bach.%, bach.mod+, bach.mod-
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the left
// llll for the multiplication, and will output the result; an llll
// in the second inlet will set the right llll for the multiplication
// (as for <o>bach.*</o>). <br />
// @copy BACH_DOC_OPERATION_ABSTRACTIONS_LLLL_AND_NUMBERS_REMARK

// @method int @digest Set modulo
// @description An integer in the third outlet sets the modulo of the
// operation. <br />
// @copy BACH_DOC_SETTHEORY_MODULO

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

// @in 0 @type llll @digest Left operand llll
// @in 1 @type llll @digest Right operand llll
// @in 2 @type int @digest Modulo



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The modular multiplication of the two operands



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name arguments @optional 1 @type list @digest Arguments 
// @description If a single integer argument is provided, this is considered
// to be the modulo of the operation. If two integers are provided,
// these are considered to be the right operand and the modulo. <br />
// @copy BACH_DOC_SETTHEORY_MODULO
