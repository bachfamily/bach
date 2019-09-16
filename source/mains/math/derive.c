/*
 *  derive.c
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
 derive.c
 
 @name 
 bach.derive
 
 @realname 
 bach.derive
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Derive functions
 
 @description
 Computes the derivative of a breakpoint function or of a general function defined via a lambda loop.
 
 @discussion
 
 @category
 bach, bach objects, bach math
 
 @keywords
 derive, derivative, function, breakpoint function, lambda loop

 @seealso
 bach.integrate, bach.expr, bach.slot, bach.reducefunction
 
 @owner
 Daniele Ghisi
 */


#include "bach.h"
#include "llllobj.h"
#include "llll_commons_ext.h"
#include "bach_math_utilities.h"
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

typedef struct _derive
{
	struct llllobj_object 	n_ob;
	
	char				mode; // 0 = auto mode: takes a bpf, returns a bpf – 1 = lambda mode: takes (0 1) 100, returns bpf 
	char				discrete;	// 0 = exact derivative: the derivation of a piecewise linear function is a piecewise constant function
									// 1 = discrete derivative: the derivation of a piecewise linear funcion is a piecewise linear 
									//	   function (each derivative point being mapped on the mean point of the segment)
	char				discrete_derivative_pad;	// The discrete derivative has one point less than the original function. What do we do?
													// 0 = no pad, 1 = pad at right, 2 = pad at left, 3 = pad at center
	
	long				num_samples;
	
	long				order; // number of derivations to be performed
	
	void				*n_proxy;
	long				n_in;
	
	double				n_lambda_return;
} t_derive;


void derive_assist(t_derive *x, void *b, long m, long a, char *s);
void derive_inletinfo(t_derive *x, void *b, long a, char *t);

t_derive *derive_new(t_symbol *s, short ac, t_atom *av);
void derive_free(t_derive *x);

void derive_bang(t_derive *x);
void derive_int(t_derive *x, t_atom_long num);
void derive_float(t_derive *x, double num);
void derive_anything(t_derive *x, t_symbol *msg, long ac, t_atom *av);

t_max_err derive_setattr_discrete(t_derive *x, t_object *attr, long ac, t_atom *av);

t_class *derive_class;

t_max_err derive_setattr_discrete(t_derive *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (atom_gettype(av) == A_LONG || atom_gettype(av) == A_FLOAT)
			x->discrete = CLAMP(atom_getlong(av), 0, 1);
		else
			x->discrete = 0;
		object_attr_setdisabled((t_object *)x, gensym("pad"), x->discrete == 0);
	}
	
	return MAX_ERR_NONE;
}



