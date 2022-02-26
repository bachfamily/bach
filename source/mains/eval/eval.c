/*
 *  eval.c
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

/**
 @file
 eval.c
 
 @name
 bach.eval
 
 @realname
 bach.eval
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Evaluate advanced expressions
 
 @description
 Evaluates expressions with variables, branching, loops and user-defined functions.
 
 @discussion
 The syntax of <o>bach.code</o> is based upon <o>bach.expr</o>'s, but a full, Turing-complete programming language is implemented.
 
 @category
 bach, bach objects, bach llll, bach math
 
 @keywords
 expression, evaluate, variable, number, calculate, compute, function, code, if, branching

 @seealso
 expr, vexpr, bach.expr, bach.value, bach.pv
 
 @owner
 Andrea Agostini
 */

#include "bell/eval.h"
#include "bell/bach_codableobj.hpp"
#include "bell/ast.hpp"
#include "bell/pvManager.hpp"


void eval_assist(t_eval *x, void *b, long m, long a, char *s);
void eval_inletinfo(t_eval *x, void *b, long a, char *t);

t_eval *eval_new(t_symbol *s, short ac, t_atom *av);
void eval_free(t_eval *x);

void eval_bang(t_eval *x);
void eval_triggerfromclient(t_eval *x, long dummy);
void eval_run(t_eval *x, long inlet);

void eval_int(t_eval *x, t_atom_long v);
void eval_float(t_eval *x, double v);
void eval_anything(t_eval *x, t_symbol *msg, long ac, t_atom *av);
void eval_expr(t_eval *x, t_symbol *msg, long ac, t_atom *av);

void eval_deferbang(t_eval *x, t_symbol *msg, long ac, t_atom *av);
void eval_setready(t_eval *x, t_symbol *msg, long ac, t_atom *av);

void eval_inletinfo(t_eval *x, void *b, long a, char *t);
long eval_ishot(t_eval *x, long inlet);

// editor
void eval_dblclick(t_eval *x);

//void bifSetup();
void eval_ownedFunctionsSetup(t_eval *x);


DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_eval, n_triggers, eval_getattr_triggers);
t_max_err eval_setattr_triggers(t_eval *x, t_object *attr, long ac, t_atom *av);

t_max_err eval_check_triggers_llll(t_eval *x, t_llll *ll);


t_class *eval_class;


