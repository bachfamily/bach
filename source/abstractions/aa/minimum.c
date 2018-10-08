/**
	@file
	minimum.c
	
	@name 
	bach.minimum
	
	@realname 
	bach.minimum

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Output minimum element-wise
	
	@description
	Compares every element of the left llll with the corresponding
	element of the right llll, and outputs the smaller.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	minimum, calculate, element, compute, number

	@seealso
	bach.maximum, bach.minmax, minimum, bach.clip, bach.expr
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the left
// llll for the comparison, and will output the result.
// An llll in the second inlet will set the right llll for the comparison,
// without outputting any result.
// The result is computed as follows: each element
// of the left llll is compared with the element in the corresponding position
// in the right llll, and the smaller one is taken. 
// An llll with all such minima is formed and output from the outlet.
// If the lllls do not correspond in length, the longer is always 
// considered (and exceeding elements are trivially taken as minimum).
// If single scalar elements are in the same position of complex lllls, such
// scalars apply for all elements of the corresponding llll. 
// Namely, if one of the two lllls is a single number, such number will apply
// for all elements of the other llll.

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input lllls.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Left operand llll
// @in 1 @type llll @digest Right operand llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The minimum of the two lllls element-wise



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name right_operand @optional 1 @type llll @digest Right operand llll
// @description The optional argument is the right operand llll.
