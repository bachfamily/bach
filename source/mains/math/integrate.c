/*
 *  integrate.c
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
	integrate.c
	
	@name 
	bach.integrate
	
	@realname 
	bach.integrate

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Integrate functions
	
	@description
	Computes the integral of a breakpoint function or of a general function defined via a lambda loop.
	
	@discussion
	
	@category
	bach, bach objects, bach math

 	@keywords
	integrate, integral function, function, breakpoint function, lambda loop, calculate

	@seealso
	bach.derive, bach.expr, bach.slot, bach.reducefunction
	
	@owner
	Daniele Ghisi
*/


#include "foundation/bach.h"
#include "foundation/llllobj.h"
#include "foundation/llll_commons_ext.h"
#include "math/bach_math_utilities.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 


#define	CONST_MAX_ORDER		1000

typedef struct _integrate
{
	struct llllobj_object 	n_ob;

	char				mode; // 0 = auto mode: takes a bpf, returns a bpf – 1 = lambda mode: takes (0 1) 100, returns bpf 
	
	long				num_samples;
	
	long				order; // number of integrations to be performed
	double				origin[CONST_MAX_ORDER]; // origin of each integration
	
	char				creating_new_obj;
	
	void				*n_proxy;
	long				n_in;
	
	double				n_lambda_return;
} t_integrate;


void integrate_assist(t_integrate *x, void *b, long m, long a, char *s);
void integrate_inletinfo(t_integrate *x, void *b, long a, char *t);

t_integrate *integrate_new(t_symbol *s, short ac, t_atom *av);
void integrate_free(t_integrate *x);

void integrate_bang(t_integrate *x);
void integrate_int(t_integrate *x, t_atom_long num);
void integrate_float(t_integrate *x, double num);
void integrate_anything(t_integrate *x, t_symbol *msg, long ac, t_atom *av);

t_max_err integrate_setattr_origin(t_integrate *x, void *attr, long ac, t_atom *av);

t_class *integrate_class;

t_max_err integrate_setattr_origin(t_integrate *x, void *attr, long ac, t_atom *av)
{
	long i;
	long max_i = x->creating_new_obj ? ac : MIN(ac, x->order);
	for (i = 0; i < max_i; i++)
		x->origin[i] = is_atom_number(av + i) ? atom_getfloat(av + i) : 0;
	if (!x->creating_new_obj) {
		for (; i < x->order; i++)
			x->origin[i] = 0;
	}
	return MAX_ERR_NONE;
}


