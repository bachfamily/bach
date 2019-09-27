/*
 *  value.c
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
 Shares the data it receives with other <o>bach.value</o> objects with the same name, as well as bell variables.
 
 @discussion
 Unlike <o>bach.pv</o>, <o>bach.value</o> also share its data between different patcher hierarchies.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 value, share, name, patcher, hierarchy

 @seealso
 bach.pv, bach.shelf, bach.reg, value, pv, bach.eval
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"
#include "bell/ast.hpp"


typedef struct _value
{
    t_llllobj_object    n_ob;
    t_symbol            *n_name;
    astGlobalVar        *n_var;
    long                n_auto[2];
    t_object            *m_editor;
} t_v;


void value_assist(t_v *x, void *b, long m, long a, char *s);
void value_inletinfo(t_v *x, void *b, long a, char *t);

t_v *value_new(t_symbol *s, short ac, t_atom *av);
void value_free(t_v *x);

void value_bang(t_v *x);
void value_triggerfromclient(t_v *x, long dummy);

void value_int(t_v *x, t_atom_long v);
void value_float(t_v *x, double v);
void value_anything(t_v *x, t_symbol *msg, long ac, t_atom *av);

t_max_err value_setattr_auto(t_v *x, t_object *attr, long ac, t_atom *av);



// editor
void value_okclose(t_v *x, char *s, short *result);
void value_edclose(t_v *x, char **ht, long size);
void value_dblclick(t_v *x);



t_class *value_class;
t_class *vault_class;

extern t_bach* bach;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.value", (method) value_new, (method) value_free, (short) sizeof(t_v), 0L, A_GIMME, 0);
    
    // @method llll @digest Store and share the llll
    // @description The llll is stored and shared between all the other instances of <o>bach.value</o> with the same name.
    class_addmethod(c, (method)value_anything,    "anything",        A_GIMME,    0);
    
    class_addmethod(c, (method)value_int,        "int",            A_LONG,        0);
    class_addmethod(c, (method)value_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)value_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Output the shared llll
    // @description When <o>bach.value</o> receives a bang, it outputs its shared llll.
    class_addmethod(c, (method)value_bang,        "bang",            0);
    class_addmethod(c, (method)value_triggerfromclient,     "triggerfromclient", A_CANT, 0);

    class_addmethod(c, (method)value_assist,    "assist",        A_CANT,        0);
    
    
    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)value_dblclick,        "dblclick",        A_CANT, 0);
    class_addmethod(c, (method)value_edclose,         "edclose",        A_CANT, 0);
    class_addmethod(c, (method)value_okclose,         "okclose",       A_CANT, 0);

    CLASS_ATTR_LONG_ARRAY(c, "auto", 0, t_v, n_auto, 2);
    CLASS_ATTR_ACCESSORS(c, "auto", NULL, value_setattr_auto);
    CLASS_ATTR_LABEL(c, "auto", 0, "Automatically output llll");
    CLASS_ATTR_BASIC(c, "auto", 0);
    // @description When set to 1, the stored llll is automatically output
    // whenever it is set by another object of the same name.<br/>
    // An optional second integer sets the priority (defaulting to 0):
    // the priority controls the order in which different bach.value objects
    // of the same name (and with the <b>auto</b> attribute switched on)
    // will automatically output the llll they receive.
    // The higher the priority, the earlier the object will fire.
    // The output order of objects with the same priority is undefined.
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    
    class_register(CLASS_BOX, c);
    value_class = c;
    
    dev_post("bach.value compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

t_max_err value_setattr_auto(t_v *x, t_object *attr, long ac, t_atom *av)
{
    if (ac >= 1) {
        long val = atom_getlong(av);
        if (!x->n_var)
            return MAX_ERR_NONE;
        switch (val) {
            case 0: {
                x->n_var->getVar()->clients.erase({(t_object *) x, x->n_auto[1]});
                x->n_auto[0] = 0;
                break;
            }
            default: {
                long const priority = ac >= 2 ? atom_getlong(av + 1) : 0;
                x->n_var->getVar()->addClient((t_object *) x, priority);
                x->n_auto[0] = 1;
                x->n_auto[1] = priority;
                break;
            }
        }
    }
    return MAX_ERR_NONE;
}


void value_dblclick(t_v *x)
{
    
    if (!x->m_editor)
        x->m_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->m_editor, gensym("visible"), 1);
    
    char *buf = NULL;
    
    llll_to_text_buf_pretty(x->n_var->eval(), &buf, 0, BACH_DEFAULT_MAXDECIMALS, BACH_DEFAULT_EDITOR_LLLL_WRAP, "\t", -1, LLLL_T_NULL, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
    
    void *rv = object_method(x->m_editor, _sym_settext, buf, gensym("utf-8"));
    if (rv) {
        t_object *ed = x->m_editor;
        x->m_editor = NULL;
        object_free(ed);
    } else
        object_attr_setsym(x->m_editor, gensym("title"), gensym("llll"));
}

void value_okclose(t_v *x, char *s, short *result)
{
    *result = 3;
}

void value_edclose(t_v *x, char **ht, long size)
{
    // do something with the text
    if (!x->m_editor) // which means that something was wrong
        return;
    if (ht) {
        t_llll *ll = llll_from_text_buf(*ht, size > MAX_SYM_LENGTH);
        
        if (ll) {
            x->n_var->assign(ll);
        } else
            object_error((t_object *)x, "Can't modify llll: it is wrongly formatted.");
    }
    x->m_editor = NULL;
}

void value_bang(t_v *x)
{    
    t_llll *out_ll = x->n_var->eval();
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, out_ll);
    llll_release(out_ll);
}

void value_triggerfromclient(t_v *x, long dummy)
{
    value_bang(x);
}

void value_int(t_v *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    value_anything(x, _sym_int, 1, &outatom);
}

void value_float(t_v *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    value_anything(x, _sym_float, 1, &outatom);
}

void value_anything(t_v *x, t_symbol *msg, long ac, t_atom *av)
{    
    t_llll *in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
    if (!in_ll)
        return;
    x->n_var->assign(in_ll);
}

void value_assist(t_v *x, void *b, long m, long a, char *s)
{    
    if (m == ASSIST_INLET) {
        sprintf(s, "llll or bang"); // @in 0 @type llll/bang @digest llll to be stored and shared, or bang to output it
    } else {
        char *type;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "stored llll (%s)", type); // @out 0 @type llll @digest The stored llll
    }
}

void value_free(t_v *x)
{
    if (x->n_auto[0] && x->n_var)
        x->n_var->getVar()->clients.erase({(t_object *) x, x->n_auto[1]});
    object_free_debug(x->m_editor);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_v *value_new(t_symbol *s, short ac, t_atom *av)
{
    t_v *x = NULL;
    t_max_err err = MAX_ERR_NONE;
    
    if ((x = (t_v *) object_alloc_debug(value_class))) {
        // @arg 0 @name name @optional 0 @type symbol @digest Name
        // @description All the <o>bach.value</o> objects and bell variables
        // with the same name share the same data.
        // @arg 1 @name initial @optional 1 @type llll @digest Default llll
        // @description Initial llll to be shared. 
        // No more than one <o>bach.value</o> instance per sharing group should have the llll argument set.
        // If more than one do, it is undefined which llll will be eventually shared.
        
        x->m_editor = NULL;
        
        long true_ac = attr_args_offset(ac, av);
        if (true_ac == 0 || atom_gettype(av) != A_SYM) {
            object_error((t_object *) x, "Invalid or missing name");
            object_free_debug(x);
            return NULL;
        }
        x->n_name = atom_getsym(av);
        
        // casting x to t_codableobj* is a ugly hack
        // but it should work
        // and help to keep things simple
        x->n_var = new astGlobalVar(bach->b_gvt, x->n_name, (t_codableobj *) x);

        attr_args_process(x, ac, av);
        llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
        if (true_ac > 1)
            value_anything(x, NULL, true_ac - 1, av + 1);
    } else
        object_bug((t_object *) x, "Memory allocation error: couldn't create bach.value");
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

