/*
 *  roll_files.h
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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


#ifndef _ROLL_FILES_H_
#define _ROLL_FILES_H_

#include "roll.h"
#include "notation/notation_files.h"

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
void roll_exportimage(t_roll *x, t_symbol *s, long argc, t_atom *argv);

void roll_readmidi(t_roll *x, t_symbol *s, read_fn fn);
void roll_writemidi(t_roll *x, t_symbol *s, long format);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _ROLL_FILES_H_
