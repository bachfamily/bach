/*
 *  period.c
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
	period.c
	
	@name 
	bach.period
	
	@realname 
	bach.period

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find the period of an llll
	
	@description
	Finds the minimal period of an incoming llll,
	i.e. the shortest llll which, if repeated, yields the original llll.

	@discussion

	@category
	bach, bach abstractions, bach llll

	@keywords
	period, periodicity, loop, repeat
	
	@seealso
	bach.group, bach.repeat, bach.pcsetinfo, bach.istruct
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Find period of llll
// @description An llll in the first inlet will trigger the calculation of its period.
// The period will be output from the first outlet, right after that its length has been
// output from the second one. For instance, the llll <b>a b c a b c a b c a b c</b> has
// period <b>a b c</b>, having length 3; similarly, the llll <b>91 8 2 4</b> has period
// <b>91 8 2 4</b> having length 4 (also, one can say that it is non-periodic).

// @method bang @digest Output period
// @description Outputs the period of the most received input llll.




// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The period of the incoming llll
// @out 1 @type int @digest The length of the period of the incoming llll


// ---------------
// ARGUMENTS
// ---------------

// (none)
