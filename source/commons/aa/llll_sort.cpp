/*
 * llll_sort.cpp
 *
 * This file is copyright 2001 Simon Tatham and copyright 2019 Andrea Agostini.
 *
 * This file has been modified from the original
 * for making it compatible with the bach library code.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL SIMON TATHAM BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */


#include <llll_commons.h>


void llll_mergesort(t_llll *in, t_llll **out, sort_fn cmpfn, void *data)
{
    t_llll *out_ll;
    t_atom_long chunksize, merges, asize, bsize, i;
    t_llllelem *a, *b;
    
    if (!in)
        return;
    
    for (a = in->l_head; a; a = a->l_next)
        a->l_flags = OBJ_FLAG_DATA;
    
    if (in->l_size <= 1) {
        *out = in;
        return;
    }
    
    chunksize = 1;
    do {
        *out = llll_get();
        out_ll = *out;
        merges = 0;
        a = b = in->l_head;
        
        while (a) {
            merges ++;
            asize = 0;
            
            for (i = 0; i < chunksize && b; i++) {
                b = b->l_next;
                asize++;
            }
            
            bsize = asize;
            
            while (asize != 0 || (b && bsize != 0)) {
                if (asize == 0) { // it is important that this chain of if ... else is in this order!
                    llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    b = b->l_next;
                    bsize--;
                } else if (bsize == 0 || !b) {
                    llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    a = a->l_next;
                    asize--;
                } else if ((*cmpfn)(data, a, b)) {
                    llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    a = a->l_next;
                    asize--;
                } else {
                    llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    b = b->l_next;
                    bsize--;
                }
            }
            a = b;
        }
        
        llll_free_nocheck(in); // depth is broken
        in = out_ll;
        chunksize *= 2;
        
    } while (merges > 1);
    
    for (a = out_ll->l_head; a; a = a->l_next)
        a->l_flags = 0;
    
    llll_adopt(out_ll, out_ll);
    pedantic_llll_check(out_ll);
}

