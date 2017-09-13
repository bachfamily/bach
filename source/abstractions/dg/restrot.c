/**
	@file
	restrot.c
	
	@name 
	bach.restrot
	
	@realname 
	bach.restrot

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Rotate the negative signs of an llll
	
	@description
	Accepts an llll of symbolic durations, and rotates the negative signs through the elements.
	
	@discussion
	<o>bach.restrot</o> is especially useful to be applied on a list of durations, 
	in order to make rests rotate through a list.

	@category
	bach, bach abstractions, bach notation

	@keywords
	rest, rotate, sign, negative, duration, talea
	
	@seealso
	bach.restrot, bach.chordrot, bach.fromc&amp;r, bach.toc&amp;r, bach.score
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set durations llll and output rotated result
// @description An llll in the first inlet is the list of durations to be rotated. The negative signs are then
// rotated through the list of a certain amount of steps (set by the <m>shift</m> attribute or by the argument),
// and the result is output. The elements corresponding to non-negative durations are left untouched. 

// @method bang @digest Rotate rest elements
// @description Performs the rotation on most recently received input llll.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "shift", 0, t_restrot, shift); 
CLASS_ATTR_STYLE_LABEL(c,"shift",0,"text","Shift");
CLASS_ATTR_BASIC(c,"shift",0);
// @description Number of steps to rotate the negative signs of. 
// Positive numbers rotate left, negative numbers rotate right.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The symbolic durations llll

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll with rotated signs


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name shift @optional 1 @type int @digest Shift  
// @description Number of steps to rotate the negative signs of. 
// Positive numbers rotate left, negative numbers rotate right.