/**
 @file
 expr.c
 
 @name 
 bach.expr
 
 @realname 
 bach.expr
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Evaluate mathematical expressions
 
 @description
 Evaluates mathematical expressions upon lllls.
 
 @discussion
 The behavior of <o>bach.expr</o> is not unlike <o>vexpr</o>'s, but rationals and sublists are treated correctly.
 
 @category
 bach, bach objects, bach math
 
 @keywords
 expression, evaluate, variable, number, calculate, compute

 @seealso
 bach.+, bach.-, bach.*, bach./, bach.%, expr, vexpr 
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"
#include "ext_critical.h"
#include "collector.h"
#include "lexpr.h"


typedef struct _bach_expr
{
	t_llllobj_object 	n_ob;
	long				n_proxies;
	void				**n_proxy;
	long				n_in;
	long				n_maxvars;
	long				n_scalarmode;
	long				n_clone;
	t_lexpr				*n_lexpr;	
	t_llll				*n_dummy;
	t_llll				*n_empty;
	t_bach_atomic_lock	n_lock;
	
} t_bach_expr;


typedef struct _expr_iteration_data {
	t_lexpr		*e_lexpr;
	t_collector	*e_collector;
	long		e_count; // how many variables
	long		e_evaluate;
	t_hatom		e_data[LEXPR_MAX_VARS]; // data for one iteration of the incoming lllls
} t_expr_iteration_data;

void bach_expr_assist(t_bach_expr *x, void *b, long m, long a, char *s);
void bach_expr_inletinfo(t_bach_expr *x, void *b, long a, char *t);

t_bach_expr *bach_expr_new(t_symbol *s, short ac, t_atom *av);
void bach_expr_free(t_bach_expr *x);

void bach_expr_bang(t_bach_expr *x);
void bach_expr_int(t_bach_expr *x, t_atom_long v);
void bach_expr_float(t_bach_expr *x, double v);
void bach_expr_anything(t_bach_expr *x, t_symbol *msg, long ac, t_atom *av);

long bach_expr_get_data(t_expr_iteration_data *x, long list, t_llll *ll, char isaddress);
long bach_expr_cmd(t_expr_iteration_data *x, long cmd);

t_class *bach_expr_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.expr", (method)bach_expr_new, (method)bach_expr_free, (short)sizeof(t_bach_expr), 0L, A_GIMME, 0);
	
	// @method llll @digest Store values to the expression variables
	// @description
	// The lllls are iterated against each other (as in <o>bach.iter</o> with <m>recursionmode 1</m>),
	// the values they contain are assigned to the variables according to the inlet each llll is received in and the llll is evaluated.
	// In general, lllls should only be composed of numbers and sublists, but comparison operators also work upon symbols.
	// An llll received in the leftmost inlet will trigger the evaluation and cause the result to be output.
	class_addmethod(c, (method)bach_expr_anything,	"anything",		A_GIMME,	0);
	
	// @method expr @digest Expression to evaluate
	// @description
	// The <m>expr</m> message, followed by a mathematical expression, will set the new expression to be evaluated by <o>bach.expr</o>.
	// For more details on the expression syntax, please refer to the <b>arguments</b> section.
	class_addmethod(c, (method)bach_expr_anything,	"expr",			A_GIMME,	0);

	class_addmethod(c, (method)bach_expr_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)bach_expr_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)bach_expr_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the last operation
	// @description Return the result of the evaluation of the most recently received lllls and expression.
	class_addmethod(c, (method)bach_expr_bang,		"bang",			0);
	
	class_addmethod(c, (method)bach_expr_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)bach_expr_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
	

	CLASS_ATTR_LONG(c, "scalarmode",	0,	t_bach_expr, n_scalarmode);
	CLASS_ATTR_FILTER_CLIP(c, "scalarmode", 0, 1);
	CLASS_ATTR_STYLE(c, "scalarmode", 0, "onoff");
	CLASS_ATTR_LABEL(c, "scalarmode", 0, "Scalar Mode");
	CLASS_ATTR_BASIC(c, "scalarmode", 0);
	// @description @copy BACH_DOC_SCALARMODE
	
	CLASS_ATTR_LONG(c, "clone", 0, t_bach_expr, n_clone);
	CLASS_ATTR_FILTER_CLIP(c, "clone", 0, 1);
	CLASS_ATTR_STYLE_LABEL(c, "clone", 0, "onoff", "Clone");
	
	/*
	CLASS_ATTR_LONG(c, "maxvars",	0,	t_bach_expr, n_maxvars);
	CLASS_ATTR_FILTER_CLIP(c, "maxvars", 0, LEXPR_MAX_VARS);
	CLASS_ATTR_LABEL(c, "maxvars", 0, "Maximum Variables");
	CLASS_ATTR_FILTER_CLIP(c, "maxvars", 1, 255);
	*/
	// @description Explicitly set the number of inlets. <br />
	// @copy BACH_DOC_STATIC_ATTR
	
	class_register(CLASS_BOX, c);
	bach_expr_class = c;
	
	dev_post("bach.expr compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void bach_expr_bang(t_bach_expr *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		bach_expr_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void bach_expr_int(t_bach_expr *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	bach_expr_anything(x, _sym_int, 1, &outatom);
}

