/*
 *  notation_maxinterface.c
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


#include "notation/notation.h"
#include "notation/notation_attrs.h"
#include "notation/notation_undo.h"

DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_notation_obj, constraint_pitches_when_editing, notationobj_getattr_pitcheditrange);
DEFINE_LLLL_ATTR_DEFAULT_SETTER(t_notation_obj, constraint_pitches_when_editing, notationobj_setattr_pitcheditrange);
DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_notation_obj, default_noteslots, notationobj_getattr_defaultnoteslots)
DEFINE_LLLL_ATTR_DEFAULT_SETTER(t_notation_obj, default_noteslots, notationobj_setattr_defaultnoteslots);

DEFINE_NOTATIONOBJ_LONGPTR_GETTER(midichannels_as_longlist, num_voices)
DEFINE_NOTATIONOBJ_ATOMPTR_GETTER(prevent_editing_atom, num_prevent_editing_elems)
DEFINE_NOTATIONOBJ_LONGPTR_GETTER(background_slots, num_background_slots)
DEFINE_NOTATIONOBJ_LONGPTR_GETTER(popup_menu_slots, num_popup_menu_slots)




void send_vzoom(t_notation_obj *r_ob, long outlet, t_symbol *label) {
	// send "vzoom" message 
	t_llll* vzoom_llll = llll_get();
	llll_appendsym(vzoom_llll, _llllobj_sym_vzoom, 0, WHITENULL_llll);
	if (label)
		llll_appendsym(vzoom_llll, label, 0, WHITENULL_llll);
	llll_appenddouble(vzoom_llll, r_ob->zoom_y * 100., 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet, vzoom_llll);
	llll_free(vzoom_llll);
}

void send_zoom(t_notation_obj *r_ob, long outlet, t_symbol *label) {
	// send "zoom" message 
	t_llll* zoom_llll = llll_get();
	llll_appendsym(zoom_llll, _llllobj_sym_zoom, 0, WHITENULL_llll);
	if (label)
		llll_appendsym(zoom_llll, label, 0, WHITENULL_llll);
	llll_appenddouble(zoom_llll, r_ob->zoom_x * 100., 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet, zoom_llll);
	llll_free(zoom_llll);
}

void handle_rebuild_done(t_notation_obj *r_ob) {
	if (r_ob->send_rebuild_done_only_after_paint_method)
		r_ob->need_send_rebuild_done_after_paint = true;
	else
		send_rebuild_done(r_ob);
}


void send_moved_playhead_position(t_notation_obj *r_ob, long outlet) {
    t_llll* out_llll = llll_get();
    llll_appendsym(out_llll, gensym("movedcursor"), 0, WHITENULL_llll);
    if (!r_ob->playing)
        llll_appenddouble(out_llll, r_ob->play_head_start_ms, 0, WHITENULL_llll);
    else
        llll_appenddouble(out_llll, r_ob->play_head_ms, 0, WHITENULL_llll);
    llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet, out_llll);
    llll_free(out_llll);
    
    send_playhead_position(r_ob, outlet);
}

void send_playhead_position(t_notation_obj *r_ob, long outlet) {
	t_llll* out_llll = llll_get();
	llll_appendsym(out_llll, _llllobj_sym_cursor, 0, WHITENULL_llll);
	if (!r_ob->playing)
		llll_appenddouble(out_llll, r_ob->play_head_start_ms, 0, WHITENULL_llll);
	else
		llll_appenddouble(out_llll, r_ob->play_head_ms, 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet, out_llll);
	llll_free(out_llll);
}


void send_loop_region_on_off(t_notation_obj *r_ob, long outlet)
{
	llllobj_outlet_symbol_couple_as_llll((t_object *)r_ob, LLLL_OBJ_UI, outlet, _llllobj_sym_loop, r_ob->use_loop_region && r_ob->show_loop_region ? _llllobj_sym_on : _llllobj_sym_off);
}

void send_loop_region(t_notation_obj *r_ob, long outlet) {
	t_llll* out_llll = llll_get();
	llll_appendsym(out_llll, _llllobj_sym_loop, 0, WHITENULL_llll);
	llll_appenddouble(out_llll, r_ob->loop_region.start.position_ms, 0, WHITENULL_llll);
	llll_appenddouble(out_llll, r_ob->loop_region.end.position_ms, 0, WHITENULL_llll);
	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) 
		llll_chain_clone(out_llll, r_ob->loop_region_as_llll);
	llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet, out_llll);
	llll_free(out_llll);
}


// sends a list containing (middleC y pos, staff bottom y, staff top y) for each voice
void send_voicepixelpos(t_notation_obj *r_ob, char obj_type, long num_voices, void *firstvoice, long outlet, t_symbol *label) {
	t_llll* out_llll = llll_get();
	long i;
	void *curr_voice = firstvoice;

	llll_appendsym(out_llll, _llllobj_sym_voicepixelpos, 0, WHITENULL_llll);
	if (label)
		llll_appendsym(out_llll, label, 0, WHITENULL_llll);

	lock_general_mutex(r_ob);	
	for (i = 0; i < num_voices; i++){
		t_llll *inner_llll = llll_get();
		double staff_top = get_staff_top_y(r_ob, (t_voice *) curr_voice, false);
		double staff_bottom = get_staff_bottom_y(r_ob, (t_voice *) curr_voice, false);
		llll_appenddouble(inner_llll, ((t_voice *) curr_voice)->middleC_y, 0, WHITENULL_llll);
		llll_appenddouble(inner_llll, staff_bottom, 0, WHITENULL_llll);
		llll_appenddouble(inner_llll, staff_top, 0, WHITENULL_llll);
		llll_appendllll(out_llll, inner_llll, 0, WHITENULL_llll);
		curr_voice = (obj_type == k_NOTATION_OBJECT_ROLL) ? (void *)(((t_rollvoice *)curr_voice)->next) : (void *)(((t_scorevoice *)curr_voice)->next);
	}
	unlock_general_mutex(r_ob);	
	
	llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet, out_llll);
	llll_free(out_llll);
}

void send_chord_as_llll(t_notation_obj *r_ob, t_chord *chord, long outlet, e_data_considering_types mode, long command_number, t_llll *forced_routers)
{
	t_llll *references = NULL;  
	char is_notewise;
	t_llll *outllll;
	
	lock_general_mutex(r_ob);
	outllll = chord_get_as_llll_for_sending(r_ob, chord, mode, command_number, forced_routers, &references, &is_notewise);
	unlock_general_mutex(r_ob);
	
//	send_sublists_through_playout_and_free(r_ob, outlet, outllll, references, is_notewise); 
	setup_sublists_lambda_and_send_llll(r_ob, outlet, outllll, references, is_notewise); 
	llll_free(outllll);
	llll_free(references);
}

t_symbol *handle_router(t_symbol *router, t_llll *forced_routers)
{
    if (!forced_routers || !forced_routers->l_head)
        return router;
    
    if (router == _llllobj_sym_note) {
        if (hatom_gettype(&forced_routers->l_head->l_hatom) == H_SYM)
            return hatom_getsym(&forced_routers->l_head->l_hatom);
    } else if (router == _llllobj_sym_chord) {
        if (forced_routers->l_size >= 2 && hatom_gettype(&forced_routers->l_head->l_next->l_hatom) == H_SYM)
            return hatom_getsym(&forced_routers->l_head->l_next->l_hatom);
        else if (hatom_gettype(&forced_routers->l_head->l_hatom) == H_SYM)
            return hatom_getsym(&forced_routers->l_head->l_hatom);
    } else if (router == _llllobj_sym_rest) {
        if (forced_routers->l_size >= 3 && hatom_gettype(&forced_routers->l_head->l_next->l_next->l_hatom) == H_SYM)
            return hatom_getsym(&forced_routers->l_head->l_next->l_next->l_hatom);
        else if (forced_routers->l_size >= 2 && hatom_gettype(&forced_routers->l_head->l_next->l_hatom) == H_SYM)
            return hatom_getsym(&forced_routers->l_head->l_next->l_hatom);
        else if (hatom_gettype(&forced_routers->l_head->l_hatom) == H_SYM)
            return hatom_getsym(&forced_routers->l_head->l_hatom);
    }
    
    return router;
}


void send_note_as_llll(t_notation_obj *r_ob, t_note *note, long outlet, e_data_considering_types mode, long command_number, t_llll *forced_routers)
{
	// we output: note voice# midichannel ( NOTE_GATHERED_SYNTAX )
	// type = 0: roll, = 1: score
	
	if (should_element_be_played(r_ob, (t_notation_item *)note)) {
		t_llll* out_llll = llll_get();
		lock_general_mutex(r_ob);
		llll_appendsym(out_llll, (command_number < 0 || command_number >= CONST_MAX_COMMANDS) ? handle_router(_llllobj_sym_note, forced_routers) : r_ob->command_note[command_number], 0, WHITENULL_llll);
		append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)note, mode);
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
			llll_appendlong(out_llll, note->parent->parent->voiceparent->v_ob.midichannel, 0, WHITENULL_llll);
			llll_appendllll(out_llll, get_single_scorenote_values_as_llll(r_ob, note, mode), 0, WHITENULL_llll); 
		} else {
			llll_appendlong(out_llll, note->parent->voiceparent->v_ob.midichannel, 0, WHITENULL_llll);
			llll_appendllll(out_llll, get_single_rollnote_values_as_llll(r_ob, note, mode), 0, WHITENULL_llll);
		}
		unlock_general_mutex(r_ob);
		
		//	send_llll_through_playout_and_free(r_ob, out_llll, outlet, note, k_NOTE);
		setup_lambda_and_send_llll(r_ob, outlet, out_llll, (t_notation_item *)note);
		llll_free(out_llll);
	}
}

void send_llll_through_playout(t_notation_obj *r_ob, t_llll *llll, long outlet, void *related_object, long related_type)
{
	// setting lambda information

	t_atom outatoms[4];
	
	atom_setlong(outatoms, outlet);
	atom_setobj(outatoms + 1, llll);
	atom_setobj(outatoms + 2, related_object);
	atom_setlong(outatoms + 3, related_type);
	
	if (r_ob->playing_scheduling_type == k_SCHEDULING_OFFLINE)
		do_send_llll_through_playout(r_ob, NULL, 4, outatoms);
	else
		schedule_delay(r_ob, (method) do_send_llll_through_playout, 0, NULL, 4, outatoms);
}


void send_llll_through_playout_and_free(t_notation_obj *r_ob, t_llll *llll, long outlet, void *related_object, long related_type)
{
	// setting lambda information
	
	t_atom outatoms[4];
	
	atom_setlong(outatoms, outlet);
	atom_setobj(outatoms + 1, llll);
	atom_setobj(outatoms + 2, related_object);
	atom_setlong(outatoms + 3, related_type);
	
    if (r_ob->playing_scheduling_type == k_SCHEDULING_OFFLINE)
		do_send_llll_through_playout_and_free(r_ob, NULL, 4, outatoms);
	else
		schedule_delay(r_ob, (method) do_send_llll_through_playout_and_free, 0, NULL, 4, outatoms);
}

void send_sublists_through_playout_and_free(t_notation_obj *r_ob, long outlet, t_llll *to_send, t_llll *to_send_references, long is_notewise)
{
	t_atom outatoms[4];
	
	atom_setlong(outatoms, outlet);
	atom_setobj(outatoms + 1, to_send);
	atom_setobj(outatoms + 2, to_send_references);
	atom_setlong(outatoms + 3, is_notewise);

    if (r_ob->playing_scheduling_type == k_SCHEDULING_OFFLINE || r_ob->playing_scheduling_type == k_SCHEDULING_PRESCHEDULE)
		do_send_sublists_through_playout_and_free(r_ob, NULL, 4, outatoms);
	else
		schedule_delay(r_ob, (method) do_send_sublists_through_playout_and_free, 0, NULL, 4, outatoms);
}



void do_send_llll_through_playout(t_notation_obj *r_ob, t_symbol *s, long ac, t_atom *av)
{
	long outlet = av[0].a_w.w_long;
	t_llll *llll = (t_llll *) av[1].a_w.w_obj;
	void *related_object = av[2].a_w.w_obj;

	setup_lambda_and_send_llll(r_ob, outlet, llll, (t_notation_item *)related_object);
}

void do_send_llll_through_playout_and_free(t_notation_obj *r_ob, t_symbol *s, long ac, t_atom *av)
{	
	long outlet = av[0].a_w.w_long;
	t_llll *llll = (t_llll *) av[1].a_w.w_obj;
	void *related_object = av[2].a_w.w_obj;
	
	setup_lambda_and_send_llll(r_ob, outlet, llll, (t_notation_item *)related_object);
	llll_free(llll);
}

void do_send_sublists_through_playout_and_free(t_notation_obj *r_ob, t_symbol *s, long ac, t_atom *av)
{
	long outlet = av[0].a_w.w_long;
	t_llll *to_send = (t_llll *) av[1].a_w.w_obj;
	t_llll *to_send_references = (t_llll *) av[2].a_w.w_obj;
	long is_notewise = av[3].a_w.w_long;
	
	setup_sublists_lambda_and_send_llll(r_ob, outlet, to_send, to_send_references, is_notewise); 
	llll_free(to_send);
	llll_free(to_send_references);
}


void setup_sublists_lambda_and_send_llll(t_notation_obj *r_ob, long outlet, t_llll *to_send, t_llll *to_send_references, long is_notewise)
{
	t_llllelem *elem, *refelem;
    for (elem = to_send->l_head, refelem = to_send_references ? to_send_references->l_head : NULL;
         elem; elem = elem->l_next, refelem = refelem ? refelem->l_next : NULL) {
		if (hatom_gettype(&elem->l_hatom) == H_OBJ) {
			t_llll *subll = (t_llll *)hatom_getobj(&elem->l_hatom);
			setup_lambda_and_send_llll(r_ob, outlet, subll, refelem ? (t_notation_item *)hatom_getobj(&refelem->l_hatom) : NULL);
			llll_free(subll);
		}
	}
}

void setup_lambda_and_send_llll(t_notation_obj *r_ob, long outlet, t_llll *llll, t_notation_item *related_item)
{
	r_ob->lambda_selected_item_ID = related_item ? related_item->ID : 0;  
	
	llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, outlet, llll);
	
	r_ob->lambda_selected_item_ID = 0;
}



void append_voice_or_full_path_to_playout_syntax(t_notation_obj *r_ob, t_llll *playout_llll, t_notation_item *item, e_data_considering_types mode) {
    switch (item->type) {
        case k_NOTE:
        {
            t_note *note = (t_note *)item;
            
            if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                if (r_ob->full_path_from_playout_syntax) // append the full path...
                    llll_appendllll(playout_llll, note_get_path_in_notationobj(r_ob, note), 0, WHITENULL_llll);
                else // just append 1-based voice number
                    llll_appendlong(playout_llll, note->parent->voiceparent->v_ob.number + 1, 0, WHITENULL_llll);
                
            } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (r_ob->full_path_from_playout_syntax) { // append the full path...
                    if (r_ob->play_tied_elements_separately ||
                        (mode != k_CONSIDER_FOR_PLAYING && mode != k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE && mode != k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE)) { //... of the single note, wrapped, or ...
                        t_llll *temp = note_get_path_in_notationobj(r_ob, note);
                        llll_wrap_once(&temp);
                        llll_appendllll(playout_llll, temp, 0, WHITENULL_llll);
                    } else // ... of all the notes belonging to which the given note is tied to.
                        llll_appendllll(playout_llll, get_tied_notes_sequence_path_in_notationobj(r_ob, note), 0, WHITENULL_llll);
                } else // just append 1-based voice number
                    llll_appendlong(playout_llll, note->parent->parent->voiceparent->v_ob.number + 1, 0, WHITENULL_llll);
            }
        }
            break;
        case k_CHORD:
        {
            t_chord *chord = (t_chord *)item;
            
            if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                if (r_ob->full_path_from_playout_syntax) // append the full path...
                    llll_appendllll(playout_llll, chord_get_path_in_notationobj(r_ob, chord), 0, WHITENULL_llll);
                else // just append 1-based voice number
                    llll_appendlong(playout_llll, chord->voiceparent->v_ob.number + 1, 0, WHITENULL_llll);
                
            } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (r_ob->full_path_from_playout_syntax) { // append the full path...
                    if (((chord->r_sym_duration.r_num >= 0 && r_ob->play_tied_elements_separately) || (chord->r_sym_duration.r_num < 0 && r_ob->play_rests_separately)) ||
                        (mode != k_CONSIDER_FOR_PLAYING && mode != k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE && mode != k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE)) { //... of the single chord, wrapped, or ...
                        t_llll *temp = chord_get_path_in_notationobj(r_ob, chord);
                        llll_wrap_once(&temp);
                        llll_appendllll(playout_llll, temp, 0, WHITENULL_llll);
                    } else { // ... of all the chord belonging to the all-tied-sequence.
                        if (chord->r_sym_duration.r_num >= 0)
                            llll_appendllll(playout_llll, get_tied_chords_sequence_path_in_notationobj(r_ob, chord), 0, WHITENULL_llll);
                        else
                            llll_appendllll(playout_llll, get_rests_sequence_path_in_notationobj(r_ob, chord), 0, WHITENULL_llll);
                    }
                } else // just append 1-based voice number
                    llll_appendlong(playout_llll, chord->parent->voiceparent->v_ob.number + 1, 0, WHITENULL_llll);
            }
        }
            break;
            
        case k_TEMPO:
        {
            t_tempo *tempo = (t_tempo *)item;
            
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (r_ob->full_path_from_playout_syntax) { // append the full path...
                    t_llll *temp = tempo_get_path_in_notationobj(r_ob, tempo);
                    llll_wrap_once(&temp);
                    llll_appendllll(playout_llll, temp, 0, WHITENULL_llll);
                } else // just append 1-based voice number
                    llll_appendlong(playout_llll, tempo->owner->voiceparent->v_ob.number + 1, 0, WHITENULL_llll);
            }
        }
            break;
        case k_MEASURE:
        {
            t_measure *meas = (t_measure *)item;
            
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                if (r_ob->full_path_from_playout_syntax) { // append the full path...
                    t_llll *temp = measure_get_path_in_notationobj(r_ob, meas);
                    llll_wrap_once(&temp);
                    llll_appendllll(playout_llll, temp, 0, WHITENULL_llll);
                } else // just append 1-based voice number
                    llll_appendlong(playout_llll, meas->voiceparent->v_ob.number + 1, 0, WHITENULL_llll);
            }
        }
            break;
        default:
            break;
	}
}



t_llll *chord_get_as_llll_for_sending(t_notation_obj *r_ob, t_chord *chord, e_data_considering_types mode, long command_number, t_llll *forced_routers, t_llll **references, char *is_notewise)
{
	// we output: chord voice# midichannel ( CHORD_GATHERED_SYNTAX ) 
	// mode = 1 = playout, 0 = single chord dump, -1 for gathered syntax (first outlet), 2 = partialplayout
	// command_number = -1 -> normal playout or dump; commandnumber >=0: a defined command.
	// puts into references the references for the played notes or chords
	
	if (references)
		*references = llll_get();
	
	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && mode >= 0 && r_ob->play_mode == k_PLAYMODE_NOTEWISE) { // SCORE notewise! we send single notes; ALWAYS (was: mode >= 1 play or partial play mode)
		
		t_llll *all_notes_llll = llll_get();

		if (!chord->firstnote) { // rest
			t_llll* out_llll = llll_get();
            llll_appendsym(out_llll, ((command_number < 0) || (command_number >= CONST_MAX_COMMANDS)) ? handle_router(_llllobj_sym_rest, forced_routers) : r_ob->command_rest[command_number], 0, WHITENULL_llll);
			append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)chord, mode);
			llll_appendlong(out_llll, chord->parent->voiceparent->v_ob.midichannel, 0, WHITENULL_llll);
			llll_appendllll(out_llll, get_scorechord_values_as_llll(r_ob, chord, mode, true));
			llll_appendobj(all_notes_llll, out_llll, 0, WHITENULL_llll);
			
			if (references)
				llll_appendobj(*references, chord, 0, WHITENULL_llll);
		} else {
			
			t_note *note;
			for (note = chord->firstnote; note; note = note->next) { 
				if ((should_element_be_played(r_ob, (t_notation_item *)note)) && (r_ob->play_tied_elements_separately || !note->tie_from || mode == k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE || mode == k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE || mode == k_CONSIDER_FOR_DUMPING || mode == k_CONSIDER_FOR_SLOT_LLLL_EDITOR || mode == k_CONSIDER_FOR_EVALUATION)) {
					
                    if (mode == k_CONSIDER_FOR_EVALUATION && !should_play_tied_notes_separately(r_ob, chord) && note->tie_from && note->tie_from != WHITENULL && notation_item_is_globally_selected(r_ob, (t_notation_item *)note->tie_from)) {
                        // nothing to do
                    } else {
                        t_llll* out_llll = llll_get();
                        
                        llll_appendsym(out_llll, ((command_number < 0) || (command_number >= CONST_MAX_COMMANDS)) ? handle_router(_llllobj_sym_note, forced_routers) : r_ob->command_note[command_number], 0, WHITENULL_llll);
                        append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)note, mode);
                        llll_appendlong(out_llll, chord->parent->voiceparent->v_ob.midichannel, 0, WHITENULL_llll);
                        llll_appendllll(out_llll, get_single_scorenote_values_as_llll(r_ob, note, mode), 0, WHITENULL_llll);
                        llll_appendobj(all_notes_llll, out_llll, 0, WHITENULL_llll);
                        
                        if (references)
                            llll_appendobj(*references, note, 0, WHITENULL_llll);
                    }
				}
			}
		}
		
		if (is_notewise)
			*is_notewise = true;
		
		return all_notes_llll;
		
	} else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && mode >= 0 && r_ob->play_mode == k_PLAYMODE_NOTEWISE) { // ROLL notewise! we send single notes; ALWAYS (was: mode >= 1 play or partial play mode)
		
		t_llll *all_notes_llll = llll_get();
		t_note *note;
		
		for (note =  chord->firstnote; note; note = note->next) { 
			if (should_element_be_played(r_ob, (t_notation_item *)note)) {
                if ((mode == k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE || mode == k_CONSIDER_FOR_PLAYING_AS_PARTIAL_NOTE_VERBOSE) && (note->parent->onset + note->duration) < r_ob->play_head_start_ms)
                    continue;
                
				t_llll* out_llll = llll_get();
				llll_appendsym(out_llll, ((command_number < 0) || (command_number >= CONST_MAX_COMMANDS)) ? handle_router(_llllobj_sym_note, forced_routers) : r_ob->command_note[command_number], 0, WHITENULL_llll);
				append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)note, mode);
				llll_appendlong(out_llll, chord->voiceparent->v_ob.midichannel, 0, WHITENULL_llll);
				llll_appendllll(out_llll, get_single_rollnote_values_as_llll(r_ob, note, mode), 0, WHITENULL_llll);
				
				llll_appendobj(all_notes_llll, out_llll, 0, WHITENULL_llll);

				if (references)
					llll_appendobj(*references, note, 0, WHITENULL_llll);
			}
		}
		
		if (is_notewise)
			*is_notewise = true;

		return all_notes_llll;
		
	} else {
		
        t_llll* external_out_llll = llll_get();
        
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && mode == k_CONSIDER_FOR_EVALUATION && chord->firstnote && !r_ob->play_tied_elements_separately && chord_is_all_tied_from(chord, false) && chord_get_prev(chord) && notation_item_is_globally_selected(r_ob, (t_notation_item *)chord_get_prev(chord))) {
            // nothing to do
        } else {
            
            t_llll* out_llll = llll_get();
            
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && !chord->firstnote)
                llll_appendsym(out_llll, ((command_number < 0) || (command_number >= CONST_MAX_COMMANDS)) ? handle_router(_llllobj_sym_rest, forced_routers) : r_ob->command_rest[command_number], 0, WHITENULL_llll);
            else
                llll_appendsym(out_llll, ((command_number < 0) || (command_number >= CONST_MAX_COMMANDS)) ? handle_router(_llllobj_sym_chord, forced_routers) : r_ob->command_chord[command_number], 0, WHITENULL_llll);
            
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)chord, mode);
                llll_appendlong(out_llll, chord->parent->voiceparent->v_ob.midichannel, 0, WHITENULL_llll);
                llll_appendllll(out_llll, get_scorechord_values_as_llll(r_ob, chord, mode, false), 0, WHITENULL_llll);
            } else {
                append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)chord, mode);
                llll_appendlong(out_llll, chord->voiceparent->v_ob.midichannel, 0, WHITENULL_llll);
                llll_appendllll(out_llll, get_rollchord_values_as_llll(r_ob, chord, mode), 0, WHITENULL_llll);
            }
            
            llll_appendobj(external_out_llll, out_llll, 0, WHITENULL_llll);
            
            if (references)
                llll_appendobj(*references, chord, 0, WHITENULL_llll);
        }
		
		if (is_notewise)
			*is_notewise = false;

		return external_out_llll;
	}
}



t_llll *get_single_tempo_values_as_llll(t_notation_obj *r_ob, t_tempo *tempo, e_data_considering_types mode)
{
    t_llll *out_llll = llll_get();
    if (tempo) {
        llll_appendrat(out_llll, tempo->tempo_figure);
        llll_appenddouble(out_llll, rat2double(tempo->figure_tempo_value));
        llll_appendrat(out_llll, tempo->changepoint);
        llll_appendlong(out_llll, tempo->interpolation_type);
    }
    return out_llll;
}

    

t_llll *get_tempo_as_llll_for_sending(t_notation_obj *r_ob, t_tempo *tempo, e_data_considering_types mode)
{
    t_llll *out_llll = llll_get();
    if (tempo) {
        t_tempo *next_tempo = NULL;
        llll_appendsym(out_llll, _llllobj_sym_tempo);
        append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)tempo, mode);
        
        if (tempo->interpolation_type && (next_tempo = tempo_get_next(tempo)))
            llll_appendllll(out_llll, double_triplet_to_llll(rat2double(tempo->tempo_value), rat2double(next_tempo->tempo_value), next_tempo->onset - tempo->onset));
        else // no interpolation, single number
            llll_appenddouble(out_llll, rat2double(tempo->tempo_value));
        
        // in any case: full tempo syntax
        llll_appendllll(out_llll, get_single_tempo_values_as_llll(r_ob, tempo, mode));
    }
    return out_llll;
}

t_llll *measure_get_as_llll_for_sending(t_notation_obj *r_ob, t_measure *measure, e_data_considering_types mode)
{
    t_llll *out_llll = llll_get();
    if (measure) {
        llll_appendsym(out_llll, _llllobj_sym_measure);
        append_voice_or_full_path_to_playout_syntax(r_ob, out_llll, (t_notation_item *)measure, mode);
        llll_appendlong(out_llll, measure->measure_number + 1); // measure number
        llll_appendllll(out_llll, measure_get_measureinfo_as_llll(r_ob, measure)); // measureinfo
        t_llll *sub_ll = llll_get();
        llll_appendrat(sub_ll, measure_get_sym_duration(measure));
        llll_appenddouble(sub_ll, notation_item_get_duration_ms(r_ob, (t_notation_item *)measure));
        llll_appenddouble(sub_ll, notation_item_get_onset_ms(r_ob, (t_notation_item *)measure));
        llll_appendllll(out_llll, sub_ll);
    }
    return out_llll;
}


void notationobj_edclose(t_notation_obj *r_ob, char **ht, long size)
{
	// the editor is closed. Let's replug the slot content!
	if (!r_ob->freeing && ht && r_ob->active_slot_notationitem && r_ob->active_slot_num >= 0) {
		undo_tick_create_for_notation_item(r_ob, get_activeitem_undo_item(r_ob), k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
		t_llll *ll;
		if (r_ob->slotinfo[r_ob->active_slot_num].slot_type == k_SLOT_TYPE_TEXT) {
			ll = llll_get();
			llll_appendsym(ll, gensym(*ht), 0, WHITENULL_llll);
        } else {
            ll = llll_from_text_buf(*ht, size > MAX_SYM_LENGTH);
        }
        if (ll) {
            llll_prependlong(ll, r_ob->active_slot_num + 1, 0, WHITENULL_llll);
            llll_wrap_once(&ll);
            set_slots_values_to_notationitem_from_llll(r_ob, r_ob->active_slot_notationitem, ll);
            notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
            handle_change(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_SLOT);
        }
	}
	r_ob->m_editor = NULL;
	return;
}



void handle_dilation_rectangle_mouse_cursor(t_notation_obj *r_ob, t_object *patcherview, t_pt pt){
	char elem = pt_to_dilation_rectangle_obj(r_ob, pt);
	if (elem == k_DILATION_RECTANGLE_MIDDLELEFT_SQ || elem == k_DILATION_RECTANGLE_MIDDLERIGHT_SQ) {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_LEFTRIGHT);
	} else if (elem == k_DILATION_RECTANGLE_TOPMIDDLE_SQ || elem == k_DILATION_RECTANGLE_BOTTOMMIDDLE_SQ) {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_UPDOWN);
	} else if (elem == k_DILATION_RECTANGLE_TOPLEFT_SQ) {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_TOPLEFTCORNER);
	} else if (elem == k_DILATION_RECTANGLE_BOTTOMLEFT_SQ) {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_BOTTOMLEFTCORNER);
	} else if (elem == k_DILATION_RECTANGLE_TOPRIGHT_SQ) {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_TOPRIGHTCORNER);
	} else if (elem == k_DILATION_RECTANGLE_BOTTOMRIGHT_SQ) {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_BOTTOMRIGHTCORNER);
	} else if (elem == k_DILATION_RECTANGLE_BODY) {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DRAGGINGHAND);
	} else {
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
	}
}





// keys

// returns 1 if a key for articulation has been pressed
char handle_keys_for_articulations(t_notation_obj *r_ob, t_object *patcherview, long keycode, long modifiers, long textcharacter){
	if (keycode == 's' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_STACCATO);
		return 1;
	} else if (keycode == 's' && modifiers == eAltKey + eShiftKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_STACCATISSIMO);
		return 1;
	} else if (keycode == 'f' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_FERMATA);
		return 1;
	} else if (keycode == 'p' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_PORTATO);
		return 1;
	} else if (keycode == 43 && modifiers == eAltKey) {  // Alt + +
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_LEFT_HAND_PIZZICATO);
		return 1;
	} else if (keycode == 't' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_TRILL);
		return 1;
	} else if (keycode == 'm' && modifiers == eAltKey + eShiftKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_MORDENT_DOWN);
		return 1;
	} else if (keycode == 'm' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_MORDENT_UP);
		return 1;
	} else if (keycode == 'n' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_DOUBLE_MORDENT);
		return 1;
	} else if (keycode == 'b' && modifiers == eAltKey + eShiftKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_BOWING_DOWN);
		return 1;
	} else if (keycode == 'b' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_BOWING_UP);
		return 1;
	} else if (keycode == 'r' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_TREMOLO3);
		return 1;
	} else if (keycode == 'r' && modifiers == eAltKey + eShiftKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_TREMOLO2);
		return 1;
	} else if (keycode == 'r' && modifiers == eAltKey + eShiftKey + eControlKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_TREMOLO1);
		return 1;
	} else if (keycode == 'g' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_GRUPPETTO);
		return 1;
	} else if (keycode == 'h' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_HARMONIC);
		return 1;
	} else if (keycode == 'z' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_ACCENT_STACCATO);
		return 1;
	} else if (keycode == 'z' && modifiers == eAltKey + eShiftKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_ACCENT_PORTATO);
		return 1;
	} else if (keycode == 'w' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_PORTATO_STACCATO);
		return 1;
	} else if (keycode == 'j' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_MARTELLATO);
		return 1;
	} else if (keycode == 'j' && modifiers == eAltKey + eShiftKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_MARTELLATO_STACCATO);
		return 1;
	} else if (keycode == 'a' && modifiers == eAltKey) { 
		add_articulation_to_selected_elements(r_ob, k_ARTICULATION_ACCENT);
		return 1;
	} else if (keycode == JKEY_BACKSPACE && modifiers == eAltKey) { 
		delete_articulations_in_selection(r_ob);
		return 1;
	}
	return 0;
}


void build_popup_filters_menu(t_notation_obj *r_ob, t_slotitem *clickeditem)
{
	t_biquad *active_filter = NULL;
	
	if (clickeditem)
		active_filter = (t_biquad *) clickeditem->item;
	else if (r_ob->active_slot_notationitem && r_ob->active_slot_num > 0 && get_activeitem_activeslot_firstitem(r_ob))
		active_filter = (t_biquad *) get_activeitem_activeslot_firstitem(r_ob)->item;
	
	if (r_ob->popup_filters)
		jpopupmenu_destroy(r_ob->popup_filters);
	
	r_ob->popup_filters = jpopupmenu_create(); 
	
	// filters (2000)
	jpopupmenu_additem(r_ob->popup_filters, 2000, "Display", NULL, active_filter && active_filter->filter_type == k_FILTER_DISPLAY, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2001, "Lowpass", NULL, active_filter && active_filter->filter_type == k_FILTER_LOWPASS, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2002, "Highpass", NULL, active_filter && active_filter->filter_type == k_FILTER_HIGHPASS, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2003, "Bandpass", NULL, active_filter && active_filter->filter_type == k_FILTER_BANDPASS, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2004, "Bandstop", NULL, active_filter && active_filter->filter_type == k_FILTER_BANDSTOP, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2005, "Peaknotch", NULL, active_filter && active_filter->filter_type == k_FILTER_PEAKNOTCH, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2006, "Lowshelf", NULL, active_filter && active_filter->filter_type == k_FILTER_LOWSHELF, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2007, "Highshelf", NULL, active_filter && active_filter->filter_type == k_FILTER_HIGHSHELF, 0, NULL);
//	jpopupmenu_additem(r_ob->popup_filters, 2008, "Resonant", NULL, active_filter && active_filter->filter_type == k_FILTER_RESONANT, 0, NULL);
	jpopupmenu_additem(r_ob->popup_filters, 2009, "Allpass", NULL, active_filter && active_filter->filter_type == k_FILTER_ALLPASS, 0, NULL);
	
	jpopupmenu_setfont(r_ob->popup_filters, r_ob->popup_main_font);
}

void build_popup_barline_menu(t_notation_obj *r_ob, t_measure *measure)
{
	if (r_ob->popup_barline)
		jpopupmenu_destroy(r_ob->popup_barline);
	
	r_ob->popup_barline = jpopupmenu_create(); 
	
	// barlines (1200)
	jpopupmenu_additem(r_ob->popup_barline, 1200, "Auto (a)", NULL, measure->end_barline->barline_type == k_BARLINE_AUTOMATIC, 0, NULL);
	jpopupmenu_additem(r_ob->popup_barline, 1201, "Normal (n)", NULL, measure->end_barline->barline_type == k_BARLINE_NORMAL, 0, NULL);
	jpopupmenu_additem(r_ob->popup_barline, 1202, "Dashed (d)", NULL, measure->end_barline->barline_type == k_BARLINE_DASHED, 0, NULL);
	jpopupmenu_additem(r_ob->popup_barline, 1203, "Points (p)", NULL, measure->end_barline->barline_type == k_BARLINE_POINTS, 0, NULL);
	jpopupmenu_additem(r_ob->popup_barline, 1204, "Double (t)", NULL, measure->end_barline->barline_type == k_BARLINE_DOUBLE, 0, NULL);
	jpopupmenu_additem(r_ob->popup_barline, 1205, "Final (f)", NULL, measure->end_barline->barline_type == k_BARLINE_FINAL, 0, NULL);
	jpopupmenu_additem(r_ob->popup_barline, 1206, "Hidden (h)", NULL, measure->end_barline->barline_type == k_BARLINE_HIDDEN, 0, NULL);
	jpopupmenu_additem(r_ob->popup_barline, 1207, "Solid (s)", NULL, measure->end_barline->barline_type == k_BARLINE_SOLID, 0, NULL);
    jpopupmenu_additem(r_ob->popup_barline, 1208, "Tick (k)", NULL, measure->end_barline->barline_type == k_BARLINE_TICK, 0, NULL);
    jpopupmenu_additem(r_ob->popup_barline, 1209, "Intervoices (i)", NULL, measure->end_barline->barline_type == k_BARLINE_INTERVOICES, 0, NULL);

	jpopupmenu_setfont(r_ob->popup_barline, r_ob->popup_main_font);
}

void build_popup_durationline_menu(t_notation_obj *r_ob, t_duration_line *dl)
{
    if (r_ob->popup_durationline)
        jpopupmenu_destroy(r_ob->popup_durationline);
    
    r_ob->popup_durationline = jpopupmenu_create();
    jpopupmenu_additem(r_ob->popup_durationline, 8000, "Slice Note", NULL, 0, 0, NULL);
    jpopupmenu_setfont(r_ob->popup_durationline, r_ob->popup_main_font);
}



void build_popup_measure_menu(t_notation_obj *r_ob, t_measure *measure)
{
	if (r_ob->popup_measure)
		jpopupmenu_destroy(r_ob->popup_measure);
	if (r_ob->popup_measure_timesignature)
		jpopupmenu_destroy(r_ob->popup_measure_timesignature);
	
	r_ob->popup_measure = jpopupmenu_create(); 
	r_ob->popup_measure_timesignature = jpopupmenu_create(); 
	
	jpopupmenu_additem(r_ob->popup_measure, 1000, "Open Inspector", NULL, 0, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_measure);
    
    jpopupmenu_additem(r_ob->popup_measure, 150, "Copy Measures", NULL, 0, 0, NULL);
    jpopupmenu_additem(r_ob->popup_measure, 160, "Paste Measures", NULL, 0, 0, NULL);
    jpopupmenu_additem(r_ob->popup_measure, 161, "Paste Measures Without Tempi", NULL, 0, 0, NULL);

    jpopupmenu_addseperator(r_ob->popup_measure);

	// time signatures (500)
    t_timesignature temp_ts;
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 501, "2/2", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 2, 2))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 502, "2/4", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 2, 4))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 503, "3/4", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 3, 4))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 504, "4/4", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 4, 4))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 505, "5/4", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 5, 4))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 506, "6/4", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 6, 4))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 507, "3/8", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 3, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 508, "4/8", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 4, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 509, "5/8", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 5, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 510, "5/8 (3+2)", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_2compound_timesignature(r_ob, 3, 2, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 511, "5/8 (2+3)", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_2compound_timesignature(r_ob, 2, 3, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 512, "6/8", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 6, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 513, "7/8", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 7, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 514, "7/8 (3+2+2)", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_3compound_timesignature(r_ob, 3, 2, 2, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 515, "7/8 (2+3+2)", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_3compound_timesignature(r_ob, 2, 3, 2, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 516, "7/8 (2+2+3)", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_3compound_timesignature(r_ob, 2, 2, 3, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 517, "9/8", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 9, 8))), 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure_timesignature, 518, "12/8", NULL, ts_are_equal(&measure->timesignature, &(temp_ts = build_simple_timesignature(r_ob, 12, 8))), 0, NULL);
	jpopupmenu_addsubmenu(r_ob->popup_measure, "Time Signature", r_ob->popup_measure_timesignature, 0);

	// lock/mute (550)
	jpopupmenu_addseperator(r_ob->popup_measure);
	if (!is_all_selection_locked(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 551, "Lock", NULL, 0, 0, NULL);
	if (!is_all_selection_unlocked(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 552, "Unlock", NULL, 0, 0, NULL);
	if (!is_all_selection_muted(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 553, "Mute", NULL, 0, 0, NULL);
	if (!is_all_selection_unmuted(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 554, "Unmute", NULL, 0, 0, NULL);
	if (!is_all_selection_solo(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 555, "Solo", NULL, 0, 0, NULL);
	if (!is_all_selection_unsolo(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 556, "Unsolo", NULL, 0, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_measure);
	
	// no solos/no mutes (570)
	jpopupmenu_addseperator(r_ob->popup_measure);
	jpopupmenu_additem(r_ob->popup_measure, 570, "No Solos", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure, 571, "No Mutes", NULL, 0, 0, NULL);

	jpopupmenu_addseperator(r_ob->popup_measure);
	jpopupmenu_additem(r_ob->popup_measure, 589, "Pop Tempo Out", NULL, 0, 0, NULL);
    jpopupmenu_additem(r_ob->popup_measure, 590, "Pop Tempo Out In This Voice Only", NULL, 0, 0, NULL);

    jpopupmenu_addseperator(r_ob->popup_measure);
    jpopupmenu_additem(r_ob->popup_measure, 591, "Clear", NULL, 0, 0, NULL);
    jpopupmenu_additem(r_ob->popup_measure, 592, "Delete", NULL, 0, 0, NULL);

    
    jpopupmenu_addseperator(r_ob->popup_measure);
	if (!is_all_selection_rhythmic_tree_locked(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 610, "Lock Rhythmic Tree", NULL, 0, 0, NULL);
	if (!is_all_selection_rhythmic_tree_unlocked(r_ob))
		jpopupmenu_additem(r_ob->popup_measure, 611, "Unlock Rhythmic Tree", NULL, 0, 0, NULL);
	
	jpopupmenu_additem(r_ob->popup_measure, 600, "Apply Auto Rhythmic Tree Keeping Existing Tuplets", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure, 605, "Apply Auto Rhythmic Tree Ignoring Existing Tuplets", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure, 601, "Stick Rhythmic Tree", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_measure, 602, "Destroy Rhythmic Tree", NULL, 0, 0, NULL);	
	
	jpopupmenu_setfont(r_ob->popup_measure, r_ob->popup_main_font);
	jpopupmenu_setfont(r_ob->popup_measure_timesignature, r_ob->popup_secondary_font);
}

void build_popup_note_menu(t_notation_obj *r_ob, t_note *note, e_element_types clipboard_type)
{
	long i;
	long curr_idx;
	
	if (r_ob->popup_note)
		jpopupmenu_destroy(r_ob->popup_note);
	if (r_ob->popup_note_enharmonicity)
		jpopupmenu_destroy(r_ob->popup_note_enharmonicity);
	if (r_ob->popup_note_slots)
		jpopupmenu_destroy(r_ob->popup_note_slots);
    if (r_ob->popup_note_paste)
        jpopupmenu_destroy(r_ob->popup_note_paste);
    if (r_ob->popup_note_copy)
        jpopupmenu_destroy(r_ob->popup_note_copy);
    if (r_ob->popup_note_copy_slot)
        jpopupmenu_destroy(r_ob->popup_note_copy_slot);
    if (r_ob->popup_note_paste_slot)
        jpopupmenu_destroy(r_ob->popup_note_paste_slot);
	
	r_ob->popup_note = jpopupmenu_create(); 
	r_ob->popup_note_enharmonicity = jpopupmenu_create(); 
	r_ob->popup_note_slots = jpopupmenu_create(); 
    r_ob->popup_note_copy = jpopupmenu_create();
    r_ob->popup_note_copy_slot = jpopupmenu_create();
    r_ob->popup_note_paste = jpopupmenu_create();
    r_ob->popup_note_paste_slot = jpopupmenu_create();

	jpopupmenu_additem(r_ob->popup_note, 1000, "Open Inspector", NULL, 0, 0, NULL);
    jpopupmenu_addseperator(r_ob->popup_note);

    jpopupmenu_additem(r_ob->popup_note, 950, "Delete Selection", NULL, 0, 0, NULL);
    jpopupmenu_additem(r_ob->popup_note, 951, "Ripple Delete Selection", NULL, 0, 0, NULL);
    
    jpopupmenu_addseperator(r_ob->popup_note);

    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
        jpopupmenu_additem(r_ob->popup_note_copy, 970, "Copy Selection", NULL, 0, 0, NULL);
    jpopupmenu_additem(r_ob->popup_note_copy, 971, "Copy Duration Line", NULL, 0, 0, NULL);

    jpopupmenu_additem(r_ob->popup_note_copy_slot, 9000, "Copy All Slots", NULL, 0, 0, NULL);
    for (i = 0; i < CONST_MAX_SLOTS; i++) {
        char label[512];
        snprintf(label, 512, "Copy Slot %ld (%s)", i+1, r_ob->slotinfo[i].slot_name->s_name);
        jpopupmenu_additem(r_ob->popup_note_copy_slot, 9000 + i + 1, label, NULL, 0, 0, NULL);
    }
    jpopupmenu_addsubmenu(r_ob->popup_note_copy, "Copy Slot", r_ob->popup_note_copy_slot, 0);
    jpopupmenu_addsubmenu(r_ob->popup_note, "Copy", r_ob->popup_note_copy, 0);

    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
        jpopupmenu_additem(r_ob->popup_note_paste, 980, "Paste Replace Selection", NULL, 0, clipboard_type != k_SELECTION_CONTENT, NULL);
    jpopupmenu_additem(r_ob->popup_note_paste, 981, "Paste Duration Line", NULL, 0, clipboard_type != k_DURATION_LINE, NULL);

    
    jpopupmenu_additem(r_ob->popup_note_paste_slot, 10000, "Paste To Original Slot", NULL, 0, clipboard_type != k_SLOT, NULL);
    for (i = 0; i < CONST_MAX_SLOTS; i++) {
        char label[512];
        snprintf(label, 512, "Paste To Slot %ld (%s)", i+1, r_ob->slotinfo[i].slot_name->s_name);
        jpopupmenu_additem(r_ob->popup_note_paste_slot, 10000 + i + 1, label, NULL, 0, clipboard_type != k_SLOT, NULL);
    }
    jpopupmenu_addsubmenu(r_ob->popup_note_paste, "Paste Slot", r_ob->popup_note_paste_slot, clipboard_type != k_SLOT);
    
    jpopupmenu_addsubmenu(r_ob->popup_note, "Paste", r_ob->popup_note_paste, 0);

    jpopupmenu_addseperator(r_ob->popup_note);

	// enharmonicity (400)
	if (note) {
		note_get_enharmonic_possibilities(r_ob, note, &curr_idx);
		for (i = 0; i < CONST_MAX_ENHARMONICITY_OPTIONS; i++) {
			char *outname = NULL;
			midicents2notename(r_ob->middleC_octave, r_ob->current_enharmonic_list_screenmc[i], r_ob->current_enharmonic_list_screenacc[i], r_ob->note_names_style, true, &outname);
			jpopupmenu_additem(r_ob->popup_note_enharmonicity, 400 + i + 1, outname, NULL, i == curr_idx, 0, NULL);
			bach_freeptr(outname);
		}
	}
	jpopupmenu_addsubmenu(r_ob->popup_note, "Enharmonicity", r_ob->popup_note_enharmonicity, 0);
	

	// slots (300)
	for (i = 0; i < r_ob->num_popup_menu_slots; i++) {
		long num_slot = r_ob->popup_menu_slots[i] - 1;
		if (num_slot >= 0 && num_slot < CONST_MAX_SLOTS)
			jpopupmenu_additem(r_ob->popup_note_slots, 300 + num_slot + 1, r_ob->slotinfo[num_slot].slot_name->s_name, NULL, 0, 0, NULL);
	}
	jpopupmenu_addsubmenu(r_ob->popup_note, "Slots", r_ob->popup_note_slots, 0);
    
    jpopupmenu_addseperator(r_ob->popup_note);
    // markers (450)
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        jpopupmenu_additem(r_ob->popup_note, 501, "Add Marker", NULL, 0, 0, NULL);
    } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        jpopupmenu_additem(r_ob->popup_note, 502, "Add Measure-Attached Marker", NULL, 0, 0, NULL);
        jpopupmenu_additem(r_ob->popup_note, 503, "Add Millisecond-Attached Marker", NULL, 0, 0, NULL);
    }

	// various (450)
	jpopupmenu_addseperator(r_ob->popup_note);
	if (!is_all_selection_locked(r_ob))
		jpopupmenu_additem(r_ob->popup_note, 451, "Lock", NULL, 0, 0, NULL);
	if (!is_all_selection_unlocked(r_ob))
		jpopupmenu_additem(r_ob->popup_note, 452, "Unlock", NULL, 0, 0, NULL);
	if (!is_all_selection_muted(r_ob))
		jpopupmenu_additem(r_ob->popup_note, 453, "Mute", NULL, 0, 0, NULL);
	if (!is_all_selection_unmuted(r_ob))
		jpopupmenu_additem(r_ob->popup_note, 454, "Unmute", NULL, 0, 0, NULL);
	if (!is_all_selection_solo(r_ob))
		jpopupmenu_additem(r_ob->popup_note, 455, "Solo", NULL, 0, 0, NULL);
	if (!is_all_selection_unsolo(r_ob))
		jpopupmenu_additem(r_ob->popup_note, 456, "Unsolo", NULL, 0, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_note);
	jpopupmenu_additem(r_ob->popup_note, 461, "No Solos", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_note, 462, "No Mutes", NULL, 0, 0, NULL);

	// various (470)
	jpopupmenu_addseperator(r_ob->popup_note);
	jpopupmenu_additem(r_ob->popup_note, 471, "Snap Pitch To Grid", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_note, 472, "Retranscribe Pitches", NULL, 0, 0, NULL);
	if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
		jpopupmenu_additem(r_ob->popup_note, 473, "Align In Time", NULL, 0, 0, NULL);
		jpopupmenu_additem(r_ob->popup_note, 474, "Evenly Distribute In Time", NULL, 0, 0, NULL);
	}
	jpopupmenu_additem(r_ob->popup_note, 475, "Legato", NULL, 0, 0, NULL);

	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
		jpopupmenu_addseperator(r_ob->popup_note);
		
		jpopupmenu_additem(r_ob->popup_note, 600, "Apply Auto Rhythmic Tree Keeping Existing Tuplets", NULL, 0, 0, NULL);
		jpopupmenu_additem(r_ob->popup_note, 605, "Apply Auto Rhythmic Tree Ignoring Existing Tuplets", NULL, 0, 0, NULL);
		jpopupmenu_additem(r_ob->popup_note, 601, "Stick Rhythmic Tree", NULL, 0, 0, NULL);
		jpopupmenu_additem(r_ob->popup_note, 602, "Destroy Rhythmic Tree", NULL, 0, 0, NULL);
		jpopupmenu_additem(r_ob->popup_note, 603, "Add Rhythmic Tree Level", NULL, 0, 0, NULL);
		jpopupmenu_additem(r_ob->popup_note, 604, "Destroy Rhythmic Tree Level", NULL, 0, 0, NULL);
	}
	
	jpopupmenu_addseperator(r_ob->popup_note);
	
	jpopupmenu_additem(r_ob->popup_note, 480, "Dump Selection", NULL, 0, 0, NULL);
	
	jpopupmenu_setfont(r_ob->popup_note, r_ob->popup_main_font);
	jpopupmenu_setfont(r_ob->popup_note_enharmonicity, r_ob->popup_secondary_font);
	jpopupmenu_setfont(r_ob->popup_note_slots, r_ob->popup_secondary_font);
    jpopupmenu_setfont(r_ob->popup_note_copy, r_ob->popup_secondary_font);
    jpopupmenu_setfont(r_ob->popup_note_paste, r_ob->popup_secondary_font);
    jpopupmenu_setfont(r_ob->popup_note_copy_slot, r_ob->popup_secondary_font);
    jpopupmenu_setfont(r_ob->popup_note_paste_slot, r_ob->popup_secondary_font);
}

void build_popup_voice_menu(t_notation_obj *r_ob, t_voice *voice)
{
	long active_clef = voice->clef;
	long active_mode = voice->mode;
	long active_key = voice->key;
	long active_midichannel = voice->midichannel;
    char is_voice_ensemble = (voiceensemble_get_numparts(r_ob, voice) > 1);
	
	if (r_ob->popup_voice)
		jpopupmenu_destroy(r_ob->popup_voice);
	if (r_ob->popup_voice_clefs)
		jpopupmenu_destroy(r_ob->popup_voice_clefs);
	if (r_ob->popup_voice_keys)
		jpopupmenu_destroy(r_ob->popup_voice_keys);
	if (r_ob->popup_voice_keys_major)
		jpopupmenu_destroy(r_ob->popup_voice_keys_major);
	if (r_ob->popup_voice_keys_minor)
		jpopupmenu_destroy(r_ob->popup_voice_keys_minor);
	if (r_ob->popup_voice_midichannels)
		jpopupmenu_destroy(r_ob->popup_voice_midichannels);
	
	r_ob->popup_voice = jpopupmenu_create(); 
	r_ob->popup_voice_clefs = jpopupmenu_create(); 
	r_ob->popup_voice_keys = jpopupmenu_create(); 
	r_ob->popup_voice_keys_major = jpopupmenu_create(); 
	r_ob->popup_voice_keys_minor = jpopupmenu_create(); 
	r_ob->popup_voice_midichannels = jpopupmenu_create(); 
	
	jpopupmenu_additem(r_ob->popup_voice, 1000, "Open Inspector", NULL, 0, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_voice);

    if (r_ob->selection_type == k_VOICE && r_ob->num_selecteditems > 1) {
        jpopupmenu_additem(r_ob->popup_voice, 4000, "Create Voice Ensemble", NULL, 0, 0, NULL);
        if (!is_voice_ensemble)
            jpopupmenu_addseperator(r_ob->popup_voice);
    }
    if (is_voice_ensemble) {
        jpopupmenu_additem(r_ob->popup_voice, 4001, "Break Voice Ensemble", NULL, 0, 0, NULL);
        jpopupmenu_addseperator(r_ob->popup_voice);
    }
    
	// clefs (0)
    jpopupmenu_additem(r_ob->popup_voice_clefs, 50, "Auto", NULL, 0, 0, NULL);
    jpopupmenu_addseperator(r_ob->popup_voice_clefs);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 1, "G", NULL, active_clef == k_CLEF_G, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 2, "F", NULL, active_clef == k_CLEF_F, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 3, "FG", NULL, active_clef == k_CLEF_FG, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 4, "FF", NULL, active_clef == k_CLEF_FF, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 5, "GG", NULL, active_clef == k_CLEF_GG, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 6, "FFG", NULL, active_clef == k_CLEF_FFG, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 7, "FGG", NULL, active_clef == k_CLEF_FGG, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 8, "FFGG", NULL, active_clef == k_CLEF_FFGG, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_voice_clefs);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 10, "G8va", NULL, active_clef == k_CLEF_G8va, 0, NULL);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 11, "G15ma", NULL, active_clef == k_CLEF_G15ma, 0, NULL);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 12, "G8vb", NULL, active_clef == k_CLEF_G8vb, 0, NULL);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 13, "G15mb", NULL, active_clef == k_CLEF_G15mb, 0, NULL);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 14, "F8va", NULL, active_clef == k_CLEF_F8va, 0, NULL);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 15, "F15ma", NULL, active_clef == k_CLEF_F15ma, 0, NULL);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 16, "F8vb", NULL, active_clef == k_CLEF_F8vb, 0, NULL);
    jpopupmenu_additem(r_ob->popup_voice_clefs, 17, "F15mb", NULL, active_clef == k_CLEF_F15mb, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_voice_clefs);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 20, "Soprano", NULL, active_clef == k_CLEF_SOPRANO, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 21, "Mezzo", NULL, active_clef == k_CLEF_MEZZO, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 22, "Alto", NULL, active_clef == k_CLEF_ALTO, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 23, "Tenor", NULL, active_clef == k_CLEF_TENOR, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 24, "Barytone", NULL, active_clef == k_CLEF_BARYTONE, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_voice_clefs);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 30, "Percussion", NULL, active_clef == k_CLEF_PERCUSSION, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_clefs, 31, "None", NULL, active_clef == k_CLEF_NONE, 0, NULL);
	jpopupmenu_addsubmenu(r_ob->popup_voice, "Clef", r_ob->popup_voice_clefs, 0);

	// keys (100)
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 101, "CM", NULL, active_mode == k_MODE_MAJOR && active_key == 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 102, "C#M", NULL, active_mode == k_MODE_MAJOR && active_key == 7, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 103, "DbM", NULL, active_mode == k_MODE_MAJOR && active_key == -5, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 104, "DM", NULL, active_mode == k_MODE_MAJOR && active_key == 2, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 105, "EbM", NULL, active_mode == k_MODE_MAJOR && active_key == -3, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 106, "EM", NULL, active_mode == k_MODE_MAJOR && active_key == 4, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 107, "FM", NULL, active_mode == k_MODE_MAJOR && active_key == -1, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 108, "F#M", NULL, active_mode == k_MODE_MAJOR && active_key == 6, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 109, "GbM", NULL, active_mode == k_MODE_MAJOR && active_key == -6, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 110, "GM", NULL, active_mode == k_MODE_MAJOR && active_key == 1, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 111, "AbM", NULL, active_mode == k_MODE_MAJOR && active_key == -4, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 112, "AM", NULL, active_mode == k_MODE_MAJOR && active_key == 3, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 113, "BbM", NULL, active_mode == k_MODE_MAJOR && active_key == -2, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 114, "BM", NULL, active_mode == k_MODE_MAJOR && active_key == 5, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_major, 115, "CbM", NULL, active_mode == k_MODE_MAJOR && active_key == -7, 0, NULL);
	
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 201, "Cm", NULL, active_mode == k_MODE_MINOR && active_key == -3, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 202, "C#m", NULL, active_mode == k_MODE_MINOR && active_key == 4, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 203, "Dm", NULL, active_mode == k_MODE_MINOR && active_key == -1, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 204, "D#m", NULL, active_mode == k_MODE_MINOR && active_key == 6, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 205, "Ebm", NULL, active_mode == k_MODE_MINOR && active_key == -6, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 206, "Em", NULL, active_mode == k_MODE_MINOR && active_key == 1, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 207, "Fm", NULL, active_mode == k_MODE_MINOR && active_key == -4, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 208, "F#m", NULL, active_mode == k_MODE_MINOR && active_key == 3, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 209, "Gm", NULL, active_mode == k_MODE_MINOR && active_key == -2, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 210, "G#m", NULL, active_mode == k_MODE_MINOR && active_key == 5, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 211, "Abm", NULL, active_mode == k_MODE_MINOR && active_key == -7, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 212, "Am", NULL, active_mode == k_MODE_MINOR && active_key == 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 213, "A#m", NULL, active_mode == k_MODE_MINOR && active_key == 7, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 214, "Bbm", NULL, active_mode == k_MODE_MINOR && active_key == -5, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_keys_minor, 215, "Bm", NULL, active_mode == k_MODE_MINOR && active_key == 2, 0, NULL);
	
	// midichannels (150)
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 151, "1", NULL, active_midichannel == 1, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 152, "2", NULL, active_midichannel == 2, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 153, "3", NULL, active_midichannel == 3, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 154, "4", NULL, active_midichannel == 4, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 155, "5", NULL, active_midichannel == 5, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 156, "6", NULL, active_midichannel == 6, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 157, "7", NULL, active_midichannel == 7, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 158, "8", NULL, active_midichannel == 8, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 159, "9", NULL, active_midichannel == 9, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 160, "10", NULL, active_midichannel == 10, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 161, "11", NULL, active_midichannel == 11, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 162, "12", NULL, active_midichannel == 12, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 163, "13", NULL, active_midichannel == 13, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 164, "14", NULL, active_midichannel == 14, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 165, "15", NULL, active_midichannel == 15, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice_midichannels, 166, "16", NULL, active_midichannel == 16, 0, NULL);
	
	jpopupmenu_addsubmenu(r_ob->popup_voice_keys, "Major", r_ob->popup_voice_keys_major, 0);
	jpopupmenu_addsubmenu(r_ob->popup_voice_keys, "Minor", r_ob->popup_voice_keys_minor, 0);
	jpopupmenu_addsubmenu(r_ob->popup_voice, "Key", r_ob->popup_voice_keys, 0);
	jpopupmenu_addsubmenu(r_ob->popup_voice, "Midichannel", r_ob->popup_voice_midichannels, 0);

	jpopupmenu_addseperator(r_ob->popup_voice);
    jpopupmenu_additem(r_ob->popup_voice, 2000, is_voice_ensemble ? "Delete Voice Ensemble" : "Delete Voice", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice, 2001, "Insert Voice Before This", NULL, 0, r_ob->num_voices >= CONST_MAX_VOICES, NULL);
	jpopupmenu_additem(r_ob->popup_voice, 2002, "Insert Voice After This", NULL, 0, r_ob->num_voices >= CONST_MAX_VOICES, NULL);
    jpopupmenu_additem(r_ob->popup_voice, 2003, is_voice_ensemble ? "Move Voice Ensemble Up" : "Move Voice Up", NULL, 0, voice->number == 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice, 2004, is_voice_ensemble ? "Move Voice Ensemble Down" : "Move Voice Down", NULL, 0, voice->number == r_ob->num_voices - 1, NULL);
	
	// lock/mute (180)
	jpopupmenu_addseperator(r_ob->popup_voice);
	if (!is_all_selection_locked(r_ob))
		jpopupmenu_additem(r_ob->popup_voice, 181, "Lock", NULL, 0, 0, NULL);
	if (!is_all_selection_unlocked(r_ob))
		jpopupmenu_additem(r_ob->popup_voice, 182, "Unlock", NULL, 0, 0, NULL);
	if (!is_all_selection_muted(r_ob))
		jpopupmenu_additem(r_ob->popup_voice, 183, "Mute", NULL, 0, 0, NULL);
	if (!is_all_selection_unmuted(r_ob))
		jpopupmenu_additem(r_ob->popup_voice, 184, "Unmute", NULL, 0, 0, NULL);
	if (!is_all_selection_solo(r_ob))
		jpopupmenu_additem(r_ob->popup_voice, 185, "Solo", NULL, 0, 0, NULL);
	if (!is_all_selection_unsolo(r_ob))
		jpopupmenu_additem(r_ob->popup_voice, 186, "Unsolo", NULL, 0, 0, NULL);
	jpopupmenu_addseperator(r_ob->popup_voice);
	jpopupmenu_additem(r_ob->popup_voice, 191, "No Solos", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_voice, 192, "No Mutes", NULL, 0, 0, NULL);
	
	jpopupmenu_setfont(r_ob->popup_voice, r_ob->popup_main_font);
	jpopupmenu_setfont(r_ob->popup_voice_clefs, r_ob->popup_secondary_font);
	jpopupmenu_setfont(r_ob->popup_voice_keys, r_ob->popup_secondary_font);
	jpopupmenu_setfont(r_ob->popup_voice_keys_major, r_ob->popup_secondary_font);
	jpopupmenu_setfont(r_ob->popup_voice_keys_minor, r_ob->popup_secondary_font);
	jpopupmenu_setfont(r_ob->popup_voice_midichannels, r_ob->popup_secondary_font);
	
}

void build_popup_background_menu(t_notation_obj *r_ob, e_element_types clipboard_type)
{
	if (r_ob->popup_background)
		jpopupmenu_destroy(r_ob->popup_background);
	
	r_ob->popup_background = jpopupmenu_create();
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        jpopupmenu_additem(r_ob->popup_background, 501, "Add Marker", NULL, 0, 0, NULL);
    } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        jpopupmenu_additem(r_ob->popup_background, 502, "Add Measure-Attached Marker", NULL, 0, 0, NULL);
        jpopupmenu_additem(r_ob->popup_background, 503, "Add Millisecond-Attached Marker", NULL, 0, 0, NULL);
    }
    
    jpopupmenu_addseperator(r_ob->popup_background);

    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        jpopupmenu_additem(r_ob->popup_background, 990, "Paste", NULL, 0, clipboard_type != k_SELECTION_CONTENT, NULL);
        jpopupmenu_additem(r_ob->popup_background, 991, "Paste At Original Position", NULL, 0, clipboard_type != k_SELECTION_CONTENT, NULL);
        jpopupmenu_addseperator(r_ob->popup_background);
    }

	// no solo/no mute (1000)
	jpopupmenu_additem(r_ob->popup_background, 1001, "No Solos", NULL, 0, 0, NULL);
	jpopupmenu_additem(r_ob->popup_background, 1002, "No Mutes", NULL, 0, 0, NULL);

    jpopupmenu_addseperator(r_ob->popup_background);

    jpopupmenu_additem(r_ob->popup_background, 1021, "Select All Items Till Here", NULL, 0, 0, NULL);
    jpopupmenu_additem(r_ob->popup_background, 1020, "Select All Items From Here", NULL, 0, 0, NULL);

	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
		jpopupmenu_additem(r_ob->popup_background, 1010, "Ceil Measures", NULL, 0, 0, NULL);
	
	jpopupmenu_setfont(r_ob->popup_background, r_ob->popup_main_font);
	
}

void build_popup_articulations_menu(t_notation_obj *r_ob, t_articulation *art)
{
    long i;
    if (r_ob->popup_articulations)
        jpopupmenu_destroy(r_ob->popup_articulations);
    
    r_ob->popup_articulations = jpopupmenu_create();
    
    jpopupmenu_additem(r_ob->popup_articulations, 1000, "Delete", NULL, 0, 0, NULL);
    jpopupmenu_addseperator(r_ob->popup_articulations);

    for (i = 1; i < r_ob->articulations_typo_preferences.num_articulations; i++)
        jpopupmenu_additem(r_ob->popup_articulations, 1000 + i, articulation_id2symbol(&r_ob->articulations_typo_preferences, i)->s_name, NULL, i == art->articulation_ID, 0, NULL);
    
    jpopupmenu_setfont(r_ob->popup_articulations, r_ob->popup_main_font);
}

void initialize_popup_menus(t_notation_obj *r_ob){
	// create font
	r_ob->popup_main_font = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, 12);
	r_ob->popup_secondary_font = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, 12);
	
	r_ob->popup_voice = NULL;
	r_ob->popup_voice_keys = NULL;
	r_ob->popup_voice_keys_major = NULL;
	r_ob->popup_voice_keys_major = NULL;
	r_ob->popup_voice_clefs = NULL;
	r_ob->popup_voice_midichannels = NULL;

	r_ob->popup_note = NULL;
	r_ob->popup_note_slots = NULL;
	r_ob->popup_note_enharmonicity = NULL;
    r_ob->popup_note_copy = r_ob->popup_note_paste = r_ob->popup_note_copy_slot = r_ob->popup_note_paste_slot = NULL;

	r_ob->popup_measure = NULL;
	r_ob->popup_measure_timesignature = NULL;

	r_ob->popup_barline = NULL;

	r_ob->popup_background = NULL;
    r_ob->popup_articulations = NULL;
	
	r_ob->popup_filters = NULL;
}

void destroy_popup_menus(t_notation_obj *r_ob){
	if (r_ob->popup_voice)
		jpopupmenu_destroy(r_ob->popup_voice);
	if (r_ob->popup_voice_clefs)
		jpopupmenu_destroy(r_ob->popup_voice_clefs);
	if (r_ob->popup_voice_keys)
		jpopupmenu_destroy(r_ob->popup_voice_keys);
	if (r_ob->popup_voice_keys_major)
		jpopupmenu_destroy(r_ob->popup_voice_keys_major);
	if (r_ob->popup_voice_keys_minor)
		jpopupmenu_destroy(r_ob->popup_voice_keys_minor);
	if (r_ob->popup_voice_midichannels)
		jpopupmenu_destroy(r_ob->popup_voice_midichannels);
	
	if (r_ob->popup_note)
		jpopupmenu_destroy(r_ob->popup_note);
	if (r_ob->popup_note_slots)
		jpopupmenu_destroy(r_ob->popup_note_slots);
	if (r_ob->popup_note_enharmonicity)
		jpopupmenu_destroy(r_ob->popup_note_enharmonicity);
    if (r_ob->popup_note_copy)
        jpopupmenu_destroy(r_ob->popup_note_copy);
    if (r_ob->popup_note_paste)
        jpopupmenu_destroy(r_ob->popup_note_paste);
    if (r_ob->popup_note_copy_slot)
        jpopupmenu_destroy(r_ob->popup_note_copy_slot);
    if (r_ob->popup_note_paste_slot)
        jpopupmenu_destroy(r_ob->popup_note_paste_slot);

	if (r_ob->popup_measure)
		jpopupmenu_destroy(r_ob->popup_measure);
	if (r_ob->popup_measure_timesignature)
		jpopupmenu_destroy(r_ob->popup_measure_timesignature);

	if (r_ob->popup_background)
		jpopupmenu_destroy(r_ob->popup_background);

    if (r_ob->popup_articulations)
        jpopupmenu_destroy(r_ob->popup_articulations);
    
	if (r_ob->popup_barline)
		jpopupmenu_destroy(r_ob->popup_barline);

	if (r_ob->popup_filters)
		jpopupmenu_destroy(r_ob->popup_filters);

	if (r_ob->popup_main_font)
		jfont_destroy_debug(r_ob->popup_main_font);
	
	if (r_ob->popup_secondary_font)
		jfont_destroy_debug(r_ob->popup_secondary_font);
}

/// COMMON ATTRIBUTES

void notationobj_arg_attr_dictionary_process_with_bw_compatibility(void *x, t_dictionary *d)
{
    t_notation_obj *r_ob = (t_notation_obj *)x;
	long ac_backgroundslots, ac_mainstavescolor, ac_auxiliarystavescolor;
	t_atom *av_backgroundslots = NULL, *av_mainstavescolor = NULL, *av_auxiliarystavescolor = NULL;
	t_atom_long *av_long = NULL;
	long has_backgroundslots = 0, has_slotsbgalpha = 0, has_backgroundslotfontsize = 0, has_velocityhandling = 0, has_notificationsformessages = 0, has_continuousbang = 0;
	double slotbgalpha = 0, backgroundslotfontsize = 0;
    t_atom_long velocityhandling = -1, notificationsformessages = -1, continuousbang = -1;
    char brand_new_creation = 0;

    
    long num_voices_from_argument = -1; // = no need to set num voices
    const char *str = NULL;
    dictionary_getstring(d, gensym("boxtext"), &str);
    if (str && str[0] && (r_ob->obj_type == k_NOTATION_OBJECT_ROLL || r_ob->obj_type == k_NOTATION_OBJECT_SCORE)) {
        long size = strlen(str);
        char *str_cpy = (char *)bach_newptr((size + 1) * sizeof(char));
        bach_copyptr(str, str_cpy, (size + 1) * sizeof(char));
        char *pch = strtok(str_cpy," ");
        long count = 0;
        while (pch != NULL){
            if (pch[0] == '@')
                break;
            if (count == 1) {
                num_voices_from_argument = CLAMP(atoi(pch), 1, CONST_MAX_VOICES);
                break;
            }
            count ++;
            pch = strtok(NULL, " ");
        }
        bach_freeptr(str_cpy);
    }
    
//    dictionary_dump(d, 1, 1);
    
    t_atom_long versionnumber = 0;
	if (dictionary_hasentry(d, gensym("versionnumber"))) {
		dictionary_getlong(d, gensym("versionnumber"), &versionnumber);
        
        // Setting retrieved version number (because it will be accounted for when the data is loaded in the new() method, after this subroutine has returned
        // At the end of the new() method the CURRENT version number will finally be stored
        llllobj_set_version_number((t_object *)r_ob, LLLL_OBJ_UI, versionnumber);
        
        if (versionnumber == 0)
            brand_new_creation = true;
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && versionnumber > 0 && versionnumber <= 7200)
			r_ob->old_timepoint_syntax_bw_compatibility = true;
	}

    if (dictionary_hasentry(d, gensym("mainstavescolor")))
        dictionary_getatoms(d, gensym("mainstavescolor"), &ac_mainstavescolor, &av_mainstavescolor);

    if (dictionary_hasentry(d, gensym("auxiliarystavescolor")))
        dictionary_getatoms(d, gensym("auxiliarystavescolor"), &ac_auxiliarystavescolor, &av_auxiliarystavescolor);

	if ((has_backgroundslots = dictionary_hasentry(d, gensym("backgroundslots"))))
		dictionary_getatoms(d, gensym("backgroundslots"), &ac_backgroundslots, &av_backgroundslots);
	
	if ((has_slotsbgalpha = dictionary_hasentry(d, gensym("slotsbgalpha"))))
		dictionary_getfloat(d, gensym("slotsbgalpha"), &slotbgalpha);
	
	if ((has_backgroundslotfontsize = dictionary_hasentry(d, gensym("backgroundslotfontsize"))))
		dictionary_getfloat(d, gensym("backgroundslotfontsize"), &backgroundslotfontsize);

    if ((has_velocityhandling = dictionary_hasentry(d, gensym("velocityhandling"))))
        dictionary_getlong(d, gensym("velocityhandling"), &velocityhandling);

    if ((has_notificationsformessages = dictionary_hasentry(d, gensym("notificationsformessages"))))
        dictionary_getlong(d, gensym("notificationsformessages"), &notificationsformessages);

    if ((has_continuousbang = dictionary_hasentry(d, gensym("continuousbang"))))
        dictionary_getlong(d, gensym("continuousbang"), &continuousbang);
    else if ((has_continuousbang = dictionary_hasentry(d, gensym("continuouslyoutputbangifchanged"))))
        dictionary_getlong(d, gensym("continuouslyoutputbangifchanged"), &continuousbang);

    if (num_voices_from_argument > 0) {
        t_atom av;
        atom_setlong(&av, num_voices_from_argument);
        notationobj_setattr_numvoices(r_ob, NULL, 1, &av);
    }
    
	attr_dictionary_process(x, d);
    
    if (versionnumber > 0 && versionnumber <= 7900) {
        // up to 0.7.9 there was no slot linkage for slot 9 and 10; we keep this that way.
        change_linkto_slot_flag(r_ob, -1, k_SLOT_LINKAGE_ANNOTATION);
        change_linkto_slot_flag(r_ob, -1, k_SLOT_LINKAGE_ARTICULATIONS);
        if (r_ob->link_notehead_to_slot == 9)
            change_linkto_slot_flag(r_ob, -1, k_SLOT_LINKAGE_NOTEHEAD);
    }
    if (versionnumber > 0 && versionnumber <= 70905)  {
        change_linkto_slot_flag(r_ob, -1, k_SLOT_LINKAGE_DYNAMICS);
        change_linkto_slot_flag(r_ob, 6, k_SLOT_LINKAGE_LYRICS);
    }

    
	if (has_backgroundslots) {
		av_long = (t_atom_long *) bach_newptr(ac_backgroundslots * sizeof(t_atom_long));
		atom_getlong_array(ac_backgroundslots, av_backgroundslots, ac_backgroundslots, av_long);
		//object_attr_setlong_array(x, gensym("bgslots"), ac_backgroundslots, av_long);
		bach_freeptr(av_long);
		// Don't need to free av_backgroundslots: dictionary_getatoms fetch the atoms by reference 
		// WHAT DOES THIS PART OF CODE DO?!?!?! SHOULD WE GET RID OF THIS?!?
	}
    
    if (av_mainstavescolor && ac_mainstavescolor >= 4) {
        t_jrgba color = build_jrgba(atom_getfloat(av_mainstavescolor), atom_getfloat(av_mainstavescolor + 1), atom_getfloat(av_mainstavescolor + 2), atom_getfloat(av_mainstavescolor + 3));
        object_attr_setcolor((t_object *)x, gensym("staffcolor"), &color);
    }

    if (av_auxiliarystavescolor && ac_auxiliarystavescolor >= 4) {
        t_jrgba color = build_jrgba(atom_getfloat(av_auxiliarystavescolor), atom_getfloat(av_auxiliarystavescolor + 1), atom_getfloat(av_auxiliarystavescolor + 2), atom_getfloat(av_auxiliarystavescolor + 3));
        object_attr_setcolor((t_object *)x, gensym("auxstaffcolor"), &color);
    }

	if (has_slotsbgalpha)
		object_attr_setfloat(x, gensym("slotwinalpha"), slotbgalpha);
	
	if (has_backgroundslotfontsize) 
		object_attr_setfloat(x, gensym("bgslotfontsize"), backgroundslotfontsize);
	
    if (has_velocityhandling)
        object_attr_setchar(x, gensym("showvelocity"), velocityhandling);
    
    if (has_notificationsformessages)
        object_attr_setchar(x, gensym("notifymessages"), notificationsformessages);
    
    if (has_continuousbang)
        object_attr_setchar(x, gensym("notifycontinuously"), continuousbang);

    // Setting object size depending on numvoices
    if (brand_new_creation && r_ob->link_vzoom_to_height && r_ob->num_voices > 1) {
        if (r_ob->num_voices <= 4) r_ob->zoom_y = 1.;
        else if (r_ob->num_voices <= 8) r_ob->zoom_y = 0.7;
        else if (r_ob->num_voices <= 12) r_ob->zoom_y = 0.5;
        else if (r_ob->num_voices <= 16) r_ob->zoom_y = 0.3;
        else if (r_ob->num_voices <= 20) r_ob->zoom_y = 0.15;
        else r_ob->zoom_y = 0.05;
        auto_set_rectangle_size_do(r_ob);
    }
}

void notation_class_add_notation_attributes(t_class *c, char obj_type){
	
// setting default textedit fields attribute invisible
// YET MAX 7 DOESN'T LOVE THESE 4 FOLLOWING LINES, SO WE DON' DO THIS FOR THE TIME BEING:
//	CLASS_ATTR_INVISIBLE(c, "textcolor", 0);
//	CLASS_ATTR_INVISIBLE(c, "fontface", 0);
//	CLASS_ATTR_INVISIBLE(c, "fontsize", 0);
//	CLASS_ATTR_INVISIBLE(c, "fontname", 0);
	
	notation_class_add_behavior_attributes(c, obj_type);
    notation_class_add_notification_attributes(c, obj_type);
	notation_class_add_edit_attributes(c, obj_type);
	notation_class_add_showhide_attributes(c, obj_type);
	notation_class_add_font_attributes(c, obj_type);
	notation_class_add_settings_attributes(c, obj_type);
	notation_class_add_slots_attributes(c, obj_type);
	notation_class_add_play_attributes(c, obj_type);
	notation_class_add_color_attributes(c, obj_type);
	notation_class_add_appearance_attributes(c, obj_type);
    notation_class_add_pitches_attributes(c, obj_type);

    CLASS_STICKY_ATTR(c,"category",0,"Notation");
    
    CLASS_ATTR_CHAR(c,"showaccidentalspreferences",0, t_notation_obj, show_accidentals_preferences);
    CLASS_ATTR_STYLE_LABEL(c,"showaccidentalspreferences",0,"enumindex","Display Accidentals");
    CLASS_ATTR_ENUMINDEX(c,"showaccidentalspreferences", 0, "Classically Always Altered Notes Altered Notes (No Repetition) Altered Note (No Naturals) Never");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showaccidentalspreferences", 0, "0");
    CLASS_ATTR_ACCESSORS(c, "showaccidentalspreferences", (method)NULL, (method)notationobj_setattr_showaccidentalspreferences);
    // @description Handles the display of accidentals: <br />
    // - Classically (default): for <o>bach.score</o>: accidentals are displayed classically, i.e. on the first (altered) note requiring them,
    //  and them never for any other note inside the same measure (but cautionary accidentals are possible: see the attribute <m>cautionaryaccidentals</m>);
    // for <o>bach.roll</o>: this coincides with Altered Note (No Naturals) (see below). <br />
    // - Always: accidentals are always displayed for all altered and naturals notes. <br />
    // - Altered Notes: accidentals are always displayed for any altered note. Natural signs are preserved for notes which have to cancel such accidental. <br />
    // - Altered Notes (No Repetition): accidentals are always displayed for any altered note, but dropped for immediate repetitions of the same note. <br />
    // - Altered Note (No Naturals): accidentals are always displayed for any altered note, and natural signs are dropped for notes having to cancel such accidentals.
    // In this case all non-natural notes have their accidental, and all natural notes have no accidental. <br />
    // - Never: accidentals are never shown (always hidden). <br />
    // IMPORTANT: be aware of the fact that, due to the cross dependencies between accidentals, in <o>bach.roll</o> the "Altered Notes"
    // "Altered Notes (No Repetition)" configurations can be sensibly slower than any other any other configuration
    // (<o>bach.score</o>, on the other hand, does not suffer from this issue).

    CLASS_STICKY_ATTR_CLEAR(c, "category");
}

void notation_class_add_slots_attributes(t_class *c, char obj_type){
	CLASS_STICKY_ATTR(c,"category",0,"Slots");
	
	CLASS_ATTR_DOUBLE(c,"slotwinalpha",0, t_notation_obj, slot_background_alpha_percentage);
	CLASS_ATTR_STYLE_LABEL(c,"slotwinalpha",0,"text","Slot Window Opacity %");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"slotwinalpha", 0, obj_type == k_NOTATION_OBJECT_SLOT ? "100" : "100");
	CLASS_ATTR_FILTER_CLIP(c, "slotwinalpha", 0., 100.);
	// @description Sets the percentage of transparency of the slot windows (0 being completely transparent, 100
	// being completely opaque.
	
	CLASS_ATTR_NOTATIONOBJ_LONGPTR(c, "bgslots", 0, background_slots, CONST_MAX_SLOTS, notationobj_setattr_backgroundslots);
	CLASS_ATTR_STYLE_LABEL(c,"bgslots",0,"text","Slots In Background");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"bgslots",0,"");
	// @description Sets the slots to be displayed on the background even when slots windows are not open.
	// The attribute expects a list of integers, each representing a slot number.
	
	// (just for bw compatibility)
	CLASS_ATTR_NOTATIONOBJ_LONGPTR(c, "backgroundslots", 0, background_slots, CONST_MAX_SLOTS, notationobj_setattr_backgroundslots);
	CLASS_ATTR_PAINT(c,"backgroundslots",0);
	CLASS_ATTR_INVISIBLE(c, "backgroundslots", 0); // just for bw compatibility
	// @exclude all
	
	CLASS_ATTR_CHAR(c,"allowslothzoom",0, t_notation_obj, allow_horizontal_slot_zooming);
	CLASS_ATTR_STYLE_LABEL(c,"allowslothzoom",0,"onoff","Allow Slot Horizontal Zooming");
	CLASS_ATTR_FILTER_CLIP(c, "allowslothzoom", 0, 1);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"allowslothzoom",0,"1");
	// @description Toggles the ability to allow the horizontal slot zooming and navigation (via mousewheel and <m>Cmd</m>+mousewheel, as standard zoom)
	// for slots of type function, 3dfunction, spat and dynfilter. However, for <o>bach.roll</o> and <o>bach.score</o>, 
	// if the slot is defined to be "temporal", no slot zooming will be allowed,
	// as the zoom will be passed to the underlying notation object.


	
	if (obj_type != k_NOTATION_OBJECT_SLOT){
		// (just for bw compatibility)
		CLASS_ATTR_DOUBLE(c, "slotsbgalpha", 0, t_notation_obj, slot_background_alpha_percentage);
		CLASS_ATTR_PAINT(c,"slotsbgalpha",0);
		CLASS_ATTR_INVISIBLE(c, "slotsbgalpha", 0);
		// @exclude all
		
		CLASS_ATTR_DOUBLE(c, "slotwinzoom", 0, t_notation_obj, slot_window_zoom); 
		CLASS_ATTR_STYLE_LABEL(c,"slotwinzoom",0,"text","Zoom For Slot Window");
		CLASS_ATTR_FILTER_MIN(c, "slotwinzoom", 0.);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"slotwinzoom",0,"125");
		// @exclude bach.slot
		// @description Sets an independent zoom factor for slot windows. This factor is set as a percentage,
		// 100 corresponding to the default standard zoom.
		
		CLASS_ATTR_DOUBLE(c, "bgslotzoom", 0, t_notation_obj, bgslot_zoom); 
		CLASS_ATTR_STYLE_LABEL(c,"bgslotzoom",0,"text","Zoom For Slot In Background");
		CLASS_ATTR_FILTER_MIN(c, "bgslotzoom", 0.);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"bgslotzoom",0,"100");
		// @exclude bach.slot
		// @description Sets the independent zoom factor relative to the slots displayed in background.
		
		CLASS_ATTR_NOTATIONOBJ_LONGPTR(c, "popupmenuslots", 0, popup_menu_slots, CONST_MAX_SLOTS, notationobj_setattr_popupmenuslots);
		CLASS_ATTR_STYLE_LABEL(c,"popupmenuslots",0,"text","Slots In Popup Menu");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"popupmenuslots",0,"");
		// @exclude bach.slot
		// @description Sets the slots which should show up in the right-click (or two-fingers-tap) popup menu 
		// of a note. The attribute expects a list of integers, each representing a slot number.
		
		CLASS_ATTR_LONG(c,"linknotecolortoslot",0, t_notation_obj, link_nitemcolor_to_slot);
		CLASS_ATTR_STYLE_LABEL(c,"linknotecolortoslot",0,"text","Link Note Color To Slot");
		CLASS_ATTR_FILTER_CLIP(c, "linknotecolortoslot", 0, CONST_MAX_SLOTS);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linknotecolortoslot",0,"0");
        CLASS_ATTR_ACCESSORS(c, "linknotecolortoslot", (method)NULL, (method)notationobj_setattr_linknotecolortoslot);
		// @exclude bach.slot
		// @description Sets the slot number of the slot whose content must be linked to the note colors.
		// An int, float, floatlist or color slot is expected. Int slots are mapped on default colors,
		// float slots are mapped on the color spectrum, floatlist slots are interpreted as RGBA coordinates
		// while color slots are simply taken as they are.
		// 0 (default) means: none.
	 	
        
        char tempstr[10];
        sprintf(tempstr, "%d", BACH_DEFAULT_SLOT_LYRICS);
		CLASS_ATTR_LONG(c,"linklyricstoslot",0, t_notation_obj, link_lyrics_to_slot);
		CLASS_ATTR_STYLE_LABEL(c,"linklyricstoslot",0,"text","Link Lyrics To Slot");
		CLASS_ATTR_FILTER_CLIP(c, "linklyricstoslot", 0, CONST_MAX_SLOTS);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linklyricstoslot",0,tempstr);
		CLASS_ATTR_ACCESSORS(c, "linklyricstoslot", (method)NULL, (method)notationobj_setattr_linklyricstoslot);
		// @exclude bach.slot
		// @description Sets the slot number of the slot whose content is to be displayed as lyrics.
		// A text slot is expected.
		// 0 (default) means: none.
		
        sprintf(tempstr, "%d", BACH_DEFAULT_SLOT_NOTEHEADS);
		CLASS_ATTR_LONG(c,"linknoteheadtoslot",0, t_notation_obj, link_notehead_to_slot);
		CLASS_ATTR_STYLE_LABEL(c,"linknoteheadtoslot",0,"text","Link Note Head To Slot");
		CLASS_ATTR_FILTER_CLIP(c, "linknoteheadtoslot", 0, CONST_MAX_SLOTS);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linknoteheadtoslot",0,tempstr);
        CLASS_ATTR_ACCESSORS(c, "linknoteheadtoslot", (method)NULL, (method)notationobj_setattr_linknoteheadtoslot);
		// @exclude bach.slot
		// @description Sets the slot number of the slot whose content is to be associated with the notehead
		// characters of each note. A slot of type "notehead" (or, for backward compatibility, "int") is expected.
        // 0 means: none.
		
		CLASS_ATTR_LONG(c,"linknoteheadfonttoslot",0, t_notation_obj, link_notehead_font_to_slot);
		CLASS_ATTR_STYLE_LABEL(c,"linknoteheadfonttoslot",0,"text","Link Note Head Font To Slot");
		CLASS_ATTR_FILTER_CLIP(c, "linknoteheadfonttoslot", 0, CONST_MAX_SLOTS);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linknoteheadfonttoslot",0,"0");
        CLASS_ATTR_ACCESSORS(c, "linknoteheadfonttoslot", (method)NULL, (method)notationobj_setattr_linknoteheadfonttoslot);
		// @exclude bach.slot
		// @description Sets the slot number of the slot whose content is the name of the font with which
		// the note should be displayed. A text slot is expected.
		// 0 (default) means: none.
		
		CLASS_ATTR_LONG(c,"linknoteheadadjusttoslot",0, t_notation_obj, link_notehead_adjust_to_slot);
		CLASS_ATTR_STYLE_LABEL(c,"linknoteheadadjusttoslot",0,"text","Link Note Head Adjust To Slot");
		CLASS_ATTR_FILTER_CLIP(c, "linknoteheadadjusttoslot", 0, CONST_MAX_SLOTS);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linknoteheadadjusttoslot",0,"0");
        CLASS_ATTR_ACCESSORS(c, "linknoteheadadjusttoslot", (method)NULL, (method)notationobj_setattr_linknoteheadadjusttoslot);
		// @exclude bach.slot
		// @description Sets the slot number of the slot whose content is associated with noteheads
		// horizontal and vertical adjustments. An intlist or floatlist slot is expected.
		// 0 (default) means: none.
		
		CLASS_ATTR_LONG(c,"linknotesizetoslot",0, t_notation_obj, link_notesize_to_slot);
		CLASS_ATTR_STYLE_LABEL(c,"linknotesizetoslot",0,"text","Link Note Size To Slot");
		CLASS_ATTR_FILTER_CLIP(c, "linknotesizetoslot", 0, CONST_MAX_SLOTS);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linknotesizetoslot",0,"0");
        CLASS_ATTR_ACCESSORS(c, "linknotesizetoslot", (method)NULL, (method)notationobj_setattr_linknoteheadsizetoslot);
		// @exclude bach.slot
		// @description Sets the slot number of the slot whose content is linked with a note size factor,
		// as a percentage (100 being the usual size). A float slot is expected (to change both note
		// and accidentals size at the same time), or also a floatlist slot can be used, in which case
		// two factor are expected: one for the note size and one for the accidentals size.
		// 0 (default) means: none.

        sprintf(tempstr, "%d", BACH_DEFAULT_SLOT_ARTICULATIONS);
        CLASS_ATTR_LONG(c,"linkarticulationstoslot",0, t_notation_obj, link_articulations_to_slot);
        CLASS_ATTR_STYLE_LABEL(c,"linkarticulationstoslot",0,"text","Link Articulations To Slot");
        CLASS_ATTR_FILTER_CLIP(c, "linkarticulationstoslot", 0, CONST_MAX_SLOTS);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linkarticulationstoslot",0,tempstr);
        CLASS_ATTR_ACCESSORS(c, "linkarticulationstoslot", (method)NULL, (method)notationobj_setattr_linkarticulationstoslot);
        // @exclude bach.slot
        // @description Sets the slot number of the slot (of type "articulations") whose content is linked with the articulations display.
        // 0 means: none.

        sprintf(tempstr, "%d", BACH_DEFAULT_SLOT_ANNOTATIONS);
        CLASS_ATTR_LONG(c,"linkannotationtoslot",0, t_notation_obj, link_annotation_to_slot);
        CLASS_ATTR_STYLE_LABEL(c,"linkannotationtoslot",0,"text","Link Text Annotation To Slot");
        CLASS_ATTR_FILTER_CLIP(c, "linkannotationtoslot", 0, CONST_MAX_SLOTS);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linkannotationtoslot",0,tempstr);
        CLASS_ATTR_ACCESSORS(c, "linkannotationtoslot", (method)NULL, (method)notationobj_setattr_linkannotationtoslot);
        // @exclude bach.slot
        // @description Sets the slot number of the slot whose content is to be displayed as annotation over the staff.
        // 0 (default) means: none.

        sprintf(tempstr, "%d", BACH_DEFAULT_SLOT_DYNAMICS);
        CLASS_ATTR_LONG(c,"linkdynamicstoslot",0, t_notation_obj, link_dynamics_to_slot);
        CLASS_ATTR_STYLE_LABEL(c,"linkdynamicstoslot",0,"text","Link Dynamics To Slot");
        CLASS_ATTR_FILTER_CLIP(c, "linkdynamicstoslot", 0, CONST_MAX_SLOTS);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linkdynamicstoslot",0,tempstr);
        CLASS_ATTR_ACCESSORS(c, "linkdynamicstoslot", (method)NULL, (method)notationobj_setattr_linkdynamicstoslot);
        // @exclude bach.slot
        // @description Sets the slot number of the slot whose content is to be displayed as dynamics under the staff.
        // 0 means: none.
        
        CLASS_ATTR_LONG(c,"linkdlcolortoslot",0, t_notation_obj, link_dlcolor_to_slot);
        CLASS_ATTR_STYLE_LABEL(c,"linkdlcolortoslot",0,"text","Link Duration Line Color To Slot");
        CLASS_ATTR_FILTER_CLIP(c, "linkdlcolortoslot", 0, CONST_MAX_SLOTS);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linkdlcolortoslot",0,"0");
        CLASS_ATTR_ACCESSORS(c, "linkdlcolortoslot", (method)NULL, (method)notationobj_setattr_linkdlcolortoslot);
        // @exclude bach.slot
        // @description Sets the slot number of the slot whose content is to be associated with the color
        // of the corresponding duration line. An int, float, floatlist or color slot is expected. Int slots are mapped on default colors,
        // float slots are mapped on the color spectrum, floatlist slots are interpreted as RGBA coordinates
        // while color slots are simply taken as they are.
        // 0 (default) means: none.
        
		CLASS_ATTR_DOUBLE(c, "slotminimumwindowwidth", 0, t_notation_obj, slot_minimum_window_uwidth);
		CLASS_ATTR_STYLE_LABEL(c,"slotminimumwindowwidth",0,"text","Minimum Slot Window Width");
		CLASS_ATTR_FILTER_MIN(c, "slotminimumwindowwidth", 0.	);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"slotminimumwindowwidth",0,"0");
		// @exclude bach.slot
		// @description Sets the minimum width of a slot window.
		
		CLASS_ATTR_LONG(c,"rightclickslot",0, t_notation_obj, right_click_directly_pops_out_slot);
		CLASS_ATTR_STYLE_LABEL(c,"rightclickslot",0,"text","Right Click Directly Pops Out Slot");
		CLASS_ATTR_FILTER_CLIP(c, "rightclickslot", 0, CONST_MAX_SLOTS);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rightclickslot",0,"0");
		CLASS_ATTR_ACCESSORS(c, "rightclickslot", (method)NULL, (method)notationobj_setattr_rightclickdirectlypopsoutslot);
		// @exclude bach.slot
		// @description Sets the number of the slot whose window should automatically popup when a
		// right-click (or a two-fingers-tap) is performed on a notehead. 0 (default) means: none 
		// (in which case the usual contextual menu pops up).
		
		CLASS_ATTR_CHAR(c,"outputslotnames",0, t_notation_obj, output_slot_names);
		CLASS_ATTR_STYLE_LABEL(c,"outputslotnames",0,"onoff","Output Slot Names From Playout");
		CLASS_ATTR_FILTER_CLIP(c, "outputslotnames", 0, 1);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"outputslotnames",0,"0");
		// @exclude bach.slot
		// @description Toggles the ability to output slot names instead of slot numbers when slot information
		// is sent through the playout.
		
		CLASS_ATTR_DOUBLE_ARRAY(c, "bgslottextshift", 0, t_notation_obj, background_slot_text_ushift, 2); 
		CLASS_ATTR_STYLE_LABEL(c,"bgslottextshift",0,"text","Background Slot Text Shift");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"bgslottextshift",0,"0 0");
		// @exclude bach.slot
		// @description Sets an horizontal and vertical shift coefficients for the slot text displayed
		// for slots kept in background.
        
        
        CLASS_ATTR_CHAR(c,"applyslope",0, t_notation_obj, combine_range_slope_during_playback);
        CLASS_ATTR_STYLE_LABEL(c,"applyslope",0,"onoff","Apply Range Slopes During Playback");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"applyslope", 0, "1");
        // @exclude bach.slot
        // @description Toggle the ability to change the slopes in function slots in order to possibly apply range slopes.
        // The new slopes will hence account for the visual range slope too. By default it is active.
	}
	
	CLASS_ATTR_CHAR(c, "showslotnumbers", 0, t_notation_obj, show_slot_numbers);
	CLASS_ATTR_STYLE_LABEL(c,"showslotnumbers",0,"onoff","Show Slot Numbers In Slot Window");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showslotnumbers",0,"1");
	// @description Toggles the display of slot numbers in the slot windows.

	CLASS_ATTR_CHAR(c, "showslotlabels", 0, t_notation_obj, show_slot_labels);
	CLASS_ATTR_STYLE_LABEL(c,"showslotlabels",0,"onoff","Show Slot Labels");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showslotlabels",0,"1");
	// @description Toggles the display of automatic labels for points in the function slots and for bars in the intlist or floatlist slots.

	CLASS_ATTR_CHAR(c,"showslotlegend",0, t_notation_obj, show_slot_legend);
	CLASS_ATTR_STYLE_LABEL(c,"showslotlegend",0,"onoff","Show Slot Legend");
	CLASS_ATTR_FILTER_CLIP(c, "showslotlegend", 0, 1);
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showslotlegend",0,"1");
	// @description Toggles the ability to display the slot legend at the top right angle.
	
	CLASS_ATTR_DOUBLE(c, "samplingrate", 0, t_notation_obj, sampling_freq);
	CLASS_ATTR_STYLE_LABEL(c,"samplingrate",0,"text","Sampling Rate (For Filter Slots)");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"samplingrate",0,"44100");
	CLASS_ATTR_ACCESSORS(c, "samplingrate", (method)NULL, (method)notationobj_setattr_samplingrate);
	// @description Sets the currentl sampling rate. "Manually" setting the sampling rate
	// is necessary for a proper handling of the filter slots. No object in the bach library is a
	// DSP objects, so this information should be set "by hand" (it could easily come from <o>dspstatus~</o>).
	
	CLASS_ATTR_DOUBLE(c,"slotfunctionptradius",0, t_notation_obj, function_slot_pt_uradius);
	CLASS_ATTR_STYLE_LABEL(c,"slotfunctionptradius",0,"text","Function Slot Point Radius");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"slotfunctionptradius", 0, "1.3");
	// @description Sets the size of the radius of breakpoints inside slots of type function
	// (rescaled according to the <m>vzoom</m>).
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
}



void notation_class_add_color_attributes(t_class *c, char obj_type){
	CLASS_STICKY_ATTR(c,"category",0,"Color");
	
	CLASS_ATTR_RGBA_LEGACY(c, "bgcolor", "brgb", 0, t_notation_obj, j_background_rgba);
	CLASS_ATTR_ALIAS(c,"bgcolor", "brgba");
	CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
	CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"bgcolor",0,"1. 1. 1. 1.");
	CLASS_ATTR_ACCESSORS(c, "bgcolor", (method)NULL, (method)notationobj_setattr_bgcolor);
	CLASS_ATTR_BASIC(c,"bgcolor", 0);
	// @description Sets the color of the background in RGBA format. 
	
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		CLASS_ATTR_RGBA(c,"bordercolor",0, t_notation_obj, j_border_rgba);
		CLASS_ATTR_STYLE_LABEL(c,"bordercolor",0,"rgba","Border Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"bordercolor",0,"0.6 0.6 0.6 1.");
		// @exclude bach.slot
		// @description Sets the color of the border in RGBA format. 
	}

	CLASS_ATTR_RGBA(c,"selectioncolor", 0, t_notation_obj, j_selection_rgba);
	CLASS_ATTR_STYLE_LABEL(c, "selectioncolor",0,"rgba","Selection Color");
	CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"selectioncolor",0,"0.8 0. 0.8 1.");
	// @description Sets the color of each selected notehead, accidental, duration line and note tail in RGBA format. 
	
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		
		CLASS_ATTR_RGBA(c,"legendcolor", 0, t_notation_obj, j_legend_rgba); 
		CLASS_ATTR_STYLE_LABEL(c, "legendcolor",0,"rgba","Mouseover Legend Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"legendcolor",0,"0.5 0.5 0.5 1.");
		// @exclude bach.slot
		// @description Sets the color of the mouseover legend (displayed at the bottom right corner of the notation object) 
		// in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"selectedlegendcolor", 0, t_notation_obj, j_selectedlegend_rgba); 
		CLASS_ATTR_STYLE_LABEL(c, "selectedlegendcolor",0,"rgba","Selection Legend Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"selectedlegendcolor",0,"0.2 0.2 0.2 1.");
		// @exclude bach.slot
		// @description Sets the color of the selection legend (displayed at the top left corner of the notation object, 
		// when one clicks on a notation item) in RGBA format. 

		CLASS_ATTR_RGBA(c,"staffcolor", 0, t_notation_obj, j_mainstaves_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "staffcolor",0,"rgba","Main Staff Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"staffcolor",0,"0. 0. 0. 1.");
		// @exclude bach.slot
		// @description Sets the color of the main staves (the ones always carring the clefs) in RGBA format. 
			
        CLASS_ATTR_RGBA(c,"auxstaffcolor", 0, t_notation_obj, j_auxiliarystaves_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "auxstaffcolor",0,"rgba","Auxiliary Staff Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"auxstaffcolor",0,"0.4 0.4 0.4 1.");
		// @exclude bach.slot
		// @description Sets the color of the auxiliary staves (the ones extending the standard G and F clefs above or below) in RGBA format. 
        
        CLASS_ATTR_RGBA(c,"keysigcolor", 0, t_notation_obj, j_keysig_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "keysigcolor",0,"rgba","Key Signature Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"keysigcolor",0,"0. 0. 0. 1.");
        // @exclude bach.slot
        // @description Sets the color of the key signature, in RGBA format.

        
		CLASS_ATTR_RGBA(c,"notecolor", 0, t_notation_obj, j_note_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "notecolor",0,"rgba","Note Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"notecolor",0,"0. 0. 0. 1.");
		// @exclude bach.slot
		// @description Sets the color (in RGBA format) of noteheads, duration lines, note tails, rests, etc.

        CLASS_ATTR_RGBA(c,"accidentalcolor", 0, t_notation_obj, j_accidentals_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "accidentalcolor",0,"rgba","Accidental Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"accidentalcolor",0,"0. 0. 0. 1.");
        // @exclude bach.slot
        // @description Sets the color of accidentals, in RGBA format.

        CLASS_ATTR_RGBA(c,"stemcolor", 0, t_notation_obj, j_stem_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "stemcolor",0,"rgba","Stem Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"stemcolor",0,"0. 0. 0. 1.");
        // @exclude bach.slot
        // @description Sets the color of chord stems, in RGBA format.

        CLASS_ATTR_RGBA(c,"articulationcolor", 0, t_notation_obj, j_articulations_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "articulationcolor",0,"rgba","Articulation Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"articulationcolor",0,"0. 0. 0. 1.");
        // @exclude bach.slot
        // @description Sets the color of articulations, in RGBA format.

        CLASS_ATTR_RGBA(c,"annotationcolor", 0, t_notation_obj, j_annotation_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "annotationcolor",0,"rgba","Annotation Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"annotationcolor",0,"0. 0. 0. 1.");
        // @exclude bach.slot
        // @description Sets the color of text annotations, in RGBA format.

        CLASS_ATTR_RGBA(c,"dynamicscolor", 0, t_notation_obj, j_dynamics_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "dynamicscolor",0,"rgba","Dynamics Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"dynamicscolor",0,"0. 0. 0. 1.");
        // @exclude bach.slot
        // @description Sets the color of dynamics, in RGBA format.
        
        if (obj_type == k_NOTATION_OBJECT_SCORE) {
            CLASS_ATTR_RGBA(c,"beamcolor", 0, t_notation_obj, j_beam_rgba);
            CLASS_ATTR_STYLE_LABEL(c, "beamcolor",0,"rgba","Beam Color");
            CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"beamcolor",0,"0. 0. 0. 1.");
            // @exclude bach.slot, bach.roll
            // @description Sets the color of beams.

            CLASS_ATTR_RGBA(c,"tupletcolor", 0, t_notation_obj, j_tuplet_rgba);
            CLASS_ATTR_STYLE_LABEL(c, "tupletcolor",0,"rgba","Tuplet Color");
            CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"tupletcolor",0,"0. 0. 0. 1.");
            // @exclude bach.slot, bach.roll
            // @description Sets the color of tuplet elements (numbers, brackets).

            CLASS_ATTR_RGBA(c,"flagcolor", 0, t_notation_obj, j_flag_rgba);
            CLASS_ATTR_STYLE_LABEL(c, "flagcolor",0,"rgba","Flag Color");
            CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"flagcolor",0,"0. 0. 0. 1.");
            // @exclude bach.slot, bach.roll
            // @description Sets the color of each chord flags.
            
            CLASS_ATTR_RGBA(c,"restcolor", 0, t_notation_obj, j_rest_rgba);
            CLASS_ATTR_STYLE_LABEL(c, "restcolor",0,"rgba","Rest Color");
            CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"restcolor",0,"0. 0. 0. 1.");
            // @exclude bach.slot, bach.roll
            // @description Sets the color of rests, in RGBA format.

            CLASS_ATTR_RGBA(c,"tempocolor", 0, t_notation_obj, j_tempi_rgba);
            CLASS_ATTR_STYLE_LABEL(c, "tempocolor",0,"rgba","Tempo Color");
            CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"tempocolor",0,"0. 0. 0. 1.");
            // @exclude bach.slot, bach.roll
            // @description Sets the color of tempi, in RGBA format.
        }
        
		CLASS_ATTR_RGBA(c,"clefcolor", 0, t_notation_obj, j_clef_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "clefcolor",0,"rgba","Clef Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"clefcolor",0,"0. 0. 0. 1.");
		// @exclude bach.slot
		// @description Sets the color of clefs in RGBA format. 

        CLASS_ATTR_RGBA(c,"auxclefcolor", 0, t_notation_obj, j_auxiliaryclef_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "auxclefcolor",0,"rgba","Auxiliary Clef Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"auxclefcolor",0,"0. 0. 0. 1.");
        // @exclude bach.slot
        // @description Sets the color of 15ma/15vb clefs used inside clef combinations such as <b>FFGG</b>, <b>FGG</b>, <b>FFG</b>, etc..

		CLASS_ATTR_RGBA(c,"scrollbarcolor", 0, t_notation_obj, j_scrollbar_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "scrollbarcolor",0,"rgba","Scrollbar Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"scrollbarcolor",0,"0.3 0.3 0.3 1.");
		// @exclude bach.slot
		// @description Sets the color of the scrollbars in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"playcolor", 0, t_notation_obj, j_play_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "playcolor",0,"rgba","Play Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"playcolor",0,"0.34 0.87 0.20 1.");
		// @exclude bach.slot
		// @description Sets the color corresponding to notes being played, in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"loopcolor", 0, t_notation_obj, j_loop_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "loopcolor",0,"rgba","Loop Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"loopcolor",0,"0.68 0.48 0.69 1.");
		// @exclude bach.slot
		// @description Sets the color of the loop region in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"lockcolor", 0, t_notation_obj, j_locked_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "lockcolor",0,"rgba","Lock Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"lockcolor",0,"0.83 0.04 0.04 1.");
		// @exclude bach.slot
		// @description Sets the color of locked items in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"mutecolor", 0, t_notation_obj, j_muted_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "mutecolor",0,"rgba","Mute Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"mutecolor",0,"0.29 0.29 0.72 1.");
		// @exclude bach.slot
		// @description Sets the color of muted items in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"solocolor", 0, t_notation_obj, j_solo_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "solocolor",0,"rgba","Solo Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"solocolor",0,"0.61 0.61 0.21 1.");
		// @exclude bach.slot
		// @description Sets the color of items set as "solo" in RGBA format. 
		
		if (obj_type == k_NOTATION_OBJECT_ROLL) {
			CLASS_ATTR_RGBA(c,"markercolor", 0, t_notation_obj, j_marker_rgba);
			CLASS_ATTR_STYLE_LABEL(c, "markercolor",0,"rgba", "Marker Color");
			CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"markercolor",0,"0.24 0.70 0.19 0.9");
			// @exclude bach.slot, bach.score
			// @description Sets the color of markers in RGBA format. 
		}
		
		if (obj_type == k_NOTATION_OBJECT_SCORE) {
			CLASS_ATTR_RGBA(c,"markercolor", 0, t_notation_obj, j_marker_rgba);
			CLASS_ATTR_STYLE_LABEL(c, "markercolor",0,"rgba", "Milliseconds-Attached Marker Color");
			CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"markercolor",0,"0.24 0.70 0.19 0.9");
			// @exclude bach.slot, bach.roll
			// @description Sets the color of markers attached to absolute milliseconds position in RGBA format. 

			CLASS_ATTR_RGBA(c,"measmarkercolor", 0, t_notation_obj, j_marker_attached_to_tp_rgba);
			CLASS_ATTR_STYLE_LABEL(c, "measmarkercolor",0,"rgba","Measure-Attached Marker Color");
			CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"measmarkercolor",0,"0.17 0.25 0.88 0.9");
			// @exclude bach.slot, bach.roll
			// @description Sets the color of markers attached to measure position in RGBA format. 
		}
		
		CLASS_ATTR_RGBA(c,"rulercolor", 0, t_notation_obj, j_ruler_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "rulercolor",0,"rgba","Ruler Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"rulercolor",0,"0. 0. 0. 1.");
		// @exclude bach.slot
		// @description Sets the color of the ruler in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"gridcolor", 0, t_notation_obj, j_main_grid_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "gridcolor",0,"rgba","Grid Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"gridcolor",0,"0. 0. 0. 0.3");
		// @exclude bach.slot
		// @description Sets the color of the main grid lines ("divisions") in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"subdivisiongridcolor", 0, t_notation_obj, j_subdivision_grid_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "subdivisiongridcolor",0,"rgba","Subdivision Grid Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"subdivisiongridcolor",0,"0. 0. 0. 0.1");
		// @exclude bach.slot
		// @description Sets the color of the each grid subdivision line in RGBA format. 
		
		CLASS_ATTR_RGBA(c,"lyricscolor", 0, t_notation_obj, j_lyrics_rgba);
		CLASS_ATTR_STYLE_LABEL(c, "lyricscolor",0,"rgba","Lyrics Color");
		CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"lyricscolor",0,"0. 0. 0. 1.");
		// @exclude bach.slot
		// @description Sets the color of lyrics in RGBA format. 
        
        CLASS_ATTR_RGBA_LEGACY(c,"lineareditcolor","lrgb", 0, t_notation_obj, j_linear_edit_rgba);
        CLASS_ATTR_STYLE_LABEL(c, "lineareditcolor",0,"rgba","Edit Color");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"lineareditcolor",0,"0.78 0.63 0.04 1.");
        CLASS_ATTR_CATEGORY(c, "lineareditcolor", 0, "Color");
        // @exclude bach.slot
        // @description Sets the color corresponding to linear editing mode, in RGBA format.
	}

	CLASS_STICKY_ATTR_CLEAR(c, "category");
}


void notation_class_add_appearance_attributes(t_class *c, char obj_type){
	CLASS_STICKY_ATTR(c,"category",0,"Appearance");
	
	CLASS_ATTR_DOUBLE(c, "rounded", 0, t_notation_obj, corner_roundness); 
	CLASS_ATTR_STYLE_LABEL(c,"rounded",0,"text","Roundness of Box Corners");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rounded",0,"0."); // default SHOULD BE: "6.", but only when corner clipping will perfectly work!
	CLASS_ATTR_INVISIBLE(c, "rounded", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // invisible attribute, as long as corner clipping doesn't perfectly work...
	// @exclude all

	CLASS_ATTR_CHAR(c,"showborder",0, t_notation_obj, show_border);
	CLASS_ATTR_STYLE_LABEL(c,"showborder",0,"onoff","Show Border");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showborder",0,"1");
	// @description Toggles the ability to display the object border.

    CLASS_ATTR_SYM(c,"jitmatrix",0, t_notation_obj, jit_destination_matrix);
    CLASS_ATTR_STYLE_LABEL(c,"jitmatrix",0,"text","Mirror To Jitter Matrix");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"jitmatrix",0,"");
    CLASS_ATTR_ACCESSORS(c, "jitmatrix", (method)NULL, (method)notationobj_setattr_jitmatrix);
    // @description Sets the name of a jitter matrix to which the canvas should be mirrored
    
	
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
        CLASS_ATTR_CHAR(c,"smartmarkernames",0, t_notation_obj, smart_markername_placement);
        CLASS_ATTR_STYLE_LABEL(c,"smartmarkernames",0,"onoff","Smart Marker Names Placement");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"smartmarkernames",0,"1");
        // @exclude bach.slot
        // @description Toggles the ability to display the marker names on multiple lines to avoid collisions.

        CLASS_ATTR_CHAR(c,"highlightdomain",0, t_notation_obj, highlight_domain);
        CLASS_ATTR_STYLE_LABEL(c,"highlightdomain",0,"onoff","Highlight Domain");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"highlightdomain",0,"0");
        // @exclude bach.slot
        // @description Toggles the ability to highlight the domain with the <m>selectioncolor</m>. This is useful, for instance, in order to
        // align other Max UI objects on the top of bach notation objects.
        
        CLASS_ATTR_CHAR(c,"fadedomain",0, t_notation_obj, fade_predomain);
        CLASS_ATTR_STYLE_LABEL(c,"fadedomain",0,"onoff","Fade Domain Over Clefs");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"fadedomain",0,"1");
        // @exclude bach.slot
        // @description Toggles the ability to fade the portion of the score at left of the domain, near the clefs, with a transparency gradient
        // (also see <m>highlightdomain</m>).
        
        
        CLASS_ATTR_DOUBLE(c, "additionalstartpad", 0, t_notation_obj, additional_ux_start_pad);
		CLASS_ATTR_STYLE_LABEL(c,"additionalstartpad",0,"text","Additional Start Pad");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"additionalstartpad",0,"0.");
		// @exclude bach.slot
		// @description Sets an additional left pad to the domain display start, in pixels (rescaled according to the <m>vzoom</m>), 
		// This pad is located right after each clef, before the music content starts. 
		// @copyif bach.roll BACH_DOC_ROLL_START_PAD

        
        CLASS_ATTR_CHAR(c, "enhancedstems", 0, t_notation_obj, forceround_stems_to_semiinteger);
        CLASS_ATTR_STYLE_LABEL(c,"enhancedstems",0,"onoff","Enhanced Stem Display");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"enhancedstems",0,"0");
        // @exclude bach.slot
        // @description Toggle a neater display for stems, but this means at the same time that vertical alignment of
        // synchronous notes might be less precise.
        
        
		CLASS_ATTR_LONG(c,"inset",0, t_notation_obj, j_inset_x);
		CLASS_ATTR_STYLE_LABEL(c,"inset",0,"text","Border Inset");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"inset",0,"7");
		CLASS_ATTR_ACCESSORS(c, "inset", (method)NULL, (method)notationobj_setattr_inset);
		// @exclude bach.slot
		// @description Sets the stafflines inset at left and right borders of notation object, in pixels (rescaled according to the
		// <m>vzoom</m>). Defaults to 7.

		CLASS_ATTR_DOUBLE(c, "durationlinewidth", 0, t_notation_obj, durations_line_width);
		CLASS_ATTR_STYLE_LABEL(c,"durationlinewidth",0,"text","Duration Line Width");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"durationlinewidth",0,"2.");
		// @exclude bach.slot
		// @description Sets the width of the duration lines (when displayed: see <m>showdurations</m>).
		// In case the <m>showvelocity</m> attribute handles velocities via duration line width, this width is the maximum possible
		// width (corresponding to a velocity of 127), and will be rescaled according to the note (or breakpoint) velocity.
		// Defaults to 2.

        CLASS_ATTR_DOUBLE(c, "breakpointsize", 0, t_notation_obj, breakpoints_size);
        CLASS_ATTR_STYLE_LABEL(c,"breakpointsize",0,"text","Pitch Breakpoint Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"breakpointsize",0,"3.");
        // @exclude bach.slot
        // @description Sets the size of diamond shaped breakpoints (when displayed: see <m>breakpointshavenoteheads</m>).
        
		CLASS_ATTR_CHAR(c,"nonantialiasedstafflines",0, t_notation_obj, force_non_antialiased_staff_lines);
		CLASS_ATTR_STYLE_LABEL(c,"nonantialiasedstafflines",0,"onoff","Only Non-Antialiased Staff");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"nonantialiasedstafflines",0,"1");
		CLASS_ATTR_ACCESSORS(c, "nonantialiasedstafflines", (method)NULL, (method)notationobj_setattr_nonantialiasedstaff);
		// @exclude bach.slot
		// @description Toggles the ability to force stafflines to precisely lie on pixels on the screen.
		// If this attribute is 1, the <m>vzoom</m> attribute will be snapped to the closest value allowing stafflines to be drawn
		// precisely on a pixel row. This also means that the staffline-to-staffline distance is an integer (e.g. 4 pixels). 
		// If this attribute is 0, all <m>vzoom</m> values are possible, and stafflines will be displayed
		// with any floating-point distance the <m>vzoom</m> will require.
		
		CLASS_ATTR_CHAR(c,"voicenamesalign",0, t_notation_obj, voice_names_alignment);
		CLASS_ATTR_STYLE_LABEL(c,"voicenamesalign",0,"enumindex","Voice Names Alignment");
		CLASS_ATTR_ENUMINDEX(c,"voicenamesalign", 0, "Left Center Right");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"voicenamesalign", 0, "1");
		// @exclude bach.slot
		// @description Sets the alignment for the voice names, at the beginning of the staff, with respect to all other
		// voice names. Possibilities are: "Left", "Center", "Right".
		
		CLASS_ATTR_CHAR(c,"breakpointshavenoteheads",0, t_notation_obj, breakpoints_have_noteheads);
		CLASS_ATTR_STYLE_LABEL(c,"breakpointshavenoteheads",0,"onoff","Breakpoints Have Noteheads");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"breakpointshavenoteheads",0,"0");
		// @exclude bach.slot
		// @description Toggles the ability to display pitch breakpoints as real notes (possibly with accidentals).
		// If this is not set, pitch breakpoints are displayed as small diamonds.
        
        
        CLASS_ATTR_CHAR(c, "thinannotations", 0, t_notation_obj, thinannotations);
        CLASS_ATTR_STYLE_LABEL(c,"thinannotations",0,"enumindex","Handle Annotation Duplicates");
        CLASS_ATTR_ENUMINDEX(c,"thinannotations", 0, "Keep Remove Remove With Clearing Symbol Remove With Bracket");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"thinannotations",0,"0");
        // @exclude bach.slot
        // @description Decides what to do with identical annotations put on nearby chords. <br />
        // 0 = Keeps all the annotations; <br />
        // 1 = Removes all the duplicates; <br />
        // 2 = Removes all the duplicates and puts a symbol to clear the annotation at the end
        // if no other annotation is present; <br />
        // 3 = Removes all the duplicates and puts a bracket.

        CLASS_ATTR_SYM(c, "thinannotationsclearsym", 0, t_notation_obj, annotations_clearingsym);
        CLASS_ATTR_STYLE_LABEL(c,"thinannotationsclearsym",0,"text","Annotation Clearing Symbol");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"thinannotationsclearsym",0,"ord.");
        // @exclude bach.slot
        // @description If <m>thinannotations</m> is set to 2 (Remove With Clearing Symbol), this attribute
        // sets the clearing symbol to remove the annotation label.

	}
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
}

void notation_class_add_settings_attributes(t_class *c, char obj_type){
	CLASS_STICKY_ATTR(c,"category",0,"Settings");

    /*
	CLASS_ATTR_LONG(c,"versionnumber",0, t_notation_obj, version_number);
	CLASS_ATTR_STYLE_LABEL(c,"versionnumber",0,"text","Version Number");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"versionnumber", 0, "0");
	CLASS_ATTR_INVISIBLE(c, "versionnumber", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // invisible attribute
	// @exclude all
     */

    CLASS_ATTR_LONG(c,"slopemapping",0, t_notation_obj, slope_mapping_type);
    CLASS_ATTR_STYLE_LABEL(c,"slopemapping",0,"enumindex","Slope Mapping");
    CLASS_ATTR_ENUMINDEX(c,"slopemapping", 0, "bach Max");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"slopemapping", 0, "0");
    // @description Sets the function to be used for slope mapping: either bach (default) or Max.

    
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		
		CLASS_ATTR_LONG(c, "numvoices", 0, t_notation_obj, num_voices);
		CLASS_ATTR_STYLE_LABEL(c,"numvoices",0,"text","Number Of Voices");
		CLASS_ATTR_ACCESSORS(c, "numvoices", (method)NULL, (method)notationobj_setattr_numvoices);
		CLASS_ATTR_SAVE(c, "numvoices", 0);
		CLASS_ATTR_BASIC(c,"numvoices", 0);
		// @exclude bach.slot
		// @description Sets the number of voices of the notation object.

		CLASS_ATTR_CHAR(c, "autosize", 0, t_notation_obj, autosize);
		CLASS_ATTR_STYLE_LABEL(c,"autosize",0,"onoff","Automatically Adapt Number Of Voices");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autosize", 0, "1");
		// @exclude bach.slot
		// @description Toggles the ability to automatically adapt the number of voices of the
		// notation object depending on the number of voice lllls given as input.
		
        
        CLASS_ATTR_NOTATIONOBJ_LONGPTR(c, "numparts", 0, voice_part, CONST_MAX_VOICES, notationobj_setattr_numparts);
        CLASS_ATTR_STYLE_LABEL(c,"numparts",0,"text","Number of Voices per Part");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"numparts",0,"1");
        // @exclude bach.slot
        // @description Sets the part grouping for voices, i.e. the lis.
        // Voices can be assigned to the same staff via this <m>numparts</m> attribute. If multiple voices are assigned to the
        // same staff, this staff is called a "staff ensemble".
        // In this <m>numparts</m> attribute, each integer specifies the number of voices to be displayed on the same staff (or multistaff).
        // For instance, if a score has 4 voices, assigning <m>parts</m> as <b>1 1 1 1</b>
        // means that every voice ensemble (displayed staff) has a single voice - or, in other words, that every part is separate voice.
        // If, on the other hand, one assigns <b>2 2</b> two staff ensembles are created: voices 1 and 2 are displayed on the same staff (or multistaff),
        // and the same is true for voices 3 and 4. One might even set <b>4</b>
        // to show all voices in a single staff or multistaff.
        
        
		CLASS_ATTR_CHAR(c,"notenamesstyle",0, t_notation_obj, note_names_style);
		CLASS_ATTR_STYLE_LABEL(c,"notenamesstyle",0,"enumindex","Note Names Style");
		CLASS_ATTR_ENUMINDEX(c,"notenamesstyle", 0, "Latin Anglo-Saxon");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"notenamesstyle", 0, "1");
        CLASS_ATTR_INVISIBLE(c, "notenamesstyle", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE);
        // @exclude all
		// @description Sets the style of the note names display: "Latin" corresponds to note names such as
		// "Do Re Mi Fa...", while "Anglo-Saxon" corresponds to note name such as "C D E F...".

		CLASS_ATTR_LONG(c,"middlecoctave",0, t_notation_obj, middleC_octave);
		CLASS_ATTR_STYLE_LABEL(c,"middlecoctave",0,"text","Middle C Octave");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"middlecoctave", 0, "5");
        CLASS_ATTR_INVISIBLE(c, "middlecoctave", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // deprecated and unsupported
        // @exclude all
		// @description Sets the octave number of the middle C. By default this is 5 (meaning that C5 is the middle C);
		// values of 3 and 5 are also encountered. 
		
		CLASS_ATTR_CHAR(c,"breakpointshavevelocity",0, t_notation_obj, breakpoints_have_velocity);
		CLASS_ATTR_STYLE_LABEL(c,"breakpointshavevelocity",0,"onoff","Breakpoints Have Velocity");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"breakpointshavevelocity", 0, "0");
		// @exclude bach.slot
		// @description Toggles the ability, for pitch breakpoints, to have their own independent velocity.
		
		CLASS_ATTR_NOTATIONOBJ_LONGPTR(c, "midichannels", 0, midichannels_as_longlist, CONST_MAX_VOICES, notationobj_setattr_midichannels);
		CLASS_ATTR_STYLE_LABEL(c,"midichannels",0,"text","MIDI Channels");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"midichannels",0,"1");
		// @exclude bach.slot
		// @description Sets the MIDI channels, which are a property of voices: a list with one integer for each voice is expected.
		
		CLASS_ATTR_DOUBLE(c,"gridperiodms",0, t_notation_obj, grid_step_ms);
		CLASS_ATTR_STYLE_LABEL(c,"gridperiodms",0,"text","Ruler/Grid Period (ms)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"gridperiodms",0,"1000");
		CLASS_ATTR_FILTER_MIN(c, "gridperiodms", 1.);
		// @exclude bach.slot
		// @description Sets the ruler and grid main period ("divisions"), in milliseconds. Defaults to 1000.

		CLASS_ATTR_LONG(c,"numgridsubdivisions",0, t_notation_obj, grid_subdivisions);
		CLASS_ATTR_STYLE_LABEL(c,"numgridsubdivisions",0,"text","Number of Ruler/Grid Subdivisions");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"numgridsubdivisions",0,"10");
		CLASS_ATTR_FILTER_MIN(c, "numgridsubdivisions", 1);
		// @exclude bach.slot
		// @description Sets the number of subdivisions for each ruler and grid period. Defaults to 10.
		
		CLASS_ATTR_DOUBLE(c,"lyricsvadj",0, t_notation_obj, lyrics_uy_pos);
		CLASS_ATTR_STYLE_LABEL(c,"lyricsvadj",0,"text","Lyrics Vertical Adjustment");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"lyricsvadj",0,"-16");
		// @exclude bach.slot
		// @description Sets the vertical shift (in pixels, rescaled depending on the <m>vzoom</m>) of the 
		// lyrics display. 0 will set the lyrics top line coinciding with the bottommost staff line.
		// The default is -16.

        CLASS_ATTR_DOUBLE(c,"dynamicsvadj",0, t_notation_obj, dynamics_uy_pos);
        CLASS_ATTR_STYLE_LABEL(c,"dynamicsvadj",0,"text","Dynamics Vertical Adjustment");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"dynamicsvadj",0,"-20");
        // @exclude bach.slot
        // @description Sets the vertical shift (in pixels, rescaled depending on the <m>vzoom</m>) of the
        // dynamics display. 0 will set the dynamics line coinciding with the bottommost staff line.
        // The default is -20.
        
		CLASS_ATTR_CHAR(c,"lyricsalignment",0, t_notation_obj, lyrics_alignment);
		CLASS_ATTR_STYLE_LABEL(c,"lyricsalignment",0,"enumindex","Lyrics Alignment");
		CLASS_ATTR_ENUMINDEX(c,"lyricsalignment", 0, "Auto Left Center Right");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"lyricsalignment", 0, "0");
		CLASS_ATTR_ACCESSORS(c, "lyricsalignment", (method)NULL, (method)notationobj_setattr_lyrics_alignment);
		// @exclude bach.slot
		// @description Sets how the lyrics syllables must be aligned with respect to the chord to which they refer.
		// Possibilities are: "Auto", "Left", "Center", "Right". Currently "Auto" completely coincides with "Center",
		// but it might be improved in a future version.

        CLASS_ATTR_CHAR(c,"dynamicsoutputmode",0, t_notation_obj, dynamics_output_mode);
        CLASS_ATTR_STYLE_LABEL(c,"dynamicsoutputmode",0,"enumindex","Dynamics Output Mode");
        CLASS_ATTR_ENUMINDEX(c,"dynamicsoutputmode", 0, "Plain Structured Full");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"dynamicsoutputmode", 0, "2");
        // @description Sets the way in which information in slots of type dynamics is output (N.B.: this does not affect the
        // behavior at input, since in this case all syntaxes are supported):
        // 0 = Plain: dynamics are output as a plain list. Manual positioning are obtained by
        // having dynamic markings preceded by a
        // floating point number (the relative positioning, between 0 and 1); breakpoint attachments are signaled with symbols bearing the
        // breakpoint index preceded by '@' (e.g. "@3"). This is the most humanly readable option; <br />
        // 1 = Structured: syntax is an llll containing the information structured in an llll; each dynamic marking is represented by
        // an llll, whose form depends on the attachment mode. If the marking attachment is "auto", then the form is
        // <b>[auto <m>dynamic_marking</m> <m>hairpin_to_next</m>]</b>; if the marking attachment is "manual", then the form is
        // <b>[<m>relative_position</m> <m>dynamic_marking</m> <m>hairpin_to_next</m>]</b>; if the marking attachment is "breakpoint", then
        // the form is
        // <b>[[breakpoint <m>breakpoint_index</m>] <m>dynamic_marking</m> <m>hairpin_to_next</m>]</b>.
        // This option is useful when you prefer to handle lllls, but, differently from the following one, it only bears
        // the minimum amount of information to assign the dynamics correctly (e.g.: no need for a relative position if we are attaching
        // the dynamic to a breakpoint); <br />
        // 2 = Full (default): syntax is an llll containing, but always output all the information,
        // as a sequence of dynamic markings each represented
        // by an llll in the form
        // <b>[[<m>attachment_mode</m> <m>breakpoint_attachment</m> <m>relative_position</m>] <m>dynamic_marking</m> <m>hairpin_to_next</m>]</b>.
        // If a dynamic marking is set to be attached to a breakpoint ("breakpoint" attachment mode),
        // both the breakpoint number and the relative position of the breakpoint are correctly output.
        // If the attachment mode is "manual" or "auto", then <m>breakpoint_attachment</m> is meaningless (and left to 0),
        // but in both cases the <m>relative_position</m> is correct.

	}
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
}

