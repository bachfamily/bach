/*
 *  dsort.c
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
	dsort.c
	
	@name 
	bach.dsort
	
	@realname 
	bach.dsort

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Sort llll by distances
	
	@description
	Sorts a list depending to the distance of its 
	element to a given fixed number (nearest elements coming first, farthest element at the end).
	
	@discussion
	<o>bach.dsort</o> is a small wrapper of <o>bach.sort</o>.

	@category
	bach, bach abstractions, bach llll

	@keywords
	sort, distance, element, number

	@seealso
	bach.sort, bach.ssort, bach.msort
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Sort llll and output result, set reference number
// @description If the llll comes through the left inlet, its are sorted by 
// their distances with respec to the reference number defined in the second inlet
// (nearest elements coming first, farthest elements appearing at the end).
// The sorted llll is thus output from the left outlet, right after the list of indices of the 
// sorted elements with respect to the original llll has been also output from the right outlet. <br />
// Any llll coming in the second inlet is considered to contain the reference number for all distances

// @method int @digest Set the reference number
// @description Any number coming from the second inlet
// will be considered as the reference number for all distances.

// @method float @digest Set the reference number
// @description Any number coming from the second inlet
// will be considered as the reference number for all distances.

// @method float @digest Set the time interval
// @description A float in the second inlet sets or changes the 
// interval (in milliseconds) between two consecutively output elements.

// @method bang @digest Sort llll and output result
// @description Sorts the most recently received input llll with respect to the
// most recently received reference number.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be sorted
// @in 1 @type number @digest The reference number

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The sorted llll
// @out 1 @type llll @digest The sorted indices


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name reference_number @optional 1 @type number @digest Reference number
// @description The optional argument is the reference number. Distances are thus computed with respect
// to this number.
