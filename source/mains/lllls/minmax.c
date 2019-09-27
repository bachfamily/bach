/*
 *  minmax.c
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
 minmax.c
 
 @name 
 bach.minmax
 
 @realname 
 bach.minmax
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Minimum and maximum of an llll
 
 @description
 Returns the minimum and maximum numbers in an llll.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 minimum, maximum, number

 @seealso
 bach.find, bach.contains, bach.expr
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _minmax
{
	struct llllobj_object 	n_ob;
	long					n_mindepth;
	long					n_maxdepth;
} t_minmax;


void minmax_assist(t_minmax *x, void *b, long m, long a, char *s);
void minmax_inletinfo(t_minmax *x, void *b, long a, char *t);

t_minmax *minmax_new(t_symbol *s, short ac, t_atom *av);
void minmax_free(t_minmax *x);

void minmax_bang(t_minmax *x);
void minmax_int(t_minmax *x, t_atom_long v);
void minmax_float(t_minmax *x, double v);
void minmax_anything(t_minmax *x, t_symbol *msg, long ac, t_atom *av);

void minmax_output(t_minmax *x);

DEFINE_STANDARD_MAXDEPTH_SETTER(t_minmax)
DEFINE_STANDARD_MINDEPTH_SETTER(t_minmax)

t_class *minmax_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.minmax", (method)minmax_new, (method)minmax_free, (short)sizeof(t_minmax), 0L, A_GIMME, 0);
	
	
	// @method llll @digest llll to find minimum and maximum of
	// @description
	// The minimum and maximum numbers contained in the llll are output, along with their addresses.<br />
	// @copy BACH_DOC_ADDRESS_BASIC

	class_addmethod(c, (method)minmax_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)minmax_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)minmax_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)minmax_anything,		"list",			A_GIMME,	0);
	
	// @method bang @digest Repeat last operation
	// @description Return the minimum and maximum of the most recently received llll.
	class_addmethod(c, (method)minmax_bang,			"bang",			0);
	
	class_addmethod(c, (method)minmax_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)minmax_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	CLASS_ATTR_LONG(c, "mindepth",	0,	t_minmax, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");
	CLASS_ATTR_BASIC(c, "mindepth", 0);
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_keys);
	// @description @copy BACH_DOC_MINDEPTH
	
	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_minmax, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, t_keys);
	// @description @copy BACH_DOC_MAXDEPTH

	class_register(CLASS_BOX, c);
	minmax_class = c;
	
	dev_post("bach.minmax compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void minmax_bang(t_minmax *x)
{	
	if (x->n_ob.l_rebuild != 0)
		minmax_anything(x, _sym_bang, 0, NULL);
	else {
		minmax_output(x);
	}
}

void minmax_output(t_minmax *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 3);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 2);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void minmax_int(t_minmax *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	minmax_anything(x, _sym_int, 1, &outatom);
}

void minmax_float(t_minmax *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	minmax_anything(x, _sym_float, 1, &outatom);
}

void minmax_anything(t_minmax *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll, *minll, *maxll, *minaddress, *maxaddress;
	t_hatom *min = NULL, *max = NULL;
	
	if (msg != _sym_bang) {
		ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} else
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
	
	
	minll = llll_get();
	maxll = llll_get();
	minaddress = llll_get();
	maxaddress = llll_get();
	llll_minmax(ll, &min, &max, minaddress, maxaddress, x->n_mindepth, x->n_maxdepth);
	llll_release(ll);
	if (min) {
		llll_appendhatom(minll, min, 0, WHITENULL_llll);
		llll_appendhatom(maxll, max, 0, WHITENULL_llll);
	}
	x->n_ob.l_rebuild = 0;
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, maxaddress, 3);
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, maxll, 2);
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, minaddress, 1);
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, minll, 0);
	minmax_output(x);
}

void minmax_assist(t_minmax *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest llll to find minimum and maximum of
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0: sprintf(s, "llll (%s): Min", type);			break; // @out 0 @type llll @digest Minimum
			case 1: sprintf(s, "llll (%s): Min Address", type);	break; // @out 1 @type llll @digest Address of the minimum
			case 2: sprintf(s, "llll (%s): Max", type);			break; // @out 2 @type llll @digest Maximum
			case 3: sprintf(s, "llll (%s): Max Address", type);	break; // @out 3 @type llll @digest Address of the maximum			
		}
	}
}

void minmax_inletinfo(t_minmax *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void minmax_free(t_minmax *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_minmax *minmax_new(t_symbol *s, short ac, t_atom *av)
{
	t_minmax *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_minmax *) object_alloc_debug(minmax_class))) {
		// @arg 0 @name depth @optional 1 @type int @digest Depth
		// @description If only one argument is present, it is considered maxdepth
		// If two arguments are present, the first is considered mindepth, the second maxdepth
		x->n_mindepth = 1;
		x->n_maxdepth = -1;
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
		
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4444");

	} else
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