void notation_class_add_play_attributes(t_class *c, char obj_type){
	
	CLASS_STICKY_ATTR(c,"category",0,"Play");

	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		
		CLASS_ATTR_CHAR(c,"spacebarplay",0, t_notation_obj, allow_play_from_interface);
		CLASS_ATTR_STYLE_LABEL(c,"spacebarplay",0,"onoff","Use Spacebar To Play");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"spacebarplay", 0, "1");	
		// @exclude bach.slot
		// @description Toggles the ability to sequence events via the spacebar (see <m>keyboard</m> commands).

		CLASS_ATTR_LONG(c,"playpollthrottle",0, t_notation_obj, max_num_chord_per_scheduler_event);
		CLASS_ATTR_STYLE_LABEL(c,"playpollthrottle",0,"text","Play Poll Throttle");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playpollthrottle",0,"10");
		CLASS_ATTR_FILTER_MIN(c, "playpollthrottle", 1);
		// @exclude bach.slot
		// @description Maximum number of synchronous notation items being output within the same scheduler event.
        // Chords count as singles notation items (so if you have a chord with a large number of notes, this will still count as 1 notation item.


		CLASS_ATTR_DOUBLE(c,"playstep",0, t_notation_obj, theoretical_play_step_ms);
		CLASS_ATTR_STYLE_LABEL(c,"playstep",0,"text","Play Bar Average Step (ms)");
		CLASS_ATTR_DEFAULT_SAVE(c,"playstep",0,"50");
		// @exclude bach.slot
		// @description Approximative step (in milliseconds) for playhead (and notation object) redraw. 
		// 0 means that the score is redrawn at each scheduled event. 
		// The "approximative" adjective is due to the fact that we need an integer number of ticks 
		// between two scheduled events (e.g.: two subsequent chord onsets), so this might slightly 
		// vary in each scheduled interval

    
        CLASS_ATTR_CHAR(c,"catchplay", 0, t_notation_obj, catch_playhead);
        CLASS_ATTR_STYLE_LABEL(c,"catchplay",0,"onoff","Catch Play Head");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"catchplay", 0, "1");
        // @exclude bach.slot
        // @description Toggles the ability to follow the playhead in the domain during playback.
        
        
		CLASS_ATTR_CHAR(c,"playmode", 0, t_notation_obj, play_mode);
		CLASS_ATTR_STYLE_LABEL(c,"playmode",0,"enumindex","Playout Mode");
		CLASS_ATTR_ENUMINDEX(c,"playmode", 0, "Chordwise Notewise");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playmode", 0, "1");
		// @exclude bach.slot
		// @description Sets the syntax of the content output from the playout: either a chordwise playout syntax,
		// or a notewise playout syntax (default). <br />
		// @copyif bach.roll BACH_DOC_PLAYOUT_SYNTAX_ROLL
		// @copyif bach.score BACH_DOC_PLAYOUT_SYNTAX_SCORE


		CLASS_ATTR_CHAR(c,"playrests", 0, t_notation_obj, play_rests);
		CLASS_ATTR_STYLE_LABEL(c,"playrests",0,"onoff","Play Rests");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playrests", 0, "0");
		// @exclude bach.slot
		// @description Toggles the ability to also play rests, having <b>rest</b> as symbol router for the playout llll. 
		// @copyif bach.roll BACH_DOC_PLAYOUT_SYNTAX_ROLL
		// @copyif bach.score BACH_DOC_PLAYOUT_SYNTAX_SCORE

		
		CLASS_ATTR_CHAR(c,"playpartialnotes",0, t_notation_obj, play_partial_notes);
		CLASS_ATTR_STYLE_LABEL(c,"playpartialnotes",0,"enumindex","Play Partial Notes");
        CLASS_ATTR_ENUMINDEX(c,"playpartialnotes", 0, "Don't Quietly Verbosely");
		CLASS_ATTR_FILTER_CLIP(c, "playpartialnotes", 0, 2);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playpartialnotes", 0, "1");
		// @exclude bach.slot
		// @description Toggle the ability to play partial notes, when the playhead starts from a point where a note has
		// already started but not yet ended. In this case, all temporal information (temporal slots, pitch breakpoints)
		// is properly trimmed, and the corresponding partial note is played.
		// By default this is 1 (quiet playing); if you set the attribute to 2 (verbosely), instead of the onset a
        // llll in the form <b>[partial <m>original_onset</m> <m>played_onset</m> <m>offset</m>]</b> is output.

		CLASS_ATTR_CHAR(c,"highlightplay",0, t_notation_obj, highlight_played_notes);
		CLASS_ATTR_STYLE_LABEL(c,"highlightplay",0,"onoff","Highlight Played Notes");
		CLASS_ATTR_DEFAULT_SAVE(c,"highlightplay",0,"0");
		CLASS_ATTR_ACCESSORS(c, "highlightplay", (method)NULL, (method)notationobj_setattr_highlightplay);
		// @exclude bach.slot
		// @description Toggle the ability to highlight the played notes with the <m>playcolor</m>.
        // By default this is 0; if you turn it on be aware that it takes significant CPU time with scores with many notes.
		
		CLASS_ATTR_CHAR(c,"playmarkers",0, t_notation_obj, play_markers);
		CLASS_ATTR_STYLE_LABEL(c,"playmarkers",0,"onoff","Play Markers");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playmarkers", 0, "1");
		// @exclude bach.slot
		// @description Toggle the ability to also send the marker information through the playout during the playback.
		// By default this is 1.

		CLASS_ATTR_CHAR(c,"useloop",0, t_notation_obj, use_loop_region);
		CLASS_ATTR_STYLE_LABEL(c,"useloop",0,"onoff","Activate Loop Region (When Shown)");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"useloop", 0, "1");
		CLASS_ATTR_ACCESSORS(c, "useloop", (method)NULL, (method)notationobj_setattr_useloop);
		// @exclude bach.slot
		// @description Toggle the ability to use the loop region during the playback, if such region is shown (see the
		// <m>showloop</m> attribute). If this is 1, and the loop region is shown, the playback will loop inside the region;
		// otherwise, even if the loop region is shown, the playback will continue linearly, without looping. By default this is 1.
		

		CLASS_ATTR_CHAR(c,"playoutfullpath",0, t_notation_obj, full_path_from_playout_syntax);
		CLASS_ATTR_STYLE_LABEL(c,"playoutfullpath",0,"onoff","Full Path In Playout Syntax");
		CLASS_ATTR_FILTER_CLIP(c, "playoutfullpath", 0, 1);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playoutfullpath", 0, "0");
		// @exclude bach.slot
		// @description Toggle the ability to output from the playout, instead of the voice number, the full path
		// to get to the played element. 
		// The playout syntax normally has as first element the voice number of the output item (note or chord).
		// By default this attribute is 0, and the simple voice number is output as first element. <br />
		// If this flag is active, for <o>bach.roll</o>, the voice number is substituted with the list
		// <b>[<m>voice_number</m> <m>chord_index</m>]</b>, if the <m>playmode</m> is chord-wise, or 
		// <b>[<m>voice_number</m> <m>chord_index</m> <m>note_index</m>]</b>, if the <m>playmode</m> is note-wise.
		// The <m>chord_index</m> is the index of the chord, when ordered by onsets. The <m>note_index</m> is the
		// index of the note (from the lowest to highest one).
		// For instance, instead of <b>note 1 1 [...]</b> one might have <b>note [1 4 2] 1 [...]</b>, meaning that
		// the output information concerns the 2nd note of 4th chord of 1st voice. 
		// Voice is anyway always the first element in the output llll. <br />
		// If this flag is active, for <o>bach.score</o>, the voice number is substituted with a list of lists, namely
		// <b>[<m>LIST1</m> <m>LIST2</m>...]</b>. The slightly complex form is due to the fact that
		// tied notes or chords are output just once for all from the playout, so that each output element
		// may be a combination of subsequently tied notes or chords. Each one of the <m>LIST</m>s represents one of these elements,
		// and has the form
		// <b>[<m>voice_number</m> <m>measure_number</m> <m>chord_index</m>]</b>, if the <m>playmode</m> is chord-wise, or 
		// <b>[<m>voice_number</m> <m>measure_number</m> <m>chord_index</m> <m>note_index</m>]</b>, if the <m>playmode</m> is note-wise.
		// The <m>chord_index</m> is the index of the chord inside the measure. The <m>note_index</m> is the
		// index of the note (from the lowest to highest one).
		// For instance, instead of <b>note 1 1 [...]</b> one might have <b>note [[1 3 4 2] [1 4 1 3]] 1 [...]</b>,
		// meaning that the output information concerns two notes: the 2nd note of 4th chord of 3rd measure of 1st voice, 
		// which is tied to the 3rd note of 1st chord of 4th measure of 1st voice.
		// Voice is anyway always the first element in the output llll. <br />
		

        CLASS_ATTR_CHAR(c, "playwhenlinearediting", 0, t_notation_obj, playback_during_linear_editing);
        CLASS_ATTR_STYLE_LABEL(c,"playwhenlinearediting",0,"onoff","Chord Playback While Linear Editing");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playwhenlinearediting", 0,"1");
        // @exclude bach.slot
        // @description Toggles the ability to output chords from the playout, while they are being inserted in the linear editing system.
        

	}
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
}


