//
//  parsers_commons.h
//  bach
//
//  Created by Andrea Agostini on 23/10/17.
//
//

#ifndef bach_parsers_commons_h
#define bach_parsers_commons_h

#include <llll_commons.h>

t_rational parse_rational(char *pos);
t_pitch parse_pitch_as_name_acc_int(char *pos);
t_pitch parse_pitch_as_name_int_acc(char *pos);
t_pitch parse_pitch_as_name_acc_int_int_t(char *pos);
t_pitch parse_pitch_as_name_acc_int_rat_t(char *pos);


#endif /* bach_parsers_commons_h */
