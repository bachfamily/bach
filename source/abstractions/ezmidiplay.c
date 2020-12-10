/*
 *  ezmidiplay.c
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
	ezmidiplay.c
	
	@name 
	bach.ezmidiplay
	
	@realname 
	bach.ezmidiplay

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quick way to play MIDI
	
	@description
	Converts the data coming from the playout of <o>bach.roll</o> or 
	<o>bach.score</o> into a MIDI stream, and plays it.
	
	@discussion
	
	@category
	bach, bach abstractions, bach notation

	@keywords
	MIDI, play, playout, stream, noteon, noteoff

	@seealso
	bach.roll, bach.score, bach.playkeys, makenote, noteout, Brother John, The Gift Of Synthesis
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert into MIDI data and play
// @description <o>bach.ezmidiplay</o> expects the lllls coming from the playout of a <o>bach.roll</o>
// or <o>bach.score</o> (standard plain <o>noteout</o> syntax is also accepted, provided that pitch is given
// in MIDIcents; refer to the <m>list</m> message to know more).
// It will convert such syntax them in MIDI triplets with <b><m>MIDI_note</m> <m>velocity</m> <m>MIDI_channel</m></b>, 
// and then  plays them as MIDI (it contains a <o>noteout</o> inside it), unless the <m>noteout</m> attribute is 
// unset. <br />
// The output <m>MIDI_note</m> is not in midicents, but in MIDI values (60 = middle C), the output <m>velocity</m> is the MIDI 
// velocity (0 to 127, 0 being note-off), and the output <m>MIDI_channel</m> is of course the MIDI channel.
// For each note, a note-on and a note-off list is properly output. <br />
// The input expected llll must be formatted in the playout syntax (it is such by default if you link
// the playout of <o>bach.roll</o> or <o>bach.score</o> to the first <o>bach.ezmidiplay</o> inlet). <br /> <br />
// @copy BACH_DOC_PLAYOUT_SYNTAX_ROLL
// @copy BACH_DOC_PLAYOUT_SYNTAX_SCORE


// @method int @digest Set microtonal division, output free MIDI channel number
// @description An integer in the second inlet sets the desired microtonal division. By default this is 
// 2 (semitonal division), but this can be different: in this case, <o>bach.ezmidiplay</o> automatically maps the 
// data on multiple MIDI channels handled with different pitch bend in order to reproduce the microtonal finesse.
// In other words, the object keesp for himself a certain number of channels (which will be affected by the pitch bend), 
// and which thus should not be used by the user. <br />
// When the microtonal division changes (and also at the instantiation) the number of free MIDI channels is 
// output from the second outlet. If the microtonal division is semitonal, this number will be 15, since it doesn't
// count the channel 10, dedicated to percussions. This means that we can use 15 independent channels to play
// semitonal music. Otherwise, the number will represent the number of MIDI channels which were not used to mimic 
// the microtonal instrument. For instance, for quartertonal division (4), this will be 7, since 7 quartertonal channels
// are indeed mapped on 14 real channels; and we could not map 8 of them, since that would yield 16 real channels, whereas
// we just had 15 (not counting percussion channel). Analogously, If we need to play sixth-tonal divisions,
// the number of free channels will be 5 (each channel has to be mapped on 3 channels, 5*3 = 15).

// @method list @digest Send messages to <o>noteout</o>
// @description A list in the first inlet is expected to be in the <o>noteout</o>-like syntax: <b>[<m>pitch</m> <m>velocity</m> <m>MIDIchannel</m>]</b>
// where, on the other hand, the <m>pitch</m> is expected to be in MIDIcents (and not as MIDI number). The velocity must range from 1 to 127,
// a velocity of 0 is considered as a note-off. <br />
// A list in the third inlet is automatically sent to the <o>noteout</o> object contained in the
// abstraction. You might want to use this to define, for instance, the MIDI port. Refer to the <o>noteout</o>
// documentation to know more.

// @method adjustpitchbend @digest Properly assign pitch bend values to MIDI channels
// @description Pitch bend values for MIDI channels are automatically assigned when you introduce the microtonal
// division, and at the object instantiation. Nevertheless, should you touch the pitch bend values elsewhere 
// in the patch, the <m>adjustpitchbend</m> message is a shortcut to set again the pitch bend of each channel 
// to the needed value for the proper microtonal MIDI playing.

// @method clock @digest Select a clock source
// @description The word <m>clock</m>, followed by the name of an existing <m>setclock</m> objects, sets the <o>bach.ezmidiplay</o> 
// object to be controlled by that <m>setclock</m> object rather than by Max's internal millisecond clock. 
// The word <m>clock</m> by itself sets the <o>bach.ezmidiplay</o> object back to using Max's regular millisecond clock.

// @method stop @digest Stop all playing notes
// @description The word <m>stop</m> stops all the currently playing notes.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

CLASS_ATTR_CHAR(c, "noteout", 0, t_ezmidiplay, noteout); 
CLASS_ATTR_STYLE_LABEL(c,"noteout",0,"onoff","Play MIDI notes");
CLASS_ATTR_BASIC(c,"noteout",0);
//	@description If this attribute is set to 0, no MIDI notes are played (the <o>noteout</o> object is unused),
//	and the incoming playout lllls are just converted into MIDI triplets of <b><m>pitch</m> <m>velocity</m> <m>MIDI_channel</m></b> and output.
//  If this attribute is set to 1 (default), MIDI notes are also played.

CLASS_ATTR_CHAR(c, "dataout", 0, t_ezmidiplay, dataout); 
CLASS_ATTR_STYLE_LABEL(c,"dataout",0,"text","Data Output Format");
CLASS_ATTR_BASIC(c,"dataout",0);
//	@description If this attribute is set to 0, nothing is output from the object's first outlet.
// If it is set to 1, the MIDI data is output in the form <b><m>MIDI note</m> <m>velocity</m> <m>MIDI channel</m></b>.
// If it is set to 2, the MIDI note is substituted by the bach MIDIcents, and the MIDI channel is the original channel
// (discarding possible changes due to microtonality).


CLASS_ATTR_LONG(c, "maxpitchbend", 0, t_ezmidiplay, maxpitchbend); 
CLASS_ATTR_STYLE_LABEL(c,"maxpitchbend",0,"text","Maximum Pitch Bend");
//	@description Since microtonal handling uses channels pitch-bending, if you build your own MIDI 
//  instrument, your maximum pitch bend could be different from General MIDI default one 
//  (2 semitones = 200 cents, up or down). You can thus specify via this attribute a maximum pitch bend
//  in cents, so that it is accounted for when creating the multi-channel microtonal instruments
//  (see the <m>int</m> method to know more).

CLASS_ATTR_CHAR(c, "repeatmode", 0, t_ezmidiplay, repeatmode); 
CLASS_ATTR_STYLE_LABEL(c,"repeatmode",0,"enumindex","Repeat Mode");
CLASS_ATTR_ENUMINDEX(c,"repeatmode", 0, "Poly Re-trigger Stop Last"); 
CLASS_ATTR_BASIC(c,"repeatmode",0);
//	@description As for <o>makenote</o>, sets the behavior when a note is retriggered. The modes are: <br />
// - Poly (0, default): There is no pre-specified behavior when you repeat a pitch before the note-off for that pitch has been sent.
// - Re-trigger (1): If a note is still playing when you retrigger it, the object will send a note-off (velocity 0) message to stop the
// first note and then send a new note-on message.
// - Stop Last (2): If a note is still playing when you retrigger it, the object will cancel the scheduled output of the first note -
// only the last played note will send note-off (velocity 0) message.

CLASS_ATTR_DOUBLE(c, "durstretch", 0, t_ezmidiplay, durstretch); 
CLASS_ATTR_STYLE_LABEL(c,"durstretch",0,"text","Duration Stretch Factor");
//	@description Sets a factor to stretch each single duration. Defaults to 1.

CLASS_ATTR_SYM(c, "port", 0, t_ezmidiplay, port); 
CLASS_ATTR_STYLE_LABEL(c,"port",0,"text","MIDI Port");
//	@description Sets the MIDI Port (also settable via the right inlet).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll coming from <o>bach.roll</o> or <o>bach.score</o> playout
// @description The expected llll must be formatted in the playout syntax (it is such by default if you link
// the playout of <o>bach.roll</o> or <o>bach.score</o> to the first <o>bach.ezmidiplay</o> inlet). <br /> <br />
// @copy BACH_DOC_PLAYOUT_SYNTAX_ROLL
// @copy BACH_DOC_PLAYOUT_SYNTAX_SCORE


// @in 1 @type int @digest The microtonal division
// @description Number of division of the tone of the equal temperament needed. For standard semitonal
// temperament, this is 2 (default); for quartertonal temperament this is 4, and so on.


// @in 1 @type list @digest Messages to <o>noteout</o>
// @description Send in the third inlet all the messages that you want to send directly to the <o>noteout</o>
// inside the abstraction, such as the MIDI port.


// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest The list containing MIDI triplets
// @description Triplets of MIDI data in the form <b><m>MIDI_note</m> <m>velocity</m> <m>MIDI_channel</m></b>.
// where <m>MIDI_note</m> is not in midicents, but in MIDI values (60 = middle C), <m>velocity</m> is the MIDI 
// velocity (0 to 127, 0 being note-off), and <m>MIDI_channel</m> is of course the MIDI channel.
// For each note, a note-on and a note-off list is properly sent.

// @out 1 @type int @digest Number of available channels
// @description The number of channels which could actually be used by the user (ignoring the percussion 10th channel),
// the other ones being used to handle microtonality (see <m>int</m> method for more information).



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name tonedivision @optional 1 @type int @digest Microtonal division  
// @description Number of division of the tone of the equal temperament needed. For standard semitonal
// temperament, this is 2 (default); for quartertonal temperament this is 4, and so on.
