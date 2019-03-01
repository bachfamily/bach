/**
 notation_dynamic.c - functions handling dynamics
 
 by Daniele Ghisi
 */

#include "bach.h"
#include "notation.h" // header with all the structures for the notation objects


long dynamics_get_ending_hairpin(t_dynamics *dyn)
{
    return dyn->lastmark ? dyn->lastmark->hairpin_to_next : k_DYNAMICS_HAIRPIN_NONE;
}

char dynamics_extend_till_next_chord(t_dynamics *dyn)
{
    long lasthairpin = dynamics_get_ending_hairpin(dyn);
    if (dyn->firstmark && (lasthairpin != k_DYNAMICS_HAIRPIN_NONE)) {
        return true; // meaning: till next chord!
    } else if (dyn->firstmark) {
        return false; // meaning: till the end of the chord
    } else
        return false;
}

t_dynamics *dynamics_clone(t_dynamics *dyn, t_notation_item *newowner)
{
    t_dynamics *newdyn = build_dynamics(newowner);
    
    newdyn->dynamics_left_uext = dyn->dynamics_left_uext;
    newdyn->dynamics_right_uext = dyn->dynamics_right_uext;
    newdyn->dynamics_right_uext_first = dyn->dynamics_right_uext_first;
    newdyn->text_deparsed = dyn->text_deparsed;
    
    newdyn->num_marks = dyn->num_marks;
    
    t_dynamics_mark *lastput = NULL;
    for (t_dynamics_mark *temp = dyn->firstmark; temp; temp = temp->next) {
        t_dynamics_mark *newtemp = build_dynamics_mark(temp->num_words);
        newtemp->end_energy = temp->end_energy;
        newtemp->start_energy = temp->start_energy;
        newtemp->snap_to_breakpoint = temp->snap_to_breakpoint;
        newtemp->dynamics_mark_attachment = temp->dynamics_mark_attachment;
        newtemp->relative_position = temp->relative_position;
        newtemp->hairpin_to_next = temp->hairpin_to_next;
        for (long i = 0; i < temp->num_words; i++) {
            newtemp->is_roman[i] = temp->is_roman[i];
            newtemp->text_deparsed[i] = temp->text_deparsed[i];
            newtemp->text_typographic[i] = temp->text_typographic[i];
        }
        
        newtemp->prev = lastput;
        if (!lastput)
            newdyn->firstmark = newtemp;
        else {
            lastput->next = newtemp;
        }
        lastput = newtemp;
    }
    newdyn->lastmark = lastput;
    return newdyn;
}


void dynamics_mark_append(t_dynamics *dyn, t_dynamics_mark *mk)
{
    if (dyn->lastmark) {
        dyn->lastmark->next = mk;
        mk->prev = dyn->lastmark;
        mk->next = NULL;
        dyn->lastmark = mk;
    } else {
        dyn->firstmark = dyn->lastmark = mk;
        mk->prev = mk->next = NULL;
    }
    dyn->num_marks++;
}

void dynamics_mark_delete(t_dynamics *dyn, t_dynamics_mark *mk)
{
    t_dynamics_mark *tofree = mk;
    
    if (mk == dyn->firstmark && mk == dyn->lastmark) {
        dyn->firstmark = dyn->lastmark = NULL;
    } else if (mk == dyn->firstmark) {
        dyn->firstmark = dyn->firstmark->next;
        if (dyn->firstmark)
            dyn->firstmark->prev = NULL;
    } else if (mk == dyn->lastmark) {
        dyn->lastmark = dyn->lastmark->prev;
        if (dyn->lastmark)
            dyn->firstmark->next = NULL;
    } else {
        mk->prev->next = mk->next;
        mk->next->prev = mk->prev;
    }
    
    dyn->num_marks --;
    bach_freeptr(tofree);
}

t_chord *dynamics_get_next(t_notation_obj *r_ob, t_voice *voice, long slot_num, t_chord *curr_ch, double *onset)
{
    for (t_chord *ch = curr_ch ? chord_get_next(curr_ch) : chord_get_first(r_ob, voice); ch; ch = chord_get_next(ch)) {
        if (chord_has_dynamics(ch)) {
            if (onset)
                *onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)ch);
            return ch;
        }
    }
    
    return NULL;
    
}

t_chord *dynamics_get_prev(t_notation_obj *r_ob, t_voice *voice, long slot_num, t_chord *curr_ch, long *num_dynamics, t_symbol **dynamics, long *hairpins, char *open_hairpin, double *onset)
{
    for (t_chord *ch = curr_ch ? chord_get_prev(curr_ch) : chord_get_last(r_ob, voice); ch; ch = chord_get_prev(ch)) {
        if (chord_has_dynamics(ch)) {
            if (onset)
                *onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)ch);
            return ch;
        }
    }
    
    return NULL;
    
}

t_chord *dynamics_get_first(t_notation_obj *r_ob, t_voice *voice, long slot_num, double *onset)
{
    return dynamics_get_next(r_ob, voice, slot_num, NULL, onset);
}

long hairpin_symbol_to_value(t_symbol *hairpin)
{
    if (hairpin == gensym("<"))
        return k_DYNAMICS_HAIRPIN_CRESC;
    if (hairpin == gensym("<<"))
        return k_DYNAMICS_HAIRPIN_CRESCEXP;
    if (hairpin == gensym(">"))
        return k_DYNAMICS_HAIRPIN_DIM;
    if (hairpin == gensym(">>"))
        return k_DYNAMICS_HAIRPIN_DIMEXP;
    if (hairpin == gensym("_<_"))
        return k_DYNAMICS_HAIRPIN_CRESCDASHED;
    if (hairpin == gensym("_>_"))
        return k_DYNAMICS_HAIRPIN_DIMDASHED;
    if (hairpin == gensym("_") || hairpin == gensym("___"))
        return k_DYNAMICS_HAIRPIN_DASHED;
    return k_DYNAMICS_HAIRPIN_NONE;
}

long hairpin_textbuf_to_value(t_notation_obj *r_ob, char *buf)
{
    if (strcmp(buf, "<") == 0)
        return k_DYNAMICS_HAIRPIN_CRESC;
    if (strcmp(buf, "<<") == 0)
        return k_DYNAMICS_HAIRPIN_CRESCEXP;
    if (strcmp(buf, ">") == 0)
        return k_DYNAMICS_HAIRPIN_DIM;
    if (strcmp(buf, ">>") == 0)
        return k_DYNAMICS_HAIRPIN_DIMEXP;
    if (strcmp(buf, "=") == 0 || strcmp(buf, " ") == 0 || strcmp(buf, "") == 0)
        return k_DYNAMICS_HAIRPIN_NONE;
    if (strcmp(buf, "_<_") == 0)
        return k_DYNAMICS_HAIRPIN_CRESCDASHED;
    if (strcmp(buf, "_>_") == 0)
        return k_DYNAMICS_HAIRPIN_DIMDASHED;
    if (strcmp(buf, "_") == 0 || strcmp(buf, "___") == 0)
        return k_DYNAMICS_HAIRPIN_DASHED;

    object_warn((t_object *)r_ob, "Unsupported hairpin: '%s'", buf);
    return k_DYNAMICS_HAIRPIN_NONE;
}

t_symbol *hairpin_value_to_symbol(long hairpin)
{
    switch (hairpin) {
        case k_DYNAMICS_HAIRPIN_CRESCEXP:
            return gensym("<<");
            break;
            
        case k_DYNAMICS_HAIRPIN_CRESC:
            return gensym("<");
            break;

        case k_DYNAMICS_HAIRPIN_DIMEXP:
            return gensym(">>");
            break;

        case k_DYNAMICS_HAIRPIN_DIM:
            return gensym(">");
            break;

        case k_DYNAMICS_HAIRPIN_CRESCDASHED:
            return gensym("_<_");
            break;

        case k_DYNAMICS_HAIRPIN_DIMDASHED:
            return gensym("_>_");
            break;
            
        case k_DYNAMICS_HAIRPIN_DASHED:
            return gensym("_");
            break;

        case k_DYNAMICS_HAIRPIN_NONE:
        default:
            return gensym("=");
            break;
    }
}


t_bpt *dynamics_mark_get_breakpoint(t_dynamics *dyn, t_dynamics_mark *mark)
{
    t_bpt *bpt = NULL;
    if (dyn->owner_item->type == k_NOTE) {
        t_note *nt = dyn->owner_item->type == k_NOTE ? (t_note *)dyn->owner_item : (dyn->owner_item->type == k_CHORD ? ((t_chord *)dyn->owner_item)->firstnote : NULL);
        if (mark->snap_to_breakpoint >= 0)
            bpt = nth_breakpoint(nt, mark->snap_to_breakpoint);
        else
            bpt = nth_breakpoint(nt, nt->num_breakpoints + mark->snap_to_breakpoint);
    }
    return bpt;
}

// This is the llll containing all the information on positioning of all markings
t_llll *dynamics_to_llll_full(t_notation_obj *r_ob, t_dynamics *dyn)
{
    t_llll *res = llll_get();
    for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next) {
        t_llll *markll = llll_get();
        {
            t_llll *posll = llll_get();
            llll_appendsym(posll, dynamics_mark_attachment_value_to_symbol(mark->dynamics_mark_attachment));
            llll_appendlong(posll, mark->snap_to_breakpoint);
            if (mark->snap_to_breakpoint > 0) {
                t_bpt *bpt = dynamics_mark_get_breakpoint(dyn, mark);
                if (bpt) {
                    llll_appenddouble(posll, bpt->rel_x_pos);
                } else {
                    llll_appenddouble(posll, 0.);
                }
            } else {
                llll_appenddouble(posll, mark->relative_position);
            }
            llll_appendllll(markll, posll);
        }
        
        if (mark->num_words == 1)
            llll_appendsym(markll, mark->text_deparsed[0]);
        else {
            t_llll *submarks = llll_get();
            for (long i = 0; i < mark->num_words; i++)
                llll_appendsym(submarks, mark->text_deparsed[i]);
            llll_appendllll(markll, submarks);
        }
        
        llll_appendsym(markll, hairpin_value_to_symbol(mark->hairpin_to_next));
        llll_appendllll(res, markll);
    }
    return res;
}

// This is the llll containing the information on attachment of all markings
// but only the information necessary to work with (i.e.: it may contain the info on the attachment to a specific breakpoint,
// but NOT the breakpoint relative positioning).
t_llll *dynamics_to_llll_detailed(t_notation_obj *r_ob, t_dynamics *dyn)
{
    t_llll *res = llll_get();
    for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next) {
        t_llll *markll = llll_get();
        switch (mark->dynamics_mark_attachment) {
            case k_DYNAMICS_MARK_ATTACHMENT_AUTO:
                llll_appendsym(markll, _llllobj_sym_auto);
                break;
                
            case k_DYNAMICS_MARK_ATTACHMENT_MANUAL:
                llll_appenddouble(markll, mark->relative_position);
                break;

            case k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT:
            {
                t_llll *posll = llll_get();
                llll_appendsym(posll, _llllobj_sym_breakpoint);
                llll_appendlong(posll, mark->snap_to_breakpoint);
                llll_appendllll(markll, posll);
            }
                break;

            default:
                break;
        }

        if (mark->num_words == 1)
            llll_appendsym(markll, mark->text_deparsed[0]);
        else {
            t_llll *submarks = llll_get();
            for (long i = 0; i < mark->num_words; i++)
                llll_appendsym(submarks, mark->text_deparsed[i]);
            llll_appendllll(markll, submarks);
        }
        
        llll_appendsym(markll, hairpin_value_to_symbol(mark->hairpin_to_next));
        llll_appendllll(res, markll);
    }
    return res;
}

t_llll *dynamics_to_llll_plain(t_notation_obj *r_ob, t_dynamics *dyn)
{
    t_llll *res = llll_get();
    for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next) {
        if (mark->dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_MANUAL)
            llll_appenddouble(res, mark->relative_position);
        else if (mark->dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT) {
            char temp[512];
            snprintf_zero(temp, 512, "@%ld", mark->snap_to_breakpoint);
            llll_appendsym(res, gensym(temp));
        }
        
        for (long i = 0; i < mark->num_words; i++)
            llll_appendsym(res, mark->text_deparsed[i]);
        
        if (mark != dyn->lastmark || mark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE)
            llll_appendsym(res, hairpin_value_to_symbol(mark->hairpin_to_next));
    }
    return res;
}

