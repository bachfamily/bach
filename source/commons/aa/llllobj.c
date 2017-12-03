#include "llllobj.h"
#include "ext_common.h"
#include "ext_strings.h"
#include "ext_critical.h"
#include "jpatcher_api.h"


#define LLLLOBJ_ENABLE_DESTRUCTIVE	0
#define LLLLOBJ_ENABLE_VOLATILE	0
#define LLLLOBJ_ENABLE_ONCE		0

extern t_bach *bach;

void llllobj_post_destructive_volatile(void)
{
#if LLLLOBJ_ENABLE_DESTRUCTIVE
	dev_post("--- destructive attribute is active");
#endif
#if LLLLOBJ_ENABLE_VOLATILE
	dev_post("--- volatile attribute is active");
#endif
}

e_llllobj_obj_types llllobj_get_obj_type(void *x)
{
	t_class *c;
	int msp = 0, ui = 0;
	
	if (!(c = object_class(x)))
		return LLLL_OBJ_ERR;
	
	msp = zgetfn((t_object *) x, _sym_dsp) != 0; // hoping that no object has a " " method!!!
	ui = c->c_flags & CLASS_FLAG_UIOBJECT; // can be changed to ui = class_is_ui(c) in max 5.1.5;
	
	if (ui && msp)
		return LLLL_OBJ_UIMSP;
	if (ui)
		return LLLL_OBJ_UI;
	if (msp)
		return LLLL_OBJ_MSP;
	
	return LLLL_OBJ_VANILLA;
}

t_llllobj_out *llllobj_get_out(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_out;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_out;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_out;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_out;
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}

t_llllobj_store *llllobj_get_incache(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_incache;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_incache;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_incache;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_incache;
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}

long llllobj_get_numouts(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_numouts;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_numouts;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_numouts;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_numouts;
			break;
		default:
			return -1;
			break;
	}
	return -1;
}

long llllobj_get_numllllouts(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_numllllouts;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_numllllouts;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_numllllouts;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_numllllouts;
			break;
		default:
			return -1;
			break;
	}
	return -1;
}

long llllobj_get_numstores(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_numstores;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_numstores;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_numstores;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_numstores;
			break;
		default:
			return -1;
			break;
	}
	return -1;
}

t_symbol *llllobj_get_outtypes(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_outtypes;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_outtypes;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_outtypes;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_outtypes;
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}


long llllobj_get_versionnumber(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_versionnumber;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_versionnumber;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_versionnumber;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_versionnumber;
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}


t_hashtab *llllobj_get_release(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return ((t_llllobj_object *) x)->l_release;
			break;
		case LLLL_OBJ_MSP:
			return ((t_llllobj_pxobject *) x)->l_release;
			break;
		case LLLL_OBJ_UI:
			return ((t_llllobj_jbox *) x)->l_release;
			break;
		case LLLL_OBJ_UIMSP:
			return ((t_llllobj_pxjbox *) x)->l_release;
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}

t_bach_atomic_lock *llllobj_get_release_lock_ptr(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return &((t_llllobj_object *) x)->l_release_lock;
			break;
		case LLLL_OBJ_MSP:
			return &((t_llllobj_pxobject *) x)->l_release_lock;
			break;
		case LLLL_OBJ_UI:
			return &((t_llllobj_jbox *) x)->l_release_lock;
			break;
		case LLLL_OBJ_UIMSP:
			return &((t_llllobj_pxjbox *) x)->l_release_lock;
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}

e_llllobj_outlet_types llllobj_get_outlet_type(t_object *x, e_llllobj_obj_types type, long num)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return (e_llllobj_outlet_types) ((t_llllobj_object *) x)->l_out[num].b_type;
			break;
		case LLLL_OBJ_MSP:
			return (e_llllobj_outlet_types) ((t_llllobj_pxobject *) x)->l_out[num].b_type;
			break;
		case LLLL_OBJ_UI:
			return (e_llllobj_outlet_types) ((t_llllobj_jbox *) x)->l_out[num].b_type;
			break;
		case LLLL_OBJ_UIMSP:
			return (e_llllobj_outlet_types) ((t_llllobj_pxjbox *) x)->l_out[num].b_type;
			break;
		default:
			return LLLL_O_DISABLED;
			break;
	}
	return LLLL_O_DISABLED;
}


t_llll **llllobj_get_dictll_ptr(t_object *x, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			return &((t_llllobj_object *) x)->l_dictll;
			break;
		case LLLL_OBJ_MSP:
			return &((t_llllobj_pxobject *) x)->l_dictll;
			break;
		case LLLL_OBJ_UI:
			return &((t_llllobj_jbox *) x)->l_dictll;
			break;
		case LLLL_OBJ_UIMSP:
			return &((t_llllobj_pxjbox *) x)->l_dictll;
			break;
		default:
			return NULL;
			break;
	}
	return NULL;
}

void llllobj_get_llll_outlet_type_as_string(t_object *x, e_llllobj_obj_types type, long num, char **str)
{
	if (num >= llllobj_get_numouts(x, type)) {
		*str = NULL;
		return;
	}
	switch (llllobj_get_outlet_type((t_object *) x, type, num)) {
		case LLLL_O_NATIVE:		*str = (char *)	"native";	break;
		case LLLL_O_TEXT:		*str = (char *)	"text";		break;
		case LLLL_O_MAX:		*str = (char *)	"max";		break;
		case LLLL_O_DISABLED:	*str = (char *)	"disabled";	break;
		default:	break;
	}
}


t_llll *llllobj_get_retained_store_contents(t_object *x, e_llllobj_obj_types type, long num)
{
	t_llllobj_store *store;
	t_llll *outll;
	switch (type) {
		case LLLL_OBJ_VANILLA:
			store = ((t_llllobj_object *) x)->l_incache + num;
			break;
		case LLLL_OBJ_MSP:
			store = ((t_llllobj_pxobject *) x)->l_incache + num;
			break;
		case LLLL_OBJ_UI:
			store = ((t_llllobj_pxobject *) x)->l_incache + num;
			break;
		case LLLL_OBJ_UIMSP:
			store = ((t_llllobj_pxobject *) x)->l_incache + num;
			break;
		default:
			return NULL;
	}
	bach_atomic_lock(&store->s_lock);
	outll = store->s_ll;
	llll_retain(outll);
	bach_atomic_unlock(&store->s_lock);
	return outll;
}

t_llll *llllobj_get_store_contents(t_object *x, e_llllobj_obj_types type, long num, long clone)
{
	t_llllobj_store *store;
	t_llll *storedll, *clonedll;
	switch (type) {
		case LLLL_OBJ_VANILLA:
			store = ((t_llllobj_object *) x)->l_incache + num;
			break;
		case LLLL_OBJ_MSP:
			store = ((t_llllobj_pxobject *) x)->l_incache + num;
			break;
		case LLLL_OBJ_UI:
			store = ((t_llllobj_jbox *) x)->l_incache + num;
			break;
		case LLLL_OBJ_UIMSP:
			store = ((t_llllobj_pxjbox *) x)->l_incache + num;
			break;
		default:
			return NULL;
	}
	bach_atomic_lock(&store->s_lock);
	storedll = store->s_ll;
	llll_retain(storedll);
	bach_atomic_unlock(&store->s_lock);
	if (clone) {
		clonedll = llll_clone(storedll);
		llll_release(storedll);
		return clonedll;
	} else
		return storedll;
}

t_llll *llllobj_get_retained_native_llll_from_args(long ac, t_atom *av)
{
	if (ac == 1 && av->a_type == A_LONG)
		return llll_retrieve_from_phonenumber_and_retain(av->a_w.w_long);
	return NULL;
}

/*
 Create a new llll from a message and an array of atoms
 This is especially useful from parsing messages coming through inlets
 If the input has the form "bach.llll 1234" (i.e. it's a native representation) the address of the associated llll is returned, if valid
 If the input is a text-based representation, a new llll is created and its address is returned
 If the input is not valid, NULL is returned
 If the LLLL_PARSE_RETAIN flag is set and the input is a native representation, the llll is retained.
 If the LLLL_PARSE_CLONE flag is set and the input is a native representation, a copy of the llll is returned.
 This gives you ownership to the returned llll in any case, and you must free it / release it.
 If you set LLLL_PARSE_RETAIN you only have the right to perform non-destructive operations on the llll.
 If you set LLLL_PARSE_CLONE you also have the right to perform destructive operations on the llll.
 But if you want to store the incoming llll in one of your object's stores, then you have to use llllobj_parse_and_store or llllobj_parse_retain_and_store
 */

t_llll *llllobj_parse_llll(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, e_llllobj_parse_flags flags, long ignore)
{
	long new_ac;
	t_atom *new_av, *this_new_av;
	t_llll *inlist;
	
	if (msg == LLLL_NATIVE_MSG ||
		(msg == NULL && ac == 2 && atom_getsym(av) == LLLL_NATIVE_MSG)) {
		if (msg)
			inlist = llllobj_get_retained_native_llll_from_args(ac, av);
		else
			inlist = llllobj_get_retained_native_llll_from_args(1, av + 1);
		if (!inlist) {
			object_error(x, "Bad input llll");
			return NULL;
		}
#ifdef BACH_CHECK_LLLLS
		if (llll_check(inlist))
			error("llllobj_parse_llll: bad llll");
#endif // BACH_CHECK_LLLLS
		if (flags & LLLL_PARSE_CLONE) {
			t_llll *cloned;
			cloned = llll_clone(inlist);
			llll_release(inlist);
			inlist = cloned;
		}
		return inlist;

	} else {
		if (msg == _sym_list || msg == _sym_int || msg == _sym_float || msg == NULL) {
			inlist = llll_parse(ac, av);
		} else {
			new_ac = ac + 1;
			new_av = (t_atom *) bach_newptr(sizeof (t_atom) * new_ac);
			atom_setsym(new_av, msg);
			this_new_av = new_av + 1;
			sysmem_copyptr(av, new_av + 1, ac * sizeof(t_atom)); // can't use bach_copyptr here, as new_av + 1 has not an entry in the memory map
			inlist = llll_parse(new_ac, new_av, ignore);
			bach_freeptr(new_av);
		}
		if (!inlist) 
			object_error(x, "Bad input llll");
		return inlist;
	}
}

