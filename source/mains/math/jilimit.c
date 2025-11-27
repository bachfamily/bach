/*
 *  jilimit.c
 *
 * Copyright (C) 2010-2025 Andrea Agostini and Daniele Ghisi
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
 jilimit.c
 
 @name 
 bach.jilimit
 
 @realname 
 bach.jilimit
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Just intonation prime limits
 
 @description
 Computes the just intonation prime limit of the incoming pitches or ratios
 
 @discussion
 
 @category
 bach, bach objects, bach math
 
 @keywords
 series, arithmetic, step, compute, calculate

 @seealso
 bach.jiwheel, bach.fareyser
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _jilimit
{
	t_llllobj_object 	n_ob;
	long				n_in;
	t_bach_atomic_lock	n_lock;
} t_jilimit;


void jilimit_assist(t_jilimit *x, void *b, long m, long a, char *s);
void jilimit_inletinfo(t_jilimit *x, void *b, long a, char *t);

t_jilimit *jilimit_new(t_symbol *s, short ac, t_atom *av);
void jilimit_free(t_jilimit *x);

void jilimit_bang(t_jilimit *x);
void jilimit_int(t_jilimit *x, t_atom_long v);
void jilimit_float(t_jilimit *x, double v);

void jilimit_anything(t_jilimit *x, t_symbol *msg, short ac, t_atom *av);


t_class *jilimit_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.jilimit", (method)jilimit_new, (method)jilimit_free, (long) sizeof(t_jilimit), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)jilimit_int,		"int",			A_LONG, 0);

	// @method int/rational/pitch/llll @digest Compute prime limits
	// @description
	// When an integer, a rational number, or a pitch is input, its just intonation prime limit is computed and output.
    // When an llll is input, the same operation is performed on every integer, rational number or pitch.
	class_addmethod(c, (method)jilimit_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)jilimit_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)jilimit_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)jilimit_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the last computed prime limits
	// @description A bang outputs the last computed prime limits.
	class_addmethod(c, (method)jilimit_bang,		"bang",			0);
	class_addmethod(c, (method)jilimit_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)jilimit_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	jilimit_class = c;
	

    
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	dev_post("bach.jilimit compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void jilimit_int(t_jilimit *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	jilimit_anything(x, _sym_int, 1, &outatom);
}

void jilimit_float(t_jilimit *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	jilimit_anything(x, _sym_float, 1, &outatom);
}

long compute_jilimit_fn(void *data, t_hatom *a, const t_llll *address){
    if (hatom_gettype(a) == H_LONG || hatom_gettype(a) == H_RAT || hatom_gettype(a) == H_PITCH) {
        t_rational r = hatom_gettype(a) == H_PITCH ? hatom_getpitch(a).getJIRatio() : hatom_getrational(a);
        hatom_setlong(a, rational_get_jilimit(r));
    } else if (hatom_gettype(a) != H_LLLL){
        hatom_setlong(a, 0);
    }
    return 0;
}

void jilimit_anything(t_jilimit *x, t_symbol *msg, short ac, t_atom *av)
{
    t_llll *ll;
    
    if (msg != _sym_bang)
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);

    ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1); // clone
    if (ll) {
        llll_funall(ll, compute_jilimit_fn, NULL, 1, -1);
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, ll);
    }
    llll_free(ll);
}

void jilimit_bang(t_jilimit *x)
{
    jilimit_anything(x, _sym_bang, 0, NULL);
}

void jilimit_assist(t_jilimit *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "int/rational/pitch/llll: Rational number, pitch or llll"); break;	// @in 0 @type int/rational/pitch/llll @digest Rational number, pitch or llll whose just intonation limit must be computed
		}
	}
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Just intonation limits
	}
}

void jilimit_inletinfo(t_jilimit *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void jilimit_free(t_jilimit *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_jilimit *jilimit_new(t_symbol *s, short ac, t_atom *av)
{
	t_jilimit *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_jilimit *) object_alloc_debug(jilimit_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
