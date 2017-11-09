/**
 @file
 find.c
 
 @name 
 bach.find
 
 @realname 
 bach.find
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Find elements
 
 @description
 Searches an llll for elements or sequences of elements satisfying a condition.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 find, detect, search, element, sequence, condition, address, lambda loop

 @seealso
 bach.filter, bach.keys, bach.sieve, bach.constraints, bach.swap, bach.locate
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _find
{
	struct llllobj_object 	n_ob;
	
	void	*n_proxy[3];
	long	n_in;
	
	long	n_mindepth;
	long	n_maxdepth;
	long	n_minidx;
	long	n_maxidx;
	long	n_size;
	long	n_idxreject;
	long	n_depthreject;
	long	n_maxcount;	
	long	n_recursive;
	long	n_unwrap;
	long	n_depthpolicy;
	long	n_result;	
	long	n_haslambda;
	t_symbol	*n_op;
	llll_cmp_fn	n_deffunc;
} t_find;

void find_assist(t_find *x, void *b, long m, long a, char *s);
void find_inletinfo(t_find *x, void *b, long a, char *t);

t_find *find_new(t_symbol *s, short ac, t_atom *av);
void find_free(t_find *x);

void find_bang(t_find *x);
void find_int(t_find *x, t_atom_long v);
void find_float(t_find *x, double v);
void find_anything(t_find *x, t_symbol *msg, long ac, t_atom *av);

long find_func_with_lambda(t_find *x, t_llll *what);
long find_func_no_lambda(t_find *x, t_llll *what);

t_max_err find_op_set(t_find *x, t_object *attr, long argc, t_atom *argv);

DEFINE_STANDARD_MAXDEPTH_SETTER(t_find)
DEFINE_STANDARD_MINDEPTH_SETTER(t_find)

t_class *find_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.find", (method)find_new, (method)find_free, (short)sizeof(t_find), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description
	// In first inlet: llll to search. 
	// The matching parts of the llll (single elements or sequences of elements according to the search criteria) 
	// will be output as sublists of the first outlet llll;
	// their addresses will be output as sublists of the second outlet llll. <br />
	// @copy BACH_DOC_ADDRESS_BASIC
	// In second inlet: element or sequence of elements to search for.
	// If a lambda loop is not present, the search is performed
	// by comparing chunks of the llll in the first inlet to the llll in the second inlet, 
	// the size of the chunks being the same as the size of the second inlet llll.
	// If a lambda loop is present the llll received in the second inlet is ignored,
	// the chunks (whose size is determined by the <m>size</m> attribute) are output from the lambda outlet
	// and a comparison result is expected in the lambda inlet.
	// In third inlet: converted to int.
	class_addmethod(c, (method)find_anything,	"anything",		A_GIMME,	0);
	
	// @method int @digest Lambda inlet
	// @description
	// The criterium by which a given element or sequence of elements is considered a match
	// can be customized through an optional lambda loop.
	// If the lambda loop is present, the <m>op</m> attribute and the llll received in the second inlet are ignored,
	// and elements or sequences of elements (see the <m>size</m> attribute for more details) are output from the lambda outlet.
	// The lambda loop should return 1 to the third inlet if the element or sequence is a match, 0 if it is not.
	class_addmethod(c, (method)find_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)find_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)find_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description A <m>bang</m> in the first inlet outputs the result of the search on the most recently received llll
	// and with the current search criteria. <br />
	// @copy BACH_DOC_BANG_LAMBDA_CAVEAT
	class_addmethod(c, (method)find_bang,		"bang",			0);
	
	class_addmethod(c, (method)find_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)find_inletinfo,	"inletinfo",	A_CANT,		0);

	CLASS_ATTR_LONG(c, "mindepth",		0,	t_find, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");	
	CLASS_ATTR_BASIC(c, "mindepth", 0);
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_find);
	// @description @copy BACH_DOC_FIND_MINDEPTH

	CLASS_ATTR_LONG(c, "maxdepth",		0,	t_find, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, t_find);
	// @description @copy BACH_DOC_FIND_MAXDEPTH

	CLASS_ATTR_LONG(c, "minidx",		0,	t_find, n_minidx);
	CLASS_ATTR_LABEL(c, "minidx", 0, "Minimum Index");
	// @description @copy BACH_DOC_FIND_MINIDX
	
	CLASS_ATTR_LONG(c, "maxidx",		0,	t_find, n_maxidx);
	CLASS_ATTR_LABEL(c, "maxidx", 0, "Maximum Index");
	// @description @copy BACH_DOC_FIND_MAXIDX

	CLASS_ATTR_LONG(c, "idxreject",		0,	t_find, n_idxreject);
	CLASS_ATTR_LABEL(c, "idxreject", 0, "Index Reject");
	CLASS_ATTR_STYLE(c, "idxreject", 0, "onoff");
	CLASS_ATTR_FILTER_CLIP(c, "idxreject", 0, 1);
	// @description @copy BACH_DOC_FIND_IDXREJECT
	
	CLASS_ATTR_LONG(c, "depthreject",	0,	t_find, n_depthreject);
	CLASS_ATTR_LABEL(c, "depthreject", 0, "Depth Reject");
	CLASS_ATTR_STYLE(c, "depthreject", 0, "onoff");
	// @description @copy BACH_DOC_DEPTHREJECT
	
	CLASS_ATTR_LONG(c, "maxcount",		0,	t_find, n_maxcount);
	CLASS_ATTR_LABEL(c, "maxcount", 0, "Maximum Number of Results");
	CLASS_ATTR_FILTER_MIN(c, "maxcount", 0);
	CLASS_ATTR_BASIC(c, "maxcount", 0);
	// @description @copy BACH_DOC_FIND_MAXCOUNT
	
	CLASS_ATTR_LONG(c, "recursive",	0,	t_find, n_recursive);
	CLASS_ATTR_LABEL(c, "recursive", 0, "Recursive");
	CLASS_ATTR_STYLE(c, "recursive", 0, "onoff");
	// @description @copy BACH_DOC_FIND_RECURSIVE
	
	CLASS_ATTR_SYM(c, "op",	0,	t_find,	n_op);
	CLASS_ATTR_LABEL(c, "op", 0, "Comparison Operator");
	CLASS_ATTR_ACCESSORS(c, "op", NULL, find_op_set);
	CLASS_ATTR_BASIC(c, "op", 0);
	// @description @copy BACH_DOC_FIND_OP

	CLASS_ATTR_LONG(c, "size",	0,	t_find,	n_size);
	CLASS_ATTR_LABEL(c, "size", 0, "Size");
	CLASS_ATTR_FILTER_MIN(c, "size", 1);
	// @description @copy BACH_DOC_FIND_SIZE

	CLASS_ATTR_LONG(c, "depthpolicy",	0,	t_find,	n_depthpolicy);
	CLASS_ATTR_LABEL(c, "depthpolicy", 0, "Depth Policy");
	CLASS_ATTR_STYLE(c, "depthpolicy", 0, "onoff");
	CLASS_ATTR_FILTER_CLIP(c, "depthpolicy", 0, 1);
	// @description When set to 1 (default) and a lambda loop is not present,
	// sequences whose overall depth is greater than the depth of the comparison llll are not considered matches.
	// This means that, for example, if the <b>1 (2 (3))</b> llll is searched for <b>2</b> with the <m>!=</m> operator
	// (that is, items different from <b>2</b> are looked for), the found matches will be <b>1</b> and <b>3</b>.
	// If <m>depthpolicy</m> was set to 0, the <b>(2 (3))</b> sublist (whose depth is 3) would be compared with <b>2</b> (whose depth is 1), 
	// found to be different and subsequently considered a match.
	// Moreover, with the <m>recursive</m> attribute set to 0, the <b>(2 (3))</b> sublist would not be entered and <b>3</b> would not be found.
	// If a lambda loop is present, the <m>depthpolicy</m> attribute is ignored.
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	find_class = c;
	
	dev_post("bach.find compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err find_op_set(t_find *x, t_object *attr, long argc, t_atom *argv)
{	
	t_symbol *sym = atom_getsym(argv);
	
	if (argc != 1)     // bad size, don't change anything
		return 0;

	if (sym == gensym("==")) {
		x->n_deffunc = llll_eq_ignoretype;
		x->n_op = sym;
	} else if (sym == gensym("===")) {
		x->n_deffunc = llll_eq_matchtype;
		x->n_op = sym;
	} else if (sym == gensym("!=")) {
		x->n_deffunc = llll_neq_ignoretype;
		x->n_op = sym;
	} else if (sym == gensym("!==")) {
		x->n_deffunc = llll_neq_matchtype;
		x->n_op = sym;
	} else if (sym == gensym("<")) {
		x->n_deffunc = llll_lt;
		x->n_op = sym;
	} else if (sym == gensym("<=")) {
		x->n_deffunc = llll_leq;
		x->n_op = sym;
	} else if (sym == gensym(">")) {
		x->n_deffunc = llll_gt;
		x->n_op = sym;
	} else if (sym == gensym(">=")) {
		x->n_deffunc = llll_geq;
		x->n_op = sym;
	}
	return 0;
}

t_max_err find_maxidx_set(t_find *x, t_object *attr, long argc, t_atom *argv) 
{
	long maxidx = atom_getlong(argv); 
	if (maxidx == 0) { 
		object_warn((t_object *) x, "maxidx 0 not accepted: setting to -1"); 
		x->n_maxidx = -1; 
		return 0; 
	} 
	x->n_maxdepth = maxidx; 
	return 0; 
}

t_max_err find_minidx_set(t_find *x, t_object *attr, long argc, t_atom *argv) 
{
	long minidx = atom_getlong(argv); 
	if (minidx == 0) { 
		object_warn((t_object *) x, "minidx 0 not accepted: setting to 1"); 
		x->n_minidx = -1; 
		return 0; 
	} 
	x->n_minidx = minidx; 
	return 0; 
}

void find_bang(t_find *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		find_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void find_int(t_find *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	find_anything(x, _sym_int, 1, &outatom);
}

void find_float(t_find *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	find_anything(x, _sym_float, 1, &outatom);
}

void find_anything(t_find *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll, *addresses, *found;
	
	long inlet = proxy_getinlet((t_object *) x);
	x->n_result = 0;

	switch (inlet) {
		case 0:
			if (msg != _sym_bang) {
				ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
				if (!ll)
					return;
			} else
				ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
			
			
			addresses = llll_get();
			if (ll->l_size) {
				x->n_haslambda = 0;
				llllobj_test_lambda_loop_one_out((t_object *) x, LLLL_OBJ_VANILLA, ll->l_head, 2);
				if (x->n_haslambda) {
					found = llll_find(ll, addresses, x->n_size, x->n_mindepth, x->n_maxdepth, x->n_minidx, x->n_maxidx, 
									  x->n_idxreject, x->n_depthreject, x->n_maxcount, x->n_recursive, x->n_unwrap, 0, 0, 
									  (find_fn) find_func_with_lambda, x);
				} else {
					t_llll *cmp_ll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1);
                    if (cmp_ll) {
                        long size = cmp_ll->l_size;
                        if (size > 0) {
                            found = llll_find(ll, addresses, size, x->n_mindepth, x->n_maxdepth, x->n_minidx, x->n_maxidx,
                                              x->n_idxreject, x->n_depthreject, x->n_maxcount, x->n_recursive, x->n_unwrap, x->n_depthpolicy, cmp_ll->l_depth,
                                              (find_fn) find_func_no_lambda, x);
                        } else
                            found = llll_get();
                        llll_release(cmp_ll);
                    } else {
                        found = llll_get();           
                    }
				}
			} else {
				found = llll_get();
			}

			llll_release(ll);
			x->n_ob.l_rebuild = 0;
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, addresses, 1);
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, found, 0);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
			break;
		case 1:
			ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1);
			x->n_ob.l_rebuild = 1;
			llll_release(ll);
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

long find_func_with_lambda(t_find *x, t_llll *what)
{
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, what);
	return x->n_result;
}

long find_func_no_lambda(t_find *x, t_llll *what)
{
	t_llll *cmp_ll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1);
	long result = (x->n_deffunc)(what, cmp_ll);
	llll_release(cmp_ll);
	return result;
}

void find_assist(t_find *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:	sprintf(s, "llll to Search");	break; // @in 0 @type llll @digest llll to search
			case 1:	sprintf(s, "Comparison llll");	break; // @in 1 @type llll @digest Comparison llll
				// @description The comparison llll is ignored if a lambda loop is present.
			case 2:	sprintf(s, "Lambda Inlet");		break; // @in 2 @type int/llll @digest Lambda inlet
				// @description @copy BACH_DOC_LAMBDA_INLET_MATCH
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0: sprintf(s, "llll (%s): Found Items", type);		break; // @out 0 @type llll @digest Found matching items
			case 1:	sprintf(s, "llll (%s): Found Addresses", type);	break; // @out 1 @type llll @digest Addresses of found matching items
			case 2:	sprintf(s, "llll (%s): Lambda Outlet", type);	break; // @out 2 @type llll @digest Lambda outlet
				// @description @copy BACH_DOC_LAMBDA_OUTLET_MATCH
		}
	}
}

void find_inletinfo(t_find *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void find_free(t_find *x)
{
	long i;
	for (i = 2; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_find *find_new(t_symbol *s, short ac, t_atom *av)
{
	t_find *x = NULL;
	long i, true_ac, savedsize = 0;
	t_max_err err = MAX_ERR_NONE;
	t_llll *ll = NULL;

	
	if ((x = (t_find *) object_alloc_debug(find_class))) {
		// @arg 0 @name comparison @optional 1 @type llll @digest Default comparison llll
		// @description A default comparison llll. Ignored if a lambda loop is present.
		true_ac = attr_args_offset(ac, av);
		x->n_op = gensym("==");
		x->n_deffunc = llll_eq_ignoretype;
		x->n_depthpolicy = 1;
		x->n_mindepth = 1;
		x->n_maxdepth = -1;
		attr_args_process(x, ac, av);
		savedsize = x->n_size;
		llllobj_obj_setup((t_llllobj_object *) x, 2, "444");
		if (true_ac)
			ll = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, NULL, true_ac, av, 1);
		if (savedsize < 1)
			x->n_size = ll ? ll->l_size : 1;
		for (i = 2; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
				
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}