t_llll *llllobj_parse_llllattr_llll(t_object *x, e_llllobj_obj_types type, long ac, t_atom *av)
{
	if (ac == 1 && atom_gettype(av) == A_SYM) {
		t_atom a;
		atom_setobj(&a, atom_getsym(av)->s_name);
		return llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, 1, &a, LLLL_PARSE_CLONE);
		// this is a workaround, because pointer attributes (as lllls are) only pass one symbol
		// containing all the text for the new attribute value
	} else {
		return llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_CLONE);
	}
}

void llllobj_gunload_bttext(t_llllobj_out *cache, t_llll *inll)
{
	t_atomarray *deparsed_aa;
	t_atomarray *free_me;
	t_llll *old_ll;

	deparsed_aa = llll_deparse_to_aa(inll, LLLL_D_QUOTE | LLLL_D_MAX);
	
	bach_atomic_lock(&cache->b_lock);
	old_ll = cache->b_ll;
	cache->b_ll = inll;
	free_me = cache->b_aa;
	llllobj_cache_text(cache, deparsed_aa);
	bach_atomic_unlock(&cache->b_lock);
	llll_free(old_ll);
	object_free_debug(free_me);
	return;
}


void llllobj_gunload_max(t_llllobj_out *cache, t_llll *inll)
{
	t_atomarray *deparsed_aa;
	t_atomarray *free_me;
	t_llll *old_ll;
	
	deparsed_aa = llll_deparse_to_aa(inll, LLLL_D_MAX);
	
	bach_atomic_lock(&cache->b_lock);
	old_ll = cache->b_ll;
	cache->b_ll = inll;
	free_me = cache->b_aa;
	llllobj_cache_text(cache, deparsed_aa);
	bach_atomic_unlock(&cache->b_lock);
	llll_free(old_ll);
	object_free_debug(free_me);
	return;
}

void llllobj_cache_text(t_llllobj_out *cache, t_atomarray *deparsed_aa)
{
	long ac;
	t_atom *av;
	atomarray_getatoms(deparsed_aa, &ac, &av);
	switch(atom_gettype(av)) {
		case A_FLOAT:
			if (ac > 1)
				llllobj_cache_list(cache, NULL, ac, av, deparsed_aa);
			else
				llllobj_cache_anything(cache, _sym_float, 1, av, deparsed_aa);
			break;
		case A_LONG:
			if (ac > 1)
				llllobj_cache_list(cache, NULL, ac, av, deparsed_aa);
			else
				llllobj_cache_anything(cache, _sym_int, 1, av, deparsed_aa);
			break;
		case A_SYM:
			llllobj_cache_anything(cache, atom_getsym(av), ac - 1, av + 1, deparsed_aa);
			break;
		default:
			break;
	}
}

void llllobj_gunload_native(t_llllobj_out *cache, t_llll *ll)
{
	t_atom *destroy_me;
	t_atom *new_atom = (t_atom *) bach_newptr(sizeof(t_atom));
	t_llll *old_ll;
	
#ifdef BACH_CHECK_LLLLS
	if (llll_check(ll))
		error("llllobj_gunload_native: bad llll");
#endif
	
	atom_setlong(new_atom, llll_phonenumber(ll));

	bach_atomic_lock(&cache->b_lock);
	destroy_me = cache->b_av;
	old_ll = cache->b_ll;
	cache->b_ll = ll;
	llllobj_cache_anything(cache, LLLL_NATIVE_MSG, 1, new_atom, NULL);
	bach_atomic_unlock(&cache->b_lock);

	llll_free(old_ll);
	bach_freeptr(destroy_me);
}

void llllobj_gunload_native_with_phonenumber(t_llllobj_out *cache, t_llll *ll, t_atom_ulong phonenumber)
{
	t_atom *destroy_me;
	t_atom *new_atom = (t_atom *) bach_newptr(sizeof(t_atom));
	t_llll *old_ll;

#ifdef BACH_CHECK_LLLLS
	if (llll_check(ll))
		error("llllobj_gunload_native_with_phonenumber: bad llll");
#endif
	
	atom_setlong(new_atom, phonenumber);

	bach_atomic_lock(&cache->b_lock);
	destroy_me = cache->b_av;
	old_ll = cache->b_ll;
	cache->b_ll = ll;
	llllobj_cache_anything(cache, LLLL_NATIVE_MSG, 1, new_atom, NULL);
	bach_atomic_unlock(&cache->b_lock);
	
	llll_free(old_ll);
	bach_freeptr(destroy_me);
}

void llllobj_gunload_llll(t_object *x, e_llllobj_obj_types type, t_llll *inll, long outnum)
{
	t_llllobj_out *cache;
	
	cache = llllobj_get_out(x, type) + outnum;

	switch (cache->b_type) {
		case LLLL_O_TEXT:
			llllobj_gunload_bttext(cache, inll);
			break;
		case LLLL_O_MAX:
			llllobj_gunload_max(cache, inll);
			break;
		case LLLL_O_NATIVE:
			llllobj_gunload_native(cache, inll);
			break;
		default:
			llll_release(inll);
			break;
	}
}

void llllobj_gunload_llll_with_phonenumber(t_object *x, e_llllobj_obj_types type, t_llll *inll, t_atom_ulong phonenumber, long outnum)
{
	t_llllobj_out *cache;
	
	cache = llllobj_get_out(x, type) + outnum;
	
	switch (cache->b_type) {
		case LLLL_O_TEXT:
			llllobj_gunload_bttext(cache, inll);
			break;
		case LLLL_O_MAX:
			llllobj_gunload_max(cache, inll);
			break;
		case LLLL_O_NATIVE:
			llllobj_gunload_native_with_phonenumber(cache, inll, phonenumber);
			break;
		default:
			llll_release(inll);
			break;
	}
}

