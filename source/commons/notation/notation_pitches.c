/*
 *  notation_pitches.c
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
	notation_pitches.c - function handling pitches
*/

#include "foundation/bach.h"
#include "notation/notation.h" // header with all the structures for the notation objects

const char *subs[] = {"numnotes", "extension"};
const long subs_count = 2;


//Midicents of the screen diatonic note, ignoring accidental. For example, for the Eb above the middle C, this will be 6400 (the midicents of the E)

char note_get_tuningsystem(t_note *nt)
{
    return nt->pitch_original.tuningSystem();
}

long note_get_screen_midicents(t_note *nt)
{
    return nt->pitch_displayed.toScreenMC_wo_accidental();
}

t_shortRational note_get_screen_accidental(t_note *nt)
{
    return nt->pitch_displayed.alter();
}

t_rational note_get_screen_midicents_with_accidental(t_note *nt)
{
    return nt->pitch_displayed.toMC();
}

char note_is_enharmonicity_userdefined(t_note *nt)
{
    return (nt->pitch_original.isNaP() ? 0 : 1);
}

void note_set_auto_enharmonicity(t_note *nt)
{
    nt->pitch_original = t_pitch::NaP;
}

void note_set_user_enharmonicity_from_screen_representation(t_note *nt, double screen_mc, t_rational screen_acc, char also_assign_mc)
{
    long steps = midicents_to_diatsteps_from_C0(NULL, screen_mc);
    nt->pitch_original = t_pitch(steps % 7, screen_acc, steps / 7);
    if (also_assign_mc)
        nt->midicents = nt->pitch_original.toMC();
}

void note_set_user_enharmonicity(t_note *nt, t_pitch pitch, char also_assign_mc)
{
    nt->pitch_original = pitch;
    if (also_assign_mc)
        nt->midicents = pitch.toMC();
}

void note_set_enharmonicity(t_note *nt, t_pitch pitch)
{
    if (pitch.isNaP())
        note_set_auto_enharmonicity(nt);
    else
        note_set_user_enharmonicity(nt, pitch);
}



void note_set_displayed_user_enharmonicity_from_screen_representation(t_note *nt, double screen_mc, t_rational screen_acc)
{
    long steps = midicents_to_diatsteps_from_C0(NULL, screen_mc);
    nt->pitch_displayed = t_pitch(steps % 7, screen_acc, steps / 7);
}

void note_set_displayed_user_enharmonicity(t_note *nt, t_pitch pitch)
{
    nt->pitch_displayed = pitch;
}


void note_appendpitch_to_llll(t_notation_obj *r_ob, t_llll *ll, t_note *note, long pitchmode)
{
    switch (pitchmode) {
        case k_OUTPUT_PITCHES_ALWAYS:
            if (note_is_enharmonicity_userdefined(note))
                llll_appendpitch(ll, note->pitch_original);
            else
                llll_appendpitch(ll, note->pitch_displayed);
            break;
            
        case k_OUTPUT_PITCHES_WHEN_USER_DEFINED:
            if (note_is_enharmonicity_userdefined(note))
                llll_appendpitch(ll, note->pitch_original);
            else
                llll_appenddouble(ll, note->midicents);
            break;
            
        case k_OUTPUT_PITCHES_NEVER:
        default:
            llll_appenddouble(ll, note->midicents);
            break;
    }
}


void note_appendpitch_to_llll_for_separate_syntax(t_notation_obj *r_ob, t_llll *ll, t_note *note, e_output_pitches pitch_output_mode)
{
    note_appendpitch_to_llll(r_ob, ll, note, pitch_output_mode == k_OUTPUT_PITCHES_DEFAULT ? r_ob->output_pitches_separate : pitch_output_mode);
}


void note_appendpitch_to_llll_for_gathered_syntax_or_playout(t_notation_obj *r_ob, t_llll *ll, t_note *note, e_data_considering_types mode)
{
    char pitchmode;
    
    switch (mode) {
        case k_CONSIDER_FOR_SAVING:
        case k_CONSIDER_FOR_SAVING_WITH_BW_COMPATIBILITY:
        case k_CONSIDER_ALL_NOTES:
        case k_CONSIDER_FOR_DUMPING:
        case k_CONSIDER_FOR_SLOT_LLLL_EDITOR:
        case k_CONSIDER_FOR_COLLAPSING_AS_NOTE_BEGINNING:
        case k_CONSIDER_FOR_COLLAPSING_AS_NOTE_MIDDLE:
        case k_CONSIDER_FOR_COLLAPSING_AS_NOTE_END:
        case k_CONSIDER_FOR_UNDO:
        case k_CONSIDER_FOR_SCORE2ROLL:
        case k_CONSIDER_FOR_SUBDUMPING:
        case k_CONSIDER_FOR_DUMPING_ONLY_TIE_SPANNING:
            pitchmode = r_ob->output_pitches_gathered;
            break;
            
        case k_CONSIDER_FOR_EVALUATION:
        case k_CONSIDER_FOR_PLAYING:
        case k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE:
        case k_CONSIDER_FOR_PLAYING_AND_ALLOW_PARTIAL_LOOPED_NOTES:
        case k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE:
            pitchmode = r_ob->output_pitches_playout;
            break;
            
        case k_CONSIDER_FOR_SELECTION_COPYING:
            pitchmode = k_OUTPUT_PITCHES_WHEN_USER_DEFINED;
            break;

        default:
            pitchmode = k_OUTPUT_PITCHES_NEVER;
            break;
    }
    
    note_appendpitch_to_llll(r_ob, ll, note, pitchmode);
}







void note_compute_approximation(t_notation_obj *r_ob, t_note* nt)
{
    t_voice *voice = (nt->parent && nt->parent->is_score_chord) ? (t_voice *)nt->parent->parent->voiceparent : (t_voice *)nt->parent->voiceparent;
    long auto_screen_mc;
    t_rational auto_screen_acc;
    
    switch (nt->pitch_original.tuningSystem()) {
        case BACH_TUNINGSYSTEM_JI:
            // don't do anything
            nt->pitch_displayed = nt->pitch_original;
            break;
            
        case BACH_TUNINGSYSTEM_UNIFORM:
            // don't do anything
            nt->pitch_displayed = nt->pitch_original;
            break;
            
        default:
            if (note_is_enharmonicity_userdefined(nt)) { // there _are_ accidentals user-defined!!!
                mc_to_screen_approximations(r_ob, nt->midicents, &auto_screen_mc, &auto_screen_acc, voice->acc_pattern, voice->full_repr);
                
                if (!(is_natural_note(note_get_screen_midicents(nt)))) {
                    object_error((t_object *)r_ob, "Error: wrong approximation found! Automatically changed to default.");
                    long steps = midicents_to_diatsteps_from_C0(r_ob, auto_screen_mc);
                    nt->pitch_displayed.set(positive_mod(steps, 7), auto_screen_acc, integer_div_round_down(steps, 7));
                    note_set_auto_enharmonicity(nt);
                } else {
                    nt->pitch_displayed = nt->pitch_original;
                    
                    t_rational auto_mc = auto_screen_acc * 200 + auto_screen_mc;
                    if (nt->pitch_original.toMC() != auto_mc) {
                        object_warn((t_object *)r_ob, "Warning: mismatch with current microtonal approximation settings, input accidental might not be displayed.");
                        
                        nt->pitch_displayed.set(nt->pitch_displayed.degree(), (auto_mc - scaleposition_to_midicents(nt->pitch_displayed.toSteps() - 5 * 7))/200, nt->pitch_displayed.octave());
                    }
                }
            } else { // use default accidentals!
                mc_to_screen_approximations(r_ob, nt->midicents, &auto_screen_mc, &auto_screen_acc, voice->acc_pattern, voice->full_repr);	// automatic approximation
                long steps = midicents_to_diatsteps_from_C0(r_ob, auto_screen_mc);
                nt->pitch_displayed.set(positive_mod(steps, 7), auto_screen_acc, integer_div_round_down(steps, 7));
            }
            break;
    }
}





//// AUTOMATIC RESPELLING ALGORITHMS


