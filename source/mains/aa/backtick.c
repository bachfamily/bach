/**
 @file
 backtick.c
 
 @name
 bach.backtick
 
 @realname
 bach.backtick
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Backticks the first element of a text-format llll
 
 @description
 Returns the text-format representation of the llll, with the first element preceded by a backtick if certains conditions are met.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 text, backtick, attributes
 
 @seealso
 bach.portal
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _backtick
{
    t_llllobj_object 	n_ob;
    long                n_autoattrs;
    long                n_argsbackticknull;
    long                n_attrsbackticknull;
    t_hashtab           *n_argsymbols;
    t_hashtab           *n_attrsymbols;
} t_backtick;

void backtick_assist(t_backtick *x, void *b, long m, long a, char *s);
void backtick_inletinfo(t_backtick *x, void *b, long a, char *t);

t_backtick *backtick_new(t_symbol *s, short ac, t_atom *av);
void backtick_free(t_backtick *x);

void backtick_bang(t_backtick *x);
void backtick_int(t_backtick *x, t_atom_long v);
void backtick_float(t_backtick *x, double v);
void backtick_anything(t_backtick *x, t_symbol *msg, long ac, t_atom *av);
t_max_err backtick_notify(t_backtick *x, t_symbol *s, t_symbol *msg, void *sender, void *data);


t_class *backtick_class;

int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.backtick", (method)backtick_new, (method)backtick_free, (short)sizeof(t_backtick), 0L, A_GIMME, 0);
    
    // @method llll @digest Return the llll in text format, with the first element backticked if requested.
    // @description
    // Returns the incoming llll in text format, with the first element backticked if one of the following conditions is met: <br/>
    // - The first element is one of Max's or bach's reserved symbols (<m>int</m>, <m>float</m>, <m>list</m>, <m>null</m>, <m>nil</m>),
    // as with all the bach objects. <br/>
    // - The first element is a rational or a pitch, as with all the bach objects. <br/>
    // - The first element is one of the symbols provided as <o>bach.backtick</o>'s arguments.
    // - The <m>autoattrs</m> attribute is not explicitly set to 0, and the first element is an attribute of one of the objects
    // connected to <o>bach.backtick</o>.

    class_addmethod(c, (method)backtick_anything,	"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)backtick_int,		"int",			A_LONG,		0);
    class_addmethod(c, (method)backtick_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)backtick_anything,	"list",			A_GIMME,	0);
    
    // @method bang @digest Return the data types
    // @description Returns the data types of the most recently received llll.
    class_addmethod(c, (method)backtick_bang,		"bang",			0);
    
    class_addmethod(c, (method)backtick_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)backtick_inletinfo,	"inletinfo",	A_CANT,		0);
    
    /*
    CLASS_ATTR_LONG(c, "autoattrs",	0,	t_backtick, n_autoattrs);
    CLASS_ATTR_FILTER_CLIP(c, "autoattrs", 0, 1);
    CLASS_ATTR_STYLE(c, "autoattrs", 0, "onoff");
    CLASS_ATTR_LABEL(c, "autoattrs", 0, "Retrieve attributes");
    // @description When set to 1 (default), the attributes of all the objects connected to <o>bach.backtick</o>
    // are considered symbols to be prepended by a backtick if encountered at the first position of the llll, in addition to the standard ones
    // (<m>int</m>, <m>float</m>, <m>list</m>, <m>null</m>, <m>nil</m>) and the ones provided as the object's arguments.
    */
    
    class_register(CLASS_BOX, c);
    backtick_class = c;
    
    dev_post("bach.backtick compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void backtick_bang(t_backtick *x)
{
    backtick_anything(x, _sym_bang, 0, NULL);
}

void backtick_int(t_backtick *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    backtick_anything(x, _sym_int, 1, &outatom);
}

void backtick_float(t_backtick *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    backtick_anything(x, _sym_float, 1, &outatom);
}

void backtick_anything(t_backtick *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
    
    switch (ll->l_size) {
        case 0:
            if (x->n_argsbackticknull || x->n_attrsbackticknull) {
                llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, gensym("`null"), 0, NULL);
            } else {
                llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_null, 0, NULL);
            }
            break;
        case 1:
            if (ll->l_head->l_hatom.h_type == H_SYM) {
                t_object *found = NULL;
                t_symbol *sym = hatom_getsym(&ll->l_head->l_hatom);
                hashtab_lookup(x->n_argsymbols, sym, &found);
                if (!found)
                    hashtab_lookup(x->n_attrsymbols, sym, &found);
                if (found) {
                    llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, sym_addquote(sym->s_name), 0, NULL);;
                } else
                    llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, sym, 0, NULL);;
            } else {
                llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, ll);
            }
            break;
        default:
            if (ll->l_head->l_hatom.h_type == H_SYM) {
                t_object *found = NULL;
                t_symbol *sym = hatom_getsym(&ll->l_head->l_hatom);
                hashtab_lookup(x->n_argsymbols, sym, &found);
                if (!found)
                    hashtab_lookup(x->n_attrsymbols, sym, &found);
                if (found) {
                    t_atom *atoms = NULL;
                    long ac;
                    llll_destroyelem_no_depth_check(ll->l_head);
                    ac = llll_deparse(ll, &atoms, 0, LLLL_D_QUOTE | LLLL_D_MAX);
                    llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, sym_addquote(sym->s_name), ac, atoms);
                    bach_freeptr(atoms);
                } else
                    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, ll);
            } else {
                llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, ll);
            }
            break;
    }
    llll_release(ll);
}

