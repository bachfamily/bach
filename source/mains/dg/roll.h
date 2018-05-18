/*
 *  roll.h
 *  bach-fw
 *
 *  Created by Daniele ghisi on 10/6/11.
 *  Copyright 2011 Daniele Ghisi and Andrea Agostini. All rights reserved.
 *
 */

#ifndef _ROLL_H_
#define _ROLL_H_

#include "notation.h"
#include "roll_files.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

typedef struct _roll // [bach.roll] structure
{
	t_notation_obj r_ob; // root: notation object (all the common attributes for roll and score) 
	
	t_rollvoice	*firstvoice;
	t_rollvoice	*lastvoice;
	

	// utilities
	char		must_append_chords;
	char		must_preselect_appended_chords;
	double		must_apply_delta_onset;
	char		pasting_chords;
	double		non_inspector_ms_screen_start;
	
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
t_llll* get_roll_values_as_llll(t_roll *x, e_data_considering_types for_what, e_header_elems dump_what, char also_lock_general_mutex, char explicitly_get_also_default_stuff);

char merge(t_roll *x, double threshold_ms, double threshold_cents, char gathering_policy_ms, char gathering_policy_cents, char only_selected, char markers_also);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif //_ROLL_H_
