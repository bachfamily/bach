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
	t_llllobj_object 	n_ob;
	long				n_auto;
    long                n_ignore;
} t_read;

void read_assist(t_read *x, void *b, long m, long a, char *s);
void read_inletinfo(t_read *x, void *b, long a, char *t);

t_read *read_new(t_symbol *s, short ac, t_atom *av);
void read_free(t_read *x);

void read_bang(t_read *x);
void read_read(t_read *x, t_symbol *s);
void read_return(t_read *x, t_llll *ll);
long read_acceptsdrag(t_read *x, t_object *drag, t_object *view);

t_max_err read_setattr_ignore(t_read *x, t_object *attr, long ac, t_atom *av);
t_max_err read_getattr_ignore(t_read *x, t_object *attr, long *ac, t_atom **av);

t_class *read_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
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

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	CLASS_ATTR_LONG(c, "auto",	0,	t_read, n_auto);
    CLASS_ATTR_LABEL(c, "auto", 0, "Output llll Automatically");
	CLASS_ATTR_FILTER_CLIP(c, "auto", 0, 1);
	CLASS_ATTR_STYLE(c, "auto", 0, "onoff");
	CLASS_ATTR_BASIC(c, "auto", 0);	
	// @description When set to 1, the llll is automatically output immediately after being read from disk.
    
    CLASS_ATTR_ATOM(c, "ignore",	0,	t_read, n_ignore);
    CLASS_ATTR_LABEL(c, "ignore", 0, "Ignore Categories");
    CLASS_ATTR_ACCESSORS(c, "ignore", read_getattr_ignore, read_setattr_ignore);
    // @description The <m>ignore</m> attribute allows preventing certain categories
    // of elements to be interpreted according to the usual bach syntax.
    // Categories are expressed by letters, according to the following table:<br />
    // - <b>L</b> stands for all the open and closed parens marking llll sublists:
    // if this category is set, parens and symbols containing parens
    // are read just as symbols, as if they were preceded by a backtick. <br />
    // - <b>l</b> stands for open and closed parens marking llll sublists,
    // only if they do not appear in a symbol of their own
    // (i.e., with the <b>l</b> category set,
    // <b>(</b> is interpreted as the beginning of a sublist,
    // whereas <b>(1</b> is interpreted just as a plain symbol,
    // as opposed to what would happen normally,
    // when it would mark the beginning of a sublist
    // whose first element is <b>1</b>). <br />
    // - <b>r</b> stands for rationals. <br />
    // - <b>p</b> stands for pitches. <br />
    // - <b>e</b> stands for floating-point numbers in scientific notation. <br />
    // - <b>s</b> stands for the special symbols <b>nil</b> and <b>null</b>. <br />
    // - <b>b</b> causes symbols beginning with a backtick
    // to be interpreted with the backtick included
    // (e.g., the <b>`foo</b> symbol is read as it is, including the backtick,
    // as opposed to what would happen normally, when it would be read as <b>foo</b>). <br />
    // - <b>a</b> stands for ignoring all the above categories.
    // If it is present alongside other specifiers (e.g., <b>alp</b>), it overrides them. <br />
    // - <b>-</b> stands for no category, and it is the default.
    // If it is present alongside other specifiers (e.g., <b>-p</b>), it is ignored. <br />
    // For example, the <m>ignore</m> attribute could be set to <b>lp</b>,
    // which would cause a file containing <b>( a001 Mahler(Bernstein).aif )</b>
    // to be read as an llll containing a sublist, containing in turn the symbols <b>a001</b> and
    // <b>Mahler(Bernstein).aif</b>.
    // Without setting the <m>ignore</m> attribute, the same file would be interpreted
    // as an llll containing a sublist containing the pitch <b>A1</b>,
    // the symbol <b>Mahler</b>,
    // a further sublist only containing the symbol <b>Bernstein</b>,
    // and finally the symbol <b>.aif</b>. <br />
    // As a final note, it should be remarked that symbols in double quotes
    // are always interpreted literally: for example, the symbol
    // <b>"Mahler (Bernstein).aif"</b> would be interpreted as the single symbol
    // <b>Mahler (Bernstein).aif</b> even if the <m>ignore</m> attribute is not set.
    
	class_register(CLASS_BOX, c);
	read_class = c;
	
	dev_post("bach.read compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err read_setattr_ignore(t_read *x, t_object *attr, long ac, t_atom *av)
{
    if (ac && av) {
        char *ignore_txt;
        switch (atom_gettype(av)) {
            case A_SYM:
                ignore_txt = atom_getsym(av)->s_name;
                break;
            case A_LONG:
                switch (atom_getlong(av)) {
                    case 0:
                        ignore_txt = (char *) "0";
                        break;
                    case 1:
                        ignore_txt = (char *) "1";
                        break;
                    default:
                        object_error((t_object *) x, "Bad value %ld for ignore attribute", atom_getlong(av));
                        ignore_txt = (char *) "";
                        break;
                }
                break;
            case A_FLOAT:
                object_error((t_object *) x, "Bad value %lf for ignore attribute", atom_getfloat(av));
                ignore_txt = (char *) "";
                break;
        }
        
        
        long negative = 0;
        while (*ignore_txt) {
            switch (*ignore_txt) {
                case 'L':   x->n_ignore |= LLLL_I_BIGPARENS | LLLL_I_SMALLPARENS;   break;
                case 'b':   x->n_ignore |= LLLL_I_BACKTICK;   break;
                case 'e':   x->n_ignore |= LLLL_I_SCIENTIFIC;   break;
                case 'l':   x->n_ignore |= LLLL_I_SMALLPARENS;   break;
                case 'p':   x->n_ignore |= LLLL_I_PITCH;   break;
                case 'r':   x->n_ignore |= LLLL_I_RATIONAL;   break;
                case 's':   x->n_ignore |= LLLL_I_SPECIAL;   break;
                case '1':   x->n_ignore = LLLL_I_ALL;   break;
                case '0':   break;
                case '-':   negative = 1;   break;
                default:    object_warn((t_object *) x, "Ignoring unknown %c specifier for ignore attribute", *ignore_txt); break;
            }
            ignore_txt++;
        }
        if (negative) {
            x->n_ignore = LLLL_I_ALL ^ x->n_ignore;
        }
        
    }
    return MAX_ERR_NONE;
}

t_max_err read_getattr_ignore(t_read *x, t_object *attr, long *ac, t_atom **av)
{
    char alloc;
    char ignore_txt[7];
    long ignore_long;
    char *this_ignore_txt = ignore_txt;
    atom_alloc(ac, av, &alloc);     // allocate return atom
    
    switch (x->n_ignore) {
        case LLLL_I_NONE:
            *ignore_txt = 0;
            ignore_long = 0;
            break;
        case LLLL_I_ALL:
            *ignore_txt = 0;
            ignore_long = 1;
            break;
        default:
            if (x->n_ignore & LLLL_I_BIGPARENS)     *(this_ignore_txt++) = 'L';
            if (x->n_ignore & LLLL_I_BACKTICK)      *(this_ignore_txt++) = 'b';
            if (x->n_ignore & LLLL_I_SCIENTIFIC)    *(this_ignore_txt++) = 'e';
            if (x->n_ignore & LLLL_I_SMALLPARENS &&
                !(x->n_ignore & LLLL_I_BIGPARENS))  *(this_ignore_txt++) = 'l';
            if (x->n_ignore & LLLL_I_PITCH)         *(this_ignore_txt++) = 'p';
            if (x->n_ignore & LLLL_I_RATIONAL)      *(this_ignore_txt++) = 'r';
            if (x->n_ignore & LLLL_I_SPECIAL)       *(this_ignore_txt++) = 's';
            break;
    }
    if (*ignore_txt) {
        *this_ignore_txt = 0;
        atom_setsym(*av, gensym(ignore_txt));
    } else
        atom_setlong(*av, ignore_long);
    return 0;
}

void read_bang(t_read *x)
{	
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void read_read(t_read *x, t_symbol *s)
{
	llll_read((t_object *) x, s, (read_fn) read_return, x->n_ignore);
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
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}