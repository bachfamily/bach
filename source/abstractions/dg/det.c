/**
	@file
	det.c
	
	@name 
	bach.det
	
	@realname 
	bach.det

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the determinant of a matrix
	
	@description
	Computes the determinant of the incoming matrix. <br />
	For non-square matrices, the product of the pivots is output. 
	
	@discussion
	The determinant of the matrix is computed by Gaussian elimination and then 
	by taking the product of pivots. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	determinant, matrix, calculate, compute, Gauss elimination
	
	@seealso
	bach.trace, bach.gausselim, bach.rank, bach.inv, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output determinant of incoming matrix
// @description The object outputs the determinant of the incoming matrix. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output determinant
// @description Outputs the determinant of the most recently input matrix.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The determinant of the incoming matrix



// ---------------
// ARGUMENTS
// ---------------

// (none)
