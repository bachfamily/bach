/*
 *  score_files.h
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
void score_exportimage(t_score *x, t_symbol *s, long argc, t_atom *argv);

void score_exportom(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_exportpwgl(t_score *x, t_symbol *s, long argc, t_atom *argv);

void score_writexml(t_score *x, t_symbol *s);

void score_exportmidi(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_exportlilypond(t_score *x, t_symbol *s, long argc, t_atom *argv);
void score_exportlilypond_pdf(t_score *x, t_symbol *s, long argc, t_atom *argv);

t_llll *score_readxmlbuffer(t_score *x,
                            char* buffer,
                            long getuidparenthesizedquartertones,
                            long lyricsslot,
                            long noteheadslot,
                            long articulationsslot,
                            long dynamicsslot,
                            long directionsslot);

const char *xml_mxl_find_rootfile(char *buffer);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _SCORE_FILES_H_