void llllobj_gunload_wrap(t_object *x, e_llllobj_obj_types type, t_atom *in_aa_atom, ...)
{
	t_atom *in_ll_atom;
	t_atomarray *in_aa;
	long ac, i, outnum[LLLL_MAX_OUTLETS], *this_outnum;
	t_llllobj_out *out, *cache;
	va_list ap;

	va_start(ap, in_aa_atom);
	out = llllobj_get_out(x, type);
	in_aa = (t_atomarray *) atom_getobj(in_aa_atom);
	atomarray_getatoms(in_aa, &ac, &in_ll_atom);
	this_outnum = outnum;
	for (i = ac - 1; i >= 0; i--)
		*this_outnum++ = va_arg(ap, long);

	for (i = ac - 1; i >= 0; i --) {
		cache = out + *(--this_outnum);
		
		switch (cache->b_type) {
			case LLLL_O_TEXT:
				llllobj_gunload_bttext(cache, (t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
			case LLLL_O_MAX:
				llllobj_gunload_max(cache, (t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
			case LLLL_O_NATIVE:
				llllobj_gunload_native(cache, (t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
			default:
				llll_release((t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
		}
	}
	va_end(ap);

	object_free_debug(in_aa); 
}

void llllobj_gunload_array_range(t_object *x, e_llllobj_obj_types type, t_llll **arr, long minout, long maxout)
{
	t_llllobj_out *out, *cache;
	t_llll **this_arr;
	
	out = llllobj_get_out(x, type);
	
	for (this_arr = arr + maxout - minout, cache = out + maxout; this_arr >= arr; this_arr--, cache--) {
		
		switch (cache->b_type) {
			case LLLL_O_TEXT:
				llllobj_gunload_bttext(cache, *this_arr);
				break;
			case LLLL_O_MAX:
				llllobj_gunload_max(cache, *this_arr);
				break;
			case LLLL_O_NATIVE:
				llllobj_gunload_native(cache, *this_arr);
				break;
			default:
				llll_release((t_llll *) *this_arr);
				break;
		}

	}
}

void llllobj_gunload_wrap_range(t_object *x, e_llllobj_obj_types type, t_atom *in_aa_atom, long minout, long maxout)
{
	t_atom *in_ll_atom;
	long ac, i;
	t_atomarray *in_aa;
	t_llllobj_out *out, *cache;
	
	out = llllobj_get_out(x, type);
	
	in_aa = (t_atomarray *) atom_getobj(in_aa_atom);
	atomarray_getatoms(in_aa, &ac, &in_ll_atom);

	for (i = maxout - minout, cache = out + maxout; i >= 0; i--, cache--) {
		
		switch (cache->b_type) {
			case LLLL_O_TEXT:
				llllobj_gunload_bttext(cache, (t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
			case LLLL_O_MAX:
				llllobj_gunload_max(cache, (t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
			case LLLL_O_NATIVE:
				llllobj_gunload_native(cache, (t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
			default:
				llll_release((t_llll *) in_ll_atom[i].a_w.w_obj);
				break;
		}
	}
	object_free_debug(in_aa);
	
}

void llllobj_shoot_llll(t_object *x, e_llllobj_obj_types type, long outnum)
{
	t_symbol *out_msg;
	t_llllobj_out *out = llllobj_get_out(x, type) + outnum;	
	bach_atomic_lock(&out->b_lock);
	if (!(out_msg = out->b_msg)) {
		bach_atomic_unlock(&out->b_lock);
		return;
	}
	
	switch (out->b_type) {
			
		case LLLL_O_NATIVE: {
			t_atom out_av = *(out->b_av);
			t_llll *outll = out->b_ll;
#ifdef BACH_CHECK_LLLLS
			if (llll_check(outll))
				error("llllobj_shoot_llll: bad llll");
#endif
			llll_retain(outll);
			bach_atomic_unlock(&out->b_lock);
			outlet_anything(out->b_outlet, out_msg, 1, &out_av);
			llll_release(outll);
			break;
		}
			
		case LLLL_O_TEXT:
		case LLLL_O_MAX: {
			long out_ac = out->b_ac;
			if (out_ac != 0) {
				long out_size = out_ac * sizeof(t_atom);
				t_atom *out_av = (t_atom *) bach_newptr(out_size);
				bach_copyptr(out->b_av, out_av, out_size);
				bach_atomic_unlock(&out->b_lock);
				if (out_msg == _sym_list)
					outlet_list(out->b_outlet, NULL, MIN(out_ac, 32767), out_av);
				else
					outlet_anything(out->b_outlet, out_msg, MIN(out_ac, 32767), out_av);
				bach_freeptr(out_av);
			} else {
				bach_atomic_unlock(&out->b_lock);
				outlet_anything(out->b_outlet, out_msg, 0, NULL);
			}
			break;
		}
			
		default: {
			bach_atomic_unlock(&out->b_lock);
			break;
		}
			
	}
}


void llllobj_outlet_bang(t_object *x, e_llllobj_obj_types type, long outnum)
{
	t_llllobj_out *out = llllobj_get_out(x, type);
	outlet_bang(out[outnum].b_outlet);	
}

void llllobj_outlet_int(t_object *x, e_llllobj_obj_types type, long outnum, t_atom_long n)
{
	t_llllobj_out *out = llllobj_get_out(x, type);
	outlet_int(out[outnum].b_outlet, n);
}

void llllobj_outlet_float(t_object *x, e_llllobj_obj_types type, long outnum, double n)
{
	t_llllobj_out *out = llllobj_get_out(x, type);
	outlet_float(out[outnum].b_outlet, n);
}

void llllobj_outlet_anything(t_object *x, e_llllobj_obj_types type, long outnum, t_symbol *msg, long ac, t_atom *av)
{
	t_llllobj_out *out = llllobj_get_out(x, type);
	outlet_anything(out[outnum].b_outlet, msg, ac, av);
}

void llllobj_outlet_symbol_as_llll(t_object *x, e_llllobj_obj_types llllobj_obj_type, long outlet_num, t_symbol *sym) 
{
	t_llll *ll = llll_get();
	llll_appendsym(ll, sym, 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) x, llllobj_obj_type, outlet_num, ll);
	llll_free(ll);
}

void llllobj_outlet_symbol_couple_as_llll(t_object *x, e_llllobj_obj_types llllobj_obj_type, long outlet_num, t_symbol *sym1, t_symbol *sym2)
{
	t_llll *ll = llll_get();
	llll_appendsym(ll, sym1, 0, WHITENULL_llll);
	llll_appendsym(ll, sym2, 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) x, llllobj_obj_type, outlet_num, ll);
	llll_free(ll);
}

void llllobj_outlet_llll_with_phonenumber(t_object *x, e_llllobj_obj_types type, t_llll *inll, t_atom_ulong phonenumber, long outnum)
{
	t_llllobj_out *cache;
	t_atom outatom;
	
	cache = llllobj_get_out(x, type) + outnum;

	switch (cache->b_type) {
		case LLLL_O_TEXT:
		case LLLL_O_MAX:
			llllobj_outlet_llll(x, type, outnum, inll);
			break;
			
		case LLLL_O_NATIVE:
#ifdef BACH_CHECK_LLLLS
			if (llll_retrieve_from_phonenumber_and_retain(phonenumber) != inll)
				error("llllobj_outlet_llll_with_phonenumber: bad llll");
			llll_release(inll);
#endif
			atom_setlong(&outatom, phonenumber);
			outlet_anything(cache->b_outlet, LLLL_NATIVE_MSG, 1, &outatom);
			break;
			
		default:
			break;
	}
}

void llllobj_outlet_llll(t_object *x, e_llllobj_obj_types type, long outnum, t_llll *in_ll, long flags)
{
	t_atom outatom;
	long ac = 0;
	t_llllobj_out *out, *cache;
	t_atomarray *out_aa = NULL;
	
	out = llllobj_get_out(x, type);
	cache = out + outnum;
	
	switch (cache->b_type) {
			
		case LLLL_O_TEXT:
		case LLLL_O_MAX: {
			t_atom *outlist;
			if (in_ll) {
				out_aa = llll_deparse_to_aa(in_ll,
											(cache->b_type == LLLL_O_TEXT ? LLLL_D_QUOTE | LLLL_D_MAX : LLLL_D_MAX) | flags);
				atomarray_getatoms(out_aa, &ac, &outlist);
				
				if (ac == 0) {
					ac = 1;
					atom_setsym(outlist, _llllobj_sym_null);
				}
				ac = MIN(ac, 32767);
				switch(atom_gettype(outlist)) {
					case A_FLOAT:
						if (ac > 1)
							outlet_list(cache->b_outlet, NULL, ac, outlist);
						else
							outlet_anything(cache->b_outlet, _sym_float, 1, outlist);
						break;
					case A_LONG:
						if (ac > 1)
							outlet_list(cache->b_outlet, NULL, ac, outlist);
						else
							outlet_anything(cache->b_outlet, _sym_int, 1, outlist);
						break;
					case A_SYM:
						outlet_anything(cache->b_outlet, atom_getsym(outlist), ac - 1, outlist + 1);
						break;
					default:
						break;
				}
				if (out_aa)
					object_free_debug(out_aa);
			}
			break;
		}
			
		case LLLL_O_NATIVE: {
#ifdef BACH_CHECK_LLLLS
			if (llll_check(in_ll))
				error("llllobj_outlet_llll: bad llll");
#endif
			atom_setlong(&outatom, llll_phonenumber(in_ll));
			outlet_anything(cache->b_outlet, LLLL_NATIVE_MSG, 1, &outatom);
			break;
		}
			
		default:
			break;
	}

}

void llllobj_cache_list(t_llllobj_out *cache, t_symbol *msg, long ac, t_atom *av, void *thing)
{
	cache->b_msg = _sym_list;
	cache->b_ac = ac;
	cache->b_av = av;
	cache->b_aa = (t_atomarray *) thing;
}

void llllobj_cache_anything(t_llllobj_out *cache, t_symbol *msg, long ac, t_atom *av, void *thing)
{
	cache->b_msg = msg;
	cache->b_ac = ac;
	cache->b_av = av;
	cache->b_aa = (t_atomarray *) thing;
}

void llllobj_obj_free(t_llllobj_object *x)
{
	long i;
	long numouts = x->l_numouts;
	long numstores = x->l_numstores;
	t_llllobj_out *this_out = x->l_out;
	t_llllobj_store *this_store = x->l_incache;
	
	if (this_out) {
		for (i = 0; i < numouts; i++, this_out++) {
			if (this_out->b_ll)
				llll_release(this_out->b_ll);
			if (this_out->b_type == LLLL_O_NATIVE && this_out->b_av)
				bach_freeptr(this_out->b_av);
			else if (this_out->b_type == LLLL_O_TEXT)
				object_free_debug(this_out->b_aa);
//			if (this_out->b_lock)
//				systhread_mutex_free_debug(this_out->b_lock);
		}
	}
	
	if (this_store) {
		for (i = 0; i < numstores; i++, this_store++) {
			llll_release(this_store->s_ll);
		}
	}
	if (x->l_out)
		bach_freeptr(x->l_out);
	if (x->l_incache)
		bach_freeptr(x->l_incache);
	llll_free(x->l_dictll);
	bach_remove_from_memmap(x);
	llllobj_free_release_pool((t_object *) x, LLLL_OBJ_VANILLA);
}

void llllobj_pxobj_free(t_llllobj_pxobject *x)
{
	long i;
	long numouts = x->l_numouts;
	long numstores = x->l_numstores;
	t_llllobj_out *this_out = x->l_out;
	t_llllobj_store *this_store = x->l_incache;
	
	if (this_out) {
		for (i = 0; i < numouts; i++, this_out++) {
			if (this_out->b_ll)
				llll_release(this_out->b_ll);
			if (this_out->b_type == LLLL_O_NATIVE && this_out->b_av)
				bach_freeptr(this_out->b_av);
			else if (this_out->b_type == LLLL_O_TEXT)
				object_free_debug(this_out->b_aa);
//			if (this_out->b_lock)
//				systhread_mutex_free_debug(this_out->b_lock);
		}
	}
	
	if (this_store) {
		for (i = 0; i < numstores; i++, this_store++) {
			llll_release(this_store->s_ll);
		}
	}
	if (x->l_out)
		bach_freeptr(x->l_out);
	if (x->l_incache)
		bach_freeptr(x->l_incache);
	llll_free(x->l_dictll);
	bach_remove_from_memmap(x);
	llllobj_free_release_pool((t_object *) x, LLLL_OBJ_MSP);
}

void llllobj_jbox_free(t_llllobj_jbox *x)
{
	long i;
	long numouts = x->l_numouts;
	long numstores = x->l_numstores;
	t_llllobj_out *this_out = x->l_out;
	t_llllobj_store *this_store = x->l_incache;
	
	if (this_out) {
		for (i = 0; i < numouts; i++, this_out++) {
			if (this_out->b_ll)
				llll_release(this_out->b_ll);
			if (this_out->b_type == LLLL_O_NATIVE && this_out->b_av)
				bach_freeptr(this_out->b_av);
			else if (this_out->b_type == LLLL_O_TEXT)
				object_free_debug(this_out->b_aa);
//			if (this_out->b_lock)
//				systhread_mutex_free_debug(this_out->b_lock);
		}
	}
	
	if (this_store) {
		for (i = 0; i < numstores; i++, this_store++) {
			llll_release(this_store->s_ll);
		}
	}
	if (x->l_out)
		bach_freeptr(x->l_out);
	if (x->l_incache)
		bach_freeptr(x->l_incache);
	llll_free(x->l_dictll);
	bach_remove_from_memmap(x);
	llllobj_free_release_pool((t_object *) x, LLLL_OBJ_UI);
}

void llllobj_pxjbox_free(t_llllobj_pxjbox *x)
{
	long i;
	long numouts = x->l_numouts;
	long numstores = x->l_numstores;
	t_llllobj_out *this_out = x->l_out;
	t_llllobj_store *this_store = x->l_incache;
	
	if (this_out) {
		for (i = 0; i < numouts; i++, this_out++) {
			if (this_out->b_ll)
				llll_release(this_out->b_ll);
			if (this_out->b_type == LLLL_O_NATIVE && this_out->b_av)
				bach_freeptr(this_out->b_av);
			else if (this_out->b_type == LLLL_O_TEXT)
				object_free_debug(this_out->b_aa);
//			if (this_out->b_lock)
//				systhread_mutex_free_debug(this_out->b_lock);
		}
	}
	
	if (this_store) {
		for (i = 0; i < numstores; i++, this_store++) {
			llll_release(this_store->s_ll);
		}
	}
	if (x->l_out)
		bach_freeptr(x->l_out);
	if (x->l_incache)
		bach_freeptr(x->l_incache);
	llll_free(x->l_dictll);
	bach_remove_from_memmap(x);
	llllobj_free_release_pool((t_object *) x, LLLL_OBJ_UIMSP);
}

t_max_err llllobj_check_version(t_atom_ulong version)
{
	bach = (t_bach *) gensym("bach")->s_thing; // initialize global variable for this object!
	if (bach == NULL) {
		object_new_typed(CLASS_NOBOX, gensym("bach"), 0, NULL);
		bach = (t_bach *) gensym("bach")->s_thing; // initialize global variable for this object!
	}
	if (bach == NULL || NOGOOD(bach) || ob_sym(bach) != gensym("bach"))
		return 0;
	return bach->b_llll_version != version;
}

t_max_err llllobj_test(void)
{
	t_llll *empty;
	t_llllelem *nothing;

	if (!bach)
		return MAX_ERR_GENERIC;
	bach_setup(bach);
	empty = llll_get();
	nothing = llllelem_get();
	nothing->l_hatom.h_type = H_NOTHING;
	if (!empty || !nothing) {
		error("bach extensions not correctly installed");
		return MAX_ERR_GENERIC;
	}
	llll_free(empty);
	llllelem_free(nothing);
	return MAX_ERR_NONE;
}

// NB: outlets are declared r2l!!!
t_max_err llllobj_obj_setup(t_llllobj_object *x, long stores, const char *outlets, ...)
{
	va_list ap;
	long i, numoutlets;
	const char *this_outlet;
	char *selector = NULL;
	t_llllobj_store *this_incache;
	t_llllobj_out *this_out;
	char *this_outtype = NULL;
	t_llll *empty_llll = llll_get();
	t_uint32 empty_phonenum = llll_phonenumber(empty_llll);
	
	x->l_running = 1;
	x->l_numouts = numoutlets = strlen(outlets);
	
	for (i = 0; i < numoutlets; i++)
		x->l_numllllouts += (outlets[i] == '4');

	if (x->l_numllllouts) {
		char *outtypes;
		long changed;
		if (!x->l_outtypes)
			x->l_outtypes = gensym("");
		outtypes = x->l_outtypes->s_name;
		changed = llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_VANILLA, &outtypes, 0);
		if (changed) {
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		}
		this_outtype = x->l_outtypes->s_name + x->l_numllllouts - 1;
	}
	
	if (stores) {
		x->l_numstores = stores;
		x->l_incache = (t_llllobj_store *) bach_newptrclear(stores * sizeof(t_llllobj_store));
	}
	
	va_start(ap, outlets);
	for (i = 0, this_incache = x->l_incache; i < stores; i++, this_incache++) {
		llll_retain(empty_llll);
		this_incache->s_ll = empty_llll;
	}
	if (numoutlets && !x->l_out)
		x->l_out = (t_llllobj_out *) bach_newptrclear(numoutlets * sizeof(t_llllobj_out));
	
	for (this_outlet = outlets, this_out = x->l_out + numoutlets - 1; *this_outlet; this_out--, this_outlet++) {
//		systhread_mutex_new_debug(&this_out->b_lock, 0);
		switch(*this_outlet) {
			case 'b':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'B':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_msg = _sym_bang;
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'i':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'I':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_msg = _sym_int;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setlong(this_out->b_av, 0);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'f':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'F':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_msg = _sym_float;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setfloat(this_out->b_av, 0);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'l':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'L':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_msg = _sym_list;
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'a':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, va_arg(ap, char*));
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case 'A':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, selector = va_arg(ap, char*));
				this_out->b_msg = gensym(selector);
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case '4':
				switch (*this_outtype) {
					case 't': case 'T':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);	
						this_out->b_type = LLLL_O_TEXT;
						break;
					case 'm': case 'M':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_MAX;
						break;
					case 'n': case 'N':
						this_out->b_msg = LLLL_NATIVE_MSG;
						this_out->b_ac = 1;
						this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
						this_out->b_ll = empty_llll;
						atom_setlong(this_out->b_av, empty_phonenum);
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_NATIVE;
						break;
				}
				this_outtype--;
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, NULL);
				break;
		}
	}
	va_end(ap);
	llll_release(empty_llll); // for the llll creation
	object_attach_byptr_register(x, x, CLASS_BOX);
	x->l_running = 1;
	x->l_release = hashtab_new_debug(0);
	hashtab_flags(x->l_release, OBJ_FLAG_DATA);
	object_method(x->l_release, _sym_readonly, 1);
	return MAX_ERR_NONE;
}

t_max_err llllobj_pxobj_setup(t_llllobj_pxobject *x, long stores, const char *outlets, ...)
{
	va_list ap;
	long i, numoutlets;
	const char *this_outlet;
	char *selector = NULL;
	t_llllobj_store *this_incache;
	t_llllobj_out *this_out;
	char *this_outtype = NULL;
	t_llll *empty_llll = llll_get();
	t_uint32 empty_phonenum = llll_phonenumber(empty_llll);
	
	x->l_running = 1;
	x->l_numouts = numoutlets = strlen(outlets);
	
	for (i = 0; i < numoutlets; i++)
		x->l_numllllouts += (outlets[i] == '4');
	
	if (x->l_numllllouts) {
		char *outtypes;
		long changed;
		if (!x->l_outtypes)
			x->l_outtypes = gensym("");
		outtypes = x->l_outtypes->s_name;
		changed = llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_MSP, &outtypes, 0);
		if (changed) {
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		}
		this_outtype = x->l_outtypes->s_name + x->l_numllllouts - 1;
	}
	
	if (stores) {
		x->l_numstores = stores;
		x->l_incache = (t_llllobj_store *) bach_newptrclear(stores * sizeof(t_llllobj_store));
	}
	
	va_start(ap, outlets);
	for (i = 0, this_incache = x->l_incache; i < stores; i++, this_incache++) {
		llll_retain(empty_llll);
		this_incache->s_ll = empty_llll;
	}
	if (numoutlets && !x->l_out)
		x->l_out = (t_llllobj_out *) bach_newptrclear(numoutlets * sizeof(t_llllobj_out));
	
	for (this_outlet = outlets, this_out = x->l_out + numoutlets - 1; *this_outlet; this_out--, this_outlet++) {
//		systhread_mutex_new_debug(&this_out->b_lock, 0);
		switch(*this_outlet) {
			case 'b':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'B':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_msg = _sym_bang;
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'i':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'I':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_msg = _sym_int;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setlong(this_out->b_av, 0);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'f':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'F':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_msg = _sym_float;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setfloat(this_out->b_av, 0);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'l':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'L':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_msg = _sym_list;
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'a':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, va_arg(ap, char*));
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case 'A':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, selector = va_arg(ap, char*));
				this_out->b_msg = gensym(selector);
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case 's':
				if (this_out->b_outlet == NULL)
					outlet_new(x, "signal");
				this_out->b_type = LLLL_O_SIGNAL;
				break;
			case '4':
				switch (*this_outtype) {
					case 't': case 'T':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_TEXT;
						break;
					case 'm': case 'M':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_MAX;
						break;
					case 'n': case 'N':
						this_out->b_msg = LLLL_NATIVE_MSG;
						this_out->b_ac = 1;
						this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
						this_out->b_ll = empty_llll;
						atom_setlong(this_out->b_av, empty_phonenum);
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_NATIVE;
						break;
				}
				this_outtype--;
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, NULL);
				break;
		}
	}
	va_end(ap);
	llll_release(empty_llll); // for the llll creation
	object_attach_byptr_register(x, x, CLASS_BOX);
	x->l_running = 1;
	x->l_release = hashtab_new_debug(0);
	hashtab_flags(x->l_release, OBJ_FLAG_DATA);
	object_method(x->l_release, _sym_readonly, 1);
	return MAX_ERR_NONE;
}

t_max_err llllobj_jbox_setup(t_llllobj_jbox *x, long stores, const char *outlets, ...)
{
	va_list ap;
	long i, numoutlets;
	const char *this_outlet;
	char *selector = NULL;
	t_llllobj_store *this_incache;
	t_llllobj_out *this_out;
	char *this_outtype = NULL;
	t_llll *empty_llll = llll_get();
	t_uint32 empty_phonenum = llll_phonenumber(empty_llll);
	
	x->l_running = 1;
	x->l_numouts = numoutlets = strlen(outlets);
	
	for (i = 0; i < numoutlets; i++)
		x->l_numllllouts += (outlets[i] == '4');
	
	if (x->l_numllllouts) {
		char *outtypes;
		long changed;
		if (!x->l_outtypes)
			x->l_outtypes = gensym("");
		outtypes = x->l_outtypes->s_name;
		changed = llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_UI, &outtypes, 0);
		if (changed) {
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		}
		this_outtype = x->l_outtypes->s_name + x->l_numllllouts - 1;
	}
	
	if (stores) {
		x->l_numstores = stores;
		x->l_incache = (t_llllobj_store *) bach_newptrclear(stores * sizeof(t_llllobj_store));
	}
	
	va_start(ap, outlets);
	for (i = 0, this_incache = x->l_incache; i < stores; i++, this_incache++) {
		llll_retain(empty_llll);
		this_incache->s_ll = empty_llll;
	}
	if (numoutlets && !x->l_out)
		x->l_out = (t_llllobj_out *) bach_newptrclear(numoutlets * sizeof(t_llllobj_out));
	
	for (this_outlet = outlets, this_out = x->l_out + numoutlets - 1; *this_outlet; this_out--, this_outlet++) {
//		systhread_mutex_new_debug(&this_out->b_lock, 0);
		switch(*this_outlet) {
			case 'b':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'B':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_msg = _sym_bang;
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'i':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'I':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_msg = _sym_int;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setlong(this_out->b_av, 0);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'f':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'F':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_msg = _sym_float;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setfloat(this_out->b_av, 0);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'l':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'L':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_msg = _sym_list;
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'a':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, va_arg(ap, char*));
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case 'A':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, selector = va_arg(ap, char*));
				this_out->b_msg = gensym(selector);
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case '4':
				switch (*this_outtype) {
					case 't': case 'T':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_TEXT;
						break;
					case 'm': case 'M':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_MAX;
						break;
					case 'n': case 'N':
						this_out->b_msg = LLLL_NATIVE_MSG;
						this_out->b_ac = 1;
						this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
						this_out->b_ll = empty_llll;
						atom_setlong(this_out->b_av, empty_phonenum);
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_NATIVE;
						break;
				}
				this_outtype--;
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, NULL);
				break;
		}
	}
	va_end(ap);
	llll_release(empty_llll); // for the llll creation
	object_attach_byptr_register(x, x, CLASS_BOX);
	x->l_running = 1;
	x->l_release = hashtab_new_debug(0);
	hashtab_flags(x->l_release, OBJ_FLAG_DATA);
	object_method(x->l_release, _sym_readonly, 1);
	return MAX_ERR_NONE;
}