void notation_class_add_notification_attributes(t_class *c, char obj_type)
{
    CLASS_STICKY_ATTR(c,"category",0,"Notification");
    
    CLASS_ATTR_CHAR(c,"notifycontinuously",0, t_notation_obj, continuously_output_changed_bang);
    CLASS_ATTR_STYLE_LABEL(c,"notifycontinuously",0,"onoff","Notify Continuously");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"notifycontinuously",0,"0");
    // @description Toggles the ability to notify continuously via the last outlet
    // while the mouse is down and dragging something. Also the <m>automessage</m>, if any, is sent continuously.
    // This defaults to 0.
    
    CLASS_ATTR_CHAR(c,"notifymessages",0, t_notation_obj, notify_also_upon_messages);
    CLASS_ATTR_STYLE_LABEL(c,"notifymessages",0,"onoff","Notifications When Changed Via Messages");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"notifymessages", 0, "0");
    // @description Toggles the ability to send notifications caused by actions coming from messages, and not only from the interface.
    // For instance, a <m>inscreenpos</m> message will toggle a <m>domain</m> notification, and so on.
    // By default this is inactive.
    
    CLASS_ATTR_CHAR(c,"notifypaint",0, t_notation_obj, notify_when_painted);
    CLASS_ATTR_STYLE_LABEL(c,"notifypaint",0,"onoff","Notifications When Display Is Refreshed");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"notifypaint", 0, "0");
    // @description Toggles the ability to send a notification (in the form of the "painted" symbol) from the playout
    // whenever the object display is refreshed (repainted). Beware: this could be CPU consuming.
    
    CLASS_ATTR_CHAR(c,"notifywith",0, t_notation_obj, notify_with);
    CLASS_ATTR_STYLE_LABEL(c,"notifywith",0,"enumindex","Notify Interface Changes Via");
    CLASS_ATTR_ENUMINDEX(c,"notifywith", 0, "bang Operation Redo Data Undo Data");
    CLASS_ATTR_FILTER_CLIP(c, "notifywith", 0, 3);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"notifywith", 0, "0");
    // @description Chooses the notification type for interface changes: <br />
    // - 0 (bang, default): the simplest and less CPU-consuming alternative, only notifies with a bang when anything changes; <br />
    // - 1 (Operation): notify with an operation label; <br />
    // - 2 (Redo Data): notify verbosely with the operation label plus a sequence of redo data, sufficient to recreate the operation; <br />
    // - 3 (Undo Data): the same as 2, but providing undo data instead.

    
    CLASS_ATTR_CHAR(c,"senddoneatstartup",0, t_notation_obj, send_rebuild_done_at_startup);
    CLASS_ATTR_STYLE_LABEL(c,"senddoneatstartup",0,"onoff","Send 'Done' At Startup (If Data Was Saved)");
    CLASS_ATTR_FILTER_CLIP(c, "senddoneatstartup", 0, 1);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"senddoneatstartup", 0, "1");
    // @description Toggles the ability to send a <m>done</m> notification through the playout (or the notification outlet
    // for <o>bach.slot</o>) at the object instantiation, if content saved with the object is loaded.
    
    CLASS_ATTR_CHAR(c,"senddoneafterpaint",0, t_notation_obj, send_rebuild_done_only_after_paint_method);
    CLASS_ATTR_STYLE_LABEL(c,"senddoneafterpaint",0,"onoff","Send 'Done' Only After Paint");
    CLASS_ATTR_FILTER_CLIP(c, "senddoneafterpaint", 0, 1);
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"senddoneafterpaint", 0, "1");
    // @description If this is 1, the <m>done</m> notification is not sent when the content has been loaded or built,
    // but after the content has been painted (which, in general, is later: paint is done at low priority). This is handy
    // if you need to retrieve appearance data (such as pixel position) which is computed inside the paint method, and not
    // when the object is loaded. If this is 0, on the other hand, the notification is sent right after the content has been loaded
    // or built, and you have no guarantee that the display data will be correct when the notification is sent.
    // By default this is 1.

    CLASS_STICKY_ATTR_CLEAR(c, "category");
}

