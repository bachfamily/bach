/*
 *  pitchunpack.c
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
	pitchunpack.c
	
	@name
	bach.pitchunpack
	
	@realname
	bach.pitchunpack
 
	@type
	abstraction
	
	@module
	bach
 
	@author
	bachproject
	
	@digest
	Separate components of pitches
	
	@description
	Retrieves degrees, alterations and octaves from an llll of pitches.
	
	@discussion
 
	@category
	bach, bach abstractions, bach math, bach pitches
 
	@keywords
	calculate, compute, pitch, number
 
	@seealso
	bach.expr, bach.pitchpack
	
	@owner
	Andrea Agostini
 */

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the pitches
// from which to extract their components and output the result.

// @method bang @digest Output result
// @description Extracts the pitches from the most recently received llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {
    
    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
    
CLASS_ATTR_LONG(c, "degreesym", 0, t_pitchunpack, degreesym); 
CLASS_ATTR_STYLE_LABEL(c,"degreesym",0,"text","Output Degrees As Letters");
CLASS_ATTR_BASIC(c,"degreesym",0);
// @description Toggles the ability to output the degrees as letters (C to B) instead of numbers (0 to 6).


}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Pitches llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The degrees
// @out 1 @type llll @digest The alterations
// @out 2 @type llll @digest The octaves



// ---------------
// ARGUMENTS
// ---------------

// (none)
