/*
 *  quantize.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
	@file
	quantize.c
	
	@name
	bach.quantize
	
	@realname
	bach.quantize
 
	@type
	object
	
	@module
	bach
 
	@author
	bachproject
	
	@digest
	Perform quantization tasks
	
	@description
	In its simplest usage, <o>bach.quantize</o> converts a <o>bach.roll</o> into a bach.score, by using specific time signatures
	and tempi, or by handling the information about the position of barlines. In its most extensive usage, it
	performs a general quantization of incoming data.
	
	@discussion
	<o>bach.quantize</o> typically performs the task of converting a <o>bach.roll</o> object into a <o>bach.score</o> object.
	Yet, it can be used for a much wider range of purposes (e.g. for performing a score-to-score quantization).
	Generally speaking, it approximates a list of durations with combinations of a given set of so-called "minimal-units".
	To accomplish this, bach.quantize implements a box-wise algorithm: it performs an initial subdivision of the original
	rhythm into "boxes" where the quantization has to be achieved; then it quantizes each box separately;
	finally the boxes are merged into the requested measures. The criterion to decide the bounty of an approximation
	is simply the euclidean distance of quantized durations with the original durations, but a lot of attributes
	can partially modify this behaviour.
	
	@category
	bach, bach objects, bach notation
 
	@keywords
	quantize, measureinfo, convert, measured, proportional, marker, minimal units, grace notes, box, approximate,
	distance, time signature, tempo, barline
 
	@seealso
	bach.roll, bach.score, bach.beatbox, bach.beatunbox, bach.score2roll, bach.mono, Real Time Stories
	
	@owner
	Daniele Ghisi
 */

#include "notation/notation.h" // header with all the structures for the notation objects
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h>


//#define QUANTIZE_USE_STDEVS

#define QUANTIZE_MARK_TIED_INFOS true

#define QUANTIZE_MERGE_WHEN (k_MERGE_WHEN_DRAWABLE) // < TO DO : WHY??? why is it "merge when drawable"???? We should merge things no matter what, shouldn't we?

#define CONST_MAX_MINIMAL_UNITS 20
#define CONST_TOLERANCE_MC 0.1
#define CONST_THRESHOLD_MS_FOR_TEMPO_MARKERS_BEING_ON_TS_MARKERS 10
#define	CONST_THRESHOLD_FOR_DELETING_BARLINE_OR_DIVISION_MARKERS_AT_SAME_POINT 40
#define CONST_THRESHOLD_MS_FOR_PICKUP_MEASURE 0.2	// it's expressed as a percentage of the division

#define CONST_MAX_MINIMAL_UNITS_AC	((CONST_MAX_MINIMAL_UNITS + 2) * 30) //CONST_MAX_VOICES)

#define CONST_COLLAPSE_SLOT (CONST_MAX_SLOTS - 1) // slot where we store the voice information of collapsed notes

// algorithms
typedef enum _quantize_algorithms {
    k_QUANTIZE_ALGORITHM_GREEDY = 0,
    k_QUANTIZE_ALGORITHM_EXHAUSTIVE,
    k_QUANTIZE_ALGORITHM_EXHAUSTIVE_GREEDY_FIRST
} e_quantize_algorithms;

// mixing modes
typedef enum _mixing_modes {
    k_ALLOW_MIX = 0,		///< Always allow having different minimal units within the same box
    k_DONT_MIX = 1,			///< Always forbid having different minimal units within the same box
    k_SMART_MIX = 2,		///< Allow having different minimal units within the same box but each chord has to have a single minimal unit, and all the tuplets must be completely achieved before changing minimal unit
    ///< For instance, (1/24 1/24 1/24 1/8 1/8) is a perfectly allowed solution for a 1/4-wide-box, but (1/24 1/24 1/8 1/24 1/8) is NOT.
} e_mixing_modes;

// regroup/delete
typedef enum _regroup_delete {
    k_DELETE = 0,
    k_MERGE,
    k_MERGE_WITH_REPETITIONS,
    k_TURN_INTO_GRACE_CHORDS
} e_regroup_delete;

// regroup/delete
typedef enum _merging_policies {
    k_MERGE_TO_NEXT = 0,
    k_MERGE_TO_PREV = 1,
    k_MERGE_TO_SMALLEST = 2,
    k_MERGE_TO_BIGGEST = 3,
    k_MERGE_TO_BOTH = 4
} e_merging_policies;

// regroup/delete
typedef enum _quantization_priorities {
    k_LINEAR = 0, // no priority: notes are analized linearly with time
    k_BACKWARDS = 1, // notes are analized from last to first
    k_NOTES_FIRST_DECREASING = 2,
    k_NOTES_FIRST_INCREASING = 3,
    k_RESTS_FIRST_DECREASING = 4,
    k_RESTS_FIRST_INCREASING = 5
} e_quantization_priorities;

// discard grace
typedef enum _discard_grace_chords {
    k_DISCARD_GRACE_NEVER = 0,
    k_DISCARD_GRACE_WHEN_TIED_TO_NEXT = 1,
    k_DISCARD_GRACE_WHEN_TIED_TO_PREV = 2,
    k_DISCARD_GRACE_WHEN_TIED_TO_NEXT_AND_PREV = 3,
    k_DISCARD_GRACE_WHEN_TIED_TO_NEXT_OR_PREV = 4,
    k_DISCARD_GRACE_WHEN_EACH_NOTE_HAS_A_TIE = 5
} e_discard_grace_chords;


// tempi handling from markers
typedef enum _tempi_handling_from_markers {
    k_TEMPI_IGNORE = 0,
    k_TEMPI_FROM_TEMPO_MARKERS = 1,
    k_TEMPI_FROM_MEASURE_BARLINES = 2,
    k_TEMPI_FROM_MEASURE_DIVISIONS = 3
} e_tempi_handling_from_markers;



typedef struct _quantize
{
    struct llllobj_object 	n_ob;
    
    long				n_mode;
    //	long				n_rebuild;
    long				n_proxies;
    
    void				*n_proxy[7];
    t_llll              *noteIDs;
    long				n_in;
    
    // parameters
    t_llll  			*user_defined_boxes; // if the user wants to insert the boxes manually
    t_llll				*minimal_units;
    long				num_minimal_units;
    char				use_dynamic_minimal_units; // use dynamic minimal units?
    t_llll				*dynamic_minimal_units;
    //	t_atom				minimal_units_as_atomlist[CONST_MAX_MINIMAL_UNITS_AC];
    //	long				this_minimal_units_as_atomlist_size;
    
    char				algorithm;
    char				mixing_mode;
    char				regroup_delete;
    char				quantize_collapsed_voices; //< Maintain synchronicities by quantizing a single voice containing all the information?
    long				approx_width; // how many posible approximations do we search for each note near the "best" one? (actually, this is 2*approx_width;
    long				max_iterations_number; // maximum number of iteration for the tree search
    double				dur_delete_percentage; // from 0. to 100., it is the % of the smaller minimal unit which allows a chord to be "saved".
    double				box_tie_percentage; // from 0. to 100., it is the % of the smaller minimal unit which allows a note to be "saved" if tied at the beginning or at the end of a box.
    char				verbose;
    char				merging_policy; // see e_merging_policies
    char				mode; // 0 = classic, 1 = streaming
    char				quantization_priority; // see e_quantization_priorities
    
    char				discard_graces;
    char				discard_grace_rests;
    char				always_try_to_quantize_boxes_with_no_grace_notes;
    double				grace_dur_delete_percentage; // percentage of the smalle rminimal unit under which grace notes will be in ANY CASE deleted. To make sense, this should be strictly < dur_delete_percentage
    
    char				autoclear;
    char				ceilmeasures;
    char				separate_mode;	// _input_ and _output_ separate syntax from all outlets, or just gathered syntax from the first one?
    
    // internal
    long				current_voice_being_quantized;
    
    // for allowing/forbidding box durations
    t_llll				*allow_box_durs;
    t_llll				*deny_box_durs;
    
    // for realtime quantization
    char				realtime_mode; // 0 = standard offline quantization, 1 = realtime quantization
    long				rt_last_length; // realtime: known length of incoming data
    long				rt_achieved_length; // realtime: length of incoming data which has already correctly be boxed (and "not to be touched").
    
    // markers, for automatic quantization
    t_llll				*marker_info;
    t_llll				*header_info;
    char                            allow_multiple_measures_inside_barline_markers;
    e_tempi_handling_from_markers   tempi_handling;
    double              pickup_added_time;
    long                tempo_approx_digits;
    char                tempo_approx_mode;
    char                incoherent_subdiv_mode;
    
    // slot type information
    long                slot_types[CONST_MAX_SLOTS];
    char                slot_copy_when_split[CONST_MAX_SLOTS];
    
    // for proper articulations handling
    t_articulations_typo_preferences    articulations_typo_preferences;
    
    t_systhread_mutex	n_mutex;
    
} t_quantize;

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_quantize, minimal_units, quantize_getattr_minimal_units)

void quantize_assist(t_quantize *x, void *b, long m, long a, char *s);
void quantize_inletinfo(t_quantize *x, void *b, long a, char *t);

t_quantize *quantize_new(t_symbol *s, short ac, t_atom *av);
void quantize_free(t_quantize *x);

void quantize_bang(t_quantize *x);
void quantize_anything(t_quantize *x, t_symbol *msg, long ac, t_atom *av);
void quantize_int(t_quantize *x, t_atom_long num);
void quantize_float(t_quantize *x, double num);
void quantize_dynamicminimalunits(t_quantize *x, t_symbol *msg, long ac, t_atom *av);

void quantize_allow(t_quantize *x, t_symbol *msg, long ac, t_atom *av);
void quantize_deny(t_quantize *x, t_symbol *msg, long ac, t_atom *av);

// comparison methods
long compare_by_first(void *data, t_llllelem *a, t_llllelem *b);
long compare_llllelem_for_approximation(void *data, t_llllelem *a, t_llllelem *b);
sort_fn choose_appropriate_sorting_function(t_quantize *x);

t_llll *get_approx_for_elem(t_quantize *x, t_llllelem *elem, t_llll *minimal_units);
t_llll *approx_elem_to_coefficients(t_llllelem *approx_elem);
t_rational approx_elem_to_error(t_llllelem *approx_elem);
t_rational approx_elem_to_approx(t_llllelem *approx_elem);
char is_there_an_approx_with_given_error(t_llll *approx_possib_for_duration, t_rational given_error);
char increment_elem_multiindex(t_llllelem **elem_multiindex, t_llll *approx_possib, long *start_from_index, char direction);
char increment_multiindex(long *multiindex, long num_entries, long *max_value, long *start_from_index, char direction);
void merge_small_notes_inplace(t_quantize *x, t_llll **rhythm, t_llll **infos, t_llll **ties,
                               t_llllelem *prev_elem_rhythm, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties,
                               t_llllelem *next_elem_rhythm, t_llllelem *next_elem_infos, t_llllelem *next_elem_ties,
                               t_llll *minimal_units);
void destroy_rhythm_element_or_turn_it_into_grace(t_quantize *x, t_llllelem *rhythm_elem_to_delete, t_llllelem *infos_elem_to_delete, t_llllelem *ties_elem_to_delete,
                                                  t_llllelem *prev_elem_rhythm, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties,
                                                  t_llllelem *next_elem_rhythm, t_llllelem *next_elem_infos, t_llllelem *next_elem_ties,
                                                  char allow_merging, char only_if_grace_note_and_according_to_grace_note_conditions, t_rational smallest_minimal_unit);
void regroup_delete_fastest_element(t_quantize *x, t_llll *rhythm, t_llll *infos, t_llll *ties,
                                    t_llllelem *prevbox_last_rhythm_elem, t_llllelem *prevbox_last_infos_elem, t_llllelem *prevbox_last_ties_elem,
                                    t_llllelem *nextbox_first_rhythm_elem, t_llllelem *nextbox_first_infos_elem, t_llllelem *nextbox_first_ties_elem, t_rational smallest_minimal_unit);
void merge_infos(t_llll *where, t_llll *what, char where_is_a_pause, t_llll *which_indices);

t_llllelem *info_to_midicents(t_llllelem *info_elem);
long info_to_num_notes(t_llllelem *info_elem);

char is_chord_as_llllelem_all_tied_from(t_llllelem *rhythm, t_llllelem *infos, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties);
char is_chord_as_llllelem_all_tied_to(t_llllelem *rhythm, t_llllelem *infos, t_llllelem *ties, t_llllelem *next_elem_infos);
char in_chord_as_llllelem_all_notes_has_tie(t_llllelem *rhythm, t_llllelem *infos, t_llllelem *ties, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties, t_llllelem *next_elem_infos);


// sorting priorities utilities
long llll_order_rationals_notes_first_decreasing_fn(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_order_rationals_notes_first_increasing_fn(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_order_rationals_rests_first_decreasing_fn(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_order_rationals_rests_first_increasing_fn(void *dummy, t_llllelem *a, t_llllelem *b);
long llll_order_linear_fn(void *dummy, t_llllelem *a, t_llllelem *b);

char quantize_box_single_step(t_quantize *x, t_llll *box_durations, t_llll **quantized_box_durations, t_llll *minimal_units);
void quantize_box(t_quantize *x, t_rational box_width, t_llll *box_durations, t_llll *box_infos, t_llll *box_ties,
                  t_llll **quantized_box_durations, t_llll **quantized_box_infos, t_llll **quantized_box_ties,
                  t_llllelem *prev_elem_rhythm, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties,
                  t_llllelem *next_elem_rhythm, t_llllelem *next_elem_infos, t_llllelem *next_elem_ties);

// collapsing
void quantize_collapse(t_llll **measureinfo, t_llll **cents, t_llll **durations, t_llll **velocities, t_llll **ties, t_llll **graphic, t_llll **breakpoints,
                       t_llll **slots, t_llll **regularityboxes, t_llll **noteIDs, long collapse_voice_slot_num, long num_voices,
                       char *need_free_graphic, char *need_free_breakpoints, char *need_free_slots);
t_llll *quantize_uncollapse(t_llll *measureinfo, t_llll *boxed_cents, t_llll *boxed_durations, t_llll *boxed_velocities, t_llll *boxed_ties,
                            t_llll *boxed_extras, long num_voices, long collapse_voice_slot_num);

// setters
t_max_err quantize_setattr_smalleventshandling(t_quantize *x, t_object *attr, long ac, t_atom *av);
t_max_err quantize_setattr_minimal_units(t_quantize *x, t_object *attr, long ac, t_atom *av);


t_class *quantize_class;

t_max_err quantize_setattr_smalleventshandling(t_quantize *x, t_object *attr, long ac, t_atom *av){
    
    if (ac && av) {
        x->regroup_delete = atom_getlong(av);
        object_attr_setdisabled((t_object *)x, _llllobj_sym_discardgrace, x->regroup_delete != k_TURN_INTO_GRACE_CHORDS);
        object_attr_setdisabled((t_object *)x, _llllobj_sym_discardgracerests, x->regroup_delete != k_TURN_INTO_GRACE_CHORDS);
        object_attr_setdisabled((t_object *)x, _llllobj_sym_trytoavoidgrace, x->regroup_delete != k_TURN_INTO_GRACE_CHORDS);
        object_attr_setdisabled((t_object *)x, _llllobj_sym_gracedeletethresh, x->regroup_delete != k_TURN_INTO_GRACE_CHORDS);
    }
    return MAX_ERR_NONE;
}

t_max_err quantize_setattr_separate(t_quantize *x, t_object *attr, long ac, t_atom *av){
    if (ac && av) {
        x->separate_mode = atom_getlong(av) ? 1 : 0;
        x->n_ob.l_rebuild = true;
    }
    return MAX_ERR_NONE;
}



t_max_err quantize_setattr_minimal_units(t_quantize *x, t_object *attr, long ac, t_atom *av){
    
    if (ac && av) {
        t_llllelem *elem, *nextelem;
        
        if (x->minimal_units)
            llll_free(x->minimal_units);
        
        x->minimal_units = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_CLONE);
        
        // to do: filter longs and rats only and avoid repetitions, take absolute values
        elem = x->minimal_units->l_head;
        while (elem){
            nextelem = elem->l_next;
            if (hatom_gettype(&elem->l_hatom) == H_DOUBLE || hatom_gettype(&elem->l_hatom) == H_OBJ)
                llll_destroyelem(elem);
            else if (hatom_gettype(&elem->l_hatom) == H_SYM) {
                t_symbol *sym = hatom_getsym(&elem->l_hatom);
                if (sym != _llllobj_sym_dynamic && sym != _llllobj_sym_dyn)
                    llll_destroyelem(elem);
                else
                    hatom_setsym(&elem->l_hatom, _llllobj_sym_dynamic);
            } else if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                long val = hatom_getlong(&elem->l_hatom);
                if (val == 0)
                    llll_destroyelem(elem);
                else if (val < 0)
                    hatom_setlong(&elem->l_hatom, -val);
            } else if (hatom_gettype(&elem->l_hatom) == H_RAT) {
                t_rational val = hatom_getrational(&elem->l_hatom);
                if (val.r_num == 0 || val.r_den == 0)
                    llll_destroyelem(elem);
                else if (val.r_num < 0)
                    hatom_setrational(&elem->l_hatom, rat_opp(val));
            } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                t_llll *sub_llll = hatom_getllll(&elem->l_hatom);
                t_llllelem *subelem = sub_llll ? sub_llll->l_head : NULL;
                t_llllelem *subnextelem;
                while (subelem) {
                    subnextelem = subelem->l_next;
                    if (hatom_gettype(&subelem->l_hatom) == H_LONG) {
                        long val = hatom_getlong(&subelem->l_hatom);
                        if (val == 0)
                            llll_destroyelem(subelem);
                        else if (val < 0)
                            hatom_setlong(&subelem->l_hatom, -val);
                    } else if (hatom_gettype(&subelem->l_hatom) == H_RAT) {
                        t_rational val = hatom_getrational(&subelem->l_hatom);
                        if (val.r_num == 0 || val.r_den == 0)
                            llll_destroyelem(elem);
                        else if (val.r_num < 0)
                            hatom_setrational(&subelem->l_hatom, rat_opp(val));
                    } else {
                        llll_destroyelem(subelem);
                    }
                    subelem = subnextelem;
                }
            }
            elem = nextelem;
        }
        
        if (!x->minimal_units || x->minimal_units->l_size == 0) {
            if (x->minimal_units) llll_free(x->minimal_units);
            x->minimal_units = llll_get();
            llll_appendrat(x->minimal_units, RAT_1OVER16);
            x->num_minimal_units = 1;
        }
        
        if (hatom_gettype(&x->minimal_units->l_head->l_hatom) == H_SYM && hatom_getsym(&x->minimal_units->l_head->l_hatom) == _llllobj_sym_dynamic)
            x->use_dynamic_minimal_units = 1;
        else
            x->use_dynamic_minimal_units = 0;
        
        /*		if (!x->use_dynamic_minimal_units) {
         t_atom *new_av = NULL;
         long new_ac = 0, i;
         
         if (x->minimal_units)
         new_ac = llll_deparse(x->minimal_units, &new_av, 0, 0);
         
         for (i = 0; i < new_ac && i < CONST_MAX_MINIMAL_UNITS_AC; i++){
         if (atom_gettype(new_av+i) == A_SYM)
         atom_setsym(x->minimal_units_as_atomlist + i, atom_getsym(new_av+i));
         else if (atom_gettype(new_av+i) == A_LONG)
         atom_setlong(x->minimal_units_as_atomlist + i, atom_getlong(new_av+i));
         else
         atom_setsym(x->minimal_units_as_atomlist + i, _llllobj_sym_empty_symbol);
         }
         x->this_minimal_units_as_atomlist_size = new_ac;
         if (new_av)
         bach_freeptr(new_av);
         } else {
         atom_setsym(x->minimal_units_as_atomlist, _llllobj_sym_dynamic);
         x->this_minimal_units_as_atomlist_size = 1;
         } */
    }
    return MAX_ERR_NONE;
}

// OLD, DEPRECATED!!!!!
void quantize_dynamicminimalunits(t_quantize *x, t_symbol *msg, long ac, t_atom *av)
{
    if (ac && av) {
        if (x->dynamic_minimal_units)
            llll_free(x->dynamic_minimal_units);
        x->dynamic_minimal_units = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, ac, av, LLLL_PARSE_CLONE);
    }
}


void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }
    
    CLASS_NEW_CHECK_SIZE(c, "bach.quantize", (method)quantize_new, (method)quantize_free, (long) sizeof(t_quantize), 0L, A_GIMME, 0);
    
    // @method llll @digest Function depends on inlet
    // @description
    // In first inlet: Sets the measureinfo and performs the quantization (outputting the result). <br />
    // In second inlet: Receives the result of bach.roll's "quantize" message (from bach.roll's or bach.score's first outlet). In "separate" mode: Sets the Cents to be quantized. <br />
    // In third inlet: Sets the regularity boxes for the quantization. In "separate" mode: Sets the absolute Durations (in milliseconds) to be quantized. <br />
    // In fourth inlet ("separate" mode only): Sets the Velocities to be quantized. <br />
    // In fifth inlet ("separate" mode only): Sets the Ties to be quantized. <br />
    // In sixth inlet ("separate" mode only): Sets the Extras to be quantized. <br />
    // In seventh inlet ("separate" mode only): Sets the regularity boxes for the quantization. <br /> <br />
    // All parameters must be given voice-wise: a list for each voice, then an element or list for each chord. (Durations are expected to have just a single element for each chord,
    // and you should use the ties to have polyphonies. All the other separate parameters can be chord-wise, i.e. the parameter is assigned to the whole chord, or note-wise, thus each
    // chord is a list of elements, one for each note).  <br /> <br />
    // @copy BACH_DOC_MEASUREINFO_SYNTAX
    // @copy BACH_DOC_REGULARITYBOXES
    class_addmethod(c, (method)quantize_anything,					"anything",				A_GIMME,	0);
    class_addmethod(c, (method)quantize_anything,					"list",					A_GIMME,	0);
    class_addmethod(c, (method)quantize_int,						"int",					A_LONG,		0);
    class_addmethod(c, (method)quantize_float,						"float",				A_FLOAT,	0);
    
    // @method auto @digest Quantize data based on markers
    // @description The word <m>auto</m> can substitute the measureinfo specification, when the quantized bach.roll
    // contains markers carrying information about tempi, time signatures, barlines, divisions (i.e. markers having a
    // role). In this case, those markers are parsed to identify automatically the proper measureinfo for quantization. <br />
    // @copy BACH_DOC_MARKERROLES
    class_addmethod(c, (method)quantize_anything,					"auto",				A_GIMME,	0);
    
    class_addmethod(c, (method)quantize_dynamicminimalunits,		"dynamicminimalunits",	A_GIMME,	0); // obsolete, just kept for bw compatibility. Use "dynamic" as first elements of the minimal units instead!!!
    
    // @method bang @digest Perform the last boxing operation.
    // @description Perform the boxing operation on the most recently received input data.
    class_addmethod(c, (method)quantize_bang,						"bang",		0);
    
    // @method allow @digest Only allow some rhythmic configurations
    // @description	Via an <m>allow</m> message one can allow the output of each box to be only in one of a given list of rhythmic configurations (thus forbidding any other option).
    // For instance "allow (1/16 1/16 1/16 1/16) (1/16 1/16 1/8) (1/8 1/8) (1/4)" only allows each box to have one of the four given possibilities (one for each sublist).
    // Just use "allow" with no further arguments in order to allow any option (default).
    // If an <m>allow</m> list has one more level of parenthesis, such as "allow ((1/16 1/16 1/16 1/16) (1/16 1/16 1/8) (1/8 1/8) (1/4)) ((1/12 1/12 1/12) (1/6 1/12) (1/12 1/6) (1/4))"
    // bach considers that different <m>allow</m> specification will apply to the different voices (possibly looping the last one, if needed).
    // @marg 0 @name allowed_configurations @optional 1 @type llll
    // @example allow [1/16 1/16 1/8] [1/8 1/16 1/16] [1/4] @caption only allow some patterns
    // @example allow [[1/16 1/16 1/8] [1/8 1/16 1/16] [1/4]] [[1/16 1/8 1/16] [1/8 1/8]] @caption allow differen patterns for different voices
    class_addmethod(c, (method)quantize_allow,	"allow",	A_GIMME,	0);
    
    // @method forbid @digest Forbid some rhythmic configurations
    // @description	Via a <m>forbid</m> message one can force a box NOT to have some rhythmic configurations.
    // For instance <b>forbid [1/16 1/8 1/16] [1/16 1/16 1/8]</b> denies the two given possibilities (one for each sublist).
    // Just use <b>forbid</b> with no further arguments in order to revert to the default behaviour of no configurations denied.
    // If an <m>forbid</m> list has one more level of parenthesis, such as <b>forbid [[1/16 1/8 1/16]] [[1/16 3/16]]</b>
    // bach considers that different <m>forbid</m> specification will apply to the different voices (possibly looping the last one, if needed).
    // @marg 0 @name forbidden_configurations @optional 1 @type llll
    // @example forbid [1/16 1/16 1/8] [1/8 1/16 1/16] [1/4] @caption forbid some patterns
    // @example forbid [[1/16 1/16 1/8] [1/8 1/16 1/16] [1/4]] [[1/16 1/8 1/16] [1/8 1/8]] @caption forbid differen patterns for different voices
    class_addmethod(c, (method)quantize_deny,	"forbid",		A_GIMME,	0);
    class_addmethod(c, (method)quantize_deny,	"deny",		A_GIMME,	0);
    
    class_addmethod(c, (method)quantize_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)quantize_inletinfo,	"inletinfo",	A_CANT,		0);
    
    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
    
    
    CLASS_STICKY_ATTR(c,"category",0,"Settings");
    
    CLASS_ATTR_CHAR(c, "autoclear", 0, t_quantize, autoclear);
    CLASS_ATTR_STYLE_LABEL(c,"autoclear",0,"onoff","Autoclear");
    CLASS_ATTR_BASIC(c,"autoclear",0);
    // @description Automatically clear the score before outputting the new data.
    
    CLASS_ATTR_CHAR(c, "autoceil", 0, t_quantize, ceilmeasures);
    CLASS_ATTR_STYLE_LABEL(c,"autoceil",0,"onoff","Force All Voices To End Together");
    CLASS_ATTR_BASIC(c,"autoceil",0);
    // @description Force all voices to have the same number of measures (in case voices have different durations).
    
    CLASS_ATTR_CHAR(c, "algorithm", 0, t_quantize, algorithm);
    CLASS_ATTR_STYLE_LABEL(c,"algorithm",0,"enumindex","Algorithm");
    CLASS_ATTR_ENUMINDEX(c,"algorithm", 0, "Greedy Exhaustive Exhaustive Greedy First");
    CLASS_ATTR_BASIC(c,"algorithm",0);
    // @description Choose the algorithm which will be used. The "Exhaustive" algorithm guarantees that the output solution will be the "best" possible solution,
    // but it will in general require a lot of time to be computed ("full tree search"). A "Greedy" algorithm (default) will find a reasonably good solution in a more
    // reasonable time. An "Exhaustive Greedy First" algorithm will perform full search, but giving priority to the Greedy possibilities (so that if a "best match" is
    // found, the search is immediately stopped, the "best match" being when each chord is individually approximated with the best possible approximation among the
    // possible choices depending on the <m>minimalunits</m>).
    
    CLASS_ATTR_CHAR(c, "sync", 0, t_quantize, quantize_collapsed_voices);
    CLASS_ATTR_STYLE_LABEL(c,"sync",0,"onoff","Preserve Synchronicities");
    CLASS_ATTR_BASIC(c,"sync",0);
    // @description Force all voices to maintain the synchronicities they had before the quantization.
    
    
    //		CLASS_ATTR_CHAR(c, "realtime", 0, t_quantize, realtime_mode);
    //		CLASS_ATTR_STYLE_LABEL(c,"realtime",0,"onoff","Realtime Mode");
    //		CLASS_ATTR_SAVE(c,"realtime",0);
    
    CLASS_ATTR_LLLL(c, "minimalunits", 0, t_quantize, minimal_units, quantize_getattr_minimal_units, quantize_setattr_minimal_units);
    CLASS_ATTR_STYLE_LABEL(c,"minimalunits",0,"text","Minimal Units");
    CLASS_ATTR_BASIC(c,"minimalunits",0);
    // @description Minimal units are the standard bricks with which the quantized rhythm of each box will be formed. More specifically, the final rhythm will be allowed to have as
    // durations only linear combinations of the given minimal units. For instance, if minimal units are [1/8 1/12],
    // the resulting rhythm will have as durations only multiple of the eighth note, multiples of the eighth-triplet note, and (but only if <m>mixingmode</m> is allowed)
    // combinations of the two, such as 5/24 (by default weird combination possibilities are not allowed, keeping the rhythm more natural and straightforward to read,
    // see <m>mixingmode</m> for more information).
    // Minimal units can also be defined depending on the "amount of events" happening in a box. The idea behind this is: if we have very few events, we might want to use looser
    // approximations and thus relatively "big" minimal units (such as 1/8 or 1/12) whereas if we have a lot of quick notes, we might want to increase (locally!) the finesse of
    // the quantization, by choosing smaller minimal units (such as 1/32 or 1/24). This is achieved by putting "dynamic" as a first symbol in the minimal unit list.
    // For instance: [dynamic ( 1/8 1/12 ) 10 ( 1/32 1/24 )] does what we wanted, and "10" is a threshold between the two regions (the one with "big" minimal units and the one
    // with "small" minimal units), measured in event density. The event density is simply the number of events per whole note (1/1), so for instance in a measure with a long
    // sequence of sixteenth notes, the density will be 16/1 = 1 (since there are 16 notes in a 1/1). Putting 10 as threshold means: in boxes where there are less than 10 notes
    // per 1/1, use (1/8 1/12); otherwise use (1/32 1/24). The threshold must be an integer number.
    // More than one threshold is also possible: for instance [dynamic ( 1/16 1/12 ) 10 ( 1/16 1/24 ) 15 ( 1/32 1/24 )] are the default minimal units when bach.quantize is created.
    // Minimal units can also be a list of lists, such as [(1/8 1/12) (1/64 1/40)] in this case: each list applies to the corresponding voice (and the last one is looped, if needed).
    
    
    // TO ADD: USER DEFINED BOXES???
    
    CLASS_ATTR_CHAR(c,"mixingmode",0, t_quantize, mixing_mode);
    CLASS_ATTR_STYLE_LABEL(c,"mixingmode",0,"enumindex","Minimal Units Mixing In A Box");
    CLASS_ATTR_ENUMINDEX(c,"mixingmode", 0, "Allow Forbid Smart Mix");
    CLASS_ATTR_FILTER_CLIP(c, "mixingmode", 0, 2);
    CLASS_ATTR_BASIC(c,"mixingmode",0);
    // @description The <m>mixingmode</m> attribute deals with the fact that inside a box one might want just multiples of a single minimal unit.
    // This is typically the most common case (and the fastest case as well!), which assure not to have tuplet-numbers greater than the one related
    // to the minimal units: if one chooses 1/12 and 1/10 as minimal units, one will just have triplets or or 5-plets, but no 15-plet (for instance).
    // If one wants this behavior, one should choose "Forbid" (default).
    // If one chooses "Allow", mixed combination of units will be possible inside a box: this will make the algorithm slower and might produce cases where,
    // by having 1/12's and 1/10's together in the same box, a 15-plet is produced.
    // The "Smart Mix" possibility is somewhere in the middle: it hallows having different minimal units within the same, box but each chord has to have a
    // single minimal unit, and all the tuplets must be completely achieved before changing minimal unit
    // For instance, (1/24 1/24 1/24 1/8 1/8) is a perfectly allowed solution for smart mixing in a 1/4-wide-box, but (1/24 1/24 1/8 1/24 1/8) is NOT.
    
    CLASS_ATTR_CHAR(c,"mergingpolicy",0, t_quantize, merging_policy);
    CLASS_ATTR_STYLE_LABEL(c,"mergingpolicy",0,"enumindex","Small Events Merging Policy");
    CLASS_ATTR_ENUMINDEX(c,"mergingpolicy", 0, "Merge To Next Merge To Previous Merge To Smallest Merge To Biggest Merge To Both");
    CLASS_ATTR_FILTER_CLIP(c, "mergingpolicy", 0, 4);
    // @description If the <m>smalleventshandling</m> requires some merging, this attributes tells how the content should be merged: <br />
    // <m>Merge To Next</m>: merges the chord to be deleted to the next chord (if any) <br />
    // <m>Merge To Previous</m>: merges the chord to be deleted to the previous chord (if any) <br />
    // <m>Merge To Smallest</m> (default): merges the chord to be deleted to the smallest between the previous and the next chord <br />
    // <m>Merge To Biggest</m>: merges the chord to be deleted to the biggest between the previous and the next chord <br />
    // <m>Merge To Both</m>: split the chord to be deleted between the previous chord and the next chord <br />
    
    CLASS_ATTR_CHAR(c,"smalleventshandling",0, t_quantize, regroup_delete);
    CLASS_ATTR_STYLE_LABEL(c,"smalleventshandling",0,"enumindex","Small Notes Policy");
    CLASS_ATTR_ENUMINDEX(c,"smalleventshandling", 0, "Delete Merge Merge With Repetitions Make Grace Chords");
    CLASS_ATTR_FILTER_CLIP(c, "smalleventshandling", 0, 3);
    CLASS_ATTR_ACCESSORS(c, "smalleventshandling", (method)NULL, (method)quantize_setattr_smalleventshandling);
    CLASS_ATTR_BASIC(c,"smalleventshandling",0);
    // @description Sometimes a quantization might require to drop some of the input events (either because they are too many with respect to the
    // grid given by the minimal units, or - but only if <m>trytoavoidgrace</m> is not set, because the approximation will gain in precision). In this
    // case there are a certain number of possibilities of dealing with the "small events" to discard. The "Small Notes Policy" deals exactly with this: <br />
    // <m>Delete</m>: small events are simply deleted <br />
    // <m>Merge</m>: small events are merged (see the attribute <m>mergingpolicy</m> to define how this is performed) <br />
    // <m>Merge With Repetitions</m>: as the previous one, but notes are present with their multiplicity: if two chords are merged having the same note, this note will appear as doubled <br />
    // <m>Make Grace Chords</m> (default): small events are turned into grace chords.
    
    CLASS_ATTR_CHAR(c,"quantizationpriority",0, t_quantize, quantization_priority);
    CLASS_ATTR_STYLE_LABEL(c,"quantizationpriority",0,"enumindex","Quantization Priority");
    CLASS_ATTR_ENUMINDEX(c,"quantizationpriority", 0, "Linear Backwards Notes First Decreasing Notes First Increasing Rests First Decreasing Rests First Increasing");
    CLASS_ATTR_FILTER_CLIP(c, "quantizationpriority", 0, 4);
    // @description Quantization is by default performed linearly, which means that quantization errors are tried to be fixed chord by chord,
    // from the first chord to the last. One might want to change this priority, and decide to quantize the chords in a different order.
    // This parameter is irrelevant if the <m>algorithm</m> is the exhaustive search. <br />
    // <m>Linear</m> (default): quantization is performed linearly on the introduced events <br />
    // <m>Backwards</m>: quantization is performed in reversed order with respect to the introduced events <br />
    // <m>Notes First Decreasing</m>: quantization is performed first on non-rest chords, in decreasing order of duration (biggest to smallest), then on rests <br />
    // <m>Notes First Increasing</m>: quantization is performed first on non-rest chords, in increasing order of duration (smallest to biggest), then on rests <br />
    // <m>Rests First Decreasing</m>: quantization is performed first on rests, in decreasing order of duration (biggest to smallest), then on non-rest chords <br />
    // <m>Rests First Increasing</m>: quantization is performed first on rests, in increasing order of duration (smallest to biggest), then on non-rest chords <br />
    
    CLASS_ATTR_LONG(c, "approxwidth", 0, t_quantize, approx_width);
    CLASS_ATTR_STYLE_LABEL(c,"approxwidth",0,"text","Width Of The Approximation Search");
    // @description bach.quantize builds a tree of possible approximations for each duration. Take a note of a given duration, for each minimal unit,
    // there will always be a "best approximation" for the note, which not necessarily will fit in the "best rhythm approximation".
    // In other words, for every note r and for each minimal unit u, there will always be a k such that k*u is "as near as possible" to r.
    // The width of the approximation search is the number of approximations that we want to consider at "every side" of k. For instance, if k = 3, we will try to approximate
    // r with k*u, but also with (k+1)*u, (k+2)*u, (k+3)*u, (k-1)*u, (k-2)*u, (k-3)*u.
    // The higher the <m>approxwidth</m> is, the higher will be the number of possible approximations and solutions - the slower the algorithm will be.
    // The default width of the approximation is is 2.
    
    CLASS_ATTR_LONG(c, "maxiterations", 0, t_quantize, max_iterations_number);
    CLASS_ATTR_STYLE_LABEL(c,"maxiterations",0,"text","Max Iterations For Single Box");
    // @description Upper bound on the number of possible iterations for each box. After this number is reached, the best found solution is output
    // (or no solution is output if no solution has been found). Leave 0 to search inside the whole tree (default).
    
    CLASS_ATTR_DOUBLE(c, "durthresh", 0, t_quantize, dur_delete_percentage);
    CLASS_ATTR_STYLE_LABEL(c,"durthresh",0,"text","Small Notes Duration Threshold");
    CLASS_ATTR_FILTER_CLIP(c, "durthresh", 0, 100);
    CLASS_ATTR_ALIAS(c, "durthresh", "durthreshold");
    CLASS_ATTR_BASIC(c,"durthresh",0);
    // @description Threshold to determine which chords are "so small" that we have to discard them (what will happen to them depends on the <m>smalleventshandling</m> attribute).
    // This threshold is given as a percentage of the smallest minimal unit (by default, this is 5%).
    
    CLASS_ATTR_DOUBLE(c, "boxedgetiedurthresh", 0, t_quantize, box_tie_percentage);
    CLASS_ATTR_STYLE_LABEL(c,"boxedgetiedurthresh",0,"text","Box Edge Tied Notes Threshold");
    CLASS_ATTR_FILTER_CLIP(c, "boxedgetiedurthresh", 0, 100);
    CLASS_ATTR_ALIAS(c, "boxedgetiedurthresh", "boxedgetiedurthreshold");
    // @description This threshold is the same as <m>durthresh</m>, but this one applies only for notes at the beginning or at the end of a quantization box, which are
    // rests or which are completely tied to (respectively) the previous or the following one. This threshold is also given as a percentage of the smallest minimal unit
    // (by default, this is 20%). Typically this should be greater than the <m>durthresh</m>.
    
    CLASS_ATTR_CHAR(c, "verbose", 0, t_quantize, verbose);
    CLASS_ATTR_STYLE_LABEL(c,"verbose",0,"text","Verbose Output");
    // @description Amount of "verbosity" of bach.quantize: bach.quantize can post in the Max window the steps of its algorithm (this could be needed, for instance, for debug).
    // By default this verbosity is 0 (no output), but it can get to 3 (most talkative: it almost mirrors the entire process in the Max window).
    // Choose any number in between to have the corresponding amount of verbosity
    
    CLASS_ATTR_LONG(c, "tempodigits", 0, t_quantize, tempo_approx_digits);
    CLASS_ATTR_STYLE_LABEL(c,"tempodigits",0,"text","Number Of Digits For Tempo Approximation");
    CLASS_ATTR_FILTER_CLIP(c, "tempodigits", 0, BACH_MAX_TEMPO_DIGITS);
    // @description Sets the number of digits for tempo approximation. Defaults to 2 for 64-bit mode, to 1 for 32-bit mode.
    
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    CLASS_STICKY_ATTR(c,"category",0,"Quantization From Markers");
    
    CLASS_ATTR_CHAR(c, "multimeasure", 0, t_quantize, allow_multiple_measures_inside_barline_markers);
    CLASS_ATTR_STYLE_LABEL(c,"multimeasure",0,"onoff","Allow Multiple Measures Within Barline Markers");
    // @description Allow the creation of more than one measure inside two barline markers, in case they are so far apart that more
    // than one measure will fit, depending on the current tempo.
    
    CLASS_ATTR_CHAR(c, "tempohandling", 0, t_quantize, tempi_handling);
    CLASS_ATTR_STYLE_LABEL(c,"tempohandling",0,"enumindex","Tempi Creation Policy");
    CLASS_ATTR_ENUMINDEX(c,"tempohandling", 0, "Ignore Set From Tempo Markers Set From Barlines Set From Divisions");	// one of the e_tempi_handling
    CLASS_ATTR_BASIC(c,"tempohandling",0);
    // @description Sets the policy for creating tempi in the new score:
    // <m>Ignore</m>: No tempi are created <br />
    // <m>Set From Tempo Markers</m>: Tempi are only created when tempo markers are found. <br />
    // <m>Set From Barlines</m>: Tempi are created for each measure, in sync with the defined barlines. <br />
    // <m>Set From Divisions</m>: Tempi are created for each division, in sync with the defined barlines and division markers.
    
    CLASS_ATTR_CHAR(c, "tempocompensation", 0, t_quantize, tempo_approx_mode);
    CLASS_ATTR_STYLE_LABEL(c,"tempocompensation",0,"enumindex","Compensate For Tempo Sync");
    CLASS_ATTR_ENUMINDEX(c,"tempocompensation", 0, "At Actual Tempo Change At Each Measure At Each Division");
    // @description Determines when tempi should be changed, in order to keep sync with the score. Indeed tempo approximation
    // might cause slight drifts with rispect to the non-quantized score; the drift amount is in general inversely proportional
    // to the <m>tempodigits</m> attribute. The more often the tempo changes, the more often compensations are made, hence
    // the better synchronicity one will achieve. Three values are available: <br />
    // <m>At Tempo Change</m>: Change tempi only when they actually change. <br />
    // <m>At Each Measure</m>: Compensate tempi at each measure beginning, if needed. <br />
    // <m>At Each Division</m>: Compensate tempi at each measure division, if needed. <br />
    
    CLASS_ATTR_CHAR(c, "incoherentsubdivisions", 0, t_quantize, incoherent_subdiv_mode);
    CLASS_ATTR_STYLE_LABEL(c,"incoherentsubdivisions",0,"enumindex","Incoherent Subdivision");
    CLASS_ATTR_ENUMINDEX(c,"incoherentsubdivisions", 0, "Drop Change Time Signature");
    // @description Determines what to do when incoherent subdivision markers are found: <br />
    // <m>Drop</m>: Incoherent subdivision markers are dropped. <br />
    // <m>Change Time Signature</m>: Time signature is modified according to the subdivision marker, to restore coherence. <br />
    
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    CLASS_STICKY_ATTR(c,"category",0,"Grace Chords");
    
    CLASS_ATTR_CHAR(c,"discardgrace",0, t_quantize, discard_graces);
    CLASS_ATTR_STYLE_LABEL(c,"discardgrace",0,"enumindex","Discard Grace Chords When");
    CLASS_ATTR_ENUMINDEX(c,"discardgrace", 0, "Never Tied To Next Chord Tied To Previous Chord Tied To Next And Previous Chord Tied To Next Or Previous Chord Each Note Has Tie");	// one of the e_discard_grace_chords
    CLASS_ATTR_FILTER_CLIP(c, "discardgrace", 0, 5);
    CLASS_ATTR_BASIC(c,"discardgrace",0);
    // @description This attribute tells in which cases grace chords have to be immediately discarded, depending on the ties starting or ending on them.
    // This might be useful, since you might want to prevent grace tied chords from being created. (This is taken into account only if <m>smalleventshandling</m> is set to "Make Grace Chords").
    // <m>Never</m>: never discard any grace chord<br />
    // <m>Tied To Next Chord</m>: discard a grace chord when it is completely tied to the next one<br />
    // <m>Tied To Previous Chord</m>: discard a grace chord when it is completely tied to the previous one<br />
    // <m>Tied To Next And Previous Chord</m>: discard a grace chord when it is completely tied to the previous AND the next one<br />
    // <m>Tied To Next Or Previous Chord</m>: discard a grace chord when it is completely tied to the previous OR the next one<br />
    // <m>Each Note Has Tie</m> (default): discard a grace chord when each note in the chord has a tie (starting or ending)<br />
    
    CLASS_ATTR_CHAR(c,"discardgracerests",0, t_quantize, discard_grace_rests);
    CLASS_ATTR_STYLE_LABEL(c,"discardgracerests",0,"onoff","Always Discard Grace Rests");
    CLASS_ATTR_FILTER_CLIP(c, "discardgracerests", 0, 1);
    CLASS_ATTR_BASIC(c,"discardgracerests",0);
    // @description If this is set, bach.quantize always delete grace rests. (This is taken into account only if <m>smalleventshandling</m> is set to "Make Grace Chords").
    
    CLASS_ATTR_CHAR(c,"trytoavoidgrace",0, t_quantize, always_try_to_quantize_boxes_with_no_grace_notes);
    CLASS_ATTR_STYLE_LABEL(c,"trytoavoidgrace",0,"onoff","Try To Avoid Grace Chords When Possible");
    CLASS_ATTR_FILTER_CLIP(c, "trytoavoidgrace", 0, 1);
    // @description If this is set, bach.quantize always tries to accomplish the quantization in each box with the minimum possible number of grace chords,
    // even if the result will be "less precise" than a solution with more grace chords. (This is taken into account only if <m>smalleventshandling</m> is set to "Make Grace Chords")
    
    CLASS_ATTR_DOUBLE(c,"gracedeletethresh",0, t_quantize, grace_dur_delete_percentage);
    CLASS_ATTR_STYLE_LABEL(c,"gracedeletethresh",0,"text","Grace Chords Deletion Duration Threshold");
    CLASS_ATTR_FILTER_CLIP(c, "gracedeletethresh", 0, 100);
    CLASS_ATTR_ALIAS(c, "gracedeletethresh", "gracedeletethreshold");
    // @description Threshold to determine which grace chords are "so small" that we have to immediately discard them.
    // All grace chords whose duration is less than this percentage of the smallest minimal unit will be in ANY case deleted.
    // The default is 2.5%. (This is taken into account only if <m>smalleventshandling</m> is set to "Make Grace Chords")
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    
    class_register(CLASS_BOX, c);
    quantize_class = c;
    
    dev_post("bach.quantize compiled %s %s", __DATE__, __TIME__);
    
    return;
}

