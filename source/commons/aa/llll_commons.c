#include "llll_commons.h"
#include <stdarg.h>
#include <string.h>
#include "llll_commonsyms.h"
#include "bach_threads.h"

#ifdef BACH_MAX
#include "ext_strings.h"
#include "ext_common.h"
#include "ext_critical.h"
#include "ext_hashtab.h"
//#include "ext_atomic.h"
typedef t_object t_binbuf;
#endif
//#include "llll_math.h"
#include "chkparser.h"

/*
 possible types:
 i = long
 d = double
 s = symbol
 r = rational
 l = llll (clone)
 */


#define MULTI_FIND_PILE_SIZE_STEP (64)



typedef enum _parseargs_types {
	P_LONG,
	P_DOUBLE,
	P_SYM,
	P_RAT,
    P_PITCH,
    P_HATOM,
	P_LLLL, // lllls are cloned, and the previous contents of the variable are freed
} e_parseargs_types;

typedef union _parseargs_ptr {
	t_atom_long		*p_long;
	double			*p_double;
	t_symbol		**p_symbol;
	t_rational		*p_rat;
    t_pitch         *p_pitch;
	t_llll			**p_llll;
    t_hatom         *p_hatom;
	void			*p_void; // for convenience
} t_parseargs_ptr;

typedef struct _parseargs_item {
	e_parseargs_types	p_type;
	t_parseargs_ptr		p_ptr;
} t_parseargs_item;

t_parseargs_item *parseargs_item_new(e_parseargs_types type, void *ptr);

//extern t_symbol **_llllobj_attributes;
t_class *llll_class;
t_class *llllelem_class;

t_bach *bach;
long *primes;
t_hashtab *memmap;
t_hashtab *poolmap;
t_systhread_mutex memmap_lock;

t_llll **llll_book;
t_uint32 **llll_phonebook;
t_uint32 *llll_current_phonebook_idx;
t_uint32 *llll_pool_size;
t_bach_atomic_lock *llll_pool_lock;
t_llll *llll_model;

t_llllelem_numbered **llllelem_book;
t_uint32 **llllelem_phonebook;
t_uint32 *llllelem_current_phonebook_idx;
t_uint32 *llllelem_pool_size;
t_bach_atomic_lock *llllelem_pool_lock;
t_llllelem_numbered *llllelem_model;



