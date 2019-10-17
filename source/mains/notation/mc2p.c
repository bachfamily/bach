/*
 *  mc2p.c
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
	mc2p.c
	
	@name 
	bach.mc2p
	
	@realname 
	bach.mc2p

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	MIDIcents to pitch conversion
	
	@description
	Converts an llll containing cents into a corresponding llll containing pitches.
	
	@discussion
	The pitches are inferred automatically from the cents, by snapping it to the
	nearest element of the current microtonal grid (see the <m>tonedivision</m> attribute),
    depending on the values of the other attributes.
	
	@category
	bach, bach objects, bach notation

	@keywords
	convert, midicent, cent, note, name, bach pitches

	@seealso
	bach.p2mc, bach.f2mc, bach.mc2f, bach.approx
	
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

typedef struct _mc2p
{
	struct llllobj_object 	n_ob;
	
	long					tone_division;
	char					accidentals_preferences;
	char					print_octave;
} t_mc2p;


void mc2p_assist(t_mc2p *x, void *b, long m, long a, char *s);
void mc2p_inletinfo(t_mc2p *x, void *b, long a, char *t);

t_mc2p *mc2p_new(t_symbol *s, short ac, t_atom *av);
void mc2p_free(t_mc2p *x);

void mc2p_bang(t_mc2p *x);
void mc2p_int(t_mc2p *x, t_atom_long num);
void mc2p_float(t_mc2p *x, double num);
void mc2p_anything(t_mc2p *x, t_symbol *msg, long ac, t_atom *av);

t_class *mc2p_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}	
	
    CLASS_NEW_CHECK_SIZE(c, "bach.mc2p", (method)mc2p_new, (method)mc2p_free, (long) sizeof(t_mc2p), 0L, A_GIMME, 0);
	
	// @method llll @digest Convert MIDIcents to pitches
	// @description The function outputs an llll formatted as the incoming one, but containing the note name 
	// instead of each midicents value. 
	class_addmethod(c, (method)mc2p_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)mc2p_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)mc2p_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)mc2p_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the conversion.
	// @description Perform the conversion on the most recently received input data.
	class_addmethod(c, (method)mc2p_bang,						"bang",		0);
	
	class_addmethod(c, (method)mc2p_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)mc2p_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

	
	CLASS_ATTR_LONG(c, "tonedivision", 0, t_mc2p, tone_division); 
	CLASS_ATTR_STYLE_LABEL(c,"tonedivision",0,"text","Microtonal Division");
	CLASS_ATTR_BASIC(c,"tonedivision",0);
	// @description @copy BACH_DOC_TONEDIVISION
    // Set <m>tonedivision</m> to 0 (default) in order to perform the conversion at maximum precision.

	CLASS_ATTR_CHAR(c, "accidentalspreferences", 0, t_mc2p, accidentals_preferences); 
	CLASS_ATTR_STYLE_LABEL(c,"accidentalspreferences",0,"enumindex","Accidental Preferences");
	CLASS_ATTR_ENUMINDEX(c,"accidentalspreferences", 0, "Auto Sharps Flats");
	CLASS_ATTR_BASIC(c,"accidentalspreferences",0);
	// @description @copy BACH_DOC_ACCIDENTALSPREFERENCES

	CLASS_ATTR_CHAR(c,"octave",0, t_mc2p, print_octave);
	CLASS_ATTR_STYLE_LABEL(c,"octave",0,"onoff","Append Octave Number");
	CLASS_ATTR_BASIC(c,"octave",0);
	// @description Toggles the ability to append the octave number to the note name. Defaults to 1 (true).
    // If this is set to 0, then the output is not a pitch, but a symbol containing the pitch string without the octave.
	

	class_register(CLASS_BOX, c);
	mc2p_class = c;
	
	dev_post("bach.mc2p compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void mc2p_bang(t_mc2p *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void mc2p_int(t_mc2p *x, t_atom_long num)
{
	t_atom argv[1]; 
	atom_setlong(argv, num);
	mc2p_anything(x, _llllobj_sym_list, 1, argv);
}

void mc2p_float(t_mc2p *x, double num)
{
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	mc2p_anything(x, _llllobj_sym_list, 1, argv);
}

long substitute_mc_with_pitches_fn(void *data, t_hatom *a, const t_llll *address)
{
    t_mc2p *x = (t_mc2p *)data;
    t_pitch p = t_pitch::middleC;
    switch (hatom_gettype(a)) {
        case H_LONG:
        case H_DOUBLE:
        case H_RAT:
            p = t_pitch::fromMC(hatom_getdouble(a), x->tone_division, (e_accidentals_preferences)x->accidentals_preferences /*key_acc_pattern, t_rational *full_repr */);
            break;

        case H_PITCH:
            p = hatom_getpitch(a);
            break;

        default:
            break;
    }
    hatom_setpitch(a, p);
    
    if (x->print_octave == 0) {
        // output symbol without octave
        hatom_setsym(a, p.toSym(false));
    }
    
	return 0;
}

void mc2p_anything(t_mc2p *x, t_symbol *msg, long ac, t_atom *av)
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
		llll_funall(inlist, (fun_fn) substitute_mc_with_pitches_fn, x, 1, -1, 0);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, inlist, 0);
	}
	
	x->n_ob.l_rebuild = 0;
	mc2p_bang(x);
}


void mc2p_assist(t_mc2p *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll containing the MIDIcents
		sprintf(s, "llll: Cents");
	} else {
		char *type = NULL; // @out 0 @type llll @digest The llll containing the pitches
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Pitches", type);
	}
}

void mc2p_inletinfo(t_mc2p *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void mc2p_free(t_mc2p *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_mc2p *mc2p_new(t_symbol *s, short ac, t_atom *av)
{
	t_mc2p *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_mc2p *) object_alloc_debug(mc2p_class))) {
	
		x->accidentals_preferences = 0;
		x->print_octave = 1;
		x->tone_division = 0;

		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

