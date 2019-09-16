/*
 *  wrandom.c
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
	wrandom.c
	
	@name 
	bach.wrandom
	
	@realname 
	bach.wrandom

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Pick weighted random elements from an llll
	
	@description
	Outputs one or more of random elements, extracted from a 
	given pool llll, depending on given probability weights.
	
	@discussion
	When the weights are left <b>null</b> or are all left equal (uniform picking), this is
	equivalent to using <o>bach.random</o>.
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	random, element, pick, extract, pool, weight, probability
	
	@seealso
	random, bach.nth, bach.pick, bach.urn, bach.lookup, bach.mrandom, bach.random, bach.urn, bach.wurn
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set pool llll or weights llll, output randomly picked elements
// @description When an llll comes through the first inlet, <o>bach.random</o> sets it as the pool from which elements
// should be picked (also depending on the <m>maxdepth</m> attribute), 
// and then output the random elements (first outlet), along with their addresses
// (second outlet). <br />
// When an llll comes through the second inlet, this is considered to be the llll containing the probability weights,
// according to which elements of the pool llll will be picked. More specifically: elements will be picked
// with a probability directly proportional to their weight. In order for everything to work properly, the weights 
// llll should have the correct shape, according to the <m>maxdepth</m>. If <m>maxdepth</m> is 1 (default), the
// weights must be a plain llll having the same length of the pool llll.

// @method int @digest Set the number of elements to be picked at once
// @description An integer in the third inlet sets the number of elements that will be picked each time
// an llll or a bang is received (default: 1). Elements can be repeated while picking: if you don't
// want this behavior have a look at <o>bach.wurn</o> instead.

// @method bang @digest Output randomly picked elements
// @description The given number of elements are randomly picked and output (from the first outlet)
// along with their addresses (from the second outlet). <br />
// @copy BACH_DOC_ADDRESS_BASIC


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
CLASS_ATTR_STYLE_LABEL(c,"default",0,"text","Default Pool llll");
// @description You can use the <m>default</m> attribute to define an llll which will be used by default
// at the instantiation. Such llll will be used as pool llll when a bang is received. If another llll is
// sent through the first inlet, this latter becomes the new pool llll, and the <m>default</m> llll is
// no longer used.

CLASS_ATTR_LLLL(c, "weights", 0, t_random, weights); 
CLASS_ATTR_STYLE_LABEL(c,"weights",0,"text","Weights llll");
// @description You can use the <m>weight</m> attribute to set the weights already at the instantiation.
// Such weights will be used by default at the beginning. Then you can replace weights equivalently by using the
// <m>weights</m> attribute or the second inlet (see <m>llll</m> message).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The pool llll or bang to pick
// @in 1 @type llll @digest The probability weights llll
// @in 2 @type int @digest The number of elements that must be picked at once


// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The picked elements
// @out 1 @type llll @digest The picked elements' addresses
// @description @copy BACH_DOC_ADDRESS_BASIC



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name number_of_elements @optional 1 @type int @digest Number of elements to be picked at once 
// @description The optional argument is the number of elements that must be picked each time
// an llll or a bang is received (default: 1).
