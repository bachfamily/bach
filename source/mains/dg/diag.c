/*
 *  diag.c
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
	diag.c
	
	@name 
	bach.diag
	
	@realname 
	bach.diag

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Build a diagonal matrix
	
	@description
	Builds a diagonal matrix having the incoming llll as diagonal.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	A <m>shift</m> attribute can be used to put the llll on a secondary diagonal.
	
	@category
	bach, bach objects, bach matrix calculus

 	@keywords
	matrix, diagonal, shift, secondary, main, build

	@seealso
	bach.minfo, bach.submatrix, bach.idmatrix, bach.mrandom, bach.wellshape, bach.m2jitcellblock, Into The Matrix
	
	@owner
	Daniele Ghisi
*/


#include "llll_linearalgebra.h" 
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 

typedef struct _diag
{
	struct llllobj_object 	n_ob;
	long				shift; // shift with respect to the main diagonal
} t_diag;


void diag_assist(t_diag *x, void *b, long m, long a, char *s);
void diag_inletinfo(t_diag *x, void *b, long a, char *t);

t_diag *diag_new(t_symbol *s, short ac, t_atom *av);
void diag_free(t_diag *x);

void diag_bang(t_diag *x);
void diag_int(t_diag *x, t_atom_long num);
void diag_float(t_diag *x, double num);
void diag_anything(t_diag *x, t_symbol *msg, long ac, t_atom *av);

t_class *diag_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}

	c = class_new("bach.diag", (method)diag_new, (method)diag_free, (short)sizeof(t_diag), 0L, A_GIMME, 0);
	
	// @method llll @digest Build matrix having incoming llll as diagonal.
	// @description The object outputs a matrix having the incoming llll as diagonal, and zeros everywhere else. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)diag_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)diag_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)diag_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)diag_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Build the diagonal matrix.
	// @description Perform the build on the most recently received input data.
	class_addmethod(c, (method)diag_bang,						"bang",		0);
	
	class_addmethod(c, (method)diag_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)diag_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_LONG(c, "shift", 0, t_diag, shift); 
	CLASS_ATTR_STYLE_LABEL(c,"shift",0,"text","Shift");
	CLASS_ATTR_BASIC(c,"shift",0);
	// @description Use the shift parameter to put the incoming data on a secondary diagonal.
	// Positive integers are upper secondary diagonals, negative integers are lower secondary diagonals.

	class_register(CLASS_BOX, c);
	diag_class = c;
	
	dev_post("bach.diag compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void diag_bang(t_diag *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void diag_int(t_diag *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	diag_anything(x, _llllobj_sym_list, 1, argv);
}

void diag_float(t_diag *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	diag_anything(x, _llllobj_sym_list, 1, argv);
}

void diag_anything(t_diag *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	t_llll *diagmatrix = NULL;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	if (inlist)
		diagmatrix = llll_get_diagonal_matrix(inlist, x->shift);
	
	if (diagmatrix)
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, diagmatrix, 0);
	
	llll_free(inlist);
	x->n_ob.l_rebuild = 0;
	diag_bang(x);
}


void diag_assist(t_diag *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll to be put on the diagonal
		sprintf(s, "llll: to Be Put on the Diagonal");
	} else { 
		char *type = NULL; // @out 0 @type llll @digest The matrix having the input llll as diagonal
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Diagonal matrix", type);
	}
}

void diag_inletinfo(t_diag *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void diag_free(t_diag *x)
{	llllobj_obj_free((t_llllobj_object *) x);
}

t_diag *diag_new(t_symbol *s, short ac, t_atom *av)
{
	t_diag *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_diag *) object_alloc_debug(diag_class))) {
	
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

