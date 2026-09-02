/*
 *  notation_commons.c
 *
 * Copyright (C) 2010-2025 Andrea Agostini and Daniele Ghisi
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
    notation_commons.c - common functions (or useful functions) for notation objects
*/

#include "foundation/bach.h"
#include "notation/notation.h" // header with all the structures for the notation objects
#include "notation/notation_undo.h"
#include "notation/notation_markers.h"
#include "notation/notation_slurs.h"

//#include "graphics/llll_modifiers.h" 
//#include "math/llll_math.h"




long notationobj_get_playout(t_notation_obj *r_ob)
{
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
        return 7;
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
        return 6;
    
    return 1;
}

void notationobj_task_chain_deferlow(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    if (r_ob->playing) {
        r_ob->play_step_count = r_ob->play_num_steps;
        defer_low(r_ob, (method)notationobj_task_gimme, NULL, 0, NULL);
        defer_low(r_ob, (method)notationobj_task_chain_deferlow, NULL, 0, NULL);
    }
}

void notationobj_task_gimme(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    notationobj_task(r_ob);
}


void notationobj_task(t_notation_obj *r_ob)
{
// clock activation.
// Time is not spanned uniformously from beginning to end, cause we want to have great precision on each note!
// So, each interval (from note to note) is divided into x->r_ob.play_num_steps steps, when we get to the last one, we compute the next note values.

    long playout_num = notationobj_get_playout(r_ob);

    r_ob->play_head_ms += r_ob->play_step_ms;
    r_ob->play_step_count++;

    if (r_ob->highlight_played_notes)
        check_unplayed_notes(r_ob, r_ob->play_head_ms);

    if (r_ob->playhead_notify_during_playback) {
        send_playhead_position(r_ob, playout_num);
    }

    if (r_ob->play_step_count < r_ob->play_num_steps) {

        // we haven't reached the next event: we just redraw the playline

        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            lock_general_mutex(r_ob);
            r_ob->play_head_ux = ms_to_unscaled_xposition(r_ob, r_ob->play_head_ms, 1);
            unlock_general_mutex(r_ob);
        }

        lock_general_mutex(r_ob);
        r_ob->play_head_ux = ms_to_unscaled_xposition(r_ob, r_ob->play_head_ms, 1);
        unlock_general_mutex(r_ob);
        
        setclock_fdelay(r_ob->setclock->s_thing, r_ob->m_clock, r_ob->play_step_ms);

        if (r_ob->theoretical_play_step_ms > 0) {
            if ((r_ob->obj_type == k_NOTATION_OBJECT_SCORE &&
                 ((r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_PAGES && r_ob->force_inscreen_ux_rolling_function((t_object *)r_ob, r_ob->play_head_ux, 0, true, false)) ||
                  (r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_FIXPOS && r_ob->force_inscreenpos_ux_function((t_object *)r_ob, r_ob->playhead_fixed_pos, r_ob->play_head_ux, true, false)))) ||
                (r_ob->obj_type == k_NOTATION_OBJECT_ROLL &&
                 ((r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_PAGES && r_ob->force_inscreen_ms_rolling_function((t_object *)r_ob, r_ob->play_head_ms, 0, true, false, false)) ||
                  (r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_FIXPOS && r_ob->force_inscreenpos_ms_function((t_object *)r_ob, r_ob->playhead_fixed_pos, r_ob->play_head_ms, true, false, false)))))
            {
                notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
            }

            notationobj_redraw(r_ob);
        }
    
    } else {
        
        // we have reached the next scheduled event
        
        lock_general_mutex(r_ob);

        if (r_ob->scheduled_item) {
            
            char scheduled_item_type = r_ob->scheduled_item->type;
            t_voice *voice;
            t_notation_item *nextitemtoplay = NULL; 
            t_chord *temp_ch;
            t_marker *marker;
            t_tempo *tempo;
            t_measure *measure;
            long count = 0, i;
            double last_scheduled_ms, nextitemtoplay_onset = 0;
            long max_chord_per_scheduler_tick = MAX(r_ob->max_num_chord_per_scheduler_event, 1);
            t_notation_item **items_to_send = (t_notation_item **) bach_newptr(max_chord_per_scheduler_tick * sizeof(t_notation_item *));

            t_llll *to_send = llll_get();
            t_llll *to_send_references = llll_get();
            char is_notewise = true;


            // finding synchronous items
            if (scheduled_item_type == k_CHORD || scheduled_item_type == k_MARKER || scheduled_item_type == k_MEASURE || scheduled_item_type == k_TEMPO) {
                
                items_to_send[0] = r_ob->scheduled_item;
                
                if (items_to_send[0]->type == k_CHORD) {
                    long voice_num = CLAMP(chord_get_voice(r_ob, (t_chord *)items_to_send[0])->number, 0, CONST_MAX_VOICES - 1);
                    r_ob->chord_play_cursor[voice_num] = (t_chord *)items_to_send[0];
                    
                    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                        if (r_ob->play_mode == k_PLAYMODE_CHORDWISE && !r_ob->play_tied_elements_separately && chord_is_all_tied_to(r_ob, (t_chord *)items_to_send[0], false, NULL)) {
                            r_ob->chord_play_cursor[voice_num] = chord_get_last_in_tieseq((t_chord *)items_to_send[0]);
                        }
                    }
                    
                } else if (items_to_send[0]->type == k_TEMPO) { // for bach.score only
                    long voice_num = CLAMP(((t_tempo *)items_to_send[0])->owner->voiceparent->v_ob.number, 0, CONST_MAX_VOICES - 1);
                    r_ob->tempo_play_cursor[voice_num] = (t_tempo *)items_to_send[0];
                } else if (items_to_send[0]->type == k_MEASURE) { // for bach.score only
                    long voice_num = CLAMP(((t_measure *)items_to_send[0])->voiceparent->v_ob.number, 0, CONST_MAX_VOICES - 1);
                    r_ob->measure_play_cursor[voice_num] = (t_measure *)items_to_send[0];
                } else if (items_to_send[0]->type == k_MARKER) {
                    r_ob->marker_play_cursor = (t_marker *)items_to_send[0];
                }

                count = 1; 

                if (r_ob->play_markers) {
                    for (marker = r_ob->marker_play_cursor ? r_ob->marker_play_cursor->next : r_ob->firstmarker;
                         marker && count < r_ob->max_num_chord_per_scheduler_event; marker = marker->next) {
                        if (should_element_be_played(r_ob, (t_notation_item *)marker)) {
                            if (marker->position_ms == r_ob->scheduled_ms) {
                                if (count < max_chord_per_scheduler_tick)
                                    items_to_send[count++] = (t_notation_item *)marker;
                                r_ob->marker_play_cursor = marker;
                            } else if (marker->position_ms > r_ob->scheduled_ms) {
                                break;
                            }
                        }
                    }
                }
                
                if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                    if (r_ob->play_measures) {
                        for (voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices && count < r_ob->max_num_chord_per_scheduler_event; voice = voice_get_next(r_ob, voice)){
                            for (measure = r_ob->measure_play_cursor[voice->number] ? measure_get_next(r_ob->measure_play_cursor[voice->number]) : ((t_scorevoice *)voice)->firstmeasure;
                                measure && count < r_ob->max_num_chord_per_scheduler_event; measure = measure_get_next(measure)){
                                
                                if (should_element_be_played(r_ob, (t_notation_item *)measure)){
                                    double measure_onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)measure);
                                    if (measure_onset == r_ob->scheduled_ms) {
                                        if (count < max_chord_per_scheduler_tick)
                                            items_to_send[count++] = (t_notation_item *)measure;
                                        r_ob->measure_play_cursor[voice->number] = measure;
                                    } else if (measure_onset > r_ob->scheduled_ms) {
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    if (r_ob->play_tempi) {
                        for (voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices && count < r_ob->max_num_chord_per_scheduler_event; voice = voice_get_next(r_ob, voice)){
                            for (tempo = r_ob->tempo_play_cursor[voice->number] ? tempo_get_next(r_ob->tempo_play_cursor[voice->number]) : (((t_scorevoice *)voice)->firstmeasure ? ((t_scorevoice *)voice)->firstmeasure->firsttempo : NULL);
                                tempo && count < r_ob->max_num_chord_per_scheduler_event; tempo = tempo_get_next(tempo)){
                                
                                if (should_element_be_played(r_ob, (t_notation_item *)tempo)){
                                    if (tempo->onset == r_ob->scheduled_ms) {
                                        if (count < max_chord_per_scheduler_tick)
                                            items_to_send[count++] = (t_notation_item *)tempo;
                                        r_ob->tempo_play_cursor[voice->number] = tempo;
                                    } else if (tempo->onset > r_ob->scheduled_ms) {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                for (voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices && count < r_ob->max_num_chord_per_scheduler_event; voice = voice_get_next(r_ob, voice)){
                    for (temp_ch = r_ob->chord_play_cursor[voice->number] ? 
                            chord_get_next(r_ob->chord_play_cursor[voice->number]) : 
                            (r_ob->obj_type == k_NOTATION_OBJECT_SCORE ?
                                (((t_scorevoice *)voice)->firstmeasure ? ((t_scorevoice *)voice)->firstmeasure->firstchord : NULL) :
                                 (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ?
                                    (((t_rollvoice *)voice)->firstchord ? ((t_rollvoice *)voice)->firstchord : NULL) :
                                    NULL));
                         temp_ch && count < r_ob->max_num_chord_per_scheduler_event; temp_ch = chord_get_next(temp_ch)){
                        
                        if (should_element_be_played(r_ob, (t_notation_item *)temp_ch)){
                            if (temp_ch->onset == r_ob->scheduled_ms) {
                                if (count < max_chord_per_scheduler_tick)
                                    items_to_send[count++] = (t_notation_item *)temp_ch;
                                r_ob->chord_play_cursor[voice->number] = temp_ch;
                                
                                if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                                    if (r_ob->play_mode == k_PLAYMODE_CHORDWISE && !r_ob->play_tied_elements_separately && chord_is_all_tied_to(r_ob, temp_ch, false, NULL)) {
                                        r_ob->chord_play_cursor[voice->number] = temp_ch = chord_get_last_in_tieseq(temp_ch);
                                    }
                                }
                            } else if (temp_ch->onset > r_ob->scheduled_ms) {
                                break;
                            }
                        }
                    }
                }
            }
            
            // we now have to find the next item to schedule
            if (r_ob->playing_scheduling_type == k_SCHEDULING_STANDARD && scheduled_item_type == k_LOOP_END) {
                // looping: setting the chord_play_cursor, measure_play_cursor and tempo_play_cursor to NULL for every voice
                for (i = 0; i < r_ob->num_voices; i++) {
                    r_ob->chord_play_cursor[i] = NULL;
                    r_ob->tempo_play_cursor[i] = NULL;
                    r_ob->measure_play_cursor[i] = NULL;
                }
                r_ob->marker_play_cursor = NULL;
                
                // we reset the start play time, and we set the starting playhead position to the loop start position 
                setclock_getftime(r_ob->setclock->s_thing, &r_ob->start_play_time);
                if (r_ob->play_head_start_ms != r_ob->loop_region.start.position_ms) {
                    r_ob->play_head_start_ms = r_ob->loop_region.start.position_ms; 
                    r_ob->play_head_start_ux = ms_to_unscaled_xposition(r_ob, r_ob->loop_region.start.position_ms, 1);
                }
                
                last_scheduled_ms = r_ob->loop_region.start.position_ms;
                r_ob->play_head_ms = last_scheduled_ms;
                r_ob->dont_schedule_loop_start = false;
            } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && r_ob->playing_scheduling_type == k_SCHEDULING_STANDARD && scheduled_item_type == k_MEASURE_END_BARLINE) {
                // scheduling repeat jump
                // gotta find the position we jump to
                t_measure *owner = ((t_measure_end_barline *)r_ob->scheduled_item)->owner;
                double teleport_to_ms = 0;
                for (t_measure *m = owner ? owner->prev : NULL; m; m = m->prev) {
                    if (m->end_barline->barline_type == k_BARLINE_REPEAT_START || m->end_barline->barline_type == k_BARLINE_REPEAT_END_AND_START) {
                        teleport_to_ms = notation_item_get_onset_ms_accurate(r_ob, (t_notation_item *)m->next);
                        break;
                    }
                }
                
                // increase count
                t_measure_end_barline *barline = (t_measure_end_barline *)r_ob->scheduled_item;
                barline->repeat_count = positive_mod(barline->repeat_count + 1, MAX(1, barline->repeat_num));
                
                // repeat: setting the chord_play_cursor, measure_play_cursor and tempo_play_cursor to NULL for every voice
                for (i = 0; i < r_ob->num_voices; i++) {
                    r_ob->chord_play_cursor[i] = NULL;
                    r_ob->tempo_play_cursor[i] = NULL;
                    r_ob->measure_play_cursor[i] = NULL;
                }
                r_ob->marker_play_cursor = NULL;
                
                // we reset the start play time, and we set the starting playhead position to the loop start position
                setclock_getftime(r_ob->setclock->s_thing, &r_ob->start_play_time);
                if (r_ob->play_head_start_ms != teleport_to_ms) {
                    if (r_ob->play_head_reset_start_ms_when_play_ends < 0) {
                        r_ob->play_head_reset_start_ms_when_play_ends = r_ob->play_head_start_ms;
                    }
                    r_ob->play_head_start_ms = teleport_to_ms;
                    r_ob->play_head_start_ux = ms_to_unscaled_xposition(r_ob, teleport_to_ms, 1);
                }
                
                last_scheduled_ms = teleport_to_ms;
                r_ob->play_head_ms = last_scheduled_ms;
//                x->r_ob.dont_schedule_loop_start = false;
                
            } else {
                last_scheduled_ms = r_ob->scheduled_ms;
                if (scheduled_item_type == k_LOOP_START)
                    r_ob->dont_schedule_loop_end = false;
            }
            
            nextitemtoplay = get_next_item_to_play(r_ob, last_scheduled_ms);
            if (nextitemtoplay)
                nextitemtoplay_onset = notation_item_get_onset_ms(r_ob, nextitemtoplay);
                
            #ifdef BACH_PLAY_DEBUG
                if (nextitemtoplay)
                    post("Next item to play has onset: %.2f ms", nextitemtoplay_onset);
            #endif
            
            if (r_ob->play_head_fixed_end_ms > 0 && nextitemtoplay && nextitemtoplay_onset >= r_ob->play_head_fixed_end_ms)
                nextitemtoplay = NULL;            
            
            // loop start must be scheduled once: if we schedule loop start, then we schedule a chord falling ON the loop start, we don't want next item to be the loop start again
            // we check if we can resume scheduling the loop start or end
            if (r_ob->dont_schedule_loop_start && r_ob->loop_region.start.position_ms != nextitemtoplay_onset)
                r_ob->dont_schedule_loop_start = false;
            if (r_ob->dont_schedule_loop_start && r_ob->loop_region.start.position_ms != nextitemtoplay_onset)
                r_ob->dont_schedule_loop_end = false;

            // we schedule the next item
            r_ob->scheduled_ms = nextitemtoplay ? nextitemtoplay_onset : 
                (r_ob->play_head_fixed_end_ms > 0 ? r_ob->play_head_fixed_end_ms : (r_ob->obj_type == k_NOTATION_OBJECT_SCORE ? r_ob->length_ms : r_ob->length_ms_till_last_note));
            if (r_ob->theoretical_play_step_ms <= 0){
                // just one step per scheduled event
                r_ob->play_num_steps = 1;
                r_ob->play_step_ms = (r_ob->scheduled_ms - last_scheduled_ms);
            } else {
                // fluid steps for redraw
                r_ob->play_num_steps = MAX(1, round((r_ob->scheduled_ms - last_scheduled_ms) / r_ob->theoretical_play_step_ms));
                r_ob->play_step_ms = (r_ob->scheduled_ms - last_scheduled_ms)/r_ob->play_num_steps;
            }

            if (nextitemtoplay) { // we check if we should or should not prevent loops from being scheduled
                if (nextitemtoplay->type == k_LOOP_START)
                    r_ob->dont_schedule_loop_start = true;
                else if (nextitemtoplay->type == k_LOOP_END)
                    r_ob->dont_schedule_loop_end = true;
            }

            r_ob->play_step_count = 0;
            r_ob->scheduled_item = nextitemtoplay; // this has to be within the mutex!


            // gathering chord values as llll
            for (i = 0; i < count; i++) {
                t_llll *this_llll = NULL, *references = NULL;
                
                if (items_to_send[i]->type == k_CHORD) {
                    
                    // chord is played
                    ((t_chord *)items_to_send[i])->played = true;

                    // and we set as played all the rest sequences (if any)
                    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                        if (((t_chord *)items_to_send[i])->r_sym_duration.r_num < 0 && !r_ob->play_rests_separately) {
                            t_chord *tmp = ((t_chord *)items_to_send[i]), *end = rest_get_last_in_seq(((t_chord *)items_to_send[i]), false);
                            while (tmp) {
                                tmp->played = true;
                                if (tmp == end || tmp->r_sym_duration.r_num >= 0)
                                    break;
                                tmp = chord_get_next(tmp);
                            }
                        }
                    
                        if (((t_chord *)items_to_send[i])->r_sym_duration.r_num >= 0 && !r_ob->play_tied_elements_separately) {
                            t_chord *tmp = (t_chord *)items_to_send[i];
                            t_note *temp_nt;
                            t_chord *next;
                            for (temp_nt = tmp->firstnote; temp_nt; temp_nt = temp_nt->next) {
                                temp_nt->played = true;
                                if (!temp_nt->tie_from) // we don't keep track of notes continuing ties in the "notes_being_played" llll
                                    llll_appendobj(r_ob->notes_being_played, temp_nt);
                            }
                            while (tmp && (next = chord_get_next(tmp)) && chord_is_all_tied_to(r_ob, tmp, 0, NULL)) {
                                if (next->num_notes == tmp->num_notes)
                                    next->played = true;
                                tmp = next;
                            }
                            if (r_ob->play_mode == k_PLAYMODE_NOTEWISE) {
                                for (temp_nt = tmp->firstnote; temp_nt; temp_nt = temp_nt->next) {
                                    t_note *tmp_tied_note = temp_nt;
                                    while (tmp_tied_note && tmp_tied_note->tie_to && tmp_tied_note->tie_to != WHITENULL) {
                                        tmp_tied_note = tmp_tied_note->tie_to;
                                        tmp_tied_note->played = true;
//                                      llll_appendobj(x->r_ob.notes_being_played, tmp_tied_note, 0, WHITENULL_llll); // we don't keep track of notes continuing ties in the "notes_being_played" llll
                                    }
                                }
                            }
                        }
                    } else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                        for (t_note *temp_nt = ((t_chord *)items_to_send[i])->firstnote; temp_nt; temp_nt = temp_nt->next) {
                            temp_nt->played = true;
                            llll_appendobj(r_ob->notes_being_played, temp_nt);
                        }
                    }


                    this_llll = chord_get_as_llll_for_sending(r_ob, (t_chord *)items_to_send[i], k_CONSIDER_FOR_PLAYING, -1, NULL, &references, &is_notewise);
                    
                } else if (items_to_send[i]->type == k_MEASURE) { // bach.score only
                    t_llll *temp = measure_get_as_llll_for_sending(r_ob, (t_measure *)items_to_send[i], k_CONSIDER_FOR_PLAYING);
                    this_llll = llll_get();
                    references = llll_get();
                    llll_appendobj(this_llll, temp);
                    llll_appendobj(references, (t_measure *)items_to_send[i]);
                } else if (items_to_send[i]->type == k_TEMPO) { // bach.score only
                    t_llll *temp = get_tempo_as_llll_for_sending(r_ob, (t_tempo *)items_to_send[i], k_CONSIDER_FOR_PLAYING);
                    this_llll = llll_get();
                    references = llll_get();
                    llll_appendobj(this_llll, temp);
                    llll_appendobj(references, items_to_send[i]);
                } else if (items_to_send[i]->type == k_MARKER) {
                    t_llll *temp = marker_get_as_llll(r_ob, (t_marker *)items_to_send[i], true, true, k_CONSIDER_FOR_PLAYING);
                    this_llll = llll_get();
                    references = llll_get();
                    llll_appendobj(this_llll, temp);
                    llll_appendobj(references, items_to_send[i]);
                }
                if (this_llll && references) {
                    llll_appendllll(to_send, this_llll);
                    llll_appendllll(to_send_references, references);
                }
            }
            
            llll_flatten(to_send, 1, 0);
            llll_flatten(to_send_references, 0, 0);
            
            unlock_general_mutex(r_ob);
            
            if (r_ob->playing_scheduling_type == k_SCHEDULING_STANDARD)
                setclock_fdelay(r_ob->setclock->s_thing, r_ob->m_clock, r_ob->play_step_ms);
            
            r_ob->play_head_ms = last_scheduled_ms;
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                r_ob->play_head_ux = ms_to_unscaled_xposition(r_ob, r_ob->play_head_ms, 1);
            }
            
            if (r_ob->playing_scheduling_type == k_SCHEDULING_STANDARD) {
                if ((r_ob->obj_type == k_NOTATION_OBJECT_SCORE &&
                    ((r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_PAGES && r_ob->force_inscreen_ux_rolling_function((t_object *)r_ob, r_ob->play_head_ux, 0, true, false)) ||
                     (r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_FIXPOS && r_ob->force_inscreenpos_ux_function((t_object *)r_ob, r_ob->playhead_fixed_pos, r_ob->play_head_ux, true, false)))) ||
                    (r_ob->obj_type == k_NOTATION_OBJECT_ROLL &&
                    ((r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_PAGES && r_ob->force_inscreen_ms_rolling_function((t_object *)r_ob, r_ob->play_head_ms, 0, true, false, false)) ||
                     (r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_FIXPOS && r_ob->force_inscreenpos_ms_function((t_object *)r_ob, r_ob->playhead_fixed_pos, r_ob->play_head_ms, true, false, false)))))
                {
                    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
                }
            }
            
            // outputting chord values
            if (r_ob->playing_scheduling_type == k_SCHEDULING_PRESCHEDULE) {
                notationobj_append_prescheduled_event(r_ob, last_scheduled_ms, to_send, is_notewise, false);
                llll_free(to_send_references);
            } else {
                if (count > 0)
                    send_sublists_through_playout_and_free(r_ob, playout_num, to_send, to_send_references, is_notewise);
                else if (scheduled_item_type == k_LOOP_START || scheduled_item_type == k_LOOP_END) {
                    llllobj_outlet_symbol_couple_as_llll((t_object *)r_ob, LLLL_OBJ_UI, playout_num, _llllobj_sym_loop, scheduled_item_type == k_LOOP_START ? _llllobj_sym_start : _llllobj_sym_end);
                    llll_free(to_send);
                    llll_free(to_send_references);
                }
                
                if (r_ob->playing_scheduling_type == k_SCHEDULING_STANDARD) {
                    if (r_ob->highlight_played_notes)
                        notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
                    else
                        notationobj_redraw(r_ob);
                }
            }

            bach_freeptr(items_to_send);
            
        } else {

            // next event is the end of the score
            double end_time = r_ob->play_head_ms;
            if (r_ob->playing_scheduling_type == k_SCHEDULING_PRESCHEDULE)
                end_time = r_ob->length_ms_till_last_note;

            char need_repaint = (r_ob->playing_scheduling_type == k_SCHEDULING_STANDARD);
            notationobj_set_everything_unplayed(r_ob);
            r_ob->playing = false;
            r_ob->play_head_ms = -1;
            r_ob->play_head_ux = -1;
            r_ob->scheduled_item = NULL;
            r_ob->only_play_selection = false;
            r_ob->playback_deferlow = false;
            r_ob->play_step_count = 0;
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (r_ob->play_head_reset_start_ms_when_play_ends >= 0) {
                    r_ob->play_head_start_ms = r_ob->play_head_reset_start_ms_when_play_ends;
                    r_ob->play_head_start_ux = ms_to_unscaled_xposition(r_ob, r_ob->play_head_start_ms, 1);
                }
            }

            unlock_general_mutex(r_ob);
            
            
            if (r_ob->playing_scheduling_type == k_SCHEDULING_PRESCHEDULE) {
                notationobj_append_prescheduled_event(r_ob, end_time, NULL, 0, true);
            } else {
                // send "end" message
                t_llll *end_llll = llll_get();
                llll_appendsym(end_llll, _llllobj_sym_end, 0, WHITENULL_llll);
                llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, playout_num, end_llll);
                llll_free(end_llll);
            }
            
            if (need_repaint)
                notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
        }
    }
}

