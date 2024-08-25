/*
 *  bach_pitch.cpp
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

#include "math/bach_pitch.hpp"
#include "foundation/bach_mem.h"
#include "math/bach_math_utilities.h"
#include <string>


inline long divdiv_floor(long a, long b) {
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    return a / b - (a % b < 0);
}

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

const t_atom_short t_pitch::whiteKey2MC[] = {0, 200, 400, 500, 700, 900, 1100};
const t_atom_short t_pitch::whiteKey2Plof[] = {0, 2, 4, -1, 1, 3, 5};
const t_atom_short t_pitch::degree2PC[] = {0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 17, 19, 21, 23};
const t_atom_short t_pitch::PC2degree[] = {0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6};
const char t_pitch::degree2name[] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B' };

//const t_rational t_pitch::primes_inv[BACH_PRIMES_JI_SIZE] = {{1, 2}, {1, 3}, {1, 5}, {1, 7}, {1, 11}, {1, 13}, {1, 17}, {1, 19}, {1, 23}, {1, 29}, {1, 31}, {1, 37}, {1, 41}, {1, 47}, {1, 53}};

const t_rational t_pitch::HEJIcommasRatios[BACH_PRIMES_JI_SIZE-2] = {{81,80}, {64,63}, {32,33}, {27,26}, {2187,2176}, {512,513}, {729,736}, {256,261}, {32,31}, {36,37}, {81,82}, {128,129}, {729,752}};


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
            sumMatrix[a * 7 + b].setET(rawdegree % 7, t_shortRational(correction, 2), rawdegree / 7); // it's ok because rawdegree >= 0
            
            // difference
            t_atom_short aa = a + 7;
            rawdegree = aa - b;
            correction = t_pitch::degree2PC[aa] - t_pitch::degree2PC[b] - t_pitch::degree2PC[rawdegree];
            diffMatrix[a * 7 + b].setET(rawdegree % 7, t_shortRational(correction, 2), rawdegree / 7 - 1); // it's ok because rawdegree >= 0
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
    return p_alterET < b.p_alterET;
}

t_bool t_pitch::operator>(const t_pitch &b)
{
    t_rational thisMC = toMC();
    t_rational bMC = b.toMC();
    if (thisMC != bMC)
        return thisMC > bMC;
    if (p_octave != b.p_octave)
        return p_octave > b.p_octave;
    return p_alterET > b.p_alterET;
}

#endif // othercomparison

void t_pitch::expVector::clear() {
    memset(data, 0, 11);
}

void t_pitch::expVector::set(const std::vector<int8_t> &v) {
    clear();
    const size_t s = v.size();
    //const int8_t* d = v.data();
    int i;
    /*
    if (s < 8) {
        for (i = 0; i < s && i < 7; i++) {
            data[i] = d[i];
        }
        return;
    }
    
    *(reinterpret_cast<int64_t*>(data)) = *(reinterpret_cast<const int64_t*>(d)); // copy 8 bytes in one shot. is it worth it?
    data[7] = (d[8] & 0x0f) | ((d[7] & 0x0f) << 4); // ...the 8th byte is discarded though...
    
    switch(s) {
        case 11:    data[10] = (d[14] & 0x0f) | ((d[13] & 0x0f) << 4);
        case 10:    data[9] = (d[12] & 0x0f) | ((d[11] & 0x0f) << 4);
        case 9:     data[8] = (d[10] & 0x0f) | ((d[9] & 0x0f) << 4);
    }
     */
    
    for (i = 0; i < s && i < 7; i++) {
        data[i] = v[i];
    }
    for (; i < s && i < 15; i++) {
        setHighPrimeUnsafe(i, v[i]);
    }
}

void t_pitch::expVector::setHighPrimeUnsafe(const int idx, const int8_t v) {
        if (idx & 1) {
            data[(idx - 7) / 2 + 7] |= (v & 0x0f) << 4;
        } else {
            data[(idx - 8) / 2 + 7] |= (v & 0x0f);
        }
        return;
}

void t_pitch::expVector::set(const int idx, const int8_t v) {
    if (idx >= 0 && idx <= 6) {
        data[idx] = v;
        return;
    }
    if (idx >= 7 && idx <= 14) {
        if (idx & 1) {
            data[(idx - 7) / 2 + 7] |= (v & 0x0f) << 4;
        } else {
            data[(idx - 8) / 2 + 7] |= (v & 0x0f);
        }
        return;
    }
}

