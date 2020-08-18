/*
 *  scale.c
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
	scale.c
	
	@name 
	bach.scale
	
	@realname 
	bach.scale

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Linearly rescale an llll
	
	@description
	Maps an input range of llll values to an output range.
	
	@discussion
	The mapping is always linear. If elements are outside
	the input range, the result will be an extrapolation.

	@category
	bach, bach abstractions, bach math

	@keywords
	rescale, expand, stretch, linear, number, minimum, maximum, value, range, map

	@seealso
	bach.autoscale, bach.minmax, bach.expr, bach.interp
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Rescale llll, output result
// @description All numbers of the llll coming from the first inlet are mapped from the given input range
// to the chosen output range (see the <m>number</m> message to define such numbers, or set them as arguments). 
// The modified llll (having the same shape of the original one) is then output through the outlet.

// @method number @digest Set minimum or maximum
// @description A number in the second inlet sets the input minimum (lowest boundary of the input range).
// A number in the third inlet sets the input minimum (highest boundary of the input range).
// A number in the fourth inlet sets the output minimum (lowest boundary of the output range).
// A number in the fifth inlet sets the output maximum (highest boundary of the output range).
// Such numbers can be of any type (integers, floats, rationals): the result will vary accordingly.

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

// @in 0 @type llll @digest The llll to be rescaled
// @in 1 @type number @digest Input minimum
// @in 2 @type number @digest Input maximum
// @in 3 @type number @digest Output minimum
// @in 4 @type number @digest Output maximum



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The linearly rescaled llll



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name input_min @optional 1 @type number @digest Input minimum
// @description First optional argument is the input minimum (default: 0.).

// @arg 1 @name input_max @optional 1 @type number @digest Input maximum
// @description Second optional argument is the input maximum (default: 127.).

// @arg 2 @name output_min @optional 1 @type number @digest Output minimum
// @description Third optional argument is the output minimum (default: 0.).

// @arg 3 @name output_max @optional 1 @type number @digest Output maximum
// @description Fourth optional argument is the output maximum (default: 1.).
