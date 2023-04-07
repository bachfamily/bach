/*
 *  llll_commonsyms.c
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

#include "foundation/bach.h"

#define BACH_MAX_ATTRS 1024 
#ifdef BACH_MAX
#include "ext.h"
#include "ext_obex.h"
#endif

#ifdef BACH_JUCE
#include "bach_jucewrapper.h"
#endif

#include "foundation/llll_commonsyms.h"

t_llllobj_common_symbols_table *_llllobj_common_symbols;

char _open_parentheses[3] = {'(', '[', '{'};
char _closed_parentheses[3] = {')', ']', '}'};
t_symbol *_open_parentheses_sym[3];
t_symbol *_closed_parentheses_sym[3];

t_max_err llllobj_common_symbols_init(void)
{
    if ((_llllobj_common_symbols = llllobj_common_symbols_gettable()))
        return MAX_ERR_NONE;
    else 
        return MAX_ERR_GENERIC;
}

t_llllobj_common_symbols_table *llllobj_common_symbols_gettable()
{
    t_llllobj_common_symbols_table *x;
    
    x = (t_llllobj_common_symbols_table *) sysmem_newptr(sizeof (t_llllobj_common_symbols_table));
    
    _open_parentheses_sym[0] = x->s_open_round_bracket = gensym("(");
    _closed_parentheses_sym[0] = x->s_closed_round_bracket = gensym(")");
    _open_parentheses_sym[1] = x->s_open_square_bracket = gensym("[");
    _closed_parentheses_sym[1] = x->s_closed_square_bracket = gensym("]");
    _open_parentheses_sym[2] = x->s_open_curly_bracket = gensym("{");
    _closed_parentheses_sym[2] = x->s_closed_curly_bracket = gensym("}");
    
    x->s_llllconnect = gensym("llll.connect");
    x->s_parse = gensym("parse");
    x->s_destroy = gensym("destroy");
    x->s_nil = gensym("nil");
    x->s_null = gensym("null");
    x->s_i = gensym("i");
    x->s_r = gensym("r");
    x->s_f = gensym("f");
    x->s_s = gensym("s");
    x->s_n = gensym("n");
    x->s_l = gensym("l");
    x->s_o = gensym("o");
    x->s_p = gensym("p");
    x->s_t = gensym("t");
    x->s_g = gensym("g");
    x->s_m = gensym("m");
    x->s_unknown = gensym("unknown");
    x->s_all = gensym("all");
    x->s_any = gensym("any");
    x->s_each = gensym("each");
    x->s_same = gensym("same");
    x->s_goto = gensym("goto");
    x->s_clear = gensym("clear");
    x->s_bach_lexpr = gensym("bach.lexpr");
    x->s_bach_collector = gensym("bach.collector");
    x->s_bach_llll = gensym("bach.llll");
    x->s_bach_llllelem = gensym("bach.llllelem");
    x->s_eval = gensym("eval");
    x->s_get = gensym("get");
    x->s_command = gensym("command");
    x->s__llll = gensym("_llll");
    x->s__llllelem = gensym("_llllelem");
    x->s_clone = gensym("clone");
    x->s_copy = gensym("copy");
    x->s_deparse = gensym("deparse");
    x->s_top = gensym("top");
    x->s_back = gensym("back");
    x->s_clearall = gensym("clearall");
    x->s_collection = gensym("collection");
    x->s_out = gensym("out");
    x->s_vars = gensym("vars");
    x->s_string = gensym("string");

    x->s___llll_primes__ = gensym("__llll_primes__");

    x->s_roll = gensym("roll");
    x->s_score = gensym("score");
    x->s_graphic = gensym("graphic");
    x->s_breakpoints = gensym("breakpoints");
    x->s_articulations = gensym("articulations");
    x->s_articulationinfo = gensym("articulationinfo");
    x->s_noteheadinfo = gensym("noteheadinfo");
    x->s_notehead = gensym("notehead");
    x->s_noteheads = gensym("noteheads");
    x->s_annotation = gensym("annotation");
    x->s_numparts = gensym("numparts");
    x->s_parts = gensym("parts");
    x->s_slots = gensym("slots");
    x->s_function = gensym("function");
    x->s_int = gensym("int");
    x->s_float = gensym("float");
    x->s_text = gensym("text");
    x->s_llll = gensym("llll");
    x->s_intlist = gensym("intlist");
    x->s_floatlist = gensym("floatlist");
    x->s_intmatrix = gensym("intmatrix");
    x->s_floatmatrix = gensym("floatmatrix");
    x->s_togglematrix = gensym("togglematrix");
    x->s_filelist = gensym("filelist");
    x->s_spat = gensym("spat");
    x->s_filter = gensym("filter");
    x->s_dynfilter = gensym("dynfilter");
    x->s_color = gensym("color");
    x->s_3dfunction = gensym("3dfunction");
    x->s_dynamics = gensym("dynamics");
    x->s_access = gensym("access");
    x->s_readonly = gensym("readonly");
    x->s_readandwrite = gensym("readandwrite");
    
    x->s_none = gensym("none");
    x->s_onset = gensym("onset");
    x->s_onsets = gensym("onsets");
    x->s_cent = gensym("cent");
    x->s_cents = gensym("cents");
    x->s_deltacents = gensym("deltacents");
    x->s_duration = gensym("duration");
    x->s_durations = gensym("durations");
    x->s_velocity = gensym("velocity");
    x->s_velocities = gensym("velocities");
    x->s_extra = gensym("extra");
    x->s_extras = gensym("extras");
    x->s_slotinfo = gensym("slotinfo");
    x->s_start = gensym("start");
    x->s_end = gensym("end");
    x->s_note = gensym("note");
    x->s_chord = gensym("chord");
    x->s_rest = gensym("rest");
    x->s_symduration = gensym("symduration");
    x->s_symonset = gensym("symonset");
    x->s_symtail = gensym("symtail");
    x->s_dumpselection = gensym("dumpselection");
    x->s_state = gensym("state");
    x->s_tillnext = gensym("tillnext");

    x->s_FFGG = gensym("FFGG");
    x->s_FFG = gensym("FFG");
    x->s_FGG = gensym("FGG");
    x->s_FF = gensym("FF");
    x->s_GG = gensym("GG");
    x->s_FG = gensym("FG");
    x->s_F = gensym("F");
    x->s_G = gensym("G");
    x->s_G15 = gensym("G15");
    x->s_F15 = gensym("F15");
    x->s_G8 = gensym("G8");
    x->s_F8 = gensym("F8");
    x->s_Soprano = gensym("Soprano");
    x->s_Mezzo = gensym("Mezzo");
    x->s_Alto = gensym("Alto");
    x->s_Tenor = gensym("Tenor");
    x->s_Barytone = gensym("Barytone");
    x->s_Bass = gensym("Bass");
    x->s_Percussion = gensym("Percussion");
    x->s_GF = gensym("GF");
    x->s_GGFF = gensym("GGFF");
    x->s_GFF = gensym("GFF");
    x->s_GGF = gensym("GGF");
    x->s_G8va = gensym("G8va");
    x->s_G8vb = gensym("G8vb");
    x->s_G15ma = gensym("G15ma");
    x->s_G15mb = gensym("G15mb");
    x->s_F8va = gensym("F8va");
    x->s_F8vb = gensym("F8vb");
    x->s_F15ma = gensym("F15ma");
    x->s_F15mb = gensym("F15mb");

    x->s_ID = gensym("ID");
    x->s_domain = gensym("domain");
    x->s_length = gensym("length");
    x->s_insertvoice = gensym("insertvoice");
    x->s_deletevoice = gensym("deletevoice");
    x->s_addchord = gensym("addchord");
    x->s_gluechord = gensym("gluechord");
    x->s_midichannels = gensym("midichannels");
    x->s_list = gensym("list");
    x->s_measureinfo = gensym("measureinfo");
    x->s_measure = gensym("measure");
    x->s_measures = gensym("measures");
    x->s_division = gensym("division");
    x->s_subdivision = gensym("subdivision");
    x->s_tie = gensym("tie");
    x->s_ties = gensym("ties");
    x->s_score2roll = gensym("score2roll");
    x->s_cursor = gensym("cursor");
    x->s_commands = gensym("commands");
    x->s_play = gensym("play");
    x->s_playout = gensym("playout");
    x->s_stop = gensym("stop");
    x->s_pause = gensym("pause");
    x->s_clefs = gensym("clefs");
    x->s_keys = gensym("keys");
    x->s_markers = gensym("markers");
    x->s_marker = gensym("marker");
    x->s_groups = gensym("groups");
    x->s_voicespacing = gensym("voicespacing");
    x->s_hidevoices = gensym("hidevoices");
    x->s_addtempo = gensym("addtempo");
    x->s_addmeasure = gensym("addmeasure");
    x->s_addmeasures = gensym("addmeasures");
    x->s_appendmeasure = gensym("appendmeasure");
    x->s_appendmeasures = gensym("appendmeasures");
    x->s_insertmeasure = gensym("insertmeasure");
    x->s_insertmeasures = gensym("insertmeasures");
    x->s_addchords = gensym("addchords");
    x->s_slope = gensym("slope");
    x->s_representation = gensym("representation");
    x->s_ysnap = gensym("ysnap");
    x->s_zsnap = gensym("zsnap");
    x->s_body = gensym("body");
    x->s_name = gensym("name");
    x->s_type = gensym("type");
    x->s_key = gensym("key");
    x->s_range = gensym("range");
    x->s_pixel = gensym("pixel");
    x->s_time = gensym("time");
    x->s_timepoint = gensym("timepoint");
    x->s_voicepixelpos = gensym("voicepixelpos");
    x->s_timeatpixel = gensym("timeatpixel");
    x->s_width = gensym("width");
    x->s_temporal = gensym("temporal");
    x->s_relative = gensym("relative");
    x->s_temporalmode = gensym("temporalmode");
    x->s_extend = gensym("extend");
    x->s_milliseconds = gensym("milliseconds");
    x->s_timepoints = gensym("timepoints");
    x->s_abr_none_abr = gensym("<none>");
    x->s_legato = gensym("legato");
    x->s_legatotrim = gensym("legatotrim");
    x->s_legatoextend = gensym("legatoextend");
    x->s_glissando = gensym("glissando");
    x->s_glissandotrim = gensym("glissandotrim");
    x->s_glissandoextend = gensym("glissandoextend");
    x->s_voicenames = gensym("voicenames");
    x->s_dyn = gensym("dyn");
    x->s_dynamic = gensym("dynamic");
    x->s_lambda = gensym("lambda");
    x->s_tail = gensym("tail");
    x->s_eraseslot = gensym("eraseslot");
    x->s_changeslotvalue = gensym("changeslotvalue");
    x->s_changeslotitem = gensym("changeslotitem");
    x->s_addslotitem = gensym("addslotitem");
    x->s_appendslotitem = gensym("appendslotitem");
    x->s_prependslotitem = gensym("prependslotitem");
    x->s_insertslotitem = gensym("insertslotitem");
    x->s_deleteslotitem = gensym("deleteslotitem");
    x->s_addslot = gensym("addslot");
    x->s_setslot = gensym("setslot");
    x->s_setdurationline = gensym("setdurationline");
    x->s_addbreakpoint = gensym("addbreakpoint");
    x->s_erasebreakpoints = gensym("erasebreakpoints");
    x->s_widthfactor = gensym("widthfactor");
    x->s_currentchord = gensym("currentchord");
    x->s_Auto = gensym("Auto");
    x->s_auto = gensym("auto");
    x->s_domainslope = gensym("domainslope");
    x->s_label = gensym("label");
    x->s_shownumber = gensym("shownumber");
    x->s_off = gensym("off");
    x->s_on = gensym("on");
    x->s_barline = gensym("barline");
    x->s_boxes = gensym("boxes");
    x->s_if = gensym("if");
    x->s_singleslotfortiednotes = gensym("singleslotfortiednotes");
    x->s_copywhensplit = gensym("copywhensplit");
    x->s_follownotehead = gensym("follownotehead");
    x->s_default = gensym("default");
    x->s_quantize = gensym("quantize");
    x->s_zrange = gensym("zrange");
    x->s_zslope = gensym("zslope");
    x->s_direction = gensym("direction");
    x->s_focus = gensym("focus");

    x->s_add = gensym("add");
    x->s_insert = gensym("insert");
    x->s_remove = gensym("remove");
    x->s_change = gensym("change");

    x->s_display = gensym("display");
    x->s_lowpass = gensym("lowpass");
    x->s_highpass = gensym("highpass");
    x->s_bandpass = gensym("bandpass");
    x->s_bandstop = gensym("bandstop");
    x->s_peaknotch = gensym("peaknotch");
    x->s_lowshelf = gensym("lowshelf");
    x->s_highshelf = gensym("highshelf");
    x->s_resonant = gensym("resonant");
    x->s_allpass = gensym("allpass");
    
    x->s_point = gensym("point");

    x->s_sel = gensym("sel");
    x->s_unsel = gensym("unsel");
    x->s_subsel = gensym("subsel");
    x->s_selmeasures = gensym("selmeasures");
    x->s_unselmeasures = gensym("unselmeasures");

    x->s_leveltype = gensym("leveltype");
    x->s_tupletunit = gensym("tupletunit");
    x->s_tupletdur = gensym("tupletdur");
    x->s_tupletpregressedratio = gensym("tupletpregressedratio");
    x->s_tupletinfo = gensym("tupletinfo");

    x->s_no_name = gensym("no name");
    x->s_empty_symbol = gensym("");
    x->s_setinterleaved = gensym("setinterleaved");
    x->s_transpose = gensym("transpose");
    x->s_complement = gensym("complement");
    x->s_invert = gensym("invert");
    x->s_inf = gensym("inf");
    x->s_error = gensym("error");
    x->s_endeditbox = gensym("endeditbox");
    x->s_frame = gensym("frame");
    x->s_begin_preset = gensym("begin_preset");
    x->s_restore_preset = gensym("restore_preset");
    x->s_end_preset = gensym("end_preset");
    x->s_discardgrace = gensym("discardgrace");
    x->s_discardgracerests = gensym("discardgracerests");
    x->s_trytoavoidgrace = gensym("trytoavoidgrace");
    x->s_gracedeletethresh = gensym("gracedeletethresh");
    x->s_1_16 = gensym("1/16");
    x->s_1_12 = gensym("1/12");
    x->s_vzoom = gensym("vzoom");
    x->s_gridperiodms = gensym("gridperiodms");
    x->s_numgridsubdivisions = gensym("numgridsubdivisions");
    x->s_Courier = gensym("Courier");
    x->s_questionmark = gensym("?");
    x->s_lock = gensym("lock");
    x->s_mute = gensym("mute");
    x->s_solo = gensym("solo");
    x->s_background = gensym("background");
    x->s_popup = gensym("popup");
    x->s_linkto = gensym("linkto");
    x->s_rightclick = gensym("rightclick");
    x->s_lyrics = gensym("lyrics");
    x->s_notecolor = gensym("notecolor");
    x->s_dlcolor = gensym("dlcolor");
    x->s_noteheadadjust = gensym("noteheadadjust");
    x->s_noteheadfont = gensym("noteheadfont");
    x->s_noteheadchar = gensym("noteheadchar");
    x->s_notesize = gensym("notesize");
    x->s_grace = gensym("grace");
    x->s_tempo = gensym("tempo");
    x->s_quartertempo = gensym("quartertempo");
    x->s_figure = gensym("figure");
    x->s_interp = gensym("interp");
    x->s_prepad = gensym("prepad");
    x->s_lockrhythmictree = gensym("lockrhythmictree");
    x->s_clef = gensym("clef");
    x->s_mode = gensym("mode");
    x->s_accpattern = gensym("accpattern");
    x->s_midichannel = gensym("midichannel");
    x->s_attach = gensym("attach");
    x->s_voice = gensym("voice");
    x->s_pim = gensym("pim");
    x->s_stafflines = gensym("stafflines");
    x->s_timesig = gensym("timesig");
    x->s_role = gensym("role");
    x->s_loop = gensym("loop");
    x->s_flags = gensym("flags");
    x->s_flag = gensym("flag");
    x->s_path = gensym("path");
    x->s_painted = gensym("painted");

    x->s_prev = gensym("prev");
    x->s_next = gensym("next");
    
    x->s_notes = gensym("notes");
    x->s_breakpoint = gensym("breakpoint");
    x->s_chords = gensym("chords");
    x->s_rests = gensym("rests");
    x->s_region = gensym("region");
    x->s_scrollbar = gensym("scrollbar");
    x->s_scrollbars = gensym("scrollbars");
    x->s_voices = gensym("voices");
    x->s_tempi = gensym("tempi");
    x->s_slot = gensym("slot");
    x->s_articulation = gensym("articulation");
    x->s_slur = gensym("slur");
    x->s_slurs = gensym("slurs");
    x->s_zoom = gensym("zoom");
    x->s_barlines = gensym("barlines");
    x->s_timesignature =  gensym("timesignature");
    x->s_timesignatures =  gensym("timesignatures");
    x->s_inspector =  gensym("inspector");
    x->s_tails =  gensym("tails");
    x->s_selection =  gensym("selection");
    x->s_group = gensym("group");
    x->s_pitch = gensym("pitch");
    x->s_poc = gensym("poc");
    x->s_pitches = gensym("pitches");
    x->s_rhythmictree = gensym("rhythmictree");
    x->s_dilationrectangle = gensym("dilationrectangle");
    x->s_popupmenu = gensym("popupmenu");
    
    
    x->s_create =  gensym("create");
    x->s_delete =  gensym("delete");
    x->s_modify =  gensym("modify");
    x->s_position =  gensym("position");
    x->s_value =  gensym("value");
    x->s_thresh =  gensym("thresh");
    
    x->s_slur = gensym("slur");
    x->s_slurs = gensym("slurs");

    x->s_names = gensym("names");
    x->s_usecustomnumber = gensym("usecustomnumber");
    x->s_usecustomboxes = gensym("usecustomboxes");
    x->s_number = gensym("number");
    x->s_lockwidth = gensym("lockwidth");
    x->s_separate = gensym("separate");
    x->s_active = gensym("active");
    x->s_openslot = gensym("openslot");
    x->s_sample = gensym("sample");

    x->s_left = gensym("left");
    x->s_right = gensym("right");
    x->s_nearest = gensym("nearest");
    x->s_header = gensym("header");
    x->s_height = gensym("height");
    x->s_root = gensym("root");

    
    x->s_mixed = gensym("mixed");
    x->s_whole = gensym("whole");
    x->s_durationline = gensym("durationline");
    x->s_transaction = gensym("transaction");

    x->s_bachcursors = gensym("bachcursors");
    x->s_getdomains = gensym("getdomains");
    x->s_setdomains = gensym("setdomains");
    x->s_reject = gensym("reject");

    x->s_float64_marker = gensym(LLLL_FLOAT64_MARKER);
    x->s_float64_marker_05 = gensym(LLLL_FLOAT64_MARKER_05);
    x->s_float64_marker_corrupt = gensym(LLLL_FLOAT64_MARKER_CORRUPT);
    
    return x;
}
