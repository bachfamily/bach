/*
 *  median.c
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
	median.c
	
	@name 
	bach.median
	
	@realname 
	bach.median

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the median of the numbers in an llll
	
	@description
	Finds the median of the elements in a flat llll.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	median, number, statistics, compute, calculate, quantile

	@seealso
	bach.quantiles, bach.mean, bach.mode, bach.variance, bach.stdev, bach.skewness, bach.kurtosis
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute and output median
// @description Any llll will trigger the computation of the output median of its elements.
// Incoming llll is supposed to be flat, otherwise lllls will be treated and considered as element
// and thus sorted accordingly, like for <o>bach.sort</o>

// @method bang @digest Compute median
// @description Computes the median of most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing numbers



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The median of all incoming numbers



// ---------------
// ARGUMENTS
// ---------------

// (none)
