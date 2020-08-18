/*
 *  getcol.c
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
	getcol.c
	
	@name 
	bach.getcol
	
	@realname 
	bach.getcol

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Get a column of a matrix
	
	@description
	Extracts a column of a matrix in llll form.
	
	@discussion

	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	column, matrix, extract, pick
	
	@seealso
	bach.getrow, bach.submatrix, bach.nth, bach.trans, bach.minfo
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set matrix and output requested column
// @description An llll in the first is interpreted as the matrix whose column has to be extracted.
// Such column is then output from the outlet.

// @method int @digest Set column index
// @description An integer in the second inlet sets the index of the column
// which has to be extracted (1 being the first column, 2 being the second, and so on).

// @method bang @digest Output column
// @description Performs the extraction on most recently received input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix in llll form
// @in 1 @type int @digest The index of the column

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The extracted column


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name column-index @optional 1 @type int @digest Column index
// @description The optional integer argument sets the column index.
