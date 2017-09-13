/**
	@file
	tree.c
	
	@name 
	bach.tree
	
	@realname 
	bach.tree

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Display and edit lllls in a tree diagram
	
	@description
	Provides a simple interface for displaying and editing llll as tree diagrams.
	
	@discussion
	The incoming llll is displayed in tree form. Clicked elements (and addresses) are output from dedicated outlets.
	Basic llll editing is possible via mouse and keyboard.
	
	@category
	bach, bach objects, bach llll, bach interface, U/I
	
	@keywords
	display, edit, tree, outline, branch, leaf, diagram
	
	@palette
	YES
	
	@palette category
	bach, bach objects, bach llll, bach interface

	@seealso
	bach.print, bach.post, bach.reg, bach.depth, bach.portal, bach.keychain, bach.path2llll, Hello World, Slot Machines
	
	@owner
	Daniele Ghisi
*/

#include "llll_files.h" // llllobj.h is included here
#include "llll_commons_ext.h"
#include "llll_modifiers.h"
#include "paint_wrappers.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "ext_critical.h"
#include <stdio.h>
#include <locale.h>
#include "ext_strings.h"

#define CONST_MAX_DEPTH 100
#define	CONST_BACH_TREE_VSCROLLBAR_WIDTH 10				///< Unscaled width of the vertical scrollbar
#define	CONST_BACH_TREE_VSCROLLBAR_RIGHT_PAD 3			///< Unscaled distance of the vertical scrollbar from the right edge
#define	CONST_BACH_TREE_VSCROLLBAR_MIN_UHEIGHT 10		///< Minimum unscaled height of the vertical scrollbar

#define CONST_BACH_TREE_UY_START_PAD 0

#define CLOSED_LEVEL_LEVELTYPE L_CURLY

typedef enum _undo_redo
{
	k_UNDO = -1,		///< Undo operation
	k_REDO = 1			///< Redo operation
} e_undo_redo;

typedef struct _treenode
{
	t_llllelem			*elem;
	t_llll				*address;				// Node address
	t_llll				*element_address;		// Real address, which might not coincide with node address when first llll element is the name
												// TO DO: to be implemented!
	struct _treenode	*linktofather;
	long				depth;
	long				num_sons;
	
	char				*text;
	
	// for each node
	double				center_x; // for node-link algorithm centers are in [0, 1] otherwise they are REAL centers! 
	double				center_y;
	double				width;
	double				height;
	
	// post-spacing (spacing for "children"): only for node-link algorithm
	double				leaveswidth; // all the width where the leaves might lie 
	double				leavesneededwidth; // the needed width for the leaves to lie
	
	char				is_dummy_node;
	
	// only for outline algorithm:
	char				closed; // used for closed lllls
	char				show_triangle; //show the triangle for opening

	// user modifications: unsupported yet, and in any case only for node-link algorithm
	double				delta_x;
	double				delta_y;
	
} t_treenode;

typedef struct _tree // [bach.tree] structure
{
	t_llllobj_jbox			j_box; // root object

	t_llll					*tree_as_llll; // stored llll
	t_llll					*treenodes; // linear llll: for each element of the tree_as_llll there's a treenode object in this llll containing all the information about the node
	
	char					mode; //  0 = Node-link or 1 = Outline? 
	
//	t_symbol				*j_textfont;
//	double					fontsize;
	double					textdecayfactor; // only used by node-link
	t_jrgba					j_textcolor;
	t_jrgba					j_clickedtextcolor;
	t_jrgba					j_linecolor;
	double					j_linewidth;
	t_jrgba					j_bgcolor;
	t_jrgba					j_bordercolor;
	double					corner_roundness; // corner roundness
	t_rect					rect;
	
	char					need_rebuid_tree_nodes;
	char					need_send_changed_bang;
	t_llllelem				*need_set_clicked_treenode_on_this;
	char					also_send_clicked_elem;
	char					need_send_domainpixels;
	
	 // only used by node-link
	double					needed_y_inset;
	double					y_inset;
	double					x_inset;
	double					leaf_from_leaf_separation; // separation from leaf to leaf for textsize = 12 (and scaled accordingly for other text sizes)
	double					row_vpad;
	
	char					j_has_focus;
	char					show_focus;
	
	char					allow_manual_placement; // UNSUPPORTED
	
	char					first_elem_in_llll_is_llll_name;
	char					output_llll_names_when_llll_clicked;
	char					unwrap;
	
	long					maxdepth;

	long					decimals;
		
	t_systhread_mutex		c_mutex;
	
	t_treenode				*clicked_node;
	char					save_data_with_patcher;
	char					show_first_node;
	t_symbol				*symbol_for_llll;
	char					only_allow_click_on_leaves;
	
	char					prevent_edit; // < Do we allow the editing of nodes?
	char					is_editing; // Some node is being edited?

	t_llll					*undo_llll;	///< List containing undo lllls 
	t_llll					*redo_llll;	///< List containing redo lllls
	t_atom					max_undo_steps;	///< Maximum number of undo steps. If this is 0, the undo is turned off. If this is the symbol gensym("inf"), the number of undo steps is unlimited.
	char					verbose_undo_redo;
	
	// enclosures (only for node-link)
	char					enclosure;
	t_jrgba					j_enclosurebackground;
	t_jrgba					j_enclosurelinecolor;
	
	// only used by outline
	double					scrollbar_pos; // between 0 and 1
	double					scrollbar_height;
	double					scrollbar_top_y;
	char					show_scrollbar;
	double					scrollbar_delta_y;
	double					floatdragging_y;
	char					clicked_on_scrollbar;
	
	// mouse hover
	t_jrgba					j_hovered_text_color;
	t_jrgba					j_hovered_strip_color;
	t_jrgba					j_selected_strip_color;
	t_jrgba					j_alternate_bgcolor;
	char					alternate_stripes;
	t_treenode				*hovered_node;
	
	// preset attributes
	long					preset_ac; // number of deparsed atoms: used by preset
	t_atom					*preset_av; // content of the deparsed atoms

	// utilities
	t_treenode				*active_treenode;
	t_treenode				*father_node[CONST_MAX_DEPTH];
	double					needed_height[CONST_MAX_DEPTH];
	long					last_cmd;
	double					temp; // temporary field

} t_tree;


// global class pointer variable
t_class	*s_tree_class = NULL;

// clipboard
t_llll *clipboard_llll = NULL;

// functions
void tree_inletinfo(t_tree *x, void *b, long a, char *t);
void tree_assist(t_tree *x, void *b, long m, long a, char *s);

void tree_clear(t_tree *x);
void tree_free(t_tree *x);
void tree_getdrawparams(t_tree *x, t_object *patcherview, t_jboxdrawparams *params);

void tree_mousedown(t_tree *x, t_object *patcherview, t_pt pt, long modifiers);
void tree_mousemove(t_tree *x, t_object *patcherview, t_pt pt, long modifiers);
void tree_mouseup(t_tree *x, t_object *patcherview, t_pt pt, long modifiers);
void tree_mousedrag(t_tree *x, t_object *patcherview, t_pt pt, long modifiers);
void tree_mousewheel(t_tree *x, t_object *patcherview, t_pt pt, long modifiers, double x_inc, double y_inc);
void node_inscreenpos(t_tree *x, t_rect rect, t_treenode *tnd, double pos, char only_change_if_not_inscreen, char also_redraw);
void tree_mousedoubleclick(t_tree *x, t_object *patcherview, t_pt pt, long modifiers);
void tree_mouseleave(t_tree *x, t_object *patcherview, t_pt pt, long modifiers);
void tree_enter(t_tree *x);
long tree_keyfilter(t_tree *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter);
long tree_key(t_tree *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);

void tree_focusgained(t_tree *x, t_object *patcherview);
void tree_focuslost(t_tree *x, t_object *patcherview);

//long tree_key(t_tree *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);

t_tree* tree_new(t_symbol *s, long argc, t_atom *argv);

void tree_paint(t_tree *x, t_object *view);

void tree_open(t_tree *x, t_symbol *s, long argc, t_atom *argv);
void tree_close(t_tree *x, t_symbol *s, long argc, t_atom *argv);
void tree_switch(t_tree *x, t_symbol *s, long argc, t_atom *argv);

void tree_click(t_tree *x, t_symbol *s, long argc, t_atom *argv);
void tree_anything(t_tree *x, t_symbol *s, long argc, t_atom *argv);
void tree_int(t_tree *x, t_atom_long num);
void tree_float(t_tree *x, double num);
void tree_dump(t_tree *x);
void tree_bang(t_tree *x);

