//
//  score_readxml.cpp
//  bach.score
//
//  Created by Andrea Agostini on 15/02/2019.
//

#include "score_files.h"
#include "mxml.h"
#include <set>

#define CONST_DYNAMICS_TEXT_ALLOC_SIZE 2048

t_rational xml_name_and_dots_to_value(const char *chordtype, long dots);

mxml_type_t xml_load_cb(mxml_node_t *node);

const char *bach_xml_acc2name(t_rational acc, long *mc_alter);


const char* const xml_accepted_dynamics[] = { "p", "pp", "ppp", "pppp", "ppppp", "pppppp", "f", "ff", "fff", "ffff", "fffff", "ffffff", "mp", "mf", "sf", "sfp", "sfpp", "fp", "rf", "rfz", "sfz", "sffz", "fz", "0", "n"};
constexpr long num_xml_accepted_dynamics = sizeof(xml_accepted_dynamics)/sizeof(xml_accepted_dynamics[0]);




class timedThing {
protected:
    timedThing(int voice, t_rational timePos, double relativeX = 0) : voice(voice), timePos(timePos), relativeX(relativeX) { };
public:
    int voice;
    t_rational timePos;
    double relativeX;
    bool operator<(const timedThing &b) const;
};

class timedChord : public timedThing {
public:
    t_llll *notell;
    timedChord(int voice, t_llll *notell, t_rational timePos) : timedThing(voice, timePos), notell(notell) { }
};

class timedDynamics : public timedThing {
public:
    const char* dyn;
    timedDynamics(const char* dyn, t_rational timePos, double relativeX) : timedThing(-1, timePos), dyn(dyn) { }
};

class timedWords : public timedThing {
public:
    const char* words;
    timedWords(const char* words, t_rational timePos, double relativeX) : timedThing(-1, timePos), words(words) { }
};

bool timedThing::operator<(const timedThing &b) const {
    if (timePos != b.timePos) {
        return timePos < b.timePos;
    } else if (typeid(this) == typeid(timedChord)) {
        return true;
    } else if (relativeX < b.relativeX)
        return true;
    else
        return false;
}

class timedThingCompare
{
public:
    bool operator()(const timedThing &a, const timedThing &b) {
        return a < b;
    }
};

using timedThingPtrSet = std::set<timedThing *>;




void xml_get_timedThings(mxml_node_t *directionXML, timedThingPtrSet &ttps)
{
    char *dynamics_text = (char *) bach_newptrclear(CONST_DYNAMICS_TEXT_ALLOC_SIZE);
    long dynamics_text_cur = 0;
    dynamics_text[0] = 0;
    
    for (mxml_node_t *typeXML = mxmlFindElement(directionXML, directionXML, "direction-type", NULL, NULL, MXML_DESCEND_FIRST);
         typeXML;
         typeXML = mxmlFindElement(typeXML, typeXML, "direction-type", NULL, NULL, MXML_NO_DESCEND)) {
        
        for (mxml_node_t *itemXML = mxmlGetFirstChild(typeXML);
             itemXML;
             itemXML = mxmlWalkNext(itemXML, typeXML, MXML_NO_DESCEND)) {
            const char *itemName = mxmlGetElement(itemXML);
            if (!itemName)
                continue;
            
            
            if (!strcmp(itemName, "dynamics")) {
                
                for (long di = 0; di < num_xml_accepted_dynamics; di++) {
                    if (mxmlFindElement(itemXML, itemXML, xml_accepted_dynamics[di], NULL, NULL, MXML_DESCEND_FIRST))
                        dynamics_text_cur += snprintf_zero(dynamics_text + dynamics_text_cur, CONST_DYNAMICS_TEXT_ALLOC_SIZE - dynamics_text_cur, "%s_", xml_accepted_dynamics[di]);
                }
                if (*dynamics_text == 0) {
                    dynamics_text[0] = '_';
                    dynamics_text[1] = 0;
                }
            } else if (!strcmp(itemName, "wedge")) {
                char hairpin = 0;
                const char *wedgetypetxt = mxmlElementGetAttr(itemXML, "type");
                if (!strcmp(wedgetypetxt, "crescendo"))
                    hairpin = 1;
                else if (!strcmp(wedgetypetxt, "diminuendo"))
                    hairpin = -1;
                if (hairpin) {
                    if (dynamics_text_cur > 0 && dynamics_text_cur <= CONST_DYNAMICS_TEXT_ALLOC_SIZE && dynamics_text[dynamics_text_cur - 1] == '_') {
                        dynamics_text[dynamics_text_cur - 1] = 0;
                        dynamics_text_cur--;
                    }
                    if (dynamics_text_cur < CONST_DYNAMICS_TEXT_ALLOC_SIZE)
                        dynamics_text[dynamics_text_cur++] = (hairpin > 0 ? '<' : '>');
                } else { // it's the end of a hairpin
                    if (dynamics_text_cur > 0 && dynamics_text_cur <= CONST_DYNAMICS_TEXT_ALLOC_SIZE && dynamics_text[dynamics_text_cur - 1] == '_') {
                        dynamics_text[dynamics_text_cur - 1] = 0;
                        dynamics_text_cur--;
                    }
                    if (dynamics_text_cur < CONST_DYNAMICS_TEXT_ALLOC_SIZE) {
                        dynamics_text[dynamics_text_cur++] = '|';
                    }
                }
            }
            
        }
    }
    
    if (dynamics_text_cur > 0) {
        if (dynamics_text_cur <= CONST_DYNAMICS_TEXT_ALLOC_SIZE && dynamics_text[dynamics_text_cur - 1] == '_') {
            dynamics_text[dynamics_text_cur - 1] = 0;
            dynamics_text_cur--;
        }
    } else {
        bach_freeptr(dynamics_text);
        dynamics_text = nullptr;
    }
    
    return dynamics_text;
}



t_llll *xml_get_words(mxml_node_t *from_this_node, mxml_node_t *stop_at_this_node, t_llll *words)
{
    mxml_node_t *tempXML = from_this_node;
    if (!words)
        words = llll_get();
    while (tempXML && tempXML != stop_at_this_node) {
        mxml_node_t *wordsXML = NULL;
        if ((wordsXML = mxmlFindElement(tempXML, tempXML, "words", NULL, NULL, MXML_DESCEND))) {
            const char *wordstxt = mxmlGetOpaque(wordsXML);
            if (wordstxt)
                llll_appendsym(words, gensym(wordstxt));
        }
        tempXML = tempXML->next;
    }
    return words;
}



t_shortRational xml_get_accidental(mxml_node_t *accXML)
{
    t_shortRational alter;
    if (!accXML)
        return t_pitch::natural;
    const char *accidentaltxt = mxmlGetText(accXML, NULL);
    
    if (!strcmp(accidentaltxt, "sharp"))
        alter = t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "natural"))
        alter = t_pitch::natural;
    else if (!strcmp(accidentaltxt, "flat"))
        alter = t_pitch::flat;
    else if (!strcmp(accidentaltxt, "double-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "sharp-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "flat-flat"))
        alter = 2 * t_pitch::flat;
    else if (!strcmp(accidentaltxt, "sharp-sharp"))
        alter = t_pitch::dblsharp;
    else if (!strcmp(accidentaltxt, "natural-sharp"))
        alter = t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "natural-flat"))
        alter = t_pitch::flat;
    else if (!strcmp(accidentaltxt, "quarter-flat"))
        alter = t_pitch::qrtrflat;
    else if (!strcmp(accidentaltxt, "quarter-sharp"))
        alter = t_pitch::qrtrsharp;
    else if (!strcmp(accidentaltxt, "three-quarters-flat"))
        alter = t_pitch::flat +  t_pitch::qrtrflat;
    else if (!strcmp(accidentaltxt, "three-quarters-sharp"))
        alter = t_pitch::sharp + t_pitch::qrtrsharp;
    else if (!strcmp(accidentaltxt, "sharp-down"))
        alter = t_pitch::qrtrsharp - t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "sharp-up"))
        alter = t_pitch::qrtrsharp + t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "natural-down"))
        alter = t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "natural-up"))
        alter = t_pitch::eighthsharp;
    else if (!strcmp(accidentaltxt, "flat-down"))
        alter = t_pitch::qrtrflat + t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "flat-up"))
        alter = t_pitch::eighthflat;
    else if (!strcmp(accidentaltxt, "triple-sharp"))
        alter = 3 * t_pitch::sharp;
    else if (!strcmp(accidentaltxt, "triple-flat"))
        alter = 3 * t_pitch::flat;
    else
        alter = t_pitch::natural;
    return alter;
}



