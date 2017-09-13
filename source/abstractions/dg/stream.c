/**
	@file
	stream.c
	
	@name 
	bach.stream
	
	@realname 
	bach.stream

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Stream last elements
	
	@description
	Makes an llll containing the last N received elements.
	
	@discussion
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	stream, element, last
	
	@seealso
	bach.collect, bach.iter, zl.stream	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Input elements
// @description Any incoming llll is iterated on its root level, and its elements are fed 
// to the streaming system. The algorithm will output from the first outlet the <m>N</m> 
// last received elements, provided that at least <m>N</m> elements have already been 
// received (or in any case if the <m>partial</m> attribute is set to 1).

// @method bang @digest Output last obtained result
// @description Outputs the last built llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "index", 0, t_stream, index); 
CLASS_ATTR_STYLE_LABEL(c,"index",0,"text","Index");
CLASS_ATTR_BASIC(c,"index",0);
// @description Sets the number of elements to be streamed at once (i.e. the length of the output lllls).
// Defaults to 1.

CLASS_ATTR_CHAR(c, "partial", 0, t_stream, partial); 
CLASS_ATTR_STYLE_LABEL(c,"partial",0,"text","Output Partial lllls");
// @description Toggles the ability to also output lllls having less than the number of elements set by
// the <m>index</m> attribute, i.e. toggles the ability to also output lllls when still incomplete.
// Defaults to 0 (off).

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Incoming elements



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Streamed elements



// ---------------
// ARGUMENTS
// ---------------


// @arg 0 @name index @optional 1 @type int @digest Index
// @description The optional argument sets the starting index, i.e. the number of 
// elements to be streamed at once.