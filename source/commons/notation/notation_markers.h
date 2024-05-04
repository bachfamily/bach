/*
 *  notation_marker.h
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
	@file	notation_markers.h
*/

#ifndef _NOTATION_MARKERS_H_
#define _NOTATION_MARKERS_H_

#include "foundation/bach.h"
#include "notation/notation.h" // header with all the structures for the notation objects
#include "notation/notation_undo.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif


//TBD
double marker_get_onset_ms(t_notation_obj *r_ob, t_marker *marker);
double marker_get_onset_ux(t_notation_obj *r_ob, t_marker *marker);
double marker_region_get_end_ms(t_notation_obj *r_ob, t_marker *marker, char for_painting);
double marker_region_get_end_ux(t_notation_obj *r_ob, t_marker *marker, char for_painting);
double marker_region_get_width(t_notation_obj *r_ob, t_marker *marker, char for_painting);
double marker_region_get_duration_ms(t_notation_obj *r_ob, t_marker *marker, char for_painting);

void marker_region_preselect_all_items(t_notation_obj *r_ob, t_marker *marker);
void marker_llllelem_to_onset_and_region_properties(t_notation_obj *r_ob, t_llllelem *el, double *onset_ms, double *dur_ms, t_timepoint *onset_timepoint, t_rational *symdur, char *attach_to);



/**    Tell if a point is on a given marker.
 @ingroup            notation_graphic
 @param     r_ob        The notation object
 @param    marker      The marker
 @param    point_x        The x coordinate of the point (pixel)
 @param    point_y        The y coordinate of the point (pixel)
 @return                1 if the point is over the marker, 0 otherwise.
 */
int is_in_marker_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y);


/**    Tell if a point is on a given marker name.
 @ingroup            notation_graphic
 @param     r_ob        The notation object
 @param    marker      The marker
 @param    point_x        The x coordinate of the point (pixel)
 @param    point_y        The y coordinate of the point (pixel)
 @return                1 if the point is over the marker name, 0 otherwise.
 */
int is_in_markername_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y);

/**    Tell if a point is on a given marker's region strip shape.
 @ingroup            notation_graphic
 @param     r_ob        The notation object
 @param    marker      The marker
 @param    point_x        The x coordinate of the point (pixel)
 @param    point_y        The y coordinate of the point (pixel)
 @return                1 if the point is over the region stripe, 0 otherwise.
 */
int is_in_marker_region_stripe_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y);


int is_in_marker_region_tail_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y, char consider_region_markers_only);


// TBD
char marker_is_region(t_marker *mk);
char marker_is_region_till_next(t_marker *mk);
double marker_get_voffset(t_notation_obj *r_ob, t_marker *mk);
double marker_get_top_y(t_notation_obj *r_ob, t_marker *mk);




/** Get the unscaled x position of the marker.
 @ingroup            markers
 @param    r_ob        The notation object
 @param    marker      The marker
 @return                The unscaled x position of the marker
 */
double marker_get_onset_ux(t_notation_obj *r_ob, t_marker *marker);


/** Get the marker onset in milliseconds.
 @ingroup            markers
 @param    r_ob        The notation object
 @param    marker      The marker
 @return                The marker onset in milliseconds
 */
double marker_get_onset_ms(t_notation_obj *r_ob, t_marker *marker);


/** Obtain all the markers as an llll containing (<position_ms> <name>) for each marker.
 @ingroup            markers
 @param    r_ob        The notation object
 @param    mode        If this is 1, the algorithm only returns the markers within a given "temporal window" (specified by the following paramters)
 If this is 0, all the markers are given.
 @param    start_ms    If <mode> = 1, this is the starting position of the window in milliseconds (otherwise ignored)
 @param    end_ms        If <mode> = 1, this is the ending position of the window in milliseconds (otherwise ignored)
 @param    namefirst    If this is non-zero, the llll for each marker will be (<name> <position_ms>)
 @param    for_what    This should be usually one of #k_CONSIDER_FOR_DUMPING, #k_CONSIDER_FOR_SUBDUMPING, #k_CONSIDER_FOR_UNDO or #k_CONSIDER_FOR_SCORE2ROLL.
 @param    start_meas_num    If <for_what> is #k_CONSIDER_FOR_SUBDUMPING and <r_ob> is a bach.score, this is the starting measure number for clipping (so that the dumped
 information will be with respect to this measure as the starting one).
 @param    keep_ending_markers  When cropping from start_ms to end_ms keep markers falling exactly on end_ms
 @return                The markers' positions and names as llll.
 @see                marker_get_as_llll()
 */
t_llll *get_markers_as_llll(t_notation_obj *r_ob, char mode, double start_ms, double end_ms, char namefirst, char for_what, long start_meas_num, char keep_ending_markers);


