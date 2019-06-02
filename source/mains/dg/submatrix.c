/**
	@file
	submatrix.c
	
	@name 
	bach.submatrix
	
	@realname 
	bach.submatrix

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Get a submatrix of a matrix
	
	@description
	Trims and outputs a rectangular portion of a matrix.
	
	@discussion
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	matrix, crop, cut, slice
	
	@seealso
	bach.minfo, bach.diag, bach.idmatrix, bach.wellshape, bach.m2jitcellblock, Into The Matrix
	
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

typedef struct _submatrix
{
	struct llllobj_object 	n_ob;

	long		start_row;
	long		end_row;
	long		start_col;
	long		end_col;

	void		*n_proxy[5];
	long		n_in;

} t_submatrix;


void submatrix_assist(t_submatrix *x, void *b, long m, long a, char *s);
void submatrix_inletinfo(t_submatrix *x, void *b, long a, char *t);

t_submatrix *submatrix_new(t_symbol *s, short ac, t_atom *av);
void submatrix_free(t_submatrix *x);

void submatrix_bang(t_submatrix *x);
void submatrix_int(t_submatrix *x, t_atom_long num);
void submatrix_float(t_submatrix *x, double num);
void submatrix_anything(t_submatrix *x, t_symbol *msg, long ac, t_atom *av);

t_class *submatrix_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.submatrix", (method)submatrix_new, (method)submatrix_free, (short)sizeof(t_submatrix), 0L, A_GIMME, 0);
	

	// @method llll @digest Set original matrix and output submatrix
	// @description The original matrix is trimmed and the result is output. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)submatrix_anything,					"anything",				A_GIMME,	0);


	// @method list @digest Set all the boundaries at once
	// @description In the second inlet, a list of four integer numbers sets all the resize boundaries at once.
	// Also see the <m>int</m> message.
	class_addmethod(c, (method)submatrix_anything,					"list",					A_GIMME,	0);

	// @method int @digest Set a boundary
	// @description The action depends on the inlet: <br />
	// - in the second inlet: Sets the starting row for trimming <br />
	// - in the third inlet: Sets the starting column for trimming <br />
	// - in the fourth inlet: Sets the ending row for trimming <br />
	// - in the fifth inlet: Sets the ending column for trimming
	class_addmethod(c, (method)submatrix_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)submatrix_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)submatrix_bang,						"bang",		0);
	
	class_addmethod(c, (method)submatrix_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)submatrix_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);



	class_register(CLASS_BOX, c);
	submatrix_class = c;
	
	dev_post("bach.submatrix compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void submatrix_bang(t_submatrix *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void submatrix_int(t_submatrix *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	submatrix_anything(x, _llllobj_sym_list, 1, argv);
}

void submatrix_float(t_submatrix *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	submatrix_anything(x, _llllobj_sym_list, 1, argv);
}

void submatrix_anything(t_submatrix *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	t_llll *inlist;
	t_llll *submatrix = NULL;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	if (inlet == 1) {
		if (ac > 0) {
			x->start_row = atom_getlong(av);
			if (ac > 1) {
				x->start_col = atom_getlong(av + 1);
				if (ac > 2) {
					x->end_row = atom_getlong(av + 2);
					if (ac > 3) {
						x->end_col = atom_getlong(av + 3);
					}
				}
			}
		}
	} else if (inlet == 2 && ac)
		x->start_col = atom_getlong(av);
	else if (inlet == 3 && ac)
		x->end_row = atom_getlong(av);
	else if (inlet == 4 && ac)
		x->end_col = atom_getlong(av);

	// do calculations
	if (inlet == 0) {
		
		inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
		
		if (inlist) {
			submatrix = llll_get_submatrix(inlist, x->start_row, x->start_col, x->end_row, x->end_col);
		}
		
		if (submatrix)
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, submatrix, 0);
		else
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);

		llll_free(inlist);
		x->n_ob.l_rebuild = 0;
		submatrix_bang(x);
	}
}


void submatrix_assist(t_submatrix *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) // @in 0 @type llll @digest Matrix to be trimmed
			sprintf(s, "llll: Matrix");
		else if (a == 1) // @in 1 @type int @digest Starting row for trimming
			sprintf(s, "int: Start Row");
		else if (a == 2) // @in 2 @type int @digest Starting column for trimming
			sprintf(s, "int: Start Column");
		else if (a == 3) // @in 3 @type int @digest Ending row for trimming
			sprintf(s, "int: End Row");
		else // @in 4 @type int @digest Ending column for trimming
			sprintf(s, "int: End Column");
	} else {
		char *type = NULL; // @out 1 @type llll @digest Trimmed submatrix
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Submatrix", type);
	}
}

void submatrix_inletinfo(t_submatrix *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void submatrix_free(t_submatrix *x)
{	
	long i;
	for (i = 1; i < 5; i++)
		object_free_debug(x->n_proxy[i]);

	llllobj_obj_free((t_llllobj_object *) x);
}

t_submatrix *submatrix_new(t_symbol *s, short ac, t_atom *av)
{
	t_submatrix *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_submatrix *) object_alloc_debug(submatrix_class))) {
	
		long true_ac = attr_args_offset(ac, av);

		x->start_row = x->end_row = x->start_col = x->end_col = 0;
		x->n_proxy[4] = proxy_new_debug((t_object *) x, 4, &x->n_in);
		x->n_proxy[3] = proxy_new_debug((t_object *) x, 3, &x->n_in);
		x->n_proxy[2] = proxy_new_debug((t_object *) x, 2, &x->n_in);
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 5, "4");

		// @arg 0 @name startrow @optional 1 @type int @digest Starting row for trimming  
		// @description Set the starting row for trimming.
		// @arg 1 @name startcolumn @optional 1 @type int @digest Starting column for trimming  
		// @description Set the starting column for trimming.
		// @arg 2 @name endrow @optional 1 @type int @digest Ending row for trimming  
		// @description Set the ending row for trimming.
		// @arg 3 @name endcolumn @optional 1 @type int @digest ending column for trimming  
		// @description Set the ending column for trimming.

		if (true_ac > 0)
			x->start_row = atom_getlong(av);
		if (true_ac > 1)
			x->start_col = atom_getlong(av + 1);
		if (true_ac > 2)
			x->end_row = atom_getlong(av + 2);
		if (true_ac > 3)
			x->end_col = atom_getlong(av + 3);

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

