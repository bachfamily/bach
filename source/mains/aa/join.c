/**
 @file
 join.c
 
 @name 
 bach.join
 
 @realname 
 bach.join
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Join lllls together
 
 @description
 Joins lllls together, according to the positions of the inlets by which they are received.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 append, join, concatenate, wrap
 
 @seealso
 bach.prepend, bach.postpend, bach.slice, bach.lace, bach.insert, bach.subs
 
 @owner
 Andrea Agostini
 */

// bach.join
// a good place to learn about basic management of llll outlets

#include "llllobj.h" // you must include this.
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _join
{
	t_llllobj_object 	n_ob; // inherits from t_object
	long				n_proxies;
	void				**n_proxy;
	long				n_in;
	t_llll				*n_triggers;
    t_bach_atomic_lock	n_triggers_lock;
	long				n_inwrap;
	long				n_outwrap;
	t_llll				*n_set;
	t_bach_atomic_lock	n_lock;
} t_join;


void join_assist(t_join *x, void *b, long m, long a, char *s);
void join_inletinfo(t_join *x, void *b, long a, char *t);

t_join *join_new(t_symbol *s, short ac, t_atom *av);
void join_free(t_join *x);

void join_bang(t_join *x);
void join_int(t_join *x, t_atom_long v);
void join_float(t_join *x, double v);
void join_anything(t_join *x, t_symbol *msg, long ac, t_atom *av);

void join_join(t_join *x);
long join_ishot(t_join *x, long inlet);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_join, n_set, join_getattr_set);
t_max_err join_setattr_set(t_join *x, t_object *attr, long ac, t_atom *av);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_join, n_triggers, join_getattr_triggers);
t_max_err join_setattr_triggers(t_join *x, t_object *attr, long ac, t_atom *av);
t_max_err join_check_triggers_llll(t_join *x, t_llll *ll);


t_class *join_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.join", (method)join_new, (method)join_free, (short)sizeof(t_join), 0L, A_GIMME, 0);
	
	// @method llll @digest Join the llll to the others
	// @description The llll will be joined to all the other lllls received in the other inlets, 
	// in the order given by each inlet's position.
	// A <b>null</b> llll is ignored.
	// If the inlet is marked as "hot" by the <m>triggers</m> attribute, the resulting llll is output.
	class_addmethod(c, (method)join_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)join_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)join_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)join_anything,		"list",			A_GIMME,	0);
	
	// @method bang @digest Output the llll
	// @description A bang in any inlet, hot or cold, will cause all the lllls received in the inlets
    // to be chained together and output.
	class_addmethod(c, (method)join_bang,			"bang",			0);
	
	class_addmethod(c, (method)join_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)join_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA); // every object with llll outlets must call this function in its main() function
	
    CLASS_ATTR_LLLL(c, "triggers", 0, t_join, n_triggers, join_getattr_triggers, join_setattr_triggers);
    CLASS_ATTR_LABEL(c, "triggers", 0, "Triggers");
	// @description A list setting which inlets are "hot" (i.e., which will will trigger the result).
	// Inlets are counted from 1. 0 means that all inlets are hot.
    // Negative indices are counted from the right (e.g., -1 means the rightmost inlet).
    // <m>null</m> means that all inlets are cold,
    // but a <m>bang</m> in any inlet will still cause the llll to be output.
    // The default is 1.
	
	CLASS_ATTR_LONG(c, "inwrap",	0,	t_join, n_inwrap);
	CLASS_ATTR_LABEL(c, "inwrap", 0, "Wrap Input");
	CLASS_ATTR_FILTER_MIN(c, "inwrap", 0);
	// @description @copy BACH_DOC_INWRAP

	CLASS_ATTR_LONG(c, "outwrap",	0,	t_join, n_outwrap);
	CLASS_ATTR_LABEL(c, "outwrap", 0, "Wrap Output");
	CLASS_ATTR_FILTER_MIN(c, "outwrap", 0);
	// @description @copy BACH_DOC_OUTWRAP

	CLASS_ATTR_LLLL(c, "set", 0, t_join, n_set, join_getattr_set, join_setattr_set);
	CLASS_ATTR_INVISIBLE(c, "set", ATTR_GET_OPAQUE);
	// @description The <m>set</m> attribute allows providing the inlets of <o>bach.join</o> with default lllls.
	// The contents of each sublist of the <m>set</m> attribute is assigned to one inlet. 
	// So <b>set (a b) (c d) ((e f))</b> will assign <b>a b</b> to the first inlet, <b>c d</b> to the second, 
	// <b>(e f)</b> to the third. If <o>bach.join</o> has less inlets than the size of the <m>set</m> llll,
	// the elements in excess are ignored. If it has more inlets, the inlets in excess are cleared.
	// <b>set null</b> clears all the inlets. <br />
	// Elements without parentheses are assigned to distinct inlets, as if each had a couple of parentheses around it.
	// So <b> set a b c</b> will assign <b>a</b> to the first inlet, <b>b</b> to the second, <b>c</b> to the third.<br/>
	// The <m>set</m> attribute can't be set through the object inspector.
	
	class_register(CLASS_BOX, c);
	join_class = c;
	
	dev_post("bach.join compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err join_setattr_triggers(t_join *x, t_object *attr, long ac, t_atom *av)
{
    t_llll *ll;
    if (ac == 0 || av) {
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, av))) {
            t_llll *free_me;
            if (join_check_triggers_llll(x, ll) != MAX_ERR_NONE) {
                llll_free(ll);
                return MAX_ERR_NONE;
            }
            bach_atomic_lock(&x->n_triggers_lock);
            free_me = x->n_triggers;
            x->n_triggers = ll;
            bach_atomic_unlock(&x->n_triggers_lock);
            llll_free(free_me);
        }
    }
    return MAX_ERR_NONE;
}