/** Get an llll containing the information about a specific marker (or about all the markers)
 @ingroup            markers
 @param    r_ob        The notation object
 @param    marker        The marker whose information has to be got, or NULL if you need the information about all markers
 @param    namefirst    If this is 1, the usual (<position_ms> <name>) coupling is reversed for each marker, and becomes (<name> <position_ms>).
                            If this is 0, the syntax is the usual (<position_ms> <name>).
 @param   prepend_marker_symbol  Also prepend a "marker" symbol to the output
 @param   mode       One of the #e_data_considering_types
 @return                A list containing the information about a single marker or all markers.
 @remark                Differntly from get_markers_as_llll(), the information we get can have names first and can concern a single marker
                        (but cannot concern a temporal window).
 @see                get_markers_as_llll()
 */
t_llll *marker_get_as_llll(t_notation_obj *r_ob, t_marker *marker, char namefirst, char prepend_marker_symbol, e_data_considering_types mode);


/** Set all markers of a given notation objet from a list of markers in the usual syntax (<position_ms> <name>) (<position_ms> <name>) ...
 @ingroup            markers
 @remark                Beware: this function does NOT free the markers llll, but might DELETE some parts of it!!!
 @param    r_ob        The notation object
 @param    markers        The llll determining the markers, in the above explained syntax
 @param    add_mode    If this is 1, the markers will be added to the existing ones, otherwise the existing ones will be removed
 @param    select      If this is 1, the markers will be added to the current selection
 @param    add_undo_ticks    If non-zero, also adds the undo ticks
 @see                marker_get_as_llll()
 */
void set_markers_from_llll(t_notation_obj *r_ob, t_llll* markers, char add_mode, char select, char add_undo_ticks);




/** Change a marker name (and recompute also the <name_uwidth> flag accordingly).
    @ingroup            markers
    @param    r_ob        The notation object
    @param    marker        The marker
    @param    new_names    The new marker's name as an llll
    @see                recalculate_marker_name_uwidth()
    @return                1 if the new name is different from the old one, 0 otherwise
 */
long change_marker_names(t_notation_obj *r_ob, t_marker *marker, t_llll *new_names);


/** Properly fill the <name_uwidth> field of a marker, contaning the unscaled width of the marker name label
    @ingroup            markers
    @param    r_ob        The notation object
    @param    marker        The marker
 */
void recalculate_marker_name_uwidth(t_notation_obj *r_ob, t_marker *marker);


/** Change a marker position in milliseconds.
    @ingroup                    markers
    @param    r_ob                The notation object
    @param    marker                The marker
    @param    new_ms                The new marker's position in ms
    @param    delta_mode            If this is 1, the <new_ms> value will be added to the marker's milliseconds. Otherwise they'll be replaced.
    @param    also_check_sorting    If this is 1, also the algorithm checks the correct ordering of all markers, increasing with respect to the <position_ms> field.
 */
void change_marker_ms(t_notation_obj *r_ob, t_marker *marker, double new_ms, char delta_mode, char also_check_sorting);


/** Change a marker role.
    @ingroup                    markers
    @param    r_ob                The notation object
    @param    marker                The marker
    @param    new_role            The new marker's role, as one of the #e_marker_roles
 */
void change_marker_role(t_notation_obj *r_ob, t_marker *marker, e_marker_roles new_role);

/** Interpret a symbol as a marker role (one of the #e_marker_roles).
    For gensym("timesig") is interpreted as #k_MARKER_ROLE_TIME_SIGNATURE.
    @ingroup            markers
    @param    s            The symbol
    @return                The element of #e_marker_roles corresponding to the symbol
 */
e_marker_roles sym_to_marker_role(t_symbol *s);


/** Convert a marker role into a symbol.
    For instance #k_MARKER_ROLE_TIME_SIGNATURE is translated into _llllobj_sym_tempo = gensym("timesig").
    @ingroup            markers
    @param    marker_role    One of the #e_marker_roles
    @return                The symbol corresponding to the marker role.
 */
t_symbol *marker_role_to_sym(e_marker_roles marker_role);


/** (Internal) Shifts the selected markers depending on the current mousedown marker
    @ingroup            markers
    @param    r_ob        The notation object
    @param    marker_with_mousedown_ux    The ux position of the marker currently having the mousedown
    @param    magnetic    If non-zero, snaps to the nearest chord
    @param    delta_ms    If non-NULL, will be filled with the actual movement in milliseconds
    @return                1 if something has changed, 0 otherwise
 */
char move_selected_ms_attached_markers(t_notation_obj *r_ob, double marker_with_mousedown_ux, char magnetic, double *delta_ms);


