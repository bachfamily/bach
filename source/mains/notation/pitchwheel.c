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

const long fareylengths[] = {2,3,5,7,11,13,19,23,29,43,47,59,73,97,103,151,
    173,181,271,397,433,491,883,941,1087,1103,1163,
    1193,1229,1427,1471,1697,2143,2273,2657,2903,3533,
    3677,4073,4129,4201,4259,4637,5023,5107,5953,6163,
    6599,7177,7237};

typedef struct _wheelpitch
{
    char        type; // 1 if pitch is a JI ratio, 0 if it's a ET
    t_rational  ratio;
    double      cents;
    long        limit;
    double      angle;
} t_wheelpitch;


typedef struct _pitchwheel // [bach.pitchwheel] structure
{
    t_llllobj_jbox            j_box; // root object

    t_jrgba                    j_textcolor;
    t_jrgba                    j_bgcolor;
    t_jrgba                    j_bordercolor;
    t_jrgba                    j_linecolor;
    
    double                  rotation_angle;
    double                  zoom;
    double                  zoom_angle;
    t_rational              octave_interval;

    char                    mode;
    
    char                    j_has_focus;
    char                    show_focus;
    double                  inset;
    
    t_pt                    mousedrag_pt;

    t_wheelpitch            *curr_pitches;
    long                    num_pitches;
    
    char                    rebuild;

    void                    *n_proxy[3];
    long                    n_in;

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

t_pitchwheel* pitchwheel_new(t_symbol *s, long argc, t_atom *argv);

void pitchwheel_paint(t_pitchwheel *x, t_object *view);

void pitchwheel_anything(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv);
void pitchwheel_dump(t_pitchwheel *x, t_symbol *s, long argc, t_atom *argv);
void pitchwheel_int(t_pitchwheel *x, t_atom_long num);
void pitchwheel_float(t_pitchwheel *x, double num);
void pitchwheel_bang(t_pitchwheel *x);
void pitchwheel_preset(t_pitchwheel *x);

void get_radius_and_center(t_pitchwheel *x, t_object *patcherview, double *radius, double *center_x, double *center_y);

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
    jbox_initclass(c, JBOX_TEXTFIELD);    // include textfield and Fonts attributes
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
    
    CLASS_STICKY_ATTR(c, "category", 0, "Appearance"); 

        CLASS_ATTR_CHAR(c, "mode", 0, t_pitchwheel, mode);
        CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
        CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Pitch Frequency");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mode",0,"0");
        CLASS_ATTR_BASIC(c,"mode",0);
        // @description Choose the mapping mode: either linear in pitch (0) or linear in frequency (1)

    
        CLASS_ATTR_DOUBLE(c,"inset",0, t_pitchwheel, inset);
        CLASS_ATTR_STYLE_LABEL(c,"inset",0,"text","Inset");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"inset",0,"40.");
        // @description Inset of the clock diagram with respect to the border, in pixels

        CLASS_ATTR_DOUBLE(c,"zoom",0, t_pitchwheel, zoom);
        CLASS_ATTR_STYLE_LABEL(c,"zoom",0,"text","Zoom");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"zoom",0,"100.");
        // @description Zoom percentage.

        CLASS_ATTR_DOUBLE(c,"zoomangle",0, t_pitchwheel, zoom_angle);

    CLASS_STICKY_ATTR_CLEAR(c, "category"); 

    s_pitchwheel_class = c;
    class_register(CLASS_BOX, s_pitchwheel_class);
    
    dev_post("bach.pitchwheel compiled %s %s", __DATE__, __TIME__);
    return;
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
    
    for (i = 1; i < 3; i++)
        object_free_debug(x->n_proxy[i]);
    jbox_free(&x->j_box.l_box);
    systhread_mutex_free_debug(x->c_mutex);
    llllobj_jbox_free((t_llllobj_jbox *) x);
}


long rational_get_limit(t_rational r)
{
    long n = r.num();
    long d = r.den();
    t_llll *n_factors = llll_factorize(n);
    t_llll *d_factors = llll_factorize(d);

    long lim = 2;
    for (t_llllelem *el = n_factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                lim = MAX(lim, hatom_getlong(&ll->l_head->l_hatom));
            }
        }
    }
    for (t_llllelem *el = d_factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                lim = MAX(lim, hatom_getlong(&ll->l_head->l_hatom));
            }
        }
    }
    return lim;
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
    
    return round(sqrt(circle_length/10.));
