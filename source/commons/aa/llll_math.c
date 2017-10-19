#include <math.h>
#include "hatom.h"
#include "llll_math.h"
#include "llll_comparisons.h"

#ifdef WIN_VERSION

double cbrt(double number)
{
	if (number > 0)
		return pow(number, 1./3.);
	else
		return -pow(-number, 1./3.);
}

double exp2(double number)
{
       return pow(2, number);
}

/*
double log2(double number)
{
       return log(number)/LOG_2;
}
*/

double acosh(double number)
{
       return log(number + sqrt(number*number-1));
}

double asinh(double number)
{
       return log(number + sqrt(number*number+1));
}

double atanh(double number)
{
       return 0.5*log((1+number)/(1-number));
}

/*
double round(double number)
{
       double floored = floor(number);
       if (number - floored <= 0.5)
               return floored;
       else
               return floored+1;
}
*/

double trunc(double number)
{
	return floor(number);
}

double trunc_at(double number, long position)
{
       return floor(pow(10., position)*number) / pow(10., position);
       // not at all the best algorithm, I suppose...
}

#endif


void hatom_fn_float(t_hatom *arg, t_hatom *res)
{
    hatom_setdouble(res, hatom_getdouble(arg));
}

void hatom_fn_int(t_hatom *arg, t_hatom *res)
{
    hatom_setlong(res, hatom_getlong(arg));
}

void hatom_fn_rat(t_hatom *arg, t_hatom *res)
{
    switch (hatom_gettype(arg)) {
        case H_LONG:
            hatom_setrational(res, long2rat(arg->h_w.w_long));
            break;
        case H_RAT:
            *res = *arg;
            break;
        case H_DOUBLE: {
            double orig = arg->h_w.w_double;
            double zeros = floor(9 - log10(orig));
            long den = pow(10, CLAMP(zeros, 0, 9));
            t_rational raw = genrat(arg->h_w.w_double * den, den);
            if (raw.r_num % 10000 > 9990)
                raw.r_num++;
            else if (raw.r_num > 1000 && raw.r_num % 10000 < 10)
                raw.r_num = (raw.r_num / 10000) * 10000;
            hatom_setrational(res, raw);
            break;
        }
        case H_PITCH:
            hatom_setrational(res, hatom_getrational(arg));
            break;
        default:
            hatom_setrational(res, long2rat(0));
            break;
    }
}

void hatom_fn_num(t_hatom *arg, t_hatom *res)
{
    hatom_setlong(res, hatom_getrational(arg).r_num);
}

void hatom_fn_den(t_hatom *arg, t_hatom *res)
{
    hatom_setlong(res, hatom_getrational(arg).r_den);
}

void hatom_fn_pitch(t_hatom *arg, t_hatom *res)
{
    switch(arg->h_type) {
        case H_LONG:
            hatom_setpitch(res, t_pitch::fromMC(arg->h_w.w_long));
            break;
        case H_RAT:
            hatom_setpitch(res, t_pitch::fromMC(arg->h_w.w_rat));
            break;
        case H_DOUBLE:
            hatom_setpitch(res, t_pitch::fromMC(arg->h_w.w_double));
            break;
        case H_PITCH:
            *res = *arg;
            break;
        default:
            hatom_setpitch(res, t_pitch(0, t_pitch::natural, 0));
            break;
    }
}

void hatom_fn_degree(t_hatom *a1, t_hatom *res)
{
    switch (a1->h_type) {
        case H_PITCH:
            hatom_setlong(res, a1->h_w.w_pitch.degree());
            break;
        case H_LONG:
        case H_RAT:
        case H_DOUBLE:
            hatom_setlong(res, t_pitch::fromMC(hatom_getdouble(a1)).degree());
            break;
        default:
            hatom_setlong(res, 0);
            break;
    }
}

void hatom_fn_octave(t_hatom *a1, t_hatom *res)
{
    switch (a1->h_type) {
        case H_PITCH:
            hatom_setlong(res, a1->h_w.w_pitch.octave());
            break;
        case H_LONG:
        case H_RAT:
        case H_DOUBLE:
            hatom_setlong(res, t_pitch::fromMC(hatom_getdouble(a1)).octave());
            break;
        default:
            hatom_setlong(res, 0);
            break;
    }
}

