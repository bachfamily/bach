/*
 *  bach_mem.c
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

#include "foundation/llllobj.h"
#include "foundation/bach_threads.h"
#include "ext_strings.h"
#include "ext_charset.h"
#include "ext_atomic.h"
#include "parsers/symparser/symparser.h"
#include "parsers/strparser/strparser.h"
#include "bell/function.hpp"
#ifdef MAC_VERSION
#include <execinfo.h>
#endif

#ifdef C74_X64
#define BACH_MAGIC_BLOAT "\xad\xde\xad\xde\xad\xde\xad\xde"
#define BACH_BLOATED_ADDR ((void *) 0xdeaddeaddeaddead)
#else
#define BACH_MAGIC_BLOAT "\xad\xde\xad\xde"
#define BACH_BLOATED_ADDR ((void *) 0xdeaddead)
#endif

#define BACH_BLOAT_STEP (sizeof(void *))

t_max_err tinyll_insert_sorted(t_tinyll *tll, void *thing, t_atom_ulong key);
void tinyll_chuck_key(t_tinyll *tll, t_atom_ulong key);
t_tinyllelem *tinyllelem_new(void);

extern t_hashtab *memmap;
extern t_hashtab *poolmap;
extern t_systhread_mutex memmap_lock;

extern t_llll **llll_book;
extern t_uint32 **llll_phonebook;
extern t_uint32 *llll_current_phonebook_idx;
extern t_uint32 *llll_pool_size;
extern t_bach_atomic_lock *llll_pool_lock;
extern t_llll *llll_model;

extern t_llllelem_numbered **llllelem_book;
extern t_uint32 **llllelem_phonebook;
extern t_uint32 *llllelem_current_phonebook_idx;
extern t_uint32 *llllelem_pool_size;
extern t_bach_atomic_lock *llllelem_pool_lock;
extern t_llllelem_numbered *llllelem_model;

static t_bool loadtime = 0;

void loadtime_clear();

t_llll *llll_get(void)
{
    //bach_breakpoint(0);
    t_llll *x;
    t_uint32 phonenumber_pos, phonenumber;
    t_uint32 phonenumber_page, phonenumber_row;
    t_uint32 llll_page, llll_row;
    bach_atomic_lock(llll_pool_lock);
    if (*llll_current_phonebook_idx == *llll_pool_size) {
        long i;
        size_t oldsize = *llll_pool_size;
        *llll_pool_size += BACH_LLLL_PAGE_SIZE;
        t_uint32 newpage_idx = oldsize / BACH_LLLL_PAGE_SIZE;
        t_llll *llll_newpage = llll_book[newpage_idx] = (t_llll *) sysmem_newptr(BACH_LLLL_PAGE_SIZE * sizeof(t_llll));
        t_uint32 *phonebook_newpage = llll_phonebook[newpage_idx] = (t_uint32 *) sysmem_newptr(BACH_LLLL_PAGE_SIZE * sizeof(t_uint32));
        bach_fill_2n_array(llll_model, llll_newpage, sizeof(t_llll), BACH_LLLL_PAGE_SIZE);
        for (i = 0, phonenumber = oldsize; i < BACH_LLLL_PAGE_SIZE; i++, phonenumber++) {
            phonebook_newpage[i] = phonenumber;
            llll_newpage[i].l_phonenumber = phonenumber;
        }
        (*llll_current_phonebook_idx)++;
        bach_atomic_unlock(llll_pool_lock);
        x = llll_newpage;
    } else {
        phonenumber_pos = (*llll_current_phonebook_idx)++;
        phonenumber_page = phonenumber_pos / BACH_LLLL_PAGE_SIZE;
        phonenumber_row = phonenumber_pos % BACH_LLLL_PAGE_SIZE;
        phonenumber = llll_phonebook[phonenumber_page][phonenumber_row];
        bach_atomic_unlock(llll_pool_lock);
        llll_page = phonenumber / BACH_LLLL_PAGE_SIZE;
        llll_row = phonenumber % BACH_LLLL_PAGE_SIZE;
        x = llll_book[llll_page] + llll_row;
    }
#ifdef BACH_CHECK_LLLLS
    if (x->l_count != 0 ||
#ifdef BACH_USE_MAGIC_NUMBER
        x->l_magic != BACH_MAGIC_BAD ||
#endif
        x->l_head != NULL ||
        x->l_tail != NULL ||
        x->l_owner != NULL ||
        x->l_size != 0 ||
        x->l_depth != 1 ||
        x->l_flags != 0 ||
        x->l_thing.w_obj != NULL)
        bach_error_break("bad llll from pool");
    
    if (llll_check_phonenumber(x) != MAX_ERR_NONE)
        bach_error_break("bad llllelem phonenumber");
#endif
    x->l_count = 1;
    
#ifdef BACH_CHECK_PHONENUMBERS
    if (llll_check_phonenumber(x))
        bach_error_break("bad llll phonenumber");
#endif

#ifdef BACH_USE_MAGIC_NUMBER
    x->l_magic = BACH_MAGIC_GOOD;
#endif

#ifdef BACH_TRACK_MEMORY_ALLOCATION
    systhread_mutex_lock(memmap_lock);
    /*
    t_symbol *what;
    t_max_err err;
    err = hashtab_lookup(poolmap, (t_symbol *) x, (t_object **) &what);
    if (err || what != _llllobj_sym__llll)
        bach_error_break("llll_get: bad item from pool");
    hashtab_delete(poolmap, (t_symbol *) x);
     */
    bach_store_in_memmap_named(x, _llllobj_sym__llll);
    systhread_mutex_unlock(memmap_lock);
#endif

#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
#ifdef BACH_SAVE_STACK_IN_LLLLS
    bach_save_stack(x->l_alloc_stack);
#endif
#endif
    dev_cprintf("allocating llll %p, phonenumber is %d\n", x, phonenumber);
    return x;
}

t_llll *llll_retrieve_from_phonenumber_and_retain(t_uint32 phonenumber)
{
    t_llll *x;
    t_uint32 llll_page, llll_row;
    bach_atomic_lock(llll_pool_lock);
    if (phonenumber > *llll_pool_size) {
        bach_atomic_unlock(llll_pool_lock);
        return NULL;
    }
    bach_atomic_unlock(llll_pool_lock);
    llll_page = phonenumber / BACH_LLLL_PAGE_SIZE;
    llll_row = phonenumber % BACH_LLLL_PAGE_SIZE;
    x = llll_book[llll_page] + llll_row;
    if (x->l_owner)
        return NULL;
    if (ATOMIC_INCREMENT_32(&x->l_count) == 1) { // which means that this list is not game
        ATOMIC_DECREMENT_32(&x->l_count);
        return NULL;
    }
    return x;
}

t_uint32 llll_phonenumber(t_llll *x)
{
    return x->l_phonenumber;
}

t_llll *llll_make(void)
{
    return llll_get();
}

void llll_init(t_llll *x)
{
#ifdef BACH_USE_MAGIC_NUMBER
    x->l_magic = BACH_MAGIC_GOOD;
#endif
    x->l_count = 1;
    x->l_head = x->l_tail = x->l_owner = NULL;
    x->l_size = 0;
    x->l_depth = 1;
    x->l_flags = 0;
    x->l_thing.w_obj = NULL;
}

void llll_reset(t_llll *x)
{
#ifdef BACH_USE_MAGIC_NUMBER
    x->l_magic = BACH_MAGIC_BAD;
#endif
    x->l_count = 0;
    x->l_head = x->l_tail = x->l_owner = NULL;
    x->l_size = 0;
    x->l_depth = 1;
    x->l_flags = 0;
    x->l_thing.w_obj = NULL;
}