t_max_err tree_setattr_llllsymbol(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_firsteleminllllisllllname(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_maxdepth(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_textdecayfactor(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_rowvpad(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_showfirstnode(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_decimals(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_mode(t_tree *x, t_object *attr, long ac, t_atom *av);
t_max_err tree_setattr_maxundosteps(t_tree *x, t_object *attr, long ac, t_atom *av);

void tree_clear(t_tree *x);

void tree_undo(t_tree *x);
void tree_redo(t_tree *x);
void create_default_interface_undo_step(t_tree *x);
void send_changed_bang(t_tree *x);


// preset
void tree_jsave(t_tree *x, t_dictionary *d);
void tree_preset(t_tree *x);
void tree_begin_preset(t_tree *x, t_symbol *s, long argc, t_atom *argv);
void tree_restore_preset(t_tree *x, t_symbol *s, long argc, t_atom *argv);
void tree_end_preset(t_tree *x);

void send_domainpixels(t_tree *x);
void send_clicked_node_address_and_content(t_tree *x);
t_llllelem *get_next_open_llllelem(t_tree *x, t_llllelem *elem, char force_open_levels);
t_llllelem *get_prev_open_llllelem(t_tree *x, t_llllelem *elem, char force_open_levels);

	
// PRESET AND SAVING
void tree_jsave(t_tree *x, t_dictionary *d)
{
	if (x->save_data_with_patcher) {
		if (x->j_box.l_dictll) {
			llll_store_in_dictionary(x->j_box.l_dictll, d, "whole_tree_data", NULL);
		} else {
			if (x->tree_as_llll) {
				llll_store_in_dictionary(x->tree_as_llll, d, "whole_tree_data", NULL);
			}
		}
	}
}


void tree_begin_preset(t_tree *x, t_symbol *s, long argc, t_atom *argv)
{
	x->preset_ac = atom_getlong(argv) ;
	x->preset_av = (t_atom *)bach_newptr(x->preset_ac * sizeof(t_atom));
	
	// could allocate memory here etc.
	//	post("begin_preset %ld values will be arriving",x->r_ob.preset_ac);
}

void tree_restore_preset(t_tree *x, t_symbol *s, long argc, t_atom *argv)
{
	long start, size;
	
	start = atom_getlong(argv);
	size = atom_getlong(argv + 1);
	//	post("restore_preset start %ld size %ld", start,size);
	
	sysmem_copyptr(argv+2, x->preset_av+start, size*sizeof(t_atom));
}

void tree_end_preset(t_tree *x)
{
	//	post("end_preset received");
	tree_anything(x, NULL, x->preset_ac,x->preset_av);
	bach_freeptr(x->preset_av);
}


void tree_preset(t_tree *x){
	t_atom temp[256];
	void *buf;
	long i, index, size;
	char wrote = false, begin = true, done = false;
	
	// 1. we deparse the list
	t_atom *av = NULL, *this_av = NULL;
	long ac = llll_deparse(x->tree_as_llll, &av, 0, LLLL_D_FLOAT64 | LLLL_D_QUOTE); //offset 0
	this_av = av;
	
	// 2. We fill the binbuf
	buf = _sym__preset->s_thing; 
	if (!buf)	// no preset object
		return;
	
	index = 0;
	while (!done) {
		i = index;
		size = ac - index;
		if (size > 250)
			size = 250;
		else	// you are at the end
			done = true;
		
		sysmem_copyptr(this_av, temp+5, 250*sizeof(t_atom));
		
		if (size) {
			atom_setobj(temp, x);
			atom_setsym(temp + 1, ob_sym(x));
			if (begin) {
				atom_setsym(temp + 2, _llllobj_sym_begin_preset);
				atom_setlong(temp + 3, ac);
				binbuf_insert(buf, NULL, 4, temp);
				begin = false;
			}
			atom_setsym(temp + 2, _llllobj_sym_restore_preset);
			atom_setlong(temp + 3, index);
			atom_setlong(temp + 4, size);
			binbuf_insert(buf, NULL, size + 5, temp);
			wrote = true;
		}
		index += size;
		this_av += 250;
	}
	if (wrote) {
		atom_setobj(temp, x);
		atom_setsym(temp + 1, ob_sym(x));
		atom_setsym(temp + 2, _llllobj_sym_end_preset);
		binbuf_insert(buf, NULL, 3, temp);
	}
	
	if (av) bach_freeptr(av);
}


/// ACCESSORS

t_max_err tree_setattr_llllsymbol(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->symbol_for_llll = atom_getsym(av);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_firsteleminllllisllllname(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->first_elem_in_llll_is_llll_name = atom_getlong(av);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_maxdepth(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->maxdepth = atom_getlong(av);
		if (x->maxdepth == 0) {
			object_warn((t_object *)x, BACH_MAXDEPTH_0_WARNING);
			x->maxdepth = -1;
		}
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_textdecayfactor(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->textdecayfactor = atom_getfloat(av);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_rowvpad(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->row_vpad = atom_getfloat(av);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_showfirstnode(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->show_first_node = (atom_getlong(av) > 0) ? 1 : 0;
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_decimals(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->decimals = atom_getlong(av);
		if (x->decimals < 0) x->decimals = 0;
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_mode(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		long mode = atom_getlong(av);
		x->mode = mode;
		object_attr_setdisabled((t_object *)x, gensym("linecolor"), mode == 1);
		object_attr_setdisabled((t_object *)x, gensym("enclosurebgcolor"), mode == 1);
		object_attr_setdisabled((t_object *)x, gensym("enclosurelinecolor"), mode == 1);
		object_attr_setdisabled((t_object *)x, gensym("linewidth"), mode == 1);
		object_attr_setdisabled((t_object *)x, gensym("separation"), mode == 1);
		object_attr_setdisabled((t_object *)x, gensym("hinset"), mode == 1);
		object_attr_setdisabled((t_object *)x, gensym("vinset"), mode == 1);
		object_attr_setdisabled((t_object *)x, gensym("enclosure"), mode == 1);
		
		object_attr_setdisabled((t_object *)x, gensym("alternate"), mode == 0);
		object_attr_setdisabled((t_object *)x, gensym("clickedstripcolor"), mode == 0);
		object_attr_setdisabled((t_object *)x, gensym("hoverstripcolor"), mode == 0);
		object_attr_setdisabled((t_object *)x, gensym("rowvpad"), mode == 0);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);
	}
	return MAX_ERR_NONE;
}

t_max_err tree_setattr_maxundosteps(t_tree *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		t_atom old_num_steps = x->max_undo_steps;
		t_atom inf;
		atom_setsym(&inf, _llllobj_sym_inf);
		t_atom new_num_steps = atom_gettype(av) != A_LONG ? inf : *av;

		if (atom_gettype(&new_num_steps) == A_LONG && atom_getlong(&new_num_steps) < 0)
			atom_setlong(&new_num_steps, -atom_getlong(&new_num_steps));
		
		if (atom_gettype(&old_num_steps) == A_LONG && atom_gettype(&new_num_steps) == A_LONG) {
			if (atom_getlong(&new_num_steps) <= atom_getlong(&old_num_steps)) {
				llll_free(llll_slice(x->undo_llll, atom_getlong(&new_num_steps)));
				llll_clear(x->redo_llll);
			}
		} else if (atom_gettype(&new_num_steps) == A_LONG && atom_gettype(&old_num_steps) == A_SYM) {
			llll_free(llll_slice(x->undo_llll, atom_getlong(&new_num_steps)));
			llll_clear(x->redo_llll);
		}
		x->max_undo_steps = new_num_steps;
	}
	return MAX_ERR_NONE;
}

int T_EXPORT main(void){
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.tree", 
						(method)tree_new,
						(method)tree_free,
						sizeof(t_tree),
						(method)NULL,
						A_GIMME,
						0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//	jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
	jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR | JBOX_FIXWIDTH);	// include textfield and Fonts attributes
//	jbox_initclass(c, 0);
	
	class_addmethod(c, (method) tree_paint,			"paint", A_CANT, 0);

	// @method llll @digest Display llll in tree form
	// @description An incoming llll is displayed in tree form.
	class_addmethod(c, (method) tree_anything, "anything", A_GIMME, 0);
	class_addmethod(c, (method) tree_anything, "list", A_GIMME, 0);
	class_addmethod(c, (method) tree_int, "int", A_LONG, 0);
	class_addmethod(c, (method) tree_float, "float", A_FLOAT, 0);

	
	// @method dump @digest Output llll
	// @description The displayed llll is output from the first outlet.
	class_addmethod(c, (method) tree_dump, "dump", 0);


	// @method bang @digest Output llll
	// @description The displayed llll is output from the first outlet, as for the <m>dump</m> message.
	class_addmethod(c, (method) tree_bang, "bang", 0);

	
	// @method clear @digest Clear the diagram
	// @description The displayed llll (if any) is removed from the diagram.
	class_addmethod(c, (method) tree_clear, "clear", 0);


	// @method getdomainpixels @digest Obtain the visibile portion of tree in pixels
	// @description In Outline mode, returns the vertical pixels of the visible portion of tree, with the syntax: 
	// <b>domainpixels <m>upper_y</m> <m>lower_y</m></b>, where <m>upper_y</m> is the upper first visible pixel of the tree,
	// and <m>lower_y</m> is the lower last visible pixel of the tree.
	// If no vertical scrollbar is present, it simply returns the Y pixels of the upper and lower side of the object box.
	// It only works in Outline mode (nothing will happen in Node/Link mode).
	class_addmethod(c, (method) send_domainpixels, "getdomainpixels", 0);

	
	// @method click @digest Set a given node as the clicked node, output information
	// @description A <m>click</m> message sets a given node as the clicked node, and outputs its address and content
	// through the second and third outlets. 
	// The argument is the address of the node to be clicked. Such address can be replaced by the "prev" or "next" symbols
	// in order to click on the previous or next node, with respect to the one being currently clicked (if any). 
	// The ordering of nodes is assumed to be the one used by <o>bach.iter</o> while iterating.
	// For instance, <b>click 1 3 4</b> clicks on the llll element having address <b>1 3 4</b>, and <b>click next</b> then clicks on 
	// the following address.
	// If the clicked node was inside folded levels, such levels are properly unfolded.
	// @marg 0 @name address @optional 0 @type llll
	class_addmethod(c, (method) tree_click, "click", A_GIMME, 0);


	// @method open @digest Unfold diagram levels (in Outline mode)
	// @description In the Outline <m>mode</m>, unfolds the lllls for a certain range of depths. <br /> 
	// If no arguments are given, this unfolds all the llll levels. <br />
	// If one integer argument is given, it is considered to be both the mindepth and the maxdepth for llll levels to be unfolded. <br />
	// If two integer arguments are given, they are considered to be the mindepth and maxdepth for llll levels to be unfolded. <br />
	// Depth 0 refers to the root level. <br />
	// @copy BACH_DOC_MINDEPTH
	// @copy BACH_DOC_MAXDEPTH
	// @marg 0 @name arguments @optional 1 @type list
	class_addmethod(c, (method) tree_open, "open", A_GIMME, 0);


	// @method close @digest Fold diagram levels (in Outline mode)
	// @description In the Outline <m>mode</m>, folds the lllls for a certain range of depths. <br /> <br />
	// If no arguments are given, this folds all the llll levels. <br />
	// If one integer argument is given, it is considered to be both the mindepth and the maxdepth for llll levels to be folded. <br />
	// If two integer arguments are given, they are considered to be the mindepth and maxdepth for llll levels to be folded. <br />
	// Depth 0 refers to the root level. <br />
	// @copy BACH_DOC_MINDEPTH
	// @copy BACH_DOC_MAXDEPTH
	// @marg 0 @name arguments @optional 1 @type list
	class_addmethod(c, (method) tree_close, "close", A_GIMME, 0);

	
	// @method switch @digest Fold/Unfold diagram levels (in Outline mode)
	// @description In the Outline <m>mode</m>, folds the unfolded llll levels, and unfolds the folded llll levels, for a certain range of depths <br /> <br />
	// If no arguments are given, this switches all the llll levels. <br />
	// If one integer argument is given, it is considered to be both the mindepth and the maxdepth for llll levels to be switched. <br />
	// If two integer arguments are given, they are considered to be the mindepth and maxdepth for llll levels to be switched. <br />
	// Depth 0 refers to the root level. <br />
	// @copy BACH_DOC_MINDEPTH
	// @copy BACH_DOC_MAXDEPTH
	// @marg 0 @name arguments @optional 1 @type list
	class_addmethod(c, (method) tree_switch, "switch", A_GIMME, 0);

	class_addmethod(c, (method) tree_getdrawparams, "getdrawparams", A_CANT, 0);
	class_addmethod(c, (method) tree_jsave, "jsave", A_CANT, 0);
    class_addmethod(c, (method) tree_preset, "preset", 0);
    class_addmethod(c, (method) tree_begin_preset, "begin_preset", A_GIMME, 0);
    class_addmethod(c, (method) tree_restore_preset, "restore_preset", A_GIMME, 0);
    class_addmethod(c, (method) tree_end_preset, "end_preset", 0);
	CLASS_METHOD_ATTR_PARSE(c, "begin_preset", "undocumented", _sym_long, 0L, "1");
	CLASS_METHOD_ATTR_PARSE(c, "restore_preset", "undocumented", _sym_long, 0L, "1");
	CLASS_METHOD_ATTR_PARSE(c, "end_preset", "undocumented", _sym_long, 0L, "1");
	
	// @method (mouse) @digest Output or edit clicked element
	// @description The clicked element of the diagram (if any) is output from the second outlet,
	// while its address is output from the third outlet. <br />
	// Clicking on an arrow or on a non-leaf node with <m>onlyclickonleaves</m> set to 1 will
	// open/close the corresponding node, and will send a notification through the third outlet, in 
	// the form <b>open <m>wrapped_node_address</m></b> or <b>open <m>close_node_address</m></b>. <br />
	// Doubleclick on an element to edit it directly, then press Enter or Return to end editing.
	class_addmethod(c, (method) tree_mousedown, "mousedown", A_CANT, 0);

	class_addmethod(c, (method) tree_mousedrag, "mousedrag", A_CANT, 0);
	class_addmethod(c, (method) tree_mousemove, "mousemove", A_CANT, 0);
	class_addmethod(c, (method) tree_mouseup, "mouseup", A_CANT, 0);
	class_addmethod(c, (method) tree_mousewheel, "mousewheel", A_CANT, 0);
    class_addmethod(c, (method) tree_mousedoubleclick, "mousedoubleclick", A_CANT, 0);
	class_addmethod(c, (method) tree_enter,		"enter",		A_CANT, 0);
	class_addmethod(c, (method) tree_focusgained, "focusgained", A_CANT, 0);
	class_addmethod(c, (method) tree_focuslost, "focuslost", A_CANT, 0); 
	class_addmethod(c, (method) tree_mouseleave, "mouseleave", A_CANT, 0);

	
	// @method (keyboard) @digest Edit nodes or dump
	// @description 
	// • <m>Cmd+T</m> (mac) or <m>Ctrl+T</m> (win): Rotate selected llll node of 1 step right <br />
	// • <m>Cmd+R</m> (mac) or <m>Ctrl+R</m> (win): Rotate selected llll node of 1 step left <br />
	// • <m>Cmd+I</m> (mac) or <m>Ctrl+I</m> (win): Reverse llll node <br />
	// • <m>Cmd+Y</m> (mac) or <m>Ctrl+Y</m> (win): Scramble llll node <br />
	// • <m>Cmd+P</m> (mac) or <m>Ctrl+P</m> (win): Wrap llll node <br />
	// • <m>Cmd+Shift+P</m> (mac) or <m>Ctrl+Shift+P</m> (win): Remove 1 level of parentheses <br />
	// • <m>Cmd+D</m> (mac) or <m>Ctrl+D</m> (win): Duplicate node <br />
	// • <m>Cmd+C</m> (mac) or <m>Ctrl+C</m> (win): Copy node content <br />
	// • <m>Cmd+V</m> (mac) or <m>Ctrl+V</m> (win): Paste node content <br />
	// • <m>Cmd+Shift+D</m> (mac) or <m>Ctrl+Shift+D</m> (win): Dump content <br />
	// • <m>Cmd+Z</m> (mac) or <m>Ctrl+Z</m> (win): Undo <br />
	// • <m>Cmd+Shift+Z</m> (mac) or <m>Ctrl+Y</m> (win): Redo <br />
	// • <m>Enter</m> or <m>Return</m>: End editing tree node <br />
	// • <m>Tab</m> and <m>Shift+Tab</m>: Switch to editing (respectively) next and previous tree node <br />
	// • <m>Esc</m>: Un-click the clicked node (if any) <br />
	// • <m>↑</m>: Select previous item (in Outline mode) <br /> 
	//    ↪ Add the <m>Shift</m> key to automatically open closed nodes. <br />
	// • <m>↓</m>: Select next item (in Outlien mode) <br /> 
	//    ↪ Add the <m>Shift</m> key to automatically open closed nodes. <br />
	// • <m>→</m>: Open tree node (in Outline mode) <br /> 
	// • <m>←</m>: Close tree node (in Outlien mode) <br /> 
	class_addmethod(c, (method) tree_key, "key", A_CANT, 0);
	class_addmethod(c, (method) tree_keyfilter, "keyfilter", A_CANT, 0);

	class_addmethod(c, (method) tree_inletinfo, "inletinfo", A_CANT, 0);
	class_addmethod(c, (method) tree_assist, "assist", A_CANT, 0);

	// @method undo @digest Perform an undo step
	// @description An <m>undo</m> message will perform an undo step. 
	class_addmethod(c, (method) tree_undo, "undo", 0);
	
	// @method redo @digest Perform a redo step
	// @description A <m>redo</m> message will perform a redo step. 
	class_addmethod(c, (method) tree_redo, "redo", 0);
	
	
	
	llllobj_class_add_out_attr(c, LLLL_OBJ_UI);
//	llllobj_class_add_check_attr(c, LLLL_OBJ_UI);

	CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 200 120"); // new dimensions
	// @exclude bach.tree

	CLASS_STICKY_ATTR(c,"category",0,"Color");

		CLASS_ATTR_RGBA_LEGACY(c, "bgcolor", "brgb", 0, t_tree, j_bgcolor);
		CLASS_ATTR_ALIAS(c,"bgcolor", "brgba");
		CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"bgcolor",0,"1. 1. 1. 1.");
		CLASS_ATTR_BASIC(c,"bgcolor",0);
		// @description The color of the background.

		CLASS_ATTR_RGBA_LEGACY(c, "alternatecolor", "brgb", 0, t_tree, j_alternate_bgcolor);
		CLASS_ATTR_STYLE_LABEL(c, "alternatecolor", 0, "rgba", "Alternate Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"alternatecolor",0,"0.929 0.953 0.996 1.");
		// @description The color superposed to the <m>bgcolor</m> for the even-indexed stripes, if the <m>alternate</m> attribute is active.
	
		CLASS_ATTR_RGBA_LEGACY(c, "linecolor", "lrgb", 0, t_tree, j_linecolor);
		CLASS_ATTR_ALIAS(c,"linecolor", "lrgba");
		CLASS_ATTR_STYLE_LABEL(c, "linecolor", 0, "rgba", "Line Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"linecolor",0,"0. 0. 0. 1.");
		// @description The color of the lines linking the tree nodes.

		CLASS_ATTR_RGBA_LEGACY(c, "bordercolor", "borgb", 0, t_tree, j_bordercolor);
		CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"bordercolor",0,"0. 0. 0. 1.");
		// @description The color of the border.

		CLASS_ATTR_RGBA_LEGACY(c, "textcolor", "trgb", 0, t_tree, j_textcolor);
		CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"textcolor",0,"0.1 0.1 0.1 1.");
		// @description The color of the text.

		CLASS_ATTR_RGBA_LEGACY(c, "hovertextcolor", "htrgb", 0, t_tree, j_hovered_text_color);
		CLASS_ATTR_STYLE_LABEL(c, "hovertextcolor", 0, "rgba", "Text Color When Mouse Is Over");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"hovertextcolor",0,"0. 0. 0. 1.");
		// @description The color of the text when the mouse is over it.

		CLASS_ATTR_RGBA_LEGACY(c, "hoverstripcolor", "hstrgb", 0, t_tree, j_hovered_strip_color);
		CLASS_ATTR_STYLE_LABEL(c, "hoverstripcolor", 0, "rgba", "Strip Color When Mouse Is Over");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"hoverstripcolor",0,"0.953 0.918 0.941 1.");
		// @description The color of the strip behind the text, in the Outline mode (see <m>mode</m> attribute)
		// when the mouse is over it.

		CLASS_ATTR_RGBA_LEGACY(c, "clickedstripcolor", "selstrgb", 0, t_tree, j_selected_strip_color);
		CLASS_ATTR_STYLE_LABEL(c, "clickedstripcolor", 0, "rgba", "Selected Strip Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"clickedstripcolor",0,"0.855 0.840 0.887 1.");
		// @description The color of the strip behind the text of the selected element, 
		// in the Outline mode (see <m>mode</m> attribute)

		CLASS_ATTR_RGBA_LEGACY(c, "clickedtextcolor", "ctrgb", 0, t_tree, j_clickedtextcolor);
		CLASS_ATTR_STYLE_LABEL(c, "clickedtextcolor", 0, "rgba", "Clicked Node Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"clickedtextcolor",0,"0.8 0. 0.8 1.");
		// @description The color of the text of a selected element (element which has been just clicked upon).
	
		CLASS_ATTR_RGBA_LEGACY(c, "enclosurebgcolor", "ergb", 0, t_tree, j_enclosurebackground);
		CLASS_ATTR_STYLE_LABEL(c, "enclosurebgcolor", 0, "rgba", "Enclosure Background Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"enclosurebgcolor",0,"1. 0.97 0.95 1.");
		// @description The background color of the rectangle enclosing each node (if the <m>enclosure</m> attribute is set to 1).

		CLASS_ATTR_RGBA_LEGACY(c, "enclosurelinecolor", "elrgb", 0, t_tree, j_enclosurelinecolor);
		CLASS_ATTR_STYLE_LABEL(c, "enclosurelinecolor", 0, "rgba", "Enclosure Line Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"enclosurelinecolor",0,"0.2 0.2 0.2 1.");
		// @description The border color of the rectangle enclosing each node (if the <m>enclosure</m> attribute is set to 1).
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c, "category", 0, "Font"); 
	
		CLASS_ATTR_DOUBLE(c,"textdecayfactor",0, t_tree, textdecayfactor);
		CLASS_ATTR_STYLE_LABEL(c,"textdecayfactor",0,"text","Text Depth Decay Factor");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"textdecayfactor",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "textdecayfactor", 0.001);
		CLASS_ATTR_FILTER_MAX(c, "textdecayfactor", 10.);
		CLASS_ATTR_ACCESSORS(c, "textdecayfactor", (method)NULL, (method)tree_setattr_textdecayfactor);
		CLASS_ATTR_BASIC(c,"textdecayfactor",0);
		// @description Factor for the font size which is applied to each depth level, so that one can
		// have the text reducing in size at each level (from top to bottom).

	CLASS_STICKY_ATTR_CLEAR(c, "category"); 

	
	CLASS_STICKY_ATTR(c,"category",0,"Appearance");

		CLASS_ATTR_DOUBLE(c, "rounded", 0, t_tree, corner_roundness); 
		CLASS_ATTR_STYLE_LABEL(c,"rounded",0,"text","Roundness of Box Corners");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rounded",0,"6."); 
		
		CLASS_ATTR_CHAR(c,"showfocus",0, t_tree, show_focus);
		CLASS_ATTR_STYLE_LABEL(c,"showfocus",0,"onoff","Show Focus");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showfocus",0,"1");
		// @description Show that the object has the focus by increasing the width of the border.

		CLASS_ATTR_DOUBLE(c,"linewidth",0, t_tree, j_linewidth);
		CLASS_ATTR_STYLE_LABEL(c,"linewidth",0,"text","Line Width");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linewidth",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "linewidth", 0.);
		// @description The width of the line linking the tree nodes

		CLASS_ATTR_CHAR(c,"enclosure",0, t_tree, enclosure);
		CLASS_ATTR_STYLE_LABEL(c,"enclosure",0,"onoff","Enclose Elements In Rectangles");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"enclosure",0,"0");
		// @description Toggles the display of enclosing rectangles for each tree node.

		CLASS_ATTR_CHAR(c,"alternate",0, t_tree, alternate_stripes);
		CLASS_ATTR_STYLE_LABEL(c,"alternate",0,"onoff","Alternate Stripes");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"alternate",0,"1");
		// @description Alternate stripes in the background of the object (only in Outline
		// mode, see <m>mode</m> attribute, and see <m>alternatecolor</m> attribute).
	
		CLASS_ATTR_DOUBLE(c,"hinset",0, t_tree, x_inset);
		CLASS_ATTR_STYLE_LABEL(c,"hinset",0,"text","Horizontal Inset");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hinset",0,"4.");
		// @description Horizontal inset of the tree display, in pixels.

		CLASS_ATTR_DOUBLE(c,"vinset",0, t_tree, y_inset);
		CLASS_ATTR_STYLE_LABEL(c,"vinset",0,"text","Vertical Inset");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"vinset",0,"4.");
		// @description Vertical inset of the tree display, in pixels.

		CLASS_ATTR_DOUBLE(c,"rowvpad",0, t_tree, row_vpad);
		CLASS_ATTR_STYLE_LABEL(c,"rowvpad",0,"text","Row Vertical Pad");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rowvpad",0,"0.");
		CLASS_ATTR_ACCESSORS(c, "rowvpad", (method)NULL, (method)tree_setattr_rowvpad);
		// @description Vertical pad for each row of the Outline <m>mode</m>, in pixels.
	
		CLASS_ATTR_DOUBLE(c,"separation",0, t_tree, leaf_from_leaf_separation);
		CLASS_ATTR_STYLE_LABEL(c,"separation",0,"text","Separation Between Leaves");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"separation",0,"15");
		// @description Minimum separation in pixels from two elements on the same branch, at the same level of depth,
		// for font size 12 (and scaled accordingly for other font sizes).
	
	CLASS_STICKY_ATTR_CLEAR(c, "category"); 


	CLASS_STICKY_ATTR(c,"category",0,"Behavior");

		CLASS_ATTR_CHAR(c, "mode", 0, t_tree, mode);
		CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mode",0,"0");
		CLASS_ATTR_ENUMINDEX(c, "mode", 0, "Node-Link Outline");
		CLASS_ATTR_ACCESSORS(c, "mode", (method)NULL, (method)tree_setattr_mode);
		CLASS_ATTR_BASIC(c,"mode",0);
		// @description If the mode is <m>Node-Link</m> (default), a diagram with nodes linked via lines is displayed vertically.
		// each llll branches into its "leaves" ("sons") via multiple lines. If the mode is <m>Outline</m>, a diagram in the 
		// "Folder Inspect" style is displayed, where everything is written line by line, and sons are indented, and each llll
		// can be "open" or "closed".
		
		CLASS_ATTR_CHAR(c, "showrootnode", 0, t_tree, show_first_node);
		CLASS_ATTR_STYLE_LABEL(c,"showrootnode",0,"onoff","Show Root llll Node");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showrootnode",0,"0");
		CLASS_ATTR_ACCESSORS(c, "showrootnode", (method)NULL, (method)tree_setattr_showfirstnode);
		CLASS_ATTR_BASIC(c,"showrootnode",0);
		CLASS_ATTR_ALIAS(c,"showrootnode", "showfirstnode");
		// @description Toggles the display of a first "virtual" node representing the whole llll (i.e. the root level).

		CLASS_ATTR_CHAR(c, "firsteleminllllisllllname", 0, t_tree, first_elem_in_llll_is_llll_name);
		CLASS_ATTR_STYLE_LABEL(c,"firsteleminllllisllllname",0,"onoff","First Elements Are llll Names");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"firsteleminllllisllllname",0,"0");
		CLASS_ATTR_ACCESSORS(c, "firsteleminllllisllllname", (method)NULL, (method)tree_setattr_firsteleminllllisllllname);
		CLASS_ATTR_BASIC(c,"firsteleminllllisllllname",0);
		// @description Toggles the ability to interpret first elements in each llll as the name assigned to such llll,
		// and display that name in the llll node.

		CLASS_ATTR_CHAR(c, "outputllllnames", 0, t_tree, output_llll_names_when_llll_clicked);
		CLASS_ATTR_STYLE_LABEL(c,"outputllllnames",0,"onoff","Output llll Names Upon Click");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"outputllllnames",0,"0");
		// @description If this flag is set and <m>firsteleminllllisllllname</m> is set to 1, when the user clicks on a node
		// representing an llll (displayed with its name), only the name is output and not the whole llll. 

		CLASS_ATTR_CHAR(c, "unwrap", 0, t_tree, unwrap);
		CLASS_ATTR_STYLE_LABEL(c,"unwrap",0,"onoff","Unwrap lllls Upon Click");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"unwrap",0,"0");
		// @description If this flag is set, when an llll node has been clicked, the external level of parenthesis of the 
		// corresponding llll is discarded, before outputting it.
	
		CLASS_ATTR_CHAR(c, "embed", 0, t_tree, save_data_with_patcher);
		CLASS_ATTR_STYLE_LABEL(c,"embed",0,"onoff","Save Data With Patcher");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"embed",0,"1");
		CLASS_ATTR_BASIC(c,"embed",0);
		// @description @copy BACH_DOC_EMBED
		
		CLASS_ATTR_CHAR(c, "onlyclickonleaves", 0, t_tree, only_allow_click_on_leaves);
		CLASS_ATTR_STYLE_LABEL(c,"onlyclickonleaves",0,"onoff","Only Allow Click On Leaves");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"onlyclickonleaves",0,"0");
		// @description If this flag is set, the user will have the ability to click only on non-llll elements inside the tree
		// (i.e.: on "leaves"), while the llll levels will ignore the click.
		

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Value");


		CLASS_ATTR_SYM(c, "llllsymbol", 0, t_tree, symbol_for_llll);
		CLASS_ATTR_STYLE_LABEL(c,"llllsymbol",0,"text","Placeholder for lllls");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"llllsymbol",0,"(...)");
		CLASS_ATTR_ACCESSORS(c, "llllsymbol", (method)NULL, (method)tree_setattr_llllsymbol);
		// @description A symbol serving as placeholder to represent llll nodes (unless the attribute
		// <m>firsteleminllllisllllname</m> is set).
		
		CLASS_ATTR_LONG(c, "maxdecimals", 0, t_tree, decimals);
		CLASS_ATTR_STYLE_LABEL(c,"maxdecimals",0,"text","Maximum Number of Decimals in Floating-Point Numbers");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxdecimals",0, "2");
		CLASS_ATTR_ACCESSORS(c, "maxdecimals", (method)NULL, (method)tree_setattr_decimals);
		// @description Maximum number of decimals to represent floating point numbers in lllls.
	
		CLASS_ATTR_LONG(c, "maxdepth", 0, t_tree, maxdepth);
		CLASS_ATTR_STYLE_LABEL(c,"maxdepth",0,"text","Maximum Depth");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxdepth",0,"-1");
		CLASS_ATTR_ACCESSORS(c, "maxdepth", (method)NULL, (method)tree_setattr_maxdepth);
		// @description Maximum depth level at which the tree branching must stop.
		//  If it is negative, the depth level is counted from the innermost level of each branch of the tree.
		//  Defaults to 0, i.e. there is no limitation (equivalent to -1: stop at the innermost level).
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
	
	CLASS_STICKY_ATTR(c,"category",0,"Edit");
	
		CLASS_ATTR_ATOM(c,"maxundosteps",0, t_tree, max_undo_steps);
		CLASS_ATTR_STYLE_LABEL(c,"maxundosteps",0,"text","Maximum Number Of Undo Steps");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxundosteps", 0, "50");	
		CLASS_ATTR_ACCESSORS(c, "maxundosteps", (method)NULL, (method)tree_setattr_maxundosteps);
		// @description Sets the maximum number of undo steps. 0 means that undo/redo system will be made inactive.
		// The "inf" symbol means unlimited undo steps.
		// Defaults to 50. You should change it to 0 if you perform heavy operations in real-time.
	
		CLASS_ATTR_CHAR(c,"verboseundo",0, t_tree, verbose_undo_redo);
		CLASS_ATTR_STYLE_LABEL(c,"verboseundo",0,"onoff","Post Undo/Redo Steps");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"verboseundo", 0, "0");
		// @description Toggles the ability of undo system to post the performed undo or redo steps in the Max window. 
		// By default this is inactive.

		CLASS_ATTR_CHAR(c,"preventedit",0, t_tree, prevent_edit);
		CLASS_ATTR_STYLE_LABEL(c,"preventedit",0,"onoff","Prevent Editing");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"preventedit", 0, "0");
		// @description Prevents the editing of <o>bach.tree</o>'s nodes, via mouse and keyboard. 
		// By default this is inactive (nodes are editable).
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	s_tree_class = c;
	class_register(CLASS_BOX, s_tree_class);
	
	dev_post("bach.tree compiled %s %s", __DATE__, __TIME__);
	return 0;
}


