/*
 *  notation_accidentals.c
 *
 * Copyright (C) 2010-2025 Andrea Agostini and Daniele Ghisi
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
    notation_commons.c - common functions (or useful functions) for notation objects
*/

#include "foundation/bach.h"
#include "notation/notation.h" // header with all the structures for the notation objects



t_shortRational note_get_display_accidentals_ordinary(t_note *nt)
{
    if (nt->pitch_displayed.isPureET()) {
        return nt->pitch_displayed.getAlterET();
    } else if (nt->pitch_displayed.isPureJI()) {
        return genrat(nt->pitch_displayed.getSharpsJI(), 2);
    } else {
        return genrat(nt->pitch_displayed.getDisplayPitchAsJI().getSharpsJI(), 2);
    }
}

t_rational note_get_display_accidentals_JIcommas(t_note *nt)
{
    if (nt->pitch_displayed.isPureET()) {
        return genrat(1, 1);
    } else if (nt->pitch_displayed.isPureJI()) {
        return nt->pitch_displayed.getHEJICommasAsRationalIncludePythagorean();
    } else {
        return nt->pitch_displayed.getDisplayPitchAsJI().getHEJICommasAsRationalIncludePythagorean();
    }
}

double note_get_display_accidentals_cents(t_note *nt)
{
    if (nt->pitch_displayed.isPureET()) {
        return nt->pitch_displayed.getAlterET() * 200.;
    } else if (nt->pitch_displayed.isPureJI()) {
        return log2(nt->pitch_displayed.getHEJICommasAsDoubleIncludePythagorean())*1200.;
    } else {
        return nt->pitch_displayed.getAlterET() * 200. + log2(nt->pitch_displayed.getHEJICommasAsDoubleIncludePythagorean())*1200.;
    }
}

bool pitch_has_accidentals(t_pitch *p)
{
    if (p->isPureET()) {
        return !(p->getAlterET() == 0);
    } else if (p->isPureJI()) {
        return !(p->isPurePythagorean() && p->getSharpsJI() == 0);
    } else {
        t_pitch q = p->getDisplayPitchAsJI();
        return !(q.getAlterET() == 0 && p->isPurePythagorean() && q.getSharpsJI() == 0);
    }
}

bool note_has_accidentals(t_note *nt)
{
    return nt->num_accidentals > 0;
//    return pitch_has_accidentals(&nt->pitch_displayed);
}

bool note_has_no_accidentals_or_has_natural(t_note *nt)
{
    if (nt->num_accidentals == 0 || (nt->num_accidentals == 1 && (nt->accidentals[0] == BACH_ACCIDENTAL_NATURAL || nt->accidentals[0] == BACH_ACCIDENTAL_JI_NATURAL)))
        return true;
    return false;
}

// accidentals must be initialized at least with CONST_MAX_ACCIDENTALS + 1
bool accidentals_eq(t_uint8 *accidentals1, t_uint8 *accidentals2)
{
    for (long i = 0; i < CONST_MAX_ACCIDENTALS+1; i++) {
        if (accidentals1[i] != accidentals2[i])
            return false;
        if (accidentals1[i] == BACH_ACCIDENTAL_NONE) // equal
            return true;
    }
    return true;
}

// accidentals must be initialized at least with CONST_MAX_ACCIDENTALS + 1
void note_get_display_accidentals(t_note *nt, t_uint8 *accidentals)
{
    sysmem_copyptr(nt->accidentals, accidentals, (MIN(nt->num_accidentals, CONST_MAX_ACCIDENTALS) + 1) * sizeof(t_uint8));
}