void notationobj_clock(t_notation_obj *r_ob, t_symbol *s)
{
    void *old = r_ob->setclock->s_thing; 
    t_object *c = 0; 
    
    // the line below can be restated as: 
    // if s is the empty symbol 
    // or s->s_thing is zero 
    // or s->s_thing is non-zero and a setclock object  
    if (s && (s == gensym("") || ((c = s->s_thing) && zgetfn(c, gensym("unset"))))) 
    { 
        if (old) 
            notationobj_stop(r_ob, NULL, 0, NULL);
        r_ob->setclock = s;
        /*        if (x->m_running) 
         setclock_delay(c, x->r_clock, 0L); */
    } 
}

void notationobj_preschedule_end(t_notation_obj *r_ob)
{
    r_ob->preschedule_cursor = NULL;
    r_ob->playing = false;
    notationobj_clear_prescheduled_events(r_ob);
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}


void notationobj_preschedule_task(t_notation_obj *r_ob)
{

    long playout = r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? 6 : 7;
    t_llllelem *cur = r_ob->preschedule_cursor;
    if (cur) {
        t_scheduled_event *ev = (t_scheduled_event *)hatom_getobj(&cur->l_hatom);
        r_ob->play_head_ms = ev->time;
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE);
        r_ob->play_head_ux = ms_to_unscaled_xposition(r_ob, ev->time, 1);
        if (ev->is_end) {
            t_llll *end_llll = llll_get();
            llll_appendsym(end_llll, _llllobj_sym_end, 0, WHITENULL_llll);
            llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, playout, end_llll);
            llll_free(end_llll);
            defer((t_object *) r_ob, (method)notationobj_preschedule_end, NULL, 0, NULL);
        } else {

            notationobj_redraw(r_ob);
            /*            if (ev->content && r_ob->highlight_played_notes) {
             check_unplayed_notes(r_ob, r_ob->play_head_ms);
             notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
             } else {
             //            if (x->r_ob.catch_playhead && force_inscreen_ms_rolling(x, x->r_ob.play_head_ms, 0, true, false, false))
             //                notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
             notationobj_redraw(r_ob);
             } */

            if (ev->content){
                send_sublists_through_playout_and_free(r_ob, playout, ev->content, NULL, ev->is_notewise);
                r_ob->preschedule_cursor = r_ob->preschedule_cursor->l_next;
            }
        }
    }
}

