/*
 *  bitdecode.c
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
	bitdecode.c
	
	@name 
	bach.bitdecode
	
	@realname 
	bach.bitdecode

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Decode a bit field
	
	@description
	Tells which bits are on in a given integer.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	bit field, decode, integer, number

	@seealso
	bach.is, bach.contains
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Output active bits
// @description For each incoming number, the list of 0-based indices
// of the bits which are on (if any) is collected and output through the
// outlet. For instance, the number <b>9</b> will trigger the output of
// <b>0 3</b>, since the first and fourth bits are on.
// Notice that when the <b>0</b> number is input, nothing happens.
// Also, incidentally, <b>-1</b> will trigger the output of all 32 or 64
// bits (depending if Max is running in 32- or 64-bit mode).

// @method bang @digest Output result
// @description Outputs the active bits of the most recently received input number.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}

// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The number whose bits must be decoded



// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest Indices of active bits
// @description The output list contains the 0-based indices of 
// the bits which are on in the incoming integer.



// ---------------
// ARGUMENTS
// ---------------

// (none)
