/*
 *  clip.c
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
	clip.c
	
	@name 
	bach.clip
	
	@realname 
	bach.clip

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Limit elements of lllls within a certain range
	
	@description
	Constraints each element of the incoming llll
	into a given numerical range, defined by a lower and 
	an upper boundary.
	
	@discussion
	Lower and upper boundaries must be coherent, namely
	the upper one must always be greater or equal to the smaller one
	(also element-wise, if any of them is a complex llll),
	otherwise the result might be inconsistent.

	@category
	bach, bach abstractions, bach math

	@keywords
	clip, force, limit, range, boundary, constraint, number, minimum, maximum

	@seealso
	bach.maximum, bach.minimum, clip, bach.expr
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Clip lll, output result, set boundary
// @description An llll in the first inlet is taken as the llll
// to be clipped. Each element of such llll is constrained to lie
// inside the range defined by the lower and upper boundaries:
// if it is smaller than the lower boundary it is set to be the lower
// boundary, if it is bigger than the upper boundary it is set to
// be the upper boundary. The modified llll is then output through
// the outlet. <br />
// An llll in the second inlet sets the lower boundary,
// an llll in the third inlet sets the upper boundary.
// In case such lllls are plain numbers, the meaning is trivial: such
// numbers apply for all elements of the original llll, coming from the
// first inlet.
// In case any of the two lllls is a complex llll, it is assumed
// to be an element-wise boundary for the incoming llll, exactly
// as it happens for the inputs of <o>bach.maximum</o> and 
// <o>bach.minimum</o>.
// If any boundary llll is complex, and do not correspond in length with the original
// llll, the longer is always considered (and exceeding elements are trivially preserved).
// If single scalar elements are in the same position of complex lllls, such
// scalars apply for all elements of the corresponding llll. 


// @method number @digest Set boundary
// @description A number in the second inlet sets the lower boundary for each element
// of the llll.
// A number in the third inlet sets the upper boundary for each element
// of the llll.

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be clipped
// @in 1 @type number/llll @digest Lower boundary
// @in 1 @type number/llll @digest Upper boundary



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll clipped element-wise



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name lower_boundary @optional 1 @type number/llll @digest Lower boundary
// @description The optional first argument sets the initial lower boundary.
// If the boundary needs to be an llll (see <m>llll</m> message), such llll needs
// to be wrapped in an outer level of parenthesis.

// @arg 1 @name upper_boundary @optional 1 @type number/llll @digest Upper boundary
// @description The optional first argument sets the initial upper boundary.
// If the boundary needs to be an llll (see <m>llll</m> message), such llll needs
// to be wrapped in an outer level of parenthesis.
