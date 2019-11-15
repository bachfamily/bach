/**
	@file
	reduce.c
	
	@name 
	bach.reduce
	
	@realname 
	bach.reduce

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Recursively apply binary function on elements
	
	@description
	Applies the binary function defined via the lambda loop on the first two elements, then on the previous result
	and third element, then on the previous result and the fourth element, and so on.

	@discussion
	Couple of elements on which the function should be evaluated and spit out the lambda outlets (the rightmost ones).
	The result is expected to be received in the lambda inlet. <br />
	@copy BACH_DOC_LAMBDA
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	apply, reduce, recursive, element, function, binary, lambda loop, iterate, iteration

	@seealso
	bach.mapelem, bach.iter, bach.collect, bach.sum, bach.prod	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet will trigger the reduction via the lambda loop.
// The first two elements of the incoming llll are output respectively from the first and second
// lambda outlet; the result of the binary function is expected from the lambda inlet. 
// Such result is output with the third element from the lambda outlets, and the result of the
// function will be injected, once again, in the lambda inlet, and so on.
// At each step, the current result and the new iterated element are output from the lambda outlets.
// When the iteration is over, the overall result is output from the first outlet. <br />
// An llll in the second inlet is considered to be the "answer" of the lambda loop. 
// Indeed second inlet is a lambda inlet. <br />
// @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// @method bang @digest Reduce llll
// @description Performs the reduction on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_kurtosis, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
//  the iteration should be performed. <br />
// 	@copy BACH_DOC_MAXDEPTH


}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be reduced
// @in 1 @type llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The reduced llll
// @out 1 @type llll @digest Lambda outlet 1
// @out 2 @type llll @digest Lambda outlet 2
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name start @optional 1 @type llll @digest Starting value
// @description Initial value for the reducing iteration (if any). More precisely,
// any llll set as argument will be prepended to the incoming llll before the reduction begins.
// Default is null, meaning that the reduction starts on the first introduced couple of elements.