void tree_assist(t_tree *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll to be displayed
		sprintf(s, "llll");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
		if (a == 0) // @out 0 @type llll @digest The displayed llll, when dumped 
			sprintf(s, "llll (%s)", type);
		else if (a == 1) // @out 1 @type llll @digest The clicked element 
			sprintf(s, "llll (%s): Element when clicked", type);
		else if (a == 2) // @out 2 @type llll @digest The address of the clicked element
			sprintf(s, "llll (%s): Address when clicked", type); // @description @copy BACH_DOC_ADDRESS_BASIC
		else if (a == 3) // @out 3 @type llll @digest Queries and notifications
			sprintf(s, "llll (%s): Queries and Notifications", type);
		else // @out 4 @type bang @digest bang when changed
			sprintf(s, "bang When Changed");		// @description This outlet sends a bang whenever the tree llll has been changed via the interface.
	}
}

void tree_inletinfo(t_tree *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void tree_int(t_tree *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	tree_anything(x, _llllobj_sym_list, 1, argv);
}

void tree_float(t_tree *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	tree_anything(x, _llllobj_sym_list, 1, argv);
}



void free_treenode(t_treenode *treenode){
	if (treenode->text)
		bach_freeptr(treenode->text);
	treenode->text = NULL;
	
	if (treenode->address)
		llll_free(treenode->address);
	treenode->address = NULL;

	treenode->linktofather = NULL;
	bach_freeptr(treenode);
}

void clear_nodes(t_tree *x){
	t_llllelem *elem;
	
	x->clicked_node = NULL;
	x->hovered_node = NULL;
	if (x->treenodes) {
		for (elem = x->treenodes->l_head; elem; elem = elem->l_next){
			if (hatom_gettype(&elem->l_hatom) == H_OBJ)
				free_treenode((t_treenode *) hatom_getobj(&elem->l_hatom));
		}
		llll_clear(x->treenodes);
	}
}

void tree_clear(t_tree *x){
	clear_nodes(x);

	if (x->tree_as_llll)
		llll_free(x->tree_as_llll);
		
	x->tree_as_llll = NULL;
	jbox_redraw((t_jbox *) x);
}

void tree_dump(t_tree *x){
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 0, x->tree_as_llll);
}

void tree_bang(t_tree *x){
	tree_dump(x);
}


// return 0 if it is an empty list, 1 otherwise
long tree_iter_lamdba_function(t_tree *x, t_llll *lambda) 
{
	t_llllelem *first_item_elem = lambda->l_head->l_hatom.h_w.w_llll->l_head;
	t_llll *first_item_ll = hatom_getllll(&first_item_elem->l_hatom);
	return first_item_ll == NULL || first_item_ll->l_size > 0;
}

/*
long tree_iter_lamdba_function(t_tree *x, t_llllelem **elems, t_llll **addresses){
	if (elems && *elems && hatom_gettype(&(*elems)->l_hatom) == H_LLLL && hatom_getllll(&(*elems)->l_hatom)->l_size == 0) {
		return 0;
	}
	return 1;
}*/

t_treenode *append_dummy_node_under_node(t_tree *x, t_treenode *parent){
	t_treenode *dummytnd = (t_treenode *)bach_newptr(sizeof(t_treenode));
	dummytnd->is_dummy_node = true;
	dummytnd->text = NULL;
	dummytnd->elem = NULL;
	dummytnd->address = llll_clone(parent->address);
	llll_appendlong(dummytnd->address, 1, 0, WHITENULL_llll);
	dummytnd->depth = parent->depth + 1;
	dummytnd->text = (char *)bach_newptr(1 * sizeof(char));
	dummytnd->text[0] = 0;
	dummytnd->width = dummytnd->height = 0;
	dummytnd->center_x = 0;
	dummytnd->center_y = 0;
	dummytnd->linktofather = parent;
	llll_appendobj(x->treenodes, dummytnd, 0, WHITENULL_llll);
	return dummytnd;
}

// function for the outline shape
long build_all_tree_nodes_fn(void *data, t_hatom *a, const t_llll *address){
	t_tree *x = (t_tree *)data;
	t_treenode *tnd = NULL;
	
	if (hatom_gettype(a) == H_LLLL && (!address || !address->l_head)) {
		if (!x->show_first_node) // The list was the global list
			return 0;
	}
	
	if (x->first_elem_in_llll_is_llll_name && address && address->l_tail && hatom_getlong(&address->l_tail->l_hatom) == 1 &&
		(x->show_first_node || address->l_size > 1)) {
		// nothing to do, it was the llll name
		return 1;
	}
	
	tnd = (t_treenode *)bach_newptr(sizeof(t_treenode));
	tnd->text = NULL;
	tnd->is_dummy_node = false;
	
	tnd->address = llll_get();
	t_llllelem *elem;
	for (elem = address->l_head; elem; elem = elem->l_next)
		llll_appendhatom_clone(tnd->address, &elem->l_hatom, 0, WHITENULL_llll);
	
	tnd->depth = address->l_size;
	tnd->linktofather = NULL; // not needed
	tnd->leavesneededwidth = -1; // dummy for this algorithm
	tnd->elem = address && address->l_head ? llll_hatom2elem(a) : NULL;
	
	if (hatom_gettype(a) == H_LLLL) {
		t_llll *ll = hatom_getllll(a);
		if ((x->maxdepth > 0 && x->maxdepth == tnd->depth) || (x->maxdepth < 0 && ll->l_depth == -x->maxdepth - 1)) {
			// node is textual: we've reached the maximum depth
			tnd->num_sons = 0;
			tnd->closed = false;
			tnd->show_triangle = false;
			llll_to_text_buf(ll, &tnd->text, 0, x->decimals, 0, NULL);
		} else {
			tnd->num_sons = ll->l_size;
			if (ll->l_size == 0) {
				tnd->show_triangle = false;
			} else {
				tnd->closed = (ll->l_leveltype == CLOSED_LEVEL_LEVELTYPE ? 1 : 0);
				tnd->show_triangle = true;
				if (x->first_elem_in_llll_is_llll_name) {
					if (ll->l_head) {
						t_llll *dummy = llll_get();
						llll_appendhatom_clone(dummy, &ll->l_head->l_hatom, 0, WHITENULL_llll);
						llll_to_text_buf(dummy, &tnd->text, 0, x->decimals, LLLL_T_COPYSYMBOLS, NULL);
						llll_free(dummy);
						
						tnd->num_sons --;
						if (tnd->num_sons == 0) 
							tnd->show_triangle = false;
					}
				}
			}
		}
	} else {
		tnd->num_sons = 0;
		tnd->closed = false;
		tnd->show_triangle = false;
		
		t_llll *dummy = llll_get();
		llll_appendhatom_clone(dummy, a, 0, WHITENULL_llll);
		llll_to_text_buf(dummy, &tnd->text, 0, x->decimals, LLLL_T_COPYSYMBOLS, NULL);
		llll_free(dummy);
	}

	if (tnd) {
		llll_appendobj(x->treenodes, tnd, 0, WHITENULL_llll);
		double fontsize = jbox_get_fontsize((t_object *)x);
		t_jfont *font = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
										   (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), fontsize);
		jfont_text_measure(font, tnd->text, &tnd->width, &tnd->height);
		jfont_destroy_debug(font);

		if (x->textdecayfactor != 1.) {
			double multiplier = pow(x->textdecayfactor, tnd->depth - 1);
			tnd->height *= multiplier;
			tnd->width *= multiplier;
		}

		if (x->mode == 1)
			tnd->height += x->row_vpad;

		double left_x = 1.5 * fontsize + x->x_inset + (tnd->depth - (x->show_first_node == 0)) * fontsize;
		tnd->center_y = x->temp + tnd->height/2.;
		tnd->center_x = left_x + tnd->width/2.;
		
		x->temp += tnd->height;
		
		if (tnd->closed)
			return 1;
	}
	
	return 0;
}

