/**
	notation_dynamicsommons.c - function handling dynamics

	by Daniele Ghisi
*/

#include "playkeys_commons.h"


long symbol_to_incoming(t_symbol *s)
{
    if (s == _llllobj_sym_note)
        return k_PLAYKEYS_INCOMING_ROLLNOTE + k_PLAYKEYS_INCOMING_SCORENOTE;
    if (s == gensym("rollnote"))
        return k_PLAYKEYS_INCOMING_ROLLNOTE;
    if (s == gensym("scorenote"))
        return k_PLAYKEYS_INCOMING_SCORENOTE;
    if (s == _llllobj_sym_chord)
        return k_PLAYKEYS_INCOMING_ROLLCHORD + k_PLAYKEYS_INCOMING_SCORECHORD;
    if (s == gensym("rollchord"))
        return k_PLAYKEYS_INCOMING_ROLLCHORD;
    if (s == gensym("scorechord"))
        return k_PLAYKEYS_INCOMING_SCORECHORD;
    if (s == _llllobj_sym_rest)
        return k_PLAYKEYS_INCOMING_SCOREREST;
    if (s == _llllobj_sym_measure)
        return k_PLAYKEYS_INCOMING_SCOREMEASURE;
    if (s == _llllobj_sym_marker)
        return k_PLAYKEYS_INCOMING_MARKER;
    if (s == _llllobj_sym_tempo)
        return k_PLAYKEYS_INCOMING_TEMPO;
    if (s == _llllobj_sym_play)
        return k_PLAYKEYS_INCOMING_PLAY;
    if (s == _llllobj_sym_stop)
        return k_PLAYKEYS_INCOMING_STOP;
    if (s == _llllobj_sym_pause)
        return k_PLAYKEYS_INCOMING_PAUSE;
    if (s == _llllobj_sym_end)
        return k_PLAYKEYS_INCOMING_END;
    
    /*
     TODO:
     k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND
     k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND
     k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND
     k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND
     k_PLAYKEYS_INCOMING_SCOREREST_COMMAND
     */
    return k_PLAYKEYS_INCOMING_UNKNOWN;
}

long get_default_allowed_notationitems_for_property(long property)
{
    long score_set = k_PLAYKEYS_INCOMING_SCORENOTE + k_PLAYKEYS_INCOMING_SCORECHORD + k_PLAYKEYS_INCOMING_SCOREREST;
    long roll_set = k_PLAYKEYS_INCOMING_ROLLNOTE + k_PLAYKEYS_INCOMING_ROLLCHORD;
    long standard_set = roll_set + score_set;
    long all = -1;
    
    switch (property) {
        case k_PLAYKEYS_PLAY: return k_PLAYKEYS_INCOMING_PLAY;
        case k_PLAYKEYS_STOP: return k_PLAYKEYS_INCOMING_STOP;
        case k_PLAYKEYS_PAUSE: return k_PLAYKEYS_INCOMING_PAUSE;
        case k_PLAYKEYS_END: return k_PLAYKEYS_INCOMING_END;
            
        case k_PLAYKEYS_TYPE:
        case k_PLAYKEYS_ROUTER:
            return all;
            
        case k_PLAYKEYS_ROLE:
            return k_PLAYKEYS_INCOMING_MARKER;
            
        case k_PLAYKEYS_TEMPO:
        case k_PLAYKEYS_QUARTERTEMPO:
            return k_PLAYKEYS_INCOMING_TEMPO;
            
        case k_PLAYKEYS_MEASUREINFO:
            return k_PLAYKEYS_INCOMING_SCOREMEASURE;
            
            
        default: return standard_set;
    }
    /*
     switch (property) {
     case k_PLAYKEYS_NONE: return standard_set;
     case k_PLAYKEYS_TYPE: return all;
     case k_PLAYKEYS_ONSET: return standard_set;
     case k_PLAYKEYS_SYMONSET: return score_set;
     case k_PLAYKEYS_CENTS: return standard_set;
     case k_PLAYKEYS_PITCH: return standard_set;
     case k_PLAYKEYS_DURATION: return standard_set;
     case k_PLAYKEYS_SYMDURATION: return score_set;
     case k_PLAYKEYS_VELOCITY: return standard_set;
     case k_PLAYKEYS_MIDICHANNEL: return standard_set;
     case k_PLAYKEYS_TIE: return score_set;
     case k_PLAYKEYS_VOICENUMBER: return standard_set;
     case k_PLAYKEYS_PATH: return standard_set;
     case k_PLAYKEYS_MEASURENUMBER: return gensym("measurenumber");
     case k_PLAYKEYS_BREAKPOINTS: return _llllobj_sym_breakpoints;
     case k_PLAYKEYS_MEASUREINFO: return _llllobj_sym_measureinfo;
     case k_PLAYKEYS_NAME: return _llllobj_sym_name;
     case k_PLAYKEYS_FLAGS: return _llllobj_sym_flags;
     case k_PLAYKEYS_TEMPO: return _llllobj_sym_tempo;
     case k_PLAYKEYS_QUARTERTEMPO: return _llllobj_sym_quartertempo;
     case k_PLAYKEYS_SLOT: return _llllobj_sym_slot;
     case k_PLAYKEYS_PLAY: return _llllobj_sym_play;
     case k_PLAYKEYS_STOP: return _llllobj_sym_stop;
     case k_PLAYKEYS_PAUSE: return _llllobj_sym_pause;
     case k_PLAYKEYS_END: return _llllobj_sym_end;
     case k_PLAYKEYS_CHORDINDEX: return gensym("chordindex");
     case k_PLAYKEYS_NOTEINDEX: return gensym("noteindex");
     case k_PLAYKEYS_TAIL: return _llllobj_sym_tail;
     case k_PLAYKEYS_DYNAMICS: return _llllobj_sym_dynamics;
     case k_PLAYKEYS_LYRICS: return _llllobj_sym_lyrics;
     case k_PLAYKEYS_NOTEHEAD: return _llllobj_sym_notehead;
     case k_PLAYKEYS_ARTICULATIONS: return _llllobj_sym_articulations;
     case k_PLAYKEYS_ROUTER: return gensym("router");
     case k_PLAYKEYS_PLAYOFFSET: return gensym("playoffset");
     default: return _llllobj_sym_none;
     } */
}

