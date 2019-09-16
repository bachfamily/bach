/*
 *  score_writexml.cpp
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

#include "score_files.h"
#include "libraries/mxml/mxml.h"
#include <set>


mxml_node_t *bach_mxmlNewTextElement(mxml_node_t *parent, const char *name, int whitespace, const char *string);
mxml_node_t *bach_mxmlNewIntElement(mxml_node_t *parent, const char *name, int whitespace, int value);
mxml_node_t *bach_mxmlNewRealElement(mxml_node_t *parent, const char *name, int whitespace, double value);

void xml_value_to_name(long den, char *chordtype);


mxml_node_t *bach_xml_add_clef(mxml_node_t *node, const char *sign, long line, long octave, const char *number);

void bach_xml_add_ornament(const t_articulations_typo_preferences *atp, mxml_node_t **ornaments, mxml_node_t *notations, long id);


void bach_xml_add_technical_or_articulation(const t_articulations_typo_preferences *atp, mxml_node_t **technical, mxml_node_t **articulations, mxml_node_t *notations, long id, char mode);


t_max_err score_dowritexml(const t_score *x, t_symbol *s, long ac, t_atom *av);


const char *whitespace_cb(mxml_node_t *node, int where);
void strip_final_ws(char *text);


void strip_final_ws(char *text)
{
    char *this_text;
    for (this_text = text + strlen(text) - 1; this_text >= text; this_text--) {
        if (isspace(*this_text))
            *this_text = 0;
        else
            break;
    }
}

const char *whitespace_cb(mxml_node_t *node, int where)
{
    static long prev = MXML_WS_AFTER_CLOSE;
    static char indent[256];
    const char *rv = "";
    static long open_count;
    static long close_count;
    //    static long guard = 6;
    static long ws_lvl = -2;
    //    static long safe = 0;
    /*    if (node) {
     const char *name = mxmlGetElement(node);
     if (!strcmp(name, "dot")) {
     char foo = 0;
     }
     }*/
    
    
    if (where < 0) {
        ws_lvl = -2;
        prev = MXML_WS_AFTER_CLOSE;
        return NULL;
    }
    
    /*    if (ws_lvl > guard) {
     long foo = 0;
     if (safe)
     return "\n      ";
     }*/
    /*
     if (prev == MXML_WS_BEFORE_OPEN && where != MXML_WS_AFTER_OPEN) {
     long foo = 0;
     }
     if (prev == MXML_WS_BEFORE_CLOSE && where != MXML_WS_AFTER_CLOSE) {
     long foo = 0;
     }
     if (where == MXML_WS_AFTER_OPEN && prev != MXML_WS_BEFORE_OPEN) {
     long foo = 0;
     }
     if (where == MXML_WS_AFTER_CLOSE && prev != MXML_WS_BEFORE_CLOSE) {
     long foo = 0;
     }
     */
    
    if (ws_lvl < 0) {
        open_count = 0;
        close_count = 0;
        prev = MXML_WS_AFTER_CLOSE;
        if (where == MXML_WS_BEFORE_OPEN) {
            return ws_lvl++ == -2 ? NULL : "\n";
        } else
            return NULL;
    }
    switch (where) {
        case MXML_WS_BEFORE_OPEN:
            indent[ws_lvl] = ws_lvl == 0 ? '\n' : '\t';
            indent[++ws_lvl] = 0;
            open_count++;
            if (prev == MXML_WS_AFTER_OPEN)
                rv = indent;
            else
                rv = indent + 1;
            break;
        case MXML_WS_AFTER_OPEN:
            rv = "";
            break;
        case MXML_WS_BEFORE_CLOSE:
            if (prev == MXML_WS_AFTER_CLOSE)
                rv = indent + 1;
            else
                rv = "";
            break;
        case MXML_WS_AFTER_CLOSE:
            //indent[ws_lvl] = ' ';
            indent[--ws_lvl] = 0;
            close_count++;
            rv = "\n";
            break;
        default:
            rv = ""; // should never happen
    }
    prev = where;
    return *rv ? rv : NULL;
}


void score_xml_add_clefs(mxml_node_t *attributesxml, long clef, long *staves, long *splitpoints)
{
    // CLEFS
    switch (clef) {
        case k_CLEF_F:
            bach_xml_add_clef(attributesxml, "F", 4, 0, NULL);
            break;
        case k_CLEF_G8va:
            bach_xml_add_clef(attributesxml, "G", 2, 1, NULL);
            break;
        case k_CLEF_G15ma:
            bach_xml_add_clef(attributesxml, "G", 2, 2, NULL);
            break;
        case k_CLEF_F8vb:
            bach_xml_add_clef(attributesxml, "F", 4, -1, NULL);
            break;
        case k_CLEF_F15mb:
            bach_xml_add_clef(attributesxml, "F", 4, -1, NULL);
            break;
        case k_CLEF_SOPRANO:
            bach_xml_add_clef(attributesxml, "C", 5, 0, NULL);
            break;
        case k_CLEF_MEZZO:
            bach_xml_add_clef(attributesxml, "C", 4, 0, NULL);
            break;
        case k_CLEF_ALTO:
            bach_xml_add_clef(attributesxml, "C", 3, 0, NULL);
            break;
        case k_CLEF_TENOR:
            bach_xml_add_clef(attributesxml, "C", 2, 0, NULL);
            break;
        case k_CLEF_BARYTONE:
            bach_xml_add_clef(attributesxml, "C", 1, 0, NULL);
            break;
        case k_CLEF_FF:
            *staves = 2;
            splitpoints[0] = 4000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 2);
            bach_xml_add_clef(attributesxml, "F", 4, 0, "1");
            bach_xml_add_clef(attributesxml, "F", 4, -1, "2");
            break;
        case k_CLEF_FG:
            *staves = 2;
            splitpoints[0] = 6000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 2);
            bach_xml_add_clef(attributesxml, "G", 2, 0, "1");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "2");
            break;
        case k_CLEF_GG:
            *staves = 2;
            splitpoints[0] = 7900;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 2);
            bach_xml_add_clef(attributesxml, "G", 2, 2, "1");
            bach_xml_add_clef(attributesxml, "G", 2, 0, "2");
            break;
        case k_CLEF_FFG:
            *staves = 3;
            splitpoints[0] = 6000;
            splitpoints[1] = 4000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 3);
            bach_xml_add_clef(attributesxml, "G", 2, 0, "1");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "2");
            bach_xml_add_clef(attributesxml, "F", 4, -1, "3");
            break;
        case k_CLEF_FGG:
            *staves = 3;
            splitpoints[0] = 7900;
            splitpoints[1] = 6000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 3);
            bach_xml_add_clef(attributesxml, "G", 2, 1, "1");
            bach_xml_add_clef(attributesxml, "G", 2, 0, "2");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "3");
            break;
        case k_CLEF_FFGG:
            *staves = 4;
            splitpoints[0] = 7900;
            splitpoints[1] = 6000;
            splitpoints[2] = 4000;
            bach_mxmlNewIntElement(attributesxml, "staves", 0, 4);
            bach_xml_add_clef(attributesxml, "G", 2, 1, "1");
            bach_xml_add_clef(attributesxml, "G", 2, 0, "2");
            bach_xml_add_clef(attributesxml, "F", 4, 0, "3");
            bach_xml_add_clef(attributesxml, "F", 4, -1, "4");
            break;
        case k_CLEF_G:
        default:
            bach_xml_add_clef(attributesxml, "G", 2, 0, "1");
            break;
    }
}



void score_exportxml(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom av;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    atom_setobj(&av, arguments);
    defer(x, (method)score_dowritexml, s, 1, &av);
}


mxml_node_t *bach_mxmlNewTextElement(mxml_node_t *parent, const char *name, int whitespace, const char *string)
{
    mxml_node_t *node = mxmlNewElement(parent, name);
    mxmlNewText(node, whitespace, string);
    return node;
}



mxml_node_t *bach_mxmlNewIntElement(mxml_node_t *parent, const char *name, int whitespace, int value)
{
    mxml_node_t *node = mxmlNewElement(parent, name);
    mxmlNewInteger(node, value);
    return node;
}

mxml_node_t *bach_mxmlNewRealElement(mxml_node_t *parent, const char *name, int whitespace, double value)
{
    mxml_node_t *node = mxmlNewElement(parent, name);
    mxmlNewReal(node, value);
    return node;
}




