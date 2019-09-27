/*
 *  linearsolve.c
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
	linearsolve.c
	
	@name 
	bach.linearsolve
	
	@realname 
	bach.linearsolve

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Solve a linear system of equations
	
	@description
	Solves a linear system of equations in the matrix form Ax = b, where A 
	is the system matrix and b is the column vector. If the system is solvable and the solution 
	is unique, the vector x is sent through the first outlet. In any case, an information 
	about the solvability is sent through the second outlet. 

	@discussion
	The linear system has to be in matrix form Ax = b. <o>bach.linearsolve</o> solves such system by performing
	a double Gaussian elimination on the juxtaposed matrix [A|b], as <o>bach.gausselim</o> can do.
	If there is no solution, this is reported from right outlet; if there are infinite solutions
	this is also reported from right outlet (and no solution is output). <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	solve, linear system, equation, matrix, column, vector

	@seealso
	bach.gausselim, bach.mtimes, bach.eig, bach.det, bach.rank, Into The Matrix
	
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

typedef struct _linearsolve
{
	struct	llllobj_object 	n_ob;
	
	char	mode;
	
	char	sol_type;

	void	*n_proxy[2];
	long	n_in;

} t_linearsolve;


void linearsolve_assist(t_linearsolve *x, void *b, long m, long a, char *s);
void linearsolve_inletinfo(t_linearsolve *x, void *b, long a, char *t);

t_linearsolve *linearsolve_new(t_symbol *s, short ac, t_atom *av);
void linearsolve_free(t_linearsolve *x);

void linearsolve_bang(t_linearsolve *x);
void linearsolve_int(t_linearsolve *x, t_atom_long num);
void linearsolve_float(t_linearsolve *x, double num);
void linearsolve_anything(t_linearsolve *x, t_symbol *msg, long ac, t_atom *av);

t_class *linearsolve_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.linearsolve", (method)linearsolve_new, (method)linearsolve_free, (short)sizeof(t_linearsolve), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description In the first inlet, an llll sets the system matrix A and have bach.linearsolve solve the linear system. <br />
	// In the second inlet, an llll sets the system vector b. <br />
	// The llll in the second inlet is expected to be a vector (a plain llll); the llll in the first inlet is expected to be a matrix. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)linearsolve_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)linearsolve_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)linearsolve_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)linearsolve_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Solve the linear system
	// @description Solve the linear system based on the most recently received input matrix and vector.
	class_addmethod(c, (method)linearsolve_bang,						"bang",								0);
	
	class_addmethod(c, (method)linearsolve_assist,					"assist",				A_CANT,		0);
	class_addmethod(c, (method)linearsolve_inletinfo,					"inletinfo",			A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


	class_register(CLASS_BOX, c);
	linearsolve_class = c;
	
	dev_post("bach.linearsolve compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void linearsolve_bang(t_linearsolve *x)
{
	if (x->sol_type == k_LINEAR_SYSTEM_ONE_SOLUTION) 
		llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
	else if (x->sol_type == k_LINEAR_SYSTEM_NO_SOLUTION) 
		llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
	else if (x->sol_type == k_LINEAR_SYSTEM_INFINITELY_MANY_SOLUTIONS) 
		llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 1, _llllobj_sym_inf, 0, NULL);
	else
		llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 1, _llllobj_sym_error, 0, NULL);

	if (x->sol_type == k_LINEAR_SYSTEM_ONE_SOLUTION)
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void linearsolve_int(t_linearsolve *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	linearsolve_anything(x, _llllobj_sym_list, 1, argv);
}

void linearsolve_float(t_linearsolve *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	linearsolve_anything(x, _llllobj_sym_list, 1, argv);
}

void linearsolve_anything(t_linearsolve *x, t_symbol *msg, long ac, t_atom *av)
{
	long i;
	long inlet = proxy_getinlet((t_object *) x);
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), inlet);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		x->n_ob.l_rebuild = 1;
	}

	// do calculations
	if (inlet == 0) {
		t_llll *inlist[2];
		t_llll *solution = NULL;
		
		for (i = 0; i < 2; i++) 
			inlist[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 1);
		
		if (inlist[0] && inlist[1])
			solution = llll_solve_linear_system(inlist[0], inlist[1], &x->sol_type);
		
		if (solution)
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, solution, 0);
		
		for (i = 0; i < 2; i++)
			llll_free(inlist[i]);

		x->n_ob.l_rebuild = 0;
		linearsolve_bang(x);
	}
}


void linearsolve_assist(t_linearsolve *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) // @in 0 @type llll @digest The matrix of the system
			sprintf(s, "llll: System Matrix");
		else // @in 1 @type llll @digest The column vector
			sprintf(s, "llll: Column Vector");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) // @out 0 @type llll @digest The solution of the system 
			sprintf(s, "llll (%s): Solution Vector", type); // @discussion The solution is only output if it exists and it is unique.
		else // @out 1 @type int/symbol @digest Number of solutions of the system
			sprintf(s, "Number of Solutions (int) or inf"); // @discussion This could be 0, 1, "inf", or "error" if the incoming data is incorrect.
	}
}

void linearsolve_inletinfo(t_linearsolve *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void linearsolve_free(t_linearsolve *x)
{	
	long i;
	for (i = 1; i < 2; i++)
		object_free_debug(x->n_proxy[i]);

	llllobj_obj_free((t_llllobj_object *) x);
}

t_linearsolve *linearsolve_new(t_symbol *s, short ac, t_atom *av)
{
	t_linearsolve *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_linearsolve *) object_alloc_debug(linearsolve_class))) {
	
		x->sol_type = k_LINEAR_SYSTEM_WRONG;
		
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);

		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "a4", NULL);

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