void notation_class_add_behavior_attributes(t_class *c, char obj_type){
	
	CLASS_STICKY_ATTR(c,"category",0,"Behavior");
	
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		CLASS_ATTR_CHAR(c,"autoclear",0, t_notation_obj, autoclear);
		CLASS_ATTR_STYLE_LABEL(c,"autoclear",0,"onoff","Autoclear");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autoclear",0,"1");
		// @exclude bach.slot
		// @description Toggles the ability to clear the notation object automatically when a new
		// separate syntax information is entered, and a bang is sent through the first inlet.
		// This defaults to 1.
	}

	CLASS_ATTR_ATOM_VARSIZE(c,"automessage",0, t_notation_obj, automessage_av, automessage_ac, 100);
	CLASS_ATTR_STYLE_LABEL(c,"automessage",0,"text","Automatically Send Message When Changed");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"automessage",0,"");
	// @description Sets a message which is sent automatically to the notation object 
	// each time any change happens in the interface (right after the bang is sent through the last outlet).
	// Use this with caution, since it creates a sort of hidden feedback connection!
	
    CLASS_ATTR_CHAR(c, "mousehover", 0, t_notation_obj, mouse_hover);
    CLASS_ATTR_STYLE_LABEL(c,"mousehover",0,"onoff","Allow Mouse Hovering");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mousehover",0,"1");
    // @description Toggles mouse hovering capabilities.

	
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		CLASS_ATTR_CHAR(c,"allowglissandi",0, t_notation_obj, allow_glissandi);
		CLASS_ATTR_STYLE_LABEL(c,"allowglissandi",0,"onoff","Allow Glissando Breakpoints");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"allowglissandi",0,"1");
		// @exclude bach.slot
		// @description Toggles the possibility, for duration lines, to have pitch breakpoints, creating glissando-like behaviors. 
		// If this is hidden, all breakpoints are not displayed.
		// This defaults to 1.
		
		CLASS_ATTR_CHAR(c,"dblclicksendsvalues",0, t_notation_obj, dblclick_sends_values);
		CLASS_ATTR_STYLE_LABEL(c,"dblclicksendsvalues",0,"onoff","Send Selection Upon Double-Click");
		CLASS_ATTR_DEFAULT_SAVE(c,"dblclicksendsvalues",0,"0");
		// @exclude bach.slot
		// @description Toggles the ability to individually off-line dump any note or marker by doubleclicking on it.
		// This defaults to 0.
	}
    
	
	CLASS_ATTR_CHAR(c,"embed",0, t_notation_obj, save_data_with_patcher);
	CLASS_ATTR_STYLE_LABEL(c,"embed",0,"onoff","Save Data With Patcher");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"embed",0,"1");
	CLASS_ATTR_BASIC(c,"embed", 0);
	// @description Toggles the ability to save the notation object content within the patch.
	// By default this is active.
    
    
    CLASS_ATTR_LONG(c,"bwcompatibility",0, t_notation_obj, bwcompatible);
    CLASS_ATTR_STYLE_LABEL(c,"bwcompatibility",0,"text","Backwards Compatible To");
    CLASS_ATTR_SAVE(c, "bwcompatibility", 0);
    CLASS_ATTR_INVISIBLE(c, "bwcompatibility", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // invisible attribute, undocumented for now
    // @exclude all
    // @description Toggles backwards compatibility for saving (whenever possible) till the indicated
    // version of bach. Versions x.y.z.w are to be inserted as the number xyzw0. For instance, 0.7.2 is
    // 7200, while 0.7.8.1 is 7810.
    
    
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		CLASS_ATTR_CHAR(c,"keepselectioniflostfocus",0, t_notation_obj, keep_selection_if_lost_focus);
		CLASS_ATTR_STYLE_LABEL(c,"keepselectioniflostfocus",0,"onoff","Keep Selection If Lost Focus");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"keepselectioniflostfocus",0,"1");
		// @exclude bach.slot
		// @description Toggles the ability to keep the current selection when the object lose the focus.
		// This defaults to 1.
	}
	
		
	if (obj_type == k_NOTATION_OBJECT_ROLL) {
		CLASS_ATTR_CHAR(c,"rulermode",0, t_notation_obj, ruler_mode);
		CLASS_ATTR_ENUMINDEX(c,"rulermode", 0, "Fixed Smart");
		CLASS_ATTR_STYLE_LABEL(c,"rulermode",0,"enumindex","Ruler/Grid Mode");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rulermode",0,"1");
		CLASS_ATTR_ACCESSORS(c, "rulermode", (method)NULL, (method)notationobj_setattr_rulermode);
		// @description Sets the ruler mode: either a "fixed" mode, where division and subdivisions are fixed independently from 
		// the horizontal zoom, or a "smart" mode, where divisions and subdivisions are automatically computed depending on the
		// current level of horizontal zoom. 
		// @exclude bach.slot, bach.score
	}
	

	CLASS_STICKY_ATTR_CLEAR(c, "category");
}

void notation_class_add_edit_attributes(t_class *c, char obj_type){
	
	CLASS_STICKY_ATTR(c,"category",0,"Edit");

	CLASS_ATTR_ATOM(c,"maxundosteps",0, t_notation_obj, max_undo_steps);
	CLASS_ATTR_STYLE_LABEL(c,"maxundosteps",0,"text","Maximum Number Of Undo Steps");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxundosteps", 0, "50");	
	CLASS_ATTR_ACCESSORS(c, "maxundosteps", (method)NULL, (method)notationobj_setattr_maxundosteps);
	// @description Sets the maximum number of undo steps. 0 means that undo/redo system will be made inactive.
	// The "inf" symbol means unlimited undo steps.
	// Defaults to 50. You should change it to 0 if you perform heavy operations in real-time.

	CLASS_ATTR_CHAR(c,"verboseundo",0, t_notation_obj, verbose_undo_redo);
	CLASS_ATTR_STYLE_LABEL(c,"verboseundo",0,"onoff","Post Undo/Redo Steps");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"verboseundo", 0, "0");
	// @description Toggles the ability of undo system to post the performed undo or redo steps in the Max window. 
	// By default this is inactive.

	CLASS_ATTR_CHAR(c,"undobang",0, t_notation_obj, send_undo_redo_bang);
	CLASS_ATTR_STYLE_LABEL(c,"undobang",0,"onoff","Send bang Upon Undo");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"undobang", 0, "1");
	// @description Toggles the ability of send the bang through the rightmost outlet when an undo/redo action is performed.
	
    CLASS_ATTR_NOTATIONOBJ_ATOMPTR(c, "preventedit", 0, prevent_editing_atom, CONST_MAX_BACH_ELEMENT_TYPES + 10, notationobj_setattr_preventedit);
    CLASS_ATTR_STYLE_LABEL(c,"preventedit",0,"text","Prevent Editing For");
    CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"preventedit",0,"");
    // @description Prevents the interface editing of the specified elements, specified via an llll. Somehow, this is a lock specified globally for given notation items or features.
    // If the first symbol is a "-" (minus), the editing is prevented for any element or feature, except for the specified ones. <br />
    // The llll must contain at its root level: <br />
    // - either single symbols, with the items or features names to be completely "locked", e.g. <b>preventedit measure lyrics inspector</b> will prevent the editing of all measures
    // (one cannot create, delete, modify them), lyrics, and will not allow the opening of the bach inspector; <br />
    // - or lllls in the form <b>[<m>item_or_feature_name</m> <m>property1</m> <m>property2</m> <m>property3</m>...]</b>, where properties are symbols which restrict the locking
    // only to a given aspect of the item or feature. For instance, <b>preventedit [measure create delete] [marker onset]</b> will prevent the creation and deletion of measures
    // (but not their modification!), and will also prevent the movement of existing markers (but not the creation of new ones!). <br/>
    // The two approaches. <br />
    // Here is the complete list of symbols which can be used to define items and feature names; parentheses list symbols for the single properties which one can block for them: <br />
    // notes (create, delete, onset, duration, pitch, velocity, modify), measures (create, delete, rhythmictree, modify), voice (create, delete, name, clef, key, position, modify),
    // breakpoints (create, delete, onset, pitch, velocity, modify), tempi (create, delete, modify), slots, markers (create, delete, onset, name, modify), articulations (create, delete),
    // selection, zooming, dilationrectangle, groups, inspector, popup, slotinfo, lyrics, cursor, loop, scrollbar, drop. <br />
    // The "modify" symbol only refers to modification different from the previously defined ones. For instance: <b>preventedit [breakpoints modify]</b> will not
    // prevent the modification of breakpoints onsets, but will, as an example, prevent the modification of breakpoints slopes. Use <b>preventedit [breakpoints onset modify]</b> to do both.
    
    if (obj_type != k_NOTATION_OBJECT_SLOT) {
		CLASS_ATTR_LLLL(c, "pitcheditrange", 0, t_notation_obj, constraint_pitches_when_editing, notationobj_getattr_pitcheditrange, notationobj_setattr_pitcheditrange);
		CLASS_ATTR_STYLE_LABEL(c,"pitcheditrange",0,"text_large","Constraint Pitches While Editing");
		CLASS_ATTR_SAVE(c, "pitcheditrange", 0);
		CLASS_ATTR_PAINT(c, "pitcheditrange", 0);
		// @exclude bach.slot
		// @description Force edited pitches to lie in a given range, given by the specified llll. 
		// One sublist for each voice is expected. For any given voice, the sublist must be in one of the following forms: <br />
		// - a plain llll specifies a list of allowed midicents, e.g. <b>[6000 6200 6400 6500 6700 6900 7100 7200]</b> will
		// force edited notes to lie in the C major scale in middle octave; <br/>
		// - a two-elements wrapped llll specifies a range of allowed midicents, e.g. <b>[[6000 7200]]</b> will do the same as above, but will also
		// allow notes in principle to have any microtonal value such as 6050;<br/>
		// - you can combine the two syntaxes to have the general one. For instance <b>[3600 4800 [6000 7200] 8400 9600]]</b> will 
		// force pitches to be in one of the specified C's or in the middle octave.<br/>
		// Such list must be given for any voice. Use a <b>nil</b> or <b>[]</b> list to allow all possibilities for a voice.
		// For instance: <b>pitchededitrange [7100] [[6000 7200]] []</b> will force first voice's edited notes to snap to 7100 mc (and no other note can be inserted or edited!),
		// second voice's edited notes to lie in middle octave, and third voice's edited notes to assume any available pitch. <br />
		// Note names (in latin or anglo-saxon syntax) can always be used instead of midicents.

		CLASS_ATTR_CHAR(c,"playheaddragmode",0, t_notation_obj, playhead_dragging_mode);
		CLASS_ATTR_STYLE_LABEL(c,"playheaddragmode",0,"enumindex","Playhead Mousing Mode");
		CLASS_ATTR_ENUMINDEX(c,"playheaddragmode", 0, "Absolute Relative");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"playheaddragmode", 0, "0");	
		// @exclude bach.slot
		// @description Sets the way the playhead bar responds to mouse clicks. In Relative mode, the playhead keeps its relative
		// position when one clicks - moving the mouse will shift the playhead to higher or lower temporal points in relation to the
		// relative position. In Absolute mode (default), the playhead will automatically jump directly on the clicked location.
		
		CLASS_ATTR_CHAR(c,"snappitch",0, t_notation_obj, snap_pitch_to_grid_when_editing);
		CLASS_ATTR_STYLE_LABEL(c,"snappitch",0,"onoff","Snap Pitch To Grid When Editing");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"snappitch",0,"1");
		CLASS_ATTR_ALIAS(c, "snappitch", "snappitchtogridondrag");
		CLASS_ATTR_ALIAS(c, "snappitch", "snappitchtogridwhenediting");
		// @exclude bach.slot
		// @description Toggles the ability to precisely snap the midicents of each edited note to the current
		// microtonal grid. If this is active, not only the display but also the midicent values of the edited notes can only be
		// one of the elements of the chosen temperament (see the <m>tonedivision</m> to know more about microtonal grids and temperaments).
		// By default this is active.
		
		if (obj_type == k_NOTATION_OBJECT_ROLL) {
			CLASS_ATTR_CHAR(c,"snaponset",0, t_notation_obj, snap_onset_to_grid_when_editing);
			CLASS_ATTR_STYLE_LABEL(c,"snaponset",0,"onoff","Snap Onset To Grid When Editing");
			CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"snaponset",0,"0");
			// @exclude bach.slot, bach.score
			// @description Toggles the ability to automatically snap the onset of the edited chords and notes to the displayed grid
			// (if any). By default this is off. When it is on, one can press the <m>Ctrl</m> key (mac) or <m>Shift+Ctrl</m> key (win)
            // before releasing the mouse button in order to prevent snapping.

            CLASS_ATTR_CHAR(c,"snaptail",0, t_notation_obj, snap_tail_to_grid_when_editing);
			CLASS_ATTR_STYLE_LABEL(c,"snaptail",0,"onoff","Snap Tail To Grid When Editing");
			CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"snaptail",0,"0");
			// @exclude bach.slot, bach.score
			// @description Toggles the ability to automatically snap the tails of the edited chords and notes to the displayed grid
            // (if any). By default this is off. When it is on, one can press the <m>Ctrl</m> key (mac) or <m>Shift+Ctrl</m> key (win)
            // before releasing the mouse button in order to prevent snapping.

            CLASS_ATTR_CHAR(c,"snaplinearedit",0, t_notation_obj, snap_linear_edit_to_grid_when_editing);
            CLASS_ATTR_STYLE_LABEL(c,"snaplinearedit",0,"onoff","Snap Linear Editing To Grid");
            CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"snaplinearedit",0,"1");
            // @exclude bach.slot, bach.score
            // @description Toggles the ability to automatically snap linear editing to the displayed grid
            // (if any). By default this is on.
            
            CLASS_ATTR_CHAR(c,"snapmarkers",0, t_notation_obj, snap_markers_to_grid_when_editing);
            CLASS_ATTR_STYLE_LABEL(c,"snapmarkers",0,"onoff","Snap Markers To Grid When Editing");
            CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"snapmarkers",0,"0");
            // @exclude bach.slot, bach.score
            // @description Toggles the ability to automatically snap the markers to the displayed grid
            // (if any). By default this is off. When it is on, one can press the <m>Ctrl</m> key (mac) or <m>Shift+Ctrl</m> key (win)
            // before releasing the mouse button in order to prevent snapping.

        }
		
		CLASS_ATTR_CHAR(c,"allowmute",0, t_notation_obj, allow_mute);
		CLASS_ATTR_STYLE_LABEL(c,"allowmute",0,"onoff","Allow Mute");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"allowmute", 0, "1");	
		// @exclude bach.slot
		// @description Toggles the ability to mute notation items.
		
		CLASS_ATTR_CHAR(c,"allowsolo",0, t_notation_obj, allow_solo);
		CLASS_ATTR_STYLE_LABEL(c,"allowsolo",0,"onoff","Allow Solo");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"allowsolo", 0, "1");	
		// @exclude bach.slot
		// @description Toggles the ability to set notation items as "solo".
		
		CLASS_ATTR_CHAR(c,"allowlock",0, t_notation_obj, allow_lock);
		CLASS_ATTR_STYLE_LABEL(c,"allowlock",0,"onoff","Allow Lock");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"allowlock", 0, "1");	
		// @exclude bach.slot
		// @description Toggles the ability to lock notation items.
        
        
        
        CLASS_ATTR_CHAR(c,"defaultvelocity",0, t_notation_obj, default_velocity);
        CLASS_ATTR_STYLE_LABEL(c,"defaultvelocity",0,"text","Default Velocity");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"defaultvelocity", 0, "100");
        CLASS_ATTR_FILTER_CLIP(c, "defaultvelocity", CONST_MIN_VELOCITY, CONST_MAX_VELOCITY)
        // @exclude bach.slot
        // @description Sets the default velocity for a newly created note.
        // This only applies to notes created via mouse and keyboard.

        
        CLASS_ATTR_SYM(c,"defaultmarkername",0, t_notation_obj, default_markername);
        CLASS_ATTR_STYLE_LABEL(c,"defaultmarkername",0,"text","Default Marker Name");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"defaultmarkername", 0, "marker");
        // @exclude bach.slot
        // @description Sets the default name for a newly created marker (by default it is "marker").
        // Although names in bach can be general lllls, the default name must be a simple single symbol.
        // Marker will be then incrementally numbered starting from this default name.
        
        CLASS_ATTR_LLLL(c, "defaultnoteslots", 0, t_notation_obj, default_noteslots, notationobj_getattr_defaultnoteslots, notationobj_setattr_defaultnoteslots);
        CLASS_ATTR_STYLE_LABEL(c,"defaultnoteslots",0,"text","Default Note Slots");
        CLASS_ATTR_SAVE(c, "defaultnoteslots", 0);
        CLASS_ATTR_PAINT(c, "defaultnoteslots", 0);
        // @exclude bach.slot
        // @description Sets the default slots for a newly created note (in the standard slot syntax).
        // This only applies to notes created via mouse and keyboard.

        CLASS_ATTR_CHAR(c,"linearedit",0, t_notation_obj, allow_linear_edit);
        CLASS_ATTR_STYLE_LABEL(c,"linearedit",0,"onoff","Allow Linear Editing");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linearedit", 0, "1");
        // @exclude bach.slot
        // @description Toggles the ability to allow entering in the linear editing mode via <m>Ctrl</m>+clicking (mac)
        // or <m>Shift</m>+<m>Ctrl</m>+clicking (win) on the staff.

        CLASS_ATTR_CHAR(c, "autojump", 0, t_notation_obj, auto_jump_to_next_chord);
        CLASS_ATTR_STYLE_LABEL(c,"autojump",0,"onoff","Auto Jump To Next Chord While Linear Editing");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autojump", 0,"1");
        // @exclude bach.slot
        // @description Toggles the ability to automatically jump to the next chord, while adding or modifying chords in the linear editing system.
        
        
        if (obj_type == k_NOTATION_OBJECT_ROLL) {
            CLASS_ATTR_DOUBLE(c, "linearedittimestep", 0, t_notation_obj, linear_edit_time_step);
            CLASS_ATTR_STYLE_LABEL(c,"linearedittimestep",0,"text","Linear Editing Base Time Step");
            CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linearedittimestep", 0,"100");
            // @exclude bach.slot, bach.score
            // @description In linear editing, sets the base time step in milliseconds
            // (corresponding by default to the duration associated with the key '1' and to the
            // cursor time shifting obtained by using the left/right keyboard arrows).

            CLASS_ATTR_DOUBLE_ARRAY(c, "linearedittimemultipliers", 0, t_notation_obj, linear_edit_time_multipliers, 10);
            CLASS_ATTR_STYLE_LABEL(c,"linearedittimemultipliers",0,"text","Linear Editing Time Multipliers");
            CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"linearedittimemultipliers", 0,"1 2 3 4 5 6 7 8 9 10");
            // @exclude bach.slot, bach.score
            // @description In linear editing, sets the array of 10 multipliers which will be assigned to keys 1 through 9 plus 0 (meaning 10), and which will be
            // multiplied by the <m>linearedittimestep</m> in order to obtain the duration of a newly created note.
        }
        
        
        CLASS_ATTR_LONG(c,"activepart",0, t_notation_obj, active_part);
        CLASS_ATTR_STYLE_LABEL(c,"activepart",0,"text","Active Part");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"activepart", 0, "1");
        // @exclude bach.slot
        // @description Sets the active part number for editing (in case of voice ensembles displaying multiple parts at once, see the <m>part</m> attribute).

    }

	CLASS_ATTR_CHAR(c,"allowcopypaste",0, t_notation_obj, allow_copy_paste);
	CLASS_ATTR_STYLE_LABEL(c,"allowcopypaste",0,"onoff","Allow Copy/Paste");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"allowcopypaste", 0, "1");	
	// @description Toggles the ability to copy and paste data via the interface copy/paste commands.

    
	CLASS_STICKY_ATTR_CLEAR(c, "category");
}