/*    for (long i = 0; i < 50; i++) {
        if (fareylengths[i] > circle_length / 25.) {
            return MAX(2, i+1);
        }
    } */
    
    return 50;
}

void pitchwheel_build_pitches(t_pitchwheel *x, t_object *view)
{
    long ji_maxden = get_default_maxden(x, view);
    systhread_mutex_lock(x->c_mutex);
    t_llll *curr_pitches_ll = llll_get();
    for (long n = 1; n <= ji_maxden; n++) {
        for (long m = n; m <= ji_maxden; m++) {
            if (rat_rat_cmp(genrat(m, n), x->octave_interval) < 0)
                llll_appendrat(curr_pitches_ll, genrat(m, n));
        }
    }
    curr_pitches_ll = llll_thin_simple(curr_pitches_ll, false);
    llll_mergesort_inplace(&curr_pitches_ll, llll_leq_elem, NULL);
    
    if (x->curr_pitches)
        bach_freeptr(x->curr_pitches);
    long numpitches = curr_pitches_ll->l_size;
    x->curr_pitches = (t_wheelpitch *)bach_newptr(MAX(numpitches, 1) * sizeof(t_wheelpitch));
    long i = 0;
    for (t_llllelem *el = curr_pitches_ll->l_head; el; el = el->l_next, i++) {
        x->curr_pitches[i].type = 1;
        x->curr_pitches[i].ratio = hatom_getrational(&el->l_hatom);
        x->curr_pitches[i].limit = rational_get_limit(x->curr_pitches[i].ratio);
        x->curr_pitches[i].cents = ratio_to_cents(x->curr_pitches[i].ratio);
        double val = rat2double(x->curr_pitches[i].ratio);
        if (x->mode == 0) { // linear pitch
            x->curr_pitches[i].angle = PIOVERTWO - TWOPI * log2(val / (rat2double(x->octave_interval) - 1));
        } else { // linear frequency
            x->curr_pitches[i].angle = PIOVERTWO - TWOPI * val / (rat2double(x->octave_interval) - 1);
        }
    }
    x->num_pitches = numpitches;
    llll_free(curr_pitches_ll);
    systhread_mutex_unlock(x->c_mutex);
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
    
    t_symbol *font_name = jbox_get_fontname((t_object *) x);

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
    
    if (x->rebuild)
        pitchwheel_build_pitches(x, view);
    
    bool line = (radius == INFINITY);

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
            paint_arc_stroken(g, black, center_x, center_y, radius, 2, anglemin, anglemax);
//            paint_arc_stroken(g, black, 20, 20, 20, 2, anglemin, anglemax);
            // paint_arc_stroken has a different convention than ours, it goes clockwise
            double anglediff = anglemax - anglemin;
            anglemin = positive_fmod(-anglemax, TWOPI);
            anglemax = anglemin + anglediff;
        } else {
            paint_circle_stroken(g, black, center_x, center_y, radius, 2);
        }
        systhread_mutex_lock(x->c_mutex);
        
        double z = x->zoom/100.;
        for (long n = 0; n < x->num_pitches; n++) {
            t_wheelpitch *p = &x->curr_pitches[n];
            long limit = p->limit;
            double z_contrib = 1 + log2(z)*0.25;
            double ticklength = z_contrib * 10./pow(limit, 0.4);
            double ticklinewidth = z_contrib * 3./pow(limit, 0.4);
            double semiticklength = ticklength/2.;
//            double theta = p->angle + x->rotation_angle;
            double theta = positive_fmod(p->angle + x->rotation_angle, TWOPI);
            if (theta < anglemin || theta > anglemax)
                continue;

            double sinus = sin(theta);
            double cosinus = cos(theta);
            double xm = center_x + radius * cosinus;
            double ym = center_y - radius * sinus;
            double x1 = center_x + (radius + semiticklength) * cosinus;
            double y1 = center_y - (radius + semiticklength) * sinus;
            double x2 = center_x + (radius - semiticklength) * cosinus;
            double y2 = center_y - (radius - semiticklength) * sinus;
            
            t_jrgba color = long_to_color(limit-1);
            
            paint_line(g, black, x1, y1, x2, y2, ticklinewidth);
            
            // write number?
            if (true) {
                t_jtextlayout *jtl = jtextlayout_create();
                double width, height;
                char *number_txt = NULL;
//                char number_txt[100];
                
                double number_center_x = xm;
                double number_center_y = ym;
                
                t_hatom h;
                hatom_setrational(&h, p->ratio);
                hatom_to_text_buf(&h, &number_txt);
//                sprintf(number_txt, "%.3f", theta);
                
                t_jfont *font = jfont_create_debug(font_name->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), jbox_get_fontsize((t_object *) x) * z_contrib * 1./pow(limit, 0.4));

                jfont_text_measure(font, number_txt, &width, &height);
                
                number_center_x -= cosinus * (width/2. + semiticklength * 1.5);
                number_center_y += sinus * (height/2. + semiticklength * 1.5);
                
                jtextlayout_set(jtl, number_txt, font, number_center_x - width/2., number_center_y - height/2., width, height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                jtextlayout_settextcolor(jtl, &j_textcolor_r);
                jtextlayout_draw(jtl, g);
                jtextlayout_destroy(jtl);
                bach_freeptr(number_txt);
                jfont_destroy_debug(font);
            }
        }
            
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
    double base_radius = MIN(center.x - x->inset, center.y - x->inset);
    *radius = base_radius;
    if (x->zoom > 100) {
        double z = x->zoom / 100.;
        *radius *= z;
/*        if (*radius >= PITCHWHEEL_LIMIT_RADIUS_FOR_LINE - base_radius) {
            center.y = INFINITY;
            *radius = INFINITY;
        } else { */
            //double t = (*radius - base_radius)/PITCHWHEEL_LIMIT_RADIUS_FOR_LINE;
            //t = sqrt(t);
            //center.y = (1-t) * (*radius + x->inset) + t * ((*radius) + rect.height/2);

        {
            double t = (*radius - base_radius)/base_radius;
            center.y = (*radius + x->inset) + (atan(0.1*t)/PIOVERTWO) * (rect.height/2 - x->inset);
            
            t_pt newcenter;
            center = pt_pt_diff(center, screencenter);
            newcenter.x = center.x * cos(x->zoom_angle) - center.y * sin(x->zoom_angle);
            newcenter.y = center.x * sin(x->zoom_angle) + center.y * cos(x->zoom_angle);
            center = pt_pt_sum(newcenter, screencenter);
        }
//        }
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


void pitchwheel_mousewheel(t_pitchwheel *x, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc)
{
    llll_format_modifiers(&modifiers, NULL);
    
    if (modifiers == eCommandKey || modifiers == eShiftKey + eCommandKey) { // change side value
        double old_zoom = x->zoom / 100.;
        double new_zoom = old_zoom;
        const double PITCHWHEEL_Y_MOUSEWHEEL_FACTOR = 3;

        new_zoom -= y_inc * pow(old_zoom, 0.5) * PITCHWHEEL_Y_MOUSEWHEEL_FACTOR * (modifiers & eShiftKey ? CONST_FINER_FROM_KEYBOARD : 1.);

        new_zoom = CLAMP(new_zoom, 1., PITCHWHEEL_MAX_ZOOM/100.);
        object_attr_setfloat((t_object *)x, gensym("zoom"), new_zoom * 100);
        
        double r, cx, cy;
        get_radius_and_center(x, view, &r, &cx, &cy);
        
        if (x->zoom <= 100.1)
            x->zoom_angle = PIOVERTWO - atan2(-pt.y+cy, pt.x-cx);

        // notify zoom change
        t_llll *ll = llll_get();
        llll_appendsym(ll, _llllobj_sym_zoom, 0, WHITENULL_llll);
        llll_appenddouble(ll, new_zoom, 0, WHITENULL_llll);
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 6, ll);
        llll_free(ll);

        x->rebuild = true;
    }
}

void pitchwheel_mousedrag(t_pitchwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_pt center;
    double radius;
    get_radius_and_center(x, patcherview, &radius, &center.x, &center.y);
    
    t_pt delta = pt_pt_diff(pt, x->mousedrag_pt);
    x->rotation_angle += delta.y * 0.03;
//    t_pt r = pt_pt_diff(x->mousedrag_pt, center);
//    double dotpr = pt_pt_dot(r, delta);
//    x->rotation_angle += delta.y * 0.003;
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
