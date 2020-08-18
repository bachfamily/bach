/*
 *  circle.c
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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
    circle.c
    
    @name 
    bach.circle
    
    @realname 
    bach.circle

    @type
    object
    
    @module
    bach

    @author
    bachproject
    
    @digest 
    Clock diagram
    
    @description
    The purpose of <o>bach.circle</o> is to act as a simple clock diagram, 
    where each point can represent any abstract concept as pitch-classes 
    or rhythmic positions on a looped grid.
    Each point may have a velocity also. Some of the points can be selected, thus representing
    for instance pitch-class sets ("chords" or "scales"...) or rhythmic patterns. <br /> <br />
    
    @discussion
    @copy BACH_DOC_SETTHEORY_MODULO
    @copy BACH_DOC_SETTHEORY_PC_AND_PCSET
    
    @category
    bach, bach objects, bach set theory, bach interface, U/I
    
    @keywords
    circle, diagram, clock, pitch-class, set, rhythm, loop, velocity, select, rotate,
    transpose, invert, microtone

    @palette
    YES
    
    @palette category
    bach, bach objects, bach set theory, bach interface

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
#include <stdio.h>
#include <locale.h>
#include "ext_strings.h"
#include "ext_boxstyle.h"

#define CONST_MAX_POINTS 480
#define CONST_PIXEL_TOLERANCE_CLICK 4
#define CONST_DRAGGING_MODULO 20.
#define CONST_DRAGGING_VELOCITY 1.
#define CONST_DEFAULT_VELOCITY 100
#define CONST_MIN_VELOCITY 1
#define CONST_MAX_VELOCITY 127
#define CONST_MAX_POINT_NAMES 480

/*
#ifndef class_attr_setstyle
#define class_attr_setstyle(...) ((void) 0)
#define class_attr_style_alias(...) ((void) 0)
#define class_attr_stylemap(...) ((void) 0)
#endif
*/

typedef struct _circle // [bach.circle] structure
{
    t_llllobj_jbox            j_box; // root object

    t_jrgba                    j_textcolor;
    t_jrgba                    j_textcolornumbers;
    t_jrgba                    j_bgcolor;
    t_jrgba                    j_bordercolor;
    t_jrgba                    j_pointbordercolor;
    t_jrgba                    j_pointinnercolor;
    t_jrgba                    j_selectedpointbordercolor;
    t_jrgba                    j_selectedpointinnercolor;
    t_jrgba                    j_circlebordercolor;
    t_jrgba                    j_circleinnercolor;
    t_jrgba                    j_linecolor;
    
    char                    j_has_focus;
    char                    show_focus;
    
    long                    points[CONST_MAX_POINTS]; // must be static because it is a LONG_VARSIZE attribute
    long                    vels[CONST_MAX_POINTS]; // must be static because it is a LONG_VARSIZE attribute
    long                    num_points;
    long                    modulo;
    
    char                    velocity_handling;
    char                    show_modulo;
    char                    show_numbers;
    char                    show_polygon;
    char                    auto_reduce;
    double                    point_radius;
    double                    inset;
    double                    circle_line_width;
    double                    point_line_width;
    double                    line_width;
    
    t_atom                  names[CONST_MAX_POINT_NAMES]; // name of each point,  // must be static because it is a ATOM_VARSIZE attribute
    long                    num_names; // number of assigned names
    char                    send_names_through_dump;
    
    long                    mouseover_pt;
    t_pt                    mousedrag_pt;

    char                    is_modulo_dragging; // just 0 or 1
    double                    dragging_modulo;
    long                    is_velocity_dragging; // keeps track of the index of the mousedown point (-1 if none)
    double                    dragging_velocity;

    
    char                    rebuild; 

    void                    *n_proxy[3];
    long                    n_in;

//    t_symbol                *textfont;
//    double                    textsize;
    
    t_systhread_mutex        c_mutex;

} t_circle;


// global class pointer variable
t_class    *s_circle_class = NULL;

// functions
void circle_inletinfo(t_circle *x, void *b, long a, char *t);
void circle_assist(t_circle *x, void *b, long m, long a, char *s);

void circle_free(t_circle *x);

void circle_focusgained(t_circle *x, t_object *patcherview);
void circle_focuslost(t_circle *x, t_object *patcherview);
void circle_mousedown(t_circle *x, t_object *patcherview, t_pt pt, long modifiers);
void circle_mousemove(t_circle *x, t_object *patcherview, t_pt pt, long modifiers);
void circle_mouseup(t_circle *x, t_object *patcherview, t_pt pt, long modifiers);
void circle_mousedrag(t_circle *x, t_object *patcherview, t_pt pt, long modifiers);
long circle_key(t_circle *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);

t_circle* circle_new(t_symbol *s, long argc, t_atom *argv);

void circle_paint(t_circle *x, t_object *view);

void circle_anything(t_circle *x, t_symbol *s, long argc, t_atom *argv);
void circle_dump(t_circle *x, t_symbol *s, long argc, t_atom *argv);
void circle_int(t_circle *x, t_atom_long num);
void circle_float(t_circle *x, double num);
void circle_bang(t_circle *x);
void circle_setinterleaved(t_circle *x, t_symbol *s, long argc, t_atom *argv);
void circle_preset(t_circle *x);

void get_radius_and_center(t_circle *x, t_object *patcherview, double *radius, double *center_x, double *center_y);

void transpose_circle(t_circle *x, long steps);
void complement_circle(t_circle *x);
void invert_circle(t_circle *x);

t_max_err circle_setattr_autoreduce(t_circle *x, t_object *attr, long ac, t_atom *av);

void sort_points(t_circle *x);
void reduce_points(t_circle *x);
t_llll *points2llll(t_circle *x, char use_symbols);
t_llll *vels2llll(t_circle *x);

void circle_bang(t_circle *x)
{
    if (x->j_box.l_rebuild == 1 || proxy_getinlet((t_object *) x) != 0)
        circle_anything(x, _sym_bang, 0, NULL);
}

