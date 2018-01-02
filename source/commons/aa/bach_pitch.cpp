//
//  bach_diatonic.cpp
//  bach
//
//  Created by Andrea Agostini on 24/08/17.
//
//

#include "bach_pitch.hpp"
#include "bach_mem.h"

const t_shortRational t_pitch::dblsharp = t_shortRational(1);
const t_shortRational t_pitch::sharp = t_shortRational(1, 2);
const t_shortRational t_pitch::qrtrsharp = t_shortRational(1, 4);
const t_shortRational t_pitch::eighthsharp = t_shortRational(1, 8);

const t_shortRational t_pitch::natural = t_shortRational(0, 1);
const t_shortRational t_pitch::flat = t_shortRational(-1, 2);
const t_shortRational t_pitch::qrtrflat = t_shortRational(-1, 4);
const t_shortRational t_pitch::eighthflat = t_shortRational(-1, 8);

const t_shortRational t_pitch::illegal = t_shortRational(0, 0);

const t_pitch t_pitch::NaP = t_pitch(0, illegal, 0); // not a pitch
const t_pitch t_pitch::middleC = t_pitch(0, natural, 5); // middle C
const t_pitch t_pitch::C0 = t_pitch(0, natural, 0); // C0

const t_atom_short t_pitch::degree2MC[] = {0, 200, 400, 500, 700, 900, 1100};
const t_atom_short t_pitch::degree2PC[] = {0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 17, 19, 21, 23};
const t_atom_short t_pitch::PC2degree[] = {0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6};
const char t_pitch::degree2name[] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B' };

t_pitchMatrices& t_pitch::pm = t_pitchMatrices::getInstance();

t_pitch t_pitchMatrices::getSum(const t_atom_short a, const t_atom_short b)
{
    return getInstance().sumMatrix[a * 7 + b];
}

t_pitch t_pitchMatrices::getDiff(const t_atom_short a, const t_atom_short b)
{
    return getInstance().diffMatrix[a * 7 + b];
}

t_pitchMatrices::t_pitchMatrices()
{
    int a, b;
    sumMatrix = (t_pitch *) bach_newptr(49 * sizeof(t_pitch));
    diffMatrix = (t_pitch *) bach_newptr(49 * sizeof(t_pitch));
    for (a = 0; a < 7; a++) {
        for (b = 0; b < 7; b++) {
            t_atom_short rawdegree, correction;
            
            // sum
            rawdegree = a + b;
            correction = t_pitch::degree2PC[a] + t_pitch::degree2PC[b] - t_pitch::degree2PC[rawdegree];
            sumMatrix[a * 7 + b].set(rawdegree % 7, t_shortRational(correction, 2), rawdegree / 7);
            
            // difference
            t_atom_short aa = a + 7;
            rawdegree = aa - b;
            correction = t_pitch::degree2PC[aa] - t_pitch::degree2PC[b] - t_pitch::degree2PC[rawdegree];
            diffMatrix[a * 7 + b].set(rawdegree % 7, t_shortRational(correction, 2), rawdegree / 7 - 1);
        }
    }
}

#ifdef othercomparison
t_bool t_pitch::operator<(const t_pitch &b)
{
    t_rational thisMC = toMC();
    t_rational bMC = b.toMC();
    if (thisMC != bMC)
        return thisMC < bMC;
    if (p_octave != b.p_octave)
        return p_octave < b.p_octave;
    return p_alter < b.p_alter;
}

t_bool t_pitch::operator>(const t_pitch &b)
{
    t_rational thisMC = toMC();
    t_rational bMC = b.toMC();
    if (thisMC != bMC)
        return thisMC > bMC;
    if (p_octave != b.p_octave)
        return p_octave > b.p_octave;
    return p_alter > b.p_alter;
}

#endif // othercomparison

t_bool t_pitch::operator<(const t_pitch &b)
{
    if (p_octave != b.p_octave)
        return p_octave < b.p_octave;
    else if (p_degree != b.p_degree)
        return p_degree < b.p_degree;
    else
        return toMC() < b.toMC();
}

t_bool t_pitch::operator>(const t_pitch &b)
{
    if (p_octave != b.p_octave)
        return p_octave > b.p_octave;
    else if (p_degree != b.p_degree)
        return p_degree > b.p_degree;
    else
        return toMC() > b.toMC();
}

t_bool t_pitch::operator<=(const t_pitch &b)
{
    if (*this == b)
        return true;
    return *this < b;
}

t_bool t_pitch::operator>=(const t_pitch &b)
{
    if (*this == b)
        return true;
    return *this > b;
}


t_pitch t_pitch::operator-() const
{
    return t_pitch(0) - *this;
}

