/*
 *  depth.c
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
 depth.c
 
 @name 
 bach.depth
 
 @realname 
 bach.depth
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Depth of an llll
 
 @description
 Returns the depth of an llll.
 
 @discussion
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 depth

 @seealso
 bach.is, bach.contains, bach.length
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"


typedef struct _depth
{
	struct	llllobj_object	n_ob;
	long	n_depth;

} t_depth;


void depth_assist(t_depth *x, void *b, long m, long a, char *s);
void depth_inletinfo(t_depth *x, void *b, long a, char *t);

t_depth *depth_new(t_symbol *s, short ac, t_atom *av);
void depth_free(t_depth *x);

void depth_bang(t_depth *x);
void depth_int(t_depth *x, t_atom_long v);
void depth_float(t_depth *x, double v);
void depth_anything(t_depth *x, t_symbol *msg, long ac, t_atom *av);


t_class *depth_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.depth", (method)depth_new, (method)depth_free, (long) sizeof(t_depth), 0L, A_GIMME, 0);
	
	// @method llll @digest Return the depth of the llll
	// @description
	// Returns the depth of the deepest branch of the llll.
	// Flat lllls and empty lllls have depth 1.
	
	class_addmethod(c, (method)depth_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)depth_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)depth_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)depth_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Return the depth
	// @description Return the depth of the most recently received llll.
	class_addmethod(c, (method)depth_bang,		"bang",			0);
	
	class_addmethod(c, (method)depth_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)depth_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	depth_class = c;
	
	dev_post("bach.depth compiled %s %s", __DATE__, __TIME__);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	return;
}

void depth_bang(t_depth *x)
{	
	outlet_int(x->n_ob.l_out[0].b_outlet, x->n_depth);
}

void depth_int(t_depth *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	depth_anything(x, _sym_int, 1, &outatom);
}

void depth_float(t_depth *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	depth_anything(x, _sym_float, 1, &outatom);
}

void depth_anything(t_depth *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_llll;

	in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	x->n_depth = in_llll ? in_llll->l_depth : 0;
	llll_free(in_llll);
	outlet_int(x->n_ob.l_out[0].b_outlet, x->n_depth);
}

void depth_assist(t_depth *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll whose depth will be returned
	} else {
		sprintf(s, "int: Depth of Incoming llll"); // @in 0 @type int @digest Depth of the incoming llll
	}
}

void depth_inletinfo(t_depth *x, void *b, long a, char *t)
{
	*t = 1;
}

void depth_free(t_depth *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}


t_depth *depth_new(t_symbol *s, short ac, t_atom *av)
{
	t_depth *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_depth *) object_alloc_debug(depth_class))) 
		llllobj_obj_setup((t_llllobj_object *) x, 0, "i");
	 else 
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
