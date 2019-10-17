/*
 *  idmatrix.c
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
	idmatrix.c
	
	@name 
	bach.idmatrix
	
	@realname 
	bach.idmatrix

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Build identity matrix
	
	@description
	Builds the identity square matrix of a given size. 
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus
	
	@keywords
	matrix, identity, build, square, size
	
	@seealso
	bach.idvector, bach.minfo, bach.diag, bach.mrandom, bach.wellshape, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Build the identity matrix of the incoming size
// @description The identity matrix having as size the incoming integer is built.

// @method bang @digest Build the identity matrix
// @description Builds the identity matrix with the most recently input size.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The size of the matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The built identity matrix



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name size @optional 1 @type int @digest Size  
// @description The size of the identity matrix to be built.
