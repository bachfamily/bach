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
// @copy BACH_DOC_FIND_MAXDEPTH
    
CLASS_ATTR_LONG(c, "mindepth",        0,    t_locate, n_mindepth);
CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");
CLASS_ATTR_BASIC(c, "mindepth", 0);
CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_find);
// @description @copy BACH_DOC_FIND_MINDEPTH
    
CLASS_ATTR_LONG(c, "minidx",        0,    t_locate, n_minidx);
CLASS_ATTR_LABEL(c, "minidx", 0, "Minimum Index");
// @description @copy BACH_DOC_FIND_MINIDX

CLASS_ATTR_LONG(c, "maxidx",        0,    t_locate, n_maxidx);
CLASS_ATTR_LABEL(c, "maxidx", 0, "Maximum Index");
// @description @copy BACH_DOC_FIND_MAXIDX

CLASS_ATTR_LONG(c, "idxreject",        0,    t_locate, n_idxreject);
CLASS_ATTR_LABEL(c, "idxreject", 0, "Index Reject");
CLASS_ATTR_STYLE(c, "idxreject", 0, "onoff");
CLASS_ATTR_FILTER_CLIP(c, "idxreject", 0, 1);
// @description @copy BACH_DOC_FIND_IDXREJECT

CLASS_ATTR_LONG(c, "depthreject",    0,    t_locate, n_depthreject);
CLASS_ATTR_LABEL(c, "depthreject", 0, "Depth Reject");
CLASS_ATTR_STYLE(c, "depthreject", 0, "onoff");
// @description @copy BACH_DOC_DEPTHREJECT


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
