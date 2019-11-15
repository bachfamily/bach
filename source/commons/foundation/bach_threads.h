/*
 *  bach_threads.h
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

#ifndef _BACH_THREADS_H_
#define _BACH_THREADS_H_

#include "foundation/hatom.h"

#ifdef MAC_VERSION

/** increment an atomic int value
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */

#define ATOMIC_INCREMENT_32(atomicptr) OSAtomicIncrement32((int32_t *)atomicptr)

/** increment an atomic int value with a memory barrier
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */
#define ATOMIC_INCREMENT_BARRIER_32(atomicptr) OSAtomicIncrement32Barrier((int32_t *)atomicptr)

/** decrement an atomic int value
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */
#define ATOMIC_DECREMENT_32(atomicptr) OSAtomicDecrement32((int32_t *)atomicptr)

/** decrement an atomic int value with a memory barrier
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */
#define ATOMIC_DECREMENT_BARRIER_32(atomicptr) OSAtomicDecrement32Barrier((int32_t *)atomicptr)

/** increment an atomic int value
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */

#define ATOMIC_INCREMENT_64(atomicptr) OSAtomicIncrement64((int64_t *)atomicptr)

/** increment an atomic int value with a memory barrier
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */
#define ATOMIC_INCREMENT_BARRIER_64(atomicptr) OSAtomicIncrement64Barrier((int64_t *)atomicptr)

/** decrement an atomic int value
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */
#define ATOMIC_DECREMENT_64(atomicptr) OSAtomicDecrement64((int64_t *)atomicptr)

/** decrement an atomic int value with a memory barrier
 @ingroup threading
 return value of ATOMIC_INCREMENT and ATOMIC_DECREMENT is the *new* value after performing the operation
 */
#define ATOMIC_DECREMENT_BARRIER_64(atomicptr) OSAtomicDecrement64Barrier((int64_t *)atomicptr)

/*
#define ATOMIC_COMPARE_SWAP32(oldvalue, newvalue, atomicptr) (OSAtomicCompareAndSwap32Barrier(oldvalue, newvalue, atomicptr))
#define ATOMIC_COMPARE_SWAP64(oldvalue, newvalue, atomicptr) (OSAtomicCompareAndSwap64Barrier(oldvalue, newvalue, atomicptr))
*/


#else // WIN_VERSION

#include <intrin.h>
 
BEGIN_USING_C_LINKAGE
LONGLONG  __cdecl _InterlockedIncrement64(LONGLONG volatile *Addend);
LONGLONG  __cdecl _InterlockedDecrement64(LONGLONG volatile *Addend);
END_USING_C_LINKAGE

#pragma intrinsic (_InterlockedIncrement64)
#pragma intrinsic (_InterlockedDecrement64)

/**	Use this routine for incrementing a global counter using a threadsafe and multiprocessor safe method.
 @ingroup			threading
 @param	atomicptr	pointer to the (int) counter.
 */

// on windows I don't think there are non-barrier atomic increment / decrement functions
// perhaps could be done with inline assembly?


#define ATOMIC_INCREMENT_32(atomicptr)			(_InterlockedIncrement(atomicptr))
#define ATOMIC_INCREMENT_BARRIER_32(atomicptr)	(_InterlockedIncrement(atomicptr))


/**	Use this routine for decrementing a global counter using a threadsafe and multiprocessor safe method.
 @ingroup	threading
 @param	atomicptr	pointer to the (int) counter.
 */
#define ATOMIC_DECREMENT_32(atomicptr)			(_InterlockedDecrement(atomicptr))
#define ATOMIC_DECREMENT_BARRIER_32(atomicptr)	(_InterlockedDecrement(atomicptr))

#define ATOMIC_INCREMENT_64(atomicptr)			(_InterlockedIncrement64(atomicptr))
#define ATOMIC_INCREMENT_BARRIER_64(atomicptr)	(_InterlockedIncrement64(atomicptr))


/**	Use this routine for decrementing a global counter using a threadsafe and multiprocessor safe method.
 @ingroup	threading
 @param	atomicptr	pointer to the (int) counter.
 */