void circle_preset(t_circle *x){
    long ac = x->num_points * 2 + 1; 
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
}


void C74_EXPORT ext_main(void *moduleRef){
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();

    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }

    CLASS_NEW_CHECK_SIZE(c, "bach.circle",
                        (method)circle_new,
                        (method)circle_free,
                        sizeof(t_circle),
                        (method)NULL,
                        A_GIMME,
                        0L);
    
    c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//    jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
    jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR);    // include textfield and Fonts attributes
//    jbox_initclass(c, 0);
    
    class_addmethod(c, (method) circle_paint,            "paint", A_CANT, 0);

    // @method llll @digest Set points and/or velocities (depending on inlet)
    // @description 
    // In first inlet: a plain list sets the points: each point is given as per its index, 0 being the upper one, and then clockwise. 
    // An interlaced such as [(<m>pt1</m> <m>vel1</m>) (<m>pt2</m> <m>vel2</m>)...] sets both points and velocities. <br />
    // In second inlet: Sets the velocities for the points you'll send in the first inlet later.
    class_addmethod(c, (method) circle_anything, "anything", A_GIMME, 0);
    class_addmethod(c, (method) circle_anything, "list", A_GIMME, 0);

    // @method dump @digest Output all data
    // @description 
    // Send: <br />
    // - the modulo from the third outlet; <br />
    // - all the velocities from the second outlet, as a plain list; <br />
    // - all the points from the first outlet, as a plain list.
    class_addmethod(c, (method) circle_dump, "dump", A_GIMME, 0);


    // @method int @digest Set the modulo (in third inlet)
    // @description 
    // In the third inlet, an integer sets the modulo (number of points in the clock).
    class_addmethod(c, (method) circle_int, "int", A_LONG, 0);
    class_addmethod(c, (method) circle_float, "float", A_FLOAT, 0);

    class_addmethod(c, (method) circle_bang, "bang", 0);

    // @method clear @digest Clear the diagram
    // @description Clear all the points of the diagram
    class_addmethod(c, (method) circle_anything, "clear", A_GIMME, 0);

    // @method add @digest Add a point
    // @description Add a point to the diagram. The argument can be, as in the standard <m>llll</m> method,
    // either a plain list (representing point indices) or an interlaced list <b>[<m>pt1</m> <m>vel1</m>] [<m>pt2</m> <m>vel2</m>]...</b>
    // representing points and velocities
    // @marg 0 @name points @optional 0 @type llll
    // @example add 2 4 5 @caption add some points
    // @example add [2 60] [4 100 [5 120] @caption add some points with their velocities
    // @seealso delete
    class_addmethod(c, (method) circle_anything, "add", A_GIMME, 0);

    // @method delete @digest Delete points
    // @description Delete some points from the diagram (from their indices).
    // @marg 0 @name points @optional 0 @type llll
    // @example delete 2 4 5 @caption delete some points
    // @ßeealso add
    class_addmethod(c, (method) circle_anything, "delete", A_GIMME, 0);

    // @method transpose @digest Transpose 
    // @description Rotate ("transpose") all the points in the diagram of a given amout, given 
    // in steps: a positive amount will rotate clockwise, a negative one will rotate counterclockwise.
    // @marg 0 @name amount @optional 0 @type int
    // @example transpose 3 @caption rotate of 3 steps clockwise
    // @example transpose -3 @caption rotate of 1 steps counterclockwise
    // @seealso invert, complement
    class_addmethod(c, (method) circle_anything, "transpose", A_GIMME, 0);

    // @method complement @digest Get the complement 
    // @description Get the complement of the existing diagram, i.e. the one formed by all the point
    // which were not in the original diagram. The velocities of such complemented points are
    // assigned by default.
    // @seealso invert, transpose
    class_addmethod(c, (method) circle_anything, "complement", A_GIMME, 0);

    // @method invert @digest Invert 
    // @description Mirror ("invert") all the points with respect to the vertical axis
    // drawn by the center and the upper point (0).
    // @seealso transpose, complement
    class_addmethod(c, (method) circle_anything, "invert", A_GIMME, 0);

    // @method (mouse) @digest Add/delete points, or change their velocities
    // @description 
    // • <m>click</m>: Add a point <br />
    // • <m>Alt+click</m>: Output clicked point index, in the form <b>point <m>pt</m></b>, where <m>pt</m> is as usual the point index. <br />
    // • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win): Delete a point <br />
    // • <m>Ctrl+click+drag</m> (mac) or <m>Shift+Ctrl+click+drag</m> (win): Change the velocity of a point (dragging up or down) <br /> 
    // • <m>Ctrl+Alt+click+drag</m> (mac) or <m>Shift+Ctrl+Alt+click+drag</m> (win): Change the modulo (dragging up or down)
    class_addmethod(c, (method) circle_mousedown, "mousedown", A_CANT, 0);
    class_addmethod(c, (method) circle_mousedrag, "mousedrag", A_CANT, 0);
    class_addmethod(c, (method) circle_mouseup, "mouseup", A_CANT, 0);
    class_addmethod(c, (method) circle_mousemove, "mousemove", A_CANT, 0);

    // @method (keyboard) @digest Modify points or dump
    // @description 
    // • <m>Cmd+T</m> (mac) or <m>Ctrl+T</m> (win): Transpose (rotate) 1 step clockwise <br />
    // • <m>Cmd+R</m> (mac) or <m>Ctrl+R</m> (win): Transpose (rotate) 1 step counterclockwise <br />
    // • <m>Cmd+C</m> (mac) or <m>Ctrl+C</m> (win): Take the complement <br />
    // • <m>Cmd+I</m> (mac) or <m>Ctrl+I</m> (win): Invert with respect to vertical axis <br />
    // • <m>Cmd+Shift+D</m> (mac) or <m>Ctrl+Shift+D</m> (win): Dump (output modulo, velocities and points)
      class_addmethod(c, (method) circle_key, "key", A_CANT, 0);

    class_addmethod(c, (method) circle_setinterleaved, "setinterleaved", A_GIMME, 0);
    class_addmethod(c, (method) circle_preset, "preset", 0);

    class_addmethod(c, (method) circle_focusgained, "focusgained", A_CANT, 0);
    class_addmethod(c, (method) circle_focuslost, "focuslost", A_CANT, 0); 

    class_addmethod(c, (method) circle_inletinfo, "inletinfo", A_CANT, 0);
    class_addmethod(c, (method) circle_assist, "assist", A_CANT, 0);

    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_UI);

    CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 120 120"); // new dimensions
    // @exclude bach.circle

    CLASS_STICKY_ATTR(c,"category",0,"Color");

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "textcolor", 0, t_circle, j_bgcolor, "Text Color", "text_number");
        CLASS_ATTR_LEGACYDEFAULT(c, "textcolor", "textcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_BASIC(c, "textcolor", 0);
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"textcolor", "numberstextcolor");
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"textcolor", "modulotextcolor");
        // @exclude all
