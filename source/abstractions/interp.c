/*
 *  interp.c
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
	interp.c
	
	@name 
	bach.interp
	
	@realname 
	bach.interp

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Interpolate between lllls
	
	@description
	Performs interpolation between two lllls.
	
	@discussion
	The parameter for the interpolation is the number
	of sampling points. Such points are sampled
	linearly, unless the exponent is 
	set to a number different from 1.

	@category
	bach, bach abstractions, bach math

	@keywords
	interpolate, parameter, sampling, sample, linear, exponent

	@seealso
	bach.expr, bach.scale, bach.autoscale
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set llll to interpolate
// @description An llll in the third inlet sets the starting llll for the interpolation.
// An llll in the fourth inlet sets the ending llll for the interpolation.

// @method int @digest Set number of interpolation points, output result
// @description An integer in the first inlet sets the number of
// interpolation points, including the starting and ending point
// (that is: the length of the output llll), and output the result 
// (an llll having at its root level all the interpolation steps).

// @method float @digest Set exponent
// @description A float number in the second inlet set the exponent
// for the interpolation. 
// A number greater than 0. is expected, 1. being linear (default), with larger values 
// leading to steeper exponential curves (the ending llll being reached far more quickly).

// @method bang @digest Output result
// @description Outputs the interpolation with the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest Number of interpolation points
// @in 1 @type float @digest Interpolation exponent
// @in 2 @type llll @digest Starting llll
// @in 3 @type llll @digest Ending llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The interpolated lllls



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name exponential @optional 1 @type float @digest Interpolation exponent
// @description The optional argument sets the initial interpolation exponent.
// A number greater than 0. is expected, 1. being linear (default), with larger values 
// leading to steeper exponential curves (the ending llll being reached far more quickly).
