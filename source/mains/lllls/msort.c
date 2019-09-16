/*
 *  msort.c
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
 msort.c
 
 @name 
 bach.msort
 
 @realname 
 bach.msort
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 deprecated
 
 @digest 
 Flexible sort with monophonic output
 
 @description
 Sorts an llll according to standard or custom criteria, and with a monophonic output.
 
 @discussion
 Object is deprecated. Use <o>bach.sort</o>.
 
 @category
 bach, bach objects, bach llll
 
 @seealso
 bach.sort
 
 @owner
 Andrea Agostini
 */
 
#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _msort
{
	struct llllobj_object 	n_ob;
	void					*n_proxy;
	long					n_in;
	long					n_return;
	long					n_base;
	long					n_order;
	long					n_haslambda;
} t_msort;

void msort_assist(t_msort *x, void *b, long m, long a, char *s);
void msort_inletinfo(t_msort *x, void *b, long a, char *t);

t_msort *msort_new(t_symbol *s, short ac, t_atom *av);
void msort_free(t_msort *x);

void msort_bang(t_msort *x);
void msort_int(t_msort *x, t_atom_long v);
void msort_float(t_msort *x, double v);
void msort_anything(t_msort *x, t_symbol *msg, long ac, t_atom *av);

long msort_func(t_msort *x, t_llllelem *a, t_llllelem *b);

t_class *msort_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.msort", (method)msort_new, (method)msort_free, (short)sizeof(t_msort), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)msort_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)msort_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)msort_float,			"float",		A_FLOAT,	0);
	class_addmethod(c, (method)msort_anything,		"list",			A_GIMME,	0);
	class_addmethod(c, (method)msort_bang,			"bang",			0);
	
	class_addmethod(c, (method)msort_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)msort_inletinfo,		"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_LONG(c, "order",	0, t_msort, n_order);
	CLASS_ATTR_FILTER_CLIP(c, "order", 0, 1);
	CLASS_ATTR_LABEL(c, "order", 0, "Order");
	CLASS_ATTR_ENUMINDEX(c, "order", 0, "Straight Reversed");
	CLASS_ATTR_BASIC(c, "order", 0);
	
	CLASS_ATTR_LONG(c, "base",	0,	t_msort, n_base);
	CLASS_ATTR_LABEL(c, "base", 0, "Base");
	
	class_register(CLASS_BOX, c);
	msort_class = c;
	
	dev_post("bach.msort compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void msort_bang(t_msort *x)
{	
	if (proxy_getinlet((t_object *) x) == 0)
		msort_anything(x, _sym_bang, 0, NULL);
}

void msort_int(t_msort *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	msort_anything(x, _sym_int, 1, &outatom);
}

void msort_float(t_msort *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	msort_anything(x, _sym_float, 1, &outatom);
}

void msort_anything(t_msort *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in, *out, *idx_ll;
	long depth;
	if (proxy_getinlet((t_object *) x) == 0) {
		
		if (msg != _sym_bang) {
			in = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
			if (!in)
				return;
		} else
			in = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		depth = in->l_depth;
		llll_prepare_sort_data((t_object *) x, in, NULL, x->n_ob.l_out[2].b_type);
		llll_mergesort(in, &out, (sort_fn) msort_func, x);
		idx_ll = llll_get();
		llll_retrieve_sort_data((t_object *) x, out, idx_ll, depth);
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, idx_ll);
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out);
		llll_free(idx_ll);
		llll_free(out);
	} else {
		if (msg == LLLL_NATIVE_MSG) {
			t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
			if (lambda_llll) {
				if (lambda_llll->l_size)
					x->n_return = hatom_getlong(&lambda_llll->l_head->l_hatom);
				else
					x->n_return = 0;
				llll_free(lambda_llll);
			} else
				x->n_return = 0;
		} else
			x->n_return = ac ? atom_getlong(av) : 0;
		x->n_haslambda = 1;
	}
}

long msort_func(t_msort *x, t_llllelem *a, t_llllelem *b)
{
	t_llll_sort_item *a_item = (t_llll_sort_item *)(a->l_hatom.h_w.w_obj);
	t_llll_sort_item *b_item = (t_llll_sort_item *)(b->l_hatom.h_w.w_obj);
	t_llll_sort_item *swap;
	
	if (x->n_order) {
		swap = a_item;
		a_item = b_item;
		b_item = swap;
	}
	
	x->n_haslambda = 0;
    
    switch (x->n_ob.l_out[2].b_type) {
        case LLLL_O_TEXT:
            outlet_int(x->n_ob.l_out[3].b_outlet, x->n_base + 1);
            outlet_anything_prudent(x->n_ob.l_out[2].b_outlet, b_item->n_t_sym, b_item->n_t_ac, b_item->n_t_av);
            outlet_int(x->n_ob.l_out[3].b_outlet, x->n_base);
            outlet_anything_prudent(x->n_ob.l_out[2].b_outlet, a_item->n_t_sym, a_item->n_t_ac, a_item->n_t_av);
            break;
        case LLLL_O_MAX:
            outlet_int(x->n_ob.l_out[3].b_outlet, x->n_base + 1);
            outlet_anything_prudent(x->n_ob.l_out[2].b_outlet, b_item->n_m_sym, b_item->n_m_ac, b_item->n_m_av);
            outlet_int(x->n_ob.l_out[3].b_outlet, x->n_base);
            outlet_anything_prudent(x->n_ob.l_out[2].b_outlet, a_item->n_m_sym, a_item->n_m_ac, a_item->n_m_av);
            break;
        case LLLL_O_NATIVE:
            outlet_anything(x->n_ob.l_out[2].b_outlet, b_item->n_n_sym, 1, b_item->n_n_av);
            break;
        default:
            break;
    }
	
	if (!x->n_haslambda)
		return llll_leq(a_item->n_this_by, b_item->n_this_by);
	else
		return x->n_return;
}

void msort_assist(t_msort *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) sprintf(s, "llll");
		else sprintf(s, "llll: Lambda Inlet");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0:	sprintf(s, "llll (%s): Sorted", type);		break;
			case 1:	sprintf(s, "llll (%s): indices", type);	break;
			case 2:	sprintf(s, "llll (%s): Lambda Outlet 1", type);	break;
			case 3:	sprintf(s, "llll (%s): Lambda Outlet 2", type);	break;
		}
	}
}

void msort_inletinfo(t_msort *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void msort_free(t_msort *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}


t_msort *msort_new(t_symbol *s, short ac, t_atom *av)
{
	t_msort *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_msort *) object_alloc_debug(msort_class))) {
		object_warn((t_object *) x, "bach.msort is deprecated. Please replace me with bach.sort!");
		x->n_base = true_ac ? atom_getlong(av) : LLLL_IDX_BASE;
		
		attr_args_process(x, ac, av);

		llllobj_obj_setup((t_llllobj_object *) x, 1, "i444");

		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
