/*
 *  notation_files.c
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

/**
	@file
	notation_files.c - common functions for notation to deal with files  

	by Andrea Agostini
*/

#include "foundation/llll_commons.h"
#include "notation/notation_files.h"

t_max_err write_to_buf_ptr(const void *src, unsigned char **basedest, long bytes, long *pos, long *size)
{
	if (*pos + bytes >= *size) {
		*size += 1024 + bytes;
		*basedest = (unsigned char *) bach_resizeptr(*basedest, *size);
	}
	if (!*basedest)
		return MAX_ERR_GENERIC;
	sysmem_copyptr(src, *basedest + *pos, bytes);
	*pos += bytes;
	return MAX_ERR_NONE;
}

t_max_err write_to_buf_value(unsigned long v, unsigned char **basedest, long bytes, long *pos, long *size)
{
	unsigned char *dest;
	if (*pos + bytes >= *size) {
		*size += 1024 + bytes;
		*basedest = (unsigned char *) bach_resizeptr(*basedest, *size);
	}
	if (!*basedest)
		return MAX_ERR_GENERIC;
	for (dest = *basedest + *pos + bytes - 1; dest >= *basedest + *pos; dest--) {
		*dest = v % 256;
		v /= 256;
	}
	*pos += bytes;
	return MAX_ERR_NONE;
}

void insert_in_buf_value(unsigned long v, unsigned char *basedest, long bytes, long pos)
{
	unsigned char *dest;
	dest = basedest + pos - 1;
	for (dest = basedest + pos + bytes - 1; dest >= basedest + pos; dest--) {
		*dest = v % 256;
		v /= 256;
	}
}

long write_to_buf_vlen_value(unsigned long v, unsigned char **basedest, long *pos, long *size)
{
	long bytes = 0;
	unsigned char res[4];
	long nextbyte_mask = 0;
	
	do {
		long this_byte = (v % 128) | nextbyte_mask;
		v /= 128;
		if (v) 
			nextbyte_mask = 0x80;
		res[3 - bytes] = this_byte;
		bytes++;
	} while (v && bytes < 4);
	
	if (*pos + bytes >= *size) {
		*size += 1024 + bytes;
		*basedest = (unsigned char *) bach_resizeptr(*basedest, *size);
	}
	if (!*basedest)
		return 0;
	
	sysmem_copyptr(res + 4 - bytes, *basedest + *pos, bytes);
	*pos += bytes;
	return bytes;
}

long sort_midi_events(void *dummy, t_llllelem *a, t_llllelem *b)
{
	t_llllelem *event_a_head = a->l_hatom.h_w.w_llll->l_head;
	t_llllelem *event_b_head = b->l_hatom.h_w.w_llll->l_head;
	
	long onset_a = event_a_head->l_next->l_hatom.h_w.w_long;
	long onset_b = event_b_head->l_next->l_hatom.h_w.w_long;
	
	if (onset_a != onset_b)
		return onset_a < onset_b;
	
	long type_a = event_a_head->l_hatom.h_w.w_long;
	long type_b = event_b_head->l_hatom.h_w.w_long;
	
	return type_a <= type_b;
}

double get_tempo_from_marker(t_llll *marker_contents_ll)
{
	double tempo = hatom_getdouble(&marker_contents_ll->l_tail->l_hatom);
	if (marker_contents_ll->l_size > 1)
		tempo /= hatom_getdouble(&marker_contents_ll->l_head->l_hatom) * 4;
	return tempo;
}

void append_tempo_to_midi_export(t_llll *track_ll, double tempo, long time)
{
	t_llll *tempo_ll = llll_get();
	llll_appendlong(tempo_ll, E_TEMPO, 0, WHITENULL_llll);
	llll_appendlong(tempo_ll, time, 0, WHITENULL_llll);
	llll_appenddouble(tempo_ll, 60000000. / tempo, 0, WHITENULL_llll);
	llll_appendllll(track_ll, tempo_ll, 0, WHITENULL_llll);
}