#else
        CLASS_ATTR_RGBA(c, "modulotextcolor", 0, t_circle, j_textcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "modulotextcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "modulotextcolor", 0, "rgba", "Modulo Text Color");
        // @description Color of the modulo text.

        CLASS_ATTR_RGBA(c, "numberstextcolor", 0, t_circle, j_textcolornumbers);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "numberstextcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "numberstextcolor", 0, "rgba", "Numbers Text Color");
        // @description Color of the numbers text.

        CLASS_ATTR_RGBA(c, "textcolor", 0, t_circle, j_textcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
        // @description Color of the text.
#endif

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "bgcolor", 0, t_circle, j_bgcolor, "Background Color", "rect_fill");
        CLASS_ATTR_LEGACYDEFAULT(c, "bgcolor", "bgcolor", 0, "1. 1. 1. 1.");
        CLASS_ATTR_BASIC(c, "bgcolor", 0);
        // @description Diagram external background color
#else
        CLASS_ATTR_RGBA(c, "bgcolor", 0, t_circle, j_bgcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "1. 1. 1. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
        CLASS_ATTR_BASIC(c, "bgcolor",0);
#endif

        CLASS_ATTR_RGBA(c, "bordercolor", 0, t_circle, j_bordercolor);
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0. 0. 0. 0.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0.2 0.2 0.2 1.");
#endif
        CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");
        // @description Color of the diagram border

        CLASS_ATTR_RGBA(c, "circlebordercolor", 0, t_circle, j_circlebordercolor);
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "circlebordercolor", 0, "0. 0. 0. 0.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "circlebordercolor", 0, "0.2 0.2 0.2 1.");
#endif
        CLASS_ATTR_STYLE_LABEL(c, "circlebordercolor", 0, "rgba", "Circle Border Color");
        // @description Color of the diagram circle outline

        CLASS_ATTR_RGBA(c, "circleinnercolor", 0, t_circle, j_circleinnercolor);
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "circleinnercolor", 0, "0.6 0.6 0.6 1.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "circleinnercolor", 0, "0.94 0.89 0.89 1.");
#endif
        CLASS_ATTR_STYLE_LABEL(c, "circleinnercolor", 0, "rgba", "Circle Inner Color");
        // @description Inner color of the diagram circle

        CLASS_ATTR_RGBA(c, "pointbordercolor", 0, t_circle, j_pointbordercolor);
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "pointbordercolor", 0, "0. 0. 0. 0.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "pointbordercolor", 0, "0.6 0. 0. 1.");
#endif
        CLASS_ATTR_STYLE_LABEL(c, "pointbordercolor", 0, "rgba", "Point Border Color");
        // @description Color of each point's outline

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "pointinnercolor", 0, t_circle, j_pointinnercolor, "Point Inner Color", "circle_fill");
        class_attr_stylemap(c, (char *)"pointinnercolor", (char *)"elementcolor");
        CLASS_ATTR_LEGACYDEFAULT(c, "pointinnercolor", "pointinnercolor", 0, "1. 1. 1. 1.");
        // @description Color of the inner part of each point.
#else
        CLASS_ATTR_RGBA(c, "pointinnercolor", 0, t_circle, j_pointinnercolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "pointinnercolor", 0, "1. 1. 1. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "pointinnercolor", 0, "rgba", "Point Inner Color");
#endif
    
        CLASS_ATTR_RGBA(c, "selectedpointbordercolor", 0, t_circle, j_selectedpointbordercolor);
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "selectedpointbordercolor", 0, "0. 0. 0. 0.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "selectedpointbordercolor", 0, "0.6 0. 0. 1.");
#endif
        CLASS_ATTR_STYLE_LABEL(c, "selectedpointbordercolor", 0, "rgba", "Selected Point Border Color");
        // @description Color of the selected point's outline

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "selectioncolor", 0, t_circle, j_selectedpointinnercolor, "Selection Color", "circle_fill");
        CLASS_ATTR_LEGACYDEFAULT(c, "selectioncolor", "selectedpointinnercolor", 0, "0.83 0.47 0. 1.");
        class_attr_stylemap(c, (char *)"selectioncolor", (char *)"color");
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"selectioncolor", "selectedpointinnercolor");
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"selectioncolor", "linecolor");
        // @description Color of the selected items and polygonal line.
