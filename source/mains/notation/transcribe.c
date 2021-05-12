/*
 *  transcribe.c
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

/**
	@file
	transcribe.c
	
	@name
	bach.transcribe
	
	@realname
	bach.transcribe
 
	@type
	object
	
	@module
	bach
 
	@author
	bachproject
	
	@digest
	Fills a <o>bach.roll</o> according to incoming MIDI data
	
	@description
	The purpose of <o>bach.transcribe</o> is to act as a machine which, when turned on,
	receives data containing cents, velocities and voice numbers (and optional durations),
	and properly adds in real time the notes in the
	connected <o>bach.roll</o> object.
	
	@discussion
	<o>bach.transcribe</o> is note-based: each MIDI triplets
	refers to a note. If you want, a posteriori, to align notes into chords,
	you should look at <o>bach.roll</o>'s <m>merge</m> message.
 
	@category
	bach, bach objects, bach notation
 
	@keywords
	transcribe, write, fill, MIDI, stream, pitch, velocity, cent, midicent, voice, number, duration,
	insert, note, proportional
	
	@seealso
	bach.roll, bach.quantize, bach.ezmidiplay, Real Time Stories
	
	@owner
	Daniele Ghisi
 */


#include "foundation/llllobj.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 
#include "foundation/llll_commons_ext.h"
#include "notation/notation.h"

typedef struct _transcribe_event
{
    double  n_onset;
    t_hatom n_pitch;
    long    n_voice;
    long    n_velocity;
    long    n_assigned_name;
    t_llllelem  *n_parent;
} t_transcribe_event;


typedef struct _transcribe
{
	struct llllobj_object 	n_ob;
	
    long    n_transcribing;
    
    void    *n_clock;
    void    *n_qelem;
    double  n_transcribe_start_time;

    t_llll  *n_active_notes;
    t_hatom *n_active_slotitems[CONST_MAX_VOICES + 1];
    long    n_max_active_voice;
    long    n_max_active_slotnum;

    // attributes
    double  n_refresh;
    double  n_inscreenpos;
    long    n_play;
    double  n_playdelay;
    long    n_autoclear;
    
    long    n_use_Max_logical_time;
    long    n_use_names;
    long    n_curr_name;
    

	void				*n_proxy[2];
	long				n_in;

    long    n_verbose;
    t_systhread_mutex	n_mutex;

} t_transcribe;


void transcribe_assist(t_transcribe *x, void *b, long m, long a, char *s);
void transcribe_inletinfo(t_transcribe *x, void *b, long a, char *t);

t_transcribe *transcribe_new(t_symbol *s, short ac, t_atom *av);
void transcribe_free(t_transcribe *x);

void transcribe_bang(t_transcribe *x);
void transcribe_int(t_transcribe *x, t_atom_long num);
void transcribe_float(t_transcribe *x, double num);
void transcribe_anything(t_transcribe *x, t_symbol *msg, long ac, t_atom *av);
void transcribe_allnotesoff(t_transcribe *x);

void transcribe_task(t_transcribe *x);
void transcribe_qelem_do(t_transcribe *x);
double transcribe_get_time(t_transcribe *x);

