/*
 *  hatom.h
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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

#ifndef _HATOM_H_
#define _HATOM_H_

#include "foundation/bach.h"

#ifdef BACH_MAX
#include "ext.h"
#include "ext_obex.h"
#include "ext_systhread.h"
#endif

#ifdef BACH_JUCE    
#include "bach_jucewrapper.h"
#endif

#ifdef BACH_JITCLANG
#include "bach_jitclang.h"
#endif

#include "math/bach_pitch.hpp"
#include "foundation/llll_commonsyms.h"

#ifdef C74_X64
#include "math/bach_128bit.h"
#endif

typedef t_int32_atomic t_bach_atomic_lock;


/////
// BEWARE: THIS IS NOT A REAL RWLOCK (TODO!!!) - it's just an ordinary spinlock
// - and anyway it's probably unused (to be cleaned up...)
typedef struct _bach_rwlock {
    t_bach_atomic_lock    r_lock;
    //t_int32_atomic        r_readers;
} t_bach_rwlock;


#ifdef BACH_TRACK_MEMORY_ALLOCATION
//
// stuff for memory debugging
//
typedef union _mword {
    char                                *w_char;
    short                                *w_short;
    int                                    *w_int;
    long                                *w_long;
    t_atom_long                            *w_atom_long;
    double                                *w_double;
    t_rational                          *w_rational;
    t_pitch                             *w_pitch;
    t_object                            *w_object;
    struct _llllelem                    *w_llllelem;
    struct _llll                        *w_llll;
    t_object                            **w_object_arr;
    struct _llllelem                    **w_llllelem_arr;
    struct _llll                        **w_llll_arr;
    struct _rhythm_level_properties        *w_rhythm_level_properties;
    void                                *w_void;
} t_mword;

typedef struct _mframe {
    char    s_string[128];
    void    *s_address;
} t_mframe;

typedef struct _memmap_item {
    t_mword            m_word;        // the memory address
    long            m_size;        // the size of the allocated memory
    t_symbol        *m_name;    // the data type
    long            m_count;    // reference count
    t_mframe        m_stack[12];
    t_int32_atomic    m_order;
} t_memmap_item;
#endif



/*
 Not all the items of the enum here are actually valid hatom types.
 Note that, unlike the Max atom types, they actually are bit flags:
 this allows to represent combinations of types within one variable.
 */
typedef enum _hatom_types {
    H_NOTHING       = 0x00000000,
    H_NULL          = 0x00000001,    // special type, used by llll_contains() and llll_is()
    H_LONG          = 0x00000002,
    H_RAT           = 0x00000004,
    H_DOUBLE        = 0x00000008,
    H_SYM           = 0x00000010,
    H_LLLL          = 0x00000020,
    H_OBJ           = 0x00000040,
    H_POP           = 0x00000080,    // special type, used by llll_from_native_buf() and the deprecated llll_save_as_native_buf()
    H_PITCH         = 0x00000100,
    H_STRING        = 0x00000200,
    H_FUNCTION      = 0x00000400,   // a function
    
    H_PAREN         = 0x00010000,   // modifier, indicating that a symbol contains parens
    H_SEPARATOR     = 0x00020000,   // modifier, indicating that a symbol contains separators (whitespace, comma, semicolon)
    H_SPECIAL       = 0x00040000,   // modifier, indicating that a symbol contains backslashes and/or double quotes
    H_BACKTICK      = 0x00100000,   // modifier, indicating that a symbol starts with a backtick
    
    H_PLAINTYPE     = 0x0000FFFF,   // bitmask for only retrieving the plain type
    H_MODIFIERS     = 0xFFFF0000,   // bitmask for only retrieving the modifiers
    H_ALL           = 0xFFFFFFFF,    // special type, only used by lexpr
} e_hatom_types;

//#define H_NUMBER (H_LONG | H_RAT | H_DOUBLE)

class t_function;

// A piece of data that can be contained in an hatom.
// On a 32-bit architecture, it is 64 bit wide.
// On a 64-bit architecture, it is 128 bit wide.
typedef union _hword
{
    t_atom_long w_long;                // long integer (32-bit or 64-bit according to the platform)
    double w_double;                // 64-bit float (on both architectures!)
    t_rational w_rat;                // a rational, composed by two t_atom_long
    t_pitch w_pitch;                // a pitch, represented in terms of "white key", alteration and octave
    t_symbol *w_sym;                // pointer to a symbol in the Max symbol table
    struct _llll *w_llll;            // an llll
    void *w_obj;                    // pointer to a #t_object or other generic pointer
    t_function *w_func;             // pointer to a function (private and only partially supported)
    t_atom_ulong w_ulong;            // long unsigned integer (32-bit or 64-bit according to the platform)
    struct _llllelem *w_llllelem;    // an llllelem
#ifdef C74_X64
    t_uint64 w_whole[2];            // only used to hackily access the whole 128-bit field; probably deprecable
#else
    t_uint64 w_whole;                // only used to hackily access the whole 64-bit field; probably deprecable
#endif
} t_hword;


