#ifndef _LLLL_COMMONS_H_
#define _LLLL_COMMONS_H_

// very private! don't ever change these!!!
#define LLLL_PRIMES_TABLE_MAX 46337		// the greatest prime <= sqrt(MAXLONG) (it's the last of our prime table)
#define LLLL_PRIMES_TABLE_SIZE 4792		// how many primes do we have in our table?
#define LLLL_STACK_SIZESTEP 64			// the dynamic allocation step used by llll_stack
#define LLLL_BUF_SIZE_STEP 16384		// the dynamic allocation step for text buffers
#define LLLL_IDX2PTR_SLOTS	1048576		// the number of slots for the llll_phonebook p_idx2ptr hash table (the hashing is just a modulo, so a power of 2 is fine)
#define BACH_SHASHTABLE_SLOTS 1024
#define MAX_SYM_LENGTH 2048				// the supposed maximum length for a symbol name
#define	QUOTE_CHAR ('`')				// the special character for quoting
#define LLLL_NATIVE_MSG	(_llllobj_sym_bach_llll)

#define TEXT_LIST_MAX_LENGTH		65536
#define ATOM_LIST_LENGTH_STEP		4096
#define TEXT_BUF_SIZE_STEP			(4096*64)

#include "llll_append.h"
#include "llll_hatom_change.h"
#include "llll_comparisons.h"
#include "bach_threads.h"
#ifdef BACH_JITCLANG
#include "bach_jitclang.h"
#else
#include "ext_hashtab.h"
#endif

#ifdef BACH_TRACK_MEMORY_ALLOCATION
#include "jgraphics.h"
#endif

//#include "jpatcher_api.h"
//#include "jgraphics.h"


// flags for llll_deparse()
// NB: for cross-architecture compatibility, 64-bit floats are stored as two longs even under 64-bit architecture
typedef enum _llll_deparse_flags {
	LLLL_D_NONE		= 0x00,
	LLLL_D_QUOTE	= 0x01, // backtick symbols if they can be interpreted as other data types
    LLLL_D_MAX      = 0x02, // backtick "int", "float" and "list" if they appear at the beginning of an llll
	LLLL_D_FLOAT64	= 0x04	// encode 64-bit floats as a special token and two longs (useful to store lllls in dictionaries and similar)
} e_llll_deparse_flags;



// flags for llll_to_text_buf
typedef enum _llll_text_flags {
	LLLL_T_NONE								= 0x00,
	LLLL_T_NULL								= 0x01,	// null is returned if list is empty
	LLLL_T_NO_DOUBLE_QUOTES					= 0x02,
	LLLL_T_NO_BACKSLASH						= 0x04,
	LLLL_T_FORCE_DOUBLE_QUOTES				= 0x08,
	LLLL_T_BACKSLASH_BEFORE_DOUBLE_QUOTES	= 0x10,
    LLLL_T_FORCE_SINGLE_QUOTES				= 0x20,
    //LLLL_T_BACKSLASH_BEFORE_SINGLE_QUOTES	= 0x40,
	LLLL_T_ONLY_STANDARD_PARENTHESES		= 0x80
} e_llll_text_flags;

#define LLLL_T_COPYSYMBOLS (LLLL_T_NO_DOUBLE_QUOTES | LLLL_T_NO_BACKSLASH)




// outlet types (used in the llllobj_out structure)
typedef enum _llllobj_outlet_types {
	LLLL_O_DISABLED		= 0x0000,
	LLLL_O_BANG         = 0x0001,
	LLLL_O_LONG         = 0x0002,
	LLLL_O_FLOAT        = 0x0004,
	LLLL_O_LIST         = 0x0008,
	LLLL_O_ANYTHING     = 0x0010,
	LLLL_O_NATIVE       = 0x0020,
	LLLL_O_TEXT         = 0x0080,
    LLLL_O_MAX          = 0x0100,
	LLLL_O_SIGNAL       = 0x0200 // unused for now
} e_llllobj_outlet_types;


//
// enums used by llll_iter and llll_step
//

// what's in this elem?
typedef enum _llll_elem_types {
    LLLL_E_NULL	= 0x01,
    LLLL_E_LLLL = 0x02,
    LLLL_E_ATOM = 0x04
} e_llll_elem_types;

// recursion modes
typedef enum _llll_modes_recursion {
    LLLL_M_RECURSION_DONT = 0,
    LLLL_M_RECURSION_UNROLL
} t_llll_modes_recursion;

// iteration modes
typedef enum _llll_modes_iteration {
    LLLL_M_ITERATION_STOP = 0,
    LLLL_M_ITERATION_MUTE,
    LLLL_M_ITERATION_SHOOT
} e_llll_modes_iteration;

// spike modes
typedef enum _llll_modes_spike {
    LLLL_M_SPIKE_SHOOT = 0,
    LLLL_M_SPIKE_IGNORE,
    LLLL_M_SPIKE_VERBOSE,
    LLLL_M_SPIKE_SHOOT_STEP
} e_llll_modes_spike;

// flags for llll_funall
typedef enum _llll_funall_flags {
	FUNALL_ONLY_PROCESS_ATOMS = 0,
	FUNALL_PROCESS_WHOLE_SUBLISTS,
	FUNALL_SKIP_ATOMS,
	FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH,
	FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH_AND_SKIP_ATOMS
} e_llll_funall_flags;




// a stack for pointers
// there is a small set of functions for dealing with it
typedef struct _llll_stack {
	void **s_stack;		// the stack itself
	void **s_current;	// pointer to the last pushed item in the stack
	long s_size;		// the current size of the stack (it's dynamic!)
	long s_items;		// the number of items in the stack
} t_llll_stack;




