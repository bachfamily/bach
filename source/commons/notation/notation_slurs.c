/*
 *  notation_slurs.c
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
    notation_slurs.c - common functions (or useful functions) for slurs
*/

#include "notation/notation_slurs.h"
#include "notation/notation_undo.h"


void slur_set_recompute_position_flag(t_slur *slur)
{
    slur->need_recompute_position = true;
}

void slur_check_extremes(t_notation_obj *r_ob, t_slur *slur)
{
    t_chord *start_ch = slur->start_chord;
    t_chord *end_ch = slur->end_chord;
    bool swap = false;
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        swap = (start_ch->onset > end_ch->onset);
    } else {
        if (start_ch->parent && end_ch->parent) {
            swap = (start_ch->parent->measure_number > end_ch->parent->measure_number ||
                    ((start_ch->parent->measure_number == end_ch->parent->measure_number) &&
                    (rat_rat_cmp(start_ch->r_sym_onset, end_ch->r_sym_onset) > 0)));
        }
    }
    
    if (swap) {
        // swap!
        if (start_ch->num_slurs_from < CONST_MAX_SLURS_PER_CHORD && end_ch->num_slurs_to < CONST_MAX_SLURS_PER_CHORD) {
            
            for (long i = 0; i < start_ch->num_slurs_to; ) {
                if (start_ch->slur_to[i] == slur) {
                    long j;
                    for (j = i+1; j < start_ch->num_slurs_to; j++)
                        start_ch->slur_to[j-1] = start_ch->slur_to[j];
                    start_ch->num_slurs_to--;
                    break;
                } else
                    i++;
            }
            
            for (long i = 0; i < end_ch->num_slurs_from; ) {
                if (end_ch->slur_from[i] == slur) {
                    long j;
                    for (j = i+1; j < end_ch->num_slurs_from; j++)
                        end_ch->slur_from[j-1] = end_ch->slur_from[j];
                    end_ch->num_slurs_from--;
                    break;
                } else
                    i++;
            }
            
            end_ch->slur_to[end_ch->num_slurs_to++] = slur;
            start_ch->slur_from[start_ch->num_slurs_from++] = slur;
            slur->start_chord = end_ch;
            slur->end_chord = start_ch;
            slur_set_recompute_position_flag(slur);
            
            if (start_ch->r_it.type != k_CHORD || end_ch->r_it.type != k_CHORD) {
                object_error((t_object *)r_ob, "SLUR ERROR!");
            }

        }
    }
}

void notationobj_check_slur_extremes_for_selection(t_notation_obj *r_ob)
{
    t_notation_item *curr_it = r_ob->firstselecteditem;
    lock_general_mutex(r_ob);
    while (curr_it) { // cycle on the selected items
        
        switch (curr_it->type) {
            case k_SLUR:
                slur_check_extremes(r_ob, (t_slur *)curr_it);
                break;
                
            case k_CHORD:
            {
                t_chord *ch = (t_chord *)curr_it;
                for (long i = 0; i < ch->num_slurs_to; i++) {
                    slur_check_extremes(r_ob, (t_slur *)ch->slur_to[i]);
                }
                for (long i = 0; i < ch->num_slurs_from; i++) {
                    slur_check_extremes(r_ob, (t_slur *)ch->slur_from[i]);
                }
                break;
            }
                
            case k_NOTE:
            {
                t_chord *ch = ((t_note *)curr_it)->parent;
                if (ch) {
                    for (long i = 0; i < ch->num_slurs_to; i++) {
                        slur_check_extremes(r_ob, (t_slur *)ch->slur_to[i]);
                    }
                    for (long i = 0; i < ch->num_slurs_from; i++) {
                        slur_check_extremes(r_ob, (t_slur *)ch->slur_from[i]);
                    }
                }
                break;
            }
                
            default:
                break;
        }
        curr_it = curr_it->next_selected;
    }
    unlock_general_mutex(r_ob);
}


void notationobj_check_all_slur_extremes(t_notation_obj *r_ob)
{
    for (t_llllelem *el = r_ob->slurs->l_head; el; el = el->l_next) {
        t_slur *sl = (t_slur *)hatom_getobj(&el->l_hatom);
        if (sl)
            slur_check_extremes(r_ob, sl);
    }
}

    
    
t_slur *slur_add(t_notation_obj *r_ob, t_chord *start_ch, t_chord *end_ch, t_llll *names, char direction)
{
    if (start_ch->num_slurs_to < CONST_MAX_SLURS_PER_CHORD && end_ch->num_slurs_from < CONST_MAX_SLURS_PER_CHORD) {
        t_slur *this_slur = (t_slur *)bach_newptr(sizeof(t_slur));
        
        notation_item_init(&this_slur->r_it, k_SLUR);
        
        this_slur->is_temporary = false;
        this_slur->temporary_extension = 0;
        this_slur->start_chord = start_ch;
        this_slur->direction = direction;
        this_slur->end_chord = end_ch;
        start_ch->slur_to[start_ch->num_slurs_to++] = this_slur;
        end_ch->slur_from[end_ch->num_slurs_from++] = this_slur;
        slur_set_recompute_position_flag(this_slur);
        slur_check_extremes(r_ob, this_slur);
        
        this_slur->elem = llll_appendobj(r_ob->slurs, this_slur);
        
        if (names && names->l_head)
            notation_item_set_names_from_llll(r_ob, (t_notation_item *)this_slur, names);

        return this_slur;
    } else {
        object_error((t_object *)r_ob, "Too many slurs start or end from a single chord.");
    }
    return NULL;
}

t_slur *slur_add_temporary(t_notation_obj *r_ob, t_chord *start_ch, char direction, long extension)
{
    t_slur *this_slur = (t_slur *)bach_newptr(sizeof(t_slur));
    
    notation_item_init(&this_slur->r_it, k_SLUR);
    
    this_slur->is_temporary = true;
    this_slur->temporary_extension = extension;
    this_slur->start_chord = start_ch;
    this_slur->direction = direction;
    this_slur->end_chord = NULL;
    slur_set_recompute_position_flag(this_slur);

    if (start_ch->r_it.type != k_CHORD) {
        object_error((t_object *)r_ob, "SLUR ERROR!");
    }

    llll_appendobj(r_ob->slurs_to_be_processed, this_slur);
    return this_slur;
}

void notationobj_make_temporary_slurs_permanent(t_notation_obj *r_ob)
{
    for (t_llllelem *el = r_ob->slurs_to_be_processed->l_head; el; el = el->l_next) {
        t_slur *tempslur = (t_slur *)hatom_getobj(&el->l_hatom);
        if (tempslur->start_chord) {
            // finding end chord
            t_chord *endchord = tempslur->start_chord;
            for (long i = 0; endchord && i < tempslur->temporary_extension; i++)
                endchord = chord_get_next(endchord);
            t_llll *names = get_names_as_llll((t_notation_item *)tempslur, false);
            if (tempslur->start_chord && endchord)
                slur_add(r_ob, tempslur->start_chord, endchord, names, tempslur->direction);
            llll_free(names);
        }
        notation_item_free((t_notation_item *)tempslur);
        bach_freeptr(tempslur);
    }
    llll_clear(r_ob->slurs_to_be_processed);
}

t_slur *slur_add_for_selection(t_notation_obj *r_ob, t_llll *names, char direction, char add_undo_ticks)
{
#ifdef BACH_ALLOW_SLURS_ON_RESTS
    t_chord *left = get_leftmost_selected_chord_even_partially(r_ob);
    t_chord *right = get_rightmost_selected_chord_even_partially(r_ob);
    if (left && right && left != right) {
        if (add_undo_ticks)
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)left, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
        t_slur *slur = slur_add(r_ob, left, right, names, direction);
        return slur;
    }