// A heavy atom, that is the llll equivalent of a Max atom.
// llllelems contain hatoms, rather than plain atoms.
typedef struct _hatom
{
    t_hword h_w;
    t_uint32 h_type;
} t_hatom;


// A place to store whatever you want, whatever you like
// (see the l_thing fields of t_llllelem and t_llll)
// The idea is that this is a very private place,
// and whenever you use it you should always take care of restoring it to its previous value
// (which, in most cases, is zero), unless you are about to free the llll or llllelem that contains it.
// llll_free_freethings() and llllelem_free_freethings()
// deal with what should be done to l_thing when its container is freed.
//
// You probably don't want to use l_thing altogether...
typedef union thingword
{
    t_atom_long            w_long;
    t_atom_ulong        w_ulong;
    double                w_double;
    t_rational          w_rat;
    t_urrational        w_urrat;
    t_pitch             w_pitch;
    struct _llll        *w_llll;
    struct _llllelem    *w_llllelem;
    void                *w_obj;
    t_function          *w_func;
    t_int64                w_whole;
} t_thingword;

/*
 An element of an llll. (see below: t_llll)
 You create one with llllelem_get(), and free it with llllelem_free()
 When you free an llllelem containing an llll, the llll is freed as well 
 (and the llllelems it contains, and so on) unless OBJ_FLAG_DATA is set.
 
 The core of an llllelem is its l_hatom field, that is a t_hatom struct.
 You may want to have a look at it!
 */

typedef struct _llllelem
{
    t_hatom                l_hatom;    // the actual data - note that this is not a pointer
    struct _llllelem    *l_prev;    // pointer to the previous element in the list
    struct _llllelem    *l_next;    // pointer to the next element
    struct _llll        *l_parent;    // pointer to the list containing the element
    t_thingword            l_thing;    // whatever you want, whatever you like - but always zero it before outputting the llll
#ifdef BACH_USE_MAGIC_NUMBER
    t_uint32            l_magic;    // magic number, BACH_MAGIC_GOOD if the object is valid - semi-deprecated
#endif
    t_int32                l_flags;    // OBJ_FLAG_OBJ: free the possibly contained llll - OBJ_FLAG_DATA: don't
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
#ifdef BACH_SAVE_STACK_IN_LLLLS
    t_mframe            l_alloc_stack[16];    // for badass debugging purposes
    t_mframe            l_free_stack[16];    // for badass debugging purposes
#endif
#endif
} t_llllelem;


// an llllelem with an id. only used for low-level object pool management
typedef struct _llllelem_numbered
{
    t_llllelem    l_elem;            // the llllelem
    t_uint32    l_phonenumber;    // its id
} t_llllelem_numbered;


/*
 The llll data structure:
 a doubly-linked list containing llllelems (see above: t_llllelem),
 with a notion for its place in the structure.
 This allows you to find the parent llll (via my_llll->l_owner->l_parent).
 If you manually tweak the contents of your llll, you must be sure that the ownerships and parenthoods are correctly maintained.
 If you do it with the API functions, they are generally maintained for you.
 The llll also has a notion of depth, which is automatically maintained if you manage the list via its API functions.
 But if you directly tweak the fields of the list, you have to take care that the depth is correctly updated.
 The functions llll_upgrade_depth() and llll_downgrade_depth() may help with this in most cases.
 
 To obtain a valid, empty llll, use llll_get()
 To convert a Max message or a string in an llll, use llll_parse() or llll_parse_with_leveltypes()
 To increment or decrement the reference count for an llll, use llll_retain() or llll_release(). If the count reaches 0, the llll is freed.
 There is also llll_free(), which is actually the same as llll_release().
 All this lifecycle stuff involves an object pool maintained by bach, 
 and memory claimed for lllls or llllelems is never really freed.
 To check for memory leaks, send the message [;bach poolstatus] and look at the Max window. 
 If there is no open patch containing llll-compatible objects,
 llll_current_phonebook_idx and llllelem_current_phonebook_idx should both be 0. If not, something has not been freed.
 In general, don't worry about llll_pool_size and llllelem_pool_size.
 
 When you free an llll, every llllelem it contains is freed unless OBJ_FLAG_DATA is set.
 This happens recursively, so in the standard case freeing a llll also frees all its sublists and its sublist's sublists and so on.
 
 Other useful functions for managing the lifecycle of lllls are:
 llll_chuck() (frees an llll but not the elements it contains: when possible, this should be preferred to setting OBJ_FLAG_DATA)
 llll_clear() (frees all the elements contained in an llll, but not the llll itself)
 */

