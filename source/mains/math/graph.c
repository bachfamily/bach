/*
 *  graph.c
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
	graph.c
	
	@name 
	bach.graph
	
	@realname 
	bach.graph

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Plot a graph
	
	@description
	The purpose of <o>bach.graph</o> is to act as a simple graph plotter: once the expression 
	of the curve to draw has been set (in the first inlet) possibly along with its parameters 
	(in the second inlet), a bang will plot the curve. Vector representation are also possible.
	
	@discussion
	The syntax is exactly like the on in bach.expr. Notice that $f1 is always the free variable, 
	whereas the parameters are indicated by $f2, $f3, $f4... 
	The graph mode can be Cartesian, Parametric or Polar (depending on the <m>graphmode</m> attribute in the inspector).
	
	@category
	bach, bach objects, bach math, bach interface, U/I
	
	@keywords
	plot, graph, draw, function, display, vector, curve, parametric, polar, cartesian, coordinate, expression

	@palette
	YES
	
	@palette category
	bach, bach objects, bach math, bach interface

	@seealso
	bach.expr, plot~, Into The Matrix
	
	@owner
	Daniele Ghisi
*/


#include "math/llll_settheory.h"
#include "math/lexpr.h"
#include "graphics/bach_graphics.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "ext_critical.h"
#include <stdio.h>
#include <locale.h>
#include "ext_strings.h"

//#define CONST_MAX_FUNCTIONS 1
#define CONST_MAX_POINTS 1000000
#define CONST_TICK_SEMILENGTH 4
#define CONST_ARROW_SIZE 8.
#define CONST_VECTORS_ARROW_SIZE 12.
#define CONST_GRID_LINE_WIDTH 0.7
#define CONST_TICK_LINE_WIDTH 1.

typedef enum _graph_types{
	k_GRAPH_CARTESIAN = 0,
	k_GRAPH_POLAR = 1,
	k_GRAPH_PARAMETRIC = 2,
	k_GRAPH_CARTESIANPOINTS = 3,
	k_GRAPH_POLARPOINTS = 4,
} e_graph_types;

typedef enum _grid_types{
	k_GRID_NONE = 0,
	k_GRID_TICKS = 1,
	k_GRID_LATTICE = 2
} e_grid_types;

typedef enum _show_modes{
	k_MODE_LINES = 0,
	k_MODE_POINTS = 1,
	k_MODE_LINESANDPOINTS = 2,
	k_MODE_VECTORS = 3
} e_show_modes;


typedef struct _graph // [bach.graph] structure
{
	t_llllobj_jbox			j_box; // root object

	t_jrgba					j_textcolor;
	t_jrgba					j_axiscolor;
	t_jrgba					j_bgcolor;
	t_jrgba					j_bordercolor;
	t_jrgba					j_graphcolor;
	t_jrgba					j_gridcolor;
    t_jrgba					j_mousedowncolor;
	
	char					j_has_focus;
	char					show_focus;

	long					max_parameters;

	char					graph_type;
	char					show_xy_axis;
	char					show_unit_circle;
	char					show_labels;
	char					show_xy_labels;
	char					grid_type;
	double					min_x;
	double					max_x;
	double					min_y;
	double					max_y;
	double					min_t;
	double					max_t;
	double					min_theta;
	double					max_theta;
	double					grid_x_step;
	double					grid_y_step;
	double					grid_r_step;
	double					grid_theta_step;
	double					labels_x_step;
	double					labels_y_step;
	char					show_mode;
	double					linewidth;
	double					point_radius;
	
	long					curr_function;
	
	long					num_points; // real number of points on screen
	long					num_sampling_points; // value of the attribute
	double					*pts_x[1];
	double					*pts_y[1];

	t_lexpr					*n_lexpry;
	t_lexpr					*n_lexprx;
	t_lexpr					*n_lexprr;
		
	t_pt					mousedrag_pt;

	long					mousedown_point;
	long					mousehover_point;
    long                    clicked_point;
	char					has_been_dragged;

	char					rebuild; 
	char					save_data_with_patcher;
	char					allow_modifications;
	char					mouse_hover;
    char                    show_mousedown;

	void					*n_proxy;
	long					n_in;

	t_systhread_mutex		c_mutex;

} t_graph;


// global class pointer variable
t_class	*s_graph_class = NULL;

// functions
void graph_inletinfo(t_graph *x, void *b, long a, char *t);
void graph_assist(t_graph *x, void *b, long m, long a, char *s);

void graph_free(t_graph *x);

void graph_jsave(t_graph *x, t_dictionary *d);

void graph_focusgained(t_graph *x, t_object *patcherview);
void graph_focuslost(t_graph *x, t_object *patcherview);
void graph_mousedown(t_graph *x, t_object *patcherview, t_pt pt, long modifiers);
void graph_mousemove(t_graph *x, t_object *patcherview, t_pt pt, long modifiers);
void graph_mouseup(t_graph *x, t_object *patcherview, t_pt pt, long modifiers);
void graph_mousedrag(t_graph *x, t_object *patcherview, t_pt pt, long modifiers);
long graph_key(t_graph *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);

t_graph* graph_new(t_symbol *s, long argc, t_atom *argv);

void graph_paint(t_graph *x, t_object *view);

void graph_anything(t_graph *x, t_symbol *s, long argc, t_atom *argv);
void graph_int(t_graph *x, t_atom_long num);
void graph_float(t_graph *x, double num);
void graph_bang(t_graph *x);
void graph_dump(t_graph *x);
void graph_clear(t_graph *x);
void graph_add(t_graph *x, t_symbol *s, long argc, t_atom *argv);
void graph_remove(t_graph *x, t_symbol *s, long argc, t_atom *argv);
void graph_set(t_graph *x, t_symbol *s, long argc, t_atom *argv);
void graph_click(t_graph *x, long val);
void graph_setclick(t_graph *x, long val);

void graph_exprx(t_graph *x, t_symbol *s, long argc, t_atom *argv);
void graph_expry(t_graph *x, t_symbol *s, long argc, t_atom *argv);
void graph_exprr(t_graph *x, t_symbol *s, long argc, t_atom *argv);

void delete_point(t_graph *x, long point_number);
void move_point(t_graph *x, long point_number, double new_x, double new_y, char values_as_delta);
void pixel_to_xy(t_graph *x, t_object *patcherview, double pixel_x, double pixel_y, double *coord_x, double *coord_y);
long pixel_to_point_number(t_graph *x, t_object *patcherview, t_pt pt);
t_llll *get_xy_as_llll(t_graph *x);
void click_point(t_graph *x, long idx);

t_max_err graph_setattr_numpoints(t_graph *x, t_object *attr, long ac, t_atom *av);
t_max_err graph_setattr_minx(t_graph *x, t_object *attr, long ac, t_atom *av);
t_max_err graph_setattr_maxx(t_graph *x, t_object *attr, long ac, t_atom *av);
t_max_err graph_setattr_miny(t_graph *x, t_object *attr, long ac, t_atom *av);
t_max_err graph_setattr_maxy(t_graph *x, t_object *attr, long ac, t_atom *av);

t_max_err graph_setattr_numpoints(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->num_sampling_points = CLAMP(atom_getlong(av), 2, CONST_MAX_POINTS);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}

t_max_err graph_setattr_minx(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->min_x = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}

t_max_err graph_setattr_maxx(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->max_x = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}

t_max_err graph_setattr_miny(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->min_y = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}

t_max_err graph_setattr_maxy(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->max_y = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}


t_max_err graph_setattr_mint(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->min_t = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}

t_max_err graph_setattr_maxt(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->max_t = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}

t_max_err graph_setattr_mintheta(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->min_theta = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}

t_max_err graph_setattr_maxtheta(t_graph *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->max_theta = atom_getfloat(av);
		x->j_box.l_rebuild = 1;
	}
	return MAX_ERR_NONE;
}


void C74_EXPORT ext_main(void *moduleRef){
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.graph", 
						(method)graph_new,
						(method)graph_free,
						sizeof(t_graph),
						(method)NULL,
						A_GIMME,
						0L);
	
	c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//	jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
	jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR);	// include textfield and Fonts attributes
