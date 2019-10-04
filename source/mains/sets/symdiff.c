/*
 *  symdiff.c
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
 symdiff.c
 
 @name 
 bach.symdiff
 
 @realname 
 bach.symdiff
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Symmetric difference of two sets
 
 @description
 Returns the symmetric difference of two lllls.

 @discussion
 If either or both lllls contain repeated elements, the behavior is undefined.
 A custom equality check can be provided through the lambda loop. <br />
 @copy BACH_DOC_LAMBDA
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 set, symmetric difference, difference

 @seealso
 bach.union, bach.diff, bach.intersection
 
 @owner
 Andrea Agostini
 */

#include "bell/bach_codableobj.hpp"
#include "bell/ast.hpp"

typedef struct _symdiff
{
    t_codableobj     n_ob;
    void            *n_proxy[3];
    long            n_in;
    long            n_result;
    long            n_haslambda;
    t_llll            *n_empty;
} t_symdiff;

typedef struct _lambdaData
{
    t_symdiff *x;
    t_execEnv *context;
} t_lambdaData;

void symdiff_assist(t_symdiff *x, void *b, long m, long a, char *s);
void symdiff_inletinfo(t_symdiff *x, void *b, long a, char *t);

t_symdiff *symdiff_new(t_symbol *s, short ac, t_atom *av);
void symdiff_free(t_symdiff *x);

void symdiff_bang(t_symdiff *x);
void symdiff_int(t_symdiff *x, t_atom_long v);
void symdiff_float(t_symdiff *x, double v);
void symdiff_anything(t_symdiff *x, t_symbol *msg, long ac, t_atom *av);

long symdiff_func(t_symdiff *x, t_llllelem *what1, t_llllelem *what2);

long symdiff_code(t_lambdaData *data, t_llllelem *what1, t_llllelem *what2);

t_class *symdiff_class;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.symdiff", (method)symdiff_new, (method)symdiff_free, (long) sizeof(t_symdiff), 0L, A_GIMME, 0);
    
    codableclass_add_standard_methods_and_attrs(c);
    codableclass_add_extended_methods_and_attrs(c);

    // @method llll @digest Store data and compute symmetric difference
    // @description
    // In first inlet: the symmetric difference between the llll and the llll is computed and the result is output.
    // In second inlet: the llll is stored, its difference with an llll received in the left inlet to be computed.
    // In third inlet: the llll is converted into an int
    class_addmethod(c, (method)symdiff_anything,    "anything",        A_GIMME,    0);
    class_addmethod(c, (method)symdiff_int,            "int",            A_LONG,        0);
    class_addmethod(c, (method)symdiff_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)symdiff_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Perform the last operation
    // @description Return the symmetric difference of the most recently received lllls. 
    class_addmethod(c, (method)symdiff_bang,        "bang",            0);

    class_addmethod(c, (method)symdiff_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)symdiff_inletinfo,    "inletinfo",    A_CANT,        0);
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

    class_register(CLASS_BOX, c);
    symdiff_class = c;
    
    dev_post("bach.symdiff compiled %s %s", __DATE__, __TIME__);
    
    return;
}

void symdiff_bang(t_symdiff *x)
{    
    if (x->n_ob.c_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
        symdiff_anything(x, _sym_bang, 0, NULL);
    else
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void symdiff_int(t_symdiff *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    symdiff_anything(x, _sym_int, 1, &outatom);
}

void symdiff_float(t_symdiff *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    symdiff_anything(x, _sym_float, 1, &outatom);
}


#ifdef ___destructive
void symdiff_anything(t_symdiff *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *inll1, *inll2;
    long inlet = proxy_getinlet((t_object *) x);
    x->n_result = 0;
    
    switch (inlet) {
        case 0:
            if (msg != _sym_bang) {
                inll1 = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
                if (!inll1)
                    return;
            } else
                inll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
            inll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
            if (x->n_ob.c_main) {
                t_execEnv lambdaContext((t_llllobj_object *) x, x->n_ob.c_main);
                lambdaContext.argc = 2;
                t_lambdaData lambdaData = {
                    x,
                    &lambdaContext
                };
                llll_symdiff(inll1, inll2, (sets_fn) symdiff_code, &lambdaData);
            } else {
                x->n_haslambda = 0;
                if (inll1->l_size && inll2->l_size)
                    llllobj_test_lambda_loop_two_outs((t_object *) x, LLLL_OBJ_VANILLA, inll1->l_head, inll2->l_head, 1, 2);
                
                if (x->n_haslambda) {
                    llll_symdiff(inll1, inll2, (sets_fn) symdiff_func, x);
                } else
                    llll_symdiff(inll1, inll2);
            }
            llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, inll1, 0);
            x->n_ob.c_ob.l_rebuild = 0;
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
            break;
        case 1:
            x->n_ob.c_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet) != NULL;
            break;
        case 2:
            if (msg == LLLL_NATIVE_MSG) {
                t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
                if (lambda_llll) {
                    if (lambda_llll->l_size)
                        x->n_result = hatom_getlong(&lambda_llll->l_head->l_hatom);
                    else
                        x->n_result = 0;
                    llll_free(lambda_llll);
                } else
                    x->n_result = 0;
            } else
                x->n_result = ac ? atom_getlong(av) : 0;
            x->n_haslambda = 1;
        break;    
    }
}
#else

