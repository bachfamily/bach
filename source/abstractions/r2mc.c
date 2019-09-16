/*
 *  r2mc.c
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
	r2mc.c
	
	@name 
	bach.r2mc
	
	@realname 
	bach.r2mc

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Frequency ratio to interval conversion
	
	@description
	Converts an llll containing frequency ratios into an identically structured llll
	containing the corresponding intervals (expressed in midicents).
	
	@discussion
	
	@category
	bach, bach abstractions, bach math

	@keywords
	interval, cent, midicent, frequency, ratio, rational, convert

	@seealso
	bach.mc2r, bach.f2mc, bach.mc2f, Through The Looking Glass
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert frequencies to midicents
// @description The function outputs an llll formatted as the incoming one, but containing the interval 
// instead of each frequency ratio. 

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

// @in 0 @type llll @digest The llll containing frequency ratios


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing intervals