t_llll *score_parse_articulations_to_llll(t_score *x, mxml_node_t *notationsXML, long articulationsslot)
{
    t_llll *articulationsll = llll_get();
    /* <!ELEMENT ornaments
     (((trill-mark | turn | delayed-turn | inverted-turn |
     delayed-inverted-turn | vertical-turn | shake |
     wavy-line | mordent | inverted-mordent | schleifer |
     tremolo | other-ornament), accidental-mark*)*)>
     */
    mxml_node_t *ornamentsXML;
    for (ornamentsXML = mxmlFindElement(notationsXML, notationsXML, "ornaments", NULL, NULL, MXML_DESCEND_FIRST);
         ornamentsXML;
         ornamentsXML = mxmlFindElement(ornamentsXML, notationsXML, "ornaments", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_ornamentXML;
        for (this_ornamentXML = mxmlWalkNext(ornamentsXML, ornamentsXML, MXML_DESCEND_FIRST);
             this_ornamentXML;
             this_ornamentXML = mxmlWalkNext(this_ornamentXML, ornamentsXML, MXML_NO_DESCEND)) {
            char *ornament_txt = NULL;
            if (this_ornamentXML->type == MXML_ELEMENT)
                ornament_txt = this_ornamentXML->value.element.name;
            if (ornament_txt) {
                if (!strcmp(ornament_txt, "trill-mark"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TRILL), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "turn") ||
                         !strcmp(ornament_txt, "delayed-turn") ||
                         !strcmp(ornament_txt, "vertical-turn") ||
                         !strcmp(ornament_txt, "inverted-turn") ||
                         !strcmp(ornament_txt, "delayed-inverted-turn"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_GRUPPETTO), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "mordent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MORDENT_UP), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "inverted-mordent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MORDENT_DOWN), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "wavy-line"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_DOUBLE_MORDENT), 0, WHITENULL_llll);
                else if (!strcmp(ornament_txt, "tremolo")) {
                    switch (mxmlGetInteger(this_ornamentXML)) {
                        case 1:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO1), 0, WHITENULL_llll);
                            break;
                        case 2:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO2), 0, WHITENULL_llll);
                            break;
                        default:
                            llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_TREMOLO3), 0, WHITENULL_llll);
                            break;
                    }
                }
            }
        }
    }
    
    
    /*
     <!ELEMENT technical
     ((up-bow | down-bow | harmonic | open-string |
     thumb-position | fingering | pluck | double-tongue |
     triple-tongue | stopped | snap-pizzicato | fret |
     string | hammer-on | pull-off | bend | tap | heel |
     toe | fingernails | hole | arrow | handbell |
     other-technical)*)>
     */
    
    mxml_node_t *technicalXML;
    for (technicalXML = mxmlFindElement(notationsXML, notationsXML, "technical", NULL, NULL, MXML_DESCEND_FIRST);
         technicalXML;
         technicalXML = mxmlFindElement(technicalXML, notationsXML, "technical", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_technicalXML;
        for (this_technicalXML = mxmlWalkNext(technicalXML, technicalXML, MXML_DESCEND_FIRST);
             this_technicalXML;
             this_technicalXML = mxmlWalkNext(this_technicalXML, technicalXML, MXML_NO_DESCEND)) {
            char *technical_txt = NULL;
            if (this_technicalXML->type == MXML_ELEMENT)
                technical_txt = this_technicalXML->value.element.name;
            if (technical_txt) {
                if (!strcmp(technical_txt, "harmonic"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_HARMONIC), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "tap"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_LEFT_HAND_PIZZICATO), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "up-bow"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_BOWING_UP), 0, WHITENULL_llll);
                else if (!strcmp(technical_txt, "down-bow"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_BOWING_DOWN), 0, WHITENULL_llll);
            }
        }
    }
    
    
    /*
     <!ELEMENT articulations
     ((accent | strong-accent | staccato | tenuto |
     detached-legato | staccatissimo | spiccato |
     scoop | plop | doit | falloff | breath-mark |
     caesura | stress | unstress | other-articulation)*)>
     */
    
    mxml_node_t *articulationsXML;
    for (articulationsXML = mxmlFindElement(notationsXML, notationsXML, "articulations", NULL, NULL, MXML_DESCEND_FIRST);
         articulationsXML;
         articulationsXML = mxmlFindElement(articulationsXML, notationsXML, "articulations", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *this_articulationsXML;
        for (this_articulationsXML = mxmlWalkNext(articulationsXML, articulationsXML, MXML_DESCEND_FIRST);
             this_articulationsXML;
             this_articulationsXML = mxmlWalkNext(this_articulationsXML, articulationsXML, MXML_NO_DESCEND)) {
            char *articulations_txt = NULL;
            if (this_articulationsXML->type == MXML_ELEMENT)
                articulations_txt = this_articulationsXML->value.element.name;
            if (articulations_txt) {
                if (!strcmp(articulations_txt, "staccato"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_STACCATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "tap"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_LEFT_HAND_PIZZICATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "accent"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_ACCENT), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "tenuto"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_PORTATO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "staccatissimo"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_STACCATISSIMO), 0, WHITENULL_llll);
                else if (!strcmp(articulations_txt, "spiccato"))
                    llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_MARTELLATO), 0, WHITENULL_llll);
            }
        }
    }
    
    /*
     <!ELEMENT fermata  (#PCDATA)>
     */
    mxml_node_t *fermataXML = mxmlFindElement(notationsXML, notationsXML, "fermata", NULL, NULL, MXML_DESCEND_FIRST);
    if (fermataXML) {
        llll_appendsym(articulationsll, articulation_id2symbol(&x->r_ob.articulations_typo_preferences, k_ARTICULATION_FERMATA), 0, WHITENULL_llll);
    }
    
    if (articulationsll->l_size > 0) {
        llll_prependlong(articulationsll, articulationsslot);
    } else {
        llll_free(articulationsll);
        articulationsll = NULL;
    }
    return articulationsll;
}


long xmlwrite_notehead_manage_filled(mxml_node_t *noteXML, mxml_node_t *noteheadXML,
                                     long filledID, long nonfilledID, long autoID)
{
    long noteheadID;
    mxml_node_t *filledXML = mxmlFindElement(noteheadXML, noteXML, "notehead", "filled", NULL, MXML_DESCEND_FIRST);
    if (filledXML) {
        const char *filledtxt = mxmlGetText(filledXML, NULL);
        if (!strcmp(filledtxt, "yes")) {
            noteheadID = filledID;
        } else if (!strcmp(filledtxt, "no")) {
            noteheadID = nonfilledID;
        } else
            noteheadID = autoID;
    } else
        noteheadID = autoID;
    return noteheadID;
}





