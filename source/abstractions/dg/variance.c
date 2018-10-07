/**
	@file
	variance.c
	
	@name 
	bach.variance
	
	@realname 
	bach.variance

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the variance of the numbers in an llll
	
	@description
	Finds the variance (square of the standard deviation) of the numbers in an llll.
	
	@discussion
	The variance is the second central moment, the expected value of the
	square deviations of numbers from their mean.

	@category
	bach, bach abstractions, bach math

	@keywords
	variance, statistics, moment, compute, calculate, number

	@seealso
	bach.mean, bach.stdev, bach.median, bach.skewness, bach.kurtosis
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute and output variance
// @description Any llll will trigger the computation of the variance of all numbers
// contained in the llll (non-numbers are ignored), which is then output from the first outlet.

// @method bang @digest Compute variance
// @description Computes the variance on most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_variance, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
//  the numbers should be considered. <br />
// 	@copy BACH_DOC_MAXDEPTH

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing numbers



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The variance of all incoming numbers



// ---------------
// ARGUMENTS
// ---------------

// (none)
