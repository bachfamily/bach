/*
 *  bach_mem.h
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

#ifndef bach_mem_h
#define bach_mem_h

#include "ext.h"

///////////////////////////////////////////////////////////////////////
// MEMORY API
//
struct _memmap_item *memmap_item_new(void *address, size_t size, t_symbol *name);

#ifdef BACH_TRACK_MEMORY_ALLOCATION
#include "jgraphics.h"
#include "foundation/hatom.h"
void object_free_debug(void *x);
void object_release_debug(void *x);
void bach_save_stack(t_mframe *frame);
void *bach_newptr(size_t size);
void *bach_newptrclear(size_t size);
void *bach_newptr_named(size_t size, t_symbol *name);
void *bach_newptrclear_named(size_t size, t_symbol *name);
void *bach_resizeptr(void *ptr, size_t newsize);
void *bach_resizeptrclear(void *ptr, size_t newsize);
void bach_freeptr(void *ptr);
void *object_alloc_debug(t_class *c);
void object_retain_debug(t_object *x);
t_atomarray *atomarray_new_debug(long ac, t_atom *av);
t_hashtab *hashtab_new_debug(long slotcount);
t_linklist *linklist_new_debug(void);
t_dictionary *dictionary_new_debug(void);
void *proxy_new_debug(void *o, long id, long *stuffloc);
void *object_new_typed_debug(t_symbol *objnamespace, t_symbol *classname, long ac, t_atom *av);
long systhread_mutex_new_debug(t_systhread_mutex *pmutex, long flags = 0);
long systhread_mutex_free_debug(t_systhread_mutex pmutex);
void *clock_new_debug(void *obj, method fn);
void *qelem_new_debug(void *obj, method fn);
void qelem_free_debug(void *obj);
char *charset_unicodetoutf8_debug(unsigned short *s, long len, long *outlen);
unsigned short *charset_utf8tounicode_debug(char *s, long *outlen);
t_jfont	*jfont_create_debug(const char *family, t_jgraphics_font_slant slant, t_jgraphics_font_weight weight, double size);
void jfont_destroy_debug(t_jfont *font);
t_max_err atom_setparse_debug(long *ac, t_atom **av, C74_CONST char *parsestr);
t_max_err atom_gettext_debug(long ac, t_atom *av, long *textsize, char **text, long flags = 0);
void bach_remove_from_memmap(void *x);
void bach_copyptr(const void *src, void *dst, long bytes);
void bach_store_in_memmap(void *x);
void bach_store_in_memmap_named(void *x, t_symbol *name);
char *bach_strdup(const char *src);
void bach_remove_from_memmap(void *x);
#endif

#ifndef BACH_TRACK_MEMORY_ALLOCATION
#define object_free_debug(x)									object_free(x)
#define object_release_debug(x)									object_release(x)
#define bach_newptr(size)										sysmem_newptr(size)
#define bach_newptrclear(size)									sysmem_newptrclear(size)
#define bach_resizeptr(ptr, newsize)							sysmem_resizeptr(ptr, newsize)
#define bach_resizeptrclear(ptr, newsize)						sysmem_resizeptrclear(ptr, newsize)
#define bach_newptr_named(size, name)							sysmem_newptr(size)
#define bach_newptrclear_named(size, name)						sysmem_newptrclear(size)
#define bach_freeptr(ptr)										sysmem_freeptr(ptr)
#define object_alloc_debug(c)									object_alloc(c)
#define object_retain_debug(x)									object_retain(x)
#define atomarray_new_debug(ac, av)								atomarray_new(ac, av)
#define hashtab_new_debug(slotcount)							hashtab_new(slotcount)
#define linklist_new_debug()									linklist_new()
#define dictionary_new_debug()									dictionary_new()
#define	proxy_new_debug(o, id, stuffloc)						proxy_new(o, id, stuffloc)
#define object_new_typed_debug(namespace, classname, ac, av)	object_new_typed(namespace, classname, ac, av)
#define systhread_mutex_new_debug(pmutex, flags)				systhread_mutex_new(pmutex, flags)
#define systhread_mutex_free_debug(pmutex)						systhread_mutex_free(pmutex)
#define clock_new_debug(obj, fn)								clock_new(obj, fn)
#define qelem_new_debug(obj, fn)								qelem_new(obj, fn)
#define qelem_free_debug(obj)									qelem_free(obj)
#define charset_unicodetoutf8_debug(s, len, outlen)				charset_unicodetoutf8(s, len, outlen)
#define charset_utf8tounicode_debug(s, outlen)					charset_utf8tounicode(s, outlen)
#define jfont_create_debug(family, slant, weight, size)			jfont_create(family, slant, weight, size)
#define jfont_destroy_debug(font)								jfont_destroy(font)
#define	atom_setparse_debug(ac, av, parsestr)					atom_setparse(ac, av, parsestr)
#define atom_gettext_debug(ac, av, textsize, text, flags)		atom_gettext(ac, av, textsize, text, flags)
#define bach_copyptr(src, dst, bytes)							sysmem_copyptr(src, dst, bytes)
#define bach_strdup(src)										strdup(src)

#define bach_remove_from_memmap(x)								((void) 0)
#endif // BACH_TRACK_MEMORY_ALLOCATION





// two macros for quick data validation.
// if check == 0, post text and goto label...

#define bach_assert_objerror_goto(obj, check, text, label) { \
if (!(check)) { \
if (obj) \
object_error(((t_object *) obj), (text)); \
else \
error((text));\
goto label; \
} \
}

// ... also setting errvar to check
#define bach_assert_objerror_goto_seterr(obj, check, text, label, errvar) { \
if (!(errvar = (check))) { \
if (obj) \
object_error(((t_object *) obj), (text)); \
else \
error((text));\
goto label; \
} \
}



// trigger a breakpoint of test == 0 (doesn't seem to work with LLVM 5)
void bach_breakpoint(long test);

// post txt and trigger a breakpoint (doesn't seem to work with LLVM 5)
void bach_error_break(const char *txt);

// object_post txt and trigger a breakpoint (doesn't seem to work with LLVM 5)
void bach_object_warn_break(t_object *x, const char *txt);


// a supposedly faster way to copy a model into an array a power-of-two number of times
void bach_fill_2n_array(void *model, void *dst, size_t src_size, long dst_items);



#endif /* bach_mem_h */
