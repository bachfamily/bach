/**
    @file
    score_files.c - functions for [bach.score] to deal with files

    by Andrea Agostini
*/

#include "score_files.h"
#ifdef MAC_VERSION
#include "pwd.h"
#endif
#ifdef WIN_VERSION
#include <Shellapi.h>
#include <process.h>
#endif


void score_doread(t_score *x, t_symbol *s, long argc, t_atom *argv);



t_max_err score_dowritemidi(t_score *x, t_symbol *s, long ac, t_atom *av);
t_max_err score_dowritelilypond(t_score *x, t_symbol *s, long ac, t_atom *av);
t_max_err score_dowritelilypond_pdf(t_score *x, t_symbol *s, long ac, t_atom *av);

long rat2ticks(const t_rational *pos, long time_division);
t_rational get_play_durations_between_timepoints(t_score *x, t_scorevoice *voice, t_timepoint *tp1, t_timepoint *tp2);
t_rational normalize_timepoint(t_score *x, t_timepoint *tp);
char strip_cresc_decresc(char *text);





// **********************************************
// import-export
// **********************************************





void score_read_singlesymbol(t_score *x, t_symbol *s, long argc, t_atom *argv)
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
        defer((t_object *) x, (method) score_doread, s, 1, &a);
    }
}

void score_read(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom a;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    //llll_retain(arguments);
    atom_setobj(&a, arguments);
    defer((t_object *) x, (method) score_doread, s, 1, &a);
}

void score_doread(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = (t_llll *) atom_getobj(argv);
    t_symbol *filename_sym = NULL;
    t_filehandle fh = NULL;
    t_fourcc outtype = 0;
    t_fourcc file_types[] = {'TEXT', 'LLLL', 'MXML', 'CXML'};
    t_llll *score_ll = NULL;
    t_ptr_size size;
    e_undo_operations undo_op = k_UNDO_OP_UNKNOWN;
    short path;
    char filename[2048];
    t_dictionary *dict = NULL;
    
    long parenthesizedquartertones = 0;
    long lyricsslot = x->r_ob.link_lyrics_to_slot;
    long noteheadslot = x->r_ob.link_notehead_to_slot;
    long articulationsslot = x->r_ob.link_articulations_to_slot;
    long dynamicsslot = x->r_ob.link_dynamics_to_slot;
    long directionsslot = x->r_ob.link_annotation_to_slot;
    long import_lyrics = 1, import_noteheads = 1, import_articulations = 1, import_dynamics = 1, import_directions = 1;

    llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siiiiiiiiii",
                                         gensym("filename"), &filename_sym,
                                         gensym("parenthesizedquartertones"), &parenthesizedquartertones,
                                         gensym("importlyrics"), &lyricsslot,
                                         gensym("importnoteheads"), &noteheadslot,
                                         gensym("importarticulations"), &articulationsslot,
                                         gensym("lyrics"), &import_lyrics,
                                         gensym("noteheads"), &import_noteheads,
                                         gensym("articulations"), &import_articulations,
                                         gensym("dynamics"), &import_dynamics,
                                         gensym("annotations"), &import_directions,
                                         gensym("directionsslot"), &directionsslot);
    
    if (!import_lyrics)
        lyricsslot = 0;
    if (!import_noteheads)
        noteheadslot = 0;
    if (!import_articulations)
        articulationsslot = 0;
    if (!import_dynamics)
        dynamicsslot = 0;
    if (!import_directions)
        directionsslot = 0;

    if (arguments->l_size >= 1 && hatom_gettype(&arguments->l_head->l_hatom) == H_SYM) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        llll_behead(arguments);
    }
    

    if (bach_openfile_for_read((t_object *) x, filename_sym, &path, file_types, 4, &outtype, filename) != MAX_ERR_NONE) {
        object_error((t_object *) x, "Can't open file");
        goto score_doread_error_dontclose;
    }
    
    if (*filename == 0)
        goto score_doread_error_dontclose;

    if (dictionary_read(filename, path, &dict) == MAX_ERR_NONE) {
        score_ll = llll_retrieve_from_dictionary(dict, "data");
        object_free(dict);
        undo_op = k_UNDO_OP_READ_SCORE;
    } else {
        if (bach_readfile((t_object *) x, filename, path, &fh) != MAX_ERR_NONE)
            goto score_doread_error_dontclose;
        sysfile_geteof(fh, &size);
        char* buffer = (char *) bach_newptr(size + 2);
        buffer[0] = 0;
        
        // let's try to guess if it's xml
        sysfile_read(fh, &size, buffer);
        if (size > 4 && !memcmp(buffer, "PK\x03\x04", 4)) {

#ifdef MAC_VERSION
            sysfile_close(fh);
            bach_freeptr(buffer);
            //system("mkdir -p \"$HOME/Library/Application Support/bach/cache\"");
            passwd* pw = getpwuid(getuid());
            std::string home = pw->pw_dir;
            std::string dq = "\"";
            std::string cache = home + "/Library/Application Support/bach/cache";
            std::string decompressed = cache + "/decompressed";
            std::string tempmxl = cache + "/tempmxl.mxl";
            
            std::string rmDecompressed = "rm -rf " + dq + decompressed + dq;
            system(rmDecompressed.c_str());
            
            std::string mkdir = "mkdir -p " + dq + decompressed + dq;
            system(mkdir.c_str());
            
            std::string rmTempxml = "rm -f " + dq + tempmxl + dq;
            system(rmTempxml.c_str());


            char abspath[4096];
            path_toabsolutesystempath(path, filename, abspath);
            
            std::string cp = "cp " + dq + abspath + dq + " " + dq + tempmxl + dq;
            system(cp.c_str());
            
            std::string unzip = "unzip " + dq + tempmxl + dq + " -d " + dq + decompressed + dq;
            system(unzip.c_str());

            std::string container = decompressed + "/META-INF/container.xml";
            
            filename_sym = gensym(container.c_str());
            
            if (bach_openfile_for_read((t_object *) x, filename_sym, &path, file_types, 2, &outtype, filename) != MAX_ERR_NONE) {
                object_error((t_object *) x, "Can't open file");
                goto score_doread_error_dontclose;
            }
            
            if (*filename == 0)
                goto score_doread_error_dontclose;
            
            if (bach_readfile((t_object *) x, filename, path, &fh) != MAX_ERR_NONE)
                goto score_doread_error_dontclose;
            sysfile_geteof(fh, &size);
            buffer = (char *) bach_newptr(size + 2);
            buffer[0] = 0;
            sysfile_read(fh, &size, buffer);
            sysfile_close(fh);
            std::string rootfilepath = decompressed + "/" + xml_mxl_find_rootfile(buffer);
            bach_freeptr(buffer);
            
            filename_sym = gensym(rootfilepath.c_str());
            if (bach_openfile_for_read((t_object *) x, filename_sym, &path, file_types, 2, &outtype, filename) != MAX_ERR_NONE) {
                object_error((t_object *) x, "Can't open file");
                goto score_doread_error_dontclose;
            }
            
            if (*filename == 0)
                goto score_doread_error_dontclose;
            
            if (bach_readfile((t_object *) x, filename, path, &fh) != MAX_ERR_NONE)
                goto score_doread_error_dontclose;
            
            sysfile_geteof(fh, &size);
            buffer = (char *) bach_newptr(size + 2);
            buffer[0] = 0;
            sysfile_read(fh, &size, buffer);
            sysfile_close(fh);
            system(rmDecompressed.c_str());
            system(rmTempxml.c_str());

#endif
            
        }
        
        if ((size > 5 && !memcmp(buffer, "<?xml", 5)) || // plain text
            (size > 8 && !memcmp(buffer, "\xef\xbb\xbf<?xml", 8)) || // utf-8
            (size > 10 && (!memcmp(buffer, "\xff\xfe\x3c\x00\x3f\x00\x78\x00\x6d\x00", 10) || // utf-16 little-endian
                            !memcmp(buffer, "\xfe\xff\x00\x3c\x00\x3f\x00\x78\x6d\x00", 10)))) { // utf-16 big-endian
            score_ll = score_readxmlbuffer(x, buffer, parenthesizedquartertones, lyricsslot, noteheadslot, articulationsslot, dynamicsslot, directionsslot);
            undo_op = k_UNDO_OP_IMPORT_XML_SCORE;
        } else {
            score_ll = llll_readbuffer((t_object *) x, 0, buffer, size);
        }
        bach_freeptr(buffer);
    }
    if (score_ll) {
        set_score_from_llll_from_read(x, score_ll);
        llll_free(score_ll);
        handle_rebuild_done((t_notation_obj *) x);
        handle_change((t_notation_obj *)x, k_CHANGED_STANDARD_UNDO_MARKER, undo_op);
    } else {
        object_error((t_object *) x, "File doesn't contain a score");
        goto score_doread_error_dontclose;
    }
    
