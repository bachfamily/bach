/*
 *  embed.c
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

#include "llll_settheory.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include "ext_critical.h"

typedef struct _embed
{
	struct llllobj_object 	n_ob;

	long				n_proxies;
	void				*n_proxy[LLLL_MAX_INLETS];
	long				n_in;
	
	long				modulo;
	char				group;
	long				num_generators;
	char				count_periodic_subsets_once;
	
	t_llll				*n_embed_return;
} t_embed;


void embed_assist(t_embed *x, void *b, long m, long a, char *s);
void embed_inletinfo(t_embed *x, void *b, long a, char *t);

t_embed *embed_new(t_symbol *s, short ac, t_atom *av);
void embed_free(t_embed *x);

void embed_bang(t_embed *x);
void embed_int(t_embed *x, t_atom_long v);
void embed_float(t_embed *x, double v);
void embed_anything(t_embed *x, t_symbol *msg, long ac, t_atom *av);

void embed_prepare_data(t_embed *x, t_llll *ll);
void embed_retrieve_data(t_embed *x, t_llll *ll, t_llll *idx_ll);
long embed_func(t_embed *x, t_llllelem *a, t_llllelem *b);

t_class *embed_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	c = class_new("bach.embed", (method)embed_new, (method)embed_free, (short)sizeof(t_embed), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)embed_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)embed_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)embed_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)embed_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)embed_bang,		"bang",			0);
	
	class_addmethod(c, (method)embed_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)embed_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	CLASS_ATTR_CHAR(c, "group", 0, t_embed, group); 
	CLASS_ATTR_STYLE_LABEL(c,"group",0,"enumindex","Group");
//	CLASS_ATTR_ENUMINDEX(c,"group", 0, "Transp Transp/Inv Affine Identity Custom"); 
	CLASS_ATTR_ENUMINDEX(c,"group", 0, "Transp Transp/Inv Affine Identity"); 
//	CLASS_ATTR_SAVE(c,"group",0);
	CLASS_ATTR_FILTER_CLIP(c, "group", 0, 3);
//	CLASS_ATTR_FILTER_CLIP(c, "group", 0, 4);
	CLASS_ATTR_BASIC(c,"group",0);

	CLASS_ATTR_LONG(c,"modulo",0, t_embed, modulo);
	CLASS_ATTR_STYLE_LABEL(c,"modulo",0,"text","Modulo");
//	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"modulo",0,"12");
	CLASS_ATTR_FILTER_MIN(c, "modulo", 1);
	CLASS_ATTR_BASIC(c,"modulo",0);

//	CLASS_ATTR_LONG(c, "numgenerators", 0, t_embed, num_generators); 
//	CLASS_ATTR_STYLE_LABEL(c,"numgenerators",0,"text","Number of Generators for Custom Group");
//	CLASS_ATTR_SAVE(c,"numgenerators",0);
//	CLASS_ATTR_FILTER_CLIP(c, "numgenerators", 0, LLLL_MAX_INLETS - 2);

	CLASS_ATTR_CHAR(c, "periodiconce", 0, t_embed, count_periodic_subsets_once); 
	CLASS_ATTR_STYLE_LABEL(c,"periodiconce",0,"onoff","Count Periodic Subsets Once");
//	CLASS_ATTR_SAVE(c,"periodiconce",0);
	CLASS_ATTR_BASIC(c,"periodiconce",0);

	class_register(CLASS_BOX, c);
	embed_class = c;
	
	dev_post("bach.embed compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void embed_bang(t_embed *x)
{	
	if (proxy_getinlet((t_object *) x) != 0)
		embed_anything(x, _sym_bang, 0, NULL);
}

void embed_int(t_embed *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	embed_anything(x, _sym_int, 1, &outatom);
}

void embed_float(t_embed *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	embed_anything(x, _sym_float, 1, &outatom);
}

void embed_anything(t_embed *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in1, *in2;
	long inlet = proxy_getinlet((t_object *) x);
	if (inlet == 0) {
		if (msg != _sym_bang)
			if (!llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0))
				return;
		
		in1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		in2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
		
		if (x->group == k_GROUP_T || x->group == k_GROUP_TI || x->group == k_GROUP_ID || x->group == k_GROUP_AFF) {
			long value = pcset_num_copies(in2, in1, x->modulo, (e_settheory_groups)x->group, x->count_periodic_subsets_once);
			llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 0, value);
		} else if (x->group == k_GROUP_CUSTOM) {
			// sputo
/*			while (true) {
				// sputo
				llllobj_outlet_llll(
			
			} */
		}
		
	} else if (inlet == 1) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1);
		
	} else if (inlet == 2 && ac) {
		x->modulo = atom_getlong(av);
	}
		
