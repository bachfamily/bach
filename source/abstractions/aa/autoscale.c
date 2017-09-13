/**
	@file
	autoscale.c
	
	@name 
	bach.autoscale
	
	@realname 
	bach.autoscale

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Linearly rescale an llll automatically
	
	@description
	Linearly rescales all the numbers in an llll so that the minimum 
	and the maximum be two given numbers.
	
	@discussion
	If all the elements of the incoming llll are the same, 
	they will be set to the mean of the given minimum and maximum.

	@category
	bach, bach abstractions, bach math

	@keywords
	rescale, expand, stretch, automatic, linear, number, minimum, maximum, detect, map

	@seealso
	bach.scale, bach.minmax, bach.expr, bach.interp
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Rescale llll, output result
// @description All numbers of the llll coming from the first inlet will be linearly rescaled 
// so that the global minimum and maximum match the output range (see the <m>number</m> message to define such numbers, 
// or set them as arguments). The result is then output through the outlet.
// If all the elements of the incoming llll are the same, they will be set to the mean of the given minimum and maximum.

// @method number @digest Set minimum or maximum
// @description A number in the second inlet sets the output minimum for the rescaled llll.
// A number in the second inlet sets the output maximum for the rescaled llll.
// Such numbers can be of any type (integers, floats, rationals): the result will vary accordingly.

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be rescaled
// @in 1 @type number @digest Output minimum
// @in 2 @type number @digest Output maximum



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The linearly rescaled llll



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name output_min @optional 1 @type number @digest Output minimum
// @description First optional argument is the output minimum (default: 0.).

// @arg 1 @name output_max @optional 1 @type number @digest Output maximum
// @description Second optional argument is the output maximum (default: 1.).