// used by bach.step
typedef struct _llll_itercache {
	long				i_active;			// are we inside an iteration? (if 0, all the other fields are not significant)
	t_llll_stack		*i_elem_stack;		// the stack containing the higher-level elems, and this one
	t_llll_stack		*i_inlist_stack;	// the stack containing the higher-level lllls, and this one
	t_llll_stack		*i_steps_stack;		// the stack containing the higher-level steps (they are actually longs!), and this one
	t_llll				**i_address;		// an array of lllls, containing the current address for every iterated llll
	t_atom_long			*i_len;				// the lengths of all the iterated lllls
	long				*i_temporaries;		// the stack depth of the temporary sublist currently open
	long				i_movements;		// which way we're moving
	long				i_direction;		// the current direction
//	t_systhread_mutex	i_mutex;
//	t_bach_atomic_lock	i_inuse;
} t_llll_itercache;





// used by bach.sort and bach.msort
// this structure contains a term of comparison (that is, a hatom of the llll to sort)
// and a set of data with all the other stuff needed for outputting the hatom for the comparison outlet
typedef struct _llll_sort_item {
	t_hatom		n_term;		// the elem in the original
	long		n_idx;		// the index of the item in the original llll
	t_llll		*n_this_by;
	
	// fields if the outlet is native
	t_symbol	*n_n_sym;	// always bach.llll
	t_atom		*n_n_av;	// atom containing the llll phonenumber. native_ac is always 1 - so we don't need it!
	
	// fields if the outlet is text
	t_symbol	*n_t_sym;	// the message selector
	long		n_t_ac;		// ac
	t_atom		*n_t_av;	// av
	t_atom		*n_t_freeme;	// the atom* to free might not be n_t_av, so we use this instead
    
    
    // fields if the outlet is max
    t_symbol	*n_m_sym;	// the message selector
    long		n_m_ac;		// ac
    t_atom		*n_m_av;	// av
    t_atom		*n_m_freeme;	// the atom* to free might not be n_t_av, so we use this instead
    
} t_llll_sort_item;
// NB: in principle, bach.sort might have one of the two comparison outlet being native and the other being text
// so we can't use an union for the two output format, because we might need them both;





// a hash table with a trivial hashing function. it always has LLLL_IDX2PTR_SLOTS
// you give it something, and get a key to retrieve it
// it can be thread-safe or not (see shashtable_new) and should be extremely fast (especially in the latter 
typedef struct _shashtable {
	struct _simpll		*s_idx2ptr[BACH_SHASHTABLE_SLOTS];	// the index is the key, the llll* is the data
	t_atom_long_atomic	s_lastused;						// last phone number used (they are given in increasing order)
	t_systhread_mutex	s_mutex;
} t_shashtable;


// one of the linked lists of a phonebook
typedef struct _simpll {
	struct _simpllelem	*s_head;
	t_bach_atomic_lock	s_lock;
} t_simpll;

typedef struct _simpllelem {
	void				*s_thing;
	unsigned long		s_key;
	struct _simpllelem	*s_next;
} t_simpllelem;


// the bach NOBOX object
typedef struct _bach {
	t_object			b_ob;
	unsigned long		b_llll_version;
	
	t_llll				**b_llll_book; // an array of arrays of lllls
	t_uint32			**b_llll_phonebook;
	t_uint32			b_llll_current_phonebook_idx;
	t_uint32			b_llll_pool_size;
	t_bach_atomic_lock	b_llll_pool_lock;
	t_llll				b_llll_model;
	
	t_llllelem_numbered	**b_llllelem_book; // an actual array of llllelems
	t_uint32			**b_llllelem_phonebook;
	t_uint32			b_llllelem_current_phonebook_idx;
	t_uint32			b_llllelem_pool_size;
	t_bach_atomic_lock	b_llllelem_pool_lock;
	t_llllelem_numbered	b_llllelem_model;

	t_object			*b_initpargs; // the initpargs singleton object, which can call the "dopargs" method of all the registered bach.portal objects
    t_hashtab           *b_portalpatchers; // a table of all the patchers containing bach.portal objects, associated to lllls of the objects themselves
	
	long				*b_primes;
	t_hashtab			*b_memmap;
	t_hashtab			*b_poolmap;
	t_systhread_mutex	b_memmap_lock;
	
	t_hashtab			*b_helppatches;
	t_bool				b_loadtime;
} t_bach;


// some useful function pointer types

typedef long (*sort_fn)(void *data, t_llllelem *a, t_llllelem *b);

// called by llll_union, llll_intersection, llll_symdiff and llll_diff
typedef long (*sets_fn)(void *data, t_llllelem *a, t_llllelem *b);

// called by llll_find
typedef long (*find_fn)(void *data, t_llll *a);
typedef long (*llll_cmp_fn)(t_llll *a, t_llll *b);

// called by llll_funall; must return non-0 if a sublist is met and we don't want to enter it
typedef long (*fun_fn)(void *data, t_hatom *a, const t_llll *address);

// called by llll_iter
typedef long (*iter_datafn)(void *x, long list, t_llll *data, char isaddress); // isaddress is 0 if called as datafunc, 1 if called as addressfunc
typedef long (*iter_cmdfn)(void *x, long cmd);
typedef long (*iter_rootfn)(void *x);
typedef long (*iter_lambdafn)(void *x, t_llll *test_llll);

// called by llll_to_text_buf and llll_print
typedef char* (*text_buf_fn)(t_hatom *h, long maxdecimals);


typedef int (*qsort_fn) (const void *a, const void *b);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif




// set some important global variables
void bach_setup(t_bach *x);




// create a new llll from an array of atoms containing its textual representation
//
// special case:
// if ac == 1 and av is A_OBJ then atom_getobj(av) is cast to a char* from which the whole string is built
// but you are advised against using this feature (its details might change in some future)
// if you need to convert a string into a llll, use llll_from_text_buf instead
//
t_llll *llll_parse(long ac, t_atom *av);


