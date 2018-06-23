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
#include "ast.hpp"


void code_assist(t_code *x, void *b, long m, long a, char *s);
void code_inletinfo(t_code *x, void *b, long a, char *t);

t_code *code_new(t_symbol *s, short ac, t_atom *av);
void code_free(t_code *x);

void code_bang(t_code *x);
void code_int(t_code *x, t_atom_long v);
void code_float(t_code *x, double v);
void code_anything(t_code *x, t_symbol *msg, long ac, t_atom *av);

long code_atoms2text(t_code *x, long ac, t_atom *av);
void code_buildAst(t_code *x, t_atom_long *inlets, t_atom_long *outlets);


// editor
void code_okclose(t_code *x, char *s, short *result);
void code_edclose(t_code *x, char **ht, long size);
void code_dblclick(t_code *x);
long code_edsave(t_code *x, char **ht, long size);


t_mainFunction *stringparser_parse_buffer(char *buf, t_safeTable<t_sharedVariable> *gvt, t_atom_long *inlets, t_atom_long *outlets, std::unordered_map<std::string, t_function *> *bifs, struct _code *owner);
void bifSetup();
void code_ownedFunctionsSetup(t_code *x);



t_class *code_class;

static t_safeTable<t_sharedVariable> *gvt;
static std::unordered_map<std::string, t_function *> *bifTable;



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
    class_addmethod(c, (method)code_edclose,        "edclose",		A_CANT, 0);
    class_addmethod(c, (method)code_okclose,        "okclose",       A_CANT, 0);
    //class_addmethod(c, (method)code_edclose,        "edsave",		A_CANT, 0);
    
    class_register(CLASS_BOX, c);
    code_class = c;
    
    if (!gvt)
        gvt = new t_safeTable<t_sharedVariable>;
    
    if (!bifTable) {
        bifSetup();
    }

    
    dev_post("bach.code compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}


void code_dblclick(t_code *x)
{
    if (!x->n_editor)
        x->n_editor = (t_object *)object_new(CLASS_NOBOX, gensym("jed"), (t_object *)x, 0);
    else
        object_attr_setchar(x->n_editor, gensym("visible"), 1);
    
    object_method(x->n_editor, _sym_settext, x->n_text, gensym("utf-8"));
    object_attr_setsym(x->n_editor, gensym("title"), gensym("code"));
}


void code_okclose(t_code *x, char *s, short *result)
{
    *result = 0;
}

void code_edclose(t_code *x, char **ht, long size)
{
    // do something with the text
    if (ht) {
        bach_atomic_lock(&x->n_lock);
        sysmem_freeptr(x->n_text);
        x->n_text = sysmem_newptr(size + 2);
        sysmem_copyptr(*ht, x->n_text, size);
        if (!isspace(*(x->n_text + size - 1))) {
            *(x->n_text + size) = ' ';
            *(x->n_text + size + 1) = 0;
        }
        t_atom_long dummy_inlets = 0, dummy_outlets = 0;
        code_buildAst(x, &dummy_inlets, &dummy_outlets);
        bach_atomic_unlock(&x->n_lock);
    }
    x->n_editor = NULL;
}

long code_edsave(t_code *x, char **ht, long size)
{
    return 1;
}

void code_bang(t_code *x)
{
    t_execContext context((t_llllobj_object *) x);
    
    t_llll *argv[x->n_inlets];
    for (int i = 0; i < x->n_inlets; i++) {
        argv[i] = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i);
    }
    if (x->n_main) {
        long outlets = x->n_outlets;
        if (outlets)
            x->n_main->clearOutletData(outlets);
        t_llll *result = x->n_main->call(x->n_inlets, argv, context);
        llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, outlets, result);
        llll_free(result);
        for (int i = outlets - 1; i >= 0; i--) {
            t_llll *outll = x->n_main->getOutletData(i);
            if (outll) {
                llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, i, outll);
                llll_free(outll);
            }
        }
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
    } else {
        code_atoms2text(x, ac, av);
        t_atom_long dummy_inlets = 0, dummy_outlets = 0;
        code_buildAst(x, &dummy_inlets, &dummy_outlets);
    }
}

void code_assist(t_code *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "llll");
        // @in 0 @type llll @digest llll to be compared
        // @in 1 @type llll @digest llll to be compared
    } else
        sprintf(s, "int: Comparison Result"); // @out 0 @type int @digest Comparison result (0/1)
}

