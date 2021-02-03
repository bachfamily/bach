/*
 *  llll_commonsyms.h
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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

#include "foundation/bach.h"

#ifndef _LLLL_COMMONSYMS_H_
#define _LLLL_COMMONSYMS_H_

#define LLLL_FLOAT64_MARKER_05		"\xcb\x87\xcb\x87\xcb\x87\xcb\x87_float64_\xcb\x87\xcb\x87\xcb\x87\xcb\x87"
#define LLLL_FLOAT64_MARKER_CORRUPT	"\xc3\x80\xc3\xa1\xc3\x80\xc3\xa1\xc3\x80\xc3\xa1\xc3\x80\xc3\xa1_float64_\xc3\x80\xc3\xa1\xc3\x80\xc3\xa1\xc3\x80\xc3\xa1\xc3\x80\xc3\xa1"
#define LLLL_FLOAT64_MARKER			"_x_x_x_x_bach_float64_x_x_x_x_"
#define LLLL_LLLL_CLASSHOLDER		"_x_x_x_x_bach.llll_class_x_x_x_x_"
#define LLLL_LLLLELEM_CLASSHOLDER	"_x_x_x_x_bach.llllelem_class_x_x_x_x_"
#define LLLL_PHONEBOOK_HOLDER		"_x_x_x_x_bach.phonebook_x_x_x_x_"
#define LLLL_GARBAGE_HOLDER			"_x_x_x_x_bach.garbage_x_x_x_x_"
#define BACH_UNKNOWN_MESSAGE_STRING "unknown message"

typedef struct _llllobj_common_symbols_table
{
	t_symbol	*s_open_round_bracket;		
	t_symbol	*s_closed_round_bracket;
	t_symbol	*s_open_square_bracket;	
	t_symbol	*s_closed_square_bracket;
	t_symbol	*s_open_curly_bracket;
	t_symbol	*s_closed_curly_bracket;
	t_symbol	*s_llllconnect;
	t_symbol	*s_parse;
	t_symbol	*s_destroy;
	t_symbol	*s_nil;
	t_symbol	*s_null;
	t_symbol	*s_i;
	t_symbol	*s_r;
	t_symbol	*s_n;
	t_symbol	*s_l;
	t_symbol	*s_f;
    t_symbol    *s_m;
	t_symbol	*s_s;
	t_symbol	*s_o;
    t_symbol	*s_p;
	t_symbol	*s_t;
	t_symbol	*s_g;
	t_symbol	*s_unknown;
	t_symbol	*s_all;
    t_symbol	*s_any;
    t_symbol	*s_each;
    t_symbol	*s_same;
    t_symbol	*s_goto;
	t_symbol	*s_clear;
	t_symbol	*s_bach_lexpr;
	t_symbol	*s_bach_collector;
	t_symbol	*s_bach_llll;
	t_symbol	*s_bach_llllelem;
	t_symbol	*s_eval;
	t_symbol	*s_get;
	t_symbol	*s_command;
	t_symbol	*s__llll;
	t_symbol	*s__llllelem;
	t_symbol	*s_clone;
	t_symbol	*s_copy;
	t_symbol	*s_deparse;
	t_symbol	*s_top;
	t_symbol	*s_back;
	t_symbol	*s_clearall;
	t_symbol	*s_collection;
	t_symbol	*s_out;
	t_symbol	*s_vars;
	t_symbol	*s_string;
	
	t_symbol	*s___llll_primes__;

	t_symbol	*s_roll;
	t_symbol	*s_score;
	t_symbol	*s_graphic;
	t_symbol	*s_breakpoints;
	t_symbol	*s_articulations;
    t_symbol	*s_articulationinfo;
    t_symbol	*s_noteheadinfo;
    t_symbol	*s_notehead;
    t_symbol	*s_noteheads;
    t_symbol	*s_annotation;
    t_symbol	*s_numparts;
    t_symbol	*s_parts;
	t_symbol	*s_slots;
	t_symbol	*s_function;
	t_symbol	*s_int;
	t_symbol	*s_float;
	t_symbol	*s_text;
	t_symbol	*s_llll;
	t_symbol	*s_intlist;
	t_symbol	*s_floatlist;
	t_symbol	*s_intmatrix;
	t_symbol	*s_floatmatrix;
	t_symbol	*s_togglematrix;
	t_symbol	*s_filelist;
	t_symbol	*s_spat;
	t_symbol	*s_filter;
	t_symbol	*s_dynfilter;
	t_symbol	*s_color;
	t_symbol	*s_3dfunction;
    t_symbol	*s_dynamics;
    t_symbol	*s_access;
    t_symbol	*s_readonly;
    t_symbol	*s_readandwrite;
	
	t_symbol	*s_none;
	t_symbol	*s_onset;
	t_symbol	*s_onsets;
	t_symbol	*s_cent;
	t_symbol	*s_cents;
	t_symbol	*s_deltacents;
	t_symbol	*s_duration;
	t_symbol	*s_durations;
	t_symbol	*s_velocity;
	t_symbol	*s_velocities;
	t_symbol	*s_extra;
	t_symbol	*s_extras;
	t_symbol	*s_slotinfo;
	t_symbol	*s_start;
	t_symbol	*s_end;
	t_symbol	*s_note;
	t_symbol	*s_chord;
	t_symbol	*s_rest;
	t_symbol	*s_symduration;
	t_symbol	*s_symonset;
	t_symbol	*s_symtail;
    t_symbol    *s_dumpselection;
    t_symbol    *s_state;

	t_symbol	*s_FFGG;
	t_symbol	*s_FFG;
	t_symbol	*s_FGG;
	t_symbol	*s_FF;
	t_symbol	*s_GG;
	t_symbol	*s_FG;
	t_symbol	*s_F;
	t_symbol	*s_G;
	t_symbol	*s_G15;
	t_symbol	*s_F15;
	t_symbol	*s_G8;
	t_symbol	*s_F8;
	t_symbol	*s_Soprano;
	t_symbol	*s_Mezzo;
	t_symbol	*s_Alto;
	t_symbol	*s_Tenor;
	t_symbol	*s_Barytone;
	t_symbol	*s_Bass;
	t_symbol	*s_Percussion;
	t_symbol	*s_GF;
	t_symbol	*s_GGF;
	t_symbol	*s_GGFF;
	t_symbol	*s_GFF;
    t_symbol	*s_G8va;
    t_symbol	*s_G8vb;
    t_symbol	*s_G15ma;
    t_symbol	*s_G15mb;
    t_symbol	*s_F8va;
    t_symbol	*s_F8vb;
    t_symbol	*s_F15ma;
    t_symbol	*s_F15mb;

	t_symbol	*s_ID;
	t_symbol	*s_domain;
	t_symbol	*s_length;
    t_symbol	*s_insertvoice;
    t_symbol	*s_deletevoice;
	t_symbol	*s_addchord;
	t_symbol	*s_gluechord;
	t_symbol	*s_midichannels;
	t_symbol	*s_list;
	t_symbol	*s_measureinfo;
	t_symbol	*s_measure;
	t_symbol	*s_measures;
	t_symbol	*s_division;
    t_symbol	*s_subdivision;
	t_symbol	*s_tie;
	t_symbol	*s_ties;
	t_symbol	*s_score2roll;
	t_symbol	*s_cursor;
	t_symbol	*s_commands;
	t_symbol	*s_play;
	t_symbol	*s_stop;
    t_symbol	*s_pause;
	t_symbol	*s_clefs;
	t_symbol	*s_keys;
	t_symbol	*s_markers;
	t_symbol	*s_marker;
	t_symbol	*s_groups;
    t_symbol    *s_voicespacing;
    t_symbol    *s_hidevoices;
    t_symbol	*s_addtempo;
    t_symbol	*s_addmeasure;
	t_symbol	*s_addmeasures;
    t_symbol	*s_appendmeasure;
    t_symbol	*s_appendmeasures;
    t_symbol	*s_insertmeasure;
    t_symbol	*s_insertmeasures;
	t_symbol	*s_addchords;
	t_symbol	*s_slope;
	t_symbol	*s_representation;
	t_symbol	*s_ysnap;
	t_symbol	*s_zsnap;
	t_symbol	*s_body;
	t_symbol	*s_name;
	t_symbol	*s_type;
	t_symbol	*s_key;
	t_symbol	*s_range;
    t_symbol	*s_pixel;
    t_symbol	*s_time;
    t_symbol	*s_timepoint;
	t_symbol	*s_voicepixelpos;
	t_symbol	*s_timeatpixel;
	t_symbol	*s_width;
	t_symbol	*s_temporal;
    t_symbol	*s_temporalmode;
    t_symbol	*s_extend;
    t_symbol	*s_relative;
    t_symbol	*s_milliseconds;
    t_symbol	*s_timepoints;
	t_symbol	*s_abr_none_abr;
	t_symbol	*s_legato;
    t_symbol	*s_legatotrim;
    t_symbol	*s_legatoextend;
    t_symbol	*s_glissando;
    t_symbol	*s_glissandotrim;
    t_symbol	*s_glissandoextend;
	t_symbol	*s_voicenames;
	t_symbol	*s_dyn;
	t_symbol	*s_dynamic;
	t_symbol	*s_lambda;
	t_symbol	*s_tail;
	t_symbol	*s_eraseslot;
	t_symbol	*s_changeslotvalue;
    t_symbol	*s_changeslotitem;
    t_symbol	*s_addslotitem;
    t_symbol	*s_appendslotitem;
    t_symbol	*s_prependslotitem;
    t_symbol	*s_insertslotitem;
    t_symbol	*s_deleteslotitem;
	t_symbol	*s_addslot;
    t_symbol    *s_setslot;
    t_symbol    *s_setdurationline;
	t_symbol	*s_addbreakpoint;
	t_symbol	*s_erasebreakpoints;
	t_symbol	*s_widthfactor;
	t_symbol	*s_currentchord;
	t_symbol	*s_Auto;
	t_symbol	*s_auto;
	t_symbol	*s_domainslope;
	t_symbol	*s_label;
	t_symbol	*s_shownumber;
	t_symbol	*s_off;
	t_symbol	*s_on;
	t_symbol	*s_barline;
	t_symbol	*s_boxes;
	t_symbol	*s_if;
	t_symbol	*s_singleslotfortiednotes;
    t_symbol	*s_copywhensplit;
    t_symbol	*s_follownotehead;
	t_symbol	*s_default;
	t_symbol	*s_quantize;
	t_symbol	*s_zrange;
	t_symbol	*s_zslope;

	t_symbol	*s_display;
	t_symbol	*s_lowpass;
	t_symbol	*s_highpass;
	t_symbol	*s_bandpass;
	t_symbol	*s_bandstop;
	t_symbol	*s_peaknotch;
	t_symbol	*s_lowshelf;
	t_symbol	*s_highshelf;
	t_symbol	*s_resonant;
	t_symbol	*s_allpass;
	t_symbol	*s_point;
	
	t_symbol	*s_sel;
	t_symbol	*s_unsel;
    t_symbol	*s_subsel;
	t_symbol	*s_selmeasures;
	t_symbol	*s_unselmeasures;

	t_symbol	*s_leveltype;
	t_symbol	*s_tupletunit;
	t_symbol	*s_tupletdur;
	t_symbol	*s_tupletpregressedratio;
	t_symbol	*s_tupletinfo;
	
	t_symbol	*s_no_name;
	t_symbol	*s_empty_symbol;
	t_symbol	*s_setinterleaved;
	t_symbol	*s_transpose;
	t_symbol	*s_complement;
	t_symbol	*s_invert;
	t_symbol	*s_inf;
	t_symbol	*s_error;
	t_symbol	*s_endeditbox;
	t_symbol	*s_frame;
	t_symbol	*s_begin_preset;
	t_symbol	*s_restore_preset;
	t_symbol	*s_end_preset;
	t_symbol	*s_discardgrace;
	t_symbol	*s_discardgracerests;
	t_symbol	*s_trytoavoidgrace;
	t_symbol	*s_gracedeletethresh;
	t_symbol	*s_1_16;
	t_symbol	*s_1_12;
	t_symbol	*s_vzoom;
	t_symbol	*s_gridperiodms;
	t_symbol	*s_numgridsubdivisions;
	t_symbol	*s_Courier;
	t_symbol	*s_questionmark;
	t_symbol	*s_lock;
	t_symbol	*s_mute;
	t_symbol	*s_solo;
	t_symbol	*s_background;
	t_symbol	*s_popup;
	t_symbol	*s_linkto;
	t_symbol	*s_rightclick;
	t_symbol	*s_lyrics;
	t_symbol	*s_notecolor;
    t_symbol	*s_dlcolor;
	t_symbol	*s_noteheadadjust;
	t_symbol	*s_noteheadfont;
	t_symbol	*s_noteheadchar;
	t_symbol	*s_notesize;
	t_symbol	*s_grace;
	t_symbol	*s_tempo;
    t_symbol	*s_quartertempo;
	t_symbol	*s_figure;
	t_symbol	*s_interp;
    t_symbol	*s_prepad;
	t_symbol	*s_lockrhythmictree;
	t_symbol	*s_clef;
	t_symbol	*s_mode;
	t_symbol	*s_accpattern;
	t_symbol	*s_midichannel;
	t_symbol	*s_attach;
	t_symbol	*s_voice;
	t_symbol	*s_pim;
	t_symbol	*s_stafflines;
	t_symbol	*s_timesig;
	t_symbol	*s_role;
	t_symbol	*s_loop;
    t_symbol	*s_flags;
    t_symbol    *s_flag;
    t_symbol	*s_path;
    t_symbol    *s_painted;

	t_symbol	*s_prev;
	t_symbol	*s_next;
	
	t_symbol	*s_notes;
	t_symbol	*s_breakpoint;
	t_symbol	*s_chords;
    t_symbol	*s_rests;
	t_symbol	*s_region;
	t_symbol	*s_scrollbar;
	t_symbol	*s_scrollbars;
	t_symbol	*s_voices;
	t_symbol	*s_tempi;
	t_symbol	*s_slot;
	t_symbol	*s_articulation;
	t_symbol	*s_slur;
	t_symbol	*s_slurs;
	t_symbol	*s_zoom;
	t_symbol	*s_barlines;
	t_symbol	*s_timesignature;
	t_symbol	*s_timesignatures;
	t_symbol	*s_inspector;
	t_symbol	*s_tails;
	t_symbol	*s_selection;
	t_symbol	*s_group;
	t_symbol	*s_pitch;
    t_symbol	*s_poc;
    t_symbol	*s_pitches;
	t_symbol	*s_rhythmictree;
	t_symbol	*s_dilationrectangle;
	t_symbol	*s_popupmenu;

	t_symbol	*s_create;
	t_symbol	*s_delete;
	t_symbol	*s_modify;
	t_symbol	*s_position;
	t_symbol	*s_value;
    t_symbol	*s_thresh;
	
	t_symbol	*s_names;
	t_symbol	*s_usecustomnumber;
	t_symbol	*s_usecustomboxes;
	t_symbol	*s_number;
	t_symbol	*s_lockwidth;
	t_symbol	*s_separate;
	t_symbol	*s_active;
	t_symbol	*s_openslot;
	t_symbol	*s_sample;

	t_symbol	*s_left;
	t_symbol	*s_right;
	t_symbol	*s_nearest;
	t_symbol	*s_header;
	t_symbol	*s_height;
	t_symbol	*s_root;
    
    t_symbol    *s_mixed;
    t_symbol    *s_whole;
    t_symbol    *s_breakpointortail;
    t_symbol    *s_durationline;
    t_symbol    *s_transaction;

	t_symbol	*s_bachcursors;
    
    t_symbol    *s_getdomains;
    t_symbol    *s_setdomains;
    t_symbol    *s_reject;

	t_symbol	*s_float64_marker;
	t_symbol	*s_float64_marker_05;
	t_symbol	*s_float64_marker_corrupt;
	
} t_llllobj_common_symbols_table;

#define _llllobj_sym_open_round_bracket		(_llllobj_common_symbols->s_open_round_bracket)
#define _llllobj_sym_closed_round_bracket	(_llllobj_common_symbols->s_closed_round_bracket)
#define _llllobj_sym_open_square_bracket	(_llllobj_common_symbols->s_open_square_bracket)
#define _llllobj_sym_closed_square_bracket	(_llllobj_common_symbols->s_closed_square_bracket)
#define _llllobj_sym_open_curly_bracket		(_llllobj_common_symbols->s_open_curly_bracket)
#define _llllobj_sym_closed_curly_bracket	(_llllobj_common_symbols->s_closed_curly_bracket)

#define _llllobj_sym_llllconnect	(_llllobj_common_symbols->s_llllconnect)
#define _llllobj_sym_parse			(_llllobj_common_symbols->s_parse)
#define _llllobj_sym_destroy		(_llllobj_common_symbols->s_destroy)
#define _llllobj_sym_nil			(_llllobj_common_symbols->s_nil)
#define _llllobj_sym_null			(_llllobj_common_symbols->s_null)
#define _llllobj_sym_i				(_llllobj_common_symbols->s_i)
#define _llllobj_sym_r				(_llllobj_common_symbols->s_r)
#define _llllobj_sym_f				(_llllobj_common_symbols->s_f)
#define _llllobj_sym_m				(_llllobj_common_symbols->s_m)
#define _llllobj_sym_n				(_llllobj_common_symbols->s_n)
#define _llllobj_sym_l				(_llllobj_common_symbols->s_l)
#define _llllobj_sym_s				(_llllobj_common_symbols->s_s)
#define _llllobj_sym_o				(_llllobj_common_symbols->s_o)
#define _llllobj_sym_p				(_llllobj_common_symbols->s_p)
#define _llllobj_sym_t				(_llllobj_common_symbols->s_t)
#define _llllobj_sym_g				(_llllobj_common_symbols->s_g)
#define _llllobj_sym_unknown		(_llllobj_common_symbols->s_unknown)
#define	_llllobj_sym_all			(_llllobj_common_symbols->s_all)
#define	_llllobj_sym_any			(_llllobj_common_symbols->s_any)
#define	_llllobj_sym_each			(_llllobj_common_symbols->s_each)
#define	_llllobj_sym_same			(_llllobj_common_symbols->s_same)
#define	_llllobj_sym_goto			(_llllobj_common_symbols->s_goto)
#define	_llllobj_sym_clear			(_llllobj_common_symbols->s_clear)
#define	_llllobj_sym_bach_lexpr		(_llllobj_common_symbols->s_bach_lexpr)	
#define	_llllobj_sym_bach_collector	(_llllobj_common_symbols->s_bach_collector)
#define	_llllobj_sym_bach_llll		(_llllobj_common_symbols->s_bach_llll)
#define	_llllobj_sym_bach_llllelem	(_llllobj_common_symbols->s_bach_llllelem)
#define	_llllobj_sym_eval			(_llllobj_common_symbols->s_eval)		
#define	_llllobj_sym_get			(_llllobj_common_symbols->s_get)	
#define	_llllobj_sym_command		(_llllobj_common_symbols->s_command)	
#define	_llllobj_sym__llll			(_llllobj_common_symbols->s__llll)	
#define	_llllobj_sym__llllelem		(_llllobj_common_symbols->s__llllelem)	
#define	_llllobj_sym_clone			(_llllobj_common_symbols->s_clone)	
#define	_llllobj_sym_copy			(_llllobj_common_symbols->s_copy)		
#define	_llllobj_sym_deparse		(_llllobj_common_symbols->s_deparse)	
#define	_llllobj_sym_top			(_llllobj_common_symbols->s_top)
#define	_llllobj_sym_back			(_llllobj_common_symbols->s_back)		
#define	_llllobj_sym_clearall		(_llllobj_common_symbols->s_clearall)	
#define	_llllobj_sym_collection		(_llllobj_common_symbols->s_collection)
#define	_llllobj_sym_out			(_llllobj_common_symbols->s_out)
#define	_llllobj_sym_vars			(_llllobj_common_symbols->s_vars)
#define	_llllobj_sym_string			(_llllobj_common_symbols->s_string)

#define	_llllobj_sym__llll_primes__	(_llllobj_common_symbols->s___llll_primes__)

#define _llllobj_sym_roll			(_llllobj_common_symbols->s_roll)
#define _llllobj_sym_score			(_llllobj_common_symbols->s_score)
#define _llllobj_sym_graphic		(_llllobj_common_symbols->s_graphic)
#define _llllobj_sym_breakpoints	(_llllobj_common_symbols->s_breakpoints)
#define _llllobj_sym_articulations	(_llllobj_common_symbols->s_articulations)
#define _llllobj_sym_articulationinfo	(_llllobj_common_symbols->s_articulationinfo)
#define _llllobj_sym_noteheadinfo	(_llllobj_common_symbols->s_noteheadinfo)
#define _llllobj_sym_notehead       (_llllobj_common_symbols->s_notehead)
#define _llllobj_sym_noteheads      (_llllobj_common_symbols->s_noteheads)
#define _llllobj_sym_annotation     (_llllobj_common_symbols->s_annotation)
#define _llllobj_sym_numparts       (_llllobj_common_symbols->s_numparts)
#define _llllobj_sym_parts          (_llllobj_common_symbols->s_parts)
#define _llllobj_sym_slots			(_llllobj_common_symbols->s_slots)
#define _llllobj_sym_function		(_llllobj_common_symbols->s_function)
#define _llllobj_sym_int			(_llllobj_common_symbols->s_int)
#define _llllobj_sym_float			(_llllobj_common_symbols->s_float)
#define _llllobj_sym_text			(_llllobj_common_symbols->s_text)
#define _llllobj_sym_llll			(_llllobj_common_symbols->s_llll)
#define _llllobj_sym_intlist		(_llllobj_common_symbols->s_intlist)
#define _llllobj_sym_floatlist		(_llllobj_common_symbols->s_floatlist)
#define _llllobj_sym_intmatrix		(_llllobj_common_symbols->s_intmatrix)
#define _llllobj_sym_floatmatrix	(_llllobj_common_symbols->s_floatmatrix)
#define _llllobj_sym_togglematrix	(_llllobj_common_symbols->s_togglematrix)
#define _llllobj_sym_filelist		(_llllobj_common_symbols->s_filelist)
#define _llllobj_sym_spat			(_llllobj_common_symbols->s_spat)
#define _llllobj_sym_filter			(_llllobj_common_symbols->s_filter)
#define _llllobj_sym_dynfilter		(_llllobj_common_symbols->s_dynfilter)
#define _llllobj_sym_color			(_llllobj_common_symbols->s_color)
#define _llllobj_sym_3dfunction		(_llllobj_common_symbols->s_3dfunction)
#define _llllobj_sym_dynamics		(_llllobj_common_symbols->s_dynamics)
#define _llllobj_sym_access         (_llllobj_common_symbols->s_access)
#define _llllobj_sym_readonly       (_llllobj_common_symbols->s_readonly)
#define _llllobj_sym_readandwrite   (_llllobj_common_symbols->s_readandwrite)

#define _llllobj_sym_none			(_llllobj_common_symbols->s_none)
#define _llllobj_sym_onset			(_llllobj_common_symbols->s_onset)
#define _llllobj_sym_onsets			(_llllobj_common_symbols->s_onsets)
#define _llllobj_sym_cent			(_llllobj_common_symbols->s_cent)
#define _llllobj_sym_cents			(_llllobj_common_symbols->s_cents)
#define _llllobj_sym_deltacents		(_llllobj_common_symbols->s_deltacents)
#define _llllobj_sym_duration		(_llllobj_common_symbols->s_duration)
#define _llllobj_sym_durations		(_llllobj_common_symbols->s_durations)
#define _llllobj_sym_velocity		(_llllobj_common_symbols->s_velocity)
#define _llllobj_sym_velocities		(_llllobj_common_symbols->s_velocities)
#define _llllobj_sym_extra			(_llllobj_common_symbols->s_extra)
#define _llllobj_sym_extras			(_llllobj_common_symbols->s_extras)
#define _llllobj_sym_slotinfo		(_llllobj_common_symbols->s_slotinfo)
#define _llllobj_sym_start			(_llllobj_common_symbols->s_start)
#define _llllobj_sym_end			(_llllobj_common_symbols->s_end)
#define _llllobj_sym_note			(_llllobj_common_symbols->s_note)
#define _llllobj_sym_chord			(_llllobj_common_symbols->s_chord)
#define _llllobj_sym_rest			(_llllobj_common_symbols->s_rest)
#define _llllobj_sym_symduration	(_llllobj_common_symbols->s_symduration)
#define _llllobj_sym_symonset		(_llllobj_common_symbols->s_symonset)
#define _llllobj_sym_symtail		(_llllobj_common_symbols->s_symtail)
#define _llllobj_sym_dumpselection  (_llllobj_common_symbols->s_dumpselection)
#define _llllobj_sym_state          (_llllobj_common_symbols->s_state)

#define _llllobj_sym_FFGG			(_llllobj_common_symbols->s_FFGG)
#define _llllobj_sym_FGG			(_llllobj_common_symbols->s_FGG)
#define _llllobj_sym_FFG			(_llllobj_common_symbols->s_FFG)
#define _llllobj_sym_FG				(_llllobj_common_symbols->s_FG)
#define _llllobj_sym_FF				(_llllobj_common_symbols->s_FF)
#define _llllobj_sym_GG				(_llllobj_common_symbols->s_GG)
#define _llllobj_sym_F				(_llllobj_common_symbols->s_F)
#define _llllobj_sym_G				(_llllobj_common_symbols->s_G)
#define _llllobj_sym_G15			(_llllobj_common_symbols->s_G15)
#define _llllobj_sym_F15			(_llllobj_common_symbols->s_F15)
#define _llllobj_sym_G8				(_llllobj_common_symbols->s_G8)
#define _llllobj_sym_F8				(_llllobj_common_symbols->s_F8)
#define _llllobj_sym_Soprano		(_llllobj_common_symbols->s_Soprano)
#define _llllobj_sym_Mezzo			(_llllobj_common_symbols->s_Mezzo)
#define _llllobj_sym_Alto			(_llllobj_common_symbols->s_Alto)
#define _llllobj_sym_Tenor			(_llllobj_common_symbols->s_Tenor)
#define _llllobj_sym_Barytone		(_llllobj_common_symbols->s_Barytone)
#define _llllobj_sym_Bass			(_llllobj_common_symbols->s_Bass)
#define _llllobj_sym_Percussion		(_llllobj_common_symbols->s_Percussion)
#define _llllobj_sym_GF				(_llllobj_common_symbols->s_GF)
#define _llllobj_sym_GGF			(_llllobj_common_symbols->s_GGF)
#define _llllobj_sym_GGFF			(_llllobj_common_symbols->s_GGFF)
#define _llllobj_sym_GFF			(_llllobj_common_symbols->s_GFF)
#define _llllobj_sym_G8va			(_llllobj_common_symbols->s_G8va)
#define _llllobj_sym_G8vb			(_llllobj_common_symbols->s_G8vb)
#define _llllobj_sym_G15ma			(_llllobj_common_symbols->s_G15ma)
#define _llllobj_sym_G15mb			(_llllobj_common_symbols->s_G15mb)
#define _llllobj_sym_F8va			(_llllobj_common_symbols->s_F8va)
#define _llllobj_sym_F8vb			(_llllobj_common_symbols->s_F8vb)
#define _llllobj_sym_F15ma			(_llllobj_common_symbols->s_F15ma)
#define _llllobj_sym_F15mb			(_llllobj_common_symbols->s_F15mb)


#define _llllobj_sym_ID				(_llllobj_common_symbols->s_ID)
#define _llllobj_sym_domain			(_llllobj_common_symbols->s_domain)
#define _llllobj_sym_length			(_llllobj_common_symbols->s_length)
#define _llllobj_sym_insertvoice		(_llllobj_common_symbols->s_insertvoice)
#define _llllobj_sym_deletevoice	(_llllobj_common_symbols->s_deletevoice)
#define _llllobj_sym_addchord		(_llllobj_common_symbols->s_addchord)
#define _llllobj_sym_gluechord		(_llllobj_common_symbols->s_gluechord)
#define _llllobj_sym_midichannels	(_llllobj_common_symbols->s_midichannels)
#define _llllobj_sym_list			(_llllobj_common_symbols->s_list)
#define _llllobj_sym_measureinfo	(_llllobj_common_symbols->s_measureinfo)
#define _llllobj_sym_measures		(_llllobj_common_symbols->s_measures)
#define _llllobj_sym_measure		(_llllobj_common_symbols->s_measure)
#define _llllobj_sym_division		(_llllobj_common_symbols->s_division)
#define _llllobj_sym_subdivision	(_llllobj_common_symbols->s_subdivision)
#define _llllobj_sym_ties			(_llllobj_common_symbols->s_ties)
#define _llllobj_sym_tie			(_llllobj_common_symbols->s_tie)
#define _llllobj_sym_score2roll		(_llllobj_common_symbols->s_score2roll)
#define _llllobj_sym_cursor			(_llllobj_common_symbols->s_cursor)
#define _llllobj_sym_commands		(_llllobj_common_symbols->s_commands)
#define _llllobj_sym_play			(_llllobj_common_symbols->s_play)
#define _llllobj_sym_stop			(_llllobj_common_symbols->s_stop)
#define _llllobj_sym_pause			(_llllobj_common_symbols->s_pause)
#define _llllobj_sym_clefs			(_llllobj_common_symbols->s_clefs)
#define _llllobj_sym_keys			(_llllobj_common_symbols->s_keys)
#define _llllobj_sym_markers		(_llllobj_common_symbols->s_markers)
#define _llllobj_sym_marker			(_llllobj_common_symbols->s_marker)
#define _llllobj_sym_groups			(_llllobj_common_symbols->s_groups)
#define _llllobj_sym_voicespacing   (_llllobj_common_symbols->s_voicespacing)
#define _llllobj_sym_hidevoices     (_llllobj_common_symbols->s_hidevoices)
#define _llllobj_sym_addtempo       (_llllobj_common_symbols->s_addtempo)
#define _llllobj_sym_addmeasure 	(_llllobj_common_symbols->s_addmeasure)
#define _llllobj_sym_addmeasures	(_llllobj_common_symbols->s_addmeasures)
#define _llllobj_sym_appendmeasure 	(_llllobj_common_symbols->s_appendmeasure)
#define _llllobj_sym_appendmeasures	(_llllobj_common_symbols->s_appendmeasures)
#define _llllobj_sym_insertmeasure 	(_llllobj_common_symbols->s_insertmeasure)
#define _llllobj_sym_insertmeasures	(_llllobj_common_symbols->s_insertmeasures)
#define _llllobj_sym_addchords		(_llllobj_common_symbols->s_addchords)
#define _llllobj_sym_slope			(_llllobj_common_symbols->s_slope)
#define _llllobj_sym_representation	(_llllobj_common_symbols->s_representation)
#define _llllobj_sym_ysnap			(_llllobj_common_symbols->s_ysnap)
#define _llllobj_sym_zsnap			(_llllobj_common_symbols->s_zsnap)
#define _llllobj_sym_body			(_llllobj_common_symbols->s_body)
#define _llllobj_sym_name			(_llllobj_common_symbols->s_name)
#define _llllobj_sym_type			(_llllobj_common_symbols->s_type)
#define _llllobj_sym_key			(_llllobj_common_symbols->s_key)
#define _llllobj_sym_range			(_llllobj_common_symbols->s_range)
#define _llllobj_sym_pixel			(_llllobj_common_symbols->s_pixel)
#define _llllobj_sym_time			(_llllobj_common_symbols->s_time)
#define _llllobj_sym_timepoint		(_llllobj_common_symbols->s_timepoint)
#define _llllobj_sym_voicepixelpos	(_llllobj_common_symbols->s_voicepixelpos)
#define _llllobj_sym_timeatpixel	(_llllobj_common_symbols->s_timeatpixel)
#define _llllobj_sym_width			(_llllobj_common_symbols->s_width)
#define _llllobj_sym_temporal		(_llllobj_common_symbols->s_temporal)
#define _llllobj_sym_temporalmode		(_llllobj_common_symbols->s_temporalmode)
#define _llllobj_sym_extend		(_llllobj_common_symbols->s_extend)
#define _llllobj_sym_relative		(_llllobj_common_symbols->s_relative)
#define _llllobj_sym_milliseconds		(_llllobj_common_symbols->s_milliseconds)
#define _llllobj_sym_timepoints		(_llllobj_common_symbols->s_timepoints)
#define _llllobj_sym_abr_none_abr	(_llllobj_common_symbols->s_abr_none_abr)
#define _llllobj_sym_legato			(_llllobj_common_symbols->s_legato)
#define _llllobj_sym_legatotrim		(_llllobj_common_symbols->s_legatotrim)
#define _llllobj_sym_legatoextend	(_llllobj_common_symbols->s_legatoextend)
#define _llllobj_sym_glissando			(_llllobj_common_symbols->s_glissando)
#define _llllobj_sym_glissandotrim		(_llllobj_common_symbols->s_glissandotrim)
#define _llllobj_sym_glissandoextend	(_llllobj_common_symbols->s_glissandoextend)
#define _llllobj_sym_voicenames		(_llllobj_common_symbols->s_voicenames)
#define _llllobj_sym_dyn			(_llllobj_common_symbols->s_dyn)
#define _llllobj_sym_dynamic		(_llllobj_common_symbols->s_dynamic)
#define _llllobj_sym_lambda			(_llllobj_common_symbols->s_lambda)
#define _llllobj_sym_tail			(_llllobj_common_symbols->s_tail)
#define _llllobj_sym_eraseslot		(_llllobj_common_symbols->s_eraseslot)
#define _llllobj_sym_changeslotvalue	(_llllobj_common_symbols->s_changeslotvalue)
#define _llllobj_sym_changeslotitem	(_llllobj_common_symbols->s_changeslotitem)
#define _llllobj_sym_addslotitem	(_llllobj_common_symbols->s_addslotitem)
#define _llllobj_sym_appendslotitem	(_llllobj_common_symbols->s_appendslotitem)
#define _llllobj_sym_prependslotitem	(_llllobj_common_symbols->s_prependslotitem)
#define _llllobj_sym_insertslotitem	(_llllobj_common_symbols->s_insertslotitem)
#define _llllobj_sym_deleteslotitem	(_llllobj_common_symbols->s_deleteslotitem)
#define _llllobj_sym_addslot		(_llllobj_common_symbols->s_addslot)
#define _llllobj_sym_setslot        (_llllobj_common_symbols->s_setslot)
#define _llllobj_sym_setdurationline        (_llllobj_common_symbols->s_setdurationline)
#define _llllobj_sym_addbreakpoint	(_llllobj_common_symbols->s_addbreakpoint)
#define _llllobj_sym_erasebreakpoints	(_llllobj_common_symbols->s_erasebreakpoints)
#define _llllobj_sym_widthfactor	(_llllobj_common_symbols->s_widthfactor)
#define _llllobj_sym_currentchord	(_llllobj_common_symbols->s_currentchord)
#define _llllobj_sym_Auto			(_llllobj_common_symbols->s_Auto)
#define _llllobj_sym_auto			(_llllobj_common_symbols->s_auto)
#define _llllobj_sym_domainslope	(_llllobj_common_symbols->s_domainslope)
#define _llllobj_sym_label			(_llllobj_common_symbols->s_label)
#define _llllobj_sym_shownumber		(_llllobj_common_symbols->s_shownumber)
#define _llllobj_sym_off			(_llllobj_common_symbols->s_off)
#define _llllobj_sym_on				(_llllobj_common_symbols->s_on)
#define _llllobj_sym_barline		(_llllobj_common_symbols->s_barline)
#define _llllobj_sym_boxes			(_llllobj_common_symbols->s_boxes)
#define _llllobj_sym_if				(_llllobj_common_symbols->s_if)
#define _llllobj_sym_singleslotfortiednotes		(_llllobj_common_symbols->s_singleslotfortiednotes)
#define _llllobj_sym_copywhensplit              (_llllobj_common_symbols->s_copywhensplit)
#define _llllobj_sym_follownotehead              (_llllobj_common_symbols->s_follownotehead)
#define _llllobj_sym_default		(_llllobj_common_symbols->s_default)
#define _llllobj_sym_quantize		(_llllobj_common_symbols->s_quantize)
#define _llllobj_sym_zrange			(_llllobj_common_symbols->s_zrange)
#define _llllobj_sym_zslope			(_llllobj_common_symbols->s_zslope)

#define _llllobj_sym_display		(_llllobj_common_symbols->s_display)
#define _llllobj_sym_lowpass		(_llllobj_common_symbols->s_lowpass)
#define _llllobj_sym_highpass		(_llllobj_common_symbols->s_highpass)
#define _llllobj_sym_bandpass		(_llllobj_common_symbols->s_bandpass)
#define _llllobj_sym_bandstop		(_llllobj_common_symbols->s_bandstop)
#define _llllobj_sym_peaknotch		(_llllobj_common_symbols->s_peaknotch)
#define _llllobj_sym_lowshelf		(_llllobj_common_symbols->s_lowshelf)
#define _llllobj_sym_highshelf		(_llllobj_common_symbols->s_highshelf)
#define _llllobj_sym_resonant		(_llllobj_common_symbols->s_resonant)
#define _llllobj_sym_allpass		(_llllobj_common_symbols->s_allpass)

#define _llllobj_sym_point			(_llllobj_common_symbols->s_point)

#define _llllobj_sym_sel			(_llllobj_common_symbols->s_sel)
#define _llllobj_sym_unsel			(_llllobj_common_symbols->s_unsel)
#define _llllobj_sym_subsel			(_llllobj_common_symbols->s_subsel)
#define _llllobj_sym_selmeasures	(_llllobj_common_symbols->s_selmeasures)
#define _llllobj_sym_unselmeasures	(_llllobj_common_symbols->s_unselmeasures)

#define _llllobj_sym_leveltype		(_llllobj_common_symbols->s_leveltype)
#define _llllobj_sym_tupletunit		(_llllobj_common_symbols->s_tupletunit)
#define _llllobj_sym_tupletdur		(_llllobj_common_symbols->s_tupletdur)
#define _llllobj_sym_tupletpregressedratio		(_llllobj_common_symbols->s_tupletpregressedratio)
#define _llllobj_sym_tupletinfo		(_llllobj_common_symbols->s_tupletinfo)


#define _llllobj_sym_no_name		(_llllobj_common_symbols->s_no_name)
#define _llllobj_sym_empty_symbol	(_llllobj_common_symbols->s_empty_symbol)
#define _llllobj_sym_setinterleaved	(_llllobj_common_symbols->s_setinterleaved)
#define _llllobj_sym_transpose		(_llllobj_common_symbols->s_transpose)
#define _llllobj_sym_complement		(_llllobj_common_symbols->s_complement)
#define _llllobj_sym_invert			(_llllobj_common_symbols->s_invert)
#define _llllobj_sym_inf			(_llllobj_common_symbols->s_inf)
#define _llllobj_sym_error			(_llllobj_common_symbols->s_error)
#define _llllobj_sym_endeditbox		(_llllobj_common_symbols->s_endeditbox)
#define _llllobj_sym_frame			(_llllobj_common_symbols->s_frame)
#define _llllobj_sym_begin_preset	(_llllobj_common_symbols->s_begin_preset)
#define _llllobj_sym_restore_preset	(_llllobj_common_symbols->s_restore_preset)
#define _llllobj_sym_end_preset		(_llllobj_common_symbols->s_end_preset)
#define _llllobj_sym_discardgrace			(_llllobj_common_symbols->s_discardgrace)
#define _llllobj_sym_discardgracerests		(_llllobj_common_symbols->s_discardgracerests)
#define _llllobj_sym_trytoavoidgrace		(_llllobj_common_symbols->s_trytoavoidgrace)
#define _llllobj_sym_gracedeletethresh		(_llllobj_common_symbols->s_gracedeletethresh)
#define _llllobj_sym_1_16			(_llllobj_common_symbols->s_1_16)
#define _llllobj_sym_1_12			(_llllobj_common_symbols->s_1_12)
#define _llllobj_sym_vzoom			(_llllobj_common_symbols->s_vzoom)
#define _llllobj_sym_gridperiodms	(_llllobj_common_symbols->s_gridperiodms)
#define _llllobj_sym_numgridsubdivisions	(_llllobj_common_symbols->s_numgridsubdivisions)
#define _llllobj_sym_Courier		(_llllobj_common_symbols->s_Courier)
#define _llllobj_sym_questionmark	(_llllobj_common_symbols->s_questionmark)
#define _llllobj_sym_lock			(_llllobj_common_symbols->s_lock)
#define _llllobj_sym_mute			(_llllobj_common_symbols->s_mute)
#define _llllobj_sym_solo			(_llllobj_common_symbols->s_solo)
#define _llllobj_sym_background		(_llllobj_common_symbols->s_background)
#define _llllobj_sym_popup			(_llllobj_common_symbols->s_popup)
#define _llllobj_sym_linkto			(_llllobj_common_symbols->s_linkto)
#define _llllobj_sym_rightclick		(_llllobj_common_symbols->s_rightclick)
#define _llllobj_sym_lyrics			(_llllobj_common_symbols->s_lyrics)
#define _llllobj_sym_notecolor		(_llllobj_common_symbols->s_notecolor)
#define _llllobj_sym_dlcolor        (_llllobj_common_symbols->s_dlcolor)
#define _llllobj_sym_noteheadadjust	(_llllobj_common_symbols->s_noteheadadjust)
#define _llllobj_sym_noteheadfont	(_llllobj_common_symbols->s_noteheadfont)
#define _llllobj_sym_noteheadchar	(_llllobj_common_symbols->s_noteheadchar)
#define _llllobj_sym_notesize		(_llllobj_common_symbols->s_notesize)
#define _llllobj_sym_grace			(_llllobj_common_symbols->s_grace)
#define _llllobj_sym_tempo			(_llllobj_common_symbols->s_tempo)
#define _llllobj_sym_quartertempo	(_llllobj_common_symbols->s_quartertempo)
#define _llllobj_sym_figure			(_llllobj_common_symbols->s_figure)
#define _llllobj_sym_interp			(_llllobj_common_symbols->s_interp)
#define _llllobj_sym_prepad			(_llllobj_common_symbols->s_prepad)
#define _llllobj_sym_lockrhythmictree			(_llllobj_common_symbols->s_lockrhythmictree)
#define _llllobj_sym_clef			(_llllobj_common_symbols->s_clef)
#define _llllobj_sym_mode			(_llllobj_common_symbols->s_mode)
#define _llllobj_sym_accpattern		(_llllobj_common_symbols->s_accpattern)
#define _llllobj_sym_midichannel	(_llllobj_common_symbols->s_midichannel)
#define _llllobj_sym_attach			(_llllobj_common_symbols->s_attach)
#define _llllobj_sym_voice			(_llllobj_common_symbols->s_voice)
#define _llllobj_sym_pim			(_llllobj_common_symbols->s_pim)
#define _llllobj_sym_stafflines		(_llllobj_common_symbols->s_stafflines)
#define _llllobj_sym_timesig		(_llllobj_common_symbols->s_timesig)
#define _llllobj_sym_role			(_llllobj_common_symbols->s_role)
#define _llllobj_sym_loop			(_llllobj_common_symbols->s_loop)
#define _llllobj_sym_flag           (_llllobj_common_symbols->s_flag)
#define _llllobj_sym_flags			(_llllobj_common_symbols->s_flags)
#define _llllobj_sym_path			(_llllobj_common_symbols->s_path)
#define _llllobj_sym_painted            (_llllobj_common_symbols->s_painted)

#define _llllobj_sym_prev			(_llllobj_common_symbols->s_prev)
#define _llllobj_sym_next			(_llllobj_common_symbols->s_next)


#define _llllobj_sym_notes			(_llllobj_common_symbols->s_notes)
#define _llllobj_sym_breakpoint		(_llllobj_common_symbols->s_breakpoint)
#define _llllobj_sym_chords			(_llllobj_common_symbols->s_chords)
#define _llllobj_sym_rests			(_llllobj_common_symbols->s_rests)
#define _llllobj_sym_region			(_llllobj_common_symbols->s_region)
#define _llllobj_sym_scrollbar		(_llllobj_common_symbols->s_scrollbar)
#define _llllobj_sym_scrollbars		(_llllobj_common_symbols->s_scrollbars)
#define _llllobj_sym_voices			(_llllobj_common_symbols->s_voices)
#define _llllobj_sym_tempi			(_llllobj_common_symbols->s_tempi)
#define _llllobj_sym_slot			(_llllobj_common_symbols->s_slot)
#define _llllobj_sym_articulation	(_llllobj_common_symbols->s_articulation)
#define _llllobj_sym_slur			(_llllobj_common_symbols->s_slur)
#define _llllobj_sym_slurs			(_llllobj_common_symbols->s_slurs)
#define _llllobj_sym_zoom			(_llllobj_common_symbols->s_zoom)
#define _llllobj_sym_barlines		(_llllobj_common_symbols->s_barlines)
#define _llllobj_sym_timesignature	(_llllobj_common_symbols->s_timesignature)
#define _llllobj_sym_timesignatures	(_llllobj_common_symbols->s_timesignatures)
#define _llllobj_sym_inspector		(_llllobj_common_symbols->s_inspector)
#define _llllobj_sym_tails		(_llllobj_common_symbols->s_tails)
#define _llllobj_sym_selection		(_llllobj_common_symbols->s_selection)
#define _llllobj_sym_group		(_llllobj_common_symbols->s_group)
#define _llllobj_sym_pitch		(_llllobj_common_symbols->s_pitch)
#define _llllobj_sym_poc		(_llllobj_common_symbols->s_poc)
#define _llllobj_sym_pitches		(_llllobj_common_symbols->s_pitches)
#define _llllobj_sym_rhythmictree		(_llllobj_common_symbols->s_rhythmictree)
#define _llllobj_sym_dilationrectangle		(_llllobj_common_symbols->s_dilationrectangle)
#define _llllobj_sym_popupmenu		(_llllobj_common_symbols->s_popupmenu)

#define _llllobj_sym_create		(_llllobj_common_symbols->s_create)
#define _llllobj_sym_delete		(_llllobj_common_symbols->s_delete)
#define _llllobj_sym_modify		(_llllobj_common_symbols->s_modify)
#define _llllobj_sym_position	(_llllobj_common_symbols->s_position)
#define _llllobj_sym_value		(_llllobj_common_symbols->s_value)
#define _llllobj_sym_thresh		(_llllobj_common_symbols->s_thresh)

#define _llllobj_sym_names		(_llllobj_common_symbols->s_names)
#define _llllobj_sym_usecustomnumber		(_llllobj_common_symbols->s_usecustomnumber)
#define _llllobj_sym_usecustomboxes		(_llllobj_common_symbols->s_usecustomboxes)
#define _llllobj_sym_number		(_llllobj_common_symbols->s_number)
#define _llllobj_sym_lockwidth		(_llllobj_common_symbols->s_lockwidth)
#define _llllobj_sym_separate	(_llllobj_common_symbols->s_separate)
#define _llllobj_sym_active	(_llllobj_common_symbols->s_active)
#define _llllobj_sym_openslot	(_llllobj_common_symbols->s_openslot)
#define _llllobj_sym_sample	(_llllobj_common_symbols->s_sample)

#define _llllobj_sym_left	(_llllobj_common_symbols->s_left)
#define _llllobj_sym_right	(_llllobj_common_symbols->s_right)
#define _llllobj_sym_nearest	(_llllobj_common_symbols->s_nearest)
#define _llllobj_sym_header	(_llllobj_common_symbols->s_header)
#define _llllobj_sym_height	(_llllobj_common_symbols->s_height)
#define _llllobj_sym_root	(_llllobj_common_symbols->s_root)

#define _llllobj_sym_mixed    (_llllobj_common_symbols->s_mixed)
#define _llllobj_sym_whole    (_llllobj_common_symbols->s_whole)
#define _llllobj_sym_breakpointortail    (_llllobj_common_symbols->s_breakpointortail)
#define _llllobj_sym_durationline    (_llllobj_common_symbols->s_durationline)
#define _llllobj_sym_transaction    (_llllobj_common_symbols->s_transaction)

#define _llllobj_sym_bachcursors	(_llllobj_common_symbols->s_bachcursors)

#define _llllobj_sym_getdomains	(_llllobj_common_symbols->s_getdomains)
#define _llllobj_sym_setdomains	(_llllobj_common_symbols->s_setdomains)
#define _llllobj_sym_reject     (_llllobj_common_symbols->s_reject)


#define _llllobj_sym_float64_marker			(_llllobj_common_symbols->s_float64_marker)
#define _llllobj_sym_float64_marker_05		(_llllobj_common_symbols->s_float64_marker_05)
#define _llllobj_sym_float64_marker_corrupt	(_llllobj_common_symbols->s_float64_marker_corrupt)


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

extern t_llllobj_common_symbols_table *_llllobj_common_symbols;
extern t_symbol **_llllobj_attributes;
extern char _open_parentheses[3];
extern char _closed_parentheses[3];
extern t_symbol *_open_parentheses_sym[3];
extern t_symbol *_closed_parentheses_sym[3];

t_llllobj_common_symbols_table *llllobj_common_symbols_gettable(void);
t_max_err llllobj_common_symbols_init(void);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _LLLL_COMMONSYMS_H_
