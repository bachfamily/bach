/**
	@file
	mapelem.c
	
	@name 
	bach.mapelem
	
	@realname 
	bach.mapelem

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Modify llll elements
	
	@description
	Takes an llll and operates a given transformation on each element.
	The transformation is defined via the lambda inlet and outlet.
	
	@discussion
	Elements are iterated (as in <o>bach.iter</o>) and spit out the lambda outlet (the rightmost one).
	They are supposed to be individually modified then by patching, and the modified element is expected
	to be received in the lambda inlet. <br />
	@copy BACH_DOC_LAMBDA
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	map, element, modify, change, each, transform, lambda loop, iterate, iteration

	@seealso
	bach.iter, bach.collect, Iterations	
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet will trigger the mapping via the lambda loop. 
// Elements re-injected in the lambda inlet are re-collected and substituted to the 
// output ones. If no element comes in the lambda inlet, the original element is dropped. <br />
// An llll in the second inlet is considered to be the "answer" of the lambda loop. 
// Indeed second inlet is a lambda inlet. <br />
// @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// @method bang @digest Modify llll
// @description Performs the modification on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_mapelem, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
//  	the element should be iterated and sent through the lambda outlet. The default is 0, meaning: all levels. <br />
// 	@copy BACH_DOC_MAXDEPTH

CLASS_ATTR_CHAR(c, "unwrap", 0, t_mapelem, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"text","Unwrap");
CLASS_ATTR_BASIC(c,"unwrap",0);
//	@description If the <m>unwrap</m> attribute is set to <m>n</m>, and is greater than 0, <m>n</m> outer levels of 
// 	parentheses (if any) are removed from the lllls output from the lambda outlet, and are automatically re-injected 
//	to the lllls input from the lambda inlet. The default is 0.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be modified
// @in 1 @type llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The modified llll
// @out 1 @type llll @digest Lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION


// ---------------
// ARGUMENTS
// ---------------

// (none)