t_class *transcribe_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}

    CLASS_NEW_CHECK_SIZE(c, "bach.transcribe", (method)transcribe_new, (method)transcribe_free, (long) sizeof(t_transcribe), 0L, A_GIMME, 0);
	
    // @method list @digest Transcribe MIDI triplets/quadruplets
    // @description A <m>list</m> in the second inlet is expected to be in the form of a MIDI triplet containing three integers:
    // <b><m>cents</m> <m>velocity</m> <m>voice_number</m></b>. When <m>velocity</m> is strictly positive,
    // this triplet represents a note, in the voice defined by the <m>voice_number</m>, which starts in the exact
    // moment the triplet has been sent, and has the introduced <m>cents</m> as pitch. In this case,
    // the appropriate messages to add a note are sent to the the possibly connected <o>bach.roll</o>.
    // The note duration is regularly updated (see the <m>refresh</m> attribute), until a note-off event
    // is received concerning the specific note. At any new received triplets or refreshing, the current
    // time is also output from the second outlet, and the screen position is refreshed (see <m>inscreenpos</m> attribute).
    // Note-off events are simply represented by triplet having <m>velocity</m> zero. <br />
    // For instance, a triplet <b>6000 70 1</b> adds a middle C having velocity of 70 in the first voice.
    // To turn such note off, you'll need to send a note-off triplet <b>6000 0 1</b>. <br />
    // If one more element is given in the third inlet (thus a MIDI quadruplet is input), such element is considered to be
    // the duration of the note in milliseconds. For such note, there will be no need to send any note-off: the note
    // is simply added with its complete duration as soon as the quadruplet is entered.
    
    // @method llll @digest Transcribe whole roll
    // @description An <m>llll</m> in the <o>bach.roll</o> gathered syntax in the second inlet will be considered as a whole roll
    // to be transcribed.

    // @method slot @digest Record temporal slot data
    // @description A <m>slot</m> message followed by a slot number <m>N</m> and a value <m>V</m> will assume that slot <m>N</m> is a
    // temporal slot with <m>temporalmode</m> "Milliseconds" and will record the value <m>V</m> as its Y value, corresponding to the 'current'
    // instant. This is a way to easily transcribe continuous controllers.
    // @marg 0 @name slot_number_or_name @optional 0 @type int/symbol
    // @marg 1 @name y_value @optional 0 @type number/llll
    // @mattr voice @type int @default 0 @digest Limit slot assignment to a given voice (0 = all)
    // @mattr interp @type int @default 0 @digest Interpolate linearly between values
    // @mattr prepad @type int @default 0 @digest Prepad slots when first elements come in
    // @example slot 1 0.1 @caption add value 0.1 to slot 1
    // @example slot 1 0.1 @voice 3 @caption The same, but only for notes in voice 3
    // @example slot 1 0.1 @interp 1 @caption The same, and interpolate between different values
    class_addmethod(c, (method)transcribe_anything,					"anything",				A_GIMME,	0);
    
    // @method allnotesoff @digest Send note-off messages for all active notes
    // @description A <m>allnotesoff</m> message ends all notes currently being played.
    class_addmethod(c, (method)transcribe_allnotesoff,					"allnotesoff",	0);
    
    
    // @method int @digest Turn transcription on/off
    // @description A <m>1</m> in the first inlet turns the transcription on: <o>bach.transcribe</o>
    // clears the connected <o>bach.roll</o> (if any) and starts expecting data from
    // its second inlet, in order to add notes in the <o>bach.roll</o>. A <m>0</m> in the first
    // inlet turns the transcription off (incoming dat in the second inlet has no longer effect).
    class_addmethod(c, (method)transcribe_int,						"int",					A_LONG,		0);
	class_addmethod(c, (method)transcribe_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)transcribe_anything,					"list",					A_GIMME,	0);
	class_addmethod(c, (method)transcribe_bang,						"bang",		0);
	
	class_addmethod(c, (method)transcribe_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)transcribe_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

    CLASS_ATTR_DOUBLE(c, "refresh",		0,	t_transcribe, n_refresh);
    CLASS_ATTR_STYLE_LABEL(c, "refresh", 0, "text", "Refresh Time");
    // @description Sets the refresh time in milliseconds. Defaults to 100ms.
    // Use 0 to avoid any refresh, except for when new transcribe data comes in.

    CLASS_ATTR_DOUBLE(c, "inscreenpos",		0,	t_transcribe, n_inscreenpos);
    CLASS_ATTR_STYLE_LABEL(c, "inscreenpos", 0, "text", "Relative Record Head Position");
    // @description Sets the relative position of the record head inside the screen (this is equivalent to the parameter
    // used in <o>bach.roll</o>'s <m>inscreenpos</m> message). Defaults to 0.7.

    CLASS_ATTR_LONG(c, "autoclear",		0,	t_transcribe, n_autoclear);
    CLASS_ATTR_STYLE_LABEL(c, "autoclear", 0, "onoff", "Auto Clear");
    CLASS_ATTR_BASIC(c, "autoclear", 0);
    // @description Toggles the ability to clear the <o>bach.roll</o> whenever a recording starts. Defaults to 1 (on).

    CLASS_ATTR_LONG(c, "play",		0,	t_transcribe, n_play);
    CLASS_ATTR_STYLE_LABEL(c, "play", 0, "onoff", "Also Play");
    CLASS_ATTR_BASIC(c, "play", 0);
    // @description Toggles the ability to also play the <o>bach.roll</o> while recording, with a delay given by the <m>playdelay</m> attribute.
    // Defaults to 0 (off).

    CLASS_ATTR_DOUBLE(c, "playdelay",		0,	t_transcribe, n_playdelay);
    CLASS_ATTR_STYLE_LABEL(c, "playdelay", 0, "text", "Play Delay");
    CLASS_ATTR_BASIC(c, "playdelay", 0);
    // @description Sets a delay in millisecond between the record head and the play head. Defaults to 250ms.
    // Only meaningful if the <m>play</m> attribute is on.


    CLASS_ATTR_LONG(c, "logical",		0,	t_transcribe, n_use_Max_logical_time);
    CLASS_ATTR_STYLE_LABEL(c, "logical", 0, "onoff", "Use Max Logical Time");
    // @description Toggles the ability to use Max logical time instead of CPU time.
    // By default this is off, so that time is retrieved from the CPU clock and can be used
    // to time real world events with microsecond precision

    CLASS_ATTR_LONG(c, "usenames",		0,	t_transcribe, n_use_names);
    CLASS_ATTR_STYLE_LABEL(c, "usenames", 0, "onoff", "Use Names While Transcribing");
    CLASS_ATTR_BASIC(c, "usenames", 0);
    // @description Toggles the ability to use assign names to chords while transcribing, in order to allow
    // a more accurate retrieval. Defaults to 0 (off).

    
    CLASS_ATTR_LONG(c, "verbose", 0, t_transcribe, n_verbose);
    CLASS_ATTR_STYLE_LABEL(c,"verbose",0,"onoff","Post Warnings");
    // @description Toggles the ability to post warning signs for incoming data
    
	class_register(CLASS_BOX, c);
	transcribe_class = c;
	
	dev_post("bach.transcribe compiled %s %s", __DATE__, __TIME__);
	
	return;
}


