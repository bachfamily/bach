/*
 *  belong.c
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
	belong.c
	
	@name 
	bach.belong
	
	@realname 
	bach.belong

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Tell if some elements belong to a llll
	
	@description
	Tells if one or more elements belong to a given llll.
	The condition for which an element belongs to the llll can be customized via
	a lambda loop.

	@discussion
	The lambda behavior work like for <o>bach.intersection</o>, of which 
	this abstraction is a small wrapper.
	An element of the first collection is said to be equal to an element
	of the second llll according the a custom operator.	<br /> <br />
	@copy BACH_DOC_LAMBDA
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	belong, lambda loop, equal, include

	@seealso
	bach.find, bach.intersection, bach.thin, bach.union, bach.filter	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description In the first inlet, an llll will set the collection of elements to be matched, 
// and will trigger the output of the answer, whether all these elements belong to the 
// contained defined in the middle inlet.<br />
// In the second inlet, an llll will set the possible container of such elements. <br />
// In the third inlet, an llll is converted into an <m>int</m>.

// @method int @digest Lambda inlet
// @description Third inlet is a lambda inlet. <br /> 
// @copy BACH_DOC_LAMBDA_INLET_EQUALITY

// @method bang @digest Tell if elements belong to the llll
// @description Outputs the answer obtained from the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The elements to be found
// @in 1 @type llll @digest The llll possibly containing the elements 
// @in 2 @type int/llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_EQUALITY



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest 1 if all elements belong to the llll container, 0 otherwise
// @out 1 @type llll @digest First lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_EQUALITY
// @out 2 @type llll @digest Second lambda outlet
// @description @copy BACH_DOC_LAMBDA_OUTLET_EQUALITY



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name possible_container @optional 1 @type llll @digest Possible container  
// @description The argument is an llll which might be the possible container 
// of the elements expected in the first inlet (this llll can also be set via second inlet).
