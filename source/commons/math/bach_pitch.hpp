/*
 *  bach_pitch.hpp
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

#ifndef bach_pitch_hpp
#define bach_pitch_hpp

#include <string>
#include <vector>
#include "math/rational.h"


/** Accidental preferences.
    @ingroup    pitch
 */
typedef enum _accidentals_preferences {
    k_ACC_AUTO = 0,    ///< Automatic choice of accidentals
    k_ACC_SHARPS,    ///< Prefer the use of sharps
    k_ACC_FLATS,    ///< Prefer the use of flats
    k_ACC_CUSTOM,    ///< Accidental are explicitely defined via the "enharmonictable" attribute, and thus the t_notation_obj::full_acc_repr symbol
} e_accidentals_preferences;



class t_pitch;


class t_pitchMatrices
{
private:
    t_pitchMatrices();
    t_pitchMatrices(t_pitchMatrices const& copy);
    t_pitchMatrices& operator=(t_pitchMatrices const& copy);
public:
    t_pitch *sumMatrix;
    t_pitch *diffMatrix;
    
    inline static t_pitch getSum(const t_atom_short a, const t_atom_short b);
    inline static t_pitch getDiff(const t_atom_short a, const t_atom_short b);

    static t_pitchMatrices& getInstance() {
        static t_pitchMatrices instance;
        return instance;
    }

};


class t_pitch
{
public:
    static int constexpr primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53};
    static const t_rational primes_inv[15];
    static double constexpr primes_inv_double[15] = {1./2., 1./3., 1./5., 1./7., 1./11., 1./13., 1./17., 1./19., 1./23., 1./29, 1./31., 1./37., 1./41., 1./47., 1./53.};
    
private:
    class expVector {
        //static t_rational constexpr primes_inv[] = {{1, 2}, {1, 3}, {1, 5}, {1, 7}, {1, 11}, {1, 13}, {1, 17}, {1, 19}, {1, 23}, {1, 29}, {1, 31}, {1, 37}, {1, 41}, {1, 47}, {1, 53}};
        
    private:
        Byte data[11]; // containing a "vector" of respectively 8 8 8 8 8 8 8 4 4 4 4 4 4 4 4 -bit signed integers
        
        static inline int8_t getLNibble(const Byte b) {
            int8_t r = (b & 0xf0) >> 4;
            if (r & 0x08)
                r |= 0xf0;
            return r;
        }
        
        static inline int8_t getRNibble(const Byte b) {
            int8_t r = b & 0x0f;
            if (r & 0x08)
                r |= 0xf0;
            return r;
        }
        
    public:
        
        expVector() {
            clear();
        }
        
        expVector(const std::vector<const int8_t> &v) {
            set(v);
        }
        
        void clear();
        void set(const std::vector<const int8_t> &v);
        void set(const int idx, const int8_t v);
        
        std::vector<int8_t> get() const;
        int8_t get(const int idx) const;
        
        bool operator==(const expVector& b) const;
        bool operator!=(const expVector& b) const { return !(*this == b); };
        bool operator<(const expVector& b) const { return getDoubleRatio() < b.getDoubleRatio(); }
        bool operator<=(const expVector& b) const { return !(*this > b); }
        bool operator>(const expVector& b) const { return getDoubleRatio() > b.getDoubleRatio(); }
        bool operator>=(const expVector& b) const { return !(*this < b); }

        expVector operator+(const expVector& b) const;
        expVector operator-(const expVector& b) const;
        expVector operator*(const expVector& b) const;
        expVector operator*(t_atom_long b) const;
        expVector operator-() const;
        
        expVector operator+=(const expVector &b) { return *this = *this + b; }
        expVector operator-=(const expVector &b) { return *this = *this - b; }
        expVector operator*=(t_atom_long b) { return *this = *this * b; }
        
        t_rational getRatio() const;
        double getDoubleRatio() const;
        bool allZeros() const;
        bool allZerosFromTritave() const;
    };
    
    class pco {
    public:
        t_uint8 commas[15];
        t_uint8 ncommas;
        t_uint8 plof;
        t_uint8 octave;
    };
    
public:
    static const t_pitch NaP; // not a pitch
    static const t_pitch middleC; // middle C
    static const t_pitch C0; // C0
    static const t_atom_short degree2MC[];
    static const t_atom_short degree2PC[];
    static const t_atom_short PC2degree[];
    static const char degree2name[];
    
    static const t_shortRational dblsharp;
    static const t_shortRational sharp;
    static const t_shortRational qrtrsharp;
    static const t_shortRational eighthsharp;
    
    static const t_shortRational natural;
    static const t_shortRational flat;
    static const t_shortRational qrtrflat;
    static const t_shortRational eighthflat;
    
    static const t_shortRational illegal;
    
    typedef struct _stepsAndMC {
        t_atom_long steps;
        t_shortRational mc;
    } t_stepsAndMC;
    