void hatom_fn_alter(t_hatom *a1, t_hatom *res)
{
    switch (a1->h_type) {
        case H_PITCH:
            hatom_setrational(res, a1->h_w.w_pitch.alter());
            break;
        case H_LONG:
        case H_RAT:
        case H_DOUBLE:
            hatom_setrational(res, t_pitch::fromMC(hatom_getdouble(a1)).alter());
            break;
        default:
            hatom_setlong(res, 0);
            break;
    }
}

void hatom_fn_makepitch(t_hatom *a1, t_hatom *a2, t_hatom *a3, t_hatom *res)
{
    long degree = hatom_getlong(a1);
    long octave = hatom_getlong(a3);
    if (degree < 0) {
        octave += (degree - 6) / 7;
        degree = (degree % 7) + 7;
    } else if (degree > 6) {
        octave += degree / 7;
        degree %= 7;
    }
    hatom_setpitch(res, t_pitch(degree, hatom_getrational(a2), octave));
}


// makepitch from steps and cents
void hatom_fn_makepitchsc(t_hatom *a1, t_hatom *a2, t_hatom *res)
{
    t_pitch::t_stepsAndMC smc;
    smc.steps = hatom_getlong(a1);
    smc.mc = hatom_getrational(a2);
    hatom_setpitch(res, t_pitch(smc));
}

void hatom_fn_cents(t_hatom *a1, t_hatom *res)
{
    if (hatom_gettype(a1) == H_PITCH) {
        hatom_setlong(res, a1->h_w.w_pitch.toMC());
    } else {
        *res = *a1;
    }
}

void hatom_fn_random(t_hatom *a1, t_hatom *a2, t_hatom *res)
{
    double d1 = hatom_getdouble(a1);
    double d2 = hatom_getdouble(a2);
    hatom_setlong(res, rand() / (double) RAND_MAX * (d2 - d1 + 1) + d1);
}

void hatom_fn_pow(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    if (h1_type == H_DOUBLE ||
        h2_type != H_LONG)
        hatom_setdouble(res, pow(hatom_getdouble(h1), hatom_getdouble(h2)));
    else if (h1_type == H_RAT || h1_type == H_PITCH) {
        t_rational rr, rop;
        long i;
        t_atom_long exp, absexp;
        exp = hatom_getlong(h2);
        if (exp == 0) {
            hatom_setlong(res, 1);
        } else {
            rop = rr = hatom_getrational(h1);
            absexp = alabs(exp);
            for (i = 1; i < absexp; i++) {
                rr.r_num *= rop.r_num;
                rr.r_den *= rop.r_den;
            }
            if (exp < 0) {
                long swap = rr.r_num;
                rr.r_num = rr.r_den;
                rr.r_den = swap;
            }
            hatom_setrational(res, rr);
        }
    } else { // TODO: optimize the case for two longs
        long i, op;
        t_atom_long exp, r, absexp;
        exp = hatom_getlong(h2);
        if (exp == 0) {
            hatom_setlong(res, 1);
        } else {
            absexp = alabs(exp);
            r = op = h1->h_w.w_long;
            for (i = 1; i < absexp; i++)
                r *= op;
            if (exp > 0)
                hatom_setlong(res, r);
            else
                hatom_setrational_from_elems(res, 1, r);
        }
    }
}

void hatom_fn_abs(t_hatom *arg, t_hatom *res)
{
    switch (arg->h_type) {
        case H_LONG:
            hatom_setlong(res, arg->h_w.w_long);
            if (res->h_w.w_long < 0)
                res->h_w.w_long *= -1;
            break;
        case H_RAT:
            hatom_setrational(res, arg->h_w.w_rat);
            if (res->h_w.w_rat.r_num < 0)
                res->h_w.w_rat.r_num *= -1;
            break;
        case H_PITCH:
            hatom_setpitch(res, arg->h_w.w_pitch.abs());
            break;
        default:
            hatom_setdouble(res, fabs(arg->h_w.w_double));
            break;
    }
}