void quantize_bang(t_quantize *x)
{
    if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
        quantize_anything(x, _sym_bang, 0, NULL);
    else {
        
        if (x->pickup_added_time >= 0.) {
            t_llll *pickupll = symbol_and_double_to_llll(gensym("pickup"), x->pickup_added_time);
            llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, x->separate_mode ? 7 : 1, pickupll);
            llll_free(pickupll);
        }
        
        if (x->separate_mode) {
            if (x->autoclear)
                llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_clear, 0, NULL);
            
            if (x->header_info->l_size > 0) {
                t_llll *cloned = llll_clone(x->header_info);
                llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 0, cloned);
                llll_free(cloned);
            }
            
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 6);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 5);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 4);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 3);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 2);
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
            llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 0);
        } else {
            llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
        }
        
        if (x->ceilmeasures)
            llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, gensym("ceilmeasures"), 0, NULL);
    }
}

void quantize_int(t_quantize *x, t_atom_long num){
    t_atom argv[1];
    atom_setlong(argv, num);
    quantize_anything(x, _llllobj_sym_list, 1, argv);
}

void quantize_float(t_quantize *x, double num){
    t_atom argv[1];
    atom_setfloat(argv, num);
    quantize_anything(x, _llllobj_sym_list, 1, argv);
}

t_llll *get_marker_content_from_llllelem(t_llllelem *elem)
{
    if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
        t_llll *mk = hatom_getllll(&elem->l_hatom);
        if (mk && mk->l_size >= 4) {
            if (hatom_gettype(&mk->l_head->l_next->l_next->l_next->l_hatom) == H_LLLL)
                return (hatom_getllll(&mk->l_head->l_next->l_next->l_next->l_hatom));
        }
    }
    return NULL;
}

e_marker_roles get_marker_role_from_llllelem(t_llllelem *elem)
{
    if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
        t_llll *mk = hatom_getllll(&elem->l_hatom);
        if (mk && mk->l_size >= 3) {
            e_marker_roles role = sym_to_marker_role(hatom_getsym(&mk->l_head->l_next->l_next->l_hatom));
            return role;
        }
    }
    return k_MARKER_ROLE_NONE;
}

double get_marker_onset_from_llllelem(t_llllelem *elem)
{
    if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
        t_llll *mk = hatom_getllll(&elem->l_hatom);
        if (mk && mk->l_size >= 1) {
            double onset = hatom_getdouble(&mk->l_head->l_hatom);
            return onset;
        }
    }
    return 0;
}

t_llll *markers_to_tempi(t_quantize *x, t_llll *markers, double from_ms, double to_ms, t_rational sym_dur, t_rational default_tempo_figure)
{
    t_llll *out = llll_get();
    t_llllelem *elem;
    for (elem = markers->l_head; elem; elem = elem->l_next){
        double onset = get_marker_onset_from_llllelem(elem);
        e_marker_roles role = get_marker_role_from_llllelem(elem);
        if (role == k_MARKER_ROLE_TEMPO) {
            t_llll *content = get_marker_content_from_llllelem(elem);
            if (content) {
                double tempo = hatom_getdouble(&content->l_tail->l_hatom);
                t_rational tempo_figure = content->l_size > 1 ? hatom_getrational(&content->l_head->l_hatom) : default_tempo_figure;
                if (onset >= from_ms - CONST_THRESHOLD_MS_FOR_TEMPO_MARKERS_BEING_ON_TS_MARKERS && onset <= from_ms + CONST_THRESHOLD_MS_FOR_TEMPO_MARKERS_BEING_ON_TS_MARKERS) {
                    t_llll *thistempo = llll_get();
                    llll_appendrat(thistempo, tempo_figure);
                    llll_appendlong(thistempo, round(tempo));
                    llll_appendllll(out, thistempo);
                } else if (onset > from_ms + CONST_THRESHOLD_MS_FOR_TEMPO_MARKERS_BEING_ON_TS_MARKERS && onset < to_ms - CONST_THRESHOLD_MS_FOR_TEMPO_MARKERS_BEING_ON_TS_MARKERS) {
                    t_llll *thistempo = llll_get();
                    t_rational changepoint = approx_double_with_rat_fixed_den(rat2double(sym_dur) * (onset - from_ms)/(to_ms - from_ms), 40, 0, NULL);
                    llll_appendrat(thistempo, tempo_figure);
                    llll_appendlong(thistempo, round(tempo));
                    llll_appendrat(thistempo, changepoint);
                    llll_appendllll(out, thistempo);
                } else if (onset >= to_ms - CONST_THRESHOLD_MS_FOR_TEMPO_MARKERS_BEING_ON_TS_MARKERS)
                    break;
            }
        }
    }
    return out;
}


t_llll *get_nilinfo(){
    t_llll *out = llll_get();
    t_llll *extras = llll_get();
    llll_appendllll(out, llll_get());
    llll_appendllll(out, llll_get());
    llll_appendllll(extras, llll_get());
    llll_appendllll(extras, llll_get());
    llll_appendllll(extras, llll_get());
    llll_appendllll(out, extras);
    return out;
}


double approx_tempo(double tempo_value, long num_digits, double error)
{
    int iSigned = tempo_value > 0? 1: -1;
    char direction = 0;
    double pow_l = pow(10.0, (double) num_digits);
    long double temp = (tempo_value*pow_l);
    
    if (error > 0)
        direction = -1;
    else if (error < 0)
        direction = 1;
    else {
        double fmod_res = (double)fmodl(temp, 1.);
        if (fmod_res > 0. && fmod_res <= 0.5)
            direction = -1;
        else if (fmod_res > 0.05 && fmod_res < 1.)
            direction = 1;
    }
    
    unsigned long long uiTemp = temp * iSigned + (direction == 1 ? 1 : 0); //Note I'm using unsigned int so that I can increase the precision of the truncate
    return (double)(((long double)uiTemp)/pow_l * iSigned);
}


// converts a list of markers (with special roles), and a list of durations (in milliseconds)
// into measure boxes and rationaldurations.
// also returns a global delta onset (in milliseconds) which has been applied.
// properly fills the measure_boxes, voice_ts and quant_boxes lllls
char markers_to_measureinfo_and_rat_durations(t_quantize *x, t_llll *markers, t_llll *voice_durations, t_llll *voice_infos,  t_llll *voice_ties, t_llll *measure_boxes, t_llll *voice_ts, t_llll *quant_boxes, double *global_delta_onset, t_llll **unquantized_boxed_voice_durations, t_llll **unquantized_boxed_voice_infos, t_llll **unquantized_boxed_voice_ties)
{
    char allow_more_than_one_measure_within_barline_markers = x->allow_multiple_measures_inside_barline_markers;
    e_tempi_handling_from_markers tempi_handling = x->tempi_handling;
    char tempo_approx_mode = x->tempo_approx_mode;
    char incoherent_subdiv_mode = x->incoherent_subdiv_mode;
    
    t_llllelem *elem, *temp;
    t_rational curr_tempo_figure = RAT_1OVER4;
    char curr_figure_tempo_value_is_dummy = true;
    double curr_figure_tempo_value = 60; // tempo referred to the tempo figure
    t_timesignature curr_ts;
    curr_ts.numerator = 4;
    curr_ts.denominator = 4;
    curr_ts.num_numerator_elements = 1;
    curr_ts.numerator_elements[0] = 4;
    
    char must_specify_tempo = false;
    
    
    // we build a list containing:
    // (t1 t2 sym_dur) (t2 t3 sym_dur) (t3 t4 sym_dur) (t4 t5 sym_dur)...
    // each tempo might be slightly different, since markers may not be precise
    t_llll *turnpike = llll_get(); //DG2020: what the hell is turnpike ? Not clear...
    t_llll *quant_boxes_ms = llll_get();
    t_llll *measure_boxes_ms = llll_get();
    t_llll *quant_boxes_quartertempo = llll_get();
    t_llll *quant_boxes_tempofigures = llll_get();
    t_llll *divisions_absolute_position = llll_get();
    t_llll *num_divisions = llll_get();
    
    double sum_all_durations = llll_sum_abs_of_double_llll(voice_durations);
    
    char first_ts_or_measure_barline = true;
    
    for (elem = markers->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
            t_llll *mk = hatom_getllll(&elem->l_hatom);
            if (mk && mk->l_size >= 3) {
                double onset = hatom_getdouble(&mk->l_head->l_hatom);
                e_marker_roles role = sym_to_marker_role(hatom_getsym(&mk->l_head->l_next->l_next->l_hatom));
                t_llll *content = mk->l_size >= 4 ? hatom_getllll(&mk->l_head->l_next->l_next->l_next->l_hatom) : NULL;
                
                if (role == k_MARKER_ROLE_MEASURE_BARLINE || role == k_MARKER_ROLE_TIME_SIGNATURE) {
                    // getting number of divisions before next barline
                    long num_divs = 1;
                    t_llllelem *next_barline = NULL;
                    double next_barline_onset = 0;
                    t_llll *onsets_divs = llll_get();
                    long num_barlines_in_range = 1;
                    t_rational ts_dur = genrat(4,4);
                    t_rational div_sym_dur = RAT_1OVER4;
                    t_llll *final_llll;
                    t_llllelem *tselem = NULL;
                    long i;
                    double cur = onset;
                    double next_onset;
                    t_llllelem *divel;
                    
                    if (role == k_MARKER_ROLE_TIME_SIGNATURE && content)
                        curr_ts = get_timesignature_from_llll((t_object *)x, content);
                    
                    if (curr_tempo_figure.r_num < 0 || (tempi_handling != k_TEMPI_FROM_TEMPO_MARKERS && role == k_MARKER_ROLE_TIME_SIGNATURE && content)) { // autoset
                        t_rational old_tempo_figure = curr_tempo_figure;
                        curr_tempo_figure = ts_to_division(NULL, &curr_ts);
                        curr_figure_tempo_value = curr_figure_tempo_value * (old_tempo_figure/RAT_1OVER4);
                    }
                    
                    t_rational to_set_later_tempo_figure = curr_tempo_figure;
                    double to_set_later_figure_tempo_value = curr_figure_tempo_value;
                    char need_set_curr_tempo = false;
                    
                    const long MAX_NUM_DIVISIONS = 50;
                    long num_subdivs[MAX_NUM_DIVISIONS];
                    long tot_num_subdivs = 1;
                    for (i = 0; i < MAX_NUM_DIVISIONS; i++)
                        num_subdivs[i] = 1;
                    
                    for (temp = elem->l_next; temp && num_divs < MAX_NUM_DIVISIONS; temp = temp->l_next) {
                        e_marker_roles this_role = get_marker_role_from_llllelem(temp);
                        t_llll *this_content = get_marker_content_from_llllelem(temp);
                        if (this_role == k_MARKER_ROLE_MEASURE_SUBDIVISION) {
                            num_subdivs[num_divs-1]++;
                            tot_num_subdivs++;
                        } else if (this_role == k_MARKER_ROLE_MEASURE_DIVISION) {
                            num_divs++;
                            tot_num_subdivs++;
                            llll_appenddouble(onsets_divs, get_marker_onset_from_llllelem(temp));
                        } else if (this_role == k_MARKER_ROLE_TIME_SIGNATURE || this_role == k_MARKER_ROLE_MEASURE_BARLINE) {
                            next_barline_onset = get_marker_onset_from_llllelem(temp);
                            next_barline = temp;
                            break;
                        } else if (this_role == k_MARKER_ROLE_TEMPO && this_content) {
                            // we store the current tempo in a variable, but we'll only set this for NEXT measure:
                            // this measure goes on with the existing tempo (tempi must always precede indeed measure barlines,
                            // and we have processed via check_that_all_tempo_elems_come_before_corresponding_ts_elems()
                            need_set_curr_tempo = true;
                            to_set_later_figure_tempo_value = hatom_getdouble(&this_content->l_tail->l_hatom);
                            if (this_content->l_size >= 2)
                                to_set_later_tempo_figure = hatom_getrational(&this_content->l_head->l_hatom);
                            else
                                to_set_later_tempo_figure = rat_long_prod(ts_to_division(NULL, &curr_ts), -1); // negative, meaning: auto set (might be changed if there's a measure/ts barline right after this marker
                        }
                    }
                    
                    // does time signature have irregular divisions?
                    char ts_has_irregular_divisions = false;
                    if (tot_num_subdivs > 0) {
                        for (i = 0; i < num_divs - 1; i++)
                            if (num_subdivs[i] != num_subdivs[i+1]) {
                                ts_has_irregular_divisions = true;
                                break;
                            }
                    }
                    if (ts_has_irregular_divisions) {
                        // dividing number of subdivision by their geq
                        long this_gcd = num_subdivs[0];
                        for (i = 1; i < num_divs; i++)
                            this_gcd = gcd(this_gcd, num_subdivs[i]);
                        if (this_gcd > 1) {
                            for (i = 0; i < num_divs; i++)
                                num_subdivs[i] /= this_gcd;
                            tot_num_subdivs /= this_gcd;
                        }
                        
                        // checking irregular ts coherence
                        if (curr_ts.numerator % tot_num_subdivs != 0) {
                            // incoherent!!! gotta make it coherent
                            if (incoherent_subdiv_mode == 1) {
                                long multiplier = MAX(0, ipow(2, floor(log2((double)tot_num_subdivs/curr_ts.denominator))));
                                curr_ts.numerator = tot_num_subdivs;
                                curr_ts.denominator *= multiplier;
                            } else {
                                ts_has_irregular_divisions = false;
                            }
                        }
                        
                        long irregular_ts_subdiv_mult = curr_ts.numerator / tot_num_subdivs;
                        if (ts_has_irregular_divisions) {
                            curr_ts.num_numerator_elements = num_divs;
                            for (i = 0; i < num_divs; i++)
                                curr_ts.numerator_elements[i] = num_subdivs[i] * irregular_ts_subdiv_mult;
                        }
                    }
                    
                    
                    
                    ts_dur = genrat(curr_ts.numerator, curr_ts.denominator);
                    cur = onset;
                    div_sym_dur = rat_long_div(ts_dur, num_divs);
                    
                    if ((curr_figure_tempo_value_is_dummy || (ts_has_irregular_divisions && tempi_handling != k_TEMPI_FROM_TEMPO_MARKERS)) && next_barline) { // < If there was NO defined first tempo, we infer the tempo from the barline distance
                        if (num_divs == 1) {
                            if (!allow_more_than_one_measure_within_barline_markers) {
                                curr_tempo_figure = ts_to_division(NULL, &curr_ts);
                                curr_figure_tempo_value = rat2double(rat_rat_div(RAT_1OVER4, curr_tempo_figure)) * 60 * 4000. / ((next_barline_onset - onset) / rat2double(ts_dur));
                                curr_figure_tempo_value_is_dummy = false;
                            }
                        } else {
                            if (ts_has_irregular_divisions) {
                                curr_tempo_figure = rat_rat_prod(ts_dur, genrat(num_subdivs[0],tot_num_subdivs));
                                curr_figure_tempo_value = 60 * 1000. / (((next_barline_onset - onset) * num_subdivs[0])/tot_num_subdivs);
                            } else {
                                curr_tempo_figure = rat_long_div(ts_dur, num_divs);
                                curr_figure_tempo_value = 60 * 1000. / ((next_barline_onset - onset) / num_divs);
                            }
                        }
                    }
                    
                    if (next_barline && !first_ts_or_measure_barline && num_divs == 1 && allow_more_than_one_measure_within_barline_markers) {
                        // we check if we have MORE than one bar inside the two barlines specifications!
                        double estimated_bar_dur = tempo_and_sym_duration_to_duration_ms(curr_figure_tempo_value, rat_abs(curr_tempo_figure), div_sym_dur);
                        double delta = next_barline_onset - cur;
                        num_barlines_in_range = MAX(1, round(delta/estimated_bar_dur));
                    }
                    
                    // some division markers inserted?
                    for (i = 1, divel = onsets_divs->l_head; divel && i < num_divs; divel = divel->l_next, i++) {
                        double this_onset = hatom_getdouble(&divel->l_hatom);
                        t_rational this_div_sym_dur = ts_has_irregular_divisions ? rat_rat_prod(ts_dur, genrat(num_subdivs[i-1],tot_num_subdivs)) : div_sym_dur;
                        t_llll *this_ll = llll_get();
                        llll_appenddouble(this_ll, cur);
                        llll_appenddouble(this_ll, this_onset - cur);
                        llll_appendrat(this_ll, this_div_sym_dur);
                        llll_appendllll(turnpike, this_ll);
                        
                        llll_appenddouble(divisions_absolute_position, this_onset);
                        
                        llll_appenddouble(quant_boxes_ms, this_onset - cur);
                        llll_appendrat(quant_boxes, this_div_sym_dur);
                        llll_appenddouble(quant_boxes_quartertempo, 240000. * rat2double(this_div_sym_dur)/(this_onset - cur));
                        llll_appendrat(quant_boxes_tempofigures, curr_tempo_figure);
                        
                        cur = this_onset;
                    }
                    
                    if (num_barlines_in_range > 1) { // more than one barline inside!
                        double single_meas_dur = (next_barline_onset - cur)/num_barlines_in_range;
                        // adding specification for each measure, except the last one (we'll do it later)
                        for (i = 1; i < num_barlines_in_range; i++) {
                            
                            // box-wise information
                            t_llll *meas_boxes = ts_to_beaming_boxes(NULL, &curr_ts, NULL, NULL);
                            double box_cur = cur;
                            t_llllelem *meas_boxes_elem;
                            for (meas_boxes_elem = meas_boxes->l_tail; meas_boxes_elem; meas_boxes_elem = meas_boxes_elem->l_prev){
                                t_rational this_box_sym_dur = hatom_getrational(&meas_boxes_elem->l_hatom);
                                double this_box_dur = single_meas_dur * rat2double(rat_rat_div(this_box_sym_dur, ts_dur));
                                t_llll *this_ll = llll_get();
                                
                                llll_appenddouble(this_ll, box_cur);
                                llll_appenddouble(this_ll, box_cur + this_box_dur);
                                llll_appendrat(this_ll, this_box_sym_dur);
                                llll_appendllll(turnpike, this_ll);
                                
                                llll_appenddouble(divisions_absolute_position, box_cur);
                                
                                llll_appenddouble(quant_boxes_ms, this_box_dur);
                                llll_appendrat(quant_boxes, this_box_sym_dur);
                                llll_appenddouble(quant_boxes_quartertempo, 240000. * rat2double(this_box_sym_dur)/this_box_dur);
                                llll_appendrat(quant_boxes_tempofigures, curr_tempo_figure);
                                box_cur += this_box_dur;
                            }
                            
                            
                            // measure-wise information
                            llll_appendrat(measure_boxes, ts_dur);
                            llll_appenddouble(measure_boxes_ms, single_meas_dur);
                            
                            t_llll *this_measureinfo_ll = llll_get();
                            t_llll *this_ts_ll = get_timesignature_as_llll(&curr_ts);
                            t_llll *this_tempi_ll = markers_to_tempi(x, markers, cur, cur + single_meas_dur, ts_dur, curr_tempo_figure);
                            llll_appendllll(this_measureinfo_ll, this_ts_ll);
                            llll_appendllll(this_measureinfo_ll, this_tempi_ll);
                            llll_appendllll(voice_ts, this_measureinfo_ll);
                            llll_appendlong(num_divisions, meas_boxes->l_size);
                            
                            cur += single_meas_dur;
                            llll_free(meas_boxes);
                        }
                        onset = cur;
                    }
                    
                    next_onset = next_barline ? next_barline_onset : cur + tempo_and_sym_duration_to_duration_ms(curr_figure_tempo_value, rat_abs(curr_tempo_figure), div_sym_dur);
                    
                    // default boxes for measure, if no boxes were assigned
                    if (num_divs == 1) {
                        t_llll *meas_boxes = ts_to_beaming_boxes(NULL, &curr_ts, NULL, NULL);
                        double box_cur = cur;
                        t_llllelem *meas_boxes_elem;
                        for (meas_boxes_elem = meas_boxes->l_tail; meas_boxes_elem; meas_boxes_elem = meas_boxes_elem->l_prev){
                            t_rational this_box_sym_dur = hatom_getrational(&meas_boxes_elem->l_hatom);
                            double this_box_dur = (next_onset - onset) * rat2double(rat_rat_div(this_box_sym_dur, ts_dur));
                            t_llll *this_ll = llll_get();
                            
                            llll_appenddouble(this_ll, box_cur);
                            llll_appenddouble(this_ll, box_cur + this_box_dur);
                            llll_appendrat(this_ll, this_box_sym_dur);
                            llll_appendllll(turnpike, this_ll);
                            
                            llll_appenddouble(divisions_absolute_position, box_cur);
                            
                            llll_appenddouble(quant_boxes_ms, this_box_dur);
                            llll_appendrat(quant_boxes, this_box_sym_dur);
                            llll_appenddouble(quant_boxes_quartertempo, 240000. * rat2double(this_box_sym_dur)/this_box_dur);
                            llll_appendrat(quant_boxes_tempofigures, curr_tempo_figure);
                            box_cur += this_box_dur;
                        }
                        llll_appendlong(num_divisions, meas_boxes->l_size);
                        llll_free(meas_boxes);
                    } else { // there were assigned boxes
                        // last box
                        t_rational this_div_sym_dur = ts_has_irregular_divisions ? rat_rat_prod(ts_dur, genrat(num_subdivs[num_divs-1],tot_num_subdivs)) : div_sym_dur;
                        final_llll = llll_get();
                        llll_appenddouble(final_llll, cur);
                        llll_appenddouble(final_llll, next_onset);
                        llll_appendrat(final_llll, this_div_sym_dur);
                        llll_appendllll(turnpike, final_llll);
                        
                        llll_appenddouble(divisions_absolute_position, cur);
                        
                        llll_appenddouble(quant_boxes_ms, next_onset - cur); // quant_boxes in ms
                        llll_appendrat(quant_boxes, this_div_sym_dur); // quant_boxes in symbolic
                        llll_appenddouble(quant_boxes_quartertempo, 240000. * rat2double(this_div_sym_dur)/(next_onset - cur));
                        llll_appendrat(quant_boxes_tempofigures, curr_tempo_figure);
                        
                        llll_appendlong(num_divisions, num_divs);
                    }
                    
                    llll_appendrat(measure_boxes, ts_dur);
                    llll_appenddouble(measure_boxes_ms, next_onset - onset);
                    
                    t_llll *this_measureinfo_ll = llll_get();
                    t_llll *this_ts_ll = get_timesignature_as_llll(&curr_ts);
                    
                    if (tempi_handling == k_TEMPI_FROM_MEASURE_DIVISIONS || tempi_handling == k_TEMPI_FROM_MEASURE_BARLINES) {
                        // update curr_tempo_value
                        curr_figure_tempo_value = 60 * 1000 * rat2double(rat_rat_div(ts_to_sym_duration(&curr_ts), curr_tempo_figure)) / (next_onset - onset);
                        //                        curr_figure_tempo_value = rat2double(rat_rat_div(ts_to_sym_duration(&curr_ts), curr_tempo_figure)) * (0.25/rat2double(curr_tempo_figure)) * 60 * 1000. / (next_onset - onset);
                    }
                    
                    llll_appendllll(this_measureinfo_ll, this_ts_ll);
                    if (num_barlines_in_range == 1) { // otherwise we have already put the tempo before!
                        t_llll *this_tempi_ll = (tempi_handling == k_TEMPI_FROM_TEMPO_MARKERS ? markers_to_tempi(x, markers, onset, next_onset, ts_dur, curr_tempo_figure) : llll_get());
                        llll_appendllll(this_measureinfo_ll, this_tempi_ll);
                    }
                    tselem = llll_appendllll(voice_ts, this_measureinfo_ll);
                    
                    
                    /// PICKUP MEASURE???
                    if (measure_boxes->l_size == 1) {
                        // first measure: do we need a pickup measure?!?
                        double dur = next_onset - onset;
                        if (onset >= CONST_THRESHOLD_MS_FOR_PICKUP_MEASURE * dur/quant_boxes->l_size) {
                            // fixed threshold expressed as a ratio of the division
                            // need one or more pickup measures!
                            cur = onset;
                            while (cur > 0) {
                                
                                // box-wise information
                                t_llll *meas_boxes = ts_to_beaming_boxes(NULL, &curr_ts, NULL, NULL);
                                double box_cur = cur;
                                t_llllelem *meas_boxes_elem;
                                for (meas_boxes_elem = meas_boxes->l_tail; meas_boxes_elem; meas_boxes_elem = meas_boxes_elem->l_prev){
                                    t_rational this_box_sym_dur = hatom_getrational(&meas_boxes_elem->l_hatom);
                                    double this_box_dur = dur * rat2double(rat_rat_div(this_box_sym_dur, ts_dur));
                                    t_llll *this_ll = llll_get();
                                    llll_appenddouble(this_ll, box_cur - this_box_dur); // rest?
                                    llll_appenddouble(this_ll, box_cur); // - this_box_dur);
                                    llll_appendrat(this_ll, this_box_sym_dur);
                                    llll_prependllll(turnpike, this_ll);
                                    
                                    llll_prependdouble(divisions_absolute_position, box_cur - this_box_dur);
                                    
                                    llll_prependdouble(quant_boxes_ms, this_box_dur);  // quant_boxes is in ms
                                    llll_prependrat(quant_boxes, this_box_sym_dur);
                                    llll_prependdouble(quant_boxes_quartertempo, 240000. * rat2double(this_box_sym_dur)/this_box_dur);
                                    llll_prependrat(quant_boxes_tempofigures, curr_tempo_figure);
                                    box_cur -= this_box_dur;
                                }
                                
                                // measure-wise information
                                llll_prependrat(measure_boxes, ts_dur);
                                llll_prependdouble(measure_boxes_ms, dur);
                                
                                t_llll *this_measureinfo_ll = llll_get();
                                t_llll *this_ts_ll = get_timesignature_as_llll(&curr_ts);
                                t_llll *this_tempi_ll = (tempi_handling == k_TEMPI_FROM_TEMPO_MARKERS ? markers_to_tempi(x, markers, cur-dur, cur, ts_dur, curr_tempo_figure) : llll_get());
                                llll_appendllll(this_measureinfo_ll, this_ts_ll);
                                llll_appendllll(this_measureinfo_ll, this_tempi_ll);
                                tselem = llll_prependllll(voice_ts, this_measureinfo_ll);
                                
                                llll_appendlong(num_divisions, meas_boxes->l_size);
                                
                                cur -=dur;
                                llll_free(meas_boxes);
                            }
                            *global_delta_onset = -cur;
                            
                            // adding a fake rest at the beginning
                            llll_prependdouble(voice_durations, cur);
                            llll_prependllll(voice_infos, get_nilinfo());
                            llll_prependllll(voice_ties, llll_get());
                            
                        } else if (onset < 0) { // something is < 0! (it might even be a marker determining time/sig or measures or tempo: gotta add a fake pause
                            *global_delta_onset = -onset;
                            
                            // adding a fake rest at the beginning
                            llll_prependdouble(voice_durations, onset);
                            llll_prependllll(voice_infos, get_nilinfo());
                            llll_prependllll(voice_ties, llll_get());
                            
                        } else { // onset is >= 0 but not enough to create a pickup measure.
                            
                            // modifying first durations
                            double s = 0, to_add = 0;
                            while (s < onset && voice_durations->l_head) {
                                double this_dur = abs(hatom_getdouble(&voice_durations->l_head->l_hatom));
                                if (s + this_dur <= onset || this_dur == 0) {
                                    to_add += this_dur;
                                    llll_behead(voice_durations);
                                    llll_behead(voice_infos);
                                    llll_behead(voice_ties);
                                } else {
                                    long sign_dur = hatom_getdouble(&voice_durations->l_head->l_hatom) < 0 ? -1 : 1;
                                    hatom_setdouble(&voice_durations->l_head->l_hatom, sign_dur * (this_dur + onset - s));
                                    break;
                                }
                                s += this_dur;
                            }

                            if (voice_durations->l_head) {
                                double this_dur = abs(hatom_getdouble(&voice_durations->l_head->l_hatom));
                                long sign_dur = hatom_getdouble(&voice_durations->l_head->l_hatom) < 0 ? -1 : 1;
                                hatom_setdouble(&voice_durations->l_head->l_hatom, sign_dur * (this_dur + to_add));
                            }

                            // modifying first quantization box
                            if (quant_boxes_ms->l_head)
                                hatom_setdouble(&quant_boxes_ms->l_head->l_hatom, hatom_getdouble(&quant_boxes_ms->l_head->l_hatom) + onset);
                            // modifying first tempo
                            if (quant_boxes_ms->l_head && quant_boxes->l_head && quant_boxes_quartertempo->l_head)
                                hatom_setdouble(&quant_boxes_quartertempo->l_head->l_hatom, 240000. * rat2double(hatom_getrational(&quant_boxes->l_head->l_hatom)) / hatom_getdouble(&quant_boxes_ms->l_head->l_hatom));
                            
                            if (measure_boxes_ms->l_head)
                                hatom_setdouble(&measure_boxes_ms->l_head->l_hatom, hatom_getdouble(&measure_boxes_ms->l_head->l_hatom) + onset);
                            if (turnpike->l_head && hatom_gettype(&turnpike->l_head->l_hatom) == H_LLLL) {
                                t_llll *ll = hatom_getllll(&turnpike->l_head->l_hatom);
                                if (ll && ll->l_head && is_hatom_number(&ll->l_head->l_hatom))
                                    hatom_setdouble(&ll->l_head->l_hatom, 0);
                            }
                        }
                    }
                    
                    llll_free(onsets_divs);
                    
                    // setting curr_tempo
                    if (need_set_curr_tempo) {
                        must_specify_tempo = true;
                        curr_figure_tempo_value_is_dummy = false;
                        curr_figure_tempo_value = to_set_later_figure_tempo_value;
                        curr_tempo_figure = to_set_later_tempo_figure;
                    }
                    
                    if (next_barline)
                        elem = next_barline->l_prev; // will be ->nexted by the foor loop!
                    
                    first_ts_or_measure_barline = false;
                    
                } else if (role == k_MARKER_ROLE_TEMPO && content && tempi_handling == k_TEMPI_FROM_TEMPO_MARKERS) {
                    must_specify_tempo = true;
                    curr_figure_tempo_value_is_dummy = false;
                    curr_figure_tempo_value = hatom_getdouble(&content->l_tail->l_hatom);
                    if (content->l_size >= 2)
                        curr_tempo_figure = hatom_getrational(&content->l_head->l_hatom);
                    else
                        curr_tempo_figure = rat_long_prod(ts_to_division(NULL, &curr_ts), -1); // negative, meaning: auto set (might be changed if there's a measure/ts barline right after this marker
                }
            }
        }
    }
    
    // adding measures to pad?
    if (quant_boxes_ms->l_tail && quant_boxes->l_tail && voice_ts->l_tail) {
        double tot_boxed_duration = llll_sum_of_doubles_llll(quant_boxes_ms);
        while (tot_boxed_duration < sum_all_durations) {
            
            // box-wise information
            t_llll *meas_boxes = ts_to_beaming_boxes(NULL, &curr_ts, NULL, NULL);
            double last_measure_dur = hatom_getdouble(&measure_boxes_ms->l_tail->l_hatom);
            t_rational last_ts_dur = genrat(curr_ts.numerator, curr_ts.denominator);
            double box_cur = tot_boxed_duration;
            t_llllelem *meas_boxes_elem;
            for (meas_boxes_elem = meas_boxes->l_tail; meas_boxes_elem; meas_boxes_elem = meas_boxes_elem->l_prev){
                t_rational this_box_sym_dur = hatom_getrational(&meas_boxes_elem->l_hatom);
                double this_box_dur = last_measure_dur * rat2double(rat_rat_div(this_box_sym_dur, last_ts_dur));
                t_llll *this_ll = llll_get();
                llll_appenddouble(this_ll, box_cur);
                llll_appenddouble(this_ll, box_cur + this_box_dur);
                llll_appendrat(this_ll, this_box_sym_dur);
                llll_appendllll(turnpike, this_ll);
                
                llll_appenddouble(divisions_absolute_position, box_cur);
                
                llll_appenddouble(quant_boxes_ms, this_box_dur);  // quant_boxes is in ms
                llll_appendrat(quant_boxes, this_box_sym_dur);
                llll_appenddouble(quant_boxes_quartertempo, 240000. * rat2double(this_box_sym_dur)/this_box_dur);
                llll_appendrat(quant_boxes_tempofigures, curr_tempo_figure);
                box_cur += this_box_dur;
            }
            
            //measure-wise information
            llll_appendrat(measure_boxes, last_ts_dur);
            llll_appenddouble(measure_boxes_ms, last_measure_dur);
            
            t_llll *new_last_ll = llll_get();
            llll_appendhatom_clone(new_last_ll, &voice_ts->l_tail->l_hatom.h_w.w_llll->l_head->l_hatom);
            llll_appendllll(voice_ts, new_last_ll);
            llll_appendllll(voice_ts->l_tail->l_hatom.h_w.w_llll, tempi_handling == k_TEMPI_FROM_TEMPO_MARKERS ? markers_to_tempi(x, markers, tot_boxed_duration, tot_boxed_duration + last_measure_dur, last_ts_dur, curr_tempo_figure) : llll_get());
            llll_upgrade_depth(voice_ts->l_tail->l_hatom.h_w.w_llll->l_tail->l_hatom.h_w.w_llll);
            
            //			dev_llll_print(voice_ts, NULL, 0, 2, NULL);
            
            tot_boxed_duration += last_measure_dur;
            llll_free(meas_boxes);
        }
    }
    
    
    // setting tempo information
    if (tempi_handling == k_TEMPI_FROM_MEASURE_BARLINES || tempi_handling == k_TEMPI_FROM_MEASURE_DIVISIONS) {
        long tempo_approx_digits = x->tempo_approx_digits;
        t_llllelem *voice_ts_elem = voice_ts->l_head; // actually this is measureinfo, not ts
        t_llllelem *tempo_elem = quant_boxes_quartertempo->l_head;
        t_llllelem *tempofigures_elem = quant_boxes_tempofigures->l_head;
        t_llllelem *sym_elem = quant_boxes->l_head;
        t_llllelem *num_divisions_elem = num_divisions->l_head;
        t_llllelem *divisions_absolute_position_elem = divisions_absolute_position->l_head;
        t_rational curr_tempo_figure = long2rat(0);
        t_rational cur_onset = long2rat(0);
        double curr_tempo_value = -111100, curr_approx_tempo_value = -111100; // doesn't matter, weird, just to initialize
        double quartertempo_avg = 0;
        double cumulated_quantized_duration_ms = 0;
        long count = 0;
        double abs_pos = 0;
        long meas_count = 1;
        t_llll *tempi_ll = llll_get();
        while (voice_ts_elem && num_divisions_elem && sym_elem && tempo_elem && divisions_absolute_position_elem) {
            long this_num_divisions = hatom_getlong(&num_divisions_elem->l_hatom);
            t_llll *this_measureinfo = hatom_getllll(&voice_ts_elem->l_hatom);
            t_rational this_sym_elem = hatom_getrational(&sym_elem->l_hatom);
            t_rational tempo_figure = hatom_getrational(&tempofigures_elem->l_hatom);
            double quartertempo = hatom_getdouble(&tempo_elem->l_hatom);
            
            if (tempi_handling == k_TEMPI_FROM_MEASURE_DIVISIONS || cur_onset.r_num == 0)
                abs_pos = hatom_getdouble(&divisions_absolute_position_elem->l_hatom);
            
            quartertempo_avg += quartertempo * rat2double(this_sym_elem);
            
            if (tempi_handling == k_TEMPI_FROM_MEASURE_DIVISIONS) {
                double tempo_value_for_figure = quartertempo * rat2double(rat_rat_div(RAT_1OVER4, tempo_figure));
                double approx_tempo_value_for_figure = approx_tempo(tempo_value_for_figure, tempo_approx_digits, abs_pos - cumulated_quantized_duration_ms);
                char entered = false;
                if (rat_rat_cmp(curr_tempo_figure, tempo_figure) != 0 ||
                    curr_tempo_value != tempo_value_for_figure ||
                    (curr_approx_tempo_value != approx_tempo_value_for_figure && (tempo_approx_mode == 2 || (tempo_approx_mode == 1 && cur_onset.r_num == 0))))
                {
                    entered = true;
                    t_llll *this_tempo_ll = llll_get();
                    llll_appendrat(this_tempo_ll, tempo_figure);
                    llll_appenddouble(this_tempo_ll, approx_tempo_value_for_figure);
                    llll_appendrat(this_tempo_ll, cur_onset);
                    llll_appendllll(tempi_ll, this_tempo_ll);
                    
                    curr_tempo_figure = tempo_figure;
                    curr_approx_tempo_value = approx_tempo_value_for_figure; // cumulated_quantized_duration_ms - abs_pos);
                    curr_tempo_value = tempo_value_for_figure; // cumulated_quantized_duration_ms - abs_pos);
                }
                cumulated_quantized_duration_ms += tempo_and_sym_duration_to_duration_ms(curr_approx_tempo_value, curr_tempo_figure, this_sym_elem);
                
#ifdef BACH_QUANTIZE_DEBUG
                post("%sMeasure %ld, offset %ld/%ld, tempo: %ld/%ld = %.2f, cumulated_ms = %.4f%s", !entered ? "(" : "", meas_count, cur_onset.r_num, cur_onset.r_den, tempo_figure.r_num, tempo_figure.r_den, tempo_value_for_figure, cumulated_quantized_duration_ms, !entered ? ")" : "");
#endif
            }
            
            count ++;
            cur_onset = rat_rat_sum(cur_onset, this_sym_elem);
            
            if (count >= this_num_divisions) {
                if (tempi_handling == k_TEMPI_FROM_MEASURE_BARLINES) {
                    double tempo_value_for_figure = quartertempo_avg * rat2double(rat_rat_div(RAT_1OVER4, tempo_figure)) / rat2double(cur_onset);
                    double approx_tempo_value_for_figure = approx_tempo(tempo_value_for_figure, tempo_approx_digits, abs_pos - cumulated_quantized_duration_ms);
                    char entered = false;
                    if (rat_rat_cmp(curr_tempo_figure, tempo_figure) != 0 ||
                        curr_tempo_value != tempo_value_for_figure ||
                        (curr_approx_tempo_value != approx_tempo_value_for_figure && (tempo_approx_mode > 0))) {
                        entered = true;
                        t_llll *this_tempo_ll = llll_get();
                        llll_appendrat(this_tempo_ll, tempo_figure);
                        llll_appenddouble(this_tempo_ll, approx_tempo_value_for_figure);
                        llll_appendllll(tempi_ll, this_tempo_ll);
                        curr_tempo_figure = tempo_figure;
                        curr_tempo_value = tempo_value_for_figure;
                        curr_approx_tempo_value = approx_tempo_value_for_figure;
                    }
                    cumulated_quantized_duration_ms += tempo_and_sym_duration_to_duration_ms(curr_approx_tempo_value, curr_tempo_figure, cur_onset);
                    
#ifdef BACH_QUANTIZE_DEBUG
                    post("%sMeasure %ld, tempo: %ld/%ld = %.2f, cumulated_ms = %.4f%s", !entered ? "(" : "", meas_count, tempo_figure.r_num, tempo_figure.r_den, tempo_value_for_figure, cumulated_quantized_duration_ms, !entered ? ")" : "");
#endif
                }
                
                
                if (this_measureinfo && this_measureinfo->l_head && this_measureinfo->l_head->l_next)
                    hatom_change_to_llll_and_free(&this_measureinfo->l_head->l_next->l_hatom, llll_clone(tempi_ll));
                
                num_divisions_elem = num_divisions_elem->l_next;
                voice_ts_elem = voice_ts_elem->l_next;
                llll_clear(tempi_ll);
                cur_onset = long2rat(0);
                count = 0;
                meas_count++;
                quartertempo_avg = 0;
            }
            tempo_elem = tempo_elem->l_next;
            sym_elem = sym_elem->l_next;
            tempofigures_elem = tempofigures_elem->l_next;
            divisions_absolute_position_elem = divisions_absolute_position_elem->l_next;
        }
        llll_free(tempi_ll);
    }
    
    
    
    
    
    // once we have the turnpike, we need to obtain the proper rat_duration values!
    // first we divide by default each milllisecond value
    t_llll *foo = llll_get();
    t_llll *foo2 = llll_get();
    long foo3;
    t_llll *foo4 = llll_get();
    llll_appendlong(foo, 4);
    llll_appendlong(foo, 4);
    llll_appendllll(foo2, foo);
    
    // CONST_RAT_SINGLE_DEN
    t_llll *rough_rat_durations = ms_to_rat_durations(foo2, foo4, voice_durations, &foo3, 1000, true); // rough durations for quarter = 60
    t_llll *rough_quant_boxes_ms = ms_to_rat_durations(foo2, foo4, quant_boxes_ms, &foo3, 1000, true); // rough durations for quarter = 60
    
