/*
 *  shelf.c
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

/**
 @file
 shelf.c
 
 @name 
 bach.shelf
 
 @realname 
 bach.shelf
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Storage system for lllls
 
 @description 
 Allows referring to lllls by name.
 
 @discussion
 Named lllls can be shared among several <o>bach.shelf</o> objects with the same name.
 The contents of a family of <o>bach.shelf</o> objects can be saved with the patcher or in a separate file.
 <o>bach.shelf</o> can be used in conjunction with the <o>umenu</o>, <o>coll</o>, <o>dict</o> or similar objects,
 allowing them to store references to native lllls.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 store, refer, name, save, reference

 @seealso
 bach.reg, bach.value, bach.pv, coll, dict
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_strings.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _shelveditem
{
	t_object s_ob;
	t_llll *s_ll;
} t_shelveditem;

typedef struct _library
{
	t_object			l_ob;
	t_hashtab			*l_shelves;
	t_systhread_mutex	l_lock;
} t_library;

typedef struct _xshelf
{
	t_object			s_ob;
	t_symbol			*s_name;
	t_hashtab			*s_shelved;
	t_systhread_mutex	s_lock;
} t_xshelf;

typedef struct _shelf
{
	t_llllobj_object 	n_ob;
	long				n_embed;
	t_symbol			*n_name;
	t_xshelf			*n_xshelf;
	t_systhread_mutex	n_lock;
	void				*n_bangout;
	void				*n_symout;
	void				*n_llllout;
} t_shelf;


typedef struct _dumpedxshelf {
	long d_count;
	t_shelveditem **d_items;
	t_symbol **d_syms;
	t_shelveditem **d_thisitems;
	t_symbol **d_thissyms;
} t_dumpedxshelf;


t_library *library_new(t_symbol *s, short ac, t_atom *av);
void library_free(t_library *x);
t_xshelf *library_addxshelf(t_symbol *name);
void library_releasexshelf(t_symbol *name);
void library_deletekey(t_symbol *name);

t_xshelf *xshelf_new(t_symbol *name);
void xshelf_free(t_xshelf *x);
void xshelf_store(t_xshelf *x, t_symbol *name, t_llll *ll);
t_max_err xshelf_clone(t_xshelf *x, t_symbol *old_name, t_symbol *new_name);
t_max_err xshelf_rename(t_xshelf *x, t_symbol *old_name, t_symbol *new_name);
t_shelveditem *xshelf_retrieve(t_xshelf *x, t_symbol *name);
void xshelf_delete(t_xshelf *x, t_symbol *name);
void xshelf_clear(t_xshelf *x);
t_dumpedxshelf *xshelf_dump(t_xshelf *x);
void xshelf_dump_one(t_hashtab_entry *e, t_dumpedxshelf *dumpedxshelf);
t_dictionary *xshelf_serialize(t_xshelf *x);
void xshelf_serialize_one(t_hashtab_entry *e, t_dictionary *dict);
void xshelf_deserialize(t_xshelf *x, t_dictionary *dict);

t_shelveditem *shelveditem_new(t_symbol *s, short ac, t_atom *av);
void shelveditem_free(t_shelveditem *x);

void shelf_store(t_shelf *x, t_symbol *msg, long ac, t_atom *av);
void shelf_storenamed(t_shelf *x, t_symbol *msg, long ac, t_atom *av);
void shelf_rename(t_shelf *x, t_symbol *msg, long ac, t_atom *av);
void shelf_clone(t_shelf *x, t_symbol *msg, long ac, t_atom *av);
void shelf_retrieve(t_shelf *x, t_symbol *name);
void shelf_anything(t_shelf *x, t_symbol *msg, long ac, t_atom *av);
void shelf_delete(t_shelf *x, t_symbol *msg);
void shelf_clear(t_shelf *x);
void shelf_dump(t_shelf *x);
void shelf_dumpnames(t_shelf *x);
void shelf_dumpit(t_shelf *x, long dumplllls);
void shelf_write(t_shelf *x, t_symbol *s); // signature is A_DEFSYM
void shelf_do_write(t_shelf *x, t_symbol *s, long ac, t_atom *av);
void shelf_read(t_shelf *x, t_symbol *s);
void shelf_readappend(t_shelf *x, t_symbol *s); // signature is A_DEFSYM
void shelf_do_read(t_shelf *x, t_symbol *s, long ac, t_atom *av);
void shelf_appendtodictionary(t_shelf *x, t_dictionary *d);
void shelf_refer(t_shelf *x, t_symbol *s);

void shelf_assist(t_shelf *x, void *b, long m, long a, char *s);
void shelf_inletinfo(t_shelf *x, void *b, long a, char *t);

t_shelf *shelf_new(t_symbol *s, short ac, t_atom *av);
void shelf_free(t_shelf *x);

void shelf_anything(t_shelf *x, t_symbol *msg, long ac, t_atom *av);

t_class *shelf_class;
t_class *library_class;
t_class *shelveditem_class;
t_class *xshelf_class;

t_library *the_library; // only one exists!

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.library", (method)library_new, (method) library_free, (long) sizeof(t_library), 0L, A_GIMME, 0);
	class_register(CLASS_NOBOX, c);
	library_class = c;
	
	library_new(NULL, 0, NULL);
	
    CLASS_NEW_CHECK_SIZE(c, "bach.shelveditem", (method)shelveditem_new, (method) shelveditem_free, (long) sizeof(t_shelveditem), 0L, A_GIMME, 0);
	class_register(CLASS_NOBOX, c);
	shelveditem_class = c;
	
    CLASS_NEW_CHECK_SIZE(c, "bach.xshelf", (method)xshelf_new, (method) xshelf_free, (long) sizeof(t_xshelf), 0L, A_SYM, 0);
	class_register(CLASS_NOBOX, c);
	xshelf_class = c;	
	
    CLASS_NEW_CHECK_SIZE(c, "bach.shelf", (method)shelf_new, (method)shelf_free, (long) sizeof(t_shelf), 0L, A_GIMME, 0);	
	
	// @method store @digest Store an llll
	// @description The argument llll is stored and associated with a unique name.
	// The name is output from the second outlet.
	// The argument llll can be provided in either text or native format. 
	// This means, for instance, that both <m>store a (b) c</m> and <m>store bach.llll 12345</m> are valid syntaxes.
	// @marg 0 @name llll @optional 0 @type llll
	class_addmethod(c, (method)shelf_store,					"store",				A_GIMME,	0);
	
	// @method storenamed @digest Store an llll with a given name
	// @description The llll is stored and associated with the provided name, 
	// the name being the first message argument, the llll the second.
	// The name is output from the second outlet.
	// The argument llll can be provided in either text or native format. 
	// This means, for instance, that both <m>storenamed foo a (b) c</m> and <m>storenamed foo bach.llll 12345</m> are valid syntaxes.
	// If the name was already associated to an llll, the previous llll is discarded.
	// @marg 0 @name name @optional 0 @type symbol
	// @marg 1 @name llll @optional 0 @type llll
	class_addmethod(c, (method)shelf_storenamed,			"storenamed",			A_GIMME,	0);
	
	// @method rename @digest Change the name of an llll
	// @description The llll associated with the name given as the first argument 
	// is associated with the name given as the second argument, and the previous association is lost.
	// @marg 0 @old_name name @optional 0 @type symbol
	// @marg 1 @new_name name @optional 0 @type symbol
	class_addmethod(c, (method)shelf_rename,				"rename",				A_GIMME,	0);
	
	// @method clone @digest Clone a stored llll
	// @description The llll associated with the name given as the first argument is cloned,
	// and the clone is associated with the name given as the second argument.
	// The original llll and its name are kept.
	// @marg 0 @old_name name @optional 0 @type symbol
	// @marg 1 @new_name name @optional 0 @type symbol
	class_addmethod(c, (method)shelf_clone,					"clone",				A_GIMME,	0);
	
	// @method retrieve @digest Retrieve a stored llll
	// @description The llll associated with the name given as the argument is retrieved and output from the left outlet.
	// The llll and its name are not discarded after the retrieval.
	// This is equivalent to just sending the name.
	// @marg 0 @name name @optional 0 @type symbol
	class_addmethod(c, (method)shelf_retrieve,				"retrieve",				A_SYM,		0);

	// @method anything @digest Retrieve a stored llll
	// @description The llll associated with the symbol is retrieved and output from the left outlet.
	// The llll and its name are not discarded after the retrieval.
	// This is equivalent to sending the <m>retrieve</m> message.
	class_addmethod(c, (method)shelf_anything,				"anything",				A_GIMME,	0);

	// @method delete @digest Discard a stored llll
	// @description The llll associated with the name given as the argument is discarded.
	// @marg 0 @name name @optional 0 @type symbol
	class_addmethod(c, (method)shelf_delete,				"delete",				A_SYM,		0);
	
	// @method clear @digest Discard all stored lllls
	// @description All the contents of <o>bach.shelf</o> are discarded.
	class_addmethod(c, (method)shelf_clear,					"clear",				0);
	
	// @method dump @digest Output all the stored lllls and their names
	// @description For each stored llll, its name is output from the second outlet
	// and the llll itself is output from the first outlet.
	class_addmethod(c, (method)shelf_dump,					"dump",					0);
	
	// @method dumpnames @digest Output the names of all the stored lllls
	// @description For each stored llll, its name is output from the second outlet.
	// This can be useful e.g. for filling a <o>umenu</o>.
	class_addmethod(c, (method)shelf_dumpnames,				"dumpnames",			0);
	
	// @method write @digest Write to disk the contents
	// @description All the stored lllls, along with their names, are written to disk.
	// When the operation is completed, a bang is output from the third outlet.
	class_addmethod(c, (method)shelf_write,					"write",				A_DEFSYM,	0);
	
	// @method read @digest Clear the object and read the contents of a file
	// @description All the stored lllls are discarded, and the contents of the specified file are loaded into <o>bach.shelf</o>.
	// When the operation is completed, a bang is output from the third outlet.
	// If a file name is not provided, a dialog box will open.
	// @marg 0 @name file_name @optional 1 @type symbol
	class_addmethod(c, (method)shelf_read,					"read",					A_DEFSYM,	0);
	
	// @method readappend @digest Read the contents of a file
	// @description The contents of a file are loaded into <o>bach.shelf</o>.
	// All the lllls that were stored are kept, unless a name conflict arises.
	// In this case, the llll in the file replaces the one that was previously stored.
	// When the operation is completed, a bang is output from the third outlet.
	// If a file name is not provided, a dialog box will open.
	// @marg 0 @name file_name @optional 1 @type symbol
	class_addmethod(c, (method)shelf_readappend,			"readappend",			A_DEFSYM,	0);
	
	// @method refer @digest Share data with other <o>bach.shelf</o> objects
	// @description A name can be assigned to <o>bach.shelf</o> through the <m>refer</m> message or an object-box argument.
	// All the <o>bach.shelf</o> objects with the same name share the same data.
	// If no name is provided, <o>bach.shelf</o> will not share its data with any other instance.
	// Beware: if the name of an instance of <o>bach.shelf</o> is changed and no other <o>bach.shelf</o> shares its contents,
	// these are discarded and there is no way to retrieve them.
	// @marg 0 @name name @optional 1 @type symbol
	class_addmethod(c, (method)shelf_refer,					"refer",				A_SYM,		0);
	
	
	class_addmethod(c, (method)shelf_assist,				"assist",				A_CANT,		0);
	class_addmethod(c, (method)shelf_inletinfo,				"inletinfo",			A_CANT,		0);
	class_addmethod(c, (method)shelf_appendtodictionary,	"appendtodictionary",	A_CANT,		0);

	CLASS_ATTR_LONG(c, "embed",	0, t_shelf, n_embed);
	CLASS_ATTR_FILTER_CLIP(c, "embed", 0, 1);
	CLASS_ATTR_LABEL(c, "embed", 0, "Save Data With Patcher");
	CLASS_ATTR_STYLE(c, "embed", 0, "onoff");
	CLASS_ATTR_SAVE(c, "embed", 0);
	CLASS_ATTR_BASIC(c, "embed", 0);	
	// @method embed @digest Save data with patcher
	// @description When set to 1, all the stored data are saved with the patch,
	// and will be retrieved when the patch is loaded.

	class_register(CLASS_BOX, c);
	shelf_class = c;
	
	dev_post("bach.shelf compiled %s %s", __DATE__, __TIME__);
	
    llllobj_class_add_versionnumber_attr(c, LLLL_OBJ_VANILLA);
    bachobject_class_add_fileusage_method(c);

	return;
}

// only one exists!
t_library *library_new(t_symbol *s, short ac, t_atom *av)
{
	t_library *x = (t_library *) object_alloc(library_class);
	x->l_shelves = hashtab_new(0);
	object_method(x->l_shelves, gensym("readonly"), 1);
	systhread_mutex_new(&x->l_lock, 0);
	the_library = x;
	return x;
}


// never called
void library_free(t_library *x)
{	
}

// the library mutex should be locked before calling this
t_xshelf *library_addxshelf(t_symbol *name)
{
	t_hashtab *shelves = the_library->l_shelves;
	t_xshelf *the_xshelf = NULL;
	t_max_err err;
	err = hashtab_lookup(shelves, name, (t_object **) &the_xshelf);
	if (err != MAX_ERR_NONE) {  // if there wasn't a shell with that name
		the_xshelf = xshelf_new(name);
		hashtab_store_safe(shelves, name, (t_object *) the_xshelf);
	} else {
		object_retain_debug((t_object *) the_xshelf);
	}

	return the_xshelf;
}

void library_releasexshelf(t_symbol *name)
{
	t_hashtab *shelves = the_library->l_shelves;
	t_xshelf *the_xshelf;
	t_max_err err;
	err = hashtab_lookup(shelves, name, (t_object **) &the_xshelf);
	if (!err)
		object_release_debug((t_object *) the_xshelf);
}

// never called
void library_deletekey(t_symbol *name)
{
	hashtab_delete(the_library->l_shelves, name);
}

void library_chuckkey(t_symbol *name)
{
	hashtab_chuckkey(the_library->l_shelves, name);
}

t_xshelf *xshelf_new(t_symbol *name)
{
	t_xshelf *x = (t_xshelf *) object_alloc_debug(xshelf_class);
	x->s_shelved = hashtab_new_debug(0);
	object_method(x->s_shelved, gensym("readonly"), 1);
	systhread_mutex_new_debug(&x->s_lock, 0);
	object_retain_debug((t_object *) x);
	object_release_debug((t_object *) x);
	x->s_name = name;
	return x;
}

void xshelf_free(t_xshelf *x)
{
	library_chuckkey(x->s_name);
	object_free_debug(x->s_shelved);
	systhread_mutex_free_debug(x->s_lock);
}

void xshelf_store(t_xshelf *x, t_symbol *name, t_llll *ll)
{
	t_max_err err;
	t_hashtab *shelved = x->s_shelved;
	t_shelveditem *shelveditem = NULL;
	systhread_mutex_lock(x->s_lock);
	err = hashtab_lookup(shelved, name, (t_object **) &shelveditem);
	if (err != MAX_ERR_NONE) { // that is, if there was nothing with that name
//		llll_retain(ll); // llllobj_parse_llll already retained it for us!
		shelveditem = shelveditem_new(NULL, 0, NULL);
		shelveditem->s_ll = ll;
		hashtab_store_safe(shelved, name, (t_object *) shelveditem);
	} else if (shelveditem->s_ll != ll) {
		llll_release(shelveditem->s_ll);
//		llll_retain(ll); // llllobj_parse_llll already retained it for us!
		shelveditem->s_ll = ll;
	}
	systhread_mutex_unlock(x->s_lock);
}

t_max_err xshelf_clone(t_xshelf *x, t_symbol *oldname, t_symbol *newname)
{
	t_hashtab *shelved;
	t_shelveditem *shelveditem;
	t_llll *ll;
	t_max_err err;
	if (oldname == newname)
		return MAX_ERR_GENERIC;
	shelved = x->s_shelved;
	systhread_mutex_lock(x->s_lock);
	err = hashtab_lookup(shelved, oldname, (t_object **) &shelveditem);
	if (err) {
		systhread_mutex_unlock(x->s_lock);
		return MAX_ERR_GENERIC;
	}
	ll = shelveditem->s_ll;
	llll_retain(ll);
	systhread_mutex_unlock(x->s_lock);
//	new_llll = llll_get();
//	llll_clone(old_llll, new_llll, -1, WHITENULL_llll, NULL);
//	llll_release(old_llll);
	
//	phonebook_get_phonenumber(new_llll);
	xshelf_store(x, newname, ll);
	return MAX_ERR_NONE;
}

t_max_err xshelf_rename(t_xshelf *x, t_symbol *old_name, t_symbol *new_name)
{	
	t_hashtab *shelved;
	t_shelveditem *shelvedold, *shelvednew;
	t_max_err err;
	if (old_name == new_name)
		return MAX_ERR_GENERIC;
	shelved = x->s_shelved;
	systhread_mutex_lock(x->s_lock);
	err = hashtab_lookup(shelved, old_name, (t_object **) &shelvedold);
	if (err) {
		systhread_mutex_unlock(x->s_lock);
		return MAX_ERR_GENERIC;
	}
	 
	hashtab_chuckkey(shelved, old_name);
	err = hashtab_lookup(shelved, new_name, (t_object **) &shelvednew);
	if (err)
		object_free_debug(shelvednew); // if there were data, I free them because...
	hashtab_store_safe(shelved, new_name, (t_object *) shelvedold); // ... with hashtab_store_safe if a value was present the data are just overwritten, but the old data are not released
	systhread_mutex_unlock(x->s_lock);
	return MAX_ERR_NONE;
}

// retains the shelveditem (and its contained llll with it)!
t_shelveditem *xshelf_retrieve(t_xshelf *x, t_symbol *name)
{
	t_hashtab *shelved = x->s_shelved;
	t_shelveditem *shelveditem;
	t_max_err err;
	systhread_mutex_lock(x->s_lock);
	err = hashtab_lookup(shelved, name, (t_object **) &shelveditem);
	if (err) {
		systhread_mutex_unlock(x->s_lock);
		return NULL;
	}
	object_retain_debug((t_object *) shelveditem);
	systhread_mutex_unlock(x->s_lock);
	return shelveditem;
}

void xshelf_delete(t_xshelf *x, t_symbol *name)
{
	systhread_mutex_lock(x->s_lock);
	hashtab_delete(x->s_shelved, name);
	systhread_mutex_unlock(x->s_lock);
}

void xshelf_clear(t_xshelf *x)
{
	systhread_mutex_lock(x->s_lock);
	hashtab_clear(x->s_shelved);
	systhread_mutex_unlock(x->s_lock);
}


t_dumpedxshelf *xshelf_dump(t_xshelf *x)
{
	long count;
	t_dumpedxshelf *dumpedxshelf = (t_dumpedxshelf *) bach_newptr(sizeof(t_dumpedxshelf));
	t_hashtab *shelved = x->s_shelved;
	systhread_mutex_lock(x->s_lock);
	dumpedxshelf->d_count = count = hashtab_getsize(shelved);
	dumpedxshelf->d_items = dumpedxshelf->d_thisitems = (t_shelveditem **) bach_newptr(count * sizeof(t_shelveditem *));
	dumpedxshelf->d_syms = dumpedxshelf->d_thissyms = (t_symbol **) bach_newptr(count * sizeof(t_symbol *));
	hashtab_funall(shelved, (method) xshelf_dump_one, dumpedxshelf);
	systhread_mutex_unlock(x->s_lock);
	return dumpedxshelf;
}

void xshelf_dump_one(t_hashtab_entry *e, t_dumpedxshelf *dumpedxshelf)
{
	object_retain_debug(e->value); // e->value is a t_shelveditem
	*(dumpedxshelf->d_thisitems++) = (t_shelveditem *) e->value;
	*(dumpedxshelf->d_thissyms++) = e->key;
}

t_dictionary *xshelf_serialize(t_xshelf *x)
{
	long count = 0, i;
	t_symbol **keys = NULL;
	t_atom *key_atoms;
	t_dictionary *dict = dictionary_new_debug();
	t_hashtab *shelved = x->s_shelved;
	systhread_mutex_lock(x->s_lock);
	hashtab_getkeys(shelved, &count, &keys);
	key_atoms = (t_atom *) bach_newptr(count * sizeof(t_atom));
	for (i = 0; i < count; i++)
		atom_setsym(key_atoms + i, keys[i]);
	if (keys)
		bach_freeptr(keys);
	dictionary_appendatoms(dict, gensym("_x_x_x_x_keys_x_x_x_x_"), count, key_atoms);
	bach_freeptr(key_atoms);
	hashtab_funall(x->s_shelved, (method) xshelf_serialize_one, dict);
	systhread_mutex_unlock(x->s_lock);
	return dict;
}

void xshelf_serialize_one(t_hashtab_entry *e, t_dictionary *dict)
{
	llll_store_in_dictionary(((t_shelveditem *) e->value)->s_ll, dict, e->key->s_name, NULL);
}

void xshelf_deserialize(t_xshelf *x, t_dictionary *dict)
{
	long count = 0, i;
	t_atom *key_atoms = NULL;
	t_max_err err;
	err = dictionary_getatoms(dict, gensym("_x_x_x_x_keys_x_x_x_x_"), &count, &key_atoms);
	if (err)
		return;	
	for (i = 0; i < count; i++) {
		t_symbol *name = atom_getsym(key_atoms + i);
		t_llll *ll = llll_retrieve_from_dictionary(dict, name->s_name);
		if (ll)
			xshelf_store(x, name, ll);
//		llll_free(ll);
	}
	//sysmem_freeptr(key_atoms); // not bach_freeptr, as key_atoms has been allocated by dictionary_getatoms
}

t_shelveditem *shelveditem_new(t_symbol *s, short ac, t_atom *av)
{
	t_shelveditem *x = (t_shelveditem *) object_alloc_debug(shelveditem_class);
	object_retain_debug((t_object *) x);
	object_release_debug((t_object *) x);
	return x;
}

void shelveditem_free(t_shelveditem *x)
{
	llll_free(x->s_ll);
	bach_remove_from_memmap(x);
}

void shelf_store(t_shelf *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_ll;
	t_symbol *name;
	if (ac == 0) {
		object_error((t_object *) x, "Wrong number of arguments for message store");
		return;
	}
	if (atom_getsym(av) != LLLL_NATIVE_MSG)
		in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_DONT); // flag is ignored, as this is surely a text llll
	else
		in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, LLLL_NATIVE_MSG, ac - 1, av + 1, LLLL_PARSE_RETAIN);

	if (!in_ll)
		return;
	name = symbol_unique();
	xshelf_store(x->n_xshelf, name, in_ll);
	llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 1, name, 0, NULL);
}

void shelf_storenamed(t_shelf *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_ll;
	t_symbol *name;
	if (ac < 2) {
		object_error((t_object *) x, "Wrong number of arguments for message store");
		return;
	}
	if (av->a_type != A_SYM) {
		object_error((t_object *) x, "Bad name");
		return;
	}
	name = av->a_w.w_sym;
	if (atom_getsym(av + 1) != LLLL_NATIVE_MSG)
		in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac - 1, av + 1, LLLL_PARSE_DONT); // flag is ignored, as this is surely a text llll
	else
		in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, LLLL_NATIVE_MSG, ac - 2, av + 2, LLLL_PARSE_RETAIN);
	if (!in_ll)
		return;
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	xshelf_store(x->n_xshelf, name, in_ll);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);	
	// llll_release(in_ll); // because xshelf_store just retained it for us
	llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 1, name, 0, NULL);
}

void shelf_rename(t_shelf *x, t_symbol *msg, long ac, t_atom *av)
{
	t_symbol *oldname, *newname;
	t_max_err err;
	if (ac != 2) {
		object_error((t_object *) x, "Wrong number of arguments for message rename");
		return;
	}
	if (av[0].a_type != A_SYM || av[1].a_type != A_SYM) {
		object_error((t_object *) x, "Bad name");
		return;
	}
	oldname = av[0].a_w.w_sym;
	newname = av[1].a_w.w_sym;
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	err = xshelf_rename(x->n_xshelf, oldname, newname);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	if (err)
		object_error((t_object *) x, "Bad name");	

}

void shelf_clone(t_shelf *x, t_symbol *msg, long ac, t_atom *av)
{
	t_symbol *oldname, *newname;
	t_max_err err;
	if (ac != 2) {
		object_error((t_object *) x, "Wrong number of arguments for message clone");
		return;
	}
	if (av[0].a_type != A_SYM || av[1].a_type != A_SYM) {
		object_error((t_object *) x, "Bad name");
		return;
	}
	oldname = av[0].a_w.w_sym;
	newname = av[1].a_w.w_sym;
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	err = xshelf_clone(x->n_xshelf, oldname, newname);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	if (err)
		object_error((t_object *) x, "Bad name");
}

void shelf_retrieve(t_shelf *x, t_symbol *name)
{
	if (!name) {
		object_error((t_object *) x, "Name missing for message retrieve");
		return;
	}
	shelf_anything(x, name, 0, NULL);
}

void shelf_anything(t_shelf *x, t_symbol *msg, long ac, t_atom *av)
{
	t_shelveditem *item;
	if (ac) {
		object_error((t_object *) x, "Wrong number of arguments");
		return;
	}
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	item = xshelf_retrieve(x->n_xshelf, msg);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	if (!item) {
		object_error((t_object *) x, "Bad name");
		return;
	}
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, item->s_ll);
	object_release_debug((t_object *) item);
}

void shelf_delete(t_shelf *x, t_symbol *name)
{
	if (!name) {
		object_error((t_object *) x, "Name missing for message delete");
		return;
	}
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	xshelf_delete(x->n_xshelf, name);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
}

void shelf_clear(t_shelf *x)
{
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	xshelf_clear(x->n_xshelf);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);	
}

void shelf_dump(t_shelf *x)
{
	shelf_dumpit(x, 1);
}

void shelf_dumpnames(t_shelf *x)
{
	shelf_dumpit(x, 0);
}

void shelf_dumpit(t_shelf *x, long dumplllls)
{
	t_dumpedxshelf *dumped;
	t_symbol **this_syms;
	t_shelveditem **this_items;
	long i;
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	dumped = xshelf_dump(x->n_xshelf);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);	
	this_syms = dumped->d_syms;
	this_items = dumped->d_items;
	if (dumplllls) {
		for (i = 0; i < dumped->d_count; i++, this_syms++, this_items++) {
			llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 1, *this_syms, 0, NULL);
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, (*this_items)->s_ll);
			object_release_debug((t_object *) *this_items);
		}
	} else {
		for (i = 0; i < dumped->d_count; i++, this_syms++, this_items++) {
			llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 1, *this_syms, 0, NULL);
			object_release_debug((t_object *) *this_items);
		}
	}

	bach_freeptr(dumped->d_items);
	bach_freeptr(dumped->d_syms);
	bach_freeptr(dumped);
}

void shelf_write(t_shelf *x, t_symbol *s) // signature is A_DEFSYM
{
	t_dictionary *dict;
	t_atom dictatom;
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	dict = xshelf_serialize(x->n_xshelf);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	atom_setobj(&dictatom, dict);
	defer(x, (method) shelf_do_write, s, 1, &dictatom);
}

void shelf_do_write(t_shelf *x, t_symbol *s, long ac, t_atom *av)
{
	t_fourcc filetype = 'JSON', outtype;
	char filename[MAX_PATH_CHARS];
	short path;
	t_max_err err;
	t_dictionary *dict = (t_dictionary *) av->a_w.w_obj;
	*filename = 0;
	
	strncpy_zero(filename, "Untitled.json", MAX_PATH_CHARS);
	if (!s || s == gensym("")) {      // if no argument supplied, ask for file
		if (saveasdialog_extended(filename, &path, &outtype, &filetype, 1))     // non-zero: user cancelled
			return;
	} else {
		strcpy(filename, s->s_name);
		path = path_getdefault();
	}
	err = dictionary_write(dict, filename, path);
	llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 2);
	object_free_debug(dict);
}

void shelf_read(t_shelf *x, t_symbol *s)
{
	t_atom shelfatom;
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	atom_setobj(&shelfatom, x->n_xshelf); // we'll release xshelf afterwards
	defer(x, (method) shelf_do_read, s, 1, &shelfatom);
}

void shelf_readappend(t_shelf *x, t_symbol *s)
{
	t_atom shelfatom[2];
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	atom_setobj(shelfatom, x->n_xshelf); // we'll release xshelf afterwards
	atom_setobj(shelfatom + 1, NULL); // this is just to have a second atom to tell shelf_do_read to append instead of replacing
	defer(x, (method) shelf_do_read, s, 2, shelfatom);
}

void shelf_do_read(t_shelf *x, t_symbol *s, long ac, t_atom *av)
{
	t_fourcc filetype[2], outtype;
	char filename[MAX_PATH_CHARS];
	short path;
	t_max_err err;
	t_dictionary *dict = NULL;
	t_xshelf *xshelf = (t_xshelf *) av->a_w.w_obj;
	
	filetype[0] = 'JSON';
	filetype[1] = 'TEXT';
	if (!s || s == gensym("")) {      // if no argument supplied, ask for file
		if (open_dialog(filename, &path, &outtype, filetype, 2))       // non-zero: user cancelled
			return;
	} else {
		strcpy(filename, s->s_name);    // must copy symbol before calling locatefile_extended
		if (locatefile_extended(filename, &path, &outtype, filetype, 2)) { // non-zero: not found
			object_error((t_object *) x, "%s: not found", s->s_name);
			return;
		}
	}
	
	err = dictionary_read(filename, path, &dict);
	if (!err) {
		if (ac == 1) // that is, if it doesn't come from readappend
			xshelf_clear(xshelf);
		xshelf_deserialize(xshelf, dict);
		object_free(dict); // because dict has been allocated by dictionary_read
	}
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) xshelf);
	systhread_mutex_unlock(x->n_lock);
	llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 2);
}

void shelf_appendtodictionary(t_shelf *x, t_dictionary *d)
{
	t_dictionary *shelf_dict;
	if (!x->n_embed)
		return;
	systhread_mutex_lock(x->n_lock);
	object_retain_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	shelf_dict = xshelf_serialize(x->n_xshelf);
	systhread_mutex_lock(x->n_lock);
	object_release_debug((t_object *) x->n_xshelf);
	systhread_mutex_unlock(x->n_lock);
	if (shelf_dict)
		dictionary_appenddictionary(d, gensym("shelf_data"), (t_object *) shelf_dict);
}

void shelf_refer(t_shelf *x, t_symbol *s)
{
	t_xshelf *freeme;
	if (!s)
		s = symbol_unique();
	systhread_mutex_lock(x->n_lock);
	freeme = x->n_xshelf;
	x->n_xshelf = library_addxshelf(s);
	systhread_mutex_unlock(x->n_lock);
	object_release_debug((t_object *) freeme);
}

void shelf_free(t_shelf *x)
{
	systhread_mutex_free_debug(x->n_lock);
	object_free_debug(x->n_xshelf);
	llllobj_obj_free((t_llllobj_object *) x);
}

void shelf_assist(t_shelf *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "Messages to bach.shelf or Name to Retrieve"); // @in 0 @type anything @digest Messages to <o>bach.shelf</o>
		// @description Messages to <o>bach.shelf</o>, or name of an llll to retrieve.
	} else {
		char *type = NULL;
		switch (a) {
			case 0:
				llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
				sprintf(s, "Retrieved llll (%s)", type); // @out 0 @type llll @digest Retrieved llll
				break;
			case 1: 
				sprintf(s, "Symbol Associated with Data"); // @out 1 @type symbol @digest Associated symbol
				// @description Whenever an llll is stored, or during the execution of a <m>dump</m> or <m>dumpnames</m> message,
				// the names associated with the lllls are output from the second outlet.
				break;
			case 2: 
				sprintf(s, "bang When File Operation Completed"); // @out 2 @type bang @digest bang when load/write is completed
				break;
		}
	}
}

void shelf_inletinfo(t_shelf *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

t_shelf *shelf_new(t_symbol *s, short ac, t_atom *av)
{
	t_shelf *x = NULL;
	long true_ac;
	t_max_err err = 0;
	t_symbol *name = NULL;
	t_dictionary *d;
	
	if ((x = (t_shelf *) object_alloc_debug(shelf_class))) {
		// @arg 0 @name name @optional 1 @type symbol @digest Name
		// @description All the <o>bach.shelf</o> objects with the same name share the same data.
		// If no name is provided, <o>bach.shelf</o> will not share its data with any other instance.
		// The name can be changed later through the <m>refer</m> message.
		
		true_ac = attr_args_offset(ac, av);
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 0, "ba4", NULL);
		if (true_ac && av->a_type == A_SYM)
			name = av->a_w.w_sym;
		else
			name = symbol_unique();
		x->n_xshelf = library_addxshelf(name);
		systhread_mutex_new_debug(&x->n_lock, 0);

		d = (t_dictionary *)gensym("#D")->s_thing;
		if (d) {
			t_dictionary *shelf_dict = NULL;
			dictionary_getdictionary(d, gensym("shelf_data"), (t_object **) &shelf_dict);
			if (shelf_dict) {
				xshelf_clear(x->n_xshelf);
				xshelf_deserialize(x->n_xshelf, shelf_dict);
			}
		}
	} else 
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;

	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
