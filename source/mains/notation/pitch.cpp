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
    pitchobj.c
    
    @name
    bach.pitchobj
    
    @realname
    bach.pitchobj

    @type
    object
    
    @module
    bach

    @author
    bachproject
    
    @digest
    Pitches to MIDIcents conversion
    
    @description
    Converts an llll containing pitches into the corresponding llll of MIDIcents.
    
    @discussion
    bach.pitchobj accepts microtones following the ASCII convention used throughout bach. <br />
    @copy BACH_DOC_ASCII_ACCIDENTALS_SYNTAX
    
    @category
    bach, bach objects, bach notation, bach pitches

    @keywords
    convert, midicent, cent, note, name

    @seealso
    bach.mc2p, bach.f2mc, bach.mc2f, bach.approx
    
    @owner
    Daniele Ghisi
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
    struct llllobj_object     n_ob;
    t_pitchKeys fromKeys[LLLL_MAX_INLETS];
    int nFromKeys;
    t_pitchKeys toKeys[LLLL_MAX_INLETS];
    int nToKeys;
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


std::unordered_map<std::string, t_pitchKeys> keys;

void pitchobj_setkeys() {
    keys["pitch"] = p_PITCH;
    keys["etwhitekey"] = p_ETWHITEKEY;
    keys["etalter"] = p_ETALTER;
    keys["octave"] = p_OCTAVE;
    keys["jiwhitekey"] = p_JIWHITEKEY;
    keys["jisharps"] = p_JISHARPS;
    keys["jiplof"] = p_JIPLOF;
    keys["commas"] = p_COMMAS;
    keys["jiratio"] = p_JIRATIO;
    keys["monzo"] = p_MONZO;
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
    
    // @method llll @digest Convert pitches to midicents
    // @description The function outputs an llll formatted as the incoming one, but containing the midicents values
    // instead of each pitch.
    class_addmethod(c, (method)pitchobj_anything,                    "anything",                A_GIMME,    0);
    class_addmethod(c, (method)pitchobj_int,                        "int",                    A_LONG,        0);
    class_addmethod(c, (method)pitchobj_float,                        "float",                A_FLOAT,    0);
    class_addmethod(c, (method)pitchobj_anything,                    "list",                    A_GIMME,    0);

    // @method bang @digest Perform the conversion.
    // @description Perform the conversion on the most recently received input data.
    class_addmethod(c, (method)pitchobj_bang,                        "bang",        0);
    
    class_addmethod(c, (method)pitchobj_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)pitchobj_inletinfo,    "inletinfo",    A_CANT,        0);

    CLASS_ATTR_SYM_VARSIZE(c, "from", 0, t_pitchobj, dummySym, dummyLong, LLLL_MAX_INLETS);
    CLASS_ATTR_ACCESSORS(c, "from", nullptr, pitchobj_setattr_from);
    CLASS_ATTR_INVISIBLE(c, "from", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE_USER);

    CLASS_ATTR_SYM_VARSIZE(c, "to", 0, t_pitchobj, dummySym, dummyLong, LLLL_MAX_INLETS);
    CLASS_ATTR_ACCESSORS(c, "to", nullptr, pitchobj_setattr_to);
    CLASS_ATTR_INVISIBLE(c, "to", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE_USER);
    
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
            if (auto k = keys.find(atom_getsym(av + i)->s_name); k != keys.end()) {
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
            if (auto k = keys.find(atom_getsym(av + i)->s_name); k != keys.end()) {
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
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
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

    
    
    t_llll *inlist;


    if (msg != _sym_bang) {
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        x->n_ob.l_rebuild = 1;
    }

    //inlist = llllobj_get_store_contents((t_object *) x, 
    if (inlist)
        llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, inlist, 0);
    
    x->n_ob.l_rebuild = 0;
    pitchobj_bang(x);
}


void pitchobj_assist(t_pitchobj *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll containing the pitches
        sprintf(s, "llll: Pitches");
    } else {
        char *type = NULL; // @out 0 @type llll @digest The llll containing the MIDIcents
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        sprintf(s, "llll (%s): Cents", type);
    }
}

void pitchobj_inletinfo(t_pitchobj *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}


void pitchobj_free(t_pitchobj *x)
{
    llllobj_obj_free((t_llllobj_object *) x);
}

t_pitchobj *pitchobj_new(t_symbol *s, short ac, t_atom *av)
{
    t_pitchobj *x = NULL;
    t_max_err err = MAX_ERR_NONE;
    
    if ((x = (t_pitchobj *) object_alloc_debug(pitchobj_class))) {
        attr_args_process(x, ac, av);
        char outTypes[LLLL_MAX_INLETS + 1];
        memset(outTypes, '4', x->nToKeys);
        outTypes[x->nToKeys] = 0;
        llllobj_obj_setup((t_llllobj_object *) x, x->nFromKeys, outTypes);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x);
    return NULL;
}

