/**
 @file
 leq.c
 
 @name 
 bach.<=
 
 @realname 
 bach.leq
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Compare two lllls for less than or equal condition
 
 @description
 Compares two lllls for less than or equal condition, in numerical/lexicographical order.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 compare, less, equal, condition, lexicographical, order, numerical

 @seealso
 bach.==, bach.!=, bach.&gt;, bach.&lt;, bach.&gt;=, bach.filter, bach.sieve 
 
 @owner
 Andrea Agostini
 */
#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _leq
{
	struct llllobj_object 	n_ob;
	
	long				n_mode;
	long				n_proxies;
	
	void				*n_proxy;
	long				n_in;
	
	long				n_longout;
	char				n_rebuild;
	
} t_leq;


void leq_assist(t_leq *x, void *b, long m, long a, char *s);
void leq_inletinfo(t_leq *x, void *b, long a, char *t);

t_leq *leq_new(t_symbol *s, short ac, t_atom *av);
void leq_free(t_leq *x);

void leq_bang(t_leq *x);
void leq_int(t_leq *x, t_atom_long v);
void leq_float(t_leq *x, double v);
void leq_anything(t_leq *x, t_symbol *msg, long ac, t_atom *av);

t_class *leq_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.<=", (method)leq_new, (method)leq_free, (short)sizeof(t_leq), 0L, A_GIMME, 0);

	// @method llll @digest Store data and perform comparison
	// @description
	// In first inlet: The llll in the right inlet is compared to the llll and the result is output.<br />
	// In second inlet: The llll is stored, to be compared with an llll received in the first inlet.<br />
	// @copy BACH_DOC_LLLL_COMPARISON
	class_addmethod(c, (method)leq_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)leq_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)leq_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)leq_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description Returns the comparison result for the most recently received lllls.
	class_addmethod(c, (method)leq_bang,		"bang",			0);
	
	class_addmethod(c, (method)leq_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)leq_inletinfo,	"inletinfo",	A_CANT,		0);
	bach_class_setname("bach.<=", "bach.leq");
	class_register(CLASS_BOX, c);
	leq_class = c;
	
	dev_post("bach.<= compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void leq_bang(t_leq *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		leq_anything(x, _sym_bang, 0, NULL);
	else
		outlet_int(x->n_ob.l_out[0].b_outlet, x->n_longout);
}

void leq_int(t_leq *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	leq_anything(x, _sym_int, 1, &outatom);
}

void leq_float(t_leq *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	leq_anything(x, _sym_float, 1, &outatom);
}

void leq_anything(t_leq *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll1, *ll2;
	long inlet = proxy_getinlet((t_object *) x);
	
	switch (inlet) {
		case 0:
			if (msg != _sym_bang) {
				ll1 = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
				if (!ll1)
					return;
			} else
				ll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
			ll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
			x->n_longout = llll_leq(ll1, ll2);
			llll_release(ll1);
			llll_release(ll2);
			x->n_ob.l_rebuild = 0;
				leq_bang(x);
			break;
		case 1:
			x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1) != NULL;
			break;
	}
}

void leq_assist(t_leq *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll");
		// @in 0 @type llll @digest llll to be compared
		// @in 1 @type llll @digest llll to be compared
	} else 
		sprintf(s, "int: Comparison Result");
		// @out 0 @type int @digest Comparison result (0/1)
}

void leq_inletinfo(t_leq *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void leq_free(t_leq *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_leq *leq_new(t_symbol *s, short ac, t_atom *av)
{
	t_leq *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_leq *) object_alloc_debug(leq_class))) {
		// @arg 0 @name default @optional 1 @digest Default comparison llll

		llllobj_obj_setup((t_llllobj_object *) x, 2, "i");
		if (true_ac) 
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, NULL, true_ac, av, 1);		
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}