long symbol_to_property(t_symbol *s)
{
    if (s == _llllobj_sym_type)
        return k_PLAYKEYS_TYPE;
    if (s == _llllobj_sym_onset)
        return k_PLAYKEYS_ONSET;
    if (s == _llllobj_sym_symonset)
        return k_PLAYKEYS_SYMONSET;
    if (s == _llllobj_sym_cents)
        return k_PLAYKEYS_CENTS;
    if (s == _llllobj_sym_pitch)
        return k_PLAYKEYS_PITCH;
    if (s == _llllobj_sym_duration)
        return k_PLAYKEYS_DURATION;
    if (s == _llllobj_sym_symduration)
        return k_PLAYKEYS_SYMDURATION;
    if (s == _llllobj_sym_velocity)
        return k_PLAYKEYS_VELOCITY;
    if (s == _llllobj_sym_midichannel)
        return k_PLAYKEYS_MIDICHANNEL;
    if (s == _llllobj_sym_tie)
        return k_PLAYKEYS_TIE;
    if (s == gensym("voicenumber"))
        return k_PLAYKEYS_VOICENUMBER;
    //    if (s == _llllobj_sym_voice)
    //        return k_PLAYKEYS_VOICENUMBER;
    if (s == gensym("measurenumber"))
        return k_PLAYKEYS_MEASURENUMBER;
    //    if (s == _llllobj_sym_measure)
    //        return k_PLAYKEYS_MEASURENUMBER;
    if (s == _llllobj_sym_breakpoints)
        return k_PLAYKEYS_BREAKPOINTS;
    if (s == _llllobj_sym_measureinfo)
        return k_PLAYKEYS_MEASUREINFO;
    if (s == _llllobj_sym_name)
        return k_PLAYKEYS_NAME;
    if (s == _llllobj_sym_flags)
        return k_PLAYKEYS_FLAGS;
    if (s == _llllobj_sym_path)
        return k_PLAYKEYS_PATH;
    if (s == _llllobj_sym_tempo)
        return k_PLAYKEYS_TEMPO;
    if (s == _llllobj_sym_role)
        return k_PLAYKEYS_ROLE;
    if (s == _llllobj_sym_quartertempo)
        return k_PLAYKEYS_QUARTERTEMPO;
    if (s == _llllobj_sym_slot)
        return k_PLAYKEYS_SLOT;
    if (s == _llllobj_sym_slots)
        return k_PLAYKEYS_ALLSLOTS;
    if (s == _llllobj_sym_play)
        return k_PLAYKEYS_PLAY;
    if (s == _llllobj_sym_stop)
        return k_PLAYKEYS_STOP;
    if (s == _llllobj_sym_pause)
        return k_PLAYKEYS_PAUSE;
    if (s == _llllobj_sym_end)
        return k_PLAYKEYS_END;
    if (s == gensym("chordindex"))
        return k_PLAYKEYS_CHORDINDEX;
    if (s == gensym("noteindex"))
        return k_PLAYKEYS_NOTEINDEX;
    if (s == _llllobj_sym_tail)
        return k_PLAYKEYS_TAIL;
    if (s == _llllobj_sym_dynamics)
        return k_PLAYKEYS_DYNAMICS;
    if (s == _llllobj_sym_lyrics)
        return k_PLAYKEYS_LYRICS;
    if (s == _llllobj_sym_notehead)
        return k_PLAYKEYS_NOTEHEAD;
    if (s == _llllobj_sym_articulations)
        return k_PLAYKEYS_ARTICULATIONS;
    if (s == gensym("router"))
        return k_PLAYKEYS_ROUTER;
    if (s == gensym("playoffset"))
        return k_PLAYKEYS_PLAYOFFSET;
    
    return k_PLAYKEYS_NONE;
}

t_symbol *property_to_symbol(long property)
{
    switch (property) {
        case k_PLAYKEYS_NONE: return _llllobj_sym_none;
        case k_PLAYKEYS_TYPE: return _llllobj_sym_type;
        case k_PLAYKEYS_ONSET: return _llllobj_sym_onset;
        case k_PLAYKEYS_SYMONSET: return _llllobj_sym_symonset;
        case k_PLAYKEYS_CENTS: return _llllobj_sym_cents;
        case k_PLAYKEYS_PITCH: return _llllobj_sym_pitch;
        case k_PLAYKEYS_DURATION: return _llllobj_sym_duration;
        case k_PLAYKEYS_SYMDURATION: return _llllobj_sym_symduration;
        case k_PLAYKEYS_VELOCITY: return _llllobj_sym_velocity;
        case k_PLAYKEYS_MIDICHANNEL: return _llllobj_sym_midichannel;
        case k_PLAYKEYS_TIE: return _llllobj_sym_tie;
        case k_PLAYKEYS_VOICENUMBER: return gensym("voicenumber");
        case k_PLAYKEYS_PATH: return _llllobj_sym_path;
        case k_PLAYKEYS_MEASURENUMBER: return gensym("measurenumber");
        case k_PLAYKEYS_BREAKPOINTS: return _llllobj_sym_breakpoints;
        case k_PLAYKEYS_MEASUREINFO: return _llllobj_sym_measureinfo;
        case k_PLAYKEYS_NAME: return _llllobj_sym_name;
        case k_PLAYKEYS_FLAGS: return _llllobj_sym_flags;
        case k_PLAYKEYS_ROLE: return _llllobj_sym_role;
        case k_PLAYKEYS_TEMPO: return _llllobj_sym_tempo;
        case k_PLAYKEYS_QUARTERTEMPO: return _llllobj_sym_quartertempo;
        case k_PLAYKEYS_SLOT: return _llllobj_sym_slot;
        case k_PLAYKEYS_ALLSLOTS: return _llllobj_sym_slots;
        case k_PLAYKEYS_PLAY: return _llllobj_sym_play;
        case k_PLAYKEYS_STOP: return _llllobj_sym_stop;
        case k_PLAYKEYS_PAUSE: return _llllobj_sym_pause;
        case k_PLAYKEYS_END: return _llllobj_sym_end;
        case k_PLAYKEYS_CHORDINDEX: return gensym("chordindex");
        case k_PLAYKEYS_NOTEINDEX: return gensym("noteindex");
        case k_PLAYKEYS_TAIL: return _llllobj_sym_tail;
        case k_PLAYKEYS_DYNAMICS: return _llllobj_sym_dynamics;
        case k_PLAYKEYS_LYRICS: return _llllobj_sym_lyrics;
        case k_PLAYKEYS_NOTEHEAD: return _llllobj_sym_notehead;
        case k_PLAYKEYS_ARTICULATIONS: return _llllobj_sym_articulations;
        case k_PLAYKEYS_ROUTER: return gensym("router");
        case k_PLAYKEYS_PLAYOFFSET: return gensym("playoffset");
        default: return _llllobj_sym_none;
    }
}


