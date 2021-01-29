/*
 *  notation_undo.h
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
	@file	notation_undo.h
*/

#ifndef _NOTATION_UNDO_H_
#define _NOTATION_UNDO_H_

#include "notation/notation.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif


/** Convert an interface operation, represented as a long (one of the #e_undo_operations), into a string describing the operation.
 This string, for instance, is the one displayed in the Max window if the undo is verbose.
 @ingroup      undo
 @param        undo_op        One of the #e_undo_operations identifying the performed operation.
 @param        buf            Allocated buffer (size at least 256 to be on the safe side)
 @seealso      undo_op_to_symbol()
 */
void undo_op_to_string(long undo_op, char *buf);


/** Convert an interface operation, represented as a long (one of the #e_undo_operations), into a symbol describing the operation.
 This string, for instance, is the one displayed in the Max window if the undo is verbose.
 @ingroup      undo
 @param        undo_op        One of the #e_undo_operations identifying the performed operation.
 @return       A symbol containing the string describing the operation.
 @seealso      undo_op_to_string()
 */
t_symbol *undo_op_to_symbol(long undo_op);

t_symbol *element_type_to_symbol(e_element_types el_type);
t_symbol *undo_modification_type_to_symbol(e_undo_modification_types modif_type);
t_llll *undo_get_information_as_llll(t_notation_obj *r_ob, t_undo_redo_information *info);
t_llll *get_undo_op_for_notification(t_notation_obj *r_ob);





/** If one of the fields <need_send_changed_bang> and <need_send_automessage> of the notation object is non-zero, the corresponding action is performed (or also both, of course).
 If <need_send_changed_bang> is nonzero, the usual bang will be sent - meaning that something has been changed via the interface.
 If <need_send_automessage> is nonzero, the automessage, if any, will be sent to the object itself.
 @ingroup                interface
 @remark                    Both actions should be called after painting, so this function is typically called at the end of the paint methods
 @param    r_ob            The notation object
 */
void send_changed_bang_and_automessage_if_needed(t_notation_obj *r_ob);



/** Tell if there are free undo ticks (see handle_change_if_there_are_free_undo_ticks() for more information)
    @ingroup        undo
    @param    r_ob    The notation object
    @param    also_return_true_if_undo_is_empty    If this is non-zero, function returns 1 also if undo llll is empty
    @return            1 if there are free undo ticks, 0 otherwise.
 */
char are_there_free_undo_ticks(t_notation_obj *r_ob, char also_return_true_if_undo_is_empty);


/** Delete and properly free all the free undo ticks (see handle_change_if_there_are_free_undo_ticks() for more information)
    @ingroup        undo
    @param    r_ob    The notation object
    @param    also_clear_ticks_flags    Also clear the flag for the free ticks – this is strongly advised to be 1.
 */
void remove_all_free_undo_ticks(t_notation_obj *r_ob, char also_clear_ticks_flags);


/** Unset the #k_FLAG_MODIF_UNDO, #k_FLAG_MODIF_FLAG_UNDO, #k_FLAG_MODIF_CHECK_ORDER_UNDO and #k_FLAG_MODIF_NAME_UNDO flags from any element in the r_ob->undo_notation_items_under_tick
    llll. This is automatically called by handle_change() when a new undo marker is added. Those flags are usually set by
    create_simple_selected_notation_item_undo_tick(), and are useful when dealing with selection to avoid saving the content of the same item multiple times.
    @ingroup        undo
    @param    r_ob    The notation object
 */
void remove_modif_undo_flag_to_last_undo_ticks(t_notation_obj *r_ob);


/** Convert the current selection into the set of notation items that describe it. This is thought for then adding undo ticks and steps to each item, and
    it is minimal with respect to this perspective;    so for instance, if a measure appears among the returned items, no chord or notes inside the measure will appear.
    Moreover, if a note is selected, its chord will appear, and not the note itself, since currently the minimum undoable item is a chord.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    undo_items    Pointer which will be filled with an array of (t_notation_item *), specifying the selected notation items whose information has to be saved for
                        undo, if we want to save a change on the current selection.
    @remark                The returned pointer must then be properly freed.
 */
void selection_to_undo_notation_item(t_notation_obj *r_ob, t_notation_item **undo_items);



/**    Set the flag fields to a notation item for some undo operation. If the item is of type chord, a list in the
    form [chord_flag (note1_flag note2_flag...)] is expected, where all flags are #H_LONG elements, a combination of the
    #e_notation_item_flags. In all other cases, a list containing a single #H_LONG is expected.
    @ingroup        undo
    @param    r_ob    The notation object
    @param    ll        The llll containing the flag information in the form explained above.
    @param    father_item        The notation item to which the flags must be assigned (if this is a chord, flags will be assigned to its notes as well).
    @see get_multiple_flags_for_undo
 */
