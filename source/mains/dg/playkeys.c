/**
 @file
 playkeys.c
 
 @name
 bach.playkeys
 
 @realname
 bach.playkeys
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Extract play information
 
 @description
 Outputs selected parameters of <o>bach.score</o>'s and <o>bach.roll</o>'s playout information.
 
 @discussion
 
 @category
 bach, bach objects, bach notation
 
 @keywords
 keys, play, unpack, unpacknote, parameter, playout, syntax
 
 @seealso
 bach.keys, bach.roll, bach.score
 
 @owner
 Daniele Ghisi
 */


#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "llll_commons_ext.h"

#include "notation.h"



enum playkeys_properties
{
    k_PLAYKEYS_NONE = 0,
    k_PLAYKEYS_TYPE,
    k_PLAYKEYS_ONSET,
    k_PLAYKEYS_SYMONSET,
    k_PLAYKEYS_CENTS,
    k_PLAYKEYS_PITCH,
    k_PLAYKEYS_DURATION,
    k_PLAYKEYS_SYMDURATION,
    k_PLAYKEYS_VELOCITY,
    k_PLAYKEYS_MIDICHANNEL,
    k_PLAYKEYS_TIE,
    k_PLAYKEYS_VOICENUMBER,
    k_PLAYKEYS_PATH,
    k_PLAYKEYS_MEASURENUMBER,
    k_PLAYKEYS_BREAKPOINTS,
    k_PLAYKEYS_MEASUREINFO,
    k_PLAYKEYS_NAME,
    k_PLAYKEYS_FLAGS,
    k_PLAYKEYS_TEMPO,
    k_PLAYKEYS_QUARTERTEMPO,
    k_PLAYKEYS_SLOT,
    k_PLAYKEYS_ALLSLOTS,
    k_PLAYKEYS_CHORDINDEX,
    k_PLAYKEYS_NOTEINDEX,
    k_PLAYKEYS_PLAY,
    k_PLAYKEYS_STOP,
    k_PLAYKEYS_PAUSE,
    k_PLAYKEYS_END,
    k_PLAYKEYS_TAIL,
    k_PLAYKEYS_DYNAMICS,
    k_PLAYKEYS_NOTEHEAD,
    k_PLAYKEYS_ARTICULATIONS,
    k_PLAYKEYS_LYRICS,
    k_PLAYKEYS_ANNOTATION,
    k_PLAYKEYS_ROUTER,
    k_PLAYKEYS_PLAYOFFSET, // due to partial playing
    k_PLAYKEYS_ROLE,
};

enum playkeys_incoming // incoming notation items
{
    k_PLAYKEYS_INCOMING_UNKNOWN             = 0,
    k_PLAYKEYS_INCOMING_ROLLNOTE            = (1 << 1),
    k_PLAYKEYS_INCOMING_SCORENOTE           = (1 << 2),
    k_PLAYKEYS_INCOMING_ROLLCHORD           = (1 << 3),
    k_PLAYKEYS_INCOMING_SCORECHORD          = (1 << 4),
    k_PLAYKEYS_INCOMING_SCOREREST           = (1 << 5),
    k_PLAYKEYS_INCOMING_SCOREMEASURE        = (1 << 6),
    k_PLAYKEYS_INCOMING_MARKER              = (1 << 7),
    k_PLAYKEYS_INCOMING_TEMPO               = (1 << 8),
    k_PLAYKEYS_INCOMING_PLAY                = (1 << 9),
    k_PLAYKEYS_INCOMING_STOP                = (1 << 10),
    k_PLAYKEYS_INCOMING_PAUSE               = (1 << 11),
    k_PLAYKEYS_INCOMING_END                 = (1 << 12),
    k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND    = (1 << 13),
    k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND   = (1 << 14),
    k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND   = (1 << 15),
    k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND  = (1 << 16),
    k_PLAYKEYS_INCOMING_SCOREREST_COMMAND   = (1 << 17),
};


typedef struct _playkeys_key
{
    long        property;                   // one of the playkeys_items
    long        allowed_notationitems;     // a combination of playkeys_incoming
    t_symbol    *allowed_command_router;     // a command router allowed to enter
    t_hatom     specification;              // content: e.g. slot number/name
    long        exists;                     // data actually exist for key
} t_playkeys_key;


typedef struct _playkeys
{
    struct llllobj_object    n_ob;
    
    t_playkeys_key          *n_keys;
    
    long                    n_flattenfornotes;
    long                    n_nullmode;
    long                    n_use_default_breakpoints;
    long                    n_breakpoints_have_velocity;
    
    t_llll                  *n_process;
    long                    n_notationitems_to_process;
    
    t_llll                  *n_note_commands;
    t_llll                  *n_chord_commands;
    t_llll                  *n_rest_commands;

    t_atom                  n_dynamicsslot;
    t_atom                  n_articulationsslot;
    t_atom                  n_lyricsslot;
    t_atom                  n_noteheadslot;
    t_atom                  n_annotationslot;
    
    char                    n_warn_pitchrequestedmidicentreceived;
    char                    n_warn_fullpathrequestedbutnotpresent;
    char                    n_warn_measurenumberneedsfullpath;
    char                    n_warn_chordindexneedsfullpath;
    char                    n_warn_noteindexneedsfullpath;
    
    char                    n_must_iterate_on_output;
    
    t_bach_atomic_lock      n_process_lock;
    
    t_llll                    *n_empty;
} t_playkeys;


DEFINE_LLLL_ATTR_DEFAULT_GETTER(t_playkeys, n_process, playkeys_getattr_process);
t_max_err playkeys_setattr_process(t_playkeys *x, t_object *attr, long ac, t_atom *av);


void playkeys_assist(t_playkeys *x, void *b, long m, long a, char *s);
void playkeys_inletinfo(t_playkeys *x, void *b, long a, char *t);

t_playkeys *playkeys_new(t_symbol *s, short ac, t_atom *av);
void playkeys_free(t_playkeys *x);

void playkeys_bang(t_playkeys *x);
void playkeys_int(t_playkeys *x, t_atom_long v);
void playkeys_float(t_playkeys *x, double v);
void playkeys_anything(t_playkeys *x, t_symbol *msg, long ac, t_atom *av);

long playkeys_func(t_hatom *key, t_llll *what);
void playkeys_output(t_playkeys *x);

t_class *playkeys_class;


void reset_warnings(t_playkeys *x)
{
    x->n_warn_pitchrequestedmidicentreceived = true;
    x->n_warn_fullpathrequestedbutnotpresent = true;
    x->n_warn_measurenumberneedsfullpath = true;
    x->n_warn_chordindexneedsfullpath = true;
    x->n_warn_noteindexneedsfullpath = true;
}


long symbol_to_incoming(t_symbol *s)
{
    if (s == _llllobj_sym_note)
        return k_PLAYKEYS_INCOMING_ROLLNOTE + k_PLAYKEYS_INCOMING_SCORENOTE;
    if (s == gensym("rollnote"))
        return k_PLAYKEYS_INCOMING_ROLLNOTE;
    if (s == gensym("scorenote"))
        return k_PLAYKEYS_INCOMING_SCORENOTE;
    if (s == _llllobj_sym_chord)
        return k_PLAYKEYS_INCOMING_ROLLCHORD + k_PLAYKEYS_INCOMING_SCORECHORD;
    if (s == gensym("rollchord"))
        return k_PLAYKEYS_INCOMING_ROLLCHORD;
    if (s == gensym("scorechord"))
        return k_PLAYKEYS_INCOMING_SCORECHORD;
    if (s == _llllobj_sym_rest)
        return k_PLAYKEYS_INCOMING_SCOREREST;
    if (s == _llllobj_sym_measure)
        return k_PLAYKEYS_INCOMING_SCOREMEASURE;
    if (s == _llllobj_sym_marker)
        return k_PLAYKEYS_INCOMING_MARKER;
    if (s == _llllobj_sym_tempo)
        return k_PLAYKEYS_INCOMING_TEMPO;
    if (s == _llllobj_sym_play)
        return k_PLAYKEYS_INCOMING_PLAY;
    if (s == _llllobj_sym_stop)
        return k_PLAYKEYS_INCOMING_STOP;
    if (s == _llllobj_sym_pause)
        return k_PLAYKEYS_INCOMING_PAUSE;
    if (s == _llllobj_sym_end)
        return k_PLAYKEYS_INCOMING_END;

    /*
     TODO:
    k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND
    k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND
    k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND
    k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND
    k_PLAYKEYS_INCOMING_SCOREREST_COMMAND
    */
    return k_PLAYKEYS_INCOMING_UNKNOWN;
}