#else
        CLASS_ATTR_RGBA(c, "selectedpointinnercolor", 0, t_circle, j_selectedpointinnercolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "selectedpointinnercolor", 0, "0.83 0.47 0. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "selectedpointinnercolor", 0, "rgba", "Selected Point Inner Color");

        CLASS_ATTR_RGBA(c, "linecolor", 0, t_circle, j_linecolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "linecolor", 0, "0.8 0. 0. 0.6");
        CLASS_ATTR_STYLE_LABEL(c, "linecolor", 0, "rgba", "Line Color");
#endif
    CLASS_STICKY_ATTR_CLEAR(c, "category");


    CLASS_STICKY_ATTR(c,"category",0,"Value");

        // max and min attributes
        CLASS_ATTR_LONG(c,"modulo",0, t_circle, modulo);
        CLASS_ATTR_STYLE_LABEL(c,"modulo",0,"text","Modulo");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"modulo",0,"12");
        CLASS_ATTR_FILTER_MIN(c, "modulo", 1);
        CLASS_ATTR_BASIC(c,"modulo",0);
        // @description Modulo of the diagram (the number of steps in which the circle is divided)

        CLASS_ATTR_LONG_VARSIZE(c, "points", 0, t_circle, points, num_points, CONST_MAX_POINTS);
        CLASS_ATTR_STYLE_LABEL(c,"points",0,"text","Points");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"points",0,"");
        CLASS_ATTR_BASIC(c,"points",0);
        // @description List of the selected points in the diagram.

        CLASS_ATTR_LONG_VARSIZE(c, "velocities", 0, t_circle, vels, num_points, CONST_MAX_POINTS);
        CLASS_ATTR_STYLE_LABEL(c,"velocities",0,"text","Velocities");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"velocities",0,"");
        // @description List of the velocities corresponding to the selected points (on element
        // for each of the defined <m>points</m>

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c,"category",0,"Settings");

        CLASS_ATTR_CHAR(c, "autoreduce", 0, t_circle, auto_reduce);
        CLASS_ATTR_STYLE_LABEL(c,"autoreduce",0,"onoff","Automatically Delete Duplicates");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autoreduce",0,"1");
        CLASS_ATTR_ACCESSORS(c, "autoreduce", (method)NULL, (method)circle_setattr_autoreduce);
        // @description Automatically delete duplicates of points (if two or more points with the
        // same index, up to the modulo, were defined).
        
        CLASS_ATTR_ATOM_VARSIZE(c, "names", 0, t_circle, names, num_names, CONST_MAX_POINT_NAMES);
        CLASS_ATTR_STYLE_LABEL(c,"names",0,"text","Point Names");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"names",0,"");
        // @description Assign name to each point in the clock, instead of number. One can use
        // this attribute to individually naming each point, e.g. by setting
        // [names do do# re re# mi fa fa# sol sol# la sib si]
        // and displaying latin notes instead of numbers.
    
        CLASS_ATTR_CHAR(c, "sendnamesthroughdump", 0, t_circle, send_names_through_dump);
        CLASS_ATTR_STYLE_LABEL(c,"sendnamesthroughdump",0,"onoff","Send Names Through Dump");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"sendnamesthroughdump",0,"1");
        // @description If <m>names</m> are defined, this attribute tells whether those names must be
        // sent through the first outlet instead of point indices.
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c,"category",0,"Show");
    
        CLASS_ATTR_CHAR(c,"showmodulo",0, t_circle, show_modulo);
        CLASS_ATTR_STYLE_LABEL(c,"showmodulo",0,"onoff","Show Modulo");
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showmodulo",0,"0");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showmodulo",0,"1");
#endif
        CLASS_ATTR_BASIC(c,"showmodulo",0);
        // @description Show the modulo in the middle of the diagram
    
        CLASS_ATTR_CHAR(c,"shownumbers",0, t_circle, show_numbers);
        CLASS_ATTR_STYLE_LABEL(c,"shownumbers",0,"enumindex","Show Numbers");
        CLASS_ATTR_ENUMINDEX(c,"shownumbers", 0, "Never Mouseover Selected Always"); 
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"shownumbers",0,"1");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"shownumbers",0,"0");
#endif
        CLASS_ATTR_BASIC(c,"shownumbers",0);
        // @description Attribute deciding when the numbers in the diagram must be shown
        // (or the names, in case the <m>names</m> attribute is defined <br />
        // <m>Never</m>: never show any number <br />
        // <m>Mouseover</m>: Only show numbers when the mouse is over them<br />
        // <m>Selected</m>: Only show numbers when the corresponding point is selected<br />
        // <m>Always</m>: Always show all the numbers

        CLASS_ATTR_CHAR(c,"showpolygon",0, t_circle, show_polygon);
        CLASS_ATTR_STYLE_LABEL(c,"showpolygon",0,"onoff","Show Polygon");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showpolygon",0,"1");
        CLASS_ATTR_BASIC(c,"showpolygon",0);
        // @description Show the polygon linking all the selected numbers.

        CLASS_ATTR_CHAR(c,"showfocus",0, t_circle, show_focus);
        CLASS_ATTR_STYLE_LABEL(c,"showfocus",0,"onoff","Show Focus");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showfocus",0,"1");
        // @description Show that the object has the focus by increasing the width of the border.
    
        CLASS_ATTR_CHAR(c, "showvelocity", 0, t_circle, velocity_handling);
        CLASS_ATTR_STYLE_LABEL(c,"showvelocity",0,"enumindex","Show Velocity");
        CLASS_ATTR_ENUMINDEX(c,"showvelocity", 0, "None Colorscale Colorspectrum Alpha Circle Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showvelocity",0,"0");
        // @description Attribute deciding how the velocity of a point must be mapped visually:
        // <m>None</m>: velocity must be graphically ignored<br />
        // <m>Colorscale</m>: by changing the lightness of the point inner color<br />
        // <m>Colorspectrum</m>: by changing the point inner color over a spectrum of colors (red to blue) <br />
        // <m>Alpha</m>: by changing the alpha channel (transparent to full) <br />
        // <m>Circle Size</m>: by changing the point circle size
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    CLASS_STICKY_ATTR(c, "category", 0, "Appearance"); 

        CLASS_ATTR_DOUBLE(c,"pointradius",0, t_circle, point_radius);
        CLASS_ATTR_STYLE_LABEL(c,"pointradius",0,"text","Point Radius");
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"pointradius",0,"5.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"pointradius",0,"4.");
#endif
        CLASS_ATTR_FILTER_MIN(c, "pointradius", 0.);
        // @description Radius of each point in pixels

        CLASS_ATTR_DOUBLE(c,"inset",0, t_circle, inset);
        CLASS_ATTR_STYLE_LABEL(c,"inset",0,"text","Inset");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"inset",0,"7.");
        // @description Inset of the clock diagram with respect to the border, in pixels

        CLASS_ATTR_DOUBLE(c,"linewidth",0, t_circle, line_width);
        CLASS_ATTR_STYLE_LABEL(c,"linewidth",0,"text","Line Width");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linewidth",0,"2.");
        CLASS_ATTR_FILTER_MIN(c, "linewidth", 0.);
        // @description Width of the line linking all selected points together, in pixels

        CLASS_ATTR_DOUBLE(c,"circlelinewidth",0, t_circle, circle_line_width);
        CLASS_ATTR_STYLE_LABEL(c,"circlelinewidth",0,"text","Circle Line Width");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"circlelinewidth",0,"1.");
        CLASS_ATTR_FILTER_MIN(c, "circlelinewidth", 0.);
        // @description Width of the line of the main circle in the diagram, in pixels

        CLASS_ATTR_DOUBLE(c,"pointlinewidth",0, t_circle, point_line_width);
        CLASS_ATTR_STYLE_LABEL(c,"pointlinewidth",0,"text","Point Line Width");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"pointlinewidth",0,"1.");
        CLASS_ATTR_FILTER_MIN(c, "pointlinewidth", 0.);
        // @description Width of the line of each point's circle, in pixels

    CLASS_STICKY_ATTR_CLEAR(c, "category"); 

    s_circle_class = c;
    class_register(CLASS_BOX, s_circle_class);
    
    dev_post("bach.circle compiled %s %s", __DATE__, __TIME__);
    return;
}

