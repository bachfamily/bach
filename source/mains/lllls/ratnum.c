/*
 *  ratnum.c
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
	ratnum.c
	
	@name 
	bach.ratnum
	
	@realname 
	bach.ratnum

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Display and output rational numbers
	
	@description
	Displays, inputs, and outputs rational numbers.
	
	@discussion
	Since rational numbers are not a Max default supported type, 
	the output is by default an llll containing the rational number.
	
	@category
	bach, bach objects, bach math, bach interface, U/I
	
	@keywords
	display, rational, number, edit

	@palette
	YES
	
	@palette category
	bach, bach objects, bach math, bach interface

	@seealso
	number, flonum, bach.expr
	
	@owner
	Daniele Ghisi
*/

#include "llllobj.h"
#include "llll_math.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include "ext_strings.h"
#include "bach_graphics.h"
#include "ext_boxstyle.h"

#define CONST_MAXDEN_FOR_DOUBLE_TO_RAT_APPROXIMATION 10000
#define	CONST_RATNUM_Y_DRAGGING_MULTIPLIER 0.1

typedef struct _ratnum // [bach.ratnum] structure
{
	t_llllobj_jbox			j_box; // root object

	t_jrgba					j_textcolor;
	t_jrgba					j_bgcolor;
	t_jrgba					j_tricolor;
	t_jrgba					j_htricolor;
	t_jrgba					j_bordercolor;
	
	char					j_hasbeendragged;
	
	t_rational				r_value; // value	
	
	double					triangle_scale_factor;

	char					def_min; // is min defined?
	char					def_max; // is max defined?
	t_symbol				*r_min_sym; // min as symbol	
	t_symbol				*r_max_sym; // max as symbol	
	t_rational				r_min; // min value	
	t_rational				r_max; // max value	

	t_pt					j_mousedrag_pt;
	char					dragging_obj;
	double					dragging_val;

	char					rebuild; 
	char					j_has_focus; 
	char					itsme;
	char					changing_size;
	char					output_mode; 
	char					autoreduce;
	char					show_triangle; // show/hide triangle	
	double					zoom_y;	// zoom y, w.r. to the original object

	t_systhread_mutex		c_mutex;

} t_ratnum;


// global class pointer variable
t_class	*s_ratnum_class = NULL;

// functions
void ratnum_inletinfo(t_ratnum *x, void *b, long a, char *t);
void ratnum_assist(t_ratnum *x, void *b, long m, long a, char *s);

void ratnum_free(t_ratnum *x);
void ratnum_select(t_ratnum *x);
void ratnum_doselect(t_ratnum *x);

void update_screen(t_ratnum *x);

long ratnum_key(t_ratnum *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);
long ratnum_keyfilter(t_ratnum *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter);
void ratnum_focusgained(t_ratnum *x, t_object *patcherview);
void ratnum_focuslost(t_ratnum *x, t_object *patcherview);
void ratnum_enter(t_ratnum *x);
long ratnum_oksize(t_ratnum *x, t_rect *newrect);

void ratnum_mousedown(t_ratnum *x, t_object *patcherview, t_pt pt, long modifiers);
void ratnum_mouseup(t_ratnum *x, t_object *patcherview, t_pt pt, long modifiers);
void ratnum_mousedrag(t_ratnum *x, t_object *patcherview, t_pt pt, long modifiers);

t_ratnum* ratnum_new(t_symbol *s, long argc, t_atom *argv);

void ratnum_paint(t_ratnum *x, t_object *view);

void ratnum_anything(t_ratnum *x, t_symbol *s, long argc, t_atom *argv);
void ratnum_int(t_ratnum *x, t_atom_long num);
void ratnum_float(t_ratnum *x, double num);
void ratnum_bang(t_ratnum *x);

// setters for min and max
t_max_err ratnum_setattr_minimum(t_ratnum *x, t_object *attr, long ac, t_atom *av);
t_max_err ratnum_setattr_maximum(t_ratnum *x, t_object *attr, long ac, t_atom *av);
t_max_err ratnum_setattr_outputmode(t_ratnum *x, t_object *attr, long ac, t_atom *av);
t_max_err ratnum_setattr_autoreduce(t_ratnum *x, t_object *attr, long ac, t_atom *av);
t_max_err ratnum_setattr_triangle(t_ratnum *x, t_object *attr, long ac, t_atom *av);
t_max_err ratnum_setattr_triscale(t_ratnum *x, t_object *attr, long ac, t_atom *av);

// other functions
t_max_err set_minimum_from_ac_av(t_ratnum *x, long ac, t_atom *av);
t_max_err set_maximum_from_ac_av(t_ratnum *x, long ac, t_atom *av);
void gunload_ratllll(t_ratnum *x);
void refresh_text_margins(t_ratnum *x);
void check_min_max(t_ratnum *x);

t_max_err ratnum_setattr_outputmode(t_ratnum *x, t_object *attr, long ac, t_atom *av){
	x->output_mode = (ac && av && (atom_getlong(av) > 0)) ? 1 : 0; 
	if (!x->itsme)
		gunload_ratllll(x);
	return MAX_ERR_NONE;
}

