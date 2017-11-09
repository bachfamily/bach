/**
	@file
	random.c
	
	@name 
	bach.random
	
	@realname 
	bach.random

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Pick random elements from an llll
	
	@description
	Outputs one or more random elements, extracted from a given pool llll.
	
	@discussion
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	random, element, pick, extract, pool
	
	@seealso
	random, bach.nth, bach.pick, bach.urn, bach.lookup, bach.mrandom, bach.wrandom
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

// @method llll @digest Set pool llll and output randomly picked elements
// @description <o>bach.random</o> sets the incoming llll as the pool from which elements
// should be picked (also depending on the <m>maxdepth</m> attribute), 
// and then output the random elements (first outlet), along with their addresses
// (second outlet).

// @method int @digest Set the number of elements to be picked at once
// @description An integer in the second inlet sets the number of elements that will be picked each time
// an llll or a bang is received (default: 1). Elements can be repeated while picking: if you don't
// want this behavior have a look at <o>bach.urn</o> instead.

// @method bang @digest Output randomly picked elements
// @description The given number of elements are randomly picked and output (from the first outlet)
// along with their addresses (from the second outlet). <br />
// @copy BACH_DOC_ADDRESS_BASIC


// @method seed @digest Set the random number generator seed
// @description Use the <m>seed</m> message to set the random number generator seed 
// (see the reference of <o>random</o> for more information).
// @marg 1 @name seed @optional 0 @type int


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "unwrap", 0, t_random, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"text","Automatically Unwrap lllls When Picked");
CLASS_ATTR_BASIC(c,"unwrap",0);
// @description Toggles the ability to unwrap automatically the llll when picked (default: 1).
// For instance, if this attribute is active, and the llll is <b>1 2 (3 (4 4)) 5</b>, with 
// <m>maxdepth</m> 1, when the <b>(3 (4 4))</b> element is picked, the flattened <b>3 (4 4)</b> llll
// is output.


CLASS_ATTR_LONG(c, "maxdepth", 0, t_random, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
// @description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
// the elements can be picked (default: 1, i.e.: elements are picked only at the root level). <br />
// @copy BACH_DOC_MAXDEPTH


CLASS_ATTR_LLLL(c, "default", 0, t_random, default); 
CLASS_ATTR_STYLE_LABEL(c,"default",0,"text","Default llll");
// @description You can use the <m>default</m> attribute to define an llll which will be used by default
// at the instantiation. Such llll will be used as pool llll when a bang is received. If another llll is
// sent through the first inlet, this latter becomes the new pool llll, and the <m>default</m> llll is
// no longer used.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The pool llll or bang to pick
// @in 1 @type int @digest The number of elements that must be picked at once


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The picked elements
// @out 1 @type llll @digest The picked elements' addresses
// @description @copy BACH_DOC_ADDRESS_BASIC



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name number_of_elements @optional 1 @type int @digest Number of elements to be picked at once 
// @description The optional argument is the number of elements that must be picked each time
// an llll or a bang is received (default: 1).