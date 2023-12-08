/*
 *  jiwheel.c
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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
    @file
    jiwheel.c
    
    @name 
    bach.jiwheel
    
    @realname 
    bach.jiwheel

    @type
    object
    
    @module
    bach

    @author
    bachproject
    
    @digest 
    Just intonation clock diagram
    
    @description
    The purpose of <o>bach.jiwheel</o> is to act as a simple clock diagram displaying
    just intonation pitches.
 
    @category
    bach, bach objects, bach just intonation, bach interface, U/I
    
    @keywords
    jiwheel, diagram, clock, just intonation, ratio, Helmholtz-Ellis, wheel, rotate,

    @palette
    YES
    
    @palette category
    bach, bach objects, bach just intonation, bach interface

    @seealso
    bach.primeform, bach.pcsetinfo, bach.mod+, bach.mod-, bach.modtimes, bach.compl
    
    @owner
    Daniele Ghisi
*/


#include "math/llll_settheory.h"
#include "graphics/bach_graphics.h"
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_globalsymbol.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "ext_critical.h"
#include "ext_strings.h"
#include "ext_boxstyle.h"

#define PITCHWHEEL_MAX_ZOOM 10000000
#define PITCHWHEEL_LIMIT_RADIUS_FOR_LINE 30000
#define PITCHWHEEL_MAX_ACCIDENTALS 10
#define PITCHWHEEL_LEGEND_INSET 10

#define MAX_ALLOWED_LIMITS 200
#define MAX_ALLOWED_PRIMES 200