// function for the node-link shape
long tree_iter_address_and_data(t_tree *x, long list, t_llll *ll, char isaddress)
{
//	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, list * 2 + isaddress, ll);

	if (isaddress){
		t_treenode *tnd;
		if (x->show_first_node && x->first_elem_in_llll_is_llll_name && // The list was a null list
			ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_LONG && hatom_getlong(&ll->l_head->l_hatom) == 1) {
			x->active_treenode = NULL;
			return 0;
		}
		
		tnd = (t_treenode *)bach_newptr(sizeof(t_treenode));
		tnd->text = NULL;
		tnd->is_dummy_node = false;
		tnd->address = llll_clone(ll);
		tnd->depth = tnd->address->l_size;
		
		if (x->last_cmd <= 0)
			tnd->linktofather = x->father_node[tnd->depth - 1];
		else if (x->last_cmd > 0) {
			long i;
			for (i = 1; i <= x->last_cmd; i++){
				t_jfont *font;
				t_treenode *fathertnd = (t_treenode *)bach_newptr(sizeof(t_treenode));
				fathertnd->is_dummy_node = false;
				fathertnd->text = NULL;
				fathertnd->elem = NULL;
				fathertnd->address = llll_clone(ll);
				llll_free(llll_slice(fathertnd->address, -x->last_cmd + i - 1));
				fathertnd->depth = fathertnd->address->l_size;
				
				if (!x->first_elem_in_llll_is_llll_name){ // dummy symbol for lllls
					fathertnd->text = (char *)bach_newptr(MAX_SYM_LENGTH * sizeof(char));
					snprintf_zero(fathertnd->text, MAX_SYM_LENGTH, "%s", x->symbol_for_llll->s_name);
				} else { // first element in llll is the name!
					t_llll *babyllll = llll_get();
					t_llll *towrite = llll_get();
					llll_findchildren(x->tree_as_llll, fathertnd->address, 0, babyllll, NULL);
					if (babyllll->l_head && hatom_gettype(&babyllll->l_head->l_hatom) == H_OBJ) {
						t_llllelem *parentllllelem = (t_llllelem *)hatom_getobj(&babyllll->l_head->l_hatom);
						if (hatom_gettype(&parentllllelem->l_hatom) == H_LLLL) {
							t_llll *thisllll = hatom_getllll(&parentllllelem->l_hatom);
							if (thisllll && thisllll->l_head)
								llll_appendhatom_clone(towrite, &thisllll->l_head->l_hatom, 0, WHITENULL_llll);
						}
					}
					llll_to_text_buf(towrite, &fathertnd->text, 0, x->decimals, LLLL_T_COPYSYMBOLS, NULL);
					llll_free(babyllll);
					llll_free(towrite);
				}
				
				
				font = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
											 (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x));
				jfont_text_measure(font, fathertnd->text, &fathertnd->width, &fathertnd->height);
				jfont_destroy_debug(font);

				if (x->textdecayfactor != 1.) {
					double multiplier = pow(x->textdecayfactor, fathertnd->depth - 1);
					fathertnd->height *= multiplier;
					fathertnd->width *= multiplier;
				}
				
				if (x->mode == 1)
					fathertnd->height += x->row_vpad;
				
				if (fathertnd->height > x->needed_height[fathertnd->depth] && (0 >= fathertnd->depth && fathertnd->depth < CONST_MAX_DEPTH))
					x->needed_height[fathertnd->depth] = fathertnd->height;

				fathertnd->center_x = 0;
				fathertnd->center_y = 0;
				fathertnd->linktofather = x->father_node[fathertnd->depth - 1];
				
				if (x->show_first_node && !fathertnd->linktofather && x->treenodes->l_head)
					fathertnd->linktofather = (t_treenode *) hatom_getobj(&x->treenodes->l_head->l_hatom);

				if (0 <= fathertnd->depth && fathertnd->depth < CONST_MAX_DEPTH)
					x->father_node[fathertnd->depth] = fathertnd;
				llll_appendobj(x->treenodes, fathertnd, 0, WHITENULL_llll);
			}
			
			tnd->linktofather = x->father_node[tnd->depth - 1];
			
			if (x->first_elem_in_llll_is_llll_name){
				free_treenode(tnd);
				tnd = NULL;
			}
		} 
		x->active_treenode = tnd;
	} else if (x->active_treenode) {
		t_jfont *font;
		x->active_treenode->elem = NULL;
//		x->active_treenode->elem = ll->l_owner ? llll_hatom2elem(&ll->l_owner->l_hatom) : NULL;
		x->active_treenode->text = NULL;
		if (ll->l_size == 1 && hatom_gettype(&ll->l_head->l_hatom) == H_LLLL && hatom_getllll(&ll->l_head->l_hatom)->l_size == 0) { // ll is nil
			x->active_treenode->text = (char *)bach_newptr(MAX_SYM_LENGTH * sizeof(char));
			snprintf_zero(x->active_treenode->text, MAX_SYM_LENGTH, "%s", x->symbol_for_llll->s_name);
			
			// creating dummy node at 1 level deeper
			append_dummy_node_under_node(x, x->active_treenode);
		} else 
			llll_to_text_buf(ll, &x->active_treenode->text, 0, x->decimals, LLLL_T_COPYSYMBOLS, NULL);
		
		font = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
									 (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x));
		jfont_text_measure(font, x->active_treenode->text, &x->active_treenode->width, &x->active_treenode->height);
		jfont_destroy_debug(font);

		if (x->textdecayfactor != 1.) {
			double multiplier = pow(x->textdecayfactor, x->active_treenode->depth - 1);
			x->active_treenode->height *= multiplier;
			x->active_treenode->width *= multiplier;
		}

		if (x->mode == 1)
			x->active_treenode->height += x->row_vpad;

		if (x->active_treenode->height > x->needed_height[x->active_treenode->depth] && (0 <= x->active_treenode->depth && x->active_treenode->depth < CONST_MAX_DEPTH))
			x->needed_height[x->active_treenode->depth] = x->active_treenode->height;

		if (x->show_first_node && !x->active_treenode->linktofather && x->treenodes->l_head)
			x->active_treenode->linktofather = (t_treenode *) hatom_getobj(&x->treenodes->l_head->l_hatom);

		llll_appendobj(x->treenodes, x->active_treenode, 0, WHITENULL_llll);
	}
	return 0;
}

long tree_iter_cmd(t_tree *x, long cmd)
{
	x->last_cmd = cmd;
	return 0;
}

void rebuild_treenodes(t_tree *x, t_rect view_rect){
	long i, global_depth;
	long howmany_elems_on_depth[CONST_MAX_DEPTH];
	double needed_width_for_this_depth[CONST_MAX_DEPTH];
	double running_width_for_this_branch[CONST_MAX_DEPTH];
	char level_is_good[CONST_MAX_DEPTH];
	long depthiter, samefathercount;
	t_treenode *activefather;
	t_llllelem *elem;
	double fontsize = jbox_get_fontsize((t_object *)x);
	
	char need_to_transfer_mousedown = (x->clicked_node != NULL);
	t_llllelem	*mousedown_elem = x->clicked_node ? x->clicked_node->elem : NULL;
 	
	if (!x->tree_as_llll){
		tree_clear(x);
		return;
	}
	
	clear_nodes(x);
	
	x->active_treenode = NULL;
	for (i = 0; i < CONST_MAX_DEPTH; i++) { 
		x->father_node[i] = NULL;
		x->needed_height[i] = 0.;
	}
	
	// first node if needed!
	if (x->show_first_node && x->tree_as_llll && x->mode == 0){
		t_jfont *font;
		t_treenode *firsttnd = (t_treenode *)bach_newptr(sizeof(t_treenode));
		firsttnd->is_dummy_node = false;
		firsttnd->text = NULL;
		firsttnd->elem = NULL;
		firsttnd->address = llll_get();
		firsttnd->depth = 0;
		if (!x->first_elem_in_llll_is_llll_name || !x->tree_as_llll->l_head){ // dummy symbol for lllls
			firsttnd->text = (char *)bach_newptr(MAX_SYM_LENGTH * sizeof(char));
			snprintf_zero(firsttnd->text, MAX_SYM_LENGTH, "%s", x->symbol_for_llll->s_name);
		} else { // first element in llll is the name!
			t_llll *towrite = llll_get();
			llll_appendhatom_clone(towrite, &x->tree_as_llll->l_head->l_hatom, 0, WHITENULL_llll);
			llll_to_text_buf(towrite, &firsttnd->text, 0, x->decimals, LLLL_T_COPYSYMBOLS, NULL);
			llll_free(towrite);
		}
		
		font = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
									 (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x));
		jfont_text_measure(font, firsttnd->text, &firsttnd->width, &firsttnd->height);
		jfont_destroy_debug(font);
		
		if (x->mode == 1)
			firsttnd->height += x->row_vpad;
		
		x->needed_height[0] = firsttnd->height;
		firsttnd->center_x = 0.5;
		firsttnd->center_y = 0.;
		firsttnd->linktofather = NULL;
		llll_appendobj(x->treenodes, firsttnd, 0, WHITENULL_llll);
		
		if (!x->tree_as_llll->l_head) // null list
			append_dummy_node_under_node(x, firsttnd);
	}
	
	if (x->mode == 1)  {
		x->temp = x->y_inset;
		llll_funall(x->tree_as_llll, build_all_tree_nodes_fn, x, 1, x->maxdepth, FUNALL_PROCESS_WHOLE_SUBLISTS);
		x->need_rebuid_tree_nodes = false;
		return; // we are done
	} else {
		llll_iter(1, &x->tree_as_llll, x->maxdepth, 0, 0, 0, 0, 0, NULL,
				  (iter_datafn) tree_iter_address_and_data, x, 
				  (iter_datafn) tree_iter_address_and_data, x, 
				  (iter_cmdfn) tree_iter_cmd, x,
				  NULL, NULL,
				  (iter_lambdafn) tree_iter_lamdba_function, x);
	}
	
	global_depth = MIN(x->tree_as_llll->l_depth, CONST_MAX_DEPTH - 1);
	
	if (x->maxdepth > 0) 
		global_depth = MIN(global_depth, x->maxdepth);
	else if (x->maxdepth < -1) 
		global_depth = MAX(0, global_depth + x->maxdepth + 1);
		
	if (x->show_first_node)
		global_depth++;

	for (i = 0; i < CONST_MAX_DEPTH; i++){
		howmany_elems_on_depth[i] = 0;
		needed_width_for_this_depth[i] = 0;
		running_width_for_this_branch[i] = 0;
	}
	
	for (elem = x->treenodes->l_head; elem; elem = elem->l_next) {
		t_treenode *tnd = (t_treenode *)hatom_getobj(&elem->l_hatom);

		tnd->leavesneededwidth = 0.;
		tnd->elem = llll_nth_one(x->tree_as_llll, tnd->address);

		if (need_to_transfer_mousedown && mousedown_elem == tnd->elem)
			x->clicked_node = tnd;
	}

	for (elem = x->treenodes->l_head; elem; elem = elem->l_next) {
		t_treenode *tnd = (t_treenode *)hatom_getobj(&elem->l_hatom);
		long this_depth = MIN(tnd->depth, CONST_MAX_DEPTH - 1);
		if (global_depth <= 1)	
			tnd->center_y = 0.5;
		else 
			tnd->center_y = ((double)this_depth - 1 + (x->show_first_node == 1))/((double)global_depth - 1);
		howmany_elems_on_depth[this_depth]++;
		needed_width_for_this_depth[this_depth] += tnd->width/view_rect.width;
		
		if (tnd->is_dummy_node)
			tnd->height = x->needed_height[tnd->depth];
		
		if (tnd->linktofather)
			tnd->linktofather->leavesneededwidth += tnd->width/view_rect.width;
		
		tnd->delta_x = tnd->delta_y = 0.;
		tnd->leaveswidth = 0.;
		tnd->num_sons = -1; // to be set
	}
	x->needed_y_inset = MAX(x->needed_height[(x->show_first_node == 1 ? 0 : 1)], x->needed_height[global_depth])/2.;
	
	for (depthiter = 1; depthiter <= global_depth && depthiter < CONST_MAX_DEPTH; depthiter++) {
		samefathercount = 0;
		activefather = NULL;
		level_is_good[depthiter] = true;
		for (elem = x->treenodes->l_head; elem; elem = elem->l_next) {
			t_treenode *tnd = (t_treenode *)hatom_getobj(&elem->l_hatom);
			if (tnd->depth == depthiter) {
				long this_branch_length = 1;
				
				// first of all we check how many sons this node has
				if (tnd->num_sons < 0) { // has to be checked
					t_llll *babyllll = llll_get();
					llll_findchildren(x->tree_as_llll, tnd->address, 0, babyllll, NULL);
					if (babyllll->l_head && hatom_gettype(&babyllll->l_head->l_hatom) == H_OBJ) {
						t_llllelem *parentllllelem = (t_llllelem *)hatom_getobj(&babyllll->l_head->l_hatom);
						if (parentllllelem && hatom_gettype(&parentllllelem->l_hatom) == H_LLLL) {
							tnd->num_sons = hatom_getllll(&parentllllelem->l_hatom)->l_size;
							if (x->first_elem_in_llll_is_llll_name)
								tnd->num_sons--;
						} else
							tnd->num_sons = 0;
					} else 
						tnd->num_sons = 0;

					llll_free(babyllll);
				}
				
				if (tnd->linktofather == activefather)
					samefathercount++;
				else {
					running_width_for_this_branch[depthiter] = 0.;
					samefathercount = 1;
				}
					
				this_branch_length = tnd->linktofather ? tnd->linktofather->num_sons : x->tree_as_llll->l_size;
				this_branch_length = MAX(this_branch_length, 1);

				if (depthiter == 1) {
					long denominator = (x->show_first_node && x->first_elem_in_llll_is_llll_name && x->tree_as_llll->l_size > 1) ? 
											x->tree_as_llll->l_size - 1: x->tree_as_llll->l_size;
					double whitespace_repatition = (1 - needed_width_for_this_depth[1])/((double)(denominator <= 0 ? 1 : denominator));
					tnd->center_x = (samefathercount - 0.5) * whitespace_repatition + running_width_for_this_branch[1] + tnd->width/(2.*view_rect.width);
					tnd->leaveswidth = whitespace_repatition + tnd->width/view_rect.width;
				} else if (this_branch_length <= 1) {
					tnd->center_x = tnd->linktofather->center_x;
					tnd->leaveswidth = tnd->linktofather->leaveswidth;
				} else {
					double whitespace_repatition = (tnd->linktofather->leaveswidth - tnd->linktofather->leavesneededwidth)/((double)(this_branch_length <= 0 ? 1 : this_branch_length));
					if (whitespace_repatition < 0)
						level_is_good[depthiter] = false;
					tnd->center_x = tnd->linktofather->center_x - tnd->linktofather->leaveswidth/2. + (samefathercount - 0.5) * whitespace_repatition + running_width_for_this_branch[depthiter] + tnd->width/(2.*view_rect.width);
					tnd->leaveswidth = whitespace_repatition + tnd->width/view_rect.width;
				}
				
				running_width_for_this_branch[depthiter] += tnd->width/view_rect.width;
				activefather = tnd->linktofather;

//				if (howmany_elems_on_depth[depthiter] <= 1) 
//					tnd->center_x_justified = tnd->center_x_rigid;
//				else
//					tnd->center_x_justified = ((double) depth_count[depthiter] - 1)/((double)x->howmany_elems_on_depth[depthiter] - 1);
			}
		}
		
		if (!level_is_good[depthiter]){
			// gotta handle collisions

			double cursor = 0;
			double start_point_for_depth = -1;
			double total_width_needed = 0.;
			for (elem = x->treenodes->l_head; elem; elem = elem->l_next) {
				t_treenode *tnd = (t_treenode *)hatom_getobj(&elem->l_hatom);
				if (tnd->depth == depthiter) {
					double diff;
					total_width_needed += tnd->width/view_rect.width;
					diff = (tnd->center_x - tnd->width/(2.*view_rect.width)) - (cursor + x->leaf_from_leaf_separation * (fontsize/12.) / (2. * view_rect.width)); 
					if (diff < 0) // left collision
						tnd->center_x -= diff;
					cursor = tnd->center_x + tnd->width/(2.*view_rect.width);
					if (start_point_for_depth < 0)
						start_point_for_depth = tnd->center_x - tnd->width/(2.*view_rect.width);
				}
			}

			if (cursor > 1.) {
				// overflown at right! gotta come back, adding a negative value to all elements
				// pushing them towards left
				double additional_width_per_note = ((double)(1. - total_width_needed))/(howmany_elems_on_depth[depthiter] + 1);
				if (additional_width_per_note < 0) 
					additional_width_per_note = 0.;
				if (total_width_needed < 0.8) 
					additional_width_per_note = 0.;
				cursor = 1.;
				for (elem = x->treenodes->l_tail; elem; elem = elem->l_prev) {
					t_treenode *tnd = (t_treenode *)hatom_getobj(&elem->l_hatom);
					if (tnd->depth == depthiter) {
						if (tnd->center_x + tnd->width/(view_rect.width) > cursor) {
							tnd->center_x = cursor - tnd->width/(2*view_rect.width) - additional_width_per_note; 
							cursor = tnd->center_x - tnd->width/(2*view_rect.width); 
						} else {
							cursor = tnd->center_x - tnd->width/(2*view_rect.width); 
							break; // solved!
						}
					}
				}

				
				if (cursor < 0.) {
					double to_add = -cursor;
					double compress_multiplier = 1./(1+to_add);
					for (elem = x->treenodes->l_tail; elem; elem = elem->l_prev) {
						t_treenode *tnd = (t_treenode *)hatom_getobj(&elem->l_hatom);
						if (tnd->depth == depthiter) {
							tnd->center_x += to_add;
							tnd->center_x *= compress_multiplier;
						}
					}
				}
			}
		}

	}
	
