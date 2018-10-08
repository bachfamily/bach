/**
	@file
	rank.c
	
	@name 
	bach.rank
	
	@realname 
	bach.rank

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the rank of a matrix
	
	@description
	Computes the rank of the incoming matrix.
	
	@discussion
	The determinant of the matrix is computed by Gaussian elimination and then 
	by counting the number of pivots. By convention the rank of <b>null</b> is -1 and
	the rank of <b>[]</b> is 0. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	rank, calculate, compute, Gauss elimination, linear independence, matrix
	
	@seealso
	bach.gausselim, bach.det, bach.inv, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output rank of incoming matrix
// @description The object outputs the rank of the incoming matrix. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output rank
// @description Outputs the rank of the most recently input matrix.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest The rank of the incoming matrix



// ---------------
// ARGUMENTS
// ---------------

// (none)