void xml_value_to_name(long den, char *chordtype)
{
    switch (den) {
        case 1:        strcpy(chordtype, "whole");                break;
        case 2:        strcpy(chordtype, "half");                break;
        case 4:        strcpy(chordtype, "quarter");            break;
        case 8:        strcpy(chordtype, "eighth");            break;
        case 32:    strcpy(chordtype, "32nd");                break;
        default:    sprintf(chordtype, "%ldth", den);
            break;
    }
}



mxml_node_t *bach_xml_add_clef(mxml_node_t *node, const char *sign, long line, long octave, const char *number)
{
    mxml_node_t *clefxml = mxmlNewElement(node, "clef");
    bach_mxmlNewTextElement(clefxml, "sign", 0, sign);
    bach_mxmlNewIntElement(clefxml, "line", 0, line);
    if (octave)
        bach_mxmlNewIntElement(clefxml, "clef-octave-change", 0, octave);
    if (number)
        mxmlElementSetAttr(clefxml, "number", number);
    return clefxml;
}


void bach_xml_add_ornament(const t_articulations_typo_preferences *atp, mxml_node_t **ornaments, mxml_node_t *notations, long id)
{
    if (*ornaments == NULL)
        *ornaments = mxmlNewElement(notations, "ornaments");
    
    if (id >= k_NUM_STANDARD_ARTICULATIONS) {
        // nonstandard
        if (atp->artpref[id].xmlornament && atp->artpref[id].xmlornament != _llllobj_sym_none)
            mxmlNewElement(*ornaments, atp->artpref[id].xmlornament->s_name);
        return;
    }
    
    // standard
    switch (id) {
        case k_ARTICULATION_TRILL:
            mxmlNewElement(*ornaments, "trill-mark");
            break;
        case k_ARTICULATION_TRILL_FLAT:
        case k_ARTICULATION_TRILL_SHARP:
            mxmlNewElement(*ornaments, "trill-mark");
            bach_mxmlNewTextElement(notations, "accidental-mark", 0, id == k_ARTICULATION_TRILL_FLAT ? "flat" : "sharp");
            *ornaments = mxmlNewElement(notations, "ornaments");
            break;
        case k_ARTICULATION_MORDENT_DOWN:
            mxmlNewElement(*ornaments, "mordent");
            break;
        case k_ARTICULATION_MORDENT_UP:
            mxmlNewElement(*ornaments, "inverted-mordent");
            break;
        case k_ARTICULATION_DOUBLE_MORDENT:
            mxmlNewElement(*ornaments, "wavy-line");
            break;
        case k_ARTICULATION_GRUPPETTO:
            mxmlNewElement(*ornaments, "turn");
            break;
        case k_ARTICULATION_TREMOLO3:
            bach_mxmlNewIntElement(*ornaments, "tremolo", 0, 3);
            break;
        case k_ARTICULATION_TREMOLO2:
            bach_mxmlNewIntElement(*ornaments, "tremolo", 0, 2);
            break;
        case k_ARTICULATION_TREMOLO1:
            bach_mxmlNewIntElement(*ornaments, "tremolo", 0, 1);
            break;
    }
}



void bach_xml_set_custom_articulation_attributes(const t_articulations_typo_preferences *atp, mxml_node_t *node, long articulation_id)
{
    if (atp->artpref[articulation_id].font)
        mxmlElementSetAttr(node, "font-family", atp->artpref[articulation_id].font->s_name);
    
    {
        char size[256];
        snprintf_zero(size, 256, "%ld", (long)round(atp->artpref[articulation_id].base_pt));
        mxmlElementSetAttr(node, "font-size", size);
    }
    
    if (atp->artpref[articulation_id].positioning & k_ARTICULATION_POSITIONING_ABOVE_NOTE)
        mxmlElementSetAttr(node, "placement", "above");
    else if (atp->artpref[articulation_id].positioning & k_ARTICULATION_POSITIONING_BELOW_NOTE)
        mxmlElementSetAttr(node, "placement", "below");
    
    // TO BE BETTER IMPLEMENTED: export custom positioning
}



// "other-articulation" and "other-technical" seem to have to be the LAST elements in the list. Hence, we deal with standard ones before
// mode = 1 standard only, mode = 2 nonstandard only
void bach_xml_add_technical_or_articulation(const t_articulations_typo_preferences *atp, mxml_node_t **technical, mxml_node_t **articulations, mxml_node_t *notations, long id, char mode)
{
    if (id >= k_NUM_STANDARD_ARTICULATIONS) {
        // nonstandard
        if (atp->artpref[id].xmltechnical && atp->artpref[id].xmltechnical != _llllobj_sym_none) {
            if (atp->artpref[id].xmltechnical == gensym("custom") || atp->artpref[id].xmltechnical == gensym("other-technical")) {
                if (mode != 1) {
                    char *buf = articulation_to_text_buf((t_articulations_typo_preferences *)atp, id);
                    if (*technical == NULL)
                        *technical = mxmlNewElement(notations, "technical");
                    bach_xml_set_custom_articulation_attributes(atp, bach_mxmlNewTextElement(*technical, "other-technical", 0, buf), id);
                    bach_freeptr(buf);
                }
            } else {
                if (mode != 2) {
                    if (*technical == NULL)
                        *technical = mxmlNewElement(notations, "technical");
                    mxmlNewElement(*technical, atp->artpref[id].xmltechnical->s_name);
                }
            }
        }
        if (atp->artpref[id].xmlarticulations && atp->artpref[id].xmlarticulations != _llllobj_sym_none) {
            if (atp->artpref[id].xmlarticulations == gensym("custom") || atp->artpref[id].xmlarticulations == gensym("other-articulation")) {
                if (mode != 1) {
                    char *buf = articulation_to_text_buf((t_articulations_typo_preferences *)atp, id);
                    if (*articulations == NULL)
                        *articulations = mxmlNewElement(notations, "articulations");
                    bach_xml_set_custom_articulation_attributes(atp, bach_mxmlNewTextElement(*articulations, "other-articulation", 0, buf), id);
                    bach_freeptr(buf);
                }
            } else {
                if (mode != 2) {
                    if (*articulations == NULL)
                        *articulations = mxmlNewElement(notations, "articulations");
                    mxmlNewElement(*articulations, atp->artpref[id].xmlarticulations->s_name);
                }
            }
        }
        return;
    }
    
    if (mode == 2)
        return;
    
    switch (id) {
        case k_ARTICULATION_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "staccato");
            break;
        case k_ARTICULATION_ACCENT:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "accent");
            break;
        case k_ARTICULATION_PORTATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "tenuto");
            break;
        case k_ARTICULATION_ACCENT_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "accent");
            mxmlNewElement(*articulations, "staccato");
            break;
        case k_ARTICULATION_ACCENT_PORTATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "accent");
            mxmlNewElement(*articulations, "tenuto");
            break;
        case k_ARTICULATION_PORTATO_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "tenuto");
            mxmlNewElement(*articulations, "staccato");
            break;
        case k_ARTICULATION_STACCATISSIMO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "staccatissimo");
            break;
        case k_ARTICULATION_MARTELLATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "spiccato");
            break;
        case k_ARTICULATION_MARTELLATO_STACCATO:
            if (*articulations == NULL)
                *articulations = mxmlNewElement(notations, "articulations");
            mxmlNewElement(*articulations, "spiccato");
            mxmlNewElement(*articulations, "staccato");
            break;
        case k_ARTICULATION_HARMONIC:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            mxmlNewElement(*technical, "harmonic");
            break;
        case k_ARTICULATION_LEFT_HAND_PIZZICATO:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            bach_mxmlNewTextElement(*technical, "tap", 0, "+");
            break;
        case k_ARTICULATION_BOWING_UP:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            mxmlNewElement(*technical, "up-bow");
            break;
        case k_ARTICULATION_BOWING_DOWN:
            if (*technical == NULL)
                *technical = mxmlNewElement(notations, "technical");
            mxmlNewElement(*technical, "down-bow");
            break;
    }
}



