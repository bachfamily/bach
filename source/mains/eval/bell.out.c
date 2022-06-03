/*
 *  bell.out.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _bell_out
{
    t_llllobj_object    n_ob;
    long                n_proxies;
    void                **n_proxy;
    long                n_in;
} t_bell_out;

t_bell_out *bell_out_new(t_symbol *s, short ac, t_atom *av);
void bell_out_free(t_bell_out *x);

void bell_out_bang(t_bell_out *x);
void bell_out_int(t_bell_out *x, t_atom_long v);
void bell_out_float(t_bell_out *x, double v);
void bell_out_anything(t_bell_out *x, t_symbol *msg, long ac, t_atom *av);

void *bell_out_fetch(t_bell_out *x, t_llll *which, t_object *culprit);

t_class *bell_out_class;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.bell.out", (method)bell_out_new, (method)bell_out_free, (long) sizeof(t_bell_out), 0L, A_GIMME, 0);

    class_addmethod(c, (method)bell_out_anything,        "anything",        A_GIMME,    0);
    
    class_addmethod(c, (method)bell_out_int,            "int",            A_LONG,        0);
    class_addmethod(c, (method)bell_out_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)bell_out_anything,        "list",            A_GIMME,    0);

    class_addmethod(c, (method)bell_out_bang,            "bang",            0);
    
    class_addmethod(c, (method)bell_out_fetch,    "fetch",    A_CANT,        0);
    
    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA); // every object with llll outlets must call this function in its main() function
  
    
    class_register(CLASS_BOX, c);
    bell_out_class = c;
    
    dev_post("bach.bell.out compiled %s %s", __DATE__, __TIME__);
    
    return;
}


void bell_out_bang(t_bell_out *x)
{
    bell_out_anything(x, _sym_bang, 0, nullptr);
}

void bell_out_int(t_bell_out *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    bell_out_anything(x, _sym_int, 1, &outatom);
}

void bell_out_float(t_bell_out *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    bell_out_anything(x, _sym_float, 1, &outatom);
}

void bell_out_anything(t_bell_out *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
}

void* bell_out_fetch(t_bell_out *x, t_llll *which, t_object *culprit)
{
    t_llll *outll = llll_get();

    if (!which || which->l_size == 0) {
        for (int i = 0; i <= x->n_proxies; i++) {
            t_llll *ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 1);
            llll_chain(outll, ll);
        }
    } else {
        t_llllelem *inelem = which->l_head;
        t_llll_stack *instack = llll_stack_new();
        while (1) {
            while (inelem) {
                long type = hatom_gettype(&inelem->l_hatom);
                if (type == H_LLLL) {
                    t_llll *subll = llll_get();
                    llll_appendllll(outll, subll);
                    outll = subll;
                    which = hatom_getllll(&inelem->l_hatom);
                    llll_stack_push(instack, inelem->l_next);
                    inelem = which->l_head;
                } else {
                    int n = hatom_getlong(&inelem->l_hatom) - 1;
                    if (n >= 0 && n <= x->n_proxies) {
                        t_llll *ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, n, 1);
                        llll_chain(outll, ll);
                    } else {
                        object_error(culprit, "fetch: bad index");
                    }
                    inelem = inelem->l_next;
                }
            }
            if (!which->l_owner)
                break;
            which = which->l_owner->l_parent;
            outll = outll->l_owner->l_parent;
            inelem = (t_llllelem *) llll_stack_pop(instack);
        }
        /*
        for (t_llllelem *el = which->l_head; el; el = el->l_next) {
            int n = hatom_getlong(&el->l_hatom) - 1;
            if (n >= 0 && n <= x->n_proxies) {
                t_llll *ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, n, 1);
                llll_appendllll(out, ll);
            } else {
                object_error(culprit, "fetch: bad index");
            }
        }
         */
    }
    llllobj_clear_all_stores((t_object *) x, LLLL_OBJ_VANILLA);
    return outll;
}

void bell_out_free(t_bell_out *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_bell_out *bell_out_new(t_symbol *s, short ac, t_atom *av)
{
    t_bell_out *x = NULL;
    long i, inlets = 0;
    t_max_err err = 0;
    long true_ac;
        
    if ((x = (t_bell_out *) object_alloc_debug(bell_out_class))) {

        inlets = atom_getlong(av);
        attr_args_process(x, ac, av);
        
        llllobj_obj_setup((t_llllobj_object *) x, inlets, "");
        x->n_proxies = inlets - 1;
        
        x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
