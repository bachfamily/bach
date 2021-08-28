/*
 *  notation_goto.c
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
	notation_goto - navigation "go-to"-style functions for notation objects
*/

#include "notation/notation_goto.h"


long goto_get_marker_voicenumber(t_notation_obj *r_ob, t_marker *mk)
{
    if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_measure *meas = (t_measure *)notation_item_retrieve_from_ID(r_ob, mk->measure_attach_ID);
        if (meas)
            return meas->voiceparent->v_ob.number;
        else
            return -1;
    } else
        return -1;
}

double goto_notation_item_get_onset(t_notation_obj *r_ob, t_goto_params *par, t_notation_item *it)
{
    if (par->graces_have_duration)
        return notation_item_get_play_onset_ms_accurate(r_ob, it);
    else
        return notation_item_get_onset_ms_accurate(r_ob, it);
}

double goto_notation_item_get_tail(t_notation_obj *r_ob, t_goto_params *par, t_notation_item *it)
{
    if (par->graces_have_duration)
        return notation_item_get_play_tail_ms_accurate(r_ob, it);
    else
        return notation_item_get_tail_ms_accurate(r_ob, it);
}

double goto_notation_item_get_duration(t_notation_obj *r_ob, t_goto_params *par, t_notation_item *it)
{
    if (par->graces_have_duration)
        return notation_item_get_play_duration_ms_accurate(r_ob, it);
    else
        return notation_item_get_duration_ms_accurate(r_ob, it);
}



long symbol_to_notationitem_type(t_notation_obj *r_ob, t_symbol *s)
{
    if (s == _llllobj_sym_chord)
        return k_CHORD;
    if (s == _llllobj_sym_note)
        return k_NOTE;
    if (s == _llllobj_sym_breakpoint)
        return k_PITCH_BREAKPOINT;
    if (s == _llllobj_sym_tail)
        return k_DURATION_TAIL;
    if (s == _llllobj_sym_marker)
        return k_MARKER;
    if (s == _llllobj_sym_tempo)
        return k_TEMPO;
    if (s == _llllobj_sym_measure)
        return k_MEASURE;
    if (s == _llllobj_sym_voice)
        return k_VOICE;
    if (s == _llllobj_sym_none)
        return k_NONE;
    
    return k_ELEMENT_TYPES_UNDEFINED;
}


void goto_preprocess_voicenumbers(t_notation_obj *r_ob, t_goto_params *par)
{
    if (!par->voicenumbers || !par->voicenumbers->l_head)
        return;
    
    
    if (hatom_gettype(&par->voicenumbers->l_head->l_hatom) == H_SYM &&
        (hatom_getsym(&par->voicenumbers->l_head->l_hatom) == _llllobj_sym_all || hatom_getsym(&par->voicenumbers->l_head->l_hatom) == _llllobj_sym_any)) {
        llll_clear(par->voicenumbers);
        for (long i = 0; i < r_ob->num_voices; i++)
            llll_appendlong(par->voicenumbers, i);
        return;
    }
    
    llll_develop_ranges_and_parse_negative_indices_inplace(&par->voicenumbers, r_ob->num_voices, true);
}

long sym_to_voicemode(t_symbol *s)
{
    if (s == _llllobj_sym_all)
        return k_GOTO_VOICEMODE_ALL;
    if (s == _llllobj_sym_any)
        return k_GOTO_VOICEMODE_ANY;
    if (s == _llllobj_sym_each)
        return k_GOTO_VOICEMODE_EACH;
    if (s == gensym("lastactive"))
        return k_GOTO_VOICEMODE_LASTACTIVE;
    if (s == gensym("allactive"))
        return k_GOTO_VOICEMODE_ALLACTIVE;
    if (s == gensym("anyactive"))
        return k_GOTO_VOICEMODE_ANYACTIVE;
    return k_GOTO_VOICEMODE_ANYACTIVE;
}

long sym_to_tiemode(t_symbol *s)
{
    if (s == _llllobj_sym_all)
        return k_GOTO_TIEMODE_ALL;
    if (s == gensym("to"))
        return k_GOTO_TIEMODE_TO;
    if (s == gensym("from"))
        return k_GOTO_TIEMODE_FROM;
    return k_GOTO_TIEMODE_EACH;
}

long sym_to_onsetpoint(t_symbol *s)
{
    if (s == gensym("head"))
        return k_GOTO_ONSETPOINT_HEAD;
    if (s == _llllobj_sym_tail)
        return k_GOTO_ONSETPOINT_TAIL;
    return k_GOTO_ONSETPOINT_AUTO;
}

long sym_to_polymode(t_symbol *s)
{
    if (s == gensym("overhang"))
        return k_GOTO_POLYMODE_OVERHANG;
    if (s == gensym("overlap"))
        return k_GOTO_POLYMODE_OVERLAP;
    return k_GOTO_POLYMODE_NONE;
}

long sym_to_untilmode(t_symbol *s)
{
    if (s == _llllobj_sym_all)
        return k_GOTO_UNTILMODE_ALL;
    return k_GOTO_UNTILMODE_ANY;
}


char goto_are_types_unchanged(t_notation_obj *r_ob, t_goto_params *par, long equal_to_this)
{
    if (par->num_allowed_types == 0)
        return 1;
    
    if (par->num_allowed_types == 1 && par->allowed_types[equal_to_this])
        return 1;
    
    return 0;
}




char goto_account_for_voice(t_goto_params *par, long voicenum, long activevoicenum)
{
    char is_voice_ok = (!par->voicenumbers || !par->voicenumbers->l_head || is_long_in_llll_first_level(par->voicenumbers, voicenum));
    if (par->command == _llllobj_sym_next || par->command == _llllobj_sym_prev) {
        switch (par->voicemode) {
            case k_GOTO_VOICEMODE_LASTACTIVE:
                return (activevoicenum == voicenum) && is_voice_ok;
                break;
                
            case k_GOTO_VOICEMODE_ALL:
            case k_GOTO_VOICEMODE_ANY:
            case k_GOTO_VOICEMODE_EACH:
                return is_voice_ok;
                break;

            case k_GOTO_VOICEMODE_ALLACTIVE:
            case k_GOTO_VOICEMODE_ANYACTIVE:
                return is_voice_ok && par->activevoices[voicenum];
                break;

            default:
                return 0;
                break;
        }
    } else {
        return is_voice_ok;
    }
}





t_notation_item *get_next_notation_item(t_notation_obj *r_ob, t_notation_item *it, char skip_rests)
{
    if (!it)
        return NULL;
    else {
        switch (it->type) {
            case k_NOTE:
                return (t_notation_item *)((t_note *)it)->next;
                
            case k_CHORD:
                return (t_notation_item *)(skip_rests ? chord_get_next_nonrest((t_chord *)it) : chord_get_next((t_chord *)it));
                
            case k_TEMPO:
                return (t_notation_item *)(tempo_get_next((t_tempo *)it));
                
            case k_MARKER:
                return (t_notation_item *)((t_marker *)it)->next;
                
            case k_MEASURE:
                return (t_notation_item *)measure_get_next((t_measure *)it);
                
            case k_VOICE:
                return (t_notation_item *)voice_get_next(r_ob, (t_voice *)it);
                
            default:
                return NULL;
                break;
        }
    }
}


t_llll *goto_get_selection_as_llll(t_notation_obj *r_ob)
{
    t_llll *ll = llll_get();
    for (t_notation_item *item = r_ob->firstselecteditem; item; item = item->next_selected)
        llll_appendobj(ll, item);
    
    return ll;
}