#ifdef BACH_QUANTIZE_DEBUG
    llll_print_named(divisions_absolute_position, gensym("division absolute pos"), 0, 2, NULL);
    llll_print_named(voice_ts, gensym("voice ts"), 0, 2, NULL);
    llll_print_named(voice_durations, gensym("voice durations"), 0, 2, NULL);
    llll_print_named(quant_boxes_ms, gensym("quant boxes (ms)"), 0, 2, NULL);
    llll_print_named(quant_boxes, gensym("quant boxes"), 0, 2, NULL);
    llll_print_named(quant_boxes_quartertempo, gensym("quant boxes quartertempo"), 0, 2, NULL);
    llll_print_named(quant_boxes_tempofigures, gensym("quant boxes tempofigures"), 0, 2, NULL);
    llll_print_named(rough_rat_durations, gensym("rough rat durs"), 0, 2, NULL);
    llll_print_named(rough_quant_boxes_ms, gensym("rough quant boxes (ms)"), 0, 2, NULL);
    llll_print_named(measure_boxes, gensym("measure boxes"), 0, 2, NULL);
    llll_post(voice_durations, 0, 1, 2, NULL, NULL);
    llll_post(quant_boxes, 0, 1, 2, NULL, NULL);
#endif
    
    char completed = split_rhythm_to_boxes(rough_rat_durations, voice_infos, voice_ties, rough_quant_boxes_ms,
                                           unquantized_boxed_voice_durations, unquantized_boxed_voice_infos, unquantized_boxed_voice_ties,
                                           true, QUANTIZE_MARK_TIED_INFOS, true);
    
    llll_check(*unquantized_boxed_voice_durations);
    
    llll_free(rough_rat_durations);
    llll_free(rough_quant_boxes_ms);
    
#ifdef BACH_QUANTIZE_DEBUG
    dev_llll_print(*unquantized_boxed_voice_durations, NULL, 0, 2, NULL);
    llll_post(*unquantized_boxed_voice_durations, 0, 1, 2, NULL, NULL);
#endif
    
    // now in each box we have the correct split stuff, but not the correct durations: we have to force that the symbolic sum of each box be the correct one
    t_llllelem *durs_box, *widths_box;
    for (durs_box = (*unquantized_boxed_voice_durations)->l_head, widths_box = turnpike->l_head; durs_box && widths_box; durs_box = durs_box->l_next, widths_box = widths_box->l_next) {
        t_rational this_width = hatom_getrational(&widths_box->l_hatom.h_w.w_llll->l_head->l_next->l_next->l_hatom);
        t_llll *durs_ll = hatom_getllll(&durs_box->l_hatom);
        t_llllelem *dur;
        t_llll *new_durs;
        
        // 1. reconverting durs_box to doubles
        for (dur = durs_ll->l_head; dur; dur = dur->l_next)
            hatom_setdouble(&dur->l_hatom, rat2double(hatom_getrational(&dur->l_hatom)));
        
#ifdef BACH_QUANTIZE_DEBUG
        dev_post("--- new box ---");
        dev_llll_print(durs_ll, NULL, 0, 4, NULL);
#endif
        
        // 2. imposing a given sum
        double sum = llll_sum_abs_of_double_llll(durs_ll);
        double multiplier = rat2double(this_width)/sum;
        for (dur = durs_ll->l_head; dur; dur = dur->l_next)
            hatom_setdouble(&dur->l_hatom, hatom_getdouble(&dur->l_hatom) * multiplier);
        
#ifdef BACH_QUANTIZE_DEBUG
        dev_llll_print(durs_ll, NULL, 0, 4, NULL);
#endif
        
        // 3. reobtaining symbolic values
        t_llll *foo5 = llll_get();
        t_tempo *dummytempo = build_tempo(long2rat(0), long2rat(240000), RAT_1OVER4, 0);
        llll_appendobj(foo5, dummytempo);
        new_durs = ms_to_rat_durations(foo2, foo5, durs_ll, &foo3, CONST_RAT_SINGLE_DEN, true);
        free_tempo(NULL, dummytempo);
        //		llll_free(durs_ll);
        //		hatom_setllll(&durs_box->l_hatom, new_durs);
        hatom_change_to_llll_and_free(&durs_box->l_hatom, new_durs);
        
#ifdef BACH_QUANTIZE_DEBUG
        dev_llll_print(new_durs, NULL, 0, 4, NULL);
#endif
        llll_free(foo5);
    }
    
    llll_free(foo2);
    llll_free(foo4);
    llll_free(turnpike);
    llll_free(quant_boxes_ms);
    llll_free(measure_boxes_ms);
    llll_free(quant_boxes_quartertempo);
    llll_free(quant_boxes_tempofigures);
    llll_free(divisions_absolute_position);
    llll_free(num_divisions);
    
    return completed;
}


void check_that_all_tempo_elems_come_before_corresponding_ts_elems(t_quantize *x, t_llll *markers)
{
    t_llllelem *elem = markers->l_head;
    while (elem) {
        t_llllelem *next = elem->l_next;
        double onset = get_marker_onset_from_llllelem(elem);
        if (get_marker_role_from_llllelem(elem) == k_MARKER_ROLE_TEMPO) {
            e_marker_roles role;
            t_llllelem *firstelem = elem;
            
            while (elem->l_prev && get_marker_role_from_llllelem(elem->l_prev) == k_MARKER_ROLE_NONE)
                elem = elem->l_prev;
            
            if (elem->l_prev && ((role = get_marker_role_from_llllelem(elem->l_prev)) == k_MARKER_ROLE_TIME_SIGNATURE ||
                                 role == k_MARKER_ROLE_MEASURE_BARLINE || role == k_MARKER_ROLE_MEASURE_DIVISION)) {
                double onset_prev = get_marker_onset_from_llllelem(elem->l_prev);
                if (fabs(onset - onset_prev) < CONST_THRESHOLD_MS_FOR_TEMPO_MARKERS_BEING_ON_TS_MARKERS) { // threshold in milliseconds
                    hatom_setdouble(&elem->l_hatom.h_w.w_llll->l_head->l_hatom, onset_prev);
                    llll_swapelems(elem->l_prev, firstelem);
                }
            }
        }
        elem = next;
    }
}


t_llllelem *llll_appendhatom_clone_handle_slots(t_quantize *x, t_llll *where, t_hatom *what, long flags, t_llll *adopter, char marked_as_newly_tied_from)
{
    if (!marked_as_newly_tied_from || what->h_type != H_LLLL)
        return llll_appendhatom_clone(where, what, flags, adopter);
    
    t_llll *slots = hatom_getllll(what);
    t_llll *new_ll = llll_get();
    t_llllelem *temp, *slotelem;
    for (temp = slots->l_head; temp; temp = temp->l_next) {
        if (hatom_gettype(&temp->l_hatom) == H_LLLL) {
            // note slots
            t_llll *new_note_slots_ll = llll_get();
            for (slotelem = hatom_getllll(&temp->l_hatom)->l_head; slotelem; slotelem = slotelem->l_next) {
                if (hatom_gettype(&slotelem->l_hatom) == H_LLLL) {
                    // single slot
                    t_llll *this_slot = hatom_getllll(&slotelem->l_hatom);
                    //                    dev_llll_print(this_slot, NULL, 0, 0, NULL);
                    
                    if (this_slot && this_slot->l_head && hatom_gettype(&this_slot->l_head->l_hatom) == H_LONG) {
                        long slot_num = hatom_getlong(&this_slot->l_head->l_hatom) - 1; // 0-based
                        long slot_type = slot_num >= 0 && slot_num < CONST_MAX_SLOTS ? x->slot_types[slot_num] : k_SLOT_TYPE_NONE;
                        
                        if (marked_as_newly_tied_from && !x->slot_copy_when_split[slot_num])
                            continue; // don't clone this slot!
                        
                        switch (slot_type) {
                            case k_SLOT_TYPE_ARTICULATIONS:
                                // handle the fact that articulations on tied notes might NOT be added.
                                // e.g. if I had a staccato note, quantized into two tied notes, only the first one will be staccato
                                if (!marked_as_newly_tied_from) {
                                    llll_appendllll_clone(new_note_slots_ll, this_slot);
                                } else {
                                    t_llllelem *elem;
                                    t_llll *new_art_ll = llll_get();
                                    llll_appendlong(new_art_ll, slot_num + 1); // need to be 1-based
                                    for (elem = this_slot->l_head->l_next; elem; elem = elem->l_next) {
                                        long art_id = (hatom_gettype(&elem->l_hatom) == H_SYM ? articulation_symbol2id(&x->articulations_typo_preferences, hatom_getsym(&elem->l_hatom)) : k_ARTICULATION_NONE);
                                        if (x->articulations_typo_preferences.artpref[art_id].options & k_ARTICULATION_OPTION_COPY_WHEN_SPLIT)
                                            llll_appendhatom_clone(new_art_ll, &elem->l_hatom);
                                    }
                                    llll_appendllll(new_note_slots_ll, new_art_ll);
                                    
                                }
                                break;
                                
                            default:
                                llll_appendllll_clone(new_note_slots_ll, this_slot);
                                break;
                        }
                    }
                }
            }
            llll_appendllll(new_ll, new_note_slots_ll);
        }
    }
    
    
    return llll_appendllll(where, new_ll, flags, adopter);
}


long make_ids_fn(void *data, t_hatom *a, const t_llll *address)
{
    long *num = (long *)data;
    if (is_hatom_number(a)){
        hatom_setlong(a, *num);
        (*num)++;
    }
    return 0;
}

long make_01_fn(void *data, t_hatom *a, const t_llll *address){
    if (hatom_gettype(a) == H_LONG)
        hatom_setlong(a, hatom_getlong(a) > 0 ? 1 : 0);
    return 0;
}


