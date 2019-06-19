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

// pvitem is the actual data container
typedef struct _pvitem
{
	t_object			p_ob;
	t_llll				*p_ll; // the llll associated to one specific name in one specific patcher hierarchy
	t_object			*p_top; // the top patcher of this hierarchy
	t_llll				*p_pvs; // all the bach.pv objects in this patcher hierarchy
	t_int32_atomic		p_count;
	t_bach_atomic_lock	p_lock;
} t_pvitem;

// pvault points to all the pvitems that are associated to the same name, in different patcher hierarchies
typedef struct _pvault
{
	t_object			p_ob;
	t_symbol			*p_name; // the associated name
	t_hashtab			*p_top2pvitem; // to retrieve one specific pvitem from one specific top patcher
	t_llll				*p_pvitems; // a list of all the pvitems associated to this pvault
	t_bach_atomic_lock	p_lock; // might be a rwlock
} t_pvault;

typedef struct _pv
{
	t_llllobj_object n_ob;
	t_symbol		*n_name;
	t_pvault		*n_pvault; // the pvault associated to this name
	t_pvitem		*n_pvitem; // the pvitem associated to the top patcher of this pv
	t_llll			*n_empty;
    long            n_placed;
    
    t_object        *m_editor;
} t_pv;


void pv_assist(t_pv *x, void *b, long m, long a, char *s);
void pv_inletinfo(t_pv *x, void *b, long a, char *t);

t_pv *pv_new(t_symbol *s, short ac, t_atom *av);
void pv_free(t_pv *x);

t_pvault *pvault_new(t_symbol *s, short ac, t_atom *av);
void pvault_free(t_pvault *x);

t_pvitem *pvitem_new(t_symbol *s, short ac, t_atom *av);
void pvitem_free(t_pvitem *x);

void pv_bang(t_pv *x);
void pv_int(t_pv *x, t_atom_long v);
void pv_float(t_pv *x, double v);
void pv_anything(t_pv *x, t_symbol *msg, long ac, t_atom *av);
void pv_place_in_hierarchy(t_pv *x, t_symbol *msg, long ac, t_atom *av);

// editor
void pv_okclose(t_pv *x, char *s, short *result);
void pv_edclose(t_pv *x, char **ht, long size);
void pv_dblclick(t_pv *x);

t_class *pv_class;
t_class *pvault_class;
t_class	*pvitem_class;

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

    
    
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	pv_class = c;
	
	c = class_new("bach.pvault", (method) pvault_new, (method) pvault_free, (short) sizeof(t_pvault), 0L, A_GIMME, 0);
	class_register(CLASS_NOBOX, c);
	pvault_class = c;
	
	c = class_new("bach.pvitem", (method) pvitem_new, (method) pvitem_free, (short) sizeof(t_pvitem), 0L, A_GIMME, 0);
	class_register(CLASS_NOBOX, c);
	pvitem_class = c;
	
	dev_post("bach.pv compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


void pv_dblclick(t_pv *x)
{
    t_pvitem *pvitem = x->n_pvitem;

    if (!x->m_editor)
        x->m_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->m_editor, gensym("visible"), 1);
    
    char *buf = NULL;
    bach_atomic_lock(&pvitem->p_lock);
    llll_to_text_buf_pretty(pvitem->p_ll, &buf, 0, BACH_DEFAULT_MAXDECIMALS, BACH_DEFAULT_EDITOR_LLLL_WRAP, "\t", -1, LLLL_T_NULL, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
    bach_atomic_unlock(&pvitem->p_lock);
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
            t_llll *freeme;
            t_pvitem *pvitem;
            
            bach_atomic_lock(&x->n_pvault->p_lock);
            pvitem = x->n_pvitem;
            
            if (!pvitem) {
                bach_atomic_unlock(&x->n_pvault->p_lock);
                object_error((t_object *)x, "Can't modify llll.");
                return;
            }

            bach_atomic_lock(&pvitem->p_lock);
            freeme = pvitem->p_ll;
            pvitem->p_ll = ll;
            bach_atomic_unlock(&pvitem->p_lock);
            bach_atomic_unlock(&x->n_pvault->p_lock);

            llll_free(freeme);
            
        } else
            object_error((t_object *)x, "Can't modify llll: it is wrongly formatted.");
    }
    x->m_editor = NULL;
}