t_llll *dynamics_to_llll(t_notation_obj *r_ob, t_dynamics *dyn, e_data_considering_types mode)
{
    switch (mode) {
        case k_CONSIDER_FOR_UNDO:
        case k_CONSIDER_FOR_SAVING:
        case k_CONSIDER_FOR_SLOT_LLLL_EDITOR:
            return dynamics_to_llll_detailed(r_ob, dyn);
            break;
            
        default:
            if (r_ob->dynamics_output_mode == 0)
                return dynamics_to_llll_plain(r_ob, dyn);
            else if (r_ob->dynamics_output_mode == 1)
                return dynamics_to_llll_detailed(r_ob, dyn);
            else
                return dynamics_to_llll_full(r_ob, dyn);
            break;
    }
}

char dynamics_mark_attachment_symbol_to_value(t_symbol *s)
{
    if (s == _llllobj_sym_auto || s == _llllobj_sym_Auto)
        return k_DYNAMICS_MARK_ATTACHMENT_AUTO;
    if (s == gensym("manual"))
        return k_DYNAMICS_MARK_ATTACHMENT_MANUAL;
    if (s == _llllobj_sym_breakpoint || s == _llllobj_sym_breakpoints)
        return k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT;
    return k_DYNAMICS_MARK_ATTACHMENT_AUTO;
}

t_symbol *dynamics_mark_attachment_value_to_symbol(char val)
{
    switch (val) {
        case k_DYNAMICS_MARK_ATTACHMENT_MANUAL:
            return gensym("manual");
            break;
        case k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT:
            return _llllobj_sym_breakpoint;
            break;
            
        default:
            return _llllobj_sym_auto;
            break;
    }
}

void dynamics_mark_measure(t_dynamics_mark *mark, t_jfont *jf_dynamics_nozoom, t_jfont *jf_dynamics_roman_nozoom, double *w, double *h)
{
    double ww = 0, hh = 0, thisw = 0, thish = 0;
    for (long i = 0; i < mark->num_words; i++) {
        if (mark->text_typographic) {
            if (mark->is_roman[i])
                jfont_text_measure(jf_dynamics_roman_nozoom, mark->text_typographic[i]->s_name, &thisw, &thish);
            else
                jfont_text_measure(jf_dynamics_nozoom, mark->text_typographic[i]->s_name, &thisw, &thish);
            ww += thisw;
            hh = MAX(hh, thish);
        }
        if (i < mark->num_words - 1)
            ww += CONST_USPACE_BETWEEN_DYNAMICS_MARK_WORDS;
    }
    *w = ww;
    *h = hh;
}

t_dynamics *dynamics_from_llll(t_notation_obj *r_ob, t_notation_item *owner, t_llll *ll)
{
    t_dynamics *dyn = NULL;
    if (ll->l_depth > 1) {
        dyn = build_dynamics(owner);
        long i = 0, num_marks = ll->l_size;
        long last_snapped_breakpoint = 0;
        for (t_llllelem *el = ll->l_head; el; el = el->l_next, i++) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *subll = hatom_getllll(&el->l_hatom);
                
                char dynamics_mark_attachment = k_DYNAMICS_MARK_ATTACHMENT_AUTO;
                long snaptobreakpoint = 0;
                double relativeposition = 0.;
                if (subll->l_size >= 1) {
                    if (hatom_gettype(&subll->l_head->l_hatom) == H_LLLL) {
                        t_llll *point = hatom_getllll(&subll->l_head->l_hatom);
                        t_llllelem *point_el = point ? point->l_head : NULL;
                        dynamics_mark_attachment = k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT;
                        if (point_el && hatom_gettype(&point_el->l_hatom) == H_SYM) {
                            dynamics_mark_attachment = dynamics_mark_attachment_symbol_to_value(hatom_getsym(&point_el->l_hatom));
                            point_el = point_el->l_next;
                        }
                        if (dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_AUTO) {
                            relativeposition = (num_marks == 1 ? 0 : ((double)i)/(num_marks - 1));
                        } else if (dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT) {
                            if (point_el)
                                snaptobreakpoint = last_snapped_breakpoint = hatom_getlong(&point_el->l_hatom);
                        } else if (dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_MANUAL) {
                            if (point_el && point_el->l_next) {
                                relativeposition = hatom_getdouble(&point_el->l_next->l_hatom);
                            } else {
                                relativeposition = (num_marks == 1 ? 0 : ((double)i)/(num_marks - 1));
                            }
                        }
                    } else {
                        if (hatom_gettype(&subll->l_head->l_hatom) == H_SYM) {
                            dynamics_mark_attachment = dynamics_mark_attachment_symbol_to_value(hatom_getsym(&subll->l_head->l_hatom));
                            if (dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT) {
                                snaptobreakpoint = (++last_snapped_breakpoint);
                            } else if (dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_AUTO) {
                                relativeposition = (num_marks == 1 ? 0 : ((double)i)/(num_marks - 1));
                            }
                        } else {
                            dynamics_mark_attachment = k_DYNAMICS_MARK_ATTACHMENT_MANUAL;
                            relativeposition = hatom_getdouble(&subll->l_head->l_hatom);
                        }
                    }
                }
                
                long num_words = 0;
                if (subll->l_size >= 2)
                    num_words = hatom_gettype(&subll->l_head->l_next->l_hatom) == H_LLLL ? hatom_getllll(&subll->l_head->l_next->l_hatom)->l_size : 1;
                
                long hairpintype = subll->l_size >= 3 ? (hatom_gettype(&subll->l_head->l_next->l_next->l_hatom) == H_SYM ? hairpin_symbol_to_value(hatom_getsym(&subll->l_head->l_next->l_next->l_hatom)) : hatom_getlong(&subll->l_head->l_next->l_next->l_hatom)) : k_DYNAMICS_HAIRPIN_NONE;
                
                t_dynamics_mark *mark = build_dynamics_mark(num_words);
                
                if (subll->l_size >= 2 && hatom_gettype(&subll->l_head->l_next->l_hatom) == H_LLLL) {
                    mark->start_energy = -1;
                    mark->end_energy = -1;
                    short this_start_energy, this_end_energy;
                    long i = 0;
                    for (t_llllelem *el = hatom_getllll(&subll->l_head->l_next->l_hatom)->l_head; el && i < num_words; el = el->l_next, i++) {
                        t_symbol *this_symbol = hatom_getsym(&el->l_hatom);
                        if (this_symbol) {
                            dynamics_parse_string_to_energy(r_ob, this_symbol->s_name, &this_start_energy, &this_end_energy);
                            mark->is_roman[i] = (this_start_energy < 0 || this_end_energy < 0);
                            if (mark->start_energy < 0)
                                mark->start_energy = this_start_energy;
                            if (this_end_energy >= 0)
                                mark->end_energy = this_end_energy;
                            mark->text_deparsed[i] = hatom_getsym(&el->l_hatom);
                            if (mark->is_roman[i]) {
                                mark->text_typographic[i] = mark->text_deparsed[i];
                            } else {
                                if (mark->text_deparsed)
                                    mark->text_typographic[i] = dynamics_mark_parse_string_to_typographic_text(r_ob, mark->text_deparsed[i]->s_name);
                                else
                                    mark->text_typographic[i] = _llllobj_sym_empty_symbol;
                            }
                        } else {
                            mark->text_deparsed[i] = _llllobj_sym_empty_symbol;
                            mark->text_typographic[i] = _llllobj_sym_empty_symbol;
                        }
                    }
                } else if (subll->l_size >= 2) {
                    t_symbol *mark_sym = hatom_getsym(&subll->l_head->l_next->l_hatom);
                    if (mark_sym) {
                        dynamics_parse_string_to_energy(r_ob, mark_sym->s_name, &mark->start_energy, &mark->end_energy);
                        mark->is_roman[0] = (mark->start_energy < 0 || mark->end_energy < 0);
                        mark->text_deparsed[0] = mark_sym;
                        if (mark->is_roman[0])
                            mark->text_typographic[0] = mark->text_deparsed[0];
                        else
                            mark->text_typographic[0] = dynamics_mark_parse_string_to_typographic_text(r_ob, mark_sym->s_name);
                    } else {
                        mark->text_deparsed[0] = _llllobj_sym_empty_symbol;
                        mark->text_typographic[0] = _llllobj_sym_empty_symbol;
                    }
                }
                
                mark->hairpin_to_next = hairpintype;
                mark->snap_to_breakpoint = snaptobreakpoint;
                mark->relative_position = relativeposition;
                mark->dynamics_mark_attachment = dynamics_mark_attachment;
                
                // special case in which the mark is simply a pipe sign: in this case it's a placeholder for an empty dynamics
                if (mark->num_words == 1 && mark->text_deparsed[0] == gensym("|"))
                    mark->num_words = 0;
                
                dynamics_mark_append(dyn, mark);
            }
        }
        
        char *buf = NULL;
        dynamics_to_textbuf(r_ob, dyn, &buf);
        dyn->text_deparsed = gensym(buf);
        bach_freeptr(buf);
    } else {
        char *buf = NULL;
        llll_to_text_buf(ll, &buf);
        dyn = dynamics_from_textbuf(r_ob, owner, buf);
        bach_freeptr(buf);
    }
    return dyn;
}


void paint_dynamics_from_slot(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *color, t_notation_item *item, double center_x,
                              double duration_x, long slot, t_jfont *jf_dynamics, t_jfont *jf_dynamics_roman, double font_size,
                              double roman_font_size, double y_position, double *curr_hairpin_start_x, long *curr_hairpin_type, char boxed)
{
    t_slotitem *firstitem = notation_item_get_slot_firstitem(r_ob, item, slot);
    if (firstitem && (t_symbol *)firstitem->item){
        t_dynamics *dyn = (t_dynamics *)firstitem->item;
        if (dyn && dyn->firstmark)
            paint_dynamics(r_ob, g, color, item, center_x, duration_x, dyn, jf_dynamics, jf_dynamics_roman, font_size, roman_font_size, y_position, curr_hairpin_start_x, curr_hairpin_type, NULL, NULL, boxed);
    }
}

char dynamics_mark_is_zero(t_dynamics_mark *dynsign)
{
    if (dynsign && dynsign->num_words == 1 && dynsign->text_typographic[0] && strcmp(dynsign->text_typographic[0]->s_name, "o") == 0)
        return true;
    return false;
}

char dynamics_mark_is_placeholder(t_dynamics_mark *dynmark)
{
    if (dynmark && dynmark->num_words == 0)
        return true;
    return false;
}

t_symbol* dynamics_mark_get_first_nonroman_symbol(t_dynamics_mark *dynmark, long *word_idx)
{
    for (long i = 0; i < dynmark->num_words; i++)
        if (!dynmark->is_roman[i]) {
            if (word_idx) *word_idx = i;
            return dynmark->text_deparsed[i];
        }
    return NULL;
}

t_symbol* dynamics_mark_get_last_nonroman_symbol(t_dynamics_mark *dynmark, long *word_idx)
{
    for (long i = dynmark->num_words - 1; i >= 0; i--)
        if (!dynmark->is_roman[i]) {
            if (word_idx) *word_idx = i;
            return dynmark->text_deparsed[i];
        }
    return NULL;
}


char dynamics_has_internal_relativeposition(t_dynamics *dyn)
{
    for (t_dynamics_mark *mk = dyn->firstmark; mk; mk = mk->next)
        if (mk->relative_position > 0 && mk->relative_position < 1)
            return true;
    return false;
}

