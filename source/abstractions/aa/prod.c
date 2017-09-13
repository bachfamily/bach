/**
	@file
	prod.c
	
	@name 
	bach.prod
	
	@realname 
	bach.prod

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Multiply all numbers in an llll
	
	@description
	Takes the product of all the numbers of the incoming llll.
	
	@discussion
	<o>bach.prod</o> only operates on numbers; each 
	non-number element is simply ignored.

	@category
	bach, bach abstractions, bach math

	@keywords
	product, number, calculate, compute, multiply

	@seealso
	bach.sum, bach.*
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Multiply all numbers and output result
// @description All the numbers of the incoming llll are
// multiplied, the number of such factors is output through
// the right outlet, and the result of the product 
// is output through the left outlet. 
// Non-numbers are simply ignored.
// The number of multiplied elements also depends on the
// <m>maxdepth</m> attribute.

// @method bang @digest Output result
// @description Outputs the number of factors and the result of calculation 
// performed on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_sum, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
//  	numbers must be considered for the product. The default is 0, meaning: all levels. <br />
// 	@copy BACH_DOC_MAXDEPTH

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll whose numbers must be multiplied



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Product of all numbers
// @out 1 @type int @digest Number of factors



// ---------------
// ARGUMENTS
// ---------------

// (none)