void hatom_fn_sgn(t_hatom *arg, t_hatom *res)
{
    double d;
    switch (arg->h_type) {
        case H_LONG:
            if (arg->h_w.w_long > 0)
                hatom_setlong(res, 1);
            else if (arg->h_w.w_long == 0)
                hatom_setlong(res, 0);
            else
                hatom_setlong(res, -1);
            break;
        case H_RAT:
            if (arg->h_w.w_rat.r_num > 0)
                hatom_setlong(res, 1);
            else if (arg->h_w.w_rat.r_num == 0)
                hatom_setlong(res, 0);
            else
                hatom_setlong(res, -1);
            break;
        case H_PITCH:
            hatom_setlong(res, arg->h_w.w_pitch.sgn());
            break;
        default:
            d = hatom_getdouble(arg);
            if (d > 0)
                hatom_setlong(res, 1);
            else if (d == 0)
                hatom_setlong(res, 0);
            else
                hatom_setlong(res, -1);
            break;
    }
}

void hatom_fn_mod(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    
    else if (h1_type == H_PITCH && h2_type == H_PITCH) { // pp -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch.mod(h2->h_w.w_pitch));
        
    } else if (h1_type == H_PITCH && h2_type == H_LONG) { // pl -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch.mod(h2->h_w.w_long));
        
    } else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE) { // dl dr dd dp ld rd pd -> double
        double d2 = hatom_getdouble(h2);
        if (d2 == 0)
            hatom_setdouble(res, 0);
        else {
            double dres = fmod(hatom_getdouble(h1), d2);
            if (dres < 0)
                dres += d2;
            hatom_setdouble(res, dres);
        }
        
    } else if (h1_type == H_LONG && h2_type == H_LONG) { // ll -> long
        long l2 = hatom_getlong(h2);
        if (l2 == 0)
            hatom_setlong(res, 0);
        else {
            long lres = hatom_getlong(h1) % l2;
            if (lres < 0)
                lres += l2;
            hatom_setlong(res, lres);
        }
        
    } else { // lr lp rl rr rp pr -> rat
        t_rational r2 = hatom_getrational(h2);
        if (r2.r_num == 0)
            hatom_setrational_from_elems(res, 0, 1);
        else
            hatom_setrational(res, rat_rat_mod(hatom_getrational(h1), hatom_getrational(h2), 1));
    }
}

void hatom_fn_remainder(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    
    else if (!(hatom_type_is_number(h2_type))) {
        *res = *h2;
        
    } else if (h1_type == H_PITCH && h2_type == H_PITCH) { // pp -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch % h2->h_w.w_pitch);
        
    } else if (h1_type == H_PITCH && h2_type == H_LONG) { // pl -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch % h2->h_w.w_long);
        
    } else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE) { // dl dr dd dp ld rd pd -> double
        double d2 = hatom_getdouble(h2);
        if (d2 == 0)
            hatom_setdouble(res, 0);
        else
            hatom_setdouble(res, fmod(hatom_getdouble(h1), d2));
        
    } else if (h1_type == H_LONG && h2_type == H_LONG) { // ll -> long
        t_atom_long l2 = hatom_getlong(h2);
        if (l2 == 0)
            hatom_setlong(res, 0);
        else
            hatom_setlong(res, hatom_getlong(h1) % l2);
        
    } else { // lr lp rl rr rp pr -> rat
        t_rational r2 = hatom_getrational(h2);
        if (r2.r_num == 0)
            hatom_setrational_from_elems(res, 0, 1);
        else
            hatom_setrational(res, rat_rat_mod(hatom_getrational(h1), hatom_getrational(h2), 0));
    }
}

void hatom_fn_jn(t_hatom *a1, t_hatom *a2, t_hatom *res)
{
    long order = hatom_getlong(a1);
    double x = hatom_getdouble(a2);
    hatom_setdouble(res, bach_jn(order, x));
}






