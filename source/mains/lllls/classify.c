/*
 *  classify.c
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
 classify.c
 
 @name 
 bach.classify
 
 @realname 
 bach.classify
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Arrange elements into classes
 
 @description
 Arranges elements into classes, according to a custom equality test.
 
 @discussion
 A custom equality test can be provided through the lambda loop. <br />
 @copy BACH_DOC_LAMBDA
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 arrange, collect, duplicates, classify, lambda loop

 @seealso
 bach.thin, bach.collect
 
 @owner
 Andrea Agostini
 */

#include "bell/bach_codableobj.hpp"
#include "bell/ast.hpp"

typedef struct _classify
{
	t_codableobj 	n_ob;
	void			*n_proxy;
	long			n_in;
	long			n_matchtype;
	long			n_result;
	long			n_haslambda;
	t_symbol		*n_op;
} t_classify;

typedef struct _lambdaData
{
    t_classify *x;
    t_execEnv *context;
} t_lambdaData;

void classify_assist(t_classify *x, void *b, long m, long a, char *s);
void classify_inletinfo(t_classify *x, void *b, long a, char *t);

t_classify *classify_new(t_symbol *s, short ac, t_atom *av);
void classify_free(t_classify *x);

void classify_bang(t_classify *x);
void classify_int(t_classify *x, t_atom_long v);
void classify_float(t_classify *x, double v);
void classify_anything(t_classify *x, t_symbol *msg, long ac, t_atom *av);

long classify_func(t_classify *x, t_llllelem *a, t_llllelem *b);

long classify_code(t_lambdaData *data, t_llllelem *what1, t_llllelem *what2);

t_class *classify_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.classify", (method)classify_new, (method)classify_free, (short)sizeof(t_classify), 0L, A_GIMME, 0);

    codableclass_add_standard_methods_and_attrs(c);
    codableclass_add_extended_methods_and_attrs(c);

	// @method llll @digest Group equal elements
	// @description
	// In first inlet: Equal elements are grouped from the llll, and the resulting llll is output, having one more parenthesis
    // level than the original one (corresponding to each group of equal elements, i.e. to each class).
	// If a lambda loop is present, couples of elements are output from the 2nd and 3rd outlets.
	// If the two elements should considered equal (and as a consequence one of the two should be removed from the llll)
	// the equality test should return 1 to <o>bach.classify</o>'s second inlet; otherwise, it should return 0.
	// If a lambda loop is not present, the elements are tested for "standard" equality (as in <o>bach.eq</o>),
	// according to the <m>matchtype</m> attribute.
	class_addmethod(c, (method)classify_anything,	"anything",		A_GIMME,	0);
	class_addmethod(c, (method)classify_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)classify_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)classify_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description A bang in the first inlet causes the result of classification of the most recently received llll to be output. <br />
	// @copy BACH_DOC_BANG_LAMBDA_CAVEAT
	class_addmethod(c, (method)classify_bang,		"bang",			0);
	
	class_addmethod(c, (method)classify_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)classify_inletinfo,	"inletinfo",	A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "matchtype",	0,	t_classify,	n_matchtype);
	CLASS_ATTR_LABEL(c, "matchtype", 0, "Match Type");
	CLASS_ATTR_FILTER_CLIP(c, "matchtype", 0, 1);
	CLASS_ATTR_STYLE(c, "matchtype", 0, "onoff");
	CLASS_ATTR_BASIC(c, "matchtype", 0);
	// @description
	// When set to 0, numbers with different types but equal value (i.e. 1.5 and 3/2) are considered as equal. 
	// When set to 1, they are considered different.
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	class_register(CLASS_BOX, c);
	classify_class = c;
	
	dev_post("bach.classify compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void classify_bang(t_classify *x)
{	
	if (x->n_ob.c_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		classify_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void classify_int(t_classify *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	classify_anything(x, _sym_int, 1, &outatom);
}

void classify_float(t_classify *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	classify_anything(x, _sym_float, 1, &outatom);
}

void classify_anything(t_classify *x, t_symbol *msg, long ac, t_atom *av)
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
                if (x->n_ob.c_main) {
                    t_execEnv lambdaContext((t_llllobj_object *) x, x->n_ob.c_main);
                    lambdaContext.argc = 2;
                    t_lambdaData lambdaData = {
                        x,
                        &lambdaContext
                    };
                    llll_put_elems_in_lllls_in_lthing(ll);
                    ll = llll_classify(ll, (sort_fn) classify_code, &lambdaData);
                    llll_remove_lllls_from_lthing(ll);
                } else {
                    x->n_haslambda = 0;
                    llllobj_test_lambda_loop_two_outs((t_object *) x, LLLL_OBJ_VANILLA, ll->l_head, ll->l_head->l_next, 1, 2);
                    if (x->n_haslambda) {
                        llll_put_elems_in_lllls_in_lthing(ll);
                        ll = llll_classify(ll, (sort_fn) classify_func, x);
                        llll_remove_lllls_from_lthing(ll);
                    }
                    else
                        ll = llll_classify_simple(ll, x->n_matchtype);
                }
            }
            x->n_ob.c_ob.l_rebuild = 0;
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

long classify_func(t_classify *x, t_llllelem *a, t_llllelem *b)
{
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, b->l_thing.w_llll);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, a->l_thing.w_llll);
	return x->n_result;
}

long classify_code(t_lambdaData *data, t_llllelem *what1, t_llllelem *what2)
{
    t_execEnv *context = data->context;
    context->argv[1] = what1->l_thing.w_llll;
    context->argv[2] = what2->l_thing.w_llll;
    context->resetLocalVariables();
    t_llll *resll = codableobj_run((t_codableobj *) data->x, *context);
    long r = llll_istrue(resll);
    llll_free(resll);
    return r;
}

void classify_assist(t_classify *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:	sprintf(s, "llll to classify");			break; // @in 0 @type llll @digest llll to be classified
			case 1:	sprintf(s, "llll: Lambda Inlet");	break; // @in 1 @type int @digest Lambda Inlet
				// @description Result of the equality test: 1 if equal, 0 if not.
				
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0: sprintf(s, "Classified llll (%s)", type);			break; // @out 0 @type llll @digest llll with grouped equal elements
			case 1:	sprintf(s, "llll (%s): Lambda outlet 1", type);	break; // @out 1 @type llll @digest Lambda Outlet 1
			case 2:	sprintf(s, "llll (%s): Lambda outlet 2", type);	break; // @out 2 @type llll @digest Lambda Outlet 2
		}
	}
}

void classify_inletinfo(t_classify *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void classify_free(t_classify *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_classify *classify_new(t_symbol *s, short ac, t_atom *av)
{
	t_classify *x = NULL;
	t_max_err err = MAX_ERR_NONE;

	if ((x = (t_classify *) object_alloc_debug(classify_class))) {
        if (codableobj_setup((t_codableobj *) x, ac, av) < 0) {
            object_free_debug(x);
            return nullptr;
        }
		llllobj_obj_setup((t_llllobj_object *) x, 1, "444");
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
        t_dictionary* d = (t_dictionary *)gensym("#D")->s_thing;
        codableobj_getCodeFromDictionaryAndBuild((t_codableobj *) x, d);
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