//	jbox_initclass(c, 0);
	
	class_addmethod(c, (method) graph_paint,			"paint", A_CANT, 0);

	// @method llll @digest Set equation parameters
	// @description A plain llll in the second inlet will set the values for all the parameters of the introduced equation.
	// Parameters correspond to all variables starting from $f2 onwards. So first element of this list will correspond to $f2,
	// second element to $f3, and so on. If there are no free parameters in the equation, this inlet is useless.
	// You can input elements as integers, floats or rational numbers, and then let <o>bach.graph</o> convert them to floats.
	class_addmethod(c, (method) graph_anything, "anything", A_GIMME, 0);
	class_addmethod(c, (method) graph_anything, "list", A_GIMME, 0);
	class_addmethod(c, (method) graph_int, "int", A_LONG, 0);
	class_addmethod(c, (method) graph_float, "float", A_FLOAT, 0);

	// @method list @digest Plot graph
	// @description Plot the graph of the most recently input equation, with the most recently input values of parameters.
	class_addmethod(c, (method) graph_bang, "bang", 0);

	// @method exprx @digest Define formula for X variable
	// @description In parametric mode (see <m>graphtype</m> attribute) you can define separately the expressions for the X and Y variables.
	// Via <m>exprx</m> one defines the formula for the X variable, as X = f(T), where T is the independent variable.
	// After the <m>exprx</m> symbol, a formula in <o>bach.expr</o> 
	// style is expected. The free variable T is represented by $f1.
	// For instance, a valid expression can be <b>exprx sin[$f1+cos[$f1]+$f2]</b>, where <b>$f2</b> is a parameter whose value has to be 
	// input from the right inlet.
	// @marg 0 @name expression @optional 0 @type llll
    // @exemple exprx sin($f1+cos($f1)) @caption define formula for x
    // @exemple exprx sin($f1+cos($f1*$f2)) @caption the same, $f2 being some parameter
    // @seealso expry, exprr, bang
	class_addmethod(c, (method) graph_exprx, "exprx", A_GIMME, 0);

	// @method expry @digest Define formula for Y variable
	// @description Via <m>expry</m> one defines the formula for the Y variable, either as Y = f(X), in cartesian mode, or as 
	// Y = f(T), in parametric mode (see <m>graphtype</m> attribute), where X and T are the indepentent variables.
	// After the <m>expry</m> symbol, a formula in <o>bach.expr</o> 
	// style is expected. The free variable X or T is represented by $f1.
	// For instance, a valid expression can be <b>expry sin[$f1*$f1+$f2]+$f3</b>, where <b>$f2</b> and <b>$f3</b> are parameters whose values 
	// have to be input from the right inlet.
	// @marg 0 @name expression @optional 0 @type llll
    // @exemple expry $f1*sin($f1*$f1) @caption define formula for y
    // @exemple expry $f2*sin($f1*$f1) @caption the same, $f2 being some parameter
    // @seealso exprx, exprr, bang
	class_addmethod(c, (method) graph_expry, "expry", A_GIMME, 0);


	// @method exprr @digest Define formula for R variable (radius)
	// @description In polar mode (see <m>graphtype</m> attribute), you can define the expression for the radius R with respect to the 
	// angle Theta, such as R = f(Theta), with Theta being the independent variable (angle in radians).
	// After the <m>exprr</m> symbol, a formula in <o>bach.expr</o> 
	// style is expected. The free variable Theta is represented by $f1.
	// For instance, a valid expression can be <b>exprr $f1*$f1</b>.
	// @marg 0 @name expression @optional 0 @type llll
    // @exemple exprr $f1 @caption map radius on angle (Archimedean spiral)
    // @exemple exprr $f2 + $f1 * log($f2+2) @caption define formula for radius, with $f2 being some parameter
    // @seealso exprx, expry, bang
	class_addmethod(c, (method) graph_exprr, "exprr", A_GIMME, 0);

	// @method clear @digest Clear the graph
	// @description Removes the displayed function from the graph. 
	class_addmethod(c, (method) graph_clear, "clear", 0);

	// @method dump @digest Output the graph points
	// @description The <m>dump</m> message outputs from <o>bach.graph</o>'s outlet the points of the graph in an interlaced list of 
	// X values and Y values such as <b>0. 0. 0.338538 1.91993 -7.327899 2.667156 -8.773019 -15.195196...</b>.
	// If you want to isolate couples, use <o>bach.group</o> with 2 as argument, which will get you to the form
	// <b>[0. 0.] [0.338538 1.91993] [-7.327899 2.667156] [-8.773019 -15.195196]...</b>
	// where each <b>X Y</b> couple is wrapped. <br />
	// The output points are the sampling that bach.graph does according to all the values of its attributes, except for the
	// Cartesian Points or Polar Points graph (see <m>graphtype</m> attribute), for which the output points are the ones
	// explicitely added by the user
	class_addmethod(c, (method) graph_dump, "dump", 0);


	// @method add @digest Add a point
	// @description The word <m>add</m> followed by two coordinates X and Y will add a point on the graph with such coordinates
	// (provided that the graph is a Cartesian Points or Polar Points type of graph, see <m>graphtype</m> attribute).
	// @marg 0 @name x_coord @optional 0 @type number
	// @marg 1 @name y_coord @optional 0 @type number
    // @example add 3 4 @caption add a point at x=3, y=4
    // @seealso remove, set
	class_addmethod(c, (method) graph_add, "add", A_GIMME, 0);

	// @method remove @digest Delete a point
	// @description To delete a point on the graph, send the word <m>remove</m> followed by the index of the point to be removed.
	// For instance, <b>remove 1</b> will remove the first introduced point. 
	// @marg 0 @name point-index @optional 0 @type int
    // @example remove 4 @caption remove 4th introduced point
    // @seealso add, set
	class_addmethod(c, (method) graph_remove, "remove", A_GIMME, 0);

	// @method set @digest Change the position of a point
	// @description To change the position of a point, send the word <m>set</m> followed by the index of the point to be moved 
	// and its two new coordinates X and Y.
	// This works provided that the graph is a Cartesian Points or Polar Points type of graph, see <m>graphtype</m> attribute.
	// For instance, <b>set 2 0 1</b> sets the second point to have cartesian coordinates (0 1). 
	// @marg 0 @name point-index @optional 0 @type int
	// @marg 1 @name X-coordinate @optional 0 @type llllelem
	// @marg 2 @name Y-coordinate @optional 0 @type llllelem
    // @example set 1 4 5 @caption set 1st introduced point at x=4, y=5
    // @seealso add, remove
	class_addmethod(c, (method) graph_set, "set", A_GIMME, 0);

    // @method setclick @digest Click on a point
    // @description For Cartesian Points or Polar Points type of graph, clicks on a given point
    // and triggers the following output (exactly as via <m>mouse</m> interaction).
    // @marg 0 @name point-index @optional 0 @type int
    // @example click 5 @caption simulate clicking on 5th introduced point
    // @seealso setclick
    class_addmethod(c, (method) graph_click, "click", A_LONG, 0);
    
    // @method setclick @digest Set the clicked point without triggering any output
    // @description For Cartesian Points or Polar Points type of graph, sets the currently clicked point
    // without triggering any output.
    // @marg 0 @name point-index @optional 0 @type int
    // @example setclick 5 @caption set 5th introduced point as clicked
    // @seealso click
    class_addmethod(c, (method) graph_setclick, "setclick", A_LONG, 0);
    
	class_addmethod(c, (method) graph_jsave, "jsave", A_CANT, 0);

	// @method (mouse) @digest Add, delete or move points
	// @description With the Cartesian Points or Polar Points types of graph (see <m>graphtype</m> attribute): <br />
	// • <m>click+drag</m>: If clicked on an existing point, moves the point <br />
	// • <m>Alt+click</m>: Adds a new point <br />
	// • <m>Cmd+click</m> (mac) or <m>Ctrl+click</m> (win): On an existing point, deletes the point <br />
	// and its two new coordinates X and Y.
	// All these command work provided that the graph is a Cartesian Points or Polar Points type of graph, see <m>graphtype</m> attribute.
	class_addmethod(c, (method) graph_mousedown, "mousedown", A_CANT, 0);
	class_addmethod(c, (method) graph_mousedrag, "mousedrag", A_CANT, 0);
	class_addmethod(c, (method) graph_mouseup, "mouseup", A_CANT, 0);
  	class_addmethod(c, (method) graph_key, "key", A_CANT, 0);
	class_addmethod(c, (method) graph_mousemove, "mousemove", A_CANT, 0);
