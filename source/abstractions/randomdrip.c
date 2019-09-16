/*
 *  randomdrip.c
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
	randomdrip.c
	
	@name 
	bach.randomdrip
	
	@realname 
	bach.randomdrip

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Output random elements with delays
	
	@description
	Outputs random elements from a pool llll repeatedly, with a given 
	time delay between each couple of output elements, depending on given probability weights.
	
	@discussion

	@category
	bach, bach abstractions, bach llll

	@keywords
	random, element, drip, pick, extract, pool, step, delay, iterate, metro, sequence, steop

	@seealso
	bach.drip, bach.step, bach.wrandom
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set pool llll or weights llll
// @description When an llll comes through the third inlet, it is set as the pool from which elements
// should be picked (also depending on the <m>maxdepth</m> attribute). <br />
// When an llll comes through the fourth inlet, this is considered to be the llll containing the probability weights,
// according to which elements of the pool llll will be picked. More specifically: elements will be picked
// with a probability directly proportional to their weight. In order for everything to work properly, the weights 
// llll should have the correct shape, according to the <m>maxdepth</m>. If <m>maxdepth</m> is 1 (default), the
// weights must be a plain llll having the same length of the pool llll.

// @method int @digest Turn dripping on/off or set the time interval
// @description Any number other than 0 in the first inlet starts the dripping: at the introduced interval,
// <o>bach.randomdrip</o> outputs the randomly picked elements (from the first outlet) along with their address (from
// the second outlet). If <m>0</m> is received in the first inlet, it stops the dripping (as for the <o>metro</o> object). <br />
// An integer in the second inlet sets or changes the 
// interval (in milliseconds) between two consecutively output elements. <br />
// @copy BACH_DOC_ADDRESS_BASIC

// @method float @digest Set the time interval
// @description A float in the second inlet sets or changes the 
// interval (in milliseconds) between two consecutively output elements.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "unwrap", 0, t_random, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"text","Automatically Unwrap lllls When Picked");
CLASS_ATTR_BASIC(c,"unwrap",0);
// @description Toggles the ability to unwrap automatically the llll when picked (default: 1).
// For instance, if this attribute is active, and the llll is <b>1 2 [3 [4 4]] 5</b>, with 
// <m>maxdepth</m> 1, when the <b>[3 [4 4]]</b> element is picked, the flattened <b>3 [4 4]</b> llll
// is output.


CLASS_ATTR_LONG(c, "maxdepth", 0, t_random, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
// @description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
// the elements can be picked (default: 1, i.e.: elements are picked only at the root level). <br />
// @copy BACH_DOC_MAXDEPTH


CLASS_ATTR_LLLL(c, "default", 0, t_random, default); 
CLASS_ATTR_STYLE_LABEL(c,"default",0,"text","Default llll");
// @description You can use the <m>default</m> attribute to define an llll which will be used by default
// at the instantiation. Such llll will be used as pool llll when a bang is received. If another llll is
// sent through the first inlet, this latter becomes the new pool llll, and the <m>default</m> llll is
// no longer used.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest 1 or 0 to turn dripping on or off
// @in 1 @type int/float @digest The time interval in milliseconds
// @in 2 @type llll @digest The pool llll
// @in 3 @type llll @digest The probability weights llll

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The currently output element
// @out 1 @type llll @digest The currently output element address
// @description @copy BACH_DOC_ADDRESS_BASIC


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name interval @optional 0 @type number @digest Time interval
// @description Initial dripping time interval (in milliseconds). 
// This could be either an integer or a float.
