/**
 @file
 lace.c
 
 @name 
 bach.lace
 
 @realname 
 bach.lace
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Interleave lllls
 
 @description
 Builds an llll by combining the elements of several lllls in a round-robin fashion.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 lace, interleave, combine

 @seealso
 bach.delace, bach.trans
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _lace
{
	struct llllobj_object 	n_ob;
	long				n_proxies;
	void				**n_proxy;
	long				n_in;
	long				n_iterationmode;
} t_lace;


void lace_assist(t_lace *x, void *b, long m, long a, char *s);
void lace_inletinfo(t_lace *x, void *b, long a, char *t);

t_lace *lace_new(t_symbol *s, short ac, t_atom *av);
void lace_free(t_lace *x);

void lace_bang(t_lace *x);
void lace_int(t_lace *x, t_atom_long v);
void lace_float(t_lace *x, double v);
void lace_anything(t_lace *x, t_symbol *msg, long ac, t_atom *av);

t_class *lace_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.lace", (method)lace_new, (method)lace_free, (short)sizeof(t_lace), 0L, A_GIMME, 0);
	
	// @method llll @digest Interleave the llll with the others
	// @description
	// The llll is interleaved with the lllls received in the other inlets, in a round-robin fashion.
	// An llll received in the first inlet also causes the resulting llll to be output.
	class_addmethod(c, (method)lace_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)lace_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)lace_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)lace_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description The interleaving of the most recently received lllls is output.
	class_addmethod(c, (method)lace_bang,		"bang",			0);

	class_addmethod(c, (method)lace_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)lace_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_LONG(c, "iterationmode",	0,	t_lace, n_iterationmode);
	CLASS_ATTR_STYLE_LABEL(c, "iterationmode", 0, "enumindex", "Iteration Mode");
	CLASS_ATTR_FILTER_CLIP(c, "iterationmode", 0, 2);
	CLASS_ATTR_ENUMINDEX(c, "iterationmode", 0, "Shortest Longest Nulls");
	// @description @copy BACH_DOC_ITERATIONMODE
	
	class_register(CLASS_BOX, c);
	lace_class = c;
	
	dev_post("bach.lace compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void lace_bang(t_lace *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		lace_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void lace_int(t_lace *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	lace_anything(x, _sym_int, 1, &outatom);
}

void lace_float(t_lace *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	lace_anything(x, _sym_float, 1, &outatom);
}

void lace_anything(t_lace *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_lllls[LLLL_MAX_INLETS];
	long inlet = proxy_getinlet((t_object *) x);
	long count = x->n_proxies + 1;
	long i;
	
	if (inlet == 0) {
		if (msg != _sym_bang) {
			if ((in_lllls[0] = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0)) == NULL)
				return;
		} else
			in_lllls[0] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		for (i = 1; i < count; i++)
			in_lllls[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 1);
		x->n_ob.l_rebuild = 0;
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_lace(in_lllls, count, x->n_iterationmode), 0);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	} else {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		x->n_ob.l_rebuild = 1;
	}
}


void lace_assist(t_lace *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll %ld", a + 1); // @in 0 @loop 1 @type llll @digest llll to interleave
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Interleaved llll
	}
}

void lace_inletinfo(t_lace *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void lace_free(t_lace *x)
{
	long i;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	bach_freeptr(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_lace *lace_new(t_symbol *s, short ac, t_atom *av)
{
	t_lace *x = NULL;
	long i, lists, proxies;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_lace *) object_alloc_debug(lace_class))) {
		// @arg 0 @name count @optional 1 @type int @description Number of inlets
		// @description The number of lllls to be interleaved. Inlets are created accordingly.
		
  		lists = (true_ac && atom_gettype(av) == A_LONG) ? atom_getlong(av) : 2; // one for each list (plus one standard input for ctl inlet)
		proxies = lists - 1;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, lists, "4");
		x->n_proxies = MIN(proxies, LLLL_MAX_INLETS);
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof(void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}