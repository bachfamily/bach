/**
	@file
	filternull.c
	
	@name 
	bach.filternull
	
	@realname 
	bach.filternull

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Let through every non-null input
	
	@description
	Takes the incoming data and
	outputs it through its first outlet only if it is 
	not a <b>null</b> llll; otherwise it sends a bang
	or a default llll through the second outlet.
	
	@discussion
	<o>bach.filternull</o> is slightly more efficient than
	using <o>bach.filter</o> with argument <b>- n</b>.
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	pass, filter, reject, accept, route, let through, null

	@seealso
	bach.filter, Hello World, Iterations, Slot Machines
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Let llll through if not null, bang otherwise, or set default
// @description An <m>llll</m> in the first inlet is immediately output through the left outlet
// if it is not <m>null</m>. If the incoming llll, on the other hand, is a <b>null</b> llll,
// a bang is sent through the second outlet, unless a default has been defined via the optional
// argument, or via the right inlet, in which case, this default llll is output from the
// second outlet instead. <br />
// An <m>llll</m> in the second inlet sets the default llll.

// @method bang @digest Revert to bang default
// A bang in the right inlet clears the default lllls and reverts <o>bach.filternull</o> to the 
// standard behavior, according to which it sends a bang from the second outlet once a
// <b>null</b> <m>llll</m> comes in.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The incoming llll
// @in 1 @type bang/llll @digest The default



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll if not null
// @out 1 @type bang @digest bang or default if incoming llll is null 


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name default @optional 1 @type llll @digest Default 
// @description The optional argument sets the initial default value which will be output,
// instead of the usual <m>bang</m>, from the second outlet when a <b>null</b> <m>llll</m> is input.