private:
    static t_pitchMatrices &pm;
    static constexpr double C0freq = 261.62556541047064229133;
;
    
    expVector p_JIratio;
    t_uint8 p_degreeET;
public: // because solves a lot of small issues... for now...
    t_tinyRational p_alter;
private:
    double JIComponentToFreq() const;
    
    t_rational ETComponentToMCrat() const;
    double ETComponentToMCdouble() const;
    double JIComponentToMC() const;
    
    t_pitch(t_stepsAndMC sat) : p_JIratio(expVector()) {
        p_degreeET = sat.steps % 7;
        if (p_degreeET < 0)
            p_degreeET += 7;
        t_int8 octave = (t_int8) integer_div_round_down(sat.steps, 7);
        setOctave(octave);
        p_alter = (sat.mc - octave * 1200 - degree2MC[p_degreeET]) / 200;
    }
    
protected:
    
public:
    t_pitch() = default;
    
    t_pitch(const t_atom_short degree) : p_JIratio(expVector()), p_degreeET(degree), p_alter(0) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational& alter) :
        p_JIratio(expVector()), p_degreeET(), p_alter(alter) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational &alter, const t_int8 octave) :
        t_pitch(degree, alter) {
            p_JIratio.set(0, octave);
        }
    
    t_pitch(const std::vector<const t_int8> &ratios) : p_JIratio(ratios), p_degreeET(0), p_alter(0) { }

    // TODODG
    t_pitch(const t_uint8 plof, const std::vector<const t_int8> monzo, const t_uint8 octave) : t_pitch() { }
    
    // TODODG
    void adjustRatios(const t_shortRational r) { }
    
    static double f2mc(double f) { return log2(f/C0freq) * 1200.; }
    
    double toMCdouble() const;
    t_rational toMCrat() const;
    
    // only ET part
    t_stepsAndMC toStepsAndMC() const {
        t_stepsAndMC sat;
        sat.steps = p_degreeET + getOctave() * 7;
        sat.mc = toMCrat();
        return sat;
    }
    
    void setOctave(t_int8 oct) { p_JIratio.set(0, oct); }
    
    // TODODG: e gli altri coefficienti?
    t_int8 getOctave() const { return p_JIratio.get(0); }

    t_atom_short degree2MC_safe() const
    {
        if (p_degreeET >= 0 && p_degreeET < 7)
            return degree2MC[p_degreeET];
        else
            return 0;
    }
    
    bool isPureET() const { return p_JIratio.allZerosFromTritave(); }
    bool isPureJI() const { return p_degreeET == 0 && p_alter.num() == 0; }

    
    
    void set(const t_atom_short degree) {
        p_degreeET = degree;
        p_alter.set(0);
        p_JIratio.clear();
    }
    
    void set(const t_atom_short degree, const t_shortRational &alter) {
        p_degreeET = degree;
        p_alter = alter;
        p_JIratio.clear();
    }
    
    void set(const t_atom_short degree, const t_shortRational &alter, const t_atom_short octave) {
        p_degreeET = degree;
        p_alter = alter;
        p_JIratio.clear();
        setOctave(octave);
    }
    
    t_atom_short degreeET() const { return p_degreeET; }
    t_int8 getPlof() const { return p_JIratio.get(1); }
    t_int8 getSharps() const { return getPlof() / 6; }
    std::vector<int8_t> getCommas() const { return std::vector<int8_t>(); } // TODODG
    t_shortRational alter() const { return p_alter; }
    
    
    // TODODG
    t_atom_long toSteps() const { return getOctave() * 7 + p_degreeET; }

    t_atom_long toStepsFromMiddleC() const { return toSteps() - 7*5; }

    t_bool operator==(const t_pitch &b) const;
    t_bool operator!=(const t_pitch &b) const { return !(*this == b); }
    
    t_bool operator<(const t_pitch &b) const;
    t_bool operator<=(const t_pitch &b) const { return !(*this > b); }
    t_bool operator>(const t_pitch &b) const;
    t_bool operator>=(const t_pitch &b) const { return !(*this < b); };

    t_pitch operator-() const;
    
    t_pitch operator+(const t_pitch &b) const;
    t_pitch operator-(const t_pitch &b) const;
    t_pitch operator*(t_atom_long b) const;
    t_pitch operator*(const t_rational &b) const;
    t_pitch operator/(const t_atom_long b) const;
    t_pitch operator/(const t_rational &b) const;
    
    // TODODG
    t_rational operator/(const t_pitch &b) const {
        t_rational b_toMCrat = b.toMCrat();
        if (b_toMCrat.r_num == 0)
            error("Illegal division by C0 (or one of its enharmonic pitches) detected.");
        return toMCrat() / b_toMCrat;
    };
    
    t_pitch operator%(const t_atom_long b) const;
    t_pitch operator%(const t_pitch &b) const;
    

    t_atom_long divdiv(const t_pitch &b) const {
        return static_cast<t_atom_long>((*this) / b);
    };
    
    friend t_pitch operator*(const t_atom_long a, const t_pitch b) { return b * a; }
    friend t_pitch operator*(const t_rational &a, const t_pitch &b) { return b * a; }

    t_pitch operator+=(const t_pitch &b) { return *this = *this + b; }
    t_pitch operator-=(const t_pitch &b) { return *this = *this - b; }
    t_pitch operator*=(t_atom_long b) { return *this = *this * b; }
    t_pitch operator*=(t_rational &b) { return *this = *this * b; }
    t_pitch operator/=(t_atom_long b) { return *this = *this / b; }
    t_pitch operator/=(t_rational b) { return *this = *this / b; }
    t_pitch operator%=(const t_pitch &b) { return *this = *this % b; }

    
    t_atom_short sgn() const {
        if (toMCdouble() > 0) return 1;
        else if (toMCdouble() == 0) return 0;
        else return -1;
    }
    
    t_pitch abs() const {
        if (toMCdouble() > 0) return *this;
        else return -*this;
    }

    // TODODG
    template <typename T> t_pitch mod(const T b) const {
        if (toMCdouble() > 0) return *this % b;
        else return -(*this % b);
    }

    // use tone_division == 0 to return pitches at maximum precision
    static t_pitch fromMC(double mc, long tone_division, e_accidentals_preferences accidentals_preferences, t_rational *key_acc_pattern, t_rational *full_repr);
    
    static t_pitch fromMC(double mc, long tone_division, e_accidentals_preferences accidentals_preferences)
    {
        return fromMC(mc, tone_division, accidentals_preferences, NULL, NULL);
    }
    
    static t_pitch fromMC(double mc)
    {
        // return pitch at maximum precision
        return fromMC(mc, 0, k_ACC_AUTO, NULL, NULL);
    }
    

