/*
 *  pcsetinfo.c
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
	pcsetinfo.c
	
	@name 
	bach.pcsetinfo
	
	@realname 
	bach.pcsetinfo

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Report basic information about a pitch-class set
	
	@description
	Reports some standard information about a pitch-class set, such as its
	cardinality, whether it is in prime form (or not), whether it is symmetrical (or not), its interval
	structure period, and its periodicity (number of different transpositions).  <br /> <br />
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	
	@discussion
	The fact of being in prime form is reported both for group of transpositions and for the group of 
	transpositions/inversion. <br /> <br />
	@copy BACH_DOC_SETTHEORY_GROUPS
	
	@category
	bach, bach abstractions, bach set theory

	@keywords
	pitch-class, set, information, symmetrical, interval structure, period, transposition,
	cardinality, prime form, normal form, modulo, inversion, group, action

	@seealso
	bach.primeform, bach.circle, bach.mod+, bach.mod-, bach.modtimes, bach.compl, bach.period, bach.istruct
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Report information about incoming pitch-class set
// @description In the first inlet, a pitch-class set will report the information about it

// @method bang @digest Report the information
// @description Reports the information about the most recently received input data

// @method int @digest Set modulo 
// @description An integer in the right inlet will set the modulo. <br />
// @copy BACH_DOC_SETTHEORY_MODULO



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "mode", 0, t_primeform, mode); 
CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Lexicographic Compactness First"); 
CLASS_ATTR_BASIC(c,"mode",0);
//	@description Criterion according to which the prime forms are chosen. <br />
//	@copy BACH_DOC_SETTHEORY_PRIMEFORMORDERINGCRITERION

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The pitch-class set
// @in 1 @type int @digest The modulo



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest Cardinality
// @out 1 @type int @digest Is in prime form (with respect to transpositions?)
//      @description Output 1 if the pitch-class set is in prime form with respect to the group of transpositions, 0 otherwise
// @out 2 @type int @digest Is in prime form (with respect to transpositions/inversion?)
//      @description Output 1 if the pitch-class set is in prime form with respect to the group of transpositions and inversion, 0 otherwise
// @out 3 @type int @digest Is symmetrical?
//      @description Output 1 if the pitch-class set has a symmetry axis (when represented as points on a circle), 0 otherwise
// @out 4 @type list @digest Interval structure period
//		@description The distances between the elements of the set. If such distances are periodic, a single period is reported. 
//					 For instance, for set <b>0 1 6 7</b>, this will not report
//					 the full interval structure <b>1 5 1 5</b>, rather just one period <b>1 5</b> (also see <o>bach.istruct</o> 
//					 and <o>bach.period</o>)
// @out 5 @type int @digest Periodicity
//		@description Report the periodicity of the pitch-class set, coinciding with the number of different transpositions it can have.
//					 (also see <o>bach.period</o>)


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
// @description @copy BACH_DOC_SETTHEORY_MODULO
