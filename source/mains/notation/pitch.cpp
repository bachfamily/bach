/*
 *  pitchobj.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
    pitch.c
    
    @name
    bach.pitch
    
    @realname
    bach.pitch

    @type
    object
    
    @module
    bach

    @author
    bachproject
    
    @digest
    Construction and query of pitches and their components
    
    @description
    Performs construction of pitches, as well as queries of their components.
    
    @discussion
    bach.pitchobj accepts microtones following the ASCII convention used throughout bach.  <br />
    @copy BACH_DOC_ASCII_ACCIDENTALS_SYNTAX
    
    @category
    bach, bach objects, bach notation, bach pitches

    @keywords
    convert, pitch, note, name, commas, ji, exponents, monzo, ratio

    @seealso
    bach.mc2p, bach.f2mc, bach.mc2f, bach.makepitch
    
    @owner
    Andrea Agostini
*/

#include "foundation/llllobj.h"
#include "notation/notation.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"

typedef enum {
    p_NONE = 0,
    p_PITCH,
    p_ETWHITEKEY,
    p_ETALTER,
    p_OCTAVE,
    p_JIWHITEKEY,
    p_JISHARPS,
    p_JIPLOF,
    p_COMMAS,
    p_JIRATIO,
    p_MONZO
} t_pitchKeys;

typedef struct _pitchobj
{
    struct llllobj_object n_ob;
    t_pitchKeys fromKeys[LLLL_MAX_INLETS];
    int nFromKeys;
    t_pitchKeys toKeys[LLLL_MAX_INLETS];
    int nToKeys;
    void **proxies;
    long inlet;
    t_symbol **dummySym;
    t_atom_long dummyLong;
} t_pitchobj;


void pitchobj_assist(t_pitchobj *x, void *b, long m, long a, char *s);
void pitchobj_inletinfo(t_pitchobj *x, void *b, long a, char *t);

t_pitchobj *pitchobj_new(t_symbol *s, short ac, t_atom *av);
void pitchobj_free(t_pitchobj *x);

void pitchobj_bang(t_pitchobj *x);
void pitchobj_int(t_pitchobj *x, t_atom_long num);
void pitchobj_float(t_pitchobj *x, double num);
void pitchobj_anything(t_pitchobj *x, t_symbol *msg, long ac, t_atom *av);

t_max_err pitchobj_setattr_from(t_pitchobj *x, t_object *attr, long ac, t_atom *av);
t_max_err pitchobj_setattr_to(t_pitchobj *x, t_object *attr, long ac, t_atom *av);

t_class *pitchobj_class;

std::unordered_map<t_symbol*, t_pitchKeys> keys;

