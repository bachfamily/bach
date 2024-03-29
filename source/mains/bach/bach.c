/*
 *  bach.c
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

//#include <Foundation/Foundation.h>

#include "foundation/llll_files.h"
#include "ext_globalsymbol.h"
#include "ext_common.h"
#include "graphics/bach_cursors.h"
#include "patreon/patrons.h"
#include <stdlib.h>
#include <algorithm>
#include <string>
#ifdef BACH_TRACK_MEMORY_ALLOCATION
#ifdef MAC_VERSION
#include <execinfo.h>
#endif
#endif

#include "graphics/bach_graphics.h"

#ifdef MAC_VERSION
#include "pwd.h"
#endif

#ifdef WIN_VERSION
//#define BACH_SLEEP_BEFORE_INIT
#endif

#ifdef WIN_VERSION_old
HINSTANCE hinst;
#endif

#include "bell/ast.hpp"
#include "bell/pvManager.hpp"

long *bach_gen_primes(void);

t_class *bach_class = NULL;
t_class *initpargs_class = NULL;

extern t_bach *bach;

t_bool bach_exists = false;


#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
//#ifdef BACH_SAVE_STACK_IN_LLLLS
void bach_dump(t_bach *x);
void bach_post_mmi(t_bach *x, t_memmap_item *mmi);
void bach_dumpreduced(t_bach *x);
void bach_forget_progeny(void *ancestor, t_memmap_item **mmi_arr, long count, long *reduced_count);
void bach_ht_to_array_one(t_hashtab_entry *e, t_memmap_item ***arr_item);
void bach_clear(t_bach *x);
void bach_trace(t_bach *x);
void bach_get_memmap_as_array(t_bach *x, long *count, t_memmap_item ***memmap_as_array);
int bach_mmi_comp(const t_memmap_item **a, const t_memmap_item **b);
//#endif
#endif

void bach_poolstatus(t_bach *x);
void bach_pooldump(t_bach *x);
void bach_version(t_bach *x);
void bach_ss(t_bach *x, t_object *obj);
void bach_printglobals(t_bach *x);
void bach_printglobalswithvalues(t_bach *x);
void bach_clearglobals(t_bach *x);
void bach_sendbuildnumber(t_bach *x, t_symbol *s);
void bach_sendversion(t_bach *x, t_symbol *s);
void bach_sendversionwithbuildnumber(t_bach *x, t_symbol *s);
void bach_sendplatform(t_bach *x, t_symbol *s);
void bach_donors(t_bach *x);
void bach_installatompackage(t_bach *x);
void bach_clearatomcachefolder(t_bach *x);
void bach_unlock(t_bach *x, t_atom_long l);
void bach_nonative(t_bach *x, t_atom_long l);
void *bach_llll_from_phonenumber_and_retain(t_bach *x, t_atom_long l);
void bach_init_print(t_bach *x, t_symbol *s, long ac, t_atom *av);
char bach_load_default_font(void);
long bach_getbuildnumber(void);
void bach_init_bifs(t_bach *x);
t_symbol *get_buildnumber_sym(void);

t_uint32 murmur3(const t_uint32 key);
t_bool bach_checkauth();

t_bach *bach_new(t_symbol *s, long ac, t_atom *av);

typedef struct _initpargs
{
    struct llllobj_object     n_ob;
    t_hashtab                *n_objs_to_process;
    long                    n_nested;
    //void                    *n_qelem;
} t_initpargs;

typedef struct _objpos
{
    t_object    *o_obj;
    long        o_depth;
    long        o_calcdepth;
} t_objpos;

t_initpargs *initpargs_new(t_symbol *s, short ac, t_atom *av);
void initpargs_free(t_initpargs *x);

void initpargs_add(t_initpargs *x, t_symbol *msg, long ac, t_atom *av);
void initpargs_remove(t_initpargs *x, t_symbol *msg, long ac, t_atom *av);
t_max_err initpargs_run(t_initpargs *x, t_symbol *msg, long ac, t_atom *av);



void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;

    if (gensym("bach")->s_thing) {
        if (!bach_exists) {
            error("Can't instantiate bach");
        }
        return;
    }
    
    common_symbols_init();
    
    if (llllobj_common_symbols_init() != MAX_ERR_NONE) {
        error("Couldn't instantiate the bach common symbols table.");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c,"bach", (method) bach_new, NULL, sizeof(t_bach), 0, A_GIMME, 0);

    class_addmethod(c, (method) bach_poolstatus, "poolstatus", 0);
    class_addmethod(c, (method) bach_pooldump, "pooldump", 0);
    class_addmethod(c, (method) bach_version, "version", 0);
    class_addmethod(c, (method) bach_ss, "ss", A_OBJ, 0);
    class_addmethod(c, (method) bach_printglobals, "printglobals", 0);
    class_addmethod(c, (method) bach_printglobalswithvalues, "printglobalswithvalues", 0);
    class_addmethod(c, (method) bach_clearglobals, "clearglobals", 0);
    class_addmethod(c, (method) bach_sendversion, "sendversion", A_SYM, 0);
    class_addmethod(c, (method) bach_sendversionwithbuildnumber, "sendversionwithbuildnumber", A_SYM, 0);
    class_addmethod(c, (method) bach_sendplatform, "sendplatform", A_SYM, 0);
    class_addmethod(c, (method) bach_sendbuildnumber, "sendbuildnumber", A_SYM, 0);
    class_addmethod(c, (method) bach_donors, "donors", 0);
    class_addmethod(c, (method) bach_donors, "patrons", 0);
    class_addmethod(c, (method) bach_installatompackage, "installatompackage", 0);
    class_addmethod(c, (method) bach_clearatomcachefolder, "clearatomcachefolder", 0);

    class_addmethod(c, (method) bach_unlock, "unlock", A_LONG, 0);
    class_addmethod(c, (method) bach_nonative, "nonative", A_LONG, 0);
    class_addmethod(c, (method) bach_init_bifs, "initbifs", 0);
    class_addmethod(c, (method) bach_llll_from_phonenumber_and_retain, "llllfromphonenumberandretain", A_LONG, 0);

    
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
//#ifdef BACH_SAVE_STACK_IN_LLLLS
    class_addmethod(c, (method) bach_dump, "dump", 0);
    class_addmethod(c, (method) bach_dumpreduced, "dumpreduced", 0);
    class_addmethod(c, (method) bach_trace, "trace", 0);
    class_addmethod(c, (method) bach_clear, "clear", 0);
//#endif
#endif
    
    class_register(CLASS_NOBOX, c);
    bach_class = c;
    
#ifdef BACH_PRELOAD_CURSORS
    t_bach_resources *resources = (t_bach_resources *)sysmem_newptr(sizeof(t_bach_resources));
    load_cursors(resources, moduleRef);
    _llllobj_sym_bachcursors->s_thing = (t_object *)resources;
#endif
    
    bach_load_default_font();
    
    t_bach *b = bach_new(NULL, 0, NULL); // among other things, also fills the version number fields
    
    bach_version(b); // posts the version
    
    CLASS_NEW_CHECK_SIZE(c,"bach.initpargs", (method)initpargs_new, (method)initpargs_free, (long) sizeof(t_initpargs), 0L, A_GIMME, 0);
    
    class_addmethod(c, (method)initpargs_add,        "add",    A_GIMME,    0);
    class_addmethod(c, (method)initpargs_remove,    "remove",    A_GIMME,    0);
    class_addmethod(c, (method)initpargs_run,        "run",    A_GIMME,    0);
    
    bachobject_class_add_fileusage_method(c);

    class_register(CLASS_NOBOX, c);
    initpargs_class = c;
    
    //dev_post("bach.initpargs compiled %s %s", __DATE__, __TIME__);
    
    bach_exists = true;
    
    return;
}

void bach_resetloadtime(t_bach *x)
{
    x->b_loadtime = 0;
}

#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
//#ifdef BACH_SAVE_STACK_IN_LLLLS
void bach_dump(t_bach *x)
{
    long i;
    long count;
    t_memmap_item **memmap_as_array, **this_memmap_as_array;
    bach_get_memmap_as_array(x, &count, &memmap_as_array);

    object_post((t_object *) x, "%ld allocated things", count);
    for (i = 0, this_memmap_as_array = memmap_as_array; i < count; i++, this_memmap_as_array++)
        bach_post_mmi(x, *this_memmap_as_array);
    sysmem_freeptr(memmap_as_array);
}

void bach_post_mmi(t_bach *x, t_memmap_item *mmi)
{
    if (mmi->m_name)
        object_post((t_object *) x, "  %p: size = %ld, name = %s", mmi->m_word.w_void, mmi->m_size, mmi->m_name->s_name);
    else
        object_post((t_object *) x, "  %p: size = %ld", mmi->m_word.w_void, mmi->m_size);
}

void bach_dumpreduced(t_bach *x)
{
    long i;
    long count, reduced_count;
    t_memmap_item **memmap_as_array, **this_memmap_as_array;
    
    // first, put everything that's in the memmap into an array
    bach_get_memmap_as_array(x, &count, &memmap_as_array);
    reduced_count = count;
    
    // now, start stripping away stuff from the array
    for (i = 0, this_memmap_as_array = memmap_as_array; i < count; i++, this_memmap_as_array++) {
        if (*this_memmap_as_array)
            bach_forget_progeny((*this_memmap_as_array)->m_word.w_void, memmap_as_array, count, &reduced_count);
    }
    
    object_post((t_object *) x, "%ld allocated reduced things", reduced_count);
    // and now post what's left in the array
    for (i = 0, this_memmap_as_array = memmap_as_array; i < count; i++, this_memmap_as_array++) {
        if (*this_memmap_as_array) {
            bach_post_mmi(x, *this_memmap_as_array);
            if ((*this_memmap_as_array)->m_name == _llllobj_sym__llll)
                llll_print((*this_memmap_as_array)->m_word.w_llll, NULL, 0, 6, NULL);
        }
    }
    sysmem_freeptr(memmap_as_array);
}


void bach_get_memmap_as_array(t_bach *x, long *count, t_memmap_item ***memmap_as_array)
{
    t_memmap_item **this_memmap_as_array;
    *count = hashtab_getsize(x->b_memmap);
    this_memmap_as_array = *memmap_as_array = (t_memmap_item **) sysmem_newptr(*count * sizeof(t_memmap_item *));
    hashtab_funall(x->b_memmap, (method) bach_ht_to_array_one, &this_memmap_as_array);
    qsort(*memmap_as_array, *count, sizeof(t_memmap_item *), (qsort_fn) bach_mmi_comp);
}

int bach_mmi_comp(const t_memmap_item **a, const t_memmap_item **b)
{
    return (*a)->m_order - (*b)->m_order;
//    return (*(t_memmap_item **) b)->m_time - (*(t_memmap_item **) a)->m_time;
}

void bach_clear(t_bach *x)
{
    hashtab_clear(x->b_memmap);
}

// the progeny of ancestor in the array will be recursively set to NULL
void bach_forget_progeny(void *ancestor, t_memmap_item **mmi_arr, long count, long *reduced_count)
{
    long i;
    t_memmap_item **this_mmi_arr;
    void *current;
    for (i = 0, this_mmi_arr = mmi_arr; i < count; i++, this_mmi_arr++) {
        if (*this_mmi_arr &&
            (((*this_mmi_arr)->m_name == _llllobj_sym__llll && (*this_mmi_arr)->m_word.w_llll->l_owner == ancestor) ||
             ((*this_mmi_arr)->m_name == _llllobj_sym__llllelem && (*this_mmi_arr)->m_word.w_llllelem->l_parent == ancestor))) {
            current = (*this_mmi_arr)->m_word.w_void;
            *this_mmi_arr = NULL;
            (*reduced_count)--;
            bach_forget_progeny(current, mmi_arr, count, reduced_count);
        }
    }
}

void bach_ht_to_array_one(t_hashtab_entry *e, t_memmap_item ***arr_item)
{
    t_memmap_item *mmi = (t_memmap_item *) e->value;
    **arr_item = mmi;
    (*arr_item)++;
}

void bach_trace(t_bach *x)
{
#ifdef MAC_VERSION
#ifdef BACH_TRACK_MEMORY_ALLOCATION
    void *backtraceFrames[128];
    int frameCount = backtrace(&backtraceFrames[0], 128);
    char **frameStrings = backtrace_symbols(&backtraceFrames[0], frameCount);
    
    if (frameStrings != NULL) {
        int i;
        char *this_fs;
        for(i = 0; i < frameCount; i++) {
            this_fs = frameStrings[i];
            if (this_fs == NULL) 
                break;
            object_post((t_object *) x, "%s", this_fs);
        }
        free(frameStrings);
    }
#endif // BACH_TRACK_MEMORY_ALLOCATION
#endif // MAC_VERSION
}

//#endif // BACH_SAVE_STACK_IN_LLLLS
#endif // BACH_SAVE_STACK_WITH_MEMORY_LOGS

void bach_poolstatus(t_bach *x)
{
    object_post((t_object *) x, "----------------------------");
    object_post((t_object *) x, "llll_current_phonebook_idx: %d", x->b_llll_current_phonebook_idx);
    object_post((t_object *) x, "llll_pool_size: %d", x->b_llll_pool_size);
    object_post((t_object *) x, "llllelem_current_phonebook_idx: %d", x->b_llllelem_current_phonebook_idx);
    object_post((t_object *) x, "llllelem_pool_size: %d", x->b_llllelem_pool_size);
    object_post((t_object *) x, "----------------------------");
}

void bach_pooldump(t_bach *x)
{
    unsigned long page, row;
    object_post((t_object *) x, "----------------------------");
    for (page = 0; page + BACH_LLLL_PAGE_SIZE < x->b_llll_current_phonebook_idx; page += BACH_LLLL_PAGE_SIZE) {
        for (row = 0; row < BACH_LLLL_PAGE_SIZE; row++) {
            t_uint32 phonenumber = x->b_llll_phonebook[page / BACH_LLLL_PAGE_SIZE][row];
            t_llll *ll = x->b_llll_book[phonenumber / BACH_LLLL_PAGE_SIZE] + phonenumber % BACH_LLLL_PAGE_SIZE;
            object_post((t_object *) bach, "--------");
            object_post((t_object *) bach, "phonenumber: %u", phonenumber);
            object_post((t_object *) bach, "count: %d", ll->l_count);
            llll_print(ll, (t_object *) bach, 0, 6, NULL);
            object_post((t_object *) bach, "--------");

        }
    }
    for (row = 0; row < x->b_llll_current_phonebook_idx % BACH_LLLL_PAGE_SIZE; row++) {
        t_uint32 phonenumber = x->b_llll_phonebook[page / BACH_LLLL_PAGE_SIZE][row];
        t_llll *ll = x->b_llll_book[phonenumber / BACH_LLLL_PAGE_SIZE] + phonenumber % BACH_LLLL_PAGE_SIZE;
        object_post((t_object *) bach, "--------");
        object_post((t_object *) bach, "phonenumber: %u", phonenumber);
        object_post((t_object *) bach, "count: %d", ll->l_count);
        llll_print(ll, (t_object *) bach, 0, 6, NULL);
        object_post((t_object *) bach, "--------");
    }
    object_post((t_object *) x, "----------------------------");
}


void bach_version(t_bach *x)
{
    
    post("--- bach: automated composer's helper ---");
    post("© 2010-2022 - Andrea Agostini and Daniele Ghisi");
    if (x && x->b_no_ss) {
        post("♥ Thank you so much for supporting us on Patreon! ♥");
    } else {
        post("The bach project is maintained thanks to our generous supporters on Patreon.");
        post("Please consider supporting us on www.patreon.com/bachproject for as little as the price of a coffee.");
    }
    post("Our top-tier Patreon institutional supporters are: HEM-CME (Genève) and IRCAM (Paris).");

    
// Post version
    char version_buf[4096];
#ifdef MAC_VERSION
#ifdef CONFIGURATION_Development
    snprintf_zero(version_buf, 4096, "%s", bach->b_version_string_verbose_with_build);
#else 
    snprintf_zero(version_buf, 4096, "%s", bach->b_version_string_verbose);
#endif
#else
    snprintf_zero(version_buf, 4096, "%s", bach->b_version_string_verbose);
#endif
    post(version_buf);
    
    
    dev_post("bach compiled %s %s", __DATE__, __TIME__);
#ifdef C74_X64
    dev_post("--- DEVELOPMENT BUILD - 64-bit version ---");
#else
    dev_post("--- DEVELOPMENT BUILD - 32-bit version ---");
#endif
    
#ifdef __clang__
    dev_post("--- built with clang");
#endif
    
#ifdef BACH_USE_NATIVE_128BIT_INTEGER
    dev_post("--- Using native 128 bit integer");
#else
    dev_post("--- Using 128 bit integer C++ class");
#endif
    
#ifdef BACH_SHOW_POOL_USAGE
    dev_post("--- BACH_SHOW_POOL_USAGE active");
#endif
    
#ifdef BACH_CHECK_LLLLS
    dev_post("--- BACH_CHECK_LLLLS active");
#endif
    
#ifdef BACH_PEDANTICALLY_CHECK_LLLLS
    dev_post("--- BACH_PEDANTICALLY_CHECK_LLLLS active");
#endif
    
#ifdef BACH_PEDANTICALLY_CHECK_LLLLS
    dev_post("--- BACH_CHECK_PHONENUMBERS active");
#endif
    
#ifdef BACH_PEDANTICALLY_CHECK_LLLLS
    dev_post("--- BACH_USE_MAGIC_NUMBER active");
#endif
    
#ifdef BACH_TRACK_MEMORY_ALLOCATION
    dev_post("--- BACH_TRACK_MEMORY_ALLOCATION active");
#endif
    
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
    dev_post("--- BACH_SAVE_STACK_WITH_MEMORY_LOGS active");
#endif
    
#ifdef BACH_BLOAT_FREED_MEMORY
    dev_post("--- BACH_BLOAT_FREED_MEMORY active");
#endif
    
#ifdef BACH_SAVE_STACK_IN_LLLLS
    dev_post("--- BACH_SAVE_STACK_IN_LLLLS active");
#endif
    
#ifdef BACH_ENABLE_BREAKPOINTS
    dev_post("--- BACH_ENABLE_BREAKPOINTS active");
#endif
    
#ifdef BACH_POST_STUFF_TO_CONSOLE
    dev_post("--- BACH_POST_STUFF_TO_CONSOLE active");
#endif
    
#ifdef BACH_PRELOAD_CURSORS
    dev_post("--- BACH_PRELOAD_CURSORS active");
#endif
    
    //llllobj_post_destructive_volatile();
    
    dev_post("--- llll page size: %ld", BACH_LLLL_PAGE_SIZE);
    dev_post("--- llll book size: %ld pages", BACH_LLLL_BOOK_SIZE);
    dev_post("--- llllelem page size: %ld", BACH_LLLLELEM_PAGE_SIZE);
    dev_post("--- llllelem book size: %ld pages", BACH_LLLLELEM_BOOK_SIZE);
    dev_post("--- size of t_llll: %ld", (long) sizeof(t_llll));
    dev_post("--- size of t_llllelem_numbered: %ld", (long) sizeof(t_llllelem_numbered));
    dev_post("--- size of t_hatom: %ld", (long) sizeof(t_hatom));
}

void bach_ss(t_bach *x, t_object *obj)
{
    bach_ss_display(obj);
}

void bach_printglobals(t_bach *x)
{
    x->b_gvt->postNames();
}

void bach_clearglobals(t_bach *x)
{
    x->b_gvt->clearAll();
}

void bach_printglobalswithvalues(t_bach *x)
{
    x->b_gvt->postNamesAndValues();
}

void bach_sendbuildnumber(t_bach *x, t_symbol *s)
{
    if (s && s->s_thing) {
        object_method_typed(s->s_thing, x->b_buildnumber_sym, 0, NULL, NULL);
    }
}

void bach_sendversion(t_bach *x, t_symbol *s)
{
    if (s && s->s_thing) {
        t_atom vnum;
        atom_setlong(&vnum, bach_get_current_version());
        object_method_typed(s->s_thing, gensym(bach_get_current_version_string_verbose()), 1, &vnum, NULL);
    }
}


void bach_sendversionwithbuildnumber(t_bach *x, t_symbol *s)
{
    if (s && s->s_thing) {
        t_atom vnum;
        atom_setlong(&vnum, bach_get_current_version());
        object_method_typed(s->s_thing, gensym(bach_get_current_version_string_verbose_with_build()), 1, &vnum, NULL);
    }
}

void bach_sendplatform(t_bach *x, t_symbol *s)
{
#ifdef MAC_VERSION
    t_symbol *platform = gensym("Mac");
#endif
#ifdef WIN_VERSION
    t_symbol *platform = gensym("Windows");
#endif
    t_atom arch;
#ifdef C74_X64
    atom_setlong(&arch, 64);
#else
    atom_setlong(&arch, 32);
#endif
    object_method_typed(s->s_thing, platform, 1, &arch, NULL);
}


void bach_donors(t_bach *x)
{
    post(" ");
    post("**************************************************************************");
    post("bach: automated composer's helper would like to thank our top-tier Patreon institutional supporters:");
//    post_institutional_supporters(); // not using this; better negotiate directly the names that should appear
    post("• Haute École de Musique de Genève - Centre de musique électroacoustique");
    post("• IRCAM-Centre Pompidou (Paris)");

    post("...as well as our top supporters:");

    // Pre-Patreon Supporters:
    post("- Cody Brookshire");
    post("- Dimitri Fergadis (aka Phthalocyanine, of A-Musik, Planet-Mu, and Plug Research, proprietor of Halocyan Records)");
    post("- Pete Kellock");
    
    // Patreon supporters:
    post_top_supporters();

    post("...and all our other patrons:");
    post_ordinary_supporters();
    
    post("for generously sustaining the development and maintenance of bach and its family.");
    post("---peace & love, bach");
    post("**************************************************************************");
    post(" ");
}

void bach_nonative(t_bach *x, t_atom_long l)
{
    x->b_nonative = l != 0;
}

void *bach_llll_from_phonenumber_and_retain(t_bach *x, t_atom_long l)
{
    return llll_retrieve_from_phonenumber_and_retain(l);
}



long parse_version_string(char *str, long *major, long *minor, long *revision, long *maintenance)
{
    long maj = 0, min = 0, rev = 0, maint = 0;
    long count = 0;
    char temp_str[128];
    snprintf_zero(temp_str, 128, "%s", str);
    
    char *pch = strtok(temp_str, ".");
    while (pch != NULL)
    {
        switch (count) {
            case 0: maj = atoi(pch); break;
            case 1: min = atoi(pch); break;
            case 2: rev = atoi(pch); break;
            case 3: maint = atoi(pch); break;
            default: break;
        }
        pch = strtok (NULL, ".");
        count++;
    }
    
    if (major) *major = maj;
    if (minor) *minor = min;
    if (revision) *revision = rev;
    if (maintenance) *maintenance = maint;
    
    return maint + rev * 100 + min * 10000 + maj * 1000000;
}

t_bach *bach_new(t_symbol *s, long ac, t_atom *av)
{
    if (bach || gensym("bach")->s_thing) {
        object_error_obtrusive(nullptr, "Can't instantiate bach. You might want to restart Max.");
        bach = nullptr;
//        gensym("bach")->s_thing = nullptr;
        return NULL;
    }
    
    if (gensym("ears")->s_thing) {
        object_warn(nullptr, "Symbol 'ears' is already in use.");
    } else {
        gensym("ears")->s_thing = (t_object *)WHITENULL;
    }
    
    t_bach *x = (t_bach *) object_alloc(bach_class);
#ifdef BACH_TRACK_MEMORY_ALLOCATION
    //t_object *dummy;
    //t_max_err err;
    gensym("bach")->s_thing = (t_object *) x;
    x->b_memmap = hashtab_new(20011);
    hashtab_flags(x->b_memmap, OBJ_FLAG_MEMORY);
    x->b_poolmap = hashtab_new(20011);
    hashtab_flags(x->b_poolmap, OBJ_FLAG_DATA);
#endif
    

    
    llll_reset(&x->b_llll_model);
    x->b_llll_book = (t_llll **) sysmem_newptr(BACH_LLLL_BOOK_SIZE * sizeof(t_llll *));
//    x->b_llll_book[0] = (t_llll *) sysmem_newptr(BACH_LLLL_PAGE_SIZE * sizeof(t_llll));
    x->b_llll_phonebook = (t_uint32 **) sysmem_newptr(BACH_LLLL_BOOK_SIZE * sizeof(t_uint32 *));
//    x->b_llll_phonebook[0] = (t_uint32 *) sysmem_newptr(BACH_LLLL_PAGE_SIZE * sizeof(t_uint32));
    x->b_llll_current_phonebook_idx = 0;
    x->b_llll_pool_size = 0; // BACH_LLLL_PAGE_SIZE;
/*    bach_fill_2n_array(&x->b_llll_model, x->b_llll_book[0], sizeof(t_llll), BACH_LLLL_PAGE_SIZE);
    for (i = 0; i < BACH_LLLL_PAGE_SIZE; i++) {
        (*x->b_llll_phonebook)[i] = i;
        (*x->b_llll_book)[i].l_phonenumber = i;
    }
*/

    llllelem_reset((t_llllelem *) &x->b_llllelem_model);
    x->b_llllelem_book = (t_llllelem_numbered **) sysmem_newptr(BACH_LLLLELEM_BOOK_SIZE * sizeof(t_llllelem_numbered *));
    //x->b_llllelem_book[0] = (t_llllelem *) sysmem_newptr(BACH_LLLLELEM_PAGE_SIZE * sizeof(t_llllelem));
    x->b_llllelem_phonebook = (t_uint32 **) sysmem_newptr(BACH_LLLLELEM_BOOK_SIZE * sizeof(t_uint32 *));
    //x->b_llllelem_phonebook[0] = (t_uint32 *) sysmem_newptr(BACH_LLLLELEM_PAGE_SIZE * sizeof(t_uint32));
    x->b_llllelem_current_phonebook_idx = 0;
    x->b_llllelem_pool_size = 0; // BACH_LLLLELEM_PAGE_SIZE;