typedef struct _autospell_params
{
    char    selection_only;
    long    verbose;
    char    voicewise;
    
    long    max_LOF_position; // max position on the line of fifths
    long    min_LOF_position; // min position on the line of fifths
    
    t_symbol    *algorithm; // either "default" or "chewandchen"
    
    char    ignore_locked_notes;
    
    // PARAMETERS FOR DEFAULT ALGORITHM
    double  lineoffifth_bias;       // Bias for the line of fifths
    t_lexpr *stdev_thresh;          // Equation for the acceptance threshold for the standard deviation of the positions on the line of fifth (may depend on numnotes and note extension)
    char    discard_altered_repetitions; // discard altered repetitions such as Eb E or F# F
    
    // PARAMETERS FOR CHEW AND CHEN ALGORITHM
    double  chunk_size_ms;
    double  spiral_r;
    double  spiral_h;
    
    long    w_sliding;          /// NUmber of chunks in sliding window
    long    w_selfreferential;  /// Number of chunks in selfreferential window
    double  f;                  ///< f parameter (see paper)
    
    
    // HANDY POINTERS for mergesort
    t_notation_obj  *r_ob;
    void            *thing;
} t_autospell_params;





////////// BASELINE TRIVIAL ALGORITHM


void notationobj_autospell_trivial(t_notation_obj *r_ob, t_autospell_params *par)
{
    if (par->selection_only)
        reset_selection_enharmonicity(r_ob, par->ignore_locked_notes);
    else
        reset_all_enharmonicity(r_ob, par->ignore_locked_notes);
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        lock_general_mutex(r_ob);
        set_need_perform_analysis_and_change_flag(r_ob);
        //        perform_analysis_and_change(x, NULL, NULL, k_BEAMING_CALCULATION_DO);
        close_slot_window(r_ob); // if we were in slot view...
        unlock_general_mutex(r_ob);
    } else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        update_all_accidentals_if_needed(r_ob);
    }
}








//// CHEW AND CHEN ALGORITHM from Chew and Chen (2003, 2005)

t_pitch pitch_snap_alteration_to_semitones(t_pitch p)
{
    // floor(alter /(1/2))
    long d = rat_rat_divdiv(p.alter(), RAT_1OVER2, false);
    return t_pitch(p.degree(), rat_long_prod(RAT_1OVER2, d), p.octave());
}

t_pitch pitch_rematch_alteration_from_semitones(t_pitch p, t_pitch orig_pitch)
{
    t_rational module = rat_rat_mod(orig_pitch.alter(), RAT_1OVER2, false);
    return t_pitch(p.degree(), rat_rat_sum(p.alter(), module), p.octave());
}

t_pitch position_on_line_of_fifths_to_pitch(long pos)
{
    return t_pitch::middleC + pos * t_pitch(4);
}


long pitch_to_position_on_line_of_fifths(t_pitch p)
{
    t_pitch snapped_p = pitch_snap_alteration_to_semitones(p);
    t_pitch temp = t_pitch(p.degree(), snapped_p.alter(), 0);
    t_pitch lowG = t_pitch(4);
    t_pitch octave = t_pitch(0, long2rat(0), 1);
    const long MAX_TRY = 128;
    
    if (temp.alter() == 0) {
        switch (p.degree()) {
            case 0: return 0;
            case 1: return 2;
            case 2: return 4;
            case 3: return -1;
            case 4: return 1;
            case 5: return 3;
            case 6: return 5;
        }
    }
    
    if (temp.alter() > 0) {
        long count = 0;
        while (temp % lowG != 0 && count < MAX_TRY) {
            temp += octave;
            count++;
        }
        if (temp % lowG == 0)
            return round((double)(temp.toMC() / lowG.toMC()));
        return LONG_MAX;
    }

    if (temp.alter() < 0) {
        long count = 0;
        while (temp % lowG != 0 && count < MAX_TRY) {
            temp -= octave;
            count++;
        }
        if (temp % lowG == 0)
            return round((double)(temp.toMC() / lowG.toMC()));
        return LONG_MAX;
    }
    
    return 0;
}

t_llll *pt3d_to_llll(t_pt3d pt)
{
    return double_triplet_to_llll(pt.x, pt.y, pt.z);
}

t_pt3d pt3d_from_llll(t_llll *ll)
{
    t_pt3d pt = {0, 0, 0};
    
    if (ll && ll->l_size >= 3) {
        pt.x = hatom_getdouble(&ll->l_head->l_hatom);
        pt.y = hatom_getdouble(&ll->l_head->l_next->l_hatom);
        pt.z = hatom_getdouble(&ll->l_head->l_next->l_next->l_hatom);
    }
    return pt;
}

t_pt3d position_on_line_of_fifths_to_position_on_spiral_array(t_notation_obj *r_ob, t_autospell_params *par, long pos)
{
    t_pt3d spiral_point;
    spiral_point.x = par->spiral_r * sin(pos*PI/2.);
    spiral_point.y = par->spiral_r * cos(pos*PI/2.);
    spiral_point.z = par->spiral_h * pos;
    return spiral_point;
}


t_pt3d pitch_to_position_on_spiral_array(t_notation_obj *r_ob, t_autospell_params *par, t_pitch p)
{
    long k = pitch_to_position_on_line_of_fifths(p);
    return position_on_line_of_fifths_to_position_on_spiral_array(r_ob, par, k);
}

t_voice *get_note_voice(t_notation_obj *r_ob, t_note *note)
{
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
        return (t_voice *)note->parent->voiceparent;
    else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
        return (t_voice *)note->parent->parent->voiceparent;
    return NULL;
}

t_llll *notationobj_autospell_list_possibilities(t_notation_obj *r_ob, t_autospell_params *par, t_note *note)
{
    t_llll *out = llll_get();

    t_voice *voice = get_note_voice(r_ob, note);
    long key = 0;
    if (voice)
        key = voice->key;
    
    long pos = pitch_to_position_on_line_of_fifths(note->pitch_displayed);
    
    if (!par->ignore_locked_notes || !notation_item_is_globally_locked(r_ob, (t_notation_item *)note)) {
        pos -= key; // indeed, maxnumflats and maxnumsharps are WITH RESPECT to the KEY!

        // now, all possibilities must lie be between (-1 - 7 * par->max_num_flats) et (5 + 7 * par->max_num_sharps)
        pos = positive_mod(pos, 12);
        
        for (long i = pos; i <= par->max_LOF_position; i += 12)
            llll_appendlong(out, i + key);
        
        for (long i = pos - 12; i >= par->min_LOF_position; i -= 12)
            llll_appendlong(out, i + key);
        
    } else {
        // note has to be kept as it is!
        llll_appendlong(out, pos);
    }

    return out;
}

t_llll *notationobj_autospell_get_chunks(t_notation_obj *r_ob, t_autospell_params *par, long idx_from, long idx_to, t_voice *only_this_voice)
{
    double single_chunk_dur = par->chunk_size_ms;
    double segm_start = idx_from * single_chunk_dur;
    double segm_end = (idx_to + 1) * single_chunk_dur;
    double segm_dur = segm_end - segm_start;
    t_llll *out = llll_get();
    
    for (t_voice *voice = only_this_voice ? only_this_voice : r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
        for (t_chord *chord = chord_get_first(r_ob, voice); chord; chord = chord_get_next(chord)) {
            double onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)chord);
            double tail = notation_item_get_tail_ms(r_ob, (t_notation_item *)chord);
            if (onset > segm_end)
                break;
            if (tail < segm_start)
                continue;
            for (t_note *note = chord->firstnote; note; note = note->next) {
                if (!par->selection_only || notation_item_is_globally_selected(r_ob, (t_notation_item *)note)) {
                    tail = notation_item_get_tail_ms(r_ob, (t_notation_item *)note);
                    if (onset < segm_start && tail >= segm_end) {
                        t_llll *this_note = llll_get();
                        llll_appendobj(this_note, note);
                        llll_appenddouble(this_note, segm_dur);
                        llll_appendlong(this_note, 0);
                        llll_appendllll(out, this_note);
                    } else if (onset >= segm_start && tail >= segm_end) {
                        t_llll *this_note = llll_get();
                        llll_appendobj(this_note, note);
                        llll_appenddouble(this_note, segm_end - onset);
                        llll_appendlong(this_note, 1);
                        llll_appendllll(out, this_note);
                    } else if (onset < segm_start && tail < segm_end) {
                        t_llll *this_note = llll_get();
                        llll_appendobj(this_note, note);
                        llll_appenddouble(this_note, tail - segm_start);
                        llll_appendlong(this_note, 0);
                        llll_appendllll(out, this_note);
                    } else if (onset >= segm_start && tail < segm_end) {
                        t_llll *this_note = llll_get();
                        llll_appendobj(this_note, note);
                        llll_appenddouble(this_note, tail - onset);
                        llll_appendlong(this_note, 1);
                        llll_appendllll(out, this_note);
                    }
                }
            }
        }
        
        if (only_this_voice)
            break;
    }
    
    return out;
    
}