/*		in = llll_get();
		systhread_mutex_lock(x->n_ob.l_incache[0].s_lock);
		llll_clone(x->n_ob.l_incache[0].s_ll, in, -1, WHITENULL_llll);
		systhread_mutex_unlock(x->n_ob.l_incache[0].s_lock);
		llll_prepare_embed_data((t_object *) x, in, x->n_ob.l_out[2].b_type | x->n_ob.l_out[3].b_type);
		llll_mergesort(in, &out, (embed_fn) embed_func, x);
		idx_ll = llll_get();
		llll_retrieve_embed_data((t_object *) x, out, idx_ll);
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, idx_ll);			
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out);
		llll_free(idx_ll);
		llll_free(out); */


//	} else if (ac)
//		x->n_embed_return = atom_getlong(av);
}

/*long embed_func(t_embed *x, t_llllelem *a, t_llllelem *b)
{
	t_llll_sort_local *a_data = ((t_llll_sort_item *)a->l_hatom.h_w.w_obj)->n_local_data;
	t_llll_sort_local *b_data = ((t_llll_sort_item *)b->l_hatom.h_w.w_obj)->n_local_data;
	
	if (x->n_ob.l_out[3].b_type == LLLL_O_TEXT)
		outlet_anything(x->n_ob.l_out[3].b_outlet, b_data->n_t_sym, b_data->n_t_ac, b_data->n_t_av);
	else if (x->n_ob.l_out[3].b_type == LLLL_O_NATIVE)
		outlet_anything(x->n_ob.l_out[3].b_outlet, b_data->n_n_sym, 1, b_data->n_n_av);
	
	if (x->n_ob.l_out[2].b_type == LLLL_O_TEXT)
		outlet_anything(x->n_ob.l_out[2].b_outlet, a_data->n_t_sym, a_data->n_t_ac, a_data->n_t_av);
	else if (x->n_ob.l_out[2].b_type == LLLL_O_NATIVE)
		outlet_anything(x->n_ob.l_out[2].b_outlet, a_data->n_n_sym, 1, a_data->n_n_av);
	
	return x->n_embed_return;
}*/

void embed_assist(t_embed *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) sprintf(s, "llll");
		else sprintf(s, "0/1: comparison result");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0:	sprintf(s, "llll (%s): Embeded", type);				break;
			case 1:	sprintf(s, "llll (%s): indices", type);				break;
			case 2:	sprintf(s, "1st term of comparison");	break;
			case 3:	sprintf(s, "2nd term of comparison");	break;
		}
	}
}

void embed_inletinfo(t_embed *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void embed_free(t_embed *x)
{
	long i;
	for (i = 1; i < x->n_proxies; i++)
		object_free_debug(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}


t_embed *embed_new(t_symbol *s, short ac, t_atom *av)
{
	t_embed *x = NULL;
	long i, proxies = 0;
	t_max_err err = MAX_ERR_NONE;
	
	if (llllobj_test())
		return NULL;

	if ((x = (t_embed *) object_alloc_debug(embed_class))) {
//		long true_ac = attr_args_offset(ac, av);

		// default values
		x->group = 1; 
		x->modulo = 12;
		x->num_generators = 0;
		x->count_periodic_subsets_once = true;
		
		attr_args_process(x, ac, av);
		proxies = 1;

		llllobj_obj_setup((t_llllobj_object *) x, 4, "4i");
		
		x->n_proxies = MIN(proxies, LLLL_MAX_INLETS);
		
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
