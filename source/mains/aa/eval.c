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
 expr, vexpr, bach.expr, bach.value
 
 @owner
 Andrea Agostini
 */

#include "eval.h"
#include "bach_codableobj.hpp"
#include "ast.hpp"


void eval_assist(t_eval *x, void *b, long m, long a, char *s);
void eval_inletinfo(t_eval *x, void *b, long a, char *t);

t_eval *eval_new(t_symbol *s, short ac, t_atom *av);
void eval_free(t_eval *x);

void eval_bang(t_eval *x);
void eval_int(t_eval *x, t_atom_long v);
void eval_float(t_eval *x, double v);
void eval_anything(t_eval *x, t_symbol *msg, long ac, t_atom *av);
void eval_expr(t_eval *x, t_symbol *msg, long ac, t_atom *av);

void eval_deferbang(t_eval *x, t_symbol *msg, long ac, t_atom *av);

// editor
void eval_dblclick(t_eval *x);

//void bifSetup();
void eval_ownedFunctionsSetup(t_eval *x);

t_class *eval_class;


int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.eval", (method)eval_new, (method)eval_free, (short)sizeof(t_eval), 0L, A_GIMME, 0);
    
    codableclass_add_standard_methods(c, true);

    // @method llll @digest Store values for the expression variables
    // @description
    // The lllls provide the data to the expression.
    // An llll received in the leftmost inlet will trigger the evaluation and cause the result to be output.
    class_addmethod(c, (method)eval_anything,    "anything",        A_GIMME,    0);
    
    // @method expr @digest Expression to evaluate
    // @description
    // The <m>expr</m> message, followed by a valid expression, will set the new expression to be evaluated by <o>bach.eval</o>.
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

    // @method (doubleclick) @digest Edit llll as text
    // @description Double-clicking on the object forces a text editor to open up, where the expression can be edited directly.
    class_addmethod(c, (method)eval_dblclick,        "dblclick",        A_CANT, 0);

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
    // @copy BACH_DOC_STATIC_ATTR

    CLASS_ATTR_ATOM_LONG(c, "auto",    0,    t_codableobj, c_auto);
    CLASS_ATTR_LABEL(c, "auto", 0, "Automatically Run Code");
    CLASS_ATTR_STYLE(c, "auto", 0, "onoff");
    //CLASS_ATTR_BASIC(c, "auto", 0);
    //CLASS_ATTR_ACCESSORS(c, "auto", (method)NULL, (method)llllobj_dummy_setter)
    // @description When set to 1, the stored code is automatically run at startup.
    // @copy BACH_DOC_STATIC_ATTR

    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    // @copy BACH_DOC_STATIC_ATTR

    //CLASS_ATTR_ACCESSORS(c, "out", (method)NULL, (method)llllobj_dummy_setter)


    class_register(CLASS_BOX, c);
    eval_class = c;
    
    dev_post("bach.eval compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}


void eval_dblclick(t_eval *x)
{
    codableobj_dblclick_helper((t_codableobj *) x, gensym("expr"));
}


void eval_bang(t_eval *x)
{
    
    if (!x->n_ob.c_main)
        return;
    t_execEnv context((t_llllobj_object *) x);
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
    
    for (int i = 0; i < dataInlets; i++) {
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
    if (inlet == 0)
        eval_bang(x);
}

void eval_expr(t_eval *x, t_symbol *msg, long ac, t_atom *av)
{
    codableobj_lambda_set((t_codableobj *) x, nullptr, ac, av);
}

void eval_assist(t_eval *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a < x->n_dataInlets)
            sprintf(s, "llll: Data Inlet %ld", a + 1);
        else
            sprintf(s, "llll: Direct Inlet " ATOM_LONG_PRINTF_FMT, a - x->n_dataInlets + 1);

        // @in 0 @type llll @digest llll to be compared
        // @in 1 @type llll @digest llll to be compared
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        if (a < x->n_dataOutlets)
            sprintf(s, "llll (%s): Data Outlet %ld", type, a + 1); // @out 0 @type int @digest Comparison result (0/1)
        else if (a == x->n_dataOutlets)
            sprintf(s, "llll (%s): Evaluation Result", type); // @out 0 @type int @digest Comparison result (0/1)
        else
            sprintf(s, "llll (%s): Direct Outlet " ATOM_LONG_PRINTF_FMT, type, a - x->n_dataOutlets);
    }

}

void eval_inletinfo(t_eval *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
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
    t_dictionary *d = nullptr;
    
    //true_ac = attr_args_offset(ac, av);

    if ((x = (t_eval *) object_alloc_debug(eval_class))) {
        // @arg 0 @name expression @optional 1 @type anything @digest Expression to evaluate
        // @description The syntax of the expression is based upon <o>bach.expr</o>'s,
        // but it can contain branching and loop statements, and user-defined variables and functions.
        // For a complete description of the expression syntax, please refer to the help file.
        
        x->n_ob.c_ofTable = new t_ofTable;
        eval_ownedFunctionsSetup(x);
        x->n_ob.c_embed = 1;
        x->n_ob.c_maxtime = 1000;
        
        true_ac = ac;
        
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

        /*
        if (dataInlets >= 0)
            x->n_dataInlets = dataInlets;
        if (dataOutlets >= 0)
            x->n_dataOutlets = dataOutlets;
        if (directInlets >= 0)
            x->n_directInlets = directInlets;
        if (directOutlets >= 0)
            x->n_directOutlets = directOutlets;
         */
        
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
        
        d = (t_dictionary *)gensym("#D")->s_thing;
        codableobj_getCodeFromDictionaryAndBuild((t_codableobj *) x, d);
        
        if (x->n_ob.c_main)
            x->n_ob.c_main->setOutlets(x->n_dataOutlets);

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