/*
	char *debug = NULL;
	llll_to_text_buf(x->treenodes, &debug, 0, 6, 0);
	post(debug);
	bach_freeptr(debug);
*/
	x->need_rebuid_tree_nodes = false;
}

void open_close_switch_llll(t_llll *ll, char mode)
{
	if (mode == 1)
		ll->l_leveltype = L_STANDARD;
	else if (mode == 2)
		ll->l_leveltype = CLOSED_LEVEL_LEVELTYPE;
	else if (mode == 3)
		ll->l_leveltype = (ll->l_leveltype == L_STANDARD ? CLOSED_LEVEL_LEVELTYPE : L_STANDARD);
}

// *data -> 1 = open, 2 = close, 3 = switch
// negative modes mean: don't parse root level
long open_close_switch_fn(void *data, t_hatom *a, const t_llll *address){
	char mode = *((char *)data);
	if (hatom_gettype(a) == H_LLLL && ((mode > 0) || (address && address->l_head))) 
		open_close_switch_llll(hatom_getllll(a), abs(mode));
	return 0;
}


void tree_open_close_switch(t_tree *x, t_symbol *s, long argc, t_atom *argv, char mode){
	t_llll *args = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
	long mindepth = 1;
	long maxdepth = -1;
	char thismode = mode;

	if (args->l_depth == 2 && args->l_size == 1 && args->l_head && hatom_gettype(&args->l_head->l_hatom) == H_LLLL) { 
		// open single node
		t_llllelem *elem = llll_nth_one(x->tree_as_llll, hatom_getllll(&args->l_head->l_hatom));
		if (elem && hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *ll = hatom_getllll(&elem->l_hatom);
			if (ll) {
				if (mode == 1)
					ll->l_leveltype = L_STANDARD;
				else if (mode == 2)
					ll->l_leveltype = CLOSED_LEVEL_LEVELTYPE;
				else if (mode == 3)
					ll->l_leveltype = (ll->l_leveltype == L_STANDARD ? CLOSED_LEVEL_LEVELTYPE : L_STANDARD);
			}
		}
	} else if (args->l_size >= 1 && is_hatom_number(&args->l_head->l_hatom)) {
		mindepth = maxdepth = hatom_getlong(&args->l_head->l_hatom);
		if (args->l_head->l_next && is_hatom_number(&args->l_head->l_next->l_hatom)) 
			maxdepth = hatom_getlong(&args->l_head->l_next->l_hatom);
//		thismode = -thismode; // hack to avoid parsing first node
		llll_funall(x->tree_as_llll, open_close_switch_fn, &thismode, mindepth, maxdepth, FUNALL_SKIP_ATOMS);
	} else if (args->l_size >= 1 && hatom_gettype(&args->l_head->l_hatom) == H_SYM && hatom_getsym(&args->l_head->l_hatom) == _llllobj_sym_root) { 
		open_close_switch_llll(x->tree_as_llll, mode);
	} else { // all
		llll_funall(x->tree_as_llll, open_close_switch_fn, &thismode, 1, -1, FUNALL_SKIP_ATOMS);
	}

	
	llll_free(args);
	x->need_rebuid_tree_nodes = true;
	x->need_send_domainpixels = true;
	jbox_redraw((t_jbox *) x);
}

void tree_open(t_tree *x, t_symbol *s, long argc, t_atom *argv){
	tree_open_close_switch(x, s, argc, argv, 1);
}


void tree_close(t_tree *x, t_symbol *s, long argc, t_atom *argv){
	tree_open_close_switch(x, s, argc, argv, 2);
}

void tree_switch(t_tree *x, t_symbol *s, long argc, t_atom *argv){
	tree_open_close_switch(x, s, argc, argv, 3);
}



void click_on_node(t_tree *x, t_llll *node_address, char also_send_clicked_elem, char also_open_node_if_needed)
{
	if (x->tree_as_llll) {
		t_llllelem *elem = NULL;
		
		 if (node_address->l_head && hatom_gettype(&node_address->l_head->l_hatom) == H_SYM) {
			if (x->clicked_node && hatom_getsym(&node_address->l_head->l_hatom) == _llllobj_sym_next) {
				elem = get_next_open_llllelem(x, x->clicked_node->elem, also_open_node_if_needed);
			} else if (x->clicked_node && hatom_getsym(&node_address->l_head->l_hatom) == _llllobj_sym_prev) {
				elem = get_prev_open_llllelem(x, x->clicked_node->elem, also_open_node_if_needed);
			}
		 } else
			elem = llll_nth_one(x->tree_as_llll, node_address);
		
		if (elem) {
		
			if (also_open_node_if_needed && elem != WHITENULL_llllelem) {
				t_llllelem *temp = elem;
				while (temp && temp->l_parent) {
					temp->l_parent->l_leveltype = L_STANDARD;
					temp = temp->l_parent->l_owner;
				}
				x->need_rebuid_tree_nodes = true;
			}
			
			x->need_set_clicked_treenode_on_this = elem;
			x->also_send_clicked_elem = also_send_clicked_elem;
			jbox_redraw((t_jbox *) x);
		} 
	}
}

void tree_click(t_tree *x, t_symbol *s, long argc, t_atom *argv){ //argv+1
	t_llll *incomingllll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_RETAIN);
	systhread_mutex_lock(x->c_mutex);
	click_on_node(x, incomingllll, true, true);
	systhread_mutex_unlock(x->c_mutex);
	llll_free(incomingllll);
}

void tree_anything(t_tree *x, t_symbol *s, long argc, t_atom *argv){ //argv+1
	t_llll *incomingllll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE);

	create_default_interface_undo_step(x);
	
	tree_clear(x);
	
	if (incomingllll) 
		x->tree_as_llll = incomingllll;

	x->need_rebuid_tree_nodes = true;
	jbox_redraw((t_jbox *) x);
}

t_tree* tree_new(t_symbol *s, long argc, t_atom *argv){
	t_tree* x = NULL;
	t_max_err err = MAX_ERR_GENERIC;
	t_dictionary *d;
	t_object *textfield;
	long flags;
	
	if (!(d=object_dictionaryarg(argc,argv)))
		return NULL;

	x = (t_tree*) object_alloc_debug(s_tree_class);
	flags = 0 
			| JBOX_DRAWFIRSTIN 
			| JBOX_NODRAWBOX
			| JBOX_DRAWINLAST
	//		| JBOX_TRANSPARENT	
	//		| JBOX_NOGROW
	//		| JBOX_GROWY
			| JBOX_GROWBOTH
			| JBOX_HILITE
	//		| JBOX_BACKGROUND
			| JBOX_TEXTFIELD
			| JBOX_DRAWBACKGROUND
	//		| JBOX_DEFAULTNAMES
	//		| JBOX_MOUSEDRAGDELTA
			;

	err = jbox_new(&x->j_box.l_box, flags, argc, argv); 
	x->j_box.l_box.b_firstin = (t_object*) x;
	x->is_editing = false;

	x->show_focus = 1;
	x->j_has_focus = 0;
	x->clicked_on_scrollbar = 0;
	x->scrollbar_pos = 0;
	x->scrollbar_height = 0;
	x->scrollbar_top_y = 0;
	x->show_scrollbar = 0;
	x->scrollbar_delta_y = 0;
	x->floatdragging_y = 0;

	x->hovered_node = NULL;
	x->maxdepth = 0;
	x->textdecayfactor = 1.;
	x->tree_as_llll = NULL;
	x->treenodes = llll_get();
	x->need_rebuid_tree_nodes = false;
	x->need_send_changed_bang = false;
	x->need_set_clicked_treenode_on_this = NULL;
	x->need_send_domainpixels = false;
	x->also_send_clicked_elem = false;
	
	x->x_inset = x->y_inset = x->needed_y_inset = 0;
	x->decimals = 2;
	x->rect = build_rect(0, 0, 0, 0);
	
	x->undo_llll = llll_get();
	x->redo_llll = llll_get();
	
	// retrieve saved attribute values
	attr_dictionary_process(x, d);

	textfield = jbox_get_textfield((t_object *) x); 
	if (textfield) {
		textfield_set_noactivate(textfield, 1);
		textfield_set_editonclick(textfield, 0);			// set it to 0 if you don't want user to edit it in lock mode
		textfield_set_textmargins(textfield, 0, 0, 0, 0);	// margin on each side
		textfield_set_textcolor(textfield, &x->j_textcolor);
		textfield_set_wordwrap(textfield, 0);
		textfield_set_autoscroll(textfield, 1);
	}
	
	llllobj_jbox_setup((t_llllobj_jbox *) x, 3, "b4444");

	// mutex
	systhread_mutex_new_debug(&x->c_mutex, 0);

	jbox_ready(&x->j_box.l_box);

	if (x) {
		// retrieving saved values?
		t_llll *llll_for_rebuild = llll_retrieve_from_dictionary_with_leveltypes(d, "whole_tree_data");
		if (llll_for_rebuild) { 
			llllobj_manage_dict_llll((t_object *)x, LLLL_OBJ_UI, llll_for_rebuild);
			x->tree_as_llll = llll_for_rebuild;
			x->need_rebuid_tree_nodes = true;
			jbox_redraw((t_jbox *) x);
		}

		return x;
	}

	object_free_debug(x);
	return NULL;
}

void tree_free(t_tree *x){
	tree_clear(x);
	llll_free(x->treenodes);
	llll_free(x->undo_llll);
	llll_free(x->redo_llll);
	jbox_free(&x->j_box.l_box);
	systhread_mutex_free_debug(x->c_mutex);
	llllobj_jbox_free((t_llllobj_jbox *) x);
}

void tree_focusgained(t_tree *x, t_object *patcherview) {
	//	object_post((t_object *)x, "focusgained"); 
	x->j_has_focus = true;
	jbox_redraw((t_jbox *)x);
}

void tree_focuslost(t_tree *x, t_object *patcherview) {
	//	object_post((t_object *)x, "focuslost"); 
	x->j_has_focus = false;
	jbox_redraw((t_jbox *)x);
}



void tree_getdrawparams(t_tree *x, t_object *patcherview, t_jboxdrawparams *params)
{
	params->d_bordercolor = x->j_bordercolor;
	params->d_borderthickness = (x->show_focus && x->j_has_focus) ? 2.5 : 1.;
	params->d_cornersize = x->corner_roundness;
	params->d_boxfillcolor = x->j_bgcolor;
}

void paint_small_triangle(t_tree *x, t_jgraphics *g, double x_pos, double y_pos, double triangle_width, char closed)
{
	t_jrgba tricolor = get_grey(0.5);
	jgraphics_set_source_jrgba(g, &tricolor); 
	jgraphics_set_line_width(g, 0.);
	if (closed) {
		jgraphics_move_to(g, x_pos + triangle_width, y_pos);
		jgraphics_line_to(g, x_pos, y_pos - triangle_width);
		jgraphics_line_to(g, x_pos, y_pos + triangle_width);
	} else {
		jgraphics_move_to(g, x_pos + triangle_width, y_pos);
		jgraphics_line_to(g, x_pos, y_pos + triangle_width);
		jgraphics_line_to(g, x_pos - triangle_width, y_pos);
	}
	jgraphics_close_path(g); 
	jgraphics_fill(g);	
}


void send_domainpixels(t_tree *x)
{
	if (x->mode == 1) {
		double pixel_y_start = 0;
		double pixel_y_end = x->rect.height;
		if (x->treenodes->l_tail && hatom_gettype(&x->treenodes->l_tail->l_hatom) == H_OBJ) {
			t_treenode *lasttnd = (t_treenode *) hatom_getobj(&x->treenodes->l_tail->l_hatom);
			double needed_height = lasttnd->center_y + lasttnd->height / 2.;	
			double real_height = x->rect.height;
			if (needed_height > real_height) {
				double scrollbar_delta_y = x->scrollbar_pos * (needed_height - real_height);
				pixel_y_start += scrollbar_delta_y;
				pixel_y_end += scrollbar_delta_y;
			}
		}
		send_sym_doubles_notification((t_object *)x, 3, gensym("domainpixels"), 2, pixel_y_start, pixel_y_end);
	}
}

