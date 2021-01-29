/*
 *  notation_undo.c
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
    notation_undo.c - common functions (or useful functions) for undo/redo of notation objects
*/

#include "notation/notation_undo.h"



void clear_undo_redo_llll(t_notation_obj *r_ob, char what){
    t_llll *ll = NULL;
    if (what == k_UNDO)
        ll = r_ob->undo_llll;
    else if (what == k_REDO)
        ll = r_ob->redo_llll;
    
    if (ll) {
        t_llllelem *elem;
        for (elem = ll->l_head; elem; elem = elem->l_next)
            if (hatom_gettype(&elem->l_hatom) == H_OBJ) {
                t_undo_redo_information *thisinfo = (t_undo_redo_information *)hatom_getobj(&elem->l_hatom);
                free_undo_redo_information(thisinfo);
            }
        llll_clear(ll);
    }
    if (what == k_UNDO)
        r_ob->num_undo_steps = 0;
    else if (what == k_REDO)
        r_ob->num_redo_steps = 0;
    r_ob->last_undo_marker = NULL;
}

// the new undo tick llll will have the form
// (ID1 itemtype1 modiftype1 voicenum measnum headerinfo CONTENT)
// what = -1 undo, what = 1 redo
// fromwhat = 0 : interface, fromwhat = 1 : we're creating this event because we have just undone/redone

long create_undo_redo_tick(t_notation_obj *r_ob, char what, char from_what, t_undo_redo_information *operation, char lock_undo_mutex)
{
    
    char must_unlock = lock_undo_mutex;
    
    if ((atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0) ||
        (what != k_UNDO && what != k_REDO)) {
        
        dev_post("Warning: undo/redo tick asked even if unnecessary, or wrong undo/redo tick asked!");
        free_undo_redo_information(operation);
        return 1;
        
    }
    
    if (r_ob->whole_obj_under_tick) {
        //        dev_post("Whole object already under tick. No need for other undo ticks.");
        free_undo_redo_information(operation);
        return 1;
    }
    
    if (operation->n_it_type == k_WHOLE_NOTATION_OBJECT)
        r_ob->whole_obj_under_tick = true;
    
    if (lock_undo_mutex)
        if (systhread_mutex_trylock(r_ob->c_undo_mutex))
            must_unlock = false; // already locked
    
    if (what == k_UNDO && from_what == 0 && r_ob->redo_llll->l_size > 0)
        clear_undo_redo_llll(r_ob, k_REDO); // we empty the redo list
    
    llll_prependobj(what == k_UNDO ? r_ob->undo_llll : r_ob->redo_llll, operation, 0, WHITENULL_llll);
    
#ifdef BACH_UNDO_DEBUG
    object_post((t_object *) r_ob, "- %s tick added.", what == k_UNDO ? "Undo" : "Redo");
    llll_post_named(operation->n_it_content, 0, 1, 2, gensym("Content"), NULL);
#endif
    
    if (lock_undo_mutex && must_unlock)
        systhread_mutex_unlock(r_ob->c_undo_mutex);
    
    return 0;
}


void prune_last_undo_step(t_notation_obj *r_ob, char lock_undo_mutex)
{
    remove_all_free_undo_ticks(r_ob, true);
    
    if (lock_undo_mutex)
        systhread_mutex_lock(r_ob->c_undo_mutex);
    
    if (r_ob->undo_llll->l_head) {
        t_llllelem *elem;
        long marker_val = -1;
        for (elem = r_ob->undo_llll->l_head->l_next; elem; elem = elem->l_next) {
            if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                marker_val = hatom_getlong(&elem->l_hatom);
                llll_destroyelem(elem);
                break;
            }
        }
        if (marker_val > 0)
            hatom_setlong(&r_ob->undo_llll->l_head->l_hatom, marker_val);
    }
    
    if (lock_undo_mutex)
        systhread_mutex_unlock(r_ob->c_undo_mutex);
}


void check_num_undo_steps(t_notation_obj *r_ob)
{
#ifdef CONFIGURATION_Development
    long count1 = r_ob->num_undo_steps;
    long count2 = 0;
    t_llllelem *elem;
    for (elem = r_ob->undo_llll->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LONG)
            count2++;
    }
    if (count1 != count2) {
        char foo = 1;
        foo++;
    }
#endif
}


t_llllelem *create_undo_redo_step_marker(t_notation_obj *r_ob, char what, char from_what, long undo_op, char lock_undo_mutex)
{
    t_llllelem *res = NULL;
    
    if (atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0)
        return NULL;
    
    if (what != k_UNDO && what != k_REDO)
        return NULL;
    
    if (lock_undo_mutex)
        systhread_mutex_lock(r_ob->c_undo_mutex);
    
    if (what == k_UNDO && from_what == 0 && r_ob->redo_llll->l_size > 0) {
        llll_clear(r_ob->redo_llll); // we empty the redo list
        r_ob->num_redo_steps = 0;
    }
    
    if (what == k_UNDO) {
        res = llll_prependlong(r_ob->undo_llll, undo_op, 0, WHITENULL_llll);
        r_ob->num_undo_steps++;
    } else {
        res = llll_prependlong(r_ob->redo_llll, undo_op, 0, WHITENULL_llll);
        r_ob->num_redo_steps++;
    }
    
    // checking if we have too many undo steps
    if (what == k_UNDO && atom_gettype(&r_ob->max_undo_steps) == A_LONG) {
        while (r_ob->undo_llll->l_tail && r_ob->num_undo_steps > atom_getlong(&r_ob->max_undo_steps)) {
            if (hatom_gettype(&r_ob->undo_llll->l_tail->l_hatom) == H_LONG) {
                r_ob->num_undo_steps--;
                if (r_ob->last_undo_marker == r_ob->undo_llll->l_tail)
                    r_ob->last_undo_marker = NULL;
                if (res == r_ob->undo_llll->l_tail)
                    res = NULL;
            } else if (hatom_gettype(&r_ob->undo_llll->l_tail->l_hatom) == H_OBJ) {
                t_undo_redo_information *info = (t_undo_redo_information *)hatom_getobj(&r_ob->undo_llll->l_tail->l_hatom);
                free_undo_redo_information(info);
            }
            llll_destroyelem(r_ob->undo_llll->l_tail);
        }
    }
    
    if (what == k_UNDO) {
        llll_clear(r_ob->undo_notation_items_under_tick);
        r_ob->undo_header_elements_under_tick = 0;
    }
    
    r_ob->whole_obj_under_tick = false;
    
#ifdef BACH_UNDO_DEBUG
    char buf[256];
    undo_op_to_string(undo_op, buf);
    object_post((t_object *) r_ob, "- %s marker for '%s' added.", what == k_UNDO ? "Undo" : "Redo", buf);
    object_post((t_object *) r_ob, "  Total number of undo steps: %ld", r_ob->num_undo_steps);
    object_post((t_object *) r_ob, "  Total number of redo steps: %ld", r_ob->num_redo_steps);
    post_undo_redo_llll(r_ob, k_UNDO);
    post_undo_redo_llll(r_ob, k_REDO);
    bach_freeptr(buf);
#endif
    
    if (lock_undo_mutex)
        systhread_mutex_unlock(r_ob->c_undo_mutex);
    
    return res;
}

void free_undo_redo_information(t_undo_redo_information *operation)
{
    if (operation->n_it_content)
        llll_free(operation->n_it_content);
    if (operation)
        bach_freeptr(operation);
}

void create_header_undo_tick(t_notation_obj *r_ob, e_header_elems what)
{
    if (r_ob->inhibited_undo)
        return;
    
    if (atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0)
        return;
    
    if (r_ob->undo_header_elements_under_tick & what) // no need to add a tick for this header element: already added!!
        return;
    
    r_ob->undo_header_elements_under_tick |= what;
    t_llll *content = get_notationobj_header_as_llll(r_ob, what, true, true, true, k_CONSIDER_FOR_UNDO);
    t_undo_redo_information *operation = build_undo_redo_information(0, k_HEADER_DATA, k_UNDO_MODIFICATION_CHANGE, 0, 0, what, content);
    create_undo_redo_tick(r_ob, k_UNDO, 0, operation, true);
}


