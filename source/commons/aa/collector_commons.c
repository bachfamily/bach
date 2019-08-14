/*
 *  collector_commons.c
 *  bach-fw
 *
 *  Created by andrea agostini on 23/2/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifdef BACH_MAX
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#endif

#include "llll_commons.h"
#include "bach_threads.h"
#include "collector.h"


t_collector *collector_new(t_atom_long stacks, long reentrant)
{
	t_collector *x;

	x = collector_alloc();
	x->c_reentrant = reentrant;
	
	
	collector_size(x, stacks);
	
	return x;
}

t_collector *collector_alloc(void)
{
	t_collector *x = (t_collector *) bach_newptrclear(sizeof(t_collector));
	x->c_magic = BACH_MAGIC_GOOD;
	x->c_count = 1;
	return x;
}

void collector_retain(t_collector *x)
{
	ATOMIC_INCREMENT(&x->c_count);
}

void collector_release(t_collector *x)
{
	collector_free(x);
}

void collector_free(t_collector *x)
{
	t_atom_long i;
	t_llll_stack **this_stack;
	if (ATOMIC_DECREMENT(&x->c_count) != 0)
		return;
	x->c_magic = BACH_MAGIC_BAD;
	for (i = 0, this_stack = x->c_stack; i < x->c_stacknum; i++, this_stack++) {
		if ((*this_stack)->s_items)
			llll_free((t_llll *) (*this_stack)->s_stack[0]);
		llll_stack_destroy(*this_stack);
	}
	bach_freeptr(x->c_stack);
	bach_freeptr(x);
}

// ---DESTRUCTIVE--- 
// load newthings in the collector, in the currently selected stack
void collector_get(t_collector *x, t_llll *newthings, long nullmode, long bipolar)
{
	t_llll *inlist;
	t_llll_stack **this_stack;
	t_llll *empty = NULL;
	
	if (!newthings)
		return;
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);
	if (x->c_thisstack < 0) {
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
		llll_free(newthings);
		return;
	}
	
	this_stack = x->c_stack + x->c_thisstack;
	if ((*this_stack)->s_items == 0) {
		inlist = llll_get();
		llll_stack_push((*this_stack), inlist);
	} else
		inlist = (t_llll *) *((*this_stack)->s_current);
	
	if (newthings->l_size == 0 && nullmode) {
		empty = llll_get();
		llll_appendllll(newthings, empty, 0, WHITENULL_llll);
	}
	
	if (newthings->l_size > 0) {
		if (x->c_isroot)
			llll_flatten(newthings, 1, 0);
		llll_chain(inlist, newthings);
	} else
		llll_free(newthings);
	
//	*((*this_stack)->s_current) = inlist; // ??? // I guess this is faster than dereferencing all the time... and sure it looks better!
	if (x->c_reentrant)
		bach_atomic_unlock(&x->c_lock);
	return;
}

void collector_set_root(t_collector *x)
{
	collector_top(x);
	x->c_isroot = 1;
}

void collector_change_level(t_collector *x, t_atom_long lvls)
{
	t_atom_long i;
//	t_llll **this_stack_lvl;
	t_llll_stack *this_stack;
//	t_llll *empty;
	t_llll *parent, *child;
	
	if (lvls > 0) {
		if (x->c_reentrant)
			bach_atomic_lock(&x->c_lock);
		x->c_isroot = 0;
		if (x->c_thisstack < 0) {
			if (x->c_reentrant)
				bach_atomic_unlock(&x->c_lock);
			return;
		}
		this_stack = x->c_stack[x->c_thisstack];
/*		
		if (this_stack->s_items == 0) {
			empty = llll_get();
			llll_stack_push(this_stack, empty);
			
			empty = llll_get();
			empty->l_legal = 1;
			this_stack->s_current = this_stack->s_stack;
			*(this_stack->s_current) = empty;
			this_stack->s_items = 1; 
		}
		
		if (this_stack->s_items + lvls >= this_stack->s_size) {
			this_stack->s_size = ((this_stack->s_items + lvls) / LLLL_STACK_SIZESTEP + 1) * LLLL_STACK_SIZESTEP;
			this_stack->s_stack = (void **) bach_resizeptr(this_stack->s_stack, this_stack->s_size * sizeof(void *));
		} 
*/		
/*		for (i = 0, this_stack_lvl = (t_llll **) this_stack->s_current; i < lvls; i++, this_stack_lvl++) {
			empty = llll_get();
			*(this_stack_lvl + 1) = empty;
			llll_appendllll(*this_stack_lvl, *(this_stack_lvl + 1), 0, WHITENULL_llll); // every level contains the next one
		}
		this_stack->s_current = (void **) this_stack_lvl;
		this_stack->s_items += lvls; */
		
		if (this_stack->s_items == 0) {
			parent = llll_get();
			llll_stack_push(this_stack, parent);
		} else
			parent = (t_llll *) *this_stack->s_current;
		
		for (i = 0; i < lvls; i++) {
			child = llll_get();
			llll_appendllll(parent, child, 0, WHITENULL_llll);
			llll_stack_push(this_stack, child);
			parent = child;
		}

		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
	} else if (lvls < 0) {
		if (x->c_reentrant)
			bach_atomic_lock(&x->c_lock);
		x->c_isroot = 0;
		if (x->c_thisstack < 0) {
			if (x->c_reentrant)
				bach_atomic_unlock(&x->c_lock);
			return;
		}
		this_stack = x->c_stack[x->c_thisstack];
		
		for (i = 0; i > lvls; i--)
			llll_stack_pop(this_stack);

/*		
		
		if (-lvls > this_stack->s_items)
			lvls = -this_stack->s_items;
		
		if ((this_stack->s_items += lvls) < this_stack->s_size - LLLL_STACK_SIZESTEP) {
			this_stack->s_size = (this_stack->s_items / LLLL_STACK_SIZESTEP + 1) * LLLL_STACK_SIZESTEP;
			this_stack->s_stack = (void **) bach_resizeptr(this_stack->s_stack, this_stack->s_size * sizeof(void *));				
		}
		this_stack->s_current += lvls;
 */
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
	}
}