void hatom_op_uminus(t_hatom *h1, t_hatom *res)
{
    switch (hatom_gettype(h1)) {
        case H_DOUBLE:
            hatom_setdouble(res, -(h1->h_w.w_double));
            break;
        case H_RAT:
            t_rational r;
            r = hatom_getrational(h1);
            hatom_setrational_from_elems(res, -r.r_num, r.r_den);
            break;
        case H_LONG:
            hatom_setlong(res, -(h1->h_w.w_long));
            break;
        case H_PITCH:
            hatom_setpitch(res, -(h1->h_w.w_pitch));
            break;
        default:
            *res = *h1;
    }
}

void hatom_op_plus(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    
    else if (h1_type == H_PITCH && h2_type == H_PITCH) { // pp -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch + h2->h_w.w_pitch);
        
    } else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE) { // dl dr dd dp ld rd pd -> double
        hatom_setdouble(res, hatom_getdouble(h1) + hatom_getdouble(h2));
        
    } else if (h1_type == H_LONG && h2_type == H_LONG) { // ll -> long
        hatom_setlong(res, h1->h_w.w_long + h2->h_w.w_long);
    
    } else if (h1_type == H_LONG && (h2_type == H_RAT || h2_type == H_PITCH)) { // lr lp -> rat
            hatom_setrational(res, h1->h_w.w_long + hatom_getrational(h2));
        
    } else if (h1_type == H_RAT && h2_type == H_LONG) { // rl pl -> rat
            hatom_setrational(res, hatom_getrational(h1) + h2->h_w.w_long);
        
    } else { // rl rr rp pr lr -> rational
        hatom_setrational(res, hatom_getrational(h1) + hatom_getrational(h2));
    }
}

void hatom_op_minus(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    
    else if (h1_type == H_PITCH && h2_type == H_PITCH) { // pp -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch - h2->h_w.w_pitch);
        
    } else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE) { // dl dr dd dp ld rd pd -> double
        hatom_setdouble(res, hatom_getdouble(h1) - hatom_getdouble(h2));
        
    } else if (h1_type == H_LONG && h2_type == H_LONG) { // ll -> long
        hatom_setlong(res, h1->h_w.w_long - h2->h_w.w_long);
        
    } else if (h1_type == H_LONG && (h2_type == H_RAT || h2_type == H_PITCH)) { // lr lp -> rat
        hatom_setrational(res, h1->h_w.w_long - hatom_getrational(h2));
        
    } else if (h1_type == H_RAT && h2_type == H_LONG) { // rl pl -> rat
        hatom_setrational(res, hatom_getrational(h1) - h2->h_w.w_long);
        
    } else { // rl rr rp pr lr -> rational
        hatom_setrational(res, hatom_getrational(h1) - hatom_getrational(h2));
    }
}

void hatom_op_times(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    
    else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE) // dl dr dd dp ld rd pd -> double
        hatom_setdouble(res, hatom_getdouble(h1) * hatom_getdouble(h2));

    else if (h1_type == H_LONG && h2_type == H_LONG) // ll -> long
        hatom_setlong(res, h1->h_w.w_long * h2->h_w.w_long);
    
    else if (h1_type == H_LONG && h2_type == H_PITCH) // lp -> pitch
        hatom_setpitch(res, h1->h_w.w_long * h2->h_w.w_pitch);
    
    else if (h1_type == H_PITCH && h2_type == H_LONG) // pl -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch * h2->h_w.w_long);
    
    else if (h1_type == H_PITCH && h2_type == H_RAT) // pr -> pitch
        hatom_setpitch(res, h1->h_w.w_pitch * h2->h_w.w_rat);
    
    else if (h1_type == H_RAT && h2_type == H_PITCH) // rp -> pitch
        hatom_setpitch(res, h1->h_w.w_rat * h2->h_w.w_pitch);

    else if (h1_type == H_LONG && h2_type == H_RAT) // lr -> rat
        hatom_setrational(res, h1->h_w.w_long * h2->h_w.w_rat);
    
    else if (h1_type == H_RAT && h2_type == H_LONG) // rl -> rat
        hatom_setrational(res, h1->h_w.w_rat * h2->h_w.w_long);
    
    else // rr pp -> rat
        hatom_setrational(res, hatom_getrational(h1) * hatom_getrational(h2));

}

