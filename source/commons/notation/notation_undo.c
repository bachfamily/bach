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

typedef struct _reordering_helper
{
    t_undo_redo_information *info;
    long appearance_order;
    long position;
    char type; // 1 = starting, -1 = ending
    double onset;
} t_reordering_helper;

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

long undo_redo_tick_create(t_notation_obj *r_ob, char what, char from_what, t_undo_redo_information *operation, char lock_undo_mutex)
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
    
    llll_prependobj(what == k_UNDO ? r_ob->undo_llll : r_ob->redo_llll, operation);
    
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
    undo_ticks_remove_dangling(r_ob, true);
    
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


char* get_string_for_tick(t_hatom *h, long maxdecimals)
{
    if (hatom_gettype(h) == H_OBJ) {
        char *out;
        t_undo_redo_information *info = (t_undo_redo_information *)hatom_getobj(h);
        long ID = info->n_it_ID;
        long type = info->n_it_type;
        long modif = info->modification_type;
        t_symbol *param = info->param;
        out = (char *)bach_newptr(20 * sizeof(char));
        snprintf_zero(out, 20, "(%s%ld%s%s)",
                      type == k_WHOLE_NOTATION_OBJECT ? "w" : (type == k_HEADER_DATA ? "h" : (type == k_MEASURE ? "m" : (type == k_CHORD ? "c" : (type == k_VOICE ? "v" : (type == k_NOTE ? "n" : "?"))))),
                      ID,
                      modif == k_UNDO_MODIFICATION_TYPE_ADD ? "+" : (modif == k_UNDO_MODIFICATION_TYPE_DELETE ? "-" : (modif == k_UNDO_MODIFICATION_TYPE_CHANGE ? "~" : (modif == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER ? "*" : "?"))),
                      param == _llllobj_sym_flag ? "f" : (param == _llllobj_sym_name ? "n" : (param == _llllobj_sym_onset ? "o" : (param == _llllobj_sym_state ? "s" : "?"))));
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


int reordering_comparator(const void* p0, const void* p1)
{
    t_reordering_helper* ps0 = (t_reordering_helper*) p0;
    t_reordering_helper* ps1 = (t_reordering_helper*) p1;
    if (ps0->type == ps1->type)
        return ps0->position - ps1->position;
    else
        return ps0->onset - ps1->onset;
}

t_llllelem *undo_redo_step_marker_create(t_notation_obj *r_ob, char what, char from_what, long undo_op, char lock_undo_mutex)
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

        // THIS PART IS ONLY NEEDED IF notify_with != bang and != operation name
        if (r_ob->notify_with > 1) {
            long i = 0, N = r_ob->undo_information_whose_path_need_to_be_checked->l_size, M = 2*N;
            if (N > 0) {
                t_reordering_helper *helper = (t_reordering_helper *)sysmem_newptr(M*sizeof(t_reordering_helper));
                for (t_llllelem *el = r_ob->undo_information_whose_path_need_to_be_checked->l_head; el; el = el->l_next) {
                    // updating the paths
                    t_undo_redo_information *info = (t_undo_redo_information *)hatom_getobj(&el->l_hatom);
                    
                    t_notation_item *item = notation_item_retrieve_from_ID(r_ob, info->n_it_ID);
                    double item_onset = notation_item_get_onset_ms(r_ob, item);
                    notation_item_get_path(r_ob, item, &info->n_it_path_before);
                    
                    // preparing the structure in order for them to work as a sequence of separate changes (see "onsetbraids.pdf")
                    helper[2*i].info = info;
                    helper[2*i].appearance_order = i;
                    helper[2*i].position = info->n_it_path_after.chord_num;
                    helper[2*i].type = 1;
                    helper[2*i].onset = info->n_it_content && info->n_it_content->l_head ? hatom_getdouble(&info->n_it_content->l_head->l_hatom) : item_onset;
                    
                    helper[2*i+1].info = info;
                    helper[2*i+1].appearance_order = i;
                    helper[2*i+1].position = info->n_it_path_before.chord_num;
                    helper[2*i+1].type = -1;
                    helper[2*i+1].onset = notation_item_get_onset_ms(r_ob, item);
                    
                    i++;
                }
                
                // sort helper structure
                qsort(helper, M, sizeof(t_reordering_helper), reordering_comparator);
                
                // now modify positions
                char done[N];
                for (long i = 0; i < M; i++)
                    done[i] = 0;
                for (long i = 0; i < M; i++) {
                    if (!done[i]) {
                        char is_start = (helper[i].type == 1);
                        // find corresponding end
                        for (long j = i+1; j < M; j++) {
                            if (helper[j].appearance_order == helper[i].appearance_order) {
                                done[j] = true;
                                break; // found the corresponding one
                            } else if (helper[j].appearance_order > helper[i].appearance_order) {
                                if (helper[j].type == 1) // start
                                    helper[j].position += (is_start ? -1 : 1);
                            } else {
                                if (helper[j].type == -1) // end
                                    helper[j].position += (is_start ? 1 : -1);
                            }
                        }
                        done[i] = true;
                    }
                }
                
                // finally, plug everything back
                for (long i = 0; i < M; i++) {
                    if (helper[i].type == 1)
                        helper[i].info->n_it_path_after.chord_num = helper[i].position;
                    else if (helper[i].type == -1)
                        helper[i].info->n_it_path_before.chord_num = helper[i].position;
                }
            }
        }

        llll_clear(r_ob->undo_notation_items_under_tick);
        llll_clear(r_ob->undo_information_whose_path_need_to_be_checked);
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
    
    r_ob->last_operation_is = 0;
    
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

void undo_tick_create_for_header(t_notation_obj *r_ob, e_header_elems what)
{
    if (r_ob->inhibited_undo)
        return;
    
    if (atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0)
        return;
    
    if (r_ob->undo_header_elements_under_tick & what) // no need to add a tick for this header element: already added!!
        return;
    
    r_ob->undo_header_elements_under_tick |= what;
    t_llll *content = get_notationobj_header_as_llll(r_ob, what, true, true, true, k_CONSIDER_FOR_UNDO);
    t_undo_redo_information *operation = undo_redo_information_create(0, k_HEADER_DATA, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state, 0, 0, what, content);
    undo_redo_tick_create(r_ob, k_UNDO, 0, operation, true);
}




void undo_redo_tick_post(t_notation_obj *r_ob, long what, t_undo_redo_information *info)
{
    char *buf = NULL;
    char buf2[256];
    llll_to_text_buf(info->n_it_content, &buf, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
    object_post((t_object *) r_ob, " > %s", what == k_UNDO ? "UNDO" : (what == k_REDO ? "REDO" : "UNKNOWN OPERATION"));
    object_post((t_object *) r_ob, " > ID = %ld", info->n_it_ID);
    object_post((t_object *) r_ob, " > TYPE = %s", info->n_it_type == k_CHORD ? "chord" : (info->n_it_type == k_VOICE ? "voice" : (info->n_it_type == k_MEASURE ? "measure" : (info->n_it_type == k_HEADER_DATA ? "header data" : (info->n_it_type == k_WHOLE_NOTATION_OBJECT ? "whole notation object" : "unknown")))));
    object_post((t_object *) r_ob, " > MODIFICATION = %s", info->modification_type == k_UNDO_MODIFICATION_TYPE_CHANGE ? "change" : (info->modification_type == k_UNDO_MODIFICATION_TYPE_ADD ? "add" : (info->modification_type == k_UNDO_MODIFICATION_TYPE_DELETE ? "delete" : (info->modification_type == k_UNDO_MODIFICATION_TYPE_NONE ? "none" : "unknown"))));
    object_post((t_object *) r_ob, " > CONTENT = %s", buf);
    object_post((t_object *) r_ob, " > MEASURE NUMBER = %ld", info->n_it_path_before.meas_num);
    object_post((t_object *) r_ob, " > VOICE NUMBER = %ld", info->n_it_path_before.voice_num);
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
        case k_UNDO_OP_GENERIC_CHANGE:
            sprintf(buf, "Generic Change");
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
        case k_UNDO_OP_CHANGE_MARKERS_ONSET:
            sprintf(buf, "Change Markers Onset");
            break;
        case k_UNDO_OP_DUPLICATE_MARKERS:
            sprintf(buf, "Duplicate Markers");
            break;
        case k_UNDO_OP_DUPLICATE_ITEMS:
            sprintf(buf, "Duplicate Items");
            break;
        case k_UNDO_OP_STRETCH_MARKER_REGION:
            sprintf(buf, "Stretch Marker Region");
            break;
        case k_UNDO_OP_MOVE_MARKER_REGION:
            sprintf(buf, "Move Marker Region");
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
        case k_UNDO_OP_CHANGE_PITCH_BREAKPOINTS:
            sprintf(buf, "Change Pitch Breakpoints");
            break;
        case k_UNDO_OP_CHANGE_PITCH_BREAKPOINT_SLOPE:
            sprintf(buf, "Change Pitch Breakpoint Slope");
            break;
        case k_UNDO_OP_CHANGE_PITCH_BREAKPOINT_VELOCITY:
            sprintf(buf, "Change Pitch Breakpoint Velocity");
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


t_symbol *undo_op_to_symbol(long undo_op, char prepend_undo_label)
{
    char buf[256];
    if (prepend_undo_label) {
        sprintf(buf, "Undo ");
        undo_op_to_string(undo_op, buf+5);
    } else {
        undo_op_to_string(undo_op, buf);
    }
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

// TODO: remove gensym()
e_element_types element_type_from_symbol(t_symbol *sym)
{
    if (sym == _llllobj_sym_note)
        return k_NOTE;

    if (sym == gensym("durationline"))
        return k_DURATION_LINE;

    if (sym == _llllobj_sym_tail)
        return k_DURATION_TAIL;

    if (sym == _llllobj_sym_breakpoint)
        return k_PITCH_BREAKPOINT;

    if (sym == _llllobj_sym_chord)
        return k_CHORD;

    if (sym == _llllobj_sym_measure)
        return k_MEASURE;

    if (sym == gensym("breakpointortail"))
        return k_PITCH_BREAKPOINT_OR_DURATION_TAIL;

    if (sym == _llllobj_sym_voice)
        return k_VOICE;
    
    if (sym == _llllobj_sym_tempo)
        return k_TEMPO;

    if (sym == gensym("mixed"))
        return k_MIXED;

    if (sym == _llllobj_sym_timesig)
        return k_TIME_SIGNATURE;

    if (sym == gensym("whole"))
        return k_WHOLE_NOTATION_OBJECT;

    if (sym == _llllobj_sym_header)
        return k_HEADER_DATA;

    if (sym == _llllobj_sym_slotinfo)
        return k_SLOTINFO;

    if (sym == _llllobj_sym_marker)
        return k_MARKER;


    // TO DO: ALL THE OTHER CASES, it's just a beginning...
    
    return k_NONE;
}

t_symbol *undo_modification_type_to_symbol(e_undo_modification_types modif_type)
{
    switch (modif_type) {
        case k_UNDO_MODIFICATION_TYPE_NONE: return gensym("none"); break;
        case k_UNDO_MODIFICATION_TYPE_ADD: return gensym("add"); break;
        case k_UNDO_MODIFICATION_TYPE_DELETE: return gensym("delete"); break;
        case k_UNDO_MODIFICATION_TYPE_CHANGE: return gensym("change"); break;
        case k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER: return gensym("change"); break;
        default: return gensym("unknown"); break;
    }
}

e_undo_modification_types undo_modification_type_from_symbol(t_notation_obj *r_ob, t_symbol *sym, e_element_types el_type)
{
    if (sym == gensym("add"))
        return k_UNDO_MODIFICATION_TYPE_ADD;
    if (sym == gensym("delete"))
        return k_UNDO_MODIFICATION_TYPE_DELETE;
    if (sym == gensym("change")) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && (el_type == k_CHORD || el_type == k_MARKER || el_type == k_NOTE))
            return k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER;
        else
            return k_UNDO_MODIFICATION_TYPE_CHANGE;
    }
    return k_UNDO_MODIFICATION_TYPE_NONE;
}


t_undo_redo_information *undo_redo_information_create(long ID, e_element_types type, e_undo_modification_types modif_type, t_symbol *param, t_notation_item_path *nitem_path_before, t_notation_item_path *nitem_path_after, e_header_elems header_info, t_llll *content)
{
    t_undo_redo_information *out = (t_undo_redo_information *)bach_newptr(sizeof(t_undo_redo_information));
    out->n_it_ID = ID;
    out->n_it_type = type;
    out->modification_type = modif_type;
    out->param = param;
    out->n_it_content = content;
    if (nitem_path_before)
        out->n_it_path_before = *nitem_path_before;
    else
        notation_item_get_path(NULL, NULL, &out->n_it_path_before); // puts everything to -1;
    if (nitem_path_after)
        out->n_it_path_after = *nitem_path_after;
    else
        notation_item_get_path(NULL, NULL, &out->n_it_path_after); // puts everything to -1;
    out->header_info = header_info;
    return out;
}

long undo_op_reverse(long undo_operation){
    if (undo_operation == k_UNDO_OP_ADD_MEASURE)
        return k_UNDO_OP_DELETE_MEASURE;
    else if (undo_operation == k_UNDO_OP_ADD_CHORD)
        return k_UNDO_OP_DELETE_CHORD;
    else if (undo_operation == k_UNDO_OP_ADD_VOICE)
        return k_UNDO_OP_DELETE_VOICE;
    else if (undo_operation == k_UNDO_OP_ADD_MEASURES)
        return k_UNDO_OP_DELETE_MEASURES;
    else if (undo_operation == k_UNDO_OP_ADD_CHORDS)
        return k_UNDO_OP_DELETE_CHORDS;
    else if (undo_operation == k_UNDO_OP_ADD_VOICES)
        return k_UNDO_OP_DELETE_VOICES;
    else if (undo_operation == k_UNDO_OP_ADD_MARKER)
        return k_UNDO_OP_DELETE_MARKER;
    return undo_operation;
}


long undo_op_make_plural(long undo_operation){
    if (undo_operation == k_UNDO_OP_ADD_MEASURE)
        return k_UNDO_OP_ADD_MEASURES;
    else if (undo_operation == k_UNDO_OP_CHANGE_MEASURE)
        return k_UNDO_OP_CHANGE_MEASURES;
    else if (undo_operation == k_UNDO_OP_DELETE_MEASURE)
        return k_UNDO_OP_DELETE_MEASURES;
    else if (undo_operation == k_UNDO_OP_ADD_CHORD)
        return k_UNDO_OP_ADD_CHORDS;
    else if (undo_operation == k_UNDO_OP_CHANGE_CHORD)
        return k_UNDO_OP_CHANGE_CHORDS;
    else if (undo_operation == k_UNDO_OP_DELETE_CHORD)
        return k_UNDO_OP_DELETE_CHORDS;
    else if (undo_operation == k_UNDO_OP_ADD_VOICE)
        return k_UNDO_OP_ADD_VOICES;
    else if (undo_operation == k_UNDO_OP_CHANGE_VOICE)
        return k_UNDO_OP_CHANGE_VOICES;
    else if (undo_operation == k_UNDO_OP_DELETE_VOICE)
        return k_UNDO_OP_DELETE_VOICES;
    return undo_operation;
}

// outputs a 1-based llll
t_llll *notation_item_path_to_llll(t_notation_item_path *path)
{
    t_llll *out = llll_get();
    if (path->voice_num >= 0)
        llll_appendlong(out, path->voice_num+1);
    if (path->meas_num >= 0)
        llll_appendlong(out, path->meas_num+1);
    if (path->chord_num >= 0)
        llll_appendlong(out, path->chord_num+1);
    if (path->note_num >= 0)
        llll_appendlong(out, path->note_num+1);
    if (path->slot_num >= 0)
        llll_appendlong(out, path->slot_num+1);
    if (path->item_num >= 0)
        llll_appendlong(out, path->item_num+1);
    return out;
}

void notation_item_path_from_llll(t_notation_obj *r_ob, e_element_types type, t_llll *ll, t_notation_item_path *path)
{
    notation_item_get_path(NULL, NULL, path); // just to put -1 everywhere
    
    if (!ll)
        return;
    
    switch (type) {
        case k_NOTE:
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (ll->l_size >= 4) {
                    path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
                    path->meas_num = hatom_getlong(&ll->l_head->l_next->l_hatom)-1;
                    path->chord_num = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom)-1;
                    path->note_num = hatom_getlong(&ll->l_head->l_next->l_next->l_next->l_hatom)-1;
                }
            } else {
                if (ll->l_size >= 3) {
                    path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
                    path->chord_num = hatom_getlong(&ll->l_head->l_next->l_hatom)-1;
                    path->note_num = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom)-1;
                }
            }
            break;
        case k_CHORD:
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (ll->l_size >= 3) {
                    path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
                    path->meas_num = hatom_getlong(&ll->l_head->l_next->l_hatom)-1;
                    path->chord_num = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom)-1;
                }
            } else {
                if (ll->l_size >= 2) {
                    path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
                    path->chord_num = hatom_getlong(&ll->l_head->l_next->l_hatom)-1;
                }
            }
            break;
        case k_MEASURE:
            if (ll->l_size >= 2) {
                path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
                path->meas_num = hatom_getlong(&ll->l_head->l_next->l_hatom)-1;
            }
            break;
        case k_VOICE:
            if (ll->l_size >= 1) {
                path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
            }
            break;
        case k_MARKER:
            if (ll->l_size >= 1) {
                path->item_num = hatom_getlong(&ll->l_head->l_hatom)-1;
            }
            break;
        case k_PITCH_BREAKPOINT:
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (ll->l_size >= 5) {
                    path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
                    path->meas_num = hatom_getlong(&ll->l_head->l_next->l_hatom)-1;
                    path->chord_num = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom)-1;
                    path->note_num = hatom_getlong(&ll->l_head->l_next->l_next->l_next->l_hatom)-1;
                    path->item_num = hatom_getlong(&ll->l_head->l_next->l_next->l_next->l_next->l_hatom)-1;
                }
            } else {
                if (ll->l_size >= 4) {
                    path->voice_num = hatom_getlong(&ll->l_head->l_hatom)-1;
                    path->chord_num = hatom_getlong(&ll->l_head->l_next->l_hatom)-1;
                    path->note_num = hatom_getlong(&ll->l_head->l_next->l_next->l_hatom)-1;
                    path->item_num = hatom_getlong(&ll->l_head->l_next->l_next->l_next->l_hatom)-1;
                }
            }
            break;
        default:
            break;
    }
}