t_pt3d notationobj_autospell_get_center_of_effect(t_notation_obj *r_ob, t_autospell_params *par, t_llll *segment)
{
    double tot_duration = 0;
    t_pt3d tot_pos = {0, 0, 0};
    for (t_llllelem *elem = segment->l_head; elem; elem = elem->l_next) {
        t_llll *ll = hatom_getllll(&elem->l_hatom);
        t_note *note = (t_note *)hatom_getobj(&ll->l_head->l_hatom);
        double duration = hatom_getdouble(&ll->l_head->l_next->l_hatom);
        
        t_pt3d this_pos = pitch_to_position_on_spiral_array(r_ob, par, note->pitch_displayed);
        
        tot_pos.x += duration * this_pos.x;
        tot_pos.y += duration * this_pos.y;
        tot_pos.z += duration * this_pos.z;
        tot_duration += duration;
    }

    tot_pos.x /= tot_duration;
    tot_pos.y /= tot_duration;
    tot_pos.z /= tot_duration;

    return tot_pos;
}

t_pt3d pt3d_sum(t_pt3d p1, t_pt3d p2)
{
    t_pt3d res;
    res.x = p1.x + p2.x;
    res.y = p1.y + p2.y;
    res.z = p1.z + p2.z;
    return res;
}

t_pt3d pt3d_diff(t_pt3d p1, t_pt3d p2)
{
    t_pt3d res;
    res.x = p1.x - p2.x;
    res.y = p1.y - p2.y;
    res.z = p1.z - p2.z;
    return res;
}


t_pt3d pt3d_double_prod(t_pt3d p, double num)
{
    t_pt3d res = p;
    res.x *= num;
    res.y *= num;
    res.z *= num;
    return res;
}


double pt3d_norm_squared(t_pt3d p1)
{
    return p1.x * p1.x + p1.y * p1.y + p1.z * p1.z;
}

double pt3d_norm(t_pt3d p1)
{
    return sqrt(pt3d_norm_squared(p1));
}

double pt3d_distance_squared(t_pt3d p1, t_pt3d p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z);
}

double pt3d_distance(t_pt3d p1, t_pt3d p2)
{
    return sqrt(pt3d_distance_squared(p1, p2));
}


t_pt3d pt3d_versor(t_pt3d from, t_pt3d to)
{
    t_pt3d res = pt3d_diff(to, from);
    double norm = pt3d_norm(res);
    if (norm > 0)
        res = pt3d_double_prod(res, 1/norm);
    return res;
}





long llll_sort_by_distance_to_SCE(void *spell_parameters, t_llllelem *a, t_llllelem *b)
{
    t_autospell_params *par = (t_autospell_params *)spell_parameters;
    t_pt3d ce = *((t_pt3d *)par->thing);
    
    long ak = hatom_getlong(&a->l_hatom);
    long bk = hatom_getlong(&b->l_hatom);
    
    if (isnan(ce.x) || isnan(ce.y) || isnan(ce.z))
        return labs(ak) <= labs(bk);
    else {
        t_pt3d apt = position_on_line_of_fifths_to_position_on_spiral_array(par->r_ob, par, ak);
        t_pt3d bpt = position_on_line_of_fifths_to_position_on_spiral_array(par->r_ob, par, bk);
        return pt3d_distance_squared(apt, ce) <= pt3d_distance_squared(bpt, ce);
    }
    
    
    return 1;
}



long llll_sort_by_distance_to_LCE(void *spell_parameters, t_llllelem *a, t_llllelem *b)
{
    t_autospell_params *par = (t_autospell_params *)spell_parameters;
    double LCE = *((double *)par->thing);
    
    long ak = hatom_getlong(&a->l_hatom);
    long bk = hatom_getlong(&b->l_hatom);
    
    if (isnan(LCE))
        return labs(ak) <= labs(bk);
    else {
        return fabs(ak - LCE) <= fabs(bk - LCE);
    }
    
    
    return 1;
}


t_pitch notationobj_autospell_match_pitch_with_position_on_line_of_fifths(t_notation_obj *r_ob, t_autospell_params *par, t_pitch orig_pitch, long pos)
{
    t_pitch new_pitch = position_on_line_of_fifths_to_pitch(pos);
    new_pitch.set(new_pitch.degree(), new_pitch.alter(), orig_pitch.octave());
    new_pitch = pitch_rematch_alteration_from_semitones(new_pitch, orig_pitch);
    long new_pitch_octave = orig_pitch.octave() + floor((double)((orig_pitch.toMC() - new_pitch.toMC())/1200));
    
    return t_pitch(new_pitch.degree(), new_pitch.alter(), new_pitch_octave);
}

// set a note pitch to a position on the line of fifths
void notationobj_autospell_set_note_pitch_to_position_on_line_of_fifths(t_notation_obj *r_ob, t_autospell_params *par, t_note *note, long pos)
{
    t_pitch new_pitch = notationobj_autospell_match_pitch_with_position_on_line_of_fifths(r_ob, par, note->pitch_displayed, pos);
    
    note_set_user_enharmonicity(note, new_pitch, false);
    
    note->parent->need_recompute_parameters = true;
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        note->parent->parent->need_check_ties = true;
        validate_accidentals_for_measure(r_ob, note->parent->parent);
        note->parent->parent->tuttipoint_reference->need_recompute_spacing = k_SPACING_RECALCULATE;
        set_need_perform_analysis_and_change_flag(r_ob);
    }
    note_compute_approximation(r_ob, note);
}

// respell a note with respect to a spiral center of effect
void autospell_respell_note_wr_to_SCE(t_notation_obj *r_ob, t_autospell_params *par, t_note *note, t_pt3d SCE)
{
    if (!par->ignore_locked_notes || !notation_item_is_globally_locked(r_ob, (t_notation_item *)note)) {
        
        t_llll *possibilities = notationobj_autospell_list_possibilities(r_ob, par, note);
        
        if (possibilities && possibilities->l_head) {
            par->thing = &SCE;
            llll_mergesort_inplace(&possibilities, llll_sort_by_distance_to_SCE, par);
            par->thing = NULL;
            
            if (par->verbose) {
                object_post((t_object *)r_ob, "  Possibilities, in order of distance:");
                for (t_llllelem *el = possibilities->l_head; el; el = el->l_next) {
                    t_pitch thispitch = notationobj_autospell_match_pitch_with_position_on_line_of_fifths(r_ob, par, note->pitch_displayed, hatom_getlong(&el->l_hatom));
                    char notename[128];
                    thispitch.toTextBuf(notename, 128);
                    object_post((t_object *)r_ob, "    %s (dist: %.3f)%s", notename, sqrt(pt3d_distance_squared(SCE, pitch_to_position_on_spiral_array(r_ob, par, thispitch))), el->l_prev ? "" : " <-- chosen");
                }
            }
            
            notationobj_autospell_set_note_pitch_to_position_on_line_of_fifths(r_ob, par, note, hatom_getlong(&possibilities->l_head->l_hatom));
        }
        llll_free(possibilities);
        
    }
}


// respell a note with respect to a center of effect
long autospell_respell_note_wr_to_LCE(t_notation_obj *r_ob, t_autospell_params *par, t_note *note, double LCE, char only_output_res, char verbose)
{
    long res = 0;
    
//    if (!par->ignore_locked_notes || !notation_item_is_globally_locked(r_ob, (t_notation_item *)note)) {
        t_llll *possibilities = notationobj_autospell_list_possibilities(r_ob, par, note);
        
        if (possibilities && possibilities->l_head) {
            par->thing = &LCE;
            llll_mergesort_inplace(&possibilities, llll_sort_by_distance_to_LCE, par);
            par->thing = NULL;
            
            if (verbose) {
                object_post((t_object *)r_ob, "  Possibilities, in order of distance:");
                for (t_llllelem *el = possibilities->l_head; el; el = el->l_next) {
                    t_pitch thispitch = notationobj_autospell_match_pitch_with_position_on_line_of_fifths(r_ob, par, note->pitch_displayed, hatom_getlong(&el->l_hatom));
                    char notename[128];
                    thispitch.toTextBuf(notename, 128);
                    object_post((t_object *)r_ob, "    %s (dist: %.3f)%s", notename, fabs(LCE - pitch_to_position_on_line_of_fifths(thispitch)), el->l_prev ? "" : " <-- chosen");
                }
            }
            
            res = hatom_getlong(&possibilities->l_head->l_hatom);
            if (!only_output_res)
                notationobj_autospell_set_note_pitch_to_position_on_line_of_fifths(r_ob, par, note, hatom_getlong(&possibilities->l_head->l_hatom));
        }
        llll_free(possibilities);
//    }
    return res;
}