t_max_err ratnum_setattr_autoreduce(t_ratnum *x, t_object *attr, long ac, t_atom *av){
	x->autoreduce = (ac && av && (atom_getlong(av) > 0)) ? 1 : 0; 
	if (x->autoreduce && !x->itsme) {
		rat_reduce(&x->r_value);
		check_min_max(x);
		gunload_ratllll(x);
		update_screen(x);
	}
	return MAX_ERR_NONE;
}

t_max_err ratnum_setattr_triscale(t_ratnum *x, t_object *attr, long ac, t_atom *av){
	double scale_factor = atom_getfloat(av);
	x->triangle_scale_factor = (ac && av && (scale_factor >= 0.)) ? scale_factor : 1.; 
	refresh_text_margins(x);
	return MAX_ERR_NONE;
}

t_max_err ratnum_setattr_triangle(t_ratnum *x, t_object *attr, long ac, t_atom *av){
	x->show_triangle = (ac && av && (atom_getlong(av) > 0)) ? 1 : 0;
	refresh_text_margins(x);
	return MAX_ERR_NONE;
}

void refresh_text_margins(t_ratnum *x){ 
	t_object *textfield = jbox_get_textfield((t_object *) x);
	double x_margin;
	if (!x->show_triangle)
		x_margin = 3;
	else
		x_margin = 5 + 6 * x->triangle_scale_factor; 
	textfield_set_textmargins(textfield, x_margin, 4, 3, 4);
}

t_max_err ratnum_setattr_minimum(t_ratnum *x, t_object *attr, long ac, t_atom *av){
	return set_minimum_from_ac_av(x, ac, av);
}

t_max_err set_minimum_from_ac_av(t_ratnum *x, long ac, t_atom *av){

	if (ac && av) {
		t_llll *attributes_as_list = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
		if (attributes_as_list && (attributes_as_list->l_size >= 1) && (hatom_gettype(&attributes_as_list->l_head->l_hatom) == H_RAT)) {
			x->r_min = hatom_getrational(&attributes_as_list->l_head->l_hatom);
			x->def_min = true;
		} else if (attributes_as_list && (attributes_as_list->l_size >= 1) && (hatom_gettype(&attributes_as_list->l_head->l_hatom) == H_LONG)) {
			x->r_min = genrat(hatom_getlong(&attributes_as_list->l_head->l_hatom), 1);
			x->def_min = true;
		} else if (attributes_as_list && (attributes_as_list->l_size >= 1) && (hatom_gettype(&attributes_as_list->l_head->l_hatom) == H_DOUBLE)) {
			x->r_min = approx_double_with_rat_fixed_den(hatom_getdouble(&attributes_as_list->l_head->l_hatom), CONST_MAXDEN_FOR_DOUBLE_TO_RAT_APPROXIMATION, 0, NULL);
			x->def_min = true;
		} else {
			x->def_min = false;
			// should I free the pointer before assigning the new value?
			x->r_min_sym = _sym_none;
		}
		
		if (x->def_min) {
			t_atom *dep_av = NULL;
			long dep_ac;
			if ((x->def_max) && (rat_rat_cmp(x->r_min, x->r_max) > 0))
				x->r_min = x->r_max;
			
			hatom_setrational(&attributes_as_list->l_head->l_hatom, x->r_min);
			// should I free the pointer before assigning the new value?
			dep_ac = llll_deparse(attributes_as_list, &dep_av, 0, 1);
			if (dep_ac && dep_av) x->r_min_sym = atom_getsym(dep_av);
			if (dep_av) bach_freeptr(dep_av);
		}
		if (attributes_as_list) llll_free(attributes_as_list);
	}
	check_min_max(x);
	jbox_redraw((t_jbox *) x);
	return MAX_ERR_NONE;
	
}

t_max_err ratnum_setattr_maximum(t_ratnum *x, t_object *attr, long ac, t_atom *av){
	return set_maximum_from_ac_av(x, ac, av);
}