long undo_redo_information_to_llll_remove_ids(void *data, t_hatom *a, const t_llll *address){
    if (hatom_gettype(a) == H_LLLL){
        t_llll *ll = hatom_getllll(a);
        for (t_llllelem *el = ll->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll2 = hatom_getllll(&el->l_hatom);
                if (ll2 && ll2->l_head && hatom_getsym(&ll2->l_head->l_hatom) == _llllobj_sym_ID) {
                    // destroy
                    llll_destroyelem(el);
                    break;
                }
            }
        }
    }
    return 0;
}

char notation_item_path_eq(t_notation_item_path *path1, t_notation_item_path *path2)
{
    if (path1->voice_num == path2->voice_num &&
        path1->meas_num == path2->meas_num &&
        path1->chord_num == path2->chord_num &&
        path1->note_num == path2->note_num &&
        path1->slot_num == path2->slot_num &&
        path1->item_num == path2->item_num)
        return 1;
    return 0;
}

void notation_item_path_diff(t_notation_item_path *path1, t_notation_item_path *path2, t_notation_item_path *res)
{
    res->voice_num = path1->voice_num - path2->voice_num;
    res->meas_num = path1->meas_num - path2->meas_num;
    res->chord_num = path1->chord_num - path2->chord_num;
    res->note_num = path1->note_num - path2->note_num;
    res->slot_num = path1->slot_num - path2->slot_num;
    res->item_num = path1->item_num - path2->item_num;
}