// *unicodeChar accidental_text must be initialized with size 2*(CONST_MAX_ACCIDENTALS+1)
void note_get_accidentals_unicode_chars(t_notation_obj *r_ob, t_note *nt, unicodeChar *accidental_text, long *accidental_text_len)
{
    long i = 0;
    if (r_ob->accidentals_typo_preferences.space_character == 0) {
        for (; i < nt->num_accidentals && i < CONST_MAX_ACCIDENTALS; i++) {
            if (nt->accidentals[i] >= 0 && nt->accidentals[i] < BACH_NUM_ACCIDENTALS)
                accidental_text[i] = r_ob->accidentals_typo_preferences.unicode_characters[nt->accidentals[i]];
            else
                accidental_text[i] = 0;
        }
        *accidental_text_len = i;
        accidental_text[i] = 0; // terminating 0
    } else {
        accidental_text[0] = 0;
        for (; i < nt->num_accidentals && i < CONST_MAX_ACCIDENTALS; i++) {
            if (nt->accidentals[i] >= 0 && nt->accidentals[i] < BACH_NUM_ACCIDENTALS)
                accidental_text[2*i] = r_ob->accidentals_typo_preferences.unicode_characters[nt->accidentals[i]];
            else
                accidental_text[2*i] = 0;
            accidental_text[2*i+1] = i < nt->num_accidentals - 1 ? r_ob->accidentals_typo_preferences.space_character : 0; // space (or terminating zero)
        }
        *accidental_text_len = (nt->num_accidentals > 0 ? 2*nt->num_accidentals-1 : 0);
    }
}

//buf must be already allocated with size >= 20
void note_get_accidental_as_fraction(t_notation_obj *r_ob, t_note *nt, char *buf)
{
    int num, den;
    double width, height, left_bottom_corner_x, left_bottom_corner_y;
    
    buf[0] = 0;
    if (nt->pitch_displayed.isPureET()) {
        num = note_get_display_accidentals_ordinary(nt).num();
        den = note_get_display_accidentals_ordinary(nt).den();
        if (r_ob->accidentals_display_type == k_ACCIDENTALS_UNREDUCED_FRACTION && den < r_ob->tone_division) {
            long factor = r_ob->tone_division / den;
            den *= factor;
            num *= factor;
        }
        if (num >= 0)
            snprintf_zero(buf, 20, "+%d/%d", num, den);
        else
            snprintf_zero(buf, 20, "-%d/%d", -num, den);
    } else if (nt->pitch_displayed.isPureJI()) {
        t_rational comma = nt->pitch_displayed.getHEJICommasAsRationalIncludePythagorean();
        snprintf_zero(buf, 20, "%d/%d", comma.r_num, comma.r_den);
    } else {
        t_rational comma = nt->pitch_displayed.getHEJICommasAsRationalIncludePythagorean();
        t_rational alterET = nt->pitch_displayed.getAlterET();
        snprintf_zero(buf, 20, "%d/%d%s%d/%dst", comma.r_num, comma.r_den, alterET > 0 ? "+" : "-", abs(alterET.r_num), alterET.r_den); // TODO: improve!
    }
}

//buf must be already allocated with size >= 20
void note_get_accidental_as_cents(t_notation_obj *r_ob, t_note *nt, char *buf)
{
    buf[0] = 0;
    double cents = 0;
    if (nt->pitch_displayed.isPureET()) {
        cents = nt->pitch_displayed.getAlterET() * 200.;
    } else if (nt->pitch_displayed.isPureJI()) {
        cents = log2(nt->pitch_displayed.getHEJICommasAsDoubleIncludePythagorean())*1200.;
    } else {
        t_pitch p = nt->pitch_displayed.getDisplayPitchAsJI();
        cents = log2(p.getHEJICommasAsDoubleIncludePythagorean())*1200. + p.getAlterET()*200.;
    }
    
    if (cents >= 0)
        snprintf_zero(buf, 20, "+%d%s", (int)round(cents), r_ob->cents_symbol ? r_ob->cents_symbol->s_name : "");
    else
        snprintf_zero(buf, 20, "-%d%s", (int)round(-cents), r_ob->cents_symbol ? r_ob->cents_symbol->s_name : "");
}

