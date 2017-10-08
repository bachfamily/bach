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


#include "llllobj.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 

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

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}

	c = class_new("bach.transcribe", (method)transcribe_new, (method)transcribe_free, (short)sizeof(t_transcribe), 0L, A_GIMME, 0);
	
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

	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);

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
    CLASS_ATTR_STYLE_LABEL(c, "playdelay", 0, "onoff", "Play Delay");
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

    

	class_register(CLASS_BOX, c);
	transcribe_class = c;
	
	dev_post("bach.transcribe compiled %s %s", __DATE__, __TIME__);
	
	return 0;
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


void transcribe_send_unsel(t_transcribe *x, double onset, double cents, long voice)
{
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_unsel);
    llll_appenddouble(out, onset);
    llll_appenddouble(out, onset);
    llll_appenddouble(out, cents);
    llll_appenddouble(out, cents);
    llll_appendlong(out, voice);
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

void transcribe_send_unsel_long(t_transcribe *x, long name)
{
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_unsel);
    llll_appendlong(out, name);
    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, out);
    llll_free(out);
}

void transcribe_send_sel_long(t_transcribe *x, long name)
{
    t_llll *out = llll_get();
    llll_appendsym(out, _llllobj_sym_sel);
    llll_appendlong(out, name);
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


void transcribe_event_noteoff(t_transcribe *x, t_transcribe_event *ev)
{
    if (x->n_use_names)
        transcribe_send_unsel_long(x, ev->n_assigned_name);
    else
        transcribe_send_unsel(x, ev->n_onset, hatom_gettype(&ev->n_pitch) == H_PITCH ? hatom_getpitch(&ev->n_pitch).toMC() : hatom_getdouble(&ev->n_pitch), ev->n_voice);
    llll_destroyelem(ev->n_parent);
    bach_freeptr(ev);
}


void transcribe_allnotesoff(t_transcribe *x)
{
    for (t_llllelem *el = x->n_active_notes->l_head; el; el = el->l_next) {
        t_transcribe_event *ev = (t_transcribe_event *)hatom_getobj(&el->l_hatom);
        if (x->n_use_names)
            transcribe_send_unsel_long(x, ev->n_assigned_name);
        else
            transcribe_send_unsel(x, ev->n_onset, hatom_gettype(&ev->n_pitch) == H_PITCH ? hatom_getpitch(&ev->n_pitch).toMC() : hatom_getdouble(&ev->n_pitch), ev->n_voice);
    }
    transcribe_clear_active_notes(x);
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
                
            } else if (args->l_size >= 4) {
                // input is: pitch, velocity, voice, duration

                t_llll *command = llll_get();
                t_llll *chord = llll_get();
                t_llll *note = llll_get();
                llll_appendsym(command, _llllobj_sym_addchord);
                llll_appendhatom_clone(command, &args->l_head->l_next->l_next->l_hatom);
                llll_appenddouble(chord, t);
                llll_appendhatom_clone(note, &args->l_head->l_hatom);
                llll_appendhatom_clone(note, &args->l_head->l_next->l_next->l_next->l_hatom);
                llll_appendhatom_clone(note, &args->l_head->l_next->l_hatom);
                llll_appendllll(chord, note);
                llll_appendllll(command, chord);
                
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
                    systhread_mutex_unlock(x->n_mutex);
                    
                    if (ev) {
                        transcribe_send_time(x, t);
                        transcribe_send_tail(x, t);
                        transcribe_event_noteoff(x, ev);
                        transcribe_send_inscreenpos(x, t);
                    } else {
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
    *t = 1;
}


void transcribe_free(t_transcribe *x)
{
	long i;
	for (i = 1; i < 2; i++)
		object_free_debug(x->n_proxy[i]);
    
    transcribe_clear_active_notes(x);
    llll_free(x->n_active_notes);
    
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
	
        x->n_clock = clock_new_debug((t_object *)x, (method)transcribe_task);
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
        systhread_mutex_new_debug(&x->n_mutex, 0);
        x->n_qelem = qelem_new_debug((t_object *)x, (method)transcribe_qelem_do);

		attr_args_process(x, ac, av);

		llllobj_obj_setup((t_llllobj_object *) x, 2, "f4");
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}


void transcribe_qelem_do(t_transcribe *x)
{
    double t = transcribe_get_time(x);
    t_llll *tail_ll = llll_get();
    t_llll *inscreenpos_ll = llll_get();

    llll_appendsym(tail_ll, _llllobj_sym_tail);
    llll_appenddouble(tail_ll, t);

    llll_appendsym(inscreenpos_ll, gensym("inscreenpos"));
    llll_appenddouble(inscreenpos_ll, x->n_inscreenpos);
    llll_appenddouble(inscreenpos_ll, t);

    llllobj_outlet_llll((t_object *)x, LLLL_OBJ_VANILLA, 0, tail_ll);
    llll_free(tail_ll);

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