score_doread_error_dontclose:
    llll_free(arguments);
    return;
}

void score_write(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *score_as_llll;
    t_symbol *filename = NULL;
    if ((argc >= 1) && (atom_gettype(argv) == A_SYM))
        filename = atom_getsym(argv);
    score_as_llll = get_score_values_as_llll(x, k_CONSIDER_FOR_SAVING, k_HEADER_ALL, x->r_ob.write_trees, x->r_ob.write_trees && x->r_ob.output_and_save_level_types, true, false); // we save the clefs as well
    llll_writenative((t_object *) x, filename, score_as_llll);
} 

void score_writetxt(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
    t_llll *score_as_llll = get_score_values_as_llll(x, k_CONSIDER_FOR_SAVING, k_HEADER_ALL, x->r_ob.write_trees, x->r_ob.write_trees && x->r_ob.output_and_save_level_types, true, false); // we save the clefs as well
    llll_writetxt((t_object *) x, score_as_llll, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_SMART, LLLL_TB_SMART);
}

void score_exportom(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
    t_llll *score_as_llll_for_om = get_score_values_as_llll(x, k_CONSIDER_FOR_EXPORT_OM, k_HEADER_ALL, false, false, true, false);
    llll_writetxt((t_object *) x, score_as_llll_for_om, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_DOUBLE_QUOTE, LLLL_TB_SPECIAL);
}

void score_exportpwgl(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, argc, argv, LLLL_PARSE_CLONE);
    t_llll *score_as_llll_for_pwgl = get_score_values_as_llll_for_pwgl(x);
    llll_writetxt((t_object *) x, score_as_llll_for_pwgl, arguments, BACH_DEFAULT_MAXDECIMALS, 0, "\t", -1, LLLL_T_NONE, LLLL_TE_DOUBLE_QUOTE, LLLL_TB_SPECIAL);
}

void score_exportmidi(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom av;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    atom_setobj(&av, arguments);
    defer(x, (method) score_dowritemidi, s, 1, &av);
}


void score_exportlilypond(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom av;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    atom_setobj(&av, arguments);
    defer(x, (method) score_dowritelilypond, s, 1, &av);
}

void score_exportlilypond_pdf(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom av;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    atom_setobj(&av, arguments);
    defer(x, (method) score_dowritelilypond_pdf, s, 1, &av);
}


// av:
// long: format

long rat2ticks(const t_rational *pos, long time_division)
{
    return pos->r_num * 4. / pos->r_den * time_division + 0.5;
}

t_rational ticks2rat(long ticks, long time_division)
{
    return genrat(ticks, 4 * time_division);
}

