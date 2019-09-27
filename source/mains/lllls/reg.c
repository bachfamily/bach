/*
 *  reg.c
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
 reg.c
 
 @name 
 bach.reg
 
 @realname 
 bach.reg
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Store an llll
 
 @description
 Stores an llll to be retrieved with a bang.
 
 @discussion
 If the <m>embed</m> attribute is set to 1, the llll is saved with the patcher.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 store, output

 @seealso
 bach.write, bach.shelf, bach.value, bach.pv, bach.portal
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

//#define parsertests

typedef struct _reg
{
    struct llllobj_object     n_ob;
    void                    *n_proxy;
    long                    n_embed;
    long                    n_in;
    
    t_object                *m_editor;
} t_reg;

//DEFINE_LLLL_ATTR_DEFAULT_GETTER_AND_SETTER(t_reg, dummy, reg_getattr_dummy, reg_setattr_dummy)

void reg_assist(t_reg *x, void *b, long m, long a, char *s);
void reg_inletinfo(t_reg *x, void *b, long a, char *t);
void reg_appendtodictionary(t_reg *x, t_dictionary *d);

t_reg *reg_new(t_symbol *s, short ac, t_atom *av);
void reg_free(t_reg *x);

void reg_bang(t_reg *x);
void reg_int(t_reg *x, t_atom_long v);
void reg_float(t_reg *x, double v);
void reg_anything(t_reg *x, t_symbol *msg, long ac, t_atom *av);


// editor
void reg_okclose(t_reg *x, char *s, short *result);
void reg_edclose(t_reg *x, char **ht, long size);
void reg_dblclick(t_reg *x);


t_class *reg_class;


void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.reg", (method)reg_new, (method)reg_free, (short)sizeof(t_reg), 0L, A_GIMME, 0);

    // @method llll @digest Store the llll
    // @description In left inlet: the llll is stored and output. <br />
    // In right inlet: the llll is stored.
    class_addmethod(c, (method)reg_anything,    "anything",        A_GIMME,    0);
    
    class_addmethod(c, (method)reg_int,            "int",            A_LONG,        0);
    class_addmethod(c, (method)reg_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)reg_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Output the llll
    // @description A bang in the left inlet outputs the stored llll.
    class_addmethod(c, (method)reg_bang,        "bang",            0);
    class_addmethod(c, (method)reg_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)reg_inletinfo,    "inletinfo",    A_CANT,        0);
    class_addmethod(c, (method)reg_appendtodictionary,    "appendtodictionary", A_CANT, 0);

    
    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)reg_dblclick,        "dblclick",        A_CANT, 0);
    class_addmethod(c, (method)reg_edclose,         "edclose",        A_CANT, 0);
    class_addmethod(c, (method)reg_okclose,         "okclose",      A_CANT, 0);
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    
    CLASS_ATTR_LONG(c, "embed",    0,    t_reg, n_embed);
    CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
    CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
    CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
    CLASS_ATTR_SAVE(c, "embed", 0);
    CLASS_ATTR_BASIC(c, "embed", 0);
    // @description When set to 1, the stored llll is saved with the patcher
    // and will be available, to be retrieved with a bang, next time the patch is loaded.
    
    class_register(CLASS_BOX, c);
    
    reg_class = c;
    
    dev_post("bach.reg compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void reg_dblclick(t_reg *x)
{
    if (!x->m_editor)
        x->m_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->m_editor, gensym("visible"), 1);
    
    char *buf = NULL;
    t_llll *ll = llllobj_get_store_contents((t_object *)x, LLLL_OBJ_VANILLA, 0, 0);
    llll_to_text_buf_pretty(ll, &buf, 0, BACH_DEFAULT_MAXDECIMALS, BACH_DEFAULT_EDITOR_LLLL_WRAP, "\t", -1, LLLL_T_NULL, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
    void *rv = object_method(x->m_editor, _sym_settext, buf, gensym("utf-8")); // non-0 if the text was too long
    if (rv) {
        t_object *ed = x->m_editor;
        x->m_editor = NULL;
        object_free(ed);
    } else
        object_attr_setsym(x->m_editor, gensym("title"), gensym("llll"));
    llll_release(ll);
}

void reg_okclose(t_reg *x, char *s, short *result)
{
    *result = 3;
}

void reg_edclose(t_reg *x, char **ht, long size)
{
    // do something with the text
    if (!x->m_editor) // which means that something was wrong
        return;
    if (ht) {
        t_llll *ll = llll_from_text_buf(*ht, size > MAX_SYM_LENGTH);
        if (ll) {
            llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
            llll_retain(ll);
            llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
        } else
            object_error((t_object *)x, "Can't modify llll: it is wrongly formatted.");
    }
    x->m_editor = NULL;
}

void reg_bang(t_reg *x)
{
    if (proxy_getinlet((t_object *) x) == 0)
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void reg_int(t_reg *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    reg_anything(x, _sym_int, 1, &outatom);
}

void reg_float(t_reg *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    reg_anything(x, _sym_float, 1, &outatom);
}

void reg_anything(t_reg *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *in_llll;
    
    in_llll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
    if (!in_llll)
        return;
    
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, in_llll, 0);

    if (proxy_getinlet((t_object *) x) == 0)
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void reg_assist(t_reg *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a == 0)    sprintf(s, "llll to Store and Output / bang"); // @in 0 @type llll/bang @digest Store and output llll
        // @description An llll is stored and output, a bang outputs the stored llll.
        else sprintf(s, "llll to Store");
        // @in 1 @type llll @digest llll to store
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Stored llll
    }
}

void reg_inletinfo(t_reg *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void reg_appendtodictionary(t_reg *x, t_dictionary *d)
{
    if (x->n_embed) {
        llll_store_in_dictionary(x->n_ob.l_incache[0].s_ll, d, "reg_data", &x->n_ob.l_incache[0].s_lock);
    }
}

void reg_free(t_reg *x)
{
    object_free_debug(x->n_proxy);
    object_free_debug(x->m_editor);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_reg *reg_new(t_symbol *s, short ac, t_atom *av)
{
    t_reg *x = NULL;
    t_max_err err = MAX_ERR_NONE;
    t_llll *def_llll;
    t_dictionary *d;
    
    if ((x = (t_reg *) object_alloc_debug(reg_class))) {
        
        x->m_editor = NULL;

        // @arg 0 @name default @optional 1 @type llll @digest Default llll
        // @description An optional default llll. 
        // If an llll has been saved with the patcher through the <m>embed</m> attribute,
        // it will override the argument llll.
        t_atom_long true_ac = attr_args_offset(ac, av);
        attr_args_process(x, ac, av);
        llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
        if (true_ac) {
            def_llll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac, av, 0);
            if (def_llll)
                llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, def_llll, 0);
        }
        
        x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);

        d = (t_dictionary *)gensym("#D")->s_thing;
        if (d) {
            def_llll = llll_retrieve_from_dictionary(d, "reg_data");
            if (def_llll) {
                llll_retain(def_llll);
                llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, def_llll, 0);
                llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, def_llll, 0);
                x->n_embed = 1;
            }
        }
    }
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    
    if (x && err == MAX_ERR_NONE)
        return x;

    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