void code_inletinfo(t_code *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void code_free(t_code *x)
{
    if (x->n_main)
        x->n_main->decrease();
    llllobj_obj_free((t_llllobj_object *) x);
}

t_code *code_new(t_symbol *s, short ac, t_atom *av)
{
    t_code *x = NULL;
    long true_ac;
    t_max_err err = 0;
    
    true_ac = attr_args_offset(ac, av);
    
    
    if ((x = (t_code *) object_alloc_debug(code_class))) {
        // @arg 0 @name default @optional 1 @digest Default comparison llll

        code_ownedFunctionsSetup(x);

        if (true_ac) {
            code_atoms2text(x, true_ac, av);
            code_buildAst(x, &x->n_inlets, &x->n_outlets);
        }
        
        long i = true_ac;
        while (i < ac - 1) {
            t_symbol *symattr = atom_getsym(av + i);
            if (!symattr || *symattr->s_name != '@') {
                object_error((t_object *) x, "Bad argument at position %ld", i);
                i++;
                break;
            }
            const char *attrname = symattr->s_name + 1;
            i++;
            if (!strcmp(attrname, "inlets")) {
                long type = atom_gettype(av + i);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(av + i);
                    x->n_inlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                    i++;
                } else
                    object_error((t_object *) x, "Bad value for inlets attribute");
            } else if (!strcmp(attrname, "outlets")) {
                long type = atom_gettype(av + i);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(av + i);
                    x->n_outlets = CLAMP(val, 0, LLLL_MAX_INLETS);
                    i++;
                } else
                    object_error((t_object *) x, "Bad value for inlets attribute");
            } else if (!strcmp(attrname, "out")) {
                llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, av + i);
                i++;
            } else
                object_error((t_object *) x, "Unknown attribute %s", attrname);
        }
        if (x->n_inlets < 1)
            x->n_inlets = 1;
        
        CLIP_ASSIGN(x->n_outlets, 0, 254);
        char outlet_str[256];
        for (i = 0; i <= x->n_outlets; i++)
            outlet_str[i] = '4';
        outlet_str[i] = 0;
        
        llllobj_obj_setup((t_llllobj_object *) x, x->n_inlets, outlet_str);
        
        x->n_proxies = CLAMP(x->n_inlets - 1, 0, LLLL_MAX_INLETS);
        
        x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
    } else 
        error(BACH_CANT_INSTANTIATE);
    
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

