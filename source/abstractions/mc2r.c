/*
 *  mc2r.c
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
	mc2r.c
	
	@name 
	bach.mc2r
	
	@realname 
	bach.mc2r

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Interval to frequency ratio conversion
	
	@description
	Converts an llll containing intervals (expressed in midicents) into an identically structured llll
	containing the corresponding frequency ratios.
	Ratio is reported as a floating point value.
	
	@discussion
	
	@category
	bach, bach abstractions, bach math

	@keywords
	interval, cent, midicent, frequency, ratio, rational, convert

	@seealso
	bach.r2mc, bach.f2mc, bach.mc2f, Through The Looking Glass
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Convert intervals to ratios
// @description The function outputs an llll formatted as the incoming one, but containing the frequency ratio 
// instead of each interval. 

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

// @in 0 @type llll @digest The llll containing intervals (in midicents)


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The llll containing ratios
