/**
 @file
 contains.c
 
 @name 
 bach.contains
 
 @realname 
 bach.contains
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Contents of an llll
 
 @description
 Returns the types of the data contained in an llll, optionally within a specified depth range.

 @category
 bach, bach objects, bach llll
 
 @keywords
 contain, data, element, content

 @seealso
 bach.is, bach.bitdecode, bach.filter
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _contains
{
	struct llllobj_object 	n_ob;
	long				n_mindepth;
	long				n_maxdepth;
	long				n_longout;	
} t_contains;


void contains_assist(t_contains *x, void *b, long m, long a, char *s);
void contains_inletinfo(t_contains *x, void *b, long a, char *t);

t_contains *contains_new(t_symbol *s, short ac, t_atom *av);
void contains_free(t_contains *x);

void contains_bang(t_contains *x);
void contains_int(t_contains *x, t_atom_long v);
void contains_float(t_contains *x, double v);
void contains_anything(t_contains *x, t_symbol *msg, long ac, t_atom *av);
t_max_err contains_notify(t_contains *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

DEFINE_STANDARD_MINDEPTH_SETTER(t_contains)

t_class *contains_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.contains", (method)contains_new, (method)contains_free, (short)sizeof(t_contains), 0L, A_GIMME, 0);
	
	// @method llll @digest Return the data types in the llll
	// @description
	// Returns the types of the data contained in an llll, optionally within a specified depth range.
	// The data types are returned as a bitfield from the first outlet and as symbols from the second outlet. 
	// The bitfield representation is a bitwise or of the following values:
	// <b>1</b> = null, <b>2</b> = integer, <b>4</b> = rational, <b>8</b> = float, <b>16</b> = symbol, <b>32</b> = llll.
	// Only values corresponding to data types that are contained in the input llll concour to the representation.
	// The symbolic representation is an llll composed by a combination of the following symbols:
	// <b>i</b> = integer, <b>r</b> = rational, <b>f</b> = float, <b>s</b> = symbol, <b>l</b> = llll, <b>null</b>.
	// Only symbols corresponding to data types that are contained in the input llll are present in the output llll. 
	class_addmethod(c, (method)contains_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)contains_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)contains_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)contains_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Return the data types
	// @description Returns the data types of the most recently received llll.
	class_addmethod(c, (method)contains_bang,		"bang",			0);
	
	class_addmethod(c, (method)contains_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)contains_inletinfo,	"inletinfo",	A_CANT,		0);
	class_addmethod(c, (method)contains_notify,		"notify",		A_CANT,		0);

	
	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_contains, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	// @description
	// <m>maxdepth</m> sets the maximum depth level at which the evaluation of the contents of the llll must be performed.
	// If negative, the depth level is counted from the innermost level of each branch of the tree.
	// A value of 0 is treated as a special case where the whole input llll is evaluated as a whole,
	// thus always returning an llll value.
	// This can be useful in special situations where a series of iterations are triggered at different maximum depths,
	// in order to emulate recursive behaviors.
	// Defaults to -1, i.e. there is no limitation (stop at the innermost level).
	CLASS_ATTR_LONG(c, "mindepth",	0,	t_contains, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");
	CLASS_ATTR_BASIC(c, "mindepth", 0);
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_contains);
	// @description @copy BACH_DOC_MINDEPTH

	class_register(CLASS_BOX, c);
	contains_class = c;
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	dev_post("bach.contains compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err contains_notify(t_contains *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	if (msg == _sym_attr_modified)
		x->n_ob.l_rebuild = 1;
	return MAX_ERR_NONE;
}

void contains_bang(t_contains *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		contains_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
		llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 0, x->n_longout);
	}
}

void contains_int(t_contains *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	contains_anything(x, _sym_int, 1, &outatom);
}

void contains_float(t_contains *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	contains_anything(x, _sym_float, 1, &outatom);
}

void contains_anything(t_contains *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *ll, *types_llll;
	long types;
	if (msg != _sym_bang) {
		ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		if (!ll)
			return;
	} 
	if (x->n_maxdepth == 0) {
		x->n_longout = H_LLLL;
		types_llll = llll_get();
		llll_appendsym(types_llll, _llllobj_sym_l, 0, WHITENULL_llll);
	} else {
		ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);

		types_llll = llll_get();
		x->n_longout = types = llll_contains(ll, x->n_mindepth, x->n_maxdepth);
		llll_release(ll);
		
		if (types & H_NULL)		llll_appendsym(types_llll, _llllobj_sym_n, 0, WHITENULL_llll);
		if (types & H_LONG)		llll_appendsym(types_llll, _llllobj_sym_i, 0, WHITENULL_llll);
		if (types & H_RAT)		llll_appendsym(types_llll, _llllobj_sym_r, 0, WHITENULL_llll);
		if (types & H_DOUBLE)	llll_appendsym(types_llll, _llllobj_sym_f, 0, WHITENULL_llll);
        if (types & H_PITCH)	llll_appendsym(types_llll, _llllobj_sym_p, 0, WHITENULL_llll);
		if (types & H_SYM)		llll_appendsym(types_llll, _llllobj_sym_s, 0, WHITENULL_llll);
		if (types & H_LLLL)		llll_appendsym(types_llll, _llllobj_sym_l, 0, WHITENULL_llll);
		if (types & H_OBJ)		llll_appendsym(types_llll, _llllobj_sym_o, 0, WHITENULL_llll);

	}
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, types_llll, 1);
	x->n_ob.l_rebuild = 0;
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 0, x->n_longout);
}

void contains_assist(t_contains *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest The llll whose contained data types will be reported
	} else {
		switch (a) {
			case 0:	sprintf(s, "int: Contained Types as a Bitfield");			break; 
				// @out 0 @type int @digest The bitfield representation of the contained data types
				// @description The bitfield representation is a bitwise or of the following values:
				// <b>1</b> = null, <b>2</b> = integer, <b>4</b> = rational, <b>8</b> = float, <b>16</b> = symbol, <b>32</b> = llll, <b>256</b> = pitch.
				// Only values corresponding to data types that are contained in the input llll concour to the representation.
			case 1:	sprintf(s, "anything: Contained Types as Symbols");	break; 
				// @out 1 @type anything @digest The symbolic representation of the contained data types
				// @description The symbolic representation is a message composed by a combination of the following symbols:
				// <b>i</b> = integer, <b>r</b> = rational, <b>f</b> = float, <b>s</b> = symbol, <b>l</b> = llll, <b>p</b> = pitch, <b>n</b> = null.
				// Only symbols corresponding to data types that are contained in the input llll are present in the output message. 
		}
	}
}

void contains_inletinfo(t_contains *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void contains_free(t_contains *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_contains *contains_new(t_symbol *s, short ac, t_atom *av)
{
	t_contains *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_contains *) object_alloc_debug(contains_class))) {
		// @arg 0 @name depth @optional 1 @type int @digest Depth
		// @description If only one argument is present, it is considered maxdepth.
		// If two arguments are present, the first is considered mindepth, the second maxdepth.
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4i");
		x->n_ob.l_out[1].b_type = LLLL_O_TEXT;
		x->n_mindepth = 1;
		x->n_maxdepth = -1;
		switch (true_ac) {
			case 0: 
				break;
			case 1:
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av);
				break;
			case 2:
				object_attr_setvalueof(x, gensym("mindepth"), 1, av);
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av + 1);
				break;
			default:
				object_warn((t_object *) x, "Bad number of arguments");
				break;
		}
		attr_args_process(x, ac, av);
		object_attach_byptr_register(x, x, CLASS_BOX);
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}