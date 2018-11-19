/**
 @file
 lisp.c
 
 @name
 bach.lisp
 
 @realname
 bach.lisp
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 lisperse an llll
 
 @description
 Performs a lispersal of an llll and its sublists, within a specified depth range.
 
 @discussion
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 lisperse, invert
 
 @seealso
 bach.rot, bach.slice, bach.join, bach.trans
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include <ecl/ecl.h>

typedef struct _lisp
{
    struct llllobj_object 	n_ob;
    long					n_mindepth;
    long					n_maxdepth;
} t_lisp;


void lisp_assist(t_lisp *x, void *b, long m, long a, char *s);
void lisp_inletinfo(t_lisp *x, void *b, long a, char *t);

cl_object lisp_lisp(const char *call);
t_llll *lisp_cl_object_to_llll(t_lisp *x, cl_object o);

t_lisp *lisp_new(t_symbol *s, short ac, t_atom *av);
void lisp_free(t_lisp *x);

void lisp_bang(t_lisp *x);
void lisp_int(t_lisp *x, t_atom_long v);
void lisp_float(t_lisp *x, double v);
void lisp_anything(t_lisp *x, t_symbol *msg, long ac, t_atom *av);

void lisp_read(t_lisp *x, t_symbol *s);
void lisp_doread(t_lisp *x, t_symbol *s);
void lisp_openfile(t_lisp *x, char *filename, short path);



// We can use the following macros to define the setters for the maxdepth and mindepth attributes, which can't be set to 0.

DEFINE_STANDARD_MAXDEPTH_SETTER(t_lisp);
DEFINE_STANDARD_MINDEPTH_SETTER(t_lisp);

t_class *lisp_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.lisp", (method)lisp_new, (method)lisp_free, (short)sizeof(t_lisp), 0L, A_GIMME, 0);
    
    // @method llll @digest lisperse the incoming llll
    // @description Perform the lispersal on the incoming llll.
    class_addmethod(c, (method)lisp_anything,	"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)lisp_int,			"int",			A_LONG,		0);
    class_addmethod(c, (method)lisp_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)lisp_anything,	"list",			A_GIMME,	0);
    
    class_addmethod(c, (method)lisp_read, "read", A_DEFSYM, 0);
    
    // @method bang @digest Perform the lispersal
    // @description Perform the lispersal on the most recently received llll.
    class_addmethod(c, (method)lisp_bang,		"bang",			0);
    
    class_addmethod(c, (method)lisp_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)lisp_inletinfo,	"inletinfo",	A_CANT,		0);
    
    
    
    
    
    
    // This is very important: it defines the out attribute, define its getter and setter
    // and also manages the notify method for managing the l_rebuild field.
    // Always put this in the main() function of an object with llll outlets.
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    

    
    class_register(CLASS_BOX, c);
    lisp_class = c;
    
    dev_post("bach.lisp compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

cl_object lisp_lisp(const char *call)
{
    return cl_safe_eval(c_string_to_object(call), Cnil, Cnil);
}

void lisp_bang(t_lisp *x)
{
    if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0) {
        lisp_anything(x, _sym_bang, 0, NULL);
    } else {
        
        
        
        // The llll resulting from the operation (or an empty llll, if no operation has been performed yet)
        // has been stored in the first store.
        // Now we output the contents of the first store (counted from 0: it's the third argument of the function call),
        // in native or text format according to the value of the out attribute.
        
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
    }
}

void lisp_int(t_lisp *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    lisp_anything(x, _sym_int, 1, &outatom);
}

void lisp_float(t_lisp *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    lisp_anything(x, _sym_float, 1, &outatom);
}

void lisp_anything(t_lisp *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *ll;
    char *buf = NULL;
    if (msg != _sym_bang) {
        ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else {
        
        // the 1 at the end means that a clone of the store contents must be returned
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
    }
    ////////////llll_to_text_buf(ll, &buf);
    
    cl_object result = lisp_lisp(buf);
    llll_release(ll);
    
    t_llll *res_ll = lisp_cl_object_to_llll(x, result);
    
    x->n_ob.l_rebuild = 0;
    
    // This loads ll into the first output cache (the final 0, as usual).
    // Notice that we don't release ll, as ownership to it has been handed to the output cache.
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, res_ll, 0);
    
    // After loading an llll, we can output it.
    // All the output cache mechanism is relevant because we want to be able to respond to a bang
    // by outputting again the same lispersed llll without having to re-perform the lispersal.
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
    
}

void lisp_read(t_lisp *x, t_symbol *s)
{
    defer(x, (method)lisp_doread, s, 0, NULL);
}

void lisp_doread(t_lisp *x, t_symbol *s)
{
    t_fourcc filetype = 'TEXT', outtype;
    short numtypes = 1;
    char filename[MAX_PATH_CHARS];
    short path;
    if (s == gensym("")) {      // if no argument supplied, ask for file
        if (open_dialog(filename, &path, &outtype, &filetype, 1))       // non-zero: user cancelled
            return;
    } else {
        strcpy(filename, s->s_name);    // must copy symbol before calling locatefile_extended
        if (locatefile_extended(filename, &path, &outtype, &filetype, 1)) { // non-zero: not found
            object_error((t_object *) x, "%s: not found", s->s_name);
            return;
        }
    }
    // we have a file
    lisp_openfile(x, filename, path);
}

void lisp_openfile(t_lisp *x, char *filename, short path)
{
    t_filehandle fh;
    char **texthandle;
    if (path_opensysfile(filename, path, &fh, READ_PERM)) {
        object_error((t_object *) x, "error opening %s", filename);
        return;
    }
    // allocate some empty memory to receive text
    texthandle = sysmem_newhandle(0);
    sysfile_readtextfile(fh, texthandle, 0, TEXT_LB_NATIVE);     // see flags explanation below
    sysfile_close(fh);
    cl_object result = lisp_lisp(*texthandle);
    t_llll *res_ll = lisp_cl_object_to_llll(x, result);
    x->n_ob.l_rebuild = 0;
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, res_ll, 0);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
    sysmem_freehandle(texthandle);
}

t_llll *lisp_cl_object_to_llll(t_lisp *x, cl_object o)
{

    cl_type type = ecl_t_of(o);
    
    /* t_cons, t_fixnum, t_character, t_bignum, t_ratio, t_singlefloat, 
     t_doublefloat, t_complex, t_symbol, t_package, t_hashtable, t_array, 
     t_vector, t_string, t_bitvector, t_stream, t_random, t_readtable, 
     t_pathname, t_bytecodes, t_cfun, t_cclosure, t_gfun, t_instance, t_foreign and t_thread.
     */
    switch (type) {
        case t_fixnum:
        {
            t_llll *ll = llll_get();
            t_atom_long n = fix(o);
            llll_appendlong(ll, n);
            return ll;
            break;
        }
        case t_character:
        {
            t_llll *ll = llll_get();
            char s[2];
            s[0] = CHAR_CODE(o);
            s[1] = 0;
            llll_appendsym(ll, gensym(s));
            return ll;
            break;
        }
        case t_list:
        {
            if (!Null(o)) {
                cl_object car = ECL_CONS_CAR(o);
                cl_object cdr = ECL_CONS_CDR(o);
                t_llll *ll = lisp_cl_object_to_llll(x, car);
                if (ECL_LISTP(car))
                    llll_wrap(&ll);
                t_llll *cdr_ll = lisp_cl_object_to_llll(x, cdr);
                llll_chain(ll, cdr_ll);
                return ll;
            } else
                return llll_get();
            break;
        }
        case t_ratio:
        {
            t_llll *ll = llll_get();
            t_rational r = genrat(fix(o->ratio.num), fix(o->ratio.den));
            llll_appendrat(ll, r);
            return ll;
            break;
        }
        case t_singlefloat:
        {
            t_llll *ll = llll_get();
            double f = o->SF.SFVAL;
            llll_appenddouble(ll, f);
            return ll;
            break;
        }
        case t_doublefloat:
        {
            t_llll *ll = llll_get();
            double f = o->DF.DFVAL;
            llll_appenddouble(ll, f);
            return ll;
            break;
        }
        case t_base_string:
        {
            t_llll *ll = llll_get();
            ecl_base_char *txt = o->base_string.self;
            llll_appendsym(ll, gensym((char *) txt));
            return ll;
            break;
        }
        case t_cl_string:
        {
            t_llll *ll = llll_get();
            ecl_character *txt = o->string.self;
            llll_appendsym(ll, gensym((char *) txt));
            return ll;
            break;
        }
        case t_cl_symbol:
        {
            return lisp_cl_object_to_llll(x, o->symbol.name);
            break;
        }
        default:
        {
            object_warn((t_object *) x, "Unsupported data type: %d", type);
            return llll_get();
            break;
        }
    }
}


