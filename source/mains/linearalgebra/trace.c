/*
 *  trace.c
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
	trace.c
	
	@name 
	bach.trace
	
	@realname 
	bach.trace

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the trace of a matrix
	
	@description
	Computes the trace of a matrix, i.e. the sum of the elements on the diagonal.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	matrix, trace, sum, diagonal, calculate, compute, element
	
	@seealso
	bach.det, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/


#include "math/llll_linearalgebra.h" 
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 

typedef struct _trace
{
	struct llllobj_object 	n_ob;
	long				shift; // shift with respect to the main traceonal
} t_trace;


void trace_assist(t_trace *x, void *b, long m, long a, char *s);
void trace_inletinfo(t_trace *x, void *b, long a, char *t);

t_trace *trace_new(t_symbol *s, short ac, t_atom *av);
void trace_free(t_trace *x);

void trace_bang(t_trace *x);
void trace_int(t_trace *x, t_atom_long num);
void trace_float(t_trace *x, double num);
void trace_anything(t_trace *x, t_symbol *msg, long ac, t_atom *av);

t_class *trace_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.trace", (method)trace_new, (method)trace_free, (short)sizeof(t_trace), 0L, A_GIMME, 0);
	
	// @method llll @digest Output trace of incoming matrix
	// @description The object outputs the trace of the incoming matrix. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)trace_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)trace_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)trace_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)trace_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Output trace
	// @description Output the trace of the most recently received input data.
	class_addmethod(c, (method)trace_bang,						"bang",		0);
	
	class_addmethod(c, (method)trace_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)trace_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_LONG(c, "shift", 0, t_trace, shift); 
	CLASS_ATTR_STYLE_LABEL(c,"shift",0,"text","Shift");
	CLASS_ATTR_BASIC(c,"shift",0);
	// @description Use the shift parameter to compute the sum of the elements of a secondary diagonal.
	// Positive integers are upper secondary diagonals, negative integers are lower secondary diagonals.

	class_register(CLASS_BOX, c);
	trace_class = c;
	
	dev_post("bach.trace compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void trace_bang(t_trace *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void trace_int(t_trace *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	trace_anything(x, _llllobj_sym_list, 1, argv);
}

void trace_float(t_trace *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	trace_anything(x, _llllobj_sym_list, 1, argv);
}

void trace_anything(t_trace *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	t_llll *tracematrix = NULL;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	if (inlist) {
		t_hatom res = llll_trace(inlist, x->shift);
		tracematrix = llll_get();
		llll_appendhatom_clone(tracematrix, &res, 0, WHITENULL_llll);
	}
	
	if (tracematrix)
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, tracematrix, 0);
	
	llll_free(inlist);
	x->n_ob.l_rebuild = 0;
	trace_bang(x);
}


void trace_assist(t_trace *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The matrix
		sprintf(s, "llll: Matrix");
	} else {
		char *type = NULL; // @out 0 @type llll @digest The trace of the incoming matrix
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Trace", type);
	}
}

void trace_inletinfo(t_trace *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void trace_free(t_trace *x)
{	llllobj_obj_free((t_llllobj_object *) x);
}

t_trace *trace_new(t_symbol *s, short ac, t_atom *av)
{
	t_trace *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_trace *) object_alloc_debug(trace_class))) {
	
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

