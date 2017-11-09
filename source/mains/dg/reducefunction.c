/**
 @file
 reducefunction.c
 
 @name 
 bach.reducefunction
 
 @realname 
 bach.reducefunction
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Simplify breakpoint functions
 
 @description
 Simplifies a breakpoint function by pruning negligible points.
 
 @discussion
 
 @category
 bach, bach objects, bach math

 @keywords
 simplify, reduce, breakpoint function, prune, smooth
 
 @seealso
 bach.slot, bach.roll, bach.score, bach.resample
 
 @owner
 Daniele Ghisi
 */


#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include "llllobj.h"
#include "ext_strings.h"
#include "llll_commons_ext.h"



// algorithms
typedef enum _reducefunction_algorithms {
	k_REDUCEFUNCTION_ALGORITHM_CLUSTERING = 0,
	k_REDUCEFUNCTION_ALGORITHM_CLUSTERING_GREEDY = 1,
	k_REDUCEFUNCTION_ALGORITHM_INTEGRAL_DISTANCE = 2,
} e_reducefunction_algorithms;


typedef struct _reducefunction
{
	struct llllobj_object 	n_ob;
	
	char	algorithm;
	char	slopes;
	
	double	thresh;
	char	relative;
	long	max_num_points;
	t_atom	p;
	
} t_reducefunction;


void reducefunction_assist(t_reducefunction *x, void *b, long m, long a, char *s);
void reducefunction_inletinfo(t_reducefunction *x, void *b, long a, char *t);

t_reducefunction *reducefunction_new(t_symbol *s, short ac, t_atom *av);
void reducefunction_free(t_reducefunction *x);

void reducefunction_bang(t_reducefunction *x);
void reducefunction_int(t_reducefunction *x, long num);
void reducefunction_float(t_reducefunction *x, double num);
void reducefunction_anything(t_reducefunction *x, t_symbol *msg, long ac, t_atom *av);
t_max_err reducefunction_setattr_algorithm(t_reducefunction *x, t_object *attr, long ac, t_atom *av);

t_class *reducefunction_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}	
	
	c = class_new("bach.reducefunction", (method)reducefunction_new, (method)reducefunction_free, (short)sizeof(t_reducefunction), 0L, A_GIMME, 0);
	
    
    // @method llll @digest Simplify incoming breakpoint function
    // @description
    // A breakpoint function in the form
    // <b>(<m>x</m> <m>y</m> <m>slope</m>) (<m>x</m> <m>y</m> <m>slope</m>)...</b>
    // is expected and then simplified by pruning negligeable points.
    // Result is output from the outlet in the same form.
    class_addmethod(c, (method)reducefunction_anything,					"anything",				A_GIMME,	0);
	
	class_addmethod(c, (method)reducefunction_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)reducefunction_float,					"float",				A_FLOAT,	0);
	class_addmethod(c, (method)reducefunction_anything,					"list",					A_GIMME,	0);
	class_addmethod(c, (method)reducefunction_bang,						"bang",		0);
	
	class_addmethod(c, (method)reducefunction_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)reducefunction_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	
	CLASS_ATTR_CHAR(c,"algorithm",0, t_reducefunction, algorithm);
	CLASS_ATTR_STYLE_LABEL(c,"algorithm",0,"enumindex","Algorithm");
	CLASS_ATTR_ENUMINDEX(c,"algorithm", 0, "Clustering Greedy Clustering Integral Approximation"); 
	CLASS_ATTR_FILTER_CLIP(c, "algorithm", 0, 2);
	CLASS_ATTR_ACCESSORS(c, "algorithm", (method)NULL, (method)reducefunction_setattr_algorithm);
	CLASS_ATTR_BASIC(c,"algorithm",0);
	// @description Sets the algorithm used to approximate the function. <br />
	// - Clustering: Points are grouped in cluster, and mid-points are pruned. 
	// The <m>thresh</m> attribute in this case sets the maximum average distance of the points with respect to the line obtained
	// with the pruned points, for clustering. The result keeps well isolated the different function regions. <br />
	// - Greedy Clustering: Same as previous one, but the search is performed greedily left-to-right. Result is usually faster
	// than previous case, but of a lower quality. <br />
	// - Integral Approximation: The algorithm approximates the function by starting with the first and last point, and subsequently
	// adding one by one some mid-points, until the integral distance (depending on the <m>p</m> value) is under the <m>thresh</m> threshold. <br />

	CLASS_ATTR_LONG(c, "maxnumpoints", 0, t_reducefunction, max_num_points); 
	CLASS_ATTR_STYLE_LABEL(c,"maxnumpoints",0,"text","Maximum Number Of Output Points");
	// @description (For Integral Approximation <m>algorithm</m> only.) Sets the maximum number of output points. Leave 0 to mean: no limit.
	
	CLASS_ATTR_DOUBLE(c, "thresh", 0, t_reducefunction, thresh); 
	CLASS_ATTR_STYLE_LABEL(c,"thresh",0,"text","Distance Threshold");
	CLASS_ATTR_BASIC(c,"thresh",0);
	// @description Sets the distance threshold for a simplified curve to be acceptable. 
	// For Clustering algorithms, this is the average distance of the points with respect to the segment created by pruning them (default: 0.025).
	// For Integral algorithms, this is the integral distance between the function and the simplified one (also see <m>p</m>).

	CLASS_ATTR_CHAR(c, "relative", 0, t_reducefunction, relative); 
	CLASS_ATTR_STYLE_LABEL(c,"relative",0,"onoff","Relative Threshold");
	CLASS_ATTR_BASIC(c,"relative",0);
	// @description Toggles the ability for the threshold defined by <m>thresh</m> to be a relative threshold (with respect to the function 
	// domain and range). By default it is on. For instance, for Clustering algorithms, setting <m>thresh</m> as 0.1 will mean that an error of 10% of the range is acceptable.
	// For Integral algorithm, this also accounts for the domain: the given <m>thresh</m> is thus an integral threshold per domain unit and per range unit.
	// For instance, if <m>thresh</m> is 0.9, domain spans 3 units and range spans 7 units, it means that an error of 0.9*3*7 is still acceptable.
	
	CLASS_ATTR_ATOM(c, "p", 0, t_reducefunction, p); 
	CLASS_ATTR_STYLE_LABEL(c,"p",0,"text","Norm p value");
	// @description (For Integral Approximation <m>algorithm</m> only.)
	// @copy BACH_DOC_NORM_P_ATTRIBUTE_FOR_FUNCTIONS
	
	CLASS_ATTR_CHAR(c,"slope",0, t_reducefunction, slopes);
	CLASS_ATTR_STYLE_LABEL(c,"slope",0,"enumindex","Slope Handling");
	CLASS_ATTR_ENUMINDEX(c,"slope", 0, "Ignore Approximate"); 
	CLASS_ATTR_FILTER_CLIP(c, "slope", 0, 1);
	
	class_register(CLASS_BOX, c);
	reducefunction_class = c;
	
	dev_post("bach.reducefunction compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err reducefunction_setattr_algorithm(t_reducefunction *x, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		x->algorithm = CLAMP(atom_getlong(av), 0, 2);
		object_attr_setdisabled((t_object *)x, gensym("p"), x->algorithm != k_REDUCEFUNCTION_ALGORITHM_INTEGRAL_DISTANCE);
		object_attr_setdisabled((t_object *)x, gensym("maxnumpoints"), x->algorithm != k_REDUCEFUNCTION_ALGORITHM_INTEGRAL_DISTANCE);
	}
	return MAX_ERR_NONE;
}