void tree_paint(t_tree *x, t_object *view){

	t_jgraphics *g;
	t_rect rect;
	t_jfont *jf_text = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
								 (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x));
	t_llllelem *elem;

	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(view); 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, view, &rect);
	
	x->rect = rect;
	
	if (x->need_rebuid_tree_nodes)
		rebuild_treenodes(x, rect);
		
	if (x->need_set_clicked_treenode_on_this) {
		t_llllelem *temp;
		for (temp = x->treenodes->l_head; temp; temp = temp->l_next){
			t_treenode *tempnode = (t_treenode *)hatom_getobj(&temp->l_hatom);
			if (tempnode->elem == x->need_set_clicked_treenode_on_this ||
				(!tempnode->elem && x->need_set_clicked_treenode_on_this == WHITENULL_llllelem)){
				x->clicked_node = tempnode;
				if (x->also_send_clicked_elem) {
					send_clicked_node_address_and_content(x);
					x->also_send_clicked_elem = false;
				}
				node_inscreenpos(x, rect, tempnode, 0.5, true, false);
				break;
			}
		}
		x->need_set_clicked_treenode_on_this = NULL;
	}
	
	if (x->treenodes) {
		if (x->mode == 1) {
			// OUTLINE MODE
			
			double scrollbar_delta_y = 0;
			if (x->treenodes->l_tail && hatom_gettype(&x->treenodes->l_tail->l_hatom) == H_OBJ) {
				t_treenode *lasttnd = (t_treenode *) hatom_getobj(&x->treenodes->l_tail->l_hatom);
				double needed_height = lasttnd->center_y + lasttnd->height / 2.;	
				double real_height = rect.height;
				if (needed_height > real_height)
					scrollbar_delta_y = x->scrollbar_pos * (needed_height - real_height);
			}
			
			const double triangle_width_factor = 0.3;
			double fontsize = jbox_get_fontsize((t_object *)x);
			double triangle_width = triangle_width_factor * fontsize;
			t_jfont *jf_text2 = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
												   (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), fontsize);
			long count = 0;
			
			for (elem = x->treenodes->l_head; elem; elem = elem->l_next, count++){
				if (hatom_gettype(&elem->l_hatom) == H_OBJ){
					t_treenode *tnd = (t_treenode *) hatom_getobj(&elem->l_hatom);
					double x1 = tnd->center_x - tnd->width/2.;
					double y1 = tnd->center_y - tnd->height / 2. - scrollbar_delta_y;
					double y_text = tnd->center_y - (tnd->height - x->row_vpad) / 2. - scrollbar_delta_y;
					
					char dont_paint_node = x->is_editing && tnd == x->clicked_node;
					
					if (tnd == x->clicked_node) 
						paint_filledrectangle(g, x->j_selected_strip_color, 0, y1, rect.width, tnd->height);
					else if (tnd == x->hovered_node) 
						paint_filledrectangle(g, x->j_hovered_strip_color, 0, y1, rect.width, tnd->height);
					else if (x->alternate_stripes){
						if (count % 2)
							paint_filledrectangle(g, x->j_alternate_bgcolor, 0, y1, rect.width, tnd->height);
					}

//					paint_line(g, get_grey(0.5), 0, tnd->center_y, 100, tnd->center_y, 1);
					
					if (tnd->show_triangle) 
						paint_small_triangle(x, g, x1 - fontsize + triangle_width * 0.8 - 0.1 * fontsize, tnd->center_y - scrollbar_delta_y, triangle_width, tnd->closed);

					if (tnd->text && !dont_paint_node) {
						if (x->textdecayfactor == 1.)
							write_text(g, jf_text2, tnd == x->clicked_node ? x->j_clickedtextcolor : (tnd == x->hovered_node ? x->j_hovered_text_color : x->j_textcolor), 
									   tnd->text, x1, y_text, rect.width, 3 * tnd->height, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
						else {
							t_jfont *jf_text2 = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
																   (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x) * pow(x->textdecayfactor, tnd->depth - 1));
							write_text(g, jf_text2, tnd == x->clicked_node ? x->j_clickedtextcolor : (tnd == x->hovered_node ? x->j_hovered_text_color : x->j_textcolor), 
									   tnd->text, x1, y_text, rect.width, 3 * tnd->height, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
							jfont_destroy_debug(jf_text2);
						}
					}

//					paint_line(g, build_jrgba(0.5, 0.5, 0.5, 0.5), 0, tnd->center_y, rect.width, tnd->center_y, 0.5);
				}
			}
			jfont_destroy_debug(jf_text2);
			
		} else {
			for (elem = x->treenodes->l_head; elem; elem = elem->l_next){
				if (hatom_gettype(&elem->l_hatom) == H_OBJ){
					t_treenode *tnd = (t_treenode *) hatom_getobj(&elem->l_hatom);
					double real_center_x, real_center_y, x1, y1, maxwidth, maxheight;
					
					char dont_paint_node = x->is_editing && tnd == x->clicked_node;

					real_center_x = x->x_inset + tnd->center_x * (rect.width - 2 * x->x_inset);
					real_center_y = x->y_inset + x->needed_y_inset + tnd->center_y * (rect.height - 2 * (x->y_inset + x->needed_y_inset));
					x1 = real_center_x - tnd->width / 2. + tnd->delta_x;
					y1 = real_center_y - tnd->height / 2. + tnd->delta_y;
					maxwidth = tnd->width + 10;
					maxheight = tnd->height + 10;
					
					if (!dont_paint_node) {
						if (x->enclosure)
							paint_rectangle(g, x->j_enclosurelinecolor, x->j_enclosurebackground, real_center_x - tnd->width/2., real_center_y - tnd->height/2., 
											tnd->width, tnd->height, 0.5);
						
						if (x->textdecayfactor == 1.)
							write_text_simple(g, jf_text, tnd == x->clicked_node ? x->j_clickedtextcolor : (tnd == x->hovered_node ? x->j_hovered_text_color : x->j_textcolor), tnd->text, x1, y1, maxwidth, maxheight);
						else {
							t_jfont *jf_text2 = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
																   (t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x) * pow(x->textdecayfactor, tnd->depth - 1));
							write_text_simple(g, jf_text2, tnd == x->clicked_node ? x->j_clickedtextcolor : (tnd == x->hovered_node ? x->j_hovered_text_color : x->j_textcolor), tnd->text, x1, y1, maxwidth, maxheight);
							jfont_destroy_debug(jf_text2);
						}
					}
					
					if (tnd->linktofather) {
						double xl1 = real_center_x;
						double yl1 = real_center_y - tnd->height / 2.;
						if (tnd->linktofather){
							double xl2 = x->x_inset + tnd->linktofather->center_x * (rect.width - 2 * x->x_inset) + tnd->linktofather->delta_x;
							double yl2 = (x->y_inset + x->needed_y_inset) + tnd->linktofather->center_y * (rect.height - 2 * (x->y_inset + x->needed_y_inset)) + tnd->linktofather->height/2. + tnd->linktofather->delta_y;
							if (tnd->is_dummy_node) {
								if (x->maxdepth == 0 || x->maxdepth == -1 || tnd->depth <= abs(x->maxdepth))
									paint_dashed_line(g, x->j_linecolor, xl1, yl1, xl2, yl2, x->j_linewidth, 3);
							} else 
								paint_line(g, x->j_linecolor, xl1, yl1, xl2, yl2, x->j_linewidth);
						}
					}
				}
			}
		}
	}
	
	if (x->mode == 1 && x->treenodes && x->treenodes->l_tail && hatom_gettype(&x->treenodes->l_tail->l_hatom) == H_OBJ) {
		t_treenode *tnd = (t_treenode *) hatom_getobj(&x->treenodes->l_tail->l_hatom);
		double needed_height = tnd->center_y+tnd->height / 2.;	
		double real_height = rect.height;
		if (needed_height > real_height) {	// scrollbar
			double zoom = 1;
			double vscrollbar_width = CONST_BACH_TREE_VSCROLLBAR_WIDTH * zoom;
			double vscrollbar_bg_width = 13 * zoom;
			double vscrollbar_height = MAX(CONST_BACH_TREE_VSCROLLBAR_MIN_UHEIGHT * zoom, (real_height - 4 * zoom) * (real_height / needed_height));
			double vscrollbar_top_y = CONST_BACH_TREE_UY_START_PAD * zoom + ((real_height - 4 * zoom) - vscrollbar_height) * x->scrollbar_pos;
			double right_distance_from_border = CONST_BACH_TREE_VSCROLLBAR_RIGHT_PAD * zoom;
			double x_innerdash = rect.width - vscrollbar_width - (vscrollbar_bg_width - vscrollbar_width)/2 - right_distance_from_border + 2 * zoom;
			double length_innerdash = vscrollbar_width - 4 * zoom;
			
			paint_rectangle_rounded(g, build_jrgba(0.5, 0.5, 0.5, 0.1), build_jrgba(1, 1, 1, 0.15), rect.width - vscrollbar_bg_width - right_distance_from_border, CONST_BACH_TREE_UY_START_PAD * zoom, vscrollbar_bg_width, rect.height - CONST_BACH_TREE_UY_START_PAD * zoom, 0.5, 2, 3);
			paint_rectangle_rounded(g, get_grey(0.2), get_grey(0.8), rect.width - vscrollbar_width - (vscrollbar_bg_width - vscrollbar_width)/2 - right_distance_from_border, vscrollbar_top_y, vscrollbar_width, vscrollbar_height, 0.5, 2, 3);
			paint_line(g, get_grey(0.3), x_innerdash, vscrollbar_top_y + vscrollbar_height / 2, x_innerdash + length_innerdash, vscrollbar_top_y + vscrollbar_height / 2, 0.5);
			paint_line(g, get_grey(0.3), x_innerdash, vscrollbar_top_y + vscrollbar_height / 2 - 2.5 * zoom, x_innerdash + length_innerdash, vscrollbar_top_y + vscrollbar_height / 2 - 2.5 * zoom, 0.5);
			paint_line(g, get_grey(0.3), x_innerdash, vscrollbar_top_y + vscrollbar_height / 2 + 2.5 * zoom, x_innerdash + length_innerdash, vscrollbar_top_y + vscrollbar_height / 2 + 2.5 * zoom, 0.5);
			
			x->scrollbar_height = vscrollbar_height;
			x->scrollbar_top_y = vscrollbar_top_y;
			x->show_scrollbar = true;
			x->scrollbar_delta_y = x->scrollbar_pos * (needed_height - real_height);
		} else {
			if (x->scrollbar_pos != 0)
				x->need_send_domainpixels = true;
			x->scrollbar_delta_y = 0;
			x->scrollbar_pos = 0;
			x->show_scrollbar = false;
		}
	} else if (x->mode == 1) {
		if (x->scrollbar_pos != 0)
			x->need_send_domainpixels = true;
		x->scrollbar_delta_y = 0;
		x->scrollbar_pos = 0;
		x->show_scrollbar = false;
	}

	if (x->need_send_changed_bang) {
		x->need_send_changed_bang = false;
		send_changed_bang(x);
	}
	
	if (x->need_send_domainpixels){
		send_domainpixels(x);
		x->need_send_domainpixels = false;
	}

	
	jfont_destroy_debug(jf_text);
}

void relative_centers_to_pixel_coordinates(t_tree *x, t_rect view_rect, double center_x, double center_y, double *pixel_center_x, double *pixel_center_y)
{
	*pixel_center_x = x->mode == 1 ? center_x : (x->x_inset + center_x * (view_rect.width - 2 * x->x_inset));
	*pixel_center_y = x->mode == 1 ? (center_y - x->scrollbar_delta_y) : ((x->y_inset + x->needed_y_inset) + center_y * (view_rect.height - 2 * (x->y_inset + x->needed_y_inset)));
}

t_treenode *pt_to_treenode(t_tree *x, t_pt pt, t_rect view_rect, char *clicked_arrow, char only_care_about_y){
	t_llllelem *elem;

	if (clicked_arrow)
		*clicked_arrow = false;

	if (x->treenodes) {
		for (elem = x->treenodes->l_head; elem; elem = elem->l_next){
			if (hatom_gettype(&elem->l_hatom) == H_OBJ){
				t_treenode *tnd = (t_treenode *) hatom_getobj(&elem->l_hatom);
				double real_center_x, real_center_y, dist_x, dist_y;
				
				relative_centers_to_pixel_coordinates(x, view_rect, tnd->center_x, tnd->center_y, &real_center_x, &real_center_y);
				dist_x = fabs(pt.x - real_center_x);
				dist_y = fabs(pt.y - real_center_y);

				if (x->mode == 0) {
					if (dist_x < tnd->width / 2. + 1 && dist_y < tnd->height / 2. + 1)
						return tnd;
				 } else if (x->mode == 1) {
					 if (dist_y < tnd->height / 2. + 1) {
						 if (only_care_about_y == 1) {
							// clicked element, and that's all
							if (clicked_arrow && tnd->show_triangle && pt.x < real_center_x - tnd->width / 2.)
								*clicked_arrow = true;
							return tnd;
						} else if (only_care_about_y == 0 && dist_x < tnd->width / 2. + 1) {
							return tnd;
						} else if (pt.x < real_center_x && tnd->show_triangle) {
							if (clicked_arrow) 
								*clicked_arrow = true;
							return tnd;
						}
					 }
				}
			}
		}
	}
	return NULL;
}


void tree_mousemove(t_tree *x, t_object *patcherview, t_pt pt, long modifiers) {
	if (x->clicked_on_scrollbar) {
		char must_redraw = false; 
		if (x->hovered_node != NULL)
			must_redraw = true;
		x->hovered_node = NULL;
		if (must_redraw)
			jbox_redraw((t_jbox *)x);
	} else {
		double zoom = 1;
		t_rect rect;
		jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);
		if (!(x->mode == 1 && x->show_scrollbar && 
			pt.x > rect.width - (CONST_BACH_TREE_VSCROLLBAR_RIGHT_PAD + CONST_BACH_TREE_VSCROLLBAR_WIDTH) * zoom &&
			pt.x < rect.width - CONST_BACH_TREE_VSCROLLBAR_RIGHT_PAD * zoom)) { // if the mouse is not on the scrollbar
			x->hovered_node = pt_to_treenode(x, pt, rect, NULL, true);
			
			 if (x->only_allow_click_on_leaves && x->hovered_node && x->hovered_node->elem && hatom_gettype(&x->hovered_node->elem->l_hatom) == H_LLLL) {
				// we only allow click on leaves!
				x->hovered_node = NULL;
			}
		}
		jbox_redraw((t_jbox *)x);
	}
}



void tree_mouseleave(t_tree *x, t_object *patcherview, t_pt pt, long modifiers) {
	x->hovered_node = NULL;
	jbox_redraw((t_jbox *)x);
}

void send_clicked_node_address_and_content(t_tree *x)
{
	t_treenode *the_clicked_node = x->clicked_node;
	
	// sending address
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 2, the_clicked_node->address);
	
	// sending content
	if (the_clicked_node->address->l_size == 0) {
		if (x->first_elem_in_llll_is_llll_name && x->output_llll_names_when_llll_clicked && x->tree_as_llll->l_head) {
			t_llll *outllll = llll_get();
			llll_appendhatom_clone(outllll, &x->tree_as_llll->l_head->l_hatom, 0, WHITENULL_llll);
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 1, outllll);
			llll_free(outllll);
		} else
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 1, x->tree_as_llll);
	} else {
		t_llll *babyllll = llll_get();
		t_llll *outllll = llll_get();
		llll_findchildren(x->tree_as_llll, the_clicked_node->address, 0, babyllll, NULL);
		if (babyllll->l_head && hatom_gettype(&babyllll->l_head->l_hatom) == H_OBJ) {
			t_llllelem *parentllllelem = (t_llllelem *)hatom_getobj(&babyllll->l_head->l_hatom);
			llll_appendhatom_clone(outllll, &parentllllelem->l_hatom, 0, WHITENULL_llll);
		} 
		if (x->first_elem_in_llll_is_llll_name && x->output_llll_names_when_llll_clicked && outllll->l_depth > 1 && outllll->l_size > 0) {
			t_llllelem *first_elem;
			llll_flat(outllll, 0, 1, 0, LLLL_FREETHING_DONT);
			first_elem = llll_getindex(outllll, 1, I_NON_NEGATIVE);
			llll_free(outllll);
			outllll = llll_get();
			llll_appendhatom_clone(outllll, &first_elem->l_hatom, 0, WHITENULL_llll);
		} else if (x->unwrap) {
			llll_flat(outllll, 0, 1, 0, LLLL_FREETHING_DONT);
		}
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 1, outllll);
		
		llll_free(outllll);
		llll_free(babyllll);
	}
}

void tree_mousedown(t_tree *x, t_object *patcherview, t_pt pt, long modifiers){
	// getting rectangle dimensions
	t_rect rect;
	t_treenode *the_clicked_node = NULL;
	char clicked_arrow = 0;
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);

	x->floatdragging_y = pt.y;
	
	// scrollbar ? 
	if (x->mode == 1 && x->show_scrollbar) {
		double zoom = 1;
		if (pt.x > rect.width - (CONST_BACH_TREE_VSCROLLBAR_RIGHT_PAD + CONST_BACH_TREE_VSCROLLBAR_WIDTH) * zoom &&
			pt.x < rect.width - CONST_BACH_TREE_VSCROLLBAR_RIGHT_PAD * zoom && 
			pt.y > x->scrollbar_top_y && pt.y < x->scrollbar_top_y + x->scrollbar_height) {
			x->clicked_on_scrollbar = true;
			return;
		}
	} 
	
	the_clicked_node = pt_to_treenode(x, pt, rect, &clicked_arrow, x->mode == 0 ? false : true);
	
	if ((the_clicked_node && !the_clicked_node->is_dummy_node && clicked_arrow) ||
		(x->only_allow_click_on_leaves && the_clicked_node && (!the_clicked_node->elem || (the_clicked_node->elem && hatom_gettype(&the_clicked_node->elem->l_hatom) == H_LLLL)))) {
		// opening or closing
		t_llllelem *el = the_clicked_node->elem;
		t_llll *ll = NULL;
		if (el && hatom_gettype(&el->l_hatom) == H_LLLL)
			ll = hatom_getllll(&el->l_hatom);
		else if (!el)
			ll = x->tree_as_llll;
			
		if (ll) {
			open_close_switch_llll(ll, 3);
			t_llll *clicked_node_address = x->clicked_node ? llll_clone(x->clicked_node->address) : NULL;

			// notifying open/close
			send_sym_lllls_notification((t_object *)x, 3, ll->l_leveltype == CLOSED_LEVEL_LEVELTYPE ? _sym_close : _sym_open, 1, the_clicked_node->address);
			
			// rebuilding nodes
			rebuild_treenodes(x, rect);

			if (clicked_node_address)
				click_on_node(x, clicked_node_address, false, false);

			if (clicked_node_address)
				llll_free(clicked_node_address);
			x->need_send_domainpixels = true;
		} 
	} else if (the_clicked_node && !the_clicked_node->is_dummy_node) {
		x->clicked_node = the_clicked_node;
		send_clicked_node_address_and_content(x);
	} else {
		x->clicked_node = the_clicked_node;
	}
	
	jbox_redraw((t_jbox *) x);
				
}


