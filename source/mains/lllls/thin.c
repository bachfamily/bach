/*
 *  thin.c
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
 thin.c
 
 @name 
 bach.thin
 
 @realname 
 bach.thin
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Remove duplicate elements
 
 @description
 Removes duplicate elements from an llll.
 
 @discussion
 A custom equality test can be provided through the lambda loop. <br />
 @copy BACH_DOC_LAMBDA
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 delete, remove, duplicates, thin, lambda loop

 @seealso
 bach.intersection, bach.diff, bach.symdiff, bach.union, bach.classify
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _thin
{
	t_llllobj_object 	n_ob;
	void				*n_proxy;
	long				n_in;
	long				n_matchtype;
	long				n_result;
	long				n_haslambda;
	t_symbol			*n_op;
	llll_cmp_fn			n_deffunc;
} t_thin;

void thin_assist(t_thin *x, void *b, long m, long a, char *s);
void thin_inletinfo(t_thin *x, void *b, long a, char *t);

t_thin *thin_new(t_symbol *s, short ac, t_atom *av);
void thin_free(t_thin *x);

void thin_bang(t_thin *x);
void thin_int(t_thin *x, t_atom_long v);
void thin_float(t_thin *x, double v);
void thin_anything(t_thin *x, t_symbol *msg, long ac, t_atom *av);

long thin_func(t_thin *x, t_llllelem *a, t_llllelem *b);

t_class *thin_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.thin", (method)thin_new, (method)thin_free, (short)sizeof(t_thin), 0L, A_GIMME, 0);

	// @method llll @digest Remove duplicate elements
	// @description
	// In first inlet: Duplicate elements are removed from the llll, and the resulting llll is output.
	// If a lambda loop is present, couples of elements are output from the 2nd and 3rd outlets.
	// If the two elements should considered equal (and as a consequence one of the two should be removed from the llll)
	// the equality test should return 1 to <o>bach.thin</o>'s second inlet; otherwise, it should return 0.
	// If a lambda loop is not present, the elements are tested for "standard" equality (as in <o>bach.eq</o>),
	// according to the <m>matchtype</m> attribute.
	class_addmethod(c, (method)thin_anything,	"anything",		A_GIMME,	0);
	class_addmethod(c, (method)thin_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)thin_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)thin_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description A bang in the first inlet causes the result of removing the duplicates from the most recently received llll to be output. <br />
	// @copy BACH_DOC_BANG_LAMBDA_CAVEAT
	class_addmethod(c, (method)thin_bang,		"bang",			0);
	
	class_addmethod(c, (method)thin_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)thin_inletinfo,	"inletinfo",	A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "matchtype",	0,	t_thin,	n_matchtype);
	CLASS_ATTR_LABEL(c, "matchtype", 0, "Match Type");
	CLASS_ATTR_FILTER_CLIP(c, "matchtype", 0, 1);
	CLASS_ATTR_STYLE(c, "matchtype", 0, "onoff");
	CLASS_ATTR_BASIC(c, "matchtype", 0);
	// @description
	// When set to 0, numbers with different types but equal value (i.e. 1.5 and 3/2) are considered as equal. 
	// When set to 1, they are considered different.
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	
	class_register(CLASS_BOX, c);
	thin_class = c;
	
	dev_post("bach.thin compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void thin_bang(t_thin *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		thin_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void thin_int(t_thin *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	thin_anything(x, _sym_int, 1, &outatom);
}

void thin_float(t_thin *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	thin_anything(x, _sym_float, 1, &outatom);
}

void thin_anything(t_thin *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll;
	
	long inlet = proxy_getinlet((t_object *) x);
	x->n_result = 0;
	
	switch (inlet) {
		case 0:
            if (msg != _sym_bang) {
                ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
                if (!ll)
                    return;
            } else
                ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
            if (ll->l_size >= 2) {
                x->n_haslambda = 0;
                llllobj_test_lambda_loop_two_outs((t_object *) x, LLLL_OBJ_VANILLA, ll->l_head, ll->l_head->l_next, 1, 2);
                if (x->n_haslambda) {
                    llll_put_elems_in_lllls_in_lthing(ll);
                    ll = llll_thin(ll, (sort_fn) thin_func, x);
                    llll_remove_lllls_from_lthing(ll);
                }
                else 
                    ll = llll_thin_simple(ll, x->n_matchtype);
            }
            x->n_ob.l_rebuild = 0;
            llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
			break;
		case 1:
			if (ac) {
				if (msg == LLLL_NATIVE_MSG) {
					t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
					if (lambda_llll) {
						if (lambda_llll->l_size)
							x->n_result = hatom_getlong(&lambda_llll->l_head->l_hatom);
						llll_release(lambda_llll);
					}
				} else
					x->n_result = atom_getlong(av);
				x->n_haslambda = 1;
			}
			break;
	}
}

long thin_func(t_thin *x, t_llllelem *a, t_llllelem *b)
{
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, b->l_thing.w_llll);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, a->l_thing.w_llll);
	return x->n_result;
}

void thin_assist(t_thin *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:	sprintf(s, "llll to Thin");			break; // @in 0 @type llll @digest llll to remove duplicates from
			case 1:	sprintf(s, "llll: Lambda Inlet");	break; // @in 1 @type int @digest Lambda Inlet
				// @description Result of the equality test: 1 if equal, 0 if not.
				
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0: sprintf(s, "Thinned llll (%s)", type);			break; // @out 0 @type llll @digest llll with duplicates removed
			case 1:	sprintf(s, "llll (%s): lambda outlet 1", type);	break; // @out 1 @type llll @digest Lambda Outlet 1
			case 2:	sprintf(s, "llll (%s): lambda outlet 2", type);	break; // @out 2 @type llll @digest Lambda Outlet 2
		}
	}
}

void thin_inletinfo(t_thin *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void thin_free(t_thin *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_thin *thin_new(t_symbol *s, short ac, t_atom *av)
{
	t_thin *x = NULL;
	t_max_err err = MAX_ERR_NONE;

	if ((x = (t_thin *) object_alloc_debug(thin_class))) {
		x->n_deffunc = llll_eq_ignoretype;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "444");
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
