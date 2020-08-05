/*
 *  slot2filtercoeff.c
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
	slot2filtercoeff.c
	
	@name 
	bach.slot2filtercoeff
	
	@realname 
	bach.slot2filtercoeff

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a dynfilter-slot content into messages to drive <o>filtercoeff~</o>
	
	@description
	Converts the llll content of a given slot,
	of type "dynfilter", into a list of messages for <o>line~</o> objects, which
	will be used to drive a <o>filtercoeff~</o>, according to the slot content.
	
	@discussion

	@category
	bach, bach abstractions, bach notation

	@keywords
	slot, filter, sequence, convert, filtercoeff~

	@seealso
	bach.slot2curve, bach.slot2line, filtercoeff~, biquad~, bach.roll, bach.score, bach.slot
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set slot content, set default
// @description An llll in the second inlet is considered as the dynfilter slot content.
// Typically this is obtained from <o>bach.playkeys</o>'s slot outlets. 
// See below for the precise syntax of the slot content (for <o>bach.slot2filtercoeff</o> only 
// syntax for dynfilter slots is relevant). <br /> 
// An llll in the third inlet is expected to contain a triplet of default frequency (in Hertz),
// default gain (linear, as amplitude) and a Q or S parameter. Those will be used when no content is
// defined in the slot.
// <br />
// @copy BACH_DOC_NOTE_SLOT_CONTENT

// @method float @digest Set duration and output messages
// @description A floating point number in the first inlet is considered as the overall duration of 
// the function, and will trigger the output of the conversion of the slot content into messages 
// for <o>line~</o> objects, which will drive the <o>filtercoeff~</o> object. 
// The second outlet outputs the line messages for the frequency 
// (the output of this <o>line~</o> object should be sent in the first inlet of <o>filtercoeff~</o>); 
// the third outlet outputs the line messages for the gain
// (the output of this <o>line~</o> object should be sent in the second inlet of <o>filtercoeff~</o>); 
// the fourth outlet outputs the line messages for the Q or slope
// (the output of this <o>line~</o> object should be sent in the third inlet of <o>filtercoeff~</o>).
// Also, the symbol representing the filter type is output from the first outlet (which should
// be sent into the first inlet of <o>filtercoeff~</o>. <br />

// @method bang @digest Output messages
// @description Outputs messages (as for the <m>float</m> message), based on the most recently received input data.


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
// @in 2 @type llll @digest The default values of frequency, gain and Q or S 

// ---------------
// OUTLETS
// ---------------

// @out 0 @type symbol @digest The symbol of the filter type 
// @description This symbol should be sent into the first inlet of <o>filtercoeff~</o>.

// @out 1 @type llll @digest The line messages concerning cutoff frequency  
// @description These messages should be sent into a <o>line~</o> object which will be connected
// to the first inlet of <o>filtercoeff~</o>, and will drive the cutoff frequency (in Hertz).

// @out 2 @type llll @digest The line messages concerning gain  
// @description These messages should be sent into a <o>line~</o> object which will be connected
// to the second inlet of <o>filtercoeff~</o>, and will drive the gain (linear, as amplitude).

// @out 3 @type llll @digest The line messages concerning Q or S  
// @description These messages should be sent into a <o>line~</o> object which will be connected
// to the third inlet of <o>filtercoeff~</o>, and will drive the Q or S parameters.


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name default_filtertype @optional 1 @type symbol @digest Default filter type
// @description First optional argument is a symbol which sets the initial filter type, which will be used if no content is
// defined in the slot.

// @arg 1 @name default_cutoff_freq @optional 1 @type float @digest Default cutoff frequency 
// @description Second optional argument sets the initial cutoff frequency (in Hz), which will be used if no content is
// defined in the slot.

// @arg 2 @name default_gain @optional 1 @type float @digest Default gain 
// @description Third optional argument sets the initial gain (in dB), which will be used if no content is
// defined in the slot.

// @arg 3 @name default_Q @optional 1 @type float @digest Default Q or S
// @description Fourth optional argument sets the initial Q or S parameter, which will be used if no content is
// defined in the slot.