t_llll *undo_redo_information_to_llll(t_notation_obj *r_ob, t_undo_redo_information *info)
{
    t_llll *ll = llll_get();
    llll_appendsym(ll, undo_modification_type_to_symbol(info->modification_type));
    llll_appendsym(ll, element_type_to_symbol(info->n_it_type));

    // path
    t_llll *subll = llll_get();
    llll_appendllll(subll, notation_item_path_to_llll(&info->n_it_path_before));
    llll_appendllll(subll, notation_item_path_to_llll(&info->n_it_path_after));
    llll_appendllll(ll, subll);

    llll_appendsym(ll, info->param);

    // content
    if (info->n_it_content) {
        t_llll *cloned = llll_clone(info->n_it_content);
        llll_funall(cloned, (fun_fn) undo_redo_information_to_llll_remove_ids, NULL, 1, -3, FUNALL_PROCESS_WHOLE_SUBLISTS);
        llll_appendllll(ll, cloned);
    }
    return ll;
}


t_undo_redo_information *undo_redo_information_from_llll(t_notation_obj *r_ob, t_llll *ll)
{
    t_undo_redo_information *info = (t_undo_redo_information *)bach_newptrclear(sizeof(t_undo_redo_information));
    t_notation_item_path path_start, path_end;
    
    // put everything to -1
    notation_item_get_path(NULL, NULL, &path_start);
    notation_item_get_path(NULL, NULL, &path_end);

    if (ll->l_size >= 4) {
        e_element_types el_type = element_type_from_symbol(hatom_getsym(&ll->l_head->l_next->l_hatom));
        e_undo_modification_types modif_type = undo_modification_type_from_symbol(r_ob, hatom_getsym(&ll->l_head->l_hatom), el_type);

        if (hatom_gettype(&ll->l_head->l_next->l_next->l_hatom) == H_LLLL) {
            t_llll *paths = hatom_getllll(&ll->l_head->l_next->l_next->l_hatom);
            if (paths->l_depth == 1) {
                notation_item_path_from_llll(r_ob, el_type, paths, &path_start);
                path_end = path_start;
            } else if (paths->l_size == 2) {
                notation_item_path_from_llll(r_ob, el_type, hatom_getllll(&paths->l_head->l_hatom), &path_start);
                notation_item_path_from_llll(r_ob, el_type, hatom_getllll(&paths->l_head->l_next->l_hatom), &path_end);
            }
        }
        
        t_symbol *param = hatom_getsym(&ll->l_head->l_next->l_next->l_next->l_hatom);
        
        // getting ID
        t_notation_item *item = notation_item_from_path(r_ob, el_type, &path_start);
        
        if (!item && modif_type != k_UNDO_MODIFICATION_TYPE_ADD && el_type != k_WHOLE_NOTATION_OBJECT && el_type != k_HEADER_DATA) {
            bach_freeptr(info);
            return NULL;
        }
        
        t_llll *content = (ll->l_size >= 5) ? llll_clone(hatom_getllll(&ll->l_head->l_next->l_next->l_next->l_next->l_hatom)) : NULL;

        e_header_elems header_info = k_HEADER_NONE;
        if (el_type == k_HEADER_DATA) {
            for (t_llllelem *el = content->l_head; el; el = el->l_next) {
                if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                    t_llll *ll = hatom_getllll(&el->l_hatom);
                    if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM) {
                        t_symbol *s = hatom_getsym(&ll->l_head->l_hatom);
                        header_info = (e_header_elems) (header_info | header_symbol_to_long(s));
                    }
                }
            }
        }

        info = undo_redo_information_create(item ? item->ID : 0, el_type, modif_type, param, &path_start, &path_end, header_info, content);
    }
    return info;
}



void undo_redo_information_free(t_undo_redo_information *this_information)
{
    if (this_information->n_it_content)
        llll_free(this_information->n_it_content);
    bach_freeptr(this_information);
}