t_llllelem *llllelem_get(void)
{
    //bach_breakpoint(0);
    t_llllelem_numbered *x;
    t_uint32 phonenumber_pos, phonenumber;
    t_uint32 phonenumber_page, phonenumber_row;
    t_uint32 llllelem_page, llllelem_row;
    bach_atomic_lock(llllelem_pool_lock);

    if (*llllelem_current_phonebook_idx == *llllelem_pool_size) {
        long i;
        size_t oldsize = *llllelem_pool_size;
        *llllelem_pool_size += BACH_LLLLELEM_PAGE_SIZE;
        t_uint32 newpage_idx = oldsize / BACH_LLLLELEM_PAGE_SIZE;
        t_llllelem_numbered *llllelem_newpage = llllelem_book[newpage_idx] = (t_llllelem_numbered *) sysmem_newptr(BACH_LLLLELEM_PAGE_SIZE * sizeof(t_llllelem_numbered));
        t_uint32 *phonebook_newpage = llllelem_phonebook[newpage_idx] = (t_uint32 *) sysmem_newptr(BACH_LLLLELEM_PAGE_SIZE * sizeof(t_uint32));
        bach_fill_2n_array(llllelem_model, llllelem_newpage, sizeof(t_llllelem_numbered), BACH_LLLLELEM_PAGE_SIZE);
        for (i = 0, phonenumber = oldsize; i < BACH_LLLLELEM_PAGE_SIZE; i++, phonenumber++) {
            phonebook_newpage[i] = phonenumber;
            llllelem_newpage[i].l_phonenumber = phonenumber;
        }
        (*llllelem_current_phonebook_idx)++;
        bach_atomic_unlock(llllelem_pool_lock);
        x = llllelem_newpage;
    } else {
        phonenumber_pos = (*llllelem_current_phonebook_idx)++;
        phonenumber_page = phonenumber_pos / BACH_LLLLELEM_PAGE_SIZE;
        phonenumber_row = phonenumber_pos % BACH_LLLLELEM_PAGE_SIZE;
        phonenumber = llllelem_phonebook[phonenumber_page][phonenumber_row];
        bach_atomic_unlock(llllelem_pool_lock);
        llllelem_page = phonenumber / BACH_LLLLELEM_PAGE_SIZE;
        llllelem_row = phonenumber % BACH_LLLLELEM_PAGE_SIZE;
        x = llllelem_book[llllelem_page] + llllelem_row;
    }
#ifdef BACH_CHECK_LLLLS
    if (x->l_elem.l_flags != 0 ||
#ifdef BACH_USE_MAGIC_NUMBER
        x->l_elem.l_magic != BACH_MAGIC_BAD ||
#endif
        x->l_elem.l_prev != NULL ||
        x->l_elem.l_next != NULL ||
        x->l_elem.l_parent != NULL ||
        x->l_elem.l_thing.w_obj != NULL)
        bach_error_break("bad llllelem from pool");
#endif
    
#ifdef BACH_CHECK_PHONENUMBERS
    if (llllelem_check_phonenumber(x))
        bach_error_break("bad llll phonenumber");
#endif
    
#ifdef BACH_USE_MAGIC_NUMBER
    x->l_elem.l_magic = BACH_MAGIC_GOOD;
#endif
    
#ifdef BACH_TRACK_MEMORY_ALLOCATION
    systhread_mutex_lock(memmap_lock);
    /*
    t_symbol *what;
    t_max_err err;
    err = hashtab_lookup(poolmap, (t_symbol *) x, (t_object **) &what);
    if (err || what != _llllobj_sym__llllelem)
        bach_error_break("llllelem_get: bad item from pool");
    hashtab_delete(poolmap, (t_symbol *) x);
     */
    bach_store_in_memmap_named(x, _llllobj_sym__llllelem);
    systhread_mutex_unlock(memmap_lock);
#endif
    
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
#ifdef BACH_SAVE_STACK_IN_LLLLS
    bach_save_stack(x->l_elem.l_alloc_stack);
#endif
#endif
    dev_cprintf("allocating llllelem %p, phonenumber is %d\n", x, phonenumber);

    return &x->l_elem;
}

t_llllelem *llllelem_make(void)
{
    return llllelem_get();
}

void llllelem_init(t_llllelem *x)
{
#ifdef BACH_USE_MAGIC_NUMBER
    x->l_magic = BACH_MAGIC_GOOD;
#endif
    x->l_prev = x->l_next = NULL;
    x->l_flags = 0;
    x->l_parent = NULL;
    x->l_thing.w_obj = NULL;
}

void llllelem_reset(t_llllelem *x)
{
#ifdef BACH_USE_MAGIC_NUMBER
    x->l_magic = BACH_MAGIC_BAD;
#endif
    x->l_prev = x->l_next = NULL;
    x->l_flags = 0;
    x->l_parent = NULL;
    x->l_thing.w_obj = NULL;
}

double parse_64bit_float(t_atom *av)
{
    t_uint64 l;
    double *f = (double *) &l;
    ++av;
    l = *((t_uint32*) &av->a_w.w_long);
    ++av;
    t_uint64 l_hi = ((t_uint64) (*((t_uint32*) &av->a_w.w_long))) << 32;
    l |= l_hi;
#ifdef whyohwyy
#ifdef C74_X64
#ifdef BACH_USE_NATIVE_128BIT_INTEGER
    ++av;
    l = *((t_uint32*) &av->a_w.w_long);
    ++av;
    t_uint64 l_hi = ((t_uint64) (*((t_uint32*) &av->a_w.w_long))) << 32;
    l |= l_hi;
#else
    ++av;
    l = av->a_w.w_long;
    ++av;
    t_uint64 l_hi = av->a_w.w_long << 32;
    l |= l_hi;
#endif
#else
    ++av;
    l = *((t_uint32*) &av->a_w.w_long);
    ++av;
    t_uint64 l_hi = ((t_uint64) (*((t_uint32*) &av->a_w.w_long))) << 32;
    l |= l_hi;
#endif
#endif // whyohwhy

    return *f;
}

t_llll *llll_parse(long ac, t_atom *av, long ignore) // creates a new llll from a list in text format
{
    long depth;
    t_llll *this_llll;
    t_llll_stack *stack;
    t_llll *x;
    const t_symbol *f64m = _llllobj_sym_float64_marker;
    
    x = llll_get();
    
    if (!ac)
        return x;
    
    this_llll = x;
    stack = llll_stack_new();
    
    depth = 1;
    
    char dollarnum[256];
    t_symParser symParser(ignore);
    long type;
    long i;
    
    for (i = 0; i < ac || (i == 0 && ac < 0); i++, av++) {
        switch (type = atom_gettype(av)) {
            case A_LONG:
                llll_appendlong(this_llll, av->a_w.w_long, 0, WHITENULL_llll);
                break;
            case A_FLOAT:
                llll_appenddouble(this_llll, av->a_w.w_float, 0, WHITENULL_llll);
                break;
            case A_COMMA:
                llll_appendsym(this_llll, gensym(","), 0, WHITENULL_llll);
                break;
            case A_SEMI:
                llll_appendsym(this_llll, gensym(";"), 0, WHITENULL_llll);
                break;
            case A_DOLLSYM:
                llll_appendsym(this_llll, gensym("$"), 0, WHITENULL_llll);
                break;
            case A_DOLLAR:
#ifdef BACH_MAX
                snprintf_zero(dollarnum, 256, "$" ATOM_LONG_PRINTF_FMT, av->a_w.w_long);
#else
                snprintf(dollarnum, 256, "$" ATOM_LONG_PRINTF_FMT, av->a_w.w_long);
#endif
                llll_appendsym(this_llll, gensym(dollarnum), 0, WHITENULL_llll);
                break;
            case A_SYM: {
                t_symbol *s = av->a_w.w_sym;
                if (s == f64m) {
                    double f = parse_64bit_float(av);
                    llll_appenddouble(this_llll, f, 0, WHITENULL_llll);
                    av += 2;
                    i += 2;
                } /*else if (llll_contains_separators(s->s_name)) {
                   llll_appendsym(this_llll, s);
                   } */else {
                       symParser.parse(s->s_name, &this_llll, stack, &depth);
                       if (depth < 1)
                           goto llll_parse_err;
                   }
                break;
            }
        }
        
    }
        
    if (stack->s_items)
        goto llll_parse_err;
    llll_stack_destroy(stack);
    return x;
    
    
llll_parse_err:
    llll_stack_destroy(stack);
    llll_free(x);
    return NULL;
}


t_llll *llll_from_text_buf(const char *txt, t_bool big, long ignore) // creates a new llll from a list contained in a string
{
    long depth;
    t_llll *this_llll;
    t_llll_stack *stack;
    t_llll *x;
    
    x = llll_get();
    
    if (!txt)
        return x;
    
    this_llll = x;
    stack = llll_stack_new();
    
    depth = 1;
    
    t_strParser strParser(big, ignore);
    strParser.parse(txt, &this_llll, stack, &depth);

    if (depth != 1)
        goto llll_parse_string_err;
    llll_stack_destroy(stack);
    return x;
    
    
llll_parse_string_err:
    llll_stack_destroy(stack);
    llll_free(x);
    return NULL;
}


