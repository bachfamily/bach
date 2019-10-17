/*
 *  stdev.c
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
	stdev.c
	
	@name 
	bach.stdev
	
	@realname 
	bach.stdev

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the standard deviation of the numbers in an llll
	
	@description
	Finds the standard deviation (square root of the variance) of the numbers in an llll.
	
	@discussion
	The standard deviation is the square root of the variance, which in turns
	is the second central moment (the expected value of the
	square deviations of numbers from their mean).

	@category
	bach, bach abstractions, bach math

	@keywords
	standard deviation, statistics, moment, compute, calculate, number

	@seealso
	bach.mean, bach.variance, bach.median, bach.skewness, bach.kurtosis
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute and output standard deviation
// @description Any llll will trigger the computation of the standard deviation of all numbers
// contained in the llll (non-numbers are ignored), which is then output from the first outlet.

// @method bang @digest Compute standard deviation
// @description Computes the standard deviation on most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_stdev, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
//  the numbers should be considered. <br />
// 	@copy BACH_DOC_MAXDEPTH

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing numbers



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The standard deviation of all incoming numbers



// ---------------
// ARGUMENTS
// ---------------

// (none)