double get_min_head(t_notation_obj *r_ob, t_goto_params *par, t_llll *toselect)
{
    char found = 0;
    double onset = -1;
    for (t_llllelem *elem = toselect->l_head; elem; elem = elem->l_next) {
        t_notation_item *it = (t_notation_item *)hatom_getobj(&elem->l_hatom);
        double this_onset = goto_notation_item_get_onset(r_ob, par, it);
        if (!found || this_onset < onset) {
            onset = this_onset;
            found = 1;
        }
    }
    
    return onset;
}

double get_max_head(t_notation_obj *r_ob, t_goto_params *par, t_llll *toselect)
{
    char found = 0;
    double onset = -1;
    char no_tie_from = (par->tiemode == k_GOTO_TIEMODE_TO || par->tiemode == k_GOTO_TIEMODE_ALL);
    for (t_llllelem *elem = toselect->l_head; elem; elem = elem->l_next) {
        t_notation_item *it = (t_notation_item *)hatom_getobj(&elem->l_hatom);
        if (no_tie_from && ((it->type == k_CHORD && chord_is_all_tied_from((t_chord *)it, false)) ||
                            (it->type == k_NOTE && ((t_note *) it)->tie_from)))
            continue;
        double this_onset = goto_notation_item_get_onset(r_ob, par, it);
        if (!found || this_onset > onset) {
            onset = this_onset;
            found = 1;
        }
    }
    
    return onset;
}


double get_min_tail(t_notation_obj *r_ob, t_goto_params *par, t_llll *toselect)
{
    char found = 0;
    double onset = -1;
    char no_tie_to = (par->tiemode == k_GOTO_TIEMODE_FROM || par->tiemode == k_GOTO_TIEMODE_ALL);
    for (t_llllelem *elem = toselect->l_head; elem; elem = elem->l_next) {
        t_notation_item *it = (t_notation_item *)hatom_getobj(&elem->l_hatom);
        if (no_tie_to && ((it->type == k_CHORD && chord_is_all_tied_to(r_ob, (t_chord *)it, false, NULL)) ||
                            (it->type == k_NOTE && ((t_note *) it)->tie_to)))
            continue;
        double this_onset = goto_notation_item_get_tail(r_ob, par, it);
        if (!found || this_onset < onset) {
            onset = this_onset;
            found = 1;
        }
    }
    
    return onset;
}


double get_max_tail(t_notation_obj *r_ob, t_goto_params *par, t_llll *toselect)
{
    char found = 0;
    double onset = -1;
    for (t_llllelem *elem = toselect->l_head; elem; elem = elem->l_next) {
        t_notation_item *it = (t_notation_item *)hatom_getobj(&elem->l_hatom);
        double this_onset = goto_notation_item_get_tail(r_ob, par, it);
        if (!found || this_onset > onset) {
            onset = this_onset;
            found = 1;
        }
    }
    
    return onset;
}


t_llll *goto_get_tied_items(t_notation_obj *r_ob, t_notation_item *it, char tie_from, char tie_to, char include_original)
{
    t_llll *out = llll_get();
    
    if (include_original)
        llll_appendobj(out, it);
    
    if (r_ob->obj_type != k_NOTATION_OBJECT_SCORE)
        return out;
    
    switch (it->type) {
        case k_CHORD:
        {
            t_chord *ch = (t_chord *)it;
            if (tie_from) {
                while (ch && chord_is_all_tied_from(ch, false)) {
                    ch = chord_get_prev(ch);
                    llll_appendobj(out, ch);
                }
            }
            ch = (t_chord *)it;
            if (tie_to) {
                while (ch && chord_is_all_tied_to(r_ob, ch, false, NULL)) {
                    ch = chord_get_next(ch);
                    llll_appendobj(out, ch);
                }
            }
        }
            break;
            
        case k_NOTE:
        {
            t_note *nt = (t_note *)it;
            if (tie_from) {
                while (nt && nt->tie_from && nt->tie_from != WHITENULL) {
                    nt = nt->tie_from;
                    llll_appendobj(out, nt);
                }
            }
            nt = (t_note *)it;
            if (tie_to) {
                while (nt && nt->tie_to && nt->tie_to != WHITENULL) {
                    nt = nt->tie_to;
                    llll_appendobj(out, nt);
                }
            }
        }
            break;
            
        default:
            break;
    }

    return out;
}


/// beware: will modify <toselect> according to tiemodes etc.
e_goto_error goto_set_selection_from_llll(t_notation_obj *r_ob, t_goto_params *par, t_llll *toselect)
{
    if (!toselect || !toselect->l_head) {
        clear_selection(r_ob);
        notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
        return k_GOTO_ERROR_NOTFOUND;
    }
    

    /// Handling tie modes
    if (par->tiemode != k_GOTO_TIEMODE_EACH && r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        t_llll *additional_selection = llll_get();
        for (t_llllelem *elem = toselect->l_head; elem; elem = elem->l_next) {
            t_notation_item *it = (t_notation_item *)hatom_getobj(&elem->l_hatom);
            llll_chain(additional_selection, goto_get_tied_items(r_ob, it,
                                                                 par->tiemode == k_GOTO_TIEMODE_FROM || par->tiemode == k_GOTO_TIEMODE_ALL,
                                                                 par->tiemode == k_GOTO_TIEMODE_TO || par->tiemode == k_GOTO_TIEMODE_ALL, false));
        }
        llll_chain(toselect, additional_selection);
    }

    
    /// Handling polyphony mode and clearing existing selection
    if (par->polymode == k_GOTO_POLYMODE_NONE) {
        clear_selection(r_ob);
    } else {
        // get min and max onset
        double newsel_min_head = get_min_head(r_ob, par, toselect);
        double newsel_max_tail = get_max_tail(r_ob, par, toselect);
        t_llll *selitems_to_unsel = llll_get();
        for (t_notation_item *it = r_ob->firstselecteditem; it; it = it->next_selected) {
            t_llll *tieseq = goto_get_tied_items(r_ob, it,
                                                 par->tiemode == k_GOTO_TIEMODE_FROM || par->tiemode == k_GOTO_TIEMODE_ALL,
                                                 par->tiemode == k_GOTO_TIEMODE_TO || par->tiemode == k_GOTO_TIEMODE_ALL, true); // tie sequence (if any), or single chord
            double this_min_head = get_min_head(r_ob, par, tieseq);
            double this_max_tail = get_max_tail(r_ob, par, tieseq);
            
            char must_unsel = true;
            
            if (this_min_head == this_max_tail)
                must_unsel = true; // currently selected item is a grace note or an instantaneous element
            else if ((par->polymode == k_GOTO_POLYMODE_OVERHANG || par->polymode == k_GOTO_POLYMODE_OVERLAP) &&
                     (this_min_head <= newsel_min_head) && (this_max_tail >= newsel_max_tail)) {
                
                if (newsel_max_tail == newsel_min_head) { // new selected item is a grace note, or an instantanteous element (marker, tempo)
                    if ((par->command == _llllobj_sym_next && this_max_tail == newsel_max_tail) ||
                        (par->command == _llllobj_sym_next && this_min_head == newsel_min_head)) {
                        must_unsel = true;
                    } else
                        must_unsel = false;
                } else
                    must_unsel = false;
            } else if (par->polymode == k_GOTO_POLYMODE_OVERLAP &&
                     (((this_min_head <= newsel_min_head) && (newsel_min_head < this_max_tail) && (this_max_tail <= newsel_max_tail)) ||
                      ((newsel_min_head <= this_min_head) && (this_min_head < newsel_max_tail) && (newsel_max_tail <= this_max_tail))))
                must_unsel = false;
            
            if (must_unsel)
                llll_appendobj(selitems_to_unsel, it);
            
            llll_free(tieseq);
        }
        
        for (t_llllelem *elem = selitems_to_unsel->l_head; elem; elem = elem->l_next)
            notation_item_delete_from_selection(r_ob, (t_notation_item *)hatom_getobj(&elem->l_hatom));
        
        llll_free(selitems_to_unsel);
    }
    
    
    
    // Setting new selection
    for (t_llllelem *elem = toselect->l_head; elem; elem = elem->l_next) {
        t_notation_item *it = (t_notation_item *)hatom_getobj(&elem->l_hatom);
        notation_item_add_to_preselection(r_ob, it);
    }
    
    move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_FORCE_SELECT, false, false);
    
    return k_GOTO_ERROR_NONE;
}