const long commalimits[] = {5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
t_rational *commas = NULL;
long numcommas = 0;
//const t_rational commas[] = {genrat(81, 80), genrat(64, 63), genrat(32, 33), genrat(27, 26), genrat(2187, 2176), genrat(512, 513), genrat(729,736), genrat(256,261), genrat(32,31), genrat(36,37), genrat(81, 82), genrat(128,129), genrat(729,752)};
//const long numcommas = 13;

typedef struct _wheelpitch
{
    long        index;
    char        type; // 1 if pitch is a JI ratio, 0 if it's a ET //< CURRENTLY UNUSED: it's always JI ratio
    t_rational  ratio;
    t_rational  ratio_without_octaves;
    double      cents;
    long        limit;
    long        pythagorean_index; // position in the circle of fifths
    long        maxexp; // maximum exponent
    double      angle;
    double      importance;
    
    long        pyth_diatonic_step; // 0 = C, 1 = D, 2 = E, 3 = F, 4 = G, 5 = A, 6 = B
    long        pyth_accidentals_as_long; // 0 = natural, 1 = sharp, 2 = doublesharp, etc., -1 = flat, etc.
    unicodeChar pyth_accidentals[PITCHWHEEL_MAX_ACCIDENTALS+1];
    long        num_pyth_accidentals; // length of the unicode string above
    unicodeChar accidentals[PITCHWHEEL_MAX_ACCIDENTALS+2]; // the +2 is needed to account for an overflow character if needed
    long        num_accidentals; // length of the unicode string above
    unicodeChar accidentals_with_spaces[2*(PITCHWHEEL_MAX_ACCIDENTALS)+2]; // same, but with spaces interleaved between accidentals
    long        num_accidentals_with_spaces;
    bool        purely_pythagorean;
    bool        accidentals_overflow; // can't represent ratio with accidentals
    
    // volatile
    bool        shown;
    double      curr_normalized_importance;
    bool        coincides_with_intwheel;
} t_wheelpitch;

enum {
    BACH_PITCHWHEEL_MODE_MAXTERM = 0,
    BACH_PITCHWHEEL_MODE_JILIMITS = 1,
};

enum {
    BACH_PITCHWHEEL_PITCHTYPE_ET = 0,
    BACH_PITCHWHEEL_PITCHTYPE_JI = 1,
};

enum {
    BACH_PITCHWHEEL_DISPLAY_RATIO = 0,
    BACH_PITCHWHEEL_DISPLAY_ACCIDENTALS = 1,
};

enum {
    BACH_PITCHWHEEL_TEXT_UPRIGHT = 0,
    BACH_PITCHWHEEL_TEXT_ANGULAR = 1,
    BACH_PITCHWHEEL_TEXT_RADIAL = 2,
};

enum {
    BACH_PITCHWHEEL_COLORMODE_PLAIN = 0,
    BACH_PITCHWHEEL_COLORMODE_LIMIT = 1,
    BACH_PITCHWHEEL_COLORMODE_MAXEXP = 2,
    BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANCHROMATICNOTE = 3,
    BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANDIATONICNOTE = 4,
};

typedef struct _jiwheel // [bach.jiwheel] structure
{
    t_llllobj_jbox            j_box; // root object

    t_jrgba                    j_textcolor;
    t_jrgba                    j_bgcolor;
    t_jrgba                    j_bordercolor;
    t_jrgba                    j_linecolor;
    
    double                  rotation_angle; // for main wheel (pitch wheel)
    double                  rotation_angle_intwheel;
    t_rational              rotation_ratio_intwheel;
    double                  zoom;
    double                  zoom_angle;
    long                    formaloctave; // by default it's 2, use 3 for bohlen pierce

    char                    mode; // 0 = up to a maxterm; 1 = JI limits combination;
    t_atom                  maxterm; // fixed integer for a maxterm (in mode = 0), "auto" symbol for automatic zooming (then tailor #auto_density)
    t_atom                  maxterm_intwheel; // similar for the integer wheel
    t_atom                  maxfifths; // extension in the line of fifths, used in mode = 1, use "auto" symbol for automatic computing (then tailor #auto_density)
    t_llll                  *allowed_commas; // allowed combinations of commas, used in mode = 1, use "auto" symbol for automatic computing (then tailor #auto_density)
    double                  density; // density factor used while using automatic zooming
    double                  density_intwheel; // similar, but for the integers wheel
    bool                    auto_zooming; // 1 if the object needs auto-zooming (and hence rebuilding of pitches)
    t_atom                  allowed_limits[MAX_ALLOWED_LIMITS]; // list of allowed limits (or <= for less-than as first element), or "any" to leave it open
    long                    allowed_limits_count; // length of allowed_limits array (for real)
    t_atom                  allowed_primes[MAX_ALLOWED_PRIMES]; // list of allowed primes (or <= for less-than as first element), or "any" to leave it open
    long                    allowed_primes_count; // length of allowed_primes array (for real)

    char                    display_mapping;
    char                    display_what; //see enum above
    char                    color_mode;
    char                    text_direction;
    char                    rotate_for_legibility;
    char                    boost_whitekeys;
    char                    boost_pythagorean;
    char                    boost_et;
    char                    always_display_whitekeys;
    char                    always_show_coincidences_with_intwheel;

    char                    j_has_focus;
    char                    show_focus;
    double                  inset;
    
    t_rational              mouseover_ratio;
    t_rational              sel1_ratio;
    t_rational              sel2_ratio;

    t_pt                    mousedrag_pt;
    bool                    mouse_is_dragging;
    t_symbol                *importance_sym;
    bool                    mousedown_is_in_etwheel;
    
    t_symbol                *base_diatonic_pitch; // whitekey pitch used as a basis (letter)
    t_wheelpitch            *curr_pitches;
    long                    num_pitches;
    
    t_wheelpitch            curr_interval;
    
    // show/hide
    char                    show_ticks;
    char                    extend_ticks_to_integers;
    char                    show_ratios;
    char                    show_et_wheel;
    char                    show_integers_wheel;
    char                    show_circles;

    double                  tick_length;
    double                  et_wheel_size;
    double                  int_wheel_size;
    char                    avoid_collisions;
    double                  minfactor;
    
    char                    auto_move_intwheel;
    char                    output_selection;
    
    char                    rebuild;

    t_lexpr                 *n_importance_lexpr;
    
    void                    *n_proxy[3];
    long                    n_in;
    
    t_jrgba                 candycane1;
    t_jrgba                 candycane2;
    t_jrgba                 candycane3;
    t_jrgba                 candycane4;
    t_jrgba                 candycane5;
    t_jrgba                 candycane6;
    t_jrgba                 candycane7;
    t_jrgba                 candycane8;
    t_jrgba                 candycane9;
    t_jrgba                 candycane10;
    t_jrgba                 candycane11;
    t_jrgba                 candycane12;
    t_jrgba                 candycane13;
    t_jrgba                 candycane14;
    t_jrgba                 candycane15;
    t_jrgba                 candycane16;
    t_jrgba                 candycane17;
    t_jrgba                 candycane18;
    t_jrgba                 candycane19;
    t_jrgba                 candycane20;
    
    t_jrgba                 etwheel_color;
    t_jrgba                 selection_color;

    // legend
    char                    show_legend;
    t_symbol                *legend_fontname;
    double                  legend_fontsize;
    t_jrgba                 legend_color;

    t_symbol                *accidentals_font;
    double                  accidentals_font_size;

//    t_symbol                *textfont;
//    double                    textsize;
    
    t_systhread_mutex        c_mutex;

} t_jiwheel;


// global class pointer variable
t_class    *s_jiwheel_class = NULL;

// functions
void jiwheel_inletinfo(t_jiwheel *x, void *b, long a, char *t);
void jiwheel_assist(t_jiwheel *x, void *b, long m, long a, char *s);

void jiwheel_free(t_jiwheel *x);

void jiwheel_focusgained(t_jiwheel *x, t_object *patcherview);
void jiwheel_focuslost(t_jiwheel *x, t_object *patcherview);
void jiwheel_mousedown(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void jiwheel_mousemove(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void jiwheel_mouseup(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void jiwheel_mousedrag(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers);
void jiwheel_mousewheel(t_jiwheel *x, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc);
void jiwheel_mousedoubleclick(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers);
long jiwheel_key(t_jiwheel *x, t_object *patcherview, long keycode, long modifiers, long textcharacter);
t_max_err jiwheel_notify(t_jiwheel *x, t_symbol *s, t_symbol *msg, void *sender, void *data);

t_jiwheel* jiwheel_new(t_symbol *s, long argc, t_atom *argv);

void jiwheel_paint(t_jiwheel *x, t_object *view);

void jiwheel_anything(t_jiwheel *x, t_symbol *s, long argc, t_atom *argv);
void jiwheel_dump(t_jiwheel *x, t_symbol *s, long argc, t_atom *argv);
void jiwheel_int(t_jiwheel *x, t_atom_long num);
void jiwheel_float(t_jiwheel *x, double num);
void jiwheel_bang(t_jiwheel *x);
void jiwheel_preset(t_jiwheel *x);

void jiwheel_importance(t_jiwheel *x, t_symbol *s, long argc, t_atom *argv);
t_max_err jiwheel_setattr_importance(t_jiwheel *x, void *attr, long ac, t_atom *av);

void get_radius_and_center(t_jiwheel *x, t_object *patcherview, double *radius, double *center_x, double *center_y);
void jiwheel_clear_selection(t_jiwheel *x);

t_llll *jiwheel_get_wheelpitch_as_llll(t_jiwheel *x, t_wheelpitch *p, bool as_interval);
void jiwheel_output_selection(t_jiwheel *x);
void ensure_ratio_is_between_1_and_formaloctave(t_rational *r, long formaloctave);
t_llll *jiwheel_get_wheelpitch_as_llll(t_jiwheel *x, t_wheelpitch *p, bool as_interval);


DEFINE_LLLL_ATTR_DEFAULT_GETTER_AND_SETTER(t_jiwheel, allowed_commas, jiwheel_getattr_commas, jiwheel_setattr_commas);

// or pseudo octaves!
void remove_octaves(long formaloctave, t_rational *r)
{
    if (formaloctave >= 2) {
        while (r->r_num != 0 && r->r_num % formaloctave == 0)
            r->r_num /= formaloctave;
        while (r->r_den != 0 && r->r_den % formaloctave == 0)
            r->r_den /= formaloctave;
    }
}

void remove_octaves(t_jiwheel *x, t_rational *r)
{
    long octave = x->formaloctave;
    if (octave >= 2) {
        while (r->r_num != 0 && r->r_num % octave == 0)
            r->r_num /= octave;
        while (r->r_den != 0 && r->r_den % octave == 0)
            r->r_den /= octave;
    }
}



void build_commas()
{
    if (commas != NULL)
        return;
    
    numcommas = MAX_ALLOWED_PRIMES;
    commas = (t_rational *)bach_newptr(numcommas * sizeof(t_rational));

    // From Marc Sabat's personal communication
    // Search no further than + or – 7 fifths to avoid reading the diminished fourth and other enharmonics which differ by a schisma from 5-limit. Those would be possible spellings from a fundamental. Find the smallest comma. Find the nearest comma. Make a choice between the two.... set maximum comma size to 69c (1/3 of a tone) – does that make sense?
    for (long i = 0; i < numcommas; i++) {
        long prime = bach->b_primes[i+2];
        // what's the comma? we search for a ratio of the form
        // 2^n*3^m*prime
        t_rational comma = long2rat(0);
        double threshold = pow(2, 1./18.); // set maximum comma size to 69c (1/3 of a tone)
        double invthreshold = 2/threshold;
        double curr_comma_dbl = DBL_MAX;
        long curr_max_term = ATOM_LONG_MAX;
        // "search no further than + or – 7 fifths to avoid reading the diminished fourth and other enharmonics which differ by a schisma from 5-limit"
        for (long m = 0; m <= 7; m++) {
            t_rational r;
            
            r = genrat(ipow(3, m), prime);
            ensure_ratio_is_between_1_and_formaloctave(&r, 2);
            if (rat2double(r) > invthreshold || rat2double(r) < threshold) {
                if (rat2double(comma) < curr_comma_dbl) {
//                if (MAX(r.r_num, r.r_den) < curr_max_term) {
                    comma = r;
                    curr_max_term = MAX(r.r_num, r.r_den);
                    curr_comma_dbl = rat2double(r);
                }
            }

            r = genrat(1, prime * long2rat(ipow(3, m)));
            ensure_ratio_is_between_1_and_formaloctave(&r, 2);
            if (rat2double(r) > invthreshold || rat2double(r) < threshold) {
                if (rat2double(comma) < curr_comma_dbl) {
//                if (MAX(r.r_num, r.r_den) < curr_max_term) {
                    comma = r;
                    curr_max_term = MAX(r.r_num, r.r_den);
                    curr_comma_dbl = rat2double(r);
                }
            }
        }
        
        if (rat2double(comma) > invthreshold) {
            comma /= 2;
        }
        
        // Two exceptions to the rule - manual adjustments to comply with HEJIv2
        if (prime == 17)
            commas[i] = genrat(2187, 2176);
        else if (prime == 47)
            commas[i] = genrat(729,752);
        else
            commas[i] = comma;
        
//        post("prime %ld, comma: %ld/%ld (%.5f)", prime, comma.r_num, comma.r_den, MAX(comma.r_num, comma.r_den)*1./MIN(comma.r_num, comma.r_den));
    }
    
//    {genrat(81, 80), genrat(64, 63), genrat(32, 33), genrat(27, 26), genrat(2187, 2176), genrat(512, 513), genrat(729,736), genrat(256,261), genrat(32,31), genrat(36,37), genrat(81, 82), genrat(128,129), genrat(729,752)}

    
// 3^4 * 2^-4 * 5  ^-1  = 81/80
// 2^6 * 3^-2 * 7  ^-1  = 64/63
// 2^5 * 3^-1 * 11 ^-1  = 32/33
// 3^3 * 2^-1 * 13 ^-1  = 27/26
// 3^7 * 2^-7 * 17 ^-1  = 2187/2176     *** 4096/4131
// 2^9 * 3^-3 * 19 ^-1  = 512/513
// 3^6 * 2^-5 * 23 ^-1  = 729/736
// 2^8 * 3^-2 * 29 ^-1  = 256/261
// 2^5 * 3^0  * 31 ^-1  = 32/31
// 2^2 * 3^2  * 37 ^-1  = 36/37
// 3^4 * 2^-1 * 41 ^-1  = 81/82          *** 128/123
// 2^7 * 3^-1 * 43 ^-1  = 128/129
// 3^6 * 2^-4 * 47 ^-1  = 729/752

// why 2187/2176 instead of 4096/4131?
//   3^7*2^-7*17^-1 instead of 2^12*3^-5*17^-1
}



const char *jiwheel_ratio_to_common_interval_name(t_rational r, long *num_octaves)
{
    if (num_octaves) {
        if (rat_rat_cmp(r, long2rat(2)) > 0) {
            *num_octaves = (long)floor(rat2double(r)/2);
            ensure_ratio_is_between_1_and_formaloctave(&r, 2);
        }
    }
    
    switch (r.num()) {
        case 1:
            switch (r.den()) {
                case 1: return "unison";
                default: break;
            }
            break;
        case 2:
            switch (r.den()) {
                case 1: return "octave";
                default: break;
            }
            break;
        case 3:
            switch (r.den()) {
                case 2: return "just perfect fifth";
                default: break;
            }
            break;
        case 4:
            switch (r.den()) {
                case 3: return "just perfect fourth";
                default: break;
            }
            break;
        case 5:
            switch (r.den()) {
                case 3: return "just major sixth";
                case 4: return "just major third";
                default: break;
            }
            break;
        case 6:
            switch (r.den()) {
                case 5: return "just minor third";
                default: break;
            }
            break;
        case 7:
            switch (r.den()) {
                case 4: return "septimal minor seventh";
                case 5: return "septimal tritone";
                case 6: return "septimal minor third";
                default: break;
            }
            break;
        case 8:
            switch (r.den()) {
                case 5: return "just minor sixth";
                case 7: return "septimal whole tone";
                default: break;
            }
            break;
        case 9:
            switch (r.den()) {
                case 5: return "classic minor seventh";
                case 7: return "septimal major third";
                case 8: return "Pythagorean whole tone";
                default: break;
            }
            break;
        case 10:
            switch (r.den()) {
                case 7: return "superaugmented fourth";
                case 9: return "classic whole tone";
                default: break;
            }
            break;
        case 11:
            switch (r.den()) {
                case 6: return "undecimal neutral seventh";
                case 7: return "undecimal augmented fifth";
                case 8: return "undecimal semi-augmented fourth";
                case 9: return "undecimal neutral third";
                case 10: return "undecimal submajor second";
                default: break;
            }
            break;
        case 12:
            switch (r.den()) {
                case 7: return "septimal major sixth";
                case 11: return "small undecimal neutral second";
                default: break;
            }
            break;
        case 13:
            switch (r.den()) {
                case 7: return "tridecimal submajor seventh";
                case 8: return "lesser tridecimal neutral sixth";
                case 9: return "tridecimal diminished fifth";
                case 10: return "tridecimal semisixth";
                case 11: return "tridecimal minor third";
                case 12: return "tridecimal neutral second";
                default: break;
            }
            break;
        case 14:
            switch (r.den()) {
                case 9: return "subminor sixth";
                case 11: return "undecimal major third";
                case 13: return "tridecimal supraminor second";
                default: break;
            }
            break;
        case 15:
            switch (r.den()) {
                case 8: return "classic major seventh";
                case 11: return "undecimal augmented fourth";
                case 13: return "tridecimal semifourth";
                case 14: return "septimal diatonic semitone";
                default: break;
            }
            break;
        case 16:
            switch (r.den()) {
                case 9: return "Pythagorean minor seventh";
                case 11: return "Sub-fifth";
                case 13: return "greater tridecimal neutral third";
                case 15: return "classic minor second";
                default: break;
            }
            break;
        case 17:
            switch (r.den()) {
                case 9: return "septendecimal major seventh";
                case 10: return "septendecimal diminished seventh";
                case 11: return "septendecimal subminor sixth";
                case 12: return "larger septendecimal tritone";
                case 13: return "septendecimal sub-fourth";
                case 14: return "septendecimal supraminor third";
                case 15: return "septendecimal whole tone";
                case 16: return "large septendecimal semitone";
                default: break;
            }
            break;
        case 18:
            switch (r.den()) {
                case 11: return "undecimal neutral sixth";
                case 13: return "tridecimal augmented fourth";
                case 17: return "small septendecimal semitone";
                default: break;
            }
            break;
        case 19:
            switch (r.den()) {
                case 10: return "undevicesimal diminished octave";
                case 11: return "undevicesimal semitwelfth";
                case 14: return "hendrix fourth";
                case 15: return "Eratosthenes' major third";
                case 16: return "otonal minor third";
                case 17: return "quasi-meantone";
                case 18: return "septimal minor semitone";
                default: break;
            }
            break;
        case 20:
            switch (r.den()) {
                case 11: return "small undecimal neutral seventh";
                case 13: return "tridecimal semitenth";
                case 17: return "septendecimal augmented second";
                case 19: return "small undevicesimal semitone";
                default: break;
            }
            break;
        case 21:
            switch (r.den()) {
                case 13: return "tridecimal supraminor sixth";
                case 16: return "narrow fourth";
                case 17: return "septendecimal submajor third";
                case 20: return "minor semitone";
                default: break;
            }
            break;
        case 22:
            switch (r.den()) {
                case 13: return "tridecimal major sixth";
                case 15: return "undecimal diminished fifth";
                case 17: return "septendecimal supermajor third";
                case 19: return "undevicesimal semifourth";
                case 21: return "undecimal minor semitone";
                default: break;
            }
            break;
        case 23:
            switch (r.den()) {
                case 16: return "vicesimotertial superaugmented fourth";
                case 18: return "vicesimotertial diminished fourth";
                case 19: return "vicesimotertial supraminor third";
                default: break;
            }
            break;
        case 24:
            switch (r.den()) {
                case 13: return "tridecimal neutral seventh";
                case 17: return "smaller septendecimal tritone";
                case 19: return "Boethius' major third";
                case 23: return "lesser vicesimotertial semitone";
                default: break;
            }
            break;
        case 25:
            switch (r.den()) {
                case 14: return "middle minor seventh";
                case 16: return "pental augmented fifth";
                case 18: return "classic augmented fourth";
                case 21: return "quasi-tempered minor third";
                case 24: return "classic chromatic semitone";
                default: break;
            }
            break;
        case 26:
            switch (r.den()) {
                case 15: return "tridecimal semitwelfth";
                case 17: return "septendecimal super-fifth";
                case 25: return "large tridecimal third tone";
                default: break;
            }
            break;
        case 27:
            switch (r.den()) {
                case 14: return "septimal major seventh";
                case 16: return "Pythagorean major sixth";
                case 20: return "acute fourth";
                case 22: return "rastmic neutral third";
                case 25: return "large limma";
                case 26: return "small tridecimal third tone";
                default: break;
            }
            break;
        case 28:
            switch (r.den()) {
                case 15: return "grave major seventh";
                case 17: return "septendecimal submajor sixth";
                case 19: return "hendrix fifth";
                case 25: return "middle major second";
                case 27: return "septimal third-tone";
                default: break;
            }
            break;
        case 29:
            switch (r.den()) {
                case 16: return "vicesimononal supraminor seventh";
                default: break;
            }
            break;
        case 30:
            switch (r.den()) {
                case 17: return "septendecimal minor seventh";
                default: break;
            }
            break;
        case 31:
            switch (r.den()) {
                case 16: return "tricesimoprimal semidiminished octave";
                case 24: return "sensi supermajor third";
                default: break;
            }
            break;
        case 32:
            switch (r.den()) {
                case 17: return "septendecimal diminished octave";
                case 19: return "utonal major sixth";
                case 21: return "super-fifth, wide fifth";
                case 25: return "classic diminished fourth";
                case 27: return "Pythagorean minor third";
                default: break;
            }
            break;
        case 33:
            switch (r.den()) {
                case 25: return "5EDO-esque fourth";
                case 26: return "tridecimal major third";
                case 32: return "undecimal diesis";
                default: break;
            }
            break;
        case 34:
            switch (r.den()) {
                case 19: return "quasi-meantone minor seventh";
                default: break;
            }
            break;
        case 35:
            switch (r.den()) {
                case 18: return "septimal semidiminished octave";
                case 24: return "septimal sub-fifth";
                case 26: return "animist fourth";
                case 27: return "septimal semidiminished fourth";
                case 29: return "doublewide minor third";
                case 32: return "septimal neutral second";
                default: break;
            }
            break;
        case 36:
            switch (r.den()) {
                case 19: return "undevicesimal major seventh";
                case 23: return "vicesimotertial augmented fifth";
                case 25: return "pental diminished fifth";
                case 35: return "septimal quarter tone";
                default: break;
            }
            break;
        case 38:
            switch (r.den()) {
                case 23: return "vicesimotertial submajor sixth";
                default: break;
            }
            break;
        case 39:
            switch (r.den()) {
                case 32: return "lesser tridecimal neutral third";
                default: break;
            }
            break;
        case 40:
            switch (r.den()) {
                case 21: return "septimal acute major seventh";
                case 27: return "grave fifth";
                default: break;
            }
            break;
        case 42:
            switch (r.den()) {
                case 25: return "quasi-tempered major sixth";
                default: break;
            }
            break;
        case 45:
            switch (r.den()) {
                case 32: return "smaller pental tritone";
                case 44: return "undecimal diesis";
                default: break;
            }
            break;
        case 48:
            switch (r.den()) {
                case 25: return "classic diminished octave";
                case 35: return "septimal super-fourth";
                default: break;
            }
            break;
        case 49:
            switch (r.den()) {
                case 25: return "Bohlen-Pierce eighth";
                case 32: return "superduper fifth";
                case 36: return "Arabic lute acute fourth";
                case 40: return "larger septimal neutral third";
                case 44: return "mothwellsmic major second";
                case 45: return "swetismic neutral second";
                case 48: return "slendro diesis";
                default: break;
            }
            break;
        case 50:
            switch (r.den()) {
                case 33: return "5EDO-esque fifth";
                case 49: return "tritonic diesis";
                default: break;
            }
            break;
        case 51:
            switch (r.den()) {
                case 41: return "maja third";
                default: break;
            }
            break;
        case 52:
            switch (r.den()) {
                case 33: return "tridecimal minor sixth";
                case 35: return "animist fifth";
                default: break;
            }
            break;
        case 54:
            switch (r.den()) {
                case 49: return "Zalzal's mujannab";
                default: break;
            }
            break;
        case 55:
            switch (r.den()) {
                case 32: return "keenanismic supermajor sixth";
                case 39: return "smaller gassormic tritone";
                case 48: return "keenanismic supermajor second";
                case 49: return "werckismic tone";
                default: break;
            }
            break;
        case 56:
            switch (r.den()) {
                case 45: return "narrow perde segah";
                default: break;
            }
            break;
        case 60:
            switch (r.den()) {
                case 49: return "smaller septimal neutral third";
                default: break;
            }
            break;
        case 61:
            switch (r.den()) {
                case 32: return "octave-reduced 61st harmonic";
                case 51: return "myna third";
                default: break;
            }
            break;
        case 62:
            switch (r.den()) {
                case 53: return "orwell subminor third";
                default: break;
            }
            break;
        case 63:
            switch (r.den()) {
                case 40: return "narrow minor sixth";
                case 50: return "quasi-tempered major third";
                case 55: return "werckismic supermajor second";
                default: break;
            }
            break;
        case 64:
            switch (r.den()) {
                case 33: return "undecimal semidiminished octave";
                case 35: return "septimal neutral seventh";
                case 45: return "larger pental tritone";
                case 49: return "septatonic major third";
                case 55: return "keenanismic subminor third";
                case 57: return "quasi-tempered whole tone";
                case 61: return "harry minor semitone";
                case 63: return "septimal comma";
                default: break;
            }
            break;
        case 65:
            switch (r.den()) {
                case 64: return "wilsorma";
                default: break;
            }
            break;
        case 66:
            switch (r.den()) {
                case 65: return "winmeanma";
                default: break;
            }
            break;
        case 68:
            switch (r.den()) {
                case 65: return "valentine semitone";
                default: break;
            }
            break;
        case 71:
            switch (r.den()) {
                case 40: return "harmonic/just minor seventh meantone";
                case 57: return "witchcraft major third";
                default: break;
            }
            break;
        case 72:
            switch (r.den()) {
                case 49: return "septimal catafifth";
                default: break;
            }
            break;
        case 73:
            switch (r.den()) {
                case 60: return "amity supraminor third";
                default: break;
            }
            break;
        case 75:
            switch (r.den()) {
                case 56: return "marvelous fourth";
                case 64: return "classic augmented second";
                default: break;
            }
            break;
        case 76:
            switch (r.den()) {
                case 61: return "magic major third";
                default: break;
            }
            break;
        case 77:
            switch (r.den()) {
                case 60: return "swetismic supermajor third";
                case 64: return "keenanismic minor third";
                case 72: return "undecimal secor";
                default: break;
            }
            break;
        case 78:
            switch (r.den()) {
                case 55: return "larger gassormic tritone";
                case 71: return "porcupine neutral second";
                default: break;
            }
            break;
        case 80:
            switch (r.den()) {
                case 63: return "5/7-kleismic major third";
                default: break;
            }
            break;
        case 81:
            switch (r.den()) {
                case 55: return "undecimal catafifth";
                case 64: return "Pythagorean major third";
                case 70: return "septimal semi-augmented second";
                case 80: return "syntonic comma";
                default: break;
            }
            break;
        case 88:
            switch (r.den()) {
                case 63: return "pentacircle diminished fifth";
                case 81: return "undecimal subtone";
                default: break;
            }
            break;
        case 90:
            switch (r.den()) {
                case 77: return "swetismic subminor third";
                default: break;
            }
            break;
        case 91:
            switch (r.den()) {
                case 64: return "larger huntmic tritone";
                default: break;
            }
            break;
        case 96:
            switch (r.den()) {
                case 77: return "undecimal perde segah";
                default: break;
            }
            break;
        case 97:
            switch (r.den()) {
                case 56: return "homothetic semitwelth";
                case 84: return "homothetic semifourth";
                default: break;
            }
            break;
        case 99:
            switch (r.den()) {
                case 70: return "homothetic quasi-tempered tritone";
                case 98: return "mothwellsma";
                default: break;
            }
            break;
        case 100:
            switch (r.den()) {
                case 97: return "shrutar quarter tone";
                case 99: return "ptolemisma";
                default: break;
            }
            break;
        case 105:
            switch (r.den()) {
                case 64: return "quasi-tempered 5/7-octave";
                default: break;
            }
            break;
        case 108:
            switch (r.den()) {
                case 77: return "swetismic augmented fourth";
                default: break;
            }
            break;
        case 112:
            switch (r.den()) {
                case 75: return "marvelous fifth";
                default: break;
            }
            break;
        case 117:
            switch (r.den()) {
                case 88: return "minthmic fourth";
                default: break;
            }
            break;
        case 121:
            switch (r.den()) {
                case 80: return "wide biyatismic fifth";
                case 90: return "wide biyatismic fourth";
                default: break;
            }
            break;
        case 126:
            switch (r.den()) {
                case 125: return "starling comma";
                default: break;
            }
            break;
        case 127:
            switch (r.den()) {
                case 72: return "harmonic/Pythagorean minor seventh meantone";
                default: break;
            }
            break;
        case 128:
            switch (r.den()) {
                case 81: return "Pythagorean minor sixth";
                case 91: return "smaller huntmic tritone";
                case 105: return "quasi-tempered 2/7-octave";
                case 125: return "minor diesis";
                default: break;
            }
            break;
        case 135:
            switch (r.den()) {
                case 112: return "large septimal minor third";
                case 128: return "major limma";
                default: break;
            }
            break;
        case 140:
            switch (r.den()) {
                case 81: return "septimal semidiminished seventh";
                default: break;
            }
            break;
        case 160:
            switch (r.den()) {
                case 81: return "octave minus syntonic comma";
                case 121: return "narrow biyatismic fourth";
                default: break;
            }
            break;
        case 161:
            switch (r.den()) {
                case 128: return "just/Pythagorean major third meantone";
                default: break;
            }
            break;
        case 176:
            switch (r.den()) {
                case 117: return "minthmic fifth";
                default: break;
            }
            break;
        case 180:
            switch (r.den()) {
                case 121: return "narrow biyatismic fifth";
                default: break;
            }
            break;
        case 182:
            switch (r.den()) {
                case 121: return "tridecimal gentle fifth";
                default: break;
            }
            break;
        case 224:
            switch (r.den()) {
                case 195: return "quasi-tempered 1/5-octave";
                default: break;
            }
            break;
        case 225:
            switch (r.den()) {
                case 128: return "marvel five-limit harmonic seventh";
                case 224: return "marvel comma";
                default: break;
            }
            break;
        case 243:
            switch (r.den()) {
                case 128: return "Pythagorean major seventh";
                case 224: return "septimal subtone";
                default: break;
            }
            break;
        case 250:
            switch (r.den()) {
                case 243: return "porcupine comma";
                default: break;
            }
            break;
        case 256:
            switch (r.den()) {
                case 243: return "Pythagorean limma";
                default: break;
            }
            break;
        case 525:
            switch (r.den()) {
                case 512: return "avicennma";
                default: break;
            }
            break;
        case 625:
            switch (r.den()) {
                case 512: return "pental neutral third";
                default: break;
            }
            break;
        case 648:
            switch (r.den()) {
                case 625: return "major diesis";
                default: break;
            }
            break;
        case 729:
            switch (r.den()) {
                case 490: return "septimal sesquiaugmented acute fourth";
                default: break;
            }
            break;
        case 959:
            switch (r.den()) {
                case 540: return "harmonic/Pythagorean/just minor seventh meantone";
                default: break;
            }
            break;
        case 980:
            switch (r.den()) {
                case 729: return "septimal sesquidiminished grave fifth";
                default: break;
            }
            break;
        case 1053:
            switch (r.den()) {
                case 1024: return "tridecimal quartertone";
                default: break;
            }
            break;
        case 2048:
            switch (r.den()) {
                case 2025: return "diaschisma";
                default: break;
            }
            break;
        case 2187:
            switch (r.den()) {
                case 2048: return "Pythagorean augmented unison";
                default: break;
            }
            break;
        case 3125:
            switch (r.den()) {
                case 3072: return "small diesis";
                default: break;
            }
            break;
        case 6272:
            switch (r.den()) {
                case 5625: return "double marvelous second";
                default: break;
            }
            break;
        case 16384:
            switch (r.den()) {
                case 10935: return "12EDO-esque fifth";
                default: break;
            }
            break;
        case 32805:
            switch (r.den()) {
                case 32768: return "schisma";
                default: break;
            }
            break;
        case 59049:
            switch (r.den()) {
                case 57344: return "Harrison's comma";
                default: break;
            }
            break;
        case 262144:
            switch (r.den()) {
                case 177147: return "Pythagorean wolf fifth";
                default: break;
            }
            break;
        case 531441:
            switch (r.den()) {
                case 524288: return "Pythagorean comma";
                default: break;
            }
            break;
        default:
            break;
    }
    return "";
}

t_jrgba jiwheel_long_to_color(t_jiwheel *x, long value)
{
    if (value == ATOM_LONG_MAX) {
        return x->j_textcolor;
    }
    
    switch (positive_mod(value, 10)) {
        case 0:
            return x->candycane1;
        case 1:
            return x->candycane2;
        case 2:
            return x->candycane3;
        case 3:
            return x->candycane4;
        case 4:
            return x->candycane5;
        case 5:
            return x->candycane6;
        case 6:
            return x->candycane7;
        case 7:
            return x->candycane8;
        case 8:
            return x->candycane9;
        default:
            return x->candycane10;
    }
    return x->j_textcolor;
}


long num_to_prime_idx(long num)
{
    // slow... to be optimized with a table
    for (long i = 0; i < LLLL_PRIMES_TABLE_SIZE; i++)
        if (bach->b_primes[i] == num)
            return i;
    
/*    for (long i = 0; i < num_ezprimes; i++)
        if (ezprimes[i] == num)
            return i;
*/
    return -1;
}

void jiwheel_bang(t_jiwheel *x)
{
    if (x->j_box.l_rebuild == 1 || proxy_getinlet((t_object *) x) != 0)
        jiwheel_anything(x, _sym_bang, 0, NULL);
}

void jiwheel_preset(t_jiwheel *x)
{
/*    long ac = x->num_points * 2 + 1;
    t_atom *av = (t_atom *) bach_newptr(ac * sizeof(t_atom)); 
    long i;
    void *preset_buf;// Binbuf that stores the preset 
    short atomCount;
    t_atom *atomArray; // array of atoms to be stored 
    for (i = 0; i < x->num_points; i++){
        atom_setlong(av + 2*i, x->points[i]);
        atom_setlong(av + 2*i+1, x->vels[i]);
    }
    atom_setlong(av + 2 * x->num_points, x->modulo);
    
    atomCount = (short)(ac + 3); // number of atoms we’re storing 
    atomArray = (t_atom *) bach_newptr(atomCount * sizeof(t_atom));
    // 1. prepare the preset "header" information 
    atom_setobj(atomArray,x); 
    atom_setsym(atomArray+1,ob_sym(x)); 
    atom_setsym(atomArray+2, _llllobj_sym_setinterleaved); 
    memcpy(atomArray+3, av, ac*sizeof(t_atom));
    // fill atomArray+3 with object’s state here and set atomCount 
    // 2. find the Binbuf 
    preset_buf = _sym__preset->s_thing; 
    // 3. store the data 
    if (preset_buf) { 
        binbuf_insert(preset_buf, NULL, atomCount, atomArray); 
    } 
    
    if (av) bach_freeptr(av);
    bach_freeptr(atomArray);
 */
}

void C74_EXPORT ext_main(void *moduleRef)
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();

    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return;
    }

    CLASS_NEW_CHECK_SIZE(c, "bach.jiwheel",
                        (method)jiwheel_new,
                        (method)jiwheel_free,
                        sizeof(t_jiwheel),
                        (method)NULL,
                        A_GIMME,
                        0L);
    
    c->c_flags |= CLASS_FLAG_NEWDICTIONARY;

//    jbox_initclass(c, JBOX_COLOR | JBOX_FIXWIDTH | JBOX_FONTATTR);
    jbox_initclass(c, JBOX_TEXTFIELD | JBOX_FONTATTR);    // include textfield and Fonts attributes
    jbox_initclass(c, 0);
    
    class_addmethod(c, (method) jiwheel_paint,            "paint", A_CANT, 0);

    class_addmethod(c, (method) jiwheel_anything, "anything", A_GIMME, 0);
    class_addmethod(c, (method) jiwheel_anything, "list", A_GIMME, 0);

    // @method dump @digest Output all pitches
    // @description Outputs the information about all pitches from the first outlet. If the "visible" symbol is given as first argument, only visible pitches
    // are output; otherwise, the ones that have been hidden to avoid collisions are also output (default behavior).
    // @marg 0 @name visible @optional 1 @type symbol
    // @example dump @caption output all pitches
    // @example dump visible @caption output visible pitches only
    class_addmethod(c, (method) jiwheel_dump, "dump", A_GIMME, 0);


    class_addmethod(c, (method) jiwheel_int, "int", A_LONG, 0);
    class_addmethod(c, (method) jiwheel_float, "float", A_FLOAT, 0);

    class_addmethod(c, (method) jiwheel_bang, "bang", 0);

    class_addmethod(c, (method) jiwheel_anything, "clear", A_GIMME, 0);

    // @method (mouse) @digest Select pitches and create intervals
    // @description 
    // • <m>click</m>: select a pitch <br />
    // • <m>Shift+click</m>: select a pitch to be used as second extreme of an interval <br />
    // • <m>click+drag</m>: select an interval <br />
    // • <m>doubleclick</m> or <m>Alt+click</m>: rotate integer wheel so that number 1 matches a specific pitch <br />
    class_addmethod(c, (method) jiwheel_mousedown, "mousedown", A_CANT, 0);
    class_addmethod(c, (method) jiwheel_mousedrag, "mousedrag", A_CANT, 0);
    class_addmethod(c, (method) jiwheel_mouseup, "mouseup", A_CANT, 0);
    class_addmethod(c, (method) jiwheel_mousemove, "mousemove", A_CANT, 0);
    class_addmethod(c, (method) jiwheel_mousewheel, "mousewheel", A_CANT, 0);
    class_addmethod(c, (method) jiwheel_mousedoubleclick, "mousedoubleclick", A_CANT, 0);

    class_addmethod(c, (method) jiwheel_notify, "bachnotify", A_CANT, 0);

    // @method (keyboard) @digest Operate on interface
    // @description 
    // • <m>Esc</m>: reset rotation and zoom <br />
      class_addmethod(c, (method) jiwheel_key, "key", A_CANT, 0);

    class_addmethod(c, (method) jiwheel_preset, "preset", 0);

    class_addmethod(c, (method) jiwheel_focusgained, "focusgained", A_CANT, 0);
    class_addmethod(c, (method) jiwheel_focuslost, "focuslost", A_CANT, 0);

    class_addmethod(c, (method) jiwheel_inletinfo, "inletinfo", A_CANT, 0);
    class_addmethod(c, (method) jiwheel_assist, "assist", A_CANT, 0);

    llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_UI);

    CLASS_ATTR_DEFAULT(c, "fontsize", 0, "24"); // new font size
    // @exclude bach.jiwheel
    CLASS_ATTR_DEFAULT(c, "patching_rect", 0, "0 0 850 600"); // new dimensions
    // @exclude bach.jiwheel
    CLASS_ATTR_DEFAULT(c, "presentation_rect", 0, "0 0 850 600"); // new dimensions
    // @exclude bach.jiwheel
    CLASS_ATTR_DEFAULT(c, "fontname", 0, "Times New Roman"); // new dimensions
    // @exclude bach.jiwheel

    CLASS_STICKY_ATTR(c,"category",0,"Color");

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "textcolor", 0, t_jiwheel, j_bgcolor, "Text Color", "text_number");
        CLASS_ATTR_LEGACYDEFAULT(c, "textcolor", "textcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_BASIC(c, "textcolor", 0);
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"textcolor", "numberstextcolor");
        CLASS_ATTR_STYLE_ALIAS_NOSAVE(c,"textcolor", "modulotextcolor");
        // @exclude all
#else
        CLASS_ATTR_RGBA(c, "textcolor", 0, t_jiwheel, j_textcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "textcolor", 0, "0. 0. 0. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "textcolor", 0, "rgba", "Text Color");
        // @description Color of the text.
#endif

#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_STYLE_RGBA_PREVIEW(c, "bgcolor", 0, t_jiwheel, j_bgcolor, "Background Color", "rect_fill");
        CLASS_ATTR_LEGACYDEFAULT(c, "bgcolor", "bgcolor", 0, "1. 1. 1. 1.");
        CLASS_ATTR_BASIC(c, "bgcolor", 0);
        // @description Diagram external background color
#else
        CLASS_ATTR_RGBA(c, "bgcolor", 0, t_jiwheel, j_bgcolor);
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bgcolor", 0, "1. 1. 1. 1.");
        CLASS_ATTR_STYLE_LABEL(c, "bgcolor", 0, "rgba", "Background Color");
        CLASS_ATTR_BASIC(c, "bgcolor",0);
#endif

        CLASS_ATTR_RGBA(c, "bordercolor", 0, t_jiwheel, j_bordercolor);
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0. 0. 0. 0.");
#else
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "bordercolor", 0, "0.2 0.2 0.2 1.");
#endif
        CLASS_ATTR_STYLE_LABEL(c, "bordercolor", 0, "rgba", "Border Color");
        // @description Color of the diagram border

    CLASS_ATTR_RGBA(c,"selectioncolor", 0, t_jiwheel, selection_color);
    CLASS_ATTR_STYLE_LABEL(c, "selectioncolor",0,"rgba","Selection Color");
    CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"selectioncolor",0,"0.8 0. 0.8 1.");
    // @description Sets the color for selection in RGBA format.

    CLASS_ATTR_RGBA(c,"legendcolor", 0, t_jiwheel, legend_color);
    CLASS_ATTR_STYLE_LABEL(c, "legendcolor",0,"rgba","Legend Color");
    CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"legendcolor",0,"0.5 0.5 0.5 1.");
    // @description Sets the color for the legend.

    CLASS_ATTR_RGBA(c,"etwheelcolor", 0, t_jiwheel, etwheel_color);
    CLASS_ATTR_STYLE_LABEL(c, "etwheelcolor",0,"rgba","Equal-Temperament Wheel Color");
    CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"etwheelcolor",0,"0.75 0.75 0.75 1.");
    // @description Sets the color for the equal temperament wheel.

    
    CLASS_STICKY_ATTR_CLEAR(c, "category");


    CLASS_STICKY_ATTR(c,"category",0,"Show");
    
        CLASS_ATTR_CHAR(c,"showfocus",0, t_jiwheel, show_focus);
        CLASS_ATTR_STYLE_LABEL(c,"showfocus",0,"onoff","Show Focus");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showfocus",0,"1");
        // @description Show that the object has the focus by increasing the width of the border.
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    CLASS_STICKY_ATTR(c, "category", 0, "Font");
    
        CLASS_ATTR_SYM(c,"accidentalsfont", 0, t_jiwheel, accidentals_font);
        CLASS_ATTR_STYLE_LABEL(c, "accidentalsfont",0,"font","Accidentals Font");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"accidentalsfont", 0, "\"Bravura\"");
        // @description @copy BACH_DOC_ACCIDENTALS_FONT
        // <br />
        // The accidentals font must be SMUFL-compliant.

        CLASS_ATTR_DOUBLE(c,"accidentalsfontsize", 0, t_jiwheel, accidentals_font_size);
        CLASS_ATTR_STYLE_LABEL(c, "accidentalsfontsize",0,"text","Accidentals Font Size");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"accidentalsfontsize", 0, "36");
        // @description Sets the maximum size of the accidentals (in pt).

        CLASS_ATTR_SYM(c,"legendfont", 0, t_jiwheel, legend_fontname);
        CLASS_ATTR_STYLE_LABEL(c, "legendfont",0,"font","Legend Font");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"legendfont", 0, "\"Arial\"");
        // @description Chooses the font used for the legend.

        CLASS_ATTR_DOUBLE(c,"legendfontsize", 0, t_jiwheel, legend_fontsize);
        CLASS_ATTR_STYLE_LABEL(c, "legendfontsize",0,"text","Legend Font Size");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"legendfontsize", 0, "12");
        // @description Sets the legend size (in pt).

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c, "category", 0, "Behavior");

        CLASS_ATTR_CHAR(c, "outputsel", 0, t_jiwheel, output_selection);
        CLASS_ATTR_STYLE_LABEL(c,"outputsel",0,"onoff","Output Selection");
        CLASS_ATTR_DEFAULTNAME_SAVE_PAINT(c,"outputsel", 0, "1");
        // @description Toggles the ability to output the selection

    CLASS_STICKY_ATTR_CLEAR(c, "category");


    CLASS_STICKY_ATTR(c, "category", 0, "Settings");

        CLASS_ATTR_LONG(c, "formaloctave", 0, t_jiwheel, formaloctave);
        CLASS_ATTR_STYLE_LABEL(c,"formaloctave",0,"text","Formal Octave Harmonic");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"formaloctave",0,"2");
        CLASS_ATTR_FILTER_MIN(c, "formaloctave", 2)
        // @description Sets the harmonic number corresponding to the formal octave (defaults to 2: actual octave)
    
        CLASS_ATTR_SYM(c, "basis", 0, t_jiwheel, base_diatonic_pitch);
        CLASS_ATTR_STYLE_LABEL(c,"basis",0,"text","Basis Diatonic Pitch");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"basis",0,"A");
        CLASS_ATTR_BASIC(c,"basis",0);
        // @description Sets the diatonic pitch corresponding to the 1/1 ratio (as one of the letters A through G).

        CLASS_ATTR_CHAR(c, "display", 0, t_jiwheel, display_what);
        CLASS_ATTR_STYLE_LABEL(c,"display",0,"enumindex","Display");
        CLASS_ATTR_ENUMINDEX(c,"display", 0, "Ratios Accidentals");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"display",0,"1");
        CLASS_ATTR_BASIC(c,"display",0);
        // @description Decides what to display: 0 (Ratios) or 1 (Accidentals).

        CLASS_ATTR_CHAR(c, "mode", 0, t_jiwheel, mode);
        CLASS_ATTR_STYLE_LABEL(c,"mode",0,"enumindex","Mode");
        CLASS_ATTR_ENUMINDEX(c,"mode", 0, "Maximum Term Prime Limits");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mode",0,"0");
        CLASS_ATTR_BASIC(c,"mode",0);
        // @description Sets the representation mode: either up to a maximum term for numerator/denominator (0) or using prime limits,
        // by combining just intonation commas (1). In the first case, see <m>maxterm</m>. In the second, see <m>fifthext</m> and <m>commas</m>.

        CLASS_ATTR_ATOM(c, "maxterm", 0, t_jiwheel, maxterm);
        CLASS_ATTR_STYLE_LABEL(c,"maxterm",0,"text","Maximum Term");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxterm",0,"auto");
        CLASS_ATTR_BASIC(c,"maxterm",0);
        // @description Sets the maximum term used if <m>mode</m> is 0. Leave this to "auto" for automatic zooming
        // (and tailor the <m>density</m> attribute in this case).

        CLASS_ATTR_ATOM(c, "maxtermintwheel", 0, t_jiwheel, maxterm_intwheel);
        CLASS_ATTR_STYLE_LABEL(c,"maxtermintwheel",0,"text","Maximum Number in Integers Wheel");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"maxtermintwheel",0,"auto");
        CLASS_ATTR_BASIC(c,"maxtermintwheel",0);
        // @description Sets the maximum number in the integers wheel. Leave this to "auto" for automatic zooming.

        CLASS_ATTR_ATOM(c, "fifthext", 0, t_jiwheel, maxfifths);
        CLASS_ATTR_STYLE_LABEL(c,"fifthext",0,"text","Extension Of Pythagorean Fifths");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"fifthext",0,"auto");
        CLASS_ATTR_BASIC(c,"fifthext",0);
        // @description Sets the number of Pythagorean fifths calculated at every side of the basis pitch,
        // used if <m>mode</m> is 1. Leave this to "auto" for automatic zooming.

        CLASS_ATTR_LLLL(c, "commas", 0, t_jiwheel, allowed_commas, jiwheel_getattr_commas, jiwheel_setattr_commas);
        CLASS_ATTR_STYLE_LABEL(c,"commas",0,"text_large","Allowed Commas");
        CLASS_ATTR_SAVE(c, "commas", 0);
        CLASS_ATTR_PAINT(c, "commas", 0);
        CLASS_ATTR_BASIC(c, "commas", 0);
        // @description Sets the commas used if <m>mode</m> is 1. Leave this to "auto" for automatic zooming
        // (and tailor the <m>density</m> attribute in this case).

        CLASS_ATTR_DOUBLE(c, "density", 0, t_jiwheel, density);
        CLASS_ATTR_STYLE_LABEL(c,"density",0,"text","Density");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"density",0,"1.");
        CLASS_ATTR_BASIC(c,"density",0);
        // @description Sets the density of displayed pitches, used when display is in automatic zooming.

        CLASS_ATTR_DOUBLE(c, "intwheeldensity", 0, t_jiwheel, density_intwheel);
        CLASS_ATTR_STYLE_LABEL(c,"intwheeldensity",0,"text","Integers Wheel Density");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"intwheeldensity",0,"1.");
        CLASS_ATTR_BASIC(c,"intwheeldensity",0);
        // @description Sets the density of integers in the integers wheel, used when display is in automatic zooming.

        CLASS_ATTR_ATOM_VARSIZE(c, "limits", 0, t_jiwheel, allowed_limits, allowed_limits_count, MAX_ALLOWED_LIMITS);
        CLASS_ATTR_STYLE_LABEL(c,"limits",0,"text","Allowed Limits");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"limits",0,"any");
        CLASS_ATTR_BASIC(c,"limits",0);
        // @description Sets the allowed limits for the displayed pitches. Leave "any" to unconstrain.
        // Use "<=" as first element to choose limits less or equal to a certain number.

        CLASS_ATTR_ATOM_VARSIZE(c, "primes", 0, t_jiwheel, allowed_primes, allowed_primes_count, MAX_ALLOWED_PRIMES);
        CLASS_ATTR_STYLE_LABEL(c,"primes",0,"text","Allowed Primes");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"primes",0,"any");
        CLASS_ATTR_BASIC(c,"primes",0);
        // @description Sets the allowed primes for the displayed pitches. Leave "any" to unconstrain.
        // Use "<=" as first element to choose limits less or equal to a certain number.
        // Notice that this is slightly different than <m>limits</m>: when using <m>limits</m> one
        // is constraining the highest prime appearing in the ratio, while when using <m>primes</m>
        // one is constraining _all_ the primes appearing in the ratio.

        CLASS_ATTR_CHAR(c, "mapping", 0, t_jiwheel, display_mapping);
        CLASS_ATTR_STYLE_LABEL(c,"mapping",0,"enumindex","Mapping");
        CLASS_ATTR_ENUMINDEX(c,"mapping", 0, "Pitch Frequency");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"mapping",0,"0");
        CLASS_ATTR_BASIC(c,"mapping",0);
        // @description Sets the mapping: either linear in pitch (0) or linear in frequency (1)

        CLASS_ATTR_SYM(c, "importance", 0, t_jiwheel, importance_sym);
        CLASS_ATTR_STYLE_LABEL(c,"importance",0,"text","Importance");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"importance",0,"(1-atan(maxexp*0.25)/1.5707)/pow(limit\\,0.3)");
        CLASS_ATTR_ACCESSORS(c, "importance", (method)NULL, (method)jiwheel_setattr_importance);
        // @description Sets the formula defining how important is each fraction. You can use as variables
        // "num" (numerator), "den" (denominator), "min" (min between the two), "max" (max between the two), "limit" (prime limit of the fraction),
        // and "maxexp" (largest power of each limit > 2).
    
        CLASS_ATTR_CHAR(c, "hidecollisions", 0, t_jiwheel, avoid_collisions);
        CLASS_ATTR_STYLE_LABEL(c,"hidecollisions",0,"onoff","Hide Collisions");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"hidecollisions",0,"1");
        // @description Toggles the ability to hide labels when colliding with others

        CLASS_ATTR_CHAR(c, "boostwhitekeys", 0, t_jiwheel, boost_whitekeys);
        CLASS_ATTR_STYLE_LABEL(c,"boostwhitekeys",0,"onoff","Boost White-Keys Pitches");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"boostwhitekeys",0,"1");
        // @description If set, boosts the importance of diatonic "white-keys" pitches, with no accidentals (i.e. 'A' through 'G').

        CLASS_ATTR_CHAR(c, "boostpythagorean", 0, t_jiwheel, boost_pythagorean);
        CLASS_ATTR_STYLE_LABEL(c,"boostpythagorean",0,"onoff","Boost Pythagorean Pitches");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"boostpythagorean",0,"1");
        // @description If set, boosts the importance of purely Pythagorean pitches.

        CLASS_ATTR_CHAR(c, "alwayswhitekeys", 0, t_jiwheel, always_display_whitekeys);
        CLASS_ATTR_STYLE_LABEL(c,"alwayswhitekeys",0,"onoff","Always Display White-Keys Pitches");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"alwayswhitekeys",0,"1");
        // @description If set, it always displays diatonic "white-keys" pitches with no accidentals (i.e. 'A' through 'G').

        CLASS_ATTR_CHAR(c, "intwheelpitchestofront", 0, t_jiwheel, always_show_coincidences_with_intwheel);
        CLASS_ATTR_STYLE_LABEL(c,"intwheelpitchestofront",0,"onoff","Move Pitches Coinciding with Integers Wheel to Front");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"intwheelpitchestofront",0,"1");
        // @description If set, it prioritize pitches coinciding with integer wheel numbers, moving them to the front.

    CLASS_STICKY_ATTR_CLEAR(c, "category");

    CLASS_STICKY_ATTR(c, "category", 0, "Show");

        CLASS_ATTR_CHAR(c, "showlegend", 0, t_jiwheel, show_legend);
        CLASS_ATTR_STYLE_LABEL(c,"showlegend",0,"enumindex","Show Legend");
        CLASS_ATTR_ENUMINDEX(c,"showlegend", 0, "Never Only For Selection Always");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showlegend",0,"2");
        // @description Chooses if and where the legend should be displayed:
        // - Never: no legend is ever shown. <br />
        // - Only For Selection: only selection legend is displayed. Selection legend is
        // located in the upper left corner of the notation object, and is shown whenever a single
        // notation item (e.g. a note) is selected. <br />
        // - Always: in addition to selection legend, also the mouseover legend is displayed.
        // Mouseover legend is located in the bottom right corner of the notation object, and is shown whenever the mouse
        // moves over the notation object. <br />

    
        CLASS_ATTR_CHAR(c, "showcircles", 0, t_jiwheel, show_circles);
        CLASS_ATTR_STYLE_LABEL(c,"showcircles",0,"onoff","Show Circles");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showcircles",0,"0");
        // @description Toggles the display of the circles

        CLASS_ATTR_CHAR(c, "showetwheel", 0, t_jiwheel, show_et_wheel);
        CLASS_ATTR_STYLE_LABEL(c,"showetwheel",0,"onoff","Show Equal-Temperament Wheel");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showetwheel",0,"1");
        // @description Toggles the display of the equal temperament wheel as a reference
    
        CLASS_ATTR_CHAR(c, "showintwheel", 0, t_jiwheel, show_integers_wheel);
        CLASS_ATTR_STYLE_LABEL(c,"showintwheel",0,"onoff","Show Integers Wheel");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showintwheel",0,"1");
        // @description Toggles the display of the integers wheel

    
        CLASS_ATTR_CHAR(c, "showticks", 0, t_jiwheel, show_ticks);
        CLASS_ATTR_STYLE_LABEL(c,"showticks",0,"onoff","Show Ticks");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showticks",0,"1");
        // @description Toggles the display of the ticks

        CLASS_ATTR_CHAR(c, "showfractions", 0, t_jiwheel, show_ratios);
        CLASS_ATTR_STYLE_LABEL(c,"showfractions",0,"onoff","Show Fractions");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"showfractions",0,"1");
        // @description Toggles the display of the fractions

    CLASS_STICKY_ATTR_CLEAR(c, "category");
    
    
    CLASS_STICKY_ATTR(c, "category", 0, "Appearance");

        CLASS_ATTR_CHAR(c, "extendtickstointwheel", 0, t_jiwheel, extend_ticks_to_integers);
        CLASS_ATTR_STYLE_LABEL(c,"extendtickstointwheel",0,"onoff","Extend Ticks to Integers Wheel");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"extendtickstointwheel",0,"1");
        // @description Toggles the extension of the pitch ticks to the integers wheel, when they line up.

        CLASS_ATTR_CHAR(c, "direction", 0, t_jiwheel, text_direction);
        CLASS_ATTR_STYLE_LABEL(c,"direction",0,"enumindex","Text And Accidentals Direction");
        CLASS_ATTR_ENUMINDEX(c,"direction", 0, "Upright Angular Radial");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"direction",0,"0");
        // @description Sets the direction for text and accidentals: upright (0), angular (1) or radial (2)

        CLASS_ATTR_CHAR(c, "autoturn", 0, t_jiwheel, rotate_for_legibility);
        CLASS_ATTR_STYLE_LABEL(c,"autoturn",0,"onoff","Rotate For Legibility");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"autoturn",0,"1");
        // @description Toggles the ability to rotate the text for legibility

        
        CLASS_ATTR_DOUBLE(c, "minfactor", 0, t_jiwheel, minfactor);
        CLASS_ATTR_STYLE_LABEL(c,"minfactor",0,"text","Minimum Reduction Factor");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"minfactor",0,"0.3");
        // @description Sets the minimum reduction factor for importance.

        CLASS_ATTR_CHAR(c, "colormode", 0, t_jiwheel, color_mode);
        CLASS_ATTR_STYLE_LABEL(c,"colormode",0,"enumindex","Color Mode");
        CLASS_ATTR_ENUMINDEX(c,"colormode", 0, "Plain Limit Max Exponent Pythagorean Chromatic Note Pythagorean Diatonic Note");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"colormode",0,"4");
        CLASS_ATTR_BASIC(c,"colormode",0);
        // @description Sets the color mode.

        CLASS_ATTR_DOUBLE(c, "ticklength", 0, t_jiwheel, tick_length);
        CLASS_ATTR_STYLE_LABEL(c,"ticklength",0,"text","Maximum Tick Length");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"ticklength",0,"40");
        // @description Sets the maximum tick length.

        CLASS_ATTR_DOUBLE(c, "etwheelsize", 0, t_jiwheel, et_wheel_size);
        CLASS_ATTR_STYLE_LABEL(c,"etwheelsize",0,"text","Equal-Temperament Wheel Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"etwheelsize",0,"30");
        // @description Sets the radial size of the equal-temperament wheel.

        CLASS_ATTR_DOUBLE(c, "intwheelsize", 0, t_jiwheel, int_wheel_size);
        CLASS_ATTR_STYLE_LABEL(c,"intwheelsize",0,"text","Integers Wheel Size");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"intwheelsize",0,"20");
        // @description Sets the radial size of the integers wheel.

        CLASS_ATTR_DOUBLE(c,"inset",0, t_jiwheel, inset);
        CLASS_ATTR_STYLE_LABEL(c,"inset",0,"text","Inset");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"inset",0,"20.");
        // @description Inset of the clock diagram with respect to the border, in pixels

        CLASS_ATTR_DOUBLE(c,"zoom",0, t_jiwheel, zoom);
        CLASS_ATTR_STYLE_LABEL(c,"zoom",0,"text","Zoom");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"zoom",0,"100.");
        // @description Zoom percentage.

        CLASS_ATTR_DOUBLE(c,"zoomangle",0, t_jiwheel, zoom_angle);
        CLASS_ATTR_STYLE_LABEL(c,"zoomangle",0,"text","Zoom Angle");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"zoomangle",0,"0");
        // @description Sets the zoomed angle (in radians).

        CLASS_ATTR_DOUBLE(c,"rotationangle",0, t_jiwheel, rotation_angle);
        CLASS_ATTR_STYLE_LABEL(c,"rotationangle",0,"text","Rotation Angle");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c,"rotationangle",0,"0");
        // @description Sets the rotation angle (in radians).

    {
        CLASS_ATTR_RGBA(c, "candycane1", 0, t_jiwheel, candycane1);
        CLASS_ATTR_STYLE_LABEL(c,"candycane1",0,"rgba","Candycane Color 1");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane1", 0, "0.77 0.11 0. 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane2", 0, t_jiwheel, candycane2);
        CLASS_ATTR_STYLE_LABEL(c,"candycane2",0,"rgba","Candycane Color 2");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane2", 0, "0.51 0.41 0.0 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane3", 0, t_jiwheel, candycane3);
        CLASS_ATTR_STYLE_LABEL(c,"candycane3",0,"rgba","Candycane Color 3");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane3", 0, "0.6 0.8 0. 1.0");
        // @description Sets one of the candycane colors

        CLASS_ATTR_RGBA(c, "candycane4", 0, t_jiwheel, candycane4);
        CLASS_ATTR_STYLE_LABEL(c,"candycane4",0,"rgba","Candycane Color 4");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane4", 0, "0.8 0.4 0.6 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane5", 0, t_jiwheel, candycane5);
        CLASS_ATTR_STYLE_LABEL(c,"candycane5",0,"rgba","Candycane Color 5");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane5", 0, "0.05 0.62 0.87 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane6", 0, t_jiwheel, candycane6);
        CLASS_ATTR_STYLE_LABEL(c,"candycane6",0,"rgba","Candycane Color 6");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane6", 0, "0. 0. 0.81 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane7", 0, t_jiwheel, candycane7);
        CLASS_ATTR_STYLE_LABEL(c,"candycane7",0,"rgba","Candycane Color 7");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane7", 0, "0. 0.518 0. 1.");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane8", 0, t_jiwheel, candycane8);
        CLASS_ATTR_STYLE_LABEL(c,"candycane8",0,"rgba","Candycane Color 8");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane8", 0, "0.764 0.419 0.07 1.0");
        // @description Sets one of the candycane colors
        
        CLASS_ATTR_RGBA(c, "candycane9", 0, t_jiwheel, candycane9);
        CLASS_ATTR_STYLE_LABEL(c,"candycane9",0,"rgba","Candycane Color 9");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane9", 0, "0.53 0. 0.59 1.0");
        // @description Sets one of the candycane colors

        CLASS_ATTR_RGBA(c, "candycane10", 0, t_jiwheel, candycane10);
        CLASS_ATTR_STYLE_LABEL(c,"candycane10",0,"rgba","Candycane Color 10");
        CLASS_ATTR_DEFAULT_SAVE_PAINT(c, "candycane10", 0, "0.84 0.69 0. 1.0");
        // @description Sets one of the candycane colors

    }

    CLASS_STICKY_ATTR_CLEAR(c, "category"); 

    s_jiwheel_class = c;
    class_register(CLASS_BOX, s_jiwheel_class);
    
    build_commas();

    dev_post("bach.jiwheel compiled %s %s", __DATE__, __TIME__);
    return;
}