/** Shift the selected markers by an amount (in milliseconds)
    @ingroup            markers
    @param    r_ob        The notation object
    @param    delta_ms    The amount of the shift (in milliseconds)
    @param    magnetic    If non-zero, snaps to the nearest chord
    @return                1 if something has changed, 0 otherwise
 */
char move_selected_ms_attached_markers_delta(t_notation_obj *r_ob, double delta_ms);


/** Find the first incremental numbered unused marker name similar to a given name.
    For instance, if the given name is "foo", he'll try to search for "foo 1", "foo 2"... up to "foo 100000",
    and if any of these is NOT used, it returns the corresponding atom array (usually with length 2, unless the introduced
    marker name was a long atom, in this case the output length will be 1, since the number will be tried to be incremented).
    If no incremental free names could be found, the original name be copied.
    @ingroup                    markers
    @param    r_ob                The notation object
    @param    default_name        The base atom for building the incremental numbered sequence
    @param    ignore_this_marker    A marker which can be ignored while searching for an unused name.
                                For instance, when trying to make a given marker's name unique, one can ignore the marker itself.
                                Leave it to NULL for standard behavior.
    @return                        The llll of unused incrementally numbered name found.
    @remark                        To avoid confusions, you might want to be sure that the <default_name> has no numbers at the end.
                                If you want to make a name unique, use make_marker_name_unique().
 */
t_llll *find_unused_marker_names(t_notation_obj *r_ob, t_hatom *default_name, t_marker *ignore_this_marker);


/** Make a marker name unique, by changing its numerical suffix.
    For instance, it might change "foo2" to "foo5", if all "foo2", "foo3" and "foo4" are already taken
    @ingroup        markers
    @param    r_ob    The notation object
    @param    names    The original names
    @return            The first unused incrementally numered name found as llll.
    @param    num_found_names        Pointer filled with the number of names found (length of #found_names)
 */
t_llll *make_marker_name_unique(t_notation_obj *r_ob, t_llll *names);


/** Change the name of the selected markers to a new name.
    @ingroup            selection_changes
    @param    r_ob        The notation object
    @param    new_names    The new marker names as llll
    @param    incremental    If this is 1, every name will be made unique by incrementing its numerical suffix
    @return                1 if something has changed, 0 otherwise.
 */
char change_selected_markers_name(t_notation_obj *r_ob, t_llll *new_names, char incremental);


/** Retrieve the timepoint of a measure-attached-marker (for [bach.score]).
    @remark                Indeed the marker structure only contains the ID of the measure to which it is attached, and the symbolic offset inside the measure,
                        but it does not contain the precise timepoint.
    @ingroup            markers
    @param    r_ob        The notation object
    @param    marker        The marker
    @return                The timepoint of the marker
 */
t_timepoint measure_attached_marker_to_timepoint(t_notation_obj *r_ob, t_marker *marker);


/** Change the onset of a marker (and possibly its attachment type) either from a lexpr
    containing the new milliseconds position or (if this latter is NULL), from a llllelem containing either the milliseconds position, or the new
    timepoint (measure_number point_in_measure) or (measure_number point_in_measure voice_number)
    @remark                Does NOT check the correct markers order, need to do it later via check_markers_order()
    @ingroup            markers
    @param    r_ob        The notation object
    @param    marker        The marker
    @param    lexpr        The lexpr
    @param    elem        The llllelem
 */
void change_marker_onset_from_lexpr_or_llllelem(t_notation_obj *r_ob, t_marker *marker, t_lexpr *lexpr, t_llllelem *elem);




// -----------------------------------
// MARKERS
// -----------------------------------

/** Build a new marker. This function allocate the memory and set fields to the correct values (depending from the arguments)
    @ingroup        markers
    @param    r_ob    The notation object
    @param    names    The name(s) of the marker (as llll)
    @param    ms        The position in milliseconds of the marker
    @param    tp        The timepoint of the marker (only makes sense with [bach.score])
    @param    attach_to    One of the #e_marker_attach, deciding to what the marker should be attached. By default, it should be #k_MARKER_ATTACH_TO_MS.
    @param    role        One of the #e_marker_roles, possibly specifying the special role of the marker
    @param    content        If the role is NOT #k_MARKER_ROLE_NONE, this is the content associated with the marker role (e.g. tempo or time signature). See the <content> field of the #t_marker structure.
    @param    dur       Duration of the marker region in milliseconds: 0 if just a instant marker, -1 if marker region extends till next marker
    @param    symdur       Duration of the marker region in symbolic units: 0 if just a instant marker, -1 if marker region extends till next marker
    @return            The newly built marker
 */
