/*
 *  pv.c
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

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

#include "bell/pvManager.hpp"

typedef struct _pv
{
	t_llllobj_object    n_ob;
	t_symbol		    *n_name;
    
    t_patcherVariable   *n_var;
    long                n_auto[2];
    t_object            *m_editor;
} t_pv;


void pv_assist(t_pv *x, void *b, long m, long a, char *s);
void pv_inletinfo(t_pv *x, void *b, long a, char *t);

t_pv *pv_new(t_symbol *s, short ac, t_atom *av);
void pv_free(t_pv *x);


void pv_bang(t_pv *x);
void pv_triggerfromclient(t_pv *x, long dummy);
void pv_int(t_pv *x, t_atom_long v);
void pv_float(t_pv *x, double v);
void pv_anything(t_pv *x, t_symbol *msg, long ac, t_atom *av);

// editor
void pv_okclose(t_pv *x, char *s, short *result);
void pv_edclose(t_pv *x, char **ht, long size);
void pv_dblclick(t_pv *x);

void pv_setpatchervariable(t_pv *x, t_symbol *name, t_patcherVariable *var);

void pv_init_do(t_pv *x, t_symbol *name, short ac, t_atom *av);

t_max_err pv_setattr_auto(t_pv *x, t_object *attr, long ac, t_atom *av);

t_class *pv_class;

extern t_bach* bach;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.pv", (method) pv_new, (method) pv_free, (short) sizeof(t_pv), 0L, A_GIMME, 0);
	
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
    class_addmethod(c, (method)pv_triggerfromclient,     "triggerfromclient", A_CANT, 0);

	class_addmethod(c, (method)pv_assist,	"assist",		A_CANT,		0);
	
    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)pv_dblclick,         "dblclick",		A_CANT, 0);
    class_addmethod(c, (method)pv_edclose,         "edclose",		A_CANT, 0);
    class_addmethod(c, (method)pv_okclose,         "okclose",       A_CANT, 0);
    
    class_addmethod(c, (method)pv_setpatchervariable, "setpatchervariable", A_CANT, 0);

    CLASS_ATTR_LONG_ARRAY(c, "auto", 0, t_pv, n_auto, 2);
    CLASS_ATTR_ACCESSORS(c, "auto", NULL, pv_setattr_auto);
    CLASS_ATTR_LABEL(c, "auto", 0, "Automatically output llll");
    CLASS_ATTR_BASIC(c, "auto", 0);
    // @description When set to 1, the stored llll is automatically output
    // whenever it is set by another object of the same name and in the same hierarchy.<br/>
    // An optional second integer sets the priority (defaulting to 0):
    // the priority controls the order in which different bach.value objects
    // of the same name (and with the <b>auto</b> attribute switched on)
    // will automatically output the llll they receive.
    // The higher the priority, the earlier the object will fire.
    // The output order of objects with the same priority is undefined.
    
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	pv_class = c;
	
	dev_post("bach.pv compiled %s %s", __DATE__, __TIME__);
	
	return;
}


t_max_err pv_setattr_auto(t_pv *x, t_object *attr, long ac, t_atom *av)
{
    if (ac >= 1) {
        long val = atom_getlong(av);
        if (!x->n_var)
            return MAX_ERR_NONE;
        switch (val) {
            case 0: {
                bach->b_thePvManager->removeClient(x->n_name, (t_object *) x);
                x->n_auto[0] = 0;
                break;
            }
            default: {
                long const priority = ac >= 2 ? atom_getlong(av + 1) : 0;
                bach->b_thePvManager->addClient(x->n_name, (t_object *) x, priority);
                x->n_auto[0] = 1;
                x->n_auto[1] = priority;
                break;
            }
        }
    }
    return MAX_ERR_NONE;
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
            x->n_var->set(ll, (t_object *) x);
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

void pv_triggerfromclient(t_pv *x, long dummy)
{
    pv_bang(x);
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
    x->n_var->set(in_ll, (t_object *) x);
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
    if (x->n_var) {
        bach->b_thePvManager->removeVariable(x->n_name, (t_object*) x);
    }
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
        
        defer_low(x, (method) pv_init_do, name, ac, av);
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

void pv_init_do(t_pv *x, t_symbol *name, short ac, t_atom *av)
{
    // also calls the setpatchervariable method
    bach->b_thePvManager->getVariable(name, (t_object *) x);
    attr_args_process(x, ac, av);
    long true_ac = attr_args_offset(ac, av);
    if (true_ac > 1) {
        pv_anything(x, NULL, true_ac - 1, av + 1);
    }
}