t_max_err score_dowritemidi(t_score *x, t_symbol *s, long ac, t_atom *av)
{
    long format = 0;
    long num_tracks;
    long time_division = 960;
    double tempo = 60;
    long tempo_interp_sampling_interval = 240;
    long timesig_num = 4, timesig_den = 4; // unused for now, that's ok
    long i;
    long voice_num;
    t_llll **this_track_ll, **track_ll;
    t_scorevoice *this_scorevoice;
    t_marker *this_marker;
    unsigned char *buffer = NULL;
    long first_onset = 0;
    long export_markers = 1;
    t_llll *voices_to_write = NULL;
    t_scorevoice *firstvoice = NULL;
    t_symbol *filename_sym = NULL;
    long ok = 1;
    t_llllelem *this_voicenum_elem;
    long num_voices = 0;
    t_llll *arguments = (t_llll *) atom_getobj(av);
    t_ptr_size count = 0;
    t_scorevoice *longest_voice = NULL;
    long longest_voice_num = 0;
    t_timepoint longest_voice_start;

    
    llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "siiiil",
                   _sym_filename, &filename_sym,
                   gensym("exportmarkers"), &export_markers,
                   gensym("format"), &format,
                   gensym("resolution"), &time_division,
                   gensym("temporampsamplingrate"), &tempo_interp_sampling_interval,
                   gensym("voices"), &voices_to_write);
    
    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_behead(arguments);
    }
    
    lock_general_mutex((t_notation_obj *)x);
    
    prepare_voices_to_write((t_notation_obj *) x, &voices_to_write);
    num_voices = voices_to_write->l_size;
    bach_assert_objerror_goto(x, ok = (num_voices > 0), "No valid voices for export", score_dowritemidi_error);
    firstvoice = (t_scorevoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&voices_to_write->l_head->l_hatom));
    num_tracks = format == 0 ? 1 : num_voices + 1;
    
    // first, prepare our intermediary structure (guess what? it's an llll!)
    this_track_ll = track_ll = (t_llll **) bach_newptr(num_tracks * sizeof(t_llll *));
    for (i = 0; i < num_tracks; i++)
        track_ll[i] = llll_get();
    
    // now set the key signature, taken from the first voice
    append_keysig_to_midi_export(track_ll[0], &firstvoice->v_ob);
    
    // let's do the markers
    longest_voice = get_longest_scorevoice(x);
    longest_voice_num = longest_voice->v_ob.number;
    longest_voice_start = build_timepoint_with_voice(0, long2rat(0), longest_voice_num);

    for (this_marker = x->r_ob.firstmarker; this_marker; this_marker = this_marker->next) {
        t_timepoint this_marker_tp, this_voice_start;
        t_scorevoice *this_marker_voice;
        if (this_marker->attach_to == k_MARKER_ATTACH_TO_MS) { // if the marker is attached to ms, we transform the ms in symbolic duration
            this_marker_tp = ms_to_timepoint((t_notation_obj *) x, this_marker->position_ms, longest_voice_num, k_MS_TO_TP_RETURN_INTERPOLATION);
            this_marker_voice = longest_voice;
            this_voice_start = longest_voice_start;
        } else {
            t_measure *this_marker_measure = (t_measure *) shashtable_retrieve(x->r_ob.IDtable, this_marker->measure_attach_ID);
            this_marker_voice = this_marker_measure->voiceparent;
            long this_marker_voicenum = this_marker_voice->v_ob.number;
            this_voice_start = build_timepoint_with_voice(0, long2rat(0), this_marker_voicenum);
            this_marker_tp = build_timepoint_with_voice(this_marker_measure->measure_number, this_marker->r_sym_pim_attach, this_marker_voicenum);
        }
        t_rational this_marker_pos_rat = get_sym_durations_between_timepoints(this_marker_voice, this_voice_start, this_marker_tp);

        t_atom *av = NULL;
        long ac = llll_deparse(this_marker->r_it.names, &av, 0, 0);
        t_atomarray *name = atomarray_new_debug(ac, av);
        append_marker_to_midi_export(track_ll[0], name, rat2ticks(&this_marker_pos_rat, time_division));
        bach_freeptr(av);
    }
    
    // now, one voice after another, insert all the notes
    for (this_voicenum_elem = voices_to_write->l_head; this_voicenum_elem; this_voicenum_elem = this_voicenum_elem->l_next) {
        voice_num = hatom_getlong(&this_voicenum_elem->l_hatom);
        this_scorevoice = (t_scorevoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&this_voicenum_elem->l_hatom));
        t_measure *this_measure;
        t_chord *this_chord;
        long channel = this_scorevoice->v_ob.midichannel % 16 - 1;
        t_timepoint voice_start_tp;
        
        if (format == 1)
            this_track_ll++;
        
        voice_start_tp = build_timepoint_with_voice(0, long2rat(0), voice_num);

        for (this_measure = this_scorevoice->firstmeasure; this_measure; this_measure = this_measure->next) {
            long this_measure_number = this_measure->measure_number; // 0-based
            t_timepoint measure_start_tp;
            t_rational measure_start_rat;
            long new_ts_num = this_measure->timesignature.numerator;
            long new_ts_den = this_measure->timesignature.denominator;
            t_tempo *this_tempo = this_measure->firsttempo;
            
            measure_start_tp = build_timepoint_with_voice(this_measure_number, long2rat(0), voice_num);
            measure_start_rat = get_sym_durations_between_timepoints(this_scorevoice, voice_start_tp, measure_start_tp);
            
            if ((this_measure_number == 0 && voice_num == 0) || new_ts_num != timesig_num || new_ts_den != timesig_den) {
                timesig_num = new_ts_num;
                timesig_den = new_ts_den;
                append_timesig_to_midi_export(track_ll[0], timesig_num, timesig_den, rat2ticks(&measure_start_rat, time_division));
            }
            
            // if there is no tempo at the beginning of the score, start with the default tempo 
            if (voice_num == 0 && this_measure_number == 0 && (this_tempo == NULL || this_tempo->changepoint.r_num != 0))
                append_tempo_to_midi_export(track_ll[0], tempo, 0);
            
            // set all the tempi in this measure, and all the tempo interpolations starting from it
            for ( ; this_tempo; this_tempo = this_tempo->next) {
                t_rational this_tempo_onset_rat = rat_rat_sum(measure_start_rat, this_tempo->changepoint);
                long this_tempo_onset_ticks = rat2ticks(&this_tempo_onset_rat, time_division);
                double new_tempo = rat2double(this_tempo->tempo_value);
                // if this tempo is different from the previous one, or we are at the beginning of the score, insert it
                if (tempo != new_tempo || (voice_num == 0 && this_measure_number == 0)) {
                    append_tempo_to_midi_export(track_ll[0], new_tempo, this_tempo_onset_ticks);
                    tempo = new_tempo;
                }
                // if it's a tempo ramp
                if (this_tempo->interpolation_type) {
                    t_tempo *next_tempo = tempo_get_next(this_tempo);
                    double next_tempo_bpm = rat2double(next_tempo->tempo_value);
                    if (next_tempo_bpm != tempo) {
                        t_measure *next_tempo_measure = next_tempo->owner;
                        t_timepoint this_tempo_onset_tp = build_timepoint_with_voice(this_measure_number, this_tempo->changepoint, voice_num);
                        t_timepoint next_tempo_onset_tp = build_timepoint_with_voice(next_tempo_measure->measure_number, next_tempo->changepoint, voice_num);
                        t_rational next_tempo_onset_rat = get_sym_durations_between_timepoints(this_scorevoice, voice_start_tp, next_tempo_onset_tp);
                        long next_tempo_onset_ticks = rat2ticks(&next_tempo_onset_rat, time_division);
                        t_rational interp_dur_rat = get_sym_durations_between_timepoints(this_scorevoice, this_tempo_onset_tp, next_tempo_onset_tp);
                        long interp_dur_ticks = rat2ticks(&interp_dur_rat, time_division);
                        long interp_dur_ticks_div2 = interp_dur_ticks / 2;
                        long this_tempo_sample;
                        
                        for (this_tempo_sample = this_tempo_onset_ticks; 
                             this_tempo_sample <= next_tempo_onset_ticks; 
                             this_tempo_sample += tempo_interp_sampling_interval) {
                            long this_tempo_sampling_point;
                            if (this_tempo_sample + interp_dur_ticks <= next_tempo_onset_ticks)
                                this_tempo_sampling_point = this_tempo_sample + interp_dur_ticks_div2;
                            else
                                this_tempo_sampling_point = (next_tempo_onset_ticks - this_tempo_sample) / 2;
                            double this_step_bpm = 1. / (((1. / tempo) * ((this_tempo_sample - this_tempo_onset_ticks) / interp_dur_ticks)) +
                                                         ((1. / next_tempo_bpm) * (next_tempo_onset_ticks - this_tempo_sample) / interp_dur_ticks));
                            append_tempo_to_midi_export(track_ll[0], this_step_bpm, this_tempo_sample);
                        }
                    }
                }
            }

            for (this_chord = this_measure->firstchord; this_chord; this_chord = this_chord->next) {
                
                t_rational this_chord_onset_rat = rat_rat_sum(measure_start_rat, this_chord->play_r_sym_onset);
                t_rational this_chord_duration_rat = this_chord->play_r_sym_duration;

                // and now write its notes one by one
                t_note *this_note;
                for (this_note = this_chord->firstnote; this_note; this_note = this_note->next) {
                    if (this_note->tie_from)
                        continue;
                    long pitch = (this_note->midicents + 50.) / 100.;
                    long vel = this_note->velocity;
                    t_rational noteoff_rat;
                    if (this_note->tie_to) {
                        t_note *last = note_get_last_in_tieseq(this_note);
                        t_chord *last_chord = last->parent;
                        t_timepoint start_tp, end_tp;
                        start_tp = build_timepoint_with_voice(this_measure_number, this_chord->play_r_sym_onset, voice_num);
//                        end_tp = build_timepoint_with_voice(last_chord->parent->measure_number, last_chord->play_r_sym_onset, voice_num);
                        end_tp = build_timepoint_with_voice(last_chord->parent->measure_number,
                                                            rat_rat_sum(last_chord->play_r_sym_onset, last_chord->play_r_sym_duration),
                                                            voice_num);
                        noteoff_rat = rat_rat_sum(this_chord_onset_rat, get_play_durations_between_timepoints(x, this_scorevoice, &start_tp, &end_tp));
                    } else
                        noteoff_rat = rat_rat_sum(this_chord_onset_rat, this_chord_duration_rat);

                    long on_ticks = rat2ticks(&this_chord_onset_rat, time_division);
                    long off_ticks = rat2ticks(&noteoff_rat, time_division);
                    if (off_ticks > on_ticks + 1)
                        off_ticks --;
                    if (on_ticks < first_onset)
                        first_onset = on_ticks;
                    append_note_to_midi_export(*this_track_ll, E_NOTEON, pitch, vel, channel, on_ticks);
                    append_note_to_midi_export(*this_track_ll, E_NOTEOFF, pitch, 0, channel, off_ticks);
                }
            }
        }
    }
    
    unlock_general_mutex((t_notation_obj *)x);
    
    // if there are notes before 0, then we have to fix up some stuff
    if (first_onset < 0) {
        // go get the key signature and put it at the beginning
        t_llllelem *elem;
        for (elem = track_ll[0]->l_head; elem; elem = elem->l_next) {
            t_llll *event_ll = hatom_getllll(&elem->l_hatom);
            long type = hatom_getlong(&event_ll->l_head->l_hatom);
            if (type == E_KEYSIG) {
                hatom_setlong(&event_ll->l_head->l_next->l_hatom, first_onset);
                break;
            }
        }
        
        // then get the first tempo, if it was at 0, and put it at the beginning
        for (elem = track_ll[0]->l_head; elem; elem = elem->l_next) {
            t_llll *event_ll = hatom_getllll(&elem->l_hatom);
            long type = hatom_getlong(&event_ll->l_head->l_hatom);
            if (type == E_TEMPO) {
                t_atom_long *time = &event_ll->l_head->l_next->l_hatom.h_w.w_long;
                if (*time == 0)
                    *time = first_onset;
                break;
            }
        }
        
        // then add a first time signature at the very beginning, accounting for the whole duration of the notes before 0
        t_rational grace_timesig = ticks2rat(-first_onset, time_division);
        append_timesig_to_midi_export(track_ll[0], grace_timesig.r_num, grace_timesig.r_den, first_onset);
    }
    
    // now that we have parsed all the roll into our intermediate data structure, let's convert it into raw MIDI data and write them 
    count = create_raw_midi_data_buffer(track_ll, num_tracks, format, time_division, first_onset, &buffer);
    //bach_fix_filename_extension(&filename_sym, "mid");
    bach_write_binary_file(filename_sym, "Untitled.mid", 'Midi', &count, buffer);
    
    if (track_ll) {
        for (i = 0, this_track_ll = track_ll; i < num_tracks; this_track_ll++, i++) {
            if (*this_track_ll)
                llll_free(*this_track_ll);
        }
        bach_freeptr(track_ll);
    }
