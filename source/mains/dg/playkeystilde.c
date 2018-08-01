/**
 @file
 playkeys~.c
 
 @name
 bach.playkeys~
 
 @realname
 bach.playkeys~
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest
 Get play information at sample rate
 
 @description
 Outputs selected parameters of <o>bach.score</o>'s and <o>bach.roll</o>'s playout information at sample rate.
 
 @discussion
 
 @category
 bach, bach objects, bach notation, bach dsp
 
 @keywords
 keys, play, unpack, unpacknote, parameter, playout, syntax, audio, tick, sample, rate
 
 @seealso
 bach.playkeys, bach.keys, bach.roll, bach.score
 
 @owner
 Daniele Ghisi
 */


#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "llll_commons_ext.h"

#include "playkeys_commons.h"
#include "z_dsp.h"


typedef struct _playkeystilde
{
    struct llllobj_object	n_ob;
    
    t_playkeys_settings   sett;

    t_llll					*n_empty;
} t_playkeystilde;


t_max_err playkeystilde_getattr_process(t_playkeystilde *x, t_object *attr, long *ac, t_atom **av);
t_max_err playkeystilde_setattr_process(t_playkeystilde *x, t_object *attr, long ac, t_atom *av);


void playkeystilde_assist(t_playkeystilde *x, void *b, long m, long a, char *s);
void playkeystilde_inletinfo(t_playkeystilde *x, void *b, long a, char *t);

t_playkeystilde *playkeystilde_new(t_symbol *s, short ac, t_atom *av);
void playkeystilde_free(t_playkeystilde *x);

void playkeystilde_int(t_playkeystilde *x, t_atom_long v);
void playkeystilde_float(t_playkeystilde *x, double v);
void playkeystilde_anything(t_playkeystilde *x, t_symbol *msg, long ac, t_atom *av);

long playkeystilde_func(t_hatom *key, t_llll *what);
void playkeystilde_output(t_playkeystilde *x);

void playkeystilde_dsp64(t_playkeystilde *x, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags);
void playkeystilde_perform64(t_playkeystilde *x, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags, void *userparam);

t_class *playkeystilde_class;


