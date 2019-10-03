/*
 *  partition.c
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
    partition.c
    
    @name
    bach.partition
    
    @realname
    bach.partition
 
    @type
    object
    
    @module
    bach
 
    @author
    bachproject
    
    @digest
    Compute integer or set partitions
    
    @description
    Computes the integer partition of the incoming non-negative number or the partition of the incoming set
    
    @discussion
    Integer partition are often displayed in Young diagrams.
    The integer partition algorithm is inspired by the iterative algorithm exposed in
    http://jeromekelleher.net/generating-integer-partitions.html
    
    @category
    bach, bach abstractions, bach math
 
    @keywords
    compute, calculate, partition, number, young, diagram, set, subset
    
    @seealso
    bach.fact, bach.prod
    
    @owner
    Daniele Ghisi
 */


#include "foundation/llllobj.h"
#include "foundation/llll_commons_ext.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "math/bach_math_utilities.h"


typedef struct _partition
{
    t_llllobj_object     n_ob;
    char                n_mode; // if non-zero, it's in set mode, otherwise it's in integer mode
    char                n_distinct; //  only return distinct set partitions
} t_partition;




void partition_assist(t_partition *x, void *b, long m, long a, char *s);
void partition_inletinfo(t_partition *x, void *b, long a, char *t);

t_partition *partition_new(t_symbol *s, short ac, t_atom *av);
void partition_free(t_partition *x);

void partition_int(t_partition *x, t_atom_long v);
void partition_float(t_partition *x, double v);
void partition_bang(t_partition *x);
void partition_anything(t_partition *x, t_symbol *msg, long ac, t_atom *av);

t_class *partition_class;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.partition", (method)partition_new, (method)partition_free, (long) sizeof(t_partition), 0L, A_GIMME, 0);
    
    // @method llll @digest Set set, output result
    // @description If the <m>mode</m> attribute is set to 1 (set), any <m>llll</m> in the second inlet is considered as the set to be partitioned.
    // Partitions are then output from the outlet, each wrapped in a level of parenthesis.
    class_addmethod(c, (method)partition_anything,    "anything",        A_GIMME,    0);
    
    // @method int @digest Set number, output result
    // @description If the <m>mode</m> attribute is set to 0 (integer), An integer number will trigger the computation of its integer partitions
    // which are subsequently output through the outlet, each wrapped in a level of parentheses,
    // and in decreasing lexicographical order.
    class_addmethod(c, (method)partition_int,            "int",            A_LONG,        0);
    class_addmethod(c, (method)partition_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)partition_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Output last obtained result
    // @description Outputs the result obtained from the most recently received input data.
    class_addmethod(c, (method)partition_bang,    "bang",    0);
    
    class_addmethod(c, (method)partition_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)partition_inletinfo,    "inletinfo",    A_CANT,        0);

    CLASS_ATTR_CHAR(c, "mode", 0, t_partition, n_mode);
    CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
    CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Integers Sets");
    CLASS_ATTR_BASIC(c,"mode",0);
    // @description If <m>mode</m> is 0, the partition is performed on integers; if <m>mode</m> is 1 the partition is performed on sets.

    CLASS_ATTR_CHAR(c, "distinct", 0, t_partition, n_distinct);
    CLASS_ATTR_STYLE_LABEL(c,"distinct",0,"onoff","Output Distinct Partitions Only");
    // @description If <m>mode</m> is 1 (Sets), this attribute toggles the ability to only output distinct partitions of a set (in case
    // some elements are repeated inside the set).

    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    

    class_register(CLASS_BOX, c);
    partition_class = c;
    
    dev_post("bach.partition compiled %s %s", __DATE__, __TIME__);
    
    return;
}

void partition_int(t_partition *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    partition_anything(x, _sym_int, 1, &outatom);
}

void partition_float(t_partition *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    partition_anything(x, _sym_float, 1, &outatom);
}


void partition_bang(t_partition *x)
{
    partition_anything(x, _sym_bang, 0, NULL);
}

t_llll *long_array_to_llll(long *array, long size)
{
    t_llll *out = llll_get();
    for (long i = 0; i < size; i++)
        llll_appendlong(out, array[i]);
    return out;
}