score_dowritemidi_error:
    if (*buffer)
        bach_freeptr(buffer);
    if (arguments)
        llll_free(arguments);
    return ok ? MAX_ERR_NONE : MAX_ERR_GENERIC;
}

t_rational get_play_durations_between_timepoints(t_score *x, t_scorevoice *voice, t_timepoint *tp1, t_timepoint *tp2) 
{
    t_rational rem1, rem2, result;
    rem1 = normalize_timepoint(x, tp1);
    rem2 = normalize_timepoint(x, tp2);
    result = get_sym_durations_between_timepoints(voice, *tp1, *tp2);
    result = rat_rat_sum(result, rem1);
    result = rat_rat_diff(result, rem2);
    return result;
}

t_rational normalize_timepoint(t_score *x, t_timepoint *tp)
{
    if (tp->pt_in_measure.r_num < 0) {
        if (tp->measure_num > 0) {
            tp->measure_num--;
            tp->pt_in_measure = rat_rat_sum(measure_get_sym_duration(nth_measure_of_scorevoice(nth_scorevoice(x, tp->voice_num), tp->measure_num)), tp->pt_in_measure);
            return long2rat(0);
        } else {
            t_rational remainder = rat_opp(tp->pt_in_measure);
            tp->pt_in_measure = long2rat(0);
            return remainder;
        }
    }
    return long2rat(0);
}


char strip_cresc_decresc(char *text)
{
    long i, len = strlen(text);
    char res = 0;
    
    // we return crescendo (1) or diminuendo (-1) only if the last character is "<" or ">"
    // id est: we don't account for intermediate crescendi such as "f<ff>p<", I have no idea of how they might be properly handled in musicXML.
    // For instance: "f<ff>p" will return 0, "f<ff>p>" will return -1
    // In both cases, we'll trim the string TO THE FIRST found "<" or ">": both strings will be trimmed to "f".
    
    if (len > 0) {
        if (text[len - 1] == '<')
            res = -1;
        else if (text[len - 1] == '>')
            res = 1;
    }

    for (i = 0; i < len; i++) {
        if (text[i] == '<' || text[i] == '>') {
            text[i] = 0;
            break;
        }
    }
    return res;
}

