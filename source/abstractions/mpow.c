/*
 *  mpow.c
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
	mpow.c
	
	@name 
	bach.mpow
	
	@realname 
	bach.mpow

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the power of a matrix
	
	@description
	Raises the incoming square matrix to a given integer power.

	@discussion
	For positive exponents, <o>bach.mpow</o> simply performs the multiplication of the 
	matrix by itself a certain number of times.
	For negative exponents, it does the same with the inverse matrix: if such inverse
	cannot be computed (because the original matrix is singular), a bang
	is output through the right outlet. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, power, compute, calculate, raise, exponent, multiplication, number, integer, square

	@seealso
	bach.mtimes, bach.expr, pow, expr, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output power of incoming matrix
// @description The power of the incoming matrix is calculated and output.
// The exponent is taken from the right inlet (or from the argument). If such exponent is negative
// and the incoming matrix admits no inverse, the power cannot be computed: in this case a bang
// is sent through the right outlet. Such bang is also sent in case the incoming matrix is not
// square or not well-formed. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output result
// @description Outputs the result of the operation with the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix
// @in 1 @type int @digest The integer exponent


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The power of the incoming matrix
// @out 1 @type bang @digest bang if power could not be computed


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name exponent @optional 1 @type int @digest Exponent  
// @description The integer exponent to which the incoming matrix is raised. 
// Negative exponents are allowed too, corresponding to powers of the inverse.
// If no argument is introduced, the default is 1.