t_pitch t_pitch::operator+(const t_pitch &b) const
{
    t_pitch sum = t_pitchMatrices::getSum(p_degree, b.p_degree);
    sum.p_octave += p_octave + b.p_octave;
    sum.p_alter += p_alter + b.p_alter;
    return sum;
}

t_pitch t_pitch::operator-(const t_pitch &b) const
{
    t_pitch diff = t_pitchMatrices::getDiff(p_degree, b.p_degree);
    diff.p_octave += p_octave - b.p_octave;
    diff.p_alter += p_alter - b.p_alter;
    return diff;
}

t_pitch t_pitch::operator*(t_atom_long b) const
{
    t_stepsAndMC sat = toStepsAndMC();
    sat.steps *= b;
    sat.mc *= b;
    return t_pitch(sat);
}

t_pitch t_pitch::operator*(const t_rational &b) const
{
    t_rat<long> inv = b.inv();

    if (inv.r_num == 0 || inv.r_den == 0)
        return t_pitch::NaP;

    return *this / b.inv();
}

t_pitch t_pitch::operator/(const t_atom_long b) const
{
    if (b == 0)
        return t_pitch::NaP;
    
    t_stepsAndMC sat = toStepsAndMC();
    sat.steps /= b;
    sat.mc /= b;
    return t_pitch(sat);
}

t_pitch t_pitch::operator/(const t_rational &b) const
{
    if (b.r_num == 0 || b.r_den == 0)
        return t_pitch::NaP;

    t_stepsAndMC sat = toStepsAndMC();
    sat.steps = sat.steps * b.den() / b.num();
    sat.mc /= t_shortRational(b);
    return t_pitch(sat);
}

t_pitch t_pitch::operator%(const t_pitch &b) const
{
    if (b.toMC() == 0)
        return t_pitch::NaP;

    t_atom_long quotient = t_atom_long(double(*this / b));
    t_pitch t = b * quotient;
    return *this - t;
}

t_pitch t_pitch::operator%(const t_atom_long b) const
{
    if (b == 0)
        return t_pitch::NaP;
    
    t_stepsAndMC sat = toStepsAndMC();
    sat.steps -= (sat.steps / b) * b;
    sat.mc = t_shortRational(0);
    return t_pitch(sat);
}