typedef struct _llll
{
    struct _llllelem    *l_head;            // pointer to the first element, or NULL if llll is empty
    struct _llllelem    *l_tail;            // pointer to the last element, or NULL if llll is empty
    struct _llllelem    *l_owner;            // pointer to the element that contains the llll, or NULL if it has none
    t_thingword            l_thing;            // whatever you want, whatever you like - but always zero it before outputting the llll
    t_uint32            l_phonenumber;        // the llll id. it is also the number passed in a patch for its native representation (as in bach.llll 12345)
                                            // you should never touch this directly!
    t_uint32            l_size;                // the number of elements in the list (at this level only - a subllll counts as one element)
    t_int32                l_depth;            // the maximal depth of the llll, starting from this level down to the deepest sublist
#ifdef BACH_USE_MAGIC_NUMBER
    t_uint32            l_magic;            // magic number, BACH_MAGIC_GOOD if the object is valid - semi-deprecated
#endif
    t_int32_atomic        l_count;            // reference count - you should never touch this directly!
    t_int32                l_flags;            // OBJ_FLAG_OBJ: free the elements it contains - OBJ_FLAG_DATA: don't
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
#ifdef BACH_SAVE_STACK_IN_LLLLS
    t_mframe            l_alloc_stack[16];    // for badass debugging purposes
    t_mframe            l_free_stack[16];    // for badass debugging purposes
#endif
#endif
} t_llll;


typedef enum _llll_leveltypes {
    L_STANDARD    = 0,
    L_SQUARE,
    L_CURLY,
    L_FLATTENED = 0xF0 // private, only used by llll_flat
} e_llll_leveltypes;


/*
 Useful with llll_getindex()
 */
typedef enum _llll_index_modes { 
    I_STANDARD        = 0x00,
    I_NON_NEGATIVE    = 0x01,    // negative indices return NULL (normally negative indices are read from the tail) 
    I_MODULO        = 0x02    // the list is seen as circular (so asking for the 4th element in a 3-element list will return the 1st element)
} e_llll_index_modes;


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

t_bool hatom_is_number(const t_hatom *h);
t_bool hatom_type_is_number(const t_int32 type);

t_uint32 hatom_gettype(const t_hatom *h);
t_atom_long hatom_getlong(const t_hatom *h);
double hatom_getdouble(const t_hatom *h);
t_rational hatom_getrational(const t_hatom *h);
t_pitch hatom_getpitch(const t_hatom *h, long tonedivision = 0, e_accidentals_preferences pref = k_ACC_AUTO);
t_symbol *hatom_getsym(const t_hatom *h);
t_llll *hatom_getllll(const t_hatom *h); // no check is performed, and the reference count of the llll is left untouched
void *hatom_getobj(const t_hatom *h);
t_function *hatom_getfunc(const t_hatom *h);
void hatom_setlong(t_hatom *h, const t_atom_long l);
void hatom_setrational(t_hatom *h, const t_rational &r); // first, the given rational is reduced. Then, if the denominator appears to be 1 or -1 a long is stored instead
void hatom_setpitch(t_hatom *h, const t_pitch &p);
void hatom_setpitch_from_elems(t_hatom *h, t_atom_short degree, t_shortRational &alter, t_atom_short octave);
void hatom_setrational_from_elems(t_hatom *h, t_atom_long num, t_atom_long den); // as above
void hatom_setdouble(t_hatom *h, const double d);
void hatom_setsym(t_hatom *h, const t_symbol *s);
void hatom_setllll(t_hatom *h, const t_llll *llll); // no check is performed, and the reference count of the llll is left untouched
void hatom_setobj(t_hatom *h, const void *o);
void hatom_setfunc(t_hatom *h, t_function *fn);
void hatom_setatom(t_hatom *h, const t_atom *a); // atom to hatom conversion. If the atom is A_OBJ and points to a llll, the hatom is correctly set to A_LLLL
long hatom_eq(const t_hatom *a, const t_hatom *b); // comparison between two atoms

t_bool hatom_istrue(const t_hatom *h);



#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _HATOM_H_
