/**
	notation_pitches.c - function handling pitches

	by Daniele Ghisi
*/

#include "bach.h"
#include "notation.h" // header with all the structures for the notation objects

//Midicents of the screen diatonic note, ignoring accidental. For example, for the Eb above the middle C, this will be 6400 (the midicents of the E)
long note_get_screen_midicents(t_note *nt)
{
    return nt->pitch_displayed.toMC_wo_accidental();
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


void note_appendpitch_to_llll_for_separate_syntax(t_notation_obj *r_ob, t_llll *ll, t_note *note)
{
    note_appendpitch_to_llll(r_ob, ll, note, r_ob->output_pitches_separate);
}


void note_appendpitch_to_llll_for_gathered_syntax_or_playout(t_notation_obj *r_ob, t_llll *ll, t_note *note, e_data_considering_types mode)
{
    char pitchmode;
    
    switch (mode) {
        case k_CONSIDER_FOR_SAVING:
        case k_CONSIDER_FOR_SAVING_WITH_BW_COMPATIBILITY:
        case k_CONSIDER_ALL_NOTES:
        case k_CONSIDER_FOR_DUMPING:
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
        case k_CONSIDER_FOR_PLAYING_ONLY_IF_SELECTED:
        case k_CONSIDER_FOR_PLAYING_AND_ALLOW_PARTIAL_LOOPED_NOTES:
        case k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE:
            pitchmode = r_ob->output_pitches_playout;
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
    if (note_is_enharmonicity_userdefined(nt)) { // there _are_ accidentals user-defined!!!
        mc_to_screen_approximations(r_ob, nt->midicents, &auto_screen_mc, &auto_screen_acc, voice->acc_pattern, voice->full_repr);
        
        if (!(is_natural_note(note_get_screen_midicents(nt)))) {
            object_error((t_object *)r_ob, "Error: wrong approximation found! Automatically changed to default.");
            long steps = midicents_to_diatsteps_from_C0(r_ob, auto_screen_mc);
            nt->pitch_displayed.set(steps % 7, auto_screen_acc, steps / 7);
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
        nt->pitch_displayed.set(steps % 7, auto_screen_acc, steps / 7);
    }
}





//// AUTOMATIC RESPELLING ALGORITHM
//// Implemented from Chew and Chen (2003, 2005)

typedef struct _autospell_params
{
    char    selection_only;
    long    verbose;

    t_symbol    *algorithm;

    
    // PARAMETERS FOR FORCE DIRECTED
    long    numiter;
    double  strength_neighbors;
    double  strength_enharmonic;
    
    
    // PARAMETERS FOR CHEW AND CHEN ALGORITHM
    double  chunk_size_ms;
    double  spiral_r;
    double  spiral_h;
    
    long    max_num_sharps;
    long    max_num_flats;
    
    long    w_sliding;          /// NUmber of chunks in sliding window
    long    w_selfreferential;  /// Number of chunks in selfreferential window
    double  f;                  ///< f parameter (see paper)
    
    
    // handy pointers for mergesort
    t_notation_obj  *r_ob;
    void            *thing;
} t_autospell_params;



t_pitch position_on_line_of_fifths_to_pitch(long pos)
{
    return t_pitch::middleC + pos * t_pitch(4);
}


long pitch_to_position_on_line_of_fifths(t_pitch p)
{
    t_pitch temp = t_pitch(p.degree(), p.alter(), 0);
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
            return round(temp.toMC() / lowG.toMC());
        return LONG_MAX;
    }

    if (temp.alter() < 0) {
        long count = 0;
        while (temp % lowG != 0 && count < MAX_TRY) {
            temp -= octave;
            count++;
        }
        if (temp % lowG == 0)
            return round(temp.toMC() / lowG.toMC());
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
    if (voice) {
        key = voice->key;
    }
    
    long pos = pitch_to_position_on_line_of_fifths(note->pitch_displayed);
    pos -= key; // indeed, maxnumflats and maxnumsharps are WITH RESPECT to the KEY!
    
    // now, all possibilities must lie be between (-1 - 7 * par->max_num_flats) et (5 + 7 * par->max_num_sharps)
    pos = positive_mod(pos, 12);
    
    for (long i = pos; i <= 5 + 7 * par->max_num_sharps; i += 12)
        llll_appendlong(out, i + key);

    for (long i = pos - 12; i >= -1 - 7 * par->max_num_flats; i -= 12)
        llll_appendlong(out, i + key);

    return out;
}

t_llll *notationobj_autospell_get_chunks(t_notation_obj *r_ob, t_autospell_params *par, long idx_from, long idx_to)
{
    double single_chunk_dur = par->chunk_size_ms;
    double segm_start = idx_from * single_chunk_dur;
    double segm_end = (idx_to + 1) * single_chunk_dur;
    double segm_dur = segm_end - segm_start;
    t_llll *out = llll_get();
    
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = get_next_voice(r_ob, voice)) {
        for (t_chord *chord = get_first_chord(r_ob, voice); chord; chord = get_next_chord(chord)) {
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





long llll_sort_by_distance_to_center_of_effect(void *spell_parameters, t_llllelem *a, t_llllelem *b)
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


t_pitch notationobj_autospell_match_pitch_with_position_on_line_of_fifths(t_notation_obj *r_ob, t_autospell_params *par, t_pitch orig_pitch, long pos)
{
    t_pitch new_pitch = position_on_line_of_fifths_to_pitch(pos);
    new_pitch.set(new_pitch.degree(), new_pitch.alter(), orig_pitch.octave());
    long new_pitch_octave = orig_pitch.octave() + floor((orig_pitch.toMC() - new_pitch.toMC())/1200);
    
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

// respell a note with respect to a center of effect
void notationobj_autospell_respell_notewr_to_center_of_effect(t_notation_obj *r_ob, t_autospell_params *par, t_note *note, t_pt3d center_of_effect)
{
    t_llll *possibilities = notationobj_autospell_list_possibilities(r_ob, par, note);

    if (possibilities && possibilities->l_head) {
        par->thing = &center_of_effect;
        llll_mergesort_inplace(&possibilities, llll_sort_by_distance_to_center_of_effect, par);
        par->thing = NULL;
        
        if (par->verbose) {
            object_post((t_object *)r_ob, "  Possibilities, in order of distance:");
            for (t_llllelem *el = possibilities->l_head; el; el = el->l_next) {
                t_pitch thispitch = notationobj_autospell_match_pitch_with_position_on_line_of_fifths(r_ob, par, note->pitch_displayed, hatom_getlong(&el->l_hatom));
                char notename[128];
                snprintf_zero(notename, 128, "%s", thispitch.toCString());
                object_post((t_object *)r_ob, "    %s (dist: %.3f)%s", notename, sqrt(pt3d_distance_squared(center_of_effect, pitch_to_position_on_spiral_array(r_ob, par, thispitch))), el->l_prev ? "" : " <-- chosen");
            }
        }

        notationobj_autospell_set_note_pitch_to_position_on_line_of_fifths(r_ob, par, note, hatom_getlong(&possibilities->l_head->l_hatom));
    }
    llll_free(possibilities);
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

void notationobj_autospell_chew_and_chen(t_notation_obj *r_ob, t_autospell_params *par)
{
    double chunk_size_ms = par->chunk_size_ms;
    long num_chunks = ceil(r_ob->length_ms_till_last_note/chunk_size_ms);
    char buf_verbose[1024];
    lock_general_mutex(r_ob);
    
    
    // We implement the algorithms proposed in Chew and Chen, "Determining Context-Defining Windows: Pitch Spelling using the Spiral Array"
    // (The way notationobj_autospell_get_chunks() is called should be largely optimizable).
    for (long j = 0; j < num_chunks; j++) {
        // FIRST PHASE: make each note consistent with the sliding_win
        t_llll *thischunk = notationobj_autospell_get_chunks(r_ob, par, j, j);
        t_llll *sliding_win = notationobj_autospell_get_chunks(r_ob, par, j - par->w_sliding, j - 1);
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
                if (par->verbose)
                    object_post((t_object *)r_ob, "      • Spelling note %s, starting at %.0fms", note->pitch_displayed.toCString(), notation_item_get_onset_ms(r_ob, (t_notation_item *)note));
                
                notationobj_autospell_respell_notewr_to_center_of_effect(r_ob, par, note, sliding_win_CE);
            }
        }
        
        
        // SECOND PHASE: the algorithm is allowed to revisit previous decisions
        t_llll *selfreferential_win = notationobj_autospell_get_chunks(r_ob, par, j - par->w_selfreferential, j);
        t_pt3d selfreferential_win_CE = notationobj_autospell_get_center_of_effect(r_ob, par, selfreferential_win);
        t_llll *global_win = notationobj_autospell_get_chunks(r_ob, par, 0, j-1); // OR j ????
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
            object_post((t_object *)r_ob, "      • Nothing to do, center of effect is NaN");
        } else {
            for (t_llllelem *elem = thischunk->l_head; elem; elem = elem->l_next) {
                t_llll *ll = hatom_getllll(&elem->l_hatom);
                t_note *note = (t_note *)hatom_getobj(&ll->l_head->l_hatom);
                long starts = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom);
                
                if (starts) { // we must spell it
                    if (par->verbose)
                        object_post((t_object *)r_ob, "      • Spelling note %s, starting at %.0fms", note->pitch_displayed.toCString(), notation_item_get_onset_ms(r_ob, (t_notation_item *)note));
                    
                    notationobj_autospell_respell_notewr_to_center_of_effect(r_ob, par, note, weighted_CE);
                }
            }
        }
        
        llll_free(selfreferential_win);
        llll_free(thischunk);
        llll_free(sliding_win);
    }
    
    unlock_general_mutex(r_ob);
}





///// SIMULATED ANNEALING ALGO

t_llll *autospell_get_all_notes(t_notation_obj *r_ob, t_autospell_params *par)
{
    t_llll *out = llll_get();
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = get_next_voice(r_ob, voice)) {
        for (t_chord *chord = get_first_chord(r_ob, voice); chord; chord = get_next_chord(chord)) {
            for (t_note *note = chord->firstnote; note; note = note->next) {
                if (!par->selection_only || notation_item_is_globally_selected(r_ob, (t_notation_item *)note)) {
                    llll_appendobj(out, note);
                }
            }
        }
    }
    
    return out;
    
}


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
        notationobj_autospell_respell_notewr_to_center_of_effect(r_ob, par, nodes[i].note, nodes[i].pt);
    }
    
    
    bach_freeptr(nodes);
    
    unlock_general_mutex(r_ob);
}