t_symbol *xml_get_clef(t_score *x, mxml_node_t *attributesXML)
{
    long numclefs;
    long top_clef = k_CLEF_G, bottom_clef = k_CLEF_G, clef = k_CLEF_G;
    mxml_node_t *clefXML;
    for (numclefs = 0, clefXML = mxmlFindElement(attributesXML, attributesXML, "clef", NULL, NULL, MXML_DESCEND_FIRST);
         clefXML && numclefs < 16;
         numclefs++, clefXML = mxmlFindElement(clefXML, attributesXML, "clef", NULL, NULL, MXML_NO_DESCEND)) {
        mxml_node_t *signXML = mxmlFindElement(clefXML, clefXML, "sign", NULL, NULL, MXML_DESCEND_FIRST);
        mxml_node_t *lineXML = mxmlFindElement(clefXML, clefXML, "line", NULL, NULL, MXML_DESCEND_FIRST);
        mxml_node_t *clef_octave_changeXML = mxmlFindElement(clefXML, clefXML, "clef-octave-change", NULL, NULL, MXML_DESCEND_FIRST);
        const char *sign = "";
        long line = -1, clef_octave_change = 0;
        long this_clef = k_CLEF_G;
        if (signXML)
            sign = mxmlGetText(signXML, 0);
        if (lineXML)
            line = mxmlGetInteger(lineXML);
        if (clef_octave_changeXML)
            clef_octave_change = mxmlGetInteger(clef_octave_changeXML);
        if (!strcmp(sign, "G")) {
            if (clef_octave_change == 1)        this_clef = k_CLEF_G8va;
            else if (clef_octave_change > 1)    this_clef = k_CLEF_G15ma;
            else                                this_clef = k_CLEF_G;
        } else if (!strcmp(sign, "F")) {
            if (line == 3)
                this_clef = k_CLEF_BARYTONE;
            else {
                if (clef_octave_change == -1)        this_clef = k_CLEF_F8vb;
                else if (clef_octave_change < -1)    this_clef = k_CLEF_F15mb;
                else                                this_clef = k_CLEF_F;
            }
        } else if (!strcmp(sign, "C")) {
            switch (line) {
                case 1:        this_clef = k_CLEF_SOPRANO;    break;
                case 2:        this_clef = k_CLEF_MEZZO;    break;
                case 3:        this_clef = k_CLEF_ALTO;    break;
                case 4:        this_clef = k_CLEF_TENOR;    break;
                default:    this_clef = k_CLEF_MEZZO;    break;
            }
        } else if (!strcmp(sign, "percussion")) {
            this_clef = k_CLEF_PERCUSSION;
        } else {
            this_clef = k_CLEF_NONE;
        }
        
        if (numclefs == 0 || (this_clef > k_CLEF_PERCUSSION && this_clef < top_clef))
            top_clef = this_clef;
        if (numclefs == 0 || this_clef > bottom_clef)
            bottom_clef = this_clef;
    }
    // k_CLEF_PERCUSSION and k_CLEF_NO can only exist if top_clef and bottom_clef are the same
    if (top_clef == bottom_clef) {
        clef = top_clef;
    } else {
        if (top_clef <= k_CLEF_G8va) {
            if (bottom_clef <= k_CLEF_G)
                clef = k_CLEF_GG;
            else if (bottom_clef <= k_CLEF_F)
                clef = k_CLEF_FGG;
            else
                clef = k_CLEF_FFGG;
        } else if (top_clef == k_CLEF_G) {
            if (bottom_clef <= k_CLEF_F)
                clef = k_CLEF_FG;
            else
                clef = k_CLEF_FFG;
        } else
            clef = k_CLEF_FF;
    }
    return clef_number_to_clef_symbol((t_notation_obj *) x, clef);
}



t_symbol *xml_get_key_signature(t_score *x, mxml_node_t *attributesXML)
{
    t_symbol *keysym;
    mxml_node_t *keyXML = mxmlFindElement(attributesXML, attributesXML, "key", NULL, NULL, MXML_DESCEND_FIRST);
    if (keyXML) {
        mxml_node_t *fifthsXML = mxmlFindElement(keyXML, keyXML, "fifths", NULL, NULL, MXML_DESCEND_FIRST);
        if (fifthsXML) {
            long fifths = mxmlGetInteger(fifthsXML);
            e_modes mode = k_MODE_MAJOR;
            mxml_node_t *modeXML = mxmlFindElement(keyXML, keyXML, "mode", NULL, NULL, MXML_DESCEND_FIRST);
            const char *mode_txt = mxmlGetText(modeXML, NULL);
            if (mode_txt && !strcmp(mode_txt, "minor"))
                mode = k_MODE_MINOR;
            keysym = key_and_mode_to_sym((t_notation_obj *) x, fifths, mode, NULL);
            // we're gonna append this later
        } else {
            t_rational acc_pattern[7];
            long i;
            for (i = 0; i < 7; i++)
                acc_pattern[i] = long2rat(0);
            mxml_node_t *key_stepXML;
            for (key_stepXML = mxmlFindElement(keyXML, keyXML, "key-step", NULL, NULL, MXML_DESCEND_FIRST);
                 key_stepXML;
                 key_stepXML = mxmlFindElement(key_stepXML, key_stepXML, "key-step", NULL, NULL, MXML_NO_DESCEND)) {
                mxml_node_t *key_alterXML = mxmlFindElement(key_stepXML, key_stepXML, "key-alter", NULL, NULL, MXML_NO_DESCEND);
                double alter_dbl = mxmlGetReal(key_alterXML);
                char key_char = mxmlGetText(key_stepXML, NULL)[0];
                key_char = key_char >= 'a' ? key_char - 'a' : key_char - 'A';
                long step = (key_char + 5) % 7;
                acc_pattern[step] = approx_double_with_rat_fixed_den(alter_dbl, 100, 1, NULL);
            }
            keysym = key_and_mode_to_sym((t_notation_obj *) x, 0, k_MODE_NONSTANDARD, acc_pattern);
            // we're gonna append this later
        }
    } else {
        keysym = gensym("CM");
        // we're gonna append this later
    }
    return keysym;
}

t_llll *xml_get_time_signature(t_score *x, mxml_node_t *attributesXML, t_bool isfirstmeasure)
{
    // time signature
    t_llll *timell = llll_get(); // if an old one was present, it is already a grandchild of measurell
    t_llll *timenumll = llll_get();
    mxml_node_t *timeXML = mxmlFindElement(attributesXML, attributesXML, "time", NULL, NULL, MXML_DESCEND_FIRST);
    mxml_node_t *beatsXML, *beat_typeXML;
    //= mxmlFindElement(timeXML, timeXML, "beats", NULL, NULL, MXML_DESCEND_FIRST);
    //mxml_node_t *beat_typeXML = mxmlFindElement(timeXML, timeXML, "beat-type", NULL, NULL, MXML_DESCEND_FIRST);
    long beat_den = 1;
    // first find lcm
    for (beat_typeXML = mxmlFindElement(timeXML, timeXML, "beat-type", NULL, NULL, MXML_DESCEND_FIRST);
         beat_typeXML;
         beat_typeXML = mxmlFindElement(beat_typeXML, timeXML, "beat-type", NULL, NULL, MXML_NO_DESCEND)) {
        if (mxmlFindElement(beat_typeXML, timeXML, "interchangeable", NULL, NULL, MXML_NO_DESCEND))
            break;
        beat_den = lcm(beat_den, mxmlGetInteger(beat_typeXML));
    }
    long beat_type = 0;
    long beats = 1;
    if (beat_den == 0) { // which means that one of the beat_types is 0 - thus we prevent division by 0 below
        object_error((t_object *) x, "Bad time signature");
    } else {
        for (beatsXML = mxmlFindElement(timeXML, timeXML, "beats", NULL, NULL, MXML_DESCEND_FIRST);
             beatsXML;
             beatsXML = mxmlFindElement(beatsXML, timeXML, "beats", NULL, NULL, MXML_NO_DESCEND)) {
            if (mxmlFindElement(beatsXML, timeXML, "interchangeable", NULL, NULL, MXML_NO_DESCEND))
                break;
            beat_typeXML = mxmlFindElement(beatsXML, timeXML, "beat-type", NULL, NULL, MXML_NO_DESCEND);
            if (!beat_typeXML)
                break;
            beat_type = mxmlGetInteger(beat_typeXML);
            beats = mxmlGetInteger(beatsXML);
            llll_appendlong(timenumll, beats * beat_den / beat_type, 0, WHITENULL_llll);
        }
    }
    if (timenumll->l_size) {
        if (timenumll->l_size == 1) {
            llll_appendlong(timell, beats, 0, WHITENULL_llll);
            llll_free(timenumll);
        } else
            llll_appendllll(timell, timenumll, 0, WHITENULL_llll);
        llll_appendlong(timell, beat_den, 0, WHITENULL_llll);
    } else {
        llll_free(timenumll);
        if (isfirstmeasure) {
            llll_appendlong(timell, 4, 0, WHITENULL_llll);
            llll_appendlong(timell, 4, 0, WHITENULL_llll);
        } else {
            llll_free(timell);
            timell = nullptr;
        }
    }
    return timell;
}