void backtick_assist(t_backtick *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "llll"); // @in 0 @type llll @digest The llll whose contained data types will be reported
    } else {
        switch (a) {
            case 0:	sprintf(s, "llll (text): backticked llll");		break;
                // @out 0 @type llll @digest The text-format llll, with the first element backticked if required
                // @description The incoming llll is returned in text format,
                // with its first element preceded by a backtick in the standard cases,
                // if it is one of the supplied arguments,
                // or if it is an attribute of one of the objects it is connected to
                // (unless the autoattrs attribute is set to 0)
        }
    }
}

void backtick_inletinfo(t_backtick *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void backtick_free(t_backtick *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_backtick *backtick_new(t_symbol *s, short ac, t_atom *av)
{
    t_backtick *x = NULL;
    t_max_err err = 0;
    //long true_ac;
    
    //true_ac = attr_args_offset(ac, av);
    
    if ((x = (t_backtick *) object_alloc_debug(backtick_class))) {
        // @arg 0 @name symbols @optional 1 @type anything @digest Symbols
        // @description The symbols that have to be backticked if found at the first position of the incoming lllls.

        long i;
        long true_ac = attr_args_offset(ac, av);
        x->n_autoattrs = 1;
        
        for (i = true_ac; i < ac - 1; i++) {
            t_symbol *symattr = atom_getsym(av + i);
            if (!symattr || *symattr->s_name != '@') {
                object_error((t_object *) x, "Bad argument at position %ld", i);
                i++;
                break;
            }
            const char *attrname = symattr->s_name + 1;
            i++;
            if (!strcmp(attrname, "autoattrs")) {
                x->n_autoattrs = atom_getlong(av);
                i++;
            } else
                object_error((t_object *) x, "Unknown attribute %s", attrname);
        }
        if (i < ac)
            object_error((t_object *) x, "Bad argument list");
        
        t_atom out;
        atom_setsym(&out, _llllobj_sym_t);
        llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, &out);
        llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
        
        x->n_argsymbols = hashtab_new(0);
        x->n_attrsymbols = hashtab_new(0);
        object_method(x->n_argsymbols, gensym("readonly"), 1);
        object_method(x->n_attrsymbols, gensym("readonly"), 1);
       for (i = 0; i < true_ac; i++, av++) {
            long type = atom_gettype(av);
            switch (type) {
                case A_SYM:
                    hashtab_store(x->n_argsymbols, atom_getsym(av), (t_object *) WHITENULL);
                    if (atom_getsym(av) == _llllobj_sym_null)
                        x->n_argsbackticknull = 1;
                    break;
                case A_LONG:
                    object_warn((t_object *) x, "ignoring argument %ld", atom_getlong(av));
                    break;
                case A_FLOAT:
                    object_warn((t_object *) x, "ignoring argument %lf", atom_getfloat(av));
                    break;
                default:
                    break;
            }
        }
    } else 
        error(BACH_CANT_INSTANTIATE);
    
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}