void wintostring(t_notation_obj *r_ob, t_autospell_params *par, t_llll *ll, char *buf, long buf_size)
{
    t_llll *temp = llll_get();
    for (t_llllelem *elem = ll->l_head; elem; elem = elem->l_next) {
        t_llll *ll = hatom_getllll(&elem->l_hatom);
        t_note *note = (t_note *)hatom_getobj(&ll->l_head->l_hatom);
        llll_appendpitch(temp, note->pitch_displayed);
    }
    
    llll_to_char_array(temp, buf, buf_size);
    
    llll_free(temp);
    
}

void notationobj_autospell_chew_and_chen_do(t_notation_obj *r_ob, t_autospell_params *par, t_voice *only_this_voice)
{
    double chunk_size_ms = par->chunk_size_ms;
    long num_chunks = ceil(r_ob->length_ms_till_last_note/chunk_size_ms);
    char buf_verbose[1024];
    lock_general_mutex(r_ob);
    
    
    // We implement the algorithms proposed in Chew and Chen, "Determining Context-Defining Windows: Pitch Spelling using the Spiral Array"
    // (The way notationobj_autospell_get_chunks() is called should be largely optimizable).
    for (long j = 0; j < num_chunks; j++) {
        // FIRST PHASE: make each note consistent with the sliding_win
        t_llll *thischunk = notationobj_autospell_get_chunks(r_ob, par, j, j, only_this_voice);
        t_llll *sliding_win = notationobj_autospell_get_chunks(r_ob, par, j - par->w_sliding, j - 1, only_this_voice);
        t_pt3d sliding_win_CE = notationobj_autospell_get_center_of_effect(r_ob, par, sliding_win);

        if (par->verbose) {
            object_post((t_object *)r_ob, "--------------------------------------------");
            object_post((t_object *)r_ob, "Analyzing chunk %ld", j);
            wintostring(r_ob, par, thischunk, buf_verbose, 1024);
            object_post((t_object *)r_ob, "   – notes: %s", buf_verbose);
            wintostring(r_ob, par, sliding_win, buf_verbose, 1024);
            object_post((t_object *)r_ob, "   First pass", j);
            object_post((t_object *)r_ob, "      Sliding window is (%ld, %ld)", j - par->w_sliding, j - 1);
            object_post((t_object *)r_ob, "      – notes: %s", buf_verbose);
            object_post((t_object *)r_ob, "      – center of effect: (%.2f, %.2f, %.2f)", sliding_win_CE.x, sliding_win_CE.y, sliding_win_CE.z);
        }
        
        for (t_llllelem *elem = thischunk->l_head; elem; elem = elem->l_next) {
            t_llll *ll = hatom_getllll(&elem->l_hatom);
            t_note *note = (t_note *)hatom_getobj(&ll->l_head->l_hatom);
            long starts = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom);
            
            if (starts) { // we must spell it
                if (par->verbose) {
                    char txt[256];
                    note->pitch_displayed.toTextBuf(txt, 256);
                    object_post((t_object *)r_ob, "      • Spelling note %s, starting at %.0fms", txt, notation_item_get_onset_ms(r_ob, (t_notation_item *)note));
                }
                
                autospell_respell_note_wr_to_SCE(r_ob, par, note, sliding_win_CE);
            }
        }
        
        
        // SECOND PHASE: the algorithm is allowed to revisit previous decisions
        t_llll *selfreferential_win = notationobj_autospell_get_chunks(r_ob, par, j - par->w_selfreferential, j, only_this_voice);
        t_pt3d selfreferential_win_CE = notationobj_autospell_get_center_of_effect(r_ob, par, selfreferential_win);
        t_llll *global_win = notationobj_autospell_get_chunks(r_ob, par, 0, j-1, only_this_voice); // OR j ????
        t_pt3d global_win_CE = notationobj_autospell_get_center_of_effect(r_ob, par, global_win);
        t_pt3d weighted_CE = pt3d_sum(pt3d_double_prod(selfreferential_win_CE, par->f), pt3d_double_prod(global_win_CE, (1 - par->f)));
        
        if (par->verbose) {
            object_post((t_object *)r_ob, "   Second pass");
            wintostring(r_ob, par, selfreferential_win, buf_verbose, 1024);
            object_post((t_object *)r_ob, "      Self-referential window is (%ld, %ld)", j - par->w_selfreferential, j);
            object_post((t_object *)r_ob, "      – notes: %s", buf_verbose);
            object_post((t_object *)r_ob, "      - center of effect (%.2f, %.2f, %.2f)", selfreferential_win_CE.x, selfreferential_win_CE.y, selfreferential_win_CE.z);
            wintostring(r_ob, par, global_win, buf_verbose, 1024);
            object_post((t_object *)r_ob, "      Global window is (%ld, %ld)", 0, j-1);
            object_post((t_object *)r_ob, "      – notes: %s", buf_verbose);
            object_post((t_object *)r_ob, "      - center of effect (%.2f, %.2f, %.2f)", global_win_CE.x, global_win_CE.y, global_win_CE.z);
        }

        if (isnan(weighted_CE.x) || isnan(weighted_CE.y) || isnan(weighted_CE.z)) {
            if (par->verbose)
                object_post((t_object *)r_ob, "      • Nothing to do, center of effect is NaN");
        } else {
            for (t_llllelem *elem = thischunk->l_head; elem; elem = elem->l_next) {
                t_llll *ll = hatom_getllll(&elem->l_hatom);
                t_note *note = (t_note *)hatom_getobj(&ll->l_head->l_hatom);
                long starts = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom);
                
                if (starts) { // we must spell it
                    if (par->verbose) {
                        char txt[256];
                        note->pitch_displayed.toTextBuf(txt, 256);
                        object_post((t_object *)r_ob, "      • Spelling note %s, starting at %.0fms", txt, notation_item_get_onset_ms(r_ob, (t_notation_item *)note));
                    }
                    
                    autospell_respell_note_wr_to_SCE(r_ob, par, note, weighted_CE);
                }
            }
        }
        
        llll_free(selfreferential_win);
        llll_free(thischunk);
        llll_free(sliding_win);
    }
    
    unlock_general_mutex(r_ob);
}



void notationobj_autospell_chew_and_chen(t_notation_obj *r_ob, t_autospell_params *par)
{
    if (par->voicewise) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice))
            notationobj_autospell_chew_and_chen_do(r_ob, par, voice);
    } else {
        notationobj_autospell_chew_and_chen_do(r_ob, par, NULL);
    }
}


long llll_sort_by_onset(void *notationobj, t_llllelem *a, t_llllelem *b)
{
    t_notation_obj *r_ob = (t_notation_obj *)notationobj;
    t_note *a_note = (t_note *)hatom_getobj(&a->l_hatom);
    t_note *b_note = (t_note *)hatom_getobj(&b->l_hatom);
    
    return notation_item_get_onset_ms(r_ob, (t_notation_item *)a_note) <= notation_item_get_onset_ms(r_ob, (t_notation_item *)b_note);
}

// if only_in_this_voice = NULL, all voices are considered
t_llll *autospell_dg_get_all_notes(t_notation_obj *r_ob, t_autospell_params *par, t_voice *only_in_this_voice)
{
    t_llll *out = llll_get();
    for (t_voice *voice = only_in_this_voice ? only_in_this_voice : r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
        for (t_chord *chord = chord_get_first(r_ob, voice); chord; chord = chord_get_next(chord)) {
            for (t_note *note = chord->firstnote; note; note = note->next) {
                if (!par->selection_only || notation_item_is_globally_selected(r_ob, (t_notation_item *)note)) {
                    llll_appendobj(out, note);
                }
            }
        }
        
        if (only_in_this_voice)
            break;
    }
    
    llll_mergesort_inplace(&out, llll_sort_by_onset, r_ob);
    
    return out;
    
}

