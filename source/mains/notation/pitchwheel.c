/*
 *  pitchwheel.c
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
    pitchwheel.c
    
    @name 
    bach.pitchwheel
    
    @realname 
    bach.pitchwheel

    @type
    object
    
    @module
    bach

    @author
    bachproject
    
    @digest 
    Pitch clock diagram
    
    @description
    The purpose of <o>bach.pitchwheel</o> is to act as a simple clock diagram displaying
    pitches, especially for just intonation applications.
 
    @category
    bach, bach objects, bach just intonation, bach interface, U/I
    
    @keywords
    pitchwheel, diagram, clock, just intonation, ratio, Helmholtz-Ellis, wheel, rotate,

    @palette
    YES
    
    @palette category
    bach, bach objects, bach just intonation, bach interface

    @seealso
    bach.primeform, bach.pcsetinfo, bach.mod+, bach.mod-, bach.modtimes, bach.compl
    
    @owner
    Daniele Ghisi
*/


#include "math/llll_settheory.h"
#include "graphics/bach_graphics.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "ext_critical.h"
#include "ext_strings.h"
#include "ext_boxstyle.h"

#define PITCHWHEEL_MAX_ZOOM 10000000
#define PITCHWHEEL_LIMIT_RADIUS_FOR_LINE 30000
#define PITCHWHEEL_MAX_ACCIDENTALS 10

const long fareylengths[] = {2,3,5,7,11,13,19,23,29,43,47,59,73,97,103,151,
    173,181,271,397,433,491,883,941,1087,1103,1163,
    1193,1229,1427,1471,1697,2143,2273,2657,2903,3533,
    3677,4073,4129,4201,4259,4637,5023,5107,5953,6163,
    6599,7177,7237};

const double ezprimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
const long num_ezprimes = 25;
const double commalimits[] = {5, 7, 11, 13, 17, 19, 23};
const t_rational commas[] = {genrat(81, 80), genrat(64, 63), genrat(33, 32), genrat(27, 26), genrat(2187, 2176), genrat(513, 512), genrat(736,729)};
const long numcommas = 7;

typedef struct _wheelpitch
{
    char        type; // 1 if pitch is a JI ratio, 0 if it's a ET
    t_rational  ratio;
    double      cents;
    long        limit;
    long        pythagorean_index; // position in the circle of fifths
    long        maxexp; // maximum exponent
    double      angle;
    double      importance;
    
    long        pyth_diatonic_step; // 0 = C, 1 = D, 2 = E, 3 = F, 4 = G, 5 = A, 6 = B
    long        pyth_accidentals_as_long; // 0 = natural, 1 = sharp, 2 = doublesharp, etc., -1 = flat, etc.
    unicodeChar pyth_accidentals[PITCHWHEEL_MAX_ACCIDENTALS+1];
    long        num_pyth_accidentals; // length of the unicode string above
    unicodeChar accidentals[PITCHWHEEL_MAX_ACCIDENTALS+2]; // the +2 is needed to account for an overflow character if needed
    long        num_accidentals; // length of the unicode string above
    bool        purely_pythagorean;
    bool        accidentals_overflow; // can't represent ratio with accidentals
    
    // volatile
    bool        shown;
    double      curr_normalized_importance;
} t_wheelpitch;

enum {
    BACH_PITCHWHEEL_MODE_MAXDEN = 0,
    BACH_PITCHWHEEL_MODE_JILIMITS = 1,
};

enum {
    BACH_PITCHWHEEL_PITCHTYPE_ET = 0,
    BACH_PITCHWHEEL_PITCHTYPE_JI = 1,
};

enum {
    BACH_PITCHWHEEL_DISPLAY_RATIO = 0,
    BACH_PITCHWHEEL_DISPLAY_ACCIDENTALS = 1,
};

enum {
    BACH_PITCHWHEEL_TEXT_UPRIGHT = 0,
    BACH_PITCHWHEEL_TEXT_ANGULAR = 1,
    BACH_PITCHWHEEL_TEXT_RADIAL = 2,
};

enum {
    BACH_PITCHWHEEL_COLORMODE_PLAIN = 0,
    BACH_PITCHWHEEL_COLORMODE_LIMIT = 1,
    BACH_PITCHWHEEL_COLORMODE_MAXEXP = 2,
    BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANCHROMATICNOTE = 3,
    BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANDIATONICNOTE = 4,
};

typedef struct _pitchwheel // [bach.pitchwheel] structure
{
    t_llllobj_jbox            j_box; // root object

    t_jrgba                    j_textcolor;
    t_jrgba                    j_bgcolor;
    t_jrgba                    j_bordercolor;
    t_jrgba                    j_linecolor;
    
    double                  rotation_angle; // for main wheel (pitch wheel)
    double                  rotation_angle_intwheel;
    double                  zoom;
    double                  zoom_angle;
    t_rational              octave_interval;

    char                    mode; // 0 = up to a maxden; 1 = JI limits combination;
    char                    display_mapping;
    char                    display_what; //see enum above
    char                    color_mode;
    char                    text_direction;
    char                    rotate_for_legibility;
    char                    boost_diatonic;
    char                    boost_pythagorean;
    char                    boost_et;

    char                    j_has_focus;
    char                    show_focus;
    double                  inset;
    
    t_pt                    mousedrag_pt;
    t_symbol                *importance_sym;

    t_symbol                *base_diatonic_pitch; // whitekey pitch used as a basis (letter)
    t_wheelpitch            *curr_pitches;
    long                    num_pitches;
    
    // show/hide
    char                    show_ticks;
    char                    show_ratios;
    char                    show_et_wheel;
    char                    show_integers_wheel;
    char                    show_circles;

    double                  tick_length;
    double                  et_wheel_size;
    double                  int_wheel_size;
    char                    avoid_collisions;
    double                  minfactor;
    
    char                    rebuild;

    t_lexpr                 *n_importance_lexpr;
    
    void                    *n_proxy[3];
    long                    n_in;
    
    t_jrgba                 candycane1;
    t_jrgba                 candycane2;
    t_jrgba                 candycane3;
    t_jrgba                 candycane4;
    t_jrgba                 candycane5;
    t_jrgba                 candycane6;
    t_jrgba                 candycane7;
    t_jrgba                 candycane8;
    t_jrgba                 candycane9;
    t_jrgba                 candycane10;
    t_jrgba                 candycane11;
    t_jrgba                 candycane12;
    t_jrgba                 candycane13;
    t_jrgba                 candycane14;
    t_jrgba                 candycane15;
    t_jrgba                 candycane16;
    t_jrgba                 candycane17;
    t_jrgba                 candycane18;
    t_jrgba                 candycane19;
    t_jrgba                 candycane20;

    t_symbol                *accidentals_font;
    double                  accidentals_font_size;

//    t_symbol                *textfont;
//    double                    textsize;
    
    t_systhread_mutex        c_mutex;

} t_pitchwheel;


// global class pointer variable
t_class    *s_pitchwheel_class = NULL;

// functions
void pitchwheel_inletinfo(t_pitchwheel *x, void *b, long a, char *t);
void pitchwheel_assist(t_pitchwheel *x, void *b, long m, long a, char *s);

void pitchwheel_free(t_pitchwheel *x);