t_llllelem *getindex_2levels(t_llll *ll, long pos1, long pos2)
{
    t_llllelem *el = llll_getindex(ll, pos1, I_STANDARD);
    if (el && hatom_gettype(&el->l_hatom) == H_LLLL)
        return llll_getindex(hatom_getllll(&el->l_hatom), pos2, I_STANDARD);
    return NULL;
}


t_bool can_llll_be_a_note(t_llll *ll)
{
    if (!ll || !ll->l_head)
        return false;
    
    if (hatom_gettype(&ll->l_head->l_hatom) == H_SYM) {
        t_symbol *router = hatom_getsym(&ll->l_head->l_hatom);
        if (router == _llllobj_sym_name ||
            router == _llllobj_sym_articulations ||
            router == _llllobj_sym_slots ||
            router == _llllobj_sym_breakpoints ||
            router == _llllobj_sym_graphic ||
            router == _llllobj_sym_flags)
            return false;
    }
    
    return true;
}


t_llllelem *root_find_el_with_sym_router(t_llll *ll, t_symbol *router)
{
    t_llllelem *el;
    for (el = ll->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *el_ll = hatom_getllll(&el->l_hatom);
            if (el_ll && el_ll->l_head && hatom_gettype(&el_ll->l_head->l_hatom) == H_SYM && hatom_getsym(&el_ll->l_head->l_hatom) == router)
                return el;
        }
    }
    return NULL;
}


t_llllelem *root_find_el_with_long_router(t_llll *ll, long router)
{
    t_llllelem *el;
    for (el = ll->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *el_ll = hatom_getllll(&el->l_hatom);
            if (el_ll && el_ll->l_head && hatom_gettype(&el_ll->l_head->l_hatom) == H_LONG && hatom_getlong(&el_ll->l_head->l_hatom) == router)
                return el;
        }
    }
    return NULL;
}


long llll_count_elems_fn(void *data, t_hatom *a, const t_llll *address)
{
    long *count = (long *)data;
    (*count)++;
    return 0;
}


long llll_count_elems(t_llll *ll) {
    long count = 0;
    llll_funall(ll, (fun_fn) llll_count_elems_fn, &count, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
    return count;
}

void playkeys_handle_flattening_and_nullmode(t_playkeys_settings *sett, t_llll **ll, long incoming, long playkeys_property, t_playkeys_key *key)
{
    if (ll && *ll) {
        switch (incoming) {
            case k_PLAYKEYS_INCOMING_ROLLNOTE:
            case k_PLAYKEYS_INCOMING_SCORENOTE:
            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
            case k_PLAYKEYS_INCOMING_TEMPO:
            case k_PLAYKEYS_INCOMING_MARKER:
            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
            case k_PLAYKEYS_INCOMING_SCOREREST:
            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                if (sett->n_flattenfornotes && (*ll)->l_size == 1)
                    llll_flatten(*ll, 1, 0);
                if (sett->n_nullmode == 0 && (*ll)->l_size == 0) {
                    llll_free(*ll);
                    *ll = NULL;
                    key->exists = 0;
                }
                break;
                
                
            case k_PLAYKEYS_INCOMING_ROLLCHORD:
            case k_PLAYKEYS_INCOMING_SCORECHORD:
            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                if (playkeys_property == k_PLAYKEYS_NAME && sett->n_flattenfornotes && (*ll)->l_size == 1)
                    llll_flatten(*ll, 1, 0);
                if (sett->n_nullmode == 0 && ((*ll)->l_size == 0 || ((*ll)->l_depth == 2 && llll_count_elems(*ll) == 0))) {
                    llll_free(*ll);
                    *ll = NULL;
                    key->exists = 0;
                }
                
            default:
                break;
        }
    }
    
}

t_max_err playkeysobj_getattr_process(t_object *x, t_playkeys_settings *sett, t_object *attr, long *ac, t_atom **av)
{
    if (ac && av) {
        *av = NULL;
        *ac = 0;
        *ac = llll_deparse(sett->n_process, av, 0, 0);
    }
    return MAX_ERR_NONE;
}


t_max_err playkeysobj_setattr_process(t_object *x, t_playkeys_settings *sett, t_object *attr, long ac, t_atom *av, char msp_obj)
{
    t_llll *ll;
    if (ac == 0 || av) {
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, msp_obj ? LLLL_OBJ_MSP : LLLL_OBJ_VANILLA, ac, av))) {
            t_llll *free_me;
            
            bach_atomic_lock(&sett->n_process_lock);
            free_me = sett->n_process;
            sett->n_process = ll;
            llll_clear(sett->n_note_commands);
            llll_clear(sett->n_chord_commands);
            llll_clear(sett->n_rest_commands);
            
            char defaultval = ((sett->n_process && sett->n_process->l_size > 0 && hatom_getsym(&sett->n_process->l_head->l_hatom) != gensym("+")) ? 0 : 1);
            if (defaultval)
                sett->n_notationitems_to_process = -1;  // all 1's
            else
                sett->n_notationitems_to_process = 0;
            
            for (t_llllelem *elem = sett->n_process->l_head; elem; elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_SYM) {
                    t_symbol *thisprocess = hatom_getsym(&elem->l_hatom);
                    if (thisprocess == _llllobj_sym_note)
                        sett->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLNOTE + k_PLAYKEYS_INCOMING_SCORENOTE);
                    else if (thisprocess == _llllobj_sym_chord)
                        sett->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLCHORD+ k_PLAYKEYS_INCOMING_SCORECHORD);
                    else if (thisprocess == _llllobj_sym_rest)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCOREREST;
                    else if (thisprocess == _llllobj_sym_measure)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCOREMEASURE;
                    else if (thisprocess == _llllobj_sym_tempo)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_TEMPO;
                    else if (thisprocess == _llllobj_sym_marker)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_MARKER;
                    else if (thisprocess == _llllobj_sym_play)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_PLAY;
                    else if (thisprocess == _llllobj_sym_stop)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_STOP;
                    else if (thisprocess == _llllobj_sym_end)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_END;
                    else if (thisprocess == _llllobj_sym_pause)
                        sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_PAUSE;
                } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                    t_llll *ll = hatom_getllll(&elem->l_hatom);
                    if (ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM) {
                        t_symbol *ref = hatom_getsym(&ll->l_head->l_hatom);
                        if (ref == _llllobj_sym_note) {
                            sett->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND + k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND);
                            for (t_llllelem *el2 = ll->l_head->l_next; el2; el2=el2->l_next)
                                if (hatom_gettype(&el2->l_hatom) == H_SYM)
                                    llll_appendsym(sett->n_note_commands, hatom_getsym(&el2->l_hatom));
                        } else if (ref == _llllobj_sym_chord) {
                            sett->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND + k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND);
                            for (t_llllelem *el2 = ll->l_head->l_next; el2; el2=el2->l_next)
                                if (hatom_gettype(&el2->l_hatom) == H_SYM)
                                    llll_appendsym(sett->n_chord_commands, hatom_getsym(&el2->l_hatom));
                        } else if (ref == _llllobj_sym_rest) {
                            sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCOREREST_COMMAND;
                            for (t_llllelem *el2 = ll->l_head->l_next; el2; el2=el2->l_next)
                                if (hatom_gettype(&el2->l_hatom) == H_SYM)
                                    llll_appendsym(sett->n_rest_commands, hatom_getsym(&el2->l_hatom));
                        }
                    }
                }
            }
            
            
            bach_atomic_unlock(&sett->n_process_lock);
            llll_free(free_me);
        }
    }
    return MAX_ERR_NONE;
}


