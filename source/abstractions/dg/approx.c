/**
	@file
	approx.c
	
	@name 
	bach.approx
	
	@realname 
	bach.approx

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Snap pitches or MIDIcents to microtonal grid
	
	@description
	Approximates the incoming llll containing pitches or MIDIcents 
	with the nearest pitches or MIDIcents in a specific microtonal grid.
	
	@discussion
	The conversion depends on the microtonal division, which is the <m>tonedivision</m> attribute
	of <o>bach.roll</o> and <o>bach.score</o>. 
	The relationship with the modulo is: modulo/6 = tonedivision. <br /> <br />
	@copy BACH_DOC_TONEDIVISION
	@copy BACH_DOC_SETTHEORY_MODULO
	
	@category
	bach, bach abstractions, bach notation, bach pitches

	@keywords
	cent, midicent, approximate, snap, grid, microtone, nearest, pitch

	@seealso
	bach.expr, bach.mc2pc, bach.pc2mc
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Snap midicents llll to microtonal grid
// @description The function outputs an llll formatted as the incoming one, where each numeric
// element has been replaced by the nearest element in the choosen microtonal temperament.
// The same holds true for any pitch in the incoming llll. 
// For instance, if the modulo is 12 (i.e. tonedivision = 2), the number 6020 would be snapped to the number 6000 
// (precise midicents of middle C). The same number, with modulo = 48, would be snapped to 6025
// (one eighth-tone above). The temperament is defined by the tone division, set in the right inlet.
// As another example, if the modulo is 12 (tonedivision = 2), the pitch C#^4 will be snapped to C#4.
// <br /> <br />
// @copy BACH_DOC_TONEDIVISION

// @method bang @digest Output snapped pitches and MIDIcents
// @description Performs the operation on the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing original pitches or MIDIcents
// @in 1 @type int @digest The microtonal division
// @description @copy BACH_DOC_TONEDIVISION


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing snapped pitches or MIDIcents



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name tonedivision @optional 1 @type int @digest Microtonal division  
// @description @copy BACH_DOC_TONEDIVISION