void pitchobj_setkeys() {
    keys[gensym("pitch")] = p_PITCH;
    keys[gensym("etwhitekey")] = p_ETWHITEKEY;
    keys[gensym("etalter")] = p_ETALTER;
    keys[gensym("octave")] = p_OCTAVE;
    keys[gensym("jiwhitekey")] = p_JIWHITEKEY;
    keys[gensym("jisharps")] = p_JISHARPS;
    keys[gensym("jiplof")] = p_JIPLOF;
    keys[gensym("commas")] = p_COMMAS;
    keys[gensym("jiratio")] = p_JIRATIO;
    keys[gensym("monzo")] = p_MONZO;
}

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.pitch", (method)pitchobj_new, (method)pitchobj_free, (long) sizeof(t_pitchobj), 0L, A_GIMME, 0);
    
    // @method llll @digest Function depends on inlet type
    // @description When the object receives an llll in its inlet,
    // it will treat it according to the inlet types
    // as declared through the static <m>from</m> attribute.
    // The data received in all the inlets are summed together into a single pitch
    // that is be output, in whole and/or as separate components,
    // according to the outlet types as declared through the <m>to</m> attribute.
    class_addmethod(c, (method)pitchobj_anything,                    "anything",                A_GIMME,    0);
    class_addmethod(c, (method)pitchobj_int,                        "int",                    A_LONG,        0);
    class_addmethod(c, (method)pitchobj_float,                        "float",                A_FLOAT,    0);
    class_addmethod(c, (method)pitchobj_anything,                    "list",                    A_GIMME,    0);

    // @method bang @digest Produce the output
    // @description A <m>bang</m> outputs the pitch resulting from the sum of all the inlet data
    // and/or its components,
    // according to the outlet types as declared through the <m>to</m> attribute.
    class_addmethod(c, (method)pitchobj_bang,                        "bang",        0);
    
    class_addmethod(c, (method)pitchobj_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)pitchobj_inletinfo,    "inletinfo",    A_CANT,        0);

    
    CLASS_ATTR_SYM_VARSIZE(c, "from", 0, t_pitchobj, dummySym, dummyLong, LLLL_MAX_INLETS);
    CLASS_ATTR_ACCESSORS(c, "from", nullptr, pitchobj_setattr_from);
    CLASS_ATTR_INVISIBLE(c, "from", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE_USER);
    // @description The <m>from</m> static attribute declares the types of information
    // that will be received by <o>bach.pitch</o>'s individual inlets. <br />
    // Each inlet type is specified by a symbol,
    // and as many inlets as symbols provided through the <m>from</m> attribute are created.
    // The available symbols and corresponding inlet types are: <br />
    // <b>pitch</b> (a whole pitch literal, such as <m>C#0+1/6t+C{1:-1}4+17/16r</m> <br />
    // <b>etwhitekey</b> (the "white key" of the equal-tempered part, 
    // expressed as an integer from 0 to 6:
    // for instance, 0 is C and 4 is G)  <br />
    // <b>etalter</b> (the alteration in whole tones or fractions thereof 
    // of the equal-tempered part, expressed as an integer or fraction:
    // for instance, -1/2 is a descending chromatic semitone, that is, a flat) <br />
    // <b>octave</b> (the octave of the pitch, with middle C at octave 5) <br />
    // <b>jiwhitekey</b> (the "white key" of the just intonation part, expressed as above) <br />
    // <b>jisharps</b> (the Pythagorean alteration of the just intonation part, 
    // expressed as the number of sharps or, if negative, flats, with respect to the white key:
    // for instance, 1 means one sharp above the white key; -2 means one double flat below the white key) <br />
    // <b>jiplof</b> (the "PLOF", or Pitch in the Line of Fifths, that is,
    // an integer counting how many Pythagorean fifths above C0 the just intonation part is:
    // for example, 4 means E{}2; -1 means F{}-1 or, equivalently, -G{}0) <br />
    // <b>commas</b> (a list containing a vector of HEJI commas for the just intonation part) <br />
    // <b>jiratio</b> (a rational expressing the frequency ratio of the just intonation part 
    // with respect to C0:
    // for example, 3/2 means one Pythagorean fifth above C0, that is, G{}0) <br />
    // <b>monzo</b> (the Monzo vector of the just intonation part, that is,
    // the list of the prime-factor exponents that constitute the frequency ratio) <br />
    // So, for example, <m>from jiwhitekey commas octave</m> creates three inlets,
    // one for each corresponding symbol. <br />
    // If the attribute is not set, a single <b>pitch</b> inlet is created by default.
    // @copy BACH_DOC_STATIC_ATTR
    
    CLASS_ATTR_SYM_VARSIZE(c, "to", 0, t_pitchobj, dummySym, dummyLong, LLLL_MAX_INLETS);
    CLASS_ATTR_ACCESSORS(c, "to", nullptr, pitchobj_setattr_to);
    CLASS_ATTR_INVISIBLE(c, "to", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE_USER);
    // @description The <m>from</m> static attribute declares the types of information
    // that will be received by <o>bach.pitch</o>'s individual inlets. <br />
    // Each inlet type is specified by a symbol,
    // and as many inlets as symbols provided through the <m>from</m> attribute are created.
    // The available symbols and corresponding inlet types are: <br />
    // <b>pitch</b> (a whole pitch literal, such as <m>C#0+1/6t+C{1:-1}4+17/16r</m> <br />
    // <b>etwhitekey</b> (the "white key" of the equal-tempered part,
    // expressed as an integer from 0 to 6:
    // for instance, 0 is C and 4 is G)  <br />
    // <b>etalter</b> (the alteration in whole tones or fractions thereof
    // of the equal-tempered part, expressed as an integer or fraction:
    // for instance, -1/2 is a descending chromatic semitone, that is, a flat) <br />
    // <b>octave</b> (the octave of the pitch, with middle C at octave 5) <br />
    // <b>jiwhitekey</b> (the "white key" of the just intonation part, expressed as above) <br />
    // <b>jisharps</b> (the Pythagorean alteration of the just intonation part,
    // expressed as the number of sharps or, if negative, flats, with respect to the white key:
    // for instance, 1 means one sharp above the white key; -2 means one double flat below the white key) <br />
    // <b>jiplof</b> (the "PLOF", or Pitch in the Line of Fifths, that is,
    // an integer counting how many Pythagorean fifths above C0 the just intonation part is:
    // for example, 4 means E{}2; -1 means F{}-1 or, equivalently, -G{}0) <br />
    // <b>commas</b> (a list containing a vector of HEJI commas for the just intonation part) <br />
    // <b>jiratio</b> (a rational expressing the frequency ratio of the just intonation part
    // with respect to C0:
    // for example, 3/2 means one Pythagorean fifth above C0, that is, G{}0) <br />
    // <b>monzo</b> (the Monzo vector of the just intonation part, that is,
    // the list of the prime-factor exponents that constitute the frequency ratio) <br />
    // So, for example, <m>from jiwhitekey commas octave</m> creates three inlets,
    // one for each corresponding symbol. <br />
    // If the attribute is not set, a single <b>pitch</b> inlet is created by default.
    // @copy BACH_DOC_STATIC_ATTR

    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

    class_register(CLASS_BOX, c);
    pitchobj_class = c;
    
    pitchobj_setkeys();
    
    dev_post("bach.pitch compiled %s %s", __DATE__, __TIME__);
    
    return;
}

