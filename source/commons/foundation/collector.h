/*
 *  collector.h
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

#ifndef	_COLLECTOR_H_
#define	_COLLECTOR_H_

typedef struct _collector {
//	t_object			c_ob;
	unsigned long		c_magic;
	t_int32_atomic		c_count;
	t_llll_stack		**c_stack;		// a dynamic array of stacks
	t_atom_long			c_thisstack;	// the currently active stack
	long				c_isroot;
	t_atom_long			c_stacknum;		// how many stacks we have
	long				c_reentrant;
	t_bach_atomic_lock	c_lock;
} t_collector;	


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

t_collector *collector_new(t_atom_long stacks, long reentrant);
t_collector *collector_alloc(void);
void collector_retain(t_collector *x);
void collector_release(t_collector *x);
void collector_free(t_collector *x);

void collector_get(t_collector *x, t_llll *newthings, long nullmode, long bipolar);
t_max_err collector_size(t_collector *x, t_atom_long newsize);
void collector_change_level(t_collector *x, t_atom_long lvls);
void collector_set_root(t_collector *x);

// collection is counted from 0
void collector_change_collection(t_collector *x, t_atom_long collection);
void collector_top(t_collector *x);
void collector_back(t_collector *x);
void collector_clear(t_collector *x);
void collector_clearall(t_collector *x);
t_llll *collector_output(t_collector *x, t_atom_long lvls, t_atom_long outwrap);
t_llll *collector_outputall(t_collector *x, long skip_empty, t_atom_long outwrap);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _COLLECTOR_H_
