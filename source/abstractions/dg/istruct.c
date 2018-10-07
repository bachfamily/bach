/**
	@file
	istruct.c
	
	@name 
	bach.istruct
	
	@realname 
	bach.istruct

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Get the interval structure pitch-class set
	
	@description
	Reports the interval structure of a pitch-class set, i.e. the list
	of distances between consecutive elements of the (looped) set. 
	
	@discussion
	For instance, if modulo is 12 and the
	pitch-class set is <b>0 1 4 9</b>, distances are 1-0 = 1, 4-1 = 3, 9-4 = 5 and then we end the loop with
	0-9 = -9 = 3. Thus <b>1 3 5 9</b> is the interval structure of our pitch-class set. 
	Of course this interval structure depends on the chosen modulo (for looping). <br /> <br />
	N.B.: Interval structure is a different concept than interval vector. Refer to <o>bach.ivec</o> if you
	were looking for it. <br /> <br />
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	
	@category
	bach, bach abstractions, bach set theory

	@keywords
	interval structure, interval, modulo, pitch-class, distance, element, loop

	@seealso
	bach.primeform, bach.circle, bach.mod+, bach.mod-, bach.modtimes, bach.period, bach.ifunc
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Get interval structure of pitch-class set
// @description In the first inlet, a pitch-class set will report its interval structure

// @method bang @digest Output the interval structure
// @description Gets the interval structure of the most recently received input data.

// @method int @digest Set modulo 
// @description An integer in the right inlet will set the modulo. <br />
// @copy BACH_DOC_SETTHEORY_MODULO



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "autosort", 0, t_istruct, autosort); 
CLASS_ATTR_STYLE_LABEL(c,"autosort",0,"onoff","Autosort");
CLASS_ATTR_BASIC(c,"autosort",0);
//	@description Sort automatically the points in the pitch-class set before reporting the interval structure (by default it is set).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Pitch-class set(s)
//		 @description A complex tree of pitch-class sets is also accepted.
// @in 1 @type int @digest Modulo



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Interval structure(s)
//        @description  The interval structure of the incoming pitch-class set. If a complex tree of pitch-class sets was input,
//						the output is a tree of interval structures, mirroring it in shape.


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
// @description @copy BACH_DOC_SETTHEORY_MODULO

// @arg 1 @name autosort @optional 1 @type int @digest Autosort  
// @description Sort automatically the points in the pitch-class set before reporting the interval structure (by default it is set).