// use item == NULL to only finish an hairpin
void paint_dynamics(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *color, t_notation_item *item,
                    double center_x, double duration_x, t_dynamics *dyn, t_jfont *jf_dynamics, t_jfont *jf_dynamics_roman,
                    double font_size, double roman_font_size, double y_position, double *curr_hairpin_start_x,
                    long *curr_hairpin_type, t_jrgba *prev_hairpin_color, char *prev_hairpin_dont_paint, char inside_slot_window)
{
    char boxed = inside_slot_window;
    double xpos = center_x, ypos = y_position;
    double h = -1, w = -1;
    //    double font_size = jfont_get_font_size(jf_dynamics);
    const double HAIRPIN_PAD = 0.11 * font_size;
    const double HAIRPIN_SEMIAPERTURE =  0.175 * font_size;
    const double ZEROCIRCLE_RADIUS = 0.1 * font_size;
    const double DASH_LENGTH = 3 * r_ob->zoom_y;
    t_chord *curr_ch = item ? notation_item_get_parent_chord(r_ob, item) : NULL;
    char dont_paint = (curr_ch && r_ob->is_editing_type == k_DYNAMICS && r_ob->is_editing_chord == curr_ch);
    
    if (!item) {
        // only finish the hairpin
        if ((r_ob->show_hairpins || boxed) && curr_hairpin_type && *curr_hairpin_type && curr_hairpin_start_x) {
            if (h < 0 && w < 0)
                h = w = 0;
            //                jfont_text_measure(jf_dynamics, dyntext, &w, &h);
            if (!(prev_hairpin_dont_paint && *prev_hairpin_dont_paint) && xpos - w/2. - HAIRPIN_PAD > *curr_hairpin_start_x)
                paint_hairpin(g, prev_hairpin_color ? *prev_hairpin_color : r_ob->j_dynamics_rgba, *curr_hairpin_type, *curr_hairpin_start_x, xpos - w/2. - HAIRPIN_PAD, ypos, HAIRPIN_SEMIAPERTURE, 1, DASH_LENGTH);
            *curr_hairpin_type = 0;
        }
        
        if (prev_hairpin_dont_paint)
            *prev_hairpin_dont_paint = dont_paint;
        if (prev_hairpin_color && color)
            *prev_hairpin_color = *color;
        
        return;
    }
    
    if (dyn){

        if (boxed) {
            duration_x = MAX(0, duration_x - dyn->dynamics_left_uext * r_ob->zoom_y);
            if (dyn->lastmark) {
                double lastw = 0, lasth = 0;
                dynamics_mark_measure(dyn->lastmark, jf_dynamics, jf_dynamics_roman, &lastw, &lasth);
                if (dyn->lastmark->num_words > 0 && !dyn->lastmark->is_roman[dyn->lastmark->num_words - 1]) {
                    double firstlastw = 0, firstlasth = 0;
                    jfont_text_measure(jf_dynamics, dyn->lastmark->text_typographic[dyn->lastmark->num_words-1]->s_name, &firstlastw, &firstlasth);
                    lastw -= firstlastw/2.;
                }
                duration_x = MAX(0, duration_x - lastw);
            }
        }
        
        //        paint_line(g, *color, 0, ypos, 200, ypos, 1);
        
        if ((r_ob->show_hairpins || boxed) && curr_hairpin_type && *curr_hairpin_type && curr_hairpin_start_x) {
            // Painting the open hairpin that ends with this chord
            char is_dynamic_zero = false;
            if (h < 0 && w < 0) {
                if (dynamics_mark_is_zero(dyn->firstmark)) {
                    w = h = ZEROCIRCLE_RADIUS * 2.; // "0" circle
                    is_dynamic_zero = true;
                } else if (dyn->firstmark) {
                    dynamics_mark_measure(dyn->firstmark, jf_dynamics, jf_dynamics_roman, &w, &h);
                } else {
                    w = h = 0;
                }
            }
            double endhairpinpos = xpos + (dyn->firstmark ? dyn->firstmark->relative_position * duration_x : 0);
            if (dyn->firstmark && dyn->firstmark->num_words > 0) {
                if (dyn->firstmark->is_roman[0])
                    endhairpinpos -= CONST_UX_NUDGE_LEFT_FOR_FIRST_ROMAN_WORD * r_ob->zoom_y;
                else {
                    if (dynamics_mark_is_zero(dyn->firstmark))
                        endhairpinpos -= ZEROCIRCLE_RADIUS;
                    else {
                        double temp_w, temp_h;
                        jfont_text_measure(jf_dynamics, dyn->firstmark->text_typographic[0]->s_name, &temp_w, &temp_h);
                        endhairpinpos -= temp_w/2.;
                    }
                }
                    
                if (!dynamics_mark_is_zero(dyn->firstmark))
                    endhairpinpos -= HAIRPIN_PAD;
            }
            if (!(prev_hairpin_dont_paint && *prev_hairpin_dont_paint) && endhairpinpos > *curr_hairpin_start_x) {
                paint_hairpin(g, prev_hairpin_color ? *prev_hairpin_color : r_ob->j_dynamics_rgba, *curr_hairpin_type, *curr_hairpin_start_x, endhairpinpos - (is_dynamic_zero ? 0 : HAIRPIN_PAD), ypos, HAIRPIN_SEMIAPERTURE, 1, DASH_LENGTH);
            }
            *curr_hairpin_type = 0;
        }
        
        if (prev_hairpin_dont_paint)
            *prev_hairpin_dont_paint = dont_paint;
        if (prev_hairpin_color && color)
            *prev_hairpin_color = *color;
        
        double prev_end_xpos = 0;
        double y_adj_for_dynamics = - 0.93 * font_size;
        double y_adj_for_romans = y_adj_for_dynamics + (font_size - roman_font_size) + 0.18 * font_size;
        for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next) {
            char is_dynamic_zero = false;
            
            if (mark->snap_to_breakpoint) {
                t_bpt *bpt = dynamics_mark_get_breakpoint(dyn, mark);
                if (bpt)
                    xpos = center_x + bpt->rel_x_pos * duration_x;
                else
                    xpos = center_x;
            } else
                xpos = center_x + mark->relative_position * duration_x;
            
            if (boxed) xpos += dyn->dynamics_left_uext * r_ob->zoom_y;
            
            long cur = xpos, end_previous_hairpin_here = xpos;
            if (r_ob->show_dynamics || boxed) {
                if (dynamics_mark_is_zero(mark)) {
                    if (!dont_paint)
                        paint_circle_stroken(g, *color, xpos, ypos, ZEROCIRCLE_RADIUS, 1);
                    is_dynamic_zero = true;
                    cur += ZEROCIRCLE_RADIUS;
                    end_previous_hairpin_here -= ZEROCIRCLE_RADIUS;
                } else {
                    end_previous_hairpin_here -= HAIRPIN_PAD;
                    if (!dont_paint) {
                        for (long i = 0; i < mark->num_words; i++) {
                            double thisw = 0, thish = 0;
                            double this_ypos = ypos + (mark->is_roman[i] ? y_adj_for_romans : y_adj_for_dynamics);
                            t_jfont *jfont = mark->is_roman[i] ? jf_dynamics_roman : jf_dynamics;
                            jfont_text_measure(jfont, mark->text_typographic[i]->s_name, &thisw, &thish);
                            if (i == 0) {
                                if (mark->is_roman[i]) {
                                    write_text(g, jfont, *color, mark->text_typographic[i]->s_name, cur - CONST_UX_NUDGE_LEFT_FOR_FIRST_ROMAN_WORD * r_ob->zoom_y, this_ypos, 600, ypos + 300, JGRAPHICS_TEXT_JUSTIFICATION_LEFT | JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
                                    cur += thisw - CONST_UX_NUDGE_LEFT_FOR_FIRST_ROMAN_WORD * r_ob->zoom_y;
                                    end_previous_hairpin_here -= CONST_UX_NUDGE_LEFT_FOR_FIRST_ROMAN_WORD * r_ob->zoom_y;
                                } else {
                                    write_text(g, jfont, *color, mark->text_typographic[i]->s_name, cur - 200, this_ypos, 400, ypos + 300, JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED | JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
                                    cur += thisw/2;
                                    end_previous_hairpin_here -= thisw/2;
                                }
                            } else {
                                write_text(g, jfont, *color, mark->text_typographic[i]->s_name, cur, this_ypos, 600, ypos + 300, JGRAPHICS_TEXT_JUSTIFICATION_LEFT | JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
                                cur += thisw;
                            }
                            if (i != mark->num_words - 1)
                                cur += CONST_USPACE_BETWEEN_DYNAMICS_MARK_WORDS * r_ob->zoom_y;
                        }
                    }
                }
            }
            
            if (is_dynamic_zero)
                w = h = ZEROCIRCLE_RADIUS * 2.;
            else
                dynamics_mark_measure(mark, jf_dynamics, jf_dynamics_roman, &w, &h);
            
            // painting hairpin?
            if ((r_ob->show_hairpins || boxed) && !dont_paint && mark->prev && mark->prev->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE && prev_end_xpos < end_previous_hairpin_here)
                paint_hairpin(g, *color, mark->prev->hairpin_to_next, prev_end_xpos, end_previous_hairpin_here, ypos, HAIRPIN_SEMIAPERTURE, 1, DASH_LENGTH);
            
            prev_end_xpos = cur + (is_dynamic_zero ? 0. : HAIRPIN_PAD);
            
            if (curr_hairpin_type)
                *curr_hairpin_type = mark->hairpin_to_next;
            if (curr_hairpin_start_x && mark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE) {
                *curr_hairpin_start_x = prev_end_xpos;
            }
        }
        
        if (boxed && !dont_paint && dyn->lastmark && dyn->lastmark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE && prev_end_xpos < center_x + duration_x - HAIRPIN_PAD) {
            paint_hairpin(g, *color, dyn->lastmark->hairpin_to_next, prev_end_xpos, center_x + duration_x - HAIRPIN_PAD, ypos, HAIRPIN_SEMIAPERTURE, 1, DASH_LENGTH);
        }
    }
}


void deparse_dynamics_to_string_once(t_notation_obj *r_ob, char *dynamics, char *buf)
{
    if (!dynamics) {
        buf[0] = 0;
        return;
    }
    
    unsigned char *c = (unsigned char *)dynamics;
    long cur = 0;
    while (c && *c && cur < CONST_MAX_NUM_DYNAMICS_CHARS - 5) {
        if (*c == 195) {
            switch (*(c+1)) {
                case 128:
                    cur += sprintf(buf+cur, "pppp");
                    break;
                case 129:
                    cur += sprintf(buf+cur, "ppp");
                    break;
                case 130:
                    cur += sprintf(buf+cur, "pp");
                    break;
                case 131:
                    cur += sprintf(buf+cur, "p");
                    break;
                case 132:
                    cur += sprintf(buf+cur, "mp");
                    break;
                case 133:
                    cur += sprintf(buf+cur, "mf");
                    break;
                case 134:
                    cur += sprintf(buf+cur, "f");
                    break;
                case 135:
                    cur += sprintf(buf+cur, "ff");
                    break;
                case 136:
                    cur += sprintf(buf+cur, "fff");
                    break;
                case 137:
                    cur += sprintf(buf+cur, "ffff");
                    break;
                case 138:
                    cur += sprintf(buf+cur, "fz");
                    break;
                case 139:
                    cur += sprintf(buf+cur, "sffz");
                    break;
                case 140:
                    cur += sprintf(buf+cur, "fp");
                    break;
                case 141:
                    cur += sprintf(buf+cur, "sfz");
                    break;
                case 142:
                    cur += sprintf(buf+cur, "sf");
                    break;
                default:
                    break;
            }
            c+=2;
            /*        } else if (*c == ' '){
             buf[cur++] = ' ';
             c++; */
        } else if (*c == 'o') {
            buf[cur++] = 'o';
            c++;
        } else
            c++;
    }
    buf[cur] = 0;
}


long dynamics_to_textbuf(t_notation_obj *r_ob, t_dynamics *dyn, char **buf)
{
    t_llll *plain = dynamics_to_llll_plain(r_ob, dyn);
    long res = llll_to_text_buf(plain, buf);
    llll_free(plain);
    
    return res;
}

t_symbol *dynamics_to_symbol(t_notation_obj *r_ob, t_dynamics *dyn)
{
    t_symbol *res = NULL;
    char *buf = NULL;
    dynamics_to_textbuf(r_ob, dyn, &buf);
    res = gensym(buf);
    bach_freeptr(buf);
    return res;
}

// the energy of a marking is defined as follow:
// undefinable = -1
// o = 0
// pp = 98
// p = 99
// mp = 100
// mf = 101
// f = 102..
// ff = 103...
// fz = 200
// sf/sfz = 201
// sff/sffz = 202
//...
void dynamics_parse_string_to_energy(t_notation_obj *r_ob, char *buf, short *start_energy, short *end_energy)
{
    long se = -1, ee = -1;
    if (buf) {
        switch (buf[0]) {
            case 'o':
                se = ee = 0;
                break;
                
            case 'm':
                if (!strcmp(buf, "mp"))
                    se = ee = 100;
                else if (!strcmp(buf, "mf"))
                    se = ee = 101;
                break;
                
            case 'p':
                for (long i = 1; i < strlen(buf); i++)
                    if (buf[i] != 'p')
                        goto end;
                se = ee = 100 - CLAMP(strlen(buf), 0, 100);
                break;
                
            case 'f':
                if (!strcmp(buf, "fz"))
                    se = ee = 200;
                else {
                    for (long i = 1; i < strlen(buf); i++)
                        if (buf[i] != 'f') {
                            if (!strcmp(buf+i, "mp")) {
                                se = 101 + CLAMP(i, 0, 100);
                                ee = 100;
                            } else if (!strcmp(buf+i, "mf")) {
                                se = 101 + CLAMP(i, 0, 100);
                                ee = 101;
                            } else if (buf[i] == 'p') {
                                for (long j = i+1; j < strlen(buf); j++) {
                                    if (buf[j] != 'p')
                                        goto end;
                                }
                                se = 101 + CLAMP(i, 0, 100);
                                se = ee = 100 - CLAMP(strlen(buf) - i, 0, 100);
                            }
                            goto end;
                        }
                    se = ee = 101 + CLAMP(strlen(buf), 0, 100);
                }
                break;
                
            case 's':
            {
                long len = buf[strlen(buf) - 1] == 'z' ? strlen(buf) - 1: strlen(buf);
                char there_is_z = true;
                if (len < 2 || buf[1] != 'f')
                    goto end;
                for (long i = 2; i < len; i++)
                    if (buf[i] != 'f') {
                        if (buf[i] == 'z') {
                            there_is_z = true;
                            i++;
                        }
                        
                        if (!strcmp(buf+i, "mp")) {
                            se = 200 + CLAMP(i, 0, 100);
                            ee = 100;
                        } else if (!strcmp(buf+i, "mf")) {
                            se = 200 + CLAMP(i, 0, 100);
                            ee = 101;
                        } else if (buf[i] == 'p') {
                            for (long j = i+1; j < len; j++) {
                                if (buf[j] != 'p')
                                    goto end;
                            }
                            se = 200 + CLAMP(i, 0, 100);
                            ee = 100 - CLAMP(len - i, 0, 100);
                        } else if (there_is_z && buf[i] == 'f') {
                            for (long j = i+1; j < len; j++) {
                                if (buf[j] != 'f')
                                    goto end;
                            }
                            se = 200 + CLAMP(i, 0, 100);
                            ee = 101 + CLAMP(len - i, 0, 100);
                        }
                        goto end;
                    }
                se = ee = 200 + CLAMP(len, 0, 100);
            }
                break;
                
            default:
                break;
        }
    }
    
end:
    *start_energy = se;
    *end_energy = ee;
}

// returns 1 if has crescendo, -1 if it has diminuendo, 0 otherwise
// buf is assumed to be 0-terminated
t_symbol *dynamics_mark_parse_string_to_typographic_text(t_notation_obj *r_ob, char *buf)
{
    char dynamics[CONST_MAX_NUM_DYNAMICS_CHARS];
    
    if (!buf) {
        dynamics[0] = 0;
        return gensym(dynamics);
    }
    
    char *c = buf;
    long cur = 0;
    while (c && *c && cur < CONST_MAX_NUM_DYNAMICS_CHARS - 5) {
        switch (*c) {
            case 'p':
                if (strncasecmp(c, "pppp", 4) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 128;
                    c+=4;
                } else if (strncasecmp(c, "ppp", 3) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 129;
                    c+=3;
                } else if (strncasecmp(c, "pp", 2) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 130;
                    c+=2;
                } else if (strncasecmp(c, "p", 1) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 131;
                    c+=1;
                } else
                    c++;
                break;
                
            case 'm':
                if (strncasecmp(c, "mp", 2) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 132;
                    c+=2;
                } else if (strncasecmp(c, "mf", 2) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 133;
                    c+=2;
                } else
                    c++;
                break;
                
            case 'f':
                if (strncasecmp(c, "ffff", 4) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 137;
                    c+=4;
                } else if (strncasecmp(c, "fff", 3) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 136;
                    c+=3;
                } else if (strncasecmp(c, "ff", 2) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 135;
                    c+=2;
                } else if (strncasecmp(c, "fz", 2) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 138;
                    c+=2;
                } else if (strncasecmp(c, "fp", 2) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 140;
                    c+=2;
                } else if (strncasecmp(c, "f", 1) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 134;
                    c+=1;
                } else
                    c++;
                break;
                
            case 's':
                if (strncasecmp(c, "sffz", 4) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 139;
                    c+=4;
                } else if (strncasecmp(c, "sfz", 3) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 141;
                    c+=3;
                } else if (strncasecmp(c, "sf", 2) == 0) {
                    dynamics[cur++] = 195;
                    dynamics[cur++] = 142;
                    c+=2;
                } else
                    c++;
                break;
                
            case 'o':
                dynamics[cur++] = 'o';
                c++;
                break;
                
                /*            case ' ':
                 dynamics[cur++] = ' ';
                 c++;
                 break;
                 */
                
            default:
                c++;
                break;
        }
    }
    dynamics[cur] = 0;
    
    return gensym(dynamics);
}

void dynamics_free_marks(t_dynamics *dyn)
{
    t_dynamics_mark *temp = dyn->firstmark, *temp2;
    while (temp) {
        temp2 = temp->next;
        bach_freeptr(temp->is_roman);
        bach_freeptr(temp->text_typographic);
        bach_freeptr(temp->text_deparsed);
        bach_freeptr(temp);
        temp = temp2;
    }
    dyn->firstmark = dyn->lastmark = NULL;
    dyn->num_marks = 0;
}

t_dynamics_mark *build_dynamics_mark(long num_words)
{
    t_dynamics_mark *ds = (t_dynamics_mark *)bach_newptr(sizeof(t_dynamics_mark));
    ds->num_words = num_words;
    ds->hairpin_to_next = k_DYNAMICS_HAIRPIN_NONE;
    ds->relative_position = 0;
    ds->snap_to_breakpoint = 0;
    ds->is_roman = (char *)bach_newptr(MAX(num_words, 1) * sizeof(char));
    ds->text_typographic = (t_symbol **)bach_newptr(MAX(num_words, 1) * sizeof(t_symbol *));
    ds->text_deparsed = (t_symbol **)bach_newptr(MAX(num_words, 1) * sizeof(t_symbol *));
    for (long i = 0; i < num_words; i++) {
        ds->is_roman[i] = 0;
        ds->text_typographic[i] = NULL;
        ds->text_deparsed[i] = NULL;
    }
    ds->prev = ds->next = NULL;
    ds->dynamics_mark_attachment = k_DYNAMICS_MARK_ATTACHMENT_AUTO;
    return ds;
}

t_dynamics *dynamics_from_textbuf(t_notation_obj *r_ob, t_notation_item *owner, char *buf)
{
    t_dynamics *dyn = build_dynamics(owner);
    
    if (!buf || !buf[0]) {
        dyn->num_marks = 0;
    } else {
        
        char *a = buf, *b, *c, *d, *e, *f;
        char position[CONST_MAX_NUM_DYNAMICS_CHARS];
        char mark[CONST_MAX_NUM_DYNAMICS_CHARS];
        char hairpin[CONST_MAX_NUM_DYNAMICS_CHARS];
        long last_snapped_breakpoint = 0;
        dyn->lastmark = NULL;
        while (*a)
        {
            // each segment is composed by
            // <optional:position> <mark> <hairpin>
            b = a;
            while (*b == '.' || (*b >= '0' && *b <= '9') || *b == '@' || *b == '-' || *b == '/') // relative position
                b++;
            c = b;
            while (*c == ' ')
                c++;
            d = c;
            while (*d != 0 && *d != '<' && *d != '>' && *d != '_' && *d != '=') // mark
                d++;
            e = d;
            while (d > a && *(d-1) == ' ')
                d--;
            f = e;
            while (*f == '<' || *f == '>' || *f == '_' || *f == '=') // hairpin
                f++;
            
            sysmem_copyptr(a, position, MIN(CONST_MAX_NUM_DYNAMICS_CHARS * sizeof(char), b-a));
            position[MAX(0, MIN(CONST_MAX_NUM_DYNAMICS_CHARS - 1, b-a))] = 0;

            sysmem_copyptr(c, mark, MIN(CONST_MAX_NUM_DYNAMICS_CHARS * sizeof(char), d-c));
            mark[MAX(0, MIN(CONST_MAX_NUM_DYNAMICS_CHARS - 1, d-c))] = 0;
            
            t_llll *mark_as_llll = llll_from_text_buf(mark, false, LLLL_I_SMALLPARENS | LLLL_I_BIGPARENS);
            
            // creating new sign
            long num_words = mark_as_llll->l_size;
            t_dynamics_mark *thismark = build_dynamics_mark(num_words);
            if (!dyn->firstmark)
                dyn->firstmark = thismark;
            
            thismark->start_energy = -1;
            thismark->end_energy = -1;
            short this_start_energy, this_end_energy;
            long i = 0;
            for (t_llllelem *el = mark_as_llll->l_head; el && i < num_words; el = el->l_next, i++) {
                thismark->text_deparsed[i] = hatom_getsym(&el->l_hatom);
                if (!thismark->text_deparsed[i])
                    thismark->text_deparsed[i] = _llllobj_sym_empty_symbol;
                dynamics_parse_string_to_energy(r_ob, thismark->text_deparsed[i]->s_name, &this_start_energy, &this_end_energy);
                thismark->is_roman[i] = (this_start_energy < 0 || this_end_energy < 0);
                if (thismark->start_energy < 0)
                    thismark->start_energy = this_start_energy;
                if (this_end_energy >= 0)
                    thismark->end_energy = this_end_energy;
                if (thismark->is_roman[i]) {
                    thismark->text_typographic[i] = thismark->text_deparsed[i];
                } else {
                    if (thismark->text_deparsed)
                        thismark->text_typographic[i] = dynamics_mark_parse_string_to_typographic_text(r_ob, thismark->text_deparsed[i]->s_name);
                    else
                        thismark->text_typographic[i] = _llllobj_sym_empty_symbol;
                }
            }
            
            // special case in which the mark is simply a pipe sign: in this case it's a placeholder for an empty dynamics
            if (thismark->num_words == 1 && thismark->text_deparsed[0] == gensym("|"))
                thismark->num_words = 0;
            
            if (position[0] == '@') {
                // breakpoint attachment
                thismark->dynamics_mark_attachment = k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT;
                thismark->relative_position = 0.;
                if (position[1] != 0)
                    thismark->snap_to_breakpoint = last_snapped_breakpoint = atol(position+1);
                else
                    thismark->snap_to_breakpoint = (++last_snapped_breakpoint);
            } else if (position[0] != 0){
                thismark->dynamics_mark_attachment = k_DYNAMICS_MARK_ATTACHMENT_MANUAL;
                if (strchr(position, '/')) { // rationals
                    t_llll *templl = llll_from_text_buf(position);
                    thismark->relative_position = (templl && templl->l_head ? hatom_getdouble(&templl->l_head->l_hatom) : 0);
                    llll_free(templl);
                } else {
                    thismark->relative_position = atof(position);
                }
            } else {
                thismark->dynamics_mark_attachment = k_DYNAMICS_MARK_ATTACHMENT_AUTO;
            }
            
            llll_free(mark_as_llll);
            
            sysmem_copyptr(e, hairpin, MIN(CONST_MAX_NUM_DYNAMICS_CHARS * sizeof(char), f-e));
            hairpin[MAX(0, MIN(CONST_MAX_NUM_DYNAMICS_CHARS - 1, f-e))] = 0;
            thismark->hairpin_to_next = hairpin_textbuf_to_value(r_ob, hairpin);
            
            dyn->num_marks++;

            a = f;
            while (*a == ' ')
                a++;

            if (dyn->lastmark) {
                dyn->lastmark->next = thismark;
                thismark->prev = dyn->lastmark;
            }
            dyn->lastmark = thismark;
        }
        
        long i = 0;
        for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next, i++) {
            if (mark->dynamics_mark_attachment == k_DYNAMICS_MARK_ATTACHMENT_AUTO)
                mark->relative_position = (dyn->num_marks > 1 ? ((double)i)/(dyn->num_marks - 1) : 0.);
        }
    }
    
    dyn->text_deparsed = dynamics_to_symbol(r_ob, dyn);
    return dyn;
}



long dynamic_mark_cmp_fromtext(char *mark1, char *mark2)
{
    char *t1, *t2;
    
    if (mark2[0] == 0) {
        if (mark1[0] == 0)
            return 0;
        else
            return -1;
    }
    
    switch (mark1[0]) {
        case 0:
            return 1;
            break;
            
        case 'o':
            //        case ' ':
            if (mark2[0] == 'o') // || mark2[0] == ' ')
                return 0;
            else
                return 1;
            break;
            
        case 'p':
            if (mark2[0] == 'o')
                return -1;
            else if (mark2[0] == 'p') {
                // count number of p's
                long count1 = 0;
                for (t1 = mark1; *t1 == 'p'; t1++, count1++);
                long count2 = 0;
                for (t2 = mark2; *t2 == 'p'; t2++, count2++);
                if (count1 > count2)
                    return 1;
                else if (count2 > count1)
                    return -1;
                else
                    return 0;
            } else
                return 1;
            break;
            
        case 'm':
            if (mark2[0] == 'o' || mark2[0] == 'p')
                return -1;
            else if (mark2[0] == 'm') {
                // count number of p's
                if (mark1[1] == mark2[1])
                    return 0;
                else if (mark1[1] == 'p')
                    return 1;
                else
                    return -1;
            } else
                return 1;
            break;
            
        case 'f':
            if (mark2[0] == 'o' || mark2[0] == 'p' || mark2[0] == 'm')
                return -1;
            else if (mark2[0] == 'f') {
                // count number of f's
                long count1 = 0;
                for (t1 = mark1; *t1 == 'f'; t1++, count1++);
                long count2 = 0;
                for (t2 = mark2; *t2 == 'f'; t2++, count2++);
                if (count1 > count2)
                    return -1;
                else if (count2 > count1)
                    return 1;
                else
                    return 0;
            } else
                return 1;
            break;
            
        case 's':
            if (mark2[0] == 'o' || mark2[0] == 'p' || mark2[0] == 'm' || mark2[0] == 'f')
                return -1;
            else if (mark2[0] == 's') {
                // count number of f's after the s
                long count1 = 0;
                for (t1 = mark1+1; *t1 == 'f'; t1++, count1++);
                long count2 = 0;
                for (t2 = mark2+1; *t2 == 'f'; t2++, count2++);
                if (count1 > count2)
                    return -1;
                else if (count2 > count1)
                    return 1;
                else
                    return 0;
            } else
                return 1;
            break;
            
        default:
            return 0;
            break;
    }
}

long dynamic_mark_end_start_cmp(t_dynamics_mark *s1, t_dynamics_mark *s2)
{
    return (s1->end_energy > s2->start_energy ? -1 : (s1->end_energy == s2->start_energy ? 0 : 1));
}


void check_dynamics_get_path(t_notation_obj *r_ob, t_chord *ch, char *path, long path_size, long dynamics_index)
{
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        if (dynamics_index > 0)
            snprintf(path, path_size, "(voice %ld, measure %ld, chord %ld, dynamic marking %ld)", ch->parent->voiceparent->v_ob.number+1, ch->parent->measure_number+1, notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)ch), dynamics_index);
        else
            snprintf(path, path_size, "(voice %ld, measure %ld, chord %ld)", ch->parent->voiceparent->v_ob.number+1, ch->parent->measure_number+1, notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)ch));
    } else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
        if (dynamics_index > 0)
            snprintf(path, path_size, "(voice %ld, chord %ld, dynamic marking %ld)", ch->voiceparent->v_ob.number+1, notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)ch), dynamics_index);
        else
            snprintf(path, path_size, "(voice %ld, chord %ld)", ch->voiceparent->v_ob.number+1, notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)ch));
    } else
        path[0] = 0;
}


