/*
 *  llllobj.h
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef _LLLLOBJ_H_
#define _LLLLOBJ_H_

#define LLLL_MAX_INLETS			256
#define LLLL_MAX_OUTLETS		256
#define BACH_CANT_INSTANTIATE	"Out of memory"
#define BACH_MAXDEPTH_0_WARNING	"maxdepth 0 not accepted: setting to -1"
#define BACH_MINDEPTH_0_WARNING	"mindepth 0 not accepted: setting to 1"

#define BACH_DEFAULT_MAXDECIMALS	6
#define BACH_DEFAULT_EDITOR_LLLL_WRAP   68 

#include "foundation/llll_commons.h"
#include "jpatcher_api.h"
#include "z_dsp.h"
#include "foundation/bach_threads.h"

#ifndef CLASS_ATTR_BASIC
#define CLASS_ATTR_BASIC(c, name, flags) CLASS_ATTR_ATTR_PARSE(c,name,"basic",_sym_long,flags,"1")
#endif


///////////////////////////////
// DATA STRUCTURES FOR LLLL OBJECTS
//
// NB: all these structures should be considered opaque

typedef struct llllobj_store	// a thread-safe storage cache for lllls - see below llllobj_parse_and_store() & co.
{
	t_llll				*s_ll;
	t_bach_atomic_lock	s_lock;
} t_llllobj_store;

typedef struct llllobj_out // the structure for an outlet and its cached data - see llllobj_gunload_llll() & co.
{
	e_llllobj_outlet_types		b_type;		// the outlet type
	void						*b_outlet;	// the outlet itself
	t_symbol					*b_msg;		// the cached message
	long						b_ac;
	t_atom						*b_av;
	t_atomarray					*b_aa;		// the atomarray passed to the gunload_wrap family
	t_llll						*b_ll;		// the llll referred by a native format cached message
	t_bach_atomic_lock			b_lock;
} t_llllobj_out;


// a vanilla (i.e., non-ui, non-msp) llll object
// inherits from t_object, of course
// TO BE CLEANED UP!
typedef struct llllobj_object
{
	t_object				l_ob;               // the t_object from which we inherit
	
	t_int32					l_numstores;        // how many stores we have
	struct llllobj_store	*l_incache;         // the stores
	
	t_int32					l_numouts;          // how many outlets
	t_int32					l_numllllouts;      // how many llll outlets
	t_symbol				*l_outtypes;        // the value of the out attribute, when relevant
	struct llllobj_out		*l_out;             // the outs
	t_object				*l_send;            // unused
	
	t_bool					l_running;          // always 1 except during the instance creation - used for some exoteric initialization stuff - don't touch this!
	t_bool					l_rebuild;          // can be managed by the standard notify method
	t_llll					*l_dictll;          // unused
	t_hashtab				*l_release;         // the release pool
	t_bach_atomic_lock		l_release_lock;     // threadlock for the release pool
    
    t_atom_long             l_versionnumber;    // the number of the bach version under which the object was created or last saved
} t_llllobj_object;




// a DSP llll object
// inherits from t_pxobject
// TO BE CLEANED UP!
typedef struct llllobj_pxobject
{
	t_pxobject				l_ob;
	
	t_int32					l_numstores;	// how many stores we have
	struct llllobj_store	*l_incache;		// the stores
	
	t_int32					l_numouts;		// how many outlets
	t_int32					l_numllllouts;	// how many llll outlets
	t_symbol				*l_outtypes;	// the value of the out attribute, when relevant
	struct llllobj_out		*l_out;			// the outs
	
	t_bool					l_running;		// always 1 except during the instance creation - used for some exoteric initialization stuff - don't touch this!
	t_bool					l_rebuild;		// can be managed by the standard notify method
	t_llll					*l_dictll;		// unused
	t_hashtab				*l_release;		// the release pool
	t_bach_atomic_lock		l_release_lock; // threadlock for the release pool

    t_atom_long             l_versionnumber;    // the number of the bach version under which the object was created or last saved
} t_llllobj_pxobject;




// a UI llll object
// inherits from t_jbox
// TO BE CLEANED UP!
typedef struct llllobj_jbox
{
	t_jbox					l_box;
	
	t_uint32				l_numstores;	// how many stores we have
	struct llllobj_store	*l_incache;		// the stores
	
	t_uint32				l_numouts;		// how many outlets
	t_uint32				l_numllllouts;	// how many llll outlets
	t_symbol				*l_outtypes;	// the value of the out attribute, when relevant
	struct llllobj_out		*l_out;			// the outs
	
	t_bool					l_running;		// always 1 except during the instance creation - don't touch this!
	t_bool					l_rebuild;		// can be managed by the standard notification method
	t_llll					*l_dictll;		// Optionally set by llllobj_is_help
	t_hashtab				*l_release;		// stuff to be released when the object is freed
	t_bach_atomic_lock		l_release_lock;

    t_atom_long             l_versionnumber;    // the number of the bach version under which the object was created or last saved
} t_llllobj_jbox;





// a DSP UI llll object
// inherits from t_pxjbox
// TO BE CLEANED UP!
typedef struct llllobj_pxjbox
{
	t_pxjbox				l_ob;
	
	t_uint32				l_numstores;	// how many stores we have
	struct llllobj_store	*l_incache;		// the stores
	
	t_uint32				l_numouts;		// how many outlets
	t_uint32				l_numllllouts;	// how many llll outlets
	t_symbol				*l_outtypes;	// the value of the out attribute, when relevant
	struct llllobj_out		*l_out;			// the outs
	
	t_bool					l_running;		// always 1 except during the instance creation - don't touch this!
	t_bool					l_rebuild;		// can be managed by the standard notification method
	t_llll					*l_dictll;		// Optionally set by llllobj_is_help
	t_hashtab				*l_release;		// stuff to be released when the object is freed
	t_bach_atomic_lock		l_release_lock;

    t_atom_long             l_versionnumber;    // the number of the bach version under which the object was created or last saved
} t_llllobj_pxjbox;





// unused
typedef struct llllobj_iterouts
{
	t_atom_long		l_data_nout;
	t_atom_long		l_data_tout;
	t_atom_long		l_address_nout;
	t_atom_long		l_address_tout;
} t_llllobj_iterouts;





//////////////////////////
// THE TINY LL
//
// A singly-linked list useful for several low-level tasks

typedef struct _tinyllelem {
	struct _tinyllelem	*t_next;
	t_llll				*t_thing;
	t_atom_ulong		t_key;
} t_tinyllelem;

typedef struct _tinyll {
	t_tinyllelem		*t_head;
	t_bach_atomic_lock	t_lock;
} t_tinyll;


// flags used by llllobj_parse_llll and family
//
// LLLL_PARSE_RETAIN causes an incoming native llll to be retained, and a new llll to be created when a text llll is received
// this means that, in either case, you are allowed to perform non-destructive operations on it, and release it afterwards.
//
// LLLL_PARSE_CLONE causes an incoming native llll to be retained, and a new llll to be created when a text llll is received
// this means that, in either case, you are allowed to perform destructive operations on it, and free it afterwards.
// of course you can perform non-destructive operations as well, but in this case LLLL_PARSE_RETAIN is much more efficient
//
// if you set LLLL_PARSE_DONT, the native llll won't be retained.
// so, if the incoming llll is text-based you have the right to use the newly-parsed llll
// but if the incoming llll is native you don't have the right to use it, which is hardly what you want!
typedef enum _llllobj_parse_flags {
	LLLL_PARSE_DONT		= 0x00, // don't do anything - you never want to use this
	LLLL_PARSE_RETAIN	= 0x01,	// if input is native, retain it
	LLLL_PARSE_CLONE	= 0x02  // if input is native, clone it
} e_llllobj_parse_flags;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif



// unused
void llllobj_post_destructive_volatile(void);





// get the object type (works with every object, not only bach!)
e_llllobj_obj_types llllobj_get_obj_type(void *x);





// functions to get fields of the llllobj structure according to the object type. outlets are counted from 0

t_symbol *llllobj_get_name(t_object *x, e_llllobj_obj_types type);
t_llllobj_out *llllobj_get_out(t_object *x, e_llllobj_obj_types type);
t_llllobj_store *llllobj_get_incache(t_object *x, e_llllobj_obj_types type);
t_object *llllobj_get_freeobj(t_object *x, e_llllobj_obj_types type);
long llllobj_get_numouts(t_object *x, e_llllobj_obj_types type);
long llllobj_get_numllllouts(t_object *x, e_llllobj_obj_types type);
long llllobj_get_numstores(t_object *x, e_llllobj_obj_types type);
e_llllobj_outlet_types llllobj_get_outlet_type(t_object *x, e_llllobj_obj_types type, t_uint32 num);
t_llll **llllobj_get_dictll_ptr(t_object *x, e_llllobj_obj_types type);
t_hashtab *llllobj_get_release(t_object *x, e_llllobj_obj_types type);
t_bach_atomic_lock *llllobj_get_release_lock_ptr(t_object *x, e_llllobj_obj_types type);






///////////////////////
///////////////////////
// FUNCTIONS TO DIRECTLY OUTPUT STUFF
//
// these functions directly output stuff, without going through output caches





// for llll outlets, retrieve the text or native type as a string
// useful in the assist method
void llllobj_get_llll_outlet_type_as_string(t_object *x, e_llllobj_obj_types type, long num, char **str);




// output things from llll objects
// these are simple wrappers to
// outlets are counted from 0
void llllobj_outlet_bang(t_object *x, e_llllobj_obj_types type, long outnum);
void llllobj_outlet_int(t_object *x, e_llllobj_obj_types type, long outnum, t_atom_long n);
void llllobj_outlet_float(t_object *x, e_llllobj_obj_types type, long outnum, double n);
void llllobj_outlet_anything(t_object *x, e_llllobj_obj_types type, long outnum, t_symbol *msg, long ac, t_atom *av);
void llllobj_outlet_anything_prudent(t_object *x, e_llllobj_obj_types type, long outnum, t_symbol *msg, long ac, t_atom *av);

void outlet_anything_prudent(void *o, t_symbol *s, short ac, t_atom *av);


/**     Send a given symbol as a unique element of an llll, through a
 given outlet of a given object (the routine also destroys the llll
 afterwards).
 @ingroup                                        llll_objects
 @param  x                                       The object sending the llll
 @param  llllobj_obj_type        The object type (one of the #e_llllobj_obj_types)
 @param  outlet_num                      The index of the outlet
 @param  sym                                     The symbol
 */
