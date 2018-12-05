//
//  bach_parser.hpp
//  bach
//
//  Created by Andrea Agostini on 07/11/17.
//
//

#ifndef bach_parser_hpp
#define bach_parser_hpp

#include "llll_commons.h"


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
        p.p_alter += t_shortRational(static_cast<t_atom_short>(strtol(next, NULL, 10)),
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
        p.p_alter += t_shortRational(static_cast<t_atom_short>(strtol(next, &next, 10)),
                                     static_cast<t_atom_short>(strtol(next + 1, NULL, 10)));
        return p;
    }
    
    
    static void fatalError(const char *msg)
    {
        error("%s", msg);
    }

};


#endif /* bach_parser_hpp */