void set_multiple_flags_from_llll_for_undo(t_notation_obj *r_ob, t_llll *ll, t_notation_item *father_item);


/**    Get the flag fields to be stored for undo. If the item is of type chord, a list in the
    form [chord_flag (note1_flag note2_flag...)] will be returned, where all flags are #H_LONG elements, a combination of the
    #e_notation_item_flags. In all other cases, a list containing a single #H_LONG will be returned.
    @ingroup        undo
    @param    r_ob    The notation object
    @param    father_item        The notation item of which we want to retrieve the flag in llll form (if this is a chord, we'll retrieve also all its notes' flags).
    @return            A llll containing the flags, in the form explained above.
    @see set_multiple_flags_from_llll_for_undo
 */
t_llll *get_multiple_flags_for_undo(t_notation_obj *r_ob, t_notation_item *father_item);


/**    Allocate the memory for a #t_undo_redo_information structure, representing some undo information linked with a specific notation item (or with the whole
    notation object, or with some header content) and initialize it with the parameters given in input.
    @ingroup            undo
    @param    ID            The ID of the notation item whose information need to be saved, or 0 if header whole notation item are being saved.
    @param    type        The type of the item whose information need to be saved (one of the #e_element_types)
    @param    modif_type    The type of the modification (as one of the #e_undo_modification_types) that need to be performed, in order to revert the item state to the previous state.
                        We stress the fact that this operation is NOT the operation performed by the user, but rather the inverse operation. For instance, if the user
                        adds a chord, the modification type stored here will be #k_UNDO_MODIFICATION_DELETE.
    @param    voice_num    The voice number of the notation item (or 0 if irrelevant)
    @param    meas_num    The measure number of the notation item (or 0 if irrelevant)
    @param    header_info    The header information (as a combination of the #e_header_elems) that need to be saved, if type = #k_HEADER_DATA. 0 otherwise.
    @param    content        An llll specifying the content of the notation item before the user-performed operation. Could be nil if irrelevant (e.g. when a chord was added, and
                        thus modif_type = #k_UNDO_MODIFICATION_DELETE).
 */
t_undo_redo_information *build_undo_redo_information(long ID, e_element_types type, e_undo_modification_types modif_type, long voice_num, long meas_num, e_header_elems header_info, t_llll *content);


/**    Free the memory for a #t_undo_redo_information structure, correctly freeing also the llll possibily contained in the
    t_undo_redo_information::n_it_content field.
    @ingroup    undo
    @param        operation    The undo/redo information to be freed.
 */
void free_undo_redo_information(t_undo_redo_information *operation);


/**    Create a undo/redo tick and properly prepend it to the undo or redo llll.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    what        One of the #e_undo_redo (k_UNDO or k_REDO) specifying if the operation is for an undo or a redo.
    @param    from_what    Leave this to 0 if the tick is placed because some interface operation occurred; set this to 1 if the tick is placed because some
                        undo or redo command has been performed (and thus the corresponding inverse redo or undo ticks are being created).
    @param    operation    Pointer to an already allocated #t_undo_redo_information structure, which describes the tick and which will be prepended as an #H_OBJ to the undo or redo llll.
    @param    lock_undo_mutex    If this is non-zero, the function also locks the undo mutex
    @return                0 if the undo tick has properly been created, 1 if it could not be created, due to the fact that the undo is inactive or to a generic error.
    @remark                VERY IMPORTANT: If for any reason the undo tick could not be created (and then 1 is returned), the #operation information is properly freed
                        (along with its possible llll content field)
 */
long create_undo_redo_tick(t_notation_obj *r_ob, char what, char from_what, t_undo_redo_information *operation, char lock_undo_mutex);


/**    Create a undo/redo step marker ("closing" a sequence of undo ticks) and properly prepend it to the undo or redo llll.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    what        One of the #e_undo_redo (k_UNDO or k_REDO) specifying if the operation is for an undo or a redo.
    @param    from_what    Leave this to 0 if the tick is placed because some interface operation occurred; set this to 1 if the tick is placed because some
                        undo or redo command has been performed (and thus the corresponding inverse redo or undo ticks are being created).
    @param    undo_op        The operation which was performed, as one of the #e_undo_operations.
    @param    lock_undo_mutex    If this is non-zero, the function also locks the undo mutex
    @return                Return the llllelem corresponding to the positioned step marker (or NULL if none)
 */
t_llllelem *create_undo_redo_step_marker(t_notation_obj *r_ob, char what, char from_what, long undo_op, char lock_undo_mutex);


/**    Create a undo tick associated with some header change.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    what        A combination of #e_header_elems, representing the header elements which have been changed
*/
void create_header_undo_tick(t_notation_obj *r_ob, e_header_elems what);