/*    bach_fill_2n_array(&x->b_llllelem_model, x->b_llllelem_book[0], sizeof(t_llllelem), BACH_LLLLELEM_PAGE_SIZE);
    for (i = 0; i < BACH_LLLLELEM_PAGE_SIZE; i++) {
        (*x->b_llllelem_phonebook)[i] = i;
        (*x->b_llllelem_book)[i].l_phonenumber = i;
    }
*/

    x->b_primes = bach_gen_primes();
    x->b_helppatches = hashtab_new(0);
    x->b_portalpatchers = hashtab_new(0);
    hashtab_flags(x->b_helppatches, OBJ_FLAG_REF);
    systhread_mutex_new(&x->b_memmap_lock, 0);
    
    x->b_reservedselectors = hashtab_new(0);
    object_method(x->b_reservedselectors, gensym("readonly"), 1);
    
    //hashtab_store(x->b_reservedselectors, _sym_bang, (t_object *) x);
    
    hashtab_store(x->b_reservedselectors, _sym_int, (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in1"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in2"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in3"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in4"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in5"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in6"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in7"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in8"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("in9"), (t_object *) x);
    
    hashtab_store(x->b_reservedselectors, _sym_float, (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft1"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft2"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft3"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft4"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft5"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft6"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft7"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft8"), (t_object *) x);
    hashtab_store(x->b_reservedselectors, gensym("ft9"), (t_object *) x);
    
    hashtab_store(x->b_reservedselectors, _sym_list, (t_object *) x);
    //hashtab_store(x->b_reservedselectors, _sym_symbol, (t_object *) x);
    
    //hashtab_store(x->b_reservedselectors, _llllobj_sym_bach_llll, (t_object *) x);
    //hashtab_store(x->b_reservedselectors, _llllobj_sym_null, (t_object *) x);
    
    x->b_no_ss = bach_checkauth();
    
    bach_setup(x);
    
    x->b_buildnumber_sym = get_buildnumber_sym();

    
    // Filling version fields
    snprintf_zero(x->b_llll_version_string, 128, "%s", BACH_LLLL_VERSION);
    snprintf_zero(x->b_version_string, 128, "%s", BACH_VERSION);
    snprintf_zero(x->b_version_string_verbose, 128, "v%s beta", BACH_VERSION);
    x->b_version = parse_version_string(x->b_version_string, NULL, NULL, NULL, NULL);
    x->b_llll_version = parse_version_string(x->b_llll_version_string, NULL, NULL, NULL, NULL);
    snprintf_zero(x->b_version_string_verbose_with_build, 128, "v%s beta (build %s)", BACH_VERSION, x->b_buildnumber_sym->s_name);

    /*
    this_llll_pool_item = x->b_llll_pool;
    llll_pool_end = this_llll_pool_item + BACH_LLLL_POOL_SIZE;
    for (; this_llll_pool_item < llll_pool_end; this_llll_pool_item++) {
        *this_llll_pool_item = (t_llll *) sysmem_newptr(sizeof(t_llll));
#ifdef BACH_TRACK_MEMORY_ALLOCATION
        err = hashtab_lookup(x->b_poolmap, (t_symbol *) *this_llll_pool_item, &dummy);
        if (!err)
            bach_error_break("bach_new: error allocating the llll pool");
        hashtab_store(x->b_poolmap, (t_symbol *) *this_llll_pool_item, (t_object *) _llllobj_sym__llll);
#endif
    }
    
    this_llllelem_pool_item = x->b_llllelem_pool;
    llllelem_pool_end = this_llllelem_pool_item + BACH_LLLLELEM_POOL_SIZE;
    for (; this_llllelem_pool_item < llllelem_pool_end; this_llllelem_pool_item++) {
        *this_llllelem_pool_item = (t_llllelem *) sysmem_newptr(sizeof(t_llllelem));
#ifdef BACH_TRACK_MEMORY_ALLOCATION
        err = hashtab_lookup(x->b_poolmap, (t_symbol *) *this_llllelem_pool_item, &dummy);
        if (!err)
            bach_error_break("bach_new: error allocating the llll pool");
        hashtab_store(x->b_poolmap, (t_symbol *) *this_llllelem_pool_item, (t_object *) _llllobj_sym__llllelem);
#endif
    }    
*/
    object_register(CLASS_NOBOX, gensym("bach"), x);

    gensym("bach")->s_thing = (t_object *) x;
    
    defer_low(x, (method) bach_init_print, NULL, 0, NULL);
    return x;
}