void reducefunction_bang(t_reducefunction *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void reducefunction_int(t_reducefunction *x, long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	reducefunction_anything(x, _llllobj_sym_list, 1, argv);
}

void reducefunction_float(t_reducefunction *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	reducefunction_anything(x, _llllobj_sym_list, 1, argv);
}


void reducefunction_anything(t_reducefunction *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll = llllobj_parse_llll((t_object *)x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	double thresh = x->thresh;
	
	if (x->relative) {
		t_llll *temp = llll_clone(ll);
		t_llll *trans = llll_trans(temp, 2);
		
		if (x->algorithm == 2 && trans->l_head && hatom_gettype(&trans->l_head->l_hatom) == H_LLLL) {
			t_hatom *min, *max;
			t_llll *minaddress = llll_get(), *maxaddress = llll_get();
			llll_minmax(hatom_getllll(&trans->l_head->l_hatom), &min, &max, minaddress, maxaddress, 0, 1);
			llll_free(minaddress);
			llll_free(maxaddress);
			double min_d = is_hatom_number(min) ? hatom_getdouble(min) : 0;
			double max_d = is_hatom_number(max) ? hatom_getdouble(max) : min_d + 1;
			thresh *= (max_d - min_d);
		}
		
		if (trans->l_head && trans->l_head->l_next && hatom_gettype(&trans->l_head->l_next->l_hatom) == H_LLLL) {
			t_hatom *min, *max;
			t_llll *minaddress = llll_get(), *maxaddress = llll_get();
			llll_minmax(hatom_getllll(&trans->l_head->l_next->l_hatom), &min, &max, minaddress, maxaddress, 0, 1);
			llll_free(minaddress);
			llll_free(maxaddress);
			double min_d = is_hatom_number(min) ? hatom_getdouble(min) : 0;
			double max_d = is_hatom_number(max) ? hatom_getdouble(max) : min_d + 1;
			thresh *= (max_d - min_d);
		}
		llll_free(trans);
	}
	
	t_llll *out_ll = llll_approximate_breakpoint_function(ll, x->max_num_points, thresh, is_atom_number(&x->p) ? atom_getlong(&x->p) : 0, x->algorithm, x->slopes, 0, (t_object *)x);
	llll_release(ll);
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, out_ll, 0);
	reducefunction_bang(x);
}


void reducefunction_assist(t_reducefunction *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll: Function Breakpoints");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Simplified Function Breakpoints", type);
	}
}

void reducefunction_inletinfo(t_reducefunction *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void reducefunction_free(t_reducefunction *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_reducefunction *reducefunction_new(t_symbol *s, short ac, t_atom *av)
{
	t_reducefunction *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_reducefunction *) object_alloc_debug(reducefunction_class))) {
	
		x->algorithm = 1; // default algorithm is greedy
		x->max_num_points = 0;
		x->thresh = 0.025;
		x->relative = true;
		x->slopes = 1;
		atom_setlong(&(x->p), 1);
		
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "4");

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