/*
typedef struct _autospell_forcedirected_node
{
    t_note  *note;
    long    chord_idx;
    double  onset;
    t_pt3d  pt;
    t_pt3d  force;
} t_autospell_forcedirected_node;


void notationobj_autospell_force_directed(t_notation_obj *r_ob, t_autospell_params *par)
{
    
    lock_general_mutex(r_ob);
    
    t_llll *all_notes = autospell_get_all_notes(r_ob, par);
    long numnotes = all_notes->l_size;
    
    // creating structures
    t_autospell_forcedirected_node *nodes = (t_autospell_forcedirected_node *)bach_newptrclear(numnotes * sizeof(t_autospell_forcedirected_node));
    long i = 0;
    for (t_llllelem *el = all_notes->l_head; el; el = el->l_next, i++) {
        nodes[i].note = (t_note *)hatom_getobj(&el->l_hatom);
        nodes[i].onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&el->l_hatom));
        nodes[i].chord_idx = notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)((t_note *)hatom_getobj(&el->l_hatom))->parent);
        nodes[i].pt = pitch_to_position_on_spiral_array(r_ob, par, nodes[i].note->pitch_displayed);
    }
    
    
    for (long count = 0; count < par->numiter; count ++) {
        
        for (i = 0; i < numnotes; i++) {

            if (par->verbose)
                object_post((t_object *)r_ob, "Analyzing forces on note No. %ld, positioned at: (%.2f, %.2f, %.2f)", i, nodes[i].pt.x, nodes[i].pt.y, nodes[i].pt.z);
            
            nodes[i].force = {0, 0, 0};
            for (long j = 0; j < numnotes; j++) {
                if (j == i)
                    continue;
                double ms_dist = fabs(nodes[i].onset - nodes[j].onset);
                double pt_dist = pt3d_distance(nodes[i].pt, nodes[j].pt);
                double idx_dist = labs(nodes[i].chord_idx - nodes[j].chord_idx);
                double factor = 0.5/(idx_dist*idx_dist + 1); // 1/((ms_dist/500) + 2);
                
                t_pt3d this_force = pt3d_double_prod(pt3d_versor(nodes[i].pt, nodes[j].pt), factor * par->strength_neighbors);
                nodes[i].force = pt3d_sum(nodes[i].force, this_force);

                if (par->verbose)
                    object_post((t_object *)r_ob, "  - Note No. %ld exerts a force of (%.2f, %.2f, %.2f)", j, this_force.x, this_force.y, this_force.z);
            }
            
            t_llll *poss = notationobj_autospell_list_possibilities(r_ob, par, nodes[i].note);
            for (t_llllelem *el = poss->l_head; el; el = el->l_next) {
                long this_pos = hatom_getlong(&el->l_hatom);
                t_pt3d this_pt = position_on_line_of_fifths_to_position_on_spiral_array(r_ob, par, this_pos);

                double pt_dist = pt3d_distance(nodes[i].pt, this_pt);
                double factor = 1/((pt_dist/10.) + 1);

                t_pt3d this_force = pt3d_double_prod(pt3d_versor(nodes[i].pt, this_pt), factor * par->strength_enharmonic);
                nodes[i].force = pt3d_sum(nodes[i].force, this_force);
                
                if (par->verbose) {
                    char pitch_str[256];
                    snprintf_zero(pitch_str, 256, "%s", position_on_line_of_fifths_to_pitch(this_pos).toCString());
                    object_post((t_object *)r_ob, "  - Pitch %s exerts a force of (%.2f, %.2f, %.2f)", pitch_str, this_force.x, this_force.y, this_force.z);
                }
            }
            
            llll_free(poss);
            
            
            
            if (par->verbose)
                object_post((t_object *)r_ob, "  • Total force: (%.2f, %.2f, %.2f)", nodes[i].force.x, nodes[i].force.y, nodes[i].force.z);

        }
        
        for (i = 0; i < numnotes; i++) {
            nodes[i].pt = pt3d_sum(nodes[i].pt, nodes[i].force);
            if (par->verbose)
                object_post((t_object *)r_ob, "New position of note No. %ld: (%.2f, %.2f, %.2f)", i, nodes[i].pt.x, nodes[i].pt.y, nodes[i].pt.z);
        }
        
    }
    
    for (i = 0; i < numnotes; i++) {
        autospell_respell_note_wr_to_SCE(r_ob, par, nodes[i].note, nodes[i].pt);
    }
    
    
    bach_freeptr(nodes);
    
    unlock_general_mutex(r_ob);
}
*/


long ksubsets_sort_by_timespan(void *notationobj, t_llllelem *a, t_llllelem *b)
{
    t_notation_obj *r_ob = (t_notation_obj *)notationobj;
    
    t_llll *a_ll = hatom_getllll(&a->l_hatom);
    t_llll *b_ll = hatom_getllll(&b->l_hatom);
    
    
    double a_ext = notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&a_ll->l_tail->l_hatom)) - notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&a_ll->l_head->l_hatom));
    double b_ext = notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&b_ll->l_tail->l_hatom)) - notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&b_ll->l_head->l_hatom));
    
    return a_ext <= b_ext;
}


t_llll *autospell_get_ksubsets(t_notation_obj *r_ob, t_llll *notes, long k)
{
    t_llll *out = llll_get();
    long len = notes->l_size, i, j;
    t_llllelem *el, *temp;
    for (i = 0, el = notes->l_head; i + k - 1 < len; i++, el = el->l_next) {
        t_llll *this_subset = llll_get();
        for (j = 0, temp = el; temp && j < k; j++, temp = temp->l_next) {
            llll_appendhatom_clone(this_subset, &temp->l_hatom);
        }
        llll_appendllll(out, this_subset);
    }
    
//    llll_print(out);
    llll_mergesort_inplace(&out, ksubsets_sort_by_timespan, r_ob);
    return out;
}


t_llll *llll_wrap_element_range_ext(t_llllelem *from, t_llllelem *to)
{
    while (llllelem_get_depth(from) > 1)
        from = from->l_parent->l_owner;
    while (llllelem_get_depth(to) > 1)
        to = from->l_parent->l_owner;
    return llll_wrap_element_range(from, to);
}


long find_note_fn(void *data, t_hatom *a, const t_llll *address)
{
    t_note *to_match = (t_note *) ((void **)data)[9];
    t_llllelem **to_fill = (t_llllelem **) ((void **)data)[1];

    if (hatom_gettype(a) == H_OBJ){
        t_note *note = (t_note *)hatom_getobj(a);
        if (note == to_match) {
            *to_fill = llll_hatom2elem(a);
            return 0;
        }
    }
    return 0;
}


// TO DO: make this better, this is slow!!!!!
t_llllelem *find_note(t_llll *notes, t_note *note)
{
    t_llllelem *found = NULL;
    void *data[2];
    data[0] = note;
    data[1] = &found;
    llll_funall(notes, (fun_fn) find_note_fn, data, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
    return found;
}

t_llll *autospell_dg_get_tree_old(t_notation_obj *r_ob, t_llll *notes)
{
    t_llll *out = llll_clone(notes);
    
    // step 1: building tree of couples
    t_llll *notes_llllelems = llll_get();
    long i = 1;
    for (t_llllelem *el = out->l_head; el; el = el->l_next, i++) {
        llll_appendobj(notes_llllelems, el);
        ((t_note *)hatom_getobj(&el->l_hatom))->r_it.flags = i;
    }
    
    t_llll *ksubsets = autospell_get_ksubsets(r_ob, notes, 2);

    for (t_llllelem *el = ksubsets->l_head; el; el = el->l_next) {
        t_note *start = (t_note *)hatom_getobj(&hatom_getllll(&el->l_hatom)->l_head->l_hatom);
        t_note *end = (t_note *)hatom_getobj(&hatom_getllll(&el->l_hatom)->l_tail->l_hatom);
        long start_idx = start->r_it.flags;
        long end_idx = end->r_it.flags;
        t_llllelem *start_el = (t_llllelem *)hatom_getobj(&llll_getindex(notes_llllelems, start_idx, I_STANDARD)->l_hatom);
        t_llllelem *end_el = (t_llllelem *)hatom_getobj(&llll_getindex(notes_llllelems, end_idx, I_STANDARD)->l_hatom);
        llll_wrap_element_range_ext(start_el, end_el);
    }
    
    for (t_llllelem *el = notes->l_head; el; el = el->l_next, i++) {
        ((t_note *)hatom_getobj(&el->l_hatom))->r_it.flags = 0;
    }

    llll_free(notes_llllelems);
    return out;
}


typedef struct _node_helper
{
    double first_onset;
    double last_onset;
    double last_tail;
    long   num_notes;
} t_node_helper;


t_node_helper *build_node_helper_from_note(t_notation_obj *r_ob, t_note *note)
{
    t_node_helper *nh = (t_node_helper *)bach_newptr(sizeof(t_node_helper));
    nh->first_onset = nh->last_onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)note);
    nh->last_tail = notation_item_get_tail_ms(r_ob, (t_notation_item *)note);
    nh->num_notes = 1;
    return nh;
}


