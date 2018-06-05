/**
 @file
 defer.c
 
 @name 
 bach.defer
 
 @realname 
 bach.defer
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Put an llll at the front of the low-priority queue
 
 @description
 Puts the incoming llll at the front of the low-priority queue.
 
 @discussion
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 defer, queue, low-priority

 @seealso
 bach.deferlow, bach.pipe
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _defer
{
	struct llllobj_object 	n_ob;
} t_defer;


void defer_assist(t_defer *x, void *b, long m, long a, char *s);
void defer_inletinfo(t_defer *x, void *b, long a, char *t);

t_defer *defer_new(t_symbol *s, short ac, t_atom *av);
void defer_free(t_defer *x);

void defer_bang(t_defer *x);
void defer_int(t_defer *x, t_atom_long v);
void defer_float(t_defer *x, double v);
void defer_anything(t_defer *x, t_symbol *msg, long ac, t_atom *av);

void defer_output(t_defer *x, t_symbol *msg, long ac, t_atom *av);

t_class *defer_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.defer", (method)defer_new, (method)defer_free, (short)sizeof(t_defer), 0L, A_GIMME, 0);
	
	// @method llll @digest Defer the llll
	// @description
	// Puts the llll at the front of the low-priority queue. 
	// This means that nothing changes if the message was already in the main thread.
	
	class_addmethod(c, (method)defer_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)defer_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)defer_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)defer_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Defer the bang
	// @description
	// Puts the bang at the front of the low-priority queue. 
	// This means that nothing changes if the message was already in the main thread.
	class_addmethod(c, (method)defer_bang,		"bang",			0);
	
	class_addmethod(c, (method)defer_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)defer_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	defer_class = c;
	
	dev_post("bach.defer compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void defer_bang(t_defer *x)
{	
	defer_anything(x, _sym_bang, 0, NULL);
}

void defer_int(t_defer *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	defer_anything(x, _sym_int, 1, &outatom);
}

void defer_float(t_defer *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	defer_anything(x, _sym_float, 1, &outatom);
}

void defer_anything(t_defer *x, t_symbol *msg, long ac, t_atom *av)
{
	t_atom outatom;
	t_llll *inll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (inll) {
		atom_setobj(&outatom, inll);
		defer(x, (method) defer_output, NULL, 1, &outatom);
	}
}

void defer_output(t_defer *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll = (t_llll *) av->a_w.w_obj;
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, ll);
	llll_release(ll);
}

void defer_assist(t_defer *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll to defer
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest The deferred llll
	}
}

void defer_inletinfo(t_defer *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void defer_free(t_defer *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_defer *defer_new(t_symbol *s, short ac, t_atom *av)
{
	t_defer *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_defer *) object_alloc_debug(defer_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}