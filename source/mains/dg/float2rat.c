/**
	@file
	float2rat.c
	
	@name 
	bach.float2rat
	
	@realname 
	bach.float2rat

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Approximate a floating point number with a rational number
	
	@description
	Approximates a floating point number with a rational number, within
	a given error threshold and with a given maximum denominator.
	
	@discussion
	The object supports multiple algorithms: have a look at the <m>algorithm</m> attribute
	to have an insight on them all.
	
	@category
	bach, bach objects, bach math

	@keywords
	convert, floating point, rational, number, approximate, threshold, denominator, error

	@seealso
	bach.expr, bach.ratnum, bach.quantize
	
	@owner
	Daniele Ghisi
*/


#include "bach.h"
#include "llllobj.h"
#include "llll_commons_ext.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 

typedef struct _float2rat
{
	struct llllobj_object 	n_ob;

	double					tolerance;					///< Maximum error to be allowed
	char					tolerance_is_ratio;			///< Flag telling if the tolerance is a ratio, to be multiplied to each 1/den in order to get the real tolerance
														///  This makes the tolerance-dealing algorithm adaptive
	long					max_den;					///< Maximum denominator to be allowed
	char					direction;					///< The rounding direction
	char					algorithm;					///< Algorithm type (see attributes)

	// used for attributes, which can also have the "none" symbol
	t_atom					tolerance_as_atom;
	t_atom					max_den_as_atom;
} t_float2rat;


/** Algorithms to handle float2rat approximations
	@ingroup	rationals
 */
typedef enum _float2rat_algorithms
{
	k_FLOAT2RAT_ALGORITHM_FIXED_DEN = 0,			///< Calculate approximation with a fixed denominator
	k_FLOAT2RAT_ALGORITHM_WITHIN_TOLERANCE = 1,		///< Calculate approximation with increasing denominators, until the correct tolerance is reached
	k_FLOAT2RAT_ALGORITHM_BEST_MATCH = 2,			///< Calculate approximation with increasing denominators, up to the inserted maxden, and the solution
													///	 with the best tolerance is output, provided that such tolerance lies within the correct tolerance threshold
	k_FLOAT2RAT_ALGORITHM_SMART_PERMANENCE = 3,		///< Smart permanence algorithm (see "algorithm" attribute)
} e_float2rat_algorithms;

/** Rounding directions for float2rat approximations
	@ingroup	rationals
 */
typedef enum _float2rat_round_direction
{
	k_FLOAT2RAT_ROUND_TO_NEAREST = 0,	///< Round to nearest integer
	k_FLOAT2RAT_ROUND_UP = 1,			///< Round towards +inf
	k_FLOAT2RAT_ROUND_DOWN = 2,			///< Round towards -inf
} e_float2rat_round_direction;



void float2rat_assist(t_float2rat *x, void *b, long m, long a, char *s);
void float2rat_inletinfo(t_float2rat *x, void *b, long a, char *t);

t_float2rat *float2rat_new(t_symbol *s, short ac, t_atom *av);
void float2rat_free(t_float2rat *x);

void float2rat_bang(t_float2rat *x);
void float2rat_int(t_float2rat *x, t_atom_long num);
void float2rat_float(t_float2rat *x, double num);
void float2rat_anything(t_float2rat *x, t_symbol *msg, long ac, t_atom *av);

t_max_err float2rat_setattr_algorithm(t_float2rat *x, t_object *attr, long ac, t_atom *av);

t_class *float2rat_class;


t_max_err float2rat_setattr_algorithm(t_float2rat *x, t_object *attr, long ac, t_atom *av){
	
	if (ac && av) {
		x->algorithm = atom_getlong(av);
		object_attr_setdisabled((t_object *)x, gensym("tolerance"), x->algorithm != k_FLOAT2RAT_ALGORITHM_WITHIN_TOLERANCE && x->algorithm != k_FLOAT2RAT_ALGORITHM_SMART_PERMANENCE);
		object_attr_setdisabled((t_object *)x, gensym("adaptive"), x->algorithm != k_FLOAT2RAT_ALGORITHM_WITHIN_TOLERANCE && x->algorithm != k_FLOAT2RAT_ALGORITHM_SMART_PERMANENCE);
	}
	return MAX_ERR_NONE;
}	