double accidentals_get_uascent(t_notation_obj *r_ob, t_uint8 *accidentals)
{
    double w = 0;
    for (long i = 0; i < CONST_MAX_ACCIDENTALS; i++) {
        if (accidentals[i] == BACH_ACCIDENTAL_NONE)
            break;
        else if (accidentals[i] >= 0 && accidentals[i] < BACH_NUM_ACCIDENTALS)
            w += r_ob->accidentals_typo_preferences.uascent[accidentals[i]];
    }
    return w;
}


double note_get_accidental_uascent(t_notation_obj *r_ob, t_note *note)
{
    if (!note->show_accidentals)
        return 0;
    
    switch (r_ob->accidentals_display_type) {
        case k_ACCIDENTALS_NO_DISPLAY:
            return 0;
            break;

        case k_ACCIDENTALS_FRACTION:
        case k_ACCIDENTALS_UNREDUCED_FRACTION:
        case k_ACCIDENTALS_CENTS:
            return 2.5;
            break;

        case k_ACCIDENTALS_CLASSICAL:
        default:
        {
            double maxuascent = 0;
            for (long i = 0; i < note->num_accidentals; i++) {
                double uascent = r_ob->accidentals_typo_preferences.uascent[note->accidentals[i]];
                if (uascent > maxuascent)
                    maxuascent = uascent;
            }
            return maxuascent * (note->parent->is_grace_chord ? CONST_GRACE_CHORD_SIZE : 1.);
            
        }
            break;
    }
}


double accidentals_get_udescent(t_notation_obj *r_ob, t_uint8 *accidentals)
{
    double w = 0;
    for (long i = 0; i < CONST_MAX_ACCIDENTALS; i++) {
        if (accidentals[i] == BACH_ACCIDENTAL_NONE)
            break;
        else if (accidentals[i] >= 0 && accidentals[i] < BACH_NUM_ACCIDENTALS)
            w += r_ob->accidentals_typo_preferences.udescent[accidentals[i]];
    }
    return w;
}

double note_get_accidental_udescent(t_notation_obj *r_ob, t_note *note)
{
    if (!note->show_accidentals)
        return 0;

    switch (r_ob->accidentals_display_type) {
        case k_ACCIDENTALS_NO_DISPLAY:
            return 0;
            break;

        case k_ACCIDENTALS_FRACTION:
        case k_ACCIDENTALS_UNREDUCED_FRACTION:
        case k_ACCIDENTALS_CENTS:
            return 3.5;
            break;

        case k_ACCIDENTALS_CLASSICAL:
        default:
        {
            double maxudescent = 0;
            for (long i = 0; i < note->num_accidentals; i++) {
                double udescent = r_ob->accidentals_typo_preferences.udescent[note->accidentals[i]];
                if (udescent > maxudescent)
                    maxudescent = udescent;
            }
            return maxudescent * (note->parent->is_grace_chord ? CONST_GRACE_CHORD_SIZE : 1.);
            
        }
            break;
    }
}

double accidentals_get_uwidth(t_notation_obj *r_ob, t_uint8 *accidentals)
{
    double w = 0;
    long count = 0;
    for (long i = 0; i < CONST_MAX_ACCIDENTALS; i++) {
        if (accidentals[i] == BACH_ACCIDENTAL_NONE)
            break;
        else if (accidentals[i] >= 0 && accidentals[i] < BACH_NUM_ACCIDENTALS) {
            count++;
            w += r_ob->accidentals_typo_preferences.uwidth[accidentals[i]];
        }
    }
    
    w += (count - 1) * r_ob->accidentals_typo_preferences.space_uwidth;
    return w;
}