void pitchwheel_focusgained(t_pitchwheel *x, t_object *patcherview);
void pitchwheel_focuslost(t_pitchwheel *x, t_object *patcherview);
void pitchwheel_mousedown(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void pitchwheel_mousemove(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void pitchwheel_mouseup(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void pitchwheel_mousedrag(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void pitchwheel_mousewheel(t_pitchwheel *x, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc);
long pitchwheel_key(t_pitchwheel *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);
t_max_err pitchwheel_notify(t_pitchwheel *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

t_pitchwheel* pitchwheel_new(t_symbol *s, long argc, t_atom *argv);

void pitchwheel_paint(t_pitchwheel *x, t_object *view);

void pitchwheel_anything(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv);
void pitchwheel_dump(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv);
void pitchwheel_int(t_pitchwheel *x, t_atom_long num);
void pitchwheel_float(t_pitchwheel *x, double num);
void pitchwheel_bang(t_pitchwheel *x);
void pitchwheel_preset(t_pitchwheel *x);

void pitchwheel_importance(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv);
t_max_err pitchwheel_setattr_importance(t_pitchwheel *x, void *attr, long ac, t_atom *av);

void get_radius_and_center(t_pitchwheel *x, t_object *patcherview, double *radius, double *center_x, double *center_y);




t_jrgba pitchwheel_long_to_color(t_pitchwheel *x, long value)
{
    if (value == LONG_MAX) {
        return x->j_textcolor;
    }
    
    switch (positive_mod(value, 10)) {
        case 0:
            return x->candycane1;
        case 1:
            return x->candycane2;
        case 2:
            return x->candycane3;
        case 3:
            return x->candycane4;
        case 4:
            return x->candycane5;
        case 5:
            return x->candycane6;
        case 6:
            return x->candycane7;
        case 7:
            return x->candycane8;
        case 8:
            return x->candycane9;
        default:
            return x->candycane10;
    }
    return x->j_textcolor;
}


long num_to_prime_idx(long num)
{
    for (long i = 0; i < num_ezprimes; i++)
        if (ezprimes[i] == num)
            return i;

    return -1;
}

void pitchwheel_bang(t_pitchwheel *x)
{
    if (x->j_box.l_rebuild == 1 || proxy_getinlet((t_object *) x) != 0)
        pitchwheel_anything(x, _sym_bang, 0, NULL);
}

void pitchwheel_preset(t_pitchwheel *x)
{
/*    long ac = x->num_points * 2 + 1;
    t_atom *av = (t_atom *) bach_newptr(ac * sizeof(t_atom)); 
    long i;
    void *preset_buf;// Binbuf that stores the preset 
    short atomCount;
    t_atom *atomArray; // array of atoms to be stored 
    for (i = 0; i < x->num_points; i++){
        atom_setlong(av + 2*i, x->points[i]);
        atom_setlong(av + 2*i+1, x->vels[i]);
    }
    atom_setlong(av + 2 * x->num_points, x->modulo);
    
    atomCount = (short)(ac + 3); // number of atoms we’re storing 
    atomArray = (t_atom *) bach_newptr(atomCount * sizeof(t_atom));
    // 1. prepare the preset "header" information 
    atom_setobj(atomArray,x); 
    atom_setsym(atomArray+1,ob_sym(x)); 
    atom_setsym(atomArray+2, _llllobj_sym_setinterleaved); 
    memcpy(atomArray+3, av, ac*sizeof(t_atom));
    // fill atomArray+3 with object’s state here and set atomCount 
    // 2. find the Binbuf 
    preset_buf = _sym__preset->s_thing; 
    // 3. store the data 
    if (preset_buf) { 
        binbuf_insert(preset_buf, NULL, atomCount, atomArray); 
    } 
    
    if (av) bach_freeptr(av);
    bach_freeptr(atomArray);
 */
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

    CLASS_NEW_CHECK_SIZE(c, "bach.pitchwheel",
                        (method)pitchwheel_new,
                        (method)pitchwheel_free,
                        sizeof(t_pitchwheel),
                        (method)NULL,
                        A_GIMME,
                        0L);
    
    c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//    jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
    jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FIXWIDTH);    // include textfield and Fonts attributes
    jbox_initclass(c, 0);
    
    class_addmethod(c, (method) pitchwheel_paint,            "paint", A_CANT, 0);

    // @method llll @digest Set points and/or velocities (depending on inlet)
    // @description 
    // In first inlet: a plain list sets the points: each point is given as per its index, 0 being the upper one, and then clockwise. 
    // An interlaced such as [(<m>pt1</m> <m>vel1</m>) (<m>pt2</m> <m>vel2</m>)...] sets both points and velocities. <br />
    // In second inlet: Sets the velocities for the points you'll send in the first inlet later.
    class_addmethod(c, (method) pitchwheel_anything, "anything", A_GIMME, 0);
    class_addmethod(c, (method) pitchwheel_anything, "list", A_GIMME, 0);

    // @method dump @digest Output all data
    // @description 
    // Send: <br />
    // - the modulo from the third outlet; <br />
    // - all the velocities from the second outlet, as a plain list; <br />
    // - all the points from the first outlet, as a plain list.
    class_addmethod(c, (method) pitchwheel_dump, "dump", A_GIMME, 0);


    class_addmethod(c, (method) pitchwheel_int, "int", A_LONG, 0);
    class_addmethod(c, (method) pitchwheel_float, "float", A_FLOAT, 0);

    class_addmethod(c, (method) pitchwheel_bang, "bang", 0);

    // @method clear @digest Clear the diagram
    // @description Clear all the points of the diagram
    class_addmethod(c, (method) pitchwheel_anything, "clear", A_GIMME, 0);

    // @method (mouse) @digest Add/delete points, or change their velocities
    // @description 
    // • <m>click</m>: Add a point <br />
    // • <m>Alt+click</m>: Output clicked point index, in the form <b>point <m>pt</m></b>, where <m>pt</m> is as usual the point index. <br />
    // • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win): Delete a point <br />
    // • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win): Change the velocity of a point (dragging up or down) <br /> 
    // • <m>Ctrl+Alt+click+drag</m> (mac) or <m>Shift+Ctrl+Alt+click+drag</m> (win): Change the modulo (dragging up or down)
    class_addmethod(c, (method) pitchwheel_mousedown, "mousedown", A_CANT, 0);
    class_addmethod(c, (method) pitchwheel_mousedrag, "mousedrag", A_CANT, 0);
    class_addmethod(c, (method) pitchwheel_mouseup, "mouseup", A_CANT, 0);
    class_addmethod(c, (method) pitchwheel_mousemove, "mousemove", A_CANT, 0);
    class_addmethod(c, (method) pitchwheel_mousewheel, "mousewheel", A_CANT, 0);

    class_addmethod(c, (method) pitchwheel_notify, "bachnotify", A_CANT, 0);

    // @method (keyboard) @digest Modify points or dump
    // @description 
    // • <m>Cmd+T</m> (mac) or <m>Ctrl+T</m> (win): Transpose (rotate) 1 step clockwise <br />
    // • <m>Cmd+R</m> (mac) or <m>Ctrl+R</m> (win): Transpose (rotate) 1 step counterclockwise <br />
    // • <m>Cmd+C</m> (mac) or <m>Ctrl+C</m> (win): Take the complement <br />
    // • <m>Cmd+I</m> (mac) or <m>Ctrl+I</m> (win): Invert with respect to vertical axis <br />
    // • <m>Cmd+Shift+D</m> (mac) or <m>Ctrl+Shift+D</m> (win): Dump (output modulo, velocities and points)
      class_addmethod(c, (method) pitchwheel_key, "key", A_CANT, 0);

    class_addmethod(c, (method) pitchwheel_preset, "preset", 0);

    class_addmethod(c, (method) pitchwheel_focusgained, "focusgained", A_CANT, 0);
    class_addmethod(c, (method) pitchwheel_focuslost, "focuslost", A_CANT, 0);

    class_addmethod(c, (method) pitchwheel_inletinfo, "inletinfo", A_CANT, 0);
    class_addmethod(c, (method) pitchwheel_assist, "assist", A_CANT, 0);

    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_UI);

    CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 500 500"); // new dimensions
    // @exclude bach.pitchwheel
    CLASS_ATTR_DEFAULT(c, "fontsize", 0, "24"); // new font size
    // @exclude bach.pitchwheel

    
    CLASS_STICKY_ATTR(c,"category",0,"Color");

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "textcolor", 0, t_pitchwheel, j_bgcolor, "Text Color", "text_number");
        CLASS_ATTR_LEGACYDEFAULT(c, "textcolor", "textcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_BASIC(c, "textcolor", 0);
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"textcolor", "numberstextcolor");
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"textcolor", "modulotextcolor");
        // @exclude all
#else
        CLASS_ATTR_RGBA(c, "textcolor", 0, t_pitchwheel, j_textcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
        // @description Color of the text.
#endif

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "bgcolor", 0, t_pitchwheel, j_bgcolor, "Background Color", "rect_fill");
        CLASS_ATTR_LEGACYDEFAULT(c, "bgcolor", "bgcolor", 0, "1. 1. 1. 1.");
        CLASS_ATTR_BASIC(c, "bgcolor", 0);
        // @description Diagram external background color
#else
        CLASS_ATTR_RGBA(c, "bgcolor", 0, t_pitchwheel, j_bgcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "1. 1. 1. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
        CLASS_ATTR_BASIC(c, "bgcolor",0);
#endif

        CLASS_ATTR_RGBA(c, "bordercolor", 0, t_pitchwheel, j_bordercolor);
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0. 0. 0. 0.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0.2 0.2 0.2 1.");
#endif
        CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");
        // @description Color of the diagram border

    CLASS_STICKY_ATTR_CLEAR(c, "category");


    CLASS_STICKY_ATTR(c,"category",0,"Show");
    
        CLASS_ATTR_CHAR(c,"showfocus",0, t_pitchwheel, show_focus);
        CLASS_ATTR_STYLE_LABEL(c,"showfocus",0,"onoff","Show Focus");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showfocus",0,"1");
        // @description Show that the object has the focus by increasing the width of the border.
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    CLASS_STICKY_ATTR(c, "category", 0, "Font");
    
        CLASS_ATTR_SYM(c,"accidentalsfont", 0, t_pitchwheel, accidentals_font);
        CLASS_ATTR_STYLE_LABEL(c, "accidentalsfont",0,"font","Accidentals Font");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"accidentalsfont", 0, "\"Bravura\"");
        // @description @copy BACH_DOC_ACCIDENTALS_FONT

        CLASS_ATTR_DOUBLE(c,"accidentalsfontsize", 0, t_pitchwheel, accidentals_font_size);
        CLASS_ATTR_STYLE_LABEL(c, "accidentalsfontsize",0,"text","Accidentals Font");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"accidentalsfontsize", 0, "24");
        // @description Sets the maximum size of the accidentals (in pt).

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c, "category", 0, "Settings");

        CLASS_ATTR_SYM(c, "basis", 0, t_pitchwheel, base_diatonic_pitch);
        CLASS_ATTR_STYLE_LABEL(c,"basis",0,"text","Basis Diatonic Pitch");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"basis",0,"C");
        CLASS_ATTR_BASIC(c,"basis",0);
        // @description Sets the diatonic pitch corresponding to the 1/1 ratio (as one of the letters A through G).

        CLASS_ATTR_CHAR(c, "display", 0, t_pitchwheel, display_what);
        CLASS_ATTR_STYLE_LABEL(c,"display",0,"enumindex","Display");
        CLASS_ATTR_ENUMINDEX(c,"display", 0, "Ratios Accidentals");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"display",0,"0");
        CLASS_ATTR_BASIC(c,"display",0);
        // @description Decides what to display: 0 (Ratios) or 1 (Accidentals).

        CLASS_ATTR_CHAR(c, "mode", 0, t_pitchwheel, mode);
        CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
        CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Maximum Denominator Just Intonation Commas");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mode",0,"0");
        CLASS_ATTR_BASIC(c,"mode",0);
        // @description Sets the representation mode: either up to a maximum denominator (0) or by combining just intonation commas (1)

        CLASS_ATTR_CHAR(c, "mapping", 0, t_pitchwheel, display_mapping);
        CLASS_ATTR_STYLE_LABEL(c,"mapping",0,"enumindex","Mapping");
        CLASS_ATTR_ENUMINDEX(c,"mapping", 0, "Pitch Frequency");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mapping",0,"0");
        CLASS_ATTR_BASIC(c,"mapping",0);
        // @description Sets the mapping: either linear in pitch (0) or linear in frequency (1)

        CLASS_ATTR_SYM(c, "importance", 0, t_pitchwheel, importance_sym);
        CLASS_ATTR_STYLE_LABEL(c,"importance",0,"text","Importance");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"importance",0,"0");
        CLASS_ATTR_ACCESSORS(c, "importance", (method)NULL, (method)pitchwheel_setattr_importance);
        // @description Sets the formula defining how important is each fraction. You can use as variables
        // "num" (numerator), "den" (denominator), "min" (min between the two), "max" (max between the two), "limit" (prime limit of the fraction),
        // and "maxexp" (largest power of each limit > 2).
    
        CLASS_ATTR_CHAR(c, "hidecollisions", 0, t_pitchwheel, avoid_collisions);
        CLASS_ATTR_STYLE_LABEL(c,"hidecollisions",0,"onoff","Hide Collisions");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hidecollisions",0,"1");
        // @description Toggles the ability to hide labels when colliding with others

        CLASS_ATTR_CHAR(c, "boostdiatonic", 0, t_pitchwheel, boost_diatonic);
        CLASS_ATTR_STYLE_LABEL(c,"boostdiatonic",0,"onoff","Boost Diatonic Pitches");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"boostdiatonic",0,"1");
        // @description If set, boosts the importance of diatonic pitches

        CLASS_ATTR_CHAR(c, "boostpythagorean", 0, t_pitchwheel, boost_pythagorean);
        CLASS_ATTR_STYLE_LABEL(c,"boostpythagorean",0,"onoff","Boost Pythagorean Pitches");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"boostpythagorean",0,"1");
        // @description If set, boosts the importance of purely Pythagorean pitches

        CLASS_ATTR_CHAR(c, "boostet", 0, t_pitchwheel, boost_et);
        CLASS_ATTR_STYLE_LABEL(c,"boostet",0,"onoff","Boost Equally-Tempered Pitches");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"boostet",0,"1");
        // @description If set, boosts the importance of equally-tempered pitches

    
    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c, "category", 0, "Show");

        CLASS_ATTR_CHAR(c, "showcircles", 0, t_pitchwheel, show_circles);
        CLASS_ATTR_STYLE_LABEL(c,"showcircles",0,"onoff","Show Circles");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showcircles",0,"0");
        // @description Toggles the display of the circles

        CLASS_ATTR_CHAR(c, "showetwheel", 0, t_pitchwheel, show_et_wheel);
        CLASS_ATTR_STYLE_LABEL(c,"showetwheel",0,"onoff","Show Equal-Temperament Wheel");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showetwheel",0,"1");
        // @description Toggles the display of the equal temperament wheel as a reference
    
        CLASS_ATTR_CHAR(c, "showintwheel", 0, t_pitchwheel, show_integers_wheel);
        CLASS_ATTR_STYLE_LABEL(c,"showintwheel",0,"onoff","Show Integers Wheel");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showintwheel",0,"1");
        // @description Toggles the display of the integers wheel

    
        CLASS_ATTR_CHAR(c, "showticks", 0, t_pitchwheel, show_ticks);
        CLASS_ATTR_STYLE_LABEL(c,"showticks",0,"onoff","Show Ticks");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showticks",0,"1");
        // @description Toggles the display of the ticks

        CLASS_ATTR_CHAR(c, "showfractions", 0, t_pitchwheel, show_ratios);
        CLASS_ATTR_STYLE_LABEL(c,"showfractions",0,"onoff","Show Fractions");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showfractions",0,"1");
        // @description Toggles the display of the fractions

    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    
    CLASS_STICKY_ATTR(c, "category", 0, "Appearance");

        CLASS_ATTR_CHAR(c, "direction", 0, t_pitchwheel, text_direction);
        CLASS_ATTR_STYLE_LABEL(c,"direction",0,"enumindex","Text And Accidentals Direction");
        CLASS_ATTR_ENUMINDEX(c,"direction", 0, "Upright Angular Radial");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"direction",0,"1");
        // @description Sets the direction for text and accidentals: upright (0), angular (1) or radial (2)

        CLASS_ATTR_CHAR(c, "autoturn", 0, t_pitchwheel, rotate_for_legibility);
        CLASS_ATTR_STYLE_LABEL(c,"autoturn",0,"onoff","Rotate For Legibility");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autoturn",0,"1");
        // @description Toggles the ability to rotate the text for legibility

        
        CLASS_ATTR_DOUBLE(c, "minfactor", 0, t_pitchwheel, minfactor);
        CLASS_ATTR_STYLE_LABEL(c,"minfactor",0,"text","Minimum Reduction Factor");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minfactor",0,"0.3");
        // @description Sets the minimum reduction factor for importance.

        CLASS_ATTR_CHAR(c, "colormode", 0, t_pitchwheel, color_mode);
        CLASS_ATTR_STYLE_LABEL(c,"colormode",0,"enumindex","Color Mode");
        CLASS_ATTR_ENUMINDEX(c,"colormode", 0, "Plain Limit Max Exponent Pythagorean Chromatic Note Pythagorean Diatonic Note");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"colormode",0,"1");
        CLASS_ATTR_BASIC(c,"colormode",0);
        // @description Sets the color mode.

        CLASS_ATTR_DOUBLE(c, "ticklength", 0, t_pitchwheel, tick_length);
        CLASS_ATTR_STYLE_LABEL(c,"ticklength",0,"text","Maximum Tick Length");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ticklength",0,"40");
        // @description Sets the maximum tick length.

        CLASS_ATTR_DOUBLE(c, "etwheelsize", 0, t_pitchwheel, et_wheel_size);
        CLASS_ATTR_STYLE_LABEL(c,"etwheelsize",0,"text","Equal-Temperament Wheel Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"etwheelsize",0,"30");
        // @description Sets the radial size of the equal-temperament wheel.

        CLASS_ATTR_DOUBLE(c, "intwheelsize", 0, t_pitchwheel, int_wheel_size);
        CLASS_ATTR_STYLE_LABEL(c,"intwheelsize",0,"text","Integers Wheel Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"intwheelsize",0,"20");
        // @description Sets the radial size of the integers wheel.

        CLASS_ATTR_DOUBLE(c,"inset",0, t_pitchwheel, inset);
        CLASS_ATTR_STYLE_LABEL(c,"inset",0,"text","Inset");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"inset",0,"20.");
        // @description Inset of the clock diagram with respect to the border, in pixels

        CLASS_ATTR_DOUBLE(c,"zoom",0, t_pitchwheel, zoom);
        CLASS_ATTR_STYLE_LABEL(c,"zoom",0,"text","Zoom");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"zoom",0,"100.");
        // @description Zoom percentage.

    {
        CLASS_ATTR_RGBA(c, "candycane1", 0, t_pitchwheel, candycane1);
        CLASS_ATTR_STYLE_LABEL(c,"candycane1",0,"rgba","Candycane Color 1");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane1", 0, "0.77 0.11 0. 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane2", 0, t_pitchwheel, candycane2);
        CLASS_ATTR_STYLE_LABEL(c,"candycane2",0,"rgba","Candycane Color 2");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane2", 0, "0.51 0.41 0. 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane3", 0, t_pitchwheel, candycane3);
        CLASS_ATTR_STYLE_LABEL(c,"candycane3",0,"rgba","Candycane Color 3");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane3", 0, "0. 0.53 0.03 1.0");
        // @description Sets one of the candycane colors

        CLASS_ATTR_RGBA(c, "candycane4", 0, t_pitchwheel, candycane4);
        CLASS_ATTR_STYLE_LABEL(c,"candycane4",0,"rgba","Candycane Color 4");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane4", 0, "0.88 0.42 0.4 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane5", 0, t_pitchwheel, candycane5);
        CLASS_ATTR_STYLE_LABEL(c,"candycane5",0,"rgba","Candycane Color 5");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane5", 0, "0.05 0.62 0.87 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane6", 0, t_pitchwheel, candycane6);
        CLASS_ATTR_STYLE_LABEL(c,"candycane6",0,"rgba","Candycane Color 6");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane6", 0, "0. 0. 0.81 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane7", 0, t_pitchwheel, candycane7);
        CLASS_ATTR_STYLE_LABEL(c,"candycane7",0,"rgba","Candycane Color 7");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane7", 0, "0. 0.61 0.42 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane8", 0, t_pitchwheel, candycane8);
        CLASS_ATTR_STYLE_LABEL(c,"candycane8",0,"rgba","Candycane Color 8");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane8", 0, "0.68 0.77 0. 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane9", 0, t_pitchwheel, candycane9);
        CLASS_ATTR_STYLE_LABEL(c,"candycane9",0,"rgba","Candycane Color 9");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane9", 0, "0.53 0. 0.59 1.0");
        // @description Sets one of the candycane colors

        CLASS_ATTR_RGBA(c, "candycane10", 0, t_pitchwheel, candycane10);
        CLASS_ATTR_STYLE_LABEL(c,"candycane10",0,"rgba","Candycane Color 10");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane10", 0, "0.84 0.69 0. 1.0");
        // @description Sets one of the candycane colors

    }
    
        CLASS_ATTR_DOUBLE(c,"zoomangle",0, t_pitchwheel, zoom_angle);

    CLASS_STICKY_ATTR_CLEAR(c, "category"); 

    s_pitchwheel_class = c;
    class_register(CLASS_BOX, s_pitchwheel_class);
    
    dev_post("bach.pitchwheel compiled %s %s", __DATE__, __TIME__);
    return;
}


