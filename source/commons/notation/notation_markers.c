/*
 *  notation_markers.c
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
    notation_markers.c - common functions (or useful functions) for markers
*/

#include "notation/notation_markers.h"




t_marker *marker_get_nth(t_notation_obj *r_ob, long n)
{
    t_marker *curr = r_ob->firstmarker;
    long i;
    long zero_based_index = n;
    
    if (zero_based_index < 0)
        return NULL;
    
    if (zero_based_index > r_ob->num_markers)
        return NULL;
    
    for (i=0; i<zero_based_index && curr; i++)
        curr = curr->next;
    return curr;
    // to be improved: if the marker# is > n/2, pass the list the other way round!
}



char marker_is_region(t_marker *mk)
{
    if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE)
        return (mk->r_sym_duration.r_num != 0);
    else
        return (mk->duration_ms != 0);
}



char marker_is_region_till_next(t_marker *mk)
{
    if (mk->attach_to == k_MARKER_ATTACH_TO_MEASURE)
        return (mk->r_sym_duration.r_num < 0);
    else
        return (mk->duration_ms < 0);
}


double marker_get_voffset(t_notation_obj *r_ob, t_marker *mk)
{
    double ypos = 0;
    if (r_ob->ruler % 2) {
        if (r_ob->show_ruler_labels)
            ypos = 7 * r_ob->zoom_y;
        else
            ypos = 4 * r_ob->zoom_y;
    } else
        ypos = 1 * r_ob->zoom_y;
    
    if (r_ob->smart_markername_placement)
        ypos += (r_ob->markers_font_size + 4) * r_ob->zoom_y * mk->name_line;
    
    return ypos;
}


double marker_get_top_y(t_notation_obj *r_ob, t_marker *mk)
{
    double playhead_y1;
    get_playhead_ypos(r_ob, &playhead_y1, NULL);
    return playhead_y1 + marker_get_voffset(r_ob, mk);
}



void fill_marker_path_from_llllelem_range(t_notation_obj *r_ob, t_llllelem *first_llllelem, long *marker_num)
{
    // initializing stuff
    if (marker_num)
        *marker_num = 1;
    
    long tot_size = 0;
    t_llllelem *temp = first_llllelem;
    while (temp) {
        tot_size++;
        temp = temp->l_next;
    }
    
    if (tot_size >= 1 && is_hatom_number(&first_llllelem->l_hatom)) {
        *marker_num = hatom_getlong(&first_llllelem->l_hatom);
    }
}


t_marker *get_marker_from_path(t_notation_obj *r_ob, long marker_num)
{
    if (marker_num < 0)
        marker_num = r_ob->num_markers + marker_num + 1;
    
    if (marker_num <= 0 || marker_num > r_ob->num_markers)
        return NULL;
    
    return marker_get_nth(r_ob, marker_num-1);
}



t_marker *get_marker_from_path_as_llllelem_range(t_notation_obj *r_ob, t_llllelem *start_llllelem)
{
    long marker_num = 1;
    fill_marker_path_from_llllelem_range(r_ob, start_llllelem, &marker_num);
    return get_marker_from_path(r_ob, marker_num);
}




t_timepoint marker_region_get_start_timepoint(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        return measure_attached_marker_to_timepoint(r_ob, marker);
    } else {
        return build_timepoint_with_voice(0, long2rat(0), 0);
    }
}

t_marker *marker_get_next_marker_with_same_attachment(t_marker *marker)
{
    char attachment = marker->attach_to;
    for (t_marker *temp = marker->next; temp; temp = temp->next)
        if (temp->attach_to == attachment)
            return temp;
    return NULL;
}

t_timepoint marker_region_get_end_timepoint(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_timepoint start_tp = marker_region_get_start_timepoint(r_ob, marker);
        if (!marker_is_region(marker))
            return start_tp;
        else {
            if (marker->r_sym_duration.r_num >= 0) {
                return timepoint_shift(r_ob, start_tp, build_timepoint(0, marker->r_sym_duration));
            } else {
                t_marker *next = marker_get_next_marker_with_same_attachment(marker);
                if (!next) { // till the end!
                    t_measure *meas = (t_measure *) notation_item_retrieve_from_ID(r_ob, marker->measure_attach_ID);
                    if (meas && meas->voiceparent) {
                        t_scorevoice *voice = meas->voiceparent;
                        return build_timepoint_with_voice(voice->num_measures, long2rat(0), voice->v_ob.number);
                    } else {
                        return build_timepoint_with_voice(0, long2rat(0), 0);
                    }
                } else {
                    return marker_region_get_start_timepoint(r_ob, next);
                }
            }
        }
    } else {
        return build_timepoint_with_voice(0, long2rat(0), 0);
    }
}

double marker_get_onset_ms(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        return unscaled_xposition_to_ms(r_ob, marker_get_onset_ux(r_ob, marker), 1);
    } else {
        return marker->position_ms;
    }
}


double marker_get_onset_ux(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_timepoint tp = marker_region_get_start_timepoint(r_ob, marker);
        return (r_ob->timepoint_to_unscaled_xposition)(r_ob, tp, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS ? k_PARSETIMEPOINT_FLAG_ZEROPIMISFIRSTCHORD : k_PARSETIMEPOINT_FLAG_NONE);
    } else {
        return ms_to_unscaled_xposition(r_ob, marker->position_ms, 1);
    }
}

double marker_get_onset_x(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
        return unscaled_xposition_to_xposition(r_ob, (r_ob->timepoint_to_unscaled_xposition)(r_ob, tp, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS ? k_PARSETIMEPOINT_FLAG_ZEROPIMISFIRSTCHORD : k_PARSETIMEPOINT_FLAG_NONE));
    } else {
        return ms_to_xposition(r_ob, marker->position_ms);
    }
}



double marker_region_get_end_ms(t_notation_obj *r_ob, t_marker *marker, char for_painting)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        return unscaled_xposition_to_ms(r_ob, marker_region_get_end_ux(r_ob, marker, for_painting), 1);
    } else {
        if (marker->duration_ms > 0)
            return marker->position_ms + marker->duration_ms;
        else {
            if (marker->duration_ms < 0) { // till next
                t_marker *next = marker_get_next_marker_with_same_attachment(marker);
                if (next)
                    return next->position_ms;
                else
                    return for_painting ? r_ob->screen_ms_end + 10 * r_ob->zoom_y : r_ob->length_ms;
            } else
                return marker->position_ms;
        }
    }
}



double marker_region_get_end_ux(t_notation_obj *r_ob, t_marker *marker, char for_painting)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_timepoint tp = marker_region_get_end_timepoint(r_ob, marker);
        return (r_ob->timepoint_to_unscaled_xposition)(r_ob, tp, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS ? k_PARSETIMEPOINT_FLAG_ZEROPIMISFIRSTCHORD : k_PARSETIMEPOINT_FLAG_NONE);
    } else {
        return ms_to_unscaled_xposition(r_ob, marker_region_get_end_ms(r_ob, marker, for_painting), 1);
    }
}