t_marker *build_marker(t_notation_obj *r_ob, t_llll *names, double ms, t_timepoint tp, char attach_to, e_marker_roles role, t_llll *content, double dur, t_rational symdur);


/** Clear all the markers in the score
    @ingroup        markers
    @param    r_ob    The notation object
 */
void clear_all_markers(t_notation_obj *r_ob);


/** Properly insert an already built marker in the score.
    Markers are always kept ordered by the <position_ms> field. If you need to check ordering, use check_markers_order()
    @ingroup        markers
    @param    r_ob    The notation object
    @param    marker    The marker to insert
    @param    force_ID    If this is > 0, it'll be the ID that the marker will be forced to have.
 */
void insert_marker(t_notation_obj *r_ob, t_marker *marker, unsigned long force_ID);


/** Convenience wrapper for build_marker and insert_marker. Builds and insert a marker inside the score.
    @ingroup        markers
    @param    r_ob    The notation object
    @param    names    The name(s) of the marker (as llll)
    @param    ms        The position in milliseconds of the marker
    @param    tp        The timepoint of the marker (only makes sense with [bach.score])
    @param    attach_to    One of the #e_marker_attach, deciding to what the marker should be attached. By default, it should be #k_MARKER_ATTACH_TO_MS.
    @param    role        One of the #e_marker_roles, possibly specifying the special role of the marker
    @param    content        If the role is NOT #k_MARKER_ROLE_NONE, this is the content associated with the marker role (e.g. tempo or time signature). See the <content> field of the #t_marker structure.
    @param    dur       Duration of the marker region in milliseconds: 0 if just a instant marker, -1 if marker region extends till next marker
    @param    symdur       Duration of the marker region in symbolic units: 0 if just a instant marker, -1 if marker region extends till next marker
    @param    force_ID    If this is > 0, it'll be the ID that the marker will be forced to have.
    @return            The newly built marker
 */
t_marker *add_marker(t_notation_obj *r_ob, t_llll *names, double ms, t_timepoint tp, char attach_to, e_marker_roles role, t_llll *content, double dur, t_rational symdur, unsigned long force_ID);

// TBD
t_marker *add_marker_from_llll(t_notation_obj *r_ob, t_llll *this_llll);
void set_marker_from_llll(t_notation_obj *r_ob, t_marker *marker, t_llll *this_llll);


/** Verify if the ordering of the markers is correct, with respect to the ascending <position_ms> fields.
    If not, corrects the ordering.
    @ingroup        markers
    @param    r_ob    The notation object
    @return            1 if something has changed, 0 otherwise
 */
char check_markers_order(t_notation_obj *r_ob);


/** Delete a marker from the score (and properly free its memory).
    @ingroup        markers
    @param    r_ob    The notation object
    @param    marker    The marker to delete
 */
void delete_marker(t_notation_obj *r_ob, t_marker *marker);


/** Search for a marker having a given name (among its possible multiple names), and delete it from the score (and properly free its memory).
    @ingroup        markers
    @param    r_ob    The notation object
    @param    names    The llll of names to be matched for the marker to delete
    @param    add_undo_ticks    Also add undo ticks
    @remark            Only the first occurrence of the name is searched and deleted!
    @return            1 if something has been deleted, 0 otherwise.
 */
char marker_delete_by_name(t_notation_obj *r_ob, t_llll *names, char add_undo_ticks);


/** Find the first marker having a set of given names (among its possible names)
    @ingroup        markers
    @param    r_ob    The notation object
    @param    names    The llll of names to be matched for the marker
    @return            The first marker having <name> as name; NULL if none.
 */
t_marker *markername2marker(t_notation_obj *r_ob, t_llll *names);


/** Select all the markers
    @ingroup        markers
    @ingroup        selection
    @param    r_ob    The notation object
    @param mode      The selection mode (one of the #e_selection_modes)
    @param only_this_marker_role    One of the e_marker_roles, or -1 if ALL markers should be selected
 */
void select_all_markers(t_notation_obj *r_ob, e_selection_modes mode, long only_this_marker_role);



/** General method to change roles to the selection of a notation object from a generic A_GIMME signature.
    This method parses the input A_GIMME signature and then properly calls change_selection_role().
    @ingroup        names
    @param    r_ob    The notation object
    @param    s        The router symbol in the A_GIMME signature
    @param    argc    The number of atoms of the A_GIMME signature
    @param    argv    The array of atoms of the A_GIMME signature
 */
void notationobj_role(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv);


t_timepoint marker_region_get_start_timepoint(t_notation_obj *r_ob, t_marker *marker);
t_timepoint marker_region_get_end_timepoint(t_notation_obj *r_ob, t_marker *marker);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _NOTATION_MARKERS_H_