t_max_err circle_setattr_autoreduce(t_circle *x, t_object *attr, long ac, t_atom *av){
    if (ac) {
        x->auto_reduce = atom_getlong(av);
        if (x->auto_reduce)
            reduce_points(x);
    }
    return MAX_ERR_NONE;
}


void circle_assist(t_circle *x, void *b, long m, long a, char *s){
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
            sprintf(s, "bang When Circle Changed"); // @description A bang is output whenever the user changes the diagram via mouse and keyboard
    }
}

void circle_inletinfo(t_circle *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void circle_int(t_circle *x, t_atom_long num)
{
    t_atom argv[1]; atom_setlong(argv, num);
    circle_anything(x, _llllobj_sym_list, 1, argv);
}

void circle_float(t_circle *x, double num){
    t_atom argv[1]; atom_setfloat(argv, num);
    circle_anything(x, _llllobj_sym_list, 1, argv);
}

void send_values(t_circle *x) {
    t_llll *out0 = points2llll(x, x->send_names_through_dump);
    t_llll *out1 = vels2llll(x);
    llllobj_outlet_int((t_object *) x, LLLL_OBJ_UI, 2, x->modulo);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 1, out1);
    llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 0, out0);
    llll_free(out0);
    llll_free(out1);
}

void circle_dump(t_circle *x, t_symbol *s, long argc, t_atom *argv){
    send_values(x);
}

void circle_setinterleaved(t_circle *x, t_symbol *s, long argc, t_atom *argv){
    long i;
    long limit = argc - (argc%2);
    t_atom *av = argv;

    if (argc % 2) // last element is modulo
        x->modulo = atom_getlong(argv + argc - 1);
    
    systhread_mutex_lock(x->c_mutex);
    x->num_points = limit/2;
    for (i = 0; i < limit/2; i++, av+=2) {
        x->points[i] = atom_getlong(av);
        x->vels[i] = atom_getlong(av+1);
    }
    sort_points(x);
    systhread_mutex_unlock(x->c_mutex);
    jbox_redraw((t_jbox *) x);
}

void circle_anything(t_circle *x, t_symbol *s, long argc, t_atom *argv){ //argv+1
    
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
                transpose_circle(x, hatom_getlong(&inllll->l_head->l_next->l_hatom));
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_complement) {
            complement_circle(x);
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_invert) {
            invert_circle(x);
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
}

