/**
	@file
	skewness.c
	
	@name 
	bach.skewness
	
	@realname 
	bach.skewness

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the skewness of the numbers in an llll
	
	@description
	Finds the skewness (third standardized moment) of the
	numbers in an llll.
	
	@discussion
	The skewness is computed as mu_3/sigma^3, where mu_4 is the fourth moment about the 
	mean. It is a measure of the extent to which a distribution 
	"leans" to one side of the mean.

	@category
	bach, bach abstractions, bach math

	@keywords
	skewness, statistics, moment, compute, calculate, number

	@seealso
	bach.mean, bach.stdev, bach.variance, bach.median, bach.kurtosis	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute and output skewness
// @description Any llll will trigger the computation of the skewness of all numbers
// contained in the llll (non-numbers are ignored), which is then output from the first outlet.

// @method bang @digest Compute skewness
// @description Computes the skewness on most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_skewness, maxdepth); 
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

// @out 0 @type llll @digest The skewness of all incoming numbers



// ---------------
// ARGUMENTS
// ---------------

// (none)