t_symbol *get_buildnumber_sym(void)
{
    
    const std::string buildDate = __DATE__;
    const std::string buildTime = __TIME__;
    
    const std::string month = buildDate.substr(0, 3);
    const std::string day = buildDate.substr(4, 2);
    const std::string year = buildDate.substr(7, 4);
    
    const std::string hour = buildTime.substr(0, 2);
    const std::string min = buildTime.substr(3, 2);
    const std::string sec = buildTime.substr(6, 2);
    
    std::string monthNum;
    if (month == "Jan")
        monthNum = "01";
    else if (month == "Feb")
        monthNum = "02";
    else if (month == "Mar")
        monthNum = "03";
    else if (month == "Apr")
        monthNum = "04";
    else if (month == "May")
        monthNum = "05";
    else if (month == "Jun")
        monthNum = "06";
    else if (month == "Jul")
        monthNum = "07";
    else if (month == "Aug")
        monthNum = "08";
    else if (month == "Sep")
        monthNum = "09";
    else if (month == "Oct")
        monthNum = "10";
    else if (month == "Nov")
        monthNum = "11";
    else if (month == "Dec")
        monthNum = "12";
    else
        monthNum = "00";
    
    
    std::string bn;
    bn = year + monthNum + day + hour + min + sec;
    std::replace(bn.begin(), bn.end(), ' ', '0');
    return gensym(bn.c_str());
}

void bach_init_print(t_bach *x, t_symbol *s, long ac, t_atom *av)
{
    t_object *printobj = (t_object *) object_new_typed(CLASS_BOX, _sym_print, 0, NULL);
    if (!printobj)
        printobj = (t_object *) newinstance(_sym_print, 0, NULL);
    object_free(printobj);
}