void reassemble_dynamics_buf(t_notation_obj *r_ob, long num_dynamics, char dynamic_text[][CONST_MAX_NUM_DYNAMICS_CHARS], long *hairpins, char *out_buf, long out_buf_size)
{
    long cur = 0;
    for (long i = 0; i < num_dynamics; i++) {
        cur += snprintf(out_buf+cur, out_buf_size - cur, "%s", dynamic_text[i]);
        if (hairpins[i] || i < num_dynamics - 1) {
            switch (hairpins[i]) {
                case -2:
                    cur += snprintf(out_buf+cur, out_buf_size - cur, ">>");
                    break;
                case -1:
                    cur += snprintf(out_buf+cur, out_buf_size - cur, ">");
                    break;
                case 0:
                    cur += snprintf(out_buf+cur, out_buf_size - cur, "_");
                    break;
                case 1:
                    cur += snprintf(out_buf+cur, out_buf_size - cur, "<");
                    break;
                case 2:
                    cur += snprintf(out_buf+cur, out_buf_size - cur, "<<");
                    break;
                default:
                    break;
            }
        }
    }
    out_buf[cur] = 0;
}

t_dynamics *chord_get_dynamics(t_chord *ch, t_slotitem **slotitem)
{
    t_slot *slot = ch->dynamics_slot;
    if (slot && slot->firstitem && slot->firstitem->item) {
        if (slotitem) *slotitem = slot->firstitem;
        return (t_dynamics *)slot->firstitem->item;
    } else {
        if (slotitem) *slotitem = NULL;
        return NULL;
    }
    
}