std::vector<int8_t> t_pitch::expVector::get() const {
    std::vector<int8_t> v(15);
    int8_t* d = v.data();
    *(reinterpret_cast<int64_t*>(d)) = *(reinterpret_cast<const int64_t*>(data));
    v[7] = getLNibble(data[7]);
    v[8] = getRNibble(data[7]);
    v[9] = getLNibble(data[8]);
    v[10] = getRNibble(data[8]);
    v[11] = getLNibble(data[9]);
    v[12] = getRNibble(data[9]);
    v[13] = getLNibble(data[10]);
    v[14] = getRNibble(data[10]);
    return v;
}

int8_t t_pitch::expVector::get(const int idx) const {
    if (idx >= 0 && idx <= 6) {
        return data[idx];
    }
    if (idx >= 7 && idx <= 14) {
        if (idx & 1) {
            return getLNibble(data[(idx - 7) / 2 + 7]);
        } else {
            return getRNibble(data[(idx - 8) / 2 + 7]);
        }
    }
    return 0;
}

bool t_pitch::expVector::operator==(const t_pitch::expVector& b) const
{
    return *(reinterpret_cast<const int64_t*>(data)) == *(reinterpret_cast<const int64_t*>(b.data)) && *(reinterpret_cast<const int16_t*>(data + 8)) == *(reinterpret_cast<const int16_t*>(b.data + 8)) && *(reinterpret_cast<const int8_t*>(data + 10)) == *(reinterpret_cast<const int8_t*>(b.data + 10));
}

t_pitch::expVector t_pitch::expVector::operator+(const t_pitch::expVector& b) const
{
    expVector r;
    int i;
    for (i = 0; i < 7; i++)
        r.data[i] = data[i] + b.data[i];
    for ( ; i < 11; i++)
        r.data[i] = (((getLNibble(data[i]) + getLNibble(b.data[i])) & 0x0f) << 4) + ((getRNibble(data[i]) + getRNibble(b.data[i])) & 0x0f);
    return r;
}

t_pitch::expVector t_pitch::expVector::operator-(const t_pitch::expVector& b) const
{
    expVector r;
    int i;
    for (i = 0; i < 7; i++)
        r.data[i] = data[i] - b.data[i];
    for ( ; i < 11; i++)
        r.data[i] = (((getLNibble(data[i]) - getLNibble(b.data[i])) & 0x0f) << 4) | ((getRNibble(data[i]) - getRNibble(b.data[i])) & 0x0f);
    return r;
}

t_pitch::expVector t_pitch::expVector::operator*(const t_pitch::expVector& b) const
{
    expVector r;
    int i;
    for (i = 0; i < 7; i++)
        r.data[i] = data[i] * b.data[i];
    for ( ; i < 11; i++)
        r.data[i] = (((getLNibble(data[i]) * getLNibble(b.data[i])) & 0x0f) << 4) + ((getRNibble(data[i]) * getRNibble(b.data[i])) & 0x0f);
    return r;
}

t_pitch::expVector t_pitch::expVector::operator*(t_atom_long b) const
{
    expVector r;
    int i;
    for (i = 0; i < 7; i++)
        r.data[i] = data[i] * b;
    for ( ; i < 11; i++)
        r.data[i] = (((getLNibble(data[i]) * b) & 0x0f) << 4) + ((getRNibble(data[i]) * b) & 0x0f);
    return r;
}

t_pitch::expVector t_pitch::expVector::operator/(t_atom_long b) const
{
    expVector r;
    int i;
    for (i = 0; i < 7; i++)
        r.data[i] = data[i] / b;
    for ( ; i < 11; i++)
        r.data[i] = (((getLNibble(data[i]) / b) & 0x0f) << 4) + ((getRNibble(data[i]) / b) & 0x0f);
    return r;
}

t_pitch::expVector t_pitch::expVector::operator/(const t_pitch::expVector& b) const
{
    expVector r;
    int i;
    for (i = 0; i < 7; i++)
        r.data[i] = data[i] / b.data[i];
    for ( ; i < 11; i++)
        r.data[i] = (((getLNibble(data[i]) / getLNibble(b.data[i])) & 0x0f) << 4) + ((getRNibble(data[i]) / getRNibble(b.data[i])) & 0x0f);
    return r;
}

