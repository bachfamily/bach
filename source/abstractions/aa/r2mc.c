/**
	@file
	r2mc.c
	
	@name 
	bach.r2mc
	
	@realname 
	bach.r2mc

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Frequency ratio to interval conversion
	
	@description
	Converts an llll containing frequency ratios into an identically structured llll
	containing the corresponding intervals (expressed in midicents).
	
	@discussion
	
	@category
	bach, bach abstractions, bach math

	@keywords
	interval, cent, midicent, frequency, ratio, rational, convert

	@seealso
	bach.mc2r, bach.f2mc, bach.mc2f, Through The Looking Glass
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert frequencies to midicents
// @description The function outputs an llll formatted as the incoming one, but containing the interval 
// instead of each frequency ratio. 

// @method bang @digest Perform the conversion
// @description Performs the conversion on the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing frequency ratios


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing intervals
