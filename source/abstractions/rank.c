/*
 *  rank.c
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
	rank.c
	
	@name 
	bach.rank
	
	@realname 
	bach.rank

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the rank of a matrix
	
	@description
	Computes the rank of the incoming matrix.
	
	@discussion
	The determinant of the matrix is computed by Gaussian elimination and then 
	by counting the number of pivots. By convention the rank of <b>null</b> is -1 and
	the rank of <b>[]</b> is 0. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	rank, calculate, compute, Gauss elimination, linear independence, matrix
	
	@seealso
	bach.gausselim, bach.det, bach.inv, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output rank of incoming matrix
// @description The object outputs the rank of the incoming matrix. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output rank
// @description Outputs the rank of the most recently input matrix.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest The rank of the incoming matrix



// ---------------
// ARGUMENTS
// ---------------

// (none)
