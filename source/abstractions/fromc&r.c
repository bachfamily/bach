/*
 *  fromc&r.c
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
	fromc&r.c
	
	@name 
	bach.fromc&r
	
	@realname 
	bach.fromc&r

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Reassemble non-rest and rest elements
	
	@description
	Accepts an llll of element corresponding to chords,
	an llll of elements corresponding to rests, and an llll corresponding to the 
	position of rests, and interlaces the two lists properly. This is typically
	used in combination with <o>bach.toc&amp;r</o>.
	
	@discussion
	<o>bach.fromc&amp;r</o> is especially useful in combination with  <o>bach.toc&amp;r</o>
	in order to perform different operations on the set of elements corresponding
	to rests and to non-rests.

	@category
	bach, bach abstractions, bach notation

	@keywords
	chord, rest, convert, assemble, position, index

	@seealso
	bach.toc&amp;r, bach.insert, bach.chordrot, bach.chordrev, bach.restrot, bach.score, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet sets the llll corresponding to non-rest elements
// and outputs the interlaced result. An llll in the second inlet sets the llll corresponding
// to rest elements. An llll in the third inlet is expected to be a plain list the original 
// indices of each rest element (positions for the reinsertion). This latter is usually
// directly retrieved via the third outlet of <o>bach.toc&amp;r</o>

// @method bang @digest Reassemble elements
// @description Performs the reassembling on most recently received input lllls.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll of elements corresponding to non-rests
// @in 1 @type llll @digest The llll of elements corresponding to rests
// @in 2 @type llll @digest The original indices of the rest elements

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The reassembled llll


// ---------------
// ARGUMENTS
// ---------------

