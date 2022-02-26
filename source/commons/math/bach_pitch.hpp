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

    t_atom_short p_degree; // 0-6, corresponding to the white keys from c to b
    t_atom_short p_octave; // middle C (MIDI note 60) starts octave 5
    t_shortRational p_alter; // in steps: # is +1/2

    t_pitch() = default;
    
    t_pitch(const t_atom_short degree) :
        p_degree(degree), p_octave(0), p_alter(t_shortRational(0)) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational alter) :
        p_degree(degree), p_octave(0), p_alter(alter) {}
    
    t_pitch(const t_atom_short degree, const t_shortRational &alter, const t_atom_short octave) :
        p_degree(degree), p_octave(octave), p_alter(alter) {}
    
    t_stepsAndMC toStepsAndMC() const {
        t_stepsAndMC sat;
        sat.steps = p_degree + p_octave * 7;
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

    t_pitch(t_stepsAndMC sat) {
        p_degree = sat.steps % 7;
        if (p_degree < 0)
            p_degree += 7;
//        p_octave = t_atom_short(floor(sat.steps / 7.));
        p_octave = t_atom_short(integer_div_round_down(sat.steps, 7));
        p_alter = (sat.mc - p_octave * 1200 - degree2MC[p_degree]) / 200;
    }
    
    void set(const t_atom_short degree) {
        p_degree = degree;
        p_octave = 0;
        p_alter.set(0);
    }
    
    void set(const t_atom_short degree, const t_shortRational &alter) {
        p_degree = degree;
        p_octave = 0;
        p_alter = alter;
    }
    
    void set(const t_atom_short degree, const t_shortRational &alter, const t_atom_short octave) {
        p_degree = degree;
        p_octave = octave;
        p_alter = alter;
    }
    
    t_atom_short degree() const { return p_degree; }
    t_shortRational alter() const { return p_alter; }
    t_atom_short octave() const { return p_octave; }

    t_atom_long toSteps() const { return p_octave * 7 + p_degree; }

    t_atom_long toStepsFromMiddleC() const { return toSteps() - 7*5; }

    t_bool operator==(const t_pitch &b) {
        return p_degree == b.p_degree && p_octave == b.p_octave && p_alter == b.p_alter;
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
        if (p_alter.den() == 0)
            return t_rational(0, 0);
        t_atom_long base = degree2MC_safe(p_degree) + p_octave * 1200;
        return base + p_alter * 200;
    }
    
    t_atom_long toMC_wo_accidental() const {
        t_atom_long base = degree2MC_safe(p_degree) + p_octave * 1200;
        return base;
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