#define ATOMIC_DECREMENT_64(atomicptr)			(_InterlockedDecrement64(atomicptr))
#define ATOMIC_DECREMENT_BARRIER_64(atomicptr)	(_InterlockedDecrement64(atomicptr))

#endif // WIN_VERSION

#ifdef C74_x64
#define t_atom_long_atomic t_int64_atomic
#define ATOMIC_INCREMENT_ATOM(atomicptr)  ATOMIC_INCREMENT_64(atomicptr)
#define ATOMIC_INCREMENT_BARRIER_ATOM(atomicptr)  ATOMIC_INCREMENT_BARRIER_64(atomicptr)
#define ATOMIC_DECREMENT_ATOM(atomicptr)  ATOMIC_DECREMENT_64(atomicptr)
#define ATOMIC_DECREMENT_BARRIER_ATOM(atomicptr)  ATOMIC_DECREMENT_BARRIER_64(atomicptr)
#else
#define t_atom_long_atomic t_int32_atomic
#define ATOMIC_INCREMENT_ATOM(atomicptr)  ATOMIC_INCREMENT_32(atomicptr)
#define ATOMIC_INCREMENT_BARRIER_ATOM(atomicptr)  ATOMIC_INCREMENT_BARRIER_32(atomicptr)
#define ATOMIC_DECREMENT_ATOM(atomicptr)  ATOMIC_DECREMENT_32(atomicptr)
#define ATOMIC_DECREMENT_BARRIER_ATOM(atomicptr)  ATOMIC_DECREMENT_BARRIER_32(atomicptr)
#endif

typedef enum _llllobj_obj_types {
	LLLL_OBJ_ERR		= -1,
	LLLL_OBJ_VANILLA	= 0,
	LLLL_OBJ_MSP,
	LLLL_OBJ_UI,
	LLLL_OBJ_UIMSP
} e_llllobj_obj_types;


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

t_max_err llllobj_add_to_release_pool(t_object *x, e_llllobj_obj_types type, void *release_me, method free_function);
t_max_err llllobj_remove_from_release_pool(t_object *x, e_llllobj_obj_types type, void *remove_me);
void llllobj_free_release_pool(t_object *x, e_llllobj_obj_types type);

typedef long (*thread_task_fn)(t_object *x, t_llll *ll, t_llll *res_ll);
typedef void (*thread_end_fn)(t_object *x, t_llll *res_ll, long rv);


/* 
 Acquire a lightweight thread lock using an atomic counter.
 This should be preferred to a mutex when the chances of resource competition are low
 */

void bach_atomic_lock(t_int32_atomic *lock);

/* 
 Try to acquire a lightweight thread lock using an atomic counter.
 If the thread lock can be acquired the function returns 0, otherwise non-0.
 This should be preferred to a mutex when the chances of resource competition are low
 */
long bach_atomic_trylock(t_int32_atomic *lock);

/*
 Release an atomic counter after it has been acquired by bach_atomic_lock() or bach_atomic_trylock()
 */
void bach_atomic_unlock(t_int32_atomic *lock);


// DEPRECATED
void bach_atomic_rlock(t_bach_rwlock *rwlock);
void bach_atomic_wlock(t_bach_rwlock *rwlock);
void bach_atomic_runlock(t_bach_rwlock *rwlock);
void bach_atomic_wunlock(t_bach_rwlock *rwlock);
long bach_atomic_rtrylock(t_bach_rwlock *rwlock);
long bach_atomic_wtrylock(t_bach_rwlock *rwlock);




/*
 Create a new thread in which task_fn will be perfomed.
 task_fn will receive x and ll as its arguments.
 When task_fn exits, end_fn is called in the Max main thread, with x and the result from task_fn (res_ll)
 When end_fn returns, ll and res_ll are freed.
 res_ll will be released immediately after end_fn has been called, so if you need to use it further than that you need to retain it. 
 It is a good idea to provide a way to stop the running thread, especially if its job is a long one.
 In this way, in the object_free() method you can ask the running thread to stop, and wait for it to exit with systhread_join().
 This is the specific case where end_fn will not be called, but ll and res_ll will be released "from the inside" instead.
 */
long bach_thread_start(t_object *x, long type, t_llll *ll, long priority, thread_task_fn task_fn, thread_end_fn end_fn, t_systhread *thread);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _BACH_THREADS_H_