int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.derive", (method)derive_new, (method)derive_free, (short)sizeof(t_derive), 0L, A_GIMME, 0);
	
	// @method llll @digest Derive breakpoint function or lambda-defined function
	// @description In auto mode (see arguments), an <m>llll</m> in the first inlet is considered to be a breakpoint function
	// defined as a sequence of points in the form <b>[<m>x</m> <m>y</m> <m>slope</m>]</b>. Such function
	// is derived exactly if the function is piecewise linear, i.e. all slopes are negligible; otherwise
	// the derivation is performed via a sampling process (the original function is sampled in a certain number
	// of points, defined by the <m>numsamples</m> attribute).
	// The resulting derivative is output in the same breakpoint function form from the left outlet
	// (all slopes will be 0: output function is always piecewise linear). <br />
	// In lambda mode (see arguments), an <m>llll</m> in the first inlet must be either in the form 
	// <b>[<m>domain_start</m> <m>domain_end</m>] <m>num_sampling_points</m></b>, or must be a plain list of
	// explicit sampling points (points in which derivative function should be sampled). The domain points are output one by one
	// from the lamdba outlet, and values of the function to derive are collected in the lambda inlet. 
	// After deriving, the resulting derivative function is output in the breakpoint function form 
	// explained above from the left outlet. <br />
	// An <m>llll</m> in the second inlet is converted into a <m>float</m>.
	class_addmethod(c, (method)derive_anything,					"anything",				A_GIMME,	0);
	
	
	// @method number @digest Lambda inlet
	// @description Second inlet is a lambda inlet.
	// @copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
	// In this case the answer is expected to be a the value of the function to be derived,
	// corresponding to the output domain value.
	// The lambda inlet also accepts the result in llll form, so you can sometimes avoid the explicit @out t. <br />
	// @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	class_addmethod(c, (method)derive_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)derive_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)derive_anything,					"list",					A_GIMME,	0);
	
	// @method bang @digest Output result
	// @description Output the derivative function, based on the most recently received input data.
	class_addmethod(c, (method)derive_bang,						"bang",		0);
	
	class_addmethod(c, (method)derive_assist,					"assist",		A_CANT,		0);
	class_addmethod(c, (method)derive_inletinfo,					"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	
	CLASS_ATTR_LONG(c, "numsamples", 0, t_derive, num_samples); 
	CLASS_ATTR_STYLE_LABEL(c,"numsamples",0,"text","Number of Sampling Points");
	CLASS_ATTR_BASIC(c,"numsamples",0);
	// @description In the automatic mode (with no arguments) sets the number of samples for the incoming
	// breakpoint function. If the breakpoint function is purely piecewise linear (no slopes), this
	// number is ignored, and the actual points are used for precise derivative. 
	
	CLASS_ATTR_LONG(c, "order", 0, t_derive, order); 
	CLASS_ATTR_STYLE_LABEL(c,"order",0,"text","Order");
	CLASS_ATTR_BASIC(c,"order",0);
	CLASS_ATTR_FILTER_MAX(c, "order", CONST_MAX_ORDER);
	CLASS_ATTR_FILTER_MIN(c, "order", 0);
	// @description Sets the order of the derivative, i.e. the number of times the derivative should be subsequently performed.

	CLASS_ATTR_CHAR(c, "discrete", 0, t_derive, discrete); 
	CLASS_ATTR_STYLE_LABEL(c,"discrete",0,"onoff","Output Discrete Derivative");
	CLASS_ATTR_BASIC(c,"discrete",0);
	CLASS_ATTR_FILTER_CLIP(c,"discrete", 0, 1);
	// @description Toggles the ability to choose between discrete derivative and continuous derivative.
	// If this attribute is active, for each couple of incoming points a derivative point is computed
	// and placed at the mean point of their X coordinates. However, if this attribute is set to 0 (default), for each incoming segment 
	// two values are output: one at the beginning of the segment, and one at the end of the segment, with the same Y coordinate,
	// retaining the original X coordinates of the segment. As a result, a piecewise linear function is mapped to a 
	// piecewise constant function. The number of points, thus, in this case essentially doubles the original number (up to 
	// a final sieving of useless function points).

	
	CLASS_ATTR_CHAR(c, "pad", 0, t_derive, discrete_derivative_pad); 
	CLASS_ATTR_STYLE_LABEL(c,"pad",0,"enumindex","Discreted Derivative Pad");
	CLASS_ATTR_ENUMINDEX(c,"pad", 0, "No Pad Pad At Left Pad At Right Pad At Left And Right"); 
	CLASS_ATTR_FILTER_CLIP(c,"pad", 0, 3);
	// @description If <m>discrete</m> is set to 1, the output discrete derivative is output.
	// Such derivative, by construction, has one point less than the original number of data. This <m>pad</m> attribute handles the 
	// possible padding behavior: <br />
	// - No Pad: output number of points will be the original number of points minus one. All output X coordinates are mean points
	// of each incoming segment. <br />
	// - Pad At Right (Default): output number of points will be the same as the original number of points. All output X coordinates are ending points
	// of each incoming segment, and a starting point is added. <br />
	// - Pad At Left: output number of points will be the same as the original number of points. All output X coordinates are starting points
	// of each incoming segment, and a final point is added. <br />
	// - Pad At Left And Right: output number of points will be the original number of points plus one. All output X coordinates are mean points
	// of each incoming segment, and a starting and final points are added. <br />
	// The padding, in all cases, is done by preserving the derivative, i.e. by constant extrapolation of the derivative.
	
	
	
	class_register(CLASS_BOX, c);
	derive_class = c;
	
	dev_post("bach.derive compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void derive_bang(t_derive *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void derive_int(t_derive *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	derive_anything(x, _llllobj_sym_list, 1, argv);
}

void derive_float(t_derive *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	derive_anything(x, _llllobj_sym_list, 1, argv);
}

t_llll *derive_with_lambda_once(t_derive *x, t_llll *x_points, char only_sample_dont_derive, char discrete_derivative, char discrete_derivative_pad)
{
	t_llll *out = llll_get();
	double res = 0;
	double prev_x = 0, prev_y = 0;
	t_llllelem *elem;
	
	for (elem = x_points->l_head; elem; elem = elem->l_next) {
		double this_x, this_y;
		
		this_x = hatom_getdouble(&elem->l_hatom);
		
		x->n_lambda_return = 0;
		llllobj_outlet_float((t_object *) x, LLLL_OBJ_VANILLA, 1, this_x);
		
		this_y = x->n_lambda_return;
		
		if (elem->l_prev) 
			res = (this_y - prev_y) / (this_x - prev_x);

		if (only_sample_dont_derive)
			llll_appendllll(out, double_triplet_to_llll(this_x, this_y, 0), 0, WHITENULL_llll);
		else if (elem->l_prev) {
			if (discrete_derivative) {
				if (!elem->l_prev->l_prev && (discrete_derivative_pad == 1 || discrete_derivative_pad == 3)) 
					llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);

				if (discrete_derivative_pad == 1)
					llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
				else if (discrete_derivative_pad == 2)
					llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
				else
					llll_appendllll(out, double_triplet_to_llll((prev_x + this_x)/2., res, 0), 0, WHITENULL_llll);

				if (!elem->l_next && (discrete_derivative_pad == 2 || discrete_derivative_pad == 3)) 
					llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
			} else {
				llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
				llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
			}
		}
		
		prev_x = this_x; 
		prev_y = this_y;
	}
	return out;
}