long get_default_allowed_notationitems_for_property(long property)
{
    long score_set = k_PLAYKEYS_INCOMING_SCORENOTE + k_PLAYKEYS_INCOMING_SCORECHORD + k_PLAYKEYS_INCOMING_SCOREREST;
    long roll_set = k_PLAYKEYS_INCOMING_ROLLNOTE + k_PLAYKEYS_INCOMING_ROLLCHORD;
    long standard_set = roll_set + score_set;
    long all = -1;
    
    switch (property) {
        case k_PLAYKEYS_PLAY: return k_PLAYKEYS_INCOMING_PLAY;
        case k_PLAYKEYS_STOP: return k_PLAYKEYS_INCOMING_STOP;
        case k_PLAYKEYS_PAUSE: return k_PLAYKEYS_INCOMING_PAUSE;
        case k_PLAYKEYS_END: return k_PLAYKEYS_INCOMING_END;

        case k_PLAYKEYS_TYPE:
        case k_PLAYKEYS_ROUTER:
            return all;
        
        case k_PLAYKEYS_ROLE:
            return k_PLAYKEYS_INCOMING_MARKER;
            
        case k_PLAYKEYS_TEMPO:
        case k_PLAYKEYS_QUARTERTEMPO:
            return k_PLAYKEYS_INCOMING_TEMPO;
            
        case k_PLAYKEYS_MEASUREINFO:
            return k_PLAYKEYS_INCOMING_SCOREMEASURE;
            
            
        default: return standard_set;
    }
/*
    switch (property) {
        case k_PLAYKEYS_NONE: return standard_set;
        case k_PLAYKEYS_TYPE: return all;
        case k_PLAYKEYS_ONSET: return standard_set;
        case k_PLAYKEYS_SYMONSET: return score_set;
        case k_PLAYKEYS_CENTS: return standard_set;
        case k_PLAYKEYS_PITCH: return standard_set;
        case k_PLAYKEYS_DURATION: return standard_set;
        case k_PLAYKEYS_SYMDURATION: return score_set;
        case k_PLAYKEYS_VELOCITY: return standard_set;
        case k_PLAYKEYS_MIDICHANNEL: return standard_set;
        case k_PLAYKEYS_TIE: return score_set;
        case k_PLAYKEYS_VOICENUMBER: return standard_set;
        case k_PLAYKEYS_PATH: return standard_set;
        case k_PLAYKEYS_MEASURENUMBER: return gensym("measurenumber");
        case k_PLAYKEYS_BREAKPOINTS: return _llllobj_sym_breakpoints;
        case k_PLAYKEYS_MEASUREINFO: return _llllobj_sym_measureinfo;
        case k_PLAYKEYS_NAME: return _llllobj_sym_name;
        case k_PLAYKEYS_FLAGS: return _llllobj_sym_flags;
        case k_PLAYKEYS_TEMPO: return _llllobj_sym_tempo;
        case k_PLAYKEYS_QUARTERTEMPO: return _llllobj_sym_quartertempo;
        case k_PLAYKEYS_SLOT: return _llllobj_sym_slot;
        case k_PLAYKEYS_PLAY: return _llllobj_sym_play;
        case k_PLAYKEYS_STOP: return _llllobj_sym_stop;
        case k_PLAYKEYS_PAUSE: return _llllobj_sym_pause;
        case k_PLAYKEYS_END: return _llllobj_sym_end;
        case k_PLAYKEYS_CHORDINDEX: return gensym("chordindex");
        case k_PLAYKEYS_NOTEINDEX: return gensym("noteindex");
        case k_PLAYKEYS_TAIL: return _llllobj_sym_tail;
        case k_PLAYKEYS_DYNAMICS: return _llllobj_sym_dynamics;
        case k_PLAYKEYS_LYRICS: return _llllobj_sym_lyrics;
        case k_PLAYKEYS_NOTEHEAD: return _llllobj_sym_notehead;
        case k_PLAYKEYS_ARTICULATIONS: return _llllobj_sym_articulations;
        case k_PLAYKEYS_ROUTER: return gensym("router");
        case k_PLAYKEYS_PLAYOFFSET: return gensym("playoffset");
        default: return _llllobj_sym_none;
    } */
}

long symbol_to_property(t_symbol *s)
{
    if (s == _llllobj_sym_type)
        return k_PLAYKEYS_TYPE;
    if (s == _llllobj_sym_onset)
        return k_PLAYKEYS_ONSET;
    if (s == _llllobj_sym_symonset)
        return k_PLAYKEYS_SYMONSET;
    if (s == _llllobj_sym_cents)
        return k_PLAYKEYS_CENTS;
    if (s == _llllobj_sym_pitch)
        return k_PLAYKEYS_PITCH;
    if (s == _llllobj_sym_duration)
        return k_PLAYKEYS_DURATION;
    if (s == _llllobj_sym_symduration)
        return k_PLAYKEYS_SYMDURATION;
    if (s == _llllobj_sym_velocity)
        return k_PLAYKEYS_VELOCITY;
    if (s == _llllobj_sym_midichannel)
        return k_PLAYKEYS_MIDICHANNEL;
    if (s == _llllobj_sym_tie)
        return k_PLAYKEYS_TIE;
    if (s == gensym("voicenumber"))
        return k_PLAYKEYS_VOICENUMBER;
//    if (s == _llllobj_sym_voice)
//        return k_PLAYKEYS_VOICENUMBER;
    if (s == gensym("measurenumber"))
        return k_PLAYKEYS_MEASURENUMBER;
//    if (s == _llllobj_sym_measure)
//        return k_PLAYKEYS_MEASURENUMBER;
    if (s == _llllobj_sym_breakpoints)
        return k_PLAYKEYS_BREAKPOINTS;
    if (s == _llllobj_sym_measureinfo)
        return k_PLAYKEYS_MEASUREINFO;
    if (s == _llllobj_sym_name)
        return k_PLAYKEYS_NAME;
    if (s == _llllobj_sym_flags)
        return k_PLAYKEYS_FLAGS;
    if (s == _llllobj_sym_path)
        return k_PLAYKEYS_PATH;
    if (s == _llllobj_sym_tempo)
        return k_PLAYKEYS_TEMPO;
    if (s == _llllobj_sym_role)
        return k_PLAYKEYS_ROLE;
    if (s == _llllobj_sym_quartertempo)
        return k_PLAYKEYS_QUARTERTEMPO;
    if (s == _llllobj_sym_slot)
        return k_PLAYKEYS_SLOT;
    if (s == _llllobj_sym_slots)
        return k_PLAYKEYS_ALLSLOTS;
    if (s == _llllobj_sym_play)
        return k_PLAYKEYS_PLAY;
    if (s == _llllobj_sym_stop)
        return k_PLAYKEYS_STOP;
    if (s == _llllobj_sym_pause)
        return k_PLAYKEYS_PAUSE;
    if (s == _llllobj_sym_end)
        return k_PLAYKEYS_END;
    if (s == gensym("chordindex"))
        return k_PLAYKEYS_CHORDINDEX;
    if (s == gensym("noteindex"))
        return k_PLAYKEYS_NOTEINDEX;
    if (s == _llllobj_sym_tail)
        return k_PLAYKEYS_TAIL;
    if (s == _llllobj_sym_dynamics)
        return k_PLAYKEYS_DYNAMICS;
    if (s == _llllobj_sym_lyrics)
        return k_PLAYKEYS_LYRICS;
    if (s == _llllobj_sym_notehead)
        return k_PLAYKEYS_NOTEHEAD;
    if (s == _llllobj_sym_articulations)
        return k_PLAYKEYS_ARTICULATIONS;
    if (s == _llllobj_sym_annotation)
        return k_PLAYKEYS_ANNOTATION;
    if (s == gensym("router"))
        return k_PLAYKEYS_ROUTER;
    if (s == gensym("playoffset"))
        return k_PLAYKEYS_PLAYOFFSET;

    return k_PLAYKEYS_NONE;
}

t_symbol *property_to_symbol(long property)
{
    switch (property) {
        case k_PLAYKEYS_NONE: return _llllobj_sym_none;
        case k_PLAYKEYS_TYPE: return _llllobj_sym_type;
        case k_PLAYKEYS_ONSET: return _llllobj_sym_onset;
        case k_PLAYKEYS_SYMONSET: return _llllobj_sym_symonset;
        case k_PLAYKEYS_CENTS: return _llllobj_sym_cents;
        case k_PLAYKEYS_PITCH: return _llllobj_sym_pitch;
        case k_PLAYKEYS_DURATION: return _llllobj_sym_duration;
        case k_PLAYKEYS_SYMDURATION: return _llllobj_sym_symduration;
        case k_PLAYKEYS_VELOCITY: return _llllobj_sym_velocity;
        case k_PLAYKEYS_MIDICHANNEL: return _llllobj_sym_midichannel;
        case k_PLAYKEYS_TIE: return _llllobj_sym_tie;
        case k_PLAYKEYS_VOICENUMBER: return gensym("voicenumber");
        case k_PLAYKEYS_PATH: return _llllobj_sym_path;
        case k_PLAYKEYS_MEASURENUMBER: return gensym("measurenumber");
        case k_PLAYKEYS_BREAKPOINTS: return _llllobj_sym_breakpoints;
        case k_PLAYKEYS_MEASUREINFO: return _llllobj_sym_measureinfo;
        case k_PLAYKEYS_NAME: return _llllobj_sym_name;
        case k_PLAYKEYS_FLAGS: return _llllobj_sym_flags;
        case k_PLAYKEYS_ROLE: return _llllobj_sym_role;
        case k_PLAYKEYS_TEMPO: return _llllobj_sym_tempo;
        case k_PLAYKEYS_QUARTERTEMPO: return _llllobj_sym_quartertempo;
        case k_PLAYKEYS_SLOT: return _llllobj_sym_slot;
        case k_PLAYKEYS_ALLSLOTS: return _llllobj_sym_slots;
        case k_PLAYKEYS_PLAY: return _llllobj_sym_play;
        case k_PLAYKEYS_STOP: return _llllobj_sym_stop;
        case k_PLAYKEYS_PAUSE: return _llllobj_sym_pause;
        case k_PLAYKEYS_END: return _llllobj_sym_end;
        case k_PLAYKEYS_CHORDINDEX: return gensym("chordindex");
        case k_PLAYKEYS_NOTEINDEX: return gensym("noteindex");
        case k_PLAYKEYS_TAIL: return _llllobj_sym_tail;
        case k_PLAYKEYS_DYNAMICS: return _llllobj_sym_dynamics;
        case k_PLAYKEYS_LYRICS: return _llllobj_sym_lyrics;
        case k_PLAYKEYS_NOTEHEAD: return _llllobj_sym_notehead;
        case k_PLAYKEYS_ARTICULATIONS: return _llllobj_sym_articulations;
        case k_PLAYKEYS_ANNOTATION: return _llllobj_sym_annotation;
        case k_PLAYKEYS_ROUTER: return gensym("router");
        case k_PLAYKEYS_PLAYOFFSET: return gensym("playoffset");
        default: return _llllobj_sym_none;
    }
}



