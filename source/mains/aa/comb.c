/**
 @file
 comb.c
 
 @name 
 bach.comb
 
 @realname 
 bach.comb
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Combinations of elements
 
 @description
 Returns the combinations of the elements of a given llll.
 
 @discussion
 Combinations are grouped in sublists according to their cardinality. 
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 combination, combinatory, element, arrange, arrangement

 @seealso
 bach.perm, bach.scramble, bach.cartesianprod
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _comb
{
    struct llllobj_object     n_ob;
    long                    n_kstart;
    t_atom                    n_kend;
    
    long                    n_maxcount;
    long                    n_allow_repetitions;
} t_comb;


void comb_assist(t_comb *x, void *b, long m, long a, char *s);
void comb_inletinfo(t_comb *x, void *b, long a, char *t);

t_comb *comb_new(t_symbol *s, short ac, t_atom *av);
void comb_free(t_comb *x);

void comb_bang(t_comb *x);
void comb_int(t_comb *x, t_atom_long v);
void comb_float(t_comb *x, double v);
void comb_anything(t_comb *x, t_symbol *msg, long ac, t_atom *av);

t_max_err comb_setattr_kstart(t_comb *x, void *attr, long ac, t_atom *av);
t_max_err comb_setattr_kend(t_comb *x, void *attr, long ac, t_atom *av);

t_class *comb_class;


int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.comb", (method)comb_new, (method)comb_free, (short)sizeof(t_comb), 0L, A_GIMME, 0);

    // @method llll @digest Compute the combinations
    // @description
    // Returns all the combinations of the given llll, within the optionally given cardinality range.
    // Combinations are grouped in sublists one by one, and these sublists are utterly grouped by cardinality.
    // For instance the llll <b>a b c</b>, with no cardinality limits, will trigger the result <b>[[]] [[a][b][c]] [[a b][a c][b c]] [[a b c]]</b>

    class_addmethod(c, (method)comb_anything,    "anything",        A_GIMME,    0);
    
    class_addmethod(c, (method)comb_int,        "int",            A_LONG,        0);
    class_addmethod(c, (method)comb_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)comb_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Perform last operation
    // @description Returns the combination of the most recently received llll.
    class_addmethod(c, (method)comb_bang,        "bang",            0);
    
    class_addmethod(c, (method)comb_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)comb_inletinfo,    "inletinfo",    A_CANT,        0);
    
    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
    
    
    CLASS_ATTR_LONG(c, "kstart", 0, t_comb, n_kstart);
    CLASS_ATTR_ACCESSORS(c, "kstart", (method)NULL, (method)comb_setattr_kstart);
    CLASS_ATTR_LABEL(c, "kstart", 0, "Start Cardinality");
    CLASS_ATTR_BASIC(c, "kstart", 0);
    // @description Start cardinality.
    
    CLASS_ATTR_ATOM(c, "kend", 0, t_comb, n_kend);
    CLASS_ATTR_ACCESSORS(c, "kend", (method)NULL, (method)comb_setattr_kend);
    CLASS_ATTR_LABEL(c, "kend", 0, "End Cardinality");
    CLASS_ATTR_BASIC(c, "kend", 0);
    // @description End cardinality.
    
    CLASS_ATTR_LONG(c, "repeat", 0, t_comb, n_allow_repetitions);
    CLASS_ATTR_STYLE_LABEL(c, "repeat", 0, "onoff", "Allow Repetitions");
    CLASS_ATTR_BASIC(c, "repeat", 0);
    // @description Allow repetition of elements in the output (i.e. compute arrangements with repetitions).
    // By default this is 0, and standard combinations are computed.

    CLASS_ATTR_LONG(c, "maxcount", 0, t_comb, n_maxcount);
    CLASS_ATTR_STYLE_LABEL(c, "maxcount", 0, "text", "Maximum Number of Combinations");
    CLASS_ATTR_BASIC(c, "maxcount", 0);
    // @description
    // Maximum number of combinations to return.
    // If set to 0 (default), all the combinations of the input llll are returned.

    
    
    class_register(CLASS_BOX, c);
    comb_class = c;
    
    dev_post("bach.comb compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}


t_max_err comb_setattr_kstart(t_comb *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (atom_gettype(av) == A_LONG || atom_gettype(av) == A_FLOAT)
            x->n_kstart = MAX(0, atom_getlong(av));
        else
            x->n_kstart = 0;
    } else
        x->n_kstart = 0;
        
    x->n_ob.l_rebuild = 1;
    return MAX_ERR_NONE;
}


t_max_err comb_setattr_kend(t_comb *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        if (atom_gettype(av) == A_LONG || atom_gettype(av) == A_FLOAT)
            x->n_kend = *av;
        else
            atom_setsym(&x->n_kend, gensym("<none>"));
    } else
        atom_setsym(&x->n_kend, gensym("<none>"));
        
    x->n_ob.l_rebuild = 1;
    return MAX_ERR_NONE;

}

void comb_bang(t_comb *x)
{    
    if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
        comb_anything(x, _sym_bang, 0, NULL);
    else
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void comb_int(t_comb *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    comb_anything(x, _sym_int, 1, &outatom);
}

void comb_float(t_comb *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    comb_anything(x, _sym_float, 1, &outatom);
}

void comb_anything(t_comb *x, t_symbol *msg, long ac, t_atom *av)
{    
    long kend;
    t_llll *ll, *combed;
    if (msg != _sym_bang) {
        ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
    if (atom_gettype(&x->n_kend) == A_SYM)
        kend = -1;
    else
        kend = atom_getlong(&x->n_kend);
    
    if (x->n_allow_repetitions)
        combed = llll_comb_with_repetitions(ll,x->n_kstart, kend, x->n_maxcount);
    else
        combed = llll_comb(ll, x->n_kstart, kend, x->n_maxcount);
    
    llll_release(ll);
    x->n_ob.l_rebuild = 0;
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, combed, 0);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void comb_assist(t_comb *x, void *b, long m, long a, char *s)
{    
    if (m == ASSIST_INLET) {
        sprintf(s, "llll"); // @in 0 @type llll @digest llll to process
    } else {    
        char *type;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "llll (%s): Combinations", type); // @out 0 @type llll @digest The computed combinations
    }
}

void comb_inletinfo(t_comb *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void comb_free(t_comb *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_comb *comb_new(t_symbol *s, short ac, t_atom *av)
{
    t_comb *x = NULL;
    t_max_err err = MAX_ERR_NONE;

    if ((x = (t_comb *) object_alloc_debug(comb_class))) {
        // @arg 0 @name cardinality @optional 1 @type list @digest Cardinality
        // @description If only one argument is present, it is considered both start and end cardinality.
        // If two arguments are present, the first is considered start cardinality, the second end cardinality
        
        x->n_allow_repetitions = false;
        x->n_maxcount = 0;
        
        long true_ac = attr_args_offset(ac, av);
        atom_setsym(&x->n_kend, gensym("<none>"));
        if (true_ac >= 1) {
            if (atom_gettype(av) == A_LONG) {
                t_atom_long k = atom_getlong(av);
                x->n_kstart = k;
                atom_setlong(&x->n_kend, k);
            } else {
                object_error((t_object *) x, "Bad argument");
            }
        }
        if (true_ac >= 2) {
            if (atom_gettype(av + 1) == A_LONG)
                x->n_kend = *(av + 1);
            else
                object_error((t_object *) x, "Bad argument");
        }
        if (true_ac > 2)
            object_warn((t_object *) x, "Too many arguments");
        attr_args_process(x, ac, av);
        llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
    } else 
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