long *bach_gen_primes(void)
{
    static long primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 
        199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 
        317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 
        443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 
        577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 
        701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 
        839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 
        983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 
        1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 
        1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 
        1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 
        1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 
        1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 
        1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 
        1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 
        1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 
        2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 
        2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 
        2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 
        2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 
        2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 
        2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 
        2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 
        3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 
        3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 
        3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 
        3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 
        3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 
        3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 
        3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 
        4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 
        4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 
        4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 
        4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 
        4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 
        4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 
        4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023, 5039, 
        5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197, 
        5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 
        5387, 5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483, 5501, 
        5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639, 5641, 5647, 5651, 
        5653, 5657, 5659, 5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791, 
        5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 
        5923, 5927, 5939, 5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067, 6073, 6079, 6089, 
        6091, 6101, 6113, 6121, 6131, 6133, 6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221, 6229, 
        6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 
        6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547, 
        6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 
        6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 
        6833, 6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 6947, 6949, 6959, 6961, 6967, 6971, 
        6977, 6983, 6991, 6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 7109, 7121, 7127, 
        7129, 7151, 7159, 7177, 7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 
        7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457, 7459, 7477, 7481, 
        7487, 7489, 7499, 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 
        7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 
        7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 
        7907, 7919, 7927, 7933, 7937, 7949, 7951, 7963, 7993, 8009, 8011, 8017, 8039, 8053, 8059, 8069, 8081, 
        8087, 8089, 8093, 8101, 8111, 8117, 8123, 8147, 8161, 8167, 8171, 8179, 8191, 8209, 8219, 8221, 8231, 
        8233, 8237, 8243, 8263, 8269, 8273, 8287, 8291, 8293, 8297, 8311, 8317, 8329, 8353, 8363, 8369, 8377, 
        8387, 8389, 8419, 8423, 8429, 8431, 8443, 8447, 8461, 8467, 8501, 8513, 8521, 8527, 8537, 8539, 8543, 
        8563, 8573, 8581, 8597, 8599, 8609, 8623, 8627, 8629, 8641, 8647, 8663, 8669, 8677, 8681, 8689, 8693, 
        8699, 8707, 8713, 8719, 8731, 8737, 8741, 8747, 8753, 8761, 8779, 8783, 8803, 8807, 8819, 8821, 8831, 
        8837, 8839, 8849, 8861, 8863, 8867, 8887, 8893, 8923, 8929, 8933, 8941, 8951, 8963, 8969, 8971, 8999, 
        9001, 9007, 9011, 9013, 9029, 9041, 9043, 9049, 9059, 9067, 9091, 9103, 9109, 9127, 9133, 9137, 9151, 
        9157, 9161, 9173, 9181, 9187, 9199, 9203, 9209, 9221, 9227, 9239, 9241, 9257, 9277, 9281, 9283, 9293, 
        9311, 9319, 9323, 9337, 9341, 9343, 9349, 9371, 9377, 9391, 9397, 9403, 9413, 9419, 9421, 9431, 9433, 
        9437, 9439, 9461, 9463, 9467, 9473, 9479, 9491, 9497, 9511, 9521, 9533, 9539, 9547, 9551, 9587, 9601, 
        9613, 9619, 9623, 9629, 9631, 9643, 9649, 9661, 9677, 9679, 9689, 9697, 9719, 9721, 9733, 9739, 9743, 
        9749, 9767, 9769, 9781, 9787, 9791, 9803, 9811, 9817, 9829, 9833, 9839, 9851, 9857, 9859, 9871, 9883, 
        9887, 9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973, 10007, 10009, 10037, 10039, 10061, 10067, 
        10069, 10079, 10091, 10093, 10099, 10103, 10111, 10133, 10139, 10141, 10151, 10159, 10163, 10169, 10177, 
        10181, 10193, 10211, 10223, 10243, 10247, 10253, 10259, 10267, 10271, 10273, 10289, 10301, 10303, 10313, 
        10321, 10331, 10333, 10337, 10343, 10357, 10369, 10391, 10399, 10427, 10429, 10433, 10453, 10457, 10459, 
        10463, 10477, 10487, 10499, 10501, 10513, 10529, 10531, 10559, 10567, 10589, 10597, 10601, 10607, 10613, 
        10627, 10631, 10639, 10651, 10657, 10663, 10667, 10687, 10691, 10709, 10711, 10723, 10729, 10733, 10739, 
        10753, 10771, 10781, 10789, 10799, 10831, 10837, 10847, 10853, 10859, 10861, 10867, 10883, 10889, 10891, 
        10903, 10909, 10937, 10939, 10949, 10957, 10973, 10979, 10987, 10993, 11003, 11027, 11047, 11057, 11059, 
        11069, 11071, 11083, 11087, 11093, 11113, 11117, 11119, 11131, 11149, 11159, 11161, 11171, 11173, 11177, 
        11197, 11213, 11239, 11243, 11251, 11257, 11261, 11273, 11279, 11287, 11299, 11311, 11317, 11321, 11329, 
        11351, 11353, 11369, 11383, 11393, 11399, 11411, 11423, 11437, 11443, 11447, 11467, 11471, 11483, 11489, 
        11491, 11497, 11503, 11519, 11527, 11549, 11551, 11579, 11587, 11593, 11597, 11617, 11621, 11633, 11657, 
        11677, 11681, 11689, 11699, 11701, 11717, 11719, 11731, 11743, 11777, 11779, 11783, 11789, 11801, 11807, 
        11813, 11821, 11827, 11831, 11833, 11839, 11863, 11867, 11887, 11897, 11903, 11909, 11923, 11927, 11933, 
        11939, 11941, 11953, 11959, 11969, 11971, 11981, 11987, 12007, 12011, 12037, 12041, 12043, 12049, 12071, 
        12073, 12097, 12101, 12107, 12109, 12113, 12119, 12143, 12149, 12157, 12161, 12163, 12197, 12203, 12211, 
        12227, 12239, 12241, 12251, 12253, 12263, 12269, 12277, 12281, 12289, 12301, 12323, 12329, 12343, 12347, 
        12373, 12377, 12379, 12391, 12401, 12409, 12413, 12421, 12433, 12437, 12451, 12457, 12473, 12479, 12487, 
        12491, 12497, 12503, 12511, 12517, 12527, 12539, 12541, 12547, 12553, 12569, 12577, 12583, 12589, 12601, 
        12611, 12613, 12619, 12637, 12641, 12647, 12653, 12659, 12671, 12689, 12697, 12703, 12713, 12721, 12739, 
        12743, 12757, 12763, 12781, 12791, 12799, 12809, 12821, 12823, 12829, 12841, 12853, 12889, 12893, 12899, 
        12907, 12911, 12917, 12919, 12923, 12941, 12953, 12959, 12967, 12973, 12979, 12983, 13001, 13003, 13007, 
        13009, 13033, 13037, 13043, 13049, 13063, 13093, 13099, 13103, 13109, 13121, 13127, 13147, 13151, 13159, 
        13163, 13171, 13177, 13183, 13187, 13217, 13219, 13229, 13241, 13249, 13259, 13267, 13291, 13297, 13309, 
        13313, 13327, 13331, 13337, 13339, 13367, 13381, 13397, 13399, 13411, 13417, 13421, 13441, 13451, 13457, 
        13463, 13469, 13477, 13487, 13499, 13513, 13523, 13537, 13553, 13567, 13577, 13591, 13597, 13613, 13619, 
        13627, 13633, 13649, 13669, 13679, 13681, 13687, 13691, 13693, 13697, 13709, 13711, 13721, 13723, 13729, 
        13751, 13757, 13759, 13763, 13781, 13789, 13799, 13807, 13829, 13831, 13841, 13859, 13873, 13877, 13879, 
        13883, 13901, 13903, 13907, 13913, 13921, 13931, 13933, 13963, 13967, 13997, 13999, 14009, 14011, 14029, 
        14033, 14051, 14057, 14071, 14081, 14083, 14087, 14107, 14143, 14149, 14153, 14159, 14173, 14177, 14197, 
        14207, 14221, 14243, 14249, 14251, 14281, 14293, 14303, 14321, 14323, 14327, 14341, 14347, 14369, 14387, 
        14389, 14401, 14407, 14411, 14419, 14423, 14431, 14437, 14447, 14449, 14461, 14479, 14489, 14503, 14519, 
        14533, 14537, 14543, 14549, 14551, 14557, 14561, 14563, 14591, 14593, 14621, 14627, 14629, 14633, 14639, 
        14653, 14657, 14669, 14683, 14699, 14713, 14717, 14723, 14731, 14737, 14741, 14747, 14753, 14759, 14767, 
        14771, 14779, 14783, 14797, 14813, 14821, 14827, 14831, 14843, 14851, 14867, 14869, 14879, 14887, 14891, 
        14897, 14923, 14929, 14939, 14947, 14951, 14957, 14969, 14983, 15013, 15017, 15031, 15053, 15061, 15073, 
        15077, 15083, 15091, 15101, 15107, 15121, 15131, 15137, 15139, 15149, 15161, 15173, 15187, 15193, 15199, 
        15217, 15227, 15233, 15241, 15259, 15263, 15269, 15271, 15277, 15287, 15289, 15299, 15307, 15313, 15319, 
        15329, 15331, 15349, 15359, 15361, 15373, 15377, 15383, 15391, 15401, 15413, 15427, 15439, 15443, 15451, 
        15461, 15467, 15473, 15493, 15497, 15511, 15527, 15541, 15551, 15559, 15569, 15581, 15583, 15601, 15607, 
        15619, 15629, 15641, 15643, 15647, 15649, 15661, 15667, 15671, 15679, 15683, 15727, 15731, 15733, 15737, 
        15739, 15749, 15761, 15767, 15773, 15787, 15791, 15797, 15803, 15809, 15817, 15823, 15859, 15877, 15881, 
        15887, 15889, 15901, 15907, 15913, 15919, 15923, 15937, 15959, 15971, 15973, 15991, 16001, 16007, 16033, 
        16057, 16061, 16063, 16067, 16069, 16073, 16087, 16091, 16097, 16103, 16111, 16127, 16139, 16141, 16183, 
        16187, 16189, 16193, 16217, 16223, 16229, 16231, 16249, 16253, 16267, 16273, 16301, 16319, 16333, 16339, 
        16349, 16361, 16363, 16369, 16381, 16411, 16417, 16421, 16427, 16433, 16447, 16451, 16453, 16477, 16481, 
        16487, 16493, 16519, 16529, 16547, 16553, 16561, 16567, 16573, 16603, 16607, 16619, 16631, 16633, 16649, 
        16651, 16657, 16661, 16673, 16691, 16693, 16699, 16703, 16729, 16741, 16747, 16759, 16763, 16787, 16811, 
        16823, 16829, 16831, 16843, 16871, 16879, 16883, 16889, 16901, 16903, 16921, 16927, 16931, 16937, 16943, 
        16963, 16979, 16981, 16987, 16993, 17011, 17021, 17027, 17029, 17033, 17041, 17047, 17053, 17077, 17093, 
        17099, 17107, 17117, 17123, 17137, 17159, 17167, 17183, 17189, 17191, 17203, 17207, 17209, 17231, 17239, 
        17257, 17291, 17293, 17299, 17317, 17321, 17327, 17333, 17341, 17351, 17359, 17377, 17383, 17387, 17389, 
        17393, 17401, 17417, 17419, 17431, 17443, 17449, 17467, 17471, 17477, 17483, 17489, 17491, 17497, 17509, 
        17519, 17539, 17551, 17569, 17573, 17579, 17581, 17597, 17599, 17609, 17623, 17627, 17657, 17659, 17669, 
        17681, 17683, 17707, 17713, 17729, 17737, 17747, 17749, 17761, 17783, 17789, 17791, 17807, 17827, 17837, 
        17839, 17851, 17863, 17881, 17891, 17903, 17909, 17911, 17921, 17923, 17929, 17939, 17957, 17959, 17971, 
        17977, 17981, 17987, 17989, 18013, 18041, 18043, 18047, 18049, 18059, 18061, 18077, 18089, 18097, 18119, 
        18121, 18127, 18131, 18133, 18143, 18149, 18169, 18181, 18191, 18199, 18211, 18217, 18223, 18229, 18233, 
        18251, 18253, 18257, 18269, 18287, 18289, 18301, 18307, 18311, 18313, 18329, 18341, 18353, 18367, 18371, 
        18379, 18397, 18401, 18413, 18427, 18433, 18439, 18443, 18451, 18457, 18461, 18481, 18493, 18503, 18517, 
        18521, 18523, 18539, 18541, 18553, 18583, 18587, 18593, 18617, 18637, 18661, 18671, 18679, 18691, 18701, 
        18713, 18719, 18731, 18743, 18749, 18757, 18773, 18787, 18793, 18797, 18803, 18839, 18859, 18869, 18899, 
        18911, 18913, 18917, 18919, 18947, 18959, 18973, 18979, 19001, 19009, 19013, 19031, 19037, 19051, 19069, 
        19073, 19079, 19081, 19087, 19121, 19139, 19141, 19157, 19163, 19181, 19183, 19207, 19211, 19213, 19219, 
        19231, 19237, 19249, 19259, 19267, 19273, 19289, 19301, 19309, 19319, 19333, 19373, 19379, 19381, 19387, 
        19391, 19403, 19417, 19421, 19423, 19427, 19429, 19433, 19441, 19447, 19457, 19463, 19469, 19471, 19477, 
        19483, 19489, 19501, 19507, 19531, 19541, 19543, 19553, 19559, 19571, 19577, 19583, 19597, 19603, 19609, 
        19661, 19681, 19687, 19697, 19699, 19709, 19717, 19727, 19739, 19751, 19753, 19759, 19763, 19777, 19793, 
        19801, 19813, 19819, 19841, 19843, 19853, 19861, 19867, 19889, 19891, 19913, 19919, 19927, 19937, 19949, 
        19961, 19963, 19973, 19979, 19991, 19993, 19997, 20011, 20021, 20023, 20029, 20047, 20051, 20063, 20071, 
        20089, 20101, 20107, 20113, 20117, 20123, 20129, 20143, 20147, 20149, 20161, 20173, 20177, 20183, 20201, 
        20219, 20231, 20233, 20249, 20261, 20269, 20287, 20297, 20323, 20327, 20333, 20341, 20347, 20353, 20357, 
        20359, 20369, 20389, 20393, 20399, 20407, 20411, 20431, 20441, 20443, 20477, 20479, 20483, 20507, 20509, 
        20521, 20533, 20543, 20549, 20551, 20563, 20593, 20599, 20611, 20627, 20639, 20641, 20663, 20681, 20693, 
        20707, 20717, 20719, 20731, 20743, 20747, 20749, 20753, 20759, 20771, 20773, 20789, 20807, 20809, 20849, 
        20857, 20873, 20879, 20887, 20897, 20899, 20903, 20921, 20929, 20939, 20947, 20959, 20963, 20981, 20983, 
        21001, 21011, 21013, 21017, 21019, 21023, 21031, 21059, 21061, 21067, 21089, 21101, 21107, 21121, 21139, 
        21143, 21149, 21157, 21163, 21169, 21179, 21187, 21191, 21193, 21211, 21221, 21227, 21247, 21269, 21277, 
        21283, 21313, 21317, 21319, 21323, 21341, 21347, 21377, 21379, 21383, 21391, 21397, 21401, 21407, 21419, 
        21433, 21467, 21481, 21487, 21491, 21493, 21499, 21503, 21517, 21521, 21523, 21529, 21557, 21559, 21563, 
        21569, 21577, 21587, 21589, 21599, 21601, 21611, 21613, 21617, 21647, 21649, 21661, 21673, 21683, 21701, 
        21713, 21727, 21737, 21739, 21751, 21757, 21767, 21773, 21787, 21799, 21803, 21817, 21821, 21839, 21841, 
        21851, 21859, 21863, 21871, 21881, 21893, 21911, 21929, 21937, 21943, 21961, 21977, 21991, 21997, 22003, 
        22013, 22027, 22031, 22037, 22039, 22051, 22063, 22067, 22073, 22079, 22091, 22093, 22109, 22111, 22123, 
        22129, 22133, 22147, 22153, 22157, 22159, 22171, 22189, 22193, 22229, 22247, 22259, 22271, 22273, 22277, 
        22279, 22283, 22291, 22303, 22307, 22343, 22349, 22367, 22369, 22381, 22391, 22397, 22409, 22433, 22441, 
        22447, 22453, 22469, 22481, 22483, 22501, 22511, 22531, 22541, 22543, 22549, 22567, 22571, 22573, 22613, 
        22619, 22621, 22637, 22639, 22643, 22651, 22669, 22679, 22691, 22697, 22699, 22709, 22717, 22721, 22727, 
        22739, 22741, 22751, 22769, 22777, 22783, 22787, 22807, 22811, 22817, 22853, 22859, 22861, 22871, 22877, 
        22901, 22907, 22921, 22937, 22943, 22961, 22963, 22973, 22993, 23003, 23011, 23017, 23021, 23027, 23029, 
        23039, 23041, 23053, 23057, 23059, 23063, 23071, 23081, 23087, 23099, 23117, 23131, 23143, 23159, 23167, 
        23173, 23189, 23197, 23201, 23203, 23209, 23227, 23251, 23269, 23279, 23291, 23293, 23297, 23311, 23321, 
        23327, 23333, 23339, 23357, 23369, 23371, 23399, 23417, 23431, 23447, 23459, 23473, 23497, 23509, 23531, 
        23537, 23539, 23549, 23557, 23561, 23563, 23567, 23581, 23593, 23599, 23603, 23609, 23623, 23627, 23629, 
        23633, 23663, 23669, 23671, 23677, 23687, 23689, 23719, 23741, 23743, 23747, 23753, 23761, 23767, 23773, 
        23789, 23801, 23813, 23819, 23827, 23831, 23833, 23857, 23869, 23873, 23879, 23887, 23893, 23899, 23909, 
        23911, 23917, 23929, 23957, 23971, 23977, 23981, 23993, 24001, 24007, 24019, 24023, 24029, 24043, 24049, 
        24061, 24071, 24077, 24083, 24091, 24097, 24103, 24107, 24109, 24113, 24121, 24133, 24137, 24151, 24169, 
        24179, 24181, 24197, 24203, 24223, 24229, 24239, 24247, 24251, 24281, 24317, 24329, 24337, 24359, 24371, 
        24373, 24379, 24391, 24407, 24413, 24419, 24421, 24439, 24443, 24469, 24473, 24481, 24499, 24509, 24517, 
        24527, 24533, 24547, 24551, 24571, 24593, 24611, 24623, 24631, 24659, 24671, 24677, 24683, 24691, 24697, 
        24709, 24733, 24749, 24763, 24767, 24781, 24793, 24799, 24809, 24821, 24841, 24847, 24851, 24859, 24877, 
        24889, 24907, 24917, 24919, 24923, 24943, 24953, 24967, 24971, 24977, 24979, 24989, 25013, 25031, 25033, 
        25037, 25057, 25073, 25087, 25097, 25111, 25117, 25121, 25127, 25147, 25153, 25163, 25169, 25171, 25183, 
        25189, 25219, 25229, 25237, 25243, 25247, 25253, 25261, 25301, 25303, 25307, 25309, 25321, 25339, 25343, 
        25349, 25357, 25367, 25373, 25391, 25409, 25411, 25423, 25439, 25447, 25453, 25457, 25463, 25469, 25471, 
        25523, 25537, 25541, 25561, 25577, 25579, 25583, 25589, 25601, 25603, 25609, 25621, 25633, 25639, 25643, 
        25657, 25667, 25673, 25679, 25693, 25703, 25717, 25733, 25741, 25747, 25759, 25763, 25771, 25793, 25799, 
        25801, 25819, 25841, 25847, 25849, 25867, 25873, 25889, 25903, 25913, 25919, 25931, 25933, 25939, 25943, 
        25951, 25969, 25981, 25997, 25999, 26003, 26017, 26021, 26029, 26041, 26053, 26083, 26099, 26107, 26111, 
        26113, 26119, 26141, 26153, 26161, 26171, 26177, 26183, 26189, 26203, 26209, 26227, 26237, 26249, 26251, 
        26261, 26263, 26267, 26293, 26297, 26309, 26317, 26321, 26339, 26347, 26357, 26371, 26387, 26393, 26399, 
        26407, 26417, 26423, 26431, 26437, 26449, 26459, 26479, 26489, 26497, 26501, 26513, 26539, 26557, 26561, 
        26573, 26591, 26597, 26627, 26633, 26641, 26647, 26669, 26681, 26683, 26687, 26693, 26699, 26701, 26711, 
        26713, 26717, 26723, 26729, 26731, 26737, 26759, 26777, 26783, 26801, 26813, 26821, 26833, 26839, 26849, 
        26861, 26863, 26879, 26881, 26891, 26893, 26903, 26921, 26927, 26947, 26951, 26953, 26959, 26981, 26987, 
        26993, 27011, 27017, 27031, 27043, 27059, 27061, 27067, 27073, 27077, 27091, 27103, 27107, 27109, 27127, 
        27143, 27179, 27191, 27197, 27211, 27239, 27241, 27253, 27259, 27271, 27277, 27281, 27283, 27299, 27329, 
        27337, 27361, 27367, 27397, 27407, 27409, 27427, 27431, 27437, 27449, 27457, 27479, 27481, 27487, 27509, 
        27527, 27529, 27539, 27541, 27551, 27581, 27583, 27611, 27617, 27631, 27647, 27653, 27673, 27689, 27691, 
        27697, 27701, 27733, 27737, 27739, 27743, 27749, 27751, 27763, 27767, 27773, 27779, 27791, 27793, 27799, 
        27803, 27809, 27817, 27823, 27827, 27847, 27851, 27883, 27893, 27901, 27917, 27919, 27941, 27943, 27947, 
        27953, 27961, 27967, 27983, 27997, 28001, 28019, 28027, 28031, 28051, 28057, 28069, 28081, 28087, 28097, 
        28099, 28109, 28111, 28123, 28151, 28163, 28181, 28183, 28201, 28211, 28219, 28229, 28277, 28279, 28283, 
        28289, 28297, 28307, 28309, 28319, 28349, 28351, 28387, 28393, 28403, 28409, 28411, 28429, 28433, 28439, 
        28447, 28463, 28477, 28493, 28499, 28513, 28517, 28537, 28541, 28547, 28549, 28559, 28571, 28573, 28579, 
        28591, 28597, 28603, 28607, 28619, 28621, 28627, 28631, 28643, 28649, 28657, 28661, 28663, 28669, 28687, 
        28697, 28703, 28711, 28723, 28729, 28751, 28753, 28759, 28771, 28789, 28793, 28807, 28813, 28817, 28837, 
        28843, 28859, 28867, 28871, 28879, 28901, 28909, 28921, 28927, 28933, 28949, 28961, 28979, 29009, 29017, 
        29021, 29023, 29027, 29033, 29059, 29063, 29077, 29101, 29123, 29129, 29131, 29137, 29147, 29153, 29167, 
        29173, 29179, 29191, 29201, 29207, 29209, 29221, 29231, 29243, 29251, 29269, 29287, 29297, 29303, 29311, 
        29327, 29333, 29339, 29347, 29363, 29383, 29387, 29389, 29399, 29401, 29411, 29423, 29429, 29437, 29443, 
        29453, 29473, 29483, 29501, 29527, 29531, 29537, 29567, 29569, 29573, 29581, 29587, 29599, 29611, 29629, 
        29633, 29641, 29663, 29669, 29671, 29683, 29717, 29723, 29741, 29753, 29759, 29761, 29789, 29803, 29819, 
        29833, 29837, 29851, 29863, 29867, 29873, 29879, 29881, 29917, 29921, 29927, 29947, 29959, 29983, 29989, 
        30011, 30013, 30029, 30047, 30059, 30071, 30089, 30091, 30097, 30103, 30109, 30113, 30119, 30133, 30137, 
        30139, 30161, 30169, 30181, 30187, 30197, 30203, 30211, 30223, 30241, 30253, 30259, 30269, 30271, 30293, 
        30307, 30313, 30319, 30323, 30341, 30347, 30367, 30389, 30391, 30403, 30427, 30431, 30449, 30467, 30469, 
        30491, 30493, 30497, 30509, 30517, 30529, 30539, 30553, 30557, 30559, 30577, 30593, 30631, 30637, 30643, 
        30649, 30661, 30671, 30677, 30689, 30697, 30703, 30707, 30713, 30727, 30757, 30763, 30773, 30781, 30803, 
        30809, 30817, 30829, 30839, 30841, 30851, 30853, 30859, 30869, 30871, 30881, 30893, 30911, 30931, 30937, 
        30941, 30949, 30971, 30977, 30983, 31013, 31019, 31033, 31039, 31051, 31063, 31069, 31079, 31081, 31091, 
        31121, 31123, 31139, 31147, 31151, 31153, 31159, 31177, 31181, 31183, 31189, 31193, 31219, 31223, 31231, 
        31237, 31247, 31249, 31253, 31259, 31267, 31271, 31277, 31307, 31319, 31321, 31327, 31333, 31337, 31357, 
        31379, 31387, 31391, 31393, 31397, 31469, 31477, 31481, 31489, 31511, 31513, 31517, 31531, 31541, 31543, 
        31547, 31567, 31573, 31583, 31601, 31607, 31627, 31643, 31649, 31657, 31663, 31667, 31687, 31699, 31721, 
        31723, 31727, 31729, 31741, 31751, 31769, 31771, 31793, 31799, 31817, 31847, 31849, 31859, 31873, 31883, 
        31891, 31907, 31957, 31963, 31973, 31981, 31991, 32003, 32009, 32027, 32029, 32051, 32057, 32059, 32063, 
        32069, 32077, 32083, 32089, 32099, 32117, 32119, 32141, 32143, 32159, 32173, 32183, 32189, 32191, 32203, 
        32213, 32233, 32237, 32251, 32257, 32261, 32297, 32299, 32303, 32309, 32321, 32323, 32327, 32341, 32353, 
        32359, 32363, 32369, 32371, 32377, 32381, 32401, 32411, 32413, 32423, 32429, 32441, 32443, 32467, 32479, 
        32491, 32497, 32503, 32507, 32531, 32533, 32537, 32561, 32563, 32569, 32573, 32579, 32587, 32603, 32609, 
        32611, 32621, 32633, 32647, 32653, 32687, 32693, 32707, 32713, 32717, 32719, 32749, 32771, 32779, 32783, 
        32789, 32797, 32801, 32803, 32831, 32833, 32839, 32843, 32869, 32887, 32909, 32911, 32917, 32933, 32939, 
        32941, 32957, 32969, 32971, 32983, 32987, 32993, 32999, 33013, 33023, 33029, 33037, 33049, 33053, 33071, 
        33073, 33083, 33091, 33107, 33113, 33119, 33149, 33151, 33161, 33179, 33181, 33191, 33199, 33203, 33211, 
        33223, 33247, 33287, 33289, 33301, 33311, 33317, 33329, 33331, 33343, 33347, 33349, 33353, 33359, 33377, 
        33391, 33403, 33409, 33413, 33427, 33457, 33461, 33469, 33479, 33487, 33493, 33503, 33521, 33529, 33533, 
        33547, 33563, 33569, 33577, 33581, 33587, 33589, 33599, 33601, 33613, 33617, 33619, 33623, 33629, 33637, 
        33641, 33647, 33679, 33703, 33713, 33721, 33739, 33749, 33751, 33757, 33767, 33769, 33773, 33791, 33797, 
        33809, 33811, 33827, 33829, 33851, 33857, 33863, 33871, 33889, 33893, 33911, 33923, 33931, 33937, 33941, 
        33961, 33967, 33997, 34019, 34031, 34033, 34039, 34057, 34061, 34123, 34127, 34129, 34141, 34147, 34157, 
        34159, 34171, 34183, 34211, 34213, 34217, 34231, 34253, 34259, 34261, 34267, 34273, 34283, 34297, 34301, 
        34303, 34313, 34319, 34327, 34337, 34351, 34361, 34367, 34369, 34381, 34403, 34421, 34429, 34439, 34457, 
        34469, 34471, 34483, 34487, 34499, 34501, 34511, 34513, 34519, 34537, 34543, 34549, 34583, 34589, 34591, 
        34603, 34607, 34613, 34631, 34649, 34651, 34667, 34673, 34679, 34687, 34693, 34703, 34721, 34729, 34739, 
        34747, 34757, 34759, 34763, 34781, 34807, 34819, 34841, 34843, 34847, 34849, 34871, 34877, 34883, 34897, 
        34913, 34919, 34939, 34949, 34961, 34963, 34981, 35023, 35027, 35051, 35053, 35059, 35069, 35081, 35083, 
        35089, 35099, 35107, 35111, 35117, 35129, 35141, 35149, 35153, 35159, 35171, 35201, 35221, 35227, 35251, 
        35257, 35267, 35279, 35281, 35291, 35311, 35317, 35323, 35327, 35339, 35353, 35363, 35381, 35393, 35401, 
        35407, 35419, 35423, 35437, 35447, 35449, 35461, 35491, 35507, 35509, 35521, 35527, 35531, 35533, 35537, 
        35543, 35569, 35573, 35591, 35593, 35597, 35603, 35617, 35671, 35677, 35729, 35731, 35747, 35753, 35759, 
        35771, 35797, 35801, 35803, 35809, 35831, 35837, 35839, 35851, 35863, 35869, 35879, 35897, 35899, 35911, 
        35923, 35933, 35951, 35963, 35969, 35977, 35983, 35993, 35999, 36007, 36011, 36013, 36017, 36037, 36061, 
        36067, 36073, 36083, 36097, 36107, 36109, 36131, 36137, 36151, 36161, 36187, 36191, 36209, 36217, 36229, 
        36241, 36251, 36263, 36269, 36277, 36293, 36299, 36307, 36313, 36319, 36341, 36343, 36353, 36373, 36383, 
        36389, 36433, 36451, 36457, 36467, 36469, 36473, 36479, 36493, 36497, 36523, 36527, 36529, 36541, 36551, 
        36559, 36563, 36571, 36583, 36587, 36599, 36607, 36629, 36637, 36643, 36653, 36671, 36677, 36683, 36691, 
        36697, 36709, 36713, 36721, 36739, 36749, 36761, 36767, 36779, 36781, 36787, 36791, 36793, 36809, 36821, 
        36833, 36847, 36857, 36871, 36877, 36887, 36899, 36901, 36913, 36919, 36923, 36929, 36931, 36943, 36947, 
        36973, 36979, 36997, 37003, 37013, 37019, 37021, 37039, 37049, 37057, 37061, 37087, 37097, 37117, 37123, 
        37139, 37159, 37171, 37181, 37189, 37199, 37201, 37217, 37223, 37243, 37253, 37273, 37277, 37307, 37309, 
        37313, 37321, 37337, 37339, 37357, 37361, 37363, 37369, 37379, 37397, 37409, 37423, 37441, 37447, 37463, 
        37483, 37489, 37493, 37501, 37507, 37511, 37517, 37529, 37537, 37547, 37549, 37561, 37567, 37571, 37573, 
        37579, 37589, 37591, 37607, 37619, 37633, 37643, 37649, 37657, 37663, 37691, 37693, 37699, 37717, 37747, 
        37781, 37783, 37799, 37811, 37813, 37831, 37847, 37853, 37861, 37871, 37879, 37889, 37897, 37907, 37951, 
        37957, 37963, 37967, 37987, 37991, 37993, 37997, 38011, 38039, 38047, 38053, 38069, 38083, 38113, 38119, 
        38149, 38153, 38167, 38177, 38183, 38189, 38197, 38201, 38219, 38231, 38237, 38239, 38261, 38273, 38281, 
        38287, 38299, 38303, 38317, 38321, 38327, 38329, 38333, 38351, 38371, 38377, 38393, 38431, 38447, 38449, 
        38453, 38459, 38461, 38501, 38543, 38557, 38561, 38567, 38569, 38593, 38603, 38609, 38611, 38629, 38639, 
        38651, 38653, 38669, 38671, 38677, 38693, 38699, 38707, 38711, 38713, 38723, 38729, 38737, 38747, 38749, 
        38767, 38783, 38791, 38803, 38821, 38833, 38839, 38851, 38861, 38867, 38873, 38891, 38903, 38917, 38921, 
        38923, 38933, 38953, 38959, 38971, 38977, 38993, 39019, 39023, 39041, 39043, 39047, 39079, 39089, 39097, 
        39103, 39107, 39113, 39119, 39133, 39139, 39157, 39161, 39163, 39181, 39191, 39199, 39209, 39217, 39227, 
        39229, 39233, 39239, 39241, 39251, 39293, 39301, 39313, 39317, 39323, 39341, 39343, 39359, 39367, 39371, 
        39373, 39383, 39397, 39409, 39419, 39439, 39443, 39451, 39461, 39499, 39503, 39509, 39511, 39521, 39541, 
        39551, 39563, 39569, 39581, 39607, 39619, 39623, 39631, 39659, 39667, 39671, 39679, 39703, 39709, 39719, 
        39727, 39733, 39749, 39761, 39769, 39779, 39791, 39799, 39821, 39827, 39829, 39839, 39841, 39847, 39857, 
        39863, 39869, 39877, 39883, 39887, 39901, 39929, 39937, 39953, 39971, 39979, 39983, 39989, 40009, 40013, 
        40031, 40037, 40039, 40063, 40087, 40093, 40099, 40111, 40123, 40127, 40129, 40151, 40153, 40163, 40169, 
        40177, 40189, 40193, 40213, 40231, 40237, 40241, 40253, 40277, 40283, 40289, 40343, 40351, 40357, 40361, 
        40387, 40423, 40427, 40429, 40433, 40459, 40471, 40483, 40487, 40493, 40499, 40507, 40519, 40529, 40531, 
        40543, 40559, 40577, 40583, 40591, 40597, 40609, 40627, 40637, 40639, 40693, 40697, 40699, 40709, 40739, 
        40751, 40759, 40763, 40771, 40787, 40801, 40813, 40819, 40823, 40829, 40841, 40847, 40849, 40853, 40867, 
        40879, 40883, 40897, 40903, 40927, 40933, 40939, 40949, 40961, 40973, 40993, 41011, 41017, 41023, 41039, 
        41047, 41051, 41057, 41077, 41081, 41113, 41117, 41131, 41141, 41143, 41149, 41161, 41177, 41179, 41183, 
        41189, 41201, 41203, 41213, 41221, 41227, 41231, 41233, 41243, 41257, 41263, 41269, 41281, 41299, 41333, 
        41341, 41351, 41357, 41381, 41387, 41389, 41399, 41411, 41413, 41443, 41453, 41467, 41479, 41491, 41507, 
        41513, 41519, 41521, 41539, 41543, 41549, 41579, 41593, 41597, 41603, 41609, 41611, 41617, 41621, 41627, 
        41641, 41647, 41651, 41659, 41669, 41681, 41687, 41719, 41729, 41737, 41759, 41761, 41771, 41777, 41801, 
        41809, 41813, 41843, 41849, 41851, 41863, 41879, 41887, 41893, 41897, 41903, 41911, 41927, 41941, 41947, 
        41953, 41957, 41959, 41969, 41981, 41983, 41999, 42013, 42017, 42019, 42023, 42043, 42061, 42071, 42073, 
        42083, 42089, 42101, 42131, 42139, 42157, 42169, 42179, 42181, 42187, 42193, 42197, 42209, 42221, 42223, 
        42227, 42239, 42257, 42281, 42283, 42293, 42299, 42307, 42323, 42331, 42337, 42349, 42359, 42373, 42379, 
        42391, 42397, 42403, 42407, 42409, 42433, 42437, 42443, 42451, 42457, 42461, 42463, 42467, 42473, 42487, 
        42491, 42499, 42509, 42533, 42557, 42569, 42571, 42577, 42589, 42611, 42641, 42643, 42649, 42667, 42677, 
        42683, 42689, 42697, 42701, 42703, 42709, 42719, 42727, 42737, 42743, 42751, 42767, 42773, 42787, 42793, 
        42797, 42821, 42829, 42839, 42841, 42853, 42859, 42863, 42899, 42901, 42923, 42929, 42937, 42943, 42953, 
        42961, 42967, 42979, 42989, 43003, 43013, 43019, 43037, 43049, 43051, 43063, 43067, 43093, 43103, 43117, 
        43133, 43151, 43159, 43177, 43189, 43201, 43207, 43223, 43237, 43261, 43271, 43283, 43291, 43313, 43319, 
        43321, 43331, 43391, 43397, 43399, 43403, 43411, 43427, 43441, 43451, 43457, 43481, 43487, 43499, 43517, 
        43541, 43543, 43573, 43577, 43579, 43591, 43597, 43607, 43609, 43613, 43627, 43633, 43649, 43651, 43661, 
        43669, 43691, 43711, 43717, 43721, 43753, 43759, 43777, 43781, 43783, 43787, 43789, 43793, 43801, 43853, 
        43867, 43889, 43891, 43913, 43933, 43943, 43951, 43961, 43963, 43969, 43973, 43987, 43991, 43997, 44017, 
        44021, 44027, 44029, 44041, 44053, 44059, 44071, 44087, 44089, 44101, 44111, 44119, 44123, 44129, 44131, 
        44159, 44171, 44179, 44189, 44201, 44203, 44207, 44221, 44249, 44257, 44263, 44267, 44269, 44273, 44279, 
        44281, 44293, 44351, 44357, 44371, 44381, 44383, 44389, 44417, 44449, 44453, 44483, 44491, 44497, 44501, 
        44507, 44519, 44531, 44533, 44537, 44543, 44549, 44563, 44579, 44587, 44617, 44621, 44623, 44633, 44641, 
        44647, 44651, 44657, 44683, 44687, 44699, 44701, 44711, 44729, 44741, 44753, 44771, 44773, 44777, 44789, 
        44797, 44809, 44819, 44839, 44843, 44851, 44867, 44879, 44887, 44893, 44909, 44917, 44927, 44939, 44953, 
        44959, 44963, 44971, 44983, 44987, 45007, 45013, 45053, 45061, 45077, 45083, 45119, 45121, 45127, 45131, 
        45137, 45139, 45161, 45179, 45181, 45191, 45197, 45233, 45247, 45259, 45263, 45281, 45289, 45293, 45307, 
        45317, 45319, 45329, 45337, 45341, 45343, 45361, 45377, 45389, 45403, 45413, 45427, 45433, 45439, 45481, 
        45491, 45497, 45503, 45523, 45533, 45541, 45553, 45557, 45569, 45587, 45589, 45599, 45613, 45631, 45641, 
        45659, 45667, 45673, 45677, 45691, 45697, 45707, 45737, 45751, 45757, 45763, 45767, 45779, 45817, 45821, 
        45823, 45827, 45833, 45841, 45853, 45863, 45869, 45887, 45893, 45943, 45949, 45953, 45959, 45971, 45979, 
        45989, 46021, 46027, 46049, 46051, 46061, 46073, 46091, 46093, 46099, 46103, 46133, 46141, 46147, 46153, 
        46171, 46181, 46183, 46187, 46199, 46219, 46229, 46237, 46261, 46271, 46273, 46279, 46301, 46307, 46309, 
        46327, 46337
    };
    return primes;
}

