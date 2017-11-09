/**
 @file
 decode.c
 
 @name 
 bach.decode
 
 @realname 
 bach.decode
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @status
 experimental
 
 @digest 
 Decode an llll after transmission
 
 @description
 Decodes an llll encoded by bach.encode
 
 @discussion
 
 @category
 bach, bach objects, bach llll

 @keywords
 decode, transmission, send
 
 @seealso
 bach.encode
 
 @owner
 Andrea Agostini
 */


#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_hashtab.h"
//#include "ext_critical.h"

typedef struct _decode
{
	struct llllobj_object 	n_ob;
	t_hashtab				*n_embryos;
	t_bach_atomic_lock			n_lock;
} t_decode;

typedef struct _incoming {
	t_object		i_ob;
	long			i_id;
	long			i_gotstart;	// 1 if the header for this llll has arrived
	long			i_tot;		// how many chunks in total
	long			i_sofar;	// how many chunks have arrived so far
	long			i_checksum;	// unused
	long			i_totsize;	// how many atoms we have collected
	t_atomarray		**i_chunks;
} t_incoming;

void decode_assist(t_decode *x, void *b, long m, long a, char *s);
void decode_inletinfo(t_decode *x, void *b, long a, char *t);

t_decode *decode_new(t_symbol *s, short ac, t_atom *av);
void decode_free(t_decode *x);

void decode_llll(t_decode *x, t_symbol *msg, long ac, t_atom *av);
void decode_clear(t_decode *x, t_symbol *msg, long ac, t_atom *av);

void incoming_free(t_incoming *x);
t_incoming *incoming_new(void);

t_class *decode_class;
t_class *incoming_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.decode", (method)decode_new, (method)decode_free, (short)sizeof(t_decode), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)decode_llll,		"llll",	A_GIMME,	0);
	class_addmethod(c, (method)decode_clear,	"clear", A_GIMME, 0);
	
	class_addmethod(c, (method)decode_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)decode_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	//llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);

	class_register(CLASS_BOX, c);
	decode_class = c;
	
	c = class_new("bach.incoming", (method)incoming_new, (method)incoming_free, (short)sizeof(t_incoming), 0L, 0);
	class_register(CLASS_NOBOX, c);
	incoming_class = c;
	dev_post("bach.decode compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


// format of the incoming chunks (message selector is llll for all of them!):
// <id> start <tot_chunks> <checksum>
// or
// <id> <chunk_num> <data> ...


void decode_llll(t_decode *x, t_symbol *msg, long ac, t_atom *av)
{
	t_atom_long id;
	t_incoming *incoming;
	long existing;
	long i, newtot, newchunk;
	t_llll *ll = NULL;
	
	if (ac < 3 || atom_gettype(av) != A_LONG) {
		object_error((t_object *) x, "Bad data");
		return;
	}
	id = atom_getlong(av);
	bach_atomic_lock(&x->n_lock);
//	critical_enter(0);
	existing = hashtab_lookup(x->n_embryos, (t_symbol *) id, (t_object **) &incoming);
	if (existing != MAX_ERR_NONE) {
		incoming = incoming_new();
		incoming->i_id = id;
		hashtab_store(x->n_embryos, (t_symbol *) id, (t_object *) incoming);
	}
	
	if (atom_getsym(av + 1) == _sym_start) {
		
		if (ac != 4 || atom_gettype(av + 2) != A_LONG) {
			bach_atomic_unlock(&x->n_lock);
//			critical_exit(0);
			object_error((t_object *) x, "Bad data");
			return;
		}
		newtot = atom_getlong(av + 2);
		if (newtot < incoming->i_tot) {
			bach_atomic_unlock(&x->n_lock);
//			critical_exit(0);
			object_error((t_object *) x, "Bad data");
			return;
		}
		if (newtot > incoming->i_tot)
			incoming->i_chunks = (t_atomarray **) bach_resizeptr(incoming->i_chunks, newtot * sizeof(t_atomarray *));
		for (i = incoming->i_tot; i < newtot; i++)
			incoming->i_chunks[i] = NULL;
		incoming->i_tot = newtot;
		incoming->i_gotstart = 1;
		incoming->i_checksum = atom_getlong(av + 3);
		
	} else {	
		
		if (atom_gettype(av + 1) != A_LONG) {
			bach_atomic_unlock(&x->n_lock);
//			critical_exit(0);
			object_error((t_object *) x, "Bad data");
			return;
		}
		
		newchunk = atom_getlong(av + 1);
		
		if (newchunk < 0) {
			bach_atomic_unlock(&x->n_lock);
//			critical_exit(0);
			object_error((t_object *) x, "Bad data");
			return;
		}
		
		if (newchunk >= incoming->i_tot) {
			if (incoming->i_gotstart) {
				bach_atomic_unlock(&x->n_lock);
//				critical_exit(0);
				object_error((t_object *) x, "Bad data");
				return;
			}
			incoming->i_chunks = (t_atomarray **) bach_resizeptr(incoming->i_chunks, (newchunk + 1) * sizeof(t_atomarray *));
			for (i = incoming->i_tot; i <= newchunk; i++)
				incoming->i_chunks[i] = NULL;
			incoming->i_tot = newchunk + 1;
		}
		if (incoming->i_chunks[newchunk] == NULL)
			incoming->i_sofar ++;
		else {
			incoming->i_totsize -= atomarray_getsize(incoming->i_chunks[newchunk]);
		}
		object_free_debug(incoming->i_chunks[newchunk]);
		incoming->i_chunks[newchunk] = atomarray_new_debug(ac - 2, av + 2);
		incoming->i_totsize += ac - 2;
	}
	
	if (incoming->i_gotstart != 0 && incoming->i_sofar == incoming->i_tot) {
		t_atom *the_atoms = (t_atom *) bach_newptr(incoming->i_totsize * sizeof(t_atom));
		t_atom *this_atom = the_atoms;
		t_atom *orig_atoms;
		long ac;
		for (i = 0; i < incoming->i_tot; i++) {
			atomarray_getatoms(incoming->i_chunks[i], &ac, &orig_atoms);
			bach_copyptr(orig_atoms, this_atom, ac * sizeof(t_atom));
			this_atom += ac;
		}
		ll = llll_parse(incoming->i_totsize, the_atoms);
		bach_freeptr(the_atoms);
		hashtab_delete(x->n_embryos, (t_symbol *) id); // this will free incoming, which in turns will free all its atomarrays
	}

	bach_atomic_unlock(&x->n_lock);
//	critical_exit(0);
	if (ll) {
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, ll);
		llll_free(ll);
	}
}