void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.integrate", (method)integrate_new, (method)integrate_free, (long) sizeof(t_integrate), 0L, A_GIMME, 0);
	
	// @method llll @digest Integrate breakpoint function or lambda-defined function
	// @description In auto mode (see arguments), an <m>llll</m> in the first inlet is considered to be a breakpoint function
	// defined as a sequence of points in the form <b>[<m>x</m> <m>y</m> <m>slope</m>]</b>. Such function
	// is integrated exactly if the function is piecewise linear, i.e. all slopes are negligible; otherwise
	// the integration is performed via a sampling process (the original function is sampled in a certain number
	// of points, defined by the <m>numsamples</m> attribute).
	// The resulting integral function is output in the same breakpoint function form from the left outlet
	// (all slopes will be 0: output function is always piecewise linear). <br />
	// In lambda mode (see arguments), an <m>llll</m> in the first inlet must be either in the form 
	// <b>[<m>domain_start</m> <m>domain_end</m>] <m>num_sampling_points</m></b>, or must be a plain list of
	// explicit sampling points (points in which integral function should be sampled). The domain points are output one by one
	// from the lamdba outlet, and values of the function to integrate are collected in the lambda inlet. 
	// After the integration, the resulting integral function is output in the breakpoint function form 
	// explained above from the left outlet. <br />
	// An <m>llll</m> in the second inlet is converted into a <m>float</m>.
	class_addmethod(c, (method)integrate_anything,					"anything",				A_GIMME,	0);

	
	// @method number @digest Lambda inlet
	// @description Second inlet is a lambda inlet.
	// @copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	// In this case the answer is expected to be a the value of the function to be integrated,
	// corresponding to the output domain value.
	// The lambda inlet also accepts the result in llll form, so you can sometimes avoid the explicit @out t. <br />
	// @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	class_addmethod(c, (method)integrate_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)integrate_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)integrate_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Output result
	// @description Output the integrated function, based on the most recently received input data.
	class_addmethod(c, (method)integrate_bang,						"bang",		0);
	
	class_addmethod(c, (method)integrate_assist,					"assist",		A_CANT,		0);
	class_addmethod(c, (method)integrate_inletinfo,					"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);



	CLASS_ATTR_LONG(c, "numsamples", 0, t_integrate, num_samples); 
	CLASS_ATTR_STYLE_LABEL(c,"numsamples",0,"text","Number of Sampling Points");
	CLASS_ATTR_BASIC(c,"numsamples",0);
	// @description In the automatic mode (with no arguments) sets the number of samples for the incoming
	// breakpoint function. If the breakpoint function is purely piecewise linear (no slopes), this
	// number is ignored, and the actual points are used for precise integration. 

	CLASS_ATTR_DOUBLE_VARSIZE(c, "origin", 0, t_integrate, origin, order, CONST_MAX_ORDER);
	CLASS_ATTR_STYLE_LABEL(c,"origin",0,"text","Initial Value For Integration");
	CLASS_ATTR_ACCESSORS(c, "origin", (method)NULL, (method)integrate_setattr_origin);
	CLASS_ATTR_BASIC(c,"origin",0);
	// @description Sets the initial value of the integral function. If the <m>order</m> of the integration is
	// greater than one, one origin for each different integration step can be defined.
	
	CLASS_ATTR_LONG(c, "order", 0, t_integrate, order); 
	CLASS_ATTR_STYLE_LABEL(c,"order",0,"text","Order");
	CLASS_ATTR_BASIC(c,"order",0);
	CLASS_ATTR_FILTER_MAX(c, "order", CONST_MAX_ORDER);
	CLASS_ATTR_FILTER_MIN(c, "order", 0);
	// @description Sets the order of the integration, i.e. the number of times the integration should be subsequently performed.
	
	
	class_register(CLASS_BOX, c);
	integrate_class = c;
	
	dev_post("bach.integrate compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void integrate_bang(t_integrate *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void integrate_int(t_integrate *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	integrate_anything(x, _llllobj_sym_list, 1, argv);
}

void integrate_float(t_integrate *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	integrate_anything(x, _llllobj_sym_list, 1, argv);
}

t_llll *integrate_with_lambda_once(t_integrate *x, t_llll *x_points, double origin, char only_sample_dont_integrate)
{
	t_llll *out = llll_get();
	double res = origin;
	double prev_x = 0, prev_y = 0;
	t_llllelem *elem;
	
	for (elem = x_points->l_head; elem; elem = elem->l_next) {
		double this_x, this_y;
		
		this_x = hatom_getdouble(&elem->l_hatom);
		
		x->n_lambda_return = 0;
		llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 1, this_x);

		this_y = x->n_lambda_return;
		
		if (elem->l_prev)  
			res += (this_y + prev_y) * (this_x - prev_x)/2.;

		if (only_sample_dont_integrate)
			llll_appendllll(out, double_triplet_to_llll(this_x, this_y, 0), 0, WHITENULL_llll);
		else 
			llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
		
		prev_x = this_x; 
		prev_y = this_y;
	}
	return out;
}


void integrate_anything(t_integrate *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll;
	long order = x->order;
	long num_samples = x->num_samples;
	
	if (proxy_getinlet((t_object *) x) == 0) {

		if (msg == _sym_clear) {
			llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
			return;
		}
		
		if (msg != _sym_bang) {
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
			x->n_ob.l_rebuild = 1;
		}

		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		
		if (ll) {
			
			if (x->mode == 0) { // automatic mode
				long i;
				for (i = 0; i < x->order; i++) {
					double this_origin = x->origin[i];
					t_llll *res = integrate_bpf(ll, 0, 0, num_samples, this_origin, true);
					llll_free(ll);
					ll = res;
				}
			} else {
				double domain_start = 0, domain_end = 1;
				long this_num_sampling_points = 101;
				long this_order;
				if (ll->l_depth > 1) { // shortcut for sampling domain points
					if (ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_LLLL) {
						t_llll *domain_ll = hatom_getllll(&ll->l_head->l_hatom);
						if (domain_ll && domain_ll->l_head) {
							if (is_hatom_number(&domain_ll->l_head->l_hatom))
								domain_start = hatom_getdouble(&domain_ll->l_head->l_hatom);
							if (domain_ll->l_head->l_next && is_hatom_number(&domain_ll->l_head->l_next->l_hatom))
								domain_end = hatom_getdouble(&domain_ll->l_head->l_next->l_hatom);
						}
						if (ll->l_head->l_next && is_hatom_number(&ll->l_head->l_next->l_hatom))
							this_num_sampling_points = hatom_getlong(&ll->l_head->l_next->l_hatom);
					}
					llll_free(ll);
					
					t_hatom start, end, step;
                    double step_double = (domain_end-domain_start)/(this_num_sampling_points - 1);
					hatom_setdouble(&start, domain_start);
					hatom_setdouble(&end, domain_end);
					hatom_setdouble(&step, step_double);
                    if (step_double == 0) {
                        ll = llll_get();
                        for (long i = 0; i < this_num_sampling_points; i++)
                            llll_appendhatom_clone(ll, &start);
                    } else
                        ll = llll_arithmser(start, end, step, 0, (t_object *) x);
				}
				
				double this_origin = x->origin[0];
				t_llll *sampling_x = ll;
				t_llll *first_int = integrate_with_lambda_once(x, sampling_x, this_origin, order <= 0);
				
				ll = first_int;
				
				for (this_order = 1; this_order < order; this_order ++) {
					this_origin = x->origin[this_order];
					t_llll *res = integrate_bpf_with_explicit_sampling(ll, sampling_x, this_origin);
					llll_free(ll);
					ll = res;
				}
				
				llll_free(sampling_x);
			}
			
			// remove equal points
			t_llllelem *elem;
			for (elem = ll->l_head; elem && elem->l_next; elem = elem->l_next) {
				if (llll_eq_ignoretype(hatom_getllll(&elem->l_hatom), hatom_getllll(&elem->l_next->l_hatom)))
					llll_destroyelem(elem->l_next);
			}
			
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
		
		}
		
		x->n_ob.l_rebuild = 0;
		integrate_bang(x);
	} else {
		// answer of a lambda loop
		if (msg == LLLL_NATIVE_MSG) {
			t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
			if (lambda_llll && lambda_llll->l_head && is_hatom_number(&lambda_llll->l_head->l_hatom))
				x->n_lambda_return = hatom_getdouble(&lambda_llll->l_head->l_hatom);
			else
				x->n_lambda_return = 0;
			llll_free(lambda_llll);
		} else {
			x->n_lambda_return = ac && is_atom_number(av) ? atom_getfloat(av) : 0;
		}
		
	}
}