void transcribe_send_time(t_transcribe *x, double t)
{
    llllobj_outlet_float((t_object *)x, LLLL_OBJ_VANILLA, 1, t);
}


void transcribe_send_play_message(t_transcribe *x, t_symbol *s, long ac, t_atom *av)
{
    if (ac) {
        t_llll *out = llll_get();
        double t = atom_getfloat(av);
        llll_appendsym(out, _llllobj_sym_play);
        llll_appenddouble(out, t);
        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
        llll_free(out);
    } else {
        llllobj_outlet_symbol_as_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_play);
    }
}

t_max_err transcribe_setattr_play(t_transcribe *x, t_object *attr, long ac, t_atom *av)
{
    if (x->n_transcribing) {
        if (ac && atom_getlong(av)) {
            x->n_play = 1;
            
            t_atom a;
            atom_setfloat(&a, transcribe_get_time(x));
            schedule_delay(x, (method) transcribe_send_play_message, x->n_playdelay, NULL, 1, &a);
        } else {
            x->n_play = 0;
            llllobj_outlet_symbol_as_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_stop);
        }
    }
    return MAX_ERR_NONE;
}



void transcribe_free_active_slotitems(t_transcribe *x)
{
    for (long i = 0; i <= CONST_MAX_VOICES && i <= x->n_max_active_voice; i++) {
        for (long j = 0; j <= CONST_MAX_SLOTS && j <= x->n_max_active_slotnum; j++)
        if (x->n_active_slotitems[i][j].h_type != H_NULL) {
            if (hatom_gettype(&x->n_active_slotitems[i][j]) == H_LLLL)
                llll_free(hatom_getllll(&x->n_active_slotitems[i][j]));
            x->n_active_slotitems[i][j].h_type = H_NULL;
        }
    }
    
    x->n_max_active_slotnum = 0;
    x->n_max_active_voice = 0;
}


