/*
 *  roll_files.c
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

#include "roll_files.h"
#include "foundation/llll_files.h"

void append_timesig_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time, long ts_num, long ts_dem);
t_llllelem* append_barline_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time);
t_llllelem* append_division_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time);
t_llllelem* append_subdivision_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time);
t_llllelem* append_marker_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time, t_symbol *text, t_symbol *role, t_llll *contents);

void roll_doreadmidi(t_roll *x, t_symbol *s, long ac, t_atom *av);
t_max_err roll_dowritemidi(t_roll *x, t_symbol *s, long ac, t_atom *av);

unsigned long midi_getvalue(unsigned char **buf, unsigned long bytes);
unsigned long midi_get_vlen_value(unsigned char **buf, t_ptr_size *size);
t_atom_ulong midi_track_and_chan_to_key(t_atom_ulong track, t_atom_ulong chan, long track2voice, long chan2voice);
void hashtab_free_one_llll(t_hashtab_entry *e, void *dummy);

void roll_doread(t_roll *x, t_symbol *s, long argc, t_atom *argv);
t_llll *roll_readmidi_direct(t_roll *x, t_filehandle fh, long track2voice, long chan2voice, long markmeasures, long markdivision, long importbarlines, long importdivisions, long importsubdivisions);

// chordthresh (default 0) > handlo io
// mergingpolicy (0 = merge to average, -1 merge to first, 1 merge to last)
// track2voice (default -1)
// channel2voice (default -1)
// importmarkers (default 1)

void roll_read_singlesymbol(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom a;
    char *text = NULL;
    long size;
    atom_gettext_debug(argc, argv, &size, &text, OBEX_UTIL_ATOM_GETTEXT_SYM_NO_QUOTE);
    if (size > 0) {
        t_llll *arguments = llll_get();
        t_symbol *s = gensym(text);
        llll_appendsym(arguments, s);
        bach_freeptr(text);
        atom_setobj(&a, arguments);
        defer((t_object *) x, (method) roll_doread, s, 1, &a);
    }
}

void roll_read(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
	t_atom a;
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	atom_setobj(&a, arguments);
	defer((t_object *) x, (method) roll_doread, s, 1, &a);
}

void roll_doread(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
	t_llll *arguments = (t_llll *) atom_getobj(argv);
	t_symbol *filename_sym = NULL;
	t_filehandle fh;
	double chord_thresh = 0;
	long merging_policy = 0;
	t_fourcc outtype = 0;
	t_fourcc file_types[] = {'Midi', 'TEXT', 'LLLL'};
	t_llll *roll_ll = NULL;
	char testbuf[5];
	t_ptr_size count = 5;
	t_dictionary *dict = NULL;
	short path;
	char filename[2048];
	long numtypes = (s == gensym("importmidi") ? 1 : 3); // if message is "importmidi", then don't allow opening of text files
	
	//bach_breakpoint(0);
	
    // these are only need to prevent llll_parseargs_and_attrs_destructive to complain for them
    long track2voice = -1;
    long chan2voice = -1;
    long markmeasures = 1;
    long markdivisions = 1;
    long importbarlines = 1;
    long importdivisions = 1;
    long importsubdivisions = 1;

    llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "disiiiiiii",
                                         gensym("chordthresh"), &chord_thresh,
                                         gensym("mergingpolicy"), &merging_policy,
                                         gensym("filename"), &filename_sym,
                                         gensym("tracks2voices"), &track2voice,
                                         gensym("chans2voices"), &chan2voice,
                                         gensym("markmeasures"), &markmeasures,
                                         gensym("markdivisions"), &markdivisions,
                                         gensym("importbarlines"), &importbarlines,
                                         gensym("importdivisions"), &importdivisions,
                                         gensym("importsubdivisions"), &importsubdivisions
                                         );
    
    if (arguments->l_size >= 1 && hatom_gettype(&arguments->l_head->l_hatom) == H_SYM) {
		filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
		llll_behead(arguments);
	}

	if (bach_openfile_for_read((t_object *) x, filename_sym, &path, file_types, numtypes, &outtype, filename) != MAX_ERR_NONE) {
		object_error((t_object *) x, "Can't open file");
		goto roll_doread_error_dontclose;
	}
	
	if (*filename == 0)
		goto roll_doread_error_dontclose;
	
	switch (outtype) {
		case 'Midi':
			if (bach_readfile((t_object *) x, filename, path, &fh) != MAX_ERR_NONE)
				goto roll_doread_error_dontclose;
			roll_ll = roll_readmidi_direct(x, fh, track2voice, chan2voice, markmeasures, markdivisions, importbarlines, importdivisions, importsubdivisions);
			if (!roll_ll)
				goto roll_doread_error_close;
			set_roll_from_llll_from_read(x, roll_ll);
			llll_free(roll_ll);
			handle_rebuild_done((t_notation_obj *) x);
			handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_IMPORT_MIDI_ROLL);
			if (chord_thresh >= 0) {
                lock_general_mutex((t_notation_obj *)x);
                merge(x, chord_thresh, -1, merging_policy, merging_policy, 0, 0);
                unlock_general_mutex((t_notation_obj *)x);
			}
			break;
		default:
			// is it a new-format native llll?
			if (dictionary_read(filename, path, &dict) == MAX_ERR_NONE) {
				roll_ll = llll_retrieve_from_dictionary(dict, "data");
				object_free(dict);
			} else {
				if (bach_readfile((t_object *) x, filename, path, &fh) != MAX_ERR_NONE)
					goto roll_doread_error_dontclose;
				// let's try to guess if it's xml
				sysfile_read(fh, &count, testbuf);
				sysfile_setpos(fh, SYSFILE_FROMSTART, 0);
				if (!memcmp(testbuf, "<?xml", 5)) { // xml
					object_error((t_object *) x, "Can't open an XML file. Maybe you meant to open it with bach.score?");
					goto roll_doread_error_close;
				}
				roll_ll = llll_readfile((t_object *) x, fh);
			}

			if (!roll_ll)
				goto roll_doread_error_dontclose;
			set_roll_from_llll_from_read(x, roll_ll);
			llll_free(roll_ll);
			handle_rebuild_done((t_notation_obj *) x);
			handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER, k_UNDO_OP_READ_ROLL);
			break;
	}
	
roll_doread_error_dontclose:
	llll_free(arguments);
	return;
roll_doread_error_close:
	llll_free(arguments);
	sysfile_close(fh);
	return;
}


/*
 arguments:
 tracks2voices (default: smart)
 chans2voices (default: smart)
 markmeasures
 */


