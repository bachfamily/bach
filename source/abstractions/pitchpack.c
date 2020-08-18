/*
 *  pitchpack.c
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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
	pitchpack.c
	
	@name
	bach.pitchpack
	
	@realname
	bach.pitchpack
 
	@type
	abstraction
	
	@module
	bach
 
	@author
	bachproject
	
	@digest
	Make pitches from their components
	
	@description
	Generates pitches from their degrees, alterations and octaves.
	
	@discussion
	The abstraction is equivalent to calling the <b>makepitch</b> function
	in a <o>bach.expr</o> object, with the <m>scalarmode</m>
	attribute set to 1.
 
	@category
	bach, bach abstractions, bach math, bach pitches
 
	@keywords
	calculate, compute, pitch, number
 
	@seealso
	bach.expr, bach.pitchunpack
	
	@owner
	Andrea Agostini
 */

// ---------------
// METHODS
// ---------------

// @method llll @digest Set operand, output result
// @description An llll in the first inlet will set the degrees
// (from 0 = C to 6 = B) for the pitch, and will output the result;
// an llll in the second inlet will set the alterations for the pitches
// (1/2 = sharp, -1/2 = flat, 1/4 = quarter-sharp, and so on)
// without outputting any result;
// an llll in the third inlet will set the octaves for the pitches
// (middle C is in octave 5) without outputting any result.<br />
// @copy BACH_DOC_OPERATION_ABSTRACTIONS_LLLL_AND_NUMBERS_REMARK

// @method bang @digest Output result
// @description Generate the pitches according to the most recently received input lllls.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {
    
    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
    
}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Degrees llll
// @in 1 @type llll @digest Alterations llll
// @in 2 @type llll @digest Octaves llll



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The generated pitches



// ---------------
// ARGUMENTS
// ---------------

// (none)