// use tnd = NULL to edit an empty llll
void start_editing_node(t_tree *x, t_treenode *tnd, t_object *patcherview)
{
	char		*text = NULL;
	t_object	*textfield = jbox_get_textfield((t_object*)x);
	t_rect		rect;
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);

	if (tnd) {
		double real_center_x, real_center_y;
		t_llll *temp_ll = llll_get();
		
		if (!tnd->elem) { // whole tree, but with firstelemisllllname
			if (x->first_elem_in_llll_is_llll_name && x->tree_as_llll->l_head) 
				llll_appendhatom_clone(temp_ll, &x->tree_as_llll->l_head->l_hatom, 0, WHITENULL_llll);
			else if (!x->first_elem_in_llll_is_llll_name)
				llll_clone_upon(x->tree_as_llll, temp_ll);
		} else {
			if (x->first_elem_in_llll_is_llll_name && hatom_gettype(&tnd->elem->l_hatom) == H_LLLL) {
				if (hatom_getllll(&tnd->elem->l_hatom)->l_head)
					llll_appendhatom_clone(temp_ll, &hatom_getllll(&tnd->elem->l_hatom)->l_head->l_hatom, 0, WHITENULL_llll);
			} else 
				llll_appendhatom_clone(temp_ll, &tnd->elem->l_hatom, 0, WHITENULL_llll);
		}
		llll_to_text_buf(temp_ll, &text, 0, BACH_DEFAULT_MAXDECIMALS, x->mode == 0 ? LLLL_T_ONLY_STANDARD_PARENTHESES : LLLL_T_NONE, NULL);
		llll_free(temp_ll);
		
		relative_centers_to_pixel_coordinates(x, rect, tnd->center_x, tnd->center_y, &real_center_x, &real_center_y);
		if (x->mode == 1) {  // outline mode
			textfield_set_textmargins(textfield, real_center_x - tnd->width / 2., real_center_y - (tnd->height - x->row_vpad) / 2., CONST_BACH_TREE_VSCROLLBAR_WIDTH + 2 * CONST_BACH_TREE_VSCROLLBAR_RIGHT_PAD, 0);
			textfield_set_justification(textfield, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP);
		} else {
			textfield_set_textmargins(textfield, 0, real_center_y - tnd->height / 2., rect.width - 2 * real_center_x, 0);
			textfield_set_justification(textfield, JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED);
		}
		
		x->is_editing = 1;
		object_method(patcherview, gensym("insertboxtext"), x, text);
		
		bach_freeptr(text);
	} else {
		// empty llll!
		x->is_editing = 1;
		text = (char *)bach_newptr(2 * sizeof(char));
		text[0] = 0;
		
		if (x->mode == 1) {  // outline mode
			textfield_set_textmargins(textfield, x->x_inset, x->y_inset, 0, 0);
			textfield_set_justification(textfield, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP);
		} else {
			textfield_set_textmargins(textfield, 0, 0, 0, 0);
			textfield_set_justification(textfield, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED);
		}
		
		object_method(patcherview, gensym("insertboxtext"), x, text);
		bach_freeptr(text);
	}
}

void tree_mousedoubleclick(t_tree *x, t_object *patcherview, t_pt pt, long modifiers) {

	systhread_mutex_lock(x->c_mutex);
	if (x->clicked_node && !x->prevent_edit)
		start_editing_node(x, x->clicked_node, patcherview);
	else if (!x->clicked_node && (!x->tree_as_llll || x->tree_as_llll->l_size == 0))
		start_editing_node(x, NULL, patcherview);
	
	systhread_mutex_unlock(x->c_mutex);
}


void tree_tab(t_tree *x, t_symbol *msg, long argc, t_atom *argv)
{
	t_llllelem *temp;
	for (temp = x->treenodes->l_head; temp; temp = temp->l_next) {
		t_treenode *this_node = (t_treenode *)hatom_getobj(&temp->l_hatom);
		t_llllelem *elem = (t_llllelem *)atom_getobj(argv + 1);
		if ((elem == WHITENULL_llllelem && this_node->depth == 0) || (elem != WHITENULL_llllelem && this_node->elem == elem)) {
			x->clicked_node = this_node;
			start_editing_node(x, this_node, (t_object *)atom_getobj(argv));
			break;
		}
	}
}

long tree_keyfilter(t_tree *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter)
{
	t_atom arv;
	long rv = 1;
	long k = *keycode;
	
	if (k == JKEY_TAB) {
		if (x->clicked_node && x->clicked_node->elem) {
			t_llllelem *next_elem = (*modifiers & eShiftKey) ?  get_prev_open_llllelem(x, x->clicked_node->elem, true) : get_next_open_llllelem(x, x->clicked_node->elem, true);
			object_method_typed(patcherview, gensym("endeditbox"), 0, NULL, &arv); 
			
			t_atom temp[2];
			atom_setobj(temp, patcherview);
			atom_setobj(temp+1, next_elem);
			defer_low(x, (method) tree_tab, NULL, 2, temp);
		}

		rv = 0;
	} else if (k == JKEY_ENTER || k == JKEY_RETURN) {
		object_method_typed(patcherview, gensym("endeditbox"), 0, NULL, &arv); 
		rv = 0;		// don't pass those keys to uitextfield
	}
	return rv;
}

void delete_tree_node(t_tree *x, t_treenode *tnd)
{
	if (tnd && tnd->elem)
	{
		llll_destroyelem(tnd->elem);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *) x);
	}
}

void rotate_tree_node(t_tree *x, t_treenode *tnd, t_atom_long amount)
{
	if (tnd && tnd->elem)
	{
		if (hatom_gettype(&tnd->elem->l_hatom) == H_LLLL) {
			t_llll *ll = hatom_getllll(&tnd->elem->l_hatom);
			llll_rot(ll, 0, 1, amount);
			x->need_rebuid_tree_nodes = true;
			jbox_redraw((t_jbox *) x);
		}
	}
}

void reverse_tree_node(t_tree *x, t_treenode *tnd)
{
	if (tnd && tnd->elem)
	{
		if (hatom_gettype(&tnd->elem->l_hatom) == H_LLLL) {
			llll_rev(hatom_getllll(&tnd->elem->l_hatom), 0, 1);
			x->need_rebuid_tree_nodes = true;
			jbox_redraw((t_jbox *) x);
		}
	}
}

void scramble_tree_node(t_tree *x, t_treenode *tnd)
{
	if (tnd && tnd->elem)
	{
		if (hatom_gettype(&tnd->elem->l_hatom) == H_LLLL) {
			llll_scramble(hatom_getllll(&tnd->elem->l_hatom), 0, 1);
			x->need_rebuid_tree_nodes = true;
			jbox_redraw((t_jbox *) x);
		}
	}
}

void wrap_tree_node(t_tree *x, t_treenode *tnd)
{
	if (tnd && tnd->elem)
	{
		t_llll *ll = llll_get();
		llll_appendhatom_clone(ll, &tnd->elem->l_hatom, 0, WHITENULL_llll);
		hatom_change_to_llll_and_free(&tnd->elem->l_hatom, ll);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *) x);
	}
}

void splatter_tree_node(t_tree *x, t_treenode *tnd)
{
	if (tnd && tnd->elem)
	{
		if (hatom_gettype(&tnd->elem->l_hatom) == H_LLLL) {
			llll_splatter(tnd->elem, LLLL_FREETHING_DONT);
			x->need_rebuid_tree_nodes = true;
			x->clicked_node = NULL;
			jbox_redraw((t_jbox *) x);
		}
	}
}

void duplicate_tree_node(t_tree *x, t_treenode *tnd)
{
	if (tnd && tnd->elem)
	{
		llll_inserthatom_after_clone(&tnd->elem->l_hatom, tnd->elem, 0, WHITENULL_llll);
		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *) x);
	}
}

long tree_key(t_tree *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
	llll_format_modifiers(&modifiers, &keycode);
	
	switch (keycode) {
		case JKEY_BACKSPACE:
			if (x->clicked_node && !x->prevent_edit) {
				systhread_mutex_lock(x->c_mutex);
				create_default_interface_undo_step(x);
				delete_tree_node(x, x->clicked_node); // redraw is here inside
				x->need_send_changed_bang = true;
				systhread_mutex_unlock(x->c_mutex);
			}
			return 1;
			break;
		case JKEY_ESC:
			if (x->clicked_node) {
				x->clicked_node = NULL;
				jbox_redraw((t_jbox *) x);
			}
			return 1;
			break;
		case JKEY_UPARROW:
		case JKEY_DOWNARROW:
			if (x->mode == 1 && x->clicked_node) {
				t_llll *temp = llll_get();
				llll_appendsym(temp, keycode == JKEY_UPARROW ? _llllobj_sym_prev : _llllobj_sym_next, 0, WHITENULL_llll);
				click_on_node(x, temp, true, modifiers & eShiftKey);
				llll_free(temp);
			}
			return 1;
			break;
		case JKEY_LEFTARROW:
			if (x->mode == 1 && x->clicked_node) {
				if (!x->clicked_node->elem) { // whole llll
					if (x->show_first_node) {
						send_sym_lllls_notification_and_free((t_object *)x, 3, _sym_close, 1, llll_get());
						open_close_switch_llll(x->tree_as_llll, 2);
						x->need_set_clicked_treenode_on_this = x->only_allow_click_on_leaves ? NULL : WHITENULL_llllelem;
						x->also_send_clicked_elem = true;
						x->need_send_domainpixels = true;
					}
				} else {
					if (hatom_gettype(&x->clicked_node->elem->l_hatom) == H_LLLL) {
						t_llll *ll = hatom_getllll(&x->clicked_node->elem->l_hatom);
						if (ll->l_leveltype == CLOSED_LEVEL_LEVELTYPE) {
							if (ll->l_owner && ll->l_owner->l_parent) {
								send_sym_lllls_notification_and_free((t_object *)x, 3, _sym_close, 1, llll_betail(llll_clone(x->clicked_node->address)));;
								open_close_switch_llll(ll->l_owner->l_parent, 2);
								x->need_send_domainpixels = true;
							}
							x->need_set_clicked_treenode_on_this = x->only_allow_click_on_leaves ? NULL : (ll->l_owner->l_parent->l_owner ? 
																										   ll->l_owner->l_parent->l_owner : WHITENULL_llllelem);
							x->also_send_clicked_elem = true;
						} else {
							send_sym_lllls_notification((t_object *)x, 3, _sym_close, 1, x->clicked_node->address);
							open_close_switch_llll(ll, 2);
							x->need_set_clicked_treenode_on_this = x->clicked_node->elem;
							x->also_send_clicked_elem = true;
							x->need_send_domainpixels = true;
						}
					} else if (x->clicked_node->elem->l_parent) {
						send_sym_lllls_notification_and_free((t_object *)x, 3, _sym_close, 1, llll_betail(llll_clone(x->clicked_node->address)));;
						open_close_switch_llll(x->clicked_node->elem->l_parent, 2);
						x->need_set_clicked_treenode_on_this = x->only_allow_click_on_leaves ? NULL : (x->clicked_node->elem->l_parent->l_owner ? 
																									   x->clicked_node->elem->l_parent->l_owner : WHITENULL_llllelem);
						x->also_send_clicked_elem = true;
						x->need_send_domainpixels = true;
					}
				}
				x->need_rebuid_tree_nodes = true;
				jbox_redraw((t_jbox *) x);
			}
			return 1;
			break;
		case JKEY_RIGHTARROW:
			if (x->mode == 1 && x->clicked_node) {
				if (!x->clicked_node->elem) { // whole llll
					send_sym_lllls_notification_and_free((t_object *)x, 3, _sym_open, 1, llll_get());
					open_close_switch_llll(x->tree_as_llll, 1);
					x->need_rebuid_tree_nodes = true;
					x->need_set_clicked_treenode_on_this = x->only_allow_click_on_leaves ? NULL : WHITENULL_llllelem;
					x->need_send_domainpixels = true;
					jbox_redraw((t_jbox *) x);
				} else if (hatom_gettype(&x->clicked_node->elem->l_hatom) == H_LLLL) {
					send_sym_lllls_notification((t_object *)x, 3, _sym_open, 1, x->clicked_node->address);
					open_close_switch_llll(hatom_getllll(&x->clicked_node->elem->l_hatom), 1);
					x->need_rebuid_tree_nodes = true;
					x->need_send_domainpixels = true;
					x->need_set_clicked_treenode_on_this = x->only_allow_click_on_leaves ? NULL : x->clicked_node->elem;
					jbox_redraw((t_jbox *) x);
				}
			}
			return 1;
			break;
		case 'r':
		case 't':
			if (x->clicked_node && !x->prevent_edit) {
				if (modifiers & eCommandKey) {
					systhread_mutex_lock(x->c_mutex);
					create_default_interface_undo_step(x);
					rotate_tree_node(x, x->clicked_node, keycode == 'r' ? 1 : -1); // redraw is here inside
					x->need_send_changed_bang = true;
					systhread_mutex_unlock(x->c_mutex);
				}
			}
			return 1;
		case 'i':
			if (x->clicked_node && !x->prevent_edit) {
				if (modifiers & eCommandKey) {
					systhread_mutex_lock(x->c_mutex);
					create_default_interface_undo_step(x);
					reverse_tree_node(x, x->clicked_node); // redraw is here inside
					x->need_send_changed_bang = true;
					systhread_mutex_unlock(x->c_mutex);
				}
			}
			return 1;
		case 'y':
			if (x->clicked_node && !x->prevent_edit) {
				if (modifiers & eCommandKey) {
					systhread_mutex_lock(x->c_mutex);
					create_default_interface_undo_step(x);
					scramble_tree_node(x, x->clicked_node); // redraw is here inside
					x->need_send_changed_bang = true;
					systhread_mutex_unlock(x->c_mutex);
				}
			}
			return 1;
		case 'p':
			if (x->clicked_node && !x->prevent_edit) {
				if (modifiers & eCommandKey) {
					systhread_mutex_lock(x->c_mutex);
					create_default_interface_undo_step(x);
					if (modifiers & eShiftKey)
						splatter_tree_node(x, x->clicked_node);
					else
						wrap_tree_node(x, x->clicked_node); // redraw is here inside
					x->need_send_changed_bang = true;
					systhread_mutex_unlock(x->c_mutex);
				}
			}
			return 1;
		case 'c':
		case 'x':
			if (x->clicked_node && !x->prevent_edit) {
				if (modifiers & eCommandKey) {
					systhread_mutex_lock(x->c_mutex);
					if (x->clicked_node->elem) {
						// copy node
						if (clipboard_llll)
							llll_free(clipboard_llll);
						clipboard_llll = llll_get();
						llll_appendhatom_clone(clipboard_llll, &x->clicked_node->elem->l_hatom, 0, WHITENULL_llll);
						if (keycode == 'x') {
							create_default_interface_undo_step(x);
							delete_tree_node(x, x->clicked_node);
						}
					}
					systhread_mutex_unlock(x->c_mutex);
				}
			}
			return 1;
		case 'v':
			if (x->clicked_node && !x->prevent_edit) {
				if (modifiers & eCommandKey) {
					systhread_mutex_lock(x->c_mutex);
					if (clipboard_llll && x->clicked_node->elem) {
						// paste node
						create_default_interface_undo_step(x);
						hatom_change_to_llll_and_free(&x->clicked_node->elem->l_hatom, llll_clone(clipboard_llll));
						t_llllelem *new_clicked_node_elem = hatom_getllll(&x->clicked_node->elem->l_hatom)->l_head;
						llll_splatter(x->clicked_node->elem, LLLL_FREETHING_DONT);
						x->clicked_node->elem = new_clicked_node_elem;
						x->need_send_changed_bang = true;
						x->need_rebuid_tree_nodes = true;
						jbox_redraw((t_jbox *) x);
					}
					systhread_mutex_unlock(x->c_mutex);
				}
			}
			return 1;
		case 'd':
			if (modifiers & eCommandKey) {
				if (modifiers & eShiftKey) {
					tree_dump(x);
				} else {
					if (x->clicked_node && !x->prevent_edit) {
						if (modifiers & eCommandKey) {
							systhread_mutex_lock(x->c_mutex);
							create_default_interface_undo_step(x);
							duplicate_tree_node(x, x->clicked_node); // redraw is here inside
							x->need_send_changed_bang = true;
							systhread_mutex_unlock(x->c_mutex);
						}
					}
				}
			}
			return 1;
		case 'z':
			if (modifiers & eCommandKey && !x->prevent_edit) 
				if (modifiers & eShiftKey)
					tree_redo(x);
				else
					tree_undo(x);
			return 1;
	}
	
	return 0;
}




