/**
	@file
	dl2curve.c
	
	@name 
	bach.dl2curve
	
	@realname 
	bach.dl2curve

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a duration line into pitch and velocity curve~ messages
	
	@description
	Converts the information about the duration line of a note
	into messages to drive a pitch curve~ and a velocity curve~.
	
	@discussion

	@category
	bach, bach abstractions, bach notation

	@keywords
	duration line, curve~, convert, glissando, pitch, velocity, duration

	@seealso
	bach.dl2line, bach.roll, bach.score, bach.slot2line, 
	bach.slot2curve, bach.playkeys
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set pitch breakpoints
// @description An llll in the fourth inlet sets the breakpoint
// function of the duration line. Breakpoints are expected 
// as an llll in the form <b><m>BPT1</m> <m>BPT2</m> <m>BPT3</m>...</b>,
// as in the note pitch breakpoint syntax (see below), but without 
// the routing <b>breakpoint</b> symbol, and without the outer level
// of parenthesis. <br /> 
// An llll in any other inlet is converted into a number (see <m>float</m> and <m>int</m>). <br />
// @copy BACH_DOC_NOTE_BREAKPOINT_SYNTAX

// @method float @digest Function depends on inlet
// A float in the first inlet sets the base pitch of the note (in midicents)
// and outputs from the first and second outlet the 
// appropriate messages for the two curve~ objects, to drive,
// respectively, the pitch profile and the velocity profile. <br />
// A float in the third inlet sets the overall duration of the note,
// in milliseconds. <br />
// A float in the fifth inlet is the lambda input for the pitch 
// lambda loop: each pitch is indeed output from the third outlet
// and you are allowed to modify them and re-inject them in the
// fifth inlet, so that their modified value is taken into account
// when building the messages for the pitch curve~ object. 
// This might be useful, for instance, to convert midicent pitch
// values into Hertz values. <br />
// A float in the sixth inlet is the lambda input for the velocity 
// lambda loop: each velocity is indeed output from the fourth outlet
// and you are allowed to modify them and re-inject them in the
// sixth inlet, so that their modified value is taken into account
// when building the messages for the velocity curve~ object. 
// This might be useful, for instance, to convert velocities into 
// amplitude values, or decibels.

// @method int @digest Set base velocity
// An integer value in the second inlet sets the base velocity of the note.
// If breakpoints have velocities (see the <m>breakpointshavevelocities</m> 
// attribute of <o>bach.roll</o> or <o>bach.score</o>) then such velocity
// can vary during the note duration line, otherwise it will apply to the whole 
// duration of the note. <br />
// An integer value in any other inlet (except for the fourth one)
// is converted into a float value.

// @method bang @digest Perform last operation
// @description Performs and outputs the messages for the curve~ objects, based on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type float @digest The base pitch (midicents)
// @in 1 @type int @digest The base velocity
// @in 2 @type float @digest The note duration (milliseconds)
// @in 3 @type llll @digest The pitch breakpoints as llll
// @description Breakpoints are expected 
// as an llll in the form <b><m>BPT1</m> <m>BPT2</m> <m>BPT3</m>...</b>,
// as in the note pitch breakpoint syntax (see below), but without 
// the routing <b>breakpoint</b> symbol, and without the outer level
// of parenthesis. <br /> 
// @copy BACH_DOC_NOTE_BREAKPOINT_SYNTAX
// @in 4 @type float/llll @digest The pitch lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION
// @in 5 @type float/llll @digest The velocity lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Messages for the curve~ controlling the pitch
// @out 1 @type llll @digest Messages for the curve~ controlling the velocity
// @out 2 @type llll @digest The pitch lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION
// @out 3 @type llll @digest The velocity lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION



// ---------------
// ARGUMENTS
// ---------------

// (none)