void notationobj_append_prescheduled_event(t_notation_obj *r_ob, double time, t_llll *content, char is_notewise, char is_end)
{
    t_scheduled_event *ev = (t_scheduled_event *)bach_newptr(sizeof(t_scheduled_event));
    ev->time = time;
    ev->clock = clock_new_debug((t_object *)r_ob, (method)notationobj_preschedule_task);
    ev->content = content;
    ev->is_end = is_end;
    ev->is_notewise = is_notewise;
    llll_appendobj(r_ob->to_preschedule, ev);
}

void notationobj_clear_prescheduled_events(t_notation_obj *r_ob)
{
    for (t_llllelem *el = r_ob->to_preschedule->l_head; el; el = el->l_next) {
        t_scheduled_event *ev = (t_scheduled_event *)hatom_getobj(&el->l_hatom);
        clock_unset(ev->clock);
        //        llll_free(ev->content);
        object_free_debug(ev->clock);
        bach_freeptr(ev);
    }
    llll_clear(r_ob->to_preschedule);
}



void notationobj_stop(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    if (r_ob->playing && r_ob->playing_scheduling_type == k_SCHEDULING_PRESCHEDULE) {
        notationobj_preschedule_end(r_ob);
    }
    schedule_delay(r_ob, (method) notationobj_do_stop, 0, s, 0, NULL);
}

