/**
	@file
	combinevoices.c
	
	@name 
	bach.combinevoices
	
	@realname 
	bach.combinevoices

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Combine voices into a new bach.roll or bach.score
	
	@description
	Takes in input a list of <o>bach.roll</o>'s or <o>bach.score</o>'s gathered syntaxes and
	combines them to make a new object listing all the input voices.<br />
	
	@discussion
	Markers and all flags (such as solo/mute flags) are all preserved and combined.
	Users can choose which incoming bach.roll or bach.score will be considered for the slotinfo
	and commands information. <br /> <br />
	@copy BACH_DOC_SLOTINFO_GENERAL
	@copy BACH_DOC_COMMANDS_GENERAL

	@category
	bach, bach abstractions, bach notation

	@keywords
	join, combine, voice, measured, proportional

	@seealso
	bach.roll, bach.score, bach.join
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Combine incoming voices and output result
// @description <o>bach.combinevoices</o> expects a list of bach.roll's or bach.score's gathered-syntax
// dump, each wrapped in a level of parenthesis (for instance, by using <o>bach.join</o> with <m>inwrap</m> 1).
// Once it receives such list, it combines all the voices of the received objects into a new bach.roll
// or bach.score, listing all the voices one by one, in the intput order. <br />
// If you don't want all the voices of some bach.roll or bach.score to be considered,
// you can use the <m>subroll</m> or <m>subscore</m> messages instead of the simple <m>dump</m>.

// @method bang @digest Combine voices
// @description Combines the most recently received input lllls.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "slotinfo", 0, t_combinevoices, slotinfo); 
CLASS_ATTR_STYLE_LABEL(c,"slotinfo",0,"text","Preserve Slotinfo");
CLASS_ATTR_BASIC(c,"slotinfo",0);
// @description Index of incoming bach.roll or bach.score whose slotinfo must be
// preserved in the output. By default this is 1 (the first). Leave it to 0
// if you don't want to have any slotinfo output.

CLASS_ATTR_LONG(c, "commands", 0, t_combinevoices, commands); 
CLASS_ATTR_STYLE_LABEL(c,"commands",0,"text","Preserve Commands");
CLASS_ATTR_BASIC(c,"    ",0);
// @description Index of incoming bach.roll or bach.score whose commands must be
// preserved in the output. By default this is 1 (the first). Leave it to 0
// if you don't want to have any commands output.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest List of bach.score's or bach.roll's gathered syntaxes 
// @description The llll musc contain the bach.roll's or bach.score's gathered syntax,
// one level of parenthesis for each one of them (so, for instance, you can append their dump 
// output via a <o>bach.join</o> with <m>inwrap</m> 1).

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The gathered syntax of the combined bach.roll or bach.score


// ---------------
// ARGUMENTS
// ---------------

// (none)