void notation_class_add_showhide_attributes(t_class *c, char obj_type){
	CLASS_STICKY_ATTR(c,"category",0,"Show");
	
	CLASS_ATTR_CHAR(c,"showfocus",0, t_notation_obj, show_focus);
	CLASS_ATTR_STYLE_LABEL(c,"showfocus",0,"onoff","Show Object Focus");
	CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showfocus", 0, "1");
	// @description Toggles the display of a thicker border when the notation object has the focus. 
	
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		CLASS_ATTR_CHAR(c, "showvelocity", 0, t_notation_obj, velocity_handling);
		CLASS_ATTR_STYLE_LABEL(c,"showvelocity",0,"enumindex","Show Velocity");
		CLASS_ATTR_ENUMINDEX(c,"showvelocity", 0, "None Colorscale Colorspectrum Alpha Duration Line Width Note Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showvelocity",0,"0");
		CLASS_ATTR_ACCESSORS(c, "showvelocity", (method)NULL, (method)notationobj_setattr_showvelocity);
		CLASS_ATTR_BASIC(c,"showvelocity", 0);
		// @exclude bach.slot
		// @description Chooses the way in which velocities should be displayed: <br />
		// - None (default): velocities are simply not displayed in any way. <br />
		// - Colorscale: velocities are mapped on a color scale ranging from almost white (velocity = 1) to the ordinary <m>notecolor</m> (velocity 127). <br />
		// - Colorspectrum: velocities are mapped on a spectrum of colors ranging from red (velocity = 1) to blue (velocity = 127). <br />
		// - Alpha: velocities are mapped on a the transparency (alpha) channel, from 0 (velocity = 1, fully transparent) to 1 (velocity = 127, fully opaque). <br />
		// - Duration Line Width: velocities are mapped on the width of the duration line, from almost 0 (velocity = 1, extremely thin) to the width defined 
		// via the attribute <m>durationlinewidth</m> (velocity = 127, maximum thickness). <br />
		// - Notehead Size: velocities are mapped on the size of the notehead and accidentals, from the smallest size (velocity = 1) to the ordinary size (velocity = 127).
		
		CLASS_ATTR_CHAR(c,"showdurations",0, t_notation_obj, show_durations);
		CLASS_ATTR_STYLE_LABEL(c,"showdurations",0,"onoff","Show Duration Lines");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showdurations",0, obj_type == k_NOTATION_OBJECT_ROLL ? "1" : "0");
        CLASS_ATTR_BASIC(c,"showdurations", 0);
		// @exclude bach.slot
		// @description Toggles the display of the duration lines.

		CLASS_ATTR_CHAR(c,"showtails",0, t_notation_obj, show_tails);
		CLASS_ATTR_STYLE_LABEL(c,"showtails",0,"onoff","Show Note Tails");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showtails",0, "1");
		// @exclude bach.slot
		// @description Toggles the display to display the note tails (this only works if <m>showdurations</m> is active.
		
		CLASS_ATTR_CHAR(c,"showvoicenames",0, t_notation_obj, show_voice_names);
		CLASS_ATTR_STYLE_LABEL(c,"showvoicenames",0,"onoff","Show Voice Names");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showvoicenames",0, "1");
		CLASS_ATTR_ACCESSORS(c, "showvoicenames", (method)NULL, (method)notationobj_setattr_show_voicenames);
		// @exclude bach.slot
		// @description Toggles the display of voice names.
		
        CLASS_ATTR_CHAR(c,"showclefs",0, t_notation_obj, show_clefs);
        CLASS_ATTR_STYLE_LABEL(c,"showclefs",0,"onoff","Show Clefs");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showclefs",0,"1");
        // @exclude bach.slot
        // @description Toggles the display of clefs.

        CLASS_ATTR_CHAR(c,"showauxclefs",0, t_notation_obj, show_aux_clefs);
        CLASS_ATTR_STYLE_LABEL(c,"showauxclefs",0,"onoff","Show Auxiliary Clefs In Combinations");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showauxclefs",0,"1");
        // @exclude bach.slot
        // @description Toggles the display of 15ma and/or 15vb clefs in voices with <m>clefs</m> combinations
        // such as <b>FFGG</b>, <b>FGG</b>, <b>FFG</b>, etc.

		CLASS_ATTR_CHAR(c,"showmarkers",0, t_notation_obj, show_markers);
		CLASS_ATTR_STYLE_LABEL(c,"showmarkers",0,"onoff","Show Markers");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showmarkers",0,"1");
		// @exclude bach.slot
		// @description Toggles the display of markers.
		
		CLASS_ATTR_CHAR(c,"showplayhead",0, t_notation_obj, show_playhead);
		CLASS_ATTR_STYLE_LABEL(c,"showplayhead",0,"onoff","Show Playhead");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showplayhead", 0, "0");
		// @exclude bach.slot
		// @description Toggles the constant display of the playhead line (even while not playing). 
		
		CLASS_ATTR_CHAR(c,"showledgerlines",0, t_notation_obj, show_ledger_lines);
		CLASS_ATTR_STYLE_LABEL(c,"showledgerlines",0,"enumindex","Show Ledger Lines");
		CLASS_ATTR_FILTER_CLIP(c, "showledgerlines", 0, 2);
		CLASS_ATTR_ENUMINDEX(c,"showledgerlines", 0, "Never Standard Always Refer To Main Staves");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showledgerlines", 0, "1");
		// @exclude bach.slot
		// @description Chooses how to display the ledger lines: <br />
		// - Never: ledger lines are always hidden. <br /> 
		// - Standard: the only displayed ledger lines are the one really needed to understand note positioning (i.e. ledger lines between main and auxiliary staves are hidden if not needed). <br /> 
		// - Always Refer To Main Staves: always show all ledger lines, even between main and auxiliary staves. 
		
		CLASS_ATTR_CHAR(c,"showlyrics",0, t_notation_obj, show_lyrics);
		CLASS_ATTR_STYLE_LABEL(c,"showlyrics",0,"onoff","Show Lyrics");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showlyrics", 0, "1");
		CLASS_ATTR_ACCESSORS(c, "showlyrics", (method)NULL, (method)notationobj_setattr_showlyrics);
		// @exclude bach.slot
		// @description Toggles the display of lyrics. 

        CLASS_ATTR_CHAR(c,"showdynamics",0, t_notation_obj, show_dynamics);
        CLASS_ATTR_STYLE_LABEL(c,"showdynamics",0,"onoff","Show Dynamics");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showdynamics", 0, "1");
        // @exclude bach.slot
        // @description Toggles the display of dynamics.

        CLASS_ATTR_CHAR(c,"showhairpins",0, t_notation_obj, show_hairpins);
        CLASS_ATTR_STYLE_LABEL(c,"showhairpins",0,"onoff","Show Hairpins for Dynamics");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showhairpins", 0, "1");
        // @exclude bach.slot
        // @description Toggles the display of hairpins for dynamics.

        
		CLASS_ATTR_CHAR(c,"ruler",0, t_notation_obj, ruler);
		CLASS_ATTR_STYLE_LABEL(c,"ruler",0,"enumindex","Show Ruler");
		CLASS_ATTR_ENUMINDEX(c,"ruler", 0, "Never Above Below Both");
        CLASS_ATTR_ACCESSORS(c, "ruler", (method)NULL, (method)notationobj_setattr_ruler);
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ruler",0,"0");
		// @exclude bach.slot
		// @description Toggles the display of the ruler. Four options are possible: <br />
		// - Never: ruler is not shown. <br />
		// - Above: ruler is shown on the upper border of the notation object. <br />
		// - Below: ruler is shown on the lower border of the notation object. <br />
		// - Both: ruler is shown on both upper and lower borders of the notation object. 
		
		CLASS_ATTR_CHAR(c,"grid",0, t_notation_obj, show_grid);
		CLASS_ATTR_STYLE_LABEL(c,"grid",0,"onoff","Show Grid");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"grid",0,"0");
		// @exclude bach.slot
		// @description Toggles the display of the grid.
		
		CLASS_ATTR_CHAR(c,"rulerlabels",0, t_notation_obj, show_ruler_labels);
		CLASS_ATTR_STYLE_LABEL(c,"rulerlabels",0,"onoff","Show Ruler Labels");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rulerlabels",0,"1");
		// @exclude bach.slot
		// @description Toggles the display of the ruler labels.
		
		CLASS_ATTR_CHAR(c,"showscrollbar",0, t_notation_obj, show_hscrollbar);
		CLASS_ATTR_STYLE_LABEL(c,"showscrollbar",0,"onoff","Show Horizontal Scrollbar If Needed");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showscrollbar", 0, "1");
		// @exclude bach.slot
		// @description Toggles the display of the horizontal scrollbar, if needed.
		// If unneeded, the scrollbar is not shown. By default this is 1: you should set it to 0 only
		// if you want to always hide the horizontal scrollbar.
		
		CLASS_ATTR_CHAR(c,"showvscrollbar",0, t_notation_obj, show_vscrollbar);
		CLASS_ATTR_STYLE_LABEL(c,"showvscrollbar",0,"onoff","Show Vertical Scrollbar If Needed");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showvscrollbar", 0, "1");
		CLASS_ATTR_ACCESSORS(c, "showvscrollbar", (method)NULL, (method)notationobj_setattr_showvscrollbar);
		// @exclude bach.slot
		// @description Toggles the display of the vertical scrollbar, if needed.
		// If unneeded, the scrollbar is not shown. By default this is 1: you should set it to 0 only
		// if you want to always hide the vertical scrollbar.
		
		CLASS_ATTR_CHAR(c,"showauxiliarystems",0, t_notation_obj, show_auxiliary_stems);
		CLASS_ATTR_STYLE_LABEL(c,"showauxiliarystems",0,"onoff","Show Unisons Auxiliary Stems");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showauxiliarystems", 0, "1");	
        CLASS_ATTR_INVISIBLE(c, "showauxiliarystems", ATTR_GET_OPAQUE | ATTR_SET_OPAQUE); // invisible attribute,  no longer supported. Use showstems instead
		// @exclude all
		
		CLASS_ATTR_CHAR(c,"shownotenames",0, t_notation_obj, show_note_names);
		CLASS_ATTR_STYLE_LABEL(c,"shownotenames",0,"onoff","Show Note Names In Selection Legend");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"shownotenames", 0, "0");
		// @exclude bach.slot
		// @description Toggles the display of note names in the selection legend
		
		if (obj_type == k_NOTATION_OBJECT_ROLL) {
			CLASS_ATTR_CHAR(c,"showgroups",0, t_notation_obj, show_groups);
			CLASS_ATTR_STYLE_LABEL(c,"showgroups",0,"enumindex","Show Groups");
			CLASS_ATTR_ENUMINDEX(c,"showgroups", 0, "None Lines Colors Lines And Colors");
			CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showgroups", 0, "3");
			// @exclude bach.slot, bach.score
			// @description Chooses how the chord grouping should be displayed: <br />
			// - None: groups are not displayed in any way. <br />
			// - Lines: groups are displayed by linking chord stems with dashed lines. <br />
			// - Colors: groups are displayed by assigning to each group a particular color. <br />
			// - Lines And Colors (default): both of the two previous devices are adopted.
		}

		CLASS_ATTR_CHAR(c, "labelfamilies", 0, t_notation_obj, show_label_families); 
		CLASS_ATTR_STYLE_LABEL(c,"labelfamilies",0,"enumindex","Show Label Families");
		CLASS_ATTR_ENUMINDEX(c,"labelfamilies", 0, "None Singleton Bounding Box Venn");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"labelfamilies",0,"0");
		CLASS_ATTR_ACCESSORS(c, "labelfamilies", (method)NULL, (method)notationobj_setattr_labelfamilies);
		// @exclude bach.slot
		// @description Chooses the way in which elements bearing the same names should be visually tagged: <br />
		// - None (default): don't show label families. <br />
		// - Singleton: enclose each single notation item in a shape (circle for notes, rectangles for chords and measures)
		// bearing the same color for each family. <br />
		// - Bounding Box: enclose all items of a certain family in a rectangle bounding box. IMPORTANT: in this case,
		// you might end up with having other notes (not belonging to that family) inside the bounding box. <br />
		// - Venn: enclose families in an unique closed curve. This will usually work well if points are not too much scattered among other points. 
		// Notice that in this case, points not belonging to the label family lie outside the curve. BEW
		
		CLASS_ATTR_CHAR(c,"legend",0, t_notation_obj, legend);
		CLASS_ATTR_STYLE_LABEL(c,"legend",0,"enumindex","Show Legend");
		CLASS_ATTR_ENUMINDEX(c,"legend", 0, "Never Only For Selection Always");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"legend",0,"2");
		// @exclude bach.slot
		// @description Chooses if and where the legend should be displayed:
		// - Never: no legend is ever shown. <br />
		// - Only For Selection: only selection legend is displayed. Selection legend is
		// located in the upper left corner of the notation object, and is shown whenever a single
		// notation item (e.g. a note) is selected. <br />
		// - Always: in addition to selection legend, also the mouseover legend is displayed. 
		// Mouseover legend is located in the bottom right corner of the notation object, and is shown whenever the mouse
		// moves over the notation object. <br />
		
		CLASS_ATTR_CHAR(c,"showmutecolor",0, t_notation_obj, show_mute_color_when);
		CLASS_ATTR_STYLE_LABEL(c,"showmutecolor",0,"enumindex","Show Mute Color");
		CLASS_ATTR_ENUMINDEX(c,"showmutecolor", 0, "Never When Selected When Not Selected Always");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showmutecolor", 0, "2");
		// @exclude bach.slot
		// @description Chooses when the muted elements should be displayed with the color associated with the element muting 
		// (see the <m>mutecolor</m> attribute): <br /> 
		// - Never: never use the <m>mutecolor</m>. <br />
		// - When Selecteed: use the <m>mutecolor</m> only when elements are selected, instead of the <m>selectioncolor</m>. <br />
		// - When Not Selected: use the <m>mutecolor</m> only when elements are not selected. <br />
		// - Always: always use the <m>mutecolor</m>.
		
		CLASS_ATTR_CHAR(c,"showlockcolor",0, t_notation_obj, show_lock_color_when);
		CLASS_ATTR_STYLE_LABEL(c,"showlockcolor",0,"enumindex","Show Lock Color");
		CLASS_ATTR_ENUMINDEX(c,"showlockcolor", 0, "Never When Selected When Not Selected Always");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showlockcolor", 0, "2");
		// @exclude bach.slot
		// @description Chooses when the locked elements should be displayed with the color associated with the element locking
		// (see the <m>lockcolor</m> attribute): <br /> 
		// - Never: never use the <m>lockcolor</m>. <br />
		// - When Selecteed: use the <m>lockcolor</m> only when elements are selected, instead of the <m>selectioncolor</m>. <br />
		// - When Not Selected: use the <m>lockcolor</m> only when elements are not selected. <br />
		// - Always: always use the <m>lockcolor</m>.
		
		CLASS_ATTR_CHAR(c,"showsolocolor",0, t_notation_obj, show_solo_color_when);
		CLASS_ATTR_STYLE_LABEL(c,"showsolocolor",0,"enumindex","Show Solo Color");
		CLASS_ATTR_ENUMINDEX(c,"showsolocolor", 0, "Never When Selected When Not Selected Always");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showsolocolor", 0, "2");
		// @exclude bach.slot
		// @description Chooses when the elements set as "solo" should be displayed with the color associated with the solo elements
		// (see the <m>solocolor</m> attribute): <br /> 
		// - Never: never use the <m>solocolor</m>. <br />
		// - When Selecteed: use the <m>solocolor</m> only when elements are selected, instead of the <m>selectioncolor</m>. <br />
		// - When Not Selected: use the <m>solocolor</m> only when elements are not selected. <br />
		// - Always: always use the <m>solocolor</m>.
		
		CLASS_ATTR_CHAR(c,"showloop",0, t_notation_obj, show_loop_region);
		CLASS_ATTR_STYLE_LABEL(c,"showloop",0,"onoff","Show Loop Region");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showloop", 0, "0");
		CLASS_ATTR_ACCESSORS(c, "showloop", (method)NULL, (method)notationobj_setattr_showloop);
		// @exclude bach.slot
		// @description Toggles the display of the loop region.

        CLASS_ATTR_CHAR(c,"showarticulations",0, t_notation_obj, show_articulations);
        CLASS_ATTR_STYLE_LABEL(c,"showarticulations",0,"onoff","Show Articulations");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showarticulations",0,"1");
        // @exclude bach.slot
        // @description Toggles the display of articulations. Articulations are handled via slot linkage:
        // pick an articulations slot and link it with "articulations".
        
        CLASS_ATTR_CHAR(c,"showarticulationsextensions",0, t_notation_obj, show_articulations_extensions);
        CLASS_ATTR_STYLE_LABEL(c,"showarticulationsextensions",0,"onoff","Show Articulations Extensions");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showarticulationsextensions",0,"1");
        // @exclude bach.slot
        // @description Toggles the display of articulation extensions (such as trill lines).
 
        CLASS_ATTR_CHAR(c,"showannotations",0, t_notation_obj, show_annotations);
        CLASS_ATTR_STYLE_LABEL(c,"showannotations",0,"onoff","Show Text Annotations");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showannotations",0,"1");
        // @exclude bach.slot
        // @description Toggles the display of annotations. Annotations are handled via slot linkage:
        // pick a text slot and link it with "annotation".
        
        CLASS_ATTR_CHAR(c,"showpartcolors",0, t_notation_obj, show_part_colors);
        CLASS_ATTR_STYLE_LABEL(c,"showpartcolors",0,"onoff","Show Part Colors");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showpartcolors",0,"0");
        // @exclude bach.slot
        // @description Toggles the display of different voice parts (see the <m>parts</m> attribute) with different colors.
    }
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
}

void notation_class_add_font_attributes(t_class *c, char obj_type){
	CLASS_STICKY_ATTR(c,"category",0,"Font");
	
	if (obj_type != k_NOTATION_OBJECT_SLOT) {
		
		CLASS_ATTR_DOUBLE(c,"rulerlabelsfontsize",0, t_notation_obj, ruler_labels_font_size);
		CLASS_ATTR_STYLE_LABEL(c,"rulerlabelsfontsize",0,"text","Ruler Labels Font Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rulerlabelsfontsize",0,"8");
		CLASS_ATTR_FILTER_MIN(c, "rulerlabelsfontsize", 1.);
		// @exclude bach.slot
		// @description Sets the font size of ruler labels (rescaled according to the <m>vzoom</m>). 
		
        CLASS_ATTR_SYM(c,"voicenamesfont", 0, t_notation_obj, voice_names_font);
        CLASS_ATTR_STYLE_LABEL(c, "voicenamesfont", 0, "font", "Voice Names Font");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"voicenamesfont", 0, "Arial");
        CLASS_ATTR_ACCESSORS(c, "voicenamesfont", (method)NULL, (method)notationobj_setattr_voicenames_font);
        // @exclude bach.slot
        // @description Sets the font size of voice names

		CLASS_ATTR_DOUBLE(c,"voicenamesfontsize",0, t_notation_obj, voice_names_font_size);
		CLASS_ATTR_STYLE_LABEL(c,"voicenamesfontsize",0,"text","Voice Names Font Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"voicenamesfontsize", 0, "11");
		CLASS_ATTR_ACCESSORS(c, "voicenamesfontsize", (method)NULL, (method)notationobj_setattr_voicenames_font_size);
		// @exclude bach.slot
		// @description Sets the font size of voice names (rescaled according to the <m>vzoom</m>). 
		
        CLASS_ATTR_SYM(c,"markersfont", 0, t_notation_obj, markers_font);
        CLASS_ATTR_STYLE_LABEL(c, "markersfont", 0, "font", "Markers Font");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"markersfont", 0, "Arial");
        CLASS_ATTR_ACCESSORS(c, "markersfont", (method)NULL, (method)notationobj_setattr_markers_font);
        // @exclude bach.slot
        // @description Sets the font size of markers

		CLASS_ATTR_DOUBLE(c,"markersfontsize",0, t_notation_obj, markers_font_size);
		CLASS_ATTR_STYLE_LABEL(c,"markersfontsize",0,"text","Markers Font Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"markersfontsize", 0, "9");
		CLASS_ATTR_ACCESSORS(c, "markersfontsize", (method)NULL, (method)notationobj_setattr_markers_font_size);
		// @exclude bach.slot
		// @description Sets the font size of marker names (rescaled according to the <m>vzoom</m>). 
		
		CLASS_ATTR_DOUBLE(c,"bgslotfontsize",0, t_notation_obj, slot_background_font_size);
		CLASS_ATTR_STYLE_LABEL(c,"bgslotfontsize",0,"text","Background Slot Font Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"bgslotfontsize", 0, "8");
		// @exclude bach.slot
		// @description Sets the font size of background slots displayed as text (rescaled according to the <m>vzoom</m>). 
		
		// just for bw compatibility
		CLASS_ATTR_DOUBLE(c,"backgroundslotfontsize",0, t_notation_obj, slot_background_font_size);
		CLASS_ATTR_PAINT(c,"backgroundslotfontsize", 0);
		CLASS_ATTR_INVISIBLE(c,"backgroundslotfontsize", 0); // just for bw compatibility
		// @exclude all
		
		CLASS_ATTR_DOUBLE(c,"lyricsfontsize",0, t_notation_obj, lyrics_font_size);
		CLASS_ATTR_STYLE_LABEL(c,"lyricsfontsize",0,"text","Lyrics Font Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"lyricsfontsize", 0, "12");
		CLASS_ATTR_ACCESSORS(c, "lyricsfontsize", (method)NULL, (method)notationobj_setattr_lyrics_font_size);
		// @exclude bach.slot
		// @description Sets the font size of lyrics (rescaled according to the <m>vzoom</m>). 

        CLASS_ATTR_DOUBLE(c,"dynamicsfontsize",0, t_notation_obj, dynamics_font_size);
        CLASS_ATTR_STYLE_LABEL(c,"dynamicsfontsize",0,"text","Dynamics Font Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"dynamicsfontsize", 0, "24");
        CLASS_ATTR_ACCESSORS(c, "dynamicsfontsize", (method)NULL, (method)notationobj_setattr_dynamics_font_size);
        // @exclude bach.slot
        // @description Sets the font size of dynamics (rescaled according to the <m>vzoom</m>).

        CLASS_ATTR_DOUBLE(c,"dynamicsexprfontsize",0, t_notation_obj, dynamics_roman_font_size);
        CLASS_ATTR_STYLE_LABEL(c,"dynamicsexprfontsize",0,"text","Dynamics Expressions Font Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"dynamicsexprfontsize", 0, "12");
        CLASS_ATTR_ACCESSORS(c, "dynamicsexprfontsize", (method)NULL, (method)notationobj_setattr_dynamics_roman_font_size);
        // @exclude bach.slot
        // @description Sets the font size of dynamic-like textual expressions (rescaled according to the <m>vzoom</m>).

		CLASS_ATTR_DOUBLE(c,"legendfontsize",0, t_notation_obj, legend_font_size);
		CLASS_ATTR_STYLE_LABEL(c,"legendfontsize",0,"text","Legend Font Size");
		CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"legendfontsize", 0, "13");
		// @exclude bach.slot
		// @description Sets the font size of mouseover and selection legends (rescaled according to the <m>vzoom</m>). 
		
        CLASS_ATTR_DOUBLE(c,"annotationfontsize",0, t_notation_obj, annotation_font_size);
        CLASS_ATTR_STYLE_LABEL(c,"annotationfontsize",0,"text","Annotation Font Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"annotationfontsize", 0, "10");
        CLASS_ATTR_ACCESSORS(c, "annotationfontsize", (method)NULL, (method)notationobj_setattr_annotation_font_size);
        // @exclude bach.slot
        // @description Sets the font size for textual annotations over the staff (handled via slot linkage).
        
	}
	
	CLASS_STICKY_ATTR_CLEAR(c, "category");
}


void notation_class_add_pitches_attributes(t_class *c, char obj_type){
    CLASS_STICKY_ATTR(c,"category",0,"Pitches");
    
    if (obj_type != k_NOTATION_OBJECT_SLOT) {
        
        CLASS_ATTR_CHAR(c,"outputpitchesgathered",0, t_notation_obj, output_pitches_gathered);
        CLASS_ATTR_STYLE_LABEL(c,"outputpitchesgathered",0,"enumindex","Output Pitches In Gathered Syntax");
        CLASS_ATTR_ENUMINDEX(c,"outputpitchesgathered", 0, "Never When User-Defined Always");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"outputpitchesgathered",0,"1");
        // @description Toggles the ability to output pitches, instead of MIDIcents, in the gathered syntax. <br />
        // - Never: never output pitches (always output MIDIcents); <br />
        // - When User-Defined: only output pitches when they are user-defined (otherwise output MIDIcents); <br />
        // - Always: force output of pitches even when user only entered MIDIcents (displayed pitches are output).

        CLASS_ATTR_CHAR(c,"outputpitchesseparate",0, t_notation_obj, output_pitches_separate);
        CLASS_ATTR_STYLE_LABEL(c,"outputpitchesseparate",0,"enumindex","Output Pitches In Separate Syntax");
        CLASS_ATTR_ENUMINDEX(c,"outputpitchesseparate", 0, "Never When User-Defined Always");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"outputpitchesseparate",0,"0");
        // @description Toggles the ability to output pitches, instead of MIDIcents, in the separate syntax. <br />
        // - Never: never output pitches (always output MIDIcents); <br />
        // - When User-Defined: only output pitches when they are user-defined (otherwise output MIDIcents); <br />
        // - Always: force output of pitches even when user only entered MIDIcents (displayed pitches are output).

        CLASS_ATTR_CHAR(c,"outputpitchesplayout",0, t_notation_obj, output_pitches_playout);
        CLASS_ATTR_STYLE_LABEL(c,"outputpitchesplayout",0,"enumindex","Output Pitches In Playout Syntax");
        CLASS_ATTR_ENUMINDEX(c,"outputpitchesplayout", 0, "Never When User-Defined Always");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"outputpitchesplayout",0,"0");
        // @description Toggles the ability to output pitches, instead of MIDIcents, in the playout syntax. <br />
        // - Never: never output pitches (always output MIDIcents); <br />
        // - When User-Defined: only output pitches when they are user-defined (otherwise output MIDIcents); <br />
        // - Always: force output of pitches even when user only entered MIDIcents (displayed pitches are output).

    }
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
}

t_max_err notationobj_setattr_showvelocity(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		long prev_vel_handling = r_ob->velocity_handling;
		r_ob->velocity_handling = atom_getlong(av);
		if (r_ob->velocity_handling == k_VELOCITY_HANDLING_NOTEHEADSIZE || prev_vel_handling == k_VELOCITY_HANDLING_NOTEHEADSIZE)
			quick_notationobj_recompute_all_chord_parameters(r_ob);
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	}
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_labelfamilies(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		long prev_label_families = r_ob->show_label_families;
		r_ob->show_label_families = atom_getlong(av);
		if (r_ob->show_label_families != prev_label_families) {
			if (r_ob->show_label_families == k_SHOW_LABEL_FAMILIES_BOUNDINGBOX || r_ob->show_label_families == k_SHOW_LABEL_FAMILIES_VENN) 
				update_all_label_families_contour(r_ob);
//			if (r_ob->show_label_families)
//				parse_label_families(r_ob);
			notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
		}
	}
	return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_highlightplay(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		r_ob->highlight_played_notes = CLAMP(atom_getlong(av), 0, 1);
		llll_clear(r_ob->notes_being_played);
	}
	
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_useloop(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		r_ob->use_loop_region = CLAMP(atom_getlong(av), 0, 1);
		if (r_ob->notify_also_upon_messages && !r_ob->creatingnewobj)
			send_loop_region_on_off(r_ob, r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? 6 : 7);
		notationobj_redraw(r_ob);
	}
	
	return MAX_ERR_NONE;
}
	
t_max_err notationobj_setattr_showloop(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		r_ob->show_loop_region = CLAMP(atom_getlong(av), 0, 1);
		if (r_ob->notify_also_upon_messages && !r_ob->creatingnewobj)
			send_loop_region_on_off(r_ob, r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? 6 : 7);
		notationobj_redraw(r_ob);
	}
	
	return MAX_ERR_NONE;
}



void set_prevent_editing(t_notation_obj *r_ob, e_element_types elem, e_element_actions action, char val)
{
	switch (elem) {
		case k_NOTE_OR_CHORD: case k_NOTE: case k_CHORD:
		{
			switch (action) {
				case k_CREATION: 
				{	
					if (elem == k_CHORD)
						r_ob->prevent_edit.chord_creation = val; 
					else
						r_ob->prevent_edit.note_creation = r_ob->prevent_edit.chord_creation = val; 
				}
					break;
				case k_DELETION: 
				{	
					if (elem == k_CHORD)
						r_ob->prevent_edit.chord_deletion = val; 
					else
						r_ob->prevent_edit.note_deletion = r_ob->prevent_edit.chord_deletion = val; 
				}
					break;
				case k_MODIFICATION_ONSET: r_ob->prevent_edit.chord_onset = val; break;
				case k_MODIFICATION_DURATION: r_ob->prevent_edit.note_duration = val; break;
				case k_MODIFICATION_PITCH: r_ob->prevent_edit.note_pitch = val; break;
				case k_MODIFICATION_VELOCITY: r_ob->prevent_edit.note_velocity = val; break;
				case k_MODIFICATION_GENERIC: r_ob->prevent_edit.note_modification = val; break;
				default:
					r_ob->prevent_edit.chord_onset = r_ob->prevent_edit.chord_creation = r_ob->prevent_edit.chord_deletion = r_ob->prevent_edit.note_duration = r_ob->prevent_edit.note_pitch = 
					r_ob->prevent_edit.note_velocity = r_ob->prevent_edit.note_creation = r_ob->prevent_edit.note_deletion =  r_ob->prevent_edit.note_modification = val; break;
			}
		}
			break;
		case k_PITCH_BREAKPOINT:
		{
			switch (action) {
				case k_CREATION: r_ob->prevent_edit.breakpoints_creation = val; break;
				case k_DELETION: r_ob->prevent_edit.breakpoints_deletion = val; break;
				case k_MODIFICATION_ONSET: r_ob->prevent_edit.breakpoints_onset = val; break;
				case k_MODIFICATION_PITCH: r_ob->prevent_edit.breakpoints_pitch = val; break;
				case k_MODIFICATION_VELOCITY: r_ob->prevent_edit.breakpoints_velocity = val; break;
				default: r_ob->prevent_edit.breakpoints_creation = r_ob->prevent_edit.breakpoints_deletion = r_ob->prevent_edit.breakpoints_onset = 
					r_ob->prevent_edit.breakpoints_pitch = r_ob->prevent_edit.breakpoints_velocity = val; break;
			}
		}
			break;
		case k_MEASURE:
		{
			switch (action) {
				case k_CREATION: r_ob->prevent_edit.measure_creation = val; break;
				case k_DELETION: r_ob->prevent_edit.measure_deletion = val; break;
				case k_MODIFICATION_RHYTHMIC_TREE: r_ob->prevent_edit.measure_rhythmic_tree = val; break;
				case k_MODIFICATION_GENERIC: r_ob->prevent_edit.measure_modification = val; break;
				default: r_ob->prevent_edit.measure_creation = r_ob->prevent_edit.measure_deletion = r_ob->prevent_edit.measure_rhythmic_tree = r_ob->prevent_edit.measure_modification = val; break;
			}
		}
			break;
		case k_VOICE:
		{
			switch (action) {
				case k_CREATION: r_ob->prevent_edit.voice_creation = val; break;
				case k_DELETION: r_ob->prevent_edit.voice_deletion = val; break;
				case k_MODIFICATION_POSITION: r_ob->prevent_edit.voice_position = val; break;
				case k_MODIFICATION_NAME: r_ob->prevent_edit.voice_name = val; break;
				case k_MODIFICATION_KEY: r_ob->prevent_edit.voice_key = val; break;
				case k_MODIFICATION_CLEF: r_ob->prevent_edit.voice_clef = val; break;
				case k_MODIFICATION_GENERIC: r_ob->prevent_edit.voice_modification = val; break;
				default: r_ob->prevent_edit.voice_creation = r_ob->prevent_edit.voice_deletion = r_ob->prevent_edit.voice_position =
					r_ob->prevent_edit.voice_name = r_ob->prevent_edit.voice_key = r_ob->prevent_edit.voice_clef = r_ob->prevent_edit.voice_modification = val; break;
			}
		}
			break;
		case k_TEMPO:
		{
			switch (action) {
				case k_CREATION: r_ob->prevent_edit.tempo_creation = val; break;
				case k_DELETION: r_ob->prevent_edit.tempo_deletion = val; break;
				case k_MODIFICATION_GENERIC: r_ob->prevent_edit.tempo_modification = val; break;
				default: r_ob->prevent_edit.tempo_creation = r_ob->prevent_edit.tempo_deletion = r_ob->prevent_edit.tempo_modification = val; break;
			}
		}
			break;
		case k_MARKER:
		{
			switch (action) {
				case k_CREATION: r_ob->prevent_edit.marker_creation = val; break;
				case k_DELETION: r_ob->prevent_edit.marker_deletion = val; break;
				case k_MODIFICATION_ONSET: r_ob->prevent_edit.marker_onset = val; break;
				case k_MODIFICATION_NAME: r_ob->prevent_edit.marker_name = val; break;
				case k_MODIFICATION_GENERIC: r_ob->prevent_edit.marker_modification = val; break;
				default:  r_ob->prevent_edit.marker_creation = r_ob->prevent_edit.marker_deletion = r_ob->prevent_edit.marker_onset =
					r_ob->prevent_edit.marker_name = r_ob->prevent_edit.marker_modification = val; break;
			}
		}
			break;
		case k_ARTICULATION:
		{
			switch (action) {
				case k_CREATION: r_ob->prevent_edit.articulation_creation = val; break;
				case k_DELETION: r_ob->prevent_edit.articulation_deletion = val; break;
				default: r_ob->prevent_edit.articulation_creation = r_ob->prevent_edit.articulation_deletion = val; break;
			}
		}
			break;
		case k_SLOT:
			r_ob->prevent_edit.slot = val;
			break;
		case k_SLOTINFO:
			r_ob->prevent_edit.slotinfo = val;
			break;
		case k_TIME_SIGNATURE:
			r_ob->prevent_edit.timesignature_modification = val;
			break;
		case k_SELECTION:
			switch (action) {
				case k_SINGLE_SELECTION: r_ob->prevent_edit.selection_single = val; break;
				case k_MULTIPLE_SELECTION: r_ob->prevent_edit.selection_multiple = val; break;
				default: r_ob->prevent_edit.selection_multiple = r_ob->prevent_edit.selection_single = val; break;
			}
			break;
		case k_ZOOMING_REGION:
			r_ob->prevent_edit.zooming = val;
			break;
		case k_DILATION_RECTANGLE:
			r_ob->prevent_edit.dilation_rect = val;
			break;
		case k_GROUP:
			r_ob->prevent_edit.grouping = val;
			break;
		case k_BACH_INSPECTOR:
			r_ob->prevent_edit.inspector = val;
			break;
		case k_POPUP_MENU:
			r_ob->prevent_edit.popup_menu = val;
			break;
		case k_LYRICS:
			r_ob->prevent_edit.lyrics = val;
			break;
        case k_DYNAMICS:
            r_ob->prevent_edit.dynamics = val;
            break;
		case k_PLAYCURSOR:
			r_ob->prevent_edit.cursor = val;
			break;
		case k_LOOP_REGION:
			r_ob->prevent_edit.loop_region = val;
			break;
		case k_SCROLLBAR:
			r_ob->prevent_edit.scrollbar = val;
			break;
        case k_DROP:
            r_ob->prevent_edit.drop = val;
            break;
		default:
			return;
	}
}

