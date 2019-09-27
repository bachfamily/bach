/*
 *  iter.c
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
	iter.c
	
	@name 
	bach.iter
	
	@realname 
	bach.iter

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Iterate through lllls
	
	@description 
	<o>bach.iter</o> traverses lllls depth-first, outputting their elements one by one.
	
	@discussion
	At each step of the iteration, <o>bach.iter</o> also report if it has entered or exited a sublist, 
	and the addresses of the elements corresponding to the step.
 
	@category
	bach, bach objects, bach llll

	@keywords
 	iterate, iteration, element, address, command

	@seealso
	bach.step, bach.collect, bach.drip, bach.mapelem, Iterations
	
	@owner
	Andrea Agostini
*/

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _iter
{
	t_llllobj_object 	n_ob;

	long				n_proxies;

	void				**n_proxy;
	long				n_in;
	long				n_lists;
	
	long				n_maxdepth;
	long				n_scalarmode;
	long				n_recursionmode;
	long				n_iterationmode;
	long				n_spikemode;
	long				n_unwrap;
	
	long				n_lambda;
	long				n_enter;
	long				n_stop;
} t_iter;


void iter_assist(t_iter *x, void *b, long m, long a, char *s);
void iter_inletinfo(t_iter *x, void *b, long a, char *t);

t_iter *iter_new(t_symbol *s, short ac, t_atom *av);
void iter_free(t_iter *x);

void iter_bang(t_iter *x);
void iter_int(t_iter *x, t_atom_long v);
void iter_float(t_iter *x, double v);
void iter_anything(t_iter *x, t_symbol *msg, long ac, t_atom *av);

long iter_shoot_llll(t_iter *x, long list, t_llll *ll, char isaddress);
long iter_shoot_cmd(t_iter *x, long cmd);
long iter_shoot_root(t_iter *x);
long iter_lambda(t_iter *x, t_llll *lambda_ll);

