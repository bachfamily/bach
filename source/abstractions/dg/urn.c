/**
	@file
	urn.c
	
	@name 
	bach.urn
	
	@realname 
	bach.urn

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Pick random elements from an llll without duplicates
	
	@description
	Outputs one or more of random elements, extracted from a given urn llll,
	without repeating them.
	
	@discussion
	Nonetheless, if elements are repeated inside the urn llll, such repetition can remain
	in the extracted elements.
	
	@category
	bach, bach abstractions, bach llll
	
	@keywords
	random, repetition, urn, pick, extract, element, duplicate

	@seealso
	urn, bach.nth, bach.pick, bach.random, bach.lookup, bach.mrandom, bach.wrandom, bach.wurn
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set urn llll
// @description An llll in the second inlet is considered to be the urn llll, from which elements
// are extracted (also depending on the <m>maxdepth</m> attribute).

// @method int @digest Set the number of elements to be picked at once
// @description An integer in the third inlet sets the number of elements that will be picked each time
// a bang is received (default: 1). Elements cannot be repeated while picking (if you 
// want to allow repetitions, have a look at <o>bach.random</o> instead), unless the urn llll
// itself has repeated elements.

// @method bang @digest Output randomly picked elements, without duplicates
// @description The given number of elements are randomly picked and output (from the first outlet)
// along with their addresses (from the second outlet). Elements having already been picked will
// not be picked anew (unless a <m>clear</m> message is explicitly sent, or the <m>llll</m> is sent anew,
// or the <m>autoclear</m> attribute is set to 1). When all elements have been picked from
// the urn, a bang is sent through the third outlet (unless the <m>autoclear</m> attribute is set to 1):
// in this case, the output llll might me shorter than expected, or even <m>null</m>. <br />
// @copy BACH_DOC_ADDRESS_BASIC

// @method seed @digest Set the random number generator seed
// @description Use the <m>seed</m> message to set the random number generator seed 
// (see the reference of <o>urn</o> for more information).
// @marg 1 @name seed @optional 0 @type int

// @method clear @digest Clears the urn
// @description Use the <m>clear</m> message to reset the urn, so that any of its elements can be picked at the
// next request.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "autoclear", 0, t_urn, autoclear); 
CLASS_ATTR_STYLE_LABEL(c,"autoclear",0,"text","Automatically Reset Urn");
CLASS_ATTR_BASIC(c,"autoclear",0);
// @description If this is 0, the urn is never reset unless a <m>clear</m> message is sent, or the llll is newly introduced (default). <br />
// If this is 1, the urn is reset before each new extractions. <br />
// If this is 2, the urn is reset whenever it is empty <br />
// If this is 3, the urn is reset both before new extractions and whenever it is empty (even during multiple elements picking).


CLASS_ATTR_CHAR(c, "unwrap", 0, t_urn, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"text","Automatically Unwrap lllls When Picked");
CLASS_ATTR_BASIC(c,"unwrap",0);
// @description Toggles the ability to unwrap automatically the llll when picked (default: 1).
// For instance, if this attribute is active, and the llll is <b>1 2 [3 [4 4]] 5</b>, with 
// <m>maxdepth</m> 1, when the <b>[3 [4 4]]</b> element is picked, the flattened <b>3 [4 4]</b> llll
// is output.


CLASS_ATTR_LONG(c, "maxdepth", 0, t_urn, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
// @description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
// the elements can be picked (default: 1, i.e.: elements are picked only at the root level). <br />
// @copy BACH_DOC_MAXDEPTH


CLASS_ATTR_LLLL(c, "default", 0, t_urn, default); 
CLASS_ATTR_STYLE_LABEL(c,"default",0,"text","Default llll");
// @description You can use the <m>default</m> attribute to define an llll which will be used by default
// at the instantiation. Such llll will be used as urn llll when a bang is received. If another llll is
// sent through the second inlet, this latter becomes the new urn llll, and the <m>default</m> llll is
// no longer used.

CLASS_ATTR_CHAR(c, "nullmode", 0, t_urn, nullmode); 
CLASS_ATTR_STYLE_LABEL(c,"nullmode",0,"text","Output null When Urn Is Empty");
CLASS_ATTR_BASIC(c,"nullmode",0);
// @description If the <m>nullmode</m> is set to 1, when a <m>bang</m> arrives and the urn is empty,
// <b>null</b> is output from the first two outlets, along with the bang from the third one.
// If <m>nullmode</m> is set to 0 (default), only the bang from the last outlet is sent.

CLASS_ATTR_CHAR(c, "sort", 0, t_urn, sort); 
CLASS_ATTR_STYLE_LABEL(c,"sort",0,"text","Sort Results According To Original Order");
CLASS_ATTR_BASIC(c,"sort",0);
// @description Toggles the ability to sort the results according to their order in the original llll.


}

// ---------------
// INLETS
// ---------------

// @in 0 @type bang/symbol @digest bang to pick, or clear
// @in 1 @type llll @digest The urn llll
// @in 2 @type int @digest The number of elements that must be picked at once


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The picked elements
// @out 1 @type llll @digest The picked elements' addresses
// @description @copy BACH_DOC_ADDRESS_BASIC
// @out 2 @type bang @digest bang when the urn is empty



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name number_of_elements @optional 1 @type int @digest Number of elements to be picked at once 
// @description The optional argument is the number of elements that must be picked each time
// an llll or a bang is received (default: 1).