void notationobj_set_everything_unplayed(t_notation_obj *r_ob)
{
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        for (t_voice *voice = r_ob->firstvoice; voice && (voice->number < r_ob->num_voices); voice = voice_get_next(r_ob, voice)) {
            for (t_chord *chord = ((t_rollvoice *)voice)->firstchord; chord; chord = chord->next) {
                chord->played = false;
                for (t_note *note = chord->firstnote; note; note = note->next)
                    note->played = false;
            }
        }
    } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        for (t_voice *voice = r_ob->firstvoice; voice && (voice->number < r_ob->num_voices); voice = voice_get_next(r_ob, voice)) {
            for (t_measure *meas = ((t_scorevoice *)voice)->firstmeasure; meas; meas = meas->next) {
                for (t_chord *chord = meas->firstchord; chord; chord = chord->next) {
                    chord->played = false;
                    for (t_note *note = chord->firstnote; note; note = note->next)
                        note->played = false;
                }
            }
        }
    }

    llll_clear(r_ob->notes_being_played);
}

void notationobj_do_stop(t_notation_obj *r_ob, t_symbol *s)
{
    lock_general_mutex(r_ob);
    r_ob->playing = false;
    notationobj_set_everything_unplayed(r_ob);
    r_ob->play_head_ms = -1;
    r_ob->dont_schedule_loop_end = r_ob->dont_schedule_loop_start = false;
    setclock_unset(r_ob->setclock->s_thing, r_ob->m_clock);
    r_ob->only_play_selection = false;
    r_ob->playback_deferlow = false;
    r_ob->play_step_count = 0;
    unlock_general_mutex(r_ob);

    llllobj_outlet_symbol_as_llll((t_object *)r_ob, LLLL_OBJ_UI, notationobj_get_playout(r_ob), s ? s : _llllobj_sym_stop);

    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        if (r_ob->highlight_played_notes)
            notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
        else
            notationobj_redraw(r_ob);
    } else {
       notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    }
}