void llllobj_outlet_symbol_as_llll(t_object *x, e_llllobj_obj_types llllobj_obj_type, long outlet_num, t_symbol *sym);


/** Send two symbols as an llll, through a given outlet of a given
 object (the routine also destroys the llll afterwards).
 @ingroup                                        llll_utilities
 @param  x                                       The object sending the llll
 @param  llllobj_obj_type        The object type (one of the #e_llllobj_obj_types)
 @param  outlet_num                      The index of the outlet
 @param  sym1                            The first symbol
 @param  sym2                            The second symbol
 */
void llllobj_outlet_symbol_couple_as_llll(t_object *x, e_llllobj_obj_types llllobj_obj_type, long outlet_num, t_symbol *sym1, t_symbol *sym2);


// directly output a llll
// it manages native / text format
// each object receiving the llll retains it if needed, so you should free the list after outputting it
// outlets are counted from 0
// flags are e_llll_deparse_flags
void llllobj_outlet_llll(t_object *x, e_llllobj_obj_types type, long outnum, t_llll *in_ll, long flags = 0);

typedef enum {
    E_DEFER = 0,
    E_DEFERLOW
} e_defer_kind;

// private
void llllobj_outlet_llll_defer_do(t_object *x, t_symbol *dummy, long ac, t_atom *av);