t_max_err set_maximum_from_ac_av(t_ratnum *x, long ac, t_atom *av){
	
	if (ac && av) {
		t_llll *attributes_as_list = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
		if (attributes_as_list && (attributes_as_list->l_size >= 1) && (hatom_gettype(&attributes_as_list->l_head->l_hatom) == H_RAT)) {
			x->r_max = hatom_getrational(&attributes_as_list->l_head->l_hatom);
			x->def_max = true;
		} else if (attributes_as_list && (attributes_as_list->l_size >= 1) && (hatom_gettype(&attributes_as_list->l_head->l_hatom) == H_LONG)) {
			x->r_max = genrat(hatom_getlong(&attributes_as_list->l_head->l_hatom), 1);
			x->def_max = true;
		} else if (attributes_as_list && (attributes_as_list->l_size >= 1) && (hatom_gettype(&attributes_as_list->l_head->l_hatom) == H_DOUBLE)) {
			x->r_max = approx_double_with_rat_fixed_den(hatom_getdouble(&attributes_as_list->l_head->l_hatom), CONST_MAXDEN_FOR_DOUBLE_TO_RAT_APPROXIMATION, 0, NULL);
			x->def_max = true;
		} else {
			x->def_max = false;
			// should I free the pointer before assigning the new value?
			x->r_max_sym = _sym_none;
		}
		
		if (x->def_max) {
			t_atom *dep_av = NULL;
			long dep_ac;
			if ((x->def_min) && (rat_rat_cmp(x->r_min, x->r_max) > 0))
				x->r_max = x->r_min;
			
			hatom_setrational(&attributes_as_list->l_head->l_hatom, x->r_max);
			// should I free the pointer before assigning the new value?
			dep_ac = llll_deparse(attributes_as_list, &dep_av, 0, 1);
			if (dep_ac && dep_av) x->r_max_sym = atom_getsym(dep_av);
			if (dep_av) bach_freeptr(dep_av);
		}
		if (attributes_as_list) llll_free(attributes_as_list);
	}
	check_min_max(x);
	jbox_redraw((t_jbox *) x);
	return MAX_ERR_NONE;
}

void ratnum_reduce(t_ratnum *x) {
	rat_reduce(&x->r_value);
	check_min_max(x);
	gunload_ratllll(x);	
	update_screen(x);
	ratnum_bang(x);
}


void ratnum_bang(t_ratnum *x)
{
	if (x->j_box.l_rebuild == 1)
		ratnum_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_UI, 0);
}


void ratnum_preset(t_ratnum *x){
     preset_store((char *)"ossll", x, ob_sym(x), _sym_list, x->r_value.r_num, x->r_value.r_den);	
}


int T_EXPORT main(void){
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.ratnum", 
						(method)ratnum_new,
						(method)ratnum_free,
						sizeof(t_ratnum),
						(method)NULL,
						A_GIMME,
						0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//	jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
	jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR);	// include textfield and Fonts attributes
//	jbox_initclass(c, 0);
	
	class_addmethod(c, (method) ratnum_paint,			"paint", A_CANT, 0);

	class_addmethod(c, (method) ratnum_key,				"key", A_CANT, 0);
	class_addmethod(c, (method) ratnum_keyfilter,		"keyfilter", A_CANT, 0);
	class_addmethod(c, (method) ratnum_enter,			"enter", A_CANT, 0);
	class_addmethod(c, (method) jbox_notify,			"notify", A_CANT, 0);

//	class_addmethod(c, (method) ratnum_select,			"select", 0);

	// @method llll @digest Store and output the value
	// @description The number received in the inlet is stored, displayed, and sent through the left outlet.
	// Floating point numbers are approximated and converted into rational numbers. Integer numbers are 
	// displayed as rational number with denominator 1.
	class_addmethod(c, (method) ratnum_anything,	"anything", A_GIMME, 0);
	class_addmethod(c, (method) ratnum_int,			"int", A_LONG, 0);
	class_addmethod(c, (method) ratnum_float,		"float", A_FLOAT, 0);
	class_addmethod(c, (method) ratnum_anything,	"list", A_GIMME, 0);


	// @method set @digest Set the value with no output
	// @description The word <m>set</m>, followed by a rational number, sets the stored and displayed value to that number
	// without triggering the output. 
	// @marg 0 @name value @optional 0 @type number/anything/llll
	class_addmethod(c, (method) ratnum_anything,	"set", A_GIMME, 0);

	// @method min @digest Set the minimum allowed value
	// @description The word <m>min</m>, followed by a number (of any type), sets the minimum value that can be displayed or sent
	// out. The word <m>min</m> followed by the symbol <m>none</m> removes any prior minimum value constraint.
	// @marg 0 @name value @optional 0 @type llll
	class_addmethod(c, (method) ratnum_anything,	"min", A_GIMME, 0);

	// @method max @digest Set the maximum allowed value
	// @description The word <m>min</m>, followed by a number (of any type), sets the maximum value that can be displayed or sent
	// out. The word <m>max</m> followed by the symbol <m>none</m> removes any prior maximum value constraint.
	// @marg 0 @name value @optional 0 @type llll
	class_addmethod(c, (method) ratnum_anything,	"max", A_GIMME, 0);

	// @method bang @digest Output the stored value
	// @description Sends the currently displayed rational number out the left outlet.
	class_addmethod(c, (method) ratnum_bang,		"bang", 0);

	// @method reduce @digest Reduce to lowest terms
	// @description Explicitely reduces the rational number to lowest terms. This operation is always performed automatically,
	// unless the <m>autoreduce</m> attribute is deactivated (in which case it is only performed for incoming numbers, but not for
	// the one typed in or changed via the interface).
	class_addmethod(c, (method) ratnum_reduce, "reduce", 0);

	// @method (mouse) @digest Edit and output the value
	// @description Clicking and dragging up and down on the numerator or denominator (when the patcher window is locked) moves the
	// displayed value up and down, and outputs new values continuously. Numerator and denominator can be clicked and dragged individually.
	// If the <m>autoreduce</m> attribute is active, the output result is always reduced to the lowest
	// terms, even if, for interface clarity, the displayed number is not, until the mouse has been released.
	// When the active patcher window is locked, numbers can be entered into bach.ratnum directly by clicking on it with the mouse and
	// typing in a number on the computer keyboard. Typing the Return or Enter keys on Macintosh or the Enter key on windows,
	// or clicking outside the box, sends the number out the outlet. 
	class_addmethod(c, (method) ratnum_mousedown, "mousedown", A_CANT, 0);
	class_addmethod(c, (method) ratnum_mousedrag, "mousedrag", A_CANT, 0);
	class_addmethod(c, (method) ratnum_mouseup, "mouseup", A_CANT, 0);
