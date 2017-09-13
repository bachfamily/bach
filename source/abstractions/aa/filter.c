/**
	@file
	filter.c
	
	@name 
	bach.filter
	
	@realname 
	bach.filter

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Only let specified data types through
	
	@description
	Takes the incoming data and,
	if its type belong to some specified types,
	outputs it through its first outlet; otherwise
	it outputs it through its second outlet.
	
	@discussion
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	pass, filter, reject, accept, route, type, let through

	@seealso
	bach.is, bach.contains, bach.sieve, bach.filternull, Iterations
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Filter incoming data
// @description An llll in the first inlet contains the data to be filtered.
// If the content matches the accepted data types (see <m>list</m> message)
// the llll is let through the first outlet ("accepted"). Otherwise, it is let through the
// second outlet ("rejected"). <br />
// The incoming data is taken as a whole: if a single element is entered, the data type
// will be the type of such element (e.g. <b>5.4</b> is a floating point number, while 
// <b>foo</b> is a symbol); if more than one elements are entered, the data type
// will be "llll" (e.g. <b>12 foo</b>, or <b>(12 foo) (1 2 ())</b>). The <b>null</b>
// llll belong to a separate "null" type (see <m>list</m> message).

// @method list @digest Set accepted data types
// @description A list in the second inlet sets the data types which are allowed to
// be let through the first outlet ("accepted"). All other data types are let through
// the right outlet ("rejected"). <br />
// Data types can be specified in two different ways.
// The simplest way is to enter them as a list of symbols, each referring to one 
// data type: <br />
// • <b>i</b> stands for "ints" and represents all integers; <br />
// • <b>r</b> stands for "rational" and represents all rational numbers, included 
// all integer numbers; <br />
// • <b>R</b> represents all rational numbers but not integer numbers (i.e.
// only rational numbers whose denominator is greater than 1); <br />
// • <b>f</b> represents all floating point numbers; <br />
// • <b>s</b> represents all symbols; <br />
// • <b>l</b> represents all lllls; <br />
// • <b>n</b> represents the <b>null</b> llll. <br />
// You can let pass more than one data type by listing them. For instance <b>i s</b> let
// through the integer numbers and symbols. You can begin the list with a minus sign 
// in order to invert the selection; for instance <b>- f i r</b> let accepts anything but 
// numbers. <br />
// Another (more complicate) way to enter data types is to use a single number 
// (also see <o>bach.is</o>). Each type is associated with a certain number:
// • 1 = null; <br />
// • 2 = integers; <br />
// • 4 = rational numbers (strictly: not integers); <br />
// • 8 = floating point numbers; <br />
// • 16 = symbols; <br />
// • 32 = lllls; <br />
// • 64 = unknown objects. <br />
// By summing up these values you can let multiple type pass through. For instance, 
// <b>14</b>, which is 2 (integers) + 4 (rationals) + 8 (floats), will let all numbers
// through. Add a negative sign to the number in order to invert the selection; for instance
// <b>-33</b> will accept everything but lllls (<b>null</b> llll included).

// @method bang @digest Output last filtered data
// @description Performs the filtering on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The incoming data
// @in 1 @type list @digest Accepted data types



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Data if accepted
// @out 1 @type llll @digest Data if rejected


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name accepted_data_types @optional 1 @type list @digest Accepted data types 
// @description The optional argument is a list or a number setting the accepted data
// types, exactly as the <m>list</m> coming in the second inlet (refer to the <m>list</m> 
// message to know more).

