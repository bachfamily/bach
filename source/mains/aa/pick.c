/**
 @file
 pick.c
 
 @name 
 bach.pick
 
 @realname 
 bach.pick
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Return elements from an llll
 
 @description
 <o>bach.pick</o> returns one or more elements from an llll, according to their positions.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 pick, retrieve, address

 @seealso
 bach.nth, bach.keys
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"


typedef struct _pick
{
	t_llllobj_object 	n_ob;
	t_llll				*n_indices;
	long				*n_exists;
	long				n_nullmode;
	long				n_unwrap;
} t_pick;


void pick_assist(t_pick *x, void *b, long m, long a, char *s);
void pick_inletinfo(t_pick *x, void *b, long a, char *t);

t_pick *pick_new(t_symbol *s, short ac, t_atom *av);
void pick_free(t_pick *x);

void pick_bang(t_pick *x);
void pick_int(t_pick *x, t_atom_long v);
void pick_float(t_pick *x, double v);
void pick_anything(t_pick *x, t_symbol *msg, long ac, t_atom *av);
t_class *pick_class;

void pick_output(t_pick *x);


int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.pick", (method)pick_new, (method)pick_free, (short)sizeof(t_pick), 0L, A_GIMME, 0);
	
	// @method llll @digest Return specified elements
	// When an llll is received, <o>bach.pick</o> extracts from it the elements specified through each of the object's arguments.
	// and outputs them from the corresponding outlets.
	// Output always happens right to left, regardless of the positions of the elements in the llll.
	class_addmethod(c, (method)pick_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)pick_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)pick_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)pick_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)pick_bang,		"bang",			0);
	
	class_addmethod(c, (method)pick_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)pick_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_LONG(c, "unwrap", 0,	t_pick, n_unwrap);
	CLASS_ATTR_LABEL(c, "unwrap", 0, "Unwrap");
	CLASS_ATTR_FILTER_CLIP(c, "unwrap", 0, 1);
	CLASS_ATTR_STYLE(c, "unwrap", 0, "onoff");
	// @description
	// When set to 1 (default), the outermost couple of parentheses of any sublist to be output is removed.
	// For instance, if the llll <b>a b [c d e]</b> is input and its third element is requested,
	// <b>c d e</b> will be output instead of <b>[c d e]</b>.
	
	CLASS_ATTR_LONG(c, "nullmode", 0,	t_pick, n_nullmode);
	CLASS_ATTR_LABEL(c, "nullmode", 0, "Output Null");
	CLASS_ATTR_FILTER_CLIP(c, "nullmode", 0, 1);
	CLASS_ATTR_STYLE(c, "nullmode", 0, "onoff");
	// @description
	// When set to 1, <b>null</b> is output from any outlet corresponding to a non-existing element in the input llll.
	
	class_register(CLASS_BOX, c);
	pick_class = c;
	
	
	dev_post("bach.pick compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void pick_bang(t_pick *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		pick_anything(x, _sym_bang, 0, NULL);
	else
		pick_output(x);
}

void pick_output(t_pick *x)
{
	long i;
	for (i = x->n_indices->l_size - 1; i >= 0; i --)
		if (x->n_nullmode || x->n_exists[i])
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
}

void pick_int(t_pick *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	pick_anything(x, _sym_int, 1, &outatom);
}

void pick_float(t_pick *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	pick_anything(x, _sym_float, 1, &outatom);
}

void pick_anything(t_pick *x, t_symbol *msg, long ac, t_atom *av)
{

	long i;
	t_llll *inlist, *baby_llll;
	
	if (msg != _sym_bang) {
		if (!(inlist = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0)))
			return;
	} else 
		inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
		
	long size = x->n_indices->l_size;
	t_llllelem **found = llll_find_multiple_elems(inlist, x->n_indices, false, false, false);
	t_llllelem **this_found;
	
	for (i = 0, this_found = found; i < size; i++, this_found++) {
		baby_llll = llll_get();
		if (*this_found) {
			x->n_exists[i] = 1;
			llll_appendhatom_clone(baby_llll, &(*this_found)->l_hatom, 0, WHITENULL_llll);
			if (x->n_unwrap)
				llll_flatten(baby_llll, 1, 0);
		} else
			x->n_exists[i] = 0;
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, baby_llll, i);
	}
	llll_free(inlist);
	bach_freeptr(found);
	x->n_ob.l_rebuild = 0;
	pick_output(x);
}

void pick_assist(t_pick *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest llll to extract elements from
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		t_hatom *idx_hatom = &(llll_getindex(x->n_indices, a + 1, I_STANDARD)->l_hatom);
		if (idx_hatom->h_type == H_LONG) {
			switch (idx_hatom->h_w.w_long) {
				case 1:		sprintf(s, "llll (%s): 1st Element", type);		break;
				case 2:		sprintf(s, "llll (%s): 2nd Element", type);		break;
				case 3:		sprintf(s, "llll (%s): 3rd Element", type);		break;
				default:	sprintf(s, "llll (%s): " ATOM_LONG_PRINTF_FMT "th Element", type, idx_hatom->h_w.w_long);	break;
			}
		} else {
			char *txt = NULL;
			llll_to_text_buf(idx_hatom->h_w.w_llll, &txt, 0, 0, 0, 0, 0, NULL);
			sprintf(s, "llll (%s): Element at position %s", type, txt);
		}
		// @out 0 @loop 1 @digest Extracted elements

	}
}

void pick_inletinfo(t_pick *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void pick_free(t_pick *x)
{
	llll_free(x->n_indices);
	bach_freeptr(x->n_exists);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_pick *pick_new(t_symbol *s, short ac, t_atom *av)
{
	t_pick *x = NULL;
	long i;
	t_max_err err = 0;
	long true_ac;
	char outlets[LLLL_MAX_OUTLETS], *this_outlets;

	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_pick *) object_alloc_debug(pick_class))) {
		// @arg 0 @name addresses @optional 0 @type llll @digest Addresses of the elements to extract
		// @description The addresses of the elements to extract from the incoming llll.
		// @copy BACH_DOC_ADDRESS_BASIC
		// @copy BACH_DOC_ADDRESS_NEGATIVE
		// Each address should be wrapped in parentheses, unless it refers to an element in the root level of the llll,
		// in which case the single index by which it is composed can be left unparenthesized.
		// For each specified address an outlet is created.<br />
		// For example, <m>(1 2) (3 4)</m> will create two outlets, one for the <m>1 2</m> address, the other for the <m>3 4</m> address.<br/>
		// <m>1 2 (3 4)</m> will create three outlets, respectively for the <m>1</m>, <m>2</m> and <m>3 4</m> addresses:
		// that is, it is equivalent to writing <m>(1) (2) (3 4)</m>.
		if (true_ac == 0) {
			object_error((t_object *) x, "Missing arguments");
			dev_object_warn((t_object *) x, "--- nevermind if a blue line follows, it's allright");
			object_free_debug(x);
			return NULL;
		}
		
		t_llll *indices = NULL;
		if (true_ac)
			indices = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac, av, LLLL_PARSE_RETAIN);
		if (!indices || indices->l_depth > 2 || indices->l_size == 0) {
			object_error((t_object *) x, "bach.pick: bad arguments");
			dev_object_warn((t_object *) x, "--- nevermind if a blue line follows, it's allright");
			object_free_debug(x);
			return NULL;
		}
		
		t_llllelem *index_elem;
		t_bool good = true;
		for (index_elem = indices->l_head; good && index_elem; index_elem = index_elem->l_next) {
			switch (index_elem->l_hatom.h_type) {
				case H_LONG:
					good = (index_elem->l_hatom.h_w.w_long != 0);
					break;
				case H_LLLL: {
					t_llll *subll = index_elem->l_hatom.h_w.w_llll;
					if (subll->l_size > 0) {
						t_llllelem *subll_elem;
						for (subll_elem = subll->l_head; good && subll_elem; subll_elem = subll_elem->l_next)
							good = (subll_elem->l_hatom.h_type = H_LONG);
					} else
						good = false;
					break;
				}
				default:
					good = false;
					break;
			}
		}
		if (!good) {
			object_error((t_object *) x, "bach.pick: bad arguments");
			dev_object_warn((t_object *) x, "--- nevermind if a blue line follows, it's allright");
			object_free_debug(x);
			return NULL;
		}
		
		//llll_fatten(indices);
		long size = indices->l_size;
		this_outlets = outlets;
		for (i = 0; i < size; i++)
			*this_outlets++ = '4';
		x->n_exists = (long *) bach_newptrclear(size * sizeof(long));
		*this_outlets = 0;
		x->n_unwrap = 1;
		x->n_indices = indices;
		attr_args_process(x, ac, av);		
		llllobj_obj_setup((t_llllobj_object *) x, 1, outlets);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