double note_get_accidental_uwidth(t_notation_obj *r_ob, t_note *nt, char always_classical_display)
{
    if (!nt->show_accidentals)
        return 0;

//returns the accidental unscaled width in the BASE CASE (i.e. for the base_pt, e.g. Maestro 24, Sonora 40, ...)
    char accidentals_display_type = always_classical_display ? k_ACCIDENTALS_CLASSICAL : r_ob->accidentals_display_type;
    switch (r_ob->accidentals_display_type) {
        case k_ACCIDENTALS_NO_DISPLAY:
            return 0;
            break;
            
        case k_ACCIDENTALS_FRACTION:
        case k_ACCIDENTALS_UNREDUCED_FRACTION: // fractions
        {
            t_jfont *jf_text_fractions;
            int num, den;
            char frac_text[20];
            double width, height;
            jf_text_fractions = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, CONST_TEXT_FRACTIONS_PT);

            note_get_accidental_as_fraction(r_ob, nt, frac_text);

            jfont_text_measure(jf_text_fractions, frac_text, &width, &height); // we get how much space do we need
            jfont_destroy_debug(jf_text_fractions);
            return width + CONST_WIDTH_ADD_FRACTIONS;
        }
            break;
            
        case k_ACCIDENTALS_CENTS:
        {
            double width, height;
            char cents_text[20];
            t_jfont *jf_text_fractions;
            jf_text_fractions = jfont_create_debug("Arial", JGRAPHICS_FONT_SLANT_NORMAL, JGRAPHICS_FONT_WEIGHT_BOLD, CONST_TEXT_FRACTIONS_PT);
            
            note_get_accidental_as_cents(r_ob, nt, cents_text);
            
            jfont_text_measure(jf_text_fractions, cents_text, &width, &height); // we get how much space do we need
            jfont_destroy_debug(jf_text_fractions);
            return width + CONST_WIDTH_ADD_FRACTIONS;
        }
            break;
            
            
        case k_ACCIDENTALS_CLASSICAL:
            return accidentals_get_uwidth(r_ob, nt->accidentals);
            break;
    }
    
    return 0;
}


e_bach_accidental rational_to_accidental_ET(t_notation_obj *r_ob, t_rational accidental)
{
    if (rat_long_cmp(accidental, -1) <= 0)
        return BACH_ACCIDENTAL_DOUBLEFLAT;
    else if (rat_long_cmp(accidental, 1) >= 0)
        return BACH_ACCIDENTAL_DOUBLESHARP;
    else {
        if ((r_ob->tone_division == 2) && (r_ob->accidentals_typo_preferences.et_dyadic_depth >= 2)) { // semitone division
            t_rational div = rat_long_prod(accidental,2);
            if (div.r_den == 1) {
                switch (div.r_num) {
                    case -2: return BACH_ACCIDENTAL_DOUBLEFLAT;
                    case -1: return BACH_ACCIDENTAL_FLAT;
                    case 0: return BACH_ACCIDENTAL_NATURAL;
                    case 1: return BACH_ACCIDENTAL_SHARP;
                    case 2: return BACH_ACCIDENTAL_DOUBLESHARP;
                    default: return BACH_ACCIDENTAL_BOGUS;
                }
            } else
                return BACH_ACCIDENTAL_BOGUS; // will be  mapped to bogus character!
        } else if ((r_ob->tone_division == 4) && (r_ob->accidentals_typo_preferences.et_dyadic_depth>=4)) { // quartertone division
            t_rational div = rat_long_prod(accidental,4);
            if (div.r_den == 1) {
                switch (div.r_num) {
                    case -4: return BACH_ACCIDENTAL_DOUBLEFLAT;
                    case -3: return BACH_ACCIDENTAL_THREEQUARTERFLAT;
                    case -2: return BACH_ACCIDENTAL_FLAT;
                    case -1: return BACH_ACCIDENTAL_QUARTERFLAT;
                    case 0: return BACH_ACCIDENTAL_NATURAL;
                    case 1: return BACH_ACCIDENTAL_QUARTERSHARP;
                    case 2: return BACH_ACCIDENTAL_SHARP;
                    case 3: return BACH_ACCIDENTAL_THREEQUARTERSHARP;
                    case 4: return BACH_ACCIDENTAL_DOUBLESHARP;
                    default: return BACH_ACCIDENTAL_BOGUS;
                }
            } else
                return BACH_ACCIDENTAL_BOGUS;
        } else if ((r_ob->tone_division == 8) && (r_ob->accidentals_typo_preferences.et_dyadic_depth>=8)) { // eighttone division
            t_rational div = rat_long_prod(accidental,8);
            if (div.r_den == 1) {
                switch (div.r_num) {
                    case -8: return BACH_ACCIDENTAL_DOUBLEFLAT;
                    case -7: return BACH_ACCIDENTAL_THREEQUARTERFLAT_ARROW_DOWN;
                    case -6: return BACH_ACCIDENTAL_THREEQUARTERFLAT;
                    case -5: return BACH_ACCIDENTAL_FLAT_ARROW_DOWN;
                    case -4: return BACH_ACCIDENTAL_FLAT;
                    case -3: return BACH_ACCIDENTAL_QUARTERFLAT_ARROW_DOWN;
                    case -2: return BACH_ACCIDENTAL_QUARTERFLAT;
                    case -1: return BACH_ACCIDENTAL_NATURAL_ARROW_DOWN;
                    case 0: return BACH_ACCIDENTAL_NATURAL;
                    case 1: return BACH_ACCIDENTAL_NATURAL_ARROW_UP;
                    case 2: return BACH_ACCIDENTAL_QUARTERSHARP;
                    case 3: return BACH_ACCIDENTAL_QUARTERSHARP_ARROW_UP;
                    case 4: return BACH_ACCIDENTAL_SHARP;
                    case 5: return BACH_ACCIDENTAL_SHARP_ARROW_UP;
                    case 6: return BACH_ACCIDENTAL_THREEQUARTERSHARP;
                    case 7: return BACH_ACCIDENTAL_THREEQUARTERSHARP_ARROW_UP;
                    case 8: return BACH_ACCIDENTAL_DOUBLESHARP;
                    default: return BACH_ACCIDENTAL_BOGUS;
                }
            } else
                return BACH_ACCIDENTAL_BOGUS;
        } else
            return BACH_ACCIDENTAL_BOGUS;
    }
}


