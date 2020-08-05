/*
 *  delace.c
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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
 delace.c
 
 @name 
 bach.delace
 
 @realname 
 bach.delace
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 De-interleave an llll
 
 @description
 Redistributes elements of an llll into several output lllls, in a round-robin fashion.
 
 @discussion
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 delace, deinterleave, split

 @seealso
 bach.lace, bach.trans
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _delace
{
	t_llllobj_object 	n_ob;
	long				n_mono;
	long				n_count;
} t_delace;


void delace_assist(t_delace *x, void *b, long m, long a, char *s);

t_delace *delace_new(t_symbol *s, short ac, t_atom *av);
void delace_free(t_delace *x);

void delace_bang(t_delace *x);
void delace_int(t_delace *x, t_atom_long v);
void delace_float(t_delace *x, double v);
void delace_anything(t_delace *x, t_symbol *msg, long ac, t_atom *av);

void delace_output(t_delace *x);

t_class *delace_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.delace", (method)delace_new, (method)delace_free, (long) sizeof(t_delace), 0L, A_GIMME, 0);

	// @method llll @digest De-interleave the llll
	// @description In standard mode: the elements of the llll are redistributed into several output lllls 
	// according to the number of outlets of the object (standard mode) 
	// or into several sublists of one output llll according to the <m>count</m> attribute (mono mode),
	// in a round-robin fashion.
	class_addmethod(c, (method)delace_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)delace_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)delace_float,	"float",		A_FLOAT,	0);
	class_addmethod(c, (method)delace_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Repeat last operation
	// @description Returns the last set of de-interleaved lllls.
	class_addmethod(c, (method)delace_bang,		"bang",			0);
	
	class_addmethod(c, (method)delace_assist,	"assist",	A_CANT,		0);

	CLASS_ATTR_LONG(c, "count",	0,	t_delace, n_count);
	CLASS_ATTR_FILTER_MIN(c, "count", 1);
	CLASS_ATTR_LABEL(c, "count", 0, "Count");
	CLASS_ATTR_BASIC(c, "count", 0);
	// @description
	// Number of output sublists in mono mode; ignored in standard mode.
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	delace_class = c;
	
	dev_post("bach.delace compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void delace_bang(t_delace *x)
{
	if (x->n_ob.l_rebuild != 0)
		delace_anything(x, _sym_bang, 0, NULL);
	else {
		delace_output(x);
	}
}

void delace_output(t_delace *x)
{
	long i;
	for (i = x->n_ob.l_numouts - 1; i >= 0; i --)
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
}
		 
void delace_int(t_delace *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	delace_anything(x, _sym_int, 1, &outatom);
}
	 
void delace_float(t_delace *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	delace_anything(x, _sym_float, 1, &outatom);
}
	 
void delace_anything(t_delace *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
	if (!inlist)
		return;
	if (x->n_mono) {
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_mdelace(inlist, x->n_count), 0);
	} else {
		t_llll **outlists = llll_delace(inlist, x->n_ob.l_numouts);
		llllobj_gunload_array_range((t_object *)x, LLLL_OBJ_VANILLA, outlists, 0, x->n_ob.l_numouts - 1);
		bach_freeptr(outlists);
	}
	delace_output(x);
}
	 
void delace_assist(t_delace *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest llll to de-interleave
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll %ld (%s)", a + 1, type); // @out 0 @loop 1 @type llll @digest De-interleaved llll
	}
}
	 
void delace_inletinfo(t_delace *x, void *b, long a, char *t)
{
	*t = 1;
}
	 
void delace_free(t_delace *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_delace *delace_new(t_symbol *s, short ac, t_atom *av)
{
	t_delace *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	char outlets[LLLL_MAX_OUTLETS];
	long i, numouts;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);

	if ((x = (t_delace *) object_alloc_debug(delace_class)) != NULL) {
		// @arg 0 @name parameters @optional 1 @type mono/int
		// @digest number of outlets / mono mode and number of sublists
		// @description A single integer argument is the number of outlets over which the incoming llll should be de-interleaved.<br />
		// If the first or only argument is the <b>mono</b> symbol, <o>bach.delace</o> works in "mono" mode,
		// that is the incoming llll is de-interleaved into sublists of a single llll.
		// In this case, the number of the resulting sublists is set via the <b>count</b> attribute, or the second argument.
		numouts = 2;
		if (true_ac) {
			if (atom_gettype(av) == A_SYM) {
				if (atom_getsym(av) == gensym("mono")) {
					x->n_mono = 1;
					numouts = 1;
					if (true_ac >= 2) {
						x->n_count = atom_getlong(av + 1);
					}
                    if (x->n_count < 1)
                        x->n_count = 2;
				} else {
					object_error((t_object *) x, "Unknown argument: %s", atom_getsym(av)->s_name);
				}
			} else {
				numouts = atom_getlong(av);
				if (numouts < 1 || numouts >= LLLL_MAX_OUTLETS) {
					object_error((t_object *) x, "Bad number of outlets");
					numouts = 2;
				}
			}
		}
		
		*outlets = 0;
		for (i = 0; i < numouts && i < LLLL_MAX_OUTLETS; i++)
			strncat(outlets, "4", LLLL_MAX_OUTLETS);
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 0, outlets);
		
	} else
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
