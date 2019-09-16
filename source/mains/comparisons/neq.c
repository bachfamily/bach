/*
 *  neq.c
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
 neq.c
 
 @name 
 bach.!=
 
 @realname 
 bach.neq
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Compare two lllls for inequality
 
 @description
 Compares two lllls for inequality.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 compare, different, condition

 @seealso
 bach.==, bach.&gt;, bach.&lt;, bach.&gt;=, bach.&lt;=, bach.filter, bach.sieve 
 
 @owner
 Andrea Agostini
 */


#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _neq
{
	struct llllobj_object 	n_ob;
	void				*n_proxy;
	long				n_in;
	long				n_matchtype;
	long				n_longout;
} t_neq;


void neq_assist(t_neq *x, void *b, long m, long a, char *s);
void neq_inletinfo(t_neq *x, void *b, long a, char *t);

t_neq *neq_new(t_symbol *s, short ac, t_atom *av);
void neq_free(t_neq *x);

void neq_bang(t_neq *x);
void neq_int(t_neq *x, t_atom_long v);
void neq_float(t_neq *x, double v);
void neq_anything(t_neq *x, t_symbol *msg, long ac, t_atom *av);
t_max_err neq_notify(t_neq *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

t_class *neq_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.neq", (method)neq_new, (method)neq_free, (short)sizeof(t_neq), 0L, A_GIMME, 0);
	
	// @method llll @digest Store data and perform comparison
	// @description
	// In first inlet: The llll in the right inlet is compared to the llll and the result is output.<br />
	// In second inlet: The llll is stored, to be compared with an llll received in the first inlet.<br />
	class_addmethod(c, (method)neq_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)neq_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)neq_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)neq_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the last operation
	// @description Return the comparison result for the most recently received lllls.
	class_addmethod(c, (method)neq_bang,		"bang",			0);
	
	class_addmethod(c, (method)neq_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)neq_inletinfo,	"inletinfo",	A_CANT,		0);
	class_addmethod(c, (method)neq_notify,		"notify",		A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "matchtype",	0,	t_neq, n_matchtype);
	CLASS_ATTR_FILTER_CLIP(c, "matchtype", 0, 1);
	CLASS_ATTR_LABEL(c, "matchtype", 0, "Match Type");
	CLASS_ATTR_STYLE(c, "matchtype", 0, "onoff");
	CLASS_ATTR_BASIC(c, "matchtype", 0);
	// @description
	// When set to 0, numbers with different types but equal value (i.e. 1.5 and 3/2) are considered as equal. 
	// When set to 1, they are considered different.
	
	class_register(CLASS_BOX, c);
	neq_class = c;
	bach_class_setname("bach.!=", "bach.neq");
	dev_post("bach.!= compiled %s %s", __DATE__, __TIME__);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	return 0;
}

t_max_err neq_notify(t_neq *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	if (msg == _sym_attr_modified)
		x->n_ob.l_rebuild = 1;
	return MAX_ERR_NONE;
}

void neq_bang(t_neq *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		neq_anything(x, _sym_bang, 0, NULL);
	else
		outlet_int(x->n_ob.l_out[0].b_outlet, x->n_longout);
}

void neq_int(t_neq *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	neq_anything(x, _sym_int, 1, &outatom);
}

void neq_float(t_neq *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	neq_anything(x, _sym_float, 1, &outatom);
}

void neq_anything(t_neq *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll1, *ll2;
	long inlet = proxy_getinlet((t_object *) x);
	
	switch (inlet) {
		case 0:
			if (msg != _sym_bang) {
				ll1 = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
				if (!ll1)
					return;
			} else
				ll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
			ll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
			if (x->n_matchtype)
				x->n_longout = llll_neq_matchtype(ll1, ll2);
			else
				x->n_longout = llll_neq_ignoretype(ll1, ll2);
			llll_release(ll1);
			llll_release(ll2);
			x->n_ob.l_rebuild = 0;
			neq_bang(x);		
			break;
		case 1:
			x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1) != NULL;
			break;
	}
}

void neq_assist(t_neq *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll");
		// @in 0 @type llll @digest llll to be compared
		// @in 1 @type llll @digest llll to be compared
	} else 
		sprintf(s, "int: Comparison Result"); // @out 0 @type int @digest Comparison result (0/1)
	
}

void neq_inletinfo(t_neq *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void neq_free(t_neq *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_neq *neq_new(t_symbol *s, short ac, t_atom *av)
{
	t_neq *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_neq *) object_alloc_debug(neq_class))) {
		// @arg 0 @name default @optional 1 @type llll @digest Default comparison llll

		llllobj_obj_setup((t_llllobj_object *) x, 2, "i");
		if (true_ac) 
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, NULL, true_ac, av, 1);
		
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
		attr_args_process(x, ac, av);
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