void append_barline_to_midi_export(t_llll *track_ll, long time)
{
	t_llll *barline_ll = llll_get();
	llll_appendlong(barline_ll, E_BARLINE, 0, WHITENULL_llll);
	llll_appendlong(barline_ll, time, 0, WHITENULL_llll);
	llll_appendllll(track_ll, barline_ll, 0, WHITENULL_llll);
}

void append_division_to_midi_export(t_llll *track_ll, long time)
{
    t_llll *barline_ll = llll_get();
    llll_appendlong(barline_ll, E_DIVISION, 0, WHITENULL_llll);
    llll_appendlong(barline_ll, time, 0, WHITENULL_llll);
    llll_appendllll(track_ll, barline_ll, 0, WHITENULL_llll);
}

void append_subdivision_to_midi_export(t_llll *track_ll, long time)
{
    t_llll *barline_ll = llll_get();
    llll_appendlong(barline_ll, E_SUBDIVISION, 0, WHITENULL_llll);
    llll_appendlong(barline_ll, time, 0, WHITENULL_llll);
    llll_appendllll(track_ll, barline_ll, 0, WHITENULL_llll);
}

void get_timesig_from_marker(t_llll *marker_contents_ll, long *timesig_num, long *timesig_den)
{
	*timesig_den = hatom_getlong(&marker_contents_ll->l_tail->l_hatom);
	if (*timesig_den < 1)
		*timesig_den = 1;
	if (marker_contents_ll->l_head->l_hatom.h_type == H_LLLL) {
		t_llll *timesig_num_ll = marker_contents_ll->l_head->l_hatom.h_w.w_llll;
		*timesig_num = 0;
		t_llllelem *this_elem;
		for (this_elem = timesig_num_ll->l_head; this_elem; this_elem = this_elem->l_next)
			*timesig_num += hatom_getlong(&this_elem->l_hatom);
	} else
		*timesig_num = hatom_getlong(&marker_contents_ll->l_head->l_hatom);
}

void append_timesig_to_midi_export(t_llll *track_ll, long timesig_num, long timesig_den, long time)
{
	t_llll *timesig_ll = llll_get();
	llll_appendlong(timesig_ll, E_TIMESIG, 0, WHITENULL_llll);
	llll_appendlong(timesig_ll, time, 0, WHITENULL_llll);
	llll_appendlong(timesig_ll, timesig_num, 0, WHITENULL_llll);
	llll_appendlong(timesig_ll, timesig_den, 0, WHITENULL_llll);
	llll_appendllll(track_ll, timesig_ll, 0, WHITENULL_llll);
}

void append_keysig_to_midi_export(t_llll *track_ll, t_voice *voice)
{
	t_llll *keysig_ll = llll_get();
	long key = 0, mode = 0;
	if (voice->mode == k_MODE_MAJOR || voice->mode == k_MODE_MINOR) {
		key = voice->key;
		mode = voice->mode == k_MODE_MAJOR ? 0 : 1;
	}
	llll_appendlong(keysig_ll, E_KEYSIG, 0, WHITENULL_llll);
	llll_appendlong(keysig_ll, 0, 0, WHITENULL_llll);
	llll_appendlong(keysig_ll, key, 0, WHITENULL_llll);
	llll_appendlong(keysig_ll, mode, 0, WHITENULL_llll);
	llll_appendllll(track_ll, keysig_ll, 0, WHITENULL_llll);
}

void append_note_to_midi_export(t_llll *track_ll, long type, long pitch, long vel, long channel, long time)
{
	t_llll *event_ll = llll_get();
	llll_appendlong(event_ll, type, 0, WHITENULL_llll);
	llll_appendlong(event_ll, time, 0, WHITENULL_llll);
	llll_appendlong(event_ll, pitch, 0, WHITENULL_llll);
	llll_appendlong(event_ll, vel, 0, WHITENULL_llll);
	llll_appendlong(event_ll, channel, 0, WHITENULL_llll);
	llll_appendllll(track_ll, event_ll, 0, WHITENULL_llll);
}

