/**
	@file
	pitchunpack.c
	
	@name
	bach.pitchunpack
	
	@realname
	bach.pitchunpack
 
	@type
	abstraction
	
	@module
	bach
 
	@author
	bachproject
	
	@digest
	Separate components of pitches
	
	@description
	Retrieves degrees, alterations and octaves from an llll of pitches.
	
	@discussion
 
	@category
	bach, bach abstractions, bach math, pitch
 
	@keywords
	calculate, compute, pitch, number
 
	@seealso
	bach.expr, bach.pitchpack
	
	@owner
	Andrea Agostini
 */

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the pitches
// from which to extract their components and output the result.

// @method bang @digest Output result
// @description Extracts the pitches from the most recently received llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {
    
    llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
    
CLASS_ATTR_LONG(c, "degreesym", 0, t_pitchunpack, degreesym); 
CLASS_ATTR_STYLE_LABEL(c,"degreesym",0,"text","Output Degrees As Letters");
CLASS_ATTR_BASIC(c,"degreesym",0);
// @description Toggles the ability to output the degrees as letters (C to B) instead of numbers (0 to 6).


}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Pitches llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The degrees
// @out 1 @type llll @digest The alterations
// @out 2 @type llll @digest The octaves



// ---------------
// ARGUMENTS
// ---------------

// (none)