void jiwheel_importance(t_jiwheel *x, t_symbol *s, long argc, t_atom *argv)
{
    const char *subs[] = {"num","den","min","max","limit","maxexp"};
    if (x->n_importance_lexpr)
        lexpr_free(x->n_importance_lexpr);
    x->n_importance_lexpr = lexpr_new(argc, argv, 6, subs, (t_object *) x);
    if (x->n_importance_lexpr) {
        x->rebuild = 1;
    } else {
        object_error((t_object *) x, "Bad expression!");
    }
}


t_max_err jiwheel_setattr_importance(t_jiwheel *x, void *attr, long ac, t_atom *av)
{
    if (ac && av) {
        jiwheel_importance(x, NULL, ac, av);
        x->importance_sym = atom_getsym(av);
    } else {
        object_error((t_object *)x, "Wrong importance function defined.");
    }
    
    x->rebuild = true;
    return MAX_ERR_NONE;
}


t_max_err jiwheel_notify(t_jiwheel *x, t_symbol *s, t_symbol *msg, void *sender, void *data)
{
    if (msg == gensym("attr_modified")) {
        t_symbol *attrname = (t_symbol *)object_method((t_object *)data, _sym_getname);
        if (attrname == gensym("limits") || attrname == gensym("primes") || attrname == gensym("formaloctave")) {
            x->rebuild = true;
            jiwheel_clear_selection(x);
        } else if (attrname == gensym("mode") || attrname == gensym("commas") || attrname == gensym("maxterm") || attrname == gensym("maxfifths") || attrname == gensym("density") || attrname == gensym("display") || attrname == gensym("basis") || attrname == gensym("alwayswhitekeys") || attrname == gensym("mapping")) {
            x->rebuild = true;
        } else if (attrname == gensym("zoom") || attrname == gensym("zoomangle")){
            if (x->auto_zooming)
                x->rebuild = true;
        }
    }
    
    jbox_redraw((t_jbox *)x);
    

    return jbox_notify((t_jbox *)x, s, msg, sender, data);
}

