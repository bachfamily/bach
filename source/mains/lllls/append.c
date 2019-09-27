/*
 *  append.c
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

/**
 @file
 append.c
 
 @name 
 bach.append
 
 @realname 
 bach.append
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 deprecated
 
 @digest 
 Append lllls together
 
 @description
 Appends lllls together, according to the positions of the inlets by which they are received. 
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 append, join, concatenate, wrap
 
 @seealso
 bach.slice, bach.lace, bach.insert, bach.subs 
 
 @owner
 Andrea Agostini
 */

// bach.append
// a good place to learn about basic management of llll outlets

#include "foundation/llllobj.h" // you must include this.
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _append
{
    t_llllobj_object     n_ob; // inherits from t_object
    long                n_proxies;
    void                **n_proxy;
    long                n_in;
    long                n_triggers[LLLL_MAX_INLETS];
    long                n_ntriggers;
    long                n_inwrap;
    long                n_outwrap;
    t_llll                *n_set;
    t_bach_atomic_lock    n_lock;
} t_append;


void append_assist(t_append *x, void *b, long m, long a, char *s);
void append_inletinfo(t_append *x, void *b, long a, char *t);

t_append *append_new(t_symbol *s, short ac, t_atom *av);
void append_free(t_append *x);

void append_bang(t_append *x);
void append_int(t_append *x, t_atom_long v);
void append_float(t_append *x, double v);
void append_anything(t_append *x, t_symbol *msg, long ac, t_atom *av);

long append_ishot(t_append *x, long inlet);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_append, n_set, append_getattr_set);
t_max_err append_setattr_set(t_append *x, t_object *attr, long ac, t_atom *av);

t_class *append_class;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    c = class_new("bach.append", (method)append_new, (method)append_free, (short)sizeof(t_append), 0L, A_GIMME, 0);
    
    // @method llll @digest Join the llll to the others
    // @description The llll will be joined to all the other lllls received in the other inlets, 
    // in the order given by each inlet's position.
    // A <b>null</b> llll is ignored.
    // If the inlet is marked as "hot" by the <m>triggers</m> attribute, the resulting llll is output.
    class_addmethod(c, (method)append_anything,        "anything",        A_GIMME,    0);
    
    class_addmethod(c, (method)append_int,            "int",            A_LONG,        0);
    class_addmethod(c, (method)append_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)append_anything,        "list",            A_GIMME,    0);
    
    // @method bang @digest Perform the last operation
    // @description A bang will cause all the lllls in the inlets to be chained together and output.
    class_addmethod(c, (method)append_bang,            "bang",            0);
    
    class_addmethod(c, (method)append_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)append_inletinfo,    "inletinfo",    A_CANT,        0);
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA); // every object with llll outlets must call this function in its main() function
    
    
    CLASS_ATTR_LONG_VARSIZE(c, "triggers",    0,    t_append, n_triggers, n_ntriggers, LLLL_MAX_INLETS);
    CLASS_ATTR_LABEL(c, "triggers", 0, "Triggers");
    CLASS_ATTR_FILTER_CLIP(c, "triggers", -1, LLLL_MAX_INLETS);
    // @description A list setting which inlets are "hot" (i.e., which will will trigger the result).
    // <m>-1</m> means all inlets are hot. No arguments mean all inlets are cold. Default is 1.
    
    CLASS_ATTR_LONG(c, "inwrap",    0,    t_append, n_inwrap);
    CLASS_ATTR_LABEL(c, "inwrap", 0, "Wrap Input");
    CLASS_ATTR_FILTER_MIN(c, "inwrap", 0);
    // @description @copy BACH_DOC_INWRAP

    CLASS_ATTR_LONG(c, "outwrap",    0,    t_append, n_outwrap);
    CLASS_ATTR_LABEL(c, "outwrap", 0, "Wrap Output");
    CLASS_ATTR_FILTER_MIN(c, "outwrap", 0);
    // @description @copy BACH_DOC_OUTWRAP

    CLASS_ATTR_LLLL(c, "set", 0, t_append, n_set, append_getattr_set, append_setattr_set);
    CLASS_ATTR_INVISIBLE(c, "set", ATTR_GET_OPAQUE);
    // @description The <m>set</m> attribute allows providing the inlets of <o>bach.append</o> with default lllls.
    // The contents of each sublist of the <m>set</m> attribute is assigned to one inlet. 
    // So <b>set [a b] [c d] [[e f]]</b> will assign <b>a b</b> to the first inlet, <b>c d</b> to the second, 
    // <b>[e f]</b> to the third. If <o>bach.append</o> has less inlets than the size of the <m>set</m> llll,
    // the elements in excess are ignored. If it has more inlets, the inlets in excess are cleared.
    // <b>set null</b> clears all the inlets. <br />
    // Elements without parentheses are assigned to distinct inlets, as if each had a couple of parentheses around it.
    // So <b> set a b c</b> will assign <b>a</b> to the first inlet, <b>b</b> to the second, <b>c</b> to the third.<br/>
    // The <m>set</m> attribute can't be set through the object inspector.
    
    class_register(CLASS_BOX, c);
    append_class = c;
    
    dev_post("bach.append compiled %s %s", __DATE__, __TIME__);
    object_warn(NULL, "bach.append is deprecated. Please replace me with bach.join---or did you mean bach.postpend?");

    return;
}

