/*
 *  notation_export.c
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
	notation_dynamicsommons.c - function handling dynamics
*/

#include "foundation/bach.h"
#include "notation/notation.h" // header with all the structures for the notation objects


void get_filename_extension(char *filename, char *ext, char also_truncate_filename)
{
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        ext[0] = 0;
    else {
        strncpy_zero(ext, dot + 1, MAX_FILENAME_CHARS);
        if (also_truncate_filename)
            *dot = 0;
    }
}


double get_tuttipoint_range_uwidth(t_notation_obj *r_ob, t_tuttipoint *tpt1, t_tuttipoint *tpt2)
{
    t_tuttipoint *temp;
    double w = 0;
    for (temp = tpt1; temp; temp = temp->next) {
        w += temp->width_ux;
        if (temp == tpt2)
            break;
    }
    return w;
}

double tuttipoint_adapt(t_notation_obj *r_ob, t_tuttipoint *start, t_tuttipoint **end, double expected_window_uwidth)
{
    double ratio = get_tuttipoint_range_uwidth(r_ob, start, *end)/expected_window_uwidth;
    while (ratio < 1.) {
        // we can maybe add more stuff in the window
        double temp_ratio = get_tuttipoint_range_uwidth(r_ob, start, (*end)->next)/expected_window_uwidth;
        if (temp_ratio > ratio && temp_ratio < 1./ratio) { // accepted!
            *end = (*end)->next;
            ratio = temp_ratio;
        } else
            break;
    }

    while (ratio > 1.) {
        // we can maybe delete stuff from the window
        if ((*end)->prev == start)
            break;
        
        double temp_ratio = get_tuttipoint_range_uwidth(r_ob, start, (*end)->prev)/expected_window_uwidth;
        if (temp_ratio < ratio && temp_ratio > 1./ratio) { // accepted!
            *end = (*end)->prev;
            ratio = temp_ratio;
        } else
            break;
    }
    
    return ratio;
}


t_llll *get_tuttipoint_system_layout(t_notation_obj *r_ob, double expected_window_uwidth)
{
    t_llll *out = llll_get();
    t_tuttipoint *from = r_ob->firsttuttipoint, *to = r_ob->firsttuttipoint;
    
    while (from) {
        
        double ratio = tuttipoint_adapt(r_ob, from, &to, expected_window_uwidth);

        if (ratio > 1.618) { // ratio too high
            // split this tuttipoint into many  parts
            
            long num_parts = round(ratio);
            double diff = to->offset_ux + to->width_ux - from->offset_ux;
            for (long i = 0; i < num_parts; i++) {
                t_llll *this_ll = llll_get();
                llll_appendobj(this_ll, from);
                llll_appendobj(this_ll, to);
                llll_appendlong(this_ll, num_parts);
                llll_appendlong(this_ll, i+1);
                llll_appenddouble(this_ll, from->offset_ux);
                llll_appenddouble(this_ll, from->offset_ux + i * diff/num_parts);
                llll_appendllll(out, this_ll);
            }
//        } else if (ratio < 0.618) {
            // ratio too low
        } else {
            t_llll *this_ll = llll_get();
            llll_appendobj(this_ll, from);
            llll_appendobj(this_ll, to);
            llll_appendlong(this_ll, 1);
            llll_appendlong(this_ll, 1);
            llll_appenddouble(this_ll, from->offset_ux);
            llll_appenddouble(this_ll, to->offset_ux + to->width_ux);
            llll_appendllll(out, this_ll);
        }
        
        if (to) {
            from = to->next;
            to = from;
        } else {
            from = to = NULL;
        }
    }
    
    return out;
}


