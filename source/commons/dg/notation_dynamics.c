/**
	notation_dynamicsommons.c - function handling dynamics

	by Daniele Ghisi
*/

#include "bach.h"
#include "notation.h" // header with all the structures for the notation objects



t_chord *dynamics_get_next(t_notation_obj *r_ob, t_voice *voice, long slot_num, t_chord *curr_ch, long *num_dynamics, t_symbol **dynamics, long *hairpins, char *open_hairpin, double *onset)
{
    char dyn_text[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
    t_slotitem *slotitem = NULL;
    for (t_chord *ch = curr_ch ? chord_get_next(curr_ch) : chord_get_first(r_ob, voice); ch; ch = chord_get_next(ch)) {
        if (chord_parse_dynamics(r_ob, ch, slot_num, dyn_text, hairpins, num_dynamics, open_hairpin, &slotitem)) {
            for (long i = 0; i < *num_dynamics; i++) {
                char this_dyn_text_dep[CONST_MAX_NUM_DYNAMICS_CHARS];
                deparse_dynamics_to_string_once(r_ob, dyn_text[i], this_dyn_text_dep);
                dynamics[i] = gensym(this_dyn_text_dep);
            }
            *onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)ch);
            return ch;
        }
    }
    
    return NULL;
    
}

t_chord *dynamics_get_prev(t_notation_obj *r_ob, t_voice *voice, long slot_num, t_chord *curr_ch, long *num_dynamics, t_symbol **dynamics, long *hairpins, char *open_hairpin, double *onset)
{
    long num_dyns = 0;
    char dyn_text[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
    t_slotitem *slotitem = NULL;
    for (t_chord *ch = curr_ch ? chord_get_prev(curr_ch) : chord_get_last(r_ob, voice); ch; ch = chord_get_prev(ch)) {
        if (chord_parse_dynamics(r_ob, ch, slot_num, dyn_text, hairpins, &num_dyns, open_hairpin, &slotitem)) {
            if (num_dynamics)
                *num_dynamics = num_dyns;
            
            if (dynamics) {
                for (long i = 0; i < num_dyns; i++) {
                    char this_dyn_text_dep[CONST_MAX_NUM_DYNAMICS_CHARS];
                    deparse_dynamics_to_string_once(r_ob, dyn_text[i], this_dyn_text_dep);
                    dynamics[i] = gensym(this_dyn_text_dep);
                }
            }
            
            if (onset)
                *onset = notation_item_get_onset_ms(r_ob, (t_notation_item *)ch);
            return ch;
        }
    }
    
    return NULL;
    
}

t_chord *dynamics_get_first(t_notation_obj *r_ob, t_voice *voice, long slot_num, long *num_dynamics, t_symbol **dynamics, long *hairpins, char *open_hairpin, double *onset)
{
    return dynamics_get_next(r_ob, voice, slot_num, NULL, num_dynamics, dynamics, hairpins, open_hairpin, onset);
}

long chord_parse_dynamics(t_notation_obj *r_ob, t_chord *ch, long slot_num, char dyn_text[][CONST_MAX_NUM_DYNAMICS_CHARS], long *hairpins, long *num_dynamics, char *open_hairpin, t_slotitem **slotitem_containing_dynamics)
{
    t_slotitem *slotitem = NULL;
    
    if (!ch->firstnote && r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
        slotitem = notation_item_get_slot_firstitem(r_ob, (t_notation_item *)ch, slot_num);
    else {
        for (t_note *temp = ch->firstnote; temp; temp = temp->next) {
            if ((slotitem = notation_item_get_slot_firstitem(r_ob, (t_notation_item *)temp, slot_num))) {
                break;
            }
        }
    }
    
    if (slotitem_containing_dynamics)
        *slotitem_containing_dynamics = slotitem;
    
    if (num_dynamics)
        *num_dynamics = 0;
    
    if (slotitem && (t_symbol *)slotitem->item) {
        parse_string_to_dynamics_ext(r_ob, ((t_symbol *)slotitem->item)->s_name, dyn_text, hairpins, num_dynamics, open_hairpin, NULL, 0);
        return 1;
    }
    
    return 0;
}


long chord_parse_dynamics_easy(t_notation_obj *r_ob, t_chord *ch, long slot_num, char *dyn_text, long *hairpin)
{
    t_slotitem *slotitem = NULL;
    
    if (!ch->firstnote && r_ob->obj_type == k_NOTATION_OBJECT_SCORE)
        slotitem = notation_item_get_slot_firstitem(r_ob, (t_notation_item *)ch, slot_num);
    else {
        for (t_note *temp = ch->firstnote; temp; temp = temp->next) {
            if ((slotitem = notation_item_get_slot_firstitem(r_ob, (t_notation_item *)temp, slot_num))) {
                break;
            }
        }
    }
    
    if (dyn_text)
        dyn_text[0] = 0;
    
    if (hairpin)
        *hairpin = 0;
    
    if (slotitem && (t_symbol *)slotitem->item) {
        char all_dynamics_text[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
        long hairpins[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
        long num_dynamics = 0;
        char open_hairpin = false;
        parse_string_to_dynamics_ext(r_ob, ((t_symbol *)slotitem->item)->s_name, all_dynamics_text, hairpins, &num_dynamics, &open_hairpin, NULL, 0);
        if (num_dynamics) {
            if (dyn_text)
                snprintf_zero(dyn_text, CONST_MAX_NUM_DYNAMICS_CHARS, "%s", all_dynamics_text[0]);
            if (hairpin && open_hairpin)
                *hairpin = hairpins[0];
        }
        return 1;
    }
    
    return 0;
}


// use item == NULL to only finish an hairpin
void paint_dynamics_from_symbol(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *color, t_notation_item *item,
                                double center_x, double duration_x, t_symbol *text, t_jfont *jf_dynamics, double font_size, double y_position,
                                double *curr_hairpin_start_x, long *curr_hairpin_type, t_jrgba *prev_hairpin_color, char *prev_hairpin_dont_paint, char inside_slot_window)
{
    char boxed = inside_slot_window;
    double xpos = center_x, ypos = y_position;
    double h = -1, w = -1;
    //    double font_size = jfont_get_font_size(jf_dynamics);
    const double HAIRPIN_PAD = 0.11 * font_size;
    const double HAIRPIN_SEMIAPERTURE =  0.175 * font_size;
    const double ZEROCIRCLE_RADIUS = 0.1 * font_size;
    char dyntext[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
    long hairpins[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
    long num_dynamics = 0;
    char open_hairpin = false;
    long i;
    t_chord *curr_ch = item ? notation_item_get_parent_chord(r_ob, item) : NULL;
    char dont_paint = (curr_ch && r_ob->is_editing_type == k_DYNAMICS && r_ob->is_editing_chord == curr_ch);
    for (i = 0; i < CONST_MAX_NUM_DYNAMICS_PER_CHORD; i++)
        dyntext[i][0] = 0;
    
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
    
    if (text){
        t_symbol *sym = text;
        parse_string_to_dynamics_ext(r_ob, sym->s_name, dyntext, hairpins, &num_dynamics, &open_hairpin, NULL, 0);
        
        if (!boxed && num_dynamics > 1) {
            double w_temp, h_temp;
            jfont_text_measure(jf_dynamics, dyntext[num_dynamics-1], &w_temp, &h_temp);
            if (duration_x - w_temp/2. > 0)
                duration_x -= w_temp/2.;
        }
        
        //        paint_line(g, *color, 0, ypos, 200, ypos, 1);
        
        if ((r_ob->show_hairpins || boxed) && curr_hairpin_type && *curr_hairpin_type && curr_hairpin_start_x) {
            // Painting the open hairpin that ends with this chord
            char is_dynamic_zero = false;
            if (h < 0 && w < 0) {
                if (dyntext[0] && (dyntext[0][0] == '0' || dyntext[0][0] == 'o' || dyntext[0][0] == 'O') && dyntext[0][1] == 0) {
                    w = h = ZEROCIRCLE_RADIUS * 2.; // "0" circle
                    is_dynamic_zero = true;
                } else if (dyntext[0])
                    jfont_text_measure(jf_dynamics, dyntext[0], &w, &h);
                else
                    w = h = 0;
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
        double y_adj_for_dynamics = - 0.93 * font_size;
        for (i = 0; i < num_dynamics; i++) {
            char align = 0;
            char is_dynamic_zero = false;
            
            //            xpos = center_x + (num_dynamics <= 1 ? 0 : i * (duration_x/(open_hairpin ? num_dynamics : num_dynamics - 1)));
            xpos = center_x + (num_dynamics <= 1 ? 0 : i * (duration_x/(num_dynamics - 1)));
            
            if (r_ob->show_dynamics || boxed) {
                if (dyntext[i] && (dyntext[i][0] == '0' || dyntext[i][0] == 'o' || dyntext[i][0] == 'O') && dyntext[i][1] == 0) {
                    if (!dont_paint)
                        paint_circle_stroken(g, *color, xpos, ypos, ZEROCIRCLE_RADIUS, 1);
                    is_dynamic_zero = true;
                } else if (boxed && (i == 0 || (!open_hairpin && i == num_dynamics - 1))) {
                    align = (i == 0 ? -1 : 1);
                    if (!dont_paint)
                        write_text(g, jf_dynamics, *color, dyntext[i], center_x, ypos + y_adj_for_dynamics, duration_x, ypos + 300, (i == 0 ? JGRAPHICS_TEXT_JUSTIFICATION_LEFT : JGRAPHICS_TEXT_JUSTIFICATION_RIGHT) | JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
                } else {
                    if (!dont_paint)
                        write_text(g, jf_dynamics, *color, dyntext[i], xpos - 200, ypos + y_adj_for_dynamics, 400, ypos + 300, JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED | JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
                }
            }
            
            if (is_dynamic_zero)
                w = h = ZEROCIRCLE_RADIUS * 2.;
            else
                jfont_text_measure(jf_dynamics, dyntext[i], &w, &h);
            
            // painting hairpin?
            if ((r_ob->show_hairpins || boxed) && !dont_paint && i > 0 && hairpins[i-1] && prev_end_xpos < xpos - (align == 0 ? w/2. : w) - (is_dynamic_zero ? 0. : HAIRPIN_PAD))
                paint_hairpin(g, *color, hairpins[i-1], prev_end_xpos, xpos - (align == 0 ? w/2. : w) - (is_dynamic_zero ? 0. : HAIRPIN_PAD), ypos, HAIRPIN_SEMIAPERTURE, 1);
            
            prev_end_xpos = (align == 0 ? xpos + w/2. + (is_dynamic_zero ? 0. : HAIRPIN_PAD) : xpos + w + (is_dynamic_zero ? 0. : HAIRPIN_PAD));
            
            if (curr_hairpin_type)
                *curr_hairpin_type = hairpins[i];
            if (curr_hairpin_start_x && hairpins[i]) {
                *curr_hairpin_start_x = prev_end_xpos;
            }
        }
        
        if (boxed && open_hairpin && !dont_paint && hairpins[num_dynamics - 1] && prev_end_xpos < center_x + duration_x - HAIRPIN_PAD) {
            paint_hairpin(g, *color, hairpins[num_dynamics - 1], prev_end_xpos, center_x + duration_x - HAIRPIN_PAD, ypos, HAIRPIN_SEMIAPERTURE, 1);
        }
    }
}


void paint_dynamics_from_slot(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *color, t_notation_item *item,
                              double center_x, double duration_x, long slot, t_jfont *jf_dynamics, double font_size, double y_position,
                              double *curr_hairpin_start_x, long *curr_hairpin_type, char boxed)
{
    t_slotitem *firstitem = notation_item_get_slot_firstitem(r_ob, item, slot);
    if (firstitem && (t_symbol *)firstitem->item){
        t_symbol *sym = (t_symbol *)firstitem->item;
        paint_dynamics_from_symbol(r_ob, g, color, item, center_x, duration_x, sym, jf_dynamics, font_size, y_position, curr_hairpin_start_x, curr_hairpin_type, NULL, NULL, boxed);
    }
}


void paint_dynamics(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *color, t_dynamics *dynamics,
                    double center_x, double duration_x, t_jfont *jf_dynamics, double font_size, double y_position,
                    double *curr_hairpin_start_x, long *curr_hairpin_type, t_jrgba *prev_hairpin_color, char *prev_hairpin_dont_paint, char boxed)
{
    if (dynamics && dynamics->text){
        paint_dynamics_from_symbol(r_ob, g, color, (t_notation_item *)dynamics->owner, center_x, duration_x, dynamics->text, jf_dynamics, font_size, y_position, curr_hairpin_start_x, curr_hairpin_type, prev_hairpin_color, prev_hairpin_dont_paint, boxed);
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
        } else if (*c == ' '){
            buf[cur++] = ' ';
            c++;
        } else if (*c == '0') {
            buf[cur++] = '0';
            c++;
        } else
            c++;
    }
    buf[cur] = 0;
}


// returns 1 if has crescendo, -1 if it has diminuendo, 0 otherwise
// buf is assumed to be 0-terminated
long parse_string_to_dynamics_once(t_notation_obj *r_ob, char *buf, char *dynamics)
{
    long res = 0;
    
    if (!buf) {
        dynamics[0] = 0;
        return 0;
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
                
            case '0':
            case 'o':
            case 'O':
                if (strncasecmp(c, "0", 1) == 0 || strncasecmp(c, "o", 1) == 0 || strncasecmp(c, "O", 1) == 0) {
                    dynamics[cur++] = '0';
                    c++;
                } else
                    c++;
                break;

            case ' ':
                dynamics[cur++] = ' ';
                c++;
                break;
                
            case '<':
                if (*(c+1) == 0) {
                    res = 1;
                    c+=1;
                } else if (*(c+1) == '<' && *(c+2) == 0) {
                    res = 2;
                    c+=2;
                } else
                    c++;
                break;
                
            case '>':
                if (*(c+1) == 0) {
                    res = -1;
                    c+=1;
                } else if (*(c+1) == '>' && *(c+2) == 0) {
                    res = -2;
                    c+=2;
                } else
                    c++;
                break;
                
            default:
                c++;
                break;
        }
    }
    dynamics[cur] = 0;
    return res;
}



void parse_string_to_dynamics_ext(t_notation_obj *r_ob, char *buf, char dynamics[][CONST_MAX_NUM_DYNAMICS_CHARS], long *hairpins, long *num_dynamics, char *open_hairpin, char *complete_deparsed_string, long complete_deparsed_string_alloc)
{
    if (!buf || !buf[0]) {
        if (num_dynamics)
            *num_dynamics = 0;
        if (complete_deparsed_string)
            complete_deparsed_string[0] = 0;
        return;
    }
    
    char *c = buf, *d;
    long cur = 0;
    long this_num_dynamics = 0;
    char temp[CONST_MAX_NUM_DYNAMICS_CHARS];
    while (*c)
    {
        d = c;
        while (*d != 0 && *d != '<' && *d != '>' && *d != '_')
            d++;
        while (*d == '<' || *d == '>' || *d == '_')
            d++;
        
        sysmem_copyptr(c, temp, MIN(CONST_MAX_NUM_DYNAMICS_CHARS * sizeof(char), d-c));
        temp[MAX(0, MIN(CONST_MAX_NUM_DYNAMICS_CHARS - 1, d-c))] = 0;

        char this_dynamics[CONST_MAX_NUM_DYNAMICS_CHARS];
        long this_hairpin = parse_string_to_dynamics_once(r_ob, temp, this_dynamics);
        if (hairpins)
            hairpins[this_num_dynamics] = this_hairpin;
        if (open_hairpin)
            *open_hairpin = (this_hairpin != 0);
        if (dynamics)
            sysmem_copyptr(this_dynamics, dynamics[this_num_dynamics], CONST_MAX_NUM_DYNAMICS_CHARS * sizeof(char));
        this_num_dynamics++;
        
        if (complete_deparsed_string)
            snprintf_zero(complete_deparsed_string + cur, complete_deparsed_string_alloc - cur, "%s%s", this_dynamics, this_hairpin == -2 ? ">>" : this_hairpin == -1 ? ">" : this_hairpin == 1 ? "<" : this_hairpin == 2 ? "<<" : " ");
        
        if (this_num_dynamics >= CONST_MAX_NUM_DYNAMICS_PER_CHORD)
            break;
        
        c = d;
    }
    
    if (num_dynamics)
        *num_dynamics = this_num_dynamics;
    
    if (complete_deparsed_string) {
        complete_deparsed_string[complete_deparsed_string_alloc-1] = 0;
        if (complete_deparsed_string[strlen(complete_deparsed_string)-1] == ' ')
            complete_deparsed_string[strlen(complete_deparsed_string)-1] = 0;
    }
}


long dynamic_marking_cmp(char *mark1, char *mark2)
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

        case '0':
        case ' ':
        case 'n':
            if (mark2[0] == '0' || mark2[0] == 'n' || mark2[0] == ' ')
                return 0;
            else
                return 1;
            break;

        case 'p':
            if (mark2[0] == '0' || mark2[0] == 'n')
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
            if (mark2[0] == '0' || mark2[0] == 'n' || mark2[0] == 'p')
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
            if (mark2[0] == '0' || mark2[0] == 'n' || mark2[0] == 'p' || mark2[0] == 'm')
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
            if (mark2[0] == '0' || mark2[0] == 'n' || mark2[0] == 'p' || mark2[0] == 'm' || mark2[0] == 'f')
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
            *c = ' ';
            break;
        }
        c++;
    }
    
    snprintf_zero(dyn_buf, CONST_MAX_NUM_DYNAMICS_CHARS * CONST_MAX_NUM_DYNAMICS_PER_CHORD, "%s", c);
}

long notationobj_check_dynamics(t_notation_obj *r_ob, long slot_num, char check_inconsistent, char check_unnecessary, char fix_inconsistent, char fix_unnecessary, char selection_only, char verbose)
{
    char path[1024];
    char dyn_text[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
    char dyn_text_dep[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
    long hairpins[CONST_MAX_NUM_DYNAMICS_PER_CHORD];
    long i;
    char last_dyn_text_dep[CONST_MAX_NUM_DYNAMICS_CHARS];
    long last_hairpin = 0;
    t_slotitem *last_slotitem = NULL;
    t_chord *last_chord = NULL;
    last_dyn_text_dep[0] = 0;

    for (t_voice *voice = r_ob->firstvoice; voice && voice->number < r_ob->num_voices; voice = voice_get_next(r_ob, voice)) {
        last_slotitem = NULL;
        last_chord = NULL;
        last_dyn_text_dep[0] = 0;
        last_hairpin = 0;

        
        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ) {
            long num_dynamics = 0;
            char open_hairpin = false;
            char something_fixed = false;
            t_slotitem *slotitem = NULL;
            
            if (selection_only && !notation_item_is_globally_selected(r_ob, (t_notation_item *)ch)) {
                ch = chord_get_next(ch);
                continue;
            }
            
            chord_parse_dynamics(r_ob, ch, slot_num, dyn_text, hairpins, &num_dynamics, &open_hairpin, &slotitem);
            
            for (i = 0; i < num_dynamics; i++)
                deparse_dynamics_to_string_once(r_ob, dyn_text[i], dyn_text_dep[i]);
            
            if (num_dynamics > 0){
                
                // checking dangling hairpin
                if (check_inconsistent && last_hairpin) {
                    long cmp = dynamic_marking_cmp(last_dyn_text_dep, dyn_text_dep[0]);
                    if (last_hairpin * cmp <= 0) {
                        if (verbose) {
                            check_dynamics_get_path(r_ob, ch, path, 1024, num_dynamics > 1 ? 1 : 0);
                            object_warn((t_object *)r_ob, "Inconsistent %s found from '%s' to '%s' %s", last_hairpin > 0 ? "crescendo" : "diminuendo", last_dyn_text_dep, dyn_text_dep[0], path);
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
                                last_dyn_text_dep[0] = 0;
                                last_hairpin = 0;
                                continue;
                            }
                        }
                    }
                }
                
                // checking unnecessary dynamics
                if (check_unnecessary) {
                    if (!last_hairpin && last_dyn_text_dep[0] && strcmp(dyn_text_dep[0], last_dyn_text_dep) == 0 && !hairpins[0]) {
                        if (verbose) {
                            check_dynamics_get_path(r_ob, ch, path, 1024, num_dynamics > 1 ? 1 : 0);
                            object_warn((t_object *)r_ob, "Unnecessary dynamic marking found: '%s' %s", last_dyn_text_dep, path);
                        }
                        if (fix_unnecessary) {
                            something_fixed = true;
                            if (num_dynamics == 1)
                                num_dynamics = 0;
                            else {
                                remove_first_dynamic_from_deparsed_dynamic(dyn_text_dep[0]);
                            }
                        }
                    }
                    
                    for (i = 1; i < num_dynamics; i++) {
                        if (strcmp(dyn_text[i-1], dyn_text[i]) == 0 && !hairpins[i-1] && !hairpins[i]) {
                            if (verbose) {
                                check_dynamics_get_path(r_ob, ch, path, 1024, num_dynamics > 1 ? i : 0);
                                object_warn((t_object *)r_ob, "Unnecessary dynamic marking found: '%s' %s", dyn_text_dep[i], path);
                            }
                            if (fix_unnecessary) {
                                something_fixed = true;
                                remove_first_dynamic_from_deparsed_dynamic(dyn_text_dep[i]);
                            }
                        }
                    }
                }
                
                // checking hairpins
                if (check_inconsistent) {
                    for (i = 1; i < num_dynamics; i++) {
                        // comparing i-1 with i
                        long cmp = dynamic_marking_cmp(dyn_text_dep[i-1], dyn_text_dep[i]);
                        if (hairpins[i-1] && hairpins[i-1] * cmp <= 0) {
                            if (verbose) {
                                check_dynamics_get_path(r_ob, ch, path, 1024, num_dynamics > 1 ? i : 0);
                                object_warn((t_object *)r_ob, "Inconsistent %s found from '%s' to '%s' %s", hairpins[i-1] > 0 ? "crescendo" : "diminuendo", dyn_text_dep[i-1], dyn_text_dep[i], path);
                            }
                            if (fix_inconsistent) {
                                something_fixed = true;
                                hairpins[i-1] = labs(hairpins[i-1]) * cmp; // correcting the hairpin
                            }
                        }
                    }
                }
                
                if (num_dynamics > 0) {
                    last_hairpin = open_hairpin ? hairpins[num_dynamics - 1] : 0;
                    snprintf_zero(last_dyn_text_dep, CONST_MAX_NUM_DYNAMICS_CHARS, "%s", dyn_text_dep[num_dynamics - 1]);
                }
            }
            
            
            if (slotitem && something_fixed) {
                // building complete string
                char buf[CONST_MAX_NUM_DYNAMICS_PER_CHORD * CONST_MAX_NUM_DYNAMICS_CHARS];
                reassemble_dynamics_buf(r_ob, num_dynamics, dyn_text_dep, hairpins, buf, CONST_MAX_NUM_DYNAMICS_PER_CHORD * CONST_MAX_NUM_DYNAMICS_CHARS);
                create_simple_notation_item_undo_tick(r_ob, (t_notation_item *)ch, k_UNDO_MODIFICATION_CHANGE);
                if (num_dynamics <= 0) {
                    slotitem_delete(r_ob, slot_num, slotitem);
                    slotitem = NULL;
                } else
                    slotitem->item = gensym(buf);
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



t_symbol *chord_get_first_dynamics(t_notation_obj *r_ob, t_chord *ch, long slot_num)
{
    char dyn_text[CONST_MAX_NUM_DYNAMICS_PER_CHORD][CONST_MAX_NUM_DYNAMICS_CHARS];
    long num_dynamics = 0;
    chord_parse_dynamics(r_ob, ch, slot_num, dyn_text, NULL, &num_dynamics, NULL);
    
    if (num_dynamics > 0) {
        char temp[CONST_MAX_NUM_DYNAMICS_CHARS * 3];
        deparse_dynamics_to_string_once(r_ob, dyn_text[0], temp);
        return gensym(temp);
    } else
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
                                    t_symbol *right_dyn = chord_get_first_dynamics(r_ob, nextchwithdyn, slot_num);
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
        
        next_dyn_chord = dynamics_get_next(r_ob, voice, slot_num, next_dyn_chord, &next_num_dynamics, next_dyn_sym, next_hairpins, &next_open_hairpin, &next_dyn_onset);

        for (t_chord *ch = chord_get_first(r_ob, voice); ch; ch = chord_get_next(ch)) {
            if (ch == next_dyn_chord) {
//                if (next_num_dynamics > 0 && !is_dynamics_local(r_ob, dyn_vel_associations, next_dyn_sym[next_num_dynamics-1], 1)) {
                    curr_dyn_chord = next_dyn_chord;
                    curr_dyn_onset = next_dyn_onset;
                    curr_num_dynamics = next_num_dynamics;
                    curr_open_hairpin = next_open_hairpin;
                    bach_copyptr(next_hairpins, curr_hairpins, CONST_MAX_NUM_DYNAMICS_PER_CHORD * sizeof(long));
                    bach_copyptr(next_dyn_sym, curr_dyn_sym, CONST_MAX_NUM_DYNAMICS_PER_CHORD * sizeof(t_symbol *));
                    next_dyn_chord = dynamics_get_next(r_ob, voice, slot_num, next_dyn_chord, &next_num_dynamics, next_dyn_sym, next_hairpins, &next_open_hairpin, &next_dyn_onset);
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

t_llll *dynamic_marking_to_slots_ll(long slot_num, t_symbol *dyn)
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
        t_llll *slot_ll = dynamic_marking_to_slots_ll(slot_num, dyn);
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

    
    // 3. deleting unnecessary dynamics
    notationobj_check_dynamics(r_ob, slot_num, true, delete_unnecessary, true, delete_unnecessary, selection_only, false);


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
