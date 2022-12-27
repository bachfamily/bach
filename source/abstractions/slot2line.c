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
	slot2line.c
	
	@name 
	bach.slot2line
	
	@realname 
	bach.slot2line

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a function-slot content into messages for <o>line~</o>
	
	@description
	Converts the llll content of a given slot,
	of type "function", into a list of messages for <o>line~</o>.
	Slopes of slot segments are ignored.
	
	@discussion

	@category
	bach, bach abstractions, bach notation

	@keywords
	slot, breakpoint function, line, line~, convert

	@seealso
	line~, bach.slot2curve, bach.roll, bach.score, bach.slot
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set slot content
// @description An llll in the second inlet is considered as the function slot content.
// Typically this is obtained from <o>bach.playkeys</o>'s slots outlets. 
// See below for the precise syntax of the slot content (for <o>bach.slot2line</o> only 
// syntax for function slots is relevant). <br />
// An llll in the fourth (lambda) inlet is considered as a floating point number in llll native form
// (see <m>float</m> message for more information).
// <br /> <br />
// @copy BACH_DOC_NOTE_SLOT_CONTENT

// @method float @digest Function depends on inlet
// @description A floating point number in the first inlet is considered as the overall duration of the function,
// and will trigger the output of the conversion of the slot content into messages for <o>line~</o>, 
// output from the first outlet. <br /> 
// A floating point number in the third inlet sets a default value which will be 
// sent to <o>line~</o> if no function is defined in the incoming slot (slot content is empty). <br />
// A floating point number in the fourth inlet is the answer of a lambda loop, allowing to remap function amplitudes. 
// This is handy, for instance, if you had a function slot representing amplitudes in decibels, and you need to convert
// them into linear amplitude representation in order to send them to <o>line~</o>.
// Indeed, fourth inlet is a lambda inlet. <br /> 
// @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// @method bang @digest Output messages
// @description Outputs messages for <o>line~</o>, based on the most recently received input data.

// @method milliseconds @digest Convert Slot in Milliseconds Mode
// @description A <m>milliseconds</m> message in the first inlet will consider
// the slot information coming from the second inlet as a slot in "Milliseconds"
// temporal mode (see <m>temporalmode</m> specification of the slotinfo),
// and will trigger the output of the conversion of the slot content into messages for <o>line~</o>, 
// output from the first outlet. <br /> 



// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type float @digest The duration of the function in milliseconds
// @in 1 @type llll @digest The llll containing the function slot content
// @in 2 @type float @digest The default value
// @in 3 @type float/llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest The messages for <o>line~</o>
// @out 1 @type llll @digest Lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION

// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name default_value @optional 1 @type float @digest Default value  
// @description A floating point number given as argument sets a default value which will be 
// sent to <o>line~</o> if no function is defined in the incoming slot (slot content is empty).
