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
        t_dynamics_mark *newtemp = build_dynamics_mark();
        *newtemp = *temp;
        
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
    if (strcmp(buf, "_") == 0 || strcmp(buf, "") == 0)
        return k_DYNAMICS_HAIRPIN_NONE;
    
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

        case k_DYNAMICS_HAIRPIN_NONE:
        default:
            return gensym("_");
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
            llll_appendsym(posll, positioning_mode_value_to_symbol(mark->positioning_mode));
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
        llll_appendsym(markll, mark->text_deparsed);
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
        switch (mark->positioning_mode) {
            case k_DYNAMICS_POSITIONING_AUTO:
                llll_appendsym(markll, _llllobj_sym_auto);
                break;
                
            case k_DYNAMICS_POSITIONING_MANUAL:
                llll_appenddouble(markll, mark->relative_position);
                break;

            case k_DYNAMICS_POSITIONING_SNAPTOBPT:
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

        llll_appendsym(markll, mark->text_deparsed);
        llll_appendsym(markll, hairpin_value_to_symbol(mark->hairpin_to_next));
        llll_appendllll(res, markll);
    }
    return res;
}

t_llll *dynamics_to_llll_plain(t_notation_obj *r_ob, t_dynamics *dyn)
{
    t_llll *res = llll_get();
    for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next) {
        if (mark->positioning_mode == k_DYNAMICS_POSITIONING_MANUAL)
            llll_appenddouble(res, mark->relative_position);
        else if (mark->positioning_mode == k_DYNAMICS_POSITIONING_SNAPTOBPT) {
            char temp[512];
            snprintf_zero(temp, 512, "@%ld", mark->snap_to_breakpoint);
            llll_appendsym(res, gensym(temp));
        }
        llll_appendsym(res, mark->text_deparsed);
        
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

char positioning_mode_symbol_to_value(t_symbol *s)
{
    if (s == _llllobj_sym_auto || s == _llllobj_sym_Auto)
        return k_DYNAMICS_POSITIONING_AUTO;
    if (s == gensym("manual"))
        return k_DYNAMICS_POSITIONING_MANUAL;
    if (s == _llllobj_sym_breakpoint || s == _llllobj_sym_breakpoints)
        return k_DYNAMICS_POSITIONING_SNAPTOBPT;
    return k_DYNAMICS_POSITIONING_AUTO;
}

t_symbol *positioning_mode_value_to_symbol(char val)
{
    switch (val) {
        case k_DYNAMICS_POSITIONING_MANUAL:
            return gensym("manual");
            break;
        case k_DYNAMICS_POSITIONING_SNAPTOBPT:
            return _llllobj_sym_breakpoint;
            break;
            
        default:
            return _llllobj_sym_auto;
            break;
    }
}

t_dynamics *dynamics_from_llll(t_notation_obj *r_ob, t_notation_item *owner, t_llll *ll)
{
    t_dynamics *dyn = NULL;
    if (ll->l_depth > 1) {
        // it's a sequence of  [[#breakpointdiattachment relativeposition] dynamicmark hairpintype]...
        dyn = build_dynamics(owner);
        long i = 0, num_marks = ll->l_size;
        long last_snapped_breakpoint = 0;
        for (t_llllelem *el = ll->l_head; el; el = el->l_next, i++) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *subll = hatom_getllll(&el->l_hatom);
                
                char positioning_mode = k_DYNAMICS_POSITIONING_AUTO;
                long snaptobreakpoint = 0;
                double relativeposition = 0.;
                if (subll->l_size >= 1) {
                    if (hatom_gettype(&subll->l_head->l_hatom) == H_LLLL) {
                        t_llll *point = hatom_getllll(&subll->l_head->l_hatom);
                        t_llllelem *point_el = point ? point->l_head : NULL;
                        positioning_mode = k_DYNAMICS_POSITIONING_SNAPTOBPT;
                        if (point_el && hatom_gettype(&point_el->l_hatom) == H_SYM) {
                            positioning_mode = positioning_mode_symbol_to_value(hatom_getsym(&point_el->l_hatom));
                            point_el = point_el->l_next;
                        }
                        if (positioning_mode == k_DYNAMICS_POSITIONING_AUTO) {
                            relativeposition = (num_marks == 1 ? 0 : ((double)i)/(num_marks - 1));
                        } else if (positioning_mode == k_DYNAMICS_POSITIONING_SNAPTOBPT) {
                            if (point_el)
                                snaptobreakpoint = last_snapped_breakpoint = hatom_getlong(&point_el->l_hatom);
                        } else if (positioning_mode == k_DYNAMICS_POSITIONING_MANUAL) {
                            if (point_el && point_el->l_next) {
                                relativeposition = hatom_getdouble(&point_el->l_next->l_hatom);
                            } else {
                                relativeposition = (num_marks == 1 ? 0 : ((double)i)/(num_marks - 1));
                            }
                        }
                    } else {
                        if (hatom_gettype(&subll->l_head->l_hatom) == H_SYM) {
                            positioning_mode = positioning_mode_symbol_to_value(hatom_getsym(&subll->l_head->l_hatom));
                            if (positioning_mode == k_DYNAMICS_POSITIONING_SNAPTOBPT) {
                                snaptobreakpoint = (++last_snapped_breakpoint);
                            } else if (positioning_mode == k_DYNAMICS_POSITIONING_AUTO) {
                                relativeposition = (num_marks == 1 ? 0 : ((double)i)/(num_marks - 1));
                            }
                        } else {
                            positioning_mode = k_DYNAMICS_POSITIONING_MANUAL;
                            relativeposition = hatom_getdouble(&subll->l_head->l_hatom);
                        }
                    }
                }
                t_symbol *mark_sym = subll->l_size >= 2 ? hatom_getsym(&subll->l_head->l_next->l_hatom) : NULL;
                long hairpintype = subll->l_size >= 3 ? (hatom_gettype(&subll->l_head->l_next->l_next->l_hatom) == H_SYM ? hairpin_symbol_to_value(hatom_getsym(&subll->l_head->l_next->l_next->l_hatom)) : hatom_getlong(&subll->l_head->l_next->l_next->l_hatom)) : k_DYNAMICS_HAIRPIN_NONE;
                
                if (mark_sym) {
                    t_dynamics_mark *mark = build_dynamics_mark();
                    dynamics_parse_string_to_energy(r_ob, mark_sym->s_name, &mark->start_energy, &mark->end_energy);
                    mark->text_typographic = dynamics_mark_parse_string_to_typographic_text(r_ob, mark_sym->s_name);
                    mark->text_deparsed = mark_sym;
                    mark->hairpin_to_next = hairpintype;
                    mark->snap_to_breakpoint = snaptobreakpoint;
                    mark->relative_position = relativeposition;
                    mark->positioning_mode = positioning_mode;
                    dynamics_mark_append(dyn, mark);
                }
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


void paint_dynamics_from_slot(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *color, t_notation_item *item,
                              double center_x, double duration_x, long slot, t_jfont *jf_dynamics, double font_size, double y_position,
                              double *curr_hairpin_start_x, long *curr_hairpin_type, char boxed)
{
    t_slotitem *firstitem = notation_item_get_slot_firstitem(r_ob, item, slot);
    if (firstitem && (t_symbol *)firstitem->item){
        t_dynamics *dyn = (t_dynamics *)firstitem->item;
        if (dyn && dyn->firstmark)
            paint_dynamics(r_ob, g, color, item, center_x, duration_x, dyn, jf_dynamics, font_size, y_position, curr_hairpin_start_x, curr_hairpin_type, NULL, NULL, boxed);
    }
}

char dynamics_mark_is_zero(t_dynamics_mark *dynsign)
{
    if (dynsign && dynsign->text_typographic && strcmp(dynsign->text_typographic->s_name, "o") == 0)
        return true;
    return false;
}


// use item == NULL to only finish an hairpin
void paint_dynamics(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *color, t_notation_item *item,
                    double center_x, double duration_x, t_dynamics *dyn, t_jfont *jf_dynamics, double font_size, double y_position,
                    double *curr_hairpin_start_x, long *curr_hairpin_type, t_jrgba *prev_hairpin_color, char *prev_hairpin_dont_paint, char inside_slot_window)
{
    char boxed = inside_slot_window;
    double xpos = center_x, ypos = y_position;
    double h = -1, w = -1;
    //    double font_size = jfont_get_font_size(jf_dynamics);
    const double HAIRPIN_PAD = 0.11 * font_size;
    const double HAIRPIN_SEMIAPERTURE =  0.175 * font_size;
    const double ZEROCIRCLE_RADIUS = 0.1 * font_size;
    t_chord *curr_ch = item ? notation_item_get_parent_chord(r_ob, item) : NULL;
    char dont_paint = (curr_ch && r_ob->is_editing_type == k_DYNAMICS && r_ob->is_editing_chord == curr_ch);
    
    if (!item) {
        // only finish the hairpin
        if ((r_ob->show_hairpins || boxed) && curr_hairpin_type && *curr_hairpin_type && curr_hairpin_start_x) {
            if (h < 0 && w < 0)
                h = w = 0;
            //                jfont_text_measure(jf_dynamics, dyntext, &w, &h);
            if (!(prev_hairpin_dont_paint && *prev_hairpin_dont_paint) && xpos - w/2. - HAIRPIN_PAD > *curr_hairpin_start_x)
                paint_hairpin(g, prev_hairpin_color ? *prev_hairpin_color : r_ob->j_dynamics_rgba, *curr_hairpin_type, *curr_hairpin_start_x, xpos - w/2. - HAIRPIN_PAD, ypos, HAIRPIN_SEMIAPERTURE, 1);
            *curr_hairpin_type = 0;
        }
        
        if (prev_hairpin_dont_paint)
            *prev_hairpin_dont_paint = dont_paint;
        if (prev_hairpin_color && color)
            *prev_hairpin_color = *color;
        
        return;
    }
    
    if (dyn){
        if (!boxed && dyn->lastmark) {
            double w_temp, h_temp;
            jfont_text_measure(jf_dynamics, dyn->lastmark->text_typographic->s_name, &w_temp, &h_temp);
            if (duration_x - w_temp/2. > 0)
                duration_x -= w_temp/2.;
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
                    jfont_text_measure(jf_dynamics, dyn->firstmark->text_typographic->s_name, &w, &h);
                } else {
                    w = h = 0;
                }
            }
            if (!(prev_hairpin_dont_paint && *prev_hairpin_dont_paint) && xpos - w/2. - HAIRPIN_PAD > *curr_hairpin_start_x)
                paint_hairpin(g, prev_hairpin_color ? *prev_hairpin_color : r_ob->j_dynamics_rgba, *curr_hairpin_type, *curr_hairpin_start_x, xpos - w/2. - (is_dynamic_zero ? 0 : HAIRPIN_PAD), ypos, HAIRPIN_SEMIAPERTURE, 1);
            *curr_hairpin_type = 0;
        }
        
        if (prev_hairpin_dont_paint)
            *prev_hairpin_dont_paint = dont_paint;
        if (prev_hairpin_color && color)
            *prev_hairpin_color = *color;
        
        double prev_end_xpos = 0;
        t_bpt *bpt = NULL;
        double y_adj_for_dynamics = - 0.93 * font_size;
        for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next) {
            char align = 0;
            char is_dynamic_zero = false;
            
            //            xpos = center_x + (num_dynamics <= 1 ? 0 : i * (duration_x/(open_hairpin ? num_dynamics : num_dynamics - 1)));
            // xpos = center_x + (dyn->num_marks <= 1 ? 0 : i * (duration_x/(dyn->num_marks - 1)));
            if (mark->snap_to_breakpoint) {
                t_bpt *bpt = dynamics_mark_get_breakpoint(dyn, mark);
                if (bpt)
                    xpos = center_x + bpt->rel_x_pos * duration_x;
                else
                    xpos = center_x;
            } else
                xpos = center_x + mark->relative_position * duration_x;
            
            if (r_ob->show_dynamics || boxed) {
                if (dynamics_mark_is_zero(mark)) {
                    if (!dont_paint)
                        paint_circle_stroken(g, *color, xpos, ypos, ZEROCIRCLE_RADIUS, 1);
                    is_dynamic_zero = true;
//                } else if (boxed && (!dynsign->prev || (!dynamics_get_ending_hairpin(dyn) && !dynsign->next))) {
//                    align = (dynsign== dyn->firstmark ? -1 : 1);
//                    if (!dont_paint)
//                        write_text(g, jf_dynamics, *color, dynsign->text_typographic->s_name, center_x, ypos + y_adj_for_dynamics, duration_x, ypos + 300, (dynsign == dyn->firstmark ? JGRAPHICS_TEXT_JUSTIFICATION_LEFT : JGRAPHICS_TEXT_JUSTIFICATION_RIGHT) | JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
                } else {
                    if (!dont_paint)
                        write_text(g, jf_dynamics, *color, mark->text_typographic->s_name, xpos - 200, ypos + y_adj_for_dynamics, 400, ypos + 300, JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED | JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
                }
            }
            
            if (is_dynamic_zero)
                w = h = ZEROCIRCLE_RADIUS * 2.;
            else
                jfont_text_measure(jf_dynamics, mark->text_typographic->s_name, &w, &h);
            
            // painting hairpin?
            if ((r_ob->show_hairpins || boxed) && !dont_paint && mark->prev && mark->prev->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE && prev_end_xpos < xpos - (align == 0 ? w/2. : w) - (is_dynamic_zero ? 0. : HAIRPIN_PAD))
                paint_hairpin(g, *color, mark->prev->hairpin_to_next, prev_end_xpos, xpos - (align == 0 ? w/2. : w) - (is_dynamic_zero ? 0. : HAIRPIN_PAD), ypos, HAIRPIN_SEMIAPERTURE, 1);
            
            prev_end_xpos = (align == 0 ? xpos + w/2. + (is_dynamic_zero ? 0. : HAIRPIN_PAD) : xpos + w + (is_dynamic_zero ? 0. : HAIRPIN_PAD));
            
            if (curr_hairpin_type)
                *curr_hairpin_type = mark->hairpin_to_next;
            if (curr_hairpin_start_x && mark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE) {
                *curr_hairpin_start_x = prev_end_xpos;
            }
        }
        
        if (boxed && !dont_paint && dyn->lastmark && dyn->lastmark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE && prev_end_xpos < center_x + duration_x - HAIRPIN_PAD) {
            paint_hairpin(g, *color, dyn->lastmark->hairpin_to_next, prev_end_xpos, center_x + duration_x - HAIRPIN_PAD, ypos, HAIRPIN_SEMIAPERTURE, 1);
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
                for (long i = 1; i < strlen(buf); i++)
                    if (buf[i] != 'f') {
                        if (strcmp(buf+i, "mp")) {
                            se = 101 + CLAMP(i, 0, 100);
                            ee = 100;
                        } else if (strcmp(buf+i, "mf")) {
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
                break;
                
            case 's':
            {
                long len = buf[strlen(buf) - 1] == 'z' ? strlen(buf) - 1: strlen(buf);
                for (long i = 1; i < len; i++)
                    if (buf[i] != 'f') {
                        if (strcmp(buf+i, "mp")) {
                            se = 200 + CLAMP(i, 0, 100);
                            ee = 100;
                        } else if (strcmp(buf+i, "mf")) {
                            se = 200 + CLAMP(i, 0, 100);
                            ee = 101;
                        } else if (buf[i] == 'p') {
                            for (long j = i+1; j < strlen(buf); j++) {
                                if (buf[j] != 'p')
                                    goto end;
                            }
                            se = 200 + CLAMP(i, 0, 100);
                            se = ee = 100 - CLAMP(strlen(buf) - i, 0, 100);
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
        bach_freeptr(temp);
        temp = temp2;
    }
    dyn->firstmark = dyn->lastmark = NULL;
    dyn->num_marks = 0;
}

t_dynamics_mark *build_dynamics_mark()
{
    t_dynamics_mark *ds = (t_dynamics_mark *)bach_newptr(sizeof(t_dynamics_mark));
    ds->hairpin_to_next = k_DYNAMICS_HAIRPIN_NONE;
    ds->relative_position = 0;
    ds->snap_to_breakpoint = 0;
    ds->text_typographic = NULL;
    ds->text_deparsed = NULL;
    ds->prev = ds->next = NULL;
    ds->positioning_mode = k_DYNAMICS_POSITIONING_AUTO;
    return ds;
}

t_dynamics *dynamics_from_textbuf(t_notation_obj *r_ob, t_notation_item *owner, char *buf)
{
    t_dynamics *dyn = build_dynamics(owner);
    
    char complete_deparsed_string[8192];
    long complete_deparsed_string_alloc = 8192;
    
    if (!buf || !buf[0]) {
        dyn->num_marks = 0;
        complete_deparsed_string[0] = 0;
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
            while (*b == '.' || (*b >= '0' && *b <= '9') || *b == '@' || *b == '-') // position
                b++;
            c = b;
            while (*c == ' ')
                c++;
            d = c;
            while (*d != 0 && *d != '<' && *d != '>' && *d != '_' && *d != ' ') // mark
                d++;
            e = d;
            while (*e == ' ')
                e++;
            f = e;
            while (*f == '<' || *f == '>' || *f == '_') // hairpin
                f++;
            
            sysmem_copyptr(a, position, MIN(CONST_MAX_NUM_DYNAMICS_CHARS * sizeof(char), b-a));
            position[MAX(0, MIN(CONST_MAX_NUM_DYNAMICS_CHARS - 1, b-a))] = 0;

            sysmem_copyptr(c, mark, MIN(CONST_MAX_NUM_DYNAMICS_CHARS * sizeof(char), d-c));
            mark[MAX(0, MIN(CONST_MAX_NUM_DYNAMICS_CHARS - 1, d-c))] = 0;

            // creating new sign
            t_dynamics_mark *thismark = build_dynamics_mark();
            if (!dyn->firstmark)
                dyn->firstmark = thismark;
            
            dynamics_parse_string_to_energy(r_ob, mark, &thismark->start_energy, &thismark->end_energy);
            thismark->text_deparsed = gensym(mark);
            thismark->text_typographic = dynamics_mark_parse_string_to_typographic_text(r_ob, mark);
            
            if (position[0] == '@') {
                // breakpoint attachment
                thismark->positioning_mode = k_DYNAMICS_POSITIONING_SNAPTOBPT;
                thismark->relative_position = 0.;
                if (position[1] != 0)
                    thismark->snap_to_breakpoint = last_snapped_breakpoint = atol(position+1);
                else
                    thismark->snap_to_breakpoint = (++last_snapped_breakpoint);
            } else if (position[0] != 0){
                thismark->positioning_mode = k_DYNAMICS_POSITIONING_MANUAL;
                thismark->relative_position = atof(position);
            } else {
                thismark->positioning_mode = k_DYNAMICS_POSITIONING_AUTO;
            }
            
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
        
        long cur = 0, i = 0;
        for (t_dynamics_mark *mark = dyn->firstmark; mark; mark = mark->next, i++) {
            if (mark->positioning_mode == k_DYNAMICS_POSITIONING_AUTO)
                mark->relative_position = (dyn->num_marks > 1 ? ((double)i)/(dyn->num_marks - 1) : 0.);
            
/*            if (mark != dyn->lastmark || mark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE) {
                cur += snprintf_zero(complete_deparsed_string + cur, complete_deparsed_string_alloc - cur, "%s %s", mark->text_deparsed ? mark->text_deparsed->s_name : "", hairpin_value_to_symbol(mark->hairpin_to_next)->s_name);
            } else
                cur += snprintf_zero(complete_deparsed_string + cur, complete_deparsed_string_alloc - cur, "%s", mark->text_deparsed ? mark->text_deparsed->s_name : "");
            if (mark != dyn->lastmark && cur < complete_deparsed_string_alloc - 1)
                complete_deparsed_string[cur++] = ' '; */
        }
        
/*        complete_deparsed_string[complete_deparsed_string_alloc-1] = 0;
        if (complete_deparsed_string[strlen(complete_deparsed_string)-1] == ' ')
            complete_deparsed_string[strlen(complete_deparsed_string)-1] = 0; */

    }
    
    dyn->text_deparsed = dynamics_to_symbol(r_ob, dyn);
//    dyn->text_deparsed = gensym(complete_deparsed_string);
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

void remove_first_dynamic_from_deparsed_dynamic(char *dyn_buf)
{
    char temp[CONST_MAX_NUM_DYNAMICS_CHARS * CONST_MAX_NUM_DYNAMICS_PER_CHORD];
    
    snprintf_zero(temp, CONST_MAX_NUM_DYNAMICS_CHARS * CONST_MAX_NUM_DYNAMICS_PER_CHORD, "%s", dyn_buf);
    
    char *c = temp;
    while (*c && *c != '_') {
        if (!*(c+1) || *(c+1) == '_') {
            *c = '|';
            break;
        }
        c++;
    }
    
    snprintf_zero(dyn_buf, CONST_MAX_NUM_DYNAMICS_CHARS * CONST_MAX_NUM_DYNAMICS_PER_CHORD, "%s", c);
}

t_dynamics *chord_get_dynamics(t_chord *ch)
{
    t_slot *slot = ch->dynamics_slot;
    if (slot && slot->firstitem && slot->firstitem->item)
        return (t_dynamics *)slot->firstitem->item;
    else
        return NULL;
    
}

long notationobj_check_dynamics(t_notation_obj *r_ob, long slot_num, char check_inconsistent, char check_unnecessary, char fix_inconsistent, char fix_unnecessary, char selection_only, char verbose)
{
    char path[1024];
    long i;
    long last_hairpin = 0;
    t_slotitem *last_slotitem = NULL;
    t_chord *last_chord = NULL;
    t_dynamics_mark *lastmark = NULL;
    
    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
        last_slotitem = NULL;
        last_chord = NULL;
        last_hairpin = 0;
        
        
        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ) {
            char something_fixed = false;
            t_slotitem *slotitem = NULL;
            
            if (selection_only && !notation_item_is_globally_selected(r_ob, (t_notation_item *)ch)) {
                ch = chord_get_next(ch);
                continue;
            }
            
            t_dynamics *dyn = chord_get_dynamics(ch);
            
            if (dyn && dyn->firstmark){
                long num_marks = dyn->num_marks;

                // checking dangling hairpin
                if (check_inconsistent && last_hairpin) {
                    long cmp = dynamic_mark_end_start_cmp(lastmark, dyn->firstmark);
                    if (last_hairpin * cmp <= 0) {
                        if (verbose) {
                            check_dynamics_get_path(r_ob, ch, path, 1024, num_marks > 1 ? 1 : 0);
                            object_warn((t_object *)r_ob, "Inconsistent %s found from '%s' to '%s' %s", last_hairpin > 0 ? "crescendo" : "diminuendo", lastmark->text_deparsed->s_name, dyn->firstmark->text_deparsed->s_name, path);
                        }
                        
                        if (fix_inconsistent && last_slotitem) {
                            last_hairpin = labs(last_hairpin) * cmp; // correcting the previous hairpin
                            
                            char buf[CONST_MAX_NUM_DYNAMICS_PER_CHORD * CONST_MAX_NUM_DYNAMICS_CHARS];
                            snprintf(buf, CONST_MAX_NUM_DYNAMICS_PER_CHORD * CONST_MAX_NUM_DYNAMICS_CHARS, "%s", ((t_symbol *)last_slotitem->item)->s_name);
                            long cur = strlen(buf) - 1;
                            while (cur >= 0) {
                                if (buf[cur] == '>' || buf[cur] == '<' || buf[cur] == '_')
                                    buf[cur] = (last_hairpin < 0 ? '>' : last_hairpin > 0 ? '<' : 0);
                                else
                                    break;
                                cur--;
                            }
                            create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)last_chord, k_UNDO_MODIFICATION_CHANGE);
                            last_slotitem->item = gensym(buf);
                            
                            // ... but if the corrected last_hairpin == 0, the dynamics on last_chord might have become unnecessary.
                            if (!last_hairpin) {
                                last_slotitem = NULL;
                                ch = dynamics_get_prev(r_ob, voice, slot_num, last_chord, NULL, NULL, NULL, NULL, NULL);
                                if (!ch)
                                    ch = last_chord;
                                last_chord = NULL;
                                lastmark = NULL;
                                last_hairpin = 0;
                                continue;
                            }
                        }
                    }
                }
                
                // checking unnecessary dynamics
                if (check_unnecessary) {
                    if (!last_hairpin && lastmark && dyn->firstmark->text_typographic == lastmark->text_typographic && dyn->firstmark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE) {
                        if (verbose) {
                            check_dynamics_get_path(r_ob, ch, path, 1024, num_marks > 1 ? 1 : 0);
                            object_warn((t_object *)r_ob, "Unnecessary dynamic marking found: '%s' %s", lastmark->text_deparsed->s_name, path);
                        }
                        if (fix_unnecessary) {
                            something_fixed = true;
                            create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
                            dynamics_mark_delete(dyn, dyn->firstmark);
                        }
                    }
                    
                    i = 0;
                    for (t_dynamics_mark *mark = dyn->firstmark->next; mark; mark = mark->next, i++) {
                        if (mark->prev->text_typographic == mark->text_typographic && mark->prev->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE && mark->hairpin_to_next != k_DYNAMICS_HAIRPIN_NONE) {
                            if (verbose) {
                                check_dynamics_get_path(r_ob, ch, path, 1024, num_marks > 1 ? i : 0);
                                object_warn((t_object *)r_ob, "Unnecessary dynamic marking found: '%s' %s", mark->text_deparsed->s_name, path);
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
                                object_warn((t_object *)r_ob, "Inconsistent %s found from '%s' to '%s' %s", mark->prev->hairpin_to_next > 0 ? "crescendo" : "diminuendo", mark->prev->text_deparsed->s_name, mark->text_deparsed->s_name, path);
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
            
            
            if (slotitem && something_fixed) {
                /*                // building complete string
                 char buf[CONST_MAX_NUM_DYNAMICS_PER_CHORD * CONST_MAX_NUM_DYNAMICS_CHARS];
                 reassemble_dynamics_buf(r_ob, num_dynamics, dyn_text_dep, hairpins, buf, CONST_MAX_NUM_DYNAMICS_PER_CHORD * CONST_MAX_NUM_DYNAMICS_CHARS);
                 create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
                 if (num_dynamics <= 0) {
                 slotitem_delete(r_ob, slot_num, slotitem);
                 slotitem = NULL;
                 } else
                 slotitem->item = gensym(buf); */
                
                dyn->text_deparsed = dynamics_to_symbol(r_ob, dyn);
            }
            
            if (slotitem) {
                last_slotitem = slotitem;
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




t_symbol *dynamics_get_longest(char c, t_dynamics_params *params)
{
    long D = params->dynamics_spectrum_halfwidth;
    char buf[129];
    long i;
    for (i = 0; i < 128 && i < D - 1; i++)
        buf[i] = c;
    buf[i] = 0;
    return gensym(buf);
}


// parse "mpfffpppp" -> "mp" and "pppp"
void parse_composed_dynamics(t_symbol *dyn, t_symbol **firstdyn, t_symbol **lastdyn, t_symbol **std_firstdyn, t_symbol **std_lastdyn, t_dynamics_params *params)
{
    char buf[CONST_MAX_NUM_DYNAMICS_CHARS];
    long len = strlen(dyn->s_name);
    long D = params->dynamics_spectrum_halfwidth;
    
    if (!strncmp(dyn->s_name, "mp", 2)) {
        *firstdyn = *std_firstdyn = gensym("mp");
    } else if (!strncmp(dyn->s_name, "mf", 2)) {
        *firstdyn = *std_firstdyn = gensym("mf");
    } else if (!strncmp(dyn->s_name, "sf", 2)) {
        snprintf_zero(buf, CONST_MAX_NUM_DYNAMICS_CHARS, "%s", dyn->s_name);
        char *cur = buf + 2;
        char entered = false;
        while (*cur == 'f') {
            cur++;
            entered = true;
        }
        if (*cur == 'z') {
            *std_firstdyn = entered ? gensym("sffz") : gensym("sfz");
            cur++;
        } else {
            *std_firstdyn = entered ? gensym("sff") : gensym("sf");
        }
        *cur = 0;
        *firstdyn = gensym(buf);
    } else if (!strncmp(dyn->s_name, "n", 1)) {
        *firstdyn = *std_firstdyn = gensym("n");
    } else if (!strncmp(dyn->s_name, "0", 1)) {
        *firstdyn = *std_firstdyn = gensym("0");
    } else if (!strncmp(dyn->s_name, "p", 1)) {
        snprintf_zero(buf, CONST_MAX_NUM_DYNAMICS_CHARS, "%s", dyn->s_name);
        char *cur = buf + 1;
        while (*cur == 'p') cur++;
        *cur = 0;
        *firstdyn = gensym(buf);
        *std_firstdyn = (strlen(buf) <= D - 1) ? *firstdyn : dynamics_get_longest('p', params);
    } else if (!strncmp(dyn->s_name, "f", 1)) {
        snprintf_zero(buf, CONST_MAX_NUM_DYNAMICS_CHARS, "%s", dyn->s_name);
        char *cur = buf + 1;
        while (*cur == 'f') cur++;
        *cur = 0;
        *firstdyn = gensym(buf);
        *std_firstdyn = (strlen(buf) <= D - 1) ? *firstdyn : dynamics_get_longest('f', params);
    }
    
    if (!strncmp(dyn->s_name + len - 2, "mp", 2)) {
        *lastdyn = *std_lastdyn = gensym("mp");
    } else if (!strncmp(dyn->s_name + len - 2, "mf", 2)) {
        *lastdyn = *std_lastdyn = gensym("mf");
    } else if (!strncmp(dyn->s_name + len - 1, "n", 1)) {
        *lastdyn = *std_lastdyn = gensym("n");
    } else if (!strncmp(dyn->s_name + len - 1, "0", 1)) {
        *lastdyn = *std_lastdyn = gensym("0");
    } else if (!strncmp(dyn->s_name + len - 1, "p", 1)) {
        snprintf_zero(buf, CONST_MAX_NUM_DYNAMICS_CHARS, "%s", dyn->s_name);
        char *cur = buf  + len - 2;
        while (*cur == 'p') cur--;
        *lastdyn = gensym(++cur);
        *std_lastdyn = (strlen(buf) <= D - 1) ? *firstdyn : dynamics_get_longest('p', params);
    } else if (!strncmp(dyn->s_name, "f", 1)) {
        snprintf_zero(buf, CONST_MAX_NUM_DYNAMICS_CHARS, "%s", dyn->s_name);
        char *cur = buf  + len - 2;
        while (*cur == 'f') cur--;
        *lastdyn = gensym(++cur);
        *std_lastdyn = (strlen(buf) <= D - 1) ? *firstdyn : dynamics_get_longest('f', params);
    } else {
        *lastdyn = *firstdyn;
        *std_lastdyn = *std_firstdyn;
    }
}

/*
 char dynamics_to_velocity_simple(t_symbol *dyn, double *vel)
 {
 if (!dyn)
 return 1;
 
 // If not found, go with defaults
 if (dyn == gensym("pppppp")) { *vel = 1; return 0; }
 if (dyn == gensym("ppppp")) { *vel = 5; return 0; }
 if (dyn == gensym("pppp")) { *vel = 10; return 0; }
 if (dyn == gensym("ppp")) { *vel = 20; return 0; }
 if (dyn == gensym("pp")) { *vel = 35; return 0; }
 if (dyn == gensym("p")) { *vel = 49; return 0; }
 if (dyn == gensym("mp")) { *vel = 64; return 0; }
 if (dyn == gensym("mf")) { *vel = 80; return 0; }
 if (dyn == gensym("f")) { *vel = 96; return 0; }
 if (dyn == gensym("ff")) { *vel = 110; return 0; }
 if (dyn == gensym("fff")) { *vel = 118; return 0; }
 if (dyn == gensym("ffff")) { *vel = 124; return 0; }
 if (dyn == gensym("fffff")) { *vel = 126; return 0; }
 if (dyn == gensym("ffffff")) { *vel = 127; return 0; }
 if (dyn == gensym("n") || dyn == gensym("o") || dyn == gensym("O") || dyn == gensym("0")) { *vel = 0; return 0; }
 
 if (dyn == gensym("sfz")) { *vel = 115; return 0; }
 if (dyn == gensym("sffz")) { *vel = 127; return 0; }
 if (dyn == gensym("fz")) { *vel = 115; return 0; }
 if (dyn == gensym("ffz")) { *vel = 127; return 0; }
 if (dyn == gensym("sf")) { *vel = 115; return 0; }
 
 return 1;
 }
 */

// 1-based index of the dynamics inside the dynamics spectrum of half width <dynamics_spectrum_halfwidth>
long dynamics_to_spectrum_index(t_symbol *dyn, long dynamics_spectrum_halfwidth)
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

char dynamics_to_velocity_builtin(t_symbol *dyn, double *vel, t_dynamics_params *params)
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
    
    
    if (!dyn)
        return 1;
    
    if (dyn == gensym("0")) { *vel = 0; return 0; }
    if (dyn == gensym("sfz")) { *vel = 127; return 0; }
    if (dyn == gensym("sffz")) { *vel = 127; return 0; }
    if (dyn == gensym("fz")) { *vel = 127; return 0; }
    if (dyn == gensym("ffz")) { *vel = 127; return 0; }
    if (dyn == gensym("sf")) { *vel = 127; return 0; }
    
    long D = params->dynamics_spectrum_halfwidth;
    long index = dynamics_to_spectrum_index(dyn, D);
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


char dynamics_to_velocity_once(t_notation_obj *r_ob, t_symbol *dyn, double *vel, t_llll *dyn_vel_associations, t_dynamics_params *params, char usage_alignment)
{
    if (!dyn)
        return 1;
    
    if (dyn_vel_associations) {
        for (t_llllelem *el = dyn_vel_associations->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                if (ll && ll->l_size >= 2 && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && is_hatom_number(&ll->l_head->l_next->l_hatom) &&
                    hatom_getsym(&ll->l_head->l_hatom) == dyn) {
                    if (usage_alignment > 0 && ll->l_size >= 3 && is_hatom_number(&ll->l_head->l_next->l_next->l_hatom))
                        *vel = hatom_getdouble(&ll->l_head->l_next->l_next->l_hatom);
                    else
                        *vel = hatom_getdouble(&ll->l_head->l_next->l_hatom);
                    return 0;
                }
            }
        }
    }
    
    // If not found, go with defaults
    if (!dynamics_to_velocity_builtin(dyn, vel, params))
        return 0;
    
    return 1;
}

// returns 0 if OK, 1 otherwise
char dynamics_to_velocity(t_notation_obj *r_ob, t_symbol *dyn, double *vel, t_llll *dyn_vel_associations, t_dynamics_params *params, char usage_alignment)
{
    
    if (!dynamics_to_velocity_once(r_ob, dyn, vel, dyn_vel_associations, params, usage_alignment)) {
        CLIP_ASSIGN(*vel, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
        return 0;
    }
    
    // re parsing composed dyn, such as "ffpppp"
    t_symbol *firstdyn = NULL, *lastdyn = NULL, *stdfirstdyn = NULL, *stdlastdyn = NULL;
    parse_composed_dynamics(dyn, &firstdyn, &lastdyn, &stdfirstdyn, &stdlastdyn, params);
    
    if (!dynamics_to_velocity_once(r_ob, usage_alignment <= 0 ? stdfirstdyn : stdlastdyn, vel, dyn_vel_associations, params, usage_alignment)) {
        CLIP_ASSIGN(*vel, CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
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
    
    // re parsing composed dyn, such as "ffpppp"
    t_symbol *firstdyn = NULL, *lastdyn = NULL, *stdfirstdyn = NULL, *stdlastdyn = NULL;
    parse_composed_dynamics(dyn, &firstdyn, &lastdyn, &stdfirstdyn, &stdlastdyn, params);
    
    dyn = (usage_alignment <= 0 ? stdfirstdyn : stdlastdyn);
    
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
    if (dyn && dyn->firstmark)
        return dyn->firstmark->text_deparsed;
    return NULL;
}


// bptmode = 0: don't add/delete breakpoints
// bptmode = 1: add breakpoints to match dynamics
// bptmode = 2: also delete existing breakpoints before adding new ones
void chord_assign_velocities_from_dynamics(t_notation_obj *r_ob, t_chord *ch, t_llll *dyn_vel_associations, t_dynamics_params *params,
                                           t_chord *left_dyns_chord, long num_left_dyns, t_symbol **left_dyns,
                                           long *hairpins, t_symbol *right_dyn, double left_onset, double right_onset,
                                           char add_undo_tick, char bptmode, long slot_num)
{
    double velocity = 0;
    double left_velocity = 0, right_velocity = 0;
    const double DYNAMICS_TO_VELOCITY_EXP_SLOPE = 0.6;
    
    if (num_left_dyns > 0) {
        double ch_onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)ch);
        
        if (ch != left_dyns_chord && num_left_dyns > 1)
            left_onset += chord_get_max_duration(r_ob, ch);
        
        if (add_undo_tick)
            create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
        
        long last_hairpin = hairpins[num_left_dyns - 1];
        
        if (ch == left_dyns_chord) {
            // sticky assignment of the left dynamics to the chord
            if (!dynamics_to_velocity(r_ob, left_dyns[0], &velocity, dyn_vel_associations, params, -1)) {
                for (t_note *nt = ch->firstnote; nt; nt = nt->next) {
                    nt->velocity = velocity;
                    if (r_ob->breakpoints_have_velocity) {
                        
                        if (bptmode >= 2)
                            note_delete_breakpoints(r_ob, nt);
                        
                        if (bptmode >= 1 && num_left_dyns > 2) {
                            // possibly creating internal breakpoints when dynamics are more than 2 for a single note
                            // First dynamics will correspond to notehead, last dynamics will correspond to note tail
                            for (long i = 1; i < num_left_dyns - 1; i++) {
                                double relative_bpt_position = (((double)i)/(num_left_dyns - 1));
                                // check whether there's a breakpoint around here (with threshold 1 ms)
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
                        
                        
                        for (t_bpt *bpt = nt->firstbreakpoint; bpt; bpt = bpt->next) {
                            if (!bpt->prev || (num_left_dyns == 1 && last_hairpin == 0))
                                bpt->velocity = velocity;
                            
                            else if (num_left_dyns == 1 && last_hairpin != 0) {
                                // we have a starting dynamics, then a hairpin ending to some other future chord (e.g. "ff>")
                                // gotta find that "future chord"
                                t_chord *nextchwithdyn = chord_get_next_with_dynamics(r_ob, ch, NULL, false, false);
                                if (nextchwithdyn) {
                                    // get first dynamics
                                    t_symbol *right_dyn = chord_get_first_dynamic_marking_as_symbol(r_ob, nextchwithdyn, slot_num);
                                    if (right_dyn) {
                                        if (!dynamics_to_velocity(r_ob, left_dyns[0], &left_velocity, dyn_vel_associations, params, 1)) {
                                            if (!dynamics_to_velocity(r_ob, right_dyn, &right_velocity, dyn_vel_associations, params, -1)) {
                                                bpt->velocity = rescale_with_slope_inv(notation_item_get_onset_ms(r_ob, (t_notation_item *)bpt), notation_item_get_onset_ms(r_ob, (t_notation_item *)nt), notation_item_get_onset_ms(r_ob, (t_notation_item *)nextchwithdyn), left_velocity, right_velocity, last_hairpin > 1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : (last_hairpin < -1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : 0.));
                                            } else
                                                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", right_dyn->s_name);
                                        } else
                                            object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", left_dyns[0]->s_name);
                                    } else {
                                        bpt->velocity = velocity;
                                    }
                                } else {
                                    bpt->velocity = velocity;
                                }
                                
                            } else {
                                // choosing
                                double idx_dyn = CLAMP(bpt->rel_x_pos*(num_left_dyns - 1), 0, num_left_dyns - 1);
                                long idx1 = CLAMP(floor(idx_dyn), 0, num_left_dyns - 1);
                                long idx2 = CLAMP(idx1 + 1, 0, num_left_dyns - 1);
                                if (idx1 == idx2 || !hairpins[idx1]) {
                                    if (!dynamics_to_velocity(r_ob, left_dyns[idx1], &left_velocity, dyn_vel_associations, params, 1)) {
                                        bpt->velocity = left_velocity;
                                    } else
                                        object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", left_dyns[idx1]->s_name);
                                    
                                } else {
                                    if (!dynamics_to_velocity(r_ob, left_dyns[idx1], &left_velocity, dyn_vel_associations, params, 1)) {
                                        if (!dynamics_to_velocity(r_ob, left_dyns[idx2], &right_velocity, dyn_vel_associations, params, -1)) {
                                            bpt->velocity = rescale_with_slope_inv(CLAMP(idx_dyn - idx1, 0., 1.), 0., 1., left_velocity, right_velocity, hairpins[idx1] > 1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : (hairpins[idx1] < -1 ? DYNAMICS_TO_VELOCITY_EXP_SLOPE : 0.));
                                        } else
                                            object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", left_dyns[idx2]->s_name);
                                    } else
                                        object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", left_dyns[idx1]->s_name);
                                }
                            }
                        }
                    }
                }
            } else
                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping all chord markings.", left_dyns[0]->s_name);
            
            
            
        } else if (right_dyn && last_hairpin) {
            // if there's a crescendo/diminuendo, interpolate
            if (!dynamics_to_velocity(r_ob, left_dyns[num_left_dyns - 1], &left_velocity, dyn_vel_associations, params,  -1)) {
                if (!dynamics_to_velocity(r_ob, right_dyn, &right_velocity, dyn_vel_associations, params, 1)) {
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
                    } else
                        object_warn((t_object *)r_ob, "Incoherent hairpin found between dynamics '%s' and '%s'. Skipping assignments.", left_dyns[num_left_dyns - 1]->s_name, right_dyn->s_name);
                } else
                    object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", right_dyn->s_name);
            } else
                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", left_dyns[num_left_dyns - 1]->s_name);
            
        } else if (left_dyns[num_left_dyns - 1]) {
            t_symbol *dyn = left_dyns[num_left_dyns - 1];
            if (!dynamics_to_velocity(r_ob, dyn, &velocity, dyn_vel_associations, params, 1)) {
                for (t_note *nt = ch->firstnote; nt; nt = nt->next) {
                    nt->velocity = velocity;
                    if (r_ob->breakpoints_have_velocity) {
                        for (t_bpt *bpt = nt->firstbreakpoint; bpt; bpt = bpt->next)
                            bpt->velocity = velocity;
                    }
                }
            } else
                object_warn((t_object *)r_ob, "Could not find velocity assignment for dynamics '%s'. Skipping dynamic marking.", dyn->s_name);
        }
    } else {
        // nothing to do, but we should never be here
    }
}

long notationobj_dynamics2velocities(t_notation_obj *r_ob, long slot_num, t_llll *dyn_vel_associations, char selection_only, long dynamics_spectrum_halfwidth, double a_exp, char bptmode)
{
    t_symbol *curr_dyn_sym[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
    t_symbol *next_dyn_sym[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
    t_symbol *prev_last_dyn_sym = NULL;
    long curr_hairpins[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
    long next_hairpins[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
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
        
        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ch = chord_get_next(ch)) {
            if (ch == next_dyn_chord) {
                //                if (next_num_dynamics > 0 && !is_dynamics_local(r_ob, dyn_vel_associations, next_dyn_sym[next_num_dynamics-1], 1)) {
                prev_last_dyn_sym = curr_num_dynamics > 0 ? curr_dyn_sym[curr_num_dynamics-1] : NULL;
                curr_dyn_chord = next_dyn_chord;
                curr_dyn_onset = next_dyn_onset;
                curr_num_dynamics = next_num_dynamics;
                curr_open_hairpin = next_open_hairpin;
                bach_copyptr(next_hairpins, curr_hairpins, CONST_MAX_NUM_DYNAMICS_PER_CHORD * sizeof(long));
                bach_copyptr(next_dyn_sym, curr_dyn_sym, CONST_MAX_NUM_DYNAMICS_PER_CHORD * sizeof(t_symbol *));
                next_dyn_chord = dynamics_get_next(r_ob, voice, slot_num, next_dyn_chord, &next_dyn_onset);
                if (curr_num_dynamics > 0 && curr_dyn_sym[0] == _llllobj_sym_empty_symbol && prev_last_dyn_sym && prev_last_dyn_sym != _llllobj_sym_empty_symbol) {
                    // this deals with the case of no initial dynamics in a chord-assigned marking, e.g. just "<" or "<ff>p",
                    // which means that the initial dynamics of the crescendo/diminuendo must be the last used one (if any)
                    curr_dyn_sym[0] = prev_last_dyn_sym;
                }
                
                //                }
            }
            
            if (selection_only && !notation_item_is_globally_selected(r_ob, (t_notation_item *)ch))
                continue;
            
            chord_assign_velocities_from_dynamics(r_ob, ch, dyn_vel_associations, &params, curr_dyn_chord, curr_num_dynamics, curr_dyn_sym, curr_hairpins, next_dyn_chord && (next_num_dynamics > 0) ? next_dyn_sym[0] : NULL, curr_dyn_onset, next_dyn_onset, true, bptmode, slot_num);
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

