/*
 *  prime.c
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
 prime.c
 
 @name 
 bach.prime
 
 @realname 
 bach.prime
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Primality test
 
 @description
 Returns 1 if the input number is prime, 0 otherwise.
 
 @discussion
 Even in 64-bit mode, the primality test can be performed only on numbers up to 2147483647.
 
 @category
 bach, bach objects, bach math
 
 @keywords
 prime, test, number

 @seealso
 bach.factorize, bach.primeser
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _prime
{
	t_llllobj_object	n_ob;
	void		*n_out;
	long		n_prime;
} t_prime;


void prime_assist(t_prime *x, void *b, long m, long a, char *s);
void prime_inletinfo(t_prime *x, void *b, long a, char *t);

t_prime *prime_new(t_symbol *s, short ac, t_atom *av);

void prime_bang(t_prime *x);
void prime_int(t_prime *x, t_atom_long v);
void prime_float(t_prime *x, double v);
void prime_anything(t_prime *x, t_symbol *msg, long ac, t_atom *av);

t_class *prime_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.prime", (method)prime_new, NULL, (long) sizeof(t_prime), 0L, A_GIMME, 0);

	// @method int @digest Perform the primality test
	// @description The primality test is performed on the integer.
	// If a negative number is input, the test is performed on its opposite.
	// Even in 64-bit mode, the primality test can be performed only on numbers up to 2147483647.
	class_addmethod(c, (method)prime_int,			"int",			A_LONG,		0);
	
	// @method float @digest Converted to int
	// @description A float is converted to an int, and the primality test is performed.
	class_addmethod(c, (method)prime_float,			"float",		A_FLOAT,	0);
	
    //class_addmethod(c, (method)prime_anything,      "anything",     A_GIMME, 0);
    
	// @method bang @digest Return last result
	// @description The result of the last primality test performed is returned.
	class_addmethod(c, (method)prime_bang,			"bang",			0);

	class_addmethod(c, (method)prime_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)prime_inletinfo,		"inletinfo",	A_CANT,		0);

    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);
    bachobject_class_add_fileusage_method(c);

	class_register(CLASS_BOX, c);
	prime_class = c;

	dev_post("bach.prime compiled %s %s", __DATE__, __TIME__);

	return;
}

void prime_bang(t_prime *x)
{	
	outlet_int(x->n_out, x->n_prime);
}

void prime_int(t_prime *x, t_atom_long v)
{
#ifdef C74_X64
	if (v > 0x7fffffffl || v < -0x80000000l) {
		object_error((t_object *) x, "Only numbers from %ld to %ld can be tested", -0x80000000l, 0x7fffffffl);
		return;
	}
#endif
	x->n_prime = llll_prime(v);
	prime_bang(x);
}

void prime_float(t_prime *x, double v)
{
	prime_int(x, v);
}

void prime_assist(t_prime *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET)
		sprintf(s, "int to Be Tested for Primality"); // @in 0 @type int @digest Number to be tested for primality
	else
		sprintf(s, "int: Primality"); // @out 0 @type int @digest Primality (0/1)
}

void prime_inletinfo(t_prime *x, void *b, long a, char *t)
{
	*t = 1;
}

t_prime *prime_new(t_symbol *s, short ac, t_atom *av)
{
	t_prime *x = NULL;
	
	if ((x = (t_prime *) object_alloc(prime_class))) {
		x->n_out = intout(x);
        llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
		return x;
	} else
		error(BACH_CANT_INSTANTIATE);
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