// the same as llllobj_outlet_llll, but the output is either deferred or deferlow-ed,
// according to the value of the parameter KIND
template<e_defer_kind KIND = E_DEFER>
void llllobj_outlet_llll_defer(t_object *x, e_llllobj_obj_types type, long outnum, t_llll *in_ll, long flags = 0)
{
    t_atom av[4];
    atom_setlong(av, type);
    atom_setlong(av + 1, outnum);
    atom_setobj(av + 2, llll_retain(in_ll));
    atom_setlong(av + 3, flags);
    if constexpr (KIND == E_DEFER)
        defer(x, (method) llllobj_outlet_llll_defer_do, NULL, 4, av);
    else
        defer_low(x, (method) llllobj_outlet_llll_defer_do, NULL, 4, av);
}



// (unused)
// directly outlets a llll
// if you are outputting a llll you know the phonenumber of, it is more efficient to call this
// outlets are counted from 0
void llllobj_outlet_llll_with_phonenumber(t_object *x, e_llllobj_obj_types type, t_llll *inll, t_atom_ulong phonenumber, long outnum);





///////////////////////
///////////////////////
// PARSING FUNCTIONS
//
// you will most often use llll_parse_clone_and_store() & co., which also manage the storing of the incoming lllls

/*
 Create a new llll from a message selector (which can be NULL as well) and an array of atoms
 This is especially useful from parsing messages coming through inlets - it correctly deals with native and text formats.
 If the input has the form "bach.llll 1234" (i.e. it's a native representation) the address of the associated llll is returned, if valid
 If the input is a valid text-based representation, a new llll is created and its address is returned
 If the input is not valid, NULL is returned
 If the LLLL_PARSE_RETAIN flag is set and the input is a native representation, the llll is retained.
 If the LLLL_PARSE_CLONE flag is set and the input is a native representation, a copy of the llll is returned.
 If the input is a text representation, a new llll is created in any case, and the flag is ignored.
 This gives you ownership to the returned llll in any case, and you must free it / release it.
 If you set LLLL_PARSE_RETAIN you only have the right to perform non-destructive operations on the llll.
 If you set LLLL_PARSE_CLONE you also have the right to perform destructive operations on the llll.
 But if you are about to store the incoming llll in one of your object's stores, then you have to use llllobj_parse_and_store() or llllobj_parse_retain_and_store()
 */
