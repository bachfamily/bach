/**
	@file
	locate.c
	
	@name 
	bach.locate
	
	@realname 
	bach.locate

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Locate elements
	
	@description
	Returns the address of the first occurrence of an element or sequence 
	inside an <m>llll</m>
	
	@discussion
	The abstraction is a small abstraction of <o>bach.find</o>.

	@category
	bach, bach abstractions, bach llll

	@keywords
	find, locate, element, address

	@seealso
	bach.find, bach.lookup
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description
// An llll in first inlet is considered as the llll to be located.
// An llll in second inlet sets the llll inside which such llll should be located.
// After an llll has been introduced in the first inlet, the address of the first
// occurrences of the llll to locate is output from the outlet; <m>null</m> is output
// if no occurrence was found.
// @copy BACH_DOC_ADDRESS_BASIC

// @method bang @digest Repeat last operation
// @description Returns the requested elements according to the most recently received lllls.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_locate, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
// @description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
// the elements should be searched. <br />
// @copy BACH_DOC_MAXDEPTH

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest llll to locate
// @in 1 @type llll @digest llll to search


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Found address


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name llll_to_search @optional 1 @type llll @digest llll to search
// @description A default llll in which elements should be located can be set 
// as <o>bach.locate</o>'s argument.