void pv_bang(t_pv *x)
{	
	t_llll *out_ll;
	t_pvitem *pvitem = x->n_pvitem;
	bach_atomic_lock(&pvitem->p_lock);
	out_ll = pvitem->p_ll;
	if (!out_ll)
		out_ll = x->n_empty;
	llll_retain(out_ll);
	bach_atomic_unlock(&pvitem->p_lock);
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
	t_llll *freeme;
	t_pvitem *pvitem;
	bach_atomic_lock(&x->n_pvault->p_lock); // this guarantees the existence of pvitem (might as well be a rwlock)
	pvitem = x->n_pvitem;
    if (!pvitem) {
        bach_atomic_unlock(&x->n_pvault->p_lock);
        defer_low(x, (method) pv_anything, msg, ac, av);
        return;
    }
	t_llll *in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!in_ll)
		return;
	bach_atomic_lock(&pvitem->p_lock);
	freeme = pvitem->p_ll;
	pvitem->p_ll = in_ll;
	bach_atomic_unlock(&pvitem->p_lock);
	bach_atomic_unlock(&x->n_pvault->p_lock);
	llll_free(freeme);
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
    dev_post("pv_free: %p", x);
	t_pvitem *pvitem = x->n_pvitem;
	t_pvault *pvault = x->n_pvault;
	if (pvault) {		
		dev_post("freeing, and we have a pvault: %p", pvault);
        dev_post("my pvitem is %p", pvitem);
        t_object *patcher = NULL;
		object_obex_lookup((t_object *) x, gensym("#P"), &patcher);
		if (pvitem->p_top != patcher) {
			dev_post("-top is not my patcher");
			t_llllelem *this_pv_elem;
			for (this_pv_elem = pvitem->p_pvs->l_head; hatom_getobj(&this_pv_elem->l_hatom) != x; this_pv_elem = this_pv_elem->l_next)
				;
			llll_destroyelem(this_pv_elem);
			if (ATOMIC_DECREMENT_32(&pvitem->p_count) == 0) {
				hashtab_delete(pvault->p_top2pvitem, (t_symbol *) pvitem->p_top);
				dev_post("--destroying pvitem %p", pvitem);
				object_free_debug(pvitem);
			}
			dev_post("-releasing pvault %p", x->n_pvault);
			object_release_debug((t_object *) pvault);
		} else {
			dev_post("-top is my patcher");
			t_llllelem *this_pv_elem;
			t_object *this_pv_patcher;
			for (this_pv_elem = pvitem->p_pvs->l_head; this_pv_elem; this_pv_elem = this_pv_elem->l_next) {
				this_pv_patcher = NULL;
				t_pv *this_pv = (t_pv *) hatom_getobj(&this_pv_elem->l_hatom);
                if (this_pv != x) {
					object_obex_lookup((t_object *) this_pv, gensym("#P"), &this_pv_patcher);
                    if (this_pv_patcher == patcher)
                        break;
                }
			}
			if (this_pv_patcher == patcher) {
				dev_post("--found another in my own patch");
				for (this_pv_elem = pvitem->p_pvs->l_head; hatom_getobj(&this_pv_elem->l_hatom) != x; this_pv_elem = this_pv_elem->l_next)
					;
				llll_destroyelem(this_pv_elem);
				if (ATOMIC_DECREMENT_32(&pvitem->p_count) == 0) {
					hashtab_delete(pvault->p_top2pvitem, (t_symbol *) pvitem->p_top);
					dev_post("---destroying pvitem %p", pvitem);
					object_free_debug(pvitem);
				}
				object_release_debug((t_object *) pvault);
			} else {
				dev_post("--didn't find another in my own patch");
				dev_post("--I'm %p", x);
				dev_post("--pvitem is %p", pvitem);
				dev_post("--deleting my pvitem from top2pvitem");
				hashtab_delete(pvault->p_top2pvitem, (t_symbol *) pvitem->p_top);
				t_llllelem *this_pvitem_elem;
				dev_post("--about to delete my pvitem from pvault->p_pvitems");
				for (this_pvitem_elem = pvault->p_pvitems->l_head; hatom_getobj(&this_pvitem_elem->l_hatom) != pvitem; this_pvitem_elem = this_pvitem_elem->l_next)
					;
				dev_post("--found this: %p", hatom_getobj(&this_pvitem_elem->l_hatom));
				llll_destroyelem(this_pvitem_elem);
				t_llllelem *this_pv_elem;
				dev_post("--now I'm running through all the pvs connected to this pvitem");
                
                long num_pvs = pvitem->p_pvs->l_size - 1;

                t_pv **pvs_of_this_pvitem = (t_pv **) bach_newptr(num_pvs * sizeof(t_pv *));
                t_pv **this_pvs_of_this_pvitem = pvs_of_this_pvitem;
                
                for (this_pv_elem = pvitem->p_pvs->l_head; this_pv_elem; this_pv_elem = this_pv_elem->l_next) {
                    t_pv *this_pv = (t_pv *) hatom_getobj(&this_pv_elem->l_hatom);
                    if (this_pv != x) {
                        *(this_pvs_of_this_pvitem++) = this_pv;
                    }
                }
                
                long i;
                for (i = 0; i < num_pvs; i++) {
                    t_pv *this_pv = pvs_of_this_pvitem[i];
                    dev_post("---here's one: %p - let's recalculate its place in the hierarchy", this_pv);
                    pv_place_in_hierarchy(this_pv, NULL, 0, NULL);
                    if (this_pv->n_pvitem->p_ll == NULL && pvitem->p_ll != NULL) {
                        llll_retain(pvitem->p_ll);
                        this_pv->n_pvitem->p_ll = pvitem->p_ll;
                    }
                }
                
                bach_freeptr(pvs_of_this_pvitem);

				dev_post("--destroying pvitem %p", pvitem);
				object_free_debug(pvitem);
				object_release_debug((t_object *) pvault);
			}
		}
	}
    //dev_post("we don't have a pvault! bug?");
    
    object_free_debug(x->m_editor);
	llll_free(x->n_empty);
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
		if (!name->s_thing) { // are you the first of your name?
			x->n_pvault = (t_pvault *) object_new_typed_debug(CLASS_NOBOX, gensym("bach.pvault"), 0, NULL);
			name->s_thing = (t_object *) x->n_pvault;
			x->n_pvault->p_name = name;
		} else {
			t_pvault *pvault = (t_pvault *) name->s_thing;
			t_symbol *classname = NULL;
			if (NOGOOD(pvault) || (classname = object_classname(pvault)) != gensym("bach.pvault")) {
				object_error((t_object *) x, "Name %s already in use by %s", name->s_name, classname->s_name);
				object_free(x);
				return NULL;
			}
			object_retain_debug((t_object *) pvault);
			x->n_pvault = pvault;
		}
		x->n_name = name;
		x->n_empty = llll_make();
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
		defer_low(x, (method) pv_place_in_hierarchy, NULL, true_ac - 1, av + 1);
	} else
		object_bug((t_object *) x, "Memory allocation error: couldn't create bach.pv");
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

