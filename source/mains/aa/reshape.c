/**
 @file
 reshape.c
 
 @name 
 bach.reshape
 
 @realname 
 bach.reshape
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Impose to an llll the structure of another
 
 @description
 Changes the structure of an llll according to the structure of another.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 reshape, change, impose, structure

 @seealso
 bach.write, bach.shelf, bach.value, bach.pv, bach.portal
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _reshape
{
	struct llllobj_object 	n_ob;
	void					*n_proxy;
	long					n_in;
} t_reshape;


void reshape_assist(t_reshape *x, void *b, long m, long a, char *s);
void reshape_inletinfo(t_reshape *x, void *b, long a, char *t);

t_reshape *reshape_new(t_symbol *s, short ac, t_atom *av);
void reshape_free(t_reshape *x);

void reshape_bang(t_reshape *x);
void reshape_int(t_reshape *x, t_atom_long v);
void reshape_float(t_reshape *x, double v);
void reshape_anything(t_reshape *x, t_symbol *msg, long ac, t_atom *av);

t_class *reshape_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.reshape", (method)reshape_new, (method)reshape_free, (short)sizeof(t_reshape), 0L, A_GIMME, 0);
	
	
	// @method llll @digest Function depends on inlet
	// @description
	// The structure of an llll in the left inlet is changed according to the structure of an llll in the right inlet.
	// Moreover, when an llll is received in the left inlet the reshaped llll is output.
	class_addmethod(c, (method)reshape_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)reshape_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)reshape_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)reshape_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description The result of reshaping the two most recently received lllls is output.
	class_addmethod(c, (method)reshape_bang,		"bang",			0);
	
	class_addmethod(c, (method)reshape_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)reshape_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
	
	

	class_register(CLASS_BOX, c);
	reshape_class = c;
	
	dev_post("bach.reshape compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void reshape_bang(t_reshape *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		reshape_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void reshape_int(t_reshape *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	reshape_anything(x, _sym_int, 1, &outatom);
}

void reshape_float(t_reshape *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	reshape_anything(x, _sym_float, 1, &outatom);
}

void reshape_anything(t_reshape *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll, *model;
	long inlet = proxy_getinlet((t_object *) x);	
	if (inlet == 0) {
        if (msg != _sym_bang) {
            ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
            if (!ll)
                return;
        } else
            ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
        model = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
        llll_reshape(ll, model, NULL);
        llll_release(model);
        x->n_ob.l_rebuild = 0;
        llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, ll, 0);
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	} else
		x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1) != NULL;
}


void reshape_assist(t_reshape *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "llll with Contents");	break; // @in 0 @type llll @digest llll with contents
				// @description The llll whose structure should be changed.
			case 1: sprintf(s, "llll with Structure");	break; // @in 1 @type llll @digest llll with structer
				// @description The llll whose structure should be imposed to the llll in the left inlet.
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Reshaped llll
	}
}

void reshape_inletinfo(t_reshape *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void reshape_free(t_reshape *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_reshape *reshape_new(t_symbol *s, short ac, t_atom *av)
{
	t_reshape *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_reshape *) object_alloc_debug(reshape_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "4");
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}