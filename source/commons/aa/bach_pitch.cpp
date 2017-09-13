//
//  bach_diatonic.cpp
//  bach
//
//  Created by Andrea Agostini on 24/08/17.
//
//

#include "bach_pitch.hpp"

const t_shortRational t_pitch::dblsharp = t_shortRational(1);
const t_shortRational t_pitch::sharp = t_shortRational(1, 2);
const t_shortRational t_pitch::qrtrsharp = t_shortRational(1, 4);
const t_shortRational t_pitch::natural = t_shortRational(0, 1);
const t_shortRational t_pitch::qrtrflat = t_shortRational(-1, 4);
const t_shortRational t_pitch::flat = t_shortRational(-1, 2);

const t_pitch t_pitch::NaP = t_pitch(0, genrat(0, 0), 0); // not a pitch
const t_pitch t_pitch::middleC = t_pitch(0, genrat(0, 1), 5); // middle C

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

t_pitch t_pitch::divdiv(const t_atom_long b) const
{
    t_stepsAndMC sat = toStepsAndMC();
    sat.steps /= b;
    sat.mc /= b;
    return t_pitch(sat);
}

t_pitch t_pitch::divdiv(const t_rational &b) const
{
    t_stepsAndMC sat = toStepsAndMC();
    sat.steps = sat.steps * b.den() / b.num();
    sat.mc /= t_shortRational(b);
    return t_pitch(sat);
}

t_pitch t_pitch::operator%(const t_pitch &b) const
{
    t_atom_long quotient = t_atom_long(double(*this / b));
    t_pitch t = b * quotient;
    return *this - t;
}

t_pitch t_pitch::operator%(const t_atom_long b) const
{
    t_stepsAndMC sat = toStepsAndMC();
    sat.steps -= (sat.steps / b) * b;
    sat.mc = t_shortRational(0);
    return t_pitch(sat);
}

std::string t_pitch::toString()
{
    std::string s;
    s = degree2name[p_degree];
    if (p_alter == natural) {
        s += std::to_string(p_octave);
    } else if (p_alter.den() == 1 || p_alter.den() == 2 || p_alter.den() == 4) {
        if (p_alter > natural) { // sharps
            t_shortRational remainder = p_alter;
            while (remainder != natural) {
                if (remainder >= dblsharp) {
                    s += 'x';
                    remainder -= dblsharp;
                } else if (remainder >= sharp) {
                    s += '#';
                    remainder -= sharp;
                } else if (remainder >= qrtrsharp) {
                    s += 'q';
                    remainder -= qrtrsharp;
                }
            }
        } else { // flats
            t_shortRational remainder = p_alter;
            while (remainder != natural) {
                if (remainder <= flat) {
                    s += 'b';
                    remainder -= flat;
                } else if (remainder <= qrtrflat) {
                    s += 'd';
                    remainder -= qrtrflat;
                }
            }
        }
        s += std::to_string(p_octave);
    } else {
        if (p_alter > natural)
            s += std::to_string(p_octave) + '+' + p_alter.to_string() + "t";
        else
            s += std::to_string(p_octave) + p_alter.to_string() + "t";
    }
    
    return s;
}