t_node_helper *build_node_helper(t_notation_obj *r_ob, double first_onset, double last_onset, double last_tail, long num_notes)
{
    t_node_helper *nh = (t_node_helper *)bach_newptr(sizeof(t_node_helper));
    nh->first_onset = first_onset;
    nh->last_onset = last_onset;
    nh->last_tail = last_tail;
    nh->num_notes = num_notes;
    return nh;
}




long free_llllelems_lthing(void *data, t_hatom *a, const t_llll *address)
{
    if (hatom_gettype(a) == H_LLLL){
        for (t_llllelem *el = hatom_getllll(a)->l_head; el; el = el->l_next) {
            if (el->l_thing.w_obj) {
                bach_freeptr(el->l_thing.w_obj);
                el->l_thing.w_obj = NULL;
            }
        }
    }
    return 0;
}


t_llll *autospell_dg_get_tree(t_notation_obj *r_ob, t_autospell_params *par, t_voice *voice)
{
    t_llll *notes = autospell_dg_get_all_notes(r_ob, par, voice);
    t_llll *out = llll_clone(notes);
    
    for (t_llllelem *el = out->l_head; el; el = el->l_next)
        el->l_thing.w_obj = build_node_helper_from_note(r_ob, (t_note *)hatom_getobj(&el->l_hatom));
    
    while (true) {
        
        // finding closest elements
        double best_dist = -1;
        long best_numnotes = 0;
        t_llllelem *best_el = NULL;
        for (t_llllelem *el = out->l_head; el && el->l_next; el = el->l_next) {
            t_node_helper *el_nh = (t_node_helper *)el->l_thing.w_obj;
            t_node_helper *elnext_nh = (t_node_helper *)el->l_next->l_thing.w_obj;
            double this_dist = fabs(elnext_nh->first_onset - el_nh->last_onset);
            long this_numnotes = elnext_nh->num_notes + el_nh->num_notes;
            if (best_dist < 0 || this_dist < best_dist || (this_dist == best_dist && this_numnotes < best_numnotes)) {
                best_dist = this_dist;
                best_numnotes = this_numnotes;
                best_el = el;
            }
        }
        
        if (!best_el)
            break; // we're done
        
        // merging best_el with best_el->l_next
        t_llll *new_ll = llll_wrap_element_range(best_el, best_el->l_next);
        
        new_ll->l_owner->l_thing.w_obj = build_node_helper(r_ob, ((t_node_helper *)best_el->l_thing.w_obj)->first_onset, ((t_node_helper *)best_el->l_next->l_thing.w_obj)->last_onset, ((t_node_helper *)best_el->l_next->l_thing.w_obj)->last_tail, ((t_node_helper *)best_el->l_thing.w_obj)->num_notes + ((t_node_helper *)best_el->l_next->l_thing.w_obj)->num_notes);
        
    }

    llll_funall(out, (fun_fn)free_llllelems_lthing, NULL, 0, -1, FUNALL_PROCESS_WHOLE_SUBLISTS);
    llll_free(notes);
    return out;
}


long autospell_dg_get_SCE_fn(void *data, t_hatom *a, const t_llll *address)
{
    t_notation_obj *r_ob = (t_notation_obj *) ((void **)data)[0];
    t_autospell_params *params = (t_autospell_params *) ((void **)data)[1];
    t_pt3d *tot_pos = (t_pt3d *) ((void **)data)[2];
    double *tot_duration = (double *) ((void **)data)[3];
    
    if (hatom_gettype(a) == H_OBJ){
        t_note *note = (t_note *)hatom_getobj(a);
        t_pt3d this_pos = pitch_to_position_on_spiral_array(r_ob, params, note->pitch_displayed);
        double duration = 1; // all notes are equal
        
        tot_pos->x += duration * this_pos.x;
        tot_pos->y += duration * this_pos.y;
        tot_pos->z += duration * this_pos.z;
        *tot_duration += duration;
    }
    return 0;
}



t_pt3d autospell_dg_get_SCE(t_notation_obj *r_ob, t_autospell_params *params, t_llll *notes)
{
    double tot_duration = 0;
    t_pt3d tot_pos = {0, 0, 0};
    void *data[4];
    data[0] = r_ob;
    data[1] = params;
    data[2] = &tot_pos;
    data[3] = &tot_duration;
    
    llll_funall(notes, (fun_fn) autospell_dg_get_SCE_fn, data, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
    tot_pos.x /= tot_duration;
    tot_pos.y /= tot_duration;
    tot_pos.z /= tot_duration;
    
    return tot_pos;
}



long respell_note_wr_SCE_fn(void *data, t_hatom *a, const t_llll *address)
{
    t_notation_obj *r_ob = (t_notation_obj *) ((void **)data)[0];
    t_autospell_params *params = (t_autospell_params *) ((void **)data)[1];
    t_pt3d SCE = *((t_pt3d *) ((void **)data)[2]);
    
    if (hatom_gettype(a) == H_OBJ){
        t_note *note = (t_note *)hatom_getobj(a);
        autospell_respell_note_wr_to_SCE(r_ob, params, note, SCE);
    }
    return 0;
}


void autospell_dg_respell_notes_wr_SCE(t_notation_obj *r_ob, t_autospell_params *params, t_llll *notes, t_pt3d SCE)
{
    void *data[3];
    data[0] = r_ob;
    data[1] = params;
    data[2] = &SCE;
    
    llll_funall(notes, (fun_fn) respell_note_wr_SCE_fn, data, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
}





long autospell_dg_get_LCE_fn(void *data, t_hatom *a, const t_llll *address)
{
    t_notation_obj *r_ob = (t_notation_obj *) ((void **)data)[0];
    t_autospell_params *params = (t_autospell_params *) ((void **)data)[1];
    double *tot_pos = (double *) ((void **)data)[2];
    double *tot_duration = (double *) ((void **)data)[3];
    t_llll *positions = (t_llll *) ((void **)data)[4];
    
    if (hatom_gettype(a) == H_OBJ){
        t_note *note = (t_note *)hatom_getobj(a);
        double this_pos = pitch_to_position_on_line_of_fifths(note->pitch_displayed);
        double duration = 1; // all notes are equal

        llll_appenddouble(positions, this_pos);
        
        *tot_pos += duration * this_pos;
        *tot_duration += duration;
    }
    return 0;
}


void get_positive_and_negative_values_closest_to_zero(t_llll *ll, double *positive, double *negative)
{
    *positive = 32000;
    *negative = -32000;
    for (t_llllelem *elem = ll->l_head; elem; elem = elem->l_next) {
        double this_val = hatom_getdouble(&elem->l_hatom);
        if (this_val == 0) {
            *positive = *negative = 0;
            return;
        } else if (this_val < 0) {
            if (this_val > *negative)
                *negative = this_val;
        } else {
            if (this_val < *positive)
                *positive = this_val;
        }
    }
}

// slightly smarter
double autospell_dg_get_LCE(t_notation_obj *r_ob, t_autospell_params *params, t_llll *notes)
{
    double tot_duration = 0;
    double tot_pos = 0.;
    t_llll *positions = llll_get();
    void *data[5];
    data[0] = r_ob;
    data[1] = params;
    data[2] = &tot_pos;
    data[3] = &tot_duration;
    data[4] = positions;
    
    llll_funall(notes, (fun_fn) autospell_dg_get_LCE_fn, data, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
    tot_pos /= tot_duration;
    
    double positive = 0, negative = 0;
    get_positive_and_negative_values_closest_to_zero(positions, &positive, &negative);

    llll_free(positions);
    return tot_pos;
//    return positions->l_head ? (positive < fabs(negative) ? positive : negative) : 0;
}

long respell_note_wr_LCE_fn(void *data, t_hatom *a, const t_llll *address)
{
    t_notation_obj *r_ob = (t_notation_obj *) ((void **)data)[0];
    t_autospell_params *params = (t_autospell_params *) ((void **)data)[1];
    double LCE = *((double *) ((void **)data)[2]);
    
    if (hatom_gettype(a) == H_OBJ){
        t_note *note = (t_note *)hatom_getobj(a);
        autospell_respell_note_wr_to_LCE(r_ob, params, note, LCE, false, params->verbose);
    }
    return 0;
}


void autospell_dg_respell_notes_wr_LCE(t_notation_obj *r_ob, t_autospell_params *params, t_llll *notes, double LC)
{
    void *data[3];
    data[0] = r_ob;
    data[1] = params;
    data[2] = &LC;
    
    llll_funall(notes, (fun_fn) respell_note_wr_LCE_fn, data, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
}


long should_respell(double best_stdev, double extension_ms, long extension_idx)
{
    if (best_stdev < 3.)
        return 1;
    return 0.;
}

double get_range_firstonset(t_notation_obj *r_ob, t_llll *range)
{
    return notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&range->l_head->l_hatom));
}

double get_range_lastonset(t_notation_obj *r_ob, t_llll *range)
{
    return notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&range->l_tail->l_hatom));
}