double marker_region_get_end_x(t_notation_obj *r_ob, t_marker *marker, char for_painting)
{
    if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_timepoint tp = marker_region_get_end_timepoint(r_ob, marker);
        return unscaled_xposition_to_xposition(r_ob, (r_ob->timepoint_to_unscaled_xposition)(r_ob, tp, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS ? k_PARSETIMEPOINT_FLAG_ZEROPIMISFIRSTCHORD : k_PARSETIMEPOINT_FLAG_NONE));
    } else {
        return ms_to_xposition(r_ob, marker_region_get_end_ms(r_ob, marker, for_painting), 1);
    }
}


double marker_region_get_width(t_notation_obj *r_ob, t_marker *marker, char for_painting)
{
    if (marker_is_region(marker)) {
        return marker_region_get_end_x(r_ob, marker, for_painting) - marker_get_onset_x(r_ob, marker);
    } else
        return 0;
}


double marker_region_get_duration_ms(t_notation_obj *r_ob, t_marker *marker, char for_painting)
{
    if (marker_is_region(marker))
        return marker_region_get_end_ms(r_ob, marker, for_painting) - marker_get_onset_ms(r_ob, marker);
    else
        return 0;
}

void paint_marker(t_notation_obj *r_ob, t_jgraphics* g, t_jrgba *linecolor, t_jrgba *textcolor, t_jfont* jf, t_marker *marker, double marker_x, double marker_end_x, double marker_y1, double marker_y2, char is_region, double linewidth, char also_paint_name, double *namewidth, double *prev_marker_x, double *prev_marker_width, t_marker *prev_region_marker, double *prev_region_marker_x, double *prev_region_marker_width)
{
    if (r_ob->smart_markername_placement) {
        t_marker *refmarker = NULL;
        if (marker->prev &&
            (!marker_is_region_till_next(marker->prev) || (r_ob->obj_type == k_NOTATION_OBJECT_SCORE && marker->attach_to != marker->prev->attach_to)) &&
             *prev_marker_x + *prev_marker_width + (marker_is_region(marker->prev) ? 0 : 2 * r_ob->step_y) > marker_x - (marker->name_painted_direction < 0) * marker->name_uwidth * r_ob->zoom_y) {
            refmarker = marker->prev;
            marker->name_line = refmarker->name_line + 1;
            if (refmarker->name_line > 0) {
                for (t_marker *tempmk = refmarker->prev; tempmk; tempmk = tempmk->prev)
                    if (tempmk->name_line == 0) {
                        double tempmkwidth = MAX(marker_region_get_width(r_ob, tempmk, true), tempmk->name_uwidth * r_ob->zoom_y + 2);
                        if (onset_to_xposition_roll(r_ob, tempmk->position_ms, NULL) + tempmkwidth + 2 * r_ob->step_y <= marker_x - (marker->name_painted_direction < 0) * marker->name_uwidth * r_ob->zoom_y)
                            marker->name_line = 0;
                        break;
                    }
            }
        } else if (is_region && prev_region_marker && !marker_is_region_till_next(prev_region_marker) && *prev_region_marker_x + *prev_region_marker_width > marker_x) {
            refmarker = prev_region_marker;
            marker->name_line = refmarker->name_line + 1;
            if (refmarker->name_line > 0) {
                for (t_marker *tempmk = refmarker->prev; tempmk; tempmk = tempmk->prev)
                    if (tempmk->name_line == 0) {
                        if (onset_to_xposition_roll(r_ob, tempmk->position_ms, NULL) + deltaonset_to_deltaxpixels(r_ob, tempmk->duration_ms) + 2 * r_ob->step_y <= marker_x - (marker->name_painted_direction < 0) * marker->name_uwidth * r_ob->zoom_y)
                            marker->name_line = 0;
                        break;
                    }
            }
        } else
            marker->name_line = 0;
    } else
        marker->name_line = 0;
    
    double regionwidth = 0;
    char marker_is_being_edited = (r_ob->is_editing_type == k_MARKERNAME && r_ob->is_editing_marker == marker);
    if (is_region) {
        regionwidth = marker_end_x - marker_x;
        t_rect markerstrip = build_rect(marker_x, marker_y1 + marker_get_voffset(r_ob, marker) - r_ob->zoom_y, regionwidth, (r_ob->markers_font_size + 4) * r_ob->zoom_y - 1);
        paint_rect(g, &markerstrip, linecolor, marker_is_being_edited ? textcolor : linecolor, 0, 2);
    }
    
    double regiontextwidth = 0;
    if (is_region) {
        regiontextwidth = regionwidth;
        if (!marker_is_region_till_next(marker)) { // see if we can increase this
            // find next region
            char found = false;
            for (t_marker *temp = marker->next; temp; temp = temp->next) {
                if (marker_is_region(temp)) {
                    regiontextwidth = MAX(regiontextwidth, onset_to_xposition_roll(r_ob, temp->position_ms, NULL) - marker_x);
                    found = true;
                    break;
                }
            }
            if (!found) {
                regiontextwidth = 0;
            }
        }
    }
    
    
    char name_direction = marker->name_painted_direction;
    double height = 0;
    
    paint_line(g, *linecolor, marker_x, marker_y1 + (is_region ? marker_get_voffset(r_ob, marker) - r_ob->zoom_y : 0), marker_x, marker_y2, linewidth);
    
    if (marker->role != k_MARKER_ROLE_NONE) {
        t_jfont *jf_special_text_markers = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, round(6 * r_ob->zoom_y));  // text font for markers
        t_jrgba specialcolor = marker->role == k_MARKER_ROLE_TEMPO ? build_jrgba(0.6, 0.2, 0.2, 1) : (marker->role == k_MARKER_ROLE_TIME_SIGNATURE ? build_jrgba(0.2, 0.2, 0.6, 1) : (marker->role == k_MARKER_ROLE_MEASURE_BARLINE ? build_jrgba(0.2, 0.6, 0.6, 1) : (marker->role == k_MARKER_ROLE_MEASURE_DIVISION ? build_jrgba(0.6, 0.6, 0.2, 1) : build_jrgba(0.6, 0.2, 0.6, 1))));
        paint_dashed_y_line(g, specialcolor, marker_x, marker_y1, marker_y2, linewidth, 3 * r_ob->zoom_y);
        if (namewidth)
            *namewidth = 0;
        write_text_in_vertical(g, jf_special_text_markers, specialcolor, marker->role == k_MARKER_ROLE_TEMPO ? "TEMPO" : (marker->role == k_MARKER_ROLE_TIME_SIGNATURE ? "TIME SIG" : (marker->role == k_MARKER_ROLE_MEASURE_BARLINE ? "BARLINE" : (marker->role == k_MARKER_ROLE_MEASURE_DIVISION ? "DIVISION" : "SUBDIVISION"))), name_direction < 0 ? marker_x : marker_x - 10 * r_ob->zoom_y, marker_y1 + 3 * r_ob->zoom_y, 10 * r_ob->zoom_y, marker_y2 - marker_y1 - 6 * r_ob->zoom_y, (marker->role == k_MARKER_ROLE_TEMPO ? JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM : JGRAPHICS_TEXT_JUSTIFICATION_TOP) + JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED, 0.8);
        jfont_destroy_debug(jf_special_text_markers);
    }
    
    if (also_paint_name) {
        if (marker->role == k_MARKER_ROLE_NONE) {
            if (marker && marker->r_it.names && marker->r_it.names->l_size > 0) {
                char buf[1000];
                get_names_as_text(marker->r_it.names, buf, 1000);
                if (namewidth)
                    jfont_text_measure(jf, buf, namewidth, &height);
                double text_x = name_direction < 0 ? marker_x - 3 * r_ob->zoom_y - marker->name_uwidth * r_ob->zoom_y : marker_x + 3 * r_ob->zoom_y;
                double text_y = marker_y1 + marker_get_voffset(r_ob, marker);
                if (is_region && text_x < get_predomain_width_pixels(r_ob)) {
                    double predomain_pix = get_predomain_width_pixels(r_ob);
                    double diff = predomain_pix - text_x;
                    text_x = predomain_pix;
                    if (regiontextwidth > 0)
                        regiontextwidth = MAX(0.01, regiontextwidth - diff); // cannot be 0, we use it as special value...
                }
                if (!is_region || text_x < marker_end_x)
                    write_text(g, jf, *textcolor, buf, text_x, text_y, regiontextwidth == 0 ? r_ob->width - text_x : regiontextwidth, r_ob->height - text_y, JGRAPHICS_TEXT_JUSTIFICATION_LEFT, true, false);
                //                write_text_standard_account_for_vinset(r_ob, g, jf, *textcolor, buf, name_direction < 0 ? marker_x - 3 * r_ob->zoom_y - marker->name_uwidth * r_ob->zoom_y : marker_x + 3 * r_ob->zoom_y, marker_y1 + marker_get_voffset(r_ob, marker));
            }
        } else if ((marker->role == k_MARKER_ROLE_TEMPO || marker->role == k_MARKER_ROLE_TIME_SIGNATURE) && marker->content) {
            char *buf = NULL;
            llll_to_text_buf(marker->content, &buf, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
            if (namewidth)
                jfont_text_measure(jf, buf, namewidth, &height);
            write_text(g, jf, *textcolor, buf, name_direction < 0 ? marker_x - 3 * r_ob->zoom_y - marker->name_uwidth * r_ob->zoom_y : marker_x + 3 * r_ob->zoom_y, marker_y1 + marker_get_voffset(r_ob, marker), 200 * r_ob->zoom_y, marker_y2 - marker_y1 - 6 * r_ob->zoom_y,
                       (marker->role == k_MARKER_ROLE_TEMPO ? JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM : JGRAPHICS_TEXT_JUSTIFICATION_TOP) + JGRAPHICS_TEXT_JUSTIFICATION_LEFT, true, true);
            bach_freeptr(buf);
        }
    }
    
    if (is_region) {
        *prev_marker_width = marker_end_x - marker_x;
        *prev_region_marker_x = marker_x;
        *prev_region_marker_width = *prev_marker_width;
    }
    *prev_marker_x = marker_x;
    
    
#ifdef BACH_PAINT_IDS
#ifdef BACH_MARKERS_HAVE_ID
    char text[20];
    snprintf_zero(text, 40, "%ld", marker->r_it.ID);
    write_text(g, jf, build_jrgba(0.5, 0.2, 0.5, 1), text, marker_x + 3 * r_ob->zoom_y, marker_y1 + 10 * r_ob->zoom_y, 50 * r_ob->zoom_y, 40, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, false);
#endif
#endif
    
}









