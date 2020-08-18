/*
 *  lcm.c
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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
	lcm.c
	
	@name 
	bach.lcm
	
	@realname 
	bach.lcm

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute least common multiple
	
	@description
	Computes the least common multiple of two numbers or of an llll.
	
	@discussion
	The implemented relies on the gcd Euclidean algorithm.
	
	@category
	bach, bach abstractions, bach math

	@keywords
	least common multiple, compute, calculate, number

	@seealso
	bach.gcd, bach.prime, bach.primeser, bach.coprime, bach.coprimeser	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Set number, output result
// @description A number in the first inlet sets the first number and outputs the least common
// multiple of this number with the one input from the second inlet (or set as argument).
// A number in the second inlet sets the second number for calculation.


// @method llll @digest Set llll of numbers and output result
// @description An llll in the first inlet sets all the numbers whose joint least common multiple
// must be computed, and outputs such least common multiple. The llll is expected to be an llll
// only containing integers.


// @method bang @digest Output least common multiple
// @description Outputs the least common multiple of the most recently received input data.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int/llll @digest The first number or the llll of numbers
// @in 1 @type int @digest The second number



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest 1 The least common multiple of the numbers



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name second-number @optional 1 @type int @digest Second number  
// @description You can set the second number (the one input in the second inlet) also as argument.
