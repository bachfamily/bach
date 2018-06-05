/**
	@file
	mc2pc.c
	
	@name 
	bach.mc2pc
	
	@realname 
	bach.mc2pc

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Midicents to pitch-classes conversion
	
	@description
	Converts an llll containing midicents into an identically structured llll containing the corresponding pitch-classes.
	
	@discussion
	The conversion depends on the chosen modulo (i.e. microtonal grid). <br /> <br />
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	
	@category
	bach, bach abstractions, bach set theory

	@keywords
	pitch-class, cent, midicent, convert, pitch

	@seealso
	bach.pc2mc, bach.approx, bach.pcsetinfo, bach.expr
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert midicents to pitch-classes
// @description The function outputs an llll formatted as the incoming one, but containing the pitch-class
// number instead of each midicents value. <br /> <br />
// @copy BACH_DOC_SETTHEORY_PC_AND_PCSET

// @method bang @digest Perform the conversion
// @description Performs the conversion on the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing midicents
// @in 1 @type int @digest The modulo
// @description @copy BACH_DOC_SETTHEORY_MODULO


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing pitch-classes



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
// @description @copy BACH_DOC_SETTHEORY_MODULO