double transcribe_get_time(t_transcribe *x)
{
    double t;
    double start_time;
    
    systhread_mutex_lock(x->n_mutex);
    start_time = x->n_transcribe_start_time;
    systhread_mutex_unlock(x->n_mutex);
    
    if (x->n_use_Max_logical_time)
        clock_getftime(&t);
    else
        t = systimer_gettime();
    
    return t - start_time;
}



void transcribe_send_inscreenpos(t_transcribe *x, double t)
{
    t_llll *out = llll_get();
    double pos = x->n_inscreenpos;
    llll_appendsym(out, gensym("inscreenpos"));
    llll_appenddouble(out, CLAMP(pos, 0., 1.));
    llll_appenddouble(out, t);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
    llll_free(out);
}

void transcribe_send_tail(t_transcribe *x, double t)
{
    t_llll *out = llll_get();
    llll_appendsym(out, gensym("tail"));
    llll_appenddouble(out, t);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
    llll_free(out);
}


t_llll *transcribe_get_unsel_llll(t_transcribe *x, double onset, double cents, long voice)
{
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_unsel);
    llll_appenddouble(out, onset);
    llll_appenddouble(out, onset);
    llll_appenddouble(out, cents);
    llll_appenddouble(out, cents);
    llll_appendlong(out, voice);
    return out;
}


void transcribe_send_unsel(t_transcribe *x, double onset, double cents, long voice)
{
    t_llll *out = transcribe_get_unsel_llll(x, onset, cents, voice);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
    llll_free(out);
}

void transcribe_send_sel(t_transcribe *x, double onset, double cents, long voice)
{
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_sel);
    llll_appenddouble(out, onset);
    llll_appenddouble(out, onset);
    llll_appenddouble(out, cents);
    llll_appenddouble(out, cents);
    llll_appendlong(out, voice);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
    llll_free(out);
}

t_llll *transcribe_get_unsel_long_llll(t_transcribe *x, long name)
{
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_unsel);
    llll_appendlong(out, name);
    return out;
}

t_llll *transcribe_get_sel_long_llll(t_transcribe *x, long name)
{
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_sel);
    llll_appendlong(out, name);
    return out;
}

void transcribe_send_unsel_long(t_transcribe *x, long name)
{
    t_llll *out = transcribe_get_unsel_long_llll(x, name);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
    llll_free(out);
}

void transcribe_bang(t_transcribe *x)
{
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		transcribe_anything(x, _sym_bang, 0, NULL);
	else {
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}


void transcribe_clear_active_notes(t_transcribe *x)
{
    for (t_llllelem *el = x->n_active_notes->l_head; el; el = el->l_next)
        bach_freeptr(hatom_getobj(&el->l_hatom));
    llll_clear(x->n_active_notes);
}


// return noteoff llll
t_llll *transcribe_event_noteoff(t_transcribe *x, t_transcribe_event *ev)
{
    t_llll *out;
    if (x->n_use_names)
        out = transcribe_get_unsel_long_llll(x, ev->n_assigned_name);
    else
        out = transcribe_get_unsel_llll(x, ev->n_onset, hatom_gettype(&ev->n_pitch) == H_PITCH ? hatom_getpitch(&ev->n_pitch).toMC() : hatom_getdouble(&ev->n_pitch), ev->n_voice);
    llll_destroyelem(ev->n_parent);
    bach_freeptr(ev);
    return out;
}


void transcribe_allnotesoff(t_transcribe *x)
{
    transcribe_send_tail(x, transcribe_get_time(x));
    systhread_mutex_lock(x->n_mutex);
    for (t_llllelem *el = x->n_active_notes->l_head; el; el = el->l_next) {
        t_transcribe_event *ev = (t_transcribe_event *)hatom_getobj(&el->l_hatom);
        if (x->n_use_names)
            transcribe_send_unsel_long(x, ev->n_assigned_name);
        else
            transcribe_send_unsel(x, ev->n_onset, hatom_gettype(&ev->n_pitch) == H_PITCH ? hatom_getpitch(&ev->n_pitch).toMC() : hatom_getdouble(&ev->n_pitch), ev->n_voice);
    }
    transcribe_clear_active_notes(x);
    systhread_mutex_unlock(x->n_mutex);
}


void transcribe_record(t_transcribe *x)
{
    long play = 0;
    double refresh = 0, playdelay = 0;

    systhread_mutex_lock(x->n_mutex);
    play = x->n_play;
    refresh = x->n_refresh;
    playdelay = x->n_playdelay;
    
    if (x->n_use_Max_logical_time)
        clock_getftime(&x->n_transcribe_start_time);
    else
        x->n_transcribe_start_time = systimer_gettime();
    x->n_transcribing = 1;
    systhread_mutex_unlock(x->n_mutex);
    
    if (refresh > 0)
        clock_fdelay(x->n_clock, refresh);

    transcribe_free_active_slotitems(x);
    
    if (x->n_autoclear) {
        x->n_curr_name = 0;
        llllobj_outlet_symbol_as_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_clear);
        transcribe_send_inscreenpos(x, 0);
    }
    
    if (play) {
        schedule_delay(x, (method) transcribe_send_play_message, playdelay, NULL, 0, NULL);
    }
}

