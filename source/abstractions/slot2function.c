/*
 *  slot2function.c
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
	slot2function.c
	
	@name 
	bach.slot2function
	
	@realname 
	bach.slot2function

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a function-slot content into a <o>function</o> object
	
	@description
	Converts the llll content of a given slot,
	of type "function", into a list of messages in order to build
	a Max <o>function</o> object accordingly. Slopes of slot segments are ignored.
	
	@discussion

	@category
	bach, bach abstractions, bach notation

	@keywords
	slot, breakpoint function, function, convert

	@seealso
	function, bach.slot2line, bach.slot2curve, bach.roll, bach.score, bach.slot
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set slot content, output messages, set slotinfo
// @description An llll in the first inlet is considered as the function slot content, and
// will also trigger the output of the proper messages for the <o>function</o> object,
// in order for it to contain the same function which was in the function slot.
// Typically the function slot content is obtained from <o>bach.playkeys</o>'s slot outlets. 
// See below for the precise syntax of the slot content (for <o>bach.slot2function</o> only 
// syntax for function slots is relevant). <br />
// An llll in the second inlet is, optionally, the slotinfo concerning the incoming slot content.
// This information is handy in order to precisely know the range and domain of the slot, and to adapt the domain
// and range of the <o>function</o> obejct accordingly. What is expected is the slotinfo only regarding
// one specific slot, or even just the two specifications of <b>range</b> and <b>domain</b> (see below
// to know more about the general slotinfo syntax: for <o>bach.slot2function</o> you need to only send a single
// <b>[<m>slot_num</m> <m>SPECIFICATIONS</m>]</b> specification.) <br /> <br />
// @copy BACH_DOC_NOTE_SLOT_CONTENT
// @copy BACH_DOC_SLOTINFO_SYNTAX


// @method bang @digest Output messages
// @description Outputs messages for <o>function</o>, based on the most recently received input data.


// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

// (none)

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing the function slot content
// @in 1 @type llll @digest The llll containing the slotinfo for the single slot

// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest The messages for <o>function</o>

// ---------------
// ARGUMENTS
// ---------------

// (none)