double get_onset_from_llllelem(t_llllelem *el)
{
    if (hatom_gettype(&el->l_hatom) == H_LLLL) { // it's probably a "partial" note llll (see the @playpartialnotes verbose mode)
        t_llllelem *sub_target_el = llll_getindex(hatom_getllll(&el->l_hatom), 3, I_STANDARD);
        if (sub_target_el)
            return hatom_getdouble(&sub_target_el->l_hatom);
        else
            return 0;
    } else {
        return hatom_getdouble(&el->l_hatom);
    }
}

char incoming_is_from_roll(long incoming)
{
    switch (incoming) {
        case k_PLAYKEYS_INCOMING_ROLLNOTE:
        case k_PLAYKEYS_INCOMING_ROLLCHORD:
        case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
        case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
            return true;
            
        default:
            return false;
    }
}

// returns 1 if must process it, 0 otherwise
char playkeysobj_handle_incoming(t_object *x, t_playkeys_settings *sett, t_llll *in_ll, long *incoming_el, t_symbol **router_sym)
{
    bach_atomic_lock(&sett->n_process_lock);

    long incoming = k_PLAYKEYS_INCOMING_UNKNOWN;
    char must_process_incoming = false;
    
    t_symbol *router = NULL;
    if (in_ll && in_ll->l_head && hatom_gettype(&in_ll->l_head->l_hatom) == H_SYM) {
        router = hatom_getsym(&in_ll->l_head->l_hatom);
        if (router == _llllobj_sym_note) {
            t_llllelem *test = getindex_2levels(in_ll, 4, 2);
            incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLNOTE : k_PLAYKEYS_INCOMING_SCORENOTE;
        } else if (router == _llllobj_sym_chord) {
            t_llllelem *test = getindex_2levels(in_ll, 4, 2);
            incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLCHORD : k_PLAYKEYS_INCOMING_SCORECHORD;
        } else if (router == _llllobj_sym_rest) {
            incoming = k_PLAYKEYS_INCOMING_SCOREREST;
        } else if (router == _llllobj_sym_measure) {
            incoming = k_PLAYKEYS_INCOMING_SCOREMEASURE;
        } else if (router == _llllobj_sym_tempo) {
            incoming = k_PLAYKEYS_INCOMING_TEMPO;
        } else if (router == _llllobj_sym_marker) {
            incoming = k_PLAYKEYS_INCOMING_MARKER;
        } else if (router == _llllobj_sym_play) {
            incoming = k_PLAYKEYS_INCOMING_PLAY;
        } else if (router == _llllobj_sym_stop) {
            incoming = k_PLAYKEYS_INCOMING_STOP;
        } else if (router == _llllobj_sym_end) {
            incoming = k_PLAYKEYS_INCOMING_END;
        } else if (router == _llllobj_sym_pause) {
            incoming = k_PLAYKEYS_INCOMING_PAUSE;
        } else {
            char found = 0;
            for (t_llllelem *elem = sett->n_note_commands->l_head; elem; elem = elem->l_next) {
                if (router == hatom_getsym(&elem->l_hatom)) {
                    t_llllelem *test = getindex_2levels(in_ll, 4, 2);
                    incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND : k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND;
                    found = 1;
                }
            }
            if (!found) {
                for (t_llllelem *elem = sett->n_chord_commands->l_head; elem; elem = elem->l_next) {
                    if (router == hatom_getsym(&elem->l_hatom)) {
                        t_llllelem *test = getindex_2levels(in_ll, 4, 2);
                        incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND : k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND;
                        found = 1;
                    }
                }
            }
            if (!found) {
                for (t_llllelem *elem = sett->n_rest_commands->l_head; elem; elem = elem->l_next) {
                    if (router == hatom_getsym(&elem->l_hatom)) {
                        incoming = k_PLAYKEYS_INCOMING_SCOREREST_COMMAND;
                        found = 1;
                    }
                }
            }
        }
    }
    
    if (incoming != k_PLAYKEYS_INCOMING_UNKNOWN) {
        must_process_incoming = ((sett->n_notationitems_to_process & incoming) != 0);
        
        switch (incoming) {
            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                if (is_symbol_in_llll_first_level(sett->n_note_commands, router))
                    must_process_incoming = true;
                break;
                
            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                if (is_symbol_in_llll_first_level(sett->n_chord_commands, router))
                    must_process_incoming = true;
                break;
                
            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                if (is_symbol_in_llll_first_level(sett->n_rest_commands, router))
                    must_process_incoming = true;
                break;
                
            default:
                break;
        }
    }
    
    bach_atomic_unlock(&sett->n_process_lock);
    
    *incoming_el = incoming;
    *router_sym = router;
    return must_process_incoming;
}

