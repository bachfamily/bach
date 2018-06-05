/**
	@file
	x2dx.c
	
	@name 
	bach.x2dx
	
	@realname 
	bach.x2dx

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Take differences between element
	
	@description
	Returns the differences between each element's immediate
	follower and the element itself.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	derive, discrete, difference, take, subtract, number

	@seealso
	bach.dx2x
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output differences
// @description Each element at the root level of the incoming llll
// is substituted with the difference between its follower and 
// the element itself. The resulting llll, which will have the same
// length of the input llll minus 1, is then output through the outlet.

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

// @in 0 @type llll @digest The original llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing differences



// ---------------
// ARGUMENTS
// ---------------

// (none)