long llll_sort_by_head(void *data, t_llllelem *a, t_llllelem *b)
{
    t_goto_params *par = (t_goto_params *)data;
    t_notation_obj *r_ob = par->notation_obj;
    t_notation_item *a_it = (t_notation_item *)hatom_getobj(&a->l_hatom);
    t_notation_item *b_it = (t_notation_item *)hatom_getobj(&b->l_hatom);
    return (goto_notation_item_get_onset(r_ob, par, a_it) <= goto_notation_item_get_onset(r_ob, par, b_it));
}

long llll_sort_by_tail(void *data, t_llllelem *a, t_llllelem *b)
{
    t_goto_params *par = (t_goto_params *)data;
    t_notation_obj *r_ob = par->notation_obj;
    t_notation_item *a_it = (t_notation_item *)hatom_getobj(&a->l_hatom);
    t_notation_item *b_it = (t_notation_item *)hatom_getobj(&b->l_hatom);
    return (goto_notation_item_get_tail(r_ob, par, a_it) <= goto_notation_item_get_tail(r_ob, par, b_it));
}


// what_to_keep = -1: keep items with minimum head/tail
// what_to_keep = 1: keep items with maximum head/tail
void goto_sieve_selection_llll(t_notation_obj *r_ob, t_goto_params *par, t_llll **ll, char what_to_keep, long onset_element)
{
    if (onset_element == k_GOTO_ONSETPOINT_TAIL)
        llll_mergesort_inplace(ll, llll_sort_by_tail, par);
    else
        llll_mergesort_inplace(ll, llll_sort_by_head, par);
    
    if (what_to_keep != 0 && (par->voicemode == k_GOTO_VOICEMODE_ANY || par->voicemode == k_GOTO_VOICEMODE_ANYACTIVE) && (*ll) && (*ll)->l_head) {
        long count = 1;
        if (what_to_keep < 0) {
            double onset_min;
            if (onset_element == k_GOTO_ONSETPOINT_TAIL)
                onset_min = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)hatom_getobj(&(*ll)->l_head->l_hatom));
            else
                onset_min = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)hatom_getobj(&(*ll)->l_head->l_hatom));
            
            for (t_llllelem *el = (*ll)->l_head->l_next; el; el = el->l_next, count++) {
                double el_ms;
                if (onset_element == k_GOTO_ONSETPOINT_TAIL)
                    el_ms = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)hatom_getobj(&el->l_hatom));
                else
                    el_ms = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)hatom_getobj(&el->l_hatom));
                
                if (el_ms > onset_min) {
                    break;
                }
            }
            llll_free(llll_slice(*ll, count));
        } else if (what_to_keep > 0) {
            double onset_max;
            if (onset_element == k_GOTO_ONSETPOINT_TAIL)
                onset_max = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)hatom_getobj(&(*ll)->l_tail->l_hatom));
            else
                onset_max = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)hatom_getobj(&(*ll)->l_tail->l_hatom));
            
            for (t_llllelem *el = (*ll)->l_tail->l_prev; el; el = el->l_prev, count++) {
                double el_ms;
                if (onset_element == k_GOTO_ONSETPOINT_TAIL)
                    el_ms = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)hatom_getobj(&el->l_hatom));
                else
                    el_ms = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)hatom_getobj(&el->l_hatom));
               
                if (el_ms < onset_max) {
                    break;
                }
            }
            t_llll *newll = llll_slice(*ll, -count);
            llll_free(*ll);
            *ll = newll;
        }
    }
}


void goto_copy_allowed_types(char *a1, char *a2)
{
    for (long i = 0; i < k_NUM_ELEMENT_TYPES; i++)
        a2[i] = a1[i];
}

t_llll *goto_get_first_notation_item_after_ms(t_notation_obj *r_ob, t_goto_params *par, double ms, char unselected_only, long *error)
{
    t_llll *toselect = llll_get();
    
    long activevoicenum = r_ob->lastselecteditem ? notation_item_get_voicenumber(r_ob, r_ob->lastselecteditem) : -1;
    char allowed_types[k_NUM_ELEMENT_TYPES];
    goto_copy_allowed_types(par->allowed_types, allowed_types);
    
    char not_tied_from = (par->tiemode == k_GOTO_TIEMODE_TO || par->tiemode == k_GOTO_TIEMODE_ALL);
    
    if (par->num_allowed_types == 0 && r_ob->lastselecteditem)
        if (r_ob->lastselecteditem->type > 0 && r_ob->lastselecteditem->type < k_NUM_ELEMENT_TYPES)
            allowed_types[r_ob->lastselecteditem->type] = 1;
    
    if (allowed_types[k_VOICE]) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)voice))
                    continue;
                llll_appendobj(toselect, voice);
            }
        }
    }

    if (allowed_types[k_MEASURE]) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                    for (t_measure *meas = ((t_scorevoice *)voice)->firstmeasure; meas; meas = meas->next) {
                        if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)meas))
                            continue;
                        double onset;
                        if (par->to == k_GOTO_ONSETPOINT_TAIL)
                            onset = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)meas);
                        else
                            onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)meas);
                        if (onset > ms || (!par->strictcmp && onset == ms)) {
                            llll_appendobj(toselect, meas);
                            break;
                        }
                    }
                }
            }
        }
    }

    if (allowed_types[k_TEMPO]) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                    for (t_tempo *tempo = tempo_get_first((t_scorevoice *)voice); tempo; tempo = tempo_get_next(tempo)) {
                        if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)tempo))
                            continue;
                        double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)tempo);
                        if (onset > ms || (!par->strictcmp && onset == ms)) {
                            llll_appendobj(toselect, tempo);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if (allowed_types[k_CHORD] || allowed_types[k_NOTE]) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                for (t_chord *chord = chord_get_first(r_ob, voice); chord; chord = chord_get_next(chord)) {
                    if (!chord->firstnote && par->skiprests)
                        continue;
                    if (unselected_only && allowed_types[k_CHORD] && notation_item_is_selected(r_ob, (t_notation_item *)chord))
                        continue;
                    if (not_tied_from && allowed_types[k_CHORD] && chord_is_all_tied_from(chord, false))
                        continue;
                    double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)chord);
                    double duration = goto_notation_item_get_duration(r_ob, par, (t_notation_item *)chord);
                    
                    char next_chord_has_same_onset = (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && chord->next && goto_notation_item_get_onset(r_ob, par, (t_notation_item *)chord->next) == onset);
                    
                    if (par->to == k_GOTO_ONSETPOINT_TAIL) {
                        if (allowed_types[k_CHORD]) {
                            onset = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)chord);
                            if (onset > ms || (!par->strictcmp && onset == ms)) {
                                llll_appendobj(toselect, chord);
                                if (duration > 0 && !next_chord_has_same_onset)
                                    break;
                            }
                        } else {
                            char then_break = false;
                            for (t_note *nt = chord->firstnote; nt; nt = nt->next) {
                                if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)nt))
                                    continue;
                                if (not_tied_from && nt->tie_from)
                                    continue;
                                double nt_onset = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)nt);
                                if (nt_onset > ms || (!par->strictcmp && nt_onset == ms)) {
                                    llll_appendobj(toselect, nt);
                                    if (!then_break && goto_notation_item_get_duration(r_ob, par, (t_notation_item *)nt) > 0 && !next_chord_has_same_onset)
                                        then_break = true;
                                }
                            }
                            if (then_break)
                                break;
                        }
                    } else {
                        if (onset > ms || (!par->strictcmp && onset == ms)) {
                            if (allowed_types[k_CHORD]) {
                                llll_appendobj(toselect, chord);
                                if (duration > 0 && !next_chord_has_same_onset)
                                    break;
                            } else {
                                char then_break = false;
                                for (t_note *nt = chord->firstnote; nt; nt = nt->next) {
                                    if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)nt))
                                        continue;
                                    if (not_tied_from && nt->tie_from)
                                        continue;
                                    llll_appendobj(toselect, nt);
                                    if (!then_break && goto_notation_item_get_duration(r_ob, par, (t_notation_item *)nt) > 0 && !next_chord_has_same_onset)
                                        then_break = true;
                                }
                                if (then_break)
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (allowed_types[k_MARKER]) {
        for (t_marker *mk = r_ob->firstmarker; mk; mk = mk->next) {
            if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE && par->markershavevoices && !goto_account_for_voice(par, goto_get_marker_voicenumber(r_ob, mk), activevoicenum))
                continue;
            if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)mk))
                continue;
            double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)mk);
            if (onset > ms || (!par->strictcmp && onset == ms)) {
                llll_appendobj(toselect, mk);
                break;
            }
        }
    }
    
    goto_sieve_selection_llll(r_ob, par, &toselect, -1, par->to);
    return toselect;
}


