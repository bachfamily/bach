/*
 *  ker.c
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
	ker.c
	
	@name 
	bach.ker
	
	@realname 
	bach.ker

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the kernel of a matrix
	
	@description
	Finds the kernel of an incoming matrix, 
	i.e. the set of vectors which are sent to 0 by the matrix multiplication.

	@discussion
	<o>bach.ker</o> finds the subspace of the vectors x such that Ax = 0, where 
	A is the incoming matrix. If a matrix is m x n, its kernel is a subspace 
	in n-dimensional euclidean space. Such subspace is defined by one of its
	basis, which is indeed output. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	kernel, matrix, nullity, vector, multiplication, extract, basis
	
	@seealso
	bach.im, bach.extractbasis, bach.lienarsolve, bach.gausselim, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output kernel of incoming matrix
// @description The kernel is output as a basis for it (a minimal list of
// spanning vectors), listed "by rows" (so a list of lists, each of the latter
// being one vector). A <b>null</b> is output if kernel is empty.<br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output kernel
// @description Outputs the kernel of the most recently input matrix (if any).


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


CLASS_ATTR_LONG(c, "makeorthogonal", 0, t_ker, makeorthogonal); 
CLASS_ATTR_STYLE_LABEL(c,"makeorthogonal",0,"onoff","Make Orthogonal");
CLASS_ATTR_BASIC(c,"makeorthogonal",0);
// @description Toggles the orthogonalization of the spanning vectors of the kernel.
// If this is 1, spanning vectors are made orthogonal via Gram-Schmidt algorithm.


CLASS_ATTR_LONG(c, "makeunitary", 0, t_ker, makeunitary); 
CLASS_ATTR_STYLE_LABEL(c,"makeunitary",0,"onoff","Make Unitary");
CLASS_ATTR_BASIC(c,"makeunitary",0);
// @description Toggles the normalization of the spanning vectors of the kernel.
// If this is 1, spanning vectors are made unitary (having euclidean norm 1).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The kernel of the matrix
// @description The kernel is output as a minimal list of its spanning vectors (listed thus "by rows").
// If the kernel is empty, <m>null</m> is output.


// ---------------
// ARGUMENTS
// ---------------

// (none)