void jiwheel_assist(t_jiwheel *x, void *b, long m, long a, char *s){
    if (m == ASSIST_INLET) {
        if (a == 0) // @in 0 @type llll @digest Messages
            sprintf(s, "llll: Messages");
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_UI, a, &type);
        if (a == 0) // @out 0 @type llll @digest Dump Outlet
            sprintf(s, "llll (%s): Dump Outlet", type);
        else if (a == 1) // @out 1 @type llll @digest Notifications
            sprintf(s, "llll (%s): Notifications", type);
    }
}

void jiwheel_inletinfo(t_jiwheel *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void jiwheel_int(t_jiwheel *x, t_atom_long num)
{
    t_atom argv[1]; atom_setlong(argv, num);
    jiwheel_anything(x, _llllobj_sym_list, 1, argv);
}

void jiwheel_float(t_jiwheel *x, double num){
    t_atom argv[1]; atom_setfloat(argv, num);
    jiwheel_anything(x, _llllobj_sym_list, 1, argv);
}


void jiwheel_dump(t_jiwheel *x, t_symbol *s, long argc, t_atom *argv){
//    send_values(x);
    bool visible_only = false;
    if (argc >= 1 && atom_gettype(argv) == A_SYM && atom_getsym(argv) == _sym_visible) {
        visible_only = true;
    }
    
    
    systhread_mutex_lock(x->c_mutex);
    t_llll *ll = llll_get();
    for (long i = 0; i < x->num_pitches; i++) {
        if (visible_only && !x->curr_pitches[i].shown)
            continue;
        llll_appendllll(ll, jiwheel_get_wheelpitch_as_llll(x, &x->curr_pitches[i], false));
    }
    systhread_mutex_unlock(x->c_mutex);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 0, ll);
    llll_free(ll);
}


void jiwheel_anything(t_jiwheel *x, t_symbol *s, long argc, t_atom *argv)
{
/*
    long inlet = proxy_getinlet((t_object *) x);
    
    if (inlet == 2 && argc) {
        systhread_mutex_lock(x->c_mutex);
        x->modulo = atom_getlong(argv);
        if (x->modulo <= 0) x->modulo = 1;
        sort_points(x);
        systhread_mutex_unlock(x->c_mutex);
    } else if (s == _sym_clear) {
        x->num_points = 0;
    } else if (inlet == 1) {
        llllobj_parse_and_store((t_object *) x, LLLL_OBJ_UI, s, argc, argv, 1);
    } else if (inlet == 0) {
        t_llll *inllll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, s, argc, argv, LLLL_PARSE_CLONE);

        if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _sym_add) {
            t_llllelem *elem;
            systhread_mutex_lock(x->c_mutex);
            for (elem = inllll->l_head->l_next; elem && x->num_points < CONST_MAX_POINTS - 1; elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                    x->points[x->num_points] = hatom_getlong(&elem->l_hatom);
                    x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                    x->num_points++;
                } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                    t_llll *ptllll = hatom_getllll(&elem->l_hatom);
                    if (ptllll && ptllll->l_head && hatom_gettype(&ptllll->l_head->l_hatom) == H_LONG) {
                        x->points[x->num_points] = hatom_getlong(&ptllll->l_head->l_hatom);
                        if (hatom_gettype(&ptllll->l_tail->l_hatom) == H_LONG || hatom_gettype(&ptllll->l_tail->l_hatom) == H_DOUBLE || hatom_gettype(&ptllll->l_tail->l_hatom) == H_RAT)
                            x->vels[x->num_points] = hatom_getlong(&ptllll->l_tail->l_hatom);
                        else
                            x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                        x->num_points++;
                    }
                }
            }
            sort_points(x);
            systhread_mutex_unlock(x->c_mutex);
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _sym_delete) {
            t_llllelem *elem;
            systhread_mutex_lock(x->c_mutex);
            for (elem = inllll->l_head->l_next; elem; elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                    long what = hatom_getlong(&elem->l_hatom);
                    long j = 0;
                    while (j < x->num_points) {
                        if (x->points[j] == what) {
                            long k;
                            for (k = j; k < x->num_points - 1; k++) {
                                x->points[k] = x->points[k+1];
                                x->vels[k] = x->vels[k+1];
                            }
                            x->num_points--;
                            break;
                        } else
                            j++;
                    }
                }
            }
            sort_points(x);
            systhread_mutex_unlock(x->c_mutex);
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_transpose) {
            if (inllll->l_head->l_next)
                transpose_jiwheel(x, hatom_getlong(&inllll->l_head->l_next->l_hatom));
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_complement) {
            complement_jiwheel(x);
        } else if (inllll && inllll->l_head && hatom_gettype(&inllll->l_head->l_hatom) == H_SYM && hatom_getsym(&inllll->l_head->l_hatom) == _llllobj_sym_invert) {
            invert_jiwheel(x);
        } else if (inllll && inllll->l_head) {
            t_llllelem *elem, *elemv;
            t_llll *vels = NULL;

            vels = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_UI, 1, 1);

            systhread_mutex_lock(x->c_mutex);
            x->num_points = 0;
            for (elem = inllll->l_head, elemv = vels ? vels->l_head : NULL; elem && x->num_points < CONST_MAX_POINTS - 1; elem = elem->l_next, elemv = elemv ? elemv->l_next : NULL) {
                if (hatom_gettype(&elem->l_hatom) == H_LONG) {
                    x->points[x->num_points] = hatom_getlong(&elem->l_hatom);
                    if (elemv && (hatom_gettype(&elemv->l_hatom) == H_LONG || hatom_gettype(&elemv->l_hatom) == H_DOUBLE || hatom_gettype(&elemv->l_hatom) == H_RAT))
                        x->vels[x->num_points] = hatom_getlong(&elemv->l_hatom);
                    else
                        x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                    x->vels[x->num_points] = CLAMP(x->vels[x->num_points], CONST_MIN_VELOCITY, CONST_MAX_VELOCITY);
                    x->num_points++;
                } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                    t_llll *ptllll = hatom_getllll(&elem->l_hatom);
                    if (ptllll && ptllll->l_head && hatom_gettype(&ptllll->l_head->l_hatom) == H_LONG) {
                        x->points[x->num_points] = hatom_getlong(&ptllll->l_head->l_hatom);
                        if (hatom_gettype(&ptllll->l_tail->l_hatom) == H_LONG || hatom_gettype(&ptllll->l_tail->l_hatom) == H_DOUBLE || hatom_gettype(&ptllll->l_tail->l_hatom) == H_RAT)
                            x->vels[x->num_points] = hatom_getlong(&ptllll->l_tail->l_hatom);
                        else
                            x->vels[x->num_points] = CONST_DEFAULT_VELOCITY;
                        x->num_points++;
                    }
                }
            }
            sort_points(x);
            systhread_mutex_unlock(x->c_mutex);
            if (vels) llll_free(vels);
        }
        llll_free(inllll);
    }
    
    jbox_redraw((t_jbox *) x);
*/
}

t_jiwheel* jiwheel_new(t_symbol *s, long argc, t_atom *argv)
{
    t_jiwheel* x = NULL;
    t_max_err err = MAX_ERR_GENERIC;
    t_dictionary *d;
    t_object *textfield;
    long flags;

    if (!(d=object_dictionaryarg(argc,argv)))
        return NULL;

    x = (t_jiwheel*) object_alloc_debug(s_jiwheel_class);
    flags = 0 
            | JBOX_DRAWFIRSTIN 
            | JBOX_NODRAWBOX
            | JBOX_DRAWINLAST
    //        | JBOX_TRANSPARENT    
    //        | JBOX_NOGROW
    //        | JBOX_GROWY
            | JBOX_GROWBOTH
            | JBOX_HILITE
    //        | JBOX_BACKGROUND
            | JBOX_TEXTFIELD
    //        | JBOX_DRAWBACKGROUND
    //        | JBOX_DEFAULTNAMES
    //        | JBOX_MOUSEDRAGDELTA
            ;

    err = jbox_new(&x->j_box.l_box, flags, argc, argv); 
    x->j_box.l_box.b_firstin = (t_object*) x;

    x->n_proxy[2] = proxy_new_debug((t_object *) x, 2, &x->n_in);
    x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);

    x->n_importance_lexpr = NULL;
    x->show_focus = 1;
    x->j_has_focus = 0;
    x->formaloctave = 2;
    x->allowed_commas = llll_from_text_buf("auto");
    atom_setsym(x->allowed_limits, gensym("any"));
    atom_setsym(x->allowed_primes, gensym("any"));
    x->allowed_limits_count = x->allowed_primes_count = 1;
    x->sel1_ratio = x->sel2_ratio = x->mouseover_ratio = genrat(0, 1);
    x->curr_interval.ratio = genrat(0, 1);
    x->rotation_angle = x->rotation_angle_intwheel = 0;
    x->rotation_ratio_intwheel = long2rat(1);
    x->auto_move_intwheel = true;
    x->boost_et = true;
        
    x->curr_pitches = NULL;
    x->num_pitches = 0;
    
    // retrieve saved attribute values
    attr_dictionary_process(x, d);

    x->rebuild = true;
    
    textfield = jbox_get_textfield((t_object *) x); 
    if (textfield) {
        textfield_set_noactivate(textfield, 1);
        textfield_set_editonclick(textfield, 0);            // set it to 0 if you don't want user to edit it in lock mode
        textfield_set_textmargins(textfield, 3, 3, 3, 3);    // margin on each side
    }
    
    llllobj_jbox_setup((t_llllobj_jbox *) x, 1, "44");

    // mutex
    systhread_mutex_new_debug(&x->c_mutex, 0);

    jbox_ready(&x->j_box.l_box);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_UI);
    if (x)
        return x;
    else 
        error(BACH_CANT_INSTANTIATE);

    object_free_debug(x);
    return NULL;
}

void jiwheel_free(t_jiwheel *x){
    long i;

    if (x->curr_pitches)
        bach_freeptr(x->curr_pitches);
    if (x->n_importance_lexpr)
        lexpr_free(x->n_importance_lexpr);
    llll_free(x->allowed_commas);

    for (i = 1; i < 3; i++)
        object_free_debug(x->n_proxy[i]);
    jbox_free(&x->j_box.l_box);
    systhread_mutex_free_debug(x->c_mutex);
    llllobj_jbox_free((t_llllobj_jbox *) x);
}


void reverse_unicodeChar_array(unicodeChar *arr, long len)
{
    for (long i = 0; i < len / 2; i++) {
        unicodeChar temp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = temp;
    }
}

double ratio_to_cents(t_rational r)
{
    return 1200 * log2(rat2double(r));
}

long rational_to_limit(t_rational r)
{
    long lim = 2;
    t_llll *factors = llll_factorize_rational(r);
    for (t_llllelem *el = factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && ll->l_head->l_next && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                long l = hatom_getlong(&ll->l_head->l_hatom);
                lim = MAX(lim, l);
            }
        }
    }
    llll_free(factors);
    return lim;
}

