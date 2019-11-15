/*
 *  nearest.c
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
	nearest.c
	
	@name 
	bach.nearest
	
	@realname 
	bach.nearest

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Snap numbers to nearest elements of an llll
	
	@description
	Snaps each number of an incoming llll to the
	nearest number of a given reference plain llll. The snapped elements
	are output, as well as their distances to the original
	elements and the indices of the chosen elements in the reference llll.

	@discussion

	@category
	bach, bach abstractions, bach llll

	@keywords
	snap, nearest, distance, grid, list

	@seealso
	bach.sort, bach.msort, bach.ssort, bach.dsort
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet will be considered as the llll whose elements
// have to be snapped to the reference llll. Elements are snapped, and the list of 
// the nearest elements (shaped as the original) is output from the first outlet.
// Before that, the list of distances of snapped elements with the original ones is output
// from the third outlet, and the llll containing for each element the index of its nearest
// element in the reference llll is output from the second outlet.
// All lllls have the same structure as the original llll. <br />
// An llll in the second inlet is considered to be the reference plain llll ("grid") 
// to which elements should be snapped.

// @method bang @digest Snap elements
// @description Performs the snapping on the most received input lllls.




// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "absolute", 0, t_nearest, absolute); 
CLASS_ATTR_STYLE_LABEL(c,"absolute",0,"text","Output Absolute Distances");
CLASS_ATTR_BASIC(c,"absolute",0);
// @description If the <m>absolute</m> attribute is set to 1 (default),
// absolute distances are output from the third outlet (see <m>llll</m> method),
// otherwise differences between the snapped elements and the
// original ones are output.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll whose elements must be snapped
// @in 1 @type llll @digest The reference plain llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing snapped elements
// @out 1 @type llll @digest The llll containing indices of snapped elements
// @out 2 @type llll @digest The llll containing distances between snapped elements and original ones


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name reference_grid @optional 1 @type llll @digest Reference plain llll, or "grid"  
// @description The optional argument sets the initial reference plain llll (or "grid") to which each incoming elements should be snapped.
