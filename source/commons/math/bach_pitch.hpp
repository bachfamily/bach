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


#define BACH_PRIMES_JI_SIZE 15

class t_pitch
{
public:
    static int constexpr primes[BACH_PRIMES_JI_SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 37};
    static const t_rational primes_inv[BACH_PRIMES_JI_SIZE];
    static double constexpr primes_inv_double[BACH_PRIMES_JI_SIZE] = {1./2., 1./3., 1./5., 1./7., 1./11., 1./13., 1./17., 1./19., 1./23., 1./29, 1./31., 1./37., 1./41., 1./43., 1./47.};
    
    static t_atom_short constexpr numFifthsPerPrimeFactor[BACH_PRIMES_JI_SIZE] = {0,1,4,-2,-1,3,7,-3,6,-2,0,2,4,-1,6}; // a major third contributes to 4 diatonic fifths, etc.
    static t_atom_short constexpr numDiatonicStepsPerPrimeFactor[BACH_PRIMES_JI_SIZE] = {7,11,16,20,24,26,29,30,31,34,35,36,37,38,38}; // number of diatonic steps per prime factor (an octave is 7 diatonic steps, a perfect twelfth 11, a 3/1 is 16, a 4/1 is 20, and so on.

    static const t_rational HEJIcommasRatios[BACH_PRIMES_JI_SIZE-2];
/*
    static int constexpr HEJIcommasExponents[BACH_PRIMES_JI_SIZE-2][BACH_PRIMES_JI_SIZE] =
            {{-4, 4, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 81/80  these start from the 5-limit!
            {6, -2, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 64/63      7-limit
            {5, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 32/33      11-limit
            {-1, 3, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 27/26      13-limit
            {-7, 7, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0},  // 2187/2176  ....
            {9, -3, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0},  // 512/513
            {-5, 6, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},  // 729/736
            {8, -2, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},  // 256/261
            {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},   // 32/31
            {2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0},   // 36/37
            {-1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0},  // 81/82
            {7, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0},  // 128/129
            {-4, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1}}; // 729/752
 */
    
// this is a more efficient representation: every limit has -1 as its exponent, and the only exponent that matter are 2^ and 3^
    static int constexpr HEJIcommasExponents2[BACH_PRIMES_JI_SIZE-2] = {-4, 6, 5, -1, -7, 9, -5, 8, 5, 2, -1, 7, -4};
    static int constexpr HEJIcommasExponents3[BACH_PRIMES_JI_SIZE-2] = {4, -2, -1, 3, 7, -3, 6, -2, 0, 2, 4, -1, 6};

    static char constexpr HEJIcommasExponentsDirection[BACH_PRIMES_JI_SIZE-2] = {1, 1, -1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1}; // is numerator > denominator in the HEJI commas

    
private:
    class expVector {
        //static t_rational constexpr primes_inv[] = {{1, 2}, {1, 3}, {1, 5}, {1, 7}, {1, 11}, {1, 13}, {1, 17}, {1, 19}, {1, 23}, {1, 29}, {1, 31}, {1, 37}, {1, 41}, {1, 43}, {1, 47}};
        
    private:
        Byte data[11]; // containing a "vector" of respectively 8 8 8 8 8 8 8 4 4 4 4 4 4 4 4 -bit signed integers // TODO: @Andrea: check/change given that I've added the p_octave
        
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
        
        void setFromRatio(t_shortRational r) {
            t_shortRational what = r;
            int8_t exponent;
            std::vector<int8_t> v(BACH_PRIMES_JI_SIZE); // TODO: are we sure that these are all 0's?
            long i = 0;
            
            if (what < 0)
                what *= -1;
            // TODO: shortrat_reduce(&what) ? // this is essential, it should already be reduced, can we make sure of it
            while (rat_long_cmp(what, 1) != 0 && i < BACH_PRIMES_JI_SIZE) {
                long this_prime = primes[i];
                if (what.r_num % this_prime == 0) {
                    exponent = 0;
                    do {
                        exponent++;
                        what.r_num /= this_prime;
                    } while (what.r_num != 0 && what.r_num % this_prime == 0);
                    v[i] = exponent;
                } else if (what.r_den % this_prime == 0) {
                    exponent = 0;
                    do {
                        exponent++;
                        what.r_den /= this_prime;
                    } while (what.r_den != 0 && what.r_den % this_prime == 0);
                    v[i] = -exponent;
                }
                i++;
            }
        }
        
