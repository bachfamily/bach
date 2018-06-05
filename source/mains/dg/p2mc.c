/**
	@file
	p2mc.c
	
	@name 
	bach.p2mc
	
	@realname 
	bach.p2mc

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Pitches to MIDIcents conversion
	
	@description
	Converts an llll containing pitches into the corresponding llll of MIDIcents.
	
	@discussion
	bach.p2mc accepts microtones following the ASCII convention used throughout bach. <br />
	@copy BACH_DOC_ASCII_ACCIDENTALS_SYNTAX
	
	@category
	bach, bach objects, bach notation

	@keywords
	convert, midicent, cent, note, name

	@seealso
	bach.mc2p, bach.f2mc, bach.mc2f
	
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

typedef struct _p2mc
{
	struct llllobj_object 	n_ob;
} t_p2mc;


void p2mc_assist(t_p2mc *x, void *b, long m, long a, char *s);
void p2mc_inletinfo(t_p2mc *x, void *b, long a, char *t);

t_p2mc *p2mc_new(t_symbol *s, short ac, t_atom *av);
void p2mc_free(t_p2mc *x);

void p2mc_bang(t_p2mc *x);
void p2mc_int(t_p2mc *x, t_atom_long num);
void p2mc_float(t_p2mc *x, double num);
void p2mc_anything(t_p2mc *x, t_symbol *msg, long ac, t_atom *av);

t_class *p2mc_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.p2mc", (method)p2mc_new, (method)p2mc_free, (short)sizeof(t_p2mc), 0L, A_GIMME, 0);
	
	// @method llll @digest Convert pitches to midicents
	// @description The function outputs an llll formatted as the incoming one, but containing the midicents values 
	// instead of each pitch.
	class_addmethod(c, (method)p2mc_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)p2mc_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)p2mc_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)p2mc_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the conversion.
	// @description Perform the conversion on the most recently received input data.
	class_addmethod(c, (method)p2mc_bang,						"bang",		0);
	
	class_addmethod(c, (method)p2mc_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)p2mc_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	
	class_register(CLASS_BOX, c);
	p2mc_class = c;
	
	dev_post("bach.p2mc compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void p2mc_bang(t_p2mc *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void p2mc_int(t_p2mc *x, t_atom_long num){
	t_atom argv[1]; 
	atom_setlong(argv, num);
	p2mc_anything(x, _llllobj_sym_list, 1, argv);
}

void p2mc_float(t_p2mc *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	p2mc_anything(x, _llllobj_sym_list, 1, argv);
}

long substitute_pitches_with_mc_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_PITCH)
        hatom_setrational(a, hatom_getpitch(a).toMC());
	return 0;
}

void p2mc_anything(t_p2mc *x, t_symbol *msg, long ac, t_atom *av)
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
		llll_funall(inlist, (fun_fn) substitute_pitches_with_mc_fn, x, 1, -1, 0);
	
	if (inlist)
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, inlist, 0);
	
	x->n_ob.l_rebuild = 0;
	p2mc_bang(x);
}


void p2mc_assist(t_p2mc *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) { // @in 0 @type llll @digest The llll containing the pitches
		sprintf(s, "llll: Pitches");
    } else {
		char *type = NULL; // @out 0 @type llll @digest The llll containing the MIDIcents
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): Cents", type);
	}
}

void p2mc_inletinfo(t_p2mc *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void p2mc_free(t_p2mc *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_p2mc *p2mc_new(t_symbol *s, short ac, t_atom *av)
{
	t_p2mc *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_p2mc *) object_alloc_debug(p2mc_class))) {
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