void dynamics_mark_to_textbuf(t_dynamics_mark *mark, char *buf, long buf_size)
{
    long cur = 0;
    for (long i = 0; i < mark->num_words; i++) {
        cur += snprintf_zero(buf+cur, buf_size - cur, i == mark->num_words - 1 ? "%s" : "%s ", mark->text_deparsed[i] ? mark->text_deparsed[i]->s_name : "");
    }
}

// -1 = dim, 1 = cresc, 0 = none
char hairpin_is_crescordim(long hairpin)
{
    switch (hairpin) {
        case k_DYNAMICS_HAIRPIN_DIM:
        case k_DYNAMICS_HAIRPIN_DIMEXP:
        case k_DYNAMICS_HAIRPIN_DIMDASHED:
            return -1;
            break;
            
        case k_DYNAMICS_HAIRPIN_CRESC:
        case k_DYNAMICS_HAIRPIN_CRESCEXP:
        case k_DYNAMICS_HAIRPIN_CRESCDASHED:
            return 1;
            break;

        default:
            return 0;
            break;
    }
}

long notationobj_check_dynamics(t_notation_obj *r_ob, long slot_num, char check_inconsistent, char check_unnecessary, char fix_inconsistent, char fix_unnecessary, char selection_only, char verbose)
{
    char path[1024];
    char temp_mark_text[1024], temp_mark_text2[1024];
    long i;
    long last_hairpin = 0;
    t_dynamics *last_dyn = NULL;
    t_chord *last_chord = NULL;
    t_dynamics_mark *lastmark = NULL;
    
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
        last_chord = NULL;
        last_hairpin = 0;
        
        
        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ) {
            char something_fixed = false;
            
            if (selection_only && !notation_item_is_globally_selected(r_ob, (t_notation_item *)ch)) {
                ch = chord_get_next(ch);
                continue;
            }
            
            t_dynamics *dyn = chord_get_dynamics(ch);
            
            if (dyn && dyn->firstmark){
                long num_marks = dyn->num_marks;

                // checking dangling hairpin
                if (check_inconsistent && hairpin_is_crescordim(last_hairpin) != 0) {
                    long cmp = dynamic_mark_end_start_cmp(lastmark, dyn->firstmark);
                    if (last_hairpin * cmp <= 0) {
                        if (verbose) {
                            check_dynamics_get_path(r_ob, ch, path, 1024, num_marks > 1 ? 1 : 0);
                            dynamics_mark_to_textbuf(lastmark, temp_mark_text, 1024);
                            dynamics_mark_to_textbuf(dyn->firstmark, temp_mark_text2, 1024);
                            object_warn((t_object *)r_ob, "Inconsistent %s found from '%s' to '%s' %s", last_hairpin > 0 ? "crescendo" : "diminuendo", temp_mark_text, temp_mark_text2, path);
                        }
                        
                        if (fix_inconsistent && last_dyn && last_dyn->lastmark) {
                            create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)last_chord, k_UNDO_MODIFICATION_CHANGE);
                            last_dyn->lastmark->hairpin_to_next = labs(last_hairpin) * cmp; // correcting the previous hairpin
                            last_dyn->text_deparsed = dynamics_to_symbol(r_ob, last_dyn);

                            // ... but if the corrected last_hairpin == 0, the dynamics on last_chord might have become unnecessary.
                            if (check_unnecessary && fix_unnecessary) {
                                if (last_dyn->lastmark->hairpin_to_next == k_DYNAMICS_HAIRPIN_NONE) {
                                    // Let's rewind the mechanism of a step, to check whether it is unnecessary
                                    last_dyn = NULL;
                                    ch = dynamics_get_prev(r_ob, voice, slot_num, last_chord, NULL, NULL, NULL, NULL, NULL);
                                    if (!ch)
                                        ch = last_chord;
                                    last_chord = NULL;
                                    lastmark = NULL;
                                    last_hairpin = k_DYNAMICS_HAIRPIN_NONE;
                                    continue;
                                }
                            }
                        }
                    }
                }
                
                // checking unnecessary dynamics
                if (check_unnecessary) {
                    
                    char then_continue = false;
                    while (!last_hairpin && lastmark && dyn->firstmark && dyn->firstmark->num_words == 1 && lastmark->num_words == 1 && dyn->firstmark->text_typographic[0] == lastmark->text_typographic[0] && dyn->firstmark->hairpin_to_next == k_DYNAMICS_HAIRPIN_NONE) {
                        if (verbose) {
                            check_dynamics_get_path(r_ob, ch, path, 1024, num_marks > 1 ? 1 : 0);
                            dynamics_mark_to_textbuf(lastmark, temp_mark_text, 1024);
                            object_warn((t_object *)r_ob, "Unnecessary dynamic marking found: '%s' %s", temp_mark_text, path);
                        }
                        if (fix_unnecessary) {
                            something_fixed = true;
                            create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
                            dynamics_mark_delete(dyn, dyn->firstmark);
                            if (!dyn->firstmark) {
                                delete_chord_dynamics(r_ob, ch);
                                then_continue = true;
                            }
                        } else {
                            break;
                        }
                    }
                    
                    if (then_continue)
                        continue;
                    
                    
                    i = 0;
                    for (t_dynamics_mark *mark = dyn->firstmark->next; mark; mark = mark->next, i++) {
                        if (mark->prev->num_words == 1 && mark->num_words == 1 && mark->prev->text_typographic[0] == mark->text_typographic[0] && mark->prev->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE && mark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE) {
                            if (verbose) {
                                check_dynamics_get_path(r_ob, ch, path, 1024, num_marks > 1 ? i : 0);
                                dynamics_mark_to_textbuf(lastmark, temp_mark_text, 1024);
                                object_warn((t_object *)r_ob, "Unnecessary dynamic marking found: '%s' %s", temp_mark_text, path);
                            }
                            if (fix_unnecessary) {
                                something_fixed = true;
                                create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
                                dynamics_mark_delete(dyn, mark);
                            }
                        }
                    }
                }
                
                // checking hairpins
                if (check_inconsistent) {
                    i = 0;
                    for (t_dynamics_mark *mark = dyn->firstmark->next; mark; mark = mark->next, i++) {
                        // comparing i-1 with i
                        long cmp = dynamic_mark_end_start_cmp(mark->prev, mark);
                        if (mark->prev->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE && mark->prev->hairpin_to_next * cmp <= 0) {
                            if (verbose) {
                                check_dynamics_get_path(r_ob, ch, path, 1024, num_marks > 1 ? i : 0);
                                dynamics_mark_to_textbuf(mark->prev, temp_mark_text, 1024);
                                dynamics_mark_to_textbuf(mark, temp_mark_text2, 1024);
                                object_warn((t_object *)r_ob, "Inconsistent %s found from '%s' to '%s' %s", mark->prev->hairpin_to_next > 0 ? "crescendo" : "diminuendo", temp_mark_text, temp_mark_text2, path);
                            }
                            if (fix_inconsistent) {
                                something_fixed = true;
                                create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
                                mark->prev->hairpin_to_next = labs(mark->prev->hairpin_to_next) * cmp; // correcting the hairpin
                            }
                        }
                    }
                }
                
                if (num_marks > 0) {
                    last_hairpin = dyn->lastmark ? dyn->lastmark->hairpin_to_next : k_DYNAMICS_HAIRPIN_NONE;
                    lastmark = dyn->lastmark;
                }
            }
            
            
            if (dyn && something_fixed) {
                dyn->text_deparsed = dynamics_to_symbol(r_ob, dyn);
            }
            
            if (dyn) {
                last_dyn = dyn;
                last_chord = ch;
            }

            ch = chord_get_next(ch);
        }
    }
    
    if (fix_unnecessary || fix_inconsistent) {
        if (r_ob->link_dynamics_to_slot - 1 >= 0 && r_ob->link_dynamics_to_slot - 1 < CONST_MAX_SLOTS)
            check_slot_linkage_recomputations_for_everything(r_ob, r_ob->link_dynamics_to_slot - 1);
        notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    }
    
    handle_change_if_there_are_free_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_FIX_DYNAMICS);
    
    return 0;
}