t_llll *goto_get_first_notation_item_before_ms(t_notation_obj *r_ob, t_goto_params *par, double ms, char unselected_only, long *error)
{
    t_llll *toselect = llll_get();
    
    long activevoicenum = r_ob->lastselecteditem ? notation_item_get_voicenumber(r_ob, r_ob->lastselecteditem) : -1;
    char allowed_types[k_NUM_ELEMENT_TYPES];
    goto_copy_allowed_types(par->allowed_types, allowed_types);
    
    // I don't think we need this when scrolling backwards... Actually in this form it gave problems with tied sequences
    char not_tied_from = false; //(par->tiemode == k_GOTO_TIEMODE_FROM || par->tiemode == k_GOTO_TIEMODE_ALL);

    if (par->num_allowed_types == 0 && r_ob->lastselecteditem)
        if (r_ob->lastselecteditem->type > 0 && r_ob->lastselecteditem->type < k_NUM_ELEMENT_TYPES)
            allowed_types[r_ob->lastselecteditem->type] = 1;
    
    if (allowed_types[k_VOICE]) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)voice))
                    continue;
                llll_appendobj(toselect, voice);
            }
        }
    }
    
    if (allowed_types[k_MEASURE]) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                    for (t_measure *meas = ((t_scorevoice *)voice)->lastmeasure; meas; meas = meas->prev) {
                        if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)meas))
                            continue;
                        double onset;
                        if (par->to == k_GOTO_ONSETPOINT_TAIL)
                            onset = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)meas);
                        else
                            onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)meas);
                        if (onset < ms || (!par->strictcmp && onset == ms)) {
                            llll_appendobj(toselect, meas);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if (allowed_types[k_TEMPO]) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                    for (t_tempo *tempo = tempo_get_last((t_scorevoice *)voice); tempo; tempo = tempo_get_prev(tempo)) {
                        if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)tempo))
                            continue;
                        double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)tempo);
                        if (onset < ms || (!par->strictcmp && onset == ms)) {
                            llll_appendobj(toselect, tempo);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if (allowed_types[k_CHORD] || allowed_types[k_NOTE]) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                for (t_chord *chord = chord_get_last(r_ob, voice); chord; chord = chord_get_prev(chord)) {
                    if (!chord->firstnote && par->skiprests)
                        continue;
                    if (unselected_only && allowed_types[k_CHORD] && notation_item_is_selected(r_ob, (t_notation_item *)chord))
                        continue;
                    if (allowed_types[k_CHORD] && not_tied_from && chord_is_all_tied_from(chord, false))
                        continue;
                    double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)chord);
                    double duration = goto_notation_item_get_duration(r_ob, par, (t_notation_item *)chord);
                    
                    char prev_chord_has_same_onset = (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && chord->prev && goto_notation_item_get_onset(r_ob, par, (t_notation_item *)chord->prev) == onset);

                    
                    if (par->to == k_GOTO_ONSETPOINT_TAIL) {
                        if (allowed_types[k_CHORD]) {
                            onset = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)chord);
                            if (onset < ms || (!par->strictcmp && onset == ms)) {
                                llll_appendobj(toselect, chord);
                                if (duration > 0 && !prev_chord_has_same_onset)
                                    break;
                            }
                        } else {
                            char then_break = false;
                            for (t_note *nt = chord->firstnote; nt; nt = nt->next) {
                                if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)nt))
                                    continue;
                                if (not_tied_from && nt->tie_from)
                                    continue;
                                double nt_onset = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)nt);
                                if (nt_onset < ms || (!par->strictcmp && nt_onset == ms)) {
                                    llll_appendobj(toselect, nt);
                                    if (!then_break && goto_notation_item_get_duration(r_ob, par, (t_notation_item *)nt) > 0 && !prev_chord_has_same_onset)
                                        then_break = true;
                                }
                            }
                            if (then_break)
                                break;
                        }
                    } else {
                        if (onset < ms || (!par->strictcmp && onset == ms)) {
                            if (allowed_types[k_CHORD]) {
                                llll_appendobj(toselect, chord);
                                if (duration > 0 && !prev_chord_has_same_onset)
                                    break;
                            } else {
                                char then_break = false;
                                for (t_note *nt = chord->firstnote; nt; nt = nt->next) {
                                    if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)nt))
                                        continue;
                                    if (not_tied_from && nt->tie_from)
                                        continue;
                                    llll_appendobj(toselect, nt);
                                    if (!then_break && goto_notation_item_get_duration(r_ob, par, (t_notation_item *)nt) > 0 && !prev_chord_has_same_onset)
                                        then_break = true;
                                }
                                if (then_break)
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (allowed_types[k_MARKER]) {
        for (t_marker *mk = r_ob->lastmarker; mk; mk = mk->prev) {
            if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE && par->markershavevoices && !goto_account_for_voice(par, goto_get_marker_voicenumber(r_ob, mk), activevoicenum))
                continue;
            if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)mk))
                continue;
            double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)mk);
            if (onset < ms || (!par->strictcmp && onset == ms)) {
                llll_appendobj(toselect, mk);
                break;
            }
        }
    }
    
    goto_sieve_selection_llll(r_ob, par, &toselect, 1, par->to);
    return toselect;
}