int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.playkeys", (method)playkeys_new, (method)playkeys_free, (short)sizeof(t_playkeys), 0L, A_GIMME, 0);
    
    // @method llll @digest Search the llll for the specified playkeys
    // @description
    // The first elements of the llll and all its sublists are examined, traversing the llll depth-first as in <o>bach.iter</o>.
    // When a first element is found to match one of <o>bach.playkeys</o>'s arguments (the "playkeys"),
    // the corresponding llll is output, with or without the key according to the <m>keep</m> attribute,
    // and that key is no further looked for.<br />
    // Anyway, all the found lllls are output right-to-left, according to their order in <o>bach.playkeys</o>'s arguments
    // and regardless of their positions in the original llll.
    // In case of multiple possible matches, the first matching llll that is found is output.
    // If no match is found for any key, a bang is output from the rightmost outlet.
    class_addmethod(c, (method)playkeys_anything,    "anything",        A_GIMME,    0);
    class_addmethod(c, (method)playkeys_int,        "int",            A_LONG,        0);
    class_addmethod(c, (method)playkeys_float,        "float",        A_FLOAT,    0);
    class_addmethod(c, (method)playkeys_anything,    "list",            A_GIMME,    0);
    
    // @method bang @digest Perform last operation
    // @description The playkeys are searched for in the most recently received llll.
    class_addmethod(c, (method)playkeys_bang,        "bang",            0);
    
    class_addmethod(c, (method)playkeys_assist,        "assist",        A_CANT,        0);
    class_addmethod(c, (method)playkeys_inletinfo,    "inletinfo",    A_CANT,        0);
    
    
    CLASS_STICKY_ATTR(c,"category",0,"Settings");

    CLASS_ATTR_LLLL(c, "routers", 0, t_playkeys, n_process, playkeys_getattr_process, playkeys_setattr_process);
    CLASS_ATTR_LABEL(c, "routers", 0, "Routers To Accept");
    CLASS_ATTR_STYLE(c, "routers",        0, "text");
    CLASS_ATTR_BASIC(c, "routers", 0);
    // @description List of router symbols which will be accepted. Leave empty to process all possible routers.
    // E.g. <b>note tempo</b> will only accept "note"- and "tempo"-routed playout lllls. <br />
    // You can have <o>bach.playkeys</o> intercept commands as well, provided that you set aliases via an llll starting
    // with "note", "chord" or "rest" (depending on the type of alias). E.g. <b>@routers note [note mynotecommand1 mynotecommand2]</b>
    // will intercept <b>note</b> messages, as well as note commands <b>mynotecommand1</b> and <b>mynotecommand2</b>.
    // To only intercept commands, simply use something like <b>@routers [note mynotecommand1 mynotecommand2]</b>.
    // If you want to add some commands for acceptance (and to keep everything else accepted) use "+" as first element, such as in
    // <b>@routers + [rest myrestcommand]</b>.

    
    
    CLASS_ATTR_LONG(c, "wrapmode",        0,    t_playkeys, n_flattenfornotes);
    CLASS_ATTR_LABEL(c, "wrapmode",        0, "Only Wrap Chords llll Data");
    CLASS_ATTR_STYLE(c, "wrapmode",        0, "onoff");
    CLASS_ATTR_BASIC(c, "wrapmode", 0);
    // @description When set to 1, it only wraps llll parameters if the playout input is a chord.

    
    CLASS_ATTR_LONG(c, "nullmode",        0,    t_playkeys, n_nullmode);
    CLASS_ATTR_LABEL(c, "nullmode",        0, "Output null");
    CLASS_ATTR_STYLE(c, "nullmode",        0, "enumindex");
    CLASS_ATTR_ENUMINDEX(c,"nullmode", 0, "Never For Empty Keys For Unmatched Keys");
    CLASS_ATTR_BASIC(c, "nullmode", 0);
    // @description Handles when <b>null</b> is output from a given key outlet.
    // 0 = Never; 1 = only for keys without any content (default); 2 = also for unmatched keys (e.g. keys that has no meaning for the specific notation item,
    // such as velocity for markers, etc.).

    
    CLASS_ATTR_LONG(c, "defaultbreakpoints",        0,    t_playkeys, n_use_default_breakpoints);
    CLASS_ATTR_LABEL(c, "defaultbreakpoints",        0, "Use Default Breakpoints");
    CLASS_ATTR_STYLE(c, "defaultbreakpoints",        0, "onoff");
    // @description When set to 1, uses default breakpoints for notes without glissandi.

    
    CLASS_ATTR_LONG(c, "breakpointshavevelocity",        0,    t_playkeys, n_breakpoints_have_velocity);
    CLASS_ATTR_LABEL(c, "breakpointshavevelocity",        0, "Breakpoints Have Velocity");
    CLASS_ATTR_STYLE(c, "breakpointshavevelocity",        0, "onoff");
    // @description Toggles the ability, for pitch breakpoints, to have their own independent velocity.
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");

    
    CLASS_STICKY_ATTR(c,"category",0,"Slots");

    CLASS_ATTR_ATOM(c, "dynamicsslot",        0,    t_playkeys, n_dynamicsslot);
    CLASS_ATTR_STYLE_LABEL(c, "dynamicsslot", 0, "text", "Dynamics Slot Number");
    // @description Sets the number of the slot containing dynamics (0 if none).

    CLASS_ATTR_ATOM(c, "lyricsslot",        0,    t_playkeys, n_lyricsslot);
    CLASS_ATTR_STYLE_LABEL(c, "lyricsslot", 0, "text", "Lyrics Slot Number");
    // @description Sets the number of the slot containing lyrics (0 if none).

    CLASS_ATTR_ATOM(c, "articulationsslot",        0,    t_playkeys, n_articulationsslot);
    CLASS_ATTR_STYLE_LABEL(c, "articulationsslot", 0, "text", "Articulations Slot Number");
    // @description Sets the number of the slot containing articulations (0 if none).

    CLASS_ATTR_ATOM(c, "noteheadslot",        0,    t_playkeys, n_noteheadslot);
    CLASS_ATTR_STYLE_LABEL(c, "noteheadslot", 0, "text", "Notehead Slot Number");
    // @description Sets the number of the slot containing noteheads (0 if none).

    CLASS_ATTR_ATOM(c, "annotationslot",        0,    t_playkeys, n_annotationslot);
    CLASS_ATTR_STYLE_LABEL(c, "annotationslot", 0, "text", "Annotation Slot Number");
    // @description Sets the number of the slot containing textual annotations (0 if none).

    CLASS_STICKY_ATTR_CLEAR(c, "category");


    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

    class_register(CLASS_BOX, c);
    playkeys_class = c;
    
    dev_post("bach.playkeys compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}

void playkeys_bang(t_playkeys *x)
{
    if (x->n_ob.l_rebuild != 0) {
        playkeys_anything(x, _sym_bang, 0, NULL);
        return;
    }
    playkeys_output(x);
}

void playkeys_output(t_playkeys *x)
{
    long i;
    if (x->n_must_iterate_on_output) {
        // gotta be complicated
        // To be implemented. No iteration for the time being.
    
    } else {
        for (i = x->n_ob.l_numouts - 1; i >= 0; i--) {
            if (x->n_keys[i].property != k_PLAYKEYS_NONE && (x->n_keys[i].exists || x->n_nullmode == 2))
                llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
        }
    }
}

void playkeys_int(t_playkeys *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    playkeys_anything(x, _sym_int, 1, &outatom);
}

void playkeys_float(t_playkeys *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    playkeys_anything(x, _sym_float, 1, &outatom);
}


t_llllelem *getindex_2levels(t_llll *ll, long pos1, long pos2)
{
    t_llllelem *el = llll_getindex(ll, pos1, I_STANDARD);
    if (el && hatom_gettype(&el->l_hatom) == H_LLLL)
        return llll_getindex(hatom_getllll(&el->l_hatom), pos2, I_STANDARD);
    return NULL;
}


t_bool can_llll_be_a_note(t_llll *ll)
{
    if (!ll || !ll->l_head)
        return false;
    
    if (hatom_gettype(&ll->l_head->l_hatom) == H_SYM) {
        t_symbol *router = hatom_getsym(&ll->l_head->l_hatom);
        if (router == _llllobj_sym_name ||
            router == _llllobj_sym_articulations ||
            router == _llllobj_sym_slots ||
            router == _llllobj_sym_breakpoints ||
            router == _llllobj_sym_graphic ||
            router == _llllobj_sym_flags)
            return false;
    }
    
    return true;
}


t_llllelem *root_find_el_with_sym_router(t_llll *ll, t_symbol *router)
{
    t_llllelem *el;
    for (el = ll->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *el_ll = hatom_getllll(&el->l_hatom);
            if (el_ll && el_ll->l_head && hatom_gettype(&el_ll->l_head->l_hatom) == H_SYM && hatom_getsym(&el_ll->l_head->l_hatom) == router)
                return el;
        }
    }
    return NULL;
}