void notationobj_play(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    notationobj_parse_play_arguments(r_ob, argc, argv, NULL, NULL, NULL, &r_ob->playback_deferlow);

    if (argc >= 1 && atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("selection")) {
        notationobj_playselection(r_ob, s, argc-1, argv+1);
        return;
    }

    char offline = (argc >= 1 && atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("offline"));
    long preschedule = (argc >= 1 && atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("preschedule"));

    long offset = (r_ob->playback_deferlow ? 2 : 1);
    
    if (offline) {
        if (bach_atomic_trylock(&r_ob->c_atomic_lock_play)) {
            object_warn((t_object *) r_ob, "Already playing offline!");
            return;
        }
        notationobj_play_offline(r_ob, s, argc - offset, argv + offset);
        bach_atomic_unlock(&r_ob->c_atomic_lock_play);
        return;
    }
    
    if (preschedule) {
        // play in preschedule mode (more accurate)
        notationobj_play_preschedule(r_ob, s, argc - offset, argv + offset);
        return;
    }

    if (r_ob->playing) {
        if (r_ob->playing_scheduling_type == k_SCHEDULING_OFFLINE) {
            object_warn((t_object *)r_ob, "Can't play: already playing offline");
        } else if (r_ob->playing_scheduling_type == k_SCHEDULING_PRESCHEDULE) {
            object_warn((t_object *)r_ob, "Can't play: already playing in preschedule mode");
        } else {
            // normal play called when a previous normal play was already ongoing.
            // For bw compatibility this will stop the existing play and trigger a new play
            notationobj_do_stop(r_ob, s);
            r_ob->playing_scheduling_type = k_SCHEDULING_STANDARD;
            schedule_delay(r_ob, (method) notationobj_do_play, 0, s, argc, argv);
            //            object_warn((t_object *)x, "Can't play: already playing!");
        }
    } else {
        r_ob->playing_scheduling_type = k_SCHEDULING_STANDARD;
        schedule_delay(r_ob, (method) notationobj_do_play, 0, s, argc, argv);
    }
}