t_class *iter_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
	c = class_new("bach.iter", (method)iter_new, (method)iter_free, (short)sizeof(t_iter), 0L, A_GIMME, 0);
	
	
	// @method llll @digest Iterate through the llll
	// @description
	// All the lllls received in every llll inlet (that is, all except the rightmost one) are iterated in parallel, element by element.
	// This means that the first elements of all the lllls are output, then the second elements, and so on, from their respective dedicate outlets.
	// Along with each element, its address is output.
	// @copy BACH_DOC_ADDRESS_BASIC
	// Whenever a sublist is met, three scenarios are possible: <br/>
	// In the standard case, a positive integer is output from the rightmost inlet (according to the number of consecutive open parentheses),
	// then the sublist is entered and iterated through. <br/>
	// If the maximum depth has been reached (see the description of the <m>maxdeph</m> attribute),
	// then the sublist is treated as a "normal" element, that is it is output as a whole from the corresponding outlet and not entered.<br/>
	// If the <m>lambda</m> attribute is set to 1, a proposal is output from the rightmost outlet.
	// A proposal is an llll composed as follows: <br/>
	// <m>lambda ( &lt;element 1&gt; ( &lt;address 1 ) &gt; ) ( &lt;element 2&gt; ( &lt;address 2 ) &gt; ) ...</m><br/>
	// where at least one element is a sublist. When this happens, a 0 or 1 return value is expected in the rightmost inlet.
	// If the return value is 1, the behavior falls back to the standard case.
	// If the return value is 0, the sublist is treated as a "normal" element and not entered.
	// It must be remarked that the first proposal output in lambda mode, at the very beginning of the iteration process,
	// is composed by all the whole input lllls, each associated to an empty address. 
	// If a return value of 1 is not subsequently received, no actual iteration takes place. <br/>
	// Whenever a sublist that was entered ends,
	// a negative integer is output from the rightmost inlet (according to the number of consecutive closed parentheses),
	// after which the iteration of the parent llll is resumed where it was left when the sublist was entered.
	// If the input lllls don't have all the same structure, 
	// the details of <o>bach.iter</o>'s behavior are defined by the <m>iterationmode</m>, <m>scalarmode</m> and <m>recursionmode</m> attributes.
	class_addmethod(c, (method)iter_anything,	"anything",		A_GIMME,	0);
	
	// @method int @digest Lambda inlet
	// @description
	// An integer in the rightmost inlet is the return value for a proposal (see description of the <m>anything</m> message).
	class_addmethod(c, (method)iter_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)iter_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)iter_anything,	"list",			A_GIMME,	0);
	
	
	// @method bang @digest Function depends on inlet
	// @description
	// In first inlet: iterate upon the most recently received lllls. <br />
	// In rightmost inlet: stop the iteration.
	class_addmethod(c, (method)iter_bang,		"bang",			0);
	
	// @method stop @digest Stop the iteration
	// @description
	// In rightmost inlet: stop the iteration.
	class_addmethod(c, (method)iter_bang,       "stop",			0);

	class_addmethod(c, (method)iter_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)iter_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_iter, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	// @description
	// <m>maxdepth</m> sets the maximum depth level at which the iteration must be performed.
	// If negative, the depth level is counted from the innermost level of each branch of the tree.
	// A value of 0 is treated as a special case where only the whole input lllls are output, 
	// each associated to a <m>null</m> address, and no actual iteration takes place.
	// In this case, the symbol <b>root</b> is output from the rightmost outlet.
	// This can be useful in special situations where a series of iterations are triggered at different maximum depths,
	// in order to emulate recursive behaviors.
	// Defaults to -1, i.e. there is no limitation (stop at the innermost level).
	
	CLASS_ATTR_LONG(c, "scalarmode",	0,	t_iter, n_scalarmode);
	CLASS_ATTR_FILTER_CLIP(c, "scalarmode", 0, 1);
	CLASS_ATTR_LABEL(c, "scalarmode", 0, "Scalar Mode");
	CLASS_ATTR_STYLE(c, "scalarmode", 0, "onoff");
	// @description @copy BACH_DOC_SCALARMODE

	CLASS_ATTR_LONG(c, "recursionmode",	0,	t_iter, n_recursionmode);
	CLASS_ATTR_FILTER_CLIP(c, "recursionmode", 0, 1);
	CLASS_ATTR_LABEL(c, "recursionmode", 0, "Recursion Mode");
	CLASS_ATTR_STYLE(c, "recursionmode", 0, "onoff");
	// @description When set to 0 and a sublist and a plain element are met, both are output as they are.
	// When set to 1, the sublist is entered and iterated against the plain element, up to <m>maxdepth</m>.
	
	CLASS_ATTR_LONG(c, "iterationmode",	0,	t_iter, n_iterationmode);
	CLASS_ATTR_STYLE_LABEL(c, "iterationmode", 0, "enumindex", "Iteration Mode");
	CLASS_ATTR_FILTER_CLIP(c, "iterationmode", 0, 2);
	CLASS_ATTR_ENUMINDEX(c, "iterationmode", 0, "Shortest Longest Nulls");
	// @description @copy BACH_DOC_ITERATIONMODE
	
	CLASS_ATTR_LONG(c, "spikemode",	0,	t_iter, n_spikemode);
	CLASS_ATTR_FILTER_CLIP(c, "spikemode", 0, 2);
	CLASS_ATTR_STYLE_LABEL(c, "spikemode", 0, "enumindex", "Spike Mode");
	CLASS_ATTR_ENUMINDEX(c, "spikemode", 0, "Distinct Ignore Nulls");
	// @description
	// A spike in an llll is a sequence of parentheses at least two of which are opposite:
	// for instance, <b>[]</b> or <b>[[[]</b> or <b>]][][</b>.
	// The <m>spikemode</m> attribute controls <o>bach.iter</o>'s behavior when a spike is met.
	// When set to 0 (the default), a distinct integer for each sequence of same-direction parentheses 
	// is output from the rightmost outlet:
	// for instance, <b>[]</b> will cause the sequence <m>1</m>, <m>-1</m> to be output;
	// <b>[[[]</b> will cause <m>3</m>, <m>-1</m> to be output;
	// <b>]][][</b> will cause <m>-2</m>, <m>1</m>, <m>-1</m>, <m>1</m> to be output.
	// This setting is most useful in conjunction with <o>bach.collect</o>. <br />
	// When the <m>spikemode</m> attribute is set to 1, a single integer is output from the rightmost outlet for the whole spike.
	// The integer represents the depth difference between the last element before the spike and the first element after it.
	// The integers output for the previous examples would then be 0, 2, -1. <br />
	// When the <m>spikemode</m> attribute is set to 2, the values that are output are the same as for <m>spikemode 0</m>.
	// In addition, after each value a set of <b>null</b> addresses and data is output from the llll outlets.
	
	CLASS_ATTR_LONG(c, "unwrap",	0,	t_iter, n_unwrap);
	CLASS_ATTR_FILTER_CLIP(c, "unwrap", 0, 1);
	CLASS_ATTR_LABEL(c, "unwrap", 0, "Unwrap");
	CLASS_ATTR_STYLE(c, "unwrap", 0, "onoff");
	// @description 
	// When set to 1, every outgoing llll is flattened by its outermost level parentheses.
	
	CLASS_ATTR_LONG(c, "lambda",	0,	t_iter, n_lambda);
	CLASS_ATTR_FILTER_CLIP(c, "lambda", 0, 1);
	CLASS_ATTR_LABEL(c, "lambda", 0, "Lambda Mode");
	CLASS_ATTR_STYLE(c, "lambda", 0, "onoff");
	// @description 
	// When set to 1, all sublists as well as the whole input llll are output as proposals, along with their addresses,
	// and a return value is expected to tell whether the sublists (or the whole input llll) should be entered or not. 
	// Please refer to the description of the <m>anything</m> message for more details.
	

	class_register(CLASS_BOX, c);
	iter_class = c;
	
	dev_post("bach.iter compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void iter_bang(t_iter *x)
{	
	iter_anything(x, _sym_bang, 0, NULL);
}

void iter_int(t_iter *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	iter_anything(x, _sym_int, 1, &outatom);
}

void iter_float(t_iter *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	iter_anything(x, _sym_float, 1, &outatom);
}

void iter_anything(t_iter *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_lllls[LLLL_MAX_INLETS];
	long inlet = proxy_getinlet((t_object *) x);
	long count = x->n_lists;
	long i;
	
	if (inlet == x->n_lists) {
		if (msg == _llllobj_sym_stop || msg == _sym_bang) {
			x->n_stop = 1;
			return;
		} else if (msg == _llllobj_sym_bach_llll) {
			t_llll *in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
			if (in_ll && in_ll->l_size)
				x->n_enter = hatom_getlong(&in_ll->l_head->l_hatom);
			llll_free(in_ll);
			return;
		} else if (ac) {
			x->n_enter = atom_getlong(av);
			return;
		}
	} else if (inlet == 0) {
		if (msg != _sym_bang) {
			if ((in_lllls[0] = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0)) == NULL)
				return;
		} else
			in_lllls[0] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
		for (i = 1; i < count; i++) {
			in_lllls[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 0);
		}
				
		llll_iter(count, in_lllls, x->n_maxdepth, x->n_scalarmode, x->n_recursionmode, x->n_iterationmode, x->n_spikemode, x->n_unwrap, NULL, 
				  (iter_datafn) iter_shoot_llll, x, (iter_datafn) iter_shoot_llll, x, (iter_cmdfn) iter_shoot_cmd, x, 
				  (iter_rootfn) iter_shoot_root, x, x->n_lambda ? (iter_lambdafn) iter_lambda : NULL, x);
		for (i = 0; i < count; i++) {
			llll_release(in_lllls[i]);
		}
	} else
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
}

