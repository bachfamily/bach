/*
 *  bach_pitch.hpp
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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


enum {
    BACH_TUNINGSYSTEM_ET = 0,
    BACH_TUNINGSYSTEM_JI = 1,
    BACH_TUNINGSYSTEM_VERTICAL = 2,
};


class t_pitch;

#define BACH_PRIMES_JI_SIZE 25
static long primes_ji[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
static t_atom_short numFifthsPerPrimeFactor[BACH_PRIMES_JI_SIZE] = {0,1,4,-2,-1,3,7,-3,6,-2,0,2,4,-1,6};
static t_atom_short numStepsPerPrimeFactor[BACH_PRIMES_JI_SIZE] = {7,11,16,20,24,26,29,30,31,34,35,36,37,38,38};

static t_atom_short ji_alt2[BACH_PRIMES_JI_SIZE] = {1,0};
static t_atom_short ji_alt3[BACH_PRIMES_JI_SIZE] = {-11,7,0};
static t_atom_short ji_alt5[BACH_PRIMES_JI_SIZE] = {-4,4,1,0};
static t_atom_short ji_alt7[BACH_PRIMES_JI_SIZE] = {6,-2,0,-1,0};
static t_atom_short ji_alt11[BACH_PRIMES_JI_SIZE] = {-5,1,0,0,1,0};


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
    
    static t_pitchMatrices &pm;

private:
    
protected:
    
public:
    typedef struct _stepsAndMC {
        t_atom_long steps;
        t_shortRational mc;
    } t_stepsAndMC;

    char p_tuningSystem; // 0 = ordinary, 1 = ji, 2 = perhaps vertical dimension only
    t_atom_short p_degree; // 0-6, corresponding to the white keys from c to b
    t_atom_short p_octave; // middle C (MIDI note 60) starts octave 5
    t_shortRational p_alter; // in steps: # is +1/2

    t_pitch() = default;
    
    t_pitch(const t_atom_short degree) :
        p_tuningSystem(BACH_TUNINGSYSTEM_ET), p_degree(degree), p_octave(0), p_alter(t_shortRational(0)) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational alter) :
        p_tuningSystem(BACH_TUNINGSYSTEM_ET), p_degree(degree), p_octave(0), p_alter(alter) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational &alter, const t_atom_short octave) :
        p_tuningSystem(BACH_TUNINGSYSTEM_ET), p_degree(degree), p_octave(octave), p_alter(alter) {}
    
    
    void factorize(long what, t_atom_short *res, long res_size) const
    {
        t_atom_short exponent;
        long *table_last = primes_ji + BACH_PRIMES_JI_SIZE - 1;
        long *this_table = primes_ji;
        long cur = 0;
        long this_prime;
        
        // cleaning all factors
        for (long i = 0; i < res_size; i++)
            res[i] = 0;
        
        if (what < 0)
            what *= -1;
        while (what > 1 && this_table <= table_last) {
            this_prime = *this_table;
            if (what % this_prime == 0) {
                exponent = 0;
                do {
                    exponent++;
                    what /= this_prime;
                } while (what % this_prime == 0);
                res[cur] = exponent;
            }
            this_table++;
            cur++;
        }
    }
    
    t_atom_short degree() const {
        switch (p_tuningSystem) {
            case BACH_TUNINGSYSTEM_JI:
                return positive_mod(p_degree*4, 7);
                break;
                
            case BACH_TUNINGSYSTEM_VERTICAL:
                return p_degree;
                break;
                
            case BACH_TUNINGSYSTEM_ET:
            default:
                return p_degree;
                break;
        }
    }
    
    // position on the Pythagorean line of fifths
    t_atom_short plofPosition() const { return (p_tuningSystem == BACH_TUNINGSYSTEM_JI ? p_degree : 0); } // only meaningful for JI
    
    t_shortRational alter() const { return p_alter; } // only meaningful for Equal Temperament
    t_atom_short octave() const { return p_octave; }
    char tuningSystem() const { return p_tuningSystem; }
    
    
    t_stepsAndMC toStepsAndMC() const {
        t_stepsAndMC sat;
        sat.steps = degree() + p_octave * 7;
        sat.mc = toMC();
        return sat;
    }

    t_atom_short degree2MC_safe(t_atom_short p_degree) const
    {
        if (p_degree >= 0 && p_degree < 7)
            return degree2MC[p_degree];
        else
            return 0;
    }

    double f2mc(double f) const {
        return 6900 + 1200 * log2(f/440); // /0.3010299957;
    }
    
    // Pythagorean line of fifths position to frequency.
    double plof2freq(t_atom_short pos, t_atom_short octave) const {
        double freq = 260.7407407407; //middleC tuning: 440*pow(2./3., 3.)*2;
        short abs_pos = (pos >= 0 ? pos : -pos);
        short deg = 0;
        char sign = (pos >= 0 ? 1 : -1);
        double mul = (sign >= 0 ? 3./2. : 2./3.);
        for (short i = 0; i < abs_pos; i++) {
            freq *= mul;
            deg = deg + 4 * sign;
            if (deg < 0 || deg >= 7) {
                deg = positive_mod(deg, 7);
                if (sign >= 0)
                    freq /= 2.;
                else
                    freq *= 2.;
            }
        }
        return freq;
    }
    
    // Pythagorean line of fifths position to MC.
    double plof2MC(t_atom_short pos, t_atom_short octave) const {
        double fifth = 701.9550008654;
        double mc = 1200 * octave;
        short abs_pos = (pos >= 0 ? pos : -pos);
        short deg = 0;
        char sign = (pos >= 0 ? 1 : -1);
        for (short i = 1; i < abs_pos; i++) {
            mc += fifth * sign;
            deg = deg + 4 * sign;
            if (deg < 0 || deg >= 7) {
                deg = positive_mod(deg, 7);
                mc += 1200 * sign;
            }
        }
        return mc;
    }

    
    t_pitch(t_stepsAndMC sat) {
        p_tuningSystem = BACH_TUNINGSYSTEM_ET;
        p_degree = sat.steps % 7;
        if (p_degree < 0)
            p_degree += 7;
//        p_octave = t_atom_short(floor(sat.steps / 7.));
        p_octave = t_atom_short(integer_div_round_down(sat.steps, 7));
        p_alter = (sat.mc - p_octave * 1200 - degree2MC[p_degree]) / 200;
    }
    
    void set(const t_atom_short degree) {
        p_tuningSystem = BACH_TUNINGSYSTEM_ET;
        p_degree = degree;
        p_octave = 0;
        p_alter.set(0);
    }
    
    void set(const t_atom_short degree, const t_shortRational &alter) {
        p_tuningSystem = BACH_TUNINGSYSTEM_ET;
        p_degree = degree;
        p_octave = 0;
        p_alter = alter;
    }
    
    void set(const t_atom_short degree, const t_shortRational &alter, const t_atom_short octave) {
        p_tuningSystem = BACH_TUNINGSYSTEM_ET;
        p_degree = degree;
        p_octave = octave;
        p_alter = alter;
    }
    
    
    void setFromJIfundamental(t_atom_short fundamental_in_pythagorean_line_of_fifths, t_atom_short octave, t_shortRational freqRatio)
    {
        long numer = freqRatio.num();
        long denom = freqRatio.den();
        t_atom_short numer_factors[BACH_PRIMES_JI_SIZE];
        t_atom_short denom_factors[BACH_PRIMES_JI_SIZE];
        factorize(numer, numer_factors, BACH_PRIMES_JI_SIZE);
        factorize(denom, denom_factors, BACH_PRIMES_JI_SIZE);
        
        long sum = 0, steps = 0;
        for (long i = 0; i < BACH_PRIMES_JI_SIZE; i++) {
            sum += (numer_factors[i] - denom_factors[i]) * numFifthsPerPrimeFactor[i];
            steps += (numer_factors[i] - denom_factors[i]) * numStepsPerPrimeFactor[i];
        }

        p_tuningSystem = BACH_TUNINGSYSTEM_JI;
        p_degree = sum + fundamental_in_pythagorean_line_of_fifths; //positive_mod(() * 4),7);
        p_octave = (octave * 7 + positive_mod(fundamental_in_pythagorean_line_of_fifths * 4, 7) + steps)/7;
        long delta_octave = p_octave - (octave * 7 + positive_mod(fundamental_in_pythagorean_line_of_fifths * 4, 7))/7;
        
        t_shortRational comma = freqRatio;
        t_shortRational threeovertwo(3,2);
        long sum_abs = (sum >= 0 ? sum : -sum);
        long sum_sign = (sum >= 0 ? 1 : -1);
        for (long i = 0; i < sum_abs; i++) {
            if (sum_sign > 0)
                comma = comma / threeovertwo;
            else
                comma = comma * threeovertwo;
        }
        
        // refining commas removing factors of 2
        if (delta_octave > 0) {
            comma *= ipow(2, delta_octave);
        } else if (delta_octave < 0) {
            comma /= ipow(2, -delta_octave);
        }
        p_alter = comma;
    }
    
    void setFromJI(t_atom_short pythagorean_note_in_line_of_fifths, t_atom_short octave, t_shortRational comma)
    {
        p_tuningSystem = BACH_TUNINGSYSTEM_JI;
        p_degree = pythagorean_note_in_line_of_fifths;
        p_octave = octave;
        p_alter = comma;
    }
    

    t_atom_long toSteps() const { return p_octave * 7 + degree(); }

    t_atom_long toStepsFromMiddleC() const { return toSteps() - 7*5; }

    t_bool operator==(const t_pitch &b) {
        return p_tuningSystem == b.p_tuningSystem && p_degree == b.p_degree && p_octave == b.p_octave && p_alter == b.p_alter;
    }
    t_bool operator!=(const t_pitch &b) { return !(*this == b); }
    
    t_bool operator<(const t_pitch &b);
    t_bool operator<=(const t_pitch &b);
    t_bool operator>(const t_pitch &b);
    t_bool operator>=(const t_pitch &b);

    t_pitch operator-() const;
    
    t_pitch operator+(const t_pitch &b) const;
    t_pitch operator-(const t_pitch &b) const;
    t_pitch operator*(t_atom_long b) const;
    t_pitch operator*(const t_rational &b) const;
    t_pitch operator/(const t_atom_long b) const;
    t_pitch operator/(const t_rational &b) const;
    t_rational operator/(const t_pitch &b) const {
        t_rational b_toMC = b.toMC();
        if (b_toMC.r_num == 0)
            error("Illegal division by C0 (or one of its enharmonic pitches) detected.");
        return toMC() / b_toMC;
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
        if (toMC() > 0) return 1;
        else if (toMC() == 0) return 0;
        else return -1;
    }
    
    t_pitch abs() const {
        if (toMC() > 0) return *this;
        else return -*this;
    }


    template <typename T> t_pitch mod(const T b) const {
        if (toMC() > 0) return *this % b;
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
    
    t_rational toMC() const {
        switch (p_tuningSystem) {
            case BACH_TUNINGSYSTEM_JI:
            {
                if (p_alter.den() == 0)
                    return t_rational(0, 0);
                double base_freq = plof2freq(p_degree, p_octave);
                double mc = f2mc(base_freq * p_alter.num() / p_alter.den());
                // we approximate this with rationals anyway, but very finely
                return t_rational((long)mc*10000, 10000); // TO DO: abstract the approximation denominator
            }
                break;
                
            case BACH_TUNINGSYSTEM_VERTICAL:
                // TO DO
                return t_rational(0, 0);
                break;

            case BACH_TUNINGSYSTEM_ET:
            default:
            {
                if (p_alter.den() == 0)
                    return t_rational(0, 0);
                t_atom_long base = degree2MC_safe(p_degree) + p_octave * 1200;
                return base + p_alter * 200;
            }
                break;
        }
    }
    
    t_atom_long toScreenMC_wo_accidental() const {
        switch (p_tuningSystem) {
            case BACH_TUNINGSYSTEM_VERTICAL:
                // TO DO
                return 0;
                break;
                
            case BACH_TUNINGSYSTEM_JI:
            case BACH_TUNINGSYSTEM_ET:
            default:
                t_atom_long base = degree2MC_safe(degree()) + p_octave * 1200;
                return base;
                break;
        }
    }
    
    // accList must be sized BACH_PRIMES_JI_SIZE; the first two entries are irrelevant (corresponding to prime number 2 and 3)
    void toJIaccidentalList(t_atom_short *accList) const
    {
        // we must convert the ratio into the appropriate accidental
        long numer = p_alter.num();
        long denom = p_alter.den();
        t_atom_short numer_factors[BACH_PRIMES_JI_SIZE];
        t_atom_short denom_factors[BACH_PRIMES_JI_SIZE];
        factorize(numer, numer_factors, BACH_PRIMES_JI_SIZE);
        factorize(denom, denom_factors, BACH_PRIMES_JI_SIZE);

//        t_atom_short diff_array[BACH_PRIMES_JI_SIZE];
        for (long i = 0; i < BACH_PRIMES_JI_SIZE; i++)
            accList[i] = numer_factors[i] - denom_factors[i];
        
        // disregard 2 (identity) and 3 (already accounted for by the pythagorean enharmonic spelling)
//        for (long i = 2; i < BACH_PRIMES_JI_SIZE; i++) {
            
//        }
    }
    
    
    t_pitch enharm(long delta_steps) const {
        t_stepsAndMC smc = this->toStepsAndMC();
        smc.steps += delta_steps;
        return t_pitch(smc);
    }
    
    t_pitch autoenharm(long tone_division, e_accidentals_preferences accidentals_preferences, t_rational *key_acc_pattern, t_rational *full_repr) const {
        return fromMC(this->toMC(), tone_division, accidentals_preferences, key_acc_pattern, full_repr);
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
    
    t_pitch approx(t_atom_long tone_division)
    {
        if (tone_division <= 0)
            return *this;
        t_shortRational temp = p_alter * tone_division;
        t_shortRational new_alter_down(temp.r_num / temp.r_den, static_cast<t_atom_short>(tone_division));
        t_shortRational new_alter_up((temp.r_num / temp.r_den) + 1, static_cast<t_atom_short>(tone_division));
        return t_pitch(p_degree, (new_alter_up - p_alter < p_alter - new_alter_down) ? new_alter_up : new_alter_down, p_octave);
    }

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
    
    long toTextBuf(char *buf, long bufSize, t_bool include_octave = true, t_bool always_positive = false, t_bool addTrailingSpace = false) const;
    
    
    t_symbol* toSym(t_bool include_octave = true, t_bool always_positive = false) const
    {
        char buf[MAX_SYM_LENGTH];
        toTextBuf(buf, MAX_SYM_LENGTH, include_octave, always_positive);
        return gensym(buf);
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
