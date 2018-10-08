#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _mdelace
{
	struct llllobj_object 	n_ob;
	long					n_count;
} t_mdelace;


void mdelace_assist(t_mdelace *x, void *b, long m, long a, char *s);
void mdelace_inletinfo(t_mdelace *x, void *b, long a, char *t);

t_mdelace *mdelace_new(t_symbol *s, short ac, t_atom *av);
void mdelace_free(t_mdelace *x);

void mdelace_bang(t_mdelace *x);
void mdelace_int(t_mdelace *x, t_atom_long v);
void mdelace_float(t_mdelace *x, double v);
void mdelace_anything(t_mdelace *x, t_symbol *msg, long ac, t_atom *av);

t_class *mdelace_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.mdelace", (method)mdelace_new, (method)mdelace_free, (short)sizeof(t_mdelace), 0L, A_GIMME, 0);
	//llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);

	class_addmethod(c, (method)mdelace_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)mdelace_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)mdelace_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)mdelace_anything,	"list",			A_GIMME,	0);
	
	class_addmethod(c, (method)mdelace_bang,		"bang",			0);
	
	class_addmethod(c, (method)mdelace_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)mdelace_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	CLASS_ATTR_LONG(c, "count",	0,	t_mdelace, n_count);
	CLASS_ATTR_FILTER_MIN(c, "count", 1);
	CLASS_ATTR_LABEL(c, "count", 0, "Count");
	CLASS_ATTR_BASIC(c, "count", 0);
	
	class_register(CLASS_BOX, c);
	mdelace_class = c;
	
	dev_post("bach.mdelace compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void mdelace_bang(t_mdelace *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		mdelace_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void mdelace_int(t_mdelace *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	mdelace_anything(x, _sym_int, 1, &outatom);
}

void mdelace_float(t_mdelace *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	mdelace_anything(x, _sym_float, 1, &outatom);
}

void mdelace_anything(t_mdelace *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll;
	if (msg != _sym_bang) {
		ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} else
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);

	x->n_ob.l_rebuild = 0;
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_mdelace(ll, x->n_count), 0);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void mdelace_assist(t_mdelace *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type);
	}
}

void mdelace_inletinfo(t_mdelace *x, void *b, long a, char *t)
{
	*t = 1;
}

void mdelace_free(t_mdelace *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_mdelace *mdelace_new(t_symbol *s, short ac, t_atom *av)
{
	t_mdelace *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long true_ac;

	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_mdelace *) object_alloc_debug(mdelace_class))) {
		object_warn((t_object *) x, "bach.mdelace is deprecated. Please replace me with bach.delace mono!");
		x->n_count = (true_ac && atom_gettype(av) == A_LONG) ? atom_getlong(av) : 2;		
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