/*	class_addmethod(c, (method) graph_mouseenter, "mouseenter", A_CANT, 0);
	class_addmethod(c, (method) graph_mouseleave, "mouseleave", A_CANT, 0);
	class_addmethod(c, (method) graph_mouseup, "mouseup", A_CANT, 0);
	class_addmethod(c, (method) graph_mousewheel, "mousewheel", A_CANT, 0); */

	class_addmethod(c, (method) graph_focusgained, "focusgained", A_CANT, 0);
	class_addmethod(c, (method) graph_focuslost, "focuslost", A_CANT, 0); 

	class_addmethod(c, (method) graph_inletinfo, "inletinfo", A_CANT, 0);
	class_addmethod(c, (method) graph_assist, "assist", A_CANT, 0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_UI);


	CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 260 260");
	// @exclude bach.graph
	CLASS_ATTR_DEFAULT(c, "presentation_rect", 0, "0 0 260 260");
	// @exclude bach.graph

	CLASS_STICKY_ATTR(c,"category",0,"Color");

		CLASS_ATTR_RGBA(c, "textcolor", 0, t_graph, j_textcolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0. 0. 0. 1.");
		CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
		// @description Sets the color for the labels on the axis.

		CLASS_ATTR_RGBA(c, "axiscolor", 0, t_graph, j_axiscolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "axiscolor", 0, "0. 0. 0. 1.");
		CLASS_ATTR_STYLE_LABEL(c, "axiscolor", 0, "rgba", "Axis Color");
		// @description Sets the color for the axis.

		CLASS_ATTR_RGBA(c, "bgcolor", 0, t_graph, j_bgcolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "1. 1. 1. 1.");
		CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
		CLASS_ATTR_BASIC(c,"bgcolor",0);
		// @description Sets the graph background color.

		CLASS_ATTR_RGBA(c, "bordercolor", 0, t_graph, j_bordercolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0.3 0.3 0.3 1.");
		CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");
		// @description Sets the graph border color.

		CLASS_ATTR_RGBA(c, "graphcolor", 0, t_graph, j_graphcolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "graphcolor", 0, "0. 0. 0. 1.");
		CLASS_ATTR_STYLE_LABEL(c, "graphcolor", 0, "rgba", "Graph Color");
		// @description Sets the color of the graph line.

		CLASS_ATTR_RGBA(c, "gridcolor", 0, t_graph, j_gridcolor);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "gridcolor", 0, "0.7 0.7 0.7 1.");
		CLASS_ATTR_STYLE_LABEL(c, "gridcolor", 0, "rgba", "Grid Color");
		CLASS_ATTR_BASIC(c,"gridcolor",0);
		// @description Sets the color of the graph grid.

        CLASS_ATTR_RGBA(c, "clickedcolor", 0, t_graph, j_mousedowncolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "clickedcolor", 0, "0.25 0.25 0.25 1.");
        CLASS_ATTR_STYLE_LABEL(c, "clickedcolor", 0, "rgba", "Clicked Point Color");
        CLASS_ATTR_BASIC(c,"clickedcolor",0);
        // @description Sets the color of the clicked points (in Cartesian or Polar Points mode only).

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c, "category", 0, "Behavior"); 

		CLASS_ATTR_CHAR(c,"embed",0, t_graph, save_data_with_patcher);
		CLASS_ATTR_STYLE_LABEL(c,"embed",0,"onoff","Save Data With Patcher");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"embed",0,"1");
		CLASS_ATTR_BASIC(c,"embed",0);
		// @description Toggles the ability to embed the graph as a part of the patch, when this latter is saved.
		// The default behaviour is 1 (graph is saved).

		CLASS_ATTR_CHAR(c,"modify",0, t_graph, allow_modifications);
		CLASS_ATTR_STYLE_LABEL(c,"modify",0,"onoff","Allow Points Modifications");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"modify",0,"1");
		// @description Toggles the ability to allow modifications the graph points (only in Cartesian Points or Polar Points mode).
	
		CLASS_ATTR_CHAR(c, "mousehover", 0, t_graph, mouse_hover);
		CLASS_ATTR_STYLE_LABEL(c,"mousehover",0,"onoff","Allow Mouse Hovering");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mousehover",0,"1");
		// @description Toggles the ability to mouse hover on function slot points (only in Cartesian Points or Polar Points mode).
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c, "category", 0, "Settings"); 

		CLASS_ATTR_CHAR(c,"graphtype",0, t_graph, graph_type);
		CLASS_ATTR_STYLE_LABEL(c,"graphtype",0,"enumindex","Graph Type");
		CLASS_ATTR_ENUMINDEX(c,"graphtype", 0, "Cartesian Polar Parametric Cartesian Points Polar Points"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"graphtype",0,"0");
		CLASS_ATTR_BASIC(c,"graphtype",0);
		// @description Specifies the type of graph: <br />
		// <m>Cartesian</m>: A standard X = f(Y) cartesian graph <br />
		// <m>Polar</m>: A graph in the form R = f(Theta), with R radius and Theta angle in radians<br />
		// <m>Parametric</m>: A graph defined by X = f(T) and Y = g(T), with T being the indipendent "time" variable<br />
		// <m>Cartesian Points</m>: A cartesian graph, but where the user inserts the points one by one, instead of the function formula<br />
		// <m>Polar Points</m>: A polar graph, but where the user inserts the points one by one, instead of the function formula

		CLASS_ATTR_LONG(c,"numpoints",0, t_graph, num_sampling_points);
		CLASS_ATTR_STYLE_LABEL(c,"numpoints",0,"text","Number Of Points");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"numpoints",0,"1000");
		CLASS_ATTR_FILTER_CLIP(c, "numpoints", 2, CONST_MAX_POINTS);
		CLASS_ATTR_ACCESSORS(c, "numpoints", (method)NULL, (method)graph_setattr_numpoints);
		CLASS_ATTR_BASIC(c,"numpoints",0);
		// @description Number of points in which the equation is sampled (cannot exceed 1000).
		// The boundaries for this sampling are given by the various <m>minx</m>, <m>maxx</m>,
		// <m>mint</m>, <m>maxt</m>, <m>mintheta</m>, <m>maxtheta</m> attributes.

	CLASS_STICKY_ATTR_CLEAR(c, "category");

	CLASS_STICKY_ATTR(c, "category", 0, "Appearance"); 

		CLASS_ATTR_DOUBLE(c,"minx",0, t_graph, min_x);
		CLASS_ATTR_STYLE_LABEL(c,"minx",0,"text","Minimum X");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minx",0,"-5");
		CLASS_ATTR_ACCESSORS(c, "minx", (method)NULL, (method)graph_setattr_minx);
		CLASS_ATTR_BASIC(c,"minx",0);
		// @description Sets the minimum displayed X on the graph. 
		// For cartesian graphs (see <m>graphtype</m> attribute), this is also the minimum sampled X value.

		CLASS_ATTR_DOUBLE(c,"maxx",0, t_graph, max_x);
		CLASS_ATTR_STYLE_LABEL(c,"maxx",0,"text","Maximum X");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxx",0,"5");
		CLASS_ATTR_ACCESSORS(c, "maxx", (method)NULL, (method)graph_setattr_maxx);
		CLASS_ATTR_BASIC(c,"maxx",0);
		// @description Sets the maximum displayed X on the graph. 
		// For cartesian graphs (see <m>graphtype</m> attribute), this is also the maximum sampled X value.

		CLASS_ATTR_DOUBLE(c,"miny",0, t_graph, min_y);
		CLASS_ATTR_STYLE_LABEL(c,"miny",0,"text","Minimum Y");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"miny",0,"-5");
		CLASS_ATTR_ACCESSORS(c, "miny", (method)NULL, (method)graph_setattr_miny);
		CLASS_ATTR_BASIC(c,"miny",0);
		// @description Sets the minimum displayed Y on the graph.

		CLASS_ATTR_DOUBLE(c,"maxy",0, t_graph, max_y);
		CLASS_ATTR_STYLE_LABEL(c,"maxy",0,"text","Maximum Y");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxy",0,"5");
		CLASS_ATTR_ACCESSORS(c, "maxy", (method)NULL, (method)graph_setattr_maxy);
		CLASS_ATTR_BASIC(c,"maxy",0);
		// @description Sets the maximum displayed Y on the graph.

		CLASS_ATTR_DOUBLE(c,"mint",0, t_graph, min_t);
		CLASS_ATTR_STYLE_LABEL(c,"mint",0,"text","Minimum T");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mint",0,"0");
		CLASS_ATTR_ACCESSORS(c, "mint", (method)NULL, (method)graph_setattr_mint);
		// @description For parametric graphs (see <m>graphtype</m> attribute), sets the minimum sampled T value.

		CLASS_ATTR_DOUBLE(c,"maxt",0, t_graph, max_t);
		CLASS_ATTR_STYLE_LABEL(c,"maxt",0,"text","Maximum T");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxt",0,"100");
		CLASS_ATTR_ACCESSORS(c, "maxt", (method)NULL, (method)graph_setattr_maxt);
		// @description For parametric graphs (see <m>graphtype</m> attribute), sets the maximum sampled T value.

		CLASS_ATTR_DOUBLE(c,"mintheta",0, t_graph, min_theta);
		CLASS_ATTR_STYLE_LABEL(c,"mintheta",0,"text","Minimum Theta");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mintheta",0,"0");
		CLASS_ATTR_ACCESSORS(c, "mintheta", (method)NULL, (method)graph_setattr_mintheta);
		// @description For polar graphs (see <m>graphtype</m> attribute), sets the maximum sampled Theta value.

		CLASS_ATTR_DOUBLE(c,"maxtheta",0, t_graph, max_theta);
		CLASS_ATTR_STYLE_LABEL(c,"maxtheta",0,"text","Maximum Theta");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxtheta",0,"12.56636");
		CLASS_ATTR_ACCESSORS(c, "maxtheta", (method)NULL, (method)graph_setattr_maxtheta);
		// @description For polar graphs (see <m>graphtype</m> attribute), sets the maximum sampled Theta value.

		CLASS_ATTR_DOUBLE(c,"linewidth",0, t_graph, linewidth);
		CLASS_ATTR_STYLE_LABEL(c,"linewidth",0,"text","Line Width");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linewidth",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "linewidth", 0.);
		// @description Sets the width of the graph line.

		CLASS_ATTR_DOUBLE(c,"pointradius",0, t_graph, point_radius);
		CLASS_ATTR_STYLE_LABEL(c,"pointradius",0,"text","Point Radius");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"pointradius",0,"2.");
		CLASS_ATTR_FILTER_MIN(c, "pointradius", 0.);
		// @description Sets the radius for each point on the graph (see <m>showmode</m> attribute).

		CLASS_ATTR_CHAR(c,"showxyaxis",0, t_graph, show_xy_axis);
		CLASS_ATTR_STYLE_LABEL(c,"showxyaxis",0,"onoff","Show XY Axis");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showxyaxis",0,"1");
		// @description Toggles the view of the X and Y axis.

		CLASS_ATTR_CHAR(c,"showunitcircle",0, t_graph, show_unit_circle);
		CLASS_ATTR_STYLE_LABEL(c,"showunitcircle",0,"onoff","Show Unit Circle");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showunitcircle",0,"0");
		// @description Toggles the view of the unit circle.

		CLASS_ATTR_CHAR(c,"showlabels",0, t_graph, show_labels);
		CLASS_ATTR_STYLE_LABEL(c,"showlabels",0,"onoff","Show Labels");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showlabels",0,"1");
		// @description Toggles the view of the grid labels.

		CLASS_ATTR_CHAR(c,"showxylabels",0, t_graph, show_xy_labels);
		CLASS_ATTR_STYLE_LABEL(c,"showxylabels",0,"onoff","Show XY Axis Labels");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showxylabels",0,"1");
		// @description Toggles the view of the X and Y axis labels.

        CLASS_ATTR_CHAR(c,"showclicked",0, t_graph, show_mousedown);
        CLASS_ATTR_STYLE_LABEL(c,"showclicked",0,"onoff","Show Clicked Point");
    	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showclicked",0,"0");
        // @description Shows the clicked point via a special color circle (only for Cartesian or Polar Points mode).

		CLASS_ATTR_CHAR(c,"showmode",0, t_graph, show_mode);
		CLASS_ATTR_STYLE_LABEL(c,"showmode",0,"enumindex","Show Mode");
		CLASS_ATTR_ENUMINDEX(c,"showmode", 0, "Line Points Line And Points Vectors"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showmode",0,"0");
		CLASS_ATTR_BASIC(c,"showmode",0);
		// @description Sets the display mode for the graph: <br />
		// <m>Line</m>: A simple line shows the graph function <br />
		// <m>Points</m>: Points are drawn at the sampled locations, and no line is shown <br />
		// <m>Line And Points</m>: Both the line and the points are shown <br />
		// <m>Vectors</m>: Points in the graph are considered to be vectors and drawn with arrows starting from the origin.

		CLASS_ATTR_CHAR(c,"gridtype",0, t_graph, grid_type);
		CLASS_ATTR_STYLE_LABEL(c,"gridtype",0,"enumindex","Grid Type");
		CLASS_ATTR_ENUMINDEX(c,"gridtype", 0, "None Ticks Lattice"); 
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gridtype",0,"2");
		CLASS_ATTR_BASIC(c,"gridtype",0);
		// @description Sets the grid type: <br />
		// <m>None</m>: No grid is displayed<br />
		// <m>Ticks</m>: Ticks are displayed on the axis (and possibly on the unit circle)<br />
		// <m>Lattice</m>: The grid lines are properly displayed

		CLASS_ATTR_DOUBLE(c,"gridxstep",0, t_graph, grid_x_step);
		CLASS_ATTR_STYLE_LABEL(c,"gridxstep",0,"text","Grid X Interval");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gridxstep",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "gridxstep", 0.);
		CLASS_ATTR_BASIC(c,"gridxstep",0);
		// @description Sets the horizontal distance between two grid lines on the X axis.

		CLASS_ATTR_DOUBLE(c,"gridystep",0, t_graph, grid_y_step);
		CLASS_ATTR_STYLE_LABEL(c,"gridystep",0,"text","Grid Y Interval");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gridystep",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "gridystep", 0.);
		CLASS_ATTR_BASIC(c,"gridystep",0);
		// @description Sets the horizontal distance between two grid lines on the Y axis.

		CLASS_ATTR_DOUBLE(c,"gridrstep",0, t_graph, grid_r_step);
		CLASS_ATTR_STYLE_LABEL(c,"gridrstep",0,"text","Grid Radius Interval");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gridrstep",0,"1.");
		CLASS_ATTR_FILTER_MIN(c, "gridrstep", 0.);
		// @description Sets the distance between two concentric grid circles
		// for polar types of graph (see <m>graphtype</m> attribute).

		CLASS_ATTR_DOUBLE(c,"gridthetastep",0, t_graph, grid_theta_step);
		CLASS_ATTR_STYLE_LABEL(c,"gridthetastep",0,"text","Grid Angle Interval");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gridthetastep",0,"0.17453293");
		CLASS_ATTR_FILTER_MIN(c, "gridthetastep", 0.);
		// @description Sets the angle distance (in radians) between two grid directions
		// starting from the origin for polar types of graph (see <m>graphtype</m> attribute).

		CLASS_ATTR_DOUBLE(c,"labelsxstep",0, t_graph, labels_x_step);
		CLASS_ATTR_STYLE_LABEL(c,"labelsxstep",0,"text","X-Labels Interval");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"labelsxstep",0,"2.");
		CLASS_ATTR_FILTER_MIN(c, "labelsxstep", 0.);
		// @description Sets the distance between two consecutive labels on the X axis.

		CLASS_ATTR_DOUBLE(c,"labelsystep",0, t_graph, labels_y_step);
		CLASS_ATTR_STYLE_LABEL(c,"labelsystep",0,"text","Y-Labels Interval");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"labelsystep",0,"2.");
		CLASS_ATTR_FILTER_MIN(c, "labelsystep", 0.);
		// @description Sets the distance between two consecutive labels on the Y axis.

	CLASS_STICKY_ATTR_CLEAR(c, "category"); 