// accidentals must be allocated with MAX_NUM_ACCIDENTALS+1 size
void get_accidentals_for_pitch_ET(t_notation_obj *r_ob, t_pitch p, t_uint8 *accidentals, t_uint8 *numAccidentals)
{
    int j = 0;
    t_rational alter = p.getAlterET();
    if (alter.num() == 0) {
        accidentals[j] = BACH_ACCIDENTAL_NATURAL;
        j = 1;
    } else {
        while (j < CONST_MAX_ACCIDENTALS && alter.num() != 0){
            accidentals[j] = rational_to_accidental_ET(r_ob, alter);
            j++;
            if (alter >= -1 && alter <= 1)
                break; // done
            else
                alter += ((alter > 0) ? -1 : 1);
        }
    }
    if (numAccidentals)
        *numAccidentals = j;
    accidentals[j] = BACH_ACCIDENTAL_NONE;
}


void swap_et_accidentals_for_ji_et(t_uint8 *accidentals, int numAccidentals)
{
    for (long i = 0; i < numAccidentals; i++) {
        switch (accidentals[i]) {
            case BACH_ACCIDENTAL_NATURAL:
                accidentals[i] = BACH_ACCIDENTAL_JI_NATURAL_ET;
                break;
                
            case BACH_ACCIDENTAL_SHARP:
                accidentals[i] = BACH_ACCIDENTAL_JI_SHARP_ET;
                break;
                
            case BACH_ACCIDENTAL_FLAT:
                accidentals[i] = BACH_ACCIDENTAL_JI_FLAT_ET;
                break;
                
            case BACH_ACCIDENTAL_DOUBLESHARP:
                accidentals[i] = BACH_ACCIDENTAL_JI_DOUBLESHARP_ET;
                break;

            case BACH_ACCIDENTAL_DOUBLEFLAT:
                accidentals[i] = BACH_ACCIDENTAL_JI_DOUBLEFLAT_ET;
                break;

            case BACH_ACCIDENTAL_QUARTERFLAT:
                accidentals[i] = BACH_ACCIDENTAL_JI_QUARTERFLAT_ET;
                break;

            case BACH_ACCIDENTAL_QUARTERSHARP:
                accidentals[i] = BACH_ACCIDENTAL_JI_QUARTERSHARP_ET;
                break;

            default:
                break;
        }
    }
}

