/*
 *  m2jitcellblock.c
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
	m2jitcellblock.c
	
	@name 
	bach.m2jitcellblock
	
	@realname 
	bach.m2jitcellblock

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Display the content of an llll matrix in a jit.cellblock
	
	@description
	Shows the content of an llll matrix in the <o>jit.cellblock</o> object.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, display, convert, cell, jit.cellblock

	@seealso
	jit.cellblock, bach.m2matrixctrl, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert llll matrix to jit.cellblock 
// @description The needed information to fill a <o>jit.cellblock</o> with the incoming matrix is output. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Build jit.cellblock
// @description Fills a <o>jit.cellblock</o> with the most recently input matrix.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

CLASS_ATTR_LONG(c, "unwrap", 0, t_m2jitcellblock, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"text","Unwrap");
CLASS_ATTR_BASIC(c,"unwrap",0);
// @description If the <m>unwrap</m> attribute is set to 1, every llll in each
// cell is flattened by its outmost level of parenthesis. Default is 0.

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest Messages for jit.cellblock



// ---------------
// ARGUMENTS
// ---------------

// (none)
