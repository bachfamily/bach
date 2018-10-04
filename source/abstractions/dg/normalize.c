/**
	@file
	normalize.c
	
	@name 
	bach.normalize
	
	@realname 
	bach.normalize

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Normalize a vector
	
	@description
	Takes a vector and returns a new one
	having the same direction but with norm equal to 1.
	
	@discussion
	The norm is by default the euclidean norm (2-norm), but
	can be any other p-norm, with p integer greater than 0, 
	or "inf" symbol.
	In general, the p-norm of a vector is calculated by 
	raising all the absolute values of the elements 
	to the <m>p</m>-th power, summing all values, and taking
	the <m>p</m>-th root (i.e. raising to 1/<m>p</m>).
	The inf-norm, on the other hand, is the absolute value
	of the maximum element in the llll.

	@category
	bach, bach abstractions, bach math

	@keywords
	normalize, unitary, norm, calculate, compute, distance, square, element, sum, square root

	@seealso
	bach.norm, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Normalize vector, output result
// @description Any llll will be considered as the vector to be
// normalized. The normalized vector (having the same direction of the
// original one, but having euclidean norm 1) is then output from the
// first outlet. In case the norm of the original vector was zero,
// first of all a bang is sent through the second outlet, and then the
// original vector is output unchanged from the first outlet.

// @method bang @digest Output result
// @description Normalizes the most recently received input vector.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_ATOM(c, "p", 0, t_norm, p); 
CLASS_ATTR_STYLE_LABEL(c,"p",0,"text","Value of p");
CLASS_ATTR_BASIC(c,"p",0);
// @description @copy BACH_DOC_NORM_P_ATTRIBUTE_FOR_VECTORS

CLASS_ATTR_CHAR(c, "floatoutput", 0, t_norm, floatoutput); 
CLASS_ATTR_STYLE_LABEL(c,"floatoutput",0,"text","Floating Point Output");
CLASS_ATTR_BASIC(c,"floatoutput",0);
// @description Toggles the ability to always return floating point values

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The vector as plain llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The normalized vector
// @out 1 @type bang @digest bang if vector norm is zero



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name p @optional 1 @type atom @digest Value of p
// @description The optional argument sets the value of p
// (the index of the norm). See the <m>p</m> attribute for more information. 