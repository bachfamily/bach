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



t_slur *slur_add(t_notation_obj *r_ob, t_chord *start_ch, t_chord *end_ch)
{
    if (start_ch->num_slurs_to < CONST_MAX_SLURS_PER_CHORD && end_ch->num_slurs_from < CONST_MAX_SLURS_PER_CHORD) {
        t_slur *this_slur = (t_slur *)bach_newptr(sizeof(t_slur));
        
        notation_item_init(&this_slur->r_it, k_SLUR);
        
        this_slur->is_temporary = false;
        this_slur->temporary_extension = 0;
        this_slur->start_chord = start_ch;
        this_slur->direction = 0; // undefined: use standard
        this_slur->end_chord = end_ch;
        start_ch->slur_to[start_ch->num_slurs_to++] = this_slur;
        end_ch->slur_from[end_ch->num_slurs_from++] = this_slur;
        this_slur->need_recompute_position = true;
        return this_slur;
    } else {
        object_error((t_object *)r_ob, "Too many slurs start or end from a single chord.");
    }
    return NULL;
}

t_slur *slur_add_temporary(t_notation_obj *r_ob, t_chord *start_ch, long extension)
{
    t_slur *this_slur = (t_slur *)bach_newptr(sizeof(t_slur));
    
    notation_item_init(&this_slur->r_it, k_SLUR);
    
    this_slur->is_temporary = true;
    this_slur->temporary_extension = extension;
    this_slur->start_chord = start_ch;
    this_slur->direction = 0; // undefined: use standard
    this_slur->end_chord = NULL;
    this_slur->need_recompute_position = true;
    
    llll_appendobj(r_ob->slurs_to_be_processed, this_slur);
    return NULL;
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
            slur_add(r_ob, tempslur->start_chord, endchord);
        }
        bach_freeptr(tempslur);
    }
    llll_clear(r_ob->slurs_to_be_processed);
}

t_slur *slur_add_for_selection(t_notation_obj *r_ob, char add_undo_ticks)
{
    t_note *left = get_leftmost_selected_note(r_ob);
    t_note *right = get_rightmost_selected_note(r_ob);
    if (left && right && left->parent != right->parent) {
        if (add_undo_ticks)
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)left->parent, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
        return slur_add(r_ob, left->parent, right->parent);
    }
    return NULL;
}

void slur_change_starting_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *newchord)
{
    long i = 0;
    if (newchord->num_slurs_to < CONST_MAX_SLURS_PER_CHORD - 1) {
        while (i < slur->start_chord->num_slurs_to) {
            if (slur->start_chord->slur_to[i] == slur) {
                long j;
                for (j = i+1; j < slur->start_chord->num_slurs_to; j++)
                    slur->start_chord->slur_to[j-1] = slur->start_chord->slur_to[j];
                slur->start_chord->num_slurs_to--;
            } else
                i++;
        }
        
        newchord->slur_to[newchord->num_slurs_to] = slur;
        newchord->num_slurs_to++;
        
        slur->start_chord = newchord;
        slur->need_recompute_position = true;
    }
}

void slur_change_ending_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *newchord)
{
    long i = 0;
    if (newchord->num_slurs_from < CONST_MAX_SLURS_PER_CHORD - 1) {
        while (i < slur->end_chord->num_slurs_from) {
            if (slur->end_chord->slur_to[i] == slur) {
                long j;
                for (j = i+1; j < slur->end_chord->num_slurs_from; j++)
                    slur->end_chord->slur_from[j-1] = slur->end_chord->slur_from[j];
                slur->end_chord->num_slurs_from--;
            } else
                i++;
        }
        
        newchord->slur_from[newchord->num_slurs_from] = slur;
        newchord->num_slurs_from++;
        
        slur->end_chord = newchord;
        slur->need_recompute_position = true;
    }
}


void slur_delete(t_notation_obj *r_ob, t_slur *slur)
{
    long i;
    if (slur) {
        t_chord *start = slur->start_chord;
        t_chord *end = slur->end_chord;
        
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
        
        bach_freeptr(slur);
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
            notation_item_delete_from_selection(r_ob, (t_notation_item *)slur); // to be 100% sure, we delete all stuff
            slur_delete(r_ob, slur);
            curr_it = temp;
        } else {
            curr_it = curr_it->next_selected;
        }
    }
    unlock_general_mutex(r_ob);
    return changed;
}




void notationobj_reset_all_slurs_position(t_notation_obj *r_ob)
{
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice))
        for (t_chord *chord = voice_get_first_chord(r_ob, voice); chord; chord = chord_get_next(chord)) {
            for (long i = 0; i < chord->num_slurs_to; i++)
                chord->slur_to[i]->need_recompute_position = true;
            for (long i = 0; i < chord->num_slurs_from; i++)
                chord->slur_from[i]->need_recompute_position = true;
        }
}

void chord_reset_slur_positions(t_chord *ch)
{
    for (long j = 0; j < ch->num_slurs_to; j++)
        ch->slur_to[j]->need_recompute_position = true;
    for (long j = 0; j < ch->num_slurs_from; j++)
        ch->slur_from[j]->need_recompute_position = true;
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


t_llll *chord_get_slurs_as_llll(t_chord *ch, char prepend_slur_symbol)
{
    t_llll *out = llll_get();
    if (prepend_slur_symbol)
        llll_appendsym(out, _llllobj_sym_slur);
    if (ch) {
        for (long i = 0; i < ch->num_slurs_to; i++)
            llll_appendlong(out, slur_get_length_in_chords(ch->slur_to[i]));
    }
    return out;
}
