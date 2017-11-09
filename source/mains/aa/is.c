/**
 @file
 is.c
 
 @name 
 bach.is
 
 @realname 
 bach.is
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Type of the incoming data
 
 @description
 Returns the type of the incoming data.
 
 @discussion
 The data type is returned in a symbolic representation from the second outlet and as a numeric one from the first outlet.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 type, is, data

 @seealso
 bach.contains, bach.filter
 
 @owner
 Andrea Agostini
 */
#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _is
{
	struct llllobj_object 	n_ob;
	long					n_longout;
	t_symbol				*n_symout;
} t_is;


void is_assist(t_is *x, void *b, long m, long a, char *s);
void is_inletinfo(t_is *x, void *b, long a, char *t);

t_is *is_new(t_symbol *s, short ac, t_atom *av);
void is_free(t_is *x);

void is_bang(t_is *x);
void is_int(t_is *x, t_atom_long v);
void is_float(t_is *x, double v);
void is_anything(t_is *x, t_symbol *msg, long ac, t_atom *av);

t_class *is_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.is", (method)is_new, (method)is_free, (short)sizeof(t_is), 0L, A_GIMME, 0);
	//llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);
	
	// @method llll @digest Return the type of the incoming data
	// @description
	// Returns the "minimum" type of the incoming data: 
	// that is, if a single-element llll is received, the data type of its element is output.
	class_addmethod(c, (method)is_anything,		"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)is_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)is_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)is_anything,		"list",			A_GIMME,	0);
	
	// @method bang @digest Return the data type
	// @description Returns the data type of the most recently received data.
	class_addmethod(c, (method)is_bang,			"bang",			0);
	
	class_addmethod(c, (method)is_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)is_inletinfo,	"inletinfo",	A_CANT,		0);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	class_register(CLASS_BOX, c);
	is_class = c;
	
	dev_post("bach.is compiled %s %s", __DATE__, __TIME__);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	return 0;
}

void is_bang(t_is *x)
{	
	llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 1, x->n_symout, 0, NULL);
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, 0, x->n_longout);
}

void is_int(t_is *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	is_anything(x, _sym_int, 1, &outatom);
}

void is_float(t_is *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	is_anything(x, _sym_float, 1, &outatom);
}

void is_anything(t_is *x, t_symbol *msg, long ac, t_atom *av)
{	
	long is;
	t_llll *in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!in_llll)
		return;
	if (in_llll->l_size == 0)
		is = H_NULL;
	else if (in_llll->l_size == 1) {
		is = in_llll->l_head->l_hatom.h_type;
	} else
		is = H_LLLL;
	llll_release(in_llll);
	switch (is) {
		case H_NULL:	x->n_symout = _llllobj_sym_n;		break;
		case H_LONG:	x->n_symout = _llllobj_sym_i;		break;
		case H_RAT:		x->n_symout = _llllobj_sym_r;		break;
		case H_DOUBLE:	x->n_symout = _llllobj_sym_f;		break;
		case H_SYM:		x->n_symout = _llllobj_sym_s;		break;
		case H_LLLL:	x->n_symout = _llllobj_sym_l;		break;
		case H_OBJ:		x->n_symout = _llllobj_sym_o;		break;
        case H_PITCH:	x->n_symout = _llllobj_sym_p;		break;
		default:		x->n_symout = _llllobj_sym_unknown;	break;
	}
	x->n_longout = is;
	is_bang(x);
}

void is_assist(t_is *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) 
		sprintf(s, "llll"); // @in 0 @type llll @digest The data whose type will be reported
	else {
		switch (a) {
			case 0:	sprintf(s, "int: Type");	break;
				// @out 0 @type int @digest The numeric representation of the contained data types
				// @description The numeric representation is one of the following values:
				// <b>1</b> = null, <b>2</b> = integer, <b>4</b> = rational, <b>8</b> = float, <b>16</b> = symbol, <b>32</b> = llll, <b>256</b> = pitch.
				
			case 1:	sprintf(s, "symbol: Type");	break;
				// @out 1 @type llll @digest The symbolic representation of the contained data types
				// @description The symbolic representation is one of the following symbols:
				// <b>i</b> = integer, <b>r</b> = rational, <b>f</b> = float, <b>s</b> = symbol, <b>l</b> = llll, <b>p</b> = pitch, <b>n</b> = null.
		}
	}
}

void is_inletinfo(t_is *x, void *b, long a, char *t)
{
	*t = 1;
}

void is_free(t_is *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_is *is_new(t_symbol *s, short ac, t_atom *av)
{
	t_is *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_is *) object_alloc_debug(is_class))) {
		llllobj_obj_setup((t_llllobj_object *) x, 0, "ai", NULL);
		x->n_symout = gensym("");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}