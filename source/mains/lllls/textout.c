/*
 *  textout.c
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
 textout.c
 
 @name
 bach.textout
 
 @realname
 bach.textout
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Produces variants of the llll text format
 
 @description
 Manages the attribution of backticks and the behavior with respect to negative pitches
 in the textual representation of the incoming lllls.

 
 @category
 bach, bach objects, bach llll
 
 @keywords
 text, backtick, attributes, pitch
 
 @seealso
 bach.portal, bach.textin, bach.write
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _textout
{
    t_llllobj_object 	n_ob;
    long				n_proxies;
    void				**n_proxy;
    long				n_in;

    t_hashtab           *n_symbols;
    t_object            *n_tempobj;
    t_llll              *n_deathrow;
    long                n_flags;
    
    long                n_flags_negative_octaves;
    long                n_flags_escape;
    long                n_flags_parens;
    t_llll              *n_selectors;
} t_textout;

void textout_assist(t_textout *x, void *b, long m, long a, char *s);
void textout_inletinfo(t_textout *x, void *b, long a, char *t);

t_textout *textout_new(t_symbol *s, short ac, t_atom *av);
void textout_free(t_textout *x);

void textout_bang(t_textout *x);
void textout_int(t_textout *x, t_atom_long v);
void textout_float(t_textout *x, double v);
void textout_anything(t_textout *x, t_symbol *msg, long ac, t_atom *av);
t_max_err textout_notify(t_textout *x, t_symbol *s, t_symbol *msg, void *sender, void *data);
void textout_patchlineupdate(t_textout *x, t_object *line, t_patchline_updatetype updatetype, t_object *src, long srcout, t_object *dst, long dstin);
void textout_add_symbol(t_textout *x, t_symbol *sym, t_object *obj);
void textout_add_symbol_to_this(t_textout *x, t_symbol *sym);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_textout, n_selectors, textout_getattr_selectors);


t_class *textout_class;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.textout", (method)textout_new, (method)textout_free, (long) sizeof(t_textout), 0L, A_GIMME, 0);
    
    // @method llll @digest An llll in any inlet is returned in text format from the corresponding outlet,
    // with some optional variants with respect to the standard textual representation.
    // In particular, it is possible to control
    // whether symbols that can be interpreted as different data types
    // are represented with a preceding backtick or not through the <m>backticks</m> attribute,
    // and whether pitches with negative octaves are represented as negative pitches or not. <br />
    // In addition, <o>bach.textout</o> can add a beginning backtick to a symbol at the first position of an llll,
    // if it belongs to a list explicitly provided through the "selectors" attribute,
    // or if it is the name of an attribute of one of the objects optionally connected to <o>bach.textout</o>'s rightmost outlet.
    
    
    class_addmethod(c, (method)textout_anything,	"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)textout_int,         "int",			A_LONG,		0);
    class_addmethod(c, (method)textout_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)textout_anything,	"list",			A_GIMME,	0);
    
    // @method bang @digest Return the data types
    // @description Returns the data types of the most recently received llll.
    class_addmethod(c, (method)textout_bang,		"bang",			0);
    
    class_addmethod(c, (method)textout_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)textout_inletinfo,	"inletinfo",	A_CANT,		0);
    
    class_addmethod(c, (method)textout_patchlineupdate,	"patchlineupdate",	A_CANT,		0);

    
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

     CLASS_ATTR_LONG(c, "escape",	0,	t_textout, n_flags_escape);
     CLASS_ATTR_FILTER_CLIP(c, "escape", 0, 1);
     CLASS_ATTR_LABEL(c, "escape", 0, "Escaping style");
     CLASS_ATTR_ENUMINDEX(c,"escape", 0, "None Backtick");
     // @description When set to 1 (default), all the symbols that could be interpreted as different data types
     // (e.g., the symbol <b>12</b>, the symbol <b>1/3</b> or the symbol <b>A1</b>,
     // distinct from the corresponding integer, rational or pitch, but potentially interpreted as such by any bach object)
     // are returned with a preceding backtick (in the above example, respectively <b>`12</b>, <b>`1/3</b>, <b>`A1</b>).
     // This is the normal behavior for the llll text format.<br />
     // When set to 0, no backtick is added. <br />
     // @copy BACH_DOC_STATIC_ATTR

    
     CLASS_ATTR_LONG(c, "negativeoctaves",	0,	t_textout, n_flags_negative_octaves);
     CLASS_ATTR_FILTER_CLIP(c, "negativeoctaves", 0, 1);
     CLASS_ATTR_LABEL(c, "negativeoctaves", 0, "Use Negative Octaves");
     CLASS_ATTR_STYLE(c, "negativeoctaves", 0, "onoff");
     // @description When set to 0 (default), pitches at octaves lower than octave 0
     // are returned as negative pitches, that is, as the inversion of the interval they form with C0.
     // For example, the pitch A-1 (one minor third below C0) is returned as its equivalent form -Eb0 (still one minor third below C0).
     // This is the normal behavior for the llll text format,
     // and is more likely to be convenient as very low pitches are usually employed to denote descending intervals.
     // Notice that the pitch class of -Eb0 is A anyway.<br />
     // When set to 1, pitches at octaves lower then octave 0 are represented as positive pitches with negative octaves.
     // For example, the pitch A-1 and its equivalent form -Eb0 are both represented as A-1. <br />
     // @copy BACH_DOC_STATIC_ATTR

     CLASS_ATTR_LLLL(c, "selectors", 0, t_textout, n_selectors, textout_getattr_selectors, (method)llllobj_dummy_setter);
     CLASS_ATTR_LABEL(c, "selectors", 0, "Potential Message Selectors");
     // @description Through the <m>selectors</m> attribute, it is possible to specify a list
     // of symbols that, when encountered at the beginning of an llll, 
     // are output with a preceding backtick, to prevent them from being interpreted
     // as message selectors by other Max objects.
     // This list adds up to the names of the attributes of the objects connected to <o>bach.textout</o>'s rightmost outlet,
     // and to the usual set of reserved symbols that are backticked anyway. <br />
     // @copy BACH_DOC_STATIC_ATTR

     CLASS_ATTR_LONG(c, "parens",    0,    t_textout, n_flags_parens);
     CLASS_ATTR_FILTER_CLIP(c, "parens", 0, 1);
     CLASS_ATTR_LABEL(c, "parens", 0, "Use Parens");
     CLASS_ATTR_STYLE(c, "parens", 0, "onoff");
     CLASS_ATTR_ACCESSORS(c, "parens", (method)NULL, (method)llllobj_dummy_setter)
     // @description When set to 0 (default),
     // list levels are marked by square brackets.
     // When set to 1, they are marked by parens.
     // This is especially useful when exporting data to Lisp programs. <br />
     // @copy BACH_DOC_STATIC_ATTR

    class_register(CLASS_BOX, c);
    textout_class = c;
    
    dev_post("bach.textout compiled %s %s", __DATE__, __TIME__);
    
    return;
}

void textout_bang(t_textout *x)
{
    textout_anything(x, _sym_bang, 0, NULL);
}

void textout_int(t_textout *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    textout_anything(x, _sym_int, 1, &outatom);
}

void textout_float(t_textout *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    textout_anything(x, _sym_float, 1, &outatom);
}

void textout_anything(t_textout *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);

    t_llll *ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
    
    switch (ll->l_size) {
        case 0: {
            t_object *found = NULL;
            hashtab_lookup(x->n_symbols, _llllobj_sym_null, &found);
            if (found) {
                llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, inlet, gensym("`null"), 0, NULL);
            } else {
                llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, inlet, _llllobj_sym_null, 0, NULL);
            }
            break;
        }
        case 1:
            if (ll->l_head->l_hatom.h_type == H_SYM) {
                t_object *found = NULL;
                t_symbol *sym = hatom_getsym(&ll->l_head->l_hatom);
                hashtab_lookup(x->n_symbols, sym, &found);
                if (found) {
                    llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, inlet, sym_addquote(sym->s_name), 0, NULL);;
                } else {
                    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, inlet, ll, x->n_flags);
                }
            } else {
                llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, inlet, ll, x->n_flags);
            }
            break;
        default:
            if (ll->l_head->l_hatom.h_type == H_SYM) {
                t_object *found = NULL;
                t_symbol *sym = hatom_getsym(&ll->l_head->l_hatom);
                hashtab_lookup(x->n_symbols, sym, &found);
                if (found) {
                    t_atom *atoms = NULL;
                    long ac;
                    llll_destroyelem_no_depth_check(ll->l_head);
                    ac = llll_deparse(ll, &atoms, 0, LLLL_D_MAX | x->n_flags);
                    llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, inlet, sym_addquote(sym->s_name), ac, atoms);
                    bach_freeptr(atoms);
                } else
                    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, inlet, ll, x->n_flags);
            } else {
                llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, inlet, ll, x->n_flags);
            }
            break;
    }
    llll_release(ll);
}

void textout_assist(t_textout *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "llll %ld", a + 1); // @in 0 @type llll @digest llll to be returned in modified text format.
    } else if (a > x->n_proxies) {
        sprintf(s, "Connect to objects whose attributes you want to backtick");
        // @out 0 @type llll @digest All the attributes of all the objects connected to the second outlet
        // will be added to the list of the symbols to be backticked if they appear as the first element of the incoming llll.
    } else {
        sprintf(s, "llll (text): llll %ld", a + 1);
        // @out 0 @type llll @digest The llll in modified text format
    }
}

void textout_inletinfo(t_textout *x, void *b, long a, char *t)
{
    *t = 0;
}

void textout_free(t_textout *x)
{
    object_free(x->n_symbols);
    llll_free(x->n_deathrow);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_textout *textout_new(t_symbol *s, short ac, t_atom *av)
{
    t_textout *x = NULL;
    t_max_err err = 0;
    
    if ((x = (t_textout *) object_alloc_debug(textout_class))) {
		// @arg 0 @name inlets @optional 1 @type int @digest Number of llll inlets/outlets

        long i;
        long true_ac = attr_args_offset(ac, av);
        long inlets = 1;
        t_atom out;
        atom_setsym(&out, _llllobj_sym_m);
        
        x->n_deathrow = llll_get();
        x->n_symbols = hashtab_new(0);
        object_method(x->n_symbols, gensym("readonly"), 1);
        
        if (true_ac >= 1) {
            inlets = atom_getlong(av);
            if (inlets < 0) {
                object_error((t_object *) x, "Bad number of inlets, setting to 1");
                inlets = 1;
            } else if (inlets > LLLL_MAX_INLETS) {
                object_error((t_object *) x, "Bad number of inlets, setting to %ld", LLLL_MAX_INLETS);
                inlets = LLLL_MAX_INLETS;
            }
            if (true_ac > 1) {
                object_error((t_object *) x, "Bad argument list");
            }
        }
        
        x->n_selectors = llll_make();
        x->n_flags = LLLL_D_QUOTE;
        for (i = true_ac ; i < ac - 1; i++) {
            t_symbol *symattr = atom_getsym(av + i);
            if (!symattr || *symattr->s_name != '@') {
                object_error((t_object *) x, "Bad argument at position %ld", i);
                i++;
                break;
            }
            const char *attrname = symattr->s_name + 1;
            i++;
            if (!strcmp(attrname, "selectors")) {
                for ( ; i < ac; i++) {
                    t_symbol *sym = atom_getsym(av + i);
                    char first = *sym->s_name;
                    if (first == '@') {
                        i--;
                        break;
                    }
                    else if (first == '`')
                        sym = gensym(sym->s_name + 1);
                    llll_appendsym(x->n_selectors, sym);
                    textout_add_symbol_to_this(x, sym);
                }
            } else if (!strcmp(attrname, "escape")) {
                if (i < ac) {
                    if (!atom_getlong(av + i))
                        x->n_flags &= ~LLLL_D_QUOTE;
               } else
                    object_error((t_object *) x, "Missing attribute value for @backticks");
            } else if (!strcmp(attrname, "negativeoctaves")) {
                if (i < ac) {
                    if (atom_getlong(av + i))
                        x->n_flags |= LLLL_D_NEGOCTAVES;
                } else
                    object_error((t_object *) x, "Missing attribute value for @negativeoctaves");
            } else if (!strcmp(attrname, "parens")) {
                if (i < ac) {
                    if (atom_getlong(av + i))
                        x->n_flags |= LLLL_D_PARENS;
                } else
                    object_error((t_object *) x, "Missing attribute value for @negativeoctaves");
            } else
                object_error((t_object *) x, "Unknown attribute %s", attrname);
        }
        if (i < ac)
            object_error((t_object *) x, "Bad argument list");
        
        
        if (x->n_flags & LLLL_D_NEGOCTAVES)
            x->n_flags_negative_octaves = 1;
        if (x->n_flags & LLLL_D_QUOTE)
            x->n_flags_escape = 1;
        if (x->n_flags & LLLL_D_PARENS)
            x->n_flags_parens = 1;
        
        object_attr_setdisabled((t_object *)x, gensym("escape"), true);
        object_attr_setdisabled((t_object *)x, gensym("parens"), true);
        object_attr_setdisabled((t_object *)x, gensym("selectors"), true);
        object_attr_setdisabled((t_object *)x, gensym("negativeoctaves"), true);

        
        x->n_proxies = inlets - 1;
        x->n_proxy = (void **) bach_newptr(inlets * sizeof(void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        
        char outlets[LLLL_MAX_OUTLETS], *this_outlets;
        this_outlets = outlets;
        *this_outlets++ = 'a';
        for (i = x->n_proxies; i >= 0; i--, this_outlets++)
            *this_outlets = '4';
        *this_outlets = 0;
        llllobj_obj_setup((t_llllobj_object *) x, 0, outlets, NULL);
        llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, &out);

    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x);
    return NULL;
}

void textout_remove_object(t_hashtab_entry *e, t_textout *x)
{
    t_hashtab *objects = (t_hashtab *) e->value;
    t_object *dummy = NULL;
    hashtab_lookup(objects, (t_symbol *) x->n_tempobj, &dummy);
    if (dummy) {
        hashtab_delete(objects, (t_symbol *) x->n_tempobj);
        llll_appendsym(x->n_deathrow, e->key);
    }
}

void textout_patchlineupdate(t_textout *x, t_object *line, t_patchline_updatetype updatetype, t_object *src, long srcout, t_object *dst, long dstin)
{
    if (updatetype == JPATCHLINE_CONNECT) {
        if (src == (t_object *) x && srcout == x->n_proxies + 1) {
            long argc = 0, i;
            t_symbol **argv = NULL;
            object_attr_getnames(dst, &argc, &argv);
            for (i = 0; i < argc; i++) {
                t_symbol *sym = argv[i];
                t_hashtab *objects = NULL;
                hashtab_lookup(x->n_symbols, sym, (t_object **) &objects);
                if (objects) {
                    hashtab_store(objects, (t_symbol *) x, (t_object *) x);
                } else {
                    textout_add_symbol(x, sym, dst);
                }
            }
        }
    } else if (updatetype == JPATCHLINE_DISCONNECT) {
        if (src == (t_object *) x && srcout == x->n_proxies + 1) {
            t_llllelem *elem;
            x->n_tempobj = dst;
            hashtab_funall(x->n_symbols, (method) textout_remove_object, x);
            for (elem = x->n_deathrow->l_head; elem; elem = elem->l_next)
                hashtab_delete(x->n_symbols, hatom_getsym(&elem->l_hatom));
            llll_clear(x->n_deathrow);
        }
    }
}

void textout_add_symbol(t_textout *x, t_symbol *sym, t_object *obj)
{
    t_hashtab *objects = hashtab_new(0);
    object_method(objects, gensym("readonly"), 1);
    hashtab_flags(objects, OBJ_FLAG_DATA | OBJ_FLAG_SILENT);
    hashtab_store(objects, (t_symbol *) obj, obj);
    hashtab_store(x->n_symbols, sym, (t_object *) objects);
}

void textout_add_symbol_to_this(t_textout *x, t_symbol *sym)
{
    t_object *dummy = NULL;
    hashtab_lookup(x->n_symbols, sym, &dummy);
    if (!dummy)
        textout_add_symbol(x, sym, (t_object *) sym);
}