int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();

	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.float2rat", (method)float2rat_new, (method)float2rat_free, (short)sizeof(t_float2rat), 0L, A_GIMME, 0);
	
	// @method llll @digest Convert floating point numbers to rationals, output result
	// @description The object converts any floating point number of the incoming <m>llll</m> into a ragional
	// number, with the current preferences determined by the attributes. The result is then output
	class_addmethod(c, (method)float2rat_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)float2rat_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)float2rat_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)float2rat_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Output result
	// @description Output the result calculated on the most recently received input llll.
	class_addmethod(c, (method)float2rat_bang,						"bang",		0);
	
	class_addmethod(c, (method)float2rat_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)float2rat_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_ATOM(c, "tolerance", 0, t_float2rat, tolerance_as_atom); 
	CLASS_ATTR_STYLE_LABEL(c,"tolerance",0,"text","Error Tolerance");
	CLASS_ATTR_BASIC(c,"tolerance",0);
	// @description Sets the maximum allowed error between the approximated values and the original ones.

	CLASS_ATTR_CHAR(c, "adaptive", 0, t_float2rat, tolerance_is_ratio); 
	CLASS_ATTR_STYLE_LABEL(c,"adaptive",0,"onoff","Adaptive Tolerance");
	CLASS_ATTR_BASIC(c,"adaptive",0);
	// @description Toggles the ability for the tolerance to be adaptive.
	// If this flag is on, the value set in the <m>tolerance</m> attribute will be divided by the denominator
	// of the candidate approximation. For instance, if <m>tolerance</m> is 0.01 and the candidate is
	// 7/8, the actual tolerance will be 0.01/8 = 0.00125.

	CLASS_ATTR_ATOM(c, "maxden", 0, t_float2rat, max_den_as_atom); 
	CLASS_ATTR_STYLE_LABEL(c,"maxden",0,"text","Maximum Denominator");
	CLASS_ATTR_BASIC(c,"maxden",0);
	// @description Sets the maximum allowed denominator for the rational approximations.

	CLASS_ATTR_CHAR(c, "direction", 0, t_float2rat, direction); 
	CLASS_ATTR_STYLE_LABEL(c,"direction",0,"enumindex","Rounding Direction");
	CLASS_ATTR_ENUMINDEX(c,"direction", 0, "Round To Nearest Round Up Round Down");
	// @description Sets the rounding direction for the approximations: <br />
	// 0 (default): round to nearest; <br />
	// 1: round up; <br />
	// 2: round down.

	CLASS_ATTR_CHAR(c, "algorithm", 0, t_float2rat, algorithm); 
	CLASS_ATTR_STYLE_LABEL(c,"algorithm",0,"enumindex","Algorithm");
	CLASS_ATTR_ENUMINDEX(c,"algorithm", 0, "Fixed Denominator Within Tolerance Best Match Smart Permanence");
	CLASS_ATTR_BASIC(c,"algorithm",0);
	CLASS_ATTR_ACCESSORS(c, "algorithm", (method)NULL, (method)float2rat_setattr_algorithm);
	// @description Sets the algorithm for the approximation: <br />
	// - Fixed Denominator: The <m>maxden</m> attribute is used as a fixed denominator, and the 
	// approximated rational will have such denominator (up to rational reduction). This algorithm
	// is the least precise, yet by far the fastest, and should be used when extremely fast conversion is required. <br />
	// - Within Tolerance: All the possibilities up to <m>maxden</m> are considered, but as soon as a solution whose error
	// is less than the <m>tolerance</m> is found, it is output, and the algorithm stops.
	// - Smart Tolerance: As the previous one, but the tolerance inserted is a ratio of the considered nominal fraction.
	// For instance, if approximating with a 4 denominator, with tolerance equal to 0.2, then the actual tolerance will be
	// 0.2 * 1/4 = 0.05, and so on. This algorithm is thus adaptive: the tolerance depends on the considered approximation.
	// - Best Match: All the possibilities up to <m>maxden</m> are considered, having the correct <m>tolerance</m>, and
	// the one with the lowest error is output.
	// - Smart Permanence: All the possibilities up to <m>maxden</m> are considered, having the correct <m>tolerance</m>, and 
	// the output one is not in general the one with the lowest error, but the one which "stays the most" in the sequence
	// of converging fractions. More specifically, a sequence of converging fraction \f$r_i\f$ with increasing denominators is 
	// produced for any incoming floating point number, and the permanence \f$p_i\f$ of the fraction \f$r_i\f$ is given by 
	// \f$p_i = den(r_{i+1}) - den(r_i)\f$, where "den" denotes the denominator of the fraction in lowest terms.
	// This somehow tells "how preciser" should we get to increase the precision of a given approximation. The idea is that
	// the higher this permanence is, the most "natural" the approximation would be. We give to each approximation \f$r_i\f$
	// a weight \f$w_i = log(p_i)/log(den(r_i))\f$, and we output the solution having the highest weight.
	
	class_register(CLASS_BOX, c);
	float2rat_class = c;
	
	dev_post("bach.float2rat compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void float2rat_bang(t_float2rat *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void float2rat_int(t_float2rat *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	float2rat_anything(x, _llllobj_sym_list, 1, argv);
}