void rational_to_wheelpitch(t_rational r, char base_diatonic_pitch, long formaloctave, bool frequential_mapping, t_wheelpitch *wp)
{
    long mp = 0;
    long numacc = 0;
    t_rational r_wo_octaves = r;
    t_llll *factors = llll_factorize_rational(r);
    
    remove_octaves(formaloctave, &r_wo_octaves);
    
    wp->type = BACH_PITCHWHEEL_PITCHTYPE_JI;
    wp->ratio = r;
    wp->ratio_without_octaves = r_wo_octaves;
    wp->cents = ratio_to_cents(r);

    // filling angle
    double val = rat2double(r);
    if (!frequential_mapping) { // linear pitch
        wp->angle = PIOVERTWO - TWOPI * log(val)/log(formaloctave);
    } else { // linear frequency
        wp->angle = PIOVERTWO - TWOPI * (val - 1) / (formaloctave - 1);
    }
    
    
    wp->num_pyth_accidentals = wp->num_accidentals = wp->pyth_accidentals_as_long = wp->num_accidentals_with_spaces = 0;
    wp->accidentals_overflow = 0;
    
    long lim = 1;
    for (t_llllelem *el = factors->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *ll = hatom_getllll(&el->l_hatom);
            if (ll->l_head && ll->l_head->l_next && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                long l = hatom_getlong(&ll->l_head->l_hatom);
                long p = hatom_getlong(&ll->l_head->l_next->l_hatom);
                lim = MAX(lim, l);
                if (l != formaloctave)
                    mp = MAX(mp, abs(p));
            }
        }
    }
    wp->limit = lim;
    wp->maxexp = mp;
    
    // finding pythagorean chromatic index
    long count = 0;
    long numArrows = 0;
    wp->pythagorean_index = 0;
    wp->purely_pythagorean = true;
    t_rational temp = r;
    
    if (formaloctave != 2) {
        count = 0;
        wp->purely_pythagorean = false;
        wp->pythagorean_index = 0;
        wp->pyth_accidentals[0] = 0;
        wp->accidentals[0] = 0;
        wp->accidentals_with_spaces[0] = 0;
        wp->num_accidentals = 0;
        wp->num_pyth_accidentals = 0;
        wp->num_accidentals_with_spaces = 0;
        wp->pyth_diatonic_step = -1;
        wp->pythagorean_index = -1;
        wp->accidentals_overflow = true;
        temp = long2rat(0); // TO DO
    }
    
    if (formaloctave == 2) { // otherwise how can we assign note names? gotta think about a general way.
        for (t_llllelem *el = factors->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                if (ll->l_head && ll->l_head->l_next && hatom_gettype(&ll->l_head->l_hatom) == H_LONG) {
                    long l = hatom_getlong(&ll->l_head->l_hatom);
                    long p = hatom_getlong(&ll->l_head->l_next->l_hatom);
                    bool p_positive = (p > 0 ? true: false);
                    long p_abs = abs(p);
                    if (l != 2 && l != 3) {
                        long li = num_to_prime_idx(l) - 2;
                        wp->purely_pythagorean = false;
                        if (li < 0 || li >= numcommas) {
                            wp->pythagorean_index = ATOM_LONG_MAX;
                            wp->accidentals_overflow = true;
                            break;
                        } else {
                            for (long pc = 0; pc < p_abs; pc++) {
                                if (p > 0)
                                    temp = temp * commas[li];
                                else
                                    temp = temp / commas[li];
                            }
                            switch (l) {
                                case 5:
                                    numArrows -= p;
                                    break;
                                case 7:
                                    while (p_abs >= 2 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58080 : 58081;
                                        p_abs -= 2;
                                    }
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58078 : 58079;
                                        p_abs -= 1;
                                    }
                                    break;
                                case 11:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58083 : 58082;
                                        p_abs--;
                                    }
                                    break;
                                case 13:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58084 : 58085;
                                        p_abs--;
                                    }
                                    break;
                                case 17:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58086 : 58087;
                                        p_abs--;
                                    }
                                    break;
                                case 19:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58089 : 58088;
                                        p_abs--;
                                    }
                                    break;
                                case 23:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58090 : 58091;
                                        p_abs--;
                                    }
                                    break;
                                case 29:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 61009 : 61008;
                                        p_abs--;
                                    }
                                    break;
                                case 31:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 58092 : 58093;
                                        p_abs--;
                                    }
                                    break;
                                case 37:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 61011 : 61010;
                                        p_abs--;
                                    }
                                    break;
                                case 41:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 61013 : 61012;
                                        p_abs--;
                                    }
                                    break;
                                case 43:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 61015 : 61014;
                                        p_abs--;
                                    }
                                    break;
                                case 47:
                                    while (p_abs > 0 && numacc < PITCHWHEEL_MAX_ACCIDENTALS) {
                                        wp->accidentals[numacc++] = p_positive ? 61017 : 61016;
                                        p_abs--;
                                    }
                                    break;
                                default:
                                    wp->accidentals_overflow = true;
                                    break;
                            }
                        }
                    }
                }
            }
        }
        
        while (temp.r_num % 3 == 0 && temp.r_num > 0) {
            temp.r_num /= 3;
            count++;
        }
        while (temp.r_den % 3 == 0 && temp.r_den > 0) {
            temp.r_den /= 3;
            count--;
        }
    }
    
    if (temp.r_num > 0 && temp.r_den > 0) {
        wp->pythagorean_index = count;
        wp->pyth_diatonic_step = positive_mod(count * 4, 7);
        
        long sharp_start = 6;
        if (base_diatonic_pitch == 'C' || base_diatonic_pitch == 'c') {
            sharp_start = 6;
        } else if (base_diatonic_pitch == 'D' || base_diatonic_pitch == 'd') {
            sharp_start = 4;
        } else if (base_diatonic_pitch == 'E' || base_diatonic_pitch == 'e') {
            sharp_start = 2;
        } else if (base_diatonic_pitch == 'F' || base_diatonic_pitch == 'f') {
            sharp_start = 7;
        } else if (base_diatonic_pitch == 'G' || base_diatonic_pitch == 'g') {
            sharp_start = 5;
        } else if (base_diatonic_pitch == 'A' || base_diatonic_pitch == 'a') {
            sharp_start = 3;
        } else if (base_diatonic_pitch == 'B' || base_diatonic_pitch == 'b') {
            sharp_start = 1;
        }
        long flat_start = sharp_start - 8;
        
        // Get pythagorean accidentals
        long temp_count = count;
        long pyth_accidentals_count = 0;
        long pyth_acc_long = 0;
        if (temp_count > 0) {
            while (temp_count >= sharp_start+7 && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += 2;
                wp->pyth_accidentals[pyth_accidentals_count++] = 57955; // SMUFL double sharp
                temp_count -= 14;
            }
            while (temp_count >= sharp_start && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += 1;
                wp->pyth_accidentals[pyth_accidentals_count++] = 57954; // SMUFL sharp
                temp_count -= 7;
            }
        } else if (temp_count < 0) {
            while (temp_count <= flat_start-7 && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += -2;
                wp->pyth_accidentals[pyth_accidentals_count++] = 57956; // SMUFL double flat
                temp_count += 14;
            }
            while (temp_count <= flat_start && pyth_accidentals_count < PITCHWHEEL_MAX_ACCIDENTALS) {
                pyth_acc_long += -1;
                wp->pyth_accidentals[pyth_accidentals_count++] = 57952; // SMUFL flat
                temp_count += 7;
            }
        }
        wp->pyth_accidentals[pyth_accidentals_count] = 0;
        wp->num_pyth_accidentals = pyth_accidentals_count;
        wp->pyth_accidentals_as_long = pyth_acc_long;

        long numarr = 0;
        long n_natural_arrows = 0; // number of arrows we need to represent as natural signs
        long n_modif_arrows = 0; // number of arrows we need to modify the first pythagorean accidental
        unicodeChar arrows[PITCHWHEEL_MAX_ACCIDENTALS+1];
        unicodeChar pyth_accidentals_temp[PITCHWHEEL_MAX_ACCIDENTALS+1];
        arrows[0] = 0;
        pyth_accidentals_temp[0] = 0;
        if (numArrows != 0) {
            if (pyth_accidentals_count == 0) {
                n_natural_arrows = numArrows;
                n_modif_arrows = 0;
            } else if (numArrows > 3) {
                n_natural_arrows = numArrows - 3;
                n_modif_arrows = 3;
            } else if (numArrows < -3) {
                n_natural_arrows = numArrows + 3;
                n_modif_arrows = -3;
            } else {
                n_natural_arrows = 0;
                n_modif_arrows = numArrows;
            }

            if (n_natural_arrows != 0) {
                if (n_natural_arrows > 0) {
                    while (n_natural_arrows >= 3 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58075;
                        n_natural_arrows -= 3;
                    }
                    while (n_natural_arrows >= 2 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58065;
                        n_natural_arrows -= 2;
                    }
                    while (n_natural_arrows >= 1 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58055;
                        n_natural_arrows -= 1;
                    }
                } else if (n_natural_arrows < 0) {
                    while (n_natural_arrows <= -3 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58070;
                        n_natural_arrows += 3;
                    }
                    while (n_natural_arrows <= -2 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58060;
                        n_natural_arrows += 2;
                    }
                    while (n_natural_arrows <= -1 && numarr < PITCHWHEEL_MAX_ACCIDENTALS) {
                        arrows[numarr++] = 58050;
                        n_natural_arrows += 1;
                    }
                }
            }
        }
        
        bach_copyptr(wp->pyth_accidentals, pyth_accidentals_temp, (PITCHWHEEL_MAX_ACCIDENTALS + 1) * sizeof(unicodeChar));
        if (n_modif_arrows != 0) {
            // modify pythagorean accidental!
            long cc = pyth_accidentals_count-1;
            switch (pyth_accidentals_temp[cc]) {
                case 57956:
                    pyth_accidentals_temp[cc] = 58048 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                    break;
                case 57952:
                    pyth_accidentals_temp[cc] = 58049 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                    break;
                case 57953:
                    pyth_accidentals_temp[cc] = 58050 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                    break;
                case 57954:
                    pyth_accidentals_temp[cc] = 58051 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                    break;
                case 57955:
                    pyth_accidentals_temp[cc] = 58052 + 10 * (abs(n_modif_arrows) - 1) + (n_modif_arrows > 0 ? 5 : 0);
                    break;
                default:
                    break;
            }
        }
        
        reverse_unicodeChar_array(wp->pyth_accidentals, pyth_accidentals_count);
        reverse_unicodeChar_array(wp->accidentals, numacc);

        // let's join higher limits accidentals, then arrows, then pythagorean accidentals
        unicodeChar accidentals_joined[3*PITCHWHEEL_MAX_ACCIDENTALS + 3]; // can't me more than this
        bach_copyptr(wp->accidentals, accidentals_joined, numacc * sizeof(unicodeChar));
        if (numarr > 0) {
            bach_copyptr(arrows, accidentals_joined + numacc, numarr * sizeof(unicodeChar));
            numacc += numarr;
        }
        if (pyth_accidentals_count > 0) {
            bach_copyptr(pyth_accidentals_temp, accidentals_joined + numacc, pyth_accidentals_count * sizeof(unicodeChar));
            numacc += pyth_accidentals_count;
        }
        
        if (numacc > 0) {
            // crop joined
            reverse_unicodeChar_array(accidentals_joined, numacc); // so that important ones are at left
            if (numacc > PITCHWHEEL_MAX_ACCIDENTALS) {
                wp->accidentals_overflow = true;
                numacc = PITCHWHEEL_MAX_ACCIDENTALS;
            }
            bach_copyptr(accidentals_joined, wp->accidentals, numacc * sizeof(unicodeChar));
            reverse_unicodeChar_array(wp->accidentals, numacc); // back to the correct order
            
            if (wp->accidentals_overflow) { // we requesteed a +2 of margin in the array, it should be ok
                wp->accidentals[numacc] = 59682; // dot dot dot!
                wp->accidentals[numacc+1] = 0;
                numacc += 1;
            }
            
            for (long i = 0; i < numacc; i++) {
                wp->accidentals_with_spaces[2*i] = wp->accidentals[i];
                wp->accidentals_with_spaces[2*i+1] = (i == numacc - 1) ? 0 : 32; // space
            }
            wp->num_accidentals_with_spaces = 2*numacc-1;
            wp->accidentals[numacc] = 0;
            wp->num_accidentals = numacc;
        } else {
            if (wp->accidentals_overflow) { // we requesteed a +2 of margin in the array, it should be ok
                wp->accidentals[0] = 59682; // dot dot dot!
                wp->accidentals_with_spaces[0] = 59682; // dot dot dot!
                wp->accidentals_with_spaces[1] = 0;
                wp->accidentals[1] = 0;
                wp->num_accidentals_with_spaces = wp->num_accidentals = 1;
                numacc = 1;
            } else {
                wp->accidentals_with_spaces[0] = 0;
                wp->accidentals[0] = 0;
                wp->num_accidentals_with_spaces = wp->num_accidentals = 0;
            }
        }

    } else {
        wp->pythagorean_index = wp->pyth_diatonic_step = ATOM_LONG_MAX;
    }
    

    wp->accidentals[numacc] = 0;
    llll_free(factors);
}



long get_default_maxterm(t_jiwheel *x, t_object *view)
{
    double radius, center_x, center_y;
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    double circle_length = TWOPI * radius;
    return round(x->density * sqrt(circle_length / 1.));
}

long get_default_fifthsext(t_jiwheel *x, t_object *view)
{
    double radius, center_x, center_y;
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    double circle_length = TWOPI * radius;
    return round(x->density * sqrt(circle_length/35.));
}

t_llll *get_default_commamix(t_jiwheel *x, t_object *view)
{
    double radius, center_x, center_y;
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    double circle_length = TWOPI * radius;
    t_llll *commamix = llll_get();
    
    // blank
    {
        t_llll *subll = repeat_long(0, numcommas);
        llll_appendllll(commamix, subll);
    }

    
    // single comma
//    post("----");
    for (long i = 0; i < numcommas; i++) {
        long max_single_comma = (long)round(x->density * sqrt(circle_length/500.) /pow(i+1, 1.));
//        if (max_single_comma > 0)
//            post("prime %ld: maximum %ld commas", commalimits[i], max_single_comma);
        for (long m = -max_single_comma; m <= max_single_comma; m++) {
            if (m == 0)
                continue;
            t_llll *subll = llll_get();
            for (long j = 0; j < numcommas; j++) {
                if (i == j) {
                    llll_appendlong(subll, m);
                } else {
                    llll_appendlong(subll, 0);
                }
            }
//            llll_print(subll);
            llll_appendllll(commamix, subll);
        }
    }
    
    // combinations
    
    
    //TODO
    return commamix;
}

void ensure_ratio_is_between_1_and_formaloctave(t_rational *r, long formaloctave)
{
    while (rat_long_cmp(*r, 1) < 0 && r->num() != 0 && r->den() != 0)
        *r = rat_long_prod(*r, formaloctave);
    while (rat_long_cmp(*r, formaloctave) > 0 && r->num() != 0 && r->den() != 0)
        *r = rat_long_div(*r, formaloctave);
}

void jiwheel_build_pitches(t_jiwheel *x, t_object *view)
{
    systhread_mutex_lock(x->c_mutex);
    t_llll *curr_pitches_ll = llll_get();
    
    // building mask for limits
    bool *limit_is_ok = (bool *)bach_newptrclear(LLLL_PRIMES_TABLE_SIZE * sizeof(bool));
    bool *prime_is_ok = (bool *)bach_newptrclear(LLLL_PRIMES_TABLE_SIZE * sizeof(bool));
    long only_limits_up_to_this_number_are_ok = -1, only_primes_up_to_this_number_are_ok = -1;

    if (x->allowed_primes_count == 1) {
        if (atom_gettype(x->allowed_primes) == A_LONG) {
            long i = num_to_prime_idx(atom_getlong(x->allowed_primes));
            if (i >= 0)
                prime_is_ok[i] = 1;
        } else {
            for (long i = 0; i < LLLL_PRIMES_TABLE_SIZE; i++)
                prime_is_ok[i] = 1;
            only_primes_up_to_this_number_are_ok = LLLL_PRIMES_TABLE_MAX;
        }
    } else if (x->allowed_primes_count >= 2) {
        if (atom_gettype(x->allowed_primes) == A_SYM && atom_getsym(x->allowed_primes) == gensym("<=")) {
            long n = atom_getlong(x->allowed_primes+1);
            long i = num_to_prime_idx(n);
            if (i >= 0) {
                for (long j = 0; j <= i; j++)
                    prime_is_ok[j] = 1;
            }
            only_primes_up_to_this_number_are_ok = n;
        } else if (atom_gettype(x->allowed_primes) == A_SYM && atom_getsym(x->allowed_primes) == gensym("<")) {
            long n = atom_getlong(x->allowed_primes+1);
            long i = num_to_prime_idx(n);
            if (i >= 0) {
                for (long j = 0; j < i; j++)
                    prime_is_ok[j] = 1;
            }
            only_primes_up_to_this_number_are_ok = n-1;
        } else {
            for (long i = 0; i < x->allowed_primes_count; i++) {
                if (atom_gettype(x->allowed_primes+i) == A_LONG) {
                    long j = num_to_prime_idx(atom_getlong(x->allowed_primes+i));
                    if (j >= 0)
                        prime_is_ok[j] = 1;
                }
            }
        }
    } else {
        object_warn((t_object *)x, "No primes defined. Defaulting to 'any'.");
        for (long i = 0; i < LLLL_PRIMES_TABLE_SIZE; i++)
            prime_is_ok[i] = 1;
        only_primes_up_to_this_number_are_ok = LLLL_PRIMES_TABLE_MAX;
    }
    
    if (x->allowed_limits_count == 1) {
        if (atom_gettype(x->allowed_limits) == A_LONG) {
            long i = num_to_prime_idx(atom_getlong(x->allowed_limits));
            if (i >= 0)
                limit_is_ok[i] = 1;
        } else {
            for (long i = 0; i < LLLL_PRIMES_TABLE_SIZE; i++)
                limit_is_ok[i] = 1;
            only_limits_up_to_this_number_are_ok = LLLL_PRIMES_TABLE_MAX;
        }
    } else if (x->allowed_limits_count >= 2) {
        if (atom_gettype(x->allowed_limits) == A_SYM && atom_getsym(x->allowed_limits) == gensym("<=")) {
            long n = atom_getlong(x->allowed_limits+1);
            long i = num_to_prime_idx(n);
            if (i >= 0) {
                for (long j = 0; j <= i; j++)
                    limit_is_ok[j] = 1;
            }
            only_limits_up_to_this_number_are_ok = n;
        } else if (atom_gettype(x->allowed_limits) == A_SYM && atom_getsym(x->allowed_limits) == gensym("<")) {
            long n = atom_getlong(x->allowed_limits+1);
            long i = num_to_prime_idx(n);
            if (i >= 0) {
                for (long j = 0; j < i; j++)
                    limit_is_ok[j] = 1;
            }
            only_limits_up_to_this_number_are_ok = n-1;
        } else {
            for (long i = 0; i < x->allowed_limits_count; i++) {
                if (atom_gettype(x->allowed_limits+i) == A_LONG) {
                    long j = num_to_prime_idx(atom_getlong(x->allowed_limits+i));
                    if (j >= 0)
                        limit_is_ok[j] = 1;
                }
            }
        }
    } else {
        object_warn((t_object *)x, "No limits defined. Defaulting to 'any'.");
        for (long i = 0; i < LLLL_PRIMES_TABLE_SIZE; i++)
            limit_is_ok[i] = 1;
        only_limits_up_to_this_number_are_ok = LLLL_PRIMES_TABLE_MAX;
    }
    
    // always display selected ratios
    if (x->sel1_ratio.r_num != 0)
        llll_appendrat(curr_pitches_ll, x->sel1_ratio);
    if (x->sel2_ratio.r_num != 0)
        llll_appendrat(curr_pitches_ll, x->sel2_ratio);
    if (x->mouseover_ratio.r_num != 0)
        llll_appendrat(curr_pitches_ll, x->mouseover_ratio);
    
    // formal octave must always be admitted:
    prime_is_ok[x->formaloctave] = true;

    if (x->always_display_whitekeys && x->formaloctave == 2 && limit_is_ok[1] && prime_is_ok[0] && prime_is_ok[1]) {
        // adding Pythagorean whitekeys
        char base_diatonic_pitch = x->base_diatonic_pitch ? x->base_diatonic_pitch->s_name[0] : 'A';
        long start = 0;
        if (base_diatonic_pitch == 'C' || base_diatonic_pitch == 'c') {
            start = -1;
        } else if (base_diatonic_pitch == 'D' || base_diatonic_pitch == 'd') {
            start = -3;
        } else if (base_diatonic_pitch == 'E' || base_diatonic_pitch == 'e') {
            start = -5;
        } else if (base_diatonic_pitch == 'F' || base_diatonic_pitch == 'f') {
            start = 0;
        } else if (base_diatonic_pitch == 'G' || base_diatonic_pitch == 'g') {
            start = -2;
        } else if (base_diatonic_pitch == 'A' || base_diatonic_pitch == 'a') {
            start = -4;
        } else if (base_diatonic_pitch == 'B' || base_diatonic_pitch == 'b') {
            start = -6;
        }
        for (long i = start; i < start + 7; i++) {
            t_rational r = rat_long_pow(genrat(3, 2), i);
            ensure_ratio_is_between_1_and_formaloctave(&r, x->formaloctave);
            llll_appendrat(curr_pitches_ll, r);
        }
    }
    
    if (x->mode == BACH_PITCHWHEEL_MODE_MAXTERM) {
        x->auto_zooming = (atom_gettype(&x->maxterm) == A_LONG ? 0 : 1);
        long ji_maxterm = x->auto_zooming ? (long)round(sqrt(x->density) * get_default_maxterm(x, view)) : atom_getlong(&x->maxterm);
        for (long n = 1; n <= ji_maxterm; n++) {
            for (long m = n; m <= ji_maxterm; m++) {
                t_rational r = genrat(m, n);
                if (rat_long_cmp(r, x->formaloctave) < 0) {
                    if (only_limits_up_to_this_number_are_ok == LLLL_PRIMES_TABLE_MAX && only_primes_up_to_this_number_are_ok == LLLL_PRIMES_TABLE_MAX) {
                        llll_appendrat(curr_pitches_ll, r);
                    } else {
                        long limit = rational_to_limit(r);
                        if ((only_limits_up_to_this_number_are_ok == LLLL_PRIMES_TABLE_MAX || (only_limits_up_to_this_number_are_ok > 0 && limit <= only_limits_up_to_this_number_are_ok)) &&
                            (only_primes_up_to_this_number_are_ok == LLLL_PRIMES_TABLE_MAX || (only_primes_up_to_this_number_are_ok > 0 && limit <= only_primes_up_to_this_number_are_ok))) {
                            llll_appendrat(curr_pitches_ll, r);
                        } else {
                            bool must_append = true;
                            // must check limit and every prime
                            long idx = num_to_prime_idx(limit);
                            if (idx < 0 || !limit_is_ok[idx]) {
                                must_append = false;
                            }
                            t_llll *factors = llll_factorize_rational(r);
                            for (t_llllelem *el = factors->l_head; el; el = el->l_next) {
                                long f = hatom_getlong(&hatom_getllll(&el->l_hatom)->l_head->l_hatom);
                                long fidx = num_to_prime_idx(f);
                                if (fidx < 0 || !prime_is_ok[fidx]) {
                                    must_append = false;
                                    break;
                                }
                            }
                            if (must_append)
                                llll_appendrat(curr_pitches_ll, r);
                        }
                    }
                }
            }
        }
        
    } else if (x->mode == BACH_PITCHWHEEL_MODE_JILIMITS) {
        t_llll *commamix = NULL;
        long fifthsext = 0;
        x->auto_zooming = false;
        
        if (x->allowed_commas && x->allowed_commas->l_size == 1 && hatom_gettype(&x->allowed_commas->l_head->l_hatom) == H_SYM) {
            x->auto_zooming = true;
            commamix = get_default_commamix(x, view);
        } else {
            commamix = llll_clone(x->allowed_commas);
        }
        if (atom_gettype(&x->maxfifths) == A_LONG) {
            fifthsext = atom_getlong(&x->maxfifths);
        } else {
            x->auto_zooming = true;
            fifthsext = get_default_fifthsext(x, view);
        }
        
        if (limit_is_ok[1] == false)
            fifthsext = 0;
        
        for (long n = -fifthsext; n <= fifthsext; n++) {
            t_rational baseratio = rat_long_pow(genrat(3, 2), n);
            if (commamix) {
                for (t_llllelem *el = commamix->l_head; el; el = el->l_next) {
                    t_rational ratio = baseratio;
                    long c = 0;
                    bool accept = true;
                    for (t_llllelem *c_el = hatom_getllll(&el->l_hatom)->l_head; c_el && c < numcommas; c_el = c_el->l_next, c++) {
                        long e = hatom_getlong(&c_el->l_hatom);
                        if (e != 0) {
                            if (limit_is_ok[c+2] == false || prime_is_ok[c+2] == false) {
                                accept = false;
                                break;
                            }
                            ratio = rat_rat_prod(ratio, rat_long_pow(commas[c], e));
                        }
                    }
                    if (accept) {
                        ensure_ratio_is_between_1_and_formaloctave(&ratio, x->formaloctave);
                        if (ratio.num() != 0 && ratio.den() != 0) {
                            llll_appendrat(curr_pitches_ll, ratio);
                        }
                    }
                }
            }
        }
        
        llll_free(commamix);
    }
    curr_pitches_ll = llll_thin_simple(curr_pitches_ll, false);
    llll_mergesort_inplace(&curr_pitches_ll, llll_leq_elem, NULL);
    
    if (x->curr_pitches)
        bach_freeptr(x->curr_pitches);
    long numpitches = curr_pitches_ll->l_size;
    x->curr_pitches = (t_wheelpitch *)bach_newptr(MAX(numpitches, 1) * sizeof(t_wheelpitch));
    long i = 0;
    double max_importance = 0;
    for (t_llllelem *el = curr_pitches_ll->l_head; el; el = el->l_next, i++) {
        rational_to_wheelpitch(hatom_getrational(&el->l_hatom), x->base_diatonic_pitch ? x->base_diatonic_pitch->s_name[0] : 'A', x->formaloctave, x->display_mapping > 0, &x->curr_pitches[i]);
        
        // filling index
        x->curr_pitches[i].index = i;

        
        // filling importance
        if (!x->n_importance_lexpr) {
            x->curr_pitches[i].importance = 1;
        } else {
            t_hatom vars[LEXPR_MAX_VARS];
            t_hatom *res;
            hatom_setlong(vars, x->curr_pitches[i].ratio.num());
            hatom_setlong(vars+1, x->curr_pitches[i].ratio.den());
            hatom_setlong(vars+2, MIN(x->curr_pitches[i].ratio.num(), x->curr_pitches[i].ratio.den()));
            hatom_setlong(vars+3, MAX(x->curr_pitches[i].ratio.num(), x->curr_pitches[i].ratio.den()));
            hatom_setlong(vars+4, x->curr_pitches[i].limit);
            hatom_setlong(vars+5, x->curr_pitches[i].maxexp);
            res = lexpr_eval(x->n_importance_lexpr, vars);
            x->curr_pitches[i].importance = hatom_getdouble(res);
            //        = pow(x->curr_pitches[i].limit, 0.4);
            bach_freeptr(res);
        }
        max_importance = MAX(max_importance, x->curr_pitches[i].importance);
    }
    
    if (x->boost_whitekeys > 0 || x->boost_pythagorean > 0 || x->boost_et > 0) {
        for (long i = 0; i < numpitches; i++) {
            if ((x->boost_whitekeys && x->curr_pitches[i].purely_pythagorean && x->curr_pitches[i].num_accidentals == 0) ||
                (x->boost_pythagorean && x->curr_pitches[i].purely_pythagorean) ||
                (x->boost_et && x->curr_pitches[i].type == BACH_PITCHWHEEL_PITCHTYPE_ET)) {
                x->curr_pitches[i].importance = (max_importance == 0 ? 1 : max_importance * 1.2); // 1.2 is the boost factor (should we expose this?)
            }
        }
    }
    
    x->num_pitches = numpitches;
    
    // normalize importances
    if (max_importance > 0) {
        for (long i = 0; i < numpitches; i++) {
            x->curr_pitches[i].importance /= max_importance;
        }
    }
    
    llll_free(curr_pitches_ll);
    systhread_mutex_unlock(x->c_mutex);
    bach_freeptr(limit_is_ok);
    bach_freeptr(prime_is_ok);
}