/*	CLASS_STICKY_ATTR(c, "category", 0, "Font"); 

		CLASS_ATTR_SYM(c,"textfont", 0, t_graph, textfont);
		CLASS_ATTR_STYLE_LABEL(c, "textfont",0,"font","Text Font");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"textfont",0,"Arial");

		CLASS_ATTR_DOUBLE(c,"textsize",0, t_graph, textsize);
		CLASS_ATTR_STYLE_LABEL(c,"textsize",0,"text","Text Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"textsize",0,"12.");

	CLASS_STICKY_ATTR_CLEAR(c, "category"); */

	s_graph_class = c;
	class_register(CLASS_BOX, s_graph_class);
	
	dev_post("bach.graph compiled %s %s", __DATE__, __TIME__);
	return;
}


void graph_assist(t_graph *x, void *b, long m, long a, char *s){
	if (m == ASSIST_INLET) {
		if (a == 0) // @in 0 @type bang @digest Set formulas or bang to plot graph
			sprintf(s, "bang to Plot Graph");
		else	// @in 1 @type llll @digest All the parameters of the inserted formulas
			sprintf(s, "llll: Parameters"); // @description The second inlet expects all the parameters of the formula
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
		if (a == 0) // @out 0 @type llll @digest Dumped interleaved list of X Y couples
			sprintf(s, "llll (%s): Interleaved List of X Y Couples", type);
		else if (a == 1) // @out 1 @type llll @digest Queries and notifications
			sprintf(s, "llll (%s): Queries and Notifications", type);
		else // @out 2 @type bang @digest bang when user changes the graph with the mouse
			sprintf(s, "bang When Changed");
	}
}

