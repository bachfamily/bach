/**
 @file
 factorize.c
 
 @name 
 bach.factorize
 
 @realname 
 bach.factorize
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Factorize a number
 
 @description
 Returns the factorization of an integer.
 
 @category
 bach, bach objects, bach math
 
 @keywords
 integer, number, factorization, factorize, factor, prime

 @seealso
 bach.prime, bach.primeser 
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _factorize
{
	struct llllobj_object 	n_ob;
} t_factorize;


void factorize_assist(t_factorize *x, void *b, long m, long a, char *s);
void factorize_inletinfo(t_factorize *x, void *b, long a, char *t);

t_factorize *factorize_new(t_symbol *s, short ac, t_atom *av);
void factorize_free(t_factorize *x);

void factorize_bang(t_factorize *x);
void factorize_int(t_factorize *x, t_atom_long v);
void factorize_float(t_factorize *x, double v);

t_class *factorize_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.factorize", (method)factorize_new, (method)factorize_free, (short)sizeof(t_factorize), 0L, A_GIMME, 0);
	
	// @method int @digest Compute the factorization
	// @description The factorization of the given integer is returned as an llll whose sublists contain each a prime factor and its exponent.
	// If a negative integer is received, the factorization of its opposite is returned.
	// Even in 64-bit mode, only numbers up to 2147483647 can be factorized
	class_addmethod(c, (method)factorize_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)factorize_float,			"float",		A_FLOAT,	0);
	
	// @method bang @digest Perform last operation
	// @description Return the factorization of the last received number
	class_addmethod(c, (method)factorize_bang,			"bang",			0);
	
	class_addmethod(c, (method)factorize_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)factorize_inletinfo,		"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
	

	class_register(CLASS_BOX, c);
	factorize_class = c;
	
	dev_post("bach.factorize compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void factorize_bang(t_factorize *x)
{	
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void factorize_int(t_factorize *x, t_atom_long v)
{
#ifdef C74_X64
	if (v > 0x7fffffffll || v < -0x80000000ll) {
		object_error((t_object *) x, "Only numbers from %ld to %ld can be factorized", -0x80000000l, 0x7fffffffl);
		return;
	}
#endif
	llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, llll_factorize(v), 0);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void factorize_float(t_factorize *x, double v)
{
	factorize_int(x, v);
}

void factorize_assist(t_factorize *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) 
		sprintf(s, "int to Factorize"); // @in 0 @type int @digest Number to factorize
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Result", type);
		// @out 0 @type llll @digest Factorization
		// @description The factorization is returned as an llll whose sublists contain each a prime factor and its exponent.
		// For instance, the factorization of 12 is expressed as <b>(2 2) (3 1)</b>
	}
}

void factorize_inletinfo(t_factorize *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void factorize_free(t_factorize *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_factorize *factorize_new(t_symbol *s, short ac, t_atom *av)
{
	t_factorize *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_factorize *) object_alloc_debug(factorize_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}