void notationobj_play_offline(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    if (r_ob->playing) {
        object_warn((t_object *)r_ob, "Can't play offline: already playing");
    } else {
        r_ob->playing_scheduling_type = k_SCHEDULING_OFFLINE;
        notationobj_do_play(r_ob, s, argc, argv);
        if (r_ob->playback_deferlow) {
            notationobj_task_chain_deferlow(r_ob, NULL, 0, NULL);
        } else {
            while (r_ob->playing) {
                r_ob->play_step_count = r_ob->play_num_steps;
                notationobj_task(r_ob);
            }
        }
    }
}

void notationobj_playselection(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    // we set all the SELECTED chords as NON-played, the other ones as PLAYED
    double start_ms = -1;
    t_notation_item *selitem;
    char offline = (argc >= 1 && atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("offline"));
    char preschedule = (argc >= 1 && atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("preschedule"));
    t_atom av[3];
    
    notationobj_parse_play_arguments(r_ob, argc, argv, NULL, NULL, NULL, &r_ob->playback_deferlow);

    // find selected chords and ms_boundaries
    lock_general_mutex(r_ob);
    for (selitem = r_ob->firstselecteditem; selitem; selitem = selitem->next_selected) {
        if (selitem->type == k_CHORD) {
            t_chord *chord = (t_chord *) selitem;
            double this_onset = chord_get_onset_ms(r_ob, chord);
            if (start_ms < 0 || this_onset < start_ms)
                start_ms = this_onset;
        } else if (selitem->type == k_NOTE) {
            t_chord *chord = ((t_note *) selitem)->parent;
            double this_onset = chord_get_onset_ms(r_ob, chord);
            if (start_ms < 0 || this_onset < start_ms)
                start_ms = this_onset;
        } else if (selitem->type == k_MEASURE) {
            t_measure *measure = (t_measure *) selitem;
            double this_onset = measure_get_onset_ms(r_ob, measure);
            if (start_ms < 0 || this_onset < start_ms)
                start_ms = this_onset;
        } else if (selitem->type == k_VOICE) {
            start_ms = 0;
            break;
        } 
    }
    unlock_general_mutex(r_ob);
    
    start_ms -= CONST_EPSILON2; // we remove an "epsilon" from the start_ms
    if (start_ms < 0.) 
        start_ms = 0.;
    
    r_ob->only_play_selection = true;
    
    long acount = 0;
    if (offline) {
        atom_setsym(av, gensym("offline"));
        if (r_ob->playback_deferlow) {
            atom_setsym(av+1, gensym("deferlow"));
            atom_setfloat(av+2, start_ms);
            acount = 3;
        } else {
            atom_setfloat(av + 1, start_ms);
            acount = 2;
        }
    } else if (preschedule) {
        atom_setsym(av, gensym("preschedule"));
        atom_setfloat(av + 1, start_ms);
        acount = 2;
    } else {
        atom_setfloat(av, start_ms);
        acount = 1;
    }
    notationobj_play(r_ob, NULL, acount, av);
}


void notationobj_play_preschedule(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    double start_ms = (argc > 0) ? atom_getfloat(argv) : r_ob->play_head_start_ms;
    
    if (r_ob->playing) {
        object_warn((t_object *)r_ob, "Can't play in preschedule mode: already playing");
    } else {
        r_ob->playing_scheduling_type = k_SCHEDULING_PRESCHEDULE;
        notationobj_clear_prescheduled_events(r_ob);
        
        // Gathering information about items to be scheduled inside r_ob->to_schedule
        notationobj_do_play(r_ob, s, argc, argv);
        while (r_ob->playing) {
            r_ob->play_step_count = r_ob->play_num_steps;
            notationobj_task(r_ob);
        }
        
        r_ob->playing = true; // we are still to play! :)
        r_ob->play_head_ms = start_ms;

        // Scheduling stuff
        r_ob->preschedule_cursor = r_ob->to_preschedule->l_head;
        for (t_llllelem *el = r_ob->to_preschedule->l_head; el; el = el->l_next) {
            t_scheduled_event *ev = (t_scheduled_event *)hatom_getobj(&el->l_hatom);
            setclock_fdelay(r_ob->setclock->s_thing, ev->clock, ev->time - start_ms);
        }
    }
}

