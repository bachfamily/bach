/**
 @file
 rot.c
 
 @name 
 bach.rot
 
 @realname 
 bach.rot
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Rotate an llll
 
 @description 
 Performs a rotation of an llll and its sublists, within a specified depth range.
  
 @category
 bach, bach objects, bach llll

 @keywords
 rotate, shift, circular

 @seealso
 bach.rev, bach.slice, bach.join, bach.trans, bach.chordrot, bach.restrot, Through The Looking Glass
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _rot
{
	t_llllobj_object 	n_ob;
	long				n_mindepth;
	long				n_maxdepth;
	long				n_shift;
} t_rot;


void rot_assist(t_rot *x, void *b, long m, long a, char *s);
void rot_inletinfo(t_rot *x, void *b, long a, char *t);

t_rot *rot_new(t_symbol *s, short ac, t_atom *av);
void rot_free(t_rot *x);

void rot_bang(t_rot *x);
void rot_int(t_rot *x, t_atom_long v);
void rot_float(t_rot *x, double v);
void rot_anything(t_rot *x, t_symbol *msg, long ac, t_atom *av);
t_max_err rot_notify(t_rot *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

DEFINE_STANDARD_MAXDEPTH_SETTER(t_rot);
DEFINE_STANDARD_MINDEPTH_SETTER(t_rot);

t_class *rot_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.rot", (method)rot_new, (method)rot_free, (short)sizeof(t_rot), 0L, A_GIMME, 0);

	// @method llll @digest Rotate the incoming llll
	// @description Perform the rotation on the incoming llll.
	class_addmethod(c, (method)rot_anything,	"anything",		A_GIMME,	0);

	class_addmethod(c, (method)rot_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)rot_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)rot_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform the rotation
	// @description Perform the rotation on the most recently received llll.
	class_addmethod(c, (method)rot_bang,		"bang",			0);
	
	class_addmethod(c, (method)rot_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)rot_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	
	CLASS_ATTR_LONG(c, "shift",	0,	t_rot,	n_shift);
	CLASS_ATTR_LABEL(c, "shift", 0, "Shift");
	CLASS_ATTR_BASIC(c, "shift", 0);
	// @description Number of steps to rotate the llll of. Positive numbers rotate left, negative numbers rotate right.
	
	CLASS_ATTR_LONG(c, "mindepth",	0,	t_rot, n_mindepth);
	CLASS_ATTR_LABEL(c, "mindepth", 0, "Minimum Depth");
	CLASS_ATTR_BASIC(c, "mindepth", 0);	
	CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, t_rot);
	// @description @copy BACH_DOC_MINDEPTH

	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_rot, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);	
	CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, t_rot);
	// @description @copy BACH_DOC_MAXDEPTH
	
	class_register(CLASS_BOX, c);
	rot_class = c;
	
	dev_post("bach.rot compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void rot_bang(t_rot *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		rot_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void rot_int(t_rot *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	rot_anything(x, _sym_int, 1, &outatom);
}

void rot_float(t_rot *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	rot_anything(x, _sym_float, 1, &outatom);
}

void rot_anything(t_rot *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll;
    if (msg != _sym_bang) {
        ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
    llll_rot(ll, x->n_mindepth, x->n_maxdepth, x->n_shift);
    x->n_ob.l_rebuild = 0;
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void rot_assist(t_rot *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @digest The llll to rotate
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @digest The rotated llll
	}
}

void rot_inletinfo(t_rot *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void rot_free(t_rot *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}


t_rot *rot_new(t_symbol *s, short ac, t_atom *av)
{
	t_rot *x = NULL;
	t_max_err err = 0;
	long true_ac;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_rot *) object_alloc_debug(rot_class))) {
		x->n_maxdepth = 1;
		x->n_mindepth = 1;

		// @arg 0 @name parameters @optional 1 @type list @digest Rotation parameters 
		// @description 
		// If one argument is present, it sets the number of steps to rotate the llll of. 
		// Positive numbers rotate left, negative numbers rotate right.
		
		// @arg 1 @name depths @optional 1 @type list @digest Depth options
		// @description If there is no third argument, it sets <m>maxdepth</m>.
		// If a second and third argument are present, they set respectively <m>mindepth</m> and <m>maxdepth</m>.

		switch (true_ac) {
			case 0: 
				break;
			case 1:
				x->n_shift = atom_getlong(av);
				break;
			case 2:
				x->n_shift = atom_getlong(av);
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av + 1);
				break;
			case 3:
				x->n_shift = atom_getlong(av);
				object_attr_setvalueof(x, gensym("mindepth"), 1, av + 1);
				object_attr_setvalueof(x, gensym("maxdepth"), 1, av + 2);
				break;
			default:
				object_warn((t_object *) x, "Bad number of arguments");
				break;
		}
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
