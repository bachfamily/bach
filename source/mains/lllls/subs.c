/*
 *  subs.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
 subs.c
 
 @name 
 bach.subs
 
 @realname 
 bach.subs
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Replace or remove elements in an llll
 
 @description
 Replaces or removes elements at specified addresses of an llll.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 substitute, modify, replace, remove, delete, element

 @seealso
 bach.insert, bach.replace, bach.find, bach.nth, bach.swap
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"


typedef struct _subs
{
	t_llllobj_object	n_ob;
	long				n_multi;
	t_llll				*n_sizes;
	void				*n_proxy[3];
	t_bach_atomic_lock	n_lock;
	long				n_in;
} t_subs;

void subs_assist(t_subs *x, void *b, long m, long a, char *s);
void subs_inletinfo(t_subs *x, void *b, long a, char *t);

t_subs *subs_new(t_symbol *s, short ac, t_atom *av);
void subs_free(t_subs *x);

void subs_bang(t_subs *x);
void subs_int(t_subs *x, t_atom_long v);
void subs_float(t_subs *x, double v);
void subs_anything(t_subs *x, t_symbol *msg, long ac, t_atom *av);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_subs, n_sizes, subs_getattr_sizes);
t_max_err subs_setattr_sizes(t_subs *x, t_object *attr, long ac, t_atom *av);
t_max_err subs_setattr_set(t_subs *x, t_object *attr, long ac, t_atom *av);

t_class *subs_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.subs", (method)subs_new, (method)subs_free, (long) sizeof(t_subs), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description
	// In first inlet: the elements received in the third inlet will be substituted in the llll. <br />
	// In second inlet: the address of the elements to be replaced.
	// The syntax depends on the value of the <m>multi</m> attribute:
	// if it is 0, a single address is expected; if it is 1, an llll whose sublists are separate addresses, at which separate substitutions have to be performed, is expected.
	// If single elements at the root level are encountered, they are treated as single-element sublist.
	// This means that in the multiple substitutions case the lllls <b>[1] [2 3] [4] [5]</b> and <b>1 [2 3] 4 [5]</b> are considered the same,
	// and in both cases four substitutions are performed.
	// Both positive and negative addresses are correctly treated, 
	// but the result can be hardly predictable when multiple substitutions are performed mixing positive and negative addresses on a single sublist. <br />
	// @copy BACH_DOC_ADDRESS_BASIC
	// If the address points to a non-existing positions, the necessary elements will be created as empty sublists whenever possible.
	// Impossible substitutions are ignored.
	// In third inlet: the elements to substitute to the existing ones.
	// The exact syntax depends on the value of the <m>multi</m> attribute:
	// if it is 0, a single sequence of elements is expected;
	// if it is 1, an llll whose sublists are separate sequence of elements, each to be inserted at the corresponding given address, is expected.
	// If single elements at the root level are encountered, they are treated as single-element sublist.
	// This means that in the multiple substitutions case the lllls <b>[a] [b c] [d] [e]</b> and <b>a [b c] d [e]</b> are considered the same.
	// If less replacement sequences than addresses are provided, the last sequence is repeated over and over. 
	// This is especially useful to substitute the same sequence at many addresses, as providing the sequence only once is enough.
	// If more sequences than addresses are provided, the exceeding sequences are ignored.
	// In any case, an empty sequence (that is, <b>null</b> if the <m>multi</m> attribute is 0, or an empty sublist otherwise)
	// causes the elements pointed by the corresponding address to be removed.
	class_addmethod(c, (method)subs_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)subs_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)subs_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)subs_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description Perform the substitution with the most recently received lllls.
	class_addmethod(c, (method)subs_bang,		"bang",			0);
	
	class_addmethod(c, (method)subs_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)subs_inletinfo,	"inletinfo",	A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "multi",	0,	t_subs, n_multi);
	CLASS_ATTR_STYLE_LABEL(c, "multi", 0, "onoff", "Multiple Substitutions");
	CLASS_ATTR_FILTER_CLIP(c, "multi", 0, 1);
	CLASS_ATTR_BASIC(c, "multi", 0);		
	// @description
	// When set to 1, multiple substitutions can be performed.
	// This changes the syntax for the second and third inlets - see the description of the <m>llll</m> message.
	
	CLASS_ATTR_LLLL(c, "sizes", 0, t_subs, n_sizes, subs_getattr_sizes, subs_setattr_sizes);
	CLASS_ATTR_LABEL(c, "sizes", 0, "Sizes");
	// @description
	// The number of consecutive elements that have to be removed by the original list, to be replaced by one sequence. Defaults to 1.
	// When set to 0 for a given substitution, the number of removed elements will match the size of the replacement sequence.
	// A value for each substitution is expected. However, if less values than addresses are provided, the last value is repeated over and over.
	
	CLASS_ATTR_LLLL(c, "set", 0, t_subs, n_ob, NULL, subs_setattr_set); // struct field is dummy
	CLASS_ATTR_INVISIBLE(c, "set", ATTR_GET_OPAQUE);
	// @description
	// The <m>set</m> attribute allows setting the insertion elements.
	// This is especially useful when used in the object box.

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	
	
	class_register(CLASS_BOX, c);
	subs_class = c;
	
	dev_post("bach.subs compiled %s %s", __DATE__, __TIME__);
	
	return;
}

t_max_err subs_setattr_sizes(t_subs *x, t_object *attr, long ac, t_atom *av)
{
	if (ac == 0 || av) {
		t_llll *ll, *freeme;
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, av))) {
			t_llllelem *elem;
			t_bool good;
			if (ll->l_depth > 1) {
				object_error((t_object *) x, "Bad sizes llll");
				llll_free(ll);
				return MAX_ERR_NONE;
			}
			for (elem = ll->l_head, good = true; elem && good; elem = elem->l_next) {
                good = hatom_is_number(&elem->l_hatom);
			}
			if (!good) {
				object_error((t_object *) x, "Bad sizes llll");
				llll_free(ll);
				return MAX_ERR_NONE;
			}
			bach_atomic_lock(&x->n_lock);
			freeme = x->n_sizes;
			x->n_sizes = ll;
			bach_atomic_unlock(&x->n_lock);
			llll_free(freeme);
		}
	}
	return MAX_ERR_NONE;
}

t_max_err subs_setattr_set(t_subs *x, t_object *attr, long ac, t_atom *av)
{
	if ((ac == 0 || av) && x->n_ob.l_running) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, 2);
	}
	return MAX_ERR_NONE;
}

void subs_bang(t_subs *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		subs_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void subs_int(t_subs *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	subs_anything(x, _sym_int, 1, &outatom);
}

void subs_float(t_subs *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	subs_anything(x, _sym_float, 1, &outatom);
}

void subs_anything(t_subs *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll, *address, *model, *sizes, *clonedsizes;
	
	switch (proxy_getinlet((t_object *) x)) {
		case 0:
            if (msg != _sym_bang) {
                ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
                if (!ll)
                    return;
            } else
                ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
            bach_atomic_lock(&x->n_lock);
            sizes = x->n_sizes;
            llll_retain(sizes);
            bach_atomic_unlock(&x->n_lock);
            clonedsizes = llll_clone(sizes);
            llll_release(sizes);
            if (x->n_multi == 0) {
                address = llll_get();
                llll_appendllll(address, llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1), 0, WHITENULL_llll);
                model = llll_get ();
                llll_appendllll(model, llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 2, 1), 0, WHITENULL_llll);
            } else {
                address = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
                model = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 2, 1);			
            }
            llll_multisubs(ll, address, model, clonedsizes);
            x->n_ob.l_rebuild = 0;
            llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
			break;
			
		case 1: 
			llllobj_parse_and_store_llll_address((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1, true, false);
			x->n_ob.l_rebuild = 1;
			break;
			
		case 2: 
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 2);
			x->n_ob.l_rebuild = 1;
			break;
	}
}

void subs_assist(t_subs *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "llll");					break; // @in 0 @type llll @digest llll to edit
			case 1: sprintf(s, "llll: Address");		break; // @in 1 @type llll @digest Addresses
			case 2: sprintf(s, "llll: Replacement");	break; // @in 2 @type llll @digest Replacement elements
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest llll with the substitution performed
	}
}

void subs_inletinfo(t_subs *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void subs_free(t_subs *x)
{
	long i;
	llll_free(x->n_sizes);
	for (i = 2; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_subs *subs_new(t_symbol *s, short ac, t_atom *av)
{
	t_subs *x = NULL;
	long i;
	t_max_err err = 0;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);

	if ((x = (t_subs *) object_alloc_debug(subs_class))) {
		// @arg 0 @name address @optional 1 @type llll @digest Default replacement address
		// @description The initial address or addresses at which the substitution must be performed
		x->n_sizes = llll_get();
		llll_appendlong(x->n_sizes, 1, 0, WHITENULL_llll);
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 3, "4");
		if (true_ac)
			llllobj_parse_and_store_llll_address((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac, av, 1, true, false);
		for (i = 2; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		attr_args_process(x, ac, av);
        t_llll *address = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
        if (address->l_size == 0) {
            t_llll *new_address = llll_get();
            llll_appendlong(new_address, 1);
            llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, new_address, 1);
        }
        llll_release(address);
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
