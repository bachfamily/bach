/*
 *  roll_files.h
 *  bach-fw
 *
 *  Created by andrea agostini on 10/6/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _ROLL_FILES_H_
#define _ROLL_FILES_H_

#include "roll.h"
#include "notation_files.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

void roll_read_generic(t_roll *x, t_symbol *s, long argc, t_atom *argv);


void roll_importmidi(t_roll *x, t_symbol *s, long argc, t_atom *argv);
void roll_exportmidi(t_roll *x, t_symbol *s, long argc, t_atom *argv);
void roll_read(t_roll *x, t_symbol *s, long argc, t_atom *argv);
void roll_read_singlesymbol(t_roll *x, t_symbol *s, long argc, t_atom *argv);
void roll_write(t_roll *x, t_symbol *s, long argc, t_atom *argv);
void roll_writetxt(t_roll *x, t_symbol *s, long argc, t_atom *argv);
void roll_exportom(t_roll *x, t_symbol *s, long argc, t_atom *argv);
void roll_exportpwgl(t_roll *x, t_symbol *s, long argc, t_atom *argv);

void roll_readmidi(t_roll *x, t_symbol *s, read_fn fn);
void roll_writemidi(t_roll *x, t_symbol *s, long format);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _ROLL_FILES_H_