char* get_string_for_tick(t_hatom *h, long maxdecimals)
{
    if (hatom_gettype(h) == H_OBJ) {
        char *out;
        t_undo_redo_information *info = (t_undo_redo_information *)hatom_getobj(h);
        long ID = info->n_it_ID;
        long type = info->n_it_type;
        long modif = info->modification_type;
        out = (char *)bach_newptr(20 * sizeof(char));
        snprintf_zero(out, 20, "(%s%ld%s)",
                      type == k_WHOLE_NOTATION_OBJECT ? "w" : (type == k_HEADER_DATA ? "h" : (type == k_MEASURE ? "m" : (type == k_CHORD ? "c" : (type == k_VOICE ? "v" : (type == k_NOTE ? "n" : "?"))))),
                      ID,
                      modif == k_UNDO_MODIFICATION_ADD ? "+" : (modif == k_UNDO_MODIFICATION_DELETE ? "-" : (modif == k_UNDO_MODIFICATION_CHANGE ? "~" : (modif == k_UNDO_MODIFICATION_CHANGE_FLAG ? "^" : (modif == k_UNDO_MODIFICATION_CHANGE_CHECK_ORDER ? "*" : (modif == k_UNDO_MODIFICATION_CHANGE_NAME ? "§" : "?"))))));
        return out;
    } else if (hatom_gettype(h) == H_LONG) {
        char *out = (char *)bach_newptr(256 * sizeof(char));
        undo_op_to_string(hatom_getlong(h), out);
        return out;
    }
    return NULL;
}



void post_undo_redo_llll(t_notation_obj *r_ob, char what)
{
    llll_print_named(what == k_UNDO ? r_ob->undo_llll : r_ob->redo_llll, what == k_UNDO ? gensym("Current Undo") : gensym("Current Redo"), 0, 0, get_string_for_tick);
}


