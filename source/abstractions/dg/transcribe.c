/**
	@file
	transcribe.c
	
	@name 
	bach.transcribe
	
	@realname 
	bach.transcribe

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Fills a <o>bach.roll</o> according to incoming MIDI data
	
	@description
	The purpose of <o>bach.transcribe</o> is to act as a machine which, when turned on,
	receives data containing cents, velocities and voice numbers (and optional durations),
	and properly adds in real time the notes in the 
	connected <o>bach.roll</o> object.
	
	@discussion
	<o>bach.transcribe</o> is note-based: each MIDI triplets
	refers to a note. If you want, a posteriori, to align notes into chords,
	you should look at <o>bach.roll</o>'s <m>merge</m> message.

	@category
	bach, bach abstractions, bach notation

	@keywords
	transcribe, write, fill, MIDI, stream, pitch, velocity, cent, midicent, voice, number, duration,
	insert, note, proportional
	
	@seealso
	bach.roll, bach.quantize, bach.ezmidiplay, Real Time Stories
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Turn transcription on/off
// @description A <m>1</m> in the first inlet turns the transcription on: <o>bach.transcribe</o> 
// clears the connected <o>bach.roll</o> (if any) and starts expecting the MIDI triplets from 
// its second inlet, in order to add notes in the <o>bach.roll</o>. A <m>0</m> in the first 
// inlet turns the transcription off (MIDI triplets in the second inlet no longer have any effect).

// @method allnotesoff @digest Send note-off messages for all active notes
// @description A <m>allnotesoff</m> message ends all notes currently being played, as if their
// note off MIDI triplets had been sent through the right inlet.

// @method list @digest Transcribe MIDI triplets/quadruplets
// @description A <m>list</m> in the second inlet is expected to be in the form of a MIDI triplet containing three integers: 
// <b><m>cents</m> <m>velocity</m> <m>voice_number</m></b>. When <m>velocity</m> is strictly positive,
// this triplet represents a note, in the voice defined by the <m>voice_number</m>, which starts in the exact 
// moment the triplet has been sent, and has the introduced <m>cents</m> as pitch. In this case, 
// the appropriate messages to add a note are sent to the the possibly connected <o>bach.roll</o>. 
// The note duration is regularly updated (see the <m>refresh</m> attribute), until a note-off event 
// is received concerning the specific note. At any new received triplets or refreshing, the current
// time is also output from the second outlet, and the screen position is refreshed (see <m>inscreenpos</m> attribute).
// Note-off events are simply represented by triplet having <m>velocity</m> zero. <br /> 
// For instance, a triplet <b>6000 70 1</b> adds a middle C having velocity of 70 in the first voice.
// To turn such note off, you'll need to send a note-off triplet <b>6000 0 1</b>. <br />
// If one more element is given in the third inlet (thus a MIDI quadruplet is input), such element is considered to be 
// the duration of the note in milliseconds. For such note, there will be no need to send any note-off: the note
// is simply added with its complete duration as soon as the quadruplet is entered.


// @method llll @digest Transcribe whole roll
// @description An <m>llll</m> in the <o>bach.roll</o> gathered syntax in the second inlet will be considered as a whole roll
// to be transcribed. 

// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {
	
	CLASS_ATTR_LONG(c, "refresh", 0, t_transcribe, refresh); 
	CLASS_ATTR_STYLE_LABEL(c,"refresh",0,"text","Refresh Time In Milliseconds");
	CLASS_ATTR_BASIC(c,"refresh",0);
	// @description Sets the refresh time, for the note durations, in milliseconds. 
	// Set this attribute to 0 in order to only refresh when new MIDI arrives in the third inlet (see <m>list</m> message). 
	// Defaults to 100ms.
	
	CLASS_ATTR_DOUBLE(c, "inscreenpos", 0, t_transcribe, inscreenpos); 
	CLASS_ATTR_STYLE_LABEL(c,"inscreenpos",0,"text","Current Instant Relative Position In Domain");
	// @description When new MIDI data arrive in the third inlet or when a refresh operation is performed (see <m>refresh</m> attribute),
	// the horizontal scrollbar position of the connected <o>bach.roll</o> (if any and if its horizontal scrollbar is visible) 
	// is changed in order for the "current instant" to be at a certain point inside the notation object domain. 
	// This point is a number between 0. and 1. defined by this attribute, 0. meaning: at the beginning of the
	// displayed portion of score, and 1. meaning: at the end of the displayed portion of score. (This is the very same
	// parameter that one encounters with <o>bach.roll</o>'s <m>inscreenpos</m> message.) 
	// Defaults to 0.7.
	
	CLASS_ATTR_CHAR(c, "autoclear", 0, t_transcribe, autoclear); 
	CLASS_ATTR_STYLE_LABEL(c,"autoclear",0,"onoff","Autoclear");
	CLASS_ATTR_BASIC(c,"autoclear",0);
	// @description Toggles the ability to automatically clear the <o>bach.roll</o> connected to the first outlet whenever a transcription
	// starts. By default it is on. 
	
	CLASS_ATTR_CHAR(c, "play", 0, t_transcribe, play); 
	CLASS_ATTR_STYLE_LABEL(c,"play",0,"onoff","Also Play");
	CLASS_ATTR_BASIC(c,"play",0);
	// @description Toggles the ability to also play the transcribed content (with a delay set via the <m>playdelay</m> attribute).
	// By default it is off.
	
	CLASS_ATTR_DOUBLE(c, "playdelay", 0, t_transcribe, playdelay); 
	CLASS_ATTR_STYLE_LABEL(c,"playdelay",0,"text","Play Delay");
	// @description If <m>play</m> is on, sets the delay between the writing cursor and the playing cursor, i.e.
	// the delay before play starts. Defaults to 250ms.
	
}

// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest 1/0 to start/stop transcription
// @in 1 @type list/llll @digest MIDI triplets/quadruplets in the form: cents, velocity, voice number; (optional) duration (ms)

// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest Messages to <o>bach.roll</o>
// @out 1 @type float @digest The current time in milliseconds


// ---------------
// ARGUMENTS
// ---------------

// (none)