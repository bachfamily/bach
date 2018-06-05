/**
	@file
	inv.c
	
	@name 
	bach.inv
	
	@realname 
	bach.inv

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the inverse of a matrix
	
	@description
	Computes the inverse of a square matrix or  
	reports when such inverse could not be computed.
	
	@discussion
 	The algorithm used to compute the matrix inverse is the Gaussian elimination algorithm.
 	If the matrix is singular, the inverse does not exists, and bach.inv outputs a bang from
	its middle outlet. If the matrix is not well-shaped or not square, 
	bach.inv outputs a bang from its right outlet. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, inverse, compute, calculate, Gauss elimination, singular, determinant, square, well-shaped
	
	@seealso
	bach.det, bach.gausselim, bach.rank, bach.trans, bach.wellshape, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output inverse of incoming matrix
// @description The object outputs the inverse of the incoming matrix (if any). <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Output inverse
// @description Outputs the inverse of the most recently input matrix (if any).


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

// @out 0 @type llll @digest The inverse of the incoming matrix, if any
// @out 1 @type bang @digest bang if the incoming matrix is singular
// @description If the matrix is singular (i.e. its determinant is 0), it has no inverse, and a bang is output.
// @out 2 @type bang @digest bang if the incoming matrix is not well-shaped or not square



// ---------------
// ARGUMENTS
// ---------------

// (none)
