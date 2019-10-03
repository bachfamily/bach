/*
 *  rev.c
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
 rev.c
 
 @name 
 bach.rev
 
 @realname 
 bach.rev
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Reverse an llll
 
 @description 
 Performs a reversal of an llll and its sublists, within a specified depth range.
 
 @discussion
 
 @category
 bach, bach objects, bach llll

 @keywords
 reverse, invert

 @seealso
 bach.rot, bach.slice, bach.join, bach.trans
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _rev
{
	struct llllobj_object 	n_ob;
	long					n_mindepth;
	long					n_maxdepth;
} t_rev;


void rev_assist(t_rev *x, void *b, long m, long a, char *s);
void rev_inletinfo(t_rev *x, void *b, long a, char *t);

t_rev *rev_new(t_symbol *s, short ac, t_atom *av);
void rev_free(t_rev *x);

void rev_bang(t_rev *x);
void rev_int(t_rev *x, t_atom_long v);
void rev_float(t_rev *x, double v);
void rev_anything(t_rev *x, t_symbol *msg, long ac, t_atom *av);




// We can use the following macros to define the setters for the maxdepth and mindepth attributes, which can't be set to 0.

DEFINE_STANDARD_MAXDEPTH_SETTER(t_rev);
DEFINE_STANDARD_MINDEPTH_SETTER(t_rev);

t_class *rev_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.rev", (method)rev_new, (method)rev_free, (long) sizeof(t_rev), 0L, A_GIMME, 0);
		
	// @method llll @digest Reverse the incoming llll
	// @description Perform the reversal on the incoming llll.
	class_addmethod(c, (method)rev_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)rev_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)rev_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)rev_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the reversal
	// @description Perform the reversal on the most recently received llll.
	class_addmethod(c, (method)rev_bang,		"bang",			0);
	
	class_addmethod(c, (method)rev_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)rev_inletinfo,	"inletinfo",	A_CANT,		0);

	
	
	
	
	
	// This is very important: it defines the out attribute, define its getter and setter
	// and also manages the notify method for managing the l_rebuild field.
	// Always put this in the main() function of an object with llll outlets.
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	
	
	CLASS_ATTR_LONG(c, "mindepth",	0,	t_rev, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");
	CLASS_ATTR_BASIC(c, "mindepth", 0);
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_rev); // referencing the setter defined above
	// @description @copy BACH_DOC_MINDEPTH

	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_rev, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);	
	CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, t_rev); // referencing the setter defined above
	// @description @copy BACH_DOC_MAXDEPTH

	class_register(CLASS_BOX, c);
	rev_class = c;
	
	dev_post("bach.rev compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void rev_bang(t_rev *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0) {
		rev_anything(x, _sym_bang, 0, NULL);
	} else {
		
		
		
		// The llll resulting from the operation (or an empty llll, if no operation has been performed yet)
		// has been stored in the first store.
		// Now we output the contents of the first store (counted from 0: it's the third argument of the function call),
		// in native or text format according to the value of the out attribute.
		
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void rev_int(t_rev *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	rev_anything(x, _sym_int, 1, &outatom);
}

void rev_float(t_rev *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	rev_anything(x, _sym_float, 1, &outatom);
}

void rev_anything(t_rev *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll;
	

	if (msg != _sym_bang) {
		
		// the llll must be cloned because llll_rev is a destructive operation
		ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} else {
		
		// the 1 at the end means that a clone of the store contents must be returned
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	}
	llll_rev(ll, x->n_mindepth, x->n_maxdepth);
	x->n_ob.l_rebuild = 0;
	
	// This loads ll into the first output cache (the final 0, as usual).
	// Notice that we don't release ll, as ownership to it has been handed to the output cache.
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
	
	// After loading an llll, we can output it.
	// All the output cache mechanism is relevant because we want to be able to respond to a bang
	// by outputting again the same reversed llll without having to re-perform the reversal.
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	
}


void rev_assist(t_rev *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @digest The llll to reverse
	} else {
		char *type = NULL;
		
		// this returns the string "text", "native" or "disabled" according to the value of the out attribute for this outlet
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		
		sprintf(s, "llll (%s)", type); // @out 0 @digest The reversed llll
	}
}

void rev_inletinfo(t_rev *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void rev_free(t_rev *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_rev *rev_new(t_symbol *s, short ac, t_atom *av)
{
	t_rev *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	if ((x = (t_rev *) object_alloc_debug(rev_class))) {
		// @arg 0 @name depths @optional 1 @type list @digest Depth options
		// @description If there is only one argument, it sets <m>maxdepth</m>.
		// If there are two arguments, they set respectively <m>mindepth</m> and <m>maxdepth</m>.
		x->n_mindepth = 1;
		x->n_maxdepth = -1;
		true_ac = attr_args_offset(ac, av);
		switch (true_ac) {
			case 0: 
				break;
			case 1:
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av);
				break;
			case 2:
				object_attr_setvalueof(x, gensym("mindepth"), 1, av);
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av + 1);
				break;
			default:
				object_warn((t_object *) x, "Bad number of arguments");
				break;
		}
		
		attr_args_process(x, ac, av);
		
		// "4" means that we want a single llll outlet
		// look at the llllobj_obj_setup() documentation for more information about this.
        // It must always be called after attr_args_process if there are llll outlets,
        // because the out attribute must have been set
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