t_llll *playkeysobj_get_values(t_object *x, t_playkeys_settings *sett, t_playkeys_key *this_key, long incoming, t_symbol *router, t_llll *in_ll)
{
    t_llll *found = NULL;
    t_llllelem *target_el = NULL;
    switch (this_key->property) {
        case k_PLAYKEYS_TYPE:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_note);
                    break;
                    
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_chord);
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCOREREST:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_rest);
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_measure);
                    break;
                    
                case k_PLAYKEYS_INCOMING_MARKER:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_marker);
                    break;
                    
                case k_PLAYKEYS_INCOMING_TEMPO:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_tempo);
                    break;
                    
                case k_PLAYKEYS_INCOMING_PLAY:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_play);
                    break;
                    
                case k_PLAYKEYS_INCOMING_STOP:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_stop);
                    break;
                    
                case k_PLAYKEYS_INCOMING_PAUSE:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_pause);
                    break;
                    
                case k_PLAYKEYS_INCOMING_END:
                    found = llll_get();
                    llll_appendsym(found, _llllobj_sym_end);
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
            
        case k_PLAYKEYS_PITCH: // pitch must be changed at some point
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 1, I_STANDARD))) {
                            if (hatom_gettype(&target_el->l_hatom) == H_PITCH)
                                llll_appendpitch(found, hatom_getpitch(&target_el->l_hatom));
                            else {
                                object_warn((t_object *)x, "Pitch requested, but only MIDIcent received.");
                                object_warn((t_object *)x, "   You might want to set \"outputpitchesplayout\" on \"Always\" for your notation object.");
                                llll_appendpitch(found, t_pitch::fromMC(hatom_getdouble(&target_el->l_hatom)));
                            }
                        }
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 1, I_STANDARD))) {
                            if (hatom_gettype(&target_el->l_hatom) == H_PITCH)
                                llll_appendpitch(found, hatom_getpitch(&target_el->l_hatom));
                            else {
                                object_warn((t_object *)x, "Pitch requested, but only MIDIcent received.");
                                object_warn((t_object *)x, "   You might want to set \"outputpitchesplayout\" on \"Always\" for your notation object.");
                                llll_appendpitch(found, t_pitch::fromMC(hatom_getdouble(&target_el->l_hatom)));
                            }
                        }
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
        case k_PLAYKEYS_CENTS:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 1, I_STANDARD)))
                            llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 1, I_STANDARD)))
                            llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_VELOCITY:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 3, I_STANDARD)))
                            llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 2, I_STANDARD)))
                            llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_TIE:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 3, I_STANDARD)))
                            llll_appendhatom_clone(found, &target_el->l_hatom);
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
            
        case k_PLAYKEYS_DURATION:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        if ((target_el = llll_getindex(notell, 2, I_STANDARD)))
                            llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 2)))
                        llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 5, 2)))
                        llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                    break;
                    
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_SYMDURATION:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 1)))
                        llll_appendrat(found, hatom_getrational(&target_el->l_hatom));
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 5, 1)))
                        llll_appendrat(found, hatom_getrational(&target_el->l_hatom));
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
            
        case k_PLAYKEYS_ONSET:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 1)))
                        llll_appenddouble(found, get_onset_from_llllelem(target_el));
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 4)))
                        llll_appenddouble(found, get_onset_from_llllelem(target_el));
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 5, 3)))
                        llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                    break;
                    
                case k_PLAYKEYS_INCOMING_MARKER:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 3, I_STANDARD)))
                        llll_appendhatom_clone(found, &target_el->l_hatom);
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_PLAYOFFSET:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 1))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) {
                            t_llllelem *sub_target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 4, I_STANDARD);
                            llll_appenddouble(found, sub_target_el ? hatom_getdouble(&sub_target_el->l_hatom) : 0);
                        } else
                            llll_appenddouble(found, 0);
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 4))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) {
                            t_llllelem *sub_target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 4, I_STANDARD);
                            llll_appenddouble(found, sub_target_el ? hatom_getdouble(&sub_target_el->l_hatom) : 0);
                        } else
                            llll_appenddouble(found, 0);
                    }
                    
                default:
                    break;
            }
        }
            break;
            
        case k_PLAYKEYS_TAIL:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    
                    if ((target_el = getindex_2levels(in_ll, 4, 1))) {
                        double onset = get_onset_from_llllelem(target_el);
                        
                        for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                            if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                break;
                            t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                            if (!can_llll_be_a_note(notell))
                                break;
                            if ((target_el = llll_getindex(notell, 2, I_STANDARD)))
                                llll_appenddouble(found, onset + hatom_getdouble(&target_el->l_hatom));
                        }
                        break;
                    }
                    
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 4))) {
                        double onset = get_onset_from_llllelem(target_el);
                        if ((target_el = getindex_2levels(in_ll, 4, 2)))
                            llll_appenddouble(found, onset + hatom_getdouble(&target_el->l_hatom));
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
            
        case k_PLAYKEYS_SYMONSET:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                case k_PLAYKEYS_INCOMING_TEMPO:
                    found = llll_get();
                    if ((target_el = getindex_2levels(in_ll, 4, 3)))
                        llll_appendrat(found, hatom_getrational(&target_el->l_hatom));
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_MIDICHANNEL:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 3, I_STANDARD)))
                        llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_VOICENUMBER:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) // playout full path
                            target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 1, I_STANDARD);
                        if (target_el)
                            llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                    }
                    break;
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                case k_PLAYKEYS_INCOMING_TEMPO:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) // playout full path
                            target_el = getindex_2levels(hatom_getllll(&target_el->l_hatom), 1, 1);
                        if (target_el)
                            llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
        case k_PLAYKEYS_PATH:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                case k_PLAYKEYS_INCOMING_TEMPO:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) != H_LLLL) { // playout full path
                            object_warn((t_object *)x, "Full path requested, but not present in the playout llll.");
                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object, or use the \"voice\" playkey to avoid this warning.");
                        }
                        if (target_el)
                            llll_appendhatom_clone(found, &target_el->l_hatom);
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_MEASURENUMBER:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                case k_PLAYKEYS_INCOMING_TEMPO:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                            t_llllelem *tie_el;
                            for (tie_el = hatom_getllll(&target_el->l_hatom)->l_head; tie_el; tie_el = tie_el->l_next) {
                                target_el = llll_getindex(hatom_getllll(&tie_el->l_hatom), 2, I_STANDARD);
                                if (target_el)
                                    llll_appendhatom_clone(found, &target_el->l_hatom);
                            }
                        } else {
                            target_el = NULL;
                            object_warn((t_object *)x, "In order to intercept the measure number, full path must be in playout syntax.");
                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                        }
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 3, I_STANDARD)))
                        llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                    break;
                    
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_CHORDINDEX:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                            target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 2, I_STANDARD);
                            if (target_el)
                                llll_appendhatom_clone(found, &target_el->l_hatom);
                        } else {
                            target_el = NULL;
                            object_warn((t_object *)x, "In order to intercept the chord index, full path must be in playout syntax.");
                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                        }
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                            t_llllelem *tie_el;
                            for (tie_el = hatom_getllll(&target_el->l_hatom)->l_head; tie_el; tie_el = tie_el->l_next) {
                                target_el = llll_getindex(hatom_getllll(&tie_el->l_hatom), 3, I_STANDARD);
                                if (target_el)
                                    llll_appendhatom_clone(found, &target_el->l_hatom);
                            }
                        } else {
                            target_el = NULL;
                            object_warn((t_object *)x, "In order to intercept the chord index, full path must be in playout syntax.");
                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                        }
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_NOTEINDEX:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                            target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 3, I_STANDARD);
                            if (target_el)
                                llll_appendhatom_clone(found, &target_el->l_hatom);
                        } else {
                            target_el = NULL;
                            object_warn((t_object *)x, "In order to intercept the note index, full path must be in playout syntax.");
                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                        }
                    }
                    break;
                    
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                            t_llllelem *tie_el;
                            for (tie_el = hatom_getllll(&target_el->l_hatom)->l_head; tie_el; tie_el = tie_el->l_next) {
                                target_el = llll_getindex(hatom_getllll(&tie_el->l_hatom), 4, I_STANDARD);
                                if (target_el)
                                    llll_appendhatom_clone(found, &target_el->l_hatom);
                            }
                        } else {
                            target_el = NULL;
                            object_warn((t_object *)x, "In order to intercept the note index, full path must be in playout syntax.");
                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                        }
                    }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_MEASUREINFO:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 4, I_STANDARD)))
                        llll_appendhatom_clone(found, &target_el->l_hatom);
                    break;
                    
                    
                default:
                    break;
            }
        }
            break;
            
            
            
        case k_PLAYKEYS_ROLE:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_MARKER:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 4, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_SYM)
                            llll_appendsym(found, hatom_getsym(&target_el->l_hatom));
                    } else
                        llll_appendsym(found, _llllobj_sym_none);
                    
                    break;
                    
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_TEMPO:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_TEMPO:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 4, I_STANDARD)))
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL)
                            llll_chain_clone(found, hatom_getllll(&target_el->l_hatom));
                    break;
                    
                    
                default:
                    break;
            }
        }
            break;
            
            
        case k_PLAYKEYS_QUARTERTEMPO:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_TEMPO:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 3, I_STANDARD))) {
                        if (hatom_gettype(&target_el->l_hatom) == H_LLLL)
                            llll_chain_clone(found, hatom_getllll(&target_el->l_hatom));
                        else
                            llll_appendhatom_clone(found, &target_el->l_hatom);
                    }
                    break;
                    
                    
                default:
                    break;
            }
        }
            break;
            
            
            
        case k_PLAYKEYS_BREAKPOINTS:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        
                        if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_breakpoints)))
                            llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                        else if (sett->n_use_default_breakpoints) {
                            if (sett->n_breakpoints_have_velocity) {
                                char buf[512];
                                long velocity = 100;
                                // getting the note velocity
                                t_llllelem *velocity_el = llll_getindex(notell, incoming_is_from_roll(incoming) ? 3 : 2, I_STANDARD);
                                if (velocity_el)
                                    velocity = hatom_getlong(&velocity_el->l_hatom);
                                snprintf(buf, 512, "(0. 0. 0. %ld) (1. 0. 0. %ld)", velocity, velocity);
                                llll_appendllll(found, llll_from_text_buf(buf));
                            } else {
                                llll_appendllll(found, llll_from_text_buf("(0. 0. 0.) (1. 0. 0.)"));
                            }
                        } else
                            llll_appendllll(found, llll_get());
                    }
                    break;
                    
                default:
                    break;
            }
            playkeys_handle_flattening_and_nullmode(sett, &found, incoming, this_key->property, this_key);
        }
            break;
            
            
            
        case k_PLAYKEYS_NAME:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_MARKER:
                    found = llll_get();
                    if ((target_el = llll_getindex(in_ll, 2, I_STANDARD)))
                        llll_appendhatom_clone(found, &target_el->l_hatom);
                    break;
                    
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        
                        if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_name)))
                            llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                        else
                            llll_appendllll(found, llll_get());
                    }
                    break;
                    
                    
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    
                    found = llll_get();
                    target_el = llll_getindex(in_ll, 4, I_STANDARD);
                    if (!target_el || hatom_gettype(&target_el->l_hatom) != H_LLLL)
                        break;
                    if ((target_el = root_find_el_with_sym_router(hatom_getllll(&target_el->l_hatom), _llllobj_sym_name)))
                        llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                    else
                        llll_appendllll(found, llll_get());
                    break;
                    
                default:
                    break;
            }
            playkeys_handle_flattening_and_nullmode(sett, &found, incoming, this_key->property, this_key);
        }
            break;
            
            
            
            
        case k_PLAYKEYS_ALLSLOTS:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        
                        if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_slots))) {
                            if (hatom_gettype(&target_el->l_hatom) != H_LLLL)
                                break;
                            
                            t_llll *slotsll = hatom_getllll(&target_el->l_hatom);
                            llll_appendllll(found, llll_behead(llll_clone(slotsll)));
                        } else
                            llll_appendllll(found, llll_get());
                    }
                    break;
                    
                    
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    // to do
                    break;
                    
                default:
                    break;
            }
            playkeys_handle_flattening_and_nullmode(sett, &found, incoming, this_key->property, this_key);
        }
            break;
            
        case k_PLAYKEYS_LYRICS:
        case k_PLAYKEYS_DYNAMICS:
        case k_PLAYKEYS_ARTICULATIONS:
        case k_PLAYKEYS_NOTEHEAD:
        case k_PLAYKEYS_SLOT:
        {
            switch (incoming) {
                case k_PLAYKEYS_INCOMING_ROLLNOTE:
                case k_PLAYKEYS_INCOMING_ROLLCHORD:
                case k_PLAYKEYS_INCOMING_SCORENOTE:
                case k_PLAYKEYS_INCOMING_SCORECHORD:
                case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                    found = llll_get();
                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                            break;
                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                        if (!can_llll_be_a_note(notell))
                            break;
                        
                        if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_slots))) {
                            if (hatom_gettype(&target_el->l_hatom) != H_LLLL)
                                break;
                            
                            t_llll *slotsll = hatom_getllll(&target_el->l_hatom);
                            
                            t_hatom spec = this_key->specification;
                            if (this_key->property == k_PLAYKEYS_DYNAMICS)
                                hatom_setatom(&spec, &sett->n_dynamicsslot);
                            if (this_key->property == k_PLAYKEYS_LYRICS)
                                hatom_setatom(&spec, &sett->n_lyricsslot);
                            if (this_key->property == k_PLAYKEYS_ARTICULATIONS)
                                hatom_setatom(&spec, &sett->n_articulationsslot);
                            if (this_key->property == k_PLAYKEYS_NOTEHEAD)
                                hatom_setatom(&spec, &sett->n_noteheadslot);
                            if (spec.h_type == H_LONG) {
                                if ((target_el = root_find_el_with_long_router(slotsll, hatom_getlong(&spec))))
                                    llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                else
                                    llll_appendllll(found, llll_get());
                            } else if (spec.h_type == H_SYM) {
                                if ((target_el = root_find_el_with_sym_router(slotsll, hatom_getsym(&spec))))
                                    llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                else
                                    llll_appendllll(found, llll_get());
                            }
                            
                        } else
                            llll_appendllll(found, llll_get());
                    }
                    break;
                    
                    
                case k_PLAYKEYS_INCOMING_SCOREREST:
                case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                    found = llll_get();
                {
                    t_llllelem *restel = llll_getindex(in_ll, 4, I_STANDARD);
                    if (!restel || hatom_gettype(&restel->l_hatom) != H_LLLL)
                        break;
                    
                    t_llll *restll = hatom_getllll(&restel->l_hatom);
                    if ((target_el = root_find_el_with_sym_router(restll, _llllobj_sym_slots))) {
                        if (hatom_gettype(&target_el->l_hatom) != H_LLLL)
                            break;
                        
                        t_llll *slotsll = hatom_getllll(&target_el->l_hatom);
                        
                        t_hatom spec = this_key->specification;
                        if (this_key->property == k_PLAYKEYS_DYNAMICS)
                            hatom_setatom(&spec, &sett->n_dynamicsslot);
                        if (this_key->property == k_PLAYKEYS_LYRICS)
                            hatom_setatom(&spec, &sett->n_lyricsslot);
                        if (this_key->property == k_PLAYKEYS_ARTICULATIONS)
                            hatom_setatom(&spec, &sett->n_articulationsslot);
                        if (this_key->property == k_PLAYKEYS_NOTEHEAD)
                            hatom_setatom(&spec, &sett->n_noteheadslot);
                        if (spec.h_type == H_LONG) {
                            if ((target_el = root_find_el_with_long_router(slotsll, hatom_getlong(&spec))))
                                llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                            else
                                llll_appendllll(found, llll_get());
                        } else if (spec.h_type == H_SYM) {
                            if ((target_el = root_find_el_with_sym_router(slotsll, hatom_getsym(&spec))))
                                llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                            else
                                llll_appendllll(found, llll_get());
                        }
                        
                    } else
                        llll_appendllll(found, llll_get());
                }
                    break;
                default:
                    break;
            }
            playkeys_handle_flattening_and_nullmode(sett, &found, incoming, this_key->property, this_key);
        }
            break;
            
            
            
            
            
        case k_PLAYKEYS_PLAY:
            if (incoming == k_PLAYKEYS_INCOMING_PLAY)
                found = WHITENULL_llll;
            break;
            
        case k_PLAYKEYS_STOP:
            if (incoming == k_PLAYKEYS_INCOMING_STOP)
                found = WHITENULL_llll;
            break;
            
        case k_PLAYKEYS_PAUSE:
            if (incoming == k_PLAYKEYS_INCOMING_PAUSE)
                found = WHITENULL_llll;
            break;
            
        case k_PLAYKEYS_END:
            if (incoming == k_PLAYKEYS_INCOMING_END)
                found = WHITENULL_llll;
            break;
            
        case k_PLAYKEYS_ROUTER:
            found = llll_get();
            if (router)
                llll_appendsym(found, router);
            break;
            
            
        default:
            break;
    }
    
    return found;
}