// 1-based index of the dynamics inside the dynamics spectrum of half width <dynamics_spectrum_halfwidth>
long dynamics_symbol_to_spectrum_index(t_symbol *dyn, long dynamics_spectrum_halfwidth)
{
    char buf[128];
    
    if (dynamics_spectrum_halfwidth < 1)
        return -1;
    
    if (dyn == gensym("mp")) return dynamics_spectrum_halfwidth;
    if (dyn == gensym("mf")) return dynamics_spectrum_halfwidth + 1;
    
    for (long i = 1; i < dynamics_spectrum_halfwidth && i < 127; i++) {
        long j = 0;
        for (; j < i; j++) buf[j] = 'p';
        buf[j] = 0;
        if (!strcmp(buf, dyn->s_name))
            return dynamics_spectrum_halfwidth - i;
    }
    
    for (long i = 1; i < dynamics_spectrum_halfwidth && i < 127; i++) {
        long j = 0;
        for (; j < i; j++) buf[j] = 'f';
        buf[j] = 0;
        if (!strcmp(buf, dyn->s_name))
            return dynamics_spectrum_halfwidth + 1 + i;
    }
    
    return -1;
}

// spectrum index is 1-based
long energy_to_spectrum_index(long energy, long dynamics_spectrum_halfwidth)
{
    if (dynamics_spectrum_halfwidth < 1 || energy < 0)
        return -1;
    
    
    long val = (energy - 100) + dynamics_spectrum_halfwidth; // this maps p-->H-1, mp-->H, mf-->H+1, f-->H+2, ...,
                                                             // where H = dynamics_spectrum_halfwidth
    return CLAMP(val, 1, dynamics_spectrum_halfwidth * 2 );
}


t_symbol *spectrum_index_to_dynamics(long index, long dynamics_spectrum_halfwidth)
{
    char buf[129];
    long D = dynamics_spectrum_halfwidth;
    if (index <= 0 || index > 2*D)
        return NULL;
    
    if (index == D)
        return gensym("mp");
    if (index == D+1)
        return gensym("mf");
    
    if (index <= D) {
        long j = 0;
        double num_chars = D - index;
        for (; j < num_chars && j < 128; j++)
            buf[j] = 'p';
        buf[j] = 0;
        return gensym(buf);
    } else {
        long j = 0;
        double num_chars = index - D - 1;
        for (; j < num_chars && j < 128; j++)
            buf[j] = 'f';
        buf[j] = 0;
        return gensym(buf);
    }
}

char dynamics_to_velocity_from_spectrum_index(long idx, double *vel, t_dynamics_params *params, char clip_between_1_and_127)
{
    long D = params->dynamics_spectrum_halfwidth;
    double a = params->a;
    double b = params->b;
    if (idx <= 0 || idx > 2 * D) {
        *vel = 0;
        return 1;
    } else if (idx > D) {
        *vel = 128. * pow((1 + pow(-1 + (2. * idx)/(2. * D + 1), a))/2., b);
    } else {
        *vel = 128. * pow((1 - pow(1 - (2. * idx)/(2. * D + 1), a))/2., b);
    }
    if (clip_between_1_and_127)
        *vel = CLAMP(*vel, 1, 127);
    return 0;
}

char velocity_to_spectrum_index_dynamics(double vel, long *idx, t_dynamics_params *params, char clip_to_spectrum)
{
    long D = params->dynamics_spectrum_halfwidth;
    double a = params->a;
    double b = params->b;
    if (vel <= 0 || vel > CONST_MAX_VELOCITY) {
        *idx = -1;
        return 1;
    } else {
        double x, xi = 2*pow(vel/128., 1./b) - 1.;
        if (xi >= 0)
            x = pow(xi, 1./a);
        else
            x = -pow(-xi, 1./a);
        *idx = round((D + 0.5) * (x + 1));
    }
    if (clip_to_spectrum)
        *idx = CLAMP(*idx, 1, 2*D);
    return 0;
}


void dynamics_compute_b(t_dynamics_params *params)
{
    params->b = 1./(1 - log2(1. - 1./(pow(2. * params->dynamics_spectrum_halfwidth + 1, params->a))));
}

char dynamics_mark_to_velocity_builtin(t_dynamics_mark *dynmark, double *vel, t_dynamics_params *params, char usage_alignment)
{
    // The <dynamics_spectrum_halfwidth> = D is the number of dynamics usable dynamics on the "piano" spectrum
    // (or, equivalently, the number of dynamics for "forte" spectrum: these two must be symmetric)
    // For instance, if only "pp", "p", "mp", "mf", "f", "ff" are required, the dynamics_range is 3
    // (since we have 3 dynamics for the forte, and 3 dynamics for the piano, including the "mezzo-" dynamics).
    // By default, dynamics_range is 5, which goes from "pppp" to "ffff".
    
    // The equation linking dynamics to velocity depends on the dynamics_spectrum_halfwidth D.
    // Let i be the 1-based index of the dynamics inside the whole dynamics spectrum (e.g. "pppp" is 1 if D = 5).
    // Hence i ranges from 1 to 2D
    // The idea is to divide the interval from x \in [-1, 1] in 2D+1 sub-intervals; the points x = 0 and x = 1 are
    // not assigned to any dynamics (x = -1 will be the 0 dynamics, while x = 1 will be a "sfz"/"sffz"/"fz"/"ffz"/"sf").
    // All the intermediate points correspond to the dynamics inside the spectrum (< 0 for "piano" dynamics, > 0 for "forte" dynamics).
    // The equation linking the index i to the velocity D is the following (for i = 1, ..., 2D)
    //
    // vel(i) = 128 * ((1 + sgn(-1+2i/(2D+1))*|-1+2i/(2D+1)|^a)/2)^b
    //
    // More clearly, once set x = -1+2i/(2D+1), as previously explained, one has
    // vel(i) = 128 * ((1 + sgn(x)*|x|^a)/2)^b
    //
    // This function assumes values between 0. and 1., for x in [-1, 1].
    // We'll surely then clip the velocity from 0 to 127 (128 won't be allowed), but we need 128 because
    // now, we want to force the fact that "mp" must be assigned to the 64 velocity, and using 128 will make things nicer:
    // This indeed implies forcing
    // vel(-1 + 2D/(2D+1)) = 64, hence
    // ((1 -(1/(2D+1))^a)/2)^b = 1/2
    // (1 -1/((2D+1)^a))^b = 2^(b-1)
    // 2^((b-1)/b)) = 1 - 1/((2D+1)^a)
    // yielding
    // 1-1/b = log2(1 - 1/((2D+1)^a))
    // This gives us b automatically
    // b = 1/(1 - log2(1 - 1/((2D+1)^a)))
    
    // Hence we only have one free parameter: a, that users may change; b will change accordingly in order to keep mp --> 64
    
    
    if (!dynmark)
        return 1;
    
    long energy = usage_alignment > 0 ? dynmark->end_energy : dynmark->start_energy;
    
    if (energy < 0)
        return 1;
    
    if (energy == 0) { *vel = CONST_MIN_VELOCITY; return 0; }
    if (energy >= 200) { *vel = CONST_MAX_VELOCITY; return 0; }
    
    long D = params->dynamics_spectrum_halfwidth;
    long index = energy_to_spectrum_index(energy, D);
    if (index >= 1 && index <= 2 * D) {
        if (!dynamics_to_velocity_from_spectrum_index(index, vel, params, true))
            return 0;
    }
    
    return 1;
}

char velocity_to_dynamics_builtin(double vel, t_symbol **dyn, t_dynamics_params *params, char clip_vel)
{
    if (clip_vel)
        vel = CLAMP(vel, 0, CONST_MAX_VELOCITY);
    
    if (vel < 0 || vel > CONST_MAX_VELOCITY)
        return 1;
    
    if (vel == 0) { *dyn = gensym("0"); return 0; }
    if (vel == 127) { *dyn = gensym("sffz"); return 0; }
    
    long index = -1;
    
    if (!velocity_to_spectrum_index_dynamics(vel, &index, params, true)) {
        *dyn = spectrum_index_to_dynamics(index, params->dynamics_spectrum_halfwidth);
        if (*dyn)
            return 0;
        else
            return 1;
    }
    
    return 1;
}


// usage_alignment > 0 ----> align to right dynamics in case of composed dynamics such as "fp" or "f somethingroman p", etc.
// usage_alignment < 0 ----> align to left dynamics in case of composed dynamics such as "fp" or "f somethingroman p", etc.
char dynamics_mark_to_velocity(t_notation_obj *r_ob, t_dynamics_mark *dynmark, double *vel, t_llll *dyn_vel_associations, t_dynamics_params *params, char usage_alignment)
{
    if (!dynmark)
        return 1;

    t_symbol *sym = usage_alignment > 0 ? dynamics_mark_get_last_nonroman_symbol(dynmark, NULL) : dynamics_mark_get_first_nonroman_symbol(dynmark, NULL);

    if (dyn_vel_associations) {
        for (t_llllelem *el = dyn_vel_associations->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                if (ll && ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && is_hatom_number(&ll->l_head->l_next->l_hatom) &&
                    hatom_getsym(&ll->l_head->l_hatom) == sym) {
                    if (usage_alignment > 0 && ll->l_size >= 3 && is_hatom_number(&ll->l_head->l_next->l_next->l_hatom))
                        *vel = hatom_getdouble(&ll->l_head->l_next->l_next->l_hatom);
                    else
                        *vel = hatom_getdouble(&ll->l_head->l_next->l_hatom);
                    *vel = CLAMP(*vel, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
                    return 0;
                }
            }
        }
    }
    
    // If not found, go with defaults
    if (!dynamics_mark_to_velocity_builtin(dynmark, vel, params, usage_alignment)) {
        *vel = CLAMP(*vel, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
        return 0;
    }
    
    return 1;
}


t_symbol *dynamics_add_ending_hairpin(t_symbol *dyn, long hairpin)
{
    char buf[CONST_MAX_NUM_DYNAMICS_CHARS];
    snprintf_zero(buf, CONST_MAX_NUM_DYNAMICS_CHARS, "%s%s", dyn->s_name, hairpin > 1 ? "<<" : hairpin > 0 ? "<" : hairpin < -1 ? ">>" : hairpin < 0 ? ">" : "");
    return gensym(buf);
}

// returns 0 if OK, 1 otherwise
char velocity_to_dynamics(t_notation_obj *r_ob, double vel, t_symbol **dyn, t_llll *dyn_vel_associations, t_dynamics_params *params)
{
    if (dyn_vel_associations && dyn_vel_associations->l_head) {
        // We need NOT using the default formula, but rather the defined associations.
        t_llll *assoc = llll_clone(dyn_vel_associations);
        llll_inplacesort(assoc, (sort_fn)llll_sort_by_second);
        double below = 0, above = 0;
        t_symbol *below_sym = NULL, *above_sym = NULL;
        for (t_llllelem *el = dyn_vel_associations->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                if (ll && ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && is_hatom_number(&ll->l_head->l_next->l_hatom)) {
                    double this_vel = hatom_getdouble(&ll->l_head->l_next->l_hatom);
                    if (vel >= this_vel && (!below_sym || this_vel > below)) {
                        below_sym = hatom_getsym(&ll->l_head->l_hatom);
                        below = this_vel;
                    }
                    if (vel <= this_vel && !above_sym) {
                        above_sym = hatom_getsym(&ll->l_head->l_hatom);
                        above = this_vel;
                        break;
                    }
                }
            }
        }
        
        if (!below_sym && !above_sym) {
            return 1;
        } else if (below_sym && !above_sym) {
            *dyn = below_sym;
            return 0;
        } else if (above_sym && !below_sym) {
            *dyn = above_sym;
            return 0;
        } else {
            if (above - vel <= vel - below)
                *dyn = above_sym;
            else
                *dyn = below_sym;
            return 0;
        }
    }
    
    // If not found, go with defaults
    if (!velocity_to_dynamics_builtin(vel, dyn, params, true)) {
        return 0;
    }
    
    return 1;
}