void llll_mergesort_with_lthings(t_llll *in, t_llll **out, sort_fn cmpfn, void *data)
{
    t_llll *out_ll;
    t_atom_long chunksize, merges, asize, bsize, i;
    t_llllelem *a, *b, *n;
    
    if (!in)
        return;
    
    for (a = in->l_head; a; a = a->l_next)
        a->l_flags = OBJ_FLAG_DATA;
    
    if (in->l_size <= 1) {
        *out = in;
        return;
    }
    
    chunksize = 1;
    do {
        *out = llll_get();
        out_ll = *out;
        merges = 0;
        a = b = in->l_head;
        
        while (a) {
            merges ++;
            asize = 0;
            
            for (i = 0; i < chunksize && b; i++) {
                b = b->l_next;
                asize++;
            }
            
            bsize = asize;
            
            while (asize != 0 || (b && bsize != 0)) {
                if (asize == 0) { // it is important that this chain of if ... else is in this order!
                    n = llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    n->l_thing.w_whole = b->l_thing.w_whole;
                    b = b->l_next;
                    bsize--;
                } else if (bsize == 0 || !b) {
                    n = llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    n->l_thing.w_whole = a->l_thing.w_whole;
                    a = a->l_next;
                    asize--;
                } else if ((*cmpfn)(data, a, b)) {
                    n = llll_appendhatom(out_ll, &a->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    n->l_thing.w_whole = a->l_thing.w_whole;
                    a = a->l_next;
                    asize--;
                } else {
                    n = llll_appendhatom(out_ll, &b->l_hatom, OBJ_FLAG_DATA, WHITENULL_llll);
                    n->l_thing.w_whole = b->l_thing.w_whole;
                    b = b->l_next;
                    bsize--;
                }
            }
            a = b;
        }
        
        llll_free_nocheck(in); // depth is broken
        in = out_ll;
        chunksize *= 2;
        
    } while (merges > 1);
    
    for (a = out_ll->l_head; a; a = a->l_next)
        a->l_flags = 0;
    
    llll_adopt(out_ll, out_ll);
    pedantic_llll_check(out_ll);
}




#ifdef ___destructive
void llll_inplacesort(t_llll *ll, sort_fn cmpfn, void *data)
{
    t_atom_long chunksize, merges, asize, bsize, i;
    t_llllelem *a, *b;
    
    if (!ll)
        return;
    /*
     for (a = in->l_head; a; a = a->l_next)
     a->l_flags = OBJ_FLAG_DATA;*/
    
    if (ll->l_size <= 1) {
        return;
    }
    
    chunksize = 1;
    do {
        merges = 0;
        a = b = ll->l_head;
        
        while (a) {
            merges ++;
            asize = 0;
            
            for (i = 0; i < chunksize && b; i++) {
                b = b->l_next;
                asize++;
            }
            
            bsize = asize;
            
            while (asize != 0 || (b && bsize != 0)) {
                if (asize == 0) { // don't move
                                  //t_llllelem *b_next = b->l_next;
                                  //llll_inplacesort_move_elem(ll, a, b);
                    b = b->l_next;
                    bsize--;
                } else if (bsize == 0 || !b) { // don't move
                    a = a->l_next;
                    asize--;
                } else if ((*cmpfn)(data, a, b)) { // don't move
                    a = a->l_next;
                    asize--;
                } else { // move
                    t_llllelem *b_next = b->l_next;
                    //post("placing %ld before %ld", hatom_getlong(&a->l_hatom), hatom_getlong(&b->l_hatom));
                    llll_inplacesort_move_elem(ll, a, b);
                    b = b_next;
                    bsize--;
                }
            }
            a = b;
            //llll_print(ll, NULL, 0, 0, NULL);
        }
        
        //llll_free_nocheck(in); // depth is broken
        //in = out_ll;
        chunksize *= 2;
        
    } while (merges > 1);
    //pedantic_llll_check(ll);
    
    //    for (a = out_ll->l_head; a; a = a->l_next)
    //        a->l_flags = 0;
    
    //    llll_adopt(out_ll, out_ll);
}
#else

/*
 this is a "fake" inplace sort. don't use it unless you really have to.
 it is slower, and uses more memory, than llll_mergesort
 moreover, you can't pass data to cmpfn
 */
void llll_inplacesort(t_llll *ll, sort_fn cmpfn, void *data)
{
    t_llll *in;
    t_llll *out;
    t_llllelem *el;
    
    if (!ll || ll->l_size < 2)
        return;
    
    in = llll_get();
    
    for (el = ll->l_head; el; el = el->l_next)
        llll_appendobj(in, el, 0, WHITENULL_llll);
    
    llll_mergesort(in, &out, (sort_fn) llll_objcmpfn, (void *) cmpfn);
    
    ll->l_size = 0;
    ll->l_depth = 1;
    ll->l_head = ll->l_tail = NULL;
    
    for (el = out->l_head; el; el = el->l_next)
        llll_append(ll, (t_llllelem *) el->l_hatom.h_w.w_obj, WHITENULL_llll);
    
    llll_free(out);
    pedantic_llll_check(ll);
}
#endif


// move b before a; both must be elements of ll, and a must actually precede b - and subsequently b must not be ll's head
void llll_inplacesort_move_elem(t_llll *ll, t_llllelem *a, t_llllelem *b)
{
    if (a->l_next == b) {
        if (a->l_prev) {
            a->l_prev->l_next = b;
            b->l_prev = a->l_prev;
        } else {
            ll->l_head = b;
            b->l_prev = NULL;
        }
        if (b->l_next) {
            b->l_next->l_prev = a;
            a->l_next = b->l_next;
        } else {
            ll->l_tail = a;
            a->l_next = NULL;
        }
        b->l_next = a;
        a->l_prev = b;
        //if (llll_check(ll))
        //    post("bah");
    } else {
        if (b->l_next) {
            b->l_prev->l_next = b->l_next;
            b->l_next->l_prev = b->l_prev;
        } else {
            ll->l_tail = b->l_prev;
            b->l_prev->l_next = NULL;
        }
        if (a->l_prev) {
            a->l_prev->l_next = b;
            b->l_prev = a->l_prev;
        } else {
            ll->l_head = b;
            b->l_prev = NULL;
        }
        a->l_prev = b;
        b->l_next = a;
        //if (llll_check(ll))
        //    post("boh");
    }
}