void derive_anything(t_derive *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll;
	long num_samples = x->num_samples;
	long order = x->order;
	char discrete_derivative = x->discrete;
	char discrete_derivative_pad = x->discrete_derivative_pad;
	
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
					t_llll *res = derive_bpf(ll, 0, 0, num_samples, true, true, discrete_derivative, discrete_derivative_pad);
					llll_free(ll);
					ll = res;
				}
			} else {
				double domain_start = 0, domain_end = 1;
				long this_num_sampling_points = 100;
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
						if (ll->l_head->l_next && hatom_gettype(&ll->l_head->l_next->l_hatom) == H_LONG)
							this_num_sampling_points = hatom_getlong(&ll->l_head->l_next->l_hatom);
					}
					llll_free(ll);
					
					t_hatom start, end, step;
					hatom_setdouble(&start, domain_start);
					hatom_setdouble(&end, domain_end);
					hatom_setdouble(&step, (domain_end-domain_start)/(this_num_sampling_points - 1));
					ll = llll_arithmser(start, end, step, 0, (t_object *) x);
				}
				
				t_llll *sampling_x = ll;
				t_llll *first_int = derive_with_lambda_once(x, sampling_x, order <= 0, discrete_derivative, discrete_derivative_pad);

				ll = first_int;
				
				for (this_order = 1; this_order < order; this_order ++) {
					t_llll *res = derive_bpf_with_explicit_sampling(ll, sampling_x, discrete_derivative, discrete_derivative_pad);
					llll_free(ll);
					ll = res;
				}
				
				llll_free(sampling_x);
			}
			
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
			
		}

		x->n_ob.l_rebuild = 0;
		derive_bang(x);

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


void derive_assist(t_derive *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) 
			// @in 0 @type bang/llll @digest Breakpoint function llll or sampling parameters
			// @description In auto mode, an <m>llll</m> in the first inlet is the breakpoint function to be derived. 
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
		if (a == 0) // @out 0 @type llll @digest Derived breakpoint function llll
			// @description The llll with the derived breakpoint function, as a list of points, where each
			// point is in the form <b>[<m>x</m> <m>y</m> 0]</b>. Notice that the slope is always 0, since the
			// output function is always piecewise linear.
			sprintf(s, "llll (%s): Derived Breakpoint Function", type);
		else // @out 1 @type llll @digest Lambda Outlet
			// @description @copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
			// In this case, domain X values are output one by one, and expect to be mapped to the corresponding Y values,
			// to be plugged in the lambda inlet.
			//  @copy BACH_DOC_LAMBDA_GENERAL_WARNING
			sprintf(s, "llll (%s): Lambda Outlet", type);
	}
}

void derive_inletinfo(t_derive *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void derive_free(t_derive *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_derive *derive_new(t_symbol *s, short ac, t_atom *av)
{
	t_derive *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	long true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_derive *) object_alloc_debug(derive_class))) {
		
		x->num_samples = 100;
		x->order = 1;
		x->discrete = 0;
		x->discrete_derivative_pad = 2;
		
		// @arg 0 @name mode @optional 1 @type symbol @digest Mode
		// @description If there is no argument or if the argument is the <b>auto</b> symbol, 
		// the operation mode is the automatic mode: the object has just one inlet and one outlet,
		// and expects as input an incoming breakpoint function, which will be derived.
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
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

