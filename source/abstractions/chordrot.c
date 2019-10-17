/*
 *  chordrot.c
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
	chordrot.c
	
	@name 
	bach.chordrot
	
	@realname 
	bach.chordrot

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Rotate the non-rest elements of an llll
	
	@description
	Accepts an llll to rotate, an llll of reference durations,
	and rotates only the elements of the left llll corresponding to non-negative elements in the 
	durations llll.<br />
	
	@discussion
	<o>bach.chordrot</o> is especially useful to perform taleas and rotate parameters like cents,
	velocities or extras, without affecting the elements corresponding to rests. <br />
	<o>bach.chordrot</o> also accepts lllls of depth 2, considering them to be a list for each voice,
	and operates accordingly.

	@category
	bach, bach abstractions, bach notation

	@keywords
	chord, rotate, talea, sequence

	@seealso
	bach.restrot, bach.chordrev, bach.tierev, bach.fromc&amp;r, bach.toc&amp;r, bach.score, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set llll or reference durations llll, output result
// @description An llll in the first inlet is considered as the llll containing the parameter data
// to rotate: its elements situated in the same position of non negative elements of the reference durations llll are thus 
// rotated of a certain amount of steps (set by the <m>shift</m> attribute or by the argument),
// and the result is output (unless the <m>triggers</m> attribute is set to 2). 
// The elements corresponding to negative durations are left untouched. <br />
// An llll in the second inlet sets the reference durations llll. If the <m>triggers</m> attribute
// is 2, it also triggers the output of the rotation. <br />
// The two lllls must have the same structure, and can either be plain lllls, or lists of plain
// lllls, in which case they are considered as being one list for each voice.

// @method bang @digest Rotate non-rest elements
// @description Performs the rotation on most recently received input lllls.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "shift", 0, t_chordrot, shift); 
CLASS_ATTR_STYLE_LABEL(c,"shift",0,"text","Shift");
CLASS_ATTR_BASIC(c,"shift",0);
// @description Number of steps to rotate the llll of (ignoring rest elements). 
// Positive numbers rotate left, negative numbers rotate right.

CLASS_ATTR_LONG(c, "triggers", 0, t_chordrot, triggers); 
CLASS_ATTR_STYLE_LABEL(c,"triggers",0,"text","Triggers");
CLASS_ATTR_BASIC(c,"triggers",0);
// @description Index of the inlet triggering the output; this can be
// 0, 1 or 2 (0 meaning: all inlets; the default is 1: left inlet).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to rotate
// @in 1 @type llll @digest The reference durations llll

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The rotated llll


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name shift @optional 1 @type int @digest Shift  
// @description Number of steps to rotate the llll of (ignoring rest elements). 
// Positive numbers rotate left, negative numbers rotate right.