t_max_err llllobj_pxjbox_setup(t_llllobj_pxjbox *x, long stores, const char *outlets, ...)
{
	va_list ap;
	long i, numoutlets;
	const char *this_outlet;
	char *selector = NULL;
	t_llllobj_store *this_incache;
	t_llllobj_out *this_out;
	char *this_outtype = NULL;
	t_llll *empty_llll = llll_get();
	t_uint32 empty_phonenum = llll_phonenumber(empty_llll);
	
	x->l_running = 1;
	x->l_numouts = numoutlets = strlen(outlets);
	
	for (i = 0; i < numoutlets; i++)
		x->l_numllllouts += (outlets[i] == '4');
	
	if (x->l_numllllouts) {
		char *outtypes;
		long changed;
		if (!x->l_outtypes)
			x->l_outtypes = gensym("");
		outtypes = x->l_outtypes->s_name;
		changed = llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_UIMSP, &outtypes, 0);
		if (changed) {
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		}
		this_outtype = x->l_outtypes->s_name + x->l_numllllouts - 1;
	}
	
	if (stores) {
		x->l_numstores = stores;
		x->l_incache = (t_llllobj_store *) bach_newptrclear(stores * sizeof(t_llllobj_store));
	}
	
	va_start(ap, outlets);
	for (i = 0, this_incache = x->l_incache; i < stores; i++, this_incache++) {
		llll_retain(empty_llll);
		this_incache->s_ll = empty_llll;
	}
	if (numoutlets && !x->l_out)
		x->l_out = (t_llllobj_out *) bach_newptrclear(numoutlets * sizeof(t_llllobj_out));
	
	for (this_outlet = outlets, this_out = x->l_out + numoutlets - 1; *this_outlet; this_out--, this_outlet++) {
//		systhread_mutex_new_debug(&this_out->b_lock, 0);
		switch(*this_outlet) {
			case 'b':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'B':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = bangout(x);
				this_out->b_msg = _sym_bang;
				this_out->b_type = LLLL_O_BANG;
				break;
			case 'i':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'I':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = intout(x);
				this_out->b_msg = _sym_int;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setlong(this_out->b_av, 0);
				this_out->b_type = LLLL_O_LONG;
				break;
			case 'f':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'F':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = floatout(x);
				this_out->b_msg = _sym_float;
				this_out->b_ac = 1;
				this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
				atom_setfloat(this_out->b_av, 0);
				this_out->b_type = LLLL_O_FLOAT;
				break;
			case 'l':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'L':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = listout(x);
				this_out->b_msg = _sym_list;
				this_out->b_type = LLLL_O_LIST;
				break;
			case 'a':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, va_arg(ap, char*));
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case 'A':
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, selector = va_arg(ap, char*));
				this_out->b_msg = gensym(selector);
				this_out->b_type = LLLL_O_ANYTHING;
				break;
			case 's':
				if (this_out->b_outlet == NULL)
					outlet_new(x, "signal");
				this_out->b_type = LLLL_O_SIGNAL;
				break;
			case '4':
				switch (*this_outtype) {
					case 't': case 'T':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_TEXT;
						break;
					case 'm': case 'M':
						this_out->b_msg = _llllobj_sym_null;
						this_out->b_ll = empty_llll;
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_MAX;
						break;
					case 'n': case 'N':
						this_out->b_msg = LLLL_NATIVE_MSG;
						this_out->b_ac = 1;
						this_out->b_av = (t_atom *) bach_newptrclear(sizeof(t_atom));
						this_out->b_ll = empty_llll;
						atom_setlong(this_out->b_av, empty_phonenum);
						llll_retain(empty_llll);
						this_out->b_type = LLLL_O_NATIVE;
						break;
				}
				this_outtype--;
				if (this_out->b_outlet == NULL)
					this_out->b_outlet = outlet_new(x, NULL);
				break;
		}
	}
	va_end(ap);
	llll_release(empty_llll); // for the llll creation
	object_attach_byptr_register(x, x, CLASS_BOX);
	x->l_running = 1;
	x->l_release = hashtab_new_debug(0);
	hashtab_flags(x->l_release, OBJ_FLAG_DATA);
	object_method(x->l_release, _sym_readonly, 1);
	return MAX_ERR_NONE;
}