void pv_place_in_hierarchy(t_pv *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_object *patcher = NULL;
	t_object *top = NULL;
	t_pvitem *pvitem = NULL;
	t_pvault *pvault = x->n_pvault;
	object_obex_lookup((t_object *) x, gensym("#P"), &patcher);
	
	dev_post("----I'm pv %p", x);
	dev_post("----my patcher is %p", patcher);
	// look for a pvitem in or above this patcher
	for (top = patcher; top; top = jpatcher_get_parentpatcher(top)) {
        dev_post("-----Climbing up");
		hashtab_lookup(pvault->p_top2pvitem, (t_symbol *) top, (t_object **) &pvitem);
		if (pvitem)
			break;
	}

	if (pvitem) {
		// if there is one, that's it
		dev_post("-----Found pvitem %p in upper or same-level patch %p", pvitem, top);
		ATOMIC_INCREMENT_32(&pvitem->p_count);
	} else {
		// if there is none, first look for a pvitem below this patcher - if you find it, you should set its patcher to this
		t_llllelem *this_pvitem_elem, *next_pvitem_elem;
		t_pvitem *this_pvitem;
		dev_post("-----couldn't find a pvitem in an upper patch");
		// so run through all the pvitems
		for (this_pvitem_elem = pvault->p_pvitems->l_head; this_pvitem_elem; this_pvitem_elem = next_pvitem_elem) {
			next_pvitem_elem = this_pvitem_elem->l_next;
			t_object *this_patcher = NULL;
			this_pvitem = (t_pvitem *) hatom_getobj(&this_pvitem_elem->l_hatom);
			dev_post("------this_pvitem is %p", this_pvitem);
			t_object *this_top = this_pvitem->p_top;
			
			// see if this pvitem's patcher has this patcher as one of its above patchers
			for (this_patcher = this_top; this_patcher && this_patcher != patcher; this_patcher = jpatcher_get_parentpatcher(this_patcher))
				;
			
			if (this_patcher) {
				// if it does
                dev_post("-------Found a pvitem under me: %p in patch %p", this_pvitem, this_patcher);
				if (!top) {
					// if it's the first being found, set it so that its patcher is this patcher
					dev_post("--------It was the first to be found, so my patcher becomes its patcher");
					pvitem = this_pvitem;
					hashtab_delete(pvault->p_top2pvitem, (t_symbol *) pvitem->p_top);
					top = this_patcher;
					hashtab_store(pvault->p_top2pvitem, (t_symbol *) top, (t_object *) pvitem);
					//llll_appendobj(pvitem->p_pvs, x, 0, WHITENULL_llll);
				} else {
					// if a previous one was found, this pvitem must be deleted and all its connected pv's should point to the one previously found
					dev_post("--------It was not the first to be found, so we're going to delete it and reset accordingly all the pvs that were connected to it");
					t_llllelem *this_pv_elem;
					for (this_pv_elem = this_pvitem->p_pvs->l_head; this_pv_elem; this_pv_elem = this_pv_elem->l_next) {
						t_pv *this_pv = (t_pv *) hatom_getobj(&this_pv_elem->l_hatom);
						dev_post("---------here's one pv: %p", this_pv);
						this_pv->n_pvitem = pvitem;
						llll_appendobj(pvitem->p_pvs, this_pv, 0, WHITENULL_llll);
					}
					bach_atomic_lock(&pvitem->p_lock);
					bach_atomic_lock(&this_pvitem->p_lock);
					if (pvitem->p_ll == NULL && this_pvitem->p_ll != NULL) {
						llll_retain(this_pvitem->p_ll);
						pvitem->p_ll = this_pvitem->p_ll;
					}
					bach_atomic_unlock(&pvitem->p_lock);
					bach_atomic_unlock(&this_pvitem->p_lock);
					llll_destroyelem(this_pvitem_elem);
					dev_post("--------destroying pvitem %p", this_pvitem);
					bach_atomic_lock(&pvault->p_lock);
                    hashtab_delete(pvault->p_top2pvitem, (t_symbol *) this_pvitem->p_top);
                    object_free_debug(this_pvitem);
					bach_atomic_unlock(&pvault->p_lock);
				}
			}
		}
		if (!pvitem) {
			// if we don't have a pvitem yet, we must create it
			pvitem = (t_pvitem *) object_new_typed_debug(CLASS_NOBOX, gensym("bach.pvitem"), 0, NULL);
			dev_post("------couldn't find a valid pvitem for me, so I'm creating a new one: %p", pvitem);
			top = patcher;
			hashtab_store(pvault->p_top2pvitem, (t_symbol *) top, (t_object *) pvitem);
			llll_appendobj(pvault->p_pvitems, pvitem, 0, WHITENULL_llll);
			dev_post("------retaining pvault %p", pvault);
		}
		pvitem->p_top = top;
	}
	
	llll_appendobj(pvitem->p_pvs, x, 0, WHITENULL_llll);
	x->n_pvitem = pvitem;
    dev_post("-my pvitem is now %p", pvitem);
	if (ac)
		pv_anything(x, NULL, ac, av);
    
}