int T_EXPORT main()
{
    t_class *c;
    
    common_symbols_init();
    llllobj_common_symbols_init();
    
    if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
        error("bach: bad installation");
        return 1;
    }
    
    c = class_new("bach.playkeys~", (method)playkeystilde_new, (method)playkeystilde_free, (short)sizeof(t_playkeystilde), 0L, A_GIMME, 0);
    
    // @method llll @digest Search the llll for the specified playkeys
    // @description
    // The first elements of the llll and all its sublists are examined, traversing the llll depth-first as in <o>bach.iter</o>.
    // When a first element is found to match one of <o>bach.playkeys~</o>'s arguments (the "playkeys"),
    // the corresponding llll is output, with or without the key according to the <m>keep</m> attribute,
    // and that key is no further looked for.<br />
    // Anyway, all the found lllls are output right-to-left, according to their order in <o>bach.playkeys~</o>'s arguments
    // and regardless of their positions in the original llll.
    // In case of multiple possible matches, the first matching llll that is found is output.
    // If no match is found for any key, a bang is output from the rightmost outlet.
    class_addmethod(c, (method)playkeystilde_anything,	"anything",		A_GIMME,	0);
    class_addmethod(c, (method)playkeystilde_int,		"int",			A_LONG,		0);
    class_addmethod(c, (method)playkeystilde_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)playkeystilde_anything,	"list",			A_GIMME,	0);
    
    class_addmethod(c, (method)playkeystilde_dsp64,        "dsp64",    A_CANT, 0);
    
    class_addmethod(c, (method)playkeystilde_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)playkeystilde_inletinfo,	"inletinfo",	A_CANT,		0);
    
    
    CLASS_STICKY_ATTR(c,"category",0,"Settings");

    CLASS_ATTR_LLLL_SUBSTRUCTURE(c, "routers", 0, t_playkeystilde, sett, t_playkeys_settings, n_process, playkeystilde_getattr_process, playkeystilde_setattr_process);
    CLASS_ATTR_LABEL(c, "routers", 0, "Routers To Accept");
    CLASS_ATTR_STYLE(c, "routers",		0, "text");
    CLASS_ATTR_BASIC(c, "routers", 0);
    // @description List of router symbols which will be accepted. Leave empty to process all possible routers.
    // E.g. <b>note tempo</b> will only accept "note"- and "tempo"-routed playout lllls. <br />
    // You can have <o>bach.playkeys~</o> intercept commands as well, provided that you set aliases via an llll starting
    // with "note", "chord" or "rest" (depending on the type of alias). E.g. <b>@routers note (note mynotecommand1 mynotecommand2)</b>
    // will intercept <b>note</b> messages, as well as note commands <b>mynotecommand1</b> and <b>mynotecommand2</b>.
    // To only intercept commands, simply use something like <b>@routers (note mynotecommand1 mynotecommand2)</b>.
    // If you want to add some commands for acceptance (and to keep everything else accepted) use "+" as first element, such as in
    // <b>@routers + (rest myrestcommand)</b>.

    
    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "wrapmode",		0,	t_playkeystilde, sett, t_playkeys_settings, n_flattenfornotes);
    CLASS_ATTR_LABEL(c, "wrapmode",		0, "Only Wrap Chords llll Data");
    CLASS_ATTR_STYLE(c, "wrapmode",		0, "onoff");
    CLASS_ATTR_BASIC(c, "wrapmode", 0);
    // @description When set to 1, it only wraps llll parameters if the playout input is a chord.

    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "nullmode",		0,	t_playkeystilde, sett, t_playkeys_settings, n_nullmode);
    CLASS_ATTR_LABEL(c, "nullmode",		0, "Output null");
    CLASS_ATTR_STYLE(c, "nullmode",		0, "enumindex");
    CLASS_ATTR_ENUMINDEX(c,"nullmode", 0, "Never For Empty Keys For Unmatched Keys");
    CLASS_ATTR_BASIC(c, "nullmode", 0);
    // @description Handles when <b>null</b> is output from a given key outlet.
    // 0 = Never; 1 = only for keys without any content (default); 2 = also for unmatched keys (e.g. keys that has no meaning for the specific notation item,
    // such as velocity for markers, etc.).

    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "defaultbreakpoints",		0,	t_playkeystilde, sett, t_playkeys_settings, n_use_default_breakpoints);
    CLASS_ATTR_LABEL(c, "defaultbreakpoints",		0, "Use Default Breakpoints");
    CLASS_ATTR_STYLE(c, "defaultbreakpoints",		0, "onoff");
    // @description When set to 1, uses default breakpoints for notes without glissandi.

    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "breakpointshavevelocity",		0,	t_playkeystilde, sett, t_playkeys_settings, n_breakpoints_have_velocity);
    CLASS_ATTR_LABEL(c, "breakpointshavevelocity",		0, "Breakpoints Have Velocity");
    CLASS_ATTR_STYLE(c, "breakpointshavevelocity",		0, "onoff");
    // @description Toggles the ability, for pitch breakpoints, to have their own independent velocity.
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");

    
    CLASS_STICKY_ATTR(c,"category",0,"Slots");

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "dynamicsslot",		0,	t_playkeystilde, sett, t_playkeys_settings, n_dynamicsslot);
    CLASS_ATTR_STYLE_LABEL(c, "dynamicsslot", 0, "text", "Dynamics Slot Number");
    // @description Sets the number of the slot containing dynamics (0 if none).

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "lyricsslot",		0,	t_playkeystilde, sett, t_playkeys_settings, n_lyricsslot);
    CLASS_ATTR_STYLE_LABEL(c, "lyricsslot", 0, "text", "Lyrics Slot Number");
    // @description Sets the number of the slot containing lyrics (0 if none).

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "articulationsslot",		0,	t_playkeystilde, sett, t_playkeys_settings, n_articulationsslot);
    CLASS_ATTR_STYLE_LABEL(c, "articulationsslot", 0, "text", "Articulations Slot Number");
    // @description Sets the number of the slot containing articulations (0 if none).

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "noteheadslot",		0,	t_playkeystilde, sett, t_playkeys_settings, n_noteheadslot);
    CLASS_ATTR_STYLE_LABEL(c, "noteheadslot", 0, "text", "Noteheads Slot Number");
    // @description Sets the number of the slot containing noteheads (0 if none).

    CLASS_STICKY_ATTR_CLEAR(c, "category");


    llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_MSP);

    class_dspinit(c);
    class_register(CLASS_BOX, c);
    playkeystilde_class = c;
    
    dev_post("bach.playkeystilde compiled %s %s", __DATE__, __TIME__);
    
    return 0;
}