t_llll *llllobj_parse_llll(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, e_llllobj_parse_flags flags, long ignore = LLLL_I_NONE);

/*
 A workaround for dealing with how text-format lllls are passed to objects
 */
t_llll *llllobj_parse_llllattr_llll(t_object *x, e_llllobj_obj_types type, long ac, t_atom *av);

// if ac == 1 and av is a valid phonenumber, retrieve the corresponding llll
// slightly faster than llllobj_parse_llll if you already know that it's native
t_llll *llllobj_get_retained_native_llll_from_args(long ac, t_atom *av);




//////////////
// FUNCTIONS TO MANAGE OUTPUT CACHES
// An output cache is a data structure holding an llll and capable to output it over and over
// Each llll outlet is associated by an output cache
// Output caches are initialized by llllobj_setup() & co.
// all these functions are thread-safe
// NB: since banging an object to obtain the same result over and over
// (that is, without changing any attribute value, or inputting new data in the cold inlets)
// is a somewhat exceptional operation,
// and at the same time the cost of maintaining an output cache is not negligible,
// output caches are likely to be suppressed in a future version of bach.
//
// Gunloading an llll doesn't automatically output it
// Use llllobj_shoot_llll() for this
//
// IMPORTANT:
// after you gunload a llll, you don't own it anymore
// its lifecycle is managed by the gunload family from now on
// so, you don't have to worry about its freeing
// but you can't count on its validity at any time, either
// after you have gunloaded a llll, you can't "touch" it anymore


// load an llll in an output cache
// outlets are counted from 0
void llllobj_gunload_llll(t_object *x, e_llllobj_obj_types type, t_llll *inll, long outnum);


// (unused) load an llll in an output cache by phonenumber
// use llllobj_gunload_llll() instead
void llllobj_gunload_llll_with_phonenumber(t_object *x, e_llllobj_obj_types type, t_llll *inll, t_atom_ulong phonenumber, long outnum);


// (unused) load one or more lllls wrapped in an atomarray
// the extra arguments are the numbers of the outs where to load, corresponding to each atom in the atomarray
// outlets are counted from 0
void llllobj_gunload_wrap(t_object *x, e_llllobj_obj_types type, t_atom *in_aa_atom, ...);


// (unused) load in consecutive outs one or more lllls wrapped in an atomarray
// minout is the outlet corresponding to the first llll in the atomarray
// maxout is the outlet corresponding to the last llll in the atomarray
// this is useful when the number of outlets is variable (as in bach.delace)
// outlets are counted from 0
void llllobj_gunload_wrap_range(t_object *x, e_llllobj_obj_types type, t_atom *in_aa_atom, long minout, long maxout);



// same as the above, but the lllls are into an array
// of course it is your responsibility to ensure that arr has the correct size
// arr is not freed
// outlets are counted from 0
void llllobj_gunload_array_range(t_object *x, e_llllobj_obj_types type, t_llll **arr, long minout, long maxout);



// (private) load an llll in a text outlet
void llllobj_gunload_bttext(t_llllobj_out *cache, t_llll *inll);

// (private) load an llll in a max-formatted outlet
void llllobj_gunload_max(t_llllobj_out *cache, t_llll *inll);

// (private) load an llll in a native outlet
void llllobj_gunload_native(t_llllobj_out *cache, t_llll *ll);

// (private) load an llll in a native outlet, with a known phonenumber
// doesn't check if the phonenumber is valid
void llllobj_gunload_native_with_phonenumber(t_llllobj_out *cache, t_llll *ll, t_atom_ulong phonenumber);





// output a llll that has been stored
// typically you call this from your bang method
// outlets are counted from 0
void llllobj_shoot_llll(t_object *x, e_llllobj_obj_types type, long outnum);

// (private) load a list (meaning, a max list - not an llll) in an output cache
void llllobj_cache_list(t_llllobj_out *cache, t_symbol *msg, long ac, t_atom *av, void *thing);

// (private) load any message in an output cache
void llllobj_cache_anything(t_llllobj_out *cache, t_symbol *msg, long ac, t_atom *av, void *thing);

// (private) load a text-based llll (with or without backticks) in an output cache from the atomarray coming from the deparse method
void llllobj_cache_text(t_llllobj_out *cache, t_atomarray *deparsed_aa);


