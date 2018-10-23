/**
	@file
	funnel.c
	
	@name 
	bach.funnel
	
	@realname 
	bach.funnel

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Index llll elements
	
	@description
	Index each llll element by prepending an increasing integer to it, and wrapping them
	in a pair of parentheses.
	
	@discussion
	From a list in the form <b>X Y Z W</b> one gets to a list in the form
	<b>[1 X] [2 Y] [3 Z] [4 W]</b>, where the offset and step of the numbering can
	be set via attributes

	@category
	bach, bach abstractions, bach llll

	@keywords
	index, funnel, enumerate, element, number

	@seealso
	listfunnel, bach.trans, bach.join
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Index incoming llll, output result
// @description An <m>llll</m> in the first inlet will be indexed so that each element will be 
// substituted by an llll in the form <b>[<m>index</m> <m>original_element</m>]</b>.
// By default, <m>index</m> starts from 1 and increases by 1 for each element of the original llll.
// These parameters can be changed via the arguments or the attributes.
// For instance a list in the form <b>X Y Z W</b> becomes <b>[1 X] [2 Y] [3 Z] [4 W]</b>.

// @method bang @digest Output result
// @description Outputs the indexed result on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_ATOM(c, "offset", 0, t_funnel, offset); 
CLASS_ATTR_STYLE_LABEL(c,"offset",0,"text","Offset");
CLASS_ATTR_BASIC(c,"offset",0);
// @description Set the initial number for the indexing (can be integer, rational or float).
// Defaults to 1.

CLASS_ATTR_ATOM(c, "step", 0, t_funnel, step); 
CLASS_ATTR_STYLE_LABEL(c,"step",0,"text","Step");
CLASS_ATTR_BASIC(c,"step",0);
// @description Set the step for the indexing (can be integer, rational or float).
// Defaults to 1.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Original llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Indexed llll



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name offset @optional 1 @type number @digest Offset
// @description Sets the initial number for the indexing (see <m>offset</m> attribute).
// Defaults to 1.

// @arg 1 @name step @optional 1 @type number @digest Step
// @description Sets the initial step for the indexing (see <m>step</m> attribute).
// Defaults to 1.