void playkeyssettings_init(t_playkeys_settings *sett, t_llll *args_ll)
{
    t_playkeys_key *this_keys;

    sett->n_process = llll_make();
    sett->n_note_commands = llll_make();
    sett->n_chord_commands = llll_make();
    sett->n_rest_commands = llll_make();
    sett->n_notationitems_to_process = -1; // all of them
    
    t_llll *args_ll_flat = llll_clone(args_ll);
    llll_flatten(args_ll_flat, 0, 0);
    sett->n_keys = (t_playkeys_key *) bach_newptr((args_ll_flat->l_size + 1) * sizeof(t_playkeys_key));
    llll_free(args_ll_flat);
    
    
    sett->n_flattenfornotes = 1;
    sett->n_nullmode = 1;
    sett->n_use_default_breakpoints = 1;
    
    atom_setlong(&sett->n_dynamicsslot, BACH_DEFAULT_SLOT_DYNAMICS);
    atom_setlong(&sett->n_lyricsslot, BACH_DEFAULT_SLOT_LYRICS);
    atom_setlong(&sett->n_articulationsslot, BACH_DEFAULT_SLOT_ARTICULATIONS);
    atom_setlong(&sett->n_noteheadslot, BACH_DEFAULT_SLOT_NOTEHEADS);
    sett->n_must_iterate_on_output = false;
}

