/*
 *  keys.c
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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
 keys.c
 
 @name 
 bach.keys
 
 @realname 
 bach.keys
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Route an llll according to specific keys
 
 @description
 Routes an llll and its sublists according to specific keys.
 
 @discussion
 The usefulness of <o>bach.keys</o> is twofold:
 it allows treating an llll as an associative array, and it allows routing lllls based upon their first elements.
 It is very commonly used in conjunction with <o>bach.score</o> and <o>bach.roll</o>'s slots,
 as well as in <o>bach.constraint</o>'s lambda loop.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 key, router, route, sublist, element, retrieve

 @seealso
 bach.find, bach.keychain, bach.score, bach.roll, bach.constraints
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _keys
{
	struct llllobj_object	n_ob;
	
	t_hatom					*n_keys;
	long					*n_exists;
	
	long					n_mindepth;
	long					n_maxdepth;
	long					n_depthreject;
	long					n_nullmode;
	long					n_keep;
	t_llll					*n_empty;
} t_keys;


void keys_assist(t_keys *x, void *b, long m, long a, char *s);
void keys_inletinfo(t_keys *x, void *b, long a, char *t);

t_keys *keys_new(t_symbol *s, short ac, t_atom *av);
void keys_free(t_keys *x);

void keys_bang(t_keys *x);
void keys_int(t_keys *x, t_atom_long v);
void keys_float(t_keys *x, double v);
void keys_anything(t_keys *x, t_symbol *msg, long ac, t_atom *av);

long keys_func(t_hatom *key, t_llll *what);
void keys_output(t_keys *x);

DEFINE_STANDARD_MAXDEPTH_SETTER(t_keys)
DEFINE_STANDARD_MINDEPTH_SETTER(t_keys)

t_class *keys_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.keys", (method)keys_new, (method)keys_free, (long) sizeof(t_keys), 0L, A_GIMME, 0);
	
	// @method llll @digest Search the llll for the specified keys
	// @description
	// The first elements of the llll and all its sublists are examined, traversing the llll depth-first as in <o>bach.iter</o>.
	// When a first element is found to match one of <o>bach.keys</o>'s arguments (the "keys"),
	// the corresponding llll is output, with or without the key according to the <m>keep</m> attribute,
	// and that key is no further looked for.<br />
	// Anyway, all the found lllls are output right-to-left, according to their order in <o>bach.keys</o>'s arguments
	// and regardless of their positions in the original llll.
	// In case of multiple possible matches, the first matching llll that is found is output.
	// If no match is found for any key, a bang is output from the rightmost outlet.
	class_addmethod(c, (method)keys_anything,	"anything",		A_GIMME,	0);
	class_addmethod(c, (method)keys_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)keys_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)keys_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description The keys are searched for in the most recently received llll.
	class_addmethod(c, (method)keys_bang,		"bang",			0);
	
	class_addmethod(c, (method)keys_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)keys_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	CLASS_ATTR_LONG(c, "mindepth",		0,	t_keys, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth",		0, "Minimum Depth");	
	CLASS_ATTR_BASIC(c, "mindepth", 0);
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_keys);
	// @description @copy BACH_DOC_MINDEPTH
	
	CLASS_ATTR_LONG(c, "maxdepth",		0,	t_keys, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth",		0, "Maximum Depth");	
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, t_keys);
	// @description @copy BACH_DOC_MAXDEPTH

	CLASS_ATTR_LONG(c, "depthreject",	0,	t_keys, n_depthreject);
	CLASS_ATTR_LABEL(c, "depthreject",	0, "Depth Reject");	
	CLASS_ATTR_STYLE(c, "depthreject",	0, "onoff");
	// @description @copy BACH_DOC_DEPTHREJECT

	CLASS_ATTR_LONG(c, "keep",			0,	t_keys, n_keep);
	CLASS_ATTR_LABEL(c, "keep",			0, "Keep");	
	CLASS_ATTR_STYLE(c, "keep",			0, "onoff");
	// @description When set to 1, the key for each output llll is not removed.
	
	CLASS_ATTR_LONG(c, "nullmode",		0,	t_keys, n_nullmode);
	CLASS_ATTR_LABEL(c, "nullmode",		0, "Null Mode");	
	CLASS_ATTR_STYLE(c, "nullmode",		0, "onoff");
	CLASS_ATTR_BASIC(c, "nullmode", 0);
	// @description When set to 1, if no match was found for a given key <b>null</b> is output from the corresponding outlet.

	class_register(CLASS_BOX, c);
	keys_class = c;
	
	dev_post("bach.keys compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void keys_bang(t_keys *x)
{
	if (x->n_ob.l_rebuild != 0) {
		keys_anything(x, _sym_bang, 0, NULL);
		return;
	}
	keys_output(x);
}

void keys_output(t_keys *x)
{
	long i, foundone = 0;
	for (i = x->n_ob.l_numouts - 2; foundone == 0 && i >= 0; i--)
		foundone |= x->n_exists[i];
	
	if (foundone) {
		for (i = x->n_ob.l_numouts - 2; i >= 0; i--) {
			if (x->n_exists[i] || (x->n_nullmode && x->n_keys[i].h_type != H_NULL))
				llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
		}
	} else {
		llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1);
		for (i = x->n_ob.l_numouts - 2; i >= 0; i--) {
			if (x->n_nullmode || x->n_keys[i].h_type == H_NULL)
				llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
		}
	}
}

void keys_int(t_keys *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	keys_anything(x, _sym_int, 1, &outatom);
}

void keys_float(t_keys *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	keys_anything(x, _sym_float, 1, &outatom);
}

void keys_anything(t_keys *x, t_symbol *msg, long ac, t_atom *av)
{
	t_hatom *this_keys;
	t_llll *in_ll, *address, *baby, *found, *dummy;
	long outlet;
	
	if (msg != _sym_bang) {
		in_ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!in_ll)
			return;
	} else
		in_ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);

	for (outlet = 0, this_keys = x->n_keys; this_keys->h_type != H_NOTHING; this_keys++, outlet++) {
		x->n_exists[outlet] = 0;

		if (this_keys->h_type != H_NULL) {
			address = llll_get();
			dummy = llll_find(in_ll, address, 1, 
					  x->n_mindepth, x->n_maxdepth, 1, 1, 0, x->n_depthreject, 
					  1, 0, 0, 1, 1, (find_fn) keys_func, this_keys);
			llll_free(dummy);
			if (address->l_size && address->l_head->l_hatom.h_w.w_llll->l_tail->l_hatom.h_w.w_long == 1) {
				x->n_exists[outlet] = 1;
				llll_flatten(address, 1, 0);
				if (address->l_size == 1) { // the list is at level 0 - so we must output the whole inll
					found = llll_clone(in_ll);
				} else {
					baby = llll_get();
					llll_findchildren(in_ll, address, 0, baby, NULL);
					found = llll_clone(((t_llllelem *) baby->l_head->l_hatom.h_w.w_obj)->l_parent);
					llll_free(baby);
				}
				if (!x->n_keep)
					llll_destroyelem(found->l_head);
				llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, found, outlet);
			} else {
				llll_retain(x->n_empty);
				llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_empty, outlet);
			}
			llll_free(address);
		} else {
			llll_retain(in_ll);
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, in_ll, outlet);
		}
	}
	llll_release(in_ll);
	x->n_ob.l_rebuild = 0;
	keys_output(x);
}

long keys_func(t_hatom *key, t_llll *what)
{
	return hatom_eq(key, &what->l_head->l_hatom);
}

void keys_assist(t_keys *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0)	sprintf(s, "llll to search"); // @out 0 @type llll @digest llll to search
	} else {
		if (a < x->n_ob.l_numouts - 1) {
			char *type = NULL;
			llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
			switch (x->n_keys[a].h_type) {
				case H_LONG:	sprintf(s, "llll (%s) for Key " ATOM_LONG_PRINTF_FMT, type, x->n_keys[a].h_w.w_long);			break;
				case H_DOUBLE:	sprintf(s, "llll (%s) for Key %f", type, x->n_keys[a].h_w.w_double);		break;
				case H_SYM:		sprintf(s, "llll (%s) for Key %s", type, x->n_keys[a].h_w.w_sym->s_name);	break;
				case H_NULL:	sprintf(s, "original llll (%s) if no match is found", type);				break;
			}
			// @out 0 @loop 1 @type llll @digest Found match for the corresponding key
		} else
			sprintf(s, "bang if No Match"); // @out 1 @type bang @digest bang if no match is found
	}
}

void keys_inletinfo(t_keys *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void keys_free(t_keys *x)
{
	bach_freeptr(x->n_keys);
	bach_freeptr(x->n_exists);
	llll_free(x->n_empty);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_keys *keys_new(t_symbol *s, short ac, t_atom *av)
{
	t_keys *x = NULL;
	long i;
	t_max_err err = 0;
	long true_ac;
	char outlets[LLLL_MAX_OUTLETS], *this_outlets = outlets;
	t_hatom *this_keys;
	
	true_ac = MIN(attr_args_offset(ac, av), LLLL_MAX_OUTLETS - 1);
	
	if ((x = (t_keys *) object_alloc_debug(keys_class))) {
		// @arg 0 @name keys @type anything @digest Keys
		// @description The keys to look for.
		this_keys = x->n_keys = (t_hatom *) bach_newptr((true_ac + 1) * sizeof(t_hatom));
		x->n_exists = (long *) bach_newptr(true_ac * sizeof(long));
		x->n_mindepth = 1;
		x->n_maxdepth = -1;
		
		attr_args_process(x, ac, av);
		
		*this_outlets++ = 'b';
		for (i = 0; i < true_ac && i < LLLL_MAX_OUTLETS - 1; i++) {
			*this_outlets++ = '4';
			if (atom_getsym(av) == _llllobj_sym_null)
				this_keys->h_type = H_NULL;
			else
				hatom_setatom(this_keys, av);
			this_keys++;
			av++;	
		}
		*this_outlets = 0;
		this_keys->h_type = H_NOTHING;
		
		llllobj_obj_setup((t_llllobj_object *) x, 1, outlets);
		
		x->n_empty = llll_get();
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;

	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