// returns 1 if the point (point_x, point_y) is on the marker
int is_in_marker_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y)
{
    double marker_x = -10000;
    
    if (r_ob->obj_type == k_NOTATION_OBJECT_SCORE) {
        if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE && r_ob->timepoint_to_unscaled_xposition) {
            t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
            marker_x = unscaled_xposition_to_xposition(r_ob, (r_ob->timepoint_to_unscaled_xposition)(r_ob, tp, CONST_MARKERS_ON_FIRST_MEASURE_CHORDS ? k_PARSETIMEPOINT_FLAG_ZEROPIMISFIRSTCHORD : k_PARSETIMEPOINT_FLAG_NONE));
        } else
            marker_x = ms_to_xposition(r_ob, marker->position_ms, 1);
    } else {
        marker_x = onset_to_xposition_roll(r_ob, marker->position_ms, NULL);
    }
    
    if (fabs(point_x - marker_x) < 2 + 2 * r_ob->zoom_y && point_y < r_ob->height - (CONST_XSCROLLBAR_UHEIGHT + 2) * r_ob->zoom_y)
        return 1;
    return 0;
}


// returns 1 if the point (point_x, point_y) is on the markername
int is_in_markername_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y)
{
    double marker_x;
    double marker_namewidth, marker_name_y_start, marker_nameheight;

    marker_x = marker_get_onset_x(r_ob, marker);
    marker_namewidth = marker->name_uwidth * r_ob->zoom_y;
    marker_name_y_start = marker_get_top_y(r_ob, marker);
    marker_nameheight = r_ob->markers_font_size * r_ob->zoom_y;

    if (marker->name_painted_direction > 0) {
        if (point_x > marker_x && point_x < marker_x + marker_namewidth + 2 * r_ob->zoom_y &&
            point_y > marker_name_y_start && point_y < marker_name_y_start + marker_nameheight)
            return 1;
    } else {
        if (point_x > marker_x - marker_namewidth - 2 * r_ob->zoom_y && point_x < marker_x &&
            point_y > marker_name_y_start && point_y < marker_name_y_start + marker_nameheight)
            return 1;
    }
    
    return 0;
}

int is_in_marker_region_stripe_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y)
{
    if (!marker_is_region(marker))
        return 0;
    
    double marker_x;
    double marker_width, marker_name_y_start, marker_nameheight;
    
    marker_x = marker_get_onset_x(r_ob, marker);
    marker_width = marker_region_get_width(r_ob, marker, true);
    marker_name_y_start = marker_get_top_y(r_ob, marker);
    marker_nameheight = r_ob->markers_font_size * r_ob->zoom_y;
    
    if (marker->name_painted_direction > 0) {
        if (point_x > marker_x && point_x < marker_x + marker_width + 2 * r_ob->zoom_y &&
            point_y > marker_name_y_start && point_y < marker_name_y_start + marker_nameheight)
            return 1;
    } else {
        if (point_x > marker_x - marker_width - 2 * r_ob->zoom_y && point_x < marker_x &&
            point_y > marker_name_y_start && point_y < marker_name_y_start + marker_nameheight)
            return 1;
    }
    

    return 0;
}

int is_in_marker_region_tail_shape(t_notation_obj *r_ob, t_marker *marker, long point_x, long point_y, char consider_region_markers_only)
{
    if (consider_region_markers_only && !marker_is_region(marker))
        return 0;
    
    double marker_end_x;
    double marker_width, marker_name_y_start, marker_nameheight;
    
    marker_end_x = marker_region_get_end_x(r_ob, marker, true);
    marker_width = marker_region_get_width(r_ob, marker, true);
    marker_name_y_start = marker_get_top_y(r_ob, marker);
    marker_nameheight = r_ob->markers_font_size * r_ob->zoom_y;
    
    if (fabs(point_x - marker_end_x) < 2 + 2 * r_ob->zoom_y && point_y > marker_name_y_start && point_y < marker_name_y_start + marker_nameheight)
        return 1;
    
    return 0;
}