void initpargs_add(t_initpargs *x, t_symbol *msg, long ac, t_atom *av)
{
    t_object *obj = (t_object *) atom_getobj(av);
    hashtab_store(x->n_objs_to_process, (t_symbol *) obj, obj);
    //    llll_appendobj(x->n_objs_to_process, obj, 0, WHITENULL_llll);
}

void initpargs_remove(t_initpargs *x, t_symbol *msg, long ac, t_atom *av)
{
    t_object *obj = (t_object *) atom_getobj(av);
    hashtab_delete(x->n_objs_to_process, (t_symbol *) obj);
    //    llll_appendobj(x->n_objs_to_process, obj, 0, WHITENULL_llll);
}

t_max_err initpargs_run(t_initpargs *x, t_symbol *msg, long ac, t_atom *av)
{
    //t_llllelem *elem;
    /*
     for (elem = x->n_objs_to_process->l_head; elem; elem = elem->l_next) {
     t_object *obj = (t_object *) hatom_getobj(&elem->l_hatom);
     object_method_typed(obj, gensym("dopargs"), 0, NULL, NULL);
     }
     */
    hashtab_methodall(x->n_objs_to_process, gensym("dopargs"));
    hashtab_clear(x->n_objs_to_process);
    return MAX_ERR_NONE;
}
/*
 long initpargs_cmp(void *data, t_llllelem *a, t_llllelem *b)
 {
 t_objpos *a_op = (t_objpos *) hatom_getobj(&a->l_hatom);
 t_objpos *b_op = (t_objpos *) hatom_getobj(&b->l_hatom);
 t_symbol *a_obj_classname = object_classname(a_op->o_obj);
 t_symbol *b_obj_classname = object_classname(b_op->o_obj);
 
 if (a_obj_classname != b_obj_classname)
 return a_obj_classname == gensym("bach.portal");
 else
 return (!a_op->o_calcdepth) || (a_op->o_depth >= b_op->o_depth);
 }
 */

