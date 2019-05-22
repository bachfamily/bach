/*
 *  bach_graphics.c
 *  bach
 *
 *  Created by daniele ghisi on 13/2/11.
 *  Copyright 2011 Daniele Ghisi. All rights reserved.
 *
 */
#include "bach.h"
#include "notation.h"
 
//#ifdef USE_GPC_LIBRARY
//#include "gpc.h"
//#endif



#define SQRT_2 1.414213562

 
// ****************************************************************
// auxiliary paint functions (wrappers)
// ****************************************************************

// ************** JUCE VERSION *******************

#ifdef BACH_JUCE
#include "bach_jucewrapper.h"
#include "juce_paint_wrappers.h"


/**
 * Converts an array of Unicode scalar values (code points) into
 * UTF-8. This algorithm works under the assumption that all
 * surrogate pairs have already been converted into scalar code
 * point values within the argument.
 * from 
 
 */

char *charset_unicodetoutf8_debug(unicodeChar *uni, long len, long *outlen)
{
    // determine how many bytes are needed for the complete conversion
    int i;
    int bytesNeeded = 0;
    unicodeChar *thisUni;
    char *utf8, *thisUtf8;
    
    if (len == 0) {
        thisUni = uni;
        while (*thisUni++)
            len++;
    }
    
    for (i = 0, thisUni = uni; i < len, *thisUni; i++, thisUni++) {
        if (*thisUni < 0x80)
            ++bytesNeeded;
        else if (*thisUni < 0x0800)
            bytesNeeded += 2;
        else if (*thisUni < 0x10000)
            bytesNeeded += 3;
        else
            bytesNeeded += 4;
    }

    thisUtf8 = utf8 = (char *) bach_newptr(bytesNeeded + 1);
    
    // do the conversion from character code points to utf-8
    for(i = 0, thisUni = uni; i < len; i++, thisUni++) {
        if(*thisUni < 0x80)
            *thisUtf8++ = *thisUni;
        else if (*thisUni < 0x0800) {
            *thisUtf8++ = *thisUni >> 6 | 0xC0;
            *thisUtf8++ = *thisUni & 0x3F | 0x80;
            //            utf8[bytes++] = (byte)(ch[i]>> 6 | 0xC0);
            //            utf8[bytes++] = (byte)(ch[i] & 0x3F | 0x80);
        } else if (*thisUni < 0x10000) {
            *thisUtf8++ = *thisUni >> 12 | 0xE0;
            *thisUtf8++ = *thisUni >> 6 & 0x3F | 0x80;        
            *thisUtf8++ = *thisUni & 0x3F | 0x80;    
            
            //            utf8[bytes++] = (byte)(ch[i]>> 12 | 0xE0);
            //            utf8[bytes++] = (byte)(ch[i]>> 6 & 0x3F | 0x80);
            //            utf8[bytes++] = (byte)(ch[i] & 0x3F | 0x80);
        } else {
            *thisUtf8++ = *thisUni >> 18 | 0xF0;
            *thisUtf8++ = *thisUni >> 12 & 0x3F | 0x80;    
            *thisUtf8++ = *thisUni >> 6 & 0x3F | 0x80;
            *thisUtf8++ = *thisUni & 0x3F | 0x80;
            
            //            utf8[bytes++] = (byte)(ch[i]>> 18 | 0xF0);
            //            utf8[bytes++] = (byte)(ch[i]>> 12 & 0x3F | 0x80);
            //            utf8[bytes++] = (byte)(ch[i]>> 6 & 0x3F | 0x80);
            //            utf8[bytes++] = (byte)(ch[i] & 0x3F | 0x80);
        }
    }
    *thisUtf8 = 0;
    return utf8;
}

void jgraphics_set_source_jrgba (t_jgraphics *g, t_jrgba *color)
{
    Colour col ((uint8) jlimit (0, 0xff, roundToInt (color->red * 255.0f)),
                (uint8) jlimit (0, 0xff, roundToInt (color->green * 255.0f)),
                (uint8) jlimit (0, 0xff, roundToInt (color->blue * 255.0f)),
                (uint8) jlimit (0, 0xff, roundToInt (color->alpha * 255.0f)));
    g->setColour(col);
} 

void jfont_text_measure(t_jfont *font, const char *text, double *width, double *height)
{
    /*
     // would this (much cheaper) work all the same?
    *width = font->getStringWidthFloat(text);
    *height = font->getHeight();
    */
    GlyphArrangement g;
    g.addLineOfText(*font, CharPointer_UTF8 (text), 0, 0);
    Path p;
    g.createPath(p);
    Rectangle<float> r = p.getBounds();
    *width = r.getWidth() * 1.1; // don't really know why...
    *height = r.getHeight();
}

t_jfont* jfont_create_debug(const char *family, t_jgraphics_font_slant slant, t_jgraphics_font_weight weight, double size) 
{
    return new Font(family, size, slant | weight);
}

void jfont_destroy_debug(t_jfont *f)
{
    delete f;
}

void paint_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width)
{
    jgraphics_set_source_jrgba (g, &color);
    g->drawLine (x1, y1, x2, y2, width);
}

void paint_filledrectangle(t_jgraphics* g, t_jrgba fillcolor, double x1, double y1, double width, double height)
{
    jgraphics_set_source_jrgba (g, &fillcolor);
    g->fillRect ((float) x1, (float) y1, (float) width, (float) height);
}

void paint_strokenrectangle(t_jgraphics* g, t_jrgba bordercolor, double x1, double y1, double width, double height, double linewidth)
{
    jgraphics_set_source_jrgba (g, &bordercolor);
    g->drawRect((float) x1, (float) y1, (float) width, (float) height, (float) linewidth);
}

void paint_rhomboid(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double bpt_x, double bpt_y, double semiwidth, double semiheight, double linewidth)
{
    Path p;
    double top_y = bpt_y - semiheight;
    double bottom_y = bpt_y + semiheight;
    double left_x = bpt_x - semiwidth;
    double right_x = bpt_x + semiwidth;
    p.addQuadrilateral(bpt_x, top_y, right_x, bpt_y, bpt_x, bottom_y, left_x, bpt_y);
    jgraphics_set_source_jrgba (g, &fillcolor);
    g->fillPath(p);
    jgraphics_set_source_jrgba (g, &bordercolor);
    g->strokePath(p, linewidth);
}

void paint_circle_filled(t_jgraphics* g, t_jrgba color, double x, double y, double radius)
{
    double diam = radius * 2;
    jgraphics_set_source_jrgba (g, &color);
    g->fillEllipse (x, y, diam, diam);
}

void paint_ellipse_filled(t_jgraphics* g, t_jrgba color, double x, double y, double radiusx, double radiusy)
{
    jgraphics_set_source_jrgba (g, &color);
    g->fillEllipse (x, y, radiusx * 2, radiusy * 2);
}

void paint_circle_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radius, double linewidth)
{
    double diam = radius * 2;
    jgraphics_set_source_jrgba (g, &color);
    g->drawEllipse (x, y, diam, diam, linewidth);
}


void paint_ellipse_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radiusx, double radiusy, double linewidth)
{
    jgraphics_set_source_jrgba (g, &color);
    g->drawEllipse (x, y, radiusx * 2, radiusy * 2, linewidth);
}

void paint_dashed_y_line(t_jgraphics* g, t_jrgba color, double x, double y1, double y2, double width, double dash_length)
{
    float fdash_length = dash_length;
    jgraphics_set_source_jrgba (g, &color);
    g->drawDashedLine(Line<float>(x, y1, x, y2), &fdash_length, 1, width);
}

void paint_dashed_x_line(t_jgraphics* g, t_jrgba color, double x1, double x2, double y, double width, double dash_length)
{
    float fdash_length = dash_length;
    jgraphics_set_source_jrgba (g, &color);
    g->drawDashedLine(Line<float>(x1, y, x2, y), &fdash_length, 1, width);
}

void paint_dashed_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width, double dash_length)
{
    float fdash_length = dash_length;
    jgraphics_set_source_jrgba (g, &color);
    g->drawDashedLine(Line<float>(x1, y1, x2, y2), &fdash_length, 1, width);
}

void paint_doublewidth_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width_start, double width_end)
{
    Path p;
    double hws = width_start / 2.;
    double hwe = width_end / 2.;
    p.addQuadrilateral(x1, y1 - hws, x2, y2 - hwe, x2, y2 + hwe, x1, y1 + hws);
    jgraphics_set_source_jrgba (g, &color);
    g->fillPath(p);
}

// same as paint_line()
void paint_line_fast(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width)
{
    jgraphics_set_source_jrgba (g, &color);
    g->drawLine (x1, y1, x2, y2, width);
}

void paint_rectangle(t_jgraphics* g, t_jrgba border_color, t_jrgba fill_color, double x1, double y1, double width, double height, double border_width)
{
    paint_filledrectangle(g, fill_color, x1, y1, width, height);
    paint_strokenrectangle(g, border_color, x1, y1, width, height, border_width);
}

void paint_rectangle_rounded(t_jgraphics* g, t_jrgba border_color, t_jrgba fill_color, double x1, double y1, double width, double height, double border_width, double ovalwidth, double ovalheight)
{
    float cornerSize = MIN(ovalwidth, ovalheight);
    jgraphics_set_source_jrgba (g, &fill_color);
    g->fillRoundedRectangle(x1, y1, width, height, cornerSize);
    jgraphics_set_source_jrgba (g, &border_color);
    g->drawRoundedRectangle(x1, y1, width, height, cornerSize, border_width);
} 
 
void write_text_simple(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double max_width, double max_height, 
                const Justification& justificationFlags)
{
    g->setFont(*jf);
//    g->setFont(Font(String("Maestro"), 24., 0));
    jgraphics_set_source_jrgba (g, &textcolor);
    g->drawFittedText(String(CharPointer_UTF8 (text)), x1, y1, max_width, max_height, justificationFlags, 1, 0.8);
//    g->drawText(text, x1, y1, max_width, max_height, justificationFlags, true);

}

void write_text(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double max_width, double max_height,
                                   const Justification& justificationFlags, char single_line, char use_ellipsis)
{
    g->setFont(*jf);
    jgraphics_set_source_jrgba (g, &textcolor);
    g->drawFittedText(CharPointer_UTF8 (text), x1, y1, max_width, max_height, justificationFlags, single_line ? 1 : 255, 0.8);
}

#endif


// ****************** MAX VERSION *******************
#ifdef BACH_MAX
void paint_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width){
    jgraphics_move_to(g, x1, y1);
    jgraphics_line_to(g, x2, y2);
    jgraphics_set_line_width(g,width);
    jgraphics_set_source_jrgba(g, &color);
    jgraphics_stroke(g); 
}

void paint_filledrectangle(t_jgraphics* g, t_jrgba fillcolor, double x1, double y1, double width, double height){
    jgraphics_set_source_jrgba(g, &fillcolor);
    jgraphics_set_line_width(g, 0.);
    jgraphics_rectangle(g, x1, y1, width, height);
    jgraphics_fill(g);
}

void paint_filledrectangle_rounded(t_jgraphics* g, t_jrgba fillcolor, double x1, double y1, double width, double height, double ovalwidth, double ovalheight){
    jgraphics_set_source_jrgba(g, &fillcolor);
    jgraphics_set_line_width(g, 0.);
    jgraphics_rectangle_rounded(g, x1, y1, width, height, ovalwidth, ovalheight);
    jgraphics_fill(g);
}

void paint_stripedrectangle(t_jgraphics* g, t_jrgba bgcolor, t_jrgba stripecolor, double x1, double y1, double width, double height, double stripe_width, double nonstripe_width){
    double cur_x = x1, x2 = x1 + width;
    paint_filledrectangle(g, bgcolor, x1, y1, width, height);

    jgraphics_set_line_width(g, 0.);
    jgraphics_set_source_jrgba(g, &stripecolor);

    while (true) {
        cur_x += nonstripe_width;
        if (cur_x > x2)
            break;
        
        paint_filledrectangle(g, stripecolor, cur_x, y1, MIN(stripe_width, x2 - cur_x), height);

        cur_x += stripe_width;
    }
}



void paint_filledrectangle_fast(t_jgraphics* g, t_jrgba fill_color, double x1, double y1, double width, double height)
{
    jgraphics_set_source_jrgba(g, &fill_color);
    jgraphics_set_line_width(g, 0.);
    jgraphics_rectangle_fill_fast(g, x1, y1, width, height);
}


void paint_strokenrectangle(t_jgraphics* g, t_jrgba bordercolor, double x1, double y1, double width, double height, double linewidth){
    jgraphics_set_source_jrgba(g, &bordercolor);
    jgraphics_set_line_width(g, linewidth);
    jgraphics_rectangle(g, x1, y1, width, height);
    jgraphics_stroke(g);
}

void paint_strokenrectangle_fast(t_jgraphics* g, t_jrgba bordercolor, double x1, double y1, double width, double height, double linewidth){
    jgraphics_set_source_jrgba(g, &bordercolor);
    jgraphics_set_line_width(g, linewidth);
    jgraphics_rectangle_draw_fast(g, x1, y1, width, height, linewidth);
}

void paint_rhomboid(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double bpt_x, double bpt_y, double semiwidth, double semiheight, double linewidth){
    //fill rhomboid
    jgraphics_set_source_jrgba(g, &fillcolor); 
    jgraphics_set_line_width(g, 0.);
    jgraphics_move_to(g, bpt_x - semiwidth, bpt_y);
    jgraphics_line_to(g, bpt_x, bpt_y - semiheight);
    jgraphics_line_to(g, bpt_x + semiwidth, bpt_y);
    jgraphics_line_to(g, bpt_x, bpt_y + semiheight);
    jgraphics_close_path(g); 
    jgraphics_fill_preserve(g);    
    //border of rhomboid
    jgraphics_set_source_jrgba(g, &bordercolor); 
    jgraphics_set_line_width(g, linewidth);
    jgraphics_stroke(g);                                                                
}


void paint_quadrilater(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double linewidth){
    //fill rhomboid
    jgraphics_set_source_jrgba(g, &fillcolor); 
    jgraphics_set_line_width(g, 0.);
    jgraphics_move_to(g, x1, y1);
    jgraphics_line_to(g, x2, y2);
    jgraphics_line_to(g, x3, y3);
    jgraphics_line_to(g, x4, y4);
    jgraphics_close_path(g); 
    jgraphics_fill_preserve(g);    
    //border of rhomboid
    jgraphics_set_source_jrgba(g, &bordercolor); 
    jgraphics_set_line_width(g, linewidth);
    jgraphics_stroke(g);                                                                
}

void paint_triangle(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double x1, double y1, double x2, double y2, double x3, double y3, double linewidth){
    //fill 
    jgraphics_set_source_jrgba(g, &fillcolor); 
    jgraphics_set_line_width(g, 0.);
    jgraphics_move_to(g, x1, y1);
    jgraphics_line_to(g, x2, y2);
    jgraphics_line_to(g, x3, y3);
    jgraphics_close_path(g); 
    jgraphics_fill_preserve(g);    
    //border 
    jgraphics_set_source_jrgba(g, &bordercolor); 
    jgraphics_set_line_width(g, linewidth);
    jgraphics_stroke(g);                                                                
}

void paint_circle_filled(t_jgraphics* g, t_jrgba color, double x, double y, double radius)
{
    jgraphics_set_source_jrgba(g, &color); jgraphics_set_line_width(g, 0.);
    jgraphics_arc(g, x, y, radius, 0., 6.29);
    jgraphics_fill(g);    
}

void paint_circle(t_jgraphics* g, t_jrgba bordercolor, t_jrgba fillcolor, double x, double y, double radius, double linewidth)
{
    jgraphics_set_source_jrgba(g, &fillcolor); 
    jgraphics_set_line_width(g, 0.);
    jgraphics_arc(g, x, y, radius, 0., 6.29);
    jgraphics_fill_preserve(g);
    jgraphics_set_source_jrgba(g, &bordercolor); 
    jgraphics_set_line_width(g, linewidth);
    jgraphics_stroke(g);
}

void paint_ellipse_filled(t_jgraphics* g, t_jrgba color, double x, double y, double radiusx, double radiusy)
{
    jgraphics_set_source_jrgba(g, &color); jgraphics_set_line_width(g, 0.);
    jgraphics_ovalarc(g, x, y, radiusx, radiusy, 0., 6.29);
    jgraphics_fill(g);    
}

void paint_circle_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radius, double linewidth){
    paint_arc_stroken(g, color, x, y, radius, linewidth, 0., 6.29);
}

void paint_arc_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radius, double linewidth, double start_angle, double end_angle){
    jgraphics_set_source_jrgba(g, &color); 
    jgraphics_set_line_width(g, linewidth);
    jgraphics_arc(g, x, y, radius, start_angle, end_angle);
    jgraphics_stroke(g);
}

void paint_ellipse_stroken(t_jgraphics* g, t_jrgba color, double x, double y, double radiusx, double radiusy, double linewidth){
    jgraphics_set_source_jrgba(g, &color); jgraphics_set_line_width(g, linewidth);
    jgraphics_ovalarc(g, x, y, radiusx, radiusy, 0., 6.29);
    jgraphics_stroke(g);    
}

void paint_dashed_y_line(t_jgraphics* g, t_jrgba color, double x, double y1, double y2, double width, double dash_length){
    double this_y;
    if (dash_length <= 0.) return;
    if (y1 > y2) { double temp = y2; y2 = y1; y1 = temp; }
    this_y = y1;
    while (this_y < y2) {
        paint_line(g, color, x, this_y, x, MIN(this_y + dash_length, y2), width);
        this_y += 2 * dash_length;
    }
}

void paint_dashed_x_line(t_jgraphics* g, t_jrgba color, double x1, double x2, double y, double width, double dash_length){
    double this_x;
    if (dash_length <= 0.) return;
    this_x = x1;
    if (x1 > x2) { double temp = x2; x2 = x1; x1 = temp; }
    while (this_x < x2) {
        paint_line(g, color, this_x, y, MIN(this_x + dash_length, x2), y, width);
        this_x += 2 * dash_length;
    }
}

void paint_dashed_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width, double dash_length){
    double angle, dash_length_x, dash_length_y, this_x, this_y;
    if (dash_length <= 0.) 
        return;
//    if (x1 < 0. || x2 < 0. || y1 < 0. || y2 < 0.) 
//        return;
    if (x1 == x2) {
        paint_dashed_y_line(g, color, x1, y1, y2, width, dash_length); // we use paint_dashed_y_line instead!!!
        return;
    }
    if (x2 < x1) { 
        double temp = x2; 
        x2 = x1; 
        x1 = temp; 
        temp = y2; 
        y2 = y1; 
        y1 = temp; 
    }
    angle = atan((y2-y1)/(x2-x1));
    dash_length_x = fabs(dash_length * cos(angle));
    dash_length_y = fsign(angle) * fabs(dash_length * sin(angle));
    if (dash_length_x <= 0.0001) 
        dash_length_x = 0.4;
    if (fabs(dash_length_y) <= 0.0001) 
        dash_length_y = fsign(angle) * 0.4;
    this_x = x1; this_y = y1;
    while (this_x < x2) {
        paint_line(g, color, this_x, this_y, MIN(this_x + dash_length_x, x2), this_x + dash_length_x > x2 ? y2 : this_y + dash_length_y, width);
        this_x += 2 * dash_length_x;
        this_y += 2 * dash_length_y;
    }
}



void paint_doublewidth_line(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width_start, double width_end){
    double p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
    
    if (fabs(y1 - y2) < CONST_EPSILON1) { // purely horizontal line
        p1x = x1;
        p1y = y1 - width_start/2.;
        p2x = x1;
        p2y = y1 + width_start/2.;
        p3x = x2;
        p3y = y2 + width_end/2.;
        p4x = x2;
        p4y = y2 - width_end/2.;
    } else if (fabs(x1 - x2) < CONST_EPSILON1) { // purely vertical line
        p1x = x1 - width_start/2.;
        p1y = y1;
        p2x = x1 + width_start/2.;
        p2y = y1;
        p3x = x2 + width_end/2.;
        p3y = y2;
        p4x = x2 - width_end/2.;
        p4y = y2;
    } else {
        double alpha = atan((y1 - y2) / (x2 - x1));
        p1x = x1 - sin(alpha) * width_start/2.;
        p1y = y1 - cos(alpha) * width_start/2.;
        p2x = x1 + sin(alpha) * width_start/2.;
        p2y = y1 + cos(alpha) * width_start/2.;
        p3x = x2 + sin(alpha) * width_end/2.;
        p3y = y2 + cos(alpha) * width_end/2.;
        p4x = x2 - sin(alpha) * width_end/2.;
        p4y = y2 - cos(alpha) * width_end/2.;
    }

    jgraphics_move_to(g, p1x, p1y);
    jgraphics_line_to(g, p2x, p2y);
    jgraphics_line_to(g, p3x, p3y);
    jgraphics_line_to(g, p4x, p4y);
    jgraphics_close_path(g);
    jgraphics_set_line_width(g, 0);
    jgraphics_set_source_jrgba(g, &color);
    jgraphics_fill(g); 
}

// non antialiased version
void paint_line_fast(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width){
    jgraphics_set_source_jrgba(g, &color);
    jgraphics_line_draw_fast(g, x1, y1, x2, y2, width);
    jgraphics_stroke(g); 
}

void paint_rectangle(t_jgraphics* g, t_jrgba border_color, t_jrgba fill_color, double x1, double y1, double width, double height, double border_width)
{
    jgraphics_set_source_jrgba(g, &fill_color);
    jgraphics_set_line_width(g, border_width);
    jgraphics_rectangle(g, x1, y1, width, height);
    jgraphics_fill_preserve(g);
    jgraphics_set_source_jrgba(g, &border_color);
    jgraphics_stroke(g);
}

void paint_rect(t_jgraphics* g, t_rect *rect, t_jrgba *border_color, t_jrgba *fill_color, double border_width, double corner_roundness)
{
    if (border_color && !fill_color) {
        jgraphics_set_source_jrgba(g, border_color);
        jgraphics_set_line_width(g, border_width);
        if (corner_roundness > 0)
            jgraphics_rectangle_rounded(g, rect->x, rect->y, rect->width, rect->height, corner_roundness, corner_roundness);
        else
            jgraphics_rectangle(g, rect->x, rect->y, rect->width, rect->height);
        jgraphics_stroke(g);
    } else if (fill_color && !border_color) {
        jgraphics_set_source_jrgba(g, fill_color);
        if (corner_roundness > 0)
            jgraphics_rectangle_rounded(g, rect->x, rect->y, rect->width, rect->height, corner_roundness, corner_roundness);
        else
            jgraphics_rectangle(g, rect->x, rect->y, rect->width, rect->height);
        jgraphics_fill(g);
    } else if (fill_color && border_color) {
        jgraphics_set_source_jrgba(g, fill_color);
        jgraphics_set_line_width(g, border_width);
        if (corner_roundness > 0)
            jgraphics_rectangle_rounded(g, rect->x, rect->y, rect->width, rect->height, corner_roundness, corner_roundness);
        else
            jgraphics_rectangle(g, rect->x, rect->y, rect->width, rect->height);
        jgraphics_fill_preserve(g);
        jgraphics_set_source_jrgba(g, border_color);
        jgraphics_stroke(g);
    }
}