// accidentals must be allocated with MAX_NUM_ACCIDENTALS+1 size
void get_accidentals_for_pitch_JI(t_notation_obj *r_ob, t_pitch pitch_displayed, t_uint8 *accidentals, t_uint8 *numAccidentals, t_pitch pitch_original)
{
    if ((pitch_displayed.isPureET() && !pitch_displayed.isPureJI()) || 
        pitch_original.isNaP() ||
        (pitch_original.isPureET() && !pitch_original.isPureJI())) {
        // use JI ET characters, the ones with the lines above (but approximate to half tones, though!
        t_pitch q = pitch_displayed.approxET(2);
        t_uint8 n;
        get_accidentals_for_pitch_ET(r_ob, q, accidentals, &n);
        swap_et_accidentals_for_ji_et(accidentals, n);
        if (numAccidentals)
            *numAccidentals = n;
    } else {
        
        std::vector<int8_t> hejicommas = pitch_displayed.getHEJICommas();
        t_uint8 *curChar = accidentals;
        int numChars = 0;
        
        // 3-limit and 5-limit: to do: standard accidental
        long plof_offset = 1 + pitch_displayed.getPlofJI();
        long num_base_accs = (plof_offset - positive_mod(plof_offset, 7)) / 7;
        long num_base_accs_abs = abs(num_base_accs);
        long num_base_accs_sign = (num_base_accs >= 0 ? 1 : -1);
        if (num_base_accs_abs == 0 && hejicommas[0] == 0) { // do I need a natural?
            char need_natural = true; // TODO: we don't want naturals on all notes, do we?
            for (long i = 1; i < BACH_PRIMES_JI_SIZE-2; i++) {
                if (hejicommas[i] != 0) {
                    need_natural = false;
                    break;
                }
            }
            if (need_natural) {
                *curChar = BACH_ACCIDENTAL_JI_NATURAL;
                curChar++;
                numChars ++;
            }
        } else if (num_base_accs_abs == 0 && hejicommas[0] != 0) { // 5-limit
            long hejicomma_abs = abs(hejicommas[0]);
            long hejicomma_sign = (hejicommas[0] >= 0 ? 1 : -1);
            while (hejicomma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS - 1) {
                if (hejicomma_abs >= 3) {
                    *curChar = (hejicomma_sign > 0 ? BACH_ACCIDENTAL_JI_NATURAL_ARROW_UP_THRICE : BACH_ACCIDENTAL_JI_NATURAL_ARROW_DOWN_THRICE);
                    hejicomma_abs -= 3;
                } else if (hejicomma_abs >= 2) {
                    *curChar = (hejicomma_sign > 0 ? BACH_ACCIDENTAL_JI_NATURAL_ARROW_UP_TWICE : BACH_ACCIDENTAL_JI_NATURAL_ARROW_DOWN_TWICE);
                    hejicomma_abs -= 2;
                } else if (hejicomma_abs == 1) {
                    *curChar = (hejicomma_sign > 0 ? BACH_ACCIDENTAL_JI_NATURAL_ARROW_UP : BACH_ACCIDENTAL_JI_NATURAL_ARROW_DOWN);
                    hejicomma_abs -= 1;
                }
                curChar++;
                numChars ++;
            }
        } else {
            long hejicomma_5abs = abs(hejicommas[0]);
            long hejicomma_5sign = (hejicommas[0] >= 0 ? 1 : -1);
            
            while (num_base_accs_abs > 0 && numChars < CONST_MAX_ACCIDENTALS - 1) {
                if (num_base_accs_abs >= 2) {
                    if (hejicomma_5abs > 0) {
                        if (hejicomma_5abs >= 3) {
                            *curChar = (num_base_accs_sign > 0 ? (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_DOUBLESHARP_ARROW_UP_THRICE : BACH_ACCIDENTAL_JI_DOUBLESHARP_ARROW_DOWN_THRICE) : (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_DOUBLEFLAT_ARROW_UP_THRICE : BACH_ACCIDENTAL_JI_DOUBLEFLAT_ARROW_DOWN_THRICE));
                            hejicomma_5abs -= 3;
                        } else if (hejicomma_5abs >= 2) {
                            *curChar = (num_base_accs_sign > 0 ? (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_DOUBLESHARP_ARROW_UP_TWICE : BACH_ACCIDENTAL_JI_DOUBLESHARP_ARROW_DOWN_TWICE) : (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_DOUBLEFLAT_ARROW_UP_TWICE : BACH_ACCIDENTAL_JI_DOUBLEFLAT_ARROW_DOWN_TWICE));
                            hejicomma_5abs -= 2;
                        } else if (hejicomma_5abs == 1) {
                            *curChar = (num_base_accs_sign > 0 ? (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_DOUBLESHARP_ARROW_UP : BACH_ACCIDENTAL_JI_DOUBLESHARP_ARROW_DOWN) : (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_DOUBLEFLAT_ARROW_UP : BACH_ACCIDENTAL_JI_DOUBLEFLAT_ARROW_DOWN));
                            hejicomma_5abs -= 1;
                        }
                    } else {
                        *curChar = (num_base_accs_sign > 0 ? BACH_ACCIDENTAL_JI_DOUBLESHARP : BACH_ACCIDENTAL_JI_DOUBLEFLAT);
                    }
                    curChar++;
                    num_base_accs_abs -= 2;
                } else if (num_base_accs_abs == 1) {
                    if (hejicomma_5abs > 0) {
                        if (hejicomma_5abs >= 3) {
                            *curChar = (num_base_accs_sign > 0 ? (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_SHARP_ARROW_UP_THRICE : BACH_ACCIDENTAL_JI_SHARP_ARROW_DOWN_THRICE) : (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_FLAT_ARROW_UP_THRICE : BACH_ACCIDENTAL_JI_FLAT_ARROW_DOWN_THRICE));
                            hejicomma_5abs -= 3;
                        } else if (hejicomma_5abs >= 2) {
                            *curChar = (num_base_accs_sign > 0 ? (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_SHARP_ARROW_UP_TWICE : BACH_ACCIDENTAL_JI_SHARP_ARROW_DOWN_TWICE) : (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_FLAT_ARROW_UP_TWICE : BACH_ACCIDENTAL_JI_FLAT_ARROW_DOWN_TWICE));
                            hejicomma_5abs -= 2;
                        } else if (hejicomma_5abs == 1) {
                            *curChar = (num_base_accs_sign > 0 ? (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_SHARP_ARROW_UP : BACH_ACCIDENTAL_JI_SHARP_ARROW_DOWN) : (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_FLAT_ARROW_UP : BACH_ACCIDENTAL_JI_FLAT_ARROW_DOWN));
                            hejicomma_5abs -= 1;
                        }
                    } else {
                        *curChar = (num_base_accs_sign > 0 ? BACH_ACCIDENTAL_JI_SHARP : BACH_ACCIDENTAL_JI_FLAT);
                    }
                    curChar++;
                    num_base_accs_abs -= 1;
                }
                numChars ++;
            }
            
            // possibly adding late naturals with arrows
            while (hejicomma_5abs > 0 && numChars < CONST_MAX_ACCIDENTALS - 1) {
                if (hejicomma_5abs >= 3) {
                    *curChar = (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_NATURAL_ARROW_UP_THRICE : BACH_ACCIDENTAL_JI_NATURAL_ARROW_DOWN_THRICE);
                    hejicomma_5abs -= 3;
                } else if (hejicomma_5abs >= 2) {
                    *curChar = (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_NATURAL_ARROW_UP_TWICE : BACH_ACCIDENTAL_JI_NATURAL_ARROW_DOWN_THRICE);
                    hejicomma_5abs -= 2;
                } else if (hejicomma_5abs == 1) {
                    *curChar = (hejicomma_5sign > 0 ? BACH_ACCIDENTAL_JI_NATURAL_ARROW_UP : BACH_ACCIDENTAL_JI_NATURAL_ARROW_DOWN);
                    hejicomma_5abs -= 1;
                }
                curChar++;
                numChars ++;
            }
        }
        
//        t_pitch pppp = t_pitch(genrat(29, 4));
        
        // from 7-limit onwards
        for (long i = 1; i < BACH_PRIMES_JI_SIZE - 1 && numChars < CONST_MAX_ACCIDENTALS; i++) {
            long comma_abs = abs(hejicommas[i]);
            long comma_sign = (hejicommas[i] >= 0 ? 1 : -1);
            if (comma_abs != 0) {
                switch (i) {
                    case 1: // 7-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            if (comma_abs >= 2) {
                                *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_7_UP_TWICE : BACH_ACCIDENTAL_JI_COMMA_7_DOWN_TWICE);
                                curChar++;
                                numChars ++;
                                comma_abs -= 2;
                            } else if (comma_abs == 1) {
                                *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_7_UP : BACH_ACCIDENTAL_JI_COMMA_7_DOWN);
                                curChar++;
                                numChars++;
                                comma_abs -= 1;
                            }
                        }
                        break;
                        
                    case 2: // 11-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_11_UP : BACH_ACCIDENTAL_JI_COMMA_11_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 3: // 13-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_13_UP : BACH_ACCIDENTAL_JI_COMMA_13_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 4: // 17-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_17_UP : BACH_ACCIDENTAL_JI_COMMA_17_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 5: // 19-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_19_UP : BACH_ACCIDENTAL_JI_COMMA_19_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 6: // 23-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_23_UP : BACH_ACCIDENTAL_JI_COMMA_23_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                        
                    case 7: // 29-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_29_UP : BACH_ACCIDENTAL_JI_COMMA_29_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 8: // 31-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_31_UP : BACH_ACCIDENTAL_JI_COMMA_31_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 9: // 37-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_37_UP : BACH_ACCIDENTAL_JI_COMMA_37_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 10: // 41-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_41_UP : BACH_ACCIDENTAL_JI_COMMA_41_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 11: // 43-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_43_UP : BACH_ACCIDENTAL_JI_COMMA_43_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    case 12: // 47-limit
                        while (comma_abs > 0 && numChars < CONST_MAX_ACCIDENTALS) {
                            *curChar = (comma_sign > 0 ? BACH_ACCIDENTAL_JI_COMMA_47_UP : BACH_ACCIDENTAL_JI_COMMA_47_DOWN);
                            curChar++;
                            numChars++;
                            comma_abs -= 1;
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        }
        
        // finally reverse the string
        long temp[CONST_MAX_ACCIDENTALS];
        for (long i = 0; i < numChars; i++)
            temp[i] = accidentals[i];
        for (long i = 0; i < numChars; i++)
            accidentals[numChars - i - 1] = temp[i];
        
        if (numAccidentals)
            *numAccidentals = numChars;
        accidentals[numChars] = BACH_ACCIDENTAL_NONE;
    }
}


bool note_accidental_equals_alter_ET(t_notation_obj *r_ob, t_note *nt, t_shortRational alterET)
{
    if (nt->pitch_displayed.isPureET()) {
        return nt->pitch_displayed.getAlterET() == alterET;
    } else if (nt->pitch_displayed.isPureJI()) {
        return nt->pitch_displayed.isPurePythagorean() && t_shortRational(nt->pitch_displayed.getSharpsJI(), 2) == alterET;
    } else {
        t_pitch p = nt->pitch_displayed.getDisplayPitchAsJI();
        return p.getAlterET() == 0 && p.isPurePythagorean() && t_shortRational(p.getSharpsJI(), 2) == alterET;
    }
}
