/*
 *  pc2mc.c
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
	pc2mc.c
	
	@name 
	bach.pc2mc
	
	@realname 
	bach.pc2mc

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Pitch-classes to midicents conversion
	
	@description
	Converts an llll containing pitch-classes into an identically 
	structured llll containing the corresponding midicents.
	
	@discussion
	The conversion depends on the modulo (i.e. microtonal grid), and
	on the chosen base note. <br /> <br />
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	
	@category
	bach, bach abstractions, bach set theory

	@keywords
	pitch-class, cent, midicent, convert, pitch

	@seealso
	bach.mc2pc, bach.approx, bach.pcsetinfo, bach.expr
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert pitch-classes to midicents
// @description The function outputs an llll formatted as the incoming one, but containing the midicents
// value instead of each pitch-class. <br /> 
// The conversion is performed according to the introduced modulo, and to a given base note, which will
// correspond to the zero pitch-class. Any other (positive) pitch class will be placed above the base note.
// Nonstandard pitch-class numbers (below 0, or above the modulo) are also allowed, and will.
// The (nonstandard) pitch-class corresponding to the modulo will be placed exactly one octave above
// the base note. For instance, if modulo is 12, and the base note is 6000 (default), the pitch-class
// 12 (which is nonstandard) will correspond to 7200; the (standard) pitch-class 1 will correspond to 
// 6100, and so on.
// <br /> <br />
// @copy BACH_DOC_SETTHEORY_PC_AND_PCSET
// @copy BACH_DOC_SETTHEORY_MODULO

// @method bang @digest Perform the conversion
// @description Performs the conversion on the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing pitch-classes
// @in 1 @type int @digest The modulo
// @description @copy BACH_DOC_SETTHEORY_MODULO
// @in 2 @type float @digest The base note
// @description Midicents of the reference note, corresponding to the pitch-class 0.


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing midicents



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
// @description @copy BACH_DOC_SETTHEORY_MODULO

// @arg 1 @name basenote @optional 1 @type float @digest Base note  
// @description Midicents of the reference note, corresponding to the pitch-class 0.
