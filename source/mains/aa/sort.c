/**
 @file
 sort.c
 
 @name 
 bach.sort
 
 @realname 
 bach.sort
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Sort an llll
 
 @description 
 Sorts an llll according to standard or custom criteria.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 sort, order, lambda loop

 @seealso
 bach.perm, bach.scramble
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _sort
{
	t_llllobj_object 	n_ob;
	void				*n_proxy;
	long				n_in;
	long				n_order;
	t_llll				*n_by;
	t_int32_atomic		n_by_lock;
	long				n_sort_return;
	long				n_haslambda;
} t_sort;


void sort_assist(t_sort *x, void *b, long m, long a, char *s);
void sort_inletinfo(t_sort *x, void *b, long a, char *t);

t_sort *sort_new(t_symbol *s, short ac, t_atom *av);
void sort_free(t_sort *x);

void sort_bang(t_sort *x);
void sort_int(t_sort *x, t_atom_long v);
void sort_float(t_sort *x, double v);
void sort_anything(t_sort *x, t_symbol *msg, long ac, t_atom *av);

long sort_leq_llll_lthings(t_sort *x, t_llllelem *a, t_llllelem *b);
long sort_geq_llll_lthings(t_sort *x, t_llllelem *a, t_llllelem *b);
long sort_func(t_sort *x, t_llllelem *a, t_llllelem *b);
long sort_func_simple_descending(t_sort *x, t_llllelem *a, t_llllelem *b);
long sort_func_simple_ascending(t_sort *x, t_llllelem *a, t_llllelem *b);

t_max_err sort_setattr_by(t_sort *x, t_object *attr, long ac, t_atom *av);
DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_sort, n_by, sort_getattr_by)

t_class *sort_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.sort", (method)sort_new, (method)sort_free, (short)sizeof(t_sort), 0L, A_GIMME, 0);
	
	// @method llll @digest Sort the llll
	// @description In first inlet: the llll is sorted. <br />
	// If a lambda loop is present, it defines the sorting criterium:
	// couples of elements are output from the 3rd and 4th outlets, 
	// and the lambda loop should check if they are in the correct order - 
	// that is, if in the sorted llll the element from the 3rd outlet should appear before the element from the 4th.
	// If this is true, the lambda loop should return 1 to <o>bach.sort</o>'s second inlet; otherwise, it should return 0.
	// If a lambda loop is not present, the llll is sorted according to a numeric/lexicographical criterium,
	// as if a <o>bach.&lt;=</o> object was connected to the lambda outlets and inlets.
	// In any case, <o>bach.sort</o>'s sorting algorithm is stable, 
	// meaning that two elements that are equal with respect to the sorting criterium
	// will not be swapped in the sorted llll.<br />
	// Besides returning the sorted llll from the first outlet, 
	// <o>bach.sort</o> also returns the indices of the sorted elements in the original llll from the second outlet.<br />
	// In third inlet: the llll is converted into an int
	// @copy BACH_DOC_BANG_LAMBDA_CAVEAT

	
	class_addmethod(c, (method)sort_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)sort_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)sort_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)sort_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last sort
	// The most recently received llll is sorted. <br />
	// @copy BACH_DOC_LAMBDA_CAVEAT
	class_addmethod(c, (method)sort_bang,		"bang",			0);
	
	class_addmethod(c, (method)sort_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)sort_inletinfo,	"inletinfo",	A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "order",	0, t_sort, n_order);
	CLASS_ATTR_FILTER_CLIP(c, "order", 0, 1);
	CLASS_ATTR_LABEL(c, "order", 0, "Order");
	CLASS_ATTR_ENUMINDEX(c, "order", 0, "Straight Reversed");
	CLASS_ATTR_BASIC(c, "order", 0);
	// @description When set to 1, the order of the output llll is reversed:
	// that is, a descending sort is performed instead that an ascending one.

	CLASS_ATTR_LLLL(c, "by", 0, t_sort, n_by, sort_getattr_by, sort_setattr_by);
	CLASS_ATTR_LABEL(c, "by", 0, "Keys Addresses");
	CLASS_ATTR_BASIC(c, "by", 0);
	// @description If the llll to be sorted is composed by sublists,
	// one or more elements of each sublist can be selected to be the sorting keys through the <m>by</m> attribute.
	// The value of the attribute is an llll composed by sublists, each expressing the address of one key
	// with respect to its containing sublist.
	// @copy BACH_DOC_ADDRESS_BASIC
	// @copy BACH_DOC_ADDRESS_NEGATIVE
	// Elements without parentheses are treated as distinct addresses. So, for example, the value
	// <b>(2)</b> means that the sorting key is the second element of each sublist of the root llll-
	// <b>(2) (2 3)</b> means that the first sorting key is the second element, and in case of equality 
	// the second sorting key is the third element of the second element of each sublist.
	// <b>2 3 (2 3)</b> means that the first sorting key is the second element; 
	// in case of equality the second sorting key is the third element;
	// and in case of further equality the third sorting key is the third element of the second element of each sublist.
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	sort_class = c;
	
	dev_post("bach.sort compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err sort_setattr_by(t_sort *x, t_object *attr, long ac, t_atom *av)
{
	if (ac == 0 || av) {
		t_llll *ll, *freeme;
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, av))) {
			t_llllelem *elem = ll->l_head;
			t_bool ok = true;
			t_llllelem *stacked_elem = NULL;
			while (1) {
				for (; ok && elem; elem = elem->l_next) {
					long type = hatom_gettype(&elem->l_hatom);
					if (type == H_LLLL) {
						t_llll *sub_ll = elem->l_hatom.h_w.w_llll;
						if (sub_ll->l_size == 0 || sub_ll->l_depth > 1) {
							ok = false;
							break;
						}
						stacked_elem = elem->l_next;
						elem = sub_ll->l_head;
					} else if (type != H_LONG)
						ok = false;
				}
				if (stacked_elem) {
					elem = stacked_elem;
					stacked_elem = NULL;
				} else
					break;
			}
			if (!ok) {
				object_error((t_object *) x, "Bad vaule for attribute by");
				llll_release(ll);
				return MAX_ERR_NONE;
			}
			bach_atomic_lock(&x->n_by_lock);
			freeme = x->n_by;
			x->n_by = ll;
			bach_atomic_unlock(&x->n_by_lock);
			llll_free(freeme);
		}
	}
	return MAX_ERR_NONE;
}

void sort_bang(t_sort *x)
{	
	if (proxy_getinlet((t_object *) x) == 0)
		sort_anything(x, _sym_bang, 0, NULL);
}

void sort_int(t_sort *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	sort_anything(x, _sym_int, 1, &outatom);
}

void sort_float(t_sort *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	sort_anything(x, _sym_float, 1, &outatom);
}

#ifdef ___destructive
void sort_anything(t_sort *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in, *idx_ll;
	t_llll *by;
	long depth;
	if (proxy_getinlet((t_object *) x) == 0) {
        if (msg != _sym_bang) {
            in = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
            if (!in)
                return;
        } else
            in = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);

		x->n_haslambda = 0;
		if (in->l_size >= 2) {
			t_llll *testll1 = llll_get();
			t_llll *testll2 = llll_get();
			t_llllelem *inhead = in->l_head;
			llll_appendhatom_clone(testll1, &inhead->l_hatom, 0, WHITENULL_llll);
			llll_appendhatom_clone(testll2, &inhead->l_next->l_hatom, 0, WHITENULL_llll);
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 3, testll2);
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, testll1);
			llll_free(testll1);
			llll_free(testll2);
		}
		bach_atomic_lock(&x->n_by_lock);
		by = x->n_by;
		llll_retain(by);
		bach_atomic_unlock(&x->n_by_lock);
		idx_ll = llll_get();
		if (x->n_haslambda) {
			depth = in->l_depth;
			llll_prepare_sort_data((t_object *) x, in, by, x->n_ob.l_out[2].b_type | x->n_ob.l_out[3].b_type);
			//llll_mergesort(in, &out, (sort_fn) sort_func, x);
			llll_inplacesort(in, (sort_fn) sort_func, x);
			llll_retrieve_sort_data((t_object *) x, in, idx_ll, depth);
		} else if (by->l_size > 0) {
			t_llllelem *elem;
			t_atom_long idx = 1;
			for (elem = in->l_head; elem; elem = elem->l_next) {
				t_llll *thing_ll = llll_get();
				if (elem->l_hatom.h_type == H_LLLL) {
					t_llllelem **elem_arr = llll_find_multiple_elems(elem->l_hatom.h_w.w_llll, by, false, false, false);
					long i;
					for (i = 0; i < by->l_size; ++i) {
						if (elem_arr[i])
							llll_appendhatom_clone(thing_ll, &elem_arr[i]->l_hatom, 0, WHITENULL_llll);
					}
					bach_freeptr(elem_arr);
				}
                llll_appendlong(thing_ll, x->n_order == 0 ? idx : -idx, 0, WHITENULL_llll);
                ++idx;
				elem->l_thing.w_llll = thing_ll;
			}
			//llll_mergesort_with_lthings(in, &out, (sort_fn) (x->n_order ? sort_geq_llll_lthings : sort_leq_llll_lthings), x);
			llll_inplacesort(in, (sort_fn) (x->n_order ? sort_geq_llll_lthings : sort_leq_llll_lthings), x);
			for (elem = in->l_head; elem; elem = elem->l_next) {
                idx = elem->l_thing.w_llll->l_tail->l_hatom.h_w.w_long;
                llll_appendlong(idx_ll, x->n_order == 0 ? idx : -idx, 0, WHITENULL_llll);
				llll_free(elem->l_thing.w_llll);
				elem->l_thing.w_llll = NULL;
			}
		} else {
			t_llllelem *elem;
			t_atom_long idx = 1;
			for (elem = in->l_head; elem; elem = elem->l_next) {
				elem->l_thing.w_long = idx++;
			}
			//llll_mergesort_with_lthings(in, &out, x->n_order ? llll_geq_elem : llll_leq_elem, x);
			llll_inplacesort(in, x->n_order ? llll_geq_elem : llll_leq_elem, x);
			for (elem = in->l_head; elem; elem = elem->l_next) {
				llll_appendlong(idx_ll, elem->l_thing.w_long, 0, WHITENULL_llll);
				elem->l_thing.w_whole = 0;
			}
		}

		llll_release(by);
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, idx_ll);			
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, in);
		llll_free(idx_ll);
		llll_free(in);
	} else {
		if (msg == LLLL_NATIVE_MSG) {
			t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
			if (lambda_llll) {
				if (lambda_llll->l_size)
					x->n_sort_return = hatom_getlong(&lambda_llll->l_head->l_hatom);
				else
					x->n_sort_return = 0;
				llll_free(lambda_llll);
			} else
				x->n_sort_return = 0;
		} else
			x->n_sort_return = ac ? atom_getlong(av) : 0;
		x->n_haslambda = 1;
	}
}
#else

void sort_anything(t_sort *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in, *out, *idx_ll;
	t_llll *by;
	long depth;
	if (proxy_getinlet((t_object *) x) == 0) {
		if (msg != _sym_bang) {
			in = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
			if (!in)
				return;
		} else
			in = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		x->n_haslambda = 0;
		if (in->l_size >= 2) {
			t_llll *testll1 = llll_get();
			t_llll *testll2 = llll_get();
			t_llllelem *inhead = in->l_head;
			llll_appendhatom_clone(testll1, &inhead->l_hatom, 0, WHITENULL_llll);
			llll_appendhatom_clone(testll2, &inhead->l_next->l_hatom, 0, WHITENULL_llll);
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 3, testll2);
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, testll1);
			llll_free(testll1);
			llll_free(testll2);
		}
		bach_atomic_lock(&x->n_by_lock);
		by = x->n_by;
		llll_retain(by);
		bach_atomic_unlock(&x->n_by_lock);
		idx_ll = llll_get();
		if (x->n_haslambda) {
			depth = in->l_depth;
			llll_prepare_sort_data((t_object *) x, in, by, x->n_ob.l_out[2].b_type | x->n_ob.l_out[3].b_type);
			llll_mergesort(in, &out, (sort_fn) sort_func, x);
			llll_retrieve_sort_data((t_object *) x, out, idx_ll, depth);
		} else if (by->l_size > 0) {
			t_llllelem *elem;
			t_atom_long idx = 1;
			for (elem = in->l_head; elem; elem = elem->l_next) {
				t_llll *thing_ll = llll_get();
				if (elem->l_hatom.h_type == H_LLLL) {
					t_llllelem **elem_arr = llll_find_multiple_elems(elem->l_hatom.h_w.w_llll, by, false, false, false);
					long i;
					for (i = 0; i < by->l_size; ++i) {
						if (elem_arr[i])
							llll_appendhatom_clone(thing_ll, &elem_arr[i]->l_hatom, 0, WHITENULL_llll);
					}
					bach_freeptr(elem_arr);
				}
				llll_appendlong(thing_ll, idx++, 0, WHITENULL_llll);
				elem->l_thing.w_llll = thing_ll;
			}
			llll_mergesort_with_lthings(in, &out, (sort_fn) (x->n_order ? sort_geq_llll_lthings : sort_leq_llll_lthings), x);
			for (elem = out->l_head; elem; elem = elem->l_next) {
				llll_appendlong(idx_ll, elem->l_thing.w_llll->l_tail->l_hatom.h_w.w_long, 0, WHITENULL_llll);
				llll_free(elem->l_thing.w_llll);
				elem->l_thing.w_llll = NULL;
			}
		} else {
			t_llllelem *elem;
			t_atom_long idx = 1;
			for (elem = in->l_head; elem; elem = elem->l_next) {
				elem->l_thing.w_long = idx++;
			}
			llll_mergesort_with_lthings(in, &out, x->n_order ? llll_geq_elem : llll_leq_elem, x);
			for (elem = out->l_head; elem; elem = elem->l_next) {
				llll_appendlong(idx_ll, elem->l_thing.w_long, 0, WHITENULL_llll);
				elem->l_thing.w_whole = 0;
			}
		}
		llll_release(by);
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, idx_ll);
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out);
		llll_free(idx_ll);
		llll_free(out);
	} else {
		if (msg == LLLL_NATIVE_MSG) {
			t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
			if (lambda_llll) {
				if (lambda_llll->l_size)
					x->n_sort_return = hatom_getlong(&lambda_llll->l_head->l_hatom);
				else
					x->n_sort_return = 0;
				llll_free(lambda_llll);
			} else
				x->n_sort_return = 0;
		} else
			x->n_sort_return = ac ? atom_getlong(av) : 0;
		x->n_haslambda = 1;
	}
}
#endif

long sort_leq_llll_lthings(t_sort *x, t_llllelem *a, t_llllelem *b)
{
	return llll_leq(a->l_thing.w_llll, b->l_thing.w_llll);
}

long sort_geq_llll_lthings(t_sort *x, t_llllelem *a, t_llllelem *b)
{
	return llll_geq(a->l_thing.w_llll, b->l_thing.w_llll);
}

long sort_func(t_sort *x, t_llllelem *a, t_llllelem *b)
{
	t_llll_sort_item *a_item = (t_llll_sort_item *)(a->l_hatom.h_w.w_obj);
	t_llll_sort_item *b_item = (t_llll_sort_item *)(b->l_hatom.h_w.w_obj);
	t_llll_sort_item *swap;
	
	if (x->n_order) {
		swap = a_item;
		a_item = b_item;
		b_item = swap;
	}

	x->n_haslambda = 0;
    
    switch (x->n_ob.l_out[3].b_type) {
        case LLLL_O_TEXT:
            outlet_anything(x->n_ob.l_out[3].b_outlet, b_item->n_t_sym, b_item->n_t_ac, b_item->n_t_av);
            break;
        case LLLL_O_MAX:
            outlet_anything(x->n_ob.l_out[3].b_outlet, b_item->n_m_sym, b_item->n_m_ac, b_item->n_m_av);
            break;
        case LLLL_O_NATIVE:
            outlet_anything(x->n_ob.l_out[3].b_outlet, b_item->n_n_sym, 1, b_item->n_n_av);
            break;
        default:
            break;
    }

    switch (x->n_ob.l_out[2].b_type) {
        case LLLL_O_TEXT:
            outlet_anything(x->n_ob.l_out[2].b_outlet, a_item->n_t_sym, a_item->n_t_ac, a_item->n_t_av);
            break;
        case LLLL_O_MAX:
            outlet_anything(x->n_ob.l_out[2].b_outlet, a_item->n_m_sym, a_item->n_m_ac, a_item->n_m_av);
            break;
        case LLLL_O_NATIVE:
            outlet_anything(x->n_ob.l_out[2].b_outlet, a_item->n_n_sym, 1, a_item->n_n_av);
            break;
        default:
            break;
    }
	return x->n_sort_return;
}

long sort_func_simple_descending(t_sort *x, t_llllelem *a, t_llllelem *b)
{
	t_llll_sort_item *a_item = (t_llll_sort_item *)(a->l_hatom.h_w.w_obj);
	t_llll_sort_item *b_item = (t_llll_sort_item *)(b->l_hatom.h_w.w_obj);
	return llll_leq_hatom(&a_item->n_term, &b_item->n_term);
}

long sort_func_simple_ascending(t_sort *x, t_llllelem *a, t_llllelem *b)
{
	t_llll_sort_item *a_item = (t_llll_sort_item *)(a->l_hatom.h_w.w_obj);
	t_llll_sort_item *b_item = (t_llll_sort_item *)(b->l_hatom.h_w.w_obj);
	return llll_leq_hatom(&b_item->n_term, &a_item->n_term);
}

void sort_assist(t_sort *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) sprintf(s, "llll"); // @in 0 @type llll @digest llll to sort
		else sprintf(s, "llll: Lambda Inlet"); // @in 1 @type int/llll @digest Lambda inlet
		// @description @copy BACH_DOC_LAMBDA_INLET_GENERAL_HEADER
		// In this case, if the elements coming from the lambda outlets are in the correct order,
		// the return value should be 1, otherwise 0.
		// @copy BACH_DOC_LAMBDA_GENERAL_WARNING
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0:	sprintf(s, "llll (%s): Sorted", type);			break;
				// @out 0 @type llll @digest Sorted llll
			case 1:	sprintf(s, "llll (%s): Indices", type);			break;
				// @out 1 @type llll @digest Indices
				// @description The position each element of the sorted llll had in the original llll.
			case 2:	sprintf(s, "llll (%s): Lambda Outlet 1", type);	break;
				// @out 2 @type llll @digest Lambda Outlet 1
				// @description @copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
				// If the elements output from the lambda outlets are in the correct order,
				// that is if the element output from the third outlet should appear 
				// before the element output from the fourth outlet in the sorted llll,
				// then 1 is expected in the lambda inlet; otherwise, 0 is expected.
				// @copy BACH_DOC_LAMBDA_GENERAL_WARNING
			case 3:	sprintf(s, "llll (%s): Lambda Outlet 2", type);	break;
				// @out 3 @type llll @digest Lambda Outlet 2
				// @description @copy BACH_DOC_LAMBDA_OUTLET_GENERAL_HEADER
				// If the elements output from the lambda outlets are in the correct order,
				// that is if the element output from the third outlet should appear 
				// before the element output from the fourth outlet in the sorted llll,
				// then 1 is expected in the lambda inlet; otherwise, 0 is expected.
				// @copy BACH_DOC_LAMBDA_GENERAL_WARNING
		}
	}
}

void sort_inletinfo(t_sort *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void sort_free(t_sort *x)
{
	object_free_debug(x->n_proxy);
	llll_free(x->n_by);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_sort *sort_new(t_symbol *s, short ac, t_atom *av)
{
	t_sort *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_sort *) object_alloc_debug(sort_class))) {
		x->n_by = llll_get();
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4444");
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
	} else 
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}