#else
    t_note *left = get_leftmost_selected_note(r_ob);
    t_note *right = get_rightmost_selected_note(r_ob);
    if (left && right && left->parent != right->parent) {
        if (add_undo_ticks)
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)left->parent, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
        t_slur *slur = slur_add(r_ob, left->parent, right->parent, names, direction);
        return slur;
    }
#endif
    return NULL;
}

void slur_change_starting_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *newchord, bool add_undo_ticks)
{
    if (notation_item_get_voicenumber(r_ob, (t_notation_item *)slur->start_chord) !=
        notation_item_get_voicenumber(r_ob, (t_notation_item *)newchord)) {
        if (!(r_ob->private_flag & k_NOTATION_OBJECT_FLAG_SLUR_WARNED_AT_MOUSEDRAG)) {
            object_warn((t_object *)r_ob, "bach currently does not support cross-voice slurs");
            r_ob->private_flag |= k_NOTATION_OBJECT_FLAG_SLUR_WARNED_AT_MOUSEDRAG;
        }
        return;
    }
    
    long i = 0;
    if (newchord->num_slurs_to < CONST_MAX_SLURS_PER_CHORD) {
        t_chord *old_chord = slur->start_chord;
        
        if (add_undo_ticks) {
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)old_chord, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)newchord, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
        }

        
        while (i < old_chord->num_slurs_to) {
            if (old_chord->slur_to[i] == slur) {
                long j;
                for (j = i+1; j < slur->start_chord->num_slurs_to; j++)
                    slur->start_chord->slur_to[j-1] = slur->start_chord->slur_to[j];
                slur->start_chord->num_slurs_to--;
                break;
            } else
                i++;
        }
        
        newchord->slur_to[newchord->num_slurs_to] = slur;
        newchord->num_slurs_to++;
        
        slur->start_chord = newchord;
        slur_set_recompute_position_flag(slur);
        slur_check_extremes(r_ob, slur);
    } else {
        object_error((t_object *)r_ob, "Too many slurs start or end from a single chord.");
    }
}

void slur_change_ending_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *newchord, bool add_undo_ticks)
{
    if (notation_item_get_voicenumber(r_ob, (t_notation_item *)slur->end_chord) !=
        notation_item_get_voicenumber(r_ob, (t_notation_item *)newchord)) {
        if (!(r_ob->private_flag & k_NOTATION_OBJECT_FLAG_SLUR_WARNED_AT_MOUSEDRAG)) {
            object_warn((t_object *)r_ob, "bach currently does not support cross-voice slurs");
            r_ob->private_flag |= k_NOTATION_OBJECT_FLAG_SLUR_WARNED_AT_MOUSEDRAG;
        }
        return;
    }

    long i = 0;
    if (newchord->num_slurs_from < CONST_MAX_SLURS_PER_CHORD) {
        
        if (add_undo_ticks) {
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)slur->start_chord, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
        }
        

        while (i < slur->end_chord->num_slurs_from) {
            if (slur->end_chord->slur_from[i] == slur) {
                long j;
                for (j = i+1; j < slur->end_chord->num_slurs_from; j++)
                    slur->end_chord->slur_from[j-1] = slur->end_chord->slur_from[j];
                slur->end_chord->num_slurs_from--;
                break;
            } else
                i++;
        }
        
        newchord->slur_from[newchord->num_slurs_from] = slur;
        newchord->num_slurs_from++;
        
        slur->end_chord = newchord;
        slur_set_recompute_position_flag(slur);
    } else {
        object_error((t_object *)r_ob, "Too many slurs start or end from a single chord.");
    }
}

void slur_nudge_starting_chord(t_notation_obj *r_ob, t_slur *slur, long delta_chords, bool add_undo_ticks)
{
    if (delta_chords == 0)
        return;
    
    t_chord *newchord = slur->start_chord;
    if (!newchord)
        return;
    
    char direction = (delta_chords > 0 ? 1 : -1);
    delta_chords = abs(delta_chords);
    for (long count = 0; count < delta_chords; count++) {
        t_chord *temp = direction > 0 ? chord_get_next_nonrest(newchord) : chord_get_prev_nonrest(newchord);
        if (temp)
            newchord = temp;
    }
    
    if (newchord && newchord != slur->start_chord)
        slur_change_starting_chord(r_ob, slur, newchord, add_undo_ticks);
}

void slur_nudge_ending_chord(t_notation_obj *r_ob, t_slur *slur, long delta_chords, bool add_undo_ticks)
{
    if (delta_chords == 0)
        return;
    
    t_chord *newchord = slur->end_chord;
    if (!newchord)
        return;
    
    char direction = (delta_chords > 0 ? 1 : -1);
    delta_chords = abs(delta_chords);
    for (long count = 0; count < delta_chords; count++) {
        t_chord *temp = direction > 0 ? chord_get_next_nonrest(newchord) : chord_get_prev_nonrest(newchord);
        if (temp)
            newchord = temp;
    }
    
    if (newchord && newchord != slur->end_chord)
        slur_change_ending_chord(r_ob, slur, newchord, add_undo_ticks);
}


void slur_nudge_starting_chord_for_selection(t_notation_obj *r_ob, long delta_chords)
{
    for (t_notation_item *it = r_ob->firstselecteditem; it; it = it->next_selected) {
        if (it->type == k_SLUR)
            slur_nudge_starting_chord(r_ob, (t_slur *)it, delta_chords, true);
    }
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}

void slur_nudge_ending_chord_for_selection(t_notation_obj *r_ob, long delta_chords)
{
    for (t_notation_item *it = r_ob->firstselecteditem; it; it = it->next_selected) {
        if (it->type == k_SLUR)
            slur_nudge_ending_chord(r_ob, (t_slur *)it, delta_chords, true);
    }
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}

void slur_delete(t_notation_obj *r_ob, t_slur *slur, bool also_delete_llllelem)
{
    long i;
    if (slur) {
        t_chord *start = slur->start_chord;
        t_chord *end = slur->end_chord;
        
        if (start->r_it.type != k_CHORD || end->r_it.type != k_CHORD) {
            object_error((t_object *)r_ob, "SLUR ERROR!");
        }
        
        if (start) {
            i = 0;
            while (i < start->num_slurs_to) {
                if (start->slur_to[i] == slur) {
                    long j;
                    for (j = i+1; j < start->num_slurs_to; j++)
                        start->slur_to[j-1] = start->slur_to[j];
                    start->num_slurs_to--;
                } else
                    i++;
            }
        }
        
        if (end) {
            i = 0;
            while (i < end->num_slurs_from) {
                if (end->slur_from[i] == slur) {
                    long j;
                    for (j = i+1; j < end->num_slurs_from; j++)
                        end->slur_from[j-1] = end->slur_from[j];
                    end->num_slurs_from--;
                } else
                    i++;
            }
        }
        
        if (also_delete_llllelem && slur->elem)
            llll_destroyelem(slur->elem);
        
        notation_item_free((t_notation_item *)slur);
        slur->r_it.ID = BACH_MAGIC_BAD; // to have a clue that we freed...
        bach_freeptr(slur);
        slur = NULL;
    }
}


char slur_delete_selected(t_notation_obj *r_ob)
{
    char changed = 0;
    t_notation_item *curr_it;
    lock_general_mutex(r_ob);
    curr_it = r_ob->firstselecteditem;
    while (curr_it) { // cycle on the selected items
        if (curr_it->type == k_SLUR || curr_it->type == k_SLUR_START_POINT || curr_it->type == k_SLUR_END_POINT) {
            t_slur *slur = ((t_slur *)curr_it);
            t_notation_item *temp = curr_it->next_selected;
            changed = 1;
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)slur->start_chord, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            notation_item_delete_from_selection(r_ob, (t_notation_item *)slur); // to be 100% sure, we delete all stuff
            slur_delete(r_ob, slur);
            curr_it = temp;
        } else {
            curr_it = curr_it->next_selected;
        }
    }
    unlock_general_mutex(r_ob);
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return changed;
}

