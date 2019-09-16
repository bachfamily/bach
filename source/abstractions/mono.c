/*
 *  mono.c
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
	mono.c
	
	@name 
	bach.mono
	
	@realname 
	bach.mono

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Make <o>bach.roll</o> monophonic
	
	@description
	Turns a generic <o>bach.roll</o> (possibly containing overlapping notes) 
	into a monophonic one, by trimming the note tails if needed.
	
	@discussion
	<o>bach.mono</o> might be useful, for instance, 
	as a preparation for quantization tasks.

	@category
	bach, bach abstractions, bach notation

	@keywords
	monophonic, trim, note, proportional, legato

	@seealso
	bach.roll, bach.quantize
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet is considered as the 
// gathered syntax of the <o>bach.roll</o> to be made monophonic,
// which is usually obtained via <o>bach.roll</o>'s <m>dump</m> message 
// (refer to it for more explainations). Such <o>bach.roll</o> is made
// monophonic, and the gathered syntax of the monophonic <o>bach.roll</o> is
// output from the outlet (ready to be connected with the left inlet
// of a <o>bach.roll</o>). <br />
// An llll in the second inlet is considered to be a list of 0's and 1's, one
// element for each voice, with 0 meaning: voice must not be made monophonic, and 
// 1 meaning: voice must be made monophonic. If no such list is provided, 
// all voices are made monophonic (default). If less integers than the number
// of voices are given, the last one is padded.

// @method bang @digest Output result
// @description Performs the operation on the most recently received input lllls.


// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "resume", 0, t_mono, resume); 
CLASS_ATTR_STYLE_LABEL(c,"resume",0,"text","Resume Notes");
CLASS_ATTR_BASIC(c,"resume",0);
// @description Toggles the ability to resume notes which had been trimmed, when possible.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing the gathered syntax of the original <o>bach.roll</o>
// @in 1 @type llll @digest Voices to be made monophonic (list of 0's and 1's) 
// @description This optional lists sets the voices to be made monophonic
// (see <m>llll</m> method).

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing the gathered syntax of the monophonic <o>bach.roll</o>


// ---------------
// ARGUMENTS
// ---------------

// (none)
