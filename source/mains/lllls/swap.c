/*
 *  swap.c
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
 swap.c
 
 @name
 bach.swap
 
 @realname
 bach.swap
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Swap elements in an llll
 
 @description
 Swaps two elements of an llll.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 swap, element, address, permutation
 
 @seealso
 bach.subs, bach.replace, bach.find, bach.nth, bach.perm
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _swap
{
    t_llllobj_object	n_ob;
    void				*n_proxy[4];
    long				n_in;
} t_swap;

void swap_assist(t_swap *x, void *b, long m, long a, char *s);
void swap_inletinfo(t_swap *x, void *b, long a, char *t);

t_swap *swap_new(t_symbol *s, short ac, t_atom *av);
void swap_free(t_swap *x);

void swap_bang(t_swap *x);
void swap_int(t_swap *x, t_atom_long v);
void swap_float(t_swap *x, double v);
void swap_anything(t_swap *x, t_symbol *msg, long ac, t_atom *av);

t_max_err swap_setattr_set(t_swap *x, t_object *attr, long ac, t_atom *av);

t_class *swap_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.swap", (method)swap_new, (method)swap_free, (short)sizeof(t_swap), 0L, A_GIMME, 0);
    
    // @method llll @digest Function depends on inlet
    // @description
    // In first inlet: the elements at the addresses set through the second and third inlets
    // (or as <o>bach.swap</o>'s argument) are swapped. <br/>
    // In second and third inlets: the addresses of the two elements to be swapped.
    class_addmethod(c, (method)swap_anything,		"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)swap_int,			"int",			A_LONG,		0);
    class_addmethod(c, (method)swap_float,          "float",		A_FLOAT,	0);
    class_addmethod(c, (method)swap_anything,		"list",			A_GIMME,	0);
    
    // @method bang @digest Perform last operation
    // @description Perform the swap with the most recently received data.
    class_addmethod(c, (method)swap_bang,			"bang",			0);
    
    class_addmethod(c, (method)swap_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)swap_inletinfo,	"inletinfo",	A_CANT,		0);
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    
    class_register(CLASS_BOX, c);
    swap_class = c;
    
    dev_post("bach.swap compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void swap_bang(t_swap *x)
{
    if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
        swap_anything(x, _sym_bang, 0, NULL);
    else
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void swap_int(t_swap *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    swap_anything(x, _sym_int, 1, &outatom);
}

void swap_float(t_swap *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    swap_anything(x, _sym_float, 1, &outatom);
}

void swap_anything(t_swap *x, t_symbol *msg, long ac, t_atom *av)
{
    long proxy = proxy_getinlet((t_object *) x);
    
    if (proxy == 0) {
        t_llll *ll, *addr1, *addr2;
        t_llllelem *el1, *el2;
        t_max_err err;
        if (msg != _sym_bang) {
            ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
            if (!ll)
                return;
        } else
            ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
        addr1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
        addr2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 2, 0);
        if (addr1->l_size == 0 || addr2->l_size == 0) {
            object_error((t_object *) x, "Missing address");
            llll_release(addr1);
            llll_release(addr2);
            llll_free(ll);
            return;
        }

        el1 = llll_nth_one(ll, addr1);
        el2 = llll_nth_one(ll, addr2);
        err = llll_swapelems(el1, el2);
        if (err == MAX_ERR_NONE) {
            llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
            x->n_ob.l_rebuild = false;
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
        } else {
            llll_free(ll);
            object_error((t_object *) x, "Bad address");
        }

        llll_release(addr1);
        llll_release(addr2);
    } else {
        llllobj_parse_and_store_llll_address((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, proxy, false, false);
    }
}

void swap_assist(t_swap *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        switch (a) {
            case 0: sprintf(s, "Original llll");    break;  // @in 0 @type llll @digest Original llll
            case 1: sprintf(s, "1st address");      break;  // @in 1 @type llll @digest Address of the first element to be swapped
            case 2: sprintf(s, "2nd address");      break;  // @in 2 @type llll @digest Address of the second element to be swapped
        }
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest llll with the two elements swaped
    }
}

void swap_inletinfo(t_swap *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void swap_free(t_swap *x)
{
    long i;
    for (i = 2; i > 0; i--)
        object_free_debug(x->n_proxy[i]);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_swap *swap_new(t_symbol *s, short ac, t_atom *av)
{
    t_swap *x = NULL;
    long i;
    long true_ac;
    t_max_err err = 0;
    
    true_ac = attr_args_offset(ac, av);
    
    if ((x = (t_swap *) object_alloc_debug(swap_class))) {
        // @arg 0 @name addresses @optional 1 @type llll @digest Initial addresses
        // @description The initial addresses to be swapped,
        // as either two address sublists, or two integers.
        // In the latter case, they represent two addresses at the root level
        long true_ac = attr_args_offset(ac, av);
        for (i = 2; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        attr_args_process(x, ac, av);
        llllobj_obj_setup((t_llllobj_object *) x, 3, "4");
        if (true_ac) {
            t_llll *def_llll = llll_parse(true_ac, av);
            //_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, _sym_list, true_ac, av, 0);
            if (def_llll) {
                if (def_llll->l_depth == 1 && def_llll->l_size == 2) {
                    long l1 = hatom_getlong(&def_llll->l_head->l_hatom);
                    long l2 = hatom_getlong(&def_llll->l_tail->l_hatom);
                    if (l1 == 0 || l2 == 0) {
                        object_error((t_object *) x, "Bad address llll");
                    } else {
                        t_llll *addr1 = llll_get();
                        llll_appendlong(addr1, l1);
                        llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, addr1, 1);
                        t_llll *addr2 = llll_get();
                        llll_appendlong(addr2, l2);
                        llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, addr2, 2);
                    }
                } else if (def_llll->l_depth == 2 && def_llll->l_size == 2) {
                    t_llll *ll1 = hatom_getllll(&def_llll->l_head->l_hatom);
                    t_llll *ll2 = hatom_getllll(&def_llll->l_tail->l_hatom);
                    t_llllelem *elem;
                    t_bool good = true;
                    for (elem = ll1->l_head; good && elem; elem = elem->l_next) {
                        if (hatom_getlong(&elem->l_hatom) == 0)
                            good = false;
                    }
                    for (elem = ll2->l_head; good && elem; elem = elem->l_next) {
                        if (hatom_getlong(&elem->l_hatom) == 0)
                            good = false;
                    }
                    if (good) {
                        t_llll *cloned;
                        cloned = llll_clone(ll1);
                        llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, cloned, 1);
                        cloned = llll_clone(ll2);
                        llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, cloned, 2);
                    } else {
                        object_error((t_object *) x, "Bad address llll");
                    }
                } else {
                    object_error((t_object *) x, "Bad address llll");
                }
                llll_free(def_llll);
            }
        }
    } else 
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