char slur_delete_all(t_notation_obj *r_ob, bool add_undo_tick)
{
    char changed = 0;
    lock_general_mutex(r_ob);
    for (t_llllelem *el = r_ob->slurs->l_head; el; el = el->l_next) {
        t_slur *slur = (t_slur *)hatom_getobj(&el->l_hatom);
        if (add_undo_tick) {
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)slur->start_chord, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)slur->end_chord, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
        }
        slur_delete(r_ob, slur, false);
        changed = 1;
    }
    llll_clear(r_ob->slurs);
    unlock_general_mutex(r_ob);
    return changed;
}


char slur_delete_starting_on_chord(t_notation_obj *r_ob, t_chord *ch)
{
    char changed = 0;
    while (ch->num_slurs_to > 0) {
        slur_delete(r_ob, ch->slur_to[0]);
        changed = 1;
    }
    return changed;
}


void slur_flip(t_slur *slur)
{
    if (!slur->start_chord)
        return;
    
    char direction = slur_get_actual_direction(slur);
    slur->direction = -direction;
    slur_set_recompute_position_flag(slur);
}

char slur_flip_selected(t_notation_obj *r_ob)
{
    char changed = 0;
    lock_general_mutex(r_ob);
    for (t_notation_item *curr_it = r_ob->firstselecteditem; curr_it; curr_it = curr_it->next_selected) {
        if (curr_it->type == k_SLUR || curr_it->type == k_SLUR_START_POINT || curr_it->type == k_SLUR_END_POINT) {
            t_slur *slur = ((t_slur *)curr_it);
            changed = 1;
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)slur->start_chord, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            slur_flip(slur);
        }
    }
    unlock_general_mutex(r_ob);
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return changed;
}

void notationobj_reset_all_slurs_position(t_notation_obj *r_ob)
{
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice))
        for (t_chord *chord = voice_get_first_chord(r_ob, voice); chord; chord = chord_get_next(chord)) {
            for (long i = 0; i < chord->num_slurs_to; i++)
                slur_set_recompute_position_flag(chord->slur_to[i]);
            for (long i = 0; i < chord->num_slurs_from; i++)
                slur_set_recompute_position_flag(chord->slur_from[i]);
        }
}

void chord_reset_slur_positions(t_chord *ch)
{
    for (long j = 0; j < ch->num_slurs_to; j++)
        slur_set_recompute_position_flag(ch->slur_to[j]);
    for (long j = 0; j < ch->num_slurs_from; j++)
        slur_set_recompute_position_flag(ch->slur_from[j]);
}


long slur_get_length_in_chords(t_slur *slur)
{
    long count = 0;
    for (t_chord *ch = slur->start_chord; ch; ch = chord_get_next(ch)) {
        if (ch == slur->end_chord)
            break;
        count ++;
    }
    return count;
}


t_llll *chord_get_slurs_as_llll(t_chord *ch, char prepend_slurs_symbol)
{
    t_llll *out = llll_get();
    if (prepend_slurs_symbol)
        llll_appendsym(out, _llllobj_sym_slurs);
    if (ch) {
        for (long i = 0; i < ch->num_slurs_to; i++) {
            bool need_llll = ((ch->slur_to[i]->r_it.names && ch->slur_to[i]->r_it.names->l_size > 0) ||
                              ch->slur_to[i]->direction != 0);
            if (need_llll) {
                t_llll *subll = llll_get();
                llll_appendlong(subll, slur_get_length_in_chords(ch->slur_to[i]));
                if (ch->slur_to[i]->r_it.names && ch->slur_to[i]->r_it.names->l_size > 0)
                    llll_appendllll(subll, get_names_as_llll((t_notation_item *)ch->slur_to[i], true));
                if (ch->slur_to[i]->direction != 0)
                    llll_appendllll(subll, symbol_and_long_to_llll(_llllobj_sym_direction, ch->slur_to[i]->direction));
                llll_appendllll(out, subll);
            } else {
                llll_appendlong(out, slur_get_length_in_chords(ch->slur_to[i]));
            }
        }
    }
    return out;
}

t_llll *chord_get_slurs_end_as_llll(t_chord *ch, char prepend_slurs_symbol)
{
    t_llll *out = llll_get();
    if (prepend_slurs_symbol)
        llll_appendsym(out, _llllobj_sym_slurs);
    if (ch) {
        for (long i = 0; i < ch->num_slurs_from; i++) {
            bool need_llll = ((ch->slur_from[i]->r_it.names && ch->slur_from[i]->r_it.names->l_size > 0) ||
                              ch->slur_from[i]->direction != 0);
            if (need_llll) {
                t_llll *subll = llll_get();
                llll_appendlong(subll, -slur_get_length_in_chords(ch->slur_from[i]));
                if (ch->slur_from[i]->r_it.names && ch->slur_from[i]->r_it.names->l_size > 0)
                    llll_appendllll(subll, get_names_as_llll((t_notation_item *)ch->slur_from[i], true));
                if (ch->slur_from[i]->direction != 0)
                    llll_appendllll(subll, symbol_and_long_to_llll(_llllobj_sym_direction, ch->slur_from[i]->direction));
                llll_appendllll(out, subll);
            } else {
                llll_appendlong(out, -slur_get_length_in_chords(ch->slur_from[i]));
            }
        }
    }
    return out;
}



void slur_region_preselect_chords(t_notation_obj *r_ob, t_slur *slur)
{
    t_chord *start = slur->start_chord;
    t_chord *end = slur->end_chord;
    
    if (start && end) {
        for (t_chord *temp = start; temp; temp = chord_get_next(temp)) {
            notation_item_add_to_preselection(r_ob, (t_notation_item *)temp);
            if (temp == end)
                break;
        }
    }
}



void notationobj_addslur(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *names = NULL;
    long direction = 0;
    t_llll *ll = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    llll_parseargs_and_attrs_destructive((t_object *)r_ob, ll, "li", _llllobj_sym_name, &names, _llllobj_sym_direction, &direction);

    if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_selection) {
        // add a slur for the selection
        slur_add_for_selection(r_ob, names, direction, true);
    } else if (ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_LLLL &&  hatom_gettype(&ll->l_head->l_next->l_hatom) == H_LLLL){
        t_notation_item_path start_path, end_path;
        notation_item_path_from_llll(r_ob, k_CHORD, hatom_getllll(&ll->l_head->l_hatom), &start_path);
        notation_item_path_from_llll(r_ob, k_CHORD, hatom_getllll(&ll->l_head->l_next->l_hatom), &end_path);
        if (start_path.chord_num != -1 && end_path.chord_num != -1) {
            t_chord *start_ch = (t_chord *)notation_item_from_path(r_ob, k_CHORD, &start_path);
            t_chord *end_ch = (t_chord *)notation_item_from_path(r_ob, k_CHORD, &end_path);
            if (start_ch && end_ch) {
                undo_tick_create_for_notation_item(r_ob, (t_notation_item *)start_ch, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
                slur_add(r_ob, start_ch, end_ch, names, direction);
            } else {
                object_error((t_object *)r_ob, "Wrong syntax");
            }
        } else {
            object_error((t_object *)r_ob, "Wrong syntax");
        }
    } else {
        object_error((t_object *)r_ob, "Wrong syntax");
    }
    
    if (names)
        llll_free(names);
    llll_free(ll);
}