long xml_get_divisions(t_score *x, mxml_node_t *attributesXML)
{
    long divisions = 0;
    mxml_node_t *divisionsXML = mxmlFindElement(attributesXML, attributesXML, "divisions", NULL, NULL, MXML_DESCEND_FIRST);
    if (divisionsXML)
        divisions = mxmlGetInteger(divisionsXML) * 4;
    if (!divisions) {
        object_warn((t_object *) x, "Tag <divisions> missing or corrupted");
        divisions = 4;
    }
    return divisions;
}

t_llll *xml_get_tempi(t_score *x, mxml_node_t *measureXML, long divisions, t_bool isfirstmeasure, t_llll* &maintempo_ll)
{
    // if tempill already has a value, it has already been used
    t_llll *tempill = llll_get();
    mxml_node_t *directionXML;
    for (directionXML = mxmlFindElement(measureXML, measureXML, "direction", NULL, NULL, MXML_DESCEND_FIRST);
         directionXML;
         directionXML = mxmlFindElement(directionXML, measureXML, "direction", NULL, NULL, MXML_NO_DESCEND)) {
        
        mxml_node_t *direction_typeXML;
        for (direction_typeXML = mxmlFindElement(directionXML, directionXML, "direction-type", NULL, NULL, MXML_DESCEND_FIRST);
             direction_typeXML;
             direction_typeXML = mxmlFindElement(direction_typeXML, directionXML, "direction-type", NULL, NULL, MXML_NO_DESCEND)) {
            
            mxml_node_t *metronomeXML = mxmlFindElement(direction_typeXML, direction_typeXML, "metronome", NULL, NULL, MXML_DESCEND_FIRST);
            if (metronomeXML) {
                t_llll *onetempoll = llll_get();
                mxml_node_t *beat_unitXML = mxmlFindElement(metronomeXML, directionXML, "beat-unit", NULL, NULL, MXML_DESCEND_FIRST);
                if (beat_unitXML) {
                    const char *beat_unittxt = mxmlGetText(beat_unitXML, NULL);
                    long dots = 0;
                    mxml_node_t *beat_unit_dotXML;
                    for (beat_unit_dotXML = mxmlFindElement(beat_unitXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND);
                         beat_unit_dotXML;
                         beat_unit_dotXML = mxmlFindElement(beat_unit_dotXML, directionXML, "beat-unit-dot", NULL, NULL, MXML_NO_DESCEND))
                        dots++;
                    
                    t_rational tempo_figure = xml_name_and_dots_to_value(beat_unittxt, dots);
                    if (tempo_figure.r_num != 0) {
                        llll_appendrat(onetempoll, tempo_figure, 0, WHITENULL_llll);
                        mxml_node_t *per_minuteXML = mxmlFindElement(metronomeXML, metronomeXML, "per-minute", NULL, NULL, MXML_DESCEND_FIRST);
                        if (per_minuteXML) {
                            const char *per_minutetxt = mxmlGetText(per_minuteXML, NULL);
                            double per_minute = 0;
                            if (per_minutetxt) {
                                while (*per_minutetxt && !isdigit(*per_minutetxt))
                                    per_minutetxt++;
                                per_minute = strtod(per_minutetxt, NULL);
                            }
                            llll_appenddouble(onetempoll, per_minute, 0, WHITENULL_llll);
                        }
                        else {
                            object_warn((t_object *) x, "Bad tempo, setting to 60");
                            llll_appendlong(onetempoll, 60, 0, WHITENULL_llll);
                        }
                        
                        mxml_node_t *offsetXML = mxmlFindElement(directionXML, directionXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);
                        t_rational offset;
                        if (offsetXML) {
                            offset = genrat(mxmlGetInteger(offsetXML), divisions);
                        } else {
                            offset = genrat(0, 1);
                        }
                        llll_appendrat(onetempoll, offset, 0, WHITENULL_llll);
                        llll_appendlong(onetempoll, 0, 0, WHITENULL_llll); // tempo interpolation
                        if (isfirstmeasure && !maintempo_ll && offset.r_num == 0) {
                            maintempo_ll = llll_get();
                            llll_appendllll_clone(maintempo_ll, onetempoll);
                        }
                        llll_appendllll(tempill, onetempoll, 0, WHITENULL_llll);
                    } else
                        object_warn((t_object *) x, "Bad tempo");
                }
            }
        }
        mxml_node_t *soundtempoXML = mxmlFindElement(directionXML, directionXML, "sound", "tempo", NULL, MXML_DESCEND_FIRST);
        if (!soundtempoXML)
            soundtempoXML = mxmlFindElement(measureXML, measureXML, "sound", "tempo", NULL, MXML_DESCEND_FIRST);
        if (soundtempoXML) {
            t_llll *onetempoll = llll_get();
            double bpm = strtod(mxmlElementGetAttr(soundtempoXML, "tempo"), NULL);
            llll_appendrat(onetempoll, genrat(1, 4), 0, WHITENULL_llll);
            llll_appenddouble(onetempoll, bpm, 0, WHITENULL_llll);
            mxml_node_t *offsetXML = NULL;
            t_rational offset;
            if (directionXML)
                offsetXML = mxmlFindElement(directionXML, directionXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);
            if (offsetXML) {
                offset = genrat(mxmlGetInteger(offsetXML), divisions);
            } else {
                offset = genrat(0, 1);
            }
            llll_appendrat(onetempoll, offset, 0, WHITENULL_llll);
            if (isfirstmeasure && !maintempo_ll && offset.r_num == 0) {
                maintempo_ll = llll_get();
                llll_appendllll_clone(maintempo_ll, onetempoll);
            }
            llll_appendllll(tempill, onetempoll, 0, WHITENULL_llll);
        }
    }
    return tempill;
}