void marker_region_preselect_all_items(t_notation_obj *r_ob, t_marker *marker)
{
    if (!marker_is_region(marker))
        return;
    
    double o1 = marker_get_onset_ms(r_ob, marker);
    double o2 = marker_region_get_end_ms(r_ob, marker, false);
    
    for (t_voice *voice = r_ob->firstvoice; voice; voice = voice_get_next(r_ob, voice)) {
        for (t_chord *ch = voice_get_first_chord(r_ob, voice); ch; ch = chord_get_next(ch)) {
            if (ch->onset >= o1 && ch->onset < o2) {
                notation_item_add_to_preselection(r_ob, (t_notation_item *)ch);
            } else if (ch->onset >= o2) {
                break;
            }
        }
    }
    for (t_marker *mk = r_ob->firstmarker; mk; mk = mk->next) {
        if (mk == marker || !marker_is_region(mk)) {
            if (mk->position_ms >= o1 && mk->position_ms < o2) {
                notation_item_add_to_preselection(r_ob, (t_notation_item *)mk);
            } else if (mk->position_ms >= o2) {
                break;
            }
        }
    }
}



void append_marker_onset_or_region_to_llll(t_notation_obj *r_ob, t_marker *marker, t_llll *ll)
{
    if (marker_is_region(marker)) {
        t_llll *subll = llll_get();
        llll_appendsym(subll, _llllobj_sym_region);
        if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE){
            t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
            t_llll *timepointll = get_timepoint_as_llll(r_ob, tp);
            llll_appendllll(subll, timepointll);
            if (marker->r_sym_duration.r_num < 0)
                llll_appendsym(subll, _llllobj_sym_tillnext);
            else
                llll_appendrat(subll, marker->r_sym_duration);
        } else {
            llll_appenddouble(subll, marker->position_ms);
            if (marker->duration_ms < 0)
                llll_appendsym(subll, _llllobj_sym_tillnext);
            else
                llll_appenddouble(subll, marker->duration_ms);
        }
        llll_appendllll(ll, subll);
    } else {
        if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE){
            t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
            t_llll *timepointll = get_timepoint_as_llll(r_ob, tp);
            llll_appendllll(ll, timepointll, 0, WHITENULL_llll);
        } else
            llll_appenddouble(ll, marker->position_ms, 0, WHITENULL_llll);
    }
}


// use marker = NULL to get all markers
t_llll *marker_get_as_llll(t_notation_obj *r_ob, t_marker *marker, char namefirst, char prepend_marker_symbol, e_data_considering_types mode)
{
    t_llll *outlist;
    
    if (marker) {
        outlist = llll_get();
        if (prepend_marker_symbol)
            llll_appendsym(outlist, _llllobj_sym_marker, 0, WHITENULL_llll); // the "marker" symbol in first place
        
        if (namefirst) {
            if (marker->r_it.names->l_size == 0)
                llll_appendsym(outlist, _llllobj_sym_none, 0, WHITENULL_llll);
            else if (marker->r_it.names->l_size == 1 && marker->r_it.names->l_depth == 1)
                llll_appendhatom(outlist, &marker->r_it.names->l_head->l_hatom, 0, WHITENULL_llll);
            else
                llll_appendllll(outlist, get_names_as_llll((t_notation_item *)marker, false), 0, WHITENULL_llll);
        }
        
        append_marker_onset_or_region_to_llll(r_ob, marker, outlist);
        
        if (!namefirst) {
            if (marker->r_it.names->l_size == 0)
                llll_appendsym(outlist, _llllobj_sym_none, 0, WHITENULL_llll);
            else if (marker->r_it.names->l_size == 1 && marker->r_it.names->l_depth == 1)
                llll_appendhatom(outlist, &marker->r_it.names->l_head->l_hatom, 0, WHITENULL_llll);
            else
                llll_appendllll(outlist, get_names_as_llll((t_notation_item *)marker, false), 0, WHITENULL_llll);
        }
        
        llll_appendsym(outlist, marker_role_to_sym(marker->role), 0, WHITENULL_llll);
        if (marker->role != k_MARKER_ROLE_NONE && marker->content)
            llll_appendllll_clone(outlist, marker->content, 0, WHITENULL_llll, NULL);
        
#ifdef BACH_NOTES_HAVE_ID
        if (mode == k_CONSIDER_FOR_UNDO)
            llll_appendllll(outlist, get_ID_as_llll((t_notation_item *)marker));
#endif
    } else {
        outlist = get_markers_as_llll(r_ob, 0, 0, 0, namefirst, k_CONSIDER_FOR_DUMPING, 0, 0);
    }
    return outlist;
}




