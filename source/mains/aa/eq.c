/**
 @file
 eq.c
 
 @name 
 bach.==
 
 @realname 
 bach.eq
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Compare two lllls for equality
 
 @description
 Compares two lllls for equality.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 compare, equal, condition

 @seealso
 bach.!=, bach.&gt;, bach.&lt;, bach.&gt;=, bach.&lt;=, bach.filter, bach.sieve 
 
 @owner
 Andrea Agostini
 */

// bach.eq, aka bach.==
// here we learn about inlets
// first, have a look to the definition of a llll, by cmd-clicking here: t_llll
// you probably want to look at the instance creation method first: eq_new()
// bach.eq outputs ints, not lllls. to learn how to deal with outlets, refer to bach.join

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"



// the object structure
// two important things to notice here:
// 1. the first field of the struct is t_llllobj_object, not t_object
// 2. outlets are not explicitly declared in the struct
//    (indeed, they are managed in a slightly higher-level way, and they are stored in the t_llllobj_object structure(
//
// if you want to build an UI, DSP or UI-DSP object instead,
// use respectively the t_llllobj_jbox, t_llllobj_pxobject or t_llllobj_pxjbox structures instead

typedef struct _eq
{
	t_llllobj_object 	n_ob;
	void				*n_proxy;
	long				n_in;
	long				n_matchtype;
	long				n_longout;	
} t_eq;



void eq_assist(t_eq *x, void *b, long m, long a, char *s);
void eq_inletinfo(t_eq *x, void *b, long a, char *t);

t_eq *eq_new(t_symbol *s, short ac, t_atom *av);
void eq_free(t_eq *x);

void eq_bang(t_eq *x);
void eq_int(t_eq *x, t_atom_long v);
void eq_float(t_eq *x, double v);
void eq_anything(t_eq *x, t_symbol *msg, long ac, t_atom *av);
t_max_err eq_notify(t_eq *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

t_class *eq_class;




int T_EXPORT main()
{
	t_class *c;
	
	
	
	
	// always do this at the beginning of the main() function
	// with this, you check for bach to be sufficiently well installed
	// and initialize some global stuff if this is the first bach object instantiated in the current Max session
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	
	
	
	
	// nothing special here
	c = class_new("bach.eq", (method)eq_new, (method)eq_free, (short)sizeof(t_eq), 0L, A_GIMME, 0);

	
	
	
	
	
	// @method llll @digest Store data and perform comparison
	// @description
	// In first inlet: The llll in the right inlet is compared to the llll and the result is output.<br />
	// In second inlet: The llll is stored, to be compared with an llll received in the first inlet.
	class_addmethod(c, (method)eq_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)eq_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)eq_float,		"float",		A_FLOAT,	0);
	
	
	
	
	
	
	
	// Notice that the list method is associated to eq_anything
	// This is quite standard for all the bach objects
	
	class_addmethod(c, (method)eq_anything,		"list",			A_GIMME,	0);
	
	
	
	
	
	
	
	// @method bang @digest Perform the last operation
	// @description Returns the comparison result for the most recently received lllls.
	class_addmethod(c, (method)eq_bang,			"bang",			0);
	
	class_addmethod(c, (method)eq_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)eq_inletinfo,	"inletinfo",	A_CANT,		0);
	
	
	
	
	
	// This is a quite special thing we might get rid of at some point
	// The idea is: if you pass the object an llll in the right inlet,
	// and then an llll in the left inlet, you obtain a result.
	// If you bang the object after this, you will surely obtain the same result,
	// so it's not worth calculating it again (especially since lllls can be rather big);
	// but if you enter a new llll in the right inlet, or modify an attribute,
	// the result may change, so we have to calculate it again.
	
	// Most objects have a mechanism to deal with this transparently,
	// but this mechanism is (not very cleanly) linked to the management of the out attribute.
	// Since bach.eq has no llll outlet, and therefore no out attribute, we need to re-implement it explicitly.
	// So we need to declare and implement a specific notify method.
	
	class_addmethod(c, (method)eq_notify,		"notify",		A_CANT,		0);
	
	
	

	
	CLASS_ATTR_LONG(c, "matchtype",	0,	t_eq, n_matchtype);
	CLASS_ATTR_FILTER_CLIP(c, "matchtype", 0, 1);
	CLASS_ATTR_LABEL(c, "matchtype", 0, "Match Type");
	CLASS_ATTR_STYLE(c, "matchtype", 0, "onoff");
	CLASS_ATTR_BASIC(c, "matchtype", 0);
	// @description
	// When set to 0, numbers with different types but equal value (i.e. 1.5 and 3/2) are considered as equal. 
	// When set to 1, they are considered different.
	
	
	
	
	
	// nothing special here
	
	bach_class_setname("bach.==", "bach.eq");
	class_register(CLASS_BOX, c);
	eq_class = c;
	
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	
	
	// posts a message when compiled in development configuration
	
	dev_post("bach.== compiled %s %s", __DATE__, __TIME__);
	
	
	return 0;
}





