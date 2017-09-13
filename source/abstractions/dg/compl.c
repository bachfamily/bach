/**
	@file
	compl.c
	
	@name 
	bach.compl
	
	@realname 
	bach.compl

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find complement of a pitch-class set
	
	@description
	Given a pitch-class set, <o>bach.compl</o> 
	finds its complement, i.e. the set of all the numbers not appearing in the given set. 
	
	@discussion
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	bach.compl accepts in input also a complex tree of pitch-class sets, and will output the complementary
	accordingly (preserving the tree shape).
	For instance, with modulo = 12, the complement of the set [4 7 9] is [0 1 2 3 5 6 8 10 11].
	
	@category
	bach, bach abstractions, bach set theory

	@keywords
	complement, pitch-class, modulo, negative
	
	@seealso
	bach.circle, bach.mod+, bach.mod-, bach.modtimes, bach.pcsetinfo
	
	@owner
	Daniele Ghisi
*/

// METHODS

// @method llll @digest Compute the complement of incoming pitch-class set
// @description In the first inlet, a pitch-class set, in the form of plain list of numbers (or a tree of such pitch-class sets)
// will trigger the output of its complement 

// @method bang @digest Find and output the complement
// @description Finds the complement of the most recently received input pitch-class set.

// @method int @digest Set modulo 
// @description An integer in the right inlet will set the modulo. <br />
// @copy BACH_DOC_SETTHEORY_MODULO


// ATTRIBUTES

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}


// INLETS

// @in 0 @type llll @digest Pitch-class set (as a plain list) or tree of pitch-clas sets.
// @in 1 @type int @digest Modulo


// OUTLETS

// @out 0 @type llll @digest Complement of pitch-class set
// @description	If a tree of pitch-class sets was given, the output is a tree of complement pitch-class sets maintaining the same shape.


// ARGUMENTS

// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
// @description @copy BACH_DOC_SETTHEORY_MODULO