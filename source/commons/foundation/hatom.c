/*
 *  hatom.c
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

#include "foundation/hatom.h"
#include "math/llll_math.h"
#include "bell/function.hpp"

extern t_class *llll_class;

t_bool hatom_is_number(const t_hatom *h)
{
    return hatom_type_is_number(hatom_gettype(h));
}

t_bool hatom_type_is_number(const t_int32 type)
{
    return type == H_LONG || type == H_RAT || type == H_DOUBLE || type == H_PITCH;
}

t_uint32 hatom_gettype(const t_hatom *h)
{
    return (h ? h->h_type : H_NULL);
}

t_atom_long hatom_getlong(const t_hatom *h)
{
    switch (hatom_gettype(h)) {
        case H_LONG:
            return h->h_w.w_long;
            break;
        case H_DOUBLE:
            return h->h_w.w_double;
            break;
        case H_RAT:
            if (h->h_w.w_rat.r_den != 0)
                return h->h_w.w_rat.r_num / h->h_w.w_rat.r_den;
            else
                return 0;
            break;
        case H_PITCH:
            return t_atom_long(h->h_w.w_pitch.toMC());
            break;
        default:
            return 0;
            break;
    }
}

double hatom_getdouble(const t_hatom *h)
{
    switch (hatom_gettype(h)) {
        case H_LONG:
            return h->h_w.w_long;
            break;
        case H_DOUBLE:
            return h->h_w.w_double;
            break;
        case H_RAT:
            return ((double) h->h_w.w_rat.r_num) / ((double) h->h_w.w_rat.r_den);
            break;
        case H_PITCH:
            return double(h->h_w.w_pitch.toMC());
            break;
        default:
            return 0;
            break;
    }
}

#define DOUBLE_TO_RATIONAL_DENOMINATOR (1000*27*7)

t_rational hatom_getrational(const t_hatom *h)
{
    t_rational r = {0,0};
    switch (hatom_gettype(h)) {
        case H_LONG:
            r.r_num = h->h_w.w_long;
            r.r_den = 1;
            return r;
            break;
        case H_DOUBLE: // TODO: can be greatly improved!!!!
            r.r_num = h->h_w.w_double * DOUBLE_TO_RATIONAL_DENOMINATOR;
            r.r_den = DOUBLE_TO_RATIONAL_DENOMINATOR;
            r.reduce();
            return r;
            break;
        case H_RAT:
            return h->h_w.w_rat;
            break;
        case H_PITCH:
            return t_rational(h->h_w.w_pitch.toMC());
            break;
        default:
            return r;
            break;
    }
    return r;
}


t_pitch hatom_getpitch(const t_hatom *h, long tonedivision, e_accidentals_preferences pref)
{
    switch (hatom_gettype(h)) {
        case H_LONG:
            return t_pitch::fromMC(h->h_w.w_long, tonedivision, pref);
            break;
        case H_DOUBLE:
            return t_pitch::fromMC(h->h_w.w_double, tonedivision, pref);
            break;
        case H_RAT: // TODO: can be improved!
        {
            double d = h->h_w.w_rat;
            return t_pitch::fromMC(d, tonedivision, pref);
        }
        case H_PITCH:
            return h->h_w.w_pitch;
            break;
        default:
            return t_pitch::C0;
            break;
    }
}

t_symbol *hatom_getsym(const t_hatom *h)
{
    if (hatom_gettype(h) == H_SYM)
        return h->h_w.w_sym;
    else 
        return NULL;
}

t_llll *hatom_getllll(const t_hatom *h)
{
    if (hatom_gettype(h) == H_LLLL)
        return h->h_w.w_llll;
    else 
        return NULL;
}

void *hatom_getobj(const t_hatom *h)
{
    if (hatom_gettype(h) == H_OBJ)
        return h->h_w.w_obj;
    else 
        return NULL;
}

t_function *hatom_getfunc(const t_hatom *h)
{
    if (hatom_gettype(h) == H_FUNCTION)
        return h->h_w.w_func;
    else
        return NULL;
}

void hatom_setlong(t_hatom *h, const t_atom_long l)
{
    h->h_type = H_LONG;
    h->h_w.w_long = l;
}

void hatom_setrational(t_hatom *h, const t_rational &r)
{
    hatom_setrational_from_elems(h, r.r_num, r.r_den);
}

void hatom_setrational_from_elems(t_hatom *h, t_atom_long num, t_atom_long den)
{
    h->h_type = H_RAT;
    
    if (den == 0 && num == 0) {
        h->h_w.w_rat.r_num = 0;
        h->h_w.w_rat.r_den = 0;
        return;
    }
    if (den == 0) {
        if (num > 0)
            h->h_w.w_rat.r_num = 1;
        else 
            h->h_w.w_rat.r_num = -1;
        h->h_w.w_rat.r_den = 0;
        return;
    }
    
    if (num == 0) {
        h->h_type = H_LONG;
        h->h_w.w_long = 0;
        return;
    }
    
    
    long_long_reduce(&num, &den);
    
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
    
    if (den == 1) {
        h->h_type = H_LONG;
        h->h_w.w_long = num;
        return;
    }
    
    h->h_w.w_rat.r_num = num;
    h->h_w.w_rat.r_den = den;
    
}

void hatom_setdouble(t_hatom *h, const double d)
{
    h->h_type = H_DOUBLE;
    h->h_w.w_double = d;
}

void hatom_setpitch(t_hatom *h, const t_pitch &p)
{
    h->h_type = H_PITCH;
    h->h_w.w_pitch = p;
}

void hatom_setpitch_from_elems(t_hatom *h, t_atom_short degree, t_shortRational &alter, t_atom_short octave)
{
    h->h_type = H_PITCH;
    h->h_w.w_pitch.set(degree, alter, octave);
}

void hatom_setsym(t_hatom *h, const t_symbol *s)
{
    h->h_type = H_SYM;
    h->h_w.w_sym = (t_symbol *) s;
}

void hatom_setllll(t_hatom *h, const t_llll *llll)
{
    h->h_type = H_LLLL;
    h->h_w.w_llll = (t_llll *) llll;
}

void hatom_setobj(t_hatom *h, const void *o)
{
    h->h_type = H_OBJ;
    h->h_w.w_obj = (t_object *) o;
}

void hatom_setfunc(t_hatom *h, t_function *fn)
{
    h->h_type = H_FUNCTION;
    fn->increase();
    h->h_w.w_func = fn;
}

void hatom_setatom(t_hatom *h, const t_atom *a)
{
    switch (a->a_type) {
        case A_LONG:
            h->h_type = H_LONG;
            h->h_w.w_long = a->a_w.w_long;
            break;
        case A_FLOAT:
            h->h_type = H_DOUBLE;
            h->h_w.w_double = a->a_w.w_float;
            break;
        case A_SYM:
            h->h_type = H_SYM;
            h->h_w.w_sym = a->a_w.w_sym;
            break;
        case A_OBJ:
            h->h_type = H_OBJ;
            h->h_w.w_obj = a->a_w.w_obj;
            break;
        case A_NOTHING:
            h->h_type = H_NOTHING;
            break;
    }
}

long hatom_eq(const t_hatom *a, const t_hatom *b)
{
    if (a->h_type != b->h_type)
        return 0;
    switch (a->h_type) {
        case H_LONG:
        case H_LLLL:
        case H_OBJ:
        case H_FUNCTION:
        case H_SYM:
            if (a->h_w.w_long != b->h_w.w_long)
                return 0;
            break;
        case H_DOUBLE:
            if (a->h_w.w_double != b->h_w.w_double)
                return 0;
            break;
        case H_RAT:
        case H_PITCH:
#ifdef C74_X64
            if (a->h_w.w_rat.r_den != b->h_w.w_rat.r_den || a->h_w.w_rat.r_num != b->h_w.w_rat.r_num)
                return 0;
#else
            if (a->h_w.w_whole != b->h_w.w_whole)
                return 0;
#endif
            break;
    }
    return 1;
}


t_bool hatom_istrue(const t_hatom *h)
{
    long type = hatom_gettype(h);
    if (!hatom_type_is_number(type))
        return true;
    if (hatom_getdouble(h) != 0.)
        return true;
    return false;
}