void post_undo_redo_tick(t_notation_obj *r_ob, long what, t_undo_redo_information *info)
{
    char *buf = NULL;
    char buf2[256];
    llll_to_text_buf(info->n_it_content, &buf, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
    object_post((t_object *) r_ob, " > %s", what == k_UNDO ? "UNDO" : (what == k_REDO ? "REDO" : "UNKNOWN OPERATION"));
    object_post((t_object *) r_ob, " > ID = %ld", info->n_it_ID);
    object_post((t_object *) r_ob, " > TYPE = %s", info->n_it_type == k_CHORD ? "chord" : (info->n_it_type == k_VOICE ? "voice" : (info->n_it_type == k_MEASURE ? "measure" : (info->n_it_type == k_HEADER_DATA ? "header data" : (info->n_it_type == k_WHOLE_NOTATION_OBJECT ? "whole notation object" : "unknown")))));
    object_post((t_object *) r_ob, " > MODIFICATION = %s", info->modification_type == k_UNDO_MODIFICATION_CHANGE ? "change" : (info->modification_type == k_UNDO_MODIFICATION_ADD ? "add" : (info->modification_type == k_UNDO_MODIFICATION_DELETE ? "delete" : (info->modification_type == k_UNDO_MODIFICATION_NONE ? "none" : "unknown"))));
    object_post((t_object *) r_ob, " > CONTENT = %s", buf);
    object_post((t_object *) r_ob, " > MEASURE NUMBER = %ld", info->meas_num);
    object_post((t_object *) r_ob, " > VOICE NUMBER = %ld", info->voice_num);
    undo_op_to_string(header_types_to_undo_op(info->header_info), buf2);
    object_post((t_object *) r_ob, " > HEADER ELEMENTS = %s", buf2);
    bach_freeptr(buf);
    bach_freeptr(buf2);
}




// use a buf sized 256 to be on the safe side
void undo_op_to_string(long undo_op, char *buf)
{
    switch (undo_op) {
        case k_UNDO_OP_UNKNOWN:
            sprintf(buf, "Unknown Operation");
            break;
        case k_UNDO_OP_CHANGE_SCORE:
            sprintf(buf, "Change Score");
            break;
        case k_UNDO_OP_CHANGE_ROLL:
            sprintf(buf, "Change Roll");
            break;
        case k_UNDO_OP_CHANGE_CHORD:
            sprintf(buf, "Change Chord");
            break;
        case k_UNDO_OP_ADD_CHORD:
            sprintf(buf, "Add Chord");
            break;
        case k_UNDO_OP_DELETE_CHORD:
            sprintf(buf, "Delete Chord");
            break;
        case k_UNDO_OP_CHANGE_MEASURE:
            sprintf(buf, "Change Measure");
            break;
        case k_UNDO_OP_ADD_MEASURE:
            sprintf(buf, "Add Measure");
            break;
        case k_UNDO_OP_APPEND_MEASURE:
            sprintf(buf, "Append Measure");
            break;
        case k_UNDO_OP_APPEND_MEASURES:
            sprintf(buf, "Append Measures");
            break;
        case k_UNDO_OP_INSERT_MEASURE:
            sprintf(buf, "Inser Measure");
            break;
        case k_UNDO_OP_INSERT_MEASURES:
            sprintf(buf, "Inser Measures");
            break;
        case k_UNDO_OP_DELETE_MEASURE:
            sprintf(buf, "Delete Measure");
            break;
        case k_UNDO_OP_CHANGE_VOICE:
            sprintf(buf, "Change Voice");
            break;
        case k_UNDO_OP_ADD_VOICE:
            sprintf(buf, "Add Voice");
            break;
        case k_UNDO_OP_DELETE_VOICE:
            sprintf(buf, "Delete Voice");
            break;
        case k_UNDO_OP_INSERT_VOICE:
            sprintf(buf, "Insert Voice");
            break;
        case k_UNDO_OP_MOVE_VOICE:
            sprintf(buf, "Move Voice");
            break;
        case k_UNDO_OP_CHANGE_HEADER:
            sprintf(buf, "Change Header");
            break;
        case k_UNDO_OP_CHANGE_CLEFS:
            sprintf(buf, "Change Clefs");
            break;
        case k_UNDO_OP_CHANGE_KEYS:
            sprintf(buf, "Change Keys");
            break;
        case k_UNDO_OP_CHANGE_MARKERS:
            sprintf(buf, "Change Markers");
            break;
        case k_UNDO_OP_CHANGE_SLOTINFO:
            sprintf(buf, "Change Slotinfo");
            break;
        case k_UNDO_OP_CHANGE_COMMANDS:
            sprintf(buf, "Change Commans");
            break;
        case k_UNDO_OP_CHANGE_MIDICHANNELS:
            sprintf(buf, "Change Midichannels");
            break;
        case k_UNDO_OP_CHANGE_VOICENAMES:
            sprintf(buf, "Change Voice Names");
            break;
        case k_UNDO_OP_CHANGE_GROUPS:
            sprintf(buf, "Change Groups");
            break;
        case k_UNDO_OP_CHANGE_STAFFLINES:
            sprintf(buf, "Change Staff Lines");
            break;
        case k_UNDO_OP_CHANGE_CUSTOM_ARTICULATIONS_DEFINITION:
            sprintf(buf, "Change Custom Articulations Definition");
            break;
        case k_UNDO_OP_CHANGE_CUSTOM_NOTEHEADS_DEFINITION:
            sprintf(buf, "Change Custom Noteheads Definition");
            break;
        case k_UNDO_OP_CHANGE_PARTS:
            sprintf(buf, "Change Parts Assignment");
            break;
        case k_UNDO_OP_CHANGE_LOOP:
            sprintf(buf, "Change Loop");
            break;
        case k_UNDO_OP_MULTIPLE_CHANGES:
            sprintf(buf, "Multiple Changes");
            break;
        case k_UNDO_OP_CHANGE_CHORDS:
            sprintf(buf, "Change Chords");
            break;
        case k_UNDO_OP_ADD_CHORDS:
            sprintf(buf, "Add Chords");
            break;
        case k_UNDO_OP_DELETE_CHORDS:
            sprintf(buf, "Delete Chords");
            break;
        case k_UNDO_OP_CHANGE_MEASURES:
            sprintf(buf, "Change Measure");
            break;
        case k_UNDO_OP_ADD_MEASURES:
            sprintf(buf, "Add Measure");
            break;
        case k_UNDO_OP_DELETE_MEASURES:
            sprintf(buf, "Delete Measures");
            break;
        case k_UNDO_OP_CHANGE_VOICES:
            sprintf(buf, "Change Voices");
            break;
        case k_UNDO_OP_ADD_VOICES:
            sprintf(buf, "Add Voices");
            break;
        case k_UNDO_OP_DELETE_VOICES:
            sprintf(buf, "Delete Voices");
            break;
        case k_UNDO_OP_READ_SCORE:
            sprintf(buf, "Read");
            break;
        case k_UNDO_OP_IMPORT_MIDI_SCORE:
            sprintf(buf, "Import MIDI");
            break;
        case k_UNDO_OP_IMPORT_XML_SCORE:
            sprintf(buf, "Import XML");
            break;
        case k_UNDO_OP_READ_ROLL:
            sprintf(buf, "Read");
            break;
        case k_UNDO_OP_IMPORT_MIDI_ROLL:
            sprintf(buf, "Import MIDI");
            break;
        case k_UNDO_OP_READ_UISLOT:
            sprintf(buf, "Read");
            break;
        case k_UNDO_OP_CLEAR_SCORE:
            sprintf(buf, "Clear");
            break;
        case k_UNDO_OP_CLEAR_ROLL:
            sprintf(buf, "Clear");
            break;
        case k_UNDO_OP_CLEAR_UISLOT:
            sprintf(buf, "Clear");
            break;
        case k_UNDO_OP_REBUILD_SCORE:
            sprintf(buf, "Rebuild");
            break;
        case k_UNDO_OP_REBUILD_ROLL:
            sprintf(buf, "Rebuild");
            break;
        case k_UNDO_OP_POP_OUT_TEMPO:
            sprintf(buf, "Pop Tempo Out");
            break;
        case k_UNDO_OP_ADD_TEMPO:
            sprintf(buf, "Add Tempo");
            break;
        case k_UNDO_OP_DELETE_SELECTED_MEASURES:
            sprintf(buf, "Delete Selected Measures");
            break;
        case k_UNDO_OP_DELETE_SELECTION:
            sprintf(buf, "Delete Selection");
            break;
        case k_UNDO_OP_RIPPLE_DELETE_SELECTION:
            sprintf(buf, "Ripple Delete Selection");
            break;
        case k_UNDO_OP_CHANGE_SLOT:
            sprintf(buf, "Change Slot");
            break;
        case k_UNDO_OP_FIX_DYNAMICS:
            sprintf(buf, "Fix Dynamics");
            break;
        case k_UNDO_OP_ASSIGN_DYNAMICS:
            sprintf(buf, "Assign Dynamics");
            break;
        case k_UNDO_OP_ASSIGN_VELOCITIES:
            sprintf(buf, "Assign Velocities");
            break;
        case k_UNDO_OP_CLEAR_MARKERS:
            sprintf(buf, "Clear Markers");
            break;
        case k_UNDO_OP_SNAP_PITCH_TO_GRID_FOR_SELECTION:
            sprintf(buf, "Snap Pitch To Grid");
            break;
        case k_UNDO_OP_SNAP_ONSET_TO_GRID_FOR_SELECTION:
            sprintf(buf, "Snap Onset To Grid");
            break;
        case k_UNDO_OP_SNAP_TAIL_TO_GRID_FOR_SELECTION:
            sprintf(buf, "Snap Tail To Grid");
            break;
        case k_UNDO_OP_RESET_ALL_ENHARMONICITIES:
            sprintf(buf, "Reset All Enharmonicities");
            break;
        case k_UNDO_OP_RESET_ENHARMONICITY_FOR_SELECTION:
            sprintf(buf, "Reset Enharmonicity");
            break;
        case k_UNDO_OP_RESPELL:
            sprintf(buf, "Respell Notes");
            break;
        case k_UNDO_OP_CHANGE_ONSET_FOR_SELECTION:
            sprintf(buf, "Change Onset");
            break;
        case k_UNDO_OP_CHANGE_DURATION_FOR_SELECTION:
            sprintf(buf, "Change Duration");
            break;
        case k_UNDO_OP_CHANGE_TAIL_FOR_SELECTION:
            sprintf(buf, "Change Tail");
            break;
        case k_UNDO_OP_CHANGE_CENTS_FOR_SELECTION:
            sprintf(buf, "Change Cents");
            break;
        case k_UNDO_OP_CHANGE_PITCH_FOR_SELECTION:
            sprintf(buf, "Change Pitch");
            break;
        case k_UNDO_OP_CHANGE_POC_FOR_SELECTION:
            sprintf(buf, "Change Pitch Or Cents");
            break;
        case k_UNDO_OP_CHANGE_MEASUREINFO_FOR_SELECTION:
            sprintf(buf, "Change Measureinfo");
            break;
        case k_UNDO_OP_CHANGE_VOICE_FOR_SELECTION:
            sprintf(buf, "Change Voice");
            break;
        case k_UNDO_OP_CHANGE_VELOCITY_FOR_SELECTION:
            sprintf(buf, "Change Velocity");
            break;
        case k_UNDO_OP_CHANGE_TIE_FOR_SELECTION:
            sprintf(buf, "Change Tie");
            break;
        case k_UNDO_OP_CHANGE_IOI_FOR_SELECTION:
            sprintf(buf, "Change Inter-Onset Interval");
            break;
        case k_UNDO_OP_ADD_BREAKPOINTS_TO_SELECTION:
            sprintf(buf, "Add Pitch Breakpoints");
            break;
        case k_UNDO_OP_ERASE_BREAKPOINTS_FOR_SELECTION:
            sprintf(buf, "Erase Pitch Breakpoints");
            break;
        case k_UNDO_OP_SET_SLOTS_TO_SELECTION:
            sprintf(buf, "Set Slots");
            break;
        case k_UNDO_OP_ERASE_SLOTS_FOR_SELECTION:
            sprintf(buf, "Erase Slots");
            break;
        case k_UNDO_OP_MOVE_SLOTS_FOR_SELECTION:
            sprintf(buf, "Move Slots");
            break;
        case k_UNDO_OP_COPY_SLOTS_FOR_SELECTION:
            sprintf(buf, "Copy Slots");
            break;
        case k_UNDO_OP_CHANGE_SLOTS_FOR_SELECTION:
            sprintf(buf, "Change Slots");
            break;
        case k_UNDO_OP_ADD_MARKER:
            sprintf(buf, "Add Marker");
            break;
        case k_UNDO_OP_DELETE_MARKER:
            sprintf(buf, "Delete Marker");
            break;
        case k_UNDO_OP_CHANGE_MARKER_NAME:
            sprintf(buf, "Change Marker Name");
            break;
        case k_UNDO_OP_CHANGE_MARKER_ATTACHMENT:
            sprintf(buf, "Change Marker Attachment");
            break;
        case k_UNDO_OP_GLUE_CHORD:
            sprintf(buf, "Glue Chord");
            break;
        case k_UNDO_OP_MERGE:
            sprintf(buf, "Merge");
            break;
        case k_UNDO_OP_OVERTYPE:
            sprintf(buf, "Overtype");
            break;
        case k_UNDO_OP_ALIGN_SELECTION:
            sprintf(buf, "Align");
            break;
        case k_UNDO_OP_EQUALLY_RESPACE_SELECTION:
            sprintf(buf, "Equally Respace");
            break;
        case k_UNDO_OP_LEGATO_FOR_SELECTION:
            sprintf(buf, "Legato");
            break;
        case k_UNDO_OP_GLISSANDO_FOR_SELECTION:
            sprintf(buf, "Glissando");
            break;
        case k_UNDO_OP_FORCE_POLYPHONY_FOR_SELECTION:
            sprintf(buf, "Force Polyphony");
            break;
        case k_UNDO_OP_DELETE_NOTE:
            sprintf(buf, "Delete Note");
            break;
        case k_UNDO_OP_ADD_NOTE:
            sprintf(buf, "Add Note");
            break;
        case k_UNDO_OP_CHANGE_NOTE:
            sprintf(buf, "Change Note");
            break;
        case k_UNDO_OP_DELETE_PITCH_BREAKPOINT:
            sprintf(buf, "Delete Pitch Breakpoint");
            break;
        case k_UNDO_OP_ADD_PITCH_BREAKPOINT:
            sprintf(buf, "Add Pitch Breakpoint");
            break;
        case k_UNDO_OP_CHANGE_PITCH_BREAKPOINT:
            sprintf(buf, "Change Pitch Breakpoint");
            break;
        case k_UNDO_OP_CHANGE_PITCH:
            sprintf(buf, "Change Pitch");
            break;
        case k_UNDO_OP_MOUSEDRAG_CHANGE:
            sprintf(buf, "Mousedrag Change");
            break;
        case k_UNDO_OP_CHANGE_VOICE_NAME:
            sprintf(buf, "Change Voice Name");
            break;
        case k_UNDO_OP_CHANGE_LYRICS:
            sprintf(buf, "Change Lyrics");
            break;
        case k_UNDO_OP_CHANGE_DYNAMICS:
            sprintf(buf, "Change Dynamics");
            break;
        case k_UNDO_OP_CHANGE_DURATION_LINES_FOR_SELECTION:
            sprintf(buf, "Change Duration Lines");
            break;
        case k_UNDO_OP_TRIM_END:
            sprintf(buf, "Trim End");
            break;
        case k_UNDO_OP_TRIM_START:
            sprintf(buf, "Trim End");
            break;
        case k_UNDO_OP_CHANGE_NAMES:
            sprintf(buf, "Change Names");
            break;
        case k_UNDO_OP_CLEAR_NAMES:
            sprintf(buf, "Clear Names");
            break;
        case k_UNDO_OP_NAMES_FROM_SLOT:
            sprintf(buf, "Assign Names From Slot");
            break;
        case k_UNDO_OP_NAMES_TO_SLOT:
            sprintf(buf, "Export Names To Slot");
            break;
        case k_UNDO_OP_CHANGE_ROLES:
            sprintf(buf, "Change Roles");
            break;
        case k_UNDO_OP_RESET_TAIL_SLOPE:
            sprintf(buf, "Reset Tail Slope");
            break;
        case k_UNDO_OP_DELETE_PITCH_BREAKPOINTS_IN_SELECTION:
            sprintf(buf, "Operation");
            break;
        case k_UNDO_OP_RESET_PITCH_BREAKPOINTS_SLOPE_FOR_SELECTION:
            sprintf(buf, "Reset Pitch Breakpoints Slope");
            break;
        case k_UNDO_OP_SHIFT_PITCH_UP_FOR_SELECTION:
            sprintf(buf, "Shift Pitch Up");
            break;
        case k_UNDO_OP_SHIFT_PITCH_DOWN_FOR_SELECTION:
            sprintf(buf, "Shift Pitch Down");
            break;
        case k_UNDO_OP_LOCK_UNLOCK_SELECTION:
            sprintf(buf, "Lock/Unlock");
            break;
        case k_UNDO_OP_MUTE_UNMUTE_SELECTION:
            sprintf(buf, "Mute/Unmute");
            break;
        case k_UNDO_OP_SOLO_UNSOLO_SELECTION:
            sprintf(buf, "Solo/Unsolo");
            break;
        case k_UNDO_OP_DELETE_GROUP:
            sprintf(buf, "Delete Group");
            break;
        case k_UNDO_OP_CREATE_GROUP:
            sprintf(buf, "Create Group");
            break;
        case k_UNDO_OP_PASTE_SLOT_CONTENT:
            sprintf(buf, "Paste Slot Content");
            break;
        case k_UNDO_OP_PASTE_DURATION_LINE:
            sprintf(buf, "Paste Duration Line");
            break;
        case k_UNDO_OP_PASTE:
            sprintf(buf, "Paste");
            break;
        case k_UNDO_OP_CUT_SLOT_CONTENT:
            sprintf(buf, "Cut Slot Content");
            break;
        case k_UNDO_OP_CUT_DURATION_LINE:
            sprintf(buf, "Cut Duration Line");
            break;
        case k_UNDO_OP_CUT:
            sprintf(buf, "Cut");
            break;
        case k_UNDO_OP_DELETE_SLOT_CONTENT:
            sprintf(buf, "Delete Slot Content");
            break;
        case k_UNDO_OP_DELETE_ARTICULATIONS_FOR_SELECTION:
            sprintf(buf, "Delete Articulations");
            break;
        case k_UNDO_OP_RESET_LOCAL_SPACING_FOR_SELECTION:
            sprintf(buf, "Reset Local Spacing");
            break;
        case k_UNDO_OP_RESET_LOCAL_SPACING:
            sprintf(buf, "Reset Local Spacing");
            break;
        case k_UNDO_OP_SET_MEASURE_PARAMETERS:
            sprintf(buf, "Set Measure Parameters");
            break;
        case k_UNDO_OP_CEIL_MEASURES:
            sprintf(buf, "Ceil Measures");
            break;
        case k_UNDO_OP_AUTO_RHYTHMIC_TREE_KEEPING_EXISTING_TUPLETS:
            sprintf(buf, "Auto Rhythmic Tree Keeping Existing Tuplets");
            break;
        case k_UNDO_OP_STICK_RHYTHMIC_TREE:
            sprintf(buf, "Stick Rhythmic Tree");
            break;
        case k_UNDO_OP_DESTROY_RHYTHMIC_TREE:
            sprintf(buf, "Destroy Rhythmic Tree");
            break;
        case k_UNDO_OP_ADD_RHYTHMIC_TREE_LEVEL:
            sprintf(buf, "Add Rhythmic Tree Level");
            break;
        case k_UNDO_OP_DESTROY_RHYTHMIC_TREE_LEVEL:
            sprintf(buf, "Destroy Rhythmic Tree Level");
            break;
        case k_UNDO_OP_AUTO_RHYTHMIC_TREE_IGNORING_EXISTING_TUPLETS:
            sprintf(buf, "Auto Rhythmic Tree Ignoring Existing Tuplets");
            break;
        case k_UNDO_OP_TURN_REST_INTO_NOTE:
            sprintf(buf, "Turn Rest Into Note");
            break;
        case k_UNDO_OP_DELETE_ARTICULTATION:
            sprintf(buf, "Delete Articulation");
            break;
        case k_UNDO_OP_DELETE_TEMPO:
            sprintf(buf, "Delete Tempo");
            break;
        case k_UNDO_OP_LINEAR_EDIT_CHANGE_PITCH:
            sprintf(buf, "Change Pitch");
            break;
        case k_UNDO_OP_LINEAR_EDIT_TOGGLE_REST:
            sprintf(buf, "Toggle Rest");
            break;
        case k_UNDO_OP_LINEAR_EDIT_TOGGLE_TIES:
            sprintf(buf, "Toggle Ties");
            break;
        case k_UNDO_OP_LINEAR_EDIT_ADD_SHARP:
            sprintf(buf, "Add Sharp");
            break;
        case k_UNDO_OP_LINEAR_EDIT_ADD_FLAT:
            sprintf(buf, "Add Flat");
            break;
        case k_UNDO_OP_LINEAR_EDIT_TOGGLE_GRACE:
            sprintf(buf, "Toggle Grace");
            break;
        case k_UNDO_OP_LINEAR_EDIT_ADD_NOTE:
            sprintf(buf, "Add Note");
            break;
        case k_UNDO_OP_LINEAR_EDIT_DELETE_NOTE:
            sprintf(buf, "Delete Note");
            break;
        case k_UNDO_OP_LINEAR_EDIT_DELETE_CHORD:
            sprintf(buf, "Delete Chord");
            break;
        case k_UNDO_OP_LINEAR_EDIT_SPLIT_CHORD:
            sprintf(buf, "Split Chord");
            break;
        case k_UNDO_OP_LINEAR_EDIT_ADD_DOT:
            sprintf(buf, "Add Dot");
            break;
        case k_UNDO_OP_LINEAR_EDIT_CHANGE_CHORD_DURATION:
            sprintf(buf, "Change Chord Duration");
            break;
        case k_UNDO_OP_LINEAR_EDIT_ADD_CHORD:
            sprintf(buf, "Add Chord");
            break;
        case k_UNDO_OP_LINEAR_EDIT_ADD_NEW_MEASURE:
            sprintf(buf, "Add New Measure");
            break;
        case k_UNDO_OP_LINEAR_EDIT_CLEAR_MEASURE:
            sprintf(buf, "Clear Measure");
            break;
        case k_UNDO_OP_DELETE_MEASURES_IN_SELECTION:
            sprintf(buf, "Delete Measures");
            break;
        case k_UNDO_OP_CLEAR_MEASURES_IN_SELECTION:
            sprintf(buf, "Clear Measures");
            break;
        case k_UNDO_OP_DUPLICATE_SELECTED_MEASURES:
            sprintf(buf, "Duplicate Measures");
            break;
        case k_UNDO_OP_DELETE_SELECTED_TEMPI:
            sprintf(buf, "Delete Tempi");
            break;
        case k_UNDO_OP_TOGGLE_INTERPOLATION_FOR_SELECTED_TEMPI:
            sprintf(buf, "Toggle Tempi Interpolation");
            break;
        case k_UNDO_OP_DELETE_SLURS_FOR_SELECTION:
            sprintf(buf, "Delete Slurs");
            break;
        case k_UNDO_OP_ADD_ARTICULATION_TO_SELECTION:
            sprintf(buf, "Add Articulation");
            break;
        case k_UNDO_OP_CHANGE_ARTICULATION:
            sprintf(buf, "Change Articulation");
            break;
        case k_UNDO_OP_TURN_SELECTION_INTO_RESTS:
            sprintf(buf, "Turn Into Rests");
            break;
        case k_UNDO_OP_JOIN_SELECTION:
            sprintf(buf, "Join");
            break;
        case k_UNDO_OP_DELETE_GRACE:
            sprintf(buf, "Delete Grace Chords");
            break;
        case k_UNDO_OP_MERGE_GRACE:
            sprintf(buf, "Merge Grace Chords");
            break;
        case k_UNDO_OP_AUTO_BEAM:
            sprintf(buf, "Auto Beam");
            break;
        case k_UNDO_OP_AUTO_RHYTHMIC_TREE_KEEPING_EXISTING_TUPLETS_FOR_SELECTION:
            sprintf(buf, "Auto Rhythmic Tree Keeping Existing Tuplets");
            break;
        case k_UNDO_OP_AUTO_RHYTHMIC_TREE_IGNORING_EXISTING_TUPLETS_FOR_SELECTION:
            sprintf(buf, "Auto Rhythmic Tree Ignoring Existing Tuplets");
            break;
        case k_UNDO_OP_DESTROY_RHYTHMIC_TREE_LEVEL_FOR_SELECTION:
            sprintf(buf, "Destroy Rhythmic Tree Level");
            break;
        case k_UNDO_OP_STICK_RHYTHMIC_TREE_FOR_SELECTION:
            sprintf(buf, "Stick Rhythmic Tree");
            break;
        case k_UNDO_OP_DESTROY_RHYTHMIC_TREE_FOR_SELECTION:
            sprintf(buf, "Destroy Rhythmic Tree");
            break;
        case k_UNDO_OP_ADD_RHYTHMIC_TREE_LEVELS_FROM_SELECTION:
            sprintf(buf, "Add Rhythmic Tree Level");
            break;
        case k_UNDO_OP_LOCK_UNLOCK_RHYTHMIC_TREES_FOR_SELECTION:
            sprintf(buf, "Lock/Unlock Rhythmic Tree");
            break;
        case k_UNDO_OP_TIE_UNTIE_SELECTION:
            sprintf(buf, "Tie/Untie");
            break;
        case k_UNDO_OP_SPLIT_SELECTION:
            sprintf(buf, "Split");
            break;
        case k_UNDO_OP_CUT_MEASURES:
            sprintf(buf, "Cut Measures");
            break;
        case k_UNDO_OP_PASTE_MEASURES:
            sprintf(buf, "Paste Measures");
            break;
        case k_UNDO_OP_FIX_UNFIX_MEASURE_WIDTH_FOR_SELECTION:
            sprintf(buf, "Fix/Unfix Measure Width");
            break;
        case k_UNDO_OP_CHANGE_SLOTS_FROM_MESSAGE:
            sprintf(buf, "Change Slots From Message");
            break;
        case k_UNDO_OP_LOCK_SELECTION:
            sprintf(buf, "Lock");
            break;
        case k_UNDO_OP_UNLOCK_SELECTION:
            sprintf(buf, "Unlock");
            break;
        case k_UNDO_OP_MUTE_SELECTION:
            sprintf(buf, "Mute");
            break;
        case k_UNDO_OP_UNMUTE_SELECTION:
            sprintf(buf, "Unmute");
            break;
        case k_UNDO_OP_SOLO_SELECTION:
            sprintf(buf, "Solo");
            break;
        case k_UNDO_OP_UNSOLO_SELECTION:
            sprintf(buf, "Unsolo");
            break;
        case k_UNDO_OP_NO_SOLOS:
            sprintf(buf, "No Solos");
            break;
        case k_UNDO_OP_NO_MUTES:
            sprintf(buf, "No Mutes");
            break;
        case k_UNDO_OP_ENHARMONICALLY_RESPELL_NOTE:
            sprintf(buf, "Enharmonically Respell Note");
            break;
        case k_UNDO_OP_CHANGE_BARLINE_TYPE:
            sprintf(buf, "Change Barline");
            break;
        case k_UNDO_OP_CHANGE_TIME_SIGNATURE_FOR_SELECTED_MEASURES:
            sprintf(buf, "Change Time Signatures");
            break;
        case k_UNDO_OP_LOCK_RHYTHMIC_TREE_FOR_SELECTION:
            sprintf(buf, "Lock Rhythmic Tree");
            break;
        case k_UNDO_OP_UNLOCK_RHYTHMIC_TREE_FOR_SELECTION:
            sprintf(buf, "Unlock Rhythmic Tree");
            break;
        case k_UNDO_OP_CREATE_VOICE_ENSEMBLE:
            sprintf(buf, "Create Voice Ensemble");
            break;
        case k_UNDO_OP_BREAK_VOICE_ENSEMBLE:
            sprintf(buf, "Break Voice Ensemble");
            break;
        case k_UNDO_OP_CLEAR_ARTICULATIONS:
            sprintf(buf, "Clear Articulations");
            break;
        case k_UNDO_OP_CLEAR_NOTES:
            sprintf(buf, "Clear Notes");
            break;
        case k_UNDO_OP_CLEAR_TEMPI:
            sprintf(buf, "Clear Tempi");
            break;
        case k_UNDO_OP_CLEAR_BREAKPOINTS:
            sprintf(buf, "Clear Pitch Breakpoints");
            break;
        case k_UNDO_OP_CHANGE_BACH_ATTRIBUTE:
            sprintf(buf, "Change Attribute");
            break;
        case k_UNDO_OP_SLICE:
            sprintf(buf, "Slice");
            break;
        case k_UNDO_OP_AUTOSPELL:
            sprintf(buf, "Autospell");
            break;
        case k_UNDO_OP_TAILS_TO_GRACES:
            sprintf(buf, "Convert tails to grace chords");
            break;
        default:
            sprintf(buf, "Generic Operation");
            break;
    }
}


t_symbol *undo_op_to_symbol(long undo_op)
{
    char buf[256];
    undo_op_to_string(undo_op, buf);
    return gensym(buf);
}



t_symbol *element_type_to_symbol(e_element_types el_type)
{
    switch (el_type) {
        case k_NONE: return gensym("none");
        case k_NOTE: return gensym("note");
        case k_DURATION_LINE: return gensym("durationline");
        case k_DURATION_TAIL: return gensym("tail");
        case k_PITCH_BREAKPOINT: return gensym("breakpoint");
        case k_CHORD: return gensym("chord");
        case k_REGION: return gensym("region");
        case k_SCROLLBAR: return gensym("scrollbar");
        case k_PITCH_BREAKPOINT_OR_DURATION_TAIL: return gensym("breakpointortail");
        case k_SLOT_INT_FLOAT_BAR: return gensym("slotbar");
        case k_SLOT_FUNCTION_POINT: return gensym("slotfunctionpoint");
        case k_SLOT_SPAT_POINT: return gensym("slotspatpoint");
        case k_VOICE: return gensym("voice");
        case k_MEASURE: return gensym("measure");
        case k_TEMPO: return gensym("tempo");
        case k_PLAYCURSOR: return gensym("cursor");
        case k_MIXED: return gensym("mixed");
        case k_DRAG: return gensym("drag");
        case k_SLOT: return gensym("slot");
        case k_ARTICULATION: return gensym("articulation");
        case k_SLUR: return gensym("slur");
        case k_SLUR_START_POINT: return gensym("slurstart");
        case k_SLUR_END_POINT: return gensym("slurend");
        case k_SLOT_MATRIX_CELL: return gensym("slotmatrixcell");
        case k_MARKER: return gensym("marker");
        case k_SCROLLBAR_LEFT_AREA: return gensym("scrollbarleftarea");
        case k_SCROLLBAR_RIGHT_AREA: return gensym("scrollbarrightarea");
        case k_ZOOMING_REGION: return gensym("zoomregion");
        case k_VOICENAME: return gensym("voicename");
        case k_TEXT_IN_SLOT: return gensym("slottext");
        case k_LLLL_IN_SLOT: return gensym("slotllll");
        case k_MARKERNAME: return gensym("markername");
        case k_SELECTION_CONTENT: return gensym("selectioncontent");
        case k_MEASURE_END_BARLINE: return gensym("barline");
        case k_LYRICS: return gensym("lyrics");
        case k_SCROLLBAR_TOP_AREA: return gensym("verticalscrollbartoparea");
        case k_SCROLLBAR_BOTTOM_AREA: return gensym("verticalscrollbarbottomarea");
        case k_VSCROLLBAR: return gensym("verticalscrollbar");
        case k_SLOT_DYNFILTER_BIQUAD: return gensym("slotdynfilterbiquad");
        case k_SLOT_COLOR_PALETTE: return gensym("slotcolorpalette");
        case k_SLOT_COLOR_SPECTRUM: return gensym("slotcolorspectrum");
        case k_DILATION_RECTANGLE_TOPLEFT_SQ: return gensym("dilationrecttl");
        case k_DILATION_RECTANGLE_TOPRIGHT_SQ: return gensym("dilationrecttr");
        case k_DILATION_RECTANGLE_BOTTOMLEFT_SQ: return gensym("dilationrectbl");
        case k_DILATION_RECTANGLE_BOTTOMRIGHT_SQ: return gensym("dilationrectbr");
        case k_DILATION_RECTANGLE_TOPMIDDLE_SQ: return gensym("dilationrecttm");
        case k_DILATION_RECTANGLE_BOTTOMMIDDLE_SQ: return gensym("dilationrectbm");
        case k_DILATION_RECTANGLE_MIDDLELEFT_SQ: return gensym("dilationrectml");
        case k_DILATION_RECTANGLE_MIDDLERIGHT_SQ: return gensym("dilationrectmr");
        case k_DILATION_RECTANGLE_BODY: return gensym("dilationrectbody");
        case k_TIME_SIGNATURE: return gensym("timesig");
        case k_WHOLE_NOTATION_OBJECT: return gensym("whole");
        case k_HEADER_DATA: return gensym("header");
        case k_SLOTINFO: return gensym("slotinfo");
        case k_BACH_INSPECTOR_ITEM: return gensym("inspectoritem");
        case k_BACH_INSPECTOR_VSCROLLBAR: return gensym("inspectorverticalscrollbar");
        case k_BACH_INSPECTOR_COLOR_PALETTE: return gensym("inspectorcolorpalette");
        case k_BACH_INSPECTOR_COLOR_SPECTRUM: return gensym("inspectorcolorspectrum");
        case k_SLOT_3DFUNCTION_POINT: return gensym("slot3dfunctionpoint");
        case k_BACH_INSPECTOR: return gensym("inspector");
        case k_GROUP: return gensym("group");
        case k_SELECTION: return gensym("selection");
        case k_NOTE_OR_CHORD: return gensym("noteorchord");
        case k_POPUP_MENU: return gensym("popupmenu");
        case k_DILATION_RECTANGLE: return gensym("dilationrect");
        case k_LOOP_REGION: return gensym("loop");
        case k_LOOP_START: return gensym("loopstart");
        case k_LOOP_END: return gensym("loopend");
        case k_SLOT_FUNCTION_SEGMENT: return gensym("slotfunctionsegment");
        case k_SLOT_REGION: return gensym("slotregion");
        case k_SLOT_SELECTION: return gensym("slotselection");
        case k_NUMBER_IN_SLOT: return gensym("slotnumber");
        case k_DROP: return gensym("drop");
        case k_DYNAMICS_IN_SLOT: return gensym("slotdynamics");
        case k_DYNAMICS: return gensym("dynamics");
        case k_GATHERED_SYNTAX: return gensym("gatheredsyntax");
        default: return gensym("unknown");
    }
}

t_symbol *undo_modification_type_to_symbol(e_undo_modification_types modif_type)
{
    switch (modif_type) {
        case k_UNDO_MODIFICATION_NONE: return gensym("none"); break;
        case k_UNDO_MODIFICATION_ADD: return gensym("add"); break;
        case k_UNDO_MODIFICATION_DELETE: return gensym("delete"); break;
        case k_UNDO_MODIFICATION_CHANGE: return gensym("change"); break;
        case k_UNDO_MODIFICATION_CHANGE_CHECK_ORDER: return gensym("change"); break;
        case k_UNDO_MODIFICATION_CHANGE_FLAG: return gensym("changeflag"); break;
        case k_UNDO_MODIFICATION_CHANGE_NAME: return gensym("changename"); break;
        default: return gensym("unknown"); break;
    }
}

t_llll *undo_get_information_as_llll(t_notation_obj *r_ob, t_undo_redo_information *info)
{
    t_llll *ll = llll_get();
    llll_appendsym(ll, undo_modification_type_to_symbol(info->modification_type));
    llll_appendsym(ll, element_type_to_symbol(info->n_it_type));
    if (info->n_it_content)
        llll_appendllll_clone(ll, info->n_it_content);
    return ll;
}

t_llll *get_undo_op_for_notification(t_notation_obj *r_ob)
{
    t_llll *out = llll_get();
    t_llll *llll = r_ob->undo_llll;
    
    if (!llll->l_head || hatom_gettype(&llll->l_head->l_hatom) != H_LONG) {
        llll_appendsym(out, gensym("unknown"));
        return out;
    }
    
    long undo_op = hatom_getlong(&llll->l_head->l_hatom);
    t_symbol *operation = undo_op_to_symbol(undo_op);
    
    llll_appendsym(out, operation);
    
    for (t_llllelem *el = llll->l_head->l_next; el && hatom_gettype(&el->l_hatom) == H_OBJ; el = el->l_next){
        t_undo_redo_information *this_information = (t_undo_redo_information *)hatom_getobj(&el->l_hatom);
        long ID = this_information->n_it_ID;
        e_element_types type = this_information->n_it_type;
        e_undo_modification_types modif_type = this_information->modification_type;
        long voice_num = this_information->voice_num;
        e_header_elems header_info = this_information->header_info;
        t_llll *content = this_information->n_it_content;
        t_llll *newcontent = NULL;
        t_notation_item *item = notation_item_retrieve_from_ID(r_ob, ID);
        t_undo_redo_information *new_information = NULL;
        
        
        if (modif_type == k_UNDO_MODIFICATION_CHANGE_FLAG) {
            newcontent = get_multiple_flags_for_undo(r_ob, item);
            new_information = build_undo_redo_information(ID, type, k_UNDO_MODIFICATION_CHANGE_FLAG, voice_num, 0, k_HEADER_NONE, newcontent);
            //            set_multiple_flags_from_llll_for_undo((t_notation_obj *)x, content, item);
            //            x->r_ob.are_there_solos = are_there_solos((t_notation_obj *)x);
            
        } else if (modif_type == k_UNDO_MODIFICATION_CHANGE_NAME) {
            newcontent = get_names_as_llll(item, false);
            new_information = build_undo_redo_information(ID, type, k_UNDO_MODIFICATION_CHANGE_NAME, voice_num, 0, k_HEADER_NONE, newcontent);
            //            notation_item_set_names_from_llll((t_notation_obj *)x, item, content);
            
        } else if (type == k_WHOLE_NOTATION_OBJECT){
            // need to reconstruct the whole roll
            //            newcontent = get_roll_values_as_llll(x, k_CONSIDER_FOR_UNDO, k_HEADER_ALL, false, true);
            // TO DO
            newcontent = llll_get();
            new_information = build_undo_redo_information(0, k_WHOLE_NOTATION_OBJECT, k_UNDO_MODIFICATION_CHANGE, 0, 0, k_HEADER_NONE, newcontent);
            //            roll_clear_all(x);
            //            set_roll_from_llll(x, content, false);
            
        } else if (type == k_CHORD) {
            if (modif_type == k_UNDO_MODIFICATION_CHANGE || modif_type == k_UNDO_MODIFICATION_CHANGE_CHECK_ORDER) {
                newcontent = get_rollchord_values_as_llll(r_ob, (t_chord *) item, k_CONSIDER_FOR_UNDO);
                new_information = build_undo_redo_information(ID, k_CHORD, modif_type, voice_num, 0, k_HEADER_NONE, newcontent);
                //                set_rollchord_values_from_llll(r_ob, (t_chord *)item, content, 0, true, false, false);
                //                need_recompute_total_length = true;
                //                if (modif_type == k_UNDO_MODIFICATION_CHANGE_CHECK_ORDER)
                //                    need_check_order = true;
                
            } else if (modif_type == k_UNDO_MODIFICATION_DELETE) {
                newcontent = get_rollchord_values_as_llll(r_ob, (t_chord *) item, k_CONSIDER_FOR_UNDO);
                new_information = build_undo_redo_information(ID, k_CHORD, k_UNDO_MODIFICATION_ADD, voice_num, 0, k_HEADER_NONE, newcontent);
                //                need_recompute_total_length = true;
                //                if (chord_delete((t_notation_obj *)x, (t_chord *)item, ((t_chord *)item)->prev, false))
                //                    check_correct_scheduling((t_notation_obj *)x, false);
                
            } else if (modif_type == k_UNDO_MODIFICATION_ADD) {
                new_information = build_undo_redo_information(ID, k_CHORD, k_UNDO_MODIFICATION_DELETE, voice_num, 0, k_HEADER_NONE, newcontent);
                //                t_chord *newch = addchord_from_llll(x, content, nth_rollvoice(x, voice_num), false, true);
                //                if (newch)
                //                    newch->need_recompute_parameters = true;
            }
            
        } else if (type == k_HEADER_DATA) {
            if (modif_type == k_UNDO_MODIFICATION_CHANGE) {
                // TO DO
                //                newcontent = get_roll_values_as_llll(x, k_CONSIDER_FOR_UNDO, header_info, false, true);
                newcontent = llll_get();
                new_information = build_undo_redo_information(0, k_HEADER_DATA, k_UNDO_MODIFICATION_CHANGE, 0, 0, header_info, newcontent);
                //                set_roll_from_llll(x, content, false);
            }
        }
        
        if (new_information) {
            llll_appendllll(out, undo_get_information_as_llll(r_ob, new_information));
            llll_free(new_information->n_it_content);
            bach_freeptr(new_information);
            //            create_undo_redo_tick((t_notation_obj *) x, -what, 1, new_information, false);
        }
    }
    
    return out;
}


// returns 1 if error, 0 otherwise;
// also fills information for reverse transformation, updates measure_whose_flag_needs_to_be_cleared and modifies flags
long notationobj_apply_undo_redo_information(t_notation_obj *r_ob, t_undo_redo_information *this_information, t_llll *measure_whose_flag_needs_to_be_cleared, t_undo_redo_information **reverse_information, long *flags)
{
    char obj_is_score = (r_ob->obj_type == k_NOTATION_OBJECT_SCORE);
    long ID = this_information->n_it_ID;
    e_element_types type = this_information->n_it_type;
    e_undo_modification_types modif_type = this_information->modification_type;
    long voice_num = this_information->voice_num;
    long meas_num = this_information->meas_num;
    e_header_elems header_info = this_information->header_info;
    t_llll *content = this_information->n_it_content;
    t_llll *newcontent = NULL;
    t_notation_item *item = notation_item_retrieve_from_ID(r_ob, ID);
    
    if (reverse_information)
        *reverse_information = NULL;
    
    if (!item && modif_type != k_UNDO_MODIFICATION_ADD && type != k_WHOLE_NOTATION_OBJECT && type != k_HEADER_DATA) {
        return 1;
    }
    
    if (modif_type == k_UNDO_MODIFICATION_CHANGE_FLAG) {
        if (reverse_information) {
            newcontent = get_multiple_flags_for_undo(r_ob, item);
            *reverse_information = build_undo_redo_information(ID, type, k_UNDO_MODIFICATION_CHANGE_FLAG, voice_num, 0, k_HEADER_NONE, newcontent);
        }
        set_multiple_flags_from_llll_for_undo(r_ob, content, item);
        r_ob->are_there_solos = are_there_solos(r_ob);
        
    } else if (modif_type == k_UNDO_MODIFICATION_CHANGE_NAME) {
        if (reverse_information) {
            newcontent = get_names_as_llll(item, false);
            *reverse_information = build_undo_redo_information(ID, type, k_UNDO_MODIFICATION_CHANGE_NAME, voice_num, 0, k_HEADER_NONE, newcontent);
        }
        notation_item_set_names_from_llll(r_ob, item, content);
        
    } else if (type == k_WHOLE_NOTATION_OBJECT){
        // need to reconstruct the whole score
        if (reverse_information) {
            if (r_ob->getstateforundo_function)
                newcontent = (r_ob->getstateforundo_function)((t_object *)r_ob, k_HEADER_ALL, false);
            *reverse_information = build_undo_redo_information(0, k_WHOLE_NOTATION_OBJECT, k_UNDO_MODIFICATION_CHANGE, 0, 0, k_HEADER_NONE, newcontent);
        }
        
        if (r_ob->clearall_function)
            (r_ob->clearall_function)((t_object *)r_ob);
        if (obj_is_score) {
            r_ob->take_rhythmic_tree_for_granted = 1;
            (r_ob->rebuild_function)((t_object *)r_ob, content, false);
            r_ob->take_rhythmic_tree_for_granted = 0;
        } else {
            (r_ob->rebuild_function)((t_object *)r_ob, content, false);
        }
        
    } else if (type == k_MEASURE) {
        t_measure *meas = ((t_measure *)item);
        if (modif_type == k_UNDO_MODIFICATION_CHANGE) { // measure need to be changed
            char need_update_solos = false;
            if (reverse_information) {
                newcontent = measure_get_values_as_llll(r_ob, (t_measure *) item, k_CONSIDER_FOR_UNDO, true, true);
                *reverse_information = build_undo_redo_information(ID, k_MEASURE, k_UNDO_MODIFICATION_CHANGE, voice_num, meas_num, k_HEADER_NONE, newcontent);
            }
            clear_measure(r_ob, meas, true, false, true);
            notation_item_get_ID_from_llll(content); // if there's an ID in the measure, we ignore it.
            if (r_ob->setmeasurefromllll)
                (r_ob->setmeasurefromllll)((t_object *)r_ob, meas, content, true, false, &need_update_solos);
            meas->beaming_calculation_flags = (is_measure_single_whole_rest(r_ob, meas) && r_ob->tree_handling != k_RHYTHMIC_TREE_HANDLING_TAKE_FOR_GRANTED) ? k_BEAMING_CALCULATION_DO : k_BEAMING_CALCULATION_DONT_CHANGE_ANYTHING;
            meas->need_recompute_beamings = true;
            compute_note_approximations_for_measure(r_ob, meas, true);
            (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_ALL_EXCEPT_FOR_BEAMINGS_AND_AUTOCOMPLETION;
            if (need_update_solos) update_solos(r_ob);
            (*flags) |= k_UNDO_PERFORM_FLAG_PERFORM_ANALYSIS_AND_CHANGE;
            llll_appendobj(measure_whose_flag_needs_to_be_cleared, meas, 0, WHITENULL_llll);
        } else if (modif_type == k_UNDO_MODIFICATION_DELETE) { // measure need to be erased
            char need_update_solos = false;
            if (reverse_information) {
                newcontent = measure_get_values_as_llll(r_ob, (t_measure *) item, k_CONSIDER_FOR_UNDO, true, true);
                *reverse_information = build_undo_redo_information(ID, k_MEASURE, k_UNDO_MODIFICATION_ADD, voice_num, meas_num, k_HEADER_NONE, newcontent);
            }
            if (delete_measure(r_ob, meas, meas->firstchord ? chord_get_prev(meas->firstchord) : NULL, &need_update_solos))
                check_correct_scheduling(r_ob, false);
            if (need_update_solos) update_solos(r_ob);
            (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_ALL_EXCEPT_FOR_BEAMINGS_AND_AUTOCOMPLETION;
        } else if (modif_type == k_UNDO_MODIFICATION_ADD) { // measure need to be added
            t_scorevoice *voice = (t_scorevoice *)nth_voice(r_ob, voice_num);
            t_measure *measure;
            char need_update_solos = false;
            if (reverse_information) {
                newcontent = llll_get();
                *reverse_information = build_undo_redo_information(ID, k_MEASURE, k_UNDO_MODIFICATION_DELETE, voice_num, meas_num, k_HEADER_NONE, newcontent);
            }
            measure = build_measure(r_ob, NULL);
            notation_item_get_ID_from_llll(content); // if there's an ID in the measure, we ignore it.
            insert_measure(r_ob, voice, measure, nth_measure_of_scorevoice(voice, meas_num - 1), ID);
            measure->beaming_calculation_flags = k_BEAMING_CALCULATION_DONT_CHANGE_ANYTHING;
            if (r_ob->setmeasurefromllll)
                (r_ob->setmeasurefromllll)((t_object *)r_ob, measure, content, true, false, &need_update_solos);
            compute_note_approximations_for_measure(r_ob, measure, true);
            (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_ALL_EXCEPT_FOR_BEAMINGS_AND_AUTOCOMPLETION;
            if (need_update_solos) update_solos(r_ob);
            (*flags) |= k_UNDO_PERFORM_FLAG_PERFORM_ANALYSIS_AND_CHANGE;
            llll_appendobj(measure_whose_flag_needs_to_be_cleared, measure, 0, WHITENULL_llll);
        }
        
    } else if (type == k_CHORD) {
        if (modif_type == k_UNDO_MODIFICATION_CHANGE || modif_type == k_UNDO_MODIFICATION_CHANGE_CHECK_ORDER) {
            if (reverse_information) {
                newcontent = get_rollchord_values_as_llll(r_ob, (t_chord *) item, k_CONSIDER_FOR_UNDO);
                *reverse_information = build_undo_redo_information(ID, k_CHORD, modif_type, voice_num, 0, k_HEADER_NONE, newcontent);
            }
            if (obj_is_score) {
                set_scorechord_values_from_llll(r_ob, (t_chord *)item, content, true, false);
                compute_note_approximations_for_chord(r_ob, (t_chord *)item, true);
                if (is_solo_with_progeny(r_ob, item)) update_solos(r_ob);
                recompute_all_for_measure(r_ob, ((t_chord *)item)->parent, false);
            } else {
                set_rollchord_values_from_llll(r_ob, (t_chord *)item, content, 0, true, false, false);
                (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH;
                if (modif_type == k_UNDO_MODIFICATION_CHANGE_CHECK_ORDER)
                    (*flags) |= k_UNDO_PERFORM_FLAG_PERFORM_ANALYSIS_AND_CHANGE;
            }
            
        } else if (modif_type == k_UNDO_MODIFICATION_DELETE) { // surely roll
            if (reverse_information) {
                newcontent = get_rollchord_values_as_llll(r_ob, (t_chord *) item, k_CONSIDER_FOR_UNDO);
                *reverse_information = build_undo_redo_information(ID, k_CHORD, k_UNDO_MODIFICATION_ADD, voice_num, 0, k_HEADER_NONE, newcontent);
            }
            (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH;
            if (chord_delete(r_ob, (t_chord *)item, ((t_chord *)item)->prev, false))
                check_correct_scheduling(r_ob, false);
            
        } else if (modif_type == k_UNDO_MODIFICATION_ADD) { // surely roll
            if (reverse_information)
                *reverse_information = build_undo_redo_information(ID, k_CHORD, k_UNDO_MODIFICATION_DELETE, voice_num, 0, k_HEADER_NONE, NULL);
            t_chord *newch = NULL;
            if (r_ob->addchordfromllll)
                (r_ob->addchordfromllll)((t_object *)r_ob, content, (t_rollvoice *)nth_voice(r_ob, voice_num), false, true);
            if (newch)
                newch->need_recompute_parameters = true;
        }
        
    } else if (type == k_HEADER_DATA) {
        if (modif_type == k_UNDO_MODIFICATION_CHANGE) {
            if (reverse_information) {
                newcontent = (r_ob->getstateforundo_function)((t_object *)r_ob, header_info, false);
                *reverse_information = build_undo_redo_information(0, k_HEADER_DATA, k_UNDO_MODIFICATION_CHANGE, 0, 0, header_info, newcontent);
            }
            if (obj_is_score) {
                r_ob->take_rhythmic_tree_for_granted = 1;
                (r_ob->rebuild_function)((t_object *)r_ob, content, false);
                r_ob->take_rhythmic_tree_for_granted = 0;
            } else {
                (r_ob->rebuild_function)((t_object *)r_ob, content, false);
            }
        }
    }
    
    return 0;
}




// what = -1 -> undo, what = 1 -> redo
long notationobj_undo_redo(t_notation_obj *r_ob, char what)
{
    long flags = k_UNDO_PERFORM_FLAG_NONE;
    t_llll *llll = NULL;
    long undo_op = k_UNDO_OP_UNKNOWN;
    char obj_is_score = (r_ob->obj_type == k_NOTATION_OBJECT_SCORE);
    t_llll *measure_whose_flag_needs_to_be_cleared = obj_is_score ? llll_get() : NULL;

    systhread_mutex_lock(r_ob->c_undo_mutex);
    
    if (what == k_UNDO)
        llll = r_ob->undo_llll;
    else if (what == k_REDO)
        llll = r_ob->redo_llll;
    
    if (!llll) {
        llll_free(measure_whose_flag_needs_to_be_cleared);
        systhread_mutex_unlock(r_ob->c_undo_mutex);
        unlock_general_mutex(r_ob);
        return flags;
    }
    
    while (llll->l_head && hatom_gettype(&llll->l_head->l_hatom) != H_LONG){
        object_error((t_object *) r_ob, what == k_UNDO ? "Wrongly placed undo tick!" : "Wrongly placed redo tick!");
        llll_destroyelem(llll->l_head);
    }
    
    if (!llll->l_head) {
        if (!(atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0))
            object_warn((t_object *) r_ob, what == k_UNDO ? "Can't undo!" : "Can't redo!");
        llll_free(measure_whose_flag_needs_to_be_cleared);
        systhread_mutex_unlock(r_ob->c_undo_mutex);
        unlock_general_mutex(r_ob);
        return flags;
    }
    
    undo_op = hatom_getlong(&llll->l_head->l_hatom);
    if (r_ob->verbose_undo_redo) {
        char buf[256];
        undo_op_to_string(undo_op, buf);
        object_post((t_object *) r_ob, "%s %s", what == k_UNDO ? "Undo" : "Redo", buf);
    }
    
    // Destroy the marker
    if (llll->l_head == r_ob->last_undo_marker)
        r_ob->last_undo_marker = NULL;
    llll_destroyelem(llll->l_head);
    
    
    if (what == k_UNDO)
        r_ob->num_undo_steps--;
    else
        r_ob->num_redo_steps--;
    
    while (llll->l_head && hatom_gettype(&llll->l_head->l_hatom) == H_OBJ){
        t_undo_redo_information *this_information = (t_undo_redo_information *)hatom_getobj(&llll->l_head->l_hatom);
        t_undo_redo_information *reverse_information = NULL;

        if (notationobj_apply_undo_redo_information(r_ob, this_information, measure_whose_flag_needs_to_be_cleared, &reverse_information, &flags)) {
            object_error((t_object *) r_ob, "Wrong undo/redo data");
            llll_destroyelem(llll->l_head);
            continue;
        }

        if (reverse_information)
            create_undo_redo_tick(r_ob, -what, 1, reverse_information, false);
        
        llll_free(this_information->n_it_content);
        bach_freeptr(this_information);
        llll_destroyelem(llll->l_head);
    }
    
    if (flags & k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH) {
        recompute_total_length(r_ob);
        flags = flags & (~k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH);
    }
    
    if (obj_is_score) {
        for (t_llllelem *elem = measure_whose_flag_needs_to_be_cleared->l_head; elem; elem = elem->l_next)
            ((t_measure *)hatom_getobj(&elem->l_hatom))->beaming_calculation_flags = k_BEAMING_CALCULATION_DO;
        llll_free(measure_whose_flag_needs_to_be_cleared);
    }
    
    create_undo_redo_step_marker(r_ob, -what, 1, undo_op, false);
    systhread_mutex_unlock(r_ob->c_undo_mutex);
    
    return flags;
}






void send_changed_bang_and_automessage_if_needed(t_notation_obj *r_ob)
{
    if (r_ob->need_send_changed_bang) {
        
        r_ob->need_send_changed_bang = false;
        
        long outlet_number = 2;
        if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
            outlet_number = 7;
        else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
            outlet_number = 8;
        else if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
            outlet_number = 2;
        
        if (r_ob->notify_with) {
            t_llll *notifllll = get_undo_op_for_notification(r_ob);
            llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet_number, notifllll);
            llll_free(notifllll);
        } else {
            llllobj_outlet_bang((t_object *) r_ob, LLLL_OBJ_UI, outlet_number);
        }
    }
    
    if (r_ob->need_send_automessage) {
        t_atom result;
        
        r_ob->need_send_automessage = false;
        
        r_ob->itsme = true;
        r_ob->is_sending_automessage = true;
        if (object_method_typed(r_ob, NULL, r_ob->automessage_ac, r_ob->automessage_av, &result) != MAX_ERR_NONE)
            object_error((t_object *)r_ob, "Automessage could not be sent.");
        r_ob->is_sending_automessage = false;
        r_ob->itsme = false;
    }
}