void graph_inletinfo(t_graph *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void graph_bang(t_graph *x)
{
	t_llll *parameters = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_UI, 1, 1);

	if (x->j_box.l_rebuild == 1 && proxy_getinlet((t_object *) x) == 0) {
		// compute points
		systhread_mutex_lock(x->c_mutex);
		if (x->graph_type == k_GRAPH_CARTESIAN) {
			if (!x->n_lexpry) {
				object_error((t_object *) x, "Insert expry expression first!");
			} else {
				t_hatom vars[LEXPR_MAX_VARS]; 
				t_hatom *res;
				t_llllelem *elem;
				long i;
				for (i = 1, elem = parameters->l_head; i < x->n_lexpry->l_numvars; elem = elem ? elem->l_next : NULL, i++){
					hatom_setdouble(vars + i, elem ? hatom_getdouble(&elem->l_hatom) : 0.);
				}
				for (i = 0; i < x->num_sampling_points; i++) {
					x->pts_x[x->curr_function][i] = x->min_x + (x->max_x - x->min_x) * (((double) i) / (x->num_sampling_points - 1));
					hatom_setdouble(vars, x->pts_x[x->curr_function][i]);
					res = lexpr_eval(x->n_lexpry, vars);
					x->pts_y[x->curr_function][i] = hatom_getdouble(res);
					bach_freeptr(res);
				}
				x->num_points = x->num_sampling_points;
			}
		} else if (x->graph_type == k_GRAPH_PARAMETRIC) {
			if (!x->n_lexprx) {
				object_error((t_object *) x, "Insert exprx expression first!");
			} else if (!x->n_lexpry) {
				object_error((t_object *) x, "Insert expry expression first!");
			} else {
				t_hatom varsx[LEXPR_MAX_VARS];
				t_hatom varsy[LEXPR_MAX_VARS];
				t_hatom *res;
				t_llllelem *elem;
				double this_t;
				long i;
				for (i = 1, elem = parameters->l_head; i < x->n_lexpry->l_numvars; elem = elem ? elem->l_next : NULL, i++)
					hatom_setdouble(varsy + i, elem ? hatom_getdouble(&elem->l_hatom) : 0.); 
				for (i = 1, elem = parameters->l_head; i < x->n_lexprx->l_numvars; elem = elem ? elem->l_next : NULL, i++)
					hatom_setdouble(varsx + i, elem ? hatom_getdouble(&elem->l_hatom) : 0.); 
				for (i = 0; i < x->num_sampling_points; i++) {
					this_t = x->min_t + (x->max_t - x->min_t) * (((double) i) / (x->num_sampling_points - 1));
					hatom_setdouble(varsx, this_t);
					hatom_setdouble(varsy, this_t);
					res = lexpr_eval(x->n_lexprx, varsx);
					x->pts_x[x->curr_function][i] = hatom_getdouble(res);
					bach_freeptr(res);
					res = lexpr_eval(x->n_lexpry, varsy);
					x->pts_y[x->curr_function][i] = hatom_getdouble(res);
					bach_freeptr(res);
				}
				x->num_points = x->num_sampling_points;
			}
		} else if (x->graph_type == k_GRAPH_POLAR) {
			if (!x->n_lexprr) {
				object_error((t_object *) x, "Insert exprr expression first!");
			} else {
				t_hatom vars[LEXPR_MAX_VARS]; 
				t_hatom *res;
				t_llllelem *elem;
				double this_theta, this_r;
				long i;
				for (i = 1, elem = parameters->l_head; i < x->n_lexprr->l_numvars; elem = elem ? elem->l_next : NULL, i++){
					hatom_setdouble(vars + i, elem ? hatom_getdouble(&elem->l_hatom) : 0.);
				}
				for (i = 0; i < x->num_sampling_points; i++) {
					this_theta = x->min_theta + (x->max_theta - x->min_theta) * (((double) i) / (x->num_sampling_points - 1));
					hatom_setdouble(vars, this_theta);
					res = lexpr_eval(x->n_lexprr, vars);
					this_r = hatom_getdouble(res);
					bach_freeptr(res);
					x->pts_x[x->curr_function][i] = this_r * cos(this_theta);
					x->pts_y[x->curr_function][i] = this_r * sin(this_theta);
				}
				x->num_points = x->num_sampling_points;	
			}
		}
		systhread_mutex_unlock(x->c_mutex);
		
		jbox_redraw((t_jbox *) x);
		x->j_box.l_rebuild = 0;
	}
	llll_free(parameters);
}

void graph_clear(t_graph *x){
	x->num_points = 0;
	jbox_redraw((t_jbox *) x);
}

void graph_dump(t_graph *x){
	t_llll *whole_info = get_xy_as_llll(x);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_UI, 0, whole_info);
	llll_free(whole_info);
}

t_llll *get_xy_as_llll(t_graph *x){
	long i;
	t_llll *whole_info = llll_get();
	for (i = 0; i < x->num_points; i++){
		llll_appenddouble(whole_info, x->pts_x[0][i], 0, WHITENULL_llll);
		llll_appenddouble(whole_info, x->pts_y[0][i], 0, WHITENULL_llll);
	}
	return whole_info;
}

void graph_jsave(t_graph *x, t_dictionary *d)
{
	if (x->save_data_with_patcher) {
		//post("***** JSAVE *****");
		if (x->j_box.l_dictll) {
			llll_store_in_dictionary(x->j_box.l_dictll, d, "whole_graph_data", NULL);
		} else {
			t_llll *whole_info = get_xy_as_llll(x);
			llll_store_in_dictionary(whole_info, d, "whole_graph_data", NULL);
			llll_free(whole_info);
		}
	}
}

void graph_expry(t_graph *x, t_symbol *s, long argc, t_atom *argv){
	if (x->n_lexpry) 
		lexpr_free(x->n_lexpry);
	x->n_lexpry = lexpr_new(argc, argv, 0, NULL, (t_object *) x);
	if (x->n_lexpry) {
//		object_post((t_object *) x, "good expr!");
		x->j_box.l_rebuild = 1;
	} else {
		object_error((t_object *) x, "Bad expression!");
	}
}


void graph_exprx(t_graph *x, t_symbol *s, long argc, t_atom *argv){
	if (x->n_lexprx) 
		lexpr_free(x->n_lexprx);
	x->n_lexprx = lexpr_new(argc, argv, 0, NULL, (t_object *) x);
	if (x->n_lexprx) {
//		object_post((t_object *) x, "good expr!");
		x->j_box.l_rebuild = 1;
	} else {
		object_error((t_object *) x, "Bad expression!");
	}
}

void graph_exprr(t_graph *x, t_symbol *s, long argc, t_atom *argv){
	if (x->n_lexprr) 
		lexpr_free(x->n_lexprr);
	x->n_lexprr = lexpr_new(argc, argv, 0, NULL, (t_object *) x);
	if (x->n_lexprr) {
//		object_post((t_object *) x, "good expr!");
		x->j_box.l_rebuild = 1;
	} else {
		object_error((t_object *) x, "Bad expression!");
	}
}

void graph_add(t_graph *x, t_symbol *s, long argc, t_atom *argv){
	if (argc >= 2) {
		if (x->num_points < CONST_MAX_POINTS){
			t_llll *parsed = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
			if (parsed && parsed->l_head && parsed->l_head->l_next){
				x->pts_x[0][x->num_points] = hatom_getdouble(&parsed->l_head->l_hatom);
				x->pts_y[0][x->num_points] = hatom_getdouble(&parsed->l_head->l_next->l_hatom);
				x->num_points++;
			}
			if (parsed)
				llll_free(parsed);
		}
		jbox_redraw((t_jbox *) x);
	}
}

void graph_set(t_graph *x, t_symbol *s, long argc, t_atom *argv){
	if (argc >= 3) {
		long num_pt = atom_getlong(argv) - 1; // 1-based externally, 0-based inside
		if (num_pt >= 0 && num_pt < x->num_points){
			t_llll *parsed = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc-1, argv+1, LLLL_PARSE_CLONE);
			if (parsed && parsed->l_head && parsed->l_head->l_next){
				x->pts_x[0][num_pt] = hatom_getdouble(&parsed->l_head->l_hatom);
				x->pts_y[0][num_pt] = hatom_getdouble(&parsed->l_head->l_next->l_hatom);
			}
			if (parsed) 
				llll_free(parsed);
		}
		jbox_redraw((t_jbox *) x);
	}
}