t_notation_item *get_prev_notation_item(t_notation_obj *r_ob, t_notation_item *it, char skip_rests)
{
    if (!it)
        return NULL;
    else {
        switch (it->type) {
            case k_NOTE:
                return (t_notation_item *)((t_note *)it)->prev;
                
            case k_CHORD:
                return (t_notation_item *)(skip_rests ? chord_get_prev_nonrest((t_chord *)it) : chord_get_prev((t_chord *)it));
                
            case k_TEMPO:
                return (t_notation_item *)(tempo_get_prev((t_tempo *)it));
                
            case k_MARKER:
                return (t_notation_item *)((t_marker *)it)->prev;
                
            case k_MEASURE:
                return (t_notation_item *)measure_get_prev((t_measure *)it);
                
            case k_VOICE:
                return (t_notation_item *)voice_get_prev(r_ob, (t_voice *)it);
                
            default:
                return NULL;
                break;
        }
    }
}



t_notation_item *goto_get_last_selected_item(t_llll *current_selection)
{
    if (current_selection && current_selection->l_tail)
        return (t_notation_item *)hatom_getobj(&current_selection->l_tail->l_hatom);
    return NULL;
}


t_notation_item *goto_get_first_selected_item(t_llll *current_selection)
{
    if (current_selection && current_selection->l_head)
        return (t_notation_item *)hatom_getobj(&current_selection->l_head->l_hatom);
    return NULL;
}


t_llll *goto_get_nextprev_notation_item(t_notation_obj *r_ob, t_goto_params *par, long *error)
{
    long direction = 0;
    t_llll *toselect = llll_get();
   
    if (par->command == _llllobj_sym_next)
        direction = 1;
    else if (par->command == _llllobj_sym_prev)
        direction = -1;
    
    *error = k_GOTO_ERROR_NONE;
    t_notation_item *curr_cur = direction > 0 ? r_ob->lastselecteditem : r_ob->firstselecteditem;
//    t_notation_item *curr_cur = direction > 0 ? goto_get_last_selected_item(current_selection) : goto_get_first_selected_item(current_selection);
    
    if (par->tiemode == k_GOTO_TIEMODE_ALL) {
        // account for all-tied sequences
        t_notation_item *tmp_it;
        if (direction > 0) {
            while (curr_cur) {
                if (curr_cur->type == k_CHORD && chord_is_all_tied_from((t_chord *)curr_cur, false) &&
                    (tmp_it = (t_notation_item *)chord_get_prev((t_chord *)curr_cur)) && notation_item_is_selected(r_ob, tmp_it)) {
                    curr_cur = tmp_it;
                } else if (curr_cur->type == k_NOTE && ((t_note *)curr_cur)->tie_from && ((t_note *)curr_cur)->tie_from != WHITENULL &&
                           notation_item_is_selected(r_ob, (t_notation_item *)((t_note *)curr_cur)->tie_from)) {
                        curr_cur = (t_notation_item *)((t_note *)curr_cur)->tie_from;
                } else
                    break;
            }
        }
    }
    
    
    if (curr_cur) {
        t_llll *selection_ll = goto_get_selection_as_llll(r_ob);
        double ms = (par->from == k_GOTO_ONSETPOINT_HEAD) ? get_max_head(r_ob, par, selection_ll) : get_min_tail(r_ob, par, selection_ll);
        
        if (direction > 0)
            llll_chain(toselect, goto_get_first_notation_item_after_ms(r_ob, par, ms, true, error));
        else if (direction < 0)
            llll_chain(toselect, goto_get_first_notation_item_before_ms(r_ob, par, ms, true, error));
        
        llll_free(selection_ll);
    } else
        *error = k_GOTO_ERROR_NOTFOUND;
    
    return toselect;
}


char is_condition_satisfied(t_notation_obj *r_ob, t_notation_item *item, t_lexpr *condition)
{
    t_hatom *res = lexpr_eval_for_notation_item(r_ob, item, condition);
    char ans = false;
    if (res && hatom_gettype(res) == H_LONG && hatom_getlong(res) != 0) {
        ans = true;
    }
    if (res)
        bach_freeptr(res);
    
    return ans;
}

t_llll *goto_get_lrud_notation_item(t_notation_obj *r_ob, t_goto_params *par, long *error)
{
    *error = k_GOTO_ERROR_NOTFOUND;
    t_llll *toselect = llll_get();
    
    t_notation_item *curr_cur = r_ob->firstselecteditem;
    
    if (curr_cur) {
        t_notation_item *newit = NULL;
        if (par->command == _llllobj_sym_left)
            newit = notation_item_get_at_left(r_ob, curr_cur, par->skiprests);
        else if (par->command == _llllobj_sym_right)
            newit = notation_item_get_at_right(r_ob, curr_cur, par->skiprests);
        else if (par->command == _sym_up)
            newit = notation_item_get_at_top(r_ob, curr_cur, par->skiprests);
        else if (par->command == _sym_down)
            newit = notation_item_get_at_bottom(r_ob, curr_cur, par->skiprests);
        if (newit) {
            *error = k_GOTO_ERROR_NONE;
            llll_appendobj(toselect, newit);
        }
    }
    
    return toselect;
}




/*
e_goto_error set_selection_to_notation_item_with_index(t_notation_obj *r_ob, t_goto_params *par)
{
    e_goto_error res = k_GOTO_ERROR_NOTFOUND;
    t_llll *items_to_select = llll_get();
    
    switch (par->nitem_type) {
        case k_CHORD:
            for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                t_chord *ch = nth_chord_of_rollvoice(voice, n)
                llll_append
            }
            break;
            
        default:
            break;
    }
    
    if ((par->nitem_type != k_NONE && par->nitem_type != curr_cur->type) ||
        (par->voicenumbers && (par->voicenumbers->l_size != 1 || hatom_getlong(&par->voicenumbers->l_head->l_hatom) != notation_item_get_voicenumber(r_ob, curr_cur)))) {
        res = k_GOTO_ERROR_WRONGPARAMS;
        //            res = set_selection_to_notation_item_after_ms(r_ob, par);
    } else {
        lock_general_mutex(r_ob);
        t_notation_item *newit = NULL;
        if (par->command == _llllobj_sym_left)
            newit = notation_item_get_at_left(r_ob, curr_cur);
        else if (par->command == _llllobj_sym_right)
            newit = notation_item_get_at_right(r_ob, curr_cur);
        else if (par->command == _sym_up)
            newit = notation_item_get_at_top(r_ob, curr_cur);
        else if (par->command == _sym_down)
            newit = notation_item_get_at_bottom(r_ob, curr_cur);
        clear_selection(r_ob);
        if (newit) {
            res = k_GOTO_ERROR_NONE;
            notation_item_add_to_preselection(r_ob, newit);
            move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_FORCE_SELECT, false, false);
        }
        notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
        unlock_general_mutex(r_ob);
    }
    
    return res;
}
*/