// allocates the new information: needs to be freed
t_undo_redo_information *undo_redo_information_reverse(t_notation_obj *r_ob, t_undo_redo_information *this_information)
{
    char obj_is_score = (r_ob->obj_type == k_NOTATION_OBJECT_SCORE);
    long ID = this_information->n_it_ID;
    e_element_types type = this_information->n_it_type;
    t_symbol *param = this_information->param;
    e_undo_modification_types modif_type = this_information->modification_type;
    t_notation_item_path *path_before = &this_information->n_it_path_before;
    t_notation_item_path *path_after = &this_information->n_it_path_after;
    e_header_elems header_info = this_information->header_info;
    t_llll *newcontent = NULL;
    t_notation_item *item = notation_item_retrieve_from_ID(r_ob, ID);
    
    t_undo_redo_information *reverse_information = NULL;
    
    if (!item && modif_type != k_UNDO_MODIFICATION_TYPE_ADD && type != k_WHOLE_NOTATION_OBJECT && type != k_HEADER_DATA) {
        return reverse_information;
    }
    
    if (param == _llllobj_sym_flag) {
        newcontent = get_multiple_flags_for_undo(r_ob, item);
        reverse_information = undo_redo_information_create(ID, type, k_UNDO_MODIFICATION_TYPE_CHANGE, param, path_after, path_before, k_HEADER_NONE, newcontent);
        
    } else if (param == _llllobj_sym_name) {
        newcontent = get_names_as_llll(item, false);
        reverse_information = undo_redo_information_create(ID, type, k_UNDO_MODIFICATION_TYPE_CHANGE, param, path_after, path_before, k_HEADER_NONE, newcontent);
        
    } else if (type == k_WHOLE_NOTATION_OBJECT){
        // need to reconstruct the whole score
        if (r_ob->getstateforundo_function)
            newcontent = (r_ob->getstateforundo_function)((t_object *)r_ob, k_HEADER_ALL, false);
        reverse_information = undo_redo_information_create(0, k_WHOLE_NOTATION_OBJECT, k_UNDO_MODIFICATION_TYPE_CHANGE, param, 0, 0, k_HEADER_NONE, newcontent);
        
    } else if (type == k_MEASURE) {
        if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE) { // measure need to be changed
            newcontent = measure_get_values_as_llll(r_ob, (t_measure *) item, k_CONSIDER_FOR_UNDO, true, true);
            reverse_information = undo_redo_information_create(ID, k_MEASURE, k_UNDO_MODIFICATION_TYPE_CHANGE, param, path_after, path_before, k_HEADER_NONE, newcontent);
        } else if (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) { // measure need to be erased
            newcontent = measure_get_values_as_llll(r_ob, (t_measure *) item, k_CONSIDER_FOR_UNDO, true, true);
//            newcontent = llll_clone(this_information->n_it_content);
            reverse_information = undo_redo_information_create(ID, k_MEASURE, k_UNDO_MODIFICATION_TYPE_ADD, param, path_after, path_before, k_HEADER_NONE, newcontent);
        } else if (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) { // measure need to be added
            newcontent = llll_get();
//            newcontent = llll_clone(this_information->n_it_content);
            reverse_information = undo_redo_information_create(ID, k_MEASURE, k_UNDO_MODIFICATION_TYPE_DELETE, param, path_after, path_before, k_HEADER_NONE, newcontent);
        }
        
    } else if (type == k_CHORD) {
        if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE || modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER) {
            if (obj_is_score)
                newcontent = get_scorechord_values_as_llll(r_ob, (t_chord *) item, k_CONSIDER_FOR_UNDO, false);
            else
                newcontent = get_rollchord_values_as_llll(r_ob, (t_chord *) item, k_CONSIDER_FOR_UNDO);
            reverse_information = undo_redo_information_create(ID, k_CHORD, modif_type, param, path_after, path_before, k_HEADER_NONE, newcontent);
        } else if (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) { // surely roll
            newcontent = get_rollchord_values_as_llll(r_ob, (t_chord *) item, k_CONSIDER_FOR_UNDO);
//            newcontent = llll_clone(this_information->n_it_content);
            reverse_information = undo_redo_information_create(ID, k_CHORD, k_UNDO_MODIFICATION_TYPE_ADD, param, path_after, path_before, k_HEADER_NONE, newcontent);
        } else if (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) { // surely roll
            newcontent = llll_get();
//            newcontent = llll_clone(this_information->n_it_content);
            reverse_information = undo_redo_information_create(ID, k_CHORD, k_UNDO_MODIFICATION_TYPE_DELETE, param, path_after, path_before, k_HEADER_NONE, newcontent);
        }
    } else if (type == k_MARKER) {
        if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE || modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER) {
            newcontent = get_single_marker_as_llll(r_ob, (t_marker *)item, false, false);
            reverse_information = undo_redo_information_create(ID, k_MARKER, modif_type, param, path_after, path_before, k_HEADER_NONE, newcontent);
        } else if (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) { // surely roll
            newcontent = get_single_marker_as_llll(r_ob, (t_marker *)item, false, false);
            reverse_information = undo_redo_information_create(ID, k_MARKER, k_UNDO_MODIFICATION_TYPE_ADD, param, path_after, path_before, k_HEADER_NONE, newcontent);
        } else if (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) { // surely roll
            newcontent = llll_get();
            reverse_information = undo_redo_information_create(ID, k_MARKER, k_UNDO_MODIFICATION_TYPE_DELETE, param, path_after, path_before, k_HEADER_NONE, newcontent);
        }
        
    } else if (type == k_HEADER_DATA) {
        if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE) {
            newcontent = (r_ob->getstateforundo_function)((t_object *)r_ob, header_info, false);
            reverse_information = undo_redo_information_create(0, k_HEADER_DATA, k_UNDO_MODIFICATION_TYPE_CHANGE, param, path_after, path_before, header_info, newcontent);
        }
    }
    
    return reverse_information;
}


