/*
 *  score2roll.c
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
	score2roll.c
	
	@name 
	bach.score2roll
	
	@realname 
	bach.score2roll

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a <o>bach.score</o> into a <o>bach.roll</o>
	
	@description
	Converts a <o>bach.score</o> object into 
	a <o>bach.roll</o> object containing the exact same content, only
	in proportional notation, also preserving markers.
	
	@discussion
	The inverse task is less immediate and is performed via <o>bach.quantize</o>.

	@category
	bach, bach abstractions, bach notation

	@keywords
	proportional, measured, classical, convert, score
	
	@seealso
	bach.roll, bach.score, bach.quantize
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert and output <o>bach.roll</o> gathered syntax
// @description An llll in the first inlet is considered as the 
// llll obtained in the first outlet of a <o>bach.score</o> when a <m>score2roll</m>
// message is sent: the content of the <o>bach.score</o> is thus converted into
// the gathered syntax of a <o>bach.roll</o> having the same content (only in proportional notation).
// Such gathered syntax is output from the outlet, ready to be connected with the left inlet
// of a <o>bach.roll</o>.

// @method bang @digest Perform conversion
// @description Performs the conversion on the most recently received input llll.


// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll obtained from <o>bach.score</o>'s first outlet when sending a <m>score2roll</m> message

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing the gathered syntax of the converted <o>bach.roll</o>


// ---------------
// ARGUMENTS
// ---------------

// (none)
