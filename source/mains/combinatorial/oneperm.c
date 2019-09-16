/*
 *  oneperm.c
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
 oneperm.c
 
 @name 
 bach.oneperm
 
 @realname 
 bach.oneperm
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 deprecated
 
 @digest 
 Returns next permutation
  
 @description
 Returns the next permutation of an llll.
 
 @discussion
 Object is deprecated. Use <o>bach.perm</o> with <m>maxcount</m> 1.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 permutation, next

 @seealso
 bach.perm
 
 @owner
 Andrea Agostini
 */
 
 
#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _oneperm
{
	struct llllobj_object 	n_ob;
	long				n_order;
	long				n_circular;
} t_oneperm;


void oneperm_assist(t_oneperm *x, void *b, long m, long a, char *s);
void oneperm_inletinfo(t_oneperm *x, void *b, long a, char *t);

t_oneperm *oneperm_new(t_symbol *s, short ac, t_atom *av);
void oneperm_free(t_oneperm *x);

void oneperm_bang(t_oneperm *x);
void oneperm_int(t_oneperm *x, t_atom_long v);
void oneperm_float(t_oneperm *x, double v);
void oneperm_anything(t_oneperm *x, t_symbol *msg, long ac, t_atom *av);

t_class *oneperm_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	
	c = class_new("bach.oneperm", (method)oneperm_new, (method)oneperm_free, (short)sizeof(t_oneperm), 0L, A_GIMME, 0);
	
	CLASS_ATTR_LONG(c, "order",	0,	t_oneperm, n_order);
	CLASS_ATTR_LABEL(c, "order", 0, "Order");
	CLASS_ATTR_FILTER_CLIP(c, "order", 0, 1);
	CLASS_ATTR_BASIC(c, "order", 0);	
	
	CLASS_ATTR_LONG(c, "circular",	0,	t_oneperm, n_circular);
	CLASS_ATTR_FILTER_CLIP(c, "circular", 0, 1);
	CLASS_ATTR_LABEL(c, "circular", 0, "Circular");
	CLASS_ATTR_STYLE(c, "circular", 0, "onoff");
	
	class_addmethod(c, (method)oneperm_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)oneperm_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)oneperm_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)oneperm_anything,		"list",			A_GIMME,	0);
	class_addmethod(c, (method)oneperm_bang,			"bang",			0);
	
	class_addmethod(c, (method)oneperm_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)oneperm_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	oneperm_class = c;
	
	dev_post("bach.oneperm compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void oneperm_bang(t_oneperm *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		oneperm_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void oneperm_int(t_oneperm *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	oneperm_anything(x, _sym_int, 1, &outatom);
}

void oneperm_float(t_oneperm *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	oneperm_anything(x, _sym_float, 1, &outatom);
}

void oneperm_anything(t_oneperm *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll;
	if (msg != _sym_bang) {
		ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} else
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);

	x->n_ob.l_rebuild = 0;
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_oneperm(ll, x->n_order, x->n_circular), 0);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void oneperm_assist(t_oneperm *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type);
	}
}

void oneperm_inletinfo(t_oneperm *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void oneperm_free(t_oneperm *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_oneperm *oneperm_new(t_symbol *s, short ac, t_atom *av)
{
	t_oneperm *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_oneperm *) object_alloc_debug(oneperm_class))) {
		object_warn((t_object *) x, "bach.oneperm is deprecated. Please replace me with bach.perm @maxcount 1");
		if (true_ac)
			x->n_order = atom_getlong(av);
		if (true_ac > 1)
			x->n_circular = atom_getlong(av + 1);
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
