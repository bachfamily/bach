/**
	@file
	keychain.c
	
	@name 
	bach.keychain
	
	@realname 
	bach.keychain

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Organize lllls by keys
	
	@description
	Classifies the elements of the incoming llll, by associating them with corresponding keys, 
	and then by outputting the llll organized by keys.
	
	@discussion

	@category
	bach, bach abstractions, bach llll

	@keywords
	keychain, tag, organize, arrange, key, lambda loop
	
	@seealso
	bach.keys
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Organize and output llll
// @description An <m>llll</m> in the left inlet is considered the llll to be organised.
// Elements are output one by one from the right outlet, so that the user can retrieve their
// corresponding keys. Once the keys are re-injected, all the incoming llll is classified
// by keys. The output llll has the form <b>(<m>key1</m> <m>ELEM11</m> <m>ELEM12</m>...)
// (<m>key2</m> <m>ELEM21</m> <m>ELEM22</m>...)</b>, where all the <m>ELEM</m>s are the original
// elements of the list having the corresponding keys. Of course, each element shows up
// in the final list as many times as the number of its keys. <br />
// An llll in the second inlet is considered to be the "answer" of the lambda loop. 
// Indeed second inlet is a lambda inlet. <br />
// @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// @method bang @digest Organize and output llll
// @description Organize and outpu the most recently received input llll.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be organized
// @in 1 @type llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The organized llll
// @out 1 @type llll @digest Lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION


// ---------------
// ARGUMENTS
// ---------------

// (none)
