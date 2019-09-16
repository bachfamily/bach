/*
 *  geq.c
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
 geq.c
 
 @name 
 bach.>=
 
 @realname 
 bach.geq
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Compare two lllls for greater than or equal condition
 
 @description
 Compares two lllls for greater than or equal condition, in numerical/lexicographical order.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 compare, greater, equal, condition, lexicographical, order, numerical

 @seealso
 bach.==, bach.!=, bach.&gt;, bach.&lt;, bach.&lt;=, bach.filter, bach.sieve 
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _geq
{
	struct llllobj_object 	n_ob;
	long					n_proxies;
	void					*n_proxy;
	long					n_in;
	long					n_longout;
} t_geq;


void geq_assist(t_geq *x, void *b, long m, long a, char *s);
void geq_inletinfo(t_geq *x, void *b, long a, char *t);

t_geq *geq_new(t_symbol *s, short ac, t_atom *av);
void geq_free(t_geq *x);

void geq_bang(t_geq *x);
void geq_int(t_geq *x, t_atom_long v);
void geq_float(t_geq *x, double v);
void geq_anything(t_geq *x, t_symbol *msg, long ac, t_atom *av);

t_class *geq_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.geq", (method)geq_new, (method)geq_free, (short)sizeof(t_geq), 0L, A_GIMME, 0);
	
	// @method llll @digest Store data and perform comparison
	// @description
	// In first inlet: The llll in the right inlet is compared to the llll and the result is output.<br />
	// In second inlet: The llll is stored, to be compared with an llll received in the first inlet.<br />
	// @copy BACH_DOC_LLLL_COMPARISON
	class_addmethod(c, (method)geq_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)geq_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)geq_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)geq_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the last operation
	// @description Return the comparison result for the most recently received lllls.
	class_addmethod(c, (method)geq_bang,		"bang",			0);
	
	class_addmethod(c, (method)geq_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)geq_inletinfo,	"inletinfo",	A_CANT,		0);
	bach_class_setname("bach.>=", "bach.geq");
	class_register(CLASS_BOX, c);
	geq_class = c;
	
	dev_post("bach.>= compiled %s %s", __DATE__, __TIME__);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	return 0;
}

void geq_bang(t_geq *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		geq_anything(x, _sym_bang, 0, NULL);
	else
		outlet_int(x->n_ob.l_out[0].b_outlet, x->n_longout);
}

void geq_int(t_geq *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	geq_anything(x, _sym_int, 1, &outatom);
}

void geq_float(t_geq *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	geq_anything(x, _sym_float, 1, &outatom);
}

void geq_anything(t_geq *x, t_symbol *msg, long ac, t_atom *av)
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
			x->n_longout = llll_geq(ll1, ll2);
			llll_release(ll1);
			llll_release(ll2);
			x->n_ob.l_rebuild = 0;
				geq_bang(x);
			break;
		case 1:
			x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1) != NULL;
			break;
	}
}

void geq_assist(t_geq *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll");
		// @in 0 @type llll @digest llll to be compared
		// @in 1 @type llll @digest llll to be compared
	} else 
		sprintf(s, "int: Comparison Result"); // @out 0 @type int @digest Comparison result (0/1)
}

void geq_inletinfo(t_geq *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void geq_free(t_geq *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}


t_geq *geq_new(t_symbol *s, short ac, t_atom *av)
{
	t_geq *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);

	if ((x = (t_geq *) object_alloc_debug(geq_class))) {
		// @arg 0 @name default @optional 1 @digest Default comparison llll

		llllobj_obj_setup((t_llllobj_object *) x, 2, "i");
		if (true_ac) 
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, NULL, true_ac, av, 1);
		
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