t_max_err notationobj_setattr_maxundosteps(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		t_atom old_num_steps = r_ob->max_undo_steps;
		t_atom inf;
		atom_setsym(&inf, _llllobj_sym_inf);
		t_atom new_num_steps = atom_gettype(av) != A_LONG ? inf : *av;

		if (atom_gettype(&new_num_steps) == A_LONG && atom_getlong(&new_num_steps) < 0)
			atom_setlong(&new_num_steps, -atom_getlong(&new_num_steps));

		if (atom_gettype(&old_num_steps) == A_LONG && atom_gettype(&new_num_steps) == A_LONG) {
			if (atom_getlong(&new_num_steps) <= atom_getlong(&old_num_steps)) {
				clear_undo_redo_llll(r_ob, k_UNDO);
				clear_undo_redo_llll(r_ob, k_REDO);
			}
		} else if (atom_gettype(&new_num_steps) == A_LONG && atom_gettype(&old_num_steps) == A_SYM) {
			clear_undo_redo_llll(r_ob, k_UNDO);
			clear_undo_redo_llll(r_ob, k_REDO);
		}
		r_ob->max_undo_steps = new_num_steps;
	}
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_preventedit(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	long set_to_value = 1;
	clear_prevent_edit(&r_ob->prevent_edit);
	
	if (ac && av) {
		r_ob->num_prevent_editing_elems = 0;
		t_llll *parsed = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
		if (parsed) {
			t_llllelem *elem;
			for (elem = parsed->l_head; elem; elem = elem->l_next) {
				if (hatom_gettype(&elem->l_hatom) == H_SYM) {
					t_symbol *sym = hatom_getsym(&elem->l_hatom);
					if (sym == gensym("-") && !elem->l_prev) { 
						set_all_prevent_edit_to_value(&r_ob->prevent_edit, 1);
						set_to_value = 0;
					} else {
						e_element_types elem_id = (e_element_types) elementtypesym2elementtypeid(sym);
						set_prevent_editing(r_ob, elem_id, k_ALL_ACTIONS, set_to_value);
					}
				} else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
					t_llll *ll = hatom_getllll(&elem->l_hatom);
					if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM) {
						t_symbol *router = hatom_getsym(&ll->l_head->l_hatom);
						e_element_types elem_id = (e_element_types) elementtypesym2elementtypeid(router);
						t_llllelem *act = ll->l_head->l_next, *nextact;
						while (act) {
							nextact = act->l_next;
							if (hatom_gettype(&act->l_hatom) == H_SYM) {
								t_symbol *action = hatom_getsym(&act->l_hatom);
								e_element_actions action_id = (e_element_actions) actiontypesym2actiontypeid(action);
								if (action_id >= 0)
									set_prevent_editing(r_ob, elem_id, action_id, set_to_value);
								else
									llll_destroyelem(act);
							}
							act = nextact;
						}
					}
				}
			}
			
			if (parsed->l_size == 0) 
				r_ob->num_prevent_editing_elems = 0;
			else {
				t_atom *out = NULL;
				long num_prevent_editing_elems = llll_deparse(parsed, &out, 0, 0);
				long n = MIN(num_prevent_editing_elems, CONST_MAX_BACH_ELEMENT_TYPES + 10);
				atom_setatom_array(n, r_ob->prevent_editing_atom, CONST_MAX_BACH_ELEMENT_TYPES + 10, out);
				r_ob->num_prevent_editing_elems = n; 
				
				bach_freeptr(out);
			}
			llll_free(parsed);
		}
	}
	return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_rulermode(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		long mode = atom_getlong(av);
		r_ob->ruler_mode = mode;
		object_attr_setdisabled((t_object *)r_ob, _llllobj_sym_gridperiodms, mode == 1);
		object_attr_setdisabled((t_object *)r_ob, _llllobj_sym_numgridsubdivisions, mode == 1);
	}
	
	return MAX_ERR_NONE;
}


// use marker = NULL to get all markers
t_llll *get_single_marker_as_llll(t_notation_obj *r_ob, t_marker *marker, char namefirst){
	t_llll *outlist;
	if (marker) {
		outlist = llll_get();
		llll_appendsym(outlist, _llllobj_sym_marker, 0, WHITENULL_llll); // the "marker" symbol in first place
		if (marker->r_it.names->l_size == 0)
			llll_appendsym(outlist, _llllobj_sym_none, 0, WHITENULL_llll);
		else if (marker->r_it.names->l_size == 1 && marker->r_it.names->l_depth == 1)
			llll_appendhatom(outlist, &marker->r_it.names->l_head->l_hatom, 0, WHITENULL_llll);
		else 
			llll_appendllll(outlist, get_names_as_llll((t_notation_item *)marker, false), 0, WHITENULL_llll);
		if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE){
			t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
			t_llll *timepointll = get_timepoint_as_llll(r_ob, tp);
			llll_appendllll(outlist, timepointll, 0, WHITENULL_llll);
		} else 
			llll_appenddouble(outlist, marker->position_ms, 0, WHITENULL_llll);
		llll_appendsym(outlist, marker_role_to_sym(marker->role), 0, WHITENULL_llll);
		if (marker->role != k_MARKER_ROLE_NONE && marker->content)
			llll_appendllll_clone(outlist, marker->content, 0, WHITENULL_llll, NULL);
	} else {
		outlist = get_markers_as_llll(r_ob, 0, 0, 0, namefirst, k_CONSIDER_FOR_DUMPING, 0);
	}
	return outlist;
}

// use marker = NULL to send all markers
void send_marker_as_llll(t_notation_obj *r_ob, t_marker *marker, char namefirst, long outlet, t_llll *forced_routers)
{
	t_llll *llll;
	lock_markers_mutex(r_ob);
	llll = get_single_marker_as_llll(r_ob, marker, namefirst);
    
    if (forced_routers && forced_routers->l_head && hatom_gettype(&forced_routers->l_head->l_hatom) == H_SYM &&
        llll && llll->l_head && hatom_getsym(&llll->l_head->l_hatom) == _llllobj_sym_marker)
        hatom_setsym(&llll->l_head->l_hatom, hatom_getsym(&forced_routers->l_head->l_hatom));
        
	unlock_markers_mutex(r_ob);
    setup_lambda_and_send_llll(r_ob, outlet, llll, (t_notation_item *)marker);
	llll_free(llll);
}

void do_send_rebuild_done(t_object *x)
{
	long outlet = -1;
	t_llll* done_llll;

	if (((t_notation_obj *)x)->obj_type == k_NOTATION_OBJECT_ROLL)
		outlet = 6;
	else if (((t_notation_obj *)x)->obj_type == k_NOTATION_OBJECT_SCORE)
		outlet = 7;
	else if (((t_notation_obj *)x)->obj_type == k_NOTATION_OBJECT_SLOT)
		outlet = 1;
	
	if (outlet > -1) {
		done_llll = llll_get();
		llll_appendsym(done_llll, _sym_done, 0, WHITENULL_llll);
		llllobj_outlet_llll(x, LLLL_OBJ_UI, outlet, done_llll);
		llll_free(done_llll);
	}
	
	if (((t_notation_obj *)x)->obj_type == k_NOTATION_OBJECT_SLOT)
		send_changed_open_slot_notification((t_notation_obj *)x, 1);
}

void send_rebuild_done(t_notation_obj *r_ob) {
	// send "done" message (after a rebuild)
	if (r_ob->need_send_rebuild_done_after_paint) { // we're in paint method
		qelem_set(r_ob->n_qelem_send_rebuild_done);
		//		defer_low((t_object *)r_ob, (method)do_send_rebuild_done, NULL, 0, NULL);
	} else {
		do_send_rebuild_done((t_object *) r_ob);
	}
}


t_max_err notationobj_setattr_bgcolor(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		atoms_to_jrgba(ac, av, &r_ob->j_background_rgba);
		notationobj_build_clef_gradient_surface(r_ob);
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	}
	return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_inset(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		long s = atom_getlong(av); 
		r_ob->j_inset_x = (s > 0) ? s : 0;
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
		recompute_total_length(r_ob);
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	}
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_jitmatrix(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
    if (ac && av && atom_gettype(av) == A_SYM) {
        t_symbol *s = atom_getsym(av);
        r_ob->jit_destination_matrix = s;
    } else {
        r_ob->jit_destination_matrix = _llllobj_sym_empty_symbol;
    }
    return MAX_ERR_NONE;
}



t_max_err notationobj_setattr_showvscrollbar(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		r_ob->show_vscrollbar = CLAMP(atom_getlong(av), 0, 1);
		quick_notationobj_recompute_all_chord_parameters(r_ob);
	}
	return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_midichannels(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	t_llll *midichannels_as_llll = llllobj_parse_llll((t_object *) r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
	set_midichannels_from_llll(r_ob, midichannels_as_llll);
	llll_free(midichannels_as_llll);
	return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_show_voicenames(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && is_atom_number(av))
		r_ob->show_voice_names = atom_getlong(av);
	recalculate_voicenames_width(r_ob);
	update_hscrollbar(r_ob, 0);
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_voicenames_font(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
    if (ac && atom_gettype(av) == A_SYM)
        r_ob->voice_names_font = atom_getsym(av);
    recalculate_voicenames_width(r_ob);
    update_hscrollbar(r_ob, 0);
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_voicenames_font_size(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && is_atom_number(av))
		r_ob->voice_names_font_size = atom_getfloat(av);
	recalculate_voicenames_width(r_ob);
	update_hscrollbar(r_ob, 0);
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_markers_font(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
    if (ac && atom_gettype(av) == A_SYM)
        r_ob->markers_font = atom_getsym(av);
    if (r_ob->firstmarker){
        t_marker *marker;
        for (marker = r_ob->firstmarker; marker; marker = marker->next)
        recalculate_marker_name_uwidth(r_ob, marker);
    }
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_markers_font_size(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
	if (ac && is_atom_number(av))
		r_ob->markers_font_size = atom_getfloat(av);
	if (r_ob->firstmarker){
		t_marker *marker;
		for (marker = r_ob->firstmarker; marker; marker = marker->next)
			recalculate_marker_name_uwidth(r_ob, marker);
	}
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	return MAX_ERR_NONE;
}

void implicitely_recalculate_all(t_notation_obj *r_ob, char also_recompute_beamings){
	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
		t_scorevoice *voice;
		t_measure *meas;
		for (voice = (t_scorevoice *)r_ob->firstvoice; voice && voice->v_ob.number < r_ob->num_voices; voice = (t_scorevoice *) voice_get_next(r_ob, (t_voice *)voice)){
			for (meas = voice->firstmeasure; meas; meas = meas->next) {
				recompute_all_for_measure(r_ob, meas, also_recompute_beamings);
			}
		}
		r_ob->need_recompute_tuttipoints = true;
	} else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL){
		t_rollvoice *voice;
		t_chord *chord;
		for (voice = (t_rollvoice *)r_ob->firstvoice; voice && voice->v_ob.number < r_ob->num_voices; voice = (t_rollvoice *) voice_get_next(r_ob, (t_voice *)voice)){
			for (chord = voice->firstchord; chord; chord = chord->next){
				chord->need_recompute_parameters = true;
			}
		}
	}
	set_need_perform_analysis_and_change_flag(r_ob);
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}


t_max_err notationobj_setattr_lyrics_font_size(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && is_atom_number(av))
		r_ob->lyrics_font_size = atom_getfloat(av);
	
	implicitely_recalculate_all(r_ob, false);

	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_dynamics_font_size(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        r_ob->dynamics_font_size = atom_getfloat(av);
    
    implicitely_recalculate_all(r_ob, false);
    
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_dynamics_roman_font_size(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        r_ob->dynamics_roman_font_size = atom_getfloat(av);
    
    implicitely_recalculate_all(r_ob, false);
    
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_annotation_font_size(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        r_ob->annotation_font_size = atom_getfloat(av);
    
    implicitely_recalculate_all(r_ob, false);
    
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_lyrics_alignment(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && is_atom_number(av))
		r_ob->lyrics_alignment = atom_getlong(av);
	
	implicitely_recalculate_all(r_ob, false);

	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_samplingrate(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	t_voice *voice;
	t_chord *chord;
	t_note *note;
	long s;
	t_slotitem *item;
	
	if (ac && is_atom_number(av))
		r_ob->sampling_freq = atom_getfloat(av);

	for (voice = r_ob->firstvoice; voice; voice = voice_get_next(r_ob, voice)){
		for (chord = (r_ob->obj_type == k_NOTATION_OBJECT_SCORE ? (((t_scorevoice *) voice)->firstmeasure ? ((t_scorevoice *) voice)->firstmeasure->firstchord : NULL)
					  : ((t_rollvoice *)voice)->firstchord); chord; chord = chord_get_next(chord))
			for (note = chord->firstnote; note; note = note->next)
				for (s = 0; s < CONST_MAX_SLOTS; s++)
					if (r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_FILTER || r_ob->slotinfo[s].slot_type == k_SLOT_TYPE_DYNFILTER) {
						for (item = note->slot[s].firstitem; item; item = item->next){
							t_biquad *bqd = (t_biquad *) item->item;
							if (bqd->filter_type != k_FILTER_NONE && bqd->filter_type != k_FILTER_DISPLAY)
								synchronize_biquad_coeff_from_freq_gain_and_Q(bqd, r_ob->sampling_freq);
						}
					}
	}
	
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_linklyricstoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && is_atom_number(av)) 
		change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_LYRICS);

	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_linknoteheadtoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_NOTEHEAD);
    
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_linknotecolortoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_NOTE_COLOR);
    
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_linkdlcolortoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_DURATIONLINE_COLOR);
    
    return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_linkarticulationstoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_ARTICULATIONS);
    
    return MAX_ERR_NONE;
}




t_max_err notationobj_setattr_linknoteheadsizetoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_NOTE_SIZE);
    
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_linknoteheadadjusttoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_NOTEHEAD_ADJUST);
    
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_linknoteheadfonttoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_NOTEHEAD_FONT);
    
    return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_linkannotationtoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_ANNOTATION);
    
    return MAX_ERR_NONE;
}


t_max_err notationobj_setattr_linkdynamicstoslot(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && is_atom_number(av))
        change_linkto_slot_flag(r_ob, atom_getlong(av) - 1, k_SLOT_LINKAGE_DYNAMICS);
    
    return MAX_ERR_NONE;
}




t_max_err notationobj_setattr_nonantialiasedstaff(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av)
{
	if (ac && av) {
		r_ob->force_non_antialiased_staff_lines = atom_getlong(av);
		if (r_ob->force_non_antialiased_staff_lines) {
			adjust_zoom_for_non_antialiased_lines(r_ob);
			calculate_voice_offsets(r_ob);
		} else {
			r_ob->zoom_y = r_ob->zoom_y_with_antialias;
			r_ob->system_jump = get_system_jump(r_ob);
		}
	}
	return MAX_ERR_NONE;
}

void start_editing_numberslot(t_notation_obj *r_ob, t_object *patcherview, t_notation_item *nitem, long slot_num, t_jrgba slot_text_textcolor)
{
    t_object *textfield;
    t_jgraphics *g;
    t_rect rect;
    textfield = jbox_get_textfield((t_object *) r_ob);
    g = (t_jgraphics*) patcherview_get_jgraphics(patcherview);
    jbox_get_rect_for_view(&r_ob->j_box.l_box.b_ob, patcherview, &rect);
    
    double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
    
    r_ob->is_editing_type = k_NUMBER_IN_SLOT;
    
    object_attr_setlong(r_ob, _sym_fontface, 0);
    textfield_set_wordwrap(textfield, 0);
    textfield_set_autoscroll(textfield, 1);
    textfield_set_textmargins(textfield, r_ob->slot_window_active_x1, r_ob->slot_window_active_y1, rect.width - r_ob->slot_window_active_x2, rect.height - r_ob->slot_window_active_y2);
    textfield_set_justification(textfield, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM);
    textfield_set_textcolor(textfield, &slot_text_textcolor);
    
    jbox_set_fontname((t_object *) r_ob, gensym("Arial"));
    jbox_set_fontsize((t_object *) r_ob, round(7.2 * zoom_y));
    if (r_ob->active_slot_notationitem && get_activeitem_slot_firstitem(r_ob, slot_num) && get_activeitem_slot_firstitem(r_ob, slot_num)->item) {
        char *number_txt = NULL;
        number_slot_to_text_buf(r_ob, get_activeitem_slot_firstitem(r_ob, slot_num), 1, &number_txt, r_ob->slotinfo[slot_num].slot_type, slot_num, true);
        object_method(patcherview, _sym_insertboxtext, r_ob, number_txt);
        bach_freeptr(number_txt);
    } else
        object_method(patcherview, _sym_insertboxtext, r_ob, "");
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}



void start_editing_textslot(t_notation_obj *r_ob, t_object *patcherview, t_notation_item *nitem, long slot_num, t_jrgba slot_text_textcolor)
{
	t_object *textfield;
	t_jgraphics *g;
	t_rect rect;
	textfield = jbox_get_textfield((t_object *) r_ob); 
	g = (t_jgraphics*) patcherview_get_jgraphics(patcherview); 
	jbox_get_rect_for_view(&r_ob->j_box.l_box.b_ob, patcherview, &rect);

	double zoom_y = r_ob->zoom_y * (r_ob->slot_window_zoom / 100.);
	
	if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_TEXT)
		r_ob->is_editing_type = k_TEXT_IN_SLOT;
	else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_LLLL)
		r_ob->is_editing_type = k_LLLL_IN_SLOT;
    else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_DYNAMICS)
        r_ob->is_editing_type = k_DYNAMICS_IN_SLOT;
	
	object_attr_setlong(r_ob, _sym_fontface, 0);
	textfield_set_wordwrap(textfield, 1); 
	textfield_set_autoscroll(textfield, 1);
	textfield_set_textmargins(textfield, r_ob->slot_window_active_x1, r_ob->slot_window_active_y1, rect.width - r_ob->slot_window_active_x2, rect.height - r_ob->slot_window_active_y2);
	textfield_set_textcolor(textfield, &slot_text_textcolor);
	
	jbox_set_fontname((t_object *) r_ob, _llllobj_sym_Courier);
    
    if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_DYNAMICS)
        jbox_set_fontsize((t_object *) r_ob, round(11. * zoom_y));
    else
        jbox_set_fontsize((t_object *) r_ob, round(7.2 * zoom_y));
    
	if (r_ob->active_slot_notationitem && get_activeitem_slot_firstitem(r_ob, slot_num) && get_activeitem_slot_firstitem(r_ob, slot_num)->item) {
		if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_TEXT)
			object_method(patcherview, _sym_insertboxtext, r_ob, (char *)notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item);
        else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_DYNAMICS) {
            t_dynamics *dyn = (t_dynamics *)notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item;
            if (dyn)
                object_method(patcherview, _sym_insertboxtext, r_ob, dyn->text_deparsed ? dyn->text_deparsed->s_name : "");
        } else if (r_ob->slotinfo[slot_num].slot_type == k_SLOT_TYPE_LLLL) {
			char *buf = NULL;
//            llll_to_text_buf_pretty((t_llll *)notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item, &buf, 0, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, 0, NULL);
			llll_to_text_buf((t_llll *)notation_item_get_slot_firstitem(r_ob, nitem, slot_num)->item, &buf, 0, BACH_DEFAULT_MAXDECIMALS, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
			object_method(patcherview, _sym_insertboxtext, r_ob, buf);
			bach_freeptr(buf);
		}
	} else 
		object_method(patcherview, _sym_insertboxtext, r_ob, "");
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}

void end_editing_textfield(t_notation_obj *r_ob)
{
	t_object *textfield = jbox_get_textfield((t_object *) r_ob); 
    textfield_set_justification(textfield, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP);
	r_ob->is_editing_voice_name = -1;
	r_ob->is_editing_type = k_NONE;
	object_method(textfield, _sym_settext, "");
	object_attr_setlong(r_ob, _sym_fontface, 0);
}


// returns: e_actions_upon_change
long handle_note_popup(t_notation_obj *r_ob, t_note *note, long modifiers, e_element_types clipboard_type)
{
	int screen_x, screen_y;
	t_pt screen; 
	int chosenelem = 0, res = 0; 
	
	if (!notation_item_is_selected(r_ob, (t_notation_item *)note) && !notation_item_is_selected(r_ob, (t_notation_item *)note->parent)){
		if (!(modifiers & eShiftKey))
			clear_selection(r_ob);
		notation_item_add_to_preselection(r_ob, (t_notation_item *)note);
		move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_INVOLUTIVE, false, false);
	}
	
	if (r_ob->right_click_directly_pops_out_slot > 0 && r_ob->right_click_directly_pops_out_slot <= CONST_MAX_SLOTS){
		open_slot_window(r_ob, r_ob->right_click_directly_pops_out_slot - 1, (t_notation_item *)note);
		return k_CHANGED_DO_NOTHING;
	}
	
	jmouse_getposition_global(&screen_x, &screen_y);
	screen.x = (double)screen_x;
	screen.y = (double)screen_y;
	build_popup_note_menu(r_ob, note, clipboard_type);
	chosenelem = jpopupmenu_popup(r_ob->popup_note, screen, 0);
	
	if (chosenelem == 1000) {
		if (notation_item_is_selected(r_ob, (t_notation_item *)note->parent) && !(modifiers & eControlKey))
			open_bach_inspector_for_notation_item(r_ob, (t_notation_item *)note->parent);
		else
			open_bach_inspector_for_notation_item(r_ob, (t_notation_item *)note);
		return k_CHANGED_DO_NOTHING;
	}

	// slots
	if (chosenelem > 300 && chosenelem <= 300 + CONST_MAX_SLOTS){
		long chosen_slot = chosenelem - 300;
		open_slot_window(r_ob, chosen_slot - 1, (t_notation_item *)note);
		return k_CHANGED_REDRAW_STATIC_LAYER;
	}
	
	// enharmonicity
	if (chosenelem > 400 && chosenelem <= 400 + CONST_MAX_ENHARMONICITY_OPTIONS){
		long chosen_idx = chosenelem - 401;
		undo_tick_create_for_notation_item(r_ob, (t_notation_item *)note->parent, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
		enharmonically_retranscribe_note(r_ob, note, false, r_ob->current_enharmonic_list_screenmc[chosen_idx], r_ob->current_enharmonic_list_screenacc[chosen_idx]);
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_ENHARMONICALLY_RESPELL_NOTE);
		return k_CHANGED_SEND_BANG;
	}
	
	if (chosenelem == 451) {
		res = lock_selection(r_ob, false);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_LOCK_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 452) {
		res = unlock_selection(r_ob, false);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNLOCK_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 453) {
		res = mute_selection(r_ob, false);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_MUTE_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 454) {
		res = unmute_selection(r_ob, false);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNMUTE_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 455) {
		res = solo_selection(r_ob, false);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_SOLO_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 456) {
		res = unsolo_selection(r_ob, false);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNSOLO_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 461) {
		res = no_solo(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_SOLOS);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 462) {
		res = no_muted(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_MUTES);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 471) {
		res = snap_pitch_to_grid_for_selection(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_SNAP_PITCH_TO_GRID_FOR_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 472) {
		res = reset_selection_enharmonicity(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_RESET_ENHARMONICITY_FOR_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 473 && r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
		return chosenelem; // we pass it through, to perform changes in roll.c
	} else if (chosenelem == 474 && r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
		return chosenelem; // we pass it through, to perform changes in roll.c
	} else if (chosenelem == 475) { // legato
		return chosenelem; // we pass it through 
	} else if (chosenelem == 480) {
		standard_dump_selection(r_ob, r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? 6 : 7, -1, NULL);
		return k_CHANGED_DO_NOTHING;
	} else if (chosenelem >= 600 && chosenelem <= 605) {
		return chosenelem; // we pass it through 
    } else if (chosenelem >= 950 && chosenelem <= 951) {
        return chosenelem; // we pass it through
    } else if (chosenelem >= 501 && chosenelem <= 503) {
        return chosenelem; // we pass it through
    } else if ((chosenelem >= 970 && chosenelem < 1000) || (chosenelem >= 9000 && chosenelem <= 9000 + CONST_MAX_SLOTS + 1) || (chosenelem >= 10000 && chosenelem <= 10000 + CONST_MAX_SLOTS + 1)) {
        return chosenelem; // copy/paste: we pass it through
	}
	
	return k_CHANGED_DO_NOTHING;
}

// returns: e_actions_upon_change
long handle_durationline_popup(t_notation_obj *r_ob, t_duration_line *dl, long modifiers)
{
//    t_note *note = dl->owner;
    int screen_x, screen_y;
    t_pt screen;
    int chosenelem = 0;
    
    jmouse_getposition_global(&screen_x, &screen_y);
    screen.x = (double)screen_x;
    screen.y = (double)screen_y;
    build_popup_durationline_menu(r_ob, dl);
    chosenelem = jpopupmenu_popup(r_ob->popup_durationline, screen, 0);
   
    return chosenelem;
    
    
    return k_CHANGED_DO_NOTHING;
}



long handle_filters_popup(t_notation_obj *r_ob, long modifiers, t_slotitem *clicked_item){
	int screen_x, screen_y;
	t_pt screen; 
	int chosenelem = 0;
	t_biquad *active_filter = NULL;
	
	if (r_ob->active_slot_notationitem && r_ob->active_slot_num >= 0 && r_ob->active_slot_num < CONST_MAX_SLOTS) {
		if (clicked_item)
			active_filter = (t_biquad *) clicked_item->item;
		else if (get_activeitem_activeslot_firstitem(r_ob))
			active_filter = (t_biquad *) get_activeitem_activeslot_firstitem(r_ob)->item;
		
		jmouse_getposition_global(&screen_x, &screen_y);
		screen.x = (double)screen_x;
		screen.y = (double)screen_y;
		build_popup_filters_menu(r_ob, clicked_item);
		chosenelem = jpopupmenu_popup(r_ob->popup_filters, screen, 0);
		
		if (chosenelem >= 2000 && chosenelem <= 2009 && !(active_filter && chosenelem - 2000 == active_filter->filter_type)) {
            undo_tick_create_for_notation_item(r_ob, get_activeitem_undo_item(r_ob), k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
			if (!active_filter) {
				t_slotitem *thisitem = build_slotitem(r_ob, get_activeitem_activeslot(r_ob));
				active_filter = (t_biquad *)bach_newptr(sizeof(t_biquad));
				initialize_biquad(active_filter);
				thisitem->item = active_filter;
				slotitem_append(thisitem);
			}
			active_filter->filter_type = (e_filter_types)(chosenelem - 2000);
			synchronize_biquad_coeff_from_freq_gain_and_Q(active_filter, r_ob->sampling_freq);
			
			if (clicked_item && r_ob->dynfilter_interp_mode == 1) { // dynamic slot and freq/gain/q interpolation: all the filters need to be of the same kind!!!
				t_slotitem *temp;
				for (temp = clicked_item->prev; temp; temp = temp->prev){
					t_biquad *thisbqd = (t_biquad *) temp->item;
					if (thisbqd->filter_type != active_filter->filter_type){
						thisbqd->filter_type = active_filter->filter_type;
						synchronize_biquad_coeff_from_freq_gain_and_Q(thisbqd, r_ob->sampling_freq);
					}
				}
				for (temp = clicked_item->next; temp; temp = temp->next){
					t_biquad *thisbqd = (t_biquad *) temp->item;
					if (thisbqd->filter_type != active_filter->filter_type){
						thisbqd->filter_type = active_filter->filter_type;
						synchronize_biquad_coeff_from_freq_gain_and_Q(thisbqd, r_ob->sampling_freq);
					}
				}
			}
			return k_CHANGED_STANDARD_SEND_BANG;
		}
	}
	
	return k_CHANGED_DO_NOTHING;
}



t_llll *measure_get_aligned_measures_as_llll(t_notation_obj *r_ob, t_measure *meas)
{
    t_llll *out = llll_get();
    if (!meas->prev) {
        // get all first measures
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            llll_appendobj(out, nth_measure_of_scorevoice((t_scorevoice *)voice, 0));
        }
    } else {
        t_measure_end_barline *barline[CONST_MAX_VOICES];
        if (get_all_tuttipoint_barlines(r_ob, meas->prev->end_barline, barline)) {
            for (long i = 0; i < r_ob->num_voices; i++) {
                if (barline[i]->owner && barline[i]->owner->next)
                    llll_appendobj(out, barline[i]->owner->next);
            }
        }
        
    }
    
    return out;
}

// barline must be instantiated with CONST_MAX_VOICES length
char get_all_tuttipoint_barlines(t_notation_obj *r_ob, t_measure_end_barline *ref_barline, t_measure_end_barline **barline)
{
	if (is_barline_tuttipoint(r_ob, ref_barline)) {
		long i;
		t_tuttipoint *tpt = ref_barline->owner->tuttipoint_reference;
		for (i = 0; i < r_ob->num_voices; i++) {
			t_measure *temp = tpt->measure[i];
			while (temp && temp->next && temp->next->tuttipoint_reference == tpt) 
				temp = temp->next;
			barline[i] = temp->end_barline;
		}
		return 1;
	} else
		return 0;
}

long handle_barline_popup(t_notation_obj *r_ob, t_measure *measure, long modifiers){
	int screen_x, screen_y;
	t_pt screen; 
	int chosenelem = 0;
	char new_barline = -1;
	
	if (!notation_item_is_selected(r_ob, (t_notation_item *)measure->end_barline)){
		if (r_ob->selection_type != k_MEASURE_END_BARLINE || !(modifiers & eShiftKey))
			clear_selection(r_ob);
		notation_item_add_to_preselection(r_ob, (t_notation_item *)measure->end_barline);
		move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_INVOLUTIVE, false, false);
	}
	
	jmouse_getposition_global(&screen_x, &screen_y);
	screen.x = (double)screen_x;
	screen.y = (double)screen_y;
	build_popup_barline_menu(r_ob, measure);
	chosenelem = jpopupmenu_popup(r_ob->popup_barline, screen, 0);
	
	switch (chosenelem) {
		case 1200:
			new_barline = k_BARLINE_AUTOMATIC;
			break;
		case 1201:
			new_barline = k_BARLINE_NORMAL;
			break;
		case 1202:
			new_barline = k_BARLINE_DASHED;
			break;
		case 1203:
			new_barline = k_BARLINE_POINTS;
			break;
		case 1204:
			new_barline = k_BARLINE_DOUBLE;
			break;
		case 1205:
			new_barline = k_BARLINE_FINAL;
			break;
		case 1206:
			new_barline = k_BARLINE_HIDDEN;
			break;
		case 1207:
			new_barline = k_BARLINE_SOLID;
			break;
        case 1208:
            new_barline = k_BARLINE_TICK;
            break;
        case 1209:
            new_barline = k_BARLINE_INTERVOICES;
            break;
	}
	
	if (new_barline >= 0) {
		t_measure_end_barline *barline_across[CONST_MAX_VOICES];
		if (r_ob->draw_barlines_across_staves && is_barline_tuttipoint(r_ob, measure->end_barline)) {
			long i;
			get_all_tuttipoint_barlines(r_ob, measure->end_barline, barline_across);
			for (i = 0; i < r_ob->num_voices; i++) {
				undo_tick_create_for_notation_item(r_ob, (t_notation_item *)barline_across[i]->owner, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
				barline_across[i]->barline_type = new_barline;
				recompute_all_for_measure(r_ob, barline_across[i]->owner, false);
			}
		} else {
			undo_tick_create_for_notation_item(r_ob, (t_notation_item *)measure, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
			measure->end_barline->barline_type = new_barline;
			recompute_all_for_measure(r_ob, measure, false);
		}
		
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_CHANGE_BARLINE_TYPE);
		return k_CHANGED_SEND_BANG;
	}
	
	return k_CHANGED_DO_NOTHING;
}


long handle_measure_popup(t_notation_obj *r_ob, t_measure *measure, long modifiers){
	int screen_x, screen_y;
	t_pt screen; 
	int chosenelem = 0, res = 0; 
	
	if (!notation_item_is_selected(r_ob, (t_notation_item *)measure)){
		if (r_ob->selection_type != k_MEASURE || !(modifiers & eShiftKey))
			clear_selection(r_ob);
		notation_item_add_to_preselection(r_ob, (t_notation_item *)measure);
		move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_INVOLUTIVE, false, false);
	}
	
	jmouse_getposition_global(&screen_x, &screen_y);
	screen.x = (double)screen_x;
	screen.y = (double)screen_y;
	build_popup_measure_menu(r_ob, measure);
	chosenelem = jpopupmenu_popup(r_ob->popup_measure, screen, 0);
	
	if (chosenelem == 1000){
		open_bach_inspector_for_notation_item(r_ob, (t_notation_item *)measure);
		return k_CHANGED_DO_NOTHING;
	} else if (chosenelem > 500 && chosenelem <= 518){
		// time signature
		t_timesignature chosen_ts = popup_menu_result_to_timesignature(r_ob, chosenelem);
		t_notation_item *item; 
		for (item = r_ob->firstselecteditem; item; item = item->next_selected){
			if (item->type == k_MEASURE) {
                
                t_voice *voice = (t_voice *)(((t_measure *)item)->voiceparent);
                t_voice *first = voiceensemble_get_firstvoice(r_ob, voice);
                t_voice *last = voiceensemble_get_lastvoice(r_ob, voice);
                
                if (first == last) {
                    undo_tick_create_create_for_selected_notation_item(r_ob, item, k_MEASURE, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
                    measure_set_ts(r_ob, (t_measure *)item, &chosen_ts);
                    recompute_all_for_measure(r_ob, (t_measure *)item, false);
                } else {
                    t_voice *temp;
                    long measure_num = ((t_measure *)item)->measure_number;
                    for (temp = first; temp && temp->number < r_ob->num_voices; temp = voice_get_next(r_ob, temp)) {
                        t_measure *m = nth_measure_of_scorevoice((t_scorevoice *)temp, measure_num);
                        if (m) {
                            undo_tick_create_create_for_selected_notation_item(r_ob, (t_notation_item *)m, k_MEASURE, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
                            measure_set_ts(r_ob, m, &chosen_ts);
                            recompute_all_for_measure(r_ob, m, false);
                        }
                        if (temp == last)
                            break;
                    }
                }
			}
		}
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_CHANGE_TIME_SIGNATURE_FOR_SELECTED_MEASURES);
		return k_CHANGED_SEND_BANG + k_CHANGED_PERFORM_ANALYSIS_AND_CHANGE;
	} else if (chosenelem == 551){ //lock
		res = lock_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_LOCK_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 552){ //unlock
		res = unlock_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNLOCK_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 553){ // mute
		res = mute_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_MUTE_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 554){ // unmute
		res = unmute_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNMUTE_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 555){ // solo
		res = solo_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_SOLO_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 556){ // unsolo
		res = unsolo_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNSOLO_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 570){ // no solo
		res = no_solo(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_SOLOS);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 571){ // no mute
		res = no_muted(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_MUTES);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem >= 600 && chosenelem <= 605) {
		return chosenelem; // we pass it through 
	} else if (chosenelem == 589 || chosenelem == 590) {
		return chosenelem; // we pass it through 
    } else if (chosenelem == 591) {
        return chosenelem; // we pass it through
    } else if (chosenelem == 592) {
        return chosenelem; // we pass it through
    } else if (chosenelem == 150 || chosenelem == 160) {
        return chosenelem; // we pass it through
	} else if (chosenelem == 610) {
		res = lock_rhythmic_trees_in_selection(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_LOCK_RHYTHMIC_TREE_FOR_SELECTION);
		return k_CHANGED_STANDARD_SEND_BANG;
	} else if (chosenelem == 611) {
		res = unlock_rhythmic_trees_in_selection(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNLOCK_RHYTHMIC_TREE_FOR_SELECTION);
		return k_CHANGED_STANDARD_SEND_BANG;
	}
	
	return k_CHANGED_DO_NOTHING;
}

// doesn't take into account clefs and keys (which have to be done separately)
long handle_voice_popup(t_notation_obj *r_ob, t_voice *voice, long modifiers, int *chosenelement)
{
	int screen_x, screen_y;
	t_pt screen; 
	int chosenelem = 0, res = 0; 
	
	if (!notation_item_is_selected(r_ob, (t_notation_item *)voice)){
		if (r_ob->selection_type != k_VOICE || !(modifiers & eShiftKey))
			clear_selection(r_ob);
		notation_item_add_to_preselection(r_ob, (t_notation_item *)voice);
		move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_INVOLUTIVE, false, false);
	}
	
	jmouse_getposition_global(&screen_x, &screen_y);
	screen.x = (double)screen_x;
	screen.y = (double)screen_y;
	build_popup_voice_menu(r_ob, voice);
	chosenelem = jpopupmenu_popup(r_ob->popup_voice, screen, 0);
	if (chosenelement) 
		*chosenelement = chosenelem;
	
	if (chosenelem == 1000){ //inspector
		open_bach_inspector_for_notation_item(r_ob, (t_notation_item *)voice);
		return k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 181){ //lock
		res = lock_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_LOCK_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 182){ //unlock
		res = unlock_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNLOCK_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 183){ // mute
		res = mute_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_MUTE_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 184){ // unmute
		res = unmute_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNMUTE_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 185){
		res = solo_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_SOLO_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 186){
		res = unsolo_selection(r_ob, true);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_UNSOLO_SELECTION);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 191){ // no solo
		res = no_solo(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_SOLOS);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 192){ // no mute
		res = no_muted(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_MUTES);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
    } else if (chosenelem == 4001){ // break voice ensemble
        voiceensemble_break(r_ob, voice, true);
        handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_BREAK_VOICE_ENSEMBLE);
        return k_CHANGED_SEND_BANG;
    } else if (chosenelem == 4000){ // create voice ensemble
        voiceensemble_create_from_selection(r_ob, true);
        handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_CREATE_VOICE_ENSEMBLE);
        return k_CHANGED_SEND_BANG;
	}
	
	return k_CHANGED_DO_NOTHING;
}