t_pitch::expVector t_pitch::expVector::operator-() const
{
    expVector r;
    int i;
    for (i = 0; i < 7; i++)
        r.data[i] = -data[i];
    for ( ; i < 11; i++)
        r.data[i] = (((-getLNibble(data[i])) & 0x0f) << 4) + ((-getRNibble(data[i])) & 0x0f);
    return r;
}

t_rational t_pitch::expVector::getRatio() const {
    t_rational r({1, 1});
    int i;
    for (i = 0; i < BACH_PRIMES_JI_SIZE; i++) {
        long d = get(i);
        if (d != 0)
            r *= long_long_pow(primes[i], d);
    }
    return r;
};

double t_pitch::expVector::getRatioAsDouble() const {
    double r = 1.;
    int i;
    for (i = 0; i < BACH_PRIMES_JI_SIZE; i++) {
        long d = get(i);
        if (d != 0)
            r *= pow(primes[i], d);
    }
    return r;
};


bool t_pitch::expVector::allZeros() const {
    return *reinterpret_cast<const t_int64*>(data) == 0 && *reinterpret_cast<const t_int16*>(data + 8) == 0 && *(data + 10) == 0;
}

bool t_pitch::expVector::allZerosButOctaves() const {
    return *reinterpret_cast<const t_int64*>(data + 1) == 0 && *reinterpret_cast<const t_int16*>(data + 9) == 0;
}

bool t_pitch::expVector::allZerosButOctavesAndTwelfths() const {
    return *reinterpret_cast<const t_int64*>(data + 2) == 0 && *reinterpret_cast<const t_int8*>(data + 10) == 0;
}


// /////////////////////////////

double t_pitch::JIComponentToFreq() const {
    return C0freq * p_JIexpVector.getRatioAsDouble();
}

double t_pitch::JIComponentToMC() const {
    return f2mc(JIComponentToFreq());
}

t_rational t_pitch::ETComponentToMCratNoOctave() const {
    t_atom_short mcBase = whiteKey2MC_safe(p_whiteKeyET);
    t_rational mc = mcBase + p_alterET * 200;
    return mc;
}

t_rational t_pitch::ETComponentToMCratWithOctave() const {
    return ETComponentToMCratNoOctave() + getOctave() * 1200;
}

double t_pitch::ETComponentToMCdoubleNoOctave() const {
    t_atom_short mcBase = whiteKey2MC_safe(p_whiteKeyET);
    double mc = mcBase + p_alterET * 200;
    return mc;
}

double t_pitch::ETComponentToMCdoubleWithOctave() const {
    return ETComponentToMCdoubleNoOctave() + getOctave() * 1200;

}

double t_pitch::toMCdouble() const {
    if (isPureET())
        return ETComponentToMCdoubleWithOctave();
    else if (isPureJI())
        return JIComponentToMC();
    else
        return ETComponentToMCdoubleNoOctave() + JIComponentToMC();
}

t_rational t_pitch::toMCrat() const {
    if (isPureET()) {
        return ETComponentToMCratWithOctave();
    } else {
        t_rational etmc = ETComponentToMCratNoOctave();
        double jimc = JIComponentToMC();
        t_rational jimcR = approx_double_with_rat_fixed_den(jimc, 10000, 0, nullptr); // TODO: Rivedere approssimazione al denominatore?
        return etmc + jimcR;
    }
}


t_bool t_pitch::operator==(const t_pitch &b) const
{
    return p_whiteKeyET == b.p_whiteKeyET && p_alterET == b.p_alterET && p_JIexpVector == b.p_JIexpVector;
}

t_bool t_pitch::operator<(const t_pitch &b) const
{
    if (isPureJI())
        return p_JIexpVector < b.p_JIexpVector; // compares the ratios (see operator< of expVector)
    if (isPureET()) {
        if (getOctave() != b.getOctave())
            return getOctave() != b.getOctave();
        else if (p_whiteKeyET != b.p_whiteKeyET)
            return p_whiteKeyET < b.p_whiteKeyET;
        else
            return ETComponentToMCdoubleWithOctave() < b.ETComponentToMCdoubleWithOctave();
    }
    return toMCdouble() < b.toMCdouble();
}

