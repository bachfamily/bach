/**
 @file
 read.c
 
 @name 
 bach.read
 
 @realname 
 bach.read
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Read an llll from disk
 
 @description
 Reads an llll from a file.
  
 @discussion
 lllls in text and native format can be read indifferently
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 read, load, disk, file, native, text

 @seealso
 bach.write, bach.shelf, bach.reg
 
 @owner
 Andrea Agostini
 */

#include "llll_files.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_drag.h"

typedef struct _read
{
	struct llllobj_object 	n_ob;
	long					n_auto;
} t_read;

void read_assist(t_read *x, void *b, long m, long a, char *s);
void read_inletinfo(t_read *x, void *b, long a, char *t);

t_read *read_new(t_symbol *s, short ac, t_atom *av);
void read_free(t_read *x);

void read_bang(t_read *x);
void read_read(t_read *x, t_symbol *s);
void read_return(t_read *x, t_llll *ll);
long read_acceptsdrag(t_read *x, t_object *drag, t_object *view);

t_class *read_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.read", (method)read_new, (method)read_free, (short)sizeof(t_read), 0L, A_GIMME, 0);
	
	// @method read @digest Read an llll from disk
	// @description The specified file is read from disk and the llll it contains is stored
	// and optionally output, according to the <m>auto</m> attribute.
	// If no file name is provided, a dialog box will open.
	// @marg 0 @name file_name @optional 1 @type symbol
	class_addmethod(c, (method)read_read,		"read",			A_DEFSYM,	0);
	
	// @method bang @digest Output the stored llll
	// @description After an llll has been read, a bang causes it to be output.
	class_addmethod(c, (method)read_bang,		"bang",			0);
	
	class_addmethod(c, (method)read_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)read_inletinfo,	"inletinfo",	A_CANT,		0);
	
	// @method (drag) @digest Drag-and-drop file loading
	// @description The specified file is read from disk and the llll it contains is stored
	// and optionally output, according to the <m>auto</m> attribute.
	class_addmethod(c, (method)read_acceptsdrag, "acceptsdrag_locked", A_CANT, 0);
	class_addmethod(c, (method)read_acceptsdrag, "acceptsdrag_unlocked", A_CANT, 0);

	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
	
	CLASS_ATTR_LONG(c, "auto",	0,	t_read, n_auto);
	CLASS_ATTR_FILTER_CLIP(c, "auto", 0, 1);
	CLASS_ATTR_STYLE(c, "auto", 0, "onoff");
	CLASS_ATTR_BASIC(c, "auto", 0);	
	// @description When set to 1, the llll is automatically output immediately after being read from disk.

	class_register(CLASS_BOX, c);
	read_class = c;
	
	dev_post("bach.read compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void read_bang(t_read *x)
{	
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void read_read(t_read *x, t_symbol *s)
{
	llll_read((t_object *) x, s, (read_fn) read_return);	
}

void read_return(t_read *x, t_llll *ll)
{
	if (!ll) {
		object_error((t_object *) x, "Bad input file");
		return;
	}
	llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
	llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 1);
	if (x->n_auto)
		read_bang(x);
}

long read_acceptsdrag(t_read *x, t_object *drag, t_object *view)
{
	if (jdrag_matchdragrole(drag, gensym("llllfile"), 0) ||
		jdrag_matchdragrole(drag, gensym("textfile"), 0))  {
		jdrag_object_add(drag, (t_object *)x, gensym("read"));
		return true;
	}
	return false;
}

void read_assist(t_read *x, void *b, long m, long a, char *s)
{
	if (m == ASSIST_INLET) {
		sprintf(s, "read / bang"); // @in 0 @type read/bang @digest Read to load an llll, bang to output it
	} else {
		if (a == 0)	{
			char *type = NULL;
			llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
			sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest llll that has been loaded
		} else
			sprintf(s, "bang When Finished Reading"); // @out 1 @type bang @digest bang when loading is completed
	}
}

void read_inletinfo(t_read *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void read_free(t_read *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_read *read_new(t_symbol *s, short ac, t_atom *av)
{
	t_read *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_read *) object_alloc_debug(read_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 0, "b4");
	}
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}