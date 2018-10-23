/**
 @file
 length.c
 
 @name 
 bach.length
 
 @realname 
 bach.length
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Length of an llll
 
 @description
 Returns the length of an llll. 
 
 @discussion
 The length is computed at the root level only, so e.g. the reported length of <b>[1 2] [3 4]</b> is 2.

 @category
 bach, bach objects, bach llll
 
 @keywords
 length

 @seealso
 bach.is, bach.contains, bach.depth
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h" // You must include this
#include "ext_common.h"
#include "ext_globalsymbol.h"

/*
 
 Some notes on the object structure:
 
 1. You don't directly inherit from t_object, but from llllobj_object instead, which in turns inherits from t_object
 (you have other classes to inherit from for UI and DSP objects)
 
 2. Outlets are not declared in the object structure - in fact, they are inherited
 
 */

typedef struct _length
{
	t_llllobj_object	n_ob;
	long				n_length;
	
} t_length;


void length_assist(t_length *x, void *b, long m, long a, char *s);
void length_inletinfo(t_length *x, void *b, long a, char *t);

t_length *length_new(t_symbol *s, short ac, t_atom *av);
void length_free(t_length *x);

void length_bang(t_length *x);
void length_int(t_length *x, t_atom_long v);
void length_float(t_length *x, double v);
void length_anything(t_length *x, t_symbol *msg, long ac, t_atom *av);

t_class *length_class;

int T_EXPORT main()
{
	t_class *c;
	
	// always do this at the beginning of main()
	// with this, you check for bach to be sufficiently well installed
	// and create some nobox classes and objects in case they're not there yet
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	} // this provides you some defines for useful symbols
	
	c = class_new("bach.length", (method)length_new, (method)length_free, (short)sizeof(t_length), 0L, A_GIMME, 0);
	//llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);
	
	
	// @method llll @digest Return the length of the llll
	// @description
	// Returns the number of elements of the root level of the llll.
	class_addmethod(c, (method)length_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)length_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)length_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)length_anything,		"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description Returns the length of the most recently received llll.
	class_addmethod(c, (method)length_bang,			"bang",			0);
	
	class_addmethod(c, (method)length_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)length_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	length_class = c;
	
	dev_post("bach.length compiled %s %s", __DATE__, __TIME__);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	return 0;
}

void length_bang(t_length *x)
{	
	outlet_int(x->n_ob.l_out[0].b_outlet, x->n_length); // here is as you get the 0-th outlet if you want to access it directly
}

void length_int(t_length *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	length_anything(x, _sym_int, 1, &outatom);
}

void length_float(t_length *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	length_anything(x, _sym_float, 1, &outatom);
}

void length_anything(t_length *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_llll;
	
	// get a llll
	// the flag LLLL_PARSE_RETAIN means that if the input is a text representation, a new llll will be created
	// whereas if the input is a native representation, the corresponding llll will be retained
	// this gives us ownership of the llll in both cases (although not the right to operate destructively upon it)
	// and imposes us to release the llll after having used it
	// for more info, see the definition of e_llllobj_parse_flags
	in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	
	if (!in_llll) // if there was no valid llll, we have done
		return;
	
	x->n_length = in_llll->l_size; // this is how we get the length
	llll_free(in_llll); // free the llll
	
	length_bang(x);
}

void length_assist(t_length *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll whose length will be returned
	} else {
		sprintf(s, "int: Length of Incoming llll"); // @in 0 @type int @digest Length of the incoming llll
	}
}

void length_inletinfo(t_length *x, void *b, long a, char *t)
{
	*t = 1;
}

void length_free(t_length *x)
{
	llllobj_obj_free((t_llllobj_object *) x); // you have to call this!
}


t_length *length_new(t_symbol *s, short ac, t_atom *av)
{
	t_length *x = NULL;
	t_max_err err = 0;
	
	// here we set up our outlets
	// the second argument is the number of the stores (we don't use them in this external)
	// the third argument contains the info for creating the outlets
	// it consists of a string with one character for each outlet, in reverse order 
	// (that is, the leftmost character is the rightmost outlet)
	// allowed types are:
	// b = bang
	// i = int
	// l = list
	// a = anything
	// 4 = llll
	// for each "a" outlet, you have to add a const char* parameter with its message selector (or NULL if none)
	// ex: llllobj_obj_setup((t_llllobj_object *) x, 0, "aa4", NULL, "text");
	
	if ((x = (t_length *) object_alloc_debug(length_class))) {
		long true_ac = attr_args_offset(ac, av);
		if (true_ac > 0)
			object_warn((t_object *) x, "Arguments are ignored");
		llllobj_obj_setup((t_llllobj_object *) x, 0, "i");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE) // if everything went fine
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