// still uses the old, non-flex parser
// doesn't recognize pitches
// useful only for bw-compatibility in bach.tree
t_llll *llll_parse_with_leveltypes(long ac, t_atom *av); // same, with leveltypes

// does it contain spaces or parentheses?
long llll_contains_separators(char *txt);


// return a retained llll from a phonenumber
// NULL if the phonenumber is not valid
t_llll *llll_retrieve_from_phonenumber_and_retain(t_uint32 phonenumber);

// return the phonenumber of an llll
t_uint32 llll_phonenumber(t_llll *x);



// (private)
// initialize an empty llll
void llll_init(t_llll *x);
void llll_reset(t_llll *x);

// find the next non-space char
char *llll_next_thing(const char *where);



// (private)
// initialize an empty llllelem
void llllelem_init(t_llllelem *x);
void llllelem_reset(t_llllelem *x);







// returns the inferred "minimum" type from a string
// e.g., it returns H_LONG for "123", H_RAT for "-4/5", H_FLOAT for "+34.5e-12", A_SYM for "abc"
// recognize a leading +, and scientific e notation
e_hatom_types llll_typecheck(const char *txt);



// posts an llll in the Max window
// (it's the engine of bach.post)
// client is the object that will be highlighted when you click the max window (can be NULL)
// fn, if != NULL, will be passed any H_OBJ and H_LLLL (provided that its l_thing is != NULL), and its return value will be displayed
void llll_post(t_llll *ll, t_int32 mindepth = 1, t_int32 maxdepth = -1, t_atom_long max_decimals = 6, t_object *client = NULL, text_buf_fn fn = NULL);


/*
 name is the name to appear in the object field of the Max window
 besides this, see llll_post
 */
void llll_post_named(t_llll *ll, t_int32 mindepth, t_int32 maxdepth, t_atom_long max_decimals, t_symbol *name, text_buf_fn fn);


// private
void llll_post_named_do(void *dummy, t_symbol *name, long ac, t_atom *av);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// client is the object to display in the max window (can be NULL)
// fn, if != NULL, will be passed any H_OBJ and H_LLLL (provided that its l_thing is != NULL), and its return value will be displayed 
void llll_print(t_llll *ll, t_object *client = NULL, long error_message_type = 0, t_atom_long max_decimals = 6, text_buf_fn fn = NULL);

/*
 name is the name to appear in the object field of the Max window
 besides this, see llll_print
 */
void llll_print_named(t_llll *ll, t_symbol *name, long error_message_type, t_atom_long max_decimals, text_buf_fn fn);

// private
void llll_print_named_do(void *dummy, t_symbol *name, long ac, t_atom *av);

// private
void llll_printobject_free(t_object *printobj, t_symbol *name, long ac, t_atom *av);






// convert a llll in an array of atoms - typically used for generating the text format
// returns the number of atoms, or 0 if it can't allocate the memory it needs
// NB: an empty llll will be converted into "null" (so the return value is always >= 1 unless there is some trouble)
//
// if out is NULL, it will be initialized. 
// otherwise, it will be considered initialized - but it could be relocated by llll_deparse.
// offset is referred to *out (leaves some atoms at the beginning, useful for preset)
// flags are LLLL_D_QUOTE, LLLL_D_MAX and LLLL_D_FLOAT64
t_atom_long llll_deparse(t_llll *ll, t_atom **out, t_atom_long offset, char flags);


// same as before, but directly deparses to an atomarray
t_atomarray *llll_deparse_to_aa(t_llll *ll, char flags);


// returns a t_symbol with the backticked txt
t_symbol *sym_addquote(const char *txt);



// copy all the contents of from_ll into to_ll, and clears from_ll
void llll_transfer(t_llll *from_ll, t_llll *to_ll);


// what's in my llll?
// (engine of bach.contains)
t_atom_long llll_contains(t_llll *ll, t_int32 mindepth, t_int32 maxdepth);



// ---DESTRUCTIVE!
// reverse an llll
void llll_rev(t_llll *ll, t_int32 mindepth, t_int32 maxdepth); // ll must have at least 1 elem!



// ---DESTRUCTIVE!
// rotate an llll of shift steps
void llll_rot(t_llll *ll, t_int32 mindepth, t_int32 maxdepth, t_atom_long shift);


/// DESTRUCTIVE!
// rotate the base level of the current llll
void llll_rotatelevel(t_llll *ll, t_atom_long shift);


// return the address of the given element, with respect to base llll
// if base is NULL, the address will be relative to the top-level llll
t_llll *llll_get_address(t_llllelem *elem, t_llll *base);

// return the first element in root pointed by address, according to the address syntax
// if none can be found, returns NULL
t_llllelem *llll_nth_one(const t_llll *root, t_llll *address);

// return a llll with H_OBJ atoms pointing to each element in root pointed by address, according to the address syntax
t_llll *llll_nth_as_objs(t_llll *root, t_llll *address);

// return a llll with hatoms copied (and sublllls cloned) from each element in root pointed by address, according to the address syntax
t_llll *llll_nth(t_llll *root, t_llll *address, long nils);

// ---DESTRUCTIVE on ll
// substitute subs_model at address in ll
// or remove the corresponding element(s) if subs_model is empty
void llll_subs(t_llll *ll, t_llll *address, t_llll *subs_model);



// ---DESTRUCTIVE on ll, addresses, substitutions, sizes
// the contents of every sublist of substitutions will be replaced
// sizes contains, for each substitution, the number of original elements to be replaced; if empty, it will be considered as 0s.
// a 0 size will cause a null substitution to remove one element, and any other substitution to replace its own number of elements
// (i.e., a 3-element long substitution will replace 3 elements)
// a non-0 size will cause the corresponding number of elements to be replaced or removed, regardless of the size of the substitution
void llll_multisubs(t_llll *ll, t_llll *addresses, t_llll *substitutions, t_llll *sizes);

