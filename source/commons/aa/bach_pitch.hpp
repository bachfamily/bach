//
//  bach_diatonic.hpp
//  bach
//
//  Created by Andrea Agostini on 24/08/17.
//
//

#ifndef bach_pitch_hpp
#define bach_pitch_hpp

#include <string>
#include "bach_mem.h"
#include "rational.h"


/** Accidental preferences.
	@ingroup	pitch
 */
typedef enum _accidentals_preferences {
    k_ACC_AUTO = 0,	///< Automatic choice of accidentals
    k_ACC_SHARPS,	///< Prefer the use of sharps
    k_ACC_FLATS,	///< Prefer the use of flats
    k_ACC_CUSTOM,	///< Accidental are explicitely defined via the "enharmonictable" attribute, and thus the t_notation_obj::full_acc_repr symbol
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
    static const t_atom_short degree2MC[];
    static const t_atom_short degree2PC[];
    static const t_atom_short PC2degree[];
    static const char degree2name[];
    static const t_shortRational dblsharp;
    static const t_shortRational sharp;
    static const t_shortRational qrtrsharp;
    static const t_shortRational natural;
    static const t_shortRational qrtrflat;
    static const t_shortRational flat;
    static t_pitchMatrices &pm;

private:
    
protected:
    
public:
    typedef struct _stepsAndTones {
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
        p_octave = t_atom_short(floor(sat.steps / 7.));
        p_alter = (sat.mc - p_octave * 1200 - degree2MC_safe(p_degree)) / 200;
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
    t_rational operator/(const t_rational &b) const { return toMC() / b; } ;
    t_rational operator/(const t_pitch &b) const { return toMC() / b.toMC(); };
    t_pitch divdiv(const t_rational &b) const;
    t_pitch divdiv(const t_atom_long b) const;
    t_pitch operator%(const t_atom_long b) const;
    t_pitch operator%(const t_pitch &b) const;
    
    friend t_pitch operator*(const t_atom_long a, const t_pitch b) { return b * a; }
    
    t_pitch operator+=(const t_pitch &b) { return *this = *this + b; }
    t_pitch operator-=(const t_pitch &b) { return *this = *this - b; }
    t_pitch operator*=(t_atom_short b) { return *this = *this * b; }
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

    static t_pitch fromMC(double mc, long tone_division, e_accidentals_preferences accidentals_preferences, t_rational *key_acc_pattern, t_rational *full_repr)
    {
        // converts a midicents number in the accidentals, with respect to the given full_accidental_representation (representing for each note)
        double fl = floor(mc/1200);
        double step_mc = 200. / tone_division;
        double rescaled = (mc - 1200 * fl) / step_mc; // this is a scaled value which tells us where the mc are with respect to the normalized grid 0 1 2 3 4 5...
        long gridstep = (long)round(rescaled); // step index on the microtonal grid
        long numsteps = 6 * tone_division;
        long add_one_octave = (gridstep >= numsteps); // if the grid step is numsteps, we need to add 1 octave
        long add_another_octave = 0;
        double gridstep_12norm;
        double natural_steps[8];
        long natural_approx_diatstep = -1, natural_approx_step = -1, i;
        t_rational natural_ratio, grid_ratio;
        const double PERFECT_MATCH_THRESHOLD = 0.0005;
        
        gridstep %= numsteps; // modulo the number of steps of the grid
        
        // now we have the step, we gotta find what it means with respect to the NATURAL notes.
        // where is the closest natural notes with respect to the grid?
        // e.g. i'm at gridstep 3 in a 24-TET; gotta normalize it at 12...
        gridstep_12norm = gridstep * 12. / numsteps; // ...so that now our 3 becomes 1.5
        
        
        // now we have to find the 12-degree natural approximation {0, 2, 4, 5, 7, 9, 11} that suits our gridstep_12norm
        
        natural_steps[0] = 0.;
        natural_steps[1] = 2.;
        natural_steps[2] = 4.;
        natural_steps[3] = 5.;
        natural_steps[4] = 7.;
        natural_steps[5] = 9.;
        natural_steps[6] = 11.;
        natural_steps[7] = 12.;
        
        // test the full_repr, if any
        if (natural_approx_step < 0 && full_repr && (tone_division == 2 || tone_division == 4 || tone_division == 8)) {
            double gridstep_48norm = gridstep * 48. / numsteps;
            long round_gridstep_48norm = round(gridstep_48norm);
            
            if (fabs(round_gridstep_48norm - gridstep_48norm) < PERFECT_MATCH_THRESHOLD || fabs(round_gridstep_48norm - gridstep_48norm) > 12. - PERFECT_MATCH_THRESHOLD){
                // precise match
                
                if (round_gridstep_48norm >= 48) {
                    round_gridstep_48norm -= 48;
                    add_another_octave = 1;
                } else if (round_gridstep_48norm < 0) {
                    round_gridstep_48norm += 48;
                    add_another_octave = -1;
                }
                if (round_gridstep_48norm < 0 || round_gridstep_48norm >= 48) {
                    dev_post("Bug in mc_to_screen_approximation_do!");
                    round_gridstep_48norm = 0;
                }
                t_rational acc = full_repr[round_gridstep_48norm];
                t_rational prod = rat_long_prod(acc, 8);
                double approx_step = (round_gridstep_48norm - prod.r_num)/4.;
                
                if (prod.r_den == 1) {
                    long j = -1;
                    for (long i = 0; i < 7; i++) {
                        double diff = fabs(approx_step - natural_steps[i]);
                        if (diff < PERFECT_MATCH_THRESHOLD || diff > 12 - PERFECT_MATCH_THRESHOLD) {
                            j = i;
                            break;
                        }
                    }
                    
                    if (j >= 0) {
                        natural_approx_diatstep = j;
                        natural_approx_step = round(approx_step);
                        if (natural_approx_step < 0) {
                            natural_approx_step += 12;
                            add_another_octave = -1;
                        } else if (natural_approx_step > 11) {
                            natural_approx_step -= 12;
                            add_another_octave = 1;
                        }
                    }
                }
            }
        }
        
        
        // if not found, test the key degrees
        if (natural_approx_step < 0 && key_acc_pattern) { // see if it fits to a step in the current key
            for (i = 0; i < 7; i++){
                double pattern_step = natural_steps[i] + rat2double(key_acc_pattern[i]) * 2.;
                if (fabs(gridstep_12norm - pattern_step) < PERFECT_MATCH_THRESHOLD || fabs(gridstep_12norm - pattern_step) > 12. - PERFECT_MATCH_THRESHOLD) {
                    natural_approx_diatstep = i;
                    natural_approx_step = natural_steps[i];
                    if (gridstep_12norm > natural_approx_step && key_acc_pattern[i].r_num < 0)
                    add_another_octave = 1;
                    else if (gridstep_12norm < natural_approx_step && key_acc_pattern[i].r_num > 0)
                    add_another_octave = -1;
                    break;
                }
            }
        }
        
        // if not found, test the natural notes
        if (natural_approx_step < 0) {
            for (i = 0; i < 7; i++){
                if (fabs(gridstep_12norm - natural_steps[i]) < PERFECT_MATCH_THRESHOLD || fabs(gridstep_12norm - natural_steps[i]) > 12. - PERFECT_MATCH_THRESHOLD) {
                    natural_approx_diatstep = i;
                    natural_approx_step = natural_steps[i];
                    break;
                }
            }
        }
        
        // if not found, test the intermediate steps
        if (natural_approx_step < 0) {
            for (i = 0; i < 7; i++){
                if (gridstep_12norm > natural_steps[i] && gridstep_12norm < natural_steps[i+1]) {
                    if (accidentals_preferences == k_ACC_FLATS) {
                        natural_approx_diatstep = i+1;
                        natural_approx_step = natural_steps[i+1];
                    } else if (accidentals_preferences == k_ACC_SHARPS) {
                        natural_approx_diatstep = i;
                        natural_approx_step = natural_steps[i];
                    } else { // auto
                        // Default enharmonicity: we privilegiate Bb, Ab, Eb and all the rest will be sharps
                        if (natural_steps[i] == 9. || natural_steps[i] == 7. || natural_steps[i] == 2.) {
                            if (gridstep_12norm >= (natural_steps[i] + natural_steps[i+1])/2.) {
                                natural_approx_diatstep = i+1;
                                natural_approx_step = natural_steps[i+1];
                            } else {
                                natural_approx_diatstep = i;
                                natural_approx_step = natural_steps[i];
                            }
                        } else {
                            if (gridstep_12norm > (natural_steps[i] + natural_steps[i+1])/2.) {
                                natural_approx_diatstep = i+1;
                                natural_approx_step = natural_steps[i+1];
                            } else {
                                natural_approx_diatstep = i;
                                natural_approx_step = natural_steps[i];
                            }
                        }
                    }
                }
            }
        }
        
        
        long steps = ((long) fl + add_one_octave + add_another_octave) * 7 + natural_approx_diatstep;
        
        natural_ratio.r_num = natural_approx_step + 12 * add_another_octave;
        natural_ratio.r_den = 12;
        grid_ratio.r_num = gridstep;
        grid_ratio.r_den = numsteps;
        
        t_rational accidental = rat_rat_diff(grid_ratio, natural_ratio) * 6;
        
        return t_pitch(steps % 7, accidental, steps / 7);
    }
    
    static t_pitch fromMC(double mc, long tone_division, e_accidentals_preferences accidentals_preferences)
    {
        return fromMC(mc, tone_division, accidentals_preferences, NULL, NULL);
    }
    
    static t_pitch fromMC(double mc)
    {
        return fromMC(mc, 2, k_ACC_AUTO, NULL, NULL);
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
        res.p_alter = t_shortRational((absolutepitch - t_pitch::degree2MC[res.p_degree])/200);
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
    
    
    t_bool isNaP() const {
        return (p_alter.r_den == 0);
    }
    
    std::string toString();
    
    const char* toCString() { return toString().c_str(); }

    t_symbol* toSym() { return gensym(toString().c_str()); }

/*
    t_pitch fromSym(t_symbol *s)
    {
        long ac = 1;
        t_atom av;
        t_pitch pitch = t_pitch::NaP;
        atom_setsym(&av, s);
        t_llll *ll = llll_parse_with_leveltypes(ac, &av);
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
                case '#':	alter += t_pitch::sharp;		(*pos)++;	break;
                case 'b':	alter += t_pitch::flat;			(*pos)++;	break;
                case 'x':	alter += t_pitch::dblsharp;		(*pos)++;	break;
                case 'q':	alter += t_pitch::qrtrsharp;	(*pos)++;	break;
                case 'd':	alter += t_pitch::qrtrflat;		(*pos)++;	break;
                default:	go = 0;	break;
            }
        }
        return alter;
    }
    
    static int text2degree(char name)
    {
        char notename = tolower(name);
        return notename >= 'c' ? notename - 'c' : notename - 'a' + 5;
    }
};



#endif /* bach_pitch_hpp */
