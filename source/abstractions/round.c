/*
 *  round.c
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
	round.c
	
	@name 
	bach.round
	
	@realname 
	bach.round

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Round llll elements to a value
	
	@description
	Calculates and outputs integer multiples of llll elements.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	round, approximate, snap, grid, number

	@seealso
	bach.expr, round
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set llll, output result
// @description An llll in the first inlet is considered as 
// the llll whose elements must be rounded. Each number inside
// the llll is rounded to the inserted multiple (see <m>number</m> message)
// and the modified llll is output.

// @method number @digest Set rounding multiple
// @description A number in the second inlet sets the rounding multiple.
// All numbers of lllls coming from the left inlet will be rounded
// to multiples of this number.
// This number also determines the type of the output numbers: if this
// is an integer, all output numbers will be integers; if this is a float
// all output numbers will be float; if this is a rational, all output
// numbers will be rationals or integers.
// The default rounding multiple is 1 (integer).

// @method bang @digest Output result
// @description Performs the rounding with the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "nearest", 0, t_round, nearest); 
CLASS_ATTR_STYLE_LABEL(c,"nearest",0,"onoff","Rounding Mode");
CLASS_ATTR_BASIC(c,"nearest",0);
// @description If this attribute is set to 0, only lower multiples
// of the inserted elements are output (i.e. the abstraction works
// like the "floor" function). If this attribute is set to 1 (default)
// lower and higher multiples are both considered (and the one nearest
// to the original value is taken).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll for rounding
// @in 1 @type number @digest Rounding multiple



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The rounded llll



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name multiple @optional 1 @type number @digest Rounding multiple
// @description The optional argument is the rounding multiple.
// See the <m>number</m> message to know more.
