/*
 *  bach_parser.hpp
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

extern class t_mempool *theMempool;

class t_mempool {
//private:
public:
    static const size_t poolSize = 0x10000;
    static const int nPools = 16;
    char pool[nPools][poolSize];
    t_int32_atomic isFree[nPools];
private:
    t_mempool() {
        for (int i = 0; i < nPools; ++i) {
            isFree[i] = 0;
        }
    };
public:
    static char* getPool();
    static void freePool(const char *whichPool);
};



class t_parser {
    
protected:
    //t_parser *self;
    char *globalsPtr;
    char *baseWorkSpacePtr;
    char *currentWorkSpacePtr;
        
    static t_pitch adjustPitchSign(t_pitch p, long s)
    {
        if (s == 1)
            return p;
        else
            return -p;
    }
    
    static t_atom_short eatSign(const char **pos) {
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
        //self = this;
        currentWorkSpacePtr = globalsPtr = t_mempool::getPool();
    }
    
    virtual ~t_parser() {
        t_mempool::freePool(globalsPtr);
    }
public:
    
    void setBasePtr()
    {
        baseWorkSpacePtr = currentWorkSpacePtr;
    }
    
    void reset()
    {
        currentWorkSpacePtr = baseWorkSpacePtr;
    }
    
    void setPtr(const size_t size)
    {
        currentWorkSpacePtr += size;
    }
    
    void *getPtr(const size_t size)
    {
        void *ptr = currentWorkSpacePtr;
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
    void freePtr(const void *ptr) {
        t_mempool::freePool(static_cast<const char*>(ptr));
    }
    
    
    
    static t_rational eatRational(char *pos)
    {
        char *textend;
        long num = strtol(pos, &textend, 10);
        long den = strtol(textend + 1, NULL, 10);
        return t_rational(num, den);
    }
    
    static t_pitch eatPitchAsNameAccInt(const char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        ++pos;
        t_shortRational alter = t_pitch::text2alter(&pos);
        t_atom_short octave = static_cast<t_atom_short>(strtol(pos, NULL, 10));
        return adjustPitchSign(t_pitch(degree, alter, octave), sign);
    }
    
    static t_pitch eatPitchAsNameIntAcc(const char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        const char *acc;
        t_atom_short octave = static_cast<t_atom_short>(strtol(pos + 1, const_cast<char**>(&acc), 10));
        t_shortRational alter = t_pitch::text2alter(&acc);
        return adjustPitchSign(t_pitch(degree, alter, octave), sign);
    }
    
    static t_pitch eatPitchAsNameAccIntIntT(const char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        const char *next = pos + 1;
        t_shortRational alter = t_pitch::text2alter(&next);
        t_atom_short octave = static_cast<t_atom_short>(strtol(next, const_cast<char**>(&next), 10));
        t_pitch p = adjustPitchSign(t_pitch(degree, alter, octave), sign);
        p.p_alterET += t_tinyRational(static_cast<t_atom_short>(strtol(next, NULL, 10)),
                                      1);
        return p;
    }
    
    static t_pitch eatPitchAsNameAccIntRatT(const char *pos)
    {
        t_atom_short sign = eatSign(&pos);
        t_atom_short degree = t_pitch::text2degree(*pos);
        const char *next = pos + 1;
        t_shortRational alter = t_pitch::text2alter(&next);
        long octave = strtol(next, const_cast<char**>(&next), 10);
        t_pitch p = adjustPitchSign(t_pitch(degree, alter, octave), sign);
        p.p_alterET += t_tinyRational(static_cast<t_int16>(strtol(next, const_cast<char**>(&next), 10)), static_cast<t_int16>(strtol(next + 1, NULL, 10)));
        return p;
    }
    
    static t_pitch eatPitchETBaseComp(const char *pos, const char **after) {
        const char *next = pos;
        t_atom_short sign = eatSign(&next);
        t_atom_short degree = t_pitch::text2degree(*next++);
        long octave;
        t_shortRational alter;
        if (isdigit(*next)) {
            octave = strtol(next, const_cast<char**>(&next), 10);
            alter = t_pitch::text2alter(&next);
        } else {
            alter = t_pitch::text2alter(&next);
            octave = strtol(next, const_cast<char**>(&next), 10);
        }
        t_pitch p = adjustPitchSign(t_pitch(degree, alter, octave), sign);
        *after = next;
        return p;
    }
    
    static t_pitch eatPitchETTComp(const char *pos, const char **after) {
        t_pitch p = t_pitch::C0;
        const char *next = pos;
        t_atom_short tSign = eatSign(&next);
        t_atom_short tNum = (t_atom_short) strtol(next, const_cast<char**>(&next), 10) * tSign;
        if (*next != '/') {
            p.p_alterET += tNum;
        } else {
            t_int16 tDen = (t_int16) strtol(++next, const_cast<char**>(&next), 10);
            p.p_alterET += t_tinyRational(tNum, tDen);
        }
        ++next; // t
        
        *after = next;
        return p;
    }
    
    static t_pitch eatPitchETFull(const char *pos, const char **after) {
        const char *next;
        t_pitch p = eatPitchETBaseComp(pos, &next);
        p += eatPitchETTComp(next, &next);
        *after = next;
        return p;
    }
    
    static std::vector<int8_t> eatJICommas(const char *pos, const char **after) {
        const char *next = pos;
        std::vector<int8_t> commas;
        next++; // {
        if (*next != '}') { // commas
            while (1) {
                int8_t c = (int8_t) strtol(next, const_cast<char**>(&next), 10);
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
    
    static t_atom_short eatPlofAndSharps(const char *pos, const char **after) {
        const char *next = pos;
        t_atom_short plof = t_pitch::text2wkplof(*next++);
        t_atom_short sharps = t_pitch::text2JIsharps(&next);
        plof += sharps * 7;
        *after = next;
        return plof;
    }
    
    static t_pitch eatPitchJIBaseComp(const char *pos, const char **after) {
        const char *next = pos;
        t_atom_short sign = eatSign(&next);
        t_atom_short plof;
        t_int8 octave;
        std::vector<int8_t> commas;
        if (*next != '{') {
            plof = eatPlofAndSharps(next, &next);
            commas = eatJICommas(next, &next);
            octave = (t_int8) strtol(next, const_cast<char**>(&next), 10);
        } else {
            plof = 0;
            commas = eatJICommas(next, &next);
            octave = 0;
        }
        t_pitch p = adjustPitchSign(t_pitch(plof, commas, octave), sign);
        *after = next;
        return p;
    }
    
    static t_pitch eatPitchJIRComp(const char *pos) {
        const char *next = pos;
        t_pitch p = t_pitch::C0;
        t_atom_short rNum = (t_atom_short) strtol(next, const_cast<char**>(&next), 10);
        if (*next != '/') {
            p.addJIratio(t_shortRational(rNum, 1));
        } else {
            t_atom_short rDen = (t_atom_short) strtol(++next, const_cast<char**>(&next), 10);
            p.addJIratio(t_shortRational(rNum, rDen));
        }
        return p;
    }
    
    static t_pitch eatPitchJIFull(const char *pos) {
        const char *next;
        t_pitch p = eatPitchJIBaseComp(pos, &next);
        p += eatPitchJIRComp(next);
        return p;
    }
    
    static t_pitch eatPitchComplete(const char *pos) {
        const char *next;
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