// THIS FUNCTION IS UNUSED FOR NOW. DYNAMICS ARE GLOBAL (unfortunately?)
char is_dynamics_local(t_notation_obj *r_ob, t_llll *dyn_vel_associations, t_symbol *dyn, t_dynamics_params *params, char usage_alignment)
{
    if (dyn_vel_associations) {
        for (t_llllelem *el = dyn_vel_associations->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                if (ll && ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM &&
                    (((usage_alignment <= 0 || ll->l_size == 2) && hatom_gettype(&ll->l_head->l_next->l_hatom) == H_SYM)||
                     ((usage_alignment > 0 && ll->l_size >= 3) && hatom_gettype(&ll->l_head->l_next->l_next->l_hatom) == H_SYM))) {
                        return true;
                    }
            }
        }
    }
    
    if (dyn == gensym("sfz")) return true;
    if (dyn == gensym("sffz")) return true;
    if (dyn == gensym("sf")) return true;
    if (dyn == gensym("sff")) return true;
    if (dyn == gensym("fz")) return true;
    
    return false;
}



t_symbol *chord_get_first_dynamic_marking_as_symbol(t_notation_obj *r_ob, t_chord *ch, long slot_num)
{
    t_dynamics *dyn = chord_get_dynamics(ch);
    if (dyn && dyn->firstmark) {
        char temp[8192];
        dynamics_mark_to_textbuf(dyn->firstmark, temp, 8192);
        return gensym(temp);
    }
    return NULL;
}