// returns the stored llll if successful, 0 if not
t_llll *llllobj_parse_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store)
{
	t_llll *inlist = llllobj_parse_llll(x, type, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!inlist)
		return NULL;
	llllobj_store_llll(x, type, inlist, store); // with this I lose ownership of the list
	return inlist;
}

// parse the incoming llll, and if successful retain it, store it and return it.
// otherwise, return NULL
t_llll *llllobj_parse_retain_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store)
{
	t_llll *inlist = llllobj_parse_llll(x, type, msg, ac, av, LLLL_PARSE_RETAIN);
	if (!inlist)
		return NULL;
	llll_retain(inlist); // one retain for the store, one for us
	llllobj_store_llll(x, type, inlist, store); 
	return inlist;
}

// parse the incoming llll, and if successful store it and return a clone of it.
// otherwise, return NULL
t_llll *llllobj_parse_clone_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store)
{
	t_llll *inlist = llllobj_parse_llll(x, type, msg, ac, av, LLLL_PARSE_RETAIN); // now we have it
	t_llll *outlist;
	if (!inlist)
		return NULL;
	outlist = llll_clone(inlist);
	llllobj_store_llll(x, type, inlist, store); // with this I lose ownership of inlist
	return outlist;
}

t_llll *llllobj_parse_wrap_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store, t_atom_long lvls)
{
	t_llll *inlist, *wrapped;
	if (lvls == 0)
		return llllobj_parse_and_store(x, type, msg, ac, av, store);
	inlist = llllobj_parse_llll(x, type, msg, ac, av, LLLL_PARSE_RETAIN); // now we have it
	if (!inlist)
		return NULL;
	wrapped = llll_clone(inlist);
	llll_release(inlist); // we don't need it anymore
	llll_wrap(&wrapped, lvls);
	llllobj_store_llll(x, type, wrapped, store); // with this I lose ownership of the list
	return wrapped;
}

t_llll *llllobj_parse_wrap_retain_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store, t_atom_long lvls)
{
	t_llll *inlist, *wrapped;
	if (lvls == 0)
		return llllobj_parse_retain_and_store(x, type, msg, ac, av, store);
	inlist = llllobj_parse_llll(x, type, msg, ac, av, LLLL_PARSE_RETAIN); // now we have it
	if (!inlist)
		return NULL;
	wrapped = llll_clone(inlist);
	llll_release(inlist); // we don't need it anymore
	llll_wrap(&wrapped, lvls);
	llll_retain(wrapped);
	llllobj_store_llll(x, type, wrapped, store); // with this I lose ownership of the list
	return wrapped;
}

t_llll *llllobj_parse_wrap_clone_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store, t_atom_long lvls)
{
	t_llll *inlist, *wrapped, *outlist;
	if (lvls == 0)
		return llllobj_parse_clone_and_store(x, type, msg, ac, av, store);
	inlist = llllobj_parse_llll(x, type, msg, ac, av, LLLL_PARSE_RETAIN); // now we have it
	if (!inlist)
		return NULL;
	wrapped = llll_clone(inlist);
	llll_release(inlist); // we don't need it anymore
	llll_wrap(&wrapped, lvls);
	outlist = llll_clone(wrapped);
	llllobj_store_llll(x, type, wrapped, store); // with this I lose ownership of the list
	return outlist;
}

void llllobj_store_llll(t_object *x, e_llllobj_obj_types type, t_llll *ll, long store_num)
{
	t_llllobj_store *store = llllobj_get_incache(x, type) + store_num;
	t_llll *kill_me;
	bach_atomic_lock(&store->s_lock);
	kill_me = store->s_ll;
	store->s_ll = ll;
	bach_atomic_unlock(&store->s_lock);
	llll_free(kill_me);
}

void llllobj_clear_all_stores(t_object *x, e_llllobj_obj_types type)
{
	t_llllobj_store *store = llllobj_get_incache(x, type);
	long numstores = llllobj_get_numstores(x, type);
	long i;
	t_llll *empty = llll_get();
	//empty->l_count = 0;
	for (i = 0; i < numstores; i++, store++) {
		t_llll *kill_me;
		bach_atomic_lock(&store->s_lock);
		kill_me = store->s_ll;
		store->s_ll = empty;
		llll_retain(empty);
		bach_atomic_unlock(&store->s_lock);
		llll_free(kill_me);
	}
	llll_release(empty);
}

void llllobj_clear_all_outs(t_object *x, e_llllobj_obj_types type)
{
	t_llllobj_out *cache = llllobj_get_out(x, type);
	long numouts = llllobj_get_numouts(x, type);
	long i;
	t_llll *empty = llll_get();
	//empty->l_count = 0;
	for (i = 0; i < numouts; i++, cache++) {
		
		switch (cache->b_type) {
			case LLLL_O_TEXT:
				llll_retain(empty);
				llllobj_gunload_bttext(cache, empty);
				break;
			case LLLL_O_MAX:
				llll_retain(empty);
				llllobj_gunload_max(cache, empty);
				break;
			case LLLL_O_NATIVE:
				llll_retain(empty);
				llllobj_gunload_native(cache, empty);
				break;
			default:
				break;
		}
	}
	llll_release(empty);
}

void llllobj_clear_all_stores_and_outs(t_object *x, e_llllobj_obj_types type)
{
	llllobj_clear_all_stores(x, type);
	llllobj_clear_all_outs(x, type);
}