void llllobj_clear_all_stores(t_object *x, e_llllobj_obj_types type);
void llllobj_clear_all_outs(t_object *x, e_llllobj_obj_types type);
void llllobj_clear_all_stores_and_outs(t_object *x, e_llllobj_obj_types type);



/////////////
// FUNCTIONS TO MANAGE STORES
// all these functions are thread-safe

// parse an llll (in native or text format, that is as it comes from an inlet) and stores it in store, also freeing the previously-stored llll
// IMPORTANT:
// the return value is the stored llll or NULL if unsuccessful,
// but you should not use this value except for checking if the operation was successful.
// In fact, you don't own a reference to the llll (so you don't have to free it!)
// if you need to do things with it, use llllobj_parse_retain_and_store
// stores are counted from 0
t_llll *llllobj_parse_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store);


// parse an llll, retain it, store it (also freeing the previously-stored llll) and returns it
// this means that you own it, and therefore you have to free it, but you can't perform destructive operations upon it
// you need this flavour when, after storing the list, you directly need to operate non-destructively on it or gunload it
// (e.g. bach.reg)
// stores are counted from 0
t_llll *llllobj_parse_retain_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store);


// parses an llll, clone it, stores it (also freeing the previously-stored llll) and returns the clone
// this means that you own it, and therefore you have to free it
// you need this flavour when, after storing the list, you directly need to operate destructively on it
// (e.g. bach.flat)
// stores are counted from 0
t_llll *llllobj_parse_clone_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store);


// parse an llll, clone it, wrap the clone in lvls levels of parentheses (as bach.wrap would do), store the result and return it
// as with llllobj_parse_and_store(), use the returned pointer only for checking if the operation was successful.
// NB: if lvls == 0, works exactly as llllobj_parse_and_store() instead.
t_llll *llllobj_parse_wrap_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store, t_atom_long lvls);


// parse an llll, clone it, wrap the clone in lvls levels of parentheses (as bach.wrap would do), store the result, clone it and return it
// you can perform non-destructive operations on the returned llll
// NB: if lvls == 0, works exactly as llllobj_parse_retain_and_store() instead.
t_llll *llllobj_parse_wrap_retain_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store, t_atom_long lvls);


// parse an llll, clone it, wrap the clone in lvls levels of parentheses (as bach.wrap would do), store the result, clone it and return the clone
// you can perform destructive operations on the returned llll
// NB: if lvls == 0, works exactly as llllobj_parse_clone_and_store() instead.
t_llll *llllobj_parse_wrap_clone_and_store(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store, t_atom_long lvls);


// a variant of llllobj_parse_and_store that is specific for dealing with element addresses (as in the address inlet of bach.nth)
// only valid addresses will be accepted
// accept_multiple tells if the multiple element syntax is refused (as in bach.swap) or accepted (as in bach.insert)
// accept_range tells if the range syntax is refused (as in bach.insert) or accepted (as in bach.nth)
// stores are counted from 0;
t_max_err llllobj_parse_and_store_llll_address(t_object *x, e_llllobj_obj_types type, t_symbol *msg, long ac, t_atom *av, long store_num, t_bool accept_multiple, t_bool accept_range);

t_max_err llllobj_check_llll_address(t_object *x, t_llll *ll, t_bool accept_multiple, t_bool accept_range);


// store an llll (also freeing the previously stored llll)
// llllobj_store_llll() takes ownership of the llll, so if you need to use it otherwise you need to retain it
// anyway, an llll that has been stored can't be modified anymore - if you have to, you must operate on a clone
// stores are counted from 0
void llllobj_store_llll(t_object *x, e_llllobj_obj_types type, t_llll *ll, long store_num);


// retain and return llll from a store
// because the llll has been retained, you are free to use it for non-destructive operations
// to perform destructive operations, you must operate on a copy (see llll_clone)
// in any case, it's your responsibility releasing the llll after use.
// of course, while you are operating on the llll the actual contents of the store might be changed in another thread
// but the llll you're working on will still be valid, just because it has been retained
// stores are counted from 0
t_llll *llllobj_get_retained_store_contents(t_object *x, e_llllobj_obj_types type, long num);


// return llll from a store
// if clone == 0, then the llll you obtain has been retained,
// which allows you to perform non-destructive operations upon it
// and requires you to release it at the end
// if clone != 0 then the llll you obtain has been cloned,
// which allows you to perform destructive operations upon it
// notice that after a destructive operation, the llll has been destroyed
// thus you don't have to free it anymore
// but if for any reason you didn't perform a destructive operation upon it
// then you must free it
// stores are counted from 0
t_llll *llllobj_get_store_contents(t_object *x, e_llllobj_obj_types type, long num, long clone);








