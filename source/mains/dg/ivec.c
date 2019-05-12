/**
	@file
	ivec.c
	
	@name 
	bach.ivec
	
	@realname 
	bach.ivec

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Compute the interval vector of a pitch-class set
	
	@description
	Computes the interval vector of a pitch class-set, i.e. the vector telling
	how many intervals of each kind show up in the set. bach.ivec can also perform multi-interval
	analysis, outputting the multi-interval vector (also known as k-deck). 
	
	@discussion
	The interval vector of a pitch-class set is the vector having as its i-th entry the 
	number of intervals of width i which appear in the given pitch class set.
	The interval vector is output with entries from 1 to ceil(modulo/2), since 
	the remaining entries are trivial by inversion, and the 1st entry will 
	just be the cardinality. <br />
	The vector can alternatively be seen as having in the i-th entry the number of copies
	of the set {0 i} which one can found in the original set. For instance, for the set 
	(0 1 2 4), and modulo = 12, the first entry is the number of semitones, which is two, 
	since we have two copies of {0, 1}, namely {0, 1} itself and {1, 2}. <br />
	Also see http://en.wikipedia.org/wiki/Interval_vector. <br />
	For a general k-interval analisi, the multi interval vector has as its i-th entry the number of
	copies of the i-th prime form of cardinality k (ordered with respect to a given ordering). <br />
	The concept of copies depends on the concept chosen transformation group. <br /> <br />
	@copy BACH_DOC_SETTHEORY_GROUPS
	@copy BACH_DOC_SETTHEORY_MODULO
	@copy BACH_DOC_SETTHEORY_PC_AND_PCSET
	
	@category
	bach, bach objects, bach set theory

	@keywords
	interval, vector, compute, calculate, pitch-class, set, interval vector, k-deck

	@seealso
	bach.ifunc, bach.zsearch, bach.circle, bach.primeform, bach.pcsetinfo
	
	@owner
	Daniele Ghisi
*/


#include "llll_settheory.h" 
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include "ext_critical.h"
#include <stdio.h>
#include <locale.h>

typedef struct _ivec
{
	struct llllobj_object 	n_ob;

	long				modulo;
	char				mode;
	char				group;

	char				count_periodic_subsets_once;
	
	char				rebuild_primeforms_list;
	t_llll				*pflist; // list of prime form
	
	long				cardinality;
	
	void				*n_proxy[2];
	long				n_in;

	t_systhread_mutex		c_mutex;

} t_ivec;


void ivec_assist(t_ivec *x, void *b, long m, long a, char *s);
void ivec_inletinfo(t_ivec *x, void *b, long a, char *t);

t_ivec *ivec_new(t_symbol *s, short ac, t_atom *av);
void ivec_free(t_ivec *x);

void ivec_bang(t_ivec *x);
void ivec_int(t_ivec *x, t_atom_long num);
void ivec_float(t_ivec *x, double num);
void ivec_anything(t_ivec *x, t_symbol *msg, long ac, t_atom *av);

// setter
t_max_err ivec_setattr_group(t_ivec *x, t_object *attr, long ac, t_atom *av);
t_max_err ivec_setattr_mode(t_ivec *x, t_object *attr, long ac, t_atom *av);
t_max_err ivec_setattr_subsetscardinality(t_ivec *x, t_object *attr, long ac, t_atom *av);