void paint_rectangle_rounded(t_jgraphics* g, t_jrgba border_color, t_jrgba fill_color, double x1, double y1, double width, double height, double border_width, double ovalwidth, double ovalheight){
    jgraphics_set_source_jrgba(g, &fill_color);
    jgraphics_set_line_width(g, border_width);
    jgraphics_rectangle_rounded(g, x1, y1, width, height, ovalwidth, ovalheight);
    jgraphics_fill_preserve(g);
    jgraphics_set_source_jrgba(g, &border_color);
    jgraphics_stroke(g);
}

// -1 = dim, 1 = cresc
void paint_hairpin(t_jgraphics* g, t_jrgba color, long hairpin_type, double xstart, double xend, double middley, double semiaperture, double width, double dash_length, double start_aperture_normalized)
{
    if (hairpin_type == k_DYNAMICS_HAIRPIN_CRESC || hairpin_type == k_DYNAMICS_HAIRPIN_CRESCEXP) {
        if (hairpin_type == k_DYNAMICS_HAIRPIN_CRESC || xend <= xstart) { // linear
            paint_line(g, color, xstart, middley + start_aperture_normalized * semiaperture, xend, middley + semiaperture, width);
            paint_line(g, color, xstart, middley - start_aperture_normalized * semiaperture, xend, middley - semiaperture, width);
        } else { // exponential
            double cropped_semiaperture = semiaperture * 0.6;
            double cropped_xend = MAX(xend - 1.5 * semiaperture, 0.5 * (xstart + xend));
            double cpx, cpy1, cpy2, temp; // bezier control point
            
            paint_line(g, color, xstart, middley + start_aperture_normalized * semiaperture * 0.6, cropped_xend, middley + cropped_semiaperture, width);
            paint_line(g, color, xstart, middley - start_aperture_normalized * semiaperture * 0.6, cropped_xend, middley - cropped_semiaperture, width);
            
            cpx = (cropped_xend + xend)/2.;
            temp = (cpx - xstart) * (cropped_semiaperture / (cropped_xend - xstart));
            cpy1 = middley - temp;
            cpy2 = middley + temp;

            paint_bezier_curve(g, color, cropped_xend, middley - cropped_semiaperture, cpx, cpy1, cpx, cpy1, xend, middley - 1.4 * semiaperture, width);
            paint_bezier_curve(g, color, cropped_xend, middley + cropped_semiaperture, cpx, cpy2, cpx, cpy2, xend, middley + 1.4 * semiaperture, width);
        }
    } else if (hairpin_type == k_DYNAMICS_HAIRPIN_DIM || hairpin_type == k_DYNAMICS_HAIRPIN_DIMEXP) {
        if (hairpin_type == k_DYNAMICS_HAIRPIN_DIM || xend <= xstart) { // linear
            paint_line(g, color, xend, middley, xstart, middley + semiaperture * (1 - start_aperture_normalized), width);
            paint_line(g, color, xend, middley, xstart, middley - semiaperture * (1 - start_aperture_normalized), width);
        } else { // exponential
            double cropped_semiaperture = semiaperture * 0.6 * (1-start_aperture_normalized);
            double cropped_xstart = MIN(xstart + 1.5 * semiaperture, 0.5 * (xstart + xend));
            double cpx, cpy1, cpy2, temp; // bezier control point
            
            paint_line(g, color, xend, middley, cropped_xstart, middley + cropped_semiaperture, width);
            paint_line(g, color, xend, middley, cropped_xstart, middley - cropped_semiaperture, width);
            
            cpx = (cropped_xstart + xstart)/2.;
            temp = (cpx - xend) * (cropped_semiaperture / (cropped_xstart - xend));
            cpy1 = middley - temp;
            cpy2 = middley + temp;
            
            paint_bezier_curve(g, color, cropped_xstart, middley - cropped_semiaperture, cpx, cpy1, cpx, cpy1, xstart, middley - 1.4 * semiaperture, width);
            paint_bezier_curve(g, color, cropped_xstart, middley + cropped_semiaperture, cpx, cpy2, cpx, cpy2, xstart, middley + 1.4 * semiaperture, width);
            
        }
    } else if (hairpin_type == k_DYNAMICS_HAIRPIN_DASHED || hairpin_type == k_DYNAMICS_HAIRPIN_CRESCDASHED || hairpin_type == k_DYNAMICS_HAIRPIN_DIMDASHED) {
        paint_dashed_line(g, color, xstart, middley + semiaperture, xend, middley + semiaperture, width, dash_length);
    }
}


void write_text_in_vertical(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double boxwidth, double boxheight, int justification, double line_spacing){
    long size = strlen(text);
    char letter[2];
    double width, height; 
    long i;
    int hjust = justification & (JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_RIGHT + JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED + JGRAPHICS_TEXT_JUSTIFICATION_HJUSTIFIED);
    double vdiff;
    
    jfont_text_measure(jf, text, &width, &height);
    
    vdiff = boxheight - height * size * line_spacing;
    letter[1] = 0;
    for (i = 0; i < size; i++){
        letter[0] = text[i];
        if (justification & JGRAPHICS_TEXT_JUSTIFICATION_TOP)
            write_text(g, jf, textcolor, letter, x1, y1 + i * height * line_spacing, boxwidth, height * line_spacing + 10, hjust, true, false);
        else if (justification & JGRAPHICS_TEXT_JUSTIFICATION_BOTTOM)
            write_text(g, jf, textcolor, letter, x1, y1 + i * height * line_spacing + vdiff, boxwidth, height * line_spacing + 10, hjust, true, false);
        else if (justification & JGRAPHICS_TEXT_JUSTIFICATION_VCENTERED)
            write_text(g, jf, textcolor, letter, x1, y1 + i * height * line_spacing + vdiff / 2., boxwidth, height * line_spacing + 10, hjust, true, false);
    }
}

void write_text_simple(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double max_width, double max_height)
{
    write_text(g, jf, textcolor, text, x1, y1, max_width, max_height, JGRAPHICS_TEXT_JUSTIFICATION_LEFT + JGRAPHICS_TEXT_JUSTIFICATION_TOP, false, false);
}

void write_text(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, const char *text, double x1, double y1, double width, double height, int justification, char single_line, char use_ellipsis)
{
    t_jtextlayout *jtl;
    jtl = jtextlayout_create(); 
    jtextlayout_set(jtl, text, jf, x1, y1, width, height, (t_jgraphics_text_justification) justification, 
                    single_line ? (use_ellipsis ? JGRAPHICS_TEXTLAYOUT_USEELLIPSIS : JGRAPHICS_TEXTLAYOUT_NOWRAP) : (t_jgraphics_textlayout_flags) 0);
    jtextlayout_settextcolor(jtl, &textcolor); 
    jtextlayout_draw(jtl, g);
    jtextlayout_destroy(jtl);
}


void write_long_if_there_is_space(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, long num, char *unit, double x1, double y1, double width, double height, int justification)
{
    char value_str[100];
    double w, h;
    snprintf_zero(value_str, 100, "%ld%s", num, unit);
    jfont_text_measure(jf, value_str, &w, &h);
    
    if (w <= width) {
        write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
        return;
    }
    
    if (unit && unit[0]) {
        // we try without the unit
        snprintf_zero(value_str, 100, "%ld", num);
        jfont_text_measure(jf, value_str, &w, &h);
        if (w < width) {
            write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
            return;
        }
    }
    
    if (num < 1000.) {
        // we try to use k = 10^2
        snprintf_zero(value_str, 100, "%ldh", (long)round(num/100.));
        jfont_text_measure(jf, value_str, &w, &h);
        if (w < width) {
            write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
            return;
        }
    }
    
    // we try to use k = 10^3
    snprintf_zero(value_str, 100, "%ldk", (long)round(num/1000.));
    jfont_text_measure(jf, value_str, &w, &h);
    if (w < width) {
        write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
        return;
    }

    // we try to use M = 10^6
    snprintf_zero(value_str, 100, "%ldM", (long)round(num/1000000.));
    jfont_text_measure(jf, value_str, &w, &h);
    if (w < width) {
        write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
        return;
    }

    // else: we simply can't display it
}

void write_double_account_for_fixed_width(t_jgraphics* g, t_jfont* jf, t_jrgba textcolor, double num, char *unit, double x1, double y1, double width, double height, 
                                    int justification, long max_num_digits)
{
    char value_str[100];
    double w, h;
    long num_decimal_digits;
    
    for (num_decimal_digits = max_num_digits; num_decimal_digits >= 2; num_decimal_digits--) {
        snprintf_zero(value_str, 100, "%.*f%s", num_decimal_digits, num, unit);
        jfont_text_measure(jf, value_str, &w, &h);
        if (w < width) {
            write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
            return;
        }
    }

    if (max_num_digits >= 2) {
        for (num_decimal_digits = 2; num_decimal_digits >= 0; num_decimal_digits--) {
            snprintf_zero(value_str, 100, "%.*f", num_decimal_digits, num);
            jfont_text_measure(jf, value_str, &w, &h);
            if (w < width) {
                write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
                return;
            }
        }
    }
    
    snprintf_zero(value_str, 100, "%.ld", (long)round(num));
    jfont_text_measure(jf, value_str, &w, &h);
    if (w < width) {
        write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
        return;
    }
    
    // using "k" as 10^3
    snprintf_zero(value_str, 100, "%.ldk", (long)round(num/1000.));
    jfont_text_measure(jf, value_str, &w, &h);
    if (w < width) {
        write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
        return;
    }
    
    // using "M" as 10^6
    snprintf_zero(value_str, 100, "%.ldM", (long)round(num/1000000.));
    jfont_text_measure(jf, value_str, &w, &h);
    if (w < width) {
        write_text(g, jf, textcolor, value_str, x1, y1, width, height, justification, true, false);
        return;
    }
}


#endif // MAX_VERSION



// **************** COMMON STUFF ******************


char is_font_installed(t_symbol *font)
{
    // get all fonts;
    t_symbol **list = NULL;
    long i, count = 0;
    char found = 0;
    jfont_getfontlist(&count, &list);
    
    for (i = 0; i < count; i++)
        if (list[i] == font) {
            found = 1;
            break;
        }

    sysmem_freeptr(list);
    return found;
}


void set_jrgba(t_jrgba *col, double r, double g, double b, double a)
{
    col->red = r;
    col->green = g;
    col->blue = b;
    col->alpha = a;
}

void compute_bezier_point(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double t, double *x_res, double *y_res){
    // computes the cubic bezier curve with control points xi yi, in the parameter t (between 0. and 1.) and fills the x_res and y_res variables
    
    double t_squared = t * t;
    double t_cubed = t_squared * t;
    double cx = 3. * (x1 - x0);
    double bx = 3. * (x2 - x1) - cx;
    double ax = x3 - x0 - cx - bx;
    double cy = 3. * (y1 - y0);
    double by = 3. * (y2 - y1) - cy;
    double ay = y3 - y0 - cy - by;
    *x_res = ax * t_cubed + bx * t_squared + cx * t + x0;
    *y_res = ay * t_cubed + by * t_squared + cy * t + y0;
}



// ONLY WORKS FOR POSITIVE SLOPES!!!!!!!
void get_bezier_control_points(double x_start, double y_start, double x_end, double y_end, double slope, 
                               double *ctrl_1_x, double *ctrl_1_y, double *ctrl_2_x, double *ctrl_2_y,
                               double *left_derivative, double *right_derivative){
// get the two internal bezier control points for the cubic bezier curve in the convex hull between x_start y_start and x_end y_end, with the slope given by slope (0 = linear)
    char must_swap = (slope < 0); // MUST SWAP IS AN OLD, NO LONGER SUPPORTED FEATURE
    double absslope = fabs(slope);
    double left_der = (left_derivative ? *left_derivative : 1);
    double right_der = (right_derivative ? *right_derivative : 1);
    
    if (must_swap) {
        swap_doubles(&x_start, &y_start);
        swap_doubles(&x_end, &y_end);
        left_der = 1/left_der;
        right_der = 1/right_der;
        slope = absslope;
    }

    double beta = absslope > 0.8 ? rescale(absslope, 0.8, 1., 1./3 + 0.161, 0.5) : rescale(absslope, 0.35, 0.8, 1./3., 1./3 + 0.161);
    double one_minus_beta = absslope > 0.8 ? 2./3 + 0.0805 : rescale(absslope, 0.35, 0.8, 2./3, 2./3 + 0.0805);
    
    *ctrl_1_x = rescale(beta, 0, 1, x_start, x_end);
    *ctrl_2_x = rescale(one_minus_beta, 0, 1, x_start, x_end);

    if (!left_derivative && !right_derivative) {
        *ctrl_1_y = (!must_swap) ? (1 - absslope) * (y_start + (y_end - y_start) * beta) + absslope * y_start :
        absslope * y_end + (1 - absslope) * (y_start + (y_end - y_start) * beta);
        
        *ctrl_2_y = (!must_swap) ? (1 - absslope) * (y_start + (y_end - y_start) * one_minus_beta) + absslope * y_start :
        absslope * y_end + (1 - absslope) * (y_start + (y_end - y_start) * one_minus_beta);
    } else {
        
        if (left_derivative) 
            *ctrl_1_y = y_start + left_der * ((*ctrl_1_x) - x_start);
        
        if (right_derivative) {
            *ctrl_2_y = y_end - right_der * (x_end - (*ctrl_2_x));
            if ((y_start <= y_end && *ctrl_2_y < y_start) || (y_start >= y_end && *ctrl_2_y > y_start)) {
                *ctrl_2_y = y_start;
                *ctrl_2_x = x_end - (y_end - *ctrl_2_y) / right_der;
            } 
        }
        
        if (!left_derivative) {
            double d = pt_line_distance_vertical(*ctrl_2_x, *ctrl_2_y, x_start, y_start, x_end, y_end);
            if (x_start == x_end)
                *ctrl_1_y = rescale(*ctrl_1_x, x_start, x_end, y_start, y_end) - d; // * (slope > 0 ? -1 : 1);
            else
                *ctrl_1_y = rescale(*ctrl_1_x, x_start, x_end, y_start, y_end) - d; // * (slope > 0 ? -1 : 1);
            if ((y_start <= y_end && *ctrl_1_y < y_start) || (y_start >= y_end && *ctrl_1_y > y_start))
                *ctrl_1_y = y_start;
        }
        
        if (!right_derivative) {
            double d = pt_line_distance_vertical(*ctrl_1_x, *ctrl_1_y, x_start, y_start, x_end, y_end);
            if (x_start == x_end)
                *ctrl_2_y = (y_start + y_end)/2.;
            else
                *ctrl_2_y = rescale(*ctrl_2_x, x_start, x_end, y_start, y_end) - d; // * (slope > 0 ? -1 : 1);
        }
    }
    
    if (must_swap) {
        swap_doubles(ctrl_1_x, ctrl_1_y);
        swap_doubles(ctrl_2_x, ctrl_2_y);
    }
}


t_pt pt_pt_sum(t_pt pt1, t_pt pt2)
{
    t_pt out;
    out.x = pt1.x + pt2.x;
    out.y = pt1.y + pt2.y;
    return out;
}


t_pt pt_pt_diff(t_pt pt1, t_pt pt2)
{
    t_pt out;
    out.x = pt1.x - pt2.x;
    out.y = pt1.y - pt2.y;
    return out;
}


t_pt pt_number_prod(t_pt point, double scalar)
{
    t_pt out;
    out.x = point.x * scalar;
    out.y = point.y * scalar;
    return out;
}


double pt_pt_scalarprod(t_pt pt1, t_pt pt2)
{
    return pt1.x * pt2.x + pt1.y * pt2.y; 
}

// p_i's are the original control points, q_i's and r_i's are subdivided curve's subdivision points. t is subdivision time between 0 and 1
// this is the de Casteljau algorithm
// see https://www.clear.rice.edu/comp360/lectures/SubdivisionTextNew.pdf for the notation
void subdivide_bezier(t_pt p0, t_pt p1, t_pt p2, t_pt p3, t_pt *q0, t_pt *q1, t_pt *q2, t_pt *q3, t_pt *r0, t_pt *r1, t_pt *r2, t_pt *r3, double t)
{
    double u = 1 - t;
    t_pt middle;
    
    *q0 = p0;
    *r3 = p3;

    *q1 = pt_pt_sum(pt_number_prod(p0, u), pt_number_prod(p1, t));
    middle = pt_pt_sum(pt_number_prod(p1, u), pt_number_prod(p2, t));
    *r2 = pt_pt_sum(pt_number_prod(p2, u), pt_number_prod(p3, t));

    *q2 = pt_pt_sum(pt_number_prod(*q1, u), pt_number_prod(middle, t));
    *r1 = pt_pt_sum(pt_number_prod(middle, u), pt_number_prod(*r2, t));

    *q3 = *r0 = pt_pt_sum(pt_number_prod(*q2, u), pt_number_prod(*r1, t));
}


void get_bezier_subdivision_points_do(t_pt p0, t_pt p1, t_pt p2, t_pt p3, double t, long start_idx, long end_idx, t_pt *subd_pts)
{
    long temp = (end_idx - start_idx)/2;
    
    t_pt q0, q1, q2, q3, r0, r1, r2, r3;
    subdivide_bezier(p0, p1, p2, p3, &q0, &q1, &q2, &q3, &r0, &r1, &r2, &r3, t);
    subd_pts[temp - 1] = q3;
    
    if (temp > 1) {
        get_bezier_subdivision_points_do(p0, p1, p2, p3, t, start_idx, start_idx + temp/2, subd_pts);
        get_bezier_subdivision_points_do(p0, p1, p2, p3, t, start_idx + temp/2, end_idx, subd_pts);
    }
}

// subd_pts must ALREADY be allocated, and sized at least 2^order - 1.
// returns 1 if error
char get_bezier_subdivision_points(t_pt p0, t_pt p1, t_pt p2, t_pt p3, double t, long order, t_pt *subd_pts)
{
    long num_segms = iexp2(order);
    long num_pts = num_segms - 1;
    
    if (num_pts < 1)
        return 1; // error : order should be at least 1
    
    get_bezier_subdivision_points_do(p0, p1, p2, p3, t, 0, num_segms, subd_pts);
    return 0;
}


t_pt get_single_bezier_subdivision_point(t_pt p0, t_pt p1, t_pt p2, t_pt p3, double t)
{
    t_pt subd_pt[1];
    get_bezier_subdivision_points(p0, p1, p2, p3, t, 1, subd_pt);
    return subd_pt[0];
}


void paint_simple_curve(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double slope, double width)
{
    double control_point1_x, control_point1_y, control_point2_x, control_point2_y;
    if (fabs(x2 - x1) < CONST_EPSILON3) {
        paint_line(g, color, x1, y1, x2, y2, width);
        return;
    }
    
    // Bezier curve (with 2 internal control points, but they COINCIDE in our scheme!)
    get_bezier_control_points(x1, y1, x2, y2, slope, &control_point1_x, &control_point1_y, &control_point2_x, &control_point2_y, NULL, NULL);
#ifdef BACH_MAX
    jgraphics_set_source_jrgba(g, &color); 
    jgraphics_set_line_width(g, width);
    jgraphics_move_to(g, x1, y1);
    jgraphics_curve_to(g, control_point1_x, control_point1_y, control_point2_x, control_point2_y, x2, y2);
    jgraphics_stroke(g);
#endif
#ifdef BACH_JUCE
    Path p;
    jgraphics_set_source_jrgba(g, &color); 
    p.startNewSubPath(x1, y1);
    p.cubicTo(control_point1_x, control_point1_y, control_point2_x, control_point2_y, x2, y2);
    g->strokePath(p, width);
#endif
    // just to debug: show the control points
//    paint_line(r_ob, g, color, control_point1_x, control_point1_y, control_point2_x, control_point2_y, 1.);                                
}


void paint_tuplet_slur(t_jgraphics* g, t_jrgba color, double x1, double y1, double xm, double ym, double x2, double y2, double width){
    jgraphics_set_source_jrgba(g, &color); 
    jgraphics_set_line_width(g, width);
    jgraphics_move_to(g, x1, y1);
    jgraphics_curve_to(g, xm, ym, xm, ym, x2, y2);
    jgraphics_stroke(g);
}

void get_middle_refinement_point_for_curve(double x1, double y1, double x2, double y2, double *middle_x, double *middle_y, double *middle_derivative, double slope)
{
    double fabs_slope = fabs(slope);
    double chosen_x = (x1 + x2)/2. + slope * fabs_slope * (x2 - x1)/2.; 

    if (fabs_slope > 0.25 && fabs_slope < 1.) {
        // We compute the maximum point of the curvature for a x^a function.
        // Such curvature is given by a*(a-1)*x^(a-2) / (1 + (a^2 x^(2a-2))^3/2,
        // and the non trivial maximum is reached for (\pm (a-2)/(2a^3-a^2))^(1/(2a-2))
        double alpha = (1 + fabs_slope)/(1 - fabs_slope); // this is "a"
        double alpha_squared = alpha*alpha;
        double temp = (alpha - 2)/(2 * alpha_squared * alpha - alpha_squared);
        double temp2 = pow(fabs(temp), 1/(2*alpha - 2));
        if (slope < 0) { temp2 = 1 - temp2; } //temp2 = pow(temp2, alpha);
        double chosen_x_2 = rescale(temp2, 0, 1, x1, x2);
//        chosen_x = chosen_x_2;
        chosen_x = fabs_slope > 0.5 ? chosen_x_2 : rescale(fabs_slope, 0.25, 0.5, chosen_x, chosen_x_2);
    }
    
    *middle_x = chosen_x;
    *middle_y = rescale_with_slope_and_get_derivative(*middle_x, x1, x2, y1, y2, slope, middle_derivative);
 }

void paint_curve(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double slope, double width)
{
    paint_curve_and_get_bezier_control_points(g, color, build_pt(x1, y1), build_pt(x2, y2), slope, width, NULL, NULL, NULL, NULL, NULL);
}

void paint_bezier_curve(t_jgraphics* g, t_jrgba color, double start_x, double start_y, double control_point1_x, double control_point1_y, double control_point2_x, double control_point2_y, double end_x, double end_y, double width)
{
    jgraphics_set_source_jrgba(g, &color);
    jgraphics_set_line_width(g, width);
    jgraphics_move_to(g, start_x, start_y);
    jgraphics_curve_to(g, control_point1_x, control_point1_y, control_point2_x, control_point2_y, end_x, end_y);
    jgraphics_stroke(g);
}

