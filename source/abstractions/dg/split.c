/**
	@file
	split.c
	
	@name 
	bach.split
	
	@realname 
	bach.split

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Add parentheses depending on a separator
	
	@description
	Splits the incoming llll into chunks, depending on a 
	given separator, and wraps each chunk inside a level of parentheses.
	The separators can also be specified via a lambda loop.

	@discussion
	The lambda loop will return 1 if a given element is a separator, 0 
	otherwise. In this case, the introduced separator (if any) is ignored. <br /> <br />
	@copy BACH_DOC_LAMBDA

	@category
	bach, bach abstractions, bach llll

	@keywords
	split, separate, chunk, separator, wrap, lambda loop, keep, change, repetition
	
	@seealso
	bach.slice
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Split llll
// @description An llll in the first inlet will be split into chunks depending on the
// given separator element; each chunk is then wrapped in a level of parenthesis, and
// the resulting list is output. The separator can be kept or discarded depending
// on the <m>keep</m> attribute; the separator itself is set via the <m>separator</m> attribute. <br />
// In the second inlet, an llll is converted into an <m>int</m>

// @method int @digest Lambda inlet
// @description Second inlet is a lambda inlet, and is expected to receive 1 if the
// currently output element is a separator, 0 otherwise. <br /> 
// @copy BACH_DOC_LAMBDA_INLET_MATCH

// @method bang @digest Output result
// @description Outputs the result of the process performed on the most received input llll.




// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_LLLL(c, "separator", 0, t_split, separator); 
CLASS_ATTR_STYLE_LABEL(c,"separator",0,"text","Separator");
CLASS_ATTR_BASIC(c,"mode",0);
// @description Element used as separator for splitting the llll into wrapped chunks.

CLASS_ATTR_CHAR(c, "keep", 0, t_split, keep); 
CLASS_ATTR_STYLE_LABEL(c,"keep",0,"enumindex","Keep Separator");
CLASS_ATTR_ENUMINDEX(c,"keep", 0, "Never Before Parentheses After Parentheses"); 
CLASS_ATTR_BASIC(c,"keep",0);
// @description Toggles the possibility to keep the separator element in the
// output llll. By default it is set to 0 (<b>Never</b>: separator is discarded),
// but this can be set to 1 (<b>Before Parentheses</b>: separator is kept before
// the newly placed parentheses) or 2 (<b>After Parentheses</b>: separator is kept
// after the newly placed parentheses).

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The llll
// @in 1 @type int/llll @digest Lambda inlet
// @description The lambda inlet expects a 1 if the currently output element is a separator,
// a 0 otherwise. <br />
// @copy BACH_DOC_LAMBDA_INLET_MATCH




// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The split llll
// @out 1 @type llll @digest Lambda outlet
// @description Elements are output through the lambda outlet in order to let the user decide
// whether they are separators (in which case 1 must returned in the lambda inlet, as for
// a found match) or not (0 should be returned in the lambda inlet). <br />
// @copy BACH_DOC_LAMBDA_OUTLET_MATCH



// ---------------
// ARGUMENTS
// ---------------

// @arg 0 @name separator @optional 1 @type llll @digest Separator
// @description The optional argument sets the element used as separator 
// for splitting the llll into wrapped chunks. It is expected to be a single element
// or an llll of length 1.