        void clear();
        void set(const std::vector<const int8_t> &v);
        void set(const int idx, const int8_t v);
        
        std::vector<int8_t> get() const;
        int8_t get(const int idx) const;

        int8_t getPlof() const {
            return get(1);
        }

        int8_t getWhiteKeyJI() const {
            int8_t sum = 0;
            for (int8_t i = 0; i < BACH_PRIMES_JI_SIZE; i++) {
                sum += get(i) * numFifthsPerPrimeFactor[i];
            }
            return sum;
//      was:            return sum + getPlof(); //positive_mod(() * 4),7);
            // DG: this thing above doesn't look right any longer
        }
        
        int8_t getOctave() const {
            if (allZerosButOctaves()) {
                return get(0);
            } else {
                int8_t steps = 0;
                for (int8_t i = 0; i < BACH_PRIMES_JI_SIZE; i++) {
                    steps += get(i) * numDiatonicStepsPerPrimeFactor[i];
                }
                return steps / 7;
            }
            // was:
//            return (positive_mod(getPlof() * 4, 7) + steps)/7;
            // but not sure why I'd need that
        }
        
        void setOctave(int8_t o) {
            int8_t curr_octave = getOctave();
            int8_t delta = o - curr_octave;
            set(0, get(0) + delta);
        }
        
        bool operator==(const expVector& b) const;
        bool operator!=(const expVector& b) const { return !(*this == b); };
        bool operator<(const expVector& b) const { return getRatioAsDouble() < b.getRatioAsDouble(); }
        bool operator<=(const expVector& b) const { return !(*this > b); }
        bool operator>(const expVector& b) const { return getRatioAsDouble() > b.getRatioAsDouble(); }
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
        double getRatioAsDouble() const;
        bool allZeros() const;
        bool allZerosButOctaves() const;
    };
    
    class pco {
    public:
        t_uint8 commas[BACH_PRIMES_JI_SIZE];
        t_uint8 ncommas;
        t_uint8 plof;
        t_uint8 octave;
    };
    
public:
    static const t_pitch NaP; // not a pitch
    static const t_pitch middleC; // middle C
    static const t_pitch C0; // C0
    static const t_atom_short whiteKey2MC[];
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
    static constexpr double C0freq = 8.1757989156437073336828122976032719176391;
;
    
    expVector p_JIratio;
    t_uint8 p_whiteKeyET;
public: // because solves a lot of small issues... for now...
    t_tinyRational p_alterET;
private:
    double JIComponentToFreq() const;
    
    t_rational ETComponentToMCrat() const;
    double ETComponentToMCdouble() const;
    double JIComponentToMC() const;
    
    t_pitch(t_stepsAndMC sat) : p_JIratio(expVector()) {
        p_whiteKeyET = sat.steps % 7;
        if (p_whiteKeyET < 0)
            p_whiteKeyET += 7;
        t_int8 octave = (t_int8) integer_div_round_down(sat.steps, 7);
        setOctave(octave);
        p_alterET = (sat.mc - octave * 1200 - whiteKey2MC[p_whiteKeyET]) / 200;
    }
    
protected:
    
public:
    t_pitch() = default;
    