bool slur_is_over_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *ch)
{
    if (!ch || !slur->start_chord || !slur->end_chord)
        return false;

    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        return (ch->onset >= slur->start_chord->onset && ch->onset <= slur->end_chord->onset);
    } else {
        bool ok_left = (ch->parent->measure_number > slur->start_chord->parent->measure_number ||
                        (ch->parent->measure_number == slur->start_chord->parent->measure_number &&
                         (rat_rat_cmp(ch->r_sym_onset, slur->start_chord->r_sym_onset) >= 0)));
        bool ok_right = (ch->parent->measure_number < slur->end_chord->parent->measure_number ||
                        (ch->parent->measure_number == slur->end_chord->parent->measure_number &&
                         (rat_rat_cmp(ch->r_sym_onset, slur->end_chord->r_sym_onset) <= 0)));
        return ok_left && ok_right;
    }
}

// slurs
void chord_recompute_slur_positions(t_notation_obj *r_ob, t_chord *ch)
{
    if (ch->num_slurs_to > 0 || ch->num_slurs_from > 0)
        chord_reset_slur_positions(ch);

    // VERIFY IF CHORD IS *INSIDE* a slur this may be costly though...
    for (t_llllelem *el = r_ob->slurs->l_head; el; el = el->l_next) {
        t_slur *slur = (t_slur *)hatom_getobj(&el->l_hatom);
        if (slur_is_over_chord)
            slur_set_recompute_position_flag(slur);
    }
}


void slur_find_and_set_direction(t_notation_obj *r_ob, t_slur *slur, t_llll *ll)
{
    for (t_llllelem *el = ll->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *subll = hatom_getllll(&el->l_hatom);
            if (subll && subll->l_size >= 2 && hatom_gettype(&subll->l_head->l_hatom) == H_SYM && hatom_getsym(&subll->l_head->l_hatom) == _llllobj_sym_direction) {
                if (hatom_gettype(&subll->l_head->l_next->l_hatom) == H_LONG) {
                    slur->direction = hatom_getlong(&subll->l_head->l_next->l_hatom);
                } else if (hatom_gettype(&subll->l_head->l_next->l_hatom) == H_SYM) {
                    t_symbol *s = hatom_getsym(&subll->l_head->l_next->l_hatom);
                    if (s == _sym_up)
                        slur->direction = 1;
                    else if (s == _sym_down)
                        slur->direction = -1;
                    else
                        slur->direction = 0;
                }
            }
        }
    }
}