void jiwheel_paint_radial_line(t_jiwheel *x, t_jgraphics *g, t_jrgba color, double center_x, double center_y, double theta, double r_start, double r_end, double linewidth, double *s, double *c, char arrow, bool dotted, double dash_length)
{
    double sinus = sin(theta);
    double cosinus = cos(theta);
    double x1 = center_x + (r_start) * cosinus;
    double y1 = center_y - (r_start) * sinus;
    double x2 = center_x + (r_end) * cosinus;
    double y2 = center_y - (r_end) * sinus;
    
    if (s) *s = sinus;
    if (c) *c = cosinus;
    
    if (arrow > 0)
        paint_arrow(g, color, x1, y1, x2, y2, linewidth, 8, 8);
    else if (arrow < 0)
        paint_arrow(g, color, x2, y2, x1, y1, linewidth, 8, 8);
    else if (dotted)
        paint_dashed_line(g, color, x1, y1, x2, y2, linewidth, dash_length);
    else
        paint_line(g, color, x1, y1, x2, y2, linewidth);
    
}

bool wheelpitch_is_sel_or_mouseover(t_jiwheel *x, t_wheelpitch *p)
{
    if (p->ratio == x->sel1_ratio || p->ratio == x->sel2_ratio || p->ratio == x->mouseover_ratio)
        return 1;
    return 0;
}

long sort_by_importance_modif(void *ptr, t_llllelem *a, t_llllelem *b)
{
    t_jiwheel *x = (t_jiwheel *)ptr;
    if (a && b) {
        t_wheelpitch *a_p = (t_wheelpitch *)hatom_getobj(&a->l_hatom);
        t_wheelpitch *b_p = (t_wheelpitch *)hatom_getobj(&b->l_hatom);

        if (wheelpitch_is_sel_or_mouseover(x, a_p)) {
            if (wheelpitch_is_sel_or_mouseover(x, b_p)) {
                return a_p->importance >= b_p->importance;
            } else {
                return 1; // always put selected pitches in front
            }
        } else if (wheelpitch_is_sel_or_mouseover(x, b_p)) {
            return 0; // always put selected pitches in front
        }
        
        if (x->always_show_coincidences_with_intwheel) {
            if (a_p->coincides_with_intwheel && !b_p->coincides_with_intwheel && b_p->num_accidentals > 0)
                return 1;
            
            if (b_p->coincides_with_intwheel && !a_p->coincides_with_intwheel && a_p->num_accidentals > 0)
                return 0;
        }

        return a_p->importance >= b_p->importance;
    }
    return 0;
}

void jiwheel_get_label_specs(t_jiwheel *x, t_wheelpitch *p, t_pt center, double radius, double cos_alpha, double sin_alpha, char **number_txt, t_jfont **font, t_pt *number_center, t_pt *number_middle_left, t_rect *number_rect, double *fontsize, bool *acc_displayed, t_rect *actual_rect)
{
    double ticklength = x->tick_length * p->curr_normalized_importance;
    t_hatom h;
    double width, height;
    double accfontsize = 0;
    
    *acc_displayed = false;
    
    switch (x->display_what) {
        case BACH_PITCHWHEEL_DISPLAY_RATIO:
            *fontsize = p->curr_normalized_importance * jbox_get_fontsize((t_object *) x);
            *font = jfont_create_debug(jbox_get_fontname((t_object *) x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), *fontsize);
            hatom_setrational(&h, p->ratio);
            hatom_to_text_buf(&h, number_txt);
            break;

        case BACH_PITCHWHEEL_DISPLAY_ACCIDENTALS:
        {
            long len_utf = 0;
            char base_diatonic_pitch = (x->base_diatonic_pitch ? x->base_diatonic_pitch->s_name[0] : 'A');
            if (!p->accidentals_overflow && p->purely_pythagorean && p->num_accidentals == 0) { // pure diatonic note
                *fontsize = jbox_get_fontsize((t_object *) x);
                *font = jfont_create_debug(jbox_get_fontname((t_object *) x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), *fontsize);
                *number_txt = (char *)bach_newptr(2 * sizeof(char));
                (*number_txt)[0] = base_diatonic_pitch + p->pyth_diatonic_step;
                if ((*number_txt)[0] > 'G')
                    (*number_txt)[0] -= 7;
                (*number_txt)[1] = 0;
            } else {
                accfontsize = p->curr_normalized_importance * object_attr_getfloat((t_object *)x, gensym("accidentalsfontsize"));
                *font = jfont_create_debug(object_attr_getsym((t_object *)x, gensym("accidentalsfont"))->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, accfontsize);
                *number_txt = charset_unicodetoutf8_debug(p->accidentals_with_spaces, p->num_accidentals_with_spaces, &len_utf);
                *fontsize = accfontsize;
                *acc_displayed = true;
            }
        }

            break;

        default:
            // TO DO!
            break;
    }

    jfont_text_measure(*font, *number_txt, &width, &height);

    double rd = radius;
    
    if (accfontsize > 0 && (x->text_direction == BACH_PITCHWHEEL_TEXT_ANGULAR))
        rd -= 1.7 * accfontsize; // accidentals are too far
    
    number_center->x = center.x + rd * cos_alpha;
    number_center->y = center.y - rd * sin_alpha;
    
    if (accfontsize > 0 && (x->text_direction == BACH_PITCHWHEEL_TEXT_UPRIGHT))
        number_center->y += 1.7 * accfontsize * sin_alpha; // accidentals are too far


    double pad = 4;

    *number_middle_left = *number_center;
    number_middle_left->x += cos_alpha * (ticklength + pad);
    number_middle_left->y -= sin_alpha * (ticklength + pad);

    number_center->x += cos_alpha * (width/2. + ticklength + pad);
    number_center->y -= sin_alpha * (height/2. + ticklength + pad);
    
    number_rect->x = number_center->x - width/2.;
    number_rect->y = number_center->y - height/2.;
    number_rect->width = width;
    number_rect->height = height;

    if (actual_rect) {
        *actual_rect = *number_rect;
        if (*acc_displayed) {
            actual_rect->y += actual_rect->height * 0.35;
            actual_rect->height *= 0.3;
            actual_rect->x -= accfontsize * 0.1;
            actual_rect->width += accfontsize * 0.2;
            
            if (x->text_direction == BACH_PITCHWHEEL_TEXT_RADIAL) {
                actual_rect->x -= accfontsize * 4;
            }
        }
    }

}


