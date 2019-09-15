/*
 *  dict2llll.c
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
	dict2llll.c
	
	@name 
	bach.dict2llll
	
	@realname 
	bach.dict2llll

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a dictionary into an llll
	
	@description
	Converts a dictionary into an llll, under the convention that the first element in each level is the level key.
		
	@discussion
	A dictionary in llll form can be visualized by <o>bach.tree</o>'s Outline mode (similar to <o>dict.view</o>, but with a few
	more features). 
 
	@category
	bach, bach abstractions, bach llll
 
	@keywords
	convert, `dictionary, name, element, tree
 
	@seealso
	bach.llll2dict, dict, bach.tree
 
	@owner
	Daniele Ghisi
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_dictobj.h"
#include "llll_commons_ext.h"

typedef struct _dict2llll
{
	struct llllobj_object 	n_ob;
} t_dict2llll;


void dict2llll_assist(t_dict2llll *x, void *b, long m, long a, char *s);
void dict2llll_inletinfo(t_dict2llll *x, void *b, long a, char *t);

t_dict2llll *dict2llll_new(t_symbol *s, short ac, t_atom *av);
void dict2llll_free(t_dict2llll *x);
void dict2llll_dictionary(t_dict2llll *x, t_symbol *s);

void dict2llll_bang(t_dict2llll *x);
void dict2llll_int(t_dict2llll *x, t_atom_long num);
void dict2llll_float(t_dict2llll *x, double num);
void dict2llll_anything(t_dict2llll *x, t_symbol *msg, long ac, t_atom *av);

t_class *dict2llll_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}	
	
	c = class_new("bach.dict2llll", (method)dict2llll_new, (method)dict2llll_free, (short)sizeof(t_dict2llll), 0L, A_GIMME, 0);
	
	// @method dictionary @digest Convert dictionary to llll
	// @description A <m>dictionary</m> message, followed by a name, will convert the dictionary identified by that name into an llll.
	// @marg 0 @name dictionary-name @optional 0 @type symbol
	class_addmethod(c, (method)dict2llll_dictionary,				"dictionary",			A_SYM,	0);
	
/*	class_addmethod(c, (method)dict2llll_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)dict2llll_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)dict2llll_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)dict2llll_anything,					"list",					A_GIMME,	0);
*/
	
	// @method bang @digest Output dictionary in llll form
	// @description Converts into llll the most recently received input dictionary.
	class_addmethod(c, (method)dict2llll_bang,						"bang",		0);
	
	class_addmethod(c, (method)dict2llll_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)dict2llll_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	
	class_register(CLASS_BOX, c);
	dict2llll_class = c;
	
	dev_post("bach.dict2llll compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void dict2llll_bang(t_dict2llll *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void dict2llll_fn(t_dictionary_entry *entry, void* my_arg)
{
	t_dictionary *d = (t_dictionary *)((void **)my_arg)[0];
	t_llll *ll = (t_llll *)((void **)my_arg)[1];
	t_symbol    *key;

	long i, ac;
	t_atom *av = NULL;
	
	key = dictionary_entry_getkey(entry);
	
	if (dictionary_entryisdictionary(d, key)) {
		t_dictionary *nested_dict = NULL;
		dictionary_getdictionary(d, key, (t_object **) &nested_dict);
		if (nested_dict) {
			t_llll *subll = llll_get();
			llll_appendsym(subll, key, 0, WHITENULL_llll);
			void *new_args[2];
			new_args[0] = nested_dict;
			new_args[1] = subll;
			dictionary_funall(nested_dict, (method)dict2llll_fn, new_args);
			llll_appendllll(ll, subll, 0, WHITENULL_llll);
		}
	} else {
		t_llll *subll = llll_get();
		llll_appendsym(subll, key, 0, WHITENULL_llll);
		dictionary_entry_getvalues(entry, &ac, &av);
		for (i = 0; i < ac; i++) {
			long type = atom_gettype(av+i);
			if (type == A_LONG || type == A_FLOAT || type == A_SYM)	
				llll_appendatom(subll, av + i, 0, WHITENULL_llll); 
		}
//		if (!dictionary_entryisatomarray(d, key))
//			sysmem_freeptr(av); // Looks like we don't have to free this
		llll_appendllll(ll, subll, 0, WHITENULL_llll);
	}
}


t_llll *dict2llll(t_dictionary *d)
{

	t_llll *ll = llll_get();
	void *args[2];
	args[0] = d;
	args[1] = ll;

	dictionary_funall(d, (method)dict2llll_fn, args);

	return ll;
}


void dict2llll_dictionary(t_dict2llll *x, t_symbol *s)
{
	t_dictionary	*d = dictobj_findregistered_retain(s);
	
	if (!d) {
		object_error((t_object *)x, "Unable to reference dictionary named %s", s);
		return;
	}
	
	t_llll *out = dict2llll(d);
	
	dictobj_release(d);
	llll_check(out);
	llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, out, 0);
	dict2llll_bang(x);
}


void dict2llll_assist(t_dict2llll *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "dictionary: Dictionary Name "); // @in 0 @type dictionary @digest The dictionary name 
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "Dictionary as llll (%s)", type); // @out 0 @type llll @digest The dictionary as llll 
	}
}

void dict2llll_inletinfo(t_dict2llll *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void dict2llll_free(t_dict2llll *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_dict2llll *dict2llll_new(t_symbol *s, short ac, t_atom *av)
{
	t_dict2llll *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_dict2llll *) object_alloc_debug(dict2llll_class))) {
	
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

