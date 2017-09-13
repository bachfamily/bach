/**
	@file
	cross.c
	
	@name 
	bach.cross
	
	@realname 
	bach.cross

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the cross product of two lllls
	
	@description
	Computes the cross product (or vector product) of two lllls having 3 coordinates.
	
	@discussion
	The cross product is only defined in the three-dimensional cartesian space,
	thus both lllls are expected to have 3 coordinates.

	@category
	bach, bach abstractions, bach math

	@keywords
	vector product, cross product, coordinate, vector, cartesian, orthogonal

	@seealso
	bach.mtimes
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set vectors, output result
// @description An <m>llll</m> in the first inlet sets the left vector and outputs the result.
// An <m>llll</m> in the second inlet sets the right vector.

// @method bang @digest Output result
// @description Outputs the cross product of the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Left vector
// @in 1 @type llll @digest Right vector



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Cross product



// ---------------
// ARGUMENTS
// ---------------

// (none)