////////////////////////
// OBJECT INITIALIZATION AND LIFECYCLE FUNCTIONS



// called from every object's main() function
// returns non-0 if the llll version number of the object doesn't match the llll version number of the global bach object
// in which case the class should not be created
t_max_err llllobj_check_version(t_atom_ulong version);


// this must be called from every object's main() function, that should abort if != 0
// it is not only a test - it also initializes some important classes the first time it's called
t_max_err llllobj_test(void);



// setup functions for different types of objects
// if your object supports the out attribute, you must parse it before calling the setup function
// NB that those don't include dspsetup etc.
// they just set up the llll-compliant part of your object
//
// stores is the number of stores you want to set up
// outlets is a string composed of one character for each outlet to be created, in reversed order.
// allowed characters are:
// b (bang)
// i (int)
// f (float)
// i (long)
// 4 (llll) - format will depend on the out attribute
// a - anything
// s - signal (only for pxobj and pxjbox. signal outlets must be the first ones, and therefore be declared at the end of the string)
// for each "a" outlet, a message selector (or NULL) must be provided
//
// examples:
// llllobj_obj_setup((t_llllobj_object *) x, 1, "4"); // a single llll outlet
// llllobj_obj_setup((t_llllobj_object *) x, 1, "44"); // two llll outlets
// llllobj_obj_setup((t_llllobj_object *) x, 1, "b44"); // two llll outlets, and a third bang outlet
// llllobj_pxobj_setup((t_llllobj_pxobject *) x, 1, "b44ss"); // two signal outlets, two llll outlets, and a bang outlet
// llllobj_obj_setup((t_llogbobj_object *) x, 1, "aaif44a", NULL, "foo", "bar");	// a "bar"-typed anything outlet,
																					// two llll outlets,
																					// a float outlet,
																					// an int outlet,
																					// a "foo"-typed anything outlet
																					// and a untyped anything outlet
t_max_err llllobj_obj_setup(t_llllobj_object *x, long stores, const char *outlets, ...);
t_max_err llllobj_pxobj_setup(t_llllobj_pxobject *x, long stores, const char *outlets, ...);
t_max_err llllobj_jbox_setup(t_llllobj_jbox *x, long stores, const char *outlets, ...);
t_max_err llllobj_pxjbox_setup(t_llllobj_pxjbox *x, long stores, const char *outlets, ...);



// free functions for different types of objects
// NB: they don't free the dsp, the jbox or the proxies
// they just free the llll-compliant part of your object
void llllobj_obj_free(t_llllobj_object *x);
void llllobj_pxobj_free(t_llllobj_pxobject *x);
void llllobj_jbox_free(t_llllobj_jbox *x);
void llllobj_pxjbox_free(t_llllobj_pxjbox *x);



// (private) adjusts the value of *outtypes according to the number of llll outlets
// accepts_minus is non-0 if we're not in the initialization phase
// returns 0 if *outtypes has not changed, 1 if it has
long llllobj_conform_outtypes(t_object *x, e_llllobj_obj_types type, char **outtypes, long accept_minus, t_max_err *err = nullptr);



// (private) attribute setters for the out attribute
t_max_err llllobj_obj_setout(t_llllobj_object *x, t_object *attr, long argc, t_atom *argv);
t_max_err llllobj_jbox_setout(t_llllobj_jbox *x, t_object *attr, long argc, t_atom *argv);
t_max_err llllobj_pxobj_setout(t_llllobj_pxobject *x, t_object *attr, long argc, t_atom *argv);
t_max_err llllobj_pxjbox_setout(t_llllobj_pxjbox *x, t_object *attr, long argc, t_atom *argv);



// (private) change the format of an llll out - only called by the out attribute setters
void llllobj_change_out_type(t_llllobj_out *cache, e_llllobj_outlet_types newtype);



// add the out attribute and a notify method to edit the rebuild setting
// you should always call this function from your object's main()
// if you want to add the out attribute to it
// (which you should do whenever you have one or more llll outlets)
//
// This function also adds a notify method, managing the l_rebuild field.
// If you need to intercept the notify method as well, declare a "bachnotify" method instead
// that will be called by the standard notify method.
void llllobj_class_add_out_attr(t_class *c, e_llllobj_obj_types type);

// add the invisible versionnumber attr
void llllobj_class_add_versionnumber_attr(t_class *c, e_llllobj_obj_types type);

// add the fileusage method
void bachobject_class_add_fileusage_method(t_class *c);

// add the out and versionnumber attrs,
// and the fileusage method
void llllobj_class_add_default_bach_attrs_and_methods(t_class *c, e_llllobj_obj_types type);