// if mode == 1 it's clipped between start_ms and end_ms
// if mode == 2 only selected markers are output
// if mode == 3 both things are done
// start_meas_num is used only if for_what = k_CONSIDER_FOR_SUBDUMPING, and bach.score is involved
t_llll *get_markers_as_llll(t_notation_obj *r_ob, char mode, double start_ms, double end_ms, char namefirst, char for_what, long start_meas_num, char keep_ending_markers){
    t_llll *outlist = llll_get();
    t_marker *marker = r_ob->firstmarker;
    llll_appendsym(outlist, _llllobj_sym_markers, 0, WHITENULL_llll);
    for (marker = r_ob->firstmarker; marker; marker = marker->next) {
        if (mode >= 2 && !notation_item_is_selected(r_ob, (t_notation_item *)marker))
            continue;
        
        double ms = marker->position_ms;
        double dur = marker->duration_ms;
        if ((mode % 2 == 0) || (ms >= start_ms && (ms < end_ms || (ms == end_ms && keep_ending_markers)))) {
            
            if (for_what == k_CONSIDER_FOR_SUBDUMPING) {
                ms = ms - start_ms;
                if (dur > 0) {
                    double end = MIN(end_ms, ms + dur);
                    dur = end - ms;
                    if (ms < 0) {
                        dur += ms;
                        ms = 0;
                    }
                }
            }
            t_llll *thisel = llll_get();
            
            if (namefirst)
                llll_append_notation_item_name(thisel, (t_notation_item *)marker);
            
            if (marker_is_region(marker)) {
                t_llll *subll = llll_get();
                llll_appendsym(subll, _llllobj_sym_region);
                if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE && for_what != k_CONSIDER_FOR_SCORE2ROLL){
                    t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
                    if (for_what == k_CONSIDER_FOR_SUBDUMPING)
                        tp.measure_num -= start_meas_num;
                    t_llll *tp_as_llll = get_timepoint_as_llll(r_ob, tp);
                    llll_appendllll(subll, tp_as_llll);
                    t_rational sym_dur = marker->r_sym_duration;
                    // TO DO: clip sym_dur
                    if (sym_dur.r_num < 0)
                        llll_appendsym(subll, _llllobj_sym_tillnext);
                    else
                        llll_appendrat(subll, sym_dur);
                } else {
                    llll_appenddouble(subll, ms);
                    if (dur < 0)
                        llll_appendsym(subll, _llllobj_sym_tillnext);
                    else
                        llll_appenddouble(subll, dur);
                }
                llll_appendllll(thisel, subll);
            } else {
                if (marker->attach_to == k_MARKER_ATTACH_TO_MEASURE && for_what != k_CONSIDER_FOR_SCORE2ROLL){
                    t_timepoint tp = measure_attached_marker_to_timepoint(r_ob, marker);
                    if (for_what == k_CONSIDER_FOR_SUBDUMPING)
                        tp.measure_num -= start_meas_num;
                    t_llll *tp_as_llll = get_timepoint_as_llll(r_ob, tp);
                    llll_appendllll(thisel, tp_as_llll, 0, WHITENULL_llll);
                } else {
                    llll_appenddouble(thisel, ms);
                }
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


void change_marker_onset_from_lexpr_or_llllelem(t_notation_obj *r_ob, t_marker *marker, t_lexpr *lexpr, t_llllelem *elem){
    if (lexpr) {
        marker->attach_to = k_MARKER_ATTACH_TO_MS;
        change_double(r_ob, &marker->position_ms, lexpr, NULL, false, (t_notation_item *)marker);
    } else if (elem) {
        if (is_hatom_number(&elem->l_hatom)) {
            marker->attach_to = k_MARKER_ATTACH_TO_MS;
            change_double(r_ob, &marker->position_ms, lexpr, elem, false, (t_notation_item *)marker);
            //            marker->position_ms = hatom_getdouble(&elem->l_hatom);
        } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
            t_llll *this_llll = hatom_getllll(&elem->l_hatom);
            t_timepoint tp = llll_to_timepoint(r_ob, this_llll, NULL, false);
            marker->attach_to = k_MARKER_ATTACH_TO_MEASURE;
            t_scorevoice *voice = (t_scorevoice *)voice_get_nth_safe(r_ob, tp.voice_num);
            t_measure *meas = measure_get_nth(voice, tp.measure_num);
            if (meas) {
                marker->measure_attach_ID = meas->r_it.ID;
                marker->r_sym_pim_attach = tp.pt_in_measure;
            }
        }
    }
}

void marker_llllelem_to_onset_and_region_properties(t_notation_obj *r_ob, t_llllelem *el, double *onset_ms, double *dur_ms, t_timepoint *onset_timepoint, t_rational *symdur, char *attach_to)
{
    *attach_to = k_MARKER_ATTACH_TO_MS;
    if (el && is_hatom_number(&el->l_hatom)) {
        *onset_ms = hatom_getdouble(&el->l_hatom);
    } else if (el && hatom_gettype(&el->l_hatom) == H_LLLL) {
        t_llll *ll = hatom_getllll(&el->l_hatom);
        if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM && hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_region) {
            // region
            if (ll->l_head->l_next && is_hatom_number(&ll->l_head->l_next->l_hatom)) {
                *onset_ms = hatom_getdouble(&ll->l_head->l_next->l_hatom);
                if (ll->l_head->l_next->l_next && hatom_getsym(&ll->l_head->l_next->l_next->l_hatom) == _llllobj_sym_tillnext)
                    *dur_ms = -1;
                else if (ll->l_head->l_next->l_next && is_hatom_number(&ll->l_head->l_next->l_next->l_hatom))
                    *dur_ms = hatom_getdouble(&ll->l_head->l_next->l_next->l_hatom);
            } else if (ll->l_head->l_next && hatom_gettype(&ll->l_head->l_next->l_hatom) == H_LLLL) {
                if (r_ob)
                    *onset_timepoint = llll_to_timepoint(r_ob, hatom_getllll(&ll->l_head->l_next->l_hatom), NULL, false);
                if (ll->l_head->l_next->l_next && hatom_getsym(&ll->l_head->l_next->l_next->l_hatom) == _llllobj_sym_tillnext)
                    *symdur = long2rat(-1);
                else if (ll->l_head->l_next->l_next && is_hatom_number(&ll->l_head->l_next->l_next->l_hatom))
                    *symdur = hatom_getrational(&ll->l_head->l_next->l_next->l_hatom);
                *attach_to = k_MARKER_ATTACH_TO_MEASURE;
            }
        } else {
            if (r_ob)
                *onset_timepoint = llll_to_timepoint(r_ob, ll, NULL, false);
            *attach_to = k_MARKER_ATTACH_TO_MEASURE;
        }
    }
}

void set_marker_from_llll(t_notation_obj *r_ob, t_marker *marker, t_llll *this_llll)
{
    double ms = 0, dur = 0;
    char attach_to = k_MARKER_ATTACH_TO_MS;
    e_marker_roles mkrole = k_MARKER_ROLE_NONE;
    t_timepoint tp = build_timepoint(0, long2rat(0));
    t_rational symdur = long2rat(0);
    t_llll *mknames = NULL;
    t_llll *content = NULL;
    char has_explicit_name = false;
    
    unsigned long forced_marker_ID = notation_item_get_ID_from_llll(this_llll);
    
    if (this_llll && this_llll->l_head)
        marker_llllelem_to_onset_and_region_properties(r_ob, this_llll->l_head, &ms, &dur, &tp, &symdur, &attach_to);
    
    if (this_llll && this_llll->l_head && this_llll->l_head->l_next) {
        has_explicit_name = true;
        mknames = get_names_from_llllelem(r_ob, this_llll->l_head->l_next);
    }
    
    if (this_llll && this_llll->l_head && this_llll->l_head->l_next && this_llll->l_head->l_next->l_next && hatom_gettype(&this_llll->l_head->l_next->l_next->l_hatom) == H_SYM)
        mkrole = sym_to_marker_role(hatom_getsym(&this_llll->l_head->l_next->l_next->l_hatom));
    if (this_llll && this_llll->l_head && this_llll->l_head->l_next && this_llll->l_head->l_next->l_next && this_llll->l_head->l_next->l_next->l_next && hatom_gettype(&this_llll->l_head->l_next->l_next->l_next->l_hatom) == H_LLLL) {
        content = llll_clone(hatom_getllll(&this_llll->l_head->l_next->l_next->l_next->l_hatom));
    }
    
    marker->position_ms = ms;
    marker->duration_ms = dur;
    marker->attach_to = attach_to;
    
    marker->r_sym_pim_attach = long2rat(0);
    if (attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_voice *voice = voice_get_nth_safe(r_ob, tp.voice_num);
        if (voice) {
            t_measure *meas = measure_get_nth((t_scorevoice *)voice, tp.measure_num);
            if (meas) {
                marker->measure_attach_ID = meas->r_it.ID;
                marker->r_sym_pim_attach = tp.pt_in_measure;
                marker->position_ms = timepoint_to_ms(r_ob, tp, tp.voice_num);
                marker->r_sym_duration = symdur;
            }
        }
    }
    
    marker->role = mkrole;
    marker->content = content;
    
    if (has_explicit_name)
        notation_item_set_names_from_llll(r_ob, (t_notation_item *)marker, mknames);
    
    if (forced_marker_ID && forced_marker_ID != marker->r_it.ID){
        shashtable_chuck_thing(r_ob->IDtable, marker->r_it.ID);
        shashtable_insert_with_key(r_ob->IDtable, marker, forced_marker_ID, 1);
        marker->r_it.ID = forced_marker_ID;
    }
    
    llll_free(mknames);
}

t_marker *add_marker_from_llll(t_notation_obj *r_ob, t_llll *this_llll)
{
    t_marker *res = NULL;
    double ms = 0, dur = 0;
    char attach_to = k_MARKER_ATTACH_TO_MS;
    e_marker_roles mkrole = k_MARKER_ROLE_NONE;
    t_timepoint tp = build_timepoint(0, long2rat(0));
    t_rational symdur = long2rat(0);
    t_llll *mknames = NULL;
    t_llll *content = NULL;
    char has_explicit_name = false;
    
    unsigned long forced_marker_ID = notation_item_get_ID_from_llll(this_llll);
    
    if (this_llll && this_llll->l_head)
        marker_llllelem_to_onset_and_region_properties(r_ob, this_llll->l_head, &ms, &dur, &tp, &symdur, &attach_to);
    
    if (this_llll->l_head && this_llll->l_head->l_next) {
        has_explicit_name = true;
        mknames = get_names_from_llllelem(r_ob, this_llll->l_head->l_next);
    }
    
    if (this_llll->l_head && this_llll->l_head->l_next && this_llll->l_head->l_next->l_next && hatom_gettype(&this_llll->l_head->l_next->l_next->l_hatom) == H_SYM)
        mkrole = sym_to_marker_role(hatom_getsym(&this_llll->l_head->l_next->l_next->l_hatom));
    if (this_llll->l_head && this_llll->l_head->l_next && this_llll->l_head->l_next->l_next && this_llll->l_head->l_next->l_next->l_next && hatom_gettype(&this_llll->l_head->l_next->l_next->l_next->l_hatom) == H_LLLL) {
        content = llll_clone(hatom_getllll(&this_llll->l_head->l_next->l_next->l_next->l_hatom));
    }
    
    if (!has_explicit_name)
        mknames = find_unused_marker_names(r_ob, NULL, NULL);
    
    res = add_marker(r_ob, mknames, ms, tp, attach_to, mkrole, content, dur, symdur, forced_marker_ID);
    llll_free(mknames);
    return res;
}

t_marker *add_marker_from_llllelem(t_notation_obj *r_ob, t_llllelem *elem)
{
    t_marker *res = NULL;
    if (hatom_gettype(&elem->l_hatom) == H_DOUBLE || hatom_gettype(&elem->l_hatom) == H_LONG) {
        t_llll *names = find_unused_marker_names(r_ob, NULL, NULL);
        res = add_marker(r_ob, names, hatom_getdouble(&elem->l_hatom), build_timepoint(0, long2rat(0)), k_MARKER_ATTACH_TO_MS, k_MARKER_ROLE_NONE, NULL, 0, long2rat(0), 0);
        llll_free(names);
    } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
        res = add_marker_from_llll(r_ob, hatom_getllll(&elem->l_hatom));
    }
    return res;
}