t_llllelem *root_find_el_with_long_router(t_llll *ll, long router)
{
    t_llllelem *el;
    for (el = ll->l_head; el; el = el->l_next) {
        if (hatom_gettype(&el->l_hatom) == H_LLLL) {
            t_llll *el_ll = hatom_getllll(&el->l_hatom);
            if (el_ll && el_ll->l_head && hatom_gettype(&el_ll->l_head->l_hatom) == H_LONG && hatom_getlong(&el_ll->l_head->l_hatom) == router)
                return el;
        }
    }
    return NULL;
}


long llll_count_elems_fn(void *data, t_hatom *a, const t_llll *address)
{
    long *count = (long *)data;
    (*count)++;
    return 0;
}


long llll_count_elems(t_llll *ll) {
    long count = 0;
    llll_funall(ll, (fun_fn) llll_count_elems_fn, &count, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
    return count;
}

void playkeys_handle_flattening_and_nullmode(t_playkeys *x, t_llll **ll, long incoming, long playkeys_property, long outlet)
{
    if (ll && *ll) {
        switch (incoming) {
            case k_PLAYKEYS_INCOMING_ROLLNOTE:
            case k_PLAYKEYS_INCOMING_SCORENOTE:
            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
            case k_PLAYKEYS_INCOMING_TEMPO:
            case k_PLAYKEYS_INCOMING_MARKER:
            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
            case k_PLAYKEYS_INCOMING_SCOREREST:
            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                if (x->n_flattenfornotes && (*ll)->l_size == 1)
                    llll_flatten(*ll, 1, 0);
                if (x->n_nullmode == 0 && (*ll)->l_size == 0) {
                    llll_free(*ll);
                    *ll = NULL;
                    x->n_keys[outlet].exists = 0;
                }
                break;
                
                
            case k_PLAYKEYS_INCOMING_ROLLCHORD:
            case k_PLAYKEYS_INCOMING_SCORECHORD:
            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                if (playkeys_property == k_PLAYKEYS_NAME && x->n_flattenfornotes && (*ll)->l_size == 1)
                    llll_flatten(*ll, 1, 0);
                if (x->n_nullmode == 0 && ((*ll)->l_size == 0 || ((*ll)->l_depth == 2 && llll_count_elems(*ll) == 0))) {
                    llll_free(*ll);
                    *ll = NULL;
                    x->n_keys[outlet].exists = 0;
                }

            default:
                break;
        }
    }
    
}

t_max_err playkeys_setattr_process(t_playkeys *x, t_object *attr, long ac, t_atom *av)
{
    t_llll *ll;
    if (ac == 0 || av) {
        if ((ll = llllobj_parse_llllattr_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, av))) {
            t_llll *free_me;
            
            bach_atomic_lock(&x->n_process_lock);
            free_me = x->n_process;
            x->n_process = ll;
            llll_clear(x->n_note_commands);
            llll_clear(x->n_chord_commands);
            llll_clear(x->n_rest_commands);
            
            char defaultval = ((x->n_process && x->n_process->l_size > 0 && hatom_getsym(&x->n_process->l_head->l_hatom) != gensym("+")) ? 0 : 1);
            if (defaultval)
                x->n_notationitems_to_process = -1;  // all 1's
            else
                x->n_notationitems_to_process = 0;
            
            for (t_llllelem *elem = x->n_process->l_head; elem; elem = elem->l_next) {
                if (hatom_gettype(&elem->l_hatom) == H_SYM) {
                    t_symbol *thisprocess = hatom_getsym(&elem->l_hatom);
                    if (thisprocess == _llllobj_sym_note)
                        x->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLNOTE + k_PLAYKEYS_INCOMING_SCORENOTE);
                    else if (thisprocess == _llllobj_sym_chord)
                        x->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLCHORD+ k_PLAYKEYS_INCOMING_SCORECHORD);
                    else if (thisprocess == _llllobj_sym_rest)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCOREREST;
                    else if (thisprocess == _llllobj_sym_measure)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCOREMEASURE;
                    else if (thisprocess == _llllobj_sym_tempo)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_TEMPO;
                    else if (thisprocess == _llllobj_sym_marker)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_MARKER;
                    else if (thisprocess == _llllobj_sym_play)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_PLAY;
                    else if (thisprocess == _llllobj_sym_stop)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_STOP;
                    else if (thisprocess == _llllobj_sym_end)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_END;
                    else if (thisprocess == _llllobj_sym_pause)
                        x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_PAUSE;
                } else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                    t_llll *ll = hatom_getllll(&elem->l_hatom);
                    if (ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM) {
                        t_symbol *ref = hatom_getsym(&ll->l_head->l_hatom);
                        if (ref == _llllobj_sym_note) {
                            x->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND + k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND);
                            for (t_llllelem *el2 = ll->l_head->l_next; el2; el2=el2->l_next)
                                if (hatom_gettype(&el2->l_hatom) == H_SYM)
                                    llll_appendsym(x->n_note_commands, hatom_getsym(&el2->l_hatom));
                        } else if (ref == _llllobj_sym_chord) {
                            x->n_notationitems_to_process |= (k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND + k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND);
                            for (t_llllelem *el2 = ll->l_head->l_next; el2; el2=el2->l_next)
                                if (hatom_gettype(&el2->l_hatom) == H_SYM)
                                    llll_appendsym(x->n_chord_commands, hatom_getsym(&el2->l_hatom));
                        } else if (ref == _llllobj_sym_rest) {
                            x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCOREREST_COMMAND;
                            for (t_llllelem *el2 = ll->l_head->l_next; el2; el2=el2->l_next)
                                if (hatom_gettype(&el2->l_hatom) == H_SYM)
                                    llll_appendsym(x->n_rest_commands, hatom_getsym(&el2->l_hatom));
                        }
                    }
                }
            }

            
            bach_atomic_unlock(&x->n_process_lock);
            llll_free(free_me);
        }
    }
    return MAX_ERR_NONE;
}


double get_onset_from_llllelem(t_llllelem *el)
{
    if (hatom_gettype(&el->l_hatom) == H_LLLL) { // it's probably a "partial" note llll (see the @playpartialnotes verbose mode)
        t_llllelem *sub_target_el = llll_getindex(hatom_getllll(&el->l_hatom), 3, I_STANDARD);
        if (sub_target_el)
            return hatom_getdouble(&sub_target_el->l_hatom);
        else
            return 0;
    } else {
        return hatom_getdouble(&el->l_hatom);
    }
}

char incoming_is_from_roll(long incoming)
{
    switch (incoming) {
        case k_PLAYKEYS_INCOMING_ROLLNOTE:
        case k_PLAYKEYS_INCOMING_ROLLCHORD:
        case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
        case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
            return true;
            
        default:
            return false;
    }
}