void graph_remove(t_graph *x, t_symbol *s, long argc, t_atom *argv){
	if (argc == 1) {
		delete_point(x, atom_getlong(argv) - 1); // 1-based externally, 0-based inside
		jbox_redraw((t_jbox *) x);
	}
}

void graph_click(t_graph *x, long val){
    if (val > 0 && val < x->num_points) {
        x->clicked_point = val - 1;
        click_point(x, val - 1);
        jbox_redraw((t_jbox *)x);
    }
}


void graph_setclick(t_graph *x, long val){
    x->clicked_point = val - 1;
    jbox_redraw((t_jbox *)x);
}

void graph_int(t_graph *x, t_atom_long num){
	t_atom argv[1]; atom_setlong(argv, num);
	graph_anything(x, _llllobj_sym_list, 1, argv);
}

void graph_float(t_graph *x, double num){
	t_atom argv[1]; atom_setfloat(argv, num);
	graph_anything(x, _llllobj_sym_list, 1, argv);
}

void graph_anything(t_graph *x, t_symbol *s, long argc, t_atom *argv){ //argv+1
	if (proxy_getinlet((t_object *) x) == 1) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_UI, s, argc, argv, 1);
		x->j_box.l_rebuild = 1;
	}
}

t_graph* graph_new(t_symbol *s, long argc, t_atom *argv){
	t_graph* x = NULL;
	t_max_err err = MAX_ERR_GENERIC;
	t_dictionary *d;
	t_object *textfield;
	long flags, true_ac;

	if (!(d=object_dictionaryarg(argc,argv)))
		return NULL;

	x = (t_graph*) object_alloc_debug(s_graph_class);
	flags = 0 
			| JBOX_DRAWFIRSTIN 
			| JBOX_NODRAWBOX
			| JBOX_DRAWINLAST
	//		| JBOX_TRANSPARENT	
	//		| JBOX_NOGROW
	//		| JBOX_GROWY
			| JBOX_GROWBOTH
			| JBOX_HILITE
	//		| JBOX_BACKGROUND
			| JBOX_TEXTFIELD
	//		| JBOX_DRAWBACKGROUND
	//		| JBOX_DEFAULTNAMES
	//		| JBOX_MOUSEDRAGDELTA
			;

	err = jbox_new(&x->j_box.l_box, flags, argc, argv); 
	x->j_box.l_box.b_firstin = (t_object*) x;

	true_ac = attr_args_offset(argc, argv);

	if (true_ac && argv)
		x->max_parameters = CLAMP(atom_getlong(argv), 0, LLLL_MAX_INLETS);

	x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
	
/*	for (i = 0; i < CONST_MAX_FUNCTIONS; i++) {
		x->pts_x[i] = (double *) bach_newptr(CONST_MAX_POINTS * sizeof (double));
		x->pts_y[i] = (double *) bach_newptr(CONST_MAX_POINTS * sizeof (double));
	}*/
	
    x->pts_x[0] = (double *)bach_newptr(CONST_MAX_POINTS * sizeof(double));
    x->pts_y[0] = (double *)bach_newptr(CONST_MAX_POINTS * sizeof(double));
	x->n_lexprx = NULL;
	x->n_lexpry = NULL;
	x->n_lexprr = NULL;
	x->curr_function = 0;
	x->num_points = 0;
	x->max_parameters = 0;
	x->show_focus = 1;
	x->show_xy_axis = 1;
	x->show_unit_circle = 0;
	x->grid_type = 1;
	x->mousedown_point = x->clicked_point = x->mousehover_point = -1;
	x->has_been_dragged = 0;
	
	// retrieve saved attribute values
	attr_dictionary_process(x, d);

	textfield = jbox_get_textfield((t_object *) x); 
	if (textfield) {
		textfield_set_noactivate(textfield, 1);
		textfield_set_editonclick(textfield, 0);			// set it to 0 if you don't want user to edit it in lock mode
		textfield_set_textmargins(textfield, 3, 3, 3, 3);	// margin on each side
	}
	
	llllobj_jbox_setup((t_llllobj_jbox *) x, 2, "b44");

	// mutex
	systhread_mutex_new_debug(&x->c_mutex, 0);

	jbox_ready(&x->j_box.l_box);

	if (x) {
		t_llll *llll_for_rebuild = llll_retrieve_from_dictionary(d, "whole_graph_data");
		if (llll_for_rebuild) { // new method
			t_llllelem  *elem  = llll_for_rebuild->l_head; 
			long count = 0;

			llllobj_manage_dict_llll((t_object *)x, LLLL_OBJ_UI, llll_for_rebuild);

			while (elem && elem->l_next && count < CONST_MAX_POINTS - 2){
				x->pts_x[0][count] = hatom_getdouble(&elem->l_hatom);
				x->pts_y[0][count] = hatom_getdouble(&elem->l_next->l_hatom);
				elem = elem->l_next->l_next;
				count++;
			}
			x->num_points = count;
			llll_free(llll_for_rebuild);
		} 

        llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_UI);
        return x;
	}

	object_free_debug(x);
	return NULL;
}

void graph_free(t_graph *x){
	object_free_debug(x->n_proxy);

	if (x->n_lexprx) 
		lexpr_free(x->n_lexprx);
	if (x->n_lexpry) 
		lexpr_free(x->n_lexpry);
	if (x->n_lexprr) 
		lexpr_free(x->n_lexprr);
	jbox_free(&x->j_box.l_box);
	systhread_mutex_free_debug(x->c_mutex);
	llllobj_jbox_free((t_llllobj_jbox *) x);
}

// text must be already initialized at least a 100 *sizeof(char)
void number_to_label_text(t_graph *x, double number, char *text){
//	if (fabs(number - round(number * 100)/100.) < 0.1)  
	if (fabs(number - round(number)) < CONST_EPSILON1) 
		snprintf_zero(text, 100, "%ld", (long)round(number));
	else
		snprintf_zero(text, 100, "%.2f", number);
}

