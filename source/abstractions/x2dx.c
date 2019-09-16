/*
 *  x2dx.c
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
	x2dx.c
	
	@name 
	bach.x2dx
	
	@realname 
	bach.x2dx

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Take differences between element
	
	@description
	Returns the differences between each element's immediate
	follower and the element itself.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	derive, discrete, difference, take, subtract, number

	@seealso
	bach.dx2x
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Output differences
// @description Each element at the root level of the incoming llll
// is substituted with the difference between its follower and 
// the element itself. The resulting llll, which will have the same
// length of the input llll minus 1, is then output through the outlet.

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The original llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing differences



// ---------------
// ARGUMENTS
// ---------------

// (none)
