/**
	@file
	times.c
	
	@name 
	bach.*
	
	@realname 
	bach.times

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quick llll multiplication
	
	@description
	Performs multiplications between lllls or
	between lllls and numbers.
	
	@discussion
	The abstraction is equivalent to a multiplication performed
	in a <o>bach.expr</o> object, with the <m>scalarmode</m>
	attribute set to 1.

	@category
	bach, bach abstractions, bach math

	@keywords
	multiplication, calculate, compute, product, number

	@seealso
	bach.expr, bach./, bach.+, bach.-, *, bach.mod*
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the left
// llll for the multiplication, and will output the result; an llll
// in the second inlet will set the right llll for the multiplication,
// without outputting any result. <br />
// @copy BACH_DOC_OPERATION_ABSTRACTIONS_LLLL_AND_NUMBERS_REMARK

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input lllls.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Left operand llll
// @in 1 @type llll @digest Right operand llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The multiplication of the two operands



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name right_operand @optional 1 @type llll @digest Right operand llll
// @description The optional argument is the right operand llll.