t_class *ivec_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}

	c = class_new("bach.ivec", (method)ivec_new, (method)ivec_free, (short)sizeof(t_ivec), 0L, A_GIMME, 0);
	
	// @method llll @digest Compute interval vector of pitch-class set 
	// @description In the first inlet, a pitch-class set, in the form of a plain list, will trigger the output of its interval vector. 	
	class_addmethod(c, (method)ivec_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)ivec_anything,					"list",					A_GIMME,	0);
	
	// @method int @digest Set modulo 
	// @description An integer in the right inlet will set the modulo. <br />
	// @copy BACH_DOC_SETTHEORY_MODULO
	class_addmethod(c, (method)ivec_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)ivec_float,						"float",				A_FLOAT,	0);

	// @method bang @digest Perform the last interval vector computation
	// @description Perform the interval vector computation on the most recently received input data.
	class_addmethod(c, (method)ivec_bang,						"bang",		0);
	
	class_addmethod(c, (method)ivec_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)ivec_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	
	CLASS_ATTR_CHAR(c, "mode", 0, t_ivec, mode); 
	CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
	CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Lexicographic Compactness First"); 
	CLASS_ATTR_SAVE(c,"mode",0);
	CLASS_ATTR_ACCESSORS(c, "mode", (method)NULL, (method)ivec_setattr_mode);
	CLASS_ATTR_BASIC(c,"mode",0);
	//	@description Criterion according to which the prime forms are chosen. <br />
	//	@copy BACH_DOC_SETTHEORY_PRIMEFORMORDERINGCRITERION

	CLASS_ATTR_LONG(c,"modulo",0, t_ivec, modulo);
	CLASS_ATTR_STYLE_LABEL(c,"modulo",0,"text","Modulo");
	CLASS_ATTR_FILTER_MIN(c, "modulo", 1);
	CLASS_ATTR_BASIC(c,"modulo",0);
	//	@description The modulo of the diagram. <br />
	//  @copy BACH_DOC_SETTHEORY_MODULO
	
	CLASS_ATTR_CHAR(c, "group", 0, t_ivec, group); 
	CLASS_ATTR_STYLE_LABEL(c,"group",0,"enumindex","Group");
	CLASS_ATTR_ENUMINDEX(c,"group", 0, "Transp Transp/Inv"); 
	CLASS_ATTR_ACCESSORS(c, "group", (method)NULL, (method)ivec_setattr_group);
	CLASS_ATTR_BASIC(c,"group",0);
	//	@description The group according to which we consider the prime forms. <br />
	//  @copy BACH_DOC_SETTHEORY_GROUPS

	CLASS_ATTR_CHAR(c, "periodiconce", 0, t_ivec, count_periodic_subsets_once); 
	CLASS_ATTR_STYLE_LABEL(c,"periodiconce",0,"onoff","Count Periodic Subsets Once");
	//	@description Some particular periodic subsets might be counted more than once
	//  by the algorithm. For instance: in (0 1 6), the set {0, 6} might be counted both as {0, 6} and as {6, 12}.
	//	If you don't want this, just set this attribute.
	//	Usually one does not want to count twice this occurrence (and the other occurrences 
	//  of periodic sets, if cardinality > 2), thus by default the attribute is set.
	
	
	CLASS_ATTR_LONG(c, "subsetscardinality", 0, t_ivec, cardinality); 
	CLASS_ATTR_STYLE_LABEL(c,"subsetscardinality",0,"text","Subsets Cardinality");
	CLASS_ATTR_FILTER_MIN(c, "subsetscardinality",1);
	CLASS_ATTR_ACCESSORS(c, "subsetscardinality", (method)NULL, (method)ivec_setattr_subsetscardinality);
	//  @description Cardinality of the test subsets. In general the (multi-)interval vector counts the number
	//  of copies of the prime form of a certain cardinality which one can find in the original set:
	//  for instance the standard interval vector is a 2-vector, i.e. counts how many copies of sets like
	//  {0, 1} or {0, 4} are contained in the original sets (no wonder this numbers are exactly the number of
	//  semitones or major third one can find among the notes of the set). But this is true for any
	//  cardinality: we might ask which is the trichordal content of a vector, thus testing how many copies
	//  of sets like {0, 1, 2} or {0, 2, 5} are contained in the set. This number is the cardinality
	//  of this family of test sets. This is by default 2 (yielding the interval vector).
	//	If you want a k-vector (multi-interval analysis) change this number to k.

	class_register(CLASS_BOX, c);
	ivec_class = c;
	
	dev_post("bach.ivec compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err ivec_setattr_group(t_ivec *x, t_object *attr, long ac, t_atom *av){
	if (ac && av)
		x->group = atom_getlong(av);
	x->group = CLAMP(x->group, 0, 1);
	x->rebuild_primeforms_list = true;
	return MAX_ERR_NONE;
}

t_max_err ivec_setattr_mode(t_ivec *x, t_object *attr, long ac, t_atom *av){
	if (ac && av)
		x->mode = atom_getlong(av);
	x->mode = CLAMP(x->mode, 0, 1);
	x->rebuild_primeforms_list = true;
	return MAX_ERR_NONE;
}