void transcribe_stop(t_transcribe *x)
{
    systhread_mutex_lock(x->n_mutex);
    x->n_transcribing = 0;
    systhread_mutex_unlock(x->n_mutex);
    clock_unset(x->n_clock);
    qelem_unset(x->n_qelem);
    transcribe_allnotesoff(x);
    if (x->n_play)
        llllobj_outlet_symbol_as_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_stop);
}

void transcribe_int(t_transcribe *x, t_atom_long num)
{
    long transcribing = x->n_transcribing;

    if (num == transcribing)
        return; // nothing to do
    
    // Turn machine on/off
    if (num) {
        transcribe_record(x);
    } else {
        transcribe_stop(x);
    }
}

void transcribe_float(t_transcribe *x, double num)
{
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	transcribe_anything(x, _llllobj_sym_list, 1, argv);
}


long transcribe_are_hatom_equal(t_hatom *h1, t_hatom *h2)
{
    long t1 = hatom_gettype(h1);
    long t2 = hatom_gettype(h2);
    
    if (t1 != t2)
        return 0;
    
    switch (t1) {
        case H_PITCH:
            if (hatom_getpitch(h1) != hatom_getpitch(h2))
                return 0;
            break;
            
        case H_LONG:
        case H_DOUBLE:
        case H_RAT:
            if (hatom_getdouble(h1) != hatom_getdouble(h2))
                return 0;
            break;

        case H_SYM:
            if (hatom_getsym(h1) != hatom_getsym(h2))
                return 0;
            break;

        default:
            break;
    }
    
    return 1;
}

t_transcribe_event *transcribe_retrieve(t_transcribe *x, long voice, t_hatom *pitch)
{
    for (t_llllelem *el = x->n_active_notes->l_head; el; el = el->l_next) {
        t_transcribe_event *ev = (t_transcribe_event *)hatom_getobj(&el->l_hatom);
        if (ev->n_voice == voice && transcribe_are_hatom_equal(pitch, &ev->n_pitch))
            return ev;
    }
    return NULL;
}