// --- DESTRUCTIVE on ll (elements are inserted), addresses (is sorted) and insertions (is sorted)
// the engine of bach.insert @mode 0
void llll_multiinsert_a(t_llll *ll, t_llll *addresses, t_llll *insertions);

// --- DESTRUCTIVE on ll (elements are inserted), addresses (is sorted) and insertions (is sorted)
// the engine of bach.insert @mode 1
void llll_multiinsert_b(t_llll *ll, t_llll *addresses, t_llll *insertions);

// --- DESTRUCTIVE
// lengthen ll up to newsize by repeating its last element
void llll_tailpad_with_last(t_llll *ll, long newsize);

// --- DESTRUCTIVE
// shorten ll down to newsize by removing its last elements
void llll_tailtrim(t_llll *ll, long newsize);

// --- DESTRUCTIVE on insertion and the llll containing target
// insert the contents of insertion after target (if direction >= 0) or before target (if direction < 0)
void llll_insert_one(t_llllelem *target, t_llll *insertion, long direction);



// ---DESTRUCTIVE on root (but only if create != 0), baby_llll and directions
// gets the llllelem pointed by address (the syntax of address is the address syntax of bach.nth)
// root is the root of the search space - i.e., the base-list to search in
// if create != 0, a non-existing llllelems are created and set to nil
// baby_llll is an empty llll that will contain H_OBJs pointing to each found llllelem
// directions can be NULL, or an empty llll that will be filled with a series of 1 and -1
// each 1 corresponds to a llll level that has been searched forward,
// each -1 to a llll level that has been searched backwards
void llll_findchildren(const t_llll *root, t_llll *address, long create, t_llll *baby_llll, t_llll *directions); // wants 2 empty lllls


// --- DESTRUCTIVE on ll (edits it to create new addresses) if create_elems and force_create_lists are set
// a more efficient way to simply search an llll for multiple elements, each pointed by a sublist of addresses
// if an element of addresses is not a sublist, it will be treated as a root-level address (i.e., as if it was a single-element sublist).
// returns an array of elements, the same size as addresses.
// non-existing elements are created when possible, otherwise returned as NULL
// Don't use mark_created_targets if you're requesting more than one address!
t_llllelem **llll_find_multiple_elems(t_llll *ll, t_llll *addresses, t_bool create_elems, t_bool force_create_lists, t_bool mark_created_targets);








/*
 iterate on lists, according to the modes (see bach.iter's help files)
 if you provide it a cache, it will only do one step, and put the result in the cache.
 in this case, it will return 0 if the list is over, 1 otherwise.
 The functions are called back once for every input llll at every step (unless the case in which no element has to be output), with:
 - datax/addressx/cmdx/lambdax as their first argument (most often, you will want to pass your calling object)
 - list is the index of the llll we're currently referring
 - llll is a newly-created (and owned by llll_iter) llll, which contains the currently iterated element
 - cmd is the command (again, see the bach.iter's help file)
 - lambdafn is a callback function that is called everytime a new subll is going to be entered. See below for details. Can also be NULL.
 if one of those function returns non-zero, the iteration stop.

 ABOUT lambdafn:
 the callback function is passed void* (typically the calling object), array of lllls, and an array of elements, and an array of addresses, all of size <lists>.

 -	the elements are the elements we're about to enter.
	they can hold an H_LLLL atom, of which the contained llll is going to be entered. at least one H_LLLL atom is always present.
	or a non-H_LLLL atom, in which case a virtual sublist is about to be created, and the atom is going to be iterated against the other sublists.
	or an element can be NULL, which means that all the elements of its containing llll have already been iterated.
	You can check out each element's parent llll.
 -	the addresses are actually lllls, each containing the address of the element about to be entered.
 the callback function should return 0 to prevent the sublists from being entered, 1 to allow them
 IMPORTANT: you can't perform destructive operations, nor output from the outlets, the data you receive from the callback function.
 If you need to, clone them first!
 
 NB that this is only useful in very specific cases, 
 usually involving synchronization of many iterations, and/or complex interaction with other objects
 currently, it is used by bach.iter, bach.expr and bach.step
 You will usually want to iterate through a list with a for cycle
 if you want to iterate depth-first, you are advised to take advantage of the stack structure and API we provide,
 rather than adopting a recursive approach that would be noticeably slower and memory-hungry.
 Or, even better, you can call llll_funall()
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
			   iter_lambdafn lambdafn, void *lambdax);






/*
 iterate on an llll, calling fn on every element. (see the definition of fun_fn for more details)
 You can alter the contents of the hatoms passed to fn, 
 but you can't output the sub-lllls they contain without cloning them, and you can't modify the structure of the llll, with one exception (see below *).
 Moreover, you can't modify or output the address passed to fn (but of course you can output/modify a clone of it).
 
 flags: see e_llll_funall_flags,
 If sublists != 0, before entering a sublist the hatom containing the sublist itself is output.
 If fn returns non-0, the sublist will not be entered.
 This applies to the main llll as well: a temporary hatom is created, containing it, and the iteration is not performed if fn returns non-0.
 When the main llll is output, address is an empty llll
 
 * How can you alter the llll structure?
 When a sublist is output, you can alter its contents as you like from within your callback function before returning control to llll_funall, 
 provided that the sublist remains valid.
 Not too bad, huh?
 */

void llll_funall(t_llll *x, fun_fn fn, void *data, t_int32 mindepth, t_int32 maxdepth, long flags = 0);










// STUFF FOR SORTING
// you will usually only use llll_inplacesort() and llll_multisort()
// llll_leq_elem and friends are typical comparison functions you will want to use


