/**
 @file
 post.c
 
 @name 
 bach.post
 
 @realname 
 bach.post
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Print lllls in the Max window, element by element
 
 @description
 Displays lllls in the Max window, emphasizing their structure.
 
 @discussion
 The llll is displayed one element per line, with each element's depth shown.
 If a line in the Max window is double-clicked, the <o>bach.post</o> object that wrote it is highlighted.
 
 @category
 bach, bach objects, bach llll

 @keywords
 post, print, Max window, show, display

 @seealso
 bach.print, print
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _post
{
	struct llllobj_object 	n_ob;
	long					n_mindepth;
	long					n_maxdepth;	
	long					n_maxdecimals;
	t_object				*n_print;
} t_post;

void post_assist(t_post *x, void *b, long m, long a, char *s);
void post_inletinfo(t_post *x, void *b, long a, char *t);

t_post *post_new(t_symbol *s, short ac, t_atom *av);
void post_free(t_post *x);

void post_bang(t_post *x);
void post_int(t_post *x, t_atom_long v);
void post_float(t_post *x, double v);
void post_anything(t_post *x, t_symbol *msg, long ac, t_atom *av);

void post_setprintbox(t_post *x, t_symbol *s, long ac, t_atom *av);

DEFINE_STANDARD_MINDEPTH_SETTER(t_post)

t_class *post_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.post", (method)post_new, (method)post_free, (short)sizeof(t_post), 0L, A_GIMME, 0);

	
	// @method llll @digest Print the llll
	// @description The llll is displayed one element per line, with each element's depth shown.
	// Sublists are entered or not according to the <m>maxdepth</m> attribute.
	// If a line in the Max window is double-clicked, the <o>bach.post</o> object that wrote it is highlighted. 
	class_addmethod(c, (method)post_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)post_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)post_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)post_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)post_bang,		"bang",			0);
	
	class_addmethod(c, (method)post_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)post_inletinfo,	"inletinfo",	A_CANT,		0);
	
    
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

    
	CLASS_ATTR_LONG(c, "mindepth",	0,	t_post, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");
	CLASS_ATTR_BASIC(c, "mindepth", 0);
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_post);
	// @description
	// The minimum depth of the elements to be printed.
	// Elements less deep than <m>mindepth</m> are skipped.
	// A negative value means that for each branch of the llll the minimum depth is counted from the deepest level of the branch.
	
	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_post, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	// @description
	// <m>maxdepth</m> sets the maximum depth level at which sublists are entered and displayed element by element.
	// Sublists deeper than <m>maxdepth</m> are displayed as single elements, on one line.
	// A negative value means that for each branch of the llll the maximum depth is counted from the deepest level of the branch.
	// A value of 0 is treated as a special case where the input llll is printed as a whole, 
	// as in the <o>bach.print</o> object.
	// Defaults to -1, i.e. there is no limitation (stop at the innermost level).
	
	CLASS_ATTR_LONG(c, "maxdecimals",	0,	t_post, n_maxdecimals);
	CLASS_ATTR_LABEL(c, "maxdecimals", 0, "Maximum Decimal Digits");
	CLASS_ATTR_FILTER_MIN(c, "maxdecimals", 0);
	// @description
	// The maximum number of decimal digits to be displayed for floats. The default is 6.
	
	class_register(CLASS_BOX, c);
	post_class = c;
	
	dev_post("bach.post compiled %s %s", __DATE__, __TIME__);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);

	return 0;
}

void post_bang(t_post *x)
{	
	//object_post(x->n_print, "yeah");
	post_anything(x, _sym_bang, 0, NULL);
}

void post_int(t_post *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	post_anything(x, _sym_int, 1, &outatom);
}

void post_float(t_post *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	post_anything(x, _sym_float, 1, &outatom);
}

void post_anything(t_post *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!in_llll)
		return;
	if (x->n_maxdepth != 0) {
		llll_post(in_llll, x->n_mindepth, x->n_maxdepth, x->n_maxdecimals, 
				  x->n_print ? x->n_print : (t_object *) x, NULL);
	} else {
		llll_print(in_llll, x->n_print ? x->n_print : (t_object *) x, 0, x->n_maxdecimals, NULL);
	}

	llll_free(in_llll);
}

void post_assist(t_post *x, void *b, long m, long a, char *s)
{
	sprintf(s, "llll"); // @in 0 @type llll @digest llll to print
}

void post_inletinfo(t_post *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void post_free(t_post *x)
{
	if (x->n_print) {
		object_obex_store(x->n_print, gensym("#B"), NULL);
		object_free_debug(x->n_print);
	}
	llllobj_obj_free((t_llllobj_object *) x);
}

t_post *post_new(t_symbol *sym, short ac, t_atom *av)
{
	t_post *x = NULL;
	t_symbol *name = NULL;
	long true_ac;
	t_max_err err = 0;
	char s[256];
	
	true_ac = attr_args_offset(ac, av);
	if ((x = (t_post *) object_alloc_debug(post_class))) {
		// @arg 0 @name parameters @optional 1 @type anything @digest Parameters
		// @description
		// If one argument is present, it is considered the name of the object, to be displayed in the "object" column of the Max window.
		// If two arguments are present, they are considered <m>maxdepth</m> and name.
		// If three arguments are present, they are considered <m>mindepth</m>, <m>maxdepth</m> and name.
		llllobj_obj_setup((t_llllobj_object *) x, 0, "");
		x->n_mindepth = 1;
		x->n_maxdepth = -1;
		switch (true_ac) {
			case 0: 
				break;
			case 1:
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
				break;
			case 2:
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av);
				switch (atom_gettype(av + 1)) {
					case A_SYM:
						name = atom_getsym(av + 1);
						break;
					case A_LONG:
						snprintf_zero(s, 256, "%ld", atom_getlong(av + 1));
						name = gensym(s);
						break;
					case A_FLOAT:
						snprintf_zero(s, 256, "%f", atom_getfloat(av + 1));
						name = gensym(s);
						break;	
				}
				break;
			case 3:
				object_attr_setvalueof(x, gensym("mindepth"), 1, av);
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av + 1);
				switch (atom_gettype(av + 2)) {
					case A_SYM:
						name = atom_getsym(av + 2);
						break;
					case A_LONG:
						snprintf_zero(s, 256, "%ld", atom_getlong(av + 2));
						name = gensym(s);
						break;
					case A_FLOAT:
						snprintf_zero(s, 256, "%f", atom_getfloat(av + 2));
						name = gensym(s);
						break;	
				}
				break;
			default:
				object_warn((t_object *) x, "Bad number of arguments");
				break;
		}
		if (name) {
			t_atom pav;
			atom_setsym(&pav, name);
			x->n_print = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, 1, &pav);
			if (!x->n_print) {
				x->n_print = (t_object *) newinstance(_sym_print, 0, NULL);
				object_free_debug(x->n_print);
				x->n_print = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, 1, &pav);
			}
			defer_low(x, (method) post_setprintbox, NULL, 0, NULL);
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

void post_setprintbox(t_post *x, t_symbol *s, long ac, t_atom *av)
{
	t_object *postbox; // post's box
	object_obex_lookup(x, gensym("#B"), (t_object **) &postbox);
	object_obex_store(x->n_print, gensym("#B"), postbox);
}