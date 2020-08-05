/*
 *  sliceheader.c
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
	sliceheader.c
	
	@name 
	bach.sliceheader
	
	@realname 
	bach.sliceheader

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Separate header and body of a gathered syntax
	
	@description
	Takes the gathered syntax of a notation object and separates the
	header part (containing meta-information about the score) and the body part (containing
	the actual content).
	
	@discussion
	@copy BACH_DOC_GENERIC_GATHERED_SYNTAX

	@category
	bach, bach abstractions, bach notation

	@keywords
	header, information, slice, separate, body, gathered syntax, content, split, retrieve
	
	@seealso
	bach.roll, bach.score, bach.slice
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Separate header and body of gathered syntax
// @description An llll in the first inlet is considered as the 
// gathered syntax of a notation object: its header and body parts are separated, and output
// respectively from the first and second outlets (in right-to-left order, as usual).
// The header part also incorporates the notation object routing symbol (such as <b>roll</b> or
// <b>score</b>), which is a slight abuse, since strictly speaking it is not part of the header.
// <br /> <br />
// @copy BACH_DOC_GENERIC_GATHERED_SYNTAX


// @method bang @digest Separate header and body
// @description Separates header and body of the most recently received input llll.


// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing the gathered syntax of the notation object

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing the header of the notation object (and routing symbol, if any)
// @out 1 @type llll @digest The llll containing the body of the notation object


// ---------------
// ARGUMENTS
// ---------------

// (none)
