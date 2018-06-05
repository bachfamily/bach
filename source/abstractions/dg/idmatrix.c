/**
	@file
	idmatrix.c
	
	@name 
	bach.idmatrix
	
	@realname 
	bach.idmatrix

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Build identity matrix
	
	@description
	Builds the identity square matrix of a given size. 
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus
	
	@keywords
	matrix, identity, build, square, size
	
	@seealso
	bach.idvector, bach.minfo, bach.diag, bach.mrandom, bach.wellshape, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Build the identity matrix of the incoming size
// @description The identity matrix having as size the incoming integer is built.

// @method bang @digest Build the identity matrix
// @description Builds the identity matrix with the most recently input size.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The size of the matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The built identity matrix



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name size @optional 1 @type int @digest Size  
// @description The size of the identity matrix to be built.