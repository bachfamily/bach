/*
 *  deferlow.c
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
 deferlow.c
 
 @name 
 bach.deferlow
 
 @realname 
 bach.deferlow
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Put an llll at the tail of the low-priority queue
 
 @description
 Puts the incoming llll at the tail of the low-priority queue. 
 
 @discussion
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 defer, queue, low-priority

 @seealso
 bach.defer, bach.pipe
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _deferlow
{
	struct llllobj_object 	n_ob;
} t_deferlow;


void deferlow_assist(t_deferlow *x, void *b, long m, long a, char *s);
void deferlow_inletinfo(t_deferlow *x, void *b, long a, char *t);

t_deferlow *deferlow_new(t_symbol *s, short ac, t_atom *av);
void deferlow_free(t_deferlow *x);

void deferlow_bang(t_deferlow *x);
void deferlow_int(t_deferlow *x, t_atom_long v);
void deferlow_float(t_deferlow *x, double v);
void deferlow_anything(t_deferlow *x, t_symbol *msg, long ac, t_atom *av);

void deferlow_output(t_deferlow *x, t_symbol *msg, long ac, t_atom *av);

t_class *deferlow_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.deferlow", (method)deferlow_new, (method)deferlow_free, (short)sizeof(t_deferlow), 0L, A_GIMME, 0);
	
	// @method llll @digest Defer the llll
	// @description
	// Puts the llll at the tail of the low-priority queue. 
	// This means that in any case its execution is deferred.
	class_addmethod(c, (method)deferlow_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)deferlow_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)deferlow_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)deferlow_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Defer the bang
	// @description
	// Puts the bang at the tail of the low-priority queue. 
	class_addmethod(c, (method)deferlow_bang,		"bang",			0);
	
	class_addmethod(c, (method)deferlow_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)deferlow_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	//llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	deferlow_class = c;
	
	dev_post("bach.deferlow compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void deferlow_bang(t_deferlow *x)
{	
	deferlow_anything(x, _sym_bang, 0, NULL);
}

void deferlow_int(t_deferlow *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	deferlow_anything(x, _sym_int, 1, &outatom);
}

void deferlow_float(t_deferlow *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	deferlow_anything(x, _sym_float, 1, &outatom);
}

void deferlow_anything(t_deferlow *x, t_symbol *msg, long ac, t_atom *av)
{
	t_atom outatom;
	t_llll *inll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (inll) {
		atom_setobj(&outatom, inll);
		defer_low(x, (method) deferlow_output, NULL, 1, &outatom);
	}
}

void deferlow_output(t_deferlow *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll = (t_llll *) av->a_w.w_obj;
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, ll);
	llll_release(ll);
}

void deferlow_assist(t_deferlow *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll to defer
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest The deferred llll
	}
}

void deferlow_inletinfo(t_deferlow *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void deferlow_free(t_deferlow *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_deferlow *deferlow_new(t_symbol *s, short ac, t_atom *av)
{
	t_deferlow *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_deferlow *) object_alloc_debug(deferlow_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