// still uses the old, non-flex parser
// doesn't recognize pitches
// useful only for bw-compatibility in bach.tree
t_llll *llll_parse_with_leveltypes(long ac, t_atom *av) // creates a new llll from a list in text format, taking into account different types of parentheses
{
    //    char *inlist;
    long i;
    t_llll *this_llll, *temp_llll;
    long len;
    t_llll_stack *stack;
    char *cursor = NULL, *thing_end, *txt, *more_txt, *bspos;
    long type;
    long leveltype = L_STANDARD;
    long a, b;
    char dollarnum[256];
    t_llll *x;
    
    t_symbol *f64m = _llllobj_sym_float64_marker;
    
    x = llll_get();
    
    if (!ac)
        return x;
    if (ac == 1 && atom_gettype(av) == A_OBJ) {
        cursor = (char *) atom_getobj(av);
        ac = -1;
    }
    
    this_llll = x;
    stack = llll_stack_new();
    
    for (i = 0; i < ac || (i == 0 && ac < 0); i++, av++) {
        if (!cursor) {
            switch (type = atom_gettype(av)) {
                case A_LONG:
                    llll_appendlong(this_llll, av->a_w.w_long, 0, WHITENULL_llll);
                    break;
                case A_FLOAT:
                    llll_appenddouble(this_llll, av->a_w.w_float, 0, WHITENULL_llll);
                    break;
                case A_COMMA:
                    llll_appendsym(this_llll, gensym(","), 0, WHITENULL_llll);
                    break;
                case A_SEMI:
                    llll_appendsym(this_llll, gensym(";"), 0, WHITENULL_llll);
                    break;
                case A_DOLLSYM:
                    llll_appendsym(this_llll, gensym("$"), 0, WHITENULL_llll);
                    break;
                case A_DOLLAR:
#ifdef BACH_MAX
                    snprintf_zero(dollarnum, 256, "$" ATOM_LONG_PRINTF_FMT, av->a_w.w_long);
#else
                    snprintf(dollarnum, 256, "$" ATOM_LONG_PRINTF_FMT, av->a_w.w_long);
#endif
                    llll_appendsym(this_llll, gensym(dollarnum), 0, WHITENULL_llll);
                    break;
                case A_SYM:
                    if (av->a_w.w_sym == f64m) {
                        double f = parse_64bit_float(av);
                        llll_appenddouble(this_llll, f, 0, WHITENULL_llll);
                        av += 2;
                        i += 2;
                    } else {
                        cursor = av->a_w.w_sym->s_name;
                        if (*cursor == QUOTE_CHAR && *(cursor + 1)) {
                            //                            if (!strrchr(cursor, '\\')
                            llll_appendsym(this_llll, gensym(cursor + 1), 0, WHITENULL_llll);
                            /*                            else {
                             len = strlen(cursor);
                             txt = (char *) bach_newptr(len);
                             strncpy_zero(txt, cursor + 1, len);
                             while (bspos = strchr(txt, '\\'))
                             strcpy(bspos, bspos - 1);
                             llll_appendsym(this_llll, gensym(txt), 0, WHITENULL_llll);
                             bach_freeptr(txt);
                             } */
                            cursor = NULL;
                        } else if (llll_contains_separators(cursor)) {
                            llll_appendsym(this_llll, av->a_w.w_sym, 0, WHITENULL_llll);
                            cursor = NULL;
                        }
                    }
                    break;
            }
        }
        while (cursor && *cursor) {
            long backtick = 0, type;
            char prev_thing_end;
            switch (*cursor) {
                case '(':
                case '[':
                case '{':
                    temp_llll = llll_get();
                    llll_appendllll(this_llll, temp_llll, 0, WHITENULL_llll);
                    llll_stack_push(stack, this_llll);
                    this_llll = temp_llll;
                    switch (*cursor) {
                        case '(':
                            leveltype = L_STANDARD;
                            break;
                        case '[':
                            leveltype = L_SQUARE;
                            break;
                        case '{':
                            leveltype = L_CURLY;
                            break;
                    }
                    temp_llll->l_thing.w_long = leveltype;
                    cursor++;
                    break;
                    
                case ')': // terminates a sub-list
                case ']':
                case '}':
                    if (*cursor != _closed_parentheses[leveltype])
                        goto llll_parse_with_leveltypes_err;
                    
                    temp_llll = (t_llll *) llll_stack_pop(stack);
                    if (!temp_llll)
                        goto llll_parse_with_leveltypes_err;
                    if (temp_llll->l_depth <= this_llll->l_depth)
                        temp_llll->l_depth = 1 + this_llll->l_depth;
                    this_llll = temp_llll;
                    leveltype = this_llll->l_thing.w_long;
                    cursor++;
                    break;
                    
                case '"':
                    cursor++;
                    thing_end = cursor;
                    while (*thing_end && *thing_end != '"')
                        thing_end++;
                    if (!*thing_end)
                        goto llll_parse_with_leveltypes_err;
                    len = thing_end - cursor;
                    txt = (char *) bach_newptr(len + 1);
#ifdef BACH_MAX
                    strncpy_zero(txt, cursor, len + 1);
#else
                    strncpy(txt, cursor, len + 1);
#endif
                    *(txt + len) = 0; // txt contains the current re-parsed llll atom
                    llll_appendsym(this_llll, gensym(txt), 0, WHITENULL_llll);
                    cursor = thing_end + 1;
                    break;
                    
                case QUOTE_CHAR:
                    if (ac < 0) {
                        backtick = 1;    // backtick is set if the current item begins with ` in string mode
                        cursor++;
                    }
                    
                default:
                    thing_end = cursor;
                    prev_thing_end = 0;
                    // search for the end of this element, which is given by:
                    
                    while (*thing_end &&                                                                // the string end, or
                           (backtick || (*thing_end != '(' && *thing_end != ')' &&
                                         *thing_end != '[' && *thing_end != ']' &&
                                         *thing_end != '{' && *thing_end != '}')) &&                    // a parenthesis, but only if we don't have backtick set
                           (!isspace(*thing_end) || (prev_thing_end == '\\' && ac < 0))) {    // a space, but only if it's not backslashed, or we're not in string mode
                        prev_thing_end = *thing_end;
                        thing_end ++;
                    }
                    
                    len = thing_end - cursor;
                    txt = (char *) bach_newptr(len + 1); 
#ifdef BACH_MAX
                    strncpy_zero(txt, cursor, len + 1);
#else
                    strncpy(txt, cursor, len + 1);
#endif
                    *(txt + len) = 0; // txt contains the current re-parsed llll atom
                    
                    type = backtick ? H_SYM : llll_typecheck(txt);
                    
                    switch(type) {
                        case H_LONG:
                            llll_appendlong(this_llll, strtol(txt, NULL, 10), 0, WHITENULL_llll);
                            break;
                        case H_DOUBLE:
                            llll_appenddouble(this_llll, strtod(txt, NULL), 0, WHITENULL_llll);
                            break;
                        case H_SYM:
                            if (!strcmp(txt, "nil")) {
                                llll_appendllll(this_llll, llll_get(), 0, WHITENULL_llll);
                                break;
                            }
                            if (!strcmp(txt, "null"))
                                break;
                            
                            if (ac < 0) {
                                char *this_txt = txt;
                                bspos = txt;
                                while (*bspos) {
                                    if (*bspos == '\\')
                                        bspos++;
                                    *this_txt++ = *bspos++;
                                }
                                *this_txt = 0;
                            }
                            
                            llll_appendsym(this_llll, gensym(txt), 0, WHITENULL_llll);
                            break;
                        case H_RAT:
                            a = strtol(txt, &more_txt, 10);
                            b = strtol(more_txt + 1, NULL, 10);
                            llll_appendrat_from_elems(this_llll, a, b, 0, WHITENULL_llll);
                            break;
                        default:
                            break;
                    }
                    bach_freeptr(txt);
                    cursor = thing_end; // points to the separator, because it must be parsed
                    break;
            }
            cursor = llll_next_thing(cursor);            
        }
        cursor = NULL;
    }
    
    if (stack->s_items)
        goto llll_parse_with_leveltypes_err;
    llll_stack_destroy(stack);
    return x;
    
llll_parse_with_leveltypes_err:
    llll_stack_destroy(stack);
    llll_free(x);
    return NULL;
}


void llllelem_dispose(t_llllelem *x)
{
    t_uint32 phonenumber_pos;
    t_uint32 phonenumber_page, phonenumber_row;
    //t_uint32 phonenumber = x->l_phonenumber;
    dev_cprintf("freeing llllelem %p, phonenumber is %d\n", x, ((t_llllelem_numbered *) x)->l_phonenumber);
    
    //bach_copyptr(llllelem_model, x, sizeof(t_llllelem));
    x->l_prev = NULL;
    x->l_next = NULL;
    x->l_parent = NULL;
    x->l_thing.w_obj = NULL;
    x->l_flags = NULL;
    if (x->l_hatom.h_type == H_FUNCTION)
        x->l_hatom.h_w.w_func->decrease();
#ifdef BACH_USE_MAGIC_NUMBER
    x->l_magic = BACH_MAGIC_BAD;
#endif
    //x->l_phonenumber = phonenumber;
#ifdef BACH_CHECK_PHONENUMBERS
    if (llllelem_check_phonenumber((t_llllelem_numbered *) x))
        bach_error_break("freeing llllelem with bad phonenumber");
#endif
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
#ifdef BACH_SAVE_STACK_IN_LLLLS
    bach_save_stack(x->l_free_stack);
#endif
#endif
    bach_atomic_lock(llllelem_pool_lock);
    phonenumber_pos = --*llllelem_current_phonebook_idx;
    phonenumber_page = phonenumber_pos / BACH_LLLL_PAGE_SIZE;
    phonenumber_row = phonenumber_pos % BACH_LLLL_PAGE_SIZE;
    llllelem_phonebook[phonenumber_page][phonenumber_row] = ((t_llllelem_numbered *) x)->l_phonenumber;
#ifdef BACH_TRACK_MEMORY_ALLOCATION
    systhread_mutex_lock(memmap_lock);
    /*
     t_symbol *what;
     t_max_err err;
     err = hashtab_lookup(poolmap, (t_symbol *) x, (t_object **) &what);
     if (!err)
     bach_error_break("llllelem_dispose: freeing something already being in the pool");
     hashtab_store_safe(poolmap, (t_symbol *) x, (t_object *) _llllobj_sym__llllelem);
     */
    bach_remove_from_memmap(x);
    systhread_mutex_unlock(memmap_lock);
#endif
    bach_atomic_unlock(llllelem_pool_lock);
}