void hatom_op_divdiv(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    
    else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE) { // dl dr dd dp ld rd pd -> p
        hatom_setdouble(res, hatom_getdouble(h1) / hatom_getdouble(h2));
        
    } else if (h1_type == H_PITCH && h2_type == H_LONG) { // pl -> p
        hatom_setpitch(res, h1->h_w.w_pitch / h2->h_w.w_long);
        
    } else if (h1_type == H_PITCH && h2_type == H_RAT) { // pr -> p
        hatom_setpitch(res, h1->h_w.w_pitch / h2->h_w.w_rat);
    
    } else if (h1_type == H_LONG && h2_type == H_LONG) { // ll -> r
        hatom_setlong(res, h1->h_w.w_long / h2->h_w.w_long);
        
    } else if (h1_type == H_LONG && (h2_type == H_RAT || h2_type == H_PITCH)) { // lr lp -> r
        hatom_setrational(res, h1->h_w.w_long / hatom_getrational(h2));
        
    } else if ((h1_type == H_RAT || h1_type == H_PITCH) && h2_type == H_LONG) { // rl pl -> r
        hatom_setrational(res, hatom_getrational(h1) / h2->h_w.w_long);
        
    } else { // rr rp
        hatom_setrational(res, hatom_getrational(h1) / hatom_getrational(h2));
    }
    
}

void hatom_op_div(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    
    else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE) { // dl dr dd dp ld rd pd -> p
        hatom_setdouble(res, hatom_getdouble(h1) / hatom_getdouble(h2));
 
    } else if (h1_type == H_PITCH && h2_type == H_LONG) { // pl -> p
        hatom_setpitch(res, h1->h_w.w_pitch / h2->h_w.w_long);
        
    } else if (h1_type == H_PITCH && h2_type == H_RAT) { // pr -> p
        hatom_setpitch(res, h1->h_w.w_pitch / h2->h_w.w_rat);
        
    } else if (h1_type == H_LONG && h2_type == H_LONG) { // ll -> r
        hatom_setrational(res, t_rational(h1->h_w.w_long, h2->h_w.w_long));
    
    } else if (h1_type == H_LONG && (h2_type == H_RAT || h2_type == H_PITCH)) { // lr lp -> r
        hatom_setrational(res, h1->h_w.w_long / hatom_getrational(h2));

    } else if ((h1_type == H_RAT || h1_type == H_PITCH) && h2_type == H_LONG) { // rl pl -> r
        hatom_setrational(res, hatom_getrational(h1) / h2->h_w.w_long);

    } else { // rr rp
        hatom_setrational(res, hatom_getrational(h1) / hatom_getrational(h2));
    }
    
}

void hatom_op_pow(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    t_uint32 h1_type = hatom_gettype(h1);
    t_uint32 h2_type = hatom_gettype(h2);
    
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    
    else if (h1_type == H_LONG && h2_type == H_LONG) { // ll -> l
        hatom_setlong(res, ipow(h1->h_w.w_long, h2->h_w.w_long));
        
    } else if ((h1_type == H_RAT || h1_type == H_PITCH) && h2_type == H_LONG) {
        hatom_setrational(res, rat_long_pow(hatom_getrational(h1), h2->h_w.w_long));
    
    } else
        hatom_setdouble(res, pow(hatom_getdouble(h1), hatom_getdouble(h2)));
}

void hatom_op_logand(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL) {
        if ((h2_type == H_DOUBLE && hatom_getdouble(h2) == 0) ||
            ((h2_type == H_PITCH || h2_type == H_RAT) && (hatom_getrational(h2).r_num == 0)))
            hatom_setlong(res, 0);
        else if (hatom_type_is_number(h2_type))
            res->h_type = H_NULL;
        else
            *res = *h2;
    } else if (h2_type == H_NULL) {
        if ((h1_type == H_DOUBLE && hatom_getdouble(h1) == 0) ||
            ((h1_type == H_LONG || h1_type == H_RAT) && (hatom_getrational(h1).r_num == 0)))
            hatom_setlong(res, 0);
        else if (hatom_type_is_number(h1_type))
            res->h_type = H_NULL;
        else
            *res = *h1;
    } else if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE)
        hatom_setlong(res, hatom_getdouble(h1) && hatom_getdouble(h2));
    else
        hatom_setlong(res, hatom_getrational(h1).r_num && hatom_getrational(h2).r_num);
}