void slur_compute_control_points_methodA(t_notation_obj *r_ob, t_slur *slur)
{
    t_chord *start = slur->start_chord, *end = slur->end_chord;
    char direction = slur_get_actual_direction(slur); // (slur->direction) ? slur->direction : -start->direction;
    double alpha;
    double long_base, delta_ux, a, b, h;
    char reversed = false;
    t_chord *chord;
    double raise1_y = 0, raise2_y = 0, raisestart_y = 0, raiseend_y = 0;
    
/*        // gotta switch start and end notes? (if chords are reversed!)
    if (is_chord_before_chord(r_ob, end, start)){
        t_chord *temp;
        temp = start;
        start = end;
        end = temp;
        reversed = true;
    }
*/
    t_note *start_nt = start->lastnote;
    t_note *end_nt = end->lastnote;
    if (direction < 0) {
        start_nt = start->firstnote;
        end_nt = end->firstnote;
    }
    
    // standard positioning for start point and end point
    double staff_top_y = voice_get_staff_top_y(r_ob, chord_get_voice(r_ob, start), k_NONSTANDARD_STAFFLINES_TOPBOTTOM_ACCOUNT);
    double staff_bottom_y = voice_get_staff_bottom_y(r_ob, chord_get_voice(r_ob, start), k_NONSTANDARD_STAFFLINES_TOPBOTTOM_ACCOUNT);
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        slur->start_ux = start->parent->tuttipoint_reference->offset_ux + start->stem_offset_ux + (start_nt ? start_nt->notecenter_stem_delta_ux : 0);
        slur->end_ux = end->parent->tuttipoint_reference->offset_ux + end->stem_offset_ux + (end_nt ? end_nt->notecenter_stem_delta_ux : 0);
    } else {
        slur->start_ux = chord_get_alignment_ux(r_ob, start) + (start_nt ? start_nt->notecenter_stem_delta_ux : 0);
        slur->end_ux = chord_get_alignment_ux(r_ob, end) + (end_nt ? end_nt->notecenter_stem_delta_ux : 0);
    }
    slur->start_y = (start_nt ? start_nt->center.y : (direction > 0 ? staff_top_y : staff_bottom_y))  + 2 * r_ob->step_y * (- direction);
    slur->end_y = (end_nt ? end_nt->center.y : (direction > 0 ? staff_top_y : staff_bottom_y)) + 2 * r_ob->step_y * (- direction);

    // particular cases for start point and end point
    if (direction == -1 && end->direction == -1) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            slur->end_ux = end->parent->tuttipoint_reference->offset_ux + end->stem_offset_ux - CONST_SLUR_USEPARATION_FROM_STEM;
        } else {
            slur->end_ux = chord_get_stem_ux(r_ob, end) - CONST_SLUR_USEPARATION_FROM_STEM;
        }
    } else if (direction == 1 && start->direction == 1) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            slur->start_ux = start->parent->tuttipoint_reference->offset_ux + start->stem_offset_ux + CONST_SLUR_USEPARATION_FROM_STEM;
        } else {
            slur->start_ux = chord_get_stem_ux(r_ob, start) + CONST_SLUR_USEPARATION_FROM_STEM;
        }
    }

    if (slur->start_ux == slur->end_ux) slur->end_ux += 5 * r_ob->zoom_y;

    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        const double stem_slur_separation_in_steps = 1.;
        if (direction * end->direction == 1 && rat_long_cmp(end->figure, 1) < 0) {
            // if the slur ends on a stem rather than a notehead
            slur->end_ux = xposition_to_unscaled_xposition(r_ob, end->stem_x) - CONST_SLUR_USEPARATION_FROM_STEM;
            if (direction == 1)
                slur->end_y = end->topmost_y - stem_slur_separation_in_steps * r_ob->step_y;
            else
                slur->end_y = end->bottommost_y + stem_slur_separation_in_steps * r_ob->step_y;
        } else if (direction * start->direction == 1 && rat_long_cmp(start->figure, 1) < 0) {
            // if the slur starts on a stem rather than a notehead
            slur->start_ux = xposition_to_unscaled_xposition(r_ob, start->stem_x) + CONST_SLUR_USEPARATION_FROM_STEM;
            if (direction == 1)
                slur->start_y = start->topmost_y - stem_slur_separation_in_steps * r_ob->step_y;
            else
                slur->start_y = start->bottommost_y + stem_slur_separation_in_steps * r_ob->step_y;
        }
    }
    
    // nudging end point if the chord has an accidental
    bool end_pt_is_on_an_accidental = false;
    fill_topmost_bottommost_fields(r_ob, end, staff_top_y);
    if (direction > 0) {
        if (end->topmost_y_noacc - CONST_EPSILON5 > end->topmost_y)
            end_pt_is_on_an_accidental = true;
    } else {
        if (end->bottommost_y_noacc + CONST_EPSILON5 < end->bottommost_y)
            end_pt_is_on_an_accidental = true;
    }
    if (r_ob->slurs_avoid_accidentals && end_pt_is_on_an_accidental) {
        slur->end_y -= 2 * r_ob->step_y * direction;
    }


    // calculating standard control points
    delta_ux = slur->end_ux - slur->start_ux;
    long_base = sqrt(delta_ux * delta_ux + (slur->start_y - slur->end_y) * (slur->start_y - slur->end_y));
    alpha = fabs(atan(-(slur->end_y - slur->start_y)/(slur->end_ux - slur->start_ux)));

    a = long_base * CLAMP(0.3 - 0.12 * long_base/400., 0.18, 0.3);
    b = long_base - a;
    h = CLAMP(CONST_SLUR_MIN_UHEIGHT + (CONST_SLUR_MAX_UHEIGHT - CONST_SLUR_MIN_UHEIGHT) * long_base/400., CONST_SLUR_MIN_UHEIGHT, CONST_SLUR_MAX_UHEIGHT) * r_ob->zoom_y;
    
    if ((direction == 1 && slur->end_y <= slur->start_y) || (direction == -1 && slur->end_y >= slur->start_y)) {
        slur->cp1_relx = a * cos(alpha) - h * sin(alpha);
        slur->cp1_y = (slur->cp1_relx * tan(alpha) + h / cos(alpha)) * (- direction);
        slur->cp2_relx = b * cos(alpha) - h * sin(alpha);
        slur->cp2_y = (slur->cp2_relx * tan(alpha) + h / cos(alpha)) * (- direction);
        slur->cp1_relx += slur->start_ux;
        slur->cp2_relx += slur->start_ux;
        slur->cp1_y += slur->start_y;
        slur->cp2_y += slur->start_y;
    } else {
        slur->cp1_relx = slur->start_ux + a / cos(alpha) + (h - a*tan(alpha)) * sin(alpha);
        slur->cp1_y = slur->start_y + (h - a*tan(alpha)) * cos(alpha) * (- direction);
        slur->cp2_relx = slur->start_ux + b / cos(alpha) + (h - b*tan(alpha)) * sin(alpha);
        slur->cp2_y = slur->start_y + (h - b*tan(alpha)) * cos(alpha) * (- direction);
    }

    // modify (if needed) control points, so that the slur does not cross notes or stems
    const long MAX_TRIES = 100;
    if (r_ob->slurs_avoid_chords && direction != 0 && start != end) {
        for (   chord = chord_get_next(start);
                chord && chord_get_prev(chord) != end; // && chord_get_prev(chord) != chord_get_prev(end->parent);
             chord = chord_get_next(chord)) {
            
            long count = 0;
            char is_good = false;
            double d1, d2, d, s, s_used, d_step;
            double stem_ux = xposition_to_unscaled_xposition(r_ob, chord->stem_x);
            
            double pt_y;
            
            fill_topmost_bottommost_fields(r_ob, chord, staff_top_y);

            double chord_topmost_y = chord->topmost_y;
            double chord_bottommost_y = chord->bottommost_y;
            double chord_topmost_y_noacc = chord->topmost_y_noacc;
            double chord_bottommost_y_noacc = chord->bottommost_y_noacc;
            
            if (direction > 0) {
                pt_y = (r_ob->slurs_avoid_accidentals ? chord_topmost_y : chord_topmost_y_noacc) - CONST_SLUR_AVOID_OBJECTS_PAD * r_ob->zoom_y;
            } else {
                pt_y = (r_ob->slurs_avoid_accidentals ? chord_bottommost_y : chord_bottommost_y_noacc) + CONST_SLUR_AVOID_OBJECTS_PAD * r_ob->zoom_y;
            }
            
            // last chord
            if (chord == end) {
                continue;
            }
            /*
             if (chord->topmost_y_noacc + CONST_EPSILON5 < chord->topmost_y) {
             // the topmost point is on an accidental. gotta find its deplacement!
             t_note *nt;
             double topmost = chord->lastnote->center.y;
             double delta_ux_candidate = 0.;
             for (nt = end->firstnote; nt; nt = nt->next) {
             double new_candidate = nt->center.y - note_get_accidental_uascent(r_ob, nt) * r_ob->zoom_y;
             if (new_candidate < topmost) {
             topmost = new_candidate;
             delta_ux_candidate = nt->accidental_stem_delta_ux;
             }
             }
             stem_ux += delta_ux_candidate;
             top_y = topmost - CONST_SLUR_AVOID_LAST_ACCIDENTALS_PAD * r_ob->zoom_y;
             } */
            
            d1 = pt_line_distance_vertical(stem_ux, pt_y, slur->start_ux, slur->start_y, slur->cp2_relx, slur->cp2_y);
            d2 = pt_line_distance_vertical(stem_ux, pt_y, slur->cp1_relx, slur->cp1_y, slur->end_ux, slur->end_y);
            
            // how big is the superposition?
            if (direction > 0) {
                is_good = (d1 < 0 && d2 < 0);
                d = MAX(d1 > 0 ? fabs(d1) : 0, d2 > 0 ? fabs(d2) : 0.);
            } else {
                is_good = (d1 > 0 && d2 > 0);
                d = MAX(d1 < 0 ? fabs(d1) : 0, d2 < 0 ? fabs(d2) : 0.);
            }
            
            // we compute the position of chord between the start chord and the end chord
            s = CLAMP((stem_ux - slur->start_ux)/(slur->end_ux - slur->start_ux), 0., 1.);
            s_used = s;
            //                    s_used = r_ob->slurs_always_symmetrical ? 0.5 : s; // if slurs are always symmetrical, we always modify left side as much as right side
            
            d_step = d/3; //3 must become some CONST_SLUR_AUTOFIND_SHAPE_STEP
            
            while (!is_good && count < MAX_TRIES) {
                // what do we do? We could:
                // A. raise everything;
                // B. shift control points left/right;
                // C. raise control points
                double w_a = 0, w_b = 0, w_c = 0;
                double t1, t2;
                
                // getting weights w_a, w_b, w_c
                w_b = CLAMP(fabs(s-0.5) * 2. * CLAMP(long_base/4000., 0., 1.), 0., 1.);
                if (slur->cp1_relx - d_step * w_b * (1 - s_used) < slur->start_ux ||
                    slur->cp2_relx + d_step * w_b * s_used > slur->end_ux)
                    w_b = 0;
                
                t1 = MAX(raise1_y, raise2_y)/h;
                t2 = MAX(raisestart_y, raiseend_y)/h;
                w_a = (1 - w_b) * CLAMP((t1 - 1)/3. - (t2 - 1)/3. + fabs(s-0.5), 0., 1.);
                w_c = 1 - w_b - w_a;
                
                w_a = 1; w_b = 0; w_c = 0;
                
                // applying A., B., and C.
                if (w_a > 0.) {
                    raisestart_y += d_step * w_a * (1 - s);
                    raiseend_y += d_step * w_a * s;
                    slur->start_y -= d_step * w_a * (1 - s) * direction;
                    slur->end_y -= d_step * w_a * s * direction;
/*                        double d_shift = d_step * w_a * 0.5 * direction;
                    slur->start_y -= d_shift;
                    slur->end_y -= d_shift;
                    slur->cp1_y -= d_shift;
                    slur->cp2_y -= d_shift; */
                }
                
                if (w_b > 0.) {
                    slur->cp1_relx -= d_step * w_b * (1 - s_used);
                    slur->cp2_relx += d_step * w_b * s_used;
                }
                
                if (w_c > 0.) {
                    // we raise the control points
                    raise1_y += d_step * w_c * (1 - s_used);
                    raise2_y += d_step * w_c * s_used;
                    slur->cp1_y -= d_step * w_c * (1 - s_used) * direction;
                    slur->cp2_y -= d_step * w_c * s_used * direction;
                }
                
                // the hull between control points & points must be convex ;-)
/*                    double dd;
                if ((dd = direction * pt_line_distance_vertical(slur->cp2_ux, slur->cp2_y, slur->cp1_ux, slur->cp1_y, slur->end_ux, slur->end_y)) <= 0) {
                    slur->cp2_y += dd;
                } else if ((dd = direction * pt_line_distance_vertical(slur->cp1_ux, slur->cp1_y, slur->start_ux, slur->start_y, slur->cp2_ux, slur->cp2_y)) <= 0) {
                    slur->cp1_y += dd;
                } */
                
                d1 = pt_line_distance_vertical(stem_ux, pt_y, slur->start_ux, slur->start_y, slur->cp2_relx, slur->cp2_y);
                d2 = pt_line_distance_vertical(stem_ux, pt_y, slur->cp1_relx, slur->cp1_y, slur->end_ux, slur->end_y);
                
                if (direction > 0) {
                    is_good = (d1 < 0 && d2 < 0);
                } else {
                    is_good = (d1 > 0 && d2 > 0);
                }
                
                count++;
            }
            if (count == MAX_TRIES) {
                dev_post("Slur couldn't be correctly painted");
            }
        }
    }

    slur->cp1_relx = (slur->cp1_relx - slur->start_ux) / delta_ux;
    slur->cp2_relx = (slur->cp2_relx - slur->start_ux) / delta_ux;

    if (reversed) {
        double temp;
        temp = slur->start_ux; slur->start_ux = slur->end_ux; slur->end_ux = temp;
        temp = slur->start_y; slur->start_y = slur->end_y; slur->end_y = temp;
//            temp = slur->cp1_ux; slur->cp1_ux = slur->cp2_ux; slur->cp2_ux = temp;
        temp = slur->cp1_y; slur->cp1_y = slur->cp2_y; slur->cp2_y = temp;
    }
    slur->need_recompute_position = false;
}