/*    template <typename T> static t_pitch fromMC(const T mc) {
        t_pitch res;
        if (mc >= 0)
            res.p_octave = t_atom_long(mc) / 1200;
        else
            res.p_octave = -t_atom_short(floor(double(mc) / 1200.));
        T absolutepitch = mc - res.p_octave * 1200;
        t_atom_short pc = t_atom_long(absolutepitch) / 100;
        res.p_degree = t_pitch::PC2degree[pc];
        res.p_alter = t_shortRational(absolutepitch - degree2MC[res.p_degree] / 200);
        return res;
    } */
    
    // TODODG: what to do with this??
    t_atom_long toMC_wo_accidental() const {
        t_atom_long base = degree2MC_safe() + getOctave() * 1200;
        return base;
    }
    
    
    t_pitch enharm(long delta_steps) const {
        t_stepsAndMC smc = this->toStepsAndMC();
        smc.steps += delta_steps;
        return t_pitch(smc);
    }
    
    // TODODG
    t_pitch autoenharm(long tone_division, e_accidentals_preferences accidentals_preferences, t_rational *key_acc_pattern, t_rational *full_repr) const {
        return fromMC(this->toMCrat(), tone_division, accidentals_preferences, key_acc_pattern, full_repr);
    }

    t_pitch autoenharm(long tone_division, e_accidentals_preferences accidentals_preferences) const {
        return this->autoenharm(tone_division, accidentals_preferences, NULL, NULL);
    }

    t_pitch autoenharm() const {
        long tone_division = 2;
        // inferring minimal tone division from accidental
        if (this->alter().r_den > tone_division)
            tone_division = lcm(2, this->alter().r_den);
        return this->autoenharm(tone_division, k_ACC_AUTO, NULL, NULL);
    }
    
    // TODODG
    t_pitch approx(t_atom_long tone_division)
    {
        if (tone_division <= 0)
            return *this;
        t_shortRational temp = p_alter * tone_division;
        t_shortRational new_alter_down(temp.r_num / temp.r_den, static_cast<t_atom_short>(tone_division));
        t_shortRational new_alter_up((temp.r_num / temp.r_den) + 1, static_cast<t_atom_short>(tone_division));
        return t_pitch(p_degree, (new_alter_up - p_alter < p_alter - new_alter_down) ? new_alter_up : new_alter_down, p_octave);
    }

    // TODODG
    t_pitch approx(t_shortRational tone_division)
    {
        if (tone_division <= 0)
            return *this;
        t_shortRational temp = p_alter * tone_division;
        t_shortRational new_alter_down = (temp.r_num / temp.r_den) / tone_division;
        t_shortRational new_alter_up = ((temp.r_num / temp.r_den) + 1) / tone_division;
        return t_pitch(p_degree, (new_alter_up - p_alter < p_alter - new_alter_down) ? new_alter_up : new_alter_down, p_octave);
    }
    
    static t_rational approx(t_rational p, t_rational tone_division)
    {
        if (tone_division <= 0)
            return p;
        long notches;
        t_rational resol = 200 / tone_division;
        if (p > 0)
            notches = t_atom_long((p / resol) + t_rational(1, 2));
        else
            notches = t_atom_long((p / resol) - t_rational(1, 2));
        return notches * resol;
    }
    
    
    static double approx(double p, double tone_division)
    {
        if (tone_division <= 0)
            return p;
        long notches;
        double resol = 200. / tone_division;
        if (p > 0)
            notches = t_atom_long((p / resol) + 0.5);
        else
            notches = t_atom_long((p / resol) - 0.5);
        return notches * resol;
    }
    
    t_bool isNaP() const {
        return (p_alter.r_den == 0);
    }
    
    std::string toString(t_bool include_octave = true, t_bool always_positive = false, t_bool addTrailingSpace = false) const;
    
    long toTextBuf(char *buf, long bufSize, t_bool include_octave = true, t_bool always_positive = false, t_bool addTrailingSpace = false) const;
    
    
    t_symbol* toSym(t_bool include_octave = true, t_bool always_positive = false) const
    {
        char buf[MAX_SYM_LENGTH];
        toTextBuf(buf, MAX_SYM_LENGTH, include_octave, always_positive);
        return gensym(buf);
    }
    
    static t_int8 text2wkplof(int c) {
        static constexpr t_int8 wkplof[] = {0, 2, 4, -1, 1, 3, 5};
        c -= c < 'a' ? 'A' : 'a';
        if (c >= 0 && c <= 6)
            return wkplof[c];
        else
            return 0;
    }
    
    static t_int8 text2JIsharps(char** const pos) {
        t_int8 sharps = 0;
        bool go = true;
        while (go) {
            switch(**pos) {
                case '#': sharps++; (*pos)++; break;
                case 'b': sharps--; (*pos)++; break;
                default: go = false; break;
            }
        }
        return sharps;
    }