void pitchwheel_importance(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv)
{
    const char *subs[] = {"num","den","min","max","limit","maxexp"};
    if (x->n_importance_lexpr)
        lexpr_free(x->n_importance_lexpr);
    x->n_importance_lexpr = lexpr_new(argc, argv, 6, subs, (t_object *) x);
    if (x->n_importance_lexpr) {
        x->rebuild = 1;
    } else {
        object_error((t_object *) x, "Bad expression!");
    }
}

t_max_err pitchwheel_setattr_importance(t_pitchwheel *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        pitchwheel_importance(x, NULL, ac, av);
        x->importance_sym = atom_getsym(av);
    } else {
        object_error((t_object *)x, "Wrong importance function defined.");
    }
    
    x->rebuild = true;
    return MAX_ERR_NONE;
}


t_max_err pitchwheel_notify(t_pitchwheel *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
    x->rebuild = true;
    jbox_redraw((t_jbox *)x);
    return jbox_notify((t_jbox *)x, s, msg, sender, data);
}

void pitchwheel_assist(t_pitchwheel *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) {
        if (a == 0) // @in 0 @type llll @digest Points, or a 2-depth list of interlaced Points and Velocities
            sprintf(s, "llll: Points or dump to Output");
        else if (a == 1)  // @in 1 @type llll @digest Velocities
            sprintf(s, "llll: Velocities");
        else // @in 2 @type int @digest Modulo
            sprintf(s, "int: Modulo");
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
        if (a == 0) // @out 0 @type llll @digest Points, as a plain list of point indices
            sprintf(s, "llll (%s): Points", type);
        else if (a == 1) // @out 1 @type llll @digest Velocities, as a plain list
            sprintf(s, "llll (%s): Velocities", type);
        else if (a == 2) // @out 2 @type llll @digest Modulo
            sprintf(s, "int: Modulo");
        else // @out 3 @type bang @digest bang when changed via the interface 
            sprintf(s, "bang When pitchwheel Changed"); // @description A bang is output whenever the user changes the diagram via mouse and keyboard
    }
}

