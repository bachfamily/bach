/*
 *  scramble.c
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
 scramble.c
 
 @name 
 bach.scramble
 
 @realname 
 bach.scramble
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Perform a random permutation of an llll
 
 @description 
 Returns a random permutation of the incoming llll and its sublists.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 scramble, permutation, permute

 @seealso
 bach.perm, bach.nth, bach.comb, bach.constraints, bach.cartesianprod
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _scramble
{
	t_llllobj_object 	n_ob;
	long				n_mindepth;
	long				n_maxdepth;
} t_scramble;


void scramble_assist(t_scramble *x, void *b, long m, long a, char *s);
void scramble_inletinfo(t_scramble *x, void *b, long a, char *t);

t_scramble *scramble_new(t_symbol *s, short ac, t_atom *av);
void scramble_free(t_scramble *x);

void scramble_bang(t_scramble *x);
void scramble_int(t_scramble *x, t_atom_long v);
void scramble_float(t_scramble *x, double v);
void scramble_anything(t_scramble *x, t_symbol *msg, long ac, t_atom *av);

DEFINE_STANDARD_MAXDEPTH_SETTER(t_scramble);
DEFINE_STANDARD_MINDEPTH_SETTER(t_scramble);

t_class *scramble_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.scramble", (method)scramble_new, (method)scramble_free, (long) sizeof(t_scramble), 0L, A_GIMME, 0);
	
	// @method llll @digest Scramble the llll
	// @description A random permutation of the llll and its sublists, 
	// within the depth range set by the <m>mindepth</m> and <m>maxdepth</m> attributes,
	// is returned.
	class_addmethod(c, (method)scramble_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)scramble_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)scramble_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)scramble_anything,	"list",			A_GIMME,	0);
	
	
	class_addmethod(c, (method)scramble_bang,		"bang",			0);
	
	class_addmethod(c, (method)scramble_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)scramble_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	
	
	CLASS_ATTR_LONG(c, "mindepth",	0,	t_scramble, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");
	CLASS_ATTR_BASIC(c, "mindepth", 0);
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_scramble);
	// @description @copy BACH_DOC_MINDEPTH

	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_scramble, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);	
	CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, t_scramble);
	// @description @copy BACH_DOC_MAXDEPTH
	
	class_register(CLASS_BOX, c);
	scramble_class = c;
	
	dev_post("bach.scramble compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void scramble_bang(t_scramble *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		scramble_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void scramble_int(t_scramble *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	scramble_anything(x, _sym_int, 1, &outatom);
}

void scramble_float(t_scramble *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	scramble_anything(x, _sym_float, 1, &outatom);
}

void scramble_anything(t_scramble *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll;
    if (msg != _sym_bang) {
        ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
    llll_scramble(ll, x->n_mindepth, x->n_maxdepth);
    x->n_ob.l_rebuild = 0;
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void scramble_assist(t_scramble *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll to be scrambled
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest The scrambled llll
	}
}

void scramble_inletinfo(t_scramble *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void scramble_free(t_scramble *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_scramble *scramble_new(t_symbol *s, short ac, t_atom *av)
{
	t_scramble *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	if ((x = (t_scramble *) object_alloc_debug(scramble_class))) {
		// @arg 0 @name depths @optional 1 @type list @digest Depth options
		// @description If there is only one argument, it sets <m>maxdepth</m>.
		// If there are two arguments, they set respectively <m>mindepth</m> and <m>maxdepth</m>.
		true_ac = attr_args_offset(ac, av);
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
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