t_circle* circle_new(t_symbol *s, long argc, t_atom *argv){
    t_circle* x = NULL;
    t_max_err err = MAX_ERR_GENERIC;
    t_dictionary *d;
    t_object *textfield;
    long flags;

    if (!(d=object_dictionaryarg(argc,argv)))
        return NULL;

    x = (t_circle*) object_alloc_debug(s_circle_class);
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

    x->num_points = 0;
    x->is_modulo_dragging = 0;
    x->show_focus = 1;
    x->j_has_focus = 0;
    x->velocity_handling = 1;
    x->is_velocity_dragging = -1;
    x->mouseover_pt = -1;
    
    
    // retrieve saved attribute values
    attr_dictionary_process(x, d);


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

void circle_free(t_circle *x){
    long i;
    for (i = 1; i < 3; i++)
        object_free_debug(x->n_proxy[i]);
    jbox_free(&x->j_box.l_box);
    systhread_mutex_free_debug(x->c_mutex);
    llllobj_jbox_free((t_llllobj_jbox *) x);
}

t_llll *points2llll(t_circle *x, char use_symbols){
    t_llll *ptsllll = llll_get();
    long i;
    for (i = 0; i < x->num_points; i++) {
        long j = x->points[i];
        if (use_symbols && j < x->num_names) {
            if (atom_gettype(&x->names[j]) == A_SYM)
                llll_appendsym(ptsllll, atom_getsym(&x->names[j]), 0, WHITENULL_llll);
            else if (atom_gettype(&x->names[j]) == A_LONG)
                llll_appendlong(ptsllll, atom_getlong(&x->names[j]), 0, WHITENULL_llll);
            else if (atom_gettype(&x->names[j]) == A_FLOAT)
                llll_appenddouble(ptsllll, atom_getfloat(&x->names[j]), 0, WHITENULL_llll);
            else
                llll_appendsym(ptsllll, _llllobj_sym_empty_symbol, 0, WHITENULL_llll);
        } else
            llll_appendlong(ptsllll, j, 0, WHITENULL_llll);
    }
    return ptsllll;
}

t_llll *vels2llll(t_circle *x){
    t_llll *velsllll = llll_get();
    long i;
    for (i = 0; i < x->num_points; i++)
        llll_appendlong(velsllll, x->vels[i], 0, WHITENULL_llll);
    return velsllll;
}

void llll2points(t_circle *x, t_llll *ptsllll, t_llll *velsllll) {
    t_llllelem *elem1, *elem2;
    long i;
    for (elem1 = ptsllll->l_head, elem2 = velsllll ? velsllll->l_head : NULL, i = 0; elem1 && i < CONST_MAX_POINTS; elem1 = elem1->l_next, elem2 = elem2 ? elem2->l_next : NULL, i++) { 
        x->points[i] = hatom_getlong(&elem1->l_hatom);
        x->vels[i] = elem2 ? hatom_getlong(&elem2->l_hatom) : CONST_DEFAULT_VELOCITY;
    }
    x->num_points = i;
}

void sort_points(t_circle *x){
    t_llll **lists_to_order = (t_llll **) bach_newptr(2 * sizeof(t_llll *));
    long i;

    if (x->auto_reduce) {
        for (i = 0; i < x->num_points; i++) {
            x->vels[i] = CLAMP(x->vels[i], CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
            x->points[i] = x->points[i] % x->modulo;
            if (x->points[i] < 0)
                x->points[i] = x->modulo - x->points[i];
        }
    }

    if (x->num_points > 0) {
        lists_to_order[0] = points2llll(x, false);
        lists_to_order[1] = vels2llll(x);
        llll_multisort(lists_to_order, lists_to_order, 2, (sort_fn)llll_leq_elem);
        llll2points(x, lists_to_order[0], lists_to_order[1]);
        
        llll_free(lists_to_order[0]);
        llll_free(lists_to_order[1]);
    }
    
    if (x->auto_reduce)
        reduce_points(x);
    
    bach_freeptr(lists_to_order);
}

void reduce_points(t_circle *x){
    long k, i = 0;
    while (i < x->num_points - 1) {
        if (x->points[i] == x->points[i+1]) {
            for (k = i+1; k < x->num_points - 1; k++) {
                x->points[k] = x->points[k+1];
                x->vels[k] = x->vels[k+1];
            }
            x->num_points--;
        } else
            i++;
    }
}


char *id_to_name(t_circle *x, long id){
    char *number_txt; 
    if (id < x->num_names) {
        if (atom_gettype(&x->names[id]) == A_SYM) {
            number_txt = (char *) bach_newptr((strlen(atom_getsym(&x->names[id])->s_name) + 5) * sizeof(char));
            strcpy(number_txt, atom_getsym(&x->names[id])->s_name);
        } else if (atom_gettype(&x->names[id]) == A_LONG) {
            number_txt = (char *) bach_newptr(50 * sizeof(char));
            snprintf_zero(number_txt, 50, "%ld", atom_getlong(&x->names[id]));
        } else if (atom_gettype(&x->names[id]) == A_FLOAT) {
            number_txt = (char *) bach_newptr(50 * sizeof(char));
            snprintf_zero(number_txt, 50, "%.2f", atom_getfloat(&x->names[id]));
        } else {
            number_txt = (char *) bach_newptr(3 * sizeof(char));
            snprintf_zero(number_txt, 50, "%s", "");
        }
    } else {
        number_txt = (char *) bach_newptr(50 * sizeof(char));
        snprintf_zero(number_txt, 50, "%ld", id);
    }
    return number_txt;
}

void circle_paint(t_circle *x, t_object *view)
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
    t_jfont *jf_text = jfont_create_debug(font_name->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), jbox_get_fontsize((t_object *) x));

    t_jrgba j_bgcolor_r, j_pointinnercolor_r, j_selectedpointinnercolor_r, j_textcolor_r, j_linecolor_r;
    object_attr_getjrgba((t_object *)x, gensym("bgcolor"), &j_bgcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("textcolor"), &j_textcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("pointinnercolor"), &j_pointinnercolor_r);
    
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    object_attr_getjrgba((t_object *)x, gensym("selectioncolor"), &j_linecolor_r);
    j_selectedpointinnercolor_r = j_linecolor_r;
#else
    object_attr_getjrgba((t_object *)x, gensym("selectedpointinnercolor"), &j_selectedpointinnercolor_r);
    object_attr_getjrgba((t_object *)x, gensym("linecolor"), &j_linecolor_r);
#endif
    
    
    // background
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    paint_background((t_object *)x, g, &rect, &j_bgcolor_r, 0);
#else
    jgraphics_rectangle_rounded(g, 1., 1., rect.width - 2, rect.height - 2, 2, 2);
#endif
    jgraphics_set_source_jrgba(g, &j_bgcolor_r); jgraphics_fill(g);
    
    
    // center and radius
    get_radius_and_center(x, view, &radius, &center_x, &center_y);

    // main circle
    paint_circle(g, x->j_circlebordercolor, x->j_circleinnercolor, center_x, center_y, radius, x->circle_line_width);
    
    // hollow circles for points
    char *number_txt = NULL;
    double width, height;
    double number_center_x, number_center_y;
    for (i = 0; i < x->modulo; i++) {
        double sinus = sin(i * TWOPI / x->modulo);
        double cosinus = cos(i * TWOPI / x->modulo);
        double point_center_x = center_x + radius * sinus;
        double point_center_y = center_y - radius * cosinus;

        // point circle
        paint_circle(g, x->j_pointbordercolor, j_pointinnercolor_r, point_center_x, point_center_y, x->velocity_handling == 4 ? 1. : x->point_radius, x->point_line_width);
        
        // write number?
        if (x->show_numbers == 3 || (x->show_numbers == 1 && x->mouseover_pt == i)) { // always
            number_center_x = point_center_x - 2 * x->point_radius * sinus;
            number_center_y = point_center_y + 2 * x->point_radius * cosinus;
            number_txt = id_to_name(x, i);
            jfont_text_measure(jf_text, number_txt, &width, &height);

            number_center_x -= sinus * width/2.;
            number_center_y += cosinus * width/2.;
            
            t_jtextlayout *jtl = jtextlayout_create();
            jtextlayout_set(jtl, number_txt, jf_text, number_center_x - width/2., number_center_y - height/2., width, height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
            jtextlayout_settextcolor(jtl, &j_textcolor_r);
            jtextlayout_draw(jtl, g);
            jtextlayout_destroy(jtl);
            bach_freeptr(number_txt);
            number_txt = NULL;
        }
    }
    

    //  lines
    if (x->num_points >= 2 && x->show_polygon) {
        double point_center_x, point_center_y;
        jgraphics_set_source_jrgba(g, &j_linecolor_r); jgraphics_set_line_width(g, x->line_width);
        point_center_x = center_x + radius * sin(x->points[0] * TWOPI / x->modulo);
        point_center_y = center_y - radius * cos(x->points[0] * TWOPI / x->modulo);
        jgraphics_move_to(g, point_center_x, point_center_y);
        for (i = 0; i < x->num_points; i++) {
            // line to the next one, if any
            double next_center_x = center_x + radius * sin(x->points[i + 1 < x->num_points ? i+1 : 0] * TWOPI / x->modulo);
            double next_center_y = center_y - radius * cos(x->points[i + 1 < x->num_points ? i+1 : 0] * TWOPI / x->modulo);
            jgraphics_line_to(g, next_center_x, next_center_y);
        }
        jgraphics_close_path(g);
        jgraphics_stroke(g);
    }

    /*
    if (number_txt) { // what dos this do??? number_txt is always NULL here...
        t_jtextlayout *jtl = jtextlayout_create();
        jtextlayout_set(jtl, number_txt, jf_text, number_center_x - width/2., number_center_y - height/2., width, height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
        jtextlayout_settextcolor(jtl, &j_textcolor_r);
        jtextlayout_draw(jtl, g);
        jtextlayout_destroy(jtl);
        bach_freeptr(number_txt);
        number_txt = NULL;
   }
     */
    
    // circle for each point
    for (i = 0; i < x->num_points; i++) {
        double sinus = sin(x->points[i] * TWOPI / x->modulo);
        double cosinus = cos(x->points[i] * TWOPI / x->modulo);
        double point_center_x = center_x + radius * sinus;
        double point_center_y = center_y - radius * cosinus;
        t_jrgba pointcolor = j_selectedpointinnercolor_r;
        double point_radius = x->point_radius;
        
        // getting color for point
        if (x->velocity_handling == 0){ // no handling
            // nothing to do
        } else if (x->velocity_handling == 1) { // building colorscale
            double temp = (1. - (((double)x->vels[i] - CONST_MIN_VELOCITY)/(CONST_MAX_VELOCITY - CONST_MIN_VELOCITY)));
            //rescaling the temp
            temp = temp * 0.8;
            pointcolor.red = (1. - temp) * pointcolor.red + temp; 
            pointcolor.blue = (1. - temp) * pointcolor.blue + temp; 
            pointcolor.green = (1. - temp) * pointcolor.green + temp;
        } else if (x->velocity_handling == 2){ // colourspectrum
            double temp = 2. * (((double)x->vels[i] - CONST_MIN_VELOCITY)/(CONST_MAX_VELOCITY - CONST_MIN_VELOCITY));
            pointcolor.red = (temp < 1.) ? (1. - temp) : 0.; 
            pointcolor.green = (((temp >= 0.) && (temp < 1.)) ? temp : 0.) + (((temp >= 1.) && (temp < 2.)) ? (2. - temp) : 0.); 
            pointcolor.blue = (temp >= 1.) ? (temp - 1.) : 0.; 
        } else if (x->velocity_handling == 3) { // changing alpha
            pointcolor.alpha *= (((double)x->vels[i] - CONST_MIN_VELOCITY)/(CONST_MAX_VELOCITY - CONST_MIN_VELOCITY));
        } else if (x->velocity_handling == 4) { // changing circle size
            point_radius *= (((double)x->vels[i])/CONST_MAX_VELOCITY);
        }
        
        // point circle
        paint_circle(g, x->j_selectedpointbordercolor, pointcolor, point_center_x, point_center_y, point_radius, x->point_line_width);

        // write number?
        if (x->show_numbers == 2) { // selected
            double number_center_x = point_center_x - 2 * point_radius * sinus;
            double number_center_y = point_center_y + 2 * point_radius * cosinus;
            
            t_jtextlayout *jtl = jtextlayout_create();
            double width, height;
            char *number_txt = id_to_name(x, x->points[i]); 
            
            jfont_text_measure(jf_text, number_txt, &width, &height);

            number_center_x -= sinus * width/2.;
            number_center_y += cosinus * width/2.;
                        
            jtextlayout_set(jtl, number_txt, jf_text, number_center_x - width/2., number_center_y - height/2., width, height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
            jtextlayout_settextcolor(jtl, &j_textcolor_r);
            jtextlayout_draw(jtl, g);
            jtextlayout_destroy(jtl);
            bach_freeptr(number_txt);
            number_txt = NULL;
        }
    }
    
    
    // modulo
    if (x->show_modulo) {
        t_jtextlayout *jtl = jtextlayout_create();
        char modulo_txt[50]; 
        double width, height;
        snprintf_zero(modulo_txt, 50, "%ld", x->modulo);
        jfont_text_measure(jf_text, modulo_txt, &width, &height);
        jtextlayout_set(jtl, modulo_txt, jf_text, center_x - width/2., center_y - height/2., width, height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
        jtextlayout_settextcolor(jtl, &j_textcolor_r);
        jtextlayout_draw(jtl, g);
        jtextlayout_destroy(jtl);
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


void circle_focusgained(t_circle *x, t_object *patcherview) {
//    object_post((t_object *)x, "focusgained"); 
    x->j_has_focus = true;
    jbox_redraw((t_jbox *)x);
}

void circle_focuslost(t_circle *x, t_object *patcherview) {
//    object_post((t_object *)x, "focuslost"); 
    x->j_has_focus = false;
    jbox_redraw((t_jbox *)x);
}

// returns info if a certain number is selected and which is its velocity
void get_number_info(t_circle *x, long number, char *selected, long *velocity){
    long j;
    *selected = false;
    for (j = 0; j < x->num_points; j++){
        if (x->points[j] == number) {
            *selected = true;
            *velocity = x->vels[j];
        }
    }
}

void get_radius_and_center(t_circle *x, t_object *patcherview, double *radius, double *center_x, double *center_y){
    t_rect rect;
    jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect); // rect dimension
    
    // center and radius
    *center_x = rect.width/2;
    *center_y = rect.height/2; 
    *radius = MIN(*center_x - x->point_radius - x->inset, *center_y - x->point_radius - x->inset);
}

long pixel_coordinates_to_point_number(t_circle *x, t_object *patcherview, double pt_x, double pt_y){
    double center_x, center_y, radius;
    long i;
    
    get_radius_and_center(x, patcherview, &radius, &center_x, &center_y);
    
    for (i = x->modulo - 1; i >= 0; i--) {
        double point_center_x = center_x + radius * sin(i * TWOPI / x->modulo);
        double point_center_y = center_y - radius * cos(i * TWOPI / x->modulo);
        double point_radius = x->point_radius;
        
        if (x->velocity_handling == 4){
            long velocity = 0; 
            char selected;
            get_number_info(x, i, &selected, &velocity);
            if (selected)
                point_radius = MAX(x->point_radius * velocity/CONST_MAX_VELOCITY, 1);
            else
                point_radius = 1;
        }        
        
        if ((pt_x - point_center_x)*(pt_x - point_center_x) + (pt_y - point_center_y)*(pt_y - point_center_y) < 
                (point_radius + CONST_PIXEL_TOLERANCE_CLICK) * (point_radius + CONST_PIXEL_TOLERANCE_CLICK)) {
            return i;
        }
    }
    return -1;
}

void circle_mousemove(t_circle *x, t_object *patcherview, t_pt pt, long modifiers) {
    if (x->show_numbers == 1) {
        long mousemove_pt = pixel_coordinates_to_point_number(x, patcherview, pt.x, pt.y);
        if (x->mouseover_pt != mousemove_pt) {
            x->mouseover_pt = mousemove_pt;
            jbox_redraw((t_jbox *) x);
        }
    }
}

void circle_mousedown(t_circle *x, t_object *patcherview, t_pt pt, long modifiers){
    long i, clicked_pt;

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
                circle_anything(x, _sym_delete, 1, argv);
            } else {
                t_atom argv[4];
                atom_setsym(argv, _llllobj_sym_open_round_bracket);
                atom_setlong(argv + 1, clicked_pt);
                atom_setlong(argv + 2, CONST_DEFAULT_VELOCITY);
                atom_setsym(argv + 3, _llllobj_sym_closed_round_bracket);
                circle_anything(x, _sym_add, 4, argv);
            }
            // changed! -> bang
            llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        }
    } else if (modifiers & eAltKey && modifiers & eControlKey) {
        x->is_modulo_dragging = 1;
        x->dragging_modulo = x->modulo;
    }
}

void circle_mouseup(t_circle *x, t_object *patcherview, t_pt pt, long modifiers){
    if (x->is_modulo_dragging || (x->is_velocity_dragging > -1)) 
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);

    x->is_modulo_dragging = 0;
    x->is_velocity_dragging = -1;
}

