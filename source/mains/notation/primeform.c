/*
 *  primeform.c
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
	primeform.c
	
	@name 
	bach.primeform
	
	@realname 
	bach.primeform

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the prime form of a pitch-class set
	
	@description
	Computes the prime form of a pitch-class set, i.e. the "smalles" copy of the set,
	with respect to a given ordering, defined by the <m>mode</m> attribute.
	
	@discussion
	To understand the concept of copy, one should first refer to the concept of group action. <br />
	@copy BACH_DOC_SETTHEORY_GROUPS
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET 
	
	@category
	bach, bach objects, bach set theory

	@keywords
	prime form, pitch-class, normal form, order, group, modulo, action, copy, compute, calculate, transpose, invert

	@seealso
	bach.ifunc, bach.zsearch, bach.circle, bach.ivec, bach.pcsetinfo, bach.mod+, bach.mod-, bach.modtimes
	
	@owner
	Daniele Ghisi
*/


#include "math/llll_settheory.h" 
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>

typedef struct _primeform
{
	struct llllobj_object 	n_ob;

	t_atom_long				modulo;
	char				mode;
	char				group;
	
	void				*n_proxy[2];
	long				n_in;

} t_primeform;


void primeform_assist(t_primeform *x, void *b, long m, long a, char *s);
void primeform_inletinfo(t_primeform *x, void *b, long a, char *t);

t_primeform *primeform_new(t_symbol *s, short ac, t_atom *av);
void primeform_free(t_primeform *x);

void primeform_bang(t_primeform *x);
void primeform_int(t_primeform *x, t_atom_long num);
void primeform_float(t_primeform *x, double num);
void primeform_anything(t_primeform *x, t_symbol *msg, long ac, t_atom *av);
void primeform_getlist(t_primeform *x, t_symbol *msg, long ac, t_atom *av);

t_class *primeform_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.primeform", (method)primeform_new, (method)primeform_free, (long) sizeof(t_primeform), 0L, A_GIMME, 0);
	
	// @method llll @digest Compute prime form of pitch-class set 
	// @description In the first inlet, a pitch-class set, in the form of a plain list, will trigger the output of its prime form. 	
	class_addmethod(c, (method)primeform_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)primeform_anything,					"list",					A_GIMME,	0);

	// @method getlist @digest Obtain a list of all prime forms
	// @description If no further arguments are given, output the list of all prime forms.
	// If a single (integer) argument is given, output the list of all prime form of that cardinality.
	// If two arguments are given, those are considered to be the lower and upper boundary for the cardinalities
	// of the prime form to output. <br />
	// All output prime form are in any case regrouped in levels depending on their cardinalities
	// (so all sets of cardinality k are gathered in a level of parenthesis.) 	
	// @marg 0 @name card_or_mincard @optional 1 @type int
	// @marg 0 @name maxcard @optional 1 @type int
    // @example getlist @caption get all the prime forms
    // @example getlist 4 @caption ...of cardinality 4
    // @example getlist 4 7 @caption ...of cardinality between 4 and 7
	class_addmethod(c, (method)primeform_getlist,					"getlist",				A_GIMME,	0);

	// @method int @digest Set modulo 
	// @description An integer in the right inlet will set the modulo. <br />
	// @copy BACH_DOC_SETTHEORY_MODULO
	class_addmethod(c, (method)primeform_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)primeform_float,						"float",				A_FLOAT,	0);

	// @method bang @digest Perform the last prime form computation
	// @description Perform the prime form computation on the most recently received input data.
	class_addmethod(c, (method)primeform_bang,						"bang",		0);
	
	class_addmethod(c, (method)primeform_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)primeform_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_CHAR(c, "mode", 0, t_primeform, mode); 
	CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
	CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Lexicographic Compactness First"); 
	CLASS_ATTR_BASIC(c,"mode",0);
	//	@description Criterion according to which the prime forms are chosen. <br />
	//	@copy BACH_DOC_SETTHEORY_PRIMEFORMORDERINGCRITERION

	CLASS_ATTR_CHAR(c, "group", 0, t_primeform, group); 
	CLASS_ATTR_STYLE_LABEL(c,"group",0,"enumindex","Group");
	CLASS_ATTR_ENUMINDEX(c,"group", 0, "Transp Transp/Inv Affine"); 
	CLASS_ATTR_BASIC(c,"group",0);
	//	@description The group according to which we consider the prime forms. <br />
	//  @copy BACH_DOC_SETTHEORY_GROUPS

	class_register(CLASS_BOX, c);
	primeform_class = c;
	
	dev_post("bach.primeform compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void primeform_bang(t_primeform *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void primeform_int(t_primeform *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	primeform_anything(x, _llllobj_sym_list, 1, argv);
}