double jiwheel_paint_legend(t_jiwheel *x, t_jgraphics *g, t_rect rect, t_wheelpitch *p, double y_start, const char *pitchLabel, bool interval)
{
    t_jfont *legendfont = jfont_create_debug(x->legend_fontname->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->legend_fontsize);
    t_jfont *legendfontsuperscript = jfont_create_debug(x->legend_fontname->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, x->legend_fontsize * 0.7);
    double legendacc_fontsize = x->legend_fontsize * 1.7;
    t_jfont *legendfont_accidentals = jfont_create_debug(x->accidentals_font->s_name, JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_NORMAL, legendacc_fontsize);
    char buf[1000];
    double width, height;
    double inset = PITCHWHEEL_LEGEND_INSET;
    
    // We write right-to left
    double writable_width = rect.width - 2 * inset;
    double full_width = rect.width - 2 * inset;
    double writable_height = rect.height - y_start - inset;
    double accshift = -legendacc_fontsize*1.7;
    
    double v = y_start;
    char base_diatonic_pitch = x->base_diatonic_pitch ? x->base_diatonic_pitch->s_name[0] : 'A';
    char ch = p->pyth_diatonic_step < 0 || p->pyth_diatonic_step == ATOM_LONG_MAX ? '?' : base_diatonic_pitch + p->pyth_diatonic_step;

    snprintf_zero(buf, 1000, "Test");
    jfont_text_measure(legendfont, buf, &width, &height);

    double interlinea = height * 1.2;

    // background
    paint_filledrectangle(g, change_alpha(x->j_bgcolor, 0.8), rect.width * 0.8, y_start, rect.width * 0.2, interlinea * 7);
    
    if (interval) {
        long numoctaves = 0;
        char octavetxt[100];
        const char *intervalname = jiwheel_ratio_to_common_interval_name(p->ratio, &numoctaves);
        
        write_text(g, legendfont, x->legend_color, "Interval:", inset, v, writable_width, rect.height - inset, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);

        if (strlen(intervalname) > 0) {
            v += interlinea;
            snprintf_zero(octavetxt, 100, " %s%doct.", numoctaves >= 0 ? "+" : "−", abs(numoctaves));
            snprintf_zero(buf, 1000, "%s%s%s", strlen(intervalname) > 0 ? " " : "", intervalname, (numoctaves == 0 || strlen(intervalname) == 0) ? "" : octavetxt);
            jfont_text_measure(legendfont, buf, &width, &height);
            write_text(g, legendfont, x->legend_color, buf, inset, v, writable_width, rect.height - inset, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
        }
    } else {
        // accidentals
        long len_utf = 0;
        char *acc_txt = charset_unicodetoutf8_debug(p->accidentals_with_spaces, p->num_accidentals_with_spaces, &len_utf);
        jfont_text_measure(legendfont_accidentals, acc_txt, &width, &height);
        write_text(g, legendfont_accidentals, x->legend_color, acc_txt, inset, y_start + accshift, writable_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
        bach_freeptr(acc_txt);
        writable_width -= width;
        
        // left part
        if (ch != '?' && ch > 'G')
            ch -= 7;
        snprintf_zero(buf, 1000, "%s: %c", pitchLabel, ch);
        jfont_text_measure(legendfont, buf, &width, &height);
        write_text(g, legendfont, x->legend_color, buf, inset, v, writable_width-2, rect.height - inset, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
    }

    v += interlinea;

/*            double difffromref = ratio_to_cents(p->ratio / rbase);
    snprintf_zero(buf, 1000, "Accidental: %s%ld cents", difffromref >= 0 ? "+" : "−", (long)round(abs(difffromref)));
    jfont_text_measure(legendfont, buf, &width, &height);
    write_text(g, legendfont, x->legend_color, buf, inset, v, full_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);

    v += interlinea;
*/
    // Uncomment when equally tempered notes will be there as well
/*            snprintf_zero(buf, 1000, "Type: %s", p->type == BACH_PITCHWHEEL_PITCHTYPE_JI ? "justly tuned" : "equally tempered");
    write_text(g, legendfont, x->legend_color, buf, inset, v, full_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
    writable_height -= interlinea;
    v += interlinea;
*/
    
    if (p->type == BACH_PITCHWHEEL_PITCHTYPE_JI) {
        snprintf_zero(buf, 1000, "Ratio: %ld/%ld", p->ratio.num(), p->ratio.den());
        write_text(g, legendfont, x->legend_color, buf, inset, v, full_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
        writable_height -= interlinea;

    }
    
    snprintf_zero(buf, 1000, "Cents: %.2f", p->cents, p->limit);
    write_text(g, legendfont, x->legend_color, buf, inset, v += interlinea, full_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
    writable_height -= interlinea;
    
    if (p->type == BACH_PITCHWHEEL_PITCHTYPE_JI) {
        t_rational r = p->ratio;
        remove_octaves(x, &r);
        snprintf_zero(buf, 1000, "Ratio up to %soctaves: %ld/%ld", x->formaloctave == 2 ? "" : "formal ", r.num(), r.den());
        write_text(g, legendfont, x->legend_color, buf, inset, v += interlinea, full_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
        writable_height -= interlinea;
    }

    if (p->type == BACH_PITCHWHEEL_PITCHTYPE_JI) {
        snprintf_zero(buf, 1000, "Prime limit: %ld", p->limit);
        write_text(g, legendfont, x->legend_color, buf, inset, v += interlinea, full_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
        writable_height -= interlinea;

        t_llll *decomp = llll_factorize_rational(p->ratio);
        char factor_buf[100];
        double w, h;
        v += interlinea;
        writable_width = full_width;
        for (t_llllelem *el = decomp->l_tail; el; el = el->l_prev) { // very safe...
            t_llll *ll = hatom_getllll(&el->l_hatom);
            long b = hatom_getlong(&ll->l_head->l_hatom);
            long e = hatom_getlong(&ll->l_head->l_next->l_hatom);
            snprintf_zero(factor_buf, 100, "%s%ld", e < 0 ? "−" : "", abs(e));
            jfont_text_measure(legendfontsuperscript, factor_buf, &w, &h);
            write_text(g, legendfontsuperscript, x->legend_color, factor_buf, inset, v, writable_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
            writable_width -= w;
            snprintf_zero(factor_buf, 100, "%s%ld", el->l_prev ? "·" : "", b);
            jfont_text_measure(legendfont, factor_buf, &w, &h);
            write_text(g, legendfont, x->legend_color, factor_buf, inset, v, writable_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
            writable_width -= w;
        }
        snprintf_zero(buf, 1000, "Factors: %s", decomp->l_size == 0 ? "(empty)" : "");
        write_text(g, legendfont, x->legend_color, buf, inset, v, writable_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
        writable_height -= interlinea;
        v += interlinea;

        if (!interval) {
            double c = p->cents;
            long c_l = (long)round(c/100.);
            double etdiff = c - c_l * 100.;
            char *etbuf = NULL;
            char temp[2];
            temp[0] = x->base_diatonic_pitch ? toupper(x->base_diatonic_pitch->s_name[0]) : 'A';
            temp[1] = 0;
            long screen_mc;
            t_rational screen_acc;
            notename2midicents(5, NULL, temp, &screen_mc, &screen_acc);
            ezmidicents2notename(5, screen_mc + c_l * 100, k_NOTE_NAMES_ANGLOSAXON, 0, &etbuf, 4, true);
            
            writable_width = full_width;
            snprintf_zero(buf, 1000, " %s%ld cents", etdiff >= 0 ? "+" : "−", (long)round(abs(etdiff)));
            jfont_text_measure(legendfont, buf, &width, &height);
            write_text(g, legendfont, x->legend_color, buf, inset, v, writable_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
            writable_width -= width;
            
            long l = strlen(etbuf);
            if (l > 0) {
                if (l == 1) {
                    unicodeChar unicode_accbuf[2];
                    long outlen;
                    unicode_accbuf[0] = 58098; // natural
                    unicode_accbuf[1] = 0;
                    char *acc_txt = charset_unicodetoutf8_debug(unicode_accbuf, 1, &outlen);
                    jfont_text_measure(legendfont_accidentals, acc_txt, &width, &height);
                    write_text(g, legendfont_accidentals, x->legend_color, acc_txt, inset, v + accshift, writable_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
                    writable_width -= width;
                    bach_freeptr(acc_txt);
                } else {
                    while (l > 1) {
                        long outlen;
                        unicodeChar unicode_accbuf[2];
                        switch (etbuf[l-1]) {
                            case 'x':
                                unicode_accbuf[0] = 58100;
                                break;
                            case '#':
                                unicode_accbuf[0] = 58099;
                                break;
                            case 'n':
                                unicode_accbuf[0] = 58098;
                                break;
                            case 'b':
                                unicode_accbuf[0] = 58097;
                                break;
                            case 'B':
                                unicode_accbuf[0] = 58096;
                                break;
                            default:
                                unicode_accbuf[0] = 0;
                                break;
                        }
                        unicode_accbuf[1] = 0;
                        char *acc_txt = charset_unicodetoutf8_debug(unicode_accbuf, 1, &outlen);
                        jfont_text_measure(legendfont_accidentals, acc_txt, &width, &height);
                        write_text(g, legendfont_accidentals, x->legend_color, acc_txt, inset, v + accshift, writable_width, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
                        writable_width -= width;
                        bach_freeptr(acc_txt);
                        etbuf[l-1] = 0;
                        l--;
                    }
                    etbuf[1] = 0;
                }
                
                snprintf_zero(buf, 1000, "Deviation: %s", etbuf);
                write_text(g, legendfont, x->legend_color, buf, inset, v, writable_width - 2, writable_height, JGRAPHICS_TEXT_JUSTIFICATION_RIGHT|JGRAPHICS_TEXT_JUSTIFICATION_TOP, true, true);
                writable_height -= height;
                
                v += interlinea;
            }
            bach_freeptr(etbuf);
        }
        

    }

    
    jfont_destroy_debug(legendfont);
    jfont_destroy_debug(legendfontsuperscript);
    jfont_destroy_debug(legendfont_accidentals);
    
    return v;
}

void jiwheel_paint_legend_interval(t_jiwheel *x, t_jgraphics *g, t_rect rect, t_wheelpitch *p1, t_wheelpitch *p2)
{
    double v = PITCHWHEEL_LEGEND_INSET;
    double linelen = (rect.width - rect.height) * 0.5 * 0.6;
    if (linelen < 0)
        linelen = 20;
    
    v = jiwheel_paint_legend(x, g, rect, p1, v, "Starting Pitch", false);

    v += 10;
    paint_line(g, x->legend_color, rect.width * 0.8, v, rect.width, v, 0.5);
    v += 10;
    
    v = jiwheel_paint_legend(x, g, rect, p2, v, "Ending Pitch", false);

    v += 10;
    paint_line(g, x->legend_color, rect.width * 0.8, v, rect.width, v, 0.5);

    if (x->curr_interval.ratio.num() > 0) {
        v += 10;
        v = jiwheel_paint_legend(x, g, rect, &x->curr_interval, v, "Interval", true);
    }
}

double jiwheel_integer_to_theta(t_jiwheel *x, long i)
{
    double theta = 0;
    if (x->display_mapping == 0) { // linear pitch
        theta = (fmod(log(i)/log(x->formaloctave), 1.)) * TWOPI - x->rotation_angle + x->rotation_angle_intwheel;
    } else { // linear frequency
        theta = TWOPI * ((i * 1. / (ipow(x->formaloctave, floor(log(i)/log(x->formaloctave))))) / (x->formaloctave - 1)) - x->rotation_angle + x->rotation_angle_intwheel;
    }
    theta = PIOVERTWO - theta;
    theta = positive_fmod(theta, TWOPI);
    return theta;
}

long jiwheel_ratio_to_index(t_jiwheel *x, t_rational r)
{
    for (long i = 0; i < x->num_pitches; i++) {
        if (x->curr_pitches[i].ratio == r)
            return i;
    }
    return -1;
}

void jiwheel_paint(t_jiwheel *x, t_object *view)
{
    t_jgraphics *g;
    t_rect rect;
    double center_x, center_y;
    double radius;
    // getting rectangle dimensions
    g = (t_jgraphics*) patcherview_get_jgraphics(view); 
    jbox_get_rect_for_view(&x->j_box.l_box.b_ob, view, &rect);
    
    t_jrgba j_bgcolor_r, j_pointinnercolor_r, j_selectedpointinnercolor_r, j_textcolor_r, j_linecolor_r;
    object_attr_getjrgba((t_object *)x, gensym("bgcolor"), &j_bgcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("textcolor"), &j_textcolor_r);
    object_attr_getjrgba((t_object *)x, gensym("pointinnercolor"), &j_pointinnercolor_r);
    object_attr_getjrgba((t_object *)x, gensym("linecolor"), &j_linecolor_r);
    
    
    // background
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    paint_background((t_object *)x, g, &rect, &j_bgcolor_r, 0);
#else
    jgraphics_rectangle_rounded(g, 1., 1., rect.width - 2, rect.height - 2, 2, 2);
#endif
    jgraphics_set_source_jrgba(g, &j_bgcolor_r); jgraphics_fill(g);
    
    
    t_jrgba black = get_grey(0.);
    // center and radius
    get_radius_and_center(x, view, &radius, &center_x, &center_y);
    
    if (x->rebuild) {
        jiwheel_build_pitches(x, view);
        x->rebuild = false;
    }
    
    bool line = (radius == INFINITY);
    double z = x->zoom/100.;
    
    if (line) {
        double d = sqrt((rect.width/2)*(rect.width/2) + (rect.height/2) + (rect.height/2));
        double x1 = rect.width/2. - d;
        double y1 = rect.height/2. - d * sin(x->zoom_angle);
        double x2 = rect.width/2. + d;
        double y2 = rect.height/2. + d * sin(x->zoom_angle);
        paint_line(g, black, x1, y1, x2, y2, 2);
    } else {
//        paint_circle_stroken(g, black, center_x, center_y, radius, 2);
        double anglemin = 0, anglemax = TWOPI;
        double anglemin_for_stroken = 0, anglemax_for_stroken = TWOPI;
        if (x->zoom > 300) { // let's only paint an arc, it's probably better
            double angle1, angle2, angle3, angle4;
            angle1 = atan2(0 - center_y, 0 - center_x);
            angle2 = atan2(rect.height - center_y, rect.width - center_x);
            angle3 = atan2(rect.height - center_y, 0 - center_x);
            angle4 = atan2(0 - center_y, rect.width - center_x);
            angle1 += TWOPI;
            while (angle2 - angle1 > PI) angle2 -= TWOPI;
            while (angle2 - angle1 < -PI) angle2 += TWOPI;
            while (angle3 - angle1 > PI) angle3 -= TWOPI;
            while (angle3 - angle1 < -PI) angle3 += TWOPI;
            while (angle4 - angle1 > PI) angle4 -= TWOPI;
            while (angle4 - angle1 < -PI) angle4 += TWOPI;
            anglemin = MIN(angle1, MIN(angle2, MIN(angle3, angle4)));
            anglemax = MAX(angle1, MAX(angle2, MAX(angle3, angle4)));
            while (anglemin >= TWOPI) {
                anglemin -= TWOPI;
                anglemax -= TWOPI;
            }
            if (x->show_circles)
                paint_arc_stroken(g, black, center_x, center_y, radius, 2, anglemin, anglemax);
            anglemin_for_stroken = anglemin;
            anglemax_for_stroken = anglemax;
//            paint_arc_stroken(g, black, 20, 20, 20, 2, anglemin, anglemax);
            // paint_arc_stroken has a different convention than ours, it goes clockwise
            double anglediff = anglemax - anglemin;
            anglemin = positive_fmod(-anglemax, TWOPI);
            anglemax = anglemin + anglediff;
        } else {
            if (x->show_circles)
                paint_circle_stroken(g, black, center_x, center_y, radius, 2);
        }
        systhread_mutex_lock(x->c_mutex);

        // Show et wheel if needed
        if (x->show_et_wheel) {
            t_jrgba etwheel_color = x->etwheel_color;
//            paint_arc_stroken(g, black, center_x, center_y, radius + x->et_wheel_size, 2, anglemin_for_stroken, anglemax_for_stroken);
            double r_avg = radius - x->et_wheel_size/2.;
            double octave_interval_cents = ratio_to_cents(genrat(x->formaloctave, 1));
            for (long i = 0; i < octave_interval_cents; i++) {
                double et_importance = 0;
                if (i % 100 == 0) et_importance = 1.;
                else if (i % 50 == 0) et_importance = 0.7;
                else if (i % 25 == 0) et_importance = 0.5;
                else if (i % 5 == 0) et_importance = 0.25;
                else et_importance = 0.1;
                if (et_importance > 1./(5.*z)) {
                    double theta = 0;
                    double r_delta = sqrt(et_importance) * x->et_wheel_size * 0.4;
                    if (x->display_mapping == 0) { // linear pitch
                        theta = PIOVERTWO - positive_fmod((i/octave_interval_cents * TWOPI) - x->rotation_angle, TWOPI);
                    } else { // linear frequency
                        theta = PIOVERTWO - positive_fmod(((pow(2, i/octave_interval_cents) - 1) * TWOPI) - x->rotation_angle, TWOPI);
                    }
                    jiwheel_paint_radial_line(x, g, etwheel_color, center_x, center_y, theta, r_avg - r_delta, r_avg + r_delta, 1.5*sqrt(et_importance) + 0.5 * (et_importance == 1.), NULL, NULL, 0, false, 0);
                }
            }
        }

        long max_int_integers_wheel = 0;
        if (x->show_integers_wheel) {
//            paint_arc_stroken(g, black, center_x, center_y, radius + x->et_wheel_size, 2, anglemin_for_stroken, anglemax_for_stroken);
            double r_start = radius - x->et_wheel_size;
            if (atom_gettype(&x->maxterm_intwheel) == A_LONG) {
                max_int_integers_wheel = atom_getlong(&x->maxterm_intwheel);
            } else {
                max_int_integers_wheel = x->density_intwheel * 30 * pow((x->zoom/100.) * (radius / 100.), 0.5);

            }
            if (x->display_mapping == 1) // frequency mapping
                max_int_integers_wheel = ipow(x->formaloctave, (long)ceil(log(max_int_integers_wheel)/log(x->formaloctave)));
            for (long i = 1; i < max_int_integers_wheel; i++) {
                if (i % x->formaloctave == 0)
                    continue;
                double int_importance = 1./i;
                double theta = jiwheel_integer_to_theta(x, i);
                bool emphasis = (x->curr_interval.ratio.r_num > 0 && (i == x->curr_interval.ratio_without_octaves.r_num || i == x->curr_interval.ratio_without_octaves.r_den));

                if (anglemin < TWOPI && anglemax >= TWOPI && theta < anglemin)
                    theta += TWOPI;
                if (theta >= anglemin && theta <= anglemax) {
                    char text[20];
                    snprintf_zero(text, 20, "%ld", i);
                    double fontrescale = x->minfactor + (1-x->minfactor) * pow(int_importance, 0.3);
                    t_jfont *jf = jfont_create_debug(jbox_get_fontname((t_object *) x)->s_name, (t_jgraphics_font_slant)jbox_get_font_slant((t_object *) x), (t_jgraphics_font_weight)jbox_get_font_weight((t_object *) x), fontrescale * jbox_get_fontsize((t_object *) x));
                    
                    double r_end = r_start - (0.15 * x->int_wheel_size + 0.85 * x->int_wheel_size * fontrescale);
                    jiwheel_paint_radial_line(x, g, black, center_x, center_y, theta, r_start, r_end, 1*fontrescale * (emphasis ? 2 : 1), NULL, NULL, emphasis, false, 0);
                    write_text(g, jf, black, text, center_x + (r_end - 10) * cos(theta) - 30,center_y - (r_end - 10) * sin(theta) - 30, 60, 60, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, true, false);
                    jfont_destroy_debug(jf);
                }
            }
        }
        
        
        // Decide which pitches must be shown
        t_llll *shown_pitches_ll = llll_get();
        double max_shown_importance = 0.;
        for (long n = 0; n < x->num_pitches; n++) {
            t_wheelpitch *p = &x->curr_pitches[n];
            double theta = positive_fmod(p->angle + x->rotation_angle, TWOPI);
            
            p->shown = true;
            if (anglemin < TWOPI && anglemax >= TWOPI && theta < anglemin)
                theta += TWOPI;
            if (theta < anglemin || theta > anglemax)
                p->shown = false;
            else {
                p->shown = true;
                llll_appendobj(shown_pitches_ll, p);
                max_shown_importance = MAX(max_shown_importance, p->importance);
            }
        }
        double maxreduction = x->minfactor;
        if (max_shown_importance > 0) {
            for (long n = 0; n < x->num_pitches; n++) { // normalizing importances
                t_wheelpitch *p = &x->curr_pitches[n];
                p->curr_normalized_importance = rescale(p->importance, 0., max_shown_importance, maxreduction, 1.);
            }
        } else {
            for (long n = 0; n < x->num_pitches; n++) { // normalizing importances
                t_wheelpitch *p = &x->curr_pitches[n];
                p->curr_normalized_importance = 0;
            }
        }
        
        // Check which points coincide with intwheel
        for (long n = 0; n < x->num_pitches; n++) {
            t_wheelpitch *p = &x->curr_pitches[n];
            if (!x->extend_ticks_to_integers) {
                p->coincides_with_intwheel = false;
            } else {
                t_rational pr = p->ratio / x->rotation_ratio_intwheel;
                remove_octaves(x, &pr);
                if (pr.den() == 1 && pr.num() < max_int_integers_wheel)
                    p->coincides_with_intwheel = true;
                else
                    p->coincides_with_intwheel = false;
            }
        }

        
        // Avoid collisions?
        if (x->avoid_collisions) {
            // sorting by importance
            llll_mergesort_inplace(&shown_pitches_ll, (sort_fn)sort_by_importance_modif, x);
            
            /* // debug: printing reordered ratios
            t_llll *temp = llll_get();
            for (t_llllelem *el = shown_pitches_ll->l_head; el; el = el->l_next) {
                t_wheelpitch *p = (t_wheelpitch *)hatom_getobj(&el->l_hatom);
                llll_appendrat(temp, p->ratio);
            }
            llll_print(temp);
            llll_free(temp);
             */

            // checking collisions
            for (t_llllelem *el = shown_pitches_ll->l_head; el; el = el->l_next) {
                t_wheelpitch *p = (t_wheelpitch *)hatom_getobj(&el->l_hatom);
                char *p_number_txt = NULL;
                t_jfont *p_font = NULL;
                t_pt p_number_center, p_number_left;
                t_rect p_number_rect, p_actual_rect;
                double p_fontsize = 0, p_theta = positive_fmod(p->angle + x->rotation_angle, TWOPI);
                bool p_acc_displayed = false;
                
                jiwheel_get_label_specs(x, p, build_pt(center_x, center_y), radius, cos(p_theta), sin(p_theta), &p_number_txt, &p_font, &p_number_center, &p_number_left, &p_number_rect, &p_fontsize, &p_acc_displayed, &p_actual_rect);
                
                bool collision = false;
                for (t_llllelem *pr_el = el->l_prev; pr_el; pr_el = pr_el->l_prev) {
                    t_wheelpitch *q = (t_wheelpitch *)hatom_getobj(&pr_el->l_hatom);
                    if (!q->shown)
                        continue;
                    
                    char *q_number_txt = NULL;
                    t_jfont *q_font = NULL;
                    t_pt q_number_center, q_number_left;
                    t_rect q_number_rect, q_actual_rect;
                    double q_fontsize = 0, q_theta = positive_fmod(q->angle + x->rotation_angle, TWOPI);
                    bool q_acc_displayed = false;

                    jiwheel_get_label_specs(x, q, build_pt(center_x, center_y), radius, cos(q_theta), sin(q_theta), &q_number_txt, &q_font, &q_number_center, &q_number_left, &q_number_rect, &q_fontsize, &q_acc_displayed, &q_actual_rect);

                    bach_freeptr(q_number_txt);
                    jfont_destroy_debug(q_font);
                    
                    switch (x->text_direction) {
                        case BACH_PITCHWHEEL_TEXT_UPRIGHT:
                            if (jgraphics_rectintersectsrect(&p_actual_rect, &q_actual_rect))
                                collision = true;
                            break;
                            
                        case BACH_PITCHWHEEL_TEXT_RADIAL:
                            if (angle_dist(p_theta, q_theta, TWOPI) * radius < (p_actual_rect.height + q_actual_rect.height) / 2.)
                                collision = true;
                            break;
                            
                        case BACH_PITCHWHEEL_TEXT_ANGULAR:
                            if (angle_dist(p_theta, q_theta, TWOPI) * radius < (p_actual_rect.width + q_actual_rect.width) / 2.)
                                collision = true;
                            break;
                        
                        default:
                            break;
                    }
                    
                    if (collision)
                        break;
                    
                }
                
                bach_freeptr(p_number_txt);
                jfont_destroy_debug(p_font);

                if (collision && !(wheelpitch_is_sel_or_mouseover(x, p))) {
                    p->shown = false;
                }
            }

        }
        
        long sel1_idx = (x->sel1_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->sel1_ratio) : -1);
        long sel2_idx = (x->sel2_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->sel2_ratio) : -1);
        long mouseover_idx = (x->mouseover_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->mouseover_ratio) : -1);

        
        
       // Display
        t_jrgba selcolor = x->selection_color;
        t_jrgba selcoloralpha = change_alpha(x->selection_color, 0.1);
        for (t_llllelem *el = shown_pitches_ll->l_head; el; el = el->l_next) {
            t_wheelpitch *p = (t_wheelpitch *)hatom_getobj(&el->l_hatom);
            
            if (!p->shown)
                continue;
            
            long limit = p->limit;
            double importance = p->curr_normalized_importance;
            double ticklength = x->tick_length * importance;
            double ticklinewidth = 1.5 * importance;
            double theta = positive_fmod(p->angle + x->rotation_angle, TWOPI);
            bool is_mouseover = (p->index == mouseover_idx);
            bool is_sel = (p->index == sel1_idx || p->index == sel2_idx);
                
            t_jrgba color = black;
            
            switch (x->color_mode) {
                case BACH_PITCHWHEEL_COLORMODE_LIMIT:
                    color = jiwheel_long_to_color(x, num_to_prime_idx(p->limit)-1);
                    break;

                case BACH_PITCHWHEEL_COLORMODE_MAXEXP:
                    color = jiwheel_long_to_color(x, p->maxexp);
                    break;

                case BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANCHROMATICNOTE:
                    color = jiwheel_long_to_color(x, p->pythagorean_index);
                    break;

                case BACH_PITCHWHEEL_COLORMODE_PYTHAGOREANDIATONICNOTE:
                    color = jiwheel_long_to_color(x, positive_fmod(p->pythagorean_index, 7));
                    break;
                    
                case BACH_PITCHWHEEL_COLORMODE_PLAIN:
                    color = j_textcolor_r;
                    break;
                    
                default:
                    color = get_grey(0); // black
                    break;
            }
            
            char text_direction = x->text_direction;
            
            double sinus, cosinus;
            if (x->show_ticks) {
                jiwheel_paint_radial_line(x, g, color, center_x, center_y, theta, radius, radius + ticklength, ticklinewidth * (is_mouseover || is_sel ? 2 : 1), &sinus, &cosinus, is_mouseover || is_sel ? -1 : 0, false, 0);
                if (x->extend_ticks_to_integers && p->coincides_with_intwheel) {
//                    t_rational q = p->ratio / x->rotation_ratio_intwheel;
//                    remove_octaves(x, &q);
//                    if (q.den() == 1 && q.num() < max_int_integers_wheel)
                        jiwheel_paint_radial_line(x, g, color, center_x, center_y, theta, radius, radius - x->et_wheel_size, MAX(ticklinewidth, 2), NULL, NULL, 0, true, 1);
                }
            } else {
                sinus = sin(theta);
                cosinus = cos(theta);
            }
            
            
            // write number?
            if (x->show_ratios) {
                t_jtextlayout *jtl = jtextlayout_create();
                char *number_txt = NULL;
                t_jfont *font = NULL;
                t_pt number_center, number_left;
                t_rect number_rect, actual_rect;
                t_jmatrix mat;
                double fontsize;
                bool accdisplayed;
                
                jiwheel_get_label_specs(x, p, build_pt(center_x, center_y), radius, cosinus, sinus, &number_txt, &font, &number_center, &number_left, &number_rect, &fontsize, &accdisplayed, &actual_rect);
                
//                paint_rect(g, &actual_rect, &black, NULL, 1, 0);
                
                theta = positive_fmod(theta, TWOPI);
                bool turn_for_legibility = false;
                
                switch (text_direction) {
                    case BACH_PITCHWHEEL_TEXT_RADIAL:
                        turn_for_legibility = (x->rotate_for_legibility && theta + PIOVERTWO > PI && theta + PIOVERTWO <= TWOPI);
                        jgraphics_matrix_init_rotate(&mat, -theta + (turn_for_legibility ? PI : 0));
                        jgraphics_matrix_translate(&mat, number_left.x, number_left.y);
                        jgraphics_set_matrix(g, &mat);
                        if (is_sel) {
                            double nudge = (accdisplayed) ? fontsize * 0.1 * (turn_for_legibility ? 1 : -1) : 0;
                            paint_rectangle(g, selcolor, selcoloralpha, nudge + (turn_for_legibility ? -actual_rect.width : 0), -actual_rect.height/2., actual_rect.width, actual_rect.height, 1);
                        } else if (is_mouseover) {
                            double nudge = (accdisplayed) ? fontsize * 0.1 * (turn_for_legibility ? 1 : -1) : 0;
                            paint_filledrectangle(g, selcoloralpha, nudge + (turn_for_legibility ? -actual_rect.width : 0), -actual_rect.height/2., actual_rect.width, actual_rect.height);
                        }
                        jtextlayout_set(jtl, number_txt, font, turn_for_legibility ? -number_rect.width : 0, -number_rect.height/2., number_rect.width, number_rect.height, turn_for_legibility ? JGRAPHICS_TEXT_JUSTIFICATION_RIGHT : JGRAPHICS_TEXT_JUSTIFICATION_LEFT, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        break;

                    case BACH_PITCHWHEEL_TEXT_ANGULAR:
                        turn_for_legibility = (x->rotate_for_legibility && theta > PI && theta <= TWOPI);
                        jgraphics_matrix_init_rotate(&mat, -theta+PIOVERTWO  + (turn_for_legibility ? PI : 0));
                        jgraphics_matrix_translate(&mat, number_left.x, number_left.y);
                        jgraphics_set_matrix(g, &mat);
                        if (is_sel) {
                            double nudge = (accdisplayed) ? actual_rect.height * 1.1666 * (turn_for_legibility ? 1 : -1) : 0;
                            paint_rectangle(g, selcolor, selcoloralpha, -actual_rect.width/2., nudge + (turn_for_legibility ? 0 : -actual_rect.height), actual_rect.width, actual_rect.height, 1.);
                        } else if (is_mouseover) {
                            double nudge = (accdisplayed) ? actual_rect.height * 1.1666 * (turn_for_legibility ? 1 : -1) : 0;
                            paint_filledrectangle(g, selcoloralpha, -actual_rect.width/2., nudge + (turn_for_legibility ? 0 : -actual_rect.height), actual_rect.width, actual_rect.height);
                        }
                        jtextlayout_set(jtl, number_txt, font, -number_rect.width/2., turn_for_legibility ? 0 : -number_rect.height, number_rect.width, number_rect.height, JGRAPHICS_TEXT_JUSTIFICATION_HCENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        break;
                        
                    default:
                        if (is_sel) {
                            paint_rectangle(g, selcolor, selcoloralpha, actual_rect.x, actual_rect.y, actual_rect.width, actual_rect.height, 1.);
                        } else if (is_mouseover) {
                            paint_filledrectangle(g, selcoloralpha, actual_rect.x, actual_rect.y, actual_rect.width, actual_rect.height);
                        }
                        jtextlayout_set(jtl, number_txt, font, number_rect.x, number_rect.y, number_rect.width, number_rect.height, JGRAPHICS_TEXT_JUSTIFICATION_CENTERED, JGRAPHICS_TEXTLAYOUT_NOWRAP);
                        break;
                }
                jtextlayout_settextcolor(jtl, &color);
                jtextlayout_draw(jtl, g);
                jtextlayout_destroy(jtl);

                bach_freeptr(number_txt);
                jfont_destroy_debug(font);
            }
            
            if (text_direction != BACH_PITCHWHEEL_TEXT_UPRIGHT)
                jgraphics_identity_matrix(g);
            
        }
        
        if (sel1_idx >= 0 && sel2_idx >= 0) {
            double a1 = -x->curr_pitches[sel1_idx].angle - x->rotation_angle;
            double a2 = -x->curr_pitches[sel2_idx].angle - x->rotation_angle;
            if (a2 < a1)
                a2 += TWOPI;
            paint_arc_stroken(g, black, center_x, center_y, radius, 4, a1, a2);
            
            double theta = -(a1 + a2)*0.5 - 7.5 / radius;
            double xm = center_x + radius * cos(theta);
            double ym = center_y - radius * sin(theta);
            double x1 = xm-sin(theta);
            double y1 = ym-cos(theta);
            double x2 = xm+sin(theta);
            double y2 = ym+cos(theta);
//            paint_circle(g, black, black, xm, ym, 15, 1);
            paint_arrow(g, black, x1, y1, x2, y2, 0, 15, 15);
        }


        // Legend
        if (x->legend_fontname) {
            if (x->show_legend >= 1 && sel1_idx >= 0 && sel2_idx >= 0) {
                jiwheel_paint_legend_interval(x, g, rect, &x->curr_pitches[sel1_idx], &x->curr_pitches[sel2_idx]);
            } else if (x->show_legend >= 1 && sel1_idx >= 0) {
                jiwheel_paint_legend(x, g, rect, &x->curr_pitches[sel1_idx], PITCHWHEEL_LEGEND_INSET, "Pitch", false);
            } else if (x->show_legend >= 2 && mouseover_idx >= 0) {
                jiwheel_paint_legend(x, g, rect, &x->curr_pitches[mouseover_idx], PITCHWHEEL_LEGEND_INSET, "Pitch", false);
            }
        }
        
 
        
        llll_free(shown_pitches_ll);
        
        systhread_mutex_unlock(x->c_mutex);
    }
    
    
    // border
#ifdef BACH_MAX7_STYLES_COMPATIBILITY
    paint_border((t_object *)x, g, &rect, &x->j_bordercolor, (x->show_focus && x->j_has_focus) ? 2.5 : 1., 0.);
#else
    jgraphics_rectangle_rounded(g, 1., 1., rect.width - 2, rect.height - 2, 10, 6);
    jgraphics_set_source_jrgba(g, &x->j_bordercolor);
    jgraphics_set_line_width(g, (x->show_focus && x->j_has_focus) ? 2.5 : 1.);
    jgraphics_stroke(g);
#endif
}


void jiwheel_focusgained(t_jiwheel *x, t_object *patcherview) {
//    object_post((t_object *)x, "focusgained"); 
    x->j_has_focus = true;
    jbox_redraw((t_jbox *)x);
}

void jiwheel_focuslost(t_jiwheel *x, t_object *patcherview) {
//    object_post((t_object *)x, "focuslost"); 
    x->j_has_focus = false;
    jbox_redraw((t_jbox *)x);
}


void get_radius_and_center(t_jiwheel *x, t_object *patcherview, double *radius, double *center_x, double *center_y){
    t_rect rect;
    jbox_get_rect_for_view(&x->j_box.l_box.b_ob, patcherview, &rect); // rect dimension
    
    // center and radius
    t_pt screencenter = build_pt(rect.width/2, rect.height/2);
    t_pt center = screencenter;
    double inset = x->inset + x->tick_length + jbox_get_fontsize((t_object *)x);
    double base_radius = MIN(center.x - inset, center.y - inset);
    *radius = base_radius;
    if (x->zoom > 100) {
        double z = x->zoom / 100.;
        *radius *= z;
        {
            double t = (*radius - base_radius)/base_radius;
            center.y = (*radius + inset) + (atan(0.1*t)/PIOVERTWO) * (rect.height/2 - x->inset);
            
            t_pt newcenter;
            center = pt_pt_diff(center, screencenter);
            newcenter.x = center.x * cos(x->zoom_angle) - center.y * sin(x->zoom_angle);
            newcenter.y = center.x * sin(x->zoom_angle) + center.y * cos(x->zoom_angle);
            center = pt_pt_sum(newcenter, screencenter);
        }
    }
    
    *center_x = center.x;
    *center_y = center.y;
}


long pt_to_wheelpitch_idx(t_jiwheel *x, t_object *patcherview, t_pt pt)
{
    double radius;
    t_pt center;
    get_radius_and_center(x, patcherview, &radius, &center.x, &center.y);
    t_pt diff = pt_pt_diff(pt, center);
    long best = -1;
    double d = pt_norm(diff);
    if ((d > radius && d < radius + x->tick_length + x->accidentals_font_size) || x->mouse_is_dragging) {
        double angle = -atan2(diff.y, diff.x);
        // find nearest
        double best_dist = DBL_MAX;
        for (long i = 0; i < x->num_pitches; i++) {
            if (!x->curr_pitches[i].shown)
                continue;
            double this_dist = angle_dist(angle, x->curr_pitches[i].angle + x->rotation_angle, TWOPI);
            if (best < 0 || (this_dist < best_dist)) {
                best_dist = this_dist;
                best = i;
            }
        }
    }
    return best;
}

void jiwheel_clear_selection(t_jiwheel *x)
{
    x->sel1_ratio = x->sel2_ratio = genrat(0, 1);
    x->curr_interval.ratio = genrat(0, 1);
}


void jiwheel_set_intwheel_from_sel1(t_jiwheel *x)
{
    if (x->sel1_ratio.r_num > 0) {
        long sel1_idx = (x->sel1_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->sel1_ratio) : -1);
        if (sel1_idx >= 0) {
            x->rotation_ratio_intwheel = x->curr_pitches[sel1_idx].ratio;
            x->rotation_angle_intwheel = PIOVERTWO - x->curr_pitches[sel1_idx].angle;
        }
    }
}

void jiwheel_set_intwheel_from_selection(t_jiwheel *x)
{
    if (x->sel1_ratio.r_num != 0 && x->sel2_ratio.r_num != 0) {
        long sel1_idx = (x->sel1_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->sel1_ratio) : -1);
        long sel2_idx = (x->sel2_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->sel2_ratio) : -1);
        if (sel1_idx >= 0 && sel2_idx >= 0) {
            // find ratio
            t_rational interval = x->curr_interval.ratio_without_octaves;
            // put the interval.r_num integer coinciding with sel1 pitch
            x->rotation_angle_intwheel = 0;
            double theta = jiwheel_integer_to_theta(x, interval.r_num) - x->curr_pitches[sel2_idx].angle;
            x->rotation_angle_intwheel = theta - x->rotation_angle;
            
            //
            x->rotation_ratio_intwheel = x->curr_pitches[sel1_idx].ratio / interval.r_den; // wrong
        }
    }
}

void jiwheel_sync_interval(t_jiwheel *x)
{
    t_rational r = x->sel2_ratio / x->sel1_ratio;
    ensure_ratio_is_between_1_and_formaloctave(&r, x->formaloctave);
    rational_to_wheelpitch(r, 'C', x->formaloctave, x->display_mapping > 0, &x->curr_interval);
}

void jiwheel_mousemove(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_rational curr_ratio = x->mouseover_ratio;
    systhread_mutex_lock(x->c_mutex);
    long i = pt_to_wheelpitch_idx(x, patcherview, pt);
    if (i >= 0) {
        x->mouseover_ratio = x->curr_pitches[i].ratio;
    } else {
        x->mouseover_ratio = genrat(0, 1);
    }
    if (curr_ratio != x->mouseover_ratio)
        jbox_redraw((t_jbox *)x);
    systhread_mutex_unlock(x->c_mutex);
    return;
}

void jiwheel_mousedoubleclick(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    jiwheel_mousedown(x, patcherview, pt, modifiers | eAltKey);
}


void jiwheel_mousedown(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    x->mousedrag_pt = pt;

    t_pt center;
    double radius;
    get_radius_and_center(x, patcherview, &radius, &center.x, &center.y);
    double norm = pt_norm(pt_pt_diff(pt, center));
    x->mousedown_is_in_etwheel = (norm < radius && norm > radius - x->et_wheel_size);

    if (x->mousedown_is_in_etwheel || modifiers & eControlKey)
        return;
    
    bool must_output_selection = false;
    systhread_mutex_lock(x->c_mutex);
    long sel_pitch_idx = pt_to_wheelpitch_idx(x, patcherview, pt);
    if (sel_pitch_idx == -1) {
        if (x->sel1_ratio.r_num != 0)
            must_output_selection = true;
        jiwheel_clear_selection(x);
        jbox_redraw((t_jbox *)x);
    } else {
        if (x->sel1_ratio.r_num != 0 && (modifiers & eShiftKey)) {
            x->sel2_ratio = x->curr_pitches[sel_pitch_idx].ratio;
            jiwheel_sync_interval(x);
            if (x->auto_move_intwheel)
                jiwheel_set_intwheel_from_selection(x);
            must_output_selection = true;
            jbox_redraw((t_jbox *)x);
        } else {
            jiwheel_clear_selection(x);
            x->sel1_ratio = x->curr_pitches[sel_pitch_idx].ratio;
            x->sel2_ratio = genrat(0, 1);
            if (modifiers & eAltKey) {
                jiwheel_set_intwheel_from_sel1(x);
            }
            must_output_selection = true;
            jbox_redraw((t_jbox *)x);
        }
    }
    systhread_mutex_unlock(x->c_mutex);
    
    if (must_output_selection)
        jiwheel_output_selection(x);

    return;
}

void jiwheel_mouseup(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers){
    x->mouse_is_dragging = false;
    x->mousedown_is_in_etwheel = false;
    return;
}


double get_mousedrag_angle(t_pt center, t_pt mousedown, t_pt mousedrag)
{
    t_pt delta = pt_pt_diff(mousedrag, mousedown);
    t_pt radius = pt_pt_diff(mousedown, center);
    t_pt perp = build_pt(radius.y, -radius.x);
    double perp_norm = pt_norm(perp);
    double radius_norm = pt_norm(radius);
    if (perp_norm == 0 || radius_norm == 0)
        return 0;
    perp = pt_number_prod(perp, 1./perp_norm);
    double dot = pt_pt_dot(perp, delta);
    return dot / radius_norm;
}

void jiwheel_mousewheel(t_jiwheel *x, t_object *view, t_pt pt, long modifiers, double x_inc, double y_inc)
{
    llll_format_modifiers(&modifiers, NULL);
    
    double r, cx, cy;
    get_radius_and_center(x, view, &r, &cx, &cy);

    if (modifiers == eCommandKey || modifiers == eShiftKey + eCommandKey) { // change side value
        double old_zoom = x->zoom / 100.;
        double new_zoom = old_zoom;
        const double PITCHWHEEL_Y_MOUSEWHEEL_FACTOR = 1.5;

        new_zoom -= y_inc * pow(old_zoom, 0.5) * PITCHWHEEL_Y_MOUSEWHEEL_FACTOR * (modifiers & eShiftKey ? CONST_FINER_FROM_KEYBOARD : 1.);

        new_zoom = CLAMP(new_zoom, 1., PITCHWHEEL_MAX_ZOOM/100.);
        object_attr_setfloat((t_object *)x, gensym("zoom"), new_zoom * 100);
        
        
        if (x->zoom <= 100.1)
            x->zoom_angle = PIOVERTWO - atan2(-pt.y+cy, pt.x-cx);
/*
        // notify zoom change
        t_llll *ll = llll_get();
        llll_appendsym(ll, _llllobj_sym_zoom, 0, WHITENULL_llll);
        llll_appenddouble(ll, new_zoom, 0, WHITENULL_llll);
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 6, ll);
        llll_free(ll); */

        jbox_redraw((t_jbox *)x);
    } else {
//        x->zoom_angle += get_mousedrag_angle(build_pt(cx, cy), pt, build_pt(x_inc, y_inc));
//        x->rebuild = true;
//        jbox_redraw((t_jbox *)x);
    }
}

void jiwheel_mousedrag(t_jiwheel *x, t_object *patcherview, t_pt pt, long modifiers)
{
    t_pt center;
    double radius;
    get_radius_and_center(x, patcherview, &radius, &center.x, &center.y);

    x->mouse_is_dragging = true;
    
    systhread_mutex_lock(x->c_mutex);
    if (modifiers & eControlKey || x->mousedown_is_in_etwheel) {
        x->rotation_angle += get_mousedrag_angle(center, x->mousedrag_pt, pt);
        if (x->sel1_ratio.r_num != 0 && x->sel2_ratio.r_num != 0) {
            jiwheel_sync_interval(x);
            jiwheel_set_intwheel_from_selection(x);
        }
    } else {
        if (x->sel1_ratio.r_num != 0) {
            long sel_pitch_idx = pt_to_wheelpitch_idx(x, patcherview, pt);
            if (sel_pitch_idx >= 0 && sel_pitch_idx < x->num_pitches) {
                x->sel2_ratio = x->curr_pitches[sel_pitch_idx].ratio;
                jiwheel_sync_interval(x);
                if (x->auto_move_intwheel)
                    jiwheel_set_intwheel_from_selection(x);
            }
        }
    }
    systhread_mutex_unlock(x->c_mutex);
    
    jiwheel_output_selection(x);
    
    jbox_redraw((t_jbox *)x);
    
    x->mousedrag_pt = pt;
}

double angle_diff(double angle1, double angle2, double modulo)
{
    return positive_fmod(angle2 - angle1, TWOPI);
}


long jiwheel_get_next(t_jiwheel *x, long idx, bool only_if_visible)
{
    if (idx < 0 || idx > x->num_pitches)
        return -1;
    
    double curr_best_angledist = DBL_MAX;
    long curr_best_idx = -1;
    for (long j = 0; j < x->num_pitches; j++) {
        if (j == idx)
            continue;
        if (only_if_visible && ! x->curr_pitches[j].shown)
            continue;
        double this_dist = angle_diff(x->curr_pitches[j].angle, x->curr_pitches[idx].angle, TWOPI);
        if (curr_best_idx < 0 || this_dist < curr_best_angledist) {
            curr_best_angledist = this_dist;
            curr_best_idx = j;
        }
    }
    return curr_best_idx;
}

long jiwheel_get_prev(t_jiwheel *x, long idx, bool only_if_visible)
{
    if (idx < 0 || idx > x->num_pitches)
        return -1;
    
    double curr_best_angledist = DBL_MAX;
    long curr_best_idx = -1;
    for (long j = 0; j < x->num_pitches; j++) {
        if (j == idx)
            continue;
        if (only_if_visible && ! x->curr_pitches[j].shown)
            continue;
        double this_dist = angle_diff(x->curr_pitches[idx].angle, x->curr_pitches[j].angle, TWOPI);
        if (curr_best_idx < 0 || this_dist < curr_best_angledist) {
            curr_best_angledist = this_dist;
            curr_best_idx = j;
        }
    }
    return curr_best_idx;
}


long jiwheel_key(t_jiwheel *x, t_object *patcherview, long keycode, long modifiers, long textcharacter)
{
    bool must_output_selection = false;
    llll_format_modifiers(&modifiers, &keycode);
    
    switch (keycode) {
        case JKEY_ESC:
            object_attr_setfloat((t_object *)x, gensym("zoom"), 100);
            object_attr_setfloat((t_object *)x, gensym("zoomangle"), 0);
            object_attr_setfloat((t_object *)x, gensym("rotationangle"), 0);
            must_output_selection = (x->sel1_ratio.r_num != 0);
            jiwheel_clear_selection(x);
            if (must_output_selection)
                jiwheel_output_selection(x);
            x->mouseover_ratio = genrat(0, 1);
            jbox_redraw((t_jbox *)x);
            return 1;
            
        case JKEY_UPARROW:
            if (x->sel2_ratio.num() > 0) {
                long nextidx = jiwheel_get_next(x, jiwheel_ratio_to_index(x, x->sel2_ratio), modifiers & eAltKey ? true : false);
                if (nextidx >= 0) {
                    x->sel2_ratio = x->curr_pitches[nextidx].ratio;
                    jiwheel_sync_interval(x);
                    jiwheel_set_intwheel_from_selection(x);
                    jiwheel_output_selection(x);
                }
            } else if (x->sel1_ratio.num() > 0) {
                long nextidx = jiwheel_get_next(x, jiwheel_ratio_to_index(x, x->sel1_ratio), modifiers & eAltKey ? true : false);
                if (nextidx >= 0) {
                    x->sel1_ratio = x->curr_pitches[nextidx].ratio;
                    jiwheel_sync_interval(x);
                    jiwheel_set_intwheel_from_sel1(x);
                    jiwheel_output_selection(x);
                }
            }
            jbox_redraw((t_jbox *)x);
            return 1;

        case JKEY_DOWNARROW:
        case 'r':
            if (x->sel2_ratio.num() > 0) {
                long nextidx = jiwheel_get_prev(x, jiwheel_ratio_to_index(x, x->sel2_ratio), modifiers & eAltKey ? true : false);
                if (nextidx >= 0) {
                    x->sel2_ratio = x->curr_pitches[nextidx].ratio;
                    jiwheel_sync_interval(x);
                    jiwheel_set_intwheel_from_selection(x);
                    jiwheel_output_selection(x);
                }
            } else if (x->sel1_ratio.num() > 0) {
                long nextidx = jiwheel_get_prev(x, jiwheel_ratio_to_index(x, x->sel1_ratio), modifiers & eAltKey ? true : false);
                if (nextidx >= 0) {
                    x->sel1_ratio = x->curr_pitches[nextidx].ratio;
                    jiwheel_sync_interval(x);
                    jiwheel_set_intwheel_from_sel1(x);
                    jiwheel_output_selection(x);
                }
            }
            jbox_redraw((t_jbox *)x);
            return 1;

        default:
            break;
    }

    return 0;
}


t_llll *jiwheel_get_wheelpitch_as_llll(t_jiwheel *x, t_wheelpitch *p, bool as_interval)
{
    
    t_llll *out = llll_get();
    // TODO: aggiungere pitch!
    llll_appendllll(out, symbol_and_rational_to_llll(gensym("ratio"), p->ratio));
    llll_appendllll(out, symbol_and_rational_to_llll(gensym("condensedratio"), p->ratio_without_octaves));
    llll_appendllll(out, symbol_and_double_to_llll(gensym("cents"), p->cents));
    llll_appendllll(out, symbol_and_long_to_llll(gensym("limit"), p->limit));
    llll_appendllll(out, symbol_and_long_to_llll(gensym("maxexp"), p->maxexp));
    llll_appendllll(out, symbol_and_double_to_llll(gensym("angle"), positive_fmod(PIOVERTWO - p->angle, TWOPI)));
    /*
    if (p->coincides_with_intwheel) {
        t_rational r = p->ratio;
        remove_octaves(x, &r);
        llll_appendllll(out, symbol_and_double_to_llll(gensym("intwheelint"), r.num()));
    }
    */

    {
        t_llll *factors = llll_factorize_rational(p->ratio);
        for (t_llllelem *el = factors->l_head; el; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                if (ll && ll->l_head && hatom_getlong(&ll->l_head->l_hatom) == x->formaloctave) {
                    llll_destroyelem(el);
                    break;
                }
            }
        }
        llll_prependsym(factors, gensym("primes"));
        llll_appendllll(out, factors); // prime commas
    }

    llll_appendllll(out, symbol_and_long_to_llll(gensym("pythstep"), p->pythagorean_index)); // pythagorean position in the circle of fiths
    llll_appendllll(out, symbol_and_long_to_llll(gensym("whitekey"), p->pyth_diatonic_step));
    if (as_interval) {
        long numoctaves = 0;
        const char *name = jiwheel_ratio_to_common_interval_name(p->ratio, &numoctaves);
        t_llll *ll = llll_get();
        llll_appendsym(ll, gensym("name"));
        llll_appendsym(ll, strlen(name) == 0 ? _llllobj_sym_unknown : gensym(name));
        llll_appendlong(ll, numoctaves);
        llll_appendllll(out, ll);
    } else {
        llll_appendllll(out, symbol_and_double_to_llll(gensym("importance"), p->importance));
    }

    return out;
}

void jiwheel_output_selection(t_jiwheel *x)
{
    if (x->output_selection) {
        long sel1_idx = (x->sel1_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->sel1_ratio) : -1);
        long sel2_idx = (x->sel2_ratio.r_num != 0 ? jiwheel_ratio_to_index(x, x->sel2_ratio) : -1);
        if (sel1_idx >= 0 && sel2_idx >= 0) {
            t_llll *out = llll_get();
            
            systhread_mutex_lock(x->c_mutex);
            t_llll *sel1 = jiwheel_get_wheelpitch_as_llll(x, &x->curr_pitches[sel1_idx], false);
            t_llll *sel2 = jiwheel_get_wheelpitch_as_llll(x, &x->curr_pitches[sel2_idx], false);
            t_llll *inter = jiwheel_get_wheelpitch_as_llll(x, &x->curr_interval, true);
            llll_prependsym(sel1, gensym("from"));
            llll_prependsym(sel2, gensym("to"));
            llll_prependsym(inter, gensym("interval"));
            llll_appendllll(out, sel1);
            llll_appendllll(out, sel2);
            llll_appendllll(out, inter);
            llll_prependsym(out, gensym("interval"));
            llll_prependsym(out, gensym("selection"));
            systhread_mutex_unlock(x->c_mutex);
            
            llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 1, out);
            
            llll_free(out);
        } else if (sel1_idx >= 0) {
            t_llll *out = jiwheel_get_wheelpitch_as_llll(x, &x->curr_pitches[sel1_idx], false);
            llll_prependsym(out, gensym("pitch"));
            llll_prependsym(out, gensym("selection"));

            llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 1, out);

            llll_free(out);
        } else {
            t_llll *out = llll_get();
            llll_appendsym(out, gensym("selection"));
            llll_appendsym(out, gensym("none"));

            llllobj_outlet_llll((t_object *)x, LLLL_OBJ_UI, 1, out);

            llll_free(out);
        }
    }
}
