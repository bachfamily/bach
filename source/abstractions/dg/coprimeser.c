/**
	@file
	coprimeser.c
	
	@name 
	bach.coprimeser
	
	@realname 
	bach.coprimeser

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Coprime number series
	
	@description
	Finds all the numbers M smaller than the absolute value of a given number N, 
	such that M and N are coprime.
	
	@discussion
	The abstraction is a based on <o>bach.coprime</o>.

	@category
	bach, bach abstractions, bach math

	@keywords
	coprime, prime, number, greatest common divisor, series, sequence

	@seealso
	bach.arithmser, bach.geomser, bach.primeser, bach.coprime, bach.factorize, bach.gcd, bach.lcm
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Set maximum, output result
// @description An integer in the inlet will set the number N (maximum number for the
// series, which in turns will never be reached, since it is not coprime with itself). <br />

// @method bang @digest Output series
// @description Outputs the coprime number series for the most recently received input maximum number N.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The maximum (number N)



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Coprime number series.
// @description The output is the list of all numbers smaller than N and coprime with N


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name maximum @optional 1 @type int @digest Maximum number
// @description An integer as argument sets the number N (maximum number for the
// series, which in turns will never be reached, since it is not coprime with itself).