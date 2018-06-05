/**
	@file
	mod-.c
	
	@name 
	bach.mod-
	
	@realname 
	bach.mod-

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Modular arithmetic subtraction
	
	@description
	Performs subtractions modulo a certain integer.
	
	@discussion

	@category
	bach, bach abstractions, bach set theory

	@keywords
	modulo, subtraction, number, pitch-class, minus
	
	@seealso
	bach.-, bach.%, bach.mod+, bach.mod*
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the left
// llll for the subtraction, and will output the result; an llll
// in the second inlet will set the right llll for the subtraction
// (as for <o>bach.-</o>). <br />
// @copy BACH_DOC_OPERATION_ABSTRACTIONS_LLLL_AND_NUMBERS_REMARK

// @method int @digest Set modulo
// @description An integer in the third outlet sets the modulo of the
// operation. <br />
// @copy BACH_DOC_SETTHEORY_MODULO

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
// @in 2 @type int @digest Modulo



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The modular subtraction of the two operands



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name arguments @optional 1 @type list @digest Arguments 
// @description If a single integer argument is provided, this is considered
// to be the modulo of the operation. If two integers are provided,
// these are considered to be the right operand and the modulo. <br />
// @copy BACH_DOC_SETTHEORY_MODULO
