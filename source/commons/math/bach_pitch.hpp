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
#include "notation/bach_accidentals.hpp"



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
    static int constexpr primes[BACH_PRIMES_JI_SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
//  TODO: @Andrea, I don't think you need primes_inv at all (there was a bug in getRatio())
//    static const t_rational primes_inv[BACH_PRIMES_JI_SIZE];
//    static double constexpr primes_inv_double[BACH_PRIMES_JI_SIZE] = {1./2., 1./3., 1./5., 1./7., 1./11., 1./13., 1./17., 1./19., 1./23., 1./29, 1./31., 1./37., 1./41., 1./43., 1./47.};

    // a map from number to the greatest prime <= number
    static int constexpr primes_locate[51] = {-1, -1, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14};

    static t_atom_short constexpr numFifthsPerPrimeFactor[BACH_PRIMES_JI_SIZE] = {0,1,4,-2,-1,3,7,-3,6,-2,0,2,4,-1,6}; // a major third contributes 4 diatonic fifths, etc.
    
    // TODO: check comment
    static t_atom_short constexpr numDiatonicStepsPerPrimeFactor[BACH_PRIMES_JI_SIZE] = {7,11,16,20,24,26,28,30,31,34,35,36,37,38,38}; // number of diatonic steps per prime factor (an octave is 7 diatonic steps, a perfect twelfth 11, a 5/1 is 16, a 7/1 is 20, and so on.
    
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
        
        expVector() = default;
        
        expVector(int dummy) {
            clear();
        }
        
        expVector(const std::vector<int8_t> &v) {
            set(v);
        }
        
        void setFromRatio(const t_shortRational r) {
            t_shortRational what = r;
            int8_t exponent;
            int i = 0;

            clear();

            if (what < 0)
                what *= -1;
            what.reduce();
            while (what != 1 && i < BACH_PRIMES_JI_SIZE) {
                const long this_prime = primes[i];
                if (what.r_num % this_prime == 0) {
                    exponent = 0;
                    do {
                        exponent++;
                        what.r_num /= this_prime;
                    } while (what.r_num != 0 && what.r_num % this_prime == 0);
                    set(i, exponent);
                } else if (what.r_den % this_prime == 0) {
                    exponent = 0;
                    do {
                        exponent++;
                        what.r_den /= this_prime;
                    } while (what.r_den != 0 && what.r_den % this_prime == 0);
                    set(i, -exponent);
                }
                i++;
            }
        }
        
        void addFromRatio(const t_shortRational r) {
            t_shortRational what = r;
            int8_t exponent;
            int i = 0;
            
            if (what < 0)
                what *= -1;
            what.reduce();
            while (what != 1 && i < BACH_PRIMES_JI_SIZE) {
                long this_prime = primes[i];
                if (what.r_num % this_prime == 0) {
                    exponent = 0;
                    do {
                        exponent++;
                        what.r_num /= this_prime;
                    } while (what.r_num != 0 && what.r_num % this_prime == 0);
                    set(i, get(i) + exponent);
                } else if (what.r_den % this_prime == 0) {
                    exponent = 0;
                    do {
                        exponent++;
                        what.r_den /= this_prime;
                    } while (what.r_den != 0 && what.r_den % this_prime == 0);
                    set(i, get(i) - exponent);
                }
                i++;
            }
        }
        
        void clear();
        void set(const std::vector<int8_t> &v);
        void set(const int idx, const int8_t v);
    
    private:
        void setHighPrimeUnsafe(const int idx, const int8_t v);
    
    public:
        std::vector<int8_t> get() const;
        int8_t get(const int idx) const;
        
        int8_t getPlof() const {
            int8_t sum = 0;
            for (int8_t i = 0; i < BACH_PRIMES_JI_SIZE; i++) {
                sum += get(i) * numFifthsPerPrimeFactor[i];
            }
            return sum;
        }
        
        int8_t getWhiteKeyJI() const {
            return positive_mod((getPlof() * 4), 7);
        }
        
        int8_t getOctave() const {
            if (allZerosButOctaves()) {
                return get(0);
            } else {
                int8_t steps = 0;
                for (int8_t i = 0; i < BACH_PRIMES_JI_SIZE; i++) {
                    steps += get(i) * numDiatonicStepsPerPrimeFactor[i];
                }
                return integer_div_round_down(steps, 7);
//                return steps / 7;
            }
        }
        
        void setOctave(int8_t o) {
            int8_t curr_octave = getOctave();
            int8_t delta = o - curr_octave;
            set(0, get(0) + delta);
        }
        
        void addOctaves(int8_t o) {
            if (o != 0) {
                const t_int8 r = get(0) + o;
                set(0, r);
            }
        }
        
        bool operator==(const expVector& b) const;
        bool operator!=(const expVector& b) const { return !(*this == b); };
        bool operator<(const expVector& b) const { return getRatioAsDouble() < b.getRatioAsDouble(); } // TODO: decide if use diatonic comparison
        bool operator<=(const expVector& b) const { return !(*this > b); }
        bool operator>(const expVector& b) const { return getRatioAsDouble() > b.getRatioAsDouble(); } // TODO: see above
        bool operator>=(const expVector& b) const { return !(*this < b); }
        
        expVector operator+(const expVector& b) const;
        expVector operator-(const expVector& b) const;
        expVector operator*(const expVector& b) const;
        expVector operator*(t_atom_long b) const;
        expVector operator/(const expVector& b) const;
        expVector operator/(t_atom_long b) const;
        expVector operator-() const;
        
        expVector operator+=(const expVector &b) { return *this = *this + b; }
        expVector operator-=(const expVector &b) { return *this = *this - b; }
        expVector operator*=(t_atom_long b) { return *this = *this * b; }
        
        t_rational getRatio() const;
        t_rational getRatioExceptOctavesAndPlof() const;
        double getRatioAsDouble() const;
        double getRatioExceptOctavesAndPlofAsDouble() const;
        bool allZeros() const;
        bool allZerosButOctaves() const;
        bool allZerosButOctavesAndTwelfths() const;
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
    
    expVector p_JIexpVector;
    t_uint8 p_whiteKeyET;
public: // because solves a lot of small issues... for now...
    t_tinyRational p_alterET;
private:
    double JIComponentToFreq() const;
    double JIComponentToMC() const;
    
    t_rational ETComponentToMCratNoOctave() const;
    double ETComponentToMCdoubleNoOctave() const;
    
    t_rational ETComponentToMCratWithOctave() const;
    double ETComponentToMCdoubleWithOctave() const;
    
protected:
    
public:
    t_pitch() = default;
    
    t_pitch(const t_atom_short degree) : p_JIexpVector(expVector(0)), p_whiteKeyET(degree), p_alterET(0) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational& alter) :
    p_JIexpVector(expVector(0)), p_whiteKeyET(degree), p_alterET(alter) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational &alter, const t_int8 octave) :
    t_pitch(degree, alter) {
        p_JIexpVector.setOctave(octave);
    }
    
    t_pitch(const std::vector<t_int8> &exponents) : p_JIexpVector(exponents), p_whiteKeyET(0), p_alterET(0) { }
    
    t_pitch(expVector exponents) : p_JIexpVector(exponents), p_whiteKeyET(0), p_alterET(0) { }
    
    
    t_pitch(const t_shortRational &r) {
        setJI(r);
    }
    
    t_pitch(const t_rational &r) {
        setJI(r);
    }
    
    t_pitch(t_stepsAndMC sat) : p_JIexpVector(expVector(0)) {
        p_whiteKeyET = sat.steps % 7;
        if (p_whiteKeyET < 0)
            p_whiteKeyET += 7;
        t_int8 octave = (t_int8) integer_div_round_down(sat.steps, 7);
        setOctave(octave);
        p_alterET = (sat.mc - octave * 1200 - whiteKey2MC[p_whiteKeyET]) / 200;
    }
    
    void plofUnpack(const t_int8 plof, t_int8 *exp2, t_int8 *exp3, t_uint8 *whiteKey) {
        // Pythagorean line of fifths position to exponents (of 2 and 3 primes) and whiteKey (diatonic C major degree)
        *exp2 = 0;
        *exp3 = 0;
        *whiteKey = 0;
        t_int8 wK = 0;
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
            wK = wK + 4 * sign;
            if (wK < 0 || wK >= 7) {
                wK = positive_mod(wK, 7);
                if (sign >= 0)
                    *exp2 -= 1;
                else
                    *exp2 += 1;
            }
        }
        *whiteKey = wK;
    }
    
    t_pitch(const t_int8 plof, const std::vector<t_int8> HEJIcommas, const t_int8 octave) : p_whiteKeyET(0), p_alterET(0) {
        setJI(plof, HEJIcommas, octave);
    }
    
    void setJI(const t_int8 plof, const std::vector<t_int8> HEJIcommas, const t_int8 octave) {
        t_int8 expof2, expof3;
        t_uint8 whiteKey;
        plofUnpack(plof, &expof2, &expof3, &whiteKey);
        
        std::vector<int8_t> exponents(BACH_PRIMES_JI_SIZE, 0);
        exponents[0] = expof2;
        exponents[1] = expof3;
        for (long i = 0; i < BACH_PRIMES_JI_SIZE-2 && i < HEJIcommas.size(); i++) { // HEJIcommas start from 5-limit
            const char dir = HEJIcommasExponentsDirection[i];
            exponents[0] += dir * HEJIcommas[i] * HEJIcommasExponents2[i];
            exponents[1] += dir * HEJIcommas[i] * HEJIcommasExponents3[i];
            exponents[i+2] += dir * HEJIcommas[i] * (-1);
        }
        
        p_JIexpVector.set(exponents);
        setOctave(octave);
    }
    
    void setJI(const std::vector<t_int8> &exponents) {
        p_JIexpVector.set(exponents);
        p_whiteKeyET = 0;
        p_alterET = {0, 1};
    }
    
    t_pitch(const t_atom_short degree, const t_tinyRational &alter, const t_int8 plof, const std::vector<t_int8> HEJIcommas, const t_int8 octave) : t_pitch(plof, HEJIcommas, octave) {
        p_whiteKeyET = degree;
        p_alterET = alter;
    }
    
    t_pitch(const t_atom_short degree, const t_tinyRational &alter, const std::vector<t_int8> &exponents, const t_int8 addOctave = 0) : p_JIexpVector(exponents), p_whiteKeyET(degree), p_alterET(alter) {
        p_JIexpVector.addOctaves(addOctave);
    }
    
    t_pitch(const t_atom_short degree, const t_tinyRational &alter, const t_shortRational &r, const t_int8 addOctave = 0) : p_whiteKeyET(degree), p_alterET(alter) {
        setJI(r);
        p_JIexpVector.addOctaves(addOctave);
    }
    
    t_pitch(const t_atom_short degree, const t_tinyRational &alter, const t_rational &r, const t_int8 addOctave = 0) : p_whiteKeyET(degree), p_alterET(alter) {
        setJI(r);
        p_JIexpVector.addOctaves(addOctave);
    }
    
    void setJI(const t_shortRational r) {
        p_JIexpVector.setFromRatio(r);
        p_whiteKeyET = 0;
        p_alterET = {0, 1};
    }
    
    void setET(const t_atom_short whiteKey) {
        p_whiteKeyET = whiteKey;
        p_alterET.set(0);
        p_JIexpVector.clear();
    }
    
    void setET(const t_atom_short whiteKey, const t_tinyRational &alter) {
        p_whiteKeyET = whiteKey;
        p_alterET = alter;
        p_JIexpVector.clear();
    }
    
    void setET(const t_atom_short whiteKey, const t_tinyRational &alter, const t_atom_short octave) {
        p_whiteKeyET = whiteKey;
        p_alterET = alter;
        p_JIexpVector.clear();
        setOctave(octave);
    }
    
    void set(const t_atom_short degree, const t_tinyRational &alter, const t_shortRational &r, const t_int8 addOctave = 0) {
        p_whiteKeyET = degree;
        p_alterET = alter;
        setJI(r);
        p_JIexpVector.addOctaves(addOctave);
    }
    
    double toMCdouble() const;
    t_rational toMCrat() const;
    
