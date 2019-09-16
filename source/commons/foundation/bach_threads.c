/*
 *  bach_threads.c
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

#include "ext.h"
#include "foundation/llll_commons.h"

typedef struct _task_data { 
	t_object		*t_obj;
	long			t_type;
	t_llll			*t_inll;
	thread_task_fn	t_task_func;
	thread_end_fn	t_end_func;
} t_task_data;

void bach_thread_task(t_task_data *data);
void bach_thread_end(t_object *x, t_symbol *sym, long ac, t_atom *av);

void bach_atomic_lock(t_bach_atomic_lock *lock)
{
	while (ATOMIC_INCREMENT_BARRIER_32(lock) > 1)
		ATOMIC_DECREMENT_BARRIER_32(lock);
}

void bach_atomic_unlock(t_bach_atomic_lock *lock)
{
	ATOMIC_DECREMENT_BARRIER(lock);
}

long bach_atomic_trylock(t_bach_atomic_lock *lock)
{
	if (ATOMIC_INCREMENT_BARRIER_32(lock) > 1) {
		ATOMIC_DECREMENT_BARRIER_32(lock);
		return 1;
	} else {
		return 0;
	}
}




void bach_atomic_rlock(t_bach_rwlock *rwlock)
{
	bach_atomic_lock(&rwlock->r_lock);
}

void bach_atomic_runlock(t_bach_rwlock *rwlock)
{
	bach_atomic_unlock(&rwlock->r_lock);
}

void bach_atomic_wlock(t_bach_rwlock *rwlock)
{
	bach_atomic_lock(&rwlock->r_lock);
}

void bach_atomic_wunlock(t_bach_rwlock *rwlock)
{
	bach_atomic_unlock(&rwlock->r_lock);
}

long bach_atomic_rtrylock(t_bach_rwlock *rwlock)
{
	return bach_atomic_trylock(&rwlock->r_lock);
}

long bach_atomic_wtrylock(t_bach_rwlock *rwlock)
{
	return bach_atomic_trylock(&rwlock->r_lock);
}


long bach_thread_start(t_object *x, long type, t_llll *ll, long priority, thread_task_fn task_fn, thread_end_fn end_fn, t_systhread *thread)
{
	t_max_err err;
	t_task_data *data = (t_task_data *) bach_newptr(sizeof(t_task_data));
	//llll_retain(ll);
	data->t_obj = x;
	data->t_type = type;
	data->t_inll = ll;
	data->t_task_func = task_fn;
	data->t_end_func = end_fn;
	err = systhread_create((method) bach_thread_task, data, 0, priority, 0, thread);
	if (err != MAX_ERR_NONE) {
		llll_free(ll);
		bach_freeptr(data);
	}
	return err;
}

void bach_thread_task(t_task_data *data)
{
	t_object *x = data->t_obj;
	e_llllobj_obj_types type = (e_llllobj_obj_types) data->t_type;
	t_llll *inll = data->t_inll;
	thread_task_fn task_fn = data->t_task_func;
	thread_end_fn end_fn = data->t_end_func;
	t_llll *resll = llll_get();
	long rv;
	t_atom out_atom[5];
	bach_freeptr(data);
	llllobj_add_to_release_pool(x, type, inll, (method) llll_free);
	llllobj_add_to_release_pool(x, type, resll, (method) llll_free);
	rv = (task_fn)(x, inll, resll);
	atom_setobj(out_atom, (void *) end_fn);
	atom_setlong(out_atom + 1, type);
	atom_setobj(out_atom + 2, inll);
	atom_setobj(out_atom + 3, resll);
	atom_setlong(out_atom + 4, rv);
	defer_low(x, (method) bach_thread_end, NULL, 5, out_atom);
	systhread_exit(0);
}

void bach_thread_end(t_object *x, t_symbol *sym, long ac, t_atom *av)
{
	thread_end_fn end_fn = (thread_end_fn) atom_getobj(av);
	e_llllobj_obj_types type = (e_llllobj_obj_types) atom_getlong(av + 1);
	t_llll *inll = (t_llll *) atom_getobj(av + 2);
	t_llll *resll = (t_llll *) atom_getobj(av + 3);
	long rv = atom_getlong(av + 4);
	(end_fn)(x, resll, rv);
	llllobj_remove_from_release_pool(x, type, inll);
	llllobj_remove_from_release_pool(x, type, resll);
	llll_release(inll);
	llll_release(resll);
}