void initpargs_free(t_initpargs *x)
{
    ;
}

t_initpargs *initpargs_new(t_symbol *s, short ac, t_atom *av)
{
    t_initpargs *x = NULL;
    t_max_err err = 0;
    
    if ((x = (t_initpargs *) object_alloc(initpargs_class))) {
        x->n_objs_to_process = hashtab_new(0);
        hashtab_flags(x->n_objs_to_process, OBJ_FLAG_REF);
        object_method(x->n_objs_to_process, gensym("readonly"), 1);
    } else 
        error("couldn't instantiate initpargs");
    
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

char bach_load_default_font(void)
{
    std::string fontsPath = bach_get_package_path() + "/fonts/November for bach.otf";
    
#ifdef WIN_VERSION
    AddFontResourceExA(fontsPath.c_str(), FR_PRIVATE, 0);
#endif
    
#ifdef WIN_VERSION_old
    HINSTANCE hResInstance = hinst;
    
    HRSRC res = FindResource(hResInstance, "#1685", RT_RCDATA);
    if (res)
    {
        HGLOBAL mem = LoadResource(hResInstance, res);
        void *data = LockResource(mem);
        size_t len = SizeofResource(hResInstance, res);
        
        DWORD nFonts;
        HANDLE bachFont = AddFontMemResourceEx(
                                               data,           // font resource
                                               len,           // number of bytes in font resource
                                               NULL,              // Reserved. Must be 0.
                                               &nFonts          // number of fonts installed
                                               );
        
        if(bachFont == 0)
        {
            error("can't load font!");
        }
    }
#endif
    
#ifdef gggMAC_VERSION
    // MAC
    CFErrorRef error = NULL;
    CFBundleRef mainBundle = CFBundleGetBundleWithIdentifier(CFSTR("com.bachproject.bach"));
    //CFURLRef fontURL = mainBundle ? CFBundleCopyResourceURL(mainBundle, CFSTR("johannsebastian"), CFSTR("dat"), NULL) : NULL;
    
    CFStringRef path = CFStringCreateWithCString(NULL, fontsPath.c_str(), kCFStringEncodingMacRoman);
    CFURLRef fontURL = CFURLCreateWithFileSystemPath(NULL, path, kCFURLPOSIXPathStyle, false);
    
    if (!mainBundle || !fontURL) {
        error("Failed to load default bach font.");
    } else if (!CTFontManagerRegisterFontsForURL(fontURL, kCTFontManagerScopeProcess, &error)) {
        
        // WE DON'T THROW AN ERROR HERE, since it could be that the font is already installed.
        
    }
    
    if (fontURL)
        CFRelease(fontURL);
    
#endif
    return 0;
    
}

long bach_getbuildnumber(void)
{
#ifdef gggMAC_VERSION
    CFBundleRef mainBundle = CFBundleGetBundleWithIdentifier(CFSTR("com.bachproject.bach"));
    if (mainBundle) {
        
//        UInt32 bundleVersion = CFBundleGetVersionNumber(mainBundle); /// this one won't work
        SInt32 bundleVersion = CFStringGetIntValue((CFStringRef)CFBundleGetValueForInfoDictionaryKey(mainBundle, kCFBundleVersionKey));
        return bundleVersion;
    } else
        return 0;
#else
    return 0;
#endif
}

void bach_init_bifs(t_bach *x)
{
    cpost("bach : initializing bell built-in functions");

    if (x->b_bifTable)
        return;
    auto bifTable = x->b_bifTable = new std::unordered_map<std::string, t_function *>;
    x->b_gvt = new t_globalVariableTable;
    
    (*bifTable)["$args"] = new t_fnArgs;
    (*bifTable)["$argcount"] = new t_fnArgcount;
    
    (*bifTable)["length"] = new t_fnLength;
    (*bifTable)["depth"] = new t_fnDepth;
    (*bifTable)["is"] = new t_fnIs;
    (*bifTable)["nth"] = new t_fnNth;
    (*bifTable)["sort"] = new t_fnSort;
    (*bifTable)["contains"] = new t_fnContains;
    (*bifTable)["rev"] = new t_fnRev;
    (*bifTable)["rot"] = new t_fnRot;
    (*bifTable)["trans"] = new t_fnTrans;
    (*bifTable)["flat"] = new t_fnFlat;
    (*bifTable)["slice"] = new t_fnSlice;
    (*bifTable)["left"] = new t_fnLeft;
    (*bifTable)["right"] = new t_fnRight;
    (*bifTable)["subs"] = new t_fnSubs;
    //(*bifTable)["keysubs"] = new t_fnKeysubs;
    (*bifTable)["insert"] = new t_fnInsert;
    (*bifTable)["find"] = new t_fnFind;
    (*bifTable)["finditems"] = new t_fnFinditems;
    (*bifTable)["findaddrs"] = new t_fnFindaddrs;
    (*bifTable)["scramble"] = new t_fnScramble;
    (*bifTable)["minmax"] = new t_fnMinmax;
    (*bifTable)["perm"] = new t_fnPerm;
    (*bifTable)["comb"] = new t_fnComb;
    (*bifTable)["cartesianprod"] = new t_fnCartesianprod;
    (*bifTable)["wrap"] = new t_fnWrap;
    (*bifTable)["delace"] = new t_fnDelace;
    (*bifTable)["group"] = new t_fnGroup;
    (*bifTable)["thin"] = new t_fnThin;
    (*bifTable)["classify"] = new t_fnClassify;
    (*bifTable)["union"] = new t_fnUnion;
    (*bifTable)["intersection"] = new t_fnIntersection;
    (*bifTable)["symdiff"] = new t_fnSymdiff;
    (*bifTable)["diff"] = new t_fnDiff;
    (*bifTable)["primeser"] = new t_fnPrimeser;
    (*bifTable)["arithmser"] = new t_fnArithmser;
    (*bifTable)["geomser"] = new t_fnGeomser;
    (*bifTable)["map"] = new t_fnMap;
    (*bifTable)["reduce"] = new t_fnReduce;
    (*bifTable)["apply"] = new t_fnApply;
    (*bifTable)["sum"] = new t_fnSum;
    (*bifTable)["prod"] = new t_fnProd;

    (*bifTable)["minimum"] = new t_fnMinimum;
    (*bifTable)["maximum"] = new t_fnMaximum;
    (*bifTable)["mc2f"] = new t_fnMc2f;
    (*bifTable)["f2mc"] = new t_fnF2mc;
    
    (*bifTable)["outlet"] = new t_fnOutlet;
    (*bifTable)["inlet"] = new t_fnInlet;

    
    (*bifTable)["cos"] = new t_mathUnaryFunctionDD<cos>("cos");
    (*bifTable)["sin"] = new t_mathUnaryFunctionDD<sin>("sin");
    (*bifTable)["tan"] = new t_mathUnaryFunctionDD<tan>("tan");
    (*bifTable)["exp"] = new t_mathUnaryFunctionDD<exp>("exp");
    (*bifTable)["log"] = new t_mathUnaryFunctionDD<log>("log");
    (*bifTable)["acos"] = new t_mathUnaryFunctionDD<acos>("acos");
    (*bifTable)["asin"] = new t_mathUnaryFunctionDD<asin>("asin");
    (*bifTable)["atan"] = new t_mathUnaryFunctionDD<atan>("atan");
    (*bifTable)["cosh"] = new t_mathUnaryFunctionDD<cosh>("cosh");
    (*bifTable)["sinh"] = new t_mathUnaryFunctionDD<sinh>("sinh");
    (*bifTable)["tanh"] = new t_mathUnaryFunctionDD<tanh>("tanh");
    (*bifTable)["exp2"] = new t_mathUnaryFunctionDD<exp2>("exp2");
    (*bifTable)["log2"] = new t_mathUnaryFunctionDD<log2>("log2");
    (*bifTable)["sqrt"] = new t_mathUnaryFunctionDD<sqrt>("sqrt");
    (*bifTable)["ceil"] = new t_mathUnaryFunctionDD<ceil>("ceil");
    (*bifTable)["acosh"] = new t_mathUnaryFunctionDD<acosh>("acosh");
    (*bifTable)["asinh"] = new t_mathUnaryFunctionDD<asinh>("asinh");
    (*bifTable)["atanh"] = new t_mathUnaryFunctionDD<atanh>("atanh");
    (*bifTable)["log10"] = new t_mathUnaryFunctionDD<log10>("log10");
    (*bifTable)["floor"] = new t_mathUnaryFunctionDD<floor>("floor");
    (*bifTable)["round"] = new t_mathUnaryFunctionDD<round>("round");
    (*bifTable)["trunc"] = new t_mathUnaryFunctionDD<trunc>("trunc");
    
    (*bifTable)["fmod"] = new t_mathBinaryFunctionDDD<fmod>("fmod");
    (*bifTable)["atan2"] = new t_mathBinaryFunctionDDD<atan2>("atan2");
    (*bifTable)["hypot"] = new t_mathBinaryFunctionDDD<hypot>("hypot");
    
    (*bifTable)["int"] = new t_mathUnaryFunctionAA<hatom_fn_int>("int");
    (*bifTable)["rat"] = new t_mathUnaryFunctionAA<hatom_fn_rat>("rat");
    (*bifTable)["num"] = new t_mathUnaryFunctionAA<hatom_fn_num>("num");
    (*bifTable)["den"] = new t_mathUnaryFunctionAA<hatom_fn_den>("den");
    (*bifTable)["abs"] = new t_mathUnaryFunctionAA<hatom_fn_abs>("abs");
    (*bifTable)["sgn"] = new t_mathUnaryFunctionAA<hatom_fn_sgn>("sgn");
    (*bifTable)["float"] = new t_mathUnaryFunctionAA<hatom_fn_float>("float");
    (*bifTable)["pitch"] = new t_mathUnaryFunctionAA<hatom_fn_pitch>("pitch");
    (*bifTable)["degree"] = new t_mathUnaryFunctionAA<hatom_fn_degree>("degree");
    (*bifTable)["octave"] = new t_mathUnaryFunctionAA<hatom_fn_octave>("octave");
    (*bifTable)["alter"] = new t_mathUnaryFunctionAA<hatom_fn_alter>("alter");
    (*bifTable)["cents"] = new t_mathUnaryFunctionAA<hatom_fn_cents>("cents");
    
    (*bifTable)["pow"] = new t_mathBinaryFunctionAAA<hatom_op_pow>("pow", "base", "exponent");
    (*bifTable)["mod"] = new t_mathBinaryFunctionAAA<hatom_fn_mod>("mod", "x", "y");
    (*bifTable)["min"] = new t_mathBinaryFunctionAAA<hatom_fn_min>("min", "x", "y");
    (*bifTable)["max"] = new t_mathBinaryFunctionAAA<hatom_fn_max>("max", "x", "y");
    (*bifTable)["random"] = new t_mathBinaryFunctionAAA<hatom_fn_random>("random", "x", "y");
    (*bifTable)["bessel"] = new t_mathBinaryFunctionAAA<hatom_fn_jn>("bessel", "x", "order");
    (*bifTable)["approx"] = new t_mathBinaryFunctionAAA<hatom_fn_approx>("approx", "pitch", "tonedivision");
    (*bifTable)["enharm"] = new t_mathBinaryFunctionAAA<hatom_fn_enharm>("enharm", "x", "y");
    (*bifTable)["makepitchsc"] = new t_mathBinaryFunctionAAA<hatom_fn_makepitchsc>("makepitchsc", "steps", "cents");

    (*bifTable)["makepitch"] = new t_mathTernaryFunctionAAAA<hatom_fn_makepitch>("makepitch", "degree", "alter", "octave");
    
    (*bifTable)["#u-"] = new t_mathUnaryFunctionAA<hatom_op_uminus>("#u-");
    (*bifTable)["#!"] = new t_mathUnaryFunctionAA<hatom_op_lognot>("#!");
    (*bifTable)["#~"] = new t_mathUnaryFunctionAA<hatom_op_bitnot>("#~");
    
    (*bifTable)["#+"] = new t_mathBinaryFunctionAAA<hatom_op_plus_with_symbols>("#+");
    (*bifTable)["#-"] = new t_mathBinaryFunctionAAA<hatom_op_minus>("#-");
    (*bifTable)["#*"] = new t_mathBinaryFunctionAAA<hatom_op_times_with_symbols>("#*");
    (*bifTable)["#/"] = new t_mathBinaryFunctionAAA<hatom_op_div>("#/");
    (*bifTable)["#//"] = new t_mathBinaryFunctionAAA<hatom_op_divdiv>("#//");
    (*bifTable)["#%"] = new t_mathBinaryFunctionAAA<hatom_fn_remainder>("#%");
    (*bifTable)["#=="] = new t_mathBinaryFunctionAAA<hatom_op_eq>("#==");
    (*bifTable)["#!="] = new t_mathBinaryFunctionAAA<hatom_op_neq>("#!=");
    (*bifTable)["#<"] = new t_mathBinaryFunctionAAA<hatom_op_lt>("#<");
    (*bifTable)["#>"] = new t_mathBinaryFunctionAAA<hatom_op_gt>("#>");
    (*bifTable)["#<="] = new t_mathBinaryFunctionAAA<hatom_op_le>("#<=");
    (*bifTable)["#>="] = new t_mathBinaryFunctionAAA<hatom_op_ge>("#>=");
    (*bifTable)["#&"] = new t_mathBinaryFunctionAAA<hatom_op_bitand>("#&");
    (*bifTable)["#^"] = new t_mathBinaryFunctionAAA<hatom_op_bitxor>("#^");
    (*bifTable)["#|"] = new t_mathBinaryFunctionAAA<hatom_op_bitor>("#|");
    (*bifTable)["#&&"] = new t_mathBinaryFunctionAAA<hatom_op_logand>("#&&");
    (*bifTable)["#^^"] = new t_mathBinaryFunctionAAA<hatom_op_logxor>("#^^");
    (*bifTable)["#||"] = new t_mathBinaryFunctionAAA<hatom_op_logor>("#||");
    //(*bifTable)["#&&&"] = new t_mathBinaryFunctionAAA<hatom_op_logand>("#&&&"); // TODO
    (*bifTable)["#|||"] = new t_mathBinaryFunctionAAA<hatom_op_logor>("#|||"); // TODO
    (*bifTable)["#<<"] = new t_mathBinaryFunctionAAA<hatom_op_lshift>("#<<");
    (*bifTable)["#>>"] = new t_mathBinaryFunctionAAA<hatom_op_rshift>("#>>");
    
    x->b_thePvManager = new pvManager();
}

t_uint32 murmur3(const t_uint32 key)
{
    uint32_t h = 0x16851750;
    uint32_t k = key;
    k *= 0xcc9e2d51;
    k = (k << 15) | (k >> 17);
    k *= 0x1b873593;
    h ^= k;
    h ^= 1;
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

void bach_unlock(t_bach *x, t_atom_long l)
{
    t_datetime dt;
    systime_datetime(&dt);
    t_uint32 year = dt.year;
    unsigned long h = murmur3(year);
    
    if (l != h) {
        if (dt.month == 1) {
            --year;
            h = murmur3(year);
        }
        if (l != h)
            object_error((t_object *) x, "Bad splashscreen removal code");
        return;
    }
    
    post("bach splashscreen removed until January 31, %lu", year + 1);
    bach->b_no_ss = true;
    
    static const std::string dq = "\"";

    std::string folder = bach_get_cache_path();
    
#ifdef MAC_VERSION
    std::string name = folder + "/bachutil.mxo";
#endif

#ifdef WIN_VERSION
    static const std::string bs = "\\";
    std::string name = folder + bs + "bachutil.mxe64";
#endif

    std::string echo = "echo " + std::to_string(l) + " > " + dq + name + dq;
    system(echo.c_str());
}

t_bool bach_checkauth()
{
    static const std::string dq = "\"";
    std::string folder = bach_get_cache_path();

#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOG
    return true;
#endif

#ifdef MAC_VERSION
    std::string name = folder + "/bachutil.mxo";
#endif
#ifdef WIN_VERSION
    std::string name = folder + "\\bachutil.mxe64";
#endif

    t_fourcc filetype = 0, outtype;
    char filename[MAX_PATH_CHARS];
    short path;
    strncpy_zero(filename, name.c_str(), MAX_PATH_CHARS);
    if (locatefile_extended(filename, &path, &outtype, &filetype, 0))
        return false;
    char *buffer;
    t_filehandle fh;
    t_ptr_size size;
    if (path_opensysfile(filename, path, &fh, READ_PERM))
        return false;
    sysfile_geteof(fh, &size);
    buffer = sysmem_newptrclear(size);
    // read in the file
    sysfile_read(fh, &size, buffer);
    sysfile_close(fh);
    // do something with data in buffer here
    unsigned long code = strtoul(buffer, NULL, 10);
    sysmem_freeptr(buffer);     // must free allocated memory
    t_datetime dt;
    systime_datetime(&dt);
    unsigned long h = murmur3(dt.year);
    if (code == h)
        return true;
    if (dt.month != 1)
        return false;
    h = murmur3(dt.year - 1);
    if (code == h)
        return true;
    return false;
}


void bach_installatompackage(t_bach *x)
{
    const static std::string dq = "\"";
    std::string home = bach_get_user_folder_path();
#ifdef MAC_VERSION
    std::string atomFolder = home + "/.atom/packages";
    char filename[MAX_PATH_CHARS];
    strncpy_zero(filename, atomFolder.c_str(), MAX_PATH_CHARS);
    short path = 0;
    t_fourcc outtype = 0;
    long err = locatefile_extended(filename, &path, &outtype, nullptr, 0);
    if (err || outtype != 'fold') {
        object_error((t_object *) x, "Can't find atom");
        return;
    }
    std::string atomPackageFolder = bach_get_package_path() + "/language-bell";
    std::string rmcmd = "rm -f " + dq + atomFolder + "/language-bell" + dq;
    std::string cmd = "ln -s " + dq + atomPackageFolder + dq + " " + dq + atomFolder + dq;
#endif
#ifdef WIN_VERSION
    std::string atomFolder = home + "\\.atom\\packages";
    char filename[MAX_PATH_CHARS];
    strncpy_zero(filename, atomFolder.c_str(), MAX_PATH_CHARS);
    short path = 0;
    t_fourcc outtype = 0;
    long err = locatefile_extended(filename, &path, &outtype, nullptr, 0);
    if (err || outtype != 'fold') {
        object_error((t_object *) x, "Can't find atom");
        return;
    }
    std::string link = atomFolder + "\\language-bell";
    std::string atomPackageFolder = bach_get_package_path() + "\\language-bell";
    std::string rmcmd = "del /f " + dq + link + dq;
    std::string cmd = "mklink /J " + dq + link + dq + " " + dq + atomPackageFolder + dq;
#endif
    system(rmcmd.c_str());
    system(cmd.c_str());
}

void bach_clearatomcachefolder(t_bach *x)
{
    short r = wind_advise_explain(nullptr, const_cast<char *>("Are you sure that you want to clear the atom editor cache?"),
                                  const_cast<char *>("You will lose any unsaved changes"),
                                  const_cast<char *>("Cancel"),
                                  const_cast<char *>("Clear the cache"),
                                  nullptr);
    if (r == 1)
        return;
    const static std::string dq = "\"";
    std::string cache = bach_get_cache_path();
#ifdef WIN_VERSION
    std::string cmd = "del /f " + dq + cache + dq + "\\scratchpad*.bell";
#endif
#ifdef MAC_VERSION
    std::string cmd = "rm -f " + dq + cache + dq + "/scratchpad*.bell";
#endif
    system(cmd.c_str());
}