void tolower_str(char *str) 
{
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

long clef_number_to_lilypond_buf(t_notation_obj *r_ob, long clef, char **buf)
{
    if (!*buf)
        *buf = (char *)bach_newptr(100 * sizeof(char));
    
    t_symbol *clef_as_sym = clef_number_to_clef_symbol(r_ob, clef); 
    if (clef_as_sym == _llllobj_sym_Barytone) 
        clef_as_sym = gensym("varbarytone");
    else if (clef_as_sym == _llllobj_sym_F || clef_as_sym == _llllobj_sym_FF || clef_as_sym == _llllobj_sym_FFG)
        clef_as_sym = gensym("bass");
    else if (clef_as_sym == _llllobj_sym_G || clef_as_sym == _llllobj_sym_GG || clef_as_sym == _llllobj_sym_FGG || clef_as_sym == _llllobj_sym_FFGG)
        clef_as_sym = gensym("treble");
    else if (clef_as_sym == _llllobj_sym_G8)
        clef_as_sym = gensym("\"treble^8\"");
    else if (clef_as_sym == _llllobj_sym_G15)
        clef_as_sym = gensym("\"treble^15\"");
    else if (clef_as_sym == _llllobj_sym_F8)
        clef_as_sym = gensym("\"bass_8\"");
    else if (clef_as_sym == _llllobj_sym_F15)
        clef_as_sym = gensym("\"bass_15\"");
    
    char *clef_buf = strdup(clef_as_sym->s_name);
    tolower_str(clef_buf);
    long count = sprintf(*buf, "\t\t\t\\clef %s\r\n", clef_buf);
    free(clef_buf);
    return count;
}


char *note_and_acc_to_lilypond_buf(t_notation_obj *r_ob, t_note *note)
{
    char *buf = (char *)bach_newptr((4 + 4 * note->num_accidentals + 20) * sizeof(char));
    long cur = 0;
    long step = midicents2diatonicstep(note_get_screen_midicents(note));
    
    // note
    switch (step) {
        case 0:
            buf[cur++] = 'c';
            break;
        case 1:
            buf[cur++] = 'd';
            break;
        case 2:
            buf[cur++] = 'e';
            break;
        case 3:
            buf[cur++] = 'f';
            break;
        case 4:
            buf[cur++] = 'g';
            break;
        case 5:
            buf[cur++] = 'a';
            break;
        case 6:
            buf[cur++] = 'b';
            break;
        default:
            buf[cur++] = 'c';
            break;
    }
    
    // accidental
    long i;
    t_rational note_screen_accidental = note_get_screen_accidental(note);
    if (rat_rat_cmp(note_screen_accidental, genrat(0, 1)) == 0){
        // most common case, nothing to do
    } else if (rat_rat_cmp(note_screen_accidental, genrat(1, 4)) == 0){
        buf[cur++] = 'i';
        buf[cur++] = 'h';
    } else if (rat_rat_cmp(note_screen_accidental, genrat(1, 2)) == 0){
        buf[cur++] = 'i';
        buf[cur++] = 's';
    } else if (rat_rat_cmp(note_screen_accidental, genrat(3, 4)) == 0){
        buf[cur++] = 'i';
        buf[cur++] = 's';
        buf[cur++] = 'i';
        buf[cur++] = 'h';
    } else if (rat_rat_cmp(note_screen_accidental, genrat(1, 1)) == 0){
        buf[cur++] = 'i';
        buf[cur++] = 's';
        buf[cur++] = 'i';
        buf[cur++] = 's';
    } else if (rat_rat_cmp(note_screen_accidental, genrat(-1, 4)) == 0){
        buf[cur++] = 'e';
        buf[cur++] = 'h';
    } else if (rat_rat_cmp(note_screen_accidental, genrat(-1, 2)) == 0){
        buf[cur++] = 'e';
        buf[cur++] = 's';
    } else if (rat_rat_cmp(note_screen_accidental, genrat(-3, 4)) == 0){
        buf[cur++] = 'e';
        buf[cur++] = 's';
        buf[cur++] = 'e';
        buf[cur++] = 'h';
    } else if (rat_rat_cmp(note_screen_accidental, genrat(-1, 1)) == 0){
        buf[cur++] = 'e';
        buf[cur++] = 's';
        buf[cur++] = 'e';
        buf[cur++] = 's';
    }
    
    // octaviation
    long temp = note_get_screen_midicents(note) / 1200 - 4;
    if (temp > 0) {
        for (i = 1; i <= temp; i++)
            buf[cur++] = '\'';
    } else if (temp < 0) {
        for (i = 1; i <= -temp; i++)
            buf[cur++] = ',';
    }
    
    buf[cur] = 0;
    return buf;
}

long articulation_to_lilypond_buf(t_notation_obj *r_ob, long articulation_ID, char **buf){
    if (!(*buf))
        *buf = (char *)bach_newptr(40 * sizeof(char));
    
    (*buf)[0] = 0;
    switch (articulation_ID) {
        case k_ARTICULATION_STACCATO: sprintf(*buf, "\\staccato"); break;
        case k_ARTICULATION_ACCENT: sprintf(*buf, "\\accent"); break;
        case k_ARTICULATION_PORTATO: sprintf(*buf, "\\tenuto"); break;
        case k_ARTICULATION_TRILL: sprintf(*buf, "\\trill"); break;
        case k_ARTICULATION_TRILL_NATURAL: sprintf(*buf, "\\trillNatural"); break;
        case k_ARTICULATION_TRILL_FLAT: sprintf(*buf, "\\trillFlat"); break;
        case k_ARTICULATION_TRILL_SHARP: sprintf(*buf, "\\trillSharp"); break;
        case k_ARTICULATION_FERMATA: sprintf(*buf, "\\fermata"); break;
        case k_ARTICULATION_ACCENT_STACCATO: sprintf(*buf, "\\staccato\\accent"); break;
        case k_ARTICULATION_ACCENT_PORTATO: sprintf(*buf, "\\tenuto\\accent"); break;
        case k_ARTICULATION_PORTATO_STACCATO: sprintf(*buf, "\\portato"); break;
        case k_ARTICULATION_STACCATISSIMO: sprintf(*buf, "\\staccatissimo"); break;
        case k_ARTICULATION_MARTELLATO: sprintf(*buf, "\\marcato"); break;
        case k_ARTICULATION_MARTELLATO_STACCATO: sprintf(*buf, "\\staccato\\marcato"); break;
        case k_ARTICULATION_MORDENT_UP: sprintf(*buf, "\\prall"); break;
        case k_ARTICULATION_MORDENT_DOWN: sprintf(*buf, "\\mordent"); break;
        case k_ARTICULATION_DOUBLE_MORDENT: sprintf(*buf, "\\prallprall"); break;
        case k_ARTICULATION_GRUPPETTO: sprintf(*buf, "\\turn"); break;
        case k_ARTICULATION_HARMONIC: sprintf(*buf, "\\flageolet"); break;
        case k_ARTICULATION_LEFT_HAND_PIZZICATO: sprintf(*buf, "\\stopped"); break;
        case k_ARTICULATION_BOWING_UP: sprintf(*buf, "\\upbow"); break;
        case k_ARTICULATION_BOWING_DOWN: sprintf(*buf, "\\downbow"); break;
        case k_ARTICULATION_TREMOLO3: sprintf(*buf, ":32"); break;
        case k_ARTICULATION_TREMOLO2: sprintf(*buf, ":16"); break;
        case k_ARTICULATION_TREMOLO1: sprintf(*buf, ":8"); break;    
    }
    
    return strlen(*buf);
}


long chord_to_lilypond_buf(t_notation_obj *r_ob, t_chord *ch, char **buf)
{
    long cur = 0, j;
    char is_all_chord_tie_to_next = chord_is_all_tied_to(r_ob, ch, false, NULL);
    
    // estimating (upper bound!) on length of the string
    long estimated_buffer_length = 0;
    t_note *note;
    
    estimated_buffer_length = 10; // say, initial security pad, or for rests
    estimated_buffer_length += (4 + 4 + 20) * ch->num_notes; // name and space and possible tie + accidentals + octaviation (secured) for each note 
    estimated_buffer_length += 2; // in case we have a chord
    estimated_buffer_length += 20; // chars needed to write the duration (uuuupper bound)
    estimated_buffer_length += ch->num_dots; // number of dots
    for (note = ch->firstnote; note; note = note->next) 
        estimated_buffer_length += 40 * note->num_articulations;
    estimated_buffer_length += 40 * ch->num_articulations;

    if (!*buf)
        *buf = (char *)bach_newptr(estimated_buffer_length * sizeof(char));
    
    (*buf)[cur++] = '\t';
    (*buf)[cur++] = '\t';
    (*buf)[cur++] = '\t';
    
    if (ch->num_notes == 0) 
        (*buf)[cur++] = 'r';
    else if (ch->num_notes > 1)
        (*buf)[cur++] = '<';
    
    for (note = ch->firstnote; note; note = note->next) {
        // adding note name
        char *note_buf = note_and_acc_to_lilypond_buf(r_ob, note);
        long len_note_buf = strlen(note_buf);
        strncpy((*buf) + cur, note_buf, len_note_buf);
        cur += len_note_buf;
        bach_freeptr(note_buf);
        
        // single tie for note
        if (!is_all_chord_tie_to_next && note->tie_to && note->tie_to != WHITENULL)
            (*buf)[cur++] = '~';
        
        if (ch->num_notes > 1) {
            for (j = 0; j < note->num_articulations; j++) {
                char *buf_articulation = NULL;
                long len_art = articulation_to_lilypond_buf(r_ob, note->articulation[j].articulation_ID, &buf_articulation);
                strncpy((*buf) + cur, note_buf, len_art);
                cur += len_art;
                bach_freeptr(buf_articulation);
            }
        }
                
        if (ch->num_notes > 1 && note->next)
            (*buf)[cur++] = ' ';
    }

    if (ch->num_notes > 1)
        (*buf)[cur++] = '>';

    // adding duration
    char dur_buf[20];
    if (rat_rat_cmp(ch->figure, genrat(2, 1)) == 0)
        snprintf_zero(dur_buf, 20, "\\breve");
    else
        snprintf_zero(dur_buf, 20, "%ld", ch->figure.r_den);
    long len_dur_buf = strlen(dur_buf);
    strncpy((*buf) + cur, dur_buf, len_dur_buf);
    cur += len_dur_buf;
    
    // adding dots
    long i; 
    for (i = 0; i < ch->num_dots; i++)
        (*buf)[cur++] = '.';

    // articulations
    if (ch->num_notes == 1) {
        for (j = 0; j < ch->firstnote->num_articulations; j++) {
            char *buf_articulation = NULL;
            long len_art = articulation_to_lilypond_buf(r_ob, ch->firstnote->articulation[j].articulation_ID, &buf_articulation);
            strncpy((*buf) + cur, buf_articulation, len_art);
            bach_freeptr(buf_articulation);
            cur += len_art;
        }
    }
    for (j = 0; j < ch->num_articulations; j++) {
        char *buf_articulation = NULL;
        long len_art = articulation_to_lilypond_buf(r_ob, ch->articulation[j].articulation_ID, &buf_articulation);
        strncpy((*buf) + cur, buf_articulation, len_art);
        bach_freeptr(buf_articulation);
        cur += len_art;
    }    
    
    // tie
    if (is_all_chord_tie_to_next)
        (*buf)[cur++] = '~';
    
    (*buf)[cur++] = '\r';
    (*buf)[cur++] = '\n';
    (*buf)[cur] = 0;
        
    return cur;
}



void key_to_note_name_lilypond_buf(t_notation_obj *r_ob, long key, char **buf)
{
    if (!*buf)
        *buf = (char *)bach_newptr(10 * sizeof(char));
    switch (key) {
        case 0: sprintf(*buf, "c"); break;
        case 1: sprintf(*buf, "g"); break;
        case 2: sprintf(*buf, "d"); break;
        case 3: sprintf(*buf, "a"); break;
        case 4: sprintf(*buf, "e"); break;
        case 5: sprintf(*buf, "b"); break;
        case 6: sprintf(*buf, "fis"); break;
        case 7: sprintf(*buf, "cis"); break;
        case 8: sprintf(*buf, "gis"); break;
        case 9: sprintf(*buf, "dis"); break;
        case 10: sprintf(*buf, "ais"); break;
        case 11: sprintf(*buf, "eis"); break;
        case 12: sprintf(*buf, "bis"); break;
        case -1: sprintf(*buf, "f"); break;
        case -2: sprintf(*buf, "bes"); break;
        case -3: sprintf(*buf, "ees"); break;
        case -4: sprintf(*buf, "aes"); break;
        case -5: sprintf(*buf, "des"); break;
        case -6: sprintf(*buf, "ges"); break;
        case -7: sprintf(*buf, "ces"); break;
        case -8: sprintf(*buf, "fes"); break;
        case -9: sprintf(*buf, "beses"); break;
        case -10: sprintf(*buf, "eeses"); break;
        case -11: sprintf(*buf, "aeses"); break;
        case -12: sprintf(*buf, "deses"); break;
        default: sprintf(*buf, "c"); break;
    }
}

long barline_to_lilypond_buf(t_notation_obj *r_ob, t_measure *measure, char **buf)
{
    if (!*buf)
        *buf = (char *)bach_newptr(30 * sizeof(char));

    char type = measure->end_barline->barline_type;
    if (type == k_BARLINE_AUTOMATIC || type == 0)
        type = measure->next ? k_BARLINE_NORMAL : k_BARLINE_FINAL;
    
    switch (type) {
        case k_BARLINE_NORMAL:
            return snprintf_zero(*buf, 30, "\t\t\t|\r\n");
            break;
        case k_BARLINE_SOLID:
            return snprintf_zero(*buf, 30, "\t\t\t\\bar \".\"\r\n");
            break;
        case k_BARLINE_DOUBLE:
            return snprintf_zero(*buf, 30, "\t\t\t\\bar \"||\"\r\n");
            break;
        case k_BARLINE_DASHED:
            return snprintf_zero(*buf, 30, "\t\t\t\\bar \"dashed\"\r\n");
            break;
        case k_BARLINE_FINAL:
            return snprintf_zero(*buf, 30, "\t\t\t\\bar \"|.\"\r\n");
            break;
        case k_BARLINE_HIDDEN:
            return snprintf_zero(*buf, 30, "\t\t\t\\bar \"\"\r\n");
            break;
        case k_BARLINE_POINTS:
            return snprintf_zero(*buf, 30, "\t\t\t\\bar \":\"\r\n");
            break;
        default:
            return snprintf_zero(*buf, 30, "\t\t\t|\r\n");
            break;
    }
}


long tempo_to_lilypond_buf(t_notation_obj *r_ob, t_tempo *tempo, char **buf, char *must_start_tempo_span, char *must_end_tempo_span)
{
    if (!*buf)
        *buf = (char *)bach_newptr(150 * sizeof(char));

    t_rational temp = rat_long_prod(tempo->figure_tempo_value, tempo->tempo_figure.r_num);
    
    *must_start_tempo_span = 0;
    if (*must_end_tempo_span == -1)
        *must_end_tempo_span = 1;
    
    if (tempo->interpolation_type) {
        t_tempo *next_tempo = tempo_get_next(tempo);
        long cmp = rat_rat_cmp(next_tempo->tempo_value, tempo->tempo_value);
        if (cmp > 0) {
            *must_start_tempo_span = 1;
            return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n\t\t\t\\override TextSpanner.bound-details.left.text = \"acc.\"\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
        } else if (cmp < 0) {
            *must_start_tempo_span = 1;
            return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n\t\t\t\\override TextSpanner.bound-details.left.text = \"rall.\"\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
        } else 
            return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
    } else 
        return snprintf_zero(*buf, 150, "\t\t\t\\tempo %ld = %ld\r\n", tempo->tempo_figure.r_den, (long)round(((double)temp.r_num)/temp.r_den));
}    


void write_tempo_interp_if_needed(t_notation_obj *r_ob, char *must_start_tempo_span, char *must_end_tempo_span, t_filestruct *f, t_ptr_size *count)
{
    char *buf = (char *)bach_newptr(150 * sizeof(char));

    if (*must_end_tempo_span == 1) {
        *must_end_tempo_span = 0;
        *count = snprintf_zero(buf, 150, "\t\t\t\\stopTextSpan\r\n");
        sysfile_write(f, count, buf);
    }

    if (*must_start_tempo_span == 1) {
        *must_start_tempo_span = 0;
        *must_end_tempo_span = -1;
        *count = snprintf_zero(buf, 150, "\t\t\t\\startTextSpan\r\n");
        sysfile_write(f, count, buf);
    } 
    
    bach_freeptr(buf);
}

t_max_err score_dowritelilypond_pdf(t_score *x, t_symbol *s, long ac, t_atom *av)
{
    char filename[MAX_FILENAME_CHARS];
    char fullname[MAX_PATH_CHARS];
    char fullname_conform[MAX_PATH_CHARS];
    short path = 0;
    t_atom new_av[4];
    atom_setobj(new_av, atom_getobj(av));
    atom_setobj(new_av+1, filename);
    atom_setobj(new_av+2, &path);
    atom_setlong(new_av+3, true);
    t_max_err err = score_dowritelilypond(x, s, 4, new_av);

    if (!err) {
        path_topathname(path, filename, fullname);
        long l = strlen(fullname);
#ifdef MAC_VERSION
        path_nameconform(fullname, fullname_conform, PATH_STYLE_MAX, PATH_TYPE_BOOT);
#else
        path_nameconform(fullname, fullname_conform, PATH_STYLE_MAX, PATH_TYPE_ABSOLUTE);
#endif
        if (l > 3 && !strncmp(fullname_conform + l - 3, ".ly", 3)) {
            fullname_conform[l - 3] = 0;
        }

#ifdef MAC_VERSION
        char buf1[MAX_PATH_CHARS * 4];
        char buf2[MAX_PATH_CHARS * 4];
        snprintf_zero(buf1, MAX_PATH_CHARS * 4, "/Applications/LilyPond.app/Contents/Resources/bin/lilypond -o \"%s\" \"%s\"", fullname_conform, fullname_conform);
        snprintf_zero(buf2, MAX_PATH_CHARS * 4, "open \"%s.pdf\"", fullname_conform);
        system(buf1);
        system(buf2);
#endif
#ifdef WIN_VERSION
        char lilypond_doc_path[MAX_PATH_CHARS * 4];
        char pdf_doc_path[MAX_PATH_CHARS * 4];
        char lilypond_app_path[MAX_PATH_CHARS * 4];
        char pdf_app_path[MAX_PATH_CHARS * 4];
        char lilypond_cmd[MAX_PATH_CHARS * 4];
        char pdf_cmd[MAX_PATH_CHARS * 4];
        HINSTANCE winapi_err;
        snprintf_zero(lilypond_doc_path, MAX_PATH_CHARS * 4, "%s.ly", fullname_conform);
        FindExecutable(lilypond_doc_path, NULL, lilypond_app_path);
        long lilypond_app_path_len;
        if ((lilypond_app_path_len = strlen(lilypond_app_path)) < 20) {
            object_error((t_object *) x, "Can't open %s", lilypond_doc_path);
            return MAX_ERR_GENERIC;
        }
        if (!strcmp(lilypond_app_path + lilypond_app_path_len - 20, "lilypond-windows.exe")) {
            strncpy_zero(lilypond_app_path + lilypond_app_path_len - 20, "lilypond.exe", MAX_PATH_CHARS * 4);
        } else if (!strcmp(lilypond_app_path + lilypond_app_path_len - 21, "lilypond-windows.exe\"")) { // one never knows...
            strncpy_zero(lilypond_app_path + lilypond_app_path_len - 21, "lilypond.exe\"", MAX_PATH_CHARS * 4);
        }
        long sys_err;
        //post("lilypond: %s", lilypond_app_path);
        snprintf_zero(lilypond_cmd, MAX_PATH_CHARS * 4, "\"\"%s\" -o \"%s\" \"%s\"\"", lilypond_app_path, fullname_conform, fullname_conform);
        //post("command: %s", lilypond_cmd);
        //sys_err = system("cmd"); 
        sys_err = system(lilypond_cmd);
        //post("sys_err = %ld", sys_err);

        snprintf_zero(pdf_doc_path, MAX_PATH_CHARS * 4, "\"%s.pdf\"", fullname_conform);
        FindExecutable(pdf_doc_path, NULL, pdf_app_path);
        //post("pdf_app_path: %s", pdf_app_path);
        //post("pdf_doc_path: %s", pdf_doc_path);
        if (*pdf_app_path == 0) {
            object_error((t_object *) x, "Can't open %s", pdf_doc_path);
            return MAX_ERR_GENERIC;        
        }
        //post("acrobat: %s", pdf_app_path);
        //snprintf_zero(pdf_cmd, MAX_PATH_CHARS * 4, "\"\"%s\" \"%s\"\"", pdf_app_path, pdf_doc_path);
        //post("command: %s", pdf_cmd);

        _spawnl(_P_NOWAIT, pdf_app_path, pdf_doc_path, pdf_doc_path, NULL);

        //system(pdf_cmd);
#endif
    }
    return err;
}


char are_trills_with_accidental_used(t_score *x)
{
    t_scorevoice *voice;
    t_measure *meas;
    t_chord *chord;
    t_note *note;
    long j;
    
    for (voice = (t_scorevoice *)x->r_ob.firstvoice; voice; voice = voice->next) {
        for (meas = voice->firstmeasure; meas; meas = meas->next) {
            for (chord = meas->firstchord; chord; chord = chord->next) {
                for (j = 0; j < chord->num_articulations; j++)
                    if (chord->articulation[j].articulation_ID == k_ARTICULATION_TRILL_NATURAL ||
                        chord->articulation[j].articulation_ID == k_ARTICULATION_TRILL_SHARP ||
                        chord->articulation[j].articulation_ID == k_ARTICULATION_TRILL_FLAT)
                        return true;
                
                for (note = chord->firstnote; note; note = note->next) {
                    for (j = 0; j < note->num_articulations; j++)
                        if (note->articulation[j].articulation_ID == k_ARTICULATION_TRILL_NATURAL ||
                            note->articulation[j].articulation_ID == k_ARTICULATION_TRILL_SHARP ||
                            note->articulation[j].articulation_ID == k_ARTICULATION_TRILL_FLAT)
                            return true;
                }
            }
        }
    }
    
    return false;
}


t_max_err score_dowritelilypond(t_score *x, t_symbol *s, long ac, t_atom *av)
{
    t_llll *voices_to_write = NULL;
    t_llll *arguments = (t_llll *) atom_getobj(av);
    char *filename = ac >= 2 ? (char *)atom_getobj(av+1) : NULL;
    short *path = ac >= 3 ? (short *)atom_getobj(av+2) : NULL;
    char direct_to_pdf = ac >= 4 ? atom_getlong(av+3) : false;
    t_symbol *filename_sym = NULL;
    t_llllelem *elem;
    t_fourcc outtype;
    t_filehandle f;
    t_fourcc filetype = 'TEXT';
    t_ptr_size count = 0;
    t_max_err err = MAX_ERR_NONE;
    char ok = true;
    
    llll_parseargs_and_attrs_destructive((t_object *) x, arguments, "sl",
                   _sym_filename, &filename_sym,
                   _llllobj_sym_voices, &voices_to_write); 

    if (arguments->l_size) {
        filename_sym = hatom_getsym(&arguments->l_head->l_hatom);
        if (filename_sym)
            llll_behead(arguments);
    }
    

    lock_general_mutex((t_notation_obj *)x);
    
    prepare_voices_to_write((t_notation_obj *) x, &voices_to_write);
    long num_voices = voices_to_write->l_size;
    bach_assert_objerror_goto(x, ok = (num_voices > 0), "No valid voices for export", score_dowritelilypond_error); // CANT SEEM TO MAKE THIS WORK

    
    if (direct_to_pdf) { // export directly to pdf, so user will input the pdf file name, we'll have to convert it into the .ly filename manually
        if (!filename_sym || filename_sym == gensym("")) {      // if no argument supplied, ask for file
            strncpy_zero(filename, "Untitled.pdf", MAX_PATH_CHARS);
            if (saveasdialog_extended(filename, path, &outtype, &filetype, 1)) {    // non-zero: user cancelled
                err = MAX_ERR_GENERIC;
            }
        } else {
            strncpy_zero(filename, filename_sym->s_name, MAX_PATH_CHARS);
            *path = path_getdefault();
        }
        
        if (!err) {
            char *ext = strchr(filename, '.');
            if (!ext) {
                strncat_zero(filename, ".ly", MAX_PATH_CHARS);
            } else {
                char *temp = ext;
                while (temp) {
                    ext = temp;
                    temp = strchr(temp + 1, '.');
                }
                if (ext && strcmp(ext, ".ly")) { // should be always true
                    if (!strcmp(ext, ".pdf")) {
                        ext[1] = 'l';
                        ext[2] = 'y';
                        ext[3] = 0;
                    } else 
                        strncat_zero(ext, ".ly", MAX_PATH_CHARS);
                }
            }
            
            err = path_createsysfile(filename, *path, 'TEXT', &f);
            sysfile_seteof(f, 0);
        }
    } else {
        err = bach_openfile_write(filename_sym, "Untitled.ly", &f, &filetype, 1, &outtype, filename, path);
    }
    
    if (err) {
        ok = 0;
        goto score_dowritelilypond_error;
    }


    count = 19;
    sysfile_write(f, &count, "\\version \"2.18.0\"\r\n");
    
    if (!are_all_measureinfo_synchronous(x)) { // if measureinfo is NOT the same for every voice
        char header_buf[1000];
        count = snprintf_zero(header_buf, 1000, "\\layout {\r\n\
            \\context {\r\n\
            \t\\Score\r\n\
            \t\\remove \"Timing_translator\"\r\n\
            \t\\remove \"Default_bar_line_engraver\"\r\n\
            \t\\remove \"Metronome_mark_engraver\"\r\n\
            }\r\n\
            \\context {\r\n\
            \t\\Staff\r\n\
            \t\\consists \"Timing_translator\"\r\n\
            \t\\consists \"Default_bar_line_engraver\"\r\n\
            \t\\consists \"Metronome_mark_engraver\"\r\n\
            }\r\n\
        }\r\n");
        sysfile_write(f, &count, header_buf);
    }
    
    if (are_trills_with_accidental_used(x)) { // we only put this if naturals/flat/sharps trills are used
        char header_buf[1000];
        count = snprintf_zero(header_buf, 1000, "\
        trillFlatMarkup = \\markup { \\vcenter { \\musicglyph #\"scripts.trill\"\
            \\smaller \\flat } } \
        trillFlat = \
#(let* ((music (make-articulation \"trill\"))\
        (trill-flat (lambda (grob)\
                     (grob-interpret-markup\
                      grob\
                      trillFlatMarkup))))\
        (ly:music-set-property! music 'tweaks\
         (acons 'stencil trill-flat\
         (ly:music-property music 'tweaks)))\
          music)\
          trillSharpMarkup = \\markup { \\vcenter { \\musicglyph #\"scripts.trill\"\
          \\smaller \\sharp } }\
          trillSharp =\
          #(let* ((music (make-articulation \"trill\"))\
          (trill-flat (lambda (grob)\
          (grob-interpret-markup\
          grob\
          trillSharpMarkup))))\
\
          (ly:music-set-property! music 'tweaks\
          (acons 'stencil trill-sharp\
           (ly:music-property music 'tweaks)))\
        music)\
        }");
    }
    
    count = 10;
    sysfile_write(f, &count, "\\score {\r\n");
    
    count = 5;
    sysfile_write(f, &count, "\t<<\r\n");

    for (elem = voices_to_write->l_head; elem; elem = elem->l_next) {
        t_scorevoice *voice = (t_scorevoice *) nth_voice((t_notation_obj *) x, hatom_getlong(&elem->l_hatom));

        count = 16;
        sysfile_write(f, &count, "\t\t\\new Staff {\r\n");

        // clef
        char *clef_buf = NULL;
        count = clef_number_to_lilypond_buf((t_notation_obj *) x, voice->v_ob.clef, &clef_buf);
        sysfile_write(f, &count, clef_buf);
        bach_freeptr(clef_buf);
        
        // key
        char key_note_buf[30];
        char *key_note_name_buf = NULL;
        key_to_note_name_lilypond_buf((t_notation_obj *)x, voice->v_ob.mode == k_MODE_NONSTANDARD ? 0 : voice->v_ob.key, &key_note_name_buf);
        count = snprintf_zero(key_note_buf,  30, "\t\t\t\\key %s %s\r\n", key_note_name_buf, voice->v_ob.mode == k_MODE_MINOR ? "\\minor" : "\\major");
        sysfile_write(f, &count, key_note_buf);
        bach_freeptr(key_note_name_buf);
        
        // measures
        t_measure *measure;
        char must_start_tempo_span = 0, must_end_tempo_span = 0;
        for (measure = voice->firstmeasure; measure; measure = measure->next) {
            t_tempo *tempo = measure->firsttempo;

            count = 5;
            sysfile_write(f, &count, "\t\t\t\r\n");

            if (!measure->prev || !ts_are_equal(&measure->timesignature, &measure->prev->timesignature)) {
                // time signature
                char ts_buf[100];
                char ts_buf_num[100];
                ts_buf_num[0] = 0;
                if (measure->timesignature.num_numerator_elements > 1) {
                    char *temp_ts_num = long_array_to_string(measure->timesignature.numerator_elements, measure->timesignature.num_numerator_elements, true);
                    bach_freeptr(temp_ts_num);
                    snprintf_zero(ts_buf_num, 100, "#'%s ", temp_ts_num);
                }
                count = snprintf_zero(ts_buf, 100, "\t\t\t\\time %s%ld/%ld\r\n", ts_buf_num, measure->timesignature.numerator, measure->timesignature.denominator);
                sysfile_write(f, &count, ts_buf);
            }

            if (is_measure_empty((t_notation_obj *)x, measure)) {
                char empty_measure_buf[30];
                
                // writing tempi
                while (tempo) {
                    char *tempo_buf = NULL;
                    count = tempo_to_lilypond_buf((t_notation_obj *)x, tempo, &tempo_buf, &must_start_tempo_span, &must_end_tempo_span);
                    sysfile_write(f, &count, tempo_buf);
                    tempo = tempo->next;
                    bach_freeptr(tempo_buf);
                }            

                count = snprintf_zero(empty_measure_buf, 30, "\t\t\tR1*%ld/%ld\r\n", measure->timesignature.numerator, measure->timesignature.denominator);
                write_tempo_interp_if_needed((t_notation_obj *)x, &must_start_tempo_span, &must_end_tempo_span, f, &count);
                sysfile_write(f, &count, empty_measure_buf);
            } else {
                
                // writing chords, one for each line
                t_chord *ch;
                char inside_grace_sequence = false;
                for (ch = measure->firstchord; ch; ch = ch->next) {
                    
                    // is there a tempo on the chord
                    while (tempo && rat_rat_cmp(tempo->changepoint, ch->r_sym_onset) <= 0) {
                        char *tempo_buf = NULL;
                        count = tempo_to_lilypond_buf((t_notation_obj *)x, tempo, &tempo_buf, &must_start_tempo_span, &must_end_tempo_span);
                        sysfile_write(f, &count, tempo_buf);
                        bach_freeptr(tempo_buf);
                        tempo = tempo->next;
                    }
                    
                    // does the chord open one or more tuplet levels?
                    t_llll *level = ch->rhythmic_tree_elem->l_parent;
                    while (level) {
                        if (is_level_tuplet(level) && get_level_start_chord(level, true) == ch) {
                            char tuplet_buf[40];
                            t_rhythm_level_properties *prop = (t_rhythm_level_properties *)level->l_thing.w_obj;
                            count = snprintf_zero(tuplet_buf, 40, "\t\t\t\\times %ld/%ld {\r\n", prop->tupletinfo.tuplet_local_ratio.r_num, prop->tupletinfo.tuplet_local_ratio.r_den);
                            sysfile_write(f, &count, tuplet_buf);
                        }
                        level = level->l_owner ? level->l_owner->l_parent : NULL;
                    }
                    
                    if (ch->is_grace_chord && !inside_grace_sequence) {
                        char grace_buf[20];
                        count = snprintf_zero(grace_buf, 20, "\t\t\t\\grace {\r\n");
                        inside_grace_sequence = true;
                        sysfile_write(f, &count, grace_buf);
                    } else if (!ch->is_grace_chord && inside_grace_sequence) {
                        char grace_end_buf[20];
                        count = snprintf_zero(grace_end_buf, 20, "\t\t\t}\r\n");
                        inside_grace_sequence = false;
                        sysfile_write(f, &count, grace_end_buf);
                    }
                    
                    char *ch_buf = NULL;
                    count = chord_to_lilypond_buf((t_notation_obj *)x, ch, &ch_buf);
                    sysfile_write(f, &count, ch_buf);
                    bach_freeptr(ch_buf);

                    write_tempo_interp_if_needed((t_notation_obj *)x, &must_start_tempo_span, &must_end_tempo_span, f, &count);

                    // does the chord end one or more tuplet levels?
                    level = ch->rhythmic_tree_elem->l_parent;
                    while (level) {
                        if (is_level_tuplet(level) && get_level_end_chord(level, true) == ch) {
                            char tuplet_buf[20];
                            count = snprintf_zero(tuplet_buf, 20, "\t\t\t}\r\n");
                            sysfile_write(f, &count, tuplet_buf);
                        }
                        level = level->l_owner ? level->l_owner->l_parent : NULL;
                    }                
                }
                
                // possibly closing a grace chord sequence
                if (inside_grace_sequence) {
                    char grace_end_buf[20];
                    count = snprintf_zero(grace_end_buf, 20, "\t\t\t}\r\n");
                    sysfile_write(f, &count, grace_end_buf);
                }
            }
            
            // barline
            char *barline_buf = NULL;
            count = barline_to_lilypond_buf((t_notation_obj *)x, measure, &barline_buf);
            sysfile_write(f, &count, barline_buf);
            bach_freeptr(barline_buf);
        } 
    
        count = 5;
        sysfile_write(f, &count, "\t\t}\r\n");
    }

    count = 5;
    sysfile_write(f, &count, "\t>>\r\n");

    count = 3;
    sysfile_write(f, &count, "}\r\n");

    sysfile_close(f);
    
score_dowritelilypond_error:
    unlock_general_mutex((t_notation_obj *)x);
    if (arguments)
        llll_free(arguments);
    return ok ? MAX_ERR_NONE : MAX_ERR_GENERIC;
}




void score_exportimage(t_score *x, t_symbol *s, long argc, t_atom *argv)
{
    t_atom av;
    t_llll *arguments = llllobj_parse_llll((t_object *) x, LLLL_OBJ_UI, NULL, argc, argv, LLLL_PARSE_CLONE);
    atom_setobj(&av, arguments);
    defer(x, (method)notationobj_dowriteimage, s, 1, &av);
}

