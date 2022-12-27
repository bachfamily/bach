/*
 *  coprime.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
	coprime.c
	
	@name 
	bach.coprime
	
	@realname 
	bach.coprime

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Test if numbers are coprime
	
	@description
	Tells if the incoming number are coprime, 
	i.e. if their greatest common divisor is 1.
	
	@discussion
	The abstraction is a simple wrapper of <o>bach.gcd</o>.

	@category
	bach, bach abstractions, bach math

	@keywords
	coprime, prime, number, greatest common divisor

	@seealso
	bach.prime, bach.primeser, bach.factorize, bach.coprimeser, bach.gcd, bach.lcm
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Set number, output result
// @description An integer in the first inlet will set the first number for coprimality test, and 
// output the result: 1 if such number and the number received in the second inlet are coprime, 
// 0 otherwise. <br />
// An integer in the second inlet will set the second number for coprimality test.

// @method bang @digest Output coprimality test result
// @description Performs the coprimality test on the most recently received input numbers.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}

// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The first number
// @in 1 @type int @digest The second number



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest 1 if numbers are coprime, 0 otherwise


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name second-number @optional 1 @type int @digest The second number
// @description You can store the second number also directly by setting it as attribute.