//	class_addmethod(c, (method) ratnum_mouseenter, "mouseenter", A_CANT, 0);
//	class_addmethod(c, (method) ratnum_mouseleave, "mouseleave", A_CANT, 0);
//	class_addmethod(c, (method) ratnum_mousemove, "mousemove", A_CANT, 0);
//	class_addmethod(c, (method) ratnum_mousewheel, "mousewheel", A_CANT, 0);
	class_addmethod(c, (method) ratnum_oksize, "oksize", A_CANT, 0);

	class_addmethod(c, (method) ratnum_focusgained, "focusgained", A_CANT, 0);
	class_addmethod(c, (method) ratnum_focuslost, "focuslost", A_CANT, 0); 
    class_addmethod(c, (method) ratnum_preset, "preset", 0);

	class_addmethod(c, (method) ratnum_inletinfo, "inletinfo", A_CANT, 0);
	class_addmethod(c, (method) ratnum_assist, "assist", A_CANT, 0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_UI);


	CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 50 22"); // new dimensions
	// @exclude bach.ratnum

	CLASS_STICKY_ATTR(c,"category",0,"Color");

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "textcolor", 0, t_ratnum, j_textcolor, "Text Color", "text_number");
        CLASS_ATTR_LEGACYDEFAULT(c, "textcolor", "textcolor", 0, "0.921569 0.917647 0.933333 1.0");
        class_attr_stylemap(c, (char *)"textcolor", (char *)"textcolor_inverse");
        CLASS_ATTR_BASIC(c, "textcolor", 0);
		// @description Sets the color for the displayed/unclicked number values.
#else
        CLASS_ATTR_RGBA(c, "textcolor", 0, t_ratnum, j_textcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0.921569 0.917647 0.933333 1.0");
        CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
        CLASS_ATTR_BASIC(c, "textcolor", 0);
#endif
    
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "bgcolor", 0, t_ratnum, j_bgcolor, "Background Color", "rect_fill");
        CLASS_ATTR_LEGACYDEFAULT(c, "bgcolor", "bgcolor", 0, "0.2 0.2 0.2 1.0");
        CLASS_ATTR_BASIC(c, "bgcolor", 0);
		// @description Sets the color for the displayed/unclicked background.
#else
        CLASS_ATTR_RGBA(c, "bgcolor", 0, t_ratnum, j_bgcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "0.2 0.2 0.2 1.0");
        CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
        CLASS_ATTR_BASIC(c, "bgcolor", 0);
#endif
    
		CLASS_ATTR_RGBA(c, "bordercolor", 0, t_ratnum, j_bordercolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0.5 0.5 0.5 1.");
		CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");
        // @description Sets the color for the object's outline.
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_INVISIBLE(c, "bordercolor", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // no longer supported since Max7
#endif

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "tricolor", 0, t_ratnum, j_tricolor, "Triangle Color", "triangle_fill");
        CLASS_ATTR_LEGACYDEFAULT(c, "tricolor", "tricolor", 0, "0.501961 0.501961 0.501961 1.0");
        class_attr_stylemap(c, (char *)"tricolor", (char *)"accentcolor");
		// @description Sets the color for the triangle that indicates that the contents are editable.
		// This is used when the content is not being edited.
#else
        CLASS_ATTR_RGBA(c, "tricolor", 0, t_ratnum, j_tricolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "tricolor", 0, "0.501961 0.501961 0.501961 1.0");
        CLASS_ATTR_STYLE_LABEL(c, "tricolor", 0, "rgba", "Triangle Color");
#endif
    
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "htricolor", 0, t_ratnum, j_htricolor, "Highlighted Triangle Color", "triangle_fill");
        CLASS_ATTR_LEGACYDEFAULT(c, "htricolor", "htricolor", 0, "0.929412 0.929412 0.352941 1.0");
        class_attr_stylemap(c, (char *)"htricolor", (char *)"selectioncolor");
		// @description Sets the highlight color for the triangle that indicates that the contents are editable.
		// This is used when the content is being edited.
#else
        CLASS_ATTR_RGBA(c, "htricolor", 0, t_ratnum, j_htricolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "htricolor", 0, "0.929412 0.929412 0.352941 1.0");
        CLASS_ATTR_STYLE_LABEL(c, "htricolor", 0, "rgba", "Highlighted Triangle Color");
