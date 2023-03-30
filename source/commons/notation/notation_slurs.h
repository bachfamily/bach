/*
 *  notation_slurs.h
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

/**
	@file	notation_slurs.h
*/

#ifndef _NOTATION_SLURS_H_
#define _NOTATION_SLURS_H_

#include "notation/notation.h"

#define BACH_SUPPORT_SLURS


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

// slurs
t_slur *slur_add(t_notation_obj *r_ob, t_chord *start_chord, char direction, t_chord *end_chord);
t_slur *slur_add_temporary(t_notation_obj *r_ob, t_chord *start_ch, char direction, long extension);
t_slur *slur_add_for_selection(t_notation_obj *r_ob, t_llll *names, char direction, char add_undo_ticks); // direction: 0 = auto; 1 = above, -1 = below
void slur_region_preselect_chords(t_notation_obj *r_ob, t_slur *slur);
void notationobj_addslur(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv);

void slur_set_recompute_position_flag(t_slur *slur);
void chord_recompute_slur_positions(t_notation_obj *r_ob, t_chord *ch);
void slur_check_extremes(t_notation_obj *r_ob, t_slur *slur);

void slur_find_and_set_direction(t_notation_obj *r_ob, t_slur *slur, t_llll *ll);

void slur_flip(t_slur *slur);
char slur_flip_selected(t_notation_obj *r_ob);

// move temporary slurs to permanent ones
void notationobj_make_temporary_slurs_permanent(t_notation_obj *r_ob);

void slur_delete(t_notation_obj *x, t_slur *slur, bool also_delete_llllelem = true);
char slur_delete_selected(t_notation_obj *r_ob);
char slur_delete_all(t_notation_obj *r_ob, bool add_undo_tick);
char slur_delete_starting_on_chord(t_notation_obj *r_ob, t_chord *ch);
void slur_change_starting_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *newchord, bool add_undo_ticks);
void slur_change_ending_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *newchord, bool add_undo_ticks);
void slur_nudge_starting_chord(t_notation_obj *r_ob, t_slur *slur, long delta_chords, bool add_undo_ticks);
void slur_nudge_ending_chord(t_notation_obj *r_ob, t_slur *slur, long delta_chords, bool add_undo_ticks);
void slur_nudge_starting_chord_for_selection(t_notation_obj *r_ob, long delta_chords);
void slur_nudge_ending_chord_for_selection(t_notation_obj *r_ob, long delta_chords);

void notationobj_reset_all_slurs_position(t_notation_obj *r_ob);
void chord_reset_slur_positions(t_chord *ch);
long slur_get_length_in_chords(t_slur *slur);
t_llll *chord_get_slurs_as_llll(t_chord *ch, char prepend_slur_symbol);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _NOTATION_UNDO_H_
