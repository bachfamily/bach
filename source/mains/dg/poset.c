/*
 *  poset.c
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
 poset.c
 
 @name 
 bach.poset
 
 @realname 
 bach.poset
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Partially ordered sets
 
 @description
 Represents a lattice as a partially ordered set, both as edge list and as adjacency list.
 
 @discussion

 @category
 bach, bach objects, bach llll
 
 @keywords
 set, order, partial, lattice, diagram

 @seealso
 bach.&gt;, bach.&lt;, bach.&gt;=, bach.&lt;=
 
 @owner
 Daniele Ghisi
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "llll_commons_ext.h"

typedef struct _poset
{
	struct llllobj_object 	n_ob;
	void					*n_proxy[3];
	long					n_in;
	long					n_result;
	long					n_haslambda;
	t_llll					*n_empty;
} t_poset;

void poset_assist(t_poset *x, void *b, long m, long a, char *s);
void poset_inletinfo(t_poset *x, void *b, long a, char *t);

t_poset *poset_new(t_symbol *s, short ac, t_atom *av);
void poset_free(t_poset *x);

void poset_bang(t_poset *x);
void poset_int(t_poset *x, t_atom_long v);
void poset_float(t_poset *x, double v);
void poset_anything(t_poset *x, t_symbol *msg, long ac, t_atom *av);

long poset_func(t_poset *x, t_llllelem *what1, t_llllelem *what2);

t_class *poset_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.poset", (method)poset_new, (method)poset_free, (short)sizeof(t_poset), 0L, A_GIMME, 0);
	
	// @method llll @digest Store data and compute poset
	// @description
	// In first inlet: the llll in the right inlet is intersected with the edge list and adjacency list are output
	// respectively from first and second outlet.<br />
	// In second inlet: the llll is converted into an int

	class_addmethod(c, (method)poset_anything,	"anything",		A_GIMME,	0);
	
	// @method int @digest Lambda inlet
	// @description Second inlet is a lambda inlet. <br /> 
	// @copy BACH_DOC_LAMBDA_INLET_ORDER
	class_addmethod(c, (method)poset_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)poset_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)poset_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the last operation
	// @description Returns the poset of the most recently received lllls. 
	class_addmethod(c, (method)poset_bang,		"bang",			0);
	
	class_addmethod(c, (method)poset_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)poset_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	poset_class = c;
	
	dev_post("bach.poset compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void poset_bang(t_poset *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		poset_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 3);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 2);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void poset_int(t_poset *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	poset_anything(x, _sym_int, 1, &outatom);
}

void poset_float(t_poset *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	poset_anything(x, _sym_float, 1, &outatom);
}

long poset_default_func(t_poset *x, t_llllelem *what1, t_llllelem *what2)
{
	return llll_leq_elem(x, what1, what2);
}

void poset_anything(t_poset *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inll, *out_edges, *out_adjacency, *out_minima, *out_maxima;
	long inlet = proxy_getinlet((t_object *) x);
	x->n_result = 0;
	
	switch (inlet) {
		case 0:
			if (msg != _sym_bang) {
				inll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
				if (!inll)
					return;
			} else
				inll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
			
			x->n_haslambda = 0;
			if (inll->l_size)
				llllobj_test_lambda_loop_two_outs((t_object *) x, LLLL_OBJ_VANILLA, inll->l_head, inll->l_head, 4, 5);		
			
			if (x->n_haslambda) {
				llll_poset(inll, (poset_fn) poset_func, x, &out_edges, &out_adjacency, &out_minima, &out_maxima);
			} else
				llll_poset(inll, (poset_fn) poset_default_func, x, &out_edges, &out_adjacency, &out_minima, &out_maxima);
			
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, out_maxima, 3);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, out_minima, 2);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, out_adjacency, 1);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, out_edges, 0);
			x->n_ob.l_rebuild = 0;
			poset_bang(x);		
			break;
		case 1:
			if (msg == LLLL_NATIVE_MSG) {
				t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
				if (lambda_llll) {
					if (lambda_llll->l_size)
						x->n_result = hatom_getlong(&lambda_llll->l_head->l_hatom);
					else
						x->n_result = 0;
					llll_free(lambda_llll);
				} else
					x->n_result = 0;
			} else
				x->n_result = ac ? atom_getlong(av) : 0;
			x->n_haslambda = 1;
			break;
	}
}

long poset_func(t_poset *x, t_llllelem *what1, t_llllelem *what2)
{
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 5, what2->l_thing.w_llll);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 4, what1->l_thing.w_llll);
	return x->n_result;
}

void poset_assist(t_poset *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:	sprintf(s, "llll");	break; // @in 0 @type llll @digest llll to order
			case 1: sprintf(s, "llll: Lambda Input");	break; // @in 1 @type int/llll @digest Lambda inlet 
				// @description @copy BACH_DOC_LAMBDA_INLET_ORDER
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0:	sprintf(s, "llll (%s): Lattice Edges", type);	break;	// @out 0 @type llll @digest Edges of the lattices
																			// @description Each edge is an element in the form <b>[<m>A</m> <m>B</m>]</b>
																			// where <m>A</m> and <m>B</m> are the elements respectively at the beginning
																			// and at the end of the edge
			case 1:	sprintf(s, "llll (%s): Adjacency List", type);	break;	// @out 1 @type llll @digest Adjacency list 
																			// @description Each element has the form <b>[<m>A</m> <m>B1</m> <m>B2</m>...]</b>
																			// where all the <m>Bi</m> are the elements to which <m>A</m> is connected.
			case 2:	sprintf(s, "llll (%s): Minima", type);	break;	// @out 2 @type llll @digest Lattice minima 
			case 3:	sprintf(s, "llll (%s): Maxima", type);	break;	// @out 3 @type llll @digest Lattice maxima 
			case 4:	sprintf(s, "llll (%s): Lambda Outlet 1", type);	break; // @out 4 @type llll @digest First lambda outlet 
				// @description @copy BACH_DOC_LAMBDA_OUTLET_ORDER
			case 5:	sprintf(s, "llll (%s): Lambda Outlet 2", type);	break; // @out 5 @type llll @digest Second lambda outlet 
				// @description @copy BACH_DOC_LAMBDA_OUTLET_ORDER
		}
	}
}

void poset_inletinfo(t_poset *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void poset_free(t_poset *x)
{
	long i;
	for (i = 1; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llll_free(x->n_empty);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_poset *poset_new(t_symbol *s, short ac, t_atom *av)
{
	t_poset *x = NULL;
	long i;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_poset *) object_alloc_debug(poset_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "444444");
		for (i = 1; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		x->n_empty = llll_get();
	} else
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
