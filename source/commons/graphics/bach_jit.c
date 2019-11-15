/*
 *  bach_jit.c
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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

#include "graphics/bach_jit.h"


void bach_paint_to_jitter_matrix(t_object *x, t_symbol *matrix_name, long width, long height, bach_paint_ext_fn obj_paint_ext)
{
    long w = width, h = height;
    t_rect draw_rect = build_rect(0, 0, w, h);
    t_jsurface *draw_surface = jgraphics_image_surface_create(JGRAPHICS_FORMAT_ARGB32, w, h);
    t_jgraphics *draw_g = jgraphics_create(draw_surface);
    
    jgraphics_set_source_rgba(draw_g, 0, 0, 0, 1.);
    //    jgraphics_image_surface_draw(g, bg_slots_surface, rect_oo, rect_oo);
    
    (obj_paint_ext)(x, NULL, draw_g, draw_rect);
    
    //find matrix
    t_jrgba color;
    void *matrix = jit_object_findregistered(matrix_name);
    if (matrix && jit_object_method(matrix, _jit_sym_class_jit_matrix)) {
        long savelock;
        t_jit_matrix_info minfo;
        char *bp,*p;
        
        savelock = (long) jit_object_method(matrix,_jit_sym_lock,1);
        jit_object_method(matrix,_jit_sym_getinfo,&minfo);
        jit_object_method(matrix,_jit_sym_getdata,&bp);
        
        if (!bp || minfo.dimcount < 2 || (minfo.planecount != 1 && minfo.planecount != 4)) {
            object_error((t_object *)x, "Error with jitter matrix");
            object_error((t_object *)x, "   Please check that it exists, that it has at least 2 dimensions and either 1 or 4 planes.");
            jit_object_method(matrix,_jit_sym_lock,savelock);
        } else {
            
            if (minfo.dim[0] != w || minfo.dim[1] != h) {
                minfo.dim[0] = w;
                minfo.dim[1] = h;
                if (jit_object_method(matrix, _jit_sym_setinfo, &minfo))
                    object_warn((t_object *)x, "Cannot resize jitter matrix automatically");
                jit_object_method(matrix,_jit_sym_getinfo,&minfo);
                jit_object_method(matrix,_jit_sym_getdata,&bp);
            }
            
            if (!bp || minfo.dimcount < 2 || (minfo.planecount != 1 && minfo.planecount != 4)) {
                object_error((t_object *)x, "Error with jitter matrix");
                object_error((t_object *)x, "   Please check that it exists, that it has at least 2 dimensions and either 1 or 4 planes.");
                jit_object_method(matrix,_jit_sym_lock,savelock);
            } else {
                
                long actual_w = minfo.dim[0], actual_h = minfo.dim[1];
                
                if (minfo.type==_jit_sym_char) {
                    for (long i = 0; i < actual_w; i++) {
                        for (long j = 0; j < actual_h; j++) {
                            jgraphics_image_surface_get_pixel(draw_surface, i, j, &color);
                            p = bp + (j)*minfo.dimstride[1] + (i)*minfo.dimstride[0];
                            if (minfo.planecount == 1) {
                                t_jhsla color_hsla = rgba_to_hsla(color);
                                *((uchar *)p) = round(color_hsla.lightness * color_hsla.alpha * 255);
                            } else {
                                *((uchar *)p) = round(color.alpha * 255);
                                *(((uchar *)p) + 1) = round(color.red * 255);
                                *(((uchar *)p) + 2) = round(color.green * 255);
                                *(((uchar *)p) + 3) = round(color.blue * 255);
                            }
                        }
                    }
                    
                } else if (minfo.type==_jit_sym_long) {
                    /*                bp += plane*4;
                     for (i=0; i<argc; i++,j++) {
                     p = bp + (j/minfo.dim[0])*minfo.dimstride[1] + (j%minfo.dim[0])*minfo.dimstride[0];
                     *((t_int32 *)p) = jit_atom_getlong(argv+i);
                     } */
                } else if (minfo.type==_jit_sym_float32) {
                    for (long i = 0; i < actual_w; i++) {
                        for (long j = 0; j < actual_h; j++) {
                            jgraphics_image_surface_get_pixel(draw_surface, i, j, &color);
                            p = bp + (j)*minfo.dimstride[1] + (i)*minfo.dimstride[0];
                            if (minfo.planecount == 1) {
                                t_jhsla color_hsla = rgba_to_hsla(color);
                                *((float *)p) = color_hsla.lightness * color_hsla.alpha;
                            } else {
                                *(((float *)p)) = color.alpha;
                                *(((float *)p) + 1) = color.red;
                                *(((float *)p) + 2) = color.green;
                                *(((float *)p) + 3) = color.blue;
                            }
                        }
                    }
                    
                    /*                bp += x->plane*4;
                     for (i=0; i<argc; i++,j++) {
                     p = bp + (j/minfo.dim[0])*minfo.dimstride[1] + (j%minfo.dim[0])*minfo.dimstride[0];
                     *((float *)p) = jit_atom_getfloat(argv+i);
                     } */
                } else if (minfo.type==_jit_sym_float64) {
                    
                    for (long i = 0; i < actual_w; i++) {
                        for (long j = 0; j < actual_h; j++) {
                            jgraphics_image_surface_get_pixel(draw_surface, i, j, &color);
                            p = bp + (j)*minfo.dimstride[1] + (i)*minfo.dimstride[0];
                            if (minfo.planecount == 1) {
                                t_jhsla color_hsla = rgba_to_hsla(color);
                                *((double *)p) = color_hsla.lightness * color_hsla.alpha;
                            } else {
                                *((double *)p) = color.alpha;
                                *(((double *)p) + 1) = color.red;
                                *(((double *)p) + 2) = color.green;
                                *(((double *)p) + 3) = color.blue;
                            }
                        }
                    }
                    
                    /*                bp += x->plane*8;
                     for (i=0; i<argc; i++,j++) {
                     p = bp + (j/minfo.dim[0])*minfo.dimstride[1] + (j%minfo.dim[0])*minfo.dimstride[0];
                     *((double *)p) = jit_atom_getfloat(argv+i);
                     } */
                }
            }
            
            jit_object_method(matrix,_jit_sym_lock,savelock);
        }
    } else {
        object_error((t_object *)x, "Can't find jitter matrix!");
        //        jit_error_sym(x,_jit_sym_err_calculate);
    }
    
    
    jgraphics_destroy(draw_g);
    jgraphics_surface_destroy(draw_surface);
}