t_max_err pitchobj_setattr_from(t_pitchobj *x, t_object *attr, long ac, t_atom *av) {
    if (ac && av && !x->n_ob.l_running) {
        int i;
        for (i = 0; i < ac && i < LLLL_MAX_INLETS; i++) {
            if (auto k = keys.find(atom_getsym(av + i)); k != keys.end()) {
                t_pitchKeys key = k->second;
                x->fromKeys[i] = key;
            } else {
                x->fromKeys[i] = p_NONE;
                object_error((t_object *) x, "Wrong \"from\" key at position %d", i + 1);
            }
        }
        if (i > x->nFromKeys)
            x->nFromKeys = i;
    }
    return MAX_ERR_NONE;
}

t_max_err pitchobj_setattr_to(t_pitchobj *x, t_object *attr, long ac, t_atom *av) {
    if (ac && av && !x->n_ob.l_running) {
        int i;
        for (i = 0; i < ac && i < LLLL_MAX_INLETS; i++) {
            if (auto k = keys.find(atom_getsym(av + i)); k != keys.end()) {
                t_pitchKeys key = k->second;
                x->toKeys[i] = key;
            } else {
                x->fromKeys[i] = p_NONE;
                object_error((t_object *) x, "Wrong \"to\" key at position %d", i + 1);
            }
        }
        if (i > x->nToKeys)
            x->nToKeys = i;
    }
    return MAX_ERR_NONE;
}

void pitchobj_bang(t_pitchobj *x)
{
    if (x->n_ob.l_rebuild) {
        t_pitch p = t_pitch::C0;
        for (int i = x->nFromKeys - 1; i >= 0; i--) {
            t_llll *ll = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i);
            if (ll->l_size != 0) {
                switch (x->fromKeys[i]) {
                    case p_PITCH: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        p += hatom_getpitch(h);
                        break;
                    }
                    case p_ETWHITEKEY: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        const t_atom_short l = (t_atom_short) hatom_getlong(h);
                        p += t_pitch(l);
                        break;
                    }
                    case p_ETALTER: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        const t_tinyRational r = (t_tinyRational) hatom_getrational(h);
                        p.p_alterET += r;
                        break;
                    }
                    case p_OCTAVE: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        const t_int8 i = (t_int8) hatom_getlong(h);
                        p.addOctaves(i);
                        break;
                    }
                    case p_JIWHITEKEY: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        const t_atom_long l = (t_int8) hatom_getlong(h);
                        const t_int8 plof = t_pitch::whiteKey2Plof_safe(l);
                        p += t_pitch(plof, std::vector<int8_t>(), 0);
                        break;
                    }
                    case p_JISHARPS: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        const t_atom_long l =  hatom_getlong(h);
                        const t_int8 plof = l * 7;
                        p += t_pitch(plof, std::vector<int8_t>(), 0);
                        break;
                    }
                    case p_JIPLOF: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        const t_atom_long plof = (t_int8) hatom_getlong(h);
                        p += t_pitch(plof, std::vector<int8_t>(), 0);
                        break;
                    }
                    case p_COMMAS: {
                        int i;
                        t_llllelem *el;
                        std::vector<int8_t> commas;
                        for (el = ll->l_head, i = 0; el && i < BACH_PRIMES_JI_SIZE - 2; el = el->l_next) {
                            const int8_t c = (int8_t) hatom_getlong(&el->l_hatom);
                            commas.push_back(c);
                        }
                        p += t_pitch(0, commas, 0);
                        break;
                    }
                    case p_JIRATIO: {
                        const t_hatom *h = &ll->l_head->l_hatom;
                        const t_rational r =  hatom_getrational(h);
                        p += t_pitch(r);
                        break;
                    }
                    case p_MONZO: {
                        int i;
                        t_llllelem *el;
                        std::vector<int8_t> monzo;
                        for (el = ll->l_head, i = 0; el && i < BACH_PRIMES_JI_SIZE; el = el->l_next) {
                            const int8_t e = (int8_t) hatom_getlong(&el->l_hatom);
                            monzo.push_back(e);
                        }
                        p += t_pitch(monzo);
                        break;
                    }
                    default:
                        break;
                }
                llll_release(ll);
            }
        }
        
        for (int i = x->nToKeys - 1; i >= 0; i--) {
            t_llll *ll;
            switch (x->toKeys[i]) {
                case p_PITCH: {
                    ll = llll_get();
                    llll_appendpitch(ll, p);
                    break;
                }
                case p_ETWHITEKEY: {
                    ll = llll_get();
                    llll_appendlong(ll, p.getWhiteKeyET());
                    break;
                }
                case p_ETALTER: {
                    ll = llll_get();
                    llll_appendrat(ll, p.getAlterET());
                    break;
                }
                case p_OCTAVE: {
                    ll = llll_get();
                    llll_appendlong(ll, p.getOctave());
                    break;
                }
                case p_JIWHITEKEY: {
                    ll = llll_get();
                    llll_appendlong(ll, p.getWhiteKeyJI());
                    break;
                }
                case p_JISHARPS: {
                    ll = llll_get();
                    llll_appendlong(ll, p.getSharpsJI());
                    break;
                }
                case p_JIPLOF: {
                    ll = llll_get();
                    llll_appendlong(ll, p.getPlofJI());
                    break;
                }
                case p_COMMAS: {
                    ll = getHEJICommas(p);
                    break;
                }
                case p_JIRATIO: {
                    ll = llll_get();
                    llll_appendrat(ll, p.getJIRatio());
                    break;
                }
                case p_MONZO: {
                    ll = getMonzo(p);
                    break;
                }
                default: {
                    ll = llll_get();
                    break;
                }
            }
            llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, i);
        }
    }
        
    for (int i = x->nToKeys - 1; i >= 0; i--) {
        llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
    }
}

