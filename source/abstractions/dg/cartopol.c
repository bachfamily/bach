/**
	@file
	cartopol.c
	
	@name 
	bach.cartopol
	
	@realname 
	bach.cartopol

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Cartesian to polar coordinate conversion for lllls
	
	@description
	Converts two lllls consisting of real and imaginary values into 
	two polar-coordinate lllls consisting of amplitudes (radius) and angle values (in radians).
	
	@discussion
	Incoming lllls must be equally structured in order for the result to be consistent	

	@category
	bach, bach abstractions, bach math

	@keywords
	polar, cartesian, coordinate, convert, amplitude, phase, angle, radius, real, imaginary, part

	@seealso
	bach.poltocar, bach.expr, bach.fft
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set X or Y coordinates, output result
// @description In the first inlet, an llll sets the X coordinates (or real parts), and output 
// the converted polar coordinates. <br />
// In the second inlet, an llll sets the Y coordinates (or imaginary parts). <br />
// As for <o>bach.expr</o> with the <m>scalarmode</m> attribute set to 1,
// the module automatically iterates lists against single elements

// @method bang @digest Perform conversion
// @description Performs the conversion on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The real parts or X coordinates
// @in 1 @type llll @digest The imaginary parts or Y coordinates



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Amplitudes
// @out 1 @type llll @digest Phases (in radians)



// ---------------
// ARGUMENTS
// ---------------

// (none)