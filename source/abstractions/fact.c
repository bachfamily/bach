/*
 *  fact.c
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
	fact.c
	
	@name 
	bach.fact
	
	@realname 
	bach.fact

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute factorial
	
	@description
	Computes the factorial of a given number N, that is
	N! = N*(N-1)*(N-2)...*2*1.
	
	@discussion
	The algorithm just applies the definition of factorial.
	
	@category
	bach, bach abstractions, bach math

	@keywords
	factorial, product, number, compute, calculate

	@seealso
	bach.bin, bach.prod	
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method int @digest Compute factorial and output result
// @description Any integer will trigger its factorial computation and output the result.
// If the result is not representable (because of overflow) a bang is sent out the second outlet,
// otherwise the result is sent out the left outlet

// @method bang @digest Compute factorial
// @description Computes the factorial most recently received input number.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

// (none)

}


// ---------------
// INLETS
// ---------------

// @in 0 @type int @digest The number N



// ---------------
// OUTLETS
// ---------------

// @out 0 @type int @digest The factorial of the number N
// @out 1 @type bang @digest bang if overflow



// ---------------
// ARGUMENTS
// ---------------

// (none)
