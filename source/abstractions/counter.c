/*
 *  counter.c
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
	counter.c
	
	@name 
	bach.counter
	
	@realname 
	bach.counter

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Multi-index counter
	
	@description
	The role of <o>bach.counter</o> is to act as a multi-indexed version of <o>counter</o>, 
	storing in its internal memory not only a single increasing
	or decreasing index, but a list of indices, each of which can independently 
	increase or decrease. <br />
	
	@discussion
	In its simplest form, you can define maxima and minima, and then a bang will output all
	indexed list combinations iteratively. For instance, if we have three indices, each
	of which can range from 0 to 3, a bang will iterate through the lists: 
	<b>0 0 0</b>, <b>0 0 1</b>, <b>0 0 2</b>, <b>0 0 3</b>, <b>0 1 0</b>, <b>0 1 1</b>,
	<b>0 1 2</b>, <b>0 1 3</b>, <b>0 2 0</b>, <b>0 2 1</b>, and so on. <br />
	Nevertheless, if the <m>strictly</m> attribute is set to 1, the iteration will only be on the 
	lists where eleemnts are strictly increasing or decreasing, depending on the chosen direction,
	which by default is Up, leading only to: <b>0 1 2</b>, <b>0 1 3</b>, <b>0 2 3</b>, <b>1 2 3</b>.

	@category
	bach, bach abstractions, bach math

	@keywords
	count, index, minimum, maximum, memory, list

	@seealso
	counter, bach.expr, bach.+, bach.reg
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method bang @digest Circular increment or decrement of indices and output
// @description A <m>bang</m> will output out the first outlet the next step in the circular increment or decrement of indices
// (depending on the chosen direction, set in the second inlet). Such circular increment is performed
// right-to-left. For instance, if the direction is "Up" and if we have three indices, of which can 
// range from 0 to 3, a bang will iterate through the lists: <b>0 0 0</b>, <b>0 0 1</b>, <b>0 0 2</b>, 
// <b>0 0 3</b>, <b>0 1 0</b>, <b>0 1 1</b>, <b>0 1 2</b>, <b>0 1 3</b>, <b>0 2 0</b>, <b>0 2 1</b>, and so on. 
// If direction is down, this will correspond to circularly decrementing the indices. <br />
// When a maximum (when direction is up) or minimum (when direction is down) for a given index is reached,
// the corresponding index is reset to its (respectively) minimum or maximum value, and the corresponding 
// "Maxima" or "Minima" list is output through the second or third outlet.
// Such list contains an element for each index, which will be 1 if such index has hit its maximum or minimum (overflow
// or underflow), 0 otherwise. When such minima or maxima are reached, the local carry is also updated and sent through
// the fourth outlet. Such local carry is a list counting the cycles of each one of the indices. <br />
// If the leftmost index has reached its minimum or maximum, also the global carry is updated and sent through the fifth
// outlet. The global carry represents the number of cycles of the whole multi-index, essentially coinciding 
// with the number of cycles of the leftmost index.

// @method int @digest Function depends on inlet
// @description A positive integer in the first inlet will always increment (independently from the the chosen direction via the
// middle inlet) the corresponding index by one unit. For instance, a <b>3</b> will increment the third index
// by one. A negative integer in the first inlet will always decrement (independently from the the chosen direction via the
// middle inlet) the corresponding index by one unit. For instance, a <b>-2</b> will decrement the second index by one.
// When the index or maximum or minimum is reached, the "Maxima" or "Minima" list (depending
// on the direction) will be updated and sent out, as well as the local carry and possibly the global carry.
// Refer to the <m>bang</m> method to know more about maxima and minima lists, as well as about local and global carry. <br />
// An integer in the second inlet sets the direction, as for <o>counter</o>: 0 is Up, 1 is Down.
// When direction is Up, indices range from their minimum to their maximum, when direction is Down they do the opposite. <br />
// An integer in the third inlet sets a global minimum for all indices. <br />
// An integer in the fourth inlet sets a global maximum for all indices <br />.

// @method list @digest Function depends on inlet
// @description A list of integer received in the first inlet combines multiple increments and decrements for given indices.
// Each integer is considered as if input via the <m>int</m> method (refer to that for more information). Finally, the state
// of the multi-index is output through the first inlet. For instance, a list
// like <b>1 4 -2 -2</b> will increase index 1 by one unit, will increase index 4 by one unit, and will decrease twice index 2
// (resulting in a decrement of two units). All the minima, maxima, local and global carry are properly handled (see <m>int</m> and <m>bang</m> methods).<br />
// A list in the third inlet will set a different minimum for each one of the indices. One element per index is thus expected. <br />
// A list in the fourth inlet will set a different maximum for each one of the indices. One element per index is thus expected. <br />

// @method list @digest Combine multiple increments and decrements and output
// @description A llll of depth 2 in the first inlet will compactly combine multiple increments or decrements, and then
// output the updated multi-index.
// It expects a list in the syntax <b>[Index NumberOfTimes] [Index NumberOfTimes]...</b>, where <b>Index</b> can be
// positive or negative, depending if you need to increment it or decrement it (see <m>int</m> method).
// For instance, the llll <b>[1 4] [2 5] [-2 3]</b> will increment the first index by 4 units, inrement the second one by 5 units
// and decrement the second one by three units. Essentially <b>[1 4]</b> thus coincides with <b>1 1 1 1</b> and so on.
// All the minima, maxima, local and global carry are correctly handled: refer to the <m>list</m>, <m>int</m>
// and <m>bang</m> methods to know more about them.

// @method inc @digest Increment all indices and output
// @description An <m>inc</m> symbol will increment all the indices by one unit and then output the updated
// multi-index.
// All the minima, maxima, local and global carry are correctly handled: refer to the <m>list</m>, <m>int</m>
// and <m>bang</m> methods to know more about them.

// @method dec @digest Decrement all indices and output
// @description A <m>dec</m> symbol will decrement all the indices by one unit and then output the updated
// multi-index state.
// All the minima, maxima, local and global carry are correctly handled: refer to the <m>list</m>, <m>int</m>
// and <m>bang</m> methods to know more about them.

// @method set @digest Set all indices values without triggering output
// @description A <m>set</m> symbol followed by a list of integers (one for each index) will set
// the status of each index, without triggering any output.
// @marg 0 @name indices-values @optional 0 @type list

// @method setnext @digest Set all indices values for next cycle without triggering output
// @description A <m>setnext</m> symbol followed by a list of integers (one for each index) will set
// the status that each index will have at next cycle (when any <m>bang</m>, <m>int</m>, <m>list</m> or <m>llll</m>
// message will be received). For instance, if after sending a <m>setnext</m> message, one sends a <m>bang</m>,
// the resulting output multi-index will be the one set via the <m>setnext</m> message.
// @marg 0 @name indices-values @optional 0 @type list

// @method jam @digest Set all indices values and output
// @description A <m>jam</m> symbol followed by a list of integers (one for each index) will set
// the status of each index, and output the update multi-index.
// @marg 0 @name indices-values @optional 0 @type list

// @method current @digest Output current multi-index
// @description Outputs the current multi-index out the first outlet, without changing it.

// @method reset @digest Reset counting
// @description Reset the counting either to all minimum values (if direction is Up) or
// to all maximum values (if direction is Down).
// (except if the <m>strictly</m> attribute is set, refer to it for more information)


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "size", 0, t_counter, size); 
CLASS_ATTR_STYLE_LABEL(c,"size",0,"int","Number Of Indices");
CLASS_ATTR_BASIC(c,"size",0);
// @description The <m>size</m> attribute sets the number of indices of the multi-indexed counter.
// This coincides with the size of the multi-index.


CLASS_ATTR_CHAR(c, "strictly", 0, t_counter, strictly); 
CLASS_ATTR_STYLE_LABEL(c,"strictly",0,"onoff","Force Strictly Increasing Or Decreasing Indices");
CLASS_ATTR_BASIC(c,"strictly",0);
// @description If the <m>strictly</m> attribute is set to 1 (which by default is not the case),
// the element of the multi-index will be forced to be strictly increasing (if direction is Up)
// or strictly decreasing (if direction is Down). This makes sense essentially while circularly cycling on
// the multi-index with bangs. For instance, if we have three indices, each
// of which can range from 0 to 3, when <m>strictly</m> is 0, a bang will iterate through the lists: 
// <b>0 0 0</b>, <b>0 0 1</b>, <b>0 0 2</b>, <b>0 0 3</b>, <b>0 1 0</b>, <b>0 1 1</b>,
// <b>0 1 2</b>, <b>0 1 3</b>, <b>0 2 0</b>, <b>0 2 1</b>, and so on. <br />
// Nevertheless, if the <m>strictly</m> attribute is set to 1, the iteration will only be on the 
// lists where eleemnts are strictly increasing or decreasing, depending on the chosen direction,
// which by default is Up, leading only to: <b>0 1 2</b>, <b>0 1 3</b>, <b>0 2 3</b>, <b>1 2 3</b>.
// If the direction is down, the index will span the reversed combinations: 
// <b>3 2 1</b>, <b>3 2 0</b>, <b>3 1 0</b>, <b>2 1 0</b>.
// Notice also that when you <m>reset</m> a <o>bach.counter</o> in <m>strictly</m> mode, all indices
// are not set to their maximum or minimum, but they are forced to lie on the lowest strictly increasing
// or decreasing configuration. In the previous case, resetting when direction is Up brings to <b>0 1 2</b>,
// even if the minimum for all indices be set to <b>0</b>.


CLASS_ATTR_CHAR(c, "verbose", 0, t_counter, verbose); 
CLASS_ATTR_STYLE_LABEL(c,"verbose",0,"onoff","Verbose Minima And Maxima");
// @description The hitting of a maximum or minimum for a certain index is reported
// through the second and third outlet (depending on the direction), with a list of 0's and 1's, one
// element for each index, where a 1 represent an index having hit its minimum (while going down)
// or its maximum (while going up). Usually such lists are output only when some index has hit
// a minimum or maximum, but you can set the <m>verbose</m> attribute to 1 to have <o>bach.change</o>
// output the minima or maxima lists (always depending on the direction) at each step.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type bang/int/list/llll @digest bang, integer, list or llll to increment or decrement
// @description The first inlet can receive a <m>bang</m>, an <m>int</m>, a <m>list</m> or an <m>llll</m>
// telling how to increment or decrement. Refer to their respective methods for information.
// Also the first inlet can receive all the other methods' messages.

// @in 1 @type int @digest Direction
// @description An integer in the second inlet defines the counting direction.
// As for <o>counter</o>, a 0 means "Up" and 1 means "Down".

// @in 2 @type list @digest Minimum value for each index
// @description An integer or list in the third inlet sets the minima for all indices

// @in 3 @type list @digest Maximum value for each index
// @description An integer or list in the fourth inlet sets the maxima for all indices

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest Current multi-index

// @out 1 @type llll @digest Hit minima (underflow)
// @description The second outlet reports (when counter is going down) the indices having hit their minimum value
// by putting a 1 in their respective position (refer to the <m>bang</m> method for more information).

// @out 2 @type llll @digest Hit maxima (overflow)
// @description The third outlet reports (when counter is going up) the indices having hit their maximum value
// by putting a 1 in their respective position (refer to the <m>bang</m> method for more information).

// @out 3 @type llll @digest Local carry
// @description Number of cycles performed by each index (refer to the <m>bang</m> method for more information).

// @out 4 @type int @digest Global carry
// @description Global number of cycles of the whole multi-index (refer to the <m>bang</m> method for more information).


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name size @optional 0 @type int @digest Number of indices
// @description As for the attribute <m>size</m>, the first argument sets the 
// number of indices of the multi-indexed counter

// @arg 1 @name options @optional 1 @type list @digest Function depends on number of arguments
// @description As for <o>counter</o>, if there is only one option, it sets an initial maximum count
// value for all indices (minimum will be by default 0, and direction by default Up). 
// If there are two options, the first number sets the global minimum value for all indices,
// and the second number sets the global maximum value of all indices (direction will be by default Up). 
// If there are three options, the first number 
// specifies the direction of the count (0 being Up, 1 being Down), the second number 
// specifies the global minimum for all indices, and the third argument specifies the global maximum.
// If no options are specified, the direction will be U, the minimum for all indices will be 0
// and the maximum for all indices will be 65535.
