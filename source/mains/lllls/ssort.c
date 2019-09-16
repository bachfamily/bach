/*
 *  ssort.c
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
 ssort.c
 
 @name 
 bach.ssort
 
 @realname 
 bach.ssort
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 deprecated
 
 @digest 
 Simple sort
  
 @description
 Sorts an llll according to standard criteria.
 
 @discussion
 Object is deprecated. Use <o>bach.sort</o>.
 
 @category
 bach, bach objects, bach llll

 @keywords
 sort, order
 
 @seealso
 bach.sort
 
 @owner
 Andrea Agostini
 */
 
 
#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _ssort
{
	struct llllobj_object 	n_ob;
	long					n_order;
} t_ssort;


void ssort_assist(t_ssort *x, void *b, long m, long a, char *s);
void ssort_inletinfo(t_ssort *x, void *b, long a, char *t);

t_ssort *ssort_new(t_symbol *s, short ac, t_atom *av);
void ssort_free(t_ssort *x);

void ssort_bang(t_ssort *x);
void ssort_int(t_ssort *x, t_atom_long v);
void ssort_float(t_ssort *x, double v);
void ssort_anything(t_ssort *x, t_symbol *msg, long ac, t_atom *av);

t_class *ssort_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.ssort", (method)ssort_new, (method)ssort_free, (short)sizeof(t_ssort), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)ssort_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)ssort_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)ssort_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)ssort_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)ssort_bang,		"bang",			0);
	
	class_addmethod(c, (method)ssort_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)ssort_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	CLASS_ATTR_LONG(c, "order",	0,	t_ssort, n_order);
	CLASS_ATTR_FILTER_CLIP(c, "order", 0, 1);
	CLASS_ATTR_LABEL(c, "order", 0, "Order");
	CLASS_ATTR_ENUMINDEX(c, "order", 0, "Descending Ascending");
	CLASS_ATTR_BASIC(c, "order", 0);	

	class_register(CLASS_BOX, c);
	ssort_class = c;
	
	dev_post("bach.ssort compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void ssort_bang(t_ssort *x)
{	
	if (x->n_ob.l_rebuild != 0)
		ssort_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void ssort_int(t_ssort *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	ssort_anything(x, _sym_int, 1, &outatom);
}

void ssort_float(t_ssort *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	ssort_anything(x, _sym_float, 1, &outatom);
}

void ssort_anything(t_ssort *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in, *out;
	if (proxy_getinlet((t_object *) x) == 0) {
		if (msg != _sym_bang) {
			in = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
			if (!in)
				return;
		} else
			in = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		llll_mergesort(in, &out, x->n_order ? llll_geq_elem : llll_leq_elem, NULL);
		x->n_ob.l_rebuild = 0;
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, out, 0);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	} else
		object_error((t_object *) x, "Invalid message %s", msg->s_name);
}

void ssort_assist(t_ssort *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {		
		sprintf(s, "llll");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type);
	}
}

void ssort_inletinfo(t_ssort *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void ssort_free(t_ssort *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_ssort *ssort_new(t_symbol *s, short ac, t_atom *av)
{
	t_ssort *x = NULL;
	t_max_err err = 0;	
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_ssort *) object_alloc_debug(ssort_class))) {
		object_warn((t_object *) x, "bach.ssort is deprecated. Please replace me with bach.sort!");
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
