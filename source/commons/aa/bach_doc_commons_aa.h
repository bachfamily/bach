/**
	@file	bach_doc_commons.h
	@brief	Common documentation about some basic concepts and syntaxes of bach.
	
	by Andrea Agostini and Daniele Ghisi
*/

#define BACH_DOC_OUT
	//	The <m>out</m> attribute is a sequence of characters identifying the outlet types (one character for each llll outlet). Characters can be one of the following: <br />
	//	<m>n</m> (default): 'native' output: faster and more precise between bach objects, but unreadable by standard Max objects (an "bach.llll" message appears instead). <br />
	//	<m>t</m>: 'text' output: slower and limited in size, but readable by standard Max objects. A plain llll in text format is a generic Max message. To keep the representation invertible (i.e., to allow a bach object receiving a text-format llll to interpret it exactly as if it was native format, except for the size limitation), some specific kinds of symbols are preceded by a backtick: namely, symbols containing parens, or containing textual representations of numbers or pitches, or beginning with a backtick, plus the symbols "null" and "nil" (distinct from the reserved words "null" and "nil" representing the empty list and the empty sublist) are preceded by a backtick. Moreover, the symbols "int", "float" or "list" are preceded by a backtick only if they are the first element of an llll, to distinguish them from the corresponding reserved messages of Max. <br />
	//	<m>m</m>: 'max' output: mostly equivalent to the <t> specifier, but no symbol is backticket except "int", "float" and "list" at the beginning of an llll. It is important to notice that, differently from text-format lllls proper, Max-format lllls might not be invertible even if they do not reach the size limit for Max message. This means that a bach object receiving a Max-format llll output from another bach object might interpret it differently from the original, or in some cases might even reject it. <br />
    //	<m>x</m>: disabled output (nothing is output) <br />
	//	<m>p</m>: 'portal' output: only used by bach.portal to intercept the @out attribute specified while creating the abstraction (see bach.portal). <br />
	//	The native output is recommended, unless communication with standard Max messages is needed. Disabling unused outputs can be useful if extreme optimization of the patch is needed.
	//  <br /> <br />
					

#define BACH_DOC_MINDEPTH
	//  <m>mindepth</m> sets the minimum depth level at which the operation must be performed. 
	//  If negative, the depth level is counted from the innermost level of each branch of the tree.
	//	A value of 0 is not accepted.
	//  Defaults to 1, i.e. there is no limitation.
	//	<br /> <br />

#define BACH_DOC_MAXDEPTH
	//  <m>maxdepth</m> sets the maximum depth level at which the operation must be performed.
	//  If negative, the depth level is counted from the innermost level of each branch of the tree.
	//	A value of 0 is not accepted.
	//  Defaults to -1, i.e. there is no limitation (stop at the innermost level).
	//	<br /> <br />

#define BACH_DOC_ITERATIONMODE
	//  <m>iterationmode</m> sets the behavior of the object when lllls of different length are iterated against each other. 
	//  If set to 0, operation will stop at the end of the shortest llll.
	//	If set to 1, operation will stop at the end of the longest llll.
	//	If set to 2, operation will stop at the end of the longest llll, and missing element from the shortest ones will be replaced by empty sublists.
	//  <br /> <br />

#define BACH_DOC_STATIC_ATTR
	//	This is a static attribute which can only be set by typing it in the object box.
	//	<br /> <br />

#define BACH_DOC_INWRAP
	//	Wrap every incoming llll in the corresponding number of parentheses.
	//	This is equivalent to connecting a <o>bach.wrap</o> object to every llll inlet.
	//	<br /> <br />

#define BACH_DOC_OUTWRAP
	//	Wrap every output llll in the correspongind number of parentheses.
	//	This is equivalent to connecting a <o>bach.wrap</o> object to every llll outlet.
	//	<br /> <br />
#define BACH_DOC_UNWRAP
	//	Flatten every incoming llll by the specified number of levels.
	//	This is equivalent to connecting a <o>bach.flat</o> object to every llll inlet. 
	//	<br /> <br />