void paint_curve_and_get_bezier_control_points(t_jgraphics* g, t_jrgba color, t_pt start, t_pt end, double slope, double width, 
                                                 t_pt *ctrl1, t_pt *ctrl2, t_pt *middle_pt, t_pt *ctrl3, t_pt *ctrl4)
{
    double middle_x, middle_y, middle_derivative;
    double control_point1_x, control_point1_y, control_point2_x, control_point2_y, control_point3_x, control_point3_y, control_point4_x, control_point4_y;
    double x1 = start.x, y1 = start.y, x2 = end.x, y2 = end.y;
    
    // we don't just paint a Bezier curve: first we split according to a middle point, depending on slope, in order to have a better slope-function approximation.
    if (slope == 0. || x1 == x2 || y1 == y2) { // easy case: it's a line
        if (g)
            paint_line(g, color, x1, y1, x2, y2, width);

        // filling ctrl points with trivial information
        if (ctrl1) {
            ctrl1->x = rescale(1/6., 0, 1, x1, x2);
            ctrl1->y = rescale(1/6., 0, 1, y1, y2);
        }
        if (ctrl2){
            ctrl2->x = rescale(2/6., 0, 1, x1, x2);
            ctrl2->y = rescale(2/6., 0, 1, y1, y2);
        }
        if (middle_pt) {
            middle_pt->x = rescale(0.5, 0, 1, x1, x2);
            middle_pt->y = rescale(0.5, 0, 1, y1, y2);
        }
        if (ctrl3) {
            ctrl3->x = rescale(4/6., 0, 1, x1, x2);
            ctrl3->y = rescale(4/6., 0, 1, y1, y2);
        }
        if (ctrl4) {
            ctrl4->x = rescale(5/6., 0, 1, x1, x2);
            ctrl4->y = rescale(5/6., 0, 1, y1, y2);
        }
        return;
    }

    if (slope < 0) {
        t_pt tcp1, tcp2, tcp3, tcp4;
        slope *= -1;
        get_middle_refinement_point_for_curve(x1, y1, x2, y2, &middle_x, &middle_y, &middle_derivative, slope);
        get_bezier_control_points(x1, y1, middle_x, middle_y, slope, &tcp1.x, &tcp1.y, &tcp2.x, &tcp2.y, NULL, &middle_derivative);
        get_bezier_control_points(middle_x, middle_y, x2, y2, slope, &tcp3.x, &tcp3.y, &tcp4.x, &tcp4.y, &middle_derivative, NULL);
        control_point1_x = x1 + (x2 - tcp4.x);
        control_point2_x = x1 + (x2 - tcp3.x);
        control_point3_x = x1 + (x2 - tcp2.x);
        control_point4_x = x1 + (x2 - tcp1.x);
        control_point1_y = y1 + (y2 - tcp4.y);
        control_point2_y = y1 + (y2 - tcp3.y);
        control_point3_y = y1 + (y2 - tcp2.y);
        control_point4_y = y1 + (y2 - tcp1.y);
        middle_x = x1 + (x2 - middle_x);
        middle_y = y1 + (y2 - middle_y);
    } else {
        get_middle_refinement_point_for_curve(x1, y1, x2, y2, &middle_x, &middle_y, &middle_derivative, slope);
        
        get_bezier_control_points(x1, y1, middle_x, middle_y, slope, &control_point1_x, &control_point1_y, &control_point2_x, &control_point2_y, NULL, &middle_derivative);
        get_bezier_control_points(middle_x, middle_y, x2, y2, slope, &control_point3_x, &control_point3_y, &control_point4_x, &control_point4_y, &middle_derivative, NULL);
    }

#ifdef CONFIGURATION_Development
/*    if (g)
        paint_circle(g, get_grey(0), get_grey(0), middle_x, middle_y, 3, 2);
 */
#endif
    

#ifdef CONFIGURATION_Development
    if (g) {
/*        paint_circle(g, get_grey(0), get_grey(0), control_point1_x, control_point1_y, 3, 2);
        paint_circle(g, get_grey(0.8), get_grey(0.8), control_point2_x, control_point2_y, 3, 2);
        paint_circle(g, get_grey(0.6), get_grey(0.6), control_point3_x, control_point3_y, 3, 2);
        paint_circle(g, get_grey(0.4), get_grey(0.4), control_point4_x, control_point4_y, 3, 2);

        paint_circle(g, color, color, middle_x, middle_y, 1, 2);
        
        
        long i;
        for (i = 0; i < 200; i++) {
            double derivative, temp_x = rescale(i, 0, 200, x1, x2);
            double temp_y = rescale_with_slope_and_get_derivative(temp_x, x1, x2, y1, y2, slope, &derivative);
            paint_circle(g, color, color, temp_x, temp_y, 0.2, 1);
        } */
    }
#endif
    
    if (ctrl1)
        *ctrl1 = build_pt(control_point1_x, control_point1_y);
    if (ctrl2)
        *ctrl2 = build_pt(control_point2_x, control_point2_y);
    if (middle_pt)
        *middle_pt = build_pt(middle_x, middle_y);
    if (ctrl3)
        *ctrl3 = build_pt(control_point3_x, control_point3_y);
    if (ctrl4)
        *ctrl4 = build_pt(control_point4_x, control_point4_y);
        
    if (g) {
#ifdef BACH_MAX
        jgraphics_set_source_jrgba(g, &color); jgraphics_set_line_width(g, width);
        jgraphics_move_to(g, x1, y1);
        jgraphics_curve_to(g, control_point1_x, control_point1_y, control_point2_x, control_point2_y, middle_x, middle_y);
        jgraphics_curve_to(g, control_point3_x, control_point3_y, control_point4_x, control_point4_y, x2, y2);
        jgraphics_stroke(g);
#endif
#ifdef BACH_JUCE
        Path p;
        jgraphics_set_source_jrgba(g, &color);
        p.startNewSubPath(x1, y1);
        p.cubicTo(control_point1_x, control_point1_y, control_point2_x, control_point2_y, middle_x, middle_y);
        p.cubicTo(control_point3_x, control_point3_y, control_point4_x, control_point4_y, x2, y2);
        g->strokePath(p, width);
#endif
    
#ifdef CONFIGURATION_Development
        // DEBUG
/*        t_jrgba red; red.green = 0.; red.blue = 0.; red.red = 1.; red.alpha = 1.;
        t_jrgba blue; blue.green = 0.; blue.blue = 1.; blue.red = 0.; blue.alpha = 1.;
        paint_line(g, red, x1, y1, control_point1_x, control_point1_y, 1.);
        paint_line(g, red, control_point1_x, control_point1_y, control_point2_x, control_point2_y, 1.);                                
        paint_line(g, red, control_point2_x, control_point2_y, middle_x, middle_y, 1.);                                
        paint_line(g, blue, middle_x, middle_y, control_point3_x, control_point3_y, 1.);
        paint_line(g, blue, control_point3_x, control_point3_y, control_point4_x, control_point4_y, 1.);                                
        paint_line(g, blue, control_point4_x, control_point4_y, x2, y2, 1.);
 */
#endif

    }
}


void paint_doublewidth_curve(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double slope, double width_start, double width_end){
    double middle_x, middle_y, middle_derivative;
    double hdyi, hdy1, hdy2, hdym, hdy3, hdy4, hdye; // half vertical corrections of bezier points (i = initial, 1 2 are control points, m is medium point, 3 4 are control points e is end point)
    double hdxi = 0, hdx1 = 0, hdx2 = 0, hdxm = 0, hdx3 = 0, hdx4 = 0, hdxe = 0; // half-horizontal corrections (initial, end)
    double control_point1_x, control_point1_y, control_point2_x, control_point2_y, control_point3_x, control_point3_y, control_point4_x, control_point4_y;
    double alpha1, alpham, alpha2, sinalpha1, sinalpham, sinalpha2, cosalpha1, cosalpham, cosalpha2;
    // we don't just paint a Bezier curve: first we split according to a middle point, depending on slope, in order to have a better slope-function approximation.
    if ((slope == 0.) || (x1 == x2) || (y1 == y2)) { // easy case: it's a line
        paint_doublewidth_line(g, color, x1, y1, x2, y2, width_start, width_end);
        return;
    }

    slope = CLAMP(slope, -0.999, 0.999);
    
    if (slope < 0) {
        t_pt tcp1, tcp2, tcp3, tcp4;
        slope *= -1;
        get_middle_refinement_point_for_curve(x1, y1, x2, y2, &middle_x, &middle_y, &middle_derivative, slope);
        get_bezier_control_points(x1, y1, middle_x, middle_y, slope, &tcp1.x, &tcp1.y, &tcp2.x, &tcp2.y, NULL, &middle_derivative);
        get_bezier_control_points(middle_x, middle_y, x2, y2, slope, &tcp3.x, &tcp3.y, &tcp4.x, &tcp4.y, &middle_derivative, NULL);
        control_point1_x = x1 + (x2 - tcp4.x);
        control_point2_x = x1 + (x2 - tcp3.x);
        control_point3_x = x1 + (x2 - tcp2.x);
        control_point4_x = x1 + (x2 - tcp1.x);
        control_point1_y = y1 + (y2 - tcp4.y);
        control_point2_y = y1 + (y2 - tcp3.y);
        control_point3_y = y1 + (y2 - tcp2.y);
        control_point4_y = y1 + (y2 - tcp1.y);
        middle_x = x1 + (x2 - middle_x);
        middle_y = y1 + (y2 - middle_y);
    } else {
        get_middle_refinement_point_for_curve(x1, y1, x2, y2, &middle_x, &middle_y, &middle_derivative, slope);
        get_bezier_control_points(x1, y1, middle_x, middle_y, slope, &control_point1_x, &control_point1_y, &control_point2_x, &control_point2_y, NULL, &middle_derivative);
        get_bezier_control_points(middle_x, middle_y, x2, y2, slope, &control_point3_x, &control_point3_y, &control_point4_x, &control_point4_y, &middle_derivative, NULL);
        
    }

    // changing one control point to preserve first derivative
//    middle_x = (control_point2_x + control_point3_x)/2.;
//    middle_y = (control_point2_y + control_point3_y)/2.;

    // overall distances on each point
    hdyi = 0.5 * width_start;
    hdy1 = 0.5 * (width_start + (width_end - width_start) * (control_point1_x - x1) / (x2 - x1));
    hdy2 = 0.5 * (width_start + (width_end - width_start) * (control_point2_x - x1) / (x2 - x1));
    hdym = 0.5 * (width_start + (width_end - width_start) * (middle_x - x1) / (x2 - x1));
    hdy3 = 0.5 * (width_start + (width_end - width_start) * (control_point3_x - x1) / (x2 - x1));
    hdy4 = 0.5 * (width_start + (width_end - width_start) * (control_point4_x - x1) / (x2 - x1));
    hdye = 0.5 * width_end;

    alpha1 = (middle_x - x1 < CONST_EPSILON5) ? -PIOVERTWO : atan((middle_y - y1)/(middle_x - x1)); 
    alpham = (x2 - x1 < CONST_EPSILON5) ? -PIOVERTWO : atan((y2 - y1)/(x2 - x1)); 
    alpha2 = (x2 - middle_x < CONST_EPSILON5) ? -PIOVERTWO : atan((y2 - middle_y)/(x2 - middle_x));
    sinalpha1 = sin(alpha1); cosalpha1 = cos(alpha1); 
    sinalpham = sin(alpham); cosalpham = cos(alpham);
    sinalpha2 = sin(alpha2); cosalpha2 = cos(alpha2); 
    hdxi = - hdyi * sinalpha1; hdyi = hdyi * cosalpha1;
    hdx1 = - hdy1 * sinalpha1; hdy1 = hdy1 * cosalpha1;
    hdx2 = - hdy2 * sinalpha1; hdy2 = hdy2 * cosalpha1;
    hdxm = - hdym * sinalpham; hdym = hdym * cosalpham;
    hdx3 = - hdy3 * sinalpha2; hdy3 = hdy3 * cosalpha2;
    hdx4 = - hdy4 * sinalpha2; hdy4 = hdy4 * cosalpha2;
    hdxe = - hdye * sinalpha2; hdye = hdye * cosalpha2;
    
#ifdef BACH_MAX    
    jgraphics_set_source_jrgba(g, &color); 
    jgraphics_set_line_width(g, 0);
    jgraphics_move_to(g, x1 - hdxi, y1 - hdyi);
    jgraphics_curve_to(g, control_point1_x - hdx1, control_point1_y - hdy1, control_point2_x - hdx2, control_point2_y - hdy2, middle_x - hdxm, middle_y - hdym);
    jgraphics_curve_to(g, control_point3_x - hdx3, control_point3_y - hdy3, control_point4_x - hdx4, control_point4_y - hdy4, x2 - hdxe, y2 - hdye);
    jgraphics_line_to(g, x2 + hdxe, y2 + hdye);
    jgraphics_curve_to(g, control_point4_x + hdx4, control_point4_y + hdy4, control_point3_x + hdx3, control_point3_y + hdy3, middle_x + hdxm, middle_y + hdym);
    jgraphics_curve_to(g, control_point2_x + hdx2, control_point2_y + hdy2, control_point1_x + hdx1, control_point1_y + hdy1, x1 + hdxi, y1 + hdyi);
    jgraphics_close_path(g);
    jgraphics_fill(g);
#endif
#ifdef BACH_JUCE
    Path p;
    jgraphics_set_source_jrgba(g, &color); 
    p.startNewSubPath(x1 - hdxi, y1 - hdyi);
    p.cubicTo(control_point1_x - hdx1, control_point1_y - hdy1, control_point2_x - hdx2, control_point2_y - hdy2, middle_x - hdxm, middle_y - hdym);
    p.cubicTo(control_point3_x - hdx3, control_point3_y - hdy3, control_point4_x - hdx4, control_point4_y - hdy4, x2 - hdxe, y2 - hdye);
    p.lineTo(x2 + hdxe, y2 + hdye);
    p.cubicTo(control_point4_x + hdx4, control_point4_y + hdy4, control_point3_x + hdx3, control_point3_y + hdy3, middle_x + hdxm, middle_y + hdym);
    p.cubicTo(control_point2_x + hdx2, control_point2_y + hdy2, control_point1_x + hdx1, control_point1_y + hdy1, x1 + hdxi, y1 + hdyi);
    p.closeSubPath();
    g->fillPath(p);
#endif
    
/*    // DEBUG
    t_jrgba red; red.green = 0.; red.blue = 0.; red.red = 1.; red.alpha = 1.;
    t_jrgba blue; blue.green = 0.; blue.blue = 1.; blue.red = 0.; blue.alpha = 1.;
    t_jrgba green; green.green = 1.; green.blue = 0.; green.red = 0.; green.alpha = 1.;
    t_jrgba yellow; yellow.green = 1.; yellow.blue = 1.; yellow.red = 0.; yellow.alpha = 1.;
    t_jrgba rosa; rosa.green = 0.2; rosa.blue = 0.1; yellow.red = 0.7; yellow.alpha = 1.;
    paint_line(r_ob, g, red, x1 - hdxi, y1 - hdyi, control_point1_x - hdx1, control_point1_y - hdy1, 1.);
    paint_line(r_ob, g, red, control_point1_x - hdx1, control_point1_y - hdy1, control_point2_x - hdx2, control_point2_y - hdy2, 1.);                                
    paint_line(r_ob, g, red, control_point2_x - hdx2, control_point2_y - hdy2, middle_x - hdxm, middle_y - hdym, 1.);                                
    paint_line(r_ob, g, green, x1 + hdxi, y1 + hdyi, control_point1_x + hdx1, control_point1_y + hdy1, 1.);
    paint_line(r_ob, g, green, control_point1_x + hdx1, control_point1_y + hdy1, control_point2_x + hdx2, control_point2_y + hdy2, 1.);                                
    paint_line(r_ob, g, green, control_point2_x + hdx2, control_point2_y + hdy2, middle_x + hdxm, middle_y + hdym, 1.);                                
    paint_line(r_ob, g, blue, middle_x - hdxm, middle_y - hdym, control_point3_x - hdx3, control_point3_y - hdy3, 1.);
    paint_line(r_ob, g, blue, control_point3_x - hdx3, control_point3_y - hdy3, control_point4_x - hdx4, control_point4_y - hdy4, 1.);                                
    paint_line(r_ob, g, blue, control_point4_x - hdx4, control_point4_y - hdy4, x2 - hdxe, y2 - hdye, 1.);                                
    paint_line(r_ob, g, yellow, middle_x + hdxm, middle_y + hdym, control_point3_x + hdx3, control_point3_y + hdy3, 1.);
    paint_line(r_ob, g, yellow, control_point3_x + hdx3, control_point3_y + hdy3, control_point4_x + hdx4, control_point4_y + hdy4, 1.);                                
    paint_line(r_ob, g, yellow, control_point4_x + hdx4, control_point4_y + hdy4, x2 + hdxe, y2 + hdye, 1.);                                
    paint_line(r_ob, g, rosa, x1, y1, control_point1_x, control_point1_y, 1.);
    paint_line(r_ob, g, rosa, control_point1_x, control_point1_y, control_point2_x, control_point2_y, 1.);                                
    paint_line(r_ob, g, rosa, control_point2_x, control_point2_y, middle_x, middle_y, 1.);                                
    paint_line(r_ob, g, rosa, middle_x, middle_y, control_point3_x, control_point3_y, 1.);
    paint_line(r_ob, g, rosa, control_point3_x, control_point3_y, control_point4_x, control_point4_y, 1.);                                
    paint_line(r_ob, g, rosa, control_point4_x, control_point4_y, x2, y2, 1.);    */                
}

void paint_colorgradient_line(t_jgraphics* g, t_jrgba color_start, t_jrgba color_end, double x1, double y1, double x2, double y2, double width, long num_steps,
                                char colors_from_spectrum, double vel1, double vel2, double max_velocity){ // last 3 args only used in spectrum velocity handling
    long i;
    long numstepsminus1 = num_steps - 1;
    double x_step = (x2 - x1) / num_steps;
    double y_step = (y2 - y1) / num_steps;
    double vel_step = (vel2 - vel1) / numstepsminus1;
    if (num_steps < 0) return;

#ifdef BACH_MAX
    jgraphics_set_line_width(g,width);
#endif

    for (i = 0; i < num_steps; i++) {
        t_jrgba thiscolor;
        if (colors_from_spectrum)
            thiscolor = double_to_color((num_steps == 1) ? vel1 : vel1 + ((double)i) * vel_step, 0, max_velocity, false);
        else
            thiscolor = color_interp(color_start, color_end, (num_steps == 1) ? 1 : ((double)i) / numstepsminus1);
#ifdef BACH_MAX
        jgraphics_move_to(g, x1 + i * x_step, y1 + i * y_step);
        jgraphics_line_to(g, x1 + (i + 1) * x_step, y1 + (i+1) * y_step);
        jgraphics_set_source_jrgba(g, &thiscolor);
        jgraphics_stroke(g); 
#endif
#ifdef BACH_JUCE
        jgraphics_set_source_jrgba(g, &thiscolor);
        g->drawLine(x1 + i * x_step, y1 + i * y_step, x1 + (i + 1) * x_step, y1 + (i+1) * y_step, width);
#endif
    }
}

void paint_colorgradient_curve(t_jgraphics* g, t_jrgba color_start, t_jrgba color_end, double x1, double y1, double x2, double y2, double slope, double width, long num_steps,
                                char colors_from_spectrum, double vel1, double vel2, double max_velocity){ // last 3 args only used in spectrum velocity handling
    double middle_x, middle_y, middle_derivative;
    double control_point1_x, control_point1_y, control_point2_x, control_point2_y, control_point3_x, control_point3_y, control_point4_x, control_point4_y;
    // we don't just paint a Bezier curve: first we split according to a middle point, depending on slope, in order to have a better slope-function approximation.
    if ((slope == 0.) || (x1 == x2) || (y1 == y2)) { // easy case: it's a line
        paint_colorgradient_line(g, color_start, color_end, x1, y1, x2, y2, width, num_steps, colors_from_spectrum, vel1, vel2, max_velocity);
        return;
    }

    if (slope < 0) {
        t_pt tcp1, tcp2, tcp3, tcp4;
        slope *= -1;
        get_middle_refinement_point_for_curve(x1, y1, x2, y2, &middle_x, &middle_y, &middle_derivative, slope);
        get_bezier_control_points(x1, y1, middle_x, middle_y, slope, &tcp1.x, &tcp1.y, &tcp2.x, &tcp2.y, NULL, &middle_derivative);
        get_bezier_control_points(middle_x, middle_y, x2, y2, slope, &tcp3.x, &tcp3.y, &tcp4.x, &tcp4.y, &middle_derivative, NULL);
        control_point1_x = x1 + (x2 - tcp4.x);
        control_point2_x = x1 + (x2 - tcp3.x);
        control_point3_x = x1 + (x2 - tcp2.x);
        control_point4_x = x1 + (x2 - tcp1.x);
        control_point1_y = y1 + (y2 - tcp4.y);
        control_point2_y = y1 + (y2 - tcp3.y);
        control_point3_y = y1 + (y2 - tcp2.y);
        control_point4_y = y1 + (y2 - tcp1.y);
        middle_x = x1 + (x2 - middle_x);
        middle_y = y1 + (y2 - middle_y);
    } else {
        get_middle_refinement_point_for_curve(x1, y1, x2, y2, &middle_x, &middle_y, &middle_derivative, slope);
        get_bezier_control_points(x1, y1, middle_x, middle_y, slope, &control_point1_x, &control_point1_y, &control_point2_x, &control_point2_y, NULL, &middle_derivative);
        get_bezier_control_points(middle_x, middle_y, x2, y2, slope, &control_point3_x, &control_point3_y, &control_point4_x, &control_point4_y, &middle_derivative, NULL);
    }
    
    // changing a control point to preserve first derivative
    middle_x = (control_point2_x + control_point3_x)/2.;
    middle_y = (control_point2_y + control_point3_y)/2.;

#ifdef BACH_MAX
    jgraphics_set_source_jrgba(g, &color_start); 
    jgraphics_set_line_width(g, width);
    jgraphics_move_to(g, x1, y1);
    jgraphics_curve_to(g, control_point1_x, control_point1_y, control_point2_x, control_point2_y, middle_x, middle_y);
    jgraphics_stroke(g);

    jgraphics_set_source_jrgba(g, &color_end); 
    jgraphics_set_line_width(g, width);
    jgraphics_move_to(g, middle_x, middle_y);
    jgraphics_curve_to(g, control_point3_x, control_point3_y, control_point4_x, control_point4_y, x2, y2);
    jgraphics_stroke(g);
#endif
    
#ifdef BACH_JUCE
    Path p;
    p.startNewSubPath(x1, y1);
    p.cubicTo(control_point1_x, control_point1_y, control_point2_x, control_point2_y, middle_x, middle_y);
    jgraphics_set_source_jrgba(g, &color_start);
    g->strokePath(p, width);
    p.clear();
    p.startNewSubPath(middle_x, middle_y);
    p.cubicTo(control_point3_x, control_point3_y, control_point4_x, control_point4_y, x2, y2);
    jgraphics_set_source_jrgba(g, &color_end);
    g->strokePath(p, width);
#endif
    
/*    // DEBUG
    t_jrgba red; red.green = 0.; red.blue = 0.; red.red = 1.; red.alpha = 1.;
    t_jrgba blue; blue.green = 0.; blue.blue = 1.; blue.red = 0.; blue.alpha = 1.;
    paint_line(r_ob, g, red, x1, y1, control_point1_x, control_point1_y, 1.);
    paint_line(r_ob, g, red, control_point1_x, control_point1_y, control_point2_x, control_point2_y, 1.);                                
    paint_line(r_ob, g, red, control_point2_x, control_point2_y, middle_x, middle_y, 1.);                                
    paint_line(r_ob, g, blue, middle_x, middle_y, control_point3_x, control_point3_y, 1.);
    paint_line(r_ob, g, blue, control_point3_x, control_point3_y, control_point4_x, control_point4_y, 1.);                                
    paint_line(r_ob, g, blue, control_point4_x, control_point4_y, x2, y2, 1.);*/                                
}


