/**
 @file
 clanger.c
 
 @name
 bach.clanger
 
 @realname
 bach.clanger
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 deprecated
 
 @digest
 Returns next permutation
 
 @description
 Returns the next permutation of an llll.
 
 @discussion
 Object is deprecated. Use <o>bach.perm</o> with <m>maxcount</m> 1.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 permutation, next
 
 @seealso
 bach.perm
 
 @owner
 Andrea Agostini
 */


#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_obstring.h"

typedef struct _clanger
{
    t_llllobj_object 	n_ob;
    char                *n_code;
    void				**n_proxy;
    long				n_in;
} t_clanger;


void clanger_assist(t_clanger *x, void *b, long m, long a, char *s);
void clanger_inletinfo(t_clanger *x, void *b, long a, char *t);

t_clanger *clanger_new(t_symbol *s, short ac, t_atom *av);
void clanger_free(t_clanger *x);

void clanger_bang(t_clanger *x);
void clanger_int(t_clanger *x, t_atom_long v);
void clanger_float(t_clanger *x, double v);
void clanger_anything(t_clanger *x, t_symbol *msg, long ac, t_atom *av);

t_class *clanger_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    
    c = class_new("bach.clanger", (method)clanger_new, (method)clanger_free, (short)sizeof(t_clanger), 0L, A_GIMME, 0);
    
    class_addmethod(c, (method)clanger_anything,		"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)clanger_int,			"int",			A_LONG,		0);
    class_addmethod(c, (method)clanger_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)clanger_anything,		"list",			A_GIMME,	0);
    class_addmethod(c, (method)clanger_bang,			"bang",			0);
    
    class_addmethod(c, (method)clanger_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)clanger_inletinfo,	"inletinfo",	A_CANT,		0);
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    
    
    class_register(CLASS_BOX, c);
    clanger_class = c;
    
    dev_post("bach.clanger compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void clanger_bang(t_clanger *x)
{
    
    t_object *clang = NULL;
    post("don't bang me!");
    return;



// if it should be interpreted as C++ code:
//object_attr_setlong(clang, gensym("cpp"), 1);

// Compile C code:
    object_method(clang, gensym("compile"), gensym("int foo(int x) { return x+1; }"));
    
    
    char *source = NULL;
    t_string *source_string = string_new(source);
    t_atom rv, av;
    atom_setobj(&av, source_string);
    object_method_typed(clang, gensym("compile"), 1, &av, &rv);
    int err = atom_getlong(&rv);
    object_free(source_string);
    
    
    // Optimize (valid options are O1, O2, O3, default is O2):
    object_method(clang, gensym("optimize"), gensym("O2"));
    
    // Post contained LLVM IR:
    object_method(clang, gensym("dump"));
    
    // Get a function pointer:
    t_atom fun;
    object_method_sym(clang, gensym("getfunction"), gensym("main"), &fun);
    method m = (method) atom_getobj(&fun);
    
    // Destroy the clang object (destroys the associated llvm::Module):
    object_free(clang);
    
    
}

void clanger_int(t_clanger *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    clanger_anything(x, _sym_int, 1, &outatom);
}

void clanger_float(t_clanger *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    clanger_anything(x, _sym_float, 1, &outatom);
}

void clanger_anything(t_clanger *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *ll1, *ll2, *outll;
    long inlet = proxy_getinlet((t_object *) x);
    t_object *clang = NULL;
    long textsize = 0;
    t_string *src_string = NULL;
    t_atom src_atom, rv, fun_atom;
    method gjg;
    char *codeline = NULL;
    //t_max_err err = 0;
    
    if (msg == gensym("clearsource")) {
        x->n_code = 0;
    }
    
    switch (inlet) {
        case 0:
            if (msg != _sym_bang) {
                ll1 = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
                if (!ll1)
                    return;
            } else
                ll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
            ll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);

            // Create a clang object:
            clang = (t_object *) object_new(CLASS_NOBOX, gensym("clang"), gensym("bach.clanger"));
            
            // Configure system paths:
            object_method(clang, gensym("include_standard_headers"));
            
            // Configure include paths:
            object_method(clang, gensym("include"), gensym("/usr/include"));
            object_method(clang, gensym("include"), gensym("/Users/andreaagostini/Documents/Max 7/Packages/max-sdk-7.0.3/source/bach-dev/commons"));
            object_method(clang, gensym("include"), gensym("/Users/andreaagostini/Documents/Max 7/Packages/max-sdk-7.0.3/source/bach-dev/commons/aa"));
            object_method(clang, gensym("include"), gensym("/Users/andreaagostini/Documents/Max 7/Packages/max-sdk-7.0.3/source/c74support/max-includes"));
            object_method(clang, gensym("include"), gensym("/Users/andreaagostini/Documents/Max 7/Packages/max-sdk-7.0.3/source/bach-dev/commons/dg"));

            // Prepend a define:
            object_method(clang, gensym("define"), gensym("BACH_JITCLANG"));
            object_method(clang, gensym("define"), gensym("__cplusplus"));
            object_method(clang, gensym("define"), gensym("MAC_VERSION"));
            object_method(clang, gensym("define"), gensym("CONFIGURATION_Deployment"));
            object_method(clang, gensym("define"), gensym("C74_X64"));
            object_method(clang, gensym("define"), gensym("clang"));

            object_method(clang, gensym("addsymbol"), gensym("llll_rot"), llll_rot);
            object_method(clang, gensym("addsymbol"), gensym("llll_rev"), llll_rev);
            object_method(clang, gensym("addsymbol"), gensym("llll_clone"), llll_clone);
            //object_method(clang, gensym("addsymbol"), gensym("ll1"), ll1);
            //object_method(clang, gensym("addsymbol"), gensym("ll2"), ll2);

            src_string = string_new("int gojohnnygo(void)\n \
            {\n \
                return 1 + 2;\n \
            }\n");
            atom_setobj(&src_atom, src_string);
            
            // if it should be interpreted as C++ code:
            object_attr_setlong(clang, gensym("cpp"), 1);
    
            object_method_typed(clang, gensym("compile"), 1, &src_atom, &rv);
            
            object_method_sym(clang, gensym("getfunction"), gensym("gojohnnygo"), &fun_atom);
            
            gjg = (method) atom_getobj(&fun_atom);
            
            //outll = (t_llll *) (gjg)(ll1, ll2);
            //llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, outll, 1);
            //llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
            
            object_free(src_string);
            llll_free(ll1);
            llll_free(ll2);
            //llll_free(outll);
            
            break;
            
        case 1:
            x->n_ob.l_rebuild = llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1) != NULL;
            break;
            
        case 2:
            atom_gettext(ac, av, &textsize, &codeline, OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE);
            strncat_zero(x->n_code, codeline, 1000000);
            strncat_zero(x->n_code, "\n", 1000000);
            post("%s", x->n_code);
            break;
    }
}


void clanger_assist(t_clanger *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "llll");
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "llll (%s)", type);
    }
}

void clanger_inletinfo(t_clanger *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void clanger_free(t_clanger *x)
{
    sysmem_freeptr(x->n_code);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_clanger *clanger_new(t_symbol *s, short ac, t_atom *av)
{
    t_clanger *x = NULL;
    long true_ac;
    t_max_err err = 0;
    long i;
    
    true_ac = attr_args_offset(ac, av);
    
    if ((x = (t_clanger *) object_alloc_debug(clanger_class))) {
        attr_args_process(x, ac, av);
        x->n_proxy = (void **) bach_newptr(2 * sizeof(void *));
        x->n_code = (char *) sysmem_newptr(1000000);
        for (i = 2; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);

        llllobj_obj_setup((t_llllobj_object *) x, 2, "4", NULL);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}