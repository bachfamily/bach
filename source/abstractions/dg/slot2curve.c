/**
	@file
	slot2curve.c
	
	@name 
	bach.slot2curve
	
	@realname 
	bach.slot2curve

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a function-slot content into messages for <o>curve~</o>
	
	@description
	Converts the llll content of a given slot,
	of type "function", into a list of messages for <o>curve~</o>.
	
	@discussion

	@category
	bach, bach abstractions, bach notation

	@keywords
	slot, curve~, breakpoint function, convert, message

	@seealso
	curve~, bach.slot2line, bach.roll, bach.score, bach.slot
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set slot content
// @description An llll in the second inlet is considered as the function slot content.
// Typically this is obtained from <o>bach.playkeys</o>'s slot outlets.
// See below for the precise syntax of the slot content (for <o>bach.slot2curve</o> only
// syntax for function slots is relevant). <br />
// An llll in the fourth (lambda) inlet is considered as a floating point number in llll native form
// (see <m>float</m> message for more information).
// <br /> <br />
// @copy BACH_DOC_NOTE_SLOT_CONTENT

// @method float @digest Function depends on inlet
// @description A floating point number in the first inlet is considered as the overall duration of the function,
// and will trigger the output of the conversion of the slot content into messages for <o>curve~</o>, 
// output from the first outlet. <br /> 
// A floating point number in the third inlet sets a default value which will be 
// sent to <o>curve~</o> if no function is defined in the incoming slot (slot content is empty). <br />
// A floating point number in the fourth inlet is the answer of a lambda loop, allowing to remap function amplitudes. 
// This is handy, for instance, if you had a function slot representing amplitudes in decibels, and you need to convert
// them into linear amplitude representation in order to send them to <o>curve~</o>.
// Indeed, fourth inlet is a lambda inlet. <br /> 
// @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// @method bang @digest Output messages
// @description Outputs messages for <o>curve~</o>, based on the most recently received input data.


// ---------------
// ATTRIBUTES
// ---------------
 
void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type float @digest The duration of the function in milliseconds
// @in 1 @type llll @digest The llll containing the function slot content
// @in 2 @type float @digest The default value
// @in 3 @type float/llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest The messages for <o>curve~</o>
// @out 1 @type llll @digest Lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION

// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name default_value @optional 1 @type float @digest Default value  
// @description A floating point number given as argument sets a default value which will be 
// sent to <o>curve~</o> if no function is defined in the incoming slot (slot content is empty).