void paint_arrow(t_jgraphics* g, t_jrgba color, double x1, double y1, double x2, double y2, double width, double arrow_height, double arrow_width){
    double pt1_x, pt1_y, pt2_x, pt2_y, alpha;
    double S = arrow_height;
    double T = arrow_width * 0.5;
    
    // line
    paint_line(g, color, x1, y1, x2, y2, width);
    
    // arrow
    if (x2 == x1)
        alpha = (y2 < y1) ? PIOVERTWO : PIOVERTWO * 3;
    else {
        double ratio = (y1 - y2)/(x2 - x1);
        alpha = atan(ratio);
        if (x2 - x1 < 0)
            alpha += PI;
    }
    
    pt1_x = x2 - S * cos(alpha) - T * sin(alpha);
    pt2_x = pt1_x + 2 * T * sin(alpha);
    pt1_y = y2 + S * sin(alpha) - T * cos(alpha);
    pt2_y = pt1_y + 2 * T * cos(alpha);
    jgraphics_set_source_jrgba(g, &color); 
    jgraphics_set_line_width(g, 0.);
    jgraphics_move_to(g, x2, y2);
    jgraphics_line_to(g, pt1_x, pt1_y);
    jgraphics_line_to(g, pt2_x, pt2_y);
    jgraphics_close_path(g); 
    jgraphics_fill(g);    
}

t_jrgba color_interp(t_jrgba color1, t_jrgba color2, double parameter){
    t_jrgba outcolor;
    outcolor.red = color1.red * (1 - parameter) + color2.red * parameter; 
    outcolor.blue = color1.blue * (1 - parameter) + color2.blue * parameter; 
    outcolor.green = color1.green * (1 - parameter) + color2.green * parameter; 
    outcolor.alpha = color1.alpha * (1 - parameter) + color2.alpha * parameter; 
    return outcolor;
}

t_jrgba change_luminosity(t_jrgba color, double factor){
    t_jrgba new_color;
    new_color.red = CLAMP(color.red * factor, 0., 1.);
    new_color.green = CLAMP(color.green * factor, 0., 1.);
    new_color.blue = CLAMP(color.blue * factor, 0., 1.);
    new_color.alpha = color.alpha;
    return new_color;
}

t_jrgba add_luminosity(t_jrgba color, double add){
    t_jrgba new_color;
    new_color.red = CLAMP(color.red + add, 0., 1.);
    new_color.green = CLAMP(color.green + add, 0., 1.);
    new_color.blue = CLAMP(color.blue + add, 0., 1.);
    new_color.alpha = color.alpha;
    return new_color;
}




t_jhsla rgba_to_hsla(t_jrgba color)
{
    t_jhsla res;
    res.hue = 0;
    res.lightness = 0;
    res.saturation = 0;
    
    double max_rgb = MAX(MAX(color.red, color.green), color.blue);
    double min_rgb = MIN(MIN(color.red, color.green), color.blue);
    double chroma = max_rgb - min_rgb;
    
    double h_prime = 0.;
    
    if (chroma == 0.)
        h_prime = 0.;
    else if (max_rgb == color.red)
        h_prime = fmod((color.green - color.blue)/chroma, 6);
    else if (max_rgb == color.green)
        h_prime = (color.blue - color.red)/chroma + 2;
    else if (max_rgb == color.blue)
        h_prime = (color.red - color.green)/chroma + 4;

    res.hue = positive_fmod(h_prime * PI / 3., TWOPI);
    res.lightness = max_rgb * 0.5 + min_rgb * 0.5;
    res.saturation = (chroma == 0. ? 0 : chroma/(1 - fabs(2 * res.lightness - 1)));
    res.alpha = color.alpha;
    
    return res;
}

// http://en.wikipedia.org/wiki/HSL_and_HSV#Converting_to_RGB
t_jrgba hsla_to_rgba(t_jhsla color)
{
    t_jrgba res = build_jrgba(0, 0, 0, 1);
    double chroma = (1 - fabs(2 * color.lightness - 1)) * color.saturation;
    double h_prime = color.hue/(PI / 3.);
    double x = chroma * (1 - fabs(fmod(h_prime, 2) - 1));

    if (h_prime >= 0 && h_prime < 1) {
        res.red = chroma; res.green = x; res.blue = 0;
    } else if (h_prime >= 1 && h_prime < 2) {
        res.red = x; res.green = chroma; res.blue = 0;
    } else if (h_prime >= 2 && h_prime < 3) {
        res.red = 0; res.green = chroma; res.blue = x;
    } else if (h_prime >= 3 && h_prime < 4) {
        res.red = 0; res.green = x; res.blue = chroma;
    } else if (h_prime >= 4 && h_prime < 5) {
        res.red = x; res.green = 0; res.blue = chroma;
    } else if (h_prime >= 5 && h_prime < 6) {
        res.red = chroma; res.green = 0; res.blue = x;
    }
    
    double m = color.lightness - chroma/2.;
    
    res.red += m;
    res.green += m;
    res.blue += m;
    res.alpha = color.alpha;
    
    return res;
}


t_jrgba change_alpha(t_jrgba color, double new_alpha){
    t_jrgba new_color;
    new_color.red = color.red;
    new_color.green = color.green;
    new_color.blue = color.blue;
    new_color.alpha = new_alpha;
    return new_color;
}

t_jrgba color_alphablend(t_jrgba color1, t_jrgba color2){
    t_jrgba outcolor;
    outcolor.red = color1.red * color1.alpha + (1 - color1.alpha)*color2.alpha * color2.red; 
    outcolor.blue = color1.blue * color1.alpha + (1 - color1.alpha)*color2.alpha * color2.blue; 
    outcolor.green = color1.green * color1.alpha + (1 - color1.alpha)*color2.alpha * color2.green; 
    outcolor.alpha =  1 - (1 - color1.alpha ) * (1 - color2.alpha); 
    return outcolor;
}

t_jrgba get_grey(double param){
    t_jrgba res_col;
    res_col.red = param; 
    res_col.green = param; 
    res_col.blue = param; 
    res_col.alpha = 1.; 
    return res_col;
}

t_jrgba build_jrgba(double r, double g, double b, double a){
    t_jrgba res_col;
    res_col.red = r; 
    res_col.green = g; 
    res_col.blue = b; 
    res_col.alpha = a; 
    return res_col;
}

t_rect build_rect(double x, double y, double width, double height) {
    t_rect rect;
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
    return rect;
}

t_pt build_pt(double x, double y){
    t_pt pt;
    pt.x = x;
    pt.y = y;
    return pt;
}

double pt_pt_distance_squared(t_pt pt1, t_pt pt2){
    t_pt diff;
    diff.x = pt2.x - pt1.x;
    diff.y = pt2.y - pt1.y;
    return diff.x * diff.x  + diff.y * diff.y;
}

double pt_pt_distance(t_pt pt1, t_pt pt2){
    return sqrt(pt_pt_distance_squared(pt1, pt2));
}

double pt_norm(t_pt pt)
{
    return sqrt(pt.x * pt.x + pt.y * pt.y);
}


char are_colors_equal(t_jrgba color1, t_jrgba color2, double epsilon){
    if (fabs(color1.red - color2.red) > epsilon)
        return false;

    if (fabs(color1.green - color2.green) > epsilon)
        return false;

    if (fabs(color1.blue - color2.blue) > epsilon)
        return false;

    if (fabs(color1.alpha - color2.alpha) > epsilon)
        return false;

    return true;
}


t_jrgba get_grey_to_write_over_color(t_jrgba color, double grey_offset){
    double lightness = get_lightness(color);
    if (lightness < 0.3)
        return get_grey(1 - grey_offset);
    else 
        return get_grey(grey_offset);
}

void correct_color_to_write_over_color(t_jrgba *color, t_jrgba color_to_write_on){
    double lightness1 = get_lightness(*color);
    double lightness2 = get_lightness(color_to_write_on);
    if (fabs(lightness1 - lightness2) < 0.35) {
        (*color).red = 1 - (*color).red;
        (*color).green = 1 - (*color).green;
        (*color).blue = 1 - (*color).blue;
    }
}


void apply_velocity_colorscale(t_jrgba *color, double velocity)
{
    double temp = (1. - (((double)velocity - CONST_MIN_VELOCITY)/(CONST_MAX_VELOCITY - CONST_MIN_VELOCITY)));
    //rescaling the temp
    temp = temp * 0.8;
    color->red = (1. - temp) * color->red + temp;
    color->blue = (1. - temp) * color->blue + temp;
    color->green = (1. - temp) * color->green + temp;
}


void apply_velocity_colorspectrum(t_jrgba *color, double velocity)
{
    *color = double_to_color(((double)velocity), CONST_MIN_VELOCITY, CONST_MAX_VELOCITY, false);
}

void apply_velocity_alphascale(t_jrgba *color, double velocity)
{
    double factor = ((double)velocity - CONST_MIN_VELOCITY)/(CONST_MAX_VELOCITY - CONST_MIN_VELOCITY);
    color->alpha = (0.7 * factor + 0.3) * color->alpha;
}


t_jrgba double_to_color(double value, double min, double max, char looped)
{
    t_jrgba out_color = build_jrgba(0, 0, 0, 1);
    double temp;
    if (max == min) { 
        min = 0.; 
        max = 1; 
    }
    temp = (looped ? 6. : 5) * (value - min)/ (max-min);
    if (temp >= 0 && temp <= 1){
        out_color.red = 1;
        out_color.green = temp;
    } else if (temp >= 1 && temp <= 2){
        out_color.green = 1;
        out_color.red = 2 - temp;
    } else if (temp >= 2 && temp <= 3){
        out_color.green = 1;
        out_color.blue = temp - 2;
    } else if (temp >= 3 && temp <= 4){
        out_color.blue = 1;
        out_color.green = 4 - temp;
    } else if (temp >= 4 && temp <= 5){
        out_color.blue = 1;
        out_color.red = temp - 4;
    } else {
        out_color.red = 1;
        out_color.blue = 6 - temp;
    }
    
//    return out_color;

    t_jhsla color_hsla = rgba_to_hsla(out_color);
    color_hsla.saturation /= 2;
    return hsla_to_rgba(color_hsla);
}

double color_to_double(t_jrgba color, double min, double max, char looped){
    t_jrgba thiscolor = get_01normalized_color(color);
    double val; // will be between 0 and 5 or 6 (depending if looped is off or on
    if (thiscolor.red == 1 && thiscolor.blue == 0){
        val = thiscolor.green;
    } else if (thiscolor.green == 1 && thiscolor.blue == 0){
        val = 2 - thiscolor.red;
    } else if (thiscolor.red == 0 && thiscolor.green == 1){
        val = 2 + thiscolor.blue;
    } else if (thiscolor.red == 0 && thiscolor.blue == 1){
        val = 4 - thiscolor.green;
    } else if (thiscolor.green == 0 && thiscolor.blue == 1){
        val = 4 + thiscolor.red;
    } else {
        val = 6 - thiscolor.blue;
    }
    return min + (max - min) * (looped ? val/6 : val/5);
}

t_jrgba long_to_color(long value){
    t_jrgba out_color;
    if (value < 0) value = 0;
    switch (value % 10) {
        case 0:
            out_color.red = 0.77;
            out_color.green = 0.11;
            out_color.blue = 0.; 
            break;
        case 1:
            out_color.red = 0.57;
            out_color.green = 0.41;
            out_color.blue = 0.0;
            break;
        case 2:
            out_color.red = 0.0;
            out_color.green = 0.53;
            out_color.blue = 0.03; 
            break;
        case 3:
            out_color.red = 0.88; 
            out_color.green = 0.42; 
            out_color.blue = 0.04; 
            break;
        case 4:
            out_color.red = 0.05; 
            out_color.green = 0.62; 
            out_color.blue = 0.87; 
            break;
        case 5:
            out_color.red = 0.;
            out_color.green = 0.;
            out_color.blue = 0.81;
            break;
        case 6:
            out_color.red = 0.;
            out_color.green = 0.61;
            out_color.blue = 0.42;
            break;
        case 7:
            out_color.red = 0.68;
            out_color.green = 0.77;
            out_color.blue = 0.;
            break;
        case 8:
            out_color.red = 0.53;
            out_color.green = 0.;
            out_color.blue = 0.59;
            break;
        default:
            out_color.red = 0.84;
            out_color.green = 0.69;
            out_color.blue = 0.;
            break;
    }
    out_color.alpha = 1.;
    return out_color;
}


char get_color_xy_coordinates(t_jrgba color, double *x_coord, double *y_coord){
    double min = MIN(MIN(color.red, color.green), color.blue);
    double max = MAX(MAX(color.red, color.green), color.blue);
    *y_coord = max;
    if (max > 0) {
        *x_coord = (max - min)/max;
        return 0;
    } else {
        *x_coord = 0;
        return 1;
    }
}


void assure_color_goodness(t_jrgba *color){
    clip_double(&color->red, 0, 1);
    clip_double(&color->green, 0, 1);
    clip_double(&color->blue, 0, 1);
    clip_double(&color->alpha, 0, 1);
}

t_jrgba xy_coordinates_to_color(double x_coord, double y_coord, t_jrgba toprightcornercolor){
    t_jrgba this_col = color_interp(color_interp(get_grey(1), toprightcornercolor, x_coord), get_grey(0), 1 - y_coord);
    this_col.alpha = toprightcornercolor.alpha;
    assure_color_goodness(&this_col);
    return this_col;
}

t_jrgba get_01normalized_color(t_jrgba color){
    return get_0normalized_color(get_1normalized_color(color));
}

t_jrgba get_1normalized_color(t_jrgba color){
    t_jrgba out_color = color;

    if (out_color.red == 0 && out_color.green == 0 && out_color.blue == 0) // black
        return color;
    
    if (color.red >= color.green && color.red >= color.blue) {
        out_color.green /= out_color.red;
        out_color.blue /= out_color.red;
        out_color.red = 1;
    } else if (color.green >= color.red && color.green >= color.blue) {
        out_color.red /= out_color.green;
        out_color.blue /= out_color.green;
        out_color.green = 1;
    } else {
        out_color.red /= out_color.blue;
        out_color.green /= out_color.blue;
        out_color.blue = 1;
    }
    assure_color_goodness(&out_color);
    return out_color;
}


// min is mapped on 0
// max is mapped on max
// map is: x * (x - min)/(max - min)
t_jrgba get_0normalized_color(t_jrgba color){
    t_jrgba out_color = color;
    double min = MIN(MIN(color.red, color.green), color.blue);
    double max = MAX(MAX(color.red, color.green), color.blue);
    if (min == max) {
        out_color.red = 1;
        out_color.green = out_color.blue = 0;
    } else {
        out_color.red *= (out_color.red - min)/(max - min); 
        out_color.green *= (out_color.green - min)/(max - min); 
        out_color.blue *= (out_color.blue - min)/(max - min); 
    }
    assure_color_goodness(&out_color);
    return out_color;
}


double get_lightness(t_jrgba color){
    double min = MIN(MIN(color.red, color.green), color.blue);
    double max = MAX(MAX(color.red, color.green), color.blue);
    double mean = (min + max)/2.;
    return mean + (1 - color.alpha) * (1 - mean);
}


char are_pts_aligned(double x0, double y0, double x1, double y1, double x2, double y2) {
    double cross_prod = (y0 - y1) * (x2 - x1) - (x0 - x1) * (y2 - y1);

    if (fabs(cross_prod) > CONST_EPSILON_ALIGNMENTS)
        return false;

    return true;
}

char is_pt_in_segment(double ptx, double pty, double x1, double y1, double x2, double y2) {
    double dot_prod, square_length_12;

    if (!are_pts_aligned(ptx, pty, x1, y1, x2, y2))
        return false;
    
    dot_prod = (ptx - x1) * (x2 - x1) + (pty - y1) * (y2 - y1);
    
    if (dot_prod < 0)
        return false;
        
    square_length_12 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    
    if (dot_prod > square_length_12)
        return false;
        
    return true;
}

char is_pt_above_segment(double ptx, double pty, double x1, double y1, double x2, double y2) {
/*    double cross_prod;
    if (x2 < x1) {
        double temp;
        temp = x1; x1 = x2; x2 = temp;
        temp = y1; y1 = y2; y2 = temp;
    }     
    cross_prod = (pty - y1) * (x2 - x1) - (ptx - x1) * (y2 - y1);

    if (cross_prod > 0)
        return true;

    return false;*/
    
    double dist = pt_line_distance_vertical(ptx, pty, x1, y1, x2, y2);
    return (dist > 0) ? true : false;
}

char is_pt_in_rectangle(t_pt pt, t_rect rect) {
    if (pt.x >= rect.x && pt.x <= rect.x + rect.width && pt.y >= rect.y && pt.y <= rect.y + rect.height)
        return 1;
    return 0;
}

char is_pt_in_rectangle_tolerance(t_pt pt, t_rect rect, double tolerance) {
    if (pt.x >= rect.x - tolerance && pt.x <= rect.x + rect.width + tolerance && pt.y >= rect.y - tolerance && pt.y <= rect.y + rect.height + tolerance)
        return 1;
    return 0;
}

char is_pt_in_triangle(double ptx, double pty, double x1, double y1, double x2, double y2, double x3, double y3) {
    double det_delta = compute_det_for_matrix_of_size_3(x1, x2, x3, y1, y2, y3, 1, 1, 1);
    if (fabs(det_delta) > CONST_EPSILON_ALIGNMENTS){
        double u1 = compute_det_for_matrix_of_size_3(ptx, x2, x3, pty, y2, y3, 1, 1, 1) / det_delta;
        double u2 = compute_det_for_matrix_of_size_3(x1, ptx, x3, y1, pty, y3, 1, 1, 1) / det_delta;
        double u3 = compute_det_for_matrix_of_size_3(x1, x2, ptx, y1, y2, pty, 1, 1, 1) / det_delta;
        // u1 u2 and u3 are the areas of the subtriangles P12 P23 P13. They all have to be > 0 in order to P be inside triangle 123 
        if (u1 >= 0 && u2 >= 0 && u3 >= 0) {
            return true;
        } else {
            return false;
        }
    } else {
        if (is_pt_in_segment(x1, y1, x2, y2, x3, y3))
            return is_pt_in_segment(ptx, pty, x2, y2, x3, y3);
        else if (is_pt_in_segment(x2, y2, x1, y1, x3, y3))
            return is_pt_in_segment(ptx, pty, x1, y1, x3, y3);
        else
            return is_pt_in_segment(ptx, pty, x1, y1, x2, y2);
    }
}

char is_any_pt_in_triangle(t_pt t1, t_pt t2, t_pt t3, long num_pts, t_pt *pts)
{
    long i;
    for (i = 0; i < num_pts; i++) {
        if (is_pt_in_triangle(pts[i].x, pts[i].y, t1.x, t1.y, t2.x, t2.y, t3.x, t3.y))
            return true;
    }
    return false;
}

char is_any_pt_in_triangle_exclude_vertices(t_pt t1, t_pt t2, t_pt t3, long num_pts, t_pt *pts)
{
    long i;
    for (i = 0; i < num_pts; i++) {
        if (!pt_pt_cmp(pts[i], t1) || !pt_pt_cmp(pts[i], t2) || !pt_pt_cmp(pts[i], t3))
            continue;
        if (is_pt_in_triangle(pts[i].x, pts[i].y, t1.x, t1.y, t2.x, t2.y, t3.x, t3.y))
            return true;
    }
    return false;
}


char is_pt_in_quadrilater(double ptx, double pty, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    if (is_pt_in_triangle(ptx, pty, x1, y1, x2, y2, x3, y3) || is_pt_in_triangle(ptx, pty, x1, y1, x3, y3, x4, y4))
        return true;
    else
        return false;
}


char is_any_pt_in_quadrilater(t_pt q1, t_pt q2, t_pt q3, t_pt q4, long num_pts, t_pt *pts)
{
    long i;
    for (i = 0; i < num_pts; i++)
        if (is_pt_in_quadrilater(pts[i].x, pts[i].y, q1.x, q1.y, q2.x, q2.y, q3.x, q3.y, q4.x, q4.y))
            return true;
    return false;
}




// x,y determine the line
double pt_line_distance(double ptx, double pty, double x1, double y1, double x2, double y2) 
{
    double Dx = x2 - x1, Dy = y2 - y1;
    double length_12 = sqrt(Dx * Dx + Dy * Dy);

    if (length_12 > 0) {
        return fabs((x2 - x1) * (y1 - pty) - (x1 - ptx) * (y2 - y1))/length_12;
//        return fabs((ptx - x1) * (x2 - x1) + (pty - y1) * (y2 - y1))/length_12;

//        return fabs(Dy * ptx - Dx * pty + x1 * y2 - x2 * y1)/length_12;
    } else {
        return  sqrt((ptx - x1) * (ptx - x1) + (pty - y1) * (pty - y1));
    }
}

double pt_pt_dot(t_pt p, t_pt q)
{
    return p.x * q.x + p.y * q.y;
}

double pt_pt_cross(t_pt p, t_pt q)
{
    return p.x * q.y - p.y * q.x;
}


double pt_segment_distance(t_pt pt, t_pt v, t_pt w) 
{
    // Return minimum distance between line segment vw and point pt
    const float l2 = pt_pt_distance_squared(v, w);  // i.e. |w-v|^2 -  avoid a sqrt
    if (l2 == 0.0) return pt_pt_distance(pt, v);   // v == w case
    // Consider the line extending the segment, parameterized as v + t (w - v).
    // We find projection of point pt onto the line. 
    // It falls where t = [(pt-v) . (w-v)] / |w-v|^2
    const float t = pt_pt_dot(pt_pt_diff(pt, v), pt_pt_diff(w, v)) / l2;
    if (t < 0.0) return pt_pt_distance(pt, v);       // Beyond the 'v' end of the segment
    else if (t > 1.0) return pt_pt_distance(pt, w);  // Beyond the 'w' end of the segment
    t_pt projection = pt_pt_sum(v, pt_number_prod(pt_pt_diff(w, v), t));  // Projection falls on the segment
    return pt_pt_distance(pt, projection);
}

// distance calculated on the y vertical line passing from ptx pty
double pt_line_distance_vertical(double ptx, double pty, double x1, double y1, double x2, double y2) {
    double squared_length_12 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    if (x2 == x1) {
        return 0;
    } else if (squared_length_12 > 0) {
        double intersection_y = y1 + (ptx - x1) * (y2 - y1)/(x2 - x1);
        return intersection_y - pty;
    } else {
        return pty - y1;
    }
}

