/**
 @file
 perm.c
 
 @name 
 bach.perm
 
 @realname 
 bach.perm
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Return permutations of an llll
 
 @description
 Returns all or a subset of the permutations of an llll.
 
 @discussion
 If the llll has repeated elements, only distinct permutations are output.
 Beware: the number of permutations grows huge even for lllls with more than a few elements.
 Requesting all the permutations of such an llll can cause Max to get stuck for minutes, or even crash.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 permutation, permute

 @seealso
 bach.comb, bach.scramble, bach.nth, bach.cartesianprod, bach.constraints, bach.swap
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _perm
{
	struct llllobj_object 	n_ob;
	long					n_maxcount;
} t_perm;


void perm_assist(t_perm *x, void *b, long m, long a, char *s);
void perm_inletinfo(t_perm *x, void *b, long a, char *t);

t_perm *perm_new(t_symbol *s, short ac, t_atom *av);
void perm_free(t_perm *x);

void perm_bang(t_perm *x);
void perm_int(t_perm *x, t_atom_long v);
void perm_float(t_perm *x, double v);
void perm_anything(t_perm *x, t_symbol *msg, long ac, t_atom *av);

t_class *perm_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.perm", (method)perm_new, (method)perm_free, (short)sizeof(t_perm), 0L, A_GIMME, 0);	

	// @method llll @digest Return the permutations
	// @description
	// The permutations of the llll (all or a subset, depending on the <m>maxcount</m> attribute)
	// are returned, each as a sublist of the output llll.
	class_addmethod(c, (method)perm_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)perm_int,        "int",			A_LONG,		0);
	class_addmethod(c, (method)perm_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)perm_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)perm_bang,		"bang",			0);
	
	class_addmethod(c, (method)perm_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)perm_inletinfo,	"inletinfo",	A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "maxcount",	0,	t_perm, n_maxcount);
	CLASS_ATTR_FILTER_MIN(c, "maxcount", 0);
	CLASS_ATTR_LABEL(c, "maxcount", 0, "Maximum Number of Permutations");
	CLASS_ATTR_BASIC(c, "maxcount", 0);
	// @description
	// Maximum number of permutations to return.
	// If set to 0 (default), all the permutations of the input llll are returned.
	// Beware: the number of permutations grows huge even for lllls with more than a few elements.
	// Requesting all the permutations of such an llll can cause Max to get stuck for minutes, or even crash.	
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	perm_class = c;
	
	dev_post("bach.perm compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void perm_bang(t_perm *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		perm_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void perm_int(t_perm *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	perm_anything(x, _sym_int, 1, &outatom);
}

void perm_float(t_perm *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	perm_anything(x, _sym_float, 1, &outatom);
}

void perm_anything(t_perm *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll;
	if (msg != _sym_bang) {
		ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} else
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	x->n_ob.l_rebuild = 0;
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_perm(ll, x->n_maxcount), 0);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void perm_assist(t_perm *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll to return the permutations of
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Permutations as sublists of the output llll
	}
}

void perm_inletinfo(t_perm *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void perm_free(t_perm *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_perm *perm_new(t_symbol *s, short ac, t_atom *av)
{
	t_perm *x = NULL;
	long true_ac;
	t_max_err err = 0;

	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_perm *) object_alloc_debug(perm_class))) {
		// @arg 0 @name maxcount @optional 1 @type int @digest Maximum Number of Permutations
		if (true_ac)
			x->n_maxcount = atom_getlong(av);
		if (true_ac > 1)
			object_warn((t_object *) x, "Too many arguments!");
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