void float2rat_float(t_float2rat *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	float2rat_anything(x, _llllobj_sym_list, 1, argv);
}


long approx_single_num_fn(void *data, t_hatom *a, const t_llll *address){
	t_float2rat *x = (t_float2rat *) ((void **)data)[0];
	t_llll *errors = (t_llll *) ((void **)data)[1];

	if (hatom_gettype(a) == H_DOUBLE){
		double num = hatom_getdouble(a);
		double this_error = 1.;
		char found = true;
		t_rational approx_res = long2rat(0);
		char direction = (x->direction == k_FLOAT2RAT_ROUND_DOWN ? -1 : (x->direction == k_FLOAT2RAT_ROUND_UP ? 1 : 0));

		switch (x->algorithm) {
			case k_FLOAT2RAT_ALGORITHM_FIXED_DEN:
				approx_res = approx_double_with_rat_fixed_den(num, x->max_den, direction, &this_error);
				break;
			case k_FLOAT2RAT_ALGORITHM_WITHIN_TOLERANCE:
				approx_res = approx_double_with_rat_up_to_tolerance(num, x->tolerance, x->max_den, direction, x->tolerance_is_ratio, &this_error, &found);
				break;
			case k_FLOAT2RAT_ALGORITHM_BEST_MATCH:
				approx_res = approx_double_with_rat_best_match(num, x->max_den, direction, &this_error);
				break;
			case k_FLOAT2RAT_ALGORITHM_SMART_PERMANENCE:
				approx_res = approx_double_with_rat_smart_permanence(num, x->tolerance, x->max_den, direction, x->tolerance_is_ratio, &this_error, &found);
				break;
			default:
				break;
		}
		
		if (!found)
			object_warn((t_object *)x, "Warning: no approximation found with given tolerance.");

		hatom_setrational(a, approx_res);
		llll_appenddouble(errors, this_error, 0, WHITENULL_llll);
	} else {
		llll_appenddouble(errors, 0., 0, WHITENULL_llll);
	}
	return 0;
}


void float2rat_anything(t_float2rat *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	// parsing maxden_as_atom and tolerance_as_atom into maxden and tolerance
	x->max_den = is_atom_number(&x->max_den_as_atom) ? labs(atom_getlong(&x->max_den_as_atom)) : 0; // 0 means : no max den
	x->tolerance = is_atom_number(&x->tolerance_as_atom) ? fabs(atom_getfloat(&x->tolerance_as_atom)) : 1.; // 1. essentially means : no threshold
	
	if (x->max_den == 0 && x->algorithm != k_FLOAT2RAT_ALGORITHM_WITHIN_TOLERANCE) {
		object_error((t_object *)x, "Cannot convert floating point number to rational with this algorithm without setting a maximum denominator");
		return;
	}
	
	if (x->tolerance > 0)
		x->tolerance = MAX(x->tolerance, CONST_EPSILON_FOR_DOUBLE2RAT_APPROXIMATION);
	
	ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	if (ll) {
		t_llll *errors = llll_get();
		void *data[2];
		data[0] = x;
		data[1] = errors;
		
		llll_funall(ll, (fun_fn) approx_single_num_fn, data, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
		llll_reshape(errors, ll, NULL);

		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, errors, 1);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
	}
	
	
	x->n_ob.l_rebuild = 0;
	float2rat_bang(x);
}


void float2rat_assist(t_float2rat *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The incoming llll of numbers
		sprintf(s, "llll");
	} else {
		char *type = NULL; 
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) // @out 0 @type llll @digest Approximated llll
			// @description The llll with the floating point numbers having been approximated to rationals.
			sprintf(s, "llll (%s): Approximated llll", type);
		else // @out 1 @type llll @digest Errors
			// @description The llll containing errors of approximated elements with respect to the original elements
			sprintf(s, "llll (%s): Errors", type);
	}
}

void float2rat_inletinfo(t_float2rat *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void float2rat_free(t_float2rat *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_float2rat *float2rat_new(t_symbol *s, short ac, t_atom *av)
{
	t_float2rat *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_float2rat *) object_alloc_debug(float2rat_class))) {
	
		atom_setlong(&x->max_den_as_atom, 1000);
		atom_setfloat(&x->tolerance_as_atom, 0.01);
		x->algorithm = k_FLOAT2RAT_ALGORITHM_WITHIN_TOLERANCE;
		x->direction = k_FLOAT2RAT_ROUND_TO_NEAREST;
		x->tolerance = 0.01;
		x->tolerance_is_ratio = true;
		x->max_den = 1000;

		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "44");

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

