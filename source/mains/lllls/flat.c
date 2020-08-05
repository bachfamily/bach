/*
 *  flat.c
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
 flat.c
 
 @name 
 bach.flat
 
 @realname 
 bach.flat
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Decrease the depth of an llll
 
 @description
 Decreases the depth of an llll by eliminating couple of parentheses.

 @category
 bach, bach objects, bach llll
 
 @keywords
 flat, flatten, level, parenthesis, remove, eliminate, couple, depth, decrease

 @seealso
 bach.wrap, bach.trans, bach.depth
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _flat
{
	t_llllobj_object 	n_ob;
	long				n_minlevel;
	long				n_maxlevel;
	long				n_spikemode;
} t_flat;


void flat_assist(t_flat *x, void *b, long m, long a, char *s);
void flat_inletinfo(t_flat *x, void *b, long a, char *t);

t_flat *flat_new(t_symbol *s, short ac, t_atom *av);
void flat_free(t_flat *x);

void flat_bang(t_flat *x);
void flat_int(t_flat *x, t_atom_long v);
void flat_float(t_flat *x, double v);
void flat_anything(t_flat *x, t_symbol *msg, long ac, t_atom *av);

t_max_err flat_maxlevel_set(t_flat *x, t_object *attr, long argc, t_atom *argv);
t_max_err flat_minlevel_set(t_flat *x, t_object *attr, long argc, t_atom *argv);


t_class *flat_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.flat", (method)flat_new, (method)flat_free, (long) sizeof(t_flat), 0L, A_GIMME, 0);
	
	// @method llll @digest Flatten the llll
	// @description
	// The depth of the llll is reduced by removing couple of parentheses, 
	// according to the <m>minlevel</m> and <m>maxlevel</m> attributes.
	class_addmethod(c, (method)flat_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)flat_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)flat_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)flat_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description Reduce the depth of the most recently received llll
	class_addmethod(c, (method)flat_bang,		"bang",			0);
	
	class_addmethod(c, (method)flat_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)flat_inletinfo,	"inletinfo",	A_CANT,		0);

	CLASS_ATTR_LONG(c, "maxlevel",	0,	t_flat, n_maxlevel);
	CLASS_ATTR_LABEL(c, "maxlevel", 0, "Maximum Level");
	CLASS_ATTR_BASIC(c, "maxlevel", 0);
	CLASS_ATTR_ACCESSORS(c, "maxlevel", NULL, flat_maxlevel_set);
	// @description
	// The <m>maxlevel</m> attribute indicates the deepest level of parentheses to remove. 
	// Every parenthesis deeper than maxlevel is left alone. 
	// For example, <m>maxlevel 1</m> means "the last level of parentheses to remove is the outermost", 
	// <m>maxlevel 2</m> means "the last level to remove is the second-outermost".
	// If set to a negative number, the levels are counted from the innermost level: 
	// <m>maxlevel -1</m> means "the last level of parentheses to remove is the innermost", 
	// that is "remove all the parentheses, down to the deepest"; 
	// <m>maxlevel -2</m> means "the last level to remove is the second-innermost",
	// that is, "always leave the deepest level of parentheses for every branch of the llll".
	// Defaults to -1.
	
	CLASS_ATTR_LONG(c, "minlevel",	0,	t_flat, n_minlevel);
	CLASS_ATTR_LABEL(c, "minlevel", 0, "Minimum Level");
	CLASS_ATTR_BASIC(c, "minlevel", 0);
	CLASS_ATTR_ACCESSORS(c, "minlevel", NULL, flat_minlevel_set);
	// @description
	// The <m>minlevel</m> attribute indicates the less deep level of parentheses to remove. 
	// Every parenthesis less deep than maxlevel is left alone. 
	// For example, <m>minlevel 1</m> means "start removing the parentheses from the first level", 
	// that is "remove all the parentheses, from the outermost". 
	// <m>minlevel 2</m> means "leave the first level of parentheses alone, and start removing from the second outermost".
	// If set to a negative number, the levels are counted from the innermost level: 
	// <m>minlevel -1</m> means "the first level of parentheses to remove is the innermost", 
	// that is "remove only the innermost level"; 
	// <m>maxlevel -2</m> means "remove the two innermost levels",
	// Defaults to 1.
	
	/*
	CLASS_ATTR_LONG(c, "spikemode",	0,	t_flat, n_spikemode);
	CLASS_ATTR_LABEL(c, "spikemode", 0, "Spike Mode");
	CLASS_ATTR_FILTER_CLIP(c, "spikemode", 0, 1);
	CLASS_ATTR_STYLE(c, "spikemode", 0, "onoff");
	*/
	// @exclude bach.flat

	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	

	class_register(CLASS_BOX, c);
	flat_class = c;
	
	dev_post("bach.flat compiled %s %s", __DATE__, __TIME__);
	
	return;
}

t_max_err flat_maxlevel_set(t_flat *x, t_object *attr, long argc, t_atom *argv)
{
	long maxlevel = atom_getlong(argv);
	if (maxlevel == 0) {
		object_warn((t_object *) x, "maxlevel 0 not accepted: setting to -1");
		x->n_maxlevel = -1;
		return 0;
	}
	x->n_maxlevel = maxlevel;
	return 0;
}

t_max_err flat_minlevel_set(t_flat *x, t_object *attr, long argc, t_atom *argv)
{
	long minlevel = atom_getlong(argv);
	if (minlevel == 0) {
		object_warn((t_object *) x, "minlevel 0 not accepted: setting to 11");
		x->n_minlevel = -1;
		return 0;
	}
	x->n_minlevel = minlevel;
	return 0;
}

void flat_bang(t_flat *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		flat_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void flat_int(t_flat *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	flat_anything(x, _sym_int, 1, &outatom);
}

void flat_float(t_flat *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	flat_anything(x, _sym_float, 1, &outatom);
}

void flat_anything(t_flat *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll;
    if (msg != _sym_bang) {
        ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
    llll_flat(ll, x->n_minlevel, x->n_maxlevel, x->n_spikemode, LLLL_FREETHING_DONT);
    x->n_ob.l_rebuild = 0;
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void flat_assist(t_flat *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest llll to flatten
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		// @out 0 @type llll @digest Flattened llll
		sprintf(s, "llll (%s)", type);
	}
}

void flat_inletinfo(t_flat *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void flat_free(t_flat *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_flat *flat_new(t_symbol *s, short ac, t_atom *av)
{
	t_flat *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_flat *) object_alloc_debug(flat_class))) {
		// @arg 0 @name levels @optional 1 @digest Levels
		// @description If only one argument is present, it is considered <m>maxlevels</m>.
		// If two arguments are present, they are considered <m>minlevels</m> and <m>maxlevels</m>.
		x->n_minlevel = 1;
		x->n_maxlevel = -1;
		switch (true_ac) {
			case 0: 
				break;
			case 1:
				object_attr_setvalueof(x, gensym("maxlevel"), 1, av);
				break;
			case 2:
				object_attr_setvalueof(x, gensym("minlevel"), 1, av);
				object_attr_setvalueof(x, gensym("maxlevel"), 1, av + 1);
				break;
			default:
				object_warn((t_object *) x, "Bad number of arguments");
				break;
		}
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