void playkeys_anything(t_playkeys *x, t_symbol *msg, long ac, t_atom *av)
{
    t_playkeys_key *this_key;
    t_llll *in_ll, *found;
    long outlet;
    
    if (msg != _sym_bang) {
        in_ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!in_ll)
            return;
    } else
        in_ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
    
    
    bach_atomic_lock(&x->n_process_lock);

    long incoming = k_PLAYKEYS_INCOMING_UNKNOWN;
    t_symbol *router = NULL;
    if (in_ll && in_ll->l_head && hatom_gettype(&in_ll->l_head->l_hatom) == H_SYM) {
        router = hatom_getsym(&in_ll->l_head->l_hatom);
        if (router == _llllobj_sym_note) {
            t_llllelem *test = getindex_2levels(in_ll, 4, 2);
            incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLNOTE : k_PLAYKEYS_INCOMING_SCORENOTE;
        } else if (router == _llllobj_sym_chord) {
            t_llllelem *test = getindex_2levels(in_ll, 4, 2);
            incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLCHORD : k_PLAYKEYS_INCOMING_SCORECHORD;
        } else if (router == _llllobj_sym_rest) {
            incoming = k_PLAYKEYS_INCOMING_SCOREREST;
        } else if (router == _llllobj_sym_measure) {
            incoming = k_PLAYKEYS_INCOMING_SCOREMEASURE;
        } else if (router == _llllobj_sym_tempo) {
            incoming = k_PLAYKEYS_INCOMING_TEMPO;
        } else if (router == _llllobj_sym_marker) {
            incoming = k_PLAYKEYS_INCOMING_MARKER;
        } else if (router == _llllobj_sym_play) {
            incoming = k_PLAYKEYS_INCOMING_PLAY;
        } else if (router == _llllobj_sym_stop) {
            incoming = k_PLAYKEYS_INCOMING_STOP;
            reset_warnings(x);
        } else if (router == _llllobj_sym_end) {
            incoming = k_PLAYKEYS_INCOMING_END;
            reset_warnings(x);
        } else if (router == _llllobj_sym_pause) {
            incoming = k_PLAYKEYS_INCOMING_PAUSE;
            reset_warnings(x);
        } else {
            char found = 0;
            for (t_llllelem *elem = x->n_note_commands->l_head; elem; elem = elem->l_next) {
                if (router == hatom_getsym(&elem->l_hatom)) {
                    t_llllelem *test = getindex_2levels(in_ll, 4, 2);
                    incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND : k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND;
                    found = 1;
                }
            }
            if (!found) {
                for (t_llllelem *elem = x->n_chord_commands->l_head; elem; elem = elem->l_next) {
                    if (router == hatom_getsym(&elem->l_hatom)) {
                        t_llllelem *test = getindex_2levels(in_ll, 4, 2);
                        incoming = (test && hatom_gettype(&test->l_hatom) == H_LLLL) ? k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND : k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND;
                        found = 1;
                    }
                }
            }
            if (!found) {
                for (t_llllelem *elem = x->n_rest_commands->l_head; elem; elem = elem->l_next) {
                    if (router == hatom_getsym(&elem->l_hatom)) {
                        incoming = k_PLAYKEYS_INCOMING_SCOREREST_COMMAND;
                        found = 1;
                    }
                }
            }
        }
    }
    
    
    char must_process_incoming = false;
    if (incoming != k_PLAYKEYS_INCOMING_UNKNOWN) {
        must_process_incoming = ((x->n_notationitems_to_process & incoming) != 0);
        
        switch (incoming) {
            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                if (is_symbol_in_llll_first_level(x->n_note_commands, router))
                    must_process_incoming = true;
                break;

            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                if (is_symbol_in_llll_first_level(x->n_chord_commands, router))
                    must_process_incoming = true;
                break;

            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                if (is_symbol_in_llll_first_level(x->n_rest_commands, router))
                    must_process_incoming = true;
                break;

            default:
                break;
        }
    }
    
    bach_atomic_unlock(&x->n_process_lock);

    t_llllelem *target_el = NULL;
    if (must_process_incoming) {
        for (outlet = 0, this_key = x->n_keys; this_key && this_key->property != k_PLAYKEYS_NONE; this_key++, outlet++) {
            x->n_keys[outlet].exists = 0;
            
            if (incoming & x->n_keys[outlet].allowed_notationitems) { // must process key
                
                if ((incoming == k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND || incoming == k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND || incoming == k_PLAYKEYS_INCOMING_SCOREREST_COMMAND) && this_key->allowed_command_router != router)
                    continue; // not the right command
                
                found = NULL;
                switch (this_key->property) {
                    case k_PLAYKEYS_TYPE:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_note);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_chord);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_rest);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_measure);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_MARKER:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_marker);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_TEMPO:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_tempo);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_PLAY:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_play);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_STOP:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_stop);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_PAUSE:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_pause);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_END:
                                found = llll_get();
                                llll_appendsym(found, _llllobj_sym_end);
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                        
                    case k_PLAYKEYS_PITCH: // pitch must be changed at some point
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 1, I_STANDARD))) {
                                        if (hatom_gettype(&target_el->l_hatom) == H_PITCH)
                                            llll_appendpitch(found, hatom_getpitch(&target_el->l_hatom));
                                        else {
                                            if (x->n_warn_pitchrequestedmidicentreceived) {
                                                object_warn((t_object *)x, "Pitch requested, but only MIDIcent received.");
                                                object_warn((t_object *)x, "   You might want to set \"outputpitchesplayout\" on \"Always\" for your notation object.");
                                                x->n_warn_pitchrequestedmidicentreceived = false;
                                            }
                                            llll_appendpitch(found, t_pitch::fromMC(hatom_getdouble(&target_el->l_hatom)));
                                        }
                                    }
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 1, I_STANDARD))) {
                                        if (hatom_gettype(&target_el->l_hatom) == H_PITCH)
                                            llll_appendpitch(found, hatom_getpitch(&target_el->l_hatom));
                                        else {
                                            if (x->n_warn_pitchrequestedmidicentreceived) {
                                                object_warn((t_object *)x, "Pitch requested, but only MIDIcent received.");
                                                object_warn((t_object *)x, "   You might want to set \"outputpitchesplayout\" on \"Always\" for your notation object.");
                                                x->n_warn_pitchrequestedmidicentreceived = false;
                                            }
                                            llll_appendpitch(found, t_pitch::fromMC(hatom_getdouble(&target_el->l_hatom)));
                                        }
                                    }
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                    case k_PLAYKEYS_CENTS:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 1, I_STANDARD)))
                                        llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 1, I_STANDARD)))
                                        llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_VELOCITY:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 3, I_STANDARD)))
                                        llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 2, I_STANDARD)))
                                        llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_TIE:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 3, I_STANDARD)))
                                        llll_appendhatom_clone(found, &target_el->l_hatom);
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                        
                    case k_PLAYKEYS_DURATION:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    if ((target_el = llll_getindex(notell, 2, I_STANDARD)))
                                        llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 2)))
                                    llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 5, 2)))
                                    llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                                break;
                                
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_SYMDURATION:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 1)))
                                    llll_appendrat(found, hatom_getrational(&target_el->l_hatom));
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 5, 1)))
                                    llll_appendrat(found, hatom_getrational(&target_el->l_hatom));
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                        
                    case k_PLAYKEYS_ONSET:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 1)))
                                    llll_appenddouble(found, get_onset_from_llllelem(target_el));
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 4)))
                                    llll_appenddouble(found, get_onset_from_llllelem(target_el));
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 5, 3)))
                                    llll_appenddouble(found, hatom_getdouble(&target_el->l_hatom));
                                break;
                                
                            case k_PLAYKEYS_INCOMING_MARKER:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 3, I_STANDARD)))
                                    llll_appendhatom_clone(found, &target_el->l_hatom);
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_PLAYOFFSET:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 1))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) {
                                        t_llllelem *sub_target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 4, I_STANDARD);
                                        llll_appenddouble(found, sub_target_el ? hatom_getdouble(&sub_target_el->l_hatom) : 0);
                                    } else
                                        llll_appenddouble(found, 0);
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 4))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) {
                                        t_llllelem *sub_target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 4, I_STANDARD);
                                        llll_appenddouble(found, sub_target_el ? hatom_getdouble(&sub_target_el->l_hatom) : 0);
                                    } else
                                        llll_appenddouble(found, 0);
                                }
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                    case k_PLAYKEYS_TAIL:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                
                                if ((target_el = getindex_2levels(in_ll, 4, 1))) {
                                    double onset = get_onset_from_llllelem(target_el);
                                    
                                    for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, 2); startnoteel; startnoteel = startnoteel->l_next) {
                                        if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                            break;
                                        t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                        if (!can_llll_be_a_note(notell))
                                            break;
                                        if ((target_el = llll_getindex(notell, 2, I_STANDARD)))
                                            llll_appenddouble(found, onset + hatom_getdouble(&target_el->l_hatom));
                                    }
                                    break;
                                }
                                
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 4))) {
                                    double onset = get_onset_from_llllelem(target_el);
                                    if ((target_el = getindex_2levels(in_ll, 4, 2)))
                                        llll_appenddouble(found, onset + hatom_getdouble(&target_el->l_hatom));
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                        
                    case k_PLAYKEYS_SYMONSET:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                            case k_PLAYKEYS_INCOMING_TEMPO:
                                found = llll_get();
                                if ((target_el = getindex_2levels(in_ll, 4, 3)))
                                    llll_appendrat(found, hatom_getrational(&target_el->l_hatom));
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_MIDICHANNEL:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 3, I_STANDARD)))
                                    llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_VOICENUMBER:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) // playout full path
                                        target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 1, I_STANDARD);
                                    if (target_el)
                                        llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                                }
                                break;
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                            case k_PLAYKEYS_INCOMING_TEMPO:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) // playout full path
                                        target_el = getindex_2levels(hatom_getllll(&target_el->l_hatom), 1, 1);
                                    if (target_el)
                                        llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                    case k_PLAYKEYS_PATH:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                            case k_PLAYKEYS_INCOMING_TEMPO:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) != H_LLLL) { // playout full path
                                        if (x->n_warn_fullpathrequestedbutnotpresent) {
                                            object_warn((t_object *)x, "Full path requested, but not present in the playout llll.");
                                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object, or use the \"voice\" playkey to avoid this warning.");
                                            x->n_warn_fullpathrequestedbutnotpresent = false;
                                        }
                                    }
                                    if (target_el)
                                        llll_appendhatom_clone(found, &target_el->l_hatom);
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_MEASURENUMBER:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                            case k_PLAYKEYS_INCOMING_TEMPO:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                                        t_llllelem *tie_el;
                                        for (tie_el = hatom_getllll(&target_el->l_hatom)->l_head; tie_el; tie_el = tie_el->l_next) {
                                            target_el = llll_getindex(hatom_getllll(&tie_el->l_hatom), 2, I_STANDARD);
                                            if (target_el)
                                                llll_appendhatom_clone(found, &target_el->l_hatom);
                                        }
                                    } else {
                                        target_el = NULL;
                                        if (x->n_warn_measurenumberneedsfullpath) {
                                            object_warn((t_object *)x, "In order to intercept the measure number, full path must be in playout syntax.");
                                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                                            x->n_warn_measurenumberneedsfullpath = false;
                                        }
                                    }
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 3, I_STANDARD)))
                                    llll_appendlong(found, hatom_getlong(&target_el->l_hatom));
                                break;
                                
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_CHORDINDEX:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                                        target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 2, I_STANDARD);
                                        if (target_el)
                                            llll_appendhatom_clone(found, &target_el->l_hatom);
                                    } else {
                                        target_el = NULL;
                                        if (x->n_warn_chordindexneedsfullpath) {
                                            object_warn((t_object *)x, "In order to intercept the chord index, full path must be in playout syntax.");
                                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                                            x->n_warn_chordindexneedsfullpath = false;
                                        }
                                    }
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                                        t_llllelem *tie_el;
                                        for (tie_el = hatom_getllll(&target_el->l_hatom)->l_head; tie_el; tie_el = tie_el->l_next) {
                                            target_el = llll_getindex(hatom_getllll(&tie_el->l_hatom), 3, I_STANDARD);
                                            if (target_el)
                                                llll_appendhatom_clone(found, &target_el->l_hatom);
                                        }
                                    } else {
                                        target_el = NULL;
                                        if (x->n_warn_chordindexneedsfullpath) {
                                            object_warn((t_object *)x, "In order to intercept the chord index, full path must be in playout syntax.");
                                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                                            x->n_warn_chordindexneedsfullpath = false;
                                        }
                                    }
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_NOTEINDEX:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                                        target_el = llll_getindex(hatom_getllll(&target_el->l_hatom), 3, I_STANDARD);
                                        if (target_el)
                                            llll_appendhatom_clone(found, &target_el->l_hatom);
                                    } else {
                                        target_el = NULL;
                                        if (x->n_warn_noteindexneedsfullpath) {
                                            object_warn((t_object *)x, "In order to intercept the note index, full path must be in playout syntax.");
                                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                                            x->n_warn_noteindexneedsfullpath = false;
                                        }
                                    }
                                }
                                break;
                                
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL) { // playout full path
                                        t_llllelem *tie_el;
                                        for (tie_el = hatom_getllll(&target_el->l_hatom)->l_head; tie_el; tie_el = tie_el->l_next) {
                                            target_el = llll_getindex(hatom_getllll(&tie_el->l_hatom), 4, I_STANDARD);
                                            if (target_el)
                                                llll_appendhatom_clone(found, &target_el->l_hatom);
                                        }
                                    } else {
                                        target_el = NULL;
                                        if (x->n_warn_noteindexneedsfullpath) {
                                            object_warn((t_object *)x, "In order to intercept the note index, full path must be in playout syntax.");
                                            object_warn((t_object *)x, "   You might want to turn \"playoutfullpath\" on for your notation object.");
                                            x->n_warn_noteindexneedsfullpath = false;
                                        }
                                    }
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_MEASUREINFO:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_SCOREMEASURE:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 4, I_STANDARD)))
                                    llll_appendhatom_clone(found, &target_el->l_hatom);
                                break;
                                
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                        
                    case k_PLAYKEYS_ROLE:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_MARKER:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 4, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_SYM)
                                        llll_appendsym(found, hatom_getsym(&target_el->l_hatom));
                                } else
                                    llll_appendsym(found, _llllobj_sym_none);
                                
                                break;
                                
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_TEMPO:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_TEMPO:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 4, I_STANDARD)))
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL)
                                        llll_chain_clone(found, hatom_getllll(&target_el->l_hatom));
                                break;
                                
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                    case k_PLAYKEYS_QUARTERTEMPO:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_TEMPO:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 3, I_STANDARD))) {
                                    if (hatom_gettype(&target_el->l_hatom) == H_LLLL)
                                        llll_chain_clone(found, hatom_getllll(&target_el->l_hatom));
                                    else
                                        llll_appendhatom_clone(found, &target_el->l_hatom);
                                }
                                break;
                                
                                
                            default:
                                break;
                        }
                    }
                        break;
                        
                        
                        
                    case k_PLAYKEYS_BREAKPOINTS:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    
                                    if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_breakpoints)))
                                        llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                    else if (x->n_use_default_breakpoints) {
                                        if (x->n_breakpoints_have_velocity) {
                                            char buf[512];
                                            long velocity = 100;
                                            // getting the note velocity
                                            t_llllelem *velocity_el = llll_getindex(notell, incoming_is_from_roll(incoming) ? 3 : 2, I_STANDARD);
                                            if (velocity_el)
                                                velocity = hatom_getlong(&velocity_el->l_hatom);
                                            snprintf(buf, 512, "(0. 0. 0. %ld) (1. 0. 0. %ld)", velocity, velocity);
                                            llll_appendllll(found, llll_from_text_buf(buf));
                                        } else {
                                            llll_appendllll(found, llll_from_text_buf("(0. 0. 0.) (1. 0. 0.)"));
                                        }
                                    } else
                                        llll_appendllll(found, llll_get());
                                }
                                break;
                                
                            default:
                                break;
                        }
                        playkeys_handle_flattening_and_nullmode(x, &found, incoming, this_key->property, outlet);
                    }
                        break;
                        
                        
                        
                    case k_PLAYKEYS_NAME:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_MARKER:
                                found = llll_get();
                                if ((target_el = llll_getindex(in_ll, 2, I_STANDARD)))
                                    llll_appendhatom_clone(found, &target_el->l_hatom);
                                break;
                                
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    
                                    if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_name)))
                                        llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                    else
                                        llll_appendllll(found, llll_get());
                                }
                                break;
                                
                                
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                
                                found = llll_get();
                                target_el = llll_getindex(in_ll, 4, I_STANDARD);
                                if (!target_el || hatom_gettype(&target_el->l_hatom) != H_LLLL)
                                    break;
                                if ((target_el = root_find_el_with_sym_router(hatom_getllll(&target_el->l_hatom), _llllobj_sym_name)))
                                    llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                else
                                    llll_appendllll(found, llll_get());
                                break;
                                
                            default:
                                break;
                        }
                        playkeys_handle_flattening_and_nullmode(x, &found, incoming, this_key->property, outlet);
                    }
                        break;
                        
                        
                        
                        
                    case k_PLAYKEYS_ALLSLOTS:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    
                                    if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_slots))) {
                                        if (hatom_gettype(&target_el->l_hatom) != H_LLLL)
                                            break;
                                        
                                        t_llll *slotsll = hatom_getllll(&target_el->l_hatom);
                                        llll_appendllll(found, llll_behead(llll_clone(slotsll)));
                                    } else
                                        llll_appendllll(found, llll_get());
                                }
                                break;
                                
                                
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                // to do
                                break;
                                
                            default:
                                break;
                        }
                        playkeys_handle_flattening_and_nullmode(x, &found, incoming, this_key->property, outlet);
                    }
                        break;
                        
                    case k_PLAYKEYS_LYRICS:
                    case k_PLAYKEYS_DYNAMICS:
                    case k_PLAYKEYS_ARTICULATIONS:
                    case k_PLAYKEYS_NOTEHEAD:
                    case k_PLAYKEYS_ANNOTATION:
                    case k_PLAYKEYS_SLOT:
                    {
                        switch (incoming) {
                            case k_PLAYKEYS_INCOMING_ROLLNOTE:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD:
                            case k_PLAYKEYS_INCOMING_SCORENOTE:
                            case k_PLAYKEYS_INCOMING_SCORECHORD:
                            case k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND:
                            case k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND:
                                found = llll_get();
                                for (t_llllelem *startnoteel = getindex_2levels(in_ll, 4, incoming_is_from_roll(incoming) ? 2 : 5); startnoteel; startnoteel = startnoteel->l_next) {
                                    if (hatom_gettype(&startnoteel->l_hatom) != H_LLLL)
                                        break;
                                    t_llll *notell = hatom_getllll(&startnoteel->l_hatom);
                                    if (!can_llll_be_a_note(notell))
                                        break;
                                    
                                    if ((target_el = root_find_el_with_sym_router(notell, _llllobj_sym_slots))) {
                                        if (hatom_gettype(&target_el->l_hatom) != H_LLLL)
                                            break;
                                        
                                        t_llll *slotsll = hatom_getllll(&target_el->l_hatom);
                                        
                                        t_hatom spec = this_key->specification;
                                        if (this_key->property == k_PLAYKEYS_DYNAMICS)
                                            hatom_setatom(&spec, &x->n_dynamicsslot);
                                        if (this_key->property == k_PLAYKEYS_LYRICS)
                                            hatom_setatom(&spec, &x->n_lyricsslot);
                                        if (this_key->property == k_PLAYKEYS_ARTICULATIONS)
                                            hatom_setatom(&spec, &x->n_articulationsslot);
                                        if (this_key->property == k_PLAYKEYS_NOTEHEAD)
                                            hatom_setatom(&spec, &x->n_noteheadslot);
                                        if (this_key->property == k_PLAYKEYS_ANNOTATION)
                                            hatom_setatom(&spec, &x->n_annotationslot);
                                        if (spec.h_type == H_LONG) {
                                            if ((target_el = root_find_el_with_long_router(slotsll, hatom_getlong(&spec))))
                                                llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                            else
                                                llll_appendllll(found, llll_get());
                                        } else if (spec.h_type == H_SYM) {
                                            if ((target_el = root_find_el_with_sym_router(slotsll, hatom_getsym(&spec))))
                                                llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                            else
                                                llll_appendllll(found, llll_get());
                                        }
                                        
                                    } else
                                        llll_appendllll(found, llll_get());
                                }
                                break;
                                
                                
                            case k_PLAYKEYS_INCOMING_SCOREREST:
                            case k_PLAYKEYS_INCOMING_SCOREREST_COMMAND:
                                found = llll_get();
                            {
                                t_llllelem *restel = llll_getindex(in_ll, 4, I_STANDARD);
                                if (!restel || hatom_gettype(&restel->l_hatom) != H_LLLL)
                                    break;
                                
                                t_llll *restll = hatom_getllll(&restel->l_hatom);
                                if ((target_el = root_find_el_with_sym_router(restll, _llllobj_sym_slots))) {
                                    if (hatom_gettype(&target_el->l_hatom) != H_LLLL)
                                        break;
                                    
                                    t_llll *slotsll = hatom_getllll(&target_el->l_hatom);
                                    
                                    t_hatom spec = this_key->specification;
                                    if (this_key->property == k_PLAYKEYS_DYNAMICS)
                                        hatom_setatom(&spec, &x->n_dynamicsslot);
                                    if (this_key->property == k_PLAYKEYS_LYRICS)
                                        hatom_setatom(&spec, &x->n_lyricsslot);
                                    if (this_key->property == k_PLAYKEYS_ARTICULATIONS)
                                        hatom_setatom(&spec, &x->n_articulationsslot);
                                    if (this_key->property == k_PLAYKEYS_NOTEHEAD)
                                        hatom_setatom(&spec, &x->n_noteheadslot);
                                    if (this_key->property == k_PLAYKEYS_ANNOTATION)
                                        hatom_setatom(&spec, &x->n_annotationslot);
                                    if (spec.h_type == H_LONG) {
                                        if ((target_el = root_find_el_with_long_router(slotsll, hatom_getlong(&spec))))
                                            llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                        else
                                            llll_appendllll(found, llll_get());
                                    } else if (spec.h_type == H_SYM) {
                                        if ((target_el = root_find_el_with_sym_router(slotsll, hatom_getsym(&spec))))
                                            llll_appendllll(found, llll_behead(llll_clone(hatom_getllll(&target_el->l_hatom))));
                                        else
                                            llll_appendllll(found, llll_get());
                                    }
                                    
                                } else
                                    llll_appendllll(found, llll_get());
                            }
                                break;
                            default:
                                break;
                        }
                        playkeys_handle_flattening_and_nullmode(x, &found, incoming, this_key->property, outlet);
                    }
                        break;
                        
                        
                        
                        
                        
                    case k_PLAYKEYS_PLAY:
                        if (incoming == k_PLAYKEYS_INCOMING_PLAY)
                            found = WHITENULL_llll;
                        break;
                        
                    case k_PLAYKEYS_STOP:
                        if (incoming == k_PLAYKEYS_INCOMING_STOP)
                            found = WHITENULL_llll;
                        break;
                        
                    case k_PLAYKEYS_PAUSE:
                        if (incoming == k_PLAYKEYS_INCOMING_PAUSE)
                            found = WHITENULL_llll;
                        break;
                        
                    case k_PLAYKEYS_END:
                        if (incoming == k_PLAYKEYS_INCOMING_END)
                            found = WHITENULL_llll;
                        break;
                        
                    case k_PLAYKEYS_ROUTER:
                        found = llll_get();
                        if (router)
                            llll_appendsym(found, router);
                        break;
                        
                        
                    default:
                        break;
                }
                
                if (found) {
                    if (found == WHITENULL_llll) {
                        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, outlet);
                    } else {
                        x->n_keys[outlet].exists = 1;
                        llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, found, outlet);
                    }
                } else {
                    llll_retain(x->n_empty);
                    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_empty, outlet);
                }
            } else {
                if (x->n_nullmode == 2) {
                    llll_retain(x->n_empty);
                    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_empty, outlet);
                }
            }
        }

        llll_release(in_ll);
        x->n_ob.l_rebuild = 0;
        playkeys_output(x);
    } else {
        llll_release(in_ll);
        x->n_ob.l_rebuild = 0;
    }
}

