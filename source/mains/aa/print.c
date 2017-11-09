/**
 @file
 print.c
 
 @name 
 bach.print
 
 @realname 
 bach.print
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Print lllls in the Max window
 
 @description
 Displays lllls in the Max window.
 
 @discussion
 The llll is displayed on a single line, in text format.
 If a line in the Max window is double-clicked, the <o>bach.print</o> object that wrote it is highlighted.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 print, Max window, show, display

 @seealso
 bach.post, print
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _print
{
	struct llllobj_object 	n_ob;
	long					n_maxdecimals;
	char					n_error;
	t_symbol				*n_name; // useful for debug!!!
	t_object				*n_print;
} t_print;

void print_assist(t_print *x, void *b, long m, long a, char *s);
void print_inletinfo(t_print *x, void *b, long a, char *t);

t_print *print_new(t_symbol *s, short ac, t_atom *av);
void print_free(t_print *x);

void print_bang(t_print *x);
void print_int(t_print *x, t_atom_long v);
void print_float(t_print *x, double v);
void print_anything(t_print *x, t_symbol *msg, long ac, t_atom *av);

void print_setprintbox(t_print *x, t_symbol *s, long ac, t_atom *av);
void print_setprintpopup(t_print *x, t_symbol *s, long ac, t_atom *av);

t_class *print_class;

int T_EXPORT main()
{
	t_class *c;
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.print", (method)print_new, (method)print_free, (short)sizeof(t_print), 0L, A_GIMME, 0);
	
	// @method llll @digest Print the llll
	// @description The llll is displayed in text format on a single line.
	// If a line in the Max window is double-clicked, the <o>bach.print</o> object that wrote it is highlighted.
	class_addmethod(c, (method)print_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)print_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)print_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)print_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)print_bang,		"bang",			0);
	
	class_addmethod(c, (method)print_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)print_inletinfo,	"inletinfo",	A_CANT,		0);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_CHAR(c, "error",	0,	t_print, n_error);
	CLASS_ATTR_STYLE_LABEL(c, "error", 0, "enumindex", "Error Message");
	CLASS_ATTR_ENUMINDEX(c, "error", 0, "None Error Warning");
	// @description
	// When set to 1, the lllls are printed on a red background, as an error message.
	// When set to 2, the lllls are printed on a yellow background, as a warning message.

	CLASS_ATTR_LONG(c, "maxdecimals",	0,	t_print, n_maxdecimals);
	CLASS_ATTR_LABEL(c, "maxdecimals", 0, "Maximum Decimal Digits");
	CLASS_ATTR_FILTER_MIN(c, "maxdecimals", 0);
	// @description
	// The maximum number of decimal digits to be displayed for floats. The default is 6.
	
	class_register(CLASS_BOX, c);
	print_class = c;
    
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);
	
	dev_post("bach.print compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void print_bang(t_print *x)
{	
	print_anything(x, _sym_bang, 0, NULL);
}

void print_int(t_print *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	print_anything(x, _sym_int, 1, &outatom);
}

void print_float(t_print *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	print_anything(x, _sym_float, 1, &outatom);
}

void print_anything(t_print *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!in_llll)
		return;
	llll_print(in_llll, x->n_print ? x->n_print : (t_object *) x, x->n_error, x->n_maxdecimals, NULL);
	llll_free(in_llll);
}

void print_assist(t_print *x, void *b, long m, long a, char *s)
{
	sprintf(s, "llll"); // @in 0 @type llll @digest llll to print
}

void print_inletinfo(t_print *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void print_free(t_print *x)
{
	if (x->n_print) {
		object_obex_store(x->n_print, gensym("#B"), NULL);
		object_free_debug(x->n_print);
	}
	llllobj_obj_free((t_llllobj_object *) x);
}

t_print *print_new(t_symbol *sym, short ac, t_atom *av)
{
	t_print *x = NULL;
	t_symbol *name = NULL;
	long true_ac;
	t_max_err err = 0;
	char s[256];

	true_ac = attr_args_offset(ac, av);
	if ((x = (t_print *) object_alloc_debug(print_class))) {
		// @arg 0 @name name @optional 1 @type anything @digest Name
		// @description
		// <o>bach.print</o>'s optional argument is the name of the object, to be displayed in the "object" column of the Max window.
		llllobj_obj_setup((t_llllobj_object *) x, 0, "");
		
		if (true_ac) {
			switch (atom_gettype(av)) {
				case A_SYM:
					name = atom_getsym(av);
					break;
				case A_LONG:
					snprintf_zero(s, 256, "%ld", atom_getlong(av));
					name = gensym(s);
					break;
				case A_FLOAT:
					snprintf_zero(s, 256, "%f", atom_getfloat(av));
					name = gensym(s);
					break;	
			}
		}
		if (name) {
			t_atom pav;
			atom_setsym(&pav, name);
			x->n_print = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, 1, &pav);
			if (!x->n_print) {
				x->n_print = (t_object *) newinstance(_sym_print, 0, NULL);
				object_free(x->n_print);
				x->n_print = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, 1, &pav);
			}
			defer_low(x, (method) print_setprintbox, NULL, 0, NULL);
			x->n_name = name;
		}
		x->n_maxdecimals = 6;
		attr_args_process(x, ac, av);
		
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}

void print_setprintbox(t_print *x, t_symbol *s, long ac, t_atom *av)
{
	t_object *printbox; // bach.print's box
	object_obex_lookup(x, gensym("#B"), (t_object **) &printbox);
	object_obex_store(x->n_print, gensym("#B"), printbox);
	defer_low(x, (method) print_setprintpopup, NULL, 0, NULL);
}

void print_setprintpopup(t_print *x, t_symbol *s, long ac, t_atom *av)
{
	object_attr_setlong(x->n_print, gensym("popup"), 1);
}