long code_atoms2text(t_code *x, long ac, t_atom *av)
{
    long textsize = 0;
    char *buf = NULL;
    atom_gettext(ac, av, &textsize, &buf, OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
    buf = sysmem_resizeptr(buf, textsize + 1);
    *(buf + textsize - 1) = ' ';
    *(buf + textsize) = 0;
    bach_atomic_lock(&x->n_lock);
    sysmem_freeptr(x->n_text);
    x->n_text = buf;
    bach_atomic_unlock(&x->n_lock);
    post("%s---", buf);
    return textsize + 1;
}

void code_buildAst(t_code *x, t_atom_long *inlets, t_atom_long *outlets)
{
    if (x->n_main)
        x->n_main->decrease();
    t_mainFunction *newMain = stringparser_parse_buffer(x->n_text, gvt, inlets, outlets, bifTable, x);
    if (newMain)
        x->n_main = newMain;
    else
        *inlets = -1;
}

void code_ownedFunctionsSetup(t_code *x)
{
    x->n_ofTable["directout"] = new t_fnDirectout(x);
    x->n_ofTable["directin"] = new t_fnDirectin(x);
    x->n_ofTable["print"] = new t_fnPrint(x);
}

void bifSetup()
{
    bifTable = new std::unordered_map<std::string, t_function *>;
    (*bifTable)["length"] = new t_fnLength;
    (*bifTable)["depth"] = new t_fnDepth;
    (*bifTable)["nth"] = new t_fnNth;
    (*bifTable)["sort"] = new t_fnSort;
    (*bifTable)["contains"] = new t_fnContains;
    (*bifTable)["rev"] = new t_fnRev;
    (*bifTable)["rot"] = new t_fnRot;
    (*bifTable)["trans"] = new t_fnTrans;
    (*bifTable)["flat"] = new t_fnFlat;
    (*bifTable)["slice"] = new t_fnSlice;
    (*bifTable)["left"] = new t_fnLeft;
    (*bifTable)["right"] = new t_fnRight;
    (*bifTable)["args"] = new t_fnArgs;
    (*bifTable)["subs"] = new t_fnSubs;
    (*bifTable)["insert"] = new t_fnInsert;
    (*bifTable)["find"] = new t_fnFind;
    (*bifTable)["finditems"] = new t_fnFinditems;
    (*bifTable)["findaddrs"] = new t_fnFindaddrs;
    (*bifTable)["scramble"] = new t_fnScramble;
    (*bifTable)["minmax"] = new t_fnMinmax;
    (*bifTable)["perm"] = new t_fnPerm;
    (*bifTable)["comb"] = new t_fnComb;
    (*bifTable)["cartesianprod"] = new t_fnCartesianprod;
    (*bifTable)["wrap"] = new t_fnWrap;
    (*bifTable)["group"] = new t_fnGroup;
    (*bifTable)["thin"] = new t_fnThin;
    (*bifTable)["classify"] = new t_fnClassify;
    (*bifTable)["union"] = new t_fnUnion;
    (*bifTable)["intersection"] = new t_fnIntersection;
    (*bifTable)["symdiff"] = new t_fnSymdiff;
    (*bifTable)["diff"] = new t_fnDiff;
    (*bifTable)["primeser"] = new t_fnPrimeser;
    (*bifTable)["arithmser"] = new t_fnArithmser;
    (*bifTable)["geomser"] = new t_fnGeomser;

    (*bifTable)["outlet"] = new t_fnOutlet;
    
    (*bifTable)["cos"] = new t_mathUnaryFunctionDD<cos>;
    (*bifTable)["sin"] = new t_mathUnaryFunctionDD<sin>;
    (*bifTable)["tan"] = new t_mathUnaryFunctionDD<tan>;
    (*bifTable)["exp"] = new t_mathUnaryFunctionDD<exp>;
    (*bifTable)["log"] = new t_mathUnaryFunctionDD<log>;
    (*bifTable)["acos"] = new t_mathUnaryFunctionDD<acos>;
    (*bifTable)["asin"] = new t_mathUnaryFunctionDD<asin>;
    (*bifTable)["atan"] = new t_mathUnaryFunctionDD<atan>;
    (*bifTable)["cosh"] = new t_mathUnaryFunctionDD<cosh>;
    (*bifTable)["sinh"] = new t_mathUnaryFunctionDD<sinh>;
    (*bifTable)["tanh"] = new t_mathUnaryFunctionDD<tanh>;
    (*bifTable)["exp2"] = new t_mathUnaryFunctionDD<exp2>;
    (*bifTable)["log2"] = new t_mathUnaryFunctionDD<log2>;
    (*bifTable)["sqrt"] = new t_mathUnaryFunctionDD<sqrt>;
    (*bifTable)["ceil"] = new t_mathUnaryFunctionDD<ceil>;
    (*bifTable)["acosh"] = new t_mathUnaryFunctionDD<acosh>;
    (*bifTable)["asinh"] = new t_mathUnaryFunctionDD<asinh>;
    (*bifTable)["atanh"] = new t_mathUnaryFunctionDD<atanh>;
    (*bifTable)["log10"] = new t_mathUnaryFunctionDD<log10>;
    (*bifTable)["floor"] = new t_mathUnaryFunctionDD<floor>;
    (*bifTable)["round"] = new t_mathUnaryFunctionDD<round>;
    (*bifTable)["trunc"] = new t_mathUnaryFunctionDD<trunc>;

    (*bifTable)["fmod"] = new t_mathBinaryFunctionDDD<fmod>;
    (*bifTable)["atan2"] = new t_mathBinaryFunctionDDD<atan2>;
    (*bifTable)["hypot"] = new t_mathBinaryFunctionDDD<hypot>;

    (*bifTable)["int"] = new t_mathUnaryFunctionAA<hatom_fn_int>;
    (*bifTable)["rat"] = new t_mathUnaryFunctionAA<hatom_fn_rat>;
    (*bifTable)["num"] = new t_mathUnaryFunctionAA<hatom_fn_num>;
    (*bifTable)["den"] = new t_mathUnaryFunctionAA<hatom_fn_den>;
    (*bifTable)["abs"] = new t_mathUnaryFunctionAA<hatom_fn_abs>;
    (*bifTable)["sgn"] = new t_mathUnaryFunctionAA<hatom_fn_sgn>;
    (*bifTable)["float"] = new t_mathUnaryFunctionAA<hatom_fn_float>;
    (*bifTable)["pitch"] = new t_mathUnaryFunctionAA<hatom_fn_pitch>;
    (*bifTable)["degree"] = new t_mathUnaryFunctionAA<hatom_fn_degree>;
    (*bifTable)["octave"] = new t_mathUnaryFunctionAA<hatom_fn_octave>;
    (*bifTable)["alter"] = new t_mathUnaryFunctionAA<hatom_fn_alter>;
    (*bifTable)["cents"] = new t_mathUnaryFunctionAA<hatom_fn_cents>;

    (*bifTable)["pow"] = new t_mathBinaryFunctionAAA<hatom_fn_pow>("base", "exponent");
    (*bifTable)["mod"] = new t_mathBinaryFunctionAAA<hatom_fn_mod>;
    (*bifTable)["min"] = new t_mathBinaryFunctionAAA<hatom_fn_min>;
    (*bifTable)["max"] = new t_mathBinaryFunctionAAA<hatom_fn_max>;
    (*bifTable)["random"] = new t_mathBinaryFunctionAAA<hatom_fn_random>;
    (*bifTable)["bessel"] = new t_mathBinaryFunctionAAA<hatom_fn_jn>("x", "order");
    (*bifTable)["approx"] = new t_mathBinaryFunctionAAA<hatom_fn_approx>;
    (*bifTable)["enharm"] = new t_mathBinaryFunctionAAA<hatom_fn_enharm>;
    (*bifTable)["makepitchsc"] = new t_mathBinaryFunctionAAA<hatom_fn_makepitchsc>("steps", "cents");

    (*bifTable)["makepitch"] = new t_mathTernaryFunctionAAAA<hatom_fn_makepitch>("pitch", "alter", "degree");

    (*bifTable)["#u-"] = new t_mathUnaryFunctionAA<hatom_op_uminus>;
    (*bifTable)["#!"] = new t_mathUnaryFunctionAA<hatom_op_lognot>;
    (*bifTable)["#~"] = new t_mathUnaryFunctionAA<hatom_op_bitnot>;

    (*bifTable)["#+"] = new t_mathBinaryFunctionAAA<hatom_op_plus>;
    (*bifTable)["#-"] = new t_mathBinaryFunctionAAA<hatom_op_minus>;
    (*bifTable)["#*"] = new t_mathBinaryFunctionAAA<hatom_op_times>;
    (*bifTable)["#/"] = new t_mathBinaryFunctionAAA<hatom_op_div>;
    (*bifTable)["#//"] = new t_mathBinaryFunctionAAA<hatom_op_divdiv>;
    (*bifTable)["#%"] = new t_mathBinaryFunctionAAA<hatom_fn_remainder>;
    (*bifTable)["#=="] = new t_mathBinaryFunctionAAA<hatom_op_eq>;
    (*bifTable)["#!="] = new t_mathBinaryFunctionAAA<hatom_op_neq>;
    (*bifTable)["#<"] = new t_mathBinaryFunctionAAA<hatom_op_lt>;
    (*bifTable)["#>"] = new t_mathBinaryFunctionAAA<hatom_op_gt>;
    (*bifTable)["#<="] = new t_mathBinaryFunctionAAA<hatom_op_le>;
    (*bifTable)["#>="] = new t_mathBinaryFunctionAAA<hatom_op_ge>;
    (*bifTable)["#&"] = new t_mathBinaryFunctionAAA<hatom_op_bitand>;
    (*bifTable)["#^"] = new t_mathBinaryFunctionAAA<hatom_op_bitxor>;
    (*bifTable)["#|"] = new t_mathBinaryFunctionAAA<hatom_op_bitor>;
    (*bifTable)["#&&"] = new t_mathBinaryFunctionAAA<hatom_op_logand>;
    (*bifTable)["#^^"] = new t_mathBinaryFunctionAAA<hatom_op_logxor>;
    (*bifTable)["#||"] = new t_mathBinaryFunctionAAA<hatom_op_logor>;
    (*bifTable)["#&&&"] = new t_mathBinaryFunctionAAA<hatom_op_logand>; // TODO
    (*bifTable)["#|||"] = new t_mathBinaryFunctionAAA<hatom_op_logor>; // TODO
    (*bifTable)["#<<"] = new t_mathBinaryFunctionAAA<hatom_op_lshift>; // TODO
    (*bifTable)["#>>"] = new t_mathBinaryFunctionAAA<hatom_op_rshift>; // TODO
}