long playkeys_func(t_hatom *key, t_llll *what)
{
    return hatom_eq(key, &what->l_head->l_hatom);
}

void playkeys_assist(t_playkeys *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a == 0)    sprintf(s, "llll from playout"); // @out 0 @type llll @digest llll from playout
                                                     // @description The llll coming from <o>bach.roll</o>'s or <o>bach.score</o>'s
                                                     // playout, containing note information in playout syntax
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        switch (x->n_keys[a].property) {
            case k_PLAYKEYS_SLOT:
                switch (x->n_keys[a].specification.h_type) {
                    case H_LONG:
                        sprintf(s, "llll (%s): slot " ATOM_LONG_PRINTF_FMT, type, hatom_getlong(&x->n_keys[a].specification));
                        break;
                    case H_SYM:
                        sprintf(s, "llll (%s): slot %s", type, hatom_getsym(&x->n_keys[a].specification)->s_name);
                        break;
                        
                    default:
                        sprintf(s, "llll (%s): unknown slot", type);
                        break;
            }
                break;
            case k_PLAYKEYS_PLAY:
            case k_PLAYKEYS_STOP:
            case k_PLAYKEYS_PAUSE:
            case k_PLAYKEYS_END:
                sprintf(s, "bang for key %s", property_to_symbol(x->n_keys[a].property)->s_name);
                break;
            default:
                sprintf(s, "llll (%s): %s", type, property_to_symbol(x->n_keys[a].property)->s_name);
                break;
        }
        // @out 0 @loop 1 @type llll @digest Found match for the corresponding key
    }
}