/*
 --- DESTRUCTIVE on ll (its elements are sorted)
 data is passed to cmpfn as its first element
 the algorithm is mergesort (stable!)
 l_things, if present, are preserved
 */
void llll_inplacesort(t_llll *ll, sort_fn cmpfn = (sort_fn) llll_leq_elem, void *data = NULL);







/*
 ---DESTRUCTIVE--- on in

 --- semi-deprecated
 
 out is an uninitialised pointer
 
 data is passed unchanged to cmpfn at each call
 bach.sort and bach.msort use it to pass themselves to their comparison output function
 
 cmpfn must return 0 if the elements must be swapped, 1 otherwise
 
 */

void llll_mergesort(t_llll *in, t_llll **out, sort_fn cmpfn, void *data);

// as above, but lthing field is preserved (just a little bit slower) - semi-deprecated
void llll_mergesort_with_lthings(t_llll *in, t_llll **out, sort_fn cmpfn, void *data);




// used by bach.sort and bach.msort
// formats a llll before the sorting algorithm for outputting its elements one by one
void llll_prepare_sort_data(t_object *x, t_llll *ll, t_llll *by, long outtypes);



// used by bach.sort and bach.msort
// to be called after llll_mergesort to discard the formatting imposed by llll_prepare_sort_data
void llll_retrieve_sort_data(t_object *x, t_llll *ll, t_llll *idx_ll, t_atom_long depth);


// (private)
void llll_inplacesort_move_elem(t_llll *ll, t_llllelem *a, t_llllelem *b);



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
void llll_multisort(t_llll **inlist, t_llll **outlist, long num, sort_fn cmpfn);


// (private) - an intermediary between llll_inplacesort and its cmpfn
long llll_objcmpfn(sort_fn cmpfn, t_llllelem *a, t_llllelem *b);

// (private) - an intermediary between llll_multisort and its cmpfn
long llll_multisort_fn(sort_fn cmpfn, t_llllelem *a, t_llllelem *b);





///////////////////////////////////////////////////////////////////////////////////

// DESTRUCTIVE (in_ll is freed)
// matrix transposition of an llll
// mode: iterationmode
t_llll *llll_trans(t_llll *in_ll, long mode);


// DESTRUCTIVE (in_ll is transposed)
// in-place matrix transposition of an llll
// mode: iterationmode
void llll_trans_inplace(t_llll *in_ll, long mode);


// DESTRUCTIVE on in_ll (in_ll is transposed)
// in-place matrix transposition of an llll
// depth: sequence of the depth levels to be transposed
// mode: iterationmode
void llll_trans_extended(t_llll *in_ll, t_llll *depth, long mode);


// DESTRUCTIVE!
// randomly permutes the elements of the root list and the sublists up to maxdepth
void llll_scramble(t_llll *ll, t_int32 mindepth, t_int32 maxdepth);


// sum += a (or stays unchanged if a is not a number); address is ignored
void llll_sum_one(t_hatom *sum, const t_hatom *a, const t_llll *address);


// calculate the sum of all the numbers in ll, and put it into sum
t_max_err llll_sum(t_llll *ll, t_hatom *sum, t_int32 mindepth, t_int32 maxdepth);


// find the minimum, maximum, address of the minimum and address of the maximum number in a list
void llll_minmax(t_llll *ll, t_hatom **min, t_hatom **max, t_llll *minaddress, t_llll *maxaddress, t_int32 mindepth, t_int32 maxdepth);



/*
 ---DESTRUCTIVE---
 return a llll with all the permutations of ll as sublists
 based on the algorithm described in http://en.wikipedia.org/wiki/Permutation#Software_implementations
 */
t_llll *llll_perm(t_llll *ll, t_atom_long maxcount);



// ---DESTRUCTIVE
// return the next permutation of inlist
// order = 0 => ascending, order != 0 => descending
// circular != 0 => the last possible permutation is followed by the first one
// circular == 0 => the last possible permutation is followed by NULL
t_llll *llll_oneperm(t_llll *inlist, long order, long circular);



// return all the combinations of the elements in ll of size between startk and endk
// endk < 0 is converted in ll->size (this means that startk = 0, endk = -1 will return all the combinations)
// the combinations are grouped in sublists according to their size, e.g.
// ((1) (2) (3)) ((1 2) (2 3) (1 3)) ((1 2 3))
t_llll *llll_comb(t_llll *ll, t_atom_long startk, t_atom_long endk);


// return the cartesian product of the lllls contained in inll. count is the size of the array
t_llll *llll_cartesianprod(t_llll **inll, long count);


// return an llll with all the elements for which cmpfn returns non-0
// addresses: an initialized llll which will contain the addresses of the elements, or NULL if you don't want to retrieve them
// what_size: size of the llll to pass at each call to cmpfn
// min_lvl, max_lvl: minimum and maximum levels to search (can be negative as well)
// min_pos, max_pos: minimum and maximum index to search
// idx_reject, depth_reject: invert the length-wise / depth-wise search space
// max_count: after how many findings to stop (0 = no maximum)
// recursive: if a match is found and it's a LLLL, do I look into it as well?
// data: passed unchanged to cmpfn (tipically, the calling object)
t_llll *llll_find(t_llll *ll, t_llll *addresses, t_atom_long what_size, t_atom_long min_lvl, t_atom_long max_lvl, t_atom_long min_idx, t_atom_long max_idx, 
				  long idx_reject, long depth_reject, t_atom_long max_count, long recursive, long unwrap, long depthpolicy, long matchdepth, find_fn cmpfn, void *data);


