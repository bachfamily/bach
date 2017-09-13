/**
	@file
	chordrev.c
	
	@name 
	bach.chordrev
	
	@realname 
	bach.chordrev

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Reverse the non-rest elements of an llll
	
	@description
	Accepts an llll to reverse, an llll of reference durations,
	and reverses only the elements of the left llll corresponding to non-negative elements in the 
	durations llll.<br />
	
	@discussion
	<o>bach.chordrev</o> is especially useful to reverse parameters like cents,
	velocities or extras, without affecting the elements corresponding to rests. <br />
	<o>bach.chordrev</o> also accepts lllls of depth 2, considering them to be a list for each voice,
	and operates accordingly.

	@category
	bach, bach abstractions, bach notation

	@keywords
	chord, reverse, sequence, ties, duration, retrograde

	@seealso
	bach.tierev, bach.chordrot, bach.restrot, bach.fromc&amp;r, bach.toc&amp;r, bach.score, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set llll or reference durations llll, output result
// @description An llll in the first inlet is considered as the llll containing the parameter data
// to be reversed: its elements situated in the same position of positive elements of the reference durations llll are thus 
// reversed and the result is output (unless the <m>triggers</m> attribute is set to 2). 
// The elements corresponding to negative durations are left untouched. <br />
// An llll in the second inlet sets the reference durations llll. If the <m>triggers</m> attribute
// is 2, it also triggers the output of the rotation. <br />
// The two lllls must have the same structure, and can either be plain lllls, or lists of plain
// lllls, in which case they are considered as being one list for each voice.

// @method bang @digest Reverse non-rest elements
// @description Performs the operation on most recently received input lllls.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "triggers", 0, t_chordrev, triggers); 
CLASS_ATTR_STYLE_LABEL(c,"triggers",0,"text","Triggers");
CLASS_ATTR_BASIC(c,"triggers",0);
// @description Index of the inlet triggering the output (by default 1: left inlet).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to reverse
// @in 1 @type llll @digest The reference durations llll

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The reversed llll


// ---------------
// ARGUMENTS
// ---------------

// (none)