void playkeystilde_output(t_playkeystilde *x)
{
    /*
    long i;
    if (x->sett.n_must_iterate_on_output) {
        // gotta be complicated
        // To be implemented. No iteration for the time being.
    
    } else {
        for (i = x->n_ob.l_numouts - 1; i >= 0; i--) {
            if (x->sett.n_keys[i].property != k_PLAYKEYS_NONE && (x->sett.n_keys[i].exists || x->sett.n_nullmode == 2))
                llllobj_shoot_llll((t_object *) x, LLLL_OBJ_MSP, i);
        }
    }
     */
}

void playkeystilde_int(t_playkeystilde *x, t_atom_long v)
{
    t_atom outatom;
    atom_setlong(&outatom, v);
    playkeystilde_anything(x, _sym_int, 1, &outatom);
}

void playkeystilde_float(t_playkeystilde *x, double v)
{
    t_atom outatom;
    atom_setfloat(&outatom, v);
    playkeystilde_anything(x, _sym_float, 1, &outatom);
}

t_max_err playkeystilde_getattr_process(t_playkeystilde *x, t_object *attr, long *ac, t_atom **av)
{
    return playkeysobj_getattr_process((t_object *)x, &x->sett, attr, ac, av);
}

t_max_err playkeystilde_setattr_process(t_playkeystilde *x, t_object *attr, long ac, t_atom *av)
{
    return playkeysobj_setattr_process((t_object *)x, &x->sett, attr, ac, av, true);
}


void playkeystilde_anything(t_playkeystilde *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *in_ll, *found;
    
    if (msg != _sym_bang) {
        in_ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_MSP, msg, ac, av, 0);
        if (!in_ll)
            return;
    } else
        in_ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_MSP, 0, 0);
    
    
    long incoming = k_PLAYKEYS_INCOMING_UNKNOWN;
    t_symbol *router = NULL;
    char must_process_incoming = playkeysobj_handle_incoming((t_object *)x, &x->sett, in_ll, &incoming, &router);
    
    if (must_process_incoming) {
        t_playkeys_key *this_key;
        long outlet;
        for (outlet = 0, this_key = x->sett.n_keys; this_key && this_key->property != k_PLAYKEYS_NONE; this_key++, outlet++) {
            this_key->exists = 0;
            
            if (incoming & this_key->allowed_notationitems) { // must process key
                
                if ((incoming == k_PLAYKEYS_INCOMING_ROLLNOTE_COMMAND || incoming == k_PLAYKEYS_INCOMING_SCORENOTE_COMMAND || incoming == k_PLAYKEYS_INCOMING_SCOREREST_COMMAND) && this_key->allowed_command_router != router)
                    continue; // not the right command
                
                found = playkeysobj_get_values((t_object *)x, &x->sett, this_key, incoming, router, in_ll);
                
                if (found) {
                    if (found == WHITENULL_llll) {
                        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_MSP, outlet);
                    } else {
                        x->sett.n_keys[outlet].exists = 1;
                        llllobj_gunload_llll((t_object *) x, LLLL_OBJ_MSP, found, outlet);
                    }
                } else {
                    llll_retain(x->n_empty);
                    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_MSP, x->n_empty, outlet);
                }
            } else {
                if (x->sett.n_nullmode == 2) {
                    llll_retain(x->n_empty);
                    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_MSP, x->n_empty, outlet);
                }
            }
        }

        llll_release(in_ll);
        x->n_ob.l_rebuild = 0;
        playkeystilde_output(x);
    } else {
        llll_release(in_ll);
        x->n_ob.l_rebuild = 0;
    }
}