///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE--- (inplace)
// for each element, look for equal elements (according to fn) and delete them
// O(n^2) - a more efficient algorithm for specific cases (where a <= operation is also defined) might be implemented
// this would require sorting the llll, then only comparing neighbour elements, and finally restore the original order
// the complexity in this case would be O(nlogn), that is the complexity of mergesort.
// on the other hand, this would require lots of memory allocations and other stuff like that
// and for this reason it would become more efficient than this only for very long lists.
// The return value is ll
t_llll *llll_thin(t_llll *ll, sort_fn fn, void *data = NULL);


// --- DESTRUCTIVE --- (inplace)
// The simpler O(nlogn) version
// The return value is ll
t_llll *llll_thin_simple(t_llll *ll, long matchtype);

// compare the l_thing fields of two elements
long llll_cmp_elems_by_lthings(void *dummy, t_llllelem *a, t_llllelem *b);





///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE--- (inplace)
// for each element, look for equal elements (according to fn) and group them together
// O(n^2) - a more efficient algorithm for specific cases (where a <= operation is also defined) might be implemented
t_llll *llll_classify(t_llll *ll, sort_fn fn, void *data);


// --- DESTRUCTIVE --- (inplace)
// The simpler O(nlogn) version
// The return value is ll
t_llll *llll_classify_simple(t_llll *ll, long matchtype);



///////////////////////////////////////////////////////////////////////////////////////////////////
// ---DESTRUCTIVE--- on ll
// inserts inside a ll (subs_model) in another (ll) at a given address (address)
// if the address is multiple, many copies of subs_model will be inserted
void llll_insert_llll_at_address(t_llll *ll, t_llll *address, t_llll *subs_model);


// ---DESTRUCTIVE - inplace
// flatten ll between mindepth and maxdepth
// spikemode 1 makes a () appear in place of a )(
// freething sets whether and how the l_thing field of lllls must be freed
void llll_flat(t_llll *ll, t_int32 minlevel, t_int32 maxlevel, long spikemode = 0, e_freething_modes freething = LLLL_FREETHING_DONT);

// ---DESTRUCTIVE - inplace
// flatten ll up to maxdepth
// spikemode 1 makes a () appear in place of a )(
void llll_flatten(t_llll *ll, t_int32 maxdepth, long spikemode);


// ---DESTRUCTIVE
// wraps *ll in lvls levels of parentheses (see bach.flat)
// the original *ll becomes a sublist of the resulting *ll
void llll_wrap(t_llll **ll, t_atom_long lvls = 1);

// ---DESTRUCTIVE--- - inplace
// remove a couple of parentheses around an H_LLLL element
// i.e., from 1 (2 3) (4) to 1 2 3 (4) if it's passed the element (2 3)
// works in place: the addresses of the elements of the sublist don't change
t_max_err llll_splatter(t_llllelem *elem, e_freething_modes freething);

// --- DESTRUCTIVE - inplace
// all the elements from from to to are wrapped up one level
t_llll *llll_wrap_element_range(t_llllelem *from, t_llllelem *to);


// ---DESTRUCTIVE - inplace
// slice a llll at idx position
// ll becomes the left slice, right slice is returned
t_llll *llll_slice(t_llll *ll, t_atom_long idx);



// ---DESTRUCTIVE---
// de-interlace a ll in an array of outlists lllls
// the 0th element of the returned array is ll (whose contents have changed, of course)
t_llll **llll_delace(t_llll *ll, long outlists);



// ---DESTRUCTIVE---
// de-interlace a ll as an llll with sublists
// the 0th element of the returned llll is ll (whose contents have changed, of course)
t_llll *llll_mdelace(t_llll *ll, long outlists);



// ---DESTRUCTIVE---
// interlace an array of count lllls
// iterationmode works the usual way (see help file for bach.lace)
t_llll *llll_lace(t_llll **lists, t_atom_long count, long iterationmode);


// ---DESTRUCTIVE on ll
// impose the structure of modelll upon inll
void llll_reshape(t_llll *ll, t_llll *modelll, llll_clone_fn fn = NULL);

/*
 ---DESTRUCTIVE
 divide an llll in modulo-sized lllls (or smaller, at the end of the original llll)
 e.g. 1 2 3 4 5 6 7 8 with modulo 3 => (1 2 3) (4 5 6) (7 8)
 return MAX_ERR_GENERIC if the modulos and overlaps are not compatible 
 (in which case, anyway, the overlap is adjusted so as to be smaller than the modulo)
 */
t_max_err llll_groupllll(t_llll *ll, t_atom_long modulo, t_atom_long overlap);
t_max_err llll_multigroupllll(t_llll *ll, t_llll *modulos, t_atom_long overlap, long circular_pad);


///////////////////////////
// lllls AS SETS
// all these functions are destructive on both lists
// cmpfn is used to determine the equality of two elements,
// but NB: it accepts a void* and two lllls, so you can't use llll_eq_matchtype or llll_eq_ignoretype
// in fact, those function are optimized for using in patch, not for calling them from code
// all these functions are O(nˆ2) if cmpfn is non-NULL, otherwise O(nlogn)
void llll_union(t_llll *in_ll1, t_llll *in_ll2, sets_fn cmpfn = NULL, void *data = NULL);
void llll_intersection(t_llll *in_ll1, t_llll *in_ll2, sets_fn cmpfn = NULL, void *data = NULL);
void llll_symdiff(t_llll *in_ll1, t_llll *in_ll2, sets_fn cmpfn = NULL, void *data = NULL);
void llll_diff(t_llll *in_ll1, t_llll *in_ll2, sets_fn cmpfn = NULL, void *data = NULL);



////////////////////////////
// STUFF WITH PRIMES

// is what a prime?
long llll_prime(long what);


// factorization
// eg 12 = 2^2 * 3^1, so (2 2) (3 1) will be returned
t_llll *llll_factorize(long what);


// return the series of primes from min to max, up to a maximum size of maxcount (0 = no maximum)
t_llll *llll_primeser(long min, long max, long maxcount);


