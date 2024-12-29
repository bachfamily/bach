/*
 *  llll_math.h
 *
 * Copyright (C) 2010-2025 Andrea Agostini and Daniele Ghisi
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

// some math functions and defines not supported by Visual Studio

#ifndef _LLLL_MATH_H_
#define _LLLL_MATH_H_

#include "foundation/bach.h"
#include "foundation/hatom.h"

#ifdef BACH_JUCE
#include "bach_jucewrapper.h"
#endif

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

#ifdef WIN_VERSION
#define LOG_2 0.693147180559945309417232121458176568 // ln(2)
#define M_LN2 LOG_2
#define bach_jn _jn
#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x))

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif
	
// "cubic root", < 0 if number < 0
double cbrt(double number);

// 2^n
double exp2(double number);

double log2(double number);
double acosh(double number);
double asinh(double number);
double atanh(double number);
double round(double number);
double trunc(double number);
double trunc_at(double number, long position);
double fold(double a, double b);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // WIN_VERSION

#ifdef MAC_VERSION
#define bach_jn jn
#endif // MAC_VERSION


// (almost) private
void hatom_fn_float(t_hatom *arg, t_hatom *res);
void hatom_fn_int(t_hatom *arg, t_hatom *res);
void hatom_fn_rat(t_hatom *arg, t_hatom *res);
void hatom_fn_num(t_hatom *arg, t_hatom *res);
void hatom_fn_den(t_hatom *arg, t_hatom *res);
void hatom_fn_pitch(t_hatom *arg, t_hatom *res);
void hatom_fn_cents(t_hatom *a1, t_hatom *res);
void hatom_fn_degree(t_hatom *a1, t_hatom *res);
void hatom_fn_octave(t_hatom *a1, t_hatom *res);
void hatom_fn_alter(t_hatom *a1, t_hatom *res);
void hatom_fn_makepitch(t_hatom *a1, t_hatom *a2, t_hatom *a3, t_hatom *res);
void hatom_fn_makepitchsc(t_hatom *a1, t_hatom *a2, t_hatom *res);
void hatom_fn_approx(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_fn_enharm(t_hatom *h1, t_hatom *h2, t_hatom *res);

void hatom_fn_etwhitekey(t_hatom *arg, t_hatom *res);
void hatom_fn_jiwhitekey(t_hatom *arg, t_hatom *res);
void hatom_fn_et(t_hatom *arg, t_hatom *res);
void hatom_fn_ji(t_hatom *arg, t_hatom *res);
void hatom_fn_jiratio(t_hatom *arg, t_hatom *res);
void hatom_fn_jiplof(t_hatom *arg, t_hatom *res);
void hatom_fn_etplof(t_hatom *arg, t_hatom *res);
void hatom_fn_jisharps(t_hatom *arg, t_hatom *res);
void hatom_fn_etsharps(t_hatom *arg, t_hatom *res);
void hatom_fn_etalter(t_hatom *arg, t_hatom *res);

void hatom_fn_makepitch_ext(t_hatom *whitekeyET,    // normally integer
                    t_hatom *alterET,       // normally rational
                    t_hatom *octave,        // normally integer
                    t_hatom *whitekeyJI,    // normally integer
                    t_hatom *sharpsJI,      // normally integer
                    t_hatom *plofJI,        // normally integer
                    t_hatom *commas,        // normally flat llll of integers passed as a H_OBJ
                    t_hatom *ratio,         // normally rational
                    t_hatom *monzo,         // normally flat llll of integers passed as a H_OBJ
                    t_hatom *res
                            );


void hatom_fn_random(t_hatom *a1, t_hatom *a2, t_hatom *res);
void hatom_fn_pow(t_hatom *h1, t_hatom *h2, t_hatom *res); // deprecated: use hatom_op_pow instead
void hatom_fn_abs(t_hatom *arg, t_hatom *res);
void hatom_fn_sgn(t_hatom *arg, t_hatom *res);


void hatom_fn_mod(t_hatom *a1, t_hatom *a2, t_hatom *res);
void hatom_fn_remainder(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_fn_jn(t_hatom *a1, t_hatom *a2, t_hatom *res);
void hatom_fn_min(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_fn_max(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_fn_fold(t_hatom *h1, t_hatom *h2, t_hatom *res);


void hatom_op_plus(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_plus_with_symbols(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_minus(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_times(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_times_with_symbols(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_div(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_divdiv(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_uminus(t_hatom *h1, t_hatom *res);
void hatom_op_pow(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_logand(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_logor(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_logxor(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_lognot(t_hatom *h1, t_hatom *res);
void hatom_op_bitand(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_bitor(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_bitxor(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_bitnot(t_hatom *h1, t_hatom *res);
void hatom_op_lshift(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_rshift(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_eq(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_eqmatch(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_neq(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_neqmatch(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_gt(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_ge(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_lt(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_le(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_t(t_hatom *h1, t_hatom *res);
void hatom_op_r(t_hatom *h1, t_hatom *res);

t_llll *getHEJICommas(const t_pitch &p);
t_llll *getMonzo(const t_pitch &p);

#endif // _LLLL_MATH_H_