void notationobj_do_play(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    // let's find the first chord to play
    long i = 0;
    t_notation_item *firstplayeditem = NULL; 
    double start_ms = 0, end_ms = 0, firstplayeditem_onset = 0;
    t_measure *temp_meas = NULL;
    t_chord *temp_ch = NULL;
    t_voice *voice;
    
    r_ob->are_there_solos = are_there_solos(r_ob);

    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        start_ms = (argc > 0) ? atom_getfloat(argv) : 0;
        
        // detecting end_ms
        if (argc > 1) {
            // end is given as argument
            end_ms = atom_getfloat(argv + 1);
            r_ob->play_head_fixed_end_ms = end_ms;
        } else {
            // automatic end: when the roll is over
            end_ms = r_ob->length_ms;
            r_ob->play_head_fixed_end_ms = -1;
        }
        
        // wrong time boundaries for play?
        if (end_ms > 0 && end_ms <= start_ms) 
            return;
        
        // synchronizing the playhead with out start_ms
        if (argc == 0)
            start_ms = r_ob->play_head_start_ms;
        else
            r_ob->play_head_start_ms = start_ms;

    } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        r_ob->are_there_repeats = are_there_repeats(r_ob, true);
        r_ob->play_head_reset_start_ms_when_play_ends = -1; // which means: don't reset

        // setting automatic end
        end_ms = r_ob->length_ms_till_last_note;
        r_ob->play_head_fixed_end_ms = -1;

        // detecting start_ms
        if (argc > 0) {
            char err;
            t_llll *start_timepoint_syntax = llllobj_parse_llll((t_object *) r_ob, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
            if (start_timepoint_syntax->l_size == 2) {
                char err2;
                t_llll *end_timepoint_syntax = llll_clone(start_timepoint_syntax);
                llll_behead(end_timepoint_syntax);
                llll_betail(start_timepoint_syntax);
                err2 = parse_open_timepoint_syntax(r_ob, end_timepoint_syntax, NULL, &end_ms, NULL);
                llll_free(end_timepoint_syntax);
                if (err2) {
                    object_error((t_object *) r_ob, "Error in defining play end position");
                    return;
                }
                r_ob->play_head_fixed_end_ms = end_ms;
            }
            err = parse_open_timepoint_syntax(r_ob, start_timepoint_syntax, NULL, &start_ms, NULL);
            llll_free(start_timepoint_syntax);
            if (err) {
                object_error((t_object *) r_ob, "Error in defining play start position");
                return;
            }
            r_ob->play_head_start_ms = start_ms;
            r_ob->play_head_start_ux = ms_to_unscaled_xposition(r_ob, start_ms, 1);
            
        } else if (argc == 0) {
            start_ms = r_ob->play_head_start_ms;
        } else {
            r_ob->play_head_start_ms = start_ms;
            if (start_ms == 0) 
                start_ms = notationobj_get_first_onset_ms_for_grace_notes(r_ob);
            r_ob->play_head_start_ux = ms_to_unscaled_xposition(r_ob, start_ms, 1);
        }
    }


    update_playhead_cant_trespass_loop_end(r_ob);
    

    // first we send the playhead starting position
    send_playhead_position(r_ob, notationobj_get_playout(r_ob));

    // This line is no longer needed, since we do it constantly at the stop method:
    // set_everything_unplayed(x)

    t_llll *to_send = NULL;
    t_llll *to_send_references = NULL;
    char is_notewise = true;
    
    // then we send partial notes, if needed
    // i.e. the chords whose onset is < start_ms but whose duration continue at start_ms
    if (r_ob->play_partial_notes) {
        to_send = llll_get();
        to_send_references = llll_get();

        lock_general_mutex(r_ob);
        
        if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {

            for (voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                for (temp_ch = ((t_rollvoice *)voice)->firstchord; temp_ch; temp_ch = temp_ch->next){
                    if (temp_ch->onset >= start_ms) {
                        break;
                    } else if (should_element_be_played(r_ob, (t_notation_item *)temp_ch)){
                        for (t_note *temp_nt = temp_ch->firstnote; temp_nt && !temp_ch->played; temp_nt = temp_nt->next) {
                            if (temp_ch->onset + temp_nt->duration - CONST_EPSILON1 > start_ms) {
    //                        if (temp_ch->onset + temp_nt->duration >= start_ms && !(temp_ch->r_it.flags & k_FLAG_PLAYED)) {
                                t_llll *this_llll, *references;
                                t_note *nt;
                                this_llll = chord_get_as_llll_for_sending(r_ob, temp_ch, r_ob->play_partial_notes > 1 ? k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE : k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE, -1, NULL, &references, &is_notewise);
                                
                                // we set the partial notes as played
                                temp_ch->played = true;
                                for (nt = temp_ch->firstnote; nt; nt = nt->next) {
                                    if (temp_ch->onset + nt->duration >= start_ms) {
                                        nt->played = true;
                                        llll_appendobj(r_ob->notes_being_played, nt);
                                    } else if (temp_ch->played)
                                        temp_ch->played = false;
                                }
                                                            
                                llll_appendllll(to_send, this_llll);
                                llll_appendllll(to_send_references, references);
                                break;
                            }
                        }
                    }
                }
            }

        } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            for (voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                for (temp_meas = ((t_scorevoice *)voice)->firstmeasure; temp_meas; temp_meas = temp_meas->next) {
                    double measure_start_ms = measure_get_onset_ms(r_ob, temp_meas);
                    double measure_end_ms = notation_item_get_tail_ms_accurate(r_ob, (t_notation_item *)temp_meas);

                    if (measure_start_ms > start_ms)
                        break;
                    else if (measure_end_ms < start_ms)
                        continue;
                    
                    for (temp_ch = temp_meas->firstchord; temp_ch; temp_ch = temp_ch->next) {
                        if (temp_ch->onset > start_ms || (temp_ch->onset == start_ms && !chord_is_all_tied_from(temp_ch, false))) {
                            break;
                        } else if (should_element_be_played(r_ob, (t_notation_item *)temp_ch) &&
                                temp_ch->onset + temp_ch->duration_ms - CONST_EPSILON1 > start_ms) {
                            t_llll *references, *this_llll;

                            // we play the partial notes
                            t_note *temp_nt;
                            t_chord *next;
                            
                            temp_ch->played = true;
                            for (temp_nt = temp_ch->firstnote; temp_nt; temp_nt = temp_nt->next) {
                                temp_nt->played = true;
                                llll_appendobj(r_ob->notes_being_played, temp_nt);
                            }
                            
                            // and we set as played all the rest sequences (if any)
                            if (temp_ch->r_sym_duration.r_num < 0 && !r_ob->play_rests_separately) {
                                t_chord *tmp = temp_ch, *end = rest_get_last_in_seq(temp_ch, false);
                                while (tmp) {
                                    tmp->played = true;
                                    tmp = chord_get_next(tmp);
                                    if (!tmp || tmp == end || tmp->r_sym_duration.r_num >= 0)
                                        break;
                                }
                            }
                            
                            // and we set as played all the tied notes
                            if (!r_ob->play_tied_elements_separately) {
                                t_chord *tmp = temp_ch;
                                while (tmp && (next = chord_get_next(tmp)) && chord_is_all_tied_to(r_ob, tmp, 0, NULL)) {
                                    next->played = true;
                                    tmp = next;
                                }
                            }
                            for (temp_nt = temp_ch->firstnote; temp_nt; temp_nt = temp_nt->next) {
                                t_note *tmp_tied_note = temp_nt;
                                while (tmp_tied_note && tmp_tied_note->tie_to && tmp_tied_note->tie_to != WHITENULL) {
                                    tmp_tied_note = tmp_tied_note->tie_to;
                                    tmp_tied_note->played = true;
    //                                llll_appendobj(x->r_ob.notes_being_played, tmp_tied_note, 0, WHITENULL_llll); // NO NEED TO STORE TIED NOTES
                                }
                            }
                            
                            this_llll = chord_get_as_llll_for_sending(r_ob, temp_ch, r_ob->play_partial_notes > 1 ? k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE : k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE, -1, NULL, &references, &is_notewise);
                            llll_appendllll(to_send, this_llll);
                            llll_appendllll(to_send_references, references);
                        }
                    }
                }
            }
        }

        llll_flatten(to_send, 1, 0);
        llll_flatten(to_send_references, 0, 0);
        
        unlock_general_mutex(r_ob);
    }
    
    // setting the chord_play_cursor to NULL for every voice (why for every voice and not just the used ones??? because if one changes the number
    // of voices during playback this could be an issue...)
    for (i = 0; i < CONST_MAX_VOICES; i++) {
        r_ob->chord_play_cursor[i] = NULL;
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            r_ob->tempo_play_cursor[i] = NULL;
            r_ob->measure_play_cursor[i] = NULL;
        }
    }
    r_ob->marker_play_cursor = NULL;

    lock_general_mutex(r_ob);

    r_ob->dont_schedule_loop_end = r_ob->dont_schedule_loop_start = false;

    firstplayeditem = get_next_item_to_play(r_ob, start_ms);
    if (firstplayeditem)
        firstplayeditem_onset = notation_item_get_onset_ms(r_ob, firstplayeditem);
    
    // if the first chord is beyond the end limit, we stop
    if (firstplayeditem && firstplayeditem_onset >= end_ms) 
        firstplayeditem = NULL; 

    if (firstplayeditem || start_ms <= end_ms) {
        
        r_ob->scheduled_item = firstplayeditem;
        r_ob->scheduled_ms = firstplayeditem ? firstplayeditem_onset : end_ms;

        // if we're scheduling loop start or end, we don't want it to be rescheduled for next event
        r_ob->dont_schedule_loop_start = (r_ob->scheduled_item && r_ob->scheduled_item->type == k_LOOP_START) ? true : false;
        r_ob->dont_schedule_loop_end = (r_ob->scheduled_item && r_ob->scheduled_item->type == k_LOOP_END) ? true : false;

        unlock_general_mutex(r_ob);

        r_ob->play_head_ms = start_ms;
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            r_ob->play_head_ux = ms_to_unscaled_xposition(r_ob, r_ob->play_head_ms, 1);
        }

        if (((r_ob->obj_type == k_NOTATION_OBJECT_SCORE) &&
             ((r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_PAGES && r_ob->force_inscreen_ux_rolling_function((t_object *)r_ob, r_ob->play_head_ux, 0, true, false)) ||
             (r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_FIXPOS && r_ob->force_inscreenpos_ux_function((t_object *)r_ob, r_ob->playhead_fixed_pos, r_ob->play_head_ux, true, false)))) ||
             ((r_ob->obj_type == k_NOTATION_OBJECT_ROLL) &&
             ((r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_PAGES && r_ob->force_inscreen_ms_rolling_function((t_object *)r_ob, r_ob->play_head_ms, 0, true, false, false)) ||
             (r_ob->catch_playhead == k_PLAYHEAD_DOMAINCHANGE_FIXPOS && r_ob->force_inscreenpos_ms_function((t_object *)r_ob, r_ob->playhead_fixed_pos, r_ob->play_head_ms, true, false, false)))))
        {
            notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
        }

        r_ob->playing = true;
        llllobj_outlet_symbol_as_llll((t_object *)r_ob, LLLL_OBJ_UI, notationobj_get_playout(r_ob), _llllobj_sym_play);
        
        if (r_ob->theoretical_play_step_ms <= 0) {
            // step at each scheduled event
            r_ob->play_num_steps = 1;
            r_ob->play_step_ms = (r_ob->scheduled_ms - start_ms);
        } else {
            // fluid scheduling for redraw
            r_ob->play_num_steps = MAX(1, round((r_ob->scheduled_ms - start_ms) / r_ob->theoretical_play_step_ms));
            r_ob->play_step_ms = (r_ob->scheduled_ms - start_ms)/r_ob->play_num_steps;
        }
        r_ob->play_step_count = 0;
        
        if (r_ob->playing_scheduling_type == k_SCHEDULING_STANDARD) {
            setclock_getftime(r_ob->setclock->s_thing, &r_ob->start_play_time);
            setclock_fdelay(r_ob->setclock->s_thing, r_ob->m_clock, r_ob->play_step_ms);
            if (r_ob->highlight_played_notes)
                notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
            else
                notationobj_redraw(r_ob);
        }

    } else 
        unlock_general_mutex(r_ob);
    
    if (to_send)
        send_sublists_through_playout_and_free(r_ob, notationobj_get_playout(r_ob), to_send, to_send_references, is_notewise);

}


void notationobj_pause(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    if (r_ob->playing && r_ob->playing_scheduling_type == k_SCHEDULING_PRESCHEDULE) {
        object_warn((t_object *)r_ob, "Can't pause during prescheduled playback.");
    } else {
        r_ob->show_playhead = true;
        r_ob->play_head_start_ms = r_ob->play_head_ms;
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            r_ob->play_head_start_ux = r_ob->play_head_ux;
        }
        notationobj_stop(r_ob, _llllobj_sym_pause, 0, NULL);
    }
}