double pt_polygon_distance(t_pt pt, t_polygon *poly)
{
    long i;
    double min_dist = -1;
    long n = poly->num_vertices;
    for (i = 0; i < n; i++) {
        double this_dist = pt_segment_distance(pt, poly->vertices[i], poly->vertices[(i+1)%n]);
        if (this_dist < min_dist || min_dist < 0)
            min_dist = this_dist;
    }
    
    if (min_dist < 0)
        min_dist = 0; // should never happen, unless poly has no points. We might even want to set NaN here.
    
    return (is_pt_in_polygon(pt, poly) ? -min_dist : min_dist);
}


// utility
void fill_unicodeChar_array(unicodeChar *a, long count,...){
    long i; va_list ap;
    va_start(ap, count);
    for (i = 0; i < count; i++, a++)
        *a = (unicodeChar) va_arg(ap, long);
    va_end(ap);
}




int is_pt_in_line_shape(double point_x, double point_y, double start_x, double start_y, double end_x, double end_y, double line_width){
    double supposed_pt_y = rescale(point_x, start_x, end_x, start_y, end_y);
    double min_x = MIN(start_x, end_x);
    double max_x = MAX(start_x, end_x);
    if (point_x >= min_x && point_x <= max_x && fabs(supposed_pt_y - point_y) < line_width/2.)
        return 1;
    return 0;
}


int is_pt_in_curve_shape(double point_x, double point_y, double start_x, double start_y, double end_x, double end_y, double slope, double line_width){
    double fabs_slope = fabs(slope);
    
    if (fabs_slope < 0.1)
        return is_pt_in_line_shape(point_x, point_y, start_x, start_y, end_x, end_y, line_width);
    
    t_pt ctrl1, ctrl2, middle, ctrl3, ctrl4;
    t_pt start = build_pt(start_x, start_y);
    t_pt end = build_pt(end_x, end_y);
    paint_curve_and_get_bezier_control_points(NULL, get_grey(0), start, end, slope, line_width, &ctrl1, &ctrl2, &middle, &ctrl3, &ctrl4);

    if (fabs_slope < 0.4) 
        return (is_pt_in_line_shape(point_x, point_y, start_x, start_y, middle.x, middle.y, line_width) ||
                is_pt_in_line_shape(point_x, point_y, middle.x, middle.y, end_x, end_y, line_width));
    
    t_pt subd1 = get_single_bezier_subdivision_point(start, ctrl1, ctrl2, middle, 0.5);
    t_pt subd2 = get_single_bezier_subdivision_point(middle, ctrl3, ctrl4, end, 0.5);
    
    return (is_pt_in_line_shape(point_x, point_y, start_x, start_y, subd1.x, subd1.y, line_width) ||
            is_pt_in_line_shape(point_x, point_y, subd1.x, subd1.y, middle.x, middle.y, line_width) ||
            is_pt_in_line_shape(point_x, point_y, middle.x, middle.y, subd2.x, subd2.y, line_width) ||
            is_pt_in_line_shape(point_x, point_y, subd2.x, subd2.y, end_x, end_y, line_width));
    
}    

/*
 int is_pt_in_curve_shape(double point_x, double point_y, double start_x, double start_y, double end_x, double end_y, double slope, double line_width){
    if (fabs(slope) < 0.0001)
        return is_pt_in_line_shape(point_x, point_y, start_x, start_y, end_x, end_y, line_width);
    
    double t, t_squared, t_cubed, x_pos, y_pos, ax, bx, cx, ay, by, cy;

    double ctrl1_x, ctrl1_y, ctrl2_x, ctrl2_y;
    get_bezier_control_points(start_x, start_y, end_x, end_y, slope, &ctrl1_x, &ctrl1_y, &ctrl2_x, &ctrl2_y);

    // Our bezier curves must be in the convex hull of the rectangle (prev_bpt_x bpt_x prev_bpt_y bpt_y)
    if ((point_x >= start_x) && (point_x <= end_x) && (point_y >= MIN(start_y, end_y) - line_width) && (point_y <= MAX(start_y, end_y)) + line_width) {
        // let's try to see if it can be a bezier spline for some t    \in [0, 1]
        double fabs_delta_x = fabs(end_x - start_x);
        double fabs_delta_y = fabs(end_y - start_y);
        double diagonal_in_pixel = sqrt(fabs_delta_x * fabs_delta_x + fabs_delta_y * fabs_delta_y);
        double t_step = CONST_STEP_BEZIER_POINT_IDENTIFICATION / diagonal_in_pixel;
        t = 0.;
        // this is the best possible t corresponding to the clicked point
        // NEW (unused for now) code. TODO: make it work 
        //            double y_ratio = (fabs(bpt_y - prev_bpt_y) > 0.) ? (((float)(point_y - prev_bpt_y)) / (bpt_y - prev_bpt_y)) : 2.;
        //            double x_ratio = (fabs(bpt_x - prev_bpt_x) > 0.) ? (((float)(point_x - prev_bpt_x)) / (bpt_x - prev_bpt_x)) : 2.;
        //            t = (1. / 2.) * (y_ratio + x_ratio);
        //            post("t: %f", t);
        while (t <= 1.){
            t_squared = t * t;
            t_cubed = t_squared * t;
            cx = 3. * (ctrl1_x - start_x);
            bx = 3. * (ctrl2_x - ctrl1_x) - cx;
            ax = end_x - start_x - cx - bx;
            x_pos = ax * t_cubed + bx * t_squared + cx * t + start_x;
            //                post("x-abs: %f", fabs(x_pos - point_x));
            if (fabs(x_pos - point_x) <  line_width / 2.) {
                // the x is ok. and the y?
                cy = 3. * (ctrl1_y - start_y);
                by = 3. * (ctrl2_y - ctrl1_y) - cy;
                ay = end_y - start_y - cy - by;
                y_pos = ay * t_cubed + by * t_squared + cy * t + start_y;
                //                    post("t-abs: %f", fabs(y_pos - point_y));
                if (fabs(y_pos - point_y) < line_width / 2.) {
                    // the y is ok as well
                    return 1;
                }
            }
            t += t_step;
        }
    }
    return 0;
    
} */


// returns 1 if there's collision, 0 otherwise
char line_rectangle_collision(double line_x1, double line_y1, double line_x2, double line_y2, double rect_x1, double rect_y1, double rect_width, double rect_height, char detect_full_line_collision) {
    double a = line_y1 - line_y2;
    double b = line_x2 - line_x1;
    double c = (line_x1 - line_x2) * line_y1 + (line_y2 - line_y1) * line_x1;
    double val1, val2, val3, val4;
    
    if (!detect_full_line_collision) {
        // trimming rectangle size depending on points.
        double new_rect_x1 = MAX(MIN(line_x1, line_x2), rect_x1);
        double new_rect_x2 = MIN(MAX(line_x1, line_x2), rect_x1 + rect_width);
        rect_x1 = new_rect_x1;
        rect_width = new_rect_x2 - new_rect_x1;
    }
    
    if (rect_width < CONST_EPSILON4) {
        // testing with essentially vertical line
        double min_y_lines = MIN(line_y1, line_y2);
        double max_y_lines = MAX(line_y1, line_y2);
        if ((rect_y1 >= min_y_lines && rect_y1 <= max_y_lines) ||
            (rect_y1 + rect_height >= min_y_lines && rect_y1 + rect_height <= max_y_lines))
            return 1;
        return 0;
    }
    
    val1 = a * rect_x1 + b * rect_y1 + c;
    
    val2 = a * rect_x1 + b * (rect_y1 + rect_height) + c;
    if (val1 * val2 <= 0)
        return 1; // collision
    
    val3 = a * (rect_x1 + rect_width) + b * (rect_y1 + rect_height) + c;
    if (val3 * val2 <= 0 || val3 * val1 <= 0)
        return 1; // collision
    
    val4 = a * (rect_x1 + rect_width) + b * rect_y1 + c;
    if (val4 * val3 <= 0 || val4 * val2 <= 0 || val4 * val1 <= 0)
        return 1; // collision
    
    return 0;
}

// returns 1 if there's collision, 0 otherwise
char rectangle_rectangle_collision(double rect1_x1, double rect1_y1, double rect1_width, double rect1_height, double rect2_x1, double rect2_y1, double rect2_width, double rect2_height) {
    
    double rect1_x2 = rect1_x1 + rect1_width;
    double rect1_y2 = rect1_y1 + rect1_height;
    double rect2_x2 = rect2_x1 + rect2_width;
    double rect2_y2 = rect2_y1 + rect2_height;

    
    if (rect1_x1 > rect2_x2 || rect1_x2 < rect2_x1 || rect1_y1 > rect2_y2 || rect1_y2 < rect2_y1) 
        return 0;
    
    return 1;
}


void paint_background(t_object *x, t_jgraphics *g, t_rect *rect, t_jrgba *fill_color, double corner_roundness)
{
    t_rect bg_rect = build_rect(0, 0, rect->width, rect->height);
    paint_rect(g, &bg_rect, NULL, fill_color, 0, corner_roundness);

    // RESETTING SOURCE TO alpha = 1, because one might want to do something later,
    // and bg_rect might have a different alpha value.
    jgraphics_set_source_rgba(g, 0, 0, 0, 1);
}

void paint_border(t_object *x, t_jgraphics *g, t_rect *rect, t_jrgba *border_color, double border_size, double corner_roundness)
{
//    t_rect bg_rect = build_rect(0 + border_size /2., 0 + border_size /2., rect->width - border_size, rect->height - border_size);
    t_rect bg_rect = build_rect(0.5, 0.5, rect->width-1, rect->height-1);
    paint_rect(g, &bg_rect, border_color, NULL, border_size, corner_roundness);

    
    // RESETTING SOURCE TO alpha = 1, because one might want to do something later,
    // and bg_rect might have a different alpha value.
    jgraphics_set_source_rgba(g, 0, 0, 0, 1);
}

void paint_playhead_line(t_jgraphics* g, t_jrgba color, double playhead_x, double playhead_y1, double playhead_y2, double width, double tip_size)
{
    paint_line(g, color, playhead_x, playhead_y1, playhead_x, playhead_y2, width);
    jgraphics_move_to(g, playhead_x, playhead_y1);
    jgraphics_line_to(g, playhead_x - tip_size, playhead_y1 - tip_size);
    jgraphics_line_to(g, playhead_x + tip_size, playhead_y1 - tip_size);
    jgraphics_close_path(g);
    jgraphics_set_source_jrgba(g, &color);
    jgraphics_fill_preserve(g);
    jgraphics_stroke(g); 
}

void paint_polygon(t_jgraphics* g, t_jrgba *border_color, t_jrgba *inner_color, double linewidth, t_polygon *poly)
{
    long i;
    jgraphics_set_line_width(g, linewidth);
    for (i = 0; i < poly->num_vertices; i++) {
        t_pt this_pt = poly->vertices[i];
        if (i == 0)
            jgraphics_move_to(g, this_pt.x, this_pt.y);
        else
            jgraphics_line_to(g, this_pt.x, this_pt.y);
    }
    jgraphics_close_path(g);
    if (border_color) {
        jgraphics_set_source_jrgba(g, border_color);
        if (inner_color)
            jgraphics_stroke_preserve(g); 
        else 
            jgraphics_stroke(g); 
    }
    if (inner_color) {
        jgraphics_set_source_jrgba(g, inner_color);
        jgraphics_fill(g);
    }
}


void paint_beziercs(t_jgraphics* g, t_jrgba *border_color, t_jrgba *inner_color, double linewidth, t_beziercs *bezier)
{
    long i;
    long n = bezier->num_segments;
    jgraphics_set_line_width(g, linewidth);
    for (i = 0; i < n; i++) {
        if (i == 0)
            jgraphics_move_to(g, bezier->vertices[i].x, bezier->vertices[i].y);
//        jgraphics_line_to(g, bezier->vertices[(i+1)%n].x, bezier->vertices[(i+1)%n].y);
        jgraphics_curve_to(g, bezier->ctrl_pt_1[i].x, bezier->ctrl_pt_1[i].y,
                           bezier->ctrl_pt_2[i].x, bezier->ctrl_pt_2[i].y,
                           bezier->vertices[(i+1)%n].x, bezier->vertices[(i+1)%n].y);
    }
    jgraphics_close_path(g);
    if (border_color) {
        jgraphics_set_source_jrgba(g, border_color);
        if (inner_color)
            jgraphics_stroke_preserve(g); 
        else 
            jgraphics_stroke(g); 
    }
    if (inner_color) {
        jgraphics_set_source_jrgba(g, inner_color);
        jgraphics_fill(g);
    }
}


void paint_polygon_debug(t_jgraphics* g, t_jrgba *border_color, t_jrgba *inner_color, double linewidth, t_polygon *poly, char paint_idx)
{
    long i;
    t_jfont *jf = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, 10);
    jgraphics_set_line_width(g, linewidth);
    for (i = 0; i < poly->num_vertices; i++) {
        t_pt this_pt = poly->vertices[i];

        if (paint_idx) {
            char text[10];
            sprintf(text, "%ld", i);
            write_text_simple(g, jf, *border_color, text, this_pt.x, this_pt.y, 200, 200);
        }
        
        if (i == 0)
            jgraphics_move_to(g, this_pt.x, this_pt.y);
        else
            jgraphics_line_to(g, this_pt.x, this_pt.y);
    }
    jgraphics_close_path(g);
    if (border_color) {
        jgraphics_set_source_jrgba(g, border_color);
        if (inner_color)
            jgraphics_stroke_preserve(g); 
        else 
            jgraphics_stroke(g); 
    }
    if (inner_color) {
        jgraphics_set_source_jrgba(g, inner_color);
        jgraphics_fill(g);
    }
    jfont_destroy_debug(jf);
}




/////// ***************** POLYGON STUFF *************** ///

// if points = NULL, it only allocates the space for the vertices
t_polygon *polygon_build(long num_points, t_pt *points)
{
    t_polygon *out = (t_polygon *)bach_newptr(sizeof(t_polygon));
    out->num_vertices = num_points;
    if (num_points > 0) {
        out->vertices = (t_pt *)bach_newptr(num_points * sizeof(t_pt));
        if (points) 
            for (long i = 0; i < num_points; i++)
                out->vertices[i] = points[i];
    } else 
        out->vertices = NULL;
    return out;
}

t_polygon *polygon_clone(t_polygon *p)
{
    return polygon_build(p->num_vertices, p->vertices);
}

void polygon_free(t_polygon *p)
{
    if (p)
        bach_freeptr(p->vertices);
    bach_freeptr(p);
}


t_pt polygon_get_barycenter(t_polygon *poly)
{
    t_pt barycenter = build_pt(0, 0);
    long i;
    for (i = 0; i < poly->num_vertices; i++) 
        barycenter = pt_pt_sum(barycenter, poly->vertices[i]);
    barycenter = pt_number_prod(barycenter, 1./poly->num_vertices);
    return barycenter;
}

char polygon_get_orientation(t_polygon *poly)
{
    double sum = 0;
    long n = poly->num_vertices;
    for (long t = 0; t < poly->num_vertices; t++)
        sum += (poly->vertices[(t+1)%n].x - poly->vertices[t%n].x) * (poly->vertices[(t+1)%n].y + poly->vertices[t%n].y);
    
    if (sum > 0)
        return 1;
    else if (sum < 0)
        return -1;
    else
        return 0;
}

char triangle_get_orientation(t_pt t1, t_pt t2, t_pt t3)
{
    double sum = 0;
    sum += (t2.x - t1.x) * (t2.y + t1.y);
    sum += (t3.x - t2.x) * (t3.y + t2.y);
    sum += (t1.x - t3.x) * (t1.y + t3.y);

    if (sum > 0)
        return 1;
    else if (sum < 0)
        return -1;
    else
        return 0;
}

char is_pt_in_polygon(t_pt pt, t_polygon *poly) 
{
    double ptx = pt.x; 
    double pty = pt.y;
    
    // We handle the easy cases first
    switch (poly->num_vertices) {
        case 0:
            return false;
            break;
        case 1:
            return (fabs(poly->vertices[0].x - ptx) < CONST_EPSILON_ALIGNMENTS && fabs(poly->vertices[0].y - pty) < CONST_EPSILON_ALIGNMENTS ? true : false);
            break;
        case 2:
            return is_pt_in_segment(ptx, pty, poly->vertices[0].x, poly->vertices[0].y, poly->vertices[1].x, poly->vertices[1].y);
            break;
        case 3:
            return is_pt_in_triangle(ptx, pty, poly->vertices[0].x, poly->vertices[0].y, poly->vertices[1].x, poly->vertices[1].y, poly->vertices[2].x, poly->vertices[2].y);
            break;
        case 4:
            return is_pt_in_quadrilater(ptx, pty, poly->vertices[0].x, poly->vertices[0].y, poly->vertices[1].x, poly->vertices[1].y, poly->vertices[2].x, poly->vertices[2].y, poly->vertices[3].x, poly->vertices[3].y);
            break;
        default:
            break;
    }
    
    // otherwise:
    
    // First we check whether the point is inside the bounded box of the polygon
    double min_x = poly->vertices[0].x, max_x = poly->vertices[0].x;
    double min_y = poly->vertices[0].y, max_y = poly->vertices[0].y;
    long i;
    for (i = 1; i < poly->num_vertices; i++) {
        if (poly->vertices[i].x < min_x)
            min_x = poly->vertices[i].x;
        if (poly->vertices[i].x > max_x)
            max_x = poly->vertices[i].x;
        if (poly->vertices[i].y < min_y)
            min_y = poly->vertices[i].y;
        if (poly->vertices[i].y > max_y)
            max_y = poly->vertices[i].y;
    }
    
    // if the point is not in the bounded box of the polygon, it cannot be inside the polygon either
    if (!is_pt_in_rectangle(build_pt(ptx, pty), build_rect(min_x, min_y, max_x - min_x, max_y - min_y)))
        return false;
    
    
    // ... then we use the ray cast algorithm
    // http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
    long j, c = 0;
    for (i = 0, j = poly->num_vertices - 1; i < poly->num_vertices; j = i++) {
        if ( ((poly->vertices[i].y > pty) != (poly->vertices[j].y > pty)) &&
            (ptx < (poly->vertices[j].x - poly->vertices[i].x) * (pty - poly->vertices[i].y) / (poly->vertices[j].y - poly->vertices[i].y) + poly->vertices[i].x))
            c = !c;
    }
    return c;
}


char is_any_pt_in_polygon_exclude_vertices(t_polygon *poly, long num_pts, t_pt *pts)
{
    long i;
    for (i = 0; i < num_pts; i++) {
        char must_continue = false;
        for (long j = 0; j < poly->num_vertices; j++)
            if (!pt_pt_cmp(pts[i], poly->vertices[j])) {
                must_continue = true;
                break;
            }
        if (must_continue)
            continue;
        if (is_pt_in_polygon(pts[i], poly))
            return true;
    }
    return false;
}


///////// BEZIER CLOSED CURVE STUFF



// if points = NULL, it only allocates the space for the vertices
t_beziercs *beziercs_build(long num_segments, t_pt *vertices, t_pt *cp1, t_pt *cp2)
{
    t_beziercs *bezier = (t_beziercs *)bach_newptr(sizeof(t_beziercs));
    bezier->num_segments = num_segments;
    if (num_segments > 0) {
        bezier->vertices = (t_pt *)bach_newptr(num_segments * sizeof(t_pt));
        bezier->ctrl_pt_1 = (t_pt *)bach_newptr(num_segments * sizeof(t_pt));
        bezier->ctrl_pt_2 = (t_pt *)bach_newptr(num_segments * sizeof(t_pt));
        if (vertices) 
            for (long i = 0; i < num_segments; i++)
                bezier->vertices[i] = vertices[i];
        if (cp1) 
            for (long i = 0; i < num_segments; i++)
                bezier->ctrl_pt_1[i] = cp1[i];
        if (cp2) 
            for (long i = 0; i < num_segments; i++)
                bezier->ctrl_pt_2[i] = cp2[i];
    } else {
        bezier->vertices = NULL;
        bezier->ctrl_pt_1 = NULL;
        bezier->ctrl_pt_2 = NULL;
    }
    return bezier;
}

void beziercs_free(t_beziercs *p)
{
    if (p) {
        bach_freeptr(p->vertices);
        bach_freeptr(p->ctrl_pt_1);
        bach_freeptr(p->ctrl_pt_2);
    }
    bach_freeptr(p);
}




///// STUFF FOR GETTING CONVEX HULL

// lexicographical order
double pt_pt_cmp(t_pt pt1, t_pt pt2)
{
    if (pt1.x < pt2.x) {
        return -1;
    } else if (pt1.x == pt2.x) {
        if (pt1.y < pt2.y)
            return -1;
        else if (pt1.y == pt2.y)
            return 0;
        else
            return 1;
    } else {
        return 1;
    }
}


// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(t_pt p, t_pt q, t_pt r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

t_polygon *polygon_switch_orientation(t_polygon *poly)
{
    long n = poly->num_vertices;
    t_polygon *respoly = polygon_build(n, NULL);
    if (n > 0) {
        long i;
        respoly->vertices[0] = poly->vertices[0];
        for (i = 1; i < n; i++)
            respoly->vertices[i] = poly->vertices[n-i];
    }
    return respoly;
}

void polygon_switch_orientation_inplace(t_polygon **poly)
{
    t_polygon *res = polygon_switch_orientation(*poly);
    polygon_free(*poly);
    *poly = res;
}


// Prints convex hull of a set of n points.
t_polygon *get_convex_hull(long num_points, t_pt *points)
{
    long n = num_points;
    
    // There must be at least 3 points
    if (n < 3) {
        t_polygon *poly = polygon_build(n, points);
        return poly;
    }
    
    // Initialize Result
    int *next = (int *) bach_newptr(n * sizeof(int));
    for (int i = 0; i < n; i++)
        next[i] = -1;
    
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again
    int p = l, q;
    do
    {
        // Search for a point 'q' such that orientation(p, i, q) is
        // counterclockwise for all points 'i'
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        
        next[p] = q;  // Add q to result as a next point of p
        p = q; // Set p as q for next iteration
    } while (p != l);
    
    
    // Counting number of points in the convex hull
    long num_out_pts = 0;
    for (int i = 0; i < n; i++)
        if (next[i] != -1) 
            num_out_pts++;
        
    // Getting Result
    long i = l;
    long count = 0; 
    t_polygon *poly = polygon_build(num_out_pts, NULL);
    poly->vertices[count++] = points[l];
    
    while (next[i] != -1 && next[i] != l) {
        poly->vertices[count++] = points[next[i]];
        i = next[i];
    }
    
    // need change orientation for our purposes
    polygon_switch_orientation_inplace(&poly);
    
    bach_freeptr(next);
    return poly;
    
/*    long i = l;
    
    poly->num_vertices = 0;
    poly->vertex[poly->num_vertices++] = points[l];
    
    while (next[i] != -1 && next[i] != l) {
        poly->vertex[poly->num_vertices++] = points[next[i]];
        i = next[i];
    }*/
}


t_rect get_bounding_box_as_rect(long num_points, t_pt *points, t_pt pad)
{
    if (num_points == 0)
        return build_rect(0, 0, 0, 0);
    
    double x_min = points[0].x, y_min = points[0].y, x_max = points[0].x, y_max = points[0].y;
    for (long i = 1; i < num_points; i++) {
        if (points[i].x < x_min) x_min = points[i].x;
        if (points[i].y < y_min) y_min = points[i].y;
        if (points[i].x > x_max) x_max = points[i].x;
        if (points[i].y > y_max) y_max = points[i].y;
    }
    
    return build_rect(x_min - pad.x, y_min - pad.y, x_max - x_min + 2 * pad.x, y_max - y_min + 2 * pad.y);
}    