void transcribe_anything(t_transcribe *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);

	if (inlet == 1 && x->n_transcribing) {
        t_llll *args = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
		
        
        if (args) {
            // getting current time
            double t = transcribe_get_time(x);
            
            if (args->l_head && hatom_gettype(&args->l_head->l_hatom) == H_SYM && hatom_getsym(&args->l_head->l_hatom) == _llllobj_sym_roll) {
                // Inserting a whole bach.roll
                hatom_setsym(&args->l_head->l_hatom, _llllobj_sym_addchords);
                llll_insertdouble_after(t, args->l_head);

                transcribe_send_time(x, t);
                llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, args);
                transcribe_send_tail(x, t);
                transcribe_send_inscreenpos(x, t);

            } else if (args->l_head && hatom_gettype(&args->l_head->l_hatom) == H_SYM && hatom_getsym(&args->l_head->l_hatom) == _llllobj_sym_slot && args->l_head->l_next) {
                // Inserting a temporal slot item
                t_symbol *temporalmode = _llllobj_sym_milliseconds;
                long voice = 0, interp = 0, prepad = 0;
                llll_parseattrs((t_object *)x, args, LLLL_PA_DESTRUCTIVE, "iiii", _llllobj_sym_temporalmode, &temporalmode, _llllobj_sym_voice, &voice, _llllobj_sym_interp, &interp, _llllobj_sym_prepad, &prepad);
                
                if (temporalmode == _llllobj_sym_milliseconds) {
                    
                    systhread_mutex_lock(x->n_mutex);
                    
                    if (voice > x->n_max_active_voice)
                        x->n_max_active_voice = voice;
                    
                    long slotnum = CLAMP(hatom_getlong(&args->l_head->l_next->l_hatom), 0, CONST_MAX_SLOTS - 1);

                    if (slotnum > x->n_max_active_slotnum)
                        x->n_max_active_slotnum = slotnum;

                    if (!interp && x->n_active_slotitems[voice][slotnum].h_type != H_NULL) {
                        // "noteoff" for the slot item
                        t_llll *command = llll_get();
                        t_llll *point = llll_get();
                        llll_appendsym(command, _llllobj_sym_appendslotitem);
                        llll_appendhatom_clone(command, &args->l_head->l_next->l_hatom);
                        llll_appenddouble(point, t);
                        if (args->l_head->l_next->l_next)
                            llll_appendhatom_clone(point, &x->n_active_slotitems[voice][slotnum]);
                        llll_appendllll(command, point);
                        if (voice > 0) {
                            llll_appendsym(command, gensym("@voice"));
                            llll_appendlong(command, voice);
                        }

                        systhread_mutex_unlock(x->n_mutex);
                        
                        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, command);
                        llll_free(command);

                        systhread_mutex_lock(x->n_mutex);

                    }
                    
                    if (prepad && x->n_active_slotitems[voice][slotnum].h_type == H_NULL && t > 0) {
                        t_llll *command = llll_get();
                        t_llll *point = llll_get();
                        llll_appendsym(command, _llllobj_sym_appendslotitem);
                        llll_appendhatom_clone(command, &args->l_head->l_next->l_hatom);
                        llll_appenddouble(point, 0);
                        if (args->l_head->l_next->l_next)
                            llll_appendhatom_clone(point, &args->l_head->l_next->l_next->l_hatom);
                        llll_appendllll(command, point);
                        if (voice > 0) {
                            llll_appendsym(command, gensym("@voice"));
                            llll_appendlong(command, voice);
                        }
                        
                        systhread_mutex_unlock(x->n_mutex);
                        
                        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, command);
                        llll_free(command);
                        
                        systhread_mutex_lock(x->n_mutex);
                    }
                    
                    t_llll *command = llll_get();
                    t_llll *point = llll_get();
                    llll_appendsym(command, _llllobj_sym_appendslotitem);
                    llll_appendhatom_clone(command, &args->l_head->l_next->l_hatom);
                    llll_appenddouble(point, t);
                    if (args->l_head->l_next->l_next) {
                        llll_appendhatom_clone(point, &args->l_head->l_next->l_next->l_hatom);
                        hatom_change_to_hatom(&x->n_active_slotitems[voice][slotnum], &args->l_head->l_next->l_next->l_hatom);
                    }
                    llll_appendllll(command, point);
                    if (voice > 0) {
                        llll_appendsym(command, gensym("@voice"));
                        llll_appendlong(command, voice);
                    }
                    
                    systhread_mutex_unlock(x->n_mutex);
                    
                    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, command);
                    llll_free(command);
                } else {
                    t_llll *command = llll_get();
                    llll_appendsym(command, _llllobj_sym_setslot);
                    llll_chain(command, llll_subllll(args->l_head->l_next, args->l_tail));
                    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, command);
                    llll_free(command);
                }

            } else if (args->l_size >= 4) {
                // input is: pitch, velocity, voice, duration

                t_llll *command = llll_get();
                t_llll *chord = llll_get();
                t_llll *note = llll_get();

                systhread_mutex_lock(x->n_mutex);
                llll_appendsym(command, _llllobj_sym_addchord);
                llll_appendhatom_clone(command, &args->l_head->l_next->l_next->l_hatom);
                llll_appenddouble(chord, t);
                llll_appendhatom_clone(note, &args->l_head->l_hatom);
                llll_appendhatom_clone(note, &args->l_head->l_next->l_next->l_next->l_hatom);
                llll_appendhatom_clone(note, &args->l_head->l_next->l_hatom);
                llll_appendllll(chord, note);
                llll_appendllll(command, chord);
                systhread_mutex_unlock(x->n_mutex);
                
                transcribe_send_time(x, t);
                llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, command);
                transcribe_send_inscreenpos(x, t);
                
                
            } else if (args && args->l_size >= 2){
                // input is: pitch, velocity, voice
                // we make a new event to keep track of the note ons and note offs.
                
                long voice = (args->l_size >= 3 ? hatom_getlong(&args->l_head->l_next->l_next->l_hatom) : 1);
                long velocity = hatom_getlong(&args->l_head->l_next->l_hatom);
                
                if (velocity > 0) {

                    systhread_mutex_lock(x->n_mutex);
                    t_transcribe_event *ev = (t_transcribe_event *)bach_newptr(sizeof(t_transcribe_event));
                    
                    ev->n_voice = voice;
                    ev->n_velocity = velocity;
                    ev->n_onset = t;
                    ev->n_assigned_name = x->n_use_names ? ++x->n_curr_name : 0;
                    ev->n_pitch = args->l_head->l_hatom;
                    
                    t_llll *command = llll_get();
                    t_llll *chord = llll_get();
                    t_llll *note = llll_get();
                    llll_appendsym(command, _llllobj_sym_addchord);
                    llll_appendlong(command, ev->n_voice);
                    llll_appenddouble(chord, t);
                    llll_appendhatom_clone(note, &ev->n_pitch);
                    llll_appenddouble(note, 0); // duration is 0 at the beginning
                    llll_appendlong(note, ev->n_velocity);
                    if (x->n_use_names) {
                        t_llll *name = llll_get();
                        llll_appendsym(name, _llllobj_sym_name);
                        llll_appendlong(name, ev->n_assigned_name);
                        llll_appendllll(chord, name);
                    }
                    llll_appendllll(chord, note);
                    llll_appendllll(command, chord);
                    llll_appendsym(command, gensym("@sel"));
                    llll_appendlong(command, 1);

                    ev->n_parent = llll_appendobj(x->n_active_notes, ev);
                    systhread_mutex_unlock(x->n_mutex);
                    
                    transcribe_send_time(x, t);
                    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, command);
                    transcribe_send_inscreenpos(x, t);
                } else {
                    // note off
                    t_transcribe_event *ev = NULL;
                    
                    systhread_mutex_lock(x->n_mutex);
                    ev = transcribe_retrieve(x, voice, &args->l_head->l_hatom);
                    
                    if (ev) {
                        t_llll *noteoff_ll = transcribe_event_noteoff(x, ev);
                        
                        systhread_mutex_unlock(x->n_mutex);

                        transcribe_send_time(x, t);
                        transcribe_send_tail(x, t);
                        llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, noteoff_ll);
                        transcribe_send_inscreenpos(x, t);
                    } else {
                        systhread_mutex_unlock(x->n_mutex);
                        if (x->n_verbose)
                            object_warn((t_object *)x, "Unmatched note-off!");
                    }
                }
            }
            
        }
        
        llll_free(args);
	}
}


