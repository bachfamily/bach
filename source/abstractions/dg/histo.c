/**
	@file
	histo.c
	
	@name 
	bach.histo
	
	@realname 
	bach.histo

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Build histograms
	
	@description
	Builds an histogram starting from a list of data, returning elements along with their occurrences.

	@discussion

	@category
	bach, bach abstractions, bach llll

	@keywords
	histogram, integer, number, build, count, appearance, statistics, word, dictionary, unique, occurrence, show up
	
	@seealso
	histo, bach.iter, bach.collect
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Set llll for analysis, output result
// @description An llll in the first inlet sets the llll from which an histogram should be built.
// In default mode, the histogram will output elements from second outlet and their occurrences from leftmost outlet.
// In integer mode (see arguments), the histogram will contain in its <m>i</m>-th entry the number of occurrences of number <m>i</m> 
// in the original data (also reporting 0-occurrence elements); the llll with the <m>i</m>'s is also output 
// through the second outlet.


// @method atom @digest Set minimum or maximum
// @description 
// This method only applies for integers mode only (see arguments). 
// The histogram will contain in its <m>i</m>-th entry the number of appearences of number <m>i</m> 
// in the original data. Yet the user can define a minimum and a maximum value of numbers <m>i</m> to
// be searched for: in this case the histogram will have an offset. 
// For instance, if minimum is set to 4, the first entry of the histogram will contain the number
// of occurrences of 4, the second one the number of occurrences of 5, and in general the <m>i</m>-the entry 
// will contain the number of occurrences of <m>i</m>+3.<br />
// Also, the number of entries of the histogram will correspond to the difference between the maximum and 
// the minimum, plus one.
// One can of course leave minimum and maximum as "automatic" so that the first element of the 
// histogram corresponds to the minimum value of the input llll, and the last element of the histogram
// corresponds to the maximum value of the input llll. <br />
// An integer in the first inlet sets a fixed minimum, an <m>auto</m> symbol links the minimum to the 
// minimum value appearing in the original data llll. <br />
// An integer in the second inlet sets a fixed maximum, an <m>auto</m> symbol links the maximum to the 
// maximum value appearing in the original data llll. <br />


// @method bang @digest Output histogram
// @description Outputs the histogram of the most recently received reference number.


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_wurn, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
// @description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
// the elements should be accounted for (default: -1, i.e.: elements are accounted for at any levels). <br />
// @copy BACH_DOC_MAXDEPTH

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll to be analyzed
// @in 1 @type int/symbol @digest The minimum integer value to be accounted for (or "auto")
// @in 2 @type int/symbol @digest The maximum integer value to be accounted for (or "auto")

// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The occurrences
// @out 1 @type llll @digest The elements



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name minimum @optional 1 @type atom @digest The minimum integer value to be accounted for (or "auto")
// @description You can store the minimum value as first argument (see the <m>atom</m> method for more information).
// If you store this value, <o>bach.histo</o> will work in integer mode (e.g. outputting occurrences of all 
// integers between the minimum and the maximum, even if they don't show up in the list).

// @arg 1 @name maximum @optional 1 @type atom @digest The maximum integer value to be accounted for (or "auto")
// @description You can store the maximum value as first argument (see the <m>atom</m> method for more information).