t_max_err ivec_setattr_subsetscardinality(t_ivec *x, t_object *attr, long ac, t_atom *av){
	if (ac && av)
		x->cardinality = atom_getlong(av);
	x->cardinality = CLAMP(x->cardinality, 1, CONST_MAX_MODULO);
	x->rebuild_primeforms_list = true;
	return MAX_ERR_NONE;
}

void ivec_bang(t_ivec *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void ivec_int(t_ivec *x, t_atom_long num)
{
	t_atom argv[1]; 
	atom_setlong(argv, num);
	ivec_anything(x, _llllobj_sym_list, 1, argv);
}

void ivec_float(t_ivec *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	ivec_anything(x, _llllobj_sym_list, 1, argv);
}

void ivec_anything(t_ivec *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	t_llll *inlist;
	t_llll *ivec = NULL, *this_pflist = NULL;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	if (inlet == 1 && ac) {
		long this_modulo = atom_getlong(av); 
		if (x->modulo != this_modulo) {
			if (this_modulo) 
				x->modulo = labs(this_modulo);
			x->rebuild_primeforms_list = true;
		}
	}
	
	// do calculations
	if (inlet == 0) {
		inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		
		if (inlist) {
			
			systhread_mutex_lock(x->c_mutex);
			if (x->rebuild_primeforms_list) {
				if (x->pflist) 
					llll_free(x->pflist);
				x->pflist = get_all_prime_forms(x->modulo, x->cardinality, (e_primeform_modes)x->mode, (e_settheory_groups)x->group);
				this_pflist = llll_clone(x->pflist);
				llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, this_pflist, 1);
			}
			ivec = pcset_mvector(inlist, x->pflist, x->modulo, (e_settheory_groups)x->group, x->count_periodic_subsets_once);
			systhread_mutex_unlock(x->c_mutex);
		}
		
		if (ivec)
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ivec, 0);
		else
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);

		llll_free(inlist);
		x->n_ob.l_rebuild = 0;
		ivec_bang(x);
	}
}



void ivec_assist(t_ivec *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) // @in 0 @type llll @digest The pitch-class set
			sprintf(s, "llll: Pitch Class Set");
		else // @in 1 @type int @digest The modulo
			sprintf(s, "int: Modulo");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) // @out 0 @type llll @digest The interval vector (or multi-interval vector)
			sprintf(s, "llll (%s): Interval Vector", type);
		else // @out 1 @type llll  @digest The test prime forms
			 //			@description This llll has one test prime form for each entry in the multi-interval vector.
			 //			If the i-th entry of the output multi-interval vector is N, it means
			 //			that the original set has N copies of the i-th output primeform
			 //			(also see <m>subsetscardinality</m> for more information).
			sprintf(s, "llll (%s): Relative Prime Forms", type);
	}
}

void ivec_inletinfo(t_ivec *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void ivec_free(t_ivec *x)
{	
	long i;

	if (x->pflist) 
		llll_free(x->pflist);

	for (i = 1; i < 2; i++)
		object_free_debug(x->n_proxy[i]);

	systhread_mutex_free_debug(x->c_mutex);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_ivec *ivec_new(t_symbol *s, short ac, t_atom *av)
{
	t_ivec *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_ivec *) object_alloc_debug(ivec_class))) {
	
		long true_ac = attr_args_offset(ac, av);
		
		x->group = k_GROUP_TI;
		x->mode = k_PRIMEFORM_MODE_LEXICOGRAPHIC;
		x->modulo = 12;
		x->cardinality = 2;
		x->count_periodic_subsets_once = true;
		x->rebuild_primeforms_list = true;
		x->pflist = NULL;
		
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
		// mutex
		systhread_mutex_new_debug(&x->c_mutex, 0);

		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "44");

		if (true_ac > 0) {
			// @arg 0 @name modulo @optional 1 @type int @digest Modulo  
			// @description @copy BACH_DOC_SETTHEORY_MODULO
			// @arg 1 @name subsetscardinality @optional 1 @type int @digest Subsets Cardinality  
			// @description Cardinality of the test subsets. See the <m>subsetscardinality</m> attribute.
			x->modulo = CLAMP(atom_getlong(av), 1, CONST_MAX_MODULO);
			if (true_ac > 1)
				x->cardinality = CLAMP(atom_getlong(av + 1), 1, CONST_MAX_MODULO);
		}
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