void bach_expr_float(t_bach_expr *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	bach_expr_anything(x, _sym_float, 1, &outatom);
}

void bach_expr_anything(t_bach_expr *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	long i;
	
	if (msg == gensym("expr")) {
		t_lexpr *old_lexpr, *new_lexpr;
		if (ac)
			new_lexpr = lexpr_new(ac, av, 0, NULL, (t_object *) x);
		else
			new_lexpr = NULL;		
		x->n_ob.l_rebuild = 1;

		if (!new_lexpr) {
			object_error((t_object *) x, "Bad expression");
			return;
		}
		bach_atomic_lock(&x->n_lock);
		old_lexpr = x->n_lexpr;
		x->n_lexpr = new_lexpr;
		if (new_lexpr->l_numvars != 0) {
			t_llll *stored_llll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0);
			if (stored_llll == x->n_dummy)
				llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_empty, 0);
			llll_release(stored_llll);
		}
		bach_atomic_unlock(&x->n_lock);
		lexpr_free(old_lexpr);
	} else {
		t_lexpr *lexpr;
		if (msg != _sym_bang) 
			x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet) ? 1 : 0;
		
		if (inlet == 0 && x->n_ob.l_rebuild) {
			
			t_expr_iteration_data data, *data_ptr = &data;
			t_llll *lists[LEXPR_MAX_VARS], *result;
			bach_atomic_lock(&x->n_lock);
			if (!(lexpr = x->n_lexpr)) {
				bach_atomic_unlock(&x->n_lock);
				return;
			}
			lexpr_retain(lexpr);
			bach_atomic_unlock(&x->n_lock);
			// if it is a constant expression and the stored llll is empty then store a dummy llll and evaluate it
			// this will retrieve the value of the expression, to be output when a bang is received
			if (lexpr->l_numvars == 0) {
				t_llll *stored_llll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0);
				if (stored_llll->l_size == 0)
					llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_dummy, 0);
				llll_release(stored_llll);
				data.e_count = 1;
			} else
				data.e_count = lexpr->l_numvars;
			
			data.e_collector = collector_new(1, 0);
			data.e_lexpr = lexpr;
			data.e_evaluate = 0;
			
			for (i = 0; i < data.e_count; i++) {
				lists[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, x->n_clone);
			}

			llll_iter(data.e_count, lists, -1,
                      x->n_scalarmode,
                      LLLL_M_RECURSION_UNROLL,
                      LLLL_M_ITERATION_STOP,
                      LLLL_M_SPIKE_VERBOSE,
                      0, NULL,
					  (iter_datafn) bach_expr_get_data, data_ptr, NULL, NULL, (iter_cmdfn) bach_expr_cmd, data_ptr, NULL, NULL, NULL, NULL);

			bach_expr_cmd(data_ptr, 0);
			lexpr_release(lexpr);
			result = collector_output(data.e_collector, 0, 0);
			collector_clear(data.e_collector);   
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, result, 0);
			x->n_ob.l_rebuild = 0;
			for (i = 0; i < data.e_count; i++) {
				llll_release(lists[i]);

			}
			collector_free(data.e_collector);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
			}
	}
}


long bach_expr_get_data(t_expr_iteration_data *x, long list, t_llll *ll, char isaddress) // never called for address
{
	if (ll->l_size)
		x->e_data[list] = ll->l_head->l_hatom; // that is, for each list get the hatom coming from iter and remember it
	else
		x->e_evaluate = 0; // or, if no hatom is coming, tell the guy not to evaluate
	return 0;
}

long bach_expr_cmd(t_expr_iteration_data *x, long cmd)
{
	t_hatom *result_hatom, *this_lexpr_data, *max_lexpr_data;
	t_llll *result_llll;
	
	if (x->e_evaluate) { // this is not true at the first call, or if no atom has been passed for at least one list
		result_hatom = lexpr_eval(x->e_lexpr, x->e_data);
		if (result_hatom) {
            short result_type = hatom_gettype(result_hatom);
			if (hatom_type_is_number(result_type) || result_type == H_SYM) {
				result_llll = llll_get();
				llll_appendhatom(result_llll, result_hatom, 0, WHITENULL_llll);
				collector_get(x->e_collector, result_llll, 0, 0);
			}
			bach_freeptr(result_hatom);
		} else { // if there was an empty llll in the incoming data
			collector_get(x->e_collector, llll_get(), 0, 0);
		}

	}
	for (this_lexpr_data = x->e_data, max_lexpr_data = this_lexpr_data + x->e_count; this_lexpr_data < max_lexpr_data; this_lexpr_data++)
		this_lexpr_data->h_type = A_NOTHING;
	if (cmd)
		collector_change_level(x->e_collector, cmd);
	x->e_evaluate = 1;
	return 0;
}

