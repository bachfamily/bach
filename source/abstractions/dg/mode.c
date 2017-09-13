/**
	@file
	mode.c
	
	@name 
	bach.mode
	
	@realname 
	bach.mode

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the mode of an llll
	
	@description
	Finds the number appearing most often in an llll.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	mode, number, statistics, compute, calculate

	@seealso
	bach.quantiles, bach.mean, bach.median, bach.variance, bach.stdev, bach.skewness, bach.kurtosis
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute and output mode
// @description Any llll will trigger the computation of its statistical mode,
// i.e. the number appearing most often in the list. 
// If the mode is not unique, all the modes are output, in ascending order.

// @method bang @digest Compute mode
// @description Computes the mode of most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The original llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The mode of the llll



// ---------------
// ARGUMENTS
// ---------------

// (none)