// returns 1 if error, 0 otherwise;
// also fills information for reverse transformation, updates measure_whose_flag_needs_to_be_cleared and modifies flags
long undo_redo_information_apply(t_notation_obj *r_ob, t_undo_redo_information *this_information, t_llll *measure_whose_flag_needs_to_be_cleared, long *flags)
{
    char obj_is_score = (r_ob->obj_type == k_NOTATION_OBJECT_SCORE);
    long ID = this_information->n_it_ID;
    e_element_types type = this_information->n_it_type;
    e_undo_modification_types modif_type = this_information->modification_type;
    t_symbol *param = this_information->param;
    long voice_num = this_information->n_it_path_before.voice_num;
    long meas_num = this_information->n_it_path_before.meas_num;
    e_header_elems header_info = this_information->header_info;
    t_llll *content = this_information->n_it_content;
    t_notation_item *item = notation_item_retrieve_from_ID(r_ob, ID);
    
    if (!item && modif_type != k_UNDO_MODIFICATION_TYPE_ADD && type != k_WHOLE_NOTATION_OBJECT && type != k_HEADER_DATA) {
        return 1;
    }
    
    if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE && param == _llllobj_sym_flag) {
        set_multiple_flags_from_llll_for_undo(r_ob, content, item);
        r_ob->are_there_solos = are_there_solos(r_ob);
        
    } else if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE && param == _llllobj_sym_name) {
        notation_item_set_names_from_llll(r_ob, item, content);
        
    } else if (param == _llllobj_sym_state) {
        if (type == k_WHOLE_NOTATION_OBJECT){
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
            if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE) { // measure need to be changed
                char need_update_solos = false;
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
            } else if (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) { // measure need to be erased
                char need_update_solos = false;
                if (delete_measure(r_ob, meas, meas->firstchord ? chord_get_prev(meas->firstchord) : NULL, &need_update_solos))
                    check_correct_scheduling(r_ob, false);
                if (need_update_solos) update_solos(r_ob);
                (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_ALL_EXCEPT_FOR_BEAMINGS_AND_AUTOCOMPLETION;
            } else if (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) { // measure need to be added
                t_scorevoice *voice = (t_scorevoice *)nth_voice_safe(r_ob, voice_num);
                t_measure *measure;
                char need_update_solos = false;
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
            if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE || modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER) {
                if (obj_is_score) {
                    set_scorechord_values_from_llll(r_ob, (t_chord *)item, content, true, false);
                    compute_note_approximations_for_chord(r_ob, (t_chord *)item, true);
                    if (is_solo_with_progeny(r_ob, item)) update_solos(r_ob);
                    recompute_all_for_measure(r_ob, ((t_chord *)item)->parent, false);
                } else {
                    set_rollchord_values_from_llll(r_ob, (t_chord *)item, content, 0, true, false, false);
                    (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH;
                    if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER)
                        (*flags) |= k_UNDO_PERFORM_FLAG_CHECK_ORDER_FOR_CHORDS;
                }
                
            } else if (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) { // surely roll
                (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH;
                if (chord_delete(r_ob, (t_chord *)item, ((t_chord *)item)->prev, false))
                    check_correct_scheduling(r_ob, false);
                
            } else if (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) { // surely roll
                t_chord *newch = NULL;
                if (r_ob->addchordfromllll)
                    (r_ob->addchordfromllll)((t_object *)r_ob, content, (t_rollvoice *)nth_voice_safe(r_ob, voice_num), false, true);
                if (newch)
                    newch->need_recompute_parameters = true;
            }

        } else if (type == k_MARKER) {
            if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE || modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER) {
                set_marker_from_llll(r_ob, (t_marker *)item, content);
                if (is_solo_with_progeny(r_ob, item)) update_solos(r_ob);
                (*flags) |= k_UNDO_PERFORM_FLAG_CHECK_ORDER_FOR_MARKERS;
                if (!obj_is_score)
                    (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH;
                
            } else if (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) {
                if (!obj_is_score)
                    (*flags) |= k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH;
                delete_marker(r_ob, (t_marker *)item);
                check_correct_scheduling(r_ob, false);
                
            } else if (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) {
                add_marker_from_llll(r_ob, content);
            }
            
        } else if (type == k_HEADER_DATA) {
            if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE) {
                if (obj_is_score) {
                    r_ob->take_rhythmic_tree_for_granted = 1;
                    (r_ob->rebuild_function)((t_object *)r_ob, content, false);
                    r_ob->take_rhythmic_tree_for_granted = 0;
                } else {
                    (r_ob->rebuild_function)((t_object *)r_ob, content, false);
                }
            }
        }
    } else {
        // changing specific parameters of notation object
        t_bach_attribute *attr = get_bach_attribute(r_ob->m_inspector.attr_manager, type, param);
        
        if (attr && item) {
            t_atom *av = NULL;
            long ac = llll_deparse(content, &av, 0, LLLL_D_QUOTE);
            // this is overkill, we should collect all changes and then only perform postprocess once for all ticks...
            set_bach_attr_and_process_from_ac_av(&r_ob->m_inspector, item, attr, ac, av, false);
            bach_freeptr(av);
        } else {
            if (!attr)
                object_error((t_object *)r_ob, "Attribute does not exist.");
            if (!item)
                object_error((t_object *)r_ob, "Notation item does not exist.");
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
        flags |= k_UNDO_PERFORM_FLAG_NOTHING_DONE;
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
        
        // reversing information for redo/undo
        t_undo_redo_information *reverse_information = undo_redo_information_reverse(r_ob, this_information);
        
        // applying undo/redo information
        long error = undo_redo_information_apply(r_ob, this_information, measure_whose_flag_needs_to_be_cleared, &flags);
        
        if (error) {
            object_error((t_object *) r_ob, "Wrong undo/redo data");
            llll_destroyelem(llll->l_head);
            continue;
        }

        if (reverse_information)
            undo_redo_tick_create(r_ob, -what, 1, reverse_information, false);
        
        undo_redo_information_free(this_information);
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
    
    undo_redo_step_marker_create(r_ob, -what, 1, undo_op, false);
    r_ob->last_operation_is = what;
    
    systhread_mutex_unlock(r_ob->c_undo_mutex);
    
    return flags;
}





void undo_redo_simplify(t_notation_obj *r_ob)
{
    
}



t_llll *notationobj_last_operation_label_to_llll(t_notation_obj *r_ob)
{
    t_llll *out = llll_get();
    t_llll *llll = r_ob->undo_llll;
    
    if (r_ob->last_operation_is == -1) {
        llll = r_ob->redo_llll;
    }
    
    if (!llll->l_head || hatom_gettype(&llll->l_head->l_hatom) != H_LONG) {
        llll_appendsym(out, gensym("Unprocessed Change"));
        return out;
    }
    
    long undo_op = hatom_getlong(&llll->l_head->l_hatom);
    t_symbol *operation = undo_op_to_symbol(undo_op, r_ob->last_operation_is == -1);
    
    llll_appendsym(out, operation);
    return out;
}

t_llll *notationobj_last_operation_label_and_details_to_llll(t_notation_obj *r_ob, char reverse_information)
{
    t_llll *out = llll_get();
    t_llll *llll = r_ob->undo_llll;
    
    if (r_ob->last_operation_is == -1) {
        llll = r_ob->redo_llll;
    }
        
    if (!llll->l_head || hatom_gettype(&llll->l_head->l_hatom) != H_LONG) {
        llll_appendsym(out, gensym("Unprocessed Change"));
        return out;
    }
    
    long undo_op = hatom_getlong(&llll->l_head->l_hatom);
    t_symbol *operation = undo_op_to_symbol(undo_op, r_ob->last_operation_is == -1);

    llll_appendsym(out, operation);
    
    if (reverse_information) {
        t_llllelem *lastel = NULL;
        for (t_llllelem *el = llll->l_head->l_next; el && hatom_gettype(&el->l_hatom) == H_OBJ; el = el->l_next){
            lastel = el;
        }
        for (t_llllelem *el = lastel; el && el != llll->l_head; el = el->l_prev){
            t_undo_redo_information *this_information = (t_undo_redo_information *)hatom_getobj(&el->l_hatom);
            t_undo_redo_information *new_information = undo_redo_information_reverse(r_ob, this_information);
            if (!new_information) {
                // this may happen if in a later tick the notation item is deleted.
                // but that is not good anyway
                object_error((t_object *)r_ob, "Cannot compute reverse change.");
            } else {
                llll_appendllll(out, undo_redo_information_to_llll(r_ob, new_information));
                undo_redo_information_free(new_information);
            }
        }
    } else {
        for (t_llllelem *el = llll->l_head->l_next; el && hatom_gettype(&el->l_hatom) == H_OBJ; el = el->l_next){
            t_undo_redo_information *this_information = (t_undo_redo_information *)hatom_getobj(&el->l_hatom);
            llll_appendllll(out, undo_redo_information_to_llll(r_ob, this_information));
        }
    }
    return out;
}






// only works with chords, voices and measures
long notation_item_get_undo_op(t_notation_obj *r_ob, t_notation_item *item, char modif_type){
    if (item->type == k_MEASURE) {
        switch (modif_type) {
            case k_UNDO_MODIFICATION_TYPE_ADD:
                return k_UNDO_OP_DELETE_MEASURE;
            case k_UNDO_MODIFICATION_TYPE_DELETE:
                return k_UNDO_OP_ADD_MEASURE;
            default:
                return k_UNDO_OP_CHANGE_MEASURE;
        }
    } else if (item->type == k_CHORD) {
        switch (modif_type) {
            case k_UNDO_MODIFICATION_TYPE_ADD:
                return k_UNDO_OP_DELETE_CHORD;
            case k_UNDO_MODIFICATION_TYPE_DELETE:
                return k_UNDO_OP_ADD_CHORD;
            default:
                return k_UNDO_OP_CHANGE_CHORD;
        }
    } else if (item->type == k_VOICE) {
        switch (modif_type) {
            case k_UNDO_MODIFICATION_TYPE_ADD:
                return k_UNDO_OP_DELETE_VOICE;
            case k_UNDO_MODIFICATION_TYPE_DELETE:
                return k_UNDO_OP_ADD_VOICE;
            default:
                return k_UNDO_OP_CHANGE_VOICE;
        }
    }
    return k_UNDO_OP_UNKNOWN;
}



// depending on the selection, returns the notation items that must
// ingroup undo!!!
// smallest_type is the element ID of the smallest element to track. This can only be k_CHORD, k_MEASURE or k_VOICE.
// and if this is k_MEASURE it means that chords will not be put into *undo_items, but rather their measures
long selection_to_undo_notation_items(t_notation_obj *r_ob, t_notation_item ***undo_items, long smallest_type){
    t_notation_item *item;
    long num_flagged = 0, count = 0;
    
    if (!r_ob->firstselecteditem)
        return 0;
    
    for (item = r_ob->firstselecteditem; item; item = item->next_selected){
        item->flags = (e_bach_internal_notation_flags) (item->flags & ~k_FLAG_COUNT);
        count++;
    }
    
    num_flagged = count;
    *undo_items = (t_notation_item **)bach_newptr(num_flagged * sizeof(t_notation_item *)); // can't be more than this (*undo_items)[0]
    
    for (count = 0, item = r_ob->firstselecteditem; item; item = item->next_selected){
        t_notation_item *item_to_save = notation_item_get_ancestor_of_at_least_a_certain_type(r_ob, item, smallest_type);
        
        if (item_to_save->flags & k_FLAG_COUNT || notation_item_is_globally_locked(r_ob, item_to_save))
            continue;    // already added
        
        // check if we have already saved a parent or a son
        long i;
        char genealogy = 0;
        for (i = 0; i < count; i++){
            if (notation_item_is_ancestor_of(r_ob, (*undo_items)[i], item_to_save)){
                genealogy = 1; // item_to_save is son of an already saved item
                break;
            } else if (notation_item_is_ancestor_of(r_ob, item_to_save, (*undo_items)[i])){
                if (i < count - 1)
                    sysmem_copyptr(&(*undo_items)[i+1], &(*undo_items)[i], (count - i - 1) * sizeof(t_notation_item *));
                genealogy = -1; // item_to_save is dad of an already existing item, we remove this item
                count--;
            }
        }
        
        if (genealogy != 1) {
            if (count < num_flagged)
                (*undo_items)[count++] = item_to_save;
            item_to_save->flags = (e_bach_internal_notation_flags) (item_to_save->flags | k_FLAG_COUNT);
        }
    }
    
    for (item = r_ob->firstselecteditem; item; item = item->next_selected)
        item->flags = (e_bach_internal_notation_flags) (item->flags & ~k_FLAG_COUNT);
    
    return count;
}






// only works with chords, notes and measures
t_llll *notation_item_get_values_as_llll_for_undo(t_notation_obj *r_ob, t_notation_item *item){
    if (item->type == k_MEASURE)
        return measure_get_values_as_llll(r_ob, (t_measure *)item, k_CONSIDER_FOR_UNDO, true, true);
    else if (item->type == k_CHORD) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
            return get_rollchord_values_as_llll(r_ob, (t_chord *)item, k_CONSIDER_FOR_UNDO);
        else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
            return get_scorechord_values_as_llll(r_ob, (t_chord *)item, k_CONSIDER_FOR_UNDO, false);
    } else if (item->type == k_NOTE) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
            return get_rollnote_values_as_llll(r_ob, (t_note *) item, k_CONSIDER_FOR_UNDO);
        else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
            return get_scorenote_values_as_llll(r_ob, (t_note *)item, k_CONSIDER_FOR_UNDO);
        else if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
            return get_uislotnote_values_as_llll(r_ob, (t_note *)item, k_CONSIDER_FOR_UNDO);
    } else if (item->type == k_MARKER) {
        return get_single_marker_as_llll(r_ob, (t_marker *)item, false, false);
    }
    return NULL;
}


