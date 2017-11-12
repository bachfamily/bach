/**
 @file
 value.c
 
 @name 
 bach.value
 
 @realname 
 bach.value
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Share lllls
 
 @description
 Shares the data it receives with other <o>bach.value</o> objects with the same name.
 
 @discussion
 Unlike <o>bach.pv</o>, <o>bach.value</o> also share its data between different patcher hierarchies.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 value, share, name, patcher, hierarchy

 @seealso
 bach.pv, bach.shelf, bach.reg, value, pv
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _vault
{
	t_object		v_ob;
	t_llll			*v_ll;
	t_bach_atomic_lock	v_lock;
	long			v_refcount;
} t_vault;

typedef struct _value
{
	struct llllobj_object 	n_ob;
	t_symbol				*n_name;
	t_vault					*n_vault;

    t_object                *m_editor;
} t_value;


void value_assist(t_value *x, void *b, long m, long a, char *s);
void value_inletinfo(t_value *x, void *b, long a, char *t);

t_value *value_new(t_symbol *s, short ac, t_atom *av);
void value_free(t_value *x);

t_vault *vault_new(t_symbol *s, short ac, t_atom *av);
void vault_free(t_vault *x);

void value_bang(t_value *x);
void value_int(t_value *x, t_atom_long v);
void value_float(t_value *x, double v);
void value_anything(t_value *x, t_symbol *msg, long ac, t_atom *av);


// editor
void value_okclose(t_value *x, char *s, short *result);
void value_edclose(t_value *x, char **ht, long size);
void value_dblclick(t_value *x);


t_class *value_class;
t_class *vault_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.value", (method) value_new, (method) value_free, (short) sizeof(t_value), 0L, A_GIMME, 0);
	
	// @method llll @digest Store and share the llll
	// @description The llll is stored and shared between all the other instances of <o>bach.value</o> with the same name.
	class_addmethod(c, (method)value_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)value_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)value_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)value_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the shared llll
	// @description When <o>bach.value</o> receives a bang, it outputs its shared llll.
	class_addmethod(c, (method)value_bang,		"bang",			0);
	
	class_addmethod(c, (method)value_assist,	"assist",		A_CANT,		0);
	
    
    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)value_dblclick,		"dblclick",		A_CANT, 0);
    class_addmethod(c, (method)value_edclose,         "edclose",		A_CANT, 0);
    class_addmethod(c, (method)value_okclose,         "okclose",       A_CANT, 0);

    
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	value_class = c;
	
	c = class_new("bach.vault", (method) vault_new, (method) vault_free, (short) sizeof(t_vault), 0L, A_GIMME, 0);
	class_register(CLASS_NOBOX, c);
	vault_class = c;
	
	dev_post("bach.value compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


void value_dblclick(t_value *x)
{
    t_vault *vault = x->n_vault;
    
    if (!x->m_editor)
        x->m_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->m_editor, gensym("visible"), 1);
    
    char *buf = NULL;
    
    bach_atomic_lock(&vault->v_lock);
    llll_to_text_buf_pretty(vault->v_ll, &buf, 0, BACH_DEFAULT_MAXDECIMALS, BACH_DEFAULT_EDITOR_LLLL_WRAP, "\t", -1, 0, NULL);
    bach_atomic_unlock(&vault->v_lock);
    
    object_method(x->m_editor, _sym_settext, buf, gensym("utf-8"));
    object_attr_setsym(x->m_editor, gensym("title"), gensym("llll"));
}

void value_okclose(t_value *x, char *s, short *result)
{
    *result = 3;
}

void value_edclose(t_value *x, char **ht, long size)
{
    // do something with the text
    if (ht) {
        t_llll *ll = llll_from_text_buf(*ht, size > 2048);
        
        if (ll) {
            t_llll *freeme;
            t_vault *vault = x->n_vault;

            bach_atomic_lock(&vault->v_lock);
            freeme = vault->v_ll;
            vault->v_ll = ll;
            bach_atomic_unlock(&vault->v_lock);
            llll_free(freeme);
            
        } else
            object_error((t_object *)x, "Can't modify llll: it is wrongly formatted.");
    }
    x->m_editor = NULL;
}



void value_bang(t_value *x)
{	
	t_llll *out_ll;
	t_vault *vault = x->n_vault;
	bach_atomic_lock(&vault->v_lock);
	out_ll = vault->v_ll;
	llll_retain(out_ll);
	bach_atomic_unlock(&vault->v_lock);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out_ll);
	llll_release(out_ll);
}

void value_int(t_value *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	value_anything(x, _sym_int, 1, &outatom);
}

void value_float(t_value *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	value_anything(x, _sym_float, 1, &outatom);
}

void value_anything(t_value *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *freeme;
	t_vault *vault = x->n_vault;
	t_llll *in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!in_ll)
		return;
	bach_atomic_lock(&vault->v_lock);
	freeme = vault->v_ll;
	vault->v_ll = in_ll;
	bach_atomic_unlock(&vault->v_lock);
	llll_free(freeme);
}

void value_assist(t_value *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll or bang"); // @in 0 @type llll/bang @digest llll to be stored and shared, or bang to output it
	} else {
		char *type;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "stored llll (%s)", type); // @out 0 @type llll @digest The stored llll
	}
}

void value_free(t_value *x)
{
	if (x->n_vault && --(x->n_vault->v_refcount) == 0) {
		object_free_debug(x->n_vault);
		x->n_name->s_thing = NULL;
	}
	llllobj_obj_free((t_llllobj_object *) x);
}

t_value *value_new(t_symbol *s, short ac, t_atom *av)
{
	t_value *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_value *) object_alloc_debug(value_class))) {
		// @arg 0 @name name @optional 0 @type symbol @digest Name
		// @description All the <o>bach.value</o> objects with the same name share the same data.
		// @arg 1 @name initial @optional 1 @type llll @digest Default llll
		// @description Initial llll to be shared. 
		// No more than one <o>bach.value</o> instance per sharing group should have the llll argument set.
		// If more than one do, it is undefined which llll will be eventually shared.
		
        x->m_editor = NULL;
        
		t_symbol *name;
		long true_ac = attr_args_offset(ac, av);
		if (true_ac == 0 || atom_gettype(av) != A_SYM) {
			object_error((t_object *) x, "Invalid or missing name");
			object_free_debug(x);
			return NULL;
		}
		name = atom_getsym(av);
		if (!name->s_thing) {
			x->n_vault = (t_vault *) object_new_typed(CLASS_NOBOX, gensym("bach.vault"), 0, NULL); // not object_new_typed_debug because the memmap will be managed by vault_new
			x->n_vault->v_refcount++;
			name->s_thing = (t_object *) x->n_vault;
		} else {
			t_vault *vault = (t_vault *) name->s_thing;
			if (NOGOOD(vault) || object_classname(vault) != gensym("bach.vault")) {
				object_error((t_object *) x, "Name %s already in use", name->s_name);
				object_free_debug(x);
				return NULL;
			}
			vault->v_refcount++;
			x->n_vault = vault;
		}
		x->n_name = name;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
		if (true_ac > 1)
			value_anything(x, NULL, true_ac - 1, av + 1);
	} else
		object_bug((t_object *) x, "Memory allocation error: couldn't create bach.value");
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

void vault_free(t_vault *x)
{
	llll_free(x->v_ll);
}

t_vault *vault_new(t_symbol *s, short ac, t_atom *av)
{
	t_vault *x = NULL;
	if ((x = (t_vault *) object_alloc_debug(vault_class))) {
		x->v_ll = llll_get();
	}
	return x;
}