private:
    // only ET part
    t_stepsAndMC toETStepsAndMC() const {
        t_stepsAndMC sat;
        sat.steps = p_whiteKeyET + getOctave() * 7;
        sat.mc = toMCrat();
        return sat;
    }
    
    t_atom_short whiteKey2MC_safe(t_uint8 whiteKey) const
    {
        if (whiteKey >= 0 && whiteKey < 7)
            return whiteKey2MC[whiteKey];
        else
            return 0;
    }
    
public:
    void setOctave(t_int8 oct) {
        p_JIexpVector.setOctave(oct);
    }

    t_int8 getOctave() const {
        return p_JIexpVector.getOctave();
    }
    
    void addOctaves(t_int8 oct) {
        p_JIexpVector.addOctaves(oct);
    }

    bool isPureET() const { return !isNaP() && p_JIexpVector.allZerosButOctaves(); }
    bool isPureJI() const { return !isNaP() && p_whiteKeyET == 0 && p_alterET.num() == 0; }
    bool isPurePythagorean() const { return isPureJI() && p_JIexpVector.allZerosButOctavesAndTwelfths(); }


    
    void setJI(const t_rational r) {
        p_whiteKeyET = 0;
        p_alterET.set(0);
        p_JIexpVector.setFromRatio(r);
    }
    
    void addJIratio(const t_shortRational r) {
        p_JIexpVector.addFromRatio(r);
    }
    
    t_rational getRatio() const { return p_JIexpVector.getRatio(); }

    t_atom_short getWhiteKeyET() const { return p_whiteKeyET; }
    t_atom_short getWhiteKeyJI() const { return p_JIexpVector.getWhiteKeyJI(); }

    t_int8 getPlofJI() const { return p_JIexpVector.getPlof(); }
    
    t_int8 getSharpsJI() const { return integer_div_round_down(getPlofJI() + 1, 7); };
    
    std::vector<int8_t> getHEJICommas(bool removeTrailingZeros = false) const {
        std::vector<int8_t> v = p_JIexpVector.get();
        long num_i = BACH_PRIMES_JI_SIZE - 2;
        if (removeTrailingZeros) {
            for (long j = BACH_PRIMES_JI_SIZE-1; j >= 0; j--) {
                if (v[j] == 0)
                    num_i = j-2;
                else
                    break;
            }
        }
        std::vector<int8_t> HEJIcommas(num_i);
        for (int8_t i = 0; i < num_i; i++) { // HEJI commas are from 5-limit on
            int8_t this_comma = v[i+2];
            char dir = HEJIcommasExponentsDirection[i];
            HEJIcommas[i] = -dir * this_comma; // TODO: or the opposite? Is there a minus sign missing? check
            v[0] -= this_comma * HEJIcommasExponents2[i];
            v[1] -= this_comma * HEJIcommasExponents3[i];
            v[i+2] -= this_comma;
        }
        return HEJIcommas;
    }

    t_rational getHEJICommasAsRational() const;

    t_shortRational getAlterET() const { return p_alterET; }
    
    /*
     ottenere un pitch ET da plof e octave: getWhiteKey() e getSharps()
     
     */
     
    t_pitch getDisplayPitchAsET() const {
        // TODO: come somma di pitch ET (approssimato ai semitoni) e pitch JI

        t_pitch pythPitch(getWhiteKeyJI(), t_shortRational(getSharpsJI(), 2), getOctave());
        t_pitch ETpitchNoOct(getWhiteKeyET(), getAlterET());
        
        return pythPitch + ETpitchNoOct;
    }

    t_int8 approxPlofFromET(t_tinyRational *err = nullptr) const {
        static t_int8 constexpr wk2plof[] = { 0, 2, 4, -1, 1, 3, 5 };
        t_tinyRational alterApprox = approx_rat_with_rat_fixed_den(p_alterET, 2);
        if (err)
            *err = p_alterET - alterApprox;
        t_int8 sharps = (alterApprox * 2).num();
        return wk2plof[positive_mod(p_whiteKeyET, 7)] + sharps * 7;
    }
    
    t_pitch getDisplayPitchAsJI() const {
        t_tinyRational err;
        t_int8 plofET = approxPlofFromET(&err);
        t_int8 plofJI = getPlofJI();
        t_int8 plofETwk = (plofET * 4) % 7;
        t_int8 plofJIwk = (plofJI * 4) % 7;
        t_int8 octave = getOctave() + (plofETwk + plofJIwk > 6);
        std::vector<t_int8> commas = getHEJICommas();
        return t_pitch(0, err, plofET + plofJI, commas, octave);
    }
    
    t_atom_long toStepsET() const { return getOctave() * 7 + getWhiteKeyET(); }
    t_atom_long toStepsETFromMiddleC() const { return toStepsET() - 7*5; }
    t_atom_long toStepsJI() const { return getOctave() * 7 + getWhiteKeyJI(); }
    t_atom_long toStepsJIFromMiddleC() const { return toStepsJI() - 7*5; }
    t_atom_long toSteps() const {
        if (isPureET()) {
            return toStepsET();
        } else if (isPureJI()) {
            return toStepsJI();
        } else {
            t_pitch p = getDisplayPitchAsJI();
            return p.toStepsJI();
        }
    }
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
    
    t_rational divET(const t_pitch &b) const {
        const t_rational b_toMCrat = b.toMCrat();
        if (b_toMCrat.r_num == 0) {
            error("Illegal division by C0 (or one of its enharmonic pitches) detected.");
            return {0, 0};
        }
        return toMCrat() / b_toMCrat;
    };
    
    double divGeneral(const t_pitch &b) const {
        double b_toMCdouble = b.toMCdouble();
        if (b_toMCdouble == 0) {
            error("Illegal division by 0 detected.");
            return 0;
        }
        return toMCdouble() / b_toMCdouble;
    };
    
    t_pitch operator%(const t_atom_long b) const;
    t_pitch operator%(const t_pitch &b) const;
    

    t_atom_long divdiv(const t_pitch &b) const {
        return static_cast<t_atom_long>(divGeneral(b));
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

    static t_pitch fromMC(double mc, long tone_division)
    {
        return fromMC(mc, tone_division, k_ACC_AUTO, NULL, NULL);
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
    
    t_atom_long toMC_wo_accidental() const {
        if (isPureET()) {
            return whiteKey2MC_safe(p_whiteKeyET) + getOctave() * 1200;
        } else if (isPureJI()) {
            return whiteKey2MC_safe(getWhiteKeyJI()) + getOctave() * 1200;
        } else {
            t_pitch jipitch = getDisplayPitchAsJI();
            return whiteKey2MC_safe(jipitch.getWhiteKeyJI()) + getOctave() * 1200; //TODO: check
        }
    }
    
    
    t_pitch enharm(long delta_steps) const {
        t_stepsAndMC smc = this->toETStepsAndMC();
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
    
    
    // A few functions providing JI approximations. The ones with JIcomp only approximate the just intonation component.
    void approxJI_JIcomp_up_to_maxden(t_atom_long max_den, char direction = 0);

    // direction = 0: any; 1 or -1 sets the directino of approximation
    double approxJI_up_to_maxden(t_atom_long max_den, char direction = 0); // Approximate a the whole pitch, return the error
 
    
    // these two function provide a list of "best" approximations that can be proposed in the interface (e.g. contextual menu)
    // they are based on continued fraction representations.
    std::vector<t_rational> getJIconvergents_JIcomp(long howmany, double threshMC, bool includeSemiconvergents, const std::vector<int> &allowed_primes = {});

    std::vector<t_rational> getJIconvergents(long howmany, double threshMC, bool includeSemiconvergents, const std::vector<int> &allowed_primes = {});

    
    // this simply approximates the JI component discarding all commas above some primelimit
    t_pitch approxJI_primelimit(long primelimit) {
        if (primelimit < 3) { // pathological case
            std::vector<int8_t> commas(BACH_PRIMES_JI_SIZE-2, 0);
            return t_pitch(p_whiteKeyET, p_alterET, 0, commas, getOctave());
        } else { // TODO: if already within limit, leave it
            std::vector<int8_t> commas = getHEJICommas();
            long len_commas = commas.size();
            long primeidx = primes_locate[primelimit];
            for (int i = MAX(0, primeidx-1); i < len_commas; i++) {
                commas[i] = 0;
            }
            return t_pitch(p_whiteKeyET, p_alterET, getPlofJI(), commas, getOctave());
        }
    }

    
    t_pitch approxET(t_atom_long tone_division) // approximates the alteration
    {
        if (tone_division <= 0)
            return *this;
        t_tinyRational temp = p_alterET * tone_division;
        t_tinyRational new_alter_down = (temp.r_num / temp.r_den) / (t_tinyRational)tone_division;
        t_tinyRational new_alter_up = ((temp.r_num / temp.r_den) + 1) / (t_tinyRational)tone_division;
        return t_pitch(p_whiteKeyET, (new_alter_up - p_alterET < p_alterET - new_alter_down) ? new_alter_up : new_alter_down, getOctave());
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
    
    std::string toString(t_bool include_octave = true, t_bool always_positive = false, t_bool addTrailingSpace = false, t_bool writeNaturalCsAsJI = false) const;
    
    long toTextBuf(char *buf, long bufSize, t_bool include_octave = true, t_bool always_positive = false, t_bool addTrailingSpace = false) const;
    
    
    t_symbol* toSym(t_bool include_octave = true, t_bool always_positive = false) const
    {
        char buf[MAX_SYM_LENGTH];
        toTextBuf(buf, MAX_SYM_LENGTH, include_octave, always_positive);
        return gensym(buf);
    }
    
    static t_int8 text2wkplof(int c) {
        static constexpr t_int8 wkplof[] = {3, 5, 0, 2, 4, -1, 1};
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
