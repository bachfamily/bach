/*
 *  mc2n.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
	mc2n.c
	
	@name 
	bach.mc2n
	
	@realname 
	bach.mc2n

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
    @status
    deprecated

	@digest 
	Midicents to note name conversion
	
	@description
	Converts an llll containing midicents into a corresponding llll containing note names. 
	
	@discussion
	The note names are inferred automatically from the pitch, by snapping it to the 
	nearest element of the current microtonal grid (see the <m>tonedivision</m> attribute).
	
	@category
	bach, bach objects, bach notation

	@keywords
	convert, midicent, cent, note, name

	@seealso
	bach.n2mc, bach.f2mc, bach.mc2f
	
	@owner
	Daniele Ghisi
*/

#include "notation/notation.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include "foundation/llllobj.h"

typedef struct _mc2n
{
	struct llllobj_object 	n_ob;
	
	long					tone_division;
	char					accidentals_preferences;
	char					note_names_style;
	char					print_octave;
	
	long					middle_c_octave;
	long					last_used_octave;
} t_mc2n;


void mc2n_assist(t_mc2n *x, void *b, long m, long a, char *s);
void mc2n_inletinfo(t_mc2n *x, void *b, long a, char *t);

t_mc2n *mc2n_new(t_symbol *s, short ac, t_atom *av);
void mc2n_free(t_mc2n *x);

void mc2n_bang(t_mc2n *x);
void mc2n_int(t_mc2n *x, t_atom_long num);
void mc2n_float(t_mc2n *x, double num);
void mc2n_anything(t_mc2n *x, t_symbol *msg, long ac, t_atom *av);

t_class *mc2n_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}	
	
    CLASS_NEW_CHECK_SIZE(c, "bach.mc2n", (method)mc2n_new, (method)mc2n_free, (long) sizeof(t_mc2n), 0L, A_GIMME, 0);
	
	// @method llll @digest Convert midicents to note names
	// @description The function outputs an llll formatted as the incoming one, but containing the note name 
	// instead of each midicents value. 
	class_addmethod(c, (method)mc2n_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)mc2n_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)mc2n_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)mc2n_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the conversion.
	// @description Perform the conversion on the most recently received input data.
	class_addmethod(c, (method)mc2n_bang,						"bang",		0);
	
	class_addmethod(c, (method)mc2n_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)mc2n_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

	
	CLASS_ATTR_LONG(c, "tonedivision", 0, t_mc2n, tone_division); 
	CLASS_ATTR_STYLE_LABEL(c,"tonedivision",0,"text","Microtonal Division");
	CLASS_ATTR_BASIC(c,"tonedivision",0);
	// @description @copy BACH_DOC_TONEDIVISION

	CLASS_ATTR_CHAR(c, "accidentalspreferences", 0, t_mc2n, accidentals_preferences); 
	CLASS_ATTR_STYLE_LABEL(c,"accidentalspreferences",0,"enumindex","Accidental Preferences");
	CLASS_ATTR_ENUMINDEX(c,"accidentalspreferences", 0, "Auto Sharps Flats");
	CLASS_ATTR_BASIC(c,"accidentalspreferences",0);
	// @description @copy BACH_DOC_ACCIDENTALSPREFERENCES

	CLASS_ATTR_CHAR(c,"notenamesstyle",0, t_mc2n, note_names_style);
	CLASS_ATTR_STYLE_LABEL(c,"notenamesstyle",0,"enumindex","Note Names Style");
	CLASS_ATTR_ENUMINDEX(c,"notenamesstyle", 0, "Latin Anglo-Saxon");
	CLASS_ATTR_BASIC(c,"notenamesstyle",0);
    CLASS_ATTR_INVISIBLE(c, "notenamesstyle", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // deprecated and unsupported
	// @description @copy BACH_DOC_NOTENAMESSTYLE

	CLASS_ATTR_CHAR(c,"octave",0, t_mc2n, print_octave);
	CLASS_ATTR_STYLE_LABEL(c,"octave",0,"onoff","Append Octave Number");
	CLASS_ATTR_BASIC(c,"octave",0);
	// @description Toggles the ability to append the octave number to the note name. Defaults to 1 (true).
	
	CLASS_ATTR_LONG(c, "middlecoctave", 0, t_mc2n, middle_c_octave); 
	CLASS_ATTR_STYLE_LABEL(c,"middlecoctave",0,"text","Middle C Octave");
    CLASS_ATTR_INVISIBLE(c, "middlecoctave", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // deprecated and unsupported
    // @exclude all
	// @description @copy BACH_DOC_MIDDLECOCTAVE
	

	class_register(CLASS_BOX, c);
	mc2n_class = c;
	
	dev_post("bach.mc2n compiled %s %s", __DATE__, __TIME__);
    object_warn(NULL, "bach.mc2n is deprecated. Please consider replacing me with bach.mc2p!");

	return;
}

void mc2n_bang(t_mc2n *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void mc2n_int(t_mc2n *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	mc2n_anything(x, _llllobj_sym_list, 1, argv);
}

void mc2n_float(t_mc2n *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	mc2n_anything(x, _llllobj_sym_list, 1, argv);
}

long substitute_mc_with_names_fn(void *data, t_hatom *a, const t_llll *address){
	if (is_hatom_number(a)){
		t_mc2n *x = (t_mc2n *) data;
		char *notename = NULL;
		long screen_mc = 6000;
		t_rational screen_acc = genrat(0, 1);
		mc_to_screen_approximations_do(x->tone_division, x->accidentals_preferences, hatom_getdouble(a), &screen_mc, &screen_acc, NULL, NULL);
		midicents2notename(x->middle_c_octave, screen_mc, screen_acc, x->note_names_style, x->print_octave, &notename);
		hatom_setsym(a, notename ? gensym(notename) : _llllobj_sym_empty_symbol);
		bach_freeptr(notename);
	}
	return 0;
}

void mc2n_anything(t_mc2n *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	if (inlist) {
		llll_funall(inlist, (fun_fn) substitute_mc_with_names_fn, x, 1, -1, 0);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, inlist, 0);
	}
	
	x->n_ob.l_rebuild = 0;
	mc2n_bang(x);
}


void mc2n_assist(t_mc2n *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll containing the midicents
		sprintf(s, "llll: Cents");
	} else {
		char *type = NULL; // @out 0 @type llll @digest The llll containing the note names
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Names", type);
	}
}

void mc2n_inletinfo(t_mc2n *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void mc2n_free(t_mc2n *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_mc2n *mc2n_new(t_symbol *s, short ac, t_atom *av)
{
	t_mc2n *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_mc2n *) object_alloc_debug(mc2n_class))) {
	
		x->middle_c_octave = 5;
		x->accidentals_preferences = 0;
		x->note_names_style = 1;
		x->print_octave = 1;
		x->tone_division = 2;

		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");

		x->last_used_octave = x->middle_c_octave;
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

