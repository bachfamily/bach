/*
 *  pack.c
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
 pack.c
 
 @name 
 bach.pack
 
 @realname 
 bach.pack
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Assemble an llll with keyed sublists
 
 @description
 Assembles an llll to be parsed by <o>bach.keys</o>.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 key, router, assemble, sublist

 @seealso
 bach.keys, bach.join
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _pack
{
	struct llllobj_object	n_ob;
	long					n_proxies;
	void					**n_proxy;
	t_hatom					*n_keys;
	long					n_nullmode;
	long					n_triggers[LLLL_MAX_INLETS];
	long					n_ntriggers;
	long					n_in;
    t_llll                  *n_prepend;
    t_llll                  *n_append;
	t_bach_atomic_lock		n_lock;
} t_pack;


void pack_assist(t_pack *x, void *b, long m, long a, char *s);
void pack_inletinfo(t_pack *x, void *b, long a, char *t);

t_pack *pack_new(t_symbol *s, short ac, t_atom *av);
void pack_free(t_pack *x);

void pack_bang(t_pack *x);
void pack_int(t_pack *x, t_atom_long v);
void pack_float(t_pack *x, double v);
void pack_anything(t_pack *x, t_symbol *msg, long ac, t_atom *av);
long pack_ishot(t_pack *x, long inlet);

t_class *pack_class;

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_pack, n_prepend, pack_prepend_attr_get)
DEFINE_LLLL_ATTR_DEFAULT_SETTER(t_pack, n_prepend, pack_prepend_attr_set)

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_pack, n_append, pack_append_attr_get)
DEFINE_LLLL_ATTR_DEFAULT_SETTER(t_pack, n_append, pack_append_attr_set)

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.pack", (method)pack_new, (method)pack_free, (short)sizeof(t_pack), 0L, A_GIMME, 0);
	
	// @method llll @digest Add the key to the llll 
	// @description
	// The key specified for the inlet will be prepended to the llll,
	// and the llll will be joined to the others, according to the position of the inlet.
	// If a <b>null</b> is received and the <m>nullmode</m> attribute is set to 1, the corresponding sublist will not be added to the output llll.
	// If the inlet is marked as "hot" by the <m>triggers</m> attribute, the resulting llll is output.
	class_addmethod(c, (method)pack_anything,	"anything",		A_GIMME,	0);
	class_addmethod(c, (method)pack_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)pack_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)pack_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description A bang will cause the assembled llll to be output.
	class_addmethod(c, (method)pack_bang,		"bang",			0);
	
	class_addmethod(c, (method)pack_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)pack_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	CLASS_ATTR_LONG(c, "nullmode",		0,	t_pack, n_nullmode);
	CLASS_ATTR_LABEL(c, "nullmode",		0, "Null Mode");	
	CLASS_ATTR_STYLE(c, "nullmode",		0, "onoff");
	// @description When set to 1, an empty inlet will not concour to the formation of the output llll.
	
	CLASS_ATTR_LONG_VARSIZE(c, "triggers",	0,	t_pack, n_triggers, n_ntriggers, LLLL_MAX_INLETS);
	CLASS_ATTR_LABEL(c, "triggers", 0, "Triggers");
	CLASS_ATTR_FILTER_CLIP(c, "triggers", -1, LLLL_MAX_INLETS);
	// @description A list setting which inlets are "hot" (i.e., which will will trigger the result).
	// <m>-1</m> means all inlets are hot. No arguments mean all inlets are cold. Default is 1.
	
    CLASS_ATTR_LLLL(c, "prepend", 0, t_pack, n_prepend, pack_prepend_attr_get, pack_prepend_attr_set);
    CLASS_ATTR_LABEL(c, "prepend", 0, "Items To Prepend");
    // @description An optional llll to be prepended at the beginning of the llll
    // resulting from the assemblage of the specified keys.
    
    CLASS_ATTR_LLLL(c, "append", 0, t_pack, n_append, pack_append_attr_get, pack_append_attr_set);
    CLASS_ATTR_LABEL(c, "append", 0, "Items To Append");
    // @description An optional llll to be appended at the end of the llll
    // resulting from the assemblage of the specified keys.
	class_register(CLASS_BOX, c);
	pack_class = c;
	
	dev_post("bach.pack compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void pack_bang(t_pack *x)
{	
	if (x->n_ob.l_rebuild)
		pack_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void pack_int(t_pack *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	pack_anything(x, _sym_int, 1, &outatom);
}

void pack_float(t_pack *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	pack_anything(x, _sym_float, 1, &outatom);
}

void pack_anything(t_pack *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_ll;
	long i;
	long inlet = proxy_getinlet((t_object *) x);
	
	if (msg != _sym_bang) {
		in_ll = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		if (!in_ll)
			return;
		x->n_ob.l_rebuild = 1;
	}
	if (pack_ishot(x, inlet)) {
		t_llll *out_ll = llll_get();
		for (i = 0; i <= x->n_proxies; i++) {
			t_llll *stored_ll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i);
			if (stored_ll->l_size == 0 && x->n_nullmode) {
				llll_release(stored_ll);
				continue;
			}
			t_llll *cloned_ll = llll_clone(stored_ll);
			llll_release(stored_ll);
			if (x->n_keys[i].h_type != H_NULL)
				llll_prependhatom(cloned_ll, x->n_keys + i, 0, WHITENULL_llll);
			llll_appendllll(out_ll, cloned_ll, 0, WHITENULL_llll);
		}
        
        if (x->n_prepend) {
            t_llll *first = llll_clone(x->n_prepend);
            t_llll *second = out_ll;
            llll_chain(first, second);
            out_ll = first;
        }
        if (x->n_append) {
            t_llll *second = llll_clone(x->n_append);
            llll_chain(out_ll, second);
        }
        
		x->n_ob.l_rebuild = 0;
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, out_ll, 0);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void pack_assist(t_pack *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (x->n_keys[a].h_type) {
			case H_LONG:	sprintf(s, "llll for Key " ATOM_LONG_PRINTF_FMT, x->n_keys[a].h_w.w_long);	break;
			case H_DOUBLE:	sprintf(s, "llll for Key %f", x->n_keys[a].h_w.w_double);		break;
			case H_SYM:		sprintf(s, "llll for Key %s", x->n_keys[a].h_w.w_sym->s_name);	break;
			case H_NULL:	sprintf(s, "llll Without Key");	break;
		}
		// @in 0 @loop 1 @type llll @digest llll to become a keyed sublist
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "Packed llll (%s)", type);
		// @out 0 @type llll @digest Assembled llll
	}
}


long pack_ishot(t_pack *x, long inlet)
{
	long hot = 0, i;
	bach_atomic_lock(&x->n_lock);
	if (x->n_ntriggers == 0)
		hot = inlet == 0;
	else {
		for (i = 0; !hot && i < x->n_ntriggers; i++)
			if (x->n_triggers[i] < 1 || x->n_triggers[i] == inlet + 1)
				hot = 1;
	}
	bach_atomic_unlock(&x->n_lock);
	return hot;
}

void pack_inletinfo(t_pack *x, void *b, long a, char *t)
{
	*t = !pack_ishot(x, a);
}


void pack_free(t_pack *x)
{
	long i;
	bach_freeptr(x->n_keys);
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
    llll_free(x->n_prepend);
    llll_free(x->n_append);
	bach_freeptr(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_pack *pack_new(t_symbol *s, short ac, t_atom *av)
{
	t_pack *x = NULL;
	long i;
	t_max_err err = 0;
	long true_ac;
	true_ac = MIN(attr_args_offset(ac, av), LLLL_MAX_OUTLETS - 1);
	
	if ((x = (t_pack *) object_alloc_debug(pack_class))) {
		// @arg 0 @name keys @type anything @digest Keys
		// @description The keys to prepend to each incoming llll.
		// If a key is set to <b>null</b>, nothing will be prepended 
		// and the incoming llll will be simply wrapped and prepended to the output llll.
		if (!true_ac) {
			object_error((t_object *) x, "Missing arguments");
			object_free_debug((t_object *) x);
			return NULL;
		}
		x->n_ntriggers = 1;
		x->n_triggers[0] = 1;
		attr_args_process(x, ac, av);
		CLIP_ASSIGN(true_ac, 1, LLLL_MAX_INLETS);
		x->n_proxies = true_ac - 1;
		x->n_keys = (t_hatom *) bach_newptr(true_ac * sizeof(t_hatom));
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
		llllobj_obj_setup((t_llllobj_object *) x, true_ac, "4");
		for (i = true_ac - 1; i >= 0; i--) {
			if (atom_getsym(av + i) == _llllobj_sym_null) {
				x->n_keys[i].h_type = H_NULL;
			} else {
				hatom_setatom(x->n_keys + i, av + i);
			}
		}
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		x->n_ob.l_rebuild = 1;
	} else
		object_error((t_object *) x, "Missing arguments");

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
