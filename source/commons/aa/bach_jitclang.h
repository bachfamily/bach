#ifndef _BACH_JITCLANG_H_
#define _BACH_JITCLANG_H_

#ifdef BACH_JITCLANG

#include "max_types.h"
#include "ext_atomic.h"


typedef void t_hashtab;
typedef void t_dictionary;
typedef void t_atomarray;
typedef void t_systhread;
typedef void *t_systhread_mutex;
typedef void *(*method)(void *, ...);

typedef struct object
{
    void *o_messlist;	///<  list of messages and methods. The -1 entry of the message list of an object contains a pointer to its #t_class entry.
    // (also used as freelist link)
    t_ptr_int o_magic;					///< magic number
    void *o_inlet;			///<  list of inlets
    void *o_outlet;		///<  list of outlets
} t_object;

typedef struct symbol
{
    char *s_name;	///< name: a c-string
    void *s_thing;	///< possible binding to a t_object
} t_symbol;

union word
{
    t_atom_long w_long;			///< long integer
    t_atom_float w_float;	///< 32-bit float
    struct symbol *w_sym;	///< pointer to a symbol in the Max symbol table
    t_object *w_obj;	///< pointer to a #t_object or other generic pointer
};

typedef struct atom		// and an atom which is a typed datum
{
    short			a_type;
    t_object		a_w;
} t_atom;

#endif // BACH_JITCLANG
#endif // _BACH_JITCLANG_H_