t_bool t_pitch::operator>(const t_pitch &b) const
{
    if (isPureJI())
        return p_JIexpVector > b.p_JIexpVector; // compares the ratios (see operator> of expVector)
    if (isPureET()) {
        if (getOctave() != b.getOctave())
            return getOctave() != b.getOctave();
        else if (p_whiteKeyET != b.p_whiteKeyET)
            return p_whiteKeyET > b.p_whiteKeyET;
        else
            return ETComponentToMCdoubleWithOctave() > b.ETComponentToMCdoubleWithOctave();
    }
    return toMCdouble() > b.toMCdouble();
}

t_pitch t_pitch::operator-() const
{
    return C0 - *this;
}

t_pitch t_pitch::operator+(const t_pitch &b) const
{
    t_pitch sum = t_pitchMatrices::getSum(p_whiteKeyET, b.p_whiteKeyET);
    t_int8 oct = sum.getOctave();
    sum.p_alterET += p_alterET + b.p_alterET;
    sum.p_JIexpVector = p_JIexpVector + b.p_JIexpVector;
    sum.p_JIexpVector.addOctaves(oct);
    return sum;
}

t_pitch t_pitch::operator-(const t_pitch &b) const
{
    t_pitch diff = t_pitchMatrices::getDiff(p_whiteKeyET, b.p_whiteKeyET);
    t_int8 oct = diff.getOctave();
    diff.p_alterET += p_alterET - b.p_alterET;
    diff.p_JIexpVector = p_JIexpVector - b.p_JIexpVector;
    diff.p_JIexpVector.addOctaves(oct);
    return diff;
}

t_pitch t_pitch::operator*(t_atom_long b) const
{
    if (isPureET()) {
        t_stepsAndMC sat = toETStepsAndMC();
        sat.steps *= b;
        sat.mc *= b;
        t_pitch r = sat;
        return r;
    } else if (isPureJI()) {
        return t_pitch(p_JIexpVector * b);
    } else {
        // TODO: replace iteration with sum + octave correction
        t_pitch r = C0;
        if (b >= 0) {
            for (t_atom_long i = 0; i < b; i++) {
                r += *this;
            }
        } else {
            for (t_atom_long i = 0; i > b; i--) {
                r -= *this;
            }
        }
        return r;
    }
}

t_pitch t_pitch::operator*(const t_rational &b) const
{
    if (b.num() == 0)
        return C0;
    if (b.den() == 0)
        return NaP;
    return *this * b.num() / b.den();
}


t_pitch t_pitch::operator/(t_atom_long b) const
{
    if (isPureET()) {
        t_stepsAndMC sat = toETStepsAndMC();
        sat.steps = sat.steps / b; // or divdiv_floor(sat.steps, b);
        sat.mc /= b;
        return t_pitch(sat);
    } else if (isPureJI()) {
        return t_pitch(p_JIexpVector / b);
    } else {
        double mc = toMCdouble();
        return fromMC(mc / b);
    }
}

t_pitch t_pitch::operator/(const t_rational &b) const
{
    return *this * b.inv();
}

t_pitch t_pitch::operator%(const t_pitch &b) const
{
    if (isPureJI()) {
        t_rational r = getRatio();
        t_rational r2 = b.getRatio();

        while (rat_rat_cmp(r, r2) > 0) {
            r /= r2;
        }
        while (rat_rat_cmp(r, long2rat(1)) < 0) {
            r *= r2;
        }
        
        return t_pitch(r);
        
    } else {
        if (b.toMCdouble() == 0)
            return t_pitch::NaP;
        
        t_atom_long quotient = t_atom_long((*this).divdiv(b));
        t_pitch t = b * quotient;
        return *this - t;
    }
}

t_pitch t_pitch::operator%(const t_atom_long b) const
{
    if (b == 0)
        return t_pitch::NaP;
    
    t_pitch temp = (*this / b);
    return *this - b * temp;
}

