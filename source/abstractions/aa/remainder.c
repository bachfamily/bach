/**
	@file
	remainder.c
	
	@name 
	bach.%
	
	@realname 
	bach.remainder

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quick llll modulo
	
	@description
	Outputs the remainders in a division operation
	between lllls or between lllls and numbers, 
	keeping the same sign of the left operand.
	
	@discussion
	The abstraction is equivalent to a modulo performed
	in a <o>bach.expr</o> object, with the <m>scalarmode</m>
	attribute set to 1.
	 The used modulo function is not  
	<o>bach.expr</o>'s <b>%</b> function whose result
	preserves the sign of the left operand.

	@category
	bach, bach abstractions, bach math

	@keywords
	modulo, remainder, division, number, calculate, compute

	@seealso
	bach.expr, bach./, bach.*, bach.+, bach.-, % 
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the left
// llll for the division, and will output the remainder of such
// division; an llll in the second inlet will set the right 
// llll for the division, without outputting any result. <br />
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

// @out 0 @type llll @digest The remainder of the division of the two operands



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name right_operand @optional 1 @type llll @digest Right operand llll
// @description The optional argument is the right operand llll.