#define BACH_DOC_LLLL_COMPARISON
	// The comparison is performed as follows:
	// the two lllls are traversed in parallel, and at each step an element of the first one is compared to an element of the second one. 
	// As soon as the two considered elements are different, the value of their comparison is the value of the comparison of the lllls.
	// If the end of either list is reached, the longer is the greater.<br />
	// Elements are compared as follows: numbers are compared by value; 
	// symbols are compared alphabetically (or, to be more precise, in lexicographical order according to the ASCII code);
	// lllls are compared recursively as explained above; numbers are less than symbols; symbols are less than lllls.
	// <br /> <br />

#define BACH_DOC_SCALARMODE
	// When set to 1 an llll with a single element is iterated against all the elements of the other lllls.
	// <br /> <br />

#define BACH_DOC_BANG_LAMBDA_CAVEAT
	// <br /> N.B.: The object is not aware of changes you make in the lambda loop. 
	// If you change the lambda loop, you might want to re-input the most recent llll rather than just sending a <m>bang</m>.

#define BACH_DOC_DEPTHREJECT
	// When set to 1, the search depth range set through the <m>mindepth</m> and <m>maxdepth</m> attributes is inverted,
	// meaning that the specified depth range is excluded from the search, rather than included.

#define BACH_DOC_ADDRESS_BASIC
	// An address is an llll providing a unique representation of the position of an element in another llll.
	// It is a concept shared by many bach object.
	// The address of each element of an llll's root level is simply its position counting from 1.
	// The address of an element in a sublist is a list composed by the position of the element in the sublist,
	// preceded by the position of the sublist in the parent llll, 
	// and so on up to the root level, as a sort of "path" to the element.<br />
	// For instance, given the llll <b>a b c (d e (f g) h i) j k</b> the position of <b>c</b> is <b>3</b>;
	// the position of <b>(d e (f g) h i)</b> is <b>4</b>;
	// the position if <b>e</b> is <b>4 2</b> since to reach it it takes to go to the 4th element of the root level, which is a sublist,
	// and to the 2nd element of that sublist. 
	// By reading the address from right to left, it can be seen that this is equivalent to saying 
	// that the pointed element is the 2nd of the 4th.
	// Likewise, in the above llll <b>f</b> has the address <b>4 3 1</b> since it is the 1st of the 3rd of the 4th.<br />

#define BACH_DOC_ADDRESS_NEGATIVE
	// In addition, addresses sent to bach objects can contain negative positions, 
	// that is positions counted from the end of the llll instead than the right.
	// Negative and positive positions can be safely mixed within a single address.
	// Thus, the address of the element <b>g</b> can be expressed as <b>4 3 2</b> as well as <b>4 3 -1</b> or <b>-3 -3 -1</b>.<br />

#define BACH_DOC_ADDRESS_MULTIPLE
	// <b>_NAME</b> also accepts a special syntax to indicate multiple elements of one level of the llll:
	// a sublist in the address will be interpreted as a sequence of elements in the corresponding level.
	// In this way, the address <b>4 (2 4 5)</b> means "the 2nd, 4th and 5th of the 4th", that is <b>e h i</b>.
	// Negative positions are accepted here as well.
	// Any number after the multiple-element sublist in the address llll is ignored.<br />

#define BACH_DOC_ADDRESS_RANGE
	// The multiple-element sublist can contain sublists in its turn. These are called "range sublists".
	// A range sublist is composed by two positions, and indicates all the elements comprised between these two positions.
	// Either or both positions of a range sublist can be negative.
	// So, the address <b> 4 ((2 -1) 1)</b> means "From the 2nd to the last (i.e. the 1st from the right) and the 1st of the 4th",
	// that is <b>e (f g) h i d</b>.
	// As a tip, notice that to retrieve all the contents of a sublist (as opposed to the sublist itself)
	// the range (1 -1) can be specified.