char is_between(long num, long a, long b)
{
    if (num > MIN(a, b) && num <= MAX(a, b))
        return 1;
    return 0;
}


/*
void undo_tick_fix_path_for_onset_change(t_notation_obj *r_ob, t_undo_redo_information *info, t_notation_item *item, double delta_onset)
{
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && item->type == k_CHORD) {
        t_chord *ch = (t_chord *)item;
        long count = 0;
        if (delta_onset > 0) {
            for (t_chord *temp = ch->next; temp && temp->onset < ch->onset + delta_onset; temp = temp->next)
                count++;
        } else if (delta_onset < 0) {
            for (t_chord *temp = ch->prev; temp && temp->onset > ch->onset - delta_onset; temp = temp->prev)
                count--;
        }
        
        // checking other ticks
        for (t_llllelem *el = r_ob->undo_llll->l_head; el && hatom_gettype(&el->l_hatom) != H_LONG; el = el->l_next) {
            t_undo_redo_information *elinfo = (t_undo_redo_information *)hatom_getobj(&el->l_hatom);
            t_notation_item *elit = notation_item_retrieve_from_ID(r_ob, elinfo->n_it_ID);
            if (elit != item && elit->type == k_CHORD && elinfo->n_it_path_after.voice_num == info->n_it_path_after.voice_num) {
                t_chord *chit = (t_chord *)elit;
                // has it been moved away?
                if (!was_within(elinfo, info) && )
                if (elinfo->n_it_path_after.chord_num > info->n_it_path_after.chord_num && chit->onset < ch->onset + delta_onset)
//                if (elinfo->n_it_path_after.chord_num > info->n_it_path_after.chord_num && chit->onset < ch->onset + delta_onset)
            }
        }
        info->n_it_path_before.chord_num = info->n_it_path_after + count;
    } //to do: markers
}
 */

t_undo_redo_information *undo_tick_create_for_notation_item(t_notation_obj *r_ob, t_notation_item *item, e_undo_modification_types modif_type, t_symbol *param)
{
    t_undo_redo_information *operation;
    t_llll *content = NULL;
    t_notation_item_path path;
    t_notation_item_path *path_before, *path_after;
    t_llllelem *tick_el = NULL;

    notation_item_get_path(r_ob, item, &path);
    
    path_before = (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) ? NULL : &path;
    path_after = (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) ? NULL : &path;

    if (r_ob->inhibited_undo)
        return NULL;
    
    if (!item)
        return NULL;
    
    if (atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0)
        return NULL;
    
    if ((tick_el = notation_item_to_undo_tick(r_ob, item)) && (tick_el->l_thing.w_long == modif_type))
        return NULL;
    
    
    if (item->type != k_MEASURE && item->type != k_CHORD && item->type != k_MARKER &&
        !(item->type == k_NOTE && (r_ob->obj_type == k_NOTATION_OBJECT_SLOT || (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE && param == _llllobj_sym_name))) &&
        !(item->type == k_VOICE && modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE  && (param == _llllobj_sym_flag || param == _llllobj_sym_name))){
#ifdef BACH_UNDO_DEBUG
        object_post((t_object *) r_ob, "Warning! WEIRD UNDO ELEMENT!!!");
#endif
        return NULL;
    }
    
    // We need to get the information on score structures, we need to lock the general mutex (if it wasn't locked already!)
    char must_unlock = true;
    if (trylock_general_mutex(r_ob))
        must_unlock = false; // already locked
    
    if (param == _llllobj_sym_flag)
        content = get_multiple_flags_for_undo(r_ob, item);
    else if (param == _llllobj_sym_name)
        content = get_names_as_llll(item, false);
    else if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE || modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER || modif_type == k_UNDO_MODIFICATION_TYPE_ADD)
        content = notation_item_get_values_as_llll_for_undo(r_ob, item);
//    else if (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) // TO DO: check!!! Indeed NO we don't want this
//        content = notation_item_get_values_as_llll_for_undo(r_ob, item);
    else
        content = llll_get();
    
    if (must_unlock)
        unlock_general_mutex(r_ob);
    
    operation = undo_redo_information_create(item->ID, item->type, modif_type, param, path_before, path_after, k_HEADER_NONE, content);
    
    if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER) 
        llll_appendobj(r_ob->undo_information_whose_path_need_to_be_checked, operation);

    
    // THIS PART IS ONLY NEEDED IF notify_with != bang.