long t_pitch::toTextBuf(char *buf, long bufSize, t_bool include_octave, t_bool always_positive, t_bool addTrailingSpace)
{
    long count = 0;
    if (!buf || bufSize == 0)
        return -1;
    if (p_alter == illegal) {
        if (addTrailingSpace)
            return snprintf_zero(buf, bufSize, "NaP ");
        else
            return snprintf_zero(buf, bufSize, "NaP");
    } else if (p_octave >= 0 || always_positive) {
        if (++count == bufSize) { *buf = 0; return count - 1; }
        *(buf++) = degree2name[p_degree];
        t_shortRational remainder = p_alter;
        if (remainder > natural) { // sharps
            /* // this is probably not convenient, as it complicates simple cases
             s += std::string("x", t_atom_long(remainder / dblsharp));
             remainder %= dblsharp;
             
             s += std::string("#", t_atom_long(remainder / sharp));
             remainder %= sharp;
             
             s += std::string("q", t_atom_long(remainder / qrtrsharp));
             remainder %= qrtrsharp;
             
             s += std::string("^", t_atom_long(remainder / eighthsharp));
             remainder %= eighthsharp;
             */
            
            while (remainder >= eighthsharp) {
                if (++count == bufSize) { *buf = 0; return count - 1; }
                if (remainder >= dblsharp) {
                    *(buf++) = 'x';
                    remainder -= dblsharp;
                } else if (remainder >= sharp) {
                    *(buf++) = '#';
                    remainder -= sharp;
                } else if (remainder >= qrtrsharp) {
                    *(buf++) = 'q';
                    remainder -= qrtrsharp;
                } else if (remainder >= eighthsharp) {
                    *(buf++) = '^';
                    remainder -= eighthsharp;
                }
            }
        } else if (remainder < natural) { // flats
            while (remainder <= eighthflat) {
                if (++count == bufSize) { *buf = 0; return count - 1; }
                if (remainder <= flat) {
                    *(buf++) = 'b';
                    remainder -= flat;
                } else if (remainder <= qrtrflat) {
                    *(buf++) = 'd';
                    remainder -= qrtrflat;
                } else if (remainder <= eighthflat) {
                    *(buf++) = 'v';
                    remainder -= eighthflat;
                }
            }
        }
        
        long len = 0;
        
        if (include_octave) {
            if (remainder > natural)
                len = snprintf_zero(buf, bufSize - count, "%d+%d/%dt", p_octave, remainder.num(), remainder.den());
            else if (remainder < natural)
                len = snprintf_zero(buf, bufSize - count, "%d%d/%dt", p_octave, remainder.num(), remainder.den());
            else
                len= snprintf_zero(buf, bufSize - count, "%d", p_octave);
        } else {
            if (remainder > natural)
                len = snprintf_zero(buf, bufSize - count, "+%d/%dt", remainder.num(), remainder.den());
            else if (remainder < natural)
                len = snprintf_zero(buf, bufSize - count, "%d/%dt", remainder.num(), remainder.den());
        }
        buf += len;
        count += len;
    } else { // if (octave < 0 && !always_positive)
        t_pitch mirrored = -*this;
        if (++count == bufSize) { *buf = 0; return count - 1; }
        *(buf++) = '-';
        if (++count == bufSize) { *buf = 0; return count - 1; }
        *(buf++) = degree2name[mirrored.p_degree];
        t_shortRational remainder = mirrored.p_alter;
        if (remainder > natural) { // sharps
            /* // this is probably not convenient, as it complicates simple cases
             s += std::string("x", t_atom_long(remainder / dblsharp));
             remainder %= dblsharp;
             
             s += std::string("#", t_atom_long(remainder / sharp));
             remainder %= sharp;
             
             s += std::string("q", t_atom_long(remainder / qrtrsharp));
             remainder %= qrtrsharp;
             
             s += std::string("^", t_atom_long(remainder / eighthsharp));
             remainder %= eighthsharp;
             */
            
            while (remainder >= eighthsharp) {
                if (++count == bufSize) { *buf = 0; return count - 1; }
                if (remainder >= dblsharp) {
                    *(buf++) = 'x';
                    remainder -= dblsharp;
                } else if (remainder >= sharp) {
                    *(buf++) = '#';
                    remainder -= sharp;
                } else if (remainder >= qrtrsharp) {
                    *(buf++) = 'q';
                    remainder -= qrtrsharp;
                } else if (remainder >= eighthsharp) {
                    *(buf++) = '^';
                    remainder -= eighthsharp;
                }
            }
            remainder *= -1;
        } else if (remainder < natural) { // flats
            while (remainder <= eighthflat) {
                if (++count == bufSize) { *buf = 0; return count - 1; }
                if (remainder <= flat) {
                    *(buf++) = 'b';
                    remainder -= flat;
                } else if (remainder <= qrtrflat) {
                    *(buf++) = 'd';
                    remainder -= qrtrflat;
                } else if (remainder <= eighthflat) {
                    *(buf++) = 'v';
                    remainder -= eighthflat;
                }
            }
            remainder *= -1;
        }
        
        long len = 0;

        if (include_octave) {
            if (remainder > natural)
                len = snprintf_zero(buf, bufSize - count, "%d+%d/%dt", mirrored.octave(), remainder.num(), remainder.den());
            else if (remainder < natural)
                len = snprintf_zero(buf, bufSize - count, "%d%d/%dt", mirrored.octave(), remainder.num(), remainder.den());
            else
                len = snprintf_zero(buf, bufSize - count, "%d", mirrored.octave());
        } else {
            if (remainder > natural)
                len = snprintf_zero(buf, bufSize - count, "+%d/%dt", remainder.num(), remainder.den());
            else if (remainder < natural)
                len = snprintf_zero(buf, bufSize - count, "%d/%dt", remainder.num(), remainder.den());
        }
        buf += len;
        count += len;
    }
    if (!addTrailingSpace || count == bufSize - 1) {
        *(buf) = 0;
        return count;
    }
    *(buf) = ' ';
    *(buf + 1) = 0;
    return count + 1;
}


long mod_positive(long num, long mod)
{
    if (num >= 0)
        return num % mod;
    
    return ((num % mod) + mod) % mod;
}

long floor_div_by_7(long num)
{
    return num / 7 - (num % 7 < 0);
}

t_pitch t_pitch::fromMC(double mc, long tone_division, e_accidentals_preferences accidentals_preferences, t_rational *key_acc_pattern, t_rational *full_repr)
{
    long original_tone_division = tone_division;
    
    if (tone_division == 0)
        tone_division = 8;
    
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
    
    if (original_tone_division == 0) {
        // obtaining the most precise alteration possible
        t_pitch p1 = t_pitch(mod_positive(steps, 7), long2rat(0), floor_div_by_7(steps));
        t_rational mc1 = p1.toMC();
        t_rational mc_orig = approx_double_with_rat_fixed_den(mc, 100, 0, NULL);
        accidental = (mc_orig - mc1)/200;
    }
    
    return t_pitch(mod_positive(steps, 7), accidental, floor_div_by_7(steps));
}