#endif

    
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Value");

		CLASS_ATTR_SYM(c,"minimum",0, t_ratnum, r_min_sym);
		CLASS_ATTR_STYLE_LABEL(c,"minimum",0,"text","Minimum");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minimum",0,"<none>");
		CLASS_ATTR_ACCESSORS(c, "minimum", (method)NULL, (method)ratnum_setattr_minimum);
		CLASS_ATTR_BASIC(c,"minimum",0);
		// @description Sets the minimum value that can be displayed or sent out.

		CLASS_ATTR_SYM(c,"maximum",0, t_ratnum, r_max_sym);
		CLASS_ATTR_STYLE_LABEL(c,"maximum",0,"text","Maximum");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maximum",0,"<none>");
		CLASS_ATTR_ACCESSORS(c, "maximum", (method)NULL, (method)ratnum_setattr_maximum);
		CLASS_ATTR_BASIC(c,"maximum",0);
		// @description Sets the maximum value that can be displayed or sent out.

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Behavior");

		CLASS_ATTR_CHAR(c,"outputmode",0, t_ratnum, output_mode);
		CLASS_ATTR_STYLE_LABEL(c,"outputmode",0,"enumindex","Output Mode");
		CLASS_ATTR_ENUMINDEX(c,"outputmode", 0, "Rational List");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"outputmode",0,"0");
		CLASS_ATTR_ACCESSORS(c, "outputmode", (method)NULL, (method)ratnum_setattr_outputmode);
		CLASS_ATTR_BASIC(c,"outputmode",0);
		// @description Sets the output mode: if this is "Rational" (default), a single rational is output.
		// If this is "List", numerator and denominator are output separately in a list (plain llll, containing just the two values).

		CLASS_ATTR_CHAR(c,"autoreduce",0, t_ratnum, autoreduce);
		CLASS_ATTR_STYLE_LABEL(c,"autoreduce",0,"onoff","Autoreduce");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autoreduce",0,"1");
		CLASS_ATTR_ACCESSORS(c, "autoreduce", (method)NULL, (method)ratnum_setattr_autoreduce);
		CLASS_ATTR_BASIC(c,"autoreduce",0);
		// @description If this flag is set to 1, rationals typed in or changed via mousedrag are automatically reduced to 
		// lowest terms before being output, each time the mouse is released. If this flag is set to 0, this does not happens,
		// and one should send explicitely a <m>reduce</m> message. This distinction only applies for numbers introduced or 
		// changed via the interface: ANY rational number introduced via message is automatically reduced to lowest terms.

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c,"category",0,"Appearance");

		CLASS_ATTR_CHAR(c,"triangle",0, t_ratnum, show_triangle);
		CLASS_ATTR_STYLE_LABEL(c,"triangle",0,"onoff","Show Triangle");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"triangle",0,"1");
		CLASS_ATTR_ACCESSORS(c, "triangle", (method)NULL, (method)ratnum_setattr_triangle);
		// @description Toggles the drawing	of a triangular arrow pointing to the number in the number box. 
		// The default is 1 (draw the triangle)

		CLASS_ATTR_DOUBLE(c,"triscale",0, t_ratnum, triangle_scale_factor);
		CLASS_ATTR_STYLE_LABEL(c,"triscale",0,"text","Triangle Scale Factor");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"triscale",0,"1.");
		CLASS_ATTR_ACCESSORS(c, "triscale", (method)NULL, (method)ratnum_setattr_triscale);
		// @description Scales the size of the triangle drawn in the number box.

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	s_ratnum_class = c;
	class_register(CLASS_BOX, s_ratnum_class);
	
	dev_post("bach.ratnum compiled %s %s", __DATE__, __TIME__);
	return 0;
}

void ratnum_assist(t_ratnum *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) { // @in 0 @type llll @digest Set display number and output
		sprintf(s, "llll: Set Displayed Number and Repeat to Output");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
		switch (a)
		{
			case 0:	// @out 0 @type llll @digest Output incoming or entered number
				sprintf(s, "llll (%s): Output Incoming or Entered Number", type);
				break;
			case 1:  // @out 1 @type bang @digest Send a bang when the Tab key has been pressed 
				sprintf(s, "bang When Tab Key Pressed");
				break;
		}
	}
}

void ratnum_inletinfo(t_ratnum *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

long ratnum_oksize(t_ratnum *x, t_rect *newrect)
{
	double w, h;
	t_jfont *font = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
			(t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x));
		
		jfont_text_measure(font, "M", &w, &h);
	jfont_destroy_debug(font);
	
	newrect->height = ceil(h - 0.0001);
	newrect->height += 8;
	if ((6+w) > newrect->width)
		newrect->width = 6 + w;
	return 0;
}

void ratnum_int(t_ratnum *x, t_atom_long num){
	t_atom argv[1]; atom_setlong(argv, num);
	ratnum_anything(x, _llllobj_sym_list, 1, argv);
}

