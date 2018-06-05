/**
	@file
	llll2dict.c
	
	@name 
	bach.llll2dict
	
	@realname 
	bach.llll2dict

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert an llll into a dictionary
	
	@description
	Converts an llll into a dictionary, under the convention that the first element in each level is the level key.
		
	@discussion
	A dictionary in llll form can be visualized by <o>bach.tree</o>'s Outline mode (similar to <o>dict.view</o>, but with a few
	more features). 
 
	@category
	bach, bach abstractions, bach llll
 
	@keywords
	convert, `dictionary, name, element, tree
 
	@seealso
	bach.dict2llll, dict, bach.tree
 
	@owner
	Daniele Ghisi
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_dictobj.h"
#include "llll_commons_ext.h"

typedef struct _llll2dict
{
	struct llllobj_object 	n_ob;
	t_symbol		*name;			// dictionary name
	t_dictionary	*dictionary;		// the actual dictionary
} t_llll2dict;


void llll2dict_assist(t_llll2dict *x, void *b, long m, long a, char *s);
void llll2dict_inletinfo(t_llll2dict *x, void *b, long a, char *t);

t_llll2dict *llll2dict_new(t_symbol *s, short ac, t_atom *av);
void llll2dict_free(t_llll2dict *x);


void llll2dict_fn(t_object *x, t_llll *ll, t_dictionary *d, char skip_first_elem);

void llll2dict_bang(t_llll2dict *x);
void llll2dict_int(t_llll2dict *x, t_atom_long num);
void llll2dict_float(t_llll2dict *x, double num);
void llll2dict_anything(t_llll2dict *x, t_symbol *msg, long ac, t_atom *av);

void llll2dict_setname(t_llll2dict *x, void *attr, long argc, t_atom *argv);


t_class *llll2dict_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}	
	
	c = class_new("bach.llll2dict", (method)llll2dict_new, (method)llll2dict_free, (short)sizeof(t_llll2dict), 0L, A_GIMME, 0);
	
	// @method llll @digest Convert llll to dictionary
	// @description Any incoming <m>llll</m> is converted into a dictionary
	class_addmethod(c, (method)llll2dict_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)llll2dict_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)llll2dict_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)llll2dict_anything,					"list",					A_GIMME,	0);
	
	// @method bang @digest Output last built dictionary
	// @description Outputs the most recently converted dictionary.
	class_addmethod(c, (method)llll2dict_bang,						"bang",		0);
	
	class_addmethod(c, (method)llll2dict_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)llll2dict_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	
	CLASS_ATTR_SYM(c,"name",0, t_llll2dict, name);
	CLASS_ATTR_STYLE_LABEL(c,"name",0,"text","Dictionary Name");
	CLASS_ATTR_ACCESSORS(c,		"name",			NULL, llll2dict_setname);
	CLASS_ATTR_BASIC(c,"name",0);
	// @description Sets the name of the dictionary. By default it is an autoassigned name.

	class_register(CLASS_BOX, c);
	llll2dict_class = c;
	
	dev_post("bach.llll2dict compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


void llll2dict_setname(t_llll2dict *x, void *attr, long argc, t_atom *argv)
{
	t_symbol		*name = atom_getsym(argv);	
	
	if (!x->name || !name || x->name!=name) {
		object_free(x->dictionary); // will call object_unregister
		x->dictionary = dictionary_new();
		x->dictionary = dictobj_register(x->dictionary, &name);
		x->name = name;
	}
	if (!x->dictionary)
		object_error((t_object*)x, "Could not create dictionary named %s", name->s_name);
}

void llll2dict_bang(t_llll2dict *x)
{
	if (x->name) {
		t_atom	a[1];
		atom_setsym(a, x->name);
		llllobj_outlet_anything((t_object *)x, LLLL_OBJ_VANILLA, 0, _sym_dictionary, 1, a);
	}
}

void llll2dict_int(t_llll2dict *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	llll2dict_anything(x, _sym_int, 1, &outatom);
}

void llll2dict_float(t_llll2dict *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	llll2dict_anything(x, _sym_float, 1, &outatom);
}



// also throws errors if needed
void llll2dict_fn(t_object *x, t_llll *ll, t_dictionary *d, char skip_first_elem)
{
	t_llllelem *elem;
	
	dictionary_clear(d);

	for (elem = (skip_first_elem && ll->l_head) ? ll->l_head->l_next : ll->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *subll = hatom_getllll(&elem->l_hatom);
			if (!subll->l_head) {
				object_error(x, "Found an empty llll - could not be converted");
			} else {
				t_symbol *key;
				if (hatom_gettype(&subll->l_head->l_hatom) == H_SYM)
					key = hatom_getsym(&subll->l_head->l_hatom);
				else {
					key = hatom_to_symbol(&subll->l_head->l_hatom);
					if (key)
						object_warn(x, "Non-symbolic key found - converted to symbol %s", key->s_name);
					else
						object_error(x, "Non-symbolic key found - could not be converted");
				}
				
				if (key) {
					if (!subll->l_head->l_next)
						object_error(x, "Null value detected for key %s - could not be converted.", key->s_name);
					else {
						if (subll->l_depth > 1) {
							// gotta make a subdictionary
							t_dictionary *subd = dictionary_new();
							llll2dict_fn(x, subll, subd, true);
							dictionary_appenddictionary(d, key, (t_object *)subd);

						} else if (subll->l_size == 2) {
							// single atom
							long type = hatom_gettype(&subll->l_head->l_next->l_hatom);
							switch (type) {
								case H_LONG:
									dictionary_appendlong(d, key, hatom_getlong(&subll->l_head->l_next->l_hatom));
									break;
								case H_DOUBLE:
									dictionary_appendfloat(d, key, hatom_getdouble(&subll->l_head->l_next->l_hatom));
									break;
								case H_RAT:		/// rationals are converted into doubles
									dictionary_appendfloat(d, key, hatom_getdouble(&subll->l_head->l_next->l_hatom));
									break;
								case H_SYM:
									dictionary_appendsym(d, key, hatom_getsym(&subll->l_head->l_next->l_hatom));
									break;
								case H_OBJ:
									dictionary_appendobject(d, key, (t_object *)hatom_getobj(&subll->l_head->l_next->l_hatom));
									break;
								default:
									object_error(x, "Unknown atom type detected - could not be converted.");
									break;
							}
							
						} else {
							// multiple atoms
							t_atom *av = NULL;
							long ac = llll_deparse(subll, &av, 0, 0);
							dictionary_appendatoms(d, key, ac - 1, av + 1);
							bach_freeptr(av);
						}
					}
				}
				
			}
		} else {
			object_error(x, "Found an atom which could not be converted");
		}
	}
}


void llll2dict(t_object *x, t_llll *ll, t_dictionary *d)
{
	llll2dict_fn(x, ll, d, false);
}

void llll2dict_anything(t_llll2dict *x, t_symbol *msg, long ac, t_atom *av)
{	
	if (x->dictionary) {
		t_llll *ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
		if (ll) 
			llll2dict((t_object *)x, ll, x->dictionary);
		llll_free(ll);
	}
	llll2dict_bang(x);
}



void llll2dict_assist(t_llll2dict *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "dictionary as llll"); // @in 0 @type llll @digest The dictionary as llll 
	} else {
		sprintf(s, "dictionary: Dictionary Name"); // @out 0 @type dictionary @digest The dictionary name 
	}
}

void llll2dict_inletinfo(t_llll2dict *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void llll2dict_free(t_llll2dict *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_llll2dict *llll2dict_new(t_symbol *s, short ac, t_atom *av)
{
	t_llll2dict *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_llll2dict *) object_alloc_debug(llll2dict_class))) {
		long			attrstart = attr_args_offset(ac, av);
		t_symbol		*name = NULL;

		// @arg 0 @name name @optional 1 @type symbol @digest Dictionary name
		if (attrstart && atom_gettype(av) == A_SYM)
			name = atom_getsym(av);		
	
//		x->outlet_dict = outlet_new(x, "dictionary");
		x->dictionary = dictionary_new();

		attr_args_process(x, ac, av);

		llllobj_obj_setup((t_llllobj_object *) x, 1, "a", "dictionary");

		if (!x->name) {
			if (name)
				object_attr_setsym(x, _sym_name, name);
			else
				object_attr_setsym(x, _sym_name, symbol_unique());
		}
		
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

