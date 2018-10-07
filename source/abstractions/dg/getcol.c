/**
	@file
	getcol.c
	
	@name 
	bach.getcol
	
	@realname 
	bach.getcol

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Get a column of a matrix
	
	@description
	Extracts a column of a matrix in llll form.
	
	@discussion

	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	column, matrix, extract, pick
	
	@seealso
	bach.getrow, bach.submatrix, bach.nth, bach.trans, bach.minfo
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set matrix and output requested column
// @description An llll in the first is interpreted as the matrix whose column has to be extracted.
// Such column is then output from the outlet.

// @method int @digest Set column index
// @description An integer in the second inlet sets the index of the column
// which has to be extracted (1 being the first column, 2 being the second, and so on).

// @method bang @digest Output column
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
// @in 1 @type int @digest The index of the column

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The extracted column


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name column-index @optional 1 @type int @digest Column index
// @description The optional integer argument sets the column index.