t_max_err notationobj_dowriteimage(t_notation_obj *r_ob, t_symbol *s, long ac, t_atom *av)
{
    t_llll *arguments = (t_llll *) atom_getobj(av);
    char ok = true;
    t_symbol *view = gensym("line");
    long dpi = 72, must_cleanup = 1, fadepredomain = -1, fitmeasures = 1, onsetindomain = 0, adaptwidth = 0;
    t_symbol *filename_sym = NULL, *type_sym = NULL;
    double mspersystem = r_ob->domain, uxperline = r_ob->domain_ux;
    t_llll *tuttipoint_system_layout = NULL;
    double new_inner_width = 0, postdomain_uwidth = -1;
    long systemvshift_pixels = 0;
    
    llll_parseargs_and_attrs_destructive((t_object *) r_ob, arguments, "sssididiiiid",
                                         _sym_filename, &filename_sym,
                                         _sym_type, &type_sym,
                                         gensym("view"), &view,         // can be one of the following: "raw", "line", "multiline", "scroll"
                                         gensym("dpi"), &dpi,
                                         gensym("mspersystem"), &mspersystem,
                                         gensym("adaptwidth"), &adaptwidth,
                                         gensym("pixelpersystem"), &uxperline,
                                         gensym("systemvshift"), &systemvshift_pixels,
                                         gensym("fitmeasures"), &fitmeasures,
                                         gensym("fadedomain"), &fadepredomain,
                                         gensym("onsetindomain"), &onsetindomain,
                                         gensym("postdomainpad"), &postdomain_uwidth
                                         );
    
    if (view != gensym("raw") && view != gensym("line") && view != gensym("multiline") && view != gensym("scroll")) {
        object_warn((t_object *)r_ob, "Unknown view mode!");
        view = gensym("line");
    }
    
    must_cleanup = (view != gensym("raw"));
    r_ob->exporting_image = must_cleanup;

    if (fadepredomain < 0)
        fadepredomain = (view == gensym("raw") ? r_ob->fade_predomain : 0);

    if (postdomain_uwidth < 0)
        postdomain_uwidth = (view == gensym("raw") || r_ob->obj_type == k_NOTATION_OBJECT_SCORE ? 0 : 10); // defaults for postdomain pad

    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_destroyelem(arguments->l_head);
    }
    
    if (!filename_sym) {
        t_fourcc filetype = 'PICT', outtype;
        char filename_temp[MAX_PATH_CHARS];
        char full_filename_temp[MAX_PATH_CHARS];
        full_filename_temp[0] = 0;
        short path = 0;
        strncpy_zero(filename_temp, "Untitled.png", MAX_PATH_CHARS);

        short c = saveasdialog_extended(filename_temp, &path, &outtype, &filetype, 1);
        if (c == 0) {
            path_topotentialname(path, filename_temp, full_filename_temp, 0);
            if (full_filename_temp[0])
                filename_sym = gensym(full_filename_temp);
        }
    }
    
    if (filename_sym) {
        char new_temp_filename[MAX_FILENAME_CHARS];
        char extension[MAX_FILENAME_CHARS];
        get_filename_extension(filename_sym->s_name, extension, false);
        if (strcmp_case_insensitive(extension, "png") != 0) {
            snprintf_zero(new_temp_filename, MAX_FILENAME_CHARS, "%s.png", filename_sym->s_name);
            filename_sym = gensym(new_temp_filename);
        }
    }

    if (!type_sym) {
        if (filename_sym) {
            char extension[MAX_FILENAME_CHARS];
            get_filename_extension(filename_sym->s_name, extension, false);
            if (strcmp_case_insensitive(extension, "png") == 0)
                type_sym = gensym("png");
            else if (strcmp_case_insensitive(extension, "jpg") == 0 || strcmp_case_insensitive(extension, "jpeg") == 0)
                type_sym = gensym("jpeg");
            else
                type_sym = gensym("png");
        }
    }

    if (filename_sym) {
        // getting output path
        short path = path_getdefault();
        char filename[MAX_FILENAME_CHARS];
        char filename_no_ext[MAX_FILENAME_CHARS];
        char extension[MAX_FILENAME_CHARS];
        filename[0] = 0;
        path_frompotentialpathname(filename_sym->s_name, &path, filename);
        if (!filename[0])
            snprintf(filename, MAX_FILENAME_CHARS, "%s", filename_sym->s_name);
        strncpy_zero(filename_no_ext, filename, MAX_FILENAME_CHARS);
        get_filename_extension(filename_no_ext, extension, true);
        
        
        //    lock_general_mutex((t_notation_obj *)x);
        long w, h;
        long num_shots = 1;
        
        long show_hscrollbar_prev = r_ob->show_hscrollbar, show_vscrollbar_prev = r_ob->show_vscrollbar;
        long legend_prev = r_ob->legend;
        double inner_width_prev = r_ob->inner_width, inner_height_prev = r_ob->inner_height;
        long show_border_prev = r_ob->show_border;
        double length_ms_prev = r_ob->length_ms;
        double length_ux_prev = r_ob->length_ux;
        double screen_ms_start_prev = r_ob->screen_ms_start;
        long fade_predomain_prev = r_ob->fade_predomain;
        long onsetindomain_prev = r_ob->onset_in_domain;
        double postdomain_prev = r_ob->postdomain_width;
        double zoom_x_prev = r_ob->zoom_x;
        char send_undo_redo_bang_prev = r_ob->send_undo_redo_bang;

        r_ob->fade_predomain = fadepredomain;
        r_ob->postdomain_width = postdomain_uwidth * r_ob->zoom_y;
        r_ob->onset_in_domain = onsetindomain;
        
        if (must_cleanup) {
            close_slot_window(r_ob);
            r_ob->show_hscrollbar = r_ob->show_vscrollbar = 0;
            r_ob->legend = 0;
            r_ob->show_border = false;
            
            if (view == gensym("line")) {
                if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                    r_ob->inner_width = MAX(inner_width_prev, deltaonset_to_deltaxpixels(r_ob, r_ob->length_ms) + get_predomain_width_pixels(r_ob));
                    r_ob->inner_height = notationobj_get_supposed_standard_uheight(r_ob) * r_ob->zoom_y;
                } else { // k_NOTATION_OBJECT_SCORE
                    r_ob->inner_width = deltauxpixels_to_deltaxpixels(r_ob, r_ob->length_ux - CONST_SCORE_ADDITIONALS_UX_AT_THE_END) + get_predomain_width_pixels(r_ob);
                    r_ob->inner_height = notationobj_get_supposed_standard_uheight(r_ob) * r_ob->zoom_y;
                }
            } else if (view == gensym("scroll") || view == gensym("page") || view == gensym("multiline")) {
                if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                    if (mspersystem != r_ob->domain && mspersystem > 0) {
                        // either we change the inner_width or we change the zoom factor.
                        if (adaptwidth) {
                            r_ob->inner_width = r_ob->postdomain_width + mspersystem * (CONST_X_SCALING * r_ob->zoom_x * r_ob->zoom_y) - (r_ob->j_inset_x - get_max_vscrollbar_width_or_inset_x(r_ob) - (get_ux_left_start(r_ob) + r_ob->key_signature_uwidth + r_ob->voice_names_uwidth + r_ob->additional_ux_start_pad) * r_ob->zoom_y);
                        } else {
                            r_ob->zoom_x = (r_ob->inner_width + (r_ob->j_inset_x - get_max_vscrollbar_width_or_inset_x(r_ob) - (get_ux_left_start(r_ob) + r_ob->key_signature_uwidth + r_ob->voice_names_uwidth + r_ob->additional_ux_start_pad) * r_ob->zoom_y) - r_ob->postdomain_width) / (mspersystem * CONST_X_SCALING * r_ob->zoom_y);
                        }
                    }
                    r_ob->inner_height = notationobj_get_supposed_standard_uheight(r_ob) * r_ob->zoom_y;
                    num_shots = ceil(length_ms_prev / mspersystem);
                    r_ob->length_ms = num_shots * mspersystem;
                } else { // k_NOTATION_OBJECT_SCORE
                    if (uxperline != r_ob->domain_ux)
                        r_ob->inner_width = deltauxpixels_to_deltaxpixels(r_ob, uxperline) + get_predomain_width_pixels(r_ob);
                    r_ob->inner_height = notationobj_get_supposed_standard_uheight(r_ob) * r_ob->zoom_y;
                    
                    if (!fitmeasures) {
                        num_shots = ceil(length_ux_prev / uxperline);
                        r_ob->length_ux = num_shots * uxperline;
                    } else {
                        r_ob->pagelike_barlines = true;
                        tuttipoint_system_layout = get_tuttipoint_system_layout(r_ob, uxperline);
                        num_shots = tuttipoint_system_layout->l_size;
//                        dev_llll_print(tuttipoint_system_layout, NULL, 0, 6, NULL);
                        
                        for (t_tuttipoint *tmp = r_ob->firsttuttipoint; tmp; tmp = tmp->next)
                            tmp->data = tmp->local_spacing_width_multiplier;
                    }
                 }
            }
            
            new_inner_width = r_ob->inner_width;
            
            redraw_hscrollbar(r_ob, 1);
            redraw_vscrollbar(r_ob, 1);
            
            calculate_ms_on_a_line(r_ob);
            recalculate_num_systems(r_ob);
            r_ob->system_jump = get_system_jump(r_ob);
            r_ob->firsttime = true;
            
            w = r_ob->inner_width + 2 * r_ob->j_inset_x, h = r_ob->inner_height + 2 * r_ob->j_inset_y;
        } else {
            w = r_ob->width, h = r_ob->height;
        }
        
        t_jsurface *page_surface = NULL;
        t_jgraphics *page_g = NULL;
        
        if (view == gensym("scroll") || view == gensym("page")) {
            page_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, w, h * num_shots + (num_shots - 1) * systemvshift_pixels);
            page_g = jgraphics_create(page_surface);
            t_rect bg = build_rect(0, 0, w, h * num_shots + (num_shots - 1) * systemvshift_pixels);
            paint_rect(page_g, &bg, NULL, &r_ob->j_background_rgba, 0, 0);
        }

        t_llllelem *tpt_el = tuttipoint_system_layout ? tuttipoint_system_layout->l_head : NULL;
        for (long i = 1; i <= num_shots; i++, tpt_el = (tpt_el ? tpt_el->l_next : NULL)) {
            // adjusting filename if needed
            char filename_temp[MAX_FILENAME_CHARS];
            if (view == gensym("multiline"))
                snprintf_zero(filename_temp, MAX_FILENAME_CHARS, "%s_%05d.%s", filename_no_ext, i, extension);
            else
                snprintf_zero(filename_temp, MAX_FILENAME_CHARS, "%s", filename);
            
            // setting domain properly
            if (view == gensym("multiline") || view == gensym("scroll") || view == gensym("page")) {
                if (r_ob->obj_type == k_NOTATION_OBJECT_ROLL) {
                    r_ob->screen_ms_start = (i - 1) * mspersystem;
                    redraw_hscrollbar(r_ob, 3);
                } else { // k_NOTATION_OBJECT_SCORE
                    if (!fitmeasures) {
                        // easy case
                        r_ob->screen_ux_start = (i - 1) * uxperline;
                        redraw_hscrollbar(r_ob, 3);
                    } else if (tpt_el) {
                        // must autofit the measures
                        t_llll *tpt_el_ll = hatom_getllll(&tpt_el->l_hatom);
                        long num_tuttipoint_slices = hatom_getlong(&tpt_el_ll->l_head->l_next->l_next->l_hatom);
                        long slice_index = hatom_getlong(&tpt_el_ll->l_head->l_next->l_next->l_next->l_hatom);
                        t_tuttipoint *from = (t_tuttipoint *)hatom_getobj(&tpt_el_ll->l_head->l_hatom);
                        t_tuttipoint *to = (t_tuttipoint *)hatom_getobj(&tpt_el_ll->l_head->l_next->l_hatom);
                        if (from && to) {
                            if (slice_index == 1) {
                                if (num_tuttipoint_slices == 1) {
                                    if (r_ob->inner_width != new_inner_width) {
                                        // resetting width
                                        r_ob->inner_width = new_inner_width;
                                        redraw_hscrollbar(r_ob, 1);
                                        calculate_ms_on_a_line(r_ob);
                                    }
                                } else if (num_tuttipoint_slices > 1) {
                                    r_ob->inner_width = (new_inner_width - get_predomain_width_pixels(r_ob)) * num_tuttipoint_slices + get_predomain_width_pixels(r_ob);
                                    redraw_hscrollbar(r_ob, 1);
                                    calculate_ms_on_a_line(r_ob);
                                }
                            }
                            
                            if (num_tuttipoint_slices == 1) {
                                (r_ob->inscreenmeas_function)((t_object *)r_ob, tuttipoint_get_first_measure(r_ob, from), tuttipoint_get_first_measure(r_ob, to), false);
                            } else if (num_tuttipoint_slices > 1) {
                                if (slice_index == 1)
                                    (r_ob->inscreenmeas_function)((t_object *)r_ob, tuttipoint_get_first_measure(r_ob, from), tuttipoint_get_first_measure(r_ob, to), false);
                                else {
                                    if (slice_index == num_tuttipoint_slices)
                                        r_ob->screen_ux_start = to->offset_ux + to->width_ux - r_ob->domain_ux;
                                    else
                                        r_ob->screen_ux_start = r_ob->screen_ux_end;
                                    redraw_hscrollbar(r_ob, 3);
                                }
                            }
                        }
                    }
                }
            }
            
            t_rect shot_rect = build_rect(0, 0, w, h);
            t_jsurface *shot_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, w, h);
            t_jgraphics *shot_g = jgraphics_create(shot_surface);
            
            jgraphics_set_source_rgba(shot_g, 0, 0, 0, 1.);
            
            char notify_when_painted_keep = r_ob->notify_when_painted;
            r_ob->notify_when_painted = false;
            (r_ob->paint_ext_function)((t_object *)r_ob, NULL, shot_g, shot_rect);
            r_ob->notify_when_painted = notify_when_painted_keep;
            
            if (view == gensym("scroll") || view == gensym("page")) {
                jgraphics_image_surface_draw(page_g, shot_surface, shot_rect, build_rect(0, (i-1) * (h + systemvshift_pixels), w, h));
            } else {
                if (type_sym && strcmp_case_insensitive(extension, "png") == 0) {
                    if (jgraphics_image_surface_writepng(shot_surface, filename_temp, path, dpi) != MAX_ERR_NONE) {
                        object_error((t_object *)r_ob, "Error while exporting image.");
                    }
                } else if (type_sym && (strcmp_case_insensitive(extension, "jpeg") == 0 || strcmp_case_insensitive(extension, "jpg") == 0)) {
                    if (jgraphics_image_surface_writejpeg(shot_surface, filename_temp, path) != MAX_ERR_NONE) {
                        object_error((t_object *)r_ob, "Error while exporting image.");
                    }
                }
            }
            
            jgraphics_destroy(shot_g);
            jgraphics_surface_destroy(shot_surface);
        }
        
        if ((view == gensym("scroll") || view == gensym("page")) && page_g && page_surface) {
            if (type_sym && strcmp_case_insensitive(extension, "png") == 0) {
                if (jgraphics_image_surface_writepng(page_surface, filename, path, dpi) != MAX_ERR_NONE) {
                    object_error((t_object *)r_ob, "Error while exporting image.");
                }
            } else if (type_sym && (strcmp_case_insensitive(extension, "jpeg") == 0 || strcmp_case_insensitive(extension, "jpg") == 0)) {
                if (jgraphics_image_surface_writejpeg(page_surface, filename, path) != MAX_ERR_NONE) {
                    object_error((t_object *)r_ob, "Error while exporting image.");
                }
            }
        }
        
        if (page_g)
            jgraphics_destroy(page_g);
        if (page_surface)
            jgraphics_surface_destroy(page_surface);
        
        //    unlock_general_mutex((t_notation_obj *)x);
        
        if (must_cleanup) {
            r_ob->zoom_x = zoom_x_prev;
            r_ob->show_hscrollbar = show_hscrollbar_prev;
            r_ob->show_vscrollbar = show_vscrollbar_prev;
            r_ob->legend = legend_prev;
            r_ob->show_border = show_border_prev;
            
            r_ob->inner_width = inner_width_prev;
            r_ob->inner_height = inner_height_prev;
            
            r_ob->screen_ms_start = screen_ms_start_prev;
            r_ob->length_ms = length_ms_prev;
            r_ob->length_ux = length_ux_prev;
            
            if (tuttipoint_system_layout) {
                r_ob->pagelike_barlines = false;

                lock_general_mutex(r_ob);
                for (t_tuttipoint *temp = r_ob->firsttuttipoint; temp; temp = temp->next){
                    assign_local_spacing_width_multiplier(r_ob, temp, temp->data);
                    temp->data = 0;
                    recompute_all_for_tuttipoint_region(r_ob, temp, false);
                }
                set_need_perform_analysis_and_change_flag(r_ob);
                unlock_general_mutex(r_ob);
            }
            
            redraw_hscrollbar(r_ob, 2);
            redraw_vscrollbar(r_ob, 1);
            calculate_ms_on_a_line(r_ob);
            recalculate_num_systems(r_ob);
            r_ob->system_jump = get_system_jump(r_ob);
            r_ob->firsttime = true;
            notationobj_invalidate_notation_static_layer_and_redraw(r_ob);
        }

        r_ob->fade_predomain = fade_predomain_prev;
        r_ob->postdomain_width = postdomain_prev;
        r_ob->onset_in_domain = onsetindomain_prev;
        
        r_ob->send_undo_redo_bang = send_undo_redo_bang_prev;

    } else {
        ok = false;
    }
    
    if (tuttipoint_system_layout)
        llll_free(tuttipoint_system_layout);
    
    if (arguments)
        llll_free(arguments);
    
    r_ob->exporting_image = 0;

    return ok ? MAX_ERR_NONE : MAX_ERR_GENERIC;
}