// beware: destructive!!
void set_markers_from_llll(t_notation_obj *r_ob, t_llll* markers, char add_mode, char select, char add_undo_ticks)
{
    if (markers) {
        t_llllelem *elem;
        if (select)
            lock_general_mutex(r_ob);
        lock_markers_mutex(r_ob);
        
        if (!add_mode && add_undo_ticks)
            undo_tick_create_for_header(r_ob, k_HEADER_MARKERS);
        
        if (!add_mode && r_ob->firstmarker)
            clear_all_markers(r_ob);
        
        for (elem = markers->l_head; elem; elem = elem->l_next)  {
            t_marker *mk = add_marker_from_llllelem(r_ob, elem);
            if (add_mode && mk)
                undo_tick_create_for_notation_item(r_ob, (t_notation_item *)mk, k_UNDO_MODIFICATION_TYPE_REMOVE, _llllobj_sym_state);
            if (select)
                notation_item_add_to_preselection(r_ob, (t_notation_item *)mk);
        }
        
        unlock_markers_mutex(r_ob);
        if (select) {
            unlock_general_mutex(r_ob);
            move_preselecteditems_to_selection(r_ob, k_SELECTION_MODE_FORCE_SELECT, false, false);
        }
    }
}






// *************
// MARKERS
// *************