// A few functions providing JI approximations. The ones with JIcomp only approximate the just intonation component.
void t_pitch::approxJI_JIcomp_up_to_maxden(t_atom_long max_den, char direction) // Approximate only the JI part of the pitch
{
    t_shortRational r = getRatio();
    double error = 0.;
    if (r.r_den > max_den) {
        r = approx_double_with_rat_up_to_maxden(rat2double(r), max_den, direction, &error);
    }
    set(p_whiteKeyET, p_alterET, r);
}

// direction = 0: any; 1 or -1 sets the directino of approximation
double t_pitch::approxJI_up_to_maxden(t_atom_long max_den, char direction) // Approximate a the whole pitch, return the error
{
    double mc = toMCdouble();
    double error = 0.;
    double r = mc2f(mc)/C0freq; // ratio
    t_rational ratio = approx_double_with_rat_up_to_maxden(r, max_den, direction, &error);
    setJI(ratio);
    return error;
}



// these two function provide a list of "best" approximations that can be proposed in the interface (e.g. contextual menu)
// they are based on continued fraction representations.
std::vector<t_rational> t_pitch::getJIconvergents_JIcomp(long howmany, double threshMC, bool includeSemiconvergents, const std::vector<int> &allowed_primes) {
    t_shortRational r = getRatio();
    std::vector<t_rational> conv = get_convergents(r, howmany, true, threshMC, true, includeSemiconvergents, allowed_primes);
    return conv;
}

std::vector<t_rational> t_pitch::getJIconvergents(long howmany, double threshMC, bool includeSemiconvergents, const std::vector<int> &allowed_primes) {
    double mc = toMCdouble();
    double error = 0.;
    double r = mc2f(mc)/C0freq; // ratio 
    std::vector<t_rational> conv = get_convergents(r, howmany, true, threshMC, true, includeSemiconvergents, allowed_primes);
    return conv;
}

t_rational t_pitch::getHEJICommasAsRational() const {
    std::vector<int8_t> commas = getHEJICommas();
    long s = commas.size();
    t_rational r = genrat(1, 1);
    for (long i = 0; i < s; i++) {
        r *= HEJIcommasRatios[i]; // TODO: check, test
    }
    return r;
}

std::string t_pitch::toString(t_bool include_octave, t_bool always_positive, t_bool addTrailingSpace) const
{
    std::string s;
    t_int8 octave;
    t_pitch p;
    if (p_alterET.den() == 0) {
        s = "NaP";
    } else {
        bool mirror;
        octave = getOctave();
        if (octave < 0 && !always_positive) {
            mirror = true;
            p = -*this;
        } else {
            mirror = false;
            p = *this;
        }
        t_int8 plof = p.getPlofJI();
        bool pureJI = p.isPureJI();
        bool pureET = p.isPureET();

        if (!pureJI || pureET) {
            // not pure JI or both pure JI and pureET (that is, it's a C with no alteration or deviation – except if we ask them to be written as JI)
            if (mirror)
                s = '-';
            s += degree2name[p.p_whiteKeyET];
            t_shortRational remainder = p.p_alterET;
            if (remainder > natural) { // sharps
                while (remainder >= eighthsharp) {
                    if (remainder >= dblsharp) {
                        s += 'x';
                        remainder -= dblsharp;
                    } else if (remainder >= sharp) {
                        s += '#';
                        remainder -= sharp;
                    } else if (remainder >= qrtrsharp) {
                        s += 'q';
                        remainder -= qrtrsharp;
                    } else if (remainder >= eighthsharp) {
                        s += '^';
                        remainder -= eighthsharp;
                    }
                }
            } else if (remainder < natural) { // flats
                while (remainder <= eighthflat) {
                    if (remainder <= flat) {
                        s += 'b';
                        remainder -= flat;
                    } else if (remainder <= qrtrflat) {
                        s += 'd';
                        remainder -= qrtrflat;
                    } else if (remainder <= eighthflat) {
                        s += 'v';
                        remainder -= eighthflat;
                    }
                }
            }
            if (include_octave) {
                if (mirror) {
                    if (plof % 7 != 0 || p_whiteKeyET != 0) {
                        s += std::to_string(-octave - 1);
                    } else {
                        s += std::to_string(-octave);
                    }
                } else {
                    s += std::to_string(octave);
                }
            }
            
            if (mirror)
                remainder = -remainder;
            
            if (remainder > natural)
                s += "+" + std::to_string(remainder.num()) + "/" + std::to_string(remainder.den()) + "t";
            else if (remainder < natural)
                s += std::to_string(remainder.num()) + "/" + std::to_string(remainder.den()) + "t";
        }
        
        if (!pureET) {
            if (mirror)
                s += '-';
            else if (!pureJI)
                s += '+';
            t_int8 sharps = p.getSharpsJI();
            if (plof >= 0) {
                s += (plof * 4 + 2) % 7 + 'A';
            } else {
                s += (-plof * 3 + 2) % 7 + 'A';
            }
            if (sharps > 1) {
                s += std::string(sharps / 2, 'x');
                sharps %= 2;
            }
            if (sharps == 1) {
                s += "#";
            } else if (sharps < 0) {
                s += std::string(-sharps, 'b');
            }
            std::vector<int8_t> commas = p.getHEJICommas(true);
            if (commas.size()) {
                s += "{";
                for (auto c: commas) {
                    s += std::to_string(c) + ":";
                }
                s.back() = '}';
            } else {
                s += "{}";
            }
            if (p.isPureJI()) {
                s += std::to_string(mirror ? -octave - 1 : octave);
            } else {
                s += "0";
            }
        }
    }

    if (addTrailingSpace)
        s += ' ';
    return s;
}


