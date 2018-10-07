/**
	@file
	mrandom.c
	
	@name 
	bach.mrandom
	
	@realname 
	bach.mrandom

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Obtain a random matrix	
	
	@description
	Builds a random matrix of given dimensions, 
	randomly picking elements from a given set of possible elements.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, random, build, size, element, pick

	@seealso
	bach.minfo, bach.diag, bach.idmatrix, bach.wellshape, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method bang @digest Build the random matrix 
// @description A <m>bang</m> in the left inlet builds the random matrix.

// @method int @digest Set matrix size
// @description An integer in the second inlet sets the number of rows;
// an integer in the third inlet sets the number of columns.

// @method list @digest Set list of possible element
// @description A list in the fourth inlet sets a list of possible
// elements. Each cell of the matrix will be build by randomly picking
// one of these elements.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type bang @digest bang to build random matrix
// @in 1 @type int @digest Number of rows
// @in 2 @type int @digest Number of columns
// @in 3 @type llll @digest List of possible elements

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The random matrix



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name numrows @optional 1 @type int @digest Number of rows
// @description Number of rows of the matrix to be built. By default it is 3.

// @arg 1 @name numcolumns @optional 1 @type int @digest Number of columns
// @description Number of columns of the matrix to be built.
// If this is not set, but the number of rows is specified, a 
// square matrix will be built. Otherwise, the default is 3.

// @arg 2 @name elems @optional 1 @type list @digest List of possible elements
// @description Each cell of the matrix will be build by randomly picking
// one of these elements. By default this is <b>0 1</b>.