// The notify method hinted at above.
// Not very interesting in general, and we will probably get rid of it

t_max_err eq_notify(t_eq *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	if (msg == _sym_attr_modified)
		x->n_ob.l_rebuild = 1;
	return MAX_ERR_NONE;
}






void eq_bang(t_eq *x)
{
	
	
	// The l_rebuild field is non-0 if a new llll has been received in the right inlet,
	// or if an attribute has been modified.
	// If this is the case, then we have to perform the computation again
	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0) { // do we have to rebuild?
		eq_anything(x, _sym_bang, 0, NULL);
	} else {
		
		// rather than the standard outlet_int(), we can use llllobj_outlet_int
		// the third argument is the outlet number, counting from 0 (from left to right)
		llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 0, x->n_longout);
	}
}






// int and float methods are usually implemented like this.
// This reflects the fact that bach objects only implement one data type, the llll,
// and an int will be treated as an llll with one single element

void eq_int(t_eq *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	eq_anything(x, _sym_int, 1, &outatom);
}

void eq_float(t_eq *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	eq_anything(x, _sym_float, 1, &outatom);
}





// This is where most often the bulk of the work gets done

void eq_anything(t_eq *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll1, *ll2;
	long inlet = proxy_getinlet((t_object *) x);
	
	switch (inlet) {
			
			
			
			
		// Is it the left, hot inlet?
			
		case 0:
			
			// If it's not a bang, then we have to parse an llll
			if (msg != _sym_bang) {
				
				
				// Checking two lllls for equality is a non-destructive operation
				// so we don't need to clone the incoming llll, but just retain it
				// so as to assure its validity throughout the course of the operation
				// (otherwise, an llll received in the same thread might invalidate it).
				// As the name suggests, llllobj_parse_retain_and_store() does the following:
				// - parse an llll (which can be in either native or text format),
				// - retain it if valid (which entitles us to perform non-destructive operations upon it, and mandates us to release it when done)
				// - and store it into the store indicated by the last argument
				// all this in thread-safely
				
				ll1 = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
				
				
				
				
				// If the llll was invalid, e.g. because of mismatched parentheses or a bad native number,
				// then ll1 has been set to NULL and the contents of the stores were left unaltered
				
				if (!ll1)
					return;
				
				
			} else {
				
				// If it's a bang, then we want to retrieve the store llll.
				// The 0 at the end means "Retain the stored llll and pass it", rather than "Pass me a clone of the stored llll"
				
				ll1 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
			}
			
			
			
			
			// The second llll for comparison is stored in the first store.
			// We want it to be retained and retrieved for us.
			
			ll2 = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 0);
			
			
			
			
			// This is where the real work is done.
			// Most bach llll-processing objects are essentially wrappers
			// around functions included in the bach API.
			// Unless stated otherwise in the header file documentation,
			// llll functions are always assumed to be non-destructive with respect to all the lllls they receive
			
			if (x->n_matchtype)
				x->n_longout = llll_eq_matchtype(ll1, ll2);
			else
				x->n_longout = llll_eq_ignoretype(ll1, ll2);
			
			
			
			
			// Since we the lllls we compared have been retained, we have to release them now.
			// Calling llll_free() would have been exactly the same.
			
			llll_release(ll1);
			llll_release(ll2);
			
			
			
			// This is to say that until new instructions the just-obtained result must be used
			
			x->n_ob.l_rebuild = 0;
			
			
			
			// And now we can call eq_bang() to output the result
			
			eq_bang(x);
			
			
			
			
			break;
			
		
			
			
		
		// Is it the right, cold inlet?
			
		case 1:
			
			// No computation to do, yet.
			// So, just parse the llll and, if it's valid, store it in the second store (see the 1 at the end).
			// llllobj_parse_and_store() returns a pointer to the llll, but it should never be operated upon
			// as the llll itself is not retained:
			// the only thing we're entitled to do with it is checking if it is NULL.
			// Indeed, if it's not we know that the equality comparison must be done again,
			// and therefore we set l_rebuild to 1.
			
			x->n_ob.l_rebuild = (llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1) != NULL);
			break;
	}
}