#define BACH_DOC_FIND_MINDEPTH
	// @copy BACH_DOC_MINDEPTH
	// <br />N.B.: when the <m>depthreject</m> attribute is set to 1, the specified depth range is excluded from the search, rather than included.

#define BACH_DOC_FIND_MAXDEPTH
	// @copy BACH_DOC_MAXDEPTH
	// <br />N.B.: when the <m>depthreject</m> attribute is set to 1, the specified depth range is excluded from the search, rather than included.

#define BACH_DOC_FIND_MINIDX
	// <m>minidx</m> sets the position at which the search should begin, for the root llll as well as any sublist.
	// If negative, the position is counted backwards from the end.
	// Defaults to 0, i.e. there is no limitation (equivalent to 1: begin at the first element).<br />
	// N.B.: when the <m>idxreject</m> attribute is set to 1, 
	// the specified index range is excluded from the search, rather than included.

#define BACH_DOC_FIND_MAXIDX
	// <m>maxidx</m> sets the position at which the search should end, for the root llll as well as any sublist.
	// If negative, the position is counted backwards from the end.
	// Defaults to 0, i.e. there is no limitation (equivalent to -1: end at the last element).<br />
	// N.B.: when the <m>idxreject</m> attribute is set to 1, 
	// the specified index range is excluded from the search, rather than included.

#define BACH_DOC_FIND_IDXREJECT
	// When set to 1, the search range set through the <m>minidx</m> and <m>maxidx</m> attributes is inverted,
	// meaning that the specified range is excluded from the search, rather than included.

#define BACH_DOC_FIND_MAXCOUNT
	// The number of matches to find. As soon as the specified number is reached, the search stops.
	// The default is 0, meaning that all the matches are found.

#define BACH_DOC_FIND_RECURSIVE
	// When set to 1, whenever a matching sublist is found its elements are investigated as well. When set to 0, they are not.

#define BACH_DOC_FIND_OP
	// The comparison operator by which chunks of the llll in the first inlet are compared to the element or sequence in the second inlet.
	// Valid operators are <m>==</m>, <m>!=</m>, <m>===</m>, <m>!==</m> 
	// (the two last being as <o>bach.==</o> and <o>bach.!=</o> with <m>matchtype 1</m>),
	// <m>&lt;</m>, <m>&lt;=</m>, <m>&gt;</m>, <m>&gt;=</m>.
	// The <m>op</m> attribute is ignored if a lambda loop is present.

#define BACH_DOC_FIND_SIZE
	// The size of each llll chunk to be output from the lambda outlet.
	// The <m>size</m> attribute is ignored if a lambda loop is not present.

#define BACH_DOC_WRITETXT_TEXT_FORMAT_AND_ARGUMENTS
// Text format is easily editable in any text editor,
// but representation of floating-point numbers is approximate.
// No limit in size is given for saving a file in text format (differently from what happens while outputting lllls as text in Max).
// If no file name is provided, a dialog box will open.
// Furthermore, some message attributes are available, for fine-tuning of the text formatting.
// Available attributes are: <br />
// - <b>maxdecimals</b> (default: 10): the precision for floating-point numbers. <br />
// - <b>indent</b> (default: <b>tab</b>): if set to <m>tab</m>, every sublist that is encountered (up to <b>maxdepth</b>, see below)
// will be placed on a new line, indented by a number of tabs equal to the depth level of the sublist itself.
// If set to an integer, the indentation for each depth level will be the corresponding number of spaces.<br />
// - <b>maxdepth</b> (default: -1, i.e. no limitation): the maximum depth at which sublists are placed in new lines.
// If negative, the depth level is counted from the innermost level of each branch of the tree.
// - <b>wrap</b> (default: 0, i.e. no wrapping): the maximum number of characters to be placed on each line.<br />
// - <b>filename</b> (default: not set): the name of the file to be written.
// If set, this specification overrides the file name set as the first message argument.