void pitchobj_int(t_pitchobj *x, t_atom_long num){
    t_atom argv[1];
    atom_setlong(argv, num);
    pitchobj_anything(x, _llllobj_sym_list, 1, argv);
}

void pitchobj_float(t_pitchobj *x, double num){
    t_atom argv[1];
    atom_setfloat(argv, num);
    pitchobj_anything(x, _llllobj_sym_list, 1, argv);
}

void pitchobj_anything(t_pitchobj *x, t_symbol *msg, long ac, t_atom *av)
{
    
    long inlet = proxy_getinlet((t_object *) x);
    
    llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
    x->n_ob.l_rebuild = 1;
    
    if (inlet == 0)
        pitchobj_bang(x);
}


void pitchobj_assist(t_pitchobj *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) { // @in 0 @type llll @digest pitch data
        // @description The llll containing the pitch data to be processed
        t_symbol *sym = nullptr;
        for (auto k: keys) {
            if (k.second == x->fromKeys[a]) {
                sym = k.first;
                break;
            }
        }
        if (sym) {
            snprintf_zero(s, 64, "llll: %s", sym->s_name);
        }
    } else {
        char *type = NULL; // @out 0 @type llll @digest pitch data
        // @description The llll containing the pitch data
        t_symbol *sym = nullptr;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        for (auto k: keys) {
            if (k.second == x->toKeys[a]) {
                sym = k.first;
                break;
            }
        }
        if (sym) {
            snprintf_zero(s, 64, "llll (%s): %s", type, sym->s_name);
        }
    }
}

void pitchobj_inletinfo(t_pitchobj *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}


void pitchobj_free(t_pitchobj *x)
{
    long i;
    for (i = x->nFromKeys - 1; i > 0; i--)
        object_free_debug(x->proxies[i]);
    bach_freeptr(x->proxies);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_pitchobj *pitchobj_new(t_symbol *s, short ac, t_atom *av)
{
    t_pitchobj *x = NULL;
    t_max_err err = MAX_ERR_NONE;
    
    if ((x = (t_pitchobj *) object_alloc_debug(pitchobj_class))) {
        attr_args_process(x, ac, av);
        if (x->nFromKeys == 0) {
            x->nFromKeys = 1;
            x->fromKeys[0] = p_PITCH;
        }
        if (x->nToKeys == 0) {
            x->nToKeys = 1;
            x->toKeys[0] = p_PITCH;
        }
        char outTypes[LLLL_MAX_INLETS + 1];
        memset(outTypes, '4', x->nToKeys);
        outTypes[x->nToKeys] = 0;
        llllobj_obj_setup((t_llllobj_object *) x, x->nFromKeys, outTypes);
        x->proxies = (void **) bach_newptr((x->nFromKeys + 1) * sizeof(void *));
        for (int i = x->nFromKeys - 1; i > 0; i--)
            x->proxies[i] = proxy_new_debug((t_object *) x, i, &x->inlet);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x);
    return NULL;
}