void quantize_anything(t_quantize *x, t_symbol *msg, long ac, t_atom *av)
{
    long inlet = proxy_getinlet((t_object *) x);
    long i;
    
    if (msg == _sym_clear) {
        x->rt_last_length = 0;
        x->rt_achieved_length = 0;
        llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), inlet);
        return;
    }
    
    if (msg == _llllobj_sym_clearall) {
        x->rt_last_length = 0;
        x->rt_achieved_length = 0;
        for (i = 0; i < (x->separate_mode ? 6 : 1); i++)
            llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), i);
        
        if (x->marker_info) {
            llll_free(x->marker_info);
            x->marker_info = NULL;
        }
        if (x->header_info)
            llll_clear(x->header_info);
        
        if (x->noteIDs) {
            llll_free(x->noteIDs);
            x->noteIDs = NULL;
        }
        return;
    }
    
    
    if (msg != _sym_bang) {
        t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
        t_symbol *router = (arguments && arguments->l_head && hatom_gettype(&arguments->l_head->l_hatom) == H_SYM ? hatom_getsym(&arguments->l_head->l_hatom) : NULL);
        if (inlet == 1 && router == _llllobj_sym_quantize) {
            long i;
            t_llllelem *elem;
            
            llll_destroyelem(arguments->l_head);
            
            if (x->marker_info) {
                llll_free(x->marker_info);
                x->marker_info = NULL;
            }
            if (x->header_info)
                llll_clear(x->header_info);
            
            while (arguments->l_head && hatom_gettype(&arguments->l_head->l_hatom) == H_LLLL && hatom_getllll(&arguments->l_head->l_hatom)->l_head && hatom_gettype(&hatom_getllll(&arguments->l_head->l_hatom)->l_head->l_hatom) == H_SYM){
                if (hatom_getsym(&hatom_getllll(&arguments->l_head->l_hatom)->l_head->l_hatom) == _llllobj_sym_markers){
                    
                    // 1. copying markers to header_info
                    llll_appendhatom_clone(x->header_info, &arguments->l_head->l_hatom);
                    // deleting special markers
                    t_llllelem *tmp = hatom_getllll(&x->header_info->l_tail->l_hatom)->l_head->l_next, *nxt;
                    while (tmp) {
                        nxt = tmp->l_next;
                        if (get_marker_role_from_llllelem(tmp) != k_MARKER_ROLE_NONE)
                            llll_destroyelem(tmp);
                        tmp = nxt;
                    }
                    
                    // 2. handle measureinfo via markers
                    t_llll *ll = hatom_getllll(&arguments->l_head->l_hatom);
                    llll_destroyelem(ll->l_head);
                    x->marker_info = llll_clone(ll);
                    // TODO remove non-special markers (no big deal, they're ignored, who cares!)
                    check_that_all_tempo_elems_come_before_corresponding_ts_elems(x, x->marker_info);
                    
                } else  {
                    if (hatom_getsym(&hatom_getllll(&arguments->l_head->l_hatom)->l_head->l_hatom) == _llllobj_sym_slotinfo) {
                        // detecting slot types
                        t_llll *ll = hatom_getllll(&arguments->l_head->l_hatom);
                        t_llllelem *slotinfoelem;
                        for (i = 0; i < CONST_MAX_SLOTS; i++) x->slot_types[i] = k_SLOT_TYPE_NONE;
                        for (slotinfoelem = ll->l_head->l_next; slotinfoelem; slotinfoelem = slotinfoelem->l_next) {
                            if (hatom_gettype(&slotinfoelem->l_hatom) == H_LLLL) {
                                t_llll *this_slotinfo_ll = hatom_getllll(&slotinfoelem->l_hatom);
                                if (this_slotinfo_ll && this_slotinfo_ll->l_head && hatom_gettype(&this_slotinfo_ll->l_head->l_hatom) == H_LONG) {
                                    long slotnum = hatom_getlong(&this_slotinfo_ll->l_head->l_hatom) - 1; // to 0-based
                                    if (slotnum >= 0 && slotnum < CONST_MAX_SLOTS) {
                                        // finding slot type
                                        t_llllelem *temp;
                                        for (temp = this_slotinfo_ll->l_head->l_next; temp; temp = temp->l_next) {
                                            if (hatom_gettype(&temp->l_hatom) == H_LLLL) {
                                                t_llll *single_entry = hatom_getllll(&temp->l_hatom);
                                                if (single_entry->l_head && single_entry->l_head->l_next && hatom_gettype(&single_entry->l_head->l_hatom) == H_SYM) {
                                                    t_symbol *router = hatom_getsym(&single_entry->l_head->l_hatom);
                                                    if (router == _llllobj_sym_type && hatom_gettype(&single_entry->l_head->l_next->l_hatom) == H_SYM)
                                                        x->slot_types[slotnum] = slot_symbol_to_type(hatom_getsym(&single_entry->l_head->l_next->l_hatom));
                                                    else if (router == _llllobj_sym_copywhensplit && is_hatom_number(&single_entry->l_head->l_next->l_hatom))
                                                        x->slot_copy_when_split[slotnum] = hatom_getlong(&single_entry->l_head->l_next->l_hatom);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (hatom_getsym(&hatom_getllll(&arguments->l_head->l_hatom)->l_head->l_hatom) == _llllobj_sym_articulationinfo) {
                        // custom articulation definition
                        t_llll *ll = hatom_getllll(&arguments->l_head->l_hatom);
                        set_articulationinfo_from_llll(NULL, &x->articulations_typo_preferences, ll, false);
                    }
                    llll_appendhatom_clone(x->header_info, &arguments->l_head->l_hatom);
                }
                llll_destroyelem(arguments->l_head);
            }
            
            elem = arguments->l_head;
            for (i = 1; i < 6 && elem; i++, elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_LLLL) { // should always be the case
                    t_llll *this_cloned_llll = llll_clone(hatom_getllll(&elem->l_hatom));
                    llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, this_cloned_llll, i);
                }
            }
            
            // storing note IDs
            if (i == 6 && elem && hatom_gettype(&elem->l_hatom) == H_LLLL) {
                if (x->noteIDs)
                    llll_free(x->noteIDs);
                x->noteIDs = llll_clone(hatom_getllll(&elem->l_hatom));
            }
            
            llll_free(arguments);
        } else if (inlet != 1 && router == _llllobj_sym_quantize){
            object_warn((t_object *)x, "Warning: use second inlet for \"quantize\" message.");
        } else if (router == _llllobj_sym_roll || router == _llllobj_sym_score){
            object_warn((t_object *)x, "Warning: quantize does not understand roll or score gathered syntax. Use the \"quantize\" message instead.");
        } else if (inlet == 0 && router == gensym("allow")) {
            llll_behead(arguments);
            if (x->allow_box_durs)
                llll_free(x->allow_box_durs);
            if (arguments->l_size > 0)
                x->allow_box_durs = arguments;
            else {
                x->allow_box_durs = NULL;
                llll_free(arguments);
            }
            return; // no need to perform calculations
        } else if (inlet == 0 && (router == gensym("forbid") || router == gensym("deny"))) {
            llll_behead(arguments);
            if (x->deny_box_durs)
                llll_free(x->deny_box_durs);
            if (arguments->l_size > 0)
                x->deny_box_durs = arguments;
            else {
                x->deny_box_durs = NULL;
                llll_free(arguments);
            }
            return; // no need to perform calculations
        } else if (router != NULL && router != _llllobj_sym_Auto && router != _llllobj_sym_auto){
            object_error((t_object *)x, "doesn't understand \"%s\".", router->s_name);
            return;
        } else {
            if (x->separate_mode && inlet == 1) {
                // assign fake IDs, one for each note.
                if (x->noteIDs)
                    llll_free(x->noteIDs);
                x->noteIDs = llll_clone(arguments);
                
                long num = 1;
                llll_funall(x->noteIDs, make_ids_fn, &num, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
            }
            llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, arguments, !x->separate_mode && inlet == 2 ? 6 : inlet);
        }
        x->n_ob.l_rebuild = 1;
    }
    
    if (inlet == 0) {
        // do calculations
        char need_free_graphic = false;
        char need_free_breakpoints = false;
        char need_free_slots = false;
        long i, v;
        t_llll *inlist[7];
        t_llll *measures, *cents, *durations, *velocities, *ties, *extras, *regularityboxes, *noteIDs;
        t_llll *graphic = NULL, *breakpoints = NULL, *slots = NULL;
        t_llllelem *extraselem;
        
        for (i = 0; i < 7; i++)
            inlist[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, true);
        
        measures = inlist[0]; // we'll operate destructively on all these
        cents = inlist[1];
        durations = inlist[2];
        velocities = inlist[3];
        ties = inlist[4];
        extras = inlist[5];
        regularityboxes = inlist[6];
        noteIDs = x->noteIDs ? llll_clone(x->noteIDs) : llll_get();
        
        x->pickup_added_time = -1; // needed negative, meaning: unused;
        
        // setting extras properly
        
        extraselem = extras->l_head;
        if (extraselem && (hatom_gettype(&extraselem->l_hatom) == H_LLLL)
            && (hatom_getllll(&extraselem->l_hatom)->l_size >= 2)
            && (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == H_SYM)
            && (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_next->l_hatom) == H_LLLL)
            && (hatom_getsym(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == _llllobj_sym_graphic)) {
            graphic = hatom_getllll(&extraselem->l_hatom);
            llll_behead(graphic);
            extraselem = extraselem->l_next;
        }
        if (extraselem && (hatom_gettype(&extraselem->l_hatom) == H_LLLL)
            && (hatom_getllll(&extraselem->l_hatom)->l_size >= 2)
            && (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == H_SYM)
            && (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_next->l_hatom) == H_LLLL)
            && (hatom_getsym(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == _llllobj_sym_breakpoints)) {
            breakpoints = hatom_getllll(&extraselem->l_hatom);
            llll_behead(breakpoints);
            extraselem = extraselem->l_next;
        }
        if (extraselem && (hatom_gettype(&extraselem->l_hatom) == H_LLLL)
            && (hatom_getllll(&extraselem->l_hatom)->l_size >= 2)
            && (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == H_SYM)
            && (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_next->l_hatom) == H_LLLL)
            && (hatom_getsym(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == _llllobj_sym_slots)) {
            slots = hatom_getllll(&extraselem->l_hatom);
            llll_behead(slots);
            extraselem = extraselem->l_next;
        }
        
        if (!graphic) {
            graphic = llll_get();
            need_free_graphic = true;
        }
        if (!breakpoints) {
            breakpoints = llll_get();
            need_free_breakpoints = true;
        }
        if (!slots) {
            slots = llll_get();
            need_free_slots = true;
        }
        
        // then, we have a cycle on the different voices
        if (measures && measures->l_head) { // measures have to be defined!!!
            long num_voices, j, num_repetitions;
            t_llll *boxed_graphic, *boxed_breakpoints, *boxed_slots, *boxed_ties, *boxed_velocities, *boxed_cents, *boxed_durations;
            t_llllelem *ties_elem, *meas_elem, *durations_elem, *cents_elem, *velocities_elem, *graphic_elem, *breakpoints_elem, *slots_elem, *regularityboxes_elem, *IDs_elem;
            t_llll *boxed_extras;
            
            char auto_measures = false;
            char collapse = x->quantize_collapsed_voices;	// do we keep the synchronicities? In this case, we collapse all voices and work on a single voice containing all the information.
            
            // first: we set measureinfo properly
            if (measures->l_size == 1 && hatom_gettype(&measures->l_head->l_hatom) == H_SYM) {
                // user has put "auto" measures
                auto_measures = true;
                llll_clear(measures);
            } else if (measures->l_depth <= 3) {
                // use has just put 1 measureinfo for everything, so we wrap it, and loop it later
                llll_wrap_once(&measures);
                llll_wrap_once(&measures);
            } else {
                if (collapse)
                    object_warn((t_object *)x, "Warning: cannot preserve synchronicities when measureinfo is defined voice-wise.");
                collapse = false; // if measureinfo are defined for any voice, we cannot collapse, since boxing might be different
            }
            
            if (regularityboxes->l_depth == 1) { // user has just put 1 regularity boxes list for everything!
                llll_wrap_once(&regularityboxes);
                inlist[6] = regularityboxes; // reassigning pointer
            }
            
            // detecting number of voices
            num_voices = measures->l_size;
            if (cents && ((long)cents->l_size > num_voices)) num_voices = cents->l_size;
            if (durations && ((long)durations->l_size > num_voices)) num_voices = durations->l_size;
            if (velocities && ((long)velocities->l_size > num_voices)) num_voices = velocities->l_size;
            if (ties && ((long)ties->l_size > num_voices)) num_voices = ties->l_size;
            if (graphic && ((long)graphic->l_size > num_voices)) num_voices = graphic->l_size;
            if (breakpoints && ((long)breakpoints->l_size > num_voices)) num_voices = breakpoints->l_size;
            if (slots && ((long)slots->l_size > num_voices)) num_voices = slots->l_size;
            
            num_repetitions = num_voices - measures->l_size;
            if (measures && measures->l_tail)
                for (j = 1; j <= num_repetitions; j++)
                    llll_appendhatom_clone(measures, &measures->l_tail->l_hatom);
            
            num_repetitions = num_voices - regularityboxes->l_size;
            if (regularityboxes && regularityboxes->l_tail)
                for (j = 1; j <= num_repetitions; j++)
                    llll_appendhatom_clone(regularityboxes, &regularityboxes->l_tail->l_hatom);
            
            
            // if the score is empty, collapsing is not needed, or it will cause crashes
            double tot_dur = 0;
            t_llllelem *voice_el;
            for (voice_el = durations->l_head; voice_el; voice_el = voice_el->l_next) {
                if (hatom_gettype(&voice_el->l_hatom) == H_LLLL)
                    tot_dur = MAX(tot_dur, llll_sum_abs_of_double_llll(hatom_getllll(&voice_el->l_hatom)));
            }
            if (tot_dur == 0) {
                collapse = false;
            }
            
            // handling the collapse case
            if (collapse){
                quantize_collapse(&measures, &cents, &durations, &velocities, &ties, &graphic, &breakpoints, &slots, &regularityboxes, &noteIDs, CONST_COLLAPSE_SLOT, num_voices, &need_free_graphic, &need_free_breakpoints, &need_free_slots);
                // now we have just 1 voice; reassigning pointers
                inlist[0] = measures;
                inlist[1] = cents;
                inlist[2] = durations;
                inlist[3] = velocities;
                inlist[4] = ties;
                regularityboxes = inlist[6];
            }
            
            
            boxed_graphic = llll_get();
            boxed_breakpoints = llll_get();
            boxed_slots = llll_get();
            boxed_ties = llll_get();
            boxed_velocities = llll_get();
            boxed_cents = llll_get();
            boxed_durations = llll_get();
            
            for (cents_elem = cents->l_head, velocities_elem = velocities->l_head,
                 IDs_elem = noteIDs->l_head,
                 regularityboxes_elem = regularityboxes->l_head,
                 ties_elem = ties->l_head, meas_elem = measures->l_head, durations_elem = durations->l_head,
                 graphic_elem = graphic->l_head, breakpoints_elem = breakpoints->l_head, slots_elem = slots->l_head, v = 0;
                 cents_elem || velocities_elem || IDs_elem || durations_elem || meas_elem || ties_elem || graphic_elem || breakpoints_elem || slots_elem;
                 cents_elem = (cents_elem) ? cents_elem->l_next : NULL,
                 velocities_elem = (velocities_elem) ? velocities_elem->l_next : NULL,
                 IDs_elem = (IDs_elem) ? IDs_elem->l_next : NULL,
                 ties_elem = (ties_elem) ? ties_elem->l_next : NULL,
                 meas_elem = (meas_elem) ? meas_elem->l_next : NULL,
                 durations_elem = (durations_elem) ? durations_elem->l_next : NULL,
                 graphic_elem = (graphic_elem) ? graphic_elem->l_next : NULL,
                 breakpoints_elem = (breakpoints_elem) ? breakpoints_elem->l_next : NULL,
                 slots_elem = (slots_elem) ? slots_elem->l_next : NULL,
                 regularityboxes_elem = (regularityboxes_elem) ? regularityboxes_elem->l_next : NULL, v++){  //cycle on the VOICES
                
                t_llll *voice_graphic = (graphic_elem && (hatom_gettype(&graphic_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&graphic_elem->l_hatom) : NULL;
                t_llll *voice_breakpoints = (breakpoints_elem && (hatom_gettype(&breakpoints_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&breakpoints_elem->l_hatom) : NULL;
                t_llll *voice_slots = (slots_elem && (hatom_gettype(&slots_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&slots_elem->l_hatom) : NULL;
                t_llll *rough_voice_ties = (ties_elem && (hatom_gettype(&ties_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&ties_elem->l_hatom) : NULL;
                t_llll *voice_velocities = (velocities_elem && (hatom_gettype(&velocities_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&velocities_elem->l_hatom) : NULL;
                t_llll *voice_IDs = (IDs_elem && (hatom_gettype(&IDs_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&IDs_elem->l_hatom) : NULL;
                t_llll *voice_cents = (cents_elem && (hatom_gettype(&cents_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&cents_elem->l_hatom) : NULL;
                t_llll *voice_durations = (durations_elem && (hatom_gettype(&durations_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&durations_elem->l_hatom) : NULL;
                t_llll *voice_measures = (meas_elem && (hatom_gettype(&meas_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&meas_elem->l_hatom) : NULL;
                t_llll *voice_regularityboxes = (regularityboxes_elem && (hatom_gettype(&regularityboxes_elem->l_hatom) == H_LLLL)) ? hatom_getllll(&regularityboxes_elem->l_hatom) : NULL;
                
                // cents, velocities, extras and noteIDs will have to be gathered in a single t_llll *infos list
                t_llll *voice_infos = llll_get(); t_llll *voice_ties = llll_get(); t_llll *voice_ratdurations;
                t_llllelem *voice_cents_elem, *voice_velocities_elem, *voice_IDs_elem, *voice_graphic_elem, *voice_breakpoints_elem, *voice_slots_elem, *voice_ties_elem;
                t_llll *measure_boxes, *voice_tempi, *quant_boxes;
                long num, den, count;
                t_llllelem *measures_elem, *voice_tempi_elem;
                t_llll *boxed_voice_ties = NULL, *boxed_voice_durations = NULL, *boxed_voice_infos = NULL;
                t_llll *unquantized_boxed_voice_ties = NULL, *unquantized_boxed_voice_durations = NULL, *unquantized_boxed_voice_infos = NULL;
                t_llll *boxed_voice_cents, *boxed_voice_velocities, *boxed_voice_IDs, *boxed_voice_graphic, *boxed_voice_breakpoints, *boxed_voice_slots;
                t_llllelem *boxed_infos_elem;
                long how_many_measures_to_append = 0;
                t_llll *voice_ts = llll_get();
                t_llllelem *melem;
                t_llllelem *temp;
                t_llllelem *voice_regularityboxes_elem;
                char completed = 0;
                t_llllelem *boxed_voice_durations_llllelem, *boxed_voice_infos_llllelem, *boxed_voice_ties_llllelem, *quant_boxes_llllelem;
                t_llll *quantized_durations = llll_get(), *quantized_infos = llll_get(), *quantized_ties = llll_get();
                //				char debug1[1000], debug2[1000], debug3[1000];
                
                x->current_voice_being_quantized = v+1;
                
                for (voice_cents_elem = (voice_cents) ? voice_cents->l_head : NULL,
                     voice_velocities_elem = (voice_velocities) ? voice_velocities->l_head : NULL,
                     voice_IDs_elem = (voice_IDs) ? voice_IDs->l_head : NULL,
                     voice_graphic_elem = (voice_graphic) ? voice_graphic->l_head : NULL,
                     voice_breakpoints_elem = (voice_breakpoints) ? voice_breakpoints->l_head : NULL,
                     voice_slots_elem = (voice_slots) ? voice_slots->l_head : NULL,
                     voice_ties_elem = (rough_voice_ties) ? rough_voice_ties->l_head : NULL;
                     voice_cents_elem || voice_velocities_elem || voice_IDs_elem || voice_graphic_elem || voice_breakpoints_elem || voice_slots_elem || voice_ties_elem;
                     voice_cents_elem = (voice_cents_elem) ? voice_cents_elem->l_next : NULL,
                     voice_velocities_elem = (voice_velocities_elem) ? voice_velocities_elem->l_next : NULL,
                     voice_IDs_elem = (voice_IDs_elem) ? voice_IDs_elem->l_next : NULL,
                     voice_graphic_elem = (voice_graphic_elem) ? voice_graphic_elem->l_next : NULL,
                     voice_breakpoints_elem = (voice_breakpoints_elem) ? voice_breakpoints_elem->l_next : NULL,
                     voice_slots_elem = (voice_slots_elem) ? voice_slots_elem->l_next : NULL,
                     voice_ties_elem = (voice_ties_elem) ? voice_ties_elem->l_next : NULL) {
                    
                    t_llll *singleinfo = llll_get();
                    t_llll *thisextras = llll_get();
                    long num_notes = 1;
                    
                    if (voice_cents_elem) {
                        llll_appendhatom_clone(singleinfo, &voice_cents_elem->l_hatom);
                        if ((hatom_gettype(&voice_cents_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_cents_elem->l_hatom)->l_size) > num_notes))
                            num_notes = hatom_getllll(&voice_cents_elem->l_hatom)->l_size;
                    } else
                        llll_appendllll(singleinfo, llll_get());
                    
                    if (voice_velocities_elem) {
                        llll_appendhatom_clone(singleinfo, &voice_velocities_elem->l_hatom);
                        if ((hatom_gettype(&voice_velocities_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_velocities_elem->l_hatom)->l_size) > num_notes))
                            num_notes = hatom_getllll(&voice_velocities_elem->l_hatom)->l_size;
                    } else
                        llll_appendllll(singleinfo, llll_get());
                    
                    if (voice_graphic_elem) {
                        llll_appendhatom_clone(thisextras, &voice_graphic_elem->l_hatom);
                        if ((hatom_gettype(&voice_graphic_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_graphic_elem->l_hatom)->l_size) > num_notes))
                            num_notes = hatom_getllll(&voice_graphic_elem->l_hatom)->l_size;
                    } else
                        llll_appendllll(thisextras, llll_get());
                    if (voice_breakpoints_elem) {
                        llll_appendhatom_clone(thisextras, &voice_breakpoints_elem->l_hatom);
                        if ((hatom_gettype(&voice_breakpoints_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_breakpoints_elem->l_hatom)->l_size) > num_notes))
                            num_notes = hatom_getllll(&voice_breakpoints_elem->l_hatom)->l_size;
                    } else
                        llll_appendllll(thisextras, llll_get());
                    if (voice_slots_elem) {
                        llll_appendhatom_clone(thisextras, &voice_slots_elem->l_hatom);
                        if ((hatom_gettype(&voice_slots_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_slots_elem->l_hatom)->l_size) > num_notes))
                            num_notes = hatom_getllll(&voice_slots_elem->l_hatom)->l_size;
                    } else
                        llll_appendllll(thisextras, llll_get());
                    llll_appendllll(singleinfo, thisextras);
                    
                    if (voice_IDs_elem) {
                        llll_appendhatom_clone(singleinfo, &voice_IDs_elem->l_hatom);
                    } else
                        llll_appendllll(singleinfo, llll_get());
                    
                    llll_appendllll(voice_infos, singleinfo);
                    
                    // refining ties
                    if (voice_ties_elem && (hatom_gettype(&voice_ties_elem->l_hatom) == H_LONG))
                        llll_appendllll(voice_ties, repeat_long(hatom_getlong(&voice_ties_elem->l_hatom), num_notes));
                    else if (voice_ties_elem && (hatom_gettype(&voice_ties_elem->l_hatom) == H_LLLL) && (hatom_getllll(&voice_ties_elem->l_hatom)->l_size > 0)) {
                        t_llll *thisllll = hatom_getllll(&voice_ties_elem->l_hatom);
                        t_llll *inllll = llll_get(); t_llllelem *thiselem;
                        for (i = 0, thiselem = thisllll->l_head; (i < num_notes); i++, thiselem = (thiselem) ? thiselem->l_next : NULL)
                            llll_appendlong(inllll, (thiselem) ? hatom_getlong(&thiselem->l_hatom) : 0);
                        llll_appendllll(voice_ties, inllll);
                    } else
                        llll_appendllll(voice_ties, repeat_long(0, num_notes));
                }
                
                if (auto_measures && x->marker_info) {
                    // measures come from the special markers
                    double global_delta_onset = 0, prev_onset = -1;
                    t_llllelem *elem;
                    
                    measure_boxes = llll_get();
                    quant_boxes = llll_get();
                    voice_tempi = llll_get();  // unneeded for the automatic case! boxing is already done marker-wise
                    
                    // delete all double-markers (marker on the same points)
                    elem = x->marker_info->l_head;
                    e_marker_roles prev_role = k_MARKER_ROLE_NONE;
                    while (elem){
                        t_llllelem *next = elem->l_next;
                        double onset = get_marker_onset_from_llllelem(elem);
                        e_marker_roles role = get_marker_role_from_llllelem(elem);
                        if (prev_onset > 0 && fabs(onset - prev_onset) < CONST_THRESHOLD_FOR_DELETING_BARLINE_OR_DIVISION_MARKERS_AT_SAME_POINT &&
                            (role == k_MARKER_ROLE_TIME_SIGNATURE || role == k_MARKER_ROLE_MEASURE_BARLINE || role == k_MARKER_ROLE_MEASURE_DIVISION)) {
                            if (prev_role == k_MARKER_ROLE_MEASURE_BARLINE && role == k_MARKER_ROLE_TIME_SIGNATURE && elem->l_prev)
                                llll_destroyelem(elem->l_prev);
                            else
                                llll_destroyelem(elem);
                        }
                        elem = next;
                        prev_onset = onset;
                        prev_role = role;
                    }
                    
                    // if there's just tempo markers, we add a barline marker coinciding with the tempo marker (otherwise the markers_to_measureinfo_and_rat_durations will not work)
                    char no_barline_markers = true;
                    t_llllelem *firsttempo = NULL;
                    double first_tempo_marker_onset = 0;
                    for (elem = x->marker_info->l_head; elem; elem = elem->l_next){
                        e_marker_roles role = get_marker_role_from_llllelem(elem);
                        if (role == k_MARKER_ROLE_MEASURE_BARLINE || role == k_MARKER_ROLE_TIME_SIGNATURE) {
                            no_barline_markers = false;
                            break;
                        } else if (!firsttempo && role == k_MARKER_ROLE_TEMPO) {
                            first_tempo_marker_onset = get_marker_onset_from_llllelem(elem);
                            firsttempo = elem;
                        }
                    }
                    
                    if (no_barline_markers) {
                        t_llll *fake_barline_marker = llll_get(); // must contain: onset name role content
                        llll_appenddouble(fake_barline_marker, first_tempo_marker_onset);
                        llll_appendsym(fake_barline_marker, _llllobj_sym_barline);
                        llll_appendsym(fake_barline_marker, _llllobj_sym_barline);
                        llll_appendllll(fake_barline_marker, llll_get());
                        if (!firsttempo)
                            llll_appendllll(x->marker_info, fake_barline_marker);
                        else
                            llll_insertllll_after(fake_barline_marker, firsttempo);
                    }
                    
                    
#ifdef BACH_QUANTIZE_DEBUG
                    dev_post("DEBUG MARKERS");
                    for (elem = x->marker_info->l_head; elem; elem = elem->l_next) {
                        e_marker_roles role = get_marker_role_from_llllelem(elem);
                        if (role == k_MARKER_ROLE_TEMPO)
                            dev_post("onset: %.2f, role: tempo", get_marker_onset_from_llllelem(elem));
                        else if (role == k_MARKER_ROLE_TIME_SIGNATURE)
                            dev_post("onset: %.2f, role: timesig", get_marker_onset_from_llllelem(elem));
                        else if (role == k_MARKER_ROLE_MEASURE_BARLINE)
                            dev_post("onset: %.2f, role: barline", get_marker_onset_from_llllelem(elem));
                    }
#endif
                    
                    completed = markers_to_measureinfo_and_rat_durations(x, x->marker_info, voice_durations, voice_infos, voice_ties, measure_boxes, voice_ts, quant_boxes, &global_delta_onset, &unquantized_boxed_voice_durations, &unquantized_boxed_voice_infos, &unquantized_boxed_voice_ties);
                    x->pickup_added_time = global_delta_onset;
                    
                    
                    llll_appendllll(measures, voice_ts);
                    
                } else {
                    // we create the measure-boxes, via the <measures> llll.
                    measure_boxes = llll_get();
                    num = 4; den = 4; // default time signature is 4/4
                    quant_boxes = llll_get();
                    voice_tempi = llll_get();
                    count = 0;
                    measures_elem = voice_measures ? voice_measures->l_head : NULL;
                    voice_regularityboxes_elem = voice_regularityboxes ? voice_regularityboxes->l_head : NULL;
                    while (measures_elem) {
                        long loop_for_n_times = 1, j;
                        t_llll *ts = NULL;
                        if (measures_elem && (hatom_gettype(&measures_elem->l_hatom) == H_LLLL)) {
                            t_llll *measurellll = hatom_getllll(&measures_elem->l_hatom);
                            if (measurellll && (measurellll->l_size > 0)) {
                                
                                if (hatom_gettype(&measurellll->l_head->l_hatom) == H_LONG) {
                                    loop_for_n_times = hatom_getlong(&measurellll->l_head->l_hatom);
                                    if (measurellll->l_size > 1 && hatom_gettype(&measurellll->l_head->l_next->l_hatom) == H_LLLL) {
                                        ts = hatom_getllll(&measurellll->l_head->l_next->l_hatom);
                                        if (measurellll->l_size > 2 && hatom_gettype(&measurellll->l_head->l_next->l_next->l_hatom) == H_LLLL){
                                            t_llll *whole_tempi = hatom_getllll(&measurellll->l_head->l_next->l_next->l_hatom);
                                            if (whole_tempi->l_depth > 1) {
                                                t_llllelem *thiselem2 = whole_tempi->l_head;
                                                long j;
                                                for (j = 0; j < loop_for_n_times; j++) {
                                                    for (thiselem2 = whole_tempi->l_head; thiselem2; thiselem2 = thiselem2->l_next) {
                                                        if (hatom_gettype(&thiselem2->l_hatom) == H_LLLL) {
                                                            t_tempo *thistempo = build_tempo_from_llll(hatom_getllll(&thiselem2->l_hatom), x->tempo_approx_digits);
                                                            if (thistempo) {
                                                                thistempo->hack_measure_number = count;
                                                                llll_appendobj(voice_tempi, thistempo);
                                                            }
                                                        }
                                                    }
                                                }
                                            } else { // just one tempo
                                                t_tempo *thistempo = build_tempo_from_llll(whole_tempi, x->tempo_approx_digits);
                                                if (thistempo) {
                                                    thistempo->hack_measure_number = count;
                                                    llll_appendobj(voice_tempi, thistempo);
                                                }
                                            }
                                        }
                                    }
                                    count += loop_for_n_times;
                                } else if (hatom_gettype(&measurellll->l_head->l_hatom) == H_LLLL) {
                                    ts = hatom_getllll(&measurellll->l_head->l_hatom);
                                    if (measurellll->l_size > 1 && hatom_gettype(&measurellll->l_head->l_next->l_hatom) == H_LLLL){
                                        t_llll *whole_tempi = hatom_getllll(&measurellll->l_head->l_next->l_hatom);
                                        if (whole_tempi->l_depth > 1) {
                                            t_llllelem *thiselem2 = whole_tempi->l_head;
                                            for (thiselem2 = whole_tempi->l_head; thiselem2; thiselem2 = thiselem2->l_next) {
                                                if (hatom_gettype(&thiselem2->l_hatom) == H_LLLL) {
                                                    t_tempo *thistempo = build_tempo_from_llll(hatom_getllll(&thiselem2->l_hatom), x->tempo_approx_digits);
                                                    if (thistempo) {
                                                        thistempo->hack_measure_number = count;
                                                        llll_appendobj(voice_tempi, thistempo);
                                                    }
                                                }
                                            }
                                        } else if (whole_tempi->l_size >= 1) { // just one tempo
                                            t_tempo *thistempo = build_tempo_from_llll(whole_tempi, x->tempo_approx_digits);
                                            if (thistempo) {
                                                thistempo->hack_measure_number = count;
                                                llll_appendobj(voice_tempi, thistempo);
                                            }
                                        }
                                    }
                                    count++;
                                }
                                
                                if (ts && (ts->l_size > 0) && ts->l_head) {
                                    if (hatom_gettype(&ts->l_head->l_hatom) == H_LLLL) { // compound time signature, e.g. ((3 5) 8)
                                        num = llll_sum_abs_of_rat_llll(hatom_getllll(&ts->l_head->l_hatom)).r_num;
                                    } else if (hatom_gettype(&ts->l_head->l_hatom) == H_LONG) {
                                        num = hatom_getlong(&ts->l_head->l_hatom);
                                    }
                                }
                                if (ts && (ts->l_size > 1) && ts->l_head && ts->l_head->l_next && (hatom_gettype(&ts->l_head->l_next->l_hatom) == H_LONG)) {
                                    den = hatom_getlong(&ts->l_head->l_next->l_hatom);
                                }
                                
                            }
                            if (num <= 0) num = 4;
                            if (den <= 0) den = 4;
                        }
                        for (j = 0; j < loop_for_n_times; j++) {
                            t_rational this_measure_sym_duration = genrat(num, den);
                            t_llll *this_ts_llll = llll_get();
                            llll_appendlong(this_ts_llll, num);
                            llll_appendlong(this_ts_llll, den);
                            llll_appendllll(voice_ts, this_ts_llll);
                            
                            llll_appendrat(measure_boxes, this_measure_sym_duration);
                        }
                        if (measures_elem)
                            measures_elem = measures_elem->l_next;
                    }
                    
                    voice_ratdurations = ms_to_rat_durations(measure_boxes, voice_tempi, voice_durations, &how_many_measures_to_append, CONST_RAT_SINGLE_DEN, true); // approximated
                    
                    // appending boxes and ts
                    for (j = 0; j < how_many_measures_to_append && measure_boxes->l_tail; j++) {
                        llll_appendhatom_clone(measure_boxes, &measure_boxes->l_tail->l_hatom);
                        llll_appendhatom_clone(voice_ts, &voice_ts->l_tail->l_hatom);
                    }
                    
                    if (x->verbose >= 2) {
                        char *voice_durations_buf = NULL;
                        char *voice_ratdurations_buf = NULL;
                        object_post((t_object *) x, "****** Quantizing voice No.%ld ******", v);
                        object_post((t_object *) x, "Incoming milliseconds: ");
                        llll_to_text_buf(voice_durations, &voice_durations_buf, 0, 4, 0, 0, 0, NULL);
                        object_post((t_object *) x, "  %s", voice_durations_buf);
                        object_post((t_object *) x, "Rational durations: ");
                        llll_to_text_buf(voice_ratdurations, &voice_ratdurations_buf, 0, 4, 0, 0, 0, NULL);
                        object_post((t_object *) x, "  %s", voice_ratdurations_buf);
                        bach_freeptr(voice_durations_buf);
                        bach_freeptr(voice_ratdurations_buf);
                    }
                    
                    /*				char debug[1000];
                     llll_to_char_array(voice_durations, debug, 999); //debug + 60  debug + 80
                     llll_to_char_array(voice_ratdurations, debug, 999); //debug + 60  debug + 80
                     llll_to_char_array(measure_boxes, debug, 999); //debug + 60  debug + 80*/
                    
                    // creating quantization boxes
                    for (melem = voice_ts->l_head, voice_regularityboxes_elem = voice_regularityboxes ? voice_regularityboxes->l_head : NULL;
                         melem;
                         melem = melem->l_next) {
                        t_llll *this_ts = hatom_getllll(&melem->l_hatom);
                        t_rational this_measure_sym_duration = genrat(hatom_getlong(&this_ts->l_head->l_hatom), hatom_getlong(&this_ts->l_tail->l_hatom));
                        t_llll *these_quant_boxes;
                        if (voice_regularityboxes_elem && (hatom_gettype(&voice_regularityboxes_elem->l_hatom) == H_RAT || hatom_gettype(&voice_regularityboxes_elem->l_hatom) == H_LONG)) {
                            these_quant_boxes = repeat_rat_until_tot_duration(hatom_getrational(&voice_regularityboxes_elem->l_hatom), this_measure_sym_duration); // explicit boxing
                        } else if (voice_regularityboxes_elem && hatom_gettype(&voice_regularityboxes_elem->l_hatom) == H_LLLL && hatom_getllll(&voice_regularityboxes_elem->l_hatom)->l_size > 0) {
                            these_quant_boxes = llll_clone(hatom_getllll(&voice_regularityboxes_elem->l_hatom));
                            force_plain_rat_llll_to_have_a_given_abs_sum(these_quant_boxes, this_measure_sym_duration); // we check that the quant boxes are correct!
                        } else {
                            t_timesignature ts = get_timesignature_from_llll((t_object *) x, this_ts);
                            these_quant_boxes = ts_to_beaming_boxes(NULL, &ts, NULL, NULL); // automatic boxing
                        }
                        //					llll_to_char_array(these_quant_boxes, debug1, 999);
                        llll_appendllll(quant_boxes, these_quant_boxes);
                        if (voice_regularityboxes_elem && voice_regularityboxes_elem->l_next)
                            voice_regularityboxes_elem = voice_regularityboxes_elem->l_next;
                    }
                    
                    
                    /*				if (voice_durations) llll_to_char_array(voice_durations, debug1, 999);
                     if (voice_ratdurations) llll_to_char_array(voice_ratdurations, debug2, 999);
                     if (quant_boxes) llll_to_char_array(quant_boxes, debug3, 999);*/
                    
                    // eliminating all tempi: we don't need them any more
                    for (voice_tempi_elem = voice_tempi->l_head; voice_tempi_elem; voice_tempi_elem = voice_tempi_elem->l_next)
                        if (hatom_gettype(&voice_tempi_elem->l_hatom) == H_OBJ && hatom_getobj(&voice_tempi_elem->l_hatom))
                            free_tempo(NULL, (t_tempo *) hatom_getobj(&voice_tempi_elem->l_hatom));
                    voice_tempi_elem = voice_tempi->l_head;
                    while (voice_tempi_elem) {
                        temp = voice_tempi_elem->l_next;
                        llll_destroyelem(voice_tempi_elem);
                        voice_tempi_elem = temp;
                    }
                    
                    llll_flatten(quant_boxes, 1, 0);
                    approximate_for_too_high_rationals_fixed_den(voice_ratdurations, long2rat(-1), CONST_RAT_SINGLE_DEN);
                    
                    //				char debug1[1000], debug2[1000], debug3[1000], debug4[1000];
                    //				llll_to_char_array(voice_ratdurations, debug1, 999); //debug1 + 70
                    
                    // obtain split rhythm
                    completed = split_rhythm_to_boxes(voice_ratdurations, voice_infos, voice_ties, quant_boxes,
                                                      &unquantized_boxed_voice_durations, &unquantized_boxed_voice_infos, &unquantized_boxed_voice_ties,
                                                      true, QUANTIZE_MARK_TIED_INFOS, true);
                    
                    llll_free(voice_ratdurations);
                    llll_free(voice_ts);
                }
                
                llll_free(voice_tempi);
                
                // *****************************************
                // REAL QUANTIZATION PART
                // *****************************************
                
                
                if (x->verbose >= 2) {
                    t_llllelem *elem, *ielem;
                    object_post((t_object *) x, "Boxed rational durations: ");
                    for (elem = unquantized_boxed_voice_durations ? unquantized_boxed_voice_durations->l_head : NULL,
                         ielem = unquantized_boxed_voice_infos ? unquantized_boxed_voice_infos->l_head : NULL; elem;
                         elem = elem->l_next, ielem = ielem ? ielem->l_next : NULL) {
                        if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                            char *unquantized_boxed_voice_durations_buf = NULL;
                            if (QUANTIZE_MARK_TIED_INFOS && ielem && hatom_gettype(&ielem->l_hatom) == H_LLLL) {
                                t_llll *ties = llll_get();
                                t_llllelem *temp;
                                t_llll *lls[2];
                                for (temp = hatom_getllll(&ielem->l_hatom)->l_head; temp; temp = temp->l_next)
                                    llll_appendsym(ties, temp->l_thing.w_obj == WHITENULL ? gensym("_") : gensym(""));
                                lls[0] = ties;
                                lls[1] = llll_clone(hatom_getllll(&elem->l_hatom));
                                t_llll *laced = llll_lace(lls, 2, 0);
                                llll_to_text_buf(laced, &unquantized_boxed_voice_durations_buf, 0, 1, 0, 0, 0, NULL);
                                llll_free(laced);
                            } else {
                                llll_to_text_buf(hatom_getllll(&elem->l_hatom), &unquantized_boxed_voice_durations_buf, 0, 1, 0, 0, 0, NULL);
                            }
                            object_post((t_object *)x, " %s", unquantized_boxed_voice_durations_buf);
                            bach_freeptr(unquantized_boxed_voice_durations_buf);
                        }
                    }
                }
                
                
                // to do: handle the Stream mode and keep the info only of the last box...
                
                // DEBUG:
                /*				if (unquantized_boxed_voice_infos->l_size > 1) {
                 t_llllelem *debug_elem1 = llll_getindex(llll_getindex(unquantized_boxed_voice_infos, 1, I_NON_NEGATIVE)->l_hatom.h_w.w_llll, 1, I_NON_NEGATIVE);
                 t_llllelem *debug_elem2 = llll_getindex(llll_getindex(unquantized_boxed_voice_infos, 1, I_NON_NEGATIVE)->l_hatom.h_w.w_llll, 2, I_NON_NEGATIVE);
                 t_llllelem *debug_elem3 = llll_getindex(llll_getindex(unquantized_boxed_voice_infos, 1, I_NON_NEGATIVE)->l_hatom.h_w.w_llll, 3, I_NON_NEGATIVE);
                 llll_to_char_array(hatom_getllll(&debug_elem1->l_hatom), debug1, 999);
                 llll_to_char_array(hatom_getllll(&debug_elem2->l_hatom), debug2, 999);
                 llll_to_char_array(hatom_getllll(&debug_elem3->l_hatom), debug3, 999);
                 llll_to_char_array(unquantized_boxed_voice_durations, debug4, 999);
                 //				post("%s", debug1);
                 }
                 */
/*
                char debug1[1000], debug2[1000], debug3[1000];
                llll_to_char_array(unquantized_boxed_voice_durations, debug1, 999); //debug1 + 100
                llll_to_char_array(unquantized_boxed_voice_infos, debug2, 999);  //debug2 + 440
                llll_to_char_array(unquantized_boxed_voice_ties, debug3, 999); // debug3 + 100
*/
                long c = 1;
                for (boxed_voice_durations_llllelem = unquantized_boxed_voice_durations->l_head,
                     boxed_voice_infos_llllelem = unquantized_boxed_voice_infos->l_head,
                     boxed_voice_ties_llllelem = unquantized_boxed_voice_ties->l_head,
                     quant_boxes_llllelem = quant_boxes->l_head;
                     boxed_voice_durations_llllelem && boxed_voice_infos_llllelem && boxed_voice_ties_llllelem && quant_boxes_llllelem;
                     boxed_voice_durations_llllelem = boxed_voice_durations_llllelem ? boxed_voice_durations_llllelem->l_next : NULL,
                     boxed_voice_infos_llllelem = boxed_voice_infos_llllelem ? boxed_voice_infos_llllelem->l_next : NULL,
                     boxed_voice_ties_llllelem = boxed_voice_ties_llllelem ? boxed_voice_ties_llllelem->l_next : NULL,
                     quant_boxes_llllelem = quant_boxes_llllelem->l_next, c++) {
                    
                    t_llll *quantized_box_durations, *quantized_box_infos, *quantized_box_ties;
                    
                    /*
                    					char debug1[1000], debug2[1000], debug3[1000];
                     llll_to_char_array(hatom_getllll(&boxed_voice_durations_llllelem->l_hatom), debug1, 999);
                     llll_to_char_array(hatom_getllll(&boxed_voice_infos_llllelem->l_hatom), debug2, 999);
                     llll_to_char_array(hatom_getllll(&boxed_voice_ties_llllelem->l_hatom), debug3, 999);
                    */
                    
                    // we quantize this single box
                    quantize_box(x, hatom_getrational(&quant_boxes_llllelem->l_hatom),
                                 hatom_getllll(&boxed_voice_durations_llllelem->l_hatom), hatom_getllll(&boxed_voice_infos_llllelem->l_hatom), hatom_getllll(&boxed_voice_ties_llllelem->l_hatom),
                                 &quantized_box_durations, &quantized_box_infos, &quantized_box_ties,
                                 (quantized_durations->l_tail) ? hatom_getllll(&quantized_durations->l_tail->l_hatom)->l_tail : NULL,
                                 (quantized_infos->l_tail) ? hatom_getllll(&quantized_infos->l_tail->l_hatom)->l_tail : NULL,
                                 (quantized_ties->l_tail) ? hatom_getllll(&quantized_ties->l_tail->l_hatom)->l_tail : NULL,
                                 (boxed_voice_durations_llllelem->l_next) ? hatom_getllll(&boxed_voice_durations_llllelem->l_next->l_hatom)->l_head : NULL,
                                 (boxed_voice_infos_llllelem->l_next) ? hatom_getllll(&boxed_voice_infos_llllelem->l_next->l_hatom)->l_head : NULL,
                                 (boxed_voice_ties_llllelem->l_next) ? hatom_getllll(&boxed_voice_ties_llllelem->l_next->l_hatom)->l_head : NULL);
                    
                    if (quantized_box_durations && quantized_box_durations->l_size > 0)
                        llll_appendllll(quantized_durations, quantized_box_durations);
                    else
                        llll_appendllll(quantized_durations, get_nilnil());
                    
                    if (quantized_box_infos && quantized_box_infos->l_size > 0)
                        llll_appendllll(quantized_infos, quantized_box_infos);
                    else
                        llll_appendllll(quantized_infos, get_nilnil());
                    
                    if (quantized_box_ties && quantized_box_ties->l_size > 0)
                        llll_appendllll(quantized_ties, quantized_box_ties);
                    else
                        llll_appendllll(quantized_ties, get_nilnil());
                    
                    /*
                    llll_to_char_array(quantized_box_durations, debug1, 999);  //debug2 + 430
                    llll_to_char_array(quantized_box_infos, debug2, 999);  //debug2 + 430
                    llll_to_char_array(quantized_box_ties, debug3, 999);  //debug2 + 430
                    
                    llll_to_char_array(quantized_box_ties, debug3, 999);  //debug2 + 430
                     */

                }
                
                //				llll_to_char_array(quantized_infos, debug2, 999);  //debug2 + 430
                
                //                llll_print(quantized_infos);
                
                llll_flatten(quantized_durations, 1, 0);
                llll_flatten(quantized_infos, 1, 0);
                llll_flatten(quantized_ties, 1, 0);
                
                llll_free(unquantized_boxed_voice_durations);
                llll_free(unquantized_boxed_voice_infos);
                llll_free(unquantized_boxed_voice_ties);
                
                if (x->verbose >= 2) {
                    object_post((t_object *) x, "=============================");
                    object_post((t_object *) x, "Quantized rational durations: ");
                    if (quantized_durations) {
                        char *quantized_boxed_voice_durations_buf = NULL;
                        if (QUANTIZE_MARK_TIED_INFOS && quantized_infos) {
                            t_llll *ties = llll_get();
                            t_llllelem *temp;
                            t_llll *lls[2];
                            for (temp = quantized_infos->l_head; temp; temp = temp->l_next)
                                llll_appendsym(ties, temp->l_thing.w_obj == WHITENULL ? gensym("_") : gensym(""));
                            lls[0] = ties;
                            lls[1] = llll_clone(quantized_durations);
                            t_llll *laced = llll_lace(lls, 2, 0);
                            llll_to_text_buf(laced, &quantized_boxed_voice_durations_buf, 0, 1, 0, 0, 0, NULL);
                            llll_free(laced);
                        } else {
                            llll_to_text_buf(quantized_durations, &quantized_boxed_voice_durations_buf, 0, 1, 0, 0, 0, NULL);
                        }
                        object_post((t_object *)x, " %s", quantized_boxed_voice_durations_buf);
                        bach_freeptr(quantized_boxed_voice_durations_buf);
                    }
                }
                
                // clip ties from 0 and 1, i.e. remove IDs
                llll_funall(quantized_ties, (fun_fn)make_01_fn, NULL, 0, -1); //CLIP BETWEEN 0 and 1, i.e. remove IDs

                // *****************************************
                // BEATBOX-LIKE PART: we construct the score
                // *****************************************
                
                /*				llll_to_char_array(llll_getindex(quantized_infos, 10, I_NONNEGATIVE)->l_hatom.h_w.w_llll, debug2, 999);  //debug2 + 400
                 llll_to_char_array(quantized_durations, debug1, 999); //debug1 + 50
                 llll_to_char_array(measure_boxes, debug1, 999); //debug1 + 50 */
                
                split_rhythm_to_boxes(quantized_durations, quantized_infos, quantized_ties, measure_boxes,
                                      &boxed_voice_durations, &boxed_voice_infos, &boxed_voice_ties, false, QUANTIZE_MARK_TIED_INFOS, true);
                
                /*				llll_to_char_array(boxed_voice_durations, debug1, 999); //debug1 + 80
                 llll_to_char_array(llll_getindex(boxed_voice_infos, 2, I_NONNEGATIVE)->l_hatom.h_w.w_llll, debug2, 999);  //debug2 + 400 */
                
                if (x->verbose >= 2) {
                    t_llllelem *elem, *ielem;
                    object_post((t_object *) x, "======================== ");
                    object_post((t_object *) x, "Measure-boxed durations: ");
                    for (elem = boxed_voice_durations ? boxed_voice_durations->l_head : NULL,
                         ielem = boxed_voice_infos ? boxed_voice_infos->l_head : NULL; elem;
                         elem = elem->l_next, ielem = ielem ? ielem->l_next : NULL) {
                        if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                            char *boxed_voice_durations_buf = NULL;
                            if (QUANTIZE_MARK_TIED_INFOS && ielem && hatom_gettype(&ielem->l_hatom) == H_LLLL) {
                                t_llll *ties = llll_get();
                                t_llllelem *temp;
                                t_llll *lls[2];
                                for (temp = hatom_getllll(&ielem->l_hatom)->l_head; temp; temp = temp->l_next)
                                    llll_appendsym(ties, temp->l_thing.w_obj == WHITENULL ? gensym("_") : gensym(""));
                                lls[0] = ties;
                                lls[1] = llll_clone(hatom_getllll(&elem->l_hatom));
                                t_llll *laced = llll_lace(lls, 2, 0);
                                llll_to_text_buf(laced, &boxed_voice_durations_buf, 0, 1, 0, 0, 0, NULL);
                                llll_free(laced);
                            } else {
                                llll_to_text_buf(hatom_getllll(&elem->l_hatom), &boxed_voice_durations_buf, 0, 1, 0, 0, 0, NULL);
                            }
                            object_post((t_object *)x, " %s", boxed_voice_durations_buf);
                            bach_freeptr(boxed_voice_durations_buf);
                        }
                    }
                }
                
                llll_free(quantized_durations);
                llll_free(quantized_infos);
                llll_free(quantized_ties);
                llll_free(quant_boxes);
                
                // now we split the boxed_infos into:
                boxed_voice_cents = llll_get(); boxed_voice_velocities = llll_get();
                boxed_voice_graphic = llll_get(); boxed_voice_breakpoints = llll_get(); boxed_voice_slots = llll_get();
                for (boxed_infos_elem = boxed_voice_infos->l_head; boxed_infos_elem; boxed_infos_elem = boxed_infos_elem->l_next) {
                    // this is a cycle on the boxes. For each box, we gotta create a box in each of our boxed_cents/vel/extras lllls
                    t_llll *this_box_cents = llll_get(); t_llll *this_box_velocities = llll_get();
                    t_llll *this_box_graphic = llll_get(); t_llll *this_box_breakpoints = llll_get(); t_llll *this_box_slots = llll_get();
                    
                    t_llll *this_box_llll = (boxed_infos_elem) ? hatom_getllll(&boxed_infos_elem->l_hatom) : NULL;
                    t_llllelem *this_box_llllelem;
                    for (this_box_llllelem = (this_box_llll) ? this_box_llll->l_head : NULL; this_box_llllelem; this_box_llllelem = this_box_llllelem->l_next) {
                        char marked_as_newly_tied_from = (QUANTIZE_MARK_TIED_INFOS && this_box_llllelem->l_thing.w_obj == WHITENULL ? true : false);
                        t_llll *singleinfo_llll = hatom_getllll(&this_box_llllelem->l_hatom);
                        if (singleinfo_llll->l_head)
                            llll_appendhatom_clone(this_box_cents, &singleinfo_llll->l_head->l_hatom);
                        if (singleinfo_llll->l_head && singleinfo_llll->l_head->l_next)
                            llll_appendhatom_clone(this_box_velocities, &singleinfo_llll->l_head->l_next->l_hatom);
                        if (singleinfo_llll->l_head && singleinfo_llll->l_head->l_next && singleinfo_llll->l_head->l_next->l_next) {
                            if (hatom_gettype(&singleinfo_llll->l_head->l_next->l_next->l_hatom) == H_LLLL) {
                                t_llll *theseextras = hatom_getllll(&singleinfo_llll->l_head->l_next->l_next->l_hatom);
                                if (theseextras->l_head)
                                    llll_appendhatom_clone(this_box_graphic, &theseextras->l_head->l_hatom);
                                if (theseextras->l_head && theseextras->l_head->l_next)
                                    llll_appendhatom_clone(this_box_breakpoints, &theseextras->l_head->l_next->l_hatom);
                                if (theseextras->l_head && theseextras->l_head->l_next && theseextras->l_head->l_next->l_next) {
                                    if (QUANTIZE_MARK_TIED_INFOS)
                                        llll_appendhatom_clone_handle_slots(x, this_box_slots, &theseextras->l_head->l_next->l_next->l_hatom, 0, WHITENULL_llll, marked_as_newly_tied_from);
                                    else
                                        llll_appendhatom_clone(this_box_slots, &theseextras->l_head->l_next->l_next->l_hatom);
                                }
                            }
                        }
                    }
                    
                    llll_appendllll(boxed_voice_cents, this_box_cents);
                    llll_appendllll(boxed_voice_velocities, this_box_velocities);
                    llll_appendllll(boxed_voice_graphic, this_box_graphic);
                    llll_appendllll(boxed_voice_breakpoints, this_box_breakpoints);
                    llll_appendllll(boxed_voice_slots, this_box_slots);
                }
                
                // changing ties which were assigned to the whole chord, such as 0, to ties assigned to each note, such as (0 0 0 0)
                t_llllelem *e1, *e2, *f1, *f2;
                for (e1 = boxed_voice_cents->l_head, e2 = boxed_voice_ties->l_head; e1 && e2; e1 = e1->l_next, e2 = e2->l_next) {
                    if (hatom_gettype(&e1->l_hatom) == H_LLLL && hatom_gettype(&e2->l_hatom) == H_LLLL) {
                        for (f1 = hatom_getllll(&e1->l_hatom)->l_head, f2 = hatom_getllll(&e2->l_hatom)->l_head; f2; f1 = f1 ? f1->l_next : NULL, f2 = f2->l_next) {
                            if (!f1 && hatom_gettype(&f2->l_hatom) == H_LONG) {
                                hatom_change_to_llll(&f2->l_hatom, llll_get());
                            } else if (f1 && hatom_gettype(&f1->l_hatom) == H_LLLL && hatom_gettype(&f2->l_hatom) == H_LONG) {
                                t_llll *ll = repeat_long(hatom_getlong(&f2->l_hatom), hatom_getllll(&f1->l_hatom)->l_size);
                                hatom_change_to_llll(&f2->l_hatom, ll);
                            }
                        }
                    }
                }
                
                // lists which we don't need any more (we don't free the lists who have been put in the gunload_llll!)
                llll_free(measure_boxes);
                if (boxed_voice_infos)
                    llll_free(boxed_voice_infos); // have been cloned-split into cents/vel/extras.
                llll_free(voice_infos);
                llll_free(voice_ties);
                
                
                // we append the boxed_voice_things to the boxed_things
                llll_appendllll(boxed_graphic, boxed_voice_graphic);
                llll_appendllll(boxed_breakpoints, boxed_voice_breakpoints);
                llll_appendllll(boxed_slots, boxed_voice_slots);
                llll_appendllll(boxed_ties, boxed_voice_ties);
                llll_appendllll(boxed_velocities, boxed_voice_velocities);
                llll_appendllll(boxed_cents, boxed_voice_cents);
                llll_appendllll(boxed_durations, boxed_voice_durations);
                
            }
            
            
            // setting new extras
            boxed_extras = llll_get();
            llll_prependsym(boxed_graphic, _llllobj_sym_graphic);
            llll_prependsym(boxed_breakpoints, _llllobj_sym_breakpoints);
            llll_prependsym(boxed_slots, _llllobj_sym_slots);
            llll_appendllll(boxed_extras, boxed_graphic);
            llll_appendllll(boxed_extras, boxed_breakpoints);
            llll_appendllll(boxed_extras, boxed_slots);
            
            /*			char debug1[1000], debug2[1000], debug3[1000], debug4[1000], debug5[1000], debug6[1000];
             llll_to_char_array(boxed_extras, debug1, 999);
             llll_to_char_array(boxed_ties, debug2, 999); //debug2 + 60
             llll_to_char_array(boxed_velocities, debug3, 999);
             llll_to_char_array(boxed_durations, debug4, 999); //debug2 + 60
             llll_to_char_array(boxed_cents, debug5, 999);
             llll_to_char_array(measures, debug6, 999);*/
            /*			char debug1[1000], debug2[1000], debug3[1000];
             llll_to_char_array(boxed_durations, debug1, 999); //debug1 + 80
             llll_to_char_array(boxed_cents, debug2, 999);
             llll_to_char_array(measures, debug3, 999);*/
            
            
            if (x->separate_mode) {
                if (collapse) {
                    // copying measureinfo properly for each voice
                    while (measures->l_head && (long)measures->l_size < num_voices)
                        llll_appendhatom_clone(measures, &measures->l_head->l_hatom);
                    
                    t_llll *gathered = quantize_uncollapse(measures, boxed_cents, boxed_durations, boxed_velocities, boxed_ties, boxed_extras, num_voices, CONST_COLLAPSE_SLOT);
                    // free stuff
                    llll_free(measures);
                    llll_free(boxed_cents);
                    llll_free(boxed_durations);
                    llll_free(boxed_velocities);
                    llll_free(boxed_ties);
                    llll_free(boxed_extras);
                    score_gathered2separate_syntax(gathered, &measures, &boxed_cents, &boxed_durations, &boxed_velocities, &boxed_ties, &boxed_extras, true);
                }
                llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_extras, 6);
                llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_ties, 5);
                llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_velocities, 4);
                llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_durations, 3);
                llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_cents, 2);
                llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, measures, 1);
            } else {
                t_llll *gathered;
                if (collapse) {
                    gathered = quantize_uncollapse(measures, boxed_cents, boxed_durations, boxed_velocities, boxed_ties, boxed_extras, num_voices, CONST_COLLAPSE_SLOT);
                } else {
                    gathered = score_separate2gathered_syntax(measures, boxed_cents, boxed_durations, boxed_velocities, boxed_ties, boxed_extras);
                }
                llll_prependsym(gathered, _llllobj_sym_score);
                
                // free stuff (ARE WE SURE??? – we should...)
                llll_free(measures);
                llll_free(boxed_cents);
                llll_free(boxed_durations);
                llll_free(boxed_velocities);
                llll_free(boxed_ties);
                llll_free(boxed_extras);
                
                if (x->header_info->l_size > 0) {
                    llll_prependllll_clone(gathered, x->header_info, NULL);
                    llll_splatter(gathered->l_head, LLLL_FREETHING_DONT);
                }
                llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, gathered, 0);
            }
        } else {
            llll_free(measures); // if measures were empty, we free the duplicate copy (we don't gunload it)
        }
        
        if (need_free_graphic) llll_free(graphic);
        if (need_free_breakpoints) llll_free(breakpoints);
        if (need_free_slots) llll_free(slots);
        
        // lists which we don't need any more (we don't free the lists who have been put in the gunload_llll!)
        for (i = 1; i < 7; i++) // we don't free measures (only if they were empty, otherwise they're gunloaded
            llll_free(inlist[i]);
        
        if (noteIDs)
            llll_free(noteIDs);
        
        x->n_ob.l_rebuild = 0;
        quantize_bang(x);
    }
}

// slot_num is 1-based!
// return value is 1 based!
long retrieve_note_voice_from_gathered_syntax(t_llll *note, long note_voice_slot_num, char also_destroy_voice_slot)
{
    t_llllelem *el, *slot_el;
    for (el = note->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slots) {
                slot_el = ll->l_head->l_next;
                while (slot_el) {
                    t_llllelem *next_slot_el = slot_el->l_next;
                    if (hatom_gettype(&slot_el->l_hatom) == H_LLLL) {
                        t_llll *slot_ll = hatom_getllll(&slot_el->l_hatom);
                        if (slot_ll->l_head && hatom_gettype(&slot_ll->l_head->l_hatom) == H_LONG && hatom_getlong(&slot_ll->l_head->l_hatom) == note_voice_slot_num) { // slot_num is 1-based
                            long res = -1;
                            if (slot_ll->l_head->l_next && is_hatom_number(&slot_ll->l_head->l_next->l_hatom))
                                res = hatom_getlong(&slot_ll->l_head->l_next->l_hatom);
                            if (also_destroy_voice_slot)
                                llll_destroyelem(slot_el);
                            return res;
                        }
                    }
                    slot_el = next_slot_el;
                }
            }
        }
    }
    return -1;
}


double el2dur(t_llllelem *el)
{
    if (hatom_gettype(&el->l_hatom) == H_LLLL) {
        t_llll *ll = hatom_getllll(&el->l_hatom);
        if (ll && ll->l_head && is_hatom_number(&ll->l_head->l_hatom))
            return hatom_getdouble(&ll->l_head->l_hatom);
    }
    
    dev_post("Warning: wrong quantize data");
    return 0;
}

void quantize_collapse(t_llll **measureinfo, t_llll **cents, t_llll **durations, t_llll **velocities, t_llll **ties, t_llll **graphic, t_llll **breakpoints,
                       t_llll **slots, t_llll **regularityboxes, t_llll **noteIDs, long collapse_voice_slot_num, long num_voices,
                       char *need_free_graphic, char *need_free_breakpoints, char *need_free_slots)
{
    // we need to use a single time signature, AND a single regularity boxes, so we just keep the first voice
    if (*measureinfo && (*measureinfo)->l_head && hatom_gettype(&(*measureinfo)->l_head->l_hatom) == H_LLLL){
        t_llll *first = llll_clone(hatom_getllll(&(*measureinfo)->l_head->l_hatom));
        llll_free(*measureinfo);
        *measureinfo = first;
        llll_wrap_once(measureinfo); // just one voice
    }
    if (*regularityboxes && (*regularityboxes)->l_head && hatom_gettype(&(*regularityboxes)->l_head->l_hatom) == H_LLLL){
        t_llll *first = llll_clone(hatom_getllll(&(*regularityboxes)->l_head->l_hatom));
        llll_free(*regularityboxes);
        *regularityboxes = first;
        llll_wrap_once(regularityboxes);
    }
    
    // retrieving max duration
    double tot_dur = 0;
    t_llllelem *voice_el;
    for (voice_el = (*durations)->l_head; voice_el; voice_el = voice_el->l_next) {
        if (hatom_gettype(&voice_el->l_hatom) == H_LLLL)
            tot_dur = MAX(tot_dur, llll_sum_abs_of_double_llll(hatom_getllll(&voice_el->l_hatom)));
    }
    
    // building transposed information for each voice
    t_llll *info = llll_get();
    llll_appendllll_clone(info, *cents, NULL);
    llll_appendllll_clone(info, *velocities, NULL);
    llll_appendllll_clone(info, *ties, NULL);
    llll_appendllll_clone(info, *graphic, NULL);
    llll_appendllll_clone(info, *breakpoints, NULL);
    llll_appendllll_clone(info, *slots, NULL);
    llll_appendllll_clone(info, *noteIDs, NULL);
    
    llll_trans_inplace(info, 2);
    llll_funall(info, (fun_fn) trans_mode2_fn, NULL, 1, 1, FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH);
    llll_funall(info, (fun_fn) trans_mode2_fn, NULL, 1, 2, FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH);
    
    t_llll *tot = llll_get();
    llll_appendllll_clone(tot, *durations, NULL);
    llll_appendllll(tot, info);
    llll_trans_inplace(tot, 2);
    llll_funall(tot, (fun_fn) trans_mode2_fn, NULL, 1, 1, FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH);
    
    // now we have, for each voice
    // (lapse_ms (NOTE NOTE)) (lapse (NOTE NOTE)) (negative_lapse ()) (lapse (NOTE NOTE))...
    
    // adding "fake" slot containing voice number (1-based) to all notes
    long i = 1;
    for (voice_el = tot->l_head, i = 1; voice_el; voice_el = voice_el->l_next, i++) {
        if (hatom_gettype(&voice_el->l_hatom) == H_LLLL) {
            t_llll *voice_ll = hatom_getllll(&voice_el->l_hatom);
            t_llllelem *el;
            for (el = voice_ll->l_head; el; el = el->l_next) {
                if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                    t_llllelem *chord_el = hatom_getllll(&el->l_hatom)->l_tail;
                    if (chord_el && hatom_gettype(&chord_el->l_hatom) == H_LLLL) {
                        t_llll *chord_ll = hatom_getllll(&chord_el->l_hatom);
                        if (chord_ll->l_size > 0) {
                            t_llllelem *note_el;
                            for (note_el = chord_ll->l_head; note_el; note_el = note_el->l_next) {
                                if (hatom_gettype(&note_el->l_hatom) == H_LLLL) {
                                    t_llll *note_ll = hatom_getllll(&note_el->l_hatom);
                                    t_llllelem *slots_el = note_ll ? llll_getindex(note_ll, 6, I_STANDARD) : NULL;
                                    if (slots_el && hatom_gettype(&slots_el->l_hatom) == H_LLLL) {
                                        t_llll *slots_ll = hatom_getllll(&slots_el->l_hatom);
                                        t_llll *newlist = llll_get();
                                        llll_appendlong(newlist, collapse_voice_slot_num);
                                        llll_appendlong(newlist, i);
                                        llll_appendllll(slots_ll, newlist);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    //	char *buf5 = NULL;
    //	llll_to_text_buf(tot, &buf5, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SPECIAL_AND_SEPARATORS, NULL);
    
    // in case graphic, breakpoints and slots had been allocated individually with llll_get(), and NOT just taken from the extras list by reference
    if (*need_free_graphic)
        llll_free(*graphic);
    if (*need_free_breakpoints)
        llll_free(*breakpoints);
    if (*need_free_slots)
        llll_free(*slots);
    
    // real collapsing
    double cur_onset_general = 0;
    t_llllelem **active = (t_llllelem **)bach_newptr(num_voices * sizeof(t_llllelem *));
    t_llllelem **cur = (t_llllelem **)bach_newptr(num_voices * sizeof(t_llllelem *));
    double *cur_onset = (double *)bach_newptr(num_voices * sizeof(double));
    
    for (i = 0; i < num_voices; i++) {
        t_llllelem *voice = llll_getindex(tot, i+1, I_STANDARD);
        cur[i] = voice && hatom_gettype(&voice->l_hatom) == H_LLLL ? hatom_getllll(&voice->l_hatom)->l_head : NULL;
        cur_onset[i] = 0;
        active[i] = NULL;
    }
    
    char is_rest = true;
    t_llll *collapsed = llll_get();
    long *transients = (long *)bach_newptr(num_voices * sizeof(long));
    while (true) {
        
        // A) finding next transient
        long best = -1;
        double best_onset = tot_dur + 500;
        for (i = 0; i < num_voices; i++) {
            if (cur[i] && cur_onset[i] < best_onset) {
                best = i;
                best_onset = cur_onset[i];
            } else if (!cur[i] && cur_onset[i] < best_onset) {
                // voice i has ended
                best = i;
                best_onset = cur_onset[i];
            }
        }
        
        if (best < 0) // end of algorithm
            break;
        
        
        // B) finding all synchronous transients
        long how_many_transients = 0;
        double orig_best_onset = best_onset;
        for (i = 0; i < num_voices; i++) {
            double this_diff = cur_onset[i] - orig_best_onset;
            if (fabs(this_diff) < 0.001) {
                transients[how_many_transients] = i;
                how_many_transients++;
                best_onset = MAX(best_onset, cur_onset[i]);
            }
        }
        
        
        // C) crystalizing previous lapse (the one BEFORE the newly found transient)
        t_llll *this_lapse = llll_get();
        t_llll *this_lapse_notes = llll_get();
        llll_appenddouble(this_lapse, (best_onset - cur_onset_general)*(is_rest ? -1 : 1));
        for (i = 0; i < num_voices; i++) { // adding active voices
            if (active[i] && hatom_gettype(&active[i]->l_hatom) == H_LLLL) {
                t_llll *cloned = llll_clone(hatom_getllll(&hatom_getllll(&active[i]->l_hatom)->l_tail->l_hatom));
                
                // if in the next cycle there is NO transient for the i-th voice, it means that this lapse for voice i continues,
                // thus we have to set all note ties to their note ID (or to 1 if there's none)
                if (!is_long_in_long_array(transients, how_many_transients, i)) {
                    t_llllelem *note_el;
                    for (note_el = cloned->l_head; note_el; note_el = note_el->l_next) {
                        if (hatom_gettype(&note_el->l_hatom) == H_LLLL){
                            t_llll *note_ll = hatom_getllll(&note_el->l_hatom);
                            t_llllelem *tie_el = llll_getindex(note_ll, 3, I_STANDARD);
                            t_llllelem *id_el = llll_getindex(note_ll, 7, I_STANDARD);
                            if (tie_el && hatom_gettype(&tie_el->l_hatom) == H_LONG) {
//                                t_llllelem *info_el = llll_getindex(note_ll, 2, I_STANDARD);
                                long note_id = (id_el && hatom_gettype(&id_el->l_hatom) == H_LONG ? hatom_getlong(&id_el->l_hatom) : 1);
                                hatom_setlong(&tie_el->l_hatom, note_id); // TO DO: how to handle this now that ties are ID-ed?
                            }
                        }
                    }
                }
                
                llll_chain(this_lapse_notes, cloned);
            }
        }
        llll_appendllll(this_lapse, this_lapse_notes);
        llll_appendllll(collapsed, this_lapse);
        
        
        // D) updating stuff for next cycle:
        // 1. updating active[] array
        for (i = 0; i < how_many_transients; i++) {
            long j = transients[i];
            if (cur[j] && el2dur(cur[j]) > 0)
                active[j] = cur[j];
            else
                active[j] = NULL;
        }
        
        // 2. updating rest status
        is_rest = true;
        for (i = 0; i < num_voices; i++) {
            if (active[i]) {
                is_rest = false;
                break;
            }
        }
        
        // 3. updating cursors and cursor onsets
        for (i = 0; i < how_many_transients; i++) {
            long j = transients[i];
            if (cur[j]) {
                cur_onset[j] += fabs(el2dur(cur[j]));
                cur[j] = cur[j]->l_next;
            } else {
                cur_onset[j] = tot_dur + 1000; // set to fake unreachable onset: voice j has ended!
            }
        }
        
        // 4. (freeing stuff)
        cur_onset_general = best_onset;
    }

    bach_freeptr(transients);

    llll_behead(collapsed); // first element is a foo "0" element
    
    bach_freeptr(active);
    bach_freeptr(cur);
    bach_freeptr(cur_onset);
    
    //	char *buf7 = NULL;
    //	llll_to_text_buf(collapsed, &buf7, 0, 2, 0, NULL); //buf7 + 120
    //	llll_post(collapsed, 0, 2, 2, NULL, NULL);
    
    // freeing stuff
    llll_free(*durations);
    llll_free(*cents);
    llll_free(*velocities);
    llll_free(*noteIDs);
    llll_free(*ties);
    //	llll_free(*graphic);
    //	llll_free(*breakpoints);
    //	llll_free(*slots);
    
    // post-treatment
    llll_trans_inplace(collapsed, 2);
    *durations = llll_clone(hatom_getllll(&collapsed->l_head->l_hatom));
    t_llll *infook = llll_clone(hatom_getllll(&collapsed->l_tail->l_hatom));
    llll_wrap_once(durations);
    
    llll_funall(infook, (fun_fn) trans_mode2_fn, NULL, 1, 1, FUNALL_PROCESS_SUBLISTS_ONLY_AT_MAXDEPTH);
    t_llllelem *infook_el;
    for (infook_el = infook->l_head; infook_el; infook_el = infook_el->l_next) {
        if (hatom_gettype(&infook_el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&infook_el->l_hatom);
            if (!ll->l_head)
                llll_appendllll(ll, llll_get());
        }
    }
    llll_trans_inplace(infook, 2);
    
    *noteIDs = llll_slice(infook, -1);
    *slots = llll_slice(infook, -1);
    *breakpoints = llll_slice(infook, -1);
    *graphic = llll_slice(infook, -1);
    *ties = llll_slice(infook, -1);
    *velocities = llll_slice(infook, -1);
    *cents = llll_slice(infook, -1);
    
    *need_free_graphic = true;
    *need_free_breakpoints = true;
    *need_free_slots = true;
    
    llll_free(tot);
    llll_free(infook);
    llll_free(collapsed);
}

// return the gathered syntax
t_llll *quantize_uncollapse(t_llll *measureinfo, t_llll *boxed_cents, t_llll *boxed_durations, t_llll *boxed_velocities, t_llll *boxed_ties, t_llll *boxed_extras, long num_voices, long collapse_voice_slot_num)
{
    // we work on the gathered syntax
    t_llll *gathered = score_separate2gathered_syntax(measureinfo, boxed_cents, boxed_durations, boxed_velocities, boxed_ties, boxed_extras);
    t_llllelem *voice_el, *meas_el, *ch_el, *note_el;
    long i;
    
    //	llll_post(gathered, 0, 1, 2, NULL, NULL);
    
    if (gathered && gathered->l_head) {
        
        // we copy the collapsed voice for all the number of needed voices in the score
        while ((long)gathered->l_size < num_voices)
            llll_appendhatom_clone(gathered, &gathered->l_head->l_hatom);
        
        // in each of those copies, we only retain the notes whose "collapse slot" is set to the current voice number
        for (voice_el = gathered->l_head, i = 1; voice_el && i <= num_voices; voice_el = voice_el->l_next, i++){
            if (hatom_gettype(&voice_el->l_hatom) == H_LLLL) {
                t_llll *voice_ll = hatom_getllll(&voice_el->l_hatom);
                for (meas_el = voice_ll->l_head; meas_el; meas_el = meas_el->l_next) {
                    if (hatom_gettype(&meas_el->l_hatom) == H_LLLL) {
                        t_llll *meas_ll = hatom_getllll(&meas_el->l_hatom);
                        if (meas_ll->l_head && meas_ll->l_head->l_next) {
                            for (ch_el = meas_ll->l_head->l_next; ch_el; ch_el = ch_el->l_next) {
                                if (hatom_gettype(&ch_el->l_hatom) == H_LLLL) {
                                    t_llll *ch_ll = hatom_getllll(&ch_el->l_hatom);
                                    char is_grace_level = false;
                                    
                                    // handling grace chords
                                    if (ch_ll->l_head && hatom_gettype(&ch_ll->l_head->l_hatom) == H_SYM &&
                                        hatom_getsym(&ch_ll->l_head->l_hatom) == _llllobj_sym_g && ch_ll->l_head->l_next &&
                                        hatom_gettype(&ch_ll->l_head->l_next->l_hatom) == H_LLLL) {
                                        ch_ll = hatom_getllll(&ch_ll->l_head->l_next->l_hatom);
                                        is_grace_level = true;
                                    }
                                    
                                    while (ch_ll) {	// juste beacuse of grace levels: it'll only cycle when inside a grace level, otherwise the chord list is plain
                                        t_llll *next_ll = NULL;
                                        
                                        if (is_grace_level && ch_ll->l_owner && ch_ll->l_owner->l_next && hatom_gettype(&ch_ll->l_owner->l_next->l_hatom) == H_LLLL)
                                            next_ll = hatom_getllll(&ch_ll->l_owner->l_next->l_hatom);
                                        
                                        if (ch_ll->l_head && ch_ll->l_head->l_next) {
                                            note_el = ch_ll->l_head->l_next;
                                            while (note_el) {
                                                t_llllelem *note_el_next = note_el->l_next;
                                                if (hatom_gettype(&note_el->l_hatom) == H_LLLL) {
                                                    t_llll *note_ll = hatom_getllll(&note_el->l_hatom);
                                                    long voice = retrieve_note_voice_from_gathered_syntax(note_ll, CONST_COLLAPSE_SLOT, true); // returned value is 1-based
                                                    if (voice != i) {
                                                        llll_destroyelem(note_el);
                                                        if (is_hatom_number(&ch_ll->l_head->l_hatom) && (!ch_ll->l_head->l_next || hatom_gettype(&ch_ll->l_head->l_next->l_hatom) != H_LLLL)) {
                                                            // NO NOTES IN THIS CHORD
                                                            if (is_grace_level && ch_ll->l_owner) {
                                                                // must be deleted!
                                                                llll_destroyelem(ch_ll->l_owner);
                                                            } else {
                                                                // must be turned into a rest
                                                                t_rational dur = hatom_getrational(&ch_ll->l_head->l_hatom);
                                                                hatom_setrational(&ch_ll->l_head->l_hatom, rat_long_prod(rat_abs(dur), -1));
                                                            }
                                                        }
                                                    }
                                                }
                                                note_el = note_el_next;
                                            }
                                        }
                                        
                                        ch_ll = next_ll;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return gathered;
}

void quantize_allow(t_quantize *x, t_symbol *s, long argc, t_atom *argv){
    if (argc == 0){
        if (x->allow_box_durs){
            llll_free(x->allow_box_durs);
            x->allow_box_durs = NULL;
        }
    } else {
        t_llll *allow = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
        if (x->allow_box_durs)
            llll_free(x->allow_box_durs);
        x->allow_box_durs = allow;
    }
}

void quantize_deny(t_quantize *x, t_symbol *s, long argc, t_atom *argv){
    if (argc == 0){
        if (x->deny_box_durs){
            llll_free(x->deny_box_durs);
            x->deny_box_durs = NULL;
        }
    } else {
        t_llll *deny = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
        if (x->deny_box_durs)
            llll_free(x->deny_box_durs);
        x->deny_box_durs = deny;
    }
}

void quantize_assist(t_quantize *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a == 0)															// @in 0 @type llll/bang @digest Measureinfo or bang
            sprintf(s, "llll: Measureinfo or auto or bang to Trigger");		// @description @copy BACH_DOC_MEASUREINFO_SYNTAX
        else if (a == 1)	// @in 1 @type llll @digest The llll output by bach.roll's or bach.score's first outlet after a <m>quantize</m> message – or in <m>separate</m> mode: Pitches or MIDIcents
            sprintf(s, x->separate_mode ? "llll: Pitches or Cents" : "llll from bach.roll or bach.score");
        else if (a == 2)	// @in 2 @type llll @digest The Regularity Boxes for the quantization – or in <m>separate</m> mode: Durations
            // @description @copy BACH_DOC_REGULARITYBOXES
            sprintf(s, x->separate_mode ? "llll: Durations" : "llll: Regularity Boxes");
        else if (a == 3)	// @in 3 @type llll @digest Velocities (in <m>separate</m> mode only)
            sprintf(s, "llll: Velocities");
        else if (a == 4)	// @in 4 @type llll @digest Ties (in <m>separate</m> mode only)
            sprintf(s, "llll: Ties");
        else if (a == 5)	// @in 5 @type llll @digest Extras (in <m>separate</m> mode only)
            sprintf(s, "llll: Extras");
        else				// @in 6 @type llll @digest Regularity Boxes (in <m>separate</m> mode only)
            // @description @copy BACH_DOC_REGULARITYBOXES
            sprintf(s, "llll: Regularity Boxes");
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        if (a == 0)		// @out 0 @type anything @digest Messages for bach.score
            // @description	Unless the <m>separate</m> argument is set, this sends
            //				the score gathered-syntax which construct the quantized score.
            //				If the <m>separate</m> attribute is set, this sends messages to score (such as "clear"
            //				if <m>autoclear</m> is active) and a bang to properly build the score from
            //				the separate parameters
            sprintf(s, x->separate_mode ? "llll (%s): Messages for bach.score's First Inlet" : "llll (%s): Score in Gathered Syntax", type);
        else if (a == 1)	//	@out 1 @type llll @digest Notifications (in standard mode), or Measureinfo (in <m>separate</m> mode)
            //  @description Unless the <m>separate</m> attribute is set, this sends out the notifications obtained
            //  from marker quantization (such as the pickup added time).
            //  If the <m>separate</m> argument is set, this sends out the Measureinfo (in <m>separate</m> mode only)
            sprintf(s, x->separate_mode ? "llll (%s): Measureinfo" : "llll (%s): Notifications", type);
        else if (a == 2)	//  @out 2 @type llll @digest The quantized Pitches or cents (in <m>separate</m> mode only)
            sprintf(s, "llll (%s): Pitches", type);
        else if (a == 3)	//  @out 3 @type llll @digest The quantized Durations (in <m>separate</m> mode only)
            sprintf(s, "llll (%s): Durations", type);
        else if (a == 4)	//  @out 4 @type llll @digest The quantized Velocities (in <m>separate</m> mode only)
            sprintf(s, "llll (%s): Velocities", type);
        else if (a == 5)	//  @out 5 @type llll @digest The quantized Ties (in <m>separate</m> mode only)
            sprintf(s, "llll (%s): Ties", type);
        else if (a == 6)	//  @out 6 @type llll @digest The quantized Extras (in <m>separate</m> mode only)
            sprintf(s, "llll (%s): Extras", type);
        else				//  @out 7 @type llll @digest Notifications (in <m>separate</m> mode only)
            sprintf(s, "llll (%s): Notifications", type);
    }
}

void quantize_inletinfo(t_quantize *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}


void quantize_free(t_quantize *x) // we must free cache!!!
{
    long i;
    
    //	bach_freeptr(x->minimal_units_as_atomlist);
    
    if (x->noteIDs)
        llll_free(x->noteIDs);
    
    bach_freeptr(x->articulations_typo_preferences.artpref);
    
    if (x->separate_mode) {
        for (i = 1; i < 7; i++)
            object_free_debug(x->n_proxy[i]);
    } else {
        object_free_debug(x->n_proxy[1]);
        object_free_debug(x->n_proxy[2]);
    }
    
    if (x->minimal_units)
        llll_free(x->minimal_units);
    
    systhread_mutex_free_debug(x->n_mutex);
    
    if (x->allow_box_durs)
        llll_free(x->allow_box_durs);
    
    if (x->deny_box_durs)
        llll_free(x->deny_box_durs);
    
    if (x->marker_info) {
        llll_free(x->marker_info);
        x->marker_info = NULL;
    }
    
    if (x->header_info) {
        llll_free(x->header_info);
        x->header_info = NULL;
    }
    
    llllobj_obj_free((t_llllobj_object *) x);
}

t_quantize *quantize_new(t_symbol *s, short ac, t_atom *av)
{
    t_quantize *x = NULL;
    t_max_err err = MAX_ERR_NONE;
    long true_ac = attr_args_offset(ac, av);
    
    if ((x = (t_quantize *) object_alloc_debug(quantize_class))) {
        // @arg 0 @name separate @optional 1 @type symbol @digest Separate parameters mode
        // @description Put a "separate" symbol as argument if you want to input and output the separate parameters (and not the bach.score gathered syntax).
        x->separate_mode = true_ac && atom_gettype(av) == A_SYM && atom_getsym(av) == _llllobj_sym_separate;
        
        object_attr_setdisabled((t_object *)x, gensym("autoclear"), !x->separate_mode); // if outputs are NOT separated, the score is of course always cleared
        
        if (x->separate_mode) {
            x->n_proxy[6] = proxy_new_debug((t_object *) x, 6, &x->n_in);
            x->n_proxy[5] = proxy_new_debug((t_object *) x, 5, &x->n_in);
            x->n_proxy[4] = proxy_new_debug((t_object *) x, 4, &x->n_in);
            x->n_proxy[3] = proxy_new_debug((t_object *) x, 3, &x->n_in);
            x->n_proxy[2] = proxy_new_debug((t_object *) x, 2, &x->n_in);
            x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
        } else {
            x->n_proxy[2] = proxy_new_debug((t_object *) x, 2, &x->n_in);
            x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
        }
        
        // default values
        x->marker_info = NULL;
        x->header_info = llll_get();
        x->algorithm = 0;
        x->realtime_mode = 0;
        x->rt_last_length = 0;
        x->rt_achieved_length = 0;
        x->num_minimal_units = 2;
        x->discard_grace_rests = 1;
        x->discard_graces = k_DISCARD_GRACE_WHEN_EACH_NOTE_HAS_A_TIE;
        x->always_try_to_quantize_boxes_with_no_grace_notes = false;
        x->tempi_handling = k_TEMPI_FROM_MEASURE_BARLINES;
        x->allow_multiple_measures_inside_barline_markers = false;
        x->tempo_approx_mode = 1; // compensate at each barline
        x->pickup_added_time = -1; // initialized negative, meaning: unneeded
#ifdef C74_X64
        x->tempo_approx_digits = 2;
#else
        x->tempo_approx_digits = 1;
#endif
        x->autoclear = true;
        x->ceilmeasures = true;
        x->allow_box_durs = NULL;
        x->deny_box_durs = NULL;
        x->current_voice_being_quantized = 0;
        
        long i;
        for (i = 0; i < CONST_MAX_SLOTS; i++) {
            x->slot_types[i] = k_SLOT_TYPE_NONE;
            x->slot_copy_when_split[i] = true;
        }
        
        /*		t_llll *default_minimal_units_llll = llll_get();
         llll_appendrat(default_minimal_units_llll, RAT_1OVER16);
         llll_appendrat(default_minimal_units_llll, genrat(1,12));
         x->minimal_units = default_minimal_units_llll;*/
        
        //		x->minimal_units = llll_from_text_buf("1/16 1/12"); // static, old default
        x->minimal_units = llll_from_text_buf((char *)"dynamic ( 1/16 1/12 ) 10 ( 1/16 1/24 ) 15 ( 1/32 1/24 )"); // dynamic: new default
        x->use_dynamic_minimal_units = true;
        
        x->dynamic_minimal_units = NULL;
        x->mixing_mode = 1;
        x->merging_policy = 2;
        x->regroup_delete = 3; //0;
        x->approx_width = 2;
        x->max_iterations_number = 0;
        x->dur_delete_percentage = 5.;
        x->grace_dur_delete_percentage = 2.5;
        x->box_tie_percentage = 20.;
        x->verbose = 0;
        x->quantization_priority = k_LINEAR;
        //		x->quantization_priority = k_NOTES_FIRST_DECREASING;
        
        
        /// Articulations handling
        x->articulations_typo_preferences.num_articulations = k_NUM_STANDARD_ARTICULATIONS;
        x->articulations_typo_preferences.artpref = (t_articulation_preferences *)bach_newptrclear(CONST_MAX_ARTICULATIONS * sizeof(t_articulation_preferences));
        load_articulations_typo_preferences(&x->articulations_typo_preferences, gensym("November for bach"));
        
        
        attr_args_process(x, ac, av);
        systhread_mutex_new_debug(&x->n_mutex, 0);
        
        if (!x->minimal_units || x->minimal_units->l_size == 0) {
            if (x->minimal_units) llll_free(x->minimal_units);
            x->minimal_units = llll_get();
            llll_appendrat(x->minimal_units, RAT_1OVER16); // default
            x->num_minimal_units = 1;
            x->use_dynamic_minimal_units = 0;
        }
        
        llllobj_obj_setup((t_llllobj_object *) x, 7, x->separate_mode ? "44444444" : "44", NULL);
        
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

long compare_by_first(void *data, t_llllelem *a, t_llllelem *b){
    if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
        t_llll *a_llll = hatom_getllll(&a->l_hatom);
        t_llll *b_llll = hatom_getllll(&b->l_hatom);
        if (hatom_getdouble(&a_llll->l_head->l_hatom) <= hatom_getdouble(&b_llll->l_head->l_hatom))
            return 1;
        else
            return 0;
    }
    return 0;
}

long compare_llllelem_for_approximation(void *data, t_llllelem *a, t_llllelem *b){
    if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
        t_llll *a_llll = hatom_getllll(&a->l_hatom);
        t_llll *b_llll = hatom_getllll(&b->l_hatom);
        if (rat_rat_cmp( rat_abs(hatom_getrational(&a_llll->l_head->l_hatom)), rat_abs(hatom_getrational(&b_llll->l_head->l_hatom))) <= 0)
            return 1;
        else
            return 0;
    }
    return 0;
}

t_llll *get_approx_for_elem(t_quantize *x, t_llllelem *elem, t_llll *minimal_units)
{
    t_llllelem *mu_elem;
    long mu_number = minimal_units->l_size;
    long i, j, mu_index;
    t_llll *approx_for_this_elem = llll_get();
    t_rational elem_rat = hatom_getrational(&elem->l_hatom);
    t_rational worst_error = elem_rat;
    long greatest_coefficient = 0;
    t_llll *inner_llll;
    
    for (mu_elem = minimal_units->l_head, mu_index = 0; mu_elem; mu_elem = mu_elem->l_next, mu_index++) {
        t_rational mu_elem_rat = hatom_getrational(&mu_elem->l_hatom);
        long quoto = (long)round(rat2double(rat_rat_div(elem_rat, mu_elem_rat)));
        for (i = -x->approx_width; i <= x->approx_width; i++) {
            if (quoto + i > 0) {
                t_llll *inner_llll = llll_get();
                t_rational approx = rat_long_prod(mu_elem_rat, quoto + i);
                t_rational error = rat_rat_diff(elem_rat, approx);
                t_llll *tree_address = llll_get();
                if (rat_rat_cmp(rat_abs(error), worst_error) > 0) worst_error = rat_abs(error);
                if (quoto + i > greatest_coefficient) greatest_coefficient = quoto + i;
                for (j = 0; j < mu_number; j++)
                    llll_appendlong(tree_address, (j == mu_index) ? quoto+i : 0);
                llll_appendrat(inner_llll, error);
                llll_appendrat(inner_llll, approx);
                llll_appendllll(inner_llll, tree_address);
                
                llll_appendllll(approx_for_this_elem, inner_llll);
            }
        }
    }
    
    if (x->mixing_mode == k_ALLOW_MIX) {
        // we add all the mixed combinations having coefficients up to greatest_coefficient, provided that thay have error < worst_error
        long *multiindex = (long *) bach_newptr(mu_number * sizeof(long));
        char end = false;
        long h, k = 0;
        for (k = 0; k < mu_number; k++)
            multiindex[k] = 0; //multiindex[0]
        
        k = 0;
        while (!end) {
            // do we take this combination?
            if (get_num_zeros_in_long_array(multiindex, mu_number) < mu_number-1) {
                // we take it: cause we haven't already taken it (it's a real combination, not a single number!)
                t_llll *inner_llll = NULL;
                t_rational approx = long2rat(0);
                t_rational error;
                for (h = 0, mu_elem = minimal_units->l_head; h < mu_number && mu_elem; h++, mu_elem = mu_elem->l_next)
                    approx = rat_rat_sum(approx, rat_long_prod(hatom_getrational(&mu_elem->l_hatom), multiindex[h]));
                error = rat_rat_diff(elem_rat, approx);
                
                if (rat_rat_cmp(error, worst_error) <= 0) {
                    t_llll *tree_address = llll_get();
                    for (i = 0; i < mu_number; i++)
                        llll_appendlong(tree_address, multiindex[i]);
                    
                    inner_llll = llll_get();
                    llll_appendrat(inner_llll, error);
                    llll_appendrat(inner_llll, approx);
                    llll_appendllll(inner_llll, tree_address);
                    
                    llll_appendllll(approx_for_this_elem, inner_llll);
                }
            }
            
            // incrementing multiindex
            multiindex[k]++;
            while (multiindex[k] > greatest_coefficient) {
                if (k >= mu_number - 1) {
                    end = true;
                    break; // end!
                } else {
                    k++;
                    multiindex[k]++;
                }
            }
            if (!end) {
                for (h = 0; h < k && h < mu_number; h++)
                    multiindex[h] = 0;
                k = 0;
            }
        }
        bach_freeptr(multiindex);
    }
    
    // we add the all zeros possibility
    inner_llll = llll_get();
    llll_appendrat(inner_llll, elem_rat);
    llll_appendrat(inner_llll, long2rat(0));
    llll_appendllll(inner_llll, repeat_long(0, mu_number));
    llll_appendllll(approx_for_this_elem, inner_llll);
    
    // we sort the list
    llll_mergesort_inplace(&approx_for_this_elem, compare_llllelem_for_approximation, NULL);
    return approx_for_this_elem;
}

void mu_combination_to_string(t_quantize *x, t_llll *mu_combination, char **string, t_llll *minimal_units){
    t_llllelem *elem4, *elem5;
    const long MAX_STRING_SIZE = 10000;
    long cursor = 0; char firsttime = true;
    
    *string = (char *) bach_newptr(MAX_STRING_SIZE); // to be safe
    for (elem4 = mu_combination->l_head, elem5 = minimal_units->l_head; elem4 && elem5; elem4 = elem4->l_next, elem5 = elem5->l_next) {
        char partial_string[50]; long len;
        long coeff = hatom_getlong(&elem4->l_hatom);
        if (coeff > 0) {
            if (firsttime) {
                snprintf_zero(partial_string, 50, " %ld * %ld/%ld ", coeff, rat_num(hatom_getrational(&elem5->l_hatom)), rat_den(hatom_getrational(&elem5->l_hatom))	);
                firsttime = false;
            } else
                snprintf_zero(partial_string, 50, " + %ld * %ld/%ld ", coeff, rat_num(hatom_getrational(&elem5->l_hatom)), rat_den(hatom_getrational(&elem5->l_hatom)) );
            len = strlen(partial_string);
            if (cursor + len > MAX_STRING_SIZE - 2)
                break;
            strncpy((*string) + cursor, partial_string, len);
            cursor += len;
        }
    }
    (*string)[cursor] = 0;
}

void post_approximation_tree(t_quantize *x, t_llll *box_durations, t_llll *approx_possib, long start_from_idx, t_llll *minimal_units) {
    t_llllelem *elem, *elem2, *elem3;
    long i, d;
    for (d = start_from_idx, elem = llll_getindex(approx_possib, start_from_idx + LLLL_IDX_BASE, I_NON_NEGATIVE), elem2 = llll_getindex(box_durations, start_from_idx + LLLL_IDX_BASE, I_NON_NEGATIVE);
         elem && elem2; d++, elem = elem->l_next, elem2 = elem2->l_next){
        object_post((t_object *) x, "   Idx: %ld. Duration: %ld/%ld", d, rat_num(hatom_getrational(&elem2->l_hatom)), rat_den(hatom_getrational(&elem2->l_hatom)));
        for (elem3 = hatom_getllll(&elem->l_hatom)->l_head, i = 0; elem3; elem3 = elem3->l_next, i++) {
            t_llll *possib = hatom_getllll(&elem3->l_hatom);
            t_llll *combination = hatom_getllll(&possib->l_head->l_next->l_next->l_hatom);
            char *possib_string;
            char *possib_comb = NULL;
            llll_to_text_buf(combination, &possib_comb, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
            mu_combination_to_string(x, combination, &possib_string, minimal_units);
            object_post((t_object *) x, "   Choice [%ld] > coeffs: ( %s), error: %ld/%ld, approx: %ld/%ld = %s", i, possib_comb, rat_num(hatom_getrational(&possib->l_head->l_hatom)), rat_den(hatom_getrational(&possib->l_head->l_hatom)),
                        rat_num(hatom_getrational(&possib->l_head->l_next->l_hatom)), rat_den(hatom_getrational(&possib->l_head->l_next->l_hatom)), possib_string);
            bach_freeptr(possib_string);
            bach_freeptr(possib_comb);
        }
    }
}

char is_llll_an_incipit_of_this_llll(t_llll *incipit_to_check, t_llll *this_llll){
    t_llllelem *elem1, *elem2;
    
    if (!this_llll || !incipit_to_check)
        return false;
    
    for (elem1 = incipit_to_check->l_head, elem2 = this_llll->l_head; elem1 && elem2; elem1 = elem1->l_next, elem2 = elem2->l_next)
        if (!llll_eq_elem_ignoretype(elem1, elem2))
            return false;
    
    if (elem1 && !elem2)
        return false;
    
    return true;
}

char is_llll_an_incipit_of_an_llll_among_a_list(t_llll *incipit_to_check, t_llll *list_of_admitted_lllls){
    t_llllelem *elem;
    
    if (!list_of_admitted_lllls || !incipit_to_check)
        return false;
    
    for (elem = list_of_admitted_lllls->l_head; elem; elem = elem->l_next){
        t_llll *this_llll = hatom_getllll(&elem->l_hatom);
        if (this_llll && is_llll_an_incipit_of_this_llll(incipit_to_check, this_llll))
            return true;
    }
    return false;
}

char is_approx_ok_for_allow_and_deny_box_durs(t_quantize *x, t_llllelem **elem_multiindex, long up_to_depth){
    t_llll *temp = llll_get();
    long i;
    char discarded = false;
    
    if (!x->allow_box_durs && !x->deny_box_durs)
        return true;
    
    for (i = 0; i <= up_to_depth; i++)
        llll_appendrat(temp, approx_elem_to_approx(elem_multiindex[i]));
    
    if (x->allow_box_durs) {
        t_llll *list;
        if (x->allow_box_durs->l_depth >= 3) {
            t_llllelem *thisel = llll_getindex(x->allow_box_durs, x->current_voice_being_quantized, I_NON_NEGATIVE);
            if (thisel && hatom_gettype(&thisel->l_hatom) == H_LLLL)
                list = hatom_getllll(&thisel->l_hatom);
            else
                list = x->allow_box_durs;
        } else
            list = x->allow_box_durs;
        discarded |= !is_llll_an_incipit_of_an_llll_among_a_list(temp, list);
    }
    
    if (x->deny_box_durs) {
        t_llll *list;
        if (x->deny_box_durs->l_depth >= 3) {
            t_llllelem *thisel = llll_getindex(x->deny_box_durs, x->current_voice_being_quantized, I_NON_NEGATIVE);
            if (thisel && hatom_gettype(&thisel->l_hatom) == H_LLLL)
                list = hatom_getllll(&thisel->l_hatom);
            else
                list = x->deny_box_durs;
        } else
            list = x->deny_box_durs;
        discarded |= is_llll_an_incipit_of_an_llll_among_a_list(temp, list);
    }
    
    llll_free(temp);
    
    return !discarded;
}

long get_num_non_zero_elements(t_llll *ll){
    t_llllelem *elem;
    long count = 0;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LONG && hatom_getlong(&elem->l_hatom) != 0)
            count++;
        else if (hatom_gettype(&elem->l_hatom) == H_RAT && hatom_getrational(&elem->l_hatom).r_num != 0)
            count++;
        else if (hatom_gettype(&elem->l_hatom) == H_DOUBLE && hatom_getdouble(&elem->l_hatom) != 0.)
            count++;
    }
    return count;
}


char is_sym_duration_tuplet(t_rational sym_duration){
    return (perfect_log2(sym_duration.r_den) < 0);
}

t_rational get_tuplet_minimum_complet_unit_from_sym_duration(t_rational sym_duration){
    long den_no2factors = sym_duration.r_den;
    while (!(den_no2factors % 2))
        den_no2factors /= 2;
    return rat_long_prod(sym_duration, sym_duration.r_den/iexp2(den_no2factors));
}

t_rational get_tail_tuplet_duration(t_llll **coefficients, long depth, long minimal_unit_index, t_rational minimal_unit){
    long i;
    t_rational tot_tuplet_dur = long2rat(0);
    for (i = depth-1; i >= 0; i--) {
        long this_nonzero_index = llll_first_nonzero_entry_index_in_plain_long_llll(coefficients[i]);
        if (this_nonzero_index == minimal_unit_index) {
            long nonzero_coeff = hatom_getlong(&llll_getindex(coefficients[i], this_nonzero_index, I_MODULO)->l_hatom);
            tot_tuplet_dur = rat_rat_sum(tot_tuplet_dur, rat_long_prod(minimal_unit, nonzero_coeff));
        } else
            break;
    }
    return tot_tuplet_dur;
}

char quantize_box_single_step(t_quantize *x, t_llll *box_durations, t_llll **quantized_box_durations, t_llll *minimal_units) {
    t_llllelem *elem, *elem2, *elem3;
    long i;
    char res = false;
    long cycle_count, num_durations, num_nonzero_durations;
    t_rational total_duration;
    char done = false;
    t_llll *best_durations, *curr_durations;
    double best_euclidean_distance;
    t_rational curr_tot_duration;
    long depth, prev_depth;
    char approx_possib_has_changed;
    t_llll *signs = llll_get();
    t_llll *approx_possib = llll_get(); // here we'll have ((err1 approx1 tree_address1) (err2 approx2 tree_address2) ...) for each element!
    t_llllelem **elem_multiindex;
    long *elem_idx_multiindex, *num_possibilities;
    t_llll **coefficients, **approx_possib_history;
    long nonzero_index = -1; //1-based
    
    *quantized_box_durations = llll_get();
    if (x->verbose){
        char *rhythm_string = NULL, *mu_string = NULL;
        t_rational width = llll_sum_abs_of_rat_llll(box_durations);
        llll_to_text_buf(box_durations, &rhythm_string, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
        llll_to_text_buf(minimal_units, &mu_string, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
        object_post((t_object *) x, "• Rhythm will be quantized in the order: %s", rhythm_string);
        object_post((t_object *) x, "• Density: %.2f", rat2double(long_rat_div(box_durations->l_size, width)));
        object_post((t_object *) x, "• Minimal units: %s", mu_string);
        bach_freeptr(rhythm_string);
        bach_freeptr(mu_string);
    }
    
    // if we have just 1 rhythmical event, or nothing
    if (box_durations->l_size <= 1) {
        if (x->verbose) {
            object_post((t_object *) x, "• There's just a rhythmical event in the box. Nothing to quantize.");
            object_post((t_object *) x, "• Rhythm out = Rhythm in.");
        }
        systhread_mutex_lock(x->n_mutex);
        llll_clone_upon(box_durations, *quantized_box_durations);
        systhread_mutex_unlock(x->n_mutex);
        
        llll_free(signs);
        llll_free(approx_possib);
        return true;
    }
    
    // if we have no minimal units, we break
    if (box_durations->l_size <= 1) {
        if (x->verbose) {
            object_post((t_object *) x, "• No minimal units for this box. Nothing to quantize.");
            object_post((t_object *) x, "• Rhythm out = Rhythm in.");
        }
        systhread_mutex_lock(x->n_mutex);
        llll_clone_upon(box_durations, *quantized_box_durations);
        systhread_mutex_unlock(x->n_mutex);
        
        llll_free(signs);
        llll_free(approx_possib);
        return true;
    }
    
    // we only operate on positive things; we'll re-inject the sign information later on
    for (elem = box_durations->l_head; elem; elem = elem->l_next) {
        if (hatom_getrational(&elem->l_hatom).r_num > 0) {
            llll_appendlong(signs, 1);
        } else {
            llll_appendlong(signs, -1);
            hatom_setrational(&elem->l_hatom, rat_long_prod(hatom_getrational(&elem->l_hatom), -1));
        }
    }
    
    // we make a list of possibilities for each duration
    for (elem = box_durations->l_head; elem; elem = elem->l_next) {
        t_llll *this_elem_approx = get_approx_for_elem(x, elem, minimal_units);
        llll_appendllll(approx_possib, this_elem_approx);
    }
    
    //	llll_check(approx_possib);
    
    // now in approx_possib we have a list like
    // (((1/48 3/32 (3)) (-1/24 1/8 (4)) (1/12 1/16 (2))) ((0 1/32 (1)) (-1/16 1/16 (2))))
    // ((note1) (note2)... )
    // where note_i = (error1 approximation1 (tree_address1)) (error2 approx2 (tree_address2))....
    // and tree_address are the coefficients in the linear combination of minimal units.
    
    if (x->verbose >= 3) {
        object_post((t_object *) x, "----- Possible approximations: -----");
        post_approximation_tree(x, box_durations, approx_possib, 0, minimal_units);
        object_post((t_object *) x, "----- end of approximation tree ----");
    }
    
    // now we start the tree exploration: we start the search!
    cycle_count = 0;
    num_durations = approx_possib->l_size;
    num_nonzero_durations = get_num_non_zero_elements(box_durations);
    total_duration = llll_sum_abs_of_rat_llll(box_durations);
    done = false;
    
    // multiindex for the track of our tree exploration. i-th entry has the current llllelem corresponding to the i-th duration
    elem_multiindex = (t_llllelem **) bach_newptr(num_durations * sizeof(t_llllelem *));
    elem_idx_multiindex = (long *) bach_newptr(num_durations * sizeof(long)); // indices of the llllelems
    num_possibilities = (long *) bach_newptr(num_durations * sizeof(long)); // number of possibilities for each duration
    coefficients = (t_llll **) bach_newptr(num_durations * sizeof(t_llll *));
    for (i = 0, elem = approx_possib->l_head; i < num_durations && elem; i++, elem = elem->l_next) {
        elem_multiindex[i] = hatom_getllll(&elem->l_hatom)->l_head;
        elem_idx_multiindex[i] = 0;
        num_possibilities[i] = hatom_getllll(&elem->l_hatom)->l_size;
    }
    // each of the elem_multiindex[i] is a llllelem containing a llll like
    // (-1/48 1/16 (0 2 1))
    
    approx_possib_history = (t_llll **) bach_newptr(num_durations * sizeof(t_llll *));
    
    //	llll_check(approx_possib);
    
    for (i = 0; i < num_durations; i++)
        approx_possib_history[i] = llll_get();
    llll_clone_upon(approx_possib, approx_possib_history[0]);
    
    //	llll_check(approx_possib);
    
    best_durations = llll_get(); // the best one
    curr_durations = llll_get(); // the current one
    best_euclidean_distance = -1.; // distance between best solution and target (needed to be initialized it as negative)
    curr_tot_duration = long2rat(0);
    depth = 0;
    prev_depth = 0;
    approx_possib_has_changed = false;
    while (!done) {
        char is_ok = true;
        t_rational nonzero_mu_unit = long2rat(0);
        char mu_number = minimal_units->l_size;
        
        cycle_count++;
        if (x->verbose >= 2) {
            char *multiindex_buf;
            object_post((t_object *) x, "");
            object_post((t_object *) x, " >>>> Cycle No. %ld", cycle_count);
            multiindex_buf = long_array_to_string(elem_idx_multiindex, num_durations, true);
            object_post((t_object *) x, " >>>> Testing multiindex: %s", multiindex_buf);
            object_post((t_object *) x, "");
            bach_freeptr(multiindex_buf);
        }
        
        if (cycle_count > 1000) // BRUTTO
            break;
        
        // euristic, to decide wheter this branch of tree is dead or alive
        for (i = 0; i < num_durations; i++)
            coefficients[i] = approx_elem_to_coefficients(elem_multiindex[i]);
        
        if (x->mixing_mode != k_SMART_MIX || nonzero_index < 0) {
            nonzero_index = llll_first_nonzero_entry_index_in_plain_long_llll(coefficients[0]);
            if (nonzero_index > 0)
                nonzero_mu_unit = hatom_getrational(&llll_getindex(minimal_units, nonzero_index, I_MODULO)->l_hatom);
        }
        
        //		if (nonzero_index < 0) {
        //			if (x->verbose >= 2) object_post((t_object *) x, "     - First chord is annihilated! Rejected.");
        //			is_ok = false;
        //		}
        
        // if it's ok we test this solution: cycle on each element
        //		for (elem = box_durations->l_head; is_ok && depth < num_durations && elem && is_ok; depth++, elem = elem->l_next) {
        for (; is_ok && depth < num_durations; depth++) {
            t_llll *delta_llll;
            t_rational delta;
            long first_nonzero_entry;
            t_rational prev_mu;
            t_rational elem_approx;
            t_llllelem *this_dur;
            
            llll_check(approx_possib);
            
            // we can keep things up to current depth
            llll_trim(curr_durations, depth);
            if (prev_depth > depth || (prev_depth == depth && approx_possib_has_changed)) {
                if (approx_possib) {
                    llll_free(approx_possib);
                    approx_possib = llll_get();
                }
                
                llll_check(approx_possib);
                llll_clone_upon(approx_possib_history[depth], approx_possib);
                llll_check(approx_possib);
                
                // reassigning pointers
                for (i = 0, elem2 = approx_possib->l_head; i < num_durations && elem2; i++, elem2 = elem2->l_next) {
                    elem_multiindex[i] = llll_getindex(hatom_getllll(&elem2->l_hatom), elem_idx_multiindex[i] + LLLL_IDX_BASE, I_NON_NEGATIVE);
                    coefficients[i] = approx_elem_to_coefficients(elem_multiindex[i]); //elem_multiindex[0]
                }
                
                if (x->mixing_mode == k_SMART_MIX) {
                    long temp = 0;
                    i = depth - 1;
                    while (i >= 0 && !(temp = llll_first_nonzero_entry_index_in_plain_long_llll(coefficients[i])))
                        i--;
                    nonzero_index = temp;
                }
                
                if (x->verbose >= 3) {
                    object_post((t_object *) x, "----- Keeping this approximation tree: -----");
                    post_approximation_tree(x, box_durations, approx_possib, depth, minimal_units);
                    object_post((t_object *) x, "-------- end of approximation tree -------");
                }
                approx_possib_has_changed = false;
            }
            
            // getting this element's approximation
            elem_approx = approx_elem_to_approx(elem_multiindex[depth]); // current approximation of the depth-th duration
            
            this_dur = llll_getindex(box_durations, depth + 1, I_NON_NEGATIVE);
            if (x->verbose >= 2) {
                char *approx_comb_string;
                mu_combination_to_string(x, coefficients[depth], &approx_comb_string, minimal_units);
                object_post((t_object *) x, "     - Target element (idx %ld): %ld/%ld", depth, hatom_getrational(&this_dur->l_hatom).r_num, hatom_getrational(&this_dur->l_hatom).r_den);
                object_post((t_object *) x, "     - Approximation element: %ld/%ld = %s", elem_approx.r_num, elem_approx.r_den, approx_comb_string);
                bach_freeptr(approx_comb_string);
            }
            
            // testing solution
            if ((x->mixing_mode == k_DONT_MIX || x->mixing_mode == k_SMART_MIX) && llll_num_zeros_in_plain_long_llll(coefficients[depth]) < mu_number - 1) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for %ld-th duration has mixed units! Rejected.", depth);
                is_ok = false;
            } else if (llll_num_zeros_in_plain_long_llll(coefficients[depth]) > mu_number - 1 && hatom_getrational(&this_dur->l_hatom).r_num != 0 && !(x->regroup_delete == k_TURN_INTO_GRACE_CHORDS && !x->always_try_to_quantize_boxes_with_no_grace_notes)) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for %ld-th duration has all zeros! Rejected.", depth);
                is_ok = false;
            } else if (llll_num_zeros_in_plain_long_llll(coefficients[depth]) != mu_number && hatom_getrational(&this_dur->l_hatom).r_num == 0) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for %ld-th duration has a grace note turned into real chord! Rejected.", depth);
                is_ok = false;
            } else if (x->mixing_mode == k_DONT_MIX && nonzero_index > 0 && (first_nonzero_entry = llll_first_nonzero_entry_index_in_plain_long_llll(coefficients[depth])) != nonzero_index && first_nonzero_entry > 0) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for %ld-th duration has new minimal unit! Rejected.", depth);
                is_ok = false;
            } else if (x->mixing_mode == k_SMART_MIX && nonzero_index > 0 &&
                       (prev_mu = hatom_getrational(&llll_getindex(minimal_units, nonzero_index, I_NON_NEGATIVE)->l_hatom)).r_num && is_sym_duration_tuplet(prev_mu) &&
                       (first_nonzero_entry = llll_first_nonzero_entry_index_in_plain_long_llll(coefficients[depth])) && first_nonzero_entry != nonzero_index &&
                       rat_rat_div(get_tail_tuplet_duration(coefficients, depth, nonzero_index, prev_mu), get_tuplet_minimum_complet_unit_from_sym_duration(prev_mu)).r_den != 1) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for %ld-th duration has an uncompleted tuplet! Rejected.", depth);
                is_ok = false;
            } else if (depth == num_durations - 1 && approx_elem_to_error(elem_multiindex[depth]).r_num != 0) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for last duration has non-zero error! Rejected.");
                is_ok = false;
            } else if (depth == num_durations - 2 && !is_there_an_approx_with_given_error(hatom_getllll(&approx_possib->l_tail->l_hatom), rat_long_prod(approx_elem_to_error(elem_multiindex[depth]), -1))) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for second-last duration cannot lead to a zero-error solution! Rejected.");
                is_ok = false;
            } else if ((x->allow_box_durs || x->deny_box_durs) && !is_approx_ok_for_allow_and_deny_box_durs(x, elem_multiindex, depth)) {
                if (x->verbose >= 2) object_post((t_object *) x, "     -- approximation for does not fit with allowed/denied configurations! Rejected.");
                is_ok = false;
            } else {
                t_rational duration_to_complete = rat_rat_diff(total_duration, llll_sum_abs_of_rat_llll(curr_durations));
                long num_notes_left = num_nonzero_durations - curr_durations->l_size; //was: num_durations - curr_durations->l_size
                t_llllelem *rat_elem = llll_getindex(minimal_units, nonzero_index, I_NON_NEGATIVE);
                t_rational minimum_unit = (x->mixing_mode == k_DONT_MIX && rat_elem) ? hatom_getrational(&rat_elem->l_hatom) : llll_min_of_plain_rat_llll(minimal_units);
                if (x->always_try_to_quantize_boxes_with_no_grace_notes &&
                    rat_rat_cmp(rat_long_prod(minimum_unit, num_notes_left), duration_to_complete) > 0) { // if we cannot use grace notes, it can't pass! it's not possible to fulfill the duration
                    if (x->verbose >= 2) object_post((t_object *) x, "     -- We cannot quantize %ld/%ld with at least %ld times %ld/%ld. Rejected.",
                                                     duration_to_complete.r_num, duration_to_complete.r_den, num_notes_left, minimum_unit.r_num, minimum_unit.r_den);
                    is_ok = false;
                } else if (x->mixing_mode == k_DONT_MIX && rat_rat_div(duration_to_complete, minimum_unit).r_den != 1) {
                    if (x->verbose >= 2) object_post((t_object *) x, "     -- We cannot fill %ld/%ld with multiples of %ld/%ld (mix not allowed). Rejected.",
                                                     duration_to_complete.r_num, duration_to_complete.r_den, minimum_unit.r_num, minimum_unit.r_den);
                    is_ok = false;
                }
            }
            
            if (!is_ok)
                break;
            
            if (x->mixing_mode == k_SMART_MIX) {
                long temp = llll_first_nonzero_entry_index_in_plain_long_llll(coefficients[depth]);
                if (temp > 0)
                    nonzero_index = temp;
            }
            
            // else: the approximation is kept! We append it to the current solution
            llll_appendrat(curr_durations, elem_approx);
            curr_tot_duration = rat_rat_sum(curr_tot_duration, elem_approx);
            delta_llll = hatom_getllll(&(elem_multiindex[depth]->l_hatom));
            delta = hatom_getrational(&delta_llll->l_head->l_hatom);
            
            // re-setting and re-sorting approximations for the next depth!
            if (depth < num_durations - 1) {
                t_llll *this_llll;
                elem3 = llll_getindex(approx_possib, depth + 1 + LLLL_IDX_BASE, I_NON_NEGATIVE);
                this_llll = hatom_getllll(&elem3->l_hatom);
                for (elem2 = this_llll->l_head; elem2; elem2 = elem2->l_next) {
                    t_llllelem *thisllllelem = hatom_getllll(&elem2->l_hatom)->l_head;
                    hatom_setrational(&thisllllelem->l_hatom, rat_rat_sum(hatom_getrational(&thisllllelem->l_hatom), delta));
                }
                if (x->algorithm == k_QUANTIZE_ALGORITHM_GREEDY || x->algorithm == k_QUANTIZE_ALGORITHM_EXHAUSTIVE_GREEDY_FIRST) {
                    t_llll *out;
                    llll_mergesort(this_llll, &out, compare_llllelem_for_approximation, NULL); // frees this_llll
                    
                    out->l_owner = elem3;
                    hatom_setllll(&elem3->l_hatom, out);	// mergesort does not change depth: I can use setllll, provided we set the owner
                    
                    // re-assigning elem_multiindex on the base of elem_idx_multiindex (we have reordered the elements! the pointer doesn't point any more to the element on the same position)
                    if (depth + 1 < num_durations) {
                        elem_multiindex[depth + 1] = llll_getindex(hatom_getllll(&elem3->l_hatom), elem_idx_multiindex[depth + 1] + LLLL_IDX_BASE, I_NON_NEGATIVE);
                        coefficients[depth + 1] = approx_elem_to_coefficients(elem_multiindex[depth + 1]);
                    }
                }
                approx_possib_has_changed = true;
            }
            
            llll_check(approx_possib);
            
            if (depth < num_durations - 1) {
                //update approx_possib_history
                if (approx_possib_history[depth + 1]) {
                    llll_free(approx_possib_history[depth + 1]);
                    approx_possib_history[depth + 1]=llll_get();
                }
                llll_clone_upon(approx_possib, approx_possib_history[depth + 1]);
            }
            
            llll_check(approx_possib);
            
            if (x->verbose >= 2) {
                char *curr_durations_string = NULL;
                object_post((t_object *) x, "     -- Seems good, so far. Approximation accepted.");
                llll_to_text_buf(curr_durations, &curr_durations_string, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
                object_post((t_object *) x, "     -- Current durations: %s", curr_durations_string);
                if ((x->algorithm == k_QUANTIZE_ALGORITHM_GREEDY || x->algorithm == k_QUANTIZE_ALGORITHM_EXHAUSTIVE_GREEDY_FIRST) && x->verbose >= 3) {
                    object_post((t_object *) x, "----- New sorted approximation tree: -----");
                    post_approximation_tree(x, box_durations, approx_possib, depth + 1, minimal_units);
                    object_post((t_object *) x, "-------- end of approximation tree -------");
                }
                bach_freeptr(curr_durations_string);
            }
            
            llll_check(approx_possib);
            
        }
        
        if (is_ok) { // solution retained!
            
            double this_euclidean_distance = llll_euclidean_distance_of_plain_rat_lllls(curr_durations, box_durations);

#ifdef QUANTIZE_USE_STDEVS
            t_llll *this_stdevs = llll_abs_diff_of_plain_lllls_as_double(curr_durations, box_durations);
            double this_error_average = 0;
            double this_error_stdev = llll_stdev_of_plain_double_llll(this_stdevs, &this_error_average);
#endif
            
            if (x->verbose) {
                char *quantization_string = NULL;
                llll_to_text_buf(curr_durations, &quantization_string, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
                object_post((t_object *) x, "      > Possible quantization found: %s", quantization_string);
                object_post((t_object *) x, "      > Euclidean distance: %.8f", this_euclidean_distance);
#ifdef QUANTIZE_USE_STDEVS
                object_post((t_object *) x, "      > Error: average %.8f, stdev: %.8f", this_error_average, this_error_stdev);
#endif
                bach_freeptr(quantization_string);
            }
            
#ifdef QUANTIZE_USE_STDEVS
            llll_free(this_stdevs);
#endif
            res = true; // found something!
            
            if (x->algorithm == k_QUANTIZE_ALGORITHM_GREEDY) {
                // we've finished! we've greedily found the first fitting solution
                if (x->verbose) object_post((t_object *) x, "      > Greedy search has ended.");
                llll_clone_upon(curr_durations, best_durations);
                done = true;
                break;
            }
            
            // is it the best one?
            if (best_euclidean_distance < 0 || this_euclidean_distance < best_euclidean_distance) {
                // it is the best
                best_euclidean_distance = this_euclidean_distance;
                if (x->verbose) object_post((t_object *) x, "      > It is the best euclidean distance so far. We keep this solution.");
                if (best_durations) {
                    llll_free(best_durations);
                    best_durations = llll_get();
                }
                llll_clone_upon(curr_durations, best_durations);
            } else {
                // not the best
                if (x->verbose) object_post((t_object *) x, "      > It is the NOT the best euclidean distance so far. We drop this solution.");
            }
            
            depth = num_durations - 2; // if we need to continue our search...
        }
        
        prev_depth = depth; // keep track of the previous depth before incrementing multiindex
        increment_multiindex(elem_idx_multiindex, num_durations, num_possibilities, &depth, -1);
        done = increment_elem_multiindex(elem_multiindex, approx_possib, &depth, -1);
        
        if (x->max_iterations_number > 0 && cycle_count > x->max_iterations_number)
            done = true;
    }
    
    
    // setting results into *quantized_box_durations
    if (res == true) {
        systhread_mutex_lock(x->n_mutex);
        llll_clone_upon(best_durations, *quantized_box_durations);
        systhread_mutex_unlock(x->n_mutex);
        
        // re-inserting signs
        for (elem = (*quantized_box_durations)->l_head, elem2 = signs->l_head; elem && elem2; elem = elem->l_next, elem2 = elem2->l_next)
            hatom_setrational(&elem->l_hatom, rat_long_prod(rat_abs(hatom_getrational(&elem->l_hatom)), hatom_getlong(&elem2->l_hatom)));
        
        if (x->verbose) {
            char *rhythm_string = NULL;
            llll_to_text_buf(*quantized_box_durations, &rhythm_string, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
            object_post((t_object *) x, "• Quantization found.");
            object_post((t_object *) x, "• Rhythm out in quantization order: %s", rhythm_string);
            bach_freeptr(rhythm_string);
        }
    } else {
        if (x->verbose) object_post((t_object *) x, "• No possible quantization found.");
        systhread_mutex_lock(x->n_mutex);
        llll_clone_upon(box_durations, *quantized_box_durations);
        systhread_mutex_unlock(x->n_mutex);
        
        // re-inserting signs
        for (elem = (*quantized_box_durations)->l_head, elem2 = signs->l_head; elem && elem2; elem = elem->l_next, elem2 = elem2->l_next)
            hatom_setrational(&elem->l_hatom, rat_long_prod(rat_abs(hatom_getrational(&elem->l_hatom)), hatom_getlong(&elem2->l_hatom)));
    }
    
    llll_free(best_durations);
    llll_free(curr_durations);
    llll_free(signs);
    llll_free(approx_possib);
    for (i = 0; i < num_durations; i++)
        llll_free(approx_possib_history[i]);
    
    bach_freeptr(elem_multiindex);
    bach_freeptr(elem_idx_multiindex);
    bach_freeptr(num_possibilities);
    bach_freeptr(coefficients);
    bach_freeptr(approx_possib_history);
    return res;
}

char is_there_an_approx_with_given_error(t_llll *approx_possib_for_duration, t_rational given_error){
    t_llllelem *elem;
    for (elem = approx_possib_for_duration->l_head; elem; elem = elem->l_next)
        if (rat_rat_cmp(approx_elem_to_error(elem), given_error) == 0)
            return true;
    
    return false;
}

t_llll *approx_elem_to_coefficients(t_llllelem *approx_elem){
    t_llllelem *elem = hatom_getllll(&approx_elem->l_hatom)->l_tail;
    return hatom_getllll(&elem->l_hatom);
}

t_rational approx_elem_to_error(t_llllelem *approx_elem){
    t_llllelem *elem = hatom_getllll(&approx_elem->l_hatom)->l_head;
    return hatom_getrational(&elem->l_hatom);
}

t_rational approx_elem_to_approx(t_llllelem *approx_elem){
    t_llllelem *elem = hatom_getllll(&approx_elem->l_hatom)->l_head->l_next;
    return hatom_getrational(&elem->l_hatom);
}

char increment_multiindex(long *multiindex, long num_entries, long *max_value, long *start_from_index, char direction){
    // returns 1 when it's over, 0 if there are still combination to endorse
    long h;
    long k = start_from_index ? *start_from_index : 0; //(direction == 1) ? 0 : num_entries - 1;
    
    k = CLAMP(k, 0, num_entries-1);
    
    if (multiindex[k] < max_value[k])
        multiindex[k]++;
    while (multiindex[k] >= max_value[k]) {
        if ((direction == 1 && k >= num_entries - 1) || (direction != 1 && k <= 0)) {
            return true; // we've ended
        } else {
            if (direction == 1)
                k++;
            else
                k--;
            multiindex[k]++;
        }
    }
    if (direction == 1) {
        for (h = 0; h < k && h < num_entries; h++)
            multiindex[h] = 0;
    } else {
        for (h = num_entries - 1; h > k && h >= 0; h--)
            multiindex[h] = 0;
    }
    
    *start_from_index = k;
    return false;
}

char increment_elem_multiindex(t_llllelem **elem_multiindex, t_llll *approx_possib, long *start_from_index, char direction){
    // returns 1 when it's over, 0 if there are still combination to endorse
    long num_entries = approx_possib->l_size;
    long h;
    long k =  start_from_index ? *start_from_index : 0; //(direction == 1) ? 0 : num_entries - 1;
    t_llllelem *elem;
    
    k = CLAMP(k, 0, num_entries-1);
    
    if (elem_multiindex[k])
        elem_multiindex[k] = elem_multiindex[k]->l_next;
    while (!elem_multiindex[k]) {
        if ((direction == 1 && k >= num_entries - 1) || (direction != 1 && k < 1)) {
            return true; // we've ended
        } else {
            if (direction == 1)
                k++;
            else
                k--;
            if (elem_multiindex[k])
                elem_multiindex[k] = elem_multiindex[k]->l_next;
        }
    }
    if (direction == 1) {
        for (h = 0, elem = approx_possib->l_head; h < k && elem; h++, elem = elem->l_next)
            elem_multiindex[h] = hatom_getllll(&elem->l_hatom)->l_head;
    } else {
        for (h = num_entries - 1, elem = approx_possib->l_tail; h > k && elem; h--, elem = elem->l_prev)
            elem_multiindex[h] = hatom_getllll(&elem->l_hatom)->l_head;
    }
    
    *start_from_index = k;
    return false;
}

void set_all_longs_to_number(t_llll *in_llll, long number) {
    // changes all the longs in in_llll to a specific number (just 1st and 2nd level)
    t_llllelem *elem, *elem2;
    
    if (!in_llll) return;
    for (elem = in_llll->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LONG) {
            hatom_setlong(&elem->l_hatom, 0);
        } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
            for (elem2 = hatom_getllll(&elem->l_hatom)->l_head; elem2; elem2 = elem2->l_next) {
                if (hatom_gettype(&elem2->l_hatom) == H_LONG) {
                    hatom_setlong(&elem2->l_hatom, 0);
                }
            }
        }
    }
}

void regroup_delete_first_element(t_quantize *x, t_llll *rhythm, t_llll *infos, t_llll *ties,
                                    t_llllelem *prevbox_last_rhythm_elem, t_llllelem *prevbox_last_infos_elem, t_llllelem *prevbox_last_ties_elem,
                                    t_llllelem *nextbox_first_rhythm_elem, t_llllelem *nextbox_first_infos_elem, t_llllelem *nextbox_first_ties_elem,
                                    t_rational smallest_minimal_unit) {
    if (rhythm && rhythm->l_size > 1) {
        t_llllelem *rhythm_elem, *infos_elem, *ties_elem;
        t_llllelem *prev_infos_elem, *prev_ties_elem, *prev_rhythm_elem;
        t_llllelem *next_infos_elem, *next_ties_elem, *next_rhythm_elem;
        t_llllelem *smallest_rhythm_elem = rhythm->l_head;
        t_llllelem *smallest_infos_elem = infos->l_head;
        t_llllelem *smallest_ties_elem = ties->l_head;
        
        if (!smallest_rhythm_elem)
            return; // not found. Something has gone wrong.
        
        prev_infos_elem = smallest_infos_elem ? (smallest_infos_elem->l_prev ? smallest_infos_elem->l_prev : prevbox_last_infos_elem) : NULL;
        prev_ties_elem = smallest_ties_elem->l_prev ? smallest_ties_elem->l_prev : prevbox_last_ties_elem;
        prev_rhythm_elem = smallest_rhythm_elem->l_prev ? smallest_rhythm_elem->l_prev : prevbox_last_rhythm_elem;
        next_infos_elem = smallest_infos_elem ? (smallest_infos_elem->l_next ? smallest_infos_elem->l_next : nextbox_first_infos_elem) : NULL;
        next_ties_elem = smallest_ties_elem->l_next ? smallest_ties_elem->l_next : nextbox_first_ties_elem;
        next_rhythm_elem = smallest_rhythm_elem->l_next ? smallest_rhythm_elem->l_next : nextbox_first_rhythm_elem;
        
        destroy_rhythm_element_or_turn_it_into_grace(x, smallest_rhythm_elem, smallest_infos_elem, smallest_ties_elem,
                                                     prev_rhythm_elem, prev_infos_elem, prev_ties_elem, next_rhythm_elem, next_infos_elem, next_ties_elem, true, false, smallest_minimal_unit);
    }
}

void regroup_delete_fastest_element(t_quantize *x, t_llll *rhythm, t_llll *infos, t_llll *ties,
                                    t_llllelem *prevbox_last_rhythm_elem, t_llllelem *prevbox_last_infos_elem, t_llllelem *prevbox_last_ties_elem,
                                    t_llllelem *nextbox_first_rhythm_elem, t_llllelem *nextbox_first_infos_elem, t_llllelem *nextbox_first_ties_elem,
                                    t_rational smallest_minimal_unit) {
    if (rhythm && rhythm->l_size > 1) {
        t_llllelem *rhythm_elem, *infos_elem, *ties_elem;
        t_llllelem *prev_infos_elem, *prev_ties_elem, *prev_rhythm_elem;
        t_llllelem *next_infos_elem, *next_ties_elem, *next_rhythm_elem;
        t_llllelem *smallest_rhythm_elem = NULL;
        t_llllelem *smallest_infos_elem = NULL;
        t_llllelem *smallest_ties_elem = NULL;
        t_rational smallest_rhythm_elem_ratabs = long2rat(0);
        
        // finding smallest element
        for (rhythm_elem = rhythm->l_head, infos_elem = infos->l_head, ties_elem = ties->l_head;
             rhythm_elem && ties_elem; // info might be null!
             rhythm_elem = rhythm_elem->l_next, infos_elem = infos_elem ? infos_elem->l_next : NULL, ties_elem = ties_elem->l_next) { // cycle on the rhythm
            t_rational rhythm_elem_ratabs = rat_abs(hatom_getrational(&rhythm_elem->l_hatom));
            if (smallest_rhythm_elem_ratabs.r_num == 0 || (rhythm_elem_ratabs.r_num != 0 && rat_rat_cmp(rhythm_elem_ratabs, smallest_rhythm_elem_ratabs) < 0)) {
                smallest_rhythm_elem_ratabs = rhythm_elem_ratabs;
                smallest_rhythm_elem = rhythm_elem;
                smallest_infos_elem = infos_elem;
                smallest_ties_elem = ties_elem;
            }
        }
        
        if (!smallest_rhythm_elem)
            return; // not found. Something has gone wrong.
        
        prev_infos_elem = smallest_infos_elem ? (smallest_infos_elem->l_prev ? smallest_infos_elem->l_prev : prevbox_last_infos_elem) : NULL;
        prev_ties_elem = smallest_ties_elem->l_prev ? smallest_ties_elem->l_prev : prevbox_last_ties_elem;
        prev_rhythm_elem = smallest_rhythm_elem->l_prev ? smallest_rhythm_elem->l_prev : prevbox_last_rhythm_elem;
        next_infos_elem = smallest_infos_elem ? (smallest_infos_elem->l_next ? smallest_infos_elem->l_next : nextbox_first_infos_elem) : NULL;
        next_ties_elem = smallest_ties_elem->l_next ? smallest_ties_elem->l_next : nextbox_first_ties_elem;
        next_rhythm_elem = smallest_rhythm_elem->l_next ? smallest_rhythm_elem->l_next : nextbox_first_rhythm_elem;
        
        //		char *buf1 = NULL, *buf2 = NULL;
        //		llll_to_text_buf(rhythm, &buf1, 0, 0, 0, NULL);
        
        /*
         char debug1[1000], debug2[1000], debug3[1000], debug3b[1000];
         char debug4[1000], debug5[1000], debug6[1000];
         llll_to_char_array(hatom_getllll(&hatom_getllll(&prev_infos_elem->l_hatom)->l_tail->l_hatom), debug1, 999);
         llll_to_char_array(hatom_getllll(&hatom_getllll(&smallest_infos_elem->l_hatom)->l_tail->l_hatom), debug2, 999);
         llll_to_char_array(hatom_getllll(&hatom_getllll(&next_infos_elem->l_hatom)->l_tail->l_hatom), debug3, 999);
         //        llll_to_char_array(hatom_getllll(&hatom_getllll(&next_infos_elem->l_next->l_hatom)->l_tail->l_hatom), debug3b, 999);
         */
        
        destroy_rhythm_element_or_turn_it_into_grace(x, smallest_rhythm_elem, smallest_infos_elem, smallest_ties_elem,
                                                     prev_rhythm_elem, prev_infos_elem, prev_ties_elem, next_rhythm_elem, next_infos_elem, next_ties_elem, true, false, smallest_minimal_unit);
        
        //        llll_to_char_array(hatom_getllll(&hatom_getllll(&prev_infos_elem->l_hatom)->l_tail->l_hatom), debug4, 999);
        //        llll_to_char_array(hatom_getllll(&hatom_getllll(&next_infos_elem->l_hatom)->l_tail->l_hatom), debug5, 999);
        //        llll_to_char_array(hatom_getllll(&hatom_getllll(&next_infos_elem->l_next->l_hatom)->l_tail->l_hatom), debug6, 999);
        //        llll_to_char_array(hatom_getllll(&next_infos_elem->l_hatom), debug6, 999);
        
        //      llll_to_text_buf(rhythm, &buf2, 0, 0, 0, NULL);
        //		bach_freeptr(buf1);
        //		bach_freeptr(buf2);
    }
}

t_llllelem *info_to_midicents(t_llllelem *info_elem){
    t_llll *this_llll;
    if (!info_elem || hatom_gettype(&info_elem->l_hatom) != H_LLLL)
        return NULL;
    
    this_llll = hatom_getllll(&info_elem->l_hatom);
    if (!this_llll || this_llll->l_size < 1)
        return NULL;
    
    return this_llll->l_head;
}

t_llllelem *info_to_IDs(t_llllelem *info_elem){
    t_llll *this_llll;
    if (!info_elem || hatom_gettype(&info_elem->l_hatom) != H_LLLL)
        return NULL;
    
    this_llll = hatom_getllll(&info_elem->l_hatom);
    if (!this_llll || this_llll->l_size < 4)
        return NULL;
    
    return this_llll->l_head->l_next->l_next->l_next;
}


long info_to_num_notes(t_llllelem *info_elem){
    t_llllelem *this_llll_elem = info_to_midicents(info_elem);
    if (!this_llll_elem)
        return 0;
    else if (hatom_gettype(&this_llll_elem->l_hatom) == H_LLLL)
        return hatom_getllll(&this_llll_elem->l_hatom)->l_size;
    else
        return 1;
}


char get_num_positives_in_llll(t_llll *ll){
    t_llllelem *elem;
    long count = 0;
    if (!ll || !ll->l_head)
        return 0;
    for (elem = ll->l_head; elem; elem = elem->l_next){
        if (hatom_gettype(&elem->l_hatom) == H_LONG && hatom_getlong(&elem->l_hatom) >= 1)
            count++;
    }
    return count;
}


void destroy_rhythm_element_or_turn_it_into_grace(t_quantize *x, t_llllelem *rhythm_elem_to_delete, t_llllelem *infos_elem_to_delete, t_llllelem *ties_elem_to_delete,
                                                  t_llllelem *prev_elem_rhythm, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties,
                                                  t_llllelem *next_elem_rhythm, t_llllelem *next_elem_infos, t_llllelem *next_elem_ties,
                                                  char allow_merging, char only_if_grace_note_and_according_to_grace_note_conditions, t_rational smallest_minimal_unit){
    // destroys a rhythmical element, and handle the tie-keeping/deleting of the previous and next element
    char need_free_prev_mc = true;
    char need_free_next_mc = true;
    char need_free_prev_infos = true;
    char need_free_next_infos = true;
    char need_free_prev_IDs = true;
    char need_free_next_IDs = true;
    char need_free_prev_ties = true;
    char need_free_next_ties = true;
    char need_free_prev_elem_ties = false;
    t_rational this_duration = hatom_getrational(&rhythm_elem_to_delete->l_hatom);
    t_llll *these_ties = NULL, *these_mc = NULL, *these_infos = NULL, *these_IDs;
    t_llllelem *mcelem, *idselem;
    t_rational prev_duration = prev_elem_rhythm ? hatom_getrational(&prev_elem_rhythm->l_hatom) : long2rat(-1);
    t_rational next_duration = next_elem_rhythm ? hatom_getrational(&next_elem_rhythm->l_hatom) : long2rat(-1);
    t_llll *prev_ties = NULL, *prev_mc = NULL, *prev_infos = NULL, *prev_IDs;
    t_llll *next_ties = NULL, *next_mc = NULL, *next_infos = NULL, *next_IDs;
    char merging_direction = 0;
    char force_delete = false;
    t_rational rhythm_elem_to_delete_ratabs = rat_abs(hatom_getrational(&rhythm_elem_to_delete->l_hatom));
    
    // deciding whether to delete it or turn it into a grace chord
    char turn_into_grace_chord = false;
    if (x->regroup_delete == k_TURN_INTO_GRACE_CHORDS) {
        turn_into_grace_chord = true;
        if (x->grace_dur_delete_percentage > 0 && rat2double(rat_abs(hatom_getrational(&rhythm_elem_to_delete->l_hatom))) <= x->grace_dur_delete_percentage * rat2double(smallest_minimal_unit) / 100.) {
            turn_into_grace_chord = false;
            force_delete = true;
        } else if (info_to_num_notes(infos_elem_to_delete) == 0 && x->discard_grace_rests) {
            turn_into_grace_chord = false;
            force_delete = true;
        } else {
            char tied_to_next = is_chord_as_llllelem_all_tied_to(rhythm_elem_to_delete, infos_elem_to_delete, ties_elem_to_delete, next_elem_infos);
            char tied_to_prev = is_chord_as_llllelem_all_tied_from(rhythm_elem_to_delete, infos_elem_to_delete, prev_elem_infos, prev_elem_ties);
            char each_note_has_tie = false;
            if (x->discard_graces == k_DISCARD_GRACE_WHEN_EACH_NOTE_HAS_A_TIE)	// we don't compute this value in any case
                each_note_has_tie = in_chord_as_llllelem_all_notes_has_tie(rhythm_elem_to_delete, infos_elem_to_delete, ties_elem_to_delete, prev_elem_infos, prev_elem_ties, next_elem_infos);
            if ((x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_NEXT && tied_to_next) ||
                (x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_PREV && tied_to_prev) ||
                (x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_NEXT_AND_PREV && tied_to_next && tied_to_prev) ||
                (x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_NEXT_OR_PREV && (tied_to_next || tied_to_prev)) ||
                (x->discard_graces == k_DISCARD_GRACE_WHEN_EACH_NOTE_HAS_A_TIE && each_note_has_tie)) {
                turn_into_grace_chord = false;
                force_delete = true;
            }
        }
        if (only_if_grace_note_and_according_to_grace_note_conditions && !force_delete)
            return;	// we just needed to delete grace notes not satisfying conditions
    }
    
    
    if (turn_into_grace_chord) {
        
        hatom_setrational(&rhythm_elem_to_delete->l_hatom, long2rat(0));
        
    } else {
        
        // getting lllls for these ties and mcs
        these_ties = llll_get();
        these_mc = llll_get();
        these_infos = llll_get();
        these_IDs = llll_get();
        mcelem = info_to_midicents(infos_elem_to_delete);
        idselem = info_to_IDs(infos_elem_to_delete);
        
        prev_ties = llll_get();
        prev_mc = llll_get();
        prev_infos = llll_get();
        prev_IDs = llll_get();
        next_ties = llll_get();
        next_mc = llll_get();
        next_infos = llll_get();
        next_IDs = llll_get();
        
        
        if (mcelem && hatom_gettype(&mcelem->l_hatom) == H_LLLL) {
            systhread_mutex_lock(x->n_mutex);
            llll_clone_upon(hatom_getllll(&mcelem->l_hatom), these_mc);
            systhread_mutex_unlock(x->n_mutex);
        } else if (mcelem) {
            llll_appenddouble(these_mc, hatom_getdouble(&mcelem->l_hatom));
        } else { // rest
            llll_appendllll(these_mc, llll_get());
        }
        
        if (idselem && hatom_gettype(&idselem->l_hatom) == H_LLLL) {
            systhread_mutex_lock(x->n_mutex);
            llll_clone_upon(hatom_getllll(&idselem->l_hatom), these_IDs);
            systhread_mutex_unlock(x->n_mutex);
        } else if (idselem) {
            llll_appenddouble(these_IDs, hatom_getlong(&idselem->l_hatom));
        } else { // rest
            llll_appendllll(these_IDs, llll_get());
        }
        
        if (hatom_gettype(&ties_elem_to_delete->l_hatom) == H_LLLL) {
            systhread_mutex_lock(x->n_mutex);
            llll_clone_upon(hatom_getllll(&ties_elem_to_delete->l_hatom), these_ties);
            systhread_mutex_unlock(x->n_mutex);
        } else {
            llll_free(these_ties);
            these_ties = repeat_long(hatom_getlong(&ties_elem_to_delete->l_hatom), these_mc->l_size);
        }
        
        if (hatom_gettype(&infos_elem_to_delete->l_hatom) == H_LLLL) {
            systhread_mutex_lock(x->n_mutex);
            llll_clone_upon(hatom_getllll(&infos_elem_to_delete->l_hatom), these_infos);
            systhread_mutex_unlock(x->n_mutex);
        }
        
        //	char debug[1000];
        //	llll_to_char_array(these_infos, debug, 999);
        
        // getting lllls for previous ties and mcs
        if (prev_elem_infos && prev_elem_ties && next_elem_infos && next_elem_ties) {
            mcelem = info_to_midicents(prev_elem_infos);
            if (mcelem && hatom_gettype(&mcelem->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&mcelem->l_hatom), prev_mc);
                systhread_mutex_unlock(x->n_mutex);
            } else if (mcelem) {
                llll_appenddouble(prev_mc, hatom_getdouble(&mcelem->l_hatom));
            } else { // rest
                llll_appendllll(prev_mc, llll_get());
            }
            
            t_llllelem *idselem = info_to_IDs(prev_elem_infos);
            if (idselem && hatom_gettype(&idselem->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&idselem->l_hatom), prev_IDs);
                systhread_mutex_unlock(x->n_mutex);
            } else if (idselem) {
                llll_appenddouble(prev_IDs, hatom_getdouble(&idselem->l_hatom));
            } else { // rest
                llll_appendllll(prev_IDs, llll_get());
            }
            
            
            if (hatom_gettype(&prev_elem_ties->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&prev_elem_ties->l_hatom), prev_ties);
                systhread_mutex_unlock(x->n_mutex);
                need_free_prev_elem_ties = true;
            } else {
                llll_free(prev_ties);
                prev_ties = repeat_long(hatom_getlong(&prev_elem_ties->l_hatom), prev_mc->l_size);
            }
            
            if (hatom_gettype(&prev_elem_infos->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&prev_elem_infos->l_hatom), prev_infos);
                systhread_mutex_unlock(x->n_mutex);
            }
        }
        
        if (next_elem_infos && next_elem_ties) {
            // getting lllls for next ties and mcs
            mcelem = info_to_midicents(next_elem_infos);
            if (mcelem && hatom_gettype(&mcelem->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&mcelem->l_hatom), next_mc);
                systhread_mutex_unlock(x->n_mutex);
            } else if (mcelem) {
                llll_appenddouble(next_mc, hatom_getdouble(&mcelem->l_hatom));
            } else { // rest
                llll_appendllll(next_mc, llll_get());
            }
            
            idselem = info_to_IDs(next_elem_infos);
            if (idselem && hatom_gettype(&idselem->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&idselem->l_hatom), next_IDs);
                systhread_mutex_unlock(x->n_mutex);
            } else if (idselem) {
                llll_appenddouble(next_IDs, hatom_getdouble(&idselem->l_hatom));
            } else { // rest
                llll_appendllll(next_IDs, llll_get());
            }
            
            if (hatom_gettype(&next_elem_ties->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&next_elem_ties->l_hatom), next_ties);
                systhread_mutex_unlock(x->n_mutex);
            } else {
                llll_free(next_ties);
                next_ties = repeat_long(hatom_getlong(&next_elem_ties->l_hatom), next_mc->l_size);
            }
            
            if (hatom_gettype(&next_elem_infos->l_hatom) == H_LLLL) {
                systhread_mutex_lock(x->n_mutex);
                llll_clone_upon(hatom_getllll(&next_elem_infos->l_hatom), next_infos);
                systhread_mutex_unlock(x->n_mutex);
            }
        }
        
    }
    
    // deciding to which element we need to merge
    t_llllelem *left = NULL, *right = NULL;
    if (x->merging_policy == k_MERGE_TO_BOTH) {
        left = rhythm_elem_to_delete->l_prev;
        right = rhythm_elem_to_delete->l_next;
        while (left && hatom_getrational(&left->l_hatom).r_num == 0)
            left = left->l_prev;
        while (right && hatom_getrational(&right->l_hatom).r_num == 0)
            right = right->l_next;
    } else if (x->merging_policy == k_MERGE_TO_PREV) {
        left = rhythm_elem_to_delete->l_prev;
        right = NULL;
        while (left && hatom_getrational(&left->l_hatom).r_num == 0)
            left = left->l_prev;
        if (!left) {
            right = rhythm_elem_to_delete->l_next;
            while (right && hatom_getrational(&right->l_hatom).r_num == 0)
                right = right->l_next;
        }
    } else if (x->merging_policy == k_MERGE_TO_NEXT) {
        left = NULL;
        right = rhythm_elem_to_delete->l_next;
        while (right && hatom_getrational(&right->l_hatom).r_num == 0)
            right = right->l_next;
        if (!right) {
            left = rhythm_elem_to_delete->l_prev;
            while (left && hatom_getrational(&left->l_hatom).r_num == 0)
                left = left->l_prev;
        }
    } else if (x->merging_policy == k_MERGE_TO_SMALLEST || x->merging_policy == k_MERGE_TO_BIGGEST) {
        left = rhythm_elem_to_delete->l_prev;
        right = rhythm_elem_to_delete->l_next;
        while (left && hatom_getrational(&left->l_hatom).r_num == 0)
            left = left->l_prev;
        while (right && hatom_getrational(&right->l_hatom).r_num == 0)
            right = right->l_next;
        if (left && right){
            if (rat_rat_cmp(rat_abs(hatom_getrational(&left->l_hatom)), rat_abs(hatom_getrational(&right->l_hatom))) < 0) {
                if (x->merging_policy == k_MERGE_TO_SMALLEST)
                    right = NULL;
                else
                    left = NULL;
            }
        }
    }
    
    // we don't merge chords to rests, so we make sure that they are NOT rests
    if (left && hatom_getrational(&left->l_hatom).r_num < 0 && right)
        left = NULL;
    if (right && hatom_getrational(&right->l_hatom).r_num < 0 && left)
        right = NULL;
    
    // re-assigning small duration to prev or next event
    if (left && right) {
        // merge to both
        char sign_left = isign(hatom_getrational(&left->l_hatom).r_num);
        char sign_right = isign(hatom_getrational(&right->l_hatom).r_num);
        t_rational half_dur = rat_long_div(rhythm_elem_to_delete_ratabs, 2);
        hatom_setrational(&left->l_hatom, rat_long_prod(rat_rat_sum(rat_abs(hatom_getrational(&left->l_hatom)), half_dur), sign_left));
        hatom_setrational(&right->l_hatom, rat_long_prod(rat_rat_sum(rat_abs(hatom_getrational(&right->l_hatom)), half_dur), sign_right));
        merging_direction = 0;
    } else if (left) {
        // merge to left
        char sign = isign(hatom_getrational(&left->l_hatom).r_num);
        hatom_setrational(&left->l_hatom, rat_long_prod(rat_rat_sum(rat_abs(hatom_getrational(&left->l_hatom)), rhythm_elem_to_delete_ratabs), sign));
        merging_direction = -1;
    } else if (right) {
        // merge to right
        char sign = isign(hatom_getrational(&right->l_hatom).r_num);
        hatom_setrational(&right->l_hatom, rat_long_prod(rat_rat_sum(rat_abs(hatom_getrational(&right->l_hatom)), rhythm_elem_to_delete_ratabs), sign));
        merging_direction = 1;
    }
    
    if (!turn_into_grace_chord) {
        
        if (QUANTIZE_MARK_TIED_INFOS) { // FIXING
            if (rhythm_elem_to_delete->l_thing.w_obj == NULL && next_elem_infos && next_elem_infos->l_thing.w_obj == WHITENULL)
                next_elem_infos->l_thing.w_obj = NULL;
        }
        
        // check if previous ties have to be broken, or have to be transferred
        if (prev_elem_infos && prev_elem_ties && next_elem_infos && next_elem_ties && next_duration.r_num >= 0 && prev_duration.r_num >= 0) {
            t_llllelem *tieelem, *idelem;
            
            // marking these_ties as non-treated on lthing field
            for (t_llllelem *tmp = these_ties->l_head; tmp; tmp = tmp->l_next)
                tmp->l_thing.w_obj = NULL;
            
            for (tieelem = prev_ties->l_head, idelem = prev_IDs->l_head; tieelem && idelem; tieelem = tieelem->l_next, idelem = idelem->l_next) {
                long this_id = hatom_getlong(&idelem->l_hatom);
                long this_tie = hatom_getlong(&tieelem->l_hatom);
                
                long l = 0; t_llllelem *tel;
                if (this_tie && // there was a tie
                    (is_long_in_llll_first_level(next_IDs, this_id) || // tied to "itself" (used by roll)
                     ((l = locate_long_in_llll_first_level(these_IDs, this_tie)) && (l >= 1 && l <= these_ties->l_size) && (tel = llll_getindex(these_ties, l, I_NON_NEGATIVE)) && hatom_getlong(&tel->l_hatom)))) // tied to something that was tied to something
                { // and the sequence of ties spanned across the element to be deleted
                    // we keep the tie
                    if (l) // transfer tie
                        hatom_setlong(&tieelem->l_hatom, hatom_getlong(&tel->l_hatom));
                } else if (this_tie) {
                    // KNOWN BUG: this causes issues with bach.score, because one may have a tie going from one note to another with different IDs
                    hatom_setlong(&tieelem->l_hatom, 0);	// we remove the tie
                    //                    if (QUANTIZE_MARK_TIED_INFOS && !tieelem->l_prev)
                    //                        these_infos->l_thing.w_obj = NULL;
                }
            }
            
            // clearing lthings
            for (t_llllelem *tmp = these_ties->l_head; tmp; tmp = tmp->l_next)
                tmp->l_thing.w_obj = NULL;
            
            hatom_change_to_llll_and_free(&prev_elem_ties->l_hatom, prev_ties);
            
            need_free_prev_ties = false;
        }
        
        
        // checking mcs
        if (x->regroup_delete != k_DELETE && !force_delete && allow_merging && this_duration.r_num > 0) {
            if (merging_direction <= 0) { // merged to left
                t_llllelem *elem, *elem2, *elem3;
                char prev_is_a_pause = (prev_duration.r_num < 0) ? true : false;
                if (x->regroup_delete == k_MERGE) {
                    long i;
                    t_llll *which_indices = llll_get();
                    
                    /*                    char debug1[1000], debug2[1000], debug3[1000];
                     llll_to_char_array(these_mc, debug1, 999);
                     llll_to_char_array(these_IDs, debug2, 999);
                     llll_to_char_array(prev_IDs, debug3, 999); */
                    
                    for (i = 0, elem = these_mc->l_head, elem2 = these_ties->l_head, elem3 = these_IDs->l_head;
                         elem;
                         i++, elem = elem->l_next, elem2 = elem2 ? elem2->l_next : NULL, elem3 = elem3 ? elem3->l_next : NULL) {
                        double this_double = hatom_getdouble(&elem->l_hatom);
                        long this_ID = elem3 ? hatom_getlong(&elem3->l_hatom) : -1;
                        if (this_ID > 0 && !is_long_in_llll_first_level(prev_IDs, this_ID)) {
                            //						if (!is_double_in_llll_first_level_with_tolerance(prev_mc, this_double, CONST_TOLERANCE_MC)) {
                            llll_appenddouble(prev_mc, this_double);
                            if (elem2)
                                llll_appendhatom_clone(prev_ties, &elem2->l_hatom);
                            else
                                llll_appendlong(prev_ties, 0);
                            llll_appendlong(which_indices, i + 1);
                        }	 
                    }
                    merge_infos(prev_infos, these_infos, prev_is_a_pause, which_indices); // the chosen indices
                    llll_free(which_indices);
                } else { // merge with repetitions
                    llll_chain_clone(prev_mc, these_mc);
                    llll_chain_clone(prev_ties, these_ties);
                    merge_infos(prev_infos, these_infos, prev_is_a_pause, NULL); // all indices
                }
                
                hatom_change_to_llll_and_free(&prev_elem_infos->l_hatom, prev_infos);
                
                
                if (merging_direction == 0) { // merged to both: special case: all prev elements are tied!
                    long length = prev_ties->l_size;
                    llll_free(prev_ties);
                    prev_ties = repeat_long(1, length);
                }
                
                if (need_free_prev_ties) 
                    hatom_change_to_llll_and_free(&prev_elem_ties->l_hatom, prev_ties);
                else
                    hatom_change_to_llll(&prev_elem_ties->l_hatom, prev_ties);
                
                need_free_prev_infos = false;
                need_free_prev_ties = false;
            } 
            
            if (merging_direction >= 0) { // merged to right
                t_llllelem *elem, *elem2, *elem3;
                char next_is_a_pause = (next_duration.r_num < 0) ? true : false;
                if (x->regroup_delete == k_MERGE) {
                    long i;
                    t_llll *which_indices = llll_get();
                    
                    for (i = 0, elem = these_mc->l_head, elem2 = these_ties->l_head, elem3 = these_IDs->l_head;
                         elem; 
                         i++, elem = elem->l_next, elem2 = elem2 ? elem2->l_next : NULL, elem3 = elem3 ? elem3->l_next : NULL) {
                        double this_double = hatom_getdouble(&elem->l_hatom);
                        long this_ID = elem3 ? hatom_getlong(&elem3->l_hatom) : -1;
                        if (this_ID > 0 && !is_long_in_llll_first_level(next_IDs, this_ID)) {
                            //						if (!is_double_in_llll_first_level_with_tolerance(next_mc, this_double, CONST_TOLERANCE_MC)) {
                            llll_appenddouble(next_mc, this_double);
                            if (elem2)
                                llll_appendhatom_clone(next_ties, &elem2->l_hatom);
                            else
                                llll_appendlong(next_ties, 0);
                            llll_appendlong(which_indices, i + 1);
                        }	
                    }
                    merge_infos(next_infos, these_infos, next_is_a_pause, which_indices); // the chosen indices
                    llll_free(which_indices);
                } else { // merge with repetitions
                    llll_chain_clone(next_mc, these_mc);
                    llll_chain_clone(next_ties, these_ties);
                    merge_infos(next_infos, these_infos, next_is_a_pause, NULL); // all indices
                }
                
                hatom_change_to_llll_and_free(&next_elem_infos->l_hatom, next_infos);
                hatom_change_to_llll_and_free(&next_elem_ties->l_hatom, next_ties);
                
                need_free_next_infos = false;
                need_free_next_ties = false;
            }
            
            // NO NEED!
            /*        } else if (this_duration.r_num == 0 && allow_merging) {
             
             // transfering info from a grace note to the next one
             // must transfer infos to next
             long i; t_llllelem *elem, *infoelem;
             
             for (i = 0, elem = these_IDs->l_head, infoelem = these_infos->l_head;
             elem && infoelem;
             i++, elem = elem->l_next, infoelem = infoelem->l_next) {
             long this_ID = elem ? hatom_getlong(&elem->l_hatom) : -1;
             long idx = locate_long_in_llll_first_level(next_IDs, this_ID);
             if (this_ID > 0 && idx >= 0 && hatom_gettype(&next_elem_infos->l_hatom) == H_LLLL) {
             t_llllelem *foundel = llll_getindex(hatom_getllll(&next_elem_infos->l_hatom), idx, I_STANDARD);
             if (foundel)
             hatom_change_to_hatom_clone_and_free(&foundel->l_hatom, &infoelem->l_hatom);
             }
             } */
        }
        
        llll_free(these_ties); 
        llll_free(these_mc);
        llll_free(these_infos); 
        llll_free(these_IDs);
        if (need_free_prev_mc) llll_free(prev_mc);
        if (need_free_prev_ties) llll_free(prev_ties);
        if (need_free_next_mc) llll_free(next_mc);
        if (need_free_next_ties) llll_free(next_ties);
        if (need_free_prev_infos) llll_free(prev_infos);
        if (need_free_next_infos) llll_free(next_infos);
        if (need_free_prev_IDs) llll_free(prev_IDs);
        if (need_free_next_IDs) llll_free(next_IDs);
        
        llll_destroyelem(rhythm_elem_to_delete);
        if (infos_elem_to_delete) llll_destroyelem(infos_elem_to_delete);
        llll_destroyelem(ties_elem_to_delete);
        
    }
}

void merge_infos(t_llll *where, t_llll *what, char where_is_a_pause, t_llll *which_indices) {
    // where_is_a_pause tells us if the *where llll is linked to a pause
    if (where_is_a_pause) { // was a pause
        llll_clear(where);
        llll_clone_upon(what, where);
    } else {
        if (where && where->l_head && what && what->l_head) {
            // mcs
            if (where->l_head && what->l_head && hatom_gettype(&where->l_head->l_hatom) == H_LLLL && hatom_gettype(&what->l_head->l_hatom) == H_LLLL) {
                t_llll *llll = hatom_getllll(&where->l_head->l_hatom);
                t_llll *lllltoappend = hatom_getllll(&what->l_head->l_hatom);
                llll_chain_clone_some_indices(llll, lllltoappend, which_indices);
            }
            // vel
            if (where->l_head && what->l_head && where->l_head->l_next && what->l_head->l_next && 
                hatom_gettype(&where->l_head->l_next->l_hatom) == H_LLLL && hatom_gettype(&what->l_head->l_next->l_hatom) == H_LLLL) {
                t_llll *llll = hatom_getllll(&where->l_head->l_next->l_hatom);
                t_llll *lllltoappend = hatom_getllll(&what->l_head->l_next->l_hatom);
                llll_chain_clone_some_indices(llll, lllltoappend, which_indices);
            }
            // extras
            if (where->l_head && what->l_head && where->l_head->l_next && what->l_head->l_next && where->l_head->l_next->l_next && what->l_head->l_next->l_next &&
                hatom_gettype(&where->l_head->l_next->l_next->l_hatom) == H_LLLL && hatom_gettype(&what->l_head->l_next->l_next->l_hatom) == H_LLLL) {
                t_llllelem *elem1 = hatom_getllll(&where->l_head->l_next->l_next->l_hatom)->l_head;
                t_llllelem *elem2 = hatom_getllll(&what->l_head->l_next->l_next->l_hatom)->l_head;
                for (elem1 = hatom_getllll(&where->l_head->l_next->l_next->l_hatom)->l_head, elem2 = hatom_getllll(&what->l_head->l_next->l_next->l_hatom)->l_head;
                     elem1 && elem2; elem1 = elem1->l_next, elem2 = elem2->l_next) {
                    if (hatom_gettype(&elem1->l_hatom) == H_LLLL && hatom_gettype(&elem2->l_hatom) == H_LLLL){
                        t_llll *llll = hatom_getllll(&elem1->l_hatom);
                        t_llll *lllltoappend = hatom_getllll(&elem2->l_hatom);
                        llll_chain_clone_some_indices(llll, lllltoappend, which_indices);
                    }
                } 
            }
            // IDs
            if (where->l_head && what->l_head && where->l_size >= 4 && what->l_size >= 4 &&
                hatom_gettype(&where->l_head->l_next->l_next->l_next->l_hatom) == H_LLLL && hatom_gettype(&what->l_head->l_next->l_next->l_next->l_hatom) == H_LLLL) {
                t_llll *llll = hatom_getllll(&where->l_head->l_next->l_next->l_next->l_hatom);
                t_llll *lllltoappend = hatom_getllll(&what->l_head->l_next->l_next->l_next->l_hatom);
                llll_chain_clone_some_indices(llll, lllltoappend, which_indices);
            }
        }
    }
}

char is_chord_as_llllelem_all_tied_to(t_llllelem *rhythm, t_llllelem *infos, t_llllelem *ties, t_llllelem *next_elem_infos){
    long num_ties = ties ? get_num_positives_in_llll(hatom_getllll(&ties->l_hatom)) : 0;
    t_llllelem *nextmcelem = info_to_midicents(next_elem_infos);
    long num_next_notes = nextmcelem && hatom_gettype(&nextmcelem->l_hatom) == H_LLLL ? hatom_getllll(&nextmcelem->l_hatom)->l_size : 0;
    if (num_ties <= num_next_notes){
        // checking each tie
        t_llllelem *this_mcelem = info_to_midicents(infos); 
        t_llll *this_mc = this_mcelem ? hatom_getllll(&this_mcelem->l_hatom) : NULL;
        t_llll *next_mc = nextmcelem ? hatom_getllll(&nextmcelem->l_hatom) : NULL;
        t_llllelem *elem;
        if (this_mc && next_mc) {
            for (elem = this_mc->l_head; elem; elem = elem->l_next)
                if (!is_double_in_llll_first_level_with_tolerance(next_mc, hatom_getdouble(&elem->l_hatom), CONST_TOLERANCE_MC))
                    return 0;
            return 1;
        }
    }
    return 0;
}

char is_chord_as_llllelem_all_tied_from(t_llllelem *rhythm, t_llllelem *infos, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties){
    long num_prev_ties = prev_elem_ties ? get_num_positives_in_llll(hatom_getllll(&prev_elem_ties->l_hatom)) : 0;
    t_llllelem *thismcelem = info_to_midicents(infos);
    long num_notes = thismcelem && hatom_gettype(&thismcelem->l_hatom) == H_LLLL ? hatom_getllll(&thismcelem->l_hatom)->l_size : 0;
    if (num_prev_ties <= num_notes){
        // checking each tie
        t_llll *this_mc = thismcelem ? hatom_getllll(&thismcelem->l_hatom) : NULL;
        t_llllelem *nextmcelem = info_to_midicents(prev_elem_infos);
        t_llll *prev_mc = nextmcelem ? hatom_getllll(&nextmcelem->l_hatom) : NULL;
        t_llllelem *elem;
        if (this_mc && prev_mc) {
            for (elem = this_mc->l_head; elem; elem = elem->l_next)
                if (!is_double_in_llll_first_level_with_tolerance(prev_mc, hatom_getdouble(&elem->l_hatom), CONST_TOLERANCE_MC))
                    return 0;
            return 1;
        }
    }
    return 0;
}

char in_chord_as_llllelem_all_notes_has_tie(t_llllelem *rhythm, t_llllelem *infos, t_llllelem *ties, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties, t_llllelem *next_elem_infos){
    t_llllelem *thismcelem = info_to_midicents(infos);
    t_llllelem *prevmcelem = info_to_midicents(prev_elem_infos);
    t_llllelem *nextmcelem = info_to_midicents(next_elem_infos);
    
    if (!thismcelem || !prevmcelem || !nextmcelem || !prev_elem_ties || !ties) {
        char completely_tied_to_next = is_chord_as_llllelem_all_tied_to(rhythm, infos, ties, next_elem_infos);
        char completely_tied_to_prev = is_chord_as_llllelem_all_tied_from(rhythm, infos, prev_elem_infos, prev_elem_ties);
        return (completely_tied_to_next || completely_tied_to_prev);
    }
    
    t_llll *this_mc = hatom_getllll(&thismcelem->l_hatom);
    t_llll *next_mc = hatom_getllll(&nextmcelem->l_hatom);
    t_llll *prev_mc = hatom_getllll(&prevmcelem->l_hatom);
    t_llllelem *elem, *tie_elem;
    
    if (!this_mc || !this_mc->l_head)
        return 0;
    
    if (hatom_gettype(&ties->l_hatom) != H_LLLL)
        return is_hatom_number(&ties->l_hatom) && hatom_getlong(&ties->l_hatom) ? 1 : 0;
    
    for (elem = this_mc->l_head, tie_elem = hatom_getllll(&ties->l_hatom)->l_head; elem && tie_elem; elem = elem->l_next, tie_elem = tie_elem->l_next) {
        char found = false;
        double this_mcs_double = hatom_getdouble(&elem->l_hatom);
        
        if (hatom_getlong(&tie_elem->l_hatom) >= 1 && is_double_in_llll_first_level_with_tolerance(next_mc, this_mcs_double, CONST_TOLERANCE_MC))
            found = true;
        
        if (!found) {
            t_llllelem *prevelem;
            t_llllelem *prevelem_ties;
            char are_ties_llll = (hatom_gettype(&prev_elem_ties->l_hatom) == H_LLLL);
            for (prevelem = prev_mc->l_head, prevelem_ties = are_ties_llll ? hatom_getllll(&prev_elem_ties->l_hatom)->l_head : prev_elem_ties; 
                 prevelem && prevelem_ties; 
                 prevelem = prevelem->l_next, prevelem_ties = are_ties_llll ? prevelem_ties->l_next : prevelem_ties)
                if (fabs(hatom_getdouble(&prevelem->l_hatom) - this_mcs_double) < CONST_TOLERANCE_MC && hatom_getlong(&prevelem_ties->l_hatom) >= 1) {
                    found = true;
                    break;
                }
        }
        
        if (!found)
            return 0;
    }
    return 1;
}

void merge_small_notes_inplace(t_quantize *x, t_llll **rhythm, t_llll **infos, t_llll **ties, 
                               t_llllelem *prev_elem_rhythm, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties, 
                               t_llllelem *next_elem_rhythm, t_llllelem *next_elem_infos, t_llllelem *next_elem_ties, 
                               t_llll *minimal_units) {
    // merge, when possible, the notes smaller than x->box_tie_percentage * minimum_unit
    t_rational minimum_unit = llll_min_of_plain_rat_llll(minimal_units);
    long num_next_chord_notes = next_elem_infos ? info_to_num_notes(next_elem_infos) : 0;
    long num_first_chord_notes = info_to_num_notes((*infos)->l_head);
    t_llllelem *rhythm_elem, *infos_elem, *ties_elem, *temp1, *temp2, *temp3;
    
    if (num_first_chord_notes == 0 && hatom_getrational(&(*rhythm)->l_head->l_hatom).r_num > 0)
        num_first_chord_notes = -5;
    
    if (num_next_chord_notes == 0 && next_elem_infos && hatom_getllll(&next_elem_infos->l_hatom)->l_size > 0 && 
        hatom_getrational(&hatom_getllll(&next_elem_infos->l_hatom)->l_head->l_hatom).r_num > 0)
        num_next_chord_notes = 1;
    else if (num_next_chord_notes == 0 && next_elem_rhythm && hatom_getrational(&next_elem_rhythm->l_hatom).r_num > 0)
        num_next_chord_notes = -5;
    
    // checking beginning and end
    if ((*rhythm) && (*rhythm)->l_size > 0) {
        while ((*rhythm)->l_size > 1 &&  
               ((is_all_llllelem_tied(prev_elem_ties, num_first_chord_notes) || hatom_getrational(&(*rhythm)->l_head->l_hatom).r_num < 0)) &&
               hatom_getrational(&(*rhythm)->l_head->l_hatom).r_num != 0 &&
               rat2double(rat_abs(hatom_getrational(&(*rhythm)->l_head->l_hatom))) <= x->box_tie_percentage * rat2double(minimum_unit) / 100.) {
            
            destroy_rhythm_element_or_turn_it_into_grace(x, (*rhythm)->l_head, (*infos)->l_head, (*ties)->l_head, prev_elem_rhythm, prev_elem_infos, prev_elem_ties, 
                                                         (*rhythm)->l_head->l_next, (*infos)->l_head ? (*infos)->l_head->l_next : NULL, (*ties)->l_head->l_next, false, false, minimum_unit);
        }
        
        while ((*rhythm)->l_size > 1  &&  
               ((is_all_llllelem_tied((*ties)->l_tail, num_next_chord_notes) || hatom_getrational(&(*rhythm)->l_tail->l_hatom).r_num < 0)) &&
               hatom_getrational(&(*rhythm)->l_tail->l_hatom).r_num != 0 &&
               rat2double(rat_abs(hatom_getrational(&(*rhythm)->l_tail->l_hatom))) <= x->box_tie_percentage * rat2double(minimum_unit) / 100.) {
            
            destroy_rhythm_element_or_turn_it_into_grace(x, (*rhythm)->l_tail, (*infos)->l_tail, (*ties)->l_tail, 
                                                         (*rhythm)->l_tail->l_prev, (*infos)->l_tail ? (*infos)->l_tail->l_prev : NULL, (*ties)->l_tail->l_prev, 
                                                         next_elem_rhythm, next_elem_infos, next_elem_ties, false, false, minimum_unit);
            
        }
    } 
    
    /*	char debug1[1000], debug2[1000], debug3[1000];
     llll_to_char_array(*rhythm, debug1, 999);
     llll_to_char_array(*infos, debug2, 999);
     llll_to_char_array(*ties, debug3, 999);*/
    
    // checking each element
    rhythm_elem = (*rhythm)->l_head;
    infos_elem = (*infos)->l_head;
    ties_elem = (*ties)->l_head;
    while (rhythm_elem && infos_elem && ties_elem) {
        t_rational this_dur = hatom_getrational(&rhythm_elem->l_hatom);
        char delete_elem = false;
        
        if (rat2double(rat_abs(this_dur)) <= x->dur_delete_percentage * rat2double(minimum_unit) / 100.)
            delete_elem = true;
        /*		else if	(x->regroup_delete == k_TURN_INTO_GRACE_CHORDS && this_dur.r_num == 0) {
         if (info_to_num_notes(infos_elem) == 0 && x->discard_grace_rests)
         delete_elem = true;
         else {
         char tied_to_next = is_chord_as_llllelem_all_tied_to(rhythm_elem, infos_elem, ties_elem, infos_elem->l_next ? infos_elem->l_next : next_elem_infos);
         char tied_to_prev = is_chord_as_llllelem_all_tied_from(rhythm_elem, infos_elem, infos_elem->l_prev ? infos_elem->l_prev : prev_elem_infos, ties_elem->l_prev ? ties_elem->l_prev : prev_elem_ties);
         if ((x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_NEXT && tied_to_next) ||
         (x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_PREV && tied_to_prev) ||
         (x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_NEXT_AND_PREV && tied_to_next && tied_to_prev) ||
         (x->discard_graces == k_DISCARD_GRACE_WHEN_TIED_TO_NEXT_OR_PREV && (tied_to_next || tied_to_prev)))
         delete_elem = true;
         }
         }*/
        
        if (delete_elem) {
            t_llllelem *prev_elem_rhythm_to_destroy, *prev_elem_infos_to_destroy, *prev_elem_ties_to_destroy, *next_elem_rhythm_to_destroy, *next_elem_infos_to_destroy, *next_elem_ties_to_destroy;
            prev_elem_infos_to_destroy = (infos_elem->l_prev) ? infos_elem->l_prev : prev_elem_infos;
            prev_elem_ties_to_destroy = (ties_elem->l_prev) ? ties_elem->l_prev : prev_elem_ties;
            prev_elem_rhythm_to_destroy = (rhythm_elem->l_prev) ? rhythm_elem->l_prev : prev_elem_rhythm;
            next_elem_infos_to_destroy = (infos_elem->l_next) ? infos_elem->l_next : next_elem_infos;
            next_elem_ties_to_destroy = (ties_elem->l_next) ? ties_elem->l_next : next_elem_ties;
            next_elem_rhythm_to_destroy = (rhythm_elem->l_next) ? rhythm_elem->l_next : next_elem_rhythm;
            temp1 = rhythm_elem->l_next;
            temp2 = infos_elem->l_next;
            temp3 = ties_elem->l_next;
            destroy_rhythm_element_or_turn_it_into_grace(x, rhythm_elem, infos_elem, ties_elem, 
                                                         prev_elem_rhythm_to_destroy, prev_elem_infos_to_destroy, prev_elem_ties_to_destroy, 
                                                         next_elem_rhythm_to_destroy, next_elem_infos_to_destroy, next_elem_ties_to_destroy, true, false, minimum_unit);
            //			char debug1[1000], debug2[1000], debug3[1000];
            //			llll_to_char_array(*rhythm, debug1, 999);
            //			llll_to_char_array(*infos, debug2, 999); //debug2+90
            //			llll_to_char_array(*ties, debug3, 999);
            rhythm_elem = temp1; 
            infos_elem = temp2;
            ties_elem = temp3;
        } else {
            rhythm_elem = rhythm_elem->l_next;
            infos_elem = infos_elem->l_next;
            ties_elem = ties_elem->l_next;
        }
    }
    
    /*	llll_to_char_array(*rhythm, debug1, 999);
     llll_to_char_array(*infos, debug2, 999);
     llll_to_char_array(*ties, debug3, 999);*/
}



void recheck_grace_notes_inplace(t_quantize *x, t_llll **rhythm, t_llll **infos, t_llll **ties, 
                                 t_llllelem *prev_elem_rhythm, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties, 
                                 t_llllelem *next_elem_rhythm, t_llllelem *next_elem_infos, t_llllelem *next_elem_ties) {
    // checking each element
    t_llllelem *rhythm_elem, *infos_elem, *ties_elem, *temp1, *temp2, *temp3;
    rhythm_elem = (*rhythm)->l_head;
    infos_elem = (*infos)->l_head;
    ties_elem = (*ties)->l_head;
    while (rhythm_elem && infos_elem && ties_elem) {
        t_rational this_dur = hatom_getrational(&rhythm_elem->l_hatom);
        if (this_dur.r_num == 0){
            t_llllelem *prev_elem_rhythm_to_destroy, *prev_elem_infos_to_destroy, *prev_elem_ties_to_destroy, 
            *next_elem_rhythm_to_destroy, *next_elem_infos_to_destroy, *next_elem_ties_to_destroy;
            prev_elem_infos_to_destroy = (infos_elem->l_prev) ? infos_elem->l_prev : prev_elem_infos;
            prev_elem_ties_to_destroy = (ties_elem->l_prev) ? ties_elem->l_prev : prev_elem_ties;
            prev_elem_rhythm_to_destroy = (rhythm_elem->l_prev) ? rhythm_elem->l_prev : prev_elem_rhythm;
            next_elem_infos_to_destroy = (infos_elem->l_next) ? infos_elem->l_next : next_elem_infos;
            next_elem_ties_to_destroy = (ties_elem->l_next) ? ties_elem->l_next : next_elem_ties;
            next_elem_rhythm_to_destroy = (rhythm_elem->l_next) ? rhythm_elem->l_next : next_elem_rhythm;
            temp1 = rhythm_elem->l_next;
            temp2 = infos_elem->l_next;
            temp3 = ties_elem->l_next;
            destroy_rhythm_element_or_turn_it_into_grace(x, rhythm_elem, infos_elem, ties_elem, 
                                                         prev_elem_rhythm_to_destroy, prev_elem_infos_to_destroy, prev_elem_ties_to_destroy, 
                                                         next_elem_rhythm_to_destroy, next_elem_infos_to_destroy, next_elem_ties_to_destroy, true, true, long2rat(-1)); // -1 is to avoid grace notes elimination
            rhythm_elem = temp1; 
            infos_elem = temp2;
            ties_elem = temp3;
        } else {
            rhythm_elem = rhythm_elem->l_next;
            infos_elem = infos_elem->l_next;
            ties_elem = ties_elem->l_next;
        }
    }
}




char quantize_box_single_step_inplace(t_quantize *x, t_llll **rhythm, t_llll *minimal_units) {
    t_llll *rhythm_quantized;
    char res; 
    char need_perform_inverse_permutation = 0;
    long size = (*rhythm)->l_size;
    t_llll *permutation = get_arithmser(1, size, 1);
    t_llll **lists_to_order = (t_llll **) bach_newptr(2 * sizeof(t_llll *));
    
    if (x->verbose){
        char *rhythm_string = NULL;
        llll_to_text_buf(*rhythm, &rhythm_string, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
        object_post((t_object *) x, "• Rhythm in: %s", rhythm_string);
        bach_freeptr(rhythm_string);
    }
    
    // choosing quantizing priorities, and sorting *rhythm accordingly
    if (x->quantization_priority == k_BACKWARDS) {
        llll_rev(*rhythm, 1, 2);
        llll_rev(permutation, 1, 2);
        need_perform_inverse_permutation = 1;
    } else if (x->quantization_priority != k_LINEAR) {
        lists_to_order[0] = *rhythm; 
        lists_to_order[1] = permutation; 
        llll_multisort(lists_to_order, lists_to_order, 2, choose_appropriate_sorting_function(x));
        *rhythm = lists_to_order[0]; 
        permutation = lists_to_order[1];
        need_perform_inverse_permutation = 2;
    }
    
    // real quantization
    res = quantize_box_single_step(x, *rhythm, &rhythm_quantized, minimal_units);
    
    // performing inverse permutation, setting things properly
    if (need_perform_inverse_permutation == 1) {
        llll_rev(*rhythm, 1, 2);
        llll_rev(permutation, 1, 2);
    } else if (need_perform_inverse_permutation == 2) {
        lists_to_order[0] = permutation; 
        lists_to_order[1] = rhythm_quantized; 
        llll_multisort(lists_to_order, lists_to_order, 2, llll_leq_elem); // just <=
        permutation = lists_to_order[0]; 
        rhythm_quantized = lists_to_order[1]; 
    }
    if (x->verbose){
        char *rhythm_string = NULL;
        llll_to_text_buf(rhythm_quantized, &rhythm_string, 0, BACH_DEFAULT_MAXDECIMALS, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_NONE, NULL);
        object_post((t_object *) x, "• Rhythm out: %s", rhythm_string);
        bach_freeptr(rhythm_string);
    }
    
    llll_free(*rhythm);
    llll_free(permutation);
    *rhythm = rhythm_quantized;
    bach_freeptr(lists_to_order);
    return res;
}

t_llll *get_minimal_units_from_density(t_quantize *x, t_rational density){
    t_llllelem *elem;
    double density_double = rat2double(density);
    t_llll *minimal_units_out = NULL;
    
    //	if (!x->dynamic_minimal_units || x->dynamic_minimal_units->l_size == 0) 
    //		return NULL;
    
    if (x->dynamic_minimal_units && x->dynamic_minimal_units->l_depth > 2) { // old way
        for (elem = x->dynamic_minimal_units->l_head; elem; elem = elem->l_next) {
            if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                t_llll *this_llll = hatom_getllll(&elem->l_hatom);
                if (this_llll && this_llll->l_size >= 2){
                    if ((hatom_gettype(&this_llll->l_head->l_hatom) == H_DOUBLE || hatom_gettype(&this_llll->l_head->l_hatom) == H_LONG || hatom_gettype(&this_llll->l_head->l_hatom) == H_RAT) &&
                        hatom_gettype(&this_llll->l_head->l_next->l_hatom) == H_LLLL) {
                        if (!minimal_units_out || hatom_getdouble(&this_llll->l_head->l_hatom) < density_double)
                            minimal_units_out = hatom_getllll(&this_llll->l_head->l_next->l_hatom);
                        else if (hatom_getdouble(&this_llll->l_head->l_hatom) >= density_double)
                            break;
                    }
                }
            }
        }
        if (!minimal_units_out && x->dynamic_minimal_units && x->dynamic_minimal_units->l_tail 
            && hatom_gettype(&x->dynamic_minimal_units->l_tail->l_hatom) == H_LLLL
            && hatom_getllll(&x->dynamic_minimal_units->l_tail->l_hatom)->l_size > 2
            && hatom_getllll(&x->dynamic_minimal_units->l_tail->l_hatom)->l_head->l_next->l_hatom.h_type == H_LLLL) {
            minimal_units_out = hatom_getllll(&x->dynamic_minimal_units->l_tail->l_hatom)->l_head->l_next->l_hatom.h_w.w_llll;
        }
        
    } else if (x->minimal_units->l_head && x->minimal_units->l_head->l_next){
        // new way
        
        for (elem = x->minimal_units->l_head->l_next; elem; elem = elem->l_next) {
            if (hatom_gettype(&elem->l_hatom) == H_LLLL) 
                minimal_units_out = hatom_getllll(&elem->l_hatom);
            else if (is_hatom_number(&elem->l_hatom)){
                if (hatom_getdouble(&elem->l_hatom) >= density_double)
                    break;
            }
        }
        if (!minimal_units_out && x->minimal_units) {
            t_llllelem *elem;
            for (elem = x->minimal_units->l_head->l_next; elem; elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_LLLL){
                    minimal_units_out = hatom_getllll(&elem->l_hatom);
                    break;
                }
            }
        }
    }
    
    
    return minimal_units_out;
}


void quantize_clone_upon_with_lthings(t_llll *from, t_llll *to)
{
    for (t_llllelem *elem = from->l_head; elem; elem = elem->l_next)
        llll_appendelem_clone_preserve_lthing(to, elem, 0, WHITENULL_llll);
}

void quantize_box(t_quantize *x, t_rational box_width, t_llll *box_durations, t_llll *box_infos, t_llll *box_ties, 
                  t_llll **quantized_box_durations, t_llll **quantized_box_infos, t_llll **quantized_box_ties, 
                  t_llllelem *prev_elem_rhythm, t_llllelem *prev_elem_infos, t_llllelem *prev_elem_ties, 
                  t_llllelem *next_elem_rhythm, t_llllelem *next_elem_infos, t_llllelem *next_elem_ties)
{
    // we take as arguments also some info about the prev and next chords, i.e. : the LAST chord of the previous box (prev) and the FIRST chord of the next box
    // they'll be useful to handle ties questions while merging/deleting chords
    
    long res = false;
    long count_merging_cycles = 0;
    t_llll *minimal_units;
    t_llll *box_durations_wk = llll_get(), *box_infos_wk = llll_get(), *box_ties_wk = llll_get(); // working-clones of the durations/infos/ties
    t_rational density;
    
#ifdef BACH_QUANTIZE_DEBUG
    char debug1[1000], debug2[1000], debug3[1000];
#endif
    
    
    if (x->verbose)
        object_post((t_object *) x, "============ bach.quantize: quantization step (box width: %ld/%ld) ============", box_width.r_num, box_width.r_den);
    
    systhread_mutex_lock(x->n_mutex);
    quantize_clone_upon_with_lthings(box_durations, box_durations_wk);
    quantize_clone_upon_with_lthings(box_infos, box_infos_wk);
    quantize_clone_upon_with_lthings(box_ties, box_ties_wk);
    systhread_mutex_unlock(x->n_mutex);
    
    /*
     llll_print(hatom_getllll(&prev_elem_infos->l_hatom));
     llll_print(box_infos);
     llll_print(hatom_getllll(&next_elem_infos->l_hatom));
     */
    if (box_durations_wk && box_durations_wk->l_size > 0) {
        
        // pre-treatments: merging and approximating
        approximate_for_too_high_rationals_fixed_den(box_durations_wk, box_width, CONST_RAT_SINGLE_DEN);
        merge_rests_and_alltied_chords_from_separate_parameters_inplace(&box_durations_wk, &box_infos_wk, &box_ties_wk, NULL, NULL, QUANTIZE_MERGE_WHEN);
        
        density = long_rat_div(box_durations_wk->l_size, box_width);
        
        // retrieving minimal_units
        if (x->use_dynamic_minimal_units)
            minimal_units = get_minimal_units_from_density(x, density); // dynamic minimal units
        else {
            if (x->minimal_units->l_depth >= 2){ // minimal units depend on voice
                t_llllelem *nth_el = llll_getindex(x->minimal_units, CLAMP(x->current_voice_being_quantized, 1, (long)x->minimal_units->l_size), I_MODULO);
                if (hatom_gettype(&nth_el->l_hatom) == H_LLLL)
                    minimal_units = hatom_getllll(&nth_el->l_hatom);
                else
                    minimal_units = x->minimal_units;
            } else
                minimal_units = x->minimal_units; // static minimal units
        }
        
        approximate_for_too_high_rationals_fixed_den(box_durations_wk, box_width, CONST_RAT_SINGLE_DEN);
        
#ifdef BACH_QUANTIZE_DEBUG
        llll_to_char_array(box_durations_wk, debug1, 999);
        llll_to_char_array(box_infos_wk, debug2, 999); 
        llll_to_char_array(box_ties_wk, debug3, 999);
#endif
        
        merge_small_notes_inplace(x, &box_durations_wk, &box_infos_wk, &box_ties_wk, prev_elem_rhythm, prev_elem_infos, prev_elem_ties, next_elem_rhythm, next_elem_infos, next_elem_ties, minimal_units);
        
#ifdef BACH_QUANTIZE_DEBUG
        llll_to_char_array(box_durations_wk, debug3, 999);
        llll_to_char_array(box_infos_wk, debug2, 999);
        llll_to_char_array(box_ties_wk, debug1, 999);
#endif
        
        // if using dynamic minimal units, we check density again (it might have changed, since too small notes might have been deleted)
        if (x->use_dynamic_minimal_units)
            minimal_units = get_minimal_units_from_density(x, long_rat_div(box_durations_wk->l_size, box_width));
        
        if (!minimal_units) { // error!
            object_error((t_object *) x, "Error: can't get dynamic minimal units! Please check your dynamicminimalunits information.");
            object_error((t_object *) x, "   Using statical minimal units instead.");
            minimal_units = x->minimal_units; // using static minimal units
        }
        
        
        // real box quantization
        res = quantize_box_single_step_inplace(x, &box_durations_wk, minimal_units);
        
        while (!res && (long)box_durations_wk->l_size > 1 && count_merging_cycles <= (long)box_durations->l_size) { // unsuccessful: we try to regroup/delete
            t_rational smallest_minimal_unit = llll_min_of_plain_rat_llll(minimal_units);
            
            if (x->verbose) {
                object_post((t_object *) x, "• No solution was found. We discard some elements.");
                object_post((t_object *) x, "  --------");
            }
            
            approximate_for_too_high_rationals_fixed_den(box_durations_wk, box_width, CONST_RAT_SINGLE_DEN);
            
            /*			dev_post("----B");
             llll_print_named(box_durations_wk, gensym("durations_wk"), 0, 2, NULL);
             llll_print_named(box_infos_wk, gensym("infos_wk"), 0, 2, NULL);
             llll_print_named(box_ties_wk, gensym("ties_wk"), 0, 2, NULL);
             */
            regroup_delete_fastest_element(x, box_durations_wk, box_infos_wk, box_ties_wk, prev_elem_rhythm, prev_elem_infos, prev_elem_ties, next_elem_rhythm, next_elem_infos, next_elem_ties, smallest_minimal_unit);
            /*
             dev_post("----C");
             llll_print_named(box_durations_wk, gensym("durations_wk"), 0, 2, NULL);
             llll_print_named(box_infos_wk, gensym("infos_wk"), 0, 2, NULL);
             llll_print_named(box_ties_wk, gensym("ties_wk"), 0, 2, NULL);
             */
            approximate_for_too_high_rationals_fixed_den(box_durations_wk, box_width, CONST_RAT_SINGLE_DEN);
            
            // TO DO: don't make him recompute ALL approximation possibilities! just the one that changed...
            approximate_for_too_high_rationals_fixed_den(box_durations_wk, box_width, CONST_RAT_SINGLE_DEN);
            
            merge_rests_and_alltied_chords_from_separate_parameters_inplace(&box_durations_wk, &box_infos_wk, &box_ties_wk, NULL, NULL, QUANTIZE_MERGE_WHEN);
            
            // real box quantization
            res = quantize_box_single_step_inplace(x, &box_durations_wk, minimal_units);
            count_merging_cycles++;
        } 
        
        if (x->regroup_delete == k_TURN_INTO_GRACE_CHORDS)
            recheck_grace_notes_inplace(x, &box_durations_wk, &box_infos_wk, &box_ties_wk, prev_elem_rhythm, prev_elem_infos, prev_elem_ties, next_elem_rhythm, next_elem_infos, next_elem_ties);
        
    }
    
    *quantized_box_durations = box_durations_wk;
    *quantized_box_infos = box_infos_wk;
    *quantized_box_ties = box_ties_wk;
    
#ifdef BACH_QUANTIZE_DEBUG
    llll_to_char_array(box_durations_wk, debug3, 999);
    llll_to_char_array(box_infos_wk, debug2, 999);
    llll_to_char_array(box_ties_wk, debug1, 999);
#endif
}


// ********** SORTING PRIORITIES FUNCTIONS *********

// gotta pass the t_quantize *x as first argument!
sort_fn choose_appropriate_sorting_function(t_quantize *x) {
    switch (x->quantization_priority) {
        case k_NOTES_FIRST_DECREASING:
            return (sort_fn) llll_order_rationals_notes_first_decreasing_fn;
            break;
        case k_NOTES_FIRST_INCREASING:
            return (sort_fn) llll_order_rationals_notes_first_increasing_fn;
            break;
        case k_RESTS_FIRST_DECREASING:
            return (sort_fn) llll_order_rationals_rests_first_decreasing_fn;
            break;
        case k_RESTS_FIRST_INCREASING:
            return (sort_fn) llll_order_rationals_rests_first_increasing_fn;
            break;
        default:
            return (sort_fn) llll_order_linear_fn;
    }
    return NULL;
}

long llll_order_linear_fn(void *dummy, t_llllelem *a, t_llllelem *b) {
    return 1; // everything is always ok
}

// order putting note first, in decreasing order (bigger notes first, then smaller notes, then bigger rests, then smaller rests)
long llll_order_rationals_notes_first_decreasing_fn(void *dummy, t_llllelem *a, t_llllelem *b) {
    if ((hatom_gettype(&a->l_hatom) == H_RAT || hatom_gettype(&a->l_hatom) == H_LONG || hatom_gettype(&a->l_hatom) == H_DOUBLE) && 
        (hatom_gettype(&b->l_hatom) == H_RAT || hatom_gettype(&b->l_hatom) == H_LONG || hatom_gettype(&b->l_hatom) == H_DOUBLE)) {
        t_rational a_r = hatom_getrational(&a->l_hatom);
        t_rational b_r = hatom_getrational(&b->l_hatom);
        if (a_r.r_num < 0 && b_r.r_num > 0)
            return 0;
        
        if (a_r.r_num < 0 && b_r.r_num < 0 && rat_rat_cmp(rat_abs(a_r), rat_abs(b_r)) < 0)
            return 0;
        
        if (a_r.r_num > 0 && b_r.r_num > 0 && rat_rat_cmp(a_r, b_r) < 0)
            return 0;
        
        return 1;
    }
    return 1;
}

// order putting note first, in increasing order (smaller notes first, then bigger notes, then smaller rests, then bigger rests)
long llll_order_rationals_notes_first_increasing_fn(void *dummy, t_llllelem *a, t_llllelem *b) {
    if ((hatom_gettype(&a->l_hatom) == H_RAT || hatom_gettype(&a->l_hatom) == H_LONG || hatom_gettype(&a->l_hatom) == H_DOUBLE) && 
        (hatom_gettype(&b->l_hatom) == H_RAT || hatom_gettype(&b->l_hatom) == H_LONG || hatom_gettype(&b->l_hatom) == H_DOUBLE)) {
        t_rational a_r = hatom_getrational(&a->l_hatom);
        t_rational b_r = hatom_getrational(&b->l_hatom);
        if (a_r.r_num < 0 && b_r.r_num > 0)
            return 0;
        
        if (a_r.r_num < 0 && b_r.r_num < 0 && rat_rat_cmp(rat_abs(a_r), rat_abs(b_r)) > 0)
            return 0;
        
        if (a_r.r_num > 0 && b_r.r_num > 0 && rat_rat_cmp(a_r, b_r) > 0)
            return 0;
        
        return 1;
    }
    return 1;
}


long llll_order_rationals_rests_first_decreasing_fn(void *dummy, t_llllelem *a, t_llllelem *b) {
    if ((hatom_gettype(&a->l_hatom) == H_RAT || hatom_gettype(&a->l_hatom) == H_LONG || hatom_gettype(&a->l_hatom) == H_DOUBLE) && 
        (hatom_gettype(&b->l_hatom) == H_RAT || hatom_gettype(&b->l_hatom) == H_LONG || hatom_gettype(&b->l_hatom) == H_DOUBLE)) {
        t_rational a_r = hatom_getrational(&a->l_hatom);
        t_rational b_r = hatom_getrational(&b->l_hatom);
        if (a_r.r_num > 0 && b_r.r_num < 0)
            return 0;
        
        if (a_r.r_num < 0 && b_r.r_num < 0 && rat_rat_cmp(rat_abs(a_r), rat_abs(b_r)) < 0)
            return 0;
        
        if (a_r.r_num > 0 && b_r.r_num > 0 && rat_rat_cmp(a_r, b_r) < 0)
            return 0;
        
        return 1;
    }
    return 1;
}


long llll_order_rationals_rests_first_increasing_fn(void *dummy, t_llllelem *a, t_llllelem *b) {
    if ((hatom_gettype(&a->l_hatom) == H_RAT || hatom_gettype(&a->l_hatom) == H_LONG || hatom_gettype(&a->l_hatom) == H_DOUBLE) && 
        (hatom_gettype(&b->l_hatom) == H_RAT || hatom_gettype(&b->l_hatom) == H_LONG || hatom_gettype(&b->l_hatom) == H_DOUBLE)) {
        t_rational a_r = hatom_getrational(&a->l_hatom);
        t_rational b_r = hatom_getrational(&b->l_hatom);
        if (a_r.r_num > 0 && b_r.r_num < 0)
            return 0;
        
        if (a_r.r_num < 0 && b_r.r_num < 0 && rat_rat_cmp(rat_abs(a_r), rat_abs(b_r)) > 0)
            return 0;
        
        if (a_r.r_num > 0 && b_r.r_num > 0 && rat_rat_cmp(a_r, b_r) > 0)
            return 0;
        
        return 1;
    }
    return 1;
}
