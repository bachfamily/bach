/*
 *  notation_files.h
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


#ifndef _NOTATION_FILES_H_
#define _NOTATION_FILES_H_

#include "notation/notation.h" // includes llll_files.h

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

// sorted in priority order in a midi file
// (that is, if a noteon a keysig have the same onset, the keysig will happen first)
typedef enum _midievent_types {
    E_TIMESIG	    = 1,
	E_KEYSIG	    = 2,
	E_TEMPO		    = 3,
	E_MARKER	    = 4,
	E_BARLINE	    = 5,
    E_DIVISION      = 6,
    E_SUBDIVISION   = 7,
	E_NOTEON	    = 8,
	E_NOTEOFF	    = 9
} e_midievent_types;

typedef struct _tempochange {
	double t_ms;
	double t_ticks;
	double t_newtempo;
} t_tempochange;

t_max_err write_to_buf_ptr(const void *src, unsigned char **basedest, long bytes, long *pos, long *size);
t_max_err write_to_buf_value(unsigned long v, unsigned char **basedest, long bytes, long *pos, long *size);
long write_to_buf_vlen_value(unsigned long v, unsigned char **basedest, long *pos, long *size);
void insert_in_buf_value(unsigned long v, unsigned char *basedest, long bytes, long pos);
long sort_midi_events(void *dummy, t_llllelem *a, t_llllelem *b);

void tempochange_set(t_tempochange *x, double ms, double ticks, double newtempo);

double get_tempo_from_marker(t_llll *marker_contents_ll);
void append_tempo_to_midi_export(t_llll *track_ll, double tempo, long time);
void get_timesig_from_marker(t_llll *marker_contents_ll, long *timesig_num, long *timesig_den);
void append_timesig_to_midi_export(t_llll *track_ll, long timesig_num, long timesig_den, long time);
void append_keysig_to_midi_export(t_llll *track_ll, t_voice *voice);
void append_note_to_midi_export(t_llll *track_ll, long type, long pitch, long vel, long channel, long time);
void append_marker_to_midi_export(t_llll *track_ll, t_atomarray *name, long time);
void append_barline_to_midi_export(t_llll *track_ll, long time);
void append_division_to_midi_export(t_llll *track_ll, long time);
void append_subdivision_to_midi_export(t_llll *track_ll, long time);


long create_raw_midi_data_buffer(t_llll **track_ll, long num_tracks, long format, long time_division, long time_offset, unsigned char **buffer);
void prepare_voices_to_write(t_notation_obj *x, t_llll **voices_to_write);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _NOTATION_FILES_H_
