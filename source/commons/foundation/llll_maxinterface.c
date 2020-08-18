/*
 *  llll_maxinterface.c
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


#include "foundation/llll_commons.h"
#include "ext_strings.h"
#include "ext_critical.h"
#include "ext_common.h"
#include "foundation/bach_threads.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// client is the object that will be highlighted when you click the max window
// name is the object that will appear in the "object" column of the max window
void llll_post(t_llll *ll, t_int32 mindepth, t_int32 maxdepth, t_atom_long max_decimals, t_object *client, text_buf_fn fn)
{
    t_atom_long i;
    char header[256], *postline;
    t_llllelem *this_elem;
    t_llll *sub_ll = NULL, *saved = NULL;
    t_llll_stack *stack;
    t_atom_long depth = 1;
    long deepenough;
    char *txt = NULL, *pos;
    
    if (!ll)
        return;
    
    if (mindepth == 0)
        mindepth = 1;
    if (maxdepth == 0)
        maxdepth = -1;
    
    if (mindepth > ll->l_depth || maxdepth < -ll->l_depth - 1)
        return;
    
    deepenough = (mindepth == 1 || ll->l_depth < -mindepth);
    stack = llll_stack_new();

    if (ll->l_depth == -maxdepth - 1) {
        saved = ll;
        ll = llll_get();
        ll->l_flags = OBJ_FLAG_DATA;
        llll_appendllll(ll, saved, 0, WHITENULL_llll);
        depth = 0;
    }

    
    if (fn) {
        t_hatom h;
        hatom_setllll(&h, ll);
        txt = (fn)(&h, max_decimals);
        if (client)
            object_post(client, "  0: " LLLL_PUSH_CSTR " %s", txt);
        else
            post("  0: " LLLL_PUSH_CSTR " %s", txt);
        bach_freeptr(txt);
    }
    
    this_elem = ll->l_head;
    postline = (char *) bach_newptr(256);
    
    while (1) {
        snprintf_zero(header, 256, "%3" ATOM_LONG_FMT_MODIFIER "d: ", depth);
        for (i = 0; i < depth; i++)
            strncat_zero(header, "•", 256);
        while (this_elem) {
            *postline = 0;

            if (deepenough && fn) {
                txt = (fn)(&this_elem->l_hatom, max_decimals);
                if (txt) {
                    snprintf_zero(postline, 256, "%s %s", header, txt);    
                    bach_freeptr(txt);
                }
            }
            if (!txt && deepenough) {
                switch(this_elem->l_hatom.h_type) {
                    case H_LONG:
                        snprintf_zero(postline, 256, "%s " ATOM_LONG_PRINTF_FMT, header, this_elem->l_hatom.h_w.w_long);
                        break;
                    case H_DOUBLE:
                        pos = postline + snprintf_zero(postline, 256, "%s %.*f", header, max_decimals, this_elem->l_hatom.h_w.w_double) - 1;                            
                        // remove trailing zeros
                        while (*pos == '0') {
                            pos--;
                        }
                        *(pos + 1) = 0;
                        break;
                    case H_SYM:
                        snprintf_zero(postline, 256, "%s %s", header, this_elem->l_hatom.h_w.w_sym->s_name);
                        break;
                    case H_RAT:
                        snprintf_zero(postline, 256, "%s " ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT, header, this_elem->l_hatom.h_w.w_rat.r_num, this_elem->l_hatom.h_w.w_rat.r_den);
                        break;
                    case H_PITCH: {
                        char txt[256];
                        this_elem->l_hatom.h_w.w_pitch.toTextBuf(txt, 256);
                        snprintf_zero(postline, 256, "%s %s", header, txt);
                        break;
                    }
                    case H_LLLL:
                        break;
                    case H_FUNCTION:
                        snprintf_zero(postline, 256, "%s <function %p>", header, this_elem->l_hatom.h_w.w_obj);
                        break;
                    case H_OBJ:
                        snprintf_zero(postline, 256, "%s <object %p>", header, this_elem->l_hatom.h_w.w_obj);
                        break;
                    default:
                        snprintf_zero(postline, 256, "%s ###UNKNOWN###", header, sub_ll);
                }
            }
            if (this_elem->l_hatom.h_type == H_LLLL) {    
                sub_ll = hatom_getllll(&(this_elem->l_hatom));
                if (sub_ll == NULL) {
                    if (!txt)
                        snprintf_zero(postline, 256, "%s ###NULL###", header);
                    this_elem = this_elem->l_next;
                } else {
                    if (depth > 0 && (depth < maxdepth || (maxdepth < 0 && sub_ll->l_depth >= -maxdepth))) { // if we are within maxdepth
                        snprintf_zero(postline, 256, "%s " LLLL_PUSH_CSTR " ", header);
                        if (txt)
                            strncat_zero(postline, txt, 256);
                        llll_stack_push(stack, this_elem);
                        this_elem = this_elem->l_hatom.h_w.w_llll->l_head;
                        depth++;
                        deepenough = (mindepth > 0 && depth >= mindepth) || sub_ll->l_depth <= -mindepth;
                        snprintf_zero(header, 256, "%3" ATOM_LONG_FMT_MODIFIER "d: ", depth);
                        for (i = 0; i < depth; i++)
                            strncat_zero(header, "•", 256);
                    } else {
                        if (deepenough) {
                            snprintf_zero(postline, 256, "%s " LLLL_PUSH_CSTR " ", header);
                            llll_to_text_buf(sub_ll, &postline, strlen(postline), max_decimals, 0, 0, 0, fn);
                            snprintf_zero(postline, sysmem_ptrsize(postline), "%s " LLLL_POP_CSTR, postline);
                        }
                        this_elem = this_elem->l_next;
                    }
                }
            } else
                this_elem = this_elem->l_next;
            if (*postline && deepenough) {
                if (client)
                    object_post((t_object *) client, postline);
                else 
                    post(postline);
            }
        }
        if (depth <= 1)
            break;
        
        if (deepenough) {
            if (client)
                object_post((t_object *) client, "%s " LLLL_POP_CSTR, header);
            else 
                post("%s " LLLL_POP_CSTR, header);
        }
        
        depth--;
        this_elem = (t_llllelem *) llll_stack_pop(stack);
        deepenough = (mindepth > 0 && depth >= mindepth) || (this_elem->l_parent->l_depth <= -mindepth);
        this_elem = this_elem->l_next;
        snprintf_zero(header, 256, "%3" ATOM_LONG_FMT_MODIFIER "d: ", depth);
    }
    bach_freeptr(postline);
    if (saved)
        llll_free(ll);
    llll_stack_destroy(stack);
}

void llll_post_named(t_llll *ll, t_int32 mindepth, t_int32 maxdepth, t_atom_long max_decimals, t_symbol *name, text_buf_fn fn)
{
    t_atom atoms[5];
    atom_setobj(atoms, (void *) ll);
    atom_setlong(atoms + 1, mindepth);
    atom_setlong(atoms + 2, maxdepth);
    atom_setlong(atoms + 3, max_decimals);
    atom_setobj(atoms + 4, (void *) fn);
    
    defer(bach, (method) llll_post_named_do, name, 4, atoms);
}

// never call this from the scheduler thread!
void llll_post_named_do(void *dummy, t_symbol *name, long ac, t_atom *av)
{
    t_atom printname;
    t_object *printobj;
    t_llll *ll = (t_llll *) atom_getobj(av++);
    t_int32 mindepth = atom_getlong(av++);
    t_int32 maxdepth = atom_getlong(av++);
    t_atom_long max_decimals = atom_getlong(av++);
    text_buf_fn fn = (text_buf_fn) atom_getobj(av);
    atom_setsym(&printname, name);
    
    printobj = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, name != NULL , &printname);
    if (!printobj) {
        printobj = (t_object *) newinstance(_sym_print, 0, NULL);
        defer_low(printobj, (method) llll_printobject_free, NULL, 0, NULL);
        printobj = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, name != NULL, &printname);
    }
    llll_post(ll, mindepth, maxdepth, max_decimals, printobj, fn);
    
    defer_low(printobj, (method) llll_printobject_free, NULL, 0, NULL);
}

void llll_printobject_free(t_object *printobj, t_symbol *name, long ac, t_atom *av)
{
    object_free_debug(printobj);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void llll_print(t_llll *ll, t_object *client, long error_message_type, t_atom_long max_decimals, text_buf_fn fn)
{
    //    char *buf;
    char *buf = NULL;
    
    if (!ll)
        return;
    
    llll_to_text_buf(ll, &buf, 0, max_decimals, LLLL_T_NULL, 0, 0, fn);
    if (client) {
        switch (error_message_type) {
            case 1:
                object_error(client, "%s", buf);
                break;
            case 2:
                object_warn(client, "%s", buf);
                break;
            default:
                object_post(client, "%s", buf);
                break;
        }
    } else
        post("%s", buf);
    bach_freeptr(buf);    
}

void llll_print_named(t_llll *ll, t_symbol *name, long error_message_type, t_atom_long max_decimals, text_buf_fn fn)
{
    t_atom atoms[4];
    atom_setobj(atoms, ll);
    atom_setlong(atoms + 1, error_message_type);
    atom_setlong(atoms + 2, max_decimals);
    atom_setobj(atoms + 3, (void *) fn);
    defer(bach, (method) llll_print_named_do, name, 3, atoms);
}

// never call this from the scheduler thread!
void llll_print_named_do(void *dummy, t_symbol *name, long ac, t_atom *av)
{
    t_atom printname;
    t_object *printobj;
    t_llll *ll = (t_llll *) atom_getobj(av++);
    long error_message_type = atom_getlong(av++);
    t_atom_long max_decimals = atom_getlong(av++);
    text_buf_fn fn = (text_buf_fn) atom_getobj(av);
    atom_setsym(&printname, name);
    printobj = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, name != NULL, &printname);
    if (!printobj) {
        printobj = (t_object *) newinstance(_sym_print, 0, NULL);
        defer_low(printobj, (method) llll_printobject_free, NULL, 0, NULL);
        printobj = (t_object *) object_new_typed_debug(CLASS_BOX, _sym_print, name != NULL, &printname);
    }
    llll_print(ll, printobj, error_message_type, max_decimals, fn);
    defer_low(printobj, (method) llll_printobject_free, NULL, 0, NULL);
}

void llll_text2atoms(char *text, long *ac, t_atom **av)
{
    char outstr[256];
    long index = 0;
    long textlen = strlen(text);
    *av = (t_atom *) bach_newptr(ATOM_LIST_LENGTH_STEP * sizeof(t_atom));
    *ac = 0;
    
    while (readatom(outstr, &text, &index, textlen, *av + *ac)) {
        (*ac)++;
        if (*ac % ATOM_LIST_LENGTH_STEP == 0)
            *av = (t_atom *) bach_resizeptr(*av, (*ac + ATOM_LIST_LENGTH_STEP) * sizeof(t_atom));
    }
}

// used by bach.sort and bach.msort
// formats a llll before the sorting algorithm for outputting its elements one by one
void llll_prepare_sort_data(t_object *x, t_llll *ll, t_llll *by, long outtypes)
{
    t_llllelem *elem;
    t_llll_sort_item *sort_item;
    t_llll *wrapped;
    t_atom *atoms;
    t_atom_long count;
    if (!ll)
        return;
    for (elem = ll->l_head, count = LLLL_IDX_BASE; elem; elem = elem->l_next, count++) {
        sort_item = (t_llll_sort_item *) bach_newptrclear(sizeof(t_llll_sort_item));
        wrapped = llll_get(); // will be destroyed in llll_retrieve_sort_data
        llll_appendhatom_clone(wrapped, &elem->l_hatom, 0, WHITENULL_llll);
        if (by && by->l_size > 0) {
            if (wrapped->l_depth > 1) {
                t_llll *elem_ll = elem->l_hatom.h_w.w_llll;
                t_llllelem **elem_arr = llll_find_multiple_elems(elem_ll, by, false, false, false);
                t_llll *this_by_ll = llll_get();
                long i;
                for (i = 0; i < by->l_size; i++)
                    llll_appendhatom_clone(this_by_ll, &elem_arr[i]->l_hatom, 0, WHITENULL_llll);
                bach_freeptr(elem_arr);
                sort_item->n_this_by = this_by_ll;
            } else
                sort_item->n_this_by = llll_get();
            llll_free(wrapped);
        } else
            sort_item->n_this_by = wrapped;
        
        if (outtypes & LLLL_O_TEXT) {
            atoms = NULL;
            sort_item->n_t_ac = llll_deparse(sort_item->n_this_by, &atoms, 0, LLLL_D_QUOTE | LLLL_D_MAX);
            sort_item->n_t_freeme = atoms = (t_atom *) bach_resizeptr(atoms, sort_item->n_t_ac * sizeof(t_atom));
            switch (atoms->a_type) {
                case A_FLOAT:
                    if (sort_item->n_t_ac > 1)
                        sort_item->n_t_sym = _sym_list;
                    else 
                        sort_item->n_t_sym = _sym_float;
                    sort_item->n_t_av = atoms;
                    break;
                case A_LONG:
                    if (sort_item->n_t_ac > 1) 
                        sort_item->n_t_sym = _sym_list;
                    else
                        sort_item->n_t_sym = _sym_int;
                    sort_item->n_t_av = atoms;
                    break;
                case A_SYM:
                    sort_item->n_t_sym = atoms->a_w.w_sym;
                    sort_item->n_t_ac--;
                    sort_item->n_t_av = atoms + 1;
                    break;
                default:
                    break;
            }
        }
        
        if (outtypes & LLLL_O_MAX) {
            atoms = NULL;
            sort_item->n_m_ac = llll_deparse(sort_item->n_this_by, &atoms, 0, LLLL_D_MAX);
            sort_item->n_m_freeme = atoms = (t_atom *) bach_resizeptr(atoms, sort_item->n_m_ac * sizeof(t_atom));
            switch (atoms->a_type) {
                case A_FLOAT:
                    if (sort_item->n_m_ac > 1)
                        sort_item->n_m_sym = _sym_list;
                    else
                        sort_item->n_m_sym = _sym_float;
                    sort_item->n_m_av = atoms;
                    break;
                case A_LONG:
                    if (sort_item->n_m_ac > 1)
                        sort_item->n_m_sym = _sym_list;
                    else
                        sort_item->n_m_sym = _sym_int;
                    sort_item->n_m_av = atoms;
                    break;
                case A_SYM:
                    sort_item->n_m_sym = atoms->a_w.w_sym;
                    sort_item->n_m_ac--;
                    sort_item->n_m_av = atoms + 1;
                    break;
                default:
                    break;
            }
        }
        
        if (outtypes & LLLL_O_NATIVE) {
            sort_item->n_n_sym = LLLL_NATIVE_MSG;
            sort_item->n_n_av = (t_atom *) bach_newptr(sizeof(t_atom));
            atom_setlong(sort_item->n_n_av, llll_phonenumber(sort_item->n_this_by));
        }
        
        sort_item->n_idx = count;
        sort_item->n_term = elem->l_hatom;
        hatom_setobj(&elem->l_hatom, (t_object *) sort_item);
    }
}

// used by bach.sort and bach.msort
// to be called after llll_mergesort to discard the formatting imposed by llll_prepare_sort_data
void llll_retrieve_sort_data(t_object *x, t_llll *ll, t_llll *idx_ll, t_atom_long depth)
{
    t_llllelem *elem;
    t_llll_sort_item *item;
    t_hatom orig_hatom;
    if (!x || !idx_ll)
        return;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        item = (t_llll_sort_item *) elem->l_hatom.h_w.w_obj;
        llll_appendlong(idx_ll, item->n_idx, 0, WHITENULL_llll);
        llll_free(item->n_this_by);
        if (item->n_n_av)
            bach_freeptr(item->n_n_av);
        if (item->n_t_av)
            bach_freeptr(item->n_t_freeme); // the t_atom* we originally allocated in llll_prepare_sort_data
        if (item->n_m_av)
            bach_freeptr(item->n_m_freeme); // the t_atom* we originally allocated in llll_prepare_sort_data

        orig_hatom = item->n_term;
        bach_freeptr(item);
        if (orig_hatom.h_type == H_LLLL)
            orig_hatom.h_w.w_llll->l_owner = elem;
        elem->l_hatom = orig_hatom;
    }
    ll->l_depth = depth;
}

t_shashtable *shashtable_new(long reentrant)
{
    long i;
    t_shashtable *x = (t_shashtable *) bach_newptr_named(sizeof(t_shashtable), gensym("shashtable"));
    x->s_lastused = 0;
    for (i = 0; i < BACH_SHASHTABLE_SLOTS; i++)
        x->s_idx2ptr[i] = (t_simpll *) bach_newptrclear_named(sizeof(t_simpll), gensym("simpll"));
//    if (reentrant)
//        systhread_mutex_new_debug(&x->s_mutex, 0);
    return x;
}

void shashtable_free(t_shashtable *x)
{
    t_simpll **this_idx2ptr, **idx2ptr;
    t_simpllelem *el, *next_el;
    idx2ptr = x->s_idx2ptr;
    for (this_idx2ptr = idx2ptr + BACH_SHASHTABLE_SLOTS - 1; this_idx2ptr >= idx2ptr; this_idx2ptr--) {
        for (el = (*this_idx2ptr)->s_head; el; el = next_el) {
            next_el = el->s_next;
            bach_freeptr(el);
        }
//        if ((*this_idx2ptr)->s_lock)
//            systhread_mutex_free_debug((*this_idx2ptr)->s_lock);
        bach_freeptr(*this_idx2ptr);
    }
    bach_freeptr(x);
}

// insert a thing in the shashtable, and return its key
t_atom_ulong shashtable_insert(t_shashtable *x, void *thing) 
{
    t_atom_ulong slot;
    t_simpll *sll;
    unsigned long newitem;
    newitem = ATOMIC_INCREMENT_ATOM(&x->s_lastused);
    slot = newitem % BACH_SHASHTABLE_SLOTS;
    sll = x->s_idx2ptr[slot];
    simpll_insert_sorted(sll, thing, newitem);
    return newitem;
}

void *shashtable_insert_with_key(t_shashtable *x, void *thing, t_atom_ulong key, long force)
{
    t_atom_ulong slot;
    void *former = NULL;
    t_simpll *sll;
    t_simpllelem *el, *prev_el = NULL, *new_el;
    slot = key % BACH_SHASHTABLE_SLOTS;
    sll = x->s_idx2ptr[slot];
    bach_atomic_lock(&sll->s_lock);
    
    if ((el = sll->s_head) != NULL) { // if sll->t_head != NULL
        for ( ; el && el->s_key < key; el = el->s_next)
            prev_el = el;
        if (el && el->s_key == key) {
            former = el->s_thing;
            if (force)
                el->s_thing = thing;
        } else {
            new_el = (t_simpllelem *) bach_newptr_named(sizeof(t_simpllelem), gensym("simpllelem"));
            new_el->s_next = el;
            new_el->s_thing = thing;
            new_el->s_key = key;
            if (prev_el)
                prev_el->s_next = new_el;
            else
                sll->s_head = new_el;
        }
    } else {
        new_el = (t_simpllelem *) bach_newptr_named(sizeof(t_simpllelem), gensym("simpllelem"));
        sll->s_head = new_el;
        new_el->s_key = key;
        new_el->s_thing = thing;
        new_el->s_next = NULL;
    }
    bach_atomic_unlock(&sll->s_lock);
    return former;
}


// retrieve a thing from the shashtable
void *shashtable_retrieve(t_shashtable *x, t_atom_ulong key)
{
    t_atom_ulong slot = key % BACH_SHASHTABLE_SLOTS;
    t_simpll *sll = x->s_idx2ptr[slot];
    t_simpllelem *el;
    void *thing = NULL;
    bach_atomic_lock(&sll->s_lock);
    for (el = sll->s_head; el && el->s_key < key; el = el->s_next)
        ;
    
    if (el && el->s_key == key)
        thing = el->s_thing;    
    bach_atomic_unlock(&sll->s_lock);
    return thing;
}

// remove a thing from the shashtable
// this will not free the thing, of course!
void shashtable_chuck_thing(t_shashtable *x, t_atom_ulong key)
{
    long slot = key % BACH_SHASHTABLE_SLOTS;
    simpll_chuck_key(x->s_idx2ptr[slot], key);
    return;
}

void shashtable_reset_keys(t_shashtable *x)
{
    x->s_lastused = 0;
}

// insert thing with the given key into sll
// the insertion is sorted key-wise
void simpll_insert_sorted(t_simpll *sll, void *thing, t_atom_ulong key)
{
    t_simpllelem *el, *prev_el = NULL, *new_el;
    new_el = (t_simpllelem *) bach_newptr_named(sizeof(t_simpllelem), gensym("simpllelem"));
    new_el->s_key = key;
    new_el->s_thing = thing;
    bach_atomic_lock(&sll->s_lock);
    if ((el = sll->s_head)) { // if sll->t_head != NULL
        for ( ; el && el->s_key < key; el = el->s_next)
            prev_el = el;
        new_el->s_next = el;
        if (prev_el)
            prev_el->s_next = new_el;
        else
            sll->s_head = new_el;
    } else {
        new_el->s_next = NULL;
        sll->s_head = new_el;
    }
    bach_atomic_unlock(&sll->s_lock);
}

// removes an element from sll
void simpll_chuck_key(t_simpll *sll, t_atom_ulong key)
{
    t_simpllelem *el, *prev_el = NULL;
    bach_atomic_lock(&sll->s_lock);
    for (el = sll->s_head; el && el->s_key != key; el = el->s_next)
        prev_el = el;
    
    if (!el) {
        bach_atomic_unlock(&sll->s_lock);
        return;
    }
    if (prev_el)
        prev_el->s_next = el->s_next;
    else
        sll->s_head = el->s_next;
    bach_atomic_unlock(&sll->s_lock);
    bach_freeptr(el);
}


void llll_posthatom(t_hatom *hatom)
{
    t_atom newatom;
    t_atom *newatom_ptr = &newatom;
    char rat_txt[256];
    switch (hatom->h_type) {
        case H_LONG:
            atom_setlong(newatom_ptr, hatom->h_w.w_long);
            break;
        case H_DOUBLE:
            atom_setfloat(newatom_ptr, hatom->h_w.w_double);
            break;
        case H_SYM:
            atom_setsym(newatom_ptr, hatom->h_w.w_sym);
            break;
        case H_RAT:
            snprintf_zero(rat_txt, 256, ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT, hatom->h_w.w_rat.r_num, hatom->h_w.w_rat.r_den);
            atom_setsym(newatom_ptr, gensym(rat_txt));
            break;
        case H_PITCH:
            atom_setsym(newatom_ptr, hatom->h_w.w_pitch.toSym());
        default:
            break;
    }
    postatom(newatom_ptr);
}


void dev_llll_send(t_llll *x, const char* receiver)
{
#ifdef CONFIGURATION_Development
    t_symbol *s = gensym(receiver);
    if (!s->s_thing)
        return;
    t_object *o = s->s_thing;
    t_atom a;
    atom_setlong(&a, x->l_phonenumber);
    object_method_typed(o, LLLL_NATIVE_MSG, 1, &a, NULL);
#endif
}