void ratnum_float(t_ratnum *x, double num){
	t_atom argv[1]; atom_setfloat(argv, num);
	ratnum_anything(x, _llllobj_sym_list, 1, argv);
}

void check_min_max(t_ratnum *x){
	if (x->def_min && (rat_rat_cmp(x->r_value, x->r_min) < 0))
		x->r_value = x->r_min;
	if (x->def_max && (rat_rat_cmp(x->r_value, x->r_max) > 0))
		x->r_value = x->r_max;
}

void gunload_ratllll(t_ratnum *x){
	t_llll *rat_llll = llll_get();
	if (x->output_mode == 0) {
		// output as a single rational
		llll_appendrat(rat_llll, x->r_value, 0, WHITENULL_llll);
	} else {
		// output as (num den) list
		llll_appendlong(rat_llll, x->r_value.r_num, 0, WHITENULL_llll);
		llll_appendlong(rat_llll, x->r_value.r_den, 0, WHITENULL_llll);
	}
	llllobj_gunload_llll((t_object *)x, LLLL_OBJ_UI, rat_llll, 0);
}

void ratnum_anything(t_ratnum *x, t_symbol *s, long argc, t_atom *argv){ //argv+1
	
	
	char just_set = false;
	if (s != _sym_bang) {
		t_llll *inputlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE); // We clone it: we operatnume destructively

		// first: let's see if we have to SET something.
		if (inputlist && (inputlist->l_size >= 1) && (hatom_gettype(&inputlist->l_head->l_hatom) == H_SYM) && (hatom_getsym(&inputlist->l_head->l_hatom) == _sym_set)) {
			just_set = true;
			llll_destroyelem(inputlist->l_head);
		}

		if (inputlist && (inputlist->l_size >= 1) && (hatom_gettype(&inputlist->l_head->l_hatom) == H_RAT)) { 

			// a RATIONAL has been introduced (as first element of a list? we don't care, still a rational has been introduced!)
			x->r_value = hatom_getrational(&inputlist->l_head->l_hatom);
			
		} else if (inputlist && (inputlist->l_size >= 2) && (hatom_gettype(&inputlist->l_head->l_hatom) == H_LONG) && (hatom_gettype(&inputlist->l_head->l_hatom) == H_LONG)) {

			// two LONGS have been introduced (as first element of a list? we don't care, still two longs have been introduced!): 
			// we take them as numerator and denominator
			x->r_value.r_num = hatom_getlong(&inputlist->l_head->l_hatom);
			x->r_value.r_den = hatom_getlong(&inputlist->l_head->l_next->l_hatom);
			if (x->autoreduce)
				rat_reduce(&x->r_value);
		
		} else if (inputlist && (inputlist->l_size >= 1) && (hatom_gettype(&inputlist->l_head->l_hatom) == H_LONG)) {
			
			// one LONGS has been introduced
			x->r_value = genrat(hatom_getlong(&inputlist->l_head->l_hatom), 1);

		} else if (inputlist && (inputlist->l_size >= 1) && (hatom_gettype(&inputlist->l_head->l_hatom) == H_DOUBLE)) {
			
			// one FLOAT has been introduced
			x->r_value = approx_double_with_rat_fixed_den(hatom_getdouble(&inputlist->l_head->l_hatom), CONST_MAXDEN_FOR_DOUBLE_TO_RAT_APPROXIMATION, 0, NULL);

		} else if (inputlist && (inputlist->l_size >= 1) && (hatom_gettype(&inputlist->l_head->l_hatom) == H_SYM)) {

			// first element is a symbol.
			t_symbol *router = hatom_getsym(&inputlist->l_head->l_hatom);
			if (router == _sym_min) {
				set_minimum_from_ac_av(x, argc-1, argv+1);
				llll_free(inputlist);
				return;
			} else if (router == _sym_max) {
				set_maximum_from_ac_av(x, argc-1, argv+1);
				llll_free(inputlist);
				return;
			}
		}
		llll_free(inputlist);
			
		check_min_max(x);
		gunload_ratllll(x); // ((t_llllobj_object *) x)
		update_screen(x);
	}
	
	
	if (!just_set) {
		x->j_box.l_rebuild = false;
		ratnum_bang(x);
	} else
		x->j_box.l_rebuild = true;

}

void update_screen(t_ratnum *x){
	// update screen:
	char text[512];
	t_object *textfield;
	long size;

	textfield = jbox_get_textfield((t_object *)x);
	sprintf(text, RATIONAL_PRINTF_FMT, x->r_value.r_num, x->r_value.r_den);
	size = strlen(text);
	if (size)
		object_method(textfield, _sym_settext, text);
	jbox_redraw((t_jbox *)x);
}


