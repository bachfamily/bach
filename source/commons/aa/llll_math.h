// some math functions and defines not supported by Visual Studio

#ifndef _LLLL_MATH_H_
#define _LLLL_MATH_H_

#include "bach.h"
#include "hatom.h"

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



void hatom_fn_random(t_hatom *a1, t_hatom *a2, t_hatom *res);
void hatom_fn_pow(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_fn_abs(t_hatom *arg, t_hatom *res);
void hatom_fn_sgn(t_hatom *arg, t_hatom *res);
void hatom_fn_mod(t_hatom *a1, t_hatom *a2, t_hatom *res);
void hatom_fn_remainder(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_fn_jn(t_hatom *a1, t_hatom *a2, t_hatom *res);




void hatom_op_uminus(t_hatom *h1, t_hatom *res);
void hatom_op_plus(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_minus(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_times(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_divdiv(t_hatom *h1, t_hatom *h2, t_hatom *res);
void hatom_op_div(t_hatom *h1, t_hatom *h2, t_hatom *res);
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


#endif // _LLLL_MATH_H_