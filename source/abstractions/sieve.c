/*
 *  sieve.c
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
	@file
	sieve.c
	
	@name 
	bach.sieve
	
	@realname 
	bach.sieve

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Only let some elements through
	
	@description
	Retains all the elements of an llll satisfying a given condition.
	
	@discussion
	The condition can be defined either via a predefined operator,
	or via the lambda loop. <br />
	@copy BACH_DOC_LAMBDA

	@category
	bach, bach abstractions, bach llll

	@keywords
	filter, keep, retain, let through, condition, if, lambda loop, operator, element

	@seealso
	bach.filter, bach.thin, bach.find, bach.filternull, Iterations 
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description
// In first inlet: retains only some elements of the incoming llll, and output them from the first outlet. 
// In second inlet: sets the comparison value for the specified operator (see <m>op</m> attribute).
// If a lambda loop is not present, the filtering is performed
// by applying such operator on all elements of the llll coming in the first inlet, with the specified comparison value, 
// and all elements satisfying the condition (for which the operator returns a non-zero value) are retained, while
// all elements for which the condition is not matched (operator returning zero) are dropped.
// For instance, if the operator is <b>&gt;</b>, with comparison value <b>1</b>, and the llll coming
// through the first inlet is <b>0 [1.1 -2 [4 3/2 -5.2]]</b>, the output llll will be <b>[1.1 [4 3/2]]</b>, i.e.
// only elements greater than 1 have been retained.
// If a lambda loop is present the llll received in the second inlet is ignored,
// the chunks (whose size is determined by the <m>size</m> attribute) are output from the lambda outlet
// and a comparison result is expected in the lambda inlet.
// In third inlet (lambda inlet): an llll is converted to an int.


// @method int @digest Lambda inlet
// @description
// The criterium by which a given element or sequence of elements is considered a match, and retained,
// can be customized through an optional lambda loop.
// If the lambda loop is present, the <m>op</m> attribute and the llll received in the second inlet are ignored,
// and elements are output one by one from the lambda outlet.
// The lambda loop should return 1 to the third inlet if the element or sequence is a match, 0 if it is not.


// @method bang @digest Perform last operation
// @description A <m>bang</m> in the first inlet outputs the result of the sieving on the most recently received llll
// and with the current matching criteria.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


CLASS_ATTR_LONG(c, "maxdepth",		0,	t_sieve, n_maxdepth);
CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
CLASS_ATTR_BASIC(c, "maxdepth", 0);
// @description You can customize the maximum level of depth for filtering via the <m>maxdepth</m> attribute.
// Any element beyond the defined <m>maxdepth</m> will be let through. <br />
// @copy BACH_DOC_MAXDEPTH


CLASS_ATTR_SYM(c, "op",	0,	t_sieve,	n_op);
CLASS_ATTR_LABEL(c, "op", 0, "Comparison Operator");
CLASS_ATTR_BASIC(c, "op", 0);
// Sets the comparison operator by which elements of the llll in the first inlet are compared to the element in the second inlet.
// Valid operators are <m>==</m>, <m>!=</m>, <m>===</m>, <m>!==</m> 
// (the two last being as <o>bach.==</o> and <o>bach.!=</o> with <m>matchtype 1</m>),
// <m>&lt;</m>, <m>&lt;=</m>, <m>&gt;</m>, <m>&gt;=</m>.
// The <m>op</m> attribute is ignored if a lambda loop is present.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The original llll
// @in 1 @type llll @digest Comparison value
// @in 2 @type int/llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MATCH



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing the retained elements
// @out 1 @type llll @digest Lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_MATCH



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name comparison @optional 1 @type llll @digest Default comparison llll
// @description A default comparison llll. Ignored if a lambda loop is present.