// to be called from the object constructor
// returns the object version number, as stored in the object dictionary,
// or 0 if the version number is not stored
// (meaning that the object was saved with bach pre-0.8,
// or that is being typed now)
// if process is true, the arguments stored in the object dictionary will be processed
t_atom_long llllobj_get_version_number(t_object *x, e_llllobj_obj_types types);

// sets the object version number as the current one
// should be called by each object at the end of its constructor
void llllobj_set_current_version_number(t_object *x, e_llllobj_obj_types type);
void llllobj_set_current_version_number_and_ss(t_object *x, e_llllobj_obj_types type);


// sets the object version number as a specified one (useful before handling backward compatibility routines)
void llllobj_set_version_number(t_object *x, e_llllobj_obj_types type, long version_number);


// clean all the stores and outlets of an object
void llllobj_cleanup_vanilla(t_object *x);
void llllobj_cleanup_ui(t_object *x);
void llllobj_cleanup_msp(t_object *x);
void llllobj_cleanup_uimsp(t_object *x);



// (private) standard notify methods
t_max_err llllobj_obj_rebuild_notify(t_llllobj_object *x, t_symbol *s, t_symbol *msg, void *sender, void *data);
t_max_err llllobj_jbox_rebuild_notify(t_llllobj_jbox *x, t_symbol *s, t_symbol *msg, void *sender, void *data);
t_max_err llllobj_pxobj_rebuild_notify(t_llllobj_pxobject *x, t_symbol *s, t_symbol *msg, void *sender, void *data);
t_max_err llllobj_pxjbox_rebuild_notify(t_llllobj_pxjbox *x, t_symbol *s, t_symbol *msg, void *sender, void *data);




/////////////////////
// RELEASE POOL MANAGEMENT
//
// each llll object has a release pool, to which things that should be freed when the object is freed are registered
// the contents release pool are freed automatically by llllobj_obj_free and co.


// register an object to be released in the release pool
// release_me is the object to be released, free_function is the function to be called to free it (e.g. object_free_debug or llll_free)

t_max_err llllobj_add_to_release_pool(t_object *x, e_llllobj_obj_types type, void *release_me, method free_function);


// remove an object from the release pool
t_max_err llllobj_remove_from_release_pool(t_object *x, e_llllobj_obj_types type, void *remove_me);


// (private)
// free the release pool and everything it contains
void llllobj_free_release_pool(t_object *x, e_llllobj_obj_types type);

// (private)
// release one element of the release pool
void hashtab_release_one(t_hashtab_entry *e, void *dummy);







/////////////////////
// LAMBDA LOOP TESTING
//


// test whether a lambda loop is present, in an object with two lambda outlets
// the function will send out an aptly-created llll containing el2 from the second lambda outlet (lambda2, counting from 0),
// and an aptly-created llll containing el1 from the first lambda outlet (lambda1, counting from 0),
// and then free the two lllls.
// It is up to the specific object to check whether something is returned to the lambda inlet.
t_max_err llllobj_test_lambda_loop_two_outs(t_object *x, e_llllobj_obj_types type, t_llllelem *el1, t_llllelem *el2, long lambda1, long lambda2);


// as above, but with a single lambda outlet
t_max_err llllobj_test_lambda_loop_one_out(t_object *x, e_llllobj_obj_types type, t_llllelem *el, long lambda);





// unused
void llllobj_manage_dict_llll(t_object *x, e_llllobj_obj_types type, t_llll *dictll);
void llllobj_manage_dict_llll_do(t_object *x, t_symbol *msg, long ac, t_atom *av);


// to remove an annoying warning about non-const string literal
void bach_class_setname(const char *obname, const char *filename);


// unused
long bach_is_loadtime(void);



// dummy setter
t_max_err llllobj_dummy_setter(t_object *x, void *attr, long ac, t_atom *av);





//////////////////////////////
// LLLL ATTRIBUTE MANAGEMENT
//
// managing llll attributes requires some extra work with respect to the standard Max attributes
// here are some macros to ease the task



// Objects having llll attributes may call this macro before the main() function
// It defines default getter and setter functions
// STRUCT is the object struct
// FIELD is the struct field containing the pointer to the llll that should be treated as an attribute
// GETTER is the name of the getter function
// SETTER is the name of the setter function

#define DEFINE_LLLL_ATTR_DEFAULT_GETTER_AND_SETTER(STRUCT, FIELD, GETTER, SETTER) \
DEFINE_LLLL_ATTR_DEFAULT_GETTER(STRUCT, FIELD, GETTER) \
DEFINE_LLLL_ATTR_DEFAULT_SETTER(STRUCT, FIELD, SETTER) \