void integrate_assist(t_integrate *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) 
			// @in 0 @type bang/llll @digest Breakpoint function llll or sampling parameters
			// @description In auto mode, an <m>llll</m> in the first inlet is the breakpoint function to be integrated. 
			// In lambda mode, a flat <m>llll</m> contains an explicit sampling, whereas an <m>llll</m> in the form
			// <b>[<m>domain_start</m> <m>domain_end</m>] <m>num_sampling_points</m></b> sets an uniform sampling.
			sprintf(s, x->mode == 0 ? "llll: Breakpoint Function" : "llll: Domain and Number of Sampling Points");
		else // @in 1 @type number/llll @digest Lambda inlet
			// @description @copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
			// In this case, the answer is supposed to be the Y value of the function at the X point which has been sent out.
			// @copy BACH_DOC_LAMBDA_GENERAL_WARNING
			sprintf(s, "llll: Lambda Inlet");
	} else {
		char *type = NULL; 
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) // @out 0 @type llll @digest Integrated breakpoint function llll
			// @description The llll with the integrated breakpoint function, as a list of points, where each
			// point is in the form <b>[<m>x</m> <m>y</m> 0]</b>. Notice that the slope is always 0, since the
			// output function is always piecewise linear.
			sprintf(s, "llll (%s): Integrated Breakpoint Function", type);
		else // @out 1 @type llll @digest Lambda Outlet
			// @description @copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
			// In this case, domain X values are output one by one, and expect to be mapped to the corresponding Y values,
			// to be plugged in the lambda inlet.
			//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
			sprintf(s, "llll (%s): Lambda Outlet", type);
	}
}

void integrate_inletinfo(t_integrate *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void integrate_free(t_integrate *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_integrate *integrate_new(t_symbol *s, short ac, t_atom *av)
{
	t_integrate *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	long true_ac = attr_args_offset(ac, av);

	if ((x = (t_integrate *) object_alloc_debug(integrate_class))) {

		x->num_samples = 100;
		x->order = 1;
		x->origin[0] = 0;
		x->creating_new_obj = true;
		
		// @arg 0 @name mode @optional 1 @type symbol @digest Mode
		// @description If there is no argument or if the argument is the <b>auto</b> symbol, 
		// the operation mode is the automatic mode: the object has just one inlet and one outlet,
		// and expects as input an incoming breakpoint function, which will be integrated.
		// If the argument is the <b>lambda</b> symbol, the object is instantiated in lambda mode:
		// the function is now defined via a lambda loop: X values are output through the lambda
		// outlet and expect to be mapped on the desired Y values, to be plugged in the lambda inlet.

		if (true_ac == 1 && atom_gettype(av) == A_SYM && atom_getsym(av) == _llllobj_sym_lambda)
			x->mode = 1;
		else
			x->mode = 0;
		
		attr_args_process(x, ac, av);
		
		llllobj_obj_setup((t_llllobj_object *) x, 1, x->mode == 1 ? "44" : "4");

		if (x->mode == 1)
			x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
		x->creating_new_obj = false;
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

