/*
 *  dx2x.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
	dx2x.c
	
	@name 
	bach.dx2x
	
	@realname 
	bach.dx2x

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Build llll from element differences
	
	@description
	Constructs an llll starting from a given number
	and then summing one by one the numeric steps 
	contained in the incoming differences llll.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	integrate, discrete, difference, build, construct, sum, number, start, step

	@seealso
	bach.x2dx
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set llll containing differences
// @description An llll in the second inlet is considered to 
// be the llll containing the difference, i.e. the numeric steps
// used to build the final llll.

// @method number @digest Set starting number, build llll
// @description Any number in the left inlet is considered
// as the starting number and triggers the output
// of the rebuilt llll, which is obtained as follows:
// the first element of the resulting llll is the starting number itself, 
// then every subsequent element is the sum of the previous one element
// plus the corresponding element of the differences llll.

// @method bang @digest Output result
// @description Performs and outputs the calculation on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "triggers", 0, t_dx2x, n_triggers);
CLASS_ATTR_FILTER_CLIP(c, "triggers", 1, 2);
CLASS_ATTR_STYLE(c, "triggers", 0, "Triggers");	
// @description Number of the inlet which triggers the result output. By default this is 1, but you can 
// set it to 2 in order to trigger the calculation via the right inlet.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type number @digest The starting number
// @in 1 @type llll @digest The differences llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The built llll



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name start_val @optional 1 @type number @digest Starting value
// @description Sets the default starting value for the built llll.
