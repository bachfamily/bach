/**
	@file
	mc2r.c
	
	@name 
	bach.mc2r
	
	@realname 
	bach.mc2r

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Interval to frequency ratio conversion
	
	@description
	Converts an llll containing intervals (expressed in midicents) into an identically structured llll
	containing the corresponding frequency ratios.
	Ratio is reported as a floating point value.
	
	@discussion
	
	@category
	bach, bach abstractions, bach math

	@keywords
	interval, cent, midicent, frequency, ratio, rational, convert

	@seealso
	bach.r2mc, bach.f2mc, bach.mc2f, Through The Looking Glass
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert intervals to ratios
// @description The function outputs an llll formatted as the incoming one, but containing the frequency ratio 
// instead of each interval. 

// @method bang @digest Perform the conversion
// @description Performs the conversion on the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing intervals (in midicents)


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing ratios