void pvault_free(t_pvault *x)
{
	dev_post("pvault_free: %p", x);
	t_symbol *name = x->p_name;
	object_free_debug(x->p_top2pvitem);
	llll_free(x->p_pvitems);
	name->s_thing = NULL;
	//bach_remove_from_memmap(x);
}

t_pvault *pvault_new(t_symbol *s, short ac, t_atom *av)
{
	t_pvault *x = NULL;
	if ((x = (t_pvault *) object_alloc_debug(pvault_class))) {
		object_retain((t_object *) x);
		object_release((t_object *) x);
		x->p_top2pvitem = hashtab_new_debug(0);
		x->p_pvitems = llll_make();
		object_method(x->p_top2pvitem, gensym("readonly"), 1);
		hashtab_flags(x->p_top2pvitem, OBJ_FLAG_REF);
	}
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	return x;
}

void pvitem_free(t_pvitem *x)
{
	dev_post("pvitem_free: %p", x);
	llll_free(x->p_ll);
	llll_free(x->p_pvs);
	//bach_remove_from_memmap(x);
}

t_pvitem *pvitem_new(t_symbol *s, short ac, t_atom *av)
{
	t_pvitem *x = NULL;
	if ((x = (t_pvitem *) object_alloc_debug(pvitem_class))) {
		x->p_count = 1;
		x->p_pvs = llll_get();
	}
	return x;
}