void fill_slur_stuff(t_notation_obj *r_ob, t_slur *slur, double *cp1_ux, double *cp2_ux, double tension, double angleL, double angleR, double distL, double distR, char direction)
{
    *cp1_ux = slur->start_ux + distL * tension * cos(angleL),
    slur->cp1_y = slur->start_y + direction * distL * tension * sin(angleL) * r_ob->zoom_y,
    *cp2_ux = slur->end_ux - distR * tension * cos(angleR),
    slur->cp2_y = slur->end_y - direction * distR * tension * sin(angleR) * r_ob->zoom_y;
    
    
}

double chord_get_extremum_for_slur(t_notation_obj *r_ob, t_chord *chord, char direction)
{
    double pt_y;
    if (direction > 0) {
        pt_y = (r_ob->slurs_avoid_accidentals ? chord_get_topmost_y_notuplets(r_ob, chord) - CONST_SLUR_AVOID_NOTE_WO_ACCIDENTAL_PAD * r_ob->zoom_y : chord_get_topmost_y_noacc(r_ob, chord)) - CONST_SLUR_AVOID_OBJECTS_PAD * r_ob->zoom_y;
    } else {
        pt_y = (r_ob->slurs_avoid_accidentals ? chord_get_bottommost_y_notuplets(r_ob, chord) + CONST_SLUR_AVOID_NOTE_WO_ACCIDENTAL_PAD * r_ob->zoom_y : chord_get_bottommost_y_noacc(r_ob, chord)) + CONST_SLUR_AVOID_OBJECTS_PAD * r_ob->zoom_y;
    }
    return pt_y;
}

double bezier_chord_dist(t_notation_obj *r_ob, t_slur *slur, double cp1_ux, double cp2_ux, t_chord *chord, char direction)
{
    double stem_ux = xposition_to_unscaled_xposition(r_ob, chord->stem_x);
    double pt_y = chord_get_extremum_for_slur(r_ob, chord, direction);
    
    t_pt sampled_pt;
    double t = bezier_x_to_t(build_pt(slur->start_ux, slur->start_y), build_pt(cp1_ux, slur->cp1_y), build_pt(cp2_ux, slur->cp2_y), build_pt(slur->end_ux, slur->end_y), stem_ux, 1, &sampled_pt);
    double bezy = sampled_pt.y; //(1-t)*(1-t)*(1-t)*slur->start_y + 3*t*(1-t)*(1-t)*slur->cp1_y + 3*t*t*(1-t)*slur->cp2_y + t*t*t*slur->end_y;
    return pt_y - bezy;
}

char slur_get_actual_direction(t_slur *slur)
{
    if (slur->direction != 0)
        return slur->direction;
    
    // if direction is automatic, we choose the opposite direction of the starting chord
    if (slur->start_chord && slur->start_chord->firstnote)
        return -slur->start_chord->direction;
    
    // if the starting chord was a rest, we choose the opposite direction of the ending chord
    if (slur->end_chord && slur->end_chord->firstnote)
        return -slur->end_chord->direction;
    
    // if both chords were rests, we chose up!
    return 1;
}

void slur_compute_control_points_methodB(t_notation_obj *r_ob, t_slur *slur)
{
    t_chord *start = slur->start_chord, *end = slur->end_chord;
    char direction = slur_get_actual_direction(slur); //(slur->direction) ? slur->direction : -start->direction;
    double alpha;
    t_chord *chord;
    double raise1_y = 0, raise2_y = 0, raisestart_y = 0, raiseend_y = 0;
    bool for_graces = false;
    
    t_note *start_nt = start->lastnote;
    t_note *end_nt = end->lastnote;
    if (direction < 0) {
        start_nt = start->firstnote;
        end_nt = end->firstnote;
    }

#ifndef BACH_ALLOW_SLURS_ON_RESTS
    if (!end_nt || !start_nt) {
        return;
    }
#endif
    
    if (!end->is_grace_chord && start != end) {
        for_graces = true;
        for (t_chord *ch = start; ch && ch != end; ch = ch->next) {
            if (!ch->is_grace_chord) {
                for_graces = false;
                break;
            }
        }
    }
    
    // standard positioning for start point and end point
    double staff_top_y = voice_get_staff_top_y(r_ob, chord_get_voice(r_ob, start), k_NONSTANDARD_STAFFLINES_TOPBOTTOM_ACCOUNT);
    double staff_bottom_y = voice_get_staff_bottom_y(r_ob, chord_get_voice(r_ob, start), k_NONSTANDARD_STAFFLINES_TOPBOTTOM_ACCOUNT);
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        slur->start_ux = start->parent->tuttipoint_reference->offset_ux + start->stem_offset_ux + (start_nt ? start_nt->notecenter_stem_delta_ux : 0);
        slur->end_ux = end->parent->tuttipoint_reference->offset_ux + end->stem_offset_ux + (end_nt ? end_nt->notecenter_stem_delta_ux : 0);
    } else {
        slur->start_ux = chord_get_stem_ux(r_ob, start) + (start_nt ? start_nt->notecenter_stem_delta_ux : 0);
        slur->end_ux = chord_get_stem_ux(r_ob, end) + (end_nt ? end_nt->notecenter_stem_delta_ux : 0);
    }
    slur->start_y = (start_nt ? start_nt->center.y : (direction > 0 ? staff_top_y : staff_bottom_y))  + 2 * r_ob->step_y * (- direction);
    slur->end_y = (end_nt ? end_nt->center.y : (direction > 0 ? staff_top_y : staff_bottom_y)) + 2 * r_ob->step_y * (- direction);

    // particular cases for start point and end point
    if (direction == -1 && end->direction == -1) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            slur->end_ux = end->parent->tuttipoint_reference->offset_ux + end->stem_offset_ux - CONST_SLUR_USEPARATION_FROM_STEM;
        } else {
            slur->end_ux = chord_get_stem_ux(r_ob, end) - CONST_SLUR_USEPARATION_FROM_STEM;
        }
    } else if (direction == 1 && start->direction == 1) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            slur->start_ux = start->parent->tuttipoint_reference->offset_ux + start->stem_offset_ux + CONST_SLUR_USEPARATION_FROM_STEM;
        } else {
            slur->start_ux = chord_get_stem_ux(r_ob, start) + CONST_SLUR_USEPARATION_FROM_STEM;
        }
    }

    if (slur->start_ux == slur->end_ux) 
        slur->end_ux += 5 * r_ob->zoom_y;

    bool end_chord_not_yet_painted = false;
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        end_chord_not_yet_painted = (end->topmost_y == DBL_SMALLEST);
        const double stem_slur_separation_in_steps = 1.;
        
        if (direction * end->direction == 1 && rat_long_cmp(end->figure, 1) < 0) {
            // if the slur ends on a stem rather than a notehead
            slur->end_ux = xposition_to_unscaled_xposition(r_ob, end->stem_x) - CONST_SLUR_USEPARATION_FROM_STEM;
            double candidate_end_y = 0;
            if (direction == 1)
                candidate_end_y = end_chord_not_yet_painted ? staff_top_y : chord_get_topmost_y_notuplets(r_ob, end) - stem_slur_separation_in_steps * r_ob->step_y;
            else
                candidate_end_y = end_chord_not_yet_painted ? staff_bottom_y :chord_get_bottommost_y_notuplets(r_ob, end) + stem_slur_separation_in_steps * r_ob->step_y;
            if (for_graces) { // nudging for slurs including grace notes
                if ((direction == 1 && candidate_end_y < slur->end_y) ||
                    (direction == -1 && candidate_end_y < slur->end_y)) {
                    // nothing to do
                    slur->end_y = candidate_end_y;
                }
            } else {
                slur->end_y = candidate_end_y;
            }
        }
        if (direction * start->direction == 1 && rat_long_cmp(start->figure, 1) < 0) {
            // if the slur starts on a stem rather than a notehead
            slur->start_ux = xposition_to_unscaled_xposition(r_ob, start->stem_x) + CONST_SLUR_USEPARATION_FROM_STEM;
            if (direction == 1)
                slur->start_y = end_chord_not_yet_painted ? staff_top_y : chord_get_topmost_y_notuplets(r_ob, start) - stem_slur_separation_in_steps * r_ob->step_y;
            else
                slur->start_y = end_chord_not_yet_painted ? staff_bottom_y : chord_get_bottommost_y_notuplets(r_ob, start) + stem_slur_separation_in_steps * r_ob->step_y;
        }
    }
    
    // nudging end point if the chord has an accidental
