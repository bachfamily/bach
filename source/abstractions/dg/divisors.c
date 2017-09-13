/**
	@file
	divisors.c
	
	@name 
	bach.divisors
	
	@realname 
	bach.divisors

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find divisors of a number
	
	@description
	Returns all the divisors of an integer number, in ascending order.
	
	@discussion
	
	@category
	bach, bach abstractions, bach math

	@keywords
	compute, calculate, binomial coefficient, combinations
	
	@seealso
	bach.factorize, bach./, bach.%, bach.expr
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Set number, output result
// @description Any incoming integer triggers the calculation of its divisors, which are then output through the outlet.

// @method bang @digest Output last obtained result
// @description Outputs the result obtained from the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The number



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The divisors



// ---------------
// ARGUMENTS
// ---------------

// (none)