void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.eval", (method)eval_new, (method)eval_free, (long) sizeof(t_eval), 0L, A_GIMME, 0);
    
    codableclass_add_standard_methods_and_attrs(c);
    codableclass_add_extended_methods_and_attrs(c);

    // @method llll @digest Store values for the inlet variables
    // @description
    // The lllls provide the data to the expression.
    // An llll received in the leftmost inlet will trigger the evaluation and cause the result to be output.
    class_addmethod(c, (method)eval_anything,    "anything",        A_GIMME,    0);
    
    // @method expr @digest Expression to evaluate
    // @description
    // The <m>expr</m> message, followed by a valid expression, will set the new program to be evaluated by <o>bach.eval</o>.
    // For more details on the expression syntax, please refer to <o>bach.eval</o>'s help patcher.
    class_addmethod(c, (method)eval_expr,    "expr",            A_GIMME,    0);
    
    // @method bang @digest Perform the last operation
    // @description Return the result of the evaluation of the most recently received lllls and expression.
    class_addmethod(c, (method)eval_bang,        "bang",            0);
   
    class_addmethod(c, (method)eval_int,        "int",            A_LONG,        0);
    class_addmethod(c, (method)eval_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)eval_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Perform the last operation
    // @description Return the comparison result for the most recently received lllls.
    
    class_addmethod(c, (method)eval_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)eval_inletinfo,    "inletinfo",    A_CANT,        0);

    // @method (doubleclick) @digest Open text editor
    // @description Double-clicking on the object forces a text editor to open up, where the expression can be edited directly.
    class_addmethod(c, (method)eval_dblclick,        "dblclick",        A_CANT, 0);
    
    class_addmethod(c, (method)eval_triggerfromclient, "triggerfromclient", A_CANT, 0);

    CLASS_ATTR_ATOM_LONG(c, "inlets",    0,    t_eval, n_dataInlets);
    CLASS_ATTR_LABEL(c, "inlets", 0, "Number of Inlets");
    //CLASS_ATTR_ACCESSORS(c, "inlets", (method)NULL, (method)llllobj_dummy_setter)
    // @description Number of data inlets. <br />
    // @copy BACH_DOC_STATIC_ATTR

    CLASS_ATTR_ATOM_LONG(c, "extraoutlets",    0,    t_eval, n_dataOutlets);
    CLASS_ATTR_LABEL(c, "extraoutlets", 0, "Number of Extra Outlets");
    //CLASS_ATTR_ACCESSORS(c, "outlets", (method)NULL, (method)llllobj_dummy_setter)
    // @description Number of data outlets. <br />
    // @copy BACH_DOC_STATIC_ATTR

    CLASS_ATTR_ATOM_LONG(c, "directins",    0,    t_eval, n_directInlets);
    CLASS_ATTR_LABEL(c, "directins", 0, "Number of Direct Inlets");
    //CLASS_ATTR_ACCESSORS(c, "directins", (method)NULL, (method)llllobj_dummy_setter)
    // @description Number of direct inlets. <br />
    // @copy BACH_DOC_STATIC_ATTR
    
    CLASS_ATTR_ATOM_LONG(c, "directouts",    0,    t_eval, n_directOutlets);
    CLASS_ATTR_LABEL(c, "directouts", 0, "Number of Outlets");
    //CLASS_ATTR_ACCESSORS(c, "directouts", (method)NULL, (method)llllobj_dummy_setter)
    // @description Number of direct outlets. <br />
    // @copy BACH_DOC_STATIC_ATTR

    CLASS_ATTR_ATOM_LONG(c, "embed",    0,    t_codableobj, c_embed);
    CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
    CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
    CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
    CLASS_ATTR_SAVE(c, "embed", 0);
    //CLASS_ATTR_BASIC(c, "embed", 0);
    //CLASS_ATTR_ACCESSORS(c, "embed", (method)NULL, (method)llllobj_dummy_setter)
    // @description When set to 1, the stored code is saved with the patcher.

    CLASS_ATTR_ATOM_LONG(c, "auto",    0,    t_codableobj, c_auto);
    CLASS_ATTR_LABEL(c, "auto", 0, "Automatically Run Code");
    CLASS_ATTR_STYLE(c, "auto", 0, "onoff");
    //CLASS_ATTR_BASIC(c, "auto", 0);
    //CLASS_ATTR_ACCESSORS(c, "auto", (method)NULL, (method)llllobj_dummy_setter)
    // @description When set to 1, the stored code is automatically run at startup.
    // @copy BACH_DOC_STATIC_ATTR

    CLASS_ATTR_LLLL(c, "triggers", 0, t_eval, n_triggers, eval_getattr_triggers, eval_setattr_triggers);
    CLASS_ATTR_LABEL(c, "triggers", 0, "Triggers");
    CLASS_ATTR_STYLE(c, "triggers", 0, "onoff");
    // @description An llll setting which data inlets are "hot" (i.e., which will will trigger the result)
    // and which global and patcher variables must cause
    // the re-evaluation of the program when assigned a new value.
    // Inlets are counted from 1. 0 means that all data inlets are hot.
    // Negative indices are counted from the right, but only considering data inlets,
    // excluding direct inlets which are always cold anyway.
    // (e.g., -1 means the rightmost data inlet).
    // <m>null</m> means that all inlets are cold,
    // but a <m>bang</m> in any inlet will still cause the llll to be output. <br/>
    // The llll can contain names of global and patcher variables (the latter preceded by a # sign):
    // whenever any of those variables takes a new value, the expression will be re-evaluated.<br/>
    // Sublists composed of a variable name and an integer will treat the integer as the variable auto-evaluation priority:
    // if different objects register to the same variable with different priorities,
    // when the value of the variable changes they will be evaluated
    // according to each's priority, from highest to lowest. The default is 0.<br/>
    // Three special wildcard tokens can be included in the trigger lists:<br/>
    // - * includes all the patcher and global variables used in the code;<br/>
    // - .* includes all the global variables used in the code;<br/>
    // - .# includes all the patcher variables used in the code.<br/>
    // Wildcards can also have a priority, with the same syntax as regular variables.<br/>
    // An important caveat concerning patcher variables
    // is that the ones declared as triggers affect the variable hierarchies,
    // even if they do not appear in the expression.<br/>
    // Examples:<br/>
    // <m>1 2 foo [ #bar 10 ] -1</m> will cause
    // the first, second and rightmost data inlets to be hot,
    // and the foo global variable and bar patcher variable
    // to trigger the evaluation, with priorities respectively of 0 and 10.<br/>
    // <m>#* [ .* -10 ] 1</m> will cause
    // all the patcher and global variables in the code to trigger the evaluation,
    // respectively with a priority of 0 and -10; moreover,
    // data received the first inlet will trigger the evaluation, too.
    
    CLASS_ATTR_LLLL(c, "params", 0, t_codableobj, c_paramsll, codableobj_params_get, codableobj_params_set);
    CLASS_ATTR_LABEL(c, "params", 0, "Extra Parameters");
    // @description The <m>params</m> attribute allows setting the values
    // of local variables to be passed to the code.
    // It is structured as an llll consisting of one or more sublists,
    // each containing the name of a variable and its value to be passed to the code.
    // For example, the llll <m>[ $foo 1 ] [ $bar [ 2 3 ] ]</m>
    // will set the $foo and $bar local variables respectively to <m>1</m> and <m>[ 2 3 ]</m>.
    
    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
    // @copy BACH_DOC_STATIC_ATTR

    //CLASS_ATTR_ACCESSORS(c, "out", (method)NULL, (method)llllobj_dummy_setter)


    class_register(CLASS_BOX, c);
    eval_class = c;
    
    dev_post("bach.eval compiled %s %s", __DATE__, __TIME__);
    
    return;
}

