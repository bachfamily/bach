/*
 *  bell.in.c
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

typedef struct _bell_in
{
    struct llllobj_object    n_ob;

} t_bell_in;

t_bell_in *bell_in_new(t_symbol *s, short ac, t_atom *av);
void bell_in_free(t_bell_in *x);

void bell_in_pass(t_bell_in *x, long n, t_llll *ll);

t_class *bell_in_class;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.bell.in", (method)bell_in_new, (method)bell_in_free, (long) sizeof(t_bell_in), 0L, A_GIMME, 0);

    class_addmethod(c, (method)bell_in_pass, "pass", A_CANT, 0);
    
    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

    class_register(CLASS_BOX, c);
    bell_in_class = c;
    
    dev_post("bach.bell_in compiled %s %s", __DATE__, __TIME__);
    
    return;
}

void bell_in_pass(t_bell_in *x, long n, t_llll *ll)
{
    if (n < x->n_ob.l_numllllouts)
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, n, ll);
}

void bell_in_free(t_bell_in *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_bell_in *bell_in_new(t_symbol *s, short ac, t_atom *av)
{
    t_bell_in *x = NULL;
    t_max_err err = 0;
    long true_ac;
    char outlets[LLLL_MAX_OUTLETS];
    
    true_ac = attr_args_offset(ac, av);
    
    if ((x = (t_bell_in *) object_alloc_debug(bell_in_class))) {

        long nOutlets = atom_getlong(av);
        
        attr_args_process(x, ac, av);
        
        for (int i = 0; i < nOutlets; i++) {
            outlets[i] = '4';
        }
        outlets[nOutlets] = 0;
        llllobj_obj_setup((t_llllobj_object *) x, 0, outlets);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;

    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