void append_marker_to_midi_export(t_llll *track_ll, t_atomarray *name, long time)
{
	t_llll *marker_ll = llll_get();
	llll_appendlong(marker_ll, E_MARKER, 0, WHITENULL_llll);
	llll_appendlong(marker_ll, time, 0, WHITENULL_llll);
	llll_appendobj(marker_ll, name, 0, WHITENULL_llll);
	llll_appendllll(track_ll, marker_ll, 0, WHITENULL_llll);
}

void tempochange_set(t_tempochange *x, double ms, double ticks, double newtempo)
{
	x->t_ms = ms;
	x->t_ticks = ticks;
	x->t_newtempo = newtempo;
}

long create_raw_midi_data_buffer(t_llll **track_ll, long num_tracks, long format, long time_division, long time_offset, unsigned char **buffer)
{
	long size;
	long pos = 0, i;
	t_llll **this_track_ll;
	
	if (!*buffer) {
		*buffer = (unsigned char *) bach_newptr(1024);
		size = 1024;
	} else
		size = sysmem_ptrsize(*buffer);
	
	write_to_buf_ptr("MThd\x00\x00\x00\x06", buffer, 8, &pos, &size);
	write_to_buf_value(format, buffer, 2, &pos, &size);
	write_to_buf_value(num_tracks, buffer, 2, &pos, &size);
	write_to_buf_value(time_division, buffer, 2, &pos, &size);
	
	for (i = 0, this_track_ll = track_ll; i < num_tracks; this_track_ll++, i++) {
		t_llll *out;
		long last_onset = time_offset;
		long chunksize_pos;
		long chunksize = 0;
		llll_mergesort(*this_track_ll, &out, sort_midi_events, NULL);
		*this_track_ll = out;
		write_to_buf_ptr("MTrk", buffer, 4, &pos, &size);
		chunksize_pos = pos;
		write_to_buf_value(0, buffer, 4, &pos, &size);
		t_llllelem *this_event;
        
        t_llll *prev_elem_ll = NULL;
        for (this_event = (*this_track_ll)->l_head; this_event; this_event = this_event->l_next) {
            t_llll *this_elem_ll = hatom_getllll(&this_event->l_hatom);
			t_llllelem *this_elem = this_elem_ll->l_head;
			e_midievent_types event_type = (e_midievent_types) this_elem->l_hatom.h_w.w_long;
			
			this_elem = this_elem->l_next;
            
            // if the event is tempo, timesig, barline or division AND
            // it is equal to the preceding one, don't write it
            if ((event_type != E_TEMPO &&
                 event_type != E_TIMESIG &&
                 event_type != E_BARLINE &&
                 event_type != E_DIVISION) ||
                !llll_eq_matchtype(this_elem_ll, prev_elem_ll)) {
                long event_abs_time = this_elem->l_hatom.h_w.w_long;
                long event_deltatime = event_abs_time - last_onset;
                
                
                
                chunksize += write_to_buf_vlen_value(event_deltatime, buffer, &pos, &size);
                
                switch (event_type) {
                    case E_NOTEON:
                    case E_NOTEOFF: {
                        this_elem = this_elem->l_next;
                        long pitch = hatom_getlong(&this_elem->l_hatom);
                        
                        this_elem = this_elem->l_next;
                        long velocity = event_type == E_NOTEON ? hatom_getlong(&this_elem->l_hatom) : 0;
                        
                        this_elem = this_elem->l_next;
                        long channel = hatom_getlong(&this_elem->l_hatom);
                        
                        unsigned char midievent = (event_type == E_NOTEON ? 0x90 : 0x80) + channel;
                        
                        write_to_buf_value(midievent, buffer, 1, &pos, &size);
                        write_to_buf_value(pitch, buffer, 1, &pos, &size);
                        write_to_buf_value(velocity, buffer, 1, &pos, &size);
                        chunksize += 3;
                        break;
                    }
                    case E_TEMPO: {
                        if (llll_eq_matchtype(this_elem_ll, prev_elem_ll))
                            break;
                        write_to_buf_value(0xFF, buffer, 1, &pos, &size);
                        write_to_buf_value(0x51, buffer, 1, &pos, &size);
                        chunksize += 2;
                        chunksize += write_to_buf_vlen_value(3, buffer, &pos, &size); // len
                        this_elem = this_elem->l_next;
                        write_to_buf_value(hatom_getlong(&this_elem->l_hatom), buffer, 3, &pos, &size);
                        chunksize += 3;
                        break;
                    }
                    case E_TIMESIG: {
                        if (llll_eq_matchtype(this_elem_ll, prev_elem_ll))
                            break;
                        long timesig_den, timesig_den_cooked, metro;
                        write_to_buf_value(0xFF, buffer, 1, &pos, &size);
                        write_to_buf_value(0x58, buffer, 1, &pos, &size);
                        chunksize += 2;
                        chunksize += write_to_buf_vlen_value(4, buffer, &pos, &size); // len
                        this_elem = this_elem->l_next;
                        write_to_buf_value(hatom_getlong(&this_elem->l_hatom), buffer, 1, &pos, &size); // numerator
                        this_elem = this_elem->l_next;
                        timesig_den = hatom_getlong(&this_elem->l_hatom);
                        timesig_den_cooked = log2(timesig_den) + 0.5;
                        write_to_buf_value(timesig_den_cooked, buffer, 1, &pos, &size); // denominator
                        metro = 96 / timesig_den;
                        write_to_buf_value(metro, buffer, 1, &pos, &size);
                        write_to_buf_value(8, buffer, 1, &pos, &size);
                        chunksize += 4;
                        break;
                    }
                    case E_KEYSIG: {
                        write_to_buf_value(0xFF, buffer, 1, &pos, &size);
                        write_to_buf_value(0x59, buffer, 1, &pos, &size);
                        chunksize += 2;
                        chunksize += write_to_buf_vlen_value(2, buffer, &pos, &size); // len
                        this_elem = this_elem->l_next;
                        write_to_buf_value(hatom_getlong(&this_elem->l_hatom), buffer, 1, &pos, &size); // key
                        this_elem = this_elem->l_next;
                        write_to_buf_value(hatom_getlong(&this_elem->l_hatom), buffer, 1, &pos, &size);	// mode
                        chunksize += 2;
                        break;
                    }
                    case E_BARLINE: {
                        if (llll_eq_matchtype(this_elem_ll, prev_elem_ll))
                            break;
                        const char *barline_txt = "bach barline";
                        const long barline_txt_size = 12; // doesn't contain terminator
                        write_to_buf_value(0xFF, buffer, 1, &pos, &size);
                        write_to_buf_value(0x06, buffer, 1, &pos, &size);
                        chunksize += 2;
                        chunksize += write_to_buf_vlen_value(barline_txt_size, buffer, &pos, &size); // len
                        write_to_buf_ptr(barline_txt, buffer, barline_txt_size, &pos, &size);
                        chunksize += barline_txt_size;
                        break;
                    }
                    case E_DIVISION: {
                        if (llll_eq_matchtype(this_elem_ll, prev_elem_ll))
                            break;
                        const char *division_txt = "bach division";
                        const long division_txt_size = 13; // doesn't contain terminator
                        write_to_buf_value(0xFF, buffer, 1, &pos, &size);
                        write_to_buf_value(0x06, buffer, 1, &pos, &size);
                        chunksize += 2;
                        chunksize += write_to_buf_vlen_value(division_txt_size, buffer, &pos, &size); // len
                        write_to_buf_ptr(division_txt, buffer, division_txt_size, &pos, &size);
                        chunksize += division_txt_size;
                        break;
                    }
                    case E_SUBDIVISION: {
                        if (llll_eq_matchtype(this_elem_ll, prev_elem_ll))
                            break;
                        const char *subdivision_txt = "bach subdivision";
                        const long subdivision_txt_size = 16; // doesn't contain terminator
                        write_to_buf_value(0xFF, buffer, 1, &pos, &size);
                        write_to_buf_value(0x06, buffer, 1, &pos, &size);
                        chunksize += 2;
                        chunksize += write_to_buf_vlen_value(subdivision_txt_size, buffer, &pos, &size); // len
                        write_to_buf_ptr(subdivision_txt, buffer, subdivision_txt_size, &pos, &size);
                        chunksize += subdivision_txt_size;
                        break;
                    }
                    case E_MARKER: {
                        t_atomarray *name;
                        char *name_txt = NULL;
                        long name_txt_size = 0, name_ac = 0;
                        t_atom *name_av;
                        write_to_buf_value(0xFF, buffer, 1, &pos, &size);
                        write_to_buf_value(0x06, buffer, 1, &pos, &size);
                        chunksize += 2;
                        this_elem = this_elem->l_next;
                        name = (t_atomarray *) hatom_getobj(&this_elem->l_hatom);
                        atomarray_getatoms(name, &name_ac, &name_av);
                        atom_gettext(name_ac, name_av, &name_txt_size, &name_txt,
                                     OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE |
                                     OBEX_UTIL_ATOM_GETTEXT_NUM_HI_RES);
                        name_txt_size--; // ignore the terminator
                        chunksize += write_to_buf_vlen_value(name_txt_size, buffer, &pos, &size); // len
                        write_to_buf_ptr(name_txt, buffer, name_txt_size, &pos, &size);
                        chunksize += name_txt_size;
                        object_free_debug(name);
                        break;
                    }
                }
                last_onset = event_abs_time;
            }
            prev_elem_ll = this_elem_ll;
		}
		// track end event
		chunksize += write_to_buf_vlen_value(0, buffer, &pos, &size);
		write_to_buf_value(0xFF, buffer, 1, &pos, &size);
		write_to_buf_value(0x2F, buffer, 1, &pos, &size);
		chunksize += 2;
		chunksize += write_to_buf_vlen_value(0, buffer, &pos, &size);
		
		// and now fix the chunksize!
		insert_in_buf_value(chunksize, *buffer, 4, chunksize_pos);
	}
	return pos;
}

void prepare_voices_to_write(t_notation_obj *x, t_llll **voices_to_write)
{
	t_llllelem *this_voicenum_elem, *next_elem;
	if (!*voices_to_write)
		*voices_to_write = llll_get();
	if ((*voices_to_write)->l_size == 0) {
		long i;
		for (i = 1; i <= x->num_voices; i++)
			llll_appendlong(*voices_to_write, i, 0, WHITENULL_llll);
	} else {
		t_llll *developed = llll_develop_ranges(*voices_to_write);
		llll_free(*voices_to_write);
		*voices_to_write = developed;
	}
	
	for (this_voicenum_elem = (*voices_to_write)->l_head; this_voicenum_elem; this_voicenum_elem = next_elem) {
		next_elem = this_voicenum_elem->l_next;
		t_atom_long *this_voice_num = &this_voicenum_elem->l_hatom.h_w.w_long; // llll_develop_ranges returned a list composed solely of H_LONGs
		if (*this_voice_num < 1 || *this_voice_num > x->num_voices) {
			object_warn((t_object *) x, "Voice " ATOM_LONG_PRINTF_FMT " does not exist", *this_voice_num);
			llll_destroyelem(this_voicenum_elem);
		} else
			(*this_voice_num)--;		
	}
}
