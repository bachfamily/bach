/*
 *  trans.c
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
 trans.c
 
 @name 
 bach.trans
 
 @realname 
 bach.trans
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Matrix transposition of an llll
 
 @description
 Performs matrix transposition of an llll.
  
 @category
 bach, bach objects, bach llll, bach matrix calculus
 
 @keywords
 transpose, matrix, mirror

 @seealso
 bach.lace, bach.delace, bach.mdelace, bach.reshape
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _trans
{
	t_llllobj_object 	n_ob;
	long				n_iterationmode;
	t_llll				*n_depth;
	t_bach_atomic_lock	n_depth_lock;
} t_trans;

void trans_assist(t_trans *x, void *b, long m, long a, char *s);
void trans_inletinfo(t_trans *x, void *b, long a, char *t);

t_trans *trans_new(t_symbol *s, short ac, t_atom *av);
void trans_free(t_trans *x);

void trans_bang(t_trans *x);
void trans_int(t_trans *x, t_atom_long v);
void trans_float(t_trans *x, double v);
void trans_anything(t_trans *x, t_symbol *msg, long ac, t_atom *av);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_trans, n_depth, trans_getattr_depth);
t_max_err trans_setattr_depth(t_trans *x, t_object *attr, long ac, t_atom *av);

t_class *trans_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.trans", (method)trans_new, (method)trans_free, (long) sizeof(t_trans), 0L, A_GIMME, 0);
	
	// @method llll @digest Perform matrix transposition
	// <o>bach.trans</o> returns an llll composed by a sublist with all the first elements of every sublist of the incoming llll;
	// a sublist with all the second elements; and so on.
	// If not all the sublists of the original llll have the same size, the behavior is defined by the <m>iterationmode</m> attribute.
	class_addmethod(c, (method)trans_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)trans_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)trans_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)trans_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)trans_bang,		"bang",			0);
	
	class_addmethod(c, (method)trans_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)trans_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	

	CLASS_ATTR_LONG(c, "iterationmode",	0,	t_trans, n_iterationmode);
	CLASS_ATTR_FILTER_CLIP(c, "iterationmode", 0, 2);
	CLASS_ATTR_LABEL(c, "iterationmode", 0, "Iteration Mode");
	// @description @copy BACH_DOC_ITERATIONMODE

	CLASS_ATTR_LLLL(c, "depth", 0, t_trans, n_depth, trans_getattr_depth, trans_setattr_depth);
	CLASS_ATTR_LABEL(c, "depth", 0, "Depths");
	// @description The depth at which the transpositions must be performed. If a plain list of depths is given,
	// <o>bach.trans</o> will perform as many transpositions as the number of elements in this list.
	// Default is <b>1</b>, meaning that transposition must only be performed at root level. Any
	// plain list of non-zero integers is allowed (negative numbers included, counting depths
	// from the innermost to the outermost level). 
	// For instance, <b>1 3 -2</b> will have <o>bach.trans</o>
	// perform a transposition at the root level, then a transposition at the third level of depth,
	// and finally a transposition at the one-but-last level of depth.

	class_register(CLASS_BOX, c);
	trans_class = c;
	
	dev_post("bach.trans compiled %s %s", __DATE__, __TIME__);
	
	return;
}

t_max_err trans_setattr_depth(t_trans *x, t_object *attr, long ac, t_atom *av)
{
	t_llll *ll;
	if (ac == 0 || av) {
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, av))) {
			t_llll *free_me;
			bach_atomic_lock(&x->n_depth_lock);
			free_me = x->n_depth;
			llll_flatten(ll, 0, 0);
			x->n_depth = ll;
			bach_atomic_unlock(&x->n_depth_lock);
			llll_free(free_me);
		}
	}
	return MAX_ERR_NONE;
}

void trans_bang(t_trans *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		trans_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void trans_int(t_trans *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	trans_anything(x, _sym_int, 1, &outatom);
}

void trans_float(t_trans *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	trans_anything(x, _sym_float, 1, &outatom);
}

#ifdef ___destructive
void trans_anything(t_trans *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll, *depth;	
    if (msg != _sym_bang) {
        ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);

    bach_atomic_lock(&x->n_depth_lock);
    depth = x->n_depth;
    llll_retain(depth);
    bach_atomic_unlock(&x->n_depth_lock);
    llll_trans_extended(ll, depth, x->n_iterationmode);
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
    x->n_ob.l_rebuild = 0;
    llll_release(depth);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}
#else
void trans_anything(t_trans *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll, *depth;
	if (msg != _sym_bang) {
		ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} else
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	bach_atomic_lock(&x->n_depth_lock);
	depth = x->n_depth;
	llll_retain(depth);
	bach_atomic_unlock(&x->n_depth_lock);
	
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_trans_extended(ll, depth, x->n_iterationmode), 0);
	llll_release(depth);
	x->n_ob.l_rebuild = 0;
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}
#endif

void trans_assist(t_trans *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll to Transpose"); // @in 0 @type llll @digest The llll to transpose
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "Transposed llll (%s)", type); // @out 0 @type llll @digest The transposed llll
	}
}

void trans_inletinfo(t_trans *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void trans_free(t_trans *x)
{
	llll_free(x->n_depth);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_trans *trans_new(t_symbol *s, short ac, t_atom *av)
{
	t_trans *x = NULL;
	long true_ac;
	t_max_err err = MAX_ERR_NONE;
	t_llll *depth_ll = NULL;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_trans *) object_alloc_debug(trans_class))) {

		// @arg 0 @name depths @type list @optional 1 @digest Depth
		// @description Initial value for the <m>depth</m> attribute.
		
		if (true_ac) {
			depth_ll = llll_parse(true_ac, av);
			if (depth_ll) {
				x->n_depth = depth_ll;
			} else {
				object_error((t_object *) x, "Bad depth llllv                                                                                                                                                                                                                                         ");
			}
		}
		if (!depth_ll)                                                                                                              
			x->n_depth = llll_make();
		
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