void pitchwheel_inletinfo(t_pitchwheel *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void pitchwheel_int(t_pitchwheel *x, t_atom_long num)
{
    t_atom argv[1]; atom_setlong(argv, num);
    pitchwheel_anything(x, _llllobj_sym_list, 1, argv);
}

void pitchwheel_float(t_pitchwheel *x, double num){
    t_atom argv[1]; atom_setfloat(argv, num);
    pitchwheel_anything(x, _llllobj_sym_list, 1, argv);
}


void pitchwheel_dump(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv){
//    send_values(x);
}


void pitchwheel_anything(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv)
{
/*
    long inlet = proxy_getinlet((t_object *) x);
    
    if (inlet == 2 && argc) {
        systhread_mutex_lock(x->c_mutex);
        x->modulo = atom_getlong(argv);
        if (x->modulo <= 0) x->modulo = 1;
        sort_points(x);
        systhread_mutex_unlock(x->c_mutex);
    } else if (s == _sym_clear) {
        x->num_points = 0;
    } else if (inlet == 1) {
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_UI, s, argc, argv, 1);
    } else if (inlet == 0) {
        t_llll *inllll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE);

        if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _sym_add) {
            t_llllelem *elem;
            systhread_mutex_lock(x->c_mutex);
            for (elem = inllll->l_head->l_next; elem && x->num_points < CONST_MAX_POINTS - 1; elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                    x->points[x->num_points] = hatom_getlong(&elem->l_hatom);
                    x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                    x->num_points++;
                } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                    t_llll *ptllll = hatom_getllll(&elem->l_hatom);
                    if (ptllll && ptllll->l_head && hatom_gettype(&ptllll->l_head->l_hatom) == H_LONG) {
                        x->points[x->num_points] = hatom_getlong(&ptllll->l_head->l_hatom);
                        if (hatom_gettype(&ptllll->l_tail->l_hatom) == H_LONG || hatom_gettype(&ptllll->l_tail->l_hatom) == H_DOUBLE || hatom_gettype(&ptllll->l_tail->l_hatom) == H_RAT)
                            x->vels[x->num_points] = hatom_getlong(&ptllll->l_tail->l_hatom);
                        else
                            x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                        x->num_points++;
                    }
                }
            }
            sort_points(x);
            systhread_mutex_unlock(x->c_mutex);
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _sym_delete) {
            t_llllelem *elem;
            systhread_mutex_lock(x->c_mutex);
            for (elem = inllll->l_head->l_next; elem; elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                    long what = hatom_getlong(&elem->l_hatom);
                    long j = 0;
                    while (j < x->num_points) {
                        if (x->points[j] == what) {
                            long k;
                            for (k = j; k < x->num_points - 1; k++) {
                                x->points[k] = x->points[k+1];
                                x->vels[k] = x->vels[k+1];
                            }
                            x->num_points--;
                            break;
                        } else
                            j++;
                    }
                }
            }
            sort_points(x);
            systhread_mutex_unlock(x->c_mutex);
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_transpose) {
            if (inllll->l_head->l_next)
                transpose_pitchwheel(x, hatom_getlong(&inllll->l_head->l_next->l_hatom));
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_complement) {
            complement_pitchwheel(x);
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_invert) {
            invert_pitchwheel(x);
        } else if (inllll && inllll->l_head) {
            t_llllelem *elem, *elemv;
            t_llll *vels = NULL;

            vels = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_UI, 1, 1);

            systhread_mutex_lock(x->c_mutex);
            x->num_points = 0;
            for (elem = inllll->l_head, elemv = vels ? vels->l_head : NULL; elem && x->num_points < CONST_MAX_POINTS - 1; elem = elem->l_next, elemv = elemv ? elemv->l_next : NULL) {
                if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                    x->points[x->num_points] = hatom_getlong(&elem->l_hatom);
                    if (elemv && (hatom_gettype(&elemv->l_hatom) == H_LONG || hatom_gettype(&elemv->l_hatom) == H_DOUBLE || hatom_gettype(&elemv->l_hatom) == H_RAT))
                        x->vels[x->num_points] = hatom_getlong(&elemv->l_hatom);
                    else
                        x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                    x->vels[x->num_points] = CLAMP(x->vels[x->num_points], CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
                    x->num_points++;
                } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                    t_llll *ptllll = hatom_getllll(&elem->l_hatom);
                    if (ptllll && ptllll->l_head && hatom_gettype(&ptllll->l_head->l_hatom) == H_LONG) {
                        x->points[x->num_points] = hatom_getlong(&ptllll->l_head->l_hatom);
                        if (hatom_gettype(&ptllll->l_tail->l_hatom) == H_LONG || hatom_gettype(&ptllll->l_tail->l_hatom) == H_DOUBLE || hatom_gettype(&ptllll->l_tail->l_hatom) == H_RAT)
                            x->vels[x->num_points] = hatom_getlong(&ptllll->l_tail->l_hatom);
                        else
                            x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                        x->num_points++;
                    }
                }
            }
            sort_points(x);
            systhread_mutex_unlock(x->c_mutex);
            if (vels) llll_free(vels);
        }
        llll_free(inllll);
    }
    
    jbox_redraw((t_jbox *) x);
*/
}

t_pitchwheel* pitchwheel_new(t_symbol *s, long argc, t_atom *argv){
    t_pitchwheel* x = NULL;
    t_max_err err = MAX_ERR_GENERIC;
    t_dictionary *d;
    t_object *textfield;
    long flags;

    if (!(d=object_dictionaryarg(argc,argv)))
        return NULL;

    x = (t_pitchwheel*) object_alloc_debug(s_pitchwheel_class);
    flags = 0 
            | JBOX_DRAWFIRSTIN 
            | JBOX_NODRAWBOX
            | JBOX_DRAWINLAST
    //        | JBOX_TRANSPARENT    
    //        | JBOX_NOGROW
    //        | JBOX_GROWY
            | JBOX_GROWBOTH
            | JBOX_HILITE
    //        | JBOX_BACKGROUND
            | JBOX_TEXTFIELD
    //        | JBOX_DRAWBACKGROUND
    //        | JBOX_DEFAULTNAMES
    //        | JBOX_MOUSEDRAGDELTA
            ;

    err = jbox_new(&x->j_box.l_box, flags, argc, argv); 
    x->j_box.l_box.b_firstin = (t_object*) x;

    x->n_proxy[2] = proxy_new_debug((t_object *) x, 2, &x->n_in);
    x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);

    x->n_importance_lexpr = NULL;
    t_atom sav;
    x->importance_sym = gensym("(1-atan(maxexp*0.25)/1.5707)/pow(limit, 0.3)");
    atom_setsym(&sav, x->importance_sym);
    pitchwheel_importance(x, NULL, 1, &sav);
    x->show_focus = 1;
    x->j_has_focus = 0;
    x->octave_interval = genrat(2, 1);
    
    x->curr_pitches = NULL;
    x->num_pitches = 0;
    
    // retrieve saved attribute values
    attr_dictionary_process(x, d);

    x->rebuild = true;
    
    textfield = jbox_get_textfield((t_object *) x); 
    if (textfield) {
        textfield_set_noactivate(textfield, 1);
        textfield_set_editonclick(textfield, 0);            // set it to 0 if you don't want user to edit it in lock mode
        textfield_set_textmargins(textfield, 3, 3, 3, 3);    // margin on each side
    }
    
    llllobj_jbox_setup((t_llllobj_jbox *) x, 3, "bi44");

    // mutex
    systhread_mutex_new_debug(&x->c_mutex, 0);

    jbox_ready(&x->j_box.l_box);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_UI);
    if (x)
        return x;
    else 
        error(BACH_CANT_INSTANTIATE);

    object_free_debug(x);
    return NULL;
}

void pitchwheel_free(t_pitchwheel *x){
    long i;
    if (x->curr_pitches)
        bach_freeptr(x->curr_pitches);
    if (x->n_importance_lexpr)
        lexpr_free(x->n_importance_lexpr);

    for (i = 1; i < 3; i++)
        object_free_debug(x->n_proxy[i]);
    jbox_free(&x->j_box.l_box);
    systhread_mutex_free_debug(x->c_mutex);
    llllobj_jbox_free((t_llllobj_jbox *) x);
}


void reverse_unicodeChar_array(unicodeChar *arr, long len)
{
    for (long i = 0; i < len / 2; i++) {
        unicodeChar temp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = temp;
    }
}