/*
    t_pitch fromSym(t_symbol *s)
    {
        long ac = 1;
        t_atom av;
        t_pitch pitch = t_pitch::NaP;
        atom_setsym(&av, s);
        t_llll *ll = llll_parse(ac, &av);
        if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_PITCH)
            pitch = hatom_getpitch(&ll->l_head->l_hatom);
        llll_free(ll);
        return pitch;
    }
    
    t_pitch fromCString(const char *str) { return fromSym(gensym(str));   }

    t_pitch fromString(std::string str) { return fromSym(gensym(str.c_str()));   }
*/

    // upon return, pos points to the first character after the sequence of accidentals
    static t_shortRational text2alter(char **pos)
    {
        t_shortRational alter = {0, 1};
        int go = 1;
        while (go) {
            switch (**pos) {
                case 'x':    alter += t_pitch::dblsharp;        (*pos)++;    break;
                case '#':    alter += t_pitch::sharp;        (*pos)++;    break;
                    
                case 'b':    alter += t_pitch::flat;            (*pos)++;    break;
                
                case 'q':    alter += t_pitch::qrtrsharp;    (*pos)++;    break;
                case 'd':    alter += t_pitch::qrtrflat;        (*pos)++;    break;
                
                case '^':    alter += t_pitch::eighthsharp;    (*pos)++;    break;
                case 'v':    alter += t_pitch::eighthflat;    (*pos)++;    break;
                    
                default:    go = 0;    break;
            }
        }
        return alter;
    }
    
    // upon return, pos points to the first character after the sequence of accidentals
    static t_shortRational text2alter_legacy(char **pos)
    {
        t_shortRational alter = {0, 1};
        int go = 1;
        while (go) {
            switch (**pos) {
                case 'x':    alter += t_pitch::dblsharp;        (*pos)++;    break;
                case '#':    alter += t_pitch::sharp;        (*pos)++;    break;
                    
                case 'b':    alter += t_pitch::flat;            (*pos)++;    break;
                    
                case '+': case 'q':    alter += t_pitch::qrtrsharp;    (*pos)++;    break;
                    
                case '-': case 'd':    alter += t_pitch::qrtrflat;        (*pos)++;    break;
                    
                case '^':    alter += t_pitch::eighthsharp;    (*pos)++;    break;
                case 'v':    alter += t_pitch::eighthflat;    (*pos)++;    break;
                    
                case 'n':   (*pos)++;   break;
                    
                default:    go = 0;    break;
            }
        }
        return alter;
    }
    
    static t_atom_short text2degree(char name)
    {
        char notename = tolower(name);
        return notename >= 'c' ? notename - 'c' : notename - 'a' + 5;
    }
};



#endif /* bach_pitch_hpp */
