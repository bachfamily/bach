/*
 *  arithmser.c
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
 arithmser.c
 
 @name 
 bach.arithmser
 
 @realname 
 bach.arithmser
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Arithmetic series
 
 @description
 Compute aritmethic series
 
 @discussion
 
 @category
 bach, bach objects, bach math
 
 @keywords
 series, arithmetic, step, compute, calculate

 @seealso
 bach.primeser, bach.geomser, bach.recurser
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _arithmser
{
	t_llllobj_object 	n_ob;
	t_hatom				n_min;
	t_hatom				n_max;
	t_hatom				n_step;
	t_atom_long			n_maxcount;
	long				n_in;
	void				*n_proxy[4];
	t_bach_atomic_lock	n_lock;
} t_arithmser;


void arithmser_assist(t_arithmser *x, void *b, long m, long a, char *s);
void arithmser_inletinfo(t_arithmser *x, void *b, long a, char *t);

t_arithmser *arithmser_new(t_symbol *s, short ac, t_atom *av);
void arithmser_free(t_arithmser *x);

void arithmser_bang(t_arithmser *x);
void arithmser_int(t_arithmser *x, t_atom_long v);
void arithmser_float(t_arithmser *x, double v);

void arithmser_anything(t_arithmser *x, t_symbol *msg, short ac, t_atom *av);

t_max_err arithmser_parse_llll(t_arithmser *x, t_llll *inlist, long inlet, const char *err_str);


t_class *arithmser_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.arithmser", (method)arithmser_new, (method)arithmser_free, (long) sizeof(t_arithmser), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)arithmser_int,		"int",			A_LONG, 0);

	
	
	
	// @method llll @digest Set start, end, step, maximum number of items
	// @description 
	// In first inlet: starting and ending values of the series, step and maximum number of items.
	// The ending value and maximum number of items can be replaced by the word <m>none</m>.
	// Values set to <m>none</m> are calculated according to the other values if possible.
	// If all the parameters are set, the stronger requirement between ending and maximum number of items is respected.
	// An llll received in the first inlet cause the series to be output.<br />
	// In second inlet: ending value, step and maximum number of items.<br />
	// In third inlet: step and maximum number of items.<br />
	// In fourth inlet: maximum number of items.<br />
	// In each inlet, if the incoming llll is shorter than described above, the missing parameters are left unchanged.

	// @method number @digest Set start, end, step or maximum number of items
	// @description 
	// In first inlet: sets the starting of the series and output the series.<br />
	// In second inlet: sets the ending value of the series, which can also be set to <m>none</m> if no ending value is needed.<br />
	// In third inlet: sets the step of the series.<br />
	// In fourth inlet: sets the maximum number of items in the series, which can also be set to <m>none</m> if no maximum is needed.<br />
	// Values set to <m>none</m> are calculated according to the other values if possible.
	// If all the parameters are set, the stronger requirement between ending and maximum number of items is respected.
	
	class_addmethod(c, (method)arithmser_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)arithmser_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)arithmser_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)arithmser_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the arithmetic series
	// @description A bang outputs the arithmetic series according to the most recently received parameters.
	class_addmethod(c, (method)arithmser_bang,		"bang",			0);
	class_addmethod(c, (method)arithmser_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)arithmser_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	arithmser_class = c;
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	dev_post("bach.arithmser compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void arithmser_bang(t_arithmser *x)
{	
	if (x->n_ob.l_rebuild != 0) {
		x->n_ob.l_rebuild = 0;
		llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, llll_arithmser(x->n_min, x->n_max, x->n_step, x->n_maxcount, (t_object *) x), 0);
	}
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void arithmser_int(t_arithmser *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	arithmser_anything(x, _sym_int, 1, &outatom);
}

void arithmser_float(t_arithmser *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	arithmser_anything(x, _sym_float, 1, &outatom);
}

void arithmser_anything(t_arithmser *x, t_symbol *msg, short ac, t_atom *av)
{
	t_max_err err;
	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);

	long inlet = proxy_getinlet((t_object *) x);
	if (!inlist)
		return;
	err = arithmser_parse_llll(x, inlist, inlet, "Invalid input llll");
	llll_free_nocheck(inlist); // because it can contain A_NOTHING elements
	if (err)
		return;
	x->n_ob.l_rebuild = 1;
	if (inlet == 0)
		arithmser_bang(x);
}

t_max_err arithmser_parse_llll(t_arithmser *x, t_llll *inlist, long inlet, const char *err_str)
{
	t_llllelem *elem;
	long i;
	t_hatom nothing;
	nothing.h_type = H_NOTHING;
	
	if (inlist->l_depth > 1 || inlist->l_size < 1 || inlist->l_size > 4 - inlet) {
		object_error((t_object *) x, "Invalid input llll: wrong structure");
		return MAX_ERR_GENERIC;
	}
	
	for (i = 0, elem = inlist->l_head; elem; elem = elem->l_next, i++) {
		if (!hatom_is_number(&elem->l_hatom) && hatom_getsym(&elem->l_hatom) != _sym_none) {
			object_error((t_object *) x, "Invalid input llll: %s symbol unknown", hatom_getsym(&elem->l_hatom)->s_name);
			return MAX_ERR_GENERIC;
		}
	}
	
	for (i = 0; i < inlet; i++)
		llll_prependhatom(inlist, &nothing, 0, WHITENULL_llll);
	
	elem = inlist->l_head;
	bach_atomic_lock(&x->n_lock);
	if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
		x->n_min = elem->l_hatom;
	if ((elem = elem->l_next)) {
		if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
			x->n_max = elem->l_hatom;
		if ((elem = elem->l_next)) {
			if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
				x->n_step = elem->l_hatom;
			if ((elem = elem->l_next))
				x->n_maxcount = hatom_getlong(&elem->l_hatom);
		}
	}
	bach_atomic_unlock(&x->n_lock);
	return MAX_ERR_NONE;
}

void arithmser_assist(t_arithmser *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "number/pitch/llll: Starting Value");			break;	// @in 0 @type number/pitch/llll @digest Starting value
																				// @description If an llll is entered, it is expected to contain: start, end, step, maximum number of items (see <m>llll</m> message).
			case 1: sprintf(s, "number/pitch/none/llll: Ending Value");			break;	// @in 1 @type number/pitch/none/llll @digest Ending value
																				// @description If an llll is entered, it is expected to contain: end, step, maximum number of items (see <m>llll</m> message).
			case 2: sprintf(s, "number/pitch/none/llll: Step");					break;	// @in 2 @type number/number/none/llll @digest Step
																				// @description If an llll is entered, it is expected to contain: step, maximum number of items (see <m>llll</m> message).
			case 3: sprintf(s, "int: Maximum Number of Elements");		break;	// @in 3 @type int/none @digest Maximum number of items
		}
	}
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Arithmetic series 
	}
}

void arithmser_inletinfo(t_arithmser *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void arithmser_free(t_arithmser *x)
{
	long i;
	for (i = 3; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_arithmser *arithmser_new(t_symbol *s, short ac, t_atom *av)
{
	t_arithmser *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long i;
	
	if ((x = (t_arithmser *) object_alloc_debug(arithmser_class))) {
		// @arg 0 @name start @optional 1 @type number @digest Starting value
		// @description The starting value for the arithmetic series (see <m>llll</m> message).
		// Default is 0.

		// @arg 1 @name end @optional 1 @type number/none @digest Ending value
		// @description The ending value for the arithmetic series, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>none</m>.

		// @arg 2 @name step @optional 1 @type number/none @digest Step
		// @description The step value for the arithmetic series (see <m>llll</m> message).
		// Default is 1.

		// @arg 3 @name max_items @optional 1 @type int/none @digest Maximum number of items
		// @description The maximum number of items in the output llll, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>none</m>.

		long true_ac = attr_args_offset(ac, av);
		hatom_setlong(&x->n_min, 1);
		attr_args_process(x, ac, av);
		for (i = 3; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		if (true_ac) {
			t_llll *def_llll = llll_parse(true_ac, av);
			if (def_llll) {
				if (arithmser_parse_llll(x, def_llll, 0, "Bad arguments") == MAX_ERR_NONE)
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