// return an arithmetic series (see bach.arithmser)
t_llll *llll_arithmser(t_hatom start_hatom, t_hatom end_hatom, t_hatom step_hatom, t_atom_long maxcount, t_object *culprit = NULL);

// return a geometric series (see bach.arithmser)
t_llll *llll_geomser(t_object *x, t_hatom start_hatom, t_hatom end_hatom, t_hatom factor_hatom, t_atom_long maxcount, long *err);




///////////////////////////////////////////////////////////////////////
// CONSTRUCTORS, DESTRUCTORS & c



// frees all the elements in a llll (regardless of its flag)
void llll_clear(t_llll *x);
void llll_clear_nocheck(t_llll *x);

// frees a list, but not the elements it contains
void llll_chuck(t_llll *x);

// frees a list, but not the elements it contains, without checking for bad sublists
void llll_chuck_nocheck(t_llll *x);

// frees a llllelem, but not the llll it contains
// NB: to correctly remove an element from a llll, 
// you must use llll_destroyelem() 
void llllelem_chuck(t_llllelem *x);



// swap places of el1 and el2, even if they belong to different lllls.
// el1 and el2 must not contain one another, or MAX_ERR_GENERIC is returned
// if they are the same element, nothing bad happens - and nothing happens, of course!
// DEPRECATED
t_max_err llll_swapelems(t_llllelem *el1, t_llllelem *el2);

// DESTRUCTIVE on a->l_parein
// as above, but only the contents of the elements are swapped
t_max_err llll_swaphatoms(t_llllelem *a, t_llllelem *b);

// properly removes an element from a llll
void llll_destroyelem(t_llllelem *killme);

// as above, but doesn't fix the depth (much faster, but use with care!)
void llll_destroyelem_no_depth_check(t_llllelem *killme);

// set the owner of every element of child as adopter, if != WHITENULL 
void llll_adopt(t_llll *child, t_llll *adopter);

// DESTRUCTIVE!
// chain two lllls one after another
void llll_chain(t_llll *x, t_llll *giver);
void llll_rchain(t_llll *giver, t_llll *x);


// return the pos-th element of the list
// can accept negative index (for counting from the end) and see the list as circular, if the appropriate mode is set
// (see documentation for e_llll_index_modes)
// NB: the actual llllelem (not a copy) is returned 
t_llllelem *llll_getindex(t_llll *ll, t_atom_long pos, e_llll_index_modes mode);


// return the root of ll
t_llll *llll_root(const t_llll *ll);

// just put a breakpoint in there to see what's wrong!
t_max_err llll_check_error(t_llll_stack *stack, long *depths_arr, long *lengths_arr);
t_max_err bach_check_phonenumber_error(void);

// check the correctness of the phonenumber (phonenumbers are not arbitrary!)
// exclude it from release builds!
t_max_err llll_check_phonenumber(const t_llll *ll);

// check the correctness of the phonenumber
// exclude it from release build!
// el can be a casted t_llllelem
t_max_err llllelem_check_phonenumber(const t_llllelem_numbered *el);


/////////////////////////////////////////////////
// STACK STUFF
//
// stacks are often used to keep track of in-depth traversal of lllls
// although they should be replaced with a more efficient, array-based mechanism
// there is no thread-safety mechanisms

// create a t_llll_stack
// this is not a t_object!
t_llll_stack *llll_stack_new(void);

// destroy a t_llll_stack
// this is not thread-safe
void llll_stack_destroy(t_llll_stack *x);

// push thing into x
// this is not thread-safe
void llll_stack_push(t_llll_stack *x, void *thing);

// pop thing from x
// this is not thread-safe
void *llll_stack_pop(t_llll_stack *x);



////////////////////////////////////////////////////////////
// FORMAT CONVERSIONS

// convert a llll to text
// returns the size of *buf (including offset)
// if *buf is NULL, it will be allocated and must be freed with bach_freeptr(). if it's not, it might as well be relocated!
// offset is relative to *buf
// max_decimals is used when converting doubles to string
// for flags see e_llll_text_flags
// it is mainly used by the write functions, but can be very helpful for debugging as well
// if fn != NULL, it is called for every hatom that is met.
// fn must return a char* to be put in the buffer instead of the standard thing,
// or NULL (in which case the standard format will be used)
// the return value of fn will then be freed by llll_to_text_buf
t_atom_long llll_to_text_buf(t_llll *ll, char **buf, t_atom_long offset = 0, t_atom_long max_decimals = 6,
                             long flags = 0, text_buf_fn fn = NULL, t_bool leave_final_space = false);

// as llll_to_text_buf, with some extra formatting:
// wrap is the maximum length of one line of the output buffer; if wrap == 0, no word wrapping is performed
// indent is the indentation string per llll level (it will usually be a tab or a sequence of spaces)
//   if indent set to NULL, sublists are not placed in new lines; to go to newlines without indenting, use ""
// maxdepth is the maximum depth at which sublists should be placed in new lines
t_atom_long llll_to_text_buf_pretty(t_llll *ll, char **buf, t_atom_long offset = 0, t_atom_long max_decimals = 6,
                                    t_atom_long wrap = 0, const char *indent = NULL, t_atom_long maxdepth = -1,
                                    long flags = 0, text_buf_fn fn = NULL);

t_atom_long hatom_to_text_buf(t_hatom *a, char **buf, t_atom_long offset = 0, t_atom_long max_decimals = 6, long flags = 0, text_buf_fn fn = NULL);

// not working
t_atom_long llll_to_text_buf_limited(t_llll *ll, char **buf, long max_size, t_atom_long offset = 0, t_atom_long max_decimals = 6, long flags = 0, text_buf_fn fn = NULL);