void eval_parse_all_triggers(t_eval *x)
{
    codableobj_removeAllVarTriggers((t_codableobj*) x);

    x->n_triggerInletsCount = 0;
    
    for (t_llllelem *elem = x->n_triggers->l_head;
         elem;
         elem = elem->l_next) {
        t_hatom *h = &elem->l_hatom;
        if (hatom_is_number(h)) {
            x->n_triggerInlets[x->n_triggerInletsCount++] = hatom_getlong(h);
        } else {
            t_symbol *varname;
            long priority = 0;
            if (t_llll *subll = hatom_getllll(h) ; subll) {
                varname = hatom_getsym(&subll->l_head->l_hatom);
                if (subll->l_size == 2)
                    priority = hatom_getlong(&subll->l_tail->l_hatom);
            } else
                varname = hatom_getsym(h);
            codableobj_register_trigger_variable((t_codableobj *) x, varname, priority);
        }
    }
}


t_max_err eval_setattr_triggers(t_eval *x, t_object *attr, long ac, t_atom *av)
{
    t_llll *ll;
    if (ac == 0 || av) {
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, av))) {
            t_llll *free_me;
            if (eval_check_triggers_llll(x, ll) != MAX_ERR_NONE) {
                llll_free(ll);
                return MAX_ERR_NONE;
            }
            bach_atomic_lock(&x->n_ob.c_triggers_lock);
            free_me = x->n_triggers;
            x->n_triggers = ll;
            eval_parse_all_triggers(x);
            bach_atomic_unlock(&x->n_ob.c_triggers_lock);
            llll_free(free_me);
            if (x->n_ob.c_ready)
                codableobj_resolve_trigger_vars((t_codableobj*) x, NULL, 0, NULL);
        }
    }
    return MAX_ERR_NONE;
}

t_max_err eval_check_triggers_llll(t_eval *x, t_llll *ll)
{
    t_llllelem *elem;
    if (ll->l_depth > 2)
        goto eval_check_triggers_llll_error;
        for (elem = ll->l_head; elem; elem = elem->l_next) {
        if (!hatom_is_number(&elem->l_hatom)) {
            if (t_llll *sub_ll = hatom_getllll(&elem->l_hatom); sub_ll) {
                if (sub_ll->l_size > 2)
                    goto eval_check_triggers_llll_error;
                if (t_symbol *s = hatom_getsym(&sub_ll->l_head->l_hatom);
                    !s || *(s->s_name) == '$') {
                    object_error((t_object *) x, "Bad trigger variable");
                        goto eval_check_triggers_llll_error;
                }
                if (sub_ll->l_size == 2 && !hatom_is_number(&sub_ll->l_tail->l_hatom))
                    goto eval_check_triggers_llll_error;
            } else if (elem->l_hatom.h_type != H_SYM) {
                goto eval_check_triggers_llll_error;
            }
        }
    }
    return MAX_ERR_NONE;
    
eval_check_triggers_llll_error:
    object_error((t_object *) x, "Bad triggers llll");
    return MAX_ERR_GENERIC;
}

void eval_dblclick(t_eval *x)
{
    codableobj_dblclick_helper((t_codableobj *) x, gensym("expr"));
}

void eval_bang_deferred(t_eval *x, t_symbol *s, long ac, t_atom *av)
{
    if (x->n_ob.c_ready) {
        t_atom_long inlet = atom_getlong(av);
        eval_run(x, inlet);
    } else {
        defer_low(x, (method) eval_bang_deferred, _sym_int, 1, av);
    }
}

