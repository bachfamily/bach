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

        }
    }
}


t_slur *slur_add(t_notation_obj *r_ob, t_chord *start_ch, t_chord *end_ch, t_llll *names)
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

t_slur *slur_add_temporary(t_notation_obj *r_ob, t_chord *start_ch, long extension)
{
    t_slur *this_slur = (t_slur *)bach_newptr(sizeof(t_slur));
    
    notation_item_init(&this_slur->r_it, k_SLUR);
    
    this_slur->is_temporary = true;
    this_slur->temporary_extension = extension;
    this_slur->start_chord = start_ch;
    this_slur->direction = 0; // undefined: use standard
    this_slur->end_chord = NULL;
    slur_set_recompute_position_flag(this_slur);

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
            slur_add(r_ob, tempslur->start_chord, endchord, names);
            llll_free(names);
        }
        notation_item_free((t_notation_item *)tempslur);
        bach_freeptr(tempslur);
    }
    llll_clear(r_ob->slurs_to_be_processed);
}

t_slur *slur_add_for_selection(t_notation_obj *r_ob, t_llll *names, char add_undo_ticks)
{
    t_note *left = get_leftmost_selected_note(r_ob);
    t_note *right = get_rightmost_selected_note(r_ob);
    if (left && right && left->parent != right->parent) {
        if (add_undo_ticks)
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)left->parent, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
        t_slur *slur = slur_add(r_ob, left->parent, right->parent, names);
        return slur;
    }
    return NULL;
}

void slur_change_starting_chord(t_notation_obj *r_ob, t_slur *slur, t_chord *newchord, bool add_undo_ticks)
{
    if (notation_item_get_voicenumber(r_ob, (t_notation_item *)slur->start_chord) !=
        notation_item_get_voicenumber(r_ob, (t_notation_item *)newchord)) {
        object_error((t_object *)r_ob, "bach currently does not support cross-voice slurs");
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
        object_error((t_object *)r_ob, "bach currently does not support cross-voice slurs");
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
        t_chord *temp = direction > 0 ? chord_get_next(newchord) : chord_get_prev(newchord);
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


t_llll *chord_get_slurs_as_llll(t_chord *ch, char prepend_slur_symbol)
{
    t_llll *out = llll_get();
    if (prepend_slur_symbol)
        llll_appendsym(out, _llllobj_sym_slur);
    if (ch) {
        for (long i = 0; i < ch->num_slurs_to; i++) {
            if (ch->slur_to[i]->r_it.names && ch->slur_to[i]->r_it.names->l_size > 0) {
                t_llll *subll = llll_get();
                llll_appendlong(subll, slur_get_length_in_chords(ch->slur_to[i]));
                llll_appendllll(subll, get_names_as_llll((t_notation_item *)ch->slur_to[i], true));
                llll_appendllll(out, subll);
            } else {
                llll_appendlong(out, slur_get_length_in_chords(ch->slur_to[i]));
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
    t_llll *ll = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    llll_parseargs_and_attrs_destructive((t_object *)r_ob, ll, "l", gensym("name"), &names);

    if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_selection) {
        // add a slur for the selection
        slur_add_for_selection(r_ob, names, true);
    } else if (ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_LLLL &&  hatom_gettype(&ll->l_head->l_next->l_hatom) == H_LLLL){
        t_notation_item_path start_path, end_path;
        notation_item_path_from_llll(r_ob, k_CHORD, hatom_getllll(&ll->l_head->l_hatom), &start_path);
        notation_item_path_from_llll(r_ob, k_CHORD, hatom_getllll(&ll->l_head->l_next->l_hatom), &end_path);
        if (start_path.chord_num != -1 && end_path.chord_num != -1) {
            t_chord *start_ch = (t_chord *)notation_item_from_path(r_ob, k_CHORD, &start_path);
            t_chord *end_ch = (t_chord *)notation_item_from_path(r_ob, k_CHORD, &end_path);
            if (start_ch && end_ch) {
                slur_add(r_ob, start_ch, end_ch, names);
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
