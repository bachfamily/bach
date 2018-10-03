/**
 @file
 code.c
 
 @name
 bach.code
 
 @realname
 bach.code
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Compare two lllls for greater than or equal condition
 
 @description
 Compares two lllls for greater than or equal condition, in numerical/lexicographical order.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 compare, greater, equal, condition, lexicographical, order, numerical
 
 @seealso
 bach.==, bach.!=, bach.&gt;, bach.&lt;, bach.&lt;=, bach.filter, bach.sieve
 
 @owner
 Andrea Agostini
 */

#include "code.h"
#include "bach_codableobj.hpp"
#include "ast.hpp"


void code_assist(t_code *x, void *b, long m, long a, char *s);
void code_inletinfo(t_code *x, void *b, long a, char *t);

t_code *code_new(t_symbol *s, short ac, t_atom *av);
void code_free(t_code *x);

void code_bang(t_code *x);
void code_int(t_code *x, t_atom_long v);
void code_float(t_code *x, double v);
void code_anything(t_code *x, t_symbol *msg, long ac, t_atom *av);

void code_deferbang(t_code *x, t_symbol *msg, long ac, t_atom *av);

// editor
void code_dblclick(t_code *x);

//void bifSetup();
void code_ownedFunctionsSetup(t_code *x);

t_class *code_class;

//static t_safeTable<t_sharedVariable> *gvt;
//static std::unordered_map<std::string, t_function *> *bifTable;