t_max_err append_setattr_set(t_append *x, t_object *attr, long ac, t_atom *av)
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

void append_bang(t_append *x)
{    
    // the rebuild property goes to 1 in two cases:
    // 1 - everytime a new list is stored in any inlet
    // 2 - everytime an attribute is changed (this is done behind the scenes by a notify method set up in the object's main() function)
    
    long inlet = proxy_getinlet((t_object *) x);
    
    if (x->n_ob.l_rebuild != 0 || !append_ishot(x, inlet))
        append_anything(x, _sym_bang, 0, NULL);
    else
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0); // this will output the llll that has been loaded for the first outlet
}

void append_int(t_append *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    append_anything(x, _sym_int, 1, &outatom);
}

void append_float(t_append *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    append_anything(x, _sym_float, 1, &outatom);
}

void append_anything(t_append *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    long count = x->n_proxies + 1;
    long i, j;
    long outwrap = x->n_outwrap;
    t_llll *outlist, *stored, *wrapped;
    
    if (msg != _sym_bang)
        x->n_ob.l_rebuild = llllobj_parse_wrap_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet, x->n_inwrap) ? 1 : 0;
    
    if (append_ishot(x, inlet) && x->n_ob.l_rebuild) {

        outlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
        for (i = 1; i < count; i++) {
            stored = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 0);
            if (stored->l_size != 0) {
                llll_chain(outlist, llll_clone(stored));
            }
            llll_release(stored);
        }
        
        
        for (j = 0; j < outwrap; j++) {
            wrapped = llll_get();
            llll_appendllll(wrapped, outlist, 0, WHITENULL_llll);
            outlist = wrapped;
        }
        x->n_ob.l_rebuild = 0;
        llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, outlist, 0);
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0); // this will output the llll that has been loaded for the first outlet
    }
}

void append_assist(t_append *x, void *b, long m, long a, char *s)
{    
    
    if (m == ASSIST_INLET) 
        sprintf(s, "llll"); // @in 0 @loop 1 @type llll @digest llll to be joined to the ones in the other inlets
    else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest All the incoming lllls joined together
    }
}

long append_ishot(t_append *x, long inlet)
{
    long hot = 0, i;
    bach_atomic_lock(&x->n_lock);
    if (x->n_ntriggers == 0)
        hot = inlet == 0;
    else {
        for (i = 0; !hot && i < x->n_ntriggers; i++)
            if (x->n_triggers[i] < 1 || x->n_triggers[i] == inlet + 1)
                hot = 1;
    }
    bach_atomic_unlock(&x->n_lock);
    return hot;
}

void append_inletinfo(t_append *x, void *b, long a, char *t)
{
    *t = !append_ishot(x, a);
}

void append_free(t_append *x)
{
    long i;
    for (i = x->n_proxies; i > 0; i--)
        object_free_debug(x->n_proxy[i]);
    llll_free(x->n_set);
    bach_freeptr(x->n_proxy);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_append *append_new(t_symbol *s, short ac, t_atom *av)
{
    t_append *x = NULL;
    long i, proxies = 0;
    t_max_err err = 0;
    long true_ac;
    
    true_ac = attr_args_offset(ac, av);
    
    if ((x = (t_append *) object_alloc_debug(append_class))) {
        // @arg 0 @name count @optional 1 @type int @digest Number of inlets
        

        proxies = true_ac ? MAX(atom_getlong(av) - 1, 0) : 1;
        x->n_ntriggers = 1;
        x->n_triggers[0] = 1;
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
        // and two long integers, for the attributes that will be passed to the "append" method of the bach.llll object
        x->n_proxies = MIN(proxies, LLLL_MAX_INLETS);
        
        x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        attr_args_process(x, ac, av); // we call it again, because only now we can set the set attribute

    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