t_ratnum* ratnum_new(t_symbol *s, long argc, t_atom *argv){
	t_ratnum* x = NULL;
	t_max_err err = MAX_ERR_GENERIC;
	t_dictionary *d;
	long flags;
	t_object *textfield;
	t_atom av[1];

	if (!(d=object_dictionaryarg(argc,argv)))
		return NULL;

	x = (t_ratnum*) object_alloc_debug(s_ratnum_class);
	flags = 0 
			| JBOX_DRAWFIRSTIN 
			| JBOX_NODRAWBOX
			| JBOX_DRAWINLAST
	//		| JBOX_TRANSPARENT	
	//		| JBOX_NOGROW
	//		| JBOX_GROWY
	//		| JBOX_GROWBOTH
			| JBOX_HILITE
	//		| JBOX_BACKGROUND
			| JBOX_TEXTFIELD
	//		| JBOX_DRAWBACKGROUND
	//		| JBOX_DEFAULTNAMES
	//		| JBOX_MOUSEDRAGDELTA
			;

	x->changing_size = 0;

	err = jbox_new(&x->j_box.l_box, flags, argc, argv); 
	x->j_box.l_box.b_firstin = (t_object*) x;

	x->def_min = x->def_max = false;
	x->j_box.l_rebuild = false;
	x->itsme = false;
	x->zoom_y = 1.;
	x->triangle_scale_factor = 1.;

	x->itsme = true;
	x->j_hasbeendragged = false;
	
	// retrieve saved attribute values
	attr_dictionary_process(x, d);


	textfield = jbox_get_textfield((t_object *) x); 
	if (textfield) {
		textfield_set_noactivate(textfield, 1);
		textfield_set_editonclick(textfield, 0); // set it to 0 if you don't want user to edit it in lock mode
		textfield_set_textmargins(textfield, 3, 4, 3, 4);	// margin on each side
		textfield_set_textcolor(textfield, &x->j_textcolor);
		textfield_set_useellipsis(textfield, 1);
        textfield_set_wantsreturn(textfield, 0);
		textfield_set_wordwrap(textfield, 0);
	}
	refresh_text_margins(x);
	
	llllobj_jbox_setup((t_llllobj_jbox *) x, 2, "b4");

	atom_setlong(av, 0);
	ratnum_anything(x, _llllobj_sym_list, 1, av);
	x->itsme = false;
	
	// mutex
	systhread_mutex_new_debug(&x->c_mutex, 0);

	jbox_ready(&x->j_box.l_box);

	if (x) {
		return x;
	}

	object_free_debug(x);
	return NULL;
}

void ratnum_free(t_ratnum *x){
	jbox_free(&x->j_box.l_box);
	systhread_mutex_free_debug(x->c_mutex);
	llllobj_jbox_free((t_llllobj_jbox *) x);
}

void ratnum_paint(t_ratnum *x, t_object *view){

	t_jgraphics *g;
	t_rect rect;
	t_object *textfield;
    t_jrgba j_textcolor_r, j_bgcolor_r, j_tricolor_r, j_htricolor_r;
    
    object_attr_getjrgba((t_object *)x, gensym("textcolor"), &j_textcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("bgcolor"), &j_bgcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("tricolor"), &j_tricolor_r);
    object_attr_getjrgba((t_object *)x, gensym("htricolor"), &j_htricolor_r);

	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(view); 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, view, &rect);

	paint_background((t_object *)x, g, &rect, &j_bgcolor_r, 0.);

	// setting font color and size
	textfield = jbox_get_textfield((t_object *) x); 
	textfield_set_textcolor(textfield, &j_textcolor_r);
	//textfield_set_wordwrap(textfield, 1); 
	
	// triangle
	if (x->show_triangle) {
		t_jrgba color = x->j_has_focus ? j_htricolor_r : j_tricolor_r;
		jgraphics_set_source_jrgba(g, &color); 
		jgraphics_set_line_width(g, 0.);
		jgraphics_move_to(g, 4 + 6 * x->triangle_scale_factor, rect.height/2.);
		jgraphics_line_to(g, 4, rect.height/2. -  6 * x->triangle_scale_factor);
		jgraphics_line_to(g, 4, rect.height/2. +  6 * x->triangle_scale_factor);
		jgraphics_close_path(g); 
		jgraphics_fill(g);	
	}


//	paint_border((t_object *)x, g, &rect, &x->j_bordercolor, 2., 6.);
}

/*
void ratnum_getdrawparams(t_ratnum *x, t_object *patcherview, t_jboxdrawparams *params)
{
	params->d_bordercolor = x->j_bordercolor;
	params->d_borderthickness = 2.;
	params->d_cornersize = 6.;
	params->d_boxfillcolor = x->j_bgcolor;
}
 */
	
long ratnum_key(t_ratnum *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
	char buff[256];
	buff[0] = textcharacter;  // we know this is just a simple char
	buff[1] = 0; 
	
	if (textcharacter == 9 || textcharacter == 13 || textcharacter == 27) { // TAB, RETURN, ESC
		t_atom arv;
		object_method_typed(patcherview, _llllobj_sym_endeditbox, 0, NULL, &arv); 
		if (textcharacter == 9)
			llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 1);
	} else if ((textcharacter >= 48 && textcharacter <= 57) || textcharacter == 47 || textcharacter == 45) {
        t_object *textfield = jbox_get_textfield((t_object *) x);
		object_method(textfield, _sym_settext, buff);
        object_method(patcherview, _sym_insertboxtext, x, buff);
		jbox_redraw((t_jbox *)x);
	}

	return 1;
}