void eval_bang(t_eval *x)
{
    t_atom_long inlet = proxy_getinlet((t_object *) x) + 1;
    if (x->n_ob.c_ready)
        eval_run(x, inlet);
    else {
        t_atom a;
        atom_setlong(&a, inlet);
        defer_low(x, (method) eval_bang_deferred, _sym_int, 1, &a);
    }
}

void eval_triggerfromclient(t_eval *x, long dummy)
{
    eval_run(x, 0);
}

void eval_run(t_eval *x, long inlet)
{
    if (!x->n_ob.c_main)
        return;
    x->n_ob.c_main->setInlet(inlet);
    t_execEnv context((t_llllobj_object *) x, x->n_ob.c_main);
    long dataInlets = x->n_dataInlets;
    
    for (int i = 0; i < dataInlets; i++) {
        context.argv[i + 1] = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i);
    }
    context.argc = dataInlets;
    
    long outlets = x->n_dataOutlets;
    x->n_ob.c_main->setOutlets(outlets); // in case the code has just changed
    
    x->n_ob.c_main->clearOutletData();
    t_llll *result = codableobj_run((t_codableobj *) x, context);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, outlets, result);
    llll_free(result);
    for (int i = outlets - 1; i >= 0; i--) {
        t_llll *outll = x->n_ob.c_main->getOutletData(i);
        if (outll) {
            llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, i, outll);
        }
    }
    
    for (int i = 1; i <= dataInlets; i++) {
        llll_release(context.argv[i]);
    }
}


void eval_int(t_eval *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    eval_anything(x, _sym_int, 1, &outatom);
}

void eval_float(t_eval *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    eval_anything(x, _sym_float, 1, &outatom);
}

void eval_anything(t_eval *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
    if (eval_ishot(x, inlet))
        eval_bang(x);
}

void eval_expr(t_eval *x, t_symbol *msg, long ac, t_atom *av)
{
    codableobj_lambda_set((t_codableobj *) x, nullptr, ac, av);
}

long eval_ishot(t_eval *x, long inlet)
{
    long hot = 0;
    bach_atomic_lock(&x->n_ob.c_triggers_lock);
    if (x->n_triggerInletsCount == 0)
        hot = 0;
    else {
        long numinlets = x->n_dataInlets;
        for (auto i = 0; i < x->n_triggerInletsCount; i++) {
            long this_trigger = x->n_triggerInlets[i];
            if ((this_trigger == 0 && inlet < x->n_dataInlets) ||
                this_trigger == inlet + 1 ||
                (this_trigger < 0 && this_trigger == inlet - numinlets))
                hot = 1;
        }
    }
    bach_atomic_unlock(&x->n_ob.c_triggers_lock);
    return hot;
}

void eval_inletinfo(t_eval *x, void *b, long a, char *t)
{
    *t = !eval_ishot(x, a);
}

void eval_assist(t_eval *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a < x->n_dataInlets)
            sprintf(s, "llll: Data Inlet %ld", a + 1); // @in 0 @loop 1 @type llll @digest llll to be assigned to inlet pseudovariables
        else
            sprintf(s, "llll: Direct Inlet " ATOM_LONG_PRINTF_FMT, a - x->n_dataInlets + 1); // @in 1 @type llll @digest llll to be assigned to direct inlet pseudovariables
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        if (a < x->n_dataOutlets)
            sprintf(s, "llll (%s): Data Outlet %ld", type, a + 1); // @out 0 @loop 1 @type llll @digest Values assigned to outlet pseudovariables
        else if (a == x->n_dataOutlets)
            sprintf(s, "llll (%s): Evaluation Result", type); // @out 1 @type llll @digest Final result of the evaluation
        else
            sprintf(s, "llll (%s): Direct Outlet " ATOM_LONG_PRINTF_FMT, type, a - x->n_dataOutlets); // @out 2 @loop 1 @type llll @digest Values assigned to direct outlet pseudovariables
    }
}

void eval_free(t_eval *x)
{
    codableobj_free((t_codableobj *) x);
}

