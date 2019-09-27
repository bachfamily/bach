/*
 *  zsearch.c
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
	zsearch.c
	
	@name 
	bach.zsearch
	
	@realname 
	bach.zsearch

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Search for Z-related pitch-class sets
	
	@description
	Performs a search for families of pitch-class sets having the 
	same interval vector, but whose elements are not pairwise related by a group tranformation 
	such as Transposition or Transposition/Inversion. 	
	
	@discussion
	Z-relation relies on the concept of "copies" and thus on the concept of group action. <br /> <br />
	@copy BACH_DOC_SETTHEORY_GROUPS
	<br /> The object outputs a llll containing one level for each requested cardinality to be searched,
	and then the found Z-related pitch-class sets in Z-Families (gathering all
	the pitch-class sets sharing the same (multi-)interval vector in a single level of parenthesis).

	@category
	bach, bach objects, bach set theory
	
	@keywords
	Z-relation, pitch-class, set, search, find, k-deck, copy, group, action, transposition, inversion,
	prime form, normal form, family, interval vector

	@seealso
	bach.ifunc, bach.primeform, bach.circle, bach.ivec, bach.pcsetinfo, bach.mod+, bach.mod-, bach.modtimes
	
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
#include "ext_critical.h"
#include <stdio.h>
#include <locale.h>

typedef struct _zsearch
{
	struct llllobj_object 	n_ob;

	long				modulo;
	char				mode;
	char				group;
	long				z_families_min_card;

	long				subset_cardinality;
	char				count_periodic_subsets_once;

	long m_in;   // space for the inlet number used by all the proxies
    void *m_proxy1;
} t_zsearch;


void zsearch_assist(t_zsearch *x, void *b, long m, long a, char *s);
void zsearch_inletinfo(t_zsearch *x, void *b, long a, char *t);

t_zsearch *zsearch_new(t_symbol *s, short ac, t_atom *av);
void zsearch_free(t_zsearch *x);

void zsearch_bang(t_zsearch *x);
void zsearch_int(t_zsearch *x, t_atom_long num);
void zsearch_float(t_zsearch *x, double num);
void zsearch_anything(t_zsearch *x, t_symbol *msg, long ac, t_atom *av);

t_class *zsearch_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
	c = class_new("bach.zsearch", (method)zsearch_new, (method)zsearch_free, (short)sizeof(t_zsearch), 0L, A_GIMME, 0);
	
	// @method llll @digest Trigger prime form search for given cardinalities
	// @description A single number k will trigger the search for all prime forms of cardinality k.
	// A couple of numbers, say [m n], will trigger the search for all cardinailties from m to n and output the result
    // @seealso all
    class_addmethod(c, (method)zsearch_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)zsearch_anything,					"list",					A_GIMME,	0);

    // @method all @digest Trigger prime form search for all cardinalities
    // @description An <m>all</m> message triggers prime form search for all cardinalities and outputs the results.
    // @seealso llll
    class_addmethod(c, (method)zsearch_anything,					"all",				A_GIMME,	0);

	// @method int @digest Set modulo 
	// @description An integer in the right inlet will set the modulo. <br /> <br />
	// @copy BACH_DOC_SETTHEORY_MODULO
	class_addmethod(c, (method)zsearch_int,							"int",					A_LONG,		0);
	class_addmethod(c, (method)zsearch_float,						"float",				A_FLOAT,	0);

	// @method bang @digest Perform the last search
	// @description Perform the search on the most recently received input data.
	class_addmethod(c, (method)zsearch_bang,						"bang",		0);
	
	class_addmethod(c, (method)zsearch_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)zsearch_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_CHAR(c, "mode", 0, t_zsearch, mode); 
	CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
	CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Lexicographic Compactness First"); 
	CLASS_ATTR_BASIC(c,"mode",0);
	//	@description Criterion according to which the prime forms are chosen. <br /> <br />
	//	@copy BACH_DOC_SETTHEORY_PRIMEFORMORDERINGCRITERION

	CLASS_ATTR_CHAR(c, "group", 0, t_zsearch, group); 
	CLASS_ATTR_STYLE_LABEL(c,"group",0,"enumindex","Group");
	CLASS_ATTR_ENUMINDEX(c,"group", 0, "Transp Transp/Inv"); 
	CLASS_ATTR_BASIC(c,"group",0);
	//	@description The group according to which we consider the prime forms. <br /> <br />
	//  @copy BACH_DOC_SETTHEORY_GROUPS

	CLASS_ATTR_LONG(c,"modulo",0, t_zsearch, modulo);
	CLASS_ATTR_STYLE_LABEL(c,"modulo",0,"text","Modulo");
	CLASS_ATTR_FILTER_MIN(c, "modulo", 1);
	CLASS_ATTR_BASIC(c,"modulo",0);
	//	@description The modulo of the diagram. <br /> <br />
	//  @copy BACH_DOC_SETTHEORY_MODULO

	CLASS_ATTR_LONG(c, "subsetscardinality", 0, t_zsearch, subset_cardinality); 
	CLASS_ATTR_STYLE_LABEL(c,"subsetscardinality",0,"text","Subset Cardinality");
	CLASS_ATTR_FILTER_MIN(c, "subsetscardinality",1);
	//  @description Cardinality of the test subsets. A generalized Z-search looks for equalities
	//  of the multi-interval vectors. In general the (multi-)interval vector counts the number
	//  of copies of the prime form of a certain cardinality which one can find in the original set:
	//  for instance the standard interval vector is a 2-vector, i.e. counts how many copies of sets like
	//  {0, 1} or {0, 4} are contained in the original sets (no wonder this numbers are exactly the number of
	//  semitones or major third one can find among the notes of the set). But this is true for any
	//  cardinality: we might ask which is the trichordal content of a vector, thus testing how many copies
	//  of sets like {0, 1, 2} or {0, 2, 5} are contained in the set. This number is the cardinality
	//  of this family of test sets. This is by default 2 (yielding the interval vector).
	//	If you want a k-vector (multi-interval analysis) change this number to k.

	CLASS_ATTR_LONG(c, "zfamiliesmincard", 0, t_zsearch, z_families_min_card); 
	CLASS_ATTR_STYLE_LABEL(c,"zfamiliesmincard",0,"text","Minimum Cardinality in a Z-Family");
	CLASS_ATTR_FILTER_MIN(c, "zfamiliesmincard",1);
	//	@description Minimum cardinality for a Z-family to be output. If this number is N,
	//  and the algorithm finds M prime forms sharing the same (multi-)interval vector,
	//  those prime forms are output only if M>=N. Typically this attribute is 2, meaning that
	//  if a prime form has no Z-partners (another prime form sharing the same (multi-)interval vector)
	//  it will not be output, and only really Z-related pitch-class sets are output.

	CLASS_ATTR_CHAR(c, "periodiconce", 0, t_zsearch, count_periodic_subsets_once); 
	CLASS_ATTR_STYLE_LABEL(c,"periodiconce",0,"onoff","Count Periodic Subsets Once");
	//	@description Some particular periodic subsets might be counted more than once while computing (multi-)interval vectors. 
	//  For instance: in (0 1 6), the set {0, 6} might be counted both as {0, 6} and as {6, 12}.
	//	If you don't want this, just set this attribute.
	//	Usually one does not want to count twice this occurrence (and the other occurrences 
	//  of periodic sets, if cardinality > 2), thus by default the attribute is set.

	class_register(CLASS_BOX, c);
	zsearch_class = c;
	
	dev_post("bach.zsearch compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void zsearch_bang(t_zsearch *x)
{
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		zsearch_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void zsearch_int(t_zsearch *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	zsearch_anything(x, _llllobj_sym_list, 1, argv);
}

void zsearch_float(t_zsearch *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	zsearch_anything(x, _llllobj_sym_list, 1, argv);
}



void zsearch_anything(t_zsearch *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	
	if (inlet == 1) {
		t_llll *in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_RETAIN);
		if (in_llll && in_llll->l_head && (hatom_gettype(&in_llll->l_head->l_hatom) == H_LONG || 
			hatom_gettype(&in_llll->l_head->l_hatom) == H_DOUBLE || hatom_gettype(&in_llll->l_head->l_hatom) == H_RAT))
			x->modulo = CLAMP(hatom_getlong(&in_llll->l_head->l_hatom), 1, CONST_MAX_MODULO);
		llll_free(in_llll);
	} else if (inlet == 0) {
		t_llll *inlist;
		if (msg != _sym_bang) {
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
			x->n_ob.l_rebuild = 1;
		}

		inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		
		if (inlist) {
			t_llll *zsets = NULL, *ivecs = NULL;
			long from = 0, to = x->modulo, i;
			t_llll *zsets_all = llll_get(), *ivecs_all = llll_get();

			if (inlist && inlist->l_head && (hatom_gettype(&inlist->l_head->l_hatom) == H_LONG || 
					hatom_gettype(&inlist->l_head->l_hatom) == H_DOUBLE || hatom_gettype(&inlist->l_head->l_hatom) == H_RAT)) {
				from = hatom_getlong(&inlist->l_head->l_hatom);
				if (!inlist->l_head->l_next)
					to = from;
			}

			if (inlist && inlist->l_head && inlist->l_head->l_next && (hatom_gettype(&inlist->l_head->l_next->l_hatom) == H_LONG || 
					hatom_gettype(&inlist->l_head->l_next->l_hatom) == H_DOUBLE || hatom_gettype(&inlist->l_head->l_next->l_hatom) == H_RAT))
				to = hatom_getlong(&inlist->l_head->l_next->l_hatom);

			from = CLAMP(from, 1, x->modulo);
			to = CLAMP(to, from, x->modulo);

			
			// copying data for thread safety
			long modulo = x->modulo;
			long subset_cardinality = x->subset_cardinality;
			e_primeform_modes mode = (e_primeform_modes)x->mode;
			e_settheory_groups group = (e_settheory_groups)x->group;
			char count_periodic_subsets_once = x->count_periodic_subsets_once;
			long z_families_min_card = x->z_families_min_card;
			
			for (i = from; i <= to; i++) {
				zsets = find_zrelated_pcsets(modulo, i, subset_cardinality, mode, group, count_periodic_subsets_once, z_families_min_card, &ivecs);
				if (zsets) 
					llll_appendllll(zsets_all, zsets, 0, WHITENULL_llll);
				if (ivecs) 
					llll_appendllll(ivecs_all, ivecs, 0, WHITENULL_llll);
			}
			
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, zsets_all, 0);
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ivecs_all, 1);
			
			llll_free(inlist);
			x->n_ob.l_rebuild = 0;
			zsearch_bang(x);
		}
	}
}


void zsearch_assist(t_zsearch *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0)	 // @in 0 @type int @digest Cardinality of Pitch Class Sets
			sprintf(s, "int: Cardinality of Pitch Class Sets");
		else // @in 1 @type int @digest Modulo
			sprintf(s, "int: Modulo");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) // @out 0 @type llll @digest Z-Families
					// @description The output list has one parenthesis level for each cardinality
					// and then one parenthesis level for Z-Family. This means that all the 
					// pitch-class sets sharing the same (multi-)interval vector are gathered
					// together in a subllll.
			sprintf(s, "llll (%s): Z-Families", type);
		else // @out 1 @type llll @digest Relative Interval Vectors
			 // @description The shape of this list refers to the shape of the output Z-Families:
			 // a single (multi-)interval vector is output for each family
			sprintf(s, "llll (%s): Relative Interval Vectors", type);
	}
}

void zsearch_inletinfo(t_zsearch *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void zsearch_free(t_zsearch *x)
{	
	object_free_debug(x->m_proxy1);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_zsearch *zsearch_new(t_symbol *s, short ac, t_atom *av)
{
	t_zsearch *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_zsearch *) object_alloc_debug(zsearch_class))) {
	
		long true_ac = attr_args_offset(ac, av);
		
		x->m_proxy1 = proxy_new_debug((t_object *) x, 1, &x->m_in);

		x->group = k_GROUP_TI;
		x->mode = k_PRIMEFORM_MODE_LEXICOGRAPHIC;
		x->modulo = 12;
		x->subset_cardinality = 2;
		x->count_periodic_subsets_once = true;
		x->z_families_min_card = 2;
				
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "44");

		if (true_ac > 0) {
			// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
			// @description @copy BACH_DOC_SETTHEORY_MODULO
			// @arg 1 @name subsetscardinality @optional 1 @type int @digest Subsets Cardinality  
			// @description Cardinality of the test subsets. See the <m>subsetscardinality</m> attribute.
			x->modulo = CLAMP(atom_getlong(av), 1, CONST_MAX_MODULO);
			if (true_ac > 1)
				x->subset_cardinality = CLAMP(atom_getlong(av + 1), 1, CONST_MAX_MODULO);
		}
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