// N.B.: pythAccidentals and accidentals must be sized PITCHWHEEL_MAX_ACCIDENTALS+1
void rational_get_limit_ext(t_rational r, char base_diatonic_pitch, long *limit, long *maxexp, long *pyth, long *pyth_accidentals_aslong, unicodeChar *pyth_accidentals, long *num_pyth_accidentals, unicodeChar *accidentals, long *num_accidentals, long *pyth_diatonic_step, bool *purely_pythagorean, bool *accidentals_overflow)
{
    long n = r.num();
    long d = r.den();
    long mp = 0;
    long numacc = 0;
    t_llll *n_factors = llll_factorize(n);
    t_llll *d_factors = llll_factorize(d);
    
    *num_pyth_accidentals = *num_accidentals = *pyth_accidentals_aslong = 0;
    *accidentals_overflow = 0;
    
    long lim = 2;
    for (t_llllelem *el = n_factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && ll->l_head->l_next && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                long l = hatom_getlong(&ll->l_head->l_hatom);
                long p = hatom_getlong(&ll->l_head->l_next->l_hatom);
                lim = MAX(lim, l);
                if (l > 2)
                    mp = MAX(mp, p);
            }
        }
    }
    for (t_llllelem *el = d_factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && ll->l_head->l_next && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                long l = hatom_getlong(&ll->l_head->l_hatom);
                long p = hatom_getlong(&ll->l_head->l_next->l_hatom);
                lim = MAX(lim, l);
                if (l > 2)
                    mp = MAX(mp, p);
            }
        }
    }
    *limit = lim;
    *maxexp = mp;
    
    // finding pythagorean chromatic index
    long count = 0;
    long numArrows = 0;
    *pyth = 0;
    *purely_pythagorean = true;
    t_rational temp = r;
    for (t_llllelem *el = n_factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && ll->l_head->l_next && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                long l = hatom_getlong(&ll->l_head->l_hatom);
                long p = hatom_getlong(&ll->l_head->l_next->l_hatom);
                if (l != 2 && l != 3) {
                    long li = num_to_prime_idx(l) - 2;
                    *purely_pythagorean = false;
                    if (li < 0 || li >= numcommas) {
                        *pyth = LONG_MAX;
                        *accidentals_overflow = true;
                        goto end;
                    } else {
                        for (long pc = 0; pc < p; pc++) {
                            temp = temp * commas[li];
                        }
                        switch (l) {
                            case 5:
                                numArrows += p;
                                break;
                            case 7:
                                while (p >= 2 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58080;
                                    p -= 2;
                                }
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58078;
                                    p -= 1;
                                }
                                break;
                            case 11:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58083;
                                    p--;
                                }
                                break;
                            case 13:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58084;
                                    p--;
                                }
                                break;
                            case 17:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58086;
                                    p--;
                                }
                                break;
                            case 19:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58088;
                                    p--;
                                }
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
    for (t_llllelem *el = d_factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && ll->l_head->l_next && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                long l = hatom_getlong(&ll->l_head->l_hatom);
                long p = hatom_getlong(&ll->l_head->l_next->l_hatom);
                if (l != 2 && l != 3) {
                    long li = num_to_prime_idx(l) - 2;
                    *purely_pythagorean = false;
                    if (li < 0 || li >= numcommas) {
                        *pyth = LONG_MAX;
                        *accidentals_overflow = true;
                        goto end;
                    } else {
                        for (long pc = 0; pc < p; pc++)
                            temp = temp / commas[li];
                        switch (l) {
                            case 5:
                                numArrows -= p;
                                break;
                            case 7:
                                while (p >= 2 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58080;
                                    p -= 2;
                                }
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58078;
                                    p--;
                                }
                                break;
                            case 11:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58082;
                                    p--;
                                }
                            case 13:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58085;
                                    p--;
                                }
                            case 17:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58087;
                                    p--;
                                }
                                break;
                            case 19:
                                while (p > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                    accidentals[numacc++] = 58089;
                                    p--;
                                }
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
    
    while (temp.r_num % 3 == 0 && temp.r_num > 0) {
        temp.r_num /= 3;
        count++;
    }
    while (temp.r_den % 3 == 0 && temp.r_den > 0) {
        temp.r_den /= 3;
        count--;
    }
    
    if (temp.r_num > 0 && temp.r_den > 0) {
        *pyth = count;
        *pyth_diatonic_step = positive_mod(count * 4, 7);
        
        long sharp_start = 6;
        if (base_diatonic_pitch == 'C' || base_diatonic_pitch == 'c') {
            sharp_start = 6;
        } else if (base_diatonic_pitch == 'D' || base_diatonic_pitch == 'd') {
            sharp_start = 4;
        } else if (base_diatonic_pitch == 'E' || base_diatonic_pitch == 'e') {
            sharp_start = 2;
        } else if (base_diatonic_pitch == 'F' || base_diatonic_pitch == 'f') {
            sharp_start = 7;
        } else if (base_diatonic_pitch == 'G' || base_diatonic_pitch == 'g') {
            sharp_start = 5;
        } else if (base_diatonic_pitch == 'A' || base_diatonic_pitch == 'a') {
            sharp_start = 3;
        } else if (base_diatonic_pitch == 'B' || base_diatonic_pitch == 'b') {
            sharp_start = 1;
        }
        long flat_start = sharp_start - 8;
        
        // Get pythagorean accidentals
        long temp_count = count;
        long pyth_accidentals_count = 0;
        long pyth_acc_long = 0;
        if (temp_count > 0) {
            while (temp_count >= sharp_start+7 && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += 2;
                pyth_accidentals[pyth_accidentals_count++] = 57955; // SMUFL double sharp
                temp_count -= 14;
            }
            while (temp_count >= sharp_start && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += 1;
                pyth_accidentals[pyth_accidentals_count++] = 57954; // SMUFL sharp
                temp_count -= 7;
            }
        } else if (temp_count < 0) {
            while (temp_count <= flat_start-7 && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += -2;
                pyth_accidentals[pyth_accidentals_count++] = 57956; // SMUFL double flat
                temp_count += 14;
            }
            while (temp_count <= flat_start && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += -1;
                pyth_accidentals[pyth_accidentals_count++] = 57952; // SMUFL flat
                temp_count += 7;
            }
        }
        pyth_accidentals[pyth_accidentals_count] = 0;
        *num_pyth_accidentals = pyth_accidentals_count;
        *pyth_accidentals_aslong = pyth_acc_long;

        long numarr = 0;
        long n_natural_arrows = 0; // number of arrows we need to represent as natural signs
        long n_modif_arrows = 0; // number of arrows we need to modify the first pythagorean accidental
        unicodeChar arrows[PITCHWHEEL_MAX_ACCIDENTALS+1];
        arrows[0] = 0;
        if (numArrows != 0) {
            if (pyth_accidentals_count == 0) {
                n_natural_arrows = numArrows;
                n_modif_arrows = 0;
            } else if (numArrows > 3) {
                n_natural_arrows = numArrows - 3;
                n_modif_arrows = 3;
            } else if (numArrows < -3) {
                n_natural_arrows = numArrows + 3;
                n_modif_arrows = -3;
            } else {
                n_natural_arrows = 0;
                n_modif_arrows = numArrows;
            }

            if (n_natural_arrows != 0) {
                if (n_natural_arrows > 0) {
                    while (n_natural_arrows >= 3 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58075;
                        n_natural_arrows -= 3;
                    }
                    while (n_natural_arrows >= 2 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58065;
                        n_natural_arrows -= 2;
                    }
                    while (n_natural_arrows >= 1 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58055;
                        n_natural_arrows -= 1;
                    }
                } else if (n_natural_arrows < 0) {
                    while (n_natural_arrows <= -3 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58070;
                        n_natural_arrows += 3;
                    }
                    while (n_natural_arrows <= -2 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58060;
                        n_natural_arrows += 2;
                    }
                    while (n_natural_arrows <= -1 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58050;
                        n_natural_arrows += 1;
                    }
                }
            }

            unicodeChar pyth_accidentals_temp[PITCHWHEEL_MAX_ACCIDENTALS+1];
            bach_copyptr(pyth_accidentals, pyth_accidentals_temp, (PITCHWHEEL_MAX_ACCIDENTALS + 1) * sizeof(unicodeChar));
            if (n_modif_arrows != 0) {
                // modify pythagorean accidental!
                long cc = pyth_accidentals_count;
                switch (pyth_accidentals_temp[cc]) {
                    case 57956:
                        pyth_accidentals_temp[cc] = 58048 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                        break;
                    case 57952:
                        pyth_accidentals_temp[cc] = 58049 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                        break;
                    case 57953:
                        pyth_accidentals_temp[cc] = 58050 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                        break;
                    case 57954:
                        pyth_accidentals_temp[cc] = 58051 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                        break;
                    case 57955:
                        pyth_accidentals_temp[cc] = 58052 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                        break;
                    default:
                        break;
                }
            }
        }
        
        // everything now is in reversed order, which is good, cause we can join easily
        // let's join higher limits accidentals, then arrows, then pythagorean accidentals (it's still in reversed order)
        
        // First join arrows and higher limits accidentals
        unicodeChar accidentals_joined[3*PITCHWHEEL_MAX_ACCIDENTALS + 3]; // can't me more than this
        bach_copyptr(accidentals, accidentals_joined, numacc * sizeof(unicodeChar));
        if (numarr > 0) {
            bach_copyptr(arrows, accidentals_joined + numacc, numarr * sizeof(unicodeChar));
            numacc += numarr;
        }
        if (pyth_accidentals_count > 0) {
            bach_copyptr(pyth_accidentals, accidentals_joined + numacc, pyth_accidentals_count * sizeof(unicodeChar));
            numacc += pyth_accidentals_count;
        }

//        reverse_unicodeChar_array(pyth_accidentals, pyth_accidentals_count);

        // crop joined
        if (numacc > PITCHWHEEL_MAX_ACCIDENTALS) {
            *accidentals_overflow = true;
            numacc = PITCHWHEEL_MAX_ACCIDENTALS;
        }
        bach_copyptr(accidentals_joined, accidentals, numacc * sizeof(unicodeChar));
        accidentals[numacc] = 0;
//        reverse_unicodeChar_array(accidentals, numacc);

        *num_accidentals = numacc;
    } else {
        *pyth = *pyth_diatonic_step =  LONG_MAX;
    }
    
end:
    accidentals[numacc] = 0;
    llll_free(n_factors);
    llll_free(d_factors);
    
    
}



double ratio_to_cents(t_rational r)
{
    return 1200 * log2(rat2double(r));
}

long get_default_maxden(t_pitchwheel *x, t_object *view)
{
    double radius, center_x, center_y;
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    double circle_length = TWOPI * radius;
    return round(sqrt(circle_length / 1.));
}

long get_default_fifthsext(t_pitchwheel *x, t_object *view)
{
    double radius, center_x, center_y;
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    double circle_length = TWOPI * radius;
    return round(sqrt(circle_length/35.));
}

t_llll *get_default_commamix(t_pitchwheel *x, t_object *view)
{
    double radius, center_x, center_y;
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    double circle_length = TWOPI * radius;
    t_llll *commamix = llll_get();
    
    // blank
    {
        t_llll *subll = repeat_long(0, numcommas);
        llll_appendllll(commamix, subll);
    }

    
    // single comma
    for (long i = 0; i < numcommas; i++) {
        long max_single_comma = (long)round((circle_length/500.) /(i+1));
        for (long m = -max_single_comma; m <= max_single_comma; m++) {
            if (m == 0)
                continue;
            t_llll *subll = llll_get();
            for (long j = 0; j < numcommas; j++) {
                if (i == j) {
                    llll_appendlong(subll, m);
                } else {
                    llll_appendlong(subll, 0);
                }
            }
//            llll_print(subll);
            llll_appendllll(commamix, subll);
        }
    }
    
    // two commas
    //TODO
    return commamix;
}


void pitchwheel_build_pitches(t_pitchwheel *x, t_object *view)
{
    systhread_mutex_lock(x->c_mutex);
    t_llll *curr_pitches_ll = llll_get();
    if (x->mode == BACH_PITCHWHEEL_MODE_MAXDEN) {
        long ji_maxden = get_default_maxden(x, view);
        for (long n = 1; n <= ji_maxden; n++) {
            for (long m = n; m <= ji_maxden; m++) {
                if (rat_rat_cmp(genrat(m, n), x->octave_interval) < 0)
                    llll_appendrat(curr_pitches_ll, genrat(m, n));
            }
        }
    } else if (x->mode == BACH_PITCHWHEEL_MODE_JILIMITS) {
        
        t_llll *commamix = get_default_commamix(x, view);
        long fifthsext = get_default_fifthsext(x, view);
        for (long n = -fifthsext; n <= fifthsext; n++) {
            t_rational baseratio = rat_long_pow(genrat(3, 2), n);
            for (t_llllelem *el = commamix->l_head; el; el = el->l_next) {
                t_rational ratio = baseratio;
                long c = 0;
                for (t_llllelem *c_el = hatom_getllll(&el->l_hatom)->l_head; c_el && c < numcommas; c_el = c_el->l_next, c++) {
                    long e = hatom_getlong(&c_el->l_hatom);
                    if (e > 0)
                        ratio = rat_rat_prod(ratio, rat_long_pow(commas[c], e));

                }
                while (rat_long_cmp(ratio, 1) < 0 && ratio.num() != 0 && ratio.den() != 0)
                    ratio = rat_long_prod(ratio, 2);
                while (rat_long_cmp(ratio, 2) > 0 && ratio.num() != 0 && ratio.den() != 0)
                    ratio = rat_long_div(ratio, 2);
                if (ratio.num() != 0 && ratio.den() != 0) {
                    llll_appendrat(curr_pitches_ll, ratio);
                }
            }
        }
        
        llll_free(commamix);
    }
    curr_pitches_ll = llll_thin_simple(curr_pitches_ll, false);
    llll_mergesort_inplace(&curr_pitches_ll, llll_leq_elem, NULL);
    
    if (x->curr_pitches)
        bach_freeptr(x->curr_pitches);
    long numpitches = curr_pitches_ll->l_size;
    x->curr_pitches = (t_wheelpitch *)bach_newptr(MAX(numpitches, 1) * sizeof(t_wheelpitch));
    long i = 0;
    double max_importance = 0;
    for (t_llllelem *el = curr_pitches_ll->l_head; el; el = el->l_next, i++) {
        x->curr_pitches[i].type = BACH_PITCHWHEEL_PITCHTYPE_JI;
        x->curr_pitches[i].ratio = hatom_getrational(&el->l_hatom);
        rational_get_limit_ext(x->curr_pitches[i].ratio, x->base_diatonic_pitch ? x->base_diatonic_pitch->s_name[0] : 'C', &x->curr_pitches[i].limit, &x->curr_pitches[i].maxexp, &x->curr_pitches[i].pythagorean_index, &x->curr_pitches[i].pyth_accidentals_as_long, x->curr_pitches[i].pyth_accidentals, &x->curr_pitches[i].num_pyth_accidentals, x->curr_pitches[i].accidentals, &x->curr_pitches[i].num_accidentals, &x->curr_pitches[i].pyth_diatonic_step, &x->curr_pitches[i].purely_pythagorean, &x->curr_pitches[i].accidentals_overflow);

        x->curr_pitches[i].cents = ratio_to_cents(x->curr_pitches[i].ratio);
        
        double val = rat2double(x->curr_pitches[i].ratio);
        if (x->display_mapping == 0) { // linear pitch
            x->curr_pitches[i].angle = PIOVERTWO - TWOPI * log2(val / (rat2double(x->octave_interval) - 1));
        } else { // linear frequency
            x->curr_pitches[i].angle = PIOVERTWO - TWOPI * val / (rat2double(x->octave_interval) - 1);
        }
        
        if (!x->n_importance_lexpr) {
            x->curr_pitches[i].importance = 1;
        } else {
            t_hatom vars[LEXPR_MAX_VARS];
            t_hatom *res;
            hatom_setlong(vars, x->curr_pitches[i].ratio.num());
            hatom_setlong(vars+1, x->curr_pitches[i].ratio.den());
            hatom_setlong(vars+2, MIN(x->curr_pitches[i].ratio.num(), x->curr_pitches[i].ratio.den()));
            hatom_setlong(vars+3, MAX(x->curr_pitches[i].ratio.num(), x->curr_pitches[i].ratio.den()));
            hatom_setlong(vars+4, x->curr_pitches[i].limit);
            hatom_setlong(vars+5, x->curr_pitches[i].maxexp);
            res = lexpr_eval(x->n_importance_lexpr, vars);
            x->curr_pitches[i].importance = hatom_getdouble(res);
            //        = pow(x->curr_pitches[i].limit, 0.4);
            bach_freeptr(res);
        }
        max_importance = MAX(max_importance, x->curr_pitches[i].importance);
    }
    
    if (x->boost_diatonic > 0 || x->boost_pythagorean > 0 || x->boost_et > 0) {
        for (long i = 0; i < numpitches; i++) {
            if ((x->boost_diatonic && x->curr_pitches[i].purely_pythagorean && x->curr_pitches[i].num_accidentals == 0) ||
                (x->boost_pythagorean && x->curr_pitches[i].purely_pythagorean) ||
                (x->boost_et && x->curr_pitches[i].type == BACH_PITCHWHEEL_PITCHTYPE_ET)) {
                x->curr_pitches[i].importance = (max_importance == 0 ? 1 : max_importance * 1.2); // 1.2 is the boost factor (should we expose this?)
            }
        }
    }
    
    x->num_pitches = numpitches;
    
    // normalize importances
    if (max_importance > 0) {
        for (long i = 0; i < numpitches; i++) {
            x->curr_pitches[i].importance /= max_importance;
        }
    }
    
    llll_free(curr_pitches_ll);
    systhread_mutex_unlock(x->c_mutex);
}

