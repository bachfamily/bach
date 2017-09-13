/**
	@file
	pow.c
	
	@name 
	bach.pow
	
	@realname 
	bach.pow

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quick llll exponentiation
	
	@description
	Raises all elements of an llll (or a number) coming in first inlet,
	to the power defined by another llll (or number).
	
	@discussion
	The abstraction is equivalent to an exponentiation performed
	in a <o>bach.expr</o> object, with the <m>scalarmode</m>
	attribute set to 1.

	@category
	bach, bach abstractions, bach math

	@keywords
	power, raise, exponent, base, number, calculate, compute

	@seealso
	bach.expr, bach.*, pow, bach.mpow
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the base llll for the 
// exponentiation, and will output the result; an llll
// in the second inlet will set the llll containing the exponent (or exponents),
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

// @in 0 @type llll @digest Base llll
// @in 1 @type llll @digest Exponent llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The exponentiation of the two operands



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name exponent @optional 1 @type llll @digest Exponent llll
// @description The optional argument is the exponent llll.