// DEPRECATED! use llll_store_in_dictionary() instead
// convert an llll to a native buffer
t_atom_long llll_to_native_buf(t_llll *in_llll, char **buf);

// creates a llll from a text buffer
t_llll *llll_from_text_buf(const char *txtbuf);


// retrieve a list from a native buffer of ac size
// native buffer is a proprietary binary format used for saving a llll into a file
// don't call this function yourself
// if you need to save a llll, use the llll_files high-level API instead
t_llll *llll_from_native_buf(char *buf, t_atom_long ac);

// store an llll of arbitrary length into a dictionary
// header is a string that will be used as a prefix for a set of entries in the dictionary
// if you plan to store more than one llll in the dictionary, each must have a header of its own
// you can pass a lock pointer, in which case the reading of the llll is locked
// or you can pass NULL for the lock, in which case there is no thread protection
// (in both cases, the access to the dictionary is inherently thread-safe)
t_max_err llll_store_in_dictionary(t_llll *ll, t_dictionary *dict, const char *header, t_bach_atomic_lock *lock);

// retrieve from a dictionary an llll
// header is the "family name" of the keys containing the llll
t_llll *llll_retrieve_from_dictionary(t_dictionary *dict, const char *header);
t_llll *llll_retrieve_from_dictionary_with_leveltypes(t_dictionary *dict, const char *header);


/////////////////////////////////////////
// SHASHTABLE FUNCTIONS
// the shashtable is a small thingy that stores something you can retrieve with a numeric key
// works best when you let it choose the key!
// it doesn't own the things it stores

// create a new, empty shashtable
// if reentrant is non-0, the shashtable is thread-safe
t_shashtable *shashtable_new(long reentrant);

// free the shashtable
// n.b.: doesn't free the things it contains!
void shashtable_free(t_shashtable *x);

// insert a thing in the shashtable with a new key, and return the key
// use this whenever you can, instead of shashtable_insert_with_key()
t_atom_ulong shashtable_insert(t_shashtable *x, void *thing);

// insert a thing in the shashtable with the given key
// force determines what happens if an item with the same key was already present
// if force is 0, the former element is kept, otherwise it is replaced
// returns the former thing, if any
// don't use this if you can use shashtable_insert()
void *shashtable_insert_with_key(t_shashtable *x, void *thing, t_atom_ulong key, long force);

// retrieve a thing from the shashtable
void *shashtable_retrieve(t_shashtable *x, t_atom_ulong key);

// remove a thing from the shashtable
// this will not free the thing, of course!
void shashtable_chuck_thing(t_shashtable *x, t_atom_ulong key);

// reset the key count - the next key you'll get will be 1
// the shashtable must be empty when you call this function!
void shashtable_reset_keys(t_shashtable *x);

// insert thing with the given key into sll
// the insertion is sorted key-wise
void simpll_insert_sorted(t_simpll *tll, void *thing, t_atom_ulong key);

// PRIVATE!
// remove an element from sll
void simpll_chuck_key(t_simpll *sll, t_atom_ulong key);

// VERY USEFUL!	convert a text in a series of atoms of any length!
void llll_text2atoms(char *text, long *ac, t_atom **av);


/////////////////////////////////////////
// WEIRD STUFF FOR DANIELE ;)
/**
 INPLACE!
 for every sublist (including the main list) containing both sublists and simple elements,
 for every sequence of 1 or more simple elements create a new sublist and put them into it:
 that is, find any "plain" and make it a "plateau"
 e.g., from
 (1/60) (1/60) 1/60 1/60 1/60 1/12 1/12 ((1/8 1/8) 1/8 1/8) 1/4
 obtain
 (1/60) (1/60) (1/60 1/60 1/60 1/12 1/12) ((1/8 1/8) (1/8 1/8)) (1/4)
 with min_plateau_len you can specify a minimum number of contiguous elements to form a plateau
 if the number is not reached, the plateau is not created
 plateaus_ll, if not NULL, gets filled with H_OBJ, each pointing to one of the new H_LLLL elements
 */

void llll_plateaus(t_llll *ll, t_atom_long min_plateau_len, t_int32 maxdepth, t_llll *plateaus_ll);

/**
 INPLACE!
 for every root-level non-llll element, wrap it into an llll
 e.g., from 1 2 (3 4) 5
 obtain (1) (2) (3 4) (5)
 */
void llll_fatten(t_llll *ll);

/*
 create an llll according to the rule:
 - the first element of the outllll is a sublist of H_OBJ, each pointing to an element at the first level of depth of the input llll
 - the second element is as above, but contains pointers to the second level of the input llll
 ... and so on.
 so, the length of the output level will be equal to the depth of the input llll
 
 BEWARE: the elements of the input llll still belong to it, and not to the output llll!
 */

t_llll *llll_scan(t_llll *in_llll, long sublists);

/*
 should be quite like postatom, but doesn't really work (postatom's fault!)
 */
void llll_posthatom(t_hatom *hatom);

long llll_parseargs(t_object *x, t_llll *ll, const char *types, ...);
long llll_parseattrs(t_object *x, t_llll *ll, char destructive, const char *types, ...);

#define llll_parseargs_and_attrs(x,ll,types,...) { llll_parseargs(NULL,ll,types,__VA_ARGS__); llll_parseattrs(x,ll,false,types,__VA_ARGS__); }
#define llll_parseargs_and_attrs_destructive(x,ll,types,...) { llll_parseargs(NULL,ll,types,__VA_ARGS__); llll_parseattrs(x,ll,true,types,__VA_ARGS__); }


t_llll *llll_develop_ranges(t_llll *ll);
void llll_put_elems_in_lllls_in_lthing(t_llll *ll);
void llll_remove_lllls_from_lthing(t_llll *ll);



#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _LLLL_COMMONS_H_	