double get_range_ext_ms(t_notation_obj *r_ob, t_llll *range)
{
    return notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&range->l_tail->l_hatom)) - notation_item_get_onset_ms(r_ob, (t_notation_item *)hatom_getobj(&range->l_head->l_hatom));
}

void notes_llll_to_text_buf(t_notation_obj *r_ob, t_llll *ll, char *buf, long buf_size)
{
    long cur = 0;
    for (t_llllelem *el = ll->l_head; el; el = el->l_next) {
        char txt[256];
        t_note *nt = (t_note *)hatom_getobj(&el->l_hatom);
        nt->pitch_displayed.toTextBuf(txt, 256);
        cur += snprintf_zero(buf + cur, buf_size - cur, "%s%s", txt, el->l_next ? " " : "");
    }
}

void positions_llll_to_text_buf(t_notation_obj *r_ob, t_llll *ll, char *buf, long buf_size)
{
    long cur = 0;
    for (t_llllelem *el = ll->l_head; el; el = el->l_next) {
        char txt[256];
        t_pitch p = position_on_line_of_fifths_to_pitch(hatom_getlong(&el->l_hatom));
        p.toTextBuf(txt, 256, false);
        cur += snprintf_zero(buf + cur, buf_size - cur, "%s%s", txt, el->l_next ? " " : "");
    }
}


void get_minmax_of_plain_long_llll(t_llll *ll, long *min, long *max)
{
    if (!ll || !ll->l_head)
        return;
    
    *min = *max = hatom_getlong(&ll->l_head->l_hatom);
    for (t_llllelem *el = ll->l_head->l_next; el; el = el->l_next) {
        long thisval = hatom_getlong(&el->l_hatom);
        if (thisval < *min)
            *min = thisval;
        if (thisval > *max)
            *max = thisval;
    }
}


char autospell_dg_respell_is_acceptable(t_notation_obj *r_ob, t_autospell_params *params, t_llll *positions)
{
    long minpos = 0, maxpos = 0;
    get_minmax_of_plain_long_llll(positions, &minpos, &maxpos);
    
    if (minpos < params->min_LOF_position || maxpos > params->max_LOF_position)
        return 0;
    
    if (params->discard_altered_repetitions) {
        // checking if same pitch appears repeated with increasing or decreasing number of accidentals, in which case it's not good
        for (t_llllelem *el = positions->l_head; el && el->l_next; el = el->l_next) {
            t_pitch p1 = position_on_line_of_fifths_to_pitch(hatom_getlong(&el->l_hatom));
            t_pitch p2 = position_on_line_of_fifths_to_pitch(hatom_getlong(&el->l_next->l_hatom));
            if (p1.degree() == p2.degree() && p1.alter() != p2.alter())
                return 0;
        }
    }
    
    return 1;
}

long autospell_dg_respell_notes_multitest(t_notation_obj *r_ob, t_autospell_params *params, t_llll *notes)
{
    char pitches_str[2048];
    pitches_str[0] = 0;
    
    if (!notes->l_head)
        return 0;
    
    // get extension
    double extension_ms = get_range_ext_ms(r_ob, notes);
    long extension_idx = notes->l_size;

    t_llll *snap_positions = llll_get();
    for (t_llllelem *nel = notes->l_head; nel; nel = nel->l_next) {
        t_llll *poss = notationobj_autospell_list_possibilities(r_ob, params, ((t_note *)hatom_getobj(&nel->l_hatom)));
        llll_chain(snap_positions, poss);
    }
    
    double best_pos = 0, best_stdev = 0, best_avg;
    char found_one = false;
    for (t_llllelem *el = snap_positions->l_head; el; el = el->l_next) {
        double this_pos = hatom_getdouble(&el->l_hatom);
        t_llll *respell_note_pos = llll_get();
        t_llll *respell_note_keys = llll_get();
        for (t_llllelem *nel = notes->l_head; nel; nel = nel->l_next) {
            t_voice *note_voice = notation_item_get_voice(r_ob, (t_notation_item *)hatom_getobj(&nel->l_hatom));
            llll_appendlong(respell_note_pos, autospell_respell_note_wr_to_LCE(r_ob, params, ((t_note *)hatom_getobj(&nel->l_hatom)), this_pos, true, false));
            llll_appenddouble(respell_note_keys, note_voice ? note_voice->key : 0);
        }
        double key_avg = llll_average_of_plain_double_llll(respell_note_keys);
        double avg;
        double stdev = llll_stdev_of_plain_double_llll(respell_note_pos, &avg);
        
        avg -= params->lineoffifth_bias;
        avg -= key_avg;
        
        if (params->verbose)
            positions_llll_to_text_buf(r_ob, respell_note_pos, pitches_str, 2048);
        
        if (!autospell_dg_respell_is_acceptable(r_ob, params, respell_note_pos)) {
            if (params->verbose)
                object_post((t_object *)r_ob, "  · Snapping to position %.2f gives %s, but snapped pitches are unacceptable", this_pos, pitches_str, stdev, avg, params->lineoffifth_bias);
        } else if (!found_one || fabs(stdev) < fabs(best_stdev) || (fabs(stdev) == fabs(best_stdev) && fabs(avg) < fabs(best_avg))) {
            found_one = true;
            best_stdev = stdev;
            best_avg = avg;
            best_pos = this_pos;

            if (params->verbose)
                object_post((t_object *)r_ob, "  · Snapping to position %.2f gives %s, with LCE stdev of %.2f and average of %.2f (with %.2f of bias): best so far", this_pos, pitches_str, stdev, avg, params->lineoffifth_bias);
        } else {
            if (params->verbose >= 2)
                object_post((t_object *)r_ob, "  · Snapping to position %.2f gives %s, with LCE stdev of %.2f and average of %.2f (with %.2f of bias)", this_pos, pitches_str, stdev, avg, params->lineoffifth_bias);
        }
        
        llll_free(respell_note_pos);
        llll_free(respell_note_keys);
    }
    
    // computing this threshold, depending on the value of the stdevthresh function
    t_hatom vars[2];
    hatom_setlong(vars, extension_idx);
    hatom_setdouble(vars + 1, extension_ms);
    t_hatom *res = lexpr_eval(params->stdev_thresh, vars);
    double this_stdev_thresh = hatom_getdouble(res);
    bach_freeptr(res);
    
    if (!found_one) {
        // no viable solution found
        if (params->verbose)
            object_post((t_object *)r_ob, "  · Won't respell: no solution found.");
        return 1;
        
    } else if (best_stdev > this_stdev_thresh) {
        if (params->verbose)
            object_post((t_object *)r_ob, "  · Won't respell: stdev = %.2f > %.2f (current parameter threshold)", best_stdev, this_stdev_thresh);
        return 1;
    } else {
        char verbose = params->verbose;
        params->verbose = 0;
        autospell_dg_respell_notes_wr_LCE(r_ob, params, notes, best_pos);
        params->verbose = verbose;
        return 0;
    }
}


long is_range_included(t_notation_obj *r_ob, t_llll *contained, t_llll *container)
{
    double contained_start = get_range_firstonset(r_ob, contained);
    double contained_end = get_range_lastonset(r_ob, contained);
    double container_start = get_range_firstonset(r_ob, container);
    double container_end = get_range_lastonset(r_ob, container);
    if (container_start <= contained_start && container_end >= contained_end)
        return 1;
    return 0;
}