t_autospell_params notationobj_autospell_get_default_params(t_notation_obj *r_ob)
{
    t_autospell_params par;
    
    par.selection_only = false;
    par.max_num_flats = par.max_num_sharps = 1;
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
    
    
    par.numiter = 10;
    par.strength_neighbors = 1.;
    par.strength_enharmonic = 1.;
    
    return par;
}

void notationobj_autospell_parseargs(t_notation_obj *r_ob, t_llll *args)
{
    t_autospell_params par = notationobj_autospell_get_default_params(r_ob);
    
    llll_parseargs_and_attrs_destructive((t_object *) r_ob, args, "iiiddddiiisidd", gensym("selection"), &par.selection_only, gensym("numsliding"), &par.w_sliding, gensym("numselfreferential"), &par.w_selfreferential, gensym("thresh"), &par.f, gensym("winsize"), &par.chunk_size_ms, gensym("spiralr"), &par.spiral_r, gensym("spiralh"), &par.spiral_h, gensym("maxflats"), &par.max_num_flats, gensym("maxsharps"), &par.max_num_sharps, gensym("verbose"), &par.verbose, gensym("algorithm"), &par.algorithm, gensym("numiter"), &par.numiter, gensym("strength"), &par.strength_neighbors, gensym("strengthenar"), &par.strength_enharmonic);
    
    if (is_symbol_in_llll_first_level(args, _llllobj_sym_selection))
        par.selection_only = true;
    
    if (r_ob->whole_obj_undo_tick_function)
        (r_ob->whole_obj_undo_tick_function)(r_ob);
    
    if (par.algorithm == gensym("chewandchen"))
        notationobj_autospell_chew_and_chen(r_ob, &par);
    else
        notationobj_autospell_force_directed(r_ob, &par);
    
    handle_change_if_there_are_free_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_AUTOSPELL);
}