long ratnum_keyfilter(t_ratnum *x, t_object *patcherview, long *keycode, long *modifiers, long *textcharacter)
{
	return 1;
}

void ratnum_enter(t_ratnum *x)	// enter is triggerd at "endeditbox time"
{
	long size	= 0;
	char *text	= NULL;
	t_object *textfield = jbox_get_textfield((t_object *)x);
	object_method(textfield, _sym_gettextptr, &text, &size);
	if (size) {
//		post("This is the new text: %s", text);
		char* p; long i = 0; t_atom argv[2];
//		printf("Stringa completa: \n %s\nStringa spezzata:\n",s);
		p = strtok(text, "/");
		while (p != NULL && i < 2)
		{
			char *q;
			long l = strtol(p, &q, 0);
			atom_setlong(argv + i, l);
//			printf("%s\n", p);
			p = strtok(NULL, ",");
			i++;
		}
//		return 0;
		
//		t_atom argv[1]; atom_setsym(argv, gensym(text));
		ratnum_anything(x, NULL, 2, argv);

	}
}

void ratnum_mousedown(t_ratnum *x, t_object *patcherview, t_pt pt, long modifiers){
	// where did I click?
	char num_str[50], den_str[50];
	const double X_INSET = 10;
	double num_w, num_h, slash_w, slash_h, den_w, den_h;
	t_jfont *font = jfont_create_debug(jbox_get_fontname((t_object *)x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *)x),
			(t_jgraphics_font_weight)jbox_get_font_weight((t_object *)x), jbox_get_fontsize((t_object *)x));

	evnum_incr();

	x->j_mousedrag_pt = pt;
	x->j_hasbeendragged = false;
	
	snprintf_zero(num_str, 50, "%ld", x->r_value.r_num);
	snprintf_zero(den_str, 50, "%ld", x->r_value.r_den);
	jfont_text_measure(font, num_str, &num_w, &num_h);
	jfont_text_measure(font, "/", &slash_w, &slash_h);
	jfont_text_measure(font, den_str, &den_w, &den_h);
	jfont_destroy_debug(font);
	
	if (pt.x >= X_INSET && pt.x <= X_INSET + num_w) { // clicked num
		x->dragging_obj = 1;
		x->dragging_val = x->r_value.r_num;
	} else if (pt.x >= X_INSET + num_w + slash_w && pt.x <= X_INSET + num_w + slash_w + den_w) { // clicked den
		x->dragging_obj = 2;
		x->dragging_val = x->r_value.r_den;
	}
}

void ratnum_mousedrag(t_ratnum *x, t_object *patcherview, t_pt pt, long modifiers){
	if (x->dragging_obj == 1 || x->dragging_obj == 2) {
		t_object *textfield;
		char text[512];
		long size;
		double diff = (x->j_mousedrag_pt.y - pt.y) * CONST_RATNUM_Y_DRAGGING_MULTIPLIER;

		x->j_hasbeendragged = true;
		
		if (x->dragging_obj == 1) { // dragging numerator
			x->r_value.r_num = round(x->dragging_val + diff);
			x->dragging_val += diff;
		} else if (x->dragging_obj == 2) { // dragging denominator
			x->r_value.r_den = round(x->dragging_val + diff);
			x->dragging_val += diff;
		}
		
		// update screen:
		textfield = jbox_get_textfield((t_object *)x);
		snprintf_zero(text, 512, "%ld/%ld", x->r_value.r_num, x->r_value.r_den);
		size = strlen(text);
		if (size)
			object_method(textfield, _sym_settext, text);
		jbox_redraw((t_jbox *)x);

		check_min_max(x);
		gunload_ratllll(x);
		ratnum_bang(x);
	}
	x->j_mousedrag_pt = pt;
}

void ratnum_mouseup(t_ratnum *x, t_object *patcherview, t_pt pt, long modifiers){
	t_object *textfield;
	char text[512];
	long size;

	if (x->autoreduce)
		rat_reduce(&x->r_value);
	check_min_max(x);
	gunload_ratllll(x);
	
	if (x->j_hasbeendragged)
		ratnum_bang(x);

	// update screen:
	textfield = jbox_get_textfield((t_object *)x);
	snprintf_zero(text, 512, "%ld/%ld", x->r_value.r_num, x->r_value.r_den);
	size = strlen(text);
	if (size)
		object_method(textfield, _sym_settext, text);
	jbox_redraw((t_jbox *)x);
}
void ratnum_focusgained(t_ratnum *x, t_object *patcherview) {
//	object_post((t_object *)x, "focusgained"); 
	x->j_has_focus = true;
	jbox_redraw((t_jbox *)x);
}

void ratnum_focuslost(t_ratnum *x, t_object *patcherview) {
//	object_post((t_object *)x, "focuslost"); 
	x->j_has_focus = false;
	jbox_redraw((t_jbox *)x);
}