t_max_err join_check_triggers_llll(t_join *x, t_llll *ll)
{
    t_llllelem *elem;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        if (!hatom_is_number(&elem->l_hatom)) {
            object_error((t_object *) x, "Bad triggers llll");
            return MAX_ERR_GENERIC;
        }
    }
    return MAX_ERR_NONE;
}

t_max_err join_setattr_set(t_join *x, t_object *attr, long ac, t_atom *av)
{
	if ((ac == 0 || av) && x->n_ob.l_running) {
		t_llll *ll, *freeme;
		if ((ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_RETAIN))) {
			t_llllelem *elem;
			long store;
			t_llll *set_ll = llll_get(); // this is the input llll with every element parenthesized, and () for every non-assigned inlet
			for (elem = ll->l_head, store = 0; elem && store < x->n_ob.l_numstores; elem = elem->l_next, store++) {
				t_llll *store_me;
				if (hatom_gettype(&elem->l_hatom) == H_LLLL)
					store_me = llll_clone(hatom_getllll(&elem->l_hatom));
				else
					llll_appendhatom(store_me = llll_get(), &elem->l_hatom, 0, WHITENULL_llll);
				llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, store_me, store);
				llll_appendllll_clone(set_ll, store_me, 0, WHITENULL_llll, NULL);
			}
			llll_free(ll);
			if (store < x->n_ob.l_numstores) {
				t_llll *empty = llll_get();
				for ( ; store < x->n_ob.l_numstores; store++) {
					llll_retain(empty);
					llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, empty, store);
					llll_appendllll(set_ll, llll_get(), 0, WHITENULL_llll);
				}
				llll_release(empty);
			}
			bach_atomic_lock(&x->n_lock);
			freeme = x->n_set;
			x->n_set = set_ll;
			bach_atomic_unlock(&x->n_lock);
			llll_free(freeme);
		}

	}
	return MAX_ERR_NONE;
}

void join_bang(t_join *x)
{	
	// the rebuild property goes to 1 in two cases:
	// 1 - everytime a new list is stored in any inlet
	// 2 - everytime an attribute is changed (this is done behind the scenes by a notify method set up in the object's main() function)
	
//	long inlet = proxy_getinlet((t_object *) x);

	if (x->n_ob.l_rebuild != 0)
        join_join(x);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0); // this will output the llll that has been loaded for the first outlet
}

void join_int(t_join *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	join_anything(x, _sym_int, 1, &outatom);
}

void join_float(t_join *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	join_anything(x, _sym_float, 1, &outatom);
}

void join_anything(t_join *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	
	if (msg != _sym_bang)
		x->n_ob.l_rebuild = llllobj_parse_wrap_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet, x->n_inwrap) ? 1 : 0;
	
	if (join_ishot(x, inlet) && x->n_ob.l_rebuild) {
        join_join(x);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0); // this will output the llll that has been loaded for the first outlet
	}
}