int llll_compare_elems_by_thing(t_llllelem **a, t_llllelem **b);
long llll_sort_addresses(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_sort_addresses_for_insert_b(void *dummy, t_llllelem *a, t_llllelem *b);


void bach_setup(t_bach *x)
{
	bach = x;
	primes = bach->b_primes;
	memmap = bach->b_memmap;
	poolmap = bach->b_poolmap;
	memmap_lock = bach->b_memmap_lock;
	
	llll_book = bach->b_llll_book;
	llll_phonebook = bach->b_llll_phonebook;
	llll_current_phonebook_idx = &bach->b_llll_current_phonebook_idx;
	llll_pool_size = &bach->b_llll_pool_size;
	llll_pool_lock = &x->b_llll_pool_lock;
	llll_model = &x->b_llll_model;
	
	llllelem_book = bach->b_llllelem_book;
	llllelem_phonebook = bach->b_llllelem_phonebook;
	llllelem_current_phonebook_idx = &bach->b_llllelem_current_phonebook_idx;
	llllelem_pool_size = &bach->b_llllelem_pool_size;
	llllelem_pool_lock = &x->b_llllelem_pool_lock;
	llllelem_model = &x->b_llllelem_model;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// create a new legal llll from text (but s is ignored, so all the list must be inside av[])
// or an illegal llll if ac == 0
//
// special case:
// if s == gensym("string") and av is A_OBJ then ac is ignored, and atom_getobj(av) is cast to a char* from which the whole string is built
// (don't rely on this, as it's never used in bach and might change in the very near future!)


char *llll_next_thing(const char *where)
{
	const char *next = where;
	while (*next && isspace(*next))
		next++;
	return (char *) next;
}


// return the inferred "minimum" type from a string
// accepts a leading +, and scientific e notation
e_hatom_types llll_typecheck(const char *txt)
{
	char decimal_point = 0;
	
	if (!isdigit(*txt)) { // if it's a digit it can be a number, otherwise we must investigate further
		if (*(txt + 1) == 0) // if it's a single char and it's not a digit, it can't be a number
			return H_SYM;
		if (*txt == '.')
			decimal_point = 1;
		else if (*txt != '+' && *txt != '-') // if it's not a . nor a sign than it's surely a symbol
			return H_SYM;
	}
	
	while (*++txt && decimal_point <= 1) {
		if (*txt == '.')
			decimal_point ++;
		else if (*txt == 'e' || *txt == 'E') {
			if (llll_typecheck(txt + 1) == H_LONG)
				return H_DOUBLE;
			else
				return H_SYM;
		} else if (decimal_point == 0 && *txt == '/') {
			if (llll_typecheck(txt + 1) == H_LONG)
				return H_RAT;
			else
				return H_SYM;
		} else if (!isdigit(*txt)) {
			return H_SYM;
		}
	}
	
	if (decimal_point > 1)
		return H_SYM;
	if (decimal_point)
		return H_DOUBLE;
	return H_LONG;
}

t_llll *llll_legalnew(void)
{
	t_llll *x = llll_get();
	return x;
}
								   
long llll_contains_separators(char *txt)
{
	while (*txt) {
		if (*txt == ',' || *txt == ';' || *txt == '$' || isspace(*txt))
			return 1;
		txt++;
	}
	return 0;
}

t_atomarray *llll_deparse_to_aa(t_llll *ll, char flags)
{
	t_atom *out = NULL;
	t_atom_long ac = llll_deparse(ll, &out, 0, flags);
	t_atomarray *aa = atomarray_new_debug(ac, out);
	bach_freeptr(out);
	return aa;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// returns 0 if it can't allocate the memory it needs,
// otherwise the number of atoms constituting the result (including the offset)
//
// offset is referred to *out (leaves some atoms at the beginning, useful for preset)
// flags are LLLL_D_QUOTE, LLLL_D_MAX and LLLL_D_FLOAT64

t_atom_long llll_deparse(t_llll *ll, t_atom **out, t_atom_long offset, char flags)
{
	long ac = offset;
	t_llll *subll;
	t_llllelem *elem;
	char txt[256];
	t_llll_stack *stack;
	t_symbol *checked;
	t_atom_long outsize;
	long leveltype = L_STANDARD;
	t_atom *new_out, *this_out;
	
	if (*out == NULL) {
		*out = (t_atom *) bach_newptr(ATOM_LIST_LENGTH_STEP * sizeof (t_atom));
		outsize = ATOM_LIST_LENGTH_STEP;
	} else {
#ifdef BACH_MAX
		outsize = sysmem_ptrsize(*out);
#endif
#ifdef BACH_JUCE
		return -1;
#endif
	}

	
	if (!*out)
		return 0;
	
	this_out = *out + offset;
	
	if (!ll) {
		return ac;
	}
	
	if (ll->l_size == 0) {
		atom_setsym(this_out, gensym("null"));
		return ac + 1;
	}
	
	stack = llll_stack_new();
	elem = ll->l_head;
	
	while (1) {
		while (elem) {
			if (ac >= outsize - 5) { // we always leave some more place for the possible closed parenthesis and a float64
				new_out = (t_atom *) bach_resizeptr(*out, (outsize += ATOM_LIST_LENGTH_STEP) * sizeof(t_atom));
				if (!new_out) {
					llll_stack_destroy(stack);
					return ac;
				}
				*out = new_out;
				this_out = *out + ac;
			}
			switch(elem->l_hatom.h_type) {
				case H_LONG:
					atom_setlong(this_out++, elem->l_hatom.h_w.w_long);
					ac ++;
					elem = elem->l_next;
					break;
                    
				case H_DOUBLE:
					if (flags & LLLL_D_FLOAT64) {
#ifdef C74_X64
						t_uint64 l = elem->l_hatom.h_w.w_whole[0];
#else
						t_uint64 l = elem->l_hatom.h_w.w_whole;
#endif
						atom_setsym(this_out++, _llllobj_sym_float64_marker);
                        t_uint64 l_lo = l & 0xFFFFFFFF;
						atom_setlong(this_out++, l_lo); // big endian
                        t_uint64 l_hi = l >> 32;
						atom_setlong(this_out++, l_hi);
						ac +=3;
					} else {
						atom_setfloat(this_out++, elem->l_hatom.h_w.w_double);
						ac ++;
					}
					elem = elem->l_next;
					break;
                    
				case H_RAT:
#ifdef BACH_MAX
					snprintf_zero(txt, 256, ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT, elem->l_hatom.h_w.w_rat.r_num, elem->l_hatom.h_w.w_rat.r_den);
#else
					snprintf(txt, 256, ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT, elem->l_hatom.h_w.w_rat.r_num, elem->l_hatom.h_w.w_rat.r_den);
#endif
					atom_setsym(this_out++, gensym(txt));
					ac ++;
					elem = elem->l_next;
					break;
                
                case H_PITCH:
                    atom_setsym(this_out++, gensym(elem->l_hatom.h_w.w_pitch.toString().c_str()));
                    ac ++;
                    elem = elem->l_next;
                    break;
                    
                case H_SYM: {
                    t_symbol *sym = elem->l_hatom.h_w.w_sym;

                    if (ac == 0 && (flags & LLLL_D_MAX) && (sym == _sym_int || sym == _sym_float || sym == _sym_list)) {
                        checked = sym_addquote(sym->s_name);
                    } else if (flags & LLLL_D_QUOTE) {
                        checked = llll_quoteme(sym);
					} else 
						checked = sym;
					
					atom_setsym(this_out++, checked);
					ac ++;
					elem = elem->l_next;
					break;
                }
				case H_LLLL:
					subll = elem->l_hatom.h_w.w_llll;
					leveltype = subll->l_leveltype;
					atom_setsym(this_out++, _open_parentheses_sym[leveltype]);
					ac ++;
					llll_stack_push(stack, elem);
					elem = subll->l_head;
					break;
				case H_OBJ:
#ifdef BACH_MAX
					snprintf_zero(txt, 256, "[object:%p]", elem->l_hatom.h_w.w_obj);
#else
					snprintf(txt, 256, "[object:%p]", elem->l_hatom.h_w.w_obj);
#endif
					atom_setsym(this_out++, gensym(txt));
					ac++;
					elem = elem->l_next;
					break;
				case H_NULL:
					atom_setsym(this_out++, _llllobj_sym_null);
					ac++;
					elem = elem->l_next;
					break;
				default:
					atom_setsym(this_out++, gensym("###UNKNOWN###"));
					ac++;
					elem = elem->l_next;
					break;
			}
		}
		if (!stack->s_items)
			break;
		atom_setsym(this_out++, _closed_parentheses_sym[leveltype]);
		ac ++;
		elem = (t_llllelem *) llll_stack_pop(stack);
		leveltype = elem->l_parent->l_leveltype;
		elem = elem->l_next;
	}
	llll_stack_destroy(stack);
	return ac;
}

// TODO:
// replace with a call to the parser
// if it returns anything different from one symbol, it should be quoted
t_symbol *llll_quoteme(t_symbol *s)
{
    if (s == _llllobj_sym_nil || s == _llllobj_sym_null) {
		return sym_addquote(s->s_name);
    } else {
        long tct;
        long type = typecheck_parse(s->s_name, &tct);
        if (type != H_SYM || tct & E_TT_PAREN ||
            (!(tct & E_TT_RESERVED) && (tct & E_TT_BACKTICK))) {
            return sym_addquote(s->s_name);
        } else
            return s;
    }
}

t_symbol *sym_addquote(const char *txt)
{
	char quoted[2048];
	*quoted = QUOTE_CHAR;
	strncpy_zero(quoted + 1, txt, 2048);
	return gensym(quoted);
}

////////////////////////////
// clones a llll
// outll is initialized
// adopter is the list that will appear as the owner of the elements of the base level of the newly-created list
// (this is useful in some exotic situations)
// WHITENULL means that the new list's elements will have the default owner (in this case, it's the same as NULL)
//
// if alloc is non-0, new lllls and llllelems will be forced being newly allocated - rather than tentatively retrieved from the pool

t_llll *llll_clone_extended(const t_llll *inll, t_llll *adopter, long alloc, llll_clone_fn fn)
{
	t_llll_stack *instack;
	t_llllelem *inelem, *outelem;
	t_llllelem *prev = NULL;
	t_llll *this_adopter;
	t_llll *deepest_subll = NULL;
	
	if (!inll)
		return NULL;
	
	if ((adopter == NULL || adopter == WHITENULL_llll) && !alloc && !fn)
		return llll_clone(inll);

	instack = llll_stack_new();
	
	t_llll *outll = llll_get();
	t_llll *actual_outll = outll;
	
	if (inll->l_thing.w_obj) {
		if (fn)
			outll->l_thing.w_obj = (fn)(inll->l_thing.w_obj);
		else
			outll->l_thing.w_obj = inll->l_thing.w_obj;
	}
	
	inelem = inll->l_head;
	this_adopter = adopter;

	while (1) {
		while (inelem) {
			outelem = alloc ? llllelem_make() : llllelem_get();
			outelem->l_hatom = inelem->l_hatom;
			outelem->l_thing = inelem->l_thing;
			outelem->l_flags = inelem->l_flags;
			outelem->l_parent = this_adopter == WHITENULL_llll ? outll : this_adopter;
			outelem->l_prev = prev;
			if (prev)
				prev->l_next = outelem;
			else
				outll->l_head = outelem;
			if (hatom_gettype(&inelem->l_hatom) == H_LLLL) {
				llll_stack_push(instack, inelem);
				outll = llll_get();
				outelem->l_hatom.h_w.w_llll = outll;
				outll->l_owner = outelem;
				inll = inelem->l_hatom.h_w.w_llll;
				inelem = inll->l_head;
				prev = NULL;
				if (this_adopter == adopter && // which means, if this is a sublist of the root llll
					(deepest_subll == NULL || deepest_subll->l_depth > inll->l_depth))
					deepest_subll = outll;
				if (inll->l_thing.w_obj) {
					if (fn)
						outll->l_thing.w_obj = (fn)(inll->l_thing.w_obj);
					else
						outll->l_thing.w_obj = inll->l_thing.w_obj;
				}
				this_adopter = WHITENULL_llll;
			} else {
				prev = outelem;
				inelem = inelem->l_next;
			}
		}
		outll->l_tail = prev;
		outll->l_depth = inll->l_depth;
		outll->l_size = inll->l_size;
		if (!instack->s_items)
			break;
		if (instack->s_items == 1)
			this_adopter = adopter;
		inelem = (t_llllelem *) llll_stack_pop(instack);
		inll = inelem->l_parent;
		inelem = inelem->l_next;
		prev = outll->l_owner;
		outll = prev->l_parent;
		if (outll == adopter)
			outll = actual_outll;
	}
	if (deepest_subll)
		llll_upgrade_depth(deepest_subll);
	llll_stack_destroy(instack);
	pedantic_llll_check(outll);
	return outll;
}

t_llll *llll_clone(const t_llll *inll)
{	
	if (!inll)
		return NULL;
	t_llll *outll = llll_get();
	llll_clone_upon(inll, outll);
	pedantic_llll_check(outll);
	return outll;
}

t_llll *llll_clone_safe(t_llll *inll)
{
#ifdef BACH_SAFE_LLLLS
	bach_atomic_rlock(&inll->l_lock);
#endif
	t_llll *outll = llll_clone(inll);
#ifdef BACH_SAFE_LLLLS
	bach_atomic_runlock(&inll->l_lock);
#endif
	return outll;
}

t_max_err llll_clone_upon(const t_llll *inll, t_llll *outll)
{
	t_llll_stack *instack;
	t_llllelem *inelem, *outelem;
	t_llllelem *prev = NULL;
	
	if (!inll || !outll)
		return MAX_ERR_GENERIC;
#ifdef CONFIGURATION_Development
#ifdef BACH_USE_MAGIC_NUMBER
	if (inll->l_magic != BACH_MAGIC_GOOD)
		error("cloning bad llll: %p", inll);
#endif
#endif
	
#ifdef BACH_CHECK_LLLLS
	llll_check(inll);
	llll_check(outll);
#endif
	instack = llll_stack_new();
	inelem = inll->l_head;
	
	while (1) {
		while (inelem) {
			outelem = llllelem_get();
			//*outelem = *inelem;
			outelem->l_hatom = inelem->l_hatom;
			outelem->l_thing = inelem->l_thing;
			outelem->l_flags = inelem->l_flags;
			outelem->l_parent = outll;
			outelem->l_prev = prev;
			if (prev)
				prev->l_next = outelem;
			else
				outll->l_head = outelem;
			if (hatom_gettype(&inelem->l_hatom) == H_LLLL) {
				llll_stack_push(instack, inelem);
				outll = llll_get();
				outelem->l_hatom.h_w.w_llll = outll;
				outll->l_owner = outelem;
				inll = inelem->l_hatom.h_w.w_llll;
				inelem = inll->l_head;
				prev = NULL;
			} else {
				prev = outelem;
				inelem = inelem->l_next;
			}
		}
		outll->l_tail = prev;
		outll->l_depth = inll->l_depth;
		outll->l_size = inll->l_size;
		outll->l_thing.w_whole = inll->l_thing.w_whole;
		outll->l_leveltype = inll->l_leveltype;
		if (!instack->s_items)
			break;
		inelem = (t_llllelem *) llll_stack_pop(instack);
		inll = inelem->l_parent;
		inelem = inelem->l_next;
		prev = outll->l_owner;
		outll = prev->l_parent;
	}
	llll_stack_destroy(instack);
	pedantic_llll_check(outll);
	return MAX_ERR_NONE;
}

void llll_transfer(t_llll *from_ll, t_llll *to_ll)
{
	to_ll->l_head = from_ll->l_head;
	to_ll->l_tail = from_ll->l_tail;
	to_ll->l_size = from_ll->l_size;
	to_ll->l_depth = from_ll->l_depth;

	from_ll->l_depth = 0;
	from_ll->l_size = 0;
	from_ll->l_head = NULL;
	from_ll->l_tail = NULL;
	from_ll->l_owner = NULL;
	
	llll_adopt(to_ll, to_ll);
	pedantic_llll_check(to_ll);
	return;
}

t_atom_long llll_contains(t_llll *ll, t_int32 mindepth, t_int32 maxdepth)
{
	short type;
    t_atom_long contains = 0;
	t_llllelem *elem;
	t_llll *subll;
	t_llll_stack *stack;
	t_int32 depth = 1;
	long deepenough;
	
	if (!ll)
		return 0;

	if (mindepth == 0)
		mindepth = 1;
	if (maxdepth == 0)
		maxdepth = -1;
	
	if (mindepth > ll->l_depth || maxdepth < -ll->l_depth)
		return 0;
	
	stack = llll_stack_new();
	elem = ll->l_head;
	
	deepenough = (mindepth == 1 || ll->l_depth < -mindepth);
	
	while (1) {
		while (elem) {
			type = elem->l_hatom.h_type;
			if (deepenough)
				contains |= type;
			if ((subll = hatom_getllll(&elem->l_hatom)) && (depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
				llll_stack_push(stack, elem->l_next);
				elem = subll->l_head;
				depth++;
				deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
			} else
				elem = elem->l_next;
		}
		if (depth <= 1)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
		depth--;
		deepenough = elem && ((mindepth > 0 && depth >= mindepth) || (elem->l_parent->l_depth <= -mindepth));
	}
	llll_stack_destroy(stack);
	return contains;
}

// DESTRUCTIVE!
void llll_rev(t_llll *ll, t_int32 mindepth, t_int32 maxdepth) // ll must have at least 1 elem!
{
	t_llllelem *elem;
	t_llllelem *next;
	t_llll_stack *stack;
	t_llll *subll;
	t_int32 depth = 1;
	t_int32 size = 0;
	
	long deepenough;

	if (!ll)
		return;
	
	if (mindepth == 0)
		mindepth = 1;
	if (maxdepth == 0)
		maxdepth = -1;
	
	if (mindepth > ll->l_depth || maxdepth < -ll->l_depth)
		return;
	
	deepenough = (mindepth == 1 || ll->l_depth <= -mindepth);
	
	stack = llll_stack_new();

	elem = ll->l_head;
	if (deepenough) {
		ll->l_head = ll->l_tail;
		ll->l_tail = elem;
		size = ll->l_size;
	}
	while (1) {
		while (elem) {
			next = elem->l_next;
			if (deepenough && size) {
				elem->l_next = elem->l_prev;
				elem->l_prev = next;
			}
			if (elem->l_hatom.h_type == H_LLLL && 
				(subll = elem->l_hatom.h_w.w_llll)->l_size != 0 &&
				(depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
				llll_stack_push(stack, next);
				ll = subll;
				elem = ll->l_head;
				depth++;
				deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
				if (deepenough) {
					ll->l_head = ll->l_tail;
					ll->l_tail = elem;
					size = ll->l_size;
				}
			} else
				elem = next;
		}
		if (depth <= 1)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
		depth--;
		deepenough = elem && ((mindepth > 0 && depth >= mindepth) || (elem->l_parent->l_depth <= -mindepth));
		if (elem && deepenough)
			size = elem->l_parent->l_size;
	}
	llll_stack_destroy(stack);
	pedantic_llll_check(ll);
	return;
}

// DESTRUCTIVE!
void llll_rot(t_llll *ll, t_int32 mindepth, t_int32 maxdepth, t_atom_long shift)
{
//	t_llllelem *newhead;
//	long deepenough;
	t_llll_stack *stack;
	t_int32 depth = 1;
	t_llllelem *elem;
	t_llll *subll;
	
	if (!ll)
		return;
	
	if (shift == 0 || ll->l_size == 0)
		return;
	
	if (mindepth == 0)
		mindepth = 1;
	if (maxdepth == 0)
		maxdepth = -1;
	
	if (mindepth > ll->l_depth || maxdepth < -ll->l_depth)
		return;
	
	if (mindepth == 1 || ll->l_depth <= -mindepth)
		llll_rotatelevel(ll, shift);
	
	if (maxdepth == 1 || ll->l_depth == -maxdepth)
		return;

	stack = llll_stack_new();
	elem = ll->l_head;
	while (1) {
		while (elem) {
			if ((subll = hatom_getllll(&elem->l_hatom)) && (depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
				llll_stack_push(stack, elem->l_next);
				depth++;
//				deepenough = ((mindepth >= 0 && depth >= mindepth) || (ll->l_depth < -mindepth));
				if ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth))
					llll_rotatelevel(subll, shift);
				elem = subll->l_head;
				
			} else
				elem = elem->l_next;
		}
		if (depth <= 1)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
		depth--;
//		deepenough = elem && ((mindepth >= 0 && depth >= mindepth) || (elem->l_parent->l_depth < -mindepth));
	}
	llll_stack_destroy(stack);
	pedantic_llll_check(ll);
}

/// DESTRUCTIVE!
// rotate the base level of the current llll
void llll_rotatelevel(t_llll *ll, t_atom_long shift)
{
	t_llllelem *newhead;
	if (!ll)
		return;
	newhead = llll_getindex(ll, shift + (shift > 0), I_MODULO);
	ll->l_tail->l_next = ll->l_head;
	ll->l_head->l_prev = ll->l_tail;
	ll->l_head = newhead;
	ll->l_tail = newhead->l_prev;
	newhead->l_prev = NULL;
	ll->l_tail->l_next = NULL;
	pedantic_llll_check(ll);
	return;
}

/*
 Iterate on lists, according to the modes (see bach.iter's help files)
 If you provide it a cache, it will only do one step, and put the result in the cache.
 In this case, it will return -1 if no actual iteration has taken place,
    0 if an iteration has been performed and the list is over, 
    1 if there are more elements to iterate upon.
 The functions are called back once for every input llll at every step (unless the case in which no element has to be output), with:
 - datax/addressx/cmdx as their first argument (most often, you will want to store your caller object there)
 - list is the index of the llll we're currently referring to
 - llll is a newly-created (and owned by llll_iter) llll, which contains the currently iterated element
 - cmd is the command (again, see the bach.iter's help file)
 if one of those function returns non-zero, the iteration stop.
 
 NB that this is only useful in very specific cases, 
 usually involving synchronization of many iterations, and/or complex interaction with other objects
 currently, it is used by bach.iter, bach.expr and bach.step
 You will usually want to iterate through a list with a for cycle
 if you want to iterate depth-first, you are advised to take advantage of the stack structure and API we provide,
 rather than adopting a recursive approach that would be noticeably slower and memory-hungry.
 For an example of stack-based depth-first iteration, see e.g. llll_clone() (there's plenty of examples around)
 Actually, llll_iter internally is based on the same approach
 */
long llll_iter(long lists, t_llll **inlist, t_int32 maxdepth,
			   long scalarmode, long recursionmode, long iterationmode, long spikemode, long unwrap, 
			   t_llll_itercache *cache,
			   iter_datafn datafunc, void *datax,
			   iter_datafn addressfunc, void *addressx,
			   iter_cmdfn cmdfunc, void *cmdx,
			   iter_rootfn rootfunc, void *rootx,
			   iter_lambdafn lambdafn, void *lambdax)
{
	t_llll **this_inlist, **address = NULL, **this_address, **sublist = NULL, **this_sublist, *temp_llll;
	t_llllelem **elem = NULL, **this_elem;
	long lastlist = lists - 1;
	t_atom_long *len = NULL, *this_len, maxlen, steps, i, subdepth;
	long elem_types, movements, direction, stop, *temporaries, *this_temporaries;
	t_hatom *this_hatom;
	char newiter = 1; // goes to 0 if we're in step mode and there is an ongoing stepping
	char fake; // 1 when in a spike in spikemode 
	char after_output = 0;
	t_llll_stack *elem_stack = NULL, *inlist_stack = NULL, *steps_stack = NULL;
	t_int32 depth = 1;

	//if (maxdepth == 0)
	//	maxdepth = -1;
	
	if (lists < 1)
		return -1;
	
	if (cache) {
		if (cache->i_active) { // if we're in stepmode and there is an ongoing stepping
			elem_stack = cache->i_elem_stack;
			inlist_stack = cache->i_inlist_stack;
			steps_stack = cache->i_steps_stack;
			len = cache->i_len;
			temporaries = cache->i_temporaries;
			address = cache->i_address;
			movements = cache->i_movements;
			direction = cache->i_direction;
			elem = (t_llllelem **) llll_stack_pop(elem_stack);
			inlist = (t_llll **) llll_stack_pop(inlist_stack);
			steps = (long) llll_stack_pop(steps_stack);
			newiter = 0;
			depth = elem_stack->s_items + 1;
		} else
			cache->i_active = 1;
	}
	if (newiter) { 
		long deepestdepth = 1;
		for (this_inlist = inlist + lastlist; this_inlist >= inlist; this_inlist--) {
			long thisdepth = (*this_inlist)->l_depth;
			if (deepestdepth < thisdepth)
				deepestdepth = thisdepth;
		}
		
		if (deepestdepth < -maxdepth - 1) { // that is, no list is deep enough for this maxdepth
			if (cache)
				cache->i_active = 0;
			return -1;
		}
		
		if (maxdepth == 0 || deepestdepth == -maxdepth - 1) {
			//if (cache)
			//	cache->i_active = 0;
			if (rootfunc)
				(rootfunc)(rootx);
			this_inlist = inlist + lastlist; this_address = address + lastlist; i = lastlist;
			for (; i >= 0; this_inlist--, this_address--, i--) {
				if (addressfunc) {
					temp_llll = llll_get(); // easier than llll_clone...
					(addressfunc)(addressx, i, temp_llll, 1);
					llll_free(temp_llll);
				}
				if (datafunc) {
					if (unwrap == 1) {
						temp_llll = llll_clone(*this_inlist);
					} else {
						temp_llll = llll_get();
						llll_appendllll(temp_llll, llll_clone(*this_inlist), 0, WHITENULL_llll);
						if (unwrap)
							llll_flat(temp_llll, 1, unwrap, 0, LLLL_FREETHING_DONT);
					}
					(datafunc)(datax, i, temp_llll, 0);
					llll_free(temp_llll);
				}
			}
			if (cache)
				cache->i_active = 0;
			return 0;
		}
		
		if (lambdafn) {
			t_bool enter;
			temp_llll = llll_get();
			this_inlist = inlist + lastlist;
			for ( ; this_inlist >= inlist; this_inlist--) {
				t_llll *this_list_ll = llll_get();
				llll_appendllll(this_list_ll, llll_clone(*this_inlist), 0, WHITENULL_llll);
				llll_appendllll(this_list_ll, llll_get(), 0, WHITENULL_llll);
				llll_appendllll(temp_llll, this_list_ll, 0, WHITENULL_llll);
			}
			enter = (lambdafn)(lambdax, temp_llll);
			llll_free(temp_llll);
			
			if (enter != 1) {
				if (cache)
					cache->i_active = 0;
				return 0;
			}
		}

		elem_stack = llll_stack_new();
		inlist_stack = llll_stack_new();
		steps_stack = llll_stack_new();
		
		// add one level to each address for which inlist is legal
		// (which means it's not temporary, which means it's not a scalar from the upper level!) 
		// and set it to 0
		
		len = (t_atom_long *) bach_newptr(lists * sizeof(t_atom_long));
		elem = (t_llllelem **) bach_newptr(lists * sizeof(t_llllelem *));
		address = (t_llll **) bach_newptr(lists * sizeof(t_llll *));
		temporaries = (long *) bach_newptrclear(lists * sizeof(long));
		
		steps = 0;
		movements = 0;
		direction = 0;
		this_elem = elem + lastlist; this_inlist = inlist + lastlist; this_address = address + lastlist;
		for (; this_elem >= elem; this_elem--, this_inlist--, this_address--) {
			*this_address = llll_get();
			llll_appendlong(*this_address, LLLL_IDX_BASE, 0, WHITENULL_llll);
			*this_elem = (*this_inlist)->l_head;
		}

		if (cache) {
			cache->i_elem_stack = elem_stack;
			cache->i_inlist_stack = inlist_stack;
			cache->i_steps_stack = steps_stack;
			cache->i_len = len;
			cache->i_temporaries = temporaries;
			cache->i_address = address;
		}
	}

	while (1) {
		
		maxlen = 0;
		elem_types = 0;
		this_elem = elem + lastlist; this_inlist = inlist + lastlist; this_address = address + lastlist; this_len = len + lastlist; this_temporaries = temporaries + lastlist;
		subdepth = 0;
		for ( ; this_elem >= elem; this_elem--, this_inlist--, this_address--, this_len--, this_temporaries--) {
			
			if ((*this_len = (*this_inlist)->l_size) > maxlen)
				maxlen = *this_len;
			
			if (*this_temporaries == 0) { // if it's not a temporary list
				if (*this_elem) {
					if (hatom_gettype(&(*this_elem)->l_hatom) == H_LLLL) {
						elem_types |= LLLL_E_LLLL;
						subdepth = MAX(subdepth, (*this_elem)->l_hatom.h_w.w_llll->l_depth);
					} else
						elem_types |= LLLL_E_ATOM;
				} else
					elem_types |= LLLL_E_NULL;
			} else
				elem_types |= LLLL_E_ATOM; // if this_inlist is temporary, it surely contains an atom
		}
		
		// do another round if there is somthing more to explore, and
		// if we iterate against the longest list, 
		// or if we iterate against the shortest and there are elements in each list,
		// or if we iterate against the shortest and all the existing elements are LLLLs,
		// or if we just entered one or more empty sublists in spike mode
		
		while ((steps < maxlen && 
				(iterationmode != LLLL_M_ITERATION_STOP || !(elem_types & LLLL_E_NULL) /* || (elem_types == (LLLL_E_NULL | LLLL_E_LLLL))*/)) ||			   
			   (direction == 1 && spikemode != LLLL_M_SPIKE_IGNORE && (elem_types & LLLL_E_NULL))) {

			if (cache && after_output) {
				cache->i_movements = movements;
				cache->i_direction = direction;
				llll_stack_push(elem_stack, elem);
				llll_stack_push(inlist_stack, inlist);
				llll_stack_push(steps_stack, (void *) steps);
				if (sublist)
					bach_freeptr(sublist);
				return 1;
			}
			
			fake = 0;
			
			// now we have to choose whether to stay at this level and process a round of elements for possible shooting,
			// or to enter a sublist
			
			// we stay at this level if: 
			// there are no lists or 
			// (there is at least one non-list and we don't resolve lists against atoms) or 
			// we reached maxdepth or
			// (we don't ignore spikes and we are at a spike) or
			// (there is a lambda function, and it returns 0)

			/*t_bool stay_at_this_level =	!(elem_types & LLLL_E_LLLL) || 
										(elem_types != LLLL_E_LLLL && recursionmode == LLLL_M_RECURSION_DONT) || 
										(depth == maxdepth || subdepth < -maxdepth) ||
										((spikemode != LLLL_M_SPIKE_IGNORE && (direction == -1 && (elem_types & LLLL_E_LLLL))) || 
										 (direction == 1 && (elem_types == LLLL_E_NULL) ));*/
					
/*			t_bool leave_this_level = ((elem_types & LLLL_E_LLLL) && // there is at least one llll and
									   (elem_types == LLLL_E_LLLL || recursionmode != LLLL_M_RECURSION_DONT) && // (all elements are lllls or we resolve lists against atoms) and
									   (depth != maxdepth && subdepth >= -maxdepth) && // we didn't reach maxdepth and
									   ((spikemode == LLLL_M_SPIKE_IGNORE || (direction != -1 || !(elem_types & LLLL_E_LLLL))) &&
										(direction != 1 || elem_types != LLLL_E_NULL))); // we ignore spikes or we're not at a spike
									   
*/

			t_bool leave_this_level = ((elem_types & LLLL_E_LLLL) && // there is at least one llll and
									   (elem_types == LLLL_E_LLLL || recursionmode != LLLL_M_RECURSION_DONT) && // (all elements are lllls or we resolve lists against atoms) and
									   (depth != maxdepth && subdepth >= -maxdepth) && // we didn't reach maxdepth and
									   (spikemode == LLLL_M_SPIKE_IGNORE || 
										((direction != -1 || !(elem_types & LLLL_E_LLLL)) && 
										 (direction != 1 || elem_types != LLLL_E_NULL)))); // we ignore spikes or we're not at a spike
			
/*			if (!(elem_types & LLLL_E_LLLL) || 
				(elem_types != LLLL_E_LLLL && recursionmode == LLLL_M_RECURSION_DONT) || 
				(depth == maxdepth || subdepth < -maxdepth) ||
				((spikemode != LLLL_M_SPIKE_IGNORE && (direction == -1 && (elem_types & LLLL_E_LLLL))) || 
				 (direction == 1 && (elem_types == LLLL_E_NULL) || 
				  (lambdafn && !(lambdafn)(lambdax, elem, address)) ))) { */
			
			if (leave_this_level) {
				
				if (lambdafn) { // here we test for lambda, but only if we have the other conditions to leave this level
					temp_llll = llll_get();
					this_address = address + lastlist; this_elem = elem + lastlist;
					for ( ; this_address >= address; this_address--, this_elem--) {
						t_llll *this_list_ll = llll_get();
						if (*this_elem)
							llll_appendhatom_clone(this_list_ll, &(*this_elem)->l_hatom, 0, WHITENULL_llll);
						else
							llll_appendllll(this_list_ll, llll_get(), 0, WHITENULL_llll);
						llll_appendllll(this_list_ll, llll_clone(*this_address), 0, WHITENULL_llll);
						llll_appendllll(temp_llll, this_list_ll, 0, WHITENULL_llll);
					}
					long lambda_result = (lambdafn)(lambdax, temp_llll);
					llll_free(temp_llll);
					if (lambda_result == -1)
						goto stopped;
					leave_this_level = lambda_result;
				}
				
				if (leave_this_level) {
					//	- if there are lists, create the appropriate temporary lists
					//	- advance what must be advanced
					//	- push
					movements++;
					
					this_elem = elem + lastlist; this_inlist = inlist + lastlist;
					if (!sublist)
						sublist = (t_llll **) bach_newptr(lists * sizeof(t_llll *));
					this_sublist = sublist + lastlist; this_address = address + lastlist; this_len = len + lastlist; this_temporaries = temporaries + lastlist;
					for ( ; this_elem >= elem; this_elem--, this_inlist--, this_sublist--, this_address--, this_len--, this_temporaries--) {
						long temporaryness = *this_temporaries;
						if (temporaryness) {
							*this_sublist = *this_inlist;
							(*this_temporaries)++;
						} else if (*this_elem) {
							this_hatom = &(*this_elem)->l_hatom;
							if (hatom_gettype(this_hatom) != H_LLLL) {
								llll_appendhatom((*this_sublist) = llll_get(), this_hatom, 0, WHITENULL_llll); // create a temporary list (temporary lists are not legal)
								(*this_temporaries)++;
							} else 
								*this_sublist = hatom_getllll(this_hatom);
						} else {
							*this_sublist = llll_get(); // create an empty temporary list
							(*this_temporaries)++;
						}
						
						
						// go to the next element if
						// this element exists and
						// either there are no lists with more than 1 element at this level (in which case, basically, we want to step out of it)
						// or this is a legal list and (we're not in scalarmode or we are in scalarmode but anyway this list doesn't have one element)
						if (*this_elem && (maxlen <= 1 || ((*this_len != 1 || scalarmode == 0) && !temporaryness)))
							*this_elem = (*this_elem)->l_next;
					}
					direction = 1; // pushing means that we're rising one level
					llll_stack_push(elem_stack, elem);
					llll_stack_push(inlist_stack, inlist);
					llll_stack_push(steps_stack, (void *) (steps + 1)); // this is an ugly hack!
					depth++; // the overall depth increases
					inlist = sublist; // and yes, let's go to the next level!
					sublist = (t_llll **) bach_newptr(lists * sizeof(t_llll *));
					elem = (t_llllelem **) bach_newptr(lists * sizeof(t_llllelem *));
					
					this_elem = elem + lastlist; this_inlist = inlist + lastlist; this_address = address + lastlist; this_temporaries = temporaries + lastlist;
					for (; this_elem >= elem; this_elem--, this_inlist--, this_address--, this_temporaries--) {
						*this_elem = (*this_inlist)->l_head;
						if (*this_temporaries == 0)
							llll_appendlong(*this_address, LLLL_IDX_BASE, 0, WHITENULL_llll);
					}
					
					steps = 0;
					break;
				}
			}
			
			if (!leave_this_level) { // if we stay at this level

				stop = cmdfunc ? (cmdfunc)(cmdx, movements) : 0;

				this_address = address + lastlist; this_elem = elem + lastlist; i = lastlist;
				for ( ; this_address >= address; this_address--, this_elem--, i--) {
					this_hatom = &(*this_elem)->l_hatom;
					// now we have to choose whether to shoot this_elem or not 
					// (the latter meaning to shoot nothing or shoot a null 
					// - which in turns can be either because this list has finished, or because it is a fake)
					// we shoot out this_elem if:
					
					// it exists and
					// we're not in a )( with spikemode on (because in this case we output a "fake" null)
					// or we are but there are also non-LLLL and we don't resolve lists against llll
					if (*this_elem &&																			
						((spikemode == LLLL_M_SPIKE_IGNORE || direction != -1 || !(elem_types & LLLL_E_LLLL)) || 
						 (elem_types != LLLL_E_LLLL && recursionmode == LLLL_M_RECURSION_DONT))) {	
							if (addressfunc) {
								temp_llll = llll_clone(*this_address);
								stop |= (addressfunc)(addressx, i, temp_llll, 1);
								llll_free(temp_llll);
							}
							if (datafunc) {
								temp_llll = llll_get();
								llll_appendhatom_clone(temp_llll, this_hatom, 0, WHITENULL_llll);
								if (unwrap)
									llll_flat(temp_llll, 1, unwrap, 0, LLLL_FREETHING_DONT);
								stop |= (datafunc)(datax, i, temp_llll, 0);
								llll_free(temp_llll);
							}
							after_output = 1;
						} else {
							// now we have to choose whether to shoot nulls for this address and datum, or not
							// we shoot the nulls if:
							// we have iterationmode VERBOSE (if we're here, we surely have a condition requiring to shoot!) or
							// we're in a spike (if we're here, we surely have spikemode on)
							if ((iterationmode == LLLL_M_ITERATION_SHOOT) || 
								((direction == 1 && elem_types == LLLL_E_NULL) || // this means ()
								  (direction == -1 && (elem_types & LLLL_E_LLLL)))) { // this means )(
									 if (iterationmode == LLLL_M_ITERATION_SHOOT || spikemode == LLLL_M_SPIKE_VERBOSE) {
										 if (addressfunc) {
											 temp_llll = llll_get();
											 stop |= (addressfunc)(addressx, i, temp_llll, 1);
											 llll_free(temp_llll);
										 }
										 if (datafunc) {
											 temp_llll = llll_get();
											 stop |= (datafunc)(datax, i, temp_llll, 0);
											 llll_free(temp_llll);
										 }
										 after_output = 1;
									 } else {
										 after_output = (spikemode == LLLL_M_SPIKE_SHOOT_STEP);
									 }

									 if (!fake && *this_elem && (elem_types == LLLL_E_NULL || (elem_types & LLLL_E_LLLL)))	// if it's an actual spike and we don't ignore it, then this was a fake
										 fake = 1;
								 }
						}
				}
				movements = 0;
				direction = 0;
				if (stop)
					goto stopped;
				
				if (!fake) {
					elem_types = 0;
					this_address = address + lastlist; this_elem = elem + lastlist; this_len = len + lastlist; this_temporaries = temporaries + lastlist;
					for ( ; this_address >= address; this_address--, this_elem--, this_len--, this_temporaries--) {
						// step to the next element of the list only if the list has more than one element or if scalarmode == 1, and it's not a temporary list
						if (*this_elem && (maxlen <= 1 || ((*this_len != 1 || scalarmode == 0) && *this_temporaries == 0))) {
							*this_elem = (*this_elem)->l_next;
							if (*this_temporaries == 0) 
								(*this_address)->l_tail->l_hatom.h_w.w_long++;
						}
					}
					steps++;
				}
				
			} 
				
			if (!fake) {
				subdepth = 0;
				for (this_elem = elem + lastlist; this_elem >= elem; this_elem--) {
					if (*this_elem) {
						if (hatom_gettype(&(*this_elem)->l_hatom) == H_LLLL) {
							elem_types |= LLLL_E_LLLL; 
							subdepth = MAX(subdepth, (*this_elem)->l_hatom.h_w.w_llll->l_depth);
						} else
							elem_types |= LLLL_E_ATOM;
					} else
						elem_types |= LLLL_E_NULL;
				}
			}
		}
		// either we're here because of a push (and in this case items > 0) or because a level is finished, in which case we have to pop
		if (elem_stack->s_items == 0) // if the last level is finished, quit
			break;

		if (direction != 1 || maxlen == 0) { // if we're not here because of a push, it means that a level is finished
			// pop
			// delete the temporary lists
			// remove the last element from address for non-temporary lists
			
			(movements)--;
			direction = -1;
			
			for (this_inlist = inlist + lastlist, this_address = address + lastlist, this_temporaries = temporaries + lastlist; this_inlist >= inlist; this_inlist--, this_address--, this_temporaries--) {
				if (*this_temporaries == 1)
					llll_free(*this_inlist);
				else if (*this_temporaries == 0)
					llll_destroyelem((*this_address)->l_tail);
				if (*this_temporaries > 0)
					(*this_temporaries)--;
			}
			bach_freeptr(inlist);
			bach_freeptr(elem);
			elem = (t_llllelem **) llll_stack_pop(elem_stack);
			inlist = (t_llll **) llll_stack_pop(inlist_stack);
			steps = (long) llll_stack_pop(steps_stack);
			depth--;
			
			// if we're here, at least one element of *this_inlist has been processed
			// therefore, if size == 1 and this_elem exist it's a scalar in scalarmode 1
			// therefore its address must not be incremented
			this_elem = elem + lastlist; this_inlist = inlist + lastlist; this_address = address + lastlist; this_temporaries = temporaries + lastlist;
			for ( ; this_elem >= elem; this_elem--, this_inlist--, this_address--, this_temporaries--)
				if (*this_elem && *this_temporaries == 0 && (*this_inlist)->l_size != 1)
					(*this_address)->l_tail->l_hatom.h_w.w_long++;
		}
	}

stopped:
	if (sublist)
		bach_freeptr(sublist);
	if (elem)
		bach_freeptr(elem);
	if (len)
		bach_freeptr(len);
	if (address) {
		for (this_address = address + lastlist; this_address >= address; this_address--)
			llll_free(*this_address);
		bach_freeptr(address);
	}
	if (temporaries)
		bach_freeptr(temporaries);
	if (elem_stack) {
		llll_stack_destroy(elem_stack);
		llll_stack_destroy(inlist_stack);
		llll_stack_destroy(steps_stack);
	}
	if (cache)
		cache->i_active = 0;

    return after_output - 1; // 0 if something has been output, -1 otherwise
}

#ifdef USE_OLD_FUNALL
void llll_funall(t_llll *ll, fun_fn fn, void *data, t_int32 mindepth, t_int32 maxdepth, long mode)
{
	t_llll *address, *subll;
	t_llll_stack *stack;
	t_llllelem *elem;
	t_hatom *hatom;
//	long deepenough;
	t_int32 depth = 1;
	long dontenter = 0;
	long sublists = mode == FUNALL_PROCESS_WHOLE_SUBLISTS || mode == FUNALL_SKIP_ATOMS;
	long elements = mode != FUNALL_SKIP_ATOMS;
	
	if (!ll)
		return;
	
	if (mindepth == 0)
		mindepth = 1;
	if (maxdepth == 0)
		maxdepth = -1;
	
	if (mindepth > ll->l_depth || maxdepth < -ll->l_depth)
		return;
	
//	deepenough = (mindepth == 1 || ll->l_depth < -mindepth);

	address = llll_get();
	
	if (sublists) {
		t_hatom temphatom;
		hatom_setllll(&temphatom, ll);
		if ((fn)(data, &temphatom, address)) {
			llll_free(address);
			return;
		}
	}

	stack = llll_stack_new();
	elem = ll->l_head;
	
	llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
	
	while (1) {
		while (elem) {
			hatom = &elem->l_hatom;
			if (hatom->h_type == H_LLLL && (subll = elem->l_hatom.h_w.w_llll)->l_legal && (depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
				if (sublists)
					dontenter = (fn)(data, hatom, address);
				if (!dontenter) {
					llll_stack_push(stack, elem->l_next);
					elem = subll->l_head;
					depth++;
					llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
	//				deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
				} else {
					elem = elem->l_next;
					address->l_tail->l_hatom.h_w.w_long++;		
				}
			} else {
				if ((elements && hatom->h_type != H_LLLL) || (sublists && hatom->h_type == H_LLLL))
					(fn)(data, hatom, address);
				elem = elem->l_next;
				address->l_tail->l_hatom.h_w.w_long++;
			}
		}
		if (depth <= 1)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
		llll_destroyelem(address->l_tail);
		address->l_tail->l_hatom.h_w.w_long++;
		depth--;
//		deepenough = elem && ((mindepth > 0 && depth >= mindepth) || (elem->l_parent->l_depth <= -mindepth));
	}
	
	llll_stack_destroy(stack);
	llll_free(address);
	pedantic_llll_check(ll);

}
#endif

void llll_funall(t_llll *ll, fun_fn fn, void *data, t_int32 mindepth, t_int32 maxdepth, long mode)
{
	t_llll *address, *subll;
	t_llll_stack *stack;
	t_llllelem *elem;
	t_hatom *hatom;
	long deepenough;
	t_int32 depth = 1;
	long dontenter = 0;
	
	if (!ll)
		return;
	
	if (mindepth == 0) {
		if (mode != FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH &&
			mode != FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH_AND_SKIP_ATOMS)
			mode = FUNALL_PROCESS_WHOLE_SUBLISTS;
		mindepth = 1;
	}
		
	long sublists = mode == FUNALL_PROCESS_WHOLE_SUBLISTS || mode == FUNALL_SKIP_ATOMS;
	long sublists_at_maxdepth = mode == FUNALL_PROCESS_WHOLE_SUBLISTS ||
								mode == FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH ||
								mode == FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH_AND_SKIP_ATOMS ||
								mode == FUNALL_SKIP_ATOMS;
	long elements = mode != FUNALL_SKIP_ATOMS && mode != FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH_AND_SKIP_ATOMS;
	
	if (mindepth > ll->l_depth || maxdepth < -ll->l_depth)
		return;
	
	deepenough = (mindepth == 1 || ll->l_depth < -mindepth);
	
	address = llll_get();
	
	if (sublists || maxdepth == 0) {
		t_hatom temphatom;
		hatom_setllll(&temphatom, ll);
		if (deepenough && (sublists || maxdepth == 0))
			dontenter = (fn)(data, &temphatom, address);
		if (dontenter || maxdepth == 0) {
			llll_free(address);
			return;
		}
	}
	
	stack = llll_stack_new();
	elem = ll->l_head;
	
	llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
	
	while (1) {
		while (elem) {
			hatom = &elem->l_hatom;
			if ((subll = hatom_getllll(hatom)) && 
				(depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
				if (sublists && deepenough)
					dontenter = (fn)(data, hatom, address);
				if (!deepenough || !dontenter) {
					llll_stack_push(stack, elem->l_next);
					elem = subll->l_head;
					depth++;
					llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
					deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
				} else {
					elem = elem->l_next;
					address->l_tail->l_hatom.h_w.w_long++;
				}
			} else {
				if (deepenough && ((elements && hatom->h_type != H_LLLL) || (sublists_at_maxdepth && hatom->h_type == H_LLLL)))
					(fn)(data, hatom, address);
				elem = elem->l_next;
				address->l_tail->l_hatom.h_w.w_long++;
			}
		}
		if (depth <= 1)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
		llll_destroyelem(address->l_tail);
		address->l_tail->l_hatom.h_w.w_long++;
		depth--;
		deepenough = elem && ((mindepth > 0 && depth >= mindepth) || (elem->l_parent->l_depth <= -mindepth));
	}
	
	llll_stack_destroy(stack);
	llll_free(address);
	pedantic_llll_check(ll);

}

// frees all the elements in a llll (regardless of its flag)
void llll_clear(t_llll *x)
{
	t_llllelem *this_elem, *next_elem;
	if (!x)
		return;
	for (this_elem = x->l_head; this_elem; this_elem = next_elem) {
		next_elem = this_elem->l_next;
		llllelem_free(this_elem); // was: nocheck
	}
	x->l_size = 0;
	x->l_depth = 1;
	x->l_head = x->l_tail = NULL;
	pedantic_llll_check(x);

}


// frees all the elements in a llll (regardless of its flag)
void llll_clear_nocheck(t_llll *x)
{
	t_llllelem *this_elem, *next_elem;
	if (!x)
		return;
	for (this_elem = x->l_head; this_elem; this_elem = next_elem) {
		next_elem = this_elem->l_next;
		llllelem_free_nocheck(this_elem); // was: nocheck
	}
	x->l_size = 0;
	x->l_depth = 1;
	x->l_head = x->l_tail = NULL;
	//pedantic_llll_check(x);
}

// set the owner of every element of child as adopter, if != WHITENULL 
void llll_adopt(t_llll *child, t_llll *adopter)
{
	t_llllelem *elem;
	if (!child)
		return;
	if (adopter != WHITENULL_llll)
		for (elem = child->l_head; elem; elem = elem->l_next)
			elem->l_parent = adopter;
	//pedantic_llll_check(child);
}

// DESTRUCTIVE! - x is augmented by giver
// chain two lllls one after another
void llll_chain(t_llll *x, t_llll *giver)
{
    if (!giver)
		return;
	if (giver->l_size == 0) {
		llll_free(giver);
		return;
	}
	if (!x)
		return;
	llll_adopt(giver, x);
	if (x->l_size == 0) {
		x->l_head = giver->l_head;
		x->l_tail = giver->l_tail;
		x->l_depth = giver->l_depth;
		x->l_size = giver->l_size;
		llll_upgrade_depth(x);
	} else {
		x->l_size += giver->l_size;
		if (giver->l_depth > x->l_depth) {
			x->l_depth = giver->l_depth;
			llll_upgrade_depth(x);
		}
		x->l_tail->l_next = giver->l_head;
		giver->l_head->l_prev = x->l_tail;
		x->l_tail = giver->l_tail;
	}
	llll_chuck_nocheck(giver);
	pedantic_llll_check(x);
}

// DESTRUCTIVE!
// works like llll_chain, but giver is prepended, rather than appended, to x
void llll_rchain(t_llll *giver, t_llll *x)
{
    if (!giver)
		return;
	if (giver->l_size == 0) {
		llll_free(giver);
		return;
	}
	if (!x)
		return;
    llll_adopt(giver, x);
	if (x->l_size == 0) {
		x->l_head = giver->l_head;
		x->l_tail = giver->l_tail;
		x->l_depth = giver->l_depth;
		x->l_size = giver->l_size;
		llll_upgrade_depth(x);
	} else {
		x->l_size += giver->l_size;
		if (giver->l_depth > x->l_depth) {
			x->l_depth = giver->l_depth;
			llll_upgrade_depth(x);
		}
		giver->l_tail->l_next = x->l_head;
		x->l_head->l_prev = giver->l_tail;
		x->l_head = giver->l_head;
	}
	llll_chuck(giver);
	pedantic_llll_check(x);
}

// properly removes an element from a llll
void llll_destroyelem(t_llllelem *killme)
{
	t_llll *parent;
	if (!killme)
		return;
	parent = killme->l_parent;
	if (parent->l_size == 1) { // it's the only element
		parent->l_head = parent->l_tail = NULL;
	} else if (killme->l_prev == NULL) { // it's head
		killme->l_next->l_prev = NULL;
		parent->l_head = killme->l_next;
	} else if (killme->l_next == NULL) { // it's tail
		killme->l_prev->l_next = NULL;
		parent->l_tail = killme->l_prev;
	} else {
		killme->l_prev->l_next = killme->l_next;
		killme->l_next->l_prev = killme->l_prev;
	}
	parent->l_size--;
	if (killme->l_hatom.h_type == H_LLLL && killme->l_hatom.h_w.w_llll->l_depth >= parent->l_depth - 1) // it should never be > of course, but one never knows...
		llll_downgrade_depth(parent);
	if (!(parent->l_flags & OBJ_FLAG_DATA))
		llllelem_free(killme); // was: nocheck
	pedantic_llll_check(parent);
}

void llll_destroyelem_no_depth_check(t_llllelem *killme)
{
	t_llll *parent;
	if (!killme)
		return;
	parent = killme->l_parent;
	if (parent->l_size == 1) { // it's the only element
		parent->l_head = parent->l_tail = NULL;
	} else if (killme->l_prev == NULL) { // it's head
		killme->l_next->l_prev = NULL;
		parent->l_head = killme->l_next;
	} else if (killme->l_next == NULL) { // it's tail
		killme->l_prev->l_next = NULL;
		parent->l_tail = killme->l_prev;
	} else {
		killme->l_prev->l_next = killme->l_next;
		killme->l_next->l_prev = killme->l_prev;
	}
	parent->l_size--;
	if (!(parent->l_flags & OBJ_FLAG_DATA))
		llllelem_free_nocheck(killme);
}

// swap places of el1 and el2, even if they belong to different lllls.
// el1 and el2 must not contain one another, or MAX_ERR_GENERIC is returned
// if they are the same element, nothing bad happens
t_max_err llll_swapelems(t_llllelem *a, t_llllelem *b)
{
	t_llllelem swap;
	
	if (!a || !b)
		return MAX_ERR_GENERIC;
	
	if (a == b)
		return MAX_ERR_NONE;
    
    long a_type = hatom_gettype(&a->l_hatom);
    long b_type = hatom_gettype(&b->l_hatom);
    
    // call the "smaller" element a
    if (a_type == H_LLLL &&
        (b_type != H_LLLL || a->l_parent->l_depth > b->l_parent->l_depth)) {
        t_llllelem *swap_elem = a;
        a = b;
        b = swap_elem;
        long swap_type = a_type;
        a_type = b_type;
        b_type = swap_type;
    }
    
    // now b is surely an llll, and if a is an llll too then b is deeper
    
    // so we only have to find out if b contains a
    t_llllelem *ancestor;
    for (ancestor = a->l_parent->l_owner; ancestor; ancestor = ancestor->l_parent->l_owner) {
        if (ancestor == b)
            return MAX_ERR_GENERIC;
    }
    
    if (a->l_next == b) {
        t_llll *parent = a->l_parent;
        b->l_prev = a->l_prev;
        a->l_next = b->l_next;
        b->l_next = a;
        a->l_prev = b;
        if (parent->l_head == a)
            parent->l_head = b;
        else
            b->l_prev->l_next = b;
        if (parent->l_tail == b)
            parent->l_tail = a;
        else
            a->l_next->l_prev = a;
    } else if (b->l_next == a) {
        t_llll *parent = b->l_parent;
        a->l_prev = b->l_prev;
        b->l_next = a->l_next;
        a->l_next = b;
        b->l_prev = a;
        if (parent->l_head == b)
            parent->l_head = a;
        else
            a->l_prev->l_next = a;
        if (parent->l_tail == a)
            parent->l_tail = b;
        else
            b->l_next->l_prev = b;
    } else {

        swap = *b;
        
        
        if (a->l_prev)
            a->l_prev->l_next = b;
        else
            a->l_parent->l_head = b;
        
        if (swap.l_prev)
            swap.l_prev->l_next = a;
        else
            swap.l_parent->l_head = a;
        
        
        b->l_prev = a->l_prev;
        a->l_prev = swap.l_prev;
        
        if (a->l_next)
            a->l_next->l_prev = b;
        else
            a->l_parent->l_tail = b;
        
        if (swap.l_next)
            swap.l_next->l_prev = a;
        else
            swap.l_parent->l_tail = a;
        
        b->l_next = a->l_next;
        a->l_next = swap.l_next;
        
        if (a->l_parent != b->l_parent) {
            b->l_parent = a->l_parent;
            a->l_parent = swap.l_parent;
            
            // if the a and b pointers have been swapped above, we're doing this for the second time
            // which might appear to be stupid
            // but first, it seems to me to be more readable
            // and second, are we sure that the other way would be faster?
            long swap_type = a_type;
            a_type = b_type;
            b_type = swap_type;
            
            // fix the depths
            // of course, now b is "smaller" (or, a and b have the same "size", of course)
            if (b_type != H_LLLL || b->l_parent->l_depth != a->l_parent->l_depth) {
                llll_upgrade_depth(a->l_parent);
                llll_downgrade_depth(b->l_parent);
            }
        }
    }
	pedantic_llll_check(a->l_parent);
	pedantic_llll_check(b->l_parent);
	return MAX_ERR_NONE;
}

t_max_err llll_swaphatoms(t_llllelem *a, t_llllelem *b)
{
    if (!a || !b)
        return MAX_ERR_GENERIC;
    
    if (a == b)
        return MAX_ERR_NONE;
    
    long a_type = hatom_gettype(&a->l_hatom);
    long b_type = hatom_gettype(&b->l_hatom);
    
    if (a_type != H_LLLL && b_type != H_LLLL) {
        t_hatom swap = a->l_hatom;
        a->l_hatom = b->l_hatom;
        b->l_hatom = swap;
        return MAX_ERR_NONE;
    }
    
    // call the "smaller" element a
    if (a_type == H_LLLL &&
        (b_type != H_LLLL || a->l_parent->l_depth > b->l_parent->l_depth)) {
        t_llllelem *swap_elem = a;
        a = b;
        b = swap_elem;
        long swap_type = a_type;
        a_type = b_type;
        b_type = swap_type;
    }
    
    // now b is surely an llll, and if a is an llll too then b is deeper
    
    // so we only have to find out if b contains a
    t_llllelem *ancestor;
    for (ancestor = a->l_parent->l_owner; ancestor; ancestor = ancestor->l_parent->l_owner) {
        if (ancestor == b)
            return MAX_ERR_GENERIC;
    }
    
    // now we can swap the hatoms
    t_hatom swap_hatom = a->l_hatom;
    a->l_hatom = b->l_hatom;
    b->l_hatom = swap_hatom;
    
    // if the a and b pointers have been swapped above, we're doing this for the second time
    // which might appear to be stupid
    // but first, it seems to me to be more readable
    // and second, are we sure that the other way would be faster?
    long swap_type = a_type;
    a_type = b_type;
    b_type = swap_type;
    
    // fix the ownerships
    a->l_hatom.h_w.w_llll->l_owner = a;
    if (b_type == H_LLLL)
        b->l_hatom.h_w.w_llll->l_owner = b;
    
    // fix the depths
    // of course, now b is "smaller" (or, a and b have the same "size", of course)
    if (b_type != H_LLLL || b->l_parent->l_depth != a->l_parent->l_depth) {
        llll_upgrade_depth(a->l_parent);
        llll_downgrade_depth(b->l_parent);
    }
    pedantic_llll_check(a->l_parent);
    pedantic_llll_check(b->l_parent);
    return MAX_ERR_NONE;
}


// returns the pos-th element (counting from LLLL_IDX_BASE) of the list
// can accept negative index (for counting from the end) and see the list as circular, if the appropriate mode is set
// (see documentation for e_llll_index_modes)
t_llllelem *llll_getindex(t_llll *ll, t_atom_long pos, e_llll_index_modes mode)
{
	t_atom_long i, size, newpos;
	t_llllelem *elem = NULL;
	
	if (!ll)
		return NULL;
	
#if LLLL_IDX_BASE
	if (pos == 0)
		return NULL;
	if (pos > 0)
		pos -= 1;
#endif
	
	if ((size = ll->l_size) == 0)
		return NULL;
	
	if ((mode & I_MODULO) && (pos >= ll->l_size || pos < -ll->l_size)) {
		newpos = pos % size;
		if (pos < 0 && newpos > 0)
			newpos -= pos;
		pos = newpos;
	}
	
	if (pos >= 0) {
		elem = ll->l_head;
		for (i = 1; elem && i <= pos; i++)
			elem = elem->l_next;
	} else if (!(mode & I_NON_NEGATIVE)) {
		elem = ll->l_tail;
		for (i = -1; elem && i > pos; i--)
			elem = elem->l_prev;
	}
	return elem;
}

		
// create a t_llll_stack
// this is not a t_object!
t_llll_stack *llll_stack_new(void)
{
	t_llll_stack *x = (t_llll_stack *) bach_newptr_named(sizeof(t_llll_stack), gensym("stack"));
	if (!x)
		return NULL;
	x->s_stack = (void **) bach_newptr(LLLL_STACK_SIZESTEP * sizeof (void *));
	x->s_current = x->s_stack - 1;
	x->s_size = LLLL_STACK_SIZESTEP;
	x->s_items = 0;
	return x;
}

// destroy a t_llll_stack
void llll_stack_destroy(t_llll_stack *x)
{
	if (!x)
		return;
	bach_freeptr(x->s_stack);
	bach_freeptr(x);
}

// push thing into x
void llll_stack_push(t_llll_stack *x, void *thing)
{
	if (!x)
		return;
	x->s_items++;
	if (x->s_items > x->s_size) {
		x->s_size += LLLL_STACK_SIZESTEP;
		x->s_stack = (void **) bach_resizeptr(x->s_stack, x->s_size * sizeof (void *));
		x->s_current = x->s_stack + x->s_items - 1;
		*x->s_current = thing;
	} else
		*(++x->s_current) = thing;
}

// pop thing from x
void *llll_stack_pop(t_llll_stack *x)
{
	void *popped;
	if (!x || x->s_items == 0)
		return NULL;
	popped = *x->s_current;
	x->s_items--;
	if (x->s_items <= x->s_size - LLLL_STACK_SIZESTEP && x->s_items != 0) {
		x->s_size -= LLLL_STACK_SIZESTEP;
		x->s_stack = (void **) bach_resizeptr(x->s_stack, x->s_size * sizeof (void *));
		x->s_current = x->s_stack + x->s_items - 1;
	} else
		x->s_current--;
	return popped;
}

// return the address of the given element, with respect to its base llll
// if base is NULL, the address will be relative to the top-level llll
t_llll *llll_get_address(t_llllelem *elem, t_llll *base)
{
	t_llllelem *this_elem, *base_owner;
	t_atom_long idx;
	t_llll *address = llll_get();
	base_owner = base ? base->l_owner : NULL;
		
	for ( ; elem && elem != base_owner; elem = elem->l_parent->l_owner) {
		idx = 1;
		for (this_elem = elem->l_parent->l_head; this_elem && this_elem != elem; this_elem = this_elem->l_next)
			idx++;
		if (!this_elem) {
			llll_free(address);
			return NULL;
		}
		llll_prependlong(address, idx, 0, WHITENULL_llll);
	}
	pedantic_llll_check(address);
	return address;
}


// return the first element in root pointed by address, according to the address syntax
// if none can be found, returns NULL
t_llllelem *llll_nth_one(const t_llll *root, t_llll *address)
{
	t_llll *baby_llll = llll_get();
	t_llllelem *result = NULL;
	llll_findchildren(root, address, 0, baby_llll, NULL);
	if (baby_llll->l_size)
		result = (t_llllelem *) baby_llll->l_head->l_hatom.h_w.w_obj;
	llll_free(baby_llll);
#ifdef PEDANTICALLY_CHECK_LLLLS
    if (result)
        pedantic_llll_check(result->l_parent);
#endif
	return result;
}

// return a llll with H_OBJ atoms pointing to each element in root pointed by address, according to the address syntax
t_llll *llll_nth_as_objs(t_llll *root, t_llll *address)
{
	t_llll *out_llll = llll_get();
	t_llll *baby_llll = llll_get();
	t_llllelem *this_baby;
	llll_findchildren(root, address, 0, baby_llll, NULL);
	for (this_baby = baby_llll->l_head; this_baby; this_baby = this_baby->l_next)
		llll_appendobj(out_llll, this_baby->l_hatom.h_w.w_obj, 0, WHITENULL_llll);
	llll_free(baby_llll);
	pedantic_llll_check(out_llll);
	return out_llll;
}

// return a llll with hatoms copied (and sublllls cloned) from each element in root pointed by address, according to the address syntax
t_llll *llll_nth(t_llll *root, t_llll *address, long nils)
{
	t_llll *out_llll = llll_get();
	t_llll *baby_llll = llll_get();
	t_llllelem *elem, *baby;
	llll_findchildren(root, address, 0, baby_llll, NULL);
	for (elem = baby_llll->l_head; elem; elem = elem->l_next) {
		if ((baby = (t_llllelem *) elem->l_hatom.h_w.w_obj)) {
			llll_appendhatom_clone(out_llll, &baby->l_hatom, 0, WHITENULL_llll);
		} else if (nils)
			llll_appendllll(out_llll, llll_get(), 0, WHITENULL_llll);
	}
	llll_free(baby_llll);
	pedantic_llll_check(out_llll);
	return out_llll;
}


// DESTRUCTIVE on ll
void llll_subs(t_llll *ll, t_llll *address, t_llll *subs_model)
{
	t_llll *baby_llll; // will contain references to the selected elements
	t_llll *this_subs, *trough = NULL;
	t_llll *edited = NULL;
	t_llllelem *elem, *baby;
	t_atom_long maxsubdepth, size_growth;
			
	baby_llll = llll_get();
	llll_findchildren(ll, address, 0, baby_llll, NULL);
	
	if (subs_model && subs_model->l_size) {
		size_growth = subs_model->l_size - 1;
		for (elem = baby_llll->l_head; elem; elem = elem->l_next) {
			if ((baby = (t_llllelem *) elem->l_hatom.h_w.w_obj)) {
				edited = baby->l_parent; // the (sub)list the surgery will be performed on	
				this_subs = llll_clone_extended(subs_model, edited, 0, NULL);
				if (baby->l_prev)
					baby->l_prev->l_next = this_subs->l_head;
				else
					edited->l_head = this_subs->l_head;
				if ((this_subs->l_head->l_prev = baby->l_prev) == NULL)
					edited->l_head = this_subs->l_head;
				
				if (baby->l_next)
					baby->l_next->l_prev = this_subs->l_tail;
				else
					edited->l_tail = this_subs->l_tail;
				if ((this_subs->l_tail->l_next = baby->l_next) == NULL)
					edited->l_tail = this_subs->l_tail;
				
				edited->l_size += size_growth;
				llllelem_free(baby);
				//llll_fix_owner_for_check(this_subs);
				llll_chuck_nocheck(this_subs);
			}
		}
		if (edited) {
			maxsubdepth = 0;
			for (elem = subs_model->l_head; elem; elem = elem->l_next) {
				if (elem->l_hatom.h_type == H_LLLL && elem->l_hatom.h_w.w_llll->l_depth > maxsubdepth) {
					maxsubdepth = elem->l_hatom.h_w.w_llll->l_depth;
					trough = elem->l_hatom.h_w.w_llll;
				}
			}
			if (maxsubdepth >= edited->l_depth)
				llll_upgrade_depth(trough);
			else if (maxsubdepth + 1 < edited->l_depth) 
				llll_downgrade_depth(edited);
			
		}
	} else {
		for (elem = baby_llll->l_head; elem; elem = elem->l_next) {
			if ((baby = (t_llllelem *) elem->l_hatom.h_w.w_obj)) {
				edited = baby->l_parent; // the (sub)list the surgery will be performed on	
				llll_destroyelem(baby);
			}
			if (edited)
				llll_downgrade_depth(edited);	
		}
	}
	
	llll_free(baby_llll);
	pedantic_llll_check(ll);

	return;
}

// ---DESTRUCTIVE
void llll_tailpad_with_last(t_llll *ll, long newsize)
{
	t_llllelem *prevtail;
	long lasttype;
	long origsize = ll->l_size;
	prevtail = ll->l_tail;
	lasttype = hatom_gettype(&prevtail->l_hatom);
	if (lasttype != H_LLLL) {
		for ( ; origsize < newsize; origsize++) {
			t_llllelem *newtail = llllelem_get();
			newtail->l_hatom = prevtail->l_hatom;
			newtail->l_parent = ll;
			newtail->l_prev = prevtail;
			prevtail->l_next = newtail;
			prevtail = newtail;
		}
	} else {
		t_llll *lastll = prevtail->l_hatom.h_w.w_llll;
		for ( ; origsize < newsize; origsize++) {
			t_llllelem *newtail = llllelem_get();
			hatom_setllll(&newtail->l_hatom, llll_clone(lastll));
			newtail->l_parent = ll;
			newtail->l_prev = prevtail;
			prevtail->l_next = newtail;
			prevtail = newtail;
		}
	}
	ll->l_tail = prevtail;
	ll->l_size = newsize;
	pedantic_llll_check(ll);
}

// ---DESTRUCTIVE
void llll_tailtrim(t_llll *ll, long newsize)
{
	t_llllelem *prev;
	t_llllelem *last = ll->l_tail;
	long critical_depth = ll->l_depth - 1;
	long origsize = ll->l_size;
	t_bool downgrade = false;
	for ( ; origsize > newsize; origsize--) {
		t_llll *lastll;
		prev = last->l_prev;
		if (!downgrade && (lastll = hatom_getllll(&last->l_hatom))) {
			if (lastll->l_depth == critical_depth)
				downgrade = true;
		}
		llllelem_free(last);
		last = prev;
	}
	last->l_next = NULL;
	ll->l_tail = last;
	ll->l_size = newsize;
	if (downgrade)
		llll_downgrade_depth(ll);
	pedantic_llll_check(ll);
}

// ---DESTRUCTIVE on ll, addresses, substitutions, sizes
// the contents of every sublist of substitutions will be replaced 
// sizes contains, for each substitution, the number of original elements to be replaced; if empty, it will be considered as 0s.
// a 0 size will cause a null substitution to remove one element, and any other substitution to replace its own number of elements
// (i.e., a 3-element long substitution will replace 3 elements)
// a non-0 size will cause the corresponding number of elements to be replaced or removed, regardless of the size of the substitution
void llll_multisubs(t_llll *ll, t_llll *addresses, t_llll *substitutions, t_llll *sizes)
{
	if (!ll)
		return;

	t_llllelem *subs_elem, *sizes_elem = NULL;
	t_llllelem **target_elems = NULL, **this_target_elems;
	long curr_size = 0;
	long subsize, addrsize, ssize;
	t_llll *sort_me[3];

	if (!ll || !addresses || addresses->l_size == 0)
		goto llll_multisubs_exit;

	// make sure that substitutions, addresses and sizes have the same size - that is, the size of addresses
	if (!substitutions)
		substitutions = llll_get();
	if (substitutions->l_size == 0)
		llll_appendllll(substitutions, llll_get(), 0, WHITENULL_llll);
	
	if (!sizes)
		sizes = llll_get();
	if (sizes->l_size == 0)
		llll_appendlong(sizes, 1, 0, WHITENULL_llll);
	
	subsize = substitutions->l_size;
	addrsize = addresses->l_size;
	ssize = sizes->l_size;
	
	if (subsize < addrsize) {
		llll_tailpad_with_last(substitutions, addrsize);
	} else if (subsize > addrsize) {
		llll_tailtrim(substitutions, addrsize);
	}
	
	if (ssize < addrsize) {
		llll_tailpad_with_last(sizes, addrsize);
	} else if (ssize > addrsize) {
		llll_tailtrim(sizes, addrsize);
	}
	
	llll_fatten(addresses);
	sort_me[0] = addresses;
	sort_me[1] = substitutions;
	sort_me[2] = sizes;
	llll_multisort(sort_me, sort_me, 3, llll_sort_addresses); // deepest elements must be placed first, and by the way why not sort by position?
	addresses = sort_me[0];
	substitutions = sort_me[1];
	sizes = sort_me[2];
	
	this_target_elems = target_elems = llll_find_multiple_elems(ll, addresses, true, false, false);
	if (!target_elems)
		goto llll_multisubs_exit;

	for (subs_elem = substitutions->l_head, sizes_elem = sizes->l_head, this_target_elems = target_elems; 
		 subs_elem; 
		 subs_elem = subs_elem->l_next, sizes_elem = sizes_elem->l_next, this_target_elems++) {
		t_llllelem *this_target = *this_target_elems;
		if (this_target) {
			t_llll *this_substitution = NULL;
			curr_size = hatom_getlong(&sizes_elem->l_hatom);
			if (curr_size < 0)
				curr_size = 0;
			if ((hatom_gettype(&subs_elem->l_hatom) == H_LLLL && (this_substitution = hatom_getllll(&subs_elem->l_hatom))->l_size == 0)) { // delete elements
				long elem_count;
				long elems_to_destroy = curr_size == 0 ? 1 : curr_size;
				t_llllelem *next_target;
				bool downgrade = false;
				t_llll *target_dad = this_target->l_parent;
				long critical_depth = target_dad->l_depth - 1;
				for (elem_count = 0; this_target && elem_count < elems_to_destroy; elem_count++, this_target = next_target) {
					t_llll *subll = hatom_getllll(&this_target->l_hatom);
					if (subll && subll->l_depth == critical_depth)
						downgrade = true;
					next_target = this_target->l_next;
					llll_destroyelem_no_depth_check(this_target);
				}
				if (downgrade)
					llll_downgrade_depth(target_dad);
			} else if (!this_substitution) { // substitute one element
				hatom_change_to_hatom_and_free(&this_target->l_hatom, &subs_elem->l_hatom);
				if (curr_size > 1) {
					long elem_count;
					t_llllelem *next_target;
					bool downgrade = false;
					t_llll *receiver = this_target->l_parent;
					long critical_depth = receiver->l_depth - 1;
					this_target = this_target->l_next;
					for (elem_count = 1; this_target && elem_count < curr_size; this_target = next_target, elem_count++) {
						t_llll *subll = hatom_getllll(&this_target->l_hatom);
						if (subll && subll->l_depth == critical_depth)
							downgrade = true;
						next_target = this_target->l_next;
						llll_destroyelem_no_depth_check(this_target);
					}
					if (downgrade)
						llll_downgrade_depth(receiver);
				}
			} else {
				long elems_to_replace = curr_size == 0 ? this_substitution->l_size : curr_size;
				long actual_elems;
				t_llllelem *target_end;
				t_llllelem *this_subs_elem;
				t_llll *deepest = NULL;
				long abyss = 0;
				bool downgrade = false;
				t_llll *receiver = this_target->l_parent;
				long critical_depth = receiver->l_depth - 1;
				
				// now we do the actual element-by-element substitutions
				for (target_end = this_target, this_subs_elem = this_substitution->l_head, actual_elems = 0;
					 target_end && this_subs_elem && actual_elems < elems_to_replace; 
					 target_end = target_end->l_next, this_subs_elem = this_subs_elem->l_next, actual_elems++) {
					t_llll *this_subs_ll = hatom_getllll(&this_subs_elem->l_hatom);
					t_llll *this_target_ll = hatom_getllll(&target_end->l_hatom);

					if (this_subs_ll) {
						t_llll *cloned_subs_ll = llll_clone(this_subs_ll);
						cloned_subs_ll->l_owner = target_end;
						if (cloned_subs_ll->l_depth > abyss) {
							abyss = cloned_subs_ll->l_depth;
							deepest = cloned_subs_ll;
						}
						hatom_setllll(&target_end->l_hatom, cloned_subs_ll);
					} else {
						target_end->l_hatom = this_subs_elem->l_hatom;
					}
						
					if (this_target_ll) {
						if (!downgrade && !deepest && this_target_ll->l_depth == critical_depth)
							downgrade = true;
						llll_free(this_target_ll);
					}
				}
				
				// do we have more elements to destroy?
				if (elems_to_replace > this_substitution->l_size) {
					if (target_end) {
						t_llllelem *last_replacement = target_end->l_prev;
						t_llllelem *next_target_end;
						for ( ; target_end && actual_elems < elems_to_replace; actual_elems++, target_end = next_target_end) {
							t_llll *this_target_ll = hatom_getllll(&target_end->l_hatom);
							if (!deepest && !downgrade && this_target_ll && this_target_ll->l_depth == critical_depth)
								downgrade = true;
							next_target_end = target_end->l_next;
							llllelem_free(target_end);
						}
						last_replacement->l_next = target_end;
						if (!target_end)
							receiver->l_tail = last_replacement;
						else
							target_end->l_prev = last_replacement;
					}
				// do we have more elements to insert?
				} else if (actual_elems < this_substitution->l_size) {
					t_llllelem *last_inserted;
					if (target_end) { // there are elements after (so it's an actual insertion, rather than appending)
						last_inserted = target_end->l_prev;
						target_end->l_prev = this_substitution->l_tail;
					} else {
						last_inserted = receiver->l_tail;
						receiver->l_tail = this_substitution->l_tail;
					}
					
					this_subs_elem->l_prev->l_next = NULL;
					this_subs_elem->l_prev = last_inserted;
					this_substitution->l_tail->l_next = target_end;
					last_inserted->l_next = this_subs_elem;
					this_substitution->l_tail = this_subs_elem->l_prev;
					
					for ( ; this_subs_elem != target_end; this_subs_elem = this_subs_elem->l_next) {
						this_subs_elem->l_parent = receiver;
						t_llll *this_subs_ll = hatom_getllll(&this_subs_elem->l_hatom);
						if (this_subs_ll && this_subs_ll->l_depth > abyss) {
							abyss = this_subs_ll->l_depth;
							deepest = this_subs_ll;
						}
					}
				}
				receiver->l_size += this_substitution->l_size - actual_elems;
				if (deepest)
					llll_upgrade_depth(deepest);
				else if (downgrade)
					llll_downgrade_depth(receiver);
			}
		}
	}
llll_multisubs_exit:
	bach_freeptr(target_elems);
	llll_free(addresses);
	llll_free(sizes);
	llll_free_nocheck(substitutions); // as bad things have been done to it!
	pedantic_llll_check(ll);
	return;
}

// --- DESTRUCTIVE on ll (elements are inserted), addresses (is sorted) and insertions (is sorted)
void llll_multiinsert_a(t_llll *ll, t_llll *addresses, t_llll *insertions)
{
	if (!ll)
		return;
	
	t_llllelem *ins_elem, *addresses_elem;
	t_llllelem **target_elems = NULL, **this_target_elems;
	long inssize, addrsize;
	t_llll *sort_me[2];
	
	if (!ll || !addresses || addresses->l_size == 0 || !insertions || insertions->l_size == 0)
		goto llll_multiinsert_a_exit;
	
	// make sure that insertions and addresses have the same size - that is, the size of addresses
	
	inssize = insertions->l_size;
	addrsize = addresses->l_size;
	
	if (inssize < addrsize) {
		llll_tailpad_with_last(insertions, addrsize);
	} else if (inssize > addrsize) {
		llll_tailtrim(insertions, addrsize);
	}
	
	llll_fatten(addresses);
	llll_fatten(insertions);
	sort_me[0] = addresses;
	sort_me[1] = insertions;
	llll_multisort(sort_me, sort_me, 2, llll_sort_addresses); // deepest elements must be placed first, and by the way why not sort by position?
	addresses = sort_me[0];
	insertions = sort_me[1];
	
	this_target_elems = target_elems = llll_find_multiple_elems(ll, addresses, false, false, false);
	if (!target_elems)
		goto llll_multiinsert_a_exit;
	
	for (ins_elem = insertions->l_head, addresses_elem = addresses->l_head, this_target_elems = target_elems; 
		 ins_elem; 
		 ins_elem = ins_elem->l_next, addresses_elem = addresses_elem->l_next, this_target_elems++) {
		t_llll *this_insertion;
		t_llllelem *this_target = *this_target_elems;
		if (this_target && (this_insertion = hatom_getllll(&ins_elem->l_hatom))) {
			if (this_insertion->l_size == 0)
				llll_appendllll(this_insertion, llll_get(), 0, WHITENULL_llll);
			llll_insert_one(this_target, this_insertion, hatom_getlong(&hatom_getllll(&addresses_elem->l_hatom)->l_tail->l_hatom));
		}
	}
llll_multiinsert_a_exit:
	bach_freeptr(target_elems);
	llll_free(addresses);
	llll_free_nocheck(insertions); // as bad things have been done to it!
	pedantic_llll_check(ll);
	return;
}

// --- DESTRUCTIVE on ll (elements are inserted), addresses (is sorted) and insertions (is sorted)
void llll_multiinsert_b(t_llll *ll, t_llll *addresses, t_llll *insertions)
{
	if (!ll)
		return;
	
	t_llllelem *ins_elem, *addresses_elem;
	long inssize, addrsize;
	t_llll *sort_me[2];
	t_llll *single_address_ll = NULL;
	t_hatom nothing;
	t_llllelem *one_address_elem = NULL;
	
	if (!ll || !addresses || addresses->l_size == 0 || !insertions || insertions->l_size == 0)
		goto llll_multiinsert_b_exit;
	
	// make sure that insertions and addresses have the same size - that is, the size of addresses
	
	inssize = insertions->l_size;
	addrsize = addresses->l_size;
	
	if (inssize < addrsize) {
		llll_tailpad_with_last(insertions, addrsize);
	} else if (inssize > addrsize) {
		llll_tailtrim(insertions, addrsize);
	}
	
	llll_fatten(addresses);
	llll_fatten(insertions);
	sort_me[0] = addresses;
	sort_me[1] = insertions;
	llll_multisort(sort_me, sort_me, 2, llll_sort_addresses_for_insert_b); // sort by position
	addresses = sort_me[0];
	insertions = sort_me[1];
	
	single_address_ll = llll_get();
	nothing.h_type = H_NOTHING;
	one_address_elem = llll_appendhatom(single_address_ll, &nothing, 0, WHITENULL_llll);
	//one_address_elem->l_parent = single_address_ll;
	for (ins_elem = insertions->l_head, addresses_elem = addresses->l_head; ins_elem; ins_elem = ins_elem->l_next, addresses_elem = addresses_elem->l_next) {
		t_llllelem *this_target;
		t_llll *this_insertion;
		t_llllelem **out_arr;
		hatom_setllll(&one_address_elem->l_hatom, addresses_elem->l_hatom.h_w.w_llll);
		out_arr = llll_find_multiple_elems(ll, single_address_ll, true, true, true);
		this_target = *out_arr;
		bach_freeptr(out_arr);
		
		if (this_target && (this_insertion = hatom_getllll(&ins_elem->l_hatom))) {
			if (this_insertion->l_size == 0)
				llll_appendllll(this_insertion, llll_get(), 0, WHITENULL_llll);
			llll_insert_one(this_target, this_insertion, hatom_getlong(&hatom_getllll(&addresses_elem->l_hatom)->l_tail->l_hatom));
			if (this_target->l_thing.w_long != 0)
				llll_destroyelem(this_target);
		}
	}
	one_address_elem->l_hatom.h_type = H_OBJ;
llll_multiinsert_b_exit:
	llll_free(addresses);
	llll_free(single_address_ll);
	llll_free_nocheck(insertions); // as bad things have been done to it!
	pedantic_llll_check(ll);
	return;
}

void llll_insert_one(t_llllelem *target, t_llll *insertion, long direction)
{
	t_llllelem *this_insertion_elem;
	t_llll *receiver = target->l_parent;
	t_llll *deepest = NULL;
	long abyss = receiver->l_depth - 1;
	for (this_insertion_elem = insertion->l_head; this_insertion_elem; this_insertion_elem = this_insertion_elem->l_next) {
		t_llll *subll = hatom_getllll(&this_insertion_elem->l_hatom);
		if (subll && subll->l_depth > abyss) {
			deepest = subll;
			abyss = subll->l_depth;
		}
		this_insertion_elem->l_parent = receiver;
	}
	if (direction >= 0) {
		t_llllelem *elem_before = target->l_prev;
		if (elem_before) {
			elem_before->l_next = insertion->l_head;
			insertion->l_head->l_prev = elem_before;
		} else
			receiver->l_head = insertion->l_head;
		target->l_prev = insertion->l_tail;
		insertion->l_tail->l_next = target;
	} else {
		t_llllelem *elem_after = target->l_next;
		if (elem_after) {
			elem_after->l_prev = insertion->l_tail;
			insertion->l_tail->l_next = elem_after;
		} else
			receiver->l_tail = insertion->l_tail;
		target->l_next = insertion->l_head;
		insertion->l_head->l_prev = target;
	}
	receiver->l_size += insertion->l_size;
	if (deepest)
		llll_upgrade_depth(deepest);
	insertion->l_size = 0;
	insertion->l_depth = 1;
	insertion->l_head = insertion->l_tail = NULL;
	pedantic_llll_check(target->l_parent);
}

//---DESTRUCTIVE if create != 0
// gets the llllelem pointed by address (the syntax of address is the address syntax of bach.nth)
// root is the root of the search space - i.e., the base-list to search in
// if create != 0, a non-existing llllelem is created and set to nil
// baby_llll is an empty llll that will contain H_OBJs pointing to each found llllelem
// directions can be NULL, or an empty llll that will contain a series of 1 and -1
// each 1 corresponds to a llll level that has been searched forward,
// each -1 to a llll level that has been searched backwards
// this is used by llll_insert_method()
void llll_findchildren(const t_llll *root, t_llll *address, long create, t_llll *baby_llll, t_llll *directions) // wants 2 empty lllls
{
	t_hatom *this_address_hatom, *this_multi_hatom;
	t_llll *multi;
	t_llll *mommy = NULL;
	t_llll *range;
	t_llllelem *elem, *multi_elem;
	t_llllelem *baby = (t_llllelem *) 0xFFFFFFFF;
	t_hatom daddy;
	t_atom_long mommylen = 0, start = 0, end = 0, rangestep, i, idx;
	long dir = 0, address_was_built_here = 0;
	
	if (!root || !baby_llll)
		return;

	hatom_setllll(&daddy, root);
	
	if (!address || address->l_size == 0) {
		address = llll_get();
		llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
		address_was_built_here = 1;
	}
	
	elem = address->l_head; 
	
	while (daddy.h_type != H_NOTHING && elem) {
		if (hatom_gettype(this_address_hatom = &elem->l_hatom) != H_LLLL) { // if it's just a number
			if (baby && hatom_gettype(&daddy) == H_LLLL) { // if daddy is an llll
				mommy = hatom_getllll(&daddy);
				baby = llll_getindex(mommy, idx = hatom_getlong(this_address_hatom), I_STANDARD); 
				if (baby) {
					daddy = baby->l_hatom;
					dir = idx >= 0 ? 1 : -1;
				} else if (create) {
					if (idx >= LLLL_IDX_BASE) {
						idx -= LLLL_IDX_BASE;
						for (i = mommy->l_size; i <= idx; i++)
							llll_appendllll(mommy, llll_get(), 0, WHITENULL_llll); 
						baby = mommy->l_tail;
						daddy = baby->l_hatom;
						dir = 0;
						llll_upgrade_depth(daddy.h_w.w_llll);
					} else if (idx < 0) {
						for (i = -mommy->l_size; i > idx; i--)
							llll_prependllll(mommy, llll_get(), 0, WHITENULL_llll);
						baby = mommy->l_head;
						daddy = baby->l_hatom;
						dir = 0;
						llll_upgrade_depth(daddy.h_w.w_llll);
					}
				else
					daddy.h_type = H_NOTHING;
				}
			} else // if (baby && hatom_getlong(this_address_hatom) != LLLL_IDX_BASE)  // if we search for a non-LLLL_IDX_BASEth element of a non-llll, we obtain nil
				baby = NULL;
			
			if (!(elem = elem->l_next)) { // if it's the last element of the address
				llll_appendobj(baby_llll, baby, 0, WHITENULL_llll);
				if (directions)
					llll_appendlong(directions, dir, 0, WHITENULL_llll);
			}
			
		} else { // if it's an llll we treat it as the last element, and start traversing it
			
			multi = hatom_getllll(&elem->l_hatom);
			mommy = hatom_getllll(&daddy);
			if (mommy)
				mommylen = mommy->l_size;

			for (multi_elem = multi->l_head; multi_elem; multi_elem = multi_elem->l_next) {		
				if (hatom_gettype(this_multi_hatom = &multi_elem->l_hatom) != H_LLLL) { // if it's just a number
					idx = hatom_getlong(this_multi_hatom);
					if (mommy) {
						baby = llll_getindex(mommy, idx, I_STANDARD);
						if (!baby && create) {
							if (idx >= LLLL_IDX_BASE) {
								idx -= LLLL_IDX_BASE;
								for (i = mommylen; i <= idx; i++)
									llll_appendllll(mommy, llll_get(), 0, WHITENULL_llll); // the newly created elements are non-legal!
								baby = mommy->l_tail;
								llll_upgrade_depth(baby->l_hatom.h_w.w_llll);
							} else if (idx < 0) {
								for (i = -mommylen; i > idx; i++)
									llll_prependllll(mommy, llll_get(), 0, WHITENULL_llll);
								baby = mommy->l_head;
								llll_upgrade_depth(baby->l_hatom.h_w.w_llll);
							} else
								baby = NULL;
							dir = 0;
						} else
							dir = idx >= 0 ? 1 : -1;
					} else {
						if (idx != LLLL_IDX_BASE) {
							baby = NULL;
						}
						dir = 1;
					}
					llll_appendobj(baby_llll, baby, 0, WHITENULL_llll);
					if (directions)
						llll_appendlong(directions, dir, 0, WHITENULL_llll);

				} else { // if it's a ll
					range = hatom_getllll(this_multi_hatom);
					if (range->l_size) {
						start = hatom_getlong(&range->l_head->l_hatom);
						dir = start >= 0 ? 1 : -1;
						if (start < 0)
							start += mommylen + LLLL_IDX_BASE;

						end = hatom_getlong(&range->l_tail->l_hatom);
						if (end < 0)
							end += mommylen + LLLL_IDX_BASE;

						rangestep = (start <= end) ? 1 : -1;
						i = start;
						
						// first, I look for the first element of the range with llll_getindex
						// I want to use llll_getindex() as rarely as possible, 
						// since it is far more expensive than just walking the llll
						if (mommy)
							baby = llll_getindex(mommy, i, I_NON_NEGATIVE);
						
						while ((rangestep > 0 && i <= end) || (rangestep < 0 && i >= end)) {
							if (directions)
								llll_appendlong(directions, dir, 0, WHITENULL_llll);
							if (mommy) {
								llll_appendobj(baby_llll, baby, 0, WHITENULL_llll);
								if (baby) // walk to the next element of the range
									baby = rangestep > 0 ? baby->l_next : baby->l_prev;
								else if (i == 0 && start == 0)
									baby = mommy->l_head; // so next time we'll have something to work upon!
	//							else if (i >= LLLL_IDX_BASE && i < mommylen + LLLL_IDX_BASE) // this should never happen!
	//								baby = llll_getindex(mommy, i, I_NON_NEGATIVE);
							} else if (i == LLLL_IDX_BASE) // if we're looking for the first element of a non-sublist
								llll_appendobj(baby_llll, baby, 0, WHITENULL_llll);
							else // if there is nothing where we're looking at!!
								llll_appendobj(baby_llll, NULL, 0, WHITENULL_llll);
							i += rangestep;
							if (i == 0)
								i += rangestep;
						}
					}
				}
			}
			break;
		}
	}
	
	if (address_was_built_here) { // which means that address has been built here
		llll_free(address);
	}
	pedantic_llll_check(root);

}

long llll_sort_addresses(void *dummy, t_llllelem *a, t_llllelem *b)
{
	t_llll *a_ll = hatom_getllll(&a->l_hatom);
	t_llll *b_ll = hatom_getllll(&b->l_hatom);
	t_llllelem *a_elem, *b_elem;
	if (a_ll->l_size != b_ll->l_size)
		return b_ll->l_size < a_ll->l_size;
	for (a_elem = a_ll->l_head, b_elem = b_ll->l_head; a_elem; a_elem = a_elem->l_next, b_elem = b_elem->l_next) {
		long a_val = hatom_getlong(&a_elem->l_hatom);
		long b_val = hatom_getlong(&b_elem->l_hatom);
		if (a_val == b_val)
			continue;
		if (a_val < 0 && b_val < 0)
			return b_val <= a_val;
		else
			return a_val <= b_val;
	}
	return 1;
}

long llll_sort_addresses_for_insert_b(void *dummy, t_llllelem *a, t_llllelem *b)
{
	t_llll *a_ll = hatom_getllll(&a->l_hatom);
	t_llll *b_ll = hatom_getllll(&b->l_hatom);
	t_llllelem *a_elem, *b_elem;
	for (a_elem = a_ll->l_head, b_elem = b_ll->l_head; a_elem && b_elem; a_elem = a_elem->l_next, b_elem = b_elem->l_next) {
		long a_val = hatom_getlong(&a_elem->l_hatom);
		long b_val = hatom_getlong(&b_elem->l_hatom);
		if (a_val == b_val)
			continue;
		if (a_val < 0 && b_val < 0)
			return b_val <= a_val;
		else
			return a_val <= b_val;
	}
	return b_elem ? 1 : 0;
}

// return an array of llllelem*, the size equal to the size of addresses
// --- DESTRUCTIVE on ll (edits it to create new addresses) if create_elems and force_create_lists are set
t_llllelem **llll_find_multiple_elems(t_llll *ll, t_llll *addresses, t_bool create_elems, t_bool force_create_lists, t_bool mark_created_targets)
{
	t_llllelem **out_arr, **this_out_arr;
	t_llllelem *elem;
	t_llll *curr_address = NULL, *prev_address = NULL, *scanned_ll = NULL;
	t_llllelem *curr_address_elem, *prev_address_elem;
	t_llllelem **elem_pile, **this_elem_pile;
	t_llllelem *found_elem = NULL;
	t_bool prev_is_temp = false, curr_is_temp = false;
	t_bool created = false;
	long elem_pile_size;
	if (!ll) {
		//llll_free(addresses);
		return NULL;
	}
	
	if (ll->l_size == 0 && create_elems) {
		llll_appendllll(ll, llll_get(), 0, WHITENULL_llll);
		created = true;
	}

	out_arr = (t_llllelem **) bach_newptr(addresses->l_size * sizeof(t_llllelem *));
	this_elem_pile = elem_pile = (t_llllelem **) bach_newptr(MULTI_FIND_PILE_SIZE_STEP * sizeof(t_llllelem *));
	for (elem = addresses->l_head, this_out_arr = out_arr; elem; elem = elem->l_next, this_out_arr++) {
		long target_idx = 0, current_idx = 0;
		long type = hatom_gettype(&elem->l_hatom);
		switch (type) {
			case H_LLLL:
				curr_address = elem->l_hatom.h_w.w_llll;
				curr_is_temp = false;
				break;
			case H_LONG:
				curr_address = llll_get();
				llll_appendlong(curr_address, elem->l_hatom.h_w.w_long, 0, WHITENULL_llll);
				curr_is_temp = true;
				break;
			default:
				curr_address = NULL;
				curr_is_temp = false;
				break;
		}
		
		if (curr_address && curr_address->l_size) {
			if (prev_address == NULL || scanned_ll == NULL || found_elem == NULL) { // if the previous address was unavailable...
				// ... restart from the beginning
				//if (!scanned_ll)
					scanned_ll = ll;
				this_elem_pile = elem_pile;
				curr_address_elem = curr_address->l_head;
				target_idx = hatom_getlong(&curr_address_elem->l_hatom);
				if (target_idx == 0)
					target_idx = 1;
				if (target_idx > 0) {
					current_idx = 1;
					found_elem = scanned_ll->l_head;
				} else {
					current_idx = -1;
					found_elem = scanned_ll->l_tail;
				}
			} else {
				long ok_depth = 1;
				long i;
				for (curr_address_elem = curr_address->l_head, prev_address_elem = prev_address->l_head;
					 curr_address_elem && prev_address_elem && hatom_getlong(&curr_address_elem->l_hatom) == hatom_getlong(&prev_address_elem->l_hatom);
					 curr_address_elem = curr_address_elem->l_next, prev_address_elem = prev_address_elem->l_next) {
					ok_depth++;
				}
				if (curr_address_elem == NULL) { // if all the current address's elements are the same as the corresponding ones from the previous address...
					if (prev_address_elem) { // ... but the previous address is longer than the current
						// ... then climb back to the owner of the sublist pointed by the current address
						for (i = prev_address->l_size; i > ok_depth; i--)
							scanned_ll = scanned_ll->l_owner->l_parent;
						found_elem = scanned_ll->l_owner;
					} // if the previous and current addresses are the same, they point to the same element so we don't have anything to do here!
					// in either case, no need to set idx since the element-finding while loop will be skipped
				} else if (prev_address_elem == NULL) { // which means that the previous target element was a sublist, and the current target element belongs to its tree
					scanned_ll = hatom_getllll(&found_elem->l_hatom);
					target_idx = hatom_getlong(&curr_address_elem->l_hatom);
					if (target_idx == 0)
						target_idx = 1;
					if (target_idx > 0) {
						current_idx = 1;
						found_elem = scanned_ll ? scanned_ll->l_head : NULL;
					} else {
						current_idx = -1;
						found_elem = scanned_ll ? scanned_ll->l_tail : NULL;
					}
				} else {
					if (ok_depth == 1) {
						scanned_ll = ll;
						this_elem_pile = elem_pile;
						found_elem = *this_elem_pile;
					} else {
						--this_elem_pile;
						for (i = prev_address->l_size; i > ok_depth; i--) {
							scanned_ll = scanned_ll->l_owner->l_parent;
							this_elem_pile--;
						}
						found_elem = *this_elem_pile;
					}
					current_idx = hatom_getlong(&prev_address_elem->l_hatom);
					if (current_idx == 0)
						current_idx = 1;
					target_idx = hatom_getlong(&curr_address_elem->l_hatom);
					if (target_idx == 0)
						target_idx = 1;
					if (current_idx < 0 && target_idx > 0) {
						current_idx = scanned_ll->l_size + current_idx + 1;
					} else if (current_idx > 0 && target_idx < 0) {
						current_idx = current_idx - scanned_ll->l_size - 1;
					}
				}
			}
			while (curr_address_elem) {					
				if (target_idx > 0) {
					if (target_idx > current_idx) {
						for ( ; found_elem && current_idx < target_idx; current_idx++) {
							found_elem = found_elem->l_next;
						}
						if (found_elem == NULL && create_elems) {
							t_llll *newll = NULL;
							t_llllelem *prevnew = NULL;
							if (scanned_ll->l_size == 0) {
								t_llllelem *newelem = llllelem_get();
								newll = llll_get();
								hatom_setllll(&newelem->l_hatom, newll);
								newll->l_owner = newelem;
								newelem->l_parent = scanned_ll;
								scanned_ll->l_head = newelem;
								prevnew = newelem;
								current_idx++;
							} else {
								prevnew = scanned_ll->l_tail;
							}
							for ( ; current_idx <= target_idx; current_idx++) {
								t_llllelem *newelem = llllelem_get();
								newll = llll_get();
								hatom_setllll(&newelem->l_hatom, newll);
								newll->l_owner = newelem;
								newelem->l_parent = scanned_ll;
								prevnew->l_next = newelem;
								newelem->l_prev = prevnew;
								prevnew = newelem;
							}
							scanned_ll->l_tail = found_elem = prevnew;
							scanned_ll->l_size = target_idx;
							if (scanned_ll->l_depth < 2)
								llll_upgrade_depth(newll);		
							created = true;
						}
					} else {
						for ( ; found_elem && current_idx > target_idx; current_idx--) {
							found_elem = found_elem->l_prev;
						}
					}

				} else {
					if (target_idx < current_idx) {
						for ( ; found_elem && current_idx > target_idx; current_idx--) {
							found_elem = found_elem->l_prev;
						}
						if (found_elem == NULL && create_elems) {
							t_llll *newll = NULL;
							t_llllelem *prevnew = NULL;
							if (scanned_ll->l_size == 0) {
								t_llllelem *newelem = llllelem_get();
								newll = llll_get();
								hatom_setllll(&newelem->l_hatom, newll);
								newll->l_owner = newelem;
								newelem->l_parent = scanned_ll;
								scanned_ll->l_tail = prevnew;
								prevnew = newelem;
								current_idx--;
							} else {
								prevnew = scanned_ll->l_head;
							}
							for ( ; current_idx >= target_idx; current_idx--) {
								t_llllelem *newelem = llllelem_get();
								newll = llll_get();
								hatom_setllll(&newelem->l_hatom, newll);
								newll->l_owner = newelem;
								newelem->l_parent = scanned_ll;
								prevnew->l_prev = newelem;
								newelem->l_next = prevnew;
								prevnew = newelem;
							}
							scanned_ll->l_head = found_elem = prevnew;
							scanned_ll->l_size = -target_idx;
							if (scanned_ll->l_depth < 2)
								llll_upgrade_depth(newll);		
							created = true;
						}
					} else {
						for ( ; found_elem && current_idx < target_idx; current_idx++) {
							found_elem = found_elem->l_next;
						}
					}
				}
				curr_address_elem = curr_address_elem->l_next;
				*(this_elem_pile++) = found_elem;
				elem_pile_size = this_elem_pile - elem_pile;
				if (elem_pile_size % MULTI_FIND_PILE_SIZE_STEP == 0) {
					elem_pile = (t_llllelem **) bach_resizeptr(elem_pile, (elem_pile_size + MULTI_FIND_PILE_SIZE_STEP) * sizeof(t_llllelem *));
					this_elem_pile = elem_pile + elem_pile_size;
				}
				if (!found_elem)
					break;
				if (curr_address_elem) {
					scanned_ll = hatom_getllll(&found_elem->l_hatom);
					if (!scanned_ll) {
						if (force_create_lists) {
							if (target_idx > 0) // this is the "old" target index
								found_elem = llll_insertllll_before(scanned_ll = llll_get(), found_elem, 0, WHITENULL_llll);
							else
								found_elem = llll_insertllll_after(scanned_ll = llll_get(), found_elem, 0, WHITENULL_llll);
						} else {
							found_elem = NULL;
							break;
						}
					}
					if (create_elems && (scanned_ll->l_size == 0)) {
						llll_appendllll(scanned_ll, llll_get(), 0, WHITENULL_llll);
						created = true;
					}
					target_idx = hatom_getlong(&curr_address_elem->l_hatom);
					if (target_idx == 0)
						target_idx = 1;
					if (target_idx > 0) {
						current_idx = 1;
						found_elem = scanned_ll->l_head;
					} else {
						current_idx = -1;
						found_elem = scanned_ll->l_tail;
					}
				}
			}
		} else {
			found_elem = NULL;
		}
		if (found_elem && created && mark_created_targets)
			found_elem->l_thing.w_long = 1;
		
		*this_out_arr = found_elem;
		
		if (prev_is_temp)
			llll_free(prev_address);
		prev_address = curr_address;
		prev_is_temp = curr_is_temp;
	}
	if (prev_is_temp)
		llll_free(prev_address);
	bach_freeptr(elem_pile);
	pedantic_llll_check(ll);
	return out_arr;
}

int llll_compare_elems_by_thing(t_llllelem **a, t_llllelem **b) 
{
	if (*a == NULL && *b == NULL)
		return 0;
	if (*a == NULL)
		return 1;
	if (*b == NULL)
		return -1;
	return (*a)->l_thing.w_long - (*b)->l_thing.w_long;
}

/*
 
 ---DESTRUCTIVE---
 *out is an uninitialised pointer
 data is passed unchanged to cmpfn at each call
 
 cmpfn will return 0 if the elements must be swapped, 1 otherwise
 
 */

void llll_mergesort(t_llll *in, t_llll **out, sort_fn cmpfn, void *data)
{
	t_llll *out_ll;
	t_atom_long chunksize, merges, asize, bsize, i;
	t_llllelem *a, *b;
	
	if (!in)
		return;
	
	for (a = in->l_head; a; a = a->l_next)
		a->l_flags = OBJ_FLAG_DATA;
	
	if (in->l_size <= 1) {
		*out = in;
		return;
	}
	
	chunksize = 1;
	do {
		*out = llll_get();
		out_ll = *out;
		merges = 0;
		a = b = in->l_head;
		
		while (a) {
			merges ++;
			asize = 0;
			
			for (i = 0; i < chunksize && b; i++) {
				b = b->l_next;
				asize++;
			}
			
			bsize = asize; 
			
			while (asize != 0 || (b && bsize != 0)) {
				if (asize == 0) { // it is important that this chain of if ... else is in this order!
					llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					b = b->l_next;
					bsize--;
				} else if (bsize == 0 || !b) {
					llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					a = a->l_next;
					asize--;
				} else if ((*cmpfn)(data, a, b)) {
					llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					a = a->l_next;
					asize--;
				} else {
					llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					b = b->l_next;
					bsize--;
				}
			}
			a = b;
		}
		
		llll_free_nocheck(in); // depth is broken
		in = out_ll;
		chunksize *= 2;
		
	} while (merges > 1);
	
	for (a = out_ll->l_head; a; a = a->l_next)
		a->l_flags = 0;
	
	llll_adopt(out_ll, out_ll);
	pedantic_llll_check(out_ll);
}

void llll_mergesort_with_lthings(t_llll *in, t_llll **out, sort_fn cmpfn, void *data)
{
	t_llll *out_ll;
	t_atom_long chunksize, merges, asize, bsize, i;
	t_llllelem *a, *b, *n;
	
	if (!in)
		return;
	
	for (a = in->l_head; a; a = a->l_next)
		a->l_flags = OBJ_FLAG_DATA;
	
	if (in->l_size <= 1) {
		*out = in;
		return;
	}
	
	chunksize = 1;
	do {
		*out = llll_get();
		out_ll = *out;
		merges = 0;
		a = b = in->l_head;
		
		while (a) {
			merges ++;
			asize = 0;
			
			for (i = 0; i < chunksize && b; i++) {
				b = b->l_next;
				asize++;
			}
			
			bsize = asize; 
			
			while (asize != 0 || (b && bsize != 0)) {
				if (asize == 0) { // it is important that this chain of if ... else is in this order!
					n = llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					n->l_thing.w_whole = b->l_thing.w_whole;
					b = b->l_next;
					bsize--;
				} else if (bsize == 0 || !b) {
					n = llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					n->l_thing.w_whole = a->l_thing.w_whole;
					a = a->l_next;
					asize--;
				} else if ((*cmpfn)(data, a, b)) {
					n = llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					n->l_thing.w_whole = a->l_thing.w_whole;
					a = a->l_next;
					asize--;
				} else {
					n = llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
					n->l_thing.w_whole = b->l_thing.w_whole;
					b = b->l_next;
					bsize--;
				}
			}
			a = b;
		}
		
		llll_free_nocheck(in); // depth is broken
		in = out_ll;
		chunksize *= 2;
		
	} while (merges > 1);
	
	for (a = out_ll->l_head; a; a = a->l_next)
		a->l_flags = 0;
	
	llll_adopt(out_ll, out_ll);
	pedantic_llll_check(out_ll);
}




#ifdef ___destructive
void llll_inplacesort(t_llll *ll, sort_fn cmpfn, void *data)
{
	t_atom_long chunksize, merges, asize, bsize, i;
	t_llllelem *a, *b;
	
	if (!ll)
		return;
/*
	for (a = in->l_head; a; a = a->l_next)
		a->l_flags = OBJ_FLAG_DATA;*/
	
	if (ll->l_size <= 1) {
		return;
	}
	
	chunksize = 1;
	do {
		merges = 0;
		a = b = ll->l_head;
		
		while (a) {
			merges ++;
			asize = 0;
			
			for (i = 0; i < chunksize && b; i++) {
				b = b->l_next;
				asize++;
			}
			
			bsize = asize;
			
			while (asize != 0 || (b && bsize != 0)) {
				if (asize == 0) { // don't move
					//t_llllelem *b_next = b->l_next;
					//llll_inplacesort_move_elem(ll, a, b);
					b = b->l_next;
					bsize--;
				} else if (bsize == 0 || !b) { // don't move
					a = a->l_next;
					asize--;
				} else if ((*cmpfn)(data, a, b)) { // don't move
					a = a->l_next;
					asize--;
				} else { // move
					t_llllelem *b_next = b->l_next;
					//post("placing %ld before %ld", hatom_getlong(&a->l_hatom), hatom_getlong(&b->l_hatom));
					llll_inplacesort_move_elem(ll, a, b);
					b = b_next;
					bsize--;
				}
			}
			a = b;
			//llll_print(ll, NULL, 0, 0, NULL);
		}
		
		//llll_free_nocheck(in); // depth is broken
		//in = out_ll;
		chunksize *= 2;
		
	} while (merges > 1);
	//pedantic_llll_check(ll);
	
//	for (a = out_ll->l_head; a; a = a->l_next)
//		a->l_flags = 0;
	
//	llll_adopt(out_ll, out_ll);
}
#else

/*
 this is a "fake" inplace sort. don't use it unless you really have to.
 it is slower, and uses more memory, than llll_mergesort
 moreover, you can't pass data to cmpfn
 */
void llll_inplacesort(t_llll *ll, sort_fn cmpfn, void *data)
{
	t_llll *in;
	t_llll *out;
	t_llllelem *el;
	
	if (!ll || ll->l_size < 2)
		return;
	
	in = llll_get();
	
	for (el = ll->l_head; el; el = el->l_next)
		llll_appendobj(in, el, 0, WHITENULL_llll);
	
	llll_mergesort(in, &out, (sort_fn) llll_objcmpfn, (void *) cmpfn);
	
	ll->l_size = 0;
	ll->l_depth = 1;
	ll->l_head = ll->l_tail = NULL;
	
	for (el = out->l_head; el; el = el->l_next)
		llll_append(ll, (t_llllelem *) el->l_hatom.h_w.w_obj, WHITENULL_llll);
	
	llll_free(out);
	pedantic_llll_check(ll);
}
#endif


// move b before a; both must be elements of ll, and a must actually precede b - and subsequently b must not be ll's head
void llll_inplacesort_move_elem(t_llll *ll, t_llllelem *a, t_llllelem *b)
{
	if (a->l_next == b) {
		if (a->l_prev) {
			a->l_prev->l_next = b;
			b->l_prev = a->l_prev;
		} else {
			ll->l_head = b;
			b->l_prev = NULL;
		}
		if (b->l_next) {
			b->l_next->l_prev = a;
			a->l_next = b->l_next;
		} else {
			ll->l_tail = a;
			a->l_next = NULL;
		}
		b->l_next = a;
		a->l_prev = b;
		//if (llll_check(ll))
		//	post("bah");
	} else {
		if (b->l_next) {
			b->l_prev->l_next = b->l_next;
			b->l_next->l_prev = b->l_prev;
		} else {
			ll->l_tail = b->l_prev;
			b->l_prev->l_next = NULL;
		}
		if (a->l_prev) {
			a->l_prev->l_next = b;
			b->l_prev = a->l_prev;
		} else {
			ll->l_head = b;
			b->l_prev = NULL;
		}
		a->l_prev = b;
		b->l_next = a;
		//if (llll_check(ll))
		//	post("boh");
	}
}



long llll_objcmpfn(sort_fn cmpfn, t_llllelem *a, t_llllelem *b)
{
	return (cmpfn)(NULL, (t_llllelem *)a->l_hatom.h_w.w_obj, (t_llllelem *)b->l_hatom.h_w.w_obj);
}


// DESTRUCTIVE!
// (the elements of the inlist array are destroyed, not the array itself!)
//
// sorts num lists in parallel - that is, sorts the first one and the others according to its indices
// e.g., (3 2 4 1) (a b c d) will be sorted as (1 2 3 4) (d b a c)
//
// if the lists are not all the same size, the behaviour is undefined and bad things can happen!
//
// outlist can be initialized, or NULL (in which case is initialized). It can even be == inlist (that is, llll_multisort can work in place)
//
// NB: cmpfn must be a regular sort_fn but it will be always passed NULL as its first argument
void llll_multisort(t_llll **inlist, t_llll **outlist, long num, sort_fn cmpfn)
{
	t_llll *inpacked, *intransed, *outtransed;
	t_llll **this_inlist, **this_outlist;
	t_llll *outpacked;
	t_llllelem *elem;
	long i;
	
	if (!outlist)
		outlist = (t_llll **) bach_newptr(num * sizeof(t_llll *));

	if ((*inlist)->l_size < 2) {
		sysmem_copyptr(inlist, outlist, num * sizeof(t_llll *)); // not bach_copyptr, as it could as well be a stack-allocated array!
		return;
	}
	
	inpacked = llll_get();
	for (i = 0, this_inlist = inlist; i < num; i++, this_inlist++)
		llll_appendllll(inpacked, *this_inlist, 0, WHITENULL_llll);
	
	intransed = llll_trans(inpacked, 0);
	
	llll_mergesort(intransed, &outtransed, (sort_fn) llll_multisort_fn, (void *) cmpfn);

	
	outpacked = llll_trans(outtransed, 0);
	
	for (this_outlist = outlist, elem = outpacked->l_head; elem; this_outlist++, elem = elem->l_next) {
		*this_outlist = elem->l_hatom.h_w.w_llll;
		(*this_outlist)->l_owner = NULL;
		elem->l_flags = OBJ_FLAG_DATA;
		pedantic_llll_check(*this_outlist);
	}
	
	//llll_fix_owner_for_check(outpacked);
	llll_free_nocheck(outpacked); // was: nocheck
} 

// (private) - an intermediate between llll_multisort and its cmpfn
long llll_multisort_fn(sort_fn cmpfn, t_llllelem *a, t_llllelem *b)
{
	return (*cmpfn)(NULL, a->l_hatom.h_w.w_llll->l_head, b->l_hatom.h_w.w_llll->l_head);
}


#ifdef ___destructive
void llll_trans_inplace(t_llll *in_ll, long mode)
{
	if (!in_ll)
		return;
	
	t_atom_long inlen = in_ll->l_size;
	
	if (inlen == 0)
		return;
	
	t_llll **sublist = (t_llll **) bach_newptr(inlen * sizeof(t_llll *));
	t_llll **this_sublist;
	t_llllelem **sublist_elem = (t_llllelem **) bach_newptr(inlen * sizeof(t_llllelem *));
	t_llllelem **this_sublist_elem;
	t_llllelem *inll_root_elem;
	t_llll *transed, *deepest;
	long go_on, i, deepest_depth;
	go_on = !mode;
	
	
	
	for (this_sublist_elem = sublist_elem, this_sublist = sublist, inll_root_elem = in_ll->l_head;
		 inll_root_elem;
		 this_sublist_elem++, this_sublist++, inll_root_elem = inll_root_elem->l_next) {
		*this_sublist = hatom_getllll(&inll_root_elem->l_hatom);
		if (*this_sublist) {
			*this_sublist_elem = (*this_sublist)->l_head;
			if (mode == 0)
				go_on = go_on && *this_sublist_elem;
			else
				go_on = go_on || *this_sublist_elem;
		} else
			go_on = 0;
		
		if (!go_on)
			break;
	}
	
	if (!go_on) {
		llll_clear(in_ll);
		bach_freeptr(sublist_elem);
		bach_freeptr(sublist);
		return;
	}
	
	transed = llll_get();
	deepest = NULL;
	deepest_depth = 0;
	while (go_on) {
		t_llll *transed_subll = llll_get();
		t_llllelem *tail = NULL;
		long size = 0;
		long sub_depth = 0;
		go_on = !mode;
		for (i = 0, this_sublist_elem = sublist_elem, this_sublist = sublist;
			 i < inlen;
			 i++, this_sublist_elem++, this_sublist++) {
			t_llllelem *elem = NULL;
			t_llllelem *next_elem = NULL;
			if (*this_sublist_elem) {
				elem = *this_sublist_elem;
				*this_sublist_elem = next_elem = elem->l_next;
				t_llll *sub_ll = hatom_getllll(&elem->l_hatom);
				if (next_elem) {
					next_elem->l_prev = NULL;
					(*this_sublist)->l_head = next_elem;
				} else {
					(*this_sublist)->l_head = NULL;
					(*this_sublist)->l_tail = NULL;
				}
				if (sub_ll && sub_ll->l_depth > sub_depth)
					sub_depth = sub_ll->l_depth;

				if (mode == 0)
					go_on = go_on && next_elem;
				else
					go_on = go_on || next_elem;
				size++;
			} else if (mode == 2) {
				t_llll *empty = llll_get();
				elem = llllelem_get();
				hatom_setllll(&elem->l_hatom, empty);
				empty->l_owner = elem;
				if (sub_depth == 0)
					sub_depth = 1;
				size++;
			}
			if (elem) {
				if (tail) {
					tail->l_next = elem;
				} else {
					elem->l_prev = NULL;
					transed_subll->l_head = elem;
				}
				transed_subll->l_tail = elem;
				elem->l_parent = transed_subll;
				elem->l_prev = tail;
				tail = elem;
			}
		}
		if (tail)
			tail->l_next = NULL;
		sub_depth += 1;
		transed_subll->l_size = size;
		transed_subll->l_depth = sub_depth;
		
		if (sub_depth > deepest_depth) {
			deepest = transed_subll;
			deepest_depth = sub_depth;
		}
		
		llll_appendllll(transed, transed_subll);
		
	}
	llll_clear_nocheck(in_ll); // sizes are broken
	llll_transfer(transed, in_ll);
	llll_free_nocheck(transed);
	if (deepest)
		llll_upgrade_depth(deepest);
	if (in_ll->l_owner)
		llll_downgrade_depth(in_ll->l_owner->l_parent);
	bach_freeptr(sublist_elem);
	bach_freeptr(sublist);
	pedantic_llll_check(in_ll);
	return;
}



// DESTRUCTIVE!
// matrix transposition of a list (it is the engine of bach.trans)
// mode: iterationmode
t_llll *llll_trans(t_llll *in_ll, long mode)
{
	t_atom_long i;
	t_atom_long inlen = in_ll->l_size;
	long go_on;
	t_llllelem **elem;
	t_llllelem **this_elem;
	t_llllelem *inll_root_elem, *next_elem;
	t_llll *this_out_subll;
	t_llll *out_ll;
	
	if (!in_ll)
		return NULL;
	
	if (inlen == 0)
		return in_ll;

	pedantic_llll_check(in_ll);
	
	out_ll = llll_get();
	elem = (t_llllelem **) bach_newptr(inlen * sizeof(t_llllelem *));
	go_on = !mode;
	
	for (this_elem = elem, inll_root_elem = in_ll->l_head; inll_root_elem; this_elem++, inll_root_elem = inll_root_elem->l_next) {
		if (inll_root_elem->l_hatom.h_type == H_LLLL) {
			*this_elem = inll_root_elem->l_hatom.h_w.w_llll->l_head;
			if (mode == 0)
				go_on = go_on && *this_elem;
			else
				go_on = go_on || *this_elem;
		} else
			go_on = 0;

		if (!go_on)
			break;
	}
	
	if (!go_on) {
		llll_free(in_ll);
		bach_freeptr(elem);
		return out_ll;
	}

	while (go_on) {
		this_out_subll = llll_get();
		go_on = !mode;
		for (i = 0, this_elem = elem; i < inlen; i++, this_elem++) {
			if (*this_elem) {
				next_elem = (*this_elem)->l_next;
				llll_appendhatom(this_out_subll, &((*this_elem)->l_hatom), 0, WHITENULL_llll);
				if (mode == 0)
					go_on = go_on && next_elem;
				else
					go_on = go_on || next_elem;
				(*this_elem)->l_flags = OBJ_FLAG_DATA;
				*this_elem = next_elem;
			} else if (mode == 2)
				llll_appendllll(this_out_subll, llll_get(), 0, WHITENULL_llll);
		}
		llll_appendllll(out_ll, this_out_subll, 0, WHITENULL_llll);
	}
/*	
	for (this_elem = elem, inll_root_elem = in_ll->l_head; inll_root_elem; this_elem++, inll_root_elem = next_root_elem) {
		for ( ; *this_elem; *this_elem = next_elem) {
			next_elem = (*this_elem)->l_next;
			llll_destroyelem(*this_elem);
		}
		next_root_elem = inll_root_elem->l_next;
		inll_root_elem->l_flags = OBJ_FLAG_DATA;
		llll_destroyelem(inll_root_elem);
	}
*/	
	llll_free_nocheck(in_ll);
	bach_freeptr(elem);
	pedantic_llll_check(out_ll);
	return out_ll;
}

long llll_inplace_trans_fn(void *data, t_hatom *a, const t_llll *address){
	long mode = *((long *)data);
	t_llll *ll = hatom_getllll(a);
	if (ll){
		//t_llll *trans = llll_trans(hatom_getllll(a), mode);
		//hatom_change_to_llll(a, trans);
		llll_trans_inplace(ll, mode);
	}
	return 0;
}


void llll_trans_extended(t_llll *in_ll, t_llll *depth, long mode)
{
	t_llllelem *depth_elem;
	
	if (!depth || depth->l_size == 0) {
		llll_trans_inplace(in_ll, mode);
		pedantic_llll_check(in_ll);
		return;
	}

	//out_ll = llll_clone(in_ll);
	for (depth_elem = depth->l_head; depth_elem; depth_elem = depth_elem->l_next) {
		if (hatom_gettype(&depth_elem->l_hatom) == H_LONG) {
			long this_depth = hatom_getlong(&depth_elem->l_hatom) - 1;	// minus one! indeed if we ask for a transposition with depth = 1, 
																		// we need to transpose the root level, and thus we don't want to iterate on anything!
																		// with depth = 2, we'll iterate on first level, and so on.
			if (this_depth == 0)
				llll_trans_inplace(in_ll, mode);
			else
				llll_funall(in_ll, llll_inplace_trans_fn, &mode, this_depth, this_depth, FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH_AND_SKIP_ATOMS);
		}
	}
	pedantic_llll_check(in_ll);
	return;
}
#else


// DESTRUCTIVE!
// translation of a list (it is the engine of bach.trans)
// mode: iterationmode
t_llll *llll_trans(t_llll *in_ll, long mode)
{
	t_atom_long i;
	t_atom_long inlen = in_ll->l_size;
	long go_on;
	t_llllelem **elem;
	t_llllelem **this_elem;
	t_llllelem *inll_root_elem, *next_elem;
	t_llll *this_out_subll;
	t_llll *out_ll;
	
	if (!in_ll)
		return NULL;
	
	if (inlen == 0)
		return in_ll;
	
	out_ll = llll_get();
	elem = (t_llllelem **) bach_newptr(inlen * sizeof(t_llllelem *));
	go_on = !mode;
	
	for (this_elem = elem, inll_root_elem = in_ll->l_head; inll_root_elem; this_elem++, inll_root_elem = inll_root_elem->l_next) {
		if (inll_root_elem->l_hatom.h_type == H_LLLL) {
			*this_elem = inll_root_elem->l_hatom.h_w.w_llll->l_head;
			if (mode == 0)
				go_on = go_on && *this_elem;
			else
				go_on = go_on || *this_elem;
		} else
			go_on = 0;
		
		if (!go_on)
			break;
	}
	
	if (!go_on) {
		llll_free(in_ll);
		bach_freeptr(elem);
		return out_ll;
	}
	
	while (go_on) {
		this_out_subll = llll_get();
		go_on = !mode;
		for (i = 0, this_elem = elem; i < inlen; i++, this_elem++) {
			if (*this_elem) {
				next_elem = (*this_elem)->l_next;
				llll_appendhatom(this_out_subll, &((*this_elem)->l_hatom), 0, WHITENULL_llll);
				if (mode == 0)
					go_on = go_on && next_elem;
				else
					go_on = go_on || next_elem;
				(*this_elem)->l_flags = OBJ_FLAG_DATA;
				*this_elem = next_elem;
			} else if (mode == 2)
				llll_appendllll(this_out_subll, llll_get(), 0, WHITENULL_llll);
		}
		llll_appendllll(out_ll, this_out_subll, 0, WHITENULL_llll);
	}
	/*
	 for (this_elem = elem, inll_root_elem = in_ll->l_head; inll_root_elem; this_elem++, inll_root_elem = next_root_elem) {
	 for ( ; *this_elem; *this_elem = next_elem) {
	 next_elem = (*this_elem)->l_next;
	 llll_destroyelem(*this_elem);
	 }
	 next_root_elem = inll_root_elem->l_next;
	 inll_root_elem->l_flags = OBJ_FLAG_DATA;
	 llll_destroyelem(inll_root_elem);
	 }
	 */
	llll_free_nocheck(in_ll);
	bach_freeptr(elem);
	pedantic_llll_check(out_ll);
	return out_ll;
}

long llll_inplace_trans_fn(void *data, t_hatom *a, const t_llll *address){
	long mode = *((long *)data);
	if (hatom_gettype(a) == H_LLLL){
		t_llll *trans = llll_trans(hatom_getllll(a), mode);
		hatom_change_to_llll(a, trans);
	}
	return 0;
}


t_llll *llll_trans_extended(t_llll *in_ll, t_llll *depth, long mode)
{
	t_llllelem *depth_elem;
	t_llll *out_ll = NULL;
	long mode_ok = mode;
	
	if (!depth || depth->l_size == 0)
		return llll_trans(in_ll, mode);
	
	out_ll = llll_clone(in_ll);
	for (depth_elem = depth->l_head; depth_elem; depth_elem = depth_elem->l_next) {
		if (hatom_gettype(&depth_elem->l_hatom) == H_LONG) {
			long this_depth = hatom_getlong(&depth_elem->l_hatom) - 1;	// minus one! indeed if we ask for a transposition with depth = 1,
			// we need to transpose the root level, and thus we don't want to iterate on anything!
			// with depth = 2, we'll iterate on first level, and so on.
			if (this_depth == 0)
				out_ll = llll_trans(out_ll, mode);
			else
				llll_funall(out_ll, llll_inplace_trans_fn, &mode_ok, this_depth, this_depth, FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH_AND_SKIP_ATOMS);
		}
	}
	pedantic_llll_check(out_ll);
	return out_ll;
}

#endif



void llll_minmax(t_llll *ll, t_hatom **min, t_hatom **max, t_llll *minaddress, t_llll *maxaddress, t_int32 mindepth, t_int32 maxdepth)
{
	t_llllelem *elem;
	t_llll *subll;
	t_int32 mintype = H_NULL;
	t_int32 maxtype = H_NULL;
	t_int32 elem_type;
	t_bool min_changed, max_changed;
	t_rational relem, rm;
	t_llll *address;
	t_llll_stack *stack;
	long deepenough;
	t_int32 depth = 1;
	
	if (!ll || !minaddress || !maxaddress)
		return;
	
	if (mindepth == 0)
		mindepth = 1;
	if (maxdepth == 0)
		maxdepth = -1;
	
	if (mindepth > ll->l_depth || maxdepth < -ll->l_depth)
		return;
	
	deepenough = (mindepth == 1 || ll->l_depth < -mindepth);
	address = llll_get();
	llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
	stack = llll_stack_new();
	elem = ll->l_head;
	
	while (1) {
		while (elem) {
			min_changed = max_changed = 0;
			elem_type = elem->l_hatom.h_type;
			if ((subll = hatom_getllll(&elem->l_hatom)) && 
				subll->l_size && 
				(depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
				llll_stack_push(stack, elem->l_next);
				elem = subll->l_head;
				depth++;
				deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
				llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
			} else {
				if (deepenough && hatom_type_is_number(elem_type)) {
					if (mintype == H_NULL) {
						*min = *max = &elem->l_hatom;
						mintype = maxtype = elem_type;
						llll_clone_upon(address, minaddress);
						llll_clone_upon(address, maxaddress);
					} else {
                        if (llll_lt_hatom(&elem->l_hatom, *min)) {
                            *min = &elem->l_hatom;
                            mintype = elem_type;
                            min_changed = 1;
                            llll_clear(minaddress);
                            llll_clone_upon(address, minaddress);
                        }
						if (!min_changed && llll_gt_hatom(&elem->l_hatom, *max)) {
                            *max = &elem->l_hatom;
                            maxtype = elem_type;
                            llll_clear(maxaddress);
                            llll_clone_upon(address, maxaddress);
                        }
					}
				}
				address->l_tail->l_hatom.h_w.w_long++;
				elem = elem->l_next;
			}
		}
		if (depth <= 1)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
		llll_destroyelem(address->l_tail);
		address->l_tail->l_hatom.h_w.w_long++;
		depth--;
		deepenough = elem && ((mindepth > 0 && depth >= mindepth) || (elem->l_parent->l_depth <= -mindepth));
	}
	pedantic_llll_check(ll);
	llll_free(address);
	llll_stack_destroy(stack);
}

void llll_sum_one(t_hatom *sum, const t_hatom *a, const t_llll *address)
{
	switch (sum->h_type) {
		case H_LONG:
			switch (a->h_type) {
				case H_LONG:
					sum->h_w.w_long += a->h_w.w_long;
					break;
				case H_RAT:
					hatom_setrational(sum, rat_long_sum(a->h_w.w_rat, sum->h_w.w_long));
					break;
				case H_DOUBLE:
					hatom_setdouble(sum, sum->h_w.w_long + a->h_w.w_double);
					break;
                case H_PITCH:
                    sum->h_w.w_long += t_atom_long(a->h_w.w_pitch.toMC());
                    break;
				default:
					break;
			}
			break;
		case H_RAT:
			switch (a->h_type) {
				case H_LONG:
					sum->h_w.w_rat = rat_long_sum(sum->h_w.w_rat, a->h_w.w_long);					
					break;
				case H_RAT:
					sum->h_w.w_rat += a->h_w.w_rat;
					break;
				case H_DOUBLE:
					hatom_setdouble(sum, hatom_getdouble(sum) + a->h_w.w_double);
					break;
                case H_PITCH:
                    sum->h_w.w_rat += a->h_w.w_pitch.toMC();
				default:
					break;
			}
			break;
		case H_DOUBLE:
			switch (a->h_type) {
				case H_LONG:
					sum->h_w.w_double += a->h_w.w_long;
					break;
				case H_RAT:
					sum->h_w.w_double += hatom_getdouble(a);
					break;
				case H_DOUBLE:
					sum->h_w.w_double += a->h_w.w_double;
					break;
                case H_PITCH:
                    sum->h_w.w_double += double(a->h_w.w_pitch.toMC());
				default:
					break;
			}
			break;
        case H_PITCH:
            switch (a->h_type) {
                case H_LONG:
                    hatom_setlong(sum, a->h_w.w_long + t_atom_long(sum->h_w.w_pitch.toMC()));
                    break;
                case H_RAT:
                    hatom_setrational(sum, a->h_w.w_rat + sum->h_w.w_pitch.toMC());
                    break;
                case H_DOUBLE:
                    hatom_setdouble(sum, a->h_w.w_double + double(sum->h_w.w_pitch.toMC()));
                    break;
                case H_PITCH:
                    sum->h_w.w_pitch += a->h_w.w_pitch;
                    break;
            }
		default:
			break;
	}
}

t_max_err llll_sum(t_llll *ll, t_hatom *sum, t_int32 mindepth, t_int32 maxdepth)
{
	if (!ll || !sum)
		return MAX_ERR_GENERIC;
	hatom_setlong(sum, 0);
	llll_funall(ll, (fun_fn) llll_sum_one, sum, mindepth, maxdepth, 0);
	pedantic_llll_check(ll);
	return MAX_ERR_NONE;
}



/*
 ---DESTRUCTIVE---
 */
t_llll *llll_perm(t_llll *ll, t_atom_long maxcount)
{
	t_llll *map, *subout, *outlist, *sortedll = NULL;
	t_llllelem *prev_elem, *this_elem, *last_elem, *k_elem, *l_elem, *map_elem;
	t_atom_long swap;
	t_atom_long k, l, last_k, last_l;
	t_atom_long len;
	t_atom_long count, prev_idx, idx;
	long i, distinct;
	t_hatom **inlist_as_array, **this_inlist_as_array;
	unsigned long long repeated, tot;
	
	//char *foo = NULL;

	//post("-----");
	
	if (!ll)
		return NULL;
	
	outlist = llll_get();
	
	len = ll->l_size;
	if (len <= 1) {
		llll_appendllll(outlist, ll, 0, WHITENULL_llll);
		return outlist;
	}
		
	last_l = len - 1;
	last_k = len - 2;

	map = llll_get();
		
	for (this_elem = ll->l_head, idx = 0; this_elem; this_elem = this_elem->l_next, idx++) {
		this_elem->l_thing.w_long = idx;
	}
	llll_mergesort_with_lthings(ll, &sortedll, llll_leq_elem_matchtype, NULL);
	ll = sortedll;
	
	this_inlist_as_array = inlist_as_array = (t_hatom **) bach_newptr(len * sizeof(t_hatom *));
	prev_elem = ll->l_head;
	prev_idx = prev_elem->l_thing.w_long;
	map_elem = llll_appendlong(map, distinct = 0, 0, WHITENULL_llll);
	map_elem->l_thing.w_long = prev_elem->l_thing.w_long;
	*(this_inlist_as_array++) = &prev_elem->l_hatom;	

	i = tot = repeated = 1;
	
	for (this_elem = prev_elem->l_next; this_elem; this_elem = this_elem->l_next) {
		if (llll_eq_elem_matchtype(prev_elem, this_elem)) {
			map_elem = llll_appendlong(map, distinct, 0, WHITENULL_llll);
			++repeated;
		} else {
			*(this_inlist_as_array++) = &this_elem->l_hatom;
			map_elem = llll_appendlong(map, ++distinct, 0, WHITENULL_llll);
			repeated = 1;
		}
		map_elem->l_thing.w_long = this_elem->l_thing.w_long;
		this_elem->l_thing.w_whole = 0;
		prev_elem = this_elem;
		tot = tot * ++i / repeated;
	}
	++distinct;
	
	llll_mergesort_with_lthings(map, &sortedll, llll_cmp_elems_by_lthings, NULL);
	map = sortedll;
	
	
	//for (i = 0; i < distinct; i++)
	//	post("ilaa[%ld] = %s", i, hatom_getsym(inlist_as_array[i])->s_name);
	
	if (maxcount < 1 || maxcount > tot)
		maxcount = tot;
	
	if (maxcount == tot) {
		subout = llll_get();

		for (this_elem = map->l_head; this_elem; this_elem = this_elem->l_next) {
			llll_appendhatom_clone(subout, inlist_as_array[this_elem->l_hatom.h_w.w_long], 0, WHITENULL_llll);
		}
		
		llll_appendllll(outlist, subout, 0, WHITENULL_llll);
		maxcount --;
	}
	
	
	//llll_to_text_buf(map, &foo, 0, 0, 0, 0);
	//post(foo);
	
	for (count = 0; count < maxcount; count++) {
		last_elem = map->l_tail;
		this_elem = last_elem->l_prev;
		prev_elem = last_elem;
		k = last_k;
		while (this_elem) {
			if (this_elem->l_hatom.h_w.w_long < prev_elem->l_hatom.h_w.w_long)
				break;
			k--;
			prev_elem = this_elem;
			this_elem = this_elem->l_prev;
		}
		if (!this_elem) {
			llll_rev(map, 1, 1);
			//t_llll *map_sorted = NULL;
			//llll_mergesort(map, &map_sorted, llll_leq_elem_matchtype, NULL);
			//map = map_sorted;
			//post("sort");
			last_elem = map->l_tail;
			this_elem = last_elem->l_prev;
			prev_elem = last_elem;
			k = last_k;
		} else { 
			k_elem = this_elem;
			this_elem = last_elem;
			l = last_l;
			while (this_elem) {
				if (k_elem->l_hatom.h_w.w_long < this_elem->l_hatom.h_w.w_long)
					break;
				l--;
				this_elem = this_elem->l_prev;
			}
			l_elem = this_elem;
			
			swap = k_elem->l_hatom.h_w.w_long;
			k_elem->l_hatom.h_w.w_long = l_elem->l_hatom.h_w.w_long;
			l_elem->l_hatom.h_w.w_long = swap;

			for (k++, l = len-1, k_elem = k_elem->l_next, l_elem = last_elem; 
				 k < l; 
				 k++, l--, k_elem = k_elem->l_next, l_elem = l_elem->l_prev) {
				swap = k_elem->l_hatom.h_w.w_long;
				k_elem->l_hatom.h_w.w_long = l_elem->l_hatom.h_w.w_long;
				l_elem->l_hatom.h_w.w_long = swap;
			}
		}
		//llll_to_text_buf(map, &foo, 0, 0, 0, 0);
		//post(foo);

		
		subout = llll_get();
		
		for (this_elem = map->l_head; this_elem; this_elem = this_elem->l_next) {
			llll_appendhatom_clone(subout, inlist_as_array[this_elem->l_hatom.h_w.w_long], 0, WHITENULL_llll);
		}

		llll_appendllll(outlist, subout, 0, WHITENULL_llll);

	}
	bach_freeptr(inlist_as_array);
	llll_free(ll);
	llll_free(map);
	pedantic_llll_check(outlist);
	return outlist;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE!
// based on the algorithm described in http://en.wikipedia.org/wiki/Permutation#Software_implementations

t_llll *llll_oneperm(t_llll *inlist, long order, long circular)
{
	t_llllelem *prev_elem, *this_elem, *last_elem, *k_elem, *l_elem;
	t_llll *temp_llll;
	t_hatom swap;
	t_atom_long len, k, l;
	
	if (!inlist)
		return NULL;
	len = inlist->l_size;
	
	
	if (len <= 1) {
		if (!circular)
			llll_clear(inlist);
		return inlist;
	}	
	
	last_elem = inlist->l_tail;
	this_elem = last_elem->l_prev;
	prev_elem = last_elem;
	k = len - 2;
	
	while (this_elem) {
		if (order == 0 ? !llll_geq_elem(NULL, this_elem, prev_elem) : !llll_leq_elem(NULL, this_elem, prev_elem))
			break;
		k--;
		prev_elem = this_elem;
		this_elem = this_elem->l_prev;
	}
	if (this_elem) {
		k_elem = this_elem;
		
		this_elem = last_elem;
		l = len - 1;
		while (this_elem) {
			if (order == 0 ? !llll_geq_elem(NULL, k_elem, this_elem) : !llll_leq_elem(NULL, k_elem, this_elem))
				break;
			l--;
			this_elem = this_elem->l_prev;
		}
		l_elem = this_elem;
		
		swap = k_elem->l_hatom;
		k_elem->l_hatom = l_elem->l_hatom;
		l_elem->l_hatom = swap;
		
		for (k++, l = len-1, k_elem = k_elem->l_next, l_elem = last_elem; k < l; k++, l--, k_elem = k_elem->l_next, l_elem = l_elem->l_prev) {
			swap = k_elem->l_hatom;
			k_elem->l_hatom = l_elem->l_hatom;
			l_elem->l_hatom = swap;
		}
		
	} else {
		if (circular) {
			llll_mergesort(inlist, &temp_llll, (sort_fn) (order == 0 ? llll_leq_elem : llll_geq_elem), NULL);
			inlist = temp_llll;
		} else
			llll_clear(inlist);
	}
	
	pedantic_llll_check(inlist);
	return inlist;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// return all the combinations of the elements in ll of size between startk and endk
// endk < 0 is converted in ll->size (this means that startk = 0, endk = -1 will return all the combinations)
// the combinations are grouped in sublists according to their size, e.g.
// ((1) (2) (3)) ((1 2) (2 3) (1 3)) ((1 2 3))

t_llll *llll_comb(t_llll *ll, t_atom_long startk, t_atom_long endk)
{
	t_llll *klist, *comblist;
	t_llll *outlist;
	t_atom_long inc, k, i;
	t_atom_long ll_size;
	t_atom_long *indices;
	t_atom_long dontreachthisk;
	t_hatom **hatoms, **this_hatoms;
	t_llllelem *el;
	
	if (!ll)
		return NULL;
	outlist = llll_get();
	
	ll_size = ll->l_size;
	if (ll_size == 0)
		return outlist;
	
	indices = (t_atom_long *) bach_newptr(ll_size * sizeof(t_atom_long));
	hatoms = (t_hatom **) bach_newptr(ll_size * sizeof(t_hatom *));
	
	startk = CLAMP(startk, 0, ll->l_size);
	if (endk < 0)
		endk = ll->l_size;
	else
		endk = MIN(endk, ll->l_size);
	
	inc = startk > endk ? -1 : 1;
	
	for (el = ll->l_head, this_hatoms = hatoms; el; el = el->l_next, this_hatoms++)
		*this_hatoms = &el->l_hatom;
	
	dontreachthisk = endk + inc;
		
	for (k = startk; k != dontreachthisk; k += inc) {
		klist = llll_get();
		llll_appendllll(outlist, klist, 0, WHITENULL_llll);
		
		if (k == 0) {
			llll_appendllll(klist, llll_get(), 0, WHITENULL_llll);
			continue;
		}
		
		for (i = 0; i < k; i++)
			indices[i] = i;
		
		while (1) {
			t_atom_long maxofthemin;
			
			comblist = llll_get();
			llll_appendllll(klist, comblist, 0, WHITENULL_llll);
			
			for (i = 0; i < k; i++)
				llll_appendhatom_clone(comblist, hatoms[indices[i]], 0, WHITENULL_llll);
			i = k - 1;
			maxofthemin = ll_size - k;
			
			indices[i] ++;
			while (i > 0 && indices[i] > maxofthemin + i) {
				i--;
				indices[i]++;
			}
			
			if (indices[0] > maxofthemin)
				break;
			
			/* comb now looks like (..., x, n, n, n, ..., n).
			 Turn it into (..., x, x + 1, x + 2, ...) */
			for (i++; i < k; i++)
				indices[i] = indices[i - 1] + 1;
			
		}
	}
	
	bach_freeptr(hatoms);
	bach_freeptr(indices);
	pedantic_llll_check(outlist);
	
	return outlist;
}

// --- NON-DESTRUCTIVE
t_llll *llll_cartesianprod(t_llll **inll, long count)
{
	long i;
	t_llll *outll = llll_get();
	t_llllelem **elempile = (t_llllelem **) bach_newptr(count * sizeof(t_llllelem *));
	t_llllelem **this_elempile;
	t_llll **this_inll;
	t_llll *subll = llll_get();
	t_llllelem *subll_elem;
	t_llllelem **top_elempile = elempile + count - 1;
	long current;
	//post("yeyeye");
	for (i = 0, this_elempile = elempile, this_inll = inll; 
		 i < count; 
		 i++, this_elempile++, this_inll++) {
		*this_elempile = (*this_inll)->l_head;
		if (!*this_elempile) {
			goto llll_cartesianprod_exit;
		}
		llll_appendhatom_clone(subll, &(*this_elempile)->l_hatom, 0, WHITENULL_llll);
		llll_check(subll);
	}
	subll_elem = subll->l_tail;
	this_elempile = top_elempile;
	current = count - 1;
	while (1) {
		llll_appendllll_clone(outll, subll, 0, WHITENULL_llll, NULL);
		//llll_check(outll);

		*this_elempile = (*this_elempile)->l_next;
		if (*this_elempile) {
			hatom_change_to_hatom_clone_and_free(&subll_elem->l_hatom, &(*this_elempile)->l_hatom);
			llll_check(subll);
		} else {
			do {
				this_elempile--;
				current--;
				if (current < 0)
					break;
				subll_elem = subll_elem->l_prev;
				*this_elempile = (*this_elempile)->l_next;
				if (*this_elempile)
					hatom_change_to_hatom_clone_and_free(&subll_elem->l_hatom, &(*this_elempile)->l_hatom);
				llll_check(subll);
			} while (!*this_elempile);
			if (this_elempile < elempile)
				break;
			while (this_elempile < top_elempile) {
				this_elempile++;
				current++;
				subll_elem = subll_elem->l_next;
				*this_elempile = inll[current]->l_head;
				hatom_change_to_hatom_clone_and_free(&subll_elem->l_hatom, &(*this_elempile)->l_hatom);
				llll_check(subll);
			}
		}
	}
llll_cartesianprod_exit:
	bach_freeptr(elempile);
	llll_free(subll);
	pedantic_llll_check(outll);
	return outll;
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////

t_llll *llll_find(t_llll *ll, t_llll *addresses, t_atom_long what_size, t_atom_long min_lvl, t_atom_long max_lvl, t_atom_long min_idx, t_atom_long max_idx, 
				  long idx_reject, long depth_reject, t_atom_long max_count, long recursive, long unwrap, long depthpolicy, long matchdepth, find_fn cmpfn, void *data)
{
	t_atom_long i, j, depth, subll_depth;
	t_llll *where = ll;
	t_atom_long where_size;
	t_llll_stack *stack;
	t_llllelem *where_elem, *this_where_elem;
	t_llll *outlist;
	t_llll *templist;
	t_llll *address;
	t_llll *subll = NULL;
	t_atom_long pos_max_idx, pos_min_idx;
	long found = 0, justfound;
	t_atom_long safezone;

//	min_lvl = min_lvl >= 0 ? min_lvl - 1 : min_lvl + ll->l_depth;
//	max_lvl = max_lvl > 0 ? max_lvl - 1 : max_lvl + ll->l_depth;
	
	if (!where || what_size < 1)
		return NULL;
	safezone = what_size - 1;
	
	if (min_lvl == 0)
		min_lvl = 1;
	if (max_lvl == 0)
		max_lvl = -1;

#if LLLL_IDX_BASE
	if (min_idx == 0)
		min_idx = 1;
	if (max_idx == 0)
		max_idx = -1;
#endif
	
// from now on, all indices are 0-based
	
	pos_min_idx = min_idx > 0 ? min_idx : min_idx + ll->l_size + LLLL_IDX_BASE;
	pos_max_idx = max_idx > 0 ? max_idx : max_idx + ll->l_size + LLLL_IDX_BASE;
	pos_max_idx -= safezone;
	if (pos_max_idx < 0)
		pos_max_idx = 0;
	
	outlist = llll_get();
	address = llll_get();
	stack = llll_stack_new();

	where_elem = where->l_head;
	where_size = where->l_size;
	llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
	i = 1;
	depth = 1;
	subll_depth = ll->l_depth;

	while (1) {
		while (where_elem) {
			templist = llll_get();
			for (j = 0, this_where_elem = where_elem; this_where_elem && j < what_size; j++, this_where_elem = this_where_elem->l_next)
				llll_appendhatom_clone(templist, &this_where_elem->l_hatom, 0, WHITENULL_llll);
			
			if (unwrap)
				llll_flatten(templist, 1, 0);
			
			justfound = 0;
			if (((i >= pos_min_idx && i <= pos_max_idx) ^ idx_reject) && 
				
				((((min_lvl > 0 && depth >= min_lvl) || subll_depth <= -min_lvl) &&
				  (depth <= max_lvl || (max_lvl < 0 && subll_depth >= -max_lvl))) ^ depth_reject) &&
				
				(depthpolicy == 0 || templist->l_depth <= matchdepth) &&
				
				(*cmpfn)(data, templist)) { // if it's a solution
				llll_appendllll(outlist, llll_clone(templist), 0, WHITENULL_llll);
				if (addresses) {
					llll_appendllll(addresses, llll_clone(address), 0, WHITENULL_llll);
				}
				if (++found == max_count) {	// have we found enough?
					llll_free(templist);
					goto finished;
				}
				justfound = 1;
			}
			llll_free(templist);
			if (where_elem->l_hatom.h_type == H_LLLL && (subll = where_elem->l_hatom.h_w.w_llll)->l_size && (!justfound || recursive)) {
				llll_stack_push(stack, where_elem->l_next);
				where_elem = subll->l_head;
				i = 1;
				depth++;
				subll_depth = subll->l_depth;
				llll_appendlong(address, LLLL_IDX_BASE, 0, WHITENULL_llll);
				if (min_idx < 0)
					pos_min_idx = min_idx + subll->l_size + LLLL_IDX_BASE;
				pos_max_idx = max_idx > 0 ? max_idx : max_idx + subll->l_size + LLLL_IDX_BASE;
				pos_max_idx -= safezone;
				if (pos_max_idx < 0)
					pos_max_idx = 0;
			} else {
				address->l_tail->l_hatom.h_w.w_long++;
				where_elem = where_elem->l_next;
				i++;
			}

		}
		if (depth <= 1)
			break;
		where_elem = (t_llllelem *) llll_stack_pop(stack);
		if (where_elem) {
			subll = where_elem->l_parent;
			if (min_idx < 0)
				pos_min_idx = min_idx + subll->l_size + LLLL_IDX_BASE;
			pos_max_idx = max_idx > 0 ? max_idx : max_idx + subll->l_size + LLLL_IDX_BASE;
			pos_max_idx -= safezone;
			if (pos_max_idx < 0)
				pos_max_idx = 0;
		}
		llll_destroyelem(address->l_tail);
		i = ++(address->l_tail->l_hatom.h_w.w_long);
		depth--;
		subll_depth = subll->l_depth;
	}

finished:
	llll_free(address);
	llll_stack_destroy(stack);
	pedantic_llll_check(outlist);
	return outlist;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE--- (inplace)
// for each element, look for equal elements (according to fn) and delete them
// O(n^2) - a more efficient algorithm for specific cases (where a <= operation is also defined) might be implemented
// this would require sorting the llll, then only comparing neighbour elements, and finally restore the original order
// the complexity in this case would be O(nlogn), that is the complexity of mergesort.
// on the other hand, this would require lots of memory allocations and other stuff like that
// and for this reason it would become more efficient than this only for very long lists
// the edited llll is also the return value for compatibility with llll_thin_simple
t_llll *llll_thin(t_llll *ll, sort_fn fn, void *data)
{
	t_llllelem *elem, *cmp_elem, *next_cmp_elem;
	t_int32 maxdepth = 1, subdepth;
	if (!ll || ll->l_size < 2)
		return ll;
	
	for (elem = ll->l_head; elem && elem->l_next; elem = elem->l_next) {
		if (elem->l_hatom.h_type == H_LLLL && (subdepth = elem->l_hatom.h_w.w_llll->l_depth) >= maxdepth)
			maxdepth = subdepth + 1;
		for (cmp_elem = elem->l_next; cmp_elem; cmp_elem = next_cmp_elem) {
			next_cmp_elem = cmp_elem->l_next;
			if ((fn)(data, elem, cmp_elem)) {
				if (next_cmp_elem) {
					cmp_elem->l_prev->l_next = next_cmp_elem;
					next_cmp_elem->l_prev = cmp_elem->l_prev;
				} else {
					cmp_elem->l_prev->l_next = NULL;
					ll->l_tail = cmp_elem->l_prev;
				}
				ll->l_size--;
				llll_free(cmp_elem->l_thing.w_llll);
				llllelem_free(cmp_elem); // was: nocheck
			}
		}
	}
	ll->l_depth = maxdepth;
	pedantic_llll_check(ll);
	return ll;
}

// --- DESTRUCTIVE ---
// The simpler O(nlogn) version
t_llll *llll_thin_simple(t_llll *ll, long matchtype)
{
	t_llll *out;
	t_llllelem *elem, *nextelem;
	long idx = 0;
	if (!ll || ll->l_size < 2)
		return ll;
	for (elem = ll->l_head; elem; elem = elem->l_next)
		elem->l_thing.w_long = idx++;
	llll_mergesort_with_lthings(ll, &out, matchtype ? llll_leq_elem_matchtype : llll_leq_elem, NULL);
	ll = out;
	if (!matchtype) {
		for (elem = ll->l_head; elem && elem->l_next; elem = elem->l_next) {
			t_llllelem *nextnext;
			t_hatom *h = &elem->l_hatom;
			for (nextelem = elem->l_next; nextelem && llll_eq_hatom_ignoretype(h, &nextelem->l_hatom); nextelem = nextnext) {
				nextnext = nextelem->l_next;
				llll_destroyelem(nextelem);
			}
		}
	} else {
		for (elem = ll->l_head; elem && elem->l_next; elem = elem->l_next) {
			t_llllelem *nextnext;
			t_hatom *h = &elem->l_hatom;
			for (nextelem = elem->l_next; nextelem && llll_eq_hatom_matchtype(h, &nextelem->l_hatom); nextelem = nextnext) {
				nextnext = nextelem->l_next;
				llll_destroyelem(nextelem);
			}
		}
	}
	llll_mergesort_with_lthings(ll, &out, llll_cmp_elems_by_lthings, NULL);
	for (elem = out->l_head; elem; elem = elem->l_next)
		elem->l_thing.w_whole = 0;
	pedantic_llll_check(out);
	return out;
}



long llll_cmp_elems_by_lthings(void *dummy, t_llllelem *a, t_llllelem *b)
{
	return a->l_thing.w_long <= b->l_thing.w_long;
}


//////////////// CLASSIFICATION STUFF /////////////////////////


long llll_cmp_lllls_by_min_elem_lthings(void *dummy, t_llllelem *a, t_llllelem *b)
{
    if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
        // find minimum lthing in elements from a and from b
        t_llll *a_ll = hatom_getllll(&a->l_hatom);
        t_llll *b_ll = hatom_getllll(&b->l_hatom);
        long min_a = -1, min_b = -1;
        t_llllelem *temp;
        for (temp = a_ll->l_head; temp; temp = temp->l_next) {
            if (min_a < 0 || temp->l_thing.w_whole < min_a)
                min_a = temp->l_thing.w_whole;
        }
        for (temp = b_ll->l_head; temp; temp = temp->l_next) {
            if (min_b < 0 || temp->l_thing.w_whole < min_b)
                min_b = temp->l_thing.w_whole;
        }
        return min_a <= min_b;
    }
    return 0; // should never happen
}






///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE--- (inplace)
// for each element, look for equal elements (according to fn) and group them
// BEWARE: fn is not a sorting function, but a *comparison* function.
// There is no sorting involved here, just classification
t_llll *llll_classify(t_llll *ll, sort_fn fn, void *data)
{
    t_llllelem *elem, *cmp_elem, *next_cmp_elem;
    if (!ll || ll->l_size == 0)
        return ll;
    
    t_llllelem *cur = NULL, *pivot = NULL;
    long flags = ll->l_flags;
    ll->l_flags |= OBJ_FLAG_DATA;
    for (elem = ll->l_head; elem; elem = cur) {
        cur = elem->l_next;
        pivot = elem;
        
        // finding all equal elements
        for (cmp_elem = elem->l_next; cmp_elem; cmp_elem = next_cmp_elem) {
            next_cmp_elem = cmp_elem->l_next;
            if ((fn)(data, elem, cmp_elem)) { // equals
                
                // These four lines are used to move cmp_elem AFTER the pivot.
                // WHenever a llllelem_move_after() api function will be available,
                // one should substitute this four lines with
                // llllelem_move_after(cmp_elem, pivot), and then just set
                // pivot = cmp_elem; cur = cmp_elem->l_next;
                t_llllelem *new_cmp_elem = llllelem_get();
                new_cmp_elem->l_hatom = cmp_elem->l_hatom;
                llll_destroyelem(cmp_elem); // lllls won't be destroyed, we've set FLAG_DATA
                llll_insert_after(new_cmp_elem, pivot);

                pivot = new_cmp_elem;
                cur = new_cmp_elem->l_next;
            }
        }
        
        // wrapping up
        llll_wrap_element_range(elem, cur ? cur->l_prev : ll->l_tail);
    }
    ll->l_flags = flags;
    pedantic_llll_check(ll);
    return ll;
}



// --- DESTRUCTIVE ---
// The simpler O(nlogn) version
t_llll *llll_classify_simple(t_llll *ll, long matchtype)
{
    t_llll *out;
    t_llllelem *elem;
    long idx = 0;
    if (!ll || ll->l_size == 0)
        return ll;
    for (elem = ll->l_head; elem; elem = elem->l_next)
        elem->l_thing.w_long = idx++;
    llll_mergesort_with_lthings(ll, &out, matchtype ? llll_leq_elem_matchtype : llll_leq_elem, NULL);
    ll = out;
    
    if (!matchtype) {
        t_llllelem *pivot = ll->l_head; // can't be NULL
        for (elem = pivot->l_next; pivot && elem; elem = elem->l_next) {
            if (!llll_eq_hatom_ignoretype(&pivot->l_hatom, &elem->l_hatom)) {
                t_llllelem *temp = elem;
                llll_wrap_element_range(pivot, elem->l_prev);
                pivot = elem = temp;
                if (!elem) break;
            }
        }
        llll_wrap_element_range(pivot, ll->l_tail);
    } else {
        t_llllelem *pivot = ll->l_head; // can't be NULL
        for (elem = pivot->l_next; pivot && elem; elem = elem->l_next) {
            if (!llll_eq_hatom_matchtype(&pivot->l_hatom, &elem->l_hatom)) {
                t_llllelem *temp = elem;
                llll_wrap_element_range(pivot, elem->l_prev);
                pivot = elem = temp;
                if (!elem) break;
            }
        }
        llll_wrap_element_range(pivot, ll->l_tail);
    }
    llll_mergesort_with_lthings(ll, &out, llll_cmp_lllls_by_min_elem_lthings, NULL);
     
    for (elem = out->l_head; elem; elem = elem->l_next)
        elem->l_thing.w_whole = 0;
    pedantic_llll_check(out);
    return out;
}





///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE--- on ll
// inserts inside a ll (subs_model) in another (ll) at a given address (address)
// if the address is multiple, many copies of subs_model will be inserted
void llll_insert_llll_at_address(t_llll *ll, t_llll *address, t_llll *subs_model)
{
	t_llll *baby_llll, *directions; 
	t_llll *this_subs, *trough = NULL;
	t_llll *edited = NULL;
	t_llllelem *elem, *baby, *dir_elem;
	long dir;
	t_atom_long maxsubdepth;

	baby_llll = llll_get();
	directions = llll_get();
	llll_findchildren(ll, address, 1, baby_llll, directions);
	
	if (subs_model && subs_model->l_size) {
		for (elem = baby_llll->l_head, dir_elem = directions->l_head; elem; elem = elem->l_next, dir_elem = dir_elem->l_next) {
			if ((baby = (t_llllelem *) elem->l_hatom.h_w.w_obj)) {
				dir = dir_elem->l_hatom.h_w.w_long;
				edited = baby->l_parent; // the (sub)list the surgery will be performed on	
				this_subs = llll_clone_extended(subs_model, edited, 0, NULL);
				
				switch (dir) {
					case 0:
						if (baby->l_prev)
							baby->l_prev->l_next = this_subs->l_head;
						else
							edited->l_head = this_subs->l_head;
						if ((this_subs->l_head->l_prev = baby->l_prev) == NULL)
							edited->l_head = this_subs->l_head;
						
						if (baby->l_next)
							baby->l_next->l_prev = this_subs->l_tail;
						else
							edited->l_tail = this_subs->l_tail;
						if ((this_subs->l_tail->l_next = baby->l_next) == NULL)
							edited->l_tail = this_subs->l_tail;
						
						edited->l_size += this_subs->l_size - 1;
						llllelem_free(baby); // was: nocheck
						break;
						
					case 1: // we come from a positive direction, so we have to prepend
						if (baby->l_prev)
							baby->l_prev->l_next = this_subs->l_head;
						else
							edited->l_head = this_subs->l_head;
						this_subs->l_head->l_prev = baby->l_prev;
						baby->l_prev = this_subs->l_tail;
						this_subs->l_tail->l_next = baby;
						edited->l_size += this_subs->l_size;
						break;
						
					case -1: // we come from a negative direction, so we have to append
						if (baby->l_next)
							baby->l_next->l_prev = this_subs->l_tail;
						else
							edited->l_tail = this_subs->l_tail;
						this_subs->l_tail->l_next = baby->l_next;
						baby->l_next = this_subs->l_head;
						this_subs->l_head->l_prev = baby;
						edited->l_size += this_subs->l_size;
						break;
				}
				//llll_fix_owner_for_check(this_subs);
				llll_chuck_nocheck(this_subs);
			}
		}
		if (edited) {
			maxsubdepth = 0;
			for (elem = subs_model->l_head; elem; elem = elem->l_next) {
				if (elem->l_hatom.h_type == H_LLLL && elem->l_hatom.h_w.w_llll->l_depth > maxsubdepth) {
					maxsubdepth = elem->l_hatom.h_w.w_llll->l_depth;
					trough = elem->l_hatom.h_w.w_llll;
				}
			}
			if (maxsubdepth >= edited->l_depth)
				llll_upgrade_depth(trough);
			else if (maxsubdepth + 1 < edited->l_depth) 
				llll_downgrade_depth(edited);
			
		}
	}
	llll_free(baby_llll);
	llll_free(directions);
	pedantic_llll_check(ll);
}



///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE---

/*
 the idea is that, as soon as we detect a LLLL-type elem compliant with mindepth and maxdepth,
 we chain its prev with the sub-llll head and its next with the sub-llll tail.
 then, if we haven't reached maxdepth yet, we look inside the newly found sublist for other lllls
 otherwise, we go directly to elem->l_next
 this allows the list to be flattened in sub-linear time
*/

void llll_flatten(t_llll *ll, t_int32 maxdepth, long spikemode)
{
	llll_flat(ll, 0, maxdepth, spikemode, LLLL_FREETHING_DONT);
	pedantic_llll_check(ll);
}

void llll_flat(t_llll *ll, t_int32 minlevel, t_int32 maxlevel, long spikemode, e_freething_modes freething)
{
	t_llllelem *this_elem = NULL, *next_elem = NULL;
	t_llllelem *nextelem_to_reach = NULL;
	t_atom_long this_lvl = 1;
	long direction = 0;
	t_int32 depth = 1;
	t_llll_stack *elem_to_reach_stack;
	t_llll_stack *base_stack;
	t_llllelem *new_elem;
	
	if (!ll || ll->l_depth == 1)
		return;
	
	if (maxlevel == 0)
		maxlevel = -1;
	if (minlevel == 0)
		minlevel = 1;
	if (maxlevel < -ll->l_depth ||
        minlevel >= ll->l_depth ||
        (minlevel * maxlevel > 0 && minlevel > maxlevel) ||
        (minlevel > 0 && maxlevel < 0 && minlevel > ll->l_depth + maxlevel) ||
        (minlevel < 0 && maxlevel > 0 && ll->l_depth + minlevel > maxlevel))
		return;

    if (maxlevel >= ll->l_depth) {
        maxlevel = ll->l_depth - 1;
    }
    if (minlevel <= -ll->l_depth) {
        minlevel = -ll->l_depth + 1;
    }
    
	if (minlevel > 0) {
        if (maxlevel > 0) {
			ll->l_depth = ll->l_depth - maxlevel + minlevel - 1;
        } else {
			ll->l_depth = minlevel - maxlevel - 1;
        }
	} else {
        if (maxlevel > 0) {
			ll->l_depth = 2 * ll->l_depth - maxlevel + minlevel - 1;
        } else {
			ll->l_depth = ll->l_depth - maxlevel + minlevel - 1;
        }
	}

	
	elem_to_reach_stack = llll_stack_new();
	base_stack = llll_stack_new();
    
    llll_stack_push(elem_to_reach_stack, NULL);

	this_elem = ll->l_head;

	while (1) {
		while (this_elem) {
            t_llll *subll = hatom_getllll(&this_elem->l_hatom);
            t_atom_long subdepth = subll ? subll->l_depth : 0;
            if (subdepth + depth <= minlevel || (maxlevel > 0 && depth > maxlevel) || subdepth < -maxlevel)
                subll = NULL;
            
            if (subll &&
                (maxlevel < -subdepth || // maxlevel < 0, and therefore independent from depth
                 minlevel - depth >= subdepth || // minlevel > 0
                 (minlevel > 0 && maxlevel < 0 && minlevel - depth > subdepth + maxlevel) ||
                 (minlevel < 0 && maxlevel > 0 && subdepth + minlevel > maxlevel - depth))) {
                subll = NULL;
            }
            
            
			if (subll) { // if we meet a sublist that has enough depth to be flattened (i.e., for its contents to be moved to its parent list)

				if ((minlevel > 0 && depth >= minlevel) || subdepth <= -minlevel) {  // if we are deep enough, and so have to flatten the sublist
					if (direction == -1 && spikemode) {		// this concerns spikemode (with spikemode, every flattened )( is replaced by a ()
						new_elem = llllelem_get();
						hatom_setllll(&new_elem->l_hatom, llll_get());
						new_elem->l_hatom.h_type = H_NULL;
						new_elem->l_prev = this_elem->l_prev;
						this_elem->l_prev->l_next = new_elem;
						this_elem->l_prev = new_elem;
						new_elem->l_next = this_elem;
						new_elem->l_parent = ll;
						ll->l_size ++;
						if (ll->l_depth == 1)
							ll->l_depth = 2;
						llll_upgrade_depth(ll);
					} 
					
					if (subll->l_thing.w_obj) {
						switch (freething) {
							case LLLL_FREETHING_OBJ:
								object_free_debug(subll->l_thing.w_obj);
								subll->l_thing.w_obj = NULL;
								break;
							case LLLL_FREETHING_MEM:
								bach_freeptr(subll->l_thing.w_obj);
								subll->l_thing.w_obj = NULL;
								break;
							case LLLL_FREETHING_LLLL:
								llll_free((t_llll *) subll->l_thing.w_obj);
								subll->l_thing.w_obj = NULL;
								break;
							case LLLL_FREETHING_LLLLELEM:
								llllelem_free((t_llllelem *) subll->l_thing.w_obj);
								subll->l_thing.w_obj = NULL;
								break;				
							default:
								break;
						}
					}

					if (subll->l_size) {	// if it's not an empty list

                        if (subll->l_depth > 1 && (this_lvl < maxlevel || (maxlevel < 0 && subll->l_depth >= -maxlevel))) {	// if we flatten this sublist, which means that we will flatten its 1-st level sublists
                            nextelem_to_reach = this_elem->l_next;		// this is what next_elem will be when we reach the end of subll
                            llll_stack_push(elem_to_reach_stack, nextelem_to_reach);	// we keep track of it
                            next_elem = subll->l_head;					// the next element in the mother list becomes the head of the sublist
                            this_lvl ++;								// we rise one level
                        } else {							// if we don't flatten this sublist
							next_elem = this_elem->l_next;				// we simply go to the next elem
                            //ll->l_depth = subll->l_depth;
                        }
                        
                        ll->l_size += subll->l_size - 1; // it's always the mother list who receives the elements
                        llll_adopt(subll, ll);	// the sublist is adopted by the mother list
                        
						subll->l_head->l_prev = this_elem->l_prev;	// some pointer sewing: the sublist becomes a part of the mother list
						if (this_elem->l_prev)
							this_elem->l_prev->l_next = subll->l_head;
						else
							ll->l_head = subll->l_head;
						subll->l_tail->l_next = this_elem->l_next;
						if (this_elem->l_next)
							this_elem->l_next->l_prev = subll->l_tail;
						else
							ll->l_tail = subll->l_tail;
 
						this_elem->l_flags = OBJ_FLAG_DATA;		// and then we chuck the sublist, and destroy the element who contains it
						llllelem_free(this_elem);
						llll_chuck_nocheck(subll); // because parenthoods of the elements are broken
						direction = 1;
					} else {	// if it's an empty list
						next_elem = this_elem->l_next;	// go to the next elem
						if (!spikemode) {
							llll_destroyelem_no_depth_check(this_elem); // depth is already ok and we might risk to mess up things!
							direction = 0; // this is just for cleanness (tomorrow never knows), because direction is used only with spikemode on
						} else { // if we are in spikemode, the list itself will stay! but we don't want its l_thing.w_obj anymore...
							direction = -1;
							subll->l_thing.w_obj = NULL;
						}
					}
                    
				} else { // if we are not deep enough, and so we have to go deeper
                    long local_minlevel, local_maxlevel;
                    
                    llll_stack_push(base_stack, this_elem->l_next);
					next_elem = subll->l_head;
					ll = subll;
                    
                    /*
                    if (maxlevel >= ll->l_depth) {
                        local_maxlevel = ll->l_depth - 1;
                    } else {
                        local_maxlevel = maxlevel;
                    }
                    
                    if (minlevel <= -ll->l_depth) {
                        local_minlevel = -ll->l_depth + 1;
                    } else {
                        local_minlevel = minlevel;
                    }
                     */
                    
                    // If we get here, it means that this sublist is not too shallow (wrt minlevel) to be flattened,
                    // but it might be shallower than what maxdepth indicates, if there are deeper branches of its parent list.
                    // We must therefore calculate our local max- and minlevel, so as to take all this into account
                    
                    
                    if (minlevel > 0) {
                        local_minlevel = minlevel - depth;
                        if (local_minlevel < 1)
                            local_minlevel = 1;
                    } else {
                        local_minlevel = minlevel;
                        // if minlevel < 0 and it includes this sublist,
                        // then we can't be here!
                        //if (local_minlevel <= -ll->l_depth)
                        //    local_minlevel = 1;
                    }
                    
                    if (maxlevel > 0) {
                        local_maxlevel = maxlevel - depth;
                        if (local_maxlevel >= ll->l_depth)
                            local_maxlevel = -1;
                    } else {
                        local_maxlevel = maxlevel;
                        // if maxlevel < 0 and it doesn't include this sublist
                        // then we can't be here!
                    }
                    
                    if (local_minlevel > 0) {
                        if (local_maxlevel > 0) {
                            ll->l_depth = ll->l_depth - local_maxlevel + local_minlevel - 1;
                        } else {
                            ll->l_depth = local_minlevel - local_maxlevel - 1;
                        }
                    } else {
                        if (local_maxlevel > 0) {
                            ll->l_depth = 2 * ll->l_depth - local_maxlevel + local_minlevel - 1;
                        } else {
                            ll->l_depth = ll->l_depth - local_maxlevel + local_minlevel - 1;
                        }
                    }
                    
					depth++;
					this_lvl++;
				}
			} else {		// if it's not a list, or it's too deep
				next_elem = this_elem->l_next; // go to the next elem
				direction = 0;	// and level doesn't change
			}
			
			if (next_elem == nextelem_to_reach && this_lvl > depth) { // which would mean that we have reached the end of the current sublist
				do {
					this_lvl--;
					nextelem_to_reach = (t_llllelem *) llll_stack_pop(elem_to_reach_stack);
				} while (this_lvl > depth && *(elem_to_reach_stack->s_current) == nextelem_to_reach); // if this is true, we're at a ))...
				direction = -1;
                
                nextelem_to_reach = (t_llllelem *) *(elem_to_reach_stack->s_current);
                
			}
			this_elem = next_elem;
		}
		if (depth == 1)
			break;
		this_elem = (t_llllelem *) llll_stack_pop(base_stack);
		if (this_elem)
			ll = this_elem->l_parent;
		depth--;
		this_lvl--;
	}
	llll_stack_destroy(elem_to_reach_stack);
	llll_stack_destroy(base_stack);
	llll_downgrade_depth(ll);
	pedantic_llll_check(ll);
}

t_llll *llll_root(const t_llll *ll)
{
	t_llll *root = (t_llll *) ll;
	while (root->l_owner)
		root = root->l_owner->l_parent;
	return root;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE---
// remove a couple of parentheses around an H_LLLL element
// i.e., from 1 (2 3) (4) to 1 2 3 (4) if it's passed the element (2 3)
// works in place: the addresses of the elements of the sublist don't change

t_max_err llll_splatter(t_llllelem *elem, e_freething_modes freething)
{
	t_llll *parent, *child;
	t_llllelem *prev_elem, *next_elem;

	if (!elem || elem->l_hatom.h_type != H_LLLL)
		return MAX_ERR_GENERIC;
	
	pedantic_llll_check(llll_root(elem->l_parent));
	
	child = elem->l_hatom.h_w.w_llll;
	
	if (child->l_thing.w_obj) {
		switch (freething) {
			case LLLL_FREETHING_OBJ:
				object_free_debug(child->l_thing.w_obj);
				child->l_thing.w_obj = NULL;
				break;
			case LLLL_FREETHING_MEM:
				bach_freeptr(child->l_thing.w_obj);
				child->l_thing.w_obj = NULL;
				break;
			case LLLL_FREETHING_LLLL:
				llll_free((t_llll *) child->l_thing.w_obj);
				child->l_thing.w_obj = NULL;
				break;
			case LLLL_FREETHING_LLLLELEM:
				llllelem_free((t_llllelem *) child->l_thing.w_obj);
				child->l_thing.w_obj = NULL;
				break;
			default:
				break;
		}
	}
	
	parent = elem->l_parent;
	
	if (child->l_size) {
		llll_adopt(child, parent);
		prev_elem = elem->l_prev;
		next_elem = elem->l_next;
		
		if (prev_elem) {
			prev_elem->l_next = child->l_head;
			child->l_head->l_prev = prev_elem;
		} else {
			parent->l_head = child->l_head;
		}
		
		if (next_elem) {
			next_elem->l_prev = child->l_tail;
			child->l_tail->l_next = next_elem;
		} else {
			parent->l_tail = child->l_tail;
		}
		
		parent->l_size += child->l_size - 1;
		elem->l_flags = OBJ_FLAG_DATA;	// and then we chuck the sublist, and destroy the element who contains it
		llllelem_free(elem);
		llll_chuck_nocheck(child); // because parenthoods of elements are broken
	} else
		llll_destroyelem(elem);
	
	llll_downgrade_depth(parent);
	
	pedantic_llll_check(parent);

	return MAX_ERR_NONE;	
}

void llll_wrap(t_llll **ll, t_atom_long lvls)
{
	t_llll *out_ll;
	if (lvls < 1)
		return;
	while (lvls) {
		out_ll = llll_get();
		llll_appendllll(out_ll, *ll, 0, WHITENULL_llll);
		*ll = out_ll;
		lvls--;
	}
	pedantic_llll_check(*ll);
}

t_llll *llll_wrap_element_range(t_llllelem *from, t_llllelem *to)
{
	t_llllelem *elem, *newll_elem;
	t_llll *basell, *newll;
	t_atom_long len, depth, subdepth;
	
	if (!from || !to)
		return NULL;
	
	basell = from->l_parent;
	if (basell != to->l_parent)
		return NULL;

	newll = llll_get();
	newll_elem = llll_insertllll_before(newll, from, 0, WHITENULL_llll);
	newll->l_head = from;
	newll->l_tail = to;
	newll_elem->l_next = to->l_next;
	if (to->l_next)
		to->l_next->l_prev = newll_elem;
	else
		to->l_parent->l_tail = newll_elem;
	from->l_prev = NULL;
	to->l_next = NULL;
	
	depth = 1;
	for (elem = from, len = 0; elem; elem = elem->l_next, len++) {
		elem->l_parent = newll;
		if (elem->l_hatom.h_type == H_LLLL && (subdepth = elem->l_hatom.h_w.w_llll->l_depth) >= depth)
			depth = subdepth + 1;
	}
	newll->l_size = len;
	newll->l_depth = depth;
	basell->l_size -= len;
	llll_upgrade_depth(newll);
	pedantic_llll_check(newll);
	return newll;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE---
// ll becomes its left slice, returns right slice

t_llll *llll_slice(t_llll *ll, t_atom_long idx)
{
	t_llllelem *righthead;
	t_llll *outllll;
	
	if (!ll)
		return NULL;
	
	if (idx < 0)
		idx += ll->l_size;
	idx++;
	if (idx < LLLL_IDX_BASE)
		idx = LLLL_IDX_BASE;
	if (!(righthead = llll_getindex(ll, idx, I_NON_NEGATIVE)))
		return NULL;
	
	
	outllll = llll_get();
	outllll->l_head = righthead;
	outllll->l_tail = ll->l_tail;
	outllll->l_depth = ll->l_depth;
	outllll->l_size = ll->l_size - idx + LLLL_IDX_BASE;
	ll->l_size = idx - LLLL_IDX_BASE;
	llll_adopt(outllll, outllll);

	if (idx != LLLL_IDX_BASE) {
		ll->l_tail = righthead->l_prev;
		ll->l_tail->l_next = NULL;
		righthead->l_prev = NULL;		
		llll_downgrade_depth(outllll);
		llll_downgrade_depth(ll);
	} else {
		ll->l_head = ll->l_tail = NULL;
		ll->l_depth = 1;
	}
	pedantic_llll_check(ll);
	pedantic_llll_check(outllll);

	return outllll;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE---
#ifdef slow_scramble
void llll_scramble(t_llll *ll, t_int32 mindepth, t_int32 maxdepth)
{
	t_atom_long count, idx, lastidx;
	t_llll_stack *llstack;
	t_llll_stack *countstack;
	t_llll_stack *nextelemstack;
	t_llllelem *elem;
	t_llll *subll;
	t_int32 depth = 1;
	long deepenough;
	
	if (!ll)
		return;
	
	if (mindepth == 0)
		mindepth = 1;
	if (maxdepth == 0)
		maxdepth = -1;
	
	if (mindepth > ll->l_depth || maxdepth < -ll->l_depth)
		return;

	llstack = llll_stack_new();
	countstack = llll_stack_new();
	nextelemstack = llll_stack_new();
	count = ll->l_size;

	deepenough = (mindepth == 1 || ll ->l_depth < -mindepth);

	while (1) {
		lastidx = count - 1;
		elem = ll->l_head; // useless if deepenough
		while (count) {
			if (deepenough) {
				idx = rand() / (RAND_MAX + 1.) * count; // take the idx-th element and put it at the end - THIS IS 0-BASED
				if (ll->l_size > 1 && idx == 0) {
					elem = ll->l_head;
					ll->l_head = elem->l_next;
					ll->l_head->l_prev = NULL;
					elem->l_next = NULL;
					elem->l_prev = ll->l_tail;
					ll->l_tail->l_next = elem;
					ll->l_tail = elem;
				} else if (idx < lastidx) {
					elem = llll_getindex(ll, idx + LLLL_IDX_BASE, I_STANDARD);
					elem->l_prev->l_next = elem->l_next;
					elem->l_next->l_prev = elem->l_prev;
					elem->l_next = NULL;
					elem->l_prev = ll->l_tail;
					ll->l_tail->l_next = elem;
					ll->l_tail = elem;
				} else
					elem = ll->l_tail;
			}

			if ((subll = hatom_getllll(&elem->l_hatom)) && 
				(depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
//				(maxdepth == 0 || (maxdepth > 0 && depth < maxdepth - 1) || (maxdepth < 0 && elem->l_hatom.h_w.w_llll->l_depth > -maxdepth))) {
				depth++;
				llll_stack_push(llstack, ll);
				llll_stack_push(countstack, (void *) (count - 1));
				llll_stack_push(nextelemstack, elem->l_next); // only useful if not deep enough
				ll = elem->l_hatom.h_w.w_llll;
				count = ll->l_size;
				lastidx = count - 1;
				deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
				elem = ll->l_head; // useless if deepenough
			} else {
				count--;
				if (!deepenough)
					elem = elem->l_next;
			}
		}
		
		if (depth <= 1)
			break;
		depth--;
		ll = (t_llll *) llll_stack_pop(llstack);
		count = (t_atom_long) llll_stack_pop(countstack);
		elem = (t_llllelem *) llll_stack_pop(nextelemstack);
		deepenough = !elem || ((mindepth > 0 && depth >= mindepth) || (elem->l_parent->l_depth <= -mindepth));
	}
	llll_stack_destroy(llstack);
	llll_stack_destroy(countstack);
	llll_stack_destroy(nextelemstack);
	pedantic_llll_check(ll);
}

#else

void llll_scramble(t_llll *ll, t_int32 mindepth, t_int32 maxdepth)
{
	t_atom_long idx, count;
	t_llllelem *elem;
	t_llll *subll;
	t_int32 depth = 1;
	long deepenough;
	t_hatom *hatoms_as_array = NULL, *this_hatoms_as_array = NULL;
	t_hatom **arraypile, **this_arraypile;
	t_hatom **hatompile, **this_hatompile;
	t_llllelem **elempile, **this_elempile;
	long rootdepth;
	if (!ll || ll->l_size == 0 || (ll->l_size == 1 && ll->l_depth == 1))
		return;
	
	if (mindepth == 0)
		mindepth = 1;
	if (maxdepth == 0)
		maxdepth = -1;
	
	rootdepth = ll->l_depth;
	if (mindepth > rootdepth || maxdepth < -rootdepth)
		return;
	
	this_arraypile = arraypile = (t_hatom **) bach_newptrclear(rootdepth * sizeof(t_hatom *));
	this_elempile = elempile = (t_llllelem **) bach_newptr(rootdepth * sizeof(t_llllelem *));
	this_hatompile = hatompile = (t_hatom **) bach_newptr(rootdepth * sizeof(t_hatom *));

	deepenough = (mindepth == 1 || rootdepth <= -mindepth);
	long scramble_me = 1;
	elem = ll->l_head;
	while (1) {
		long size = ll->l_size;
		long size_in_bytes = size * sizeof(t_hatom);
		if (deepenough && size > 1) {
			if (scramble_me) {
				scramble_me = 0;
				if (*this_arraypile == NULL || sysmem_ptrsize(*this_arraypile) < size_in_bytes) {
					*this_arraypile = (t_hatom *) bach_resizeptr(*this_arraypile, size_in_bytes);
				}
				hatoms_as_array = *this_arraypile;
				for (this_hatoms_as_array = hatoms_as_array; elem; elem = elem->l_next, this_hatoms_as_array++)
					*this_hatoms_as_array = elem->l_hatom;
				for (count = size - 1; count > 0; count--) {
					t_hatom swap;
					idx = rand() % (count + 1);
					if (count != idx) {
						swap = hatoms_as_array[idx];
						hatoms_as_array[idx] = hatoms_as_array[count];
						hatoms_as_array[count] = swap;
					}
				}
				elem = ll->l_head;
				this_hatoms_as_array = hatoms_as_array;
			} 
			for ( ; elem; elem = elem->l_next, this_hatoms_as_array++) {
				elem->l_hatom = *this_hatoms_as_array;
				if (elem->l_hatom.h_type == H_LLLL) {
					subll = elem->l_hatom.h_w.w_llll;
					elem->l_hatom.h_w.w_llll->l_owner = elem;
					if ((depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth)) && subll->l_size > 0) {
						*(this_elempile++) = elem->l_next;
						*(this_hatompile++) = this_hatoms_as_array + 1;
						this_arraypile++;
						depth++;
						deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
						ll = subll;
						elem = ll->l_head;
						scramble_me = 1;
						break;
					}
				}
			}
		} else {
			scramble_me = 0;
			for ( ; elem; elem = elem->l_next, this_hatoms_as_array++) {
				if (elem->l_hatom.h_type == H_LLLL) {
					subll = elem->l_hatom.h_w.w_llll;
					subll->l_owner = elem;
					
					if ((depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth)) && subll->l_size > 0) {
						*(this_elempile++) = elem->l_next;
						*(this_hatompile++) = this_hatoms_as_array + 1;
						this_arraypile++;
						depth++;
						deepenough = ((mindepth >= 0 && depth >= mindepth) || (subll->l_depth <= -mindepth));
						ll = subll;
						elem = ll->l_head;
						scramble_me = 1;
						break;
					}
				}
			}
		}
		if (scramble_me)
			continue;
		if (depth == 1)
			break;
		do {
			elem = *(--this_elempile);
			this_hatoms_as_array = *(--this_hatompile);
			--this_arraypile;
			--depth;
		} while (depth >= 1 && elem == NULL);				
		if (depth == 0)
			break;
		ll = elem->l_parent;
		deepenough = (mindepth > 0 && depth >= mindepth) || (ll->l_depth <= -mindepth);
	}
	for (depth = 0, this_arraypile = arraypile; depth < rootdepth; depth++, this_arraypile++)
		bach_freeptr(*this_arraypile);
	bach_freeptr(arraypile);
	bach_freeptr(elempile);
	bach_freeptr(hatompile);
	pedantic_llll_check(ll);
}

#endif


///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE---
// returns array of lllls. the 0th elem is ll

t_llll **llll_delace(t_llll *ll, long outlists)
{
	t_llll **delaced;
	t_llll **this_delaced, **end_delaced;
	t_llllelem *elem, *nextelem;
	
	if (!ll)
		return NULL;
	
	delaced = (t_llll **) bach_newptr(outlists * sizeof (t_llll *));
	
	this_delaced = delaced;
	*this_delaced++ = ll;
	end_delaced = delaced + outlists;
	for ( ; this_delaced < end_delaced; this_delaced++)
		*this_delaced = llll_get();
	
	for (elem = ll->l_head; elem; elem = nextelem) {
		nextelem = elem->l_next;
		if (this_delaced == end_delaced) {
			this_delaced = delaced;
			(*this_delaced)->l_tail = elem;
		} else {
			elem->l_prev->l_next = nextelem;
			if (nextelem)
				nextelem->l_prev = elem->l_prev;

			if ((*this_delaced)->l_size) {
				elem->l_prev = (*this_delaced)->l_tail;
				(*this_delaced)->l_tail->l_next = elem;
				(*this_delaced)->l_tail = elem;
			} else {
				(*this_delaced)->l_head = (*this_delaced)->l_tail = elem;
				elem->l_prev = NULL;
			}
			(*this_delaced)->l_size++;
			ll->l_size--;
		}
		this_delaced ++;
	}
	
	this_delaced = delaced;
	if ((*this_delaced)->l_size) {
		(*this_delaced)->l_tail->l_next = NULL;
		llll_downgrade_depth(*this_delaced++);
	}
	for ( ; this_delaced < end_delaced; this_delaced++) {
		if ((*this_delaced)->l_size) {
			(*this_delaced)->l_tail->l_next = NULL;
			llll_adopt(*this_delaced, *this_delaced);
			llll_downgrade_depth(*this_delaced);
			pedantic_llll_check(*this_delaced);
	}
	}
	return delaced;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE---
// returns llll. the first sublist is ll

t_llll *llll_mdelace(t_llll *ll, long outlists)
{
	t_llll **delaced;
	t_llll **this_delaced, **end_delaced;
	t_llllelem *elem, *nextelem;
	t_llll *outlist;
	
	if (!ll)
		return NULL;
	
	delaced = (t_llll **) bach_newptr(outlists * sizeof (t_llll *));
	outlist = llll_get();
	
	this_delaced = delaced;
	*this_delaced++ = ll;
	end_delaced = delaced + outlists;
	for ( ; this_delaced < end_delaced; this_delaced++)
		*this_delaced = llll_get();
	
	for (elem = ll->l_head; elem; elem = nextelem) {
		nextelem = elem->l_next;
		if (this_delaced == end_delaced) {
			this_delaced = delaced;
			(*this_delaced)->l_tail = elem;
		} else {
			elem->l_prev->l_next = nextelem;
			if (nextelem)
				nextelem->l_prev = elem->l_prev;
			
			if ((*this_delaced)->l_size) {
				elem->l_prev = (*this_delaced)->l_tail;
				(*this_delaced)->l_tail->l_next = elem;
				(*this_delaced)->l_tail = elem;
			} else {
				(*this_delaced)->l_head = (*this_delaced)->l_tail = elem;
				elem->l_prev = NULL;
			}
			(*this_delaced)->l_size++;
			ll->l_size--;
		}
		this_delaced ++;
	}
	
	this_delaced = delaced;
	if ((*this_delaced)->l_size) {
		(*this_delaced)->l_tail->l_next = NULL;
		llll_downgrade_depth(*this_delaced);
		llll_appendllll(outlist, *this_delaced++, 0, WHITENULL_llll);
	}
	for ( ; this_delaced < end_delaced; this_delaced++) {
		if ((*this_delaced)->l_size) {
			(*this_delaced)->l_tail->l_next = NULL;
			llll_adopt(*this_delaced, *this_delaced);
			llll_downgrade_depth(*this_delaced);
			llll_appendllll(outlist, *this_delaced, 0, WHITENULL_llll);
		}
	}
	bach_freeptr(delaced);
	pedantic_llll_check(outlist);
	return outlist;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE on all lists


t_llll *llll_lace(t_llll **lists, t_atom_long count, long iterationmode)
{
	long lastlist = count - 1;
	t_llll **this_list, *new_llll;
	t_llllelem **elem = (t_llllelem **) bach_newptr(count * sizeof(t_llllelem *));
	t_llllelem **nextelem = (t_llllelem **) bach_newptrclear(count * sizeof(t_llllelem *));
	t_llllelem **this_elem, **this_nextelem;
	long are_there_nulls, are_there_things;
	t_atom_long i, subdepth;
	t_llll *outlist = llll_get();
	long outdepth = 1, outsize = 0;

	are_there_nulls = 0;
	are_there_things = 0;
	this_elem = elem + lastlist;
	this_nextelem = nextelem + lastlist;
	this_list = lists + lastlist;
	for ( ; this_elem >= elem; this_elem--, this_nextelem--, this_list--) {
		*this_elem = (*this_list)->l_head;
		if (*this_elem) {
			*this_nextelem = (*this_elem)->l_next;
			are_there_things = 1;
		} else
			are_there_nulls = 1;
	}

	while ((iterationmode == LLLL_M_ITERATION_STOP && !are_there_nulls) || 
		   (iterationmode != LLLL_M_ITERATION_STOP && are_there_things)) {
		
		for (this_elem = elem, i = 0; i < count; this_elem++, i++) {
			if (!*this_elem && iterationmode == LLLL_M_ITERATION_SHOOT) {
				new_llll = llll_get();
				*this_elem = llllelem_get();
				hatom_setllll(&(*this_elem)->l_hatom, new_llll);
				new_llll->l_owner = *this_elem;
				if (outdepth == 1)
					outdepth = 2;
			} else if (*this_elem && (*this_elem)->l_hatom.h_type == H_LLLL) {
				subdepth = (*this_elem)->l_hatom.h_w.w_llll->l_depth;
				if (subdepth >= outdepth)
					outdepth = subdepth + 1;
			}
			if (*this_elem) {
				if (outsize) {
					outlist->l_tail->l_next = *this_elem;
					(*this_elem)->l_prev = outlist->l_tail;
					outlist->l_tail = *this_elem;
				} else {
					outlist->l_head = outlist->l_tail = *this_elem;
					(*this_elem)->l_next = (*this_elem)->l_prev = NULL;
				}
				(*this_elem)->l_parent = outlist;
				outsize++;
			}
		}

		are_there_nulls = 0;
		are_there_things = 0;
		for (this_elem = elem + lastlist, this_nextelem = nextelem + lastlist; 
			 this_elem >= elem; 
			 this_elem--, this_nextelem--) {
			*this_elem = *this_nextelem;
			if (*this_elem) {
				*this_nextelem = (*this_elem)->l_next;
				are_there_things = 1;
			} else
				are_there_nulls = 1;
		}
	}
	outlist->l_size = outsize;
	outlist->l_depth = outdepth;

	for (this_elem = elem + lastlist, this_nextelem = nextelem + lastlist, this_list = lists + lastlist; 
		 this_elem >= elem; 
		 this_elem--, this_nextelem--, this_list--) {
		while (*this_elem) {
			*this_nextelem = (*this_elem)->l_next;
			llllelem_free(*this_elem); // was: nocheck
			*this_elem = *this_nextelem;
		}
		//llll_fix_owner_for_check(*this_list);
		llll_chuck_nocheck(*this_list); // was: nocheck
	}

	if (outlist->l_tail)
		outlist->l_tail->l_next = NULL;
	bach_freeptr(elem);
	bach_freeptr(nextelem);
	pedantic_llll_check(outlist);

	return outlist;
}

#ifdef ___destructive
///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- ll1 is altered, ll2 is freed
void llll_union(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	t_llllelem *elem1, *elem2, *next;
	
	if (!ll1 || !ll1)
		return;
	
	if (ll2->l_size == 0) {
		llll_free(ll2);
		return;
	}
	if (ll1->l_size == 0) {
		llll_clear(ll1);
		llll_transfer(ll2, ll1);
		llll_free(ll2);
		return;
	}
	
	if (cmpfn) {
		
		llll_put_elems_in_lllls_in_lthing(ll1);
		llll_put_elems_in_lllls_in_lthing(ll2);

		for (elem1 = ll1->l_head; elem1; elem1 = elem1->l_next) {
			for (elem2 = ll2->l_head; elem2; elem2 = next) {
				next = elem2->l_next;
				if ((cmpfn)(data, elem1, elem2)) {
					llll_free(elem2->l_thing.w_llll);
					llll_destroyelem(elem2);
				}
			}
		}
		if (ll2->l_size) {
			llll_chain(ll1, ll2);
		} else
			llll_free(ll2);

		llll_remove_lllls_from_lthing(ll1);
		pedantic_llll_check(ll1);
		return;
		
	} else {
		
		llll_inplacesort(ll1, (sort_fn) llll_leq_elem);
		llll_inplacesort(ll2, (sort_fn) llll_leq_elem);
		
		elem1 = ll1->l_head;
		elem2 = ll2->l_head;
		
		while (elem1) {
			while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
				elem2 = elem2->l_next;
			if (!elem2)
				break;
			if (llll_eq_elem_ignoretype(elem1, elem2)) {
				next = elem2->l_next;
				llll_destroyelem(elem2);
				elem2 = next;
			}
			elem1 = elem1->l_next;
		}
		if (ll2->l_size)
			llll_chain(ll1, ll2);
		else
			llll_free(ll2);
		pedantic_llll_check(ll1);
		return;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- ll1 is altered, ll2 is freed
// O(nˆ2) version

void llll_intersection(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	if (!ll1 || !ll2)
		return;
	
	if (ll1->l_size == 0) {
		llll_free(ll2);
		return;
	}
	if (ll2->l_size == 0) {
		llll_clear(ll1);
		llll_free(ll2);
		return;
	}
	
	if (cmpfn) {
		t_llllelem *elem1, *elem2, *next1, *next2;
		llll_put_elems_in_lllls_in_lthing(ll1);
		llll_put_elems_in_lllls_in_lthing(ll2);

		
		for (elem1 = ll1->l_head; elem1; elem1 = next1) {
			long keep = 0;

			next1 = elem1->l_next;
			for (elem2 = ll2->l_head; !keep && elem2; elem2 = next2) {
				next2 = elem2->l_next;
				if ((cmpfn)(data, elem1, elem2))
					keep = 1;
			}
			if (!keep) {
				llll_free(elem1->l_thing.w_llll);
				llll_destroyelem(elem1);
			}
		}
		llll_remove_lllls_from_lthing(ll1);
		llll_remove_lllls_from_lthing(ll2);

		llll_free(ll2);
		pedantic_llll_check(ll1);
		return;
	} else {
		t_llllelem *elem1, *elem2, *next;
		long pos = 0;
		llll_inplacesort(ll1, (sort_fn) llll_leq_elem);
		llll_inplacesort(ll2, (sort_fn) llll_leq_elem);
		
		elem1 = ll1->l_head;
		elem2 = ll2->l_head;

		while (elem1) {
			while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
				elem2 = elem2->l_next;
			if (!elem2)
				break;
			next = elem1->l_next;
			if (!llll_eq_elem_ignoretype(elem1, elem2)) {
				llll_destroyelem(elem1);
				pos--;
			}
			pos++;
			elem1 = next;
		}
		if (pos == 0) {
			llll_clear(ll1);
		} else if (pos < ll1->l_size) {
			ll1->l_tail = elem1->l_prev;
			
			while (elem1) {
				next = elem1->l_next;
				llllelem_free(elem1);
				elem1 = next;
			}
			ll1->l_tail->l_next = NULL;
			ll1->l_size = pos;
			llll_downgrade_depth(ll1);
		}
		llll_free(ll2);
		pedantic_llll_check(ll1);
		return;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- ll1 is altered, ll2 is freed

void llll_diff(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	
	if (!ll1 || !ll1)
		return;
	
	if (ll1->l_size == 0) {
		llll_clear(ll1);
		llll_free(ll2);
		return;
	}
	
	if (ll2->l_size == 0) {
		llll_free(ll2);
		return;
	}
	
	if (cmpfn) {
		t_llllelem *elem1, *elem2, *next1, *next2;

		llll_put_elems_in_lllls_in_lthing(ll1);
		llll_put_elems_in_lllls_in_lthing(ll2);
		
		for (elem1 = ll1->l_head; elem1; elem1 = next1) {
			next1 = elem1->l_next;
			for (elem2 = ll2->l_head; elem1 && elem2; elem2 = next2) {
				next2 = elem2->l_next;
				if ((cmpfn)(data, elem1, elem2)) {
					llll_free(elem1->l_thing.w_llll);
					llll_free(elem2->l_thing.w_llll);
					llll_destroyelem(elem1);
					llll_destroyelem(elem2);
					break;
				}
			}
		}
		llll_remove_lllls_from_lthing(ll1);
		llll_remove_lllls_from_lthing(ll2);
		llll_free(ll2);
		pedantic_llll_check(ll1);
		return;
		
	} else {
		t_llllelem *elem1, *elem2, *next;
		
		if (!ll1 || !ll2)
			return;
		
		if (ll1->l_size == 0) {
			llll_clear(ll1);
			llll_clone_upon(ll2, ll1);
			llll_free(ll2);
			return;
		}
		
		if (ll2->l_size == 0) {
			llll_free(ll2);
			return;
		}
		
		llll_inplacesort(ll1, (sort_fn) llll_leq_elem);
		llll_inplacesort(ll2, (sort_fn) llll_leq_elem);
		
		elem1 = ll1->l_head;
		elem2 = ll2->l_head;
		
		while (elem1) {
			while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
				elem2 = elem2->l_next;
			if (!elem2)
				break;
			next = elem1->l_next;
			if (llll_eq_elem_ignoretype(elem1, elem2))
				llll_destroyelem(elem1);
			elem1 = next;
		}
		
		llll_free(ll2);
		pedantic_llll_check(ll1);
		return;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- ll1 is altered, ll2 is freed

void llll_symdiff(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	t_llllelem *elem1, *elem2, *next1, *next2;
	long deleted;
	
	if (!ll1 || !ll1)
		return;
	
	if (ll2->l_size == 0) {
		llll_free(ll2);
		return;
	}
	if (ll1->l_size == 0) {
		llll_clear(ll1);
		llll_transfer(ll2, ll1);
		llll_free(ll2);
		return;
	}
	
	if (cmpfn) {
		llll_put_elems_in_lllls_in_lthing(ll1);
		llll_put_elems_in_lllls_in_lthing(ll2);

		for (elem1 = ll1->l_head; elem1; elem1 = next1) {
			next1 = elem1->l_next;
			for (deleted = 0, elem2 = ll2->l_head; !deleted && elem2; elem2 = next2) {
				next2 = elem2->l_next;
				if ((cmpfn)(data, elem1, elem2)) {
					deleted = 1;
					llll_free(elem1->l_thing.w_llll);
					llll_free(elem2->l_thing.w_llll);
					llll_destroyelem(elem1);
					llll_destroyelem(elem2);
				}
			}
		}

		if (ll2->l_size)
			llll_chain(ll1, ll2);
		else 
			llll_free(ll2);
		
		llll_remove_lllls_from_lthing(ll1);
		pedantic_llll_check(ll1);
		return;
	} else {
		llll_inplacesort(ll1, (sort_fn) llll_leq_elem);
		llll_inplacesort(ll2, (sort_fn) llll_leq_elem);
		
		elem1 = ll1->l_head;
		elem2 = ll2->l_head;
		
		while (elem1) {
			while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
				elem2 = elem2->l_next;
			if (!elem2)
				break;
			next1 = elem1->l_next;
			if (llll_eq_elem_ignoretype(elem1, elem2)) {
				next2 = elem2->l_next;
				llll_destroyelem(elem1);
				llll_destroyelem(elem2);
				elem2 = next2;
			}
			elem1 = next1;
		}
		if (ll2->l_size)
			llll_chain(ll1, ll2);
		else
			llll_free(ll2);
		pedantic_llll_check(ll1);
		return;
	}
}
#else


/////////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (destroys both lists)
// linear time version

t_llll *llll_union_simple(t_llll *in_ll1, t_llll *in_ll2)
{
	t_llll *ll1, *ll2;
	t_llllelem *elem1, *elem2, *next;
	
	if (!in_ll1 || !in_ll2)
		return NULL;
	
	if (in_ll2->l_size == 0) {
		llll_free(in_ll2);
		return in_ll1;
	}
	if (in_ll1->l_size == 0) {
		llll_free(in_ll1);
		return in_ll2;
	}
	
	llll_mergesort(in_ll1, &ll1, (sort_fn) llll_leq_elem, NULL);
	llll_mergesort(in_ll2, &ll2, (sort_fn) llll_leq_elem, NULL);
	
	elem1 = ll1->l_head;
	elem2 = ll2->l_head;
	
	while (elem1) {
		while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
			elem2 = elem2->l_next;
		if (!elem2)
			break;
		if (llll_eq_elem_ignoretype(elem1, elem2)) {
			next = elem2->l_next;
			llll_destroyelem(elem2);
			elem2 = next;
		}
		elem1 = elem1->l_next;
	}
	if (ll2->l_size)
		llll_chain(ll1, ll2);
	else
		llll_free(ll2);
	
	return ll1;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (ll1 contains the result, ll2 is destroyed)
// O(n^2), alas...
t_llll *llll_union(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	t_llllelem *elem1, *elem2, *next;
	
	if (!ll1 || !ll1)
		return NULL;
	
	if (ll2->l_size == 0) {
		llll_free(ll2);
		return ll1;
	}
	if (ll1->l_size == 0) {
		llll_free(ll1);
		return ll2;
	}
	
	llll_put_elems_in_lllls_in_lthing(ll1);
	llll_put_elems_in_lllls_in_lthing(ll2);
	
	for (elem1 = ll1->l_head; elem1; elem1 = elem1->l_next) {
		for (elem2 = ll2->l_head; elem2; elem2 = next) {
			next = elem2->l_next;
			if ((cmpfn)(data, elem1, elem2)) {
				llll_free(elem2->l_thing.w_llll);
				llll_destroyelem(elem2);
			}
		}
	}
	if (ll2->l_size) {
		llll_chain(ll1, ll2);
	} else
		llll_free(ll2);
	
	llll_remove_lllls_from_lthing(ll1);
	return ll1;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (destroys both lists)
// linear-time version

t_llll *llll_intersection_simple(t_llll *in_ll1, t_llll *in_ll2)
{
	t_llll *ll1, *ll2;
	t_llllelem *elem1, *elem2, *next;
	long pos = 0;
	
	if (!in_ll1 || !in_ll2)
		return NULL;
	
	if (in_ll1->l_size == 0) {
		llll_free(in_ll2);
		return in_ll1;
	}
	if (in_ll2->l_size == 0) {
		llll_free(in_ll1);
		return in_ll2;
	}
	
	llll_mergesort(in_ll1, &ll1, (sort_fn) llll_leq_elem, NULL);
	llll_mergesort(in_ll2, &ll2, (sort_fn) llll_leq_elem, NULL);
	
	elem1 = ll1->l_head;
	elem2 = ll2->l_head;
	
	
	while (elem1) {
		while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
			elem2 = elem2->l_next;
		if (!elem2)
			break;
		next = elem1->l_next;
		if (!llll_eq_elem_ignoretype(elem1, elem2)) {
			llll_destroyelem(elem1);
			pos--;
		}
		pos++;
		elem1 = next;
	}
	if (pos == 0) {
		llll_clear(ll1);
	} if (pos < ll1->l_size) {
		ll1->l_tail = elem1->l_prev;
		
		while (elem1) {
			next = elem1->l_next;
			llllelem_free(elem1);
			elem1 = next;
		}
		ll1->l_tail->l_next = NULL;
		ll1->l_size = pos;
		llll_downgrade_depth(ll1);
	}
	llll_free(ll2);
	return ll1;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (destroys both lists)
// O(nˆ2) version

t_llll *llll_intersection(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	t_llllelem *elem1, *elem2, *next1, *next2;
	long keep = 0;
	
	if (!ll1 || !ll1)
		return NULL;
	
	if (ll1->l_size == 0) {
		llll_free(ll2);
		return ll1;
	}
	if (ll2->l_size == 0) {
		llll_free(ll1);
		return ll2;
	}
	
	llll_put_elems_in_lllls_in_lthing(ll1);
	llll_put_elems_in_lllls_in_lthing(ll2);
	
	for (elem1 = ll1->l_head; elem1; elem1 = next1) {
		next1 = elem1->l_next;
		keep = 0;
		for (elem2 = ll2->l_head; !keep && elem2; elem2 = next2) {
			next2 = elem2->l_next;
			if ((cmpfn)(data, elem1, elem2))
				keep = 1;
		}
		if (!keep) {
			llll_free(elem1->l_thing.w_llll);
			llll_destroyelem(elem1);
		}
	}
	llll_remove_lllls_from_lthing(ll1);
	llll_remove_lllls_from_lthing(ll2);
	
	llll_free(ll2);
	return ll1;
}




///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (destroys both lists)
// linear time version

t_llll *llll_diff_simple(t_llll *in_ll1, t_llll *in_ll2)
{
	t_llll *ll1, *ll2;
	t_llllelem *elem1, *elem2, *next;
	
	if (!in_ll1 || !in_ll2)
		return NULL;
	
	if (in_ll1->l_size == 0) {
		llll_free(in_ll1);
		return in_ll2;
	}
	
	if (in_ll2->l_size == 0) {
		llll_free(in_ll2);
		return in_ll1;
	}
	
	llll_mergesort(in_ll1, &ll1, (sort_fn) llll_leq_elem, NULL);
	llll_mergesort(in_ll2, &ll2, (sort_fn) llll_leq_elem, NULL);
	
	elem1 = ll1->l_head;
	elem2 = ll2->l_head;
	
	while (elem1) {
		while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
			elem2 = elem2->l_next;
		if (!elem2)
			break;
		next = elem1->l_next;
		if (llll_eq_elem_ignoretype(elem1, elem2))
			llll_destroyelem(elem1);
		elem1 = next;
	}
	
	llll_free(ll2);
	return ll1;
}




///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (destroys both lists)
// O(nˆ2) version
t_llll *llll_diff(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	t_llllelem *elem1, *elem2, *next1, *next2;
	
	if (!ll1 || !ll1)
		return NULL;
	
	if (ll1->l_size == 0) {
		llll_free(ll1);
		return ll2;
	}
	
	if (ll2->l_size == 0) {
		llll_free(ll2);
		return ll1;
	}
	
	llll_put_elems_in_lllls_in_lthing(ll1);
	llll_put_elems_in_lllls_in_lthing(ll2);
	
	for (elem1 = ll1->l_head; elem1; elem1 = next1) {
		next1 = elem1->l_next;
		for (elem2 = ll2->l_head; elem1 && elem2; elem2 = next2) {
			next2 = elem2->l_next;
			if ((cmpfn)(data, elem1, elem2)) {
				llll_free(elem1->l_thing.w_llll);
				llll_free(elem2->l_thing.w_llll);
				llll_destroyelem(elem1);
				llll_destroyelem(elem2);
				break;
			}
		}
	}
	llll_remove_lllls_from_lthing(ll1);
	llll_remove_lllls_from_lthing(ll2);
	llll_free(ll2);
	return ll1;
}


// linear-time version
///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (destroys both lists)

t_llll *llll_symdiff_simple(t_llll *in_ll1, t_llll *in_ll2)
{
	t_llll *ll1, *ll2;
	t_llllelem *elem1, *elem2, *next1, *next2;
	
	if (!in_ll1 || !in_ll2)
		return NULL;
	
	if (in_ll1->l_size == 0) {
		llll_free(in_ll1);
		return in_ll2;
	}
	
	if (in_ll2->l_size == 0) {
		llll_free(in_ll2);
		return in_ll1;
	}
	
	llll_mergesort(in_ll1, &ll1, (sort_fn) llll_leq_elem, NULL);
	llll_mergesort(in_ll2, &ll2, (sort_fn) llll_leq_elem, NULL);
	
	elem1 = ll1->l_head;
	elem2 = ll2->l_head;
	
	while (elem1) {
		while (elem2 && !llll_leq_elem(NULL, elem1, elem2))
			elem2 = elem2->l_next;
		if (!elem2)
			break;
		next1 = elem1->l_next;
		if (llll_eq_elem_ignoretype(elem1, elem2)) {
			next2 = elem2->l_next;
			llll_destroyelem(elem1);
			llll_destroyelem(elem2);
			elem2 = next2;
		}
		elem1 = next1;
	}
	if (ll2->l_size)
		llll_chain(ll1, ll2);
	else
		llll_free(ll2);
	return ll1;
}


// O(nˆ2) version
///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- (destroys both lists)

t_llll *llll_symdiff(t_llll *ll1, t_llll *ll2, sets_fn cmpfn, void *data)
{
	t_llllelem *elem1, *elem2, *next1, *next2;
	long deleted;
	
	if (!ll1 || !ll1)
		return NULL;
	
	if (ll2->l_size == 0) {
		llll_free(ll2);
		return ll1;
	}
	if (ll1->l_size == 0) {
		llll_free(ll1);
		return ll2;
	}
	
	llll_put_elems_in_lllls_in_lthing(ll1);
	llll_put_elems_in_lllls_in_lthing(ll2);
	
	for (elem1 = ll1->l_head; elem1; elem1 = next1) {
		next1 = elem1->l_next;
		for (deleted = 0, elem2 = ll2->l_head; !deleted && elem2; elem2 = next2) {
			next2 = elem2->l_next;
			if ((cmpfn)(data, elem1, elem2)) {
				deleted = 1;
				llll_free(elem1->l_thing.w_llll);
				llll_free(elem2->l_thing.w_llll);
				llll_destroyelem(elem1);
				llll_destroyelem(elem2);
			}
		}
	}
	
	if (ll2->l_size)
		llll_chain(ll1, ll2);
	else
		llll_free(ll2);
	
	llll_remove_lllls_from_lthing(ll1);
	return ll1;
}
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////
// is it a prime?
long llll_prime(long what)
{
	long *center_elem, scope;
	long *table_last = primes + LLLL_PRIMES_TABLE_SIZE - 1;
	long *this_table;
	if (what < 0)
		what *= -1;
	if (what < 2 || what == 4)
		return 0;
	if (what < 6)
		return 1;
	if (what % 6 != 1 && what % 6 != 5)
		return 0;
	if (what <= LLLL_PRIMES_TABLE_MAX) {
		scope = LLLL_PRIMES_TABLE_SIZE / 2;
		center_elem = primes + scope;
		while (1) {
			if (*center_elem == what)
				return 1;
			if (*(center_elem - 1) < what && *center_elem > what)
				return 0;
			scope = scope / 2 + scope % 2;
			if (*center_elem < what) {
				center_elem += scope;
				if (center_elem > table_last)
					center_elem = table_last;
			} else {
				center_elem -= scope;
				if (center_elem < primes)
					center_elem = primes;
			}
		}
	} // there _should certainly be a return!
	
	for (this_table = primes; this_table <= table_last; this_table++) {
		if (what % *this_table == 0)
			return 0;
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

t_llll *llll_factorize(long what)
{
	t_llll *factors = llll_get();
	t_llll *this_factor;
	t_atom_long exponent;
	long *table_last = primes + LLLL_PRIMES_TABLE_SIZE - 1;
	long *this_table = primes;
	long this_prime;
	
	if (what < 0)
		what *= -1;
	while (what > 1 && this_table <= table_last) {
		this_prime = *this_table;
		if (what % this_prime == 0) {
			this_factor = llll_get();
			llll_appendlong(this_factor, this_prime, 0, WHITENULL_llll);
			exponent = 0;
			do {
				exponent++;
				what /= this_prime;
			} while (what % this_prime == 0);
			llll_appendlong(this_factor, exponent, 0, WHITENULL_llll);
			llll_appendllll(factors, this_factor, 0, WHITENULL_llll);
		}
		this_table++;
	}
/*
 if the number is not reduced after all the factors < sqrt(MAXLONG) have been found,
 then the remaining factor must be the only one, and a prime
 because otherwise there would be two factors > sqrt(MAXLONG)
 */	
	if (what > 1) {
		this_factor = llll_get();
		llll_appendlong(this_factor, what, 0, WHITENULL_llll);
		llll_appendlong(this_factor, 1, 0, WHITENULL_llll);
		llll_appendllll(factors, this_factor, 0, WHITENULL_llll);
	}
	pedantic_llll_check(factors);
	return factors;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

t_llll *llll_primeser(long min, long max, long maxcount)
{
	long *table_last = primes + LLLL_PRIMES_TABLE_SIZE - 1;
	long *center_elem = NULL, scope;
	t_llll *ser = llll_get();

	
	if (max < 0)
		max = LONG_MAX;
	if (min <= 2) {
		min = 2;
		center_elem = primes;
	}
	if (min > max)
		return ser;

	if (min > 2 && min <= LLLL_PRIMES_TABLE_MAX) {
		scope = LLLL_PRIMES_TABLE_SIZE / 2;
		center_elem = primes + scope;
		while (1) {
			if (*(center_elem - 1) < min && *center_elem >= min) {
				min = *center_elem;
				break;
			}
			scope = scope / 2 + scope % 2;
			if (*center_elem < min) {
				center_elem += scope;
				if (center_elem > table_last)
					center_elem = table_last;
			} else {
				center_elem -= scope;
				if (center_elem < primes)
					center_elem = primes;
			}
		}
	} else if (min > LLLL_PRIMES_TABLE_MAX) {
		switch (min % 6) {
			case 1:
			case 5:
				break;
			case 0:
				min ++;
				break;
			default:
				min += 5 - min % 6;
				break;
		}
		
		while (!llll_prime(min))
			min += (min % 6 == 1) ? 4 : 2;
	}
	
	while (min <= max && min > 0) { // we stop at overflow
		llll_appendlong(ser, min, 0, WHITENULL_llll);
		if (--maxcount == 0)
			break;
		if (min < LLLL_PRIMES_TABLE_MAX)
			min = *(++center_elem);
		else
			do { 
				min += (min % 6 == 1) ? 4 : 2;
			} while (!llll_prime(min));
	}
	pedantic_llll_check(ser);
	return ser;
}

t_llll *llll_arithmser(t_hatom start_hatom, t_hatom end_hatom, t_hatom step_hatom, t_atom_long maxcount)
{
	long start_type = hatom_gettype(&start_hatom);
	long end_type = hatom_gettype(&end_hatom);
	long step_type = hatom_gettype(&step_hatom);
	t_llll *outll = llll_get();
	t_bool maxcount_decides = false;
	
	if (start_type == H_DOUBLE || end_type == H_DOUBLE || step_type == H_DOUBLE) {
		double start, end, step, v;
		t_atom_long count;
		step = hatom_getdouble(&step_hatom);
        
        if (hatom_type_is_number(start_type)) {
            start = hatom_getdouble(&start_hatom);
        } else {
            if (!(hatom_type_is_number(end_type))) {
                return outll;
            } else if (maxcount == 1) {
                start = end = hatom_getdouble(&end_hatom);
            } else if (step == 0 || maxcount <= 0) {
                return outll;
            } else {
                end = hatom_getdouble(&end_hatom);
                start = end - step * (maxcount - 1);
            }
        }
        
        if (hatom_type_is_number(end_type)) {
			end = hatom_getdouble(&end_hatom);
        } else if (maxcount == 1) {
            end = start;
        } else {
			if (step == 0 || maxcount <= 0)
				return outll;
            else
                end = step > 0 ? DBL_MAX : -DBL_MAX;
		}
        
		if (step == 0) {
			if (maxcount <= 0) {
				step = start <= end ? 1 : -1;
				maxcount = ATOM_LONG_MAX;
			} else {
				maxcount_decides = true;
                if (maxcount > 1)
                    step = (end - start) / (maxcount - 1);
			}
		} else if (maxcount <= 0)
			maxcount = ATOM_LONG_MAX;
		
		if (!maxcount_decides) {
			if (step > 0) {
				for (v = start, count = 0; v <= end && count < maxcount; v += step, count++)
					llll_appenddouble(outll, v, 0, WHITENULL_llll);
			} else {
				for (v = start, count = 0; v >= end && count < maxcount; v += step, count++)
					llll_appenddouble(outll, v, 0, WHITENULL_llll);
			}
		} else {
			//if (step > 0) {
				for (v = start, count = 0; count < maxcount; v += step, count++)
					llll_appenddouble(outll, v, 0, WHITENULL_llll);
			//} else {
			//	for (v = start, count = 0; count < maxcount; v += step, count++)
			//		llll_appenddouble(outll, v, 0, WHITENULL_llll);
			//}
			outll->l_tail->l_hatom.h_w.w_double = end;
		}
		pedantic_llll_check(outll);
		return outll;
		
	} else if (start_type == H_RAT || end_type == H_RAT || step_type == H_RAT) {
		t_rational start, end, step, v;
		t_atom_long count;
		step = hatom_getrational(&step_hatom);
        
        if (hatom_type_is_number(start_type)) {
            start = hatom_getrational(&start_hatom);
        } else {
            if (!(hatom_type_is_number(end_type))) {
                return outll;
            } else if (maxcount == 1) {
                start = end = hatom_getrational(&end_hatom);
            } else if (step.r_num == 0 || maxcount <= 0) {
                return outll;
            } else {
                end = hatom_getrational(&end_hatom);
                start = rat_rat_diff(end, rat_long_prod(step, maxcount - 1));
            }
        }
        
		if (hatom_type_is_number(end_type)) {
			end = hatom_getrational(&end_hatom);
		} else {
			if (step.r_num == 0 || maxcount <= 0)
				return outll;
			end = step.r_num > 0 ? RAT_MAX : RAT_MIN;
		}
		if (step.r_num == 0) {
			if (maxcount <= 0) {
				step = rat_rat_cmp(start, end) <= 0 ? genrat(1, 1) : genrat(-1, 1);
				maxcount = ATOM_LONG_MAX;
			} else {
                if (maxcount > 1) {
                    step = rat_long_div(rat_rat_diff(end, start), maxcount - 1);
                }
				if (step.r_num == 0)
					step = rat_rat_cmp(start, end) <= 0 ? RAT_MIN_POSITIVE : RAT_MAX_NEGATIVE;
			}
		} else if (maxcount <= 0)
			maxcount = ATOM_LONG_MAX;
		
		if (step.r_num > 0) {
			for (v = start, count = 0; rat_rat_cmp(v, end) <= 0 && count < maxcount; v = rat_rat_sum(v, step), count++)
				llll_appendrat(outll, v, 0, WHITENULL_llll);
		} else {
			for (v = start, count = 0; rat_rat_cmp(v, end) >= 0 && count < maxcount; v = rat_rat_sum(v, step), count++)
				llll_appendrat(outll, v, 0, WHITENULL_llll);
		}
		pedantic_llll_check(outll);
		return outll;
		
	} else if (start_type == H_LONG || end_type == H_LONG || step_type == H_LONG) {
		t_atom_long start, end, step, v;
		t_atom_long count;
		step = hatom_getlong(&step_hatom);

        if (hatom_type_is_number(start_type)) {
            start = hatom_getlong(&start_hatom);
        } else {
            if (!(hatom_type_is_number(end_type))) {
                return outll;
            } else if (maxcount == 1) {
                start = end = hatom_getdouble(&end_hatom);
            } else if (step == 0 || maxcount <= 0) {
                return outll;
            } else {
                end = hatom_getlong(&end_hatom);
                start = end - step * (maxcount - 1);
            }
        }
        if (hatom_type_is_number(end_type)) {
			end = hatom_getlong(&end_hatom);
		} else {
			if (step == 0 || maxcount <= 0)
				return outll;
			end = step > 0 ? ATOM_LONG_MAX : ATOM_LONG_MIN;
		}
		if (step == 0) {
			if (maxcount <= 0) {
				step = start <= end ? 1 : -1;
				maxcount = ATOM_LONG_MAX;
			} else {
                if (maxcount > 1)
                    step = (end - start) / (maxcount - 1);
				if (step == 0)
					step = start <= end ? 1 : -1;
			}
		} else if (maxcount <= 0)
			maxcount = ATOM_LONG_MAX;
		
		if (step > 0) {
			for (v = start, count = 0; v <= end && count < maxcount; v += step, count++)
				llll_appendlong(outll, v, 0, WHITENULL_llll);
		} else {
			for (v = start, count = 0; v >= end && count < maxcount; v += step, count++)
				llll_appendlong(outll, v, 0, WHITENULL_llll);
		}
		pedantic_llll_check(outll);
		return outll;
        
    } else { // pitches
        t_pitch start, end, step, v;
        t_atom_long count;
        step = hatom_getpitch(&step_hatom);
        
        if (hatom_type_is_number(start_type)) {
            start = hatom_getpitch(&start_hatom);
        } else {
            if (!(hatom_type_is_number(end_type))) {
                return outll;
            } else if (maxcount == 1) {
                start = end = hatom_getpitch(&end_hatom);
            } else if (step == t_pitch::C0 || maxcount <= 0) {
                return outll;
            } else {
                end = hatom_getpitch(&end_hatom);
                start = end - step * (maxcount - 1);
            }
        }
        
        if (hatom_type_is_number(end_type)) {
            end = hatom_getpitch(&end_hatom);
        } else {
            if (step == t_pitch::C0 || maxcount <= 0)
                return outll;
            end = step > t_pitch::C0 ? PITCH_MAX : PITCH_MIN;
        }
        if (step == t_pitch::C0) {
            if (maxcount <= 0) {
                step =  start < end ? t_pitch(1, t_pitch::flat, 0) : t_pitch(6, t_pitch::natural, -1);
                maxcount = ATOM_LONG_MAX;
            } else {
                if (maxcount > 1) {
                    step = (end - start) / (maxcount - 1);;
                }
                if (step == t_pitch::C0)
                    step = start < end ? PITCH_MIN_POSITIVE : PITCH_MAX_NEGATIVE;
            }
        } else if (maxcount <= 0)
            maxcount = ATOM_LONG_MAX;
        
        if (step > t_pitch::C0) {
            for (v = start, count = 0; v <= end && count < maxcount; v += step, count++)
                llll_appendpitch(outll, v, 0, WHITENULL_llll);
        } else {
            for (v = start, count = 0; v >= end && count < maxcount; v += step, count++)
                llll_appendpitch(outll, v, 0, WHITENULL_llll);
        }
        pedantic_llll_check(outll);
        return outll;
    }
}

t_llll *llll_geomser(t_object *x, t_hatom start_hatom, t_hatom end_hatom, t_hatom factor_hatom, t_atom_long maxcount, long *err)
{
	long start_type = hatom_gettype(&start_hatom);
	long end_type = hatom_gettype(&end_hatom);
	long factor_type = hatom_gettype(&factor_hatom);
	t_llll *outll = llll_get();
	*err = 0;

	if (start_type == H_DOUBLE || end_type == H_DOUBLE || factor_type == H_DOUBLE) {
		double start, end, factor, v;
		t_atom_long count;
		
		start = hatom_getdouble(&start_hatom);
		if (start == 0) {
			object_error(x, "Start can't be 0");
			*err = 1;
			return outll;
		}
		
		factor = hatom_getdouble(&factor_hatom);
		if ((factor == 1 || factor == -1) && maxcount <= 0) {
			object_error(x, "Factor can't be %ld if the maximum number of elements is not set", (long) factor);
			*err = 1;
			return outll;
		}
		
		if (maxcount <= 0)
			maxcount = LONG_MAX;
			
		if (hatom_type_is_number(end_type)) {
			end = hatom_getdouble(&end_hatom);
		} else {
			if (factor == 0) {
				object_error(x, "Insufficient data");
				*err = 1;
				return outll;
			}
			double factor_abs = fabs(factor);
			if (factor_abs >= 1) {
				end = start > 0 ? DBL_MAX : -DBL_MAX;
			} else {
				end = start > 0 ? DBL_MIN : -DBL_MIN;
			}
		}
		if (factor == 0) {
			factor = start <= end ? 2 : -2;
		}
		
		if ((start > 0 && factor >= 1) || (start < 0 && factor > 0 && factor < 1)) {
			for (v = start, count = 0; v <= end && count < maxcount; v *= factor, count++)
				llll_appenddouble(outll, v, 0, WHITENULL_llll);
		} else if ((start > 0 && factor > 0 && factor < 1) || (start < 0 && factor >= 1)) {
			for (v = start, count = 0; v >= end && count < maxcount; v *= factor, count++)
				llll_appenddouble(outll, v, 0, WHITENULL_llll);
		} else if (factor <= -1) {
			double end_abs = fabs(end);
			for (v = start, count = 0; fabs(v) <= end_abs && count < maxcount; v *= factor, count++)
				llll_appenddouble(outll, v, 0, WHITENULL_llll);
		} else { // factor < 0 && factor > -1
			double end_abs = fabs(end);
			for (v = start, count = 0; fabs(v) >= end_abs && count < maxcount; v *= factor, count++)
				llll_appenddouble(outll, v, 0, WHITENULL_llll);
		}
		pedantic_llll_check(outll);
		return outll;
		
	} else if (start_type == H_RAT || end_type == H_RAT || factor_type == H_RAT ||
               start_type == H_PITCH || end_type == H_PITCH || factor_type == H_PITCH) {
		t_rational start, end, factor, v;
		t_atom_long count;
		
		start = hatom_getrational(&start_hatom);
		if (start.r_num == 0) {
			object_error(x, "Start can't be 0");
			*err = 1;
			return outll;
		}
		
		factor = hatom_getrational(&factor_hatom);
		if (factor.r_den == 1 && (factor.r_num == 1 || factor.r_num == -1) && maxcount <= 0) {
			object_error(x, "Factor can't be " ATOM_LONG_PRINTF_FMT " if the maximum number of elements is not set", factor.r_num);
			*err = 1;
			return outll;
		}
		
		if (maxcount <= 0)
			maxcount = LONG_MAX;

		if (hatom_type_is_number(end_type)) {
			end = hatom_getrational(&end_hatom);
		} else {
			if (factor.r_num == 0) {
				object_error(x, "Insufficient data");
				*err = 1;
				return outll;
			}
			t_atom_long factor_num_abs = factor.r_num > 0 ? factor.r_num : -factor.r_num;
			if (factor_num_abs >= factor.r_den) {
				end = start.r_num > 0 ? RAT_MAX : RAT_MIN;
			} else {
				end = start.r_num > 0 ? RAT_MIN_POSITIVE : RAT_MAX_NEGATIVE;
			}
		}
		if (factor.r_num == 0) {
			factor.r_num = rat_rat_cmp(start, end) <= 0 ? 2 : -2;
			factor.r_den = 1;
		}
		
		if ((start.r_num > 0 && rat_long_cmp(factor, 1) > 0) || (start.r_num < 0 && factor.r_num > 0 && rat_long_cmp(factor, 1) < 0)) {
			for (v = start, count = 0; rat_rat_cmp(v, end) <= 0 && count < maxcount; v = rat_rat_prod(v, factor), count++)
				llll_appendrat(outll, v, 0, WHITENULL_llll);
		} else if ((start.r_num > 0 && factor.r_num > 0 && rat_long_cmp(factor, 1) < 0) || (start.r_num < 0 && rat_long_cmp(factor, 1) > 0)) {
			for (v = start, count = 0; rat_rat_cmp(v, end) >= 0 && count < maxcount; v = rat_rat_prod(v, factor), count++)
				llll_appendrat(outll, v, 0, WHITENULL_llll);
		} else if (factor.r_num < -1) {
			t_rational end_abs = rat_abs(end);
			for (v = start, count = 0; rat_rat_cmp(rat_abs(v), end_abs) <= 0 && count < maxcount; v = rat_rat_prod(v, factor), count++)
				llll_appendrat(outll, v, 0, WHITENULL_llll);
		} else {
			t_rational end_abs = rat_abs(end);
			for (v = start, count = 0; rat_rat_cmp(rat_abs(v), end_abs) >= 0 && count < maxcount; v = rat_rat_prod(v, factor), count++)
				llll_appendrat(outll, v, 0, WHITENULL_llll);
		}
		pedantic_llll_check(outll);
		return outll;
		
	} else {
		t_atom_long start, end, factor, v;
		t_atom_long count;
		
		start = hatom_getlong(&start_hatom);
		if (start == 0) {
			object_error(x, "Start can't be 0");
			*err = 1;
			return outll;
		}
		
		factor = hatom_getlong(&factor_hatom);
		if ((factor == 1 || factor == -1) && maxcount <= 0) {
			object_error(x, "Factor can't be " ATOM_LONG_PRINTF_FMT " if the maximum number of elements is not set", factor);
			*err = 1;
			return outll;
		}
		
		if (maxcount <= 0)
			maxcount = LONG_MAX;		
		if (hatom_type_is_number(end_type)) {
			end = hatom_getlong(&end_hatom);
		} else {
			if (factor == 0) {
				object_error(x, "Insufficient data");
				*err = 1;
				return outll;
			}
			end = start > 0 || factor < 0 ? LONG_MAX : LONG_MIN;
		}
		if (factor == 0) {
			factor = start <= end ? 2 : -2;
		}
		
		if (start > 0 && factor > 1) {
			for (v = start, count = 0; v <= end && count < maxcount; v *= factor, count++)
				llll_appendlong(outll, v, 0, WHITENULL_llll);
		} else if (start < 0 && factor > 1) {
			for (v = start, count = 0; v >= end && count < maxcount; v *= factor, count++)
				llll_appendlong(outll, v, 0, WHITENULL_llll);
		} else {
			t_atom_long end_abs = alabs(end);
			for (v = start, count = 0; alabs(v) <= end_abs && count < maxcount; v *= factor, count++)
				llll_appendlong(outll, v, 0, WHITENULL_llll);
		}
		pedantic_llll_check(outll);
		return outll;
		
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/**
 from
 (1/60) (1/60) 1/60 1/60 1/60 1/12 1/12 ((1/8 1/8) 1/8 1/8) 1/4
 obtain
 (1/60) (1/60) (1/60 1/60 1/60 1/12 1/12) ((1/8 1/8) (1/8 1/8)) (1/4)
 returns a new llll
 */

void llll_plateaus(t_llll *ll, t_atom_long min_plateau_len, t_int32 maxdepth, t_llll *plateaus_ll)
{
	t_llll_stack *stack;
	t_llllelem *elem;
	
	if (ll == NULL)
		return;
	
	if (ll->l_depth == 1)
		return;
	
	stack = llll_stack_new();
	
	elem = ll->l_head;
	if (maxdepth == 0)
		maxdepth = -1;

	while (1) {
		while (elem) {
			if (elem->l_hatom.h_type == H_LLLL) {
				t_llll *subll = elem->l_hatom.h_w.w_llll;
				if (subll->l_depth > 1 && (stack->s_items + 1 < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
					llll_stack_push(stack, elem->l_next);
					elem = subll->l_head;
					ll = subll;
				} else
					elem = elem->l_next;
			} else {
				t_llllelem *this_seq_elem;
				t_llllelem *last_seq_elem = elem;
				t_atom_long n;
				for (this_seq_elem = elem->l_next, n = 1; this_seq_elem && this_seq_elem->l_hatom.h_type != H_LLLL; this_seq_elem = this_seq_elem->l_next, n++)
					last_seq_elem = this_seq_elem;
				if (n >= min_plateau_len) {
					t_llll *plateau = llll_get();
					t_llllelem *plateau_elem = llllelem_get();
					if (plateaus_ll)
						llll_appendobj(plateaus_ll, plateau_elem, 0, WHITENULL_llll);
					hatom_setllll(&plateau_elem->l_hatom, plateau);
					plateau->l_owner = plateau_elem;
					plateau_elem->l_parent = ll;
					plateau->l_head = elem;
					plateau->l_tail = last_seq_elem;
					plateau->l_size = n;
					if (elem->l_prev) {
						plateau_elem->l_prev = elem->l_prev;
						elem->l_prev->l_next = plateau_elem;
						elem->l_prev = NULL;
					} else {
						ll->l_head = plateau_elem;
					}
					elem = last_seq_elem->l_next; // so it's ready for the next cycle
					if (elem) {
						plateau_elem->l_next = elem;
						elem->l_prev = plateau_elem;
						last_seq_elem->l_next = NULL;
					} else {
						ll->l_tail = plateau_elem;
					}
					ll->l_size -= n - 1;
					llll_adopt(plateau, plateau);
				} else
					elem = this_seq_elem;
			}
		}
		if (stack->s_items == 0)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
		if (elem)
			ll = elem->l_parent;
	}

	llll_stack_destroy(stack);
	pedantic_llll_check(ll);
	return;
}

// from 1 2 (3 4) 5 to (1) (2) (3 4) (5)
void llll_fatten(t_llll *ll)
{
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) != H_LLLL) {
			t_llll *newsub = llll_get();
			llll_appendhatom(newsub, &elem->l_hatom, 0, WHITENULL_llll);
			hatom_change_to_llll(&elem->l_hatom, newsub);
		}
	}
	pedantic_llll_check(ll);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
 impose the structure of modelll onto inll
 */
void llll_reshape(t_llll *ll, t_llll *modelll, llll_clone_fn fn)
{
	t_llllelem *elem, *modelelem, *nextelem = NULL, *newelem = NULL, *prevelem = NULL, *nilelem = NULL;
	t_llll_stack *modelstack;
	t_llll *newll, *parent = NULL;
	t_atom_long newdepth;
	long downgrade = 0;

	if (!ll || !modelll || ll->l_size == 0 || modelll->l_size == 0)
		return;
	
	if (modelll->l_thing.w_obj)
		ll->l_thing.w_obj = fn ? (fn)(modelll->l_thing.w_obj) : modelll->l_thing.w_obj;

	elem = ll->l_head;
	modelelem = modelll->l_head;
	modelstack = llll_stack_new();

	ll->l_size = 0;
	ll->l_depth = 1;
	ll->l_tail = NULL;
	while (1) {
		while (elem && modelelem) {
			if (prevelem) { // prevelem is NULL, unless we come 
				elem->l_prev = prevelem;
				prevelem->l_next = elem;
				prevelem = NULL;
			}
			if (modelelem->l_hatom.h_type == H_LLLL) { // if we have an llll in modelll, then place one in ll
				modelll = modelelem->l_hatom.h_w.w_llll;
				newll = llll_get();
				if (modelll->l_thing.w_obj)
					newll->l_thing.w_obj = fn ? (fn)(modelll->l_thing.w_obj) : modelll->l_thing.w_obj;

				if (ll->l_depth == 1) {
					ll->l_depth = 2;
					llll_upgrade_depth(ll);
				}
				nilelem = llllelem_get();
				hatom_setllll(&nilelem->l_hatom, newll);
				newll->l_owner = nilelem;
				nilelem->l_parent = ll;					
				if (ll->l_tail) {
					nilelem->l_prev = ll->l_tail;
					nilelem->l_prev->l_next = ll->l_tail = nilelem;
				} else {
					ll->l_head = ll->l_tail = nilelem;
				}
				ll->l_size++;	
				if (modelll->l_size != 0) {
					elem->l_prev = NULL; 
					newelem = nilelem;
					nilelem = NULL;
					newll->l_head = elem;
					parent = ll;
					ll = newll;
					llll_stack_push(modelstack, modelelem->l_next);
					modelelem = modelll->l_head;
				} else
					modelelem = modelelem->l_next;
			} else {
				nextelem = elem->l_next;
				if (elem->l_hatom.h_type == H_LLLL) {
					newdepth = elem->l_hatom.h_w.w_llll->l_depth + 1;
					if (ll->l_depth < newdepth) {
						ll->l_depth = newdepth;
						llll_upgrade_depth(ll);
					}
				}
				elem->l_parent = ll;
				ll->l_size++;
				modelelem = modelelem->l_next;
				ll->l_tail = elem;
				if (nilelem) {
					nilelem->l_next = elem;
					elem->l_prev = nilelem;
					nilelem = NULL;
				}
				if (!nextelem || !modelelem)
					break;
				elem = nextelem;
			}
		}
		if (!elem)
			break;
		elem->l_next = NULL;
		if (modelstack->s_items == 0)
			break;
		modelelem = (t_llllelem *) llll_stack_pop(modelstack);
		if (modelelem) // if it's not a pop!
			elem = nextelem;
		ll = parent;
		prevelem = newelem;
		if (ll && ll->l_owner) {
			newelem = ll->l_owner;
			parent = newelem->l_parent;
		} else {
			newelem = NULL;
			parent = NULL;
		}
		nilelem = NULL;
	}

	while ((elem = ll->l_owner)) {
		elem = ll->l_owner;
		elem->l_next = NULL;
		ll = elem->l_parent;
		ll->l_tail = elem;
	}
/*	
	while (modelelem && modelelem->l_hatom.h_type == H_LLLL && modelelem->l_hatom.h_w.w_llll->l_size == 0) {
		llll_appendllll(ll, llll_get(), 0, WHITENULL_llll);
		modelelem = modelelem->l_next;
	}
*/	
	for (elem = nextelem; elem; elem = nextelem) {
		if (elem->l_hatom.h_type == H_LLLL)
			downgrade = 1;
		nextelem = elem->l_next;
		llllelem_free(elem);
	}
	
	if (downgrade)
		llll_downgrade_depth(ll);
/*
	if (elem != ll->l_tail) {
		for ( ; elem; elem = nextelem) {
			nextelem = elem->l_next;
			llll_destroyelem(elem);
		}
	}*/
	llll_stack_destroy(modelstack);
	pedantic_llll_check(ll);
}

/*
 ---DESTRUCTIVE
 divide an llll in modulo-sized lllls
 e.g. 1 2 3 4 5 6 7 8 with modulo 3 => (1 2 3) (4 5 6) (7 8)
 */
t_max_err llll_groupllll(t_llll *ll, t_atom_long modulo, t_atom_long overlap)
{
	t_atom_long count;
	t_llllelem *elem, *nextelem = NULL, *pivot, *temp;
    t_max_err err = MAX_ERR_NONE;
    if (overlap >= modulo) {
        overlap = modulo - 1;
        err = MAX_ERR_GENERIC;
    } else if (overlap < 0) {
        overlap = 0;
        err = MAX_ERR_GENERIC;
    }
	elem = ll->l_head;
	while (elem) {
		pivot = elem;
		for (elem = pivot, count = 1; elem && count < modulo; count++) {
			if ((nextelem = elem->l_next))
				elem = nextelem;
		}
		if (elem != ll->l_tail) {
			for (temp = elem, count = 0; temp && count < overlap; count++, temp = temp->l_prev)
				llll_inserthatom_after_clone(&temp->l_hatom, elem, 0, WHITENULL_llll);
		}
		nextelem = elem->l_next;
		llll_wrap_element_range(pivot, elem);
		elem = nextelem;
	}
	pedantic_llll_check(ll);
    return err;
}

/*
 ---DESTRUCTIVE
 as llll_groupllll, but accepts a llll of integers for grouping
 */
t_max_err llll_multigroupllll(t_llll *ll, t_llll *modulos, t_atom_long overlap, long circular_pad)
{
	t_atom_long count;
	t_llllelem *modulo_elem, *elem, *nextelem = NULL, *pivot, *temp;
    t_max_err err = MAX_ERR_NONE;
	if (modulos->l_size == 0) {
		return llll_groupllll(ll, 1, 0);
	}
    modulo_elem = modulos->l_head;
	if (modulos->l_size == 1) {
		t_atom_long modulo = hatom_getlong(&modulo_elem->l_hatom);
		if (modulo < 1)
			modulo = 1;
		return llll_groupllll(ll, modulo, overlap);
	}
	
	elem = ll->l_head;
	while (elem && modulo_elem) {
		t_atom_long this_modulo = hatom_is_number(&modulo_elem->l_hatom) ? hatom_getlong(&modulo_elem->l_hatom) : 1;
        t_atom_long this_overlap;
        if (overlap >= this_modulo) {
            this_overlap = this_modulo - 1;
            err |= MAX_ERR_GENERIC;
        } else if (overlap < 0) {
            this_overlap = 0;
            err |= MAX_ERR_GENERIC;
        } else {
            this_overlap = overlap;
        }
		pivot = elem;
		for (count = 1; elem && count < this_modulo; count++) {
			if ((nextelem = elem->l_next))
				elem = nextelem;
		}
		if (elem != ll->l_tail) {
			for (temp = elem, count = 0; temp && count < this_overlap; count++, temp = temp->l_prev)
				llll_inserthatom_after_clone(&temp->l_hatom, elem, 0, WHITENULL_llll);
		}
		nextelem = elem->l_next;
		llll_wrap_element_range(pivot, elem);
		elem = nextelem;
		
		modulo_elem = modulo_elem->l_next;
		if (!modulo_elem)
			modulo_elem = circular_pad == 0 ? modulos->l_tail : modulos->l_head;
	}
	pedantic_llll_check(ll);
    return err;
}

/////////////////////////////////////////////////////////
/*
 create an llll according to the rule:
 - the first element of the outllll is a sublist of H_OBJ, each pointing to an element at the first level of depth of the input llll
 - the second element is as above, but contains pointers to the second level of the input llll
 ... and so on.
 so, the length of the output level will be equal to the depth of the input llll
 
 BEWARE: the elements of the input llll still belong to it, and not to the output llll!
 */

t_llll *llll_scan(t_llll *in_llll, long sublists)
{
	t_llllelem *inelem = in_llll->l_head;
	t_llllelem *outelem;
	t_llll *outllll = llll_get();
	t_llll *cur_depth_llll;
	t_llll_stack *stack = llll_stack_new();
	
	cur_depth_llll = llll_get();
	outelem = llll_appendllll(outllll, cur_depth_llll, 0, WHITENULL_llll);

	
	while (1) {
		while (inelem) {
			if (inelem->l_hatom.h_type == H_LLLL) {
				if (sublists)
					llll_appendobj(cur_depth_llll, inelem, 0, WHITENULL_llll);
				llll_stack_push(stack, inelem->l_next);
				outelem = outelem->l_next;
				if (!outelem) {
					cur_depth_llll = llll_get();
					outelem = llll_appendllll(outllll, cur_depth_llll, 0, WHITENULL_llll);
				} else
					cur_depth_llll = outelem->l_hatom.h_w.w_llll;
				inelem = inelem->l_hatom.h_w.w_llll->l_head;
			} else {
				llll_appendobj(cur_depth_llll, inelem, 0, WHITENULL_llll);
				inelem = inelem->l_next;
			}
		}
		inelem = (t_llllelem *) llll_stack_pop(stack);
		outelem = outelem->l_prev;
		if (!outelem)
			break;
		cur_depth_llll = outelem->l_hatom.h_w.w_llll;
	}
	llll_stack_destroy(stack);
	
/*	
	{
		t_llllelem *elem;
		for (elem = outllll->l_head; elem; elem = elem->l_next) {
			t_llllelem *depthelem;
			for (depthelem = elem->l_hatom.h_w.w_llll->l_head; depthelem; depthelem = depthelem->l_next)
				llll_posthatom(&((t_llllelem *) depthelem->l_hatom.h_w.w_obj)->l_hatom);
			post("----");
		}
	}
 */
	pedantic_llll_check(outllll);
	return outllll;
}

t_atom_long hatom_to_text_buf(t_hatom *a, char **buf, t_atom_long offset, t_atom_long max_decimals, long flags, text_buf_fn fn)
{
    t_atom_long res;
    t_llll *ll = llll_get();
    llll_appendhatom(ll, a);
    ll->l_head->l_flags = OBJ_FLAG_DATA;
    res = llll_to_text_buf(ll, buf, offset, max_decimals, flags, fn);
    llll_free(ll);
    return res;
}


t_atom_long llll_to_text_buf(t_llll *ll, char **buf, t_atom_long offset, t_atom_long max_decimals, long flags, text_buf_fn fn, t_bool leave_final_space)
{
	t_atom_long ac = offset;
	t_llll *subll;
	t_llllelem *elem;
	t_llll_stack *stack;
	t_atom_long outsize;
	long leveltype = L_STANDARD;
	t_bool special_parentheses = (flags & LLLL_T_ONLY_STANDARD_PARENTHESES) == 0;
	t_atom_long len;
	char *new_buf, *pos = NULL, *txt = NULL;
	
	if (*buf == NULL) {
		outsize = 2 * TEXT_BUF_SIZE_STEP + offset;
		*buf = (char *) bach_newptr(outsize * sizeof (char));
	} else {
		outsize = sysmem_ptrsize(*buf);
	}
	if (!*buf)
		return 0;
	
	pos = *buf + offset;
	if (!ll) {
		*pos = 0;
		return ac;
	}
	
	if (ll->l_size == 0) {
		if (flags & LLLL_T_NULL) {
			strncpy_zero(pos, "null", TEXT_BUF_SIZE_STEP);
			return ac + 4;
		}
		else {
			*pos = 0;
			return ac;
		}
	}
	
	stack = llll_stack_new();
	elem = ll->l_head;
	//	max_decimals++;
	
	if (fn) {
		t_hatom h;
		hatom_setllll(&h, ll);
		txt = (fn)(&h, max_decimals);
		if (txt) {
			len = snprintf_zero(pos, 256, "%s : ", txt);
			bach_freeptr(txt);
			ac += len;
			pos += len;
		}
	}
	
	while (1) {
		while (elem) {
			if (outsize - ac < TEXT_BUF_SIZE_STEP) {
				outsize += TEXT_BUF_SIZE_STEP;
				new_buf = (char *) bach_resizeptr(*buf, outsize);
				if (!new_buf) {
					llll_stack_destroy(stack);
					return ac;
				} else {
					*buf = new_buf;
					pos = *buf + ac;
				}
			}
			
			if (fn) {
				txt = (fn)(&elem->l_hatom, max_decimals);
				if (txt) {
					len = snprintf_zero(pos, 256, "%s ", txt);
					bach_freeptr(txt);
					ac += len;
					pos += len;
				}	
			}
			
			if (!txt) {
				switch(elem->l_hatom.h_type) {
					case H_LONG:
						len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, ATOM_LONG_PRINTF_FMT " ", elem->l_hatom.h_w.w_long);
						ac += len;
						pos += len;
						break;		
					case H_DOUBLE:
                        len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, "%.*f", max_decimals, elem->l_hatom.h_w.w_double);
                        ac += len;
                        pos += len - 1;
                        
                        // remove trailing zeros
                        while (*pos == '0') {
                            pos--;
                            ac--;
                        }
                        *++pos = ' ';
                        *++pos = 0;
                        ac++;
						break;
					case H_RAT:
						len = snprintf_zero(pos, 256, ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT " ", elem->l_hatom.h_w.w_rat.r_num, elem->l_hatom.h_w.w_rat.r_den);
						ac += len;
						pos += len;
						break;
                    case H_PITCH:
                        len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, "%s ", elem->l_hatom.h_w.w_pitch.toString().c_str());
                        ac += len;
                        pos += len;
                        break;
					case H_SYM: 
						if (flags & LLLL_T_COPYSYMBOLS) {
							len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, "%s ", elem->l_hatom.h_w.w_sym->s_name);
							ac += len;
							pos += len;
						} else {
							t_atom_long symlen = 0;
							char *symname = elem->l_hatom.h_w.w_sym->s_name;
							char *symnamepos = symname;
							char *thispos = pos;
							char *contains_spaces = NULL;
                            if (flags & LLLL_T_FORCE_SINGLE_QUOTES) {
                                *thispos++ = '\'';
                                symlen++;
                            }
							if (!(flags & (LLLL_T_NO_DOUBLE_QUOTES))) {
								contains_spaces = strchr(symname, ' ');
								if (contains_spaces || (flags & (LLLL_T_FORCE_DOUBLE_QUOTES))) { // if it contains spaces or forced double quotes
									if (flags & (LLLL_T_BACKSLASH_BEFORE_DOUBLE_QUOTES)) {
										*thispos++ ='\\';
										symlen++;
									}
									*thispos++ = '"';
									symlen++;
								}
							}
							while (*symnamepos && symlen < TEXT_BUF_SIZE_STEP - 6) {
								switch (*symnamepos) {
									case ',':
									case ';':
										if (contains_spaces || (flags & LLLL_T_NO_BACKSLASH)) {
											*thispos++ = *symnamepos++;
											symlen ++;
										} else {
											*thispos++ = '\\';
											*thispos++ = *symnamepos++;
											symlen += 2;
										}
										break;
									case '"':
									case '\\':
										if (contains_spaces || (flags & LLLL_T_NO_BACKSLASH)) {
											*thispos++ = *symnamepos++;
											symlen ++;
										} else {
											*thispos++ = '\\';
											*thispos++ = *symnamepos++;
											symlen += 2;
										}
										break;
									default:
										*thispos++ = *symnamepos++;
										symlen ++;
										break;
								}
							}
							if (contains_spaces || (flags & (LLLL_T_FORCE_DOUBLE_QUOTES))) { // if it contains spaces or forced double quotes
								if (flags & (LLLL_T_BACKSLASH_BEFORE_DOUBLE_QUOTES)) {
									*thispos++ ='\\';
									symlen++;
								}
								*thispos++ = '"';
								symlen++;
							}
                            if (flags & LLLL_T_FORCE_SINGLE_QUOTES) {
                                *thispos++ = '\'';
                                symlen++;
                            }
							*thispos++ = ' ';
							*thispos = 0;
							symlen++;
							pos = thispos;
							ac += symlen;
						}
						break;
					case H_OBJ:
						len = snprintf_zero(pos, 256, "[object:%p] ", elem->l_hatom.h_w.w_obj);
						ac += len;
						pos += len;
						break;
					case H_NULL:
						strncpy_zero(pos, "null ", 5);
						pos += 5;
						ac += 5;
						break;
					case H_LLLL:
						break;
					default:
						strncpy_zero(pos, "###UNKNOWN### ", 14);
						pos += 13;
						ac += 13;
						break;
				}
			}
			
			if (elem->l_hatom.h_type == H_LLLL) {
				subll = elem->l_hatom.h_w.w_llll;
				leveltype = subll->l_leveltype;
				*pos++ = special_parentheses ? _open_parentheses[leveltype] : '(';
				*pos++ = ' ';
				*pos = 0;
				ac += 2;
				llll_stack_push(stack, elem);
				elem = subll->l_head;
			} else
				elem = elem->l_next;
		}
		
		
		if (!stack->s_items)
			break;
		*pos++ = special_parentheses ? _closed_parentheses[leveltype] : ')';
		*pos++ = ' ';
		*pos = 0;
		
		ac += 2;
		
		if (outsize - ac < TEXT_BUF_SIZE_STEP) {
			outsize += TEXT_BUF_SIZE_STEP;
			new_buf = (char *) bach_resizeptr(*buf, outsize);
			if (!new_buf) {
				llll_stack_destroy(stack);
				return ac;
			} else {
				*buf = new_buf;
				pos = *buf + ac;
			}
		}
		elem = (t_llllelem *) llll_stack_pop(stack);
		leveltype = elem->l_parent->l_leveltype;
		elem = elem->l_next;
	}
    if (!leave_final_space) {
        ac--;
        *(pos - 1) = 0;
    }
	llll_stack_destroy(stack);
	return ac;
}



#define __use_llll_to_text_buf_pretty

#ifdef __use_llll_to_text_buf_pretty

void manage_indent(char **pos, t_atom_long *linesize, t_atom_long *count, t_atom_long depth, const char *indent)
{
    t_atom_long i;
    
    if (indent) {
        for (i = 0; i < depth - 1; i++) {
            int len = snprintf_zero(*pos, 256, indent);
            *pos += len;
            *count += len;
        }
        *linesize = 0;
    }
    
/*
    
    t_atom_long actual_indent = (depth - 1) * indent;
    for (i = 0; i < actual_indent; i++)
        *((*pos)++) = ' ';
    *count += actual_indent;
 */
}


void manage_wrap_and_indent(int len, char **pos, t_atom_long *linesize, t_atom_long *count,
                            t_atom_long depth, t_atom_long wrap, const char *indent, t_bool indent_anyway)
{
    if ((wrap > 0 && *linesize + len > wrap) || indent_anyway) { // that is, if we reached the maximum line size, or if we just closed a sublist
        *(*pos - 1) = '\n';
        manage_indent(pos, linesize, count, depth, indent);
    }
}



t_atom_long llll_to_text_buf_pretty(t_llll *ll, char **buf, t_atom_long offset, t_atom_long max_decimals,
                                      t_atom_long wrap, const char *indent, t_atom_long maxdepth, long flags, text_buf_fn fn)
{
    t_atom_long count = offset;
    t_llll *subll;
    t_llllelem *elem;
    t_llll_stack *stack;
    t_atom_long outsize;
    long leveltype = L_STANDARD;
    t_bool special_parentheses = (flags & LLLL_T_ONLY_STANDARD_PARENTHESES) == 0;
    t_atom_long len;
    t_atom_long linesize = 0;
    t_atom_long indent_depth = 1;
    t_bool just_closed_indented_sublist = false;
    char *new_buf, *pos = NULL;
    
    if (*buf == NULL) {
        outsize = 2 * TEXT_BUF_SIZE_STEP + offset;
        *buf = (char *) bach_newptr(outsize * sizeof (char));
    } else {
        outsize = sysmem_ptrsize(*buf);
    }
    if (!*buf)
        return 0;
    
    pos = *buf + offset;
    if (!ll) {
        *pos = 0;
        return count;
    }
    
    if (ll->l_size == 0) {
        if (flags & LLLL_T_NULL) {
            strncpy_zero(pos, "null", TEXT_BUF_SIZE_STEP);
            return count + 4;
        }
        else {
            *pos = 0;
            return count;
        }
    }
    
    stack = llll_stack_new();
    elem = ll->l_head;
    //	max_decimals++;
    
    if (fn) {
        t_hatom h;
        hatom_setllll(&h, ll);
        char *txt = NULL;
        txt = (fn)(&h, max_decimals);
        if (txt) {
            len = snprintf_zero(pos, 256, "%s : ", txt);
            bach_freeptr(txt);
            count += len;
            pos += len;
            linesize += len;
        }
    }
    
    while (1) {
        while (elem) {
            if (outsize - count < TEXT_BUF_SIZE_STEP) {
                outsize += TEXT_BUF_SIZE_STEP;
                new_buf = (char *) bach_resizeptr(*buf, outsize);
                if (!new_buf) {
                    llll_stack_destroy(stack);
                    return count;
                } else {
                    *buf = new_buf;
                    pos = *buf + count;
                }
            }
            
            t_bool processed = false;
            if (fn) {
                char *txt = NULL;
                txt = (fn)(&elem->l_hatom, max_decimals);
                if (txt) {
                    if (wrap > 0 && pos > *buf + offset) {
                        int len = strlen(txt);
                        manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                        just_closed_indented_sublist = false;
                    }
                    len = snprintf_zero(pos, 256, "%s ", txt);
                    bach_freeptr(txt);
                    count += len;
                    pos += len;
                    linesize += len;
                    processed = true;
                    elem = elem->l_next;
                }
            }
            
            if (!processed) {
                switch(elem->l_hatom.h_type) {
                    case H_LONG:
                        if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                            char txt[256];
                            len = snprintf_zero(txt, 256, ATOM_LONG_PRINTF_FMT, elem->l_hatom.h_w.w_long);
                            manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                            just_closed_indented_sublist = false;
                            len = snprintf_zero(pos, 256, "%s ", txt);
                        } else {
                            len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, ATOM_LONG_PRINTF_FMT " ", elem->l_hatom.h_w.w_long);
                        }
                        count += len;
                        pos += len;
                        linesize += len;
                        elem = elem->l_next;
                        break;
                    case H_DOUBLE:
                        if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                            char txt[256], *this_txt;
                            len = snprintf_zero(txt, 256, "%.*f", max_decimals, elem->l_hatom.h_w.w_double);
                            
                            // remove trailing zeros
                            this_txt = txt + len;
                            while (*this_txt == '0') {
                                this_txt--;
                                len--;
                            }
                            *(this_txt + 1) = '0';
                            manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                            just_closed_indented_sublist = false;
                            len = snprintf_zero(pos, 256, "%s ", txt);
                            count += len;
                            linesize += len;
                            pos += len;
                        } else {
                            len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, "%.*f", max_decimals, elem->l_hatom.h_w.w_double);
                            count += len;
                            pos += len - 1;
                            linesize += len;
                            // remove trailing zeros
                            while (*pos == '0') {
                                --pos;
                                --count;
                                --linesize;
                            }
                            *++pos = ' ';
                            ++linesize;
                            *++pos = 0;
                            count++;
                        }
                        elem = elem->l_next;
                        break;
                    case H_RAT:
                        if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                            char txt[256];
                            len = snprintf_zero(txt, 256, ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT, elem->l_hatom.h_w.w_rat.r_num, elem->l_hatom.h_w.w_rat.r_den);
                            manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                            just_closed_indented_sublist = false;
                            len = snprintf_zero(pos, 256, "%s ", txt);
                        } else {
                            len = snprintf_zero(pos, 256, ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT " ", elem->l_hatom.h_w.w_rat.r_num, elem->l_hatom.h_w.w_rat.r_den);
                        }
                        count += len;
                        pos += len;
                        linesize += len;
                        elem = elem->l_next;
                        break;
                    case H_PITCH:
                        if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                            char txt[256];
                            len = snprintf_zero(txt, TEXT_BUF_SIZE_STEP - 2, "%s ", elem->l_hatom.h_w.w_pitch.toString().c_str());
                            manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                            just_closed_indented_sublist = false;
                            len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, "%s ", txt);
                        } else {
                            len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, "%s ", elem->l_hatom.h_w.w_pitch.toString().c_str());
                        }
                        count += len;
                        pos += len;
                        linesize += len;
                        elem = elem->l_next;
                        break;
                    case H_SYM:
                        if (flags & LLLL_T_COPYSYMBOLS) {
                            if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                                char *txt = elem->l_hatom.h_w.w_sym->s_name;
                                len = strlen(txt);
                                manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                                just_closed_indented_sublist = false;
                                len = snprintf_zero(pos, 256, "%s ", txt);
                            } else {
                                len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP - 2, "%s ", elem->l_hatom.h_w.w_sym->s_name);
                            }
                            count += len;
                            pos += len;
                            linesize += len;
                        } else {
                            t_atom_long len = 0;
                            char *symname = elem->l_hatom.h_w.w_sym->s_name;
                            char *symnamepos = symname;
                            long txtlen = strlen(symname) * 2;
                            char *this_txt, *txt;
                            txt = (char *) bach_newptr(txtlen);
                            
                            if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                                this_txt = txt;
                            } else {
                                this_txt = pos;
                            }
                            
                            //char *thispos = pos;
                            char *contains_spaces = NULL;
                            if (flags & LLLL_T_FORCE_SINGLE_QUOTES) {
                                *this_txt++ = '\'';
                                len++;
                            }
                            if (!(flags & (LLLL_T_NO_DOUBLE_QUOTES))) {
                                contains_spaces = strchr(symname, ' ');
                                if (contains_spaces || (flags & (LLLL_T_FORCE_DOUBLE_QUOTES))) { // if it contains spaces or forced double quotes
                                    if (flags & (LLLL_T_BACKSLASH_BEFORE_DOUBLE_QUOTES)) {
                                        *this_txt++ ='\\';
                                        len++;
                                    }
                                    *this_txt++ = '"';
                                    len++;
                                }
                            }
                            while (*symnamepos && len < TEXT_BUF_SIZE_STEP - 6) {
                                switch (*symnamepos) {
                                    case ',':
                                    case ';':
                                        if (contains_spaces || (flags & LLLL_T_NO_BACKSLASH)) {
                                            *this_txt++ = *symnamepos++;
                                            len ++;
                                        } else {
                                            *this_txt++ = '\\';
                                            *this_txt++ = *symnamepos++;
                                            len += 2;
                                        }
                                        break;
                                    case '"':
                                    case '\\':
                                        if (contains_spaces || (flags & LLLL_T_NO_BACKSLASH)) {
                                            *this_txt++ = *symnamepos++;
                                            len ++;
                                        } else {
                                            *this_txt++ = '\\';
                                            *this_txt++ = *symnamepos++;
                                            len += 2;
                                        }
                                        break;
                                    default:
                                        *this_txt++ = *symnamepos++;
                                        len ++;
                                        break;
                                }
                            }
                            if (contains_spaces || (flags & (LLLL_T_FORCE_DOUBLE_QUOTES))) { // if it contains spaces or forced double quotes
                                if (flags & (LLLL_T_BACKSLASH_BEFORE_DOUBLE_QUOTES)) {
                                    *this_txt++ ='\\';
                                    len++;
                                }
                                *this_txt++ = '"';
                                len++;
                            }
                            if (flags & LLLL_T_FORCE_SINGLE_QUOTES) {
                                *this_txt++ = '\'';
                                len++;
                            }
                            
                            if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                                manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                                just_closed_indented_sublist = false;
                                *this_txt = 0;
                                if (outsize - count - (this_txt - txt) < TEXT_BUF_SIZE_STEP) {
                                    outsize += (this_txt - txt) + TEXT_BUF_SIZE_STEP;
                                    new_buf = (char *) bach_resizeptr(*buf, outsize);
                                    if (!new_buf) {
                                        bach_freeptr(txt);
                                        llll_stack_destroy(stack);
                                        return count;
                                    } else {
                                        *buf = new_buf;
                                        pos = *buf + count;
                                    }
                                }
                                len = snprintf_zero(pos, TEXT_BUF_SIZE_STEP, "%s ", txt);
                                count += len;
                                pos += len;
                                linesize += len;
                                bach_freeptr(txt);
                            } else {
                                *this_txt++ = ' ';
                                //*this_txt = 0; // we don't really need this
                                len++;
                                pos = this_txt;
                                count += len;
                                linesize += len;
                            }
                        }
                        elem = elem->l_next;
                        break;
                    case H_OBJ:
                        if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                            char txt[256];
                            len = snprintf_zero(txt, 256, "[object:%p]", elem->l_hatom.h_w.w_obj);
                            manage_wrap_and_indent(len, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                            just_closed_indented_sublist = false;
                            len = snprintf_zero(pos, 256, "%s ", txt);
                        } else {
                            len = snprintf_zero(pos, 256, "[object:%p] ", elem->l_hatom.h_w.w_obj);
                        }
                        count += len;
                        pos += len;
                        linesize += len;
                        elem = elem->l_next;
                        break;
                    case H_LLLL:
                        subll = elem->l_hatom.h_w.w_llll;
                        if (indent) {
                            if (indent_depth <= maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth)) { // if we are within maxdepth
                                ++indent_depth;
                                if (pos > *buf + offset)
                                    *(pos - 1) = '\n';
                                manage_indent(&pos, &linesize, &count, indent_depth, indent);
                            }
                            just_closed_indented_sublist = false;
                        }
                        leveltype = subll->l_leveltype;
                        *pos++ = special_parentheses ? _open_parentheses[leveltype] : '(';
                        *pos++ = ' ';
                        //*pos = 0; // we don't really need this
                        count += 2;
                        linesize += 2;
                        llll_stack_push(stack, elem);
                        elem = subll->l_head;
                        break;
                    case H_NULL:
                        if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                            manage_wrap_and_indent(4, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                            just_closed_indented_sublist = false;
                        }
                        strncpy_zero(pos, "null ", 5);
                        pos += 5;
                        count += 5;
                        linesize += 5;
                        elem = elem->l_next;
                        break;
                    default:
                        if ((wrap > 0 || just_closed_indented_sublist) && pos > *buf + offset) {
                            manage_wrap_and_indent(13, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                            just_closed_indented_sublist = false;
                        }
                        strncpy_zero(pos, "###UNKNOWN### ", 15);
                        pos += 14;
                        count += 14;
                        linesize += 14;
                        elem = elem->l_next;
                        break;
                }
            }

        }
        
        
        if (!stack->s_items)
            break;
        if (indent) {
            if (indent_depth <= maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth)) { // if we are within maxdepth
                manage_wrap_and_indent(1, &pos, &linesize, &count, indent_depth, wrap, indent, just_closed_indented_sublist);
                --indent_depth;
                *pos++ = special_parentheses ? _closed_parentheses[leveltype] : ')';
                *pos++ = '\n';
                just_closed_indented_sublist = true;
            } else {
                *pos++ = special_parentheses ? _closed_parentheses[leveltype] : ')';
                *pos++ = ' ';
                //just_closed_indented_sublist = false;
            }
        } else {
            *pos++ = special_parentheses ? _closed_parentheses[leveltype] : ')';
            *pos++ = ' ';
        }
        //*pos = 0; // we don't really need this
        count += 2;
        linesize = 0;
        
        if (outsize - count < TEXT_BUF_SIZE_STEP) {
            outsize += TEXT_BUF_SIZE_STEP;
            new_buf = (char *) bach_resizeptr(*buf, outsize);
            if (!new_buf) {
                llll_stack_destroy(stack);
                return count;
            } else {
                *buf = new_buf;
                pos = *buf + count;
            }
        }
        elem = (t_llllelem *) llll_stack_pop(stack);
        subll = elem->l_parent;
        leveltype = subll->l_leveltype;
        elem = elem->l_next;
        //if (!elem && (depth <= maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth)))
          //  manage_indent(&pos, &linesize, &count, depth, indent);
    }
    count--;
    *(pos - 1) = 0;
    llll_stack_destroy(stack);
    return count;
}

#endif // __use_llll_to_text_buf_pretty


t_atom_long llll_to_text_buf_limited(t_llll *ll, char **buf, long max_size, t_atom_long offset, t_atom_long max_decimals, long flags, text_buf_fn fn)
{
	t_atom_long ac = offset;
	t_llll *subll;
	t_llllelem *elem;
	t_llll_stack *stack;
	long leveltype = L_STANDARD;
	t_bool special_parentheses = (flags & LLLL_T_ONLY_STANDARD_PARENTHESES) == 0;
	t_atom_long len;
	char *pos = NULL, *txt = NULL;
	
	if (*buf == NULL) {
		*buf = (char *) bach_newptr(max_size * sizeof(char));

	}
	if (!*buf)
		return 0;
	
	pos = *buf + offset;
	max_size -= offset;
	if (!ll) {
		*pos = 0;
		return ac;
	}
	
	if (ll->l_size == 0) {
		if (flags & LLLL_T_NULL) {
			len = snprintf_zero(pos, max_size, "null", txt);
			return len;
		}
		else {
			*pos = 0;
			return ac;
		}
	}
	
	stack = llll_stack_new();
	elem = ll->l_head;
	//	max_decimals++;
	
	if (fn) {
		t_hatom h;
		hatom_setllll(&h, ll);
		txt = (fn)(&h, max_decimals);
		if (txt) {
			len = snprintf_zero(pos, max_size, "%s : ", txt);
			bach_freeptr(txt);
			ac += len;
			pos += len;
			max_size -= len;
		}
	}
	
	while (1) {
		while (elem && max_size > 0) {
			if (fn) {
				txt = (fn)(&elem->l_hatom, max_decimals);
				if (txt) {
					len = snprintf_zero(pos, max_size, "%s ", txt);
					bach_freeptr(txt);
					ac += len;
					pos += len;
					max_size -= len;
				}
			}
			
			if (!txt) {
				switch(elem->l_hatom.h_type) {
					case H_LONG:
						len = snprintf_zero(pos, max_size, ATOM_LONG_PRINTF_FMT " ", elem->l_hatom.h_w.w_long);
						ac += len;
						pos += len;
						max_size -= len;
						break;
					case H_DOUBLE:
                        len = snprintf_zero(pos, max_size, "%.*f", max_decimals, elem->l_hatom.h_w.w_double);
                        ac += len;
                        pos += len - 1;
                        max_size -= len;
                        // remove trailing zeros
                        while (*pos == '0') {
                            pos--;
                            ac--;
                            max_size++;
                        }
                        pos++;
                        len = snprintf_zero(pos, max_size, " ");
                        pos += len;
                        ac += len;
                        max_size -= len;
						break;
					case H_RAT:
						len = snprintf_zero(pos, max_size, ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT " ", elem->l_hatom.h_w.w_rat.r_num, elem->l_hatom.h_w.w_rat.r_den);
						ac += len;
						pos += len;
						max_size -= len;
						break;
					case H_SYM:
						if (flags & LLLL_T_COPYSYMBOLS) {
							len = snprintf_zero(pos, max_size, "%s ", elem->l_hatom.h_w.w_sym->s_name);
							ac += len;
							pos += len;
						} else {
							t_atom_long symlen = 0;
							char *symname = elem->l_hatom.h_w.w_sym->s_name;
							char *symnamepos = symname;
							char *contains_spaces = NULL;
                            
                            if (flags & LLLL_T_FORCE_SINGLE_QUOTES) {
                                *pos++ = '\'';
                                symlen++;
                                max_size--;
                            }
							if (!(flags & (LLLL_T_NO_DOUBLE_QUOTES)) && max_size > 2) {
								contains_spaces = strchr(symname, ' ');
								if (contains_spaces || (flags & (LLLL_T_FORCE_DOUBLE_QUOTES))) { // if it contains spaces or forced double quotes
									if (flags & (LLLL_T_BACKSLASH_BEFORE_DOUBLE_QUOTES)) {
										*pos++ ='\\';
										symlen++;
										max_size--;
									}
									*pos++ = '"';
									symlen++;
									max_size--;
								}
							}
							while (*symnamepos && symlen < max_size - 6) {
								switch (*symnamepos) {
									case ',':
									case ';':
										if (contains_spaces || (flags & LLLL_T_NO_BACKSLASH)) {
											*pos++ = *symnamepos++;
											symlen ++;
										} else {
											*pos++ = '\\';
											*pos++ = *symnamepos++;
											symlen += 2;
										}
										break;
									case '"':
									case '\\':
										if (contains_spaces || (flags & LLLL_T_NO_BACKSLASH)) {
											*pos++ = *symnamepos++;
											symlen ++;
										} else {
											*pos++ = '\\';
											*pos++ = *symnamepos++;
											symlen += 2;
										}
										break;
									default:
										*pos++ = *symnamepos++;
										symlen ++;
										break;
								}
							}
							if (contains_spaces || (flags & (LLLL_T_FORCE_DOUBLE_QUOTES))) { // if it contains spaces or forced double quotes
								if (flags & (LLLL_T_BACKSLASH_BEFORE_DOUBLE_QUOTES)) {
									*pos++ ='\\';
									symlen++;
								}
								*pos++ = '"';
								symlen++;
							}
                            if (flags & LLLL_T_FORCE_SINGLE_QUOTES) {
                                *pos++ = '\'';
                                symlen++;
                                max_size--;
                            }
							*pos++ = ' ';
							*pos = 0;
							symlen++;
							ac += symlen;
							max_size -= symlen;
						}
						break;
					case H_OBJ:
						len = snprintf_zero(pos, max_size, "[object:%p] ", elem->l_hatom.h_w.w_obj);
						ac += len;
						pos += len;
						max_size -= len;
						break;
					case H_NULL:
						len = snprintf_zero(pos, max_size, "null ");
						pos += len;
						ac += len;
						max_size -= len;
						break;
					case H_LLLL:
						break;
					default:
						len = snprintf_zero(pos, max_size, "###UNKNOWN### ");
						pos += len;
						ac += len;
						max_size -= len;
						break;
				}
			}
			
			if (elem->l_hatom.h_type == H_LLLL) {
				subll = elem->l_hatom.h_w.w_llll;
				leveltype = subll->l_leveltype;
				if (max_size > 2) {
					*pos++ = special_parentheses ? _open_parentheses[leveltype] : '(';
					*pos++ = ' ';
					*pos = 0;
					ac += 2;
					max_size -= 2;
				}
				llll_stack_push(stack, elem);
				elem = subll->l_head;
			} else
				elem = elem->l_next;
		}
		
		
		if (!stack->s_items)
			break;
		if (max_size > 2) {
			*pos++ = special_parentheses ? _closed_parentheses[leveltype] : ')';
			*pos++ = ' ';
			*pos = 0;
			ac += 2;
			max_size -= 2;
		}

		elem = (t_llllelem *) llll_stack_pop(stack);
		leveltype = elem->l_parent->l_leveltype;
		elem = elem->l_next;
	}
	if (*pos == ' ') {
		ac--;
		*(pos - 1) = 0;
	}
	llll_stack_destroy(stack);
	return ac;
}



// write a llll into a native buffer
// native buffer is a proprietary binary format used for saving a llll into a file
// don't call this function yourself
// if you need to save a llll, use the llll_files high-level API instead
t_atom_long llll_to_native_buf(t_llll *ll, char **buf)
{
	t_llll_stack *stack;
	t_llllelem *elem;
	e_hatom_types type;
	t_hatom *hatom;
	t_atom_long symsize;
	t_atom_long size = LLLL_BUF_SIZE_STEP;
	char *thisbuf;
	t_atom_long ac;
	
	if (!ll || !buf)
		return 0;
	
	thisbuf = *buf = (char *) bach_newptr(size);
	stack = llll_stack_new();

	strcpy(thisbuf, "\nbach");
	ac = 6;
	thisbuf += 6;

	elem = ll->l_head;
	while (1) {
		while (elem) {
			if (ac > size - 512) {
				size += LLLL_BUF_SIZE_STEP;
				*buf = (char *) bach_resizeptr(*buf, size);
				thisbuf = *buf + ac;
			}
			hatom = &elem->l_hatom;
			type = (e_hatom_types) hatom->h_type;
			bach_copyptr(&type, thisbuf, sizeof(e_hatom_types));
			thisbuf += sizeof(e_hatom_types);
			ac += sizeof(e_hatom_types);
			switch (type) {
				case H_SYM:
					symsize = strlen(hatom->h_w.w_sym->s_name) + 1;
					bach_copyptr(hatom->h_w.w_sym->s_name, thisbuf, symsize);
					thisbuf += symsize;
					ac += symsize;
					elem = elem->l_next;
					break;
				case H_LLLL:
					llll_stack_push(stack, elem->l_next);
					ll = hatom->h_w.w_llll;
					elem = ll->l_head;
					break;
				default:
					bach_copyptr(&hatom->h_w, thisbuf, sizeof(t_hword));
					thisbuf += sizeof(t_hword);
					ac += sizeof(t_hword);
					elem = elem->l_next;
					break;
			}
		}
		if (!stack->s_items)
			break;
		type = H_POP;
		bach_copyptr(&type, thisbuf, sizeof(e_hatom_types));
		thisbuf += sizeof(e_hatom_types);
		ac += sizeof(e_hatom_types);	
		if (!stack->s_items)
			break;
		elem = (t_llllelem *) llll_stack_pop(stack);
	}
	llll_stack_destroy(stack);
	type = H_NOTHING;
	bach_copyptr(&type, thisbuf, sizeof(e_hatom_types));
	ac += sizeof(e_hatom_types);	
	return ac;
}

// retrieve a list from a native buffer
// native buffer is a proprietary binary format used for saving a llll into a file
// don't call this function yourself
// if you want need to save a llll, use the llll_files high-level API instead
t_llll *llll_from_native_buf(char *buf, t_atom_long ac)
{
    const int sizeof_e_hatom_types_old = 1; /// TODO: check that it is true!!!
	t_atom_long pos, symsize;
	t_llll *rootll;
	t_llll *ll;
	t_llll *subll;
	e_hatom_types type;
	t_hatom hatom;
	t_atom_long lvl = 0; // just for checking
	
	if (!buf)
		return NULL;
	ll = rootll = llll_get();
	

	buf += 6;
	pos = 6;
	
	for ( ; pos < ac; ) {
		type = *((e_hatom_types *) buf);
		buf += sizeof_e_hatom_types_old;
		pos += sizeof_e_hatom_types_old;
		switch (type) {
			case H_NOTHING:
				goto file_end;
				break;
			case H_SYM:
				llll_appendsym(ll, gensym(buf), 0, WHITENULL_llll);
				symsize = strlen(buf) + 1;
				pos += symsize;
				buf += symsize;
				break;
			case H_LLLL:
				lvl++;
				subll = llll_get();
				llll_appendllll(ll, subll, 0, WHITENULL_llll);
				ll = subll;
				break;
			case H_POP:
				lvl--;
				if (lvl < 0) {
					llll_free(ll);
					return NULL;
				}
				ll = ll->l_owner->l_parent;
				break;
			case H_LONG:
				llll_appendlong(ll, *(t_int32 *) buf, 0, WHITENULL_llll);
				buf += sizeof(t_hword);
				pos += sizeof(t_hword);
				break;
			case H_RAT:
				t_int32 n, d;
				n = *(t_int32 *) buf;
				buf += 4;
				d = *(t_int32 *) buf;
				buf += 4;
				llll_appendrat_from_elems(ll, n, d, 0, WHITENULL_llll);
				pos += sizeof(t_hword);
			case H_DOUBLE:
				llll_appenddouble(ll, *(double *) buf, 0, WHITENULL_llll);
				buf += sizeof(t_hword);
				pos += sizeof(t_hword);
				break;
			default: // should never happen!!!
				error("unknown atom type in native buffer");
				hatom.h_type = type;
				*((t_int64 *) &hatom.h_w) = *((t_int64 *) buf);
				llll_appendhatom(ll, &hatom, 0, WHITENULL_llll);
				buf += sizeof(t_hword);
				pos += sizeof(t_hword);
				break;
		}
	}
file_end:
	if (lvl) {
		llll_free(rootll);
		return NULL;
	} 
	return ll;
}

t_max_err llll_store_in_dictionary(t_llll *ll, t_dictionary *dict, const char *header, t_bach_atomic_lock *lock)
{
	char *entryname = (char *) bach_newptr(strlen(header) + 16);
	t_atom *av = NULL, *this_av, countatom;
	t_atom_long ac, count = 0, block_size;
	
	if (lock)
		bach_atomic_lock(lock);
	ac = llll_deparse(ll, &av, 0, LLLL_D_QUOTE | LLLL_D_FLOAT64);
	if (lock)
		bach_atomic_unlock(lock);
	this_av = av;
	
	while (ac > 0) {
		block_size = ac > 4096 ? 4096 : ac;
		sprintf(entryname, "%s_%010" ATOM_LONG_FMT_MODIFIER "d", header, count++);
		dictionary_appendatoms(dict, gensym(entryname), block_size, this_av);
		this_av += block_size;
		ac -= block_size;
	}
	sprintf(entryname, "%s_count", header);
	atom_setlong(&countatom, count);
	dictionary_appendatoms(dict, gensym(entryname), 1, &countatom);
	bach_freeptr(av);
	bach_freeptr(entryname);
	return MAX_ERR_NONE;
}

t_llll *llll_retrieve_from_dictionary(t_dictionary *dict, const char *header)
{
	char *entryname = (char *) bach_newptr(strlen(header) + 16);
	long ac = 0, whole_ac = 0, count, i;
	t_atom *av = NULL, *whole_av, *this_whole_av;
	t_llll *outlist;
	t_max_err err;
	sprintf(entryname, "%s_count", header);
	err = dictionary_getatoms(dict, gensym(entryname), &ac, &av);
	if (err || ac != 1) {
		bach_freeptr(entryname);
		return NULL;
	}
	count = atom_getlong(av);
	this_whole_av = whole_av = (t_atom *) bach_newptr(count * 4096 * sizeof(t_atom));
	for (i = 0; i < count; i++) {
		sprintf(entryname, "%s_%010ld", header, i);
		dictionary_getatoms(dict, gensym(entryname), &ac, &av);
		sysmem_copyptr(av, this_whole_av, ac * sizeof(t_atom));
		whole_ac += ac;
		this_whole_av += ac;
	}
	outlist = llll_parse(whole_ac, whole_av);
	bach_freeptr(whole_av);
	bach_freeptr(entryname);
	return outlist;
}

t_llll *llll_retrieve_from_dictionary_with_leveltypes(t_dictionary *dict, const char *header)
{
	char *entryname = (char *) bach_newptr(strlen(header) + 16);
	long ac = 0, whole_ac = 0, count, i;
	t_atom *av = NULL, *whole_av, *this_whole_av;
	t_llll *outlist;
	t_max_err err;
	sprintf(entryname, "%s_count", header);
	err = dictionary_getatoms(dict, gensym(entryname), &ac, &av);
	if (err || ac != 1) {
		bach_freeptr(entryname);
		return NULL;
	}
	count = atom_getlong(av);
	this_whole_av = whole_av = (t_atom *) bach_newptr(count * 4096 * sizeof(t_atom));
	for (i = 0; i < count; i++) {
		sprintf(entryname, "%s_%010ld", header, i);
		dictionary_getatoms(dict, gensym(entryname), &ac, &av);
		sysmem_copyptr(av, this_whole_av, ac * sizeof(t_atom));
		whole_ac += ac;
		this_whole_av += ac;
	}
	outlist = llll_parse_with_leveltypes(whole_ac, whole_av);
	bach_freeptr(whole_av);
	bach_freeptr(entryname);
	return outlist;
}

t_parseargs_item *parseargs_item_new(e_parseargs_types type, void *ptr)
{
	t_parseargs_item *x = (t_parseargs_item *) bach_newptr_named(sizeof(t_parseargs_item), gensym("parseargs_item"));
	x->p_type = type;
	x->p_ptr.p_void = ptr;
	return x;
}

// example:
// llll_parseargs(my_object, my_args_ll, "idl", gensym("my_int_key"), &my_long, gensym("my_double_key"), &my_double, gensym("my_llll_key"), &my_llll_ptr);
// lllls are cloned, and if there was a default llll it is freed
// NON DESTRUCTIVE
long llll_parseargs(t_object *x, t_llll *ll, const char *types, ...)
{
    va_list ap;
    
    // key is the name, value is a hatom
    t_hashtab *vars_ht = hashtab_new_debug(0);
    t_atom_long ac;
    const char *this_types;
    t_symbol *key;
    t_parseargs_item *item;
    t_llllelem *elem;
    long err = 0;
    t_atom_long pos;
    
    hashtab_flags(vars_ht, OBJ_FLAG_MEMORY);
    ac = strlen(types);
    
    va_start(ap, types);
    for (this_types = types; *this_types; this_types++) {
        item = NULL;
        key = va_arg(ap, t_symbol*);
        switch (*this_types) {
            case 'i':
                item = parseargs_item_new(P_LONG, va_arg(ap, t_atom_long*));
                break;
            case 'd':
                item = parseargs_item_new(P_DOUBLE, va_arg(ap, double*));
                break;
            case 's':
                item = parseargs_item_new(P_SYM, va_arg(ap, t_symbol**));
                break;
            case 'r':
                item = parseargs_item_new(P_RAT, va_arg(ap, t_rational*));
                break;
            case 'p':
                item = parseargs_item_new(P_PITCH, va_arg(ap, t_rational*));
                break;
            case 'l':
                item = parseargs_item_new(P_LLLL, va_arg(ap, t_llll**));
                break;
            case 'h':
                item = parseargs_item_new(P_HATOM, va_arg(ap, t_hatom*));
                break;
            default:
                object_bug((t_object *) x, "llll_parseargs: bad types: %s", types);
                err = 1;
                goto llll_parseargs_error;
                break;
        }
        hashtab_store(vars_ht, key, (t_object *) item);
    }
    va_end(ap);
    
    for (elem = ll->l_head, pos = 1; elem; elem = elem->l_next, pos++) {
        t_llll *arg_ll = hatom_getllll(&elem->l_hatom);
        t_max_err ht_err;
        t_llll **item_ll;
        if (!arg_ll) {
            if (x)
                object_warn(x, "Bad argument value at position " ATOM_LONG_PRINTF_FMT, pos);
            continue;
        }
        key = hatom_getsym(&arg_ll->l_head->l_hatom);
        ht_err = hashtab_lookup(vars_ht, key, (t_object **) &item);
        if (hatom_gettype(&arg_ll->l_head->l_hatom) != H_SYM || (item && item->p_type != P_LLLL && arg_ll->l_size < 2)) {
            if (x)
                object_warn(x, "Bad argument at position " ATOM_LONG_PRINTF_FMT, pos);
            continue;
        }
        if (ht_err) {
            //object_warn(x, "unknown argument %s at position %ld", key, pos);
            continue;
        }
        switch (item->p_type) {
            case P_LONG:
                if (hatom_gettype(&arg_ll->l_tail->l_hatom) == H_SYM) {
                    t_symbol *s = hatom_getsym(&arg_ll->l_tail->l_hatom);
                    long outlen = 0;
                    unsigned short *s_unicode = charset_utf8tounicode_debug(s->s_name, &outlen);
                    *(item->p_ptr.p_long) = outlen > 0 ? s_unicode[0] : 0;
                    bach_freeptr(s_unicode);
                } else
                    *(item->p_ptr.p_long) = hatom_getlong(&arg_ll->l_tail->l_hatom);
                break;
            case P_DOUBLE:
                *(item->p_ptr.p_double) = hatom_getdouble(&arg_ll->l_tail->l_hatom);
                break;
            case P_SYM:
                *(item->p_ptr.p_symbol) = hatom_getsym(&arg_ll->l_tail->l_hatom);
                break;
            case P_RAT:
                *(item->p_ptr.p_rat) = hatom_getrational(&arg_ll->l_tail->l_hatom);
                break;
            case P_PITCH:
                *(item->p_ptr.p_pitch) = hatom_getpitch(&arg_ll->l_tail->l_hatom);
                break;
            case P_HATOM:
                *(item->p_ptr.p_hatom) = arg_ll->l_tail->l_hatom;
                break;
            case P_LLLL:
                item_ll = item->p_ptr.p_llll;
                if (*item_ll)
                    llll_free(*item_ll);
                *item_ll = llll_clone(arg_ll);
                llll_destroyelem((*item_ll)->l_head);
                break;
        }
    }
llll_parseargs_error:
    object_free_debug((t_object *) vars_ht);
    return err;
}


/// Same as llll_parseargs, but using the attribute-like syntax: @attrname attrvalue
// IMPORTANT: if destructive is non-zero the function is destructive: the incoming ll will have all @stuff removed.
long llll_parseattrs(t_object *x, t_llll *ll, char destructive, const char *types, ...)
{
    va_list ap;
    
    // key is the name, value is a hatom
    t_hashtab *vars_ht = hashtab_new_debug(0);
    t_atom_long ac;
    const char *this_types;
    t_symbol *key;
    t_parseargs_item *item;
    t_llllelem *elem;
    long err = 0;
    
    t_symbol *s, *s2;
    t_llllelem *endelem, *temp_el, *next_temp_el, *nextelem = NULL;

    
    hashtab_flags(vars_ht, OBJ_FLAG_MEMORY);
    ac = strlen(types);
    
    va_start(ap, types);
    for (this_types = types; *this_types; this_types++) {
        item = NULL;
        key = va_arg(ap, t_symbol*);
        switch (*this_types) {
            case 'i':
                item = parseargs_item_new(P_LONG, va_arg(ap, t_atom_long*));
                break;
            case 'd':
                item = parseargs_item_new(P_DOUBLE, va_arg(ap, double*));
                break;
            case 's':
                item = parseargs_item_new(P_SYM, va_arg(ap, t_symbol**));
                break;
            case 'r':
                item = parseargs_item_new(P_RAT, va_arg(ap, t_rational*));
                break;
            case 'p':
                item = parseargs_item_new(P_PITCH, va_arg(ap, t_rational*));
                break;
            case 'l':
                item = parseargs_item_new(P_LLLL, va_arg(ap, t_llll**));
                break;
            case 'h':
                item = parseargs_item_new(P_HATOM, va_arg(ap, t_hatom*));
                break;
            default:
                object_bug((t_object *) x, "llll_parseargs: bad types: %s", types);
                err = 1;
                goto llll_parseargs_error;
                break;
        }
        hashtab_store(vars_ht, key, (t_object *) item);
    }
    va_end(ap);
    
    for (elem = ll->l_head; elem; elem = nextelem) {
        nextelem = elem->l_next;
        
        if (hatom_gettype(&elem->l_hatom) == H_SYM && (s = hatom_getsym(&elem->l_hatom)) && s->s_name && s->s_name[0] == '@') {
            t_max_err ht_err;
            t_llll **item_ll;
            
            key = gensym(s->s_name + 1);
            ht_err = hashtab_lookup(vars_ht, key, (t_object **) &item);
            
            if (ht_err) {
                object_error(x, "Bad message attribute key %s", key->s_name);
                continue;
            } else if (!item) {
                object_error(x, "Something is wrong with message attribute %s", key->s_name);
                continue;
            }

            
            // finding ending elem
            endelem = elem;
            while (endelem && endelem->l_next && !(hatom_gettype(&endelem->l_next->l_hatom) == H_SYM && (s2 = hatom_getsym(&endelem->l_next->l_hatom)) && s2->s_name && s2->s_name[0] == '@'))
                endelem = endelem->l_next;
            if (endelem == elem)
                endelem = NULL;
            
            if (item->p_type != P_LLLL) {
                if (!endelem) {
                    if (x)
                        object_error(x, "Bad value for message attribute %s", key->s_name);
                    continue;
                } else if (endelem != elem->l_next) {
                    if (x)
                        object_warn(x, "Multiple values for message attribute %s: only first one kept", key->s_name);
                }
            }

            switch (item->p_type) {
                case P_LONG:
                    if (hatom_gettype(&elem->l_next->l_hatom) == H_SYM) {
                        t_symbol *s = hatom_getsym(&elem->l_next->l_hatom);
                        long outlen = 0;
                        unsigned short *s_unicode = charset_utf8tounicode_debug(s->s_name, &outlen);
                        *(item->p_ptr.p_long) = outlen > 0 ? s_unicode[0] : 0;
                        bach_freeptr(s_unicode);
                    } else
                        *(item->p_ptr.p_long) = hatom_getlong(&elem->l_next->l_hatom);
                    break;
                case P_DOUBLE:
                    *(item->p_ptr.p_double) = hatom_getdouble(&elem->l_next->l_hatom);
                    break;
                case P_SYM:
                    *(item->p_ptr.p_symbol) = hatom_getsym(&elem->l_next->l_hatom);
                    break;
                case P_RAT:
                    *(item->p_ptr.p_rat) = hatom_getrational(&elem->l_next->l_hatom);
                    break;
                case P_PITCH:
                    *(item->p_ptr.p_pitch) = hatom_getpitch(&elem->l_next->l_hatom);
                    break;
                case P_HATOM:
                    *(item->p_ptr.p_hatom) = elem->l_next->l_hatom;
                    break;
                case P_LLLL:
                    item_ll = item->p_ptr.p_llll;
                    if (*item_ll)
                        llll_free(*item_ll);
                    *item_ll = llll_get();
                    for (temp_el = elem->l_next; temp_el; temp_el = temp_el->l_next) {
                        llll_appendhatom_clone(*item_ll, &temp_el->l_hatom);
                        if (temp_el == endelem)
                            break;
                    }
                    break;
            }

            if (endelem) {
                nextelem = endelem->l_next;
                
                if (destructive) {
                    temp_el = elem;
                    while (temp_el && temp_el != nextelem) {
                        next_temp_el = temp_el->l_next;
                        llll_destroyelem(temp_el);
                        temp_el = next_temp_el;
                    }
                }
            
            } else {
                
                if (destructive)
                    llll_destroyelem(elem);
            }
        }
    }
    
llll_parseargs_error:
    object_free_debug((t_object *) vars_ht);
    return err;
}

t_llll *llll_develop_ranges(t_llll *ll)
{
	t_llll *output = llll_get();
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		t_hatom *elem_hatom = &elem->l_hatom;
		long type = hatom_gettype(elem_hatom);
		if (type == H_LONG || type == H_DOUBLE) {
			llll_appendlong(output, hatom_getlong(elem_hatom), 0, WHITENULL_llll);
		} else if (type == H_LLLL) {
			t_llll *range_ll = hatom_getllll(elem_hatom);
            switch (range_ll->l_size) {
                case 1:
                {
                    llll_appendlong(output, hatom_getlong(&range_ll->l_head->l_hatom));
                    break;
                }
                case 2:
                {
                    t_atom_long start = hatom_getlong(&range_ll->l_head->l_hatom);
                    t_atom_long end = hatom_getlong(&range_ll->l_tail->l_hatom);
                    t_atom_long incr = start <= end ? 1 : -1;
                    t_atom_long i;
                    for (i = start; i <= end; i += incr)
                        llll_appendlong(output, i, 0, WHITENULL_llll);
                    break;
                }
            }
		}
	}
	pedantic_llll_check(output);
	return output;
}

void llll_put_elems_in_lllls_in_lthing(t_llll *ll)
{
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		t_llll *elem_ll = llll_get();
		llll_appendhatom_clone(elem_ll, &elem->l_hatom, 0, WHITENULL_llll);
		elem->l_thing.w_llll = elem_ll;
	}
}

void llll_remove_lllls_from_lthing(t_llll *ll)
{
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		llll_free(elem->l_thing.w_llll);
		elem->l_thing.w_llll = NULL;
	}
}  