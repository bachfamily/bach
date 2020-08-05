/*
 *  unpacknote.c
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
	unpacknote.c
	
	@name 
	bach.unpacknote
	
	@realname 
	bach.unpacknote

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Separate note parameters from playout syntax
	
	@description
	Separates the note parameters coming from
	the playout of a <o>bach.roll</o> or <o>bach.score</o>.
	
	@discussion

	@status
	deprecated

	@category
	bach, bach abstractions, bach notation

	@keywords
	unpack, separate, playout, parameter, cent, duration, pitch, velocity, MIDI, channel, 
	slot, pitch breakpoint, enharmonicity, graphic, tie, start, articulation
	
	@seealso
	bach.playkeys, bach.roll, bach.score, bach.ezmidiplay, Brother John, The Gift Of Synthesis
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Separate note parameters
// @description An incoming llll is expected to be in playout syntax, i.e. the syntax according
// to which <o>bach.roll</o> and <o>bach.score</o> output note and chord data from their playout.
// When such llll is received, its parameters are separately output through the outlets, which
// are respectively (left-to-right): pitch (in midicents), velocity, 
// duration (always in milliseconds), tie? (1 if the note starts a tie, 0 otherwise), 
// graphic enharmonicity data, pitch breakpoints, slots, 
// midichannel, articulations. As usual, information is output right-to-left, so articulations
// are output first, and pitch is output last. See below to know more about playout syntax
// in <o>bach.roll</o> and <o>bach.score</o>. <br /> <br />
// @copy BACH_DOC_PLAYOUT_SYNTAX_ROLL
// @copy BACH_DOC_PLAYOUT_SYNTAX_SCORE

// @method bang @digest Send note parameters
// @description A <m>bang</m> sends the parameter concerning the most recently received input llll.


// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "nullmode", 0, t_unpacknote, nullmode); 
CLASS_ATTR_STYLE_LABEL(c,"nullmode",0,"onoff","Send null Pitch Breakpoints Instead Of Trivial Ones");
CLASS_ATTR_BASIC(c,"nullmode",0);
// @description The <m>nullmode</m> attribute handles the case when a note has only trivial pitch breakpoints
// (note head, note tail, without any glissando). If <m>nullmode</m> is 1, <b>null</b> is output from the 
// pitch breakpoints outlet; if <m>nullmode</m> is 0 (default), the trivial 
// breakpoints <b>[0. 0. 0.] [1. 0. 0.]</b> are output instead, or <b>[0. 0. 0. <m>vel</m>] [1. 0. 0. <m>vel</m>]</b>
// if <m>breakpointshavevelocity</m> is set to 1 (with <m>vel</m> being the note velocity).

CLASS_ATTR_CHAR(c, "extras", 0, t_unpacknote, extras); 
CLASS_ATTR_STYLE_LABEL(c,"extras",0,"onoff","Send Extras Information");
CLASS_ATTR_BASIC(c,"extras",0);
// @description If the <m>extras</m> attribute is set to 0 all the information about extras
// (breakpoints, graphic representation and enharmonicity, slots, articulations) is not output from the corresponding outlets,
// which can be useful to optimize CPU activity. By default, the attribute is set to 1, and all the information is properly output.

CLASS_ATTR_CHAR(c, "breakpointshavevelocity", 0, t_unpacknote, breakpointshavevelocity); 
CLASS_ATTR_STYLE_LABEL(c,"breakpointshavevelocity",0,"onoff","Breakpoints Have Velocity");
// @description If the <m>breakpointshavevelocity</m> attribute is set to 1, when <m>nullmode</m> is 0 and when a note has 
// no inner pitch breakpoints, the note velocity is output as last element along with the trivial breakpoint data, which thus
// becomes <b>[0. 0. 0. <m>vel</m>] [1. 0. 0. <m>vel</m>]</b>, with <m>vel</m> being the note velocity.


}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll in playout syntax

// ---------------
// OUTLETS
// ---------------

// @out 0 @type float @digest Pitch in midicents
// @out 1 @type int @digest Velocity
// @out 2 @type float @digest Duration in milliseconds
// @out 3 @type llll @digest 1 if the note starts a tie, 0 otherwise
// @out 4 @type llll @digest Graphic extra, enharmonicity
// @out 5 @type llll @digest Pitch breakpoint extra
// @out 6 @type llll @digest Slots extra
// @out 7 @type int @digest Midichannel number
// @out 8 @type llll @digest Articulations extra


// ---------------
// ARGUMENTS
// ---------------

// (none)
