/**
	@file
	m2jitcellblock.c
	
	@name 
	bach.m2jitcellblock
	
	@realname 
	bach.m2jitcellblock

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Display the content of an llll matrix in a jit.cellblock
	
	@description
	Shows the content of an llll matrix in the <o>jit.cellblock</o> object.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, display, convert, cell, jit.cellblock

	@seealso
	jit.cellblock, bach.m2matrixctrl, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert llll matrix to jit.cellblock 
// @description The needed information to fill a <o>jit.cellblock</o> with the incoming matrix is output. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Build jit.cellblock
// @description Fills a <o>jit.cellblock</o> with the most recently input matrix.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

CLASS_ATTR_LONG(c, "unwrap", 0, t_m2jitcellblock, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"text","Unwrap");
CLASS_ATTR_BASIC(c,"unwrap",0);
// @description If the <m>unwrap</m> attribute is set to 1, every llll in each
// cell is flattened by its outmost level of parenthesis. Default is 0.

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest Messages for jit.cellblock



// ---------------
// ARGUMENTS
// ---------------

// (none)
