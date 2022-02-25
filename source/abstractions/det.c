/*
 *  det.c
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
	det.c
	
	@name 
	bach.det
	
	@realname 
	bach.det

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the determinant of a matrix
	
	@description
	Computes the determinant of the incoming matrix. <br />
	For non-square matrices, the product of the pivots is output. 
	
	@discussion
	The determinant of the matrix is computed by Gaussian elimination and then 
	by taking the product of pivots. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	determinant, matrix, calculate, compute, Gauss elimination
	
	@seealso
	bach.trace, bach.gausselim, bach.rank, bach.inv, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output determinant of incoming matrix
// @description The object outputs the determinant of the incoming matrix. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output determinant
// @description Outputs the determinant of the most recently input matrix.


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


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The determinant of the incoming matrix



// ---------------
// ARGUMENTS
// ---------------

// (none)