const char *bach_xml_acc2name(t_rational acc, long *mc_alter)
{
    const char *acc_name;
    long dummy_alter;
    if (!mc_alter)
        mc_alter = &dummy_alter;
    if (acc.r_num == 0) {
        acc_name = "natural";
        *mc_alter = 0;
    } else if (acc.r_num == 1 && acc.r_den == 4) {
        acc_name = "quarter-sharp";
        *mc_alter = 50;
    } else if (acc.r_num == 1 && acc.r_den == 2) {
        acc_name = "sharp";
        *mc_alter = 100;
    } else if (acc.r_num == 3 && acc.r_den == 4) {
        acc_name = "three-quarter-sharp";
        *mc_alter = 150;
    } else if (acc.r_num == 2 && acc.r_den == 1) {
        acc_name = "double-sharp";
        *mc_alter = 200;
    } else if (acc.r_num == - 1 && acc.r_den == 4) {
        acc_name = "quarter-flat";
        *mc_alter = 50;
    } else if (acc.r_num == -1 && acc.r_den == 2) {
        acc_name = "flat";
        *mc_alter = 100;
    } else if (acc.r_num == -3 && acc.r_den == 4) {
        acc_name = "three-quarter-flat";
        *mc_alter = 150;
    } else if (acc.r_num == -2 && acc.r_den == 1) {
        acc_name = "double-flat";
        *mc_alter = 200;
    } else {
        acc_name = "unknown";
        *mc_alter = 0;
    }
    return acc_name;
}

bool is_xml_dynamic(t_symbol* sym) {
    static const char *supported[] = {
        "p", "pp", "ppp", "pppp", "ppppp", "pppppp", "f", "ff", "fff", "ffff", "fffff", "ffffff", "mp", "mf", "sf", "sfp", "sfpp", "fp", "rf", "rfz", "sfz", "sffz", "fz"
    };
    static constexpr char n = sizeof(supported) / sizeof(supported[0]);
    for (int i = 0; i < n; i++) {
        if (gensym(supported[i]) == sym)
            return true;
    }
    return false;
}

bool xml_open_hairpin(mxml_node_t* directionxml, const char* type)
{
    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
    mxml_node_t *wedgexml = mxmlNewElement(direction_typexml, "wedge");
    mxmlElementSetAttr(wedgexml, "relative-x", "10");
    mxmlElementSetAttr(wedgexml, "type", type);
    return true;
}

bool xml_close_hairpin(mxml_node_t* directionxml)
{
    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
    mxml_node_t *wedgexml = mxmlNewElement(direction_typexml, "wedge");
    mxmlElementSetAttr(wedgexml, "relative-x", "-10");
    mxmlElementSetAttr(wedgexml, "type", "stop");
    return false;
}