void eq_assist(t_eq *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll");
		// @in 0 @type llll @digest llll to be compared
		// @in 1 @type llll @digest llll to be compared
	} else 
		sprintf(s, "int: Comparison Result"); // @out 0 @type int @digest Comparison result (0/1)
}

void eq_inletinfo(t_eq *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void eq_free(t_eq *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x); // you must always call this in your free method, or you will have memory leaks all around
}

t_eq *eq_new(t_symbol *s, short ac, t_atom *av)
{
	t_eq *x = NULL;
	long true_ac;
	t_max_err err = 0;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_eq *) object_alloc_debug(eq_class))) {
		// @arg 0 @name default @optional 1 @type llll @digest Default comparison llll

		
		
		
		// among the other things, this will process the out attribute if present
		// (which should not be the case here, since there are no llll attributes)
		// Anyway, this should always be called before llllobj_obj_setup().
		
		attr_args_process(x, ac, av);
		
		
		
		// llllobj_obj_setup() performs a set of standard actions to set up an object with llll capabilities.
		// You have to pass it:
		// - the newly-created object, cast to a t_llllobj_object (or one of its variants for dsp or ui objects)
		// - the number of stores you want to create (see below)
		// - the types of outlets you want to create
		// A store is a structure usually associated with inlets, capable to hold an llll for further usage.
		// It is a standard way to deal with cold inlets (and the memory of hot inlets as well).
		// Here we have two inlets, both capable of holding the lllls they receive
		// (in this way, we can for example retrieve the most recently received llll for each inlet
		// if a bang is received in the left inlet), so we need two stores.
		// When a store is created, it contains an empty llll.
		// Important: you must never modify an llll contained into a store.
		// If you need to, you should clone it first, and then modify the clone.
		// We also have one outlet, always outputting integers: so, we pass "i" for the outlet types.
		// See the description of llllobj_obj_setup() for more details.
		// Notice, though, that creating the stores doesn't automatically create the associated inlets!
		
		llllobj_obj_setup((t_llllobj_object *) x, 2, "i");

		
		
		
		
		// what we do here is:
		// if there was some av besides the attributes, we treat them as if it was an llll in the right inlet
		// (in a similar fashion as the standard == object does)
		// To do this, we call llllobj_parse_and_store, which accepts a message with its arguments
		// and puts it in the store specified by the last parameter (stores are referenced by numbers from 0 to n-1)
		// This is thread-safe, and automatically releases the previously stored llll, and retains the incoming one if needed.
		// LLLL_OBJ_VANILLA means that this is a non-UI and non-DSP object. Many functions require this parameter.
		
		if (true_ac)
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, NULL, true_ac, av, 1);
		
		
		
		
		
		// In general, all the llll inlets are proxies.
		// For most allocations and deallocations, we use _debug versions of functions,
		// but this is only relevant for debugging the bach core.
		// When linking to the static library without access to the complete bach sources,
		// proxy_new() and proxy_new_debug() are equivalent.
		
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
		
	} else
		
		// Should never happen...
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	
	object_free_debug(x); // as above: using object_free() instead is equivalent if you don't have access to the bach core sources
	
	return NULL;
}
