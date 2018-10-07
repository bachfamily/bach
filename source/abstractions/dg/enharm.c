/**
	@file
	enharm.c
	
	@name 
	bach.enharm
	
	@realname 
	bach.enharm

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Handle enharmonicity
	
	@description
	Modifies the enharmonicity of the incoming pitches, either by adding diatonic
	steps, or via automatic respelling
	
	@discussion
	
	@category
	bach, bach abstractions, bach notation

	@keywords
	pitch, enharmonicity, retranscribe, respell, note

	@seealso
	bach.expr, bach.mc2pc, bach.pc2mc
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Change enharmonicity for pitches
// @description The function outputs an llll formatted as the incoming one, where each numeric
// pitch has been replaced by an enharmonic respelling, chosen according to the state of the right inlet. <br />
// If the right inlet (or argument) receives a number, this is assumed to be the number of diatonic steps
// to be added to the incoming ones. For instance, if the right inlet receives 2, a C#4 will be transcribed as Ebbb4,
// since two diatonic steps run between C to E. <br />
// If the right inlet (or argument) receives the "auto" symbol, the pitches are automatically respelled.

// @method bang @digest Perform enharmonic respell
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

// @in 0 @type llll @digest The llll containing original pitches
// @in 1 @type int @digest Difference in diatonic steps, or "auto" symbol


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing retranscribed pitches



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name delta_steps_or_auto @optional 1 @type int/auto @digest Delta steps or "auto" symbol  
// @description The argument sets the difference in diatonic steps (if it is an integer) or toggles the 
// automatic retranscription mode (if it is the "auto" symbol). See <m>llll</m> method to know more.
