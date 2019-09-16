/*
 *  f2mc.c
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
	f2mc.c
	
	@name 
	bach.f2mc
	
	@realname 
	bach.f2mc

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Frequency to midicents conversion
	
	@description
	Converts an llll containing frequencies (in Hertz) into an identically structured llll containing the corresponding midicents.
	
	@discussion
	
	@category
	bach, bach abstractions, bach math

	@keywords
	frequency, cent, midicent, convert, pitch

	@seealso
	bach.mc2f, mtof, ftom, bach.n2mc, bach.mc2n, bach.mc2r, bach.r2mc, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert frequencies to midicents
// @description The function outputs an llll formatted as the incoming one, but containing the midicents value 
// instead of each frequency value. 

// @method bang @digest Perform the conversion
// @description Performs the conversion on the most recently input data.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing frequencies (in Hertz)
// @in 1 @type float @digest The reference frequency (A above middle C)
// @description Set the frequency (in Hertz) of the A above middle C. Default is 440 Hz.


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing midicents



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name base @optional 1 @type float @digest The reference frequency (A above middle C)
// @description Set the frequency (in Hertz) of the A above middle C. Default is 440 Hz.
