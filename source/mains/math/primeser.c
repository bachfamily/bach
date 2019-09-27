/*
 *  primeser.c
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
 primeser.c
 
 @name 
 bach.primeser
 
 @realname 
 bach.primeser
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Series of prime numbers
 
 @description
 Returns series of prime numbers, with a minimum, maximum and optional maximum numbers of items.
 
 @discussion
 Even in 64-bit mode, no prime number bigger than 2147483647 can be output.
 
 @category
 bach, bach objects, bach llll, bach math
 
 @keywords
 series, prime, number

 @seealso
 bach.factorize, bach.prime, bach.arithmser, bach.geomser, bach.recurser
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _primeser
{
	struct llllobj_object 	n_ob;
	t_atom_long				n_min;
	t_atom_long				n_max;
	t_atom_long				n_maxcount;
	long					n_in;
	void					*n_proxy[3];
	t_bach_atomic_lock		n_lock;
} t_primeser;


void primeser_assist(t_primeser *x, void *b, long m, long a, char *s);
void primeser_inletinfo(t_primeser *x, void *b, long a, char *t);

t_primeser *primeser_new(t_symbol *s, short ac, t_atom *av);
void primeser_free(t_primeser *x);

t_max_err primeser_parse_llll(t_primeser *x, t_llll *inlist, long inlet, const char *err_str);

void primeser_bang(t_primeser *x);
void primeser_anything(t_primeser *x, t_symbol *msg, short ac, t_atom *av);
void primeser_int(t_primeser *x, t_atom_long l);
void primeser_float(t_primeser *x, double v);

t_class *primeser_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
	c = class_new("bach.primeser", (method)primeser_new, (method)primeser_free, (short)sizeof(t_primeser), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)primeser_int,		"int",			A_LONG, 0);
	class_addmethod(c, (method)primeser_float,		"float",		A_LONG, 0);

	// @method llll @digest Set minimum, maximum, maximum number of items
	// @description In first inlet: the minimum and maximum values of the series, and the maximum number of items. <br />
	// In second inlet; the maximum value of the series and the maximum number of items. <br />
	// In third inlet: the maximum number of items. <br />
	// If the maximum is set to <m>none</m>, no maximum is considered. This is the default.
	// If the maximum number of items is set to <m>none</m>, no maximum number of items is considered. The default is 1000.
	// If both are set to actual values, the stronger requirement between the two is respected.
	// Anyway, even in 64-bit mode no prime number bigger than 2147483647 can be output.<br />
	
	// @method int @digest Set minimum, maximum, maximum number of items
	// @description In first inlet: the minimum value of the series. <br />
	// In second inlet; the maximum value of the series. <br />
	// In third inlet: the maximum number of items. <br />
	// If the maximum is set to <m>none</m>, no maximum is considered. This is the default.
	// If the maximum number of items is set to <m>none</m>, no maximum number of items is considered. The default is 1000.
	// If both are set to actual values, the stronger requirement between the two is respected.
	// Anyway, even in 64-bit mode no prime number bigger than 2147483647 can be output.<br />
	class_addmethod(c, (method)primeser_anything,	"anything",		A_GIMME,	0);
	class_addmethod(c, (method)primeser_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the last operation
	// @description A bang outputs the series of primes according to the most recently received parameters.
	class_addmethod(c, (method)primeser_bang,		"bang",			0);
	class_addmethod(c, (method)primeser_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)primeser_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	primeser_class = c;
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	dev_post("bach.primeser compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void primeser_bang(t_primeser *x)
{	
	if (x->n_ob.l_rebuild) {
		x->n_ob.l_rebuild = 0;
		llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, llll_primeser(x->n_min, x->n_max, x->n_maxcount), 0);
	}
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void primeser_int(t_primeser *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	primeser_anything(x, _sym_int, 1, &outatom);
}

void primeser_float(t_primeser *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	primeser_anything(x, _sym_float, 1, &outatom);
}

void primeser_anything(t_primeser *x, t_symbol *msg, short ac, t_atom *av)
{
	t_max_err err;
	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
	
	long inlet = proxy_getinlet((t_object *) x);
	if (!inlist)
		return;
	err = primeser_parse_llll(x, inlist, inlet, "Invalid input llll");
	llll_free_nocheck(inlist); // because it can contain A_NOTHING elements
	if (err)
		return;
	x->n_ob.l_rebuild = 1;
	if (inlet == 0)
		primeser_bang(x);
}

void primeser_assist(t_primeser *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "int/llll: Starting Value");				break;	// @in 0 @type int/llll @digest Starting value 
																				// @description If an llll is entered, it is expected to contain: start, end, maximum number of items (see <m>llll</m> message).
			case 1: sprintf(s, "int: Ending Value");					break;	// @in 1 @type int @digest Maximum
			case 2: sprintf(s, "int: Maximum Number of Elements");		break;	// @in 2 @type int @digest Maximum number of items
		}
	}
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Series of primes 
	}
}

void primeser_inletinfo(t_primeser *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void primeser_free(t_primeser *x)
{
	long i;
	for (i = 2; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_max_err primeser_parse_llll(t_primeser *x, t_llll *inlist, long inlet, const char *err_str)
{
	t_llllelem *elem;
	long i;
	t_atom_long l;
	t_hatom nothing;
	nothing.h_type = H_NOTHING;
	
	if (inlist->l_depth > 1 || inlist->l_size < 1 || inlist->l_size > 3 - inlet) {
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
	if (hatom_gettype(&elem->l_hatom) != H_NOTHING) {
		l = hatom_getlong(&elem->l_hatom);
#ifdef C74_X64
		if (l > 0x7fffffff) {
			object_warn((t_object *) x, "Numbers bigger than %ld are not taken into account", 0x7fffffffl);
			l = 0;
		}		
#endif
		x->n_min = l;
	}
	if ((elem = elem->l_next)) {
		if (hatom_gettype(&elem->l_hatom) != H_NOTHING) {
			l = hatom_getlong(&elem->l_hatom);
			if (l == 0)
				l = 0x7fffffffl;
#ifdef C74_X64
			if (l > 0x7fffffffl) {
				object_warn((t_object *) x, "Numbers bigger than %ld are not taken into account", 0x7fffffffl);
				l = 0x7fffffffl;
			}		
#endif
			x->n_max = l;
		}
		if ((elem = elem->l_next)) {
			l = hatom_getlong(&elem->l_hatom);
#ifdef C74_X64
			if (l > 0x7fffffffl) {
				object_warn((t_object *) x, "Numbers bigger than %ld are not taken into account", 0x7fffffffl);
				l = 0x7fffffff;
			}		
#endif
			x->n_maxcount = l;
		}
			
	}
	bach_atomic_unlock(&x->n_lock);
	return MAX_ERR_NONE;
}

t_primeser *primeser_new(t_symbol *s, short ac, t_atom *av)
{
	t_primeser *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long i, true_ac;
	
	if ((x = (t_primeser *) object_alloc_debug(primeser_class))) {
		// @arg 0 @name minimum @optional 1 @type number @digest Minimum
		// @description The minimum value for the series (see <m>llll</m> message).
		// Default is 1.

		// @arg 1 @name maximum @optional 1 @type number/none @digest Maximum
		// @description The maximum value for the series, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>none</m>.

		// @arg 2 @name max_items @optional 1 @type int/none @digest Maximum number of items
		// @description The maximum number of items in the output llll, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>none</m>.
		
		true_ac = attr_args_offset(ac, av);
		for (i = 2; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		
		x->n_max = 0x7fffffff;
		x->n_maxcount = 1000;
		
		if (true_ac) {
			t_llll *def_llll = llll_parse(true_ac, av);
			if (def_llll) {
				if (primeser_parse_llll(x, def_llll, 0, "Bad arguments") == MAX_ERR_NONE)
					x->n_ob.l_rebuild = 1;
				llll_free(def_llll);
			}
		}
		
		attr_args_process(x, ac, av); 
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
