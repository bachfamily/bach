/*
 *  roll.h
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

#ifndef _ROLL_H_
#define _ROLL_H_

#include "notation/notation.h"
#include "roll_files.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

typedef struct _roll // [bach.roll] structure
{
    t_notation_obj r_ob; // root: notation object (all the common attributes for roll and score) 
    
    t_rollvoice    *firstvoice;
    t_rollvoice    *lastvoice;
    

    // utilities
    char        must_append_chords;
    char        must_preselect_appended_chords;
    double        must_apply_delta_onset;
    char        pasting_chords;
    double        non_inspector_ms_screen_start;
    
    long m_in;   // space for the inlet number used by all the proxies
    void *m_proxy1;
    void *m_proxy2;
    void *m_proxy3;
    void *m_proxy4;
    void *m_proxy5;
} t_roll;

void set_roll_from_llll_from_read(t_roll *x, t_llll* inputlist);
void set_roll_from_llll(t_roll *x, t_llll* inputlist, char also_lock_general_mutex);
t_llll* get_roll_values_as_llll_for_pwgl(t_roll *x);
t_llll* get_roll_values_as_llll(t_roll *x, e_data_considering_types for_what, e_header_elems dump_what, char also_lock_general_mutex, char explicitly_get_also_default_stuff, t_symbol *router = NULL, bool selection_only = false);
t_llll *get_roll_values_as_llll_for_undo(t_roll *x, e_header_elems dump_what, char also_lock_general_mutex);

char merge(t_roll *x, double threshold_ms, double threshold_cents, char gathering_policy_ms, char gathering_policy_cents, char only_selected, char markers_also);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif //_ROLL_H_