t_llll *score_readxml(t_score *x,
                      t_filehandle fh,
                      long parenthesizedquartertones,
                      long lyricsslot,
                      long noteheadslot,
                      long articulationsslot,
                      long dynamicsslot,
                      long directionsslot)
{
    t_ptr_size size;
    unsigned char *buffer;
    long new_tonedivision = 2;
    t_llll *maintempo_ll = NULL;
    
    // allocate memory block that is the size of the file
    sysfile_geteof(fh, &size);
    buffer = (unsigned char *) sysmem_newptr(size + 2);
    if (!buffer) {
        object_error((t_object *) x, "File too long");
        return NULL;
    }
    buffer[0] = 0;
    // read in the file
    sysfile_read(fh, &size, buffer);
    sysfile_close(fh);
    *(buffer + size) = 0;
    *(buffer + size + 1) = 0;
    /*
     if (*buffer >= 0xfe) {
     long convlen = 0;
     char *convbuf = charset_unicodetoutf8((unsigned short *) buffer, 0, &convlen);
     sysmem_freeptr(buffer);
     if (!convbuf) {
     object_error((t_object *) x, "bad file");
     return NULL;
     }
     buffer = (unsigned char *) convbuf;
     }
     */
    mxml_node_t *scoreXML = mxmlLoadString(NULL, (char *) buffer, xml_load_cb);
    sysmem_freeptr(buffer);
    
    mxml_node_t *score_partwiseXML = mxmlFindElement(scoreXML, scoreXML, "score-partwise", NULL, NULL, MXML_DESCEND_FIRST);
    if (!score_partwiseXML) {
        object_error((t_object *) x, "File is not a partwise MusicXML!");
        return NULL;
    }
    t_llll *scorell = llll_get();
    llll_appendsym(scorell, _llllobj_sym_score, 0, WHITENULL_llll);
    
    // parse all the header stuff
    mxml_node_t *part_listXML = mxmlFindElement(score_partwiseXML, score_partwiseXML, "part-list", NULL, NULL, MXML_DESCEND_FIRST);
    if (!part_listXML) {
        object_error((t_object *) x, "Missing <part-list> tag");
        llll_free(scorell);
        return NULL;
    }
    
    t_llll *clefsll = llll_get();
    llll_appendsym(clefsll, _llllobj_sym_clefs, 0, WHITENULL_llll);
    llll_appendllll(scorell, clefsll, 0, WHITENULL_llll);
    
    t_llll *keysll = llll_get();
    llll_appendsym(keysll, _llllobj_sym_keys, 0, WHITENULL_llll);
    llll_appendllll(scorell, keysll, 0, WHITENULL_llll);
    
    t_llll *numpartsll = llll_get();
    llll_appendsym(numpartsll, _llllobj_sym_numparts, 0, WHITENULL_llll);
    llll_appendllll(scorell, numpartsll);
    
    // iterate on the parts
    mxml_node_t *partXML;
    long partnum = 1; // for debug
    for (partXML = mxmlFindElement(score_partwiseXML, score_partwiseXML, "part", NULL, NULL, MXML_DESCEND_FIRST);
         partXML;
         partXML = mxmlFindElement(partXML, score_partwiseXML, "part", NULL, NULL, MXML_NO_DESCEND), partnum++) {
        
        t_llll *voicell[CONST_MAX_VOICES];
        voicell[0] = llll_get();
        voicell[1] = llll_get();
        
        long voices_for_this_xml_part = 1;
        
        
        long divisions = 0;
        long velocity = 90;
        t_llll *timell = NULL;
        t_llll *tempill = NULL;
        // iterate on the measures for this part
        mxml_node_t *measureXML;
        long isfirstmeasure = 1;
        long measure_number = 1;
        
        char dynamics_text[CONST_DYNAMICS_TEXT_ALLOC_SIZE];
        
        dynamics_text[0] = 0;
        t_llll *words = NULL;
        t_symbol *clefsym, *keysym;
        
        t_rational global_position = t_rational(0);
        timedThingPtrSet theTimedThingPtrSet;
        
        for (measureXML = mxmlFindElement(partXML, partXML, "measure", NULL, NULL, MXML_DESCEND_FIRST);
             measureXML;
             measureXML = mxmlFindElement(measureXML, partXML, "measure", NULL, NULL, MXML_NO_DESCEND), measure_number++) {
            
            t_llll *measurell[CONST_MAX_VOICES];
            t_rational used_duration[CONST_MAX_VOICES];
            
            for (long i = 0; i <= voices_for_this_xml_part; i++) {
                measurell[i] = llll_get();
                used_duration[i] = t_rational(0);
            }
            
            t_rational current_timepoint = t_rational(0);
            
            t_llll *measureinfoll = llll_get();
            mxml_node_t *attributesXML = mxmlFindElement(measureXML, measureXML, "attributes", NULL, NULL, MXML_DESCEND_FIRST);
            t_llll *newtimell = nullptr;
            // parse the attributes:
            if (attributesXML) {
                if (isfirstmeasure) {
                    clefsym = xml_get_clef(x, attributesXML);
                    keysym = xml_get_key_signature(x, attributesXML);
                }
                
                newtimell = xml_get_time_signature(x, attributesXML, isfirstmeasure);
                divisions = xml_get_divisions(x, attributesXML);
 
            } else if (isfirstmeasure) {
                object_warn((t_object *) x, "Tag <divisions> missing or corrupted");
                divisions = 4;
                llll_appendsym(clefsll, _llllobj_sym_G, 0, WHITENULL_llll);
                llll_appendsym(keysll, gensym("CM"), 0 , WHITENULL_llll);
                timell = llll_get();
                llll_appendlong(timell, 4, 0, WHITENULL_llll);
                llll_appendlong(timell, 4, 0, WHITENULL_llll);
            }
            
            if (newtimell) {
                timell = newtimell;
            } else { // which means that we're using the one from the previous measure
                timell = llll_clone(timell);
            }
            llll_appendllll(measureinfoll, timell, 0, WHITENULL_llll);
            
            // tempi
            tempill = xml_get_tempi(x, measureXML, divisions, isfirstmeasure, maintempo_ll);

            if (tempill->l_size) {
                llll_appendllll(measureinfoll, tempill, 0, WHITENULL_llll);
            } else if (maintempo_ll) {
                llll_clone_upon(maintempo_ll, tempill);
                llll_appendllll(measureinfoll, tempill, 0, WHITENULL_llll);
            } else {
                llll_free(tempill);
                tempill = NULL;
            }
            
            
            
            ///////////////////////////////
            ///////////////////////////////
            //
            // chords and notes
            //
            ///////////////////////////////
            ///////////////////////////////
            
            mxml_node_t *nextnoteXML = NULL;
            
            mxml_node_t *firstnoteXML = NULL;
            t_llll *chordll = NULL;
            t_llll *chord_parentll[CONST_MAX_VOICES];
            
            for (long i = 0; i < voices_for_this_xml_part; i++)
                chord_parentll[i] = measurell[i];
            //            chord_parentll[0] = measurell[0];
            long grace_group = 0, grace = 0;
            long pops = 0;
            t_llll *chordslotsll = NULL;
            
            long current_voice_in_part = 0;
            
            
            t_pitch allpitches[10000];
            long numpitches = 0;
            
            mxml_node_t *itemXML;
            for (itemXML = mxmlGetFirstChild(measureXML);
                 itemXML;
                 itemXML = mxmlWalkNext(itemXML, measureXML, MXML_NO_DESCEND)) {
                
                t_bool switch_to_new_voice = false;
                //mxml_node_t *nextnode = noteXML;
                t_bool isrest = false;
                const char *itemName = mxmlGetElement(itemXML);
                if (!itemName)
                    continue;
                
                if (!strcmp(itemName, "forward")) {
                    isrest = true;
                    
                } else if (!strcmp(itemName, "backup")) {
                    mxml_node_t *durationXML = mxmlFindElement(itemXML, itemXML, "duration", NULL, NULL, MXML_DESCEND_FIRST);
                    t_rational backupdur = t_rational(mxmlGetInteger(durationXML), divisions);
                    current_timepoint -= backupdur;
                    global_position -= backupdur;
                    
                    //t_rational getHere = used_duration[current_voice_in_part] - backupdur;
                    if (current_timepoint < 0) {
                        object_warn((t_object *) x, "<backup> tag wants to backup too far");
                        current_timepoint = t_rational(0);
                    }
                    switch_to_new_voice = true;
                    continue;
                    
                } else if (!strcmp(itemName, "direction")) {
                    const char *dyntxt = xml_get_dynamics(itemXML);
                    if (dyntxt) {
                        t_rational offset;
                        mxml_node_t *offsetXML = mxmlFindElement(itemXML, itemXML, "offset", NULL, NULL, MXML_DESCEND_FIRST);
                        if (offsetXML) {
                            offset = t_rational(mxmlGetInteger(offsetXML), divisions);
                        } else {
                            offset = t_rational(0);
                        }
                        
                        timedDynamics *theTimedDynamics = new timedDynamics(dyntxt, global_position + offset);
                        theTimedThingPtrSet.insert(theTimedDynamics);
                    }
                } else if (strcmp(itemName, "note")) {
                    continue;
                }
                
                if (!firstnoteXML)
                    firstnoteXML = itemXML;
                
                nextnoteXML = mxmlFindElement(itemXML, measureXML, "note", NULL, NULL, MXML_NO_DESCEND);
                
                mxml_node_t *voiceXML = mxmlFindElement(itemXML, itemXML, "voice", NULL, NULL, MXML_DESCEND_FIRST);
                
                if (voiceXML) {
                    int newvoice = mxmlGetInteger(voiceXML) - 1;
                    if (newvoice != current_voice_in_part) {
                        switch_to_new_voice = true;
                        current_voice_in_part = newvoice;
                    }
                }
                
                while (current_voice_in_part < voices_for_this_xml_part) {
                    if (used_duration[current_voice_in_part] > current_timepoint) {
                        ++current_voice_in_part;
                        switch_to_new_voice = true;
                    } else
                        break;
                }
                
                while (current_voice_in_part >= voices_for_this_xml_part) {
                    voicell[voices_for_this_xml_part + 1] = llll_clone(voicell[voices_for_this_xml_part]);
                    measurell[voices_for_this_xml_part + 1] = llll_clone(measurell[voices_for_this_xml_part]);
                    used_duration[voices_for_this_xml_part + 1] = t_rational(0);
                    
                    chord_parentll[voices_for_this_xml_part] = measurell[voices_for_this_xml_part];
                    ++voices_for_this_xml_part;
                }
                
                if (used_duration[current_voice_in_part] < current_timepoint) {
                    t_rational restdur = - (current_timepoint - used_duration[current_voice_in_part]);
                    chordll = llll_get();
                    llll_appendrat(chordll, restdur);
                    llll_appendlong(chordll, 0);
                    llll_appendllll(chord_parentll[current_voice_in_part], chordll);
                    used_duration[current_voice_in_part] = current_timepoint;
                }
                
                // IMPORTING DYNAMICS
                if (itemXML == firstnoteXML && (!nextnoteXML || switch_to_new_voice)) { // just 1 note,
                                                                                        // assuming that this is the right thing to do when we switch to another voice
                    xml_get_dynamics(measureXML->child, NULL, dynamics_text);
                    words = xml_get_words(measureXML->child, NULL, NULL);
                } else if (itemXML == firstnoteXML) {
                    xml_get_dynamics(measureXML->child, firstnoteXML, dynamics_text);
                    words = xml_get_words(measureXML->child, firstnoteXML, NULL);
                } else if (!nextnoteXML || switch_to_new_voice) {
                    char temp_dynamics_text[CONST_DYNAMICS_TEXT_ALLOC_SIZE];
                    temp_dynamics_text[0] = 0;
                    xml_get_dynamics(itemXML->next, NULL, temp_dynamics_text);
                    if (temp_dynamics_text[0]) {
                        // merge dynamics
                        long len = strlen(dynamics_text);
                        if (len == 0)
                            snprintf_zero(dynamics_text, CONST_DYNAMICS_TEXT_ALLOC_SIZE, "%s", temp_dynamics_text);
                        else {
                            if (dynamics_text[len-1] == '_') {
                                dynamics_text[len-1] = 0;
                                len--;
                            }
                            snprintf_zero(dynamics_text + len, CONST_DYNAMICS_TEXT_ALLOC_SIZE - len, "%s", temp_dynamics_text);
                        }
                    }
                    words = xml_get_words(itemXML->next, NULL, words);
                }
                
                
                // if there is a chord and we're closing (even if temporarily) this voice,
                // append to it its articulations and flags
                if (chordll && switch_to_new_voice) {
                    if (chordslotsll) {
                        llll_appendllll(chordll, chordslotsll);
                    }
                    llll_appendlong(chordll, 0, 0, WHITENULL_llll); // chord flags
                    chordll = NULL;
                }
                
                mxml_node_t *chordXML = mxmlFindElement(itemXML, itemXML, "chord", NULL, NULL, MXML_DESCEND_FIRST);
                if (chordXML && !chordll) {
                    object_warn((t_object *) x, "<chord> tag with no preceding note");
                    chordXML = NULL;
                }
                
                mxml_node_t *notationsXML = mxmlFindElement(itemXML, itemXML, "notations", NULL, NULL, MXML_DESCEND_FIRST);
                
                if (!chordXML) {
                    if (chordll) { // if there was a previous chord, append its flags to it
                        if (chordslotsll) {
                            llll_appendllll(chordll, chordslotsll);
                            chordslotsll = NULL;
                        }
                        llll_appendlong(chordll, 0, 0, WHITENULL_llll); // chord flags
                    }
                    grace = mxmlFindElement(itemXML, itemXML, "grace", NULL, NULL, MXML_DESCEND_FIRST) != 0;
                    if (grace && !grace_group) { // that is, we're starting a new grace group
                        chordll = llll_get();
                        llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
                        llll_appendsym(chordll, _llllobj_sym_g, 0, WHITENULL_llll);
                        chord_parentll[current_voice_in_part] = chordll;
                        grace_group = 1;
                    } else if (!grace && grace_group) { // that is, this is the first note outside a grace group
                        if (chord_parentll[current_voice_in_part] != measurell[current_voice_in_part]) // don't climb too much, even if there is a mistake!
                            chord_parentll[current_voice_in_part] = chord_parentll[current_voice_in_part]->l_owner->l_parent;
                        grace_group = 0;
                    }
                    
                    while (pops) {
                        if (chord_parentll[current_voice_in_part] != measurell[current_voice_in_part]) { // don't climb too much, even if there is a mistake!
                            chord_parentll[current_voice_in_part] = chord_parentll[current_voice_in_part]->l_owner->l_parent;
                            pops--;
                        } else
                            pops = 0;
                    }
                    
                    // level stuff
                    mxml_node_t *beamXML;
                    for (beamXML = mxmlFindElement(itemXML, itemXML, "beam", NULL, NULL, MXML_DESCEND_FIRST);
                         beamXML;
                         beamXML = mxmlFindElement(beamXML, itemXML, "beam", NULL, NULL, MXML_NO_DESCEND)) {
                        const char *beamtxt = mxmlGetText(beamXML, NULL);
                        if (!strcmp(beamtxt, "begin")) {
                            chordll = llll_get();
                            llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
                            chord_parentll[current_voice_in_part] = chordll;
                        } else if (!strcmp(beamtxt, "end")) {
                            pops++;
                        }
                    }
                    
                    mxml_node_t *tupletXML;
                    for (tupletXML = mxmlFindElement(notationsXML, notationsXML, "tuplet", NULL, NULL, MXML_DESCEND_FIRST);
                         tupletXML;
                         tupletXML = mxmlFindElement(tupletXML, notationsXML, "tuplet", NULL, NULL, MXML_NO_DESCEND)) {
                        const char *tuplettypetxt = mxmlElementGetAttr(tupletXML, "type");
                        if (!strcmp(tuplettypetxt, "start")) {
                            chordll = llll_get();
                            llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
                            chord_parentll[current_voice_in_part] = chordll;
                        } else if (!strcmp(tuplettypetxt, "stop")) {
                            pops++;
                        }
                    }
                    
                    chordll = llll_get();
                    llll_appendllll(chord_parentll[current_voice_in_part], chordll, 0, WHITENULL_llll);
                    
                    mxml_node_t *restXML = mxmlFindElement(itemXML, itemXML, "rest", NULL, NULL, MXML_DESCEND_FIRST);
                    if (restXML)
                        isrest = true;
                    t_rational duration = t_rational(0);
                    
                    mxml_node_t *typeXML = mxmlFindElement(itemXML, itemXML, "type", NULL, NULL, MXML_DESCEND_FIRST);
                    if (typeXML) {
                        const char *typetxt = mxmlGetText(typeXML, NULL);
                        long dots = 0;
                        mxml_node_t *dotXML;
                        for (dotXML = mxmlFindElement(typeXML, itemXML, "dot", NULL, NULL, MXML_NO_DESCEND);
                             dotXML;
                             dotXML = mxmlFindElement(dotXML, itemXML, "dot", NULL, NULL, MXML_NO_DESCEND))
                            dots++;
                        
                        duration = xml_name_and_dots_to_value(typetxt, dots);
                    }
                    if ((!typeXML && !grace) || (restXML && duration == 1)) { // it could be the only note in the part
                        mxml_node_t *durationXML = mxmlFindElement(itemXML, itemXML, "duration", NULL, NULL, MXML_DESCEND_FIRST);
                        if (durationXML)
                            duration = genrat(mxmlGetInteger(durationXML), divisions);
                        else if (duration == t_rational(0)) {
                            object_warn((t_object *) x, "Note without duration");
                            duration = genrat(1, 4); // use a dummy duration!
                        }
                    } else if (!typeXML && grace) { // if it's a grace note and there is no type
                        duration = genrat(1, 8); // use a dummy duration!
                    }
                    
                    mxml_node_t *time_modificationXML = mxmlFindElement(itemXML, itemXML, "time-modification", NULL, NULL, MXML_DESCEND_FIRST);
                    if (time_modificationXML) {
                        mxml_node_t *actual_notesXML = mxmlFindElement(time_modificationXML, time_modificationXML, "actual-notes", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *normal_notesXML = mxmlFindElement(time_modificationXML, time_modificationXML, "normal-notes", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *normal_typeXML = mxmlFindElement(time_modificationXML, time_modificationXML, "normal-type", NULL, NULL, MXML_DESCEND_FIRST);
                        long actual_notes = mxmlGetInteger(actual_notesXML);
                        long normal_notes = mxmlGetInteger(normal_notesXML);
                        if (!typeXML && normal_typeXML) {
                            const char *normal_typetxt = mxmlGetText(normal_typeXML, NULL);
                            long normal_dots = 0;
                            mxml_node_t *normal_dotXML;
                            for (normal_dotXML = mxmlFindElement(normal_typeXML, itemXML, "normal-dot", NULL, NULL, MXML_NO_DESCEND);
                                 normal_dotXML;
                                 normal_dotXML = mxmlFindElement(normal_dotXML, itemXML, "normal-dot", NULL, NULL, MXML_NO_DESCEND))
                                normal_dots++;
                            
                            duration = xml_name_and_dots_to_value(normal_typetxt, normal_dots);
                        }
                        duration = rat_long_prod(duration, normal_notes);
                        duration = rat_long_div(duration, actual_notes);
                    }
                    
                    timedChord *theTimedChord = new timedChord(current_voice_in_part, chordll, global_position);
                    theTimedThingPtrSet.insert(theTimedChord);
                    
                    
                    if (!grace) {
                        current_timepoint = used_duration[current_voice_in_part] += duration;
                        global_position += duration;
                    }
                    
                    if (isrest) { // which can be either because it is an actual rest, or beacuse of <forward>
                        duration.r_num *= -1;
                    }
                    llll_appendrat(chordll, duration, 0, WHITENULL_llll);
                    
                    
                    
                    
                }
                
                if (!isrest) {
                    mxml_node_t *pitchXML = mxmlFindElement(itemXML, itemXML, "pitch", NULL, NULL, MXML_DESCEND_FIRST);
                    const char *steptxt = NULL;
                    long octave = 0;
                    short degree = 0;
                    t_shortRational alter;
                    
                    if (pitchXML) {
                        mxml_node_t *stepXML = mxmlFindElement(pitchXML, pitchXML, "step", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *alterXML = mxmlFindElement(pitchXML, pitchXML, "alter", NULL, NULL, MXML_DESCEND_FIRST);
                        mxml_node_t *octaveXML = mxmlFindElement(pitchXML, pitchXML, "octave", NULL, NULL, MXML_DESCEND_FIRST);
                        steptxt = mxmlGetText(stepXML, NULL);
                        degree = toupper(*steptxt) - 'C';
                        if (degree < 0)
                            degree += 7;
                        CLAMP(degree, 0, 6);
                        alter = approx_double_with_rat_fixed_den(mxmlGetReal(alterXML) / 2., 8, 0, nullptr);
                        octave = mxmlGetInteger(octaveXML) + 1;
                        mxml_node_t *accidentalXML = mxmlFindElement(itemXML, itemXML, "accidental", NULL, NULL, MXML_DESCEND_FIRST);
                        if (accidentalXML) {
                            alter = xml_get_accidental(accidentalXML);
                        }
                        short den = alter.den();
                        if (den > new_tonedivision)
                            new_tonedivision = den;
                        if (den <= 2 && parenthesizedquartertones) {
                            const char *parentheses = mxmlElementGetAttr(accidentalXML, "parentheses");
                            if (parentheses && !strcmp(parentheses, "yes")) {
                                alter += t_pitch::qrtrsharp;
                                if (new_tonedivision < 4)
                                    new_tonedivision = 4;
                            } else {
                                for (long i = numpitches - 1; i >= 0; i--) {
                                    if (allpitches[i].degree() == degree &&
                                        allpitches[i].degree() == octave &&
                                        ((!accidentalXML && alter == 0) ||
                                         allpitches[i].alter() == alter - t_pitch::qrtrsharp))
                                        alter = allpitches[i].alter();
                                }
                            }
                        } else if (!accidentalXML && alter == 0) { // see if there is a previous note to get the alteration from
                            for (long i = numpitches - 1; i >= 0; i--) {
                                if (allpitches[i].degree() == degree &&
                                    allpitches[i].octave() == octave) {
                                    alter = allpitches[i].alter();
                                    break;
                                }
                            }
                        }
                        
                        
                        
                        
                    } else {
                        mxml_node_t *unpitchedXML = mxmlFindElement(itemXML, itemXML, "unpitched", NULL, NULL, MXML_DESCEND_FIRST);
                        if (unpitchedXML) {
                            mxml_node_t *display_stepXML = mxmlFindElement(unpitchedXML, unpitchedXML, "display-step", NULL, NULL, MXML_DESCEND_FIRST);
                            if (display_stepXML) {
                                mxml_node_t *display_octaveXML = mxmlFindElement(unpitchedXML, unpitchedXML, "display-octave", NULL, NULL, MXML_DESCEND_FIRST);
                                steptxt = mxmlGetText(display_stepXML, NULL);
                                degree = toupper(*steptxt) - 'C';
                                if (degree < 0)
                                    degree += 7;
                                CLAMP(degree, 0, 6);
                                octave = mxmlGetInteger(display_octaveXML) + 1;
                            } else {
                                degree = 6;
                                octave = 5;
                            }
                        }
                    }
                    
                    t_llll *notell = llll_get();
                    t_pitch pch = t_pitch(degree, alter, octave);
                    allpitches[numpitches++] = pch;
                    llll_appendpitch(notell, pch);
                    mxml_node_t *soundXML = mxmlFindElement(itemXML, itemXML, "sound", NULL, NULL, MXML_DESCEND_FIRST);
                    mxml_node_t *dynamicsXML = mxmlFindElement(soundXML, soundXML, "dynamics", NULL, NULL, MXML_DESCEND_FIRST);
                    if (dynamicsXML)
                        velocity = mxmlGetInteger(dynamicsXML) / 100. * 90.;
                    llll_appendlong(notell, velocity, 0, WHITENULL_llll);
                    if (mxmlFindElement(itemXML, itemXML, "tie", "type", "start", MXML_DESCEND_FIRST))
                        llll_appendlong(notell, 1, 0, WHITENULL_llll);
                    else
                        llll_appendlong(notell, 0, 0, WHITENULL_llll);
                    
                    t_llll *slotsll = llll_get();
                    llll_appendsym(slotsll, gensym("slots"));
                    
                    if (noteheadslot > 0) {
                        mxml_node_t *noteheadXML = mxmlFindElement(itemXML, itemXML, "notehead", NULL, NULL, MXML_DESCEND_FIRST);
                        if (noteheadXML) {
                            const char *notehead_txt = mxmlGetText(noteheadXML, NULL);
                            if (notehead_txt) {
                                long noteheadID = -1;
                                if (!strcmp(notehead_txt, "x"))
                                    noteheadID = k_NOTEHEAD_CROSS;
                                else if (!strcmp(notehead_txt, "diamond"))
                                    noteheadID = k_NOTEHEAD_DIAMOND;
                                else if (!strcmp(notehead_txt, "cross"))
                                    noteheadID = k_NOTEHEAD_PLUS;
                                else if (!strcmp(notehead_txt, "normal")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_NOTE, k_NOTEHEAD_WHITE_NOTE, k_NOTEHEAD_DEFAULT);
                                } else if (!strcmp(notehead_txt, "square")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_SQUARE, k_NOTEHEAD_WHITE_SQUARE, k_NOTEHEAD_SQUARE);
                                } else if (!strcmp(notehead_txt, "triangle")) {
                                    xmlwrite_notehead_manage_filled(itemXML, noteheadXML, k_NOTEHEAD_BLACK_TRIANGLE, k_NOTEHEAD_WHITE_TRIANGLE, k_NOTEHEAD_TRIANGLE);
                                }
                                if (noteheadID > 0) {
                                    t_llll *noteheadll = llll_get();
                                    llll_appendlong(noteheadll, noteheadslot);
                                    llll_appendsym(noteheadll, notehead_id2symbol(&x->r_ob.noteheads_typo_preferences, noteheadID));
                                    llll_appendllll(slotsll, noteheadll);
                                }
                            }
                        }
                    }
                    
                    if (articulationsslot > 0) {
                        t_llll *articulationsll = score_parse_articulations_to_llll(x, notationsXML, articulationsslot);
                        if (articulationsll)
                            llll_appendllll(slotsll, articulationsll);
                    }
                    
                    if (dynamicsslot > 0 && dynamics_text[0]) {
                        t_llll *dynamicsll = llll_get();
                        llll_appendlong(dynamicsll, dynamicsslot);
                        llll_appendsym(dynamicsll, gensym(dynamics_text));
                        llll_appendllll(slotsll, dynamicsll);
                    }
                    
                    if (directionsslot > 0 && words && words->l_size) {
                        llll_prependlong(words, directionsslot);
                        llll_appendllll(slotsll, words);
                        words = NULL;
                    }
                    
                    if (lyricsslot > 0) {
                        mxml_node_t *lyricXML = mxmlFindElement(itemXML, itemXML, "lyric", NULL, NULL, MXML_DESCEND_FIRST);
                        if (lyricXML) {
                            t_llll *lyricsll = llll_get();
                            mxml_node_t *textXML = mxmlFindElement(lyricXML, lyricXML, "text", NULL, NULL, MXML_DESCEND_FIRST);
                            mxml_node_t *syllabicXML = mxmlFindElement(lyricXML, lyricXML, "syllabic", NULL, NULL, MXML_DESCEND_FIRST);
                            llll_appendlong(lyricsll, lyricsslot);
                            const char *txt = textXML ? mxmlGetText(textXML, NULL) : NULL;
                            const char *syllabictxt = syllabicXML ? mxmlGetText(syllabicXML, NULL) : NULL;
                            t_symbol *txtsym = _llllobj_sym_empty_symbol;
                            if (syllabictxt && (!strcmp(syllabictxt, "begin") || !strcmp(syllabictxt, "middle"))) {
                                long len = strlen(txt);
                                char *temp_txt = (char *)bach_newptr((len + 2) * sizeof(char));
                                snprintf_zero(temp_txt, len + 2, "%s-", txt);
                                txtsym = gensym(temp_txt);
                                bach_freeptr(temp_txt);
                            } else if (txt) {
                                txtsym = gensym(txt);
                            }
                            llll_appendsym(lyricsll, txtsym);
                            llll_appendllll(slotsll, lyricsll);
                        }
                    }
                    if (slotsll->l_size > 1)
                        llll_appendllll(notell, slotsll);
                    else
                        llll_free(slotsll);
                    
                    llll_appendlong(notell, 0, 0, WHITENULL_llll); // note flags
                    llll_appendllll(chordll, notell, 0, WHITENULL_llll);
                    
                } else { // if it's a rest look for articulations and put them in the chord slot
                    if (articulationsslot > 0) {
                        t_llll *articulationsll = score_parse_articulations_to_llll(x, notationsXML, articulationsslot);
                        if (articulationsll) {
                            chordslotsll = llll_get();
                            llll_appendsym(chordslotsll, _llllobj_sym_slots);
                            llll_appendllll(chordslotsll, articulationsll);
                        }
                    }
                }
                xml_get_dynamics(itemXML->next, nextnoteXML, dynamics_text);
                words = xml_get_words(itemXML->next, nextnoteXML, NULL);
            }
            
            if (chordll) {
                if (chordslotsll) {
                    llll_appendllll(chordll, chordslotsll);
                }
                llll_appendlong(chordll, 0, 0, WHITENULL_llll); // chord flags
                chordll = NULL;
            }
            
            mxml_node_t *barlineXML = mxmlFindElement(measureXML, measureXML, "barline", NULL, NULL, MXML_DESCEND_FIRST);
            if (barlineXML) {
                mxml_node_t *barstyleXML = mxmlFindElement(barlineXML, barlineXML, "bar-style", NULL, NULL, MXML_DESCEND_FIRST);
                if (barstyleXML) {
                    const char *bar_styletxt = mxmlGetText(barstyleXML, NULL);
                    char barline[2];
                    barline[1] = 0;
                    if (!strcmp(bar_styletxt, "regular"))            *barline = k_BARLINE_NORMAL;
                    else if (!strcmp(bar_styletxt, "dashed"))        *barline = k_BARLINE_DASHED;
                    else if (!strcmp(bar_styletxt, "dotted"))        *barline = k_BARLINE_POINTS;
                    else if (!strcmp(bar_styletxt, "light-light"))    *barline = k_BARLINE_DOUBLE;
                    else if (!strcmp(bar_styletxt, "light-heavy"))    *barline = k_BARLINE_FINAL;
                    else if (!strcmp(bar_styletxt, "none"))            *barline = k_BARLINE_HIDDEN;
                    else if (!strcmp(bar_styletxt, "heavy"))        *barline = k_BARLINE_SOLID;
                    else *barline = 0;
                    t_llll *barlinell = llll_get();
                    llll_appendsym(barlinell, _llllobj_sym_barline, 0, WHITENULL_llll);
                    if (*barline)
                        llll_appendsym(barlinell, gensym(barline), 0, WHITENULL_llll);
                    else
                        llll_appendlong(barlinell, 0, 0, WHITENULL_llll);
                    llll_appendllll(measureinfoll, barlinell, 0, WHITENULL_llll);
                }
            }
            
            llll_prependllll(measurell[0], measureinfoll, 0, WHITENULL_llll);
            llll_appendlong(measurell[0], 0, 0, WHITENULL_llll); // measure flags
            llll_appendllll(voicell[0], measurell[0]);
            
            for (long i = 1; i <= voices_for_this_xml_part; i++) {
                llll_prependllll_clone(measurell[i], measureinfoll);
                llll_appendlong(measurell[i], 0, 0, WHITENULL_llll); // measure flags
                llll_appendllll(voicell[i], measurell[i]);
            }
            
            isfirstmeasure = 0;
        }
        
        for (long i = 0; i < voices_for_this_xml_part; i++) {
            llll_appendlong(voicell[i], 0, 0, WHITENULL_llll); // part flags
            llll_appendllll(scorell, voicell[i], 0, WHITENULL_llll);
            llll_appendsym(clefsll, clefsym);
            llll_appendsym(keysll, keysym);
        }
        
        llll_free(voicell[voices_for_this_xml_part]);
        llll_appendlong(numpartsll, voices_for_this_xml_part); // numparts has been added to scorell at the beginning
        
        llll_free(words);
    }
    mxmlDelete(scoreXML);
    
    long tone_division = x->r_ob.tone_division;
    if (tone_division % new_tonedivision != 0) {
        object_warn((t_object *) x, "Changed microtonal division!");
        object_attr_setlong(x, gensym("tonedivision"), lcm(tone_division, 4));
    }
    
    //dev_llll_post(scorell, 1, -1, 10, x, NULL);
    return scorell;
}






t_rational xml_name_and_dots_to_value(const char *chordtype, long dots)
{
    long figure_den;
    if (!strcmp(chordtype, "whole"))
        figure_den = 1;
    else if (!strcmp(chordtype, "half"))
        figure_den = 2;
    else if (!strcmp(chordtype, "quarter"))
        figure_den = 4;
    else if (!strcmp(chordtype, "eighth"))
        figure_den = 8;
    else figure_den = strtol(chordtype, NULL, 0);
    return figure_and_dots_to_figure_sym_duration(genrat(1, figure_den), dots);
}




mxml_type_t xml_load_cb(mxml_node_t *node)
{
    const char *name = mxmlGetElement(node);
    
    if (!strcmp(name, "divisions") ||
        !strcmp(name, "fifths") ||
        !strcmp(name, "beats") ||
        !strcmp(name, "beat-type") ||
        !strcmp(name, "line") ||
        !strcmp(name, "duration") ||
        !strcmp(name, "staff") ||
        !strcmp(name, "octave") ||
        !strcmp(name, "display-octave") ||
        !strcmp(name, "actual-notes") ||
        !strcmp(name, "normal-notes") ||
        !strcmp(name, "tuplet-number") ||
        !strcmp(name, "dynamics") ||
        !strcmp(name, "tremolo") ||
        !strcmp(name, "clef-octave-change") ||
        !strcmp(name, "voice") ||
        !strcmp(name, "offset"))
        return MXML_INTEGER;
    else if (!strcmp(name, "alter") ||
             !strcmp(name, "key-alter"))
        return MXML_REAL;
    else if (!strcmp(name, "per-minute"))
        return MXML_TEXT;
    else if (!strcmp(name, "words"))
        return MXML_OPAQUE;
    else
        return MXML_TEXT;
}







