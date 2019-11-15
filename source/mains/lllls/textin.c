/*
 *  textin.c
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
 textin.c
 
 @name
 bach.textin
 
 @realname
 bach.textin
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Accept variants of the llll text format
 
 @description
 Parses lllls according to variants of the text format.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 text, native, backtick, llll
 
 @seealso
 bach.portal, bach.textout, bach.read
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _textin
{
    t_llllobj_object 	n_ob;
    long				n_proxies;
    void				**n_proxy;
    long				n_in;
    
    long                n_ignore;
    t_symbol            *n_ignore_sym;
} t_textin;

void textin_assist(t_textin *x, void *b, long m, long a, char *s);
void textin_inletinfo(t_textin *x, void *b, long a, char *t);

t_textin *textin_new(t_symbol *s, short ac, t_atom *av);
void textin_free(t_textin *x);

void textin_bang(t_textin *x);
void textin_int(t_textin *x, t_atom_long v);
void textin_float(t_textin *x, double v);
void textin_anything(t_textin *x, t_symbol *msg, long ac, t_atom *av);
t_max_err textin_notify(t_textin *x, t_symbol *s, t_symbol *msg, void *sender, void *data);
void textin_patchlineupdate(t_textin *x, t_object *line, t_patchline_updatetype updatetype, t_object *src, long srcout, t_object *dst, long dstin);
void textin_add_symbol(t_textin *x, t_symbol *sym, t_object *obj);
void textin_add_symbol_to_this(t_textin *x, t_symbol *sym);


t_class *textin_class;

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.textin", (method)textin_new, (method)textin_free, (long) sizeof(t_textin), 0L, A_GIMME, 0);
    
    // @method llll @digest A text-format llll received in any inlet
    // is interpreted according to specific rules set by the <m>ignore</m> attribute.
    // lllls in native format are accepted but not affected.
    
    class_addmethod(c, (method)textin_anything,	"anything",		A_GIMME,	0);
    
    class_addmethod(c, (method)textin_int,         "int",			A_LONG,		0);
    class_addmethod(c, (method)textin_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)textin_anything,	"list",			A_GIMME,	0);
    
    class_addmethod(c, (method)textin_bang,		"bang",			0);
    
    class_addmethod(c, (method)textin_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)textin_inletinfo,	"inletinfo",	A_CANT,		0);
    
    
    
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);
    bachobject_class_add_fileusage_method(c);
    
    CLASS_ATTR_SYM(c, "ignore",	0,	t_textin, n_ignore_sym);
    CLASS_ATTR_LABEL(c, "ignore", 0, "Ignore Categories");
    //CLASS_ATTR_BASIC(c, "ignore", 0);
    // CLASS_ATTR_ACCESSORS(c, "ignore", (method)NULL, (method)llllobj_dummy_setter)
    // @description The <m>ignore</m> attribute allows preventing certain categories
    // of elements from being interpreted according to the usual bach syntax.
    // Categories are expressed by letters, according to the following table:<br />
    // - <b>L</b> stands for all the open and closed parens marking llll sublists:
    // if this category is set, parens and symbols containing parens
    // are interpreted just as symbols, as if they were preceded by a backtick. <br />
    // - <b>l</b> stands for open and closed parens marking llll sublists,
    // only if they do not appear in a symbol of their own
    // (i.e., with the <b>l</b> category set,
    // <b>[</b> is interpreted as the beginning of a sublist,
    // whereas <b>[1</b> is interpreted just as a plain symbol,
    // as opposed to what would happen normally,
    // when it would mark the beginning of a sublist
    // whose first element is <b>1</b>). <br />
    // - <b>r</b> stands for rationals. <br />
    // - <b>p</b> stands for pitches. <br />
    // - <b>e</b> stands for floating-point numbers in scientific notation. <br />
    // - <b>s</b> stands for the special symbols <b>nil</b> and <b>null</b>. <br />
    // - <b>b</b> causes symbols beginning with a backtick
    // to be interpreted with the backtick included
    // (e.g., the <b>`foo</b> symbol is read as it is, including the backtick,
    // as opposed to what would happen normally, when it would be read as <b>foo</b>). <br />
    // - <b>-</b> reverses the selection, that is, makes the characters detailed above
    // indicate the categories <i>not</i> to be ignored. <br />
    // - <b>1</b> stands for ignoring all the above categories.
    // If it is present alongside other specifiers (e.g., <b>alp</b>), it overrides them. <br />
    // - <b>0</b> stands for no category, and is the default.
    // If it is present alongside other specifiers (e.g., <b>-p</b>), it is ignored. <br />
    // For example, the <m>ignore</m> attribute could be set to <b>lp</b>,
    // which would cause a message containing <b>[ a001 Mahler[Bernstein].aif ]</b>
    // to be interpreted as an llll containing a sublist, 
    // containing in turn the symbols <b>a001</b> and <b>Mahler[Bernstein].aif</b>.
    // Without setting the <m>ignore</m> attribute, the same message would be interpreted
    // as an llll containing a sublist containing the pitch <b>A1</b>,
    // the symbol <b>Mahler</b>,
    // a further sublist only containing the symbol <b>Bernstein</b>,
    // and finally the symbol <b>.aif</b>. <br />
    // @copy BACH_DOC_STATIC_ATTR
    
    
    class_register(CLASS_BOX, c);
    textin_class = c;
    
    dev_post("bach.textin compiled %s %s", __DATE__, __TIME__);
    
    return;
}

void textin_bang(t_textin *x)
{
    textin_anything(x, _sym_bang, 0, NULL);
}

void textin_int(t_textin *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    textin_anything(x, _sym_int, 1, &outatom);
}

void textin_float(t_textin *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    textin_anything(x, _sym_float, 1, &outatom);
}

void textin_anything(t_textin *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    
    t_llll *ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE, x->n_ignore);
    if (!ll)
        return;
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, inlet, ll, x->n_ignore);
    llll_release(ll);
}

void textin_assist(t_textin *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        sprintf(s, "llll %ld", a + 1); // @in 0 @loop 1 @type llll @digest llll to be interpreted according to the <m>ignore</m> attribute and output from the corresponding outlet
    } else {
        sprintf(s, "llll (text): llll %ld", a + 1);
        // @out 0 @loo@type llll @digest The llll received in the corresponding inlet
    }
}

void textin_inletinfo(t_textin *x, void *b, long a, char *t)
{
    *t = 0;
}

void textin_free(t_textin *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_textin *textin_new(t_symbol *s, short ac, t_atom *av)
{
    t_textin *x = NULL;
    t_max_err err = 0;
    
    if ((x = (t_textin *) object_alloc_debug(textin_class))) {
        // @arg 0 @name inlets @optional 1 @type int @digest Number of llll inlets/outlets
        
        long i;
        long true_ac = attr_args_offset(ac, av);
        long inlets = 1;
        
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

        x->n_proxies = inlets - 1;
        x->n_proxy = (void **) bach_newptr(inlets * sizeof(void *));
        for (i = x->n_proxies; i > 0; i--)
            x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
        
        char outlets[LLLL_MAX_OUTLETS], *this_outlets;
        this_outlets = outlets;
        for (i = x->n_proxies; i >= 0; i--, this_outlets++)
            *this_outlets = '4';
        *this_outlets = 0;
        llllobj_obj_setup((t_llllobj_object *) x, 0, outlets);
        
        x->n_ignore_sym = gensym("");
        
        for (i = true_ac ; i < ac - 1; i++) {
            t_symbol *symattr = atom_getsym(av + i);
            if (!symattr || *symattr->s_name != '@') {
                object_error((t_object *) x, "Bad argument at position %ld", i);
                i++;
                break;
            }
            const char *attrname = symattr->s_name + 1;
            i++;
            if (!strcmp(attrname, "ignore")) {
                char const *ignore_txt;
                switch (atom_gettype(av + i)) {
                    case A_SYM:
                        ignore_txt = atom_getsym(av + i)->s_name;
                        break;
                    case A_LONG:
                        switch (atom_getlong(av + i)) {
                            case 0:
                                ignore_txt = (char *) "0";
                                break;
                            case 1:
                                ignore_txt = (char *) "1";
                                break;
                            default:
                                object_error((t_object *) x, "Bad value %ld for ignore attribute", atom_getlong(av + i));
                                ignore_txt = "";
                                break;
                        }
                        break;
                    case A_FLOAT:
                        object_error((t_object *) x, "Bad value %lf for ignore attribute", atom_getfloat(av + i));
                        ignore_txt = "";
                        break;
                }
                
                x->n_ignore_sym = gensym(ignore_txt);

                long negative = 0;
                while (*ignore_txt) {
                    switch (*ignore_txt) {
                        case 'L':   x->n_ignore |= LLLL_I_BIGPARENS | LLLL_I_SMALLPARENS;   break;
                        case 'b':   x->n_ignore |= LLLL_I_BACKTICK;   break;
                        case 'e':   x->n_ignore |= LLLL_I_SCIENTIFIC;   break;
                        case 'l':   x->n_ignore |= LLLL_I_SMALLPARENS;   break;
                        case 'p':   x->n_ignore |= LLLL_I_PITCH;   break;
                        case 'r':   x->n_ignore |= LLLL_I_RATIONAL;   break;
                        case 's':   x->n_ignore |= LLLL_I_SPECIAL;   break;
                        case '1':   x->n_ignore = LLLL_I_ALL;   break;
                        case '0':   break;
                        case '-':   negative = 1;   break;
                        default:    object_warn((t_object *) x, "Ignoring unknown %c specifier for ignore attribute", *ignore_txt); break;
                    }
                    ignore_txt++;
                }
                if (negative) {
                    x->n_ignore = LLLL_I_ALL ^ x->n_ignore;
                }
                
            } else if (!strcmp(attrname, "out")) {
                llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, av + i);

            } else
                object_error((t_object *) x, "Unknown attribute %s", attrname);
        }
        if (i < ac)
            object_error((t_object *) x, "Bad argument list");
        
    } else
        error(BACH_CANT_INSTANTIATE);
    
    object_attr_setdisabled((t_object *)x, gensym("ignore"), true);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x);
    return NULL;
}
