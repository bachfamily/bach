/*
 *  score_api.h
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

#ifndef _SCORE_API_H_
#define _SCORE_API_H_

#include "foundation/bach.h"


#ifdef BACH_MAX
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_critical.h"
#endif

#ifdef JUCE_MAX
#include "bach_jucewrapper.h"
#include "juce_paint_wrappers.h"
#endif

#include <stdio.h>
#include <locale.h>
#include <time.h> 
#include "notation/notation.h" // header with all the structures for the notation objects

typedef struct _score // [bach.score] structure
{
    t_notation_obj r_ob;  // root: notation object (all the common attributes) 

    // elements in the score
    t_scorevoice    *firstvoice;
    t_scorevoice    *lastvoice;
    
    
    double            non_inspector_ux_screen_start;
    
    // utilities
    char        durations_given;
    char        need_repaint;
    char        can_need_repaint;
    char        not_clicked_anything;
    char        n_rebuild;
    char        debug;
    char        must_append_measures;
    
    long m_in;   // space for the inlet number used by all the proxies
    void *m_proxy1;
    void *m_proxy2;
    void *m_proxy3;
    void *m_proxy4;
    void *m_proxy5;
    void *m_proxy6;

} t_score;





// verbose?
#define verbose        false

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif
    
void score_hidecursor(t_score *x);
void score_showcursor(t_score *x);

void scoreapi_setcursor_from_double(t_score *x, double pos);
void scoreapi_setcursor_from_llll(t_score *x, t_llll *args, long flags);

// inscreen and playing
char scoreapi_inscreen(t_score *x, t_llll *inscreen);
char scoreapi_inscreenpos(t_score *x, t_llll *inscreen);
char scoreapi_inscreenmeas(t_score *x, t_llll *inscreenmeas);

void sync_loop_ms_with_loop_tp(t_score *x);

t_max_err score_setattr_clefs(t_score *x, t_object *attr, long ac, t_atom *av);
t_max_err score_setattr_keys(t_score *x, t_object *attr, long ac, t_atom *av);
t_max_err score_setattr_align(t_score *x, t_object *attr, long ac, t_atom *av);

void scoreapi_set_tonedivision(t_score *x, long s);
void scoreapi_set_accidentalsgraphic(t_score *x, long s);
void scoreapi_set_accidentalspreferences(t_score *x, long s);
void scoreapi_set_enharmonictable(t_score *x, long ac, t_atom *av);
void scoreapi_set_nonantialiasedstaff(t_score *x, long l);
void scoreapi_set_zoom(t_score *x, double z);
void scoreapi_set_vzoom(t_score *x, double z);
void scoreapi_set_noteheads_font(t_score *x, t_symbol *font);
void scoreapi_set_accidentals_font(t_score *x, t_symbol *font);
void scoreapi_set_articulations_font(t_score *x, t_symbol *font);
void scoreapi_set_autoretranscribe(t_score *x, long l);
void scoreapi_set_outputtrees(t_score *x, long l);
void scoreapi_set_showaccidentalstiepreferences(t_score *x, long l);
void scoreapi_set_cautionaryaccidentals(t_score *x, long l);
void scoreapi_set_cautionaryaccidentalsdecay(t_score *x, long l);
void scoreapi_set_cautionaryaccidentalsremind(t_score *x, long l);
void scoreapi_set_restswithinbeaming(t_score *x, long l);
void scoreapi_set_maxrestfloatingsteps(t_score *x, long l);
void scoreapi_set_constraintbeamsinspaces(t_score *x, long l);
void scoreapi_set_maxbeamslope(t_score *x, double d);
void scoreapi_set_maxbeamdeltay(t_score *x, long d);
void scoreapi_set_reversegracedirection(t_score *x, long d);
void scoreapi_set_tieassignpitch(t_score *x, double d);
void scoreapi_set_maxdots(t_score *x, long l);
void scoreapi_set_centeredwholerests(t_score *x, long l);
void scoreapi_set_dontbeamtupletswithotherthings(t_score *x, long l);
void scoreapi_set_admitdottedtuplets(t_score *x, long l);
void scoreapi_set_showtimesignatures(t_score *x, long l);
void scoreapi_set_allowbeaming(t_score *x, long l);
void scoreapi_set_autocompletemeasures(t_score *x, long l);
void scoreapi_set_spacingparameter(t_score *x, double d);
void scoreapi_set_spacingwidth(t_score *x, double d);
void scoreapi_set_spacingproportionality(t_score *x, double d);
void scoreapi_set_minmeaswidth(t_score *x, double d);
void scoreapi_set_minmeaswidthpersymunit(t_score *x, double d);
void scoreapi_set_syncopationasymratio(t_score *x, double d);
void scoreapi_set_syncopationposdurratio(t_score *x, double d);
void scoreapi_set_syncopationmaxdots(t_score *x, long l);
void scoreapi_set_lyricsaffectspacing(t_score *x, long s);
void scoreapi_set_dynamicsaffectspacing(t_score *x, long s);
void scoreapi_set_hidetupletshapeonbeams(t_score *x, long l);
void scoreapi_set_treehandling(t_score *x, long l);
void scoreapi_set_maketreecompatiblewithts(t_score *x, long l);
void scoreapi_set_extendbeamsoverrests(t_score *x, long l);
void scoreapi_set_leveltobeam(t_score *x, long l);
void scoreapi_set_breakrootlevelbeam(t_score *x, long l);
void scoreapi_set_jointuplets(t_score *x, long l);
void scoreapi_set_simplifytuplets(t_score *x, long l);
void scoreapi_set_showtupletspreferences(t_score *x, long l);
void scoreapi_set_beamgracesequences(t_score *x, long l);
void scoreapi_set_gracedur(t_score *x, t_symbol *s);
void scoreapi_set_gracemaxperc(t_score *x, double d);

void recalculate_all_chord_parameters(t_score *x);
void recalculate_all_tuttipoints_spacing(t_score *x);
void recalculate_all_beamings(t_score *x);
void recalculate_all_utf_measure_timesignatures(t_score *x);
void check_all_measures_autocompletion(t_score *x);
void check_all_measures_ties(t_score *x);
void recompute_all(t_score *x);
void recompute_all_and_redraw(t_score *x);
void recompute_all_except_for_beamings_and_autocompletion(t_score *x);

void remove_all_tuttipoints_flag_modified(t_score *x);
char scoreapi_inscreenmeas_do(t_score *x, t_measure *start_meas, t_measure *end_meas);


t_scorevoice* nth_scorevoice(t_score *x, long n);
t_llll *getdomain_from_uxstart(t_score *x, double ux_start, t_symbol *message_selector, t_symbol *label);
t_llll *scoreapi_testdomain(t_score *x, t_llll *dom, t_symbol *label);
t_llll *scoreapi_getdomain(t_score *x, t_symbol *label);
void scoreapi_getdomainpixels(t_score *x, double *start, double *end);
t_max_err scoreapi_getpixelpos(t_score *x, t_llll *open_timepoint_syntax, double *pos, long flags);
double scoreapi_getlength(t_score *x);
double scoreapi_get_end_ux(t_score *x);
void send_all_values_as_llll(t_score *x, long send_what_for_header, t_symbol *gatheredsyntax_router);
void clear_voice(t_score *x, t_scorevoice *voice);
void clear_measure(t_score *x, t_measure *measure, char also_reset_all_attributes, char also_clear_ties_from, char also_clear_tempi); 
void set_all_tstempo_values_from_llll(t_score *x, t_llll* measureinfo, long num_introduced_voices);
void set_all_durations_values_from_llll(t_score *x, t_llll* durations, long num_introduced_voices);
void set_all_cents_values_from_llll(t_score *x, t_llll* cents, char force_append_notes, long num_introduced_voices);
void set_all_velocities_values_from_llll(t_score *x, t_llll* velocities, long num_introduced_voices);
void set_all_ties_values_from_llll(t_score *x, t_llll* ties, long num_introduced_voices);
void set_all_graphic_values_from_llll(t_score *x, t_llll* graphic);
void set_all_breakpoints_values_from_llll(t_score *x, t_llll* breakpoints);
void set_all_articulations_values_from_llll(t_score *x, t_llll* articulations);
void set_all_slots_values_from_llll(t_score *x, t_llll* slots);
void set_voice_tstempo_values_from_llll(t_score *x, t_llll* measureinfo, t_scorevoice *voice);
void set_measure_cents_values_from_llll(t_score *x, t_llll* measure_midicents, t_measure *measure, char force_append_notes);
void set_voice_cents_values_from_llll(t_score *x, t_llll* midicents, t_scorevoice *voice, char force_append_notes);
void set_voice_durations_values_from_llll(t_score *x, t_llll* durations, t_scorevoice *voice);
void set_measure_durations_values_from_llll(t_score *x, t_llll* durations, t_measure *measure);
void set_voice_velocities_values_from_llll(t_score *x, t_llll* velocities, t_scorevoice *voice);
void set_measure_velocities_values_from_llll(t_score *x, t_llll* measure_velocities, t_measure *measure);
void set_voice_ties_values_from_llll(t_score *x, t_llll* ties, t_scorevoice *voice);
void set_measure_ties_values_from_llll(t_score *x, t_llll* measure_ties, t_measure *measure);
void set_all_extras_values_from_llll(t_score *x, t_llll* extras);
void set_voice_graphic_values_from_llll(t_score *x, t_llll* graphic, t_scorevoice *voice);
void set_voice_breakpoints_values_from_llll(t_score *x, t_llll* breakpoints, t_scorevoice *voice);
void set_voice_articulation_values_from_llll(t_score *x, t_llll* articulations, t_scorevoice *voice);
void set_voice_slots_values_from_llll(t_score *x, t_llll* slots, t_scorevoice *voice);
void set_measure_graphic_values_from_llll(t_score *x, t_llll* graphic, t_measure *measure);
void set_measure_breakpoints_values_from_llll(t_score *x, t_llll* breakpoints, t_measure *measure);
void set_measure_articulations_values_from_llll(t_score *x, t_llll* articulations, t_measure *measure);
void set_measure_slots_values_from_llll(t_score *x, t_llll* slots, t_measure *measure);
void set_clefs_from_llll(t_score *x, t_llll* clefs);
void set_keys_from_llll(t_score *x, t_llll* keys);
void set_measure_from_llll(t_score *x, t_measure *measure, t_llll *measelemllll, char also_set_tempi,
                           char when_no_ts_given_use_previous_measure_ts, char *need_update_solos);
void create_whole_score_undo_tick(t_score *x);
void changed_bang(t_score *x, int change_type);
void retranscribe_voice(t_score *x, t_scorevoice *voice);
void score_retranscribe(t_score *x, t_symbol *s, long argc, t_atom *argv);
void clear_score_body(t_score *x, long voicenum, long min_num_voices_to_be_cleared = 0); // voicenum is 0-based; special values include: -1 meaning: all voices (up to the current voice number); -2 meaning: all voices up to the CONST_MAX_VOICES
void score_clear_all(t_score *x);
void score_cleararticulations(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_clearnotes(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_cleartempi(t_score *x, t_symbol *s, long argc, t_atom *argv);
char pop_tempo_over_chord(t_score *x, t_chord *chord, char in_all_voices);
void verbose_print(t_score *x);
void merge_chords_and_sum_durations(t_score *x, t_chord *chord1, t_chord *chord2);
t_note* merge_chords(t_score *x, t_chord *chord1, t_chord *chord2, char flags, char transfer_mousedown, char assign_IDs);
void insert_measure(t_score *x, t_scorevoice *voice, t_measure *measure_to_insert, t_measure *after_this_measure, unsigned long force_ID);
void turn_chord_into_rest(t_score *x, t_chord *chord);
void turn_chord_into_rest_or_into_note(t_score *x, t_chord *chord, double mc);
t_chord* addchord_in_measure_from_notes(t_score *x, t_measure *measure, t_chord *after_this_chord, t_rational r_sym_duration, long ID, long num_notes, t_note *firstnote, t_note *lastnote, unsigned long force_ID);
t_chord* addchord_in_measure_from_values(t_score *x, t_measure *measure, t_chord *after_this_chord, t_rational r_sym_duration, long ID, long num_notes, long argc, double *argv, long* num_bpt, double *bpt, long slot_list_length, t_atom *slots, unsigned long force_ID, unsigned long *force_note_IDs);
void check_measure_autocompletion(t_score *x, t_measure *measure);
char merge(t_score *x, t_rational threshold_sym, double threshold_cents, char gathering_policy_sym, char gathering_policy_cents, char selection_only);
char chord_merge_mc(t_score *x, t_chord *chord, double threshold_cents, char gathering_policy_cents);
long get_max_num_measures(t_score *x, long *voice);
char delete_measure(t_score *x, t_measure *measure, t_chord *update_chord_play_cursor_to_this_chord_if_needed, char *need_update_solos);
char voiceensemble_delete_measure(t_score *x, t_measure *measure, t_chord *update_chord_play_cursor_to_this_chord_if_needed, char *need_check_solos, char add_undo_ticks);
void turn_measure_into_single_rest(t_score *x, t_measure *measure);
void voiceensemble_turn_measure_into_single_rest(t_score *x, t_measure *measure);
void measure_delete_all_chords(t_score *x, t_measure *measure);
char turn_selection_into_rests(t_score *x, char delete_notes, char delete_lyrics, char delete_dynamics, t_llll *slots_to_transfer_to_next_note_in_chord_1based = NULL, char transfer_slots_even_if_empty = false, char transfer_slots_even_to_rests = false, char also_clear_selection = true);
long score_oksize(t_score *x, t_rect *newrect);
long get_global_num_notes(t_score *x);
long get_global_num_notes_voice(t_scorevoice *voice);
t_chord *split_chord(t_score *x, t_chord *chord, long how_many, long also_split_rests);
char has_measure_attached_markers(t_score *x, t_measure *meas);

void score_delete_voice(t_score *x, t_scorevoice *voice);
void score_delete_voiceensemble(t_score *x, t_voice *any_voice_in_voice_ensemble);
void score_move_and_reinitialize_last_voice(t_score *x, t_scorevoice *after_this_voice, t_symbol *key, long clef, t_llll *voicename, long midichannel, long idx_of_the_stafflist_element_in_llll, t_scorevoice *ceilmeasure_from_this_voice);
void score_swap_voices(t_score *x, t_scorevoice *v1, t_scorevoice *v2);
void score_swap_voiceensembles(t_score *x, t_scorevoice *v1, t_scorevoice *v2);
t_tuttipoint *build_tuttipoint(t_score *x);

// domain
void send_domain(t_score *x, long outlet, t_symbol *label);

// inscreen
char force_inscreen_ux(t_score *x, double inscreen_ux, char send_domain_if_changed);
char force_inscreenpos_ux(t_score *x, double position, double inscreen_ux, char also_send_domain, char also_move_mousedown_pt);
char force_inscreen_ux_to_boundary(t_score *x, double inscreen_ux, char clip_to_length, char send_domain_if_changed, char also_move_mousedown_pt);
char force_inscreen_ux_rolling(t_score *x, double inscreen_ux, char clip_to_length, char send_domain_if_changed, char also_move_mousedown_pt);
void force_notation_item_inscreen(t_score *x, t_notation_item *it, void *dummy);

void scoreapi_initscore_step01(t_score *x);
void scoreapi_initscore_step02(t_score *x);
void delete_measure_tempi(t_score *x, t_measure *measure);
void delete_voice_tempi(t_score *x, t_scorevoice *voice);
void deletetuttipoint(t_score *x, t_tuttipoint *pt);
void delete_all_tuttipoints(t_score *x, char also_clear_measure_tuttipoint_references);
void scoreapi_destroyscore(t_score *x);

void calculate_all_chords_remaining_onsets(t_score *x);
void calculate_all_tempi_remaining_onsets(t_score *x);
void calculate_tuttipoints(t_score *x);
void insert_tuttipoint(t_score *x, t_tuttipoint *tuttipoint_to_insert, t_tuttipoint *after_this_tuttipoint);
void refresh_all_tuttipoints_offset_ux(t_score *x);
void tuttipoint_calculate_spacing(t_score *x, t_tuttipoint *tpt);
void tuttipoint_refine_spacing(t_score *x, t_tuttipoint *tpt);
long get_num_chords(t_score *x);
t_chord* ID_to_chord(t_score *x, long ID_to_find);
void refresh_measure_numbers(t_score *x, t_scorevoice *voice);
void reset_all_articulations_position(t_score *x);

#ifdef BACH_SUPPORT_SLURS
void reset_all_slurs_position(t_score *x);
#endif


char are_all_tempi_synchronous(t_score *x);
char are_all_time_signatures_synchronous(t_score *x);
char are_all_measureinfo_synchronous(t_score *x);
char voiceensemble_are_all_measureinfo_synchronous(t_score *x, t_voice *any_voice_in_voiceensemble);
double chord_get_spacing_correction_for_voiceensembles(t_score *x, t_chord *chord, double *accidental_ushift);

void perform_analysis_and_change(t_score *x, t_jfont *jf_lyrics_nozoom, t_jfont *jf_dynamics_nozoom, t_jfont *jf_dynamics_roman_nozoom, long beaming_calculation_flags);
void check_tempi(t_score *x);
t_llll* get_score_values_as_llll(t_score *x, e_data_considering_types for_what, long get_what, char tree, char also_get_level_information, char also_lock_general_mutex, char explicitly_get_also_default_stuff, t_symbol *router = NULL);
t_llll* get_subvoice_values_as_llll(t_score *x, t_scorevoice *voice, long start_meas, long end_meas, char tree, char also_get_level_information);
t_llll* get_scorevoice_values_as_llll(t_score *x, t_scorevoice *voice, e_data_considering_types for_what, char tree, char also_get_level_information);
t_llll* get_all_measuresinfo_values_as_llll(t_score *x);
t_llll* get_all_cents_values_as_llll(t_score *x, char tree, e_output_pitches pitch_output_mode = k_OUTPUT_PITCHES_DEFAULT);
t_llll* get_all_durations_values_as_llll(t_score *x, char tree);
t_llll* get_all_velocities_values_as_llll(t_score *x, char tree);
t_llll* get_all_ties_values_as_llll(t_score *x, char tree);
t_llll* get_all_extras_values_as_llll(t_score *x, char tree);
t_llll* get_all_pixel_values_as_llll(t_score *x);
t_llll* get_all_measure_pixel_values_as_llll(t_score *x);
t_llll* get_timesignature_as_llll(t_timesignature *ts);
t_llll* get_voice_measuresinfo_values_as_llll(t_scorevoice *voice);
t_llll* get_voice_cents_values_as_llll(t_score *x, t_scorevoice *voice, char tree, e_output_pitches pitch_output_mode = k_OUTPUT_PITCHES_DEFAULT);
t_llll* get_voice_ties_values_as_llll(t_scorevoice *voice, char tree);
t_llll* get_voice_durations_values_as_llll(t_score *x, t_scorevoice *voice, char tree);
t_llll* measure_get_durations_values_as_llll(t_score *x, t_measure *measure, char tree);
t_llll* measure_get_chords_obj_as_llll(t_measure *measure);
t_llll* measure_get_velocities_values_as_llll(t_measure *measure, char tree);
t_llll* get_voice_velocities_values_as_llll(t_scorevoice *voice, char tree);
t_llll* measure_get_pixel_values_as_llll(t_score *x, t_scorevoice *voice, t_measure *measure);
t_llll* get_voice_pixel_values_as_llll(t_score *x, t_scorevoice *voice);

void score_paint_ext(t_score *x, t_object *view, t_jgraphics *g, t_rect rect);
void paint_ruler_and_grid_for_score(t_score *x, t_jgraphics* g, t_rect graphic_rect);

double get_linear_edit_cursor_ux_position(t_score *x);

void paint_static_stuff1(t_score *x, t_object *view, t_rect rect, t_jfont *jf, t_jfont *jf_acc, t_jfont *jf_text_fractions, t_jfont *jf_acc_bogus, t_jfont *jf_ts, t_jfont *jf_tempi,
                         t_jfont *jf_text, char *there_is_legend, char *legend_text);
void paint_static_stuff2(t_score *x, t_object *view, t_rect rect, t_jfont *jf, t_jfont *jf_acc, t_jfont *jf_acc_bogus, t_jfont *jf_text, t_jfont *jf_ts, t_jfont *jf_tempi,
                         char *there_is_legend, char *legend_text);

void create_whole_score_undo_tick_nolock(t_score *x);
void check_if_need_to_splatter_level_when_turning_note_to_rest(t_score *x, t_chord *chord);
void check_if_need_to_flatten_level_when_turning_rest_to_note(t_score *x, t_chord *chord);

void change_marker_attachment(t_score *x, t_marker *mk, char new_attachment, long voicenum);
char move_selected_measure_attached_markers(t_score *x, double delta_ux, char magnetic);
t_measure *create_and_insert_new_measure(t_score *x, t_scorevoice *voice, t_measure *refmeasure, char direction, unsigned long force_ID, t_measure *refmeasure_for_measureinfo, char clone_tempi);
void score_ceilmeasures_ext(t_score *x, t_scorevoice *from, t_scorevoice *to, long *out_num_meas, char also_lock_general_mutex);

//t_scorevoice *voice_get_first_visible(t_score *x);
//t_scorevoice *voice_get_last_visible(t_score *x);



/** Add all measures starting together (in all voices) to the preselection.
    This measure block is identifying by a reference measure belonging to it.
    @ingroup            selection
    @param    r_ob        The notation object
    @param    ref_measure    The reference measure
    @param    except_ref_measure    If non-zero means: don't preselect the reference measure
 */
