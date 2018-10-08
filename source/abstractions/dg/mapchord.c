/**
	@file
	mapchord.c
	
	@name 
	bach.mapchord
	
	@realname 
	bach.mapchord

	@type
	abstraction
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Individually modify chords 
	
	@description
	Takes the gathered syntax of a <o>bach.roll</o> or <o>bach.score</o> and operates a given
	transformation on each chord, defined via a lambda loop.
	
	@discussion
	The iteration is performed until a chord element is found (both for <o>bach.roll</o> and <o>bach.score</o>).
	This especially also works if rhythmic tree levels are present. 
	The chord llll is output from the first lambda outlet, preceded by the chord path 
	(from the second lambda outlet). The chord is supposed to be modified then by patching, 
	and the modified llll is expected to be received in the lambda inlet. <br />
	@copy BACH_DOC_LAMBDA
	
	@category
	bach, bach abstractions, bach notation

	@keywords
	map, chord, modify, change, each, transform, lambda loop, iterate, iteration, rhythmic tree,
	level, parenthesis

	@seealso
	bach.mapelem, bach.iter, bach.collect
	
	@owner
	Daniele Ghisi
*/

// ---------------
// METHODS
// ---------------

// @method llll @digest Function depends on inlet
// @description An <m>llll</m> in the first inlet is considered to be the gathered syntax of a 
// <o>bach.roll</o> or <o>bach.score</o>, and will trigger the mapping via the lambda loop: lllls
// corresponding to chords are output one by one from the first lambda outlet, preceded by the chord
// path (output from the second lambda outlet, also see the <m>treepath</m> attribute), and the
// modified chord is expected to be re-injected in the lambda inlet (such chord will be substituted
// to the original one). If no element comes in the lambda inlet, the original element is dropped. <br />
// An <m>llll</m> in the second inlet is considered to be the "answer" of the lambda loop. 
// Indeed second inlet is a lambda inlet. <br />
// @copy BACH_DOC_LAMBDA_INLET_MODIFICATION

// @method bang @digest Modify llll
// @description Performs the modification on the most recently received input llll.



// ---------------
// ATTRIBUTES
// ---------------

void main_foo() {

llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

CLASS_ATTR_CHAR(c, "treepath", 0, t_mapchord, tree_path); 
CLASS_ATTR_STYLE_LABEL(c,"treepath",0,"onoff","Output Rhythmic Tree Path");
CLASS_ATTR_BASIC(c,"treepath",0);
// @description If the <m>treepath</m> attribute is set to 1, the chord path output from the second lambda outlet,
// for <o>bach.score</o>, is the path of the chord llll inside the whole gathered syntax tree structure (including possible 
// rhythmic tree levels). If <m>treepath</m> is set to 0, the output path, for <o>bach.score</o>, is only composed by 
// <b><m>voice_num</m> <m>meas_num</m> <m>chord_idx</m></b>, where <m>chord_idx</m> is the index of the chord inside the measure
// (counting from 1). This latter case is the default. Notice that for a <o>bach.roll</o> syntax, on the other hand, this attribute
// has no effect, as the output path is always composed by <b><m>voice_num</m> <m>chord_idx</m></b>.

}

// ---------------
// INLETS
// ---------------

// @in 0 @type llll @digest The original gathered syntax
// @in 1 @type llll @digest Lambda inlet
// @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION



// ---------------
// OUTLETS
// ---------------

// @out 0 @type llll @digest The modified gathered syntax
// @out 1 @type llll @digest Lambda outlet: Chord
// @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION
// @out 2 @type llll @digest Lambda outlet: Path
// @description The second outlet outputs the chord path. By default it is in the form
// <b><m>voice_num</m> <m>chord_idx</m></b> for <o>bach.roll</o> and <b><m>voice_num</m> <m>meas_num</m> <m>chord_idx</m></b>
// for <o>bach.score</o>, where <m>chord_idx</m> is the index of the chord inside the measure
// (counting from 1). This path can be set to a real rhythmic tree path via the <m>treepath</m> attribute.
// @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION

// ---------------
// ARGUMENTS
// ---------------

// (none)