long iter_shoot_llll(t_iter *x, long list, t_llll *ll, char isaddress)
{
	x->n_stop = 0;
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, list * 2 + isaddress, ll);
	return x->n_stop;
}

long iter_shoot_cmd(t_iter *x, long cmd)
{
	x->n_stop = 0;
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1, cmd);
	return x->n_stop;
}

long iter_shoot_root(t_iter *x)
{
	x->n_stop = 0;
	llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1, gensym("root"), 0, NULL);
	return x->n_stop;
}

long iter_lambda(t_iter *x, t_llll *lambda_ll)
{
	x->n_enter = 0;
	llll_prependsym(lambda_ll, gensym("lambda"), 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1, lambda_ll);
	if (x->n_stop == 1)
		return -1;
	else
		return x->n_enter != 0;
}

void iter_assist(t_iter *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a < x->n_lists) // @in 0 @loop 1 @type llll @digest llll to be iterated
			sprintf(s, "llll %ld", a + 1);
		else				// @in 1 @type bang/stop/int @digest bang/stop to stop iteration, or lambda inlet
							// @description A <m>bang</m> or <m>stop</m> message stops the iteration.
							// An integer (1 or 0) received as the response to a proposal from the lambda outlet
							// causes the proposed sublists (or the whole lllls) to be entered and iterated through or not.
			sprintf(s, "bang/stop/int: Stop / Lambda Inlet");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == x->n_lists * 2)			
			sprintf(s, "int/llll (%s): Depth Delta / Lambda Outlet", type);	// @out 2 @type int/llll @digest Depth delta / Lambda outlet
			// @description The difference between the depth of the previous and current elements; 
			// this value can be fed into <o>bach.collect</o>'s rightmost inlet.
			// If the <m>lambda</m> attribute is set, proposals are output from the rightmost outlet whenever one or more sublists are met,
			// as well as the very beginning of the iteration, and a return value is expected in the rightmost inlet
			// telling whether the proposed sublists (or the whole lllls) should be entered or not.
			// Please refer to the description of the <m>anything</m> message for more details.
		else {
			switch (a % 2) {
				case 0: sprintf(s, "llll %ld (%s): Data", a / 2 + 1, type);		break;	// @out 0 @loop 1 @type llll @digest Current element
				case 1: sprintf(s, "llll %ld (%s): Address", a / 2 + 1, type);	break;	// @out 1 @loop 2 @type llll @digest Current element's address
					// @description @copy BACH_DOC_ADDRESS_BASIC

			}
		}
	}
}