t_llll *get_integer_partitions(long n)
{
    if (n == 0)
        return llll_get();
    
    long *a = (long *)bach_newptrclear((n+1) * sizeof(long));
    long k = 1;
    long x, y;
    t_llll *out = llll_get();
    a[1] = n;
    while (k != 0) {
        x = a[k-1] + 1;
        y = a[k] - 1;
        k -= 1;
        while (x <= y) {
            a[k] = x;
            y -= x;
            k += 1;
        }
        a[k] = x + y;
        llll_appendllll(out, long_array_to_llll(a, k+1));
    }
    llll_rev(out, 1, 2);
    return out;
}

// recursive algorithm
t_llll *get_set_partitions(t_llll *set, char distinct_only)
{
    t_llll *out = llll_get();
    
    if (set->l_size == 0)
        return out;
    
    if (set->l_size == 1) {
        t_llll *temp = llll_clone(set);
        llll_wrap(&temp);
        llll_appendllll(out, temp);
        return out;
    }
    
    t_llll *setclone = llll_clone(set);
    t_hatom *first = &set->l_head->l_hatom;
    llll_behead(setclone);
    t_llll *cdr_partitions = get_set_partitions(setclone, distinct_only); // e.g. {{1, 2, 3};   {2, 3} {1};  {1, 3} {2};  {3} {1, 2};  {3} {2} {1}}
    for (t_llllelem *elem = cdr_partitions->l_head; elem; elem = elem->l_next) { //{{2}}
        t_llll *smaller = hatom_getllll(&elem->l_hatom); // e.g. {1, 3} {2}
        for (long i = 1; i <= smaller->l_size; i++) {
            t_llll *smaller_modif = llll_clone(smaller);
            t_llllelem *smaller_subllelem = llll_getindex(smaller_modif, i, I_STANDARD);
            t_llll *smaller_subll = hatom_getllll(&smaller_subllelem->l_hatom);
            llll_prependhatom_clone(smaller_subll, first);
            llll_prependllll(out, smaller_modif);
        }
        
        t_llll *ownll = llll_clone(smaller);
        t_llll *ownll_head = llll_get();
        llll_appendhatom_clone(ownll_head, first);
        llll_prependllll(ownll, ownll_head);
        llll_prependllll(out, ownll);
    }
    llll_free(setclone);
    llll_free(cdr_partitions);
    
    if (distinct_only)
        out = llll_thin_simple(out, false);
    
    llll_rev(out, 1, 1);
    return out;
}


void partition_anything(t_partition *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *ll;
    char mode = x->n_mode;
    char distinct = x->n_distinct;
    t_llll *out = NULL;
    
    if (msg != _sym_bang)
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);

    ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
    
    if (mode == 0) {
        if (ll && ll->l_head && is_hatom_number(&ll->l_head->l_hatom)) {
            long num = hatom_getlong(&ll->l_head->l_hatom);
            if (num < 0) {
                object_error((t_object *)x, "Incoming number must be non-negative!");
            } else {
                out = get_integer_partitions(num);
            }
        }
    } else {
        if (ll)
            out = get_set_partitions(ll, distinct);
    }
    
    if (out)
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
    llll_free(out);
    llll_free(ll);
}

void partition_assist(t_partition *x, void *b, long m, long a, char *s)
{    
    if (m == ASSIST_INLET) {
        sprintf(s, "number/llll: Number or Set to be partitioned"); // @in 0 @type number/llll @digest The number or set to be partitioned
                                                                    // @description First inlet accepts a number or a set (llll) to be partitioned,
                                                                    // depending on the value of the <m>mode</m> attribute
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "number/symbol: Converted Number"); // @out 0 @type llll @digest Partitions of the number or set
    }
}

void partition_inletinfo(t_partition *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void partition_free(t_partition *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_partition *partition_new(t_symbol *s, short ac, t_atom *av)
{
    t_partition *x = NULL;
    t_max_err err = 0;
    
    
    if ((x = (t_partition *) object_alloc_debug(partition_class))) {
        x->n_mode = 0;
        attr_args_process(x, ac, av);
        llllobj_obj_setup((t_llllobj_object *) x, 3, "4");
    } else
        error(BACH_CANT_INSTANTIATE);        
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