void primeform_float(t_primeform *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	primeform_anything(x, _llllobj_sym_list, 1, argv);
}

void primeform_anything(t_primeform *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	t_llll *inlist;
	t_llll *primeform = NULL;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	if (inlet == 1 && ac) {
		t_atom_long this_modulo = atom_getlong(av); 
		if (this_modulo) 
			x->modulo = labs(this_modulo);
	}
	
	// do calculations
	if (inlet == 0) {
		long transp_component = 0, mult_component = 1;
		t_llll *components = llll_get();
		
		inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		
		if (inlist)
			primeform = pcset_get_primeform(inlist, x->modulo, (e_primeform_modes)x->mode, (e_settheory_groups)x->group, &mult_component, &transp_component);
		
		if (primeform)
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, primeform, 0);
		else
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);

		
		llll_appendlong(components, mult_component, 0, WHITENULL_llll);
		llll_appendlong(components, transp_component, 0, WHITENULL_llll);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, components, 1);

		llll_free(inlist);
		x->n_ob.l_rebuild = 0;
		primeform_bang(x);
	}
}

void primeform_getlist(t_primeform *x, t_symbol *msg, long ac, t_atom *av)
{
	t_atom_long from = 1;
	t_atom_long to = x->modulo;
	t_atom_long i;
	t_llll *out_llll = llll_get();
	
	if (ac >= 2) {
		if (atom_gettype(av) == A_LONG)
			from = atom_getlong(av);
		if (atom_gettype(av + 1) == A_LONG)
			to = atom_getlong(av + 1);
	} else if (ac >= 1) {
		if (atom_gettype(av) == A_LONG)
			from = to = atom_getlong(av);
	}
	
	from = MAX(from, 1);
	to = MIN(to, x->modulo);
	
	for (i = from; i <= to; i++)
		llll_appendllll(out_llll, get_all_prime_forms(x->modulo, i, (e_primeform_modes)x->mode, (e_settheory_groups)x->group), 0, WHITENULL_llll);
	
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, out_llll, 0);
	x->n_ob.l_rebuild = 0;
	primeform_bang(x);
}


void primeform_assist(t_primeform *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) // @in 0 @type llll @digest Pitch-class set
			sprintf(s, "llll: Pitch Class Set"); 
		else	// @in 1 @type int @digest The modulo
			sprintf(s, "int: Modulo");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0)	 // @out 0 @type llll @digest Prime form of incoming pitch-class set
			sprintf(s, "llll (%s): Prime Form", type);
		else	// @out 1 @type llll @digest Multiplier and Summand To Get To Prime Form
				// @description Two numbers are output. If one multiplies the original set by
				// the first number, and then sums the second number, one obtains the prime form.
			sprintf(s, "llll (%s): Multiplier and Summand To Get To Prime Form", type);
	}
}

void primeform_inletinfo(t_primeform *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void primeform_free(t_primeform *x)
{	
	long i;
	for (i = 1; i < 2; i++)
		object_free_debug(x->n_proxy[i]);

	llllobj_obj_free((t_llllobj_object *) x);
}

t_primeform *primeform_new(t_symbol *s, short ac, t_atom *av)
{
	t_primeform *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_primeform *) object_alloc_debug(primeform_class))) {
	
		long true_ac = attr_args_offset(ac, av);
		
		x->group = k_GROUP_TI;
		x->mode = k_PRIMEFORM_MODE_LEXICOGRAPHIC;
		x->modulo = 12;
		
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 5, "44");

		if (true_ac) {
			// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
			// @description @copy BACH_DOC_SETTHEORY_MODULO
			x->modulo = atom_getlong(av);
			if (x->modulo < 0) x->modulo = -x->modulo;
			if (x->modulo == 0) x->modulo = 12;
		}
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