long handle_background_popup(t_notation_obj *r_ob, long modifiers, e_element_types clipboard_type)
{
	int screen_x, screen_y;
	t_pt screen; 
	int chosenelem = 0, res = 0; 
	
	clear_selection(r_ob);
	
	jmouse_getposition_global(&screen_x, &screen_y);
	screen.x = (double)screen_x;
	screen.y = (double)screen_y;
	build_popup_background_menu(r_ob, clipboard_type);
	chosenelem = jpopupmenu_popup(r_ob->popup_background, screen, 0);
	
	if (chosenelem == 1001 && r_ob->allow_solo){ // no solo
		res = no_solo(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_SOLOS);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 1002 && r_ob->allow_mute){ // no mute
		res = no_muted(r_ob);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_NO_MUTES);
		return res ? k_CHANGED_SEND_BANG : k_CHANGED_DO_NOTHING;
	} else if (chosenelem == 1010) {
		t_atom arv;
		object_method_typed((t_object *)r_ob, gensym("ceilmeasures"), 0, NULL, &arv);
    } else if (chosenelem == 1020 || chosenelem == 1021) {
        double ms = xposition_to_ms(r_ob, r_ob->j_mousedown_point.x, 1);
        clear_selection(r_ob);
        preselect_notes_in_region(r_ob, chosenelem == 1021 ? 0 : ms, chosenelem == 1021 ? ms : r_ob->length_ms_till_last_note + 100, -100000, 100000, 0, r_ob->num_voices, r_ob->show_durations, r_ob->show_durations);
        if (r_ob->show_markers)
            preselect_markers_in_region(r_ob, chosenelem == 1021 ? 0 : ms, chosenelem == 1021 ? ms : r_ob->length_ms_till_last_note + 100);
        move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_FORCE_SELECT, false, false);
        notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    } else {
        return chosenelem;
    }
	
	return k_CHANGED_DO_NOTHING;
}

long handle_articulations_popup(t_notation_obj *r_ob, t_articulation *art, long modifiers)
{
    int screen_x, screen_y;
    t_pt screen;
    int chosenelem = 0;
    
    jmouse_getposition_global(&screen_x, &screen_y);
    screen.x = (double)screen_x;
    screen.y = (double)screen_y;
    build_popup_articulations_menu(r_ob, art);
    chosenelem = jpopupmenu_popup(r_ob->popup_articulations, screen, 0);
    
    chosenelem -= 1000;
    
    if (chosenelem >= 0 && chosenelem < r_ob->articulations_typo_preferences.num_articulations){
        t_chord *ch = NULL;
        if (art->owner)
            ch = art->owner->type == k_CHORD ? (t_chord *)art->owner : ((t_note *)art->owner)->parent;
        undo_tick_create_for_notation_item(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);

        art->articulation_ID = chosenelem;
        art->need_recompute_position = true;
        if (ch)
            reset_articulation_position_for_chord(r_ob, ch);
        
        handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_CHANGE_ARTICULATION);
        return k_CHANGED_SEND_BANG;
    }
    
    return k_CHANGED_DO_NOTHING;
}


long popup_menu_result_to_clef(t_notation_obj *r_ob, long result){
	switch (result) {
		case 1:		return k_CLEF_G;
		case 2:		return k_CLEF_F;
		case 3:		return k_CLEF_FG;
		case 4:		return k_CLEF_FF;
		case 5:		return k_CLEF_GG;
		case 6:		return k_CLEF_FFG;
		case 7:		return k_CLEF_FGG;
		case 8:		return k_CLEF_FFGG;
// separator
		case 10:	return k_CLEF_G8va;
        case 11:	return k_CLEF_G15ma;
        case 12:	return k_CLEF_G8vb;
        case 13:	return k_CLEF_G15mb;
        case 14:	return k_CLEF_F8va;
        case 15:	return k_CLEF_F15ma;
        case 16:	return k_CLEF_F8vb;
        case 17:	return k_CLEF_F15mb;
// separator
		case 20:	return k_CLEF_SOPRANO;
		case 21:	return k_CLEF_MEZZO;
		case 22:	return k_CLEF_ALTO;
		case 23:	return k_CLEF_TENOR;
		case 24:	return k_CLEF_BARYTONE;
// separator
		case 30:	return k_CLEF_PERCUSSION;
		case 31:	return k_CLEF_NONE;
        case 50:	return k_CLEF_AUTO;
		default:	return k_CLEF_WRONG;
	}
}

t_symbol* popup_menu_result_to_keysymbol(t_notation_obj *r_ob, long result){
	switch (result) {
		case 101:	return gensym("CM");
		case 102:	return gensym("C#M");
		case 103:	return gensym("DbM");
		case 104:	return gensym("DM");
		case 105:	return gensym("EbM");
		case 106:	return gensym("EM");
		case 107:	return gensym("FM");
		case 108:	return gensym("F#M");
		case 109:	return gensym("GbM");
		case 110:	return gensym("GM");
		case 111:	return gensym("AbM");
		case 112:	return gensym("AM");
		case 113:	return gensym("BbM");
		case 114:	return gensym("BM");
		case 115:	return gensym("CbM");
			
		case 201:	return gensym("Cm");
		case 202:	return gensym("C#m");
		case 203:	return gensym("Dm");
		case 204:	return gensym("D#m");
		case 205:	return gensym("Ebm");
		case 206:	return gensym("Em");
		case 207:	return gensym("Fm");
		case 208:	return gensym("F#m");
		case 209:	return gensym("Gm");
		case 210:	return gensym("G#m");
		case 211:	return gensym("Abm");
		case 212:	return gensym("Am");
		case 213:	return gensym("A#m");
		case 214:	return gensym("Bbm");
		case 215:	return gensym("Bm");
			
		default: return NULL;
	}
}

t_timesignature popup_menu_result_to_timesignature(t_notation_obj *r_ob, long result){
	switch (result) {
		case 501: return build_simple_timesignature(r_ob, 2, 2);
		case 502: return build_simple_timesignature(r_ob, 2, 4);
		case 503: return build_simple_timesignature(r_ob, 3, 4);
		case 504: return build_simple_timesignature(r_ob, 4, 4);
		case 505: return build_simple_timesignature(r_ob, 5, 4);
		case 506: return build_simple_timesignature(r_ob, 6, 4);
		case 507: return build_simple_timesignature(r_ob, 3, 8);
		case 508: return build_simple_timesignature(r_ob, 4, 8);
		case 509: return build_simple_timesignature(r_ob, 5, 8);
		case 510: return build_2compound_timesignature(r_ob, 3, 2, 8);
		case 511: return build_2compound_timesignature(r_ob, 2, 3, 8);
		case 512: return build_simple_timesignature(r_ob, 6, 8);
		case 513: return build_simple_timesignature(r_ob, 7, 8);
		case 514: return build_3compound_timesignature(r_ob, 3, 2, 2, 8);
		case 515: return build_3compound_timesignature(r_ob, 2, 3, 2, 8);
		case 516: return build_3compound_timesignature(r_ob, 2, 2, 3, 8);
		case 517: return build_simple_timesignature(r_ob, 9, 8);
		case 518: return build_simple_timesignature(r_ob, 12, 8);
		default: return build_simple_timesignature(r_ob, 4, 4);
	}
}

void initialize_textfield(t_notation_obj *r_ob){
	t_object *textfield;
	textfield = jbox_get_textfield((t_object *) r_ob); 
	if (textfield) {
		jbox_set_fontname((t_object *) r_ob, gensym("Arial"));
		jbox_set_fontsize((t_object *) r_ob, 12);
		
		textfield_set_noactivate(textfield, 1);
		textfield_set_editonclick(textfield, 0); // set it to 0 if you don't want user to edit it in lock mode
		textfield_set_useellipsis(textfield, 1);
		textfield_set_wantsreturn(textfield, 0);
		textfield_set_wordwrap(textfield, 0);
		textfield_set_editonclick(textfield, 0);			// set it to 0 if you don't want user to edit it in lock mode
		textfield_set_textmargins(textfield, 0, 0, 0, 0);	// margin on each side
		textfield_set_textcolor(textfield, &r_ob->j_mainstaves_rgba);// textcolor
		object_method(textfield, gensym("settext"), "");
	}
	
}

void start_editing_voicename(t_notation_obj *r_ob, t_object *patcherview, t_voice *voice){
	t_object *textfield;
	t_jfont *jf_voice_names;
	double top, bottom, text_width, text_height;
	char buf[1000];
	
	textfield = jbox_get_textfield((t_object *) r_ob); 
	
	r_ob->is_editing_type = k_VOICENAME;
	r_ob->is_editing_voice_name = voice->number;
	top = get_staff_top_y(r_ob, voice, true);
	bottom = get_staff_bottom_y(r_ob, voice, true);
	
	object_attr_setlong(r_ob, gensym("fontface"), 0);
	
	jf_voice_names = jfont_create_debug(r_ob->voice_names_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, r_ob->voice_names_font_size * r_ob->zoom_y);
	get_names_as_text(voice->r_it.names, buf, 1000);
	jfont_text_measure(jf_voice_names, buf, &text_width, &text_height);
	
	textfield_set_wordwrap(textfield, 0);
	textfield_set_autoscroll(textfield, 0);
	textfield_set_textmargins(textfield, r_ob->j_inset_x, (top + bottom - text_height)/2, 0, 0);
	textfield_set_textcolor(textfield, &r_ob->j_mainstaves_rgba);
	
	jbox_set_fontname((t_object *) r_ob, gensym("Arial"));
	jbox_set_fontsize((t_object *) r_ob, r_ob->voice_names_font_size * r_ob->zoom_y);
	object_method(patcherview, gensym("insertboxtext"), r_ob, buf);
	
	jfont_destroy_debug(jf_voice_names);
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}

void start_editing_markername(t_notation_obj *r_ob, t_object *patcherview, t_marker *marker, double textfield_left_position){
	t_object *textfield;
	double top, left;
	char buf[1000];
	
	if (marker->role != k_MARKER_ROLE_NONE)
		return;
	
	textfield = jbox_get_textfield((t_object *) r_ob); 
	
	object_attr_setlong(r_ob, gensym("fontface"), 1);
	
	r_ob->is_editing_type = k_MARKERNAME;
	r_ob->is_editing_marker = marker;
	top = r_ob->j_inset_y + 10 * r_ob->zoom_y + notationobj_get_marker_voffset(r_ob, marker);
	left = textfield_left_position; 
	
	textfield_set_wordwrap(textfield, 0);
	textfield_set_autoscroll(textfield, 0);
	textfield_set_textmargins(textfield, left, top, 0, 0);
	textfield_set_textcolor(textfield, &r_ob->j_selection_rgba);
	
	get_names_as_text(marker->r_it.names, buf, 1000);
	jbox_set_fontname((t_object *) r_ob, gensym("Arial"));
	jbox_set_fontsize((t_object *) r_ob, r_ob->markers_font_size * r_ob->zoom_y);
	object_method(patcherview, gensym("insertboxtext"), r_ob, buf);
	
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}


void start_editing_lyrics(t_notation_obj *r_ob, t_object *patcherview, t_chord *chord){
	t_object *textfield;
	double top, left;
	
	if (notation_item_is_globally_locked(r_ob, (t_notation_item *)chord))
		return;
	
	textfield = jbox_get_textfield((t_object *) r_ob); 
	
	object_attr_setlong(r_ob, gensym("fontface"), 0);
	
	r_ob->is_editing_type = k_LYRICS;
	r_ob->is_editing_chord = chord;
	r_ob->is_editing_slot_number = r_ob->link_lyrics_to_slot - 1;

	top = get_staff_bottom_y(r_ob, (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? (t_voice *) chord->voiceparent : (t_voice *) chord->parent->voiceparent), false) - r_ob->lyrics_uy_pos * r_ob->zoom_y;
	left = (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? onset_to_xposition_roll(r_ob, chord->onset, NULL) : unscaled_xposition_to_xposition(r_ob, chord_get_alignment_ux(r_ob, chord))) 
				+ chord->lyrics->lyrics_ux_shift * r_ob->zoom_y;
	if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
		left += (chord->direction == 1 ? -0.5 : 0.5) * get_principal_notehead_uwidth(r_ob, chord) * r_ob->zoom_y;
	
	textfield_set_wordwrap(textfield, 0);
	textfield_set_autoscroll(textfield, 0);
	textfield_set_textmargins(textfield, left, top, 0, 0);
	textfield_set_textcolor(textfield, &r_ob->j_lyrics_rgba);
	
	jbox_set_fontname((t_object *) r_ob, gensym("Arial"));
	jbox_set_fontsize((t_object *) r_ob, r_ob->lyrics_font_size * r_ob->zoom_y);
	
	if (true) {
		long len = chord->lyrics->label ? strlen(chord->lyrics->label) : 0;
		char *oklyrics = (char *) bach_newptr(len+2);
		if (chord->lyrics->label)
			strncpy(oklyrics, chord->lyrics->label, len);
		oklyrics[len] = oklyrics[len + 1] = 0;
		if (chord->lyrics->lyrics_dashed_extension)
			oklyrics[len] = '-';
		
		object_method(patcherview, gensym("insertboxtext"), r_ob, oklyrics);
		bach_freeptr(oklyrics);
	}
	
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}


void start_editing_dynamics(t_notation_obj *r_ob, t_object *patcherview, t_chord *chord)
{
    t_object *textfield;
    double top, left;
    
    if (notation_item_is_globally_locked(r_ob, (t_notation_item *)chord))
        return;
    
    textfield = jbox_get_textfield((t_object *) r_ob);
    
    object_attr_setlong(r_ob, gensym("fontface"), 0);
    
    r_ob->is_editing_type = k_DYNAMICS;
    r_ob->is_editing_chord = chord;
    r_ob->is_editing_slot_number = r_ob->link_dynamics_to_slot - 1;
    
    top = get_staff_bottom_y(r_ob, (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? (t_voice *) chord->voiceparent : (t_voice *) chord->parent->voiceparent), false) - r_ob->dynamics_uy_pos * r_ob->zoom_y - 8 * r_ob->zoom_y;
    left = chord_get_alignment_x(r_ob, chord) - get_principal_notehead_uwidth(r_ob, chord) * r_ob->zoom_y;
    
    textfield_set_wordwrap(textfield, 0);
    textfield_set_autoscroll(textfield, 0);
    textfield_set_textmargins(textfield, left, top, 0, 0);
    textfield_set_textcolor(textfield, &r_ob->j_dynamics_rgba);
    
    jbox_set_fontname((t_object *) r_ob, _llllobj_sym_Courier);
    jbox_set_fontsize((t_object *) r_ob, 11 * 1.25 * r_ob->zoom_y);
    
    if (r_ob->is_editing_slot_number >= 0 && r_ob->is_editing_slot_number < CONST_MAX_SLOTS) {
        t_notation_item *it = notation_item_get_bearing_dynamics(r_ob, (t_notation_item *)chord, r_ob->is_editing_slot_number);
        t_slotitem *slit = it ? nth_slotitem(r_ob, it, r_ob->is_editing_slot_number, 0) : NULL;
        if (slit && r_ob->slotinfo[r_ob->is_editing_slot_number].slot_type == k_SLOT_TYPE_DYNAMICS) {
            t_dynamics *dyn = (t_dynamics *)slit->item;
            object_method(patcherview, gensym("insertboxtext"), r_ob, dyn->text_deparsed ? dyn->text_deparsed->s_name : "");
        } else {
            if (chord && chord->firstnote) {
                object_method(patcherview, gensym("insertboxtext"), r_ob, "");
            }
        }
    }
    
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}




/*
t_pt attribute_to_edit_to_pt(t_notation_obj *r_ob, t_object *view, t_bach_attribute *attr){
	t_rect rect;
	t_pt res;
	jbox_get_rect_for_view(&r_ob->j_box.l_box.b_ob, view, &rect);

	double column2_x = MIN(rect.width * CONST_BACH_INSPECTOR_ITEM_COLUMN2_MAX_REL_POS, CONST_BACH_INSPECTOR_ITEM_UX_COLUMN2 * r_ob->zoom_y);
	double shift = r_ob->bach_inspector_scrollbar_delta_y / r_ob->zoom_y;
	double attr_y = (attr->idx * CONST_BACH_INSPECTOR_ITEM_UY_STEP + (CONST_BACH_INSPECTOR_ITEM_UY_STEP - CONST_BACH_INSPECTOR_ITEM_LINE_UHEIGHT) + CONST_BACH_INSPECTOR_ITEM_UY_START_PAD) * r_ob->zoom_y - shift;
//	double attr_y = (attr->idx * CONST_BACH_INSPECTOR_ITEM_UY_STEP + CONST_BACH_INSPECTOR_ITEM_UY_START_PAD) * r_ob->zoom_y - shift;
	res.x = column2_x;
	res.y = attr_y;
	return res;
} */

t_bach_attribute *pt_to_attribute_to_edit(t_bach_inspector_manager *man, t_object *view, t_pt pt){
	t_rect rect;
	jbox_get_rect_for_view(&((t_jbox *)man->inspector_ui)->b_ob, view, &rect);
	double zoom = CONST_BACH_INSPECTOR_DEFAULT_ZOOM;

	double column2_x = MIN(rect.width * CONST_BACH_INSPECTOR_ITEM_COLUMN2_MAX_REL_POS, CONST_BACH_INSPECTOR_ITEM_UX_COLUMN2 * zoom);
	double shift = man->bach_inspector_scrollbar_delta_y / zoom;
	long idx = floor(((pt.y/zoom) - CONST_BACH_INSPECTOR_ITEM_UY_START_PAD + shift)/CONST_BACH_INSPECTOR_ITEM_UY_STEP);

	if (((pt.y/zoom) - CONST_BACH_INSPECTOR_ITEM_UY_START_PAD + shift) - idx * CONST_BACH_INSPECTOR_ITEM_UY_STEP < (CONST_BACH_INSPECTOR_ITEM_UY_STEP - CONST_BACH_INSPECTOR_ITEM_LINE_UHEIGHT))
		return NULL; // we've clicked above the attribute line
	
	if (pt.x > column2_x && idx >= 0 && idx < man->attr_manager->num_attr[man->active_bach_inspector_obj_type] &&
		(!man->there_is_miniature_in_inspector || pt.x < man->active_inspector_miniature_rect.x))
		return &man->attr_manager->attr[man->active_bach_inspector_obj_type][idx];
	
	return NULL;
}


t_jrgba get_bach_attribute_as_color(t_bach_inspector_manager *man, void *elem, t_bach_attribute *attr)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	long ac = 0;
	t_atom *av = NULL;
	t_jrgba res = build_jrgba(0, 0, 0, 1);
	
	if (attr->getter)
		(*attr->getter)(r_ob, elem, attr, &ac, &av);
	else 
		bach_default_get_bach_attr(r_ob, elem, attr, &ac, &av);
	
	if (ac >= 3)
		res = build_jrgba(atom_getfloat(av), atom_getfloat(av+1), atom_getfloat(av+2), ac >= 4 ? atom_getfloat(av+3) : 1);

	if (av)
		bach_freeptr(av);
		
	return res;
}


char *get_bach_attribute_as_character(t_bach_inspector_manager *man, void *elem, t_bach_attribute *attr)
{
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	long ac = 0;
	t_atom *av = NULL;
	char *text = (char *)bach_newptr(2 * sizeof(char));
	
	if (attr->getter)
		(*attr->getter)(r_ob, elem, attr, &ac, &av);
	else 
		bach_default_get_bach_attr(r_ob, elem, attr, &ac, &av);
	
	text[0] = ac ? (char)atom_getlong(av) : 0;
	text[1] = 0;

	bach_freeptr(av);

	return text;
}


char *get_bach_attribute_as_string(t_bach_inspector_manager *man, void *elem, t_bach_attribute *attr)
{
    if (!elem) {
        char *res = (char *)bach_newptr(2*sizeof(char));
        res[0] = 0;
        return res;
    }
    
    t_notation_obj *r_ob = (man->bach_managing ? (t_notation_obj *)man->owner : NULL);
	long ac = 0;
	t_atom *av = NULL;
	char *text = NULL;
	long size;
	
	if (attr->getter)
		(*attr->getter)(man, elem, attr, &ac, &av);
	else 
		bach_default_get_bach_attr(r_ob, elem, attr, &ac, &av);
		
	atom_gettext_debug(ac, av, &size, &text, 0);

/*	t_llll *ll = llllobj_parse_llll((t_object *)r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
	if (ll) {
		llll_to_text_buf(ll, &text, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
		llll_free(ll);
	} else {
		text = (char *)bach_newptr(1 * sizeof(char));
		text[0] = 0;
	} */
	
	bach_freeptr(av);
	
	return text;
}

void start_editing_bach_attribute(t_notation_obj *r_ob, t_bach_inspector_manager *man, t_object *patcherview, t_bach_attribute *attr){
	t_object *textfield;
	t_jrgba textcolor = CONST_BACH_INSPECTOR_TEXT_COLOR;
	void *elem = man->active_bach_inspector_item;
	t_rect rect;
	double zoom = CONST_BACH_INSPECTOR_DEFAULT_ZOOM;
	t_object *object_owning_textfield = (t_object *)man->inspector_ui;

	jbox_get_rect_for_view(&man->inspector_ui->u_box.b_ob, patcherview, &rect);

	double x1 = MIN(rect.width * CONST_BACH_INSPECTOR_ITEM_COLUMN2_MAX_REL_POS, CONST_BACH_INSPECTOR_ITEM_UX_COLUMN2 * zoom);
	double y1 = (CONST_BACH_INSPECTOR_ITEM_UY_START_PAD + attr->idx * CONST_BACH_INSPECTOR_ITEM_UY_STEP + (CONST_BACH_INSPECTOR_ITEM_UY_STEP - CONST_BACH_INSPECTOR_ITEM_LINE_UHEIGHT)) * zoom - man->bach_inspector_scrollbar_delta_y;
    double y_bottom_margin = rect.height - y1 - CONST_BACH_INSPECTOR_ITEM_UY_STEP * zoom;
    
	textfield = jbox_get_textfield(object_owning_textfield); 

	if (man->inspector_ui) {
		man->inspector_ui->edited_attribute = attr;
	} else {
		r_ob->is_editing_type = k_BACH_INSPECTOR_ITEM;
		man->is_editing_attribute = attr;
	}
	
	object_attr_setlong(object_owning_textfield, gensym("fontface"), 0);
	
	textfield_set_wordwrap(textfield, 0);
//    textfield_set_wantsreturn(textfield, 1);
	textfield_set_autoscroll(textfield, 1);
    textfield_set_textmargins(textfield, x1, y1, 0, y_bottom_margin); //0);
	textfield_set_textcolor(textfield, &textcolor);
	
	jbox_set_fontname(object_owning_textfield, gensym("Arial"));
	jbox_set_fontsize(object_owning_textfield, CONST_BACH_INSPECTOR_TEXT_FONT_SIZE * zoom);
	
	char *text = attr->display_type == k_BACH_ATTR_DISPLAY_CHAR ? get_bach_attribute_as_character(man, elem, attr) : get_bach_attribute_as_string(man, elem, attr);

	object_method(patcherview, gensym("insertboxtext"), object_owning_textfield, text);
	bach_freeptr(text);
	
	if (man->inspector_ui)
		jbox_redraw((t_jbox *)man->inspector_ui);
	else
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}


void notation_item_free(t_notation_item *it)
{
	// keeping label families synchronized
	remove_label_families_data_for_notation_item(it);

	llll_free(it->names);
	llll_free(it->label_families);
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

void notationobj_preschedule_end(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    r_ob->preschedule_cursor = NULL;
    r_ob->playing = false;
    notationobj_clear_prescheduled_events(r_ob);
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
}



void notationobj_free(t_notation_obj *r_ob)
{
	long i;
	
    r_ob->freeing = 1; // we're starting to free everything
    
	jbox_free(&r_ob->j_box.l_box);
	
	
	// ************************
	// FREEING ALLOCATED MEMORY
	// ************************
	
	// Voice-related stuff
	bach_freeptr(r_ob->clefs_as_symlist);
	bach_freeptr(r_ob->keys_as_symlist);
	bach_freeptr(r_ob->hidevoices_as_charlist);
	bach_freeptr(r_ob->midichannels_as_longlist);
	bach_freeptr(r_ob->voiceuspacing_as_floatlist);
	bach_freeptr(r_ob->show_measure_numbers);
	bach_freeptr(r_ob->full_acc_repr);
	bach_freeptr(r_ob->chord_play_cursor);
    bach_freeptr(r_ob->tempo_play_cursor);
    bach_freeptr(r_ob->measure_play_cursor);
    bach_freeptr(r_ob->voice_part);

	// Slot-related stuff
	bach_freeptr(r_ob->background_slots);
	bach_freeptr(r_ob->popup_menu_slots);

	free_slotinfos(r_ob);
	bach_freeptr(r_ob->slotinfo);

	// Prevent-editing-related stuff
	bach_freeptr(r_ob->prevent_editing_atom);

	// Attribute manager
	bach_freeptr(r_ob->m_inspector.attr_manager);

	// ************************
	// FREEING MUTEXES AND QELEMS
	// ************************
	
	if (r_ob->c_general_mutex)
		systhread_mutex_free_debug(r_ob->c_general_mutex);

    if (r_ob->c_deparse_mutex)
        systhread_mutex_free_debug(r_ob->c_deparse_mutex);

	if (r_ob->c_markers_mutex)
		systhread_mutex_free_debug(r_ob->c_markers_mutex);

	if (r_ob->c_undo_mutex)
		systhread_mutex_free_debug(r_ob->c_undo_mutex);

	// free our qelem
	if (r_ob->n_qelem_send_rebuild_done)
		qelem_free_debug(r_ob->n_qelem_send_rebuild_done);
	
	
	// **************************
	// FREEING LLLLS IN STRUCTURE
	// **************************

	if (r_ob->notes_being_played)
		llll_free(r_ob->notes_being_played);

	if (r_ob->stafflines_as_llll)
		llll_free(r_ob->stafflines_as_llll);

	if (r_ob->voicenames_as_llll)
		llll_free(r_ob->voicenames_as_llll);
		
	if (r_ob->loop_region_as_llll)
		llll_free(r_ob->loop_region_as_llll);

	if (r_ob->constraint_pitches_when_editing)
		llll_free(r_ob->constraint_pitches_when_editing);
		
    // default things
    llll_free(r_ob->default_noteslots);
    
	llll_free(r_ob->selected_slot_items);

	clear_undo_redo_llll(r_ob, k_UNDO);
	clear_undo_redo_llll(r_ob, k_REDO);
	llll_free(r_ob->undo_llll);
	llll_free(r_ob->redo_llll);
	llll_free(r_ob->undo_notation_items_under_tick);
    llll_free(r_ob->undo_information_whose_path_need_to_be_checked);

    notationobj_clear_prescheduled_events(r_ob);
    llll_free(r_ob->to_preschedule);
    
    if (r_ob->notation_cursor.touched_measures)
        llll_free(r_ob->notation_cursor.touched_measures);
	
	// **************************
	// OBSOLETE STUFF
	// **************************	

	// Obsolete stuff, kept for compatibility with old undo system
	// freeing old undo/redo lllls
	
	
	
	// **************************
	// FREEING SURFACES
	// **************************	
	

	if (r_ob->quarternotehead_surface)
		jgraphics_surface_destroy(r_ob->quarternotehead_surface);
	if (r_ob->selected_quarternotehead_surface)
		jgraphics_surface_destroy(r_ob->selected_quarternotehead_surface);
	if (r_ob->solo_quarternotehead_surface)
		jgraphics_surface_destroy(r_ob->solo_quarternotehead_surface);
	if (r_ob->lock_quarternotehead_surface)
		jgraphics_surface_destroy(r_ob->lock_quarternotehead_surface);
	if (r_ob->mute_quarternotehead_surface)
		jgraphics_surface_destroy(r_ob->mute_quarternotehead_surface);

	if (r_ob->clef_gradient_surface)
		jgraphics_surface_destroy(r_ob->clef_gradient_surface);
	
	// **************************
	// MISCELLANEA
	// **************************	
	
    // freeing external editor
    object_free_debug(r_ob->m_editor);

    // freeing typo pref
    bach_freeptr(r_ob->articulations_typo_preferences.artpref);
    bach_freeptr(r_ob->noteheads_typo_preferences.nhpref);
    
	destroy_popup_menus(r_ob);
	clear_all_groups(r_ob);
	clear_all_markers(r_ob);
	
	if (r_ob->n_lexpr)
		lexpr_free(r_ob->n_lexpr);
	
	shashtable_free(r_ob->IDtable);
	
	free_all_label_families(&r_ob->m_labels);
	llll_free(r_ob->m_labels.families);

	if (r_ob->m_inspector.inspector_patcher)
		object_free(r_ob->m_inspector.inspector_patcher);
	
	llllobj_jbox_free((t_llllobj_jbox *) r_ob); // free the llll stuff
}


// returns the 1-based position of the tempo in the owner
long get_tempo_position(t_notation_obj *r_ob, t_tempo *tp){
	t_tempo *temp;
	long i;
	for (i = 1, temp = tp->owner->firsttempo; temp; temp = temp->next, i++){
		if (temp == tp)
			return i;
	}
	return 0;
}

// returns the 1-based position of the note inside its chord
long note_get_position(t_notation_obj *r_ob, t_note *nt){
	t_note *temp;
	long i;
	for (i = 1, temp = nt->parent->firstnote; temp; temp = temp->next, i++){
		if (temp == nt)
			return i;
	}
	return 0;
}

// returns the 1-based position of the note inside its chord
long get_marker_position(t_notation_obj *r_ob, t_marker *mk){
	t_marker *temp;
	long i;
	for (i = 1, temp = r_ob->firstmarker; temp; temp = temp->next, i++){
		if (temp == mk)
			return i;
	}
	return 0;
}


// returns the 1-based index of the pitch-breakpoint (note head DOES count! so first non-trivial breakpoint is the second breakpoint)
long get_breakpoint_position(t_notation_obj *r_ob, t_bpt *bpt){
	t_bpt *temp;
	long i;
	for (i = 1, temp = bpt->owner->firstbreakpoint; temp; temp = temp->next, i++){
		if (temp == bpt)
			return i;
	}
	return 0;
}

// returns the 1-based (!!!)position of the chord in the parent: either rollvoice or measure (0 if chord is NOT in the voice)
long chord_get_position(t_notation_obj *r_ob, t_chord *chord){
	t_chord *ch;
	long i;
	for (i = 1, ch = (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? chord->voiceparent->firstchord : chord->parent->firstchord); ch; ch = ch->next, i++){
		if (ch == chord)
			return i;
	}
	return 0;
}



t_llll *chord_get_path_in_notationobj(t_notation_obj *r_ob, t_chord *chord)
{
	t_llll *out = llll_get();
	if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL){
		long voice = chord->voiceparent->v_ob.number + 1;
		long chord_position = chord_get_position(r_ob, chord);
		llll_appendlong(out, voice, 0, WHITENULL_llll);
		llll_appendlong(out, chord_position, 0, WHITENULL_llll);
	} else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE){
		long voice = chord->parent->voiceparent->v_ob.number + 1;
		long measure = chord->parent->measure_number + 1;
		long chord_position = chord_get_position(r_ob, chord);
		llll_appendlong(out, voice, 0, WHITENULL_llll);
		llll_appendlong(out, measure, 0, WHITENULL_llll);
		llll_appendlong(out, chord_position, 0, WHITENULL_llll);
	}
	return out;
}

t_llll *note_get_path_in_notationobj(t_notation_obj *r_ob, t_note *note)
{
	t_llll *out = llll_get();
	if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL){
		long voice = note->parent->voiceparent->v_ob.number + 1;
		long chord_position = chord_get_position(r_ob, note->parent);
		long note_position = note_get_position(r_ob, note);
		llll_appendlong(out, voice, 0, WHITENULL_llll);
		llll_appendlong(out, chord_position, 0, WHITENULL_llll);
		llll_appendlong(out, note_position, 0, WHITENULL_llll);
	} else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE){
		long voice = note->parent->parent->voiceparent->v_ob.number + 1;
		long measure = note->parent->parent->measure_number + 1;
		long chord_position = chord_get_position(r_ob, note->parent);
		long note_position = note_get_position(r_ob, note);
		llll_appendlong(out, voice, 0, WHITENULL_llll);
		llll_appendlong(out, measure, 0, WHITENULL_llll);
		llll_appendlong(out, chord_position, 0, WHITENULL_llll);
		llll_appendlong(out, note_position, 0, WHITENULL_llll);
	}
	return out;
}


t_llll *tempo_get_path_in_notationobj(t_notation_obj *r_ob, t_tempo *tempo)
{
    t_llll *out = llll_get();
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE){
        long voice = tempo->owner->voiceparent->v_ob.number + 1;
        long measure = tempo->owner->measure_number + 1;
        long tempo_position = get_tempo_position(r_ob, tempo);
        llll_appendlong(out, voice, 0, WHITENULL_llll);
        llll_appendlong(out, measure, 0, WHITENULL_llll);
        llll_appendlong(out, tempo_position, 0, WHITENULL_llll);
    }
    return out;
}

t_llll *measure_get_path_in_notationobj(t_notation_obj *r_ob, t_measure *meas)
{
    t_llll *out = llll_get();
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE){
        long voice = meas->voiceparent->v_ob.number + 1;
        long measure = meas->measure_number + 1;
        llll_appendlong(out, voice, 0, WHITENULL_llll);
        llll_appendlong(out, measure, 0, WHITENULL_llll);
    }
    return out;
}

t_llll *get_tied_notes_sequence_path_in_notationobj(t_notation_obj *r_ob, t_note *note){
	t_note *note1 = note_get_first_in_tieseq(note);
	t_note *note2 = note_get_last_in_tieseq(note);
	t_note *temp;
	t_llll *out = llll_get();
	for (temp = note1; temp && temp != WHITENULL; temp = temp->tie_to) {
		llll_appendllll(out, note_get_path_in_notationobj(r_ob, temp), 0, WHITENULL_llll);
		if (temp == note2)
			break;
	}
	return out;
}


t_llll *get_tied_chords_sequence(t_notation_obj *r_ob, t_chord *chord){
    t_chord *chord1 = chord_get_first_in_tieseq(chord);
    t_chord *chord2 = chord_get_last_in_tieseq(chord);
    t_chord *temp;
    t_llll *out = llll_get();
    for (temp = chord1; temp; temp = chord_get_next(temp)) {
        llll_appendobj(out, temp);
        if (temp == chord2)
            break;
    }
    return out;
}

t_llll *get_tied_chords_sequence_path_in_notationobj(t_notation_obj *r_ob, t_chord *chord){
	t_chord *chord1 = chord_get_first_in_tieseq(chord);
	t_chord *chord2 = chord_get_last_in_tieseq(chord);
	t_chord *temp;
	t_llll *out = llll_get();
	for (temp = chord1; temp; temp = chord_get_next(temp)) {
		llll_appendllll(out, chord_get_path_in_notationobj(r_ob, temp), 0, WHITENULL_llll);
		if (temp == chord2)
			break;
	}
	return out;
}

t_llll *get_rests_sequence(t_notation_obj *r_ob, t_chord *chord){
    t_chord *chord1 = rest_get_first_in_seq(chord, 0);
    t_chord *chord2 = rest_get_last_in_seq(chord, 0);
    t_chord *temp;
    t_llll *out = llll_get();
    for (temp = chord1; temp; temp = chord_get_next(temp)) {
        llll_appendobj(out, temp);
        if (temp == chord2)
            break;
    }
    return out;
}

t_llll *get_rests_sequence_path_in_notationobj(t_notation_obj *r_ob, t_chord *chord){
	t_chord *chord1 = rest_get_first_in_seq(chord, 0);
	t_chord *chord2 = rest_get_last_in_seq(chord, 0);
	t_chord *temp;
	t_llll *out = llll_get();
	for (temp = chord1; temp; temp = chord_get_next(temp)) {
		llll_appendllll(out, chord_get_path_in_notationobj(r_ob, temp), 0, WHITENULL_llll);
		if (temp == chord2)
			break;
	}
	return out;
}


// if mode = 1 it's clipped between start_ms and end_ms
t_llll *get_groups_for_dump_as_llll(t_notation_obj *r_ob, char mode, double start_ms, double end_ms){
	t_llll *outlist = llll_get();
	t_group *gr;
	llll_appendsym(outlist, _llllobj_sym_groups, 0, WHITENULL_llll);
	for (gr = r_ob->firstgroup; gr; gr = gr->next) {
		t_llll *thisgroup = llll_get();
		t_notation_item *el;
		for (el = gr->firstelem; el; el = el->next_group_item)
			if (el->type == k_CHORD)
				if (mode != 1 || (((t_chord *)el)->onset >= start_ms && ((t_chord *)el)->onset <= end_ms))
					llll_appendllll(thisgroup, chord_get_path_in_notationobj(r_ob, (t_chord *)el), 0, WHITENULL_llll);
		if (thisgroup->l_size <= 1)	// doesn't form a group
			llll_free(thisgroup);
		else
			llll_appendllll(outlist, thisgroup, 0, WHITENULL_llll);
	}
	return outlist;
}



double get_marker_ux_position(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
        return (r_ob->timepoint_to_unscaled_xposition)(r_ob, tp, false, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS);
    } else {
        return ms_to_unscaled_xposition(r_ob, marker->position_ms, 1);
    }
}


double get_marker_ms_position(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        return unscaled_xposition_to_ms(r_ob, get_marker_ux_position(r_ob, marker), 1);
    } else {
        return marker->position_ms;
    }
}



// if mode == 1 it's clipped between start_ms and end_ms
// if mode == 2 only selected markers are output
// if mode == 3 both things are done
// start_meas_num is used only if for_what = k_CONSIDER_FOR_SUBDUMPING, and bach.score is involved
t_llll *get_markers_as_llll(t_notation_obj *r_ob, char mode, double start_ms, double end_ms, char namefirst, char for_what, long start_meas_num){
	t_llll *outlist = llll_get();
	t_marker *marker = r_ob->firstmarker;
	llll_appendsym(outlist, _llllobj_sym_markers, 0, WHITENULL_llll);
	for (marker = r_ob->firstmarker; marker; marker = marker->next) {
        if (mode >= 2 && !notation_item_is_selected(r_ob, (t_notation_item *)marker))
            continue;

        double ms = marker->position_ms;
		if ((mode % 2 == 0) || (ms >= start_ms && ms <= end_ms)) {
            
			t_llll *thisel = llll_get();
			
			if (namefirst) 
				llll_append_notation_item_name(thisel, (t_notation_item *)marker);
			
			if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE && for_what != k_CONSIDER_FOR_SCORE2ROLL){
				t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
				if (for_what == k_CONSIDER_FOR_SUBDUMPING)
					tp.measure_num -= start_meas_num;
				t_llll *tp_as_llll = get_timepoint_as_llll(r_ob, tp);
				llll_appendllll(thisel, tp_as_llll, 0, WHITENULL_llll);
			} else {
				llll_appenddouble(thisel, for_what == k_CONSIDER_FOR_SUBDUMPING ? ms - start_ms : ms, 0, WHITENULL_llll);
			}
			
			if (!namefirst) 
				llll_append_notation_item_name(thisel, (t_notation_item *)marker);
			
			llll_appendsym(thisel, marker_role_to_sym(marker->role), 0, WHITENULL_llll);
			if (marker->role != k_MARKER_ROLE_NONE && marker->content)
				llll_appendllll_clone(thisel, marker->content, 0, WHITENULL_llll, NULL);

			if (for_what == k_CONSIDER_FOR_UNDO)
				llll_appendllll(thisel, get_ID_as_llll((t_notation_item *)marker), 0, WHITENULL_llll);
			
			llll_appendllll(outlist, thisel, 0, WHITENULL_llll);
		}
	}
	return outlist;
}

