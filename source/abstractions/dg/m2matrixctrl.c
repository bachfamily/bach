/**
	@file
	m2matrixctrl.c
	
	@name 
	bach.m2matrixctrl
	
	@realname 
	bach.m2matrixctrl

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Format an llll matrix to be used with matrixctrl or matrix~
	
	@description
	Converts an llll matrix in order to pilote a <o>matrix~</o> or a <o>matrixctrl</o> object.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach abstractions, bach matrix calculus

	@keywords
	matrix, matrixctrl, convert

	@seealso
	matrixctrl, matrix~, router, bach.matrixctrl2m, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert llll matrix to matrixctrl or matrix~ form 
// @description The needed information to fill a <o>matrixctrl</o> with the incoming llll matrix is output. The same information can be sent to <o>matrix~</o> in order to pilote it. <br />
// @copy BACH_DOC_MATRIXCALCULUS_MATRIX

// @method bang @digest Convert llll matrix
// @description Performs the conversion on the most recently input matrix.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

CLASS_ATTR_CHAR(c, "autosize", 0, t_m2matrixctrl, autosize); 
CLASS_ATTR_STYLE_LABEL(c,"autosize",0,"onoff","Autosize");
CLASS_ATTR_BASIC(c,"autosize",0);
// @description Use the <m>autosize</m> attribute to automatically
// set the size of the destination <o>matrixctrl</o>, according to the size
// of the incoming llll matrix. Don't use it when piloting a 
// <o>matrix~</o> object.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll matrix


// ---------------
// OUTLETS
// ---------------

// @out 0 @type list @digest Messages for matrixctrl or matrix~



// ---------------
// ARGUMENTS
// ---------------

// (none)