void hatom_op_logor(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL) {
        if ((h2_type == H_DOUBLE && hatom_getdouble(h2) != 0) ||
            ((h2_type == H_LONG || h2_type == H_RAT) && (hatom_getrational(h2).r_num != 0)))
            hatom_setlong(res, 1);
        else if (hatom_type_is_number(h2_type))
            res->h_type = H_NULL;
        else
            *res = *h2;
    } else if (h2_type == H_NULL) {
        if ((h1_type == H_DOUBLE && hatom_getdouble(h1) != 0) ||
            ((h1_type == H_LONG || h1_type == H_RAT) && (hatom_getrational(h1).r_num != 0)))
            hatom_setlong(res, 1);
        else if (hatom_type_is_number(h1_type))
            res->h_type = H_NULL;
        else
            *res = *h1;
    } else if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE)
        hatom_setlong(res, hatom_getdouble(h1) || hatom_getdouble(h2));
    else
        hatom_setlong(res, hatom_getrational(h1).r_num || hatom_getrational(h2).r_num);
}

void hatom_op_logxor(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else if (h1_type == H_DOUBLE || h2_type == H_DOUBLE)
        hatom_setlong(res, (hatom_getdouble(h1) != 0) ^ (hatom_getdouble(h2) != 0));
    else
        hatom_setlong(res, (hatom_getrational(h1).r_num != 0) ^ (hatom_getrational(h2).r_num != 0));
}

void hatom_op_lognot(t_hatom *h1, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (h1_type == H_DOUBLE)
        hatom_setlong(res, hatom_getdouble(h1) == 0);
    else
        hatom_setlong(res, hatom_getrational(h1).r_num == 0);
}

void hatom_op_bitand(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else hatom_setlong(res, hatom_getlong(h1) & hatom_getlong(h2));
}

void hatom_op_bitor(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else hatom_setlong(res, hatom_getlong(h1) | hatom_getlong(h2));
}

void hatom_op_bitxor(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else hatom_setlong(res, hatom_getlong(h1) ^ hatom_getlong(h2));
}

void hatom_op_bitnot(t_hatom *h1, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else hatom_setlong(res, ~hatom_getlong(h1));
}

void hatom_op_lshift(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else hatom_setlong(res, hatom_getlong(h1) << hatom_getlong(h2));
}

void hatom_op_rshift(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (!(hatom_type_is_number(h1_type)))
        *res = *h1;
    else if (!(hatom_type_is_number(h2_type)))
        *res = *h2;
    else hatom_setlong(res, hatom_getlong(h1) >> hatom_getlong(h2));
}

void hatom_op_eq(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, llll_eq_hatom_ignoretype(h1, h2));
}

void hatom_op_eqmatch(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, llll_eq_hatom_matchtype(h1, h2));
}

void hatom_op_neq(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, !llll_eq_hatom_ignoretype(h1, h2));
}

void hatom_op_neqmatch(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, !llll_eq_hatom_matchtype(h1, h2));
}

void hatom_op_gt(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, llll_gt_hatom(h1, h2));
}

void hatom_op_ge(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, llll_geq_hatom(h1, h2));
}

void hatom_op_lt(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, llll_lt_hatom(h1, h2));
}

void hatom_op_le(t_hatom *h1, t_hatom *h2, t_hatom *res)
{
    long h1_type = hatom_gettype(h1);
    long h2_type = hatom_gettype(h2);
    if (h1_type == H_NULL || h2_type == H_NULL)
        res->h_type = H_NULL;
    else
        hatom_setlong(res, llll_leq_hatom(h1, h2));
}