void playkeyssettings_free(t_playkeys_settings *sett)
{
    llll_free(sett->n_process);
    llll_free(sett->n_note_commands);
    llll_free(sett->n_chord_commands);
    llll_free(sett->n_rest_commands);
    
    bach_freeptr(sett->n_keys);
}


// returns 1 if error, 0 otherwise
long playkeysobj_parse_keys(t_object *x, t_playkeys_settings *sett, t_llll *args_ll, char *outlets, char msp)
{
    if (!args_ll->l_head) {
        object_error((t_object *)x, "No keys defined.");
        llll_free(args_ll);
        return 1;
    }

    char *this_outlets = outlets;
    long i = 0;
    t_playkeys_key *this_keys = sett->n_keys;
    t_llll_stack *stack = llll_stack_new();
    t_llllelem *el = args_ll->l_head;
    t_symbol *allowed_command_router = NULL;
    long curr_allowed_notationitems = -1; // default
    while (i < LLLL_MAX_OUTLETS - 1) {
        while (el && i < LLLL_MAX_OUTLETS - 1) {
            switch(el->l_hatom.h_type) {
                case H_SYM:
                {
                    t_symbol *sym = hatom_getsym(&el->l_hatom);
                    this_keys->property = symbol_to_property(sym);
                    this_keys->allowed_command_router = allowed_command_router;
                    if (this_keys->property == k_PLAYKEYS_NONE) {
                        object_error((t_object *)x, "Unrecognized key '%s', can't create object.", sym ? sym->s_name : "");
                        llll_free(args_ll);
                        return 1;
                    }
                    this_keys->specification.h_type = H_NULL;
                    this_keys->allowed_notationitems = curr_allowed_notationitems >= 0 ? curr_allowed_notationitems :get_default_allowed_notationitems_for_property(this_keys->property);
                    switch (this_keys->property) {
                        case k_PLAYKEYS_PLAY:
                        case k_PLAYKEYS_STOP:
                        case k_PLAYKEYS_PAUSE:
                        case k_PLAYKEYS_END:
                            *this_outlets++ = 'b';
                            break;
                            
                        default:
                            *this_outlets++ = msp ? 's' : '4';
                            break;
                    }
                    i++;
                    this_keys++;
                }
                    break;
                    
                case H_LONG:
                {
                    long slotnum = hatom_getlong(&el->l_hatom);
                    this_keys->property = k_PLAYKEYS_SLOT;
                    this_keys->allowed_command_router = allowed_command_router;
                    hatom_setlong(&this_keys->specification, slotnum);
                    this_keys->allowed_notationitems = curr_allowed_notationitems >= 0 ? curr_allowed_notationitems :get_default_allowed_notationitems_for_property(this_keys->property);
                    *this_outlets++ = msp ? 's' : '4';
                    i++;
                    this_keys++;
                }
                    break;
                    
                case H_LLLL:
                {
                    t_llll *ll = hatom_getllll(&el->l_hatom);
                    char router_is_sym = ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM;
                    
                    if (router_is_sym && (hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slot || hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slots)) {
                        for (t_llllelem *tempel = ll->l_head->l_next; tempel; tempel = tempel->l_next) {
                            this_keys->property = k_PLAYKEYS_SLOT;
                            this_keys->allowed_command_router = allowed_command_router;
                            this_keys->allowed_notationitems = curr_allowed_notationitems >= 0 ? curr_allowed_notationitems : get_default_allowed_notationitems_for_property(this_keys->property);
                            if (hatom_gettype(&tempel->l_hatom) == H_SYM)
                                hatom_setsym(&this_keys->specification, hatom_getsym(&tempel->l_hatom));
                            else
                                hatom_setlong(&this_keys->specification, hatom_getlong(&tempel->l_hatom));
                            *this_outlets++ = msp ? 's' : '4';
                            i++;
                            this_keys++;
                        }
                        
                    } else if (router_is_sym) {
                        curr_allowed_notationitems = symbol_to_incoming(hatom_getsym(&ll->l_head->l_hatom));
                        if (curr_allowed_notationitems) {
                            allowed_command_router = NULL;
                            llll_stack_push(stack, el->l_next);
                            el = ll->l_head;
                        } else {
                            // defining a command
                            long operate_on = 0;
                            allowed_command_router = hatom_getsym(&ll->l_head->l_hatom);
                            
                            if (is_symbol_in_llll_first_level(sett->n_note_commands, allowed_command_router)) {
                                operate_on = 1;
                            } else if (is_symbol_in_llll_first_level(sett->n_chord_commands, allowed_command_router)) {
                                operate_on = 2;
                            } else if (is_symbol_in_llll_first_level(sett->n_rest_commands, allowed_command_router)) {
                                operate_on = 3;
                            }
                            
                            if (operate_on == 0) { // the command was not assigned to any of the routers
                                // ASSIGNING IT TO NOTES
                                operate_on = 1;
                                sett->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND + k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND;
                                llll_appendsym(sett->n_note_commands, allowed_command_router);
                            }
                            
                            if (operate_on == 2) {
                                curr_allowed_notationitems = k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND + k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND;
                            } else if (operate_on == 3) {
                                curr_allowed_notationitems = k_PLAYKEYS_INCOMING_SCOREREST_COMMAND;
                            } else {
                                curr_allowed_notationitems = k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND + k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND;
                            }
                            
                            llll_stack_push(stack, el->l_next);
                            el = ll->l_head;
                        }
                    } else {
                        object_error((t_object *)x, "Unknown llll key.");
                        llll_free(args_ll);
                        return 1;
                    }
                }
                    break;
                    
                default:
                {
                    object_error((t_object *)x, "Unknown key.");
                    llll_free(args_ll);
                    return 1;
                }
                    break;
            }
            el = el->l_next;
        }
        
        if (!stack->s_items)
            break;
        
        el = (t_llllelem *) llll_stack_pop(stack);
        curr_allowed_notationitems = -1; // default
    }
    llll_stack_destroy(stack);
    
    *this_outlets = 0;
    this_keys->property = k_PLAYKEYS_NONE;
    llll_free(args_ll);

    return 0;
}