void join_join(t_join *x)
{
    long count = x->n_proxies + 1;
    long i, j;
    long outwrap = x->n_outwrap;    t_llll *outlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
    for (i = 1; i < count; i++) {
        t_llll *stored = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 0);
        if (stored->l_size != 0) {
            llll_chain(outlist, llll_clone(stored));
        }
        llll_release(stored);
    }
    
    for (j = 0; j < outwrap; j++) {
        t_llll *wrapped = llll_get();
        llll_appendllll(wrapped, outlist, 0, WHITENULL_llll);
        outlist = wrapped;
    }
    x->n_ob.l_rebuild = 0;
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, outlist, 0);
}

void join_assist(t_join *x, void *b, long m, long a, char *s)
{	
	
	if (m == ASSIST_INLET) 
		sprintf(s, "llll"); // @in 0 @loop 1 @type llll @digest llll to be joined to the ones in the other inlets
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest All the incoming lllls joined together
	}
}

long join_ishot(t_join *x, long inlet)
{
	long hot = 0;
	bach_atomic_lock(&x->n_triggers_lock);
    long size = x->n_triggers->l_size;
	if (size == 0)
		hot = 0;
	else {
        long numinlets = x->n_proxies + 1;
        t_llllelem *elem;
        for (elem = x->n_triggers->l_head; elem; elem = elem->l_next) {
            long this_trigger = hatom_getlong(&elem->l_hatom);
			if (this_trigger == 0 ||
                this_trigger == inlet + 1 ||
                (this_trigger < 0 && this_trigger == inlet - numinlets))
				hot = 1;
        }
	}
	bach_atomic_unlock(&x->n_triggers_lock);
	return hot;
}

void join_inletinfo(t_join *x, void *b, long a, char *t)
{
	*t = !join_ishot(x, a);
}

void join_free(t_join *x)
{
	long i;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	llll_free(x->n_set);
    llll_free(x->n_triggers);
	bach_freeptr(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_join *join_new(t_symbol *s, short ac, t_atom *av)
{
	t_join *x = NULL;
	long i, proxies = 0;
	t_max_err err = 0;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_join *) object_alloc_debug(join_class))) {
		// @arg 0 @name count @optional 1 @type int @digest Number of inlets
		
		proxies = true_ac ? MAX(atom_getlong(av) - 1, 0) : 1;
		x->n_set = llll_get();

		attr_args_process(x, ac, av); // this must be called before llllobj_obj_setup
		// among the other things, it will parse the out attribute
		// the set attribute will not be set now, as it depends on the stores which have not been initialized yet
		
		// llllobj_obj_setup creates the object outlets, according to a string provided as its 3rd argument.
		// actually, every outlet is contained in a structure (called an "out"), which can act as a storage place for lllls ready to be output
		// you never directly "touch" the outlets. functions like outlet_anything are never directly called if you manage your outlets with the provided API
		// (which you should, because it deals with some llll's low-level details you should not be concerned of)
		// the operation of text vs. native data output is completely transparent to you. 
		// you simply ask for a certain llll to be output, and the format is managed by the API.
		// in this way, if you want to send out from an outlet the same llll over and over, you can simply shoot what's already inside the out
		// of course, the API for the outs is completely thread-safe
		
		llllobj_obj_setup((t_llllobj_object *) x, proxies + 1, "4"); // "4" means that we have one outlet, and it will output lllls according to the out attribute
		// after all this, x->n_prayargs will look like "dxxxll" (a char for every inlet, the first is always 'd', the others are 'x', plus two l's)
		// this will tell llllobj_pray that the first store contains an llll that must be copied and passed to a destructive method (the d)
		// then some other lllls that must be also copied, but whose adopter will be the first llll (the x's)
		// (that is, the first llll will appear as the owner of the elements of the base level of the copied lllls)
		// and two long integers, for the attributes that will be passed to the "join" method of the bach.llll object
		x->n_proxies = MIN(proxies, LLLL_MAX_INLETS);
		
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		attr_args_process(x, ac, av); // we call it again, because only now we can set the set attribute

        if (x->n_triggers == NULL) {
            x->n_triggers = llll_get();
            llll_appendlong(x->n_triggers, 1);
        }
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}