void circle_mousedrag(t_circle *x, t_object *patcherview, t_pt pt, long modifiers){
    if (x->is_modulo_dragging) {
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
    }
}

void transpose_circle(t_circle *x, long steps) {
    t_llll *ptsllll, *velsllll;
    
    systhread_mutex_lock(x->c_mutex);
    ptsllll = points2llll(x, false);
    velsllll = vels2llll(x);
    pcset_transpose_inplace(&ptsllll, steps, x->modulo, false);
    llll2points(x, ptsllll, velsllll);
    sort_points(x);
    systhread_mutex_unlock(x->c_mutex);
    
    llll_free(ptsllll);
    llll_free(velsllll);
}

void invert_circle(t_circle *x) {
    t_llll *ptsllll, *velsllll;

    systhread_mutex_lock(x->c_mutex);
    ptsllll = points2llll(x, false);
    velsllll = vels2llll(x);
    pcset_invert_inplace(&ptsllll, x->modulo, false);
    llll2points(x, ptsllll, velsllll);
    sort_points(x);
    systhread_mutex_unlock(x->c_mutex);

    llll_free(ptsllll);
    llll_free(velsllll);
}

void complement_circle(t_circle *x) {
    t_llll *ptsllll, *compl_ll;
    
    systhread_mutex_lock(x->c_mutex);
    ptsllll = points2llll(x, false);
    compl_ll = pcset_complement(ptsllll, x->modulo);
    llll2points(x, compl_ll, NULL);
    systhread_mutex_unlock(x->c_mutex);

    llll_free(ptsllll);
    llll_free(compl_ll);
}

long circle_key(t_circle *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
    llll_format_modifiers(&modifiers, &keycode);

    if (keycode == 't' && modifiers & eCommandKey) {
        transpose_circle(x, 1);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'r' && modifiers & eCommandKey) {
        transpose_circle(x, -1);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'i' && modifiers & eCommandKey) {
        invert_circle(x);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'c' && modifiers & eCommandKey) {
        complement_circle(x);
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 3);
        jbox_redraw((t_jbox *) x);
        return 1;
    } else if (keycode == 'd' && modifiers & eCommandKey && modifiers & eShiftKey) {
        send_values(x);
        return 1;
    }
    return 0;
}