void preselect_measure_in_all_voices(t_score *x, t_measure *ref_measure, char except_ref_measure);


// beaming trees
void set_measure_beaming_and_ties_plain_trees(t_measure *measure);
t_llll* measure_get_plain_ties_flags_as_llll(t_measure *measure);
t_llll* measure_get_plain_chords_obj_as_llll(t_measure *measure);
void set_measure_plain_rhythmic_tree(t_measure *measure);
void check_for_chords_with_no_rhythmic_tree_leaf(t_notation_obj *r_ob, t_measure *measure);

// read write & import
void set_score_from_llll_from_xml(t_score *x, t_llll* inputlist);
void set_score_from_llll(t_score *x, t_llll* inputlist, char also_lock_general_mutex);
void set_score_from_llll_from_read(t_score *x, t_llll* inputlist);
t_llll* get_score_values_as_llll_for_pwgl(t_score *x);

// bach inspector stuff
void score_bach_attribute_declares(t_score *x);
t_rect bach_measure_miniature_fn(t_score *x, void *elem, long elem_type, char *show_line);
t_rect bach_tempo_miniature_fn(t_score *x, void *elem, long elem_type, char *show_line);

void bach_set_grace(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av);
void sync_quartertempo_fn(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr);
void recompute_all_except_for_beamings_and_autocompletion_fn(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr);
void bach_set_marker_measure_attach(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long ac, t_atom *av);
void bach_get_marker_measure_attach(t_bach_inspector_manager *man, void *obj, t_bach_attribute *attr, long *ac, t_atom **av);
long bach_marker_measure_attach_inactive(t_bach_inspector_manager *man, void *elem, t_bach_attribute *attr);

void sync_all_markers_absolute_ms_onset(t_score *x);
void sync_marker_absolute_ms_onset(t_score *x, t_marker *marker);
void sync_selected_markers_absolute_ms_onset(t_score *x);

double get_first_onset_ms_for_grace_notes(t_score *x);
t_scorevoice *get_longest_scorevoice(t_score *x);
char measure_barlines_coincide_for_all_voices(t_score *x, long up_to_this_measure_num);
t_llll *score_get_interp_at_timepoint(t_score *x, t_timepoint tp);
t_llll *score_get_sampling_timepoint(t_score *x, t_timepoint delta_tp);



void set_loop_region_from_llll(t_score *x, t_llll* loop, char lock_mutex);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif //_SCORE_API_H_
