/*
 *  im.c
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
	im.c
	
	@name 
	bach.im
	
	@realname 
	bach.im

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the image of a matrix
	
	@description
	Finds the image of an incoming matrix A, i.e. its column span. 
	
	@discussion
	<o>bach.im</o> is just a little wrapper for a <o>bach.trans</o> and <o>bach.extractbasis</o>. <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, image, column, span, basis, extract, rank

	@seealso
	bach.ker, bach.extractbasis, bach.trans, bach.gausselim, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output image of incoming matrix
// @description The image is output as a basis for it (a minimal list of
// spanning vectors), listed "by rows" (so a list of lists, each of the latter
// being one vector). A <b>null</b> is output if image is empty.<br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output image
// @description Outputs the image of the most recently input matrix (if any).


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);


CLASS_ATTR_LONG(c, "makeorthogonal", 0, t_im, makeorthogonal); 
CLASS_ATTR_STYLE_LABEL(c,"makeorthogonal",0,"onoff","Make Orthogonal");
CLASS_ATTR_BASIC(c,"makeorthogonal",0);
// @description Toggles the orthogonalization of the spanning vectors of the image.
// If this is 1, spanning vectors are made orthogonal via Gram-Schmidt algorithm.


CLASS_ATTR_LONG(c, "makeunitary", 0, t_im, makeunitary); 
CLASS_ATTR_STYLE_LABEL(c,"makeunitary",0,"onoff","Make Unitary");
CLASS_ATTR_BASIC(c,"makeunitary",0);
// @description Toggles the normalization of the spanning vectors of the image.
// If this is 1, spanning vectors are made unitary (having euclidean norm 1).

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The image of the matrix
// @description The image is output as a minimal list of its spanning vectors (listed thus "by rows").
// If the image is empty, <m>null</m> is output.


// ---------------
// ARGUMENTS
// ---------------

// (none)
