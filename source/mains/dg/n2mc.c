/**
	@file
	n2mc.c
	
	@name 
	bach.n2mc
	
	@realname 
	bach.n2mc

	@type
	object
	
	@module
	bach

	@author
	bachproject
 
    @status
    deprecated
	
	@digest
	Note names to midicents conversion
	
	@description
	Converts an llll containing note names (in latin or anglo-saxon syntax) into the corresponding llll of midicents.
	
	@discussion
	bach.n2mc accepts microtones following the ascii convention used throughout bach. <br />	
	@copy BACH_DOC_ASCII_ACCIDENTALS_SYNTAX
	
	@category
	bach, bach objects, bach notation

	@keywords
	convert, midicent, cent, note, name

	@seealso
	bach.mc2n, bach.f2mc, bach.mc2f
	
	@owner
	Daniele Ghisi
*/

#include "llllobj.h"
#include "notation.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"

typedef struct _n2mc
{
	struct llllobj_object 	n_ob;
	
	long					middle_c_octave;
	long					last_used_octave;
} t_n2mc;


void n2mc_assist(t_n2mc *x, void *b, long m, long a, char *s);
void n2mc_inletinfo(t_n2mc *x, void *b, long a, char *t);

t_n2mc *n2mc_new(t_symbol *s, short ac, t_atom *av);
void n2mc_free(t_n2mc *x);

void n2mc_bang(t_n2mc *x);
void n2mc_int(t_n2mc *x, t_atom_long num);
void n2mc_float(t_n2mc *x, double num);
void n2mc_anything(t_n2mc *x, t_symbol *msg, long ac, t_atom *av);

t_class *n2mc_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.n2mc", (method)n2mc_new, (method)n2mc_free, (short)sizeof(t_n2mc), 0L, A_GIMME, 0);
	
	// @method llll @digest Convert note names to midicents
	// @description The function outputs an llll formatted as the incoming one, but containing the midicents values 
	// instead of each note name. 
	class_addmethod(c, (method)n2mc_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)n2mc_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)n2mc_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)n2mc_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the conversion.
	// @description Perform the conversion on the most recently received input data.
	class_addmethod(c, (method)n2mc_bang,						"bang",		0);
	
	class_addmethod(c, (method)n2mc_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)n2mc_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	
	CLASS_ATTR_LONG(c, "middlecoctave", 0, t_n2mc, middle_c_octave); 
	CLASS_ATTR_STYLE_LABEL(c,"middlecoctave",0,"text","Middle C Octave");
    CLASS_ATTR_INVISIBLE(c, "middlecoctave", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // deprecated and unsupported
    // @exclude all
	// @description @copy BACH_DOC_MIDDLECOCTAVE

	class_register(CLASS_BOX, c);
	n2mc_class = c;
	
	dev_post("bach.n2mc compiled %s %s", __DATE__, __TIME__);
    object_warn(NULL, "bach.n2mc is deprecated. Please consider replacing me with bach.p2mc!");

	return 0;
}

void n2mc_bang(t_n2mc *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void n2mc_int(t_n2mc *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	n2mc_anything(x, _llllobj_sym_list, 1, argv);
}

void n2mc_float(t_n2mc *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	n2mc_anything(x, _llllobj_sym_list, 1, argv);
}

long substitute_names_with_mc_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_SYM){
		t_n2mc *x = (t_n2mc *) data;
		long screen_mc = 0;
		t_rational screen_acc = long2rat(0);
		t_rational acc_part = long2rat(0);
		
		notename2midicents(x->middle_c_octave, &x->last_used_octave, hatom_getsym(a)->s_name, &screen_mc, &screen_acc);
		acc_part = rat_long_prod(screen_acc, 200);
		if (acc_part.r_den == 1)
			hatom_setlong(a, screen_mc + acc_part.r_num);
		else
			hatom_setdouble(a, screen_mc + rat2double(acc_part));
    } else if (hatom_gettype(a) == H_PITCH) {
        t_pitch p = hatom_getpitch(a);
        t_rational mc = p.toMC();
        if (mc.r_den == 1)
            hatom_setlong(a, mc.r_num);
        else
            hatom_setdouble(a, rat2double(mc));
    }
	return 0;
}

void n2mc_anything(t_n2mc *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	if (inlist)
		llll_funall(inlist, (fun_fn) substitute_names_with_mc_fn, x, 1, -1, 0);
	
	if (inlist)
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, inlist, 0);
	
	x->n_ob.l_rebuild = 0;
	n2mc_bang(x);
}


void n2mc_assist(t_n2mc *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll containing the note names 
		sprintf(s, "llll: Names"); // @discussion Both latin and anglo-saxon syntaxes are accepted.
	} else {
		char *type = NULL; // @out 0 @type llll @digest The llll containing the midicents
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Cents", type);
	}
}

void n2mc_inletinfo(t_n2mc *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void n2mc_free(t_n2mc *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_n2mc *n2mc_new(t_symbol *s, short ac, t_atom *av)
{
	t_n2mc *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_n2mc *) object_alloc_debug(n2mc_class))) {
	
		x->middle_c_octave = 5;

		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");

		x->last_used_octave = x->middle_c_octave;
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