void bach_expr_assist(t_bach_expr *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll %ld", a + 1); // @in 0 @loop 1 @type llll/expr @digest llll with values or new expression
		// @description The values contained in the llll will be assigned to the variables during evaluation; 
		// in alternative, it is possible to set a new expression with the <m>expr</m> message.
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Result", type); // @out 0 @type llll @digest Result of the evaluation
	}
}

void bach_expr_inletinfo(t_bach_expr *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void bach_expr_free(t_bach_expr *x)
{
	long i;
	t_llll *stored = x->n_ob.l_incache[0].s_ll;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	bach_freeptr(x->n_proxy);
	lexpr_free(x->n_lexpr);
	llll_release(x->n_dummy);
	llll_release(x->n_empty);
	if (stored != x->n_dummy)
		llll_free(x->n_dummy); // otherwise it will be released by llllobj_obj_free
	if (stored != x->n_empty)
		llll_free(x->n_empty); // otherwise it will be released by llllobj_obj_free
	llllobj_obj_free((t_llllobj_object *) x);
}

t_bach_expr *bach_expr_new(t_symbol *s, short ac, t_atom *av)
{
	t_bach_expr *x = NULL;
	long i;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_bach_expr *) object_alloc_debug(bach_expr_class))) {
		// @arg 0 @name expression @optional 1 @type anything @digest Expression to evaluate
		// @description The expression can contain variables, in the form <m>$in</m>, <m>$rn</m>, <m>$fn</m>, <m>$xn</m>, where <m>n</m> stands for an inlet number.
		// <m>$in</m> will refer to an integer value extracted from the llll received in the n-th inlet; 
		// likewise, <m>$rn</m> will refer to a rational or integer value and <m>$fn</m> to a floating-point value.
		// <m>$xn</m> will refer to an untyped value, meaning that the type of the value extracted from the llll will be taken as-is, including symbols (see the description of the <m>llll</m> method).
		// Unless specific needs, <m>$xn</m> should be considered the preferred way to express variables.
		// For a complete list of the mathematical operators and functions supported by <o>bach.expr</o>, please refer to the help file.
		
		if (true_ac) {
			x->n_lexpr = lexpr_new(true_ac, av, 0, NULL, (t_object *) x);
			if (x->n_lexpr) {
//				object_post((t_object *) x, "good expr!");
				x->n_maxvars = x->n_lexpr->l_numvars;
				if (x->n_lexpr->l_numvars == 0)
					x->n_ob.l_rebuild = 1;
			} else {
				object_error((t_object *) x, "Bad expression");
//				post("true_ac = %ld, av = %p", true_ac, av);
			}
		}
		
		i = true_ac;
		while (i < ac - 1) {
			t_symbol *symattr = atom_getsym(av + i);
			if (!symattr || *symattr->s_name != '@') {
				object_error((t_object *) x, "Bad argument at position %ld", i);
				i++;
				break;
			}
			const char *attrname = symattr->s_name + 1;
			i++;
			if (!strcmp(attrname, "maxvars")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_maxvars = CLAMP(val, 0, LLLL_MAX_INLETS);
					i++;
				} else
					object_error((t_object *) x, "Bad value for ins attribute");
			} else if (!strcmp(attrname, "scalarmode")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_scalarmode = CLAMP(val, 0, 1);
					i++;
				} else
					object_error((t_object *) x, "Bad value for scalarmode attribute");
			} else if (!strcmp(attrname, "out")) {
				llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, av + i);
				i++;
			} else
				object_error((t_object *) x, "Unknown attribute %s", attrname);
		}
		if (x->n_maxvars < 1)
			x->n_maxvars = 1;
		llllobj_obj_setup((t_llllobj_object *) x, x->n_maxvars, "4");
		
		x->n_proxies = CLAMP(x->n_maxvars - 1, 0, LLLL_MAX_INLETS);
		
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
			
		x->n_dummy = llll_get();
		llll_appendobj(x->n_dummy, NULL, 0, WHITENULL_llll);
		llll_retain(x->n_dummy);
		x->n_empty = llll_get();
		llll_retain(x->n_empty);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}