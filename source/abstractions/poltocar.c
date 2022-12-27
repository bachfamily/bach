/*
 *  poltocar.c
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
	poltocar.c
	
	@name 
	bach.poltocar
	
	@realname 
	bach.poltocar

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Polar to cartesian coordinate conversion for lllls
	
	@description
	Converts two lllls consisting of amplitudes (radii) and angle values (in radians)
	into two cartesian-coordinate lllls consisting of real and imaginary values.
	
	@discussion
	Incoming lllls must be equally structured in order for the result to be consistent	

	@category
	bach, bach abstractions, bach math

	@keywords
	polar, cartesian, coordinate, convert, amplitude, phase, angle, radius, real, imaginary, part

	@seealso
	bach.cartopol, bach.expr, bach.fft
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set amplitudes or phases, output result
// @description In the first inlet, an llll sets the amplitudes (radii), and output 
// the converted cartesian coordinates.<br />
// In the second inlet, an llll sets the phases (in radians). <br />
// As for <o>bach.expr</o> with the <m>scalarmode</m> attribute set to 1,
// the module automatically iterates lists against single elements

// @method bang @digest Perform conversion
// @description Performs the conversion on the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

}


// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest Amplitudes (radii)
// @in 1 @type llll @digest Phases (in radians)



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The real parts or X coordinates
// @out 1 @type llll @digest The imaginary parts or Y coordinates



// ---------------
// ARGUMENTS
// ---------------

// (none)