void pitchwheel_paint_radial_line(t_pitchwheel *x, t_jgraphics *g, t_jrgba color, double center_x, double center_y, double theta, double r_start, double r_end, double linewidth, double *s, double *c)
{
    double sinus = sin(theta);
    double cosinus = cos(theta);
    double x1 = center_x + (r_start) * cosinus;
    double y1 = center_y - (r_start) * sinus;
    double x2 = center_x + (r_end) * cosinus;
    double y2 = center_y - (r_end) * sinus;
    
    if (s) *s = sinus;
    if (c) *c = cosinus;
    
    paint_line(g, color, x1, y1, x2, y2, linewidth);
}

long sort_by_importance(void *dummy, t_llllelem *a, t_llllelem *b) // dummy is never used, but it's there for llll_mergesort
{
    if (a && b) {
        t_wheelpitch *a_p = (t_wheelpitch *)hatom_getobj(&a->l_hatom);
        t_wheelpitch *b_p = (t_wheelpitch *)hatom_getobj(&b->l_hatom);
        return a_p->importance >= b_p->importance;
    }
    return 0;
}

void pitchwheel_get_label_specs(t_pitchwheel *x, t_wheelpitch *p, t_pt center, double radius, double cos_alpha, double sin_alpha, char **number_txt, t_jfont **font, t_pt *number_center, t_pt *number_middle_left, t_rect *number_rect, double *fontsize, bool *acc_displayed)
{
    double ticklength = x->tick_length * p->curr_normalized_importance;
    t_hatom h;
    double width, height;
    double accfontsize = 0;
    
    *acc_displayed = false;
    
    switch (x->display_what) {
        case BACH_PITCHWHEEL_DISPLAY_RATIO:
            *fontsize = p->curr_normalized_importance * jbox_get_fontsize((t_object *) x);
            *font = jfont_create_debug(jbox_get_fontname((t_object *) x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), *fontsize);
            hatom_setrational(&h, p->ratio);
            hatom_to_text_buf(&h, number_txt);
            break;

        case BACH_PITCHWHEEL_DISPLAY_ACCIDENTALS:
        {
            long len_utf = 0;
            char base_diatonic_pitch = (x->base_diatonic_pitch ? x->base_diatonic_pitch->s_name[0] : 'C');
            if (!p->accidentals_overflow && p->purely_pythagorean && p->num_accidentals == 0) { // pure diatonic note
                *fontsize = jbox_get_fontsize((t_object *) x);
                *font = jfont_create_debug(jbox_get_fontname((t_object *) x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), *fontsize);
                *number_txt = (char *)bach_newptr(2 * sizeof(char));
                (*number_txt)[0] = base_diatonic_pitch + p->pyth_diatonic_step;
                if ((*number_txt)[0] > 'G')
                    (*number_txt)[0] -= 7;
                (*number_txt)[1] = 0;
            } else {
                accfontsize = p->curr_normalized_importance * object_attr_getfloat((t_object *)x, gensym("accidentalsfontsize"));
                *font = jfont_create_debug(object_attr_getsym((t_object *)x, gensym("accidentalsfont"))->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, accfontsize);
                if (p->accidentals_overflow) { // we have sized accidentals safely with a +2 instead of a +1
                    p->accidentals[p->num_accidentals] = 59682;
                    p->accidentals[p->num_accidentals+1] = 0;
                }
                *number_txt = charset_unicodetoutf8_debug(p->accidentals, p->num_accidentals + (p->accidentals_overflow ? 1 : 0), &len_utf);
                *fontsize = accfontsize;
                *acc_displayed = true;
            }
        }

            break;

        default:
            // TO DO!
            break;
    }

    jfont_text_measure(*font, *number_txt, &width, &height);

    double rd = radius;
    
    if (accfontsize > 0 && (x->text_direction == BACH_PITCHWHEEL_TEXT_ANGULAR))
        rd -= 1.7 * accfontsize; // accidentals are too far
    
    number_center->x = center.x + rd * cos_alpha;
    number_center->y = center.y - rd * sin_alpha;
    
    if (accfontsize > 0 && (x->text_direction == BACH_PITCHWHEEL_TEXT_UPRIGHT))
        number_center->y += 1.7 * accfontsize * sin_alpha; // accidentals are too far


    double pad = 4;

    *number_middle_left = *number_center;
    number_middle_left->x += cos_alpha * (ticklength + pad);
    number_middle_left->y -= sin_alpha * (ticklength + pad);

    number_center->x += cos_alpha * (width/2. + ticklength + pad);
    number_center->y -= sin_alpha * (height/2. + ticklength + pad);
    
    number_rect->x = number_center->x - width/2.;
    number_rect->y = number_center->y - height/2.;
    number_rect->width = width;
    number_rect->height = height;
}

