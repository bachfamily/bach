/**
	@file
	adj.c
	
	@name 
	bach.adj
	
	@realname 
	bach.adj

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the adjugate of a matrix
	
	@description
	Computes the adjugate (or the classical adjoint) of an incoming matrix, 
	i.e. the transposed of the matrix whose entries are the cofactors of the incoming matrix. 
	If such a matrix can't be computed (for instance for non-wellshaped or non-square matrices)
	a bang is output through the right outlet.
	
	@discussion
	For a non-singular matrix, adj(A) / det(A) = inv(A). Yet, <o>bach.adj</o> and <o>bach.inv</o> use 
	different algorithms, thus computationally the results might slightly differ on floats. <br /> <br />
	@copy BACH_DOC_MATRIXCALCULUS_MATRIX
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	adjoint, matrix, adjugate, transpose, cofactor, determinant, inverse, invert
	
	@seealso
	bach.trans, bach.inv, bach.m2jitcellblock
	
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

typedef struct _adj
{
	struct llllobj_object 	n_ob;
	char		mode;
} t_adj;


void adj_assist(t_adj *x, void *b, long m, long a, char *s);
void adj_inletinfo(t_adj *x, void *b, long a, char *t);

t_adj *adj_new(t_symbol *s, short ac, t_atom *av);
void adj_free(t_adj *x);

void adj_bang(t_adj *x);
void adj_int(t_adj *x, t_atom_long num);
void adj_float(t_adj *x, double num);
void adj_anything(t_adj *x, t_symbol *msg, long ac, t_atom *av);

t_class *adj_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.adj", (method)adj_new, (method)adj_free, (short)sizeof(t_adj), 0L, A_GIMME, 0);
	

	// @method llll @digest Output the adjugate of incoming matrix.
	// @description The adjugate (or classical adjoint) of the incoming matrix is output. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)adj_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)adj_int,							"int",					A_LONG,		0);
	class_addmethod(c, (method)adj_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)adj_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Output the adjoint
	// @description Output the adjoint of the most recently received input data.
	class_addmethod(c, (method)adj_bang,						"bang",								0);
	
	class_addmethod(c, (method)adj_assist,					"assist",				A_CANT,		0);
	class_addmethod(c, (method)adj_inletinfo,					"inletinfo",			A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	class_register(CLASS_BOX, c);
	adj_class = c;
	
	dev_post("bach.adj compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void adj_bang(t_adj *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void adj_int(t_adj *x, t_atom_long num)
{
	t_atom argv[1]; 
	atom_setlong(argv, num);
	adj_anything(x, _llllobj_sym_list, 1, argv);
}

void adj_float(t_adj *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	adj_anything(x, _llllobj_sym_list, 1, argv);
}

void adj_anything(t_adj *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	t_llll *adj_llll = NULL;
	
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
		adj_llll = llll_adj(inlist);
	
	if (adj_llll) {
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, adj_llll, 0);
	} else {
		llllobj_outlet_bang((t_object *)x, LLLL_OBJ_VANILLA, 1);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
	}
	
	llll_free(inlist);
	x->n_ob.l_rebuild = 0;
	adj_bang(x);
}


void adj_assist(t_adj *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest Incoming matrix
		sprintf(s, "llll: Matrix");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) // @out 0 @type llll @digest Adjugate of incoming matrix (if any)
			sprintf(s, "llll (%s): Adjugate Matrix (if Any)", type);
		else // @out 1 @type bang @digest A bang is output if no adjugate matrix could be computed.
			sprintf(s, "bang if No Adjugate Exists");
	}
}

void adj_inletinfo(t_adj *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void adj_free(t_adj *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_adj *adj_new(t_symbol *s, short ac, t_atom *av)
{
	t_adj *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_adj *) object_alloc_debug(adj_class))) {
	
		x->mode = 0; // unused
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "b4");

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