long llllobj_conform_outtypes(t_object *x, e_llllobj_obj_types type, char **outtypes, long accept_minus)
{
	long numlllloutlets = llllobj_get_numllllouts(x, type);
	long len_outtypes = strlen(*outtypes);
	long i;
	long changed = 0;
	if (accept_minus) {
		char *old_outtypes = *outtypes;
		*outtypes = (char *) bach_newptr(numlllloutlets + 1);
		strncpy_zero(*outtypes, old_outtypes, numlllloutlets + 1);
		changed = 1;
	}
	for (i = 0; i < len_outtypes && i < numlllloutlets; i++) {
		switch ((*outtypes)[i]) {
			case 't': case 'm': case 'n': case 'x':
				break;
			case 'T':
				if (!changed) {
					char *old_outtypes = *outtypes;
					*outtypes = (char *) bach_newptr(numlllloutlets + 1);
					strncpy_zero(*outtypes, old_outtypes, numlllloutlets + 1);
					changed = 1;
				}
				(*outtypes)[i] = 't';
				break;
			case 'X':
				if (!changed) {
					char *old_outtypes = *outtypes;
					*outtypes = (char *) bach_newptr(numlllloutlets + 1);
					strncpy_zero(*outtypes, old_outtypes, numlllloutlets + 1);
					changed = 1;
				}
				(*outtypes)[i] = 'x';
				break;
			case '-':
				if (!accept_minus) {
					if (!changed) {
						char *old_outtypes = *outtypes;
						*outtypes = (char *) bach_newptr(numlllloutlets + 1);
						strncpy_zero(*outtypes, old_outtypes, numlllloutlets + 1);
						changed = 1;
					}
					(*outtypes)[i] = 'n';
				}
				break;
			default:
				if (!changed) {
					char *old_outtypes = *outtypes;
					*outtypes = (char *) bach_newptr(numlllloutlets + 1);
					strncpy_zero(*outtypes, old_outtypes, numlllloutlets + 1);
					changed = 1;
				}
				(*outtypes)[i] = 'n';
				break;
		}
	}
	if (len_outtypes == numlllloutlets)
		return changed;
	if (len_outtypes > numlllloutlets) {
		if (!changed) {
			char *old_outtypes = *outtypes;
			*outtypes = (char *) bach_newptr(numlllloutlets + 1);
			strncpy_zero(*outtypes, old_outtypes, numlllloutlets + 1);
			changed = 1;
		}
		(*outtypes)[i] = 0;
		return changed;
	}
	char pad = len_outtypes > 0 ? (*outtypes)[i - 1] : 'n';
	if (!changed) {
		char *old_outtypes = *outtypes;
		*outtypes = (char *) bach_newptr(numlllloutlets + 1);
		strncpy_zero(*outtypes, old_outtypes, numlllloutlets + 1);
		changed = 1;
	}
	for ( ; i < numlllloutlets; i++)
		(*outtypes)[i] = pad;
	(*outtypes)[i] = 0;
	return changed;
}

t_max_err llllobj_obj_setout(t_llllobj_object *x, t_object *attr, long argc, t_atom *argv)
{
	char *this_outtype;
	char *outtypes;
	t_llllobj_out *this_out;
	long numlllloutlets = x->l_numllllouts;
	t_symbol *sym;
	if (argc && atom_gettype(argv) == A_SYM && (sym = argv->a_w.w_sym)) {
		if (x->l_running) {
			outtypes = sym->s_name;
			llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_VANILLA, &outtypes, 1);
			this_outtype = outtypes + numlllloutlets - 1;
			for (this_out = x->l_out + numlllloutlets - 1; this_out >= x->l_out ; this_out--) {
				if (this_out->b_type == LLLL_O_NATIVE || this_out->b_type == LLLL_O_TEXT || this_out->b_type == LLLL_O_MAX || this_out->b_type == LLLL_O_DISABLED) {
					switch (*this_outtype) {
						case 't': llllobj_change_out_type(this_out, LLLL_O_TEXT);		break;
						case 'm': llllobj_change_out_type(this_out, LLLL_O_MAX);		break;
						case 'x': llllobj_change_out_type(this_out, LLLL_O_DISABLED);	break;
						case 'n': llllobj_change_out_type(this_out, LLLL_O_NATIVE);		break;
						case '-':
							switch (this_out->b_type) {
								case LLLL_O_NATIVE:		*this_outtype = 'n';	break;
								case LLLL_O_TEXT:		*this_outtype = 't';	break;
								case LLLL_O_MAX:		*this_outtype = 'm';	break;
								case LLLL_O_DISABLED:	*this_outtype = 'x';	break;
								default: break;
							}
							break;
					}
					this_outtype--;
				}
			}
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		} else {
			x->l_outtypes = sym;
		}
	}
	return MAX_ERR_NONE;
}

t_max_err llllobj_jbox_setout(t_llllobj_jbox *x, t_object *attr, long argc, t_atom *argv)
{
	char *this_outtype;
	char *outtypes;
	t_llllobj_out *this_out;
	long numlllloutlets = x->l_numllllouts;
	t_symbol *sym;
	if (argc && atom_gettype(argv) == A_SYM && (sym = argv->a_w.w_sym)) {
		if (x->l_running) {
			outtypes = sym->s_name;
			llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_UI, &outtypes, 1);
			this_outtype = outtypes + numlllloutlets - 1;
			for (this_out = x->l_out + numlllloutlets - 1; this_out >= x->l_out ; this_out--) {
				if (this_out->b_type == LLLL_O_NATIVE || this_out->b_type == LLLL_O_TEXT || this_out->b_type == LLLL_O_MAX || this_out->b_type == LLLL_O_DISABLED) {
					switch (*this_outtype) {
						case 't': llllobj_change_out_type(this_out, LLLL_O_TEXT);		break;
						case 'm': llllobj_change_out_type(this_out, LLLL_O_MAX);		break;
						case 'x': llllobj_change_out_type(this_out, LLLL_O_DISABLED);	break;
						case 'n': llllobj_change_out_type(this_out, LLLL_O_NATIVE);		break;
						case '-':
							switch (this_out->b_type) {
								case LLLL_O_NATIVE:		*this_outtype = 'n';	break;
								case LLLL_O_TEXT:		*this_outtype = 't';	break;
								case LLLL_O_MAX:		*this_outtype = 'm';	break;
								case LLLL_O_DISABLED:	*this_outtype = 'x';	break;
								default: break;
							}
							break;
					}
					this_outtype--;
				}
			}
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		} else {
			x->l_outtypes = sym;
		}
	}
	return MAX_ERR_NONE;
}

t_max_err llllobj_pxobj_setout(t_llllobj_pxobject *x, t_object *attr, long argc, t_atom *argv)
{
	char *this_outtype;
	char *outtypes;
	t_llllobj_out *this_out;
	long numlllloutlets = x->l_numllllouts;
	t_symbol *sym;
	if (argc && atom_gettype(argv) == A_SYM && (sym = argv->a_w.w_sym)) {
		if (x->l_running) {
			outtypes = sym->s_name;
			llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_UI, &outtypes, 1);
			this_outtype = outtypes + numlllloutlets - 1;
			for (this_out = x->l_out + numlllloutlets - 1; this_out >= x->l_out ; this_out--) {
				if (this_out->b_type == LLLL_O_NATIVE || this_out->b_type == LLLL_O_TEXT || this_out->b_type == LLLL_O_MAX || this_out->b_type == LLLL_O_DISABLED) {
					switch (*this_outtype) {
						case 't': llllobj_change_out_type(this_out, LLLL_O_TEXT);		break;
						case 'm': llllobj_change_out_type(this_out, LLLL_O_MAX);		break;
						case 'x': llllobj_change_out_type(this_out, LLLL_O_DISABLED);	break;
						case 'n': llllobj_change_out_type(this_out, LLLL_O_NATIVE);		break;
						case '-':
							switch (this_out->b_type) {
								case LLLL_O_NATIVE:		*this_outtype = 'n';	break;
								case LLLL_O_TEXT:		*this_outtype = 't';	break;
								case LLLL_O_MAX:		*this_outtype = 'm';	break;
								case LLLL_O_DISABLED:	*this_outtype = 'x';	break;
								default: break;
							}
							break;
					}
					this_outtype--;
				}
			}
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		} else {
			x->l_outtypes = sym;
		}
	}
	return MAX_ERR_NONE;
}

t_max_err llllobj_pxjbox_setout(t_llllobj_pxjbox *x, t_object *attr, long argc, t_atom *argv)
{
	char *this_outtype;
	char *outtypes;
	t_llllobj_out *this_out;
	long numlllloutlets = x->l_numllllouts;
	t_symbol *sym;
	if (argc && atom_gettype(argv) == A_SYM && (sym = argv->a_w.w_sym)) {
		if (x->l_running) {
			outtypes = sym->s_name;
			llllobj_conform_outtypes((t_object *) x, LLLL_OBJ_UIMSP, &outtypes, 1);
			this_outtype = outtypes + numlllloutlets - 1;
			for (this_out = x->l_out + numlllloutlets - 1; this_out >= x->l_out ; this_out--) {
				if (this_out->b_type == LLLL_O_NATIVE || this_out->b_type == LLLL_O_TEXT || this_out->b_type == LLLL_O_MAX || this_out->b_type == LLLL_O_DISABLED) {
					switch (*this_outtype) {
						case 't': llllobj_change_out_type(this_out, LLLL_O_TEXT);		break;
						case 'm': llllobj_change_out_type(this_out, LLLL_O_MAX);		break;
						case 'x': llllobj_change_out_type(this_out, LLLL_O_DISABLED);	break;
						case 'n': llllobj_change_out_type(this_out, LLLL_O_NATIVE);		break;
						case '-':
							switch (this_out->b_type) {
								case LLLL_O_NATIVE:		*this_outtype = 'n';	break;
								case LLLL_O_TEXT:		*this_outtype = 't';	break;
								case LLLL_O_MAX:		*this_outtype = 'm';	break;
								case LLLL_O_DISABLED:	*this_outtype = 'x';	break;
								default: break;
							}
							break;
					}
					this_outtype--;
				}
			}
			x->l_outtypes = gensym(outtypes);
			bach_freeptr(outtypes);
		} else {
			x->l_outtypes = sym;
		}
	}
	return MAX_ERR_NONE;
}

