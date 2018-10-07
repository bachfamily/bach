/**
	@file
	abs.c
	
	@name 
	bach.abs
	
	@realname 
	bach.abs

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quick absolute value of lllls
	
	@description
	Takes the absolute value of an incoming llll.
	
	@discussion
	The abstraction is equivalent to the <b>abs</b> function called
	in a <o>bach.expr</o> object.

	@category
	bach, bach abstractions, bach math

	@keywords
	absolute value, modulo, magnitude, radius, calculate, compute, sign

	@seealso
	bach.expr, abs 
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output the absolute value
// @description For each number of the incoming llll is 
// taken the absolute (non-negative) value, and the llll
// containing the absolute values (having the same shape
// as the original one) is output through the outlet.
// Non-numbers are kept as they are.

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Original llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing absolute values



// ---------------
// ARGUMENTS
// ---------------

// (none)