void graph_paint(t_graph *x, t_object *view){

	t_jgraphics *g;
	t_rect rect;
	long i;
	double p, this_x, this_y, prev_x = 0, prev_y = 0;
	double center_x, center_y, scale_x, scale_y;
	double font_size = jbox_get_fontsize((t_object *) x);
	t_symbol *font_name = jbox_get_fontname((t_object *) x);
	t_jfont *jf_labels = jfont_create_debug(font_name->s_name, (t_jgraphics_font_slant) jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight) jbox_get_font_weight((t_object *) x), font_size);
	t_jfont *jf_axisnames = jfont_create_debug("Times", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, font_size * 1.25);
	
	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(view); 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, view, &rect);
	
	scale_x = rect.width / (x->max_x - x->min_x);
	scale_y = rect.height / (x->max_y - x->min_y);
	center_x = scale_x * (-x->min_x); // origine_x
	center_y = scale_y * x->max_y; // origine_x

	// background
    paint_background((t_object *)x, g, &rect, &x->j_bgcolor, 0);

	// grid
	if (x->grid_type == k_GRID_TICKS || x->grid_type == k_GRID_LATTICE) {
		t_jrgba color = (x->grid_type == k_GRID_LATTICE) ? x->j_gridcolor : x->j_axiscolor;
		double linewidth = (x->grid_type == k_GRID_LATTICE) ? CONST_GRID_LINE_WIDTH : CONST_TICK_LINE_WIDTH;

		if (x->graph_type == k_GRAPH_POLAR || x->graph_type == k_GRAPH_POLARPOINTS){
			double abs_x_max = MAX(fabs(x->max_x), fabs(x->min_y));
			double abs_y_max = MAX(fabs(x->max_y), fabs(x->min_y));
			double max_r = sqrt(abs_x_max * abs_x_max + abs_y_max * abs_y_max);
			if (x->grid_r_step > 0 && x->grid_type == k_GRID_LATTICE) {
				for (p = 0.; p < max_r; p += x->grid_r_step)
					paint_ellipse_stroken(g, color, center_x, center_y, p * scale_x, p * scale_y, linewidth);
			} else if (x->grid_r_step > 0 && x->grid_type == k_GRID_TICKS) {
				double x_start = (x->grid_type == k_GRID_LATTICE) ? 4 : center_x - CONST_TICK_SEMILENGTH;
				double x_end = (x->grid_type == k_GRID_LATTICE) ? rect.width - 4 : center_x + CONST_TICK_SEMILENGTH;
				double y_start = (x->grid_type == k_GRID_LATTICE) ? 4 : center_y - CONST_TICK_SEMILENGTH;
				double y_end = (x->grid_type == k_GRID_LATTICE) ? rect.height - 4 : center_y + CONST_TICK_SEMILENGTH;
				for (p = 0.; p < x->max_x && center_x + p * scale_x < rect.width - CONST_ARROW_SIZE - 4; p += x->grid_r_step)
					paint_line(g, color, center_x + p * scale_x, y_start, center_x + p * scale_x, y_end, linewidth);
				for (p = -x->grid_r_step; p > x->min_x; p -= x->grid_r_step)
					paint_line(g, color, center_x + p * scale_x, y_start, center_x + p * scale_x, y_end, linewidth);
				for (p = 0.; p < x->max_y && center_y - p * scale_y > 4 + CONST_ARROW_SIZE; p += x->grid_r_step)
					paint_line(g, color, x_start, center_y - p * scale_y, x_end, center_y - p * scale_y, linewidth);
				for (p = -x->grid_r_step; p > x->min_y ; p -= x->grid_r_step)
					paint_line(g, color, x_start, center_y - p * scale_y, x_end, center_y - p * scale_y, linewidth);
			}
			if (x->grid_theta_step > 0 && x->show_unit_circle) {
				double step_theta_rad = x->grid_theta_step; // * PI / 180.;
				double max_r_scaled = sqrt(abs_x_max * abs_x_max * scale_x * scale_x + abs_y_max * abs_y_max * scale_y * scale_y);
				if (x->grid_type == k_GRID_LATTICE) {
					for (p = 0.; p < TWOPI; p += step_theta_rad) {
						double pt_x = center_x + cos(p) * scale_x;
						double pt_y = center_y - sin(p) * scale_y;
						double tick_x = max_r_scaled * cos(p);
						double tick_y = max_r_scaled * sin(p);
						paint_line(g, color,center_x, center_y, pt_x + tick_x, pt_y - tick_y, linewidth);
					}
				} else {
					for (p = 0.; p < TWOPI; p += step_theta_rad) {
						double pt_x = center_x + cos(p) * scale_x;
						double pt_y = center_y - sin(p) * scale_y;
						double tick_x = CONST_TICK_SEMILENGTH * cos(p);
						double tick_y = CONST_TICK_SEMILENGTH * sin(p);
						paint_line(g, color, pt_x - tick_x, pt_y + tick_y, pt_x + tick_x, pt_y - tick_y, linewidth);
					}
				}
			}
		} else {
			if (x->grid_x_step > 0 && x->show_xy_axis) {
				double y_start = (x->grid_type == k_GRID_LATTICE) ? 4 : center_y - CONST_TICK_SEMILENGTH;
				double y_end = (x->grid_type == k_GRID_LATTICE) ? rect.height - 4 : center_y + CONST_TICK_SEMILENGTH;
				for (p = 0.; p < x->max_x && (x->grid_type == k_GRID_LATTICE || center_x + p * scale_x < rect.width - CONST_ARROW_SIZE - 4); p += x->grid_x_step)
					paint_line(g, color, center_x + p * scale_x, y_start, center_x + p * scale_x, y_end, linewidth);
				for (p = -x->grid_x_step; p > x->min_x; p -= x->grid_x_step)
					paint_line(g, color, center_x + p * scale_x, y_start, center_x + p * scale_x, y_end, linewidth);
			}
			if (x->grid_y_step > 0 && x->show_xy_axis) {
				double x_start = (x->grid_type == k_GRID_LATTICE) ? 4 : center_x - CONST_TICK_SEMILENGTH;
				double x_end = (x->grid_type == k_GRID_LATTICE) ? rect.width - 4 : center_x + CONST_TICK_SEMILENGTH;
				for (p = 0.; p < x->max_y && (x->grid_type == k_GRID_LATTICE || center_y - p * scale_y > 4 + CONST_ARROW_SIZE); p += x->grid_y_step)
					paint_line(g, color, x_start, center_y - p * scale_y, x_end, center_y - p * scale_y, linewidth);
				for (p = -x->grid_y_step; p > x->min_y; p -= x->grid_y_step)
					paint_line(g, color, x_start, center_y - p * scale_y, x_end, center_y - p * scale_y, linewidth);
			}
		}
	}

	// xy axis?
	if (x->show_xy_axis) {
		if (center_x > 0) {
			paint_line(g, x->j_axiscolor, center_x, 4, center_x, rect.height - 4, 1.5);
			// arrow
			jgraphics_set_source_jrgba(g, &x->j_axiscolor); jgraphics_set_line_width(g, 0.);
			jgraphics_move_to(g, center_x, 4);
			jgraphics_line_to(g, center_x - CONST_ARROW_SIZE/2., 4 + CONST_ARROW_SIZE);
			jgraphics_line_to(g, center_x + CONST_ARROW_SIZE/2., 4 + CONST_ARROW_SIZE);
			jgraphics_close_path(g); 
			jgraphics_fill(g);	
		}
		
		if (center_y > 0) {
			paint_line(g, x->j_axiscolor, 4, center_y, rect.width - 4, center_y, 1.5);
			// arrow
			jgraphics_set_source_jrgba(g, &x->j_axiscolor); jgraphics_set_line_width(g, 0.);
			jgraphics_move_to(g, rect.width - 4, center_y);
			jgraphics_line_to(g, rect.width - 4 - CONST_ARROW_SIZE, center_y - CONST_ARROW_SIZE/2.);
			jgraphics_line_to(g, rect.width - 4 - CONST_ARROW_SIZE, center_y + CONST_ARROW_SIZE/2.);
			jgraphics_close_path(g); 
			jgraphics_fill(g);	
		}
	}

	// unit circle?
	if (x->show_unit_circle)
		paint_ellipse_stroken(g, x->j_axiscolor, center_x, center_y, scale_x, scale_y, 1.5);

	// lines and points
	for (i = 0; i < x->num_points; i++) {
		this_x = center_x + x->pts_x[0][i]*scale_x;
		this_y = center_y - x->pts_y[0][i]*scale_y;

		if (x->show_mode == k_MODE_POINTS || x->show_mode == k_MODE_LINESANDPOINTS)
			paint_circle_filled(g, x->j_graphcolor, this_x, this_y, x->point_radius);
		
		if (i > 0 && (x->show_mode == k_MODE_LINES || x->show_mode == k_MODE_LINESANDPOINTS))
			paint_line(g, x->j_graphcolor, prev_x, prev_y, this_x, this_y, x->linewidth);
		
		if (x->show_mode == k_MODE_VECTORS) 
			paint_arrow(g, x->j_graphcolor, center_x, center_y, this_x, this_y, x->linewidth, CONST_VECTORS_ARROW_SIZE, CONST_VECTORS_ARROW_SIZE);
		

        if (x->show_mousedown && x->clicked_point == i){ // mouse hover?
            paint_circle_stroken(g, x->j_mousedowncolor, this_x, this_y, x->point_radius * 2.5, 1.);
            paint_circle_stroken(g, x->j_mousedowncolor, this_x, this_y, x->point_radius * 3, 1.);
        }

        if (x->mouse_hover && x->mousehover_point == i){ // mouse hover?
            paint_circle_stroken(g, x->j_graphcolor, this_x, this_y, x->point_radius * 2.5, 1.);
            paint_circle_stroken(g, x->j_graphcolor, this_x, this_y, x->point_radius * 3, 1.);
        }

		prev_x = this_x;
		prev_y = this_y;
	}

	// labels?
	if (x->show_xy_axis && x->show_labels){
		char text[100]; double em_width, em_height, width, height;
		jfont_text_measure(jf_labels, "M", &em_width, &em_height);
		if (x->labels_x_step > 0) {
			double offset_y = (x->grid_type == k_GRID_TICKS) ? - CONST_TICK_SEMILENGTH - 2 : - 2;
			double y_pos_for_writing = center_y - offset_y;
			if (y_pos_for_writing + em_height > rect.height)
				y_pos_for_writing = center_y + offset_y - em_height;
			for (p = x->labels_x_step; p < x->max_x && center_x + p * scale_x < rect.width - CONST_ARROW_SIZE - 4; p += x->labels_x_step) {
				number_to_label_text(x, p, text);
				jfont_text_measure(jf_labels, text, &width, &height);
				write_text_standard_singleline(g, jf_labels, x->j_textcolor, text, center_x + p * scale_x - width/2., y_pos_for_writing, width+20, height+20);
			}
			for (p = -x->labels_x_step; p > x->min_x; p -= x->labels_x_step) {
				number_to_label_text(x, p, text);
				jfont_text_measure(jf_labels, text, &width, &height);
				write_text_standard_singleline(g, jf_labels, x->j_textcolor, text, center_x + p * scale_x - width/2., y_pos_for_writing, width+20, height+20);
			}
			if (x->show_xy_labels) {
				jfont_text_measure(jf_axisnames, "x", &width, &height);
				write_text_standard_singleline(g, jf_axisnames, x->j_textcolor, "x", rect.width - width - 12, y_pos_for_writing, width+20, height+20);
			}
		}
		if (x->labels_y_step > 0) {
			double offset_x = (x->grid_type == k_GRID_TICKS) ? - CONST_TICK_SEMILENGTH - 4: - 4;
			char writing_direction = (center_x + offset_x - em_width -6 < 0 ? -1 : 1); 
			for (p = x->labels_y_step; p < x->max_y; p += x->labels_y_step) {
				number_to_label_text(x, p, text);
				jfont_text_measure(jf_labels, text, &width, &height);
				write_text_standard_singleline(g, jf_labels, x->j_textcolor, text, writing_direction < 0  ? center_x - offset_x : center_x + offset_x - width, center_y - p * scale_y - height/2., width+20, height+20);
			}
			for (p = -x->labels_x_step; p > x->min_x && center_x + p * scale_x > CONST_ARROW_SIZE + 4; p -= x->labels_y_step) {
				number_to_label_text(x, p, text);
				jfont_text_measure(jf_labels, text, &width, &height);
				write_text_standard_singleline(g, jf_labels, x->j_textcolor, text, writing_direction < 0 ? center_x - offset_x : center_x + offset_x - width, center_y - p * scale_y - height/2., width+20, height+20);
			}
			if (x->show_xy_labels) {
				jfont_text_measure(jf_axisnames, "y", &width, &height);
				write_text_standard_singleline(g, jf_axisnames, x->j_textcolor, "y", writing_direction < 0 ? center_x - offset_x + 6 : center_x + offset_x - width - 6, 4, width+20, height+20);
			}
		}
	}
	
    // border
    paint_border((t_object *)x, g, &rect, &x->j_bordercolor, (x->show_focus && x->j_has_focus) ? 2.5 : 1., 0);

    
	jfont_destroy_debug(jf_labels);
	jfont_destroy_debug(jf_axisnames);
}


