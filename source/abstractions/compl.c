/*
 *  compl.c
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
	compl.c
	
	@name 
	bach.compl
	
	@realname 
	bach.compl

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find complement of a pitch-class set
	
	@description
	Given a pitch-class set, <o>bach.compl</o> 
	finds its complement, i.e. the set of all the numbers not appearing in the given set. 
	
	@discussion
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	bach.compl accepts in input also a complex tree of pitch-class sets, and will output the complementary
	accordingly (preserving the tree shape).
	For instance, with modulo = 12, the complement of the set [4 7 9] is [0 1 2 3 5 6 8 10 11].
	
	@category
	bach, bach abstractions, bach set theory

	@keywords
	complement, pitch-class, modulo, negative
	
	@seealso
	bach.circle, bach.mod+, bach.mod-, bach.modtimes, bach.pcsetinfo
	
	@owner
	Daniele Ghisi
*/

// METHODS

// @method llll @digest Compute the complement of incoming pitch-class set
// @description In the first inlet, a pitch-class set, in the form of plain list of numbers (or a tree of such pitch-class sets)
// will trigger the output of its complement 

// @method bang @digest Find and output the complement
// @description Finds the complement of the most recently received input pitch-class set.

// @method int @digest Set modulo 
// @description An integer in the right inlet will set the modulo. <br />
// @copy BACH_DOC_SETTHEORY_MODULO


// ATTRIBUTES

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

}


// INLETS

// @in 0 @type llll @digest Pitch-class set (as a plain list) or tree of pitch-clas sets.
// @in 1 @type int @digest Modulo


// OUTLETS

// @out 0 @type llll @digest Complement of pitch-class set
// @description	If a tree of pitch-class sets was given, the output is a tree of complement pitch-class sets maintaining the same shape.


// ARGUMENTS

// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
// @description @copy BACH_DOC_SETTHEORY_MODULO