void lisp_assist(t_lisp *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "llll"); // @in 0 @digest The llll to lisperse
    } else {
        char *type = NULL;
        
        // this returns the string "text", "native" or "disabled" according to the value of the out attribute for this outlet
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        
        sprintf(s, "llll (%s)", type); // @out 0 @digest The lispersed llll
    }
}

void lisp_inletinfo(t_lisp *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void lisp_free(t_lisp *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_lisp *lisp_new(t_symbol *s, short ac, t_atom *av)
{
    t_lisp *x = NULL;
    t_max_err err = 0;
    long true_ac;
    
    if ((x = (t_lisp *) object_alloc_debug(lisp_class))) {
        // @arg 0 @name depths @optional 1 @type list @digest Depth options
        // @description If there is only one argument, it sets <m>maxdepth</m>.
        // If there are two arguments, they set respectively <m>mindepth</m> and <m>maxdepth</m>.
        char *av0 = (char *) "/Users/andreaagostini/Documents/Max 7/Packages/bach/externals/bach.lisp.mxo";
        cl_boot(1, &av0);
        x->n_mindepth = 1;
        x->n_maxdepth = -1;
        true_ac = attr_args_offset(ac, av);
        switch (true_ac) {
            case 0:
                break;
            case 1:
                object_attr_setvalueof(x, gensym("maxdepth"), 1, av);
                break;
            case 2:
                object_attr_setvalueof(x, gensym("mindepth"), 1, av);
                object_attr_setvalueof(x, gensym("maxdepth"), 1, av + 1);
                break;
            default:
                object_warn((t_object *) x, "Bad number of arguments");
                break;
        }
        
        attr_args_process(x, ac, av);
        
        // "4" means that we want a single llll outlet
        // look at the llllobj_obj_setup() documentation for more information about this.
        // It must always be called after attr_args_process if there are llll outlets,
        // because the out attribute must have been set
        llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
    } else 
        error(BACH_CANT_INSTANTIATE);
    
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
