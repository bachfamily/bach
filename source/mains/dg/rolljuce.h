/*
 *  rolljuce.h
 *
 *  Header files of shared functions for JUCE binding
 *
 */

#ifndef _ROLLJUCE_H_
#define _ROLLJUCE H_

#include "notation.h"
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

void roll_paint_ext(t_roll *x, t_object *view, t_jgraphics *g, t_rect rect);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif //_ROLLJUCE_H_