/**    Clear the undo llll or the redo llll. This means that all the ticks (#H_OBJ elements) are properly freed, and their <content> llll field is properly freed as well.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    what        One of the #e_undo_redo (k_UNDO or k_REDO) specifying if the operation is for an undo or a redo.
    @remark                To avoid memory leaks, never call llll_free() on the undo/redo lllls, but always use this function.
 */
void clear_undo_redo_llll(t_notation_obj *r_ob, char what);


/**    Create a simple undo tick, containing the information about the modification of a given notation item.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    item        The notation item being modified
    @param    modif_type    The type of the modification (as one of the #e_undo_modification_types) that need to be performed, in order to revert the item state to the previous state.
                        We stress the fact that this operation is NOT the operation performed by the user, but rather the inverse operation. For instance, if the user
                        adds a chord, the modification type stored here will be #k_UNDO_MODIFICATION_DELETE.
    @remark                This function has to be called BEFORE the item is modified (so that it can retrieve the correct content for undo), except if the
                        notation item has just been created, in which case it should be called afterwards, with #modif_type = #k_UNDO_MODIFICATION_DELETE.
    @see                create_undo_redo_tick()
 */
void create_simple_notation_item_undo_tick(t_notation_obj *r_ob, t_notation_item *item, e_undo_modification_types modif_type);


/**    Create undo ticks for a sequence of notation items.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    num_items    The number of notation items for which ticks need to be created
    @param    item        Pointer to the first element of the array of notation items (the algorithm expects #num_items items).
    @param    modif_type    The type of the modification (as one of the #e_undo_modification_types) that need to be performed, in order to revert the item state to the previous state.
                        This must be common to all notation items in the array, otherwise single create_simple_notation_item_undo_tick() functions must be called for.
    @remark                This function has to be called BEFORE the items are modified (so that it can retrieve the correct content for undo), except if the
                        notation items have just been created, in which case it should be called afterwards, with #modif_type = #k_UNDO_MODIFICATION_DELETE.
    @see                create_simple_notation_item_undo_tick()
    @see                create_undo_redo_tick()
 */
void create_multiple_notation_items_undo_ticks(t_notation_obj *r_ob, long num_items, t_notation_item **item, e_undo_modification_types modif_type, long *undo_op);


/**    Works just like create_simple_notation_item_undo_tick(), but when the item is selected. This also accepts a #smallest_undoable_element specification,
    specifying the minimum structure for which the undo information has to be store. For instance, if #item is a note, and #smallest_undoable_element is #k_MEASURE,
    the undo tick will actually involve the whole measure containing the note. Also, this function has the advantage to automatically set
    the flags #k_FLAG_MODIF_FLAG_UNDO, #k_FLAG_MODIF_UNDO, #k_FLAG_MODIF_CHECK_ORDER_UNDO and #k_FLAG_MODIF_NAME_UNDO if needed. Those flags are assigned, respectively, when the flag information
    of the item is already stored as an undo tick, when the whole information of the item is already stored as an undo tick, and when the whole information of the item
    is stored as an undo tick and also this undo operation will require a new checking of the chords order. Those flags are set for selected item in order to avoid
    repeatedly storing undo ticks on the same thing. For instance, once we've stored an undo tick for a chord, because one of its notes has changed while dragging, we don't need to add
    a new tick if another note has changed.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    item        The notation item being modified
    @param    smallest_undoable_element    One of the #e_element_types determining the smallest element of which we want to save the undo information. For instance,
                                        usually in bach we don't save undo information for notes, so #smallest_undoable_element is usually #k_CHORD or #k_MEASURE.
    @param    modif_type    The type of the modification (as one of the #e_undo_modification_types) that need to be performed, in order to revert the item state to the previous state.
                        We stress the fact that this operation is NOT the operation performed by the user, but rather the inverse operation. For instance, if the user
                        adds a chord, the modification type stored here will be #k_UNDO_MODIFICATION_DELETE.
    @remark                This function has to be called BEFORE the item is modified (so that it can retrieve the correct content for undo), except if the
                        notation item has just been created, in which case it should be called afterwards, with #modif_type = #k_UNDO_MODIFICATION_DELETE.
    @see                create_simple_notation_item_undo_tick()
 */
void create_simple_selected_notation_item_undo_tick(t_notation_obj *r_ob, t_notation_item *item, e_element_types smallest_undoable_element, e_undo_modification_types modif_type);