// Objects having llll attributes may call this macro before the main() function
// It defines a default setter for an llll attribute
// STRUCT is the object struct
// FIELD is the struct field containing the pointer to the llll that should be treated as an attribute
// SETTER is the name of the setter function

#define DEFINE_LLLL_ATTR_DEFAULT_SETTER(STRUCT, FIELD, SETTER) \
t_max_err SETTER(STRUCT *x, t_object *attr, long ac, t_atom *av) \
{ \
	if (ac == 0 || av) { \
		t_llll *ll; \
    if ((ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_CLONE))) { \
			if (x->FIELD) \
				llll_free(x->FIELD); \
			x->FIELD = ll; \
		} \
	} \
	return MAX_ERR_NONE; \
} \




// Objects having llll attributes may call this macro before the main() function
// It defines a default getter for an llll attribute
// STRUCT is the object struct
// FIELD is the struct field containing the pointer to the llll that should be treated as an attribute
// GETTER is the name of the getter function

#define DEFINE_LLLL_ATTR_DEFAULT_GETTER(STRUCT, FIELD, GETTER) \
t_max_err GETTER(STRUCT *x, t_object *attr, long *ac, t_atom **av) \
{ \
	if (*ac && *av) { \
		dev_post("Error in llll_Max_attr_get!"); \
	} else { \
		*av = NULL; \
		*ac = 0; \
		*ac = llll_deparse(x->FIELD, av, 0, 0); \
		bach_remove_from_memmap(*av); \
} \
	return MAX_ERR_NONE; \
}




// Objects having llll attributes may call this macro in the main() function
// It defines the actual attribute
#define CLASS_ATTR_LLLL(c,attrname,flags,structname,structmember,getter,setter) \
	class_addattr((c), attr_offset_array_new(attrname, USESYM(atom), 1, (flags), (method)getter, (method)setter, 0, calcoffset(structname, structmember)))





///////////////////
// MAXDEPTH AND MINDEPTH ATTRIBUTES MANAGEMENT
//
// In most objects, the maxdepth and mindepth attributes can't accept a value of 0
// To deal with this, here are two macros to define standard setters for them


// Objects having the maxdepth attribute may call this macro before the main() function
// It defines a standard setter for maxdepth, named after the object struct name
// e.g., if the struct name is t_rev, the setter name will be t_rev_maxdepth_set
// This setter will emit a warning if maxdepth is set to 0, and automatically change it to -1

#define DEFINE_STANDARD_MAXDEPTH_SETTER(STRUCT) \
t_max_err STRUCT_maxdepth_set(STRUCT *x, t_object *attr, long argc, t_atom *argv) \
{ \
	long maxdepth = atom_getlong(argv); \
	if (maxdepth == 0) { \
		object_warn((t_object *) x, BACH_MAXDEPTH_0_WARNING); \
		x->n_maxdepth = -1; \
		return 0; \
	} \
	x->n_maxdepth = maxdepth; \
	return 0; \
}




// Objects having the mindepth attribute may call this macro before the main() function
// It defines a standard setter for mindepth, named after the object struct name
// e.g., if the struct name is t_rev, the setter name will be t_rev_mindepth_set
// This setter will emit a warning if mindepth is set to 0, and automatically change it to 1

#define DEFINE_STANDARD_MINDEPTH_SETTER(STRUCT) \
t_max_err STRUCT_mindepth_set(STRUCT *x, t_object *attr, long argc, t_atom *argv) \
{ \
	long mindepth = atom_getlong(argv); \
	if (mindepth == 0) { \
		object_warn((t_object *) x, BACH_MINDEPTH_0_WARNING); \
		x->n_mindepth = 1; \
		return 0; \
	} \
	x->n_mindepth = mindepth; \
	return 0; \
}




// Objects having the maxdepth attribute may call this macro in the main() function, after the attribute declaration
// It sets the standard setter for it, according to the naming convention of DEFINE_STANDARD_MAXDEPTH_SETTER

#define CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, STRUCT) \
CLASS_ATTR_ACCESSORS(c, "maxdepth", NULL, STRUCT_maxdepth_set);


// Objects having the mindepth attribute may call this macro in the main() function, after the attribute declaration
// It sets the standard setter for it, according to the naming convention of DEFINE_STANDARD_MINDEPTH_SETTER

#define CLASS_ATTR_STANDARD_MINDEPTH_ACCESSORS(c, STRUCT) \
CLASS_ATTR_ACCESSORS(c, "mindepth", NULL, STRUCT_mindepth_set);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif
	
#endif // _LLLLOBJ_H_