long compare_markers(void *data, t_llllelem *a, t_llllelem *b){
    if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
        t_llll *a_llll = hatom_getllll(&a->l_hatom);
        t_llll *b_llll = hatom_getllll(&b->l_hatom);
        if (hatom_gettype(&a_llll->l_head->l_hatom) == H_LLLL && hatom_gettype(&b_llll->l_head->l_hatom) == H_LLLL) {
            t_llll *pos_a_llll = hatom_getllll(&a_llll->l_head->l_hatom);
            t_llll *pos_b_llll = hatom_getllll(&b_llll->l_head->l_hatom);
            if (pos_a_llll->l_head && pos_b_llll->l_head && hatom_getdouble(&pos_a_llll->l_head->l_hatom) <= hatom_getdouble(&pos_b_llll->l_head->l_hatom))
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

t_llllelem *get_marker_ms_llllelem(t_llllelem *marker){
    if (hatom_gettype(&marker->l_hatom) == H_LLLL) {
        t_llll *marker_llll = hatom_getllll(&marker->l_hatom);
        if (marker_llll && marker_llll->l_head && hatom_gettype(&marker_llll->l_head->l_hatom) == H_LLLL) {
            t_llll *pos_marker_llll = hatom_getllll(&marker_llll->l_head->l_hatom);
            if (pos_marker_llll && pos_marker_llll->l_head)
                return pos_marker_llll->l_head;
        }
    }
    return NULL;
}

char *atom_to_buffer(t_atom *atom)
{
    long size;
    char *buf = NULL;
    atom_gettext_debug(1, atom, &size, &buf, 0);
    return buf;
}

void recalculate_marker_name_uwidth(t_notation_obj *r_ob, t_marker *marker)
{
    if (marker) {
        double width = 0, height = 0;
        t_jfont *jf_text_markers = jfont_create_debug(r_ob->markers_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, r_ob->markers_font_size);
        if (marker->role == k_MARKER_ROLE_NONE) {
            if (marker->r_it.names->l_size > 0) {
                char buf[1000];
                get_names_as_text(marker->r_it.names, buf, 1000);
                jfont_text_measure(jf_text_markers, buf, &width, &height);
            }
        } else {
            if (marker->content) {
                char *buf = NULL;
                llll_to_text_buf(marker->content, &buf, 0, 2, 0, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
                jfont_text_measure(jf_text_markers, buf, &width, &height);
                bach_freeptr(buf);
            }
        }
        marker->name_uwidth = width;
        jfont_destroy_debug(jf_text_markers);
    }
}

t_marker *build_marker(t_notation_obj *r_ob, t_llll *names, double ms, t_timepoint tp, char attach_to, e_marker_roles role, t_llll *content, double dur, t_rational symdur){
    t_marker *marker = (t_marker *) bach_newptrclear(sizeof(t_marker));
    notation_item_init(&marker->r_it, k_MARKER);
    
    change_notation_item_names(r_ob, &marker->r_it, names, false);
    //    llll_free(marker->r_it.names);
    //    marker->r_it.names = llll_clone(names);
    
    marker->position_ms = ms;
    marker->name_uwidth = 0;
    marker->need_update_name_uwidth = 0;
    marker->attach_to = attach_to;
    marker->role = role;
    marker->content = content;
    marker->name_painted_direction = 0;
    marker->measure_attach_ID = 0;
    marker->name_line = 0;
    marker->r_sym_pim_attach = long2rat(0);
    marker->duration_ms = dur;
    marker->r_sym_duration = symdur;

    if (attach_to == k_MARKER_ATTACH_TO_MEASURE) {
        t_voice *voice = voice_get_nth_safe(r_ob, tp.voice_num);
        if (voice) {
            t_measure *meas = measure_get_nth((t_scorevoice *)voice, tp.measure_num);
            if (meas) {
                marker->measure_attach_ID = meas->r_it.ID;
                marker->r_sym_pim_attach = tp.pt_in_measure;
                marker->position_ms = timepoint_to_ms(r_ob, tp, tp.voice_num);
            }
        }
    }
    
    marker->ux_difference_with_mousedown_marker = 0;
    return marker;
}

void insert_marker(t_notation_obj *r_ob, t_marker *marker, unsigned long force_ID){
    t_marker *after_this_marker = r_ob->lastmarker;
    if (r_ob->firstmarker) { // not at the beginning
        // gotta find where to put it
        t_marker *temp = r_ob->firstmarker;
        while (temp) {
            if (temp->position_ms > marker->position_ms) {
                after_this_marker = temp->prev;
                break;
            }
            temp = temp->next;
        }
    }
    
    if (r_ob->firstmarker) { // not at the beginning
        if (after_this_marker) {
            if (after_this_marker->next) { // insert between these
                after_this_marker->next->prev = marker;
                marker->next = after_this_marker->next;
                marker->prev = after_this_marker;
                after_this_marker->next = marker;
            } else { // insert at the end
                marker->next = NULL;
                marker->prev = after_this_marker;
                after_this_marker->next = marker;
                r_ob->lastmarker = marker;
            }
        } else { // at the beginning
            marker->prev = NULL;
            marker->next = r_ob->firstmarker;
            r_ob->firstmarker->prev = marker;
            r_ob->firstmarker = marker;
        }
    } else { // no markers in the voices yet
        marker->next = NULL;
        marker->prev = NULL;
        r_ob->firstmarker = marker;
        r_ob->lastmarker = marker;
    }
    
#ifdef BACH_MARKERS_HAVE_ID
    if (force_ID > 0) {
        shashtable_insert_with_key(r_ob->IDtable, marker, force_ID, 1);
        marker->r_it.ID = force_ID;
    } else
        marker->r_it.ID = shashtable_insert(r_ob->IDtable, marker);
#endif
    
    // increase the # of markers
    r_ob->num_markers++;
}

// build and insert
t_marker *add_marker(t_notation_obj *r_ob, t_llll *names, double ms, t_timepoint tp, char attach_to, e_marker_roles role, t_llll *content, double dur, t_rational symdur, unsigned long force_ID)
{
    t_marker *marker = build_marker(r_ob, names, ms, tp, attach_to, role, content, dur, symdur);
    if (marker) {
        insert_marker(r_ob, marker, force_ID);
        marker->need_update_name_uwidth = r_ob->need_update_markers_uwidth = true;
        //        recalculate_marker_name_uwidth(r_ob, marker);
    }
    return marker;
}


char delete_marker_by_llllelem(t_notation_obj *r_ob, t_llllelem *marker){
    if (marker) {
        if (!NOGOOD(marker)) {
            llll_destroyelem(marker);
        } else
            object_error((t_object *) r_ob, "Marker is a wrong object!");
        return 1;
    }
    return 0;
}

void marker_check_dependencies_before_deleting_it(t_notation_obj *r_ob, t_marker *marker){
    
    if (notation_item_is_selected(r_ob, (t_notation_item *)marker))
        notation_item_delete_from_selection(r_ob, (t_notation_item *)marker);
    
    if (notation_item_is_preselected(r_ob, (t_notation_item *)marker))
        notation_item_delete_from_preselection(r_ob, (t_notation_item *)marker);
    
    if (r_ob->m_inspector.active_bach_inspector_obj_type == k_MARKER && r_ob->m_inspector.active_bach_inspector_item == marker)
        close_bach_inspector(r_ob, &r_ob->m_inspector);
    
    if (r_ob->playing){
        if (r_ob->scheduled_item == (t_notation_item *)marker) {
            r_ob->scheduled_item = NULL;
            check_correct_scheduling(r_ob, false);
        }
        
        if (r_ob->marker_play_cursor == marker)
            r_ob->marker_play_cursor = marker->prev;
    }
}


void delete_marker(t_notation_obj *r_ob, t_marker *marker){
    if (marker){
        
        marker_check_dependencies_before_deleting_it(r_ob, marker);
        
        r_ob->num_markers --;
        if (marker->prev) { // not the first marker
            if (marker->next) { // not the last marker
                marker->prev->next = marker->next;
                marker->next->prev = marker->prev;
            } else { // last marker
                marker->prev->next = NULL;
                r_ob->lastmarker = marker->prev;
            }
        } else { // first marker
            if (marker->next) { // some tempi remain
                marker->next->prev = NULL;
                r_ob->firstmarker = marker->next;
            } else { // there was just 1 marker
                r_ob->firstmarker = NULL;
                r_ob->lastmarker = NULL;
                r_ob->num_markers = 0;
            }
        }
        marker_free(r_ob, marker);
    }
}


char marker_delete_by_name(t_notation_obj *r_ob, t_llll *names, char add_undo_ticks){
    char changed = false;
    t_marker *marker;
    for (marker = r_ob->firstmarker; marker; marker = marker->next) {
        if (are_all_names_contained(names, marker->r_it.names)) {
            changed = true;
            undo_tick_create_for_notation_item(r_ob, (t_notation_item *)marker, k_UNDO_MODIFICATION_TYPE_INSERT, _llllobj_sym_state);
            delete_marker(r_ob, marker);
            break;
        }
    }
    return changed;
}

// get the FIRST marker having as name a given name (or a set of given names)
t_marker *markername2marker(t_notation_obj *r_ob, t_llll *names){
    t_marker *marker;
    for (marker = r_ob->firstmarker; marker; marker = marker->next)
        if (are_all_names_contained(names, marker->r_it.names))
            return marker;
    return NULL;
}




long change_marker_names(t_notation_obj *r_ob, t_marker *marker, t_llll *new_names)
{
    if (marker) {
        if (are_names_equal(marker->r_it.names, new_names))
            return 0;
        change_notation_item_names(r_ob, (t_notation_item *)marker, new_names, false);
        marker->need_update_name_uwidth = r_ob->need_update_markers_uwidth = true;
        //        recalculate_marker_name_uwidth(r_ob, marker);
        return 1;
    }
    return 0;
}


char check_markers_order(t_notation_obj *r_ob){
    char changed = false;
    t_marker *curr_mk = r_ob->firstmarker;
    while(curr_mk && curr_mk->next) {
        if (curr_mk->next->position_ms < curr_mk->position_ms){ // we have to swap them
            if (curr_mk->prev){
                if (curr_mk->next->next) { // swap between two inner markers
                    t_marker *temp1, *temp2, *temp3, *temp4;
                    temp1 = curr_mk->prev;
                    temp2 = curr_mk;
                    temp3 = curr_mk->next;
                    temp4 = curr_mk->next->next;
                    curr_mk->next->next->prev = temp2;
                    curr_mk->prev->next = temp3;
                    curr_mk->next->next = temp2;
                    curr_mk->next->prev = temp1;
                    curr_mk->next = temp4;
                    curr_mk->prev = temp3;
                    changed = true;
                } else { // swap between the last two curr_mk
                    t_marker *temp1, *temp2, *temp3, *temp4;
                    temp1 = curr_mk->prev;
                    temp2 = curr_mk;
                    temp3 = curr_mk->next;
                    temp4 = NULL;
                    curr_mk->prev->next = temp3;
                    curr_mk->next->next = temp2;
                    curr_mk->next->prev = temp1;
                    curr_mk->next = NULL;
                    curr_mk->prev = temp3;
                    r_ob->lastmarker = temp2;
                    changed = true;
                }
            } else { // swap between 1st and 2nd note
                t_marker *temp1, *temp2, *temp3, *temp4;
                temp1 = NULL;
                temp2 = curr_mk;
                temp3 = curr_mk->next;
                temp4 = curr_mk->next->next;
                if (!temp4) // we have just 2 notes:
                    r_ob->lastmarker = temp2;
                else
                    curr_mk->next->next->prev = temp2;
                curr_mk->next->next = temp2;
                curr_mk->next->prev = NULL;
                curr_mk->next = temp4;
                curr_mk->prev = temp3;
                r_ob->firstmarker = temp3;
                changed = true;
            }
            //... and to restart to check from the beginning
            curr_mk = r_ob->firstmarker;
        } else
            curr_mk = curr_mk->next;
    }
    
    return changed;
}

t_timepoint measure_attached_marker_to_timepoint(t_notation_obj *r_ob, t_marker *marker){
    t_timepoint tp = build_timepoint(0, long2rat(0));
    if (marker->measure_attach_ID > 0) {
        t_notation_item *it = notation_item_retrieve_from_ID(r_ob, marker->measure_attach_ID);
        if (it && it->type == k_MEASURE) {
            t_measure *meas = (t_measure *)it;
            if (meas){
                tp.measure_num = meas->measure_number;
                tp.voice_num = meas->voiceparent->v_ob.number;
                tp.pt_in_measure = marker->r_sym_pim_attach;
            }
        }
    }
    return tp;
}


t_symbol *marker_role_to_sym(e_marker_roles marker_role){
    switch (marker_role) {
        case k_MARKER_ROLE_NONE:
            return _llllobj_sym_none;
            break;
        case k_MARKER_ROLE_TEMPO:
            return _llllobj_sym_tempo;
            break;
        case k_MARKER_ROLE_MEASURE_BARLINE:
            return _llllobj_sym_barline;
            break;
        case k_MARKER_ROLE_MEASURE_DIVISION:
            return _llllobj_sym_division;
            break;
        case k_MARKER_ROLE_MEASURE_SUBDIVISION:
            return _llllobj_sym_subdivision;
            break;
        case k_MARKER_ROLE_TIME_SIGNATURE:
            return _llllobj_sym_timesig;
            break;
    }
    return _llllobj_sym_none;
}

e_marker_roles sym_to_marker_role(t_symbol *s){
    if (s == _llllobj_sym_none)
        return k_MARKER_ROLE_NONE;
    else if (s == _llllobj_sym_tempo)
        return k_MARKER_ROLE_TEMPO;
    else if (s == _llllobj_sym_timesig)
        return k_MARKER_ROLE_TIME_SIGNATURE;
    else if (s == _llllobj_sym_measure || s == _llllobj_sym_barline)
        return k_MARKER_ROLE_MEASURE_BARLINE;
    else if (s == _llllobj_sym_division)
        return k_MARKER_ROLE_MEASURE_DIVISION;
    else if (s == _llllobj_sym_subdivision)
        return k_MARKER_ROLE_MEASURE_SUBDIVISION;
    return k_MARKER_ROLE_NONE;
}

void change_marker_role(t_notation_obj *r_ob, t_marker *marker, e_marker_roles new_role, t_llll *new_value)
{
    lock_markers_mutex(r_ob);
    marker->role = new_role;
    if (marker->content)
        llll_free(marker->content);
    if (new_value)
        marker->content = llll_clone(new_value);
    else
        marker->content = NULL;
    unlock_markers_mutex(r_ob);
    notationobj_invalidate_notation_static_layer_and_redraw((t_notation_obj *)r_ob);
}

void change_marker_ms(t_notation_obj *r_ob, t_marker *marker, double new_ms, char delta_mode, char also_check_sorting){
    lock_markers_mutex(r_ob);
    if (marker) {
        double old_ms = marker->position_ms;
        marker->position_ms = MAX(delta_mode ? old_ms + new_ms : new_ms, 0);
        if (also_check_sorting)
            check_markers_order(r_ob);
    }
    unlock_markers_mutex(r_ob);
}




char change_selection_role(t_notation_obj *r_ob, t_symbol *new_role, t_llll *new_value, char lambda)
{
    char res = 0;
    t_notation_item *curr_it;
    
    curr_it = r_ob->firstselecteditem;
    
    curr_it = notation_item_get_first_selected_account_for_lambda(r_ob, lambda);
    
    e_marker_roles role_ok = sym_to_marker_role(new_role);
    
    while (curr_it) { // cycle on the selected items
        if (curr_it->type == k_MARKER) {
            if (!is_editable(r_ob, k_MARKER, k_MODIFICATION_GENERIC)) continue;
            change_marker_role(r_ob, ((t_marker *)curr_it), role_ok, new_value);
        }
        
        curr_it = lambda ? NULL : curr_it->next_selected;
    }
    
    notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
    return res;
}



void notationobj_role(t_notation_obj *r_ob, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *args = llllobj_parse_llll((t_object *) r_ob, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    if (args && args->l_head && hatom_gettype(&args->l_head->l_hatom) == H_SYM) {
        t_llll *rolevalue = NULL;
        if (args->l_head->l_next && hatom_gettype(&args->l_head->l_next->l_hatom) == H_LLLL)
            rolevalue = hatom_getllll(&args->l_head->l_next->l_hatom);
        undo_tick_create_for_header(r_ob, k_HEADER_MARKERS);
        change_selection_role(r_ob, hatom_getsym(&args->l_head->l_hatom), rolevalue, s == _llllobj_sym_lambda);
        handle_change_if_there_are_dangling_undo_ticks(r_ob, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_CHANGE_ROLES);
    }
    llll_free(args);
}