void playkeystilde_assist(t_playkeystilde *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {
        if (a == 0)	sprintf(s, "llll from playout"); // @out 0 @type llll @digest llll from playout
                                                     // @description The llll coming from <o>bach.roll</o>'s or <o>bach.score</o>'s
                                                     // playout, containing note information in playout syntax
    } else {
        switch (x->sett.n_keys[a].property) {
            case k_PLAYKEYS_SLOT:
                switch (x->sett.n_keys[a].specification.h_type) {
                    case H_LONG:
                        sprintf(s, "signal: slot " ATOM_LONG_PRINTF_FMT, hatom_getlong(&x->sett.n_keys[a].specification));
                        break;
                    case H_SYM:
                        sprintf(s, "signal: slot %s", hatom_getsym(&x->sett.n_keys[a].specification)->s_name);
                        break;
                        
                    default:
                        sprintf(s, "signal: unknown slot");
                        break;
            }
                break;
            case k_PLAYKEYS_PLAY:
            case k_PLAYKEYS_STOP:
            case k_PLAYKEYS_PAUSE:
            case k_PLAYKEYS_END:
                sprintf(s, "bang for key %s", property_to_symbol(x->sett.n_keys[a].property)->s_name);
                break;
            default:
                sprintf(s, "signal: %s", property_to_symbol(x->sett.n_keys[a].property)->s_name);
                break;
        }
        // @out 0 @loop 1 @type signal/bang @digest Signal for the corresponding key, or bang for play/stop/pause/end keys
    }
}

void playkeystilde_inletinfo(t_playkeystilde *x, void *b, long a, char *t)
{
    if (a)
        *t = 1;
}

void playkeystilde_free(t_playkeystilde *x)
{
    playkeyssettings_free(&x->sett);
    llll_free(x->n_empty);
    dsp_free((t_pxobject *)x);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_playkeystilde *playkeystilde_new(t_symbol *s, short ac, t_atom *av)
{
    t_playkeystilde *x = NULL;
    t_max_err err = 0;
    long true_ac;
    char outlets[LLLL_MAX_OUTLETS];
    
    true_ac = MIN(attr_args_offset(ac, av), LLLL_MAX_OUTLETS - 1);
    
    if ((x = (t_playkeystilde *) object_alloc_debug(playkeystilde_class))) {
        // @arg 0 @name playkeystilde @type anything @digest parameters
        // @description The names of the parameters to retrieve.
        // Use an llll of type <b>(slot <m>number</m>)</b> or
        // <b>(slot <m>name</m>)</b> to retrieve a given slot.
        // If you need to retrieve multiple slots you can also
        // join them in a single llll in the form
        // <b>(slot <m>name_or_number</m> <m>name_or_number</m>...)</b>.
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
        
        t_llll *args_ll = llll_parse(true_ac, av);

        playkeyssettings_init(&x->sett, args_ll);
        
        attr_args_process(x, ac, av);
        
        if (playkeysobj_parse_keys((t_object *)x, &x->sett, args_ll, outlets, true)) // llll_free(args_ll) is in here
            return NULL;
        
        dsp_setup((t_pxobject *)x, 0); // no MSP inlets
        llllobj_obj_setup((t_llllobj_object *) x, 1, outlets);
        
        x->n_empty = llll_get();
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_MSP);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}




// registers a function for the signal chain in Max
void playkeystilde_dsp64(t_playkeystilde *x, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags)
{
    post("my sample rate is: %f", samplerate);
    
    // instead of calling dsp_add(), we send the "dsp_add64" message to the object representing the dsp chain
    // the arguments passed are:
    // 1: the dsp64 object passed-in by the calling function
    // 2: the symbol of the "dsp_add64" message we are sending
    // 3: a pointer to your object
    // 4: a pointer to your 64-bit perform method
    // 5: flags to alter how the signal chain handles your object -- just pass 0
    // 6: a generic pointer that you can use to pass any additional data to your perform method
    
    object_method(dsp64, gensym("dsp_add64"), x, playkeystilde_perform64, 0, NULL);
}


// this is the 64-bit perform method audio vectors
void playkeystilde_perform64(t_playkeystilde *x, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags, void *userparam)
{
    t_double *outL = outs[0];    // we get audio for each outlet of the object from the **outs argument
    int n = sampleframes;
    
    // this perform method simply copies the input to the output, offsetting the value
    while (n--)
        *outL++ = 0.;
}