/**    (DEPRECATED) Create undo ticks for all selected items.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    num_items    The number of notation items for which ticks need to be created
    @param    item        Pointer to the first element of the array of notation items (the algorithm expects #num_items items).
    @param    modif_type    The type of the modification (as one of the #e_undo_modification_types) that need to be performed, in order to revert the item state to the previous state.
                        This must be common to all notation items in the array, otherwise single create_simple_notation_item_undo_tick() functions must be called for.
    @remark                This function has to be called BEFORE the items are modified (so that it can retrieve the correct content for undo), except if the
                        notation items have just been created, in which case it should be called afterwards, with #modif_type = #k_UNDO_MODIFICATION_DELETE.
    @remark                This function is DEPRECATED. The standard way to handle undo in bach is to add ticks individually to each it when it is modified. For instance
                        if we're changing the velocity to the selection, instead of using this function, we should add single ticks at the points of the code where
                        we actually change the velocity for each given chord (via create_simple_selected_notation_item_undo_tick()) and then add a marker directly with the
                        handle_change() function when the operation is performed.
    @see                create_simple_selected_notation_item_undo_tick()
 */
long create_selection_notation_item_undo_tick(t_notation_obj *r_ob, e_element_types smallest_undoable_element, e_undo_modification_types modif_type);


/**    Obtain, starting from a modification performed on a single notation item, the operation performed by the user as one of the #e_undo_operations.
    @ingroup            undo
    @param    r_ob        The notation object
    @param    item        The notation item
    @param    modif_type    The type of the modification (as one of the #e_undo_modification_types) that need to be performed, in order to revert the item state to the previous state.
    @return                The operation performed by the user, as one of the #e_undo_operations.
    @remark                For instance, if #item is a measure and #modif_type is #k_UNDO_MODIFICATION_DELETE, then the operation returned will be #k_UNDO_OP_ADD_MEASURE.
 */
long notation_item_get_undo_op(t_notation_obj *r_ob, t_notation_item *item, char modif_type);


/**    Obtain, starting from a combination of #e_header_elems, the name of the operation performed by the user when changing the specified header information.
    @ingroup                undo
    @param    header_types    The header elements being changed, as a combination of #e_header_elems
    @return                    The operation, as one of the #e_undo_operations, performed by the user when changing the specified header elements.
    @remark                    For instance, if #header_types = #k_HEADER_KEYS, then the operation returned will be #k_UNDO_OP_CHANGE_KEYS.
 */
long header_types_to_undo_op(long header_types);


/**    Get the inverse undo operation (e.g. from #k_UNDO_OP_ADD_MEASURE to #k_UNDO_OP_DELETE_MEASURE)
    @ingroup                undo
    @param    undo_operation    The given undo operation
    @return                    The inverse undo operation
    @remark                    This only works with adding/deleting operations on chords, measures, voices, markers.
 */
long reverse_undo_op(long undo_operation);


/**    Make an undo operation plural (e.g. from #k_UNDO_OP_CHANGE_MEASURE to #k_UNDO_OP_CHANGE_MEASURES)
    @ingroup                undo
    @param    undo_operation    The given undo operation
    @return                    The plural undo operation
 */
long make_undo_op_plural_for_undo(long undo_operation);


/**    Post on the max window (verbosely) a given undo/redo tick.
    @ingroup                undo
    @param    r_ob            The notation object
    @param    what            One of the #e_undo_redo specifying if it is a #k_UNDO or a #k_REDO tick.
    @param    info            The tick as a pointer to a #t_undo_redo_information structure.
 */
void post_undo_redo_tick(t_notation_obj *r_ob, long what, t_undo_redo_information *info);


/**    Prune the last undo step, by merging its undo ticks (undo information) into the previous undo step.
    @ingroup                undo
    @param    r_ob            The notation object
    @param    lock_undo_mutex    Flag telling if the function has also to lock/unlock the #c_undo_mutex mutex of the #t_notation_obj.
 */
void prune_last_undo_step(t_notation_obj *r_ob, char lock_undo_mutex);


/**    Tell if a given notation item is under undo tick.
    @ingroup                undo
    @param    r_ob            The notation object
    @param    item            The notation item
    @return                 1 if the notation item is under undo tick, 0 otherwise
 */
char notation_item_is_under_undo_tick(t_notation_obj *r_ob, t_notation_item *item);


/**    Given a notation item, retrieve the corresponding element in the undo tick list (if any), or NULL if none.
    @ingroup                undo
    @param    r_ob            The notation object
    @param    item            The notation item
    @return                 The llllelem containing the item in the items under undo tick llll, or NULL if none
 */
t_llllelem *notation_item_to_undo_tick(t_notation_obj *r_ob, t_notation_item *item);



/**    Given a notation item, retrieve the corresponding element in the undo tick list (if any), or NULL if none.
    @ingroup                undo
    @param    r_ob          The notation object
    @param    what          -1 for undo, 1 for redo
    @return                 A collection of flags notifying if certain aspects of the notation object must be reprocessed
 */
long notationobj_undo_redo(t_notation_obj *r_ob, char what);



#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _NOTATION_UNDO_H_
