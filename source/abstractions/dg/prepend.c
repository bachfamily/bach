/**
	@file
	prepend.c
	
	@name 
	bach.prepend
	
	@realname 
	bach.prepend

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Add an llll in front of input
	
	@description
	Adds a given llll in front of the input llll.

	@discussion
	The abstraction is a simple wrapper of <o>bach.join</o>.

	@category
	bach, bach abstractions, bach llll

	@keywords
	prepend, combine, concatenate, add, front, append, join

	@seealso
	bach.postpend, bach.join, bach.insert, bach.pack
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet is the original llll, to which 
// the llll coming from the second inlet (or set as argument) is prepended, and the result is output. <br />
// An llll in the second inlet is the llll to be prepended.


// @method bang @digest Prepend llll, cause output
// @description Performs the operation on the most received input data.




// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_LONG(c, "inwrap",	0,	t_prepend, n_inwrap);
	CLASS_ATTR_LABEL(c, "inwrap", 0, "Wrap Input");
	CLASS_ATTR_FILTER_MIN(c, "inwrap", 0);
	// @description @copy BACH_DOC_INWRAP

	CLASS_ATTR_LONG(c, "outwrap",	0,	t_prepend, n_outwrap);
	CLASS_ATTR_LABEL(c, "outwrap", 0, "Wrap Output");
	CLASS_ATTR_FILTER_MIN(c, "outwrap", 0);
	// @description @copy BACH_DOC_OUTWRAP
}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The original llll
// @in 1 @type llll @digest The llll to be prepended



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The modified llll


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name llll_to_be_prepended @optional 1 @type llll @digest The llll to be prepended
// @description The optional argument is the initial llll to be prepended (default: <b>null</b>).