void autospell_dg_delete_container_ranges(t_notation_obj *r_ob, t_llll *range, t_llllelem *range_el)
{
    t_llllelem *temp = range_el->l_next, *tempnext;
    while (temp) {
        t_llllelem *range_el_ok = (t_llllelem *)hatom_getobj(&temp->l_hatom);
        tempnext = temp->l_next;
        if (hatom_gettype(&range_el_ok->l_hatom) == H_LLLL) {
            t_llll *temp_range = llll_clone(hatom_getllll(&range_el_ok->l_hatom));
            llll_flatten(temp_range, -1, 0);
            if (is_range_included(r_ob, range, temp_range))
                llll_destroyelem(temp);
            llll_free(temp_range);
        }
        temp = tempnext;
    }
}


// if voice is a single voice, the single voice is considered;
// if voice is NULL, all voices are considered
void notationobj_autospell_dg_do(t_notation_obj *r_ob, t_autospell_params *par, t_voice *voice)
{
    char cant_respell_not_even_single_notes = false;
    lock_general_mutex(r_ob);
    
    t_llll *k_subsets_tree = autospell_dg_get_tree(r_ob, par, voice);
    
    t_llll *scanned = llll_scan(k_subsets_tree, true);
    llll_flatten(scanned, 1, 0);
    llll_rev(scanned, 1, 1);
    
//    dev_llll_print(scanned);
    
    for (t_llllelem *el = scanned->l_head; el; el = el->l_next) {
        t_llllelem *this_el = (t_llllelem *)hatom_getobj(&el->l_hatom);
        char type = hatom_gettype(&this_el->l_hatom);
        t_llll *range = NULL;
        
        if (type == H_LLLL) {
            range = llll_clone(hatom_getllll(&this_el->l_hatom));
            llll_flatten(range, -1, 0);
        } else if (type == H_OBJ) {
            range = llll_get();
            llll_appendobj(range, hatom_getobj(&this_el->l_hatom));
        }

        if (range) {
            if (par->verbose) {
                char buf[1024];
                notes_llll_to_text_buf(r_ob, range, buf, 1024);
                object_post((t_object *)r_ob, "Harmonizing pitches %s", buf);
            }
            
            // Harmonizing all the notes inside range
            if (autospell_dg_respell_notes_multitest(r_ob, par, range)) {
                // deleting all other scanned items that contain this one
                if (type == H_LLLL)
                    autospell_dg_delete_container_ranges(r_ob, range, el);
                else
                    cant_respell_not_even_single_notes = true;
            }
            llll_free(range);
        }
    }
    
    if (cant_respell_not_even_single_notes)
        object_warn((t_object *)r_ob, "Warning: some notes could not be respelled properly due to the too tight respelling conditions");
    
    llll_free(k_subsets_tree);
    llll_free(scanned);
    
    unlock_general_mutex(r_ob);
}


void notationobj_autospell_dg(t_notation_obj *r_ob, t_autospell_params *par)
{
    notationobj_autospell_trivial(r_ob, par); // we rewrite the single notes trivially as first step
    
    if (par->voicewise) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice))
            notationobj_autospell_dg_do(r_ob, par, voice);
    } else {
        notationobj_autospell_dg_do(r_ob, par, NULL);
    }
}




////


t_autospell_params notationobj_autospell_get_default_params(t_notation_obj *r_ob)
{
    t_autospell_params par;
    
    par.selection_only = false;
    par.max_LOF_position = 5 + 7;
    par.min_LOF_position = -1 - 7;
    par.w_sliding = 8;
    par.w_selfreferential = 2;
    par.f = 0.5;
    par.chunk_size_ms = 500;
    par.spiral_r = sqrt(2.);
    par.spiral_h = sqrt(15.);
    par.verbose = 0;
    par.thing = NULL;
    par.r_ob = r_ob;
    par.algorithm = _llllobj_sym_default; //gensym("chewandchen");
    
    par.ignore_locked_notes = 1;
    
    par.voicewise = 1;
    
    par.lineoffifth_bias = 2.;
    par.discard_altered_repetitions = true;
    
    t_llll *stdev_thresh_ll = llll_from_text_buf("21/(numnotes+1)");
    t_atom *stdev_thresh_av = NULL;
    long stdev_thresh_ac = llll_deparse(stdev_thresh_ll, &stdev_thresh_av, 0, LLLL_D_PARENS);
    par.stdev_thresh = lexpr_new(stdev_thresh_ac, stdev_thresh_av, subs_count, subs, (t_object *)r_ob);
    llll_free(stdev_thresh_ll);
    
    return par;
}

long llll_to_pos_helper(t_llll *ll)
{
    if (ll && ll->l_head) {
        switch (hatom_gettype(&ll->l_head->l_hatom)) {
            case H_LONG:
                return hatom_getlong(&ll->l_head->l_hatom);
                break;
            case H_PITCH:
                return pitch_to_position_on_line_of_fifths(hatom_getpitch(&ll->l_head->l_hatom));
                break;
            case H_SYM:
            {
                long res = 0;
                t_symbol *s = hatom_getsym(&ll->l_head->l_hatom);
                char temp[2048];
                snprintf_zero(temp, 2048, "%s0", s ? s->s_name : "C");
                t_llll *temp_ll = llll_from_text_buf(temp);
                if (temp_ll && temp_ll->l_head) {
                    if (hatom_gettype(&temp_ll->l_head->l_hatom) == H_PITCH)
                        res = pitch_to_position_on_line_of_fifths(hatom_getpitch(&temp_ll->l_head->l_hatom));
                }
                llll_free(temp_ll);
                return res;
            }
                break;
            default:
                break;
        }
    }
        return 0;
}

void notationobj_autospell_parseargs(t_notation_obj *r_ob, t_llll *args)
{

    long maxsharps = -1, minflats = -1;
    t_llll *maxpitch = NULL, *minpitch = NULL;
    t_llll *stdev_thresh_ll = NULL;
    t_autospell_params par = notationobj_autospell_get_default_params(r_ob);
    
    llll_parseargs_and_attrs_destructive((t_object *) r_ob, args, "iiiddddiiisdilllii", gensym("selection"), &par.selection_only, gensym("sliding"), &par.w_sliding, gensym("selfreferential"), &par.w_selfreferential, gensym("locality"), &par.f, gensym("winsize"), &par.chunk_size_ms, gensym("spiralr"), &par.spiral_r, gensym("spiralh"), &par.spiral_h, gensym("maxflats"), &minflats, gensym("maxsharps"), &maxsharps, gensym("verbose"), &par.verbose, gensym("algorithm"), &par.algorithm, gensym("bias"), &par.lineoffifth_bias, gensym("voicewise"), &par.voicewise, gensym("sharpest"), &maxpitch, gensym("flattest"), &minpitch, gensym("stdevthresh"), &stdev_thresh_ll, gensym("discardalteredrepetitions"), &par.discard_altered_repetitions, gensym("ignorelocked"), &par.ignore_locked_notes);
    
    
    if (stdev_thresh_ll) {
        if (par.stdev_thresh)
            lexpr_free(par.stdev_thresh);
        
        t_atom *stdev_thresh_av = NULL;
        long stdev_thresh_ac = llll_deparse(stdev_thresh_ll, &stdev_thresh_av, 0, LLLL_D_PARENS);
        par.stdev_thresh = lexpr_new(stdev_thresh_ac, stdev_thresh_av, subs_count, subs, (t_object *)r_ob);
        bach_freeptr(stdev_thresh_av);
    }

    
    if (maxsharps >= 0)
        par.max_LOF_position = 5 + 7 * maxsharps;
    if (minflats >= 0)
        par.min_LOF_position = -1 - 7 * minflats;
    
    if (maxpitch && maxpitch->l_head)
        par.max_LOF_position = llll_to_pos_helper(maxpitch);
    if (minpitch && minpitch->l_head)
        par.min_LOF_position = llll_to_pos_helper(minpitch);
    
    
    if (is_symbol_in_llll_first_level(args, _llllobj_sym_selection))
        par.selection_only = true;
    
    if (r_ob->whole_obj_undo_tick_function)
        (r_ob->whole_obj_undo_tick_function)(r_ob);
    
    if (par.algorithm == gensym("chewandchen"))
        notationobj_autospell_chew_and_chen(r_ob, &par);
    else if (par.algorithm == gensym("atonal"))
        notationobj_autospell_dg(r_ob, &par);
    else
        notationobj_autospell_trivial(r_ob, &par);
    
    if (par.stdev_thresh)
        lexpr_free(par.stdev_thresh);

    handle_change_if_there_are_free_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_RESPELL);
}