// TODO: @Andrea: questa funzione mancava ed era chiesta da un sacco di oggetti. Io intanto l'ho fatta così, ma verifica
long t_pitch::toTextBuf(char *buf, long bufSize, t_bool include_octave, t_bool always_positive, t_bool addTrailingSpace) const
{
    std::string str = toString(include_octave, always_positive, addTrailingSpace);
    snprintf_zero(buf, bufSize, "%s", str.c_str());
    return MIN(str.length(), bufSize-1);
}

#ifdef ___oldToTextBuf

long t_pitch::toTextBuf(char *buf, long bufSize, t_bool include_octave, t_bool always_positive, t_bool addTrailingSpace) const
{
    long count = 0;
    if (!buf || bufSize == 0)
        return -1;
    if (p_alterET.den() == 0) {
        if (addTrailingSpace)
            return snprintf_zero(buf, bufSize, "NaP ");
        else
            return snprintf_zero(buf, bufSize, "NaP");
    } else if (p_octave >= 0 || always_positive) {
        
        
        
        if (++count == bufSize) { *buf = 0; return count - 1; }
        *(buf++) = degree2name[p_degree];
        t_shortRational remainder = p_alterET;
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
        t_shortRational remainder = mirrored.p_alterET;
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

#endif // ___oldToTextBuf

long floor_div_by_7(long num)
{
    return num / 7 - (num % 7 < 0);
}

// TODOAA
// fromMC dovrebbe diventare costruttore?
// TODO: @Andrea: Why TODO DG? if it's fromMC it's clearly a purely ET pitch, isn't it?
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
    static double constexpr natural_steps[] = {0., 2., 4., 5., 7., 9., 11., 12.};
    long natural_approx_diatstep = -1, natural_approx_step = -1, i;
    t_rational natural_ratio, grid_ratio;
    const double PERFECT_MATCH_THRESHOLD = 0.0005;
    
    gridstep %= numsteps; // modulo the number of steps of the grid
    
    // now we have the step, we gotta find what it means with respect to the NATURAL notes.
    // where is the closest natural notes with respect to the grid?
    // e.g. i'm at gridstep 3 in a 24-TET; gotta normalize it at 12...
    gridstep_12norm = gridstep * 12. / numsteps; // ...so that now our 3 becomes 1.5
    
    
    // now we have to find the 12-degree natural approximation {0, 2, 4, 5, 7, 9, 11} that suits our gridstep_12norm

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
        t_pitch p1 = t_pitch(positive_mod(steps, 7), long2rat(0), floor_div_by_7(steps));
        t_rational mc1 = p1.ETComponentToMCratWithOctave();
        t_rational mc_orig = approx_double_with_rat_fixed_den(mc, 100, 0, NULL);
        accidental = (mc_orig - mc1)/200;
    }
    
    return t_pitch(positive_mod(steps, 7), accidental, floor_div_by_7(steps));
}
