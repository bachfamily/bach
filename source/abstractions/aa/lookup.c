/**
	@file
	lookup.c
	
	@name 
	bach.lookup
	
	@realname 
	bach.lookup

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Return specific elements of an llll (inlets reversed)
	
	@description
	Returns one or more specific elements of an llll, based on their addresses.
	It works exactly like <o>bach.nth</o>, but with reversed inlets.
	
	@discussion
	The abstraction is a small abstraction of <o>bach.nth</o>.

	@category
	bach, bach abstractions, bach llll

	@keywords
	retrieve, look up, element, address

	@seealso
	bach.nth, bach.pick
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description
// An llll in first inlet sets the address of the elements to extract, extract such elements and 
// outputs them.
// An llll in second inlet sets the llll from which elements should be extracted.
// @copy BACH_DOC_ADDRESS_BASIC
// @copy BACH_DOC_ADDRESS_NEGATIVE
// @copy BACH_DOC_ADDRESS_MULTIPLE
// @copy BACH_DOC_ADDRESS_RANGE

// @method bang @digest Repeat last operation
// @description Returns the requested elements according to the most recently received lllls.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "nils", 0, t_lookup, n_nils);
CLASS_ATTR_FILTER_CLIP(c, "nils", 0, 1);
CLASS_ATTR_STYLE(c, "nils", 0, "nil for Not Found");	
// @description When set to 1, if no element was present at the requested address <b>()</b> is output.
// When set to 0 (default), <b>null</b> is output.

CLASS_ATTR_LONG(c, "unwrap", 0,	t_lookup, n_unwrap);
CLASS_ATTR_LABEL(c, "unwrap", 0, "Unwrap");
CLASS_ATTR_FILTER_CLIP(c, "unwrap", 0, 1);
CLASS_ATTR_STYLE(c, "unwrap", 0, "onoff");
// @description
// When set to 1, the outermost couple of parentheses of any sublist to be output is removed.
// For instance, if the llll <b>a b (c d e)</b> is input and its third element is requested,
// <b>c d e</b> will be output instead of <b>(c d e)</b>.
// Defaults to 0.


}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Address llll
// @in 1 @type llll @digest llll to retrieve elements from


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Retrieved elements


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name original @optional 1 @type llll @digest llll to retrieve elements from
// @description A default llll to retrieve elements from can be set as <o>bach.lookup</o>'s argument.