void collector_change_collection(t_collector *x, t_atom_long collection)
{
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);	
	if (collection < 0 || collection >= x->c_stacknum)
		x->c_thisstack = -1;
	else
		x->c_thisstack = collection;
	x->c_isroot = 0;
	if (x->c_reentrant)
		bach_atomic_unlock(&x->c_lock);
}

void collector_top(t_collector *x)
{
	t_llll_stack *this_stack;
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);
	x->c_isroot = 0;
	if (x->c_thisstack < 0) {
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
		return;
	}
	this_stack = x->c_stack[x->c_thisstack];
	this_stack->s_size = LLLL_STACK_SIZESTEP;
	this_stack->s_stack = (void **) bach_resizeptr(this_stack->s_stack, this_stack->s_size * sizeof(void *));
	if (this_stack->s_items != 0) {
		this_stack->s_items = 1;
		this_stack->s_current = this_stack->s_stack;
	} else
		this_stack->s_current = this_stack->s_stack - 1;
	if (x->c_reentrant)
		bach_atomic_unlock(&x->c_lock);
}

void collector_back(t_collector *x)
{
	t_llll_stack *this_stack;
	t_llllelem *elem;
	t_llll *ll;
	
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);
	x->c_isroot = 0;
	if (x->c_thisstack < 0) {
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
		return;
	}
	
	this_stack = x->c_stack[x->c_thisstack];
	
	if (this_stack->s_items == 0) 
		goto collector_back_exit;
	
	ll = (t_llll *) *this_stack->s_current;
	elem = ll->l_tail;
	
	if (!elem) 		
		goto collector_back_exit;
	
	llll_destroyelem(elem);
collector_back_exit:
	if (x->c_reentrant)
		bach_atomic_unlock(&x->c_lock);
}

void collector_clear(t_collector *x)
{
	t_llll_stack *this_stack;
	t_llll *destroy_me;
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);
	x->c_isroot = 0;
	if (x->c_thisstack < 0) {
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
		return;
	}
	this_stack = x->c_stack[x->c_thisstack];
	if (this_stack->s_size != LLLL_STACK_SIZESTEP) {
		this_stack->s_stack = (void **) bach_resizeptr(this_stack->s_stack, LLLL_STACK_SIZESTEP * sizeof(void *));
		this_stack->s_size = LLLL_STACK_SIZESTEP;
	}
	if (this_stack->s_items) {
		destroy_me = (t_llll *) this_stack->s_stack[0];
		this_stack->s_items = 0;
		this_stack->s_current = this_stack->s_stack - 1;
	} else
		destroy_me = NULL;
	if (x->c_reentrant)
		bach_atomic_unlock(&x->c_lock);
	llll_free(destroy_me);	
}

