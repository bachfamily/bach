/**
	@file
	kurtosis.c
	
	@name 
	bach.kurtosis
	
	@realname 
	bach.kurtosis

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the kurtosis of the numbers in an llll
	
	@description
	Finds the kurtosis (fourth standardized moment) of the
	numbers in an llll.
	
	@discussion
	The kurtosis calculated is the fourth standardized moment 
	beta_4 = mu_4/sigma^4, where mu_4 is the fourth moment about the 
	mean and sigma is the standard deviation. Another definition of 
	the kurtosis can be the forth cumulant divided by the second 
	cumulant; if you need this definition, just remove 3 at the 
	previous definition (implemented by the bach object).

	@category
	bach, bach abstractions, bach math

	@keywords
	kurtosis, statistics, moment, compute, calculate, number
	
	@seealso
	bach.mean, bach.stdev, bach.variance, bach.median, bach.skewness	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute and output kurtosis
// @description Any llll will trigger the computation of the kurtosis of all numbers
// contained in the llll (non-numbers are ignored), which is then output from the first outlet.

// @method bang @digest Compute kurtosis
// @description Computes the kurtosis on most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_kurtosis, maxdepth); 
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

// @out 0 @type llll @digest The kurtosis of all incoming numbers



// ---------------
// ARGUMENTS
// ---------------

// (none)