void pitchwheel_paint(t_pitchwheel *x, t_object *view)
{
    t_jgraphics *g;
    t_rect rect;
    double center_x, center_y;
    double radius;
    long i;
    // getting rectangle dimensions
    g = (t_jgraphics*) patcherview_get_jgraphics(view); 
    jbox_get_rect_for_view(&x->j_box.l_box.b_ob, view, &rect);
    
    t_jrgba j_bgcolor_r, j_pointinnercolor_r, j_selectedpointinnercolor_r, j_textcolor_r, j_linecolor_r;
    object_attr_getjrgba((t_object *)x, gensym("bgcolor"), &j_bgcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("textcolor"), &j_textcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("pointinnercolor"), &j_pointinnercolor_r);
    object_attr_getjrgba((t_object *)x, gensym("linecolor"), &j_linecolor_r);
    
    
    // background
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    paint_background((t_object *)x, g, &rect, &j_bgcolor_r, 0);
#else
    jgraphics_rectangle_rounded(g, 1., 1., rect.width - 2, rect.height - 2, 2, 2);
#endif
    jgraphics_set_source_jrgba(g, &j_bgcolor_r); jgraphics_fill(g);
    
    
    t_jrgba black = get_grey(0.);
    // center and radius
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    
    if (x->rebuild) {
        pitchwheel_build_pitches(x, view);
        x->rebuild = false;
    }
    
    bool line = (radius == INFINITY);
    double z = x->zoom/100.;
    
    if (line) {
        double d = sqrt((rect.width/2)*(rect.width/2) + (rect.height/2) + (rect.height/2));
        double x1 = rect.width/2. - d;
        double y1 = rect.height/2. - d * sin(x->zoom_angle);
        double x2 = rect.width/2. + d;
        double y2 = rect.height/2. + d * sin(x->zoom_angle);
        paint_line(g, black, x1, y1, x2, y2, 2);
    } else {
//        paint_circle_stroken(g, black, center_x, center_y, radius, 2);
        double anglemin = 0, anglemax = TWOPI;
        double anglemin_for_stroken = 0, anglemax_for_stroken = TWOPI;
        if (x->zoom > 300) { // let's only paint an arc, it's probably better
            double angle1, angle2, angle3, angle4;
            angle1 = atan2(0 - center_y, 0 - center_x);
            angle2 = atan2(rect.height - center_y, rect.width - center_x);
            angle3 = atan2(rect.height - center_y, 0 - center_x);
            angle4 = atan2(0 - center_y, rect.width - center_x);
            angle1 += TWOPI;
            while (angle2 - angle1 > PI) angle2 -= TWOPI;
            while (angle2 - angle1 < -PI) angle2 += TWOPI;
            while (angle3 - angle1 > PI) angle3 -= TWOPI;
            while (angle3 - angle1 < -PI) angle3 += TWOPI;
            while (angle4 - angle1 > PI) angle4 -= TWOPI;
            while (angle4 - angle1 < -PI) angle4 += TWOPI;
            anglemin = MIN(angle1, MIN(angle2, MIN(angle3, angle4)));
            anglemax = MAX(angle1, MAX(angle2, MAX(angle3, angle4)));
            while (anglemin >= TWOPI) {
                anglemin -= TWOPI;
                anglemax -= TWOPI;
            }
            if (x->show_circles)
                paint_arc_stroken(g, black, center_x, center_y, radius, 2, anglemin, anglemax);
            anglemin_for_stroken = anglemin;
            anglemax_for_stroken = anglemax;
//            paint_arc_stroken(g, black, 20, 20, 20, 2, anglemin, anglemax);
            // paint_arc_stroken has a different convention than ours, it goes clockwise
            double anglediff = anglemax - anglemin;
            anglemin = positive_fmod(-anglemax, TWOPI);
            anglemax = anglemin + anglediff;
        } else {
            if (x->show_circles)
                paint_circle_stroken(g, black, center_x, center_y, radius, 2);
        }
        systhread_mutex_lock(x->c_mutex);

        // Show et wheel if needed
        if (x->show_et_wheel) {
//            paint_arc_stroken(g, black, center_x, center_y, radius + x->et_wheel_size, 2, anglemin_for_stroken, anglemax_for_stroken);
            double r_avg = radius - x->et_wheel_size/2.;
            double octave_interval_cents = ratio_to_cents(x->octave_interval);
            for (long i = 0; i < octave_interval_cents; i++) {
                double et_importance = 0;
                if (i % 100 == 0) et_importance = 1.;
                else if (i % 50 == 0) et_importance = 0.7;
                else if (i % 25 == 0) et_importance = 0.5;
                else if (i % 5 == 0) et_importance = 0.25;
                else et_importance = 0.1;
                if (et_importance > 1./(5.*z)) {
                    double theta = 0;
                    double r_delta = sqrt(et_importance) * x->et_wheel_size * 0.4;
                    if (x->display_mapping == 0) { // linear pitch
                        theta = PIOVERTWO - positive_fmod((i/octave_interval_cents * TWOPI) - x->rotation_angle, TWOPI);
                    } else { // linear frequency
                        theta = PIOVERTWO - positive_fmod(((pow(2, i/octave_interval_cents) - 1) * TWOPI) - x->rotation_angle, TWOPI);
                    }
                    pitchwheel_paint_radial_line(x, g, black, center_x, center_y, theta, r_avg - r_delta, r_avg + r_delta, 1.5*sqrt(et_importance) + 0.5 * (et_importance == 1.), NULL, NULL);
                }
            }
        }

        if (x->show_integers_wheel) {
//            paint_arc_stroken(g, black, center_x, center_y, radius + x->et_wheel_size, 2, anglemin_for_stroken, anglemax_for_stroken);
            double r_start = radius - x->et_wheel_size;
            long max_int = 30 * pow((x->zoom/100.) * (radius / 100.), 0.5);
            if (x->display_mapping == 1) // frequency mapping
                max_int = ipow(2, (long)ceil(log2(max_int)));
            for (long i = 1; i < max_int; i+=2) {
                double int_importance = 1./i;
                double theta;
                
                if (x->display_mapping == 0) { // linear pitch
                    theta = (fmod(log2(i), 1.) + x->rotation_angle_intwheel) * TWOPI;
                } else { // linear frequency
                    theta = TWOPI * ((i * 1. / (ipow(2, floor(log2(i))))) / (rat2double(x->octave_interval) - 1)  + x->rotation_angle_intwheel);
                }
                theta = PIOVERTWO - theta;
                theta = positive_fmod(theta, TWOPI);
                if (anglemin < TWOPI && anglemax >= TWOPI && theta < anglemin)
                    theta += TWOPI;
                if (theta >= anglemin && theta <= anglemax) {
                    char text[20];
                    snprintf_zero(text, 20, "%d", i);
                    double fontrescale = x->minfactor + (1-x->minfactor) * pow(int_importance, 0.3);
                    t_jfont *jf = jfont_create_debug(jbox_get_fontname((t_object *) x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), fontrescale * jbox_get_fontsize((t_object *) x));
                    
                    double r_end = r_start - (0.15 * x->int_wheel_size + 0.85 * x->int_wheel_size * fontrescale);
                    pitchwheel_paint_radial_line(x, g, black, center_x, center_y, theta, r_start, r_end, 1*fontrescale, NULL, NULL);
                    write_text(g, jf, black, text, center_x + (r_end - 10) * cos(theta) - 30,center_y - (r_end - 10) * sin(theta) - 30, 60, 60, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
                    jfont_destroy_debug(jf);
                }
            }
        }
        
        
        // Decide which pitches must be shown
        t_llll *shown_pitches_ll = llll_get();
        double max_shown_importance = 0.;
        for (long n = 0; n < x->num_pitches; n++) {
            t_wheelpitch *p = &x->curr_pitches[n];
            double theta = positive_fmod(p->angle + x->rotation_angle, TWOPI);
            
            p->shown = true;
            if (anglemin < TWOPI && anglemax >= TWOPI && theta < anglemin)
                theta += TWOPI;
            if (theta < anglemin || theta > anglemax)
                p->shown = false;
            else {
                p->shown = true;
                llll_appendobj(shown_pitches_ll, p);
                max_shown_importance = MAX(max_shown_importance, p->importance);
            }
        }
        double maxreduction = x->minfactor;
        if (max_shown_importance > 0) {
            for (long n = 0; n < x->num_pitches; n++) { // normalizing importances
                t_wheelpitch *p = &x->curr_pitches[n];
                p->curr_normalized_importance = rescale(p->importance, 0., max_shown_importance, maxreduction, 1.);
            }
        } else {
            for (long n = 0; n < x->num_pitches; n++) { // normalizing importances
                t_wheelpitch *p = &x->curr_pitches[n];
                p->curr_normalized_importance = 0;
            }
        }
        
        // Avoid collisions?
        if (x->avoid_collisions) {
            // sorting by importance
            llll_mergesort_inplace(&shown_pitches_ll, (sort_fn)sort_by_importance, NULL);
            
            // checking collisions
            
            for (t_llllelem *el = shown_pitches_ll->l_head; el; el = el->l_next) {
                t_wheelpitch *p = (t_wheelpitch *)hatom_getobj(&el->l_hatom);
                char *p_number_txt = NULL;
                t_jfont *p_font = NULL;
                t_pt p_number_center, p_number_left;
                t_rect p_number_rect;
                double p_fontsize = 0, p_theta = positive_fmod(p->angle + x->rotation_angle, TWOPI);
                bool p_acc_displayed = false;
                
                pitchwheel_get_label_specs(x, p, build_pt(center_x, center_y), radius, cos(p_theta), sin(p_theta), &p_number_txt, &p_font, &p_number_center, &p_number_left, &p_number_rect, &p_fontsize, &p_acc_displayed);
                
                bool collision = false;
                for (t_llllelem *pr_el = el->l_prev; pr_el; pr_el = pr_el->l_prev) {
                    t_wheelpitch *q = (t_wheelpitch *)hatom_getobj(&pr_el->l_hatom);
                    if (!q->shown)
                        continue;
                    
                    char *q_number_txt = NULL;
                    t_jfont *q_font = NULL;
                    t_pt q_number_center, q_number_left;
                    t_rect q_number_rect;
                    double q_fontsize = 0, q_theta = positive_fmod(q->angle + x->rotation_angle, TWOPI);
                    bool q_acc_displayed = false;

                    pitchwheel_get_label_specs(x, q, build_pt(center_x, center_y), radius, cos(q_theta), sin(q_theta), &q_number_txt, &q_font, &q_number_center, &q_number_left, &q_number_rect, &q_fontsize, &q_acc_displayed);

                    bach_freeptr(q_number_txt);
                    jfont_destroy_debug(q_font);
                    
                    switch (x->text_direction) {
                        case BACH_PITCHWHEEL_TEXT_UPRIGHT:
                            if (jgraphics_rectintersectsrect(&p_number_rect, &q_number_rect))
                                collision = true;
                            break;
                            
                        case BACH_PITCHWHEEL_TEXT_RADIAL:
                            if (angle_dist(p_theta, q_theta, TWOPI) * radius < (p_number_rect.height * (p_acc_displayed ? 0.2 : 1) + q_number_rect.height * (q_acc_displayed ? 0.2 : 1)) / 2.)
                                collision = true;
                            break;
                            
                        case BACH_PITCHWHEEL_TEXT_ANGULAR:
                            if (angle_dist(p_theta, q_theta, TWOPI) * radius < (p_number_rect.width + q_number_rect.width) / 2.)
                                collision = true;
                            break;
                        
                        default:
                            break;
                    }
                    
                    if (collision)
                        break;
                    
                }
                
                bach_freeptr(p_number_txt);
                jfont_destroy_debug(p_font);

                if (collision) {
                    p->shown = false;
                }
            }

        }
        
        // Display
        for (t_llllelem *el = shown_pitches_ll->l_head; el; el = el->l_next) {
            t_wheelpitch *p = (t_wheelpitch *)hatom_getobj(&el->l_hatom);
            
            if (!p->shown)
                continue;
            
            long limit = p->limit;
            double importance = p->curr_normalized_importance;
            double ticklength = x->tick_length * importance;
            double ticklinewidth = 1.5 * importance;
            double theta = positive_fmod(p->angle + x->rotation_angle, TWOPI);

            t_jrgba color = black;
            
            switch (x->color_mode) {
                case BACH_PITCHWHEEL_COLORMODE_LIMIT:
                    color = pitchwheel_long_to_color(x, num_to_prime_idx(p->limit)-1);
                    break;

                case BACH_PITCHWHEEL_COLORMODE_MAXEXP:
                    color = pitchwheel_long_to_color(x, p->maxexp);
                    break;

                case BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANCHROMATICNOTE:
                    color = pitchwheel_long_to_color(x, p->pythagorean_index);
                    break;

                case BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANDIATONICNOTE:
                    color = pitchwheel_long_to_color(x, positive_fmod(p->pythagorean_index, 7));
                    break;
                    
                case BACH_PITCHWHEEL_COLORMODE_PLAIN:
                    color = j_textcolor_r;
                    break;
                    
                default:
                    color = get_grey(0); // black
                    break;
            }
            
            char text_direction = x->text_direction;
            
            double sinus, cosinus;
            if (x->show_ticks) {
                pitchwheel_paint_radial_line(x, g, color, center_x, center_y, theta, radius, radius + ticklength, ticklinewidth, &sinus, &cosinus);
            }
            
            
            // write number?
            if (x->show_ratios) {
                t_jtextlayout *jtl = jtextlayout_create();
                char *number_txt = NULL;
                t_jfont *font = NULL;
                t_pt number_center, number_left;
                t_rect number_rect;
                t_jmatrix mat;
                double fontsize;
                bool accdisplayed;
                
                pitchwheel_get_label_specs(x, p, build_pt(center_x, center_y), radius, cosinus, sinus, &number_txt, &font, &number_center, &number_left, &number_rect, &fontsize, &accdisplayed);
                
                theta = positive_fmod(theta, TWOPI);
                bool turn_for_legibility = false;
                
                switch (text_direction) {
                    case BACH_PITCHWHEEL_TEXT_RADIAL:
                        turn_for_legibility = (x->rotate_for_legibility && theta + PIOVERTWO > PI && theta + PIOVERTWO <= TWOPI);
                        jgraphics_matrix_init_rotate(&mat, -theta + (turn_for_legibility ? PI : 0));
                        jgraphics_matrix_translate(&mat, number_left.x, number_left.y);
                        jgraphics_set_matrix(g, &mat);
                        if (turn_for_legibility)
                            jtextlayout_set(jtl, number_txt, font, -number_rect.width, -number_rect.height/2., number_rect.width, number_rect.height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        else
                            jtextlayout_set(jtl, number_txt, font, 0, -number_rect.height/2., number_rect.width, number_rect.height, JGRAPHICS_TEXT_JUSTIFICATION_LEFT, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        break;

                    case BACH_PITCHWHEEL_TEXT_ANGULAR:
                        turn_for_legibility = (x->rotate_for_legibility && theta > PI && theta <= TWOPI);
                        jgraphics_matrix_init_rotate(&mat, -theta+PIOVERTWO  + (turn_for_legibility ? PI : 0));
                        jgraphics_matrix_translate(&mat, number_left.x, number_left.y);
                        jgraphics_set_matrix(g, &mat);
                        if (turn_for_legibility)
                            jtextlayout_set(jtl, number_txt, font, -number_rect.width/2., 0, number_rect.width, number_rect.height, JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        else
                            jtextlayout_set(jtl, number_txt, font, -number_rect.width/2., -number_rect.height, number_rect.width, number_rect.height, JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        break;
                        
                    default:
                        jtextlayout_set(jtl, number_txt, font, number_rect.x, number_rect.y, number_rect.width, number_rect.height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        break;
                }
                jtextlayout_settextcolor(jtl, &color);
                jtextlayout_draw(jtl, g);
                jtextlayout_destroy(jtl);

                bach_freeptr(number_txt);
                jfont_destroy_debug(font);
            }
            
            if (text_direction != BACH_PITCHWHEEL_TEXT_UPRIGHT)
                jgraphics_identity_matrix(g);

        }
        
        llll_free(shown_pitches_ll);
        
        systhread_mutex_unlock(x->c_mutex);
    }
    
    
    // border
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    paint_border((t_object *)x, g, &rect, &x->j_bordercolor, (x->show_focus && x->j_has_focus) ? 2.5 : 1., 0.);
#else
    jgraphics_rectangle_rounded(g, 1., 1., rect.width - 2, rect.height - 2, 10, 6);
    jgraphics_set_source_jrgba(g, &x->j_bordercolor);
    jgraphics_set_line_width(g, (x->show_focus && x->j_has_focus) ? 2.5 : 1.);
    jgraphics_stroke(g);
#endif
}


void pitchwheel_focusgained(t_pitchwheel *x, t_object *patcherview) {
//    object_post((t_object *)x, "focusgained"); 
    x->j_has_focus = true;
    jbox_redraw((t_jbox *)x);
}

void pitchwheel_focuslost(t_pitchwheel *x, t_object *patcherview) {
//    object_post((t_object *)x, "focuslost"); 
    x->j_has_focus = false;
    jbox_redraw((t_jbox *)x);
}


void get_radius_and_center(t_pitchwheel *x, t_object *patcherview, double *radius, double *center_x, double *center_y){
    t_rect rect;
    jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect); // rect dimension
    
    // center and radius
    t_pt screencenter = build_pt(rect.width/2, rect.height/2);
    t_pt center = screencenter;
    double inset = x->inset + x->tick_length + jbox_get_fontsize((t_object *)x);
    double base_radius = MIN(center.x - inset, center.y - inset);
    *radius = base_radius;
    if (x->zoom > 100) {
        double z = x->zoom / 100.;
        *radius *= z;
        {
            double t = (*radius - base_radius)/base_radius;
            center.y = (*radius + inset) + (atan(0.1*t)/PIOVERTWO) * (rect.height/2 - x->inset);
            
            t_pt newcenter;
            center = pt_pt_diff(center, screencenter);
            newcenter.x = center.x * cos(x->zoom_angle) - center.y * sin(x->zoom_angle);
            newcenter.y = center.x * sin(x->zoom_angle) + center.y * cos(x->zoom_angle);
            center = pt_pt_sum(newcenter, screencenter);
        }
    }
    
    *center_x = center.x;
    *center_y = center.y;
}


void pitchwheel_mousemove(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    return;
}

void pitchwheel_mousedown(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    x->mousedrag_pt = pt;
    return;
/*    long i, clicked_pt;

    evnum_incr();
    
    llll_format_modifiers(&modifiers, NULL);

    x->mousedrag_pt = pt;
    
    clicked_pt = pixel_coordinates_to_point_number(x, patcherview, pt.x, pt.y);
    
    if (clicked_pt > -1) {
        if (modifiers & eControlKey) {
            for (i = 0; i < x->num_points; i++)
                if (x->points[i] == clicked_pt) {
                    x->is_velocity_dragging = i;
                    x->dragging_velocity = x->vels[i];
                    break;
                }
        } else if (modifiers == eAltKey) {
            t_llll *out = llll_get();
            llll_appendsym(out, _llllobj_sym_point, 0, WHITENULL_llll);
            if (clicked_pt < x->num_names) {
                if (atom_gettype(&x->names[clicked_pt]) == A_SYM)
                    llll_appendsym(out, atom_getsym(&x->names[clicked_pt]), 0, WHITENULL_llll);
                else if (atom_gettype(&x->names[clicked_pt]) == A_LONG)
                    llll_appendlong(out, atom_getlong(&x->names[clicked_pt]), 0, WHITENULL_llll);
                else if (atom_gettype(&x->names[clicked_pt]) == A_FLOAT)
                    llll_appenddouble(out, atom_getfloat(&x->names[clicked_pt]), 0, WHITENULL_llll);
                else
                    llll_appendsym(out, _llllobj_sym_empty_symbol, 0, WHITENULL_llll);
            } else
                llll_appendlong(out, clicked_pt, 0, WHITENULL_llll);
            llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 0, out);
            llll_free(out);
        } else {
            if (modifiers & eCommandKey) {
                t_atom argv[1];
                atom_setlong(argv, clicked_pt);
                pitchwheel_anything(x, _sym_delete, 1, argv);
            } else {
                t_atom argv[4];
                atom_setsym(argv, _llllobj_sym_open_round_bracket);
                atom_setlong(argv + 1, clicked_pt);
                atom_setlong(argv + 2, CONST_DEFAULT_VELOCITY);
                atom_setsym(argv + 3, _llllobj_sym_closed_round_bracket);
                pitchwheel_anything(x, _sym_add, 4, argv);
            }
            // changed! -> bang
            llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        }
    } else if (modifiers & eAltKey && modifiers & eControlKey) {
        x->is_modulo_dragging = 1;
        x->dragging_modulo = x->modulo;
    } */
}

void pitchwheel_mouseup(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers){
    return;
}


double get_mousedrag_angle(t_pt center, t_pt mousedown, t_pt mousedrag)
{
    t_pt delta = pt_pt_diff(mousedrag, mousedown);
    t_pt radius = pt_pt_diff(mousedown, center);
    t_pt perp = build_pt(radius.y, -radius.x);
    double perp_norm = pt_norm(perp);
    double radius_norm = pt_norm(radius);
    if (perp_norm == 0 || radius_norm == 0)
        return 0;
    perp = pt_number_prod(perp, 1./perp_norm);
    double dot = pt_pt_dot(perp, delta);
    return dot / radius_norm;
}

void pitchwheel_mousewheel(t_pitchwheel *x, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc)
{
    llll_format_modifiers(&modifiers, NULL);
    
    double r, cx, cy;
    get_radius_and_center(x, view, &r, &cx, &cy);

    if (modifiers == eCommandKey || modifiers == eShiftKey + eCommandKey) { // change side value
        double old_zoom = x->zoom / 100.;
        double new_zoom = old_zoom;
        const double PITCHWHEEL_Y_MOUSEWHEEL_FACTOR = 3;

        new_zoom -= y_inc * pow(old_zoom, 0.5) * PITCHWHEEL_Y_MOUSEWHEEL_FACTOR * (modifiers & eShiftKey ? CONST_FINER_FROM_KEYBOARD : 1.);

        new_zoom = CLAMP(new_zoom, 1., PITCHWHEEL_MAX_ZOOM/100.);
        object_attr_setfloat((t_object *)x, gensym("zoom"), new_zoom * 100);
        
        
        if (x->zoom <= 100.1)
            x->zoom_angle = PIOVERTWO - atan2(-pt.y+cy, pt.x-cx);
/*
        // notify zoom change
        t_llll *ll = llll_get();
        llll_appendsym(ll, _llllobj_sym_zoom, 0, WHITENULL_llll);
        llll_appenddouble(ll, new_zoom, 0, WHITENULL_llll);
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 6, ll);
        llll_free(ll); */

        x->rebuild = true;
        jbox_redraw((t_jbox *)x);
    } else {
//        x->zoom_angle += get_mousedrag_angle(build_pt(cx, cy), pt, build_pt(x_inc, y_inc));
//        x->rebuild = true;
//        jbox_redraw((t_jbox *)x);
    }
}

void pitchwheel_mousedrag(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_pt center;
    double radius;
    get_radius_and_center(x, patcherview, &radius, &center.x, &center.y);
    
    x->rotation_angle += get_mousedrag_angle(center, x->mousedrag_pt, pt);

    //    t_pt delta = pt_pt_diff(pt, x->mousedrag_pt);
//    x->rotation_angle += delta.y * 0.03 / (x->zoom/100.);
    
    jbox_redraw((t_jbox *)x);
    
    x->mousedrag_pt = pt;
/*    if (x->is_modulo_dragging) {
        long new_modulo;
        double to_add = ((double)(pt.y - x->mousedrag_pt.y)) / CONST_DRAGGING_MODULO;

        systhread_mutex_lock(x->c_mutex);
        x->dragging_modulo -= to_add;
        new_modulo = round(x->dragging_modulo);
        if (new_modulo != x->modulo) {
            x->modulo = CLAMP(new_modulo, 1, CONST_MAX_MODULO);
            sort_points(x);
        }
        x->mousedrag_pt = pt;
        systhread_mutex_unlock(x->c_mutex);
        
        jbox_redraw((t_jbox *) x);
    } else if (x->is_velocity_dragging > -1) {
        long new_velocity;
        double to_add = ((double)(pt.y - x->mousedrag_pt.y)) / CONST_DRAGGING_VELOCITY;

        systhread_mutex_lock(x->c_mutex);
        x->dragging_velocity -= to_add;
        new_velocity = round(x->dragging_velocity);
        if (x->is_velocity_dragging < x->num_points && new_velocity != x->vels[x->is_velocity_dragging])
            x->vels[x->is_velocity_dragging] = CLAMP(new_velocity, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
        x->mousedrag_pt = pt;
        systhread_mutex_unlock(x->c_mutex);

        jbox_redraw((t_jbox *) x);
    } */
}


long pitchwheel_key(t_pitchwheel *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
    llll_format_modifiers(&modifiers, &keycode);
    
    if (keycode == JKEY_ESC) {
        x->rotation_angle = 0;
        x->zoom = 100;
        jbox_redraw((t_jbox *)x);
    }
    /*

    if (keycode == 't' && modifiers & eCommandKey) {
        transpose_pitchwheel(x, 1);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'r' && modifiers & eCommandKey) {
        transpose_pitchwheel(x, -1);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'i' && modifiers & eCommandKey) {
        invert_pitchwheel(x);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'c' && modifiers & eCommandKey) {
        complement_pitchwheel(x);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'd' && modifiers & eCommandKey && modifiers & eShiftKey) {
        send_values(x);
        return 1;
    } */
    return 0;
}
