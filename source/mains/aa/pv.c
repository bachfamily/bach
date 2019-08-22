/**
 @file
 pv.c
 
 @name 
 bach.pv
 
 @realname 
 bach.pv
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Share lllls within a patch hierarchy
 
 @description
 Shares the data it receives with other <o>bach.pv</o> objects with the same name, located in the same patch hierarchy.
 
 @discussion
 Other <o>bach.pv</o> objects with the same name, but belonging to different patcher hierarchies, 
 will share independently their own data.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 share, value, data, patch, hierarchy, name

 @seealso
 bach.value, bach.shelf, bach.reg, value, pv
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

#include "pvManager.hpp"

typedef struct _pv
{
	t_llllobj_object    n_ob;
	t_symbol		    *n_name;
    
    t_patcherVariable   *n_var;
    
    t_object            *m_editor;
} t_pv;


void pv_assist(t_pv *x, void *b, long m, long a, char *s);
void pv_inletinfo(t_pv *x, void *b, long a, char *t);

t_pv *pv_new(t_symbol *s, short ac, t_atom *av);
void pv_free(t_pv *x);


void pv_bang(t_pv *x);
void pv_int(t_pv *x, t_atom_long v);
void pv_float(t_pv *x, double v);
void pv_anything(t_pv *x, t_symbol *msg, long ac, t_atom *av);

// editor
void pv_okclose(t_pv *x, char *s, short *result);
void pv_edclose(t_pv *x, char **ht, long size);
void pv_dblclick(t_pv *x);

void pv_setpatchervariable(t_pv *x, t_symbol *name, t_patcherVariable *var);

t_class *pv_class;

extern t_bach* bach;
pvManager* thePvManager = bach->b_thePvManager;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.pv", (method) pv_new, (method) pv_free, (short) sizeof(t_pv), 0L, A_GIMME, 0);
	
	// @method llll @digest Store and share the llll
	// @description The llll is stored and shared between all the other instances of <o>bach.pv</o> with the same name,
	// located in the same patcher hierarchy.
	class_addmethod(c, (method)pv_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)pv_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)pv_float,	"float",		A_FLOAT,	0);
	class_addmethod(c, (method)pv_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the shared llll
	// @description When <o>bach.pv</o> receives a bang, it outputs its shared llll.
	class_addmethod(c, (method)pv_bang,		"bang",			0);
	
	class_addmethod(c, (method)pv_assist,	"assist",		A_CANT,		0);
	
    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)pv_dblclick,         "dblclick",		A_CANT, 0);
    class_addmethod(c, (method)pv_edclose,         "edclose",		A_CANT, 0);
    class_addmethod(c, (method)pv_okclose,         "okclose",       A_CANT, 0);
    
    class_addmethod(c, (method)pv_setpatchervariable, "setpatchervariable", A_CANT, 0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	pv_class = c;
	
	dev_post("bach.pv compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


void pv_dblclick(t_pv *x)
{

    if (!x->m_editor)
        x->m_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->m_editor, gensym("visible"), 1);
    
    char *buf = NULL;
    t_llll *ll = x->n_var->get();
    llll_to_text_buf_pretty(ll, &buf, 0, BACH_DEFAULT_MAXDECIMALS, BACH_DEFAULT_EDITOR_LLLL_WRAP, "\t", -1, LLLL_T_NULL, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
    llll_release(ll);
    void *rv = object_method(x->m_editor, _sym_settext, buf, gensym("utf-8"));
    if (rv) {
        t_object *ed = x->m_editor;
        x->m_editor = NULL;
        object_free(ed);
    } else
        object_attr_setsym(x->m_editor, gensym("title"), gensym("llll"));
}

void pv_okclose(t_pv *x, char *s, short *result)
{
    *result = 3;
}

void pv_edclose(t_pv *x, char **ht, long size)
{
    // do something with the text
    if (!x->m_editor) // which means that something was wrong
        return;
    if (ht) {
        t_llll *ll = llll_from_text_buf(*ht, size > MAX_SYM_LENGTH);
        if (ll) {
            x->n_var->set(ll);
            llll_free(ll);
        } else
            object_error((t_object *)x, "Can't modify llll: it is wrongly formatted.");
    }
    x->m_editor = NULL;
}

void pv_setpatchervariable(t_pv *x, t_symbol *name, t_patcherVariable *var)
{
    x->n_var = var;
}

void pv_bang(t_pv *x)
{	
    t_llll *out_ll = x->n_var->get();
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out_ll);
	llll_release(out_ll);
}

void pv_int(t_pv *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	pv_anything(x, _sym_int, 1, &outatom);
}

void pv_float(t_pv *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	pv_anything(x, _sym_float, 1, &outatom);
}

void pv_anything(t_pv *x, t_symbol *msg, long ac, t_atom *av)
{	
    if (!x->n_var) {
        defer_low(x, (method) pv_anything, msg, ac, av);
        return;
    }
	t_llll *in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!in_ll)
		return;
    x->n_var->set(in_ll);
    llll_free(in_ll);
}

void pv_assist(t_pv *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll or bang"); // @in 0 @type llll/bang @digest llll to be stored and shared, or bang to output it
	} else {
		char *type;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "stored llll (%s)", type); // @out 0 @type llll @digest The stored llll
	}
}

void pv_free(t_pv *x)
{
    thePvManager->removeVariable(x->n_name, (t_object*) x);
    object_free_debug(x->m_editor);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_pv *pv_new(t_symbol *s, short ac, t_atom *av)
{
	t_pv *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_pv *) object_alloc_debug(pv_class))) {
		// @arg 0 @name name @optional 0 @type symbol @digest Name
		// @description All the <o>bach.pv</o> objects with the same name and located in the same patcher hierarchy
		// share the same data.
		// @arg 1 @name initial @optional 1 @type llll @digest Default llll
		// @description Initial llll to be shared. 
		// No more than one <o>bach.pv</o> instance per sharing group should have the llll argument set.
		// If more than one do, it is undefined which llll will be eventually shared.
	
		t_symbol *name;
		long true_ac = attr_args_offset(ac, av);
		if (true_ac < 1 || atom_gettype(av) != A_SYM) {
			object_error((t_object *) x, "Invalid or missing name");
			object_free(x);
			return NULL;
		}
		name = atom_getsym(av);
        x->n_var = thePvManager->getVariable(name, (t_object *) x);

		x->n_name = name;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else
		object_bug((t_object *) x, "Memory allocation error: couldn't create bach.pv");
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
