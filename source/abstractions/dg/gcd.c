/**
	@file
	gcd.c
	
	@name 
	bach.gcd
	
	@realname 
	bach.gcd

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute greatest common divisor
	
	@description
	Computes the greatest common divisor of two numbers or of an llll.
	
	@discussion
	The implemented algorithm the Euclidean algorithm.
	
	@category
	bach, bach abstractions, bach math

	@keywords
	greatest common divisor, compute, calculate, number
	
	@seealso
	bach.lcm, bach.prime, bach.primeser, bach.coprime, bach.coprimeser	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Set number, output result
// @description A number in the first inlet sets the first number and outputs the greatest common
// divisor of this number with the one input from the second inlet (or set as argument).
// A number in the second inlet sets the second number for calculation.


// @method llll @digest Set llll of numbers and output result
// @description An llll in the first inlet sets all the numbers whose joint greatest common divisor
// must be computed, and outputs such greatest common divisor. The llll is expected to be an llll
// only containing integers.


// @method bang @digest Output greatest common divisor
// @description Outputs the greatest common divisor of the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int/llll @digest The first number or the llll of numbers
// @in 1 @type int @digest The second number



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int  @digest The greatest common divisor of the numbers



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name second-number @optional 1 @type int @digest Second number  
// @description You can set the second number (the one input in the second inlet) also as argument.