void transcribe_assist(t_transcribe *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) // @in 0 @type int @digest 1/0 integer turning recording or on
			sprintf(s, "int: 1/0 for Transcribe On/Off");
		else  // @in 1 @type llll @digest Right factor (matrix, vector or scalar)
                // @description The transcribe data can be in the form <b><m>pitch</m> <m>velocity</m> <m>voice</m></b> (where <m>velocity</m> is greater
                // than zeros for note-ons, and zero for note-offs), or in the form <b><m>pitch</m> <m>velocity</m> <m>voice</m> <m>duration_ms</m></b>
                // (in which case no note-off is expected), or in <o>bach.roll</o> gathered syntax (with a <b>roll</b> symbol router).
			sprintf(s, "llll: Transcribe Data (in the simplest case: Cents, Velocity, Voice)");
	} else {
        if (a == 0) {
            char *type = NULL;	// @out 0 @type llll @digest The recording messages for <o>bach.roll</o>
            llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
            sprintf(s, "llll (%s): Messages for bach.roll", type);
        } else {    // @out 1 @type float @digest Current time in milliseconds
            sprintf(s, "float: Current Time in Milliseconds");
        }
	}
}

void transcribe_inletinfo(t_transcribe *x, void *b, long a, char *t)
{
    return; // both inlets are "hot" since turning on/off the recoring (1st inlet) may trigger some output messages (such as clear, etc.),
            // and of course data in the right inlet will trigger the insertion of the recorded notes.
}


