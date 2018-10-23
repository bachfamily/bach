/**
	@file
	fact.c
	
	@name 
	bach.fact
	
	@realname 
	bach.fact

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute factorial
	
	@description
	Computes the factorial of a given number N, that is
	N! = N*(N-1)*(N-2)...*2*1.
	
	@discussion
	The algorithm just applies the definition of factorial.
	
	@category
	bach, bach abstractions, bach math

	@keywords
	factorial, product, number, compute, calculate

	@seealso
	bach.bin, bach.prod	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Compute factorial and output result
// @description Any integer will trigger its factorial computation and output the result.
// If the result is not representable (because of overflow) a bang is sent out the second outlet,
// otherwise the result is sent out the left outlet

// @method bang @digest Compute factorial
// @description Computes the factorial most recently received input number.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The number N



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest The factorial of the number N
// @out 1 @type bang @digest bang if overflow



// ---------------
// ARGUMENTS
// ---------------

// (none)