void graph_focusgained(t_graph *x, t_object *patcherview) {
//	object_post((t_object *)x, "focusgained"); 
	x->j_has_focus = true;
	jbox_redraw((t_jbox *)x);
}

void graph_focuslost(t_graph *x, t_object *patcherview) {
//	object_post((t_object *)x, "focuslost"); 
	x->j_has_focus = false;
	jbox_redraw((t_jbox *)x);
}

void graph_mousemove(t_graph *x, t_object *patcherview, t_pt pt, long modifiers) {
	llll_format_modifiers(&modifiers, NULL);
	x->has_been_dragged = 0;
	if (x->graph_type == k_GRAPH_CARTESIANPOINTS || x->graph_type == k_GRAPH_POLARPOINTS) {
		if (modifiers == 0 && x->mouse_hover) {
			long this_hover = pixel_to_point_number(x, patcherview, pt);
			if (this_hover != x->mousehover_point) {
				x->mousehover_point = this_hover;
				jbox_redraw((t_jbox *)x);
			}
		} 
	}

}

long pixel_to_point_number(t_graph *x, t_object *patcherview, t_pt pt){
	long i;
	t_jgraphics *g;
	t_rect rect;
	double scale_x, scale_y, center_x, center_y;
	
	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(patcherview); 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);
	
	scale_x = rect.width / (x->max_x - x->min_x);
	scale_y = rect.height / (x->max_y - x->min_y);
	center_x = scale_x * (-x->min_x); // origine_x
	center_y = scale_y * x->max_y; // origine_x

	for (i = 0; i < x->num_points; i++){
		double this_x = center_x + x->pts_x[0][i]*scale_x;
		double this_y = center_y - x->pts_y[0][i]*scale_y;
		
		if (fabs(pt.x - this_x) < x->point_radius + 3 && fabs(pt.y - this_y) < x->point_radius + 3)
			return i;
	}
	return -1;
}

void click_point(t_graph *x, long idx)
{
    if (idx >= 0 && idx < x->num_points) {
        t_llll *ll = llll_get();
        llll_appendsym(ll, gensym("clicked"), 0, WHITENULL_llll);
        llll_appendlong(ll, idx + 1, 0, WHITENULL_llll);
        llll_appendllll(ll, double_couple_to_llll(x->pts_x[0][idx], x->pts_y[0][idx]), 0, WHITENULL_llll);
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 1, ll);
        llll_free(ll);
    }
    jbox_redraw((t_jbox *) x);
}

void graph_mousedown(t_graph *x, t_object *patcherview, t_pt pt, long modifiers){
	llll_format_modifiers(&modifiers, NULL);
	x->has_been_dragged = 0;
    x->clicked_point = -1;
    
	if (x->graph_type == k_GRAPH_CARTESIANPOINTS || x->graph_type == k_GRAPH_POLARPOINTS) {
		if (modifiers == 0) {
			x->clicked_point = x->mousedown_point = pixel_to_point_number(x, patcherview, pt);
            click_point(x, x->mousedown_point);
		} else if (modifiers == eAltKey && x->allow_modifications) {
			double new_pt_x, new_pt_y;
			pixel_to_xy(x, patcherview, pt.x, pt.y, &new_pt_x, &new_pt_y);
			if (x->num_points < CONST_MAX_POINTS){
				x->pts_x[0][x->num_points] = new_pt_x;
				x->pts_y[0][x->num_points] = new_pt_y;
				x->num_points++;
			}
			llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 2);
			jbox_redraw((t_jbox *) x);
		} else if (modifiers == eCommandKey && x->allow_modifications) {
			long mousedown_pt = pixel_to_point_number(x, patcherview, pt);
			if (mousedown_pt >= 0) {
				delete_point(x, mousedown_pt);
				llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 2);
				jbox_redraw((t_jbox *) x);
			}
		}
	}
}

void graph_mouseup(t_graph *x, t_object *patcherview, t_pt pt, long modifiers){
	x->mousedown_point = -1;
	if (x->has_been_dragged)
		llllobj_outlet_bang((t_object *) x, LLLL_OBJ_UI, 2);
    jbox_redraw((t_jbox *) x);
}

void move_point(t_graph *x, long point_number, double new_x, double new_y, char values_as_delta){
	if (point_number >= 0 && point_number < x->num_points && point_number < CONST_MAX_POINTS) {
		if (values_as_delta) {
			x->pts_x[0][point_number] += new_x;
			x->pts_y[0][point_number] += new_y;
		} else {
			x->pts_x[0][point_number] = new_x;
			x->pts_y[0][point_number] = new_y;
		}
	}
}

void delete_point(t_graph *x, long point_number){
	if (point_number >= 0 && point_number < x->num_points && point_number < CONST_MAX_POINTS) {
		long j;
		for (j = point_number + 1; j < x->num_points; j++){
			x->pts_x[0][j-1] = x->pts_x[0][j]; 
			x->pts_y[0][j-1] = x->pts_y[0][j]; 
		}
		x->num_points--;
	}
}

void pixel_to_xy(t_graph *x, t_object *patcherview, double pixel_x, double pixel_y, double *coord_x, double *coord_y) {
	t_jgraphics *g;
	t_rect rect;
	double scale_x, scale_y, center_x, center_y;
	
	// getting rectangle dimensions
	g = (t_jgraphics*) patcherview_get_jgraphics(patcherview); 
	jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect);
	
	scale_x = rect.width / (x->max_x - x->min_x);
	scale_y = rect.height / (x->max_y - x->min_y);
	center_x = scale_x * (-x->min_x);
	center_y = scale_y * x->max_y;
	*coord_x = (pixel_x - center_x)/scale_x;
	*coord_y = (center_y - pixel_y)/scale_y;
}

void graph_mousedrag(t_graph *x, t_object *patcherview, t_pt pt, long modifiers){
	if (x->mousedown_point >= 0 && x->allow_modifications) {
		double this_pt_x, this_pt_y;
		pixel_to_xy(x, patcherview, pt.x, pt.y, &this_pt_x, &this_pt_y);
		move_point(x, x->mousedown_point, this_pt_x, this_pt_y, false);
		x->has_been_dragged = true;
		jbox_redraw((t_jbox *) x);
	}
}

long graph_key(t_graph *x, t_object *patcherview, long keycode, long modifiers, long textcharacter){
/*	llll_format_modifiers(&modifiers, &keycode); */
	return 0;
}
