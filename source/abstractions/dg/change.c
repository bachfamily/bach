/**
	@file
	change.c
	
	@name 
	bach.change
	
	@realname 
	bach.change

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Filter out repetitions of an llll
	
	@description
	The purpose of <o>bach.change</o> is the to act like a <o>change</o> object for lllls, 
	outputting the incoming llll only if it differs from the one previously entered.	
	
	@discussion
	<o>bach.change</o> is initialized with a "null" llll, so if you send 
	a "null" llll as first llll, it will not be let through. <br />
	A <m>matchtype</m> argument will tell if type has to be taken into account
	for equality testing.

	@category
	bach, bach abstractions, bach llll

	@keywords
	filter, repetition, change

	@seealso
	change, bach.reg, bach.eq, bach.neq
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Let llll through if changed
// @description An <m>llll</m> in the first inlet is let through only if it is
// different from the previously received one. <o>bach.change</o> is initialized with 
// a "null" llll, so if you send a "null" llll as first llll, it will not 
// be let through. <br />
// An <m>llll</m> in second inlet is stored without triggering any output (as for the <m>set</m> message).

// @method set @digest Store llll without triggering any output
// @description An <m>llll</m> after the <m>set</m> message is stored without triggering any output (as for 
// lllls coming in the second inlet).
// @marg 1 @name llll @optional 0 @type llll



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be possibly filtered
// @in 1 @type llll @digest Set incoming llll without triggering output



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The incoming llll if it changed
// @out 1 @type bang @digest bang if the incoming llll hasn't changed


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name initial_llll @optional 1 @type llll @digest Set the initial stored llll
// @description Put an llll as argument to set the initially stored llll,
// so that the same incoming llll will not pass right after the abstraction
// instantiation.
