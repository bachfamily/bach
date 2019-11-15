/*
 *  cartesianprod.c
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
 cartesianprod.c
 
 @name 
 bach.cartesianprod
 
 @realname 
 bach.cartesianprod
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Cartesian product
 
 @description
 <o>bach.cartesianprod</o> returns the cartesian product of two or more lllls.
 
 @category
 bach, bach objects, bach llll

 @keywords
 set, cartesian product, product, combination, couple, combine

 @seealso
 bach.comb, bach.perm, bach.trans, bach.constraints
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _cartesianprod
{
	struct llllobj_object 	n_ob;
	long				n_proxies;
	void				**n_proxy;
	long				n_in;
} t_cartesianprod;


void cartesianprod_assist(t_cartesianprod *x, void *b, long m, long a, char *s);
void cartesianprod_inletinfo(t_cartesianprod *x, void *b, long a, char *t);

t_cartesianprod *cartesianprod_new(t_symbol *s, short ac, t_atom *av);
void cartesianprod_free(t_cartesianprod *x);

void cartesianprod_bang(t_cartesianprod *x);
void cartesianprod_int(t_cartesianprod *x, t_atom_long v);
void cartesianprod_float(t_cartesianprod *x, double v);
void cartesianprod_anything(t_cartesianprod *x, t_symbol *msg, long ac, t_atom *av);

t_class *cartesianprod_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.cartesianprod", (method)cartesianprod_new, (method)cartesianprod_free, (long) sizeof(t_cartesianprod), 0L, A_GIMME, 0);
	
	// @method llll @digest Return the cartesian product
	// @description
	// The cartesian product of the llll and the lllls in the other inlets is computed.
	// An llll received in the first inlet also causes the cartesian product to be output.
	class_addmethod(c, (method)cartesianprod_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)cartesianprod_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)cartesianprod_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)cartesianprod_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description The cartesian product of the most recently received lllls is output.
	class_addmethod(c, (method)cartesianprod_bang,		"bang",			0);
	
	class_addmethod(c, (method)cartesianprod_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)cartesianprod_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	cartesianprod_class = c;
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	dev_post("bach.cartesianprod compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void cartesianprod_bang(t_cartesianprod *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		cartesianprod_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void cartesianprod_int(t_cartesianprod *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	cartesianprod_anything(x, _sym_int, 1, &outatom);
}

void cartesianprod_float(t_cartesianprod *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	cartesianprod_anything(x, _sym_float, 1, &outatom);
}

void cartesianprod_anything(t_cartesianprod *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_lllls[LLLL_MAX_INLETS];
	long inlet = proxy_getinlet((t_object *) x);
	long count = x->n_proxies + 1;
	long i;
	t_llll *prod;
	
	if (inlet == 0) {
		if (msg != _sym_bang) {
			if ((in_lllls[0] = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0)) == NULL)
				return;
		} else
			in_lllls[0] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
		for (i = 1; i < count; i++) {
			in_lllls[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 0);
		}
		prod = llll_cartesianprod(in_lllls, count);
		for (i = 0; i < count; i++) {
			llll_release(in_lllls[i]);
		}
		x->n_ob.l_rebuild = 0;
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, prod, 0);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0); // this will output the llll that has been loaded for the first outlet
	} else {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		x->n_ob.l_rebuild = 1;
	}
}


void cartesianprod_assist(t_cartesianprod *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll %ld", a + 1); // @in 0 @loop 1 @type llll @digest Factor llll
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Cartesian product
	}
}

void cartesianprod_inletinfo(t_cartesianprod *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void cartesianprod_free(t_cartesianprod *x)
{
	long i;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	bach_freeptr(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_cartesianprod *cartesianprod_new(t_symbol *s, short ac, t_atom *av)
{
	t_cartesianprod *x = NULL;
	long i, lists, proxies;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_cartesianprod *) object_alloc_debug(cartesianprod_class))) {
		// @arg 0 @name count @optional 1 @type int @digest Number of input lllls
		// @description The number of lllls to be multiplied. Inlets are created accordingly.
		
  		lists = (true_ac && atom_gettype(av) == A_LONG) ? atom_getlong(av) : 2; // one for each list (plus one standard input for ctl inlet)
		proxies = lists - 1;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, lists, "4");
		x->n_proxies = MIN(proxies, LLLL_MAX_INLETS);
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof(void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
