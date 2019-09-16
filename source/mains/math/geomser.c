/*
 *  geomser.c
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
 geomser.c
 
 @name 
 bach.geomser
 
 @realname 
 bach.geomser
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Geometric series
 
 @description
 Compute geometric series
 
 @discussion
 
 @category
 bach, bach objects, bach math
 
 @keywords
 series, geometric, factor, compute, calculate

 @seealso
 bach.primeser, bach.arithmser, bach.recurser
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _geomser
{
	t_llllobj_object 	n_ob;
	t_hatom				n_start;
	t_hatom				n_end;
	t_hatom				n_factor;
	t_atom_long			n_maxcount;
	long				n_in;
	void				*n_proxy[4];
	t_bach_atomic_lock	n_lock;
} t_geomser;


void geomser_assist(t_geomser *x, void *b, long m, long a, char *s);
void geomser_inletinfo(t_geomser *x, void *b, long a, char *t);

t_geomser *geomser_new(t_symbol *s, short ac, t_atom *av);
void geomser_free(t_geomser *x);

void geomser_bang(t_geomser *x);
void geomser_int(t_geomser *x, t_atom_long v);
void geomser_float(t_geomser *x, double v);

void geomser_anything(t_geomser *x, t_symbol *msg, short ac, t_atom *av);

t_max_err geomser_parse_llll(t_geomser *x, t_llll *inlist, long inlet, const char *err_str);


t_class *geomser_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.geomser", (method)geomser_new, (method)geomser_free, (short)sizeof(t_geomser), 0L, A_GIMME, 0);

	class_addmethod(c, (method)geomser_int,		"int",			A_LONG, 0);

	// @method llll @digest Set start, limit, factor, maximum number of items
	// @description 
	// In first inlet: starting value of the series, limit value of the series, factor and maximum number of items.
	// The limit value and maximum number of items can be replaced by the word <m>none</m>.
	// Values set to <m>none</m> are calculated according to the other values if possible.
	// If all the parameters are set, the stronger requirement between ending and maximum number of items is respected.
	// An llll received in the first inlet cause the series to be output.<br />
	// In second inlet: limit value, factor and maximum number of items.<br />
	// In third inlet: factor and maximum number of items.<br />
	// In fourth inlet: maximum number of items.<br />
	// In each inlet, if the incoming llll is shorter than described above, the missing parameters are left unchanged.

	// @method number @digest Set start, limit, factor or maximum number of items
	// @description 
	// In first inlet: sets the starting of the series and output the series.<br />
	// In second inlet: sets the limit value of the series, which can also be set to <m>none</m> if no limit is needed.<br />
	// In third inlet: sets the factor of the series.<br />
	// In fourth inlet: sets the maximum number of items in the series, which can also be set to <m>none</m> if no maximum is needed.<br />
	// Values set to <m>none</m> are calculated according to the other values if possible.
	// If all the parameters are set, the stronger requirement between ending and maximum number of items is respected.
	

	class_addmethod(c, (method)geomser_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)geomser_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)geomser_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)geomser_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the geometric series
	// @description A bang outputs the geometric series of primes according to the most recently received parameters.
	class_addmethod(c, (method)geomser_bang,		"bang",			0);
	class_addmethod(c, (method)geomser_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)geomser_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	geomser_class = c;
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	dev_post("bach.geomser compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void geomser_bang(t_geomser *x)
{	
	long err;
	if (x->n_ob.l_rebuild != 0) {
		llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, 
							 llll_geomser((t_object *) x, x->n_start, x->n_end, x->n_factor, x->n_maxcount, &err), 0);
		x->n_ob.l_rebuild = err;
	}
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void geomser_int(t_geomser *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	geomser_anything(x, _sym_int, 1, &outatom);
}

void geomser_float(t_geomser *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	geomser_anything(x, _sym_float, 1, &outatom);
}

void geomser_anything(t_geomser *x, t_symbol *msg, short ac, t_atom *av)
{
	t_max_err err;
	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
	
	long inlet = proxy_getinlet((t_object *) x);
	if (!inlist)
		return;
	err = geomser_parse_llll(x, inlist, inlet, "Invalid input llll");
	llll_free_nocheck(inlist); // because it can contain A_NOTHING elements
	if (err)
		return;
	x->n_ob.l_rebuild = 1;
	if (inlet == 0)
		geomser_bang(x);	
}

t_max_err geomser_parse_llll(t_geomser *x, t_llll *inlist, long inlet, const char *err_str)
{
	t_llllelem *elem;
	long i;
	t_hatom nothing;
	nothing.h_type = H_NOTHING;
	
	if (inlist->l_depth > 1 || inlist->l_size < 1 || inlist->l_size > 4 - inlet) {
		object_error((t_object *) x, "Invalid input llll");
		llll_free(inlist);
		return MAX_ERR_GENERIC;
	}
	
	for (i = inlet, elem = inlist->l_head; elem; elem = elem->l_next, i++) {
		if (!hatom_is_number(&elem->l_hatom) &&
			(i == 0 || hatom_getsym(&elem->l_hatom) != _sym_none)) {
			object_error((t_object *) x, "Invalid input llll");
			llll_free(inlist);
			return MAX_ERR_GENERIC;
		}
	}
	
	for (i = 0; i < inlet; i++)
		llll_prependhatom(inlist, &nothing, 0, WHITENULL_llll);
	
	elem = inlist->l_head;
	bach_atomic_lock(&x->n_lock);
	if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
		x->n_start = elem->l_hatom;
	if ((elem = elem->l_next)) {
		if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
			x->n_end = elem->l_hatom;
		if ((elem = elem->l_next)) {
			if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
				x->n_factor = elem->l_hatom;
			if ((elem = elem->l_next))
				x->n_maxcount = hatom_getlong(&elem->l_hatom);
		}
	}
	bach_atomic_unlock(&x->n_lock);
	return MAX_ERR_NONE;
}

void geomser_assist(t_geomser *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "number/llll: Starting Value");		break;	// @in 0 @type number/llll @digest Starting value 
																			// @description If an llll is entered, it is expected to contain: start, limit, factor, maximum number of items (see <m>llll</m> message).
			case 1: sprintf(s, "number/llll: Ending Value");		break;	// @in 1 @type number/llll @digest Limit value
																			// @description If an llll is entered, it is expected to contain: limit, factor, maximum number of items (see <m>llll</m> message).
			case 2: sprintf(s, "number/llll: Factor");				break;	// @in 2 @type number/llll @digest Factor
																			// @description If an llll is entered, it is expected to contain: factor, maximum number of items (see <m>llll</m> message).
			case 3: sprintf(s, "int: Maximum Number of Elements");	break;	// @in 3 @type int @digest Maximum number of items
		}
	}
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Geometric series 
	}
}

void geomser_inletinfo(t_geomser *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void geomser_free(t_geomser *x)
{
	long i;
	for (i = 3; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_geomser *geomser_new(t_symbol *s, short ac, t_atom *av)
{
	t_geomser *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long i;

	if ((x = (t_geomser *) object_alloc_debug(geomser_class))) {
		// @arg 0 @name start @optional 1 @type number @digest Starting value
		// @description The starting value for the geometric series (see <m>llll</m> message).
		// Default is 1.

		// @arg 1 @name limit @optional 1 @type number/none @digest Limit value
		// @description The limit value for the geometric series, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>none</m>.

		// @arg 2 @name factor @optional 1 @type number @digest Factor
		// @description The multiplier for the arithmetic series (see <m>llll</m> message).
		// Default is 2.

		// @arg 3 @name max_items @optional 1 @type int/none @digest Maximum number of items
		// @description The maximum number of items in the output llll, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>none</m>.

		long true_ac = attr_args_offset(ac, av);
		hatom_setlong(&x->n_start, 1);
		attr_args_process(x, ac, av);
		for (i = 3; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		if (true_ac) {
			t_llll *def_llll = llll_parse(true_ac, av);
			if (def_llll) {
				if (geomser_parse_llll(x, def_llll, 0, "Bad arguments") == MAX_ERR_NONE)
					x->n_ob.l_rebuild = 1;
				llll_free(def_llll);
				
			}
		}
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