    t_pitch(const t_atom_short degree) : p_JIratio(expVector()), p_whiteKeyET(degree), p_alterET(0) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational& alter) :
        p_JIratio(expVector()), p_whiteKeyET(), p_alterET(alter) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational &alter, const t_int8 octave) :
        t_pitch(degree, alter) {
            p_JIratio.set(0, octave);
        }
    
    t_pitch(const std::vector<const t_int8> &exponents) : p_JIratio(exponents), p_whiteKeyET(0), p_alterET(0) { }

    // TODO: ANDREA, CHECK & and *
    void plofUnpack(const t_uint8 plof, t_uint8 *exp2, t_uint8 *exp3, t_uint8 *whiteKey) {
        // Pythagorean line of fifths position to exponents (of 2 and 3 primes) and whiteKey (diatonic C major degree)
        *exp2 = 0;
        *exp3 = 0;
        *whiteKey = 0;
        short abs_plof = (plof >= 0 ? plof : -plof);
        char sign = (plof >= 0 ? 1 : -1);
        t_shortRational mul = t_shortRational(sign >= 0 ? 3 : 2, sign >= 0 ? 2 : 3);
        for (short i = 0; i < abs_plof; i++) {
            if (sign >= 0) {
                *exp3 += 1;
                *exp2 -= 1;
            } else {
                *exp3 -= 1;
                *exp2 += 1;
            }
            *whiteKey = *whiteKey + 4 * sign;
            if (*whiteKey < 0 || *whiteKey >= 7) {
                *whiteKey = positive_mod(*whiteKey, 7);
                if (sign >= 0)
                    *exp2 -= 1;
                else
                    *exp2 += 1;
            }
        }
    }
    
    // TODO: CHECK ANDREA
    t_pitch(const t_uint8 plof, const std::vector<const t_int8> HEJIcommas, const t_uint8 octave) {
        t_uint8 expof2, expof3, whiteKey;
        plofUnpack(plof, &expof2, &expof3, &whiteKey);
        p_whiteKeyET = whiteKey;
        
        std::vector<int8_t> exponents(BACH_PRIMES_JI_SIZE); // TODO: are we sure that these are initialized as zeros?
        exponents[0] = expof2;
        exponents[1] = expof3;
        for (long i = 0; i < BACH_PRIMES_JI_SIZE-2; i++) { // HEJIcommas start from 5-limit
            char dir = HEJIcommasExponentsDirection[i];
            exponents[0] += dir * HEJIcommasExponents2[i];
            exponents[1] += dir * HEJIcommasExponents3[i];
            exponents[i+2] += dir * (-1);
        }

        p_JIratio.set(exponents); // TODO: @Andrea, there's some const stuff missing, but I cannot initialize with const...
    }
    
    void set(const t_shortRational r) {
        p_JIratio.setFromRatio(r);
    }
    
    static double f2mc(double f) { return log2(f/C0freq) * 1200.; }
    
    double toMCdouble() const;
    t_rational toMCrat() const;
    
    // only ET part
    t_stepsAndMC toStepsAndMC() const {
        t_stepsAndMC sat;
        sat.steps = p_whiteKeyET + getOctave() * 7;
        sat.mc = toMCrat();
        return sat;
    }
    
    void setOctave(t_int8 oct) {
        p_JIratio.setOctave(oct);
        p_octave = oct;
    }
    
    t_int8 getOctave() const { return p_octave; }

    t_atom_short whiteKey2MC_safe() const
    {
        if (p_whiteKeyET >= 0 && p_whiteKeyET < 7)
            return whiteKey2MC[p_whiteKeyET];
        else
            return 0;
    }
    
    bool isPureET() const { return p_JIratio.allZerosButOctaves(); }
    bool isPureJI() const { return p_whiteKeyET == 0 && p_alterET.num() == 0; }

    
    
    void set(const t_atom_short whiteKey) {
        p_whiteKeyET = whiteKey;
        p_alterET.set(0);
        p_JIratio.clear();
    }
    
    void set(const t_atom_short whiteKey, const t_shortRational &alter) {
        p_whiteKeyET = whiteKey;
        p_alterET = alter;
        p_JIratio.clear();
    }
    
    void set(const t_atom_short whiteKey, const t_shortRational &alter, const t_atom_short octave) {
        p_whiteKeyET = whiteKey;
        p_alterET = alter;
        p_JIratio.clear();
        setOctave(octave);
    }
    
    void setFromRatio(t_rational r) { p_JIratio.setFromRatio(r); }

    t_rational getRatio() const { return p_JIratio.getRatio(); }

    t_atom_short getWhiteKeyET() const { return p_whiteKeyET; }
    t_atom_short getWhiteKeyJI() const { return p_JIratio.getWhiteKeyJI(); }

    t_int8 getPlof() const { return p_JIratio.get(1); }
    
    t_int8 getSharps() const { return (getPlof()+1)/7; };
    
    std::vector<int8_t> getHEJICommas() const {
        std::vector<int8_t> v = p_JIratio; // TODO: @Andrea: how do I copy the vector?
        std::vector<int8_t> HEJIcommas(BACH_PRIMES_JI_SIZE - 2);
        for (int8_t i = 0; i < BACH_PRIMES_JI_SIZE - 2; i++) { // HEJI commas are from 5-limit on
            int8_t this_comma = v[i+2];
            char dir = HEJIcommasExponentsDirection[i];
            HEJIcommas[i] = dir * this_comma; // TODO: or the opposite? Is there a minus sign missing? check
            v[0] -= this_comma * HEJIcommasExponents2[i];
            v[1] -= this_comma * HEJIcommasExponents3[i];
            v[i+2] -= this_comma;
        }
        return HEJIcommas;
    }

    t_shortRational getAlterET() const { return p_alterET; }
    t_shortRational getAlterJI() const { return p_alterJI; }

    t_pitch getDisplayPitch() const {
        // TODO: come somma di pitch ET (approssimato ai semitoni) e pitch JI
        t_uint8 plof_ET = ..... ;
        
        p_whiteKeyET =
    }

    
    t_atom_long toSteps() const { return getOctave() * 7 + p_whiteKeyET; }

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
        res.p_alterET = t_shortRational(absolutepitch - whiteKey2MC[res.p_degree] / 200);
        return res;
    } */
    
    // TODO: this shouldn't be needed for JI?
    // potresti darmi il MC_wo_accidental del pitch_displayed()
    // TODOAA
    t_atom_long toMC_wo_accidental() const {
        t_atom_long base = whiteKey2MC_safe() + getOctave() * 1200;
        return base;
    }
    
    
    t_pitch enharm(long delta_steps) const {
        t_stepsAndMC smc = this->toStepsAndMC();
        smc.steps += delta_steps;
        return t_pitch(smc);
    }
    
    // TODOAA: verificare che autoenharm dia sempre pure ET
    t_pitch autoenharm(long tone_division, e_accidentals_preferences accidentals_preferences, t_rational *key_acc_pattern, t_rational *full_repr) const {
        return fromMC(this->toMCrat(), tone_division, accidentals_preferences, key_acc_pattern, full_repr);
    }

    t_pitch autoenharm(long tone_division, e_accidentals_preferences accidentals_preferences) const {
        return this->autoenharm(tone_division, accidentals_preferences, NULL, NULL);
    }

    t_pitch autoenharm() const {
        long tone_division = 2;
        // inferring minimal tone division from accidental
        if (this->getAlterET().r_den > tone_division)
            tone_division = lcm(2, this->getAlterET().r_den);
        return this->autoenharm(tone_division, k_ACC_AUTO, NULL, NULL);
    }
    
    /*
    t_pitch approxJI_maxden(t_atom_long max_num, t_atom_long max_den) // Approximate a pitch within some limit
    {
        t_shortRational r = p_JIratio.getRatio();
        t_uint8 octave = getOctave();
        
        t_rational r_approx = approx_rat_with_rat(r, max_num, max_den);
        
        p_JIratio.setFromRatio(r);
        setOctave(octave);
    }
     */
    
    // TODO: ApproxJI to some limit?
    t_pitch approxJI_limit() {
        // TODO: approssima il ratio a un limite
        t_rational r = p_JIratio.getRatio();
        // fai qualcosa con r
        // TODODG
        p_JIratio.setFromRatio(r);
    }

    // TODO: approx con frazioni continue?
    t_pitch approxJI() {
        t_rational r = p_JIratio.getRatio();
        // fai qualcosa con r
        // BOH!!!!!!!
        // TODODG
        p_JIratio.setFromRatio(r);
    }

    
    
    // TODO: @Andrea: can you do this? I suppose that approx(tone_division) MUST give an ET pitch, right?
    t_pitch approx(t_atom_long tone_division)
    {
        if (tone_division <= 0)
            return *this;
        t_shortRational temp = p_alterET * tone_division;
        t_shortRational new_alter_down(temp.r_num / temp.r_den, static_cast<t_atom_short>(tone_division));
        t_shortRational new_alter_up((temp.r_num / temp.r_den) + 1, static_cast<t_atom_short>(tone_division));
        return t_pitch(p_degree, (new_alter_up - p_alterET < p_alterET - new_alter_down) ? new_alter_up : new_alter_down, p_octave);
    }

    t_pitch approx(t_shortRational tone_division)
    {
        if (tone_division <= 0)
            return *this;
        t_shortRational temp = p_alterET * tone_division;
        t_shortRational new_alter_down = (temp.r_num / temp.r_den) / tone_division;
        t_shortRational new_alter_up = ((temp.r_num / temp.r_den) + 1) / tone_division;
        return t_pitch(p_degree, (new_alter_up - p_alterET < p_alterET - new_alter_down) ? new_alter_up : new_alter_down, p_octave);
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
        return (p_alterET.r_den == 0);
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