void decode_clear(t_decode *x, t_symbol *msg, long ac, t_atom *av)
{
	if (ac > 1 || (ac == 1 && atom_gettype(av) != A_LONG)) {
		object_error((t_object *) x, "clear: bad arguments");
		return;
	}
	
	if (ac == 1) {
		bach_atomic_lock(&x->n_lock);
//		critical_enter(0);
		hashtab_delete(x->n_embryos, (t_symbol *) atom_getlong(av));
		bach_atomic_unlock(&x->n_lock);
//		critical_exit(0);
	} else {
		bach_atomic_lock(&x->n_lock);
//		critical_enter(0);
		hashtab_clear(x->n_embryos);
		bach_atomic_unlock(&x->n_lock);
//		critical_exit(0);
	}
}

void decode_assist(t_decode *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll: Data / clear");
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type);
	}
}

void decode_inletinfo(t_decode *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void decode_free(t_decode *x)
{
	decode_clear(x, _sym_clear, 0, NULL);
	object_free_debug(x->n_embryos);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_decode *decode_new(t_symbol *s, short ac, t_atom *av)
{
	t_decode *x = NULL;
	t_max_err err = 0;
	
	if ((x = (t_decode *) object_alloc_debug(decode_class))) {		
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
		x->n_embryos = hashtab_new_debug(0);
		object_warn((t_object *) x, "This is a deprecated object which might not work as expected");
		object_warn((t_object *) x, "and might be fixed in a future release of bach");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

void incoming_free(t_incoming *x)
{
	long i;
	for (i = 0; i < x->i_tot; i++)
		object_free_debug(x->i_chunks[i]);
	if (x->i_chunks)
		bach_freeptr(x->i_chunks);
	bach_remove_from_memmap(x); // only for debug!
}

t_incoming *incoming_new(void) {
	return (t_incoming *) object_alloc_debug(incoming_class);
}
