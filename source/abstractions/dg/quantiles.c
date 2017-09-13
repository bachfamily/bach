/**
	@file
	quantiles.c
	
	@name 
	bach.quantiles
	
	@realname 
	bach.quantiles

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find quantiles or filter according to them
		
	@description
	Finds quantiles of an llll or filters the llll by keeping elements only inside some quantile regions.
	
	@discussion

	@category
	bach, bach abstractions, bach math

	@keywords
	mean, statistics, quantile, upper, lower, range, region, filter, sieve, keep

	@seealso
	bach.median, bach.filter
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Compute quantiles or set quantile points
// @description An <m>llll</m> in the first inlet is the llll whose quantiles should be 
// computed, and will trigger the calculation and output. <br />
// An <m>llll</m> in the second inlet is the llll whose elements are the quantile points
// (i.e. the list of <m>q</m>'s determining the <m>q</m> quantiles). For instance, if such
// list is <b>1/4 1/2 3/4</b>, the first 4-quantile, the median and the third 4-quantile are
// output once the left lllls comes in. Quantiles can be rational or floating point numbers. Alternatively, numbers
// can be substituted by a range-syntax lllls in the form <b>(<m>start_quantile</m> <m>end_quantile</m>)</b>;
// in this case what will be output are not the quantiles, rather the original llll filtered so that 
// only numbers lying within the two quantiles will be kept (numbers equal to either one of the two quantile extremes
// are also kept).

// @method bang @digest Compute quantiles
// @description Computes the quantiles on most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);


CLASS_ATTR_CHAR(c, "sort", 0, t_quantiles, sort); 
CLASS_ATTR_STYLE_LABEL(c,"sort",0,"onoff","Sort output");
CLASS_ATTR_BASIC(c,"sort",0);
//	@description If quantile points are defined in range syntax (see <m>llll</m>), the
// <m>sort</m> attribute toggles the ability to sort the output llll. By default, this attribute
// is 0, so that the output llll will not be sorted, only filtered.

CLASS_ATTR_CHAR(c, "absolute", 0, t_quantiles, absolute); 
CLASS_ATTR_STYLE_LABEL(c,"absolute",0,"onoff","Absolute Mode");
CLASS_ATTR_BASIC(c,"absolute",0);
//	@description Toggles the ability to interpret quantiles not as relative proportion, rather
// as absolute integer position in the list. For instance, 3 will mean "third element", 
// and -4 "fourth element counted backwards", as for <o>bach.nth</o>. If <m>absolute</m> mode is active,
// asking for quantile points such as <b>(-4 -1)</b> will return essentially the four biggest numbers in 
// the llll - except if the fourth biggest number has more than one occurrence in the list, in which case
// it will be returned as many times as the number of occurrences. In general, then, asking for a 
// <b>(<m>M</m> <m>N</m>)</b> quantile region will not necessarily yield <m>N</m> - <m>M</m> + 1 values.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll containing numbers
// @in 1 @type llll @digest The quantile points



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The quantiles or the filtered llll



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name quantile_points @optional 1 @type llll @digest Quantile points 
// @description The initial value for the quantile points (as the llll coming in the second inlet).
// See <m>llll</m> to know more.