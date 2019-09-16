/*
 *  matrixctrl2m.c
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
	matrixctrl2m.c
	
	@name 
	bach.matrixctrl2m
	
	@realname 
	bach.matrixctrl2m

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a matrixctrl object into an llll matrix	
	
	@description
	Converts the information contained in a 
	<o>matrixctrl</o> into an llll matrix.
	
	@discussion
	In order to perform the conversion, the right outlet of
	<o>bach.matrixctrl2m</o> has to be connected with the inlet 
	of <o>matrixctrl</o>, and the right outlet of <o>matrixctrl</o>
	has to be connected with the right inlet of <o>bach.matrixctrl2m</o>. <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, matrixctrl, convert

	@seealso
	matrixctrl, bach.m2matrixctrl, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method list @digest Messages from matrixctrl's right outlet 
// @description A list in the second inlet is expected to contain
// all the messages coming from <o>matrixctrl</o>'s right outlet. Just connect
// <o>matrixctrl</o>'s right outlet with <o>bach.matrixctrl2m</o>'s right inlet

// @method bang @digest Perform conversion
// @description Performs the conversion on the most recently received input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type bang @digest bang to perform conversion
// @in 1 @type list @digest Messages from matrixctrl's right outlet
// @description <o>matrixctrl</o>'s right outlet must be connected with 
// <o>bach.matrixctrl2m</o>'s right inlet.

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Converted matrix in llll form
// @out 1 @type list @digest Messages for matrixctrl's inlet
// @description <o>bach.matrixctrl2m</o>'s right outlet must be connected with 
// <o>matrixctrl</o>'s inlet.



// ---------------
// ARGUMENTS
// ---------------

// (none)