//    fill_topmost_bottommost_fields(r_ob, end, staff_top_y);
    if (r_ob->slurs_avoid_accidentals) {
        if (direction > 0) {
            double chord_topmost_noacc = end_chord_not_yet_painted ? staff_top_y : chord_get_topmost_y_noacc(r_ob, end);
            double chord_topmost_notuplets = end_chord_not_yet_painted ? staff_top_y : chord_get_topmost_y_notuplets(r_ob, end);
            if (!end_chord_not_yet_painted && chord_get_topmost_y_noacc(r_ob, end) - CONST_EPSILON5 > chord_get_topmost_y_notuplets(r_ob, end)) {
                slur->end_y -= (chord_topmost_noacc - chord_topmost_notuplets);
            }
        } else {
            double chord_bottommost_noacc = end_chord_not_yet_painted ? staff_bottom_y : chord_get_bottommost_y_noacc(r_ob, end);
            double chord_bottommost_notuplets = end_chord_not_yet_painted ? staff_bottom_y :chord_get_bottommost_y_notuplets(r_ob, end);
            if (!end_chord_not_yet_painted &&chord_bottommost_noacc + CONST_EPSILON5 < chord_bottommost_notuplets) {
                slur->end_y += (chord_bottommost_notuplets - chord_bottommost_noacc);
            }
        }
    }


    // calculating standard control points
    double delta_ux = slur->end_ux - slur->start_ux;
    double delta_x = deltauxpixels_to_deltaxpixels(r_ob, delta_ux);
    double delta_y = slur->end_y - slur->start_y;
    double long_base = sqrt(delta_x * delta_x + delta_y * delta_y);
    alpha = fabs(atan(-delta_y/delta_x));

    double cp1_x = 0, cp2_x = 0;
    double cp1_ux = 0, cp2_ux = 0;

    // first, setting a simple case
    {
/*        double a = long_base * CLAMP(0.3 - 0.12 * long_base/400., 0.18, 0.3);
        double b = long_base - a;
        double h = CLAMP(CONST_SLUR_MIN_UHEIGHT + (CONST_SLUR_MAX_UHEIGHT - CONST_SLUR_MIN_UHEIGHT) * long_base/400., CONST_SLUR_MIN_UHEIGHT, CONST_SLUR_MAX_UHEIGHT) * r_ob->zoom_y;
        
        if ((direction == 1 && slur->end_y <= slur->start_y) || (direction == -1 && slur->end_y >= slur->start_y)) {
            cp1_ux = a * cos(alpha) - h * sin(alpha);
            slur->cp1_y = (cp1_ux * tan(alpha) + h / cos(alpha)) * (- direction);
            cp2_ux = b * cos(alpha) - h * sin(alpha);
            slur->cp2_y = (cp2_ux * tan(alpha) + h / cos(alpha)) * (- direction);
        } else { */
        /*            cp1_ux = a / cos(alpha) + (h - a*tan(alpha)) * sin(alpha);
                    slur->cp1_y = (h - a*tan(alpha)) * cos(alpha) * (- direction);
                    cp2_ux = b / cos(alpha) + (h - b*tan(alpha)) * sin(alpha);
                    slur->cp2_y = (h - b*tan(alpha)) * cos(alpha) * (- direction);*/
        //        }

        double L = 0.2 * long_base;
        double H = direction * CLAMP(CONST_SLUR_MIN_UHEIGHT + (CONST_SLUR_MAX_UHEIGHT - CONST_SLUR_MIN_UHEIGHT) * delta_ux/400., CONST_SLUR_MIN_UHEIGHT, CONST_SLUR_MAX_UHEIGHT) * r_ob->zoom_y;
        double slur_start_x = unscaled_xposition_to_xposition(r_ob, slur->start_ux);
        double slur_end_x = unscaled_xposition_to_xposition(r_ob, slur->end_ux);
        double cp1_y, cp2_y;
        
        double angle1 = alpha * (slur->end_y >= slur->start_y ? -1 : 1);
        double add_x = L * cos(angle1) - H * sin(angle1);
        double add_y = L * sin(angle1) + H * cos(angle1);
        cp1_x = slur_start_x + add_x;
        cp1_y = slur->start_y - add_y;
        
        double angle2 = alpha * (slur->end_y >= slur->start_y ? 1 : -1);
        add_x = L * cos(angle2) - H * sin(angle2);
        add_y = L * sin(angle2) + H * cos(angle2);
        cp2_x = slur_end_x - add_x;
        cp2_y = slur->end_y - add_y;

        cp1_ux = xposition_to_unscaled_xposition(r_ob, cp1_x);
        cp2_ux = xposition_to_unscaled_xposition(r_ob, cp2_x);
        slur->cp1_y = cp1_y;
        slur->cp2_y = cp2_y;
    }
    
    bool done = true;
    if (r_ob->slurs_avoid_chords) {
        
        for (chord = chord_get_next(start); chord && chord != end; chord = chord_get_next(chord)) {
            double d = bezier_chord_dist(r_ob, slur, cp1_ux, cp2_ux, chord, direction);
            if (direction * d < 0) {
                done = false;
                break;
            }
        }

        
        
        if (!done) {
            
            
            // final distance and angles for the control points
            //        double distL = 0, distR = 0, angleL = 0, angleR = 0;
            const double DEFAULT_REL_DISTANCE = 0.4;
            const double DEFAULT_ANGLE = rescale(CLAMP(delta_ux, 60, 1000), 5, 100, 20, 10) * PI/180.; // between 20° and 5°
            const double ANGLE_DIL_FACTOR = 2.;
            const double DEFAULT_TENSION = 0.5, MAX_TENSION = 1.1;
            
            double distL = DEFAULT_REL_DISTANCE * delta_ux, distR = DEFAULT_REL_DISTANCE * delta_ux;
            double angleL = -DEFAULT_ANGLE, angleR = DEFAULT_ANGLE;
            double middle_ux = 0.5 * (slur->start_ux + slur->end_ux);
            t_chord *middle = NULL;
            long num_chords_under_slur = 0;
            for (chord = chord_get_next(start); chord && chord_get_prev(chord) != end; chord = chord_get_next(chord)) {
                double stem_ux = xposition_to_unscaled_xposition(r_ob, chord->stem_x);
                if (stem_ux <= middle_ux) {
                    middle = chord;
                } else {
                    if (!middle)
                        middle = chord;
                    break;
                }
            }
            
            if (middle == start && middle->next != end)
                middle = middle->next;
            else if (middle == end && middle->prev != start)
                middle = middle->prev;
            
            if (middle) {
                
                // finding smallest angle in the first half of the
                for (chord = chord_get_next(start); chord && chord_get_prev(chord) != middle; chord = chord_get_next(chord)) {
                    double chord_stem_ux = xposition_to_unscaled_xposition(r_ob, chord->stem_x);
                    double dx = chord_stem_ux - slur->start_ux;
                    double dy = chord_get_extremum_for_slur(r_ob, chord, direction) - slur->start_y;
/*                    double dy;
                    if (direction >= 0)
                        dy = (r_ob->slurs_avoid_accidentals ? chord_get_topmost_y_notuplets(r_ob, chord) : chord_get_topmost_y_noacc(r_ob, chord)) - slur->start_y;
                    else
                        dy = (r_ob->slurs_avoid_accidentals ? chord_get_bottommost_y_notuplets(r_ob, chord) : chord_get_bottommost_y_noacc(r_ob, chord)) - slur->start_y;*/
                    
                    
                    double dist = sqrt(dx*dx + dy*dy);
                    double angle = atan2(direction * dy, dx);
                    
                    if (angle < angleL) {
                        angleL = angle;
                        distL = dist;
                    }
                }
                
                angleL *= ANGLE_DIL_FACTOR;
                
                if (angleL < -PIOVERTWO)
                    angleL = -PIOVERTWO;
                
                for (chord = chord_get_prev(end); chord && chord && chord_get_next(chord) != middle; chord = chord_get_prev(chord)) {
                    double chord_stem_ux = xposition_to_unscaled_xposition(r_ob, chord->stem_x);
                    double dx = chord_stem_ux - slur->end_ux;
                    double dy = chord_get_extremum_for_slur(r_ob, chord, direction) - slur->end_y;
/*                    double dy;
                    if (direction >= 0)
                        dy = (r_ob->slurs_avoid_accidentals ? chord_get_topmost_y_notuplets(r_ob, chord) : chord_get_topmost_y_noacc(r_ob, chord)) - slur->end_y;
                    else
                        dy = (r_ob->slurs_avoid_accidentals ? chord_get_bottommost_y_notuplets(r_ob, chord) : chord_get_bottommost_y_noacc(r_ob, chord)) - slur->end_y;*/
                    
                    double dist = sqrt(dx*dx + dy*dy);
                    double angle = atan2(-direction * dy, -dx);
                    
                    if (angle > angleR) {
                        angleR = angle;
                        distR = dist;
                    }
                }
                
                angleR *= ANGLE_DIL_FACTOR;
                
                if (angleR > PIOVERTWO)
                    angleR = PIOVERTWO;
                
                double tens = DEFAULT_TENSION;
                fill_slur_stuff(r_ob, slur, &cp1_ux, &cp2_ux, tens, angleL+alpha, angleR+alpha, distL, distR, direction);
                //            cp1_ux = slur->start_ux + distL * tens * cos(angleL + alpha),
                //            slur->cp1_y = slur->start_y + distL * tens * sin(angleL + alpha),
                //            cp2_ux = slur->end_ux - distR * tens * cos(angleR + alpha),
                //            slur->cp2_y = slur->end_y - distR * tens * sin(angleR + alpha);
                
                
                // now this could still lead to collisions, so we check
                //            const long MAX_TRIES = 20;
                for (chord = chord_get_next(start); chord && chord != end; chord = chord_get_next(chord)) {
                    double d = bezier_chord_dist(r_ob, slur, cp1_ux, cp2_ux, chord, direction);
                    bool must_fix = (direction * d < 0);
                    
                    if (must_fix) {
                        // first, we try to increase the tension a bit (combined with a small shift
                        while (tens < MAX_TENSION && must_fix) {
                            
                            // increase tension
                            tens += 0.1;
                            
                            // and shift up slightly
                            slur->start_y += d/3.;
                            slur->end_y += d/3.;
                            
                            fill_slur_stuff(r_ob, slur, &cp1_ux, &cp2_ux, tens, angleL+alpha, angleR+alpha, distL, distR, direction);
                            
                            d = bezier_chord_dist(r_ob, slur, cp1_ux, cp2_ux, chord, direction);
                            must_fix = (direction * d < 0);
                        }
                        
                        
                        if (must_fix) {
                            // finally, just raise
                            d = bezier_chord_dist(r_ob, slur, cp1_ux, cp2_ux, chord, direction);

                            if (direction * d < 0) { // must correct
                                double d_step = d + (d > 0 ? 1 : -1) * CONST_SLUR_AVOID_OBJECTS_PAD;
                                double stem_ux = xposition_to_unscaled_xposition(r_ob, chord->stem_x);
                                double s = CLAMP((stem_ux - slur->start_ux)/delta_ux, 0., 1.);
                                
                                slur->start_y += d_step * (1 - s);
                                slur->end_y += d_step * s;
                                
                                fill_slur_stuff(r_ob, slur, &cp1_ux, &cp2_ux, tens, angleL+alpha, angleR+alpha, distL, distR, direction);
                            }
                        }
                    }
                }
                
                //                    if (triangle_get_orientation(build_pt(slur->start_ux, slur->start_y), build_pt(cp1_ux, slur->cp1_y), build_pt(cp2_ux, slur->cp2_y)) > 0) {

                // ensure convexity
                if (pt_line_distance_vertical_signed(cp1_ux, slur->cp1_y, slur->start_ux, slur->start_y, cp2_ux, slur->cp2_y) * direction > 0) {
                    slur->cp1_y = rescale(cp1_ux, slur->start_ux, cp2_ux, slur->start_y, slur->cp2_y);
                }
                if (pt_line_distance_vertical_signed(cp2_ux, slur->cp2_y, cp1_ux, slur->cp1_y, slur->end_ux, slur->end_y) * direction > 0) {
                    slur->cp2_y = rescale(cp2_ux, cp1_ux, slur->end_ux, slur->cp1_y, slur->end_y);
                }

                done = true;
            }
        }
    }
    
    
    slur->cp1_relx = (cp1_ux - slur->start_ux) / delta_ux;
    slur->cp2_relx = (cp2_ux - slur->start_ux) / delta_ux;

    slur->need_recompute_position = false;
}