t_llll *goto_get_notation_item_at_ms(t_notation_obj *r_ob, t_goto_params *par, double ms, char unselected_only, long *error)
{
    t_llll *toselect = llll_get();
    
    long activevoicenum = r_ob->lastselecteditem ? notation_item_get_voicenumber(r_ob, r_ob->lastselecteditem) : -1;
    char allowed_types[k_NUM_ELEMENT_TYPES];
    goto_copy_allowed_types(par->allowed_types, allowed_types);
    
    if (par->num_allowed_types == 0) {
        allowed_types[k_CHORD] = 1;
        allowed_types[k_MARKER] = 1;
    }
    
    if (allowed_types[k_VOICE]) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)voice))
                    continue;
                llll_appendobj(toselect, voice);
            }
        }
    }
    
    if (allowed_types[k_MEASURE]) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                    for (t_measure *meas = ((t_scorevoice *)voice)->firstmeasure; meas; meas = meas->next) {
                        if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)meas))
                            continue;
                        
                        double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)meas);
                        double tail = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)meas);
                        
                        if (onset > ms)
                            break;

                        if (onset < ms && ms < tail) {
                            llll_appendobj(toselect, meas);
                            break;
                        } else if (onset == ms && tail == ms && (par->matchinclude & (k_GOTO_ONSETPOINT_HEAD | k_GOTO_ONSETPOINT_TAIL))) { // 0-length measure?!?
                            llll_appendobj(toselect, meas); // won't break
                        } else if (tail == ms && (par->matchinclude & k_GOTO_ONSETPOINT_TAIL)) {
                            llll_appendobj(toselect, meas);
                            if (!(par->matchinclude & k_GOTO_ONSETPOINT_HEAD)) // otherwise, we might also select the next one!
                                break;
                        } else if (onset == ms && (par->matchinclude & k_GOTO_ONSETPOINT_HEAD)) {
                            llll_appendobj(toselect, meas);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    if (allowed_types[k_TEMPO]) {
        if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
            for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
                if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                    for (t_tempo *tempo = tempo_get_first((t_scorevoice *)voice); tempo; tempo = tempo_get_next(tempo)) {
                        if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)tempo))
                            continue;
                        double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)tempo);

                        if (onset > ms)
                            break;

                        if (onset == ms) {
                            llll_appendobj(toselect, tempo);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    
    if (allowed_types[k_CHORD] || allowed_types[k_NOTE]) {
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            if (goto_account_for_voice(par, voice->number, activevoicenum)) {
                for (t_chord *chord = chord_get_first(r_ob, voice); chord; chord = chord_get_next(chord)) {
                    if (!chord->firstnote && par->skiprests)
                        continue;
                    if (unselected_only && allowed_types[k_CHORD] && notation_item_is_selected(r_ob, (t_notation_item *)chord))
                        continue;
                    
                    double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)chord);
                    double tail = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)chord);
                    
                    if (tail < ms)
                        continue;
                    if (onset > ms)
                        break;
                    
                    if (allowed_types[k_CHORD]) {
                        if (onset < ms && ms < tail) {
                            llll_appendobj(toselect, chord);
                        } else if (onset == ms && tail == ms && (par->matchinclude & (k_GOTO_ONSETPOINT_HEAD | k_GOTO_ONSETPOINT_TAIL))) { // 0-length chord
                            llll_appendobj(toselect, chord);
                        } else if (tail == ms && (par->matchinclude & k_GOTO_ONSETPOINT_TAIL)) {
                            llll_appendobj(toselect, chord);
                        } else if (onset == ms && (par->matchinclude & k_GOTO_ONSETPOINT_HEAD)) {
                            llll_appendobj(toselect, chord);
                        }
                    } else {
                        for (t_note *nt = chord->firstnote; nt; nt = nt->next) {
                            if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)nt))
                                continue;
                            tail = goto_notation_item_get_tail(r_ob, par, (t_notation_item *)nt);

                            if (onset < ms && ms < tail) {
                                llll_appendobj(toselect, nt);
                            } else if (onset == ms && tail == ms && (par->matchinclude & (k_GOTO_ONSETPOINT_HEAD | k_GOTO_ONSETPOINT_TAIL))) { // 0-length note
                                llll_appendobj(toselect, nt);
                            } else if (tail == ms && (par->matchinclude & k_GOTO_ONSETPOINT_TAIL)) {
                                llll_appendobj(toselect, nt);
                            } else if (onset == ms && (par->matchinclude & k_GOTO_ONSETPOINT_HEAD)) {
                                llll_appendobj(toselect, nt);
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (allowed_types[k_MARKER]) {
        for (t_marker *mk = r_ob->firstmarker; mk; mk = mk->next) {
            if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE && par->markershavevoices && !goto_account_for_voice(par, goto_get_marker_voicenumber(r_ob, mk), activevoicenum))
                continue;
            if (unselected_only && notation_item_is_selected(r_ob, (t_notation_item *)mk))
                continue;
            double onset = goto_notation_item_get_onset(r_ob, par, (t_notation_item *)mk);
            
            if (onset > ms)
                break;
            
            if (onset == ms) {
                llll_appendobj(toselect, mk);
                break;
            }
        }
    }
    
    return toselect;
}


t_llll *goto_get_notation_item_at_timepoint(t_notation_obj *r_ob, t_goto_params *par, t_timepoint tp, char unselected_only, long *error)
{
    t_llll *toselect = llll_get();
    
    long activevoicenum = r_ob->lastselecteditem ? notation_item_get_voicenumber(r_ob, r_ob->lastselecteditem) : -1;
    char allowed_types[k_NUM_ELEMENT_TYPES];
    goto_copy_allowed_types(par->allowed_types, allowed_types);
    
    return toselect;
}


t_llll *goto_time(t_notation_obj *r_ob, t_goto_params *par, long *error)
{
    double ms;
    t_timepoint tp;
    t_llll *toselect = llll_get();
    
    if (!par->arguments || !par->arguments->l_head) {
        *error = k_GOTO_ERROR_WRONGARGUMENTS;
        return toselect;
    }
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        if (is_hatom_number(&par->arguments->l_head->l_hatom)) {
            ms = hatom_getdouble(&par->arguments->l_head->l_hatom);
            llll_chain(toselect, goto_get_notation_item_at_ms(r_ob, par, ms, false, error));
        }
    } else if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        parse_open_timepoint_syntax_from_llllelem(r_ob, par->arguments->l_head, NULL, &ms, &tp, true,
                                                  true, // accurate parsing
                                                  par->nudge_back_for_graces); // we nudge back grace notes
        llll_chain(toselect, goto_get_notation_item_at_ms(r_ob, par, ms, false, error));
    }
    
    return toselect;
}


t_llll *goto_sieve_selection_for_voice(t_notation_obj *r_ob, t_llll *selection, long voicenum, char include_elems_with_no_voice)
{
    t_llll *out = llll_get();
    
    for (t_llllelem *elem = selection->l_head; elem; elem = elem->l_next){
        t_notation_item *item = (t_notation_item *)hatom_getobj(&elem->l_hatom);
        long this_voicenum = notation_item_get_voicenumber(r_ob, item);
        if ((this_voicenum < 0 && include_elems_with_no_voice) || (this_voicenum == voicenum))
            llll_appendobj(out, item);
    }
    return out;
}


void goto_resync_selection_active_voices(t_notation_obj *r_ob, t_goto_params *par)
{
    for (long i = 0; i < CONST_MAX_VOICES; i++)
        par->activevoices[i] = 0;

    for (t_notation_item *it = r_ob->firstselecteditem; it; it = it->next_selected) {
        long this_voicenum = notation_item_get_voicenumber(r_ob, it);
        if (it->type != k_MARKER || par->markershavevoices)
            if (this_voicenum >= 0 && this_voicenum < CONST_MAX_VOICES)
                par->activevoices[this_voicenum] = 1;
    }
}

