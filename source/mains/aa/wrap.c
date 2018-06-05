/**
 @file
 wrap.c
 
 @name 
 bach.wrap
 
 @realname 
 bach.wrap
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Wrap an llll in parentheses
 
 @description
 Raises the depth of an llll by wrapping it in parentheses.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 wrap, add, level, parenthesis

 @seealso
 bach.flat, bach.nth, bach.depth
 
 @owner
 Andrea Agostini
 */


#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _wrap
{
	struct llllobj_object 	n_ob;
	long				n_levels;
} t_wrap;


void wrap_assist(t_wrap *x, void *b, long m, long a, char *s);
void wrap_inletinfo(t_wrap *x, void *b, long a, char *t);

t_wrap *wrap_new(t_symbol *s, short ac, t_atom *av);
void wrap_free(t_wrap *x);

void wrap_bang(t_wrap *x);
void wrap_int(t_wrap *x, t_atom_long v);
void wrap_float(t_wrap *x, double v);
void wrap_anything(t_wrap *x, t_symbol *msg, long ac, t_atom *av);

t_class *wrap_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.wrap", (method)wrap_new, (method)wrap_free, (short)sizeof(t_wrap), 0L, A_GIMME, 0);

	// @method llll @digest Wrap the llll
	// @description The depth of the llll is raised by wrapping it in parentheses.
	class_addmethod(c, (method)wrap_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)wrap_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)wrap_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)wrap_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)wrap_bang,		"bang",			0);
	
	class_addmethod(c, (method)wrap_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)wrap_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	CLASS_ATTR_LONG(c, "levels",	0,	t_wrap, n_levels);
	CLASS_ATTR_FILTER_MIN(c, "levels", 0);
	CLASS_ATTR_LABEL(c, "levels", 0, "Levels");
	CLASS_ATTR_BASIC(c, "levels", 0);
	// @description The number of levels of parentheses to wrap the llll into. Default is 1.

	class_register(CLASS_BOX, c);
	wrap_class = c;
	
	dev_post("bach.wrap compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void wrap_bang(t_wrap *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		wrap_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void wrap_int(t_wrap *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	wrap_anything(x, _sym_int, 1, &outatom);
}

void wrap_float(t_wrap *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	wrap_anything(x, _sym_float, 1, &outatom);
}

void wrap_anything(t_wrap *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll, *outll;
	long i;
	long levels = x->n_levels;
	if (msg != _sym_bang) {
		ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} else
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	for (i = 0; i < levels; i++) {
		outll = llll_get();
		llll_appendllll(outll, ll, 0, WHITENULL_llll);
		ll = outll;
	}
	x->n_ob.l_rebuild = 0;
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void wrap_assist(t_wrap *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll to wrap
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest The wrapped llll
	}
}

void wrap_inletinfo(t_wrap *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void wrap_free(t_wrap *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_wrap *wrap_new(t_symbol *s, short ac, t_atom *av)
{
	t_wrap *x = NULL;
	t_max_err err = 0;
	long true_ac;

	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_wrap *) object_alloc_debug(wrap_class))) {
		// @arg 0 @name levels @optional 1 @type int @digest Levels
		// @description The number of levels of parentheses to wrap the llll into. Default is 1.
		x->n_levels = (true_ac && atom_gettype(av) == A_LONG) ? atom_getlong(av) : 1;
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