int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.code", (method)code_new, (method)code_free, (short)sizeof(t_code), 0L, A_GIMME, 0);
    
    codableclass_add_standard_methods(c);

    // @method llll @digest Store data and perform comparison
    // @description
    // In first inlet: The llll in the right inlet is compared to the llll and the result is output.<br />
    // In second inlet: The llll is stored, to be compared with an llll received in the first inlet.<br />
    // @copy BACH_DOC_LLLL_COMPARISON
    class_addmethod(c, (method)code_anything,	"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)code_bang,		"bang",			0);
    class_addmethod(c, (method)code_int,		"int",			A_LONG,		0);
    class_addmethod(c, (method)code_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)code_anything,	"list",			A_GIMME,	0);
    
    // @method bang @digest Perform the last operation
    // @description Return the comparison result for the most recently received lllls.
    
    class_addmethod(c, (method)code_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)code_inletinfo,	"inletinfo",	A_CANT,		0);

    // @method (doubleclick) @digest Edit llll as text
    // @description Doubleclicking on the object forces a text editor to open up, where the llll can be edited directly in text form.
    class_addmethod(c, (method)code_dblclick,		"dblclick",		A_CANT, 0);


    class_register(CLASS_BOX, c);
    code_class = c;
    
    dev_post("bach.code compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void code_dblclick(t_code *x)
{
    codableobj_dblclick_helper((t_codableobj *) x, gensym("code"));
}


void code_bang(t_code *x)
{
    
    if (!x->n_ob.c_main)
        return;
    t_execContext context((t_llllobj_object *) x);
    long dataInlets = x->n_dataInlets;
    
    for (int i = 0; i < dataInlets; i++) {
        context.argv[i] = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i);
    }
    context.argc = dataInlets;

    
    long outlets = x->n_dataOutlets;
    x->n_ob.c_main->setOutlets(outlets); // in case the code has just changed

    x->n_ob.c_main->clearOutletData();
    t_llll *result = x->n_ob.c_main->call(context);
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


void code_int(t_code *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    code_anything(x, _sym_int, 1, &outatom);
}

void code_float(t_code *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    code_anything(x, _sym_float, 1, &outatom);
}

void code_anything(t_code *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    if (msg != gensym("code")) {
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
        if (inlet == 0)
            code_bang(x);
    } else
        defer_low(x, (method) codableobj_code_do, gensym("code"), ac, av);
}



void code_assist(t_code *x, void *b, long m, long a, char *s)
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

void code_inletinfo(t_code *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void code_free(t_code *x)
{
    codableobj_free((t_codableobj *) x);
}

t_code *code_new(t_symbol *s, short ac, t_atom *av)
{
    t_code *x = NULL;
    long true_ac, i;
    t_max_err err = 0;
    t_dictionary *d = nullptr;
    
    //true_ac = attr_args_offset(ac, av);

    if ((x = (t_code *) object_alloc_debug(code_class))) {
        // @arg 0 @name default @optional 1 @digest Default comparison llll

        code_ownedFunctionsSetup(x);
        x->n_ob.c_embed = 1;

        true_ac = ac;
        
        t_symbol *symattr;
        char *attrname;
        
        t_atom_long dataInlets = -1, dataOutlets = -1, directInlets = -1, directOutlets = -1;
        
        t_bool attrParseErr = false;
        
        while (true_ac >= 2 &&
               (symattr = atom_getsym(av + true_ac - 2)) &&
               *(attrname = symattr->s_name) == '@') {
            attrname++;
            t_atom *this_av = av + true_ac - 1;
            if (!strcmp(attrname, "inlets")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    dataInlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    if (type == A_SYM && !strchr(atom_getsym(this_av)->s_name, '}'))
                        object_error((t_object *) x, "Bad value for inlets attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "outlets")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    dataOutlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    if (type == A_SYM && !strchr(atom_getsym(this_av)->s_name, '}'))
                        object_error((t_object *) x, "Bad value for outlets attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "directins")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    directInlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    if (type == A_SYM && !strchr(atom_getsym(this_av)->s_name, '}'))
                        object_error((t_object *) x, "Bad value for directins attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "directouts")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    directOutlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                } else {
                    if (type == A_SYM && !strchr(atom_getsym(this_av)->s_name, '}'))
                        object_error((t_object *) x, "Bad value for directouts attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "auto")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    x->n_ob.c_auto = val != 0;
                } else {
                    if (type == A_SYM && !strchr(atom_getsym(this_av)->s_name, '}'))
                        object_error((t_object *) x, "Bad value for auto attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "embed")) {
                long type = atom_gettype(this_av);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(this_av);
                    x->n_ob.c_embed = val != 0;
                } else {
                    if (type == A_SYM && !strchr(atom_getsym(this_av)->s_name, '}'))
                        object_error((t_object *) x, "Bad value for auto attribute");
                    attrParseErr = true;
                }
            } else if (!strcmp(attrname, "out")) {
                t_max_err err = MAX_ERR_NONE;
                char *outtypes = atom_getsym(this_av)->s_name;
                llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_VANILLA, &outtypes, 1, &err);
                bach_freeptr(outtypes);
                if (!err)
                    llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, this_av);
                else {
                    if (atom_gettype(this_av) != A_SYM ||
                        !strchr(atom_getsym(this_av)->s_name, '}'))
                        object_error((t_object *) x, "Bad value for out attribute");
                    attrParseErr = true;
                }
            } else {
                //object_error((t_object *) x, "Unknown attribute %s", attrname);
                attrParseErr = true;
            }
            if (!attrParseErr)
                true_ac -= 2;
            else
                break;
        }

        if (true_ac) {
            codableobj_getCodeFromAtoms((t_codableobj *) x, true_ac, av);
            err = codableobj_buildAst((t_codableobj *) x, &dataInlets, &dataOutlets, &directInlets, &directOutlets);
        }

        if (x->n_dataInlets < 1 || err)
            x->n_dataInlets = 1;
        
        if (dataInlets >= 0)
            x->n_dataInlets = dataInlets;
        if (dataOutlets >= 0)
            x->n_dataOutlets = dataOutlets;
        if (directInlets >= 0)
            x->n_directInlets = directInlets;
        if (directOutlets >= 0)
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
        
        x->n_proxies = CLAMP(totInlets - 1, 0, LLLL_MAX_INLETS);
        
        x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        
        d = (t_dictionary *)gensym("#D")->s_thing;
        codableobj_getCodeFromDictionaryAndBuild((t_codableobj *) x, d);
        
        x->n_ob.c_main->setOutlets(x->n_dataOutlets);

    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE) {
        if (x->n_ob.c_auto)
            defer_low(x, (method) code_deferbang, _sym_bang, 0, nullptr);
        return x;
    }
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

void code_deferbang(t_code *x, t_symbol *msg, long ac, t_atom *av)
{
    code_bang(x);
}



void code_ownedFunctionsSetup(t_code *x)
{
    x->n_ob.c_ofTable["directout"] = new t_fnDirectout(x);
    x->n_ob.c_ofTable["directin"] = new t_fnDirectin(x);
    x->n_ob.c_ofTable["print"] = new t_fnPrint((t_object *) x);
}