void playkeys_inletinfo(t_playkeys *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void playkeys_free(t_playkeys *x)
{
    llll_free(x->n_process);
    llll_free(x->n_note_commands);
    llll_free(x->n_chord_commands);
    llll_free(x->n_rest_commands);

    bach_freeptr(x->n_keys);
    llll_free(x->n_empty);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_playkeys *playkeys_new(t_symbol *s, short ac, t_atom *av)
{
    t_playkeys *x = NULL;
    t_max_err err = 0;
    long true_ac;
    char outlets[LLLL_MAX_OUTLETS], *this_outlets = outlets;
    t_playkeys_key *this_keys;
    
    true_ac = MIN(attr_args_offset(ac, av), LLLL_MAX_OUTLETS - 1);
    
    if ((x = (t_playkeys *) object_alloc_debug(playkeys_class))) {
        // @arg 0 @name playkeys @type anything @digest Parameters
        // @description The names of the parameters to retrieve.
        // Use an llll of type <b>[slot <m>number</m>]</b> or
        // <b>[slot <m>name</m>]</b> to retrieve a given slot.
        // If you need to retrieve multiple slots you can also
        // join them in a single llll in the form
        // <b>[slot <m>name_or_number</m> <m>name_or_number</m>...]</b>.
        // Allowed parameters to retrieve correspond to the following symbols:
        // "type", "onset", "symonset", "cents", "pitch", "duration", "symduration", "tail", "velocity",
        // "midichannel", "tie", "voicenumber", "chordindex", "noteindex, "path" (these last three only meaningful
        // if <m>playoutfullpath</m> is active for the notation object), "measurenumber"
        // (only meaningful for notes and chords if <m>playoutfullpath</m> is active for the notation object), "breakpoints",
        // "measureinfo", "name", "tempo", "quartertempo", "slot", "playoffset" (for partial played notes with
        // <m>playpartialnotes</m> set to 2), "role" (for markers only), "slots" (all slots)
        // In addition to these,
        // also "play", "stop", "pause", "end" keys are allowed; the "router" key will output the incoming router message;
        // they will report the corresponding actions with a bang.
        // As a shortcut for dynamics-, lyrics-, articulations- and noteheads-slot (whose numbers are settable via the four corresponding attributes)
        // the "dynamics", "lyrics", "articulations" and "noteheads" symbol can be used.
        
        x->n_process = llll_make();
        x->n_note_commands = llll_make();
        x->n_chord_commands = llll_make();
        x->n_rest_commands = llll_make();
        
        reset_warnings(x);

        x->n_notationitems_to_process = -1; // all of them

        t_llll *args_ll = llll_parse(true_ac, av);

        t_llll *args_ll_flat = llll_clone(args_ll);
        llll_flatten(args_ll_flat, 0, 0);
        this_keys = x->n_keys = (t_playkeys_key *) bach_newptr((args_ll_flat ? args_ll_flat->l_size + 1 : 1) * sizeof(t_playkeys_key));
        llll_free(args_ll_flat);
        
        
        x->n_flattenfornotes = 1;
        x->n_nullmode = 1;
        x->n_use_default_breakpoints = 1;
        
        atom_setlong(&x->n_dynamicsslot, BACH_DEFAULT_SLOT_DYNAMICS);
        atom_setlong(&x->n_lyricsslot, BACH_DEFAULT_SLOT_LYRICS);
        atom_setlong(&x->n_articulationsslot, BACH_DEFAULT_SLOT_ARTICULATIONS);
        atom_setlong(&x->n_noteheadslot, BACH_DEFAULT_SLOT_NOTEHEADS);
        atom_setlong(&x->n_annotationslot, BACH_DEFAULT_SLOT_ANNOTATIONS);
        x->n_must_iterate_on_output = false;
        
        attr_args_process(x, ac, av);
        
        if (!args_ll || !args_ll->l_head) {
            object_error((t_object *)x, "No keys defined, or wrong keys syntax.");
            llll_free(args_ll);
            llll_free(args_ll_flat);
            return NULL;
        }
        
        long i = 0;
        
        
        t_llll_stack *stack = llll_stack_new();
        t_llllelem *el = args_ll->l_head;
        t_symbol *allowed_command_router = NULL;
        long curr_allowed_notationitems = -1; // default
        while (i < LLLL_MAX_OUTLETS - 1) {
            while (el && i < LLLL_MAX_OUTLETS - 1) {
                switch(el->l_hatom.h_type) {
                    case H_SYM:
                    {
                        t_symbol *sym = hatom_getsym(&el->l_hatom);
                        this_keys->property = symbol_to_property(sym);
                        this_keys->allowed_command_router = allowed_command_router;
                        if (this_keys->property == k_PLAYKEYS_NONE) {
                            object_error((t_object *)x, "Unrecognized key '%s', can't create object.", sym ? sym->s_name : "");
                            llll_free(args_ll);
                            llll_free(args_ll_flat);
                            return NULL;
                        }
                        this_keys->specification.h_type = H_NULL;
                        this_keys->allowed_notationitems = curr_allowed_notationitems >= 0 ? curr_allowed_notationitems :get_default_allowed_notationitems_for_property(this_keys->property);
                        *this_outlets++ = '4';
                        i++;
                        this_keys++;
                    }
                        break;
                        
                    case H_LONG:
                    {
                        long slotnum = hatom_getlong(&el->l_hatom);
                        this_keys->property = k_PLAYKEYS_SLOT;
                        this_keys->allowed_command_router = allowed_command_router;
                        hatom_setlong(&this_keys->specification, slotnum);
                        this_keys->allowed_notationitems = curr_allowed_notationitems >= 0 ? curr_allowed_notationitems :get_default_allowed_notationitems_for_property(this_keys->property);
                        *this_outlets++ = '4';
                        i++;
                        this_keys++;
                    }
                        break;
                        
                    case H_LLLL:
                    {
                        t_llll *ll = hatom_getllll(&el->l_hatom);
                        char router_is_sym = ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM;
                        
                        if (router_is_sym && (hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slot || hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slots)) {
                            for (t_llllelem *tempel = ll->l_head->l_next; tempel; tempel = tempel->l_next) {
                                this_keys->property = k_PLAYKEYS_SLOT;
                                this_keys->allowed_command_router = allowed_command_router;
                                this_keys->allowed_notationitems = curr_allowed_notationitems >= 0 ? curr_allowed_notationitems : get_default_allowed_notationitems_for_property(this_keys->property);
                                
                                if (hatom_gettype(&tempel->l_hatom) == H_SYM) {
                                    t_symbol *ts = hatom_getsym(&tempel->l_hatom);
                                    hatom_setsym(&this_keys->specification, ts);
                                    
                                    long prop = symbol_to_property(ts);
                                    if (prop == k_PLAYKEYS_ANNOTATION || prop == k_PLAYKEYS_NOTEHEAD || prop == k_PLAYKEYS_ARTICULATIONS || prop == k_PLAYKEYS_DYNAMICS || k_PLAYKEYS_LYRICS) {
                                        this_keys->property = prop;
                                        this_keys->specification.h_type = H_NULL;
                                        this_keys->allowed_notationitems = curr_allowed_notationitems >= 0 ? curr_allowed_notationitems :get_default_allowed_notationitems_for_property(this_keys->property);
                                    }

                                } else
                                    hatom_setlong(&this_keys->specification, hatom_getlong(&tempel->l_hatom));
                                
                                *this_outlets++ = '4';
                                i++;
                                this_keys++;
                            }

                        } else if (router_is_sym) {
                            curr_allowed_notationitems = symbol_to_incoming(hatom_getsym(&ll->l_head->l_hatom));
                            if (curr_allowed_notationitems) {
                                allowed_command_router = NULL;
                                llll_stack_push(stack, el->l_next);
                                el = ll->l_head;
                            } else {
                                // defining a command
                                long operate_on = 0;
                                allowed_command_router = hatom_getsym(&ll->l_head->l_hatom);
                                
                                if (is_symbol_in_llll_first_level(x->n_note_commands, allowed_command_router)) {
                                    operate_on = 1;
                                } else if (is_symbol_in_llll_first_level(x->n_chord_commands, allowed_command_router)) {
                                        operate_on = 2;
                                } else if (is_symbol_in_llll_first_level(x->n_rest_commands, allowed_command_router)) {
                                    operate_on = 3;
                                }

                                if (operate_on == 0) { // the command was not assigned to any of the routers
                                    // ASSIGNING IT TO NOTES
                                    operate_on = 1;
                                    x->n_notationitems_to_process |= k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND + k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND;
                                    llll_appendsym(x->n_note_commands, allowed_command_router);
                                }
                                
                                if (operate_on == 2) {
                                    curr_allowed_notationitems = k_PLAYKEYS_INCOMING_SCORECHORD_COMMAND + k_PLAYKEYS_INCOMING_ROLLCHORD_COMMAND;
                                } else if (operate_on == 3) {
                                    curr_allowed_notationitems = k_PLAYKEYS_INCOMING_SCOREREST_COMMAND;
                                } else {
                                    curr_allowed_notationitems = k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND + k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND;
                                }
                                
                                llll_stack_push(stack, el->l_next);
                                el = ll->l_head;
                            }
                        } else {
                            object_error((t_object *)x, "Unknown llll key.");
                            llll_free(args_ll);
                            llll_free(args_ll_flat);
                            return NULL;
                        }
                    }
                        break;
                        
                    default:
                    {
                        object_error((t_object *)x, "Unknown key.");
                        llll_free(args_ll);
                        llll_free(args_ll_flat);
                        return NULL;
                    }
                        break;
                }
                el = el->l_next;
            }
            
            if (!stack->s_items)
                break; 
            
            el = (t_llllelem *) llll_stack_pop(stack);
            curr_allowed_notationitems = -1; // default
        }
        llll_stack_destroy(stack);

        
        /*
        for (t_llllelem *el = args_ll->l_head; el && i < LLLL_MAX_OUTLETS - 1; el = el->l_next) {
            if (hatom_gettype(&el->l_hatom) == H_SYM) {
                t_symbol *sym = hatom_getsym(&el->l_hatom);
                this_keys->property = symbol_to_property(sym);
                if (this_keys->property == k_PLAYKEYS_NONE) {
                    object_error((t_object *)x, "Unrecognized key '%s', can't create object.", sym ? sym->s_name : "");
                    llll_free(args_ll);
                    llll_free(args_ll_flat);
                    return NULL;
                }
                this_keys->specification.h_type = H_NULL;
                this_keys->allowed_notationitems = get_default_allowed_notationitem_for_property(this_keys->property);
                *this_outlets++ = '4';
                i++;
                this_keys++;
            } else if (hatom_gettype(&el->l_hatom) == H_LONG) {
                long slotnum = hatom_getlong(&el->l_hatom);
                this_keys->property = k_PLAYKEYS_SLOT;
                hatom_setlong(&this_keys->specification, slotnum);
                this_keys->allowed_notationitems = get_default_allowed_notationitem_for_property(this_keys->property);
                *this_outlets++ = '4';
                i++;
                this_keys++;
            } else if (hatom_gettype(&el->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&el->l_hatom);
                char router_is_sym = ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_SYM;
                if (router_is_sym && (hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slot || hatom_getsym(&ll->l_head->l_hatom) == _llllobj_sym_slots)) {
                    for (t_llllelem *tempel = ll->l_head->l_next; tempel; tempel = tempel->l_next) {
                        this_keys->property = k_PLAYKEYS_SLOT;
                        this_keys->allowed_notationitems = get_default_allowed_notationitem_for_property(this_keys->property);
                        if (hatom_gettype(&tempel->l_hatom) == H_SYM)
                            hatom_setsym(&this_keys->specification, hatom_getsym(&tempel->l_hatom));
                        else
                            hatom_setlong(&this_keys->specification, hatom_getlong(&tempel->l_hatom));
                        *this_outlets++ = '4';
                        i++;
                        this_keys++;
                    }
                } else if (router_is_sym) {
                    this_keys->allowed_notationitems = symbol_to_incoming(hatom_getsym(&ll->l_head->l_hatom));
                    
                } else {
                    object_error((t_object *)x, "Unknown llll key.");
                    llll_free(args_ll);
                    llll_free(args_ll_flat);
                    return NULL;
                }
            } else {
                object_error((t_object *)x, "Unknown key.");
                llll_free(args_ll);
                llll_free(args_ll_flat);
                return NULL;
            }
        } */
        
        *this_outlets = 0;
        this_keys->property = k_PLAYKEYS_NONE;
        llll_free(args_ll);
        
        llllobj_obj_setup((t_llllobj_object *) x, 1, outlets);
        
        x->n_empty = llll_get();
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