void iter_inletinfo(t_iter *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void iter_free(t_iter *x)
{
	long i;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	bach_freeptr(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_iter *iter_new(t_symbol *s, short ac, t_atom *av)
{
	t_iter *x = NULL;
	long i, proxies = 0;
	long true_ac;
	t_max_err err = 0;
	char outlets[LLLL_MAX_OUTLETS];
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_iter *) object_alloc_debug(iter_class))) {
		// @arg 0 @name count @optional 1 @type int @digest Number of parallel lllls
		// @description The number of lllls to be iterated in parallel.
		// Inlets and outlets are created accordingly.
		
  		proxies = (true_ac && atom_gettype(av) == A_LONG) ? atom_getlong(av) : 1; // one for each list (plus one standard input for ctl inlet)
		if (proxies < 1) {
			object_warn((t_object *) x, "Invalid argument: setting to 1");
			proxies = 1;
		}
		x->n_lists = proxies;
		strncpy_zero(outlets, "444", LLLL_MAX_OUTLETS);
		for (i = 1; i < x->n_lists; i++) 
			strncat_zero(outlets, "44", LLLL_MAX_OUTLETS);
		
		x->n_maxdepth = -1;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, x->n_lists, outlets);
		x->n_proxies = MIN(proxies, LLLL_MAX_INLETS);
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
	} else 
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
