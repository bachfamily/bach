/*
 *  weights.c
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
 weights.c
 
 @name 
 bach.weights
 
 @realname 
 bach.weights
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Interpolate lllls according to weights
 
 @description
 Interpolate among multiple lllls according to weights.
 
 @discussion
 <o>bach.weights</o> is especially conceived to work in conjunction with the <o>nodes</o> object.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 interpolate, weight, linear combination

 @seealso
 bach.expr, bach.interp, bach.normalize, nodes
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"
#include "ext_critical.h"
#include "foundation/collector.h"
#include "math/llll_math.h"


typedef struct _weights
{
	t_llllobj_object 	n_ob;
	long				n_proxies;
	void				**n_proxy;
	long				n_in;
	long				n_scalarmode;
	long				n_mono;
	t_llll				*n_empty;
	t_collector			*n_collector;
} t_weights;


typedef struct _weights_iteration_data {
	t_collector	*w_collector;
	long		w_evaluate;
	t_llll		*w_weights;
	t_llllelem	*w_this_weight;
	t_hatom		w_sum; // data for one iteration of the incoming lllls
} t_weights_iteration_data;

void bach_weights_assist(t_weights *x, void *b, long m, long a, char *s);
void bach_weights_inletinfo(t_weights *x, void *b, long a, char *t);

t_weights *bach_weights_new(t_symbol *s, short ac, t_atom *av);
void bach_weights_free(t_weights *x);

void bach_weights_bang(t_weights *x);
void bach_weights_int(t_weights *x, t_atom_long v);
void bach_weights_float(t_weights *x, double v);
void bach_weights_anything(t_weights *x, t_symbol *msg, long ac, t_atom *av);

long bach_weights_get_data(t_weights_iteration_data *x, long list, t_llll *ll, char isaddress);
long bach_weights_cmd(t_weights_iteration_data *x, long cmd);

t_class *weights_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.weights", (method)bach_weights_new, (method)bach_weights_free, (long) sizeof(t_weights), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description
	// An llll in the first inlet is treated as a list of weight coefficients, each to be applied to one of the lllls to be interpolated.
	// The weighted lllls are then summed together element-wise, and the resulting llll is output. <br/>
	// An llll in any inlet but the first is stored, to be interpolated with respect to the weight coefficients. <br/>
	// If the object is in <m>mono</m> mode (see description of the object arguments), a single llll is expected in the second outlet.
	// In this case, each of its sublists will be interpolated with the corresponding weight coefficient. 
	class_addmethod(c, (method)bach_weights_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)bach_weights_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)bach_weights_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)bach_weights_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the last operation
	// @description Return the result of the interpolation of the most recently received lllls and weights.
	class_addmethod(c, (method)bach_weights_bang,		"bang",			0);
	
	class_addmethod(c, (method)bach_weights_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)bach_weights_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_LONG(c, "scalarmode",	0,	t_weights, n_scalarmode);
	CLASS_ATTR_FILTER_CLIP(c, "scalarmode", 0, 1);
	CLASS_ATTR_STYLE(c, "scalarmode", 0, "onoff");
	CLASS_ATTR_LABEL(c, "scalarmode", 0, "Scalar Mode");
	CLASS_ATTR_BASIC(c, "scalarmode", 0);
	// @description @copy BACH_DOC_SCALARMODE

	class_register(CLASS_BOX, c);
	weights_class = c;
	
	dev_post("bach.weights compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void bach_weights_bang(t_weights *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		bach_weights_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void bach_weights_int(t_weights *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	bach_weights_anything(x, _sym_int, 1, &outatom);
}

void bach_weights_float(t_weights *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	bach_weights_anything(x, _sym_float, 1, &outatom);
}

void bach_weights_anything(t_weights *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	long i;
	
	if (msg != _sym_bang) 
		x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet) ? 1 : 0;
	
	if (inlet == 0 && x->n_ob.l_rebuild) {
		t_weights_iteration_data data, *data_ptr = &data;
		t_llll *lists[255], *result, *biglist = NULL;
		data.w_weights = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
		long count;
		data.w_collector = x->n_collector;
		
		if (x->n_mono) {
			biglist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
			count = MIN(biglist->l_size, 255);
			t_llllelem *biglist_elem;
			for (biglist_elem = biglist->l_head, i = count - 1; i >= 0; biglist_elem = biglist_elem->l_next, i--) {
				if (biglist_elem->l_hatom.h_type == H_LLLL)
					lists[i] = hatom_getllll(&biglist_elem->l_hatom);
				else
					lists[i] = x->n_empty;
			}
		} else {
			count = MIN(data.w_weights->l_size, x->n_proxies);
			for (i = 0; i < count; i++) {
				lists[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, count - i, 0);			
			}
		}
		data.w_evaluate = 0;

		llll_iter(count, lists, -1, x->n_scalarmode, 1, 0, 2, 0, NULL, 
				  (iter_datafn) bach_weights_get_data, data_ptr, NULL, NULL, (iter_cmdfn) bach_weights_cmd, data_ptr, NULL, NULL, NULL, NULL);
		
		bach_weights_cmd(data_ptr, 0);
		result = collector_output(data.w_collector, 0, 0);
		collector_clear(data.w_collector);
		x->n_ob.l_rebuild = 0;
		if (x->n_mono) {
			llll_release(biglist);
		} else {
			for (i = 0; i < count; i++)
				llll_release(lists[i]);
		}
		llll_release(data.w_weights);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, result, 0);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}


long bach_weights_get_data(t_weights_iteration_data *x, long list, t_llll *ll, char isaddress) // never called for address
{
	if (x->w_evaluate && ll->l_size) {
		t_hatom res;
        if (x->w_this_weight) {
            hatom_op_times(&ll->l_head->l_hatom, &x->w_this_weight->l_hatom, &res);
            hatom_op_plus(&x->w_sum, &res, &x->w_sum);
            x->w_this_weight = x->w_this_weight->l_next;
        }
	} else
		x->w_evaluate = 0; // or, if no hatom is coming, tell the guy not to evaluate
	return 0;
}

long bach_weights_cmd(t_weights_iteration_data *x, long cmd)
{	
	if (x->w_evaluate) { // this is not true at the first call, or if no atom has been passed for at least one list
		t_llll *result_llll = llll_get();
		llll_appendhatom(result_llll, &x->w_sum, 0, WHITENULL_llll);
		collector_get(x->w_collector, result_llll, 0, 0);
	}
	if (cmd)
		collector_change_level(x->w_collector, cmd);
	x->w_this_weight = x->w_weights->l_head;
	hatom_setlong(&x->w_sum, 0);
	x->w_evaluate = 1;
	return 0;
}

void bach_weights_assist(t_weights *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) {
			sprintf(s, "llll: Weights"); // @in 0 @type llll @digest llll with weights
		} else {
			sprintf(s, "llll %ld to Interpolate", a); // @in 1 @type llll @digest llll to be interpolated
			// @description The first llll to be interpolated, or a list composed by sublists to be individually interpolated
			
			// @in 2 @loop 1 @type llll @digest llll to be interpolated
		}

	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Result", type); // @out 0 @type llll @digest Result of the interpolation
	}
}

void bach_weights_inletinfo(t_weights *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void bach_weights_free(t_weights *x)
{
	long i;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	bach_freeptr(x->n_proxy);
	collector_free(x->n_collector);
	llll_free(x->n_empty);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_weights *bach_weights_new(t_symbol *s, short ac, t_atom *av)
{
	t_weights *x = NULL;
	long i, proxies = 0;
	t_max_err err = 0;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_weights *) object_alloc_debug(weights_class))) {
		// @arg 0 @name count/mono @optional 1 @type int/mono @digest Number of lllls to weight
		// @description If an integer is given, inlets for the lllls to interpolate are created accordingly, 
		// in addition to the left inlet for the interpolation weights.
		// If the symbol <b>mono</b> is given, only one inlet is created in addition to the left inlet.
		// In this case, the second inlet should receive an llll composed by sublists to be interpolated.
		
		proxies = 1;
		x->n_mono = 1;
		if (true_ac) {
			long type = atom_gettype(av);
			if (type == A_SYM && atom_getsym(av) != gensym("mono"))
				object_warn((t_object *) x, "Bad argument");
			else if (type == A_LONG || type == A_FLOAT) {
				x->n_mono = 0;
				proxies = atom_getlong(av);
				if (proxies < 1) {
					object_warn((t_object *) x, "Bad number of inlets, setting to 1");
					proxies = 1;
				} else if (proxies > LLLL_MAX_INLETS) {
					object_warn((t_object *) x, "Too many outlets, setting to %ld", (long) LLLL_MAX_INLETS);
					proxies = LLLL_MAX_INLETS;
				}
			}
		}
		x->n_empty = llll_make();
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, proxies + 1, "4");
		x->n_proxies = MIN(proxies, LLLL_MAX_INLETS);
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
		x->n_collector = collector_new(1, 1);
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}