t_llll *notationobj_goto_do(t_notation_obj *r_ob, t_goto_params *par, long *error)
{
    t_llll *toselect = NULL;
    long err = k_GOTO_ERROR_NONE;
    char do_this_again = false;
    long count = 0;
    
    if (par->repeat <= 0)
        return NULL;

    do {
        
        count++;
    
        if (toselect) {
            llll_free(toselect);
            toselect = NULL;
        }
        
        // sync with active voices
        if (par->voicemode == k_GOTO_VOICEMODE_ALLACTIVE || par->voicemode == k_GOTO_VOICEMODE_ANYACTIVE)
            goto_resync_selection_active_voices(r_ob, par);
        
        if (par->command == _llllobj_sym_next || par->command == _llllobj_sym_prev) {
            toselect = goto_get_nextprev_notation_item(r_ob, par, &err);
        } else if (par->command == _sym_up || par->command == _sym_down || par->command == _llllobj_sym_left || par->command == _llllobj_sym_right) {
            toselect = goto_get_lrud_notation_item(r_ob, par, &err);
            //        } else if (par->command == _sym_index) {
            //            res = set_selection_to_notation_item_with_index(r_ob, par);
        } else if (par->command == _llllobj_sym_time || par->command == _llllobj_sym_timepoint) {
            toselect = goto_time(r_ob, par, &err);
        } else {
            err = k_GOTO_ERROR_WRONGCOMMAND;
        }
        
        // subselecting according to 'where' clause
        if (par->where) {
            t_llllelem *nextelem = toselect->l_head ? toselect->l_head->l_next : NULL;
            for (t_llllelem *elem = toselect->l_head; elem; elem = nextelem) {
                nextelem = elem->l_next;
                if (!is_condition_satisfied(r_ob, (t_notation_item *)hatom_getobj(&elem->l_hatom), par->where))
                    llll_destroyelem(elem);
            }
        }
        
        e_goto_error err_sel = goto_set_selection_from_llll(r_ob, par, toselect);
        if (err == k_GOTO_ERROR_NONE)
            err = err_sel;
        
        // checking if we have to do this again because 'until' clause is not matched
        do_this_again = false;
        if (count < par->repeat)
            do_this_again = true;
        else {
            if (err == k_GOTO_ERROR_NONE && r_ob->firstselecteditem && par->until) {
                if (par->untilmode == k_GOTO_UNTILMODE_ANY)
                    do_this_again = true;
                
                for (t_llllelem *elem = toselect->l_head; elem; elem = elem->l_next) {
                    long this_ans = is_condition_satisfied(r_ob, (t_notation_item *)hatom_getobj(&elem->l_hatom), par->until);
                    if (par->untilmode == k_GOTO_UNTILMODE_ANY) {
                        if (this_ans) {
                            do_this_again = false;
                            break;
                        }
                    } else {
                        if (!this_ans) {
                            do_this_again = true;
                            break;
                        }
                    }
                }
            }
        }
        
    } while (err == k_GOTO_ERROR_NONE && do_this_again);

    
    *error = err;
    return toselect;
}


e_goto_error goto_errors_and(t_llll *errors)
{
    if (is_long_in_llll_first_level(errors, k_GOTO_ERROR_NONE))
        return k_GOTO_ERROR_NONE;

    if (is_long_in_llll_first_level(errors, k_GOTO_ERROR_WRONGCOMMAND))
        return k_GOTO_ERROR_WRONGCOMMAND;

    if (is_long_in_llll_first_level(errors, k_GOTO_ERROR_WRONGARGUMENTS))
        return k_GOTO_ERROR_WRONGARGUMENTS;

    if (is_long_in_llll_first_level(errors, k_GOTO_ERROR_WRONGPARAMS))
        return k_GOTO_ERROR_WRONGPARAMS;
    
    return k_GOTO_ERROR_NONE;
}

e_goto_error notationobj_goto(t_notation_obj *r_ob, t_goto_params *par)
{
    long err = k_GOTO_ERROR_NONE;
    t_llll *toselect = NULL;
    
    sort_selection(r_ob, false);

    lock_general_mutex(r_ob);
    
    if (par->voicemode == k_GOTO_VOICEMODE_EACH) {
        // hard case: looping through voices
        t_goto_params par_temp = *par; // I know: we're not cloning lllls, doesn't matter, we'll do things manually
        toselect = llll_get();
        t_llll *orig_sel = goto_get_selection_as_llll(r_ob);
        t_llll *errors = llll_get();
        par_temp.tiemode = k_GOTO_TIEMODE_EACH;
        
        for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
            if (goto_account_for_voice(par, voice->number, -1)) {
                
                par_temp.voicenumbers = llll_get();
                llll_appendlong(par_temp.voicenumbers, voice->number);
                
                t_llll *sel_for_voice = goto_sieve_selection_for_voice(r_ob, orig_sel, voice->number, false);
                goto_set_selection_from_llll(r_ob, par, sel_for_voice);
                
                long this_error = k_GOTO_ERROR_NONE;
                t_llll *this_select = notationobj_goto_do(r_ob, &par_temp, &this_error);
                if (this_select)
                    llll_chain(toselect, this_select);
                llll_appendlong(errors, this_error);
                
                llll_free(sel_for_voice);
                llll_free(par_temp.voicenumbers);
            }
        }
        
        // and now all the elements that have NO voice
        {
            par_temp.voicenumbers = llll_get();
            llll_appendlong(par_temp.voicenumbers, -1);
            
            t_llll *sel_for_voice = goto_sieve_selection_for_voice(r_ob, orig_sel, -1, false);
            goto_set_selection_from_llll(r_ob, par, sel_for_voice);
            
            long this_error = k_GOTO_ERROR_NONE;
            t_llll *this_select = notationobj_goto_do(r_ob, &par_temp, &this_error);
            if (this_select)
                llll_chain(toselect, this_select);
            llll_appendlong(errors, this_error);
            
            llll_free(sel_for_voice);
            llll_free(par_temp.voicenumbers);
        }
        
        goto_set_selection_from_llll(r_ob, par, toselect);

        // compatibilize errors
        err = goto_errors_and(errors);
        llll_free(errors);
        llll_free(orig_sel);
    } else {
        // simple case
        toselect = notationobj_goto_do(r_ob, par, &err);
    }

    
//    if (err == k_GOTO_ERROR_NONE)
//        err = goto_set_selection_from_llll(r_ob, par, toselect);
    
    if (par->force_inscreen && r_ob->force_notation_item_inscreen && toselect) {
        for (t_llllelem *el = toselect->l_head; el; el = el->l_next)
            (r_ob->force_notation_item_inscreen)(r_ob, (t_notation_item *)hatom_getobj(&el->l_hatom), NULL);
    }

    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);

    if (toselect)
        llll_free(toselect);

    unlock_general_mutex(r_ob);
    
    return (e_goto_error)err;
}



