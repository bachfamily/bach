/*
 *  tierev.c
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
	tierev.c
	
	@name 
	bach.tierev
	
	@realname 
	bach.tierev

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Reverse a sequence of ties
	
	@description
	Accepts in its left inlet an llll of pitches, in its right inlet an llll ties,
	and properly reverses the tie sequence.<br />
	
	@discussion
	<o>bach.tierev</o> accepts either a chord-wise sequence of pitches and ties, 
	or a voice-wise lllls of chords. It won't accept measure-syntaxed lllls: if you want to use it
	on more than one measure, make use of <o>bach.beatunbox</o>.

	@category
	bach, bach abstractions, bach notation

	@keywords
	reverse, tie, sequence, chord, pitch, voice
	
	@seealso
	bach.chordrev, bach.chordrot, bach.restrot, bach.fromc&amp;r, bach.toc&amp;r, bach.score, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set reference pitches or ties llll, output result
// @description An llll in the first inlet is considered as the llll containing pitches (in midicents),
// and will reverse the ties llll and output the result. <br />
// An llll in the second inlet is considered as the llll containing tie information, structured exactly
// as pitches llll (1 for notes starting a tie, 0 otherwise). Such ties llll will be the one to be
// reversed and output when the reference pitches llll is received in the first inlet. <br />
// The two lllls must have the same structure, and can either be chord-wise lllls (one list for each chord, 
// one element for each note), or voice-wise lllls (one list for each voice, one list for each chord,
// one element for each note).

// @method bang @digest Reverse the ties llll
// @description Performs the operation on most recently received input lllls.


// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing reference pitches
// @in 1 @type llll @digest The llll containing ties information

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The properly reversed ties llll


// ---------------
// ARGUMENTS
// ---------------

// (none)