void collector_clearall(t_collector *x)
{
	t_atom_long i, size;
	t_llll **destroy_all, **this_destroy_all;
	t_llll_stack **this_stack_ptr;
	
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);
	x->c_isroot = 0;
	this_stack_ptr = x->c_stack;
	size = x->c_stacknum;
	this_destroy_all = destroy_all = (t_llll **) bach_newptr(size * sizeof (t_llll *));
	for (i = 0; i < size; i++, this_stack_ptr++, this_destroy_all++) {
		if ((*this_stack_ptr)->s_size != LLLL_STACK_SIZESTEP) {
			(*this_stack_ptr)->s_stack = (void **) bach_resizeptr((*this_stack_ptr)->s_stack, LLLL_STACK_SIZESTEP * sizeof(void *));
			(*this_stack_ptr)->s_size = LLLL_STACK_SIZESTEP;
		}
		if ((*this_stack_ptr)->s_items) {
			*this_destroy_all = (t_llll *)  (*this_stack_ptr)->s_stack[0];
			(*this_stack_ptr)->s_items = 0;
			(*this_stack_ptr)->s_current = (*this_stack_ptr)->s_stack - 1;
		} else
			*this_destroy_all = NULL;
	}
	if (x->c_reentrant)
		bach_atomic_unlock(&x->c_lock);
	for (i = 0, this_destroy_all = destroy_all; i < size; i++, this_destroy_all++)
		llll_free(*this_destroy_all);
	bach_freeptr(destroy_all);
}

t_llll *collector_output(t_collector *x, t_atom_long lvls, t_atom_long outwrap)
{
	t_llll *to_clone = NULL;
	t_llll *cloned;
	t_llll_stack **this_stack;
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);
	if (x->c_thisstack < 0) {
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
		return NULL;
	}
	
	this_stack = x->c_stack + x->c_thisstack;
	
	if ((*this_stack)->s_items == 0 || lvls < -(*this_stack)->s_items) {
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
		cloned = llll_get();
	} else {
		if (lvls == 0 || lvls > (*this_stack)->s_items)
			to_clone = (t_llll *) (*this_stack)->s_stack[0];
		else if (lvls > 0)
			to_clone = (t_llll *) (*this_stack)->s_stack[(*this_stack)->s_items - lvls];
		else if (lvls < 0)
			to_clone = (t_llll *) (*this_stack)->s_stack[-lvls - 1];
		cloned = llll_clone(to_clone); // I need to clone the output lists, as they may be changed in the future
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
	}
	while (outwrap) {
		t_llll *to_wrap = cloned;
		cloned = llll_get();
		llll_appendllll(cloned, to_wrap, 0, WHITENULL_llll);
		outwrap--;
	}
	return cloned;
}

t_llll *collector_outputall(t_collector *x, long skip_empty, t_atom_long outwrap)
{
	t_atom_long i, this_outwrap;
	t_llll_stack **this_stack;
	t_llll *outll = llll_get();
	t_llll *cloned;
	if (x->c_reentrant)
		bach_atomic_lock(&x->c_lock);
	for (i = 0, this_stack = x->c_stack; i < x->c_stacknum; i++, this_stack++) {
		if ((*this_stack)->s_items) {
			cloned = llll_clone((t_llll *) (*this_stack)->s_stack[0]);
			this_outwrap = outwrap;
			while (this_outwrap--) {
				t_llll *to_wrap = cloned;
				cloned = llll_get();
				llll_appendllll(cloned, to_wrap, 0, WHITENULL_llll);
			}
			llll_appendllll(outll, cloned, 0, WHITENULL_llll);
		} else if (!skip_empty)
			llll_appendllll(outll, llll_get(), 0, WHITENULL_llll);			
	}	
	if (x->c_reentrant)
		bach_atomic_unlock(&x->c_lock);

	return outll;
}

t_max_err collector_size(t_collector *x, t_atom_long newsize)
{
	t_llll_stack **this_stack;
	t_atom_long i;
	
	newsize = MAX(newsize, 1);
	
	if (newsize > x->c_stacknum) {
		if (x->c_reentrant)
			bach_atomic_lock(&x->c_lock);
		
		x->c_stack = (t_llll_stack **) bach_resizeptr(x->c_stack, newsize * sizeof(t_llll_stack *));
		for (i = x->c_stacknum, this_stack = x->c_stack + i; i < newsize; i++, this_stack ++) 
			*this_stack = llll_stack_new();
		
		if (x->c_stacknum == 0)
			x->c_thisstack = 0;
		x->c_stacknum = newsize;
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
		
	} else if (newsize < x->c_stacknum) {
		if (x->c_reentrant)
			bach_atomic_lock(&x->c_lock);
		for (i = x->c_stacknum - 1, this_stack = x->c_stack + i; i >= newsize; i--, this_stack --) {
			while ((*this_stack)->s_items != 0)
				llll_free((t_llll *) llll_stack_pop(*this_stack));
			llll_stack_destroy(*this_stack);
		}
		x->c_stack = (t_llll_stack **) bach_resizeptr(x->c_stack, newsize * sizeof(t_llll_stack *));
		if (x->c_thisstack >= newsize)
			x->c_thisstack = -1;
		x->c_stacknum = newsize;
		if (x->c_reentrant)
			bach_atomic_unlock(&x->c_lock);
	}
	
	return MAX_ERR_NONE;
}
