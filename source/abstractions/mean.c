/*
 *  mean.c
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
	mean.c
	
	@name 
	bach.mean
	
	@realname 
	bach.mean

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the mean of the numbers in an llll
	
	@description
	Finds the mean of the numbers in an llll.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	mean, statistics, average, moment, compute, calculate, number

	@seealso
	bach.variance, bach.stdev, bach.median, bach.skewness, bach.kurtosis
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute and output mean
// @description Any llll will trigger the computation of the mean of all numbers
// contained in the llll (non-numbers are ignored), which is then output from the first outlet.

// @method bang @digest Compute mean
// @description Computes the mean on most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);


CLASS_ATTR_LONG(c, "maxdepth", 0, t_mean, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
//  the numbers should be considered. <br />
// 	@copy BACH_DOC_MAXDEPTH

CLASS_ATTR_LLLL(c, "weights", 0, t_mean, weights); 
CLASS_ATTR_STYLE_LABEL(c,"weights",0,"text","Weights");
CLASS_ATTR_BASIC(c,"weights",0);
//	@description This attribute defines weights for each element (in order to compute a weighted mean). Leave it to null (default) to compute standard mean.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing numbers



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The mean of all incoming numbers



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name floatmode @optional 1 @type float @digest Floating Point Output  
// @description Any float argument will force the output to be a floating point number.