void symdiff_anything(t_symdiff *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *inll1, *inll2, *outll;
    long inlet = proxy_getinlet((t_object *) x);
    x->n_result = 0;
    
    switch (inlet) {
        case 0:
            if (msg != _sym_bang) {
                inll1 = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
                if (!inll1)
                    return;
            } else
                inll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
            inll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
            
            x->n_haslambda = 0;
            if (inll1->l_size && inll2->l_size)
                llllobj_test_lambda_loop_two_outs((t_object *) x, LLLL_OBJ_VANILLA, inll1->l_head, inll2->l_head, 1, 2);
            
            if (x->n_haslambda) {
                outll = llll_symdiff(inll1, inll2, (sets_fn) symdiff_func, x);
            } else
                outll = llll_symdiff_simple(inll1, inll2);
            
            llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, outll, 0);
            x->n_ob.l_rebuild = 0;
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
            break;
        case 1:
            x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet) != NULL;
            break;
        case 2:
            if (msg == LLLL_NATIVE_MSG) {
                t_llll *lambda_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
                if (lambda_llll) {
                    if (lambda_llll->l_size)
                        x->n_result = hatom_getlong(&lambda_llll->l_head->l_hatom);
                    else
                        x->n_result = 0;
                    llll_free(lambda_llll);
                } else
                    x->n_result = 0;
            } else
                x->n_result = ac ? atom_getlong(av) : 0;
            x->n_haslambda = 1;
            break;
    }
}
#endif

long symdiff_func(t_symdiff *x, t_llllelem *what1, t_llllelem *what2)
{
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 2, what2->l_thing.w_llll);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, what1->l_thing.w_llll);
    return x->n_result;
}

long symdiff_code(t_lambdaData *data, t_llllelem *what1, t_llllelem *what2)
{
    t_execEnv *context = data->context;
    context->argv[1] = what1->l_thing.w_llll;
    context->argv[2] = what2->l_thing.w_llll;
    context->resetLocalVariables();
    t_llll *resll = codableobj_run((t_codableobj *) data->x, *context);
    long r = llll_istrue(resll);
    llll_free(resll);
    return r;
}

void symdiff_assist(t_symdiff *x, void *b, long m, long a, char *s)
{    
    if (m == ASSIST_INLET) {
        switch (a) {
            case 0:    sprintf(s, "llll 1");    break; // @in 0 @type llll @digest llll to compute the symmetric difference of
            case 1: sprintf(s, "llll 2");    break; // @in 1 @type llll @digest llll to compute the symmetric difference of
            case 2: sprintf(s, "llll: Lambda Input");    break; // @in 3 @type int/llll @digest Lambda inlet 
                // @description @copy BACH_DOC_LAMBDA_INLET_EQUALITY
        }
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        switch (a) {
            case 0:    sprintf(s, "llll (%s): Symmetric Difference", type);    break; // @out 0 @type llll @digest Result of the symmetric difference
            case 1:    sprintf(s, "llll (%s): Lambda Outlet 1", type);            break; // @out 1 @type llll @digest First lambda outlet 
                // @description @copy BACH_DOC_LAMBDA_OUTLET_EQUALITY
            case 2:    sprintf(s, "llll (%s): Lambda Outlet 2", type);            break; // @out 2 @type llll @digest Seconnd lambda outlet 
                // @description @copy BACH_DOC_LAMBDA_OUTLET_EQUALITY
        }
    }
}

void symdiff_inletinfo(t_symdiff *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void symdiff_free(t_symdiff *x)
{
    long i;
    for (i = 2; i > 0; i--)
        object_free_debug(x->n_proxy[i]);
    llll_free(x->n_empty);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_symdiff *symdiff_new(t_symbol *s, short ac, t_atom *av)
{
    t_symdiff *x = NULL;
    long i;
    t_max_err err = MAX_ERR_NONE;    
    
    if ((x = (t_symdiff *) object_alloc_debug(symdiff_class))) {
        if (codableobj_setup((t_codableobj *) x, ac, av) < 0) {
            object_free_debug(x);
            return nullptr;
        }
        llllobj_obj_setup((t_llllobj_object *) x, 2, "444");
        for (i = 2; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        x->n_empty = llll_get();
        
        codableobj_finalize((t_codableobj *) x);


    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