void transcribe_free(t_transcribe *x)
{
	long i;
	for (i = 1; i < 2; i++)
		object_free_debug(x->n_proxy[i]);
    
    transcribe_free_active_slotitems(x);
    transcribe_clear_active_notes(x);
    llll_free(x->n_active_notes);

    for (i = 0; i < CONST_MAX_SLOTS; i++)
        bach_freeptr(x->n_active_slotitems[i]);
    
    object_free(x->n_clock);
    systhread_mutex_free_debug(x->n_mutex);
    qelem_free_debug(x->n_qelem);

	llllobj_obj_free((t_llllobj_object *) x);
}

t_transcribe *transcribe_new(t_symbol *s, short ac, t_atom *av)
{
	t_transcribe *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_transcribe *) object_alloc_debug(transcribe_class))) {
        x->n_autoclear = 1;
        x->n_inscreenpos = 0.7;
        x->n_play = 0;
        x->n_refresh = 100;
        x->n_playdelay = 250;
        x->n_use_names = 0;
        x->n_use_Max_logical_time = 0;
        x->n_active_notes = llll_get();
        x->n_verbose = true;
        
        for (long i = 0; i <= CONST_MAX_VOICES; i++)
            x->n_active_slotitems[i] = (t_hatom *)bach_newptr(CONST_MAX_SLOTS * sizeof(t_hatom));
        
        for (long i = 0; i <= CONST_MAX_VOICES; i++)
            for (long j = 0; j < CONST_MAX_SLOTS; j++)
                x->n_active_slotitems[i][j].h_type = H_NULL;
        x->n_max_active_voice = x->n_max_active_slotnum = 0;
        
        x->n_clock = clock_new_debug((t_object *)x, (method)transcribe_task);
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
        systhread_mutex_new_debug(&x->n_mutex, 0);
        x->n_qelem = qelem_new_debug((t_object *)x, (method)transcribe_qelem_do);

		attr_args_process(x, ac, av);

		llllobj_obj_setup((t_llllobj_object *) x, 2, "f4");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}


void transcribe_qelem_do(t_transcribe *x)
{
    double t = transcribe_get_time(x);
    t_llll *tail_ll = llll_get();

    llll_appendsym(tail_ll, _llllobj_sym_tail);
    llll_appenddouble(tail_ll, t);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, tail_ll);
    llll_free(tail_ll);

    t_llll *inscreenpos_ll = llll_get();
    llll_appendsym(inscreenpos_ll, gensym("inscreenpos"));
    llll_appenddouble(inscreenpos_ll, x->n_inscreenpos);
    llll_appenddouble(inscreenpos_ll, t);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, inscreenpos_ll);
    llll_free(inscreenpos_ll);
}

void transcribe_task(t_transcribe *x)
{
    double refresh = 0;
    systhread_mutex_lock(x->n_mutex);
    refresh = x->n_refresh;
    systhread_mutex_unlock(x->n_mutex);
    
    if (x->n_transcribing && x->n_refresh > 0)
        qelem_set(x->n_qelem);
    if (refresh)
        clock_fdelay(x->n_clock, refresh);
}

