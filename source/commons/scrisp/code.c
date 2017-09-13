/**
 @file
 code.c
 
 @name
 bach.>=
 
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

#include "llllobj.h"
#include "scrispast.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _code
{
    t_llllobj_object 	n_ob;
    long				n_proxies;
    void				**n_proxy;
    long				n_in;
    t_astNode           *n_ast;
    t_globalVarTable    *n_gvt;
    long n_maxvars;
} t_code;


void code_assist(t_code *x, void *b, long m, long a, char *s);
void code_inletinfo(t_code *x, void *b, long a, char *t);

t_code *code_new(t_symbol *s, short ac, t_atom *av);
void code_free(t_code *x);

void code_bang(t_code *x);
void code_int(t_code *x, t_atom_long v);
void code_float(t_code *x, double v);
void code_anything(t_code *x, t_symbol *msg, long ac, t_atom *av);

long code_buildAst(t_code *x, long ac, t_atom *av);


t_class *code_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
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
    class_register(CLASS_BOX, c);
    code_class = c;
    
    dev_post("bach.code compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void code_bang(t_code *x)
{
    t_llll *result = ast_eval(x->n_ast, (t_llllobj_object *) x);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, result);
    llll_free(result);
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
        code_buildAst(x, ac, av);
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
    globalVarTable_free(x->n_gvt);
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

        x->n_gvt = globalVarTavble_new();
        if (true_ac) {
            x->n_maxvars = code_buildAst(x, true_ac, av);
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
            if (!strcmp(attrname, "maxvars")) {
                long type = atom_gettype(av + i);
                if (type == A_LONG || type == A_FLOAT) {
                    t_atom_long val = atom_getlong(av + i);
                    x->n_maxvars = CLAMP(val, 0, LLLL_MAX_INLETS);
                    i++;
                } else
                    object_error((t_object *) x, "Bad value for maxvars attribute");
            } else if (!strcmp(attrname, "out")) {
                llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, av + i);
                i++;
            } else
                object_error((t_object *) x, "Unknown attribute %s", attrname);
        }
        if (x->n_maxvars < 1)
            x->n_maxvars = 1;
        
        llllobj_obj_setup((t_llllobj_object *) x, x->n_maxvars, "4");
        
        x->n_proxies = CLAMP(x->n_maxvars - 1, 0, LLLL_MAX_INLETS);
        
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

long code_buildAst(t_code *x, long ac, t_atom *av)
{
    long textsize = 0;
    char *buf = NULL;
    long maxvars = 0;
    atom_gettext(ac, av, &textsize, &buf, OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
    buf = sysmem_resizeptr(buf, textsize + 1);
    *(buf + textsize - 1) = ' ';
    *(buf + textsize) = 0;
    post("%s---", buf);
    if (x->n_ast)
        ast_free(x->n_ast);
    globalVarTable_clear(x->n_gvt);
    x->n_ast = bisonparse(buf, x->n_gvt, &maxvars);
    sysmem_freeptr(buf);
    return maxvars;
}