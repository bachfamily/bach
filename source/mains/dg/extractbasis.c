/**
	@file
	extractbasis.c
	
	@name 
	bach.extractbasis
	
	@realname 
	bach.extractbasis

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Find linearly independent vectors
	
	@description
	Extracts a set of linearly independent vectors from an incoming list of vectors.
	Depending on its attributes, it can also transform the vectors so that they be orthogonal and/or unitary.
	
	@discussion
	The algorithm used to extract the vectors is the Gauss elimination. Gram-Schmidt is used to make
	vectors orthogonal.
	
	@category
	bach, bach objects, bach matrix calculus

	@keywords
	extract, find, basis, vector, orthogonal, unitary, linear independence

	@seealso
	bach.gausselim, bach.linearsolve, bach.ker, bach.im, Into The Matrix
	
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

typedef struct _extractbasis
{
	struct llllobj_object 	n_ob;
	
	char		make_orthogonal;
	char		make_unitary;

} t_extractbasis;


void extractbasis_assist(t_extractbasis *x, void *b, long m, long a, char *s);
void extractbasis_inletinfo(t_extractbasis *x, void *b, long a, char *t);

t_extractbasis *extractbasis_new(t_symbol *s, short ac, t_atom *av);
void extractbasis_free(t_extractbasis *x);

void extractbasis_bang(t_extractbasis *x);
void extractbasis_int(t_extractbasis *x, t_atom_long num);
void extractbasis_float(t_extractbasis *x, double num);
void extractbasis_anything(t_extractbasis *x, t_symbol *msg, long ac, t_atom *av);

t_class *extractbasis_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.extractbasis", (method)extractbasis_new, (method)extractbasis_free, (short)sizeof(t_extractbasis), 0L, A_GIMME, 0);
	
	// @method llll @digest Find eigenvalues and eigenvectors of incoming matrix
	// @description The object outputs the eigenvalues and the eigenvectors of the incoming matrix. <br />
	// @copy BACH_DOC_MATRIXCALCULUS_MATRIX
	class_addmethod(c, (method)extractbasis_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)extractbasis_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)extractbasis_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)extractbasis_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the basis extraction
	// @description Perform the basis extraction on the most recently received input data.
	class_addmethod(c, (method)extractbasis_bang,						"bang",								0);
	
	class_addmethod(c, (method)extractbasis_assist,					"assist",				A_CANT,		0);
	class_addmethod(c, (method)extractbasis_inletinfo,					"inletinfo",			A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_CHAR(c, "makeorthogonal", 0, t_extractbasis, make_orthogonal); 
	CLASS_ATTR_STYLE_LABEL(c,"makeorthogonal",0,"onoff","Make Orthogonal");
	CLASS_ATTR_BASIC(c,"makeorthogonal",0);
	// @description Flag to tell if vectors should also be made orthogonal.

	CLASS_ATTR_CHAR(c, "makeunitary", 0, t_extractbasis, make_unitary); 
	CLASS_ATTR_STYLE_LABEL(c,"makeunitary",0,"onoff","Make Unitary");
	CLASS_ATTR_BASIC(c,"makeunitary",0);
	// @description Flag to tell if vectors should also be made unitary (normalized).

	class_register(CLASS_BOX, c);
	extractbasis_class = c;
	
	dev_post("bach.extractbasis compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void extractbasis_bang(t_extractbasis *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void extractbasis_int(t_extractbasis *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	extractbasis_anything(x, _llllobj_sym_list, 1, argv);
}

void extractbasis_float(t_extractbasis *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	extractbasis_anything(x, _llllobj_sym_list, 1, argv);
}

void extractbasis_anything(t_extractbasis *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	t_llll *extracted = NULL;
	
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
		extracted = llll_extract_basis(inlist, x->make_orthogonal, x->make_unitary);
	
	llll_free(inlist);
	x->n_ob.l_rebuild = 0;

	if (extracted) {
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, extracted, 0);
		extractbasis_bang(x);
	} else {
		llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 1);
	}
}


void extractbasis_assist(t_extractbasis *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The original vectors
		sprintf(s, "llll: Containing the Vectors"); // @description This is expected to be a list of plain lists, where each vector corresponds to a sublist.
													// such as <b>(0 0 1) (0 1 1) (0 2 0) (1 2 1)</b>.
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) // @out 0 @type llll @digest The extracted set of independent vectors
					// @description This will be a list of plain lists, where each vector corresponds to a sublist.
			sprintf(s, "llll (%s): Containing the Extracted Vectors", type);
		else	// @out 1 @type bang @digest bang if extraction failed
			sprintf(s, "bang if Extraction Failed");
	}
}

void extractbasis_inletinfo(t_extractbasis *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void extractbasis_free(t_extractbasis *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_extractbasis *extractbasis_new(t_symbol *s, short ac, t_atom *av)
{
	t_extractbasis *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_extractbasis *) object_alloc_debug(extractbasis_class))) {
	
		x->make_orthogonal = x->make_unitary = 0;
		
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

