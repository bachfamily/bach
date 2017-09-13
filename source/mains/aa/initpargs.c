#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "jpatcher_api.h"

typedef struct _initpargs
{
	struct llllobj_object 	n_ob;
	t_hashtab				*n_objs_to_process;
	long					n_nested;
	//void					*n_qelem;
} t_initpargs;

typedef struct _objpos
{
	t_object	*o_obj;
	long		o_depth;
	long		o_calcdepth;
} t_objpos;

void initpargs_assist(t_initpargs *x, void *b, long m, long a, char *s);
void initpargs_inletinfo(t_initpargs *x, void *b, long a, char *t);

t_initpargs *initpargs_new(t_symbol *s, short ac, t_atom *av);
void initpargs_free(t_initpargs *x);

void initpargs_add(t_initpargs *x, t_symbol *msg, long ac, t_atom *av);
void initpargs_remove(t_initpargs *x, t_symbol *msg, long ac, t_atom *av);
t_max_err initpargs_run(t_initpargs *x, t_symbol *msg, long ac, t_atom *av);
void initpargs_run_do(t_initpargs *x);
long initpargs_cmp(void *data, t_llllelem *a, t_llllelem *b);

t_class *initpargs_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.initpargs", (method)initpargs_new, (method)initpargs_free, (short)sizeof(t_initpargs), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)initpargs_add,		"add",	A_GIMME,	0);
	class_addmethod(c, (method)initpargs_remove,	"remove",	A_GIMME,	0);
	class_addmethod(c, (method)initpargs_run,		"run",	A_GIMME,	0);
	
	class_register(CLASS_NOBOX, c);
	initpargs_class = c;
	
	dev_post("bach.initpargs compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void initpargs_add(t_initpargs *x, t_symbol *msg, long ac, t_atom *av)
{
	t_object *obj = (t_object *) atom_getobj(av);
	hashtab_store(x->n_objs_to_process, (t_symbol *) obj, obj);
//	llll_appendobj(x->n_objs_to_process, obj, 0, WHITENULL_llll);
}

void initpargs_remove(t_initpargs *x, t_symbol *msg, long ac, t_atom *av)
{
	t_object *obj = (t_object *) atom_getobj(av);
	hashtab_delete(x->n_objs_to_process, (t_symbol *) obj);
//	llll_appendobj(x->n_objs_to_process, obj, 0, WHITENULL_llll);
}

t_max_err initpargs_run(t_initpargs *x, t_symbol *msg, long ac, t_atom *av)
{
	//t_llllelem *elem;
	/*
	for (elem = x->n_objs_to_process->l_head; elem; elem = elem->l_next) {
		t_object *obj = (t_object *) hatom_getobj(&elem->l_hatom);
		object_method_typed(obj, gensym("dopargs"), 0, NULL, NULL);
	}
	 */
	hashtab_methodall(x->n_objs_to_process, gensym("dopargs"));
	hashtab_clear(x->n_objs_to_process);
	return MAX_ERR_NONE;
}
/*
long initpargs_cmp(void *data, t_llllelem *a, t_llllelem *b)
{
	t_objpos *a_op = (t_objpos *) hatom_getobj(&a->l_hatom);
	t_objpos *b_op = (t_objpos *) hatom_getobj(&b->l_hatom);
	t_symbol *a_obj_classname = object_classname(a_op->o_obj);
	t_symbol *b_obj_classname = object_classname(b_op->o_obj);

	if (a_obj_classname != b_obj_classname)
		return a_obj_classname == gensym("bach.portal");
	else
		return (!a_op->o_calcdepth) || (a_op->o_depth >= b_op->o_depth);
}
*/

void initpargs_free(t_initpargs *x)
{
	;
}

t_initpargs *initpargs_new(t_symbol *s, short ac, t_atom *av)
{
	t_initpargs *x = NULL;
	t_max_err err = 0;
	
	if (x = (t_initpargs *) object_alloc(initpargs_class)) {
		x->n_objs_to_process = hashtab_new(0);
		hashtab_flags(x->n_objs_to_process, OBJ_FLAG_REF);
		object_method(x->n_objs_to_process, gensym("readonly"), 1);
	} else 
		error("couldn't instantiate initpargs");
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}