t_goto_params notationobj_goto_get_default_params(t_notation_obj *r_ob)
{
    t_goto_params par;
    par.command = _llllobj_sym_none;
    for (long i = 0; i < k_NUM_ELEMENT_TYPES; i++)
        par.allowed_types[i] = 0;
    par.num_allowed_types = 0;
    par.where = par.until = NULL;
    par.skiprests = 0;
    par.voicenumbers = NULL;
    par.nullmode = 1;
    par.arguments = NULL;
    par.strictcmp = 1;
    par.tiemode = k_GOTO_TIEMODE_ALL;
    par.from = k_GOTO_ONSETPOINT_AUTO;
    par.to = k_GOTO_ONSETPOINT_AUTO;
    
    par.voicemode = k_GOTO_VOICEMODE_ANYACTIVE;
    par.polymode = k_GOTO_POLYMODE_OVERLAP;
    
    
    // Other meaningful defaults could have been
    //    par.voicemode = k_GOTO_VOICEMODE_ALLACTIVE;
    //    par.polymode = k_GOTO_POLYMODE_NONE;
    // or
    //    par.voicemode = k_GOTO_VOICEMODE_EACH;
    //    par.polymode = k_GOTO_POLYMODE_NONE;
    
    
    par.matchinclude = k_GOTO_ONSETPOINT_HEAD;
    par.force_inscreen = 0;
    par.graces_have_duration = 0;
    par.nudge_back_for_graces = -1;
    par.repeat = 1;
    par.markershavevoices = 0;
    par.notation_obj = r_ob;
    for (long i = 0; i < CONST_MAX_VOICES; i++)
        par.activevoices[i] = 0;
    
    return par;
}

void notationobj_goto_parseargs(t_notation_obj *r_ob, t_llll *args)
{
    t_goto_params par = notationobj_goto_get_default_params(r_ob);
    
    t_llll *where_ll = NULL, *until_ll = NULL, *types_ll = NULL, *matchinclude_ll = NULL;
    t_symbol *voicemode_sym = gensym("anyactive"), *tiemode_sym = _llllobj_sym_all, *from_sym = _llllobj_sym_auto, *to_sym = _llllobj_sym_auto, *polymode_sym = gensym("overlap"), *untilmode_sym = _llllobj_sym_any;

    llll_parseargs_and_attrs_destructive((t_object *) r_ob, args, "iiiiiiilllllssssssi", gensym("repeat"), &par.repeat, gensym("inscreen"), &par.force_inscreen, gensym("skiprests"), &par.skiprests, gensym("nullmode"), &par.nullmode, gensym("strict"), &par.strictcmp, gensym("graceshavedur"), &par.graces_have_duration, gensym("markershavevoices"), &par.markershavevoices, gensym("voices"), &par.voicenumbers, gensym("where"), &where_ll, gensym("until"), &until_ll, gensym("type"), &types_ll, gensym("include"), &matchinclude_ll, gensym("voicemode"), &voicemode_sym, gensym("tiemode"), &tiemode_sym, gensym("from"), &from_sym, gensym("to"), &to_sym, gensym("polymode"), &polymode_sym, gensym("untilmode"), &untilmode_sym, gensym("nudgeforgraces"), &par.nudge_back_for_graces);
    
    for (t_llllelem *el = types_ll ? types_ll->l_head : NULL; el; el = el->l_next) {
        if (hatom_getsym(&el->l_hatom) == _llllobj_sym_all) {
            for (long i = 0; i < k_NUM_ELEMENT_TYPES; i++)
                par.allowed_types[i] = 1;
            break;
        }
        
        long this_type = symbol_to_notationitem_type(r_ob, hatom_getsym(&el->l_hatom));
        if (this_type > 0 && this_type < k_NUM_ELEMENT_TYPES) {
            if (!par.allowed_types[this_type])
                par.num_allowed_types++;
            par.allowed_types[this_type] = 1;
        }
    }
    
    par.voicemode = sym_to_voicemode(voicemode_sym);
    par.tiemode = sym_to_tiemode(tiemode_sym);
    par.from = sym_to_onsetpoint(from_sym);
    par.to = sym_to_onsetpoint(to_sym);
    par.polymode = sym_to_polymode(polymode_sym);
    par.untilmode = sym_to_untilmode(untilmode_sym);
    
    if (matchinclude_ll) {
        par.matchinclude = 0;
        for (t_llllelem *elem = matchinclude_ll->l_head; elem; elem = elem->l_next) {
            if (hatom_gettype(&elem->l_hatom) == H_SYM)
                par.matchinclude |= sym_to_onsetpoint(hatom_getsym(&elem->l_hatom));
        }
    }
    
    goto_preprocess_voicenumbers(r_ob, &par);
    
    if (where_ll) {
        t_atom *new_av = NULL;
        long new_ac = llll_deparse(where_ll, &new_av, 0, LLLL_D_PARENS);
        par.where = notation_obj_lexpr_new(new_ac, new_av);
        
        if (new_av)
            bach_freeptr(new_av);
        
        if (!par.where) {
            object_error((t_object *) r_ob, "Bad expression for 'where' clause!");
        }
    }

    if (until_ll) {
        t_atom *new_av = NULL;
        long new_ac = llll_deparse(until_ll, &new_av, 0, LLLL_D_PARENS);
        par.until = notation_obj_lexpr_new(new_ac, new_av);
        
        if (new_av)
            bach_freeptr(new_av);
        
        if (!par.until) {
            object_error((t_object *) r_ob, "Bad expression for 'until' clause!");
        }
    }

    
    if (args->l_head && hatom_gettype(&args->l_head->l_hatom) == H_SYM) {
        par.command = hatom_getsym(&args->l_head->l_hatom);
        par.arguments = llll_clone(args);
        llll_behead(par.arguments);
    }
    
    
    // preprocessing from/to AUTO attr
    if (par.command == _llllobj_sym_next) {
        if (par.from == k_GOTO_ONSETPOINT_AUTO)
            par.from = k_GOTO_ONSETPOINT_HEAD;
        if (par.to == k_GOTO_ONSETPOINT_AUTO)
            par.to = k_GOTO_ONSETPOINT_HEAD;
    } else if (par.command == _llllobj_sym_prev) {
        if (par.from == k_GOTO_ONSETPOINT_AUTO)
            par.from = k_GOTO_ONSETPOINT_TAIL;
        if (par.to == k_GOTO_ONSETPOINT_AUTO)
            par.to = k_GOTO_ONSETPOINT_TAIL;
    }
    
    
    if (par.command == _sym_up || par.command == _sym_down || par.command == _llllobj_sym_left || par.command == _llllobj_sym_right)
        par.polymode = k_GOTO_POLYMODE_NONE;
    
    switch (notationobj_goto(r_ob, &par)) {
        case k_GOTO_ERROR_NOTFOUND:
            if (par.nullmode) {
                // null go-to! No element to go-to!
                t_llll *notifyll = llll_get();
                llll_appendsym(notifyll, _llllobj_sym_goto);
                llll_appendsym(notifyll, _llllobj_sym_none);
                llllobj_outlet_llll((t_object *) r_ob, LLLL_OBJ_UI, notationobj_get_notification_outlet(r_ob), notifyll);
                llll_free(notifyll);
            }
            break;
            
        case k_GOTO_ERROR_WRONGCOMMAND:
            object_error((t_object *)r_ob, "Unknown command for go-to navigation.");
            break;

        case k_GOTO_ERROR_WRONGPARAMS:
            object_error((t_object *)r_ob, "Unsupported parameters for go-to navigation.");
            break;

        case k_GOTO_ERROR_WRONGARGUMENTS:
            object_error((t_object *)r_ob, "Error in arguments syntax for go-to navigation.");
            break;

        default:
            break;
    }
    
    if (types_ll)
        llll_free(types_ll);
    if (where_ll)
        llll_free(where_ll);
    if (until_ll)
        llll_free(until_ll);
    if (matchinclude_ll)
        llll_free(matchinclude_ll);
    if (par.where)
        lexpr_free(par.where);
    if (par.until)
        lexpr_free(par.until);
    if (par.arguments)
        llll_free(par.arguments);
}




