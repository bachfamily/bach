/*
 *  minfo.c
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
	minfo.c
	
	@name 
	bach.minfo
	
	@realname 
	bach.minfo

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Report information about a matrix
	
	@description
	Outputs the number of rows and columns of an incoming matrix, plus an additional information 
	which tells us whether the matrix is well-shaped or square.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach objects, bach matrix calculus

	@keyword
	matrix, information, square, well-shaped, row, column, size, symmetry

	@seealso
	bach.diag, bach.submatrix, bach.idmatrix, bach.mrandom, bach.wellshape, bach.m2jitcellblock, Into The Matrix
	
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

typedef struct _minfo
{
	struct llllobj_object 	n_ob;

	long					num_rows;
	long					num_cols;
	char					is_ws; // well shaped?
	char					is_square; // is square?
	char					is_sym; // is symmetric?
	
	char					match_type; // for symmetricity

} t_minfo;


void minfo_assist(t_minfo *x, void *b, long m, long a, char *s);
void minfo_inletinfo(t_minfo *x, void *b, long a, char *t);

t_minfo *minfo_new(t_symbol *s, short ac, t_atom *av);
void minfo_free(t_minfo *x);

void minfo_int(t_minfo *x, t_atom_long num);
void minfo_float(t_minfo *x, double num);
void minfo_anything(t_minfo *x, t_symbol *msg, long ac, t_atom *av);

t_class *minfo_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.minfo", (method)minfo_new, (method)minfo_free, (short)sizeof(t_minfo), 0L, A_GIMME, 0);
	
	// @method llll @digest Output information about incoming matrix
	// @description The object outputs the information about the incoming matrix. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)minfo_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)minfo_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)minfo_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)minfo_anything,					"list",					A_GIMME,	0);
	
	class_addmethod(c, (method)minfo_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)minfo_inletinfo,	"inletinfo",	A_CANT,		0);


    // no @out attribute, only versionnumber (hidden)
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_CHAR(c, "matchtype", 0, t_minfo, match_type);
	CLASS_ATTR_STYLE_LABEL(c,"matchtype",0,"onoff","Match Type for Symmetricity");
	CLASS_ATTR_BASIC(c,"matchtype",0);
	// @discussion If this flag is set, the symmetricity check for a matrix will take 
	// into account the types of elements. For instance, <b>[0 1] [1. 0]</b> would not be
	// a symmetric matrix, while <b>[0 1.] [1. 0]</b> would be perfectly symmetric.
	// If the flag is not set, the element types are ignored, and both previous matrices
	// are considered symmetric. 
	
	class_register(CLASS_BOX, c);
	minfo_class = c;
	
	dev_post("bach.minfo compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void minfo_int(t_minfo *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	minfo_anything(x, _llllobj_sym_list, 1, argv);
}

void minfo_float(t_minfo *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	minfo_anything(x, _llllobj_sym_list, 1, argv);
}

void minfo_anything(t_minfo *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	
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
		x->num_rows = llll_get_matrix_num_rows(inlist);
		x->num_cols = llll_get_matrix_num_cols(inlist, &x->is_ws);
		x->is_square = (x->is_ws && (x->num_rows == x->num_cols)) ? true : false;
		x->is_sym = (x->is_ws && x->is_square && llll_is_matrix_symmetrical(inlist, x->match_type)) ? true : false;
	} else {
		x->num_rows = x->num_cols = -1;
		x->is_ws = false;
		x->is_square = false;
	}
	
	llll_free(inlist);

	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 4, x->is_sym);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 3, x->is_square);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 2, x->is_ws);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 1, x->num_cols);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 0, x->num_rows);
}


void minfo_assist(t_minfo *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The matrix
		sprintf(s, "llll: Matrix");
	} else {
		if (a == 0) // @out 0 @type int @digest The number or rows
			sprintf(s, "int: Number of Rows");
		else if (a == 1) // @out 1 @type int @digest The number of columns
			sprintf(s, "int: Number of Columns");
		else if (a == 2) // @out 2 @type int @digest 1 if the matrix is well-shaped, 0 otherwise
			sprintf(s, "1 if Matrix Is Well-Shaped, 0 Otherwise");
		else if (a == 3) // @out 3 @type int @digest 1 if the matrix is square, 0 otherwise
			sprintf(s, "1 if Matrix Is Square, 0 Otherwise");
		else // @out 4 @type int @digest 1 if the matrix is symmetrical, 0 otherwise
			sprintf(s, "1 if Matrix Is Symmetrical, 0 Otherwise");
	}
}

void minfo_inletinfo(t_minfo *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void minfo_free(t_minfo *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_minfo *minfo_new(t_symbol *s, short ac, t_atom *av)
{
	t_minfo *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_minfo *) object_alloc_debug(minfo_class))) {

		x->match_type = false;
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "iiiii");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