t_polygon *get_bounding_box(long num_points, t_pt *points, t_pt pad)
{
    if (num_points == 0)
        return polygon_build(0, NULL);
        
    double x_min = points[0].x, y_min = points[0].y, x_max = points[0].x, y_max = points[0].y;
    for (long i = 1; i < num_points; i++) {
        if (points[i].x < x_min) x_min = points[i].x;
        if (points[i].y < y_min) y_min = points[i].y;
        if (points[i].x > x_max) x_max = points[i].x;
        if (points[i].y > y_max) y_max = points[i].y;
    }
    
    t_polygon *poly = polygon_build(4, NULL);
    poly->vertices[0] = build_pt(x_min - pad.x, y_min - pad.y);
    poly->vertices[1] = build_pt(x_min - pad.x, y_max + pad.y);
    poly->vertices[2] = build_pt(x_max + pad.x, y_max + pad.y);
    poly->vertices[3] = build_pt(x_max + pad.x, y_min - pad.y);
    return poly;
}    


/*
#ifdef USE_GPC_LIBRARY

//// GPC to bach conversions
void gpcpolygon_free(gpc_polygon *p)
{
    gpc_free_polygon(p);
    bach_freeptr(p);
}


gpc_polygon *bach_polygon_to_gpcpolygon(t_polygon *poly)
{
    gpc_polygon *gpcpoly = (gpc_polygon *)bach_newptrclear(sizeof(gpc_polygon)); // "void" polygon

//    gpc_polygon *gpcpoly = bach_newptrclear(sizeof(gpcpoly));
    if (poly->num_vertices > 0) {
        gpc_vertex_list *verts = (gpc_vertex_list *)malloc(sizeof(gpc_vertex_list));
        verts->num_vertices = poly->num_vertices;
        verts->vertex = (gpc_vertex *)malloc(poly->num_vertices * sizeof(gpc_vertex));
        long i;
        for (i = 0; i < poly->num_vertices; i++) {
            verts->vertex[i].x = poly->vertices[i].x;
            verts->vertex[i].y = poly->vertices[i].y;
        }
        gpc_add_contour(gpcpoly, verts, 0);
    }
    return gpcpoly;
}

t_polygon *gpcpolygon_to_bach_polygon(gpc_polygon *gpcpoly)
{
    long i, found = -1;
    for (i = 0; i < gpcpoly->num_contours; i++) {
        if (!gpcpoly->hole[i]) {
            found = i;
            break;
        }
    }
    
    if (found < 0)
        return polygon_build(0, NULL);
    
    t_polygon *poly = polygon_build(gpcpoly->contour[found].num_vertices, NULL);
    for (i = 0; i < gpcpoly->contour[found].num_vertices; i++) {
        poly->vertices[i].x = gpcpoly->contour[found].vertex[i].x;
        poly->vertices[i].y = gpcpoly->contour[found].vertex[i].y;
    }
    return poly;
}

t_polygon *polygon_op(gpc_op op, t_polygon *poly1, t_polygon *poly2, long *num_contours)
{
    gpc_polygon *gpcpoly1 = bach_polygon_to_gpcpolygon(poly1);
    gpc_polygon *gpcpoly2 = bach_polygon_to_gpcpolygon(poly2);
    gpc_polygon *gpcresult = (gpc_polygon *)bach_newptr(sizeof(gpc_polygon));
    
    gpc_polygon_clip(op, gpcpoly1, gpcpoly2, gpcresult);

    if (num_contours) *num_contours = gpcresult->num_contours;
    
    t_polygon *result = gpcpolygon_to_bach_polygon(gpcresult);
    
    gpcpolygon_free(gpcpoly1);
    gpcpolygon_free(gpcpoly2);
    gpcpolygon_free(gpcresult);
    
    return result;
}

#endif
*/

void pts_polygon_dist(t_polygon *poly, long num_pts, t_pt *pts, double *dist)
{
    long i;
    for (i = 0; i < num_pts; i++)
        dist[i] = pt_polygon_distance(pts[i], poly);
}


void pts_segment_dist(t_pt segment_start, t_pt segment_end, long num_pts, t_pt *pts, double *dist)
{
    long i;
    for (i = 0; i < num_pts; i++)
        dist[i] = pt_segment_distance(pts[i], segment_start, segment_end);
}

void are_pts_in_polygon(t_polygon *poly, long num_pts, t_pt *pts, char *res)
{
    long i;
    for (i = 0; i < num_pts; i++)
        res[i] = is_pt_in_polygon(pts[i], poly);
}

char is_any_pt_in_polygon(t_polygon *poly, long num_pts, t_pt *pts)
{
    long i;
    for (i = 0; i < num_pts; i++)
        if (is_pt_in_polygon(pts[i], poly))
            return true;
    return false;
}

char is_any_pt_not_in_polygon(t_polygon *poly, long num_pts, t_pt *pts)
{
    long i;
    for (i = 0; i < num_pts; i++)
        if (!is_pt_in_polygon(pts[i], poly))
            return true;
    return false;
}


void are_pts_in_polygon_up_to_thresh(t_polygon *poly, long num_pts, t_pt *pts, char *res, double threshold)
{
    long i;
    for (i = 0; i < num_pts; i++) 
        res[i] = (pt_polygon_distance(pts[i], poly) < threshold);
}


char are_char_arrays_equal(long len, char *ar1, char *ar2)
{
    long i;
    for (i = 0; i < len; i++)
        if (ar1[i] != ar2[i])
            return false;
    return true;
}

t_pt pts_mean(long num_pts, t_pt *pts)
{
    t_pt total = build_pt(0, 0);
    long i;
    if (num_pts > 0) {
        for (i = 0; i < num_pts; i++)
            total = pt_pt_sum(total, pts[i]);
        total = pt_number_prod(total, 1./num_pts);
    }
    return total;
}

void pts_linear_regression_x(long num_pts, t_pt *pts, double *m, double *q)
{
    t_pt mean = pts_mean(num_pts, pts);

    // Finding y = mx + q
    double num = 0, den = 0;
    long i;
    for (i = 1; i < num_pts; i++)
        num += (pts[i].x - mean.x) * (pts[i].y - mean.y);
    for (i = 1; i < num_pts; i++)
        den += (pts[i].x - mean.x) * (pts[i].x - mean.x);
    *m = num/den;
    *q = mean.y - (*m) * mean.x;
}

void pts_linear_regression_y(long num_pts, t_pt *pts, double *n, double *r)
{
    t_pt mean = pts_mean(num_pts, pts);
    
    // Finding x = nx + r
    double num = 0, den = 0;
    long i;
    for (i = 1; i < num_pts; i++)
        num += (pts[i].x - mean.x) * (pts[i].y - mean.y);
    for (i = 1; i < num_pts; i++)
        den += (pts[i].y - mean.y) * (pts[i].y - mean.y);
    *n = num/den;
    *r = mean.x - (*n) * mean.y;
}

t_pt pts_find_leftmost_pt(long num_pts, t_pt *pts)
{
    t_pt res = build_pt(0, 0);
    if (num_pts > 0) {
        double min_x = pts[0].x;
        long idx = 0;
        for (long i = 0; i < num_pts; i++) {
            if (pts[i].x < min_x) {
                min_x = pts[i].x;
                idx = i;
            }
        }
        res = pts[idx];
    }
    return res;
}

t_pt pts_find_rightmost_pt(long num_pts, t_pt *pts)
{
    t_pt res = build_pt(0, 0);
    if (num_pts > 0) {
        double max_x = pts[0].x;
        long idx = 0;
        for (long i = 0; i < num_pts; i++) {
            if (pts[i].x > max_x) {
                max_x = pts[i].x;
                idx = i;
            }
        }
        res = pts[idx];
    }
    return res;
}

t_pt pts_find_topmost_pt(long num_pts, t_pt *pts)
{
    t_pt res = build_pt(0, 0);
    if (num_pts > 0) {
        double min_y = pts[0].y;
        long idx = 0;
        for (long i = 0; i < num_pts; i++) {
            if (pts[i].y < min_y) {
                min_y = pts[i].y;
                idx = i;
            }
        }
        res = pts[idx];
    }
    return res;
}

t_pt pts_find_bottommost_pt(long num_pts, t_pt *pts)
{
    t_pt res = build_pt(0, 0);
    if (num_pts > 0) {
        double max_y = pts[0].y;
        long idx = 0;
        for (long i = 0; i < num_pts; i++) {
            if (pts[i].y > max_y) {
                max_y = pts[i].y;
                idx = i;
            }
        }
        res = pts[idx];
    }
    return res;
}




void pts_approximate_with_segment(long num_pts, t_pt *pts, t_pt *res_start, t_pt *res_end)
{
    if (num_pts == 0)
        return;
    
    double m, q, n, r;
    pts_linear_regression_x(num_pts, pts, &m, &q);
    pts_linear_regression_y(num_pts, pts, &n, &r);
    
    double error_mq = 0, error_nr = 0;
    long i;
    for (i = 0; i < num_pts; i++) {
        error_mq += fabs(m * pts[i].x + q - pts[i].y);
        error_nr += fabs(n * pts[i].y + r - pts[i].x);
    }
    
    if (error_mq < error_nr) {
        t_pt left = pts_find_leftmost_pt(num_pts, pts);
        t_pt right = pts_find_rightmost_pt(num_pts, pts);
        res_start->x = left.x;
        res_end->x = right.x;
        res_start->y = m * left.x + q;
        res_end->y = m * right.x + q;
    } else {
        t_pt top = pts_find_topmost_pt(num_pts, pts);
        t_pt bottom = pts_find_bottommost_pt(num_pts, pts);
        res_start->y = top.y;
        res_end->y = bottom.y;
        res_start->x = n * top.y + r;
        res_end->x = n * bottom.y + r;
    }
}

double pts_get_max_distance_from_line(long num_pts, t_pt *pts, t_pt line_start, t_pt line_end)
{
    long i, max_dist = 0;
    for (i = 0; i < num_pts; i++) {
        double this_dist = pt_line_distance(pts[i].x, pts[i].y, line_start.x, line_start.y, line_end.x, line_end.y);
        if (this_dist > max_dist)
            max_dist = this_dist;
    }
    return max_dist;
}


t_polygon *polygon_offset_simple(t_polygon *poly, double amount)
{
    long n = poly->num_vertices;
    t_pt c = polygon_get_barycenter(poly);

    // find expansion factor
    double maxnorm = 0;
    double factor = 1;
    if (n >= 2) {
        for (long i = 0; i < n; i++) {
            t_pt p = poly->vertices[i];
            double this_norm = pt_pt_distance(p, c);
            if (this_norm > maxnorm)
                maxnorm = this_norm;
        }
        factor = (maxnorm + amount)/maxnorm;
    }
    
    long i; 
    t_polygon *poly_extr = polygon_build(poly->num_vertices, poly->vertices); // cloning polygon
    for (i = 0; i < n; i++) 
        poly_extr->vertices[i] = pt_pt_sum(c, pt_number_prod(pt_pt_diff(poly->vertices[i], c), factor));    
    return poly_extr;
}


double offset_amount_to_expansion_factor(t_polygon *poly, double offset_amount) {
    // find expansion factor
    double maxnorm = 0;
    double factor = 1;
    long n = poly->num_vertices;
    t_pt c = polygon_get_barycenter(poly);
    if (n >= 2) {
        for (long i = 0; i < n; i++) {
            t_pt p = poly->vertices[i];
            double this_norm = pt_pt_distance(p, c);
            if (this_norm > maxnorm)
                maxnorm = this_norm;
        }
        factor = (maxnorm + offset_amount)/maxnorm;
    }
    return factor;
}

t_polygon *polygon_shrink_smart(t_polygon *poly, double amount, long wanted_pts_size, t_pt *wanted_pts)
{
    char *wanted_inpoly_before = (char *)bach_newptr(wanted_pts_size * sizeof(char));
    char *wanted_inpoly_after = (char *)bach_newptr(wanted_pts_size * sizeof(char));
    t_pt c = polygon_get_barycenter(poly);
    t_polygon *poly_shr = polygon_build(0, NULL);
    long n = poly->num_vertices;
    
    double amount_used = amount;
    while (amount_used > 0.00001) { 
        polygon_free(poly_shr);
        double factor = offset_amount_to_expansion_factor(poly, -amount_used);
        are_pts_in_polygon(poly, wanted_pts_size, wanted_pts, wanted_inpoly_before);

        long i; 
        poly_shr = polygon_build(poly->num_vertices, poly->vertices); // cloning polygon
        for (i = 0; i < n; i++) 
            poly_shr->vertices[i] = pt_pt_sum(c, pt_number_prod(pt_pt_diff(poly->vertices[i], c), factor));
        
        are_pts_in_polygon(poly_shr, wanted_pts_size, wanted_pts, wanted_inpoly_after);
        
        if (are_char_arrays_equal(wanted_pts_size, wanted_inpoly_before, wanted_inpoly_after)) 
            break;
            
        amount_used *= 0.8;
    }
    
    bach_freeptr(wanted_inpoly_before);
    bach_freeptr(wanted_inpoly_after);
    return poly_shr;
}



char are_all_chars_zero(long num_chars, char *ar)
{
    long i;
    for (i = 0; i < num_chars; i++)
        if (ar[i] != 0)
            return false;
    return true;
}

char are_all_chars_one(long num_chars, char *ar)
{
    long i;
    for (i = 0; i < num_chars; i++)
        if (ar[i] != 1)
            return false;
    return true;
}


long pts_juxtapose(long size1, t_pt *pts1, long size2, t_pt *pts2, t_pt **result)
{
    if (size1 < 0 || size2 < 0)
        return 0;

    if (size1 == 0 && size2 == 0)
        return 0;

    long i;
    *result = (t_pt *) bach_newptr((size1 + size2) * sizeof(t_pt));
    
    for (i = 0; i < size1; i++)
        (*result)[i] = pts1[i];
    
    for (; i< size1 + size2; i++)
        (*result)[i] = pts2[i - size1];
    
    return size1+size2;
}

t_polygon *polygon_loop(t_polygon *poly, long times)
{
    long i;
    t_polygon *looped_poly = polygon_build(times * poly->num_vertices, NULL);
    for (i = 0; i < times * poly->num_vertices; i++)
        looped_poly->vertices[i] = poly->vertices[i % poly->num_vertices];
    return looped_poly;
}


double polygon_get_upper_bound_for_diameter(t_polygon *poly)
{
    if (poly->num_vertices == 0)
        return 0;
    
    double xmax = poly->vertices[0].x, xmin = poly->vertices[0].x, ymax = poly->vertices[0].y, ymin = poly->vertices[0].y;
    long i;
    for (i = 1; i < poly->num_vertices; i++) {
        if (poly->vertices[i].x < xmin) xmin = poly->vertices[i].x;
        if (poly->vertices[i].y < ymin) ymin = poly->vertices[i].y;
        if (poly->vertices[i].x > xmax) xmax = poly->vertices[i].x;
        if (poly->vertices[i].y > ymax) ymax = poly->vertices[i].y;
    }
    
    double height = ymax - ymin;
    double width = xmax - xmin;
    return sqrt(height * height + width * width);    
}


// Returns 1 if the lines intersect, otherwise 0. In addition, if the lines 
// intersect the intersection point may be stored in the floats i_x and i_y.
char get_segment_intersection(double p0_x, double p0_y, double p1_x, double p1_y,
                           double p2_x, double p2_y, double p3_x, double p3_y, double *i_x, double *i_y)
{
    double s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;
    
    double s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);
    
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        if (i_x != NULL)
            *i_x = p0_x + (t * s1_x);
        if (i_y != NULL)
            *i_y = p0_y + (t * s1_y);
        return 1;
    }
    
    return 0; // No collision
}

// Returns 1 if the lines intersect, otherwise 0. In addition, if the lines
// intersect the intersection point may be stored in the floats i_x and i_y.
char get_line_intersection(double p0_x, double p0_y, double p1_x, double p1_y,
                              double p2_x, double p2_y, double p3_x, double p3_y, double *i_x, double *i_y, double parallelism_thresh)
{
    double s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;
    
    double s, t;
    double den = (-s2_x * s1_y + s1_x * s2_y);
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / den;
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / den;

    if (fabs(den) <= parallelism_thresh)
        return 0;
    else
    {
        // Collision detected
        if (i_x != NULL)
            *i_x = p0_x + (t * s1_x);
        if (i_y != NULL)
            *i_y = p0_y + (t * s1_y);
        return 1;
    }
}


char segment_segment_intersection(t_pt line1_start, t_pt line1_end, t_pt line2_start, t_pt line2_end, t_pt *res)
{
    return get_segment_intersection(line1_start.x, line1_start.y, line1_end.x, line1_end.y,
                                 line2_start.x, line2_start.y, line2_end.x, line2_end.y, &(res->x), &(res->y));
}


char line_line_intersection(t_pt line1_start, t_pt line1_end, t_pt line2_start, t_pt line2_end, t_pt *res, double parallelism_thresh)
{
    return get_line_intersection(line1_start.x, line1_start.y, line1_end.x, line1_end.y,
                                 line2_start.x, line2_start.y, line2_end.x, line2_end.y, &(res->x), &(res->y), parallelism_thresh);
}




// find all intersections between polygon and line
long polygon_segment_intersection(t_polygon *poly, t_pt line_start, t_pt line_end, t_pt **res, long **idx)
{
    long n = poly->num_vertices;
    if (n <= 2) {
        *res = NULL;
        return 0;
    }
    
    long i, count = 0;
    *res = (t_pt *)bach_newptr(n * sizeof(t_pt));
    *idx = (long *)bach_newptr(n * sizeof(long));
    
    for (i = 0; i < n; i++) {
        if (segment_segment_intersection(line_start, line_end, poly->vertices[i], poly->vertices[(i+1)%n], &((*res)[count])))
            (*idx)[count++] = i;
    }
    
    *res = (t_pt *)bach_resizeptr(*res, count * sizeof(t_pt));
    *idx = (long *)bach_resizeptr(*idx, count * sizeof(long));
    return count;
}


// find the intersection between polygon and line being nearest to the point c
char polygon_line_nearest_intersection(t_polygon *poly, t_pt line_start, t_pt line_end, t_pt c, t_pt *res, long *idx)
{
    long *allidx = NULL; 
    t_pt *allres = NULL;
    long num_intersections = polygon_segment_intersection(poly, line_start, line_end, &allres, &allidx);
    
    if (num_intersections > 0) {
        // finding nearest to c
        long i, min_idx = -1;
        double min_dist = -1; 
        for (i = 0; i < num_intersections; i++) {
            double this_dist = pt_pt_distance_squared(c, allres[i]);
            if (min_dist < 0 || this_dist < min_dist) {
                min_idx = i;
                min_dist = this_dist;
            }
        }
        
        if (min_idx >= 0) {
            *idx = allidx[min_idx];
            *res = allres[min_idx];
            
            bach_freeptr(allidx);
            bach_freeptr(allres);
            return 1;
        }
    }
    
    *idx = -1;
    bach_freeptr(allidx);
    bach_freeptr(allres);
    return 0;
}

int polygon_combine_cmpfunc (const void * a, const void * b)
{
    t_bach_casting_ray *axx = (t_bach_casting_ray *)a;
    t_bach_casting_ray *bxx = (t_bach_casting_ray *)b;
    return ( axx->dist - bxx->dist );
}

