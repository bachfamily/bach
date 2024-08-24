/*
 *  bach_parser.hpp
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

#ifndef bach_parser_hpp
#define bach_parser_hpp

#include "foundation/llll_commons.h"


#ifdef CONFIGURATION_Development
//#define parserpost post // COMMENT EITHER THIS...
#define parserpost(...) ((void) 0) // ...OR THIS...
#else
#define parserpost(...) ((void) 0) // ... BUT DON'T COMMENT THIS
#endif

#define YY_FATAL_ERROR(msg) t_parser::fatalError(msg)

#define PARSER_POOL_SIZE (34000)

class t_parser {
private:
    char pool[PARSER_POOL_SIZE];
    char *basepoolptr;
    char *poolptr;
    
    static t_pitch adjustPitchSign(t_pitch p, long s)
    {
        if (s == 1)
            return p;
        else
            return -p;
    }
    
    static t_atom_short eatSign(char **pos) {
        t_atom_short sign = 1;
        switch (**pos) {
            case '-':
                sign = -1;
            case '+':
                ++*pos;
                break;
        }
        return sign;
    }
    
protected:
    t_parser() {
        poolptr = pool;
    }
public:
    
    void setBasePtr()
    {
        basepoolptr = poolptr;
    }
    
    void reset()
    {
        poolptr = basepoolptr;
    }
    
    void setPtr(const size_t size)
    {
        poolptr += size;
    }
    
    void *getPtr(const size_t size)
    {
        void *ptr = poolptr;
        setPtr(size);
        return ptr;
    }
    
    // this is completely dummy,
    // and only works on the assumption that our flex scanners will only resize their buffers
    // which are always the last thing they allocate
    // --- hope it's gonna work...
    void *resizePtr(void *ptr, const size_t size) {
        return ptr;
    }
    
    // nothing to do, because our mempool is stack-allocated
    void freePtr(const void *ptr) {}
    
    
    
    static t_rational eatRational(char *pos)
    {
        char *textend;
        long num = strtol(pos, &textend, 10);
        long den = strtol(textend + 1, NULL, 10);
        return t_rational(num, den);
    }
    
    static t_pitch eatPitchAsNameAccInt(char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        ++pos;
        t_shortRational alter = t_pitch::text2alter(&pos);
        t_atom_short octave = static_cast<t_atom_short>(strtol(pos, NULL, 10));
        return adjustPitchSign(t_pitch(degree, alter, octave), sign);
    }
    
    static t_pitch eatPitchAsNameIntAcc(char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        char *acc;
        t_atom_short octave = static_cast<t_atom_short>(strtol(pos + 1, &acc, 10));
        t_shortRational alter = t_pitch::text2alter(&acc);
        return adjustPitchSign(t_pitch(degree, alter, octave), sign);
    }
    
    static t_pitch eatPitchAsNameAccIntIntT(char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        char *next = pos + 1;
        t_shortRational alter = t_pitch::text2alter(&next);
        t_atom_short octave = static_cast<t_atom_short>(strtol(next, &next, 10));
        t_pitch p = adjustPitchSign(t_pitch(degree, alter, octave), sign);
        p.p_alterET += t_tinyRational(static_cast<t_atom_short>(strtol(next, NULL, 10)),
                                      1);
        return p;
    }
    
    static t_pitch eatPitchAsNameAccIntRatT(char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        char *next = pos + 1;
        t_shortRational alter = t_pitch::text2alter(&next);
        long octave = strtol(next, &next, 10);
        t_pitch p = adjustPitchSign(t_pitch(degree, alter, octave), sign);
        p.p_alterET += t_tinyRational(static_cast<t_int16>(strtol(next, &next, 10)), static_cast<t_int16>(strtol(next + 1, NULL, 10)));
        return p;
    }
    
    static t_pitch eatPitchETBaseComp(char *pos, char **after) {
        char *next = pos;
        t_atom_short sign = eatSign(&next);
        t_atom_short degree = t_pitch::text2degree(*next++);
        long octave;
        t_shortRational alter;
        if (isdigit(*next)) {
            octave = strtol(next, &next, 10);
            alter = t_pitch::text2alter(&next);
        } else {
            alter = t_pitch::text2alter(&next);
            octave = strtol(next, &next, 10);
        }
        t_pitch p = adjustPitchSign(t_pitch(degree, alter, octave), sign);
        *after = next;
        return p;
    }
    
    static t_pitch eatPitchETTComp(char *pos, char **after) {
        t_pitch p = t_pitch::C0;
        char *next = pos;
        t_atom_short tSign = eatSign(&next);
        t_atom_short tNum = (t_atom_short) strtol(next, &next, 10) * tSign;
        if (*next != '/') {
            p.p_alterET += tNum;
        } else {
            t_int16 tDen = (t_int16) strtol(++next, &next, 10);
            p.p_alterET += t_tinyRational(tNum, tDen);
        }
        ++next; // t
        
        *after = next;
        return p;
    }
    
    static t_pitch eatPitchETFull(char *pos, char **after) {
        char *next;
        t_pitch p = eatPitchETBaseComp(pos, &next);
        p += eatPitchETTComp(next, &next);
        *after = next;
        return p;
    }
    
    static std::vector<int8_t> eatJICommas(char *pos, char **after) {
        char *next = pos;
        std::vector<int8_t> commas;
        next++; // {
        if (*next != '}') { // commas
            while (1) {
                int8_t c = (int8_t) strtol(next, &next, 10);
                commas.push_back(c);
                if (*next == '}')
                    break;
                else
                    next++;
            }
        }
        ++next; // }
        *after = next;
        return commas;
    }
    
    static t_pitch eatPitchJIBaseComp(char *pos, char **after) {
        char *next = pos;
        t_atom_short sign = eatSign(&next);
        t_atom_short plof;
        t_int8 octave;
        std::vector<int8_t> commas;
        if (*next != '{') {
            plof = t_pitch::text2wkplof(*next++);
            t_atom_short sharps = t_pitch::text2JIsharps(&next);
            plof += sharps * 7;
            commas = eatJICommas(next, &next);
            octave = (t_int8) strtol(next, &next, 10);
        } else {
            plof = 0;
            commas = eatJICommas(next, &next);
            octave = 0;
        }
        t_pitch p = adjustPitchSign(t_pitch(plof, commas, octave), sign);
        *after = next;
        return p;
    }
    
    static t_pitch eatPitchJIRComp(char *pos) {
        char *next = pos;
        t_pitch p = t_pitch::C0;
        t_atom_short rNum = (t_atom_short) strtol(next, &next, 10);
        if (*next != '/') {
            p.addJIratio(t_shortRational(rNum, 1));
        } else {
            t_atom_short rDen = (t_atom_short) strtol(++next, &next, 10);
            p.addJIratio(t_shortRational(rNum, rDen));
        }
        return p;
    }
    
    static t_pitch eatPitchJIFull(char *pos) {
        char *next;
        t_pitch p = eatPitchJIBaseComp(pos, &next);
        p += eatPitchJIRComp(next);
        return p;
    }
    
    static t_pitch eatPitchComplete(char *pos) {
        char *next;
        t_pitch p = eatPitchETFull(pos, &next);
        p += eatPitchJIFull(next);
        return p;
    }
    
    static void fatalError(const char *msg)
    {
        error("%s", msg);
    }

};


#endif /* bach_parser_hpp */
