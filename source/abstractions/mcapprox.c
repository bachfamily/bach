/*
 *  mcapprox.c
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
	mcapprox.c
	
	@name 
	bach.mcapprox
	
	@realname 
	bach.mcapprox

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Snap midicents to microtonal grid
	
	@description
	Approximates the incoming midicents llll with the nearest pitches in the 
	full chromatic range of the chosen microtonal grid.
	
	@discussion
	The conversion depends on the microtonal division, which is the <m>tonedivision</m> attribute
	of <o>bach.roll</o> and <o>bach.score</o>. 
	The relationship with the modulo is: modulo/6 = tonedivision. <br /> <br />
	@copy BACH_DOC_TONEDIVISION
	@copy BACH_DOC_SETTHEORY_MODULO

	@status
	deprecated

	@category
	bach, bach abstractions, bach notation

	@keywords
	cent, midicent, approximate, snap, grid, microtone, nearest, pitch

	@seealso
	bach.expr, bach.mc2pc, bach.pc2mc
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Snap midicents llll to microtonal grid
// @description The function outputs an llll formatted as the incoming one, where each numeric
// element has been replaced by the nearest element in the choosen temperament. 
// For instance, if the modulo is 12, the number 6020 would be snapped to the number 6000 
// (precise midicents of middle C). The same number, with modulo = 48, would be snapped to 6025
// (one eighth-tone above). The temperament is defined by the tone division, set in the right inlet.
// <br /> <br />
// @copy BACH_DOC_TONEDIVISION

// @method bang @digest Output snapped midicents
// @description Performs the operation on the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing original midicents
// @in 1 @type int @digest The microtonal division
// @description @copy BACH_DOC_TONEDIVISION


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing snapped midicents



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name tonedivision @optional 1 @type int @digest Microtonal division  
// @description @copy BACH_DOC_TONEDIVISION