// core function, combining polys so that polyh is brought out of the poly (if type == 0) or inside the poly (type == 1), polyh being the "hole" in first case
// and an external polygon to be incorporated in the polygon in the second case
// g is just for debug
t_polygon *polygon_combine(t_polygon *poly, t_polygon *polyh, char type, long num_pts_in, t_pt *pts_in, long num_pts_out, t_pt *pts_out, t_jgraphics *g)
{
    t_jrgba grey1 = change_alpha(get_grey(0.2), 0.3);
//    t_jrgba grey2 = change_alpha(get_grey(0.8), 0.3);
//    t_jrgba red = build_jrgba(1, 0, 0, 0.5);
//    t_jrgba blue = build_jrgba(0, 0, 1, 0.5);
    long i, j;
    t_pt *pts;
    long num_pts = pts_juxtapose(num_pts_in, pts_in, num_pts_out, pts_out, &pts);
    char *inpoly = (char *)bach_newptr(num_pts * sizeof(char));
    t_polygon *poly_looped = polygon_loop(poly, 2);
    t_polygon *polyh_looped = polygon_loop(polyh, 2);
    long n = poly->num_vertices, m = polyh->num_vertices;
    t_polygon *result = polygon_build(0, NULL);
    
    const double min_angle_thresh = 0.01; // could be a parameter
    const double MAX_NUM_DIVS = 512;
    
    t_pt c = polygon_get_barycenter(polyh);
    double ubound_diam = polygon_get_upper_bound_for_diameter(poly);
    long num_div = 4;
    char good = false;
    
//    if (g) paint_polygon_debug(g, &red, NULL, 1, poly, false);
//    if (g) paint_polygon_debug(g, &blue, NULL, 1, polyh, false);

    
    while (!good && num_div < MAX_NUM_DIVS) {

        // casting <num_div> rays starting from barycenter of the hole and going outside the container 
        double alpha_step = 2 * PI / num_div;
        t_bach_casting_ray *xx = (t_bach_casting_ray *)bach_newptrclear(num_div * sizeof(t_bach_casting_ray));
        for (i = 0; i < num_div; i++) {
            xx[i].alpha = 2 * PI * i/num_div;
            xx[i].p.x = c.x + ubound_diam * cos(xx[i].alpha);
            xx[i].p.y = c.y + ubound_diam * sin(xx[i].alpha);
            xx[i].c = c;
        }        
        
        // Find first intersection of casting rays with <poly> and with <polyh>
        
        
        for (i = 0; i < num_div; i++) {
            polygon_line_nearest_intersection(poly, c, xx[i].p, c, &(xx[i].q), &(xx[i].idx_q));
            polygon_line_nearest_intersection(polyh, c, xx[i].p, c, &(xx[i].r), &(xx[i].idx_r));
            xx[i].dist = pt_pt_distance_squared(xx[i].q, xx[i].r);
        }
        
        // find minimum distance
        qsort(xx, num_div, sizeof(t_bach_casting_ray), polygon_combine_cmpfunc);
        
        // Now rays are ordered with respect to their intersection
        for (i = 0; i < num_div; i++) {
            // trying to extend the ray cw and ccw, and see if it doensn't span a region containing "bad" points
            xx[i].q_cw = xx[i].q_ccw = xx[i].q;
            xx[i].r_cw = xx[i].r_ccw = xx[i].r;

            if (g)    paint_line(g, grey1, c.x, c.y, xx[i].p.x, xx[i].p.y, 1);

            // BEWARE: this algorithm takes into account the Y axis as pointing upwards, hence if Y points downwards
            // (as in computer graphics) ccw and cw are swapped. Nothing bad happens, just be careful with orientation stuff.
            
            // extending ccw
            double delta_alpha_ccw = alpha_step / 2.;
            while (delta_alpha_ccw > min_angle_thresh) {
                xx[i].alpha_ccw = xx[i].alpha + delta_alpha_ccw;
                xx[i].p_ccw = pt_pt_sum(c, pt_number_prod(build_pt(cos(xx[i].alpha_ccw), sin(xx[i].alpha_ccw)), ubound_diam));
                polygon_line_nearest_intersection(poly, c, xx[i].p_ccw, c, &(xx[i].q_ccw), &(xx[i].idx_q_ccw));
                polygon_line_nearest_intersection(polyh, c, xx[i].p_ccw, c, &(xx[i].r_ccw), &(xx[i].idx_r_ccw));
                long idx_q_i = xx[i].idx_q, idx_r_i = xx[i].idx_r;
//                long idx_q_ccw_orig = xx[i].idx_q_ccw, idx_r_ccw_orig = xx[i].idx_r_ccw;
                
                if (idx_q_i < xx[i].idx_q_ccw)
                    idx_q_i += n;
                
                if (idx_r_i < xx[i].idx_r_ccw)
                    idx_r_i += m;
                
                // reassemble portion of extrusion, and see if there are "bad" point inside it
                t_polygon *assembled = polygon_build(2 * n + 2 * m + 10, NULL);
                long count = 0;
                assembled->vertices[count++] = xx[i].r;
                for (j = idx_r_i; j >= xx[i].idx_r_ccw + 1; j--) 
                    assembled->vertices[count++] = polyh_looped->vertices[j];
                assembled->vertices[count++] = xx[i].r_ccw;
                assembled->vertices[count++] = xx[i].q_ccw;
                for (j = xx[i].idx_q_ccw + 1; j <= idx_q_i; j++) 
                    assembled->vertices[count++] = poly_looped->vertices[j];
                assembled->vertices[count++] = xx[i].q;
                assembled->num_vertices = count;
                assembled->vertices = (t_pt *)bach_resizeptr(assembled->vertices, count * sizeof(t_pt));
                
/*                if (g) {
                    paint_line(g, grey1, c.x, c.y, xx[i].p_ccw.x, xx[i].p_ccw.y, 1);
                    paint_polygon_debug(g, &grey1, NULL, 3, &assembled);
                }
*/
                are_pts_in_polygon(assembled, num_pts, pts, inpoly);
                polygon_free(assembled);
                
                
                if (are_all_chars_zero(num_pts, inpoly))
                    break; // we are done: we have successfully extended ccw
                
                delta_alpha_ccw /= 2.;
            }
            
            
            // extending cw
            double delta_alpha_cw = alpha_step / 2.;
            while (delta_alpha_cw > min_angle_thresh) {
                xx[i].alpha_cw = xx[i].alpha - delta_alpha_cw;
                xx[i].p_cw = pt_pt_sum(c, pt_number_prod(build_pt(cos(xx[i].alpha_cw), sin(xx[i].alpha_cw)), ubound_diam));
                polygon_line_nearest_intersection(poly, c, xx[i].p_cw, c, &(xx[i].q_cw), &(xx[i].idx_q_cw));
                polygon_line_nearest_intersection(polyh, c, xx[i].p_cw, c, &(xx[i].r_cw), &(xx[i].idx_r_cw));
                long idx_q_i = xx[i].idx_q, idx_r_i = xx[i].idx_r;
                long idx_q_i_cw = xx[i].idx_q_cw, idx_r_i_cw = xx[i].idx_r_cw;
                
                if (idx_q_i_cw < idx_q_i)
                    idx_q_i_cw += n;
                
                if (idx_r_i_cw < idx_r_i)
                    idx_r_i_cw += m;
                
                // reassemble portion of extrusion, and see if there are "bad" point inside it
                t_polygon *assembled = polygon_build(2 * n + 2 * m + 10, NULL);
                long count = 0;
                assembled->vertices[count++] = xx[i].r;
                assembled->vertices[count++] = xx[i].q;
                for (j = idx_q_i+1; j <= idx_q_i_cw; j++) 
                    assembled->vertices[count++] = poly_looped->vertices[j];
                assembled->vertices[count++] = xx[i].q_cw;
                assembled->vertices[count++] = xx[i].r_cw;
                for (j = idx_r_i_cw; j >= idx_r_i + 1; j--) 
                    assembled->vertices[count++] = polyh_looped->vertices[j];
                assembled->num_vertices = count;
                assembled->vertices = (t_pt *)bach_resizeptr(assembled->vertices, count * sizeof(t_pt));

//                if (g) paint_polygon(g, &grey1, NULL, 3, &assembled);
                
                are_pts_in_polygon(assembled, num_pts, pts, inpoly);
                polygon_free(assembled);
                
                if (are_all_chars_zero(num_pts, inpoly))
                    break; // we are done: we have successfully extended ccw
                
                delta_alpha_cw /= 2.;
            }
            
            if (delta_alpha_ccw < min_angle_thresh && delta_alpha_cw < min_angle_thresh)
                continue;
            
            
            // If we are here, everything is fine, we have found all we needed
            good = true;
            
            long idx_q_ccw = xx[i].idx_q_ccw, idx_q_cw = xx[i].idx_q_cw;
            long idx_r_ccw = xx[i].idx_r_ccw, idx_r_cw = xx[i].idx_r_cw;

            if (type == 0) {
                if (idx_q_ccw <= idx_q_cw)
                    idx_q_ccw += n;
                if (idx_r_ccw <= idx_r_cw)
                    idx_r_ccw += m;
                
                polygon_free(result);
                result = polygon_build(2 * n + 2 * m + 10, NULL);
                long count = 0;
                result->vertices[count++] = xx[i].q_cw;
                for (j = idx_q_cw+1; j <= idx_q_ccw; j++) 
                    result->vertices[count++] = poly_looped->vertices[j];
                result->vertices[count++] = xx[i].q_ccw;
                result->vertices[count++] = xx[i].r_ccw;
                for (j = idx_r_ccw; j >= idx_r_cw + 1; j--) 
                    result->vertices[count++] = polyh_looped->vertices[j];
                result->vertices[count++] = xx[i].r_cw;
                result->num_vertices = count;
                result->vertices = (t_pt *)bach_resizeptr(result->vertices, count * sizeof(t_pt));
            } else {
                if (idx_q_cw <= idx_q_ccw)
                    idx_q_cw += n;
                if (idx_r_ccw <= idx_r_cw)
                    idx_r_ccw += m;
                
                polygon_free(result);
                result = polygon_build(2 * n + 2 * m + 10, NULL);
                long count = 0;
                result->vertices[count++] = xx[i].q_ccw;
                for (j = idx_q_ccw+1; j <= idx_q_cw; j++) 
                    result->vertices[count++] = poly_looped->vertices[j];
                result->vertices[count++] = xx[i].q_cw;
                result->vertices[count++] = xx[i].r_cw;
                for (j = idx_r_cw+1; j <= idx_r_ccw + 1; j++) 
                    result->vertices[count++] = polyh_looped->vertices[j];
                result->vertices[count++] = xx[i].r_ccw;
                result->num_vertices = count;
                result->vertices = (t_pt *)bach_resizeptr(result->vertices, count * sizeof(t_pt));
            }
            
//            if (g) paint_polygon_debug(g, &grey1, NULL, 3, result);
            
            break;
            
        }
        
        bach_freeptr(xx);
        
        if (!good) {
            num_div *= 2;
//            min_angle_thresh /= 2.;
        }
    }
    
    
    
    bach_freeptr(inpoly);
    bach_freeptr(pts);
    polygon_free(poly_looped);
    polygon_free(polyh_looped);    
    
    return result;
}


// poly is modified
void polygon_combine_inplace(t_polygon **poly, t_polygon *polyh, char type, long num_pts_in, t_pt *pts_in, long num_pts_out, t_pt *pts_out, t_jgraphics *g)
{
    t_polygon *res = polygon_combine(*poly, polyh, type, num_pts_in, pts_in, num_pts_out, pts_out, g);
    polygon_free(*poly);
    *poly = res;
}



long extract_pts_having_given_corresponding_value(long num_pts, t_pt *pts, char *ar, char requested_val, t_pt **pts_sub)
{
    *pts_sub = (t_pt *)bach_newptr(num_pts * sizeof(t_pt));
    long i, j = 0;
    for (i = 0; i < num_pts; i++)
        if (ar[i] == requested_val)
            (*pts_sub)[j++] = pts[i];
    *pts_sub = (t_pt *)bach_resizeptr(*pts_sub, j * sizeof(t_pt));
    return j;
}


// only works for roll at zoomx = zoomy = 1., and at the beginning of the score
void paint_points_debug(long num_pts, t_pt *pts, t_jrgba *color, t_jgraphics *g)
{
    long i;
    for (i = 0; i < num_pts; i++) {
//        double x = (pts[i].x + CONST_ROLL_UX_LEFT_START + 7); // for roll
        double x =  pts[i].x * CONST_X_SCALING_SCORE + 7 + CONST_SCORE_UX_LEFT_START;

        
        paint_circle(g, *color, *color, x, pts[i].y, 2, 1);
    }
}


void polygon_prune_vertex_inplace(t_polygon *poly, long prune_idx)
{
    long n = poly->num_vertices;
    long j;
    for (j = prune_idx; j < n-1; j++)
        poly->vertices[j] = poly->vertices[j+1];
    poly->num_vertices--;
}

void polygon_insert_vertex_inplace(t_polygon *poly, long index, t_pt vert)
{
    poly->num_vertices++;
    poly->vertices = (t_pt *)bach_resizeptr(poly->vertices, poly->num_vertices*sizeof(t_pt));
    for (long i = poly->num_vertices-1; i > index; i--) {
        poly->vertices[i] = poly->vertices[i-1];
    }
    poly->vertices[index] = vert;
}


t_polygon *polygon_prune_vertex(t_polygon *poly, long prune_idx)
{
    long n = poly->num_vertices;
    long j;
    t_polygon *pruned = polygon_build(n-1, poly->vertices); // cloning
    for (j = 0; j < n-1; j++) {
        if (j >= prune_idx)
            pruned->vertices[j] = poly->vertices[j+1];
        else
            pruned->vertices[j] = poly->vertices[j];
    }
    return pruned;
}


