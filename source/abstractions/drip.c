/*
 *  drip.c
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
	drip.c
	
	@name 
	bach.drip
	
	@realname 
	bach.drip

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Automatically step through lllls with delays
	
	@description
	The purpose of <o>bach.drip</o> is to automatically output elements of an llll,
	with a given delay between each couple of output elements.
	
	@discussion

	@category
	bach, bach abstractions, bach llll

	@keywords
	drip, iterate, delay, metro, sequence, step

	@seealso
	bach.step
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set the llll and start dripping
// @description An llll in the first inlet will immediately begin to be stepped through,
// and its elements will be output one by one (according to the <m>maxdepth</m> attribute)
// with delays given by the interval set in the right inlet.
// Each element address will be output from the second outlet, before the corresponding
// element itself be output from the first outlet, as for <o>bach.step</o>. <br />
// @copy BACH_DOC_ADDRESS_BASIC

// @method int @digest Set the time interval
// @description An integer in the second inlet sets or changes the 
// interval (in milliseconds) between two consecutively output elements.

// @method float @digest Set the time interval
// @description A float in the second inlet sets or changes the 
// interval (in milliseconds) between two consecutively output elements.

// @method stop @digest Stop dripping
// @description A <m>stop</m> symbol will immediately stop the current dripping.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_drip, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
//	@description You can use a <m>maxdepth</m> attribute in order to decide how deep in 
//	the iteration <o>bach.drip</o> should go. <br />
// 	@copy BACH_DOC_MAXDEPTH

CLASS_ATTR_CHAR(c, "circular", 0, t_drip, circular); 
CLASS_ATTR_STYLE_LABEL(c,"circular",0,"text","Circular");
CLASS_ATTR_BASIC(c,"circular",0);
//	@description When set to 1, lllls are dripping in a circular fashion (i.e. after the last element
//	is reached, the first element is output again). Defaults to 0.

CLASS_ATTR_LONG(c, "unwrap", 0, t_drip, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"onoff","Unwrap");
// @description When set to 1, every outgoing llll is flattened by its outermost level parentheses.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be stepped through
// @in 1 @type int/float @digest The time interval in milliseconds

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The currently output element
// @out 1 @type llll @digest The currently output element address
// @description @copy BACH_DOC_ADDRESS_BASIC
// @out 2 @type bang @digest A bang when dripping is completed


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name interval @optional 0 @type number @digest Time interval
// @description Initial dripping time interval (in milliseconds). 
// This could be either an integer or a float.