t_eval *eval_new(t_symbol *s, short ac, t_atom *av)
{
    t_eval *x = NULL;
    long true_ac, i;
    t_max_err err = 0;
    
    //true_ac = attr_args_offset(ac, av);

    if ((x = (t_eval *) object_alloc_debug(eval_class))) {
        // @arg 0 @name expression @optional 1 @type anything @digest Expression to evaluate
        // @description The syntax of the expression is based upon <o>bach.expr</o>'s,
        // but it can contain branching and loop statements, and user-defined variables and functions.
        // For a complete description of the expression syntax, please refer to the help file.
        
        x->n_triggerInletsCount = 1;
        x->n_triggerInlets[0] = 1;
        
        x->n_ob.c_ofTable = new t_ofTable;
        eval_ownedFunctionsSetup(x);
        x->n_ob.c_embed = 1;
        x->n_ob.c_maxtime = 60000;
        x->n_ob.c_watch = 1;
        true_ac = ac;
        x->n_ob.c_text = (char *) bach_newptr(2);
        strncpy_zero(x->n_ob.c_text, " ", 2);
        
        t_atom_long dataInlets = -1, dataOutlets = -1, directInlets = -1, directOutlets = -1;
        
        long codeac = -1;

        if (ac &&
            (atom_gettype(av) != A_SYM || *atom_getsym(av)->s_name != '@')) {
            // we build the ast from the text with the atom separators,
            // as this allows us to figure out where the object attributes begin
            codableobj_getCodeFromAtomsWithSeparators((t_codableobj *) x, ac, av);
            err = codableobj_buildAst((t_codableobj *) x, &codeac, &dataInlets, &dataOutlets, &directInlets, &directOutlets);
            
            if (err == MAX_ERR_NONE) {
                if (codeac < 0) codeac = ac;
                
                // then we convert again the code in the object box to text,
                // this time without the atom separators and leaving out the object attributes,
                // for the text editor etc.
                sysmem_freeptr(x->n_ob.c_text);
                codableobj_getCodeFromAtoms((t_codableobj *) x, codeac, av);
            } else {
                // if the code was invalid, the attributes can't be parsed
                // so it's better to abort the object instantiation
                object_error((t_object *) x, "Invalid code");
                object_free_debug(x);
                return nullptr;
            }
        } else {
            codeac = 0;
        }
        
        if (dataInlets < 1)
            dataInlets = 1;
        
        if (codeac >= 0) {
            attr_args_process(x, ac - codeac, av + codeac);
        }
        
        if (dataInlets > x->n_dataInlets)
            x->n_dataInlets = dataInlets;
        if (dataOutlets > x->n_dataOutlets)
            x->n_dataOutlets = dataOutlets;
        if (directInlets > x->n_directInlets)
            x->n_directInlets = directInlets;
        if (directOutlets > x->n_directOutlets)
            x->n_directOutlets = directOutlets;
        
        CLIP_ASSIGN(x->n_dataOutlets, 0, 127);
        CLIP_ASSIGN(x->n_directOutlets, 0, 126);

        char outlet_str[256];
        long totOutlets = x->n_dataOutlets + x->n_directOutlets;
        for (i = 0; i <= totOutlets; i++)
            outlet_str[i] = '4';
        outlet_str[i] = 0;
        
        long totInlets = x->n_dataInlets + x->n_directInlets;
        llllobj_obj_setup((t_llllobj_object *) x, totInlets, outlet_str);

        object_attr_setdisabled((t_object *)x, gensym("extraoutlets"), true);
        object_attr_setdisabled((t_object *)x, gensym("inlets"), true);
        object_attr_setdisabled((t_object *)x, gensym("directins"), true);
        object_attr_setdisabled((t_object *)x, gensym("directouts"), true);
        //object_attr_setdisabled((t_object *)x, gensym("auto"), true);
        //object_attr_setdisabled((t_object *)x, gensym("embed"), true);
        //object_attr_setdisabled((t_object *)x, gensym("out"), true);

        x->n_proxies = CLAMP(totInlets - 1, 0, LLLL_MAX_INLETS);
        
        x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        
        codableobj_finalize((t_codableobj *) x);
        
        if (x->n_ob.c_main) {
            x->n_ob.c_main->setOutlets(x->n_dataOutlets);
            defer_low(x, (method)codableobj_resolvepatchervars, NULL, 0, NULL);
        }
        defer_low(x, (method)codableobj_resolve_trigger_vars, NULL, 0, NULL);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE) {
        if (x->n_ob.c_auto)
            defer_low(x, (method) eval_deferbang, _sym_bang, 0, nullptr);
        return x;
    }
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

void eval_deferbang(t_eval *x, t_symbol *msg, long ac, t_atom *av)
{
    eval_bang(x);
}

void eval_ownedFunctionsSetup(t_eval *x)
{
    (*x->n_ob.c_ofTable)["directout"] = new t_fnDirectout(x);
    (*x->n_ob.c_ofTable)["directin"] = new t_fnDirectin(x);
    (*x->n_ob.c_ofTable)["print"] = new t_fnPrint((t_object *) x);
}

