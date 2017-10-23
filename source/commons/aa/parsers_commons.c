//
//  bach_parsers_commons.c
//  bach
//
//  Created by Andrea Agostini on 23/10/17.
//
//

#include "parsers_commons.h"

long parsesign(char **pos)
{
    t_atom_long sign = 1;
    switch (**pos) {
        case '-':
            sign = -1;
        case '+':
            ++*pos;
            break;
    }
    return sign;
}

t_rational parse_rational(char *pos)
{
    char *textend;
    long num = strtol(pos, &textend, 10);
    long den = strtol(textend + 1, NULL, 10);
    return t_rational(num, den);
}

t_pitch from_abs_and_sign(t_pitch p, long s)
{
    if (s == 1)
        return p;
    else
        return -p;
}

t_pitch parse_pitch_as_name_acc_int(char *pos)
{
    long sign = parsesign(&pos);
    long degree = t_pitch::text2degree(*pos);
    ++pos;
    t_shortRational alter = t_pitch::text2alter(&pos);
    long octave = strtol(pos, NULL, 10);
    return from_abs_and_sign(t_pitch(degree, alter, octave), sign);
}

t_pitch parse_pitch_as_name_int_acc(char *pos)
{
    long sign = parsesign(&pos);
    long degree = t_pitch::text2degree(*pos);
    char *acc;
    long octave = strtol(pos + 1, &acc, 10);
    t_shortRational alter = t_pitch::text2alter(&acc);
    return from_abs_and_sign(t_pitch(degree, alter, octave), sign);
}

t_pitch parse_pitch_as_name_acc_int_int_t(char *pos)
{
    long sign = parsesign(&pos);
    long degree = t_pitch::text2degree(*pos);
    char *next = pos + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
    long octave = strtol(next, &next, 10);
    alter += t_shortRational(strtol(next, NULL, 10), 1);
    return from_abs_and_sign(t_pitch(degree, alter, octave), sign);
}

t_pitch parse_pitch_as_name_acc_int_rat_t(char *pos)
{
    long sign = parsesign(&pos);
    long degree = t_pitch::text2degree(*pos);
    char *next = pos + 1;
    t_shortRational alter = t_pitch::text2alter(&next);
    long octave = strtol(next, &next, 10);
    alter += t_shortRational(strtol(next, &next, 10),  strtol(next + 1, NULL, 10));
    return from_abs_and_sign(t_pitch(degree, alter, octave), sign);
}



