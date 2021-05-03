/*
 *  score_api.c
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
 
#include "score_api.h" 


void verbose_print(t_score *x)
{
    if (verbose) {
        long count0, count1, count2;
        t_scorevoice *voice = x->firstvoice;
        t_measure *curr_meas; t_chord *curr_ch;
        t_notation_item *temp;
        post("There are %ld SCOREVOICES. First scorevoice: %lx. Last scorevoice: %lx", x->r_ob.num_voices, x->firstvoice, x->lastvoice);
        while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
            post("**** VOICE %ld ****", voice->v_ob.number);
            curr_meas = voice->firstmeasure;
            count0 = 0;
            post("There are %ld MEASURES. First chord: %lx. Last chord: %lx", voice->num_measures, voice->firstmeasure, voice->lastmeasure);
            while (curr_meas) {
                t_tempo *curr_tempo;
                post("  --- MEASURE %ld ---", curr_meas->measure_number);
                post("There are %ld TEMPO DATA. First tempo: %lx. Last tempo: %lx", curr_meas->num_tempi, curr_meas->firsttempo, curr_meas->lasttempo);
                curr_tempo = curr_meas->firsttempo; 
                while (curr_tempo) {
                    post("  - At measure %d, point_in_measure %d/%d, new_tempo: %d/%d, interp_type: %d", curr_tempo->owner->measure_number, curr_tempo->changepoint.r_num, curr_tempo->changepoint.r_den, curr_tempo->tempo_value, curr_tempo->interpolation_type);
                    curr_tempo = curr_tempo->next; 
                }
                curr_ch = curr_meas->firstchord;
                count1 = 0;
                post("  There are %ld CHORDS. First chord: %lx. Last chord: %lx", curr_meas->num_chords, curr_meas->firstchord, curr_meas->lastchord);
                while (curr_ch) {
                    t_note *curr_nt;
                    count1++;
                    post("   - Chord #%ld. Address: %lx. Onset: %.1fms. Prev: %lx, Next: %lx. It has %ld notes. First note: %lx. Last note: %lx", count1, curr_ch, curr_ch->onset, curr_ch->prev, curr_ch->next, curr_ch->num_notes, curr_ch->firstnote, curr_ch->lastnote);  
                    curr_nt = curr_ch->firstnote; 
                    count2 = 0;
                    while (curr_nt) {
                        count2++;
                        post("       . Note #%ld. Address: %lx. Parent: %lx. Prev: %lx, Next: %lx. Dur: %.1f, mc: %.1f, vel: %.d, acc: %ld/%ld, def_acc: %d. notecenter_stem_delta_ux: %f", count2, curr_nt, curr_nt->parent, curr_nt->prev, curr_nt->next, curr_nt->duration, curr_nt->midicents, curr_nt->velocity, curr_nt->pitch_original.alter().r_num, curr_nt->pitch_original.alter().r_den, note_is_enharmonicity_userdefined(curr_nt), curr_nt->notecenter_stem_delta_ux);
                        post("                    First Breakpoint: %lx, Last Breakpoint: %lx. Tie_to: %lx, Tie_from : %lx", curr_nt->firstbreakpoint, curr_nt->lastbreakpoint, curr_nt->tie_to, curr_nt->tie_from);
                        curr_nt = curr_nt->next;
                    }
                    curr_ch = curr_ch->next;
                }
                curr_meas = curr_meas->next;
            }
            voice = voice->next;
        }
        
        post("%ld elements SELECTED. First element: %lx. Last element: %lx", x->r_ob.num_selecteditems, x->r_ob.firstselecteditem, x->r_ob.lastselecteditem);
        temp = x->r_ob.firstselecteditem; count1 = 0;
        while (temp){
            count1++;
            post("- Element #%ld. Element address: %lx, type: %ld.", count1, temp, temp->type);
            temp = temp->next_selected;
        }
    }
}


void score_hidecursor(t_score *x)
{
    x->r_ob.show_playhead = false;
    notationobj_redraw((t_notation_obj *) x);
}

void score_showcursor(t_score *x)
{
    x->r_ob.show_playhead = true;
    notationobj_redraw((t_notation_obj *) x);
}

void scoreapi_setcursor_from_double(t_score *x, double pos)
{
    x->r_ob.play_head_start_ms = CLAMP(pos, 0, x->r_ob.length_ms_till_last_note);
    x->r_ob.play_head_start_ux = ms_to_unscaled_xposition((t_notation_obj *)x, x->r_ob.play_head_start_ms, 1);
    notationobj_redraw((t_notation_obj *) x);
}

void scoreapi_setcursor_from_llll(t_score *x, t_llll *args)
{
    t_timepoint tp;
    parse_open_timepoint_syntax((t_notation_obj *)x, args, &x->r_ob.play_head_start_ux, &x->r_ob.play_head_start_ms, &tp, false);
    notationobj_redraw((t_notation_obj *) x);
}


//returns true if need a redraw
char force_inscreen_ux(t_score *x, double inscreen_ux, char send_domain_if_changed){
    if (inscreen_ux >= x->r_ob.screen_ux_end) {
        x->r_ob.screen_ux_start = x->r_ob.screen_ux_end + floor((inscreen_ux - x->r_ob.screen_ux_end) / x->r_ob.domain_ux) *  x->r_ob.domain_ux;
        update_hscrollbar((t_notation_obj *)x, 2);
#ifdef BACH_MAX
        if (send_domain_if_changed) 
            send_domain(x, 7, NULL);
#endif
        return true;
    } else if (inscreen_ux <= x->r_ob.screen_ux_start) {
        x->r_ob.screen_ux_start = inscreen_ux;
        update_hscrollbar((t_notation_obj *)x, 2); 
#ifdef BACH_MAX
        if (send_domain_if_changed) 
            send_domain(x, 7, NULL);
#endif    
        return true;
    }
    return false;
}


//always returns true
char force_inscreenpos_ux(t_score *x, double position, double inscreen_ux, char also_send_domain, char also_move_mousedown_pt){
    double old_screen_ux_start = x->r_ob.screen_ux_start;
    
    if (inscreen_ux + x->r_ob.domain_ux * (1 - position) > x->r_ob.length_ux)
        x->r_ob.length_ux = inscreen_ux + x->r_ob.domain_ux * (1 - position);
    
    x->r_ob.screen_ux_start = inscreen_ux - x->r_ob.domain_ux * position;
    if (x->r_ob.screen_ux_start < 0)
        x->r_ob.screen_ux_start = 0;
        
    update_hscrollbar((t_notation_obj *)x, 2); 

    if (also_move_mousedown_pt) {
        double delta_x = deltauxpixels_to_deltaxpixels((t_notation_obj *)x, x->r_ob.screen_ux_start - old_screen_ux_start);
        x->r_ob.j_mousedown_point.x -= delta_x;
    }

#ifdef BACH_MAX
    if (also_send_domain) 
        send_domain(x, 7, NULL);
#endif

    return true;
}


// forces a given point to be in the screen, but exactly on the start or on the end point of the domain!
// returns 1 if point is overflown at right, -1 if it overflown at left, 0 if it was already in domain (->nothing has been done)
char force_inscreen_ux_to_boundary(t_score *x, double inscreen_ux, char clip_to_length, char send_domain_if_changed, char also_move_mousedown_pt){
    if (clip_to_length) 
        inscreen_ux = CLAMP(inscreen_ux, 0, x->r_ob.length_ux);

    if (inscreen_ux > x->r_ob.screen_ux_end) {
        force_inscreenpos_ux(x, 1., inscreen_ux, send_domain_if_changed, also_move_mousedown_pt);
        return 1;
    } else if (inscreen_ux < x->r_ob.screen_ux_start) {
        force_inscreenpos_ux(x, 0., inscreen_ux, send_domain_if_changed, also_move_mousedown_pt);
        return -1;
    } else 
        return 0;
}

// forces a given point to be in the screen, if it overflows at right, sets that point as the left beginning (useful for playing)
// returns 1 if point is overflown at right, -1 if it overflown at left, 0 if it was already in domain (->nothing has been done)
char force_inscreen_ux_rolling(t_score *x, double inscreen_ux, char clip_to_length, char send_domain_if_changed, char also_move_mousedown_pt){
    if (clip_to_length) 
        inscreen_ux = CLAMP(inscreen_ux, 0, x->r_ob.length_ux);
    
    if (inscreen_ux > x->r_ob.screen_ux_end) {
        force_inscreenpos_ux(x, 0., MIN(inscreen_ux, x->r_ob.length_ux - x->r_ob.domain_ux), send_domain_if_changed, also_move_mousedown_pt);
        return 1;
    } else if (inscreen_ux < x->r_ob.screen_ux_start) {
        force_inscreenpos_ux(x, 0., inscreen_ux, send_domain_if_changed, also_move_mousedown_pt);
        return -1;
    } else 
        return 0;
}


// for inspector
void force_notation_item_inscreen(t_score *x, t_notation_item *it, void *dummy){
    if (it->type == k_MEASURE)
        force_inscreen_ux_rolling(x, ((t_measure *)it)->tuttipoint_reference->offset_ux + ((t_measure *)it)->start_barline_offset_ux, 0, true, false);
    else if (it->type == k_CHORD)
        force_inscreen_ux_rolling(x, ((t_chord *)it)->parent->tuttipoint_reference->offset_ux + ((t_chord *)it)->stem_offset_ux - ((t_chord *)it)->left_uextension, 0, true, false);
    else if (it->type == k_NOTE)
        force_inscreen_ux_rolling(x, ((t_note *)it)->parent->parent->tuttipoint_reference->offset_ux + ((t_note *)it)->parent->stem_offset_ux - ((t_note *)it)->parent->left_uextension, 0, true, false);
    else if (it->type == k_TEMPO)
        force_inscreen_ux_rolling(x, ((t_tempo *)it)->owner->tuttipoint_reference->offset_ux + ((t_tempo *)it)->tuttipoint_offset_ux, 0, true, false);
}

double get_last_barline_ux(t_score *x)
{
    if (x->r_ob.lasttuttipoint) {
        double final_barline_width = get_barline_ux_width((t_notation_obj *)x, k_BARLINE_FINAL);
        return x->r_ob.lasttuttipoint->offset_ux + x->r_ob.lasttuttipoint->width_ux + final_barline_width;
    } else {
        return 0;
    }
        
}

// returns true if score must be redrawn
char scoreapi_inscreen(t_score *x, t_llll *inscreen)
{
    char err = false; 
    double unscaled_x = 0;
    
    if (inscreen->l_head && hatom_gettype(&inscreen->l_head->l_hatom) == H_SYM && hatom_getsym(&inscreen->l_head->l_hatom) == _llllobj_sym_end)
        unscaled_x = get_last_barline_ux(x); // x->r_ob.length_ux;
    else if (inscreen->l_head && hatom_gettype(&inscreen->l_head->l_hatom) == H_SYM && hatom_getsym(&inscreen->l_head->l_hatom) == _llllobj_sym_cursor)
        unscaled_x = x->r_ob.playing ? x->r_ob.play_head_ux : x->r_ob.play_head_start_ux;
    else
        err = parse_open_timepoint_syntax((t_notation_obj *)x, inscreen, &unscaled_x, NULL, NULL, false);
    
    if (!err)
        return force_inscreen_ux(x, unscaled_x, true);

    return false;
}

// returns true if score must be redrawn
char scoreapi_inscreenpos(t_score *x, t_llll *inscreen)
{
    char err = false; 
    double screenpos = 0., unscaled_x = 0;
    
    if (inscreen && inscreen->l_head) {
        screenpos = hatom_getdouble(&inscreen->l_head->l_hatom);
        llll_destroyelem(inscreen->l_head);
        if (inscreen->l_head && hatom_gettype(&inscreen->l_head->l_hatom) == H_SYM && hatom_getsym(&inscreen->l_head->l_hatom) == _llllobj_sym_end)
            unscaled_x = get_last_barline_ux(x); // x->r_ob.length_ux;
        else if (inscreen->l_head && hatom_gettype(&inscreen->l_head->l_hatom) == H_SYM && hatom_getsym(&inscreen->l_head->l_hatom) == _llllobj_sym_cursor)
            unscaled_x = x->r_ob.playing ? x->r_ob.play_head_ux : x->r_ob.play_head_start_ux;
        else
            err = parse_open_timepoint_syntax((t_notation_obj *)x, inscreen, &unscaled_x, NULL, NULL, false);
    } else
        err = true;
    
    if (!err) 
        return force_inscreenpos_ux(x, screenpos, unscaled_x, true, false);
    
    return false;
}



void assign_local_spacing_from_measure_parameters(t_score *x){
    t_scorevoice *voice;
    for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next){
        t_measure *meas;
        for (meas = voice->firstmeasure; meas; meas = meas->next){
            if (meas->tuttipoint_reference) {
                if (meas->r_it.flags & k_FLAG_DEFINES_FIXED_WIDTH) {
                    assign_fixed_spacing_uwidth((t_notation_obj *)x, meas->tuttipoint_reference, meas->fixed_spacing_uwidth);
                    assign_local_spacing_width_multiplier((t_notation_obj *)x, meas->tuttipoint_reference, 1.); // we reset the widthfactor to 1
                } else if (meas->r_it.flags & k_FLAG_REMOVES_FIXED_WIDTH)
                    remove_fixed_spacing_uwidth((t_notation_obj *)x, meas->tuttipoint_reference);
                else if (meas->r_it.flags & k_FLAG_DEFINES_LOCAL_SPACING_WIDTH)
                    assign_local_spacing_width_multiplier((t_notation_obj *)x, meas->tuttipoint_reference, meas->local_spacing_width_multiplier);
                
                meas->r_it.flags = (e_bach_internal_notation_flags) (meas->r_it.flags & ~k_FLAG_DEFINES_FIXED_WIDTH);
                meas->r_it.flags = (e_bach_internal_notation_flags) (meas->r_it.flags & ~k_FLAG_REMOVES_FIXED_WIDTH);
                meas->r_it.flags = (e_bach_internal_notation_flags) (meas->r_it.flags & ~k_FLAG_DEFINES_LOCAL_SPACING_WIDTH);
            }
        }
    }
}


double get_last_tpt_barline_width(t_score *x, t_tuttipoint *tpt){
    double width = 0;
    long i;
    for (i = 0; i < x->r_ob.num_voices && i < CONST_MAX_VOICES; i++){
        t_measure *tmp_meas = tpt->measure[i];
        t_measure *last_tpt_measure = NULL;
        while ((tpt->next && tmp_meas != tpt->next->measure[i]) || (!tpt->next && tmp_meas)) {
            if (!tmp_meas) {
                notationobj_throw_issue((t_notation_obj *)x);
                break;
            } else
                tmp_meas = tmp_meas->next;
        }
        
        if (tmp_meas && tmp_meas->prev)
            last_tpt_measure = tmp_meas->prev;
        else if (!tmp_meas)
            last_tpt_measure = scorevoice_get_nth(x, i)->lastmeasure;

        if (last_tpt_measure) {
            double this_width = measure_get_barline_ux_width((t_notation_obj *) x, last_tpt_measure);
            if (width < this_width)
                width = this_width;
        }
    }
    
    return width;
}


char scoreapi_inscreenmeas_do(t_score *x, t_measure *start_meas, t_measure *end_meas)
{
    t_notation_obj *r_ob = (t_notation_obj *)x;
    
    if (start_meas && end_meas) {
        t_tuttipoint *start_tpt = start_meas->tuttipoint_reference;
        t_tuttipoint *end_tpt = end_meas->tuttipoint_reference;
        
        if (start_tpt && end_tpt) {
            
            t_tuttipoint *temp;
            double total_width = 0;
            double total_fixed_barline_ts_uwidth = 0;
            double ratio = 1.;
            double last_barline_width = get_last_tpt_barline_width(x, end_tpt);
            t_llll *garbage = llll_get();
            t_llll *garbage2 = llll_get();
            
            lock_general_mutex((t_notation_obj *)x);
            
            // resetting local width
            for (temp = start_tpt; temp; temp = temp->next){
                assign_local_spacing_width_multiplier(r_ob, temp, 1.);
                temp->need_recompute_spacing = k_SPACING_RECALCULATE;
                if (temp == end_tpt)
                    break;
            }
            
            set_need_perform_analysis_and_change_flag(r_ob);
            perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DO);
            
            start_tpt = start_meas->tuttipoint_reference;
            end_tpt = end_meas->tuttipoint_reference;
            
            if (start_tpt && end_tpt) {
                
                // calculating new widths
                for (temp = start_tpt; temp; temp = temp->next){
                    total_width += temp->width_ux;
                    total_fixed_barline_ts_uwidth += temp->fixed_barline_ts_uwidth;
                    if (temp == end_tpt)
                        break;
                }
                
                ratio = (r_ob->domain_ux - total_fixed_barline_ts_uwidth - last_barline_width)/(total_width - total_fixed_barline_ts_uwidth);
                
                if (ratio <= 0.)
                    ratio = CONST_EPSILON1;
                
                for (temp = start_tpt; temp; temp = temp->next){
                    assign_local_spacing_width_multiplier(r_ob, temp, temp->local_spacing_width_multiplier * ratio);
                    temp->need_recompute_spacing = k_SPACING_RECALCULATE;
                    if (temp == end_tpt)
                        break;
                }
                
                set_need_perform_analysis_and_change_flag(r_ob);
                perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DO);
                
                force_inscreenpos_ux(x, 0., start_tpt->offset_ux, true, false);
                recompute_total_length(r_ob); //x->r_ob.screen_ux_start
                update_hscrollbar(r_ob, 2);
            }
            
            unlock_general_mutex(r_ob);
            
            llll_free(garbage);
            llll_free(garbage2);
            
            return true;
        }
    }
    return false;
}

// returns true if score must be redrawn
char scoreapi_inscreenmeas(t_score *x, t_llll *inscreen_measures)
{
    if (inscreen_measures && inscreen_measures->l_head && inscreen_measures->l_head->l_next && 
        hatom_gettype(&inscreen_measures->l_head->l_hatom) == H_LONG && hatom_gettype(&inscreen_measures->l_head->l_next->l_hatom) == H_LONG){
        
        long start_meas_num = hatom_getlong(&inscreen_measures->l_head->l_hatom);
        long end_meas_num = hatom_getlong(&inscreen_measures->l_head->l_next->l_hatom);
        long voicenum = (inscreen_measures->l_head->l_next->l_next && hatom_gettype(&inscreen_measures->l_head->l_next->l_next->l_hatom) == H_LONG) ?
                        hatom_getlong(&inscreen_measures->l_head->l_next->l_next->l_hatom) : 1;
        
        if (voicenum >= 1 && voicenum <= x->r_ob.num_voices){
            t_scorevoice *voice = scorevoice_get_nth(x, voicenum-1);
            t_measure *start_meas, *end_meas;
            if (start_meas_num <= 0)
                start_meas_num = 1;
            if (end_meas_num > voice->num_measures)
                end_meas_num = voice->num_measures;
            if (end_meas_num < start_meas_num){
                long temp = start_meas_num;
                start_meas_num = end_meas_num;
                end_meas_num = temp;
            }
            start_meas = measure_get_nth(voice, start_meas_num - 1);
            end_meas = measure_get_nth(voice, end_meas_num - 1);
        
            return scoreapi_inscreenmeas_do(x, start_meas, end_meas);
        }
    }

    return false;
}






// attribute setters
void scoreapi_set_tonedivision(t_score *x, long s)
{
    if (s<=2) s=2;
    if (x->r_ob.tone_division > s) {
        // are there userdefined accidentals?
        // if yes, we'll send a warning
        t_scorevoice *temp_vc, *voice; 
        t_measure *temp_meas, *measure;
        t_chord *temp_ch, *chord; 
        t_note *temp_nt;
        char there_are_user_accidentals = 0;
        for (temp_vc = x->firstvoice; temp_vc && (temp_vc->v_ob.number < x->r_ob.num_voices) && (!(there_are_user_accidentals)); temp_vc = temp_vc->next) 
            for (temp_meas = temp_vc->firstmeasure; temp_meas && (!(there_are_user_accidentals)); temp_meas = temp_meas->next) 
                for (temp_ch = temp_meas->firstchord; temp_ch && (!(there_are_user_accidentals)); temp_ch = temp_ch->next) 
                    for (temp_nt = temp_ch->firstnote; temp_nt && (!(there_are_user_accidentals)); temp_nt = temp_nt->next) 
                        if (note_is_enharmonicity_userdefined(temp_nt))
                            there_are_user_accidentals = 1;
        if (there_are_user_accidentals)
            object_warn((t_object *) x, "Warning: loosening tone division has made automatic accidentals of user-defined accidentals.");
        // going from a finer to a looser tonedivision : we change all the user-defined accidentals into automatic-accidentals
        voice = x->firstvoice;
        while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
            measure = voice->firstmeasure;
            while (measure) {
                chord = measure->firstchord;
                while (chord){
                    t_note *note = chord->firstnote;
                    while (note) {
                        note_set_auto_enharmonicity(note);
                        note = note->next;
                    }
                    chord = chord->next;
                } 
                measure = measure->next;
            }
            voice = voice->next;
        }
    }
    x->r_ob.tone_division = s;
    if (x->r_ob.accidentals_display_type == k_ACCIDENTALS_CLASSICAL) { // classical graphic
        if ((x->r_ob.tone_division != 2) && (x->r_ob.tone_division != 4) && (x->r_ob.tone_division != 8))
            object_warn((t_object *) x, "bach.score does not support graphical accidentals for the %ld-tone division. Use fraction- or cents-representation instead.", s);
        else if (((x->r_ob.tone_division == 8) && (x->r_ob.accidentals_typo_preferences.binary_characters_depth < 8)) || 
                 ((x->r_ob.tone_division == 4) && (x->r_ob.accidentals_typo_preferences.binary_characters_depth < 4)) ||
                   ((x->r_ob.tone_division == 2) && (x->r_ob.accidentals_typo_preferences.binary_characters_depth < 2)))
            object_warn((t_object *) x, "The active accidental font does not support the %ld-tone division. Use fraction- or cents-representation instead, or change font.", s);
    }
    
    object_attr_setdisabled((t_object *)x, gensym("accidentalspreferences"), x->r_ob.tone_division != 2 && x->r_ob.tone_division != 4 && x->r_ob.tone_division != 8);
    object_attr_setdisabled((t_object *)x, gensym("enharmonictable"), x->r_ob.tone_division != 2 && x->r_ob.tone_division != 4 && x->r_ob.tone_division != 8);

    check_all_voices_fullaccpatterns((t_notation_obj *)x);
    
    recompute_all_and_redraw(x);
}

void scoreapi_set_accidentalsgraphic(t_score *x, long s)
{
    if (s>4) s=1;
    x->r_ob.accidentals_display_type = s;
    if (s == 1) { // classical graphic
        if ((x->r_ob.tone_division != 2) && (x->r_ob.tone_division != 4) && (x->r_ob.tone_division != 8))
            object_warn((t_object *) x, "bach.score does not support graphical accidentals for the %d-tone division. Use fraction- or cents-representation instead.", x->r_ob.tone_division);
        else if (((x->r_ob.tone_division == 8) && (x->r_ob.accidentals_typo_preferences.binary_characters_depth < 8)) || 
                 ((x->r_ob.tone_division == 4) && (x->r_ob.accidentals_typo_preferences.binary_characters_depth < 4)) ||
                 ((x->r_ob.tone_division == 2) && (x->r_ob.accidentals_typo_preferences.binary_characters_depth < 2)))
            object_warn((t_object *) x, "The active accidental font does not support the %d-tone division. Use fraction- or cents-representation instead, or change font.", x->r_ob.tone_division);
    }
    
    recompute_all_and_redraw(x);
}

void scoreapi_set_accidentalspreferences(t_score *x, long s)
{
    x->r_ob.accidentals_preferences = (e_accidentals_preferences) CLAMP(s, 0, 3);
    object_attr_setdisabled((t_object *)x, gensym("enharmonictable"), x->r_ob.accidentals_preferences != k_ACC_CUSTOM);
    if (!x->r_ob.creatingnewobj)
        parse_fullaccpattern_to_voices((t_notation_obj *) x);
    recompute_all_and_redraw(x);
}

void scoreapi_set_enharmonictable(t_score *x, long ac, t_atom *av)
{
    long i;
    for (i = 0; i < ac && i < x->r_ob.num_voices; i++)
        x->r_ob.full_acc_repr[i] = atom_getsym(av+i);
    for (; i < x->r_ob.num_voices; i++) // repeat last one
        x->r_ob.full_acc_repr[i] = atom_getsym(av + ac - 1);
    if (!x->r_ob.creatingnewobj)
        parse_fullaccpattern_to_voices((t_notation_obj *) x);
    recompute_all_and_redraw(x);
}

void scoreapi_set_lyricsaffectspacing(t_score *x, long s)
{
    x->r_ob.lyrics_affect_spacing = CLAMP(s, 0, 3);
    recompute_all_and_redraw(x);
}

void scoreapi_set_dynamicsaffectspacing(t_score *x, long s)
{
    x->r_ob.dynamics_affect_spacing = CLAMP(s, 0, 3);
    recompute_all_and_redraw(x);
}


void scoreapi_set_nonantialiasedstaff(t_score *x, long l)
{
    x->r_ob.force_non_antialiased_staff_lines = l;
    if (l) {
        adjust_zoom_for_non_antialiased_lines((t_notation_obj *)x);
        calculate_voice_offsets((t_notation_obj *) x);
    } else {
        x->r_ob.zoom_y = x->r_ob.zoom_y_with_antialias;
    }
}

/*
t_max_err score_setattr_keys(t_score *x, t_object *attr, long ac, t_atom *av)
{
    long i;
    //    t_scorevoice *voice;
    t_symbol *keys[CONST_MAX_VOICES + 1];
    
    for (i = 0; i < ac && i < CONST_MAX_VOICES; i++)
        keys[i] = atom_getsym(av++);
    keys[i] = NULL;
    scoreapi_set_keys(x, keys);
    return MAX_ERR_NONE;
}


t_max_err score_setattr_clefs(t_score *x, t_object *attr, long ac, t_atom *av)
{
    t_symbol *clefs[CONST_MAX_VOICES + 1];
    long i;
    for (i = 0; i < ac && i < CONST_MAX_VOICES; i++, av++)
        clefs[i] = atom_getsym(av);
    clefs[i] = NULL;
    scoreapi_set_clefs(x, clefs);
    return MAX_ERR_NONE;
}*/


void scoreapi_set_zoom(t_score *x, double z)
{
    change_zoom((t_notation_obj *) x, (z > 1.) ? z : 1.);
    redraw_hscrollbar((t_notation_obj *)x, 0);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
}

void scoreapi_set_vzoom(t_score *x, double z)
{            
    z = MAX(1., z);
    atom_setfloat(&x->r_ob.vertical_zoom, z);
    x->r_ob.zoom_y = z/100.;
    x->r_ob.step_y = CONST_STEP_UY * x->r_ob.zoom_y;
    x->r_ob.zoom_y_with_antialias = x->r_ob.zoom_y;
    adjust_zoom_for_non_antialiased_lines((t_notation_obj *)x);
    x->r_ob.system_jump = get_system_jump((t_notation_obj *)x);
    //        post("supposed: %f. this: %f.--> zoom %f", supposedheight, height, x->r_ob.zoom_y);
    calculate_voice_offsets((t_notation_obj *) x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
}

void scoreapi_set_noteheads_font(t_score *x, t_symbol *font)
{
    if (!font)
        return;
    x->r_ob.noteheads_font = font;
    load_notation_typo_preferences((t_notation_obj *) x, font);
    load_noteheads_typo_preferences((t_notation_obj *) x, font);
    recompute_all_and_redraw(x);
}

void scoreapi_set_accidentals_font(t_score *x, t_symbol *font)
{
    if (!font)
        return;
    x->r_ob.accidentals_font = font;
    load_accidentals_typo_preferences((t_notation_obj *) x, font);
    
    x->r_ob.key_signature_uwidth = get_max_key_uwidth((t_notation_obj *) x);
    x->r_ob.system_jump = get_system_jump((t_notation_obj *)x);
    x->r_ob.firsttime = true;
    
    recompute_all_and_redraw(x);
}

void scoreapi_set_articulations_font(t_score *x, t_symbol *font)
{
    if (!font)
        return;
    x->r_ob.articulations_font = font;
    load_articulations_typo_preferences(&x->r_ob.articulations_typo_preferences, font);
    x->r_ob.firsttime = true;
    recompute_all_and_redraw(x);
}


void scoreapi_set_autoretranscribe(t_score *x, long l)
{
    x->r_ob.autoparse_rhythms = CLAMP(l, 0, 1);
    object_attr_setdisabled((t_object *)x, gensym("maketreecompatiblewithts"), x->r_ob.autoparse_rhythms == 0);
    object_attr_setdisabled((t_object *)x, gensym("syncopationposdurratio"), x->r_ob.autoparse_rhythms == 0);
    object_attr_setdisabled((t_object *)x, gensym("syncopationasymratio"), x->r_ob.autoparse_rhythms == 0);
    
    recompute_all_and_redraw(x);
}

void scoreapi_set_outputtrees(t_score *x, long l)
{
    x->r_ob.output_trees = CLAMP(l, 0, 3);
    object_attr_setdisabled((t_object *)x, gensym("outputtiesindurationtree"), x->r_ob.output_trees < 2);
}

void scoreapi_set_maketreecompatiblewithts(t_score *x, long l)
{
    x->r_ob.make_tree_compatible_with_ts = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}


void scoreapi_set_showaccidentalstiepreferences(t_score *x, long l)
{
    x->r_ob.show_accidentals_tie_preferences = (e_show_accidentals_tie_preferences)CLAMP(l, 0, 2);
    recompute_all_and_redraw(x);
}

void scoreapi_set_cautionaryaccidentals(t_score *x, long l)
{
    x->r_ob.cautionary_accidentals = CLAMP(l, 0, 2);
    recompute_all_and_redraw(x);
}

void scoreapi_set_cautionaryaccidentalsdecay(t_score *x, long l)
{
    x->r_ob.cautionary_accidentals_decay = MAX(l, 0);
    recompute_all_and_redraw(x);
}

void scoreapi_set_cautionaryaccidentalsremind(t_score *x, long l)
{
    x->r_ob.cautionary_accidentals_remind = MAX(l, 0);
    recompute_all_and_redraw(x);
}

void scoreapi_set_constraintbeamsinspaces(t_score *x, long l)
{
    x->r_ob.constraint_beam_start_end_in_spaces = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void set_all_non_treelocked_measure_to_ignore_except_for_tuplets(t_score *x){
    t_scorevoice *voice;
    t_measure *meas;
    for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next)
        for (meas = voice->firstmeasure; meas; meas = meas->next)
            if (!meas->lock_rhythmic_tree && meas->rhythmic_tree) {
                set_tuplet_levels_as_keep_levels(meas->rhythmic_tree);
                set_level_type_flag_for_level(meas->rhythmic_tree, k_RHYTHM_LEVEL_IGNORE);
            }
}

void scoreapi_set_extendbeamsoverrests(t_score *x, long l)
{
    x->r_ob.extend_beams_over_rests = CLAMP(l, 0, 2);
    if (!x->r_ob.creatingnewobj) 
        set_all_non_treelocked_measure_to_ignore_except_for_tuplets(x);
    recompute_all_and_redraw(x);
}

void scoreapi_set_restswithinbeaming(t_score *x, long l)
{
    x->r_ob.rests_within_beaming = CLAMP(l, 0, 2);
    object_attr_setdisabled((t_object *)x, gensym("extendbeamsoverrests"), x->r_ob.rests_within_beaming == k_REST_IN_BEAM_NEVER);
    if (!x->r_ob.creatingnewobj) 
        set_all_non_treelocked_measure_to_ignore_except_for_tuplets(x);
    recompute_all_and_redraw(x);
}

void scoreapi_set_maxrestfloatingsteps(t_score *x, long l)
{
    x->r_ob.max_rest_floating_steps = MAX(l, 0);
    recompute_all_and_redraw(x);
}

void scoreapi_set_maxbeamslope(t_score *x, double d)
{
    x->r_ob.max_beam_slope = MAX(d, 0);
    recompute_all_and_redraw(x);
}

void scoreapi_set_maxbeamdeltay(t_score *x, long d)
{
    x->r_ob.max_beam_delta_y = MAX(d, 0);
    recompute_all_and_redraw(x);
}

void scoreapi_set_reversegracedirection(t_score *x, long d)
{
    x->r_ob.reverse_grace_chord_direction = CLAMP(d, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_tieassignpitch(t_score *x, double d)
{
    x->r_ob.tie_assign_pitch = CLAMP(d, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_maxdots(t_score *x, long l)
{
    x->r_ob.max_dots = MAX(l, 0);
    recompute_all_and_redraw(x);
}

void scoreapi_set_centeredwholerests(t_score *x, long l)
{
    x->r_ob.whole_rests_in_empty_measures = l;
    recompute_all_and_redraw(x);
}

void scoreapi_set_dontbeamtupletswithotherthings(t_score *x, long l)
{
    x->r_ob.dont_beam_tuplets_with_other_things = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_simplifytuplets(t_score *x, long l)
{
    x->r_ob.try_to_make_tuplets_simple = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_beamgracesequences(t_score *x, long l)
{
    x->r_ob.try_to_beam_grace_sequences = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_gracedur(t_score *x, t_symbol *s)
{
    t_atom av;
    x->r_ob.grace_note_equivalent_sym = s ? s : gensym("1/64");
    atom_setsym(&av, x->r_ob.grace_note_equivalent_sym);
    t_llll *ll = llllobj_parse_llll((t_object *)x, LLLL_OBJ_UI, NULL, 1, &av, LLLL_PARSE_CLONE);
    if (ll && ll->l_head && is_hatom_number(&ll->l_head->l_hatom))
        x->r_ob.grace_note_equivalent = rat_abs(hatom_getrational(&ll->l_head->l_hatom));
    llll_free(ll);
    calculate_all_chords_remaining_onsets(x);
}

void scoreapi_set_gracemaxperc(t_score *x, double d)
{
    x->r_ob.max_percentage_of_chord_taken_by_grace_notes = CLAMP(d, 0., 100.);
    calculate_all_chords_remaining_onsets(x);
}

void scoreapi_set_jointuplets(t_score *x, long l)
{
    x->r_ob.try_to_join_tuplets = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_treehandling(t_score *x, long l)
{
    x->r_ob.tree_handling = CLAMP(l, k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED, k_RHYTHMIC_TREE_HANDLING_IGNORE);
    object_attr_setdisabled((t_object *)x, gensym("maketreecompatiblewithts"), x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_IGNORE);
    object_attr_setdisabled((t_object *)x, gensym("jointuplets"), x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED);
    object_attr_setdisabled((t_object *)x, gensym("simplifytuplets"), x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED);
    object_attr_setdisabled((t_object *)x, gensym("syncopationasymratio"), x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED);
    object_attr_setdisabled((t_object *)x, gensym("syncopationposdurratio"), x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED);
    recompute_all_and_redraw(x);
}

void scoreapi_set_breakrootlevelbeam(t_score *x, long l)
{
    x->r_ob.always_break_first_level_beams = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_leveltobeam(t_score *x, long l)
{
    x->r_ob.tree_to_beaming_correspondence = CLAMP(l, 0, 2);
//    object_attr_setdisabled((t_object *)x, gensym("breakrootlevelbeam"), x->r_ob.tree_to_beaming_correspondence == k_TREE2BEAM_BREAK_BEAMS_AROUND_LEVELS);
    recompute_all_and_redraw(x);
}


void scoreapi_set_showtupletspreferences(t_score *x, long l)
{
    x->r_ob.show_tuplets_preferences = CLAMP(l, 0, 5);
    recompute_all_and_redraw(x);
}


void scoreapi_set_hidetupletshapeonbeams(t_score *x, long l)
{
    x->r_ob.only_use_shape_on_unbeamed_tuplets = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}



void scoreapi_set_admitdottedtuplets(t_score *x, long l)
{
    x->r_ob.admit_dotted_tuplets = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_showtimesignatures(t_score *x, long l)
{
    x->r_ob.show_time_signatures = CLAMP(l, 0, 2);
    recompute_all_and_redraw(x);
}

void scoreapi_set_allowbeaming(t_score *x, long l)
{
    x->r_ob.allow_beaming = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_autocompletemeasures(t_score *x, long l)
{
    x->r_ob.auto_complete_measures = CLAMP(l, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_spacingparameter(t_score *x, double d)
{
    // legacy, for compatibility
    if (x->r_ob.spacing_type == k_SPACING_NOTE_TS)
        d = MIN(d, 1.);
    d = MAX(d, 0);
    x->r_ob.spacing_width = d * 1.8;
    recompute_all_and_redraw(x);
}

void scoreapi_set_spacingwidth(t_score *x, double d)
{
    x->r_ob.spacing_width = MAX(d, 0);
    recompute_all_and_redraw(x);
}

void scoreapi_set_spacingproportionality(t_score *x, double d)
{
    x->r_ob.spacing_proportionality = CLAMP(d, 0, 1);
    recompute_all_and_redraw(x);
}

void scoreapi_set_minmeaswidth(t_score *x, double d)
{
    x->r_ob.minimum_uwidth_for_measure = d > 0. ? d : 0.;
    recompute_all_and_redraw(x);
}

void scoreapi_set_minmeaswidthpersymunit(t_score *x, double d)
{
    x->r_ob.minimum_uwidth_per_sym_unit_for_measure = d > 0. ? d : 0.;
    recompute_all_and_redraw(x);
}

void scoreapi_set_syncopationasymratio(t_score *x, double d)
{
    x->r_ob.syncopation_asym_ratio = d;
    recompute_all_and_redraw(x);
}

void scoreapi_set_syncopationposdurratio(t_score *x, double d)
{
    x->r_ob.syncopation_pos_dur_ratio = d;
    recompute_all_and_redraw(x);
}

void scoreapi_set_syncopationmaxdots(t_score *x, long l)
{
    x->r_ob.syncopation_max_dots = l;
    recompute_all_and_redraw(x);
}





void recalculate_all_chord_parameters(t_score *x) 
{
    // recalculate all the chords parameters
    t_scorevoice *voice = x->firstvoice;
    t_chord *temp_ch; t_measure *temp_meas;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        temp_meas = voice->firstmeasure;
        while (temp_meas) {
            temp_ch = temp_meas->firstchord;
            while (temp_ch) {
                chord_set_recompute_parameters_flag((t_notation_obj *)x, temp_ch);
                temp_ch = temp_ch->next;
            }
            temp_meas = temp_meas->next;
        }
        voice = voice->next;
    }
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
}


void remove_all_tuttipoints_flag_modified(t_score *x){
    t_tuttipoint *tpt = x->r_ob.firsttuttipoint;
    while (tpt){
        tpt->flag &= ~k_FLAG_MODIFIED;
        tpt = tpt->next;
    }
}


void recalculate_all_tuttipoints_spacing(t_score *x) 
{
    t_tuttipoint *tpt = x->r_ob.firsttuttipoint;
    while (tpt) {
        tpt->need_recompute_spacing = k_SPACING_RECALCULATE;
        tpt = tpt->next;
    }
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
}

void recalculate_all_beamings(t_score *x) 
{
    t_scorevoice *voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        t_measure *meas = voice->firstmeasure;
        while (meas) {
            meas->need_recompute_beamings = true;
            meas = meas->next;
        }
        voice = voice->next;
    }
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
}

void recalculate_all_beams_positions(t_score *x) 
{
    t_scorevoice *voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        t_measure *meas = voice->firstmeasure;
        while (meas) {
            meas->need_recompute_beams_positions = true;
            meas = meas->next;
        }
        voice = voice->next;
    }
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
}

void recalculate_all_utf_measure_timesignatures(t_score *x) 
{
    t_scorevoice *voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        t_measure *meas = voice->firstmeasure;
        while (meas) {
            compute_utf_timesignature((t_notation_obj *) x, &meas->timesignature);
            meas = meas->next;
        }
        voice = voice->next;
    }
}

void check_all_measures_autocompletion(t_score *x) 
{
    if (x->r_ob.auto_complete_measures) {
        t_scorevoice *voice = x->firstvoice;
        while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
            t_measure *meas = voice->firstmeasure;
            while (meas) {
                meas->need_check_autocompletion = true;
                meas = meas->next;
            }
            voice = voice->next;
        }
        set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
    }
}

void check_all_measures_ties(t_score *x) 
{
    t_scorevoice *voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        t_measure *meas = voice->firstmeasure;
        while (meas) {
            meas->need_check_ties = true;
            meas = meas->next;
        }
        voice = voice->next;
    }
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
}

void recompute_all_except_for_beamings_and_autocompletion(t_score *x) 
{
    x->r_ob.need_recompute_tuttipoints = true;
    x->r_ob.need_reassign_local_spacing = true;
    recalculate_all_beams_positions(x);
    recalculate_all_chord_parameters(x);
    recalculate_all_tuttipoints_spacing(x);
    x->r_ob.key_signature_uwidth = get_max_key_uwidth((t_notation_obj *) x);
    x->r_ob.system_jump = get_system_jump((t_notation_obj *)x);
    recalculate_all_utf_measure_timesignatures(x);
    check_all_measures_ties(x);
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
    x->r_ob.need_recompute_chords_double_onset = true;
}

void recompute_all(t_score *x) 
{
    x->r_ob.need_recompute_tuttipoints = true;
    x->r_ob.need_reassign_local_spacing = true;
    recalculate_all_beamings(x);
    recalculate_all_chord_parameters(x);
    recalculate_all_tuttipoints_spacing(x);
    x->r_ob.key_signature_uwidth = get_max_key_uwidth((t_notation_obj *) x);
    x->r_ob.system_jump = get_system_jump((t_notation_obj *)x);
    check_all_measures_autocompletion(x);
    recalculate_all_utf_measure_timesignatures(x);
    check_all_measures_ties(x);
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
    x->r_ob.need_recompute_chords_double_onset = true;
}

void recompute_all_except_for_beamings_and_autocompletion_and_redraw(t_score *x)
{
    recompute_all_except_for_beamings_and_autocompletion(x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
}

void recompute_all_and_redraw(t_score *x) 
{
    recompute_all(x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
}

/*
t_scorevoice *voice_get_last_visible(t_score *x)
{
    t_scorevoice *voice = scorevoice_get_nth(x, x->r_ob.num_voices - 1);
    while (voice && voice->v_ob.hidden)
        voice = voice->prev;
    return voice;
}

t_scorevoice *voice_get_first_visible(t_score *x)
{
    t_scorevoice *voice = x->firstvoice;
    while (voice && voice->v_ob.number < x->r_ob.num_voices && voice->v_ob.hidden)
        voice = voice->next;
    return voice;
}
*/


// returns the nth (0-based) voice of a score
t_scorevoice* scorevoice_get_nth(t_score *x, long n)
{ 
    t_scorevoice *curr = x->firstvoice;
    long i;
    if (n < 0) 
        return curr;
    
    if (n >= x->r_ob.num_voices) 
        n = x->r_ob.num_voices;
    
    for (i = 0; i<n; i++)
        curr = curr->next;
    return curr;
    // to be improved: if the note# is > n/2, pass the list the other way round!
}

t_llll *getdomain_from_uxstart(t_score *x, double ux_start, t_symbol *message_selector, t_symbol *label)
{
    t_llll *outlist = llll_get();

    //    double ms_start = unscaled_xposition_to_ms((t_notation_obj *)x, x->r_ob.screen_ux_start, 1);
    //    double ms_end = unscaled_xposition_to_ms((t_notation_obj *)x, x->r_ob.screen_ux_end, 1);
    
    double ms_start = unscaled_xposition_to_ms((t_notation_obj *)x, ux_start, 1);
    double ms_end = unscaled_xposition_to_ms((t_notation_obj *)x, ux_start + x->r_ob.domain_ux, 1);
    long i;
    
    llll_appendsym(outlist, message_selector, 0, WHITENULL_llll);
    if (label)
        llll_appendsym(outlist, label, 0, WHITENULL_llll);
    
    llll_appendlong(outlist, ms_start, 0, WHITENULL_llll);
    llll_appendlong(outlist, ms_end, 0, WHITENULL_llll);

    for (i = 0; i < x->r_ob.num_voices; i++){
        t_llll *this_voice = llll_get();
        t_llll *this_voice_start = llll_get();
        t_llll *this_voice_end = llll_get();
        t_timepoint tp_start = ms_to_timepoint((t_notation_obj *)x, ms_start, i, k_MS_TO_TP_RETURN_RIGHT_CHORD);
        t_timepoint tp_end = ms_to_timepoint((t_notation_obj *)x, ms_end, i, k_MS_TO_TP_RETURN_LEFT_CHORD);
        llll_appendlong(this_voice_start, tp_start.measure_num + 1, 0, WHITENULL_llll);
        llll_appendrat(this_voice_start, tp_start.pt_in_measure, 0, WHITENULL_llll);
        llll_appendlong(this_voice_end, tp_end.measure_num + 1, 0, WHITENULL_llll);
        llll_appendrat(this_voice_end, tp_end.pt_in_measure, 0, WHITENULL_llll);
        llll_appendllll(this_voice, this_voice_start, 0, WHITENULL_llll);
        llll_appendllll(this_voice, this_voice_end, 0, WHITENULL_llll);
        llll_appendrat(this_voice, get_sym_durations_between_timepoints(scorevoice_get_nth(x, i), tp_start, tp_end), 0, WHITENULL_llll);
        llll_appendllll(outlist, this_voice, 0, WHITENULL_llll);
    }
    return outlist;
}

t_llll *scoreapi_testdomain(t_score *x, t_llll *dom, t_symbol *label)
{
    t_max_err err;
    double unscaled_x = 0;
    err = parse_open_timepoint_syntax((t_notation_obj *)x, dom, &unscaled_x, NULL, NULL, false);
    if (!err)
        return getdomain_from_uxstart(x, unscaled_x, gensym("testdomain"), label);
    else
        return NULL;
}

t_llll *scoreapi_getdomain(t_score *x, t_symbol *label)
{
    return getdomain_from_uxstart(x, x->r_ob.screen_ux_start, _llllobj_sym_domain, label);
}

void scoreapi_getdomainpixels(t_score *x, double *start, double *end)
{
    *start = unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.screen_ux_start);
    *end = unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.screen_ux_end);
}

t_max_err scoreapi_getpixelpos(t_score *x, t_llll *open_timepoint_syntax, double *pos)
{
    t_max_err err = true;
    double unscaled_x = 0;
    err = parse_open_timepoint_syntax((t_notation_obj *)x, open_timepoint_syntax, &unscaled_x, NULL, NULL, false);
    if (!err)
        *pos = unscaled_xposition_to_xposition((t_notation_obj *) x, unscaled_x);
    return err;
}

double scoreapi_getlength(t_score *x)
{
    redraw_hscrollbar((t_notation_obj *)x, 0);
    return x->r_ob.length_ms_till_last_note;
}

double scoreapi_get_end_ux(t_score *x)
{
    if (x->r_ob.lasttuttipoint)
        return x->r_ob.lasttuttipoint->offset_ux + x->r_ob.lasttuttipoint->width_ux;
    return 0;
}

void clear_voice(t_score *x, t_scorevoice *voice) 
{
    char need_check_scheduling = false;
    if (voice->lastmeasure) {
        t_measure *temp = voice->lastmeasure; t_measure *temp2;
        while (temp) {
            temp2 = temp;
            temp = temp->prev;
            if (delete_measure((t_notation_obj *)x, temp2, NULL, NULL))
                need_check_scheduling = true;
        }
    }
    if (need_check_scheduling)
        check_correct_scheduling((t_notation_obj *)x, false);
    update_solos((t_notation_obj *)x);
//    delete_voice_tempi(x, voice);
}


void set_all_tstempo_values_from_llll(t_score *x, t_llll* measureinfo, long num_introduced_voices)
{
    if (measureinfo) {
        // admitted syntaxes are, for each voice
        // ((TS))
        // (nil (TEMPI))
        // ((TS) (TEMPI))
        // ((TS) (TEMPI) measbarline)
        // (validfor#measure (TS) (TEMPI) measbarline)
        // also attributes are possible 
        
        //        char debug[1000];
        //        llll_to_char_array(measureinfo, debug, 999);
        t_scorevoice *tmp_voice;
        if ((measureinfo->l_depth <= 3) && (measureinfo->l_size >= 1)) { // easy case: only [(num den)] or [(num den) (tempo)] for all voices
            t_llllelem *firstelem = measureinfo->l_head;
            tmp_voice = x->firstvoice;
            if (hatom_gettype(&firstelem->l_hatom) == H_LLLL) { 
                t_llll *ts = hatom_getllll(&firstelem->l_hatom);
                t_llll *tempi = ((measureinfo->l_size >= 2) && (hatom_gettype(&firstelem->l_next->l_hatom) == H_LLLL)) ? hatom_getllll(&firstelem->l_next->l_hatom) : NULL;
                char measure_barline = (measureinfo->l_size >= 3 && hatom_gettype(&firstelem->l_next->l_next->l_hatom) == H_SYM) ? hatom_getsym(&firstelem->l_next->l_next->l_hatom)->s_name[0] : k_BARLINE_AUTOMATIC;
                while (tmp_voice && (tmp_voice->v_ob.number < x->r_ob.num_voices)) {
                    t_measure *meas;
                    if (tempi && (tempi->l_size > 0) && !x->must_append_measures) 
                        clear_voice_tempi((t_notation_obj *)x, tmp_voice);
                    if (!x->must_append_measures)
                        meas = tmp_voice->firstmeasure;
                    else 
                        meas = measure_get_nth(tmp_voice, tmp_voice->num_measures);
                    if (!meas) { // if the measure does not exist, we create it
                        meas = build_measure((t_notation_obj *) x, NULL);
                        insert_measure((t_notation_obj *)x, tmp_voice, meas, tmp_voice->lastmeasure, 0);
                    }
                    while (meas) {
                        measure_set_ts_and_tempo_from_llll((t_notation_obj *) x, meas, ts, tempi, measure_barline, measureinfo, false);
                        compute_utf_timesignature((t_notation_obj *) x, &meas->timesignature);
                        meas = meas->next;
                    }
                    tmp_voice = tmp_voice->next;
                }
            }
            
        } else if ((measureinfo->l_depth >= 4) && (measureinfo->l_size >= 1)) { // specification for every voice
            
            t_llllelem *voiceelem; t_llll* voice_measures = NULL;
            for (voiceelem = measureinfo->l_head, tmp_voice = x->firstvoice;
                 (voiceelem && tmp_voice && (tmp_voice->v_ob.number < num_introduced_voices));
                 voiceelem = voiceelem->l_next, tmp_voice = tmp_voice->next) {
                if (voiceelem) {
                    long type = hatom_gettype(&voiceelem->l_hatom);
                    if ((type == H_LLLL) && (hatom_getllll(&voiceelem->l_hatom)->l_size > 0)) {
                        if (!x->must_append_measures)
                            clear_voice_tempi((t_notation_obj *)x, tmp_voice); // first of all it clears the tempi
                        voice_measures = hatom_getllll(&voiceelem->l_hatom); 
                        set_voice_tstempo_values_from_llll(x, voice_measures, tmp_voice);
                    }
                } else 
                    break;
            }
            if (!x->must_append_measures) {
                // remaining voices are copies!
                while (voice_measures && tmp_voice && (tmp_voice->v_ob.number < num_introduced_voices)) {
                    clear_voice_tempi((t_notation_obj *)x, tmp_voice); // first of all it clears the tempi
                    set_voice_tstempo_values_from_llll(x, voice_measures, tmp_voice);
                    tmp_voice = tmp_voice->next;
                }
            }
        }
    }
    check_all_measures_autocompletion(x);
}



void set_all_durations_values_from_llll(t_score *x, t_llll* durations, long num_introduced_voices)
{
    if (durations) {
        t_llllelem *elem; 
        
        t_scorevoice *voice = x->firstvoice;
        for (elem = durations->l_head; elem && voice && voice->v_ob.number < num_introduced_voices; elem = (elem && elem->l_next) ? elem->l_next : elem) {
            if (voice) {
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_durations = hatom_getllll(&elem->l_hatom); 
                    set_voice_durations_values_from_llll(x, voice_durations, voice);
                }
            } else 
                break;
            voice = voice->next;
        }
    }
}

void set_all_cents_values_from_llll(t_score *x, t_llll* cents, char force_append_notes, long num_introduced_voices)
{
    if (cents) {
        t_llllelem *elem; 
        t_scorevoice *voice = x->firstvoice;
        for (elem = cents->l_head; elem && voice && voice->v_ob.number < num_introduced_voices; elem = (elem && elem->l_next) ? elem->l_next : elem) {
            if (voice) {
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_llll = hatom_getllll(&elem->l_hatom); 
                    set_voice_cents_values_from_llll(x, voice_llll, voice, force_append_notes);
                }
            } else 
                break;
            voice = voice->next;
        }
    }
}

void set_all_velocities_values_from_llll(t_score *x, t_llll* velocities, long num_introduced_voices)
{
    if (velocities) {
        t_llllelem *elem;
        t_scorevoice *voice = x->firstvoice;
        for (elem = velocities->l_head; elem && voice && voice->v_ob.number < num_introduced_voices; elem = (elem && elem->l_next) ? elem->l_next : elem) {
            if (voice) {
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_llll = hatom_getllll(&elem->l_hatom); 
                    set_voice_velocities_values_from_llll(x, voice_llll, voice);
                }
            } else 
                break;
            voice = voice->next;
        }
    }
}

void set_all_ties_values_from_llll(t_score *x, t_llll* ties, long num_introduced_voices)
{
    if (ties) {
        t_llllelem *elem;
        t_scorevoice *voice = x->firstvoice;
        for (elem = ties->l_head; elem && voice && voice->v_ob.number < num_introduced_voices; elem = (elem && elem->l_next) ? elem->l_next : elem) {
            if (voice) {
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_llll = hatom_getllll(&elem->l_hatom); 
                    set_voice_ties_values_from_llll(x, voice_llll, voice);
                }
            } else 
                break;
            voice = voice->next;
        }
    }
}

void set_all_graphic_values_from_llll(t_score *x, t_llll* graphic)
{
    if (graphic) {
        t_llllelem *elem;
        t_scorevoice *voice = x->firstvoice;
        for (elem = graphic->l_head; elem; elem = elem->l_next) {
            if (voice) {
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_llll = hatom_getllll(&elem->l_hatom); 
                    set_voice_graphic_values_from_llll(x, voice_llll, voice);
                }
            } else 
                break;
            voice = voice->next;
        }
    }
}

void set_all_breakpoints_values_from_llll(t_score *x, t_llll* breakpoints)
{
    if (breakpoints) {
        t_llllelem *elem; 
        t_scorevoice *voice = x->firstvoice;
        for (elem = breakpoints->l_head; elem; elem = elem->l_next) {
            if (voice) { // cycle on the voices
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_llll = hatom_getllll(&elem->l_hatom); 
                    set_voice_breakpoints_values_from_llll(x, voice_llll, voice);
                }
            } else 
                break;
            voice = voice->next;
        }
    }   
}

void set_all_articulations_values_from_llll(t_score *x, t_llll* articulations)
{
    if (articulations) {
        t_llllelem *elem; 
        t_scorevoice *voice = x->firstvoice;
        for (elem = articulations->l_head; elem; elem = elem->l_next) {
            if (voice) { // cycle on the voices
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_llll = hatom_getllll(&elem->l_hatom); 
                    set_voice_articulation_values_from_llll(x, voice_llll, voice);
                }
            } else 
                break;
            voice = voice->next;
        }
    }   
}

void set_all_slots_values_from_llll(t_score *x, t_llll* slots)
{
    if (slots) {
        t_llllelem *elem;
        t_scorevoice *voice = x->firstvoice;
        
        for (elem = slots->l_head; elem; elem = elem->l_next) {
            if (voice) {
                long type = hatom_gettype(&elem->l_hatom);
                if (type == H_LLLL) {
                    t_llll* voice_llll = hatom_getllll(&elem->l_hatom); 
                    set_voice_slots_values_from_llll(x, voice_llll, voice);
                }
            } else 
                break;
            voice = voice->next;
        }
    }
}

void set_voice_tstempo_values_from_llll(t_score *x, t_llll* measureinfo, t_scorevoice *voice)
{ 
    t_llllelem *elem; 
    t_measure *measure = (!x->must_append_measures) ? voice->firstmeasure : NULL; // if must_append_measures is true, we append measures
    t_llll *ts = NULL; t_llll *tempi = NULL;
    long valid_for_n_measures = 1; char barline = k_BARLINE_AUTOMATIC;
    for (elem = measureinfo->l_head; elem; elem = elem->l_next) { // cycle on the measures. the syntax is ((TS)) or ((TS) (TEMPO)) or (validfor#meas (TS) (TEMPO) barline)
        if (hatom_gettype(&elem->l_hatom) == H_LLLL) { // it has to be a llll
            t_llll *thismeas = hatom_getllll(&elem->l_hatom);
            if (thismeas->l_size > 0) {
                long count;
                if (hatom_gettype(&thismeas->l_head->l_hatom) == H_LONG) {
                    valid_for_n_measures= hatom_getlong(&thismeas->l_head->l_hatom);
                    ts = (thismeas->l_size >= 2) ? hatom_getllll(&thismeas->l_head->l_next->l_hatom) : NULL;
                    tempi = (thismeas->l_size >= 3) ? hatom_getllll(&thismeas->l_head->l_next->l_next->l_hatom) : NULL;
                    barline = ((thismeas->l_size >= 4) && (hatom_gettype(&thismeas->l_head->l_next->l_next->l_next->l_hatom) == H_SYM)) ? hatom_getsym(&thismeas->l_head->l_next->l_next->l_next->l_hatom)->s_name[0] : k_BARLINE_AUTOMATIC;
                } else {
                    valid_for_n_measures = 1;
                    ts = (thismeas->l_size >= 1) ? hatom_getllll(&thismeas->l_head->l_hatom) : NULL;
                    tempi = (thismeas->l_size >= 2) ? hatom_getllll(&thismeas->l_head->l_next->l_hatom) : NULL;
                    barline = ((thismeas->l_size >= 3) && (hatom_gettype(&thismeas->l_head->l_next->l_next->l_hatom) == H_SYM)) ? hatom_getsym(&thismeas->l_head->l_next->l_next->l_hatom)->s_name[0] : k_BARLINE_AUTOMATIC;
                }
                
                if (valid_for_n_measures < 0) { // to the end!
                    if (!measure) { // if the measure does not exist, we create it
                        measure = build_measure((t_notation_obj *) x, NULL);
                        insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
                    }
                    while (measure) {
                        measure_set_ts_and_tempo_from_llll((t_notation_obj *) x, measure, ts, tempi, barline, thismeas, false);
                        compute_utf_timesignature((t_notation_obj *) x, &measure->timesignature);
                        measure = measure->next;
                    }
                    break;
                }
                for (count = 0; count < valid_for_n_measures; count++) {
                    if (!measure) { // if the measure does not exist, we create it
                        measure = build_measure((t_notation_obj *) x, NULL);
                        insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
                    }
                    measure_set_ts_and_tempo_from_llll((t_notation_obj *) x, measure, ts, tempi, barline, thismeas, false);
                    compute_utf_timesignature((t_notation_obj *) x, &measure->timesignature);
                    measure = measure->next;
                }
            }
        }
    }
    
    // remaining measures?
    while (measure) {
        measure_set_ts_and_tempo_from_llll((t_notation_obj *) x, measure, ts, tempi, barline, NULL, false);
        compute_utf_timesignature((t_notation_obj *) x, &measure->timesignature);
        measure = measure->next;
    }
    
    recompute_all(x);
    verbose_print(x);
    
}

void set_measure_cents_values_from_llll(t_score *x, t_llll* measure_midicents, t_measure *measure, char force_append_notes)
{
    t_llllelem *elem; 
    t_rational onset;
    long num_chords;
    t_chord *chord;
    t_rational measure_dur;
    long chord_num = 0;
    
    if (is_measure_empty((t_notation_obj *)x, measure))
        measure_delete_all_chords(x, measure);
    
    onset = long2rat(0); 
    measure_dur = measure_get_sym_duration(measure);
    num_chords = measure_midicents->l_size;
    chord = measure->firstchord;
    
    for (elem = measure_midicents->l_head; elem; elem = elem->l_next) {
        long type = hatom_gettype(&elem->l_hatom);
        if (type == H_LLLL) { // there's a nested llll, so specifications for each note
            t_llll* note_midicents = hatom_getllll(&elem->l_hatom);
            if (chord) { // there's already a chord: we change its cents
                if (note_midicents->l_size > 0) {
                    if (chord->r_sym_duration.r_num >= 0) {
                        t_llllelem *subelem; 
                        t_note *note = chord->firstnote;
                        for (subelem = note_midicents->l_head; subelem; subelem = subelem->l_next) {
                            long subtype = hatom_gettype(&subelem->l_hatom);
                            double cents; 
                            char set_pitch = 0;
                            t_pitch pitch_in = t_pitch::NaP;
                            
                            if ((subtype == H_LONG) || (subtype == H_DOUBLE) || (subtype == H_RAT)) {
                                cents = hatom_getdouble(&subelem->l_hatom);
                                modify_cents_if_nan_or_inf_and_warn((t_notation_obj *)x, &cents);
                                set_pitch = 1;
                            } else if (subtype == H_PITCH) {
                                pitch_in = hatom_getpitch(&subelem->l_hatom);
                                cents = pitch_in.toMC();
                                set_pitch = 1;
                            } else if (chord->is_grace_chord) {
                                turn_chord_into_rest(x, chord);
                                break;
                            }
                            
                            if (set_pitch) {
                                if (note) { // there's already a note: we change its cents
                                    note->midicents = cents;
                                    note_set_enharmonicity(note, pitch_in);
                                    note = note->next;
                                } else { // we create a note within the same chord!
                                    t_note *this_nt;
                                    double argv[2]; 
                                    argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                    argv[1] = cents;
                                    this_nt = build_note_from_ac_av((t_notation_obj *) x, 2, argv);
                                    if (force_append_notes)
                                        note_append_force((t_notation_obj *) x, chord, this_nt, 0);
                                    else
                                        note_insert((t_notation_obj *) x, chord, this_nt, 0);
                                    note_set_enharmonicity(this_nt, pitch_in);
                                }
                            }
                        }
                    }
                } else { // we skip this chord
                    // turn_chord_into_rest(x, chord); // or we turn it into a pause??
                }
                chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
                chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                chord = chord->next;
                
            } else { // there was NO chord: but we can create one
                t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                if (remaining_duration.r_num > 0) {
                    t_chord *newchord = NULL; 
                    t_note *nt;
                    t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                    long num_notes = note_midicents->l_size;
                    double *argv = (double *) bach_newptr(2 * num_notes * sizeof(double));
                    t_pitch *pitch_in = (t_pitch *) bach_newptr(num_notes * sizeof(t_pitch));
                    long *screen_mc = (long *) bach_newptr(num_notes * sizeof(long)); 
                    t_rational *screen_acc = (t_rational *) bach_newptr(num_notes * sizeof(t_rational)); 
                    t_llllelem *subelem; 
                    long i = 0; 
                    long h = 0;
                    if (note_midicents->l_size > 0) {
                        for (subelem = note_midicents->l_head; subelem && i < 2 * num_notes - 1 && h < num_notes; subelem = subelem->l_next) {
                            long subtype = hatom_gettype(&subelem->l_hatom);
                            argv[i] = CONST_DEFAULT_NEW_NOTE_DURATION;
                            pitch_in[h] = t_pitch::NaP;
                            if ((subtype == H_LONG) || (subtype == H_DOUBLE) || (subtype == H_RAT)) {
                                argv[i+1] = hatom_getdouble(&subelem->l_hatom);
                                modify_cents_if_nan_or_inf_and_warn((t_notation_obj *)x, &(argv[i+1]));
                            } else if (subtype == H_PITCH) {
                                pitch_in[h] = hatom_getpitch(&subelem->l_hatom);
                                argv[i+1] = pitch_in[h].toMC();
                            } else {
                                argv[i+1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                            }
                            h++;
                            i += 2;
                        }
                        newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 2 * num_notes, argv, NULL, NULL, 0, NULL, 0, NULL);
                        newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                    } else { //nil = rest (cannot skip a chord which is not there!)
                        double argv[2]; 
                        argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                        argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                        chord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1,  1, 2 , argv, NULL, NULL, 0, NULL, 0, NULL);
                        chord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, chord, 0, WHITENULL_llll);
                        turn_chord_into_rest(x, chord);
                        chord = chord->next;
                    }
                    chord_num++; 
                    onset = rat_rat_sum(onset, r_sym_duration);
                    if (newchord) {
                        for (nt = newchord->firstnote, h = 0; nt && h < num_notes; nt = nt->next, h++)
                            note_set_enharmonicity(nt, pitch_in[h]);
                    }
                    bach_freeptr(argv);
                    bach_freeptr(pitch_in);
                    bach_freeptr(screen_mc);
                    bach_freeptr(screen_acc);
                }
            } 
            
        } else if ((type == H_LONG) || (type == H_DOUBLE) || (type == H_RAT) || (type == H_PITCH)) { // just one cent given: we apply it to the whole chord!!
            
            double cents; t_chord *newchord;
            char set_pitch = 0;
            t_pitch pitch_in = t_pitch::NaP;
            if ((type == H_LONG) || (type == H_DOUBLE) || (type == H_RAT)) {
                cents = hatom_getdouble(&elem->l_hatom); 
                set_pitch = 1;
            } else if (type == H_PITCH) {
                pitch_in = hatom_getpitch(&elem->l_hatom);
                cents = pitch_in.toMC();
                set_pitch = 1;
            }
            
            if (set_pitch) {
                if (chord) { // there's already a chord: we change all its cents
                    if (chord->r_sym_duration.r_num > 0) {
                        t_note *note = chord->firstnote;
                        while (note) {
                            note->midicents = cents;
                            note_set_enharmonicity(note, pitch_in);
                            note = note->next;
                        }
                    }
                    chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
                    chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                    chord = chord->next;
                } else { // there was NO chord: we create one, with just one note
                    t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                    if (remaining_duration.r_num > 0) {
                        t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                        double argv[2]; 
                        argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                        argv[1] = cents;
                        newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1,  1, 2 , argv, NULL, NULL, 0, NULL, 0, NULL);
                        newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                        
                        if (newchord->firstnote)
                            note_set_enharmonicity(newchord->firstnote, pitch_in);
                        chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                    }
                } 
            }
        }
    }
}

void set_voice_cents_values_from_llll(t_score *x, t_llll* midicents, t_scorevoice *voice, char force_append_notes)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = midicents->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_midicents = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) 
                    measure_set_ts((t_notation_obj *) x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            set_measure_cents_values_from_llll(x, measure_midicents, measure, force_append_notes);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}

void set_voice_durations_values_from_llll(t_score *x, t_llll* durations, t_scorevoice *voice)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = durations->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_durations = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) 
                    measure_set_ts((t_notation_obj *)x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            if (measure_durations->l_size > 0) // if this was NIL, it meant: skip the element!
                set_measure_durations_values_from_llll(x, measure_durations, measure);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}



void set_measure_durations_values_from_llll_OLD(t_score *x, t_llll* durations, t_measure *measure){
    t_llllelem *elem; t_chord *chord = measure->firstchord;
    llll_filter_zeros(durations);
    for (elem = durations->l_head; elem; elem = elem->l_next) {
        long type = hatom_gettype(&elem->l_hatom);
        if ((type == H_LONG) || (type == H_RAT)) { // duration must be rational
            
            t_rational r_sym_duration = hatom_getrational(&elem->l_hatom); 
            if (chord) { // there's already a chord: we change all its cents
                chord->r_sym_duration = r_sym_duration;
                if ((r_sym_duration.r_num > 0) && (!(chord->firstnote))) { // we want a real chord, but we have a rest! we add a dummy note
                    t_note *this_nt;
                    double argv[2]; 
                    argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                    argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                    this_nt = build_note_from_ac_av((t_notation_obj *) x, 2, argv);
                    note_insert((t_notation_obj *) x, chord, this_nt, 0);
                } else if ((r_sym_duration.r_num < 0) && (chord->firstnote)) {
                    turn_chord_into_rest(x, chord);
                } 
            } else { // there was NO chord: we create one, with just one note
                double argv[2]; 
                argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                chord = addchord_in_measure_from_values(x, measure, measure->lastchord, rat_abs(r_sym_duration), -1,  1, 2 , argv, NULL, NULL, 0, NULL, 0, NULL);
                chord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, chord, 0, WHITENULL_llll);
                if (r_sym_duration.r_num < 0)
                    turn_chord_into_rest(x, chord);
            } 
            chord = chord->next;
        }
    }
    
    verbose_print(x);
}


t_llll *prepend_all_sym_to_long(long num){
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_all, 0, WHITENULL_llll);
    llll_appendlong(out, num, 0, WHITENULL_llll);
    return out;
}

long convert_zeros_into_grace_note_levels_fn(void *data, t_hatom *a, const t_llll *address){
    if (hatom_gettype(a) == H_LLLL){
        t_llll *box = hatom_getllll(a);
        t_llllelem *elem = box->l_head;
        t_notation_obj *r_ob = (t_notation_obj *)data;
        
        while (elem){
            t_llllelem *nextelem = elem->l_next;
            if (is_hatom_number(&elem->l_hatom) && hatom_getrational(&elem->l_hatom).r_num == 0){
                t_llllelem *until = elem->l_next;
                t_rational eighth = RAT_1OVER8;
                
                hatom_setrational(&elem->l_hatom, eighth);

                if (r_ob->try_to_beam_grace_sequences) {
                    while (until && is_hatom_number(&until->l_hatom) && hatom_getrational(&until->l_hatom).r_num == 0) {
                        hatom_setrational(&until->l_hatom, eighth);
                        until = until->l_next;
                    }
                }
                
                nextelem = until;
                
                t_llll *wrapped = llll_wrap_element_range(elem, until ? until->l_prev : box->l_tail);
                if (wrapped)
                    llll_prependsym(wrapped, _llllobj_sym_g, 0, WHITENULL_llll);
            }
            elem = nextelem;
        }
    }
    return 0;
}


void set_measure_durations_values_from_llll(t_score *x, t_llll* durations, t_measure *measure)
{
    char is_grace = false;
    
    t_chord *chord = measure->firstchord;
    t_llll *durations_clone = llll_get(), *duration_clone_original; // we operate on a copy, for grace note reason
    t_llll *tree = llll_get();
    t_rational total_dur = long2rat(0);
    
    llll_clone_upon(durations, durations_clone);
    duration_clone_original = durations_clone;
    
    // converting 0's into grace note levels
    llll_funall(durations_clone, convert_zeros_into_grace_note_levels_fn, x, 1, -1, FUNALL_SKIP_ATOMS);
    
    t_llllelem *durselem = durations_clone->l_head;
    t_llll *templl2;
    t_llll_stack *dursstack = llll_stack_new();
    t_llll_stack *treestack = llll_stack_new();

    t_chord *last_introduced_chord = NULL;
    
    if (measure)
        free_rhythmic_tree((t_notation_obj *)x, measure);
        
    while (1) {
        while (durselem) {
            switch(durselem->l_hatom.h_type) {
                case H_LONG:
                case H_RAT:
                {
                    t_rational r_sym_duration = hatom_getrational(&durselem->l_hatom); 
                    if (chord) { // there's already a chord: we change all its cents
                        if (is_grace) 
                            r_sym_duration = rat_long_prod(rat_abs(r_sym_duration), isign(chord->r_sym_duration.r_num));    // this is a special case: with grace chords we keep the existing status (chord or note), since for both we might use the "0" syntax
                            
                        chord->r_sym_duration = r_sym_duration;
                        
                        if (!is_grace)
                            total_dur = rat_rat_sum(total_dur, rat_abs(r_sym_duration));
                            
                        if (r_sym_duration.r_num > 0 && !chord->firstnote) { 
                            // we want a real chord, but we have a rest! 
                            // Up to bach 0.7.1, what we did was to add a dummy note.
                            // However, if we are at this point and there's no chord->firstnote is because
                            // the user has inserted a cents separate syntax with a chord having no notes, 
                            // i.e. s/he wanted a rest. 
                            // From bach 0.7.2, both durations and cents are capable to define rests, thus
                            // this portion of code is not used any more:
                            
/*                            t_note *this_nt;
                            double argv[2]; 
                            argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                            argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                            this_nt = build_note_from_ac_av((t_notation_obj *) x, 2, argv);
                            note_insert((t_notation_obj *) x, chord, this_nt, 0); */

                            // on the other hand, what we do is to change the r_sym_duration: the user
                            // clearly wanted to have a rest!
                            
                            chord->r_sym_duration = r_sym_duration = rat_opp(r_sym_duration);
                            
                        } else if (r_sym_duration.r_num < 0 && chord->firstnote) {
                            turn_chord_into_rest(x, chord);
                        } 
                    } else { // there was NO chord: we create one, with just one note
                        double argv[2];
                        argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                        argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                        chord = addchord_in_measure_from_values(x, measure, measure->lastchord, rat_abs(r_sym_duration), -1,  1, 2 , argv, NULL, NULL, 0, NULL, 0, NULL);
                        total_dur = rat_rat_sum(total_dur, rat_abs(r_sym_duration));
                        if (r_sym_duration.r_num < 0)
                            turn_chord_into_rest(x, chord);
                    } 
                    
                    chord->rhythmic_tree_elem = llll_appendobj(tree, chord, 0, WHITENULL_llll);
                    
                    // checking grace chord
                    chord->is_grace_chord = is_grace;
                    
                    last_introduced_chord = chord;
                    
                    // checking ties NOT ANY MORE: See the H_SYM case!
/*                    if (durselem->l_next && hatom_gettype(&durselem->l_next->l_hatom) == H_SYM && hatom_getsym(&durselem->l_next->l_hatom) == _llllobj_sym_t){
                        // tie
                        t_note *temp;
                        for (temp = chord->firstnote; temp; temp = temp->next)
                            temp->tie_to = (t_note *) WHITENULL;

                        durselem = durselem->l_next;
                    }
*/                    
                    chord = chord->next;
                    durselem = durselem->l_next;
                    break;
                }

                case H_SYM:
                    if (hatom_getsym(&durselem->l_hatom) == _llllobj_sym_g) {
                        if (tree)
                            set_level_type_flag_for_level(tree, k_RHYTHM_LEVEL_GRACE);
                        is_grace = true;
                    } else if (last_introduced_chord && hatom_getsym(&durselem->l_hatom) == _llllobj_sym_t) {
                        t_note *temp;
                        for (temp = last_introduced_chord->firstnote; temp; temp = temp->next)
                            temp->tie_to = (t_note *) WHITENULL;
                    }
                    durselem = durselem->l_next;
                    break;
                    
                case H_LLLL:
                    llll_stack_push(treestack, tree);

                    templl2 = llll_get();

                    llll_stack_push(dursstack, durselem->l_next);
                    
                    durations_clone = durselem->l_hatom.h_w.w_llll;
                    durselem = durations_clone->l_head;

                    templl2->l_depth = durations_clone->l_depth;        
                    llll_appendllll(tree, templl2, 0, WHITENULL_llll);
                    tree = templl2;
                    break;

                case H_DOUBLE:
                case H_OBJ:
                default:
                    durselem = durselem->l_next;
                    break;
            }
        } 
        
        if (!dursstack->s_items)
            break; 
        
        is_grace = false;
        durselem = (t_llllelem *) llll_stack_pop(dursstack);
        tree = (t_llll *) llll_stack_pop(treestack);
    }
    
    llll_stack_destroy(dursstack);
    llll_stack_destroy(treestack);
    
    llll_free(duration_clone_original);
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, measure, gensym("MMM"), 0);
    
    // are there chords to which we did NOT assign a rhythmic element?
    if (chord) {
        t_chord *tmpch = chord;
        long how_many = 0;
        while (tmpch) {
            how_many++;
            tmpch = tmpch->next;
        }
        t_rational dur_for_each = rat_long_div(rat_rat_diff(measure_get_sym_duration(measure), total_dur), how_many);
        if (rat_long_cmp(dur_for_each, 0) > 0) {
            tmpch = chord;
            while (tmpch) {
                tmpch->r_sym_duration = rat_long_prod(dur_for_each, isign(tmpch->r_sym_duration.r_num));
                tmpch->rhythmic_tree_elem = llll_appendobj(tree, tmpch, 0, WHITENULL_llll);
                tmpch = tmpch->next;
            }
        } else {
            t_chord *nxt;
            tmpch = chord;
            while (tmpch) {
                nxt = tmpch->next;
                chord_delete_from_measure((t_notation_obj *) x, tmpch, true);
                tmpch = nxt;
            }
        }
    }
    
    measure->rhythmic_tree = tree;
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, measure, gensym("score"), 0);
    verbose_print(x);
}



void set_voice_velocities_values_from_llll(t_score *x, t_llll* velocities, t_scorevoice *voice)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = velocities->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_velocities = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) 
                    measure_set_ts((t_notation_obj *)x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            set_measure_velocities_values_from_llll(x, measure_velocities, measure);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}

void set_measure_velocities_values_from_llll(t_score *x, t_llll* measure_velocities, t_measure *measure)
{
    t_llllelem *elem; 
    t_rational onset, measure_dur;
    long num_chords, chord_num = 0;
    t_chord *chord;
    if (is_measure_empty((t_notation_obj *)x, measure) && (!x->durations_given)) measure_delete_all_chords(x, measure);
    onset = long2rat(0); measure_dur = measure_get_sym_duration(measure);
    num_chords = measure_velocities->l_size;
    chord = measure->firstchord;
    for (elem = measure_velocities->l_head; elem; elem = elem->l_next) {
        long type = hatom_gettype(&elem->l_hatom);
        if (type == H_LLLL) { // there's a nested llll, so specifications for each note
            t_llll* note_velocities = hatom_getllll(&elem->l_hatom); 
            if (chord) { // there's already a chord: we change its cents
                if (note_velocities->l_size > 0) {
                    if (chord->r_sym_duration.r_num >= 0) {
                        t_llllelem *subelem; t_note *note = chord->firstnote;
                        for (subelem = note_velocities->l_head; subelem; subelem = subelem->l_next) {
                            long subtype = hatom_gettype(&subelem->l_hatom);
                            if ((subtype == H_LONG) || (subtype == H_DOUBLE) || (subtype == H_RAT)) {
                                long vel = hatom_getlong(&subelem->l_hatom);
                                clip_long(&vel, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
                                if (note) { // there's already a note: we change its cents
                                    note_set_velocity((t_notation_obj *)x, note, vel);
                                    note = note->next;
                                } else { // we create a note within the same chord!
                                    t_note *this_nt;
                                    double argv[3]; 
                                    argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                    argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS; 
                                    argv[2] = vel; 
                                    this_nt = build_note_from_ac_av((t_notation_obj *) x, 3, argv);
                                    note_insert((t_notation_obj *) x, chord, this_nt, 0);
                                }
                            }
                        }
                    }
                    chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
                    chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                }
                chord = chord->next;
            } else { // there was NO chord: but we can create one
                t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                if (remaining_duration.r_num > 0) {
                    t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                    long num_notes = note_velocities->l_size;
                    t_chord *newchord;
                    t_llllelem *subelem; 
                    long i = 0, cc = 0;
                    double *argv;
                    if (num_notes <= 0) num_notes = 1;
                    argv = (double *) bach_newptr(3 * num_notes * sizeof(double));
                    for (subelem = note_velocities->l_head; (subelem || cc < num_notes) && i < 3 * num_notes - 2; subelem = subelem ? subelem->l_next : subelem, cc++) {
                        long vel;
                        argv[i] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                        argv[i+1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                        vel = (subelem) ? hatom_getlong(&subelem->l_hatom) : CONST_DEFAULT_NEW_NOTE_VELOCITY;
                        clip_long(&vel, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
                        argv[i+2] = vel;
                        i += 3;
                    }
                    newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 3 * num_notes, argv, NULL, NULL, 0, NULL, 0, NULL);
                    newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                    chord_num++; 
                    onset = rat_rat_sum(onset, r_sym_duration);
                    bach_freeptr(argv);
                }
            } 
            
        } else if ((type == H_LONG) || (type == H_DOUBLE) || (type == H_RAT)) { // just one cent given: we apply it to the whole chord!!
            
            long vel = hatom_getlong(&elem->l_hatom); 
            clip_long(&vel, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
            if (chord) { // there's already a chord: we change all its cents
                if (chord->r_sym_duration.r_num > 0) {
                    t_note *note = chord->firstnote;
                    while (note) {
                        note_set_velocity((t_notation_obj *)x, note, vel);
                        note = note->next;
                    }
                }
                chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
                chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                chord = chord->next;
            } else { // there was NO chord: we create one, with just one note
                t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                if (remaining_duration.r_num > 0) {
                    t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                    double argv[3]; 
                    t_chord *newchord;
                    argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                    argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                    argv[2] = vel;
                    newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1,  1, 3, argv, NULL, NULL, 0, NULL, 0, NULL);
                    newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                    chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                }
            } 
        }
    }
}

void set_voice_ties_values_from_llll(t_score *x, t_llll* ties, t_scorevoice *voice)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = ties->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_ties = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) measure_set_ts((t_notation_obj *)x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            set_measure_ties_values_from_llll(x, measure_ties, measure);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}

void set_measure_ties_values_from_llll(t_score *x, t_llll* measure_ties, t_measure *measure)
{
    t_llllelem *elem; 
    t_rational onset, measure_dur;
    long num_chords, chord_num = 0;
    t_chord *chord;
    if (is_measure_empty((t_notation_obj *)x, measure) && (!x->durations_given)) measure_delete_all_chords(x, measure);
    onset = long2rat(0); measure_dur = measure_get_sym_duration(measure);
    num_chords = measure_ties->l_size; chord_num = 0;
    chord = measure->firstchord;
    for (elem = measure_ties->l_head; elem; elem = elem->l_next) {
        long type = hatom_gettype(&elem->l_hatom);
        
        if (type == H_LLLL) { // there's a nested llll, so specifications for each note
            t_llll* note_ties = hatom_getllll(&elem->l_hatom); 
            if (chord) { // there's already a chord: we change its cents
                if (note_ties->l_size > 0) {
                    if (chord->r_sym_duration.r_num >= 0) {
                        t_llllelem *subelem; t_note *note = chord->firstnote;
                        for (subelem = note_ties->l_head; subelem; subelem = subelem->l_next) {
                            long tie = hatom_getlong(&subelem->l_hatom);
                            if (note) { // there's already a note: we change its cents
                                note->tie_to = (tie == 0) ? NULL : (t_note *) WHITENULL;
                                note = note->next;
                            } else { // we create a note within the same chord!
                                t_note *this_nt = build_default_note((t_notation_obj *) x);
                                note_insert((t_notation_obj *) x, chord, this_nt, 0);
                                this_nt->tie_to = (tie == 0) ? NULL : (t_note *) WHITENULL;
                            }
                        }
                    }
                    chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
                    chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                }
                chord = chord->next;
            } else { // there was NO chord: but we can create one
                t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                if (remaining_duration.r_num > 0) {
                    t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                    long num_notes = note_ties->l_size; 
                    if (num_notes >= 0) {
                        double *argv = (double *) bach_newptr(2 * num_notes * sizeof(double));
                        t_note *note;
                        t_llllelem *subelem; long i = 0;
                        for (subelem = note_ties->l_head; subelem && i < 2 * num_notes - 1; subelem = subelem->l_next) {
                            argv[i] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                            argv[i+1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                            i += 2;
                        }
                        chord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 2 * num_notes, argv, NULL, NULL, 0, NULL, 0, NULL);
                        chord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, chord, 0, WHITENULL_llll);
                        note = chord->firstnote;
                        for (subelem = note_ties->l_head, note = chord->firstnote; subelem && note; subelem = subelem->l_next, note = note->next) {
                            note->tie_to = (hatom_getlong(&subelem->l_hatom) == 0) ? NULL : (t_note *) WHITENULL;
                        }
                        chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                        chord = chord->next;
                        bach_freeptr(argv);
                    }
                }
            } 
            
        } else if ((type == H_LONG) || (type == H_DOUBLE) || (type == H_RAT)) { // just one cent given: we apply it to the whole chord!!
            
            long tie = hatom_getlong(&elem->l_hatom); 
            if (chord) { // there's already a chord: we change all its cents
                if (chord->r_sym_duration.r_num > 0) {
                    t_note *note = chord->firstnote;
                    while (note) {
                        note->tie_to = (tie == 0) ? NULL : (t_note *) WHITENULL;
                        note = note->next;
                    }
                }
                chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
                chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                chord = chord->next;
            } else { // there was NO chord: we create one, with just one note
                t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                if (remaining_duration.r_num > 0) {
                    t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                    double argv[2]; 
                    argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION;
                    argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                    chord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1,  1, 2, argv, NULL, NULL, 0, NULL, 0, NULL);
                    chord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, chord, 0, WHITENULL_llll);
                    chord->firstnote->tie_to = (hatom_getlong(&elem->l_hatom) == 0) ? NULL : (t_note *) WHITENULL;
                    chord = chord->next;
                    chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                }
            } 
        }
    }
}

void set_all_extras_values_from_llll(t_score *x, t_llll* extras)
{
    t_llllelem *elem;
    for (elem = extras->l_head; elem; elem = elem->l_next) {
        long type = hatom_gettype(&elem->l_hatom);
        if (type == H_SYM) { 
            // we just have 1 extra, so the user has omitted one level of ( .... )
            if (hatom_getsym(&elem->l_hatom) == _llllobj_sym_breakpoints) {
                llll_destroyelem(elem);
                set_all_breakpoints_values_from_llll(x, extras); 
            } else if (hatom_getsym(&elem->l_hatom) == _llllobj_sym_slots) {
                llll_destroyelem(elem);
                set_all_slots_values_from_llll(x, extras);
            } else if (hatom_getsym(&elem->l_hatom) == _llllobj_sym_graphic) {
                llll_destroyelem(elem);
                set_all_graphic_values_from_llll(x, extras);
            } else if (hatom_getsym(&elem->l_hatom) == _llllobj_sym_articulations) {
                llll_destroyelem(elem);
                set_all_articulations_values_from_llll(x, extras);
            }
            return;
        } else if (type == H_LLLL) { // there's a nested llll, so specifications for each extra
            t_llll* this_extra = hatom_getllll(&elem->l_hatom); 
            if (this_extra->l_size >= 1) {
                t_llllelem *pivot = this_extra->l_head;
                if (pivot) {
                    if (hatom_gettype(&pivot->l_hatom) == H_SYM) {
                        if (hatom_getsym(&pivot->l_hatom) == _llllobj_sym_breakpoints) {
                            llll_destroyelem(pivot);
                            set_all_breakpoints_values_from_llll(x, this_extra);
                        } else if (hatom_getsym(&pivot->l_hatom) == _llllobj_sym_slots) {
                            llll_destroyelem(pivot);
                            set_all_slots_values_from_llll(x, this_extra);
                        } else if (hatom_getsym(&pivot->l_hatom) == _llllobj_sym_graphic) {
                            llll_destroyelem(pivot);
                            set_all_graphic_values_from_llll(x, this_extra);
                        } else if (hatom_getsym(&pivot->l_hatom) == _llllobj_sym_articulations) {
                            llll_destroyelem(pivot);
                            set_all_articulations_values_from_llll(x, this_extra);
                        }
                    }
                }
            }
        }
        
    }
    
    recompute_all(x);
    verbose_print(x);
}

void set_voice_graphic_values_from_llll(t_score *x, t_llll* graphic, t_scorevoice *voice)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = graphic->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_graphic = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) measure_set_ts((t_notation_obj *)x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            set_measure_graphic_values_from_llll(x, measure_graphic, measure);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}

void set_voice_breakpoints_values_from_llll(t_score *x, t_llll* breakpoints, t_scorevoice *voice)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = breakpoints->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_breakpoints = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) measure_set_ts((t_notation_obj *)x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            set_measure_breakpoints_values_from_llll(x, measure_breakpoints, measure);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}

void set_voice_articulation_values_from_llll(t_score *x, t_llll* articulations, t_scorevoice *voice)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = articulations->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_articulations = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) measure_set_ts((t_notation_obj *)x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            set_measure_articulations_values_from_llll(x, measure_articulations, measure);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}


void set_voice_slots_values_from_llll(t_score *x, t_llll* slots, t_scorevoice *voice)
{
    t_llllelem *velem; t_measure *measure = voice->firstmeasure;
    for (velem = slots->l_head; velem; velem = velem->l_next) {
        if (hatom_gettype(&velem->l_hatom) == H_LLLL) { // measure specification
            t_llll* measure_slots = hatom_getllll(&velem->l_hatom); 
            if (!measure) { // if the measure does not exist, we create it
                measure = build_measure((t_notation_obj *) x, NULL);
                if (voice->lastmeasure) measure_set_ts((t_notation_obj *)x, measure, &voice->lastmeasure->timesignature);
                insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, 0);
            }
            set_measure_slots_values_from_llll(x, measure_slots, measure);
            measure = measure->next;
        }
    }
    
    recompute_all(x);
    verbose_print(x);
}

void set_measure_graphic_values_from_llll(t_score *x, t_llll* graphic, t_measure *measure)
{
    t_llllelem *elem; 
    long num_chords, chord_num = 0;
    t_rational onset, measure_dur;
    t_chord *chord;
    if (is_measure_empty((t_notation_obj *)x, measure) && (!x->durations_given)) measure_delete_all_chords(x, measure);
    num_chords = graphic->l_size; chord_num = 0;
    onset = long2rat(0); measure_dur = measure_get_sym_duration(measure);
    chord = measure->firstchord; // For instance: graphic = (((6000 1/4) (7000 1/8)) (7000 -1/4))
    for (elem = graphic->l_head; elem; elem = elem->l_next) { // elem cycles on the chords, e.g. elem = ((6000 1/4) (7000 1/8))    or    elem = (7000 -1/4) 
        long type = hatom_gettype(&elem->l_hatom);
        if (chord) { 
            
            if (type == H_LLLL) { // it has to be a LLLL
                t_llll *notes_graphic = hatom_getllll(&elem->l_hatom); 
                if (notes_graphic->l_size > 0) { // it has to be non nil!
                    
                    if (notes_graphic->l_depth == 2) { //there are specifications for each note, e.g.: elem = ((6000 1/4) (7000 1/8))
                        
                        t_llllelem *subelem; t_note *note = chord->firstnote;
                        for (subelem = notes_graphic->l_head; subelem; subelem = subelem->l_next) { // subelem cycles on the notes
                            long subtype = hatom_gettype(&subelem->l_hatom);
                            if (subtype == H_LLLL) {
                                t_llll *graphic = hatom_getllll(&subelem->l_hatom);
//                                if ((graphic->l_size >= 2) && (graphic->l_depth == 1)) {
                                    if (note){ // there's already a note: we change its graphic values
                                        set_graphic_values_to_note_from_llll((t_notation_obj *) x, note, graphic);
                                    } else { // we create a note within the same chord!
                                        if (graphic && graphic->l_size >= 2) {
                                            t_note *this_nt;
                                            double argv[2];
                                            long screen_mc = hatom_getlong(&graphic->l_head->l_hatom);
                                            t_rational screen_acc = hatom_getrational(&graphic->l_head->l_next->l_hatom);
                                            argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION;
                                            if (!(is_natural_note(screen_mc))) {
                                                object_warn((t_object *) x, "Wrong graphic approximation introduced. Dummy note created.");
                                                screen_mc = CONST_DEFAULT_NEW_NOTE_CENTS;
                                                screen_acc = long2rat(0);
                                            }
                                            argv[1] = rat2double(rat_long_sum(rat_long_prod(screen_acc, 200), screen_mc));
                                            this_nt = build_note_from_ac_av((t_notation_obj *) x, 2, argv);
                                            note_insert((t_notation_obj *) x, chord, this_nt, 0);
                                            set_graphic_values_to_note_from_llll((t_notation_obj *) x, this_nt, graphic);
                                        }
                                    }
//                                }
                            }
                            if (note) note = note->next;
                        }
                        
                    } else if (notes_graphic->l_depth == 1) { // there is just 1 specification for the whole chord, e.g. elem = (7000 -1/4)
                        
                        if (notes_graphic->l_size >= 2) {
                            t_note *note = chord->firstnote;
                            while (note) {
                                set_graphic_values_to_note_from_llll((t_notation_obj *) x, note, notes_graphic);
                                note = note->next;
                            }
                        }
                    }
                    
                    chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                }
            }
            
            chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
            chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);

            chord = chord->next;
            
        } else { // there's no chord: we create one
            
            if (type == H_LLLL) { // it has to be a LLLL
                t_llll *notes_graphic = hatom_getllll(&elem->l_hatom); 
                if (notes_graphic->l_size > 0) { // it has to be non nil!
                    
                    t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                    if (remaining_duration.r_num > 0) {
                        
                        t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                        
                        if (notes_graphic->l_depth == 2) { //there are specifications for each note, e.g.: elem = ((6000 1/4) (7000 1/8))
                            long num_notes = notes_graphic->l_size;
                            if (num_notes > 0) {
                                double *argv = (double *) bach_newptr(2 * num_notes * sizeof(double)); 
                                t_llllelem *subelem; long i = 0;
                                for (subelem = notes_graphic->l_head; subelem && i < 2 * num_notes - 1; subelem = subelem->l_next) {
                                    if (hatom_gettype(&subelem->l_hatom) == H_LLLL) {
                                        t_llll *subelemllll = hatom_getllll(&subelem->l_hatom);
                                        if (subelemllll->l_size >= 2) {
                                            long screen_mc = hatom_getlong(&subelemllll->l_head->l_hatom);
                                            t_rational screen_acc = hatom_getrational(&subelemllll->l_head->l_next->l_hatom);
                                            argv[i] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                            if (!(is_natural_note(screen_mc))) {
                                                object_warn((t_object *) x, "Wrong graphic approximation introduced. Dummy note created.");
                                                screen_mc = CONST_DEFAULT_NEW_NOTE_CENTS;
                                                screen_acc = long2rat(0);
                                            }
                                            argv[i+1] = rat2double(rat_long_sum(rat_long_prod(screen_acc, 200), screen_mc));
                                            i += 2;
                                        }
                                    }
                                }
                                num_notes = i / 2;
                                if (num_notes > 0) {
                                    t_chord *newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 2 * num_notes, argv, NULL, NULL, 0, NULL, 0, NULL);
                                    t_note *newnote = newchord->firstnote;
                                    newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                                    for (subelem = notes_graphic->l_head; subelem; subelem = subelem->l_next) { // subelem cycles on the notes, e.g. subelem = (6000 1/4)
                                        t_llll *graphic = hatom_getllll(&subelem->l_hatom);
                                        set_graphic_values_to_note_from_llll((t_notation_obj *) x, newnote, graphic);
                                        newnote = newnote->next;
                                    } 
                                    chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                                }
                                bach_freeptr(argv);
                            }
                        } else if (notes_graphic->l_depth == 1) { // there's only one specification for the whole chord
                            if (notes_graphic->l_size >= 2) { // we need screen_cents and screen_accidental
                                double argv[2];
                                long screen_mc = hatom_getlong(&notes_graphic->l_head->l_hatom);
                                t_rational screen_acc = hatom_getrational(&notes_graphic->l_head->l_next->l_hatom);
                                t_chord *newchord;
                                argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                if (!(is_natural_note(screen_mc))) {
                                    object_warn((t_object *) x, "Wrong graphic approximation introduced. Dummy note created.");
                                    screen_mc = CONST_DEFAULT_NEW_NOTE_CENTS;
                                    screen_acc = long2rat(0);
                                }
                                argv[1] = rat2double(rat_long_sum(rat_long_prod(screen_acc, 200), screen_mc));
                                newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, 1, 2, argv, NULL, NULL, 0, NULL, 0, NULL);
                                newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                                set_graphic_values_to_note_from_llll((t_notation_obj *) x, newchord->firstnote, notes_graphic);
                                chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                            }
                        }
                        
                    }
                }
                
                
            } 
        }
    }
}


void set_measure_breakpoints_values_from_llll(t_score *x, t_llll* breakpoints, t_measure *measure)
{
    t_llllelem *elem; t_chord *chord = measure->firstchord; // For instance: breakpoints = (  ((0 0 0) (1 1 1))   (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1))) )
    t_rational onset, measure_dur;
    long num_chords, chord_num = 0;
    if (is_measure_empty((t_notation_obj *)x, measure) && (!x->durations_given)) measure_delete_all_chords(x, measure);
    onset = long2rat(0); measure_dur = measure_get_sym_duration(measure);
    num_chords = breakpoints->l_size; chord_num = 0;
    
    for (elem = breakpoints->l_head; elem; elem = elem->l_next) { // elem cycles on the chords, e.g. elem = (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1)))    or    elem = ((0 0 0) (1 1 1)) 
        long type = hatom_gettype(&elem->l_hatom);
        if (chord) { 
            
            if (type == H_LLLL) { // it must to be a LLLL
                t_llll *notes_bpt = hatom_getllll(&elem->l_hatom); 
                if (notes_bpt->l_size > 0) { // it has to be non nil!
                    
                    if (notes_bpt->l_depth == 3) { //there are specifications for each note, e.g.: elem = (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1)))
                        
                        t_llllelem *subelem; t_note *note = chord->firstnote;
                        for (subelem = notes_bpt->l_head; subelem; subelem = subelem->l_next) { // subelem cycles on the notes, e.g. subelem = ((0 0 0) (0.5 20 0.) (1 1 1))
                            long subtype = hatom_gettype(&subelem->l_hatom);
                            if (subtype == H_LLLL) { // it must be a LLLL
                                t_llll *bpt = hatom_getllll(&subelem->l_hatom);
//                                if ((bpt->l_size >= 1) && (bpt->l_depth == 2)) {
                                    if (note){ // there's already a note: we change its graphic values
                                        note_set_breakpoints_from_llll((t_notation_obj *) x, note, bpt);
                                    } else { // we create a note within the same chord!
                                        t_note *this_nt;
                                        double argv[2]; argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                        argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                                        this_nt = build_note_from_ac_av((t_notation_obj *) x, 2, argv);
                                        note_insert((t_notation_obj *) x, chord, this_nt, 0);
                                        note_set_breakpoints_from_llll((t_notation_obj *) x, this_nt, bpt);
                                    }
//                                }
                            }
                            if (note) note = note->next;
                        }
                        
                    } else if (notes_bpt->l_depth == 2) { // there is just 1 specification for the whole chord, e.g. elem = ((0 0 0) (1 1 1))
                        
                        if (notes_bpt->l_size >= 1) {
                            t_note *note = chord->firstnote;
                            while (note) {
                                note_set_breakpoints_from_llll((t_notation_obj *) x, note, notes_bpt);
                                note = note->next;
                            }
                        }
                        
                    }
                    
                    chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                }
            }
            
            chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
            chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);

            chord = chord->next;
            
        } else { // there's no chord: we create one
            
            if (type == H_LLLL) { // it has to be a LLLL
                t_llll *notes_bpt = hatom_getllll(&elem->l_hatom); 
                if (notes_bpt->l_size > 0) { // it has to be non nil! it is the # of notes
                    
                    t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                    if (remaining_duration.r_num > 0) {
                        t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                        
                        if (notes_bpt->l_depth == 3) { //there are specifications for each note,  e.g.: elem = (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1)))
                            
                            long num_notes = notes_bpt->l_size;
                            if (num_notes >= 0) {
                                t_chord *newchord;
                                t_note *newnote;
                                double *argv = (double *) bach_newptr(2 * num_notes * sizeof(double)); 
                                t_llllelem *subelem; long i = 0;
                                for (subelem = notes_bpt->l_head; subelem && i < 2 * num_notes - 1; subelem = subelem->l_next) {
                                    if (hatom_gettype(&subelem->l_hatom) == H_LLLL) {
                                        t_llll *subelemllll = hatom_getllll(&subelem->l_hatom);
                                        if (subelemllll->l_size >= 1) {
                                            argv[i] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                            argv[i+1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                                            i += 2;
                                        }
                                    }
                                }
                                num_notes = i / 2;
                                newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 2 * num_notes, argv, NULL, NULL, 0, NULL, 0, NULL);
                                newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                                newnote = newchord->firstnote;
                                for (subelem = notes_bpt->l_head; subelem; subelem = subelem->l_next) { // subelem cycles on the notes, e.g. subelem = ((0 0 0) (1 1 1))
                                    t_llll *bpts = hatom_getllll(&subelem->l_hatom);
                                    note_set_breakpoints_from_llll((t_notation_obj *) x, newnote, bpts);
                                    newnote = newnote->next;
                                } 
                                chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                                chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                                bach_freeptr(argv);
                            }
                        } else if (notes_bpt->l_depth == 2) { // there's only one specification for the whole chord, e.g. notes_bpt = ((0 0 0) (1 1 1))
                            
                            if ((notes_bpt->l_size >= 1) && (hatom_gettype(&notes_bpt->l_head->l_hatom) != H_LLLL)) { 
                                double argv[2];
                                t_chord *newchord;
                                argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                                newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, 1, 2, argv, NULL, NULL, 0, NULL, 0, NULL);
                                newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                                note_set_breakpoints_from_llll((t_notation_obj *) x, newchord->firstnote, notes_bpt);
                                chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                                chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                            }
                        }
                    }    
                }
            } 
        }
    }
}


void set_measure_articulations_values_from_llll(t_score *x, t_llll* articulations, t_measure *measure)
{
    t_llllelem *elem; t_chord *chord = measure->firstchord; // For instance: breakpoints = (  ((0 0 0) (1 1 1))   (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1))) )
    t_rational onset, measure_dur;
    long num_chords, chord_num = 0;
    if (is_measure_empty((t_notation_obj *)x, measure) && (!x->durations_given)) measure_delete_all_chords(x, measure);
    onset = long2rat(0); measure_dur = measure_get_sym_duration(measure);
    num_chords = articulations->l_size; chord_num = 0;
    
    for (elem = articulations->l_head; elem; elem = elem->l_next) { // elem cycles on the chords, e.g. elem = (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1)))    or    elem = ((0 0 0) (1 1 1)) 
        long type = hatom_gettype(&elem->l_hatom);
        if (chord) { 
            
            if (type == H_LLLL) { // info for each note
                t_llll *notes_bpt = hatom_getllll(&elem->l_hatom);
                t_llllelem *elem2; 
                t_note *note = chord->firstnote;
                
                for (elem2 = notes_bpt->l_head; elem2; elem2 = elem2->l_next){
                    if (note){ // there's already a note: we change its graphic values
                        set_articulations_to_element_from_hatom((t_notation_obj *) x, (t_notation_item *)note, &elem2->l_hatom);
                    } else { // we create a note within the same chord!
                        t_note *this_nt = build_default_note((t_notation_obj *) x);
                        note_insert((t_notation_obj *) x, chord, this_nt, 0);
                        set_articulations_to_element_from_hatom((t_notation_obj *) x, (t_notation_item *)this_nt, &elem2->l_hatom);
                    }
                    if (note) note = note->next;
                }
            } else { // info for the chord
                set_articulations_to_element_from_hatom((t_notation_obj *) x, (t_notation_item *)chord, &elem->l_hatom);
            }
            
            chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
            chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);

            chord = chord->next;
            
        } else { // there's no chord: we create one
            
            t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
            if (remaining_duration.r_num > 0) {
                t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                
                t_llll *notes_bpt = hatom_getllll(&elem->l_hatom);
                
                if (type == H_LLLL) { // info for each note
                    
                    long num_notes = notes_bpt->l_size;
                    if (num_notes >= 0) {
                        t_chord *newchord;  
                        t_note *newnote;
                        double *argv = (double *) bach_newptr(2 * num_notes * sizeof(double)); 
                        t_llllelem *subelem; 
                        long i = 0;
                        for (subelem = notes_bpt->l_head; subelem && i < 2 * num_notes - 1; subelem = subelem->l_next) {
                            argv[i] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                            argv[i+1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                        }
                        newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 2 * num_notes, argv, NULL, NULL, 0, NULL, 0, NULL);
                        newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                        newnote = newchord->firstnote;
                        for (subelem = notes_bpt->l_head; subelem; subelem = subelem->l_next) { // subelem cycles on the notes, e.g. subelem = ((0 0 0) (1 1 1))
                            set_articulations_to_element_from_hatom((t_notation_obj *) x, (t_notation_item *)newnote, &subelem->l_hatom);
                            newnote = newnote->next;
                        } 
                        chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                        chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                        bach_freeptr(argv);
                    }
                } else { // there's only one specification for the whole chord, e.g. notes_bpt = ((0 0 0) (1 1 1))
                    
                    double argv[2];
                    t_chord *newchord;
                    argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                    argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                    newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, 1, 2, argv, NULL, NULL, 0, NULL, 0, NULL);
                    newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                    set_articulations_to_element_from_hatom((t_notation_obj *) x, (t_notation_item *)newchord, &elem->l_hatom);
                    chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                    chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                }
            }    
        }
    }
}


void set_measure_slots_values_from_llll(t_score *x, t_llll* slots, t_measure *measure)
{
    t_llllelem *elem; t_chord *chord = measure->firstchord; // For instance: slots = (  ((0 0 0) (1 1 1))   (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1))) )
    t_rational onset, measure_dur;
    long num_chords, chord_num = 0;
    if (is_measure_empty((t_notation_obj *)x, measure) && !x->durations_given) measure_delete_all_chords(x, measure);
    onset = long2rat(0); measure_dur = measure_get_sym_duration(measure);
    num_chords = slots->l_size;
    
    for (elem = slots->l_head; elem; elem = elem->l_next) { // elem cycles on the chords, e.g. elem = (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1)))    or    elem = ((0 0 0) (1 1 1)) 
        long type = hatom_gettype(&elem->l_hatom);
        if (chord) { 
            
            if (type == H_LLLL) { // it must to be a LLLL
                t_llll *notes_slots = hatom_getllll(&elem->l_hatom); 
                if (notes_slots ->l_size > 0) { // it has to be non nil!
                    
                    char specif_for_each_note = true; 
                    if (hatom_gettype(&notes_slots->l_head->l_hatom) != H_LLLL) 
                        specif_for_each_note = false;
                    else if ((hatom_gettype(&notes_slots->l_head->l_hatom) == H_LLLL) &&
                             (hatom_getllll(&notes_slots->l_head->l_hatom)->l_size > 0) && 
                             (hatom_gettype(&hatom_getllll(&notes_slots->l_head->l_hatom)->l_head->l_hatom) != H_LLLL))
                        specif_for_each_note = false;
                    
                    if (specif_for_each_note) { //there are specifications for each note, e.g.: elem = (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1)))
                        
                        t_llllelem *subelem; t_note *note = chord->firstnote;
                        for (subelem = notes_slots->l_head; subelem; subelem = subelem->l_next) { // subelem cycles on the notes, e.g. subelem = ((0 0 0) (0.5 20 0.) (1 1 1))
                            long subtype = hatom_gettype(&subelem->l_hatom);
                            if (subtype == H_LLLL) { // it must be a LLLL
                                t_llll *slots = hatom_getllll(&subelem->l_hatom);
//                                if (slots->l_size >= 1) {
                                    if (note){ // there's already a note: we change its graphic values
                                        note_set_slots_from_llll((t_notation_obj *) x, note, slots);
                                    } else { // we create a note within the same chord!
                                        t_note *this_nt = build_default_note((t_notation_obj *) x);
                                        note_insert((t_notation_obj *) x, chord, this_nt, 0);
                                        note_set_slots_from_llll((t_notation_obj *) x, this_nt, slots);
                                    }
//                                }
                            }
                            if (note) note = note->next;
                        }
                        
                    } else if (notes_slots->l_depth >= 2) { // there is just 1 specification for the whole chord, e.g. elem = ((0 0 0) (1 1 1))
                        
                        if (notes_slots->l_size >= 1) {
                            t_note *note = chord->firstnote;
                            
#ifdef BACH_CHORDS_HAVE_SLOTS
                            if (!note) {
                                // set slots to rest
                                notation_item_set_slots_from_llll((t_notation_obj *) x, (t_notation_item *)chord, notes_slots);
                            } else {
                                while (note) {
                                    note_set_slots_from_llll((t_notation_obj *) x, note, notes_slots);
                                    note = note->next;
                                }
                            }
#else
                            while (note) {
                                note_set_slots_from_llll((t_notation_obj *) x, note, notes_slots);
                                note = note->next;
#endif
                        }
                        
                    }
                    
                    chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                }
            }
            
            chord_num++; onset = rat_rat_sum(onset, rat_abs(chord->r_sym_duration));
            chord = chord->next;
            
        } else { // there's no chord: we create one
            
            if (type == H_LLLL) { // it has to be a LLLL
                t_llll *notes_slots = hatom_getllll(&elem->l_hatom); 
                if (notes_slots->l_size > 0) { // it has to be non nil!
                    
                    t_rational remaining_duration = rat_rat_diff(measure_dur, onset);
                    if (remaining_duration.r_num > 0) {
                        t_rational r_sym_duration = rat_long_div(remaining_duration, num_chords - chord_num);
                        
                        if (hatom_gettype(&notes_slots->l_head->l_hatom) == H_LLLL) { //there are specifications for each note,  e.g.: elem = (((0 0 0) (1 1 1)) ((0 0 0) (0.5 20 0.) (1 1 1)))
                            
                            long num_notes = notes_slots->l_size;
                            if (num_notes > 0) {
                                double *argv = (double *) bach_newptr(2 * num_notes * sizeof(double)); 
                                t_llllelem *subelem; 
                                long z = 0;
                                for (subelem = notes_slots->l_head; subelem && z < 2 * num_notes - 1; subelem = subelem->l_next) {
                                    if (hatom_gettype(&subelem->l_hatom) == H_LLLL) {
                                        t_llll *telem = hatom_getllll(&subelem->l_hatom);
                                        if (telem->l_size > 0) {
                                            argv[z] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                            argv[z+1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                                            z += 2;
                                        }
                                    }
                                }
                                num_notes = z / 2;
                                if (num_notes > 0) {
                                    t_note *newnote;
                                    t_chord *newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 2 * num_notes, argv, NULL, NULL, 0, NULL, 0, NULL);
                                    newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                                    chord_num++; 
                                    onset = rat_rat_sum(onset, r_sym_duration);
                                    newnote = newchord->firstnote;
                                    for (subelem = notes_slots->l_head; subelem; subelem = subelem->l_next) { // subelem cycles on the notes, e.g. subelem = ((0 0 0) (1 1 1))
                                        note_set_slots_from_llll((t_notation_obj *) x, newnote, hatom_getllll(&subelem->l_hatom));
                                        newnote = newnote->next;
                                    } 
                                    chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                                }
                                bach_freeptr(argv);
                            }
                            
                        } else { // there's only one specification for the whole chord, e.g. notes_bpt = ((0 0 0) (1 1 1))
                            if (notes_slots->l_size >= 1) {
                                t_llll *slots = llll_get();
#ifdef BACH_CHORDS_HAVE_SLOTS
                                // ==> we create a REST: if one wanted to have notes,
                                notation_item_set_slots_from_llll((t_notation_obj *) x, (t_notation_item *)chord, notes_slots);
                                t_chord *newchord = addchord_in_measure_from_notes(x, measure, measure->lastchord, r_sym_duration, -1, 0, NULL, NULL, 0);
#else
                                double argv[2];
                                t_chord *newchord;
                                argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION;
                                argv[1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                                newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, 1, 2, argv, NULL, NULL, 0, NULL, 0, NULL);
#endif
                                newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
                                chord_num++; onset = rat_rat_sum(onset, r_sym_duration);
                                llll_appendllll_clone(slots, notes_slots, 0, WHITENULL_llll);
                                note_set_slots_from_llll((t_notation_obj *) x, newchord->firstnote, slots);
                                chord_set_recompute_parameters_flag((t_notation_obj *)x, newchord);
                                llll_free(slots);
                            }
                        }
                    }
                }
                
                
            } 
        }
    }
}


void set_clefs_from_llll(t_score *x, t_llll* clefs)
{
    if (clefs) {
        t_atom *av = NULL;
        long ac = llll_deparse(clefs, &av, 0, LLLL_D_NONE); // it's important that we do not backtick symbols, for instance G8vb can be interpreted as pitch and backticked!
        score_setattr_clefs(x, NULL, ac, av);
        if (av) bach_freeptr(av);
    }
}

void set_keys_from_llll(t_score *x, t_llll* keys)
{
    if (keys) {
        t_atom *av = NULL;
        long ac = llll_deparse(keys, &av, 0, 1);
        score_setattr_keys(x, NULL, ac, av);
        if (av) bach_freeptr(av);
    }
}

t_max_err score_setattr_clefs(t_score *x, t_object *attr, long ac, t_atom *av){

    x->r_ob.private_flag = 0;
    t_max_err err = notationobj_setattr_clefs((t_notation_obj *)x, attr, ac, av);

    char must_unlock = true;
    if (trylock_general_mutex((t_notation_obj *)x))
        must_unlock = false; // already locked

    recompute_all_except_for_beamings_and_autocompletion_and_redraw(x);
    if (x->r_ob.private_flag) {
        perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DONT_CHANGE_LEVELS + k_BEAMING_CALCULATION_DONT_CHANGE_CHORDS + k_BEAMING_CALCULATION_DONT_CHANGE_TIES);
    }
    
    if (must_unlock)
        unlock_general_mutex((t_notation_obj *)x);
    return err;
}

void compute_all_notes_approximations(t_score *x, char also_put_show_accidental_to_false){
    t_scorevoice *voice; t_measure *temp_meas;
    for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next)
        for (temp_meas = voice->firstmeasure; temp_meas; temp_meas = temp_meas->next)
            compute_note_approximations_for_measure((t_notation_obj *)x, temp_meas, also_put_show_accidental_to_false);
}

t_max_err score_setattr_keys(t_score *x, t_object *attr, long ac, t_atom *av)
{
    char must_unlock = true;
    if (trylock_general_mutex((t_notation_obj *)x))
        must_unlock = false; // already locked

    t_max_err err = notationobj_setattr_keys((t_notation_obj *)x, attr, ac, av);
    check_all_voices_fullaccpatterns((t_notation_obj *)x);
    compute_all_notes_approximations(x, true); 
    recalculate_all_chord_parameters(x);
    recalculate_all_beams_positions(x); // by calling this it will also validate the accidentals for all measures.
    
    if (must_unlock)
        unlock_general_mutex((t_notation_obj *)x);
    
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
    return err;
}

t_max_err score_setattr_align(t_score *x, t_object *attr, long ac, t_atom *av){
    if (ac && av) {
        x->r_ob.align_chords_with_what = CLAMP(atom_getlong(av), 0, 2);
        recompute_all_and_redraw(x);
    }
    return MAX_ERR_NONE;
}


void set_measure_from_llll(t_score *x, t_measure *measure, t_llll *measelemllll, char also_set_tempi,
                           char when_no_ts_given_use_previous_measure_ts, char *need_update_solos)
{
    if (measelemllll->l_size > 0) {
        t_llllelem *elem;
        t_llll* tsllll = NULL; 
        t_llll* tempollll = NULL; 
        char measurebarline = k_BARLINE_AUTOMATIC;
        t_symbol *sym;
        
        // are there specification for the ts/tempo?
        elem = measelemllll->l_head; 
        if (hatom_gettype(&elem->l_hatom) == H_LLLL) { // must be a llll
            t_llll *elemllll = hatom_getllll(&elem->l_hatom); // TS and TEMPO and possibly other attributes
            
            if ((elemllll->l_size >= 1) && (hatom_gettype(&elemllll->l_head->l_hatom) == H_LLLL)) { // there are ts/tempo specifications
                tsllll = hatom_getllll(&elemllll->l_head->l_hatom);
                if ((elemllll->l_size >= 2) && (hatom_gettype(&elemllll->l_head->l_next->l_hatom) == H_LLLL)) {
                    tempollll = hatom_getllll(&elemllll->l_head->l_next->l_hatom);
                    if ((elemllll->l_size >= 3) && (hatom_gettype(&elemllll->l_head->l_next->l_next->l_hatom) == H_SYM)) { // measure barline
                        measurebarline = hatom_getsym(&elemllll->l_head->l_next->l_next->l_hatom)->s_name[0];
                    }
                }
            }

            measure_set_ts_and_tempo_from_llll((t_notation_obj *) x, measure, tsllll, also_set_tempi ? tempollll : NULL, measurebarline, elemllll, when_no_ts_given_use_previous_measure_ts);
            x->r_ob.need_reassign_local_spacing = true;

        } else
            object_warn((t_object *) x, "Error: wrong input llll.");
        
//        if (elem)
//            llll_destroyelem(elem);

        if (measure)
            free_rhythmic_tree((t_notation_obj *)x, measure);
        
        // do we have an info if the measure is locked/muted/solo/treelocked or not?
        notation_item_set_flags_from_llllelem((t_notation_obj *) x, measelemllll->l_tail, (t_notation_item *)measure, true);

        // Old non-symbolic mute/lock flag setting mechanism
        if (measelemllll->l_tail && hatom_gettype(&measelemllll->l_tail->l_hatom) != H_LLLL)
            notation_item_set_flags_from_llllelem((t_notation_obj *) x, measelemllll->l_tail, (t_notation_item *)measure, true);
        
#ifdef BACH_OUTPUT_SYMBOLIC_FLAGS
        notation_item_find_and_set_flags((t_notation_obj *) x, (t_notation_item *)measure, measelemllll);
#endif
        
        t_llll_stack *elemstack = llll_stack_new();
        t_llll_stack *treestack = llll_stack_new();
        t_llll *tree = llll_get();
        t_llll *templl2;
        t_llll *elements = measelemllll;
        t_chord *newchord = NULL;
        char is_grace = false;

        notation_item_find_and_set_names((t_notation_obj *)x, (t_notation_item *)measure, measelemllll);

//        elem = measelemllll->l_head;
        elem = measelemllll->l_head ? measelemllll->l_head->l_next : NULL;
        
        while (1) {
            while (elem) {
                switch(elem->l_hatom.h_type) {
                    case H_LLLL:
                    {
                        char need_push_stack = true;
                        t_llll *this_llll = elem->l_hatom.h_w.w_llll;
                        if (this_llll && this_llll->l_head && is_hatom_number(&this_llll->l_head->l_hatom)){
                            // new chord in this level

                            long forced_chord_ID = notation_item_get_ID_from_llll(this_llll);
                        
                            elem = elem->l_next;
                            need_push_stack = false;
                            if (this_llll->l_size >= 1) { // there has to be at least (r_sym_duration)
                                t_rational r_sym_duration = RAT_1OVER4;
                                t_llllelem *elem = this_llll->l_head;
                                long num_notes = get_num_llll_no_first_attribute_sym_in_llll(this_llll); 
                                double *argv = (double *) bach_newptr(MAX(1, 2 * num_notes * sizeof(double)));
                                unsigned long *forced_note_IDs = (unsigned long *) bach_newptr(MAX(1, 2 * num_notes * sizeof(unsigned long)));
                                long i = 0;
                                
                                if (hatom_gettype(&elem->l_hatom) != H_LLLL)
                                    elem = get_next_llll_no_first_attribute_sym_elem(elem);
                                
                                for (i = 0; elem && i < num_notes; i++, elem = get_next_llll_no_first_attribute_sym_elem(elem)) {
                                    argv[2 * i] = CONST_DEFAULT_NEW_NOTE_DURATION; 
                                    argv[2 * i + 1] = CONST_DEFAULT_NEW_NOTE_CENTS;
                                    forced_note_IDs[i] = !elem ? 0 : notation_item_get_ID_from_llll(hatom_getllll(&elem->l_hatom));
                                }
                                
                                newchord = addchord_in_measure_from_values(x, measure, measure->lastchord, r_sym_duration, -1, num_notes, 2 * num_notes, argv, NULL, NULL, 0, NULL, forced_chord_ID, forced_note_IDs);
                                if (newchord) {
                                    set_scorechord_values_from_llll((t_notation_obj *) x, newchord, this_llll, true, false);
                                    if (newchord->r_sym_duration.r_num > 0 && !newchord->firstnote)
                                        newchord->r_sym_duration = rat_long_prod(rat_abs(newchord->r_sym_duration), -1);
                                    newchord->is_grace_chord = is_grace;
                                    if (rat_long_cmp(newchord->r_sym_duration, 0) == 0 && tree) {
                                        // 0 as a shortcut for grace chord
                                        t_llll *inner = llll_get();
                                        inner->l_thing.w_obj = build_rhythm_level_properties();
                                        set_level_type_flag_for_level(inner, k_RHYTHM_LEVEL_GRACE);
                                        newchord->r_sym_duration = RAT_1OVER8;
                                        newchord->rhythmic_tree_elem = llll_appendobj(inner, newchord, 0, WHITENULL_llll);
                                        llll_appendllll(tree, inner, 0, WHITENULL_llll);
                                    } else
                                        newchord->rhythmic_tree_elem = llll_appendobj(tree, newchord, 0, WHITENULL_llll);
                                }
                                bach_freeptr(argv);
                                bach_freeptr(forced_note_IDs);
                            }
                            
                        } else if (this_llll && this_llll->l_head && hatom_gettype(&this_llll->l_head->l_hatom) == H_SYM) {
                            sym = hatom_getsym(&this_llll->l_head->l_hatom);
                            if (sym == _llllobj_sym_leveltype) {
                                need_push_stack = false;
                                if (tree && this_llll->l_head->l_next) {
                                    if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_LONG)
                                        set_level_type_flag_for_level(tree, hatom_getlong(&this_llll->l_head->l_next->l_hatom));
                                    else if (hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_SYM)
                                        set_level_type_flag_for_level(tree, symbol2leveltype(hatom_getsym(&this_llll->l_head->l_next->l_hatom)));
                                }
                                elem = elem->l_next;
                            } else if (sym == _llllobj_sym_tupletinfo) { 
                                need_push_stack = false;
                                if (this_llll->l_head->l_next && this_llll->l_head->l_next->l_next && this_llll->l_head->l_next->l_next->l_next && this_llll->l_head->l_next->l_next->l_next->l_next) {
                                    t_rational tuplet_local_ratio = hatom_getrational(&this_llll->l_head->l_next->l_hatom);
                                    t_rational tuplet_graphical_unit = hatom_getrational(&this_llll->l_head->l_next->l_next->l_hatom);
                                    t_rational tuplet_pregressed_ratio = hatom_getrational(&this_llll->l_head->l_next->l_next->l_next->l_hatom);
                                    t_rational tuplet_multiplier = hatom_getrational(&this_llll->l_head->l_next->l_next->l_next->l_next->l_hatom);
                                    if (!tree->l_thing.w_obj)
                                        tree->l_thing.w_obj = build_rhythm_level_properties();
                                    fill_tupletinfo_fields2((t_notation_obj *) x, &((t_rhythm_level_properties *)tree->l_thing.w_obj)->tupletinfo, tuplet_local_ratio, tuplet_graphical_unit, tuplet_pregressed_ratio, tuplet_multiplier);
                                }
                                elem = elem->l_next;
                            }
                        }
                            
                        if (need_push_stack) {
                            llll_stack_push(treestack, tree);
                            llll_stack_push(elemstack, elem->l_next);
                            
                            elements = elem->l_hatom.h_w.w_llll;
                            elem = elements->l_head;
                            
                            templl2 = llll_get();
                            llll_appendllll(tree, templl2, 0, WHITENULL_llll);
                            tree = templl2;
                        }
                        break;
                    }
                        
                    case H_SYM:
                        if (hatom_getsym(&elem->l_hatom) == _llllobj_sym_t) {
                            if (newchord)
                                tie_chord(newchord);
                        } else if (hatom_getsym(&elem->l_hatom) == _llllobj_sym_g) {
                            if (tree)
                                add_level_type_flag_for_level(tree, k_RHYTHM_LEVEL_GRACE);
                            is_grace = true;
                        }
                        elem = elem->l_next;
                        break;
                        
                    case H_LONG:
                    case H_RAT:
                    case H_DOUBLE:
                    case H_OBJ:
                    default:
#ifdef CONFIGURATION_Development
                        llll_post_named(measelemllll, 0, 0, 2, NULL, NULL);
                        llll_print(measelemllll, NULL, 0, 2, NULL);
#endif
                        object_warn((t_object *) x, "Error: wrong input list.");
                        elem = elem->l_next;
                        break;
                }
            } 
            
            if (!elemstack->s_items)
                break; 
            
            is_grace = false;
            elem = (t_llllelem *) llll_stack_pop(elemstack);
            tree = (t_llll *) llll_stack_pop(treestack);
        }
        
        llll_stack_destroy(elemstack);
        llll_stack_destroy(treestack);

        measure->rhythmic_tree = tree;
        
        if (need_update_solos)
            *need_update_solos |= is_solo_with_progeny((t_notation_obj *)x, (t_notation_item *)measure);
        
        #ifdef BACH_RHYTHMIC_TREE_DEBUG
            char *buf = NULL;
            llll_to_text_buf(measure->rhythmic_tree, &buf, 0, 0, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL); //buf+50
            verbose_post_rhythmic_tree((t_notation_obj *) x, measure, gensym("score_set"), 1);
            bach_freeptr(buf);
        #endif

    } 
}


void create_whole_score_undo_tick_nolock(t_score *x) {
    if (x->r_ob.inhibited_undo)
        return;
    if (!(atom_gettype(&x->r_ob.max_undo_steps) == A_LONG && atom_getlong(&x->r_ob.max_undo_steps) == 0)) {
        //        notationobj_check_force((t_notation_obj *)x, true);
        t_llll *content = get_score_values_as_llll(x, k_CONSIDER_FOR_UNDO, k_HEADER_ALL, true, true, false, true);
        // we clone the content outside the memory pool so that it does not fill it
        t_llll *content_cloned = llll_clone_extended(content, WHITENULL_llll, 1, NULL);
        t_undo_redo_information *operation = undo_redo_information_create(0, k_WHOLE_NOTATION_OBJECT, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state, 0, 0, k_HEADER_NONE, content_cloned);
        llll_free(content);
        undo_redo_tick_create((t_notation_obj *) x, k_UNDO, 0, operation, true);
    }
}

void create_whole_score_undo_tick(t_score *x) {
    if (x->r_ob.inhibited_undo)
        return;
    if (!(atom_gettype(&x->r_ob.max_undo_steps) == A_LONG && atom_getlong(&x->r_ob.max_undo_steps) == 0)) {
//        notationobj_check_force((t_notation_obj *)x, true);
        t_llll *content = get_score_values_as_llll(x, k_CONSIDER_FOR_UNDO, k_HEADER_ALL, true, true, true, true);
        // we clone the content outside the memory pool so that it does not fill it
        t_llll *content_cloned = llll_clone_extended(content, WHITENULL_llll, 1, NULL);
        t_undo_redo_information *operation = undo_redo_information_create(0, k_WHOLE_NOTATION_OBJECT, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state, 0, 0, k_HEADER_NONE, content_cloned);
        llll_free(content);
        undo_redo_tick_create((t_notation_obj *) x, k_UNDO, 0, operation, true);
    }
}



void set_score_from_llll_from_xml(t_score *x, t_llll* inputlist)
{  
    if (inputlist) {
        create_whole_score_undo_tick(x); 
        set_score_from_llll(x, inputlist, true);
// TO DO
//        delete_redundant_graphic_information((t_notation_obj *)x);
    }
}

void set_score_from_llll_from_read(t_score *x, t_llll* inputlist)
{  
    if (inputlist) {
        create_whole_score_undo_tick(x); 
        set_score_from_llll(x, inputlist, true);
    }
}

void debug_scorevoices(t_score *x)
{
    t_scorevoice *v;
    dev_post("^^^^^^^");
    for (v = x->firstvoice; v && v->v_ob.number < x->r_ob.num_voices; v = v->next)
        dev_post("v: %p", v);
}
    
    
    
void check_score(t_score *x)
    {
#ifdef CONFIGURATION_Development
        for (t_scorevoice *voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next) {
            for (t_measure *meas = voice->firstmeasure; meas; meas = meas->next) {
                for (t_chord *ch = meas->firstchord; ch; ch = ch->next) {
                    if (!ch->parent)
                        bach_breakpoint(0);
                    for (t_note *nt = ch->firstnote; nt; nt = nt->next) {
                        if (!nt->parent)
                            bach_breakpoint(0);
                        if (!nt->firstbreakpoint || !nt->lastbreakpoint)
                            bach_breakpoint(0);
                    }
                }
            }
        }
#endif
    }

 
void set_score_from_llll(t_score *x, t_llll* inputlist, char also_lock_general_mutex)
{  
    // set the whole score, starting from a llll (it clones the llll) 
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
    notationobj_check((t_notation_obj *)x);
#endif

    t_llll *wholescore = llll_get();
    t_llll *markers = NULL, *loopregion = NULL;
    char markers_are_given = false, loopregion_is_given = false;

    if (!inputlist) { 
        llll_free(wholescore); 
        return; 
    }
    
    if (also_lock_general_mutex)
        lock_general_mutex((t_notation_obj *)x);    
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
    notationobj_check((t_notation_obj *)x);
#endif

    x->r_ob.nullify_incorrect_ties = false;
    llll_clone_upon(inputlist, wholescore);
    
    // if we have a "score" message at the beginning, we get rid of it (ok, it's a "signature" that everything is ok)
    if ((wholescore->l_size > 0) && (hatom_gettype(&wholescore->l_head->l_hatom) == H_SYM)) { 
        t_llllelem *firstelem = wholescore->l_head; // this is a symbol
        t_symbol *firstsym = hatom_getsym(&firstelem->l_hatom);
        if (firstsym == _llllobj_sym_score)
            llll_destroyelem(firstelem);
        else if (firstsym == _llllobj_sym_roll) {
            object_warn((t_object *) x, "Can't load a bach.roll content into a bach.score. Use bach.quantize instead.");
            llll_free(wholescore);

            if (also_lock_general_mutex)
                unlock_general_mutex((t_notation_obj *)x);    
            
            return;
        } else if (firstsym == _llllobj_sym_slot) {
            object_warn((t_object *) x, "Can't load a bach.slot content into a bach.score.");
            llll_free(wholescore);

            if (also_lock_general_mutex)
                unlock_general_mutex((t_notation_obj *)x);    
            
            return;
        }
    }
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
    notationobj_check((t_notation_obj *)x);
#endif

    if (wholescore->l_size > 0) { 
        t_llllelem *voiceelem;
        t_scorevoice *voice;
        
        // checking header
        while (true) { // cycle on the header elements
            t_llllelem *firstelem = wholescore->l_head; // this has to be a linked list
            
            if (!firstelem) 
                break; // there's no body content
            
            if (hatom_gettype(&firstelem->l_hatom) == H_LLLL) {
                t_llll *firstllll = hatom_getllll(&firstelem->l_hatom);
                if (firstllll->l_size > 0) {
                    t_llllelem *pivot = firstllll->l_head;
                    if (hatom_gettype(&pivot->l_hatom) == H_SYM) {
                        // we're still in the header;
                        t_symbol *pivotsym = hatom_getsym(&pivot->l_hatom);
                        if (pivotsym == _llllobj_sym_slotinfo) {
                            llll_destroyelem(pivot); // we kill the pivot, in order to give the correct llll to the set_slotinfo function
                            if (firstllll && firstllll->l_head)
                                set_slotinfo_from_llll((t_notation_obj *) x, firstllll);
                        } else if (pivotsym == _llllobj_sym_commands) {
                            llll_destroyelem(pivot); // we kill the pivot, in order to give the correct llll to the function
                            if (firstllll && firstllll->l_head)
                                set_commands_from_llll((t_notation_obj *) x, firstllll);
                        } else if (pivotsym == _llllobj_sym_midichannels) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                set_midichannels_from_llll((t_notation_obj *) x, firstllll);
                        } else if (pivotsym == _llllobj_sym_stafflines) {
                            llll_destroyelem(pivot);
                            set_stafflines_from_llll((t_notation_obj *)x, firstllll, true);
                        } else if (pivotsym == _llllobj_sym_clefs) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                set_clefs_from_llll(x, firstllll);
                        } else if (pivotsym == _llllobj_sym_voicespacing) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                notationobj_set_voicespacing_from_llll((t_notation_obj *)x, firstllll);
                        } else if (pivotsym == _llllobj_sym_hidevoices) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                notationobj_set_hidevoices_from_llll((t_notation_obj *)x, firstllll);
                        } else if (pivotsym == _llllobj_sym_keys) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                set_keys_from_llll(x, firstllll);
                        } else if (pivotsym == _llllobj_sym_voicenames) {
                            llll_destroyelem(pivot);
                            set_voicenames_from_llll((t_notation_obj *)x, firstllll, true);
                        } else if (pivotsym == _llllobj_sym_markers) {
                            markers_are_given = true;
                            llll_destroyelem(pivot); 
                            markers = llll_clone(firstllll);
                        } else if (pivotsym == _llllobj_sym_articulationinfo) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                set_articulationinfo_from_llll((t_notation_obj *)x, &x->r_ob.articulations_typo_preferences, firstllll, false);
                        } else if (pivotsym == _llllobj_sym_noteheadinfo) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                set_noteheadinfo_from_llll((t_notation_obj *)x, firstllll, false);
                        } else if (pivotsym == _llllobj_sym_numparts) {
                            llll_destroyelem(pivot);
                            if (firstllll && firstllll->l_head)
                                notationobj_set_numparts_from_llll((t_notation_obj *)x, firstllll);
                        } else if (pivotsym == _llllobj_sym_loop) {
                            loopregion_is_given = true;
                            llll_destroyelem(pivot);
                            loopregion = llll_clone(firstllll);
                        }
                        
#ifdef BACH_CHECK_NOTATION_ITEMS
                        notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
                        notationobj_check((t_notation_obj *)x);
#endif

                    } else
                        break; // break and go to the body of the object!
                } else
                    break; // break and go to the body of the object!
            }
            llll_destroyelem(firstelem); // we kill the first element and continue
        }
        
#ifdef BACH_CHECK_NOTATION_ITEMS
        notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
        notationobj_check((t_notation_obj *)x);
#endif

        long num_llll_in_llll_first_level = CLAMP(get_num_llll_in_llll_first_level(wholescore), 0, CONST_MAX_VOICES);
        
        // now we're ready to iterate on scorevoices
        voiceelem = wholescore->l_head;
        if (voiceelem && !x->must_append_measures) {
            // if there is some score stuff (and we're not appending), we clear the score, as a very first thing.
            clear_score_body(x, -1, num_llll_in_llll_first_level);
            if (x->r_ob.firstmarker && !markers_are_given) 
                clear_all_markers((t_notation_obj *) x);
            clear_preselection((t_notation_obj *) x);
            clear_selection((t_notation_obj *) x);
            close_slot_window((t_notation_obj *)x);
        } else if (markers_are_given)
            clear_all_markers((t_notation_obj *) x);

        
        // autosizing the number of voices – NEW CODE: bach 0.7.4
        if (x->r_ob.autosize) {
            long num_voices = num_llll_in_llll_first_level;

            // we change the number of voices if there was no "addmeasures" message and the number of voice inserted is different from the existing one,
            // or if there was "addmeasures" message, and the number of voices inserted is greater than the existing ones.
            if (num_voices > 0 && // if numvoices == 0 it means that there's only header in the incoming llll
                ((!x->must_append_measures && x->r_ob.num_voices != num_voices) ||
                 (x->must_append_measures && x->r_ob.num_voices < num_voices)))
                set_numvoices((t_notation_obj *)x, num_voices);
        }

        
        voice = x->firstvoice;
        while (voiceelem && voice){
            // is it a suitable llll for a voice?
            if (hatom_gettype(&voiceelem->l_hatom) == H_LLLL) {
                t_llll *voiceelemllll = hatom_getllll(&voiceelem->l_hatom);
                if (voiceelemllll->l_size > 0) {
                    if (voice && voiceelemllll->l_head) {
                        t_llllelem *measelem;

                        unsigned long forced_voice_ID = notation_item_get_ID_from_llll(voiceelemllll);
                        if (forced_voice_ID && forced_voice_ID != voice->v_ob.r_it.ID) {
                            shashtable_chuck_thing(x->r_ob.IDtable, voice->v_ob.r_it.ID);
                            shashtable_insert_with_key(x->r_ob.IDtable, voice, forced_voice_ID, 1);
                            voice->v_ob.r_it.ID = forced_voice_ID;
                        }
                        
                        measelem = voiceelemllll->l_head;

                        // Old non-symbolic mute/lock flag setting mechanism
                        if (voiceelemllll->l_tail && hatom_gettype(&voiceelemllll->l_tail->l_hatom) != H_LLLL)
                            notation_item_set_flags_from_llllelem((t_notation_obj *) x, voiceelemllll->l_tail, (t_notation_item *)voice, true);
                        
#ifdef BACH_OUTPUT_SYMBOLIC_FLAGS
                        notation_item_find_and_set_flags((t_notation_obj *) x, (t_notation_item *)voice, voiceelemllll);
#endif
                        
                        measelem = voiceelemllll->l_head;
                        // we iterate on measures
                        while (measelem) {
                            // is it a suitable llll for a measure?
                            if (hatom_gettype(&measelem->l_hatom) == H_LLLL) { // MUST be a LLLL
                                t_llll *measelemllll = hatom_getllll(&measelem->l_hatom);

                                long forced_meas_ID = notation_item_get_ID_from_llll(measelemllll);

// DEBUG:                                
//                                llll_writetxt((t_object *)x, NULL, llll_clone(measelemllll));
                    
                                if (measelemllll->l_size > 0) {
                                    t_measure *measure = build_measure((t_notation_obj *) x, NULL);
                                    insert_measure((t_notation_obj *)x, voice, measure, voice->lastmeasure, forced_meas_ID);
                                    
                                    set_measure_from_llll(x, measure, measelemllll, true, true, NULL);
                                 } 
                            }
                            measelem = measelem->l_next;
                        }
                    }
                }
                if (!voice) 
                    break;
                voice = voice->next;
            }
            voiceelem = voiceelem->l_next;
        }
    }
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
    notationobj_check((t_notation_obj *)x);
#endif

    notationobj_make_temporary_slurs_permanent((t_notation_obj *)x);

    if (markers) // we need to set them later, since they might be attached to measures
        set_markers_from_llll((t_notation_obj *)x, markers, false, false, false);
    
    recompute_all(x);

    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
    notationobj_check((t_notation_obj *)x);
#endif
    
//    notationobj_check_force((t_notation_obj *)x, false);
    
    perform_analysis_and_change(x, NULL, NULL, NULL, x->r_ob.take_rhythmic_tree_for_granted ? k_BEAMING_CALCULATION_DONT_CHANGE_ANYTHING : k_BEAMING_CALCULATION_DO);

    if (loopregion && loopregion->l_head)
        set_loop_region_from_llll(x, loopregion, false);
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

    if (markers){
        sync_all_markers_absolute_ms_onset(x);
        check_markers_order((t_notation_obj *) x);
        sync_all_markers_absolute_ms_onset(x);
        llll_free(markers);
    }

    check_mute_solo_flags_for_rests((t_notation_obj *) x);
    x->r_ob.are_there_solos = are_there_solos((t_notation_obj *) x);
    x->r_ob.nullify_incorrect_ties = true;
    
    if (also_lock_general_mutex)
        unlock_general_mutex((t_notation_obj *)x);    
    
    check_correct_scheduling((t_notation_obj *)x, also_lock_general_mutex);
    update_solos((t_notation_obj *)x);
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

     llll_free(wholescore);
    
    update_hscrollbar((t_notation_obj *)x, 0);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);

#ifdef CONFIGURATION_Development
    verbose_print(x);
#endif
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
    notationobj_check((t_notation_obj *)x);
#endif
}



/*
void check_if_a_chord_is_wrong(t_score *x){
    t_scorevoice *voice;
    t_measure *meas;
    t_chord *ch;
    for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next)
        for (meas = voice->firstmeasure; meas; meas = meas->next)
            for (ch = meas->firstchord; ch; ch = ch->next)
                if (ch->prev == ch || ch->next == ch){
                    char foo = 8;
                    foo++;
                }
}
 */



void snap_pitch_to_grid_voice(t_score *x, t_scorevoice *voice) 
{
    t_measure *curr_meas = voice->firstmeasure;
    while (curr_meas) {
        t_chord *curr_ch = curr_meas->firstchord;
        while(curr_ch){ // cycle on the chords
            t_note *curr_nt = curr_ch->firstnote; 
            while(curr_nt){ // cycle on the chords
                snap_pitch_to_grid_for_note((t_notation_obj *) x, curr_nt);
                curr_nt = curr_nt->next;
            }
            chord_set_recompute_parameters_flag((t_notation_obj *)x, curr_ch);
            curr_ch = curr_ch->next;
        }
        curr_meas = curr_meas->next;
    }
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
}

void score_snap_pitch_to_grid(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    // retranscribe the midicents, with respect to the shown approximation on the score, and NOT to the fine tuning. 
    lock_general_mutex((t_notation_obj *)x);    
    if (argc >= 0) { // retranscribe only a voice
        long numvoice = atom_getlong(argv) - 1; // 0-based inside, 1-based for the user
        t_scorevoice *voice = scorevoice_get_nth(x, numvoice);
        snap_pitch_to_grid_voice(x, voice);
    } else {
        t_scorevoice *voice = x->firstvoice;
        while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
            snap_pitch_to_grid_voice(x, voice);
            voice = voice->next;
        }
    }
    unlock_general_mutex((t_notation_obj *)x);    
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
}



// voicenum >= 0: specific voice (0-based)
// voicenum = -1: all voices, up to current num_voices
// voicenum = -2: all voices, up to CONST_MAX_VOICES
// this function must be put within a mutex
void clear_score_body(t_score *x, long voicenum, long min_num_voices_to_be_cleared)
{
    // clears all the score (or just a specific voice)
    
    clear_preselection((t_notation_obj *) x);
    clear_selection((t_notation_obj *) x);
    
    clear_all_groups((t_notation_obj *) x);

    if (voicenum >= 0) { // there's a voice argument
        t_scorevoice *voice = scorevoice_get_nth(x, voicenum);
        t_measure *measure = voice->firstmeasure;
        t_measure *temp = measure; 
        while (measure) {
            temp = measure->next;
            delete_measure((t_notation_obj *)x, measure, NULL, NULL);
            measure = temp;
        }
    } else { 
        t_scorevoice *voice = x->firstvoice;
        long max_num_voices = (voicenum == -2 ? CONST_MAX_VOICES : x->r_ob.num_voices);
        if (max_num_voices < min_num_voices_to_be_cleared)
            max_num_voices = min_num_voices_to_be_cleared;
        while (voice && (voice->v_ob.number < max_num_voices)) {
            t_measure *measure = voice->firstmeasure;
            while (measure) {
                t_measure *temp = measure->next;
                delete_measure((t_notation_obj *)x, measure, NULL, NULL);
                measure = temp;
            }
            voice = voice->next;
        }
    }
    
    check_correct_scheduling((t_notation_obj *)x, false);
    
    delete_all_tuttipoints(x, true);
    
    // we recalculate everything
    update_solos((t_notation_obj *)x);
    recompute_all(x);
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
    
    perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DO);
    close_slot_window((t_notation_obj *)x); // if we were in slot view...
    
#ifdef BACH_MAX
    // erasing possible lllls in the stores
    llllobj_store_llll((t_object *) x, LLLL_OBJ_UI, llll_get(), 1);
    llllobj_store_llll((t_object *) x, LLLL_OBJ_UI, llll_get(), 2);
    llllobj_store_llll((t_object *) x, LLLL_OBJ_UI, llll_get(), 3);
    llllobj_store_llll((t_object *) x, LLLL_OBJ_UI, llll_get(), 4);
    llllobj_store_llll((t_object *) x, LLLL_OBJ_UI, llll_get(), 5);
    llllobj_store_llll((t_object *) x, LLLL_OBJ_UI, llll_get(), 6);
#endif
    update_hscrollbar((t_notation_obj *)x, 0);
    
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
}

// this function must be put inside a mutex
void score_clear_all(t_score *x)
{
    clear_score_body(x, -2);
    clear_all_markers((t_notation_obj *)x);
}





void score_cleararticulations(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    create_whole_score_undo_tick(x);
    if (argc > 0) { // there's a voice argument
        long voicenum = atom_getlong(argv) - 1; // 0-based inside, 1-based for the user
        t_scorevoice *voice = scorevoice_get_nth(x, voicenum);
        t_measure *meas; t_chord *chord; t_note *note;
        for (meas = voice->firstmeasure; meas; meas = meas->next)
            for (chord = meas->firstchord; chord; chord = chord->next) {
                delete_all_articulations_from_notation_item((t_notation_obj *)x, (t_notation_item *)chord);
                for (note = chord->firstnote; note; note = note->next)
                    delete_all_articulations_from_notation_item((t_notation_obj *)x, (t_notation_item *)note);
        }
    } else {
        t_scorevoice *voice; t_measure *meas; t_chord *chord; t_note *note;
        for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next)
            for (meas = voice->firstmeasure; meas; meas = meas->next)
                for (chord = meas->firstchord; chord; chord = chord->next) {
                    delete_all_articulations_from_notation_item((t_notation_obj *)x, (t_notation_item *)chord);
                    for (note = chord->firstnote; note; note = note->next)
                        delete_all_articulations_from_notation_item((t_notation_obj *)x, (t_notation_item *)note);
                }
    }
    handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CLEAR_ARTICULATIONS);
}

void score_clearnotes(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    create_whole_score_undo_tick(x);
    // clears all the notes
    lock_general_mutex((t_notation_obj *)x);
    if (argc > 0) { // there's a voice argument
        long voicenum = atom_getlong(argv) - 1; // 0-based inside, 1-based for the user
        t_scorevoice *voice = scorevoice_get_nth(x, voicenum);
        t_measure *measure = voice->firstmeasure;
        while (measure) {
            clear_measure((t_notation_obj *)x, measure, false, true, false);
            measure = measure->next;
        }
    } else {
        t_scorevoice *voice = x->firstvoice;
        while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
            t_measure *measure = voice->firstmeasure;
            while (measure) {
                clear_measure((t_notation_obj *)x, measure, false, true, false);
                measure = measure->next;
            }
            voice = voice->next;
        }
    }
    
    recompute_all(x);
    perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DO);
    close_slot_window((t_notation_obj *)x); // if we were in slot view...
    unlock_general_mutex((t_notation_obj *)x);
    
    redraw_hscrollbar((t_notation_obj *)x, 0);
    handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CLEAR_NOTES);
}

void score_cleartempi(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    create_whole_score_undo_tick(x);
    lock_general_mutex((t_notation_obj *)x);
    if (argc > 0) { // there's a voice argument
        long voicenum = atom_getlong(argv) - 1; // 0-based inside, 1-based for the user
        t_scorevoice *voice = scorevoice_get_nth(x, voicenum);
        delete_voice_tempi((t_notation_obj *)x, voice);
    } else {
        t_scorevoice *voice = x->firstvoice;
        while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
            delete_voice_tempi((t_notation_obj *)x, voice);
            voice = voice->next;
        }
    }
    
    recompute_all_except_for_beamings_and_autocompletion(x);
    perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DONT_CHANGE_ANYTHING);

//  DG, 2020.06.11 why was this???
//    perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DO);
//    close_slot_window((t_notation_obj *)x); // if we were in slot view...

    unlock_general_mutex((t_notation_obj *)x);
    
    redraw_hscrollbar((t_notation_obj *)x, 0);
    handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CLEAR_TEMPI);
}

char pop_tempo_over_chord(t_score *x, t_chord *chord, char in_all_voices)
{
    t_scorevoice *voice = chord->parent->voiceparent;
    t_measure *meas = chord->parent;
    t_rational figure_tempo_value, tempo_value, tempo_figure; char interpolation;
    t_timepoint tp = build_timepoint_with_voice(chord->parent->measure_number, chord->r_sym_onset, voice->v_ob.number);
    t_tempo *tempo;
    get_tempo_at_timepoint((t_notation_obj *)x, voice, tp, &figure_tempo_value, &tempo_figure, &tempo_value, &interpolation);
    
    if (in_all_voices) {
        t_scorevoice *tempvc;
        for (tempvc = x->firstvoice; tempvc && tempvc->v_ob.number < x->r_ob.num_voices; tempvc = tempvc->next){
            t_measure *this_meas = measure_get_nth(tempvc, meas->measure_number);
            if (this_meas) {
                tempo = build_tempo(tp.pt_in_measure, figure_tempo_value, tempo_figure, interpolation);
                insert_tempo((t_notation_obj *)x, this_meas, tempo);
            }
        }
    } else {
        tempo = build_tempo(tp.pt_in_measure, figure_tempo_value, tempo_figure, interpolation);
        insert_tempo((t_notation_obj *)x, meas, tempo);
    }
    
    recompute_all(x);
    return 1;
}


void merge_chords_and_sum_durations(t_score *x, t_chord *chord1, t_chord *chord2)
{
    t_rational new_duration;
    
    if ((!chord1->is_grace_chord && !chord2->is_grace_chord) || (chord1->is_grace_chord && chord2->is_grace_chord)) // both are grace or both aren't grace
        new_duration = rat_rat_sum(rat_abs(chord1->r_sym_duration), rat_abs(chord2->r_sym_duration));
    else if (chord1->is_grace_chord)
        new_duration = rat_abs(chord2->r_sym_duration);
    else
        new_duration = rat_abs(chord1->r_sym_duration);
    
    if ((chord1->r_sym_duration.r_num < 0) && (chord2->r_sym_duration.r_num < 0)) 
        new_duration.r_num = -new_duration.r_num; 
    
    // handling tree elements
    if (chord1->rhythmic_tree_elem->l_parent != chord2->rhythmic_tree_elem->l_parent){
        long depth1, depth2, depthrelative;
        t_llll *common_relative = llllelem_find_first_common_relative(chord1->rhythmic_tree_elem, chord2->rhythmic_tree_elem, &depth1, &depth2, &depthrelative);
        if (common_relative){
            long i;
            t_llllelem *elem;
            char there_are_tuplets = false;
            
            elem = chord1->rhythmic_tree_elem;
            for (i = 0; elem && i < depth1 - depthrelative; i++){
                t_llll *parent = elem->l_parent;
                
#ifdef BACH_RHYTHMIC_TREE_DEBUG
                char *buf = NULL;
                llll_to_text_buf(common_relative, &buf, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, get_strings_for_rhythmic_tree_elements_verbosity0);
                llll_check(chord1->parent->rhythmic_tree);
                bach_freeptr(buf);
#endif
                
                if (!there_are_tuplets && hatom_gettype(&elem->l_hatom) == H_LLLL && is_level_tuplet(hatom_getllll(&elem->l_hatom)))
                    there_are_tuplets = true;
                
                llll_splatter(elem, LLLL_FREETHING_MEM);
                
#ifdef BACH_RHYTHMIC_TREE_DEBUG
                char *buf2 = NULL;
                llll_check(chord1->parent->rhythmic_tree);
                llll_to_text_buf(common_relative, &buf2, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, get_strings_for_rhythmic_tree_elements_verbosity0);
                bach_freeptr(buf2);
#endif
                
                elem = parent->l_owner;
            }
            elem = chord2->rhythmic_tree_elem;
            for (i = 0; elem && i < depth2 - depthrelative; i++) {
                t_llll *parent = elem->l_parent;
                
#ifdef BACH_RHYTHMIC_TREE_DEBUG
                char *buf = NULL;
                llll_to_text_buf(common_relative, &buf, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, get_strings_for_rhythmic_tree_elements_verbosity0);
                llll_check(chord1->parent->rhythmic_tree);
                bach_freeptr(buf);
#endif
                
                if (!there_are_tuplets && hatom_gettype(&elem->l_hatom) == H_LLLL && is_level_tuplet(hatom_getllll(&elem->l_hatom)))
                    there_are_tuplets = true;
                
                llll_splatter(elem, LLLL_FREETHING_MEM);
                
#ifdef BACH_RHYTHMIC_TREE_DEBUG
                char *buf2 = NULL;
                llll_check(chord1->parent->rhythmic_tree);
                llll_to_text_buf(common_relative, &buf2, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, get_strings_for_rhythmic_tree_elements_verbosity0);
                bach_freeptr(buf2);
#endif
                
                elem = parent->l_owner;
            }
            
            if (depthrelative == 0) // we have come to the root!
                common_relative = llll_wrap_element_range(common_relative->l_head, common_relative->l_tail);
            
            add_level_type_flag_for_level(common_relative, there_are_tuplets ? k_RHYTHM_LEVEL_ORIGINAL | k_RHYTHM_LEVEL_TUPLET : k_RHYTHM_LEVEL_ORIGINAL);
            
            // this one below gave issues
            //                add_level_type_flag_for_level(common_relative, there_are_tuplets ? k_RHYTHM_LEVEL_ORIGINAL | k_RHYTHM_LEVEL_FORCE_TUPLET : k_RHYTHM_LEVEL_ORIGINAL);
        }
    } else if (chord1->rhythmic_tree_elem->l_parent && !chord1->rhythmic_tree_elem->l_prev && !chord2->rhythmic_tree_elem->l_next) {
        add_level_type_flag_for_level(chord1->rhythmic_tree_elem->l_parent, k_RHYTHM_LEVEL_ORIGINAL);
    }
    // else: nothing to do
    // we don't free chord2->rhythmic_tree_elem, since it'll be done when we call chord_delete_from_measure on it, inside merge_chords

    untie_chord(chord1); 
    merge_chords(x, chord1, chord2, 0, true, true);
    chord_merge_mc(x, chord1, (100. / x->r_ob.tone_division), 0);
    chord1->r_sym_duration = new_duration;
    recompute_all_for_measure((t_notation_obj *)x, chord1->parent, true);
    
    verbose_post_rhythmic_tree((t_notation_obj *)x, chord1->parent, gensym("merging"), 1);
}

t_note* merge_chords(t_score *x, t_chord *chord1, t_chord *chord2, char add_cloned_items_to_preselection, char transfer_mousedown, char assign_IDs)
{
    // merge the notes of the second chord in the first one. VERY IMPORTANT: the algorithm _frees the second chord_ after merging.
    // we just append the list of notes, and then check the order, in order to re-arrange correctly the notes (sorted by midicents, from min to max)
    // if flags == 1 we add new notes to selection 
    // returns the pointer to the newly j_mousedown note, if any
    
    t_note *new_mousedown_note = NULL;
    if (chord2 && chord1) {
        if (chord2->firstnote) {
            long mousedown_id_in_chord1 = -1, i;
            t_note *temp_nt = chord2->firstnote;
            
            if (transfer_mousedown) {
                t_note *tmp;
                for (tmp = chord1->firstnote, i = 0; tmp; tmp = tmp->next, i++){
                    if (x->r_ob.j_mousedown_ptr == tmp || (x->r_ob.j_mousedown_ptr == chord1 && chord1->num_notes == 1)){
                        mousedown_id_in_chord1 = i;
                        break;
                    }
                }
            }
            i = 0;
            while (temp_nt) {
                t_note *cloned_note = clone_note((t_notation_obj *) x, temp_nt, k_CLONE_FOR_ORIGINAL);
                
                // j_mousedown to be transfered?
                if (transfer_mousedown && !new_mousedown_note && mousedown_id_in_chord1 == i)
                    new_mousedown_note = cloned_note;
                
                cloned_note->parent = chord1; // change parent!!!
                cloned_note->tie_to = (temp_nt->tie_to) ? (t_note *) WHITENULL : NULL; // is note tied?
                note_insert((t_notation_obj *) x, chord1, cloned_note, 0);
                if (add_cloned_items_to_preselection == 1)  // was: notation_item_add_to_preselection
                    notation_item_add_to_preselection((t_notation_obj *) x, (t_notation_item *)cloned_note); // we could drop this, but it's useful when we drag'n'drop, so that just the NEW notes remain selected
                temp_nt = temp_nt->next;
                i++;
            }
        }
        
        if (chord2->parent == chord1->parent)  // it was inside the measure
            chord_delete_from_measure((t_notation_obj *) x, chord2, false);
        else {
            chord_check_dependencies_before_deleting_it((t_notation_obj *)x, chord2, false, NULL);
            free_chord((t_notation_obj *)x, chord2);
        }
    } 
    return new_mousedown_note;
}

long get_global_num_notes_voice(t_scorevoice *voice)
{
    t_chord *temp_ch; t_measure *temp_meas = voice->firstmeasure;
    long numnotes = 0;
    while (temp_meas){
        temp_ch = temp_meas->firstchord;
        while (temp_ch) {
            numnotes += temp_ch->num_notes;
            temp_ch = temp_ch->next;
        }
        temp_meas = temp_meas->next;
    }
    return numnotes;
}

long get_global_num_notes(t_score *x)
{
    t_scorevoice *voice = x->firstvoice;
    long numnotes = 0;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        numnotes += get_global_num_notes_voice(voice);
        voice = voice->next;
    }
    return numnotes;
}



// this function must be put within a mutex
void turn_chord_into_rest_or_into_note(t_score *x, t_chord *chord, double mc) {
    if (chord->r_sym_duration.r_num > 0) {
        turn_chord_into_rest(x, chord);
        perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DONT_CHANGE_TIES + k_BEAMING_CALCULATION_DONT_AUTOCOMPLETE);
    } else {
        double argv[2]; 
        t_note *nt;
        argv[0] = CONST_DEFAULT_NEW_NOTE_DURATION; 
        argv[1] = mc;
        nt = build_note_from_ac_av((t_notation_obj *) x, 2, argv);
        chord->r_sym_duration = rat_abs(chord->r_sym_duration);
        note_insert((t_notation_obj *) x, chord, nt, 0);
        note_compute_approximation((t_notation_obj *) x, nt);
        calculate_chord_parameters((t_notation_obj *) x, chord, get_voice_clef((t_notation_obj *)x, (t_voice *)chord->parent->voiceparent), true);
        
        set_tuplet_levels_as_keep_levels(chord->parent->rhythmic_tree);
        set_level_type_flag_for_level(chord->parent->rhythmic_tree, k_RHYTHM_LEVEL_IGNORE);

        x->r_ob.notation_cursor.measure->need_recompute_beamings = true;
        set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
        perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DONT_CHANGE_TIES + k_BEAMING_CALCULATION_DONT_AUTOCOMPLETE);
        notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
    }
}



void turn_chord_into_rest(t_score *x, t_chord *chord)
{
    
    // turns a chord into  a rest
    if (chord) {
        t_note *note = chord->firstnote; 
        t_note *note2;
        while (note) {
            note2 = note->next;
            note_delete((t_notation_obj *)x, note, false);
            note = note2;
        }
        chord->r_sym_duration = rat_long_prod(rat_abs(chord->r_sym_duration), -1);
        recompute_all_for_measure((t_notation_obj *)x, chord->parent, true);
    }
    
}



long get_num_chords(t_score *x)
{
    long numch = 0;
    t_scorevoice *voice = x->firstvoice; t_measure *measure;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        measure = voice->firstmeasure;
        while (measure) {
            numch += measure->num_chords;
            measure = measure->next;
        }
        voice = voice->next;
    }
    return numch;
}


t_chord* addchord_in_measure_from_notes(t_score *x, t_measure *measure, t_chord *after_this_chord, t_rational r_sym_duration, long ID, long num_notes, t_note *firstnote, t_note *lastnote, unsigned long force_ID) 
{
    // add a chord, starting from a linked list of notes
    t_chord *this_ch;
    t_note *curr_nt;
    // first of all: if it's a rest, it has to have NO notes!
    if (r_sym_duration.r_num < 0) {
        t_note *tmp = firstnote; t_note *tmp2; 
        while (tmp) {
            tmp2 = tmp->next;
            free_note((t_notation_obj *)x, tmp);
            tmp = tmp2;
        }
        firstnote = NULL;
        lastnote = NULL;
    }
    
    // create chord, and insert it in the linked list
    this_ch = (t_chord *)bach_newptrclear(sizeof(t_chord));
    notation_item_init(&this_ch->r_it, k_CHORD);
    this_ch->lyrics = build_lyrics(this_ch);
    this_ch->dynamics_slot = NULL;

    this_ch->onset = 0; // will be set later by calculate_all_chords_remaining_onsets
    this_ch->just_added_from_separate_parameters = false;
    this_ch->float_steps = 0;
//    this_ch->min_float_steps = LONG_MIN;
//    this_ch->max_float_steps = LONG_MAX;
    this_ch->is_score_chord = true;
    this_ch->system_index = 0;
    this_ch->direction = 0;
    this_ch->imposed_direction = 0;
    this_ch->need_recompute_parameters = true;
    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
    this_ch->r_sym_duration = r_sym_duration;
    this_ch->voiceparent = NULL;
    this_ch->parent = measure;
    this_ch->num_notes = num_notes;
    this_ch->firstnote = firstnote;
    this_ch->lastnote = lastnote;
    this_ch->locked = false;
    this_ch->solo = false;
    this_ch->muted = false;
    this_ch->played = false;
    this_ch->rhythmic_tree_elem = NULL;
    this_ch->overall_tuplet_ratio = long2rat(1);
    this_ch->dont_split_for_ts_boxes = false;
    
    this_ch->is_grace_chord = 0;

    this_ch->num_articulations = 0;
    this_ch->articulation = NULL;
    
#ifdef BACH_SUPPORT_SLURS
    this_ch->num_slurs_to = 0;
    this_ch->num_slurs_from = 0;
#endif

    chord_insert_in_measure((t_notation_obj *) x, measure, this_ch, after_this_chord, force_ID);
    
    // compute the approximation
    curr_nt = this_ch->firstnote;  
    while(curr_nt) {
        curr_nt->parent = this_ch;
        curr_nt = curr_nt->next;
    }
    
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
    
    return this_ch;
}



t_chord* addchord_in_measure_from_values(t_score *x, t_measure *measure, t_chord *after_this_chord, t_rational r_sym_duration, long unused, long num_notes, long argc, double *argv, long* num_bpt, double *bpt, long slot_list_length, t_atom *slots, unsigned long force_ID, unsigned long *force_note_IDs) 
{
    // add a chord. Possible arguments are: [...] = looped numnotes-times.
    // - voicenumber numnotes onset ID [duration midicents]
    // - voicenumber numnotes onset ID [duration midicents velocity]
    // - voicenumber numnotes onset ID [duration midicents velocity accidentals]
    // - voicenumber numnotes onset ID [duration midicents velocity accidentals flag]
    // - voicenumber numnotes onset ID [duration midicents velocity accidentals flag ID]
    // plus: num_bpt (sized num_notes) contains the number of breakpoints (one entry for each note) - leave NULL for no breakpoint info
    //         all the breakpoints are then listed (rel_x, y, slope)
    // NB:: leave ID = -1 for autoassign!!
    
    // argv[0] argv[1] argv[2] argv[3] argv[4] argv[5] argv[6] argv[7] argv[8] argv[9] argv[10] argv[11]  num_bpt[0] num_bpt[1] bpt[0] bpt[1] bpt[2] bpt[3] bpt[4] bpt[5]
    if (num_notes >= 0) {
        if ((argc !=2*num_notes) && (argc!=3*num_notes) && (argc!=4*num_notes) && (argc!=5*num_notes) && (argc!=6*num_notes)) {
            object_warn((t_object *)x, "Can't build a chord with these parameters.");    
            return NULL;
        } else {
            // assign ID if needed
            long s; // lecture head
            t_chord *this_ch;
            long i, j, k;
            t_note *head_nt = NULL;
            t_note *temp; 
            long pos = 0; 
            
            // create chord, and insert it in the linked list
            this_ch = (t_chord *)bach_newptrclear(sizeof(t_chord));
            notation_item_init(&this_ch->r_it, k_CHORD);
            this_ch->lyrics = build_lyrics(this_ch);
            this_ch->dynamics_slot = NULL;

            this_ch->just_added_from_separate_parameters = false;
            this_ch->voiceparent = NULL;
            this_ch->float_steps = 0;
//            this_ch->min_float_steps = LONG_MIN;
//            this_ch->max_float_steps = LONG_MAX;
            this_ch->is_score_chord = true;
            this_ch->system_index = 0;
            this_ch->direction = 0;
            this_ch->imposed_direction = 0;
            this_ch->parent = measure;
            this_ch->need_recompute_parameters = false;
            set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
            this_ch->r_sym_duration = r_sym_duration;
            this_ch->onset = 0; // will be set later by calculate_all_chords_remaining_onsets
            this_ch->locked = false;
            this_ch->muted = false;
            this_ch->played = false;
            this_ch->solo = false;
            this_ch->num_notes = num_notes;
            this_ch->rhythmic_tree_elem = NULL;
            this_ch->overall_tuplet_ratio = long2rat(1);
            this_ch->dont_split_for_ts_boxes = false;

            this_ch->is_grace_chord = 0;
            
            this_ch->num_articulations = 0;
            this_ch->articulation = NULL;
            
#ifdef BACH_SUPPORT_SLURS
            this_ch->num_slurs_to = 0;
            this_ch->num_slurs_from = 0;
#endif

            chord_insert_in_measure((t_notation_obj *) x, measure, this_ch, after_this_chord, force_ID);
            
            // create the chain of notes
            this_ch->lastnote = NULL;
            for(i=num_notes-1; i>=0; i--) { //reversed cycle on the notes (each note is put at the beginning of the list)
                t_note *this_note = NULL;
                // building the note
                if (argc == 2*num_notes) // case (duration midicents)
                    this_note = build_note_from_ac_av((t_notation_obj *) x, 2, argv+2*i);
                else if (argc == 3*num_notes) // case (duration midicents velocity)
                    this_note = build_note_from_ac_av((t_notation_obj *) x, 3, argv+3*i);
                else if (argc == 4*num_notes) // case (duration midicents velocity accidental)
                    this_note = build_note_from_ac_av((t_notation_obj *) x, 4, argv+4*i);
                else if (argc == 5*num_notes) // case (duration midicents velocity accidental def_acc)
                    this_note = build_note_from_ac_av((t_notation_obj *) x, 5, argv+5*i);
                else if (argc == 6*num_notes) // case (duration midicents velocity accidental def_acc ID)
                    this_note = build_note_from_ac_av((t_notation_obj *) x, 6, argv+6*i);
                
                this_note->parent = this_ch;
                this_note->next = head_nt;
                
#ifdef BACH_NOTES_HAVE_ID
                if (force_note_IDs && force_note_IDs[i] > 0) { 
                    shashtable_insert_with_key(x->r_ob.IDtable, this_note, force_note_IDs[i], 1);
                    this_note->r_it.ID = force_note_IDs[i];
                } else
                    this_note->r_it.ID = shashtable_insert(x->r_ob.IDtable, this_note);
#endif
                
                if (i==num_notes-1) 
                    this_ch->lastnote = this_note;
                if (i<num_notes-1) 
                    head_nt->prev = this_note;
                head_nt = this_note;
            }
            this_ch->firstnote = head_nt;
            
            // handle breakpoints
            temp = this_ch->firstnote; 
            i = 0;
            while (temp) { // num_bpt[0] bpt[0] bpt[1] bpt[2] bpt[3] bpt[4] bpt[5]
                if ((num_bpt) && (num_bpt[i]>0)) {
                    temp->num_breakpoints = 2;
                    pos += 3; // skip first breakpoint (trivial)
                    for (k = 1; k < num_bpt[i] - 1; k++) { // first breakpoint is standard... we don't copy it! last breakpoint is dealt separately with.
                        add_breakpoint((t_notation_obj *) x, temp, bpt[pos], bpt[pos+1], bpt[pos+2], 0, CONST_DEFAULT_NEW_NOTE_VELOCITY, 1);
                        pos += 3;
                    }
                    // change last bpt values
                    temp->lastbreakpoint->delta_mc = bpt[pos+1];
                    temp->lastbreakpoint->slope = bpt[pos+2];
                    pos += 3;
                }
                temp = temp->next; i++;
            }
            
            // handle slots
            // ALL THIS PART IS DEPRECATED: BETTER USE note_set_slots_from_llll()
            temp = this_ch->firstnote;
            s = 0; // lecture head... 
            while (temp) { 
                // slots - first: tabula rasa
                for (i = 0; i< CONST_MAX_SLOTS; i++) {
                    temp->slot[i].firstitem = NULL;
#ifdef BACH_SLOTS_HAVE_LASTITEM
                    temp->slot[i].lastitem = NULL;
#endif
#ifdef BACH_SLOTS_HAVE_OWNER
                    temp->slot[i].owner = temp;
#endif
#ifdef BACH_SLOTS_HAVE_ACTIVEITEM
                    temp->slot[i].activeitem = NULL;
#endif
                    temp->slot[i].length = 0;
                }
                
                if (slot_list_length > 0) {
                    // then: parsing of *slots
                    while (true) {
                        if ((atom_gettype(slots + s) == A_SYM) && (strcmp(atom_getsym(slots + s)->s_name, "next") == 0)) { // go to next note!
                            s += 1;
                            break;            
                        } else if ((atom_gettype(slots + s) == A_SYM) && (strcmp(atom_getsym(slots + s)->s_name, "slot") == 0)) { // slot content
                            j = atom_getlong(slots + s + 1) - 1; // slot number (we make it is 0-based)
                            if (atom_gettype(slots + s + 2) == A_SYM) { // it MUST be a A_SYM
                                if (strcmp(atom_getsym(slots + s + 2)->s_name, "function") == 0) { // slot function
                                    long num_pts = atom_getlong(slots + s + 3);
                                    temp->slot[j].length = 0; // we'll put it at the end (just to avoid that slotitem_append get crazy)
                                    s += 4;
                                    for (i = 0; i < num_pts; i++) { // add each point 
                                        double x_val, y_val, slope;
                                        t_pts *point;
                                        t_slotitem *thisitem = build_slotitem((t_notation_obj *)x, &(temp->slot[j]));
                                        x_val = atom_getfloat(slots + s);
                                        y_val = atom_getfloat(slots + s + 1);
                                        slope = atom_getfloat(slots + s + 2);
                                        s += 3;
                                        point = (t_pts *)bach_newptr(sizeof(t_pts));
                                        point->x = x_val; point->y = y_val; point->slope = slope;
                                        thisitem->item = point;
                                        slotitem_append(thisitem); // points are ordered! we just have to append them
                                    }
                                    temp->slot[j].length = num_pts; // number of points
                                } else if (strcmp(atom_getsym(slots + s + 2)->s_name, "long") == 0) { // slot long
                                    long *val = (long *)bach_newptr(sizeof(long));
                                    t_slotitem *thisitem = build_slotitem((t_notation_obj *)x, &(temp->slot[j]));
                                    temp->slot[j].length = 0;
                                    *val = atom_getlong(slots + s + 3);
                                    s += 4;
                                    thisitem->item = val;
                                    slotitem_append(thisitem);
                                } else if (strcmp(atom_getsym(slots + s + 2)->s_name, "float") == 0) { // slot float
                                    double *val = (double *)bach_newptr(sizeof(double));
                                    t_slotitem *thisitem = build_slotitem((t_notation_obj *)x, &(temp->slot[j]));
                                    *val = atom_getfloat(slots + s + 3);
                                    s += 4;
                                    thisitem->item = val;
                                    temp->slot[j].length = 0;
                                    slotitem_append(thisitem);
                                } else if (strcmp(atom_getsym(slots + s + 2)->s_name, "longlist") == 0) { // slot longlist
                                    long num_numbers = atom_getlong(slots + s + 3); // number of numbers
                                    temp->slot[j].length = 0;
                                    s += 4;
                                    for (i = 0; i < num_numbers; i++) { // add each number 
                                        long *val = (long *)bach_newptr(sizeof(long));
                                        t_slotitem *thisitem = build_slotitem((t_notation_obj *)x, &(temp->slot[j]));
                                        *val = atom_getlong(slots + s);
                                        s += 1;
                                        thisitem->item = val;
                                        slotitem_append(thisitem);
                                    }
                                } else if (strcmp(atom_getsym(slots + s + 2)->s_name, "floatlist") == 0) { // slot floatlist
                                    long num_numbers = atom_getlong(slots + s + 3); // number of numbers
                                    temp->slot[j].length = 0;
                                    s += 4;
                                    for (i = 0; i < num_numbers; i++) { // add each number 
                                        double *val = (double *)bach_newptr(sizeof(double));
                                        t_slotitem *thisitem = build_slotitem((t_notation_obj *)x, &(temp->slot[j]));
                                        *val = atom_getfloat(slots + s);
                                        s += 1;
                                        thisitem->item = val;
                                        slotitem_append(thisitem);
                                    }
                                } else if (strcmp(atom_getsym(slots + s + 2)->s_name, "text") == 0) { // slot text
                                    long num_chars = atom_getlong(slots + s + 3); // number of chars
                                    char *text = (char *) bach_newptr(num_chars + 2);
                                    t_slotitem *thisitem = build_slotitem((t_notation_obj *)x, &(temp->slot[j]));
                                    strncpy_zero(text, atom_getsym(slots + 4)->s_name, num_chars + 1);
                                    s += 5;
                                    bach_copyptr(thisitem->item, text, num_chars * sizeof(char));
                                    temp->slot[j].length = 0; // just to avoid that slotitem_append (which incrase automatically the # of items) get crazy
                                    slotitem_append(thisitem);
                                    temp->slot[j].length = num_chars;
                                    bach_freeptr(text);
                                } else if (strcmp(atom_getsym(slots + s + 2)->s_name, "filelist") == 0) { // slot filelist
                                    long num_files = atom_getlong(slots + s + 3); // number of files
                                    long act_file_index = atom_getlong(slots + s + 4); // active file index (1-based)
                                    temp->slot[j].length = 0;
                                    s += 5;
                                    for (i = 0; i < num_files; i++) { // add each file 
                                        t_slotitem *thisitem = build_slotitem((t_notation_obj *)x, &(temp->slot[j]));
                                        long pathID, filename_length;
                                        char filename[MAX_PATH_CHARS]; 
                                        t_file *file = (t_file *)bach_newptr(sizeof(t_file));
                                        pathID = atom_getlong(slots + s);
                                        filename_length = atom_getlong(slots + s + 1);
                                        file->exists = true;
                                        strncpy_zero(filename, atom_getsym(slots + s + 2)->s_name, MAX_PATH_CHARS);
                                        s += 3;
                                        strncpy_zero(file->filename, filename, MAX_PATH_CHARS);
                                        file->pathID = pathID;
                                        file->filename_length = filename_length;
                                        thisitem->item = file;
                                        if (i + 1 == act_file_index)
                                            slot_set_active_item(&temp->slot[j], thisitem);
                                        slotitem_append(thisitem); // files are ordered! we just have to append them
                                    }
                                } else { // undefined or wrongly defined slot
                                    s += 3;
                                }
                            }
                        } else {
                            s += 1;
                            if (s == slot_list_length) 
                                break;
                        }
                    }
                }
                
                temp = temp->next;
            }
            
            
            update_hscrollbar((t_notation_obj *)x, 0); 
            verbose_print(x);
            
            chord_set_recompute_parameters_flag((t_notation_obj *)x, this_ch);
            set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
            return this_ch; 
        }
    }
    
    return NULL; // if everything is ok, it will not get here 
}

// a bit hardcore: does not assign hatom to NEW rhythmic elements, but rather chains elements DIRECTLY
// (so we won't lose the correct pointing from chords to corresponding rhythmic trees elements)
void llll_rchain_dontfreeelems(t_llll *where, t_llll *what){
    t_llllelem *elem, *nextelem;
    if (!what) return;
    for (elem = what->l_tail; elem; elem = nextelem) {
        nextelem = elem->l_prev;
        llll_prepend(where, elem);
    }
    llll_check(where);

    what->l_count--; // hardcore stuff...
    if (what->l_thing.w_obj)
        bach_freeptr(what->l_thing.w_obj);
    llll_dispose(what);
}

void reset_llll_size(t_llll *ll)
{
    long count = 0;
    t_llllelem *elem;
    for (elem = ll->l_head; elem; elem = elem->l_next)
        count++;
    ll->l_size = count;
}



void check_scorevoice(t_scorevoice *voice)
{
    t_measure *measure;
    for (measure = voice->firstmeasure; measure; measure = measure->next) {
        if (measure->firstchord && !measure->lastchord)
            bach_breakpoint(0);
    }
}


void overflow_chords_to_next_measure(t_score *x, t_measure *measure, t_chord *from_this_chord)
{
    if (!measure->next || !from_this_chord)
        return;
    // counting chords
    long num_ch_to_overflow = 0;
    t_chord *chord;
    for (chord = from_this_chord; chord; chord = chord->next)
        num_ch_to_overflow++;
    
//    llll_cpost(measure->rhythmic_tree);

    t_measure *nextmeasure = measure->next;
    t_chord *from_this_chord_prev = from_this_chord->prev;
    t_chord *last_measure_chord = measure->lastchord;
    t_llll *right = NULL;
    if (from_this_chord_prev) {
        from_this_chord_prev->next = NULL;
        from_this_chord->prev = NULL;

        // gotta split the rhythmic tree
        t_llllelem *leftabysselem = llllelem_create_abyss(from_this_chord_prev->rhythmic_tree_elem, 0);
        t_llllelem *rightabysselem = leftabysselem->l_next;
        right = llll_get();
        while (rightabysselem) {
            t_llllelem *nextrightabysselem = rightabysselem->l_next;
            llll_append(right, rightabysselem);
            rightabysselem = nextrightabysselem;
        }
        leftabysselem->l_next = NULL;
        measure->rhythmic_tree->l_tail = leftabysselem;
        
//        llll_cpost(measure->rhythmic_tree);
//        llll_cpost(right);
        
//        dev_llll_print(measure->rhythmic_tree, NULL, 2, 2, NULL);
//        dev_llll_print(right, NULL, 2, 2, NULL);
    } else {
        measure->firstchord = measure->lastchord = NULL;
        right = measure->rhythmic_tree;
        measure->rhythmic_tree = llll_get(); // no elements in the measure
    }
    
/*    llll_check(right);
    check_scorevoice(measure->voiceparent);
*/
//    post_rhythmic_tree((t_notation_obj *)x, nextmeasure, gensym("NEXTMEAS1"), 2);
    {
        t_chord *nextmeasure_firstchord = nextmeasure->firstchord;
        last_measure_chord->next = nextmeasure_firstchord;
        if (nextmeasure_firstchord)
            nextmeasure_firstchord->prev = last_measure_chord;
        nextmeasure->firstchord = from_this_chord;
        if (!nextmeasure->lastchord)
            nextmeasure->lastchord = last_measure_chord;
        measure->lastchord = from_this_chord_prev;
        nextmeasure->num_chords += num_ch_to_overflow;
        measure->num_chords -= num_ch_to_overflow;
        
        // changing parents!
        for (chord = nextmeasure->firstchord; chord; chord = chord->next)
            chord->parent = nextmeasure;
        
        recompute_measure_r_onsets((t_notation_obj *)x, measure); //recalculating the r_sym_onset for each chord
        measure->r_total_content_duration = measure_get_content_sym_duration(measure);

        recompute_measure_r_onsets((t_notation_obj *)x, nextmeasure); //recalculating the r_sym_onset for each chord
        nextmeasure->r_total_content_duration = measure_get_content_sym_duration(nextmeasure);

        llll_upgrade_depth(nextmeasure->rhythmic_tree);
    }
    
    llll_rchain_dontfreeelems(nextmeasure->rhythmic_tree, right);
//    post_rhythmic_tree((t_notation_obj *)x, nextmeasure, gensym("NEXTMEAS2"), 2);
//    check_scorevoice(measure->voiceparent);

    char changed = false;
    llll_funall(nextmeasure->rhythmic_tree, fix_level_type_flag_for_level_as_ignore_fn, &changed, 1, -1, FUNALL_SKIP_ATOMS);
    recompute_all_for_measure((t_notation_obj *)x, nextmeasure, true);

//    post_rhythmic_tree((t_notation_obj *)x, measure, gensym("MEAS"), 2);
//    post_rhythmic_tree((t_notation_obj *)x, nextmeasure, gensym("NEXTMEAS"), 2);
    
    llll_downgrade_depth(measure->rhythmic_tree);
    reset_llll_size(measure->rhythmic_tree);
    reset_llll_size(nextmeasure->rhythmic_tree);
    
/*    llll_check(measure->rhythmic_tree);
    llll_check(nextmeasure->rhythmic_tree);
  */
    
    if (x->r_ob.auto_complete_measures)
        nextmeasure->need_check_autocompletion = true;
    recompute_all_for_measure((t_notation_obj *)x, measure, true);
    recompute_all_for_measure((t_notation_obj *)x, nextmeasure, true);
}


void check_measure_autocompletion(t_score *x, t_measure *measure)
{
    
    // we delete the "extra" chords, if any
    t_rational meas_sym_dur = measure_get_sym_duration(measure);
    t_rational r_sym_onset = long2rat(0);
    t_chord *chord = measure->firstchord; t_chord *tmpch;
    t_llll *rhythm;
    t_rational rhythm_sym_sum, measure_sym_sum;
    while (chord) {
        char cmp = rat_rat_cmp(r_sym_onset, meas_sym_dur);
        if (cmp > 0 || (cmp == 0 && !chord->is_grace_chord)) {
            if (measure->next && measure->beaming_calculation_flags & k_BEAMING_CALCULATION_DO_AND_OVERFLOW_TO_NEXT) {
                // overflow all following chords to next measure!
                overflow_chords_to_next_measure(x, measure, chord);
                measure->beaming_calculation_flags &= ~k_BEAMING_CALCULATION_DO_AND_OVERFLOW_TO_NEXT;
                break;
            } else {
                // delete chord
                tmpch = chord->next;
                chord_delete_from_measure((t_notation_obj *) x, chord, false);
                chord = tmpch;
            }
        } else if (!chord->is_grace_chord && rat_rat_cmp(rat_rat_sum(r_sym_onset, rat_abs(chord->r_sym_duration)), meas_sym_dur) > 0) {
            if (measure->next && measure->beaming_calculation_flags & k_BEAMING_CALCULATION_DO_AND_OVERFLOW_TO_NEXT) {
                char sign = (chord->r_sym_duration.r_num >= 0) ? 1 : -1;
                t_rational left_dur = rat_long_prod(rat_rat_diff(meas_sym_dur, r_sym_onset), sign);
                t_rational right_dur = rat_long_prod(rat_rat_diff(rat_rat_sum(r_sym_onset, rat_abs(chord->r_sym_duration)), meas_sym_dur), sign);
                t_chord *newleftchord = split_chord(x, chord, 2, true);
                tie_chord(newleftchord);
                newleftchord->r_sym_duration = left_dur;
                newleftchord->next->r_sym_duration = right_dur;

                overflow_chords_to_next_measure(x, measure, newleftchord->next);
                measure->beaming_calculation_flags &= ~k_BEAMING_CALCULATION_DO_AND_OVERFLOW_TO_NEXT;
                break;
            } else {
                // reduce its duration
                char sign = (chord->r_sym_duration.r_num >= 0) ? 1 : -1;
                chord->r_sym_duration = rat_long_prod(rat_rat_diff(meas_sym_dur, r_sym_onset), sign);
                r_sym_onset = meas_sym_dur;
                chord = chord->next;
            }
        } else {
            if (!chord->is_grace_chord)
                r_sym_onset = rat_rat_sum(r_sym_onset, rat_abs(chord->r_sym_duration));
            chord = chord->next;
        }
    }
    
    // we autocomplete the *measure, if needed
    rhythm = measure_get_durations_values_as_llll(x, measure, 0);
    rhythm_sym_sum = llll_sum_abs_of_rat_llll(rhythm);
    measure_sym_sum = measure_get_sym_duration(measure);
    if (x->r_ob.auto_complete_measures) {
        if (rat_rat_cmp(rhythm_sym_sum, measure_sym_sum) < 0) {
            // adding a chord in the measure
            t_chord *newchord = addchord_in_measure_from_notes(x, measure, measure->lastchord, rat_long_prod(rat_rat_diff(measure_sym_sum, rhythm_sym_sum), -1), -1, 0, NULL, NULL, 0);
            newchord->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newchord, 0, WHITENULL_llll);
        }
    }
    llll_free(rhythm);
}

//returns the corresponding first chord in the series
t_chord *split_chord(t_score *x, t_chord *chord, long how_many, long also_split_rests)
{
    // splits a chord in <how_many> chords, preserving total r_sym_duration
    
    if (!chord->parent) {
        object_error((t_object *) x, "Error!");
        return chord;
    }
    
    if (rat_rat_cmp(rat_abs(rat_long_div(chord->r_sym_duration,how_many)), CONST_MIN_SYM_DURATION_FOR_CHORD) < 0) {
        object_warn((t_object *) x, "Warning: trying to create too small chords.");
        return chord;
    }
    
    if (how_many > 1 && (chord->r_sym_duration.r_num > 0 || also_split_rests)){
        t_measure *meas;
        t_llll *beam_llll = NULL;
        t_chord **split;
        t_rational orig_figure = chord->figure;
        long i;
        char is_chord_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)chord);
        
        if (is_chord_selected)
            notation_item_delete_from_selection((t_notation_obj *) x, (t_notation_item *)chord);
        
        meas = chord->parent;
        split = (t_chord **) bach_newptr(how_many * sizeof(t_chord *));
        split[0] = clone_chord((t_notation_obj *) x, chord, k_CLONE_FOR_ORIGINAL);
        split[0]->r_sym_duration = rat_long_div(split[0]->r_sym_duration, how_many);
        split[0]->parent = chord->parent;
        split[0]->r_it.flags = (e_bach_internal_notation_flags) (split[0]->r_it.flags & ~k_FLAG_SPLIT);
        
        if (chord->rhythmic_tree_elem) {
            beam_llll = llll_wrap_element_range(chord->rhythmic_tree_elem, chord->rhythmic_tree_elem);
            // llll_destroyelem(beam_llll->l_head);    // we don't destroy the chord->rhythmic_tree_elem, since it'll be destroyed by the "chord_delete_from_measure" function at the end
            split[0]->rhythmic_tree_elem = llll_appendobj(beam_llll, split[0], 0, WHITENULL_llll);
            set_level_type_flag_for_level(beam_llll, k_RHYTHM_LEVEL_ORIGINAL);
        } else {
            dev_post("WARNING: a chord with no rhythmic tree element was found!!!");
        }
        
        for (i = 1; i < how_many; i++) {
            split[i] = clone_chord_without_lyrics((t_notation_obj *) x, split[0], k_CLONE_FOR_SPLIT);
            split[i]->parent = chord->parent;
            split[i]->r_it.flags = (e_bach_internal_notation_flags) (split[i]->r_it.flags & ~k_FLAG_SPLIT);
            if (beam_llll)
                split[i]->rhythmic_tree_elem = llll_appendobj(beam_llll, split[i], 0, WHITENULL_llll);
        }
        
        for (i = how_many - 1; i >= 0; i--) {
            chord_insert_in_measure((t_notation_obj *) x, meas, split[i], chord, 0);
            if (is_chord_selected)
                notation_item_add_to_selection((t_notation_obj *) x, (t_notation_item *)split[i]);
        }
        
        if (x->r_ob.notation_cursor.chord == chord)
            x->r_ob.notation_cursor.chord = split[0];
        
        for (i = 0; i < how_many; i++) { // resetting ties
            t_note *tmp;
            for (tmp = split[i]->firstnote; tmp; tmp = tmp->next) {
                if (i > 0)
                    tmp->tie_from = NULL;
                if (i < how_many - 1)
                    tmp->tie_to = NULL;
            }
        }
        
        if (split[0]->rhythmic_tree_elem) {
            t_llll *ll = llll_wrap_element_range(split[0]->rhythmic_tree_elem, split[how_many-1]->rhythmic_tree_elem);    // will be ORIGINAL
            if (perfect_log2(rat_long_div(orig_figure, how_many).r_den) < 0) { // forcing a tuplet. we need to force that since when we'll perform analysis and change we'll keep the levels for granted
                ll->l_thing.w_obj = build_rhythm_level_properties();
                ((t_rhythm_level_properties *)ll->l_thing.w_obj)->level_type |= k_RHYTHM_LEVEL_TUPLET;
            }
        } else
            dev_post("WARNING: a chord with no rhythmic tree element was found!!!");
        
        chord_delete_from_measure((t_notation_obj *) x, chord, false);
        
        recompute_all_for_measure((t_notation_obj *)x, meas, true);
        
        t_chord *res = split[0];
        bach_freeptr(split);
        
        return res;
    }
    return chord;
}


char merge(t_score *x, t_rational threshold_sym, double threshold_cents, char gathering_policy_sym, char gathering_policy_cents, char only_selected) 
{
    char changed = 0;
    t_scorevoice *voice = x->firstvoice;
    t_measure *measure; t_chord *chord;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        measure = voice->firstmeasure;
        while (measure) {
            
            chord = measure->firstchord;
            while (chord) {
                t_chord *lastchord, *prev_chord, *next_chord, *chord_to_merge_into;
                
                if (!(only_selected && !notation_item_is_globally_selected((t_notation_obj *)x, (t_notation_item *)chord))) {
                    
                    if ((threshold_sym.r_num >= 0.) && (rat_rat_cmp(rat_abs(chord->r_sym_duration), threshold_sym) <= 0)) { // time merging
                        long count = 0; t_rational smallevents_r_duration = long2rat(0);
                        t_chord *chord2 = chord; 
                        while (chord2 && (rat_rat_cmp(rat_abs(chord2->r_sym_duration), threshold_sym) <= 0)) {
                            if (only_selected && !notation_item_is_globally_selected((t_notation_obj *)x, (t_notation_item *)chord2))
                                break;
                            count++;
                            smallevents_r_duration = rat_rat_sum(smallevents_r_duration, rat_abs(chord->r_sym_duration));
                            chord2 = chord2->next;
                        }
                        
                        lastchord = chord2; 
                        if (lastchord && (lastchord != chord)) 
                            lastchord = lastchord->prev; 
                        else if (!lastchord) 
                            lastchord = measure->lastchord;
                        
                        if (chord->prev) 
                            chord_to_merge_into = chord->prev;
                        else if (lastchord->next) 
                            chord_to_merge_into = lastchord->next;
                        else {
                            clear_measure((t_notation_obj *)x, measure, false, true, false); // all small elements: clear measure!
                            return 1;
                        }
                        
                        prev_chord = chord->prev;
                        next_chord = lastchord->next; 
                        if (count > 0) {
                            t_chord *tmp; char goout = false; 
                            chord2 = chord;
                            changed = 1;
                            while (chord2 && (! goout)) {
                                t_chord *chord_to_merge;
                                if (chord2 == lastchord) goout = true;
                                tmp = chord2->next;
                                // we merge the chord to the first one
                                chord_to_merge = clone_chord((t_notation_obj *) x, chord2, k_CLONE_FOR_ORIGINAL);
                                merge_chords(x, chord_to_merge_into, chord_to_merge, 0, true, true);
                                chord_delete_from_measure((t_notation_obj *) x, chord2, false);
                                chord2 = tmp;
                            }
                        }
                        if (gathering_policy_sym > 0) // add duration to last
                            if (next_chord) 
                                next_chord->r_sym_duration = rat_long_prod(rat_rat_sum(rat_abs(next_chord->r_sym_duration), smallevents_r_duration), (next_chord->r_sym_duration.r_num >= 0) ? 1 : -1);
                            else
                                chord_to_merge_into->r_sym_duration = rat_long_prod(rat_rat_sum(rat_abs(chord_to_merge_into->r_sym_duration), smallevents_r_duration), (chord_to_merge_into->r_sym_duration.r_num >= 0) ? 1 : -1);
                            else if (gathering_policy_sym == 0) { // add duration to both
                                if ((prev_chord) && (next_chord)) {
                                    prev_chord->r_sym_duration = rat_long_prod(rat_rat_sum(rat_abs(prev_chord->r_sym_duration), rat_long_div(smallevents_r_duration, 2)), (prev_chord->r_sym_duration.r_num >= 0) ? 1 : -1);
                                    next_chord->r_sym_duration = rat_long_prod(rat_rat_sum(rat_abs(next_chord->r_sym_duration), rat_long_div(smallevents_r_duration, 2)), (next_chord->r_sym_duration.r_num >= 0) ? 1 : -1);
                                } else
                                    chord_to_merge_into->r_sym_duration = rat_long_prod(rat_rat_sum(rat_abs(chord_to_merge_into->r_sym_duration), smallevents_r_duration), (chord_to_merge_into->r_sym_duration.r_num >= 0) ? 1 : -1);
                            } else // add duration to the first chord
                                if (prev_chord) 
                                    prev_chord->r_sym_duration = rat_long_prod(rat_rat_sum(rat_abs(prev_chord->r_sym_duration), smallevents_r_duration), (prev_chord->r_sym_duration.r_num >= 0) ? 1 : -1);
                                else
                                    chord_to_merge_into->r_sym_duration = rat_long_prod(rat_rat_sum(rat_abs(chord_to_merge_into->r_sym_duration), smallevents_r_duration), (chord_to_merge_into->r_sym_duration.r_num >= 0) ? 1 : -1);
                        
                        recompute_all_for_measure((t_notation_obj *)x, chord_to_merge_into->parent, true);
                        chord = chord_to_merge_into;
                    }
                    
                    // then we merge the mc
                    if (chord_merge_mc(x, chord, threshold_cents, gathering_policy_cents)) 
                        changed = 1;
                    
                }
                
                chord = chord->next;
            }
            measure = measure->next;
            
        }
        voice = voice->next;
    }
    
    if (changed) {
        check_correct_scheduling((t_notation_obj *)x, false);
        notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
    }
    
    return changed;
}


char chord_merge_mc(t_score *x, t_chord *chord, double threshold_cents, char gathering_policy_cents)
{
    char changed = 0;
    if (threshold_cents >= 0.) { // pitch merging
        t_note *note = chord->firstnote;
        while (note) {
            long count_note = 1; double gathering_average_pitch = note->midicents; double last_pitch = note->midicents; 
            t_note *note2 = note->next; char there_is_a_tie = (note->tie_to) ? true : false;
            while (note2 && (note2->midicents - note->midicents <= threshold_cents)) {
                count_note++;
                gathering_average_pitch += note2->midicents;
                last_pitch = note2->midicents;
                there_is_a_tie |= ((note2->tie_to) ? true : false);
                // we delete the note
                note_delete((t_notation_obj *)x, note2, false);
                note2 = note2->next;
            }
            gathering_average_pitch /= count_note;
            if (count_note > 1) {
                changed = 1;
                chord_set_recompute_parameters_flag((t_notation_obj *)x, chord);
                set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
                //  we change the pitch of the first note
                if (gathering_policy_cents > 0) // align to last pitch
                    note->midicents = last_pitch;
                else if (gathering_policy_cents == 0) // align to average pitch
                    note->midicents = gathering_average_pitch;
                if (there_is_a_tie && (!note->tie_to))
                    note->tie_to = (t_note *) WHITENULL;
                // else: nothing to do: it stays aligned to first pitch
                note_compute_approximation((t_notation_obj *) x, note);
            }    
            
            note = note->next;
            
        }
        if (changed) {
            recompute_all_measure_chord_parameters((t_notation_obj *)x, chord->parent);
            chord->parent->need_check_ties = true;
            chord->parent->need_recompute_beamings = true;
            chord->parent->tuttipoint_reference->need_recompute_spacing = k_SPACING_RECALCULATE;
            set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
        }
    }
    
    return changed;
}



long get_max_num_measures(t_score *x, long *voice)
{
    long max_measure_number = x->firstvoice->num_measures;
    t_scorevoice *temp = x->firstvoice->next;
    if (voice) *voice = 0;
    while (temp && (temp->v_ob.number < x->r_ob.num_voices)) {
        if (temp->num_measures > max_measure_number) {
            max_measure_number = temp->num_measures;
            if (voice) *voice = temp->v_ob.number;
        }
        temp = temp->next;
    }
    return max_measure_number;
}


char has_measure_attached_markers(t_score *x, t_measure *measure)
{
    t_marker *mk;
    for (mk = x->r_ob.firstmarker; mk; mk = mk->next)
        if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE && mk->measure_attach_ID == measure->r_it.ID)
            return true;
    
    return false;
}


char voiceensemble_delete_measure(t_score *x, t_measure *measure, t_chord *update_chord_play_cursor_to_this_chord_if_needed, char *need_check_solos, char add_undo_ticks)
{
    t_voice *first = voiceensemble_get_firstvoice((t_notation_obj *)x, (t_voice *)measure->voiceparent);
    t_voice *last = voiceensemble_get_lastvoice((t_notation_obj *)x, (t_voice *)measure->voiceparent);
    
    if (first == last) {
        if (add_undo_ticks) {
            if (has_measure_attached_markers(x, measure))
                undo_tick_create_for_header((t_notation_obj *) x, k_HEADER_MARKERS);
            
            // because of possible ties, we set an undo tick on previous measure
            if (measure->prev)
                undo_tick_create_for_notation_item((t_notation_obj *)x, (t_notation_item *)measure->prev, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            
            // because of tempi, we set an undo tick on next measure: if the current measure has a tempo, and it is the first one, we MIGHT need to
            // assign it to next measure
            if (measure->firsttempo && measure->next)
                undo_tick_create_for_notation_item((t_notation_obj *)x, (t_notation_item *)measure->next, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            
            undo_tick_create_for_notation_item((t_notation_obj *)x, (t_notation_item *)measure, k_UNDO_MODIFICATION_TYPE_INSERT, _llllobj_sym_state);
        }
        return delete_measure((t_notation_obj *)x, measure, update_chord_play_cursor_to_this_chord_if_needed, need_check_solos);
    } else {
        char res = 0;
        t_voice *temp;
        long measure_number = measure->measure_number;
        for (temp = first; temp && temp->number < x->r_ob.num_voices; temp = voice_get_next((t_notation_obj *)x, temp)) {
            t_measure *m = measure_get_nth((t_scorevoice *)temp, measure_number);
            if (m) {
                char this_need_check_solos = false;
                if (add_undo_ticks) {
                    if (has_measure_attached_markers(x, m))
                        undo_tick_create_for_header((t_notation_obj *) x, k_HEADER_MARKERS);
                    if (measure->prev)
                        undo_tick_create_for_notation_item((t_notation_obj *)x, (t_notation_item *)m->prev, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state); // because of ties
                    undo_tick_create_for_notation_item((t_notation_obj *)x, (t_notation_item *)m, k_UNDO_MODIFICATION_TYPE_INSERT, _llllobj_sym_state);
                }
                res |= delete_measure((t_notation_obj *)x, m, update_chord_play_cursor_to_this_chord_if_needed, &this_need_check_solos);
                *need_check_solos |= this_need_check_solos;
            }
            if (temp == last)
                break;
        }
        return res;
    }
}

void turn_measure_into_single_rest(t_score *x, t_measure *measure)
{
    t_chord *newch = NULL;
    
    if (measure->firstchord) {
        measure_delete_all_chords(x, measure);
        
        free_rhythmic_tree((t_notation_obj *)x, measure);
        measure->rhythmic_tree = llll_get();
        
        clear_measure_beams((t_notation_obj *)x, measure);
    }

    t_rational r_sym_duration = rat_long_prod(measure_get_sym_duration(measure), -1);
    newch = addchord_in_measure_from_notes(x, measure, NULL, r_sym_duration, -1, 0, NULL, NULL, 0);
    
    // add a single chord
    newch->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newch, 0, WHITENULL_llll);
    newch->r_measure_onset_sec = long2rat(0);
    newch->onset = chord_get_onset_ms(newch);
    newch->r_tuttipoint_onset_sec = measure->r_tuttipoint_onset_sec;
    newch->tuttipoint_onset_ms = measure->tuttipoint_onset_ms;
    newch->duration_ms = measure->total_duration_ms;
    newch->r_duration_sec = measure->r_total_duration_sec;
    newch->play_r_duration_sec = newch->r_duration_sec;
    newch->play_r_measure_onset_sec = newch->r_measure_onset_sec;
    if (x->r_ob.whole_rests_in_empty_measures)
        newch->figure = long2rat(1);
    else {
        newch->figure = measure_get_sym_duration(measure);
        
        void *data[5];
        char beaming_calculation_flags = 0;
        data[0] = x;
        data[1] = measure;
        data[2] = NULL;
        data[3] = &beaming_calculation_flags;
        data[4] = NULL;
        
        llll_funall(measure->rhythmic_tree, get_rhythm_drawable_for_level_fn, data, 1, one_but_last_level(measure->rhythmic_tree), FUNALL_SKIP_ATOMS);
        calculate_chords_and_tempi_measure_onsets((t_notation_obj *)x, measure);
        recompute_measure_r_onsets((t_notation_obj *)x, measure);
    }
}


/*
void turn_measure_into_single_rest(t_score *x, t_measure *measure)
{
    t_chord *giver = measure && measure->firstchord ? clone_chord((t_notation_obj *)x, measure->firstchord, k_CLONE_FOR_ORIGINAL) : NULL;
    
    clear_measure((t_notation_obj *)x, measure, false, true, false);

    t_rational r_sym_duration = rat_long_prod(measure_get_sym_duration(measure), -1);
    t_chord *newch = addchord_in_measure_from_notes(x, measure, NULL, r_sym_duration, -1, 0, NULL, NULL, 0);

    if (giver)
        clone_slots_for_notation_item((t_notation_obj *)x, (t_notation_item *)giver, (t_notation_item *)newch, k_CLONE_FOR_ORIGINAL);

    // add a single chord

    newch->rhythmic_tree_elem = llll_appendobj(measure->rhythmic_tree, newch, 0, WHITENULL_llll);
    newch->r_measure_onset_sec = long2rat(0);
    newch->onset = chord_get_onset_ms(newch);
    newch->r_tuttipoint_onset_sec = measure->r_tuttipoint_onset_sec;
    newch->tuttipoint_onset_ms = measure->tuttipoint_onset_ms;
    newch->duration_ms = measure->total_duration_ms;
    newch->r_duration_sec = measure->r_total_duration_sec;
    if (x->r_ob.whole_rests_in_empty_measures)
        newch->figure = long2rat(1);
    else {
        newch->figure = measure_get_sym_duration(measure);

        void *data[5];
        char beaming_calculation_flags = 0;
        data[0] = x;
        data[1] = measure;
        data[2] = NULL;
        data[3] = &beaming_calculation_flags;
        data[4] = NULL;
        
        llll_funall(measure->rhythmic_tree, get_rhythm_drawable_for_level_fn, data, 1, one_but_last_level(measure->rhythmic_tree), FUNALL_SKIP_ATOMS);
        calculate_chords_and_tempi_measure_onsets((t_notation_obj *)x, measure);
        recompute_measure_r_onsets((t_notation_obj *)x, measure);
    }
    
    if (giver)
        free_chord((t_notation_obj *)x, giver);
} */

void voiceensemble_turn_measure_into_single_rest(t_score *x, t_measure *measure)
{
    t_voice *first = voiceensemble_get_firstvoice((t_notation_obj *)x, (t_voice *)measure->voiceparent);
    t_voice *last = voiceensemble_get_lastvoice((t_notation_obj *)x, (t_voice *)measure->voiceparent);
    
    if (first == last)
        turn_measure_into_single_rest(x, measure);
    else {
        t_voice *temp;
        for (temp = first; temp && temp->number < x->r_ob.num_voices; temp = voice_get_next((t_notation_obj *)x, temp)) {
            t_measure *m = measure_get_nth((t_scorevoice *)temp, measure->measure_number);
            if (m)
                turn_measure_into_single_rest(x, m);
        }
    }
}

void measure_delete_all_chords(t_score *x, t_measure *measure)
{
    t_chord *chord = measure->firstchord; t_chord *chord2;
    while (chord) { // delete all chords
        chord2 = chord->next;
        chord_delete_from_measure((t_notation_obj *) x, chord, true);
        chord = chord2;
    }
}


void check_if_need_to_flatten_level_when_turning_rest_to_note(t_score *x, t_chord *chord){
    if (chord->firstnote) {
        if (x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_REFINE_ONLY_GRAPHICALLY || x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_REFINE || 
            x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_PROCESS || x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_IGNORE) {
            t_llll *ll = chord->rhythmic_tree_elem->l_parent;
            if (!is_level_locked(chord->parent, ll)) {
            llll_flat(ll, 0, 1, 0, LLLL_FREETHING_MEM);
//            if (ll && ll->l_thing.w_obj)
//                ((t_rhythm_level_properties *)ll->l_thing.w_obj)->level_type |= k_RHYTHM_LEVEL_IGNORE;
            }
        }
    }
}

void check_if_need_to_splatter_level_when_turning_note_to_rest(t_score *x, t_chord *chord){
    if (!chord->firstnote) {
        if (x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_REFINE_ONLY_GRAPHICALLY || x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_REFINE || 
            x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_PROCESS || x->r_ob.tree_handling == k_RHYTHMIC_TREE_HANDLING_IGNORE) {
            t_llll *ll = chord->rhythmic_tree_elem->l_parent;
            if (!is_level_locked(chord->parent, ll)) {
            while (ll && ll->l_owner) {
                t_llll *prev = ll->l_owner->l_parent;
                char num_beams = ll->l_thing.w_obj ? ((t_rhythm_level_properties *)ll->l_thing.w_obj)->beam_number : 0;
                if (num_beams) {
                    if (x->r_ob.rests_within_beaming == k_REST_IN_BEAM_NEVER ||
                        (x->r_ob.rests_within_beaming == k_REST_IN_BEAM_IF_INTERNAL && (!chord->rhythmic_tree_elem->l_next || !chord->rhythmic_tree_elem->l_prev)))
                        llll_splatter(ll->l_owner, LLLL_FREETHING_MEM);
                    else 
                        break;
                } else
                    break;
                ll = prev;
            }
            }
        }
    }
}


char turn_selection_into_rests(t_score *x, char delete_notes, char delete_lyrics, char delete_dynamics, t_llll *slots_to_transfer_to_next_note_in_chord_1based, char transfer_slots_even_if_empty, char transfer_slots_even_to_rests, char also_clear_selection)
{ 
    //delete chords/notes within the selected region: actually, it turns them into rests
    t_notation_item *curr_it, *next_item = NULL;
    t_notation_item *lambda_it = x->r_ob.lambda_selected_item_ID > 0 ? notation_item_retrieve_from_ID((t_notation_obj *)x, x->r_ob.lambda_selected_item_ID) : NULL;
    
    char changed = 0;
    lock_general_mutex((t_notation_obj *)x);    
    for (curr_it = x->r_ob.firstselecteditem; curr_it; curr_it = next_item) { // cycle on the selected items
        
        if (lambda_it && (lambda_it == curr_it || // lambda item is exactly the item we're deleting..
                          notation_item_is_ancestor_of((t_notation_obj *)x, lambda_it, curr_it) || // or one of its ancestors...
                          notation_item_is_ancestor_of((t_notation_obj *)x, curr_it, lambda_it))) { // or one of its progeny...
//            cpost("Trying to delete item %p (type %ld). Can't.", curr_it, curr_it->type);
            object_error((t_object *)x, "Can't turn item into rests, it's being output from the playout!");
            continue;
        }        
        
        next_item = curr_it->next_selected;
        if (curr_it->type == k_NOTE && delete_notes) { // it is a note
            t_note *nt = (t_note *) curr_it;
            t_chord *ch = nt->parent;
            if (!notation_item_is_globally_locked((t_notation_obj *)x, (t_notation_item *)nt)) {
                undo_tick_create_for_selected_notation_item((t_notation_obj *) x, (t_notation_item *)nt->parent, k_MEASURE, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
                note_transfer_slots_to_siebling((t_notation_obj *)x, nt, slots_to_transfer_to_next_note_in_chord_1based, transfer_slots_even_if_empty, transfer_slots_even_to_rests);
                note_delete((t_notation_obj *)x, (t_note *) curr_it, false);
                check_if_need_to_splatter_level_when_turning_note_to_rest(x, ch);
                changed = 1;
            }
        } else if (curr_it->type == k_CHORD && delete_notes) {
            t_chord *ch = ((t_chord *)curr_it);
            if (!notation_item_is_globally_locked((t_notation_obj *)x, (t_notation_item *)ch)) {
                undo_tick_create_for_selected_notation_item((t_notation_obj *) x, (t_notation_item *)ch->parent, k_MEASURE, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
                if (ch->is_grace_chord) {
                    t_measure *meas = ch->parent;
                    chord_delete_from_measure((t_notation_obj *) x, ch, false);
                    recompute_all_for_measure((t_notation_obj *) x, meas, true);
                    changed = 1;
                } else {
                    t_note *nt = ch->firstnote; t_note *nt2;
                    if (ch->r_sym_duration.r_num >= 0) {
                        changed = 1;
                        recompute_all_for_measure((t_notation_obj *) x, ch->parent, true);
                    }
                    
                    t_llll *temp = NULL;
                    while (nt){
                        nt2 = nt->next;
                        if (!nt->locked) {
                            if (transfer_slots_even_to_rests) {
                                if (!nt2) {
                                    if (slots_to_transfer_to_next_note_in_chord_1based && slots_to_transfer_to_next_note_in_chord_1based->l_head)
                                        temp = notation_item_get_slots_to_be_copied((t_notation_obj *)x, (t_notation_item *)nt, slots_to_transfer_to_next_note_in_chord_1based, transfer_slots_even_if_empty);
                                } else
                                    note_transfer_slots_to_siebling((t_notation_obj *)x, nt, slots_to_transfer_to_next_note_in_chord_1based, transfer_slots_even_if_empty, transfer_slots_even_to_rests);
                            }
                            note_delete((t_notation_obj *)x, nt, false);
                            changed = 1;
                        }
                        nt = nt2;
                    }
                    
                    check_if_need_to_splatter_level_when_turning_note_to_rest(x, ch);
                    if (temp) {
                        notation_item_set_slots_from_llll((t_notation_obj *)x, (t_notation_item *)ch, temp);
                        llll_free(temp);
                    }
                }
            }
        } else if (curr_it->type == k_MEASURE && delete_notes) {
            t_measure *meas = ((t_measure *)curr_it);
            if (!notation_item_is_globally_locked((t_notation_obj *)x, (t_notation_item *)meas)){ 
                t_chord *ch = meas->firstchord;
                undo_tick_create_for_selected_notation_item((t_notation_obj *) x, (t_notation_item *)meas, k_MEASURE, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
                while (ch){
                    if (!ch->locked){
                        t_note *nt = ch->firstnote; t_note *nt2;
                        while (nt){
                            nt2 = nt->next;
                            if (!nt->locked) {
                                note_delete((t_notation_obj *)x, nt, false);
                                changed = 1;
                            }
                            nt = nt2;
                        }
                    }
                    ch = ch->next;
                }
                recompute_all_for_measure((t_notation_obj *) x, meas, true);
            }
        
        } else if (curr_it->type == k_LYRICS && delete_lyrics) {
            t_lyrics *ly = (t_lyrics *)curr_it;
            undo_tick_create_for_selected_notation_item((t_notation_obj *) x, (t_notation_item *)ly->owner, k_CHORD, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            changed |= delete_chord_lyrics((t_notation_obj *) x, (t_chord *) ly->owner);
            
        } else if (curr_it->type == k_DYNAMICS && delete_dynamics) {
            t_dynamics *dy = (t_dynamics *)curr_it;
            changed |= chord_delete_dynamics((t_notation_obj *) x, notation_item_get_parent_chord((t_notation_obj *) x, dy->owner_item), true);
        }
        curr_it = next_item;
    }
    
    if (also_clear_selection)
        clear_selection((t_notation_obj *) x);
    unlock_general_mutex((t_notation_obj *)x);    

    check_correct_scheduling((t_notation_obj *)x, true);
        
    return changed;
}


long score_oksize(t_score *x, t_rect *newrect)
{
    if (!x->r_ob.itsme) {
        if (x->r_ob.link_vzoom_to_height)
            notationobj_set_vzoom_depending_on_height((t_notation_obj *)x, newrect->height);
        else
            notationobj_reset_size_related_stuff((t_notation_obj *)x);

        x->r_ob.inner_width = newrect->width - (2 * x->r_ob.j_inset_x);

        reset_all_articulations_positions((t_notation_obj *)x);
        notationobj_reset_all_slurs_position((t_notation_obj *) x);
#ifdef BACH_SUPPORT_SLURS
        notationobj_reset_all_slurs_position((t_notation_obj *)x);
#endif
        x->r_ob.firsttime = true;
        notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
        return 1;
    }
    return 0;
}

void scoreapi_initscore_step01(t_score *x)
{
    long v;
    t_scorevoice *voiceprec = NULL;
    
    score_bach_attribute_declares(x);
    
    x->r_ob.num_systems = 1;
    x->must_append_measures = false;
    x->r_ob.firsttuttipoint = NULL;
    x->r_ob.lasttuttipoint = NULL;
    x->r_ob.need_recompute_tuttipoints = true;
    x->r_ob.need_reassign_local_spacing = true;
    x->r_ob.need_recompute_chords_double_onset = true;
    x->r_ob.nullify_incorrect_ties = true;
    x->r_ob.accidentals_preferences = k_ACC_AUTO;


    // initializing all scorevoices (we DON'T fill them, but we have them). 
    x->r_ob.voiceuspacing_as_floatlist[0] = 0.;
    for (v = 0; v < CONST_MAX_VOICES; v++) {
        t_scorevoice *voice = (t_scorevoice *)bach_newptr(sizeof(t_scorevoice));
        if (v == 0) {
            x->firstvoice = voice;
            x->r_ob.firstvoice = (t_voice *)voice;
        }
        if (v == CONST_MAX_VOICES - 1) {
            x->lastvoice = voice;
            x->r_ob.lastvoice = (t_voice *)voice;
        }    
            
        initialize_scorevoice((t_notation_obj *)x, voice, v, gensym("CM"));
        voice->next = NULL; 
        voice->prev = voiceprec;
        if (voiceprec)
            voiceprec->next = voice; 
        voiceprec = voice;
    }
}

void scoreapi_initscore_step02(t_score *x)
{
    // default attributes vlues
    x->r_ob.tempi_are_all_synchronous = false;
    x->r_ob.auto_complete_measures = true;
    x->r_ob.add_staff = 0;
    x->r_ob.itsme = 0;
    x->r_ob.add_voice = 0;
    x->r_ob.step_y = CONST_STEP_UY * x->r_ob.zoom_y;
    // x->r_ob.horizontal_zoom = 100.;
    x->r_ob.zoom_x = x->r_ob.horizontal_zoom / 100.;
    x->r_ob.j_inset_y = 0.5;
    set_mousedown((t_notation_obj *)x, NULL, k_NONE);
    // x->r_ob.legend = 2;
    // members for scrolling
    x->r_ob.domain = 2000;
    x->r_ob.screen_ms_start = 0;
    x->r_ob.screen_ms_end = 2000;
    x->r_ob.length_ms = 2000; 
    x->r_ob.screen_ux_start = 0;
    x->r_ob.screen_ux_end = 2000;
    x->r_ob.length_ux = 2000; 
    x->r_ob.num_systems = 1; // for now
    
    lock_general_mutex((t_notation_obj *)x);
    clear_selection((t_notation_obj *) x);
    clear_preselection((t_notation_obj *) x);
    unlock_general_mutex((t_notation_obj *)x);
    
    x->r_ob.active_slot_num = -1; // active slot is the normal view (= no slot is visible!)
    x->r_ob.active_slot_num_1based = 0;
    x->r_ob.m_editor = NULL;
    x->r_ob.play_head_ms = -1;
    x->r_ob.play_head_ux = -1;
    x->need_repaint = false;
    x->can_need_repaint = false;
    
    recompute_all(x); // needed here, to have the right domain (after a draw)
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
}


void deletetuttipoint(t_score *x, t_tuttipoint *pt)
{
    if (pt){
        tuttipoint_free_alignmentpoints((t_notation_obj *)x, pt);
        
        x->r_ob.num_tuttipoints--;
        if (pt->prev) { // not the first pt
            if (pt->next) { // not the last pt
                pt->prev->next = pt->next;
                pt->next->prev = pt->prev;
            } else { // last pt
                pt->prev->next = NULL;
                x->r_ob.lasttuttipoint = pt->prev;
            }
        } else { // first pt
            if (pt->next) { // some pt remain
                pt->next->prev = NULL;
                x->r_ob.firsttuttipoint = pt->next;
            } else { // there was just 1 tuttipoint
                x->r_ob.firsttuttipoint = NULL;
                x->r_ob.lasttuttipoint = NULL;
                x->r_ob.num_tuttipoints = 0;
            }
        }
        free_tuttipoint((t_notation_obj *)x, pt);
    }
}

void delete_all_tuttipoints(t_score *x, char also_clear_measure_tuttipoint_references)
{
    t_tuttipoint *pt = x->r_ob.firsttuttipoint; t_tuttipoint *temp;    
    while (pt) {
        temp = pt->next;
        deletetuttipoint(x, pt);
        pt = temp;
    }
    x->r_ob.num_tuttipoints = 0;
    
    if (also_clear_measure_tuttipoint_references)
        clear_all_measure_tuttipoint_references((t_notation_obj *)x);
}


void scoreapi_destroyscore(t_score *x)
{
    t_scorevoice *voice, *temp;
    
    // deleting and freeing everything
    clear_score_body(x, -2);
    
    delete_all_tuttipoints(x, false);
    
    // freeing all voices
    voice = x->firstvoice;  
    while (voice && (voice->v_ob.number < CONST_MAX_VOICES)) {
        temp = voice->next;
        // freeing all tempi
        delete_voice_tempi((t_notation_obj *)x, voice);
        free_voice((t_notation_obj *)x, (t_voice *)voice);
        voice = temp;
    }
}

long how_many_grace_chords_after_chord(t_chord *ch){
    t_chord *temp;
    long count = 0;

    if (!ch)
        return 0;
    
    temp = ch->next;
    while (temp && temp->is_grace_chord){
        count++;
        temp = temp->next;
    }
    return count;
}

long how_many_grace_chords_before_chord(t_chord *ch){
    t_chord *temp;
    long count = 0;
    
    if (!ch)
        return 0;
    
    temp = ch->prev;
    while (temp && temp->is_grace_chord){
        count++;
        temp = temp->prev;
    }
    return count;
}

t_rational total_grace_chords_r_sym_duraions_before_chord(t_chord *ch){
    t_chord *temp;
    t_rational r_sym_dur = long2rat(0);
    
    if (!ch)
        return long2rat(0);
    
    temp = ch->prev;
    while (temp && temp->is_grace_chord){
        r_sym_dur = rat_rat_sum(r_sym_dur, rat_abs(temp->r_sym_duration));
        temp = temp->prev;
    }
    return r_sym_dur;
}

t_rational total_grace_chords_r_sym_duraions_after_chord(t_chord *ch){
    t_chord *temp;
    t_rational r_sym_dur = long2rat(0);
    
    if (!ch)
        return long2rat(0);
    
    temp = ch->next;
    while (temp && temp->is_grace_chord){
        r_sym_dur = rat_rat_sum(r_sym_dur, rat_abs(temp->r_sym_duration));
        temp = temp->next;
    }
    return r_sym_dur;
}


t_rational get_grace_note_equivalent(t_score *x, t_chord *gracechord)
{
    t_chord *prev_non_grace_chord = gracechord;
    t_rational tot_sym, tot_sym_rescaled_with_tempo;
    char interp = 0;
    t_rational figure_tempo_value = long2rat(60), tempo_figure = RAT_1OVER4, tempo_value = long2rat(60);
    t_rational lim;

    get_tempo_at_timepoint((t_notation_obj *)x, gracechord->parent->voiceparent, build_timepoint_with_voice(gracechord->parent->measure_number, gracechord->r_sym_onset, gracechord->parent->voiceparent->v_ob.number), &figure_tempo_value, &tempo_figure, &tempo_value, &interp);
    tempo_value = approx_rat_with_rat(tempo_value, 100000, 10);

    tot_sym = rat_rat_sum(rat_rat_sum(total_grace_chords_r_sym_duraions_before_chord(gracechord), total_grace_chords_r_sym_duraions_after_chord(gracechord)), rat_abs(gracechord->r_sym_duration));
    tot_sym_rescaled_with_tempo = rat_long_prod(rat_rat_prod(tot_sym, x->r_ob.grace_note_equivalent), 8);
//    tot_sym_rescaled_with_tempo = rat_rat_div(rat_long_prod(rat_rat_prod(tot_sym, x->r_ob.grace_note_equivalent), 8 * 60), tempo_value);
 
    while (prev_non_grace_chord && prev_non_grace_chord->is_grace_chord)
        prev_non_grace_chord = chord_get_prev(prev_non_grace_chord);

    if (prev_non_grace_chord) {
        //t_rational diff = rat_rat_diff(prev_non_grace_chord->r_sym_duration, tot_sym_rescaled_with_tempo);
        t_rational ratio = rat_rat_div(tot_sym_rescaled_with_tempo, prev_non_grace_chord->r_sym_duration);
        lim = approx_double_with_rat_fixed_den(x->r_ob.max_percentage_of_chord_taken_by_grace_notes/100., 10, 0, NULL); 
        if (rat_rat_cmp(ratio, lim) > 0){
            t_rational multiplier = rat_rat_div(ratio, lim);
            return rat_rat_div(x->r_ob.grace_note_equivalent, multiplier);
        } else
            return x->r_ob.grace_note_equivalent;
    } else {
        return x->r_ob.grace_note_equivalent;
    }
}

// calculates    chord->onset = global onset (in ms)
//                chord->r_tuttipoint_onset_sec = rational onset w.r. to the tuttipoint (actually in sec)
//                chord->tuttipoint_onset_ms = onset w.r. to the tuttipoint (in ms)
//                also calcolates the chord->duration_ms and the note->duration_ms fields
void calculate_all_chords_remaining_onsets(t_score *x)
{
    t_scorevoice *voice; 
    t_measure *measure; 
    t_chord *chord;
    t_note *nt;
    char interp = 0;
    t_rational grace_equiv = long2rat(0);
    t_rational figure_tempo_value = long2rat(60), tempo_figure = RAT_1OVER4, tempo_value = long2rat(60);
    for (voice = x->firstvoice; voice && (voice->v_ob.number < x->r_ob.num_voices); voice = voice->next)
        for (measure = voice->firstmeasure; measure; measure = measure->next) {
            t_rational tot_sym_duration = long2rat(0), play_r_sec_cur = long2rat(0);
            for (chord = measure->firstchord; chord; chord = chord->next) {
                chord->onset = chord_get_onset_ms(chord);
                chord->play_r_sym_onset = chord->r_sym_onset;
                chord->play_r_measure_onset_sec = chord->r_measure_onset_sec;

                if (chord->is_grace_chord) {
                    t_chord *prevch;
                    if (grace_equiv.r_num == 0)
                        grace_equiv = get_grace_note_equivalent(x, chord);
                    get_tempo_at_timepoint((t_notation_obj *)x, voice, build_timepoint_with_voice(measure->measure_number, chord->r_sym_onset, voice->v_ob.number), &figure_tempo_value, &tempo_figure, &tempo_value, &interp);
                    tempo_value = approx_rat_with_rat(tempo_value, 100000, 10);
                    
                    t_rational diff_sym = rat_long_prod(rat_rat_prod(rat_rat_sum(total_grace_chords_r_sym_duraions_after_chord(chord),
                                                                                 rat_abs(chord->r_sym_duration)), grace_equiv), 8);
                    t_rational diff_sec = rat_rat_div(rat_long_prod(diff_sym, 4 * 60), tempo_value);
                    double diff_ms = (rat2double(total_grace_chords_r_sym_duraions_after_chord(chord)) + rat2double(rat_abs(chord->r_sym_duration))) * rat2double(grace_equiv) * 8 * 4 * 60000 / rat2double(tempo_value); // it's a trade off between precision and preventing overflows... we give up a bit of precision here, we could have just said that this is rat2double(diff_sec)*1000
                    
                    play_r_sec_cur = rat_rat_sum(play_r_sec_cur, diff_sec);
                    chord->play_r_measure_onset_sec = rat_rat_diff(chord->play_r_measure_onset_sec, diff_sec);
                    
                    chord->onset -= diff_ms;
                    chord->play_r_sym_onset = rat_rat_diff(chord->play_r_sym_onset, diff_sym);
                    prevch = chord_get_prev(chord);
                    if (prevch && chord->onset < prevch->onset)
                        chord->onset = prevch->onset;
                    if (!chord->prev && measure->prev && measure->prev->lastchord) {
                        measure->prev->lastchord->play_r_sym_duration = rat_rat_sum(measure->prev->lastchord->play_r_sym_duration, chord->play_r_sym_onset);
                        measure->prev->lastchord->play_r_duration_sec = rat_rat_diff(measure->prev->lastchord->play_r_duration_sec, diff_sec);
                    }
                } else {
                    tot_sym_duration = rat_rat_sum(tot_sym_duration, rat_abs(chord->r_sym_duration));
                    grace_equiv = long2rat(0); // reset grace equivalent
                }
                
                if (chord->prev)
                    chord->prev->play_r_duration_sec = rat_rat_diff(chord->play_r_measure_onset_sec, chord->prev->play_r_measure_onset_sec);

                
                chord->r_tuttipoint_onset_sec = rat_rat_sum(chord->r_measure_onset_sec, chord->parent->r_tuttipoint_onset_sec);
                chord->tuttipoint_onset_ms = (rat2double(chord->r_measure_onset_sec) + rat2double(chord->parent->r_tuttipoint_onset_sec)) * 1000.;
                if (chord->prev) {
                    chord->prev->duration_ms = chord->onset - chord->prev->onset; 
                    chord->prev->r_duration_sec = rat_rat_diff(chord->r_tuttipoint_onset_sec, chord->prev->r_tuttipoint_onset_sec);
                    
                    for (nt = chord->prev->firstnote; nt; nt = nt->next)
                        nt->duration = chord->prev->duration_ms;
                    chord->prev->play_r_sym_duration = rat_rat_diff(chord->play_r_sym_onset, chord->prev->play_r_sym_onset);
                }
            }
            
            if (measure->lastchord) {
                measure->lastchord->play_r_sym_duration = rat_rat_diff(measure_get_sym_duration(measure), measure->lastchord->play_r_sym_onset);
                measure->lastchord->play_r_duration_sec = rat_rat_diff(measure->r_total_duration_sec, measure->lastchord->play_r_measure_onset_sec);
                if (measure->lastchord->is_grace_chord) {
                    t_rational grace_equiv = get_grace_note_equivalent(x, measure->lastchord);
                    get_tempo_at_timepoint((t_notation_obj *)x, voice, build_timepoint_with_voice(measure->measure_number, measure->lastchord->r_sym_onset, voice->v_ob.number), &figure_tempo_value, &tempo_figure, &tempo_value, &interp);
                    measure->lastchord->duration_ms = rat2double(rat_abs(measure->lastchord->r_sym_duration)) * rat2double(grace_equiv) * 8 * 4 * 60000 / rat2double(tempo_value);
                    measure->lastchord->r_duration_sec = rat_rat_div(rat_long_prod(rat_rat_prod(rat_abs(measure->lastchord->r_sym_duration), grace_equiv), 8*4*60), tempo_value);
                } else {
                    t_rational last_chord_dur = get_rat_durations_sec_between_timepoints((t_notation_obj *)x, voice, build_timepoint(measure->measure_number, measure->lastchord->r_sym_onset), build_timepoint(measure->measure_number, rat_rat_sum(measure->lastchord->r_sym_onset, rat_abs(measure->lastchord->r_sym_duration))));
                    measure->lastchord->duration_ms = 1000 * rat2double(last_chord_dur);
                    measure->lastchord->r_duration_sec = last_chord_dur;
                }
                for (nt = measure->lastchord->firstnote; nt; nt = nt->next)
                    nt->duration = measure->lastchord->duration_ms;
                
                measure->measure_filling = rat_rat_cmp(tot_sym_duration, measure_get_sym_duration(measure));
                measure->r_total_content_duration = tot_sym_duration; // we update this, au cas où...
            } else
                measure->measure_filling = -1;
                                              
//                measure->lastchord->duration_ms = measure->firstchord->onset + rat2double(measure->r_total_duration_sec) * 1000. - measure->lastchord->onset; 
        }
}

// calculates    chord->onset = global onset (in ms)
//                chord->r_tuttipoint_onset_sec = rational onset w.r. to the tuttipoint (actually in sec)
//                chord->tuttipoint_onset_ms = onset w.r. to the tuttipoint (in ms)
void calculate_all_tempi_remaining_onsets(t_score *x)
{
    t_scorevoice *voice; t_measure *measure; t_tempo *tempo;
    for (voice = x->firstvoice; voice && (voice->v_ob.number < x->r_ob.num_voices); voice = voice->next)
        for (measure = voice->firstmeasure; measure; measure = measure->next) {
            for (tempo = measure->firsttempo; tempo; tempo = tempo->next) {
                tempo->onset = get_tempo_onset_ms(tempo);
                tempo->r_tuttipoint_onset_sec = rat_rat_sum(tempo->r_measure_onset_sec, measure->r_tuttipoint_onset_sec);
                tempo->tuttipoint_onset_ms = (rat2double(tempo->r_measure_onset_sec) + rat2double(measure->r_tuttipoint_onset_sec)) * 1000.;
            }
        }
}


t_tuttipoint *build_tuttipoint(t_score *x)
{
    t_tuttipoint *tpt = NULL;
    tpt = (t_tuttipoint *)bach_newptrclear(sizeof(t_tuttipoint));
    tpt->prev = NULL;
    tpt->ID = 0;
    tpt->firstalignmentpoint = tpt->lastalignmentpoint = NULL;
    tpt->num_alignmentpoints = 0;
    tpt->need_recompute_spacing = k_SPACING_RECALCULATE;
    tpt->r_onset_sec = long2rat(0);
    tpt->onset_ms = 0;
    return tpt;
}


void calculate_tuttipoints(t_score *x) 
{
    t_tuttipoint *tpt; 
    long i; 
    char go_safe = true;
    char we_needed_to_approximate = false;
    char we_are_done;
    t_tuttipoint *active_tuttipoint;
    t_rational tpt_onset, *totdur;
    double tpt_onset_ms, *totdur_ms, last_onset_ms = 0;
    t_scorevoice *voice;
    t_tuttipoint *this_tpt; 
    t_measure **meas, *this_meas;
    t_scorevoice *vc;
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
#endif

    // delete previous tuttipoints
    delete_all_tuttipoints(x, true);
    
//#ifdef BACH_CHECK_NOTATION_ITEMS
//    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
//#endif

    if (x->r_ob.num_voices <= 0)
        return;
    
    // calculate all measure durations
    for (voice = x->firstvoice; (voice && (voice->v_ob.number < x->r_ob.num_voices)); voice = voice->next)
        calculate_rat_measure_durations_ms_for_voice((t_notation_obj *)x, voice);
    
    // creating first tuttipoint
    tpt = build_tuttipoint(x);
    tpt->need_recompute_spacing = k_SPACING_RECALCULATE;
    
    meas = (t_measure **) bach_newptr(x->r_ob.num_voices * sizeof(t_measure *));
    totdur = (t_rational *) bach_newptr(x->r_ob.num_voices * sizeof(t_rational));
    totdur_ms = (double *) bach_newptr(x->r_ob.num_voices * sizeof(double));
    
    for (i = 0, voice = x->firstvoice; i < x->r_ob.num_voices; i++, voice = voice->next) {
        meas[i] = voice->firstmeasure;
        totdur[i] = long2rat(0);
        totdur_ms[i] = 0;
        if (meas[i]) {
            meas[i]->tuttipoint_reference = tpt;
            meas[i]->r_tuttipoint_onset_sec = long2rat(0);
            meas[i]->tuttipoint_onset_ms = 0;
            tpt->measure[i] = meas[i];
        } else {
            tpt->measure[i] = NULL;
        }
    }
    insert_tuttipoint(x, tpt, NULL);
    
    for (i = 0; i < x->r_ob.num_voices; i++) {
        if (meas[i]) {
            totdur[i] = rat_rat_sum(totdur[i], meas[i]->r_total_duration_sec);
            totdur_ms[i] += meas[i]->total_duration_ms;
            meas[i] = meas[i]->next;
        }
    }
    
    if (go_safe) {
        for (i = 0; i < x->r_ob.num_voices; i++) {
            char changed;
            totdur[i] = approx_rat_with_rat_notify(totdur[i], CONST_RAT_MAX_NUM_SAFETY, CONST_RAT_MAX_DEN_SAFETY, &changed);
            we_needed_to_approximate |= changed;
        }
    }

    we_are_done = false; 
    active_tuttipoint = tpt; 
    tpt_onset = long2rat(0);
    tpt_onset_ms = 0;
    
    long ref_voice = 0;

    long max_num_meas = 0;
    for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next) {
        if (voice->num_measures > max_num_meas) {
            max_num_meas = voice->num_measures;
            ref_voice = voice->v_ob.number;
        }
    }
    
    const double CONST_THRESHOLD = 1;
    while (meas[ref_voice] && !we_are_done) {
        char equals = 1; // is it == to all the others?
        for (i = 0; i < x->r_ob.num_voices; i++) {
            long cmp;
            if (!meas[i]) { 
                if (rat_rat_cmp(totdur[ref_voice], totdur[i]) == -1) {
                    equals = 0; // no tuttipoint! we've ended
                    break;
                } 
                continue;
            }
            
            cmp = double_double_cmp_with_threshold(totdur_ms[ref_voice], totdur_ms[i], CONST_THRESHOLD);
//            cmp = rat_rat_cmp_account_for_approximations(&totdur[ref_voice], &totdur[i], we_needed_to_approximate, CONST_THRESHOLD_FOR_APPROX_TPT_EQ);
            
            if (cmp == -1) { // measure i is farther, nothing to do, just increase meas[0]!
                meas[i]->tuttipoint_reference = active_tuttipoint;
                equals = 0; // no tuttipoints!
                break;
            } else if (cmp == 1) { // measure i is early, maybe we can increase the measure in the i voice...
                long cmp2;
                while (meas[i] && (double_double_cmp_with_threshold(totdur_ms[ref_voice], totdur_ms[i], CONST_THRESHOLD) == 1)) {
                    totdur[i] = rat_rat_sum(totdur[i], meas[i]->r_total_duration_sec);
                    totdur_ms[i] += meas[i]->total_duration_ms;

                    if (go_safe) {
                        char changed;
                        totdur[i] = approx_rat_with_rat_notify(totdur[i], CONST_RAT_MAX_NUM_SAFETY, CONST_RAT_MAX_DEN_SAFETY, &changed);
                        we_needed_to_approximate |= changed;
                    }
                    meas[i]->tuttipoint_reference = active_tuttipoint;
                    meas[i] = meas[i]->next;
                }
                if (!meas[i]) {
                    equals = 0; // no tuttipoint! we've ended
                    break;
                }

                cmp2 = double_double_cmp_with_threshold(totdur_ms[ref_voice], totdur_ms[i], CONST_THRESHOLD);
                
                if (cmp2 == 1) { // still early, but then it means that the number of measure is over. break everything!!!
                    equals = 0;
                    meas[i]->tuttipoint_reference = active_tuttipoint;
                    we_are_done = true;
                    break;
                } else if (cmp2 == -1) { // now it is too far! whatever, no tuttipoint, just increase meas[0]!
                    equals = 0; // no tuttipoint!
                    meas[i]->tuttipoint_reference = active_tuttipoint;
                    break;
                } else if (cmp2 != 0) { // awkward... if we're here there's an error
                    equals = 0; // no tuttipoint!
                    meas[i]->tuttipoint_reference = active_tuttipoint;
                    object_warn((t_object *) x, "Error in tuttipoints calculation.");
                    break;
                } 
                // else if cmp2 == 0, cool, we're at the right timing, we just have to continue
            }
        }
        
        if (we_are_done) { //last tuttipoint references
            long j;
            for (j = 0; j < x->r_ob.num_voices; j++) {
                if (meas[j]) {
                    t_timepoint tp1, tp2; 
                    tp1.measure_num = tpt->measure[j]->measure_number;
                    tp2.pt_in_measure = long2rat(0); 
                    while (meas[j]) {
                        tp2.measure_num = meas[j]->measure_number; tp2.pt_in_measure = long2rat(0);
                        meas[j]->r_tuttipoint_onset_sec = get_rat_durations_sec_between_timepoints((t_notation_obj *)x, scorevoice_get_nth(x, j), tp1, tp2);
                        meas[j]->tuttipoint_onset_ms = rat2double(meas[j]->r_tuttipoint_onset_sec) * 1000;
                        meas[j]->tuttipoint_reference = active_tuttipoint;
                        meas[j] = meas[j]->next;
                    }
                }
            }
            break;
        }
        
        if (equals) {
            // new tuttipoint!
            long j;
            t_tuttipoint *tpt = build_tuttipoint(x);
            tpt->ID = active_tuttipoint->ID + 1;
            tpt->firstalignmentpoint = tpt->lastalignmentpoint = NULL;
            tpt->num_alignmentpoints = 0;
            tpt->need_recompute_spacing = k_SPACING_RECALCULATE;
            tpt->r_onset_sec = totdur[ref_voice]; 
            for (j = 0; j < x->r_ob.num_voices; j++)
                tpt->measure[j] = meas[j] ? meas[j] : NULL;
            insert_tuttipoint(x, tpt, active_tuttipoint);
            active_tuttipoint = tpt;
            for (j = 0; j < x->r_ob.num_voices; j++)
                if (meas[j]) 
                    meas[j]->tuttipoint_reference = active_tuttipoint;
            
            tpt->onset_ms = totdur_ms[ref_voice];
            if (tpt->prev)
                tpt->prev->duration_ms = tpt->onset_ms - last_onset_ms;
            last_onset_ms = tpt->onset_ms;
                
            tpt_onset = tpt->r_onset_sec;
            tpt_onset_ms = tpt->onset_ms;
        }
        
        totdur[ref_voice] = rat_rat_sum(totdur[ref_voice], meas[ref_voice]->r_total_duration_sec); // totdur[0].r_num/(double)totdur[0].r_den
        totdur_ms[ref_voice] += meas[ref_voice]->total_duration_ms;

        if (go_safe) {
            for (i = 0; i < x->r_ob.num_voices; i++) {
                char changed;
                totdur[i] = approx_rat_with_rat_notify(totdur[i], CONST_RAT_MAX_NUM_SAFETY, CONST_RAT_MAX_DEN_SAFETY, &changed);
                we_needed_to_approximate |= changed;
            }
        }
        
        meas[ref_voice] = meas[ref_voice]->next;
    }

    if (x->r_ob.lasttuttipoint)
        x->r_ob.lasttuttipoint->duration_ms = x->r_ob.lasttuttipoint->onset_ms - last_onset_ms;

    
    // finally, calculate r_tuttipoint_onset_sec for each measure
    for (this_tpt = x->r_ob.firsttuttipoint; this_tpt; this_tpt = this_tpt->next) {
        for (i = 0; i < x->r_ob.num_voices; i++) {
            t_rational r_measure_onset = long2rat(0);
            double measure_onset_ms = 0;
            for (this_meas = this_tpt->measure[i]; (this_tpt->next && this_meas != this_tpt->next->measure[i]) || (!this_tpt->next && this_meas); this_meas = this_meas->next) { // TODO: check that this_meas exists?
                this_meas->tuttipoint_reference = this_tpt;
                this_meas->r_tuttipoint_onset_sec = r_measure_onset;
                this_meas->tuttipoint_onset_ms = measure_onset_ms;
//                r_measure_onset = rat_rat_sum(r_measure_onset, this_meas->r_total_duration_sec);
                measure_onset_ms += rat2double(this_meas->r_total_duration_sec)*1000;
                r_measure_onset = approx_rat_with_rat(rat_rat_sum(r_measure_onset, this_meas->r_total_duration_sec), CONST_RAT_MAX_NUM_SAFETY, CONST_RAT_MAX_DEN_SAFETY);
            }
        }
    }
    
    // checking tuttipoints having a measure starting and ending with all the voices
    for (this_tpt = x->r_ob.firsttuttipoint; this_tpt; this_tpt = this_tpt->next) {
        char all_voices_start = true;
        char simple_single_measure_tuttipoint = true;
        char some_measures_have_next = false;
        for (i = 0; i < x->r_ob.num_voices; i++) {
            if (!this_tpt->measure[i]) {
                all_voices_start = false;
                simple_single_measure_tuttipoint = false;
                break;
            } else if (!this_tpt->measure[i]->next && some_measures_have_next) {
                simple_single_measure_tuttipoint = false;
            } else if (this_tpt->measure[i]->next) {
                some_measures_have_next = true;
                if (this_tpt->measure[i]->next->tuttipoint_reference == this_tpt) {
                    simple_single_measure_tuttipoint = false;
                }
            }
        }
        this_tpt->all_voices_are_together = all_voices_start;
        this_tpt->simple_single_measure_tuttipoint = simple_single_measure_tuttipoint;
    }

    // checking if all measures have a tuttipoint reference
    for (vc = x->firstvoice; vc && (vc->v_ob.number < x->r_ob.num_voices); vc = vc->next)
        for (this_meas = vc->firstmeasure; this_meas; this_meas = this_meas->next){
            if (!this_meas->tuttipoint_reference) {
                this_meas->tuttipoint_reference = (this_meas->prev) ? this_meas->prev->tuttipoint_reference : x->r_ob.firsttuttipoint; // just for PANIC
                object_error((t_object *)x, "Measure measure %d of voice %d has no tuttipoint reference.", this_meas->measure_number, vc->v_ob.number + 1);
                dev_post("WARNING! There's a measure with no tuttipoint reference");
            }
        }

    bach_freeptr(meas);
    bach_freeptr(totdur);
    bach_freeptr(totdur_ms);
    
#ifdef BACH_CHECK_NOTATION_ITEMS
    notationobj_check_all_measure_tuttipoints((t_notation_obj *)x);
#endif

}


void insert_tuttipoint(t_score *x, t_tuttipoint *tuttipoint_to_insert, t_tuttipoint *after_this_tuttipoint)
{
    // insert an (already built) tuttipoint in a voice, at a given position.
    if (after_this_tuttipoint) { // not at the beginning
        if (after_this_tuttipoint->next) { // insert between these
            after_this_tuttipoint->next->prev = tuttipoint_to_insert;
            tuttipoint_to_insert->next = after_this_tuttipoint->next;
            tuttipoint_to_insert->prev = after_this_tuttipoint;
            after_this_tuttipoint->next = tuttipoint_to_insert;
        } else { // insert at the end
            tuttipoint_to_insert->next = NULL;
            tuttipoint_to_insert->prev = after_this_tuttipoint;
            after_this_tuttipoint->next = tuttipoint_to_insert;
            x->r_ob.lasttuttipoint = tuttipoint_to_insert;
        }
    } else { // at the beginning
        if (x->r_ob.firsttuttipoint) { // there's already a chord
            tuttipoint_to_insert->next = x->r_ob.firsttuttipoint;
            tuttipoint_to_insert->prev = NULL;
            x->r_ob.firsttuttipoint->prev = tuttipoint_to_insert;
            x->r_ob.firsttuttipoint = tuttipoint_to_insert;
        } else { // no chords in the voices yet
            tuttipoint_to_insert->next = NULL;
            tuttipoint_to_insert->prev = NULL;
            x->r_ob.firsttuttipoint = tuttipoint_to_insert;
            x->r_ob.lasttuttipoint = tuttipoint_to_insert;
        }    
    }
    x->r_ob.num_tuttipoints++;
}

void refresh_all_tuttipoints_offset_ux(t_score *x) 
{  
    // refresh all the tuttipoints offset_ux, by means of the tuttipoints_width
    t_tuttipoint *tpt = x->r_ob.firsttuttipoint;
    double offset_ux = 0.;
    
    if (!tpt)
        return;
    
    while (tpt) {
        tpt->offset_ux = offset_ux;
        offset_ux += tpt->width_ux;
        tpt = tpt->next;
    }
    
    x->r_ob.length_ux = x->r_ob.lasttuttipoint->offset_ux + x->r_ob.lasttuttipoint->width_ux + CONST_SCORE_ADDITIONALS_UX_AT_THE_END;
    x->r_ob.length_ms_till_last_note = x->r_ob.length_ms = x->r_ob.lasttuttipoint->onset_ms + x->r_ob.lasttuttipoint->duration_ms;
}



double get_interpolated_offset_ux(t_score *x, t_tuttipoint *tpt, void *obj_ptr, char obj_type){
    t_alignmentpoint *al;
    for (al = tpt->firstalignmentpoint; al; al = al->next){
        if (!al->next) 
            return al->offset_ux;
        else {
            double this_alpt_onset_ms = 1000 * rat2double(al->r_onset_sec);
            double next_alpt_onset_ms = 1000 * rat2double(al->next->r_onset_sec);
            double onset_ms = (obj_type == k_CHORD) ? ((t_chord *)obj_ptr)->tuttipoint_onset_ms : ((t_tempo *)obj_ptr)->tuttipoint_onset_ms;
            if (onset_ms >= this_alpt_onset_ms && onset_ms < next_alpt_onset_ms)
                return rescale(onset_ms, this_alpt_onset_ms, next_alpt_onset_ms, al->offset_ux, al->next->offset_ux);
        }
    }
    
    return tpt->lastalignmentpoint->offset_ux; 
}

// this does NOT space things properly: only refines the EXISTING spacing
void tuttipoint_refine_spacing(t_score *x, t_tuttipoint *tpt) 
{ 
    long i;
    t_measure *this_meas;
    
    if (x->r_ob.spacing_type == k_SPACING_PROPORTIONAL)
        tuttipoint_calculate_spacing(x, tpt);
        
    for (i = 0; i < x->r_ob.num_voices; i++) // cycle on the voices
        for (this_meas = tpt->measure[i]; ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas)); this_meas = this_meas->next) { // cycle on the measures within the tuttipoin
            t_tempo *tempo;
            t_chord *chord; 
            
            for (tempo = this_meas->firsttempo; tempo; tempo = tempo->next)
                tempo->tuttipoint_offset_ux = get_interpolated_offset_ux(x, tpt, tempo, k_TEMPO);
            
            for (chord = this_meas->firstchord; chord; chord = chord->next) {
                if (chord->r_sym_duration.r_num > 0){
                    double notewidth = chord_get_mainside_notehead_uwidth((t_notation_obj *) x, chord->figure, chord);
                    chord->alignment_ux = get_interpolated_offset_ux(x, tpt, chord, k_CHORD);
                    chord->stem_offset_ux = chord->alignment_ux + chord->direction * notewidth/2.;
                } else 
                    chord->stem_offset_ux = chord->alignment_ux = get_interpolated_offset_ux(x, tpt, chord, k_CHORD);
            }
        }
}


t_alignmentpoint *build_alignmentpoint(){
    t_alignmentpoint *align_pt = (t_alignmentpoint *)bach_newptrclear(sizeof(t_alignmentpoint));
    align_pt->num_aligned_obj = 0; 
    align_pt->prev = NULL; 
    align_pt->next = NULL; 
    align_pt->left_uext = align_pt->left_uext_due_to_lyrics = align_pt->left_uext_due_to_dynamics = align_pt->left_uext_due_to_grace_chords = 0;
    align_pt->right_uext = align_pt->right_uext_due_to_lyrics = align_pt->right_uext_due_to_dynamics = 0;
    align_pt->global_lyrics_uwidth = align_pt->global_dynamics_uwidth = 0;
    align_pt->offset_ux = 0;
    align_pt->tuttipoint_reference = NULL;
    align_pt->r_onset_sec = long2rat(0);
    return align_pt;
}

t_chord *measure_get_first_non_grace_chord(t_measure *meas){
    t_chord *temp = meas->firstchord;
    while (temp && temp->is_grace_chord)
        temp = temp->next;
    return temp;
}


// wf = width factor
void tuttipoint_calculate_spacing_proportional(t_score *x, t_tuttipoint *tpt, double wf)
{ // No Need for alignment points
    // easy case! everything is just proportional
    double temp = 0.;
    t_chord *chord = NULL;
    t_measure *this_meas = NULL, *last_done_meas = NULL;
    long i;
    double XSCALE_FACTOR = CONST_X_SCALING;
    
    for (i = 0; i < x->r_ob.num_voices; i++) // cycle on the voices
        for (this_meas = tpt->measure[i]; (tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas); this_meas = this_meas->next) { // cycle on the measures within the tuttipoin
            t_tempo *tempo;
            
            this_meas->start_barline_offset_ux = 1000 * rat2double(this_meas->r_tuttipoint_onset_sec) * x->r_ob.spacing_width * XSCALE_FACTOR * wf;
            this_meas->width_ux = 1000 * rat2double(this_meas->r_total_duration_sec) * x->r_ob.spacing_width * XSCALE_FACTOR * wf;
            if (this_meas->start_barline_offset_ux + this_meas->width_ux > temp)
                temp = this_meas->start_barline_offset_ux + this_meas->width_ux;
            
            // deciding the needed spaces for ts and barline
            if (!this_meas->prev || !(ts_are_equal(&this_meas->prev->timesignature, &this_meas->timesignature))) {
                this_meas->timesignature_uwidth = ts_get_uwidth((t_notation_obj *) x, &this_meas->timesignature);
                this_meas->timesignature_spacing_uwidth = ts_get_spacing_uwidth((t_notation_obj *) x, &this_meas->timesignature);
            }
            
            for (tempo = this_meas->firsttempo; tempo; tempo = tempo->next)
                tempo->tuttipoint_offset_ux = tempo->tuttipoint_onset_ms *  x->r_ob.spacing_width * XSCALE_FACTOR * wf;
            
            for (chord = this_meas->firstchord; chord; chord = chord->next) {
                double alignment_point = chord->tuttipoint_onset_ms *  x->r_ob.spacing_width * XSCALE_FACTOR * wf;
                chord->alignment_ux = alignment_point;
                if (x->r_ob.align_chords_with_what == k_CHORD_ALIGN_WITH_STEMS)
                    chord->stem_offset_ux = alignment_point;
                else if (x->r_ob.align_chords_with_what == k_CHORD_ALIGN_WITH_PRINCIPAL_NOTEHEAD_CENTER)
                    chord->stem_offset_ux = alignment_point + chord->direction * chord_get_mainside_notehead_uwidth((t_notation_obj *)x, chord->r_sym_duration, chord)/2.;
                else if (x->r_ob.align_chords_with_what == k_CHORD_ALIGN_WITH_PRINCIPAL_NOTEHEAD_END)
                    chord->stem_offset_ux = alignment_point - x->r_ob.zoom_y * notehead_get_uwidth((t_notation_obj *)x, chord->r_sym_duration, chord->firstnote, true);
            }
            
            last_done_meas = this_meas;
        }
    tpt->width_ux = temp;
    if (last_done_meas) {
        tpt->r_duration_sec = rat_rat_sum(last_done_meas->r_tuttipoint_onset_sec, last_done_meas->r_total_duration_sec);
        tpt->duration_ms = last_done_meas->tuttipoint_onset_ms + last_done_meas->total_duration_ms;
    } else {
        tpt->r_duration_sec = long2rat(0);
        tpt->duration_ms = 0;
    }
}

// this really spaces all things properly
void tuttipoint_calculate_spacing(t_score *x, t_tuttipoint *tpt) 
{ 
    // this is the spacing function: assign, within the tuttipoint, to each chord an offset_ux, w.r. to the tuttipoint beginning.
    
    long i;
    t_measure **meas, *this_meas;
    t_chord *chord; 
    t_tempo *tempo;
    double *rightlim, *portion_of_rightlim_due_to_lyrics, general_rightlim;
    t_measure **last_tpt_measures;
    t_alignmentpoint *firstalignmentpoint = NULL, *lastalignmentpoint = NULL; 
    long num_align_pt = 0;
    t_alignmentpoint **endmeasalignmpoints;
    t_alignmentpoint *al_pt;
    t_alignmentpoint *start_tranche, *end_tranche;
    char *done;
    double all_tranches_width = 0.;
    char are_there_stem_up_chords_in_prev_al_pt = false;
    double prev_align_x = 0;
    t_measure *first_tpt_measure = tuttipoint_get_first_measure((t_notation_obj *)x, tpt);
    double wf = 1.;
    long ct;
    wf = tpt->local_spacing_width_multiplier = first_tpt_measure ? first_tpt_measure->local_spacing_width_multiplier : 1.;
    tpt->fixed_spacing_uwidth = first_tpt_measure ? first_tpt_measure->fixed_spacing_uwidth : 0;
    tpt->is_spacing_fixed = first_tpt_measure ? first_tpt_measure->is_spacing_fixed : 0;
    
    // first of all
    tuttipoint_free_alignmentpoints((t_notation_obj *)x, tpt);

    if (x->r_ob.spacing_type == k_SPACING_PROPORTIONAL) {
        tuttipoint_calculate_spacing_proportional(x, tpt, wf);
    } else {
        
        double delta_ux_start_next_tranche = 0;
        t_chord *ch_cursor[CONST_MAX_VOICES];
        t_tempo *tempo_cursor[CONST_MAX_VOICES];
        long tranche_id;

        // initializing chord and tempo cursors
        for (i = 0; i < x->r_ob.num_voices; i++){
            ch_cursor[i] = tpt->measure[i] ? tpt->measure[i]->firstchord : NULL;
            tempo_cursor[i] = tpt->measure[i] ? tempo_get_first_after_measure(tpt->measure[i]) : NULL;
        }
                    
        // tell all chords that we have to recalculate their offset
        for (i = 0; i < x->r_ob.num_voices; i++) // cycle on the voices
            for (this_meas = tpt->measure[i]; ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas)); this_meas = this_meas->next)  // cycle on the measures within the tuttipoint
                for (chord = this_meas->firstchord; chord; chord = chord->next)
                    chord->need_recalculate_onset = true;
        for (i = 0; i < x->r_ob.num_voices; i++) // and all the tempi
            for (this_meas = tpt->measure[i]; ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas)); this_meas = this_meas->next)
                for (tempo = this_meas->firsttempo; tempo; tempo = tempo->next)
                    tempo->need_recalculate_onset = true;
        
        meas = (t_measure **) bach_newptr(x->r_ob.num_voices * sizeof(t_measure *));
        for (i = 0; i < x->r_ob.num_voices; i++) 
            meas[i] = tpt->measure[i];
        
        rightlim = (double *) bach_newptr(x->r_ob.num_voices * sizeof(double)); // here we keep the right limit of all the voices, during the spacing calculation
        for (i = 0; i < x->r_ob.num_voices; i++) 
            rightlim[i] = 0.;

        portion_of_rightlim_due_to_lyrics = (double *) bach_newptr(x->r_ob.num_voices * sizeof(double));
        for (i = 0; i < x->r_ob.num_voices; i++) 
            portion_of_rightlim_due_to_lyrics[i] = 0.; 

        // now each tempo[i] has the first tempo within the tpt (or it could also be a later tempo)
        
        while (true) {
            // finding first chord:
            t_chord *firstchord = NULL; 
            t_tempo *firsttempo = NULL;
            t_rational best_r_onset_sec;
            t_alignmentpoint *align_pt;
            long i = 0;
            long num_chords_to_align = 0;
            long num_tempi_to_align = 0;
            t_chord **chords_to_align;
            t_tempo **tempi_to_align;
            long offset = 0; 
            long idx = -1;
            
            for (i = 0; i < x->r_ob.num_voices; i++) {
                for (chord = ch_cursor[i]; chord && chord->parent->tuttipoint_reference == tpt; chord = chord_get_next(chord))
                    if (chord->need_recalculate_onset && !chord->is_grace_chord){ 
                        if (!firstchord || 
                            (firstchord && chord != firstchord && chord->tuttipoint_onset_ms < firstchord->tuttipoint_onset_ms)) {
                            firstchord = chord;
                            break;
                        }
                    }
            }

            for (i = 0; i < x->r_ob.num_voices; i++)
                for (tempo = tempo_cursor[i]; tempo && tempo->owner && tempo->owner->tuttipoint_reference == tpt; 
                     tempo = tempo_get_next(tempo))
                    if (tempo->need_recalculate_onset) { 
                        if (!firstchord || 
                            (firstchord && !firsttempo && tempo->tuttipoint_onset_ms < firstchord->tuttipoint_onset_ms) ||
                            (firstchord && firsttempo && tempo->tuttipoint_onset_ms < firsttempo->tuttipoint_onset_ms)) {
                            firstchord = NULL;
                            firsttempo = tempo;
                            break;
                        } else if (firstchord && !firsttempo && tempo->tuttipoint_onset_ms == firstchord->tuttipoint_onset_ms) {
//                                   (rat_rat_cmp(rat_rat_sum(tempo->r_measure_onset_sec, tempo->owner->r_tuttipoint_onset_sec), 
//                                                rat_rat_sum(firstchord->r_measure_onset_sec, firstchord->parent->r_tuttipoint_onset_sec)) == 0)) {
                            firsttempo = tempo;
                            break;
                        }
                    }

            
            if (!firstchord && !firsttempo) 
                break; // we're done, we've calculated all the offsets
            
            best_r_onset_sec = firstchord ? rat_rat_sum(firstchord->r_measure_onset_sec, firstchord->parent->r_tuttipoint_onset_sec) : 
            rat_rat_sum(firsttempo->r_measure_onset_sec, firsttempo->owner->r_tuttipoint_onset_sec) ;
            
            align_pt = build_alignmentpoint();

            num_align_pt++;
            if (!firstalignmentpoint) {
                firstalignmentpoint = align_pt;
                lastalignmentpoint = align_pt;
            } else if (lastalignmentpoint) {
                lastalignmentpoint->next = align_pt;
                align_pt->prev = lastalignmentpoint;
                lastalignmentpoint = align_pt;
            }
            #ifdef CONFIGURATION_Development
            check_alignment_points(firstalignmentpoint, lastalignmentpoint);
            #endif
            chords_to_align = (t_chord **) bach_newptr(MAX(1, x->r_ob.num_voices) * sizeof(t_chord *)); // a "syncronous chord family"
            tempi_to_align = (t_tempo **) bach_newptr(MAX(1, x->r_ob.num_voices) * sizeof(t_tempo *)); // a "syncronous tempi family"
            
            if (firstchord) {
                t_scorevoice *voice;
                // find all chords with the same alignment of the firstchord
                for (i = 0; i < x->r_ob.num_voices; i++) 
                    chords_to_align[i] = NULL;
                for (i = 0; i < x->r_ob.num_voices; i++)
                    for (this_meas = tpt->measure[i]; this_meas && ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas)); this_meas = this_meas->next)
                        for (chord = this_meas->firstchord; chord; chord = chord->next)
                            if (chord->need_recalculate_onset == true &&    
                                (chord == firstchord || 
                                 rat_rat_cmp(rat_rat_sum(chord->r_measure_onset_sec, this_meas->r_tuttipoint_onset_sec), best_r_onset_sec) == 0)) {
                                if (chord->is_grace_chord) {
                                    // don't account for it now
                                } else {
                                    if (num_chords_to_align >= 0 && num_chords_to_align < x->r_ob.num_voices) {
                                        chords_to_align[num_chords_to_align] = chord;
                                        num_chords_to_align++;
                                    } else {
                                        notationobj_throw_issue((t_notation_obj *)x);
                                    }
                                }
                            }
                
                // adding the alignment point
                align_pt->r_onset_sec = rat_rat_sum(force_standard_rational(firstchord->r_measure_onset_sec), firstchord->parent->r_tuttipoint_onset_sec);

                #ifdef BACH_SPACING_DEBUG
                    object_post((t_object *) x, "- Adding an alignment point with r_onset_sec: %ld/%ld = %f", align_pt->r_onset_sec.r_num, align_pt->r_onset_sec.r_den, rat2double(align_pt->r_onset_sec));
                    object_post((t_object *) x, "   chord_onset: %ld/%ld = %f", firstchord->r_measure_onset_sec.r_num, firstchord->r_measure_onset_sec.r_den, rat2double(firstchord->r_measure_onset_sec));
                    object_post((t_object *) x, "   parent_onset: %ld/%ld = %f", firstchord->parent->r_tuttipoint_onset_sec.r_num, firstchord->parent->r_tuttipoint_onset_sec.r_den, rat2double(firstchord->parent->r_tuttipoint_onset_sec));
                    object_post((t_object *) x, "   num_chords_to_align: %ld", num_chords_to_align);
                #endif
                
                align_pt->num_aligned_obj = num_chords_to_align;
                for (i = 0; i < num_chords_to_align && i < x->r_ob.num_voices; i++) {
                    t_timepoint tp1, tp2;
                    align_pt->aligned_obj[i] = (t_notation_item *)chords_to_align[i];
                    voice = chords_to_align[i]->parent->voiceparent;
                    align_pt->voice_number[i] = voice->v_ob.number;
                    ch_cursor[CLAMP(voice->v_ob.number, 0, x->r_ob.num_voices - 1)] = chord_get_next(chords_to_align[i]); // updating ch_cursor
                    tp1.measure_num = tpt->measure[align_pt->voice_number[i]]->measure_number; 
                    tp1.pt_in_measure = long2rat(0);
                    tp2.measure_num = chords_to_align[i]->parent->measure_number; 
                    tp2.pt_in_measure = chords_to_align[i]->r_sym_onset;
                    align_pt->r_onset_sym[i] = get_sym_durations_between_timepoints(voice, tp1, tp2);
                    align_pt->timepoints[i] = build_timepoint(chords_to_align[i]->parent->measure_number, chords_to_align[i]->r_sym_onset);
                }
                offset = num_chords_to_align;
            } 
            
            if (firsttempo) { // tempo
                t_scorevoice *voice;
                // find all tempi with the same alignment of the firsttempo
                for (i = 0; i < x->r_ob.num_voices; i++) 
                    tempi_to_align[i] = NULL;
                for (i = 0; i < x->r_ob.num_voices; i++)
                    for (this_meas = tpt->measure[i]; ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas)); this_meas = this_meas->next)
                        for (tempo = this_meas->firsttempo; tempo; tempo = tempo->next)
                            if ((tempo->need_recalculate_onset == true) &&    
                                ((tempo == firsttempo) || (rat_rat_cmp(rat_rat_sum(tempo->r_measure_onset_sec, this_meas->r_tuttipoint_onset_sec), rat_rat_sum(firsttempo->r_measure_onset_sec, firsttempo->owner->r_tuttipoint_onset_sec)) == 0))) {
                                if (num_tempi_to_align >= 0 && num_tempi_to_align < x->r_ob.num_voices) {
                                    tempi_to_align[num_tempi_to_align] = tempo;
                                    num_tempi_to_align++;
                                } else {
                                    notationobj_throw_issue((t_notation_obj *)x);
                                }
                            }
                
                // adding the alignment point
                align_pt->r_onset_sec = rat_rat_sum(force_standard_rational(firsttempo->r_measure_onset_sec), firsttempo->owner->r_tuttipoint_onset_sec);
                align_pt->num_aligned_obj += num_tempi_to_align;
                for (i = 0; i < num_tempi_to_align && i < x->r_ob.num_voices && i + offset < 3 * CONST_MAX_VOICES; i++) {
                    t_timepoint tp1, tp2;
                    align_pt->aligned_obj[i + offset] = (t_notation_item *)tempi_to_align[i];
                    voice = tempi_to_align[i]->owner->voiceparent;
                    align_pt->voice_number[i + offset] = voice->v_ob.number;
                    tempo_cursor[CLAMP(voice->v_ob.number, 0, x->r_ob.num_voices - 1)] = tempo_get_next(tempi_to_align[i]); // updating tempo_cursor
                    tp1.measure_num = tpt->measure[CLAMP(voice->v_ob.number, 0, x->r_ob.num_voices - 1)]->measure_number; tp1.pt_in_measure = long2rat(0);
                    tp2 = build_timepoint(tempi_to_align[i]->owner->measure_number, tempi_to_align[i]->changepoint);
                    align_pt->r_onset_sym[i + offset] = get_sym_durations_between_timepoints(voice, tp1, tp2);
                    align_pt->timepoints[i + offset] = tp2;
                }
            }
            
            if (firstchord) {
                double *alignment_x, *notewidths, *chord_left_uext_with_al, *chord_left_uext_with_al_ignore_grace_chords, *left_uext_due_to_lyrics, *left_uext_due_to_dynamics;
                long *voices;
                char *is_pause;
                double chosen_alignment_x;
                // see how many of those chords start a measure!
                double general_rightlim = array_fmax(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim);
                double barlinewidth = 0.; 
                double ts_change_width = 0.; 
                char some_chord_starts_a_measure = false;
                double max_notewidth = 0.;
                double new_general_right_lim;
                double min_lyrics_left = 0, min_dynamics_left = 0;
                double max_lyrics_right = 0, max_dynamics_right = 0;
                double max_left_uext = 0, max_right_uext = 0;

                for (i = 0; i < num_chords_to_align && i < x->r_ob.num_voices; i++) { 
                    if (chords_to_align[i] == measure_get_first_non_grace_chord(chords_to_align[i]->parent)){ // first chord in measure, 
                        if (chords_to_align[i]->parent->prev) { // ... and it is not the first measure 
                            some_chord_starts_a_measure = true;
                            break;
                        } else { 
                            // first measure
                            double this_ts_width = ts_get_uwidth((t_notation_obj *) x, &chords_to_align[i]->parent->timesignature);
                            double this_ts_spacing_width = ts_get_spacing_uwidth((t_notation_obj *) x, &chords_to_align[i]->parent->timesignature);
                            chords_to_align[i]->parent->timesignature_uwidth = this_ts_width;
                            chords_to_align[i]->parent->timesignature_spacing_uwidth = this_ts_spacing_width;
                            if (this_ts_spacing_width > 0.) // there's a time signature
                                this_ts_spacing_width += CONST_SCORE_USPACE_AFTER_TS;
                            else
                                this_ts_spacing_width = CONST_SCORE_USPACE_AFTER_START_BARLINE_WITH_NO_TS;
                            
                            if (ts_change_width < this_ts_spacing_width)
                                ts_change_width = this_ts_spacing_width;
                            chords_to_align[i]->parent->start_barline_offset_ux = 0.; // first measures! (and first tuttipoint),
                        }
                    }
                }
                
                if (some_chord_starts_a_measure) { //...and it is not the first measure!
                    t_alignmentpoint *align_pt_meas = build_alignmentpoint();
                    num_align_pt++;
                    for (i = 0; i < num_chords_to_align && i < x->r_ob.num_voices && align_pt_meas->num_aligned_obj < 3 * CONST_MAX_VOICES; i++) { 
                        if (chords_to_align[i] == measure_get_first_non_grace_chord(chords_to_align[i]->parent)) { // first chord in measure
                            t_measure *started_measure = chords_to_align[i]->parent;
                            if (started_measure->prev) { // not the first measure
                                
                                // setting previous meas width
                                if (started_measure->prev->tuttipoint_reference == tpt) { // same tuttipoint (not the first measure in the tuttipoint)
                                    started_measure->prev->width_ux = general_rightlim - started_measure->prev->start_barline_offset_ux;
                                }
                                
                                // are there grace notes before the barline, but in the same tuttipoint?
                                t_chord *pr = chord_get_prev(started_measure->firstchord);
                                if (pr && pr->is_grace_chord && pr->parent->tuttipoint_reference == tpt) {
                                    t_chord *temp_grace;
                                    for (temp_grace = pr; temp_grace && temp_grace->is_grace_chord; temp_grace = temp_grace->prev) {
                                        double add = (temp_grace == pr && temp_grace->direction == 1 && chords_to_align[i]->direction == -1) ? CONST_SCORE_ADD_GRACE_USPACE_FOR_STEMS : 0; 
                                        general_rightlim += temp_grace->left_uextension + temp_grace->right_uextension + add + has_chord_at_least_one_tie(temp_grace) * CONST_SCORE_TIE_ADDITIONAL_USPACING + CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                                    }
                                }
                                
                                // deciding the needed spaces for ts and barline
                                if (!(ts_are_equal(&started_measure->prev->timesignature, &started_measure->timesignature))) { // time signature width
                                    double this_ts_width, this_ts_spacing_width, real_width_with_spaces;
                                    this_ts_width = ts_get_uwidth((t_notation_obj *) x, &started_measure->timesignature);
                                    this_ts_spacing_width = ts_get_spacing_uwidth((t_notation_obj *) x, &started_measure->timesignature);
                                    started_measure->timesignature_uwidth = this_ts_width;
                                    started_measure->timesignature_spacing_uwidth = this_ts_spacing_width;
                                    if (this_ts_spacing_width > 0.)
                                        real_width_with_spaces = this_ts_spacing_width + CONST_SCORE_USPACE_AFTER_START_BARLINE_WITH_TS + CONST_SCORE_USPACE_AFTER_TS;
                                    else
                                        real_width_with_spaces = CONST_SCORE_USPACE_AFTER_START_BARLINE_WITH_NO_TS;
                                    if (ts_change_width < real_width_with_spaces) 
                                        ts_change_width = real_width_with_spaces;
                                } else {
                                    double this_ts_spacing_width = (is_measure_single_whole_rest((t_notation_obj *) x, started_measure)) ? 0. : CONST_SCORE_USPACE_AFTER_START_BARLINE_WITH_NO_TS;
                                    started_measure->timesignature_uwidth = 0;
                                    started_measure->timesignature_spacing_uwidth = this_ts_spacing_width;
                                    if (ts_change_width < this_ts_spacing_width)
                                        ts_change_width = this_ts_spacing_width;
                                }
                                switch (started_measure->prev->end_barline->barline_type) { // barline width
                                    case k_BARLINE_SOLID: { if (barlinewidth < 2.) barlinewidth = 2.; break; }
                                    case k_BARLINE_DOUBLE: { if (barlinewidth < 3.) barlinewidth = 3.; break; }
                                    case k_BARLINE_FINAL: { if (barlinewidth < 5.) barlinewidth = 5.; break; }
                                    default: { if (barlinewidth < 1.) barlinewidth = 1.; break; }
                                }
                                // special case: does it end an empty measure with no alignment point in between?
                                if (lastalignmentpoint && lastalignmentpoint->prev) {
                                    long j;
                                    for (j = 0; j < lastalignmentpoint->prev->num_aligned_obj && j < 3 * CONST_MAX_VOICES; j++) {
                                        if ((lastalignmentpoint->prev->aligned_obj[j]->type == k_CHORD) &&
                                            (lastalignmentpoint->prev->voice_number[j] == chords_to_align[i]->parent->voiceparent->v_ob.number) &&
                                            (is_measure_single_whole_rest((t_notation_obj *) x, ((t_chord *)lastalignmentpoint->prev->aligned_obj[j])->parent))) {
                                            general_rightlim += CONST_SCORE_USPACE_BETWEEN_NOTE_AND_BARLINE + rest_get_uwidth((t_notation_obj *) x, long2rat(-1));
                                        }
                                    }
                                }
                                
                                chords_to_align[i]->parent->start_barline_offset_ux = general_rightlim;
                                // updating align_pt
                                align_pt_meas->aligned_obj[align_pt_meas->num_aligned_obj] = (t_notation_item *)chords_to_align[i]->parent->prev->end_barline;
                                align_pt_meas->r_onset_sym[align_pt_meas->num_aligned_obj] = align_pt->r_onset_sym[i];
                                align_pt_meas->voice_number[align_pt_meas->num_aligned_obj] = chords_to_align[i]->parent->voiceparent->v_ob.number;
                                align_pt_meas->timepoints[align_pt_meas->num_aligned_obj] = build_timepoint(chords_to_align[i]->parent->measure_number, long2rat(0));
                                align_pt_meas->r_onset_sec = align_pt->r_onset_sec;
                                align_pt_meas->offset_ux = general_rightlim;
//                                dev_post(">> align_meas_off_ux = %.2f",  align_pt_meas->offset_ux);
                                align_pt_meas->left_uext = align_pt_meas->right_uext = 0;
                                align_pt_meas->left_uext_due_to_lyrics = align_pt_meas->right_uext_due_to_lyrics = 0;
                                align_pt_meas->left_uext_due_to_dynamics = align_pt_meas->right_uext_due_to_dynamics = 0;
                                align_pt_meas->num_aligned_obj++;

                            }
                        }
                    }
                    
                    align_pt_meas->prev = align_pt->prev; // we insert the measure alignment point
                    if (align_pt->prev) {
                        align_pt->prev->next = align_pt_meas;
                    } else {
                        firstalignmentpoint = align_pt_meas; //lastalignmentpoint
                    }
                    align_pt_meas->next = align_pt;
                    align_pt->prev = align_pt_meas;

                    check_alignment_points(firstalignmentpoint, lastalignmentpoint);

                    // setting right_uext_due_to_lyrics
                    if (align_pt_meas->prev) {
                        if (x->r_ob.show_lyrics && x->r_ob.link_lyrics_to_slot > 0){
                            double max_right_lim = array_fmax(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim);
                            double max_right_lim_no_lyrics = array_fmax_with_diff(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim, portion_of_rightlim_due_to_lyrics);
                            if (max_right_lim_no_lyrics < max_right_lim)
                                align_pt_meas->prev->right_uext_due_to_lyrics = max_right_lim - max_right_lim_no_lyrics;
                            else
                                align_pt_meas->prev->right_uext_due_to_lyrics = 0.;
                        } else
                            align_pt_meas->prev->right_uext_due_to_lyrics = 0.;
                    }

                }

                // if there's some barline or some time signature, the right limit has to be aligned for all voices
                if (barlinewidth > 0. || ts_change_width > 0.) { // was: WITHOUT THIS IF clause 
                    for (i = 0; i < x->r_ob.num_voices; i++)
                        rightlim[i] = general_rightlim + barlinewidth + ts_change_width;
                }
                
                // find alignment position for each chord within this "syncronous chord family"
                alignment_x = (double *) bach_newptr(num_chords_to_align * sizeof(double)); // alignment positions of each chord
                left_uext_due_to_lyrics = (double *) bach_newptr(num_chords_to_align * sizeof(double)); // alignment positions of each chord
                left_uext_due_to_dynamics = (double *) bach_newptr(num_chords_to_align * sizeof(double)); // alignment positions of each chord
                chord_left_uext_with_al = (double *) bach_newptr(num_chords_to_align * sizeof(double)); // left extension of each chord with respect to the alignment point
                chord_left_uext_with_al_ignore_grace_chords = (double *) bach_newptr(num_chords_to_align * sizeof(double)); // left extension of each chord with respect to the alignment point, not including the extension due to the grace chords preceding the chord
                voices = (long *) bach_newptr(num_chords_to_align * sizeof(long)); // voices
                notewidths = (double *) bach_newptr(num_chords_to_align * sizeof(double)); // notewidths
                is_pause = (char *) bach_newptr(num_chords_to_align * sizeof(char)); // notewidths
                
                max_left_uext = 0;
                max_right_uext = 0;
                
                for (i = 0; i < num_chords_to_align; i++) {
                    double chord_left_uext, chord_left_uext_for_grace_chords = 0, chord_left_uext_no_grace_chords;
                    char chord_direction, rest_only_measure;
                    long voice_number = chords_to_align[i]->parent->voiceparent->v_ob.number; // voice # of the chord (0-based)
                    t_chord *temp_grace;
                    
                    voices[i] = voice_number;
                    chord_left_uext_no_grace_chords = chord_left_uext = chords_to_align[i]->left_uextension;
                    chord_direction = chords_to_align[i]->direction;
                    is_pause[i] = (chords_to_align[i]->r_sym_duration.r_num < 0) ? 1 : 0;
                    left_uext_due_to_lyrics[i] = 0;
                    left_uext_due_to_dynamics[i] = 0;
                    
                    // handling the particular case of a whole rest in the measure:
                    rest_only_measure = is_measure_single_whole_rest((t_notation_obj *) x, chords_to_align[i]->parent);
                    if (rest_only_measure)
                        chord_left_uext = 0.;
                    
                    // grace chords info
                    for (temp_grace = chords_to_align[i]->prev; temp_grace && temp_grace->is_grace_chord; temp_grace = temp_grace->prev) {
                        double add = (temp_grace == chords_to_align[i]->prev && temp_grace->direction == 1 && chords_to_align[i]->direction == -1) ? CONST_SCORE_ADD_GRACE_USPACE_FOR_STEMS : 0;
                        chord_left_uext_for_grace_chords += temp_grace->left_uextension + MAX(temp_grace->right_uextension + add + has_chord_at_least_one_tie(temp_grace) * CONST_SCORE_TIE_ADDITIONAL_USPACING, CONST_SCORE_MIN_USPACE_BETWEEN_GRACE_CHORDS) + CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                    }
                    chord_left_uext += chord_left_uext_for_grace_chords;
                    
                    if (!temp_grace)    // Oh, well: if the chord is at the beginning of the measure, we account immediately the grace notes for the spacing!
                        chord_left_uext_no_grace_chords = chord_left_uext;
                    
                    if (is_pause[i]) { // pause = rest, sorry...
                        double pausewidth = rest_get_uwidth((t_notation_obj *) x, chords_to_align[i]->figure);
                        notewidths[i] = (rest_only_measure) ? 0. : pausewidth;
                        alignment_x[i] = rightlim[voice_number] + chord_left_uext_no_grace_chords; // was: chord_left_uext;
                        chord_left_uext_with_al[i] = chord_left_uext;
                        chord_left_uext_with_al_ignore_grace_chords[i] = chord_left_uext_no_grace_chords;
                        
                        // alignment point left/right extensions
                        max_left_uext = MAX(max_left_uext, chord_left_uext);
                        max_right_uext = MAX(max_right_uext, chords_to_align[i]->right_uextension);

                    } else {
                        double notewidth = chord_get_mainside_notehead_uwidth((t_notation_obj *) x, chords_to_align[i]->figure, chords_to_align[i]);
                        notewidths[i] = notewidth;
                        
                        if (chord_direction == 1) { // stem up
                            chord_left_uext_with_al[i] = chord_left_uext - notewidth / 2.;
                            chord_left_uext_with_al_ignore_grace_chords[i] = chord_left_uext_no_grace_chords - notewidth / 2.;
                            alignment_x[i] = rightlim[voice_number] + chord_left_uext_with_al_ignore_grace_chords[i]; //was: chord_left_uext_with_al[i];
                            
                            // alignment point left/right extensions
                            max_left_uext = MAX(max_left_uext, chord_left_uext    - notewidth / 2.);
                            max_right_uext = MAX(max_right_uext, chords_to_align[i]->right_uextension + notewidth / 2.);
                        } else { // stem down
                            chord_left_uext_with_al[i] = chord_left_uext + notewidth / 2.;
                            chord_left_uext_with_al_ignore_grace_chords[i] = chord_left_uext_no_grace_chords + notewidth / 2.;
                            alignment_x[i] = rightlim[voice_number] + chord_left_uext_with_al_ignore_grace_chords[i]; // was: chord_left_uext_with_al[i];
                            if (are_there_stem_up_chords_in_prev_al_pt && alignment_x[i] < prev_align_x + notewidth)
                                alignment_x[i] += notewidth;
                            
                            // alignment point left/right extensions
                            max_left_uext = MAX(max_left_uext, chord_left_uext + notewidth / 2.);
                            max_right_uext = MAX(max_right_uext, chords_to_align[i]->right_uextension - notewidth / 2.);
                        }
                        
                        if (x->r_ob.show_lyrics && chords_to_align[i]->lyrics && chords_to_align[i]->lyrics->label) {
                            double this_left = chords_to_align[i]->lyrics->lyrics_ux_shift;
                            double this_right = this_left + chords_to_align[i]->lyrics->lyrics_uwidth;

                            left_uext_due_to_lyrics[i] = chords_to_align[i]->lyrics_portion_of_left_uextension; //portion_of_rightlim_due_to_lyrics[voice_number];

                            if (this_left < min_lyrics_left)
                                min_lyrics_left = this_left;
                            if (this_right > max_lyrics_right)
                                max_lyrics_right = this_right;
                        }

                        
                        if (x->r_ob.show_dynamics && chord_has_dynamics(chords_to_align[i])) {
                            t_dynamics *dyn = chord_get_dynamics(chords_to_align[i]);
                            if (dyn) {
                                double this_left = -dynamics_get_left_extension_from_chord_stem((t_notation_obj *)x, dyn); // TO DO: meno?
                                double this_right = dyn->dynamics_min_uwidth + this_left;
                                
                                left_uext_due_to_dynamics[i] = chords_to_align[i]->dynamics_portion_of_left_uextension; //portion_of_rightlim_due_to_lyrics[voice_number];
                                
                                if (this_left < min_dynamics_left)
                                    min_dynamics_left = this_left;
                                if (this_right > max_dynamics_right)
                                    max_dynamics_right = this_right;
                            }
                        }
                        // in such a way, the alignment point results at the middle of the notehead
                    }
                }
                
                align_pt->left_uext = max_left_uext;
                align_pt->right_uext = max_right_uext;
                
                // finding greatest alignment_x
                max_notewidth = array_fmax(num_chords_to_align, 0, num_chords_to_align - 1, notewidths);
                chosen_alignment_x = array_fmax_and_idx(num_chords_to_align, 0, num_chords_to_align - 1, alignment_x, &idx);
                
                #ifdef BACH_SPACING_DEBUG
                object_post((t_object *) x, "   Aligning to (ux): %.2f", chosen_alignment_x);
                #endif
                
                align_pt->offset_ux = chosen_alignment_x;

                // setting left_uext_due_to_grace_chords
                align_pt->left_uext_due_to_grace_chords = array_fmax(num_chords_to_align, 0, num_chords_to_align - 1, chord_left_uext_with_al) - array_fmax(num_chords_to_align, 0, num_chords_to_align - 1, chord_left_uext_with_al_ignore_grace_chords);
                
                // setting right_uext_due_to_lyrics
                if (align_pt->prev) {
                    if (x->r_ob.show_lyrics && x->r_ob.link_lyrics_to_slot > 0){
                        double max_right_lim = array_fmax(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim);
                        double max_right_lim_no_lyrics = array_fmax_with_diff(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim, portion_of_rightlim_due_to_lyrics);
                        if (max_right_lim_no_lyrics < max_right_lim) {
                            double min_left_al = array_fmax_with_scalar_diff(num_chords_to_align, 0, num_chords_to_align-1, chosen_alignment_x, chord_left_uext_with_al);
                            align_pt->prev->right_uext_due_to_lyrics = MIN(max_right_lim - max_right_lim_no_lyrics, min_left_al - max_right_lim_no_lyrics);
                        } else
                            align_pt->prev->right_uext_due_to_lyrics = 0.;
                    } else
                        align_pt->prev->right_uext_due_to_lyrics = 0.;
                }
                
                // setting left_uext_due_to_lyrics
                if (x->r_ob.show_lyrics && x->r_ob.link_lyrics_to_slot > 0){
                    double chosen_alignment_x_ignore_lyrics = array_fmax_with_diff(num_chords_to_align, 0, num_chords_to_align-1, alignment_x, left_uext_due_to_lyrics);
                    align_pt->left_uext_due_to_lyrics = (idx >= 0 ? MIN(left_uext_due_to_lyrics[idx], chosen_alignment_x - chosen_alignment_x_ignore_lyrics) : 0);
                    align_pt->global_lyrics_uwidth = max_lyrics_right - min_lyrics_left;
                } else {
                    align_pt->left_uext_due_to_lyrics = 0.;
                    align_pt->global_lyrics_uwidth = 0;
                }
                

                // setting left_uext_due_to_dynamics
                if (x->r_ob.show_dynamics && x->r_ob.link_dynamics_to_slot > 0){
                    double chosen_alignment_x_ignore_dynamics = array_fmax_with_diff(num_chords_to_align, 0, num_chords_to_align-1, alignment_x, left_uext_due_to_dynamics);
                    align_pt->left_uext_due_to_dynamics = (idx >= 0 ? MIN(left_uext_due_to_dynamics[idx], chosen_alignment_x - chosen_alignment_x_ignore_dynamics) : 0);
                    align_pt->global_dynamics_uwidth = max_dynamics_right - min_dynamics_left;
                } else {
                    align_pt->left_uext_due_to_lyrics = 0.;
                    align_pt->global_lyrics_uwidth = 0;
                }
                
                
                // setting the alignment to all the "syncronous" chords and updating rightlim
                are_there_stem_up_chords_in_prev_al_pt = false;
                for (i = 0; i < num_chords_to_align; i++) {
                    char tied = false;
                    long voices_i = 0;
                    
                    chords_to_align[i]->alignment_ux = chosen_alignment_x;
                    if (is_pause[i]) {
                        chords_to_align[i]->stem_offset_ux = chosen_alignment_x;
                    } else {
                        tied = has_chord_at_least_one_tie(chords_to_align[i]);
                        if (rat_rat_cmp(chords_to_align[i]->figure, long2rat(1)) >= 0) {
                            chords_to_align[i]->stem_offset_ux = chosen_alignment_x + chords_to_align[i]->direction * notewidths[i] / 2.;
                         } else if (chords_to_align[i]->direction == 1) { // stem up
                            if (!are_there_stem_up_chords_in_prev_al_pt && (rat_rat_cmp(chords_to_align[i]->figure, RAT_1OVER8) <= 0))
                                are_there_stem_up_chords_in_prev_al_pt = true;
                            chords_to_align[i]->stem_offset_ux = chosen_alignment_x + notewidths[i] / 2.;
                        } else { // stem down
                            chords_to_align[i]->stem_offset_ux = chosen_alignment_x - notewidths[i] / 2.;
                        }
                    }
                    chords_to_align[i]->need_recalculate_onset = false;
                    voices_i = CLAMP(voices[i], 0, x->r_ob.num_voices - 1);
                    portion_of_rightlim_due_to_lyrics[voices_i] = 0.;
                    if (is_measure_single_whole_rest((t_notation_obj *) x, chords_to_align[i]->parent))
                        rightlim[voices_i] = chords_to_align[i]->stem_offset_ux + chords_to_align[i]->right_uextension + CONST_SCORE_USPACE_BETWEEN_THINGS;
                    else {
                        rightlim[voices_i] = chords_to_align[i]->stem_offset_ux + chords_to_align[i]->right_uextension + 
                                                    chords_to_align[i]->num_dots * CONST_DOT_UWIDTH + 
                                                    tied * CONST_SCORE_TIE_ADDITIONAL_USPACING + CONST_SCORE_USPACE_BETWEEN_THINGS;
                        portion_of_rightlim_due_to_lyrics[voices_i] = chords_to_align[i]->lyrics_portion_of_right_uextension;
                    }
                    
                    // if the chord is the last chord in measure...
                    if (!chords_to_align[i]->next)
                        rightlim[voices_i] += CONST_SCORE_USPACE_BETWEEN_NOTE_AND_BARLINE;
                    
                    // if the chord was shifted, gotta account for shifting
                    double acc_shift = 0;
                    double shift_for_voiceensembles = chord_get_spacing_correction_for_voiceensembles(x, chords_to_align[i], &acc_shift);
                    rightlim[voices_i] += (shift_for_voiceensembles > 0 ? 10 + shift_for_voiceensembles : 0); // TO DO: WHY 10 + ? it should just be shift_for_voiceensembles... but it doesn't seem to work without 10+!
                    rightlim[voices_i] += acc_shift;
                }
                
                // checking rightlim for all voices
                new_general_right_lim = chosen_alignment_x + CONST_SCORE_USPACE_BETWEEN_THINGS;
                prev_align_x = new_general_right_lim;
                for (i = 0; i < x->r_ob.num_voices; i++) {
                    if (rightlim[i] <= new_general_right_lim) {
                        double new_rightlim_i = new_general_right_lim - (ch_cursor[i] ? ch_cursor[i]->left_uextension - (ch_cursor[i]->direction == 1 ? max_notewidth : 0) : 0);
                        if (new_rightlim_i > rightlim[i]) {
                            rightlim[i] = new_rightlim_i;
                            portion_of_rightlim_due_to_lyrics[i] = 0;
                        } else 
                            portion_of_rightlim_due_to_lyrics[i] = MIN(portion_of_rightlim_due_to_lyrics[i], rightlim[i] - new_rightlim_i);
                    } else 
                        portion_of_rightlim_due_to_lyrics[i] = MIN(portion_of_rightlim_due_to_lyrics[i], rightlim[i] - new_general_right_lim);
                }
                
                bach_freeptr(alignment_x);
                bach_freeptr(left_uext_due_to_lyrics);
                bach_freeptr(left_uext_due_to_dynamics);
                bach_freeptr(chord_left_uext_with_al);
                bach_freeptr(chord_left_uext_with_al_ignore_grace_chords);
                bach_freeptr(voices);
                bach_freeptr(notewidths);
                bach_freeptr(is_pause);
            }
            
            
            if (firsttempo) { // firsttempo: it was a tempo alignment
                if (firstchord) {
                    for (i = 0; i < num_tempi_to_align && i < 3 * CONST_MAX_VOICES; i++) {
                        tempi_to_align[i]->tuttipoint_offset_ux = align_pt->offset_ux;
                        tempi_to_align[i]->need_recalculate_onset = false;
                    }
                } else { // just tempo, no chord
                    double general_rightlim = array_fmax(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim);
                    for (i = 0; i < num_tempi_to_align && i < 3 * CONST_MAX_VOICES; i++){
                        tempi_to_align[i]->tuttipoint_offset_ux = general_rightlim;
                        tempi_to_align[i]->need_recalculate_onset = false;
                    }
                    align_pt->offset_ux = general_rightlim;
                    align_pt->left_uext = align_pt->right_uext = align_pt->left_uext_due_to_lyrics = align_pt->right_uext_due_to_lyrics = align_pt->global_lyrics_uwidth = align_pt->left_uext_due_to_dynamics = align_pt->right_uext_due_to_dynamics = align_pt->global_dynamics_uwidth = 0;
                }
            }
            bach_freeptr(chords_to_align);
            bach_freeptr(tempi_to_align);
        }
        
        general_rightlim = array_fmax(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim);    //rightlim[0] rightlim[1] lastalignmentpoint
        tpt->width_ux = general_rightlim; // updating tpt->width rightlim[0]
        if (lastalignmentpoint) {
            tpt->r_duration_sec = lastalignmentpoint->r_onset_sec; // will be reupdated with the last measure barline onset_ms
            tpt->duration_ms = rat2double(lastalignmentpoint->r_onset_sec) * 1000;
        } else {
            tpt->r_duration_sec = long2rat(0);
            tpt->duration_ms = 0;
        }
        
        
        // ***** HANDLING LAST GRACE CHORDS *****
        double grace_space[CONST_MAX_VOICES];
        double max_grace_space;
        for (i = 0; i < x->r_ob.num_voices; i++) 
            grace_space[i] = 0;
        for (i = 0; i < x->r_ob.num_voices; i++) {
            char are_there_grace = false; 
            for (chord = ch_cursor[i]; chord && chord->parent->tuttipoint_reference == tpt; chord = chord_get_next(chord)) 
                if (chord->is_grace_chord) {
                    grace_space[i] += chord->left_uextension + chord->right_uextension + has_chord_at_least_one_tie(chord) * CONST_SCORE_TIE_ADDITIONAL_USPACING * CONST_GRACE_CHORD_SIZE + CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                    are_there_grace = true;
                }
            if (are_there_grace)
                grace_space[i] += CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
        }
        max_grace_space = array_fmax(x->r_ob.num_voices, 0, x->r_ob.num_voices - 1, grace_space);
        general_rightlim += max_grace_space;
        
        
        
        // ***** HANDLING LAST MEASURES *****
        // adding last measures alignment points
        // N.B: if (tpt->next), all the ending points will be aligned! But what we do here is to handle also the case of (!tpt->next) and all the measure ending not at the same time.
        
        // First of all, we find all last measures 
        last_tpt_measures = (t_measure **) bach_newptr(x->r_ob.num_voices * sizeof(t_measure *)); 
        for (i = 0; i < x->r_ob.num_voices; i++) 
            last_tpt_measures[i] = NULL;
        for (i = 0; i < x->r_ob.num_voices; i++) {
            t_measure *this_meas = tpt->measure[i]; 
            while (this_meas && ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas))) {
                last_tpt_measures[i] = this_meas;
                this_meas = this_meas->next;
            }
        }
        
        endmeasalignmpoints = (t_alignmentpoint **) bach_newptr(x->r_ob.num_voices * sizeof(t_alignmentpoint *)); 
        for (i = 0; i < x->r_ob.num_voices; i++) 
            endmeasalignmpoints[i] = NULL;
        
        done = (char *) bach_newptr(x->r_ob.num_voices * sizeof(char));  
        for (i = 0; i < x->r_ob.num_voices; i++) 
            done[i] = last_tpt_measures[i] ? false : true;
        
        while (true) {
            // searching for the measure that ends first
            t_measure *firstendingmeasure = NULL; 
            t_rational *r_sec_durations = (t_rational *) bach_newptr(x->r_ob.num_voices * sizeof(t_rational)); 
            t_timepoint *timepoints = (t_timepoint *) bach_newptr(x->r_ob.num_voices * sizeof(t_timepoint)); 
            t_measure **endingmeasures = (t_measure **) bach_newptr(x->r_ob.num_voices * sizeof(t_measure *));
            t_timepoint *endingtimepoints = (t_timepoint *) bach_newptr(x->r_ob.num_voices * sizeof(t_timepoint));
            long *endingvoices = (long *) bach_newptr(x->r_ob.num_voices * sizeof(long));
            long num_ending_measures = 0;
            t_alignmentpoint *a_pt; 
            t_alignmentpoint *insert_endmeasures_here = NULL;
            long j;
            t_rational min_r_sec_dur = long2rat(-1);
            
            for (i = 0; i < x->r_ob.num_voices; i++) {
                if (!done[i]) {
                    t_timepoint this_end_meas_tp;
                    t_rational this_r_sec_duration;
                    t_scorevoice *vc = scorevoice_get_nth(x, i);
                    timepoints[i] = build_timepoint(last_tpt_measures[i]->measure_number, genrat(last_tpt_measures[i]->timesignature.numerator, last_tpt_measures[i]->timesignature.denominator));
                    this_end_meas_tp = timepoints[i];
                    this_r_sec_duration = get_rat_durations_sec_between_timepoints((t_notation_obj *)x, vc, build_timepoint(tpt->measure[i]->measure_number, long2rat(0)), this_end_meas_tp);
                    r_sec_durations[i] = this_r_sec_duration;
                    if (min_r_sec_dur.r_num < 0 || rat_rat_cmp(this_r_sec_duration, min_r_sec_dur) == -1) {
                        firstendingmeasure = last_tpt_measures[i];
                        min_r_sec_dur = this_r_sec_duration;
                    }
                }
            }
            
            if (firstendingmeasure){ 
                
                // gathering measures which end at the same time
                for (i = 0; i < x->r_ob.num_voices; i++) { 
                    endingmeasures[i] = NULL; 
                    endingtimepoints[i] = build_timepoint(0, long2rat(0)); 
                    endingvoices[i] = -1; 
                }
                
                for (i = 0; i < x->r_ob.num_voices && num_ending_measures < x->r_ob.num_voices; i++) {
                    if (!done[i] && rat_rat_cmp(r_sec_durations[i], min_r_sec_dur) == 0) {
                        endingmeasures[num_ending_measures] = last_tpt_measures[i];
                        endingtimepoints[num_ending_measures] = timepoints[i];
                        endingvoices[num_ending_measures] = i;
                        done[i] = true;
                        num_ending_measures++;
                    }
                }
                
                // is there another event at min_r_ms_dur?
                for (a_pt = firstalignmentpoint; a_pt; a_pt = a_pt->next) {
                    if (rat_rat_cmp(a_pt->r_onset_sec, min_r_sec_dur) == 0)
                        insert_endmeasures_here = a_pt;
                }
                
                if (insert_endmeasures_here) { // gotta insert them
                    
                    while (insert_endmeasures_here->prev && rat_rat_cmp(insert_endmeasures_here->prev->r_onset_sec, insert_endmeasures_here->r_onset_sec) == 0)
                        insert_endmeasures_here = insert_endmeasures_here->prev;
                    
                    for (j = 0; j < num_ending_measures && j < x->r_ob.num_voices; j++) {
                        t_scorevoice *vc;
                        long insert_endmeasures_here_num_aligned_obj = CLAMP(insert_endmeasures_here->num_aligned_obj, 0, 3 * CONST_MAX_VOICES - 1);
                        endmeasalignmpoints[CLAMP(endingvoices[j], 0, x->r_ob.num_voices - 1)] = insert_endmeasures_here;
                        vc = scorevoice_get_nth(x, endingvoices[j]);
                        insert_endmeasures_here->aligned_obj[insert_endmeasures_here_num_aligned_obj] = (t_notation_item *)scorevoice_get_nth(x, endingvoices[j])->lastmeasure->end_barline; // ending barline!
                        insert_endmeasures_here->timepoints[insert_endmeasures_here_num_aligned_obj] = endingtimepoints[j]; 
                        insert_endmeasures_here->voice_number[insert_endmeasures_here_num_aligned_obj] = endingvoices[j]; 
                        insert_endmeasures_here->r_onset_sym[insert_endmeasures_here_num_aligned_obj] = get_sym_durations_between_timepoints(vc, build_timepoint(tpt->measure[endingvoices[j]]->measure_number, long2rat(0)), endingtimepoints[j]);
                        insert_endmeasures_here->num_aligned_obj++;
                    }
                } else { // gotta create a timepoint and insert it
                    // we create a timepoint
                    t_alignmentpoint *align_pt_meas = build_alignmentpoint();  
                    t_alignmentpoint *insert_after_this = NULL;
                    num_align_pt++;
                    align_pt_meas->num_aligned_obj = num_ending_measures; 
                    align_pt_meas->tuttipoint_reference = tpt;
                    align_pt_meas->r_onset_sec = min_r_sec_dur;
                    for (j = 0; j < num_ending_measures && j < x->r_ob.num_voices; j++) {
                        t_scorevoice *vc;
                        long voice_num = CLAMP(endingvoices[j], 0, x->r_ob.num_voices - 1);
                        endmeasalignmpoints[voice_num] = align_pt_meas;
                        vc = scorevoice_get_nth(x, voice_num);
                        align_pt_meas->aligned_obj[j] = (t_notation_item *)vc->lastmeasure->end_barline; // ending barline!
                        align_pt_meas->timepoints[j] = endingtimepoints[j]; 
                        align_pt_meas->voice_number[j] = endingvoices[j]; 
                        align_pt_meas->r_onset_sym[j] = get_sym_durations_between_timepoints(vc, build_timepoint(tpt->measure[voice_num]->measure_number, long2rat(0)), endingtimepoints[j]);
                    }
                    
                    // special case: does it end an empty measure with no alignment point in between?
                    if (lastalignmentpoint) {
                        for (j = 0; j < num_ending_measures; j++) {
                            long k;
                            for (k = 0; k < lastalignmentpoint->num_aligned_obj && k < 3 * CONST_MAX_VOICES; k++) {
                                if (lastalignmentpoint->aligned_obj[k]) {
                                    if (lastalignmentpoint->aligned_obj[k]->type == k_CHORD &&
                                        lastalignmentpoint->voice_number[k] == align_pt_meas->voice_number[j] &&
                                        
                                        is_measure_single_whole_rest((t_notation_obj *) x, ((t_chord *)lastalignmentpoint->aligned_obj[k])->parent)) {
                                        general_rightlim += CONST_SCORE_USPACE_BETWEEN_NOTE_AND_BARLINE + rest_get_uwidth((t_notation_obj *) x, long2rat(-1));
                                    }
                                }
                            }
                        }
                    }
                    
                    // where do we insert it?
                    for (a_pt = firstalignmentpoint; a_pt; a_pt = a_pt->next) {
                        if (rat_rat_cmp(a_pt->r_onset_sec, min_r_sec_dur) <= 0) {
                            insert_after_this = a_pt;
                        }
                    }
                    
                    if (!lastalignmentpoint){
                        lastalignmentpoint = firstalignmentpoint = align_pt_meas;
                        align_pt_meas->prev = align_pt_meas->next = NULL;
                        align_pt_meas->offset_ux = general_rightlim;
                        tpt->r_duration_sec = align_pt_meas->r_onset_sec; // here we go, we update the r_duration_sec.
                        tpt->duration_ms = rat2double(align_pt_meas->r_onset_sec) * 1000;
                        general_rightlim += 2 * CONST_SCORE_USPACE_AFTER_START_BARLINE_WITH_NO_TS;
                     } else if (insert_after_this == lastalignmentpoint) { // at the end!
                        align_pt_meas->next = NULL;
                        align_pt_meas->prev = lastalignmentpoint;
                        lastalignmentpoint->next = align_pt_meas;
                        lastalignmentpoint = align_pt_meas;
                        align_pt_meas->offset_ux = general_rightlim;
                        tpt->r_duration_sec = align_pt_meas->r_onset_sec; // here we go, we update the r_duration_sec.
                        tpt->duration_ms = rat2double(align_pt_meas->r_onset_sec) * 1000;
                        general_rightlim += 2 * CONST_SCORE_USPACE_AFTER_START_BARLINE_WITH_NO_TS;
                    } else if (insert_after_this) { // this has NEVER to be NULL! we don't insert ending measure barlines at the BEGINNING, do we?
                        align_pt_meas->next = insert_after_this->next;
                        if (insert_after_this->next)
                            insert_after_this->next->prev = align_pt_meas;
                        else
                            lastalignmentpoint = align_pt_meas;
                        align_pt_meas->prev = insert_after_this;
                        insert_after_this->next = align_pt_meas;
                        // finding offset_ux
                        if (align_pt_meas->next)
                            align_pt_meas->offset_ux = align_pt_meas->prev->offset_ux + (align_pt_meas->next->offset_ux - align_pt_meas->prev->offset_ux) * 
                            (rat2double(rat_rat_diff(align_pt_meas->r_onset_sec, align_pt_meas->prev->r_onset_sec))) / (rat2double(rat_rat_diff(align_pt_meas->next->r_onset_sec, align_pt_meas->prev->r_onset_sec)));
                        else
                            align_pt_meas->offset_ux = general_rightlim;
                    } else {
                        align_pt_meas->offset_ux = general_rightlim;
                        dev_post("There's a bug in the lastmeasure tuttipoint insertion.");
                    }
                    
                    check_alignment_points(firstalignmentpoint, lastalignmentpoint);

                    
                    tpt->width_ux = MAX(tpt->width_ux, align_pt_meas->offset_ux);

                    // setting right_uext_due_to_lyrics
                    if (align_pt_meas->prev) {
                        if (x->r_ob.show_lyrics && x->r_ob.link_lyrics_to_slot > 0){
                            double max_right_lim = array_fmax(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim);
                            double max_right_lim_no_lyrics = array_fmax_with_diff(x->r_ob.num_voices, 0, x->r_ob.num_voices-1, rightlim, portion_of_rightlim_due_to_lyrics);
                            if (max_right_lim_no_lyrics < max_right_lim)
                                align_pt_meas->prev->right_uext_due_to_lyrics = max_right_lim - max_right_lim_no_lyrics;
                            else
                                align_pt_meas->prev->right_uext_due_to_lyrics = 0.;
                        } else
                            align_pt_meas->prev->right_uext_due_to_lyrics = 0.;
                    }
                    
                }
            }

            bach_freeptr(r_sec_durations);
            bach_freeptr(timepoints);
            bach_freeptr(endingmeasures);
            bach_freeptr(endingtimepoints);
            bach_freeptr(endingvoices);
            
            if (!firstendingmeasure)
                break;
        }
        
        // *****************************
        // re-scaling all tempi properly
        // *****************************

        al_pt = firstalignmentpoint;
        while (al_pt) { 
            if (al_pt->aligned_obj[0]->type == k_TEMPO) { // tempo not aligned to any chord
                t_alignmentpoint *al_prev = al_pt->prev;
                t_alignmentpoint *al_next = al_pt->next;
                if (al_prev) {
                    long i;
                    double new_x_distance;
                    while (al_next && (al_next->aligned_obj[0]->type == k_TEMPO))
                        al_next = al_next->next;
                    new_x_distance = al_pt->offset_ux;
                    if (al_next) {
                        // now al_prev and al_next are both non-tempi alignment points. 
                        double al_prev_next_x_distance = al_next->offset_ux - al_prev->offset_ux; 
                        t_rational al_prev_next_r_ms_distance = rat_rat_diff(al_next->r_onset_sec, al_prev->r_onset_sec);
                        t_rational al_prev_this_r_ms_distance = rat_rat_diff(al_pt->r_onset_sec, al_prev->r_onset_sec);
                        new_x_distance = al_prev->offset_ux + rat2double(al_prev_this_r_ms_distance) * al_prev_next_x_distance / rat2double(al_prev_next_r_ms_distance);
                    }
                    
                    for (i=0; i<al_pt->num_aligned_obj; i++) {
                        if (al_pt->aligned_obj[i]->type == k_TEMPO) {
                            al_pt->offset_ux = new_x_distance;
                            ((t_tempo *)al_pt->aligned_obj[i])->tuttipoint_offset_ux = new_x_distance;
                        }
                    }
                }
            }
            al_pt = al_pt->next;
        }
        
        #ifdef BACH_SPACING_DEBUG
        dev_post("ALIGNMENT POINTS");
        for (al_pt = firstalignmentpoint; al_pt; al_pt = al_pt->next) {
            dev_post(". offset_ux = %.2f, num_objs = %ld, firstobj = %ld", 
                     al_pt->offset_ux, al_pt->num_aligned_obj, al_pt->num_aligned_obj ? al_pt->aligned_obj[0]->type : 0);
        }
        dev_post("---------------");
        #endif
        
        // beware: at this point the ->offset_ux give the minimal spacing for the region, BUT
        // they don't account for grace notes! The space for grace notes is allocated separately, and independently.
        
        
        // *****************************
        // re-scaling aligning points w.r. to the symbolic durations
        // *****************************

        // the sense is: if we have 50px spacing for 1/8 and 40px spacing for a quarter, there's something wrong about it. We get the 40->100=2*50;
        // actually what we do is operating on a parameter which will linearly move 40->100 (i.e. note spacing -> time signature spacing). One may have 50%-50%.
        // NOW we do this for i = 0. We should find a way for all i's.
        al_pt = firstalignmentpoint; // lastalignmentpoint
        i = 0; // only the first voice... for now! 
        
        delta_ux_start_next_tranche = firstalignmentpoint ? firstalignmentpoint->offset_ux : 0;
        
        tranche_id = -1;
        
        while (al_pt) {
            double dist_ratio = -1.; // not assigned, it will have the pixel / symbol ratio value.
            double max_ratio = -1.; 
            long count_times = 0;
            long j, k; 
            long count = 0;
            t_rational tranche_sym_density;
            double tranche_sec_dur, tranche_minwidth;
            char flags = 0; 
            t_rational bar_sym_duration;
            t_rational tranche_sym_dur;
            double width = 0, surplus, right_shift, minimal_spacing_width;
            double mu = x->r_ob.spacing_proportionality;
            double delta_xi_average, delta_xi2_average, delta_xi_stdev, new_spacing_width, max_dev, stdev_avg_ratio, Psi1, Psi2;
            long count_avg;
            double tranche_part_due_to_lyrics = 0, tranche_part_due_to_dynamics = 0, global_lyrics_uwidth = 0;
            t_alignmentpoint *temp_al_pt;
            double delta_ux_start_tranche = delta_ux_start_next_tranche;
            
            tranche_id++;

            // detecting tranche
            // we split the alignment points into tranches; each tranch 
            start_tranche = al_pt;
            while (al_pt && al_pt->next && 
                   (!are_there_measures_in_alignmentpoint(al_pt) || !are_there_only_measures_in_alignmentpoint(al_pt) || 
                    (are_there_measures_in_alignmentpoint(al_pt) && are_there_measures_in_alignmentpoint(al_pt->next)))) {
                       
                       t_rational diff = rat_rat_diff(al_pt->next->r_onset_sec, al_pt->r_onset_sec); //rat_rat_diff(al_pt->next->r_onset_sym[i], al_pt->r_onset_sym[i]);
                       if (diff.r_num > 0) {
                           dist_ratio = (al_pt->next->offset_ux - al_pt->offset_ux) / rat2double(diff);
                           if (dist_ratio > max_ratio)    
                               max_ratio = dist_ratio;
                       }
                       count_times++;
                       al_pt = al_pt->next;
                   }
            if (count_times == 0) {
                delta_ux_start_next_tranche = al_pt->next ? al_pt->next->offset_ux - al_pt->offset_ux : 0;
                al_pt = al_pt ? al_pt->next : NULL;
                continue;
            }
            end_tranche = al_pt;

            if (start_tranche->offset_ux == end_tranche->offset_ux)
                dev_post("Bug: alignment points coincide!");

            double grace_width = 0;
            for (temp_al_pt = start_tranche->next; temp_al_pt; temp_al_pt = temp_al_pt->next) {
                grace_width += temp_al_pt->left_uext_due_to_grace_chords;
                if (temp_al_pt == end_tranche) 
                    break;
            }

            delta_ux_start_next_tranche = end_tranche->next ? end_tranche->next->offset_ux + grace_width - end_tranche->offset_ux : 0;
            
            // calculating whole tranche symbolic duration; we make an average of symbolic durations in each voice
            tranche_sym_dur = long2rat(0); 
            for (j = 0; j < start_tranche->num_aligned_obj; j++) {
                long this_voice = start_tranche->voice_number[j];
                // looking for something in the same voice in the end_tranche
                for (k = 0; k < end_tranche->num_aligned_obj && k < 3 * CONST_MAX_VOICES; k++) {
                    if (end_tranche->voice_number[k] == this_voice) {
                        tranche_sym_dur = rat_rat_sum(tranche_sym_dur, get_sym_durations_between_timepoints(scorevoice_get_nth(x, this_voice), start_tranche->timepoints[j], end_tranche->timepoints[k]));
                        count++;
                        break;
                    }
                }
            }

            if (count == 0) { // possible...
//                dev_post(". count was 0");
//                tranche_sym_dur = long2rat(0);
                t_timepoint tp = ms_to_timepoint((t_notation_obj *)x, rat2double(end_tranche->r_onset_sec)*1000, start_tranche->voice_number[0], k_MS_TO_TP_RETURN_LEFT_CHORD);
                tranche_sym_dur = get_sym_durations_between_timepoints(scorevoice_get_nth(x, start_tranche->voice_number[0]), 
                                                                       start_tranche->timepoints[0], tp);
            } else // averaging
                tranche_sym_dur = rat_long_div(tranche_sym_dur, count);
            
            tranche_sec_dur = rat2double(end_tranche->r_onset_sec) - rat2double(start_tranche->r_onset_sec); //in seconds!!!
            tranche_sym_density = (tranche_sym_dur.r_num == 0 ? genrat(1, 40000): rat_long_prod(rat_inv(tranche_sym_dur), count_times));
//            dev_post("tpt: %x, tranche_sec_dur: %.2f, tranche_sym_dur: %ld/%ld, tranche_sym_density: %ld/%ld", tpt, tranche_sec_dur, tranche_sym_dur.r_num, tranche_sym_dur.r_den, tranche_sym_density.r_num, tranche_sym_density.r_den);
            
            // we obtain the default width of the tranche. 
            // first we have to know if the tranche corresponds exactly to a measure in some voice. in this case, the default_width function will take it into account via the last flag
            bar_sym_duration = long2rat(0);
            if (start_tranche->next == end_tranche && are_there_measures_in_alignmentpoint(start_tranche) && are_there_measures_in_alignmentpoint(start_tranche->next)) {
                flags = 0; // just two barlines one after the other
            } else if (start_tranche == firstalignmentpoint && are_there_measures_in_alignmentpoint(end_tranche)) {
                flags = 1; //there is surely a measure in a voice which is completed
            } else if (start_tranche->prev && are_there_measures_in_alignmentpoint(start_tranche->prev) && are_there_measures_in_alignmentpoint(end_tranche)) {
                long j, k;
                for (j = 0; j < start_tranche->prev->num_aligned_obj && flags == 0; j++) {
                    if (start_tranche->prev->aligned_obj[j]->type == k_MEASURE_END_BARLINE) {
                        long voice_j;
                        t_measure *start_meas = ((t_measure_end_barline *) start_tranche->prev->aligned_obj[j])->owner->next;
                        if (!start_meas) { // a priori it should never happen
                            flags = 1;
                            bar_sym_duration = long2rat(1); // default 
                            break;
                        }
                        voice_j = start_meas->voiceparent->v_ob.number;
                        for (k = 0; (k < end_tranche->num_aligned_obj) && (flags == 0); k++) {
                            if (end_tranche->aligned_obj[k]->type == k_MEASURE_END_BARLINE) {
                                long voice_k;
                                t_measure *end_meas = ((t_measure_end_barline *) end_tranche->aligned_obj[k])->owner->next;
                                if (!end_meas){ // NULL = last measure
                                    bar_sym_duration = measure_get_sym_duration(start_meas);
                                    flags = 1;
                                    break;
                                }
                                voice_k = end_meas->voiceparent->v_ob.number;
                                if (voice_k == voice_j) {
                                    bar_sym_duration = measure_get_sym_duration(start_meas);
                                    flags = 1;
                                }
                            }
                        }
                    }
                }
            } else {
                flags = 0;
            }
            
            tranche_part_due_to_lyrics = 0;
            tranche_part_due_to_dynamics = 0;
            global_lyrics_uwidth = 0;
            
            // getting standard deviation and average, and possibly changing the spacing_width if needed
            delta_xi_average = 0;
            delta_xi2_average = 0;
            delta_xi_stdev = 0;
            new_spacing_width = x->r_ob.spacing_width;
            count_avg = 0;
            max_dev = 0;
            stdev_avg_ratio = 0.;
            Psi1 = 1;
            Psi2 = 1;
            
            if (x->r_ob.show_lyrics && x->r_ob.link_lyrics_to_slot > 0) {
                for (temp_al_pt = start_tranche; temp_al_pt; temp_al_pt = temp_al_pt->next) {
                    tranche_part_due_to_lyrics += temp_al_pt->left_uext_due_to_lyrics + temp_al_pt->right_uext_due_to_lyrics;
                    global_lyrics_uwidth += temp_al_pt->global_lyrics_uwidth;
                    if (temp_al_pt == end_tranche) 
                        break;
                }
            }

            if (x->r_ob.show_dynamics && x->r_ob.link_dynamics_to_slot > 0) {
                for (temp_al_pt = start_tranche; temp_al_pt; temp_al_pt = temp_al_pt->next) {
                    tranche_part_due_to_dynamics += temp_al_pt->left_uext_due_to_dynamics + temp_al_pt->right_uext_due_to_dynamics;
                    global_lyrics_uwidth += temp_al_pt->global_dynamics_uwidth;
                    if (temp_al_pt == end_tranche)
                        break;
                }
            }
            
            for (temp_al_pt = start_tranche->next; temp_al_pt; temp_al_pt = temp_al_pt->next) {
                double this_delta_offset_ux = temp_al_pt->offset_ux - temp_al_pt->prev->offset_ux;
                if (this_delta_offset_ux > max_dev)
                    max_dev = this_delta_offset_ux;
                delta_xi_average += this_delta_offset_ux;
                delta_xi2_average += this_delta_offset_ux * this_delta_offset_ux;
                count_avg++;
                if (temp_al_pt == end_tranche) break;
            }
            delta_xi_average /= count_avg;
            delta_xi2_average /= count_avg;
            delta_xi_stdev = sqrt(delta_xi2_average - delta_xi_average*delta_xi_average);
            stdev_avg_ratio = delta_xi_stdev/delta_xi_average;

            /*        post("-");
             post("- stdev(Delta xi) = %f", delta_xi_stdev);
             post("- mean(Delta xi) = %f", delta_xi_average);
             post("- maxdev(Delta xi) = %f", max_dev);
             post("- stdev(Delta xi)/mean(Delta xi) = %f", delta_xi_stdev/delta_xi_average);
             post("- stdev(Delta xi)/maxdev(Delta xi) = %f", delta_xi_stdev/max_dev);
             */        
            
            if (stdev_avg_ratio > CONST_SPACING_DECAY_BETA && CONST_SPACING_DECAY_ALPHA > 0.)
                Psi1 = atan(CONST_SPACING_DECAY_ALPHA * (stdev_avg_ratio-CONST_SPACING_DECAY_BETA))/(CONST_SPACING_DECAY_ALPHA * (stdev_avg_ratio-CONST_SPACING_DECAY_BETA));
            
            if     (delta_xi_average > CONST_SPACING_DECAY_BETA_PRIME && CONST_SPACING_DECAY_ALPHA_PRIME > 0.)
                Psi2 = atan(CONST_SPACING_DECAY_ALPHA_PRIME * (delta_xi_average-CONST_SPACING_DECAY_BETA_PRIME))/(CONST_SPACING_DECAY_ALPHA_PRIME * (delta_xi_average-CONST_SPACING_DECAY_BETA_PRIME));
            
            if (Psi1 < 1. || Psi2 < 1.) {
                new_spacing_width *= 1/x->r_ob.spacing_width + Psi1 * Psi2 *(x->r_ob.spacing_width - 1)/x->r_ob.spacing_width;
                //            post("* CHANGED GAMMA: old = %f, new = %f; Psi1 = %f, Psi2 = %f", x->r_ob.spacing_width, new_spacing_width, Psi1, Psi2);
            }
            
            minimal_spacing_width = end_tranche->offset_ux + grace_width - start_tranche->offset_ux - (x->r_ob.lyrics_affect_spacing < 3 ? tranche_part_due_to_lyrics : 0) - (x->r_ob.dynamics_affect_spacing < 3 ? tranche_part_due_to_dynamics : 0);
//            dev_post("> end_tr_offset: %.2f, start_tr_offset: %.2f", end_tranche->offset_ux, start_tranche->offset_ux);

            if (x->r_ob.lyrics_affect_spacing == 2){
                double diff = minimal_spacing_width - global_lyrics_uwidth;
                if (diff < 0)
                    minimal_spacing_width = global_lyrics_uwidth;
            }
            
            if (tpt->is_spacing_fixed) {
                double tranche_proportion = (end_tranche->offset_ux - start_tranche->offset_ux + delta_ux_start_tranche)/tpt->width_ux;
                width = MAX(0, tpt->fixed_spacing_uwidth * tpt->local_spacing_width_multiplier * tranche_proportion - delta_ux_start_tranche);
//                dev_post("> FIXED SPACING: tranche_width = %.2f", width);
            } else {
                double default_width = get_default_uwidth((t_notation_obj *) x, tranche_sym_density, tranche_sym_dur, minimal_spacing_width, flags, new_spacing_width);
                width = tpt->local_spacing_width_multiplier * default_width;
//                dev_post("> FLOATING SPACING: default_width = %.2f, gamma^X = %.2f, WIDTH = %.2f", default_width, tpt->local_spacing_width_multiplier, width);
//                dev_post("  (tranche_sym_density: %ld/%ld, tranche_sym_dur: %ld/%ld, minimal_spacing_width: %.2f, flags: %d, gamma: %.2f", 
//                         tranche_sym_density.r_num, tranche_sym_density.r_den, tranche_sym_dur.r_num, tranche_sym_dur.r_den, minimal_spacing_width, (int) flags, new_spacing_width);
            }

            all_tranches_width += width;
            
            //        post("- this tranche width : %f", width); 
            
            tranche_minwidth = end_tranche->offset_ux + grace_width - start_tranche->offset_ux;
//            tranche_minwidth_width_ratio = (tranche_minwidth > 0) ? width / tranche_minwidth : 1;
            double tranche_minwidth_no_graces = MAX(0, tranche_minwidth - grace_width);
            double tranche_width_no_graces_minwidth_no_graces_ratio = (tranche_minwidth > 0) ? (width - grace_width) / tranche_minwidth_no_graces : 1;
            surplus = width - tranche_minwidth;
            
            if (x->r_ob.spacing_type == k_SPACING_SPRING) {
                double k_sum = 0;
                double end_shift = 0.; 
                double tranche_duration_sec = rat2double(end_tranche->r_onset_sec) - rat2double(start_tranche->r_onset_sec);
                double alpha = x->r_ob.spacing_proportionality;
                
                // ASSIGNING k values
                for (temp_al_pt = start_tranche; temp_al_pt && temp_al_pt->next; temp_al_pt = temp_al_pt->next) {
                    double s_contribution = temp_al_pt->right_uext + temp_al_pt->next->left_uext;
                    if (temp_al_pt->next == end_tranche && are_there_measures_in_alignmentpoint(temp_al_pt->next))
                        s_contribution += x->r_ob.noteheads_typo_preferences.nhpref[k_NOTEHEAD_BLACK_NOTE].uwidth/2.;
//                    temp_al_pt->k = 1;
//                    temp_al_pt->k = rat2double(rat_rat_diff(al_pt->next->r_onset_sec, al_pt->r_onset_sec));
                    temp_al_pt->k = rat2double(rat_rat_diff(temp_al_pt->next->r_onset_sec, temp_al_pt->r_onset_sec)) * pow(tranche_duration_sec * s_contribution, alpha);
                    if (temp_al_pt == end_tranche) 
                        break;
                }
                

                for (temp_al_pt = start_tranche; temp_al_pt; temp_al_pt = temp_al_pt->next) {
                    k_sum += temp_al_pt->k;
                    if (temp_al_pt == end_tranche || (temp_al_pt->next && temp_al_pt->next == end_tranche)) 
                        break;
                }
                if (start_tranche->next) { 
                    double cur = start_tranche->offset_ux;
                    double delta_x = 0;
                    
                    if (end_tranche) {
                        end_shift = width - (end_tranche->offset_ux - start_tranche->offset_ux);
                        end_tranche->offset_ux = start_tranche->offset_ux + width;
                    }

                    delta_x = width * start_tranche->k / k_sum;
                    cur += delta_x;
                    start_tranche->next->offset_ux = cur;
                        
                    for (temp_al_pt = start_tranche->next->next; temp_al_pt; temp_al_pt = temp_al_pt->next) {
                        double old_delta_x = delta_x;
                        delta_x = old_delta_x * temp_al_pt->prev->k / temp_al_pt->prev->prev->k;
                        cur += delta_x; 
                        temp_al_pt->offset_ux = cur;
                        if (temp_al_pt == end_tranche) 
                            break;
                    }
                }
                
                if (temp_al_pt && !temp_al_pt->next)
                    tpt->width_ux = temp_al_pt->offset_ux; // update tpt width (useful for updating last measure width, later on) //al_pt //firstalignmentpoint
                
                // we gotta shift all the following tranches
                if (end_tranche) {
                    temp_al_pt = end_tranche->next;
                    while (temp_al_pt) {
                        temp_al_pt->offset_ux += end_shift;
                        temp_al_pt = temp_al_pt->next;
                    }
                }
                
            } else {
                
                
                // ok, let's see the spacing
                right_shift = 0.;
                if (max_ratio > 0.) { // we re-scale all the alignment points within the measure
                    // if max_ratio == 0. there's nothing to respace (probably only two barlines)
                    
                    t_alignmentpoint *temp_al_pt = start_tranche; 
                    double end_shift = 0.; 
                    t_alignmentpoint *temp_al_pt_prev;
                    
                    // we check if there's enough space to use ts spacing
                    if (x->r_ob.spacing_type == k_SPACING_SMART) { // smart spacing
                        // gotta decide what mu needs to be! 
                        double prev_ts_respaced_offset_ux = start_tranche->offset_ux;
                        double prev_note_respaced_offset_ux = start_tranche->offset_ux;
                        double maximum_mu = 1.;
                        double curr_grace_spacing = 0;
                        
                        for (temp_al_pt = start_tranche->next; temp_al_pt; temp_al_pt = temp_al_pt->next) {
                            double ts_respaced_offset_ux = start_tranche->offset_ux + (rat2double(rat_rat_diff(temp_al_pt->r_onset_sec, start_tranche->r_onset_sec))/tranche_sec_dur) * width + curr_grace_spacing;
                            double note_respaced_offset_ux = start_tranche->offset_ux + tranche_width_no_graces_minwidth_no_graces_ratio * (temp_al_pt->offset_ux - start_tranche->offset_ux) + curr_grace_spacing;
                            double this_collision = (ts_respaced_offset_ux - prev_ts_respaced_offset_ux) - (temp_al_pt->offset_ux - temp_al_pt->prev->offset_ux) - CONST_THRESHOLD_FOR_SMART_SPACING;
                            
                            if (temp_al_pt->next)
                                curr_grace_spacing += temp_al_pt->next->left_uext_due_to_grace_chords;
                            
                            if (this_collision < 0){
                                double this_mu_num = ((temp_al_pt->offset_ux - temp_al_pt->prev->offset_ux) - (note_respaced_offset_ux - prev_note_respaced_offset_ux) + CONST_THRESHOLD_FOR_SMART_SPACING);
                                double this_mu_den = ((ts_respaced_offset_ux - prev_ts_respaced_offset_ux) - (note_respaced_offset_ux - prev_note_respaced_offset_ux));
                                if (this_mu_den != 0){
                                    double this_mu = this_mu_num/this_mu_den;
                                    double this_mu_clipped = CLAMP(this_mu, 0., 1.);
                                    if (this_mu_clipped < maximum_mu)
                                        maximum_mu = this_mu_clipped;
                                    //                            post("-this_mu: %f", this_mu);
                                }
                            }
                            
                            prev_ts_respaced_offset_ux = ts_respaced_offset_ux;
                            prev_note_respaced_offset_ux = note_respaced_offset_ux;
                            if (temp_al_pt == end_tranche) 
                                break;
                        }
                        
                        mu = maximum_mu;
                        //                post("  mu = %f", mu);
                    }
                    
                    // we respace things according to mu
                    temp_al_pt = start_tranche;
                    double curr_grace_width = 0;
                    while (temp_al_pt) { 
                        double onset_abs = rat2double(temp_al_pt->r_onset_sec) - rat2double(start_tranche->r_onset_sec);
                        double original_offset_ux = temp_al_pt->offset_ux;
//was:                        double coeff1 = onset_abs < CONST_EPSILON4 || tranche_sec_dur < CONST_EPSILON1 ? 0 : onset_abs/tranche_sec_dur;
                        double coeff1 = tranche_sec_dur < CONST_EPSILON1 ? 0 : onset_abs/tranche_sec_dur;
                        
                        temp_al_pt->offset_ux = start_tranche->offset_ux + mu * coeff1 * (width - grace_width) + (1 - mu) * tranche_width_no_graces_minwidth_no_graces_ratio * (original_offset_ux - start_tranche->offset_ux) + curr_grace_width;
                        
                        if (temp_al_pt->next)
                            curr_grace_width += temp_al_pt->next->left_uext_due_to_grace_chords;
                        
                        //                post("  . al_pt offset x : %f", temp_al_pt->offset_ux);
                        if (temp_al_pt == end_tranche) {
                            end_shift = temp_al_pt->offset_ux - original_offset_ux;
                            break; 
                        }
                        
                        temp_al_pt_prev = temp_al_pt;
                        temp_al_pt = temp_al_pt->next;
                    }
                    
                    if (temp_al_pt && !temp_al_pt->next)
                        tpt->width_ux = temp_al_pt->offset_ux; // update tpt width (useful for updating last measure width, later on) //al_pt //firstalignmentpoint
                    
                    // we gotta shift all the following tranches
                    if (end_tranche) {
                        temp_al_pt = end_tranche->next;
                        while (temp_al_pt) {
                            temp_al_pt->offset_ux += end_shift;
                            temp_al_pt = temp_al_pt->next;
                        }
                    }
                }
            }
            
        }
        
        tpt->width_ux = lastalignmentpoint ? lastalignmentpoint->offset_ux : 0;
        tpt->fixed_barline_ts_uwidth = tpt->width_ux - all_tranches_width;
        
        if (tpt->width_ux == 0 && lastalignmentpoint)
            tpt->width_ux = lastalignmentpoint->offset_ux = tpt->local_spacing_width_multiplier * x->r_ob.minimum_uwidth_for_measure;
        else if (tpt->width_ux < tpt->local_spacing_width_multiplier * x->r_ob.minimum_uwidth_for_measure && x->r_ob.notation_cursor.measure && 
                x->r_ob.notation_cursor.measure->tuttipoint_reference == tpt && lastalignmentpoint)
            tpt->width_ux = lastalignmentpoint->offset_ux = tpt->local_spacing_width_multiplier * x->r_ob.minimum_uwidth_for_measure;

        
        //    post("tpt_fixedwidth: %f", tpt->fixed_barline_ts_uwidth);
        //    post("tpt_width: %f", tpt->width);
        
        
        
        // reassign alignmentpoints offsets to the aligned elements
        al_pt = firstalignmentpoint;
        while (al_pt) {
            for (i = 0; i < al_pt->num_aligned_obj; i++) {
                if (al_pt->aligned_obj[i]) {
                    if (al_pt->aligned_obj[i]->type == k_CHORD) {
                        t_chord *temp_grace;
                        double cursor;
                        
                        chord = ((t_chord *)al_pt->aligned_obj[i]);
                        chord->alignment_ux = al_pt->offset_ux;
                        if (chord->r_sym_duration.r_num >= 0) { // it's a real chord
                            double notehead_uwidth = chord_get_mainside_notehead_uwidth((t_notation_obj *) x, chord->figure, chord);
                            if (rat_rat_cmp(chord->figure, long2rat(1)) >= 0)
                                chord->stem_offset_ux = al_pt->offset_ux + chord->direction * notehead_uwidth / 2.;
                            else if (chord->direction == 1)
                                chord->stem_offset_ux = al_pt->offset_ux + notehead_uwidth / 2.;
                            else
                                chord->stem_offset_ux = al_pt->offset_ux - notehead_uwidth / 2.;
                        } else { // it's a rest
                            chord->stem_offset_ux = al_pt->offset_ux;
                        }
                        
                        // grace chords
                        cursor = chord->stem_offset_ux - chord->left_uextension - CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                        for (temp_grace = chord->prev; temp_grace && temp_grace->is_grace_chord; temp_grace = temp_grace->prev){
                            double add = (temp_grace == chord->prev && temp_grace->direction == 1 && chord->direction == -1) ? CONST_SCORE_ADD_GRACE_USPACE_FOR_STEMS : 0;
                            temp_grace->stem_offset_ux = temp_grace->alignment_ux = cursor - MAX(temp_grace->right_uextension + add + has_chord_at_least_one_tie(temp_grace) * CONST_SCORE_TIE_ADDITIONAL_USPACING, CONST_SCORE_MIN_USPACE_BETWEEN_GRACE_CHORDS);
                            cursor = temp_grace->stem_offset_ux - temp_grace->left_uextension - CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                        }
                    } else if (al_pt->aligned_obj[i]->type == k_TEMPO) {
                        ((t_tempo *)al_pt->aligned_obj[i])->tuttipoint_offset_ux = al_pt->offset_ux;
                    } else if (al_pt->aligned_obj[i]->type == k_MEASURE_END_BARLINE) {
                        t_measure *meas = ((t_measure_end_barline *)al_pt->aligned_obj[i])->owner->next;
                        if (meas) { // not the last measure
                            meas->start_barline_offset_ux = al_pt->offset_ux;
                            
                            // grace chords before the measure, in this very same tuttipoint
                            t_chord *temp_grace;
                            double cursor = al_pt->offset_ux - CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                            for (temp_grace = chord_get_prev(meas->firstchord); temp_grace && temp_grace->is_grace_chord && temp_grace->parent->tuttipoint_reference == tpt; temp_grace = temp_grace->prev){
                                //                            double add = (temp_grace == chord->prev && temp_grace->direction == 1 && chord->direction == -1) ? CONST_SCORE_ADD_GRACE_USPACE_FOR_STEMS : 0; 
                                temp_grace->stem_offset_ux = temp_grace->alignment_ux = cursor - temp_grace->right_uextension - has_chord_at_least_one_tie(temp_grace) * CONST_SCORE_TIE_ADDITIONAL_USPACING;
                                cursor = temp_grace->stem_offset_ux - temp_grace->left_uextension - CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                            }
                        }
                    }
                } else 
                    dev_post("Something has not been aligned");
            }
            al_pt = al_pt->next;
        }    
        
        
        // recalculate width of all measures
        for (i = 0; i < x->r_ob.num_voices; i++) {
            t_measure *meas = tpt->measure[i];
            while (meas && (meas->tuttipoint_reference == tpt)) {
                if (meas == last_tpt_measures[i]) { // last measure
                    meas->width_ux = endmeasalignmpoints[i]->offset_ux - meas->start_barline_offset_ux;
                } else {
                    meas->width_ux = meas->next->start_barline_offset_ux - meas->start_barline_offset_ux;
                }
                meas = meas->next;
            }
        }
        
        // setting position of grace chords at the end of tuttipoints
        for (i = 0; i < x->r_ob.num_voices; i++) {
            t_chord *lastchord = ch_cursor[i];
            t_chord *lastnongracechord, *firstendinggracechord = NULL;
            t_chord *next_chord;
            double cursor;

            while (lastchord && (next_chord = chord_get_next(lastchord)) && next_chord->parent->tuttipoint_reference == tpt)
                lastchord = next_chord;
            
            lastnongracechord = lastchord;
            while (lastnongracechord && lastnongracechord->is_grace_chord) {
                firstendinggracechord = lastnongracechord;
                lastnongracechord = lastnongracechord->prev;
            }
            
            if (lastchord && x->r_ob.notation_cursor.measure && x->r_ob.notation_cursor.measure == lastchord->parent) {
                cursor = lastnongracechord ? lastnongracechord->stem_offset_ux + lastnongracechord->right_uextension : (lastchord ? lastchord->parent->start_barline_offset_ux + lastchord->parent->timesignature_spacing_uwidth + 3 * CONST_SCORE_USPACE_BEFORE_GRACE_CHORD : 0);
                for (chord = firstendinggracechord; chord; chord = chord->next) {
                    if (chord->is_grace_chord) {
                        chord->stem_offset_ux = chord->alignment_ux = cursor + chord->left_uextension;
                        cursor = chord->stem_offset_ux + chord->right_uextension + CONST_SCORE_USPACE_BEFORE_GRACE_CHORD + has_chord_at_least_one_tie(chord) * CONST_SCORE_TIE_ADDITIONAL_USPACING;
                    }
                }
            } else {
                cursor = lastchord ? lastchord->parent->start_barline_offset_ux + lastchord->parent->width_ux - CONST_SCORE_USPACE_BEFORE_GRACE_CHORD : 0; 
                for (chord = lastchord; chord && chord->parent->tuttipoint_reference == tpt; chord = chord_get_prev(chord)){
                    if (chord->is_grace_chord) {
                        chord->stem_offset_ux = chord->alignment_ux = cursor - chord->right_uextension - has_chord_at_least_one_tie(chord) * CONST_SCORE_TIE_ADDITIONAL_USPACING;
                        cursor = chord->stem_offset_ux - chord->left_uextension - CONST_SCORE_USPACE_BEFORE_GRACE_CHORD;
                    } else
                        break;
                }
            }
        }
            
        bach_freeptr(meas);
        bach_freeptr(rightlim);
        bach_freeptr(portion_of_rightlim_due_to_lyrics);
        bach_freeptr(endmeasalignmpoints);
        bach_freeptr(last_tpt_measures);
        bach_freeptr(done);
    }
    
    
    // if a measures is just a full rest measure, we align the rest at the center of the measure
    for (i = 0; i < x->r_ob.num_voices; i++) { 
        t_measure *meas = tpt->measure[i];
        while (meas && (meas->tuttipoint_reference == tpt)) {
            if (is_measure_single_whole_rest((t_notation_obj *) x, meas) && meas->firstchord){
                if (meas->prev && (meas->timesignature.numerator == meas->prev->timesignature.numerator) && (meas->timesignature.denominator == meas->prev->timesignature.denominator))
                    meas->firstchord->stem_offset_ux = meas->firstchord->alignment_ux = (meas->start_barline_offset_ux + meas->start_barline_offset_ux + meas->width_ux)/2.;
                else
                    meas->firstchord->stem_offset_ux = meas->firstchord->alignment_ux = (meas->start_barline_offset_ux + CONST_SCORE_USPACE_AFTER_START_BARLINE_WITH_TS + meas->timesignature_spacing_uwidth + meas->start_barline_offset_ux + meas->width_ux)/2.;
            }
            meas = meas->next;
        }
    }
    
    // calculate all chords duration_ux
    for (i = 0; i < x->r_ob.num_voices; i++) // cycle on the voices
        for (this_meas = tpt->measure[i]; ((tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas)); this_meas = this_meas->next) // cycle on the measures within the tuttipoin
            for (chord = this_meas->firstchord; chord; chord = chord->next) {
                if (chord->next)
                    chord->duration_ux = chord->next->stem_offset_ux - chord->stem_offset_ux - CONST_SAFETY_USEPARATION_TAIL_NEXT_OBJ * x->r_ob.zoom_x * x->r_ob.zoom_y;
                else
                    chord->duration_ux = this_meas->start_barline_offset_ux + this_meas->width_ux - chord->stem_offset_ux - CONST_SAFETY_USEPARATION_TAIL_NEXT_OBJ * x->r_ob.zoom_x * x->r_ob.zoom_y;
                
                chord_reset_slur_positions(chord);
                
            }

    ct = 0;
#ifdef CONFIGURATION_Development    
    // check the number of alignment points
    t_alignmentpoint *temp1;
    for (temp1 = firstalignmentpoint; temp1; temp1 = temp1->next)
        ct++;
    if (ct != num_align_pt) 
        dev_post("Bug: aligned pt: %ld, but freed: %ld", num_align_pt, ct);
#endif    

#ifdef BACH_SPACING_DEBUG
    dev_post("ALIGNMENT POINTS end of function");
    for (al_pt = firstalignmentpoint; al_pt; al_pt = al_pt->next) {
        dev_post(". offset_ux = %.2f, num_objs = %ld, firstobj = %ld",
                 al_pt->offset_ux, al_pt->num_aligned_obj, al_pt->num_aligned_obj ? al_pt->aligned_obj[0]->type : 0);
    }
    dev_post("---------------");
#endif
    
    
    tpt->firstalignmentpoint = firstalignmentpoint;
    tpt->lastalignmentpoint = lastalignmentpoint;
    tpt->num_alignmentpoints = num_align_pt;
    
//    tuttipoint_free_alignmentpoints(tpt);
    
    tpt->need_recompute_spacing = k_SPACING_DONT_RECALCULATE;
    
    // refresh all tuttipoints offsets
    refresh_all_tuttipoints_offset_ux(x);
    
    // checking if all measures end together
    if (tpt == x->r_ob.lasttuttipoint) {
        t_scorevoice *vc;
        double last_measure_ux = -1;
        x->r_ob.all_voices_end_together = true;
        for (vc = x->firstvoice; vc && (vc->v_ob.number < x->r_ob.num_voices); vc = vc->next){
            t_measure *lastmeas = vc->lastmeasure;
            if (!lastmeas) {
                x->r_ob.all_voices_end_together = false;
                break;
            } else if (lastmeas && lastmeas->tuttipoint_reference){ 
                if (vc == x->firstvoice)
                    last_measure_ux = lastmeas->tuttipoint_reference->offset_ux + lastmeas->start_barline_offset_ux + lastmeas->width_ux;
                if (last_measure_ux != lastmeas->tuttipoint_reference->offset_ux + lastmeas->start_barline_offset_ux + lastmeas->width_ux) {
                    x->r_ob.all_voices_end_together = false;
                    break;
                }
            }
        }
    }
}




// UNMEASURED <--> MEASURED CONVERSION FOR SCORE


void sync_marker_absolute_ms_onset(t_score *x, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_measure *meas = (t_measure *) notation_item_retrieve_from_ID((t_notation_obj *)x, marker->measure_attach_ID);
        if (meas) {
            t_timepoint tp = build_timepoint(meas->measure_number, marker->r_sym_pim_attach);
            marker->position_ms = timepoint_to_ms((t_notation_obj *)x, tp, meas->voiceparent->v_ob.number);
            if (marker->r_sym_duration.r_num >= 0) {
                double end_position = timepoint_to_ms((t_notation_obj *)x, timepoint_shift((t_notation_obj *)x, tp, build_timepoint(0, marker->r_sym_duration)), meas->voiceparent->v_ob.number);
                marker->duration_ms = end_position - marker->position_ms;
            } else {
                marker->duration_ms = 0;
            }
        } else {
            marker->position_ms = 0;
            marker->duration_ms = 0;
        }
    }
}

void sync_selected_markers_absolute_ms_onset(t_score *x)
{
    t_notation_item *it;
    for (it = x->r_ob.firstselecteditem; it; it = it->next_selected)
        if (it->type == k_MARKER)
            sync_marker_absolute_ms_onset(x, (t_marker *)it);
}

void sync_all_markers_absolute_ms_onset(t_score *x)
{
    t_marker *mk;
    for (mk = x->r_ob.firstmarker; mk; mk = mk->next)
        sync_marker_absolute_ms_onset(x, mk);
}




char are_all_time_signatures_synchronous_ext(t_score *x, t_scorevoice *from, t_scorevoice *to)
{
    t_scorevoice *voice, *fstvoice = from;
    t_measure *meas1, *meas2;
    
    for (voice = from->next; voice && voice->v_ob.number < x->r_ob.num_voices && voice->v_ob.number <= to->v_ob.number; voice = voice->next){
        for (meas1 = fstvoice->firstmeasure, meas2 = voice->firstmeasure; meas1 && meas2; meas1 = meas1->next, meas2 = meas2->next){
            if (!ts_are_equal(&meas1->timesignature, &meas2->timesignature))
                return false;
            if ((meas1->next && !meas2->next) || (meas2->next && !meas1->next))
                return false;
        }
        if (voice == to)
            break;
    }
    return true;
    
}

char are_all_time_signatures_synchronous(t_score *x)
{
    if (x->r_ob.num_voices < 2 || !x->firstvoice)
        return true;
    
    return are_all_time_signatures_synchronous_ext(x, x->firstvoice, scorevoice_get_nth(x, x->r_ob.num_voices - 1));
    
}

char voiceensemble_are_all_time_signatures_synchronous(t_score *x, t_voice *any_voice_in_voiceensemble)
{
    if (!any_voice_in_voiceensemble || voiceensemble_get_numparts((t_notation_obj *)x, any_voice_in_voiceensemble) < 1)
        return true;
    
    return are_all_time_signatures_synchronous_ext(x, (t_scorevoice *)voiceensemble_get_firstvoice((t_notation_obj *)x, any_voice_in_voiceensemble), (t_scorevoice *)voiceensemble_get_lastvoice((t_notation_obj *)x, any_voice_in_voiceensemble));
}
    

char are_all_tempi_synchronous_ext(t_score *x, t_scorevoice *from, t_scorevoice *to)
{
    t_scorevoice *voice, *fstvoice = (t_scorevoice *)from;
    t_measure *meas1, *meas2;
    t_tempo *tempo1, *tempo2;
    
    for (voice = from->next; voice && voice->v_ob.number < x->r_ob.num_voices && voice->v_ob.number <= to->v_ob.number; voice = voice->next){
        for (meas1 = fstvoice->firstmeasure, meas2 = voice->firstmeasure; meas1 && meas2; meas1 = meas1->next, meas2 = meas2->next){
            for (tempo1 = meas1->firsttempo, tempo2 = meas2->firsttempo; tempo1 || tempo2; tempo1 = tempo1 ? tempo1->next : NULL, tempo2 = tempo2 ? tempo2->next : NULL){
                if (!(tempo1 && tempo2))
                    return false;
                if (!are_tempi_the_same_and_in_the_same_tp(tempo1, tempo2))
                    return false;
            }
        }
        if (voice == to)
            break;
    }
    return true;
}

char are_all_tempi_synchronous(t_score *x)
{
    if (x->r_ob.num_voices < 2 || !x->firstvoice)
        return true;

    return are_all_tempi_synchronous_ext(x, x->firstvoice, scorevoice_get_nth(x, x->r_ob.num_voices - 1));
}
    
    
char voiceensemble_are_all_tempi_synchronous(t_score *x, t_voice *any_voice_in_voiceensemble)
{
    if (!any_voice_in_voiceensemble || voiceensemble_get_numparts((t_notation_obj *)x, any_voice_in_voiceensemble) < 1)
        return true;
    
    return are_all_tempi_synchronous_ext(x, (t_scorevoice *)voiceensemble_get_firstvoice((t_notation_obj *)x, any_voice_in_voiceensemble), (t_scorevoice *)voiceensemble_get_lastvoice((t_notation_obj *)x, any_voice_in_voiceensemble));
}
    
    
char are_all_measureinfo_synchronous(t_score *x)
{
    return (are_all_time_signatures_synchronous(x) && are_all_tempi_synchronous(x));
}

    

char voiceensemble_are_all_measureinfo_synchronous(t_score *x, t_voice *any_voice_in_voiceensemble)
{
    
    return (voiceensemble_are_all_time_signatures_synchronous(x, any_voice_in_voiceensemble) && voiceensemble_are_all_tempi_synchronous(x, any_voice_in_voiceensemble));
}


    
double chord_get_spacing_correction_for_voiceensembles(t_score *x, t_chord *chord, double *accidental_ushift)
{
    if (accidental_ushift)
        *accidental_ushift = 0;

    if (!chord || !chord->parent || !chord->parent->voiceparent)
        return 0;
    
    t_measure *measure = chord->parent;
    t_voice *voice = (t_voice *)measure->voiceparent;

    if (voiceensemble_get_numparts((t_notation_obj *)x, voice) <= 1)
        return 0;
    
    if (voice->part_index % 2 != 0)
        return 0; // only even parts are shifted
    
    t_voice *first = voiceensemble_get_firstvoice((t_notation_obj *)x, voice);
    t_voice *last = voiceensemble_get_lastvoice((t_notation_obj *)x, voice);
    
    if (first == last)
        return 0; // at this point should never happen, but let's take some precautions...
    
    t_note *note;
    t_voice *v;
    long measure_num = measure->measure_number;
    double shift = 0;
    double acc_shift_for_note = 0, acc_shift_for_acc = 0;
    
    for (note = chord->firstnote; note; note = note->next) {
        long note_steps = midicents_to_diatsteps_from_middleC((t_notation_obj *)x, note_get_screen_midicents(note));
        double note_uy = scaleposition_to_uyposition((t_notation_obj *)x, note_steps, voice);
        double note_stem_ux = get_stem_x_from_alignment_point_x((t_notation_obj *)x, chord, unscaled_xposition_to_xposition((t_notation_obj *)x, chord->alignment_ux))/x->r_ob.zoom_y;
        
        // checking agains all other voiceensemble voices
        for (v = first; v && v->number < x->r_ob.num_voices; v = voice_get_next((t_notation_obj *)x, v)) {
            if (v == voice) {
                if (v == last)
                    break;
                else
                    continue;
            }
            
            if (v->part_index % 2 == voice->part_index % 2) {
                if (v == last)
                    break;
                else
                    continue;
            }
            
            t_measure *m = measure_get_nth((t_scorevoice *)v, measure_num);
            t_chord *c;
            t_note *n;
            if (!m)
                continue;
            
            for (c = m->firstchord; c; c = c->next) {
                long cmp = rat_rat_cmp(c->r_sym_onset, chord->r_sym_onset);
                if (cmp == 0) {
                    for (n = c->firstnote; n; n = n->next) {
                        long n_steps = midicents_to_diatsteps_from_middleC((t_notation_obj *)x, note_get_screen_midicents(n));

                        if (n_steps == note_steps + 1 || n_steps == note_steps || n_steps == note_steps - 1) {
                            shift = MAX(shift, notehead_get_uwidth((t_notation_obj *)x, c->r_sym_duration, n, true));
                        }
                        
                        acc_shift_for_note = shift;
                        if (n->show_accidental && note->show_accidental) {
                            double n_uy = scaleposition_to_uyposition((t_notation_obj *)x, n_steps, v);
                            double n_top = note_get_accidental_top_uextension((t_notation_obj *)x, n);
                            double n_bottom = note_get_accidental_top_uextension((t_notation_obj *)x, n);
                            double note_top = note_get_accidental_top_uextension((t_notation_obj *)x, note);
                            double note_bottom = note_get_accidental_top_uextension((t_notation_obj *)x, note);
                            if (!((n_uy - n_top < note_uy + note_bottom && n_uy + n_bottom < note_uy - note_top) ||
                                (n_uy - n_top > note_uy + note_bottom && n_uy + n_bottom > note_uy - note_top))) {
                                    acc_shift_for_acc = MAX(acc_shift_for_acc, -n->accidental_stem_delta_ux + CONST_UX_ACC_SEPARATION_FROM_NOTE);
                            }
                        }
                    }
                } else if (cmp > 0)
                    break;
            }
            
            if (v == last)
                break;
        }
    }
    
    if (accidental_ushift)
        *accidental_ushift = -acc_shift_for_note - acc_shift_for_acc;

    
    return shift;
}
    
    
void correct_measure_spacing_for_voiceensembles(t_score *x, t_measure *measure)
{
    t_chord *chord;
    t_note *note;
    
    for (chord = measure->firstchord; chord; chord = chord->next) {
        double accshift = 0;
        double shift = chord_get_spacing_correction_for_voiceensembles(x, chord, &accshift);
        chord->alignment_ux += shift;
        chord->stem_offset_ux += shift;
        for (note = chord->firstnote; note; note = note->next)
            note->accidental_stem_delta_ux += accshift;
    }
}
    
void tuttipoint_correct_spacing_for_voiceensembles(t_score *x, t_tuttipoint *tpt)
{
    t_voice *voice;
    for (voice = x->r_ob.firstvoice; voice && voice->number < x->r_ob.num_voices; voice = voice_get_next((t_notation_obj *)x, voice)) {
        long i = voice->number;
        if (voiceensemble_get_numparts((t_notation_obj *)x, voice) > 1) {
            t_measure *this_meas;
            for (this_meas = tpt->measure[i]; (tpt->next && this_meas != tpt->next->measure[i]) || (!tpt->next && this_meas); this_meas = this_meas->next) {
                if (voice->part_index % 2 == 0)  // we only (possibly) shift the notes' in even voices
                    correct_measure_spacing_for_voiceensembles(x, this_meas);
            }
        }
    }
}
    
//beaming_calculation_flags is a combination of the e_beaming_calculation_flags
void perform_analysis_and_change(t_score *x, t_jfont *jf_lyrics_nozoom, t_jfont *jf_dynamics_nozoom, t_jfont *jf_dynamics_roman_nozoom, long beaming_calculation_flags)
{
    t_scorevoice *tmp_voice; t_measure *tmp_meas; t_chord *tmp_chord;
    t_tuttipoint *tmp_pt;
    char need_free_jf_lyrics_nozoom_ok, need_free_jf_dynamics_nozoom_ok, need_free_jf_dynamics_roman_nozoom_ok;
    char recomputed_beamings = false;
    t_jfont *jf_lyrics_nozoom_ok, *jf_dynamics_nozoom_ok, *jf_dynamics_roman_nozoom_ok;

    if (jf_lyrics_nozoom) {
        need_free_jf_lyrics_nozoom_ok = false;
        jf_lyrics_nozoom_ok = jf_lyrics_nozoom;
    } else {
        need_free_jf_lyrics_nozoom_ok = true;
        jf_lyrics_nozoom_ok = jfont_create_debug(x->r_ob.lyrics_font ? x->r_ob.lyrics_font->s_name : "Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.lyrics_font_size);
    }

    if (jf_dynamics_nozoom) {
        need_free_jf_dynamics_nozoom_ok = false;
        jf_dynamics_nozoom_ok = jf_dynamics_nozoom;
    } else {
        need_free_jf_dynamics_nozoom_ok = true;
        jf_dynamics_nozoom_ok = jfont_create_debug("November for bach", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.dynamics_font_size);
    }

    if (jf_dynamics_roman_nozoom) {
        need_free_jf_dynamics_roman_nozoom_ok = false;
        jf_dynamics_roman_nozoom_ok = jf_dynamics_roman_nozoom;
    } else {
        need_free_jf_dynamics_roman_nozoom_ok = true;
        jf_dynamics_roman_nozoom_ok = jfont_create_debug("Times New Roman", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.dynamics_roman_font_size);
    }

    for (tmp_voice = x->firstvoice; tmp_voice && (tmp_voice->v_ob.number < x->r_ob.num_voices); tmp_voice = tmp_voice->next) {
        char is_in_voiceensemble = (voiceensemble_get_numparts((t_notation_obj *)x, (t_voice *)tmp_voice) > 1);
        for (tmp_meas = tmp_voice->firstmeasure; tmp_meas; tmp_meas = tmp_meas->next) {
            
            recomputed_beamings = false;
            
            verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);
            if ((beaming_calculation_flags == k_BEAMING_CALCULATION_DO || beaming_calculation_flags == k_BEAMING_CALCULATION_DO_AND_OVERFLOW_TO_NEXT) && (tmp_meas->beaming_calculation_flags == k_BEAMING_CALCULATION_DO || tmp_meas->beaming_calculation_flags == k_BEAMING_CALCULATION_DO_AND_OVERFLOW_TO_NEXT)) {

                // check if there are chords with no tree reference (they should be at the end).
                // in this case, either we delete them...
                check_for_chords_with_no_rhythmic_tree_leaf((t_notation_obj *)x, tmp_meas);                

                // need to set default beaming/ties trees?
                if (!tmp_meas->rhythmic_tree)
                    set_measure_plain_rhythmic_tree(tmp_meas);
            }
            verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

            set_grace_flag_to_chords_from_rhythmic_tree((t_notation_obj *) x, tmp_meas->rhythmic_tree);
            // was: && x->r_ob.notation_cursor.measure != tmp_meas
            if (tmp_meas->need_check_autocompletion && !(beaming_calculation_flags & k_BEAMING_CALCULATION_DONT_AUTOCOMPLETE) && (tmp_meas->beaming_calculation_flags == k_BEAMING_CALCULATION_DO || tmp_meas->beaming_calculation_flags == k_BEAMING_CALCULATION_DO_AND_OVERFLOW_TO_NEXT)) {
                // we check the overflowing/autocompletion for each measure
                check_measure_autocompletion(x, tmp_meas);
                tmp_meas->need_check_autocompletion = false;
            }
            
            verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0); // x->r_ob
    
            if (tmp_meas->need_recompute_beamings) { 
                recomputed_beamings = true;

                // We compute the approximation for each note. This must be done BEFORE check_measure_ties() is called, so that the ties can be checked
                // when there's already the correct screen_midicent values
                compute_note_approximations_for_measure((t_notation_obj *)x, tmp_meas, true);
            }
            
            if (tmp_meas->need_check_ties) { 
                // we validate the accidentals, choosing the ones to be shown, and the ones to be hidden
                validate_accidentals_for_measure((t_notation_obj *) x, tmp_meas);
                
                // we check the ties in the measure, by substituting to all WHITENULL-ed <tie_to> note fields, the proper note to which the note is tied.
                check_measure_ties((t_notation_obj *) x, tmp_meas, x->r_ob.tie_assign_pitch, 1);
                
                // we don't unset the need_check_ties flag, since we'll have to check them again, after beaming computation
            }
            verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

            if (recomputed_beamings) {
                
                // We check the show/hide accidentals options. We have to compute the note screen values (inside, via note_compute_approximation()).
                validate_accidentals_for_measure((t_notation_obj *)x, tmp_meas);
                
                llll_check(tmp_meas->rhythmic_tree);
                
                // We start recompute the beamings by using the tree information
                process_rhythmic_tree((t_notation_obj *) x, tmp_meas,
                                      (beaming_calculation_flags | tmp_meas->beaming_calculation_flags) & ~k_BEAMING_CALCULATION_DONT_AUTOCOMPLETE);

                // We re-compute the approximation for each note (rhythmic trees might have created/destroyed chords)
                compute_note_approximations_for_measure((t_notation_obj *)x, tmp_meas, true);
                validate_accidentals_for_measure((t_notation_obj *)x, tmp_meas);
                
                // we don't unset the need_recompute_beamings flag, since we have the actual beaming building task to perform!
                
            } else if (tmp_meas->need_recompute_beams_positions) {
                
                // We compute the approximation for each note.
                compute_note_approximations_for_measure((t_notation_obj *) x, tmp_meas, true);
                
                decide_beaming_direction((t_notation_obj *) x, tmp_meas);
                
                llll_funall(tmp_meas->rhythmic_tree, decide_tuplet_direction_for_level_fn, &is_in_voiceensemble, 1, -2, FUNALL_SKIP_ATOMS);
                
                validate_accidentals_for_measure((t_notation_obj *)x, tmp_meas);
                
                calculate_chords_and_tempi_measure_onsets((t_notation_obj *)x, tmp_meas);
                
                // we don't unset the need_recompute_beams_position flag, since we have a step2 to perform!
            }
            verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);
        }
    }
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

    for (tmp_voice = x->firstvoice; (tmp_voice && (tmp_voice->v_ob.number < x->r_ob.num_voices)); tmp_voice = tmp_voice->next)
        for (tmp_meas = tmp_voice->firstmeasure; tmp_meas; tmp_meas = tmp_meas->next) {
            for (tmp_chord = tmp_meas->firstchord; tmp_chord; tmp_chord = tmp_chord->next) {
                if (tmp_chord->need_recompute_parameters) { // we have to recalculate chord parameters 
                    
                    // we assign the lyrics to each chord (if needed)
                    assign_chord_lyrics((t_notation_obj *) x, tmp_chord, jf_lyrics_nozoom_ok);
                    chord_assign_dynamics((t_notation_obj *) x, tmp_chord, jf_dynamics_nozoom_ok, jf_dynamics_roman_nozoom_ok);

                    // we recalculate the chord parameters
                    calculate_chord_parameters((t_notation_obj *) x, tmp_chord, get_voice_clef((t_notation_obj *)x, (t_voice *)tmp_voice), true);
                    tmp_chord->need_recompute_parameters = false;
                }
            }

            if (tmp_meas->need_check_ties) {
                // "need check ties" again!: gotta do that twice if something has been changed in recompute beamings...
                check_measure_ties((t_notation_obj *) x, tmp_meas, x->r_ob.tie_assign_pitch, 1);
                
                // and we validate accidentals again (ties might have changed something)
                validate_accidentals_for_measure((t_notation_obj *) x, tmp_meas);
                tmp_meas->need_check_ties = false;
            } 
        }
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

    // Then we get to the spacing computation:
    
    if (x->r_ob.need_recompute_tuttipoints) {
        // we clear and recompute all tuttipoints
        calculate_tuttipoints(x);
        x->r_ob.need_recompute_tuttipoints = false;
    }    
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

    if (x->r_ob.need_reassign_local_spacing) {
        // we assign the local spacing parameters starting from the measure local spacing flags
        assign_local_spacing_from_measure_parameters(x);
        x->r_ob.need_reassign_local_spacing = false;
    }

    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);
    
    if (x->r_ob.need_recompute_chords_double_onset) {
        // we recompute the chord and tempi onsets in double precision (used for play)
        // (BTW: this is not the best way to go... should just recompute when the chord is changed)
        calculate_all_chords_remaining_onsets(x); 
        calculate_all_tempi_remaining_onsets(x); 
        x->r_ob.need_recompute_chords_double_onset = false;
    }
    
    check_tempi(x); // decide whether we should hide some tempi
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);
#ifdef CONFIGURATION_Development
    for (tmp_voice = x->firstvoice; tmp_voice && (tmp_voice->v_ob.number < x->r_ob.num_voices); tmp_voice = tmp_voice->next) { 
        for (tmp_meas = tmp_voice->firstmeasure; tmp_meas; tmp_meas = tmp_meas->next) {
            if (!tmp_meas->tuttipoint_reference) {
//                char foo = 4;
                dev_post("Bug! There's a measure with no tuttipoint reference!");
            }
        }
    }
#endif

    for (tmp_pt = x->r_ob.firsttuttipoint; tmp_pt; tmp_pt = tmp_pt->next) 
        if (tmp_pt->need_recompute_spacing == k_SPACING_RECALCULATE) {
            // and then we get to the real spacing computation for each tuttipoint
                        
            // checking if measures are empty
            t_measure *this_meas;
            long i;
            for (i = 0; i < x->r_ob.num_voices; i++)
                for (this_meas = tmp_pt->measure[i]; (tmp_pt->next && this_meas != tmp_pt->next->measure[i]) || (!tmp_pt->next && this_meas); this_meas = this_meas->next) {
                    if (is_measure_empty((t_notation_obj *)x, this_meas) && x->r_ob.notation_cursor.measure != this_meas &&
                        rat_rat_cmp(measure_get_content_sym_duration(this_meas), measure_get_sym_duration(this_meas)) == 0 &&
                        !this_meas->lock_rhythmic_tree &&
                        x->r_ob.tree_handling != k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED) {
                        verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);
                        turn_measure_into_single_rest(x, this_meas);
                        verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);
                    }
                }
            
            tuttipoint_calculate_spacing(x, tmp_pt);
            tuttipoint_correct_spacing_for_voiceensembles(x, tmp_pt);
            tmp_pt->need_recompute_spacing = k_SPACING_DONT_RECALCULATE;
            
        } else if (tmp_pt->need_recompute_spacing == k_SPACING_REFINE_ONLY) {
            // These three lines are completely unused
            tuttipoint_refine_spacing(x, tmp_pt);
            tuttipoint_correct_spacing_for_voiceensembles(x, tmp_pt);
            tmp_pt->need_recompute_spacing = k_SPACING_DONT_RECALCULATE;
        }
    
    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

    for (tmp_voice = x->firstvoice; (tmp_voice && (tmp_voice->v_ob.number < x->r_ob.num_voices)); tmp_voice = tmp_voice->next) 
        for (tmp_meas = tmp_voice->firstmeasure; tmp_meas; tmp_meas = tmp_meas->next) {
            if (tmp_meas->need_recompute_beamings || tmp_meas->need_recompute_beams_positions) { // step 02 is performed also if we only need to recompute the beaming positions
                build_beams_structures((t_notation_obj *) x, tmp_meas);
                tmp_meas->need_recompute_beamings = false;
                tmp_meas->need_recompute_beams_positions = false;
            }
        }
    
    sync_loop_ms_with_loop_tp(x);
    update_hscrollbar((t_notation_obj *) x, 2);

    verbose_post_rhythmic_tree((t_notation_obj *) x, x->firstvoice->firstmeasure, NULL, 0);

    x->r_ob.need_perform_analysis_and_change = false;
    
    if (need_free_jf_lyrics_nozoom_ok)
        jfont_destroy_debug(jf_lyrics_nozoom_ok);
    if (need_free_jf_dynamics_nozoom_ok)
        jfont_destroy_debug(jf_dynamics_nozoom_ok);
    if (need_free_jf_dynamics_roman_nozoom_ok)
        jfont_destroy_debug(jf_dynamics_roman_nozoom_ok);

//    notationobj_check_force((t_notation_obj *)x, false);

    // to do: here we'll need to recompute chord topmost_y and bottommost_y (and NOT inside the following loops)
    // to do: here we'll need to recompute beaming_graphics (and NOT inside the following loops)
    // to do: here we'll need to recompute tuplet_graphics (and NOT inside the following loops)
}


void set_all_tempi_unhidden(t_score *x){
    // set all tempi not hidden
    t_scorevoice *tmp_voice;
    t_measure *tmp_meas; t_tempo *tmp_tempo;
    for (tmp_voice = x->firstvoice; (tmp_voice && (tmp_voice->v_ob.number < x->r_ob.num_voices)); tmp_voice = tmp_voice->next)
        for (tmp_meas = tmp_voice->firstmeasure; tmp_meas; tmp_meas = tmp_meas->next)
            for (tmp_tempo = tmp_meas->firsttempo; tmp_tempo; tmp_tempo = tmp_tempo->next)
                tmp_tempo->hidden = false;
}

// decide whether some tempi have to be hidden or not
void check_tempi(t_score *x)
{
    set_all_tempi_unhidden(x);

    if (x->r_ob.hide_tempi_when_equal_on_all_voices && x->r_ob.num_voices > 0) {
        t_measure *tmp_meas; t_tempo *tmp_tempo;
        t_tempo *found_tempi[CONST_MAX_VOICES];
        t_scorevoice *tmp_voice;
        char all_measureinfo_sync = are_all_measureinfo_synchronous(x);
        
        for (tmp_meas = x->firstvoice->firstmeasure; tmp_meas; tmp_meas = tmp_meas->next)
            for (tmp_tempo = tmp_meas->firsttempo; tmp_tempo; tmp_tempo = tmp_tempo->next) {
                char all_found = true;
                for (tmp_voice = x->firstvoice->next; (tmp_voice && (tmp_voice->v_ob.number < x->r_ob.num_voices)); tmp_voice = tmp_voice->next){
                    t_measure *meas2 = NULL;
                    char found = false;
                    t_tempo *tmp3 = NULL;

                    if (all_measureinfo_sync) {
                        // easy case
                        meas2 = measure_get_nth(tmp_voice, tmp_meas->measure_number);
                        if (!meas2) {
                            found_tempi[CLAMP(tmp_voice->v_ob.number, 0, CONST_MAX_VOICES - 1)] = NULL;
                            all_found = false;
                            break;
                        }

                        for (tmp3 = meas2->firsttempo; tmp3; tmp3 = tmp3->next){
                            if (are_tempi_the_same_and_in_the_same_tp(tmp_tempo, tmp3)) {
                                found = true;
                                found_tempi[CLAMP(tmp_voice->v_ob.number, 0, CONST_MAX_VOICES - 1)] = tmp3;
                                break;
                            }
                        }

                    } else {
                        // hard case.
                        for (tmp3 = tempo_get_first(tmp_voice); tmp3; tmp3 = tempo_get_next(tmp3)) {
                            if (are_tempi_the_same_and_with_the_same_onset(tmp_tempo, tmp3)) {
                                found = true;
                                found_tempi[CLAMP(tmp_voice->v_ob.number, 0, CONST_MAX_VOICES - 1)] = tmp3;
                                break;
                            }
                        }
                    }
                    
                    
                    if (found && tmp3) {
                        t_tempo *prev = tempo_get_prev(tmp3);
                        if (prev && !prev->hidden && prev->interpolation_type != 0 && rat_rat_cmp(prev->tempo_value, tmp3->tempo_value) != 0) {
                            // the previous tempo was different for this voice, and had an interpolation to this tempo.
                            // Hence We can't hide this tempo.
                            all_found = false;
                        }
                    }
                    
                    if (!found) {
                        all_found = false;
                        break;
                    }
                    
                }
                if (all_found) {
                    t_voice *firstvisible = voice_get_first_visible((t_notation_obj *)x);
                    if (firstvisible) {
                        char must_hide = true;
                        long interp = tmp_tempo->interpolation_type;
                        
                        if (interp) {
                            t_tempo *pivot = tempo_get_next(tmp_tempo);
                            if (pivot) {
                                for (long i = firstvisible->number + 1; i < x->r_ob.num_voices; i++) {
                                    if (!are_tempi_the_same_and_with_the_same_onset(tempo_get_next(found_tempi[i]), pivot)) {
                                        must_hide = false;
                                        break;
                                    }
                                }
                            }
                        }
                        
                        if (must_hide) {
                            for (long i = firstvisible->number + 1; i < x->r_ob.num_voices; i++)
                                if (found_tempi[i])
                                    found_tempi[i]->hidden = true;
                        }
                    }
                }
            }
    }
}


t_llll *get_score_values_as_llll_for_undo(t_score *x, e_header_elems dump_what, char also_lock_general_mutex)
{
    return get_score_values_as_llll(x, k_CONSIDER_FOR_UNDO, dump_what, true, true, also_lock_general_mutex, true);
}
    
// getwhat is one of the e_data_considering_types
t_llll* get_score_values_as_llll(t_score *x, e_data_considering_types for_what, e_header_elems dump_what, char tree, char also_get_level_information, char also_lock_general_mutex, char explicitly_get_also_default_stuff, t_symbol *router) // char get_clefs, char get_keys, char get_markers, char get_slotinfo, char get_commands, char get_midichannels)
{
    // get all the information concerning the score and put it in a llll
    
    // the output is given as a long text-like llll formatted as
    // score (slotinfo ( INFOSLOT ) ( INFOSLOT ) ( INFOSLOT ) ...) (commands ( CMD ) ( CMD ) ... ) (midichannels ch1 ch2 ch3 ...)   (   SCOREVOICE  1   )    (   SCOREVOICE  2  ) 
    //
    // each ( SCOREVOICE ) has the form ( ( MEASURE 1 ) ( MEASURE 2 ) ... flag ) 
    // each ( MEASURE ) has the form ( ( ( TIME_SIGNATURE ) ( TEMPO ) )   ( r_sym_duration ( NOTE1 ) ( NOTE2 ) ( NOTE3 ) ... (articulations ...) locked?) ( r_sym_duration ( NOTE1 ) ( NOTE2 ) ( NOTE3 ) ... locked?) ...  meas_locked?)
    //                                                                                        C H O R D   1                                          C H O R D   2
    //
    // each ch1, ch2, ch3... refears to the midichannels of the SCOREVOICE1, SCOREVOICE2, SCOREVOICE3...
    //
    // each ( INFOSLOT ) has the form   
    // (slotnumber slotname slottype slotmin slotmax optional:slotkey)
    //
    // each ( CMD ) has the form   
    // (commandnumber command_for_notes command_for_chords commandkey)
    //
    // each ( NOTE# ) has the form 
    // ( midicents velocity tie
    //              ( graphic screen_midicents  screen_accidental )
    //              ( breakpoints  (ms1 mc1 slope1) (ms2 mc2 slope2) (ms3 mc3 slope3)...)
    //              ( slots (slot# SLOT_VALUES) (slot# SLOT2_VALUES) ...)
    // )
    //
    // where graphic, breakpoints and slot are called extras, so the form is more of a ( midicents duration velocity EXTRA1 EXTRA2 EXTRA3 ), and all the EXTRAS are optional 
    //
    // where each SLOT#_VALUES has the form
    //                    if slottype = "function":    (x1 y1 slope1) (x2 y2 slope2) (x3 y3 slope3)...
    //                    if slottype = "long" or "double": number
    //                    if slottype = "text", we have as arguments: "array_of_characters"
    //                    if slottype = "filelist", we have as arguments:  "filepath1" "filepath2" ...  "lastfilepath" active_file#
    //
    // if flags == 1, we also send the clefs info within the header, as (clefs CLEF1 CLEF2 ... CLEF_N)
    
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    
    llll_appendsym(out_llll, router ? router : _llllobj_sym_score, 0, WHITENULL_llll); // "score" message
    
    if (also_lock_general_mutex)
        lock_general_mutex((t_notation_obj *)x);    
    
    llll_chain(out_llll, get_notationobj_header_as_llll((t_notation_obj *)x, dump_what, false, explicitly_get_also_default_stuff, for_what == k_CONSIDER_FOR_UNDO, for_what));

    if (dump_what & k_HEADER_BODY) {
        voice = x->firstvoice;
        while (voice && (voice->v_ob.number < x->r_ob.num_voices)) { // append chord lllls
            llll_appendllll(out_llll, get_scorevoice_values_as_llll(x, voice, for_what, tree, also_get_level_information), 0, WHITENULL_llll);    
            voice = voice->next;
        }
    }
    
    if (also_lock_general_mutex)
        unlock_general_mutex((t_notation_obj *)x);    
    
    return out_llll;
}

t_llll* get_subvoice_values_as_llll(t_score *x, t_scorevoice *voice, long start_meas, long end_meas, char tree, char also_get_level_information)
{
    t_llll* out_llll = llll_get();
    
    // do we need to add a tempo at the beginning?
    t_tempo *tempotoadd = NULL;
    t_tempo tempocopy;
    t_measure *startmeas = measure_get_nth(voice, start_meas);
    t_measure *temp_meas = startmeas;
    if (startmeas && (!startmeas->firsttempo || rat_long_cmp(startmeas->firsttempo->changepoint, 0) > 0)) {
        tempotoadd = voice_get_first_tempo((t_notation_obj *)x, (t_voice *)voice);
        if (tempotoadd && tempotoadd->owner && tempotoadd->owner->measure_number >= start_meas)
            tempotoadd = NULL;
        t_tempo *nexttempo = tempotoadd ? tempo_get_next(tempotoadd) : NULL;
        while (nexttempo && nexttempo->owner->measure_number < start_meas) {
            tempotoadd = nexttempo;
            nexttempo = tempo_get_next(nexttempo);
        }
        if (tempotoadd)
            tempocopy = *tempotoadd;
        if (tempotoadd && tempotoadd->interpolation_type != 0) {
            get_tempo_at_timepoint((t_notation_obj *)x, voice, build_timepoint(start_meas, long2rat(0)), &tempocopy.figure_tempo_value, &tempocopy.tempo_figure, &tempocopy.tempo_value, &tempocopy.interpolation_type);
        }
    }
    
    while (temp_meas) { // append measure lllls
        if ((temp_meas->measure_number >= start_meas) && (temp_meas->measure_number <= end_meas)) {
            t_llll* to_append = measure_get_values_as_llll((t_notation_obj *) x, temp_meas, k_CONSIDER_FOR_SUBDUMPING, tree, also_get_level_information, tempotoadd && temp_meas->measure_number == start_meas ? &tempocopy : NULL);
            
            llll_appendllll(out_llll, to_append);    // we append the list
        } else if (temp_meas->measure_number > start_meas)
            break;
        
        temp_meas = temp_meas->next;
    }
    return out_llll;
}



t_llll* get_scorevoice_values_as_llll(t_score *x, t_scorevoice *voice, e_data_considering_types for_what, char tree, char also_get_level_information)
{
    t_llll* out_llll = llll_get();
    t_measure *temp_meas = voice->firstmeasure;

    while (temp_meas) { // append chord lllls
        llll_appendllll(out_llll, measure_get_values_as_llll((t_notation_obj *) x, temp_meas, for_what, tree, also_get_level_information), 0, WHITENULL_llll);    
        temp_meas = temp_meas->next;
    }
    
    if (for_what != k_CONSIDER_FOR_EXPORT_OM && for_what != k_CONSIDER_FOR_EXPORT_PWGL)
        llll_append_notationitem_flag((t_notation_obj *) x, out_llll, (t_notation_item *)voice);

    if (for_what == k_CONSIDER_FOR_UNDO) 
        llll_appendllll(out_llll, get_ID_as_llll((t_notation_item *) voice), 0, WHITENULL_llll);

    return out_llll;
}


t_llll* get_all_measuresinfo_values_as_llll(t_score *x)
{
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    lock_general_mutex((t_notation_obj *)x);    
    voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        llll_appendllll(out_llll, get_voice_measuresinfo_values_as_llll(voice), 0, WHITENULL_llll);    
        voice = voice->next;
    }
    unlock_general_mutex((t_notation_obj *)x);    
    return out_llll;
}

t_llll* get_all_cents_values_as_llll(t_score *x, char tree, e_output_pitches pitch_output_mode)
{
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    lock_general_mutex((t_notation_obj *)x);    
    voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        llll_appendllll(out_llll, get_voice_cents_values_as_llll(x, voice, tree, pitch_output_mode), 0, WHITENULL_llll);
        voice = voice->next;
    }
    unlock_general_mutex((t_notation_obj *)x);    
    return out_llll;
}

t_llll* get_all_durations_values_as_llll(t_score *x, char tree)
{
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    lock_general_mutex((t_notation_obj *)x);    
    voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        llll_appendllll(out_llll, get_voice_durations_values_as_llll(x, voice, tree), 0, WHITENULL_llll);    
        voice = voice->next;
    }
    unlock_general_mutex((t_notation_obj *)x);    
    return out_llll;
}

t_llll* get_all_velocities_values_as_llll(t_score *x, char tree)
{
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    lock_general_mutex((t_notation_obj *)x);    
    voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        llll_appendllll(out_llll, get_voice_velocities_values_as_llll(voice, tree), 0, WHITENULL_llll);    
        voice = voice->next;
    }
    unlock_general_mutex((t_notation_obj *)x);    
    return out_llll;
}

t_llll* get_all_ties_values_as_llll(t_score *x, char tree)
{
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    lock_general_mutex((t_notation_obj *)x);    
    voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        llll_appendllll(out_llll, get_voice_ties_values_as_llll(voice, tree), 0, WHITENULL_llll);    
        voice = voice->next;
    }
    unlock_general_mutex((t_notation_obj *)x);    
    return out_llll;
}

t_llll* get_all_pixel_values_as_llll(t_score *x)
{
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    lock_general_mutex((t_notation_obj *)x);    
    voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
        llll_appendllll(out_llll, get_voice_pixel_values_as_llll(x, voice), 0, WHITENULL_llll);    
        voice = voice->next;
    }
    unlock_general_mutex((t_notation_obj *)x);    
    return out_llll;
}

t_llll* get_all_measure_pixel_values_as_llll(t_score *x)
{
    t_llll* out_llll = llll_get();
    t_scorevoice *voice;
    t_measure *meas;
    lock_general_mutex((t_notation_obj *)x);
    for (voice = x->firstvoice; voice && (voice->v_ob.number < x->r_ob.num_voices); voice = voice->next) {
        t_llll *voice_ll = llll_get();
        for (meas = voice->firstmeasure; meas; meas = meas->next) {
            t_llll *meas_ll = llll_get();
            t_llll *x_ll = llll_get();
            t_llll *y_ll = llll_get();
            double this_meas_pixel_start = unscaled_xposition_to_xposition((t_notation_obj *) x, meas->tuttipoint_reference->offset_ux + meas->start_barline_offset_ux);
            double this_meas_pixel_end = unscaled_xposition_to_xposition((t_notation_obj *) x, meas->tuttipoint_reference->offset_ux + meas->start_barline_offset_ux + meas->width_ux);

            llll_appenddouble(x_ll, this_meas_pixel_start);
            llll_appenddouble(x_ll, this_meas_pixel_end);
            llll_appenddouble(y_ll, get_staff_top_y((t_notation_obj *)x, (t_voice *)voice, false));
            llll_appenddouble(y_ll, get_staff_bottom_y((t_notation_obj *)x, (t_voice *)voice, false));
            llll_appendllll(meas_ll, x_ll);
            llll_appendllll(meas_ll, y_ll);
            
            llll_appendllll(voice_ll, meas_ll);
        }
        llll_appendllll(out_llll, voice_ll);
    }
    unlock_general_mutex((t_notation_obj *)x);
    return out_llll;
}

t_llll* get_voice_measuresinfo_values_as_llll(t_scorevoice *voice)
{
    t_llll* out_llll = llll_get();
    t_measure *temp_meas = voice->firstmeasure;
    while (temp_meas) { // append chord lllls
        
        t_llll* ts_tempo_llll = llll_get();
        llll_appendllll(ts_tempo_llll, get_timesignature_as_llll(&temp_meas->timesignature), 0, WHITENULL_llll);
        llll_appendllll(ts_tempo_llll, measure_get_tempi_as_llll(temp_meas), 0, WHITENULL_llll);
        if (temp_meas->end_barline->barline_type > 0 && temp_meas->end_barline->barline_type != k_BARLINE_AUTOMATIC)
            llll_appendlong(ts_tempo_llll, temp_meas->end_barline->barline_type, 0, WHITENULL_llll);
        llll_appendllll(out_llll, ts_tempo_llll, 0, WHITENULL_llll);    
        
        temp_meas = temp_meas->next;
    }
    
    return out_llll;
}

t_llll *measure_get_cents_values_as_llll(t_score *x, t_measure *measure, char tree, e_output_pitches pitch_output_mode)
{
    t_chord *temp_chord = measure->firstchord;
    t_llll* meas_llll = llll_get();
    while (temp_chord) { // append chord lllls
        t_note *temp_note = temp_chord->firstnote;
        t_llll* in_llll = llll_get();
        while (temp_note) { // append chord lllls
            note_appendpitch_to_llll_for_separate_syntax((t_notation_obj *)x, in_llll, temp_note, pitch_output_mode);
            temp_note = temp_note->next;
        }
        llll_appendllll(meas_llll, in_llll, 0, WHITENULL_llll);    
        temp_chord = temp_chord->next;
    }
    if (tree)
        llll_reshape(meas_llll, measure->rhythmic_tree, ignore_l_thing_fn);
    
    return meas_llll;
}

t_llll* get_voice_cents_values_as_llll(t_score *x, t_scorevoice *voice, char tree, e_output_pitches pitch_output_mode)
{
    // get all the information concerning the cents and put it in a llll
    
    // the output is given as a long text-like llll formatted as
    // (((midicents_note1   midicents_note2 ....)   (midicents_note1    midicents_note2 ....)  ...)) ( MEAS 2) (MEAS 3...)
    //              C H O R D   1                              C H O R D     2
    //                        M     E    A    S    U    R    E      1
    
    t_llll* out_llll = llll_get();
    t_measure *temp_meas = voice->firstmeasure;
    while (temp_meas) {
        t_llll* meas_llll = measure_get_cents_values_as_llll(x, temp_meas, tree, pitch_output_mode);
        llll_appendllll(out_llll, meas_llll, 0, WHITENULL_llll);    
        temp_meas = temp_meas->next;
    }
    
    return out_llll;
}

t_llll *measure_get_ties_values_as_llll(t_measure *meas, char tree){
    t_chord *temp_chord = meas->firstchord;
    t_llll* meas_llll = llll_get();
    while (temp_chord) { // append chord lllls
        t_note *temp_note = temp_chord->firstnote;
        t_llll* in_llll = llll_get();
        while (temp_note) { // append chord lllls
            llll_appendlong(in_llll, (temp_note->tie_to) ? 1 : 0, 0, WHITENULL_llll);    
            temp_note = temp_note->next;
        }
        llll_appendllll(meas_llll, in_llll, 0, WHITENULL_llll);    
        temp_chord = temp_chord->next;
    }
    return meas_llll;
}

t_llll* get_voice_ties_values_as_llll(t_scorevoice *voice, char tree)
{
    // get all the information concerning the ties and put it in a llll

    t_llll* out_llll = llll_get();
    t_measure *temp_meas = voice->firstmeasure;
    while (temp_meas) {
        t_llll* meas_llll = measure_get_ties_values_as_llll(temp_meas, tree);
        llll_appendllll(out_llll, meas_llll, 0, WHITENULL_llll);    
        temp_meas = temp_meas->next;
    }
    
    return out_llll;
}


t_llll* get_voice_durations_values_as_llll(t_score *x, t_scorevoice *voice, char tree)
{
    t_llll* out_llll = llll_get();
    t_measure *temp_meas = voice->firstmeasure;
    while (temp_meas) {
        t_llll *measllll = measure_get_durations_values_as_llll(x, temp_meas, tree);
        llll_appendllll(out_llll, measllll, 0, WHITENULL_llll);    
        temp_meas = temp_meas->next;
    }
    
    return out_llll;
}

// tree == 2 also outputs "t" for the all tied chords
t_llll* measure_get_durations_values_as_llll(t_score *x, t_measure *measure, char tree)
{
    t_llll* out_llll = llll_get();
    t_chord *temp_chord = measure->firstchord;
    while (temp_chord) { // append chord lllls
        // if we DON'T use trees, grace chords duration is output as 0 (no matter what, dudes: if you don't want to operate with trees, you just have octave grace notes!)
        llll_appendrat(out_llll, (tree == 0 && temp_chord->is_grace_chord) ? long2rat(0) : temp_chord->r_sym_duration, 0, WHITENULL_llll);    

        // adding ties, if needed to output the whole rhythmic tree
        if (tree == 2 && chord_is_all_tied_to((t_notation_obj *) x, temp_chord, false, NULL))
            llll_appendsym(out_llll, _llllobj_sym_t, 0, WHITENULL_llll);    
        
        temp_chord = temp_chord->next;
    }
    if (tree) {
        t_llll *model = measure->rhythmic_tree;
        
        if (tree == 2) {
            void *data[2];
            model = llll_clone_extended(measure->rhythmic_tree, WHITENULL_llll, 0, clone_rhythm_level_properties_fn);
            data[0] = (t_notation_obj *)x;
            data[1] = model;
            llll_funall(model, add_t_after_all_tied_chords_fn, data, 1, -1, 0);
        }
        
        llll_reshape(out_llll, model, clone_rhythm_level_properties_fn);
        
        // adding the "g" symbol in front of any grace level
//        verbose_post_rhythmic_tree((t_notation_obj *) x, measure, NULL, 2);
        llll_funall(out_llll, add_g_in_front_of_grace_levels_fn, NULL, 1, -1, FUNALL_SKIP_ATOMS);
        
        if (tree == 2)
            llll_free_freethings(model, LLLL_FREETHING_MEM);
        
        llll_free_all_l_things(out_llll);
    }
    return out_llll;
}

t_llll* measure_get_plain_chords_obj_as_llll(t_measure *measure)
{
    t_llll* out_llll = llll_get();
    t_chord *temp_chord;
    for (temp_chord = measure->firstchord; temp_chord; temp_chord = temp_chord->next)
        llll_appendobj(out_llll, temp_chord, 0, WHITENULL_llll);    
    return out_llll;
}


t_llll* measure_get_plain_ties_flags_as_llll(t_measure *measure)
{
    t_llll* out_llll = llll_get();
    t_chord *temp_chord;
    for (temp_chord = measure->firstchord; temp_chord; temp_chord = temp_chord->next){
        long num_tied_notes = get_num_tied_to_notes(temp_chord);
        if (num_tied_notes > 0 && num_tied_notes == temp_chord->num_notes)
            llll_appendllll(out_llll, prepend_all_sym_to_long(1), 0, WHITENULL_llll);    
        else if (num_tied_notes == 0 || temp_chord->num_notes == 0)
            llll_appendllll(out_llll, prepend_all_sym_to_long(0), 0, WHITENULL_llll);    
        else {
            t_llll *sub_llll = llll_get();
            t_note *nt;
            for (nt = temp_chord->firstnote; nt; nt = nt->next)
                llll_appendlong(sub_llll, nt->tie_to ? 1 : 0, 0, WHITENULL_llll);    
            llll_appendllll(out_llll, sub_llll, 0, WHITENULL_llll);    
        }
    }
    return out_llll;
}

void set_measure_plain_rhythmic_tree(t_measure *measure){
    t_chord *chord;
    t_llllelem *beam_elem;
    
    measure->rhythmic_tree = measure_get_plain_chords_obj_as_llll(measure);
    
    // assigning chord tree elems
    for (chord = measure->firstchord, beam_elem = measure->rhythmic_tree->l_head; chord; 
         chord = chord->next, beam_elem = beam_elem->l_next){
        chord->rhythmic_tree_elem = beam_elem;
    }
}


void check_for_chords_with_no_rhythmic_tree_leaf(t_notation_obj *r_ob, t_measure *measure){
    t_chord *chord = measure->firstchord;
    while (chord) {
        t_chord *nextch = chord->next;
        if (!chord->rhythmic_tree_elem){
            if (r_ob->tree_handling == k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED || r_ob->tree_handling == k_RHYTHMIC_TREE_HANDLING_REFINE_ONLY_GRAPHICALLY ||
                r_ob->tree_handling == k_RHYTHMIC_TREE_HANDLING_REFINE)
                chord_delete_from_measure(r_ob, chord, false);
            else {
                free_rhythmic_tree(r_ob, measure); 
                measure->rhythmic_tree = NULL;
            }
        }
        chord = nextch;
    }
}


t_llll* measure_get_velocities_values_as_llll(t_measure *measure, char tree)
{
    t_llll* out_llll = llll_get();
    t_chord *temp_chord = measure->firstchord;
    while (temp_chord) { // append chord lllls
        t_note *temp_note = temp_chord->firstnote;
        t_llll* in_llll = llll_get();
        while (temp_note) { // append chord lllls
            llll_appendlong(in_llll, temp_note->velocity, 0, WHITENULL_llll);    
            temp_note = temp_note->next;
        }
        llll_appendllll(out_llll, in_llll, 0, WHITENULL_llll);    
        temp_chord = temp_chord->next;
    }
    if (tree)
        llll_reshape(out_llll, measure->rhythmic_tree, ignore_l_thing_fn);
    return out_llll;
}

t_llll* get_voice_velocities_values_as_llll(t_scorevoice *voice, char tree)
{
    t_llll* out_llll = llll_get();
    t_measure *temp_meas = voice->firstmeasure;
    while (temp_meas) {
        llll_appendllll(out_llll, measure_get_velocities_values_as_llll(temp_meas, tree), 0, WHITENULL_llll);    
        temp_meas = temp_meas->next;
    }
    return out_llll;
}

t_llll* measure_get_pixel_values_as_llll(t_score *x, t_scorevoice *voice, t_measure *measure)
{
    t_llll* out_llll = llll_get();
    t_chord *temp_chord; t_note *temp_note;
    for (temp_chord = measure->firstchord; temp_chord; temp_chord = temp_chord->next) {
        t_llll *chord_llll = llll_get();
        t_llll *notes_y_pixel_pos = llll_get();
        t_llll *accidentals_x_pixel_pos = llll_get();
        double this_chord_pixel_start = unscaled_xposition_to_xposition((t_notation_obj *) x, measure->tuttipoint_reference->offset_ux + temp_chord->stem_offset_ux);
        llll_appenddouble(chord_llll, this_chord_pixel_start, 0, WHITENULL_llll); // pixel start
        if (!temp_chord->next) { // pixel duration
            double end_meas_pixel = unscaled_xposition_to_xposition((t_notation_obj *) x, measure->tuttipoint_reference->offset_ux + measure->start_barline_offset_ux + measure->width_ux);
            llll_appenddouble(chord_llll, end_meas_pixel - this_chord_pixel_start, 0, WHITENULL_llll);
        } else {
            double next_chord_pixel_start = unscaled_xposition_to_xposition((t_notation_obj *) x, measure->tuttipoint_reference->offset_ux + temp_chord->next->stem_offset_ux);
            llll_appenddouble(chord_llll, next_chord_pixel_start - this_chord_pixel_start, 0, WHITENULL_llll);
        }
        for (temp_note = temp_chord->firstnote; temp_note; temp_note = temp_note->next) { // y pixel position
            llll_appenddouble(notes_y_pixel_pos, mc_to_yposition((t_notation_obj *) x, note_get_screen_midicents(temp_note), (t_voice *) voice), 0, WHITENULL_llll);
            if (note_get_screen_accidental(temp_note).r_num != 0)
                llll_appenddouble(accidentals_x_pixel_pos, this_chord_pixel_start + temp_note->accidental_stem_delta_ux * x->r_ob.zoom_y + 
                                  x->r_ob.accidentals_typo_preferences.ux_shift * x->r_ob.zoom_y - 
                                  get_accidental_uwidth((t_notation_obj *) x, note_get_screen_accidental(temp_note), false) * x->r_ob.zoom_y, 0, WHITENULL_llll);
            else 
                llll_appenddouble(accidentals_x_pixel_pos, this_chord_pixel_start + 
                                  get_notehead_ux_shift((t_notation_obj *) x, temp_note) * x->r_ob.zoom_y + temp_note->notecenter_stem_delta_ux * x->r_ob.zoom_y -
                                  ((temp_note->notehead_uwidth / 2.) * x->r_ob.zoom_y), 0, WHITENULL_llll); 
        }
        llll_appendllll(chord_llll, notes_y_pixel_pos, 0, WHITENULL_llll);    
        llll_appendllll(chord_llll, accidentals_x_pixel_pos, 0, WHITENULL_llll);    
        llll_appendllll(out_llll, chord_llll, 0, WHITENULL_llll);    
    }
    return out_llll;
}

t_llll* get_voice_pixel_values_as_llll(t_score *x, t_scorevoice *voice)
{
    t_llll* out_llll = llll_get();
    t_measure *temp_meas;
    for (temp_meas = voice->firstmeasure; temp_meas; temp_meas = temp_meas->next)
        llll_appendllll(out_llll, measure_get_pixel_values_as_llll(x, voice, temp_meas), 0, WHITENULL_llll);    
    return out_llll;
}


t_llll* get_all_extras_values_as_llll(t_score *x, char tree)
{
    // get all the information concerning the extras and put it in a llll
    t_llll* out_llll = llll_get();
//    t_llll* graphic_llll = llll_get();
    t_llll* breakpoints_llll = llll_get();
    t_llll* slots_llll = llll_get();
    t_scorevoice *voice;
    lock_general_mutex((t_notation_obj *)x);    
//    llll_appendsym(graphic_llll, _llllobj_sym_graphic, 0, WHITENULL_llll);
    llll_appendsym(breakpoints_llll, _llllobj_sym_breakpoints, 0, WHITENULL_llll);
    llll_appendsym(slots_llll, _llllobj_sym_slots, 0, WHITENULL_llll);
    
    voice = x->firstvoice;
    while (voice && (voice->v_ob.number < x->r_ob.num_voices)) {
//        t_llll* graphic_voicellll = llll_get();
        t_llll* breakpoints_voicellll = llll_get();
        t_llll* slots_voicellll = llll_get();
        
        t_measure *temp_meas = voice->firstmeasure;
        while (temp_meas) { // append chord lllls
//            t_llll* graphic_measllll = llll_get();
            t_llll* breakpoints_measllll = llll_get();
            t_llll* slots_measllll = llll_get();
            
            t_chord *temp_chord = temp_meas->firstchord;
            while (temp_chord) { // append chord lllls
                t_note *temp_note = temp_chord->firstnote;
//                t_llll* graphic_subllll = llll_get();
                t_llll* breakpoints_subllll = llll_get();
                if (!temp_note) {
                    llll_appendllll(slots_measllll, notation_item_get_slots_values_no_header_as_llll((t_notation_obj *) x, (t_notation_item *)temp_chord, false));
                } else {
                    t_llll* slots_subllll = llll_get();
                    while (temp_note) { // append chord lllls
                        //                    llll_appendllll(graphic_subllll, note_get_graphic_values_no_router_as_llll((t_notation_obj *) x, temp_note), 0, WHITENULL_llll);
                        llll_appendllll(breakpoints_subllll, note_get_breakpoints_values_no_router_as_llll((t_notation_obj *) x, temp_note));
                        llll_appendllll(slots_subllll, note_get_slots_values_no_header_as_llll((t_notation_obj *) x, temp_note, false));
                        temp_note = temp_note->next;
                    }
                    llll_appendllll(slots_measllll, slots_subllll, 0, WHITENULL_llll);
                }
//                llll_appendllll(graphic_measllll, graphic_subllll, 0, WHITENULL_llll);
                llll_appendllll(breakpoints_measllll, breakpoints_subllll, 0, WHITENULL_llll);
                temp_chord = temp_chord->next;
            }
            
            if (tree){
//                llll_reshape(graphic_measllll, temp_meas->rhythmic_tree, ignore_l_thing_fn);
                llll_reshape(breakpoints_measllll, temp_meas->rhythmic_tree, ignore_l_thing_fn);
                llll_reshape(slots_measllll, temp_meas->rhythmic_tree, ignore_l_thing_fn);
            }
            
//            llll_appendllll(graphic_voicellll, graphic_measllll, 0, WHITENULL_llll);
            llll_appendllll(breakpoints_voicellll, breakpoints_measllll, 0, WHITENULL_llll);
            llll_appendllll(slots_voicellll, slots_measllll, 0, WHITENULL_llll);
            temp_meas = temp_meas->next;
        }
        
//        llll_appendllll(graphic_llll, graphic_voicellll, 0, WHITENULL_llll);
        llll_appendllll(breakpoints_llll, breakpoints_voicellll, 0, WHITENULL_llll);    
        llll_appendllll(slots_llll, slots_voicellll, 0, WHITENULL_llll);    
        voice = voice->next;
    }
    
//    llll_appendllll(out_llll, graphic_llll, 0, WHITENULL_llll);
    llll_appendllll(out_llll, breakpoints_llll, 0, WHITENULL_llll);    
    llll_appendllll(out_llll, slots_llll, 0, WHITENULL_llll);    
    unlock_general_mutex((t_notation_obj *)x);    
    
    return out_llll;
}


long get_average_x_position_for_level_fn(void *data, t_hatom *a, const t_llll *address){
    if (hatom_gettype(a) == H_OBJ)
        *((double *)data) += ((t_chord *)hatom_getobj(a))->stem_x;  
    return 0;
}




double get_average_x_position_for_level(t_llll *level){
    double sum = 0;
    double res = 0;
    llll_funall(level, get_average_x_position_for_level_fn, &sum, 1, -1, 0);
    
    t_llll *cloned = llll_clone_extended(level, WHITENULL_llll, 0, ignore_l_thing_fn);
    llll_flatten(cloned, 0, 0);
    res = sum/cloned->l_size;
    llll_free(cloned);
    return res;
}

t_jrgba level_type_to_color(long level_type){
    if (level_type & k_RHYTHM_LEVEL_ORIGINAL)
        return build_jrgba(0.8, 0.1, 0.1, 1);    // red
    else if (level_type & k_RHYTHM_LEVEL_TS_BOX)
        return build_jrgba(0.16, 0.47, 0.1, 1);    // green
    else if (level_type &  k_RHYTHM_LEVEL_ADDED)
        return build_jrgba(0.04, 0.17, 0.55, 1);    // blue
    else if (level_type &  k_RHYTHM_LEVEL_DISPLAY_ONLY)
        return build_jrgba(0.74, 0.43, 0.79, 1);    // violet
    else if (level_type &  k_RHYTHM_LEVEL_IGNORE)
        return build_jrgba(0.5, 0.5, 0.5, 1);    // grey
    else
        return build_jrgba(0., 0., 0., 1);        // black
}

long show_rhythmic_tree_fn(void *data, t_hatom *a, const t_llll *address){
    t_notation_obj *r_ob = (t_notation_obj *) ((void **)data)[0];
    t_jgraphics *g = (t_jgraphics *) ((void **)data)[1];
    double staff_top = *((double *) ((void **)data)[2]);
    double start_pos = *((double *) ((void **)data)[3]);
    
    char direction = (staff_top > start_pos ? 1 : -1);

    if (!address->l_size)
        return 0;

    if (hatom_gettype(a) == H_OBJ){
        t_chord *chord = (t_chord *)hatom_getobj(a);
        char is_tuplet = (chord->rhythmic_tree_elem->l_parent->l_thing.w_obj ? ((t_rhythm_level_properties *) chord->rhythmic_tree_elem->l_parent->l_thing.w_obj)->is_tuplet : 0);
        t_jrgba col = level_type_to_color(chord->rhythmic_tree_elem->l_parent->l_thing.w_obj ? ((t_rhythm_level_properties *) chord->rhythmic_tree_elem->l_parent->l_thing.w_obj)->level_type : k_RHYTHM_LEVEL_ORIGINAL);
        double x2 = get_average_x_position_for_level(chord->rhythmic_tree_elem->l_parent);
        if (!is_tuplet) {
            paint_line(g, col, chord->stem_x, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * address->l_size, x2, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * (address->l_size - 1), 1);
            paint_dashed_line(g, col, chord->stem_x, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * address->l_size, chord->stem_x, staff_top, 1, 1);
        } else {
            paint_dashed_line(g, col, chord->stem_x, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * address->l_size, x2, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * (address->l_size - 1), 1, 6);
            paint_dashed_line(g, col, chord->stem_x, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * address->l_size, chord->stem_x, staff_top, 1, 1);
        }
    } else if (hatom_gettype(a) == H_LLLL){
        t_llll *llll = hatom_getllll(a);
        char is_tuplet = (llll->l_owner->l_parent->l_thing.w_obj ? ((t_rhythm_level_properties *) llll->l_owner->l_parent->l_thing.w_obj)->is_tuplet : 0);
        t_jrgba col = level_type_to_color(llll->l_owner->l_parent->l_thing.w_obj ? ((t_rhythm_level_properties *) llll->l_owner->l_parent->l_thing.w_obj)->level_type : k_RHYTHM_LEVEL_ORIGINAL);
        double x1 = get_average_x_position_for_level(llll);
        double x2 = get_average_x_position_for_level(llll->l_owner->l_parent);
        if (!is_tuplet)
            paint_line(g, col, x1, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * address->l_size, x2, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * (address->l_size - 1), 1);
        else
            paint_dashed_line(g, col, x1, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * address->l_size, x2, start_pos + direction * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * r_ob->zoom_y * (address->l_size - 1), 1, 6);
    }
    return 0;
}

char need_to_show_ts(t_score *x, t_measure *measure)
{
    char must_show = (measure->voiceparent->v_ob.part_index == 0 && (!measure->prev || !ts_are_equal(&measure->prev->timesignature, &measure->timesignature)));
    
    if (must_show && x->r_ob.show_time_signatures == 2 && measure->voiceparent && (t_voice *)measure->voiceparent != voice_get_first_visible((t_notation_obj *)x)) {
        if (!measure->prev) {
            if (is_tuttipoint_with_same_ts((t_notation_obj *)x, measure->tuttipoint_reference))
                must_show = false;
        } else {
            if (is_barline_tuttipoint_with_same_ts((t_notation_obj *)x, measure->prev->end_barline))
                must_show = false;
        }
    }
    
    return must_show;
}

double get_linear_edit_cursor_ux_position(t_score *x){
    if (x->r_ob.notation_cursor.chord)
        return chord_get_alignment_ux((t_notation_obj *) x, x->r_ob.notation_cursor.chord);
    else {
        t_measure *curr_meas = x->r_ob.notation_cursor.measure;
        double lastmeas_uxpos = curr_meas->tuttipoint_reference->offset_ux + curr_meas->start_barline_offset_ux + curr_meas->width_ux;
        double uxpos;
        
        if (curr_meas->lastchord)
            uxpos = chord_get_alignment_ux((t_notation_obj *) x, curr_meas->lastchord) + 10;
        else 
            uxpos = curr_meas->tuttipoint_reference->offset_ux + curr_meas->start_barline_offset_ux + 10 + (need_to_show_ts(x, curr_meas) ? curr_meas->timesignature_spacing_uwidth : 0);

        if (uxpos > lastmeas_uxpos)
            uxpos = (curr_meas->lastchord ? (chord_get_alignment_ux((t_notation_obj *) x, curr_meas->lastchord) + lastmeas_uxpos)/2. : (curr_meas->tuttipoint_reference->offset_ux + curr_meas->start_barline_offset_ux + lastmeas_uxpos)/2.);
        return uxpos;
    }    
}
    
    
char get_actual_tempo_interp(t_score *x, t_tempo *tempo)
{
    char tempo_interp = 0;
    t_tempo *nexttempo = tempo_get_next(tempo);
    if (nexttempo && (tempo->interpolation_type != 0)) {
        if (rat_rat_cmp(nexttempo->tempo_value, tempo->tempo_value) == 1) // we start an accelerando
            tempo_interp = 1;
        else if (rat_rat_cmp(nexttempo->tempo_value, tempo->tempo_value) == -1) // we start a rallentando
            tempo_interp = -1;
        else
            tempo_interp = 0;
    }
    return tempo_interp;
}

char do_dynamics_span_ties(t_score *x)
{
    if (x->r_ob.link_dynamics_to_slot > 0 && x->r_ob.link_dynamics_to_slot <= CONST_MAX_SLOTS &&
        x->r_ob.slotinfo[x->r_ob.link_dynamics_to_slot - 1].slot_singleslotfortiednotes == 0)
        return 0;
    return 1;
}
    
void paint_scorevoice(t_score *x, t_scorevoice *voice, t_object *view, t_jgraphics *g, t_rect rect, double end_x_to_repaint_no_inset, double last_staff_bottom, t_jfont *jf, t_jfont *jf_acc, t_jfont *jf_text_fractions, t_jfont *jf_acc_bogus, t_jfont *jf_ts, t_jfont *jf_ts_big, t_jfont *jf_tempi, t_jfont *jf_text, t_jfont *jf_text_small, t_jfont *jf_text_smallbold, t_jfont *jf_text_markers, t_jfont *jf_tempi_italic, t_jfont *jf_tempi_figure, t_jfont *jf_measure_num, t_jfont *jf_tuplets, t_jfont *jf_lyrics, t_jfont *jf_lyrics_nozoom, t_jfont *jf_ann, t_jfont *jf_small_dynamics, t_jfont *jf_small_dynamics_roman, t_jfont *jf_dynamics, t_jfont *jf_dynamics_roman, t_pt *force_xy_position, t_llll *repaint_these_measure_nums)
{
	t_jfont *jf_grace = NULL;
	t_jrgba mainstaffcolor = get_mainstaff_color((t_notation_obj *) x, voice->v_ob.r_it.selected, voice->v_ob.locked, voice->v_ob.muted, voice->v_ob.solo);
	t_jrgba auxstaffcolor = get_auxstaff_color((t_notation_obj *) x, voice->v_ob.r_it.selected, voice->v_ob.locked, voice->v_ob.muted, voice->v_ob.solo);
    t_jrgba beamcolor = beam_get_color((t_notation_obj *)x, (t_voice *)voice);
    t_jrgba tupletcolor = tuplet_get_color((t_notation_obj *)x, (t_voice *)voice);

    t_measure *curr_meas;
    t_chord *curr_ch;
    t_note *curr_nt;

    long clef = get_voice_clef((t_notation_obj *)x, (t_voice *)voice);
    double staff_top, staff_bottom;
    double system_jump = 0; // just for now!!!
    char tempo_interp = 0;
    double start_dottedline_x = 0.;
    t_tuttipoint *curr_tuttipt;
    double tuttipoint_ux;
    long k;
    char lyrics_dashed_going_on = 0, lyrics_word_extension_going_on = 0;
    t_chord *lyrics_word_extensions_start_chord = NULL;
    double left_dashed_ux = 0., left_word_extension_ux = 0.;
    double measure_numbers_top_y = 0;
    t_voice *first_visible_voice = voice_get_first_visible((t_notation_obj *)x);
    char is_in_voiceensemble = (voiceensemble_get_numparts((t_notation_obj *)x, (t_voice *)voice) > 1);
    char part_direction = is_in_voiceensemble ? (voice->v_ob.part_index % 2 == 1 ? -1 : 1) : 0;
    char dynamics_span_ties = do_dynamics_span_ties(x);
    
    double domain_start_pixel = get_predomain_width_pixels((t_notation_obj *)x);
    double domain_end_pixel = unscaled_xposition_to_xposition((t_notation_obj *)x, x->r_ob.screen_ux_end);

    char last_annotation_text[BACH_MAX_LAST_ANNOTATION_TEXT_CHARS];
    double annotation_sequence_start_x_pos = 0, annotation_sequence_end_x_pos = 0, annotation_line_y_pos = 0;
    last_annotation_text[0] = 0;

    
    if (voice->v_ob.hidden) // voice is hidden!
        return;

#ifdef BACH_SPACING_DEBUG
    long yy = 0;
#endif

    
    double curr_hairpin_start_x = -100;
    long curr_hairpin_type = 0;
    t_chord *first_painted_chord = NULL;
    t_chord *last_painted_chord = NULL;
    t_jrgba prev_hairpin_color = x->r_ob.j_dynamics_rgba;
    char prev_hairpin_dontpaint = false;

    
    // Boundary line between voices: needed for debug
    // paint_line((t_notation_obj *) x, g, x->r_ob.j_selection_rgba, 0, voice->v_ob.offset_y + CONST_VOICE_THRESHOLD * x->r_ob.zoom_y, rect.width, voice->v_ob.offset_y + CONST_VOICE_THRESHOLD * x->r_ob.zoom_y, 1.);
    
    // paint staff lines
    double this_middleC_y = voice->v_ob.middleC_y;
    staff_top = get_staff_top_y((t_notation_obj *) x, (t_voice *) voice, false);
    staff_bottom = get_staff_bottom_y((t_notation_obj *) x, (t_voice *) voice, false);

    // possible forced shift
    if (force_xy_position) {
        this_middleC_y = this_middleC_y - staff_top + force_xy_position->y;
        staff_bottom = this_middleC_y - staff_top + force_xy_position->y;
        staff_top = force_xy_position->y;
    }


    // paint staff lines
    if (voice->v_ob.part_index == 0)
        for (k = 0; k < x->r_ob.num_systems; k++)
            paint_staff_lines((t_notation_obj *)x, g, end_x_to_repaint_no_inset, rect.width - x->r_ob.j_inset_x, 1., this_middleC_y + k * system_jump, clef, mainstaffcolor, auxstaffcolor, voice->v_ob.num_staff_lines, voice->v_ob.staff_lines);
    
    // clefs (and keys) later! at the end!
    
#ifdef BACH_PAINT_IDS
    char text[20];
    snprintf_zero(text, 40, "%ld", voice->v_ob.r_it.ID);
    write_text(g, jf_text_markers, build_jrgba(0, 0.3, 0, 1), text, x->r_ob.j_inset_x + 20 * x->r_ob.zoom_y, staff_top - 40, rect.width, 40, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
#endif
    
    // measures!
    curr_tuttipt = x->r_ob.firsttuttipoint;
    tuttipoint_ux = (curr_tuttipt) ? curr_tuttipt->offset_ux : 0; // it's the x of the tuttipoint to which *curr_meas will belong
    
    t_tempo *last_cur_tempo = NULL;
    
    for (curr_meas = voice->firstmeasure; curr_meas && curr_tuttipt; curr_meas = curr_meas->next) {
        long tuplet_group_index = 0;
        t_jrgba notecolor, tailcolor, stemcolor, flagcolor, accidentalcolor, durationlinecolor;
        double octave_stem_length;
        double end_barline_x, end_barline_y;
        char barline_type, measure_across;
        char measure_locked, measure_muted, measure_solo, measure_linear_edited;
        t_jrgba barline_color;
        
        // changed tuttipoint?
        if (curr_tuttipt->next && curr_tuttipt->next->measure[voice->v_ob.number] == curr_meas) {
            curr_tuttipt = curr_tuttipt->next;
            tuttipoint_ux = curr_tuttipt->offset_ux;
            if (force_xy_position)
                tuttipoint_ux = tuttipoint_ux - xposition_to_unscaled_xposition((t_notation_obj *)x, (unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.firsttuttipoint->offset_ux) - force_xy_position->x));
        }
        
#ifdef BACH_SPACING_DEBUG
        if (curr_meas == curr_tuttipt->measure[voice->v_ob.number]) {
            t_alignmentpoint *al;
            for (al = curr_tuttipt->firstalignmentpoint; al; al = al->next){
                char text[200];
                long i;
                double xx = unscaled_xposition_to_xposition((t_notation_obj *)x, curr_tuttipt->offset_ux + al->offset_ux);
                for (i = 0; i < al->num_aligned_obj; i++)
                    text[i] = (al->aligned_obj[i]->type == k_CHORD ? 'c' : (al->aligned_obj[i]->type == k_MEASURE_END_BARLINE ? 'b' : (al->aligned_obj[i]->type == k_TEMPO ? 't' : '?')));
                snprintf(text + al->num_aligned_obj, 150, ": %.2fux, %ld/%ld = %.2fsec", al->offset_ux, al->r_onset_sec.r_num, al->r_onset_sec.r_den, rat2double(al->r_onset_sec));
                write_text_standard(g, jf_text_markers, build_jrgba(0.1, 0.3, 0.6, 0.7), text, xx, (yy + 10) * x->r_ob.zoom_y, 400* x->r_ob.zoom_y, 30 * x->r_ob.zoom_y);
                paint_dashed_line(g, build_jrgba(0.1, 0.3, 0.6, 0.7), xx, 0, xx, rect.height, 1, 5);
                yy = (yy + 10) % 100;
            }
        }
#endif                
        
        if (tuttipoint_ux + curr_meas->start_barline_offset_ux > x->r_ob.screen_ux_end)
            break;
        
        if (tuttipoint_ux + curr_meas->start_barline_offset_ux + curr_meas->width_ux < x->r_ob.screen_ux_start - 300 / x->r_ob.zoom_x) {
            if (curr_meas->lasttempo && !curr_meas->lasttempo->hidden) {
                last_cur_tempo = curr_meas->lasttempo;
                start_dottedline_x = unscaled_xposition_to_xposition((t_notation_obj *)x, x->r_ob.screen_ux_start);
                tempo_interp = get_actual_tempo_interp(x, curr_meas->lasttempo);
            }

            continue;
        }
        
        measure_locked = notation_item_is_globally_locked((t_notation_obj *)x, (t_notation_item *)curr_meas);
        measure_muted = notation_item_is_globally_muted((t_notation_obj *)x, (t_notation_item *)curr_meas);
        measure_solo = notation_item_is_globally_solo((t_notation_obj *)x, (t_notation_item *)curr_meas);
        measure_linear_edited = (x->r_ob.notation_cursor.measure == curr_meas);
        
        
#ifdef BACH_PAINT_IDS
        char text[20];
        snprintf_zero(text, 40, "%ld", curr_meas->r_it.ID);
        write_text(g, jf_text_markers, get_grey(0.2), text, unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux), 
                   staff_top - 40, rect.width, 40, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
#endif
        
#ifdef BACH_SPACING_DEBUG
        double t1 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux));
        double t2 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux + curr_meas->width_ux));
        paint_rectangle(g, get_grey(1.), change_alpha(get_default_slotcolor(curr_meas->tuttipoint_reference->ID), 0.5), t1, staff_top, t2 - t1, staff_bottom - staff_top, 0.);
#endif
        // measure selected?
        if (notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_meas)) {
            t_jrgba meas_sel_color = change_alpha(measure_get_color((t_notation_obj *) x, true, measure_locked, measure_muted, measure_solo, measure_linear_edited), 0.2);
            double sel_x1 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux)); 
            double sel_x2 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux + curr_meas->width_ux));
            paint_rectangle(g, get_grey(1.), meas_sel_color, sel_x1, staff_top, sel_x2 - sel_x1, staff_bottom - staff_top, 0.);
            
        } else {
            if (measure_locked || measure_muted || measure_solo || measure_linear_edited) {
                t_jrgba bgmeascolor = get_grey(1.);
                change_color_depending_on_playlockmute((t_notation_obj *) x, &bgmeascolor, false, false, measure_locked, measure_muted, measure_solo, measure_linear_edited);
                bgmeascolor = change_alpha(bgmeascolor, 0.2);
                if (bgmeascolor.red != 1 || bgmeascolor.blue != 1 || bgmeascolor.green != 1 || bgmeascolor.alpha != 1) {
                    double sel_x1 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux));
                    double sel_x2 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux + curr_meas->width_ux));
                    paint_rectangle(g, get_grey(1.), bgmeascolor, sel_x1, staff_top, sel_x2 - sel_x1, staff_bottom - staff_top, 0.);
                }
            }
        }
        
        
        // need to print time signature?
        if (x->r_ob.show_time_signatures && need_to_show_ts(x, curr_meas)) {
            // if it's the first measure, or if the time signature has changed from previous measure, print time signature, one for each staff
            char big = (x->r_ob.show_time_signatures == 2) && (!curr_meas->prev || is_barline_tuttipoint_with_same_ts((t_notation_obj *)x, curr_meas->prev->end_barline));
            paint_timesignature((t_notation_obj *) x, g, x->r_ob.j_mainstaves_rgba, big ? jf_ts_big : jf_ts, clef, get_staff_top_y((t_notation_obj *)x, (t_voice *)voice, true), curr_meas, big);
        }
        
        
        // paint measure label rectangles 
        if (x->r_ob.show_label_families == k_SHOW_LABEL_FAMILIES_SINGLETONS) 
            paint_measure_label_families((t_notation_obj *)x, view, g, curr_meas);        
        
        
        // chords and notes!
        octave_stem_length =  mc_to_yposition_in_scale((t_notation_obj *) x,6000, (t_voice *) voice) - mc_to_yposition_in_scale((t_notation_obj *) x,7200, (t_voice *) voice); // y_length corresponding to 1 octave 
        for (curr_ch = curr_meas->firstchord; curr_ch; curr_ch = curr_ch->next) { // cycle on the chords
            
            double accidental_top_extension = 0., accidental_bottom_extension = 0.; // local top-bottom values for the accidental
            
            // finding stem position // to do: handle scrollbar
            double chord_alignment_point_x = unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_ch->alignment_ux);
            double stem_x = get_stem_x_from_alignment_point_x((t_notation_obj *)x, curr_ch, chord_alignment_point_x);
            char is_chord_locked, is_chord_muted, is_chord_solo, is_chord_linear_edited;
            t_pt beaming_average_point; 
            char is_grace_chord = curr_ch->is_grace_chord;
            double grace_ratio = is_grace_chord ? CONST_GRACE_CHORD_SIZE : 1.;
            
//            paint_line(g, build_jrgba(1, 0, 0, 0.5), chord_alignment_point_x, 0., chord_alignment_point_x, rect.height, 1);
            
            // handling selection
            char is_chord_selected = (notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_ch) ^ notation_item_is_preselected((t_notation_obj *) x, (t_notation_item *)curr_ch)); // 1 if chord is selected
            
            // handling play
            char is_chord_played = false;
            
            if (is_grace_chord)
                jf_grace = jfont_create_debug(x->r_ob.noteheads_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.notation_typo_preferences.base_pt * x->r_ob.zoom_y * grace_ratio);
            
            if (x->r_ob.playing && x->r_ob.play_mode == k_PLAYMODE_CHORDWISE && x->r_ob.highlight_played_notes) {
                if (curr_ch->played) {
                    t_chord *lasttiedchord_forplay;
                    if (curr_ch->firstnote)
                        lasttiedchord_forplay = x->r_ob.play_tied_elements_separately ? curr_ch : last_all_tied_chord(curr_ch, false);
                    else
                        lasttiedchord_forplay = x->r_ob.play_rests_separately ? curr_ch : rest_get_last_in_seq(curr_ch, false);
                    if (lasttiedchord_forplay && x->r_ob.play_head_ms < lasttiedchord_forplay->onset + lasttiedchord_forplay->duration_ms)
                        is_chord_played = true;
                }
            }
            
            // handling lock
            is_chord_locked = notation_item_is_globally_locked((t_notation_obj *)x, (t_notation_item *)curr_ch);
            is_chord_muted = notation_item_is_globally_muted((t_notation_obj *)x, (t_notation_item *)curr_ch);
            is_chord_solo = notation_item_is_globally_solo((t_notation_obj *)x, (t_notation_item *)curr_ch);
            is_chord_linear_edited = (x->r_ob.notation_cursor.measure == curr_meas && x->r_ob.notation_cursor.chord == curr_ch);
            
            // setting stem_x field
            curr_ch->stem_x = stem_x;
            
            // average point on the main beaming
            beaming_average_point.x = stem_x; beaming_average_point.y = 0.; // will be useful later, with tuplets
            
            if (chord_get_placement_in_screen((t_notation_obj *) x, curr_ch) == 0) {
                double first_note_y_real = 0, last_note_y_real = 0;
                double end_pos = unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_ch->stem_offset_ux + curr_ch->duration_ux); 
                double chord_first_notehead_uwidth = 0;
                long i;
                
                if (!first_painted_chord) {
                    long s = x->r_ob.link_dynamics_to_slot - 1;
                    if (x->r_ob.show_hairpins && s >= 0 && s < CONST_MAX_SLOTS && x->r_ob.slotinfo[s].slot_type == k_SLOT_TYPE_DYNAMICS) {
                        // check if there's an hairpin ending on this chord
                        for (t_chord *temp = chord_get_prev(curr_ch); temp; temp = chord_get_prev(temp)) {
                            if (chord_has_dynamics(temp)) {
                                t_dynamics *dyn = chord_get_dynamics(temp);
                                if (dyn) {
                                    curr_hairpin_type = (dyn->lastmark ? dyn->lastmark->hairpin_to_next : 0);
                                    curr_hairpin_start_x = unscaled_xposition_to_xposition((t_notation_obj *) x, chord_get_alignment_ux((t_notation_obj *) x, temp));
                                    break;
                                }
                            }
                        }
                    }
                    first_painted_chord = curr_ch;
                }
                
                last_painted_chord = curr_ch;
                
#ifdef BACH_PAINT_IDS
                char text[140];
                snprintf_zero(text, 140, "%ld", curr_ch->r_it.ID);
                write_text(g, jf_text_markers, build_jrgba(0.3, 0, 0, 1), text, curr_ch->stem_x, 
                           staff_top - 40, rect.width, 40, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
#endif

                // debug
/*                char text[340];
                snprintf_zero(text, 340, "o %ld/%ld, d %ld/%ld", curr_ch->play_r_sym_onset.r_num, curr_ch->play_r_sym_onset.r_den, curr_ch->play_r_sym_duration.r_num, curr_ch->play_r_sym_duration.r_den);
                write_text(g, jf_text_markers, build_jrgba(0.3, 0, 0, 1), text, curr_ch->stem_x, 
                           staff_top - 40, rect.width, 40, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
*/
                
                /*                        // DEBUG
                 t_xml_chord_beam_info xml1 = get_xml_chord_beam_info((t_notation_obj *) x, curr_ch);
                 t_xml_chord_tuplet_info xml2[CONST_MAX_XML_NESTED_TUPLETS];
                 long num_tuplets = get_xml_chord_tuplet_info((t_notation_obj *) x, curr_ch, xml2);
                 snprintf_zero(text, 140, "BDpth: %ld. b: %d %d %d %d", xml1.num_beams, xml1.beam_type[0], xml1.beam_type[1], xml1.beam_type[2], xml1.beam_type[3]);
                 write_text(g, jf_text_markers, build_jrgba(0, 0.4, 0, 1), text, curr_ch->stem_x, 
                 staff_top - 20, rect.width, 20, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
                 snprintf_zero(text, 140, "Tdpth: %ld", num_tuplets);
                 write_text(g, jf_text_markers, build_jrgba(0, 0.4, 0, 1), text, curr_ch->stem_x, 
                 staff_top - 40, rect.width, 40, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
                 */
                
                double label_family_chord_shape_radius = CONST_LABEL_FAMILY_NOTE_STARTING_URADIUS * x->r_ob.zoom_y;
                
                if (curr_ch->r_sym_duration.r_num >= 0 && curr_ch->firstnote) { // non-rest
                    // chord values useful later:
                    first_note_y_real = mc_to_yposition_in_scale((t_notation_obj *) x, note_get_screen_midicents(curr_ch->firstnote), (t_voice *) voice);
                    last_note_y_real = mc_to_yposition_in_scale((t_notation_obj *) x, note_get_screen_midicents(curr_ch->lastnote), (t_voice *) voice);
//                    curr_ch->firstnote_y_real = first_note_y_real;
//                    curr_ch->lastnote_y_real = last_note_y_real;
                    
                    // assign top and bottom extensions (if not already assigned by beamings)
                    if (curr_ch->topmost_y == DBL_SMALLEST)
                        curr_ch->topmost_y = staff_top + curr_ch->topmost_stafftop_uy * x->r_ob.zoom_y; 
                    if (curr_ch->bottommost_y == DBL_SMALLEST)
                        curr_ch->bottommost_y = staff_top + curr_ch->bottommost_stafftop_uy * x->r_ob.zoom_y; 
//                    if (curr_ch->topmost_y_noacc == DBL_SMALLEST)
                        curr_ch->topmost_y_noacc = staff_top + curr_ch->topmost_stafftop_uy_noacc * x->r_ob.zoom_y;
                    if (curr_ch->bottommost_y_noacc == DBL_SMALLEST)
                        curr_ch->bottommost_y_noacc = staff_top + curr_ch->bottommost_stafftop_uy_noacc * x->r_ob.zoom_y; 
                    if (curr_ch->beam_y == DBL_SMALLEST) {
//                        curr_ch->beam_y = (curr_ch->direction == 1) ? curr_ch->topmost_y_noacc : curr_ch->bottommost_y_noacc;
                        curr_ch->beam_y = staff_top + curr_ch->stemtip_stafftop_uy * x->r_ob.zoom_y;
                    }

					// decide stem & noteflag basic positions
					stemcolor = stem_get_color((t_notation_obj *) x, curr_ch, is_chord_selected, is_chord_played, is_chord_locked, is_chord_muted, is_chord_solo, is_chord_linear_edited);
                    flagcolor = flag_get_color((t_notation_obj *) x, curr_ch, is_chord_selected, is_chord_played, is_chord_locked, is_chord_muted, is_chord_solo, is_chord_linear_edited);
					curr_ch->stem_x = stem_x;
					
					if ((curr_ch->beams_depth == 0) && rat_rat_cmp(curr_ch->figure, RAT_1OVER8) <= 0) {
						// if we don't have to beam the chord and if the duration needs flags
						char i;
						char howmanyflags;
						double firstshift_y, secondshift_y, nextstep_y; 
						double flag_x;
						long outlen;
						char firsttailcharacter[5], followingtailcharacter[5];
						char *followingtailcharacter_utf;
						double this_flag_x;

						double tip_y = staff_top + curr_ch->stemtip_stafftop_uy * x->r_ob.zoom_y; // for some reason sometimes curr_ch->stemtip_stafftop_uy is wrong (0)!
						
//						dev_post("Chord %p: tip: %.2f, need_rec ? %d", curr_ch, curr_ch->stemtip_stafftop_uy, (long)curr_ch->need_recompute_parameters);
						
						// draw stem if needed
						if (x->r_ob.show_stems > 0 && rat_rat_cmp(curr_ch->figure, RAT_1OVER2) <= 0) {
							if (curr_ch->direction == 1) // stem upwards
								paint_line(g, stemcolor, stem_x, first_note_y_real, stem_x, tip_y, CONST_STEM_WIDTH);
							else if (curr_ch->direction == -1) // stem downwards
								paint_line(g, stemcolor, stem_x, last_note_y_real, stem_x, tip_y, CONST_STEM_WIDTH);
						}
						
						// draw noteflag
                        if (x->r_ob.show_flags) {
                            howmanyflags = perfect_log2(rat_rat_div(RAT_1OVER8, curr_ch->figure).r_num) + 1;
                            
                            if (curr_ch->direction == 1) { // stem up
                                if (howmanyflags >= 2) {
                                    char *firsttailcharacter_utf = charset_unicodetoutf8_debug(&x->r_ob.notation_typo_preferences.flag_unicode_characters[2], 1, &outlen);
                                    strncpy(firsttailcharacter, firsttailcharacter_utf, 4);
                                    bach_freeptr(firsttailcharacter_utf);
                                    firstshift_y = tip_y + x->r_ob.notation_typo_preferences.flag_uy_shifts[2] * x->r_ob.zoom_y * grace_ratio;
                                    secondshift_y = tip_y + x->r_ob.notation_typo_preferences.flag_uy_shifts[4] * x->r_ob.zoom_y * grace_ratio;
                                } else {
                                    char *firsttailcharacter_utf = charset_unicodetoutf8_debug(&x->r_ob.notation_typo_preferences.flag_unicode_characters[0], 1, &outlen);
                                    strncpy(firsttailcharacter, firsttailcharacter_utf, 4);
                                    bach_freeptr(firsttailcharacter_utf);
                                    firstshift_y = tip_y + x->r_ob.notation_typo_preferences.flag_uy_shifts[0] * x->r_ob.zoom_y * grace_ratio;
                                    secondshift_y = tip_y + x->r_ob.notation_typo_preferences.flag_uy_shifts[4] * x->r_ob.zoom_y * grace_ratio;
                                }
                                
                                followingtailcharacter_utf = charset_unicodetoutf8_debug(&x->r_ob.notation_typo_preferences.flag_unicode_characters[4], 1, &outlen);
                                strncpy(followingtailcharacter, followingtailcharacter_utf, 4);
                                bach_freeptr(followingtailcharacter_utf);
                                nextstep_y = - x->r_ob.notation_typo_preferences.further_flag_uy_step_stemup * x->r_ob.zoom_y * grace_ratio;
                            } else { // stem down
                                if (howmanyflags >= 2) {
                                    char *firsttail_character_utf = charset_unicodetoutf8_debug(&x->r_ob.notation_typo_preferences.flag_unicode_characters[3], 1, &outlen);
                                    strncpy(firsttailcharacter, firsttail_character_utf, 4);
                                    bach_freeptr(firsttail_character_utf);
                                    firstshift_y = tip_y - octave_stem_length * grace_ratio + x->r_ob.notation_typo_preferences.flag_uy_shifts[3] * x->r_ob.zoom_y * grace_ratio;
                                    secondshift_y = tip_y - octave_stem_length * grace_ratio + x->r_ob.notation_typo_preferences.flag_uy_shifts[5] * x->r_ob.zoom_y * grace_ratio;
                                } else {
                                    char *firsttail_character_utf = charset_unicodetoutf8_debug(&x->r_ob.notation_typo_preferences.flag_unicode_characters[1], 1, &outlen);
                                    strncpy(firsttailcharacter, firsttail_character_utf, 4);
                                    bach_freeptr(firsttail_character_utf);
                                    firstshift_y = tip_y - octave_stem_length * grace_ratio + x->r_ob.notation_typo_preferences.flag_uy_shifts[1] * x->r_ob.zoom_y * grace_ratio;
                                    secondshift_y = tip_y - octave_stem_length * grace_ratio + x->r_ob.notation_typo_preferences.flag_uy_shifts[5] * x->r_ob.zoom_y * grace_ratio;
                                }
                                followingtailcharacter_utf = charset_unicodetoutf8_debug(&x->r_ob.notation_typo_preferences.flag_unicode_characters[5], 1, &outlen);
                                strncpy(followingtailcharacter, followingtailcharacter_utf, 4);
                                bach_freeptr(followingtailcharacter_utf);
                                nextstep_y = x->r_ob.notation_typo_preferences.further_flag_uy_step_stemdown * x->r_ob.zoom_y * grace_ratio;
                            }
                            
                            flag_x = stem_x - 0.5 + x->r_ob.notation_typo_preferences.flag_ux_shift * x->r_ob.zoom_y;
                            
                            for (i = 0; i < howmanyflags; i++) {
                                // paint a notetail
                                int j = (howmanyflags >= 2) ? (i > 0 ? 4 : 2) : 0;
                                
                                if ((curr_ch->direction == 1) && (x->r_ob.notation_typo_preferences.flag_noteheadaligned[j] == 1))
                                    this_flag_x = flag_x - round(notehead_get_uwidth((t_notation_obj *)x, curr_ch->figure, NULL, false) * x->r_ob.zoom_y) + 1.45;
                                else 
                                    this_flag_x = flag_x; 
                                
                                write_text_standard_account_for_vinset((t_notation_obj *) x, g, is_grace_chord ? jf_grace : jf, flagcolor,
                                                              i == 0 ? firsttailcharacter : followingtailcharacter, this_flag_x, 
                                                              i == 0 ? firstshift_y : (curr_ch->direction == 1 ? secondshift_y - (i - 2) * nextstep_y : secondshift_y + (i - 2) * nextstep_y));
                                if (i == 0) 
                                    i++; // we skip the 1/16 flag: we've already drawn that
                            }
                            
                            // slash flag?
                            if (curr_ch->is_grace_chord && x->r_ob.slash_grace_flags) {
                                if (curr_ch->direction == 1)
                                    paint_line(g, flagcolor, stem_x - 3 * x->r_ob.zoom_y, tip_y + 7 * x->r_ob.zoom_y,
                                               stem_x + 4 * x->r_ob.zoom_y, tip_y + 1 * x->r_ob.zoom_y, 1);
                                else 
                                    paint_line(g, flagcolor, stem_x - 3 * x->r_ob.zoom_y, tip_y - 6 * x->r_ob.zoom_y,
                                               stem_x + 4 * x->r_ob.zoom_y, tip_y - 0 * x->r_ob.zoom_y, 1);
                            }
                        }
                    } else {
                        // draw stem if needed
                        if (x->r_ob.show_stems > 0 && rat_rat_cmp(curr_ch->figure, RAT_1OVER2) <= 0) { // the figure is <= 1/2: we need the stem
                            double tip_y = staff_top + curr_ch->stemtip_stafftop_uy * x->r_ob.zoom_y;
                            paint_line(g, stemcolor, stem_x, curr_ch->direction == 1 ? first_note_y_real : last_note_y_real, stem_x, tip_y, CONST_STEM_WIDTH);
                        }
                        
                    }
                    
                    // we draw the notes and the accidentals
                    for (curr_nt = curr_ch->firstnote; curr_nt; curr_nt = curr_nt->next) { // cycle on the notes
                        
                        // selection (or preselection):
                        char is_note_preselected = notation_item_is_preselected((t_notation_obj *) x, (t_notation_item *)curr_nt);
                        char is_note_selected = (notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_nt) ^ is_note_preselected);
                        char is_durationline_selected = is_note_selected; 
                        char is_tail_selected = (notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_nt->lastbreakpoint) ^ notation_item_is_preselected((t_notation_obj *) x, (t_notation_item *)curr_nt->lastbreakpoint)); 
                        char note_unselected = false;
                        char is_note_locked, is_note_muted, is_note_solo;
                        double note_y, note_y_real, note_x_real, notehead_uwidth;
                        long scaleposition;
                        double ledger_lines_y[CONST_MAX_LEDGER_LINES]; 
                        int num_ledger_lines = 0; int i;
                        double additional_notehead_correction;
                        char j;
                        double dot_x_offset, dot_y_offset;
                        t_bpt *selected_breakpoint = NULL;
                        char is_note_played = false;
                        double note_end_pos = end_pos;
                        
//                        if (x->r_ob.show_durations && x->r_ob.dl_spans_ties > 2 && curr_nt->tie_from)
//                            continue;
                        
                        if (is_chord_selected && is_note_preselected)
                            note_unselected = true;
                        
                        if (x->r_ob.dl_spans_ties) {
                            t_note *last_tie = note_get_last_in_tieseq(curr_nt);
                            if (last_tie && last_tie != curr_nt)
                                note_end_pos = unscaled_xposition_to_xposition((t_notation_obj *)x, last_tie->parent->parent->tuttipoint_reference->offset_ux + last_tie->parent->stem_offset_ux + last_tie->parent->duration_ux);
                        }
                        
						
						// handle play
						if (x->r_ob.playing && x->r_ob.highlight_played_notes) {
							if (x->r_ob.play_mode == k_PLAYMODE_CHORDWISE)
								is_note_played = is_chord_played;
							else {
								if (should_element_be_played((t_notation_obj *) x, (t_notation_item *)curr_nt) && (curr_ch->played || curr_nt->played)) {
									t_note *lasttiednote_forplay = x->r_ob.play_tied_elements_separately ? curr_nt : note_get_last_in_tieseq(curr_nt);
									if (x->r_ob.play_head_ms < lasttiednote_forplay->parent->onset + lasttiednote_forplay->parent->duration_ms)
										is_note_played = true;
								}
							}
						}
						
						
						// handle lock
						is_note_locked = notation_item_is_globally_locked((t_notation_obj *)x, (t_notation_item *)curr_nt);
						is_note_muted = notation_item_is_globally_muted((t_notation_obj *)x, (t_notation_item *)curr_nt);
						is_note_solo = notation_item_is_globally_solo((t_notation_obj *)x, (t_notation_item *)curr_nt);
						
						// get colors
						notecolor = note_get_color((t_notation_obj *) x, curr_nt, !note_unselected && (is_chord_selected || is_note_selected || is_durationline_selected), is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited, curr_nt->velocity);
                        durationlinecolor = durationline_get_color((t_notation_obj *) x, curr_nt, !note_unselected && (is_chord_selected || is_note_selected || is_durationline_selected), is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited, curr_nt->velocity);
                        accidentalcolor = accidental_get_color((t_notation_obj *) x, curr_nt, !note_unselected && (is_chord_selected || is_note_selected || is_durationline_selected), is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited, curr_nt->velocity);
						tailcolor = tail_get_color((t_notation_obj *) x, curr_nt, !note_unselected && (is_chord_selected || is_note_selected || is_durationline_selected || is_tail_selected), is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited, x->r_ob.breakpoints_have_velocity ? curr_nt->lastbreakpoint->velocity : curr_nt->velocity);
						
						// particular case: note is end of a slur that is being drawn
						if (x->r_ob.j_mouse_is_down &&
                            ((x->r_ob.j_mousedown_obj_type == k_SLUR_START_POINT && ((t_slur *) x->r_ob.j_mousedown_ptr)->start_chord == curr_ch) ||
                             (x->r_ob.j_mousedown_obj_type == k_SLUR_END_POINT && ((t_slur *) x->r_ob.j_mousedown_ptr)->end_chord == curr_ch)))
							notecolor = color_interp(notecolor, build_jrgba(1., 0.7, 0.7, 1.), 0.5); 
						
						notehead_uwidth = curr_nt->notehead_uwidth;
						chord_first_notehead_uwidth = notehead_uwidth;
						
						// finding y positions
						note_y = mc_to_yposition_in_scale_for_notes((t_notation_obj *) x,curr_nt, (t_voice *) voice, 1);
						note_y_real = mc_to_yposition_in_scale((t_notation_obj *) x, note_get_screen_midicents(curr_nt), (t_voice *) voice);
						curr_nt->center.y = note_y_real;
						
						// finding x positions
                        double shift = (get_notehead_ux_shift((t_notation_obj *) x, curr_nt) + curr_nt->notecenter_stem_delta_ux) * x->r_ob.zoom_y;
                        note_x_real = stem_x + shift;
                        curr_nt->center.x = note_x_real;
                        
                        // paint note label circles
                        if (x->r_ob.show_label_families == k_SHOW_LABEL_FAMILIES_SINGLETONS) 
                            paint_note_label_families((t_notation_obj *)x, view, g, curr_nt, &label_family_chord_shape_radius);

                        // background noteslots
                        double slot_zoom_y = x->r_ob.zoom_y * (x->r_ob.bgslot_zoom/100.);
                        double note_x = note_x_real - ((notehead_uwidth  * grace_ratio/ 2.) * x->r_ob.zoom_y);
                        paint_background_slots((t_notation_obj *) x, g, note_x_real, note_y_real, end_pos - note_x_real, jf_text_small,
                                                   jf_text_smallbold, jf_small_dynamics, jf_small_dynamics_roman, (t_notation_item *)curr_nt,
                                                   note_x_real + (note_x_real - note_x) * 2  + x->r_ob.background_slot_text_ushift[0] * slot_zoom_y, 
                                                   note_y_real + x->r_ob.background_slot_text_ushift[1] * slot_zoom_y, 
                                                   note_x_real + (note_x_real - note_x) * 2  + x->r_ob.background_slot_text_ushift[0] * slot_zoom_y, 
                                                   note_y_real - (1.3 * x->r_ob.slot_background_font_size - 0.5) * slot_zoom_y + x->r_ob.background_slot_text_ushift[1] * slot_zoom_y, -1);
                        
                        // draw ledger lines if needed
                        scaleposition = curr_nt->pitch_displayed.toStepsFromMiddleC();
                        
                        additional_notehead_correction = (rat_rat_cmp(curr_ch->figure, RAT_1OVER2) <= 0) ? 0. : 2.;

                        get_ledger_lines((t_notation_obj *) x, (t_voice *) voice, scaleposition, &num_ledger_lines, ledger_lines_y); // let's obtain the list of ledger lines y
                        for (i = 0; i < num_ledger_lines; i++)
                            paint_line(g, mainstaffcolor, note_x_real - CONST_LEDGER_LINES_HALF_UWIDTH * grace_ratio * curr_nt->notehead_resize * x->r_ob.zoom_y, ledger_lines_y[i], note_x_real + (additional_notehead_correction + CONST_LEDGER_LINES_HALF_UWIDTH) * grace_ratio * curr_nt->notehead_resize * x->r_ob.zoom_y, ledger_lines_y[i], 1.);
                        
                        
                        // duration line and breakpoints
                        if (x->r_ob.show_durations && (x->r_ob.dl_spans_ties == 0 || !curr_nt->tie_from)) {
                            if (x->r_ob.allow_glissandi) {
                                double (*mc_to_ypos)(t_notation_obj *, double, t_voice *) = x->r_ob.breakpoints_have_noteheads ? mc_to_yposition_quantized : mc_to_yposition;
                                double mc_or_screen_mc = x->r_ob.breakpoints_have_noteheads ? curr_nt->midicents : note_get_screen_midicents(curr_nt);
                                t_bpt *temp = curr_nt->firstbreakpoint->next;
                                double prev_bpt_y = mc_to_ypos((t_notation_obj *) x, note_get_screen_midicents(curr_nt), (t_voice *) voice);
                                double prev_bpt_x = note_x_real + notehead_uwidth * x->r_ob.zoom_y * 0.41;
                                // first: draw all the lines
                                while (temp) {
                                    // draw line
                                    double bpt_x = (temp->rel_x_pos < 1.) ? chord_alignment_point_x + (note_end_pos - chord_alignment_point_x) * temp->rel_x_pos : note_end_pos;
                                    double bpt_y;
                                    
                                    if (temp->rel_x_pos >= 1. && (x->r_ob.breakpoints_have_noteheads)) {
                                        if (!temp->prev || temp->delta_mc != temp->prev->delta_mc)
                                            bpt_y = mc_to_ypos((t_notation_obj *)x, curr_nt->midicents + round(temp->delta_mc), (t_voice *) voice);
                                        else
                                            bpt_y = mc_to_ypos((t_notation_obj *)x, note_get_screen_midicents(curr_nt) + round(temp->delta_mc), (t_voice *) voice);
                                    } else
                                        bpt_y = mc_to_ypos((t_notation_obj *) x, mc_or_screen_mc + round(temp->delta_mc), (t_voice *) voice);
                                    
                                    if (x->r_ob.velocity_handling == k_VELOCITY_HANDLING_DURATIONLINEWIDTH && x->r_ob.breakpoints_have_velocity)  {
                                        double width1 = x->r_ob.durations_line_width * grace_ratio * x->r_ob.zoom_y * (((double) (temp->prev->prev ? temp->prev->velocity : curr_nt->velocity)) / CONST_MAX_VELOCITY + 0.1);
                                        double width2 = x->r_ob.durations_line_width * grace_ratio * x->r_ob.zoom_y * (((double) temp->velocity) / CONST_MAX_VELOCITY + 0.1);
                                        notationobj_paint_doublewidth_curve((t_notation_obj *)x, g, durationlinecolor, prev_bpt_x, prev_bpt_y, bpt_x, bpt_y, temp->slope, width1, width2);
                                    } else if (x->r_ob.velocity_handling == k_VELOCITY_HANDLING_DURATIONLINEWIDTH)
                                        notationobj_paint_curve((t_notation_obj *)x, g, durationlinecolor, prev_bpt_x, prev_bpt_y, bpt_x, bpt_y, temp->slope,
                                                    rescale((double)curr_nt->velocity, 0, CONST_MAX_VELOCITY, 0.5, x->r_ob.durations_line_width *  grace_ratio * x->r_ob.zoom_y));
                                    else if ((x->r_ob.velocity_handling == k_VELOCITY_HANDLING_COLORSCALE || x->r_ob.velocity_handling == k_VELOCITY_HANDLING_ALPHACHANNEL ||
                                              x->r_ob.velocity_handling == k_VELOCITY_HANDLING_COLORSPECTRUM) && x->r_ob.breakpoints_have_velocity) {
                                        long vel1 = temp->prev->prev ? temp->prev->velocity : curr_nt->velocity;
                                        t_jrgba color_start = note_get_color((t_notation_obj *) x, curr_nt, !note_unselected && (is_chord_selected || is_note_selected || is_durationline_selected),
                                                                             is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited, vel1);
                                        t_jrgba color_end = note_get_color((t_notation_obj *) x, curr_nt, !note_unselected && (is_chord_selected || is_note_selected || is_durationline_selected),
                                                                           is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited, temp->velocity);
                                        long num_steps = MAX(labs(vel1 - temp->velocity) * 1, 1);
                                        notationobj_paint_colorgradient_curve((t_notation_obj *)x, g, color_start, color_end, prev_bpt_x, prev_bpt_y, bpt_x, bpt_y, temp->slope, x->r_ob.durations_line_width *  grace_ratio * x->r_ob.zoom_y, num_steps,
                                                                  x->r_ob.velocity_handling == k_VELOCITY_HANDLING_COLORSPECTRUM &&
                                                                  !(!note_unselected && (is_chord_selected || is_note_selected || is_durationline_selected)), vel1, temp->velocity, CONST_MAX_VELOCITY);
                                    } else
                                        notationobj_paint_curve((t_notation_obj *)x, g, durationlinecolor, prev_bpt_x, prev_bpt_y, bpt_x, bpt_y, temp->slope, x->r_ob.durations_line_width *  grace_ratio * x->r_ob.zoom_y);
                                    if (temp->rel_x_pos < 1.) prev_bpt_x = bpt_x; prev_bpt_y = bpt_y;
                                    
                                    temp = temp->next;
                                }
                                
                                // then draw all the rhomboids
                                temp = curr_nt->firstbreakpoint->next;
                                while (temp) {
                                    if (temp->rel_x_pos < 1.) {
                                        // draw line
                                        double bpt_x = chord_alignment_point_x + (note_end_pos - chord_alignment_point_x) * temp->rel_x_pos;
                                        double bpt_y = mc_to_ypos((t_notation_obj *) x, mc_or_screen_mc + round(temp->delta_mc), (t_voice *) voice);
                                        char is_bpt_selected;
                                        t_jrgba bptcolor;
                                        prev_bpt_x = bpt_x; prev_bpt_y = bpt_y;
                                        //draw bpt
                                        is_bpt_selected = (notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)temp) ^ notation_item_is_preselected((t_notation_obj *) x, (t_notation_item *)temp));
                                        if (is_bpt_selected)
                                            selected_breakpoint = temp;
                                        bptcolor = tail_get_color((t_notation_obj *) x, curr_nt, (is_chord_selected || is_note_selected || is_durationline_selected || is_bpt_selected), is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited, x->r_ob.breakpoints_have_velocity ? temp->velocity : curr_nt->velocity);
                                        if (x->r_ob.breakpoints_have_noteheads) {
                                            paint_default_small_notehead_with_accidentals((t_notation_obj *) x, view, g, bptcolor, temp->delta_mc + curr_nt->midicents, bpt_x, curr_nt, 0, (x->r_ob.breakpoints_have_velocity && x->r_ob.velocity_handling == k_VELOCITY_HANDLING_NOTEHEADSIZE) ? velocity_to_notesize_factor((t_notation_obj *) x, temp->velocity) : CONST_GRACE_CHORD_SIZE);
                                        } else {
                                            paint_rhomboid(g, x->r_ob.j_background_rgba, bptcolor, bpt_x, bpt_y, x->r_ob.breakpoints_size * 0.6 * x->r_ob.zoom_y * grace_ratio, x->r_ob.breakpoints_size * x->r_ob.zoom_y * grace_ratio, 0.9);
                                        }
                                    } else { //tail
                                        if (x->r_ob.breakpoints_have_noteheads && (!temp->prev || temp->delta_mc != temp->prev->delta_mc)) {
                                            paint_default_small_notehead_with_accidentals((t_notation_obj *) x, view, g, tailcolor, temp->delta_mc + curr_nt->midicents, note_end_pos, curr_nt, 0, (x->r_ob.breakpoints_have_velocity && x->r_ob.velocity_handling == k_VELOCITY_HANDLING_NOTEHEADSIZE) ? velocity_to_notesize_factor((t_notation_obj *) x, temp->velocity) : CONST_GRACE_CHORD_SIZE);
                                        } else { 
                                            if (x->r_ob.show_tails) {
                                                double bpt_y = mc_to_ypos((t_notation_obj *) x, note_get_screen_midicents(curr_nt) + round(temp->delta_mc), (t_voice *) voice);
                                                paint_line(g, tailcolor, note_end_pos, bpt_y - x->r_ob.breakpoints_size * 0.666 * x->r_ob.zoom_y, note_end_pos, bpt_y + x->r_ob.breakpoints_size * 0.666 * x->r_ob.zoom_y * grace_ratio, x->r_ob.durations_line_width * x->r_ob.zoom_y * grace_ratio);
                                            }
                                        }
                                    }
                                    temp = temp->next;
                                }
                                if (notation_item_is_selected((t_notation_obj *)x, (t_notation_item *)curr_nt->lastbreakpoint) ^ notation_item_is_preselected((t_notation_obj *) x, (t_notation_item *)curr_nt->lastbreakpoint))
                                    selected_breakpoint = curr_nt->lastbreakpoint;
                                
                            } else {
                                double line_y = mc_to_yposition((t_notation_obj *) x, note_get_screen_midicents(curr_nt), (t_voice *) voice); 
                                paint_line(g, durationlinecolor, note_x_real, line_y, note_end_pos, line_y, x->r_ob.durations_line_width * x->r_ob.zoom_y * grace_ratio);
                                paint_line(g, tailcolor, note_end_pos, line_y - 2. * x->r_ob.zoom_y, note_end_pos, line_y + 2. * x->r_ob.zoom_y, x->r_ob.durations_line_width * x->r_ob.zoom_y * grace_ratio);
                            }
                        }
                        
                        
                        // draw the notehead
                        if (x->r_ob.dl_spans_ties < 2 || !curr_nt->tie_from)
                            paint_notehead((t_notation_obj *) x, view, g, jf, &notecolor, curr_nt, note_x_real, note_y_real, 0, grace_ratio);
                        
                        //                        paint_line(g, build_jrgba(1, 0, 0, 0.5), chord_alignment_point_x, 0, chord_alignment_point_x, rect.height, 1.);
                        //                        dev_post("note voice %ld; alignment_pt: %.2f, stem_x: %.2f, notehead_width: %.2f", voice->v_ob.number + 1, chord_alignment_point_x, stem_x, curr_nt->notehead_uwidth * x->r_ob.zoom_y);
                        
#ifdef BACH_PAINT_IDS
                        if (curr_nt->r_it.ID > 0) {
                            char text[140];
                            snprintf_zero(text, 140, "%ld", curr_nt->r_it.ID);
                            write_text(g, jf_text_markers, build_jrgba(0.3, 0.2, 0.5, 1), text, note_x + notehead_uwidth * x->r_ob.zoom_y,
                                       note_y_real, rect.width, 40, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
                        }
#endif
                        
                        // draw dot(s) if needed
                        if (x->r_ob.show_dots) {
                            long multiplier = (is_in_voiceensemble && voice->v_ob.part_index % 2 == 1 ? 1 : -1);
                            dot_x_offset = (CONST_CHORD_DOT_USEPARATION * grace_ratio + MAX(0, curr_ch->right_uextension - curr_ch->lyrics_portion_of_right_uextension - curr_ch->dynamics_portion_of_right_uextension)) * x->r_ob.zoom_y ;
                            dot_y_offset = (curr_ch->is_grace_chord ? 9 : 1) * x->r_ob.zoom_y;
                            if (is_clef_multistaff((t_notation_obj *)x, clef) || clef == k_CLEF_PERCUSSION || clef == k_CLEF_NONE) {
                                if (scaleposition % 2 == 0)
                                    dot_y_offset += multiplier * x->r_ob.step_y;
                            } else {
                                if ((scaleposition + clef) % 2 == 0)
                                    dot_y_offset += multiplier * x->r_ob.step_y;
                            }
                            for (j=0; j<curr_ch->num_dots; j++) {
                                unicodeChar dot_char = x->r_ob.notation_typo_preferences.dot_unicode_character;
                                char dot_txt[5];
                                long dot_utf_len;
                                char *dot_utf = charset_unicodetoutf8_debug(&dot_char, 1, &dot_utf_len);
                                strncpy(dot_txt, dot_utf, 4);
                                bach_freeptr(dot_utf);
                                write_text_standard_account_for_vinset((t_notation_obj *) x, g, is_grace_chord ? jf_grace : jf, notecolor, dot_txt, stem_x + dot_x_offset, note_y + dot_y_offset);
                                dot_x_offset += CONST_DOT_DOT_USEPARATION * x->r_ob.zoom_y * grace_ratio;
                            }
                        }
                        
                        // draw tie, if there's a tie
                        if (x->r_ob.show_ties && curr_nt->tie_to && (!x->r_ob.show_durations || x->r_ob.dl_spans_ties <= 2)) {
                            const double CONST_SCORE_TIE_POSITION = 0.6;
                            char tie_direction = (curr_nt->tie_direction) ? curr_nt->tie_direction : ((curr_ch->direction == -1) ? 1 : -1);
                            double start_x = (curr_ch->num_dots) ? stem_x + dot_x_offset : note_x_real + notehead_uwidth * x->r_ob.zoom_y * CONST_SCORE_TIE_POSITION;
                            double start_y = note_y_real + ((tie_direction == 1)? -3 * x->r_ob.zoom_y : 3 * x->r_ob.zoom_y);
                            double end_x, end_y;
                            if (curr_nt->tie_to != (t_note *) WHITENULL) {
                                end_x = (curr_nt->tie_to->show_accidental) ?
                                unscaled_xposition_to_xposition((t_notation_obj *)x, curr_nt->tie_to->parent->parent->tuttipoint_reference->offset_ux +
                                                                curr_nt->tie_to->parent->stem_offset_ux) - curr_nt->notehead_uwidth * x->r_ob.zoom_y * CONST_SCORE_TIE_POSITION + curr_nt->tie_to->accidental_stem_delta_ux * x->r_ob.zoom_y :
                                unscaled_xposition_to_xposition((t_notation_obj *)x, curr_nt->tie_to->parent->parent->tuttipoint_reference->offset_ux +
                                                                curr_nt->tie_to->parent->stem_offset_ux) - curr_nt->notehead_uwidth * x->r_ob.zoom_y * CONST_SCORE_TIE_POSITION + curr_nt->tie_to->notecenter_stem_delta_ux * x->r_ob.zoom_y;
                                end_y = mc_to_yposition_in_scale((t_notation_obj *) x, note_get_screen_midicents(curr_nt->tie_to), (t_voice *) voice) + ((tie_direction == 1)? -3 * x->r_ob.zoom_y : 3 * x->r_ob.zoom_y);
                            } else {
                                if (curr_nt->parent->next)
                                end_x = unscaled_xposition_to_xposition((t_notation_obj *)x, curr_nt->parent->next->parent->tuttipoint_reference->offset_ux + curr_nt->parent->next->stem_offset_ux - curr_nt->parent->next->left_uextension - 2);
                                else
                                end_x = start_x + 20 * x->r_ob.zoom_y;
                                end_y = start_y;
                            }
                            paint_tie((t_notation_obj *) x, g, x->r_ob.j_note_rgba, start_x, start_y, end_x, end_y, tie_direction);
                            if (tie_direction == 1) {
                                if (start_y - CONST_SCORE_TIE_OUTER_UHEIGHT * x->r_ob.zoom_y < curr_ch->topmost_y)
                                curr_ch->topmost_y = start_y - CONST_SCORE_TIE_OUTER_UHEIGHT * x->r_ob.zoom_y;
                            }
                            if (tie_direction == -1) {
                                if (start_y + CONST_SCORE_TIE_OUTER_UHEIGHT * x->r_ob.zoom_y > curr_ch->bottommost_y)
                                curr_ch->bottommost_y = start_y + CONST_SCORE_TIE_OUTER_UHEIGHT * x->r_ob.zoom_y;
                            }
                        }
                        
                        // draw the auxiliary stems, if needed
                        if (x->r_ob.show_stems > 1 && rat_rat_cmp(curr_ch->figure, RAT_1OVER2) <= 0 && curr_nt->need_auxiliary_stem) {
                            if (curr_ch->direction == 1) { // stem upwards
                                paint_line(g, stemcolor, stem_x, last_note_y_real - 0.4 * octave_stem_length * grace_ratio, note_x_real, last_note_y_real - 0.2 * octave_stem_length * grace_ratio, CONST_AUX_STEM_WIDTH);
                                paint_line(g, stemcolor, note_x_real, last_note_y_real - 0.2 * octave_stem_length * grace_ratio, note_x_real, note_y_real - 0.5 * x->r_ob.step_y * grace_ratio, CONST_AUX_STEM_WIDTH);
                            } else if (curr_ch->direction == -1) { // stem downwards
                                paint_line(g, stemcolor, stem_x, first_note_y_real + 0.4 * octave_stem_length * grace_ratio, note_x_real, first_note_y_real + 0.2 * octave_stem_length * grace_ratio, CONST_AUX_STEM_WIDTH);
                                paint_line(g, stemcolor, note_x_real, first_note_y_real + 0.2 * octave_stem_length * grace_ratio, note_x_real, note_y_real + 0.5 * x->r_ob.step_y * grace_ratio, CONST_AUX_STEM_WIDTH);
                            } else
                            object_warn((t_object *)x, "Warning: chord direction undefined!");
                        }
                        
                        // need to put accidentals?
                        paint_noteaccidentals((t_notation_obj *) x, g, jf_acc, jf_text_fractions, jf_acc_bogus, &accidentalcolor, curr_nt,
                                              get_voice_clef((t_notation_obj *)x, (t_voice *)voice), note_y_real, stem_x,
                                              &accidental_top_extension, &accidental_bottom_extension);
                        
                        // need to put articulations
                        if (x->r_ob.show_articulations){
                            // OLD-WAY: note-attached articulations.
                            for (i = 0; i < curr_nt->num_articulations; i++) {
                                char is_articulation_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)(&(curr_nt->articulation[i])));
                                t_jrgba articulationcolor = articulation_get_color((t_notation_obj *) x, curr_ch, is_articulation_selected, is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited);
                                paint_articulation((t_notation_obj *) x, g, &articulationcolor, &curr_nt->articulation[i], (t_notation_item *)curr_nt, curr_ch->direction, stem_x, note_x_real, note_y_real, notehead_uwidth, end_pos, part_direction);
                            }
                            
                            // NEW WAY: slot-attached articulations
                            if (x->r_ob.link_articulations_to_slot > 0 && x->r_ob.link_articulations_to_slot < CONST_MAX_SLOTS) {
                                long s = x->r_ob.link_articulations_to_slot - 1;
                                if (x->r_ob.slotinfo[s].slot_type == k_SLOT_TYPE_ARTICULATIONS) {
                                    t_slotitem *item;
                                    for (item = curr_nt->slot[s].firstitem; item; item = item->next) {
                                        t_articulation *art = (t_articulation *)item->item;
                                        double art_end_pos = end_pos;
                                        if (x->r_ob.articulations_typo_preferences.artpref[art->articulation_ID].options & k_ARTICULATION_OPTION_SPAN_TIES) {
                                            t_note *last_tie = note_get_last_in_tieseq(curr_nt);
                                            if (last_tie && last_tie != curr_nt)
                                            art_end_pos = unscaled_xposition_to_xposition((t_notation_obj *)x, last_tie->parent->parent->tuttipoint_reference->offset_ux + last_tie->parent->stem_offset_ux + last_tie->parent->duration_ux);
                                        }
                                        char is_articulation_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)art);
                                        t_jrgba articulationcolor = articulation_get_color((t_notation_obj *) x, curr_ch, is_articulation_selected, is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited);
                                        paint_articulation((t_notation_obj *) x, g, &articulationcolor, art, (t_notation_item *)curr_nt, curr_ch->direction, stem_x, note_x_real, note_y_real, notehead_uwidth, art_end_pos, part_direction);
                                    }
                                }
                            }
                        }
                        
                    }
                    
                    
                    
                } else if (x->r_ob.show_rests > 0) { // it is a rest (sorry... "pause" is used sometimes instead of rest... italian-to-english poorly made translation...)
                    
                    char just_this_rest_in_the_measure = false; // tells if the measure is made up by a single rest
					double pause_x, pause_real_y, pause_y, dot_x_offset, dot_y_offset;
					unicodeChar pause_unicode_char;
					char pausechars[15]; 
					long pausechars_len; 
					char *pausechars_utf;
					char j, num_dots; 
					
                    stemcolor = stem_get_color((t_notation_obj *) x, curr_ch, is_chord_selected, is_chord_played, is_chord_locked, is_chord_muted, is_chord_solo, is_chord_linear_edited);

                    if (curr_ch->parent->num_chords == 1 && x->r_ob.notation_cursor.measure != curr_ch->parent)
                        just_this_rest_in_the_measure = true;
                    
                    if (!just_this_rest_in_the_measure || x->r_ob.show_rests == k_SHOW_RESTS_ALWAYS || x->r_ob.is_linear_editing) {
                        char whole_rest_measure = is_measure_single_whole_rest((t_notation_obj *)x, curr_ch->parent);
                        char rest_needs_ledger_line = 0;
                        
                        if (rat_rat_cmp(curr_ch->figure, RAT_1OVER2) == 0 && !is_rest_within_staff((t_notation_obj *)x, curr_ch)) // (curr_ch->float_steps > 4 || curr_ch->float_steps <= -4))
                            rest_needs_ledger_line = -1;
                        else if (rat_long_cmp(curr_ch->figure, 1) == 0 && !is_rest_within_staff((t_notation_obj *)x, curr_ch)) // (curr_ch->float_steps >= 4 || curr_ch->float_steps < -4))
                            rest_needs_ledger_line = 1;
                        
                        // get colors
                        notecolor = rest_get_color((t_notation_obj *) x, curr_ch, is_chord_selected, x->r_ob.play_rests ? is_chord_played : false, is_chord_locked, x->r_ob.play_rests ? is_chord_muted : false, x->r_ob.play_rests ? is_chord_solo : false, is_chord_linear_edited); // rests cannot be muted
                        
                        long rest_scaleposition = 0;
                        double rest_uwidth = rest_get_uwidth((t_notation_obj *) x, curr_ch->figure);
                        double rest_semiwidth = rest_uwidth * grace_ratio * x->r_ob.zoom_y / 2.;
                        pause_x = chord_alignment_point_x - rest_semiwidth + x->r_ob.notation_typo_preferences.rest_ux_shift * grace_ratio * x->r_ob.zoom_y;
                        
                        pause_real_y = rest_get_floating_yposition((t_notation_obj *) x, curr_ch, NULL, &rest_scaleposition);
//                        curr_ch->firstnote_y_real = curr_ch->lastnote_y_real = pause_real_y;
                        pause_y = pause_real_y + ((is_grace_chord ? -22.5 : -34.) + x->r_ob.notation_typo_preferences.rest_uy_shift) * x->r_ob.zoom_y;
                        last_note_y_real = staff_top; first_note_y_real = staff_top; // abuse, but for tuplets handling
                        curr_ch->topmost_y = curr_ch->topmost_y_noacc = pause_real_y - rest_get_top_extension_in_steps((t_notation_obj *) x, curr_ch->figure) * x->r_ob.step_y;
                        curr_ch->bottommost_y = curr_ch->bottommost_y_noacc = pause_real_y + rest_get_bottom_extension_in_steps((t_notation_obj *) x, curr_ch->figure) * x->r_ob.step_y;
                        

                        
                        // background rest slots
                        double slot_zoom_y = x->r_ob.zoom_y * (x->r_ob.bgslot_zoom/100.);
                        double bg_slot_start_x = just_this_rest_in_the_measure ? 0 : chord_alignment_point_x;
                        double bg_slot_text_start_x = chord_alignment_point_x + 2*rest_semiwidth;
                        paint_background_slots((t_notation_obj *) x, g, bg_slot_start_x, pause_real_y, end_pos - bg_slot_start_x, jf_text_small, jf_text_smallbold, jf_small_dynamics, jf_small_dynamics_roman, (t_notation_item *)curr_ch,
                                               bg_slot_text_start_x  + x->r_ob.background_slot_text_ushift[0] * slot_zoom_y,
                                               pause_real_y + x->r_ob.background_slot_text_ushift[1] * slot_zoom_y,
                                               bg_slot_text_start_x  + x->r_ob.background_slot_text_ushift[0] * slot_zoom_y,
                                               pause_real_y - (1.3 * x->r_ob.slot_background_font_size - 0.5) * slot_zoom_y + x->r_ob.background_slot_text_ushift[1] * slot_zoom_y, -1);
                        

                        
                        // draw the rest
                        pause_unicode_char = rest_get_unicode_character((t_notation_obj *) x, whole_rest_measure ? long2rat(1) : curr_ch->figure);
                        pausechars_utf = charset_unicodetoutf8_debug(&pause_unicode_char, 1, &pausechars_len);
                        strncpy(pausechars, pausechars_utf, 14);
                        bach_freeptr(pausechars_utf);
                        
                        if (rest_needs_ledger_line != 0) {
                            double ledger_line_y = scaleposition_to_yposition((t_notation_obj *)x, (rest_needs_ledger_line > 0 ? rest_scaleposition + 2 : rest_scaleposition), (t_voice *)voice);
                            paint_line(g, notecolor, chord_alignment_point_x - rest_semiwidth * 1.4, ledger_line_y, chord_alignment_point_x + rest_semiwidth * 1.4, ledger_line_y, 0.7);
                        }

                        write_text_standard_account_for_vinset((t_notation_obj *) x, g, is_grace_chord ? jf_grace : jf, notecolor, pausechars, pause_x, pause_y);
                        
                        // draw additional stem if rest is beamed (and if stem is requested)
                        if (x->r_ob.show_half_stem_for_beamed_rests && curr_ch->beams_depth > 0) {
                            double tip_y = staff_top + curr_ch->stemtip_stafftop_uy * x->r_ob.zoom_y;
                            paint_line(g, stemcolor, stem_x, curr_ch->direction == 1 ? curr_ch->topmost_y : curr_ch->bottommost_y, stem_x, tip_y, CONST_STEM_WIDTH);
                        }
                        
                        // draw dot(s) if needed
                        if (x->r_ob.show_dots) {
                            num_dots = whole_rest_measure ? 0 : curr_ch->num_dots;
                            dot_x_offset = 2 * rest_semiwidth + CONST_REST_DOT_USEPARATION * grace_ratio;
                            dot_y_offset = - x->r_ob.step_y; //(scaleposition % 2 == 0) ? x->r_ob.step_y : 0.;
                            for (j=0; j<num_dots; j++) {
                                unicodeChar dot_char = x->r_ob.notation_typo_preferences.dot_unicode_character;
                                char dot_txt[5];
                                long dot_utf_len;
                                char *dot_utf = charset_unicodetoutf8_debug(&dot_char, 1, &dot_utf_len);
                                strncpy(dot_txt, dot_utf, 4);
                                bach_freeptr(dot_utf);
                                write_text_standard_account_for_vinset((t_notation_obj *) x, g, is_grace_chord ? jf_grace : jf, notecolor, dot_txt, pause_x + dot_x_offset, pause_y + dot_y_offset);
                                dot_x_offset += CONST_DOT_DOT_USEPARATION * x->r_ob.zoom_y * grace_ratio;
                            }
                        }
                        
                        
#ifdef BACH_CHORDS_HAVE_SLOTS
                        // need to put articulations ?
                        if (x->r_ob.show_articulations){
                            // NEW WAY: slot-attached articulations
                            if (x->r_ob.link_articulations_to_slot > 0 && x->r_ob.link_articulations_to_slot < CONST_MAX_SLOTS) {
                                long s = x->r_ob.link_articulations_to_slot - 1;
                                if (x->r_ob.slotinfo[s].slot_type == k_SLOT_TYPE_ARTICULATIONS) {
                                    t_slotitem *item;
                                    for (item = curr_ch->slot[s].firstitem; item; item = item->next) {
                                        t_articulation *art = (t_articulation *)item->item;
                                        double art_end_pos = end_pos;
                                        if (x->r_ob.articulations_typo_preferences.artpref[art->articulation_ID].options & k_ARTICULATION_OPTION_SPAN_REST_SEQUENCES) {
                                            t_chord *lastrest = rest_get_last_in_seq(curr_ch, false);
                                            if (lastrest && lastrest != curr_ch)
                                                art_end_pos = unscaled_xposition_to_xposition((t_notation_obj *)x, lastrest->parent->tuttipoint_reference->offset_ux + lastrest->stem_offset_ux + lastrest->duration_ux);
                                        }
                                        char is_articulation_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)art);
                                        t_jrgba articulationcolor = articulation_get_color((t_notation_obj *) x, curr_ch, is_articulation_selected, x->r_ob.play_rests ? is_chord_played : false, is_chord_locked, x->r_ob.play_rests ? is_chord_muted : false, x->r_ob.play_rests ? is_chord_solo : false, is_chord_linear_edited);
                                        paint_articulation((t_notation_obj *) x, g, &articulationcolor, art, (t_notation_item *)curr_ch, is_in_voiceensemble ? (voice->v_ob.part_index % 2 == 0 ? -1 : 1) : -1, stem_x, chord_alignment_point_x, pause_real_y, rest_uwidth, art_end_pos, part_direction);
                                    }
                                }
                            }
                        }
#endif
                        
                        
                    }
                }
                
                
                if (x->r_ob.show_annotations){
                    if (x->r_ob.link_annotation_to_slot > 0 && x->r_ob.link_annotation_to_slot < CONST_MAX_SLOTS) {
                        long s = x->r_ob.link_annotation_to_slot - 1;
                        for (curr_nt = curr_ch->firstnote; curr_nt; curr_nt = curr_nt->next) {
                            if (notation_item_get_slot_firstitem((t_notation_obj *)x, (t_notation_item *)curr_nt, s) ||
                                (last_annotation_text[0] && (e_annotations_filterdup_modes)x->r_ob.thinannotations != k_ANNOTATIONS_FILTERDUP_DONT)) {
                                char is_note_locked = notation_item_is_globally_locked((t_notation_obj *)x, (t_notation_item *)curr_nt);
                                char is_note_muted = notation_item_is_globally_muted((t_notation_obj *)x, (t_notation_item *)curr_nt);
                                char is_note_solo = notation_item_is_globally_solo((t_notation_obj *)x, (t_notation_item *)curr_nt);
                                char is_note_played = x->r_ob.highlight_played_notes ? (should_element_be_played((t_notation_obj *) x, (t_notation_item *)curr_nt) && (curr_ch->played || curr_nt->played)) : false;
                                t_jrgba annotationcolor = annotation_get_color((t_notation_obj *) x, curr_ch, false, is_note_played, is_note_locked, is_note_muted, is_note_solo, is_chord_linear_edited);
                                double left_corner_x = curr_nt->center.x - notehead_get_uwidth((t_notation_obj *) x, curr_ch->r_sym_duration, curr_nt, true) / 2.;
                                paint_annotation_from_slot((t_notation_obj *) x, g, &annotationcolor, (t_notation_item *)curr_nt, left_corner_x, s, jf_ann, staff_top, last_annotation_text, &annotation_sequence_start_x_pos, &annotation_sequence_end_x_pos, &annotation_line_y_pos);
                            }
                        }
                    }
                }
                
                if (x->r_ob.show_dynamics || x->r_ob.show_hairpins){
                    if (chord_has_dynamics(curr_ch)) {
                        t_dynamics *dyn = chord_get_dynamics(curr_ch);
                        t_notation_item *nitem = (t_notation_item *)curr_ch;
                        char is_item_locked = notation_item_is_globally_locked((t_notation_obj *)x, nitem);
                        char is_item_muted = notation_item_is_globally_muted((t_notation_obj *)x, nitem);
                        char is_item_solo = notation_item_is_globally_solo((t_notation_obj *)x, nitem);
                        char is_item_played = x->r_ob.highlight_played_notes ? (should_element_be_played((t_notation_obj *) x, nitem) && curr_ch->played) : false;
                        char is_dynamics_selected = notation_item_is_selected((t_notation_obj *) x, nitem) || notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)dyn);
                        
                        t_jrgba dynamicscolor = dynamics_get_color((t_notation_obj *) x, curr_ch, is_dynamics_selected, is_item_played, is_item_locked, is_item_muted, is_item_solo, is_chord_linear_edited);
                        double chord_alignment_x = chord_get_alignment_x((t_notation_obj *)x, curr_ch);
                        
                        double end_pos = chord_alignment_x + deltauxpixels_to_deltaxpixels((t_notation_obj *)x, curr_ch->duration_ux);
                        double orig_end_pos = end_pos;
                        
                        t_notation_item *dyn_nitem = notation_item_get_bearing_dynamics((t_notation_obj *)x, nitem, x->r_ob.link_dynamics_to_slot - 1);
                        t_chord *next_chord = curr_ch->next;
                        
                        if (dyn_nitem->type == k_NOTE) {
                            t_note *last_tie = note_get_last_in_tieseq((t_note *)dyn_nitem);
                            if (last_tie) {
                                end_pos = unscaled_xposition_to_xposition((t_notation_obj *)x, last_tie->parent->parent->tuttipoint_reference->offset_ux + last_tie->parent->stem_offset_ux + last_tie->parent->duration_ux - 6);
                                next_chord = last_tie->parent->next;
                            }
                        }
                        
                        if (next_chord && chord_get_dynamics(next_chord))
                            end_pos -= deltauxpixels_to_deltaxpixels((t_notation_obj *)x, chord_get_dynamics(next_chord)->dynamics_left_uext);
                        
                        double dynamics_duration_x = (dynamics_span_ties ? end_pos : orig_end_pos) - chord_alignment_x;
                        char must_paint = !chord_is_all_tied_from(curr_ch, false);
                        if (x->r_ob.link_dynamics_to_slot > 0 && x->r_ob.link_dynamics_to_slot <= CONST_MAX_SLOTS && !x->r_ob.slotinfo[x->r_ob.link_dynamics_to_slot-1].slot_singleslotfortiednotes)
                            must_paint = true;
                        if (must_paint)
                                paint_dynamics((t_notation_obj *)x, g, &dynamicscolor, nitem, chord_alignment_x, dynamics_duration_x, dyn, jf_dynamics, jf_dynamics_roman, x->r_ob.dynamics_font_size * x->r_ob.zoom_y, x->r_ob.dynamics_roman_font_size * x->r_ob.zoom_y, staff_bottom - x->r_ob.dynamics_uy_pos * x->r_ob.zoom_y, &curr_hairpin_start_x, &curr_hairpin_type, &prev_hairpin_color, &prev_hairpin_dontpaint, 0, 0, false);
                    }
                }

                
                // paint chord label rectangles
                if (x->r_ob.show_label_families == k_SHOW_LABEL_FAMILIES_SINGLETONS)
                    paint_chord_label_families((t_notation_obj *)x, view, g, curr_ch, label_family_chord_shape_radius);
                
                
                // OLD WAY:
				// need to put chord-attached articulations ?
				if (x->r_ob.show_articulations){
					for (i = 0; i < curr_ch->num_articulations; i++) {
						char is_articulation_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)(&(curr_ch->articulation[i])));
						t_jrgba articulationcolor = articulation_get_color((t_notation_obj *) x, curr_ch, is_articulation_selected, is_chord_played, is_chord_locked, is_chord_muted, is_chord_solo, is_chord_linear_edited);
                        paint_articulation((t_notation_obj *) x, g, &articulationcolor, &curr_ch->articulation[i], (t_notation_item *)curr_ch,
										   curr_ch->r_sym_duration.r_num >= 0 ? curr_ch->direction : 0, stem_x,
										   (curr_ch->r_sym_duration.r_num >= 0) ? (curr_ch->direction >= 0 ? stem_x - chord_first_notehead_uwidth * x->r_ob.zoom_y /2. : stem_x + chord_first_notehead_uwidth * x->r_ob.zoom_y /2.) : stem_x,
										   (curr_ch->r_sym_duration.r_num >= 0) ? (curr_ch->direction >= 0 ? first_note_y_real : last_note_y_real) : first_note_y_real,
										   chord_first_notehead_uwidth * x->r_ob.zoom_y, end_pos, part_direction);
					}
				}
				
				// lyrics word extensions?
				if (x->r_ob.show_lyrics && x->r_ob.show_lyrics_word_extensions) {
					if (lyrics_word_extension_going_on && !lyrics_dashed_going_on &&
						(curr_ch->r_sym_duration.r_num < 0 || (curr_ch->lyrics && curr_ch->lyrics->label && strlen(curr_ch->lyrics->label) > 0)) &&
						curr_ch != chord_get_next(lyrics_word_extensions_start_chord)) {
						t_chord *prevch = chord_get_prev(curr_ch);
						if (prevch) {
							double line_y = get_lyrics_word_extension_y_pos((t_notation_obj *) x, staff_bottom);
							double x1 = unscaled_xposition_to_xposition((t_notation_obj *) x, left_word_extension_ux);
							double x2 = prevch->stem_x;
							paint_line(g, x->r_ob.j_lyrics_rgba, x1, line_y, x2, line_y, 0.7);
							lyrics_word_extension_going_on = false;
						}
					} else if (lyrics_word_extension_going_on && curr_ch->r_sym_duration.r_num < 0)
						lyrics_word_extension_going_on = false;
				}
				
				// lyrics?
				if (curr_ch->lyrics && curr_ch->lyrics->label && strlen(curr_ch->lyrics->label) > 0 && x->r_ob.show_lyrics) {
					double pos_y = staff_bottom - x->r_ob.lyrics_uy_pos * x->r_ob.zoom_y;
					double lyrics_end_ux;
					if (!(x->r_ob.is_editing_type == k_LYRICS && x->r_ob.is_editing_chord == curr_ch)){
						double pos_x = curr_ch->stem_x + (curr_ch->direction == 1 ? -0.5 : 0.5) * chord_get_mainside_notehead_uwidth((t_notation_obj *) x, curr_ch->r_sym_duration, curr_ch) + curr_ch->lyrics->lyrics_ux_shift * x->r_ob.zoom_y;
						char is_lyrics_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_ch) || notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_ch->lyrics);
                        t_jrgba lyrics_color = x->r_ob.j_lyrics_rgba;
                        change_color_depending_on_playlockmute((t_notation_obj *) x, &lyrics_color, is_lyrics_selected, is_chord_played, is_chord_locked, is_chord_muted, is_chord_solo, is_chord_linear_edited);
						write_text_standard_account_for_vinset((t_notation_obj *) x, g, jf_lyrics, lyrics_color, curr_ch->lyrics->label, pos_x, pos_y);
					}
					
					if (lyrics_dashed_going_on) {
						double this_left_ux = chord_get_alignment_ux((t_notation_obj *) x, curr_ch) + curr_ch->lyrics->lyrics_ux_shift;
						long num_dash_needed = MAX(0, round((this_left_ux - left_dashed_ux) * CONST_NUM_DASH_PER_UX * x->r_ob.zoom_x / x->r_ob.zoom_y)); 
						
						if (num_dash_needed == 0 && (this_left_ux - left_dashed_ux) > CONST_UX_MINIMUM_SPACE_FOR_DASH * 1.25)
							num_dash_needed = 1;
						
						if (num_dash_needed == 1) {
							double ux_module = (this_left_ux - left_dashed_ux - CONST_UX_MINIMUM_SPACE_FOR_DASH)/2;
							write_text_standard_account_for_vinset((t_notation_obj *) x, g, jf_lyrics, x->r_ob.j_lyrics_rgba, "-", unscaled_xposition_to_xposition((t_notation_obj *) x, left_dashed_ux + ux_module), pos_y);
						} else if (num_dash_needed > 1) {
							double ux_module = (this_left_ux - left_dashed_ux)/num_dash_needed;
							for (i = 0; i < num_dash_needed; i++){
								double this_x = unscaled_xposition_to_xposition((t_notation_obj *) x, left_dashed_ux + ux_module/2. + i * ux_module);
								write_text_standard_account_for_vinset((t_notation_obj *) x, g, jf_lyrics, x->r_ob.j_lyrics_rgba, "-", this_x, pos_y);
							}
						}
					}
					
					lyrics_dashed_going_on = curr_ch->lyrics->lyrics_dashed_extension;
					lyrics_end_ux = chord_get_alignment_ux((t_notation_obj *) x, curr_ch) + curr_ch->lyrics->lyrics_ux_shift + curr_ch->lyrics->lyrics_uwidth;
					if (lyrics_dashed_going_on)
						left_dashed_ux = lyrics_end_ux;
					
					if (x->r_ob.show_lyrics_word_extensions && !curr_ch->lyrics->lyrics_dashed_extension) {
						lyrics_word_extensions_start_chord = curr_ch;
						lyrics_word_extension_going_on = true;
						left_word_extension_ux = lyrics_end_ux + 1;
					}
				}
			}
			
			if (is_grace_chord)
				jfont_destroy_debug(jf_grace);
		}
		
		
		// BEAMS AND TUPLETS
        if (x->r_ob.show_beams) {
            t_beam *beam;
            for (beam = curr_meas->firstbeam; beam; beam = beam->next){
                char pl1 = chord_get_placement_in_screen((t_notation_obj *) x, beam->beam_start_chord);
                char pl2 = chord_get_placement_in_screen((t_notation_obj *) x, beam->beam_end_chord);
                t_chord *firstbeamchord = beam->beam_start_chord;
                char direction = 0;
                double grace_ratio = beam->grace ? CONST_GRACE_CHORD_SIZE : 1;
                
                while (firstbeamchord && firstbeamchord->next && firstbeamchord != beam->beam_end_chord && firstbeamchord->r_sym_duration.r_num < 0)
                    firstbeamchord = firstbeamchord->next;
                
                direction = firstbeamchord->direction;
                if (pl1 == 0 || pl2 == 0 || (pl1 == -1 && pl2 == 1)) {
                    // we need to paint the beam, cause either one of the start/end chord is in the screen, or the starting chord is
                    // hidden at left and the ending chord is hidden at right
                    if (beam->has_beam_line) {
                        if (beam->beam_start_chord == beam->beam_end_chord){ // i.e. beam->is_tick
                            double tickpoint_beam_ys = staff_top + beam->beam_end_uy * x->r_ob.zoom_y;
                            double tickpoint_beam_xe = beam->beam_start_chord->stem_x + beam->tick_direction * CONST_BEAMINGS_TICK_DEFAULT_UEXTENSION * x->r_ob.zoom_y * grace_ratio;
                            double tickpoint_beam_ye = tickpoint_beam_ys - beam->slope * beam->tick_direction * CONST_BEAMINGS_TICK_DEFAULT_UEXTENSION * x->r_ob.zoom_y * grace_ratio / x->r_ob.zoom_x;
                            paint_beam_line((t_notation_obj *) x, g, beamcolor, beam->beam_start_chord->stem_x, tickpoint_beam_ys, tickpoint_beam_xe, tickpoint_beam_ye, CONST_BEAMING_UWIDTH * x->r_ob.zoom_y * grace_ratio, direction);
                        } else
                            paint_beam_line((t_notation_obj *) x, g, beamcolor, beam->beam_start_chord->stem_x, staff_top + beam->beam_start_uy * x->r_ob.zoom_y,
                                            beam->beam_end_chord->stem_x, staff_top + beam->beam_end_uy * x->r_ob.zoom_y, CONST_BEAMING_UWIDTH * x->r_ob.zoom_y * grace_ratio, direction);
                    }
                    
                    // slash beam?
                    if (beam->grace && x->r_ob.slash_grace_beams && beam->depth == 1)
                        paint_line(g, beamcolor, beam->beam_start_chord->stem_x - 3 * x->r_ob.zoom_y, staff_top + beam->beam_start_uy * x->r_ob.zoom_y + 5 * x->r_ob.zoom_y * beam->direction - (beam->direction == -1 ? x->r_ob.zoom_y : 0),
                                   beam->beam_start_chord->stem_x + 4 * x->r_ob.zoom_y, staff_top + beam->beam_start_uy * x->r_ob.zoom_y - 3 * x->r_ob.zoom_y * beam->direction - (beam->direction == -1 ? x->r_ob.zoom_y : 0), 1);
                    
                    if (beam->is_tuplet){
                        double x1t = (beam->beam_start_chord->stem_x + beam->beam_end_chord->stem_x)/2. + beam->tuplet_text1_delta_ux * x->r_ob.zoom_y;
                        double y1t = staff_top + beam->tuplet_text1_uy * x->r_ob.zoom_y;
                        double cur_x = x1t;
                        double tt_width1, tt_height1, tt_width2, tt_height2, tt_width_fig;
                        
                        jfont_text_measure(jf_tuplets, beam->tuplet_text1, &tt_width1, &tt_height1);
                        
                        // number
                        if (!beam->tuplet_text2[0])
                            write_text_standard_singleline(g, jf_tuplets, tupletcolor, beam->tuplet_text1, x1t, y1t, rect.width - x1t, rect.height - y1t);
                        else {
                            jfont_text_measure(jf_tuplets, beam->tuplet_text2, &tt_width2, &tt_height2);
                            write_text_standard_singleline(g, jf_tuplets, tupletcolor, beam->tuplet_text1, x1t, y1t, rect.width - x1t, rect.height - y1t);
                            cur_x += tt_width1 + 2. * x->r_ob.zoom_y;
                            paint_small_note((t_notation_obj *) x, g, tupletcolor, beam->tuplet_graphical_unit, cur_x, y1t + 6 * x->r_ob.zoom_y , CONST_FIGURE_IN_TUPLET_LEGEND_RATIO, &tt_width_fig);
                            cur_x += tt_width_fig;
                            write_text_standard_singleline(g, jf_tuplets, tupletcolor, beam->tuplet_text2, cur_x, y1t, rect.width - cur_x, rect.height - y1t);
                            cur_x += tt_width2;
                        }
                        
                        // bracket
                        if (beam->tuplet_show_bracket && x->r_ob.tuplet_shape != k_TUPLET_SHAPE_NONE){
                            double x1 = beam->beam_start_chord->stem_x;
                            double x2 = beam->beam_end_chord->stem_x;
                            double y1 = staff_top + beam->beam_start_uy * x->r_ob.zoom_y;
                            double y2 = staff_top + beam->beam_end_uy * x->r_ob.zoom_y;
                            double xm1, ym1, xm2, ym2; // middle points for line
                            
                            if (beam->direction == -1 && beam->beam_start_chord->direction == 1)
                                x1 -= notehead_get_uwidth((t_notation_obj *) x, beam->beam_start_chord->r_sym_duration, NULL, false) * x->r_ob.zoom_y;
                            if (beam->direction == 1 && beam->beam_end_chord->direction == -1)
                                x2 += notehead_get_uwidth((t_notation_obj *) x, beam->beam_end_chord->r_sym_duration, NULL, false) * x->r_ob.zoom_y;
                            
                            xm1 = x1t - 1 * x->r_ob.zoom_y;
                            ym1 = rescale(xm1, x1, x2, y1, y2);
                            xm2 = (beam->tuplet_text2[0] ? cur_x : x1t + tt_width1) + 1 * x->r_ob.zoom_y;
                            ym2 = rescale(xm2, x1, x2, y1, y2);
                            
                            if (x->r_ob.tuplet_shape == k_TUPLET_SHAPE_BRACKET) {
                                if (beam->dashed) {
                                    paint_dashed_line(g, tupletcolor, x1, y1, xm1, ym1, 1, 4);
                                    paint_dashed_line(g, tupletcolor, xm2, ym2, x2, y2, 1, 4);
                                } else {
                                    paint_line(g, tupletcolor, x1, y1, xm1, ym1, 1);
                                    paint_line(g, tupletcolor, xm2, ym2, x2, y2, 1);
                                }
                                paint_line(g, tupletcolor, x1, y1, x1, y1 + beam->direction * CONST_TUPLET_TICK_UHEIGHT * x->r_ob.zoom_y, 1);
                                paint_line(g, tupletcolor, x2, y2, x2, y2 + beam->direction * CONST_TUPLET_TICK_UHEIGHT * x->r_ob.zoom_y, 1);
                                
                            } else if (x->r_ob.tuplet_shape == k_TUPLET_SHAPE_SLUR) {
                                paint_tuplet_slur(g, tupletcolor, x1, y1 + beam->direction * CONST_TUPLET_TICK_UHEIGHT * x->r_ob.zoom_y, x1, y1, xm1, ym1, 1);
                                paint_tuplet_slur(g, tupletcolor, x2, y2 + beam->direction * CONST_TUPLET_TICK_UHEIGHT * x->r_ob.zoom_y, x2, y2, xm2, ym2, 1);
                            }
                            
                        }
                    }
                }
            }
        }
            
            // draw the tree
            if (x->r_ob.show_rhythmic_tree){
                char direction = (voiceensemble_get_numparts((t_notation_obj *)x, (t_voice *)voice) > 1 ? (voice->v_ob.part_index % 2 == 0 ? 1 : -1) : 1);
                double start_pos;
                if (direction > 0)
                    start_pos = staff_top - curr_meas->rhythmic_tree->l_depth * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * x->r_ob.zoom_y;
                else
                    start_pos = staff_bottom + curr_meas->rhythmic_tree->l_depth * CONST_SCORE_BEAMING_TREE_STEP_UHEIGHT * x->r_ob.zoom_y;
                void *data[4];
                data[0] = (t_notation_obj *)x;
                data[1] = g;
                data[2] = (direction > 0 ? &staff_top : &staff_bottom);
                data[3] = &start_pos;
                llll_funall(curr_meas->rhythmic_tree, show_rhythmic_tree_fn, data, 1, -1, FUNALL_PROCESS_WHOLE_SUBLISTS);
            }
        
        
        // linear_edit cursor?
        if (measure_linear_edited){
            double yy, ypos = this_middleC_y - x->r_ob.notation_cursor.step * x->r_ob.step_y;
            double xpos = unscaled_xposition_to_xposition((t_notation_obj *) x, get_linear_edit_cursor_ux_position(x));
            paint_line(g, x->r_ob.j_linear_edit_rgba, xpos, staff_top, xpos, staff_bottom, 2);
            if (ypos < staff_top) {
                for (yy = staff_top - x->r_ob.step_y * 2; yy > ypos; yy -= x->r_ob.step_y * 2)
                    paint_line(g, x->r_ob.j_auxiliarystaves_rgba, xpos - 1.3 * x->r_ob.zoom_y, yy, xpos + 1.3 * x->r_ob.zoom_y, yy, 1);
                paint_line(g, x->r_ob.j_linear_edit_rgba, xpos, staff_top, xpos, ypos, 1);
            }
            if (ypos > staff_bottom) {
                for (yy = staff_bottom + x->r_ob.step_y * 2; yy < ypos; yy += x->r_ob.step_y * 2)
                    paint_line(g, x->r_ob.j_mainstaves_rgba, xpos - 1.3 * x->r_ob.zoom_y, yy, xpos + 1.3 * x->r_ob.zoom_y, yy, 1);
                paint_line(g, x->r_ob.j_linear_edit_rgba, xpos, staff_bottom, xpos, ypos, 1);
            }
            
            paint_line(g, x->r_ob.j_linear_edit_rgba, xpos - 2 * x->r_ob.zoom_y, ypos, xpos + 2 * x->r_ob.zoom_y, ypos, 2);
            
            // speedy edit tuplet insertion?
            if (x->r_ob.num_speedy_tuplets > 0){
                char tuplettxt[10 * CONST_MAX_NESTED_TUPLETS_FOR_SPEEDY];
                long i, cur = 0;
                for (i = 0; i < x->r_ob.num_speedy_tuplets; i++){
                    if (x->r_ob.speedy_tuplet_numerator_defined[i])
                        cur += snprintf_zero(tuplettxt + cur, 10 * CONST_MAX_NESTED_TUPLETS_FOR_SPEEDY - cur, "%ld:%ld ", x->r_ob.speedy_tuplet[i].r_den, x->r_ob.speedy_tuplet[i].r_num);
                    else if (x->r_ob.defining_numerator && i == x->r_ob.num_speedy_tuplets - 1)
                        cur += snprintf_zero(tuplettxt + cur, 10 * CONST_MAX_NESTED_TUPLETS_FOR_SPEEDY - cur, "%ld: ", x->r_ob.speedy_tuplet[i].r_den);
                    else
                        cur += snprintf_zero(tuplettxt + cur, 10 * CONST_MAX_NESTED_TUPLETS_FOR_SPEEDY - cur, "%ld ", x->r_ob.speedy_tuplet[i].r_den);
                }
                double width, height;
                jfont_text_measure(jf_text_smallbold, tuplettxt, &width, &height);
                write_text(g, jf_text_smallbold, x->r_ob.j_linear_edit_rgba, tuplettxt, xpos - width/2., staff_top - height - 2 * x->r_ob.zoom_y, width + 20, height + 20, JGRAPHICS_TEXT_JUSTIFICATION_TOPLEFT, true, false);
            }
        }
        
        
        if (voice->v_ob.part_index == 0) {
            // draw end barline
            end_barline_y = staff_bottom;
            measure_across = false;
            end_barline_x = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, tuttipoint_ux + curr_meas->start_barline_offset_ux + curr_meas->width_ux));
            
            if (x->r_ob.spacing_type == k_SPACING_PROPORTIONAL) {
                end_barline_x += x->r_ob.barline_ushift_for_proportional_spacing * x->r_ob.zoom_y; // barline_ushift_for_proportional_spacing is not exposed, so it's constantly 0
            }
            
            barline_type = curr_meas->end_barline->barline_type;
            if (barline_type <= 0 || barline_type == 'a') // automatic
                barline_type = (curr_meas->next) ? k_BARLINE_NORMAL : k_BARLINE_FINAL;
            char barline_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_meas->end_barline);
            if (x->r_ob.show_barlines == 0)
                barline_type = k_BARLINE_HIDDEN;
            else if (x->r_ob.draw_barlines_across_staves && is_barline_tuttipoint((t_notation_obj *)x, curr_meas->end_barline)) {
                // check if any of the tuttipoint barlines is selected
                t_tuttipoint *tpt = curr_meas->tuttipoint_reference;
                long i;
                for (i = 0; i < x->r_ob.num_voices; i++) {
                    t_measure *temp = tpt->measure[i];
                    while (temp && temp->next && temp->next->tuttipoint_reference == tpt)
                        temp = temp->next;
#ifdef CONFIGURATION_Development
                    if (!temp) {
                        long foo = 7;
                        foo++;
                        bach_breakpoint(0);
                    }
#endif
                    if (temp && notation_item_is_selected((t_notation_obj *)x, (t_notation_item *)temp->end_barline)){
                        barline_selected = true;
                        break;
                    }
                }
                
                measure_across = true;
                if ((t_voice *)voice == first_visible_voice)
                    end_barline_y = last_staff_bottom;
                else
                    barline_type = k_BARLINE_HIDDEN;
            }
            barline_color = barline_selected ? x->r_ob.j_selection_rgba : x->r_ob.j_mainstaves_rgba;
            
            double THRESH_PAGELIKE_BARLINES_END = 2.5 * x->r_ob.zoom_y, THRESH_PAGELIKE_BARLINES_START = 2.5 * x->r_ob.zoom_y;

            if (x->r_ob.pagelike_barlines && fabs(end_barline_x - domain_end_pixel) < THRESH_PAGELIKE_BARLINES_END) {
                end_barline_x = round_to_semiinteger(domain_end_pixel) - 1;
            }
            
            if (!x->r_ob.pagelike_barlines || !(fabs(end_barline_x - domain_start_pixel) < THRESH_PAGELIKE_BARLINES_START)) {
                switch (barline_type) { // barline width
                    case k_BARLINE_NORMAL:
                        paint_line(g, barline_color, end_barline_x, staff_top, end_barline_x, end_barline_y, 1.);
                        break;
                    case k_BARLINE_DASHED:
                        paint_dashed_y_line(g, barline_color, end_barline_x, staff_top, end_barline_y, 1., x->r_ob.step_y * 1.2);
                        break;
                    case k_BARLINE_POINTS:
                        paint_dashed_y_line(g, barline_color, end_barline_x, staff_top, end_barline_y, 1., x->r_ob.step_y * 0.5);
                        break;
                    case k_BARLINE_SOLID:
                        paint_line(g, barline_color, end_barline_x, staff_top, end_barline_x, end_barline_y, 3. * x->r_ob.zoom_y);
                        break;
                    case k_BARLINE_TICK:
                        paint_line(g, barline_color, end_barline_x, staff_top - 3.5 * x->r_ob.zoom_y, end_barline_x, staff_top + 3.5 * x->r_ob.zoom_y, 1.);
                        break;
                    case k_BARLINE_INTERVOICES:
                    {
                        for (t_voice *v = x->r_ob.firstvoice; v && v->number < x->r_ob.num_voices - 1; v = voice_get_next((t_notation_obj *)x, v)) {
                            t_voice *vn = voice_get_next((t_notation_obj *)x, v);
                            double v_bottom = get_staff_bottom_y((t_notation_obj *)x, v, false);
                            double vn_top = get_staff_top_y((t_notation_obj *)x, vn, false);
                            paint_line(g, barline_color, end_barline_x, v_bottom, end_barline_x, vn_top, 1.);
                        }
                    }
                        break;
                    case k_BARLINE_HIDDEN:
                        break;
                    case k_BARLINE_DOUBLE:
                        paint_line(g, barline_color, end_barline_x, staff_top, end_barline_x, end_barline_y, 1.);
                        paint_line(g, barline_color, end_barline_x + 3 * x->r_ob.zoom_y, staff_top, end_barline_x + 3 * x->r_ob.zoom_y, end_barline_y, 1.);
                        break;
                    case k_BARLINE_FINAL:
                        paint_line(g, barline_color, end_barline_x, staff_top, end_barline_x, end_barline_y, 1.);
                        paint_line(g, barline_color, end_barline_x + 4 * x->r_ob.zoom_y, staff_top, end_barline_x + 4 * x->r_ob.zoom_y, end_barline_y, 3.5  * x->r_ob.zoom_y);
                        break;
                }
            }
            
            // measure numbers?
            measure_numbers_top_y = staff_top;
            if (x->r_ob.show_measure_numbers[voice->v_ob.number] && curr_meas->next && curr_meas->next->show_measure_number && (!measure_across || (t_voice *)voice == first_visible_voice)) {
                if (x->r_ob.pagelike_barlines && fabs(end_barline_x - domain_end_pixel) < THRESH_PAGELIKE_BARLINES_END) {
                    // this is at the end of the line, won't paint this number
                } else if (x->r_ob.pagelike_barlines && fabs(end_barline_x - domain_start_pixel) < THRESH_PAGELIKE_BARLINES_START) {
                    // will paint this number later, in order to avoid for it to be
                    llll_appendobj(repaint_these_measure_nums, curr_meas->next);
                } else {
                    char measurenum_txt[8];
                    double measurenum_width, measurenum_height;
                    snprintf_zero(measurenum_txt, 8, "%ld", curr_meas->next->force_measure_number ? curr_meas->next->forced_measure_number : curr_meas->measure_number + 2 + x->r_ob.measure_number_offset);
                    jfont_text_measure(jf_measure_num, measurenum_txt, &measurenum_width, &measurenum_height);
                    measure_numbers_top_y = staff_top - measurenum_height - CONST_MEASURE_NUMBER_STAFF_USEPARATION * x->r_ob.zoom_y - (curr_meas->end_barline->barline_type == k_BARLINE_TICK ? 2 * x->r_ob.zoom_y : 0);
                    write_text_standard_account_for_vinset((t_notation_obj *) x, g, jf_measure_num, x->r_ob.j_mainstaves_rgba, measurenum_txt, end_barline_x - measurenum_width/2., measure_numbers_top_y);
                }
            }
            
            if (notation_item_is_selected((t_notation_obj *)x, (t_notation_item *)curr_meas->end_barline)){
                char mspacing[100];
                snprintf_zero(mspacing, 100, "Ɣ %.2f, w %.1f", curr_meas->tuttipoint_reference->local_spacing_width_multiplier, curr_meas->width_ux);
                write_text_standard_account_for_vinset((t_notation_obj *) x, g, jf_measure_num, get_grey(0.5), mspacing, end_barline_x, staff_bottom);
            }
            
            // barline locks?
            if (x->r_ob.show_barline_locks && curr_meas->is_spacing_fixed && (!measure_across || voice == x->firstvoice)){
                double side = 6 * x->r_ob.zoom_y;
                double top = measure_numbers_top_y + CONST_BARLINE_LOCK_UY_SHIFT * x->r_ob.zoom_y;
                double bottom_arc = top - 2 * x->r_ob.zoom_y;
                paint_rectangle(g, x->r_ob.j_locked_rgba, change_alpha(x->r_ob.j_locked_rgba, 0.2), end_barline_x - side/2, top, side, side, 0.5);
                paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.4, top, end_barline_x - side * 0.4, bottom_arc, 0.5);
                paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.25, top, end_barline_x - side * 0.25, bottom_arc, 0.5);
                paint_line(g, x->r_ob.j_locked_rgba, end_barline_x + side * 0.4, top, end_barline_x + side * 0.4, bottom_arc, 0.5);
                paint_line(g, x->r_ob.j_locked_rgba, end_barline_x + side * 0.25, top, end_barline_x + side * 0.25, bottom_arc, 0.5);
                paint_arc_stroken(g, x->r_ob.j_locked_rgba, end_barline_x, bottom_arc, side * 0.4, 0.5, 3.14, 6.28);
                paint_arc_stroken(g, x->r_ob.j_locked_rgba, end_barline_x, bottom_arc, side * 0.25, 0.5, 3.14, 6.28);
                measure_numbers_top_y = top - side - CONST_MEASURE_NUMBER_STAFF_USEPARATION  * x->r_ob.zoom_y;
            }
        }
        
        // tree locks?
        if (x->r_ob.show_rhythmic_tree_locks && curr_meas->lock_rhythmic_tree && (!measure_across || voice == x->firstvoice)){
            double side = 10 * x->r_ob.zoom_y;
            double top = measure_numbers_top_y + CONST_BARLINE_TREE_LOCK_UY_SHIFT * x->r_ob.zoom_y;
            if (measure_across)
                paint_rectangle(g, x->r_ob.j_background_rgba, x->r_ob.j_background_rgba, end_barline_x - side * 0.6 - 1 * x->r_ob.zoom_y, top - side * 1.1 - 1 * x->r_ob.zoom_y, side * 1.2 + 2 * x->r_ob.zoom_y, side * 0.8 + 2 * x->r_ob.zoom_y, 0);
            paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.4, top - side, end_barline_x - side * 0.4, top - side * 0.3, 0.5);
            paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.1, top - side, end_barline_x - side * 0.1, top - side * 0.3, 0.5);
            paint_line(g, x->r_ob.j_locked_rgba, end_barline_x + side * 0.4, top - side, end_barline_x + side * 0.4, top - side * 0.3, 0.5);
            paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.4 - 0.5, top - side, end_barline_x + side * 0.4 + 0.5, top - side, 2. * x->r_ob.zoom_y);
            paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.4 - 0.5, top - side * 0.68, end_barline_x - side * 0.1 + 0.5, top - side * 0.68, 2. * x->r_ob.zoom_y);
            paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.6, top - side * 1.1, end_barline_x + side * 0.6, top - side * 0.3, 1 * x->r_ob.zoom_y);
            paint_line(g, x->r_ob.j_locked_rgba, end_barline_x - side * 0.6, top - side * 0.3, end_barline_x + side * 0.6, top - side * 1.1, 1 * x->r_ob.zoom_y);
        }
        
        
        // draw tempi
        if (x->r_ob.show_tempi) {
            t_tempo *curr_tempo = curr_meas->firsttempo;
            while (curr_tempo) {
                last_cur_tempo = curr_tempo;
                if (!curr_tempo->hidden) {
                    
                    double tempibox_x1 = unscaled_xposition_to_xposition((t_notation_obj *)x, curr_tempo->owner->tuttipoint_reference->offset_ux + curr_tempo->tuttipoint_offset_ux) - CONST_USHIFT_TEMPI_LEFT * x->r_ob.zoom_y;
                    double tempibox_y1 = staff_top + (-x->r_ob.tempi_uy_pos + curr_tempo->uy_offset) * x->r_ob.zoom_y;
                    char veryfirsttempo;
                    double line_x, line_y;
                    double tempo_text_width = 0., tempo_text_height = 0., text_x = 0., width;
                    t_jrgba tempocolor;
                    char tempo_chars[30];
                    //                    t_jtextlayout *jtl; 
                    
                    // if tempo_interp != 0: paint the ........... line!
                    if (tempo_interp != 0 && x->r_ob.show_tempi_interp_line) {
                        paint_dashed_x_line(g, x->r_ob.j_tempi_rgba, start_dottedline_x, tempibox_x1, tempibox_y1 + 7 *x->r_ob.zoom_y, 1, 3);
                        tempo_interp = 0;
                    }
                    
                    // does the tempo start at the VERY beginning of the voice???
                    veryfirsttempo = (!curr_meas->prev && curr_tempo->changepoint.r_num == 0 && !tempo_get_next(curr_tempo)) ? true : false;
                    if (veryfirsttempo)
                        tempibox_x1 = x->r_ob.j_inset_x + 1 + x->r_ob.notation_typo_preferences.clef_ux_shift; // we put the tempo over the clef
                    
                    tempocolor = ((x->r_ob.num_selecteditems == 1) && (notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)curr_tempo))) ?
                    x->r_ob.j_selection_rgba : x->r_ob.j_tempi_rgba;
                    
                    // tempo figure.
                    line_x = tempibox_x1 + notehead_get_uwidth((t_notation_obj *) x, curr_tempo->tempo_figure, NULL, false) * x->r_ob.zoom_y * CONST_TEMPI_FIGURE_PT;
                    line_y = tempibox_y1 + 5 * x->r_ob.zoom_y;
                    // if it's the veryfirst tempo (the one that is meant to go over the clef) we paint it trasparently, since we'll repaint it later on.
                    // however we need the "width" variable to be properly filled.
                    paint_small_note((t_notation_obj *) x, g, veryfirsttempo ? build_jrgba(1., 1., 1., 0) : tempocolor, curr_tempo->tempo_figure, line_x, line_y, CONST_TEMPI_FIGURE_PT, &width);
                    
                    // text
                    text_x = line_x + width + 1 * x->r_ob.zoom_y; 
                    tempo_to_char_buf(curr_tempo, tempo_chars, 30, x->r_ob.tempo_approx_digits);
                    
                    jfont_text_measure(jf_tempi, tempo_chars, &tempo_text_width, &tempo_text_height); // we get how much space do we need
                    if (!veryfirsttempo) { // we draw it if it's not the VERY FIRST! (the very first is drawn over the clef! but later)
                        write_text_standard_singleline(g, jf_tempi, tempocolor, tempo_chars, text_x, tempibox_y1, text_x + 500, tempibox_y1 + 500);
                    }
                    
                    tempo_interp = get_actual_tempo_interp(x, curr_tempo);
                    
                    // write acc/rall?
                    if (tempo_interp != 0) {
                        double acc_rall_x = text_x + tempo_text_width + 2 * x->r_ob.zoom_y;
                        double accrall_text_width, accrall_text_height; char accrall_text[10]; 
                        //                        t_jtextlayout *jtl = jtextlayout_create(); // numerator
                        snprintf_zero(accrall_text, 10, (tempo_interp == 1) ? "acc." : "rall.");
                        
                        jfont_text_measure(jf_tempi_italic, accrall_text, &accrall_text_width, &accrall_text_height); // we get how much space do we need
                        write_text_standard_singleline(g, jf_tempi_italic, tempocolor, accrall_text, acc_rall_x, tempibox_y1, text_x + 500, tempibox_y1 + 500);
                        
                        start_dottedline_x = acc_rall_x + accrall_text_width;
                    }
                    curr_tempo->real_x_width = text_x + tempo_text_width - tempibox_x1;
                }
                
                curr_tempo = curr_tempo->next;
            }
        }
        
    }
    
    // paint slurs
    if (x->r_ob.show_slurs && x->r_ob.slurs && x->r_ob.slurs->l_size > 0) {

        curr_tuttipt = x->r_ob.firsttuttipoint;
        tuttipoint_ux = (curr_tuttipt) ? curr_tuttipt->offset_ux : 0;

        for (curr_meas = voice->firstmeasure; curr_meas && curr_tuttipt; curr_meas = curr_meas->next) {
            
            if (curr_tuttipt->next && curr_tuttipt->next->measure[voice->v_ob.number] == curr_meas) {
                curr_tuttipt = curr_tuttipt->next;
                tuttipoint_ux = curr_tuttipt->offset_ux;
                if (force_xy_position)
                    tuttipoint_ux = tuttipoint_ux - xposition_to_unscaled_xposition((t_notation_obj *)x, (unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.firsttuttipoint->offset_ux) - force_xy_position->x));
            }
            
            if (tuttipoint_ux + curr_meas->start_barline_offset_ux > x->r_ob.screen_ux_end)
                break;
            
            if (tuttipoint_ux + curr_meas->start_barline_offset_ux + curr_meas->width_ux < x->r_ob.screen_ux_start - 300 / x->r_ob.zoom_x)
                continue;
            
            for (t_chord *curr_ch = curr_meas->firstchord; curr_ch; curr_ch = curr_ch->next) {
                chord_paint_slurs_to((t_notation_obj *)x, g, curr_ch);
            }
        }
    }
    
    // if tempo_interp != 0: paint the ........... line!
    if (last_cur_tempo && tempo_interp != 0 && x->r_ob.show_tempi_interp_line) {
        double tempibox_y1 = staff_top + (-x->r_ob.tempi_uy_pos + last_cur_tempo->uy_offset) * x->r_ob.zoom_y;
        paint_dashed_x_line(g, x->r_ob.j_tempi_rgba, start_dottedline_x, rect.width - x->r_ob.j_inset_x, tempibox_y1 + 7 *x->r_ob.zoom_y, 1, 3);
    }

    
    // word extension left to draw?
    if (x->r_ob.show_lyrics && x->r_ob.show_lyrics_word_extensions) {
        if (lyrics_word_extension_going_on && last_painted_chord != lyrics_word_extensions_start_chord && last_painted_chord != chord_get_next(lyrics_word_extensions_start_chord)) {
            double line_y = get_lyrics_word_extension_y_pos((t_notation_obj *) x, staff_bottom);
            double x1 = unscaled_xposition_to_xposition((t_notation_obj *) x, left_word_extension_ux);
            double x2 = x->r_ob.j_inset_x + x->r_ob.inner_width;
            if (x->r_ob.lasttuttipoint)
                x2 = MIN(x2, unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.lasttuttipoint->offset_ux + x->r_ob.lasttuttipoint->width_ux));
            paint_line(g, x->r_ob.j_lyrics_rgba, x1, line_y, x2, line_y, 0.7);
            lyrics_word_extension_going_on = false;
        }
    }
    
    // last hairpin?
    if (curr_hairpin_type && x->r_ob.show_hairpins){
        long s = x->r_ob.link_dynamics_to_slot - 1;
        if (s >= 0 && s < CONST_MAX_SLOTS && x->r_ob.slotinfo[s].slot_type == k_SLOT_TYPE_DYNAMICS) {
            long old_hairpin_type = curr_hairpin_type;
            t_chord *lastch = chord_get_next_with_dynamics((t_notation_obj *)x, last_painted_chord, &curr_hairpin_type, false, true);
            double curr_hairpin_end_x = ms_to_xposition((t_notation_obj *)x, x->r_ob.length_ms_till_last_note); // rect.width * 2;
            if (lastch)
                curr_hairpin_end_x = ms_to_xposition((t_notation_obj *)x, lastch->onset, NULL);
//            curr_hairpin_end_x = onset_to_xposition_roll((t_notation_obj *)x, lastch->onset, NULL);
            paint_dynamics((t_notation_obj *)x, g, NULL, NULL, curr_hairpin_end_x, 0, NULL, jf_dynamics, jf_dynamics_roman, x->r_ob.dynamics_font_size * x->r_ob.zoom_y, x->r_ob.dynamics_roman_font_size * x->r_ob.zoom_y, staff_bottom - x->r_ob.dynamics_uy_pos * x->r_ob.zoom_y, &curr_hairpin_start_x, &old_hairpin_type, &prev_hairpin_color, &prev_hairpin_dontpaint, 0, 0, false);
        }
    }

    
    // dashed lines for lyrics left to draw?
    if (x->r_ob.show_lyrics && lyrics_dashed_going_on) {
        double pos_y = staff_bottom - x->r_ob.lyrics_uy_pos * x->r_ob.zoom_y;
        double this_left_ux = xposition_to_unscaled_xposition((t_notation_obj *) x, x->r_ob.j_inset_x + x->r_ob.inner_width);
        long num_dash_needed = MAX(0, round((this_left_ux - left_dashed_ux) * CONST_NUM_DASH_PER_UX * x->r_ob.zoom_x / x->r_ob.zoom_y)); 
        
        if (num_dash_needed == 1) {
            double ux_module = (this_left_ux - left_dashed_ux)/2;
            write_text_standard_account_for_vinset((t_notation_obj *) x, g, jf_lyrics, x->r_ob.j_lyrics_rgba, "-", unscaled_xposition_to_xposition((t_notation_obj *) x, left_dashed_ux + ux_module), pos_y);
        } else if (num_dash_needed > 1) {
            double ux_module = (this_left_ux - left_dashed_ux)/num_dash_needed;
            long i;
            for (i = 0; i < num_dash_needed; i++){
                double this_x = unscaled_xposition_to_xposition((t_notation_obj *) x, left_dashed_ux + ux_module/2. + i * ux_module);
                write_text_standard_account_for_vinset_singleline((t_notation_obj *) x, g, jf_lyrics, x->r_ob.j_lyrics_rgba, "-", this_x, pos_y);
            }
        }
        lyrics_dashed_going_on = false;
    }
}



void paint_static_stuff1(t_score *x, t_object *view, t_rect rect, t_jfont *jf, t_jfont *jf_acc, t_jfont *jf_text_fractions, t_jfont *jf_acc_bogus, t_jfont *jf_ts, t_jfont *jf_ts_big, t_jfont *jf_tempi, t_jfont *jf_text, t_jfont *jf_measure_num, t_jgraphics *force_graphic_context, t_llll *repaint_these_measure_nums)
{
    
    t_jgraphics *g = view ? jbox_start_layer((t_object *)x, view, gensym("static_layer1"), rect.width, rect.height) : force_graphic_context;
    
    if (g){
        t_jfont *jf_text_small, *jf_text_smallbold, *jf_text_markers, *jf_dynamics, *jf_dynamics_roman, *jf_small_dynamics, *jf_small_dynamics_roman;
        t_jfont *jf_tempi_italic, *jf_tempi_figure, *jf_tuplets, *jf_lyrics, *jf_lyrics_nozoom, *jf_dynamics_nozoom, *jf_dynamics_roman_nozoom, *jf_ann;
        long end_x_to_repaint_no_inset;
        t_scorevoice *voice;
        double playhead_y1, playhead_y2;
        double last_staff_bottom = 0.;
        
        // some constant that will be useful later for the "retouches" left to do, in order to have things working properly 
        // e.g.: if some notes have been drawn over these parts, we cover the notes with the keys/background/staves...
        end_x_to_repaint_no_inset = unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.screen_ux_start - CONST_X_LEFT_START_DELETE_UX_SCORE) - x->r_ob.additional_ux_start_pad * x->r_ob.zoom_y;

        // defining fonts
        jf_text_small = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(x->r_ob.slot_background_font_size * x->r_ob.zoom_y * (x->r_ob.bgslot_zoom/100.)));  // text font (small)
        jf_text_smallbold = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(x->r_ob.slot_background_font_size * x->r_ob.zoom_y * (x->r_ob.bgslot_zoom/100.)));  // text font (small and bold)
        jf_text_markers = jfont_create_debug(x->r_ob.markers_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(x->r_ob.markers_font_size * x->r_ob.zoom_y));  // text font for markers
        jf_tempi_italic = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_ITALIC , JGRAPHICS_FONT_WEIGHT_NORMAL, round(8.8 * x->r_ob.zoom_y)); 
        jf_tempi_figure = jfont_create_debug(x->r_ob.noteheads_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, CONST_TEMPI_FIGURE_PT * x->r_ob.notation_typo_preferences.base_pt * x->r_ob.zoom_y);
        jf_tuplets = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(CONST_TUPLET_BASE_PT * x->r_ob.zoom_y));
        jf_lyrics = jfont_create_debug(x->r_ob.lyrics_font ? x->r_ob.lyrics_font->s_name : "Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.lyrics_font_size * x->r_ob.zoom_y);
        jf_lyrics_nozoom = jfont_create_debug(x->r_ob.lyrics_font ? x->r_ob.lyrics_font->s_name : "Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.lyrics_font_size);
        jf_ann = jfont_create_debug(x->r_ob.annotations_font ? x->r_ob.annotations_font->s_name : "Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.annotation_font_size * x->r_ob.zoom_y);
        jf_small_dynamics = jfont_create_debug("November for bach", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.slot_background_font_size * 2 * x->r_ob.zoom_y * (x->r_ob.bgslot_zoom/100.));
        jf_small_dynamics_roman = jfont_create_debug("Times New Roman", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.slot_background_font_size * x->r_ob.zoom_y * (x->r_ob.bgslot_zoom/100.));
        jf_dynamics = jfont_create_debug("November for bach", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.dynamics_font_size * x->r_ob.zoom_y);
        jf_dynamics_roman = jfont_create_debug("Times New Roman", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.dynamics_roman_font_size * x->r_ob.zoom_y);
        jf_dynamics_nozoom = jfont_create_debug("November for bach", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.dynamics_font_size);
        jf_dynamics_roman_nozoom = jfont_create_debug("Times New Roman", JGRAPHICS_FONT_SLANT_ITALIC, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.dynamics_roman_font_size);

        
        // cycle on the SCOREVOICES!
        get_playhead_ypos((t_notation_obj *)x, &playhead_y1, &playhead_y2);
        
        lock_general_mutex((t_notation_obj *)x);
        
        // here we re-calculate things if changes have been done graphically
        if (x->r_ob.need_perform_analysis_and_change)
            perform_analysis_and_change(x, jf_lyrics_nozoom, jf_dynamics_nozoom, jf_dynamics_roman_nozoom, k_BEAMING_CALCULATION_DO);
        

        for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next)
            compute_middleC_position_for_voice((t_notation_obj *) x, (t_voice *) voice);

        if (x->r_ob.num_voices > 0) {
            t_voice *last_visible_voice = voice_get_last_visible((t_notation_obj *)x);
            if (last_visible_voice)
                last_staff_bottom = get_staff_bottom_y((t_notation_obj *) x, last_visible_voice, false);
        }
        
#ifdef BACH_SPACING_DEBUG
        t_tuttipoint *tmptp;
        for (tmptp = x->r_ob.firsttuttipoint; tmptp; tmptp = tmptp->next) {
            paint_line(g, get_default_slotcolor(tmptp->ID), unscaled_xposition_to_xposition((t_notation_obj *)x, tmptp->offset_ux), 0, unscaled_xposition_to_xposition((t_notation_obj *)x, tmptp->offset_ux), rect.height, 1);
        }
#endif
        
        for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next)
            paint_scorevoice(x, voice, view, g, rect, end_x_to_repaint_no_inset, last_staff_bottom,
                            jf, jf_acc, jf_text_fractions, jf_acc_bogus, jf_ts, jf_ts_big, jf_tempi, jf_text,
                            jf_text_small, jf_text_smallbold, jf_text_markers, jf_tempi_italic, jf_tempi_figure, 
                            jf_measure_num, jf_tuplets, jf_lyrics, jf_lyrics_nozoom, jf_ann, jf_small_dynamics, jf_small_dynamics_roman, jf_dynamics, jf_dynamics_roman, NULL, repaint_these_measure_nums);
            
        unlock_general_mutex((t_notation_obj *)x);

        if (x->r_ob.show_markers && x->r_ob.firstmarker) {
            t_marker *marker;

            lock_markers_mutex((t_notation_obj *)x);
            markers_check_update_name_uwidth((t_notation_obj *)x);
            double this_marker_x = 0, prev_marker_x = -30000, prev_marker_width = 0, prev_region_marker_x = -30000, prev_region_marker_width = 0;
            t_marker *prev_region_marker = NULL;
            char buf[1000];
            for (marker = x->r_ob.firstmarker; marker; marker = marker->next) {
                double marker_onset = 0;
                t_timepoint tp = build_timepoint(0, long2rat(0));
                t_jrgba marker_color;
                

                if (marker->attach_to == k_MARKER_ATTACH_TO_MS) {
                    marker_onset = marker->position_ms;
                    marker_color = x->r_ob.j_marker_rgba;
                } else if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
                    tp = measure_attached_marker_to_timepoint((t_notation_obj *) x, marker);
                    marker_onset = marker->position_ms; // unscaled_xposition_to_ms((t_notation_obj *)x, timepoint_to_unscaled_xposition(x, tp, false, true), 1);
                    marker_color = x->r_ob.j_marker_attached_to_tp_rgba;
                }
                
                get_names_as_text(marker->r_it.names, buf, 1000);

                double marker_ux = marker_get_onset_ux((t_notation_obj *)x, marker);
                double marker_end_ux = marker_region_get_end_ux((t_notation_obj *)x, marker, true);
                bool is_region = marker_is_region(marker);

                
                if ((marker_ux >= x->r_ob.screen_ux_start - 200 / x->r_ob.zoom_x && marker_ux < x->r_ob.screen_ux_end) ||
                    (is_region &&
                     ((marker_end_ux >= x->r_ob.screen_ux_start - 200 / x->r_ob.zoom_x && marker_end_ux < x->r_ob.screen_ux_end) ||
                      (marker_ux <= x->r_ob.screen_ux_start && marker_end_ux >= x->r_ob.screen_ux_end)))){
                    
                    char is_marker_selected = notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)marker);
                    char is_marker_preselected = notation_item_is_preselected((t_notation_obj *) x, (t_notation_item *)marker);
                    
                    t_jrgba *markerlinecolor = (is_marker_selected ^ is_marker_preselected) ? &x->r_ob.j_selection_rgba : &marker_color;
                    t_jrgba white = get_grey(1.);
                    t_jrgba markertextcolor = (!is_region) ? *markerlinecolor : jgraphics_jrgba_interpolate(markerlinecolor, &white, CONST_MARKER_REGION_TEXT_WHITENING);
                     
                    this_marker_x = unscaled_xposition_to_xposition((t_notation_obj *)x, marker_ux);
                    
                    marker->name_painted_direction = (!is_region && !(marker->prev && marker_is_region_till_next(marker->prev)) && (marker_ux + marker->name_uwidth > x->r_ob.screen_ux_end) ? -1 : 1);
                    
                    double this_marker_end_x = unscaled_xposition_to_xposition((t_notation_obj *)x, marker_end_ux);
                    char marker_is_being_edited = (x->r_ob.is_editing_type == k_MARKERNAME && x->r_ob.is_editing_marker == marker);

                    paint_marker((t_notation_obj *) x, g, markerlinecolor, &markertextcolor, jf_text_markers, marker, this_marker_x, this_marker_end_x, playhead_y1, playhead_y2, is_region, CONST_MARKER_LINE_WIDTH, !marker_is_being_edited, &prev_marker_width, &prev_marker_x, &prev_marker_width, prev_region_marker, &prev_region_marker_x, &prev_region_marker_width);
                    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE){
                        double voice_staff_top_y = get_staff_top_y((t_notation_obj *)x, (t_voice *)scorevoice_get_nth(x, tp.voice_num), false);
                        paint_circle(g, change_alpha(marker_color, 1), marker_color, this_marker_x, voice_staff_top_y, 2 * x->r_ob.zoom_y, 1);
                    }
                    
                    if (is_region)
                         prev_region_marker = marker;
                } else if (marker_ux >= x->r_ob.screen_ux_end)
                    break;
            }
            unlock_markers_mutex((t_notation_obj *)x);;
        }
        
        // destroying all fonts
        jfont_destroy_debug(jf_text_small);
        jfont_destroy_debug(jf_text_smallbold);
        jfont_destroy_debug(jf_text_markers);
        jfont_destroy_debug(jf_tempi_italic);
        jfont_destroy_debug(jf_tempi_figure);
        jfont_destroy_debug(jf_tuplets);
        jfont_destroy_debug(jf_lyrics);
        jfont_destroy_debug(jf_lyrics_nozoom);
        jfont_destroy_debug(jf_ann);
        jfont_destroy_debug(jf_dynamics);
        jfont_destroy_debug(jf_dynamics_roman);
        jfont_destroy_debug(jf_dynamics_nozoom);
        jfont_destroy_debug(jf_dynamics_roman_nozoom);
        jfont_destroy_debug(jf_small_dynamics);
        jfont_destroy_debug(jf_small_dynamics_roman);

        if (view)
            jbox_end_layer((t_object *)x, view, gensym("static_layer1"));
    }
    
    if (view)
        jbox_paint_layer((t_object *)x, view, gensym("static_layer1"), 0., 0.);    // position of the layer
}

        
void paint_static_stuff2(t_score *x, t_object *view, t_rect rect, t_jfont *jf, t_jfont *jf_acc, t_jfont *jf_acc_bogus, t_jfont *jf_text_legend, t_jfont *jf_ts, t_jfont *jf_ts_big, t_jfont *jf_tempi, t_jgraphics *force_graphic_context)
{

    t_jgraphics *g = view ? jbox_start_layer((t_object *)x, view, gensym("static_layer2"), rect.width, rect.height) : force_graphic_context;
    
    if (g) {
        t_jfont *jf_voice_names = jfont_create_debug(x->r_ob.voice_names_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.voice_names_font_size * x->r_ob.zoom_y); 
        double end_x_to_repaint_no_inset = unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.screen_ux_start - CONST_X_LEFT_START_DELETE_UX_SCORE) - x->r_ob.additional_ux_start_pad * x->r_ob.zoom_y;
        double fadestart_no_inset = unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.screen_ux_start - CONST_X_LEFT_START_FADE_UX_SCORE / x->r_ob.zoom_x) - x->r_ob.additional_ux_start_pad * x->r_ob.zoom_y;
        t_scorevoice *voice;
        double system_jump = x->r_ob.system_jump;

        if (!x->r_ob.fade_predomain)
            end_x_to_repaint_no_inset = fadestart_no_inset = get_predomain_width_pixels((t_notation_obj *)x);

        // painting label families
        if (x->r_ob.show_label_families == k_SHOW_LABEL_FAMILIES_BOUNDINGBOX || x->r_ob.show_label_families == k_SHOW_LABEL_FAMILIES_VENN)
            paint_venn_label_families((t_notation_obj *)x, view, g);

//        dev_post("painting stuff2");

        if (x->r_ob.fade_predomain) {
            paint_ruler_and_grid_for_score(x, g, rect);
            repaint_left_background_part((t_notation_obj *)x, g, rect, fadestart_no_inset, end_x_to_repaint_no_inset);
        } else {
            repaint_left_background_part((t_notation_obj *)x, g, rect, fadestart_no_inset, end_x_to_repaint_no_inset);
            paint_ruler_and_grid_for_score(x, g, rect);
        }

        // repaint first ts if needed
        if (x->r_ob.spacing_type == k_SPACING_PROPORTIONAL) {
            for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next) {
                if (voice->firstmeasure && voice->firstmeasure && unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.firsttuttipoint->offset_ux) > 0) {
                    if (need_to_show_ts(x, voice->firstmeasure)) {
                        char big = (x->r_ob.show_time_signatures == 2 && is_tuttipoint_with_same_ts((t_notation_obj *)x, voice->firstmeasure->tuttipoint_reference));
                        paint_timesignature((t_notation_obj *) x, g, x->r_ob.j_mainstaves_rgba, big ? jf_ts_big : jf_ts, get_voice_clef((t_notation_obj *)x, (t_voice *)voice), get_staff_top_y((t_notation_obj *) x, (t_voice *) voice, true), voice->firstmeasure, big);
                    }
                }
            }
        }
        
        lock_general_mutex((t_notation_obj *)x);
        for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next){
            double k; 
            long clef = get_voice_clef((t_notation_obj *)x, (t_voice *)voice);
            t_jrgba mainstaffcolor = get_mainstaff_color((t_notation_obj *) x, voice->v_ob.r_it.selected, voice->v_ob.locked, voice->v_ob.muted, voice->v_ob.solo);
            t_jrgba keysigcolor = get_keysig_color((t_notation_obj *) x, voice->v_ob.r_it.selected, voice->v_ob.locked, voice->v_ob.muted, voice->v_ob.solo);
			t_jrgba auxstaffcolor = get_auxstaff_color((t_notation_obj *) x, voice->v_ob.r_it.selected, voice->v_ob.locked, voice->v_ob.muted, voice->v_ob.solo);
			t_jrgba clefcolor = clef_get_color((t_notation_obj *) x, voice->v_ob.r_it.selected, voice->v_ob.locked, voice->v_ob.muted, voice->v_ob.solo);
            t_jrgba auxclefcolor = get_auxclef_color((t_notation_obj *) x, voice->v_ob.r_it.selected, voice->v_ob.locked, voice->v_ob.muted, voice->v_ob.solo);
            double staff_top_y = get_staff_top_y((t_notation_obj *) x, (t_voice *) voice, true);
            double staff_bottom_y = get_staff_bottom_y((t_notation_obj *) x, (t_voice *) voice, true);

            if (voice->v_ob.hidden) 
                continue;

            if (voice->v_ob.part_index != 0)
                continue;

            // repaint first parts of staves
            for (k=0; k<x->r_ob.num_systems; k++)
                paint_staff_lines((t_notation_obj *)x, g, x->r_ob.j_inset_x + x->r_ob.voice_names_uwidth * x->r_ob.zoom_y, end_x_to_repaint_no_inset, 1., voice->v_ob.middleC_y + k * system_jump, clef, mainstaffcolor, auxstaffcolor, voice->v_ob.num_staff_lines, voice->v_ob.staff_lines);
            
            // paint clefs
            for (k=x->r_ob.first_shown_system; k <= x->r_ob.last_shown_system; k++)
				paint_clef((t_notation_obj *)x, g, jf, voice->v_ob.middleC_y + k * system_jump, clef, clefcolor, auxclefcolor);

            // paint key signature
            for (k=x->r_ob.first_shown_system; k <= x->r_ob.last_shown_system; k++)
                paint_keysignature((t_notation_obj *)x, g, jf_acc, jf_acc_bogus, voice->v_ob.middleC_y + k * system_jump, (t_voice *)voice, keysigcolor);
            
            // paint the vertical staff line
            if (is_clef_multistaff((t_notation_obj *)x, clef))
                paint_left_vertical_staffline((t_notation_obj *)x, g, (t_voice *)voice, mainstaffcolor);
            
            // paint the accollatura
            if (voiceensemble_get_numparts((t_notation_obj *)x, (t_voice *)voice) > 1)
                for (k=x->r_ob.first_shown_system; k <= x->r_ob.last_shown_system; k++)
                    paint_accollatura((t_notation_obj *)x, g, staff_top_y, staff_bottom_y, mainstaffcolor);
            

            // paint voice names
            if (x->r_ob.there_are_voice_names && x->r_ob.show_voice_names && (x->r_ob.is_editing_type != k_VOICENAME || x->r_ob.is_editing_voice_name != voice->v_ob.number)) { 
                char buf[1000];
                get_voicenames_as_text((t_notation_obj *)x, (t_voice *)voice, buf, 1000);
                for (k=x->r_ob.first_shown_system; k <= x->r_ob.last_shown_system; k++)
                    write_voicename((t_notation_obj *)x, g, jf_voice_names, (staff_top_y+staff_bottom_y)/2, buf, x->r_ob.voice_names_alignment, mainstaffcolor);
            }
            
            // repaint very first tempo
            if (x->r_ob.show_tempi) {
                if (voice->firstmeasure && voice->firstmeasure->firsttempo && voice->firstmeasure->firsttempo->changepoint.r_num == 0 && 
                    !tempo_get_next(voice->firstmeasure->firsttempo) && !voice->firstmeasure->firsttempo->hidden) {
                    
                    if (!x->r_ob.pagelike_barlines || x->r_ob.screen_ux_start == 0) {
                        t_tempo *thistempo = voice->firstmeasure->firsttempo;
                        t_jrgba tempocolor = ((x->r_ob.num_selecteditems == 1) && (notation_item_is_selected((t_notation_obj *) x, (t_notation_item *)thistempo))) ?
                        x->r_ob.j_selection_rgba : x->r_ob.j_tempi_rgba;
                        double tempibox_x1 = x->r_ob.j_inset_x + 1 + x->r_ob.notation_typo_preferences.clef_ux_shift + x->r_ob.voice_names_uwidth * x->r_ob.zoom_y; // we put the tempo over the clef
                        double tempibox_y1 = get_staff_top_y((t_notation_obj *) x, (t_voice *) voice, false) + (-x->r_ob.tempi_uy_pos + thistempo->uy_offset) * x->r_ob.zoom_y;
                        // tempo figure.
                        double line_x = tempibox_x1 + notehead_get_uwidth((t_notation_obj *) x, thistempo->tempo_figure, NULL, false) * x->r_ob.zoom_y * CONST_TEMPI_FIGURE_PT;
                        double line_y = tempibox_y1 + 5 * x->r_ob.zoom_y;
                        double tempo_text_width = 0., tempo_text_height = 0., text_x = 0.;
                        double width;
                        char tempo_chars[30];
                        
                        paint_small_note((t_notation_obj *) x, g, tempocolor, thistempo->tempo_figure, line_x, line_y, CONST_TEMPI_FIGURE_PT, &width);
                        
                        // text
                        text_x = line_x + width + 1 * x->r_ob.zoom_y;
                        tempo_to_char_buf(thistempo, tempo_chars, 30, x->r_ob.tempo_approx_digits);
                        
                        jfont_text_measure(jf_tempi, tempo_chars, &tempo_text_width, &tempo_text_height); // we get how much space do we need
                        write_text_standard_singleline(g, jf_tempi, tempocolor, tempo_chars, text_x, tempibox_y1, text_x + 500, tempibox_y1 + 500);
                        
                        thistempo->real_x_width = text_x + tempo_text_width - tempibox_x1;
                    }
                }
            }
        }

        unlock_general_mutex((t_notation_obj *)x);

        // strip of background at the end
        paint_filledrectangle(g, x->r_ob.j_background_rgba, x->r_ob.j_inset_x+x->r_ob.inner_width, 0, x->r_ob.j_inset_x, rect.height);

        // obtain and paint legend
        notationobj_paint_legend((t_notation_obj *)x, g, rect, jf_text_legend);
        
        // draw vertical scroll bar
        update_vscrollbar_and_paint_it_if_needed((t_notation_obj *) x, g, rect);
        
        // draw horizontal scroll bar
        if (x->r_ob.view == k_VIEW_SCROLL)
            update_hscrollbar_and_paint_it_if_needed((t_notation_obj *) x, g, rect);
        
        
        // slot handling
        if (x->r_ob.active_slot_num > -1 && x->r_ob.active_slot_notationitem) { // if there's an active slot!!!!
            
            lock_general_mutex((t_notation_obj *)x);
            if (x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_singleslotfortiednotes && x->r_ob.active_slot_notationitem->type == k_NOTE) {
                // if requested, we go to the first tied note
                x->r_ob.active_slot_notationitem = (t_notation_item *)note_get_first_in_tieseq((t_note *)x->r_ob.active_slot_notationitem);
            }
            
            // determine the slot window x
            switch (x->r_ob.active_slot_notationitem->type) {
                case k_NOTE:
                {
                    t_note *activenote = (t_note *)x->r_ob.active_slot_notationitem;
                    
                    x->r_ob.slot_window_x1 = round_to_semiinteger(chord_get_alignment_x((t_notation_obj *)x, activenote->parent));

                    if (x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_uwidth == -3. || x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_uwidth == -1. ||
                        (x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_uwidth == -2. && !slot_can_extend_beyond_note_tail((t_notation_obj *)x, x->r_ob.active_slot_num))) { // duration
                        double ms_end = notation_item_get_onset_ms((t_notation_obj *)x, (t_notation_item *)activenote) + notation_item_get_duration_ms_for_slots_account_for_ties((t_notation_obj *)x, x->r_ob.active_slot_num, (t_notation_item *)activenote);
                        double x_end = ms_to_xposition((t_notation_obj *)x, ms_end, 0);
                        x->r_ob.slot_window_x2 = x_end;
                        
                    } else if (x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_uwidth == -2. && slot_is_temporal((t_notation_obj *)x, x->r_ob.active_slot_num)) { // auto
                        double ms_start = notation_item_get_onset_ms((t_notation_obj *)x, (t_notation_item *)activenote);
                        double ms_end = ms_start + notation_item_get_duration_ms_for_slots_account_for_ties((t_notation_obj *)x, x->r_ob.active_slot_num, (t_notation_item *)activenote);
                        double x_end;
                        double max_x = slot_get_max_x((t_notation_obj *)x, notation_item_get_slot((t_notation_obj *)x, x->r_ob.active_slot_notationitem, x->r_ob.active_slot_num), x->r_ob.active_slot_num);
                        
                        if (slot_is_temporal_absolute((t_notation_obj *)x, x->r_ob.active_slot_num)) {
                            x_end = ms_to_xposition((t_notation_obj *)x, ms_start + MAX(ms_end - ms_start, max_x), 0);
                         } else {
                             x_end = ms_to_xposition((t_notation_obj *)x, MAX(ms_end, rescale(MAX(max_x, 1.), x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_domain[0], x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_domain[1], 0, notation_item_get_duration_ms_for_slots_account_for_ties((t_notation_obj *)x, x->r_ob.active_slot_num, x->r_ob.active_slot_notationitem))), 0);
                         }
                        
                        x->r_ob.slot_window_x2 = x_end;

                        
                    } else {
                        if (x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_temporalmode == k_SLOT_TEMPORALMODE_MILLISECONDS) {
                            x->r_ob.slot_window_x2 = ms_to_xposition((t_notation_obj *)x, notation_item_get_onset_ms((t_notation_obj *)x, (t_notation_item *)activenote) + x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_uwidth);
                        } else {
                            x->r_ob.slot_window_x2 = x->r_ob.slot_window_x1 + x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_uwidth * x->r_ob.zoom_y * (x->r_ob.slot_window_zoom / 100.);
                        }
                    }
                }
                    break;
                case k_CHORD:
                {
                    t_chord *activechord = (t_chord *)x->r_ob.active_slot_notationitem;
                    if (is_chord_a_whole_measure_rest((t_notation_obj *)x, activechord)) {
                        x->r_ob.slot_window_x1 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, activechord->parent->tuttipoint_reference->offset_ux));
                        x->r_ob.slot_window_x2 = unscaled_xposition_to_xposition((t_notation_obj *)x, activechord->parent->tuttipoint_reference->offset_ux + activechord->parent->width_ux);
                    } else {
                        if (slot_is_temporal((t_notation_obj *)x, x->r_ob.active_slot_num)) { //temporal slot
                            x->r_ob.slot_window_x1 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, activechord->parent->tuttipoint_reference->offset_ux + activechord->stem_offset_ux));
                            x->r_ob.slot_window_x2 = unscaled_xposition_to_xposition((t_notation_obj *)x, activechord->parent->tuttipoint_reference->offset_ux + activechord->stem_offset_ux + activechord->duration_ux);
                        } else {
                            x->r_ob.slot_window_x1 = round_to_semiinteger(unscaled_xposition_to_xposition((t_notation_obj *)x, activechord->parent->tuttipoint_reference->offset_ux + activechord->stem_offset_ux));
                            x->r_ob.slot_window_x2 = x->r_ob.slot_window_x1 + x->r_ob.slotinfo[x->r_ob.active_slot_num].slot_uwidth * x->r_ob.zoom_y * (x->r_ob.slot_window_zoom / 100.);
                        }
                    }
                }
                    break;
                default:
                    dev_post("error: item type is %d", x->r_ob.active_slot_notationitem->type);
                    break;
            }
            
            paint_slot((t_notation_obj *) x, g, rect, x->r_ob.active_slot_notationitem, x->r_ob.active_slot_num);
            unlock_general_mutex((t_notation_obj *)x);
        }
        
        jfont_destroy_debug(jf_voice_names);
        if (view)
            jbox_end_layer((t_object *)x, view, gensym("static_layer2"));
    }
    
    if (view)
        jbox_paint_layer((t_object *)x, view, gensym("static_layer2"), 0., 0.);    // position of the layer
}

void score_paint_ext(t_score *x, t_object *view, t_jgraphics *g, t_rect rect)
{
    t_jfont *jf_text, *jf_text_fixed, *jf, *jf_acc, *jf_acc_bogus, *jf_text_fractions, *jf_ts, *jf_ts_big, *jf_tempi, *jf_measure_num;
    t_llll *repaint_measure_num = llll_get();
    
    if (x->need_repaint) 
        x->need_repaint = false;
    
    paint_background((t_object *)x, g, &rect, &x->r_ob.j_background_rgba, x->r_ob.corner_roundness);
    
    // getting/keeping domain
    x->r_ob.domain = getdomain((t_notation_obj *) x);
    
    // setting parameters
    //    x->r_ob.zoom_x = x->r_ob.horizontal_zoom/100.;
    //    if (x->r_ob.zoom_x < 0.) x->r_ob.zoom_x = 0.;
    
    x->r_ob.inner_width = rect.width - (2 * x->r_ob.j_inset_x);
    x->r_ob.inner_height = rect.height - (2 * x->r_ob.j_inset_y); //
    x->r_ob.height = rect.height;
    x->r_ob.width = rect.width;
    
    if (x->r_ob.zoom_y == 0) 
        x->r_ob.firsttime = 1;
    
    if (x->r_ob.firsttime) { // actually, it shouldn't be used anymore (only vzoom set is needed)
        if (x->r_ob.link_vzoom_to_height)
            notationobj_set_vzoom_depending_on_height((t_notation_obj *)x, rect.height);
        else
            notationobj_reset_size_related_stuff((t_notation_obj *)x);
        x->need_repaint = true;
        x->r_ob.firsttime = 0; 
    }
    
    jf_text = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(11. * x->r_ob.zoom_y));  // text font
    jf_text_fixed = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.legend_font_size);  // text font
    jf = jfont_create_debug(x->r_ob.noteheads_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.notation_typo_preferences.base_pt * x->r_ob.zoom_y);
    jf_acc = jfont_create_debug(x->r_ob.accidentals_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.accidentals_typo_preferences.base_pt * x->r_ob.zoom_y);
    jf_acc_bogus = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(8.8 * x->r_ob.zoom_y)); 
    jf_text_fractions = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, CONST_TEXT_FRACTIONS_PT * x->r_ob.zoom_y);
    jf_ts = jfont_create_debug(x->r_ob.noteheads_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.notation_typo_preferences.base_pt_ts * x->r_ob.zoom_y);
    jf_ts_big = jfont_create_debug(x->r_ob.noteheads_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->r_ob.notation_typo_preferences.base_pt_ts * x->r_ob.zoom_y * x->r_ob.big_time_signatures_ratio);
    jf_tempi = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(8.8 * x->r_ob.zoom_y));
    jf_measure_num = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, round(x->r_ob.measure_numbers_font_size * x->r_ob.zoom_y));

//    dev_post("val = %.3f", x->r_ob.notation_typo_preferences.base_pt * x->r_ob.zoom_y);
    
    // getting number of staves
    //    long num_staves = get_num_staves(x);
    //    long num_voices = x->r_ob.num_voices;
    
    x->r_ob.step_y = CONST_STEP_UY * x->r_ob.zoom_y;
    
    
    if (USE_BITMAPS_FOR_STANDARD_QUARTERNOTEHEADS) // building surfaces for most common graphic notation elements
        notationobj_build_notation_item_surfaces((t_notation_obj *)x, view, rect);

    if (x->r_ob.highlight_domain) {
        double x1 = unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.screen_ux_start);
        double x2 = unscaled_xposition_to_xposition((t_notation_obj *) x, x->r_ob.screen_ux_end);
        paint_rectangle(g, change_alpha(x->r_ob.j_selection_rgba, 0.1), change_alpha(x->r_ob.j_selection_rgba, 0.1), x1, 0, x2-x1, rect.height, 0);
    }
    
    // setting alpha to 1 before painting layers! otherwise we have blending issues
    jgraphics_set_source_rgba(g, 0, 0, 0, 1);
    paint_static_stuff1(x, view, rect, jf, jf_acc, jf_text_fractions, jf_acc_bogus, jf_ts, jf_ts_big, jf_tempi, jf_text, jf_measure_num, g, repaint_measure_num);
    
    paint_playhead((t_notation_obj *)x, g, rect);
    
    // draw the legend
    if (x->r_ob.j_mouse_is_over && x->r_ob.legend == 2 && x->r_ob.j_mouse_x >= x->r_ob.j_inset_x && 
        x->r_ob.j_mouse_x <= x->r_ob.j_inset_x + x->r_ob.inner_width && x->r_ob.active_slot_num == -1){
        char legend_text[256];
        snprintf_zero(legend_text, 256, "Cents %.1f", yposition_to_mc((t_notation_obj *)x,x->r_ob.j_mouse_y, NULL, NULL));
        
        write_text(g, jf_text_fixed, x->r_ob.j_legend_rgba, legend_text, x->r_ob.j_inset_x, x->r_ob.j_inset_y, 
                   x->r_ob.inner_width - (x->r_ob.need_vscrollbar && x->r_ob.show_vscrollbar ? CONST_YSCROLLBAR_UWIDTH * x->r_ob.zoom_y : 0) - 5, 
                   x->r_ob.inner_height - (x->r_ob.need_hscrollbar && x->r_ob.show_hscrollbar ? CONST_XSCROLLBAR_UHEIGHT * x->r_ob.zoom_y : 0) - 5 * x->r_ob.zoom_y,
                   JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM, true, false);
    }
    
    // setting alpha to 1 before painting layers! otherwise we have blending issues
    jgraphics_set_source_rgba(g, 0, 0, 0, 1);
    paint_static_stuff2(x, view, rect, jf, jf_acc, jf_acc_bogus, jf_text_fixed, jf_ts, jf_ts_big, jf_tempi, g);

    // painting the first measure number, if needed
    double domain_start_pixel = get_predomain_width_pixels((t_notation_obj *)x);
    for (t_llllelem *el = repaint_measure_num->l_head; el; el = el->l_next) {
        t_measure *meas = (t_measure *)hatom_getobj(&el->l_hatom);
        char measurenum_txt[8];
        double measurenum_width, measurenum_height;
        double staff_top = get_staff_top_y((t_notation_obj *) x, (t_voice *) meas->voiceparent, false);
        snprintf_zero(measurenum_txt, 8, "%ld", meas->force_measure_number ? meas->forced_measure_number : meas->measure_number + 1 + x->r_ob.measure_number_offset);
        jfont_text_measure(jf_measure_num, measurenum_txt, &measurenum_width, &measurenum_height);
        double measure_numbers_top_y = staff_top - measurenum_height - CONST_MEASURE_NUMBER_STAFF_USEPARATION * x->r_ob.zoom_y;
        write_text_standard_account_for_vinset_singleline((t_notation_obj *) x, g, jf_measure_num, x->r_ob.j_mainstaves_rgba, measurenum_txt, domain_start_pixel - measurenum_width/2., measure_numbers_top_y);
        
    }
    
    
    // paint the selection rectangle, if needed
    if (x->r_ob.j_mousedown_obj_type == k_REGION)
        paint_selection_rectangle((t_notation_obj *) x, g, get_default_selection_rectangle_border_color(), get_default_selection_rectangle_fill_color());
    else if (x->r_ob.j_mousedown_obj_type == k_ZOOMING_REGION)
        paint_selection_rectangle((t_notation_obj *) x, g, get_default_selection_rectangle_border_color(), get_default_selection_rectangle_zooming_fill_color());
    else if (x->r_ob.show_dilation_rectangle)
        paint_dilation_rectangle((t_notation_obj *) x, g);

    // paint loop region?
    if (x->r_ob.show_loop_region) {
        double playhead_y1, playhead_y2;
        double x1 = unscaled_xposition_to_xposition((t_notation_obj *)x, timepoint_to_unscaled_xposition((t_notation_obj *)x, x->r_ob.loop_region.start.timepoint, false, false));
        double x2 = unscaled_xposition_to_xposition((t_notation_obj *)x, timepoint_to_unscaled_xposition((t_notation_obj *)x, x->r_ob.loop_region.end.timepoint, false, false));
//        double x1 = ms_to_xposition(x, x->r_ob.loop_region.start.position_ms, 1);
//        double x2 = ms_to_xposition(x, x->r_ob.loop_region.end.position_ms, 1);
        get_playhead_ypos((t_notation_obj *)x, &playhead_y1, &playhead_y2);
        paint_loop_region((t_notation_obj *)x, g, rect, x->r_ob.j_loop_rgba, x1, x2, playhead_y1, playhead_y2, 1.);
    }

    
    if (x->need_repaint) { // in some very special cases (particular tuplets) we need to draw at least 2 times to have the correct result
        x->can_need_repaint = false;
        notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)x);
    } else if (x->r_ob.need_send_rebuild_done_after_paint) {
#ifdef BACH_MAX
        // sending rebuild done (will be deferred_low!!!)
        send_rebuild_done((t_notation_obj *) x);
#endif
        x->r_ob.need_send_rebuild_done_after_paint = false;
    }

    jfont_destroy_debug(jf);
    jfont_destroy_debug(jf_text_fixed);
    jfont_destroy_debug(jf_acc);
    jfont_destroy_debug(jf_acc_bogus);
    jfont_destroy_debug(jf_text_fractions);
    jfont_destroy_debug(jf_text);
    jfont_destroy_debug(jf_ts);
    jfont_destroy_debug(jf_ts_big);
    jfont_destroy_debug(jf_tempi);
    jfont_destroy_debug(jf_measure_num);
    
    llll_free(repaint_measure_num);
}



void paint_ruler_and_grid_for_score(t_score *x, t_jgraphics* g, t_rect graphic_rect){
    if (x->r_ob.ruler > 0 || x->r_ob.show_grid) {
        double screen_ms_start = unscaled_xposition_to_ms((t_notation_obj *)x, x->r_ob.screen_ux_start, 1);
        double screen_ms_end = unscaled_xposition_to_ms((t_notation_obj *)x, x->r_ob.screen_ux_end, 1);
        double start_ms = x->r_ob.grid_step_ms * MAX(0, (round(screen_ms_start / x->r_ob.grid_step_ms) - 1));
        long num_subdivisions = x->r_ob.grid_subdivisions;
        double step_ms = x->r_ob.grid_step_ms / num_subdivisions;
        double ms;
        long i, div, number_of_labels, number_of_divisions_in_window, label_step;
        double bottom_y = (x->r_ob.need_hscrollbar && x->r_ob.show_hscrollbar) ? graphic_rect.height - (CONST_XSCROLLBAR_UHEIGHT + CONST_XSCROLLBAR_WHITE_UPAD_UPON + 2) * x->r_ob.zoom_y : graphic_rect.height;
        double right_cur = -1000;
        double domain_start_x = unscaled_xposition_to_xposition((t_notation_obj *)x, x->r_ob.screen_ux_start);

        if (num_subdivisions <= 0) 
            num_subdivisions = 1;
        
        if (step_ms <= 0.)
            return;
        
        if (screen_ms_end > x->r_ob.length_ms)
            screen_ms_end = x->r_ob.length_ms;
        
        number_of_labels = round(graphic_rect.width/(100 * x->r_ob.zoom_y));
        number_of_divisions_in_window = 0;

        x->r_ob.current_first_grid_ms = start_ms;
        x->r_ob.current_grid_subdivision_ms = step_ms;
        x->r_ob.current_num_grid_subdivisions = num_subdivisions;
        
        for (i = 0, ms = start_ms; ms < screen_ms_end; ms += step_ms, i++){
            if (!x->r_ob.fade_predomain && ms + CONST_EPSILON_DOUBLE_EQ < x->r_ob.screen_ms_start)
                continue;

            double pix = ms_to_xposition((t_notation_obj *)x, ms, 1);
            
            if (pix < 0 || pix < domain_start_x)
                continue;

            if (i % num_subdivisions == 0) { // main division
                if (x->r_ob.show_grid)
                    paint_line(g, x->r_ob.j_main_grid_rgba, pix, 0, pix, bottom_y, 1.);
                if (x->r_ob.ruler == 1 || x->r_ob.ruler == 3) // ruler above
                    paint_line(g, x->r_ob.j_ruler_rgba, pix, 0, pix, CONST_RULER_MAIN_TICKS_UHEIGHT * x->r_ob.zoom_y, 1.);
                if (x->r_ob.ruler == 2 || x->r_ob.ruler == 3) // ruler below
                    paint_line(g, x->r_ob.j_ruler_rgba, pix, bottom_y - CONST_RULER_MAIN_TICKS_UHEIGHT * x->r_ob.zoom_y, pix, bottom_y, 1.);
                number_of_divisions_in_window++;
            } else { // subdivision
                if (x->r_ob.show_grid)
                    paint_line(g, x->r_ob.j_subdivision_grid_rgba, pix, 0, pix, bottom_y, 1.);
                if (x->r_ob.ruler == 1 || x->r_ob.ruler == 3) // ruler above
                    paint_line(g, x->r_ob.j_ruler_rgba, pix, 0, pix, CONST_RULER_SECONDARY_TICKS_UHEIGHT * x->r_ob.zoom_y, 1.);
                if (x->r_ob.ruler == 2 || x->r_ob.ruler == 3) // ruler below
                    paint_line(g, x->r_ob.j_ruler_rgba, pix, bottom_y - CONST_RULER_SECONDARY_TICKS_UHEIGHT * x->r_ob.zoom_y, pix, bottom_y, 1.);
            }
        }
        
        label_step = floor(((double) number_of_divisions_in_window) / number_of_labels);
        if (label_step <= 0) 
            label_step = 1;
        
        // labels
        if (x->r_ob.show_ruler_labels && x->r_ob.ruler > 0) {
            for (ms = start_ms, i = 0, div = 0; ms < screen_ms_end; ms += x->r_ob.grid_step_ms, i+= num_subdivisions){

                if (!x->r_ob.fade_predomain && ms + CONST_EPSILON_DOUBLE_EQ < x->r_ob.screen_ms_start)
                    continue;
                
                double pix = ms_to_xposition((t_notation_obj *)x, ms, 1);
                
                if (pix < 0 || pix < domain_start_x)
                    continue;

                if (pix > right_cur + x->r_ob.ruler_labels_font_size * 3 * x->r_ob.zoom_y) {
                    if (x->r_ob.ruler == 1 || x->r_ob.ruler == 3) { // ruler above
                        if ((div + 1) % label_step == 0)
                            right_cur = paint_label_for_ruler((t_notation_obj *) x, g, ms, pix, CONST_RULER_MAIN_TICKS_UHEIGHT * x->r_ob.zoom_y, 1);
                    }
                    if (x->r_ob.ruler == 2 || x->r_ob.ruler == 3) { // ruler below
                        if ((div + 1) % label_step == 0)
                            right_cur = paint_label_for_ruler((t_notation_obj *) x, g, ms, pix, bottom_y - CONST_RULER_MAIN_TICKS_UHEIGHT * x->r_ob.zoom_y, -1);
                    }
                }
                div++;
            }
        }
    }
}


void recompute_all_except_for_beamings_and_autocompletion_fn(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_score *x = (t_score *)r_ob;
        recompute_all_except_for_beamings_and_autocompletion(x);
    }
}


void sync_quartertempo_fn(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_score *x = (t_score *)r_ob;
        
        t_tempo *tempo = (t_tempo *)obj;
        if (x->r_ob.also_changing_in_inspector_all_sync_tempi) {
            t_tempo *sync_tempi[CONST_MAX_VOICES];
            long i, num_sync_tempi = get_synchronous_tempi((t_notation_obj *)x, tempo, sync_tempi);
            for (i = 0; i < num_sync_tempi; i++)
                sync_tempi[i]->tempo_value = rat_rat_prod(sync_tempi[i]->figure_tempo_value, rat_long_prod(sync_tempi[i]->tempo_figure, 4));
        } else {
            tempo->tempo_value = rat_rat_prod(tempo->figure_tempo_value, rat_long_prod(tempo->tempo_figure, 4));
        }
        recompute_all_except_for_beamings_and_autocompletion(x);
        check_tempi(x);
        check_correct_scheduling((t_notation_obj *)x, true);
    }
}


t_rect bach_measure_miniature_fn(t_score *x, void *elem, long elem_type, char *show_line){
    t_measure *meas = (t_measure *)elem;
    t_voice *voice = (t_voice *)meas->voiceparent;
    double topmmost_voice_y = get_staff_top_y((t_notation_obj *)x, voice, false);
    double bottommost_voice_y = get_staff_bottom_y((t_notation_obj *)x, voice, false);
    double hh = (bottommost_voice_y - topmmost_voice_y) + 50 * x->r_ob.zoom_y;
    double ww = deltauxpixels_to_deltaxpixels((t_notation_obj *)x, meas->width_ux);
    double yy = (topmmost_voice_y + bottommost_voice_y)/2 - hh/2.;
    double xx;
    
    *show_line = k_INSPECTOR_MINIATURE_NO_LINE;
    
    xx = unscaled_xposition_to_xposition((t_notation_obj *)x, meas->tuttipoint_reference->offset_ux + meas->start_barline_offset_ux);

    return build_rect(xx, yy, ww, hh);
}

t_rect bach_tempo_miniature_fn(t_score *x, void *elem, long elem_type, char *show_line){
    t_tempo *tempo = (t_tempo *)elem;
    t_voice *voice = (t_voice *)tempo->owner->voiceparent;
    double topmmost_voice_y = get_staff_top_y((t_notation_obj *)x, voice, false);
    double bottommost_voice_y = get_staff_bottom_y((t_notation_obj *)x, voice, false);
    double hh = (bottommost_voice_y - topmmost_voice_y) + 90 * x->r_ob.zoom_y;
    double ww = 100 * x->r_ob.zoom_y;
    double xx = unscaled_xposition_to_xposition((t_notation_obj *)x, tempo->owner->tuttipoint_reference->offset_ux + tempo->tuttipoint_offset_ux) - ww/2.;
    double yy = (topmmost_voice_y + bottommost_voice_y)/2 - hh/2.;
    *show_line = k_INSPECTOR_MINIATURE_SHOW_VERTICAL_LINE;
    return build_rect(xx, yy, ww, hh);
}

void recompute_all_and_redraw_fn(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr)
    {
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_score *x = (t_score *)r_ob;
        recompute_all_and_redraw(x);
    }
}


void score_bach_attribute_declares(t_score *x){
    t_bach_attr_manager *man = x->r_ob.m_inspector.attr_manager;

    // CHORD ATTRIBUTES
    DECLARE_BACH_ATTR(man, 1, _llllobj_sym_duration, (char *)"Rational Duration", k_CHORD, t_chord, r_sym_duration, k_BACH_ATTR_RAT, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    DECLARE_BACH_ATTR(man, 2, _llllobj_sym_grace, (char *)"Grace", k_CHORD, t_chord, is_grace_chord, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_CHORD, _llllobj_sym_grace), NULL, (bach_setter_fn)bach_set_grace, NULL, NULL, NULL);
    
    // MEASURE ATTRIBUTES
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_name, (char *)"Name", k_MEASURE, t_notation_item, names, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_MEASURE, _llllobj_sym_name), NULL, (bach_setter_fn)bach_set_name_fn, NULL, NULL, NULL);
    DECLARE_BACH_ATTR(man, -1,  _llllobj_sym_timesig, (char *)"Time Signature", k_MEASURE, t_measure, timesignature_dummy, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_MEASURE, _llllobj_sym_timesig), NULL, NULL, NULL,(bach_attr_process_fn)recompute_all_and_redraw_fn, NULL);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_lock, (char *)"Lock", k_MEASURE, t_measure, locked, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_mute, (char *)"Mute", k_MEASURE, t_measure, muted, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    DECLARE_BACH_ATTR(man, -1,  _llllobj_sym_solo, (char *)"Solo", k_MEASURE, t_measure, solo, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_MEASURE, _llllobj_sym_lock), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
    bach_attribute_add_functions(bach_attribute_get(man, k_MEASURE, _llllobj_sym_mute), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
    bach_attribute_add_functions(bach_attribute_get(man, k_MEASURE, _llllobj_sym_solo), NULL, (bach_setter_fn)bach_set_flags_fn, NULL, (bach_attr_process_fn)check_correct_scheduling_fn, NULL);
    DECLARE_BACH_ATTR(man, -1,  _llllobj_sym_lockrhythmictree, (char *)"Lock Rhythmic Tree", k_MEASURE, t_measure, lock_rhythmic_tree, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    x->r_ob.m_inspector.attr_manager->miniature[k_MEASURE] = (bach_inspector_miniature_fn)bach_measure_miniature_fn;

    t_symbol *barlinetype[10];
    barlinetype[0] = gensym("Automatic");
    barlinetype[1] = gensym("Normal");
    barlinetype[2] = gensym("Dashed");
    barlinetype[3] = gensym("Points");
    barlinetype[4] = gensym("Double");
    barlinetype[5] = gensym("Final");
    barlinetype[6] = gensym("Hidden");
    barlinetype[7] = gensym("Solid");
    barlinetype[8] = gensym("Tick");
    barlinetype[9] = gensym("Intervoices");
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_barline, (char *)"Ending Barline Type", k_MEASURE, t_measure, end_barline_dummy, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ENUMINDEX, 0, 0);
    bach_attribute_add_enumindex(bach_attribute_get(man, k_MEASURE, _llllobj_sym_barline), 8, barlinetype);

    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_shownumber, (char *)"Show Measure Number", k_MEASURE, t_measure, show_measure_number, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_usecustomnumber, (char *)"Use Custom Numbering", k_MEASURE, t_measure, force_measure_number, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_number, (char *)"Measure Number", k_MEASURE, t_measure, forced_measure_number, k_BACH_ATTR_LONG, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);

    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_lockwidth, (char *)"Lock Width", k_MEASURE, t_measure, is_spacing_fixed, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_width, (char *)"Width", k_MEASURE, t_measure, width_ux, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_widthfactor, (char *)"Width Multiplier", k_MEASURE, t_measure, local_spacing_width_multiplier, k_BACH_ATTR_DOUBLE, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);

    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_usecustomboxes, (char *)"Use Custom Boxing", k_MEASURE, t_measure, custom_boxing, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_boxes, (char *)"Measure Boxes", k_MEASURE, t_measure, boxes, k_BACH_ATTR_LLLL, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);


    // TEMPO ATTRIBUTES
    //        DECLARE_BACH_ATTR(r_ob, -1, _llllobj_sym_name, "Name", k_TEMPO, t_notation_item, name, k_BACH_ATTR_SYM, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    DECLARE_BACH_ATTR(man, -1,  _llllobj_sym_figure, (char *)"Figure", k_TEMPO, t_tempo, tempo_figure, k_BACH_ATTR_RAT, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    DECLARE_BACH_ATTR(man, -1,  _llllobj_sym_tempo, (char *)"Tempo Value", k_TEMPO, t_tempo, figure_tempo_value, k_BACH_ATTR_RAT, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    DECLARE_BACH_ATTR(man, -1,  _llllobj_sym_onset, (char *)"Rational Onset", k_TEMPO, t_tempo, changepoint, k_BACH_ATTR_RAT, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    DECLARE_BACH_ATTR(man, -1,  _llllobj_sym_interp, (char *)"Rall./Acc. To Next", k_TEMPO, t_tempo, interpolation_type, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ONOFF, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_TEMPO, _llllobj_sym_figure), NULL, NULL, NULL, (bach_attr_process_fn)sync_quartertempo_fn, NULL);
    bach_attribute_add_functions(bach_attribute_get(man, k_TEMPO, _llllobj_sym_tempo), NULL, NULL, NULL, (bach_attr_process_fn)sync_quartertempo_fn, NULL);
    bach_attribute_add_functions(bach_attribute_get(man, k_TEMPO, _llllobj_sym_onset), NULL, NULL, NULL, (bach_attr_process_fn)recompute_all_except_for_beamings_and_autocompletion_fn, NULL);
    bach_attribute_add_functions(bach_attribute_get(man, k_TEMPO, _llllobj_sym_interp), NULL, NULL, NULL, (bach_attr_process_fn)recompute_all_except_for_beamings_and_autocompletion_fn, NULL);
    x->r_ob.m_inspector.attr_manager->miniature[k_TEMPO] = (bach_inspector_miniature_fn)bach_tempo_miniature_fn;
    
    // MARKER ATTRIBUTES
    bach_attribute_add_functions(bach_attribute_get(man, k_MARKER, _llllobj_sym_onset), (bach_getter_fn)bach_get_marker_measure_attach, NULL, NULL, NULL, (bach_inactive_fn)bach_marker_measure_attach_inactive);
    bach_attribute_add_functions(bach_attribute_get(man, k_MARKER, _llllobj_sym_duration), (bach_getter_fn)bach_get_marker_measure_attach, NULL, NULL, NULL, (bach_inactive_fn)bach_marker_measure_attach_inactive);
    t_symbol *attachto[2];
    attachto[0] = gensym("Milliseconds Position");
    attachto[1] = gensym("Measure Position");
    DECLARE_BACH_ATTR(man, 1, _llllobj_sym_attach, (char *)"Attached To", k_MARKER, t_marker, attach_to, k_BACH_ATTR_CHAR, 1, k_BACH_ATTR_DISPLAY_ENUMINDEX, 0, 0);
    bach_attribute_add_enumindex(bach_attribute_get(man, k_MARKER, _llllobj_sym_attach), 2, attachto);
    bach_attribute_add_functions(bach_attribute_get(man, k_MARKER, _llllobj_sym_attach), NULL, (bach_setter_fn)bach_set_marker_measure_attach, NULL, NULL, NULL);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_measure, (char *)"Measure Number", k_MARKER, t_marker, meas_for_attr, k_BACH_ATTR_LONG, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_MARKER, _llllobj_sym_measure), (bach_getter_fn)bach_get_marker_measure_attach, (bach_setter_fn)bach_set_marker_measure_attach, NULL, NULL, (bach_inactive_fn)bach_marker_measure_attach_inactive);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_pim, (char *)"Point In Measure", k_MARKER, t_marker, r_sym_pim_attach, k_BACH_ATTR_RAT, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_MARKER, _llllobj_sym_pim), (bach_getter_fn)bach_get_marker_measure_attach, (bach_setter_fn)bach_set_marker_measure_attach, NULL, NULL, (bach_inactive_fn)bach_marker_measure_attach_inactive);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_voice, (char *)"Voice Number", k_MARKER, t_marker, voice_for_attr, k_BACH_ATTR_LONG, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_MARKER, _llllobj_sym_voice), (bach_getter_fn)bach_get_marker_measure_attach, (bach_setter_fn)bach_set_marker_measure_attach, NULL, NULL, (bach_inactive_fn)bach_marker_measure_attach_inactive);
    DECLARE_BACH_ATTR(man, -1, _llllobj_sym_symduration, (char *)"Rational Duration", k_MARKER, t_marker, r_sym_duration, k_BACH_ATTR_RAT, 1, k_BACH_ATTR_DISPLAY_TEXT, 0, 0);
    bach_attribute_add_functions(bach_attribute_get(man, k_MARKER, _llllobj_sym_duration), (bach_getter_fn)bach_get_marker_measure_attach, (bach_setter_fn)bach_set_marker_measure_attach, NULL, NULL, (bach_inactive_fn)bach_marker_measure_attach_inactive);

}

void bach_set_marker_measure_attach(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_score *x = (t_score *)r_ob;
        if (attr->owner_type == k_MARKER && ac && av){
            t_marker *marker = (t_marker *)obj;
            if (attr->name == _llllobj_sym_attach) {
                change_marker_attachment(x, marker, atom_getlong(av), 0);
            } else if (attr->name == _llllobj_sym_pim) {
                t_llll *parsed = llllobj_parse_llll((t_object *)x, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
                if (parsed && parsed->l_head && is_hatom_number(&parsed->l_head->l_hatom))
                    marker->r_sym_pim_attach = hatom_getrational(&parsed->l_head->l_hatom);
                if (marker->r_sym_pim_attach.r_num < 0)
                    marker->r_sym_pim_attach = long2rat(0);
                if (marker->measure_attach_ID){
                    t_measure *meas = (t_measure *) notation_item_retrieve_from_ID((t_notation_obj *)x, marker->measure_attach_ID);
                    t_rational meas_dur = measure_get_sym_duration(meas);
                    if (rat_rat_cmp(marker->r_sym_pim_attach, meas_dur) > 0)
                        marker->r_sym_pim_attach = meas_dur;
                }
                sync_marker_absolute_ms_onset(x, marker);
                llll_free(parsed);
            } else if (attr->name == _llllobj_sym_duration) {
                t_llll *parsed = llllobj_parse_llll((t_object *)x, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
                if (parsed && parsed->l_head && is_hatom_number(&parsed->l_head->l_hatom))
                    marker->r_sym_duration = hatom_getrational(&parsed->l_head->l_hatom);
                sync_marker_absolute_ms_onset(x, marker);
                llll_free(parsed);
            } else if (attr->name == _llllobj_sym_measure) {
                long voiceac = 0;
                t_atom *voiceav = NULL;
                bach_get_attr(&x->r_ob.m_inspector, obj, bach_attribute_get(x->r_ob.m_inspector.attr_manager, k_MARKER, _llllobj_sym_voice), &voiceac, &voiceav);
                if (ac && av){
                    long voice_num = atom_getlong(voiceav) - 1;
                    long meas_num = atom_getlong(av) - 1;
                    t_scorevoice *voice = (t_scorevoice *)voice_get_nth_safe((t_notation_obj *)x, voice_num);
                    if (voice) {
                        t_measure *meas = measure_get_nth(voice, meas_num);
                        if (meas)
                            marker->measure_attach_ID = meas->r_it.ID;
                    }
                }
                sync_marker_absolute_ms_onset(x, marker);
                if (voiceav)
                    bach_freeptr(voiceav);
            } else if (attr->name == _llllobj_sym_voice) {
                long measac = 0;
                t_atom *measav = NULL;
                bach_get_attr(&x->r_ob.m_inspector, obj, bach_attribute_get(x->r_ob.m_inspector.attr_manager, k_MARKER, _llllobj_sym_measure), &measac, &measav);
                if (ac && av){
                    long voice_num = atom_getlong(av) - 1;
                    long meas_num = atom_getlong(measav) - 1;
                    t_scorevoice *voice = (t_scorevoice *)voice_get_nth_safe((t_notation_obj *)x, voice_num);
                    if (voice) {
                        t_measure *meas = measure_get_nth(voice, meas_num);
                        if (meas)
                            marker->measure_attach_ID = meas->r_it.ID;
                    }
                }
                sync_marker_absolute_ms_onset(x, marker);
                if (measav)
                    bach_freeptr(measav);
            }
        }
    }
}


void bach_get_marker_measure_attach(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long *ac, t_atom **av){
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_score *x = (t_score *)r_ob;
        *ac = 1;
        *av = (t_atom *)bach_newptr(sizeof(t_atom));
        atom_setsym(*av, _llllobj_sym_none);
        if (attr->owner_type == k_MARKER){
            t_marker *marker = (t_marker *)obj;
            if (marker && marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
                t_timepoint tp = measure_attached_marker_to_timepoint((t_notation_obj *)x, marker);
                if (attr->name == _llllobj_sym_measure){
                    atom_setlong(*av, tp.measure_num + 1);
                } else if (attr->name == _llllobj_sym_voice){
                    atom_setlong(*av, tp.voice_num + 1);
                } else if (attr->name == _llllobj_sym_pim){
                    bach_freeptr(*av);
                    *ac = 0;
                    *av = NULL;
                    bach_default_get_bach_attr((t_notation_obj *)x, obj, attr, ac, av);
                } else if (attr->name == _llllobj_sym_duration){
                    if (marker->r_sym_duration.r_num >= 0) {
                        bach_freeptr(*av);
                        *ac = 0;
                        *av = NULL;
                        bach_default_get_bach_attr((t_notation_obj *)x, obj, attr, ac, av);
                    } else {
                        atom_setsym(*av, _llllobj_sym_tillnext);
                    }
                } else if (attr->name == _llllobj_sym_onset){
                    t_timepoint tp = measure_attached_marker_to_timepoint((t_notation_obj *)x, marker);
                    double onset = unscaled_xposition_to_ms((t_notation_obj *)x, timepoint_to_unscaled_xposition((t_notation_obj *)x, tp, false, false), 1);
                    atom_setfloat(*av, onset);
                }
            } else if (marker) {
                if (attr->name == _llllobj_sym_onset)
                    atom_setfloat(*av, marker->position_ms);
                else if (attr->name == _llllobj_sym_duration) {
                    if (marker->duration_ms >= 0)
                        atom_setfloat(*av, marker->duration_ms);
                    else
                        atom_setsym(*av, _llllobj_sym_tillnext);
                }
            }
        }
    }
}


long bach_marker_measure_attach_inactive(t_bach_inspector_manager *man, void *elem, t_bach_attribute *attr)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
//        t_score *x = (t_score *)r_ob;
        if (attr->owner_type == k_MARKER){
            t_marker *marker = (t_marker *)elem;
            if (!marker)
                return 1;
            
            if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
                if (attr->name == _llllobj_sym_onset || attr->name == _llllobj_sym_duration)
                    return 1;
            } else {
                if (attr->name == _llllobj_sym_voice || attr->name == _llllobj_sym_measure || attr->name == _llllobj_sym_pim || attr->name == _llllobj_sym_duration)
                    return 1;
            } 
        }
    }
    return 0;
}


void bach_set_grace(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av){
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_score *x = (t_score *)r_ob;
        if (attr->owner_type == k_CHORD){
            if (ac && av) {
                char new_grace = atom_getlong(av);
                t_chord *ch = (t_chord *)obj;
                if (ch->is_grace_chord != new_grace){
                    toggle_grace_for_chord((t_notation_obj *)x, ch, new_grace);
                    recompute_all_for_measure((t_notation_obj *)x, ch->parent, true);
                    x->r_ob.need_recompute_chords_double_onset = true;
                    set_need_perform_analysis_and_change_flag((t_notation_obj *)x);
                    perform_analysis_and_change(x, NULL, NULL, NULL, false);
                }
            } 
        }
    }
}


// voice is only used when attaching to TP
void change_marker_attachment(t_score *x, t_marker *mk, char new_attachment, long voicenum){
    if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE && new_attachment == k_MARKER_ATTACH_TO_MS){
        t_timepoint tp = measure_attached_marker_to_timepoint((t_notation_obj *)x, mk);
        mk->attach_to = k_MARKER_ATTACH_TO_MS;
        mk->position_ms = unscaled_xposition_to_ms((t_notation_obj *)x, timepoint_to_unscaled_xposition((t_notation_obj *)x, tp, false, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS), 1);
    } else if (mk->attach_to == k_MARKER_ATTACH_TO_MS && new_attachment == k_MARKER_ATTACH_TO_MEASURE) {
        t_timepoint tp = ms_to_timepoint((t_notation_obj *)x, mk->position_ms, voicenum, k_MS_TO_TP_RETURN_INTERPOLATION);
        t_scorevoice *voice = scorevoice_get_nth(x, voicenum);
        t_measure *meas = measure_get_nth(voice, tp.measure_num);
        mk->attach_to = k_MARKER_ATTACH_TO_MEASURE;
        if (voice && meas) {
            mk->measure_attach_ID = meas->r_it.ID;
            mk->r_sym_pim_attach = tp.pt_in_measure;
        } else if (x->firstvoice && x->firstvoice->firstmeasure) {
            mk->measure_attach_ID = x->firstvoice->firstmeasure->r_it.ID;
            mk->r_sym_pim_attach = long2rat(0);
        } else {
            mk->measure_attach_ID = 0;
            mk->r_sym_pim_attach = long2rat(0);
        }
        sync_marker_absolute_ms_onset(x, mk);
    }
}

/*
void reassign_measure_attached_marker_ms_position(t_score *x, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE){
        t_timepoint tp = measure_attached_marker_to_timepoint((t_notation_obj *)x, marker);
        marker->position_ms = unscaled_xposition_to_ms((t_notation_obj *)x, timepoint_to_unscaled_xposition(x, tp, false, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS), 1);
    }
}

void reassign_selected_measure_attached_markers_ms_position(t_score *x)
{
    t_notation_item *it;
    for (it = x->r_ob.firstselecteditem; it; it = it->next_selected)
        if (it->type == k_MARKER)
            reassign_measure_attached_marker_ms_position(x, (t_marker *)it);
}

void reassign_all_measure_attached_markers_ms_position(t_score *x)
{
    t_marker *marker;
    for (marker = x->r_ob.firstmarker; marker; marker = marker->next)
        reassign_measure_attached_marker_ms_position(x, marker);
}
 */

char move_selected_measure_attached_markers(t_score *x, double marker_withmousedown_ux, char magnetic)
{
    t_notation_item *curr_it = x->r_ob.firstselecteditem;
    char changed = 0;
    lock_general_mutex((t_notation_obj *)x);
    while (curr_it) { // cycle on the selected items
        if (curr_it->type == k_MARKER) { // it is a marker : let's move it
            t_marker *marker = (t_marker *)curr_it;
            if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
                t_timepoint tp = measure_attached_marker_to_timepoint((t_notation_obj *)x, marker);
                double ux = marker_withmousedown_ux + marker->ux_difference_with_mousedown_marker;
                t_timepoint new_tp;
                t_measure *new_meas;
                                
                if (magnetic)
                    new_tp = ms_to_timepoint_autochoose_voice((t_notation_obj *)x, unscaled_xposition_to_ms((t_notation_obj *)x, ux, 1), magnetic ? k_MS_TO_TP_RETURN_NEAREST : k_MS_TO_TP_RETURN_INTERPOLATION, &tp.voice_num);
                else
                    new_tp = ms_to_timepoint((t_notation_obj *)x, unscaled_xposition_to_ms((t_notation_obj *)x, ux, 1), tp.voice_num, magnetic ? k_MS_TO_TP_RETURN_NEAREST : k_MS_TO_TP_RETURN_INTERPOLATION);
                
//                dev_post("Timepoint - voice: %ld, meas: %ld, pim: %ld/%ld", new_tp.voice_num, new_tp.measure_num, new_tp.pt_in_measure.r_num, new_tp.pt_in_measure.r_den);
                
                new_meas = measure_get_nth(scorevoice_get_nth(x, tp.voice_num), new_tp.measure_num);
                
                undo_tick_create_for_notation_item((t_notation_obj *)x, curr_it, k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER, _llllobj_sym_state);
                if (new_meas) {
                    marker->measure_attach_ID = new_meas->r_it.ID;
                    marker->r_sym_pim_attach = new_tp.pt_in_measure;
                    changed = 1;
                }
            }
        }
        curr_it = curr_it->next_selected;
    }
    if (changed) {
        check_markers_order((t_notation_obj *)x);
        sync_selected_markers_absolute_ms_onset(x);
    }
    unlock_general_mutex((t_notation_obj *)x);
    return changed;
}


// creates and insert in the score a new measure, after or before the measure refmeasure
t_measure *create_and_insert_new_measure(t_score *x, t_scorevoice *voice, t_measure *refmeasure, char direction, unsigned long force_ID,
                                         t_measure *refmeasure_for_measureinfo, char clone_tempi) {
    t_measure *newmeas = build_measure((t_notation_obj *) x, NULL);
    if (refmeasure_for_measureinfo) {
        measure_set_ts((t_notation_obj *) x, newmeas, &refmeasure_for_measureinfo->timesignature);
        if (clone_tempi) {
            t_tempo *temp;
            for (temp = refmeasure_for_measureinfo->firsttempo; temp; temp = temp->next) {
                t_tempo *cloned = clone_tempo((t_notation_obj *)x, temp);
                insert_tempo((t_notation_obj *)x, newmeas, cloned);
            }
        }
    }
    newmeas->voiceparent = voice;
    insert_measure((t_notation_obj *)x, voice, newmeas, (direction < 0 && refmeasure) ? refmeasure->prev : refmeasure, force_ID);
    recompute_all_for_measure((t_notation_obj *) x, newmeas, true);
    recompute_all_except_for_beamings_and_autocompletion(x);
    return newmeas;
}


    

// ceil all the voices so that they have the SAME number of measures
void score_ceilmeasures_ext(t_score *x, t_scorevoice *from, t_scorevoice *to, long *out_num_meas, char also_lock_general_mutex)
{
    long max_num_meas = 0, i = 0;
    t_scorevoice *voice;
    char changed = false;
    
    // retrieving max number of measures
    if (out_num_meas)
        max_num_meas = *out_num_meas;
    else {
        for (voice = from; voice && voice->v_ob.number < x->r_ob.num_voices && voice->v_ob.number <= to->v_ob.number; voice = voice->next) {
            if (voice->num_measures > max_num_meas)
                max_num_meas = voice->num_measures;
            if (voice == to)
                break;
        }
    }
    
    if (max_num_meas > 0) {
        if (also_lock_general_mutex)
            lock_general_mutex((t_notation_obj *)x);
        for (voice = from; voice && voice->v_ob.number < x->r_ob.num_voices && voice->v_ob.number <= to->v_ob.number; voice = voice->next) {
            char ref_for_measureinfo_is_not_this_voice = (voice->lastmeasure == NULL);
            for (i = voice->num_measures; i < max_num_meas; i++) {
                t_measure *ref_measure = voice->lastmeasure;
                if (ref_for_measureinfo_is_not_this_voice) {
                    t_scorevoice *v;
                    ref_measure = NULL;
                    
                    v = voice->prev;
                    while (v && v->v_ob.number >= 0 && !v->firstmeasure)
                        v = v->prev;
                    if (!v) {
                        v = voice->next;
                        while (v && v->v_ob.number < x->r_ob.num_voices && !v->firstmeasure)
                            v = v->next;
                    }
                    if (v)
                        ref_measure = measure_get_nth(v, i);
                }
                changed = true;
                if (ref_measure) {
                    t_measure *newmeas = create_and_insert_new_measure(x, voice, voice->lastmeasure, 1, 0, ref_measure, ref_for_measureinfo_is_not_this_voice);
                    undo_tick_create_for_notation_item((t_notation_obj *)x, (t_notation_item *)newmeas, k_UNDO_MODIFICATION_TYPE_REMOVE, _llllobj_sym_state);
                }
            }
            if (voice == to)
                break;
        }
        
        perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DONT_CHANGE_LEVELS + k_BEAMING_CALCULATION_DONT_CHANGE_CHORDS + k_BEAMING_CALCULATION_DONT_CHANGE_TIES);
        if (also_lock_general_mutex)
            unlock_general_mutex((t_notation_obj *)x);
    }
    
    handle_change_if_there_are_dangling_undo_ticks((t_notation_obj *) x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_CEIL_MEASURES);
}


    
// actually moves the voice at the end, and resort voices
void score_delete_voice(t_score *x, t_scorevoice *voice)
{
    long voicenumber_to_delete = voice->v_ob.number;
    t_scorevoice *tmp_voice = voice->next;
    
    if (x->r_ob.num_voices <= 1) {
        object_error((t_object *)x, "Can't delete voice: object has just one voice");
        return;
    }

    if (notation_item_is_selected((t_notation_obj *)x, (t_notation_item *)voice))
        notation_item_delete_from_selection((t_notation_obj *)x, (t_notation_item *)voice);
    
    shift_voicewise_arrays((t_notation_obj *)x, voice->v_ob.number + 1, voice->v_ob.number, x->r_ob.num_voices - voice->v_ob.number - 1);

    if (voice->prev) 
        voice->prev->next = voice->next;
    if (voice->next)
        voice->next->prev = voice->prev;
    if (voice != x->lastvoice) {
        voice->prev = x->lastvoice;
        x->lastvoice->next = voice;
    }
    
    if (voice == x->firstvoice){
        x->r_ob.firstvoice = (t_voice *)voice->next;
        x->firstvoice = voice->next;
    }
    voice->next = NULL;
    
    // shifting voice numbers
    for (; tmp_voice; tmp_voice = tmp_voice->next)
        tmp_voice->v_ob.number--;
    voice->v_ob.number = CONST_MAX_VOICES - 1;

    x->r_ob.lastvoice = (t_voice *)voice;
    x->lastvoice = voice;
    x->r_ob.num_voices--;
    x->r_ob.num_voices_plus_one--;
    
    // handling staff lines
    t_llllelem *elem = llll_getindex(x->r_ob.stafflines_as_llll, voicenumber_to_delete + 1, I_MODULO);
    llll_destroyelem(elem);
    set_stafflines_from_llll((t_notation_obj *)x, x->r_ob.stafflines_as_llll, false); // resync

    // handling voice names
    elem = llll_getindex(x->r_ob.voicenames_as_llll, voicenumber_to_delete + 1, I_MODULO);
    llll_destroyelem(elem);
    set_voicenames_from_llll((t_notation_obj *)x, x->r_ob.voicenames_as_llll, false); // resync

    update_solos((t_notation_obj *)x);
    
    if (x->r_ob.link_vzoom_to_height)
        auto_set_rectangle_size((t_notation_obj *) x);
    else
        calculate_voice_offsets((t_notation_obj *) x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
    
    recompute_all(x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
    
}


void score_delete_voiceensemble(t_score *x, t_voice *any_voice_in_voice_ensemble)
{
    if (notationobj_get_num_voiceensembles((t_notation_obj *)x) <= 1) {
        object_error((t_object *)x, "Can't delete voice ensemble: object has just one voice ensemble.");
        return;
    }
    
    t_voice *first = voiceensemble_get_firstvoice((t_notation_obj *)x, any_voice_in_voice_ensemble);
    t_voice *last = voiceensemble_get_lastvoice((t_notation_obj *)x, any_voice_in_voice_ensemble);
    if (first == last)
        score_delete_voice(x, (t_scorevoice *)first);
    else {
        long first_num = first->number;
        long last_num = last->number;
        long i;
        for (i = first_num; i <= last_num; i++) {
            t_scorevoice *temp = scorevoice_get_nth(x, first_num);
            if (temp)
                score_delete_voice(x, (t_scorevoice *)temp);
        }
    }
}



void score_swap_voices(t_score *x, t_scorevoice *v1, t_scorevoice *v2)
{
    if (!v1 || !v2)
        return;
    
    long idx1 = v1->v_ob.number;
    long idx2 = v2->v_ob.number;
    
    if (x->firstvoice == v1)
        x->firstvoice = v2;
    else if (x->firstvoice == v2)
        x->firstvoice = v1;
    
    if (x->lastvoice == v1)
        x->lastvoice = v2;
    else if (x->lastvoice == v2)
        x->lastvoice = v1;
    
    x->r_ob.firstvoice = (t_voice *)x->firstvoice;
    x->r_ob.lastvoice = (t_voice *)x->lastvoice;
    
    t_scorevoice *v1prev = v1->prev, *v1next = v1->next, *v2prev = v2->prev, *v2next = v2->next;
    t_scorevoice *temp_prev = (v2->prev == v1 ? v2 : v2->prev), *temp_next = (v2->next == v1 ? v2 : v2->next);
    long temp_num = v2->v_ob.number;
    
    if (v1prev && v1prev != v2) v1prev->next = v2;
    if (v1next && v1next != v2) v1next->prev = v2;
    if (v2prev && v2prev != v1) v2prev->next = v1;
    if (v2next && v2next != v1) v2next->prev = v1;
    
    v2->prev = (v1->prev == v2 ? v1 : v1->prev);
    v2->next = (v1->next == v2 ? v1 : v1->next);
    v2->v_ob.number = v1->v_ob.number;
    
    v1->prev = temp_prev;
    v1->next = temp_next;
    v1->v_ob.number = temp_num;
    
    swapelem_voicewise_arrays((t_notation_obj *)x, idx1, idx2);
    
    // handling staff lines
    t_llllelem *elem1, *elem2;
    
    long val = llll_check(x->r_ob.stafflines_as_llll);
    elem1 = llll_getindex(x->r_ob.stafflines_as_llll, idx1 + 1, I_STANDARD);
    elem2 = llll_getindex(x->r_ob.stafflines_as_llll, idx2 + 1, I_STANDARD);
    llll_swapelems(elem1, elem2);
    val = llll_check(x->r_ob.stafflines_as_llll);
    set_stafflines_from_llll((t_notation_obj *)x, x->r_ob.stafflines_as_llll, false);
    
    // handling voicenames
    elem1 = llll_getindex(x->r_ob.voicenames_as_llll, idx1 + 1, I_STANDARD);
    elem2 = llll_getindex(x->r_ob.voicenames_as_llll, idx2 + 1, I_STANDARD);
    llll_swapelems(elem1, elem2);
    set_voicenames_from_llll((t_notation_obj *)x, x->r_ob.voicenames_as_llll, false);
}

void score_swap_voiceensembles(t_score *x, t_scorevoice *v1, t_scorevoice *v2)
{
    t_notation_obj *r_ob = (t_notation_obj *)x;

    lock_general_mutex(r_ob);
    t_voice *first1 = voiceensemble_get_firstvoice(r_ob, (t_voice *)v1);
    t_voice *last1 = voiceensemble_get_lastvoice(r_ob, (t_voice *)v1);
    t_voice *first2 = voiceensemble_get_firstvoice(r_ob, (t_voice *)v2);
    t_voice *last2 = voiceensemble_get_lastvoice(r_ob, (t_voice *)v2);
    
    if (first1 == first2 || last1 == last2)
        return; // nothing to do
    
    // suppose we have A B C    D E
    // we have to swap : D <-> C,    A B D    C E
    // we have to swap : D <-> B,    A D B    C E
    // we have to swap : D <-> A,    D A B    C E
    // then:
    // we have to swap : E <-> C,    D A B    C E
    // we have to swap : E <-> B,    A D B    C E
    // we have to swap : E <-> A,    D A B    C E
    
    t_voice *temp1, *temp2;
    for (temp2 = first2; temp2 && temp2->number < r_ob->num_voices; temp2 = voice_get_next(r_ob, temp2)) {
        for (temp1 = first1; temp1 && temp1->number < r_ob->num_voices; temp1 = voice_get_next(r_ob, temp1)) {
            score_swap_voices(x, (t_scorevoice *)temp1, (t_scorevoice *)temp2);
            if (temp1 == last1)
                break;
        }
        
        if (temp2 == last2)
            break;
    }
    unlock_general_mutex(r_ob);
    
    if (x->r_ob.link_vzoom_to_height)
        auto_set_rectangle_size((t_notation_obj *) x);
    else
        calculate_voice_offsets((t_notation_obj *) x);
    recompute_all_and_redraw(x);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
}


// moves the last voice in a given point.
// idx_of_the_stafflist_element_in_llll is 1-based
void score_move_and_reinitialize_last_voice(t_score *x, t_scorevoice *after_this_voice, t_symbol *key, long clef, t_llll *voicename, long midichannel, long idx_of_the_stafflist_element_in_llll, t_scorevoice *ceilmeasure_from_this_voice)
{
    t_scorevoice *tmp_voice;
    t_llllelem *elem, *nth;
    
    if (x->r_ob.num_voices < CONST_MAX_VOICES){
        // reinsert last voice after the voice *after_this_voice
        t_scorevoice *voice_to_move = x->lastvoice;
        if (after_this_voice && ((t_scorevoice *)after_this_voice)->next) {
            // insert between two voices
            x->lastvoice->prev->next = NULL;
            x->lastvoice = voice_to_move->prev;
            x->r_ob.lastvoice = (t_voice *)x->lastvoice;
            voice_to_move->next = after_this_voice->next;
            voice_to_move->prev = after_this_voice;
            after_this_voice->next->prev = voice_to_move;
            after_this_voice->next = voice_to_move;
            voice_to_move->v_ob.number = after_this_voice->v_ob.number + 1;
            for (tmp_voice = voice_to_move->next; tmp_voice; tmp_voice = tmp_voice->next)
                tmp_voice->v_ob.number ++;
            shift_voicewise_arrays((t_notation_obj *)x, after_this_voice->v_ob.number + 1, after_this_voice->v_ob.number + 2, x->r_ob.num_voices - after_this_voice->v_ob.number - 1);
        } else if (after_this_voice) {
            // insert at the end. Nothing to do: last voice remains last voice!
        } else {
            // insert at the beginning 
            x->lastvoice->prev->next = NULL;
            x->lastvoice = voice_to_move->prev;
            x->r_ob.lastvoice = (t_voice *)x->lastvoice;
            voice_to_move->next = x->firstvoice;
            voice_to_move->prev = NULL;
            x->firstvoice->prev = voice_to_move;
            x->firstvoice = voice_to_move;
            x->r_ob.firstvoice = (t_voice *)x->firstvoice;
            voice_to_move->v_ob.number = 0;
            for (tmp_voice = voice_to_move->next; tmp_voice; tmp_voice = tmp_voice->next)
                tmp_voice->v_ob.number ++;
            shift_voicewise_arrays((t_notation_obj *)x, 0, 1, x->r_ob.num_voices);
        }
        x->r_ob.num_voices++;
        x->r_ob.num_voices_plus_one++;

        long voice_to_move_number = CLAMP(voice_to_move->v_ob.number, 0, CONST_MAX_VOICES - 1);
        x->r_ob.hidevoices_as_charlist[voice_to_move_number] = 0;
        x->r_ob.voiceuspacing_as_floatlist[voice_to_move_number] = CONST_DEFAULT_ROLLVOICES_SPACING_UY;
        x->r_ob.show_measure_numbers[voice_to_move_number] = 1;

        // handling staff lines
        elem = llll_getindex(x->r_ob.stafflines_as_llll, idx_of_the_stafflist_element_in_llll, I_MODULO);
        nth = llll_getindex(x->r_ob.stafflines_as_llll, voice_to_move->v_ob.number, I_MODULO);
        if (voice_to_move->v_ob.number > 0)
            llll_inserthatom_after_clone(&elem->l_hatom, nth, 0, WHITENULL_llll);
        else
            llll_prependhatom_clone(x->r_ob.stafflines_as_llll, &elem->l_hatom, 0, WHITENULL_llll);
        set_stafflines_from_llll((t_notation_obj *)x, x->r_ob.stafflines_as_llll, false);

        // handling voicenames
        nth = llll_getindex(x->r_ob.voicenames_as_llll, voice_to_move->v_ob.number, I_MODULO);
        if (voice_to_move->v_ob.number > 0)
            llll_insertllll_after(voicename, nth, 0, WHITENULL_llll);
        else
            llll_prependllll(x->r_ob.voicenames_as_llll, voicename, 0, WHITENULL_llll);
        set_voicenames_from_llll((t_notation_obj *)x, x->r_ob.voicenames_as_llll, false);

        change_single_key((t_notation_obj *)x, (t_voice *)voice_to_move, key, false);
        change_single_clef((t_notation_obj *)x, (t_voice *)voice_to_move, clef, false);
        voice_to_move->v_ob.midichannel = midichannel;
        voice_to_move->v_ob.locked = voice_to_move->v_ob.solo = voice_to_move->v_ob.hidden = voice_to_move->v_ob.muted = 0;

        if (x->r_ob.link_vzoom_to_height)
            auto_set_rectangle_size((t_notation_obj *) x);
        else
            calculate_voice_offsets((t_notation_obj *) x);
        
        // clear all measures, if any
        clear_voice(x, voice_to_move);
        
        if (ceilmeasure_from_this_voice) {
            if (ceilmeasure_from_this_voice->v_ob.number < voice_to_move->v_ob.number)
                score_ceilmeasures_ext(x, ceilmeasure_from_this_voice, voice_to_move, NULL, false);
            else if (ceilmeasure_from_this_voice->v_ob.number > voice_to_move->v_ob.number)
                score_ceilmeasures_ext(x, voice_to_move, ceilmeasure_from_this_voice, NULL, false);
            
            recompute_all(x);
            perform_analysis_and_change(x, NULL, NULL, NULL, k_BEAMING_CALCULATION_DO);
        }
        
        notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *) x);
    }
}

double get_first_onset_ms_for_grace_notes(t_score *x)
{
    t_scorevoice *voice;
    double res = 0;
    for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next)
        if (voice->firstmeasure && voice->firstmeasure->firstchord && voice->firstmeasure->firstchord->is_grace_chord)
            if (voice->firstmeasure->firstchord->onset < res)
                res = voice->firstmeasure->firstchord->onset - CONST_EPSILON2;
    return res;
}

t_scorevoice *get_longest_scorevoice(t_score *x)
{
    t_scorevoice *voice, *longest_voice = NULL;
    double this_length, max_length = 0;
    for (voice = x->firstvoice; voice; voice = voice->next) {
        if (!voice->lastmeasure || !voice->lastmeasure->tuttipoint_reference)
            continue;
        this_length = voice->lastmeasure->tuttipoint_reference->onset_ms + voice->lastmeasure->tuttipoint_onset_ms + voice->lastmeasure->total_duration_ms;
        if (this_length > max_length) {
            max_length = this_length;
            longest_voice = voice;
        }
    }
    return longest_voice;
}

// measure "up_to_this_measure_num" is included (and 0-based)
char measure_barlines_coincide_for_all_voices(t_score *x, long up_to_this_measure_num)
{
    t_scorevoice *voice = get_longest_scorevoice(x);
    t_measure *meas;
    t_tuttipoint *tpt;
    
    if (x->r_ob.num_voices <= 1)
        return true;
    
    for (meas = voice->firstmeasure, tpt = x->r_ob.firsttuttipoint; meas && tpt; meas = meas->next, tpt = tpt->next) {
        if (tpt->measure[voice->v_ob.number] != meas)
            return false;
        if (meas->measure_number > up_to_this_measure_num)
            return true;
    }
    
    if (meas || tpt)
        return false;
    return true;
}




t_llll *score_get_interp_at_timepoint(t_score *x, t_timepoint tp)
{
    t_scorevoice *voice;
    t_chord *chord;
    t_note *note;
    t_llll *out = llll_get();
    
    lock_general_mutex((t_notation_obj *)x);
    for (voice = x->firstvoice; voice && voice->v_ob.number < x->r_ob.num_voices; voice = voice->next) {
        t_llll *voice_ll = llll_get();
        t_measure *meas = measure_get_nth(voice, tp.measure_num);
        
        if (meas) {
            for (chord = meas->firstchord; chord; chord = chord->next) {
                if (rat_rat_cmp(chord->r_sym_onset, tp.pt_in_measure) <= 0 &&
                    rat_rat_cmp(rat_rat_sum(chord->r_sym_onset, chord->r_sym_duration), tp.pt_in_measure) > 0) {
                    // a chord has something at #tp; notice that if the chord ENDS exactly at tp, we don't consider it.
                    // which is a fairly reasonable choice, to have legato figures only being sampled with one note at a time in all cases.
                    t_llll *chord_ll = llll_get();
                    
                    for (note = chord->firstnote; note; note = note->next) {
                        t_llll *note_ll;
                        x->r_ob.curr_sampling_ms = timepoint_to_ms((t_notation_obj *)x, tp, voice->v_ob.number);
                        note_ll = get_scorenote_values_as_llll((t_notation_obj *)x, note, k_CONSIDER_FOR_SAMPLING);
                        llll_appendllll(chord_ll, note_ll, 0, WHITENULL_llll);
                    }
                    
                    llll_appendllll(voice_ll, chord_ll, 0, WHITENULL_llll);
                }
            }
        }
        
        llll_appendllll(out, voice_ll, 0, WHITENULL_llll);
    }
    unlock_general_mutex((t_notation_obj *)x);
    
    return out;
}

t_llll *score_get_sampling_timepoint(t_score *x, t_timepoint delta_tp)
{
    t_llll *out = llll_get();
    t_llll *out1 = llll_get();
    t_llll *out2 = llll_get();
    
    long master_voice_num = delta_tp.voice_num;
    t_scorevoice *master_voice = scorevoice_get_nth(x, master_voice_num);
    if (master_voice) {
        if (delta_tp.measure_num > 0 || rat_long_cmp(delta_tp.pt_in_measure, 0) > 0) {
            t_timepoint tp = build_timepoint_with_voice(0, long2rat(0), master_voice_num);
            for (; tp.measure_num < master_voice->num_measures; tp = timepoint_shift((t_notation_obj *)x, tp, delta_tp)) {
                t_llll *this_point = llll_get();
                llll_appenddouble(this_point, timepoint_to_ms((t_notation_obj *)x, tp, master_voice_num));
                llll_appendllll(this_point, get_timepoint_as_llll((t_notation_obj *)x, tp));
                llll_appendllll(out1, this_point, 0, WHITENULL_llll);
                llll_appendllll(out2, score_get_interp_at_timepoint(x, tp), 0, WHITENULL_llll);
            }
        }
    }
    
    llll_appendllll(out, out1, 0, WHITENULL_llll);
    llll_appendllll(out, out2, 0, WHITENULL_llll);
    
    return out;
}