void tree_enter(t_tree *x)	// enter is triggerd at "endeditbox time"
{
	long size	= 0;
	char *text	= NULL;
	t_object *textfield = jbox_get_textfield((t_object *)x);
	 
	x->is_editing = 0;
	object_method(textfield, gensym("gettextptr"), &text, &size);
	if (size) {
		
//		dev_post("This is the new text: %s", text);
		t_llll *this_ll = llll_from_text_buf(text, true);
		
		if (this_ll) { 
			t_llllelem *new_clicked_node_elem = NULL;
			if (x->clicked_node) {
				
				systhread_mutex_lock(x->c_mutex);

				create_default_interface_undo_step(x);
				
				if (!x->clicked_node->elem) { // whole tree, but with firstelemisllllname
					if (x->first_elem_in_llll_is_llll_name) {
						if (!x->tree_as_llll->l_head) 
							llll_appendlong(x->tree_as_llll, 0, 0, WHITENULL_llll); // dummy
						hatom_change_to_llll_and_free(&x->tree_as_llll->l_head->l_hatom, this_ll);
						new_clicked_node_elem = hatom_getllll(&x->tree_as_llll->l_head->l_hatom)->l_head;
						llll_splatter(x->tree_as_llll->l_head, LLLL_FREETHING_DONT);
					} else {
						llll_clear(x->tree_as_llll);
						llll_chain(x->tree_as_llll, this_ll);
					}
				} else {
					if (x->first_elem_in_llll_is_llll_name && hatom_gettype(&x->clicked_node->elem->l_hatom) == H_LLLL) {
						t_llll *ll = hatom_getllll(&x->clicked_node->elem->l_hatom);
						if (!ll->l_head)
							llll_appendlong(ll, 0, 0, WHITENULL_llll); /// dummy
						hatom_change_to_llll_and_free(&ll->l_head->l_hatom, this_ll);
						new_clicked_node_elem = hatom_getllll(&ll->l_head->l_hatom)->l_head;
						llll_splatter(ll->l_head, LLLL_FREETHING_DONT);
					} else {
						hatom_change_to_llll_and_free(&x->clicked_node->elem->l_hatom, this_ll);
						new_clicked_node_elem = hatom_getllll(&x->clicked_node->elem->l_hatom)->l_head;
						llll_splatter(x->clicked_node->elem, LLLL_FREETHING_DONT);
					}
				}
				x->clicked_node->elem = new_clicked_node_elem;
				x->need_rebuid_tree_nodes = true;
				x->need_send_changed_bang = true;
				systhread_mutex_unlock(x->c_mutex);
				
				jbox_redraw((t_jbox *) x);
			} else {
				// whole tree
				systhread_mutex_lock(x->c_mutex);
				create_default_interface_undo_step(x);
				
				if (x->first_elem_in_llll_is_llll_name) {
					if (!x->tree_as_llll->l_head) 
						llll_appendlong(x->tree_as_llll, 0, 0, WHITENULL_llll); // dummy
					hatom_change_to_llll_and_free(&x->tree_as_llll->l_head->l_hatom, this_ll);
					new_clicked_node_elem = hatom_getllll(&x->tree_as_llll->l_head->l_hatom)->l_head;
					llll_splatter(x->clicked_node->elem, LLLL_FREETHING_DONT);
				} else {
					llll_clear(x->tree_as_llll);
					llll_chain(x->tree_as_llll, this_ll);
				}
				
				x->need_rebuid_tree_nodes = true;
				x->need_send_changed_bang = true;
				systhread_mutex_unlock(x->c_mutex);
				
				jbox_redraw((t_jbox *) x);
			}
		} else {
			object_error((t_object *)x, "Wrong llll introduced!");
		}
	}
		
	object_method(textfield, _sym_settext, "");
}

void tree_mouseup(t_tree *x, t_object *patcherview, t_pt pt, long modifiers){
	if (x->clicked_on_scrollbar) // remove mousedown flag!
		x->clicked_on_scrollbar = false;
}

void tree_mousewheel(t_tree *x, t_object *patcherview, t_pt pt, long modifiers, double x_inc, double y_inc)
{
	if (x->show_scrollbar) {
		if (pt.y >= CONST_BACH_TREE_UY_START_PAD) {
			x->scrollbar_pos -= y_inc/5;
			x->scrollbar_pos = CLAMP(x->scrollbar_pos, 0, 1);
			send_domainpixels(x);
			jbox_redraw((t_jbox *)x);
		}
	}
}	

double scrollbar_pos_to_scrollbar_top_y(t_tree *x, double scrollbar_pos, double object_real_height)
{
	double zoom = 1;
	return CONST_BACH_TREE_UY_START_PAD * zoom + ((object_real_height - 4 * zoom) - x->scrollbar_height) * scrollbar_pos;
}

double scrollbar_top_y_to_scrollbar_pos(t_tree *x, double scrollbar_top_y, double object_real_height)
{
	double zoom = 1;
	return CLAMP((scrollbar_top_y - CONST_BACH_TREE_UY_START_PAD * zoom)/((object_real_height - 4 * zoom) - x->scrollbar_height), 0., 1.);
}


// pos is between 0 and 1
void node_inscreenpos(t_tree *x, t_rect rect, t_treenode *tnd, double pos, char only_change_if_not_inscreen, char also_redraw)
{
	if (!x->treenodes->l_tail)
		return;

	// 0 -> rect.height - x->scrollbar_height
	t_treenode *lasttnd = (t_treenode *) hatom_getobj(&x->treenodes->l_tail->l_hatom);
		
	if (only_change_if_not_inscreen && (tnd->center_y - tnd->height/2. >= x->scrollbar_delta_y)
		&& (tnd->center_y + tnd->height/2. <= rect.height + x->scrollbar_delta_y))
		return;
		
	double needed_height = lasttnd->center_y+lasttnd->height / 2.;	
	double val = (tnd->center_y - tnd->height/2. - pos * (rect.height - tnd->height))/(needed_height - rect.height);
	x->scrollbar_pos = CLAMP(val, 0., 1.);	
	send_domainpixels(x);
	if (also_redraw)
		jbox_redraw((t_jbox *)x);
}

void tree_mousedrag(t_tree *x, t_object *patcherview, t_pt pt, long modifiers){

	if (x->mode == 1 && x->clicked_on_scrollbar && x->treenodes->l_tail && hatom_gettype(&x->treenodes->l_tail->l_hatom) == H_OBJ) {
		t_rect rect;
		double zoom = 1;
		jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);
		double real_height = rect.height - CONST_BACH_TREE_UY_START_PAD * zoom;
			
		double vscrollbar_top_y = scrollbar_pos_to_scrollbar_top_y(x, x->scrollbar_pos, real_height);
		vscrollbar_top_y += pt.y - x->floatdragging_y;
		x->scrollbar_pos = scrollbar_top_y_to_scrollbar_pos(x, vscrollbar_top_y, real_height);
		send_domainpixels(x);
		jbox_redraw((t_jbox *)x);
	}
	x->floatdragging_y = pt.y;
}


t_llll *get_outermost_closed_level(t_tree *x, t_llllelem *elem)
{
	t_llll *ans = NULL;
	while (elem && elem->l_parent) {
		if ((x->show_first_node || (!x->show_first_node && elem->l_parent->l_owner)) &&
			elem->l_parent->l_leveltype == CLOSED_LEVEL_LEVELTYPE)
			ans = elem->l_parent;
		elem = elem->l_parent->l_owner;
	}
	return ans;
}

t_llllelem *get_next_open_llllelem(t_tree *x, t_llllelem *elem, char force_open_levels)
{
	t_llllelem *temp = NULL;

	if (!elem) { // whole llll
		if (x->tree_as_llll->l_leveltype == CLOSED_LEVEL_LEVELTYPE)
			temp = force_open_levels ? x->tree_as_llll->l_head : NULL;
		else
			temp = x->tree_as_llll->l_head;
		if (temp && x->first_elem_in_llll_is_llll_name)
			temp = temp->l_next;
	} else {
		t_llll *outermost_closed_level = get_outermost_closed_level(x, elem);
		t_llll *ll;
		if (hatom_gettype(&elem->l_hatom) == H_LLLL && !x->first_elem_in_llll_is_llll_name && hatom_getllll(&elem->l_hatom)->l_head)
			temp = hatom_getllll(&elem->l_hatom)->l_head;
		else if (hatom_gettype(&elem->l_hatom) == H_LLLL && x->first_elem_in_llll_is_llll_name && 
				 ((ll = hatom_getllll(&elem->l_hatom))->l_head && ll->l_head->l_next && (ll->l_leveltype != CLOSED_LEVEL_LEVELTYPE || force_open_levels)))
			temp = hatom_getllll(&elem->l_hatom)->l_head->l_next;
		else {
			if (outermost_closed_level) 
				elem = outermost_closed_level->l_owner;
			while (elem && elem->l_parent && !elem->l_next)
				elem = elem->l_parent->l_owner;
			if (!elem || !elem->l_next)
				return NULL;
			temp = elem->l_next;
		}
	}
	
//	if (!x->only_allow_click_on_leaves)
//		return elem->l_next;
	
	while (temp && hatom_gettype(&temp->l_hatom) == H_LLLL) {
		t_llll *ll = hatom_getllll(&temp->l_hatom);
		if (!x->only_allow_click_on_leaves)
			return temp;
		
		if (ll->l_leveltype == CLOSED_LEVEL_LEVELTYPE && !force_open_levels) {
			if (temp->l_next)
				temp = temp->l_next;
			else if (temp->l_parent && temp->l_parent->l_owner)
				temp = temp->l_parent->l_owner->l_next;
			else
				return NULL;
		} else {
			if (!x->first_elem_in_llll_is_llll_name && ll->l_head)
				temp = ll->l_head;
			else if (x->first_elem_in_llll_is_llll_name && ll->l_head && ll->l_head->l_next)
				temp = ll->l_head->l_next;
			else if (temp->l_parent && temp->l_parent->l_owner)
				temp = temp->l_parent->l_owner->l_next;
			else
				return NULL;
		}
	}
	return temp;
}

t_llllelem *get_prev_open_llllelem(t_tree *x, t_llllelem *elem, char force_open_levels)
{
	t_llll *outermost_closed_level = get_outermost_closed_level(x, elem);

	if (outermost_closed_level)
		elem = outermost_closed_level->l_owner;
	
	while (elem && elem->l_parent && 
		(((x->first_elem_in_llll_is_llll_name && x->only_allow_click_on_leaves) && (elem->l_parent->l_owner || x->show_first_node) && (!elem->l_prev || !elem->l_prev->l_prev))
		|| (!(x->first_elem_in_llll_is_llll_name && x->only_allow_click_on_leaves) && !elem->l_prev)))
		elem = elem->l_parent->l_owner;
	
	if (!elem || (((x->first_elem_in_llll_is_llll_name && x->only_allow_click_on_leaves) && (elem->l_parent->l_owner || x->show_first_node) &&(!elem->l_prev || !elem->l_prev->l_prev))
		|| (!(x->first_elem_in_llll_is_llll_name && x->only_allow_click_on_leaves) && !elem->l_prev)))
		return NULL;
		
/*	if (!x->only_allow_click_on_leaves) {
		if (hatom_gettype(&elem->l_prev->l_hatom) == H_LLLL)
		return elem->l_prev->l_prev ? elem->l_prev : elem->l_parent->l_owner;
	}
*/	
	t_llllelem *temp = elem->l_prev;
	while (temp && hatom_gettype(&temp->l_hatom) == H_LLLL) {
		t_llll *ll = hatom_getllll(&temp->l_hatom);

		if (ll->l_leveltype == CLOSED_LEVEL_LEVELTYPE && !force_open_levels) {
			if (!x->only_allow_click_on_leaves) {
				return temp;
			} else if (temp->l_prev) {
				if (x->first_elem_in_llll_is_llll_name && !temp->l_prev->l_prev) {
					if (temp->l_parent->l_owner)
						temp = temp->l_parent->l_owner->l_prev;
					else
						return NULL;
				} else
					temp = temp->l_prev;
			} else if (temp->l_parent && temp->l_parent->l_owner)
				temp = temp->l_parent->l_owner->l_prev;
			else
				return NULL;
		} else {
			if (!x->only_allow_click_on_leaves && ll->l_tail)
				temp = ll->l_tail;
			else if (!x->first_elem_in_llll_is_llll_name && ll->l_tail)
				temp = ll->l_tail;
			else if (x->first_elem_in_llll_is_llll_name && ll->l_tail && ll->l_tail->l_prev)
				temp = ll->l_tail;
			else if (temp->l_parent && temp->l_parent->l_owner)
				temp = temp->l_parent->l_owner->l_prev;
			else
				return NULL;
		}
	}
	
	if (temp && !x->only_allow_click_on_leaves && x->first_elem_in_llll_is_llll_name && !temp->l_prev && temp->l_parent)
		return temp->l_parent->l_owner ? temp->l_parent->l_owner : WHITENULL_llllelem;
	else
		return temp;
}


// fromwhat = 0 : interface, fromwhat = 1 : we're creating this event because we have just undone/redone
void create_undo_redo_step(t_tree *x, char what, char from_what, t_llll *content, char lock_mutex)
{
	if (lock_mutex)
		systhread_mutex_lock(x->c_mutex);	

	if (what == k_UNDO && from_what == 0 && x->redo_llll->l_size > 0)
		llll_clear(x->redo_llll);
	
	llll_prependllll(what == k_UNDO ? x->undo_llll : x->redo_llll, content, 0, WHITENULL_llll);

	if (what == k_UNDO && atom_gettype(&x->max_undo_steps) == A_LONG && x->undo_llll->l_size > atom_getlong(&x->max_undo_steps))
		llll_free(llll_slice(x->undo_llll, atom_getlong(&x->max_undo_steps)));
	
	if (lock_mutex)
		systhread_mutex_unlock(x->c_mutex);	
}


void create_default_interface_undo_step(t_tree *x)
{
	if (x->tree_as_llll)
		create_undo_redo_step(x, k_UNDO, 0, llll_clone(x->tree_as_llll), true);
}


// what = -1 -> undo, what = 1 -> redo
void tree_undo_redo(t_tree *x, char what){
	t_llll *llll = NULL;
	t_treenode *clicked_node;
	t_llll *clicked_node_address;
	
	systhread_mutex_lock(x->c_mutex);	

	clicked_node = x->clicked_node;
	clicked_node_address = x->clicked_node ? x->clicked_node->address : NULL;

	if (what == k_UNDO)
		llll = x->undo_llll;
	else if (what == k_REDO)
		llll = x->redo_llll;
	
	if (!llll) {
		systhread_mutex_unlock(x->c_mutex);	
		return;
	}
	
	if (x->verbose_undo_redo) 
		object_post((t_object *) x, "%s llll modification", what == k_UNDO ? "Undo" : "Redo");
	
	if (llll->l_head){
		create_undo_redo_step(x, -what, 1, llll_clone(x->tree_as_llll), false);

		llll_free(x->tree_as_llll);
		x->tree_as_llll = llll_clone(hatom_getllll(&llll->l_head->l_hatom));
		llll_destroyelem(llll->l_head);
		
		if (clicked_node && clicked_node_address) 
			x->need_set_clicked_treenode_on_this = llll_nth_one(x->tree_as_llll, clicked_node_address);

		x->need_rebuid_tree_nodes = true;
		jbox_redraw((t_jbox *)x);

		systhread_mutex_unlock(x->c_mutex);	
		send_changed_bang(x);

	} else {
		systhread_mutex_unlock(x->c_mutex);	
		object_warn((t_object *)x, what == k_UNDO ? "Can't undo!" : "Can't redo");
	}
}

void tree_undo(t_tree *x)
{
	tree_undo_redo(x, k_UNDO);
}

void tree_redo(t_tree *x)
{
	tree_undo_redo(x, k_REDO);
}

void send_changed_bang(t_tree *x)
{
	llllobj_outlet_bang((t_object *)x, LLLL_OBJ_UI, 4);
}