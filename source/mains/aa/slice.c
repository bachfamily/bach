/**
 @file
 slice.c
 
 @name 
 bach.slice
 
 @realname 
 bach.slice
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Split lllls in two
 
 @description 
 Splits lllls in two, according to a split point.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 slice, cut, split

 @seealso
 bach.nth, bach.find, bach.split, bach.lace, bach.delace
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _slice
{
	t_llllobj_object 	n_ob;
	long				n_index;
} t_slice;


void slice_assist(t_slice *x, void *b, long m, long a, char *s);
void slice_inletinfo(t_slice *x, void *b, long a, char *t);

t_slice *slice_new(t_symbol *s, short ac, t_atom *av);
void slice_free(t_slice *x);

void slice_bang(t_slice *x);
void slice_int(t_slice *x, t_atom_long v);
void slice_float(t_slice *x, double v);
void slice_anything(t_slice *x, t_symbol *msg, long ac, t_atom *av);
t_max_err slice_notify(t_slice *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

t_class *slice_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.slice", (method)slice_new, (method)slice_free, (short)sizeof(t_slice), 0L, A_GIMME, 0);
	
	// @method llll @digest Split the llll
	// @description The llll is divided in two, at the split point set by the <m>index</m> attribute, 
	// and the two parts are output from the two outlets.
	class_addmethod(c, (method)slice_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)slice_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)slice_float,			"float",		A_FLOAT,	0);
	class_addmethod(c, (method)slice_anything,		"list",			A_GIMME,	0);
	
	// @method bang @digest Repeat last operation
	// @description The most recently received llll is split.
	class_addmethod(c, (method)slice_bang,			"bang",			0);
	
	class_addmethod(c, (method)slice_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)slice_inletinfo,		"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	
	CLASS_ATTR_LONG(c, "index",	0,	t_slice, n_index);
	CLASS_ATTR_LABEL(c, "index", 0, "Index");
	CLASS_ATTR_BASIC(c, "index", 0);	
	// @description The split point, that is the position of the last element of the first part of the llll.
	// If a negative position is set, it is counted from the end of the llll.
	// The split point can only be in the root level of the llll.
	// The default is 1.

	class_register(CLASS_BOX, c);
	slice_class = c;
	
	dev_post("bach.slice compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void slice_bang(t_slice *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		slice_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void slice_int(t_slice *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	slice_anything(x, _sym_int, 1, &outatom);
}

void slice_float(t_slice *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	slice_anything(x, _sym_float, 1, &outatom);
}

void slice_anything(t_slice *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll, *rll;
    if (msg != _sym_bang) {
        ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
    
    if (!(rll = llll_slice(ll, x->n_index)))
        rll = llll_get();
	x->n_ob.l_rebuild = 0;
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, rll, 1);
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void slice_assist(t_slice *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) sprintf(s, "llll"); // @in 0 @type llll @digest The llll to split
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0: sprintf(s, "llll (%s): Left", type);	break; // @out 0 @type llll @digest The left part of the splitted llll
			case 1: sprintf(s, "llll (%s): Right", type);	break; // @out 1 @type llll @digest The right part of the splitted llll
		}
	}
}

void slice_inletinfo(t_slice *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void slice_free(t_slice *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}


t_slice *slice_new(t_symbol *s, short ac, t_atom *av)
{
	t_slice *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_slice *) object_alloc_debug(slice_class))) {
		// @arg 0 @name index @optional 1 @type int @digest Index
		// @description The split point, that is the position of the first element of the second part of the llll.
		// If a negative position is set, it is counted from the end of the llll.
		// The split point can only be in the root level of the llll.
		
		x->n_index = true_ac ? atom_getlong(av) : LLLL_IDX_BASE;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "44");

	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}