// use command_number = -1 for standard dump
char standard_dump_selection(t_notation_obj *r_ob, long outlet, long command_number, delete_item_fn delete_item_method, t_llll *forced_routers)
{
    t_notation_item *item; // *nextitem;
    
    // Important: selection might change due to lambda stuff, etc. New selection will be appended at the end.
    // Hence we break after the last selected item
    t_notation_item *lastselected = r_ob->lastselecteditem;
    for (item = r_ob->firstselecteditem; item; ) {
        r_ob->selectioncursor = item->next_selected;
//        nextitem = item->next_selected; // item might be deleted, so that might be nice to keep the pointer to nextitem.
                                        // but what if nextitem is ALSO deleted???
		if (item->type == k_NOTE)
			send_note_as_llll((t_notation_obj *) r_ob, (t_note *)item, outlet, k_CONSIDER_FOR_EVALUATION, command_number, forced_routers);
		else if (item->type == k_CHORD)
			send_chord_as_llll((t_notation_obj *) r_ob, (t_chord *)item, outlet, k_CONSIDER_FOR_EVALUATION, command_number, forced_routers);
		else if (item->type == k_MARKER && command_number < 0)
			send_marker_as_llll(r_ob, (t_marker *) item, true, outlet, forced_routers);
		else if (item->type == k_MEASURE) {
			t_chord *ch;
			for (ch = ((t_measure *)item)->firstchord; ch; ch = ch->next)
				send_chord_as_llll((t_notation_obj *) r_ob, ch, outlet, k_CONSIDER_FOR_EVALUATION, command_number, forced_routers);
		}
        
        if (item == lastselected)
            break;
        
//        item = nextitem;
        item = r_ob->selectioncursor;
	}
	
	char changed = 0, need_check_scheduling = 0;
	if (delete_item_method) {
		// We might need to delete some items, which have been marked for deletion but which could NOT be deleted, due to the 
		// fact that they were iterated upon...
		
		lock_general_mutex(r_ob);
		for (item = r_ob->firstselecteditem; item; item = item->next_selected)
			if (item->flags & k_FLAG_TO_BE_DELETED)
                changed |= (delete_item_method)(r_ob, item, &need_check_scheduling);
		
		if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
			if (changed) recompute_total_length(r_ob);
			if (need_check_scheduling) check_correct_scheduling(r_ob, false);
		} else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
			if (need_check_scheduling) check_correct_scheduling(r_ob, false);
		}
		unlock_general_mutex(r_ob);
		
		if (changed) handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_DELETE_SELECTION);
	}
	return changed;
}

t_max_err notationobj_setattr_showlyrics(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	if (ac && av) {
		long z = atom_getlong(av); 
		r_ob->show_lyrics = CLAMP(z, 0, 1);
		if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
			object_attr_setdisabled((t_object *)r_ob, gensym("showlyricswordextensions"), z == 0);
		implicitely_recalculate_all(r_ob, false);
		notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	}
	return MAX_ERR_NONE;
}

t_max_err notationobj_setattr_ruler(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
    if (ac && av) {
        long z = atom_getlong(av);
        r_ob->ruler = CLAMP(z, 0, 3);
        object_attr_setdisabled((t_object *)r_ob, gensym("rulerlabels"), z == 0);
        notationobj_redraw(r_ob);
    }
    return MAX_ERR_NONE;
}

// beware!!! if (force_assign_if_elem_is_wrong) is defined, this is destructive on elem: changes elem if not long or llll,
// list is the overall list of elems (one for each voice), and is accounted for only if force_assign_if_elem_is_wrong is true
void set_stafflines_to_voice_from_llllelem(t_notation_obj *r_ob, t_voice *voice, t_llllelem *elem, char force_assign_if_elem_is_wrong, t_llll *list){
	if (elem && hatom_gettype(&elem->l_hatom) == H_LONG) {
		long num = CLAMP(hatom_getlong(&elem->l_hatom), 0, CONST_MAX_STAFF_LINES);
		long min = 3 - (num / 2); // num/2 is an integer division – it is correct
		long i;
		for (i = 0; i < num; i++)
			voice->staff_lines[i] = min + i;
		voice->num_staff_lines = num;
		voice->min_staff_line = min;
		voice->max_staff_line = min+num-1;
		voice->are_staff_lines_standard = true;
		
	} else if (elem && hatom_gettype(&elem->l_hatom) == H_LLLL) {
		t_llll *subllll = hatom_getllll(&elem->l_hatom);
		t_llllelem *subelem;
		long count = 0;
		char def_min = false, def_max = false;
		voice->min_staff_line = voice->min_staff_line = 0;
		for (subelem = subllll->l_head; subelem && count < CONST_MAX_STAFF_LINES; subelem = subelem->l_next){
			if (hatom_gettype(&subelem->l_hatom) == H_LONG){
				long this_long = hatom_getlong(&subelem->l_hatom);
				voice->staff_lines[count] = this_long;
				if (!def_min || this_long < voice->min_staff_line) {
					voice->min_staff_line = this_long;
					def_min = true;
				}
				if (!def_max || this_long > voice->max_staff_line) {
					voice->max_staff_line = this_long;
					def_max = true;
				}
				count++;
			}
		}
		voice->num_staff_lines = count;
		voice->are_staff_lines_standard = false;

	} else if (force_assign_if_elem_is_wrong) {
		if (elem)
			hatom_setlong(&elem->l_hatom, 5);
		else 
			llll_appendlong(list, 5, 0, WHITENULL_llll);
		
		voice->num_staff_lines = 5;
		voice->staff_lines[0] = 1;
		voice->staff_lines[1] = 2;
		voice->staff_lines[2] = 3;
		voice->staff_lines[3] = 4;
		voice->staff_lines[4] = 5;
		voice->min_staff_line = 1;
		voice->max_staff_line = 5;
		voice->are_staff_lines_standard = true;
	}
	
	if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE){
		t_measure *meas;
		for (meas = ((t_scorevoice *)voice)->firstmeasure; meas; meas = meas->next) {
			recompute_all_measure_chord_parameters(r_ob, meas);
			meas->need_recompute_beams_positions = true;
		}
		set_need_perform_analysis_and_change_flag(r_ob);
	}
}


t_max_err notationobj_setattr_stafflines(t_notation_obj *r_ob, t_object *attr, long ac, t_atom *av){
	t_llll *inputlist = NULL;
	
	inputlist = llllobj_parse_llll((t_object *) r_ob, LLLL_OBJ_UI, NULL, ac, av, LLLL_PARSE_CLONE);
	
	if (!inputlist)
		return MAX_ERR_GENERIC;
	
	set_stafflines_from_llll(r_ob, inputlist, true);
	llll_free(inputlist);
	
	notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
	
	return MAX_ERR_NONE;
}

t_llll *get_voicespacing_as_llll(t_notation_obj *r_ob, char prepend_router)
{
    t_llll *outlist = llll_get();
    long v = 0;
    if (prepend_router)
        llll_appendsym(outlist, _llllobj_sym_voicespacing);
    for (v = 0; v < r_ob->num_voices+1; v++) {
        llll_appenddouble(outlist, r_ob->voiceuspacing_as_floatlist[v]);
    }
    return outlist;
}

t_llll *get_hidevoices_as_llll(t_notation_obj *r_ob, char prepend_router)
{
    t_llll *outlist = llll_get();
    long v = 0;
    if (prepend_router)
        llll_appendsym(outlist, _llllobj_sym_hidevoices);
    for (v = 0; v < r_ob->num_voices; v++) {
        llll_appendlong(outlist, r_ob->hidevoices_as_charlist[v]);
    }
    return outlist;
}


t_llll *get_voicenames_as_llll(t_notation_obj *r_ob, char prepend_router){
	t_llll *outlist = llll_get();
	long v = 0;
	t_voice *voice;
	if (prepend_router)
		llll_appendsym(outlist, _llllobj_sym_voicenames, 0, WHITENULL_llll);
	voice = r_ob->firstvoice;
	for (v = 0; v < r_ob->num_voices; v++) {
		llll_append_notation_item_name(outlist, (t_notation_item *)voice);
		voice = voice_get_next(r_ob, voice);
	}
	return outlist;
}

t_llll *get_clefs_as_llll(t_notation_obj *r_ob, char prepend_router){
	t_llll *outlist = llll_get();
	long v;
	if (prepend_router)
		llll_appendsym(outlist, _llllobj_sym_clefs, 0, WHITENULL_llll);
	for (v = 0; v < r_ob->num_voices; v++)
		llll_appendsym(outlist, r_ob->clefs_as_symlist[v], 0, WHITENULL_llll);
	return outlist;
}

t_llll *get_keys_as_llll(t_notation_obj *r_ob, char prepend_router){
	t_llll *outlist = llll_get();
	long v;
	if (prepend_router)
		llll_appendsym(outlist, _llllobj_sym_keys, 0, WHITENULL_llll);
	for (v = 0; v < r_ob->num_voices; v++)
		llll_appendsym(outlist, r_ob->keys_as_symlist[v], 0, WHITENULL_llll);
	return outlist;
}

t_llll *get_midichannels_as_llll(t_notation_obj *r_ob, char prepend_router)
{
	t_llll *outlist = llll_get();
	long v = 0; 
	t_voice *voice;
	if (prepend_router)
		llll_appendsym(outlist, _llllobj_sym_midichannels, 0, WHITENULL_llll);
	voice = r_ob->firstvoice;
	for (v = 0; v < r_ob->num_voices; v++) {
		llll_appendlong(outlist, voice->midichannel, 0, WHITENULL_llll);
		voice = voice_get_next(r_ob, voice);
	}
	return outlist;
}

t_llll *get_stafflines_as_llll(t_notation_obj *r_ob, char prepend_router)
{
	t_llll *outlist = llll_get();
	t_voice *voice;
	if (prepend_router)
		llll_appendsym(outlist, _llllobj_sym_stafflines, 0, WHITENULL_llll);
	for (voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) 
		llll_append(outlist, get_voice_stafflines_as_llllelem(r_ob, voice), WHITENULL_llll);
	return outlist;
}



void notationobj_erase_slots_from_llll(t_notation_obj *r_ob, t_llll *slot_numbers)
{
	if (slot_numbers && slot_numbers->l_size > 0) {
		t_llllelem *elem;
		for (elem = slot_numbers->l_head; elem; elem = elem->l_next) {
			if (hatom_gettype(&elem->l_hatom) == H_LONG) {
				long j = hatom_getlong(&elem->l_hatom);
				if (j >= 0 && j < CONST_MAX_SLOTS) 
					notationobj_erase_slot(r_ob, j);
			}
		}
	}
}


void notationobj_erase_slot(t_notation_obj *r_ob, int slot_number){
	t_voice *voice;
	t_chord *temp_ch;
	
	if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT) {
		note_clear_slot(r_ob, r_ob->dummynote, slot_number);
		return;
	}
	
	for (voice = r_ob->firstvoice; voice && (voice->number < r_ob->num_voices); voice = voice_get_next(r_ob, voice)) {
		for (temp_ch = (r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? ((t_rollvoice *)voice)->firstchord : (((t_scorevoice *)voice)->firstmeasure ? ((t_scorevoice *)voice)->firstmeasure->firstchord : NULL));
				temp_ch; temp_ch = chord_get_next(temp_ch)) {
			t_note *temp_nt = temp_ch->firstnote;
            if (!temp_nt && r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
#ifdef BACH_CHORDS_HAVE_SLOTS
                notation_item_clear_slot(r_ob, (t_notation_item *)temp_ch, slot_number, false);
#endif
            } else {
                while (temp_nt) {
                    notation_item_clear_slot(r_ob, (t_notation_item *)temp_nt, slot_number, false);
                    temp_nt = temp_nt->next;
                }
            }
		}
	}
	check_slot_linkage_recomputations_for_everything(r_ob, slot_number);
}

void post_unknown_message(t_object *x, t_llll *incoming_llll){
	t_symbol *s;
	if (incoming_llll && incoming_llll->l_head && hatom_gettype(&incoming_llll->l_head->l_hatom) == H_SYM && (s = hatom_getsym(&incoming_llll->l_head->l_hatom))){
		char *text = (char *) bach_newptr(strlen(s->s_name) + 200);
		snprintf_zero(text, 199, "%s: %s", BACH_UNKNOWN_MESSAGE_STRING, s->s_name);
		object_error((t_object *) x, text);
		bach_freeptr(text);
	} else
		object_error((t_object *) x, BACH_UNKNOWN_MESSAGE_STRING);
}


void notationobj_handle_change_cursors_on_mousedrag(t_notation_obj *r_ob, t_object *patcherview, t_pt pt, long modifiers)
{
    if (r_ob->j_mouse_cursor == BACH_CURSOR_NOTE_FOURWAY && modifiers == eShiftKey)
        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, ((r_ob->obj_type == k_NOTATION_OBJECT_SCORE && r_ob->j_mousedown_obj_type != k_PITCH_BREAKPOINT) || r_ob->main_dragging_direction > 0) ? BACH_CURSOR_NOTE_UPDOWN : BACH_CURSOR_NOTE_LEFTRIGHT);
    else if (r_ob->j_mouse_cursor == BACH_CURSOR_RESIZE_FOURWAY && modifiers == eShiftKey)
        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, r_ob->main_dragging_direction > 0 ? BACH_CURSOR_RESIZE_UPDOWN : BACH_CURSOR_RESIZE_LEFTRIGHT);
    else if (((r_ob->j_mouse_cursor == BACH_CURSOR_NOTE_UPDOWN && is_editable(r_ob, k_NOTE_OR_CHORD, k_MODIFICATION_ONSET))
                || (r_ob->j_mouse_cursor == BACH_CURSOR_NOTE_LEFTRIGHT && is_editable(r_ob, k_NOTE_OR_CHORD, k_MODIFICATION_PITCH))) && modifiers != eShiftKey)
        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_NOTE_FOURWAY);
    else if (((r_ob->j_mouse_cursor == BACH_CURSOR_NOTE_UPDOWN && is_editable(r_ob, k_PITCH_BREAKPOINT, k_MODIFICATION_ONSET))
              || (r_ob->j_mouse_cursor == BACH_CURSOR_RESIZE_LEFTRIGHT && is_editable(r_ob, k_PITCH_BREAKPOINT, k_MODIFICATION_PITCH))) &&
             r_ob->j_mousedown_obj_type != k_MARKER && modifiers != eShiftKey)
        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_FOURWAY);
    else if (!r_ob->j_mouse_hasbeendragged) {
        if (r_ob->j_mousedown_obj_type == k_REGION && (is_editable(r_ob, k_SELECTION, k_MULTIPLE_SELECTION) || is_editable(r_ob, k_SELECTION, k_SINGLE_SELECTION))) {
            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CROSSHAIR);
        } else if (r_ob->j_mousedown_obj_type == k_ZOOMING_REGION && is_editable(r_ob, k_ZOOMING_REGION, k_ELEMENT_ACTIONS_NONE)) {
            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CROSSHAIR);
        } else if (r_ob->j_mousedown_obj_type == k_VOICE && (modifiers & eShiftKey)  && is_editable(r_ob, k_VOICE, k_MODIFICATION_POSITION)) {
            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_UPDOWN);
        } else if (r_ob->j_mousedown_obj_type == k_DURATION_LINE) {
            bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_NONE);
        }
    }
}

// returns 1 if intercepted 0 otherwise
void notationobj_handle_change_cursors_on_mousemove(t_notation_obj *r_ob, t_object *patcherview, t_pt pt, long modifiers, t_rect rect)
{
	e_element_types loop_region_el = k_NONE;
	char dragging = (modifiers == eAltKey + eControlKey || modifiers == eAltKey + eControlKey + eShiftKey + eCommandKey);
	
	dragging |= r_ob->show_loop_region && !(modifiers & eAltKey) && !(modifiers & eCommandKey) && 
					!(modifiers & eControlKey) && (loop_region_el = is_in_loop_region(r_ob, rect, pt.x, pt.y)) == k_LOOP_REGION;
	
    if (r_ob->show_dilation_rectangle) {
		handle_dilation_rectangle_mouse_cursor(r_ob, patcherview, pt);
        return;
	}
    

    
	if (dragging && is_editable(r_ob, k_SCROLLBAR, k_ELEMENT_ACTIONS_NONE))
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DRAGGINGHAND);
	else if ((loop_region_el == k_LOOP_START || loop_region_el == k_LOOP_END) && is_editable(r_ob, k_LOOP_REGION, k_ELEMENT_ACTIONS_NONE))
		bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_LEFTRIGHT);
    else {
        void *hovered_elem_ptr = NULL;
        long hovered_elem_type = k_NONE;
        
        lock_general_mutex(r_ob);
        notationobj_pixel_to_element(r_ob, pt, &hovered_elem_ptr, &hovered_elem_type);
        
        if (is_in_linear_edit_mode(r_ob)) {
            if ((r_ob->obj_type == k_NOTATION_OBJECT_SCORE && hovered_elem_type == k_MEASURE) ||
                (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && is_y_within_any_staff(r_ob, pt.y)))
                bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, modifiers & eControlKey ? BACH_CURSOR_PENCIL : BACH_CURSOR_DEFAULT);
            else
                bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_REVERT);
            unlock_general_mutex(r_ob);
            return;
        }
        
        switch (hovered_elem_type) {
                
            case k_MARKER:
                if (modifiers == eCommandKey && is_editable(r_ob, k_MARKER, k_DELETION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DELETE);
                else if (modifiers == eAltKey && is_editable(r_ob, k_MARKER, k_CREATION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_COPY);
                else if (modifiers == eControlKey) {
                    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DRAGGINGHAND);
                    else
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_SWITCH);
                } else if (modifiers == eControlKey + eCommandKey && r_ob->obj_type == k_NOTATION_OBJECT_ROLL)
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_TRIM_END);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_LEFTRIGHT);
                break;
                
            case k_NOTE:
                if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && modifiers & eShiftKey && modifiers & eControlKey && is_editable(r_ob, k_NOTE_OR_CHORD, k_MODIFICATION_ONSET) && is_editable(r_ob, k_NOTE_OR_CHORD, k_MODIFICATION_DURATION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_TRIM_START);
                else if (modifiers == eControlKey && is_editable(r_ob, k_NOTE_OR_CHORD, k_MODIFICATION_VELOCITY))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CHANGE_VELOCITY);
                else if (modifiers == eCommandKey && is_editable(r_ob, k_NOTE_OR_CHORD, k_DELETION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DELETE);
                else if (modifiers == eAltKey || modifiers == eAltKey + eShiftKey)
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DUPLICATE);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview,
                                    r_ob->obj_type == k_NOTATION_OBJECT_ROLL ? BACH_CURSOR_NOTE_FOURWAY : BACH_CURSOR_NOTE_UPDOWN);
                break;
                
            case k_DURATION_LINE:
                if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && modifiers == eCommandKey && is_editable(r_ob, k_NOTE_OR_CHORD, k_CREATION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_NOTE);
                else if (modifiers == eAltKey && is_editable(r_ob, k_PITCH_BREAKPOINT, k_CREATION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_ADD_POINT);
                else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && modifiers == eShiftKey + eControlKey && r_ob->allow_glissandi && is_editable(r_ob, k_NOTE_OR_CHORD, k_MODIFICATION_GENERIC))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CUT);
                else if (modifiers == eControlKey && is_editable(r_ob, k_PITCH_BREAKPOINT, k_MODIFICATION_GENERIC))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CURVE);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;

            case k_PITCH_BREAKPOINT:
            {
                t_bpt *bpt = (t_bpt *)hovered_elem_ptr;
                if (!bpt)
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                else if (!bpt->next && r_ob->obj_type == k_NOTATION_OBJECT_ROLL && modifiers == eCommandKey && is_editable(r_ob, k_NOTE_OR_CHORD, k_CREATION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_NOTE);
                else if (r_ob->breakpoints_have_velocity && modifiers == eControlKey && is_editable(r_ob, k_PITCH_BREAKPOINT, k_MODIFICATION_VELOCITY))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CHANGE_VELOCITY);
                else if (bpt->next && modifiers == eCommandKey && is_editable(r_ob, k_PITCH_BREAKPOINT, k_DELETION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DELETE);
                else if (!bpt->next && modifiers == eControlKey + eShiftKey)
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_TRIM_END);
                else if (!bpt->next && modifiers == eShiftKey)
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_LEFTRIGHT);
                else {
                    if (!bpt->next && r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, r_ob->breakpoints_have_noteheads ? BACH_CURSOR_NOTE_UPDOWN : BACH_CURSOR_RESIZE_UPDOWN);
                    else
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, r_ob->breakpoints_have_noteheads ? BACH_CURSOR_NOTE_FOURWAY : BACH_CURSOR_RESIZE_FOURWAY);
                }
            }
                break;

            case k_CHORD: // Actually implies this is a REST (otherwise it's NOTE)
                if (modifiers == eCommandKey && is_editable(r_ob, k_NOTE_OR_CHORD, k_CREATION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_NOTE);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;
                
            case k_MEASURE:
                if (modifiers == eCommandKey && is_editable(r_ob, k_MEASURE, k_CREATION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_ADD_POINT);
                else if (modifiers == eControlKey && r_ob->allow_linear_edit && !r_ob->is_linear_editing)
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_PENCIL);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;

            case k_MEASURE_END_BARLINE:
                if (modifiers == eShiftKey && is_editable(r_ob, k_MEASURE, k_MODIFICATION_GENERIC))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_LEFTRIGHT);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;

            case k_VOICE:
                if ((modifiers == eShiftKey || modifiers == eShiftKey+eControlKey) && is_editable(r_ob, k_VOICE, k_MODIFICATION_POSITION))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_RESIZE_UPDOWN);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;
                
            case k_DYNAMICS:
                if (modifiers == eControlKey && is_editable(r_ob, k_DYNAMICS, k_MODIFICATION_GENERIC))
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_CHANGE_DYNAMICS);
                else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;
                


            case k_NONE:

                if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && is_y_within_any_staff(r_ob, pt.y) &&
                    (modifiers == eControlKey && r_ob->allow_linear_edit && !r_ob->is_linear_editing)) {
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_PENCIL);
                    
                } else if (modifiers == eShiftKey + eAltKey && is_editable(r_ob, k_MARKER, k_CREATION)) {
                    double ux = xposition_to_unscaled_xposition(r_ob, pt.x);
                    if (r_ob->obj_type != k_NOTATION_OBJECT_ROLL || ux >= 0)
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_MARKER_ADD);
                    else
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                } else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && modifiers == eCommandKey && is_editable(r_ob, k_NOTE_OR_CHORD, k_CREATION)) {
                    e_bach_mouse_cursors cursor = BACH_CURSOR_NOTE;
                    double quanty = pt.y;
                    double ux = xposition_to_unscaled_xposition(r_ob, pt.x);
                    if (ux >= 0) {
                        long voicenum = yposition_to_voicenumber(r_ob, pt.y, NULL, k_VOICEENSEMBLE_INTERFACE_FIRST);
                        t_voice *voice = nth_voice_safe(r_ob, voicenum);
                        if (voice) {
                            double mc = yposition_to_mc(r_ob, pt.y, NULL, NULL);
                            long screen_mc;
                            t_rational screen_acc;
                            constraint_midicents_depending_on_editing_ranges(r_ob, &mc, voice->number);
                            mc_to_screen_approximations(r_ob, mc, &screen_mc, &screen_acc, voice->acc_pattern, voice->full_repr);
                            if (screen_acc.r_num > 0) cursor = BACH_CURSOR_NOTE_SHARP;
                            else if (screen_acc.r_num < 0) cursor = BACH_CURSOR_NOTE_FLAT;
                            
                            quanty = mc_to_yposition(r_ob, screen_mc, voice);
                        }
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, cursor);
                    } else
                        bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                } else
                    bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;
                
            default:
                bach_set_cursor((t_object *)r_ob, &r_ob->j_mouse_cursor, patcherview, BACH_CURSOR_DEFAULT);
                break;
        }
        unlock_general_mutex(r_ob);
    }
}






void notationobj_copy_slot_selection(t_notation_obj *r_ob, t_clipboard *clipboard, t_notation_item *nitem, long slot_num, char cut)
{
	if (clipboard->gathered_syntax)
		llll_free(clipboard->gathered_syntax);
	
	// we only copy the selected slot items 
	clipboard->gathered_syntax = notation_item_get_single_slot_values_as_llll(r_ob, nitem, k_CONSIDER_FOR_DUMPING, slot_num, true);
	clipboard->type = k_SLOT_SELECTION;
	clipboard->object = k_NOTATION_OBJECT_ANY;
	if (cut) { // cut
		if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
			r_ob->whole_obj_undo_tick_function(r_ob);
		else
			undo_tick_create_create_for_selected_notation_item(r_ob, (t_notation_item *)notation_item_get_parent_chord(r_ob, nitem), k_CHORD, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
		delete_all_selected_function_points(r_ob, slot_num);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CUT_SLOT_CONTENT);
	}
}


void notationobj_copy_slot(t_notation_obj *r_ob, t_clipboard *clipboard, t_notation_item *nitem, long slot_num, char cut)
{
	if (clipboard->gathered_syntax)
		llll_free(clipboard->gathered_syntax);
	
	// we copy the entire slot
	if (slot_num < 0) // we copy all the (used) slots
		clipboard->gathered_syntax = notation_item_get_slots_values_as_llll(r_ob, nitem, k_CONSIDER_FOR_DUMPING, false);
	else  {  // we just copy the active slot
		clipboard->gathered_syntax = llll_get();
		llll_appendllll(clipboard->gathered_syntax, notation_item_get_single_slot_values_as_llll(r_ob, nitem, k_CONSIDER_FOR_DUMPING, slot_num, false), 0, WHITENULL_llll);
	}
	clipboard->type = k_SLOT;
	clipboard->object = k_NOTATION_OBJECT_ANY;
    
	if (cut) { // cut
		if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
			r_ob->whole_obj_undo_tick_function(r_ob);
		else
			undo_tick_create_create_for_selected_notation_item(r_ob, get_activeitem_undo_item(r_ob), k_CHORD, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
		notation_item_clear_slot(r_ob, nitem, slot_num);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CUT_SLOT_CONTENT);
	}
}

// use paste_to_this_slot = -1 to paste to the original position
void notationobj_paste_slot(t_notation_obj *r_ob, t_clipboard *clipboard, long paste_to_this_slot, char also_paste_to_rests) {
	if (paste_to_this_slot < 0) {
		set_slots_to_selection(r_ob, clipboard->gathered_syntax, also_paste_to_rests);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_PASTE_SLOT_CONTENT);
	} else {
		// gotta paste the (only) cached slot into the active slot (we don't check the type)
		t_llll *clonedslot;
		lock_general_mutex(r_ob);	
		clonedslot = llll_clone(clipboard->gathered_syntax);
		unlock_general_mutex(r_ob);
		if (clonedslot->l_head && hatom_gettype(&clonedslot->l_head->l_hatom) == H_LLLL && hatom_gettype(&clonedslot->l_head->l_hatom.h_w.w_llll->l_head->l_hatom) == H_LONG)
			hatom_setlong(&clonedslot->l_head->l_hatom.h_w.w_llll->l_head->l_hatom, paste_to_this_slot + 1);
        if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT) {
            lock_general_mutex(r_ob);
			set_slots_values_to_note_from_llll(r_ob, r_ob->dummynote, clonedslot);
            unlock_general_mutex(r_ob);
        } else
			set_slots_to_selection(r_ob, clonedslot, also_paste_to_rests);
		llll_free(clonedslot);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_PASTE_SLOT_CONTENT);
	}
}


void notationobj_copy_durationline(t_notation_obj *r_ob, t_clipboard *clipboard, t_note *note, char cut)
{
    if (note) {
        if (clipboard->gathered_syntax)
            llll_free(clipboard->gathered_syntax);
        
        // we copy the duration line
        clipboard->gathered_syntax = note_get_breakpoint_values_as_llll(r_ob, note, k_CONSIDER_FOR_DUMPING, NULL, NULL);
        clipboard->type = k_DURATION_LINE;
        clipboard->object = k_NOTATION_OBJECT_ANY;
        
        if (cut) { // cut
            if (r_ob->obj_type == k_NOTATION_OBJECT_SLOT)
                r_ob->whole_obj_undo_tick_function(r_ob);
            else
                undo_tick_create_for_notation_item(r_ob, (t_notation_item *)note->parent, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
            note_delete_breakpoints(r_ob, note);
            handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CUT_DURATION_LINE);
        }
    }
}


void notationobj_set_durationline(t_notation_obj *r_ob, t_llll *durationline_as_breakpoints) {
    set_breakpoints_to_selection(r_ob, durationline_as_breakpoints);
    handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_CHANGE_DURATION_LINES_FOR_SELECTION);
}

void notationobj_paste_durationline(t_notation_obj *r_ob, t_clipboard *clipboard) {
    // gotta paste the (only) cached slot into the active slot (we don't check the type)
    t_llll *clonedbpts;
    lock_general_mutex(r_ob);
    clonedbpts = llll_clone(clipboard->gathered_syntax);
    unlock_general_mutex(r_ob);
    set_breakpoints_to_selection(r_ob, clonedbpts);
    llll_free(clonedbpts);
    handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_PASTE_DURATION_LINE);
}


void notationobj_paste_slot_selection_to_open_slot_window(t_notation_obj *r_ob, t_clipboard *clipboard, char delete_intermediate_points)
{
	if (r_ob->active_slot_num >= 0) {
		double offset = r_ob->j_mouse_x - r_ob->slot_window_active_x1;
		t_rect activeslotwin = build_rect(r_ob->slot_window_active_x1, r_ob->slot_window_active_y1, r_ob->slot_window_active_x2 - r_ob->slot_window_active_x1, r_ob->slot_window_active_y2 - r_ob->slot_window_active_y1);
		
		// getting leftmost x
		t_llllelem *elem;
		double min = 0;
		char def_min = 0;
		for (elem = clipboard->gathered_syntax->l_head; elem; elem = elem->l_next) {
			if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
				t_llll *ll = hatom_getllll(&elem->l_hatom);
				if (ll->l_head && is_hatom_number(&ll->l_head->l_hatom)) {
					if (!def_min)
						min = hatom_getdouble(&ll->l_head->l_hatom);
					else
						min = MIN(min, hatom_getdouble(&ll->l_head->l_hatom));
					def_min = true;
				}
			}
		}
		if (def_min) {
			t_pt pt;
			function_xy_values_to_pt(r_ob, r_ob->active_slot_notationitem, min, 0, r_ob->active_slot_num, activeslotwin, &pt);
			offset -= pt.x - activeslotwin.x;
		}
		
		undo_tick_create_create_for_selected_notation_item(r_ob, get_activeitem_undo_item(r_ob), k_CHORD, k_UNDO_MODIFICATION_TYPE_CHANGE, _llllobj_sym_state);
		paste_slotitems(r_ob, r_ob->active_slot_notationitem, r_ob->active_slot_num, clipboard->gathered_syntax, activeslotwin, offset, delete_intermediate_points);
		handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER_AND_BANG, k_UNDO_OP_PASTE_SLOT_CONTENT);
	}
}


t_max_err notationobj_handle_attr_modified_notify(t_notation_obj *r_ob, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
    if (!r_ob->creatingnewobj && msg == _sym_attr_modified) {
        t_symbol *attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
        if (attrname && strlen(attrname->s_name) > 10 && !strncmp(attrname->s_name, "link", 4)) {
            if (attrname == gensym("linklyricstoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_lyrics_to_slot - 1, k_SLOT_LINKAGE_LYRICS);
            else if (attrname == gensym("linknoteheadtoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_notehead_to_slot - 1, k_SLOT_LINKAGE_NOTEHEAD);
            else if (attrname == gensym("linknoteheadfonttoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_notehead_font_to_slot - 1, k_SLOT_LINKAGE_NOTEHEAD_FONT);
            else if (attrname == gensym("linknoteheadadjusttoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_notehead_adjust_to_slot - 1, k_SLOT_LINKAGE_NOTEHEAD_ADJUST);
            else if (attrname == gensym("linknotesizetoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_notesize_to_slot - 1, k_SLOT_LINKAGE_NOTE_SIZE);
            else if (attrname == gensym("linknotecolortoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_nitemcolor_to_slot - 1, k_SLOT_LINKAGE_NOTE_COLOR);
            else if (attrname == gensym("linkarticulationstoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_articulations_to_slot - 1, k_SLOT_LINKAGE_ARTICULATIONS);
            else if (attrname == gensym("linkannotationtoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_annotation_to_slot - 1, k_SLOT_LINKAGE_ANNOTATION);
            else if (attrname == gensym("linkdynamicstoslot"))
                change_linkto_slot_flag(r_ob, r_ob->link_dynamics_to_slot - 1, k_SLOT_LINKAGE_DYNAMICS);
            else if (attrname == gensym("linkdlcolortoslot"))
            change_linkto_slot_flag(r_ob, r_ob->link_dlcolor_to_slot - 1, k_SLOT_LINKAGE_DURATIONLINE_COLOR);
        }
        
        notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    }
    return MAX_ERR_NONE;
}


t_atom_long notationobj_acceptsdrag(t_notation_obj *r_ob, t_object *drag, t_object *view)
{
    if (is_editable(r_ob, k_DROP, k_MODIFICATION_GENERIC) && !jdrag_matchdragrole(drag, gensym("folder"), 0)) {
        jdrag_box_add(drag, (t_object *)r_ob, gensym("readsinglesymbol"));
        return true;
    }
    return false;
}






/////// MIRA / MIRAWEB INTERACTION


long notationobj_mt_get_num_fingers_down(t_notation_obj *r_ob)
{
    long res = 0;
    for (long i = 0; i < 10; i++)
        res += (r_ob->mt_finger_state[i] > 0);
    return res;
}

void notationobj_mt(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    if (argc) {
        t_object *firstview = jpatcher_get_firstview((t_object *)r_ob);
        
//        if (atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("region") && argc >= 4) { // region <regionID> <finger> <state> <device>
//            long finger_id = CLAMP(atom_getlong(argv + 2), 1, 10) - 1;
//            long state = CLAMP(atom_getlong(argv + 3), 0, 1);
//            finger_state[finger_id] = state;
//        } else
            if (atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("touch") && argc >= 5) { // touch <x> <y> <finger> <state> <region> <device>
            long finger_id = CLAMP(atom_getlong(argv + 3), 1, 10) - 1;
            long state = CLAMP(atom_getlong(argv + 4), 0, 1);
            t_pt pos = build_pt(atom_getfloat(argv + 1) * r_ob->width, atom_getfloat(argv + 2) * r_ob->height);
            
//            dev_object_post((t_object *)r_ob, "• Mira finger %ld %s", finger_id + 1, state ? "ON" : "OFF");
            
            if (!r_ob->mt_pinching) {
                if (r_ob->mt_finger_state[finger_id]) {
                    if (!state) {
                        // finger released
                        method mouseup = object_method_direct_getmethod((t_object *) r_ob, gensym("mouseup"));
                        if (mouseup) (mouseup)(r_ob, firstview, pos, 0);
                    } else {
                        // finger dragged
                        method mousedrag = object_method_direct_getmethod((t_object *) r_ob, gensym("mousedrag"));
                        if (mousedrag) (mousedrag)(r_ob, firstview, pos, 0);
                    }
                } else {
                    if (!state) {
                        // should not happen, in principle
                    } else {
                        // finger pressed
                        method mousedown = object_method_direct_getmethod((t_object *) r_ob, gensym("mousedown"));
                        if (mousedown) (mousedown)(r_ob, firstview, pos, 0);
                    }
                }
            }
            
            r_ob->mt_finger_state[finger_id] = state;
            r_ob->mt_finger_pos[finger_id] = pos;
            
            if (notationobj_mt_get_num_fingers_down(r_ob) == 0)
                r_ob->mt_pinching = false;
            
            // swipe = scroll
        } else if (atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("swipe") && argc >= 2) { // swipe <direction> <device>
            t_symbol *direction = atom_getsym(argv + 1);
            method mousewheel = object_method_direct_getmethod((t_object *) r_ob, gensym("mousewheel"));
            if (mousewheel) {
                if (direction == gensym("left"))
                    (mousewheel)(r_ob, firstview, r_ob->mt_finger_pos[0], 0, -get_domain_width_pixels(r_ob) / (25. * CONST_X_MOUSEWHEEL_FACTOR), 0.);
                else if (direction == gensym("right"))
                    (mousewheel)(r_ob, firstview, r_ob->mt_finger_pos[0], 0, get_domain_width_pixels(r_ob) / (25. * CONST_X_MOUSEWHEEL_FACTOR), 0.);
            }
            
            // pinch = change zoom
        } else if (atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("pinch") && argc >= 2) { // pinch <change> <velocity> <state> <device>
            double change = atom_getfloat(argv + 1);
            if (!r_ob->mt_pinching) {
                // just started pinching!
                r_ob->mt_zoom_at_pinch_start = r_ob->zoom_x;
                r_ob->mt_pinching = true;
            }
            object_attr_setfloat((t_object *)r_ob, gensym("zoom"), r_ob->mt_zoom_at_pinch_start * change * 100.);
//            method mousewheel = object_method_direct_getmethod((t_object *) r_ob, gensym("mousewheel"));
//            (mousewheel)(r_ob, firstview, r_ob->mt_finger_pos[0], eCommandKey, 0., 4 * (r_ob->zoom_x - change * r_ob->zoom_x)/CONST_Y_MOUSEWHEEL_FACTOR);
            
            // tap = Cmd + click
        } else if (atom_gettype(argv) == A_SYM && atom_getsym(argv) == gensym("tap") && argc >= 3) { // tap <x> <y> <region> <device>
            t_pt pos = build_pt(atom_getfloat(argv + 1) * r_ob->width, atom_getfloat(argv + 2) * r_ob->height);
            method mousedown = object_method_direct_getmethod((t_object *) r_ob, gensym("mousedown"));
            method mouseup = object_method_direct_getmethod((t_object *) r_ob, gensym("mouseup"));
            if (mousedown) (mousedown)(r_ob, firstview, pos, eCommandKey);
            if (mouseup) (mouseup)(r_ob, firstview, pos, eCommandKey);
        }
    }
}