void llll_dispose(t_llll *x)
{
    t_uint32 phonenumber_pos;
    t_uint32 phonenumber_page, phonenumber_row;
    //t_uint32 phonenumber = x->l_phonenumber;
    dev_cprintf("freeing llll %p, phonenumber is %d\n", x, x->l_phonenumber);
#ifdef BACH_CHECK_PHONENUMBERS
    if (llll_check_phonenumber(x))
        bach_error_break("freeing llll with bad phonenumber");
#endif
    //bach_copyptr(llll_model, x, sizeof(t_llll));
    //x->l_phonenumber = phonenumber;
#ifdef BACH_CHECK_LLLLS
    if (x->l_count != 0)
        bach_error_break("llll_free: llll with count != 0");
#endif
    x->l_head = NULL;
    x->l_tail = NULL;
    x->l_owner = NULL;
    x->l_thing.w_obj = NULL;
    x->l_size = 0;
    x->l_depth = 1;
    x->l_flags = 0;
#ifdef BACH_USE_MAGIC_NUMBER
    x->l_magic = BACH_MAGIC_BAD;
#endif
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
#ifdef BACH_SAVE_STACK_IN_LLLLS
    bach_save_stack(x->l_free_stack);
#endif
#endif
    bach_atomic_lock(llll_pool_lock);
    phonenumber_pos = --*llll_current_phonebook_idx;
    phonenumber_page = phonenumber_pos / BACH_LLLL_PAGE_SIZE;
    phonenumber_row = phonenumber_pos % BACH_LLLL_PAGE_SIZE;
    llll_phonebook[phonenumber_page][phonenumber_row] = x->l_phonenumber;
#ifdef BACH_TRACK_MEMORY_ALLOCATION

    systhread_mutex_lock(memmap_lock);
    /*
     t_symbol *what;
     t_max_err err;
     err = hashtab_lookup(poolmap, (t_symbol *) x, (t_object **) &what);
     if (!err)
     bach_error_break("llll_dispose: freeing something already being in the pool");
     hashtab_store_safe(poolmap, (t_symbol *) x, (t_object *) _llllobj_sym__llll);
     */
    bach_remove_from_memmap(x);
    systhread_mutex_unlock(memmap_lock);
#endif
    bach_atomic_unlock(llll_pool_lock);
}

void llll_fix_owner_for_check(t_llll *ll)
{
#ifdef BACH_CHECK_LLLLS
    ll->l_owner = NULL;
#endif
}

void llll_free_nocheck(t_llll *ll)
{

    if (!ll)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    if (ll->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llll_free_nocheck: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    
    if (ATOMIC_DECREMENT_32(&ll->l_count)) // release
        return;
    
    llll_destroy(ll);
}

void llll_destroy(t_llll *ll)
{
    t_llll_stack *stack;
    t_llllelem *elem, *nextelem;
    
    if (!(ll->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF))) {
        
        stack = llll_stack_new();
        elem = ll->l_head;
        
        while (1) {
            while (elem) {
                nextelem = elem->l_next;
                if (elem->l_hatom.h_type != H_LLLL ||
                    elem->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF)) {
                    llllelem_dispose(elem);
                    elem = nextelem;
                } else {
                    //                    elem->l_parent = ll; // just to be sure, or we'll lose ourselves!
                    llll_stack_push(stack, elem);
                    ll = elem->l_hatom.h_w.w_llll;
                    elem = ll->l_head;
#ifdef BACH_CHECK_LLLLS
                    if (ATOMIC_DECREMENT_32(&ll->l_count)) {
                        bach_error_break("llll_free: sublist has a count different from 1");
                    }
#endif
                }
            }
            llll_dispose(ll);
            if (stack->s_items == 0)
                break;
            elem = (t_llllelem *) llll_stack_pop(stack);
            ll = elem->l_parent;
            nextelem = elem->l_next;
            llllelem_dispose(elem);
            elem = nextelem;
        }
        llll_stack_destroy(stack);
    } else {
        llll_dispose(ll);
    }
}

