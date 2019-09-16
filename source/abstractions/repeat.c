/*
 *  repeat.c
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
	repeat.c
	
	@name 
	bach.repeat
	
	@realname 
	bach.repeat

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Repeat lllls
	
	@description
	Repeats an incoming llll a certain number of times.
	
	@discussion
	The repetitions could be individually wrapped or globally wrapped, thanks to the
	<m>inwrap</m> and <m>outwrap</m> attributes
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	repeat, loop, wrap

	@seealso
	bach.collect, bach.group, uzi, bach.period, bach.pad	
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Repeat llll
// @description An llll in the first inlet will be repeated a certain number of times
// (defined by the number in the right inlet or by the argument), and then output
// through the outlet. For instance, repeating <b>foo [fee faa]</b> three times will yield
// <b>foo [fee faa] foo [fee faa] foo [fee faa]</b>. Via the <m>inwrap</m> and <m>outwrap</m> 
// attributes you can add level of parenthesis for each individual repetition or for the whole 
// output llll, which allows you to obtain more complicate output lllls, such as 
// <b>[[[foo [fee faa]]] [[foo [fee faa]]] [[foo [fee faa]]]]</b>.

// @method int @digest Set number of repetitions
// @description A non-negative integer in the second inlet sets the number of times the
// incoming llll must be repeated.

// @method bang @digest Repeat llll
// @description Repeats the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "inwrap", 0, t_repeat, inwrap);
CLASS_ATTR_STYLE_LABEL(c,"inwrap",0,"text","Wrap Input");
CLASS_ATTR_BASIC(c,"unwrap",0);
// @description @copy BACH_DOC_INWRAP

CLASS_ATTR_LONG(c, "outwrap", 0, t_repeat, unwrap); 
CLASS_ATTR_STYLE_LABEL(c,"outwrap",0,"text","Wrap Output");
CLASS_ATTR_BASIC(c,"unwrap",0);
// @description @copy BACH_DOC_OUTWRAP

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be repeated
// @in 1 @type int @digest Number of repetitions



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The repeated llll


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name number_of_repetitions @optional 1 @type int @digest Number of repetitions 
// @description The optional argument sets the initial number of repetitions (the default is 1). 
