/*
 *  score_files.h
 *  bach-fw
 *
 *  Created by andrea agostini on 10/6/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _SCORE_FILES_H_
#define _SCORE_FILES_H_

#include "score_api.h"
#include "notation_files.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

void score_read(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_write(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_writetxt(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_exportxml(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_read_singlesymbol(t_score *x, t_symbol *s, long argc, t_atom *argv);

void score_exportom(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_exportpwgl(t_score *x, t_symbol *s, long argc, t_atom *argv);

void score_writexml(t_score *x, t_symbol *s);

void score_exportmidi(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_exportlilypond(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_exportlilypond_pdf(t_score *x, t_symbol *s, long argc, t_atom *argv);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _SCORE_FILES_H_