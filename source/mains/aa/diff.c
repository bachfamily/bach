/**
 @file
 diff.c
 
 @name 
 bach.diff
 
 @realname 
 bach.diff
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Difference of two sets
 
 @description
 Returns the difference of two lllls.

 @discussion
 If either or both lllls contain repeated elements, the behavior is undefined.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 set, difference

 @seealso
 bach.union, bach.intersection, bach.symdiff
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _diff
{
	t_llllobj_object 	n_ob;
	void				*n_proxy[3];
	long				n_in;
	long				n_result;
	long				n_haslambda;
	t_llll				*n_empty;
} t_diff;

void diff_assist(t_diff *x, void *b, long m, long a, char *s);
void diff_inletinfo(t_diff *x, void *b, long a, char *t);

t_diff *diff_new(t_symbol *s, short ac, t_atom *av);
void diff_free(t_diff *x);

void diff_bang(t_diff *x);
void diff_int(t_diff *x, t_atom_long v);
void diff_float(t_diff *x, double v);
void diff_anything(t_diff *x, t_symbol *msg, long ac, t_atom *av);

long diff_func(t_diff *x, t_llllelem *what1, t_llllelem *what2);

t_class *diff_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.diff", (method)diff_new, (method)diff_free, (short)sizeof(t_diff), 0L, A_GIMME, 0);
	
	// @method llll @digest Store data and compute difference
	// @description
	// In first inlet: the llll in the right inlet is subtracted from the llll and the result is output.<br />
	// In second inlet: the llll is stored, to be subtracted from an llll received in the left inlet.
	// In third inlet: the llll is converted into an int

	class_addmethod(c, (method)diff_anything,	"anything",		A_GIMME,	0);
	
	// @method int @digest Lambda inlet
	// @description Third inlet is a lambda inlet. <br /> 
	// @copy BACH_DOC_LAMBDA_INLET_EQUALITY
	class_addmethod(c, (method)diff_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)diff_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)diff_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the last operation
	// @description Returns the difference of the most recently received lllls.  <br />
	// @copy BACH_DOC_BANG_LAMBDA_CAVEAT
	class_addmethod(c, (method)diff_bang,		"bang",			0);
	
	class_addmethod(c, (method)diff_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)diff_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	
	class_register(CLASS_BOX, c);
	diff_class = c;
	
	dev_post("bach.diff compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void diff_bang(t_diff *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		diff_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void diff_int(t_diff *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	diff_anything(x, _sym_int, 1, &outatom);
}

void diff_float(t_diff *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	diff_anything(x, _sym_float, 1, &outatom);
}

#ifdef ___destructive
void diff_anything(t_diff *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inll1, *inll2;
	long inlet = proxy_getinlet((t_object *) x);
	x->n_result = 0;
	
	switch (inlet) {
		case 0:
            if (msg != _sym_bang) {
                inll1 = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
                if (!inll1)
                    return;
            } else
                inll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
            inll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
            x->n_haslambda = 0;
            if (inll1->l_size && inll2->l_size)
                llllobj_test_lambda_loop_two_outs((t_object *) x, LLLL_OBJ_VANILLA, inll1->l_head, inll2->l_head, 1, 2);		
            
            if (x->n_haslambda) {
                llll_diff(inll1, inll2, (sets_fn) diff_func, x);
            } else
                llll_diff(inll1, inll2);
            llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, inll1, 0);
            x->n_ob.l_rebuild = 0;
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);

			break;
		case 1:
			x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet) != NULL;
			break;
		case 2:
			if (msg == LLLL_NATIVE_MSG) {
				t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
				if (lambda_llll) {
					if (lambda_llll->l_size)
						x->n_result = hatom_getlong(&lambda_llll->l_head->l_hatom);
					else
						x->n_result = 0;
					llll_free(lambda_llll);
				} else
					x->n_result = 0;
			} else
				x->n_result = ac ? atom_getlong(av) : 0;
			x->n_haslambda = 1;
			break;
	}
}
#else
void diff_anything(t_diff *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inll1, *inll2, *outll;
	long inlet = proxy_getinlet((t_object *) x);
	x->n_result = 0;
	
	switch (inlet) {
		case 0:
			if (msg != _sym_bang) {
				inll1 = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
				if (!inll1)
					return;
			} else
				inll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
			inll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
			x->n_haslambda = 0;
			if (inll1->l_size && inll2->l_size)
				llllobj_test_lambda_loop_two_outs((t_object *) x, LLLL_OBJ_VANILLA, inll1->l_head, inll2->l_head, 1, 2);
			
			if (x->n_haslambda) {
				outll = llll_diff(inll1, inll2, (sets_fn) diff_func, x);
			} else
				outll = llll_diff_simple(inll1, inll2);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, outll, 0);
			x->n_ob.l_rebuild = 0;
			diff_bang(x);
			break;
		case 1:
			x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet) != NULL;
			break;
		case 2:
			if (msg == LLLL_NATIVE_MSG) {
				t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
				if (lambda_llll) {
					if (lambda_llll->l_size)
						x->n_result = hatom_getlong(&lambda_llll->l_head->l_hatom);
					else
						x->n_result = 0;
					llll_free(lambda_llll);
				} else
					x->n_result = 0;
			} else
				x->n_result = ac ? atom_getlong(av) : 0;
			x->n_haslambda = 1;
			break;
	}
}
#endif


long diff_func(t_diff *x, t_llllelem *what1, t_llllelem *what2)
{
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, what2->l_thing.w_llll);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, what1->l_thing.w_llll);
	return x->n_result;
}

void diff_assist(t_diff *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:	sprintf(s, "llll 1");	break; // @in 0 @type llll @digest llll to subtract from
			case 1: sprintf(s, "llll 2");	break; // @in 1 @type llll @digest llll to be subtracted
			case 2: sprintf(s, "llll: Lambda Input");	break; // @in 2 @type int/llll @digest Lambda inlet 
				// @description @copy BACH_DOC_LAMBDA_INLET_EQUALITY
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0:	sprintf(s, "llll (%s): Difference", type);		break; // @out 0 @type llll @digest Difference
			case 1:	sprintf(s, "llll (%s): Lambda Outlet 1", type);	break; // @out 1 @type llll @digest First lambda outlet 
				// @description @copy BACH_DOC_LAMBDA_OUTLET_EQUALITY
			case 2:	sprintf(s, "llll (%s): Lambda Outlet 2", type);	break; // @out 2 @type llll @digest Second lambda outlet 
				// @description @copy BACH_DOC_LAMBDA_OUTLET_EQUALITY
		}
	}
}

void diff_inletinfo(t_diff *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void diff_free(t_diff *x)
{
	long i;
	for (i = 2; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llll_free(x->n_empty);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_diff *diff_new(t_symbol *s, short ac, t_atom *av)
{
	t_diff *x = NULL;
	long i;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_diff *) object_alloc_debug(diff_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "444");
		for (i = 2; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		x->n_empty = llll_get();
	} else
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}