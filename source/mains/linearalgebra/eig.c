/*
 *  eig.c
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
	eig.c
	
	@name 
	bach.eig
	
	@realname 
	bach.eig

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find eigenvalues and eigenvectors
	
	@description
	Finds the eigenvalues and eigenvectors of the incoming matrix, via the power iteration method.
	
	@discussion
	An overview of the power iteration method can be found for instance in 
	http://www.cs.cornell.edu/~bindel/class/cs6210-f09/lec26.pdf 
	The first eigenvalue found by this method is usually the dominant eigenvalue, and thus it will most likely
	be the most accurate one. For complex-valued eigenvalues, the convergence to the moudulo is not assured 
	(and thus also the relative eigenvectors' accuracy). If a matrix is singular, N eigenvalues will 
	be surely 0, N being is the dimension of the kernel (these zero-eigenvalues correspond to the 
	kernel spanning eigenvectors). <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	eigenvalue, eigenvector, find, power, iteration, matrix

	@seealso
	bach.mtimes, bach.extractbasis, jitcellblock, Into The Matrix
	
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

typedef struct _eig
{
	struct llllobj_object 	n_ob;
	
	long		num_iterations;
	long		max_coeff_for_random_vector;

} t_eig;


void eig_assist(t_eig *x, void *b, long m, long a, char *s);
void eig_inletinfo(t_eig *x, void *b, long a, char *t);

t_eig *eig_new(t_symbol *s, short ac, t_atom *av);
void eig_free(t_eig *x);

void eig_bang(t_eig *x);
void eig_int(t_eig *x, t_atom_long num);
void eig_float(t_eig *x, double num);
void eig_anything(t_eig *x, t_symbol *msg, long ac, t_atom *av);

t_class *eig_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.eig", (method)eig_new, (method)eig_free, (short)sizeof(t_eig), 0L, A_GIMME, 0);
	
	// @method llll @digest Find eigenvalues and eigenvectors of incoming matrix
	// @description The object outputs the eigenvalues and the eigenvectors of the incoming matrix. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)eig_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)eig_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)eig_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)eig_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the eigenvalues and eigenvectors search
	// @description Perform the eigenvalues and eigenvectors search on the most recently received input data.
	class_addmethod(c, (method)eig_bang,						"bang",								0);
	
	class_addmethod(c, (method)eig_assist,					"assist",				A_CANT,		0);
	class_addmethod(c, (method)eig_inletinfo,					"inletinfo",			A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_LONG(c, "numiter", 0, t_eig, num_iterations); 
	CLASS_ATTR_STYLE_LABEL(c,"numiter",0,"text","Number of Iterations");
	CLASS_ATTR_BASIC(c,"numiter",0);
	// @description Number of iterations in the power method algorithm.

	CLASS_ATTR_LONG(c, "maxcoeffrandvect", 0, t_eig, max_coeff_for_random_vector); 
	CLASS_ATTR_STYLE_LABEL(c,"maxcoeffrandvect",0,"text","Max Coefficient for Initial Random Vector");
	// @description Maximum coefficient of the power method.
	
	class_register(CLASS_BOX, c);
	eig_class = c;
	
	dev_post("bach.eig compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void eig_bang(t_eig *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void eig_int(t_eig *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	eig_anything(x, _llllobj_sym_list, 1, argv);
}

void eig_float(t_eig *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	eig_anything(x, _llllobj_sym_list, 1, argv);
}

void eig_anything(t_eig *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	t_llll *eigenvals = NULL, *eigenvec = NULL;
	
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
		llll_get_eigenvalues_and_eigenvectors(inlist, &eigenvals, &eigenvec, x->num_iterations, x->max_coeff_for_random_vector);
	
	llll_free(inlist);
	x->n_ob.l_rebuild = 0;

	if (eigenvals)
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, eigenvals, 0);

	if (eigenvec)
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, eigenvec, 1);

	eig_bang(x);
}


void eig_assist(t_eig *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The incoming matrix
		sprintf(s, "llll: Matrix");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0)	// @in 0 @type llll @digest The eigenvalues of the matrix
			sprintf(s, "llll (%s): Eigenvalues", type);
		else	// @in 1 @type llll @digest The eigenvectors relative to the eigenvalues, listed by rows
			sprintf(s, "llll (%s): Eigenvectors", type);	// @description	The eigenvalues are listed by rows in the output matrix, and are normalized.
	}
}

void eig_inletinfo(t_eig *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void eig_free(t_eig *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_eig *eig_new(t_symbol *s, short ac, t_atom *av)
{
	t_eig *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_eig *) object_alloc_debug(eig_class))) {
	
		x->num_iterations = 20;
		x->max_coeff_for_random_vector = 100;
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "44");

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

