/**
	@file
	replace.c
	
	@name 
	bach.replace
	
	@realname 
	bach.replace

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Quickly find and replace elements
	
	@description
	Search and replace all occurrences of an element, or all elements satisfying a condition.
	
	@discussion
	<o>bach.replace</o> finds all the occurrences of a certain element.
	As for <o>bach.find</o>, such occurrences can be specified via a lambda inlet and outlet. <br />
	@copy BACH_DOC_LAMBDA
	
	@category
	bach, bach abstractions, bach llll

	@keywords
	replace, find, search, occurrence, condition, lambda loop, element

	@seealso
	bach.find, bach.subs, bach.nsubs, Iterations
	
	@owner
	Andrea Agostini
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An llll in the first inlet is the llll whose elements must be searched for substitutions.
// Such llll will trigger the substitution and the result llll will be output through the first outlet. <br />
// An llll in the second inlet contains the element which has to be searched (in order to replace it). Such llll
// is thus expected to have length 1, although it can represent a complex wrapped llll to be found, such as
// <b>[1 2 3]</b>. <br />
// An llll in the third inlet contains the element(s) which will be replaced for each occurrence. Such llll can be of any
// type. <br /> 
// For instance, if the element to be substituted is <b>1</b> in the llll <b>1 a b c [1] d [e 1 f]</b>, and 
// the replacing elements are <b>foo [fee faa]</b>, the result will be 
// <b>foo [fee faa] a b c [foo [fee faa]] d [e foo [fee faa] f]</b>. <br />
// An llll in the fourth inlet is converted into an <m>int</m>.

// @method int @digest Lambda inlet
// @description Fourth inlet is a lambda inlet. 
// The criterium by which a given element or sequence of elements is considered a match
// can be customized through an optional lambda loop.
// If the lambda loop is present, the <m>op</m> attribute and the llll received in the second inlet are ignored,
// and elements or sequences of elements (see the <m>size</m> attribute for more details) are output from the lambda outlet.
// The lambda loop should return 1 to the fourth inlet if the element or sequence is a match, 0 if it is not.

// @method bang @digest Replace elements in llll
// @description Performs the replacement with the most recently received input data.
// @copy BACH_DOC_BANG_LAMBDA_CAVEAT


// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LONG(c, "maxdepth", 0, t_replace, maxdepth); 
CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
CLASS_ATTR_BASIC(c,"maxdepth",0);
// @description @copy BACH_DOC_MAXDEPTH

CLASS_ATTR_LONG(c, "mindepth", 0, t_replace, mindepth); 
CLASS_ATTR_STYLE_LABEL(c,"mindepth",0,"text","Minimum Depth");
CLASS_ATTR_BASIC(c,"mindepth",0);
// @description @copy BACH_DOC_MINDEPTH

CLASS_ATTR_CHAR(c, "depthreject", 0, t_replace, depthreject); 
CLASS_ATTR_STYLE_LABEL(c,"depthreject",0,"onoff","Depth Reject");
// @description @copy BACH_DOC_DEPTHREJECT

CLASS_ATTR_CHAR(c, "idxreject", 0, t_replace, idxreject); 
CLASS_ATTR_STYLE_LABEL(c,"idxreject",0,"onoff","Index Reject");
// @description @copy BACH_DOC_FIND_IDXREJECT

CLASS_ATTR_LONG(c, "maxidx", 0, t_replace, maxidx); 
CLASS_ATTR_STYLE_LABEL(c,"maxidx",0,"text","Maximum Index");
// @description @copy BACH_DOC_FIND_MAXIDX

CLASS_ATTR_LONG(c, "minidx", 0, t_replace, minidx); 
CLASS_ATTR_STYLE_LABEL(c,"minidx",0,"text","Minimum Index");
// @description @copy BACH_DOC_FIND_MINIDX

CLASS_ATTR_LONG(c, "size", 0, t_replace, size); 
CLASS_ATTR_STYLE_LABEL(c,"size",0,"onoff","Size");
// @description @copy BACH_DOC_FIND_SIZE

CLASS_ATTR_LONG(c, "op", 0, t_replace, op); 
CLASS_ATTR_STYLE_LABEL(c,"op",0,"onoff","Comparison Operator");
CLASS_ATTR_BASIC(c,"op",0);
// @description @copy BACH_DOC_FIND_OP

CLASS_ATTR_LONG(c, "maxcount", 0, t_replace, maxcount); 
CLASS_ATTR_STYLE_LABEL(c,"maxcount",0,"text","Maximum Count");
// @description @copy BACH_DOC_FIND_MAXCOUNT

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll whose elements must be searched for substitutions
// @in 1 @type llll @digest The comparison element to be matched
// @in 2 @type llll @digest The elements for replacement
// @in 3 @type int/llll @digest Lambda inlet



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The modified llll
// @out 1 @type llll @digest Lambda outlet


// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name old_element @optional 1 @type llll @digest Element to be replaced 
// @description The first optional argument is the element to be found and replaced (see <m>llll</m> message,
// second inlet, to know more).

// @arg 1 @name new_elements @optional 1 @type llll @digest Replacing llll 
// @description The second optional argument is the llll to be replaced at each occurrence (see <m>llll</m> message,
// third inlet, to know more).