t_llll *roll_readmidi_direct(t_roll *x, t_filehandle fh, long track2voice, long chan2voice, long markmeasures, long markdivisions, long importbarlines, long importdivisions, long importsubdivisions)
{
	t_ptr_size size;
	unsigned char *buffer, *buffer_orig = NULL;
	unsigned long time_division, num_tracks;
	t_llll *roll_ll = NULL;
	t_llll *keys_ll = NULL;
	t_llll *markers_ll = NULL;
	t_llll *clefs_ll = NULL;
	t_llll *midichannels_ll = NULL;
	t_hashtab *key2voice = NULL, *noteons = NULL;
	t_llll *all_events = NULL;
	long ts_num = 4, ts_den = 4;
    t_rational divis;
	long measure_duration, beat_duration;
	// only for now!!!
	long ok = 1;
	long last_abs_tempo_change = 0;
	double ms_offset = 0;
	double tempo = 120.;
	unsigned long next_good_ts_onset = 0;
	t_llllelem *first_voice_elem = NULL;
	double ticksperms = 0;
	unsigned long format_type = 1;
    t_timesignature ts;
    
	// allocate memory block that is the size of the file
	sysfile_geteof(fh, &size);
	buffer_orig = buffer = (unsigned char *) bach_newptr(size + 1);
    buffer_orig[0] = 0;
	//buffer_end = buffer + size;
	// read in the file
	sysfile_read(fh, &size, buffer);
	
    t_llll *all_calculated_barlines = llll_get();
    t_llll *all_calculated_divisions = llll_get();
    t_bool are_there_imported_barlines = false;
    t_bool are_there_imported_divisions = false;
    
	// check for validity
	bach_assert_objerror_goto(x, ok = ((size -= 14) >= 0), "Invalid file format: missing file header", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
	bach_assert_objerror_goto(x, ok = !memcmp(buffer, "MThd\x00\x00\x00\x06", 8), "Invalid file format: bad header", readmidi_error);
	buffer += 8;
	
	format_type = midi_getvalue(&buffer, 2);
	
	if (format_type == 0) {
        if (chan2voice < 0)
            chan2voice = 1;
		if (track2voice < 0)
            track2voice = 0;
	} else {
        if (chan2voice < 0)
            chan2voice = 0;
		if (track2voice < 0)
            track2voice = 1;
	}
	
	
	bach_assert_objerror_goto(x, ok = (format_type == 0 || format_type == 1), "Only MIDI file formats 0 and 1 are supported", readmidi_error);
	
    /*if (importbarlines && markmeasures) {
		dev_object_warn((t_object *) x, "markmeasures and importbarlines are both active");
    }*/
	
	num_tracks = midi_getvalue(&buffer, 2);
	
	if ((*buffer & 0x80) == 0) { // ticks per beat
		time_division = midi_getvalue(&buffer, 2);
	} else {
		double fps = *buffer & 0x7f;
		if (fps == 29.)
			fps = 29.97;
		buffer++;
		unsigned char ticksperframe = *buffer;
		buffer++;
		time_division = fps * ticksperframe;
	}
	measure_duration = time_division * 4 * ts_num / ts_den;
    ts = build_simple_timesignature((t_notation_obj *) x, ts_num, ts_den);
    divis = ts_to_division((t_notation_obj *) x, &ts);
    beat_duration = time_division * 4 * divis.r_num / divis.r_den;
	
	all_events = llll_get();
	// each element of all_events is an llll which can have the following forms:
	// - E_NOTEON time obj where obj points to the note llll
	// - E_NOTEOFF time obj where obj points to the note llll
	// - E_TEMPO time newtempo
	
	roll_ll = llll_get();
	llll_appendsym(roll_ll, _llllobj_sym_roll, 0, WHITENULL_llll);
	key2voice = hashtab_new_debug(0);
	hashtab_flags(key2voice, OBJ_FLAG_DATA);
	noteons = hashtab_new_debug(0); // each entry is a llll containing the pending note ons for a voice
	hashtab_flags(noteons, OBJ_FLAG_DATA);
	unsigned long this_track;
	keys_ll = llll_get();
	markers_ll = llll_get();
	llll_appendsym(markers_ll, _llllobj_sym_markers, 0, WHITENULL_llll);
	for (this_track = 0; this_track < num_tracks; this_track++) {
		long go_on = 1;
		unsigned long abstime = 0; // measured in ticks
		unsigned long midi_channel_prefix = 0; // for meta-events
        while (1) {
            bach_assert_objerror_goto(x, ok = ((size -= 8) >= 0), "Corrupted or invalid MIDI file: missing track header", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
            //bach_assert_objerror_goto(x, ok = (!strncmp((char *) buffer, "MTrk", 4)), "Corrupted or invalid MIDI file: bad track header", readmidi_error);
            if (!strncmp((char *) buffer, "MTrk", 4))
                break;
            buffer++;
        }
		buffer += 4;
		
		unsigned long chunksize = midi_getvalue(&buffer, 4); // the size of the track chunk
		
		unsigned char *track_start = buffer;
		unsigned char midievent = 0;
		unsigned char prev_midichannel_event = 0;
		while (go_on && (buffer - track_start < (long) chunksize)) {
			unsigned long deltatime = midi_get_vlen_value(&buffer, &size);
			bach_assert_objerror_goto(x, ok = (size >= 0), "Corrupted or invalid MIDI file: missing event", readmidi_error); 
			abstime += deltatime;
			bach_assert_objerror_goto(x, ok = (--size >= 0), "Corrupted or invalid MIDI file: incomplete event", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
			unsigned char firstbyte = *(buffer++);
			long velocity = -1;
			long pitch = 0;
			if (firstbyte > 0x7F) // if not, we're in running status - i.e., we can assume that the midievent is the same as before
				midievent = firstbyte;
			else
				midievent = prev_midichannel_event;
			bach_assert_objerror_goto(x, midievent >= 0x80, "Corrupted or invalid MIDI file: expecting status byte, found data byte", readmidi_error);
			if (midievent < 0xF0) { // it is a midi channel event
				unsigned long channel = (midievent & 0x0F) + 1;
				unsigned char eventtype = midievent & 0xF0;
				long param1, param2 = 0;
				if (firstbyte > 0x7F) {
					bach_assert_objerror_goto(x, ok = (--size >= 0), "Corrupted or invalid MIDI file: missing first data byte", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
					param1 = *(buffer++);
				} else
					param1 = firstbyte;
				if (eventtype != 0xC0 && eventtype != 0xD0) {
					bach_assert_objerror_goto(x, ok = (--size >= 0), "Corrupted or invalid MIDI file: missing second data byte", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
					param2 = *(buffer++);
				}
				if (eventtype == 0x90) { // note on
					pitch = param1;
					velocity = param2;
					if (velocity > 0) { // that is, a real note on
						t_atom_ulong key = midi_track_and_chan_to_key(this_track, channel, track2voice, chan2voice);
						t_llll *voice;
						t_max_err err = hashtab_lookup(key2voice, (t_symbol *) key, (t_object **) &voice);
						if (err != MAX_ERR_NONE) { // didn't find the voice: we need to create it
							t_llll *pitches_ll;
							voice = llll_get();
							voice->l_thing.w_ulong = key;
							t_llllelem *prev_elem = NULL, *this_elem;
							
							for (this_elem = first_voice_elem; this_elem; this_elem = this_elem->l_next) {
								if (this_elem->l_hatom.h_w.w_llll->l_thing.w_ulong >= key) // l_thing is the hash key, and we're inserting the new voice according to the key order
									break;
								prev_elem = this_elem;
							}
							if (prev_elem == NULL) { // then it goes at the first place
								if (first_voice_elem ==	NULL) // there is no voice yet
									first_voice_elem = llll_appendllll(roll_ll, voice, 0, WHITENULL_llll);
								else
									first_voice_elem = llll_insertllll_before(voice, first_voice_elem, 0, WHITENULL_llll);
							} else if (this_elem == NULL) { // then it goes at the last place
								llll_appendllll(roll_ll, voice, 0, WHITENULL_llll);
							} else { // it goes right before this_elem
								llll_insertllll_before(voice, this_elem, 0, WHITENULL_llll);
							}
							pitches_ll = llll_get();
							llll_appendllll(voice, pitches_ll, 0, WHITENULL_llll); // this will be removed later on, when the clefs sublist is set
							llll_appendlong(voice, channel, 0, WHITENULL_llll); // this will be removed later on, when the midichannels sublist is set
							
							hashtab_store(key2voice, (t_symbol *) key, (t_object *) voice);
						}
						t_llll *chord = llll_get();
						llll_appendlong(chord, abstime, 0, WHITENULL_llll);
						t_llll *note = llll_get();
						llll_appendlong(note, pitch * 100, 0, WHITENULL_llll);
						llll_appendlong(note, 0., 0, WHITENULL_llll); // provisional duration, to be set later
						llll_appendlong(note, velocity, 0, WHITENULL_llll);
						llll_appendlong(note, 0, 0, WHITENULL_llll); // note flags
						llll_appendllll(chord, note, 0, WHITENULL_llll);
						llll_appendlong(chord, 0, 0, WHITENULL_llll); // chord flags
						llll_appendllll(voice, chord, 0, WHITENULL_llll);
						t_llll *noteon_ll = NULL;
						key = channel * 65536 + pitch;
						err = hashtab_lookup(noteons, (t_symbol *) key, (t_object **) &noteon_ll);							
						if (err != MAX_ERR_NONE) {
							noteon_ll = llll_get();
							hashtab_store(noteons, (t_symbol *) key, (t_object *) noteon_ll);
						}
						llll_appendobj(noteon_ll, note, 0, WHITENULL_llll);	
						
						t_llll *event = llll_get();
						llll_appendlong(event, E_NOTEON, 0, WHITENULL_llll);
						llll_appendlong(event, abstime, 0, WHITENULL_llll);
						llll_appendobj(event, note, 0, WHITENULL_llll);
						llll_appendllll(all_events, event, 0, WHITENULL_llll);
						
						llll_appendlong(voice->l_head->l_hatom.h_w.w_llll, pitch * 100, 0, WHITENULL_llll);
					}
				}
				if (eventtype == 0x80 || velocity == 0) { // note off
					pitch = param1;
					unsigned long key = channel * 65536 + pitch;
					t_llll *noteon_ll = NULL;
					t_max_err err = hashtab_lookup(noteons, (t_symbol *) key, (t_object **) &noteon_ll);
					if (err == MAX_ERR_NONE && noteon_ll->l_size > 0) {
						t_llll *note = (t_llll *) noteon_ll->l_head->l_hatom.h_w.w_obj;
						llll_destroyelem(noteon_ll->l_head);
						t_llll *event = llll_get();
						llll_appendlong(event, E_NOTEOFF, 0, WHITENULL_llll);
						llll_appendlong(event, abstime, 0, WHITENULL_llll);
						llll_appendobj(event, note, 0, WHITENULL_llll);
						llll_appendllll(all_events, event, 0, WHITENULL_llll);
					} else {
						object_warn((t_object *) x, "Unmatched note off");
					}
					
				}
				// other event types are ignored for now
				prev_midichannel_event = midievent;
			} else if (midievent == 0xFF) { // it is a meta-event
				bach_assert_objerror_goto(x, ok = (--size >= 0), "Corrupted or invalid file format: meta-event missing length specifier", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
				unsigned char eventtype = *(buffer++);
				unsigned long len = midi_get_vlen_value(&buffer, &size);
				bach_assert_objerror_goto(x, ok = (size >= 0), "Corrupted or invalid file format: meta-event missing data", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
				switch (eventtype) {
					case 0x06: // marker
					case 0x07: // cue point
					{
						bach_assert_objerror_goto(x, ok = ((size -= len) >= 0), "Corrupted or invalid MIDI file: insufficient data for marker or cue point", readmidi_error);
						char text[4096];
						long textlen = MIN(len, 4095) + 1; // includes terminator
						strncpy_zero(text, (const char *) buffer, textlen);
                        
                        if (!strncmp(text, "bach barline", textlen)) {
                            if (importbarlines) {
                                append_barline_to_midi_import(all_events, markers_ll, abstime);
                                are_there_imported_barlines = true;
                            }
                        } else if (!strncmp(text, "bach division", textlen)) {
                            if (importdivisions) {
                                append_division_to_midi_import(all_events, markers_ll, abstime);
                                are_there_imported_divisions = true;
                            }
                        } else if (!strncmp(text, "bach subdivision", textlen)) {
                            if (importsubdivisions) {
                                append_subdivision_to_midi_import(all_events, markers_ll, abstime);
                            }
                        } else {
                            append_marker_to_midi_import(all_events, markers_ll, abstime, gensym(text), _llllobj_sym_none, NULL);

                        }

						buffer += len;
						break;
					}
						
					case 0x58: // time signature
					{
						long metro, thirtyseconds;
						bach_assert_objerror_goto(x, ok = (len == 4 && (size -= len) >= 0), "Corrupted or invalid MIDI file: bad data for time signature", readmidi_error);
						long fix_measure_duration = next_good_ts_onset > abstime + 2 && (abstime + 2) % measure_duration < 4; // a time signature is well placed if it falls on a barline (save for a small epsilon)
						long stop_here;
                        t_timesignature ts;
						
						if (markmeasures || markdivisions) {
							stop_here = abstime - 3;
                            
							// place one automatic marker per measure until the current abstime (if the current abstime falls at the beginning of a measure, which should always be the case in a good MIDI file)
							while ((long) next_good_ts_onset <= stop_here) {
                                unsigned long next_division;
                                if (markmeasures) {
                                    llll_appendobj(all_calculated_barlines, append_barline_to_midi_import(all_events, markers_ll, next_good_ts_onset));
                                    next_division = next_good_ts_onset - measure_duration + beat_duration;
                                } else {
                                    next_division = next_good_ts_onset - measure_duration;
                                }
                                if (markdivisions) {
                                    while ((long) next_division < next_good_ts_onset && (long) next_division <= stop_here) {
                                        llll_appendobj(all_calculated_divisions, append_division_to_midi_import(all_events, markers_ll, next_division));
                                        next_division += beat_duration;
                                    }
                                }
                                next_good_ts_onset += measure_duration;
							}
						}
						
						ts_num = midi_getvalue(&buffer, 1);
						ts_den = iexp2(midi_getvalue(&buffer, 1));
						if (ts_den < 1) {
							ts_den = 4;
							object_warn((t_object *) x, "Bad time signature: %d/%d, fixing with %d/4", ts_num, ts_den, ts_num);
						}
						metro = midi_getvalue(&buffer, 1); // unused
						thirtyseconds = midi_getvalue(&buffer, 1); // unused
						append_timesig_to_midi_import(all_events, markers_ll, abstime, ts_num, ts_den);
						if ((markmeasures || markdivisions) && fix_measure_duration)
							next_good_ts_onset -= measure_duration;
						measure_duration = time_division * 4 * ts_num / ts_den;
                        ts = build_simple_timesignature((t_notation_obj *) x, ts_num, ts_den);
                        divis = ts_to_division((t_notation_obj *) x, &ts);
                        beat_duration = time_division * 4 * divis.r_num / divis.r_den;
                        if ((markmeasures || markdivisions) && (fix_measure_duration || next_good_ts_onset == abstime))
							next_good_ts_onset += measure_duration;
						break;
					}
						
					case 0x20: // midi channel prefix
						bach_assert_objerror_goto(x, ok = (--size >= 0), "Corrupted or invalid MIDI file: insufficient data for MIDI channel prefix", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
						midi_channel_prefix = *(buffer++);
						break;
						
					case 0x2F: // track end
					{
                        if (markmeasures || markdivisions) {
                            
                            // place one automatic marker per measure until the current abstime (if the current abstime falls at the beginning of a measure, which should always be the case in a good MIDI file)
                            while ((long) next_good_ts_onset <= abstime) {
                                unsigned long next_division;
                                if (markmeasures) {
                                    llll_appendobj(all_calculated_barlines, append_barline_to_midi_import(all_events, markers_ll, next_good_ts_onset));
                                    next_division = next_good_ts_onset - measure_duration + beat_duration;
                                } else {
                                    next_division = next_good_ts_onset - measure_duration;
                                }
                                if (markdivisions) {
                                    while ((long) next_division < next_good_ts_onset && (long) next_division <= abstime) {
                                        llll_appendobj(all_calculated_divisions, append_division_to_midi_import(all_events, markers_ll, next_division));
                                        next_division += beat_duration;
                                    }
                                }
                                next_good_ts_onset += measure_duration;
                            }
                        }
                        
						go_on = 0;
						break;
					}
						
					case 0x51: // tempo (microseconds per quarter note) 
					{
						t_llll *event;
						bach_assert_objerror_goto(x, ok = (len == 3 && (size -= 3) >= 0), "Corrupted or invalid MIDI file: bad data for tempo event", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
						t_llll *tempo_ll = llll_get();
						llll_appendrat(tempo_ll, genrat(1, 4), 0, WHITENULL_llll);
						double bpm = 60000000. / midi_getvalue(&buffer, 3);
						llll_appenddouble(tempo_ll, bpm, 0, WHITENULL_llll);
						append_marker_to_midi_import(all_events, markers_ll, abstime, NULL, _llllobj_sym_tempo, tempo_ll);
						event = llll_get();
						llll_appendlong(event, E_TEMPO, 0, WHITENULL_llll);
						llll_appendlong(event, abstime, 0, WHITENULL_llll);
						llll_appenddouble(event, bpm, 0, WHITENULL_llll); // this is the actual BPM
						llll_appendllll(all_events, event, 0, WHITENULL_llll);
						break;
					}
						
					case 0x59: // key signature
					{	
						bach_assert_objerror_goto(x, ok = (len == 2 && (size -= len) >= 0), "Corrupted or invalid MIDI file: bad data for key signature", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
						if (keys_ll->l_size == 0) { // if no time signature has been defined yet
							long keysig_midi = midi_getvalue(&buffer, 1);
							long mode_midi = midi_getvalue(&buffer, 1);
							t_symbol *keysig_sym = key_and_mode_to_sym((t_notation_obj *) x, keysig_midi, mode_midi == 0 ? k_MODE_MAJOR : k_MODE_MINOR, NULL);
							llll_appendsym(keys_ll, keysig_sym, 0, WHITENULL_llll);
						} else
							buffer += 2; // fix it quickly!
						break;
					}
						
					case 0x00: // sequence number (should never happen)
					case 0x01: // text event
					case 0x02: // copyright
					case 0x03: // sequence/track name
					case 0x04: // instrument name
					case 0x05: // lyrics	
					case 0x09: // device name
					case 0x21: // MIDI port
					case 0x54: // smpte offset
					case 0x7F: // sequencer specific
						bach_assert_objerror_goto(x, ok = ((size -= len) >= 0), "Corrupted or invalid MIDI file: insufficient meta-event data", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
						buffer += len;
						break;
						
					default:
						bach_assert_objerror_goto(x, ok = ((size -= len) >= 0), "Corrupted or invalid MIDI file: insufficient data for unknown meta-event", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
						object_warn((t_object *) x, "Unknown MIDI meta-event type (%x)", eventtype);
						buffer += len;
						break;
				}
			} else if (midievent == 0xF0 || midievent == 0xF7) { // it is a sysex
				unsigned long len = midi_get_vlen_value(&buffer, &size);
				bach_assert_objerror_goto(x, ok = (size >= 0), "Corrupted or invalid file format: bad data for sysex", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
				buffer += len;
			}
		}
		//bach_assert_objerror_goto(x, ok = (!go_on && buffer - track_start >= (long) chunksize), "Corrupted or invalid MIDI file: bad chunk size", readmidi_error);
		hashtab_funall(noteons, (method) hashtab_free_one_llll, NULL);
		hashtab_clear(noteons);
	}
	
    
    if (are_there_imported_barlines) {
        if (all_calculated_barlines->l_size) {
            object_warn((t_object*) x, "Removed calculated barlines as there are barline markers in the MIDI file");
        }
        for (t_llllelem *barline_ref = all_calculated_barlines->l_head; barline_ref; barline_ref = barline_ref->l_next) {
            t_llllelem *event_elem = barline_ref->l_hatom.h_w.w_llllelem; // contained in all_events
            t_llll *this_marker_ll = event_elem->l_hatom.h_w.w_llll->l_tail->l_hatom.h_w.w_llll;
            t_bool check1 = event_elem->l_parent == all_events;
            t_bool check2 = this_marker_ll->l_owner->l_parent == markers_ll;
            
            llll_destroyelem(event_elem);
            llll_destroyelem(this_marker_ll->l_owner);
        }
    }
    
    if (are_there_imported_divisions) {
        if (all_calculated_divisions->l_size) {
            object_warn((t_object*) x, "Removed calculated divisions as there are division markers in the MIDI file");
        }
        for (t_llllelem *division_ref = all_calculated_divisions->l_head; division_ref; division_ref = division_ref->l_next) {
            t_llllelem *event_elem = division_ref->l_hatom.h_w.w_llllelem; // contained in all_events
            t_llll *this_marker_ll = event_elem->l_hatom.h_w.w_llll->l_tail->l_hatom.h_w.w_llll;
            t_bool check1 = event_elem->l_parent == all_events;
            t_bool check2 = this_marker_ll->l_owner->l_parent == markers_ll;
            
            llll_destroyelem(event_elem);
            llll_destroyelem(this_marker_ll->l_owner);
        }
    }
    
	llll_insertllll_after(markers_ll, roll_ll->l_head, 0, WHITENULL_llll);
	markers_ll = NULL; // don't free it anymore
	
	t_llllelem *this_elem;
	clefs_ll = llll_get();
	midichannels_ll = llll_get();
	llll_appendsym(clefs_ll, _llllobj_sym_clefs, 0, WHITENULL_llll);
	
	//	llll_appendsym(clefs_ll, _llllobj_sym_midichannels, 0, WHITENULL_llll); // UNCOMMENT TO CRASH!!!
	llll_appendsym(midichannels_ll, _llllobj_sym_midichannels, 0, WHITENULL_llll); // and comment this one instead
	
	for (this_elem = first_voice_elem; this_elem; this_elem = this_elem->l_next) {
		t_llll *this_voice_ll;
		long clef;
		t_symbol *clef_sym;
		long channel;
		bach_assert_objerror_goto(x, ok = (hatom_gettype(&this_elem->l_hatom) == H_LLLL), "roll_doreadmidi: bug", readmidi_error); // <header> + <format> + <num tracks> + <ticks per beat>
		this_voice_ll = this_elem->l_hatom.h_w.w_llll;
		this_voice_ll->l_thing.w_ulong = 0;
		
		// each voice's llll is now composed by:
		// - an llll with the list of pitches
		// - a long for the channel
		// - the chords
		
		clef = infer_most_appropriate_clef((t_notation_obj *) x, this_voice_ll->l_head->l_hatom.h_w.w_llll, 1.5);
		clef_sym = clef_number_to_clef_symbol((t_notation_obj *) x, clef);
		llll_appendsym(clefs_ll, clef_sym, 0, WHITENULL_llll);	// to be improved
		llll_destroyelem(this_voice_ll->l_head); // strip away the list of pitches
		
		channel = this_voice_ll->l_head->l_hatom.h_w.w_long;
		llll_appendlong(midichannels_ll, channel, 0, WHITENULL_llll);
		llll_destroyelem(this_voice_ll->l_head); // strip away the channel
	}
	llll_insertllll_after(midichannels_ll, roll_ll->l_head, 0, WHITENULL_llll);
	llll_insertllll_after(clefs_ll, roll_ll->l_head, 0, WHITENULL_llll);
	clefs_ll = NULL; // don't free it anymore
	midichannels_ll = NULL; // don't free it anymore
	
	if (keys_ll->l_size) {
		llll_prependsym(keys_ll, _llllobj_sym_keys, 0, WHITENULL_llll);
		llll_insertllll_after(keys_ll, roll_ll->l_head, 0, WHITENULL_llll);
	} else
		llll_free(keys_ll);
	keys_ll = NULL; // don't free it anymore

    
	// now we need to sort all_events according to time, and change all the onsets and durations according to the tempi
	t_llll *all_events_sorted;
	llll_mergesort(all_events, &all_events_sorted, sort_midi_events, NULL);
	all_events = all_events_sorted;
	ticksperms = time_division * tempo / 60000.;
	t_llllelem *this_event;
	
	for (this_event = all_events->l_head; this_event; this_event = this_event->l_next) {
		t_llllelem *this_event_llll_head = this_event->l_hatom.h_w.w_llll->l_head;
		e_midievent_types event_type = (e_midievent_types) this_event_llll_head->l_hatom.h_w.w_long;
		long event_abs_time = this_event_llll_head->l_next->l_hatom.h_w.w_long;
		double event_ms_time = (event_abs_time - last_abs_tempo_change) / ticksperms + ms_offset;
		switch (event_type) {
			case E_NOTEON: // E_NOTEON <time> <note_ll>
			{
				t_llll *note = (t_llll *) this_event_llll_head->l_next->l_next->l_hatom.h_w.w_obj;
				t_llll *chord = note->l_owner->l_parent;
				t_hatom *chord_onset_hatom = &chord->l_head->l_hatom;
				hatom_setdouble(chord_onset_hatom, event_ms_time); // no need to call hatom_change_to_double as surely we don't have do deal with sublists
				break;
			}
			case E_NOTEOFF: // E_NOTEOFF <time> <note_ll>
			{
				t_llll *note = (t_llll *) this_event_llll_head->l_next->l_next->l_hatom.h_w.w_obj;
				t_llll *chord = note->l_owner->l_parent;
				double chord_onset = chord->l_head->l_hatom.h_w.w_double; // if we have a noteoff, its noteon has surely been converted before
				t_hatom *note_duration_hatom = &note->l_head->l_next->l_hatom;
				hatom_setdouble(note_duration_hatom, event_ms_time - chord_onset - 1.);
				break;
			}
			case E_TEMPO: // E_TEMPO <time> <tempo>
			{
				tempo = this_event_llll_head->l_next->l_next->l_hatom.h_w.w_double;
				ticksperms = time_division * tempo / 60000.;
				last_abs_tempo_change = event_abs_time;
				ms_offset = event_ms_time;
				break;
			}
			case E_MARKER: // E_MARKER <time> <marker>
			{
				t_llll *this_marker_ll = (t_llll *) this_event_llll_head->l_next->l_next->l_hatom.h_w.w_obj;
				t_hatom *marker_onset = &this_marker_ll->l_head->l_hatom;
				hatom_setdouble(marker_onset, event_ms_time);
				break;
			}
			default:
				break;
		}
	}
	
//	dev_llll_print(roll_ll, (t_object *) x, 0, 6, NULL);
	
readmidi_error:
    llll_free(all_calculated_barlines);
    llll_free(all_calculated_divisions);

	if (!ok) {
		llll_free(roll_ll);
		roll_ll = NULL;
	}
	if (buffer_orig)
		bach_freeptr(buffer_orig);
	if (key2voice)
		object_free_debug(key2voice);
	if (noteons) {
		hashtab_funall(noteons, (method) hashtab_free_one_llll, NULL);
		object_free_debug(noteons);
	}
	if (all_events)
		llll_free(all_events);
	if (keys_ll)
		llll_free(keys_ll);
	if (markers_ll)
		llll_free(markers_ll);
	if (midichannels_ll)
		llll_free(markers_ll);
	return roll_ll;
}

void roll_exportmidi(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
	t_atom av;
	t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
	atom_setobj(&av, arguments);
	defer(x, (method)roll_dowritemidi, s, 1, &av);
}

void roll_write(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
	t_llll *roll_as_llll;
	t_symbol *filename = NULL;
	if ((argc >= 1) && (atom_gettype(argv) == A_SYM))
		filename = atom_getsym(argv);
	roll_as_llll = get_roll_values_as_llll(x, k_CONSIDER_FOR_SAVING, k_HEADER_ALL, true, false); // we save everything
	llll_writenative((t_object *) x, filename, roll_as_llll);
}

void roll_writetxt(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
	t_llll *roll_as_llll = get_roll_values_as_llll(x, k_CONSIDER_FOR_SAVING, k_HEADER_ALL, true, false); // we save everything
	llll_writetxt((t_object *) x, roll_as_llll, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_SMART, LLLL_TB_SMART);
}

void roll_exportom(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
	t_llll *roll_as_llll = get_roll_values_as_llll(x, k_CONSIDER_FOR_EXPORT_OM, k_HEADER_ALL, true, false); // we save everything
	llll_writetxt((t_object *) x, roll_as_llll, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_PARENS, LLLL_TE_DOUBLE_QUOTE, LLLL_TB_SPECIAL);
}

void roll_exportpwgl(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
	t_llll *roll_as_llll_for_pwgl = get_roll_values_as_llll_for_pwgl(x);
	llll_writetxt((t_object *) x, roll_as_llll_for_pwgl, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_PARENS, LLLL_TE_DOUBLE_QUOTE, LLLL_TB_SPECIAL);
}

unsigned long midi_getvalue(unsigned char **buf, unsigned long bytes)
{
	unsigned long res = 0, i;
	for (i = 0; i < bytes; i++) {
		res = res * 256 + **buf;
		(*buf)++;
	}
	return res;
}

unsigned long midi_get_vlen_value(unsigned char **buf, t_ptr_size *size)
{
	long go_on = 1;
	unsigned long res = 0;
	while (go_on) {
		if (*size == 0)
			return -1;
        --(*size);
		res = res * 128 + (**buf & 0x7f);
		go_on = **buf & 0x80;
		(*buf)++;
	}
	return res;
}

t_atom_ulong midi_track_and_chan_to_key(t_atom_ulong track, t_atom_ulong chan, long track2voice, long chan2voice)
{
	if (track2voice && chan2voice)
		return track * 65536 + chan;
	if (track2voice)
		return track;
	if (chan2voice)
		return chan;
	return 1;
}

void hashtab_free_one_llll(t_hashtab_entry *e, void *dummy)
{
	llll_free((t_llll *)(e->value));
}

void append_timesig_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time, long ts_num, long ts_den)
{
	t_llll *timesig_ll = llll_get();
	llll_appendlong(timesig_ll, ts_num, 0, WHITENULL_llll);
	llll_appendlong(timesig_ll, ts_den, 0, WHITENULL_llll);
	append_marker_to_midi_import(all_events, markers_ll, time, NULL, _llllobj_sym_timesig, timesig_ll);
}

t_llllelem* append_barline_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time)
{
	return append_marker_to_midi_import(all_events, markers_ll, time, NULL, _llllobj_sym_barline, NULL);
}

t_llllelem* append_division_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time)
{
    return append_marker_to_midi_import(all_events, markers_ll, time, NULL, _llllobj_sym_division, NULL);
}

t_llllelem* append_subdivision_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time)
{
    return append_marker_to_midi_import(all_events, markers_ll, time, NULL, _llllobj_sym_subdivision, NULL);
}

t_llllelem* append_marker_to_midi_import(t_llll *all_events, t_llll *markers_ll, long time, t_symbol *text, t_symbol *role, t_llll *contents)
{
	t_llll *this_marker_ll = llll_get();
	llll_appendlong(this_marker_ll, time, 0, WHITENULL_llll);
	if (text)
		llll_appendsym(this_marker_ll, text, 0, WHITENULL_llll);
	else 
		llll_appendllll(this_marker_ll, llll_get(), 0, WHITENULL_llll);
	llll_appendsym(this_marker_ll, role, 0, WHITENULL_llll);
	if (contents)
		llll_appendllll(this_marker_ll, contents, 0, WHITENULL_llll);
	llll_appendllll(markers_ll, this_marker_ll, 0, WHITENULL_llll);
	
	t_llll *event = llll_get();
	llll_appendlong(event, E_MARKER, 0, WHITENULL_llll);
	llll_appendlong(event, time, 0, WHITENULL_llll);
	llll_appendobj(event, this_marker_ll, 0, WHITENULL_llll);
	return llll_appendllll(all_events, event, 0, WHITENULL_llll);
}

// format (default 1)
// resolution (default 960)
// exportmarkers (default 1)
// voices (default: nil = tutte)

#define TEMPOCHANGES_STEP 1024

t_max_err roll_dowritemidi(t_roll *x, t_symbol *s, long ac, t_atom *av)
{
	long format = 0;
	long num_tracks = 0;
	long time_division = 960;
	double tempo = 60;
	long timesig_num = 4, timesig_den = 4; // unused for now, that's ok
	long i;
	t_llll **this_track_ll, **track_ll = NULL;
	t_rollvoice *this_rollvoice;
	t_marker *this_marker;
	double this_tempo_onset_ms = 0;
	double this_tempo_onset_ticks = 0;
	long num_tempi, found_tempo, found_timesig;
	t_tempochange *tempochanges = NULL;
	unsigned char *buffer = NULL;
	t_llll *arguments = (t_llll *) atom_getobj(av);
	t_symbol *filename_sym = NULL;
	long export_markers = 1;
	long export_barlines = 1;
    long export_divisions = 1;
    long export_subdivisions = 1;
	t_llll *voices_to_write = NULL;
	t_rollvoice *firstvoice = NULL;
	long ok = 1;
	t_llllelem *this_voicenum_elem;
	long num_voices = 0;
	t_ptr_size count = 0;

	llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siiiiiil",
				   _sym_filename, &filename_sym,
				   gensym("exportmarkers"), &export_markers,
				   gensym("exportbarlines"), &export_barlines,
                   gensym("exportdivisions"), &export_divisions,
                   gensym("exportsubdivisions"), &export_subdivisions,
				   gensym("format"), &format,
				   gensym("resolution"), &time_division,
				   gensym("voices"), &voices_to_write);
	
    
    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_destroyelem(arguments->l_head);
    }
    
    lock_general_mutex((t_notation_obj *)x);

	prepare_voices_to_write((t_notation_obj *) x, &voices_to_write);
	
	num_voices = voices_to_write->l_size;
	bach_assert_objerror_goto(x, ok = (num_voices > 0), "No valid voices for export", roll_dowritemidi_error);
	firstvoice = (t_rollvoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&voices_to_write->l_head->l_hatom));
	
	num_tracks = format == 0 ? 1 : num_voices + 1;

	// first, prepare our intermediary structure (guess what? it's an llll!)
	this_track_ll = track_ll = (t_llll **) bach_newptr(num_tracks * sizeof(t_llll *));
	for (i = 0; i < num_tracks; i++)
		track_ll[i] = llll_get();

	// let's put the first tempo as the first element of the midifile
	num_tempi = 0;
	found_tempo = 0;
	for (this_marker = x->r_ob.firstmarker; this_marker && !found_tempo; this_marker = this_marker->next) {
		t_llll *marker_contents_ll = this_marker->content;
		if (marker_contents_ll && this_marker->role == k_MARKER_ROLE_TEMPO && marker_contents_ll->l_size) {
			tempo = get_tempo_from_marker(marker_contents_ll);
			append_tempo_to_midi_export(track_ll[0], tempo, 0);
			found_tempo = 1;
		}
	}

	// if there was no tempo, then put the default tempo 
	if (!found_tempo)
		append_tempo_to_midi_export(track_ll[0], tempo, 0);

    tempochanges = (t_tempochange *) bach_newptr(TEMPOCHANGES_STEP * sizeof(t_tempochange));
    
	tempochange_set(&tempochanges[0], 0, 0, tempo);

	// then put the first time signature as the second element of the midifile
	found_timesig = 0;
	for (this_marker = x->r_ob.firstmarker; this_marker && !found_timesig; this_marker = this_marker->next) {
		t_llll *marker_contents_ll = this_marker->content;
		if (marker_contents_ll && this_marker->role == k_MARKER_ROLE_TIME_SIGNATURE && marker_contents_ll->l_size >= 2) {
			get_timesig_from_marker(marker_contents_ll, &timesig_num, &timesig_den);
			append_timesig_to_midi_export(track_ll[0], timesig_num, timesig_den, 0);
			found_timesig = 1;
		}
	}
	
	// if there was no time signature, put the default time signature
	if (!found_timesig)
		append_timesig_to_midi_export(track_ll[0], timesig_num, timesig_den, 0);
	
	// now set the key signature, taken from the first voice
	append_keysig_to_midi_export(track_ll[0], &firstvoice->v_ob);
	
	// now start running through the markers, in order to set the other tempi and time signatures, and all the markers
	found_timesig = 0;
	for (this_marker = x->r_ob.firstmarker; this_marker; this_marker = this_marker->next) {
		long onset = this_tempo_onset_ticks + (this_marker->position_ms - this_tempo_onset_ms) / 60000. * tempo * time_division + 0.5;
		switch (this_marker->role) {
			case k_MARKER_ROLE_TEMPO: {
				t_llll *marker_contents_ll = this_marker->content;
				if (marker_contents_ll && marker_contents_ll->l_size) {
					// the first tempo has already been inserted
					if (num_tempi > 0) {
						this_tempo_onset_ms = this_marker->position_ms;
						this_tempo_onset_ticks = onset;
						tempo = get_tempo_from_marker(marker_contents_ll);
						append_tempo_to_midi_export(track_ll[0], tempo, onset);
						tempochange_set(&tempochanges[num_tempi], this_tempo_onset_ms, this_tempo_onset_ticks, tempo);
					}
					num_tempi++;
                    if (num_tempi % TEMPOCHANGES_STEP == 0) {
                        tempochanges = (t_tempochange *) bach_resizeptr(tempochanges, (num_tempi + TEMPOCHANGES_STEP) * sizeof(t_tempochange));
                    }
					break;
				}
			}
			case k_MARKER_ROLE_TIME_SIGNATURE: {
				t_llll *marker_contents_ll = this_marker->content;
				if (marker_contents_ll && marker_contents_ll->l_size >= 2) {
					// the first time signature has already been inserted
					if (found_timesig) {
						get_timesig_from_marker(marker_contents_ll, &timesig_num, &timesig_den);
						append_timesig_to_midi_export(track_ll[0], timesig_num, timesig_den, onset);
					}
					found_timesig = 1;
				}
				break;
			}
			case k_MARKER_ROLE_MEASURE_BARLINE: {
				if (export_barlines)
					append_barline_to_midi_export(track_ll[0], onset);
				break;
			}
            case k_MARKER_ROLE_MEASURE_DIVISION: {
                if (export_divisions)
                    append_division_to_midi_export(track_ll[0], onset);
                break;
            }
            case k_MARKER_ROLE_MEASURE_SUBDIVISION: {
                if (export_subdivisions)
                    append_subdivision_to_midi_export(track_ll[0], onset);
                break;
            }
			case k_MARKER_ROLE_NONE: {
                if (export_markers) {
                    t_atom *av = NULL;
                    long ac = llll_deparse(this_marker->r_it.names, &av, 0, 0);
                    t_atomarray *name = atomarray_new_debug(ac, av);
                    append_marker_to_midi_export(track_ll[0], name, onset);
                    bach_freeptr(av);
                }
			}
		}
	}
	
	if (num_tempi == 0)
		num_tempi = 1; // at least the first, default tempo is always set
	
	// dummy values as the array terminator
	tempochange_set(&tempochanges[num_tempi], -1, -1, 0);
	
	// now, one voice after another, insert all the notes
	for (this_voicenum_elem = voices_to_write->l_head; this_voicenum_elem; this_voicenum_elem = this_voicenum_elem->l_next) {
		this_rollvoice = (t_rollvoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&this_voicenum_elem->l_hatom));
		t_chord *this_chord;
		long channel = (this_rollvoice->v_ob.midichannel - 1) % 16;
		long this_tempochange = 0;
		double next_tempochange_ms = tempochanges[1].t_ms;
		this_tempo_onset_ms = 0;
		this_tempo_onset_ticks = 0;
		tempo = tempochanges[0].t_newtempo;
		
		if (format == 1)
			this_track_ll++;
		
		for (this_chord = this_rollvoice->firstchord; this_chord; this_chord = this_chord->next) {
			// for each chord, calculate its onset according to the tempo changes
			if (next_tempochange_ms >= 0 && this_chord->onset >= next_tempochange_ms) {
				this_tempochange++;
				this_tempo_onset_ms = tempochanges[this_tempochange].t_ms;
				this_tempo_onset_ticks = tempochanges[this_tempochange].t_ticks;
				tempo = tempochanges[this_tempochange].t_newtempo;
				next_tempochange_ms = tempochanges[this_tempochange + 1].t_ms;
			}
			long onset = this_tempo_onset_ticks + (this_chord->onset - this_tempo_onset_ms) / 60000. * tempo * time_division + 0.5;
			
			// and now write its notes one by one
			t_note *this_note;
			for (this_note = this_chord->firstnote; this_note; this_note = this_note->next) {
				long pitch = (this_note->midicents + 50.) / 100.;
				long vel = this_note->velocity;
				
				// to calculate the time of the noteoff, we need to take into account the tempo changes happening during the note duration
				long noteoff_tempochange = this_tempochange;
				double noteoff_tempo_onset_ms = this_tempo_onset_ms;
				while (noteoff_tempochange < num_tempi - 1 && tempochanges[noteoff_tempochange + 1].t_ms < noteoff_tempo_onset_ms)
					noteoff_tempochange++;
				
				long noteoff_time = tempochanges[noteoff_tempochange].t_ticks + (this_chord->onset + this_note->duration - tempochanges[noteoff_tempochange].t_ms) 
									/ 60000. * tempochanges[noteoff_tempochange].t_newtempo * time_division;
				append_note_to_midi_export(*this_track_ll, E_NOTEON, pitch, vel, channel, onset);
				append_note_to_midi_export(*this_track_ll, E_NOTEOFF, pitch, 0, channel, noteoff_time);
			}
		}
	}
    
    unlock_general_mutex((t_notation_obj *)x);
	
	// now that we have parsed all the roll into our intermediate data structure, let's convert it into raw MIDI data and write them 
	count = create_raw_midi_data_buffer(track_ll, num_tracks, format, time_division, 0, &buffer);
	//bach_fix_filename_extension(&filename_sym, "mid");
	bach_write_binary_file(filename_sym, "Untitled.mid", 'Midi', &count, buffer);

roll_dowritemidi_error:	
	if (track_ll) {
		for (i = 0, this_track_ll = track_ll; i < num_tracks; this_track_ll++, i++) {
			if (*this_track_ll)
			llll_free(*this_track_ll);
		}
		bach_freeptr(track_ll);
	}
    bach_freeptr(tempochanges);
	if (*buffer)
		bach_freeptr(buffer);
	if (arguments)
		llll_free(arguments);
	return ok ? MAX_ERR_NONE : MAX_ERR_GENERIC;
}


void roll_exportimage(t_roll *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom av;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    atom_setobj(&av, arguments);
    defer(x, (method)notationobj_dowriteimage, s, 1, &av);
}
