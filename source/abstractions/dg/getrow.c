/**
	@file
	getrow.c
	
	@name 
	bach.getrow
	
	@realname 
	bach.getrow

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Get a row of a matrix
	
	@description
	Extracts a row of a matrix in llll form.
	
	@discussion

	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	row, matrix, extract, pick

	@seealso
	bach.getcol, bach.submatrix, bach.nth, bach.minfo
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set matrix and output requested row
// @description An llll in the first is interpreted as the matrix whose row has to be extracted.
// Such row is then output from the outlet.

// @method int @digest Set column index
// @description An integer in the second inlet sets the index of the row
// which has to be extracted (1 being the first row, 2 being the second, and so on).

// @method bang @digest Output row
// @description Performs the extraction on most recently received input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix in llll form
// @in 1 @type int @digest The index of the row

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The extracted row


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name row-index @optional 1 @type int @digest Row index
// @description The optional integer argument sets the row index.