//    if (item->flags & k_FLAG_MODIF_UNDO_ANY) { // is already being undone for something
    if (r_ob->notify_with > 1) {
        // Delicate part: when there's CHANGE * * * DELETE, we turn it into DELETE * * *
        // This is needed for the notification system, which otherwise should have information on both previous and next state.

        // TO DO: only do this if there's a flag on the notation item that it already had a tick in the undo list (including DELETE, though)
        for (t_llllelem *el = r_ob->undo_llll->l_head; el && hatom_gettype(&el->l_hatom) != H_LONG; ) {
            t_undo_redo_information *existinginfo = (t_undo_redo_information *)hatom_getobj(&el->l_hatom);
            t_llllelem *next_el = el->l_next;

            if (existinginfo->n_it_ID == item->ID) {
                if (existinginfo->modification_type == k_UNDO_MODIFICATION_TYPE_DELETE) {
                    // fix paths for intermediate stuff
                    for (t_llllelem *temp = el->l_prev; temp; temp = temp->l_prev) {
                        t_undo_redo_information *tempinfo = (t_undo_redo_information *)hatom_getobj(&temp->l_hatom);
                        if (tempinfo->n_it_type == existinginfo->n_it_type) {
                            if (tempinfo->n_it_type == k_CHORD) {
                                // TO DO: CHECK FOR THE OTHER IN_BETWEEN (reversed extremes)
                                if (tempinfo->n_it_path_before.voice_num == existinginfo->n_it_path_before.voice_num &&
                                    is_between(tempinfo->n_it_path_before.chord_num, operation->n_it_path_before.chord_num, existinginfo->n_it_path_before.chord_num ))
                                    tempinfo->n_it_path_before.chord_num--;
                                if (tempinfo->n_it_path_after.voice_num == existinginfo->n_it_path_before.voice_num &&
                                    is_between(tempinfo->n_it_path_before.chord_num, operation->n_it_path_before.chord_num, existinginfo->n_it_path_before.chord_num ))
                                    tempinfo->n_it_path_after.chord_num--;
                            }
                        
                        }
                    }
                    
                    operation->modification_type = existinginfo->modification_type;
                    if (existinginfo->modification_type == k_UNDO_MODIFICATION_TYPE_DELETE)
                        notation_item_get_path(NULL, NULL, &operation->n_it_path_after);
                    
                    // delete old one
                    llll_destroyelem(el);
                    
                    break;
                }
            }
            
            el = next_el;
        }
    }
//    }
    
    
    tick_el = llll_prependobj(r_ob->undo_notation_items_under_tick, item);
    tick_el->l_thing.w_long = modif_type;
    undo_redo_tick_create(r_ob, k_UNDO, 0, operation, true);
    
    return operation;
}

void undo_tick_create_create_for_selected_notation_item(t_notation_obj *r_ob, t_notation_item *item, e_element_types smallest_undoable_element, e_undo_modification_types modif_type, t_symbol *param){
    t_notation_item *undo_item;
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
        smallest_undoable_element = k_NOTE;
    
    undo_item = notation_item_get_ancestor_of_at_least_a_certain_type(r_ob, item, smallest_undoable_element);
    
    if (!undo_item) {
        dev_post("Warning: wrong undo item; smallest_undoable_elem = %ld, modif_type %ld, itemtype %ld", smallest_undoable_element, modif_type, item->type);
        return;
    }

    
    if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE && param == _llllobj_sym_name && !(undo_item->flags & k_FLAG_MODIF_NAME_UNDO)){
        undo_tick_create_for_notation_item(r_ob, undo_item, k_UNDO_MODIFICATION_TYPE_CHANGE, param);
        undo_item->flags = (e_bach_internal_notation_flags) (undo_item->flags | k_FLAG_MODIF_NAME_UNDO);
        
    } else if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE && param == _llllobj_sym_flag && !(undo_item->flags & k_FLAG_MODIF_FLAG_UNDO)){
        undo_tick_create_for_notation_item(r_ob, undo_item, k_UNDO_MODIFICATION_TYPE_CHANGE, param);
        undo_item->flags = (e_bach_internal_notation_flags) (undo_item->flags | k_FLAG_MODIF_FLAG_UNDO);
        
    } else if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER && !(undo_item->flags & k_FLAG_MODIF_CHECK_ORDER_UNDO)){
        undo_tick_create_for_notation_item(r_ob, undo_item, modif_type, param);
        undo_item->flags = (e_bach_internal_notation_flags) (undo_item->flags | k_FLAG_MODIF_CHECK_ORDER_UNDO);
        
    } else if (!(modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE && param == _llllobj_sym_flag) && modif_type != k_UNDO_MODIFICATION_TYPE_CHANGE_CHECK_ORDER &&
               (modif_type == k_UNDO_MODIFICATION_TYPE_ADD || modif_type == k_UNDO_MODIFICATION_TYPE_DELETE || !(undo_item->flags & k_FLAG_MODIF_UNDO_WITH_OR_WO_CHECK_ORDER))){
        undo_tick_create_for_notation_item(r_ob, undo_item, modif_type, param);
        undo_item->flags = (e_bach_internal_notation_flags) (undo_item->flags | k_FLAG_MODIF_UNDO);
    }
}

void undo_ticks_create_for_multiple_notation_items(t_notation_obj *r_ob, long num_items, t_notation_item **item, e_undo_modification_types modif_type, t_symbol *param, long *undo_op){
    long i;
    
    if (r_ob->inhibited_undo)
        return;
    
    if (atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0)
        return;
    
    if (undo_op)
        *undo_op = k_UNDO_OP_UNKNOWN;
    
    for (i = 0; i < num_items; i++){
        t_llll *content = NULL;
        long this_undo_op = notation_item_get_undo_op(r_ob, item[i], modif_type);
        t_notation_item_path path;
        t_notation_item_path *path_before, *path_after;
        t_undo_redo_information *operation;
        
        if (undo_op) {
            if (*undo_op == k_UNDO_OP_UNKNOWN)
                *undo_op = this_undo_op;
            else if (*undo_op != this_undo_op)
                *undo_op = k_UNDO_OP_MULTIPLE_CHANGES;
        }
        
        if (item[i]->type != k_MEASURE && item[i]->type != k_CHORD){
#ifdef BACH_UNDO_DEBUG
            object_post((t_object *) r_ob, "Warning! WEIRD UNDO ELEMENT!!!");
#endif
            return;
        }
        
        if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE && param == _llllobj_sym_flag)
            content = get_multiple_flags_for_undo(r_ob, item[i]);
        else if (modif_type == k_UNDO_MODIFICATION_TYPE_CHANGE || modif_type == k_UNDO_MODIFICATION_TYPE_ADD)
            content = notation_item_get_values_as_llll_for_undo(r_ob, item[i]);
        else
            content = llll_get();
        
        notation_item_get_path(r_ob, item[i], &path);
        path_before = (modif_type == k_UNDO_MODIFICATION_TYPE_ADD) ? NULL : &path;
        path_after = (modif_type == k_UNDO_MODIFICATION_TYPE_DELETE) ? NULL : &path;

        operation = undo_redo_information_create(item[i]->ID, item[i]->type, modif_type, param, path_before, path_after, k_HEADER_NONE, content);
        
        t_llllelem *tick_el = llll_prependobj(r_ob->undo_notation_items_under_tick, item[i], 0, WHITENULL_llll);
        tick_el->l_thing.w_long = modif_type;
        undo_redo_tick_create(r_ob, k_UNDO, 0, operation, true);
    }
    
    if (undo_op && num_items > 1)
        *undo_op = undo_op_make_plural(*undo_op);
}