// bptmode = 0: don't add/delete breakpoints
// bptmode = 1: add breakpoints to match dynamics
// bptmode = 2: also delete existing breakpoints before adding new ones
void chord_assign_velocities_from_dynamics(t_notation_obj *r_ob, t_chord *ch, t_llll *dyn_vel_associations, t_dynamics_params *params,
                                           t_chord *left_dyns_chord,
                                           t_dynamics_mark *last_dyn_mark, t_dynamics *left_dyn, t_dynamics_mark *right_dyn_mark,
                                           double left_onset, double right_onset,
                                           char add_undo_tick, char bptmode, long slot_num)
{
    char marktext[1024], marktext2[1024];
    double velocity = 0;
    double left_velocity = 0, right_velocity = 0;
    const double DYNAMICS_TO_VELOCITY_EXP_SLOPE = 0.6;
    
    if (left_dyn && left_dyn->firstmark) {
        double ch_onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)ch);
        
        if (ch != left_dyns_chord && left_dyn->num_marks > 1)
            left_onset += chord_get_max_duration(r_ob, ch);
        
        if (add_undo_tick)
            create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
        
        long last_hairpin = left_dyn->lastmark->hairpin_to_next;
        
        if (ch == left_dyns_chord) {
            t_dynamics_mark *prev_mark = dynamics_mark_is_placeholder(left_dyn->firstmark) ? last_dyn_mark : left_dyn->firstmark;
            
            // sticky assignment of the left dynamics to the chord
            if (!dynamics_mark_to_velocity(r_ob, prev_mark, &velocity, dyn_vel_associations, params, -1)) {
                for (t_note *nt = ch->firstnote; nt; nt = nt->next) {
                    nt->velocity = velocity;
                    if (r_ob->breakpoints_have_velocity) {
                        
                        if (bptmode >= 1 && dynamics_has_internal_relativeposition(left_dyn)) {

                            if (bptmode >= 2)
                                note_delete_breakpoints(r_ob, nt);
                            
                            // possibly creating internal breakpoints when dynamics are more than 2 for a single note
                            // First dynamics will correspond to notehead, last dynamics will correspond to note tail
                            for (t_dynamics_mark *mk = left_dyn->firstmark; mk; mk = mk->next) {
                                double relative_bpt_position = mk->relative_position;
                                if (relative_bpt_position > 0. && relative_bpt_position < 1.) {
                                    // check whether there's already a breakpoint around here (with threshold 1 ms)
                                    char found = false;
                                    for (t_bpt *bpt = nt->firstbreakpoint; bpt; bpt = bpt->next)
                                        if (fabs(bpt->rel_x_pos * nt->duration - relative_bpt_position * nt->duration) < 1.) {
                                            found = true;
                                            break;
                                        }
                                    if (!found)
                                        add_breakpoint(r_ob, nt, relative_bpt_position, 0, 0, true, 0, true);
                                }
                            }
                        }
                        
                        
                        for (t_bpt *bpt = nt->firstbreakpoint; bpt; bpt = bpt->next) {
                            if (!bpt->prev || (left_dyn->num_marks <= 1 && hairpin_is_crescordim(last_hairpin) == 0))
                                bpt->velocity = velocity;
                            
                            else if (left_dyn->num_marks == 1 && hairpin_is_crescordim(last_hairpin) != 0) {
                                // we have a starting dynamics, then a hairpin ending to some other future chord (e.g. "ff>")
                                // gotta find that "future chord"
                                t_chord *nextchwithdyn = chord_get_next_with_dynamics(r_ob, ch, NULL, false, false);
                                if (nextchwithdyn) {
                                    // get first dynamics
                                    t_dynamics *right_dyn_temp = chord_get_dynamics(nextchwithdyn);
                                    if (right_dyn_temp) {
                                        if (!dynamics_mark_to_velocity(r_ob, prev_mark, &left_velocity, dyn_vel_associations, params, 1)) {
                                            if (!dynamics_mark_to_velocity(r_ob, right_dyn_temp->firstmark, &right_velocity, dyn_vel_associations, params, -1)) {
                                                bpt->velocity = rescale_with_slope_inv(notation_item_get_onset_ms(r_ob, (t_notation_item *)bpt), notation_item_get_onset_ms(r_ob, (t_notation_item *)nt), notation_item_get_onset_ms(r_ob, (t_notation_item *)nextchwithdyn), left_velocity, right_velocity, last_hairpin > 1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : (last_hairpin < -1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : 0.));
                                            } else {
                                                dynamics_mark_to_textbuf(right_dyn_temp->firstmark, marktext, 1024);
                                                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
                                            }
                                        } else {
                                            dynamics_mark_to_textbuf(prev_mark, marktext, 1024);
                                            object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
                                        }
                                    } else {
                                        bpt->velocity = velocity;
                                    }
                                } else {
                                    bpt->velocity = velocity;
                                }
                                
                            } else {
                                // choosing appropriate markings
                                t_dynamics_mark *left = left_dyn->firstmark, *left_corrected = left;
                                t_dynamics_mark *right = left_dyn->lastmark;
                                while (left && left->next && left->next->relative_position <= bpt->rel_x_pos)
                                    left = left->next;
                                while (right && right->prev && right->prev->relative_position >= bpt->rel_x_pos)
                                    right = right->prev;
                                
                                while (left && left->prev && dynamics_mark_is_placeholder(left))
                                    left = left->prev;

                                while (right && right->next && dynamics_mark_is_placeholder(right))
                                    right = right->next;

                                if (left == left_dyn->firstmark && dynamics_mark_is_placeholder(left))
                                    left_corrected = last_dyn_mark;
                                else
                                    left_corrected = left;

                                if (left == right || hairpin_is_crescordim(left->hairpin_to_next) == 0) {
                                    if (!dynamics_mark_to_velocity(r_ob, left_corrected, &left_velocity, dyn_vel_associations, params, 1)) {
                                        bpt->velocity = left_velocity;
                                    } else {
                                        dynamics_mark_to_textbuf(left, marktext, 1024);
                                        object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
                                    }
                                } else {
                                    if (!dynamics_mark_to_velocity(r_ob, left_corrected, &left_velocity, dyn_vel_associations, params, 1)) {
                                        if (!dynamics_mark_to_velocity(r_ob, right, &right_velocity, dyn_vel_associations, params, -1)) {
                                            bpt->velocity = rescale_with_slope_inv(bpt->rel_x_pos, left->relative_position, right->relative_position, left_velocity, right_velocity, hairpin_is_crescordim(left->hairpin_to_next) == k_DYNAMICS_HAIRPIN_CRESCEXP ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : (hairpin_is_crescordim(left->hairpin_to_next) == k_DYNAMICS_HAIRPIN_DIMEXP ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : 0.));
                                        } else {
                                            dynamics_mark_to_textbuf(right, marktext, 1024);
                                            object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
                                        }
                                    } else {
                                        dynamics_mark_to_textbuf(left_corrected, marktext, 1024);
                                        object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                dynamics_mark_to_textbuf(left_dyn->firstmark, marktext, 1024);
                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic mark '%s'. Skipping all chord markings.", marktext);
            }
            
            
            
        } else if (right_dyn_mark && last_hairpin) {
            // if there's a crescendo/diminuendo, interpolate
            if (!dynamics_mark_to_velocity(r_ob, left_dyn->lastmark, &left_velocity, dyn_vel_associations, params,  1)) {
                if (!dynamics_mark_to_velocity(r_ob, right_dyn_mark, &right_velocity, dyn_vel_associations, params, -1)) {
                    if (last_hairpin * (right_velocity - left_velocity) > 0) {
                        velocity = rescale_with_slope(CLAMP(ch_onset, left_onset, right_onset), left_onset, right_onset, left_velocity, right_velocity, last_hairpin > 1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : (last_hairpin < -1 ? -DYNAMICS_TO_VELOCITY_EXP_SLOPE : 0.));
                        for (t_note *nt = ch->firstnote; nt; nt = nt->next) {
                            nt->velocity = velocity;
                            if (r_ob->breakpoints_have_velocity) {
                                for (t_bpt *bpt = nt->firstbreakpoint; bpt; bpt = bpt->next) {
                                    if (!bpt->prev)
                                        bpt->velocity = velocity;
                                    else {
                                        bpt->velocity = rescale_with_slope_inv(CLAMP(notation_item_get_onset_ms(r_ob, (t_notation_item *)bpt), left_onset, right_onset), left_onset, right_onset, left_velocity, right_velocity, last_hairpin > 1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : (last_hairpin < -1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : 0.));
                                    }
                                }
                            }
                        }
                    } else {
                        dynamics_mark_to_textbuf(left_dyn->lastmark, marktext, 1024);
                        dynamics_mark_to_textbuf(right_dyn_mark, marktext2, 1024);
                        object_warn((t_object *)r_ob, "Incoherent hairpin found between dynamic markings '%s' and '%s'. Skipping assignments.", marktext, marktext2);
                    }
                } else {
                    dynamics_mark_to_textbuf(right_dyn_mark, marktext, 1024);
                    object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
                }
            } else {
                dynamics_mark_to_textbuf(left_dyn->lastmark, marktext, 1024);
                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
            }
            
        } else if (left_dyn->lastmark) {
            if (!dynamics_mark_to_velocity(r_ob, left_dyn->lastmark, &velocity, dyn_vel_associations, params, 1)) {
                for (t_note *nt = ch->firstnote; nt; nt = nt->next) {
                    nt->velocity = velocity;
                    if (r_ob->breakpoints_have_velocity) {
                        for (t_bpt *bpt = nt->firstbreakpoint; bpt; bpt = bpt->next)
                            bpt->velocity = velocity;
                    }
                }
            } else {
                dynamics_mark_to_textbuf(left_dyn->lastmark, marktext, 1024);
                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamic marking '%s'. Skipping dynamic marking.", marktext);
            }
        }
    } else {
        // we should never be here, but still:
        object_warn((t_object *)r_ob, "Cannot assign dynamics, no initial dynamics assigned.");
    }
}

long notationobj_dynamics2velocities(t_notation_obj *r_ob, long slot_num, t_llll *dyn_vel_associations, char selection_only, long dynamics_spectrum_halfwidth, double a_exp, char bptmode)
{
    t_dynamics *curr_dyn = NULL;
    t_dynamics *next_dyn = NULL;
    t_dynamics_mark *prev_dyn_mark = NULL;

    
    long curr_num_dynamics = 0, next_num_dynamics = 0;
    char curr_open_hairpin = 0, next_open_hairpin = 0;
    
    t_dynamics_params params;
    params.a = a_exp;
    params.dynamics_spectrum_halfwidth = dynamics_spectrum_halfwidth;
    dynamics_compute_b(&params);
    
    
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
        t_chord *curr_dyn_chord = NULL, *next_dyn_chord = NULL;
        double curr_dyn_onset = -1, next_dyn_onset = -1;
        
        next_dyn_chord = dynamics_get_next(r_ob, voice, slot_num, next_dyn_chord, &next_dyn_onset);
        if (next_dyn_chord)
            next_dyn = chord_get_dynamics(next_dyn_chord);
        
        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ch = chord_get_next(ch)) {
            if (ch == next_dyn_chord) {
                prev_dyn_mark = curr_dyn ? curr_dyn->lastmark : NULL;
                curr_dyn_chord = next_dyn_chord;
                curr_dyn_onset = next_dyn_onset;
                curr_num_dynamics = next_num_dynamics;
                curr_open_hairpin = next_open_hairpin;
                curr_dyn = next_dyn;
                next_dyn_chord = dynamics_get_next(r_ob, voice, slot_num, next_dyn_chord, &next_dyn_onset);
                if (next_dyn_chord)
                    next_dyn = chord_get_dynamics(next_dyn_chord);
            }
            
            if (selection_only && !notation_item_is_globally_selected(r_ob, (t_notation_item *)ch))
                continue;
            
            chord_assign_velocities_from_dynamics(r_ob, ch, dyn_vel_associations, &params, curr_dyn_chord,
                                                  prev_dyn_mark, curr_dyn, next_dyn_chord && next_dyn && next_dyn->num_marks > 0 ? next_dyn->firstmark : NULL,
                                                  curr_dyn_onset, next_dyn_onset, true, bptmode, slot_num);
        }
        
    }
    
    handle_change_if_there_are_free_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_ASSIGN_VELOCITIES);
    
    return 0;
}

t_llll *dynamic_mark_to_slots_ll(long slot_num, t_symbol *dyn)
{
    t_llll *ll = llll_get();
    t_llll *subll = llll_get();
    llll_appendlong(subll, slot_num + 1); // 1-based for interface
    llll_appendsym(subll, dyn);
    llll_appendllll(ll, subll);
    return ll;
}

void erase_chord_dynamics(t_notation_obj *r_ob, t_chord *ch, long slot_num, char add_undo_tick)
{
    char undo_tick_added = false;
    
    if (notation_item_get_slot_firstitem(r_ob, (t_notation_item *)ch, slot_num)) {
        if (add_undo_tick) {
            undo_tick_added = true;
            create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
        }
        notation_item_clear_slot(r_ob, (t_notation_item *)ch, slot_num);
    }
    
    for (t_note *nt = ch->firstnote; nt; nt = nt->next){
        if (notation_item_get_slot_firstitem(r_ob, (t_notation_item *)nt, slot_num)) {
            if (add_undo_tick && !undo_tick_added) {
                undo_tick_added = true;
                create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
            }
            notation_item_clear_slot(r_ob, (t_notation_item *)nt, slot_num);
        }
    }
}

t_symbol *assign_chord_dynamics_from_velocities(t_notation_obj *r_ob, t_chord *ch, long slot_num, t_llll *dyn_vel_associations, t_dynamics_params *params, char add_undo_tick, long ending_hairpin)
{
    if (!ch->firstnote) {
        erase_chord_dynamics(r_ob, ch, slot_num, add_undo_tick);
        return NULL;
    }
    
    if (add_undo_tick)
        create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
    
    // Erasing existing dynamics
    erase_chord_dynamics(r_ob, ch, slot_num, false);
    
    
    // Computing mean velocity
    double mean_vel = 0;
    long count = 0;
    for (t_note *nt = ch->firstnote; nt; nt = nt->next, count++)
        mean_vel += nt->velocity;
    mean_vel /= count;
    
    // Converting mean velocity to dynamics
    t_symbol *dyn = NULL, *dyn_without_hairpin = NULL;
    if (!velocity_to_dynamics(r_ob, mean_vel, &dyn, dyn_vel_associations, params)) {
        dyn_without_hairpin = dyn;
        if (ending_hairpin)
            dyn = dynamics_add_ending_hairpin(dyn, ending_hairpin);
        
        t_notation_item *nitem = notation_item_get_to_which_dynamics_should_be_assigned(r_ob, (t_notation_item *)ch);
        t_llll *slot_ll = dynamic_mark_to_slots_ll(slot_num, dyn);
        set_slots_values_to_notationitem_from_llll(r_ob, nitem, slot_ll);
        llll_free(slot_ll);
    } else {
        object_warn((t_object *)r_ob, "Could not convert mean chord velocity '%.2f' to dynamic marking.", mean_vel);
    }
    
    return dyn;
}

double chord_get_average_velocity(t_chord *ch)
{
    long count = 0;
    double avg_vel = 0;
    for (t_note *nt = ch->firstnote; nt; nt = nt->next, count++)
        avg_vel += nt->velocity;
    if (count == 0)
        return 0;
    else
        return avg_vel / count;
}

long notationobj_velocities2dynamics(t_notation_obj *r_ob, long slot_num, t_llll *dyn_vel_associations, char selection_only, long dynamics_spectrum_halfwidth, double a_exp, char delete_unnecessary, double approx_thresh)
{
    t_dynamics_params params;
    params.a = a_exp;
    params.dynamics_spectrum_halfwidth = dynamics_spectrum_halfwidth;
    dynamics_compute_b(&params);
    
    lock_general_mutex(r_ob);
    
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
        t_llll *ll = llll_get();
        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ch = chord_get_next(ch)) {
            
            if (chord_is_all_tied_from(ch, false))
                continue;
            
            if (selection_only && !notation_item_is_globally_selected(r_ob, (t_notation_item *)ch))
                continue;
            
            erase_chord_dynamics(r_ob, ch, slot_num, true);
            
            if (ch->firstnote) {
                t_llll *sub_ll = double_triplet_to_llll(notation_item_get_onset_ms(r_ob, (t_notation_item *)ch), chord_get_average_velocity(ch), 0.);
                sub_ll->l_thing.w_obj = ch; // keeping chord information in the l_thing field
                llll_appendllll(ll, sub_ll);
            }
        }
        
        // 1. inferring hairpins
        t_llll *pivot_chords_ll = ll;
        char must_free_pivot_chords_ll = false;
        if (approx_thresh > 0) {
            pivot_chords_ll = llll_approximate_breakpoint_function(ll, 0, approx_thresh, 2, 1, false, true, (t_object *)r_ob);
            must_free_pivot_chords_ll = true;
        }
        
        
        // 2. assigning dynamics
        for (t_llllelem *elem = pivot_chords_ll->l_head; elem; elem = elem->l_next) {
            t_chord *ch = (t_chord *)(hatom_getllll(&elem->l_hatom)->l_thing.w_obj);
            double ch_slope = elem->l_thing.w_double;
            long hairpin = (ch_slope > 0 ? 1 : (ch_slope < 0 ? -1 : 0));
            t_chord *next_ch = (elem->l_next ? (t_chord *)(hatom_getllll(&elem->l_next->l_hatom)->l_thing.w_obj) : NULL);
            
            //            post("Chord No. %ld, slope: %.2f, hairpin: %ld, next chord No. %ld", notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)ch), ch_slope, hairpin, next_ch ? notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)next_ch) : -1);
            
            // no hairpin between consecutive chords!
            if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
                t_chord *last_tied = chord_get_last_in_tieseq(ch);
                for (t_chord *tmp = ch; tmp; tmp = chord_get_next(tmp)) {
                    if (tmp == next_ch) {
                        hairpin = 0;
                        break;
                    }
                    if (tmp == last_tied)
                        break;
                }
                if (chord_get_next(last_tied) == next_ch)
                    hairpin = 0;
            } else if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL && ch->next == next_ch)
                hairpin = 0;
            
            //            post("– Chord No. %ld, slope: %.2f, hairpin: %ld", notation_item_get_index_for_lexpr(r_ob, (t_notation_item *)ch), ch_slope, hairpin);
            
            assign_chord_dynamics_from_velocities(r_ob, ch, slot_num, dyn_vel_associations, &params, true, hairpin);
        }
        
        if (must_free_pivot_chords_ll)
            llll_free(pivot_chords_ll);
        
        llll_free(ll);
    }
    
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice))
        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ch = chord_get_next(ch))
            assign_chord_dynamics(r_ob, ch, NULL, NULL);
    unlock_general_mutex(r_ob);
    
    
    // 3. deleting unnecessary dynamics
    notationobj_check_dynamics(r_ob, slot_num, true, delete_unnecessary, true, delete_unnecessary, selection_only, false);
    
    lock_general_mutex(r_ob);
    check_slot_linkage_recomputations_for_everything(r_ob, slot_num);
    unlock_general_mutex(r_ob);
    
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    handle_change_if_there_are_free_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_ASSIGN_DYNAMICS);
    
    return 0;
}






t_notation_item *notation_item_get_bearing_dynamics(t_notation_obj *r_ob, t_notation_item *nitem, long dynamics_slot_num)
{
    if (!nitem)
        return NULL;
    
    switch (nitem->type) {
        case k_CHORD:
            if (!((t_chord *)nitem)->firstnote)
                return nitem;
            
            for (t_note *temp = ((t_chord *)nitem)->firstnote; temp; temp = temp->next)
                if (notation_item_get_slot_firstitem(r_ob, (t_notation_item *)temp, dynamics_slot_num))
                    return (t_notation_item *)temp;
            
            return NULL;
            break;
            
        case k_NOTE:
            return notation_item_get_bearing_dynamics(r_ob, (t_notation_item *)((t_note *)nitem)->parent, dynamics_slot_num);
            break;
            
        default:
            return NULL;
            break;
    }
}

t_notation_item *notation_item_get_to_which_dynamics_should_be_assigned(t_notation_obj *r_ob, t_notation_item *nitem)
{
    if (!nitem)
        return NULL;
    
    switch (nitem->type) {
        case k_CHORD:
            if (!((t_chord *)nitem)->firstnote)
                return nitem;
            return (t_notation_item *)((t_chord *)nitem)->firstnote;
            break;
            
        case k_NOTE:
            return notation_item_get_to_which_dynamics_should_be_assigned(r_ob, (t_notation_item *)((t_note *)nitem)->parent);
            break;
            
        default:
            return NULL;
            break;
    }
}