double get_triangle_area(t_polygon *poly)
{
    double a = pt_pt_distance(poly->vertices[0], poly->vertices[1]);
    double b = pt_pt_distance(poly->vertices[1], poly->vertices[2]);
    double c = pt_pt_distance(poly->vertices[0], poly->vertices[2]);
    double p = (a+b+c)/2;
    
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void remove_vertices_preserving_inclusion_of_pts(t_polygon *poly, long num_pts, t_pt *pts, double dist_threshold, t_jgraphics *g)
{
    long i, j;
    long n = poly->num_vertices;
    long num_test_pts = (num_pts + (n - 3));
    t_pt *test_pts = (t_pt *)bach_newptr(num_test_pts * sizeof(t_pt));
    char *test_pts_inpoly = (char *)bach_newptr(num_test_pts * sizeof(char));
    double *pts_dist = (double *)bach_newptr(num_pts * sizeof(double));
    double *pts_dist2 = (double *)bach_newptr(num_pts * sizeof(double));
    double *pts_distpruned = (double *)bach_newptr(num_pts * sizeof(double));
    for (i = 0; i < num_pts; i++) test_pts[i] = pts[i];
    
    t_polygon* tri = polygon_build(3, NULL);

    for (i = 1; i <= n; i++) {
        tri->vertices[0] = poly->vertices[i-1];
        tri->vertices[1] = poly->vertices[i % n];
        tri->vertices[2] = poly->vertices[(i+1) % n];
//        double tri_area = get_triangle_area(tri); 

/*        if (g) {
            t_jrgba red = build_jrgba(1, 0, 0, 1);
            paint_polygon_debug(g, &red, NULL, 1, tri, false);
        }
*/        
        long count = num_pts;
        for (j = 0; j < n && count < num_test_pts; j++) 
            if ((j % n) != (i % n) && (j % n) != ((i - 1) % n) && (j % n) != ((i + 1) % n))    
                test_pts[count++] = poly->vertices[j];
        
//        polygon_offset_smart_inplace(&tri, 5, 0, NULL, 0, NULL);
        are_pts_in_polygon(tri, num_test_pts, test_pts, test_pts_inpoly);
        
        
//        are_pts_in_polygon_up_to_thresh(tri, num_test_pts, test_pts, test_pts_inpoly, dist_threshold);
        
        if (are_all_chars_zero(num_test_pts, test_pts_inpoly)) {
            // there are no points inside the triangle. We test and see if we can prune it.
            t_polygon *pruned = polygon_prune_vertex(poly, i%n);
            
            pts_polygon_dist(poly, num_pts, pts, pts_dist);
            pts_polygon_dist(pruned, num_pts, pts, pts_distpruned);
             
/*            pts_segment_dist(poly->vertices[i-1], poly->vertices[i % n], num_pts, pts, pts_dist);
            pts_segment_dist(poly->vertices[i % n], poly->vertices[(i + 1) % n], num_pts, pts, pts_dist2);
            pts_segment_dist(poly->vertices[i-1], poly->vertices[(i + 1) % n], num_pts, pts, pts_distpruned);
*/            
            char can_prune = true;
            for (j = 0; j < num_pts; j++) // are the new distances less than the existing ones ?
// WAS:
                if ((fabs(pts_distpruned[j]) < dist_threshold) && (fabs(pts_distpruned[j]) < fabs(pts_dist[j]) - 0.001)) {
//                if (fabs(pts_distpruned[j]) < dist_threshold) {
//                    if (fabs(pts_distpruned[j]) < MIN(fabs(pts_dist[j]), fabs(pts_dist2[j]) - 0.001)) {
                        can_prune = false; 
                        break;
//                    }
                }
            
            polygon_free(pruned);
            
            if (can_prune) {
                // actually prune
                long i0 = (i%n);
                for (j = i0 + 1; j < n; j++)
                    poly->vertices[j-1] = poly->vertices[j];
                poly->num_vertices -- ;
                n--;
                num_test_pts--;
                
                i = 1; // start over.
//                i--; // so it will i++ later
            }
        }
    }
    
    polygon_free(tri);
    
    bach_freeptr(test_pts);
    bach_freeptr(test_pts_inpoly);
    bach_freeptr(pts_dist);
    bach_freeptr(pts_dist2);
    bach_freeptr(pts_distpruned);
    
}

t_pt pt_pt_linear_comb(t_pt pt1, t_pt pt2, double t)
{
    return pt_pt_sum(pt_number_prod(pt1, 1-t), pt_number_prod(pt2, t));
}


void smooth_preserving_inclusion_of_pts(t_polygon *poly, long num_pts, t_pt *pts, double dist_threshold, t_jgraphics *g)
{
    long i, j;
    long n = poly->num_vertices;
    long num_test_pts = (num_pts + (n - 3));
    t_pt *test_pts = (t_pt *)bach_newptr(num_test_pts * sizeof(t_pt));
    char *test_pts_inpoly = (char *)bach_newptr(num_test_pts * sizeof(char));
    for (i = 0; i < num_pts; i++) test_pts[i] = pts[i];
    
    t_polygon* quadri = polygon_build(4, NULL);
    for (i = 1; i <= n; i++) {
        double t = 0.5;
        while (t > 0.4) {
            t_pt candidate = pt_pt_linear_comb(poly->vertices[i % n], pt_pt_linear_comb(poly->vertices[i-1], poly->vertices[(i+1) % n], 0.5), t);
            quadri->vertices[0] = poly->vertices[i-1];
            quadri->vertices[1] = poly->vertices[i % n];
            quadri->vertices[2] = poly->vertices[(i+1) % n];
            quadri->vertices[3] = candidate;
            
            if (g) {
                t_jrgba red = build_jrgba(1, 0, 0, 1);
                paint_polygon_debug(g, &red, NULL, 1, quadri, false);
            }
            
            long count = num_pts;
            for (j = 0; j < n && count < num_test_pts; j++) 
                if ((j % n) != i && (j % n) != i - 1 && (j % n) != i + 1)    
                    test_pts[count++] = poly->vertices[j];
            
//            are_pts_in_polygon(quadri, num_test_pts, test_pts, test_pts_inpoly);
            are_pts_in_polygon_up_to_thresh(quadri, num_test_pts, test_pts, test_pts_inpoly, dist_threshold);
            
            if (are_all_chars_zero(num_test_pts, test_pts_inpoly)) {
                // there are no points inside the quadrilater. We smooth it.
                poly->vertices[i % n] = candidate;
                break;
            }
            t /= 2.;
        }
    }
    
    polygon_free(quadri);
    
    bach_freeptr(test_pts);
    bach_freeptr(test_pts_inpoly);
    
}




t_polygon *pts_to_triangle(t_pt pt1, t_pt pt2, t_pt pt3)
{
    t_pt pts[3];
    pts[0] = pt1; pts[1] = pt2; pts[2] = pt3;
    return polygon_build(3, pts);
}

t_beziercs *polygon_to_bezier_closed_spline(t_polygon *poly)
{
    t_beziercs *bezier = beziercs_build(poly->num_vertices, NULL, NULL, NULL); 
    long i;
    long n = poly->num_vertices;
    for (i = 0; i < n; i++) {
        bezier->vertices[i] = poly->vertices[i];
        bezier->ctrl_pt_1[i] = pt_pt_linear_comb(poly->vertices[i], poly->vertices[(i+1)%n], 0.333);
        bezier->ctrl_pt_2[i] = pt_pt_linear_comb(poly->vertices[i], poly->vertices[(i+1)%n], 0.666);
    }
    return bezier;
}

// t is a factor between 0 and 1 affecting the positioning of the control points with respect
// to line segments (0. = not derivable, 0.5 = very smooth, 1 = more pointy)
// factor_factor is a decay factor for the factor
t_beziercs *refine_poly_to_bezier_preserving_inclusion_of_pts(t_polygon *poly, long num_pts, t_pt *pts, 
                                                              double starting_factor, double factor_factor, 
                                                              double t, t_jgraphics *g)
{
    long n = poly->num_vertices;
    t_beziercs *bezier = beziercs_build(n * 3 + 1, NULL, NULL, NULL); // upped bound
    char *pts_intri = (char *)bach_newptrclear(MAX(1, num_pts)  * sizeof(char)) ;
    long i, count = 0;
    t_pt last_pt = build_pt(0, 0);
    
    for (i = 0; i < n && count < n * 3 - 1; i++) {
        t_pt p1 = poly->vertices[i], p2 = poly->vertices[i]; // doesn't matter how we initialize them
        
        // analyzing segment between knot i, i+1 and i+2;
        double factor = starting_factor;
        while (factor > 0.001) { // threshold
            p1 = pt_pt_linear_comb(poly->vertices[i], poly->vertices[(i+1) % n], 1 - factor);
            p2 = pt_pt_linear_comb(poly->vertices[(i+1) % n], poly->vertices[(i+2) % n], factor);
            t_polygon *tri = pts_to_triangle(p1, poly->vertices[(i+1) % n], p2);

            are_pts_in_polygon(tri, num_pts, pts, pts_intri);
            
            polygon_free(tri);
            
            if (are_all_chars_zero(num_pts, pts_intri))
                break; // no pt hits in the triangle. We can refine the polygon.
            
            factor *= factor_factor; // decrease factor
        }
        
        if (i >= 1) {
            bezier->vertices[count] = last_pt;
            bezier->ctrl_pt_1[count] = pt_pt_linear_comb(last_pt, p1, 0.333);
            bezier->ctrl_pt_2[count] = pt_pt_linear_comb(last_pt, p1, 0.666);
            count++;
        }
        
        t_pt v = poly->vertices[(i+1) % n];
        bezier->vertices[count] = p1;
        bezier->ctrl_pt_1[count] = pt_pt_linear_comb(v, p1, t);
        bezier->ctrl_pt_2[count] = pt_pt_linear_comb(v, p2, t);
        
        last_pt = p2;
        count++;
    }

    if (n >= 3) {
        bezier->vertices[count] = last_pt;
        bezier->ctrl_pt_1[count] = pt_pt_linear_comb(last_pt, bezier->vertices[0], 0.333);
        bezier->ctrl_pt_2[count] = pt_pt_linear_comb(last_pt, bezier->vertices[0], 0.666);
        count++;
    }
    
    if (g) {
        t_jrgba red = build_jrgba(1, 0, 0, 1);
        t_jrgba violet = build_jrgba(1, 0, 1, 1);
        t_jrgba green = build_jrgba(0, 1, 0, 1);
        paint_points_debug(count, bezier->vertices, &red, g);
        paint_points_debug(count, bezier->ctrl_pt_1, &violet, g);
        paint_points_debug(count, bezier->ctrl_pt_2, &green, g);
    }

    bezier->num_segments = count;
    bezier->ctrl_pt_1 = (t_pt *)bach_resizeptr(bezier->ctrl_pt_1, count * sizeof(t_pt));
    bezier->ctrl_pt_2 = (t_pt *)bach_resizeptr(bezier->ctrl_pt_2, count * sizeof(t_pt));
    bezier->vertices = (t_pt *)bach_resizeptr(bezier->vertices, count * sizeof(t_pt));
    bach_freeptr(pts_intri);
    
    return bezier;
}


double get_min_segment_distance(t_pt seg_start, t_pt seg_end, long num_pts_out, t_pt *pts_out, long *min_idx)
{
    double min_dist = DBL_MAX;
    for (long j = 0; j < num_pts_out; j++) {
        double this_dist = pt_segment_distance(pts_out[j], seg_start, seg_end);
        if (this_dist < min_dist) {
            min_dist = this_dist;
            if (min_idx) *min_idx = j;
        }
    }
    return min_dist;
}

t_pt get_perp_vect_ccw(t_pt vec, double size)
{
    t_pt perp;
    perp.x = vec.y;
    perp.y = -vec.x;
    perp = pt_number_prod(perp, size / pt_norm(vec));
    return perp;
}

t_pt get_perp_vect_cw(t_pt vec, double size)
{
    t_pt perp;
    perp.x = -vec.y;
    perp.y = vec.x;
    perp = pt_number_prod(perp, size / pt_norm(vec));
    return perp;
}

t_pt get_norm_vector(t_pt vec, double norm)
{
    return pt_number_prod(vec, norm / pt_norm(vec));
}

long polygon_get_extruded_point_rough(t_polygon *p, long h, long i, long j, double amount, t_pt *pt, t_pt *hh_ext1, t_pt *ii_ext1, t_pt *ii_ext2, t_pt *jj_ext2)
{
    t_pt perp1 = get_perp_vect_ccw(pt_pt_diff(p->vertices[i], p->vertices[h]), amount);
    t_pt h_ext1 = pt_pt_sum(p->vertices[h], perp1);
    t_pt i_ext1 = pt_pt_sum(p->vertices[i], perp1);
    
    t_pt perp2 = get_perp_vect_ccw(pt_pt_diff(p->vertices[j], p->vertices[i]), amount);
    t_pt i_ext2 = pt_pt_sum(p->vertices[i], perp2);
    t_pt j_ext2 = pt_pt_sum(p->vertices[j], perp2);
    
    if (hh_ext1) *hh_ext1 = h_ext1;
    if (ii_ext1) *ii_ext1 = i_ext1;
    if (ii_ext2) *ii_ext2 = i_ext2;
    if (jj_ext2) *jj_ext2 = j_ext2;
    
    return line_line_intersection(h_ext1, i_ext1, i_ext2, j_ext2, pt, 0.01);
}

t_polygon *polygon_extrude(t_polygon *p, double ideal_amount, double safety_factor, long num_pts_out, t_pt *pts_out)
{
    if (p->num_vertices == 1) {
        // special case
        t_pt new_pts[4];
        double amount = ideal_amount;
        long count;
        while (true) {
            for (long i = 0; i < 4; i++)
                new_pts[i] = p->vertices[0];
            new_pts[0].x -= amount; new_pts[0].y -= amount;
            new_pts[1].x += amount; new_pts[1].y -= amount;
            new_pts[2].x += amount; new_pts[2].y += amount;
            new_pts[3].x -= amount; new_pts[3].y += amount;
            count = 4;
            
            if (is_any_pt_in_quadrilater(new_pts[0], new_pts[1], new_pts[2], new_pts[3], num_pts_out, pts_out)) {
                amount *= 0.6;
            } else {
                break;
            }
            
            if (amount < 0.001) {
                //                dev_post("Cannot extrude point");
                new_pts[0] = p->vertices[0];
                count = 0;
                break;
            }
        }
        t_polygon *q = polygon_build(count, new_pts);
        return q;
    }
    
    long num_pts = p->num_vertices;
    long count = 0;
    t_pt *newpts = (t_pt *) bach_newptr(2 * num_pts * sizeof(t_pt));
    for (long i = 0; i < num_pts; i++) {
        // substituting point i
        long h = positive_mod(i-1, num_pts);
        long j = positive_mod(i+1, num_pts);
        
        double amount_factor = safety_factor; // if this is 3 we aim at thrice, to check for out_pts to stay out of that; then we'll extrude by a third of this
        double amount = ideal_amount * amount_factor;
        
        while (true) {
            t_pt h_ext1, i_ext1, i_ext2, j_ext2, new_pt;
            
            if (polygon_get_extruded_point_rough(p, h, i, j, amount, &new_pt, &h_ext1, &i_ext1, &i_ext2, &j_ext2)) {
                if (pt_pt_distance(new_pt, p->vertices[i]) > 2 * amount &&
                    pt_pt_cross(pt_pt_diff(i_ext2, new_pt), pt_pt_diff(new_pt, i_ext1)) < 0) {
                    // intersection goes too far: adding two points instead of one
                    t_pt new_pt1 = pt_pt_sum(i_ext1, get_norm_vector(pt_pt_diff(new_pt, i_ext1), amount));
                    t_pt new_pt2 = pt_pt_sum(i_ext2, get_norm_vector(pt_pt_diff(new_pt, i_ext2), amount));
                    if (is_any_pt_in_quadrilater(h_ext1, i_ext1, p->vertices[i], p->vertices[h], num_pts_out, pts_out) ||
                        is_any_pt_in_quadrilater(i_ext1, new_pt1, new_pt2, i_ext2, num_pts_out, pts_out) ||
                        is_any_pt_in_triangle(i_ext1, i_ext2, p->vertices[i], num_pts_out, pts_out) ||
                        is_any_pt_in_quadrilater(i_ext2, j_ext2, p->vertices[j], p->vertices[i], num_pts_out, pts_out)) {
                        // trying to remove point
                        amount = amount * 0.6;
                    } else {
                        newpts[count++] = pt_pt_sum(i_ext1, get_norm_vector(pt_pt_diff(new_pt, i_ext1), amount / amount_factor));
                        newpts[count++] = pt_pt_sum(i_ext2, get_norm_vector(pt_pt_diff(new_pt, i_ext2), amount / amount_factor));
                        break; // all right
                    }
                }
                if (is_any_pt_in_quadrilater(h_ext1, i_ext1, p->vertices[i], p->vertices[h], num_pts_out, pts_out) ||
                    is_any_pt_in_quadrilater(i_ext1, new_pt, i_ext2, p->vertices[i], num_pts_out, pts_out) ||
                    is_any_pt_in_quadrilater(i_ext2, j_ext2, p->vertices[j], p->vertices[i], num_pts_out, pts_out)) {
                    amount = amount * 0.6;
                } else {
                    polygon_get_extruded_point_rough(p, h, i, j, amount/amount_factor, &new_pt, NULL, NULL, NULL, NULL);
                    newpts[count++] = new_pt;
                    break; // all right
                }
            } else {
                if (pt_pt_dot(pt_pt_diff(j_ext2, i_ext2), pt_pt_diff(i_ext1, h_ext1)) <= 0) {
                    // two segments were parallel and face opposite direction (most likely overlapping)
                    t_pt v = get_norm_vector(pt_pt_diff(p->vertices[i], p->vertices[h]), amount);
                    t_pt new_pt1 = pt_pt_sum(i_ext1, v);
                    t_pt new_pt2 = pt_pt_sum(i_ext2, v);
                    if (is_any_pt_in_quadrilater(h_ext1, i_ext1, p->vertices[i], p->vertices[h], num_pts_out, pts_out) ||
                        is_any_pt_in_quadrilater(i_ext1, new_pt1, new_pt2, i_ext2, num_pts_out, pts_out) ||
                        is_any_pt_in_quadrilater(i_ext2, j_ext2, p->vertices[j], p->vertices[i], num_pts_out, pts_out)) {
                        amount = amount * 0.6;
                    } else {
                        newpts[count++] = pt_pt_sum(i_ext1, get_norm_vector(pt_pt_diff(p->vertices[i], p->vertices[h]), amount/amount_factor));
                        newpts[count++] = pt_pt_sum(i_ext2, get_norm_vector(pt_pt_diff(p->vertices[i], p->vertices[h]), amount/amount_factor));
                        break; // all right
                    }
                } else {
                    if (is_any_pt_in_quadrilater(h_ext1, i_ext1, p->vertices[i], p->vertices[h], num_pts_out, pts_out) ||
                        is_any_pt_in_quadrilater(i_ext2, j_ext2, p->vertices[j], p->vertices[i], num_pts_out, pts_out)) {
                        amount = amount * 0.6;
                    } else {
//                        new_pt = i_ext2;
                        polygon_get_extruded_point_rough(p, h, i, j, amount/amount_factor, NULL, NULL, NULL, &new_pt, NULL);
                        newpts[count++] = new_pt;
                        break; // all right
                    }
                }
            }
            
            if (amount < 0.001) {
//                dev_post("Cannot extrude segment");
                newpts[count++] = p->vertices[i];
                break;
            }
        }
    }
    
    t_polygon *q = polygon_build(count, newpts);
    bach_freeptr(newpts);
    
    return q;
}

void paint_polygon_debug_new(t_polygon *p, t_jgraphics *g, long iteration, char paint_labels)
{
    t_polygon *q = polygon_clone(p);
    t_jrgba grey = get_grey(0.5);
    t_jfont *jf = jfont_create_debug("Times", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, 7);
    for (long i = 0; i < q->num_vertices; i++) {
        q->vertices[i].x = 7 + (CONST_ROLL_UX_LEFT_START) + (p->vertices[i].x);
        
        if (paint_labels) {
            t_pt t = pt_pt_sum(q->vertices[i], get_perp_vect_ccw(pt_pt_diff(q->vertices[i], q->vertices[(i+1) % q->num_vertices]), 10));
            char text[200];
            sprintf(text, "%ld", i);
            paint_circle_filled(g, grey, q->vertices[i].x, q->vertices[i].y, 1);
            write_text_simple(g, jf, grey, text, t.x, t.y, 200, 200);
        }
    }

    
    t_jrgba c = long_to_color(iteration);
    paint_polygon(g, &c, NULL, 1, q);
    polygon_free(q);
    jfont_destroy_debug(jf);
}



t_beziercs *get_venn_enclosure(long num_pts_in, t_pt *pts_in, long num_pts_out, t_pt *pts_out, t_jgraphics *g)
{
    const double EXTRUDE_AMOUNT = 10;
    
    // Refining polygon to bezier curve
    t_pt *pts = NULL; // Building array of juxtaposed points [pts_in pts_out]
    long num_pts = pts_juxtapose(num_pts_in, pts_in, num_pts_out, pts_out, &pts);

    // 1) find the base path across points
    const double safe_dist = 2 * EXTRUDE_AMOUNT;
    long *path_ids = (long *)bach_newptr(num_pts_in*sizeof(long));
    long *done = (long*) bach_newptr(num_pts_in * sizeof(long));

    for (long i = 0; i < num_pts_in; i++)
        done[i] = false;
    
    path_ids[0] = 0;
    done[0] = true;
    for (long i = 1; i < num_pts_in; i++) {
        long best_j = -1;
        double best_weight = DBL_MAX;
        for (long j = 0; j < num_pts_in; j++) {
            if (done[j])
                continue;
            double dist = pt_pt_distance(pts_in[i-1], pts_in[j]);
            double min_dist = get_min_segment_distance(pts_in[i-1], pts_in[j], num_pts_out, pts_out, NULL);
            double this_weight = dist / MIN(1, min_dist / safe_dist);
            if (best_j < 0 || this_weight < best_weight) {
                best_weight = this_weight;
                best_j = j;
            }
        }
        
        if (best_j < 0)
            break;
        
        path_ids[i] = best_j;
        done[best_j] = true;
    }
    
    t_pt *pts_in_modif = (t_pt *)bach_newptr(2 * num_pts_in * sizeof(t_pt));
    long count = 0, num_pts_in_modif = 0;
    
    // 2) verify if points are essentially collinear with some pts_out, in which case add a "fake" point
    for (long i = 0; i < num_pts_in-1 && count < 2 * num_pts_in; i++) {
        long j = positive_mod(i+1, num_pts_in);
        long minidx = -1;
        t_pt pt_i = pts_in[path_ids[i]];
        t_pt pt_j = pts_in[path_ids[j]];
        double d = get_min_segment_distance(pt_i, pt_j, num_pts_out, pts_out, &minidx);
        double thresh = EXTRUDE_AMOUNT;
        char has_inters = false;
        char ratio_is_ok = true;

        pts_in_modif[count++] = pt_i;
        
        if (minidx >= 0) {
            t_pt inters;
            has_inters = line_line_intersection(pt_i, pt_j, pts_out[minidx], pt_pt_sum(pts_out[minidx], get_perp_vect_cw(pt_pt_diff(pt_j, pt_i), EXTRUDE_AMOUNT)), &inters, 0);
            if (has_inters) {
                double dist_ratio = (pt_pt_distance(inters, pt_i) / (pt_pt_distance(pt_j, pt_i)));
                if (dist_ratio < 0.05 || dist_ratio > 0.95)
                    ratio_is_ok = false;
            }
        }
        
        while (d < thresh && has_inters && ratio_is_ok) {
            t_pt addedpt = pt_pt_sum(pts_out[minidx], get_perp_vect_cw(pt_pt_diff(pt_j, pt_i), thresh));
            d = MIN(get_min_segment_distance(pt_i, addedpt, num_pts_out, pts_out, NULL), get_min_segment_distance(addedpt, pt_j, num_pts_out, pts_out, NULL));
            if (d < thresh) {
                pts_in_modif[count++] = addedpt;
                break;
            } else {
                thresh *= 0.6;
            }
        }
    }
    pts_in_modif[count++] = pts_in[path_ids[num_pts_in-1]];
    num_pts_in_modif = count;

    
    // try to resolve crossings, if any
    t_pt inters;
    t_pt *pts_in_modif2 = (t_pt *)bach_newptr(num_pts_in_modif*sizeof(t_pt));
    t_pt *temp_pts = (t_pt *)bach_newptr(num_pts_in_modif*sizeof(t_pt));
    long MAX_RESOLVECROSSING_TRIES = 10;
    long crossing_resolved = 0;
    for (long i = 0; i < num_pts_in_modif; i++)
        pts_in_modif2[i] = pts_in_modif[i];
    while (crossing_resolved < MAX_RESOLVECROSSING_TRIES) {
        char changed = false, break_twice = false;
        for (long i = 0; i + 3 < num_pts_in_modif; i++) {
            t_pt i1 = pts_in_modif2[i];
            t_pt i2 = pts_in_modif2[i+1];
            for (long j = i+2; j + 1 < num_pts_in_modif; j++) {
                t_pt j1 = pts_in_modif2[j];
                t_pt j2 = pts_in_modif2[j+1];
                
                if (segment_segment_intersection(i1, i2, j1, j2, &inters)) {
                    // resolve crossing
                    changed = true;
                    for (long t = 0; t < num_pts_in_modif; t++)
                        temp_pts[t] = pts_in_modif2[t];
                    for (long t = i+1; t <= i + (j-i); t++)
                        pts_in_modif2[t] = temp_pts[j + (i+1 - t)];
                    break_twice = true;
                    break;
                }
            }
            if (break_twice)
                break;
        }
        if (!changed)
            break;
        else
            crossing_resolved++;
    }
    
    
    // 3) build initial degenerate polygon from the found path
    t_pt *new_pts;
    long num_new_pts = (2*num_pts_in_modif - 2);
    if (num_pts_in_modif == 1) {
        new_pts = (t_pt *)bach_newptr(1*sizeof(t_pt));
        new_pts[0] = pts_in_modif2[0];
        num_new_pts = 1;
    } else {
        new_pts = (t_pt *)bach_newptr((2*num_pts_in_modif - 2)*sizeof(t_pt));
        num_new_pts = (2*num_pts_in_modif - 2);
        for (long i = 0; i < num_pts_in_modif; i++)
            new_pts[i] = pts_in_modif2[i];
        for (long i = num_pts_in_modif; i < num_new_pts; i++)
            new_pts[i] = pts_in_modif2[2*num_pts_in_modif - i - 2];
    }
    
    t_polygon *p = polygon_build(num_new_pts, new_pts);
    
//    if (g) paint_polygon_debug_new(p, g, 1, false);

    
    // 4) try to prune points to extend the path to a true polygon
    long num_pruned = 0;
    t_pt dummy;
    t_pt *temp_pts2 = (t_pt *)bach_newptr(p->num_vertices *sizeof(t_pt));
    while (p->num_vertices >= 3) {
        char pruned = false;
        long n = p->num_vertices;
        for (long i = 0; i < n; i++) {
            long h = positive_mod(i-1, n);
            
            /*
             // ALGORITHM FOR PRUNING JUST TRIANGLES
             // check if the pruned segment would intersect with the other ones
             char would_intersect = false;
             for (long t = 0; t < p->num_vertices; t++) {
             if (t == h || t == i)
             continue;
             if (segment_segment_intersection(p->vertices[h], p->vertices[j], p->vertices[t], p->vertices[t+1], &dummy)) {
             would_intersect = true;
             break;
             }
             }
             // should we prune i?
             if (!would_intersect &&
             !is_any_pt_in_triangle_exclude_vertices(p->vertices[h], p->vertices[i], p->vertices[j], num_pts, pts) &&
             pt_pt_cross(pt_pt_diff(p->vertices[i], p->vertices[h]), pt_pt_diff(p->vertices[j], p->vertices[i])) < 0) {
             pruned = true;
             num_pruned++;
             polygon_prune_vertex_inplace(p, i);
             if (g) paint_polygon_debug_new(p, g, num_pruned+1, false);
             */
            
            for (long k = i + n - 4; k >= i; k--) {
                // trying to prune from i to k included
                long prpn = k - i + 3; // pruned poly size
                
                // check if the pruned segment would intersect with the other ones
                char would_new_segment_intersect_existing_segments = false;
                for (long t = k+2; t%n != h && (t+1)% n != h; t++) {
                    if (!pt_pt_cmp(p->vertices[t%n], p->vertices[h]) || !pt_pt_cmp(p->vertices[t%n], p->vertices[(k+1)%n]) ||
                        !pt_pt_cmp(p->vertices[(t+1)%n], p->vertices[h]) || !pt_pt_cmp(p->vertices[(t+1)%n], p->vertices[(k+1)%n]))
                        continue;
                    if (segment_segment_intersection(p->vertices[h], p->vertices[(k+1)%n], p->vertices[t%n], p->vertices[(t+1)%n], &dummy)) {
                        would_new_segment_intersect_existing_segments = true;
                        break;
                    }
                }
                
                for (long t = i-1; t <= k+1; t++)
                    temp_pts2[t-(i-1)] = p->vertices[positive_mod(t, n)];
                t_polygon *pr_p = polygon_build(prpn, temp_pts2); // pruned polygon
                
                // would the pruned polygon intersect itself?
                char would_pruned_polygon_intersect_itself = false;
                for (long t = 0; t < prpn - 1; t++) {
                    char break_twice = false;
                    for (long u = t+2; u < prpn; u++) {
                        if ((u+1) % prpn == t % prpn)
                            continue;
                        if (segment_segment_intersection(pr_p->vertices[t%prpn], pr_p->vertices[(t+1)%prpn], pr_p->vertices[u%prpn], pr_p->vertices[(u+1)%prpn], &dummy)) {
                            would_pruned_polygon_intersect_itself = true;
                            break_twice = true;
                            break;
                        }
                    }
                    if (break_twice)
                        break;
                }
                
                // is the pruned polygon degenerate?
                char is_pruned_polygon_degenerate = false;
                for (long t = 0; t < prpn; t++) {
                    char break_twice = false;
                    for (long u = t+1; u < prpn; u++) {
                        if (!pt_pt_cmp(pr_p->vertices[t], pr_p->vertices[u])) {
                            is_pruned_polygon_degenerate = true;
                            break_twice = true;
                            break;
                        }
                    }
                    if (break_twice)
                        break;
                }
                
                // would the pruned polygon have the right orientation?
                char is_pruned_polygon_ccw = (polygon_get_orientation(pr_p) > 0);
                
/*                // checking if is any of the pruned vertices NOT in polygon?
                // SHOULD NOT BE NEEDED!
  */
                
                // should we prune i?
                if (!would_new_segment_intersect_existing_segments &&
                    !would_pruned_polygon_intersect_itself &&
                    !is_pruned_polygon_degenerate &&
                    is_pruned_polygon_ccw &&
                    !is_any_pt_in_polygon_exclude_vertices(pr_p, num_pts, pts)) {
                    pruned = true;
                    num_pruned++;
                    for (long t = i; t <= k; t++)
                        polygon_prune_vertex_inplace(p, i);
//                    if (g) paint_polygon_debug_new(p, g, num_pruned+1, false);
                }
                
                polygon_free(pr_p);
            }
        }
        if (!pruned)
            break;
    }

    if (g) paint_polygon_debug_new(p, g, 1, true);

    // 5) make a knee of the segments where out points lie too near them
    double thresh_knee = EXTRUDE_AMOUNT;
    if (p->num_vertices >= 3) {
        for (long i = 0; i < p->num_vertices; i++) {
            // check if edge i, i+1 lies near an pts_out
            long n = p->num_vertices;
            long minidx;
            t_pt pi = p->vertices[i%n];
            t_pt pj = p->vertices[(i+1)%n];
            double mindist = get_min_segment_distance(pi, pj, num_pts_out, pts_out, &minidx);
            
            if (mindist < thresh_knee) {
                t_pt inters;
                t_pt perp = get_perp_vect_cw(pt_pt_diff(pi, pj), EXTRUDE_AMOUNT);
                char has_inters = line_line_intersection(pi, pj, pts_out[minidx], pt_pt_sum(pts_out[minidx], perp), &inters, 0);
                if (has_inters) {
                    double dist_ratio = (pt_pt_distance(inters, pi) / pt_pt_distance(pj, pi));
                    if (dist_ratio >= 0.05 && dist_ratio <= 0.95) {
                        double amount = EXTRUDE_AMOUNT;
                        while (true) {
                            t_pt base_pt = pt_pt_sum(pi, pt_number_prod(pt_pt_diff(pj, pi), dist_ratio));
                            t_pt new_pt = pt_pt_sum(base_pt, get_perp_vect_ccw(pt_pt_diff(pi, pj), amount));
                            
                            char good = true;
                            for (long i = 0; i < num_pts; i++)
                                if (!pt_pt_cmp(new_pt, pts[i])) {
                                    good = false;
                                    break;
                                }

                            if (good) {
                                for (long t = 0; t < p->num_vertices; t++) {
                                    if (!pt_pt_cmp(pi, pts[(t+1)%n]) && !pt_pt_cmp(pj, pts[t%n])) {
                                        good = false;
                                        break;
                                    }
                                }
                            }
                            
                            if (good) {
                                t_pt dummy;
                                for (long t = 0; t < p->num_vertices; t++) {
                                    if (t == i || (t+1)%n == i || t == (i+1)%n || (t+1)%n == (i+1)%n)
                                        continue;
                                    if (segment_segment_intersection(pi, new_pt, p->vertices[t], p->vertices[(t+1)%n], &dummy)) {
                                        good = false;
                                        break;
                                    }
                                }
                            }
                            
                            if (good) {
                                t_pt dummy;
                                for (long t = 0; t < p->num_vertices; t++) {
                                    if (t == i)
                                        continue;
                                    if (segment_segment_intersection(base_pt, new_pt, p->vertices[t], p->vertices[(t+1)%n], &dummy)) {
                                        good = false;
                                        break;
                                    }
                                }
                            }

                            if (good) {
                                for (long t = 0; t < p->num_vertices; t++) {
                                    if (t == i)
                                        continue;
                                    if (pt_segment_distance(new_pt, p->vertices[t], p->vertices[(t+1)%n]) < amount) {
                                        good = false;
                                        break;
                                    }
                                }
                            }
                            
                            if (good && is_any_pt_in_triangle_exclude_vertices(pi, new_pt, pj, num_pts, pts))
                                good = false;
                            
                            if (good && MIN(get_min_segment_distance(pi, new_pt, num_pts_out, pts_out, &minidx), get_min_segment_distance(new_pt, pj, num_pts_out, pts_out, &minidx)) <= mindist)
                                good = false;
                            
                            if (good) {
                                polygon_insert_vertex_inplace(p, i+1, new_pt);
                                i++;
                                break;
                            } else {
                                amount = amount * 0.6;
                            }
                            
                            if (amount < 1) {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

//    if (g) paint_polygon_debug_new(p, g, 10, true);

    // 6) extrude polygon
    t_polygon *q = polygon_extrude(p, EXTRUDE_AMOUNT, 2., num_pts_out, pts_out);

//    if (g) paint_polygon_debug_new(q, g, 11, true);

    // 7) convert to bezier closed spline
    t_beziercs *beziercs = refine_poly_to_bezier_preserving_inclusion_of_pts(q, num_pts, pts, 0.5, 0.8, 0.5, NULL);
    
    bach_freeptr(temp_pts2);
    bach_freeptr(pts_in_modif2);
    bach_freeptr(temp_pts);
    bach_freeptr(pts_in_modif);
    bach_freeptr(path_ids);
    bach_freeptr(new_pts);
    bach_freeptr(pts);
	bach_freeptr(done);
    polygon_free(p);
    polygon_free(q);

    return beziercs;
}
