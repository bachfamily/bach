/*
 *  toc&r.c
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
	toc&r.c
	
	@name 
	bach.toc&r
	
	@realname 
	bach.toc&r

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Route non-rest and rest elements
	
	@description
	Accepts an llll of elements and an llll of reference durations:
	the element of the former corresponding to non-negative reference durations 
	(non-rest elements) are output from the first outlet, while the ones corresponding
	to negative reference durations (rest elements) are output from the second outlet.
	Third outlet outputs the position of rest element, for a future reassembling of 
	the llll via <o>bach.fromc&amp;r</o>.
	
	@discussion
	<o>bach.toc&amp;r</o> is especially useful in combination with <o>bach.fromc&amp;r</o>
	in order to perform different operations on the set of elements corresponding
	to rests and to non-rests.

	@category
	bach, bach abstractions, bach notation

	@keywords
	chord, rest, convert, route, divide, split, position, index

	@seealso
	bach.fromc&amp;r, bach.insert, bach.chordrot, bach.chordrev, bach.restrot bach.score, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set llll or reference durations llll, output result
// @description An llll in the first inlet is considered as the llll containing the elements to route.
// Unless the <m>triggers</m> attribute is set to 2, this also outputs the result:
// the indices of elements corresponding to negative durations in the reference durations llll are output
// from the third outlet; the elements situated in the same position of negative elements of the reference
// durations llll are collected and output from the second outlet; finally the elements situated in the same 
// position of non-negative elements of the reference durations llll are collected and output from the first
// outlet. <br />
// An llll in the second inlet sets the reference durations llll. If the <m>triggers</m> attribute
// is 2, it also triggers the output of the results (see above). <br />
// The two lllls must have the same structure, and can either be plain lllls, or lists of plain
// lllls, in which case they are considered as being one list for each voice.

// @method bang @digest Output position indices and routed lllls
// @description Outputs the results (see the <m>llll</m> method) based on most recently received input lllls.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "triggers", 0, t_chordrot, triggers); 
CLASS_ATTR_STYLE_LABEL(c,"triggers",0,"text","Triggers");
CLASS_ATTR_BASIC(c,"triggers",0);
// @description Index of the inlet triggering the output; this can be
// 0, 1 or 2 (0 meaning: all inlets; the default is 1: left inlet).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll of elements
// @in 1 @type llll @digest The reference durations llll

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The elements corresponding to non-negative durations (non-rest elements)
// @out 1 @type llll @digest The elements corresponding to negative durations (rest elements)
// @out 2 @type llll @digest Indices of rest elements for future reinsertion


// ---------------
// ARGUMENTS
// ---------------

