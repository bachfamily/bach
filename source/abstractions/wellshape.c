/*
 *  wellshape.c
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
	wellshape.c
	
	@name 
	bach.wellshape
	
	@realname 
	bach.wellshape

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Force matrix to be properly rectangular	
	
	@description
	Pads the rows of an incoming matrix, in order to
	have it properly rectangular (thus well-shaped). 
	It wraps elements too, if needed.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	well-shaped, row, column, number, matrix, rectangle, wrap, force, constraint
	
	@seealso
	bach.minfo, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet is interpreted as the matrix
// which needs to be made properly rectangular. Such matrix is thus put in
// rectangular shape (possibly with a given number of rows and columns,
// if the attributes <m>numrows</m> and <m>numcols</m> are set to an integer)
// and then output. <br />
// An llll in the second inlet sets instead the padding element, which will
// be used to fill any defective line while performing the rectangularization
// (see the <m>padelem</m> argument).

// @method bang @digest Output well-shaped matrix
// @description Forces the most recently received input matrix 
// to be properly rectangular


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_ATOM(c, "numrows", 0, t_wellshape, numrows); 
CLASS_ATTR_STYLE_LABEL(c,"numrows",0,"text","Number Of Rows");
CLASS_ATTR_BASIC(c,"numrows",0);
// @description Sets the number of rows of the output matrix. Leave "none"
// to autodetect (default).

CLASS_ATTR_ATOM(c, "numcols", 0, t_wellshape, numcols); 
CLASS_ATTR_STYLE_LABEL(c,"numcols",0,"text","Number Of Columns");
CLASS_ATTR_BASIC(c,"numcols",0);
// @description Sets the number of columns of the output matrix. Leave "none"
// to autodetect (default).

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix to be made properly rectangular 
// @in 1 @type number/symbol/llll @digest The padding element
// @description An llll in the second inlet sets instead the padding element, which will
// be used to fill any defective line while performing the rectangularization.
// (see the <m>padelem</m> argument).

// ---------------
// OUTLETS
// ---------------

// @out 1 @type llll @digest The matrix made properly rectangular



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name padelem @optional 1 @type llll @digest Padding element
// @description The padding element is the element used to 
// to fill any defective line while performing the rectangularization.
// This is usually a single atom (number or symbol), but can also be a complex
// llll, provided that it has length 1. For instance <b>[12 13]</b> is fine, whereas
// if one puts <b>12 13</b> only the first number will be accounted for.
// By default this is 0.

// @arg 1 @name numrows @optional 1 @type int/none @digest Number of rows
// @description The number of rows of the output matrix, or "none" (default) to autodetect.

// @arg 2 @name numcols @optional 1 @type int/none @digest Number of columns
// @description The number of columns of the output matrix, or "none" (default) to autodetect.