void undo_ticks_remove_modif_undo_flag_to_last(t_notation_obj *r_ob){
    t_llllelem *elem;
    for (elem = r_ob->undo_notation_items_under_tick->l_head; elem; elem = elem->l_next) {
        t_notation_item *item = (t_notation_item *)hatom_getobj(&elem->l_hatom);
        item->flags = (e_bach_internal_notation_flags) (item->flags & ~k_FLAG_MODIF_UNDO);
        item->flags = (e_bach_internal_notation_flags) (item->flags & ~k_FLAG_MODIF_FLAG_UNDO);
        item->flags = (e_bach_internal_notation_flags) (item->flags & ~k_FLAG_MODIF_CHECK_ORDER_UNDO);
        item->flags = (e_bach_internal_notation_flags) (item->flags & ~k_FLAG_MODIF_NAME_UNDO);
    }
    r_ob->header_undo_flags = 0;
}

char undo_ticks_are_dangling(t_notation_obj *r_ob, char also_return_true_if_undo_is_empty){
    char res = false;
    
    systhread_mutex_lock(r_ob->c_undo_mutex);
    if ((r_ob->undo_llll && r_ob->undo_llll->l_head && hatom_gettype(&r_ob->undo_llll->l_head->l_hatom) != H_LONG) ||
        (also_return_true_if_undo_is_empty && (!r_ob->undo_llll->l_head || !r_ob->undo_llll)))    // we also set true if there are NO undos!
        res = true;
    systhread_mutex_unlock(r_ob->c_undo_mutex);
    
    return res;
}


void undo_ticks_remove_dangling(t_notation_obj *r_ob, char also_clear_ticks_flags){
    systhread_mutex_lock(r_ob->c_undo_mutex);
    if (also_clear_ticks_flags)
        undo_ticks_remove_modif_undo_flag_to_last(r_ob);
    while (r_ob->undo_llll->l_head && hatom_gettype(&r_ob->undo_llll->l_head->l_hatom) != H_LONG) {
        if (hatom_gettype(&r_ob->undo_llll->l_head->l_hatom) == H_OBJ) {
            t_undo_redo_information *thisinfo = (t_undo_redo_information *)hatom_getobj(&r_ob->undo_llll->l_head->l_hatom);
            free_undo_redo_information(thisinfo);
        }
        llll_destroyelem(r_ob->undo_llll->l_head);
    }
    systhread_mutex_unlock(r_ob->c_undo_mutex);
}


long undo_tick_create_for_multiple_selected_notation_items(t_notation_obj *r_ob, e_element_types smallest_undoable_element, e_undo_modification_types modif_type, t_symbol *param)
{
    t_notation_item **undo_items = NULL;
    long num_items, i;
    
    if (atom_gettype(&r_ob->max_undo_steps) == A_LONG && atom_getlong(&r_ob->max_undo_steps) == 0)
        return 0;
    
    num_items = selection_to_undo_notation_items(r_ob, &undo_items, smallest_undoable_element);
    for (i = 0; i < num_items; i++)
        undo_tick_create_for_notation_item(r_ob, undo_items[i], modif_type, param);
    bach_freeptr(undo_items);
    return num_items;
}


long header_types_to_undo_op(long header_types){
    switch (header_types) {
        case 0:
            return k_UNDO_OP_UNKNOWN;
        case k_HEADER_CLEFS:
            return k_UNDO_OP_CHANGE_CLEFS;
        case k_HEADER_COMMANDS:
            return k_UNDO_OP_CHANGE_COMMANDS;
        case k_HEADER_GROUPS:
            return k_UNDO_OP_CHANGE_GROUPS;
        case k_HEADER_KEYS:
            return k_UNDO_OP_CHANGE_KEYS;
        case k_HEADER_MARKERS:
            return k_UNDO_OP_CHANGE_MARKERS;
        case k_HEADER_MIDICHANNELS:
            return k_UNDO_OP_CHANGE_MIDICHANNELS;
        case k_HEADER_SLOTINFO:
            return k_UNDO_OP_CHANGE_SLOTINFO;
        case k_HEADER_VOICENAMES:
            return k_UNDO_OP_CHANGE_VOICENAMES;
        case k_HEADER_STAFFLINES:
            return k_UNDO_OP_CHANGE_STAFFLINES;
        case k_HEADER_ARTICULATIONINFO:
            return k_UNDO_OP_CHANGE_CUSTOM_ARTICULATIONS_DEFINITION;
        case k_HEADER_NOTEHEADINFO:
            return k_UNDO_OP_CHANGE_CUSTOM_NOTEHEADS_DEFINITION;
        case k_HEADER_NUMPARTS:
            return k_UNDO_OP_CHANGE_PARTS;
        case k_HEADER_LOOP:
            return k_UNDO_OP_CHANGE_LOOP;
        default:
            return k_UNDO_OP_CHANGE_HEADER;
    }
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
        
        switch (r_ob->notify_with) {
            case 0:
                llllobj_outlet_bang((t_object *) r_ob, LLLL_OBJ_UI, outlet_number);
                break;
            case 1:
            {
                t_llll *notifllll = notationobj_last_operation_label_to_llll(r_ob);
                llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet_number, notifllll);
                llll_free(notifllll);
            }
                break;
            case 2:
            case 3:
            {
                t_llll *notifllll = notationobj_last_operation_label_and_details_to_llll(r_ob, r_ob->notify_with == 2);
                llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet_number, notifllll);
                llll_free(notifllll);
            }
                break;
            default:
                break;
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


long notationobj_generic_change(t_notation_obj *r_ob, t_symbol *msg, long ac, t_atom *av)
{
    long flags = 0;
    char obj_is_score = (r_ob->obj_type == k_NOTATION_OBJECT_SCORE);
    t_llll *measure_whose_flag_needs_to_be_cleared = obj_is_score ? llll_get() : NULL;
    long add_undo_step = 1;
    
    t_llll *ll = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, msg, ac, av, LLLL_PARSE_RETAIN);
    llll_parseattrs((t_object *)r_ob, ll, true, "i", gensym("undo"), &add_undo_step);
    
    if (!ll) {
        object_error((t_object *)r_ob, "Syntax error.");
        llll_free(measure_whose_flag_needs_to_be_cleared);
        return flags;
    }
    
    t_undo_redo_information *info = undo_redo_information_from_llll(r_ob, ll);

    if (!info) {
        object_error((t_object *)r_ob, "Can't find notation items.");
        llll_free(measure_whose_flag_needs_to_be_cleared);
        unlock_general_mutex(r_ob);
        return flags;
    }
    
    if (add_undo_step) {
        // reversing information for redo/undo
        t_undo_redo_information *reverse_information = undo_redo_information_reverse(r_ob, info);
        
        // applying undo/redo information
        undo_redo_information_apply(r_ob, info, measure_whose_flag_needs_to_be_cleared, &flags);
        
        if (reverse_information) {
            undo_redo_tick_create(r_ob, k_UNDO, 1, reverse_information, true);
            undo_redo_step_marker_create(r_ob, k_UNDO, 0, k_UNDO_OP_GENERIC_CHANGE, true);
        }
        
    }
    llll_free(ll);
    
    if (flags & k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH) {
        recompute_total_length(r_ob);
        flags = flags & (~k_UNDO_PERFORM_FLAG_RECOMPUTE_TOTAL_LENGTH);
    }
    
    if (flags & k_UNDO_PERFORM_FLAG_CHECK_ORDER_FOR_MARKERS) {
        check_markers_order(r_ob);
        flags = flags & (~k_UNDO_PERFORM_FLAG_CHECK_ORDER_FOR_MARKERS);
    }
    
    if (obj_is_score) {
        for (t_llllelem *elem = measure_whose_flag_needs_to_be_cleared->l_head; elem; elem = elem->l_next)
            ((t_measure *)hatom_getobj(&elem->l_hatom))->beaming_calculation_flags = k_BEAMING_CALCULATION_DO;
        llll_free(measure_whose_flag_needs_to_be_cleared);
    }
    
    undo_redo_information_free(info);
    llll_free(measure_whose_flag_needs_to_be_cleared);
    
    return flags;
}


