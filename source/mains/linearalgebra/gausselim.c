/*
 *  gausselim.c
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
	gausselim.c
	
	@name 
	bach.gausselim
	
	@realname 
	bach.gausselim

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Perform matrix gaussian elimination
	
	@description
	Applies the Gaussian elimination algorithm to reduce the incoming matrix to a row echelon form.
	It also outputs some additional information, such as determinant and rank.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	The algorithm has attributes to admit column swap, and to perform (in addition) also the reversed Gauss elimination.
	To know more: http://mathworld.wolfram.com/GaussianElimination.html <br />
	Rank and determinant are immediate to compute once the matrix is in echelon form, so no big further additional
	computation is required. Indeed, the bach.rank and bach.det abstractions are little wrappers of bach.gausselim.
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	reduce, matrix, Gauss elimination, echelon form, determinant, rank, swap, row, column 
	
	@seealso
	bach.linearsolve, bach.extractbasis, bach.det, bach.rank, bach.im, bach.ker, bach.inv, Into The Matrix
	
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

typedef struct _gausselim
{
	struct llllobj_object 	n_ob;
	
	char		mode;
	char		admit_cols_swaps;
	
	long		num_swaps;
	long		rank;
	t_hatom		det;

} t_gausselim;


void gausselim_assist(t_gausselim *x, void *b, long m, long a, char *s);
void gausselim_inletinfo(t_gausselim *x, void *b, long a, char *t);

t_gausselim *gausselim_new(t_symbol *s, short ac, t_atom *av);
void gausselim_free(t_gausselim *x);

void gausselim_bang(t_gausselim *x);
void gausselim_int(t_gausselim *x, t_atom_long num);
void gausselim_float(t_gausselim *x, double num);
void gausselim_anything(t_gausselim *x, t_symbol *msg, long ac, t_atom *av);

t_class *gausselim_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}

    CLASS_NEW_CHECK_SIZE(c, "bach.gausselim", (method)gausselim_new, (method)gausselim_free, (long) sizeof(t_gausselim), 0L, A_GIMME, 0);
	
	// @method llll @digest Perform Gaussian elimination on incoming matrix
	// @description The Gaussian elimination is performed on the incoming matrix and the matrix in echelon form is output. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)gausselim_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)gausselim_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)gausselim_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)gausselim_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the Gaussian elimination
	// @description Perform the Gaussina elimination on the most recently received input matrix.
	class_addmethod(c, (method)gausselim_bang,						"bang",								0);
	
	class_addmethod(c, (method)gausselim_assist,					"assist",				A_CANT,		0);
	class_addmethod(c, (method)gausselim_inletinfo,					"inletinfo",			A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_CHAR(c, "mode", 0, t_gausselim, mode); 
	CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
	CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Simple Double"); 
	CLASS_ATTR_BASIC(c,"mode",0);
	// @description If the mode is "Simple", the standard Gauss elimination is performed <br />
	// If the mode is "Double", also the backward Gauss elimination is performed, bringing
	// the left part of the output matrix in a pseudo-identity form.

	CLASS_ATTR_CHAR(c, "admitcolswap", 0, t_gausselim, admit_cols_swaps); 
	CLASS_ATTR_STYLE_LABEL(c,"admitcolswap",0,"onoff","Admit Column Swap");
	CLASS_ATTR_BASIC(c,"admitcolswap",0);
	// @description If this flag is set, the algorithm will be allowed to swap
	// columns of the incoming matrix. 

	
	class_register(CLASS_BOX, c);
	gausselim_class = c;
	
	dev_post("bach.gausselim compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void gausselim_bang(t_gausselim *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 4);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 3);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 2, x->rank);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 1, x->num_swaps);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void gausselim_int(t_gausselim *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	gausselim_anything(x, _llllobj_sym_list, 1, argv);
}

void gausselim_float(t_gausselim *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	gausselim_anything(x, _llllobj_sym_list, 1, argv);
}

void gausselim_anything(t_gausselim *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	t_llll *gaussel_llll = NULL;
	t_llll *col_order;
	
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
		gaussel_llll = llll_gauss_reduce_matrix(inlist, &x->num_swaps, &x->rank, &x->det, x->mode, 0, NULL, NULL, x->admit_cols_swaps, &col_order);
	
	if (gaussel_llll) {
		t_llll *det_llll = llll_get();
		llll_appendhatom_clone(det_llll, &x->det, 0, WHITENULL_llll);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, gaussel_llll, 0);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, det_llll, 3);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, col_order, 4);
	} else {
		t_llll *det_llll = llll_get();
		llll_appendlong(det_llll, 0, 0, WHITENULL_llll);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, det_llll, 3);
	}
	
	llll_free(inlist);
	x->n_ob.l_rebuild = 0;
	gausselim_bang(x);
}


void gausselim_assist(t_gausselim *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest Original matrix
		sprintf(s, "llll: Matrix");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0)	// @out 0 @type llll @digest Matrix after Gaussian elimination
			sprintf(s, "llll (%s): Matrix After Gaussian Elimination", type);
		else if (a == 1) // @out 1 @type int @digest The number of line swaps that have been performed
			sprintf(s, "int: Number of line swaps");
		else if (a == 2) // @out 2 @type int @digest The rank of the original matrix
			sprintf(s, "int: Rank");
		else if (a == 3) // @out 3 @type llll @digest the determinant of the original matrix
			sprintf(s, "llll (%s): Determinant", type);
		else	// @out 4 @type llll @digest The columns permutation
			sprintf(s, "llll (%s): New Order of Columns", type);	// @description A list is output with the number from
																	// 1 to the number of columns reordered exactly in the 
																	// way the algorithm has reordered the columns.
	}
}

void gausselim_inletinfo(t_gausselim *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void gausselim_free(t_gausselim *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_gausselim *gausselim_new(t_symbol *s, short ac, t_atom *av)
{
	t_gausselim *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_gausselim *) object_alloc_debug(gausselim_class))) {
	
		x->mode = x->admit_cols_swaps = 0;
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "44ii4");

		x->num_swaps = 0;
		x->rank = -1;
		hatom_setlong(&x->det, 0);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