void llll_free(t_llll *ll)
{
#ifdef BACH_CHECK_LLLLS
    if (llll_check(ll)) {
        bach_error_break("llll_free: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
    }
#endif // BACH_CHECK_LLLLS
    llll_free_nocheck(ll);
}

t_llll *llll_retain(t_llll *ll)
{
#ifdef BACH_CHECK_LLLLS
    if (llll_check(ll)) {
        bach_error_break("llll_retain: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
    }
#endif // BACH_CHECK_LLLLS
    if (ll)
        ATOMIC_INCREMENT(&ll->l_count);
    return ll;
}

t_llll *llll_retain_nocheck(t_llll *ll)
{
    if (ll)
        ATOMIC_INCREMENT(&ll->l_count);
    return ll;
}

t_llll *llll_retain_unsafe(t_llll *ll)
{
#ifdef BACH_CHECK_LLLLS
    if (llll_check(ll)) {
        bach_error_break("llll_retain_unsafe: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
    }
#endif // BACH_CHECK_LLLLS
    if (ll)
        ++(ll->l_count);
    return ll;
}

void llll_release_unsafe(t_llll *ll)
{
#ifdef BACH_CHECK_LLLLS
    if (llll_check(ll)) {
        bach_error_break("llll_release_unsafe: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
    }
#endif // BACH_CHECK_LLLLS
    
    if (!ll)
        return;
    if (--(ll->l_count) == 0)
        llll_destroy(ll);
}

void llll_release(t_llll *ll)
{
    llll_free(ll);
}

void llll_free_nocheck_freethings(t_llll *ll, e_freething_modes freething)
{
    t_llll_stack *stack;
    t_llllelem *elem, *nextelem;
    if (!ll)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    //    if (NOGOOD(ll) || ob_sym(ll) != _llllobj_sym_bach_llll) {
    if (ll->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llll_free_nocheck_freethings: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    if (ATOMIC_DECREMENT(&ll->l_count)) // release
        return;

    if (!(ll->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF))) {
        
        stack = llll_stack_new();
        elem = ll->l_head;
        
        while (1) {
            while (elem) {
                nextelem = elem->l_next;
                if (elem->l_hatom.h_type != H_LLLL || elem->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF)) {
                    llllelem_dispose(elem);
                    elem = nextelem;
                } else {
                    elem->l_parent = ll; // just to be sure, or we'll lose ourselves!
                    llll_stack_push(stack, elem);
                    ll = elem->l_hatom.h_w.w_llll;
#ifdef BACH_CHECK_LLLLS
                    if (ATOMIC_DECREMENT_32(&ll->l_count)) {
                        bach_error_break("llll_free: sublist has a count different from 1");
                    }
#endif
                    elem = ll->l_head;
                }
            }
            if (ll->l_thing.w_obj) {
                switch (freething) {
                    case LLLL_FREETHING_MEM:
                        bach_freeptr(ll->l_thing.w_obj);
                        break;
                    case LLLL_FREETHING_OBJ:
                        object_free_debug(ll->l_thing.w_obj);
                        break;
                    case LLLL_FREETHING_LLLL:
                        llll_free(ll->l_thing.w_llll);
                        break;
                    case LLLL_FREETHING_LLLLELEM:
                        llllelem_free(ll->l_thing.w_llllelem);
                        break;
                    default:
                        break;
                }
            }
            ll->l_thing.w_obj = NULL;
            llll_dispose(ll);
            if (stack->s_items == 0)
                break;
            elem = (t_llllelem *) llll_stack_pop(stack);
            ll = elem->l_parent;
            nextelem = elem->l_next;
            llllelem_dispose(elem);
            elem = nextelem;    
        } 
        llll_stack_destroy(stack);
        
    } else {
        llll_dispose(ll);
    }
}

void llll_free_freethings(t_llll *ll, e_freething_modes freething)
{
#ifdef BACH_CHECK_LLLLS
    if (llll_check(ll)) {
        bach_error_break("llll_free_freethings: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
    }
#endif // BACH_CHECK_LLLLS
    llll_free_nocheck_freethings(ll, freething);
}

void llllelem_free_nocheck(t_llllelem *elem)
{
    t_llll *ll;
    if (!elem)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    //    if (NOGOOD(elem) || ob_sym(elem) != _llllobj_sym_bach_llllelem) {
    if (elem->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llllelem_free_nocheck: bad llllelem");
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    if (elem->l_hatom.h_type == H_LLLL && !(elem->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF))) {
        ll = elem->l_hatom.h_w.w_llll;
        if (ll)
            llll_free_nocheck(ll);
    }
    llllelem_dispose(elem);
}

void llllelem_free_nocheck_freethings(t_llllelem *elem, e_freething_modes freething)
{
    t_llll *ll;
    if (!elem)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    if (elem->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llllelem_free_nocheck_freethings: bad llllelem");
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    if (elem->l_hatom.h_type == H_LLLL && !(elem->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF))) {
        ll = elem->l_hatom.h_w.w_llll;
        if (ll)
            llll_free_nocheck_freethings(ll, freething);
    }
    llllelem_dispose(elem);
}

void llllelem_free(t_llllelem *elem)
{
    t_llll *ll;
    if (!elem)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    if (elem->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llllelem_free: bad llllelem");
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    if (elem->l_hatom.h_type == H_LLLL && !(elem->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF))) {
        ll = elem->l_hatom.h_w.w_llll;
        if (ll) {
            llll_fix_owner_for_check(ll);
            llll_free(ll);
        }
    }
    llllelem_dispose(elem);
}

void llllelem_free_freethings(t_llllelem *elem, e_freething_modes freething)
{
    t_llll *ll;
    if (!elem)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    if (elem->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llllelem_free_freethings: bad llllelem");
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    if (elem->l_hatom.h_type == H_LLLL && !(elem->l_flags & (OBJ_FLAG_DATA | OBJ_FLAG_REF))) {
        ll = elem->l_hatom.h_w.w_llll;
        if (ll)
            llll_free_freethings(ll, freething);
    }
    llllelem_dispose(elem);
}

void llllelem_chuck(t_llllelem *elem)
{
    if (!elem)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    if (elem->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llllelem_chuck: bad llllelem");
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    llllelem_dispose(elem);
}

void llll_freethings(t_llll *ll, e_freething_modes freething)
{
    t_llll_stack *elem_stack, *ll_stack;
    t_llllelem *elem;
    
    if (!ll)
        return;
#ifdef BACH_CHECK_LLLLS
#ifdef BACH_USE_MAGIC_NUMBER
    if (ll->l_magic != BACH_MAGIC_GOOD) {
        bach_error_break("llll_freethings: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
        return;
    }
#endif
#endif // BACH_CHECK_LLLLS
    
    elem_stack = llll_stack_new();
    ll_stack = llll_stack_new();
    elem = ll->l_head;
    
    while (1) {
        while (elem) {
            if (elem->l_hatom.h_type != H_LLLL) {
                elem = elem->l_next;
            } else {
                llll_stack_push(ll_stack, ll); // just to be sure, or we'll lose ourselves!
                llll_stack_push(elem_stack, elem->l_next);
                ll = elem->l_hatom.h_w.w_llll;
                elem = ll->l_head;
            }
        }
        if (elem_stack->s_items == 0)
            break;
        elem = (t_llllelem *) llll_stack_pop(elem_stack);
        ll = (t_llll *) llll_stack_pop(ll_stack);
    }
    if (ll->l_thing.w_obj) {
        switch (freething) {
            case LLLL_FREETHING_MEM:
                bach_freeptr(ll->l_thing.w_obj);
                break;
            case LLLL_FREETHING_OBJ:
                object_free_debug(ll->l_thing.w_obj);
                break;
            case LLLL_FREETHING_LLLL:
                llll_free(ll->l_thing.w_llll);
                break;
            case LLLL_FREETHING_LLLLELEM:
                llllelem_free(ll->l_thing.w_llllelem);
                break;
            default:
                break;
        }
        ll->l_thing.w_obj = NULL;
    }
    llll_stack_destroy(elem_stack);
    llll_stack_destroy(ll_stack);
}

// frees a list, but not the elements it contains
void llll_chuck(t_llll *ll)
{
    if (!ll)
        return;
#ifdef BACH_CHECK_LLLLS
    if (llll_check(ll)) {
        bach_error_break("llll_chuck: bad llll");
        llll_print(ll, NULL, 2, 6, NULL);
    }
    if (ATOMIC_DECREMENT_32(&ll->l_count))
        bach_error_break("llll_chuck_nocheck: llll with count != 0");
#endif // BACH_CHECK_LLLLS
    llll_dispose(ll);
}

// frees a list, but not the elements it contains
void llll_chuck_nocheck(t_llll *ll)
{
    if (!ll)
        return;
#ifdef BACH_CHECK_LLLLS
    if (ATOMIC_DECREMENT_32(&ll->l_count))
        bach_error_break("llll_chuck_nocheck: llll with count != 0");
#endif // BACH_CHECK_LLLLS
    llll_dispose(ll);
}

t_max_err llll_check(const t_llll *ll)
{
#ifndef CONFIGURATION_Deployment
    t_llll_stack *stack = NULL;
    //t_llll *depths = NULL, *lengths = NULL;
    t_llllelem *elem;
    //t_llllelem *depth_elem;
    long *lengths_arr = NULL, *depths_arr = NULL;
    long base_depth, curr_depth;
    
    if (!ll)
        return MAX_ERR_NONE;
#ifdef BACH_USE_MAGIC_NUMBER
    if (ll->l_magic != BACH_MAGIC_GOOD)
        return llll_check_error(stack, depths_arr, lengths_arr);
#endif
    if (ll->l_count == 0)
        return llll_check_error(stack, depths_arr, lengths_arr);

#ifdef BACH_CHECK_PHONENUMBERS
if (llll_check_phonenumber(ll))
        return llll_check_error(stack, depths_arr, lengths_arr);
#endif
    //if (ll->l_owner)
    //    return llll_check_error(stack, depths, lengths);
    
    stack = llll_stack_new();
    //depths = llll_get();
    //lengths = llll_get();
    base_depth = ll->l_depth;
    if (base_depth <= 0)
        return llll_check_error(stack, depths_arr, lengths_arr);
    lengths_arr = (long *) sysmem_newptr(base_depth * sizeof(long));
    depths_arr = (long *) sysmem_newptr(base_depth * sizeof(long));
    
    elem = ll->l_head;
    //llll_appendlong(lengths, 0, 0, WHITENULL_llll);
    //llll_appendlong(depths, 1, 0, WHITENULL_llll);
    lengths_arr[0] = 0;
    depths_arr[0] = 1;
    curr_depth = 1;
    
    while (1) {
        while (elem) {
#ifdef BACH_CHECK_PHONENUMBERS
            if (llllelem_check_phonenumber((t_llllelem_numbered *) elem))
                return llll_check_error(stack, depths_arr, lengths_arr);
#endif
            if (elem->l_parent != ll)
                return llll_check_error(stack, depths_arr, lengths_arr);
            if (elem->l_prev) {
                if (elem->l_prev->l_next != elem)
                    return llll_check_error(stack, depths_arr, lengths_arr);
            } else {
                if (elem != ll->l_head)
                    return llll_check_error(stack, depths_arr, lengths_arr);
            }
            
            if (elem->l_next) {
                if (elem->l_next->l_prev != elem)
                    return llll_check_error(stack, depths_arr, lengths_arr);
            } else {
                if (elem != ll->l_tail)
                    return llll_check_error(stack, depths_arr, lengths_arr);
            }
            if (elem->l_parent != ll)
                return llll_check_error(stack, depths_arr, lengths_arr);
            
            //lengths->l_tail->l_hatom.h_w.w_long++;
            lengths_arr[curr_depth - 1]++;
            switch (elem->l_hatom.h_type) {
                case H_LONG:
                case H_DOUBLE:
                case H_RAT:
                case H_PITCH:
                case H_OBJ:
                case H_FUNCTION:
                    elem = elem->l_next;
                    break;
                case H_SYM:
                    if (elem->l_hatom.h_w.w_sym == NULL) // if a symbol is NULL, this causes lots of troubles when deparsing!!
                        return llll_check_error(stack, depths_arr, lengths_arr);
                    elem = elem->l_next;
                    break;
                case H_LLLL:
                    ll = elem->l_hatom.h_w.w_llll;
                    llll_stack_push(stack, elem); // watch out! this is different from what happens usually!
                    if (!ll)
                        return llll_check_error(stack, depths_arr, lengths_arr);
                    if (llll_check_phonenumber(ll))
                        return llll_check_error(stack, depths_arr, lengths_arr);
#ifdef BACH_USE_MAGIC_NUMBER
                    if (ll->l_magic != BACH_MAGIC_GOOD)
                        return llll_check_error(stack, depths_arr, lengths_arr);
#endif
                    if (ll->l_owner != elem)
                        return llll_check_error(stack, depths_arr, lengths_arr);
                    elem = ll->l_head;
                    curr_depth++;
                    if (curr_depth > base_depth)
                        return llll_check_error(stack, depths_arr, lengths_arr);
                    lengths_arr[curr_depth - 1] = 0;
                    //llll_appendlong(lengths, 0, 0, WHITENULL_llll);
                    //llll_appendlong(depths, 1, 0, WHITENULL_llll);
                    //for (depth_elem = depths->l_tail->l_prev; depth_elem; depth_elem = depth_elem->l_prev) {
                        //if (depth_elem->l_hatom.h_w.w_long < depth_elem->l_next->l_hatom.h_w.w_long + 1)
                            //depth_elem->l_hatom.h_w.w_long++;
                        //else
                            //break;
                    //}
                    depths_arr[curr_depth - 1] = 1;
                    long i;
                    for (i = curr_depth - 2; i >= 0; i--) {
                        if (depths_arr[i] <= depths_arr[i+1])
                            depths_arr[i]++;
                        else
                            break;
                    }
                    break;
                default:
                    return llll_check_error(stack, depths_arr, lengths_arr);
                    break;
            }
        }
        //if (depths->l_tail->l_hatom.h_w.w_long != ll->l_depth)
        //    return llll_check_error(stack, depths_arr, lengths_arr); // l_depth is wrong
        if (depths_arr[curr_depth - 1] != ll->l_depth)
            return llll_check_error(stack, depths_arr, lengths_arr); // l_depth is wrong

        //if (lengths->l_tail->l_hatom.h_w.w_long != ll->l_size)
        //    return llll_check_error(stack, depths, lengths); // l_size is wrong
        if (lengths_arr[curr_depth - 1] != ll->l_size)
            return llll_check_error(stack, depths_arr, lengths_arr); // l_depth is wrong

        //llll_destroyelem_no_depth_check(depths->l_tail);
        //llll_destroyelem_no_depth_check(lengths->l_tail);
        curr_depth--;
        if (stack->s_items < 1)
            break;
        if (curr_depth < 0)
            return llll_check_error(stack, depths_arr, lengths_arr); // something is wrong
        elem = (t_llllelem *) llll_stack_pop(stack);
        ll = elem->l_parent; // this has already been checked (this is why we do differently than usual)
        elem = elem->l_next;
    }
    if (curr_depth != 0)
        return llll_check_error(stack, depths_arr, lengths_arr); // something is wrong
    sysmem_freeptr(depths_arr);
    sysmem_freeptr(lengths_arr);

    llll_stack_destroy(stack);
    //llll_free_nocheck(depths);
    //llll_free_nocheck(lengths);
#endif
    return MAX_ERR_NONE;
}

t_max_err llll_check_error(t_llll_stack *stack, long *depths_arr, long *lengths_arr)
{
    bach_breakpoint(0);
    if (stack)
        llll_stack_destroy(stack);
    if (depths_arr)
        sysmem_freeptr(depths_arr);
    if (lengths_arr)
        sysmem_freeptr(lengths_arr);
    return MAX_ERR_GENERIC;
}

t_max_err bach_check_phonenumber_error(void)
{
    bach_breakpoint(0);
    return MAX_ERR_GENERIC;
}

t_max_err llll_check_phonenumber(const t_llll *ll)
{
    t_int32 phonenumber = ll->l_phonenumber;
    if (phonenumber > *llll_pool_size) {
        bach_check_phonenumber_error();
        return MAX_ERR_GENERIC;
    }
    t_int32 page = phonenumber / BACH_LLLL_PAGE_SIZE;
    t_int32 row = phonenumber % BACH_LLLL_PAGE_SIZE;
    
    if (ll != llll_book[page] + row) {
        bach_check_phonenumber_error();
        return MAX_ERR_GENERIC;
    }
    
    return MAX_ERR_NONE;
}


t_max_err llllelem_check_phonenumber(const t_llllelem_numbered *el)
{
    t_int32 phonenumber = el->l_phonenumber;
    if (phonenumber > *llllelem_pool_size) {
        bach_check_phonenumber_error();
        return MAX_ERR_GENERIC;
    }
    t_int32 page = phonenumber / BACH_LLLL_PAGE_SIZE;
    t_int32 row = phonenumber % BACH_LLLL_PAGE_SIZE;
    
    if (el != llllelem_book[page] + row) {
        bach_check_phonenumber_error();
        return MAX_ERR_GENERIC;
    }
    
    return MAX_ERR_NONE;
}


long bach_is_loadtime(void)
{
    if (loadtime)
        return 1;
#ifdef MAC_VERSION
    void *frames[256];
    long count = backtrace(frames, 256);
    char **txt = backtrace_symbols(frames, count);
    loadtime = 0;
    if (txt) {
        long i;
        for (i = 0; txt[i] && !loadtime && i < count; i++) {
            //dev_post("---- parsing frame %ld: %s", i, txt[i]);
            if (strstr(txt[i], "lowload_type"))
                loadtime = true;
        }
    }
#endif
    if (loadtime) {
        defer_low(NULL, (method) loadtime_clear, NULL, 0, NULL);
    }
    return loadtime;
}

void loadtime_clear(void)
{
    loadtime = false;
}

#ifdef BACH_TRACK_MEMORY_ALLOCATION
t_memmap_item *memmap_item_new(void *address, size_t size, t_symbol *name)
{
    static t_int32_atomic count = 0;
    t_memmap_item *x = (t_memmap_item *) sysmem_newptrclear(sizeof (t_memmap_item));
    x->m_word.w_void = address;
    x->m_size = size;
    x->m_name = name;
    x->m_count = 1;
    x->m_order = ATOMIC_INCREMENT(&count);
#ifdef MAC_VERSION
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
    bach_save_stack(x->m_stack);
    /*
    void *backtraceFrames[16];
    int frameCount = backtrace(backtraceFrames, 16);
    char **frameStrings = backtrace_symbols(backtraceFrames, frameCount);
    
    if (frameStrings != NULL) {
        int i;
        for (i = 0; i < frameCount; i++) {
            if (frameStrings[i] == NULL) 
                break;
            x->m_stack[i].s_address = backtraceFrames[i];
            strncpy_zero(x->m_stack[i].s_string, frameStrings[i], 128);
            
        }
        free(frameStrings);
    }*/
#endif // BACH_SAVE_STACK_WITH_MEMORY_LOGS
#endif // MAC_VERSION
    return x;
}

void bach_save_stack(t_mframe *frame)
{
#ifdef MAC_VERSION
#ifdef BACH_SAVE_STACK_WITH_MEMORY_LOGS
    void *backtraceFrames[15];
    int frameCount = backtrace(backtraceFrames, 15);
    char **frameStrings = backtrace_symbols(backtraceFrames, frameCount);
    
    if (frameStrings != NULL) {
        int i;
        for (i = 3; i < frameCount; i++) {
            if (frameStrings[i] == NULL) 
                break;
            frame[i-3].s_address = backtraceFrames[i];
            strncpy_zero(frame[i-3].s_string, frameStrings[i], 128);
            
        }
        free(frameStrings);
    }
#endif // BACH_SAVE_STACK_WITH_MEMORY_LOGS
#endif // MAC_VERSION
}

size_t bach_adjust_ptr_size(size_t size)
{
    return ((size + (BACH_BLOAT_STEP - 1)) / BACH_BLOAT_STEP) * BACH_BLOAT_STEP;
}

t_max_err bach_bloat_ptr(void *ptr) {
    t_max_err err = MAX_ERR_NONE;
#ifdef BACH_BLOAT_FREED_MEMORY
    char *bloatme;
    t_memmap_item *mmi;
    if (memmap)
        err = hashtab_lookup(memmap, (t_symbol *) ptr, (t_object **) &mmi);
    if (!err && memmap && mmi->m_size > 0) {
        for (bloatme = (char *) ptr; bloatme + BACH_BLOAT_STEP <= (char *) ptr + mmi->m_size; bloatme += BACH_BLOAT_STEP) {
            sysmem_copyptr(BACH_MAGIC_BLOAT, bloatme, BACH_BLOAT_STEP);
        }
    }
#endif
    return err;
}

void *bach_newptr(size_t size)
{
#ifdef BACH_BLOAT_FREED_MEMORY
    size = bach_adjust_ptr_size(size);
#endif
    void *x = sysmem_newptr(size);
    if (!x) {
        if (size)
            bach_error_break("bach_newptr: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, size, NULL);
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (memmap && err)
            bach_error_break("bach_newptr: double allocation");
    }
    bach_bloat_ptr(x);
    return x;
}

void *bach_newptrclear(size_t size)
{
#ifdef BACH_BLOAT_FREED_MEMORY
    size = bach_adjust_ptr_size(size);
#endif
    void *x = sysmem_newptrclear(size);
    if (!x && size) {
        bach_error_break("bach_newptrclear: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, size, NULL);
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("bach_newptrclear: double allocation");
    }
    return x;
}

void *bach_newptr_named(size_t size, t_symbol *name)
{
#ifdef BACH_BLOAT_FREED_MEMORY
    size = bach_adjust_ptr_size(size);
#endif
    void *x = sysmem_newptr(size);
    if (!x) {
        bach_error_break("bach_newptr_named: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, size, name);
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("bach_newptr_named: double allocation");
    }
    return x;
}

void *bach_newptrclear_named(size_t size, t_symbol *name)
{
#ifdef BACH_BLOAT_FREED_MEMORY
    size = bach_adjust_ptr_size(size);
#endif
    void *x = sysmem_newptrclear(size);
    if (!x) {
        bach_error_break("bach_newptrclear_named: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, size, name);
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("bach_newptrclear_named: double allocation");
    }
    return x;
}

void bach_store_in_memmap(void *x)
{
    if (!memmap)
        return;
    size_t size = sysmem_ptrsize(x);
    t_memmap_item *mmi = memmap_item_new(x, size, NULL);
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (err)
        bach_error_break("bach_store_in_memmap: double allocation");
}

void bach_store_in_memmap_named(void *x, t_symbol *name)
{
    size_t size;
    if (!memmap)
        return;
    if (name == _llllobj_sym__llll)
        size = sizeof(t_llll);
    else if (name == _llllobj_sym__llllelem)
        size = sizeof(t_llllelem_numbered);
    else
        size = sysmem_ptrsize(x);
    t_memmap_item *mmi = memmap_item_new(x, size, name);
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (err)
        bach_error_break("bach_store_in_memmap_named: double allocation");
}

void *bach_resizeptr(void *ptr, size_t newsize)
{
    if (ptr) {
#ifdef BACH_BLOAT_FREED_MEMORY
        newsize = bach_adjust_ptr_size(newsize);
#endif
        void *x = sysmem_resizeptr(ptr, newsize);
        t_max_err err;
        t_memmap_item *mmi;
        if (memmap) {
            err = hashtab_lookup(memmap, (t_symbol *) ptr, (t_object **) &mmi);
            mmi->m_size = newsize;
            mmi->m_word.w_void = x;
            hashtab_chuckkey(memmap, (t_symbol *) ptr);
        }
        if (!x) {
            bach_error_break("bach_resizeptr: NULL pointer allocation");
            return NULL;
        }
        if (memmap) {
            err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
            if (err)
                bach_error_break("bach_resizeptr: double allocation");
        }
        return x;
    } else
        return bach_newptr(newsize);
}

void *bach_resizeptrclear(void *ptr, size_t newsize)
{
    if (ptr) {
        void *x = sysmem_resizeptrclear(ptr, newsize);
        t_max_err err;
        t_memmap_item *mmi;
        if (memmap) {
            err = hashtab_lookup(memmap, (t_symbol *) ptr, (t_object **) &mmi);
            mmi->m_size = newsize;
            mmi->m_word.w_void = x;
            hashtab_chuckkey(memmap, (t_symbol *) ptr);
        }
        if (!x) {
            bach_error_break("bach_resizeptrclear: NULL pointer allocation");
            return NULL;
        }
        if (memmap) {
            err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
            if (err)
                bach_error_break("bach_resizeptr: double allocation");
        }
        return x;
    } else
        return bach_newptr(newsize);
}

void bach_freeptr(void *ptr)
{
    t_max_err err;
    if (!ptr)
        return;
#ifdef BACH_BLOAT_FREED_MEMORY
    if (ptr == BACH_BLOATED_ADDR) {
        bach_error_break("bach_freeptr: freeing DEAD pointer - you should be incredibly lucky for this to be a false positive ;)");
        return;
    }
#endif
    bach_bloat_ptr(ptr);
    if (memmap) {
        err = hashtab_delete(memmap, (t_symbol *) ptr);
        if (err)
            bach_error_break("bach_freeptr: double free");
    }
    sysmem_freeptr(ptr);
}

void bach_remove_from_memmap(void *ptr)
{
    if (!memmap)
        return;
    if (!ptr)
        return;
    t_max_err err = hashtab_delete(memmap, (t_symbol *) ptr);
    if (err)
        bach_error_break("bach_remove_from_memmap: double free");
}

void *object_alloc_debug(t_class *c)
{
    void *x = object_alloc(c);
    if (!x) {
        bach_error_break("object_alloc_debug: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, c->c_size, c->c_sym);
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("object_alloc_debug: double allocation");
    }
    return x;
}

t_atomarray *atomarray_new_debug(long ac, t_atom *av)
{
    t_atomarray *x = atomarray_new(ac, av);
    if (!x) {
        bach_error_break("atomarray_new_debug: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, class_findbyname(CLASS_NOBOX, _sym_atomarray)->c_size, _sym_atomarray);
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("atomarray_new_debug: double allocation");
    }
    return x;
}

t_hashtab *hashtab_new_debug(long slotcount)
{
    t_hashtab *x = hashtab_new(slotcount);
    if (!x) {
        bach_error_break("hashtab_new_debug: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, class_findbyname(CLASS_NOBOX, gensym("hashtab"))->c_size, gensym("hashtab"));
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("hashtab_new_debug: double allocation");
    }
    return x;
}

t_linklist *linklist_new_debug(void)
{
    t_linklist *x = linklist_new();
    if (!x) {
        bach_error_break("linklist_new_debug: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, class_findbyname(CLASS_NOBOX, gensym("linklist"))->c_size, gensym("linklist"));
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("linklist_new_debug: double allocation");
    }
    return x;
}

t_dictionary *dictionary_new_debug(void)
{
    t_dictionary *x = dictionary_new();
    if (!x) {
        bach_error_break("dictionary_new_debug: NULL pointer allocation");
        return NULL;
    }
    if (memmap) {
        t_memmap_item *mmi = memmap_item_new(x, class_findbyname(CLASS_NOBOX, _sym_dictionary)->c_size, _sym_dictionary);
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
        if (err)
            bach_error_break("dictionary_new_debug: double allocation");
    }
    return x;
}

void *proxy_new_debug(void *o, long id, long *stuffloc)
{
    void *x = proxy_new(o, id, stuffloc);
    if (!x) {
        bach_error_break("proxy_new_debug: NULL pointer allocation");
        return NULL;
    }
    t_memmap_item *mmi = memmap_item_new(x, (size_t) -1, gensym("proxy"));
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (err)
        bach_error_break("proxy_new_debug: double allocation");
    return x;
}

void *object_new_typed_debug(t_symbol *objnamespace, t_symbol *classname, long ac, t_atom *av)
{
    void *x = object_new_typed(objnamespace, classname, ac, av);
    if (!x) {
        bach_error_break("object_new_typed_debug: NULL pointer allocation");
        return NULL;
    }
    t_memmap_item *mmi = memmap_item_new(x, class_findbyname(objnamespace, classname)->c_size, classname);
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (memmap && err)
        bach_error_break("object_new_typed_debug: double allocation");
    return x;
}

long systhread_mutex_new_debug(t_systhread_mutex *pmutex, long flags)
{
    t_max_err err = systhread_mutex_new(pmutex, flags);
    if (err)
        return err;
    t_memmap_item *mmi = memmap_item_new(*pmutex, (size_t) -1, gensym("systhread_mutex"));
    err = hashtab_store_safe(memmap, (t_symbol *) *pmutex, (t_object *) mmi);
    if (memmap && err)
        bach_error_break("systhread_mutex_new_debug: double allocation");
    return 0;
}

long systhread_mutex_free_debug(t_systhread_mutex pmutex)
{
    t_max_err err = systhread_mutex_free(pmutex);
    if (err)
        return err;
    err = hashtab_delete(memmap, (t_symbol *) pmutex);
    if (memmap && err)
        bach_error_break("systhread_mutex_free: double free");
    return 0;
}

void *clock_new_debug(void *obj, method fn)
{
    void *x = clock_new(obj, fn);
    if (!x) {
        bach_error_break("clock_new_debug: NULL pointer allocation");
        return NULL;
    }
    t_memmap_item *mmi = memmap_item_new(x, class_findbyname(CLASS_NOBOX, _sym_clock)->c_size, _sym_clock);
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (memmap && err)
        bach_error_break("clock_new_debug: double allocation");
    return x;
}

void *qelem_new_debug(void *obj, method fn)
{
    void *x = qelem_new(obj, fn);
    if (!x) {
        bach_error_break("qelem_new_debug: NULL pointer allocation");
        return NULL;
    }
    t_memmap_item *mmi = memmap_item_new(x, (size_t) -1, gensym("qelem"));
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (memmap && err)
        bach_error_break("qelem_new_debug: double allocation");
    return x;
}

void qelem_free_debug(void *obj)
{
    t_max_err err;
    qelem_free(obj);
    err = hashtab_delete(memmap, (t_symbol *) obj);
    if (memmap && err)
        bach_error_break("qelem_free_debug: double free");
}

char *charset_unicodetoutf8_debug(unsigned short *s, long len, long *outlen)
{
    t_memmap_item *mmi;
    char *x = charset_unicodetoutf8(s, len, outlen);
    if (!x) {
        bach_error_break("charset_unicodetoutf8_debug: NULL pointer allocation");
        return NULL;
    }
    mmi = memmap_item_new(x, *outlen + 1, gensym("utf8"));
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (memmap && err)
        bach_error_break("charset_unicodetoutf8_debug: double allocation");
    return x;
}

unsigned short *charset_utf8tounicode_debug(char *s, long *outlen)
{
    t_memmap_item *mmi;
    unsigned short *x = charset_utf8tounicode(s, outlen);
    if (!x) {
        bach_error_break("charset_utf8tounicode_debug: NULL pointer allocation");
        return NULL;
    }
    mmi = memmap_item_new(x, *outlen + 1, gensym("unicode"));
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (memmap && err)
        bach_error_break("charset_utf8tounicode_debug: double allocation");
    return x;
}

t_jfont    *jfont_create_debug(const char *family, t_jgraphics_font_slant slant, t_jgraphics_font_weight weight, double size)
{
    t_memmap_item *mmi;
    t_jfont *x = jfont_create(family, slant, weight, size);
    if (!x) {
        bach_error_break("jfont_create_debug: NULL pointer allocation");
        return NULL;
    }
    mmi = memmap_item_new(x, (size_t) -1, gensym("jfont"));
    t_max_err err = hashtab_store_safe(memmap, (t_symbol *) x, (t_object *) mmi);
    if (memmap && err)
        bach_error_break("jfont_create_debug: double allocation");
    return x;
}

void jfont_destroy_debug(t_jfont *font)
{
    t_max_err err;
    jfont_destroy(font);
    err = hashtab_delete(memmap, (t_symbol *) font);
    if (memmap && err)
        bach_error_break("jfont_destroy_debug: double free");
}

t_max_err atom_setparse_debug(long *ac, t_atom **av, C74_CONST char *parsestr)
{
    long newmem = (*ac == 0 && *av == NULL);
    t_max_err rtn_err = atom_setparse(ac, av, parsestr);
    if (rtn_err == MAX_ERR_NONE && newmem && *ac) {
        t_memmap_item *mmi = memmap_item_new(*av, *ac * sizeof(t_atom), gensym("atom"));
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) *av, (t_object *) mmi);
        if (memmap && err)
            bach_error_break("atom_setparse_debug: double allocation");
    }
    return rtn_err;
}

t_max_err atom_gettext_debug(long ac, t_atom *av, long *textsize, char **text, long flags)
{
    t_max_err rtn_err = atom_gettext(ac, av, textsize, text, flags);
    if (rtn_err == MAX_ERR_NONE) {
        t_memmap_item *mmi = memmap_item_new(*text, *textsize, gensym("text"));
        t_max_err err = hashtab_store_safe(memmap, (t_symbol *) *text, (t_object *) mmi);
        if (memmap && err)
            bach_error_break("atom_gettext_debug: double allocation");
    }
    return rtn_err;
}


void object_retain_debug(t_object *x)
{
    t_memmap_item *mmi;
    t_max_err err;
    if (!memmap)
        return;
    systhread_mutex_lock(memmap_lock);
    err = hashtab_lookup(memmap, (t_symbol *) x, (t_object **) &mmi);
    if (err)
        bach_error_break("object_retain_debug: missing object");
    else
        mmi->m_count++;
    systhread_mutex_unlock(memmap_lock);
    object_retain(x);
}

void object_free_debug(void *x)
{
    t_max_err err;
    t_memmap_item *mmi;
    if (!x)
        return;
    if (NOGOOD(x)) {
        bach_error_break("object_free_debug: bad object");
    }
    if (!memmap)
        return;
    systhread_mutex_lock(memmap_lock);
    err = hashtab_lookup(memmap, (t_symbol *) x, (t_object **) &mmi);
    if (err) {
        systhread_mutex_unlock(memmap_lock);
        bach_error_break("object_free_debug: double free");
        object_free(x);
        return;
    }
    if (mmi->m_count > 1) {
        mmi->m_count--;
        systhread_mutex_unlock(memmap_lock);
        object_release((t_object *) x);
    } else {
        systhread_mutex_unlock(memmap_lock);
        err = hashtab_delete(memmap, (t_symbol *) x);
        if (err)
            bach_error_break("object_free_debug: double free");
        object_free(x);
    }
}

void object_release_debug(void *x)
{
    object_free_debug(x);    
}

void bach_copyptr(const void *src, void *dst, long bytes)
{
    t_max_err err;
    t_memmap_item *mmi;
    if (!src || !dst) {
        bach_error_break("bach_copyptr: NULL pointer");
        return;
    }
    if (bytes == 0)
        return;
    if (memmap) {
        err = hashtab_lookup(memmap, (t_symbol *) dst, (t_object **) &mmi);
        if (err)
            bach_error_break("bach_copyptr: destination not allocated");
        else if (mmi->m_size < bytes)
            bach_error_break("bach_copyptr: insufficient destination size");
    }
    sysmem_copyptr(src, dst, bytes);
}

char *bach_strdup(const char *src)
{
    if (!src) {
        bach_error_break("bach_strdup: NULL pointer");
        return NULL;
    }
    long bytes = strlen(src);
    char *x = (char *) bach_newptr(bytes + 1);
    if (!x)
        return NULL;
    strncpy_zero(x, src, bytes);
    return x;
}

#endif // BACH_TRACK_MEMORY_ALLOCATION

// insert thing with the given key into tll
// the insertion is sorted key-wise
t_max_err tinyll_insert_sorted(t_tinyll *tll, void *thing, t_atom_ulong key)
{
    t_tinyllelem *el, *prev_el = NULL, *new_el;
    new_el = tinyllelem_new();
    new_el->t_key = key;
    new_el->t_thing = (t_llll *) thing;
    bach_atomic_lock(&tll->t_lock);
//    systhread_mutex_lock(tll->t_lock);
    if ((el = tll->t_head)) {
        for ( ; el && el->t_key < key; el = el->t_next)
            prev_el = el;
        if (el && el->t_key == key) { // if the list has already been inserted
            bach_atomic_unlock(&tll->t_lock);
            return MAX_ERR_GENERIC;
        }
        new_el->t_next = el;
        if (prev_el)
            prev_el->t_next = new_el;
        else
            tll->t_head = new_el;
    } else {
        tll->t_head = new_el;
    }
    bach_atomic_unlock(&tll->t_lock);
//    systhread_mutex_unlock(tll->t_lock);
    return MAX_ERR_NONE;
}

// removes an element from tll
void tinyll_chuck_key(t_tinyll *tll, t_atom_ulong key)
{
    t_tinyllelem *el, *prev_el = NULL;
    
    bach_atomic_lock(&tll->t_lock);

    for (el = tll->t_head; el && el->t_key != key; el = el->t_next)
        prev_el = el;
    
    if (!el) {
        bach_atomic_unlock(&tll->t_lock);
        return;
    }
    
    if (prev_el)
        prev_el->t_next = el->t_next;
    else
        tll->t_head = el->t_next;
    
    bach_freeptr(el);
    bach_atomic_unlock(&tll->t_lock);
}

// tinyllelem constructor
t_tinyllelem *tinyllelem_new(void) 
{
    return (t_tinyllelem *) bach_newptrclear(sizeof(t_tinyllelem));
}

void bach_breakpoint(long test)
{
#ifdef MAC_VERSION
#ifdef BACH_ENABLE_BREAKPOINTS
    if (!test)
        Debugger();
#endif
#endif
}

void bach_fill_2n_array(void *model, void *dst, size_t src_size, long dst_items)
{
    size_t curr_size, dst_size;
    sysmem_copyptr(model, dst, src_size);
    
    dst_size = src_size * dst_items;
    for (curr_size = src_size; curr_size < dst_size; curr_size *= 2) {
        sysmem_copyptr((t_uint8 *) dst, ((t_uint8 *) dst) + curr_size, curr_size);
    }
}

void bach_error_break(const char *txt)
{
    object_bug((t_object *) bach, txt);
    bach_breakpoint(0);
}

void bach_object_warn_break(t_object *x, const char *txt)
{
    object_warn(x, txt);
    bach_breakpoint(0);
}

