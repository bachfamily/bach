/**
 @file
 group.c
 
 @name 
 bach.group
 
 @realname 
 bach.group
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Group elements of an llll
 
 @description
 Groups the element of an llll in sublists, according to a regular size pattern.
  
 @category
 bach, bach objects, bach llll
 
 @keywords
 group, wrap, pattern, sublist

 @seealso
 bach.trans, bach.lace, bach.delace, bach.mdelace
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _group
{
	t_llllobj_object 	n_ob;
	t_llll				*n_count;
	t_bach_atomic_lock	n_count_lock;
	long				n_overlap;
} t_group;

void group_assist(t_group *x, void *b, long m, long a, char *s);

t_group *group_new(t_symbol *s, short ac, t_atom *av);
void group_free(t_group *x);

void group_bang(t_group *x);
void group_int(t_group *x, t_atom_long v);
void group_float(t_group *x, double v);
void group_anything(t_group *x, t_symbol *msg, long ac, t_atom *av);

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_group, n_count, group_getattr_count);
t_max_err group_setattr_count(t_group *x, t_object *attr, long ac, t_atom *av);
t_max_err group_check_count_llll(t_group *x, t_llll *ll);

t_class *group_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.group", (method)group_new, (method)group_free, (short)sizeof(t_group), 0L, A_GIMME, 0);

	// @method llll @digest Group the elements of the llll
	// @description
	// The elements of the input llll are sequentially grouped into sublists 
	// according to a regular pattern of sublist sizes, with optional overlapping.
	class_addmethod(c, (method)group_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)group_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)group_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)group_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Perform last operation
	// @description Returns the grouping of the most recently received llll.
	class_addmethod(c, (method)group_bang,		"bang",			0);
	
	class_addmethod(c, (method)group_assist,	"assist",		A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	
	
	
	CLASS_ATTR_LLLL(c, "count", 0, t_group, n_count, group_getattr_count, group_setattr_count);
	CLASS_ATTR_LABEL(c, "count", 0, "Count");
	CLASS_ATTR_BASIC(c, "count", 0);
	// @description The pattern of the size of the sublists. 
	// When the pattern's end is reached, it is read again from the beginning. 
	
	CLASS_ATTR_LONG(c, "overlap",	0,	t_group, n_overlap);
	CLASS_ATTR_FILTER_MIN(c, "overlap", 0);
	CLASS_ATTR_LABEL(c, "overlap", 0, "Overlap");
	// @description The number of shared elements between adjacent sublists.
	
	class_register(CLASS_BOX, c);
	group_class = c;
	
	dev_post("bach.group compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

t_max_err group_setattr_count(t_group *x, t_object *attr, long ac, t_atom *av)
{
	t_llll *ll;
	if (ac == 0 || av) {
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, av))) {
			t_llll *free_me;
			if (group_check_count_llll(x, ll) != MAX_ERR_NONE) {
				llll_free(ll);
				return MAX_ERR_NONE;
			}
			bach_atomic_lock(&x->n_count_lock);
			free_me = x->n_count;
			x->n_count = ll;
			bach_atomic_unlock(&x->n_count_lock);
			llll_free(free_me);
		}
	}
	return MAX_ERR_NONE;
}

t_max_err group_check_count_llll(t_group *x, t_llll *ll)
{
	t_llllelem *elem;
	if (ll->l_size == 0) {
		object_error((t_object *) x, "Bad count llll");
		return MAX_ERR_GENERIC;
	}
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		if (!hatom_is_number(&elem->l_hatom) || hatom_getlong(&elem->l_hatom) <= 0) {
			object_error((t_object *) x, "Bad count llll");
			return MAX_ERR_GENERIC;
		}
	}
	return MAX_ERR_NONE;
}

void group_bang(t_group *x)
{	
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		group_anything(x, _sym_bang, 0, NULL);
	else
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void group_int(t_group *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	group_anything(x, _sym_int, 1, &outatom);
}

void group_float(t_group *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	group_anything(x, _sym_float, 1, &outatom);
}

void group_anything(t_group *x, t_symbol *msg, long ac, t_atom *av)
{	
	t_llll *ll, *count;
    if (msg != _sym_bang) {
        ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!ll)
            return;
    } else
        ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);

    bach_atomic_lock(&x->n_count_lock);
    count = x->n_count;
    llll_retain(count);
    bach_atomic_unlock(&x->n_count_lock);
    t_max_err err = llll_multigroupllll(ll, count, x->n_overlap, 1);
    llll_release(count);
    if (err != MAX_ERR_NONE)
        object_warn((t_object *) x, "Bad overlap");
    x->n_ob.l_rebuild = 0;
    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, ll, 0);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void group_assist(t_group *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll"); // @in 0 @type llll @digest llll to process
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type);
		// @out 0 @type llll @digest Processed llll
	}
}

void group_free(t_group *x)
{
	llll_free(x->n_count);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_group *group_new(t_symbol *s, short ac, t_atom *av)
{
	t_group *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long true_ac;
	t_llll *count_ll = NULL;
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_group *) object_alloc_debug(group_class))) {
		// @arg 0 @name count @type list @optional 1 @digest Count
		// @description Initial value for the <m>count</m> attribute.

		if (true_ac) {
			count_ll = llll_parse(true_ac, av);
			if (count_ll) {
				if (group_check_count_llll(x, count_ll) == MAX_ERR_NONE) {
					x->n_count = count_ll;
				} else {
					llll_free(count_ll);
					count_ll = NULL;
				}
			} else {
				object_error((t_object *) x, "Bad count llll");
			}
		}
		if (!count_ll)
			x->n_count = llll_make();

		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "4");
	}
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
