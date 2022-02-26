/*
 *  mtimes.c
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
	mtimes.c
	
	@name 
	bach.mtimes
	
	@realname 
	bach.mtimes

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Perform matrix multiplication
	
	@description
	Performs multiplications involving matrices, vectors and scalars.
	
	@discussion
	The output depends on the type of the inputs (matrix, vector or scalar).
	Inputs must be coherent (so if left input is a matrix, right input cannot be 
	a row vector. In general if left input is a NxM matrix, and right input is
	RxS matrix, M must be equal to R. <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	matrix, multiplication, calculate, compute, vector, scalar

	@seealso
	bach.cross, bach.expr, times, expr, bach.mpow, bach.m2jitcellblock, Into The Matrix
	
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

typedef struct _mtimes
{
	struct llllobj_object 	n_ob;
	
	long				n_mode;
	long				n_proxies;
	
	void				*n_proxy[2];
	long				n_in;
	
} t_mtimes;


void mtimes_assist(t_mtimes *x, void *b, long m, long a, char *s);
void mtimes_inletinfo(t_mtimes *x, void *b, long a, char *t);

t_mtimes *mtimes_new(t_symbol *s, short ac, t_atom *av);
void mtimes_free(t_mtimes *x);

void mtimes_bang(t_mtimes *x);
void mtimes_int(t_mtimes *x, t_atom_long num);
void mtimes_float(t_mtimes *x, double num);
void mtimes_anything(t_mtimes *x, t_symbol *msg, long ac, t_atom *av);

t_class *mtimes_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}

    CLASS_NEW_CHECK_SIZE(c, "bach.mtimes", (method)mtimes_new, (method)mtimes_free, (long) sizeof(t_mtimes), 0L, A_GIMME, 0);
	
	// @method llll @digest Store matrix as factor, output the result
	// @description The object take the incoming matrix (or vector, or scalar) and sets it either as left or as
	// right factor (depending on the inlet). If the inlet is the left one, it also outputs the result of the
	// matrix multiplication. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)mtimes_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)mtimes_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)mtimes_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)mtimes_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the last matrix multiplication
	// @description Perform the matrix multiplication on the most recently received input data.
	class_addmethod(c, (method)mtimes_bang,						"bang",		0);
	
	class_addmethod(c, (method)mtimes_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)mtimes_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);


	class_register(CLASS_BOX, c);
	mtimes_class = c;
	
	dev_post("bach.mtimes compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void mtimes_bang(t_mtimes *x)
{
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		mtimes_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void mtimes_int(t_mtimes *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	mtimes_anything(x, _llllobj_sym_list, 1, argv);
}

void mtimes_float(t_mtimes *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	mtimes_anything(x, _llllobj_sym_list, 1, argv);
}

void mtimes_anything(t_mtimes *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	long i;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), inlet);
		return;
	}
	
	if (msg == _llllobj_sym_clearall) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 1);
		return;
	}


	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		x->n_ob.l_rebuild = 1;
	}

	if (inlet == 0) {
		// do calculations
		t_llll *inlist[2];
		t_llll *result;
		
		for (i = 0; i < 2; i++) 
			inlist[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 1);
		
		result = llll_matrix_matrix_product(inlist[0], inlist[1]);
		if (result)
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, result, 0);
			
		for (i = 0; i < 2; i++)
			llll_free(inlist[i]);
		
		x->n_ob.l_rebuild = 0;
		mtimes_bang(x);
	}
}


void mtimes_assist(t_mtimes *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) // @in 0 @type llll @digest Left factor (matrix, vector or scalar)
			sprintf(s, "llll: Matrix or vector (left)");
		else  // @in 1 @type llll @digest Right factor (matrix, vector or scalar)
			sprintf(s, "llll: Matrix or vector (right)");
	} else { 
		char *type = NULL; // @out 0 @type llll @digest The result of the matrix multiplication
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Result", type);
	}
}

void mtimes_inletinfo(t_mtimes *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void mtimes_free(t_mtimes *x)
{
	long i;
	for (i = 1; i < 2; i++)
		object_free_debug(x->n_proxy[i]);

	llllobj_obj_free((t_llllobj_object *) x);
}

t_mtimes *mtimes_new(t_symbol *s, short ac, t_atom *av)
{
	t_mtimes *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_mtimes *) object_alloc_debug(mtimes_class))) {
	
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);

		attr_args_process(x, ac, av);

		llllobj_obj_setup((t_llllobj_object *) x, 2, "4");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