t_max_err score_dowritexml(const t_score *x, t_symbol *s, long ac, t_atom *av)
{
    long err = MAX_ERR_NONE;
    long partidx, measureidx;
    long divisions, midicents = 0;
    long isfirstnote;
    t_fourcc filetype = 'MXML', outtype;
    char measurenum[256];
    char *stafftxt;
    t_symbol *filename_sym = NULL;
    t_scorevoice *voice;
    t_measure *measure;
    t_chord *chord;
    t_note *note;
    t_llll *export_slots = NULL;
    long export_velocities = 0, export_noteheads = 1, export_lyrics = 1, export_dynamics = 1, export_articulations = 1, export_glissandi = 0;
    long dynamics_slot = x->r_ob.link_dynamics_to_slot;
    long articulations_slot = x->r_ob.link_articulations_to_slot;
    const t_articulations_typo_preferences *atp = &x->r_ob.articulations_typo_preferences;
    long parenthesized_quartertones = 0;
    t_llll *arguments = (t_llll *) atom_getobj(av);
    t_slotitem *slotitem;
    
    llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siilliiiiii",
                                         _sym_filename, &filename_sym,
                                         gensym("dynamicsslot"), &dynamics_slot,
                                         gensym("velocity"), &export_velocities,
                                         gensym("directionslots"), &export_slots,
                                         gensym("directionsslots"), &export_slots,
                                         gensym("parenthesizedquartertones"), &parenthesized_quartertones,
                                         gensym("articulations"), &export_articulations,
                                         gensym("lyrics"), &export_lyrics,
                                         gensym("noteheads"), &export_noteheads,
                                         gensym("dynamics"), &export_dynamics,
                                         gensym("glissandi"), &export_glissandi
                                         );
    
    if (!export_slots)
        llll_appendlong(export_slots, x->r_ob.link_annotation_to_slot);
    
    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_destroyelem(arguments->l_head);
    }
    
    
    llll_free(arguments);
    
    if (!export_articulations)
        articulations_slot = 0;
    if (!export_dynamics)
        dynamics_slot = 0;
    
    whitespace_cb(NULL, -1);
    mxmlSetWrapMargin(1000);
    long numvoices = x->r_ob.num_voices;
    
    mxml_node_t *scorexml = mxmlNewXML("1.0");
    mxmlNewElement(scorexml, "!DOCTYPE score-partwise PUBLIC \"-//Recordare//DTD MusicXML 3.0 Partwise//EN\"\n\"http://www.musicxml.org/dtds/partwise.dtd\" ");
    mxml_node_t *scorepartwisexml = mxmlNewElement(scorexml, "score-partwise");
    mxmlElementSetAttr(scorepartwisexml, "version", "3.0");
    
    
    // Adding identification
    char bachversiontxt[512];
    char datetxt[512];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf_zero(bachversiontxt, 512, "bach for Max %s", bach_get_current_version_string_verbose());
    snprintf_zero(datetxt, 512, "%.4d-%.2d-%.2d", tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday);
    mxml_node_t *identificationxml = mxmlNewElement(scorepartwisexml, "identification");
    mxml_node_t *encodingxml = mxmlNewElement(identificationxml, "encoding");
    bach_mxmlNewTextElement(encodingxml, "software", 0, bachversiontxt);
    bach_mxmlNewTextElement(encodingxml, "encoding-date", 0, datetxt);
    
    mxml_node_t *defaults = mxmlNewElement(scorepartwisexml, "defaults");
    mxml_node_t *wordfont = mxmlNewElement(defaults, "word-font");
    mxmlElementSetAttr(wordfont, "font-family", "Times New Roman");
    mxmlElementSetAttr(wordfont, "font-size", "11");
    
    mxml_node_t *partlistxml = mxmlNewElement(scorepartwisexml, "part-list");
    
    lock_general_mutex((t_notation_obj *)x);
    
    // prepare the slot export
    t_llllelem *this_slotnum_elem, *next_elem;
    if (!export_slots)
        export_slots = llll_get();
    
    t_llll *developed = llll_develop_ranges(export_slots);
    llll_free(export_slots);
    export_slots = developed;
    
    for (this_slotnum_elem = export_slots->l_head; this_slotnum_elem; this_slotnum_elem = next_elem) {
        next_elem = this_slotnum_elem->l_next;
        t_atom_long *this_slotnum = &this_slotnum_elem->l_hatom.h_w.w_long; // llll_develop_ranges returned a list composed solely of H_LONGs
        if (*this_slotnum < 1 || *this_slotnum > CONST_MAX_SLOTS) {
            if (*this_slotnum != 0) // 0 means don't set, no warning should be given
                object_warn((t_object *) x, "Slot %ld does not exist", *this_slotnum);
            llll_destroyelem(this_slotnum_elem);
        } else {
            t_slotinfo *this_slot_info = &x->r_ob.slotinfo[(*this_slotnum) - 1];
            long slot_type = this_slot_info->slot_type;
            if (slot_type == k_SLOT_TYPE_NONE) {
                object_warn((t_object *) x, "Slot %ld is of type none", *this_slotnum);
                llll_destroyelem(this_slotnum_elem);
            } else /* if (slot_type != k_SLOT_INT ||
                    slot_type != k_SLOT_FLOAT ||
                    slot_type != k_SLOT_INTLIST ||
                    slot_type != k_SLOT_FLOATLIST ||
                    slot_type != k_SLOT_TEXT ||
                    slot_type != k_SLOT_LLLL) {
                    object_warn((t_object *) score, "slot %ld is unsupported for export", *this_slotnum);
                    llll_destroyelem(this_slotnum_elem);
                    } else */
                (*this_slotnum)--;
        }
    }
    
    //////////////////
    // prepare the dynamics slot
    //////////////////
    char dynamics_slot_is_text = false;
    if (dynamics_slot > 0) {
        if (dynamics_slot > CONST_MAX_SLOTS) {
            object_warn((t_object *) x, "Slot %ld does not exist", dynamics_slot);
            dynamics_slot = 0;
        } else {
            t_slotinfo *this_slot_info = &x->r_ob.slotinfo[dynamics_slot - 1];
            long slot_type = this_slot_info->slot_type;
            if (slot_type == k_SLOT_TYPE_NONE) {
                object_warn((t_object *) x, "Slot %ld is of type none", dynamics_slot);
                dynamics_slot = 0;
            } else if (slot_type != k_SLOT_TYPE_TEXT && slot_type != k_SLOT_TYPE_DYNAMICS) {
                object_warn((t_object *) x, "Requested dynamics slot is not of type dynamics or text", dynamics_slot);
                dynamics_slot = 0;
            }
            if (slot_type == k_SLOT_TYPE_TEXT)
                dynamics_slot_is_text = true;
        }
    }
    dynamics_slot --;
    
    //////////////////
    // checking articulations slot
    //////////////////
    if (articulations_slot > 0) {
        if (articulations_slot > CONST_MAX_SLOTS) {
            object_warn((t_object *) x, "Slot %ld does not exist", articulations_slot);
            articulations_slot = 0;
        } else {
            t_slotinfo *this_slot_info = &x->r_ob.slotinfo[articulations_slot - 1];
            long slot_type = this_slot_info->slot_type;
            if (slot_type == k_SLOT_TYPE_NONE) {
                object_warn((t_object *) x, "Slot %ld is of type none", articulations_slot);
                articulations_slot = 0;
            } else if (slot_type != k_SLOT_TYPE_ARTICULATIONS) {
                object_warn((t_object *) x, "Requested articulations slot is not of type articulation", articulations_slot);
                articulations_slot = 0;
            }
        }
    }
    articulations_slot --;
    
    t_llll *numparts_llll = get_numparts_as_llll((t_notation_obj *) x);
    t_llllelem *numparts_elem = numparts_llll->l_head; // first elem is "numparts"
    long voices_left_in_voiceensemble;
    t_llllelem *this_voice_ensemble_measure;
    t_bool new_voice_ensemble = true;
    
    partidx = 1;
    long voiceidx;
    for (voice = x->firstvoice, voiceidx = 1;
         voice && voiceidx <= numvoices;
         voice = voice->next, voiceidx++) {
        char id[32];
        char *nametxt = NULL;
        long textsize = 0;
        
        if (new_voice_ensemble) {
            numparts_elem = numparts_elem->l_next;

            voices_left_in_voiceensemble = hatom_getlong(&numparts_elem->l_hatom);
            
            mxml_node_t *partxml = mxmlNewElement(partlistxml, "score-part");
            
            t_atom *names = NULL;
            long name_ac = 0;
            if (voice->v_ob.r_it.names->l_size != 0) {
                name_ac = llll_deparse(voice->v_ob.r_it.names, &names, 0, 0);
            }
            
            snprintf_zero(id, 32, "P%ld", partidx);
            mxmlElementSetAttr(partxml, "id", id);
            
            if (name_ac == 0 || (atom_gettype(&names[0]) == A_SYM && atom_getsym(&names[0]) == _llllobj_sym_abr_none_abr)) {
                nametxt = (char *) sysmem_newptr(1);
                *nametxt = 0;
            } else
                atom_gettext(name_ac, names, &textsize, &nametxt,
                             OBEX_UTIL_ATOM_GETTEXT_TRUNCATE_ZEROS |
                             OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE |
                             OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
            
            // nametxt = "dummy";
            
            bach_mxmlNewTextElement(partxml, "part-name", 0, nametxt);
            sysmem_freeptr(nametxt); // COMMENT THIS IF REVERTING TO OLD VERSION!
            mxml_node_t *score_instrument = mxmlNewElement(partxml, "score-instrument");
            snprintf_zero(id, 32, "P%ld-I%ld", partidx, partidx);
            mxmlElementSetAttr(score_instrument, "id", id);
            bach_mxmlNewTextElement(score_instrument, "instrument-name", 0, "Grand Piano");
            
            bach_freeptr(names);
        }
        
        --voices_left_in_voiceensemble;
        
        if (voices_left_in_voiceensemble == 0) {
            partidx++;
            new_voice_ensemble = true;
        } else {
            new_voice_ensemble = false;
        }
    }
    
    
    //////////////////
    //////////////////
    // here we export the body of the score
    //////////////////
    //////////////////
    
    //////////////////
    // first, pass through all the score to calculate a value of the division attribute that is valid for every measure
    // this is not very elegant, but makes things much simpler with voice ensembles
    //////////////////
    divisions = 16;
    for (voiceidx = 1, voice = x->firstvoice;
         voice && voiceidx <= numvoices;
         voiceidx++, voice = voice->next) {
        for (measure = voice->firstmeasure; measure; measure = measure->next) {
            for (chord = measure->firstchord; chord; chord = chord->next) {
                divisions = lcm(divisions, chord->r_sym_duration.r_den);
            }
        }
    }
    
    t_llll *voice_ensemble_measures = llll_get();
    
    numparts_elem = numparts_llll->l_head;
    new_voice_ensemble = true;
    
    partidx = 1;
    for (voiceidx = 1, voice = x->firstvoice; voice && voiceidx <= numvoices; voiceidx++, voice = voice->next) {
        t_timesignature *ts = NULL;
        long clef;
        mxml_node_t *partxml;
        t_llll *open_gliss = export_glissandi ? llll_get() : NULL;
        
        if (new_voice_ensemble) {
            char part_id[16];
            clef = voice->v_ob.clef;
            partxml = mxmlNewElement(scorepartwisexml, "part");
            snprintf_zero(part_id, 16, "P%ld", partidx);
            mxmlElementSetAttr(partxml, "id", part_id);
            
            numparts_elem = numparts_elem->l_next;
            voices_left_in_voiceensemble = hatom_getlong(&numparts_elem->l_hatom);
        }
        stafftxt = NULL;
        long staves = 1;
        long splitpoints[3];
        
        bool currently_open_hairpin = false;
        bool currently_ongoing_lyrics_syllable = false;
        mxml_node_t *measurexml;

        for (measureidx = 1,
             measure = voice->firstmeasure,
             this_voice_ensemble_measure = voice_ensemble_measures->l_head;
             
             measure;
             
             measureidx++,
             measure = measure->next,
             this_voice_ensemble_measure = this_voice_ensemble_measure ? this_voice_ensemble_measure->l_next : NULL) {
            
            if (new_voice_ensemble || !this_voice_ensemble_measure) {
                measurexml = mxmlNewElement(partxml, "measure");
                if (voices_left_in_voiceensemble > 1)
                    this_voice_ensemble_measure = llll_appendobj(voice_ensemble_measures, measurexml);
                
                snprintf_zero(measurenum, 256, "%ld", measureidx);
                mxmlElementSetAttr(measurexml, "number", measurenum);
                
                // measure attributes
                mxml_node_t *attributesxml = mxmlNewElement(measurexml, "attributes");
                
                /*
                 // divisions (lcm of duration denominators)
                 divisions = 16;
                 for (chord = measure->firstchord; chord; chord = chord->next) {
                 divisions = lcm(divisions, chord->r_sym_duration.r_den);
                 }
                 */
                
                bach_mxmlNewIntElement(attributesxml, "divisions", 0, divisions / 4);
                
                // key signature
                if (measureidx == 1) {
                    mxml_node_t *keyxml = mxmlNewElement(attributesxml, "key");
                    if (voice->v_ob.mode != k_MODE_NONSTANDARD) {
                        bach_mxmlNewIntElement(keyxml, "fifths", 0, voice->v_ob.key);
                        bach_mxmlNewTextElement(keyxml, "mode", 0, voice->v_ob.mode == k_MODE_MAJOR ? "major" : "minor");
                    } else {
                        long i;
                        for (i = 0; i < 7; i++) {
                            t_rational pattern = voice->v_ob.acc_pattern[i];
                            if (pattern.r_num != 0) {
                                char stepname[2];
                                stepname[0] = 'A' + (i + 2) % 7;
                                stepname[1] = 0;
                                bach_mxmlNewTextElement(keyxml, "key-step", 0, stepname);
                                bach_mxmlNewRealElement(keyxml, "key-alter", 0, rat2double(pattern) * 2.);
                                bach_mxmlNewTextElement(keyxml, "key-accidental", 0, bach_xml_acc2name(pattern, NULL));
                            }
                        }
                    }
                    
                }
                
                // time signature
                if (measureidx == 1 || !ts_are_equal(ts, &measure->timesignature)) {
                    ts = &measure->timesignature;
                    mxml_node_t *timexml = mxmlNewElement(attributesxml, "time");
                    
                    if (ts->num_numerator_elements == 1) { // simple time signature
                        bach_mxmlNewIntElement(timexml, "beats", 0, ts->numerator);
                        bach_mxmlNewIntElement(timexml, "beat-type", 0, ts->denominator);
                    } else { // composite time signature
                        long i;
                        for (i = 0; i < ts->num_numerator_elements; i++) {
                            bach_mxmlNewIntElement(timexml, "beats", 0, ts->numerator_elements[i]);
                            bach_mxmlNewIntElement(timexml, "beat-type", 0, ts->denominator);
                        }
                    }
                }
                
                if (measureidx == 1) {
                    score_xml_add_clefs(attributesxml, clef, &staves, splitpoints);
                }
                
                // tempo
                t_tempo *tempo;
                for (tempo = measure->firsttempo; tempo; tempo = tempo->next) {
                    char tempo_figure_txt[16], tempo_txt[16];
                    mxml_node_t *directionxml = mxmlNewElement(measurexml, "direction");
                    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
                    mxml_node_t *metronomexml = mxmlNewElement(direction_typexml, "metronome");
                    t_rational screen_tempo_figure;
                    char tempo_figure_num_dots;
                    if (is_duration_drawable((t_notation_obj *) x, tempo->tempo_figure, &screen_tempo_figure, &tempo_figure_num_dots)) {
                        xml_value_to_name(screen_tempo_figure.r_den, tempo_figure_txt);
                        bach_mxmlNewTextElement(metronomexml, "beat-unit", 0, tempo_figure_txt);
                        char i;
                        for (i = 0; i < tempo_figure_num_dots; i++)
                            mxmlNewElement(metronomexml, "beat-unit-dot");
                        if (tempo->tempo_value.r_den == 1)
                            bach_mxmlNewIntElement(metronomexml, "per-minute", 0, tempo->figure_tempo_value.r_num);
                        else
                            bach_mxmlNewRealElement(metronomexml, "per-minute", 0, rat2double(tempo->figure_tempo_value));
                    } else {
                        bach_mxmlNewTextElement(metronomexml, "beat-unit", 0, "quarter");
                        if (tempo->tempo_value.r_den == 1)
                            bach_mxmlNewIntElement(metronomexml, "per-minute", 0, tempo->tempo_value.r_num);
                        else
                            bach_mxmlNewRealElement(metronomexml, "per-minute", 0, rat2double(tempo->tempo_value));
                    }
                    mxml_node_t *offsetxml = mxmlNewElement(directionxml, "offset");
                    mxmlElementSetAttr(offsetxml, "sound", "yes");
                    mxmlNewInteger(offsetxml, tempo->changepoint.r_num * divisions / tempo->changepoint.r_den);
                    mxml_node_t *soundxml = mxmlNewElement(directionxml, "sound");
                    snprintf_zero(tempo_txt, 16, "%lf", rat2double(tempo->tempo_value));
                    mxmlElementSetAttr(soundxml, "tempo", tempo_txt);
                }
                
            } else {
                measurexml = (mxml_node_t *) hatom_getobj(&this_voice_ensemble_measure->l_hatom);
                t_rational dur = measure_get_sym_duration(measure);
                t_atom_long backup = dur * divisions;
                mxml_node_t *backupxml = mxmlNewElement(measurexml, "backup");
                bach_mxmlNewIntElement(backupxml, "duration", 0, backup);
            }
            
            // chords
            for (chord = measure->firstchord; chord; chord = chord->next) {
                
                // dynamics
                if (chord_has_dynamics(chord)) {
                    mxml_node_t *directionxml = NULL;
                    t_dynamics *dyn = chord_get_dynamics(chord);
                    if (dyn) {
                        t_rational dyndur = dynamics_get_symduration((t_notation_obj *) x, dyn);
                        double last_offset = -1.;
                        for (t_dynamics_mark* mark = dyn->firstmark;
                             mark;
                             mark = mark->next) {
                            double new_offset;
                            switch (mark->dynamics_mark_attachment) {
                                case k_DYNAMICS_MARK_ATTACHMENT_SNAPTOBPT: {
                                    t_bpt *bpt = dynamics_mark_get_breakpoint(dyn, mark);
                                    new_offset = bpt->rel_x_pos;
                                    break;
                                }
                                default: {
                                    new_offset = mark->relative_position;
                                    break;
                                }
                            }
                            
                            if (new_offset != last_offset) {
                                directionxml = mxmlNewElement(measurexml, "direction");
                                mxmlElementSetAttr(directionxml, "placement", "below");
                            }
                            
                            if (currently_open_hairpin) {
                                currently_open_hairpin = xml_close_hairpin(directionxml);
                            }
                            
                            long nw = mark->num_words;
                            for (int i = 0; i < nw; i++) {
                                if (currently_open_hairpin) {
                                    currently_open_hairpin = xml_close_hairpin(directionxml);
                                }
                                t_symbol *sym = mark->text_deparsed[i];
                                if (is_xml_dynamic(sym)) {
                                    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
                                    mxml_node_t *dynamicsxml = mxmlNewElement(direction_typexml, "dynamics");
                                    mxmlNewElement(dynamicsxml, sym->s_name);
                                } else if (sym != gensym("|") && sym != gensym("=")) {
                                    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
                                    if (!mark->is_roman) {
                                        mxml_node_t *dynamicsxml = mxmlNewElement(direction_typexml, "dynamics");
                                        bach_mxmlNewTextElement(dynamicsxml, "other-dynamics", 0, sym->s_name);
                                    } else {
                                        mxml_node_t *wordsxml;
                                        if (i > 0) { // if it's not the first mark of this group
                                            char wordstxt[2048];
                                            snprintf_zero(wordstxt, 2048, " %s", sym->s_name);
                                            wordsxml = bach_mxmlNewTextElement(direction_typexml, "words", 0, wordstxt);
                                        } else {
                                            wordsxml = bach_mxmlNewTextElement(direction_typexml, "words", 0, sym->s_name);
                                        }
                                        mxmlElementSetAttr(wordsxml, "font-style", "italic");
                                    }
                                }
                            }
                            
                            switch (mark->hairpin_to_next) {
                                case k_DYNAMICS_HAIRPIN_DIM:
                                case k_DYNAMICS_HAIRPIN_DIMEXP:
                                case k_DYNAMICS_HAIRPIN_DIMDASHED: {
                                    currently_open_hairpin = xml_open_hairpin(directionxml, "diminuendo");
                                    break;
                                }
                                case k_DYNAMICS_HAIRPIN_CRESC:
                                case k_DYNAMICS_HAIRPIN_CRESCEXP:
                                case k_DYNAMICS_HAIRPIN_CRESCDASHED: {
                                    currently_open_hairpin = xml_open_hairpin(directionxml, "crescendo");
                                    break;
                                }
                            }
                            
                            if (new_offset != last_offset) {
                                
                                long xmloffset = round((dyndur * divisions).num() * new_offset);
                                if (xmloffset != 0) {
                                    bach_mxmlNewIntElement(directionxml, "offset", 0, xmloffset);
                                }
                                last_offset = new_offset;
                                
                            }
                            
                        }
                        
                    }
                }

                long is_rest, is_grace;
                t_xml_chord_beam_info beam_info;
                t_xml_chord_tuplet_info tuplet_info[CONST_MAX_XML_NESTED_TUPLETS];
                long num_tuplets;
                long num_dots = chord->num_dots;
                char chordtype[16], normal_type[16];
                t_rational screen_accidental;
                t_llll *open_gliss_chord = export_glissandi ? llll_get() : NULL;
                char at_least_a_gliss_has_ended = false;
                xml_value_to_name(chord->figure.r_den, chordtype);
                t_rational dur = chord->r_sym_duration;
                char durtxt[16];

                if (dur.r_num < 0) {
                    dur.r_num *= -1;
                    is_rest = 1;
                } else
                    is_rest = 0;
                
                is_grace = chord->is_grace_chord;
                
                snprintf_zero(durtxt, 16, "%ld", dur.r_num * divisions / dur.r_den);
                
                beam_info = get_xml_chord_beam_info((t_notation_obj *) x, chord);
                num_tuplets = get_xml_chord_tuplet_info((t_notation_obj *) x, chord, tuplet_info);
                
                if (num_tuplets)
                    xml_value_to_name(tuplet_info[0].tuplet_actual_type.r_den, normal_type);
                
                
                // cycle on notes
                for (isfirstnote = 1, note = chord->firstnote; isfirstnote || note; isfirstnote = 0, note = note ? note->next : NULL) {
                    
                    // velocity and slots
                    if (note) {
                        
                        if (export_velocities) {
                            mxml_node_t *soundxml = NULL;
                            mxml_node_t *directionxml = mxmlNewElement(measurexml, "direction");
                            soundxml = mxmlNewElement(directionxml, "sound");
                            char dynamics_txt[16];
                            snprintf_zero(dynamics_txt, 16, "%lf", (double) (note->velocity * 100. / 90.));
                            mxmlElementSetAttr(soundxml, "dynamics", dynamics_txt);
                        }
                        
                        for (this_slotnum_elem = export_slots->l_head; this_slotnum_elem; this_slotnum_elem = this_slotnum_elem->l_next) {
                            long slotnum = hatom_getlong(&this_slotnum_elem->l_hatom);
                            t_llll *slot_contents = note_get_single_slot_values_as_llll((t_notation_obj *) x, note, k_CONSIDER_FOR_DUMPING, slotnum, false);
                            t_bool single = x->r_ob.slotinfo[slotnum].slot_singleslotfortiednotes;
                            if (slot_contents->l_size > 1 && !(note->tie_from && single)) {
                                llll_destroyelem(slot_contents->l_head);
                                char *text = NULL;
                                llll_to_text_buf(slot_contents, &text, 0, 10, LLLL_T_NONE, LLLL_TE_NONE, LLLL_TB_SPECIAL, NULL);
                                if (*text) {
                                    mxml_node_t *directionxml = mxmlNewElement(measurexml, "direction");
                                    mxml_node_t *direction_typexml = mxmlNewElement(directionxml, "direction-type");
                                    bach_mxmlNewTextElement(direction_typexml, "words", 0, text);
                                }
                                bach_freeptr(text);
                            }
                            llll_free(slot_contents);
                        }
                    }
                    
                    mxml_node_t *notexml = mxmlNewElement(measurexml, "note");
                    long screen_midicents = 0;
                    long i;
                    const char *acc_name = NULL;
                    long add_par_qrtrtone = 0;
                    if (is_grace)
                        mxmlNewElement(notexml, "grace");
                    
                    if (note) {
                        if (!isfirstnote) {
                            mxmlNewElement(notexml, "chord");
                        }
                        
                        mxml_node_t *pitchxml = mxmlNewElement(notexml, "pitch");
                        mxml_node_t *stepxml = mxmlNewElement(pitchxml, "step");
                        mxml_node_t *alterxml = mxmlNewElement(pitchxml, "alter");
                        mxml_node_t *octavexml = mxmlNewElement(pitchxml, "octave");
                        screen_midicents = note_get_screen_midicents(note);
                        switch (screen_midicents % 1200) {
                            case 0:        mxmlNewText(stepxml, 0, "C");    break;
                            case 200:    mxmlNewText(stepxml, 0, "D");    break;
                            case 400:    mxmlNewText(stepxml, 0, "E");    break;
                            case 500:    mxmlNewText(stepxml, 0, "F");    break;
                            case 700:    mxmlNewText(stepxml, 0, "G");    break;
                            case 900:    mxmlNewText(stepxml, 0, "A");    break;
                            case 1100:    mxmlNewText(stepxml, 0, "B");    break;
                        }
                        // alter
                        screen_accidental = note_get_screen_accidental(note);
                        if (parenthesized_quartertones && screen_accidental.r_den > 2) {
                            if (parenthesized_quartertones == 30061984) { // yeah, that's bad and private :-) It's however a very bad convention, but I needed it now.
                                screen_accidental = screen_accidental > 0 ? screen_accidental + genrat(1, 4) : screen_accidental - genrat(1, 4);
                                add_par_qrtrtone = 1;
                            } else {
                                screen_accidental = rat_rat_diff(screen_accidental, genrat(1, 4));
                                add_par_qrtrtone = 1;
                            }
                        }
                        double alter = rat2double(rat_long_prod(screen_accidental, 2));
                        if (alter == (int) alter)
                            mxmlNewInteger(alterxml, alter);
                        else
                            mxmlNewReal(alterxml, alter);
                        
                        // octave
                        mxmlNewInteger(octavexml, note_get_screen_midicents(note) / 1200 - 1);
                    } else {
                        mxmlNewElement(notexml, "rest");
                    }
                    
                    if (!is_grace) {
                        // duration
                        bach_mxmlNewIntElement(notexml, "duration", 0, dur.r_num * divisions / dur.r_den);
                    }
                    
                    
                    if (note) {
                        long mc_alter;
                        acc_name = bach_xml_acc2name(screen_accidental, &mc_alter);
                        midicents = screen_midicents + mc_alter;
                        
                        if (note->tie_from) { // stop the tie and delete this item
                            mxml_node_t *tie = mxmlNewElement(notexml, "tie");
                            mxmlElementSetAttr(tie, "type", "stop");
                        }
                        
                        if (note->tie_to) {
                            mxml_node_t *tie = mxmlNewElement(notexml, "tie");
                            mxmlElementSetAttr(tie, "type", "start");
                        }
                    }
                    
                    mxml_node_t *type = mxmlNewElement(notexml, "type");
                    mxmlNewText(type, 0, chordtype);
                    
                    for (i = 0; i < num_dots; i++)
                        mxmlNewElement(notexml, "dot");
                    
                    if (note && note->show_accidental) {
                        mxml_node_t *accidental = bach_mxmlNewTextElement(notexml, "accidental", 0, acc_name);
                        if (add_par_qrtrtone)
                            mxmlElementSetAttr(accidental, "parentheses", "yes");
                    }
                    
                    if (num_tuplets) {
                        mxml_node_t *time_modification = mxmlNewElement(notexml, "time-modification");
                        bach_mxmlNewIntElement(time_modification, "actual-notes", 0, tuplet_info[0].actual_notes);
                        bach_mxmlNewIntElement(time_modification, "normal-notes", 0, tuplet_info[0].normal_notes);
                        bach_mxmlNewTextElement(time_modification, "normal-type", 0, normal_type);
                        for (i = 0; i < tuplet_info[0].normal_dots; i++)
                            mxmlNewElement(time_modification, "normal-dot");
                    }
                    
                    if (note) {
                        
                        
                        /// noteheads
                        /*
                         The notehead element indicates shapes other than the open
                         and closed ovals associated with note durations. The element
                         value can be slash, triangle, diamond, square, cross, x,
                         circle-x, inverted triangle, arrow down, arrow up, slashed,
                         back slashed, normal, cluster, circle dot, left triangle,
                         rectangle, or none. For shape note music, the element values
                         do, re, mi, fa, fa up, so, la, and ti are also used,
                         corresponding to Aikin's 7-shape system. The fa up shape is
                         typically used with upstems; the fa shape is typically used
                         with downstems or no stems.
                         
                         The arrow shapes differ from triangle and inverted triangle
                         by being centered on the stem. Slashed and back slashed
                         notes include both the normal notehead and a slash. The
                         triangle shape has the tip of the triangle pointing up;
                         the inverted triangle shape has the tip of the triangle
                         pointing down. The left triangle shape is a right triangle
                         with the hypotenuse facing up and to the left.
                         */
                        if (export_noteheads && note->notehead_ID != k_NOTEHEAD_DEFAULT) {
                            const char *notehead_txt = NULL;
                            const char *filled_txt = NULL;
                            switch (note->notehead_ID) {
                                case k_NOTEHEAD_WHITE_NOTE:
                                    if (chord->figure.r_den != 2) {
                                        notehead_txt = "normal";
                                        filled_txt = "no";
                                    }
                                    break;
                                case k_NOTEHEAD_BLACK_NOTE:
                                    if (chord->figure.r_den < 4) {
                                        notehead_txt = "normal";
                                        filled_txt = "yes";
                                    }
                                    break;
                                case k_NOTEHEAD_CROSS:
                                    notehead_txt = "x";
                                    break;
                                case k_NOTEHEAD_DIAMOND:
                                    notehead_txt = "diamond";
                                    filled_txt = "no";
                                    break;
                                case k_NOTEHEAD_PLUS:
                                    notehead_txt = "cross";
                                    break;
                                case k_NOTEHEAD_BLACK_SQUARE:
                                    notehead_txt = "square";
                                    filled_txt = "yes";
                                    break;
                                case k_NOTEHEAD_WHITE_SQUARE:
                                    notehead_txt = "square";
                                    filled_txt = "no";
                                    break;
                                case k_NOTEHEAD_SQUARE:
                                    notehead_txt = "square";
                                    break;
                                case k_NOTEHEAD_BLACK_TRIANGLE:
                                    notehead_txt = "triangle";
                                    filled_txt = "yes";
                                    break;
                                case k_NOTEHEAD_WHITE_TRIANGLE:
                                    notehead_txt = "triangle";
                                    filled_txt = "no";
                                    break;
                                case k_NOTEHEAD_TRIANGLE:
                                    notehead_txt = "triangle";
                                    break;
                                case k_NOTEHEAD_DOUBLE_WHOLE_NOTE:
                                case k_NOTEHEAD_WHOLE_NOTE:
                                case k_NOTEHEAD_ACCENT:
                                case k_NOTEHEAD_BLACK_RHOMBUS:
                                case k_NOTEHEAD_WHITE_RHOMBUS:
                                default:
                                    break;
                            }
                            if (notehead_txt) {
                                mxml_node_t *notehead = bach_mxmlNewTextElement(notexml, "notehead", 0, notehead_txt);
                                if (filled_txt) {
                                    mxmlElementSetAttr(notehead, "filled", filled_txt);
                                }
                            }
                        }
                        
                        
                        // staff
                        long staff = 0;
                        if (staves > 1) {
                            for (staff = 0; staff < staves - 1 && screen_midicents <= splitpoints[staff]; staff++)
                                ;
                            bach_mxmlNewIntElement(notexml, "staff", 0, staff + 1);
                        }
                        
                        for (i = 0; i < beam_info.num_beams; i++) {
                            mxml_node_t *beam = mxmlNewElement(notexml, "beam");
                            char beamnumber_txt[16];
                            const char *beamtype;
                            snprintf_zero(beamnumber_txt, 16, "%ld", i + 1);
                            mxmlElementSetAttr(beam, "number", beamnumber_txt);
                            switch (beam_info.beam_type[i]) {
                                case k_XML_START:        beamtype = "begin";            break;
                                case k_XML_STOP:        beamtype = "end";            break;
                                case k_XML_CONTINUE:    beamtype = "continue";        break;
                                case k_XML_HOOK_LEFT:    beamtype = "backward hook";    break;
                                case k_XML_HOOK_RIGHT:    beamtype = "forward hook";    break;
                                default:                beamtype = "";                break;
                            }
                            mxmlNewText(beam, 0, beamtype);
                        }
                    }
                    
                    mxml_node_t *notations = mxmlNewElement(notexml, "notations");
                    
                    if (note) {
                        if (note->tie_from) { // stop the tie and delete this item
                            mxml_node_t *tied = mxmlNewElement(notations, "tied");
                            mxmlElementSetAttr(tied, "type", "stop");
                        }
                        
                        if (note->tie_to) {
                            mxml_node_t *tied = mxmlNewElement(notations, "tied");
                            mxmlElementSetAttr(tied, "type", "start");
                        }
                    }
                    
                    if (export_glissandi) {
                        if (open_gliss && open_gliss->l_head && note && (!note->tie_from || x->r_ob.dl_spans_ties == 0)) {
                            mxml_node_t *slide = mxmlNewElement(notations, "slide");
                            mxmlElementSetAttr(slide, "line-type", "solid");
                            char numtxt[64];
                            snprintf_zero(numtxt, 64, "%ld", hatom_getlong(&open_gliss->l_head->l_hatom));
                            mxmlElementSetAttr(slide, "number", numtxt);
                            mxmlElementSetAttr(slide, "type", "stop");
                            llll_behead(open_gliss);
                            at_least_a_gliss_has_ended = true;
                        }
                        if (note && note->lastbreakpoint->delta_mc != 0 && (!note->tie_from || x->r_ob.dl_spans_ties == 0)) {
                            // finding first free gliss id
                            long curr_gliss_id = 0;
                            for (long i = 1; i <= 6; i++) {
                                if (!is_long_in_llll_first_level(open_gliss, i) && !is_long_in_llll_first_level(open_gliss_chord, i)) {
                                    curr_gliss_id = i;
                                    break;
                                }
                            }
                            if (curr_gliss_id > 0) {
                                mxml_node_t *slide = mxmlNewElement(notations, "slide");
                                mxmlElementSetAttr(slide, "line-type", "solid");
                                char numtxt[64];
                                snprintf_zero(numtxt, 64, "%ld", curr_gliss_id);
                                mxmlElementSetAttr(slide, "number", numtxt);
                                mxmlElementSetAttr(slide, "type", "start");
                                llll_appendlong(open_gliss_chord, curr_gliss_id);
                                curr_gliss_id++;
                            }
                        }
                    }
                    
                    if (num_tuplets) {
                        long are_there_tuplets = 0;
                        for (i = 0; i < num_tuplets; i++) { // first, see if there is at least one tuplet to write
                            if ((are_there_tuplets = tuplet_info[i].type != k_XML_CONTINUE))
                                break; // that is, it is a start or stop
                        }
                        if (are_there_tuplets) {
                            for ( ; i < num_tuplets; i++) {
                                if (tuplet_info[i].type == k_XML_CONTINUE)
                                    continue;
                                mxml_node_t *tuplet = mxmlNewElement(notations, "tuplet");
                                const char *tuplet_type;
                                switch (tuplet_info[i].type) {
                                    case k_XML_START:    tuplet_type = "start";    break;
                                    case k_XML_STOP:    tuplet_type = "stop";    break;
                                    default:            tuplet_type = "";        break;
                                }
                                mxmlElementSetAttr(tuplet, "type", tuplet_type);
                                char txt[16];
                                snprintf_zero(txt, 16, "%ld", i + 1);
                                mxmlElementSetAttr(tuplet, "number", txt);
                                mxml_node_t *tuplet_actual = mxmlNewElement(tuplet, "tuplet-actual");
                                bach_mxmlNewIntElement(tuplet_actual, "tuplet-number", 0, tuplet_info[i].tuplet_actual_number);
                                xml_value_to_name(tuplet_info[i].tuplet_actual_type.r_den, txt);
                                bach_mxmlNewTextElement(tuplet_actual, "tuplet-type", 0, txt);
                                long j;
                                for (j = 0; j < tuplet_info[i].tuplet_actual_dots; j++)
                                    mxmlNewElement(tuplet_actual, "tuplet-dot");
                                
                                mxml_node_t *tuplet_normal = mxmlNewElement(tuplet, "tuplet-normal");
                                bach_mxmlNewIntElement(tuplet_normal, "tuplet-number", 0, tuplet_info[i].tuplet_normal_number);
                                xml_value_to_name(tuplet_info[i].tuplet_normal_type.r_den, txt);
                                bach_mxmlNewTextElement(tuplet_normal, "tuplet-type", 0, txt);
                                for (j = 0; j < tuplet_info[i].tuplet_normal_dots; j++)
                                    mxmlNewElement(tuplet_normal, "tuplet-dot");
                            }
                        }
                    }
                    
                    
                    if (note && (note->num_articulations > 0 || (isfirstnote && chord->num_articulations > 0) || articulations_slot >= 0)) {
                        long i;
                        mxml_node_t *ornaments = NULL;
                        mxml_node_t *technical = NULL;
                        mxml_node_t *articulations = mxmlNewElement(notations, "articulations");
                        /* <!ELEMENT ornaments
                         (((trill-mark | turn | delayed-turn | inverted-turn |
                         delayed-inverted-turn | vertical-turn | shake |
                         wavy-line | mordent | inverted-mordent | schleifer |
                         tremolo | other-ornament), accidental-mark*)*)>
                         
                         <!ELEMENT technical
                         ((up-bow | down-bow | harmonic | open-string |
                         thumb-position | fingering | pluck | double-tongue |
                         triple-tongue | stopped | snap-pizzicato | fret |
                         string | hammer-on | pull-off | bend | tap | heel |
                         toe | fingernails | hole | arrow | handbell |
                         other-technical)*)>
                         
                         <!ELEMENT articulations
                         ((accent | strong-accent | staccato | tenuto |
                         detached-legato | staccatissimo | spiccato |
                         scoop | plop | doit | falloff | breath-mark |
                         caesura | stress | unstress | other-articulation)*)>
                         
                         <!ELEMENT fermata  (#PCDATA)>
                         */
                        
                        // 1. first the ornaments, who might require different <ornaments> elements
                        {
                            //      OLD WAY of assigning articulations:
                            for (i = 0; i < note->num_articulations; i++) {
                                long id = note->articulation[i].articulation_ID;
                                bach_xml_add_ornament(atp, &ornaments, notations, id);
                            }
                            
                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++) {
                                    long id = chord->articulation[i].articulation_ID;
                                    bach_xml_add_ornament(atp, &ornaments, notations, id);
                                }
                            }
                            
                            //      NEW WAY of assigning articulations:
                            if (articulations_slot >= 0 && articulations_slot < CONST_MAX_SLOTS) {
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                    bach_xml_add_ornament(atp, &ornaments, notations, ((t_articulation *)slotitem->item)->articulation_ID);
                                }
                            }
                        }
                        
                        
                        
                        // 2. then technical and articulations
                        {
                            // old way (the weird interleaved-fashion of this part is due to the fact that standard articulations must apparently
                            // be put BEFORE other-articulations in order to be properly parsed by Finale
                            for (i = 0; i < note->num_articulations; i++)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, note->articulation[i].articulation_ID, 1);
                            
                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, chord->articulation[i].articulation_ID, 1);
                            }
                            
                            for (i = 0; i < note->num_articulations; i++)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, note->articulation[i].articulation_ID, 2);
                            
                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, chord->articulation[i].articulation_ID, 2);
                            }
                            
                            
                            // new way
                            if (articulations_slot >= 0 && articulations_slot < CONST_MAX_SLOTS) {
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 1);
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                    bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 2);
                            }
                        }
                        
                        // 3. then fermatas (hopefully one!)
                        {
                            // old way:
                            for (i = 0; i < note->num_articulations; i++) {
                                long id = note->articulation[i].articulation_ID;
                                switch (id) {
                                    case k_ARTICULATION_FERMATA:
                                        bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                                }
                            }
                            
                            if (isfirstnote) {
                                for (i = 0; i < chord->num_articulations; i++) {
                                    long id = chord->articulation[i].articulation_ID;
                                    switch (id) {
                                        case k_ARTICULATION_FERMATA:
                                            bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                                    }
                                }
                            }
                            
                            // new way:
                            if (articulations_slot >= 0 && articulations_slot < CONST_MAX_SLOTS) {
                                for (slotitem = note->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                    t_articulation *art = ((t_articulation *)slotitem->item);
                                    if (art->articulation_ID == k_ARTICULATION_FERMATA)
                                        bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                                }
                            }
                        }
                        
                        
                    } else if (is_rest && articulations_slot >= 0) {
                        mxml_node_t *ornaments = mxmlNewElement(notations, "ornaments");
                        mxml_node_t *technical = mxmlNewElement(notations, "technical");
                        mxml_node_t *articulations = mxmlNewElement(notations, "articulations");
                        // 1. first the ornaments, who might require different <ornaments> elements
                        {
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                bach_xml_add_ornament(atp, &ornaments, notations, ((t_articulation *)slotitem->item)->articulation_ID);
                            }
                        }
                        
                        // 2. then technical and articulations
                        {
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 1);
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next)
                                bach_xml_add_technical_or_articulation(atp, &technical, &articulations, notations, ((t_articulation *)slotitem->item)->articulation_ID, 2);
                        }
                        
                        // 3. then fermatas (hopefully one!)
                        {
                            // new way:
                            for (slotitem = chord->slot[articulations_slot].firstitem; slotitem; slotitem = slotitem->next) {
                                t_articulation *art = ((t_articulation *)slotitem->item);
                                if (art->articulation_ID == k_ARTICULATION_FERMATA)
                                    bach_mxmlNewTextElement(notations, "fermata", 0, "normal");
                            }
                        }
                        
                    }
                    
                    // lyrics
                    if (export_lyrics && isfirstnote && chord->lyrics && chord->lyrics->label) { // first note in chord: we'll attach lyrics to it
                        mxml_node_t *lyricxml = mxmlNewElement(notexml, "lyric");
                        mxmlElementSetAttr(lyricxml, "number", "1");
                        
                        if (chord->lyrics->lyrics_dashed_extension)
                            bach_mxmlNewTextElement(lyricxml, "syllabic", 0, currently_ongoing_lyrics_syllable ? "middle" : "begin");
                        else
                            bach_mxmlNewTextElement(lyricxml, "syllabic", 0, currently_ongoing_lyrics_syllable ? "end" : "single");
                        currently_ongoing_lyrics_syllable = chord->lyrics->lyrics_dashed_extension;
                        
                        bach_mxmlNewTextElement(lyricxml, "text", 0, chord->lyrics->label);
                        
                        // possibly to do: add word extension?
                    }
                    
                    
                }
                
                if (open_gliss) {
                    if (at_least_a_gliss_has_ended)
                        llll_clear(open_gliss);
                    if (open_gliss_chord)
                        llll_chain(open_gliss, open_gliss_chord);
                }
            }
            
            if (measure->next == NULL && currently_open_hairpin) {
                mxml_node_t* directionxml = mxmlNewElement(measurexml, "direction");
                currently_open_hairpin = xml_close_hairpin(directionxml);
            }
            
            if (voices_left_in_voiceensemble == 1) {
                char barline = measure->end_barline->barline_type;
                if (barline == 0)
                    barline = k_BARLINE_AUTOMATIC;
                if (measure->next == NULL && barline == k_BARLINE_AUTOMATIC)
                    barline = k_BARLINE_FINAL;
                if (barline != k_BARLINE_AUTOMATIC) {
                    const char *type = "regular";
                    mxml_node_t *barlinexml = mxmlNewElement(measurexml, "barline");
                    switch (barline) {
                        case k_BARLINE_NORMAL:    type = "regular";        break;
                        case k_BARLINE_DASHED:    type = "dashed";        break;
                        case k_BARLINE_POINTS:    type = "dotted";        break;
                        case k_BARLINE_DOUBLE:    type = "light-light";    break;
                        case k_BARLINE_FINAL:    type = "light-heavy";    break;
                        case k_BARLINE_HIDDEN:    type = "none";            break;
                        case k_BARLINE_SOLID:    type = "heavy";            break;
                        case k_BARLINE_TICK:    type = "tick";            break;
                    }
                    bach_mxmlNewTextElement(barlinexml, "bar-style", 0, type);
                }
            }
        }
        
        if (voices_left_in_voiceensemble == 1) {
            partidx++;
            llll_clear(voice_ensemble_measures);
            new_voice_ensemble = true;
        } else {
            --voices_left_in_voiceensemble;
            new_voice_ensemble = false;
        }
        
        if (open_gliss)
            llll_free(open_gliss);
    }
    
    
    unlock_general_mutex((t_notation_obj *)x);
    
    t_filehandle fh;
    //bach_fix_filename_extension(&filename_sym, "xml");
    switch (bach_openfile_write(filename_sym, "Untitled.musicxml", &fh, &filetype, 1, &outtype, NULL, NULL)) {
        case FILE_ERR_NONE:
            break;
        case FILE_ERR_CANCELED:
            goto score_dowritexml_error_dontclose;
            break;
        case FILE_ERR_CANTOPEN:
            if (filename_sym)
                object_error((t_object *) x, "could not create file: %s", filename_sym->s_name);
            else
                object_error((t_object *) x, "could not create file");
            goto score_dowritexml_error_dontclose;
            break;
    }
    
    mxmlSaveMaxFile(scorexml, fh, whitespace_cb);
    
    //score_dowritexml_error_close:
    sysfile_close(fh);
score_dowritexml_error_dontclose:
    llll_free(voice_ensemble_measures);
    llll_free(numparts_llll);
    mxmlDelete(scorexml);
    return err;
}

