void llllobj_class_add_out_attr(t_class *c, e_llllobj_obj_types type) 
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			class_addmethod(c, (method)llllobj_obj_rebuild_notify, "notify", A_CANT, 0);
			CLASS_ATTR_SYM(c, "out", 0, t_llllobj_object, l_outtypes);
			CLASS_ATTR_ACCESSORS(c, "out", NULL, llllobj_obj_setout);
			//CLASS_ATTR_SYM(c, "o", 0, t_llllobj_object, l_outtypes);
			//CLASS_ATTR_ACCESSORS(c, "o", NULL, llllobj_obj_setout);
			//CLASS_ATTR_INVISIBLE(c, "o", 0);
			//class_addmethod(c, (method) llllobj_cleanup_vanilla, "bach.cleanup", 0);
			break;
		case LLLL_OBJ_UI:
			class_addmethod(c, (method)llllobj_jbox_rebuild_notify, "notify", A_CANT, 0);
			CLASS_ATTR_SYM(c, "out", 0, t_llllobj_jbox, l_outtypes);
			CLASS_ATTR_DEFAULT_SAVE(c, "out", 0, "");
			CLASS_ATTR_ACCESSORS(c, "out", NULL, llllobj_jbox_setout);
			//class_addmethod(c, (method) llllobj_cleanup_ui, "bach.cleanup", 0);
			break;
		case LLLL_OBJ_MSP:
			class_addmethod(c, (method)llllobj_pxobj_rebuild_notify, "notify", A_CANT, 0);
			CLASS_ATTR_SYM(c, "out", 0, t_llllobj_pxobject, l_outtypes);
			CLASS_ATTR_ACCESSORS(c, "out", NULL, llllobj_pxobj_setout);
			//CLASS_ATTR_SYM(c, "o", 0, t_llllobj_pxobject, l_outtypes);
			//CLASS_ATTR_ACCESSORS(c, "o", NULL, llllobj_obj_setout);
			//CLASS_ATTR_INVISIBLE(c, "o", 0);
			//class_addmethod(c, (method) llllobj_cleanup_msp, "bach.cleanup", 0);
			break;
		case LLLL_OBJ_UIMSP:
			class_addmethod(c, (method)llllobj_pxjbox_rebuild_notify, "notify", A_CANT, 0);
			CLASS_ATTR_SYM(c, "out", 0, t_llllobj_pxjbox, l_outtypes);
			CLASS_ATTR_DEFAULT_SAVE(c, "out", 0, "");
			CLASS_ATTR_ACCESSORS(c, "out", NULL, llllobj_pxjbox_setout);
			//class_addmethod(c, (method) llllobj_cleanup_uimsp, "bach.cleanup", 0);
			break;
		default:
			break;
	}
	CLASS_ATTR_STYLE(c, "out", 0, "text");
	CLASS_ATTR_LABEL(c, "out", 0, "Outlet Types");
	CLASS_ATTR_CATEGORY(c, "out", 0, "Behavior");
	CLASS_ATTR_BASIC(c, "out", 0);
}

void llllobj_class_add_versionnumber_attr(t_class *c, e_llllobj_obj_types type)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			CLASS_ATTR_ATOM_LONG(c, "versionnumber", 0, t_llllobj_object, l_versionnumber);
			break;
		case LLLL_OBJ_UI:
			CLASS_ATTR_ATOM_LONG(c, "versionnumber", 0, t_llllobj_jbox, l_versionnumber);
			break;
		case LLLL_OBJ_MSP:
			CLASS_ATTR_ATOM_LONG(c, "versionnumber", 0, t_llllobj_pxobject, l_versionnumber);
			break;
		case LLLL_OBJ_UIMSP:
			CLASS_ATTR_ATOM_LONG(c, "versionnumber", 0, t_llllobj_pxjbox, l_versionnumber);
			break;
		default:
			break;
	}
	CLASS_ATTR_DEFAULT_SAVE(c,"versionnumber", 0, "0");
	CLASS_ATTR_INVISIBLE(c, "versionnumber", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // invisible attribute
	// @exclude all
}

void llllobj_class_add_default_bach_attrs(t_class *c, e_llllobj_obj_types type)
{
	llllobj_class_add_out_attr(c, type);
	llllobj_class_add_versionnumber_attr(c, type);
}


t_atom_long llllobj_get_version_number(t_object *x, e_llllobj_obj_types type)
{
	t_atom_long vn = 0;
	t_dictionary *d = (t_dictionary *) gensym("#D")->s_thing;
	if (d) {
		if (type == LLLL_OBJ_UI || type == LLLL_OBJ_UIMSP) {
			if (dictionary_hasentry(d, gensym("versionnumber")))
				dictionary_getlong(d, gensym("versionnumber"), &vn);
			
		} else {
			t_dictionary *savedattrs = NULL;
			dictionary_getdictionary(d, gensym("saved_object_attributes"), (t_object **) &savedattrs);
			if (savedattrs) {
				dictionary_getlong(savedattrs, gensym("versionnumber"), &vn);
			}
		}
	}
	return vn;
}


void llllobj_set_version_number(t_object *x, e_llllobj_obj_types type, long version_number)
{
	switch (type) {
		case LLLL_OBJ_VANILLA:
			((t_llllobj_object *) x)->l_versionnumber = version_number;
			break;
		case LLLL_OBJ_MSP:
			((t_llllobj_pxobject *) x)->l_versionnumber = version_number;
			break;
		case LLLL_OBJ_UI:
			((t_llllobj_jbox *) x)->l_versionnumber = version_number;
			break;
		case LLLL_OBJ_UIMSP:
			((t_llllobj_pxjbox *) x)->l_versionnumber = version_number;
			break;
		default:
			break;
	}
}

void llllobj_set_current_version_number(t_object *x, e_llllobj_obj_types type)
{
	llllobj_set_version_number(x, type, bach_get_current_version());
}

void llllobj_cleanup_vanilla(t_object *x)
{
	llllobj_clear_all_stores_and_outs(x, LLLL_OBJ_VANILLA);
}

void llllobj_cleanup_ui(t_object *x)
{
	llllobj_clear_all_stores_and_outs(x, LLLL_OBJ_UI);
}

void llllobj_cleanup_msp(t_object *x)
{
	llllobj_clear_all_stores_and_outs(x, LLLL_OBJ_MSP);
}

void llllobj_cleanup_uimsp(t_object *x)
{
	llllobj_clear_all_stores_and_outs(x, LLLL_OBJ_UIMSP);
}


void llllobj_change_out_type(t_llllobj_out *cache, e_llllobj_outlet_types newtype)
{
	t_llll *empty_llll = llll_get();
	t_atom *destroy_atom = NULL;
	t_atomarray *destroy_aa = NULL, *deparsed_aa;
	t_llll *destroy_ll = NULL;
	t_atom_ulong phonenum;
//	bach_atomic_lock(&cache->b_lock);
	bach_atomic_lock(&cache->b_lock);
	switch (cache->b_type) {
			
		case LLLL_O_NATIVE:
			switch (newtype) {
				case LLLL_O_TEXT:
					destroy_atom = cache->b_av;
					deparsed_aa = llll_deparse_to_aa(cache->b_ll, LLLL_D_QUOTE | LLLL_D_MAX);
					llllobj_cache_text(cache, deparsed_aa);
					cache->b_type = LLLL_O_TEXT;
					break;
				case LLLL_O_MAX:
					destroy_atom = cache->b_av;
					deparsed_aa = llll_deparse_to_aa(cache->b_ll, LLLL_D_MAX);
					llllobj_cache_text(cache, deparsed_aa);
					cache->b_type = LLLL_O_MAX;
					break;
				case LLLL_O_DISABLED:
					destroy_atom = cache->b_av;
					destroy_ll = cache->b_ll;
					cache->b_av = NULL;
					cache->b_ll = NULL;
					cache->b_type = LLLL_O_DISABLED;
					break;
				default:
					break;
			}
			break;
			
		case LLLL_O_TEXT:
			switch (newtype) {
				case LLLL_O_MAX:
					destroy_aa = cache->b_aa;
					deparsed_aa = llll_deparse_to_aa(cache->b_ll, LLLL_D_MAX);
					llllobj_cache_text(cache, deparsed_aa);
					cache->b_type = LLLL_O_MAX;
					break;
				case LLLL_O_NATIVE:
					destroy_aa = cache->b_aa;
					cache->b_aa = NULL;
					phonenum = llll_phonenumber(cache->b_ll);
					cache->b_av = (t_atom *) bach_newptr(sizeof(t_atom));
					cache->b_ac = 1;
					atom_setlong(cache->b_av, phonenum);
					cache->b_type = LLLL_O_NATIVE;
					break;
				case LLLL_O_DISABLED:
					destroy_aa = cache->b_aa;
					cache->b_aa = NULL;
					destroy_ll = cache->b_ll;
					cache->b_ll = NULL;
					cache->b_type = LLLL_O_DISABLED;
					break;
				default:
					break;
			}
			break;
			
		case LLLL_O_MAX:
			switch (newtype) {
				case LLLL_O_TEXT:
					destroy_aa = cache->b_aa;
					deparsed_aa = llll_deparse_to_aa(cache->b_ll, LLLL_D_QUOTE | LLLL_D_MAX);
					llllobj_cache_text(cache, deparsed_aa);
					cache->b_type = LLLL_O_TEXT;
					break;
				case LLLL_O_NATIVE:
					destroy_aa = cache->b_aa;
					cache->b_aa = NULL;
					phonenum = llll_phonenumber(cache->b_ll);
					cache->b_av = (t_atom *) bach_newptr(sizeof(t_atom));
					cache->b_ac = 1;
					atom_setlong(cache->b_av, phonenum);
					cache->b_type = LLLL_O_NATIVE;
					break;
				case LLLL_O_DISABLED:
					destroy_aa = cache->b_aa;
					cache->b_aa = NULL;
					destroy_ll = cache->b_ll;
					cache->b_ll = NULL;
					cache->b_type = LLLL_O_DISABLED;
					break;
				default:
					break;
			}
			break;
		case LLLL_O_DISABLED:
			switch (newtype) {
				case LLLL_O_NATIVE:
					phonenum = llll_phonenumber(empty_llll);
					cache->b_ll = empty_llll;
					llll_retain(empty_llll);
					cache->b_ac = 1;
					cache->b_av = (t_atom *) bach_newptr(sizeof(t_atom));
					atom_setlong(cache->b_av, phonenum);
					cache->b_type = LLLL_O_NATIVE;
					break;
				case LLLL_O_TEXT:
					phonenum = llll_phonenumber(empty_llll);
					cache->b_ll = empty_llll;
					llll_retain(empty_llll);
					deparsed_aa = llll_deparse_to_aa(empty_llll, LLLL_D_QUOTE | LLLL_D_MAX);
					llllobj_cache_text(cache, deparsed_aa);
					cache->b_type = LLLL_O_TEXT;
					break;
				case LLLL_O_MAX:
					phonenum = llll_phonenumber(empty_llll);
					cache->b_ll = empty_llll;
					llll_retain(empty_llll);
					deparsed_aa = llll_deparse_to_aa(empty_llll, LLLL_D_MAX);
					llllobj_cache_text(cache, deparsed_aa);
					cache->b_type = LLLL_O_TEXT;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
//	bach_atomic_unlock(&cache->b_lock);
	bach_atomic_unlock(&cache->b_lock);
	llll_free(empty_llll);
	if (destroy_atom)
		bach_freeptr(destroy_atom);
	object_free_debug(destroy_aa);
	llll_free(destroy_ll);
}

t_max_err llllobj_obj_rebuild_notify(t_llllobj_object *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	t_symbol *attrname;
/*	object_post((t_object *) x, "notification received: x: %p, s: %s, msg: %s, sender: %p, data: %p",
				x, s->s_name, msg->s_name, sender, data);*/
	if (msg == _sym_attr_modified) {
		attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
//		object_post((t_object *) x, "attrname: %s", attrname);
		if (attrname != _llllobj_sym_out)
			x->l_rebuild = 1;
	}
	//object_method_direct(t_max_err, (t_object *, t_symbol *, t_symbol *, void *, void *), x, gensym("bachnotify"), msg, sender, data);
#ifdef zxcvb
	method bachnotify_method = object_method_direct_getmethod((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) object_method_direct_getobject((t_object *) x, gensym("bachnotify")), gensym("bachnotify"), msg, sender, data);
	}
#endif
	method bachnotify_method = zgetfn((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) x, gensym("bachnotify"), msg, sender, data);
	}
	return MAX_ERR_NONE;
}

