/*
 *  nth.c
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
 nth.c
 
 @name 
 bach.nth
 
 @realname 
 bach.nth
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Return specific elements of an llll
 
 @description
 Returns one or more specific elements of an llll, based on their addresses.
 
 @discussion
 <o>bach.nth</o>, through its multiple-element syntax, can be used to retrieve a given permutation of an llll.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 element, position, address, retrieve, range, permutation

 @seealso
 bach.pick, bach.subs, bach.insert, bach.replace, bach.lookup, bach.swap
 
 @owner
 Andrea Agostini
 */


#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _nth
{
	t_llllobj_object 	n_ob;
	void				*n_proxy;
	long				n_in;
	long				n_nils;
	long				n_unwrap;
    t_llll              *n_nil;
} t_nth;


void nth_assist(t_nth *x, void *b, long m, long a, char *s);
void nth_inletinfo(t_nth *x, void *b, long a, char *t);

t_nth *nth_new(t_symbol *s, short ac, t_atom *av);
void nth_free(t_nth *x);

void nth_bang(t_nth *x);
void nth_int(t_nth *x, t_atom_long v);
void nth_float(t_nth *x, double v);
void nth_anything(t_nth *x, t_symbol *msg, long ac, t_atom *av);

t_class *nth_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.nth", (method)nth_new, (method)nth_free, (long) sizeof(t_nth), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description
	// In first inlet: the elements at the specified addresses are extracted from the llll and output.<br />
	// In second inlet: the address of the elements to extract.<br />
	// @copy BACH_DOC_ADDRESS_BASIC
	// @copy BACH_DOC_ADDRESS_NEGATIVE
	// @copy BACH_DOC_ADDRESS_MULTIPLE
	// @copy BACH_DOC_ADDRESS_RANGE
	class_addmethod(c, (method)nth_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)nth_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)nth_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)nth_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Repeat last operation
	// @description Returns the requested elements according to the most recently received lllls.
	class_addmethod(c, (method)nth_bang,		"bang",			0);
	
	class_addmethod(c, (method)nth_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)nth_inletinfo,	"inletinfo",	A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "nils",	0,	t_nth, n_nils);
	CLASS_ATTR_FILTER_CLIP(c, "nils", 0, 1);
	CLASS_ATTR_LABEL(c, "nils", 0, "() for Not Found");
	CLASS_ATTR_STYLE(c, "nils", 0, "onoff");
	// @description When set to 1, if no element was present at the requested address <b>[]</b> is output.
	// When set to 0 (default), <b>null</b> is output.
	
	CLASS_ATTR_LONG(c, "unwrap", 0,	t_nth, n_unwrap);
	CLASS_ATTR_LABEL(c, "unwrap", 0, "Unwrap");
	CLASS_ATTR_FILTER_CLIP(c, "unwrap", 0, 1);
	CLASS_ATTR_STYLE(c, "unwrap", 0, "onoff");
	// @description
	// When set to 1, the outermost couple of parentheses of any sublist to be output is removed.
	// For instance, if the llll <b>a b [c d e]</b> is input and its third element is requested,
	// <b>c d e</b> will be output instead of <b>[c d e]</b>.
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	nth_class = c;
	
	dev_post("bach.nth compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void nth_bang(t_nth *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		nth_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void nth_int(t_nth *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	nth_anything(x, _sym_int, 1, &outatom);
}

void nth_float(t_nth *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	nth_anything(x, _sym_float, 1, &outatom);
}

void nth_anything(t_nth *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll, *address, *outll;
	long inlet = proxy_getinlet((t_object *) x);	
	if (inlet == 0) {
		if (msg != _sym_bang) {
			ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
			if (!ll)
				return;
		} else
			ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
		address = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
        outll = llll_nth(ll, address, x->n_nils ? x->n_nil : nullptr);
		if (x->n_unwrap)
			llll_flatten(outll, 1, 0);
		llll_release(ll);
		llll_release(address);
		x->n_ob.l_rebuild = 0;
		llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, outll, 0);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	} else
		x->n_ob.l_rebuild = llllobj_parse_and_store_llll_address((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1, true, true) == MAX_ERR_NONE;
}

void nth_assist(t_nth *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) sprintf(s, "llll"); // @in 0 @type llll @digest llll to retrieve elements from
		else sprintf(s, "llll: Address"); // @in 1 @type llll @digest Address llll
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Retrieved elements
	}
}

void nth_inletinfo(t_nth *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void nth_free(t_nth *x)
{
    llll_free(x->n_nil);
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_nth *nth_new(t_symbol *s, short ac, t_atom *av)
{
	t_nth *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	
	if ((x = (t_nth *) object_alloc_debug(nth_class))) {
		// @arg 0 @name address @optional 1 @type llll @digest Default address
		// @description A default address llll can be set as <o>bach.nth</o>'s argument.
		true_ac = attr_args_offset(ac, av);
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "4");
		if (true_ac)
			llllobj_parse_and_store_llll_address((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac, av, 1, true, true);
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
        x->n_nil = llll_get();
        llll_appendllll(x->n_nil, llll_get());
	} else 
		error(BACH_CANT_INSTANTIATE);		
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