t_max_err llllobj_jbox_rebuild_notify(t_llllobj_jbox *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	t_symbol *attrname;
	if (msg == _sym_attr_modified) {
		attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
		if (attrname != _llllobj_sym_out) {
			x->l_rebuild = 1;
			jbox_redraw((t_jbox *) x);
		}
	} 
#ifdef zxcvb
	method bachnotify_method = object_method_direct_getmethod((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) object_method_direct_getobject((t_object *) x, gensym("bachnotify")), gensym("bachnotify"), msg, sender, data);
	}
#endif
	method bachnotify_method = zgetfn((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) x, gensym("bachnotify"), msg, sender, data);
	}
	return MAX_ERR_NONE;
}

t_max_err llllobj_pxobj_rebuild_notify(t_llllobj_pxobject *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	t_symbol *attrname;
	if (msg == _sym_attr_modified) {
		attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
		if (attrname != _llllobj_sym_out)
			x->l_rebuild = 1;
	} 
#ifdef zxcvb
	method bachnotify_method = object_method_direct_getmethod((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) object_method_direct_getobject((t_object *) x, gensym("bachnotify")), gensym("bachnotify"), msg, sender, data);
	}
#endif
	method bachnotify_method = zgetfn((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) x, gensym("bachnotify"), msg, sender, data);
	}
	return MAX_ERR_NONE;
}

t_max_err llllobj_pxjbox_rebuild_notify(t_llllobj_pxjbox *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
	t_symbol *attrname;
	if (msg == _sym_attr_modified) {
		attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
		if (attrname != _llllobj_sym_out) {
			x->l_rebuild = 1;
			jbox_redraw((t_jbox *) x);
		}
	} 
#ifdef zxcvb
	method bachnotify_method = object_method_direct_getmethod((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) object_method_direct_getobject((t_object *) x, gensym("bachnotify")), gensym("bachnotify"), msg, sender, data);
	}
#endif
	method bachnotify_method = zgetfn((t_object *) x, gensym("bachnotify"));
	if (bachnotify_method) {
		(bachnotify_method)((t_object *) x, gensym("bachnotify"), msg, sender, data);
	}
	return MAX_ERR_NONE;
}

t_max_err llllobj_parse_and_store_llll_address(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store_num, t_bool accept_multiple, t_bool accept_range)
{
	long contains;
	t_llll *in_llll = NULL;
	t_atom_long depth;
	
	in_llll = llllobj_parse_llll((t_object *) x, type, msg, ac, av, LLLL_PARSE_CLONE);
	if (!in_llll)
		return MAX_ERR_GENERIC;
	
	if (in_llll->l_size == 0) {
		object_error(x, "Address llll can't be null");
		llll_free(in_llll);
		return MAX_ERR_GENERIC;
	}
	
	depth = in_llll->l_depth;
	if (depth == 1 || (accept_multiple && depth == 2) || (accept_range && depth == 3)) {
		contains = llll_contains(in_llll, 0, 0);
		if (contains != H_NOTHING && (contains & ~(H_LONG | H_DOUBLE | H_LLLL))) {
			object_error(x, "Bad address llll");
			llll_free(in_llll);
			return MAX_ERR_GENERIC;
		}
	} else if (depth == 2) {
		object_error(x, "Doesn't support multiple element syntax");
		llll_free(in_llll);
		return MAX_ERR_GENERIC;
	} else if (depth == 3) {
		object_error(x, "Doesn't support range");
		llll_free(in_llll);
		return MAX_ERR_GENERIC;
	} else {
		object_error(x, "Bad address llll");
		llll_free(in_llll);
		return MAX_ERR_GENERIC;
	}

	llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, in_llll, store_num);
	return MAX_ERR_NONE;
}



t_max_err llllobj_add_to_release_pool(t_object *x, e_llllobj_obj_types type, void *release_me, method free_function)
{
	t_object *val;
	t_max_err err;
	t_hashtab *release = llllobj_get_release(x, type);
	t_bach_atomic_lock *release_lock = llllobj_get_release_lock_ptr(x, type);
	bach_atomic_lock(release_lock);
	err = hashtab_lookup(release, (t_symbol *) release_me, &val);
	if (err == MAX_ERR_NONE) { // there is already something here!
		bach_atomic_unlock(release_lock);
		return MAX_ERR_GENERIC;
	}
	hashtab_store(release, (t_symbol *) release_me, (t_object *) free_function);
	bach_atomic_unlock(release_lock);
	return MAX_ERR_NONE;
}

t_max_err llllobj_remove_from_release_pool(t_object *x, e_llllobj_obj_types type, void *remove_me)
{
	t_hashtab *release = llllobj_get_release(x, type);
	t_bach_atomic_lock *release_lock = llllobj_get_release_lock_ptr(x, type);
	t_max_err err;
	bach_atomic_lock(release_lock);
	err = hashtab_delete(release, (t_symbol *) remove_me);
	bach_atomic_unlock(release_lock);
	return err;
}

void llllobj_free_release_pool(t_object *x, e_llllobj_obj_types type)
{
	t_hashtab *release = llllobj_get_release(x, type);
	hashtab_funall(release, (method) hashtab_release_one, NULL);
	object_free_debug(release);
}

t_max_err llllobj_test_lambda_loop_two_outs(t_object *x, e_llllobj_obj_types type, t_llllelem *el1, t_llllelem *el2, long lambda1, long lambda2)
{
	t_llll *a_ll = llll_get();
	t_llll *b_ll = llll_get();
	llll_appendhatom_clone(a_ll, &el1->l_hatom, 0, WHITENULL_llll);
	llll_appendhatom_clone(b_ll, &el2->l_hatom, 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) x, type, lambda2, b_ll);
	llllobj_outlet_llll((t_object *) x, type, lambda1, a_ll);
	llll_free(a_ll);
	llll_free(b_ll);
	return MAX_ERR_NONE;
}

t_max_err llllobj_test_lambda_loop_one_out(t_object *x, e_llllobj_obj_types type, t_llllelem *el, long lambda)
{
	t_llll *a_ll = llll_get();
	llll_appendhatom_clone(a_ll, &el->l_hatom, 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) x, type, lambda, a_ll);
	llll_free(a_ll);
	return MAX_ERR_NONE;
}

void hashtab_release_one(t_hashtab_entry *e, void *dummy)
{
	((method)(e->key))(e->value);
}

void llllobj_manage_dict_llll(t_object *x, e_llllobj_obj_types type, t_llll *dictll)
{
	t_atom a[2];
	atom_setobj(a, llllobj_get_dictll_ptr(x, type));
	atom_setobj(a + 1, llll_clone(dictll));
	defer_low(x, (method) llllobj_manage_dict_llll_do, NULL, 2, a);
}

void llllobj_manage_dict_llll_do(t_object *x, t_symbol *msg, long ac, t_atom *av)
{
	t_object *mypatcher = NULL;
	t_llll **dictll_ptr;
	t_llll *dictll;
	t_symbol *filename = NULL;
	dictll_ptr = (t_llll **) atom_getobj(av);
	dictll = (t_llll *) atom_getobj(av + 1);

	object_obex_lookup(x, gensym("#P"), &mypatcher);
	while (mypatcher) {
		filename = jpatcher_get_filename(mypatcher);
		if (!filename || !strncmp(filename->s_name, "bach.help.", 10))
			break;
		char *extension = strrchr(filename->s_name, '.');
		if (extension && !strcmp(extension, ".maxhelp"))
			break;
		mypatcher = jpatcher_get_parentpatcher(mypatcher);
	}
#ifdef zzzzz_CONFIGURATION_Development
	if (mypatcher && filename) {
		llll_print(dictll, x, 0, 6, NULL);
		*dictll_ptr = dictll;
		//dev_object_post(x, "Yes, it's a help file!");
	} else {
		*dictll_ptr = NULL;
		llll_free(dictll);
		//dev_object_post(x, "No, it's not a help file!");
	}
#else
	*dictll_ptr = NULL;
	llll_free(dictll);
#endif
}

void bach_class_setname(const char *obname, const char *filename)
{
	class_setname(const_cast<char *>(obname), const_cast<char *>(filename));
}



