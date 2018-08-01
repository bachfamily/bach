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
 
 @status
 experimental
 
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


typedef struct _playkeystilde_ramp
{
    long    num_segments;
    long    *sample_start;
    long    *sample_end;
    double  *value_start;
    double  *value_end;
    double  *slope;
    long    curr_segment;
    long    curr_sample;
} t_playkeystilde_ramp;

typedef struct _playkeystilde
{
    struct llllobj_pxobject	n_ob;
    
    long                  num_outlets;
    char                  audiooutlet2objoutlet[LLLL_MAX_OUTLETS];
    double                outlet_val[LLLL_MAX_OUTLETS]; // current dsp value for specific outlet
    t_playkeystilde_ramp  outlet_ramp[LLLL_MAX_OUTLETS];

    t_playkeys_settings   sett;
    
    long                  samplerate;
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
    
    dev_post("bach.playkeys~ compiled %s %s", __DATE__, __TIME__);
    
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




void playkeystilde_ramp_free(t_playkeystilde *x)
{
    for (long outlet = 0; outlet < x->num_outlets; outlet ++) {
        if (x->outlet_ramp[outlet].sample_start)
            bach_freeptr(x->outlet_ramp[outlet].sample_start);
        if (x->outlet_ramp[outlet].sample_end)
            bach_freeptr(x->outlet_ramp[outlet].sample_end);
        if (x->outlet_ramp[outlet].value_start)
            bach_freeptr(x->outlet_ramp[outlet].value_start);
        if (x->outlet_ramp[outlet].value_end)
            bach_freeptr(x->outlet_ramp[outlet].value_end);
        if (x->outlet_ramp[outlet].slope)
            bach_freeptr(x->outlet_ramp[outlet].slope);
    }
}

void playkeystilde_ramp_init(t_playkeystilde *x)
{
    for (long outlet = 0; outlet < x->num_outlets; outlet ++) {
        x->outlet_ramp[outlet].sample_start = (long *)bach_newptrclear(sizeof(long));
        x->outlet_ramp[outlet].sample_end = (long *)bach_newptrclear(sizeof(long));
        x->outlet_ramp[outlet].value_start = (double *)bach_newptrclear(sizeof(double));
        x->outlet_ramp[outlet].value_end = (double *)bach_newptrclear(sizeof(double));
        x->outlet_ramp[outlet].slope = (double *)bach_newptrclear(sizeof(double));
        x->outlet_ramp[outlet].curr_segment = -1; // = no segment
    }
}

void llllelem_to_double_triplet(t_llllelem *el, double *t, double *y, double *s)
{
    if (hatom_gettype(&el->l_hatom) == H_LLLL) {
        t_llll *ll = hatom_getllll(&el->l_hatom);
        t_llllelem *temp = ll->l_head;
        if (temp) {
            *t = hatom_getdouble(&temp->l_hatom);
            temp = temp->l_next;
            if (temp) {
                *y = hatom_getdouble(&temp->l_hatom);
                temp = temp->l_next;
                if (temp)
                    *s = hatom_getdouble(&temp->l_hatom);
            }
        }
    } else {
        *t = 0;
        *y = hatom_getdouble(&el->l_hatom);
        *s = 0;
    }
}


void playkeystilde_fill_ramp(t_playkeystilde *x, long outlet, t_llll *ramp)
{
    long num_segments = ramp->l_size - 1;
    
    // checking if memory is enough
    if (num_segments > x->outlet_ramp[outlet].num_segments) {
        x->outlet_ramp[outlet].sample_start = (long *)bach_resizeptr(x->outlet_ramp[outlet].sample_start, num_segments * sizeof(long));
        x->outlet_ramp[outlet].sample_end = (long *)bach_resizeptr(x->outlet_ramp[outlet].sample_end, num_segments * sizeof(long));
        x->outlet_ramp[outlet].value_start = (double *)bach_resizeptr(x->outlet_ramp[outlet].value_start, num_segments * sizeof(double));
        x->outlet_ramp[outlet].value_end = (double *)bach_resizeptr(x->outlet_ramp[outlet].value_end, num_segments * sizeof(double));
        x->outlet_ramp[outlet].slope = (double *)bach_resizeptr(x->outlet_ramp[outlet].slope, num_segments * sizeof(double));
    }
    
    long i = 0;
    x->outlet_ramp[outlet].num_segments = MAX(0, num_segments);
    double this_t = 0, this_y = x->outlet_val[outlet], this_slope = 0;
    double prev_t = 0, prev_y = this_y, prev_slope = 0;
    
    t_llllelem *el = ramp->l_head;
    if (el) {
        llllelem_to_double_triplet(el, &prev_t, &prev_y, &prev_slope);
        el = el->l_next;
        for (; el; el = el->l_next, i++) {
            llllelem_to_double_triplet(el, &this_t, &this_y, &this_slope);
            x->outlet_ramp[outlet].sample_start[i] = (long)round(prev_t * x->samplerate);
            x->outlet_ramp[outlet].sample_start[i] = (long)round(this_t * x->samplerate);
            x->outlet_ramp[outlet].value_start[i] = prev_y;
            x->outlet_ramp[outlet].value_end[i] = this_y;
            x->outlet_ramp[outlet].slope[i] = this_slope;
            prev_t = this_t;
            prev_y = this_y;
            prev_slope = this_slope;
        }
    }
    
}

void playkeystilde_start_ramp(t_playkeystilde *x, long outlet, t_llll *ramp)
{
    playkeystilde_fill_ramp(x, outlet, ramp);
    x->outlet_ramp[outlet].curr_segment = 0;
    x->outlet_ramp[outlet].curr_sample = 0;
}

void playkeystilde_goto_value(t_playkeystilde *x, long outlet, double value)
{
    x->outlet_val[outlet] = value;
}

void playkeystilde_process_key_value(t_playkeystilde *x, long outlet, t_llll *key_value)
{
    while (key_value->l_depth > 2) {
        key_value = hatom_gettype(&key_value->l_head->l_hatom) == H_LLLL ? hatom_getllll(&key_value->l_head->l_hatom) : NULL;
    }
    
    if (key_value) {
        switch (key_value->l_depth) {
            case 1:
                if (key_value->l_head)
                    playkeystilde_goto_value(x, outlet, is_hatom_number(&key_value->l_head->l_hatom) ? hatom_getdouble(&key_value->l_head->l_hatom) : 0);
                break;
                
            case 2:
                playkeystilde_start_ramp(x, outlet, key_value);
                break;
            default:
                break;
        }
    }
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
                        playkeystilde_process_key_value(x, outlet, found);
//                        x->sett.n_keys[outlet].exists = 1;
//                        llllobj_gunload_llll((t_object *) x, LLLL_OBJ_MSP, found, outlet);
                    }
                } else {
//                    llll_retain(x->n_empty);
//                    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_MSP, x->n_empty, outlet);
                }
            } else {
                if (x->sett.n_nullmode == 2) {
//                    llll_retain(x->n_empty);
//                    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_MSP, x->n_empty, outlet);
                }
            }
        }

        llll_release(in_ll);
//        x->n_ob.l_rebuild = 0;
//        playkeystilde_output(x);
    } else {
        llll_release(in_ll);
//        x->n_ob.l_rebuild = 0;
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
        
        if (playkeysobj_parse_keys((t_object *)x, &x->sett, args_ll, outlets, true)) { // llll_free(args_ll) is in here
            playkeyssettings_free(&x->sett);
            object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
            return NULL;
        }
        
        long num_outlets = MIN(LLLL_MAX_OUTLETS, strlen(outlets));
        x->num_outlets = num_outlets;

        long j = 0;
        for (long i = 0; i < num_outlets; i++)
            x->audiooutlet2objoutlet[i] = (outlets[i] == 's') ? j++ : -1;
//        playkeystilde_ramp_init(x);
        
        dsp_setup((t_pxobject *)x, 1); // no MSP inlets
        llllobj_pxobj_setup((t_llllobj_pxobject *) x, 1, outlets);
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_MSP);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}

void playkeystilde_free(t_playkeystilde *x)
{
//    dsp_free((t_pxobject *)x);
//    playkeystilde_ramp_free(x);
//    playkeyssettings_free(&x->sett);
//    llllobj_pxobj_free((t_llllobj_pxobject *) x);
}




// registers a function for the signal chain in Max
void playkeystilde_dsp64(t_playkeystilde *x, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags)
{
    x->samplerate = samplerate;
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
/*    if (numouts > 0) {
        t_double *outL = outs[0];    // we get audio for each outlet of the object from the **outs argument
        int n = sampleframes;
        t_playkeystilde_ramp *ramp;
        long curr_segment;
        long i;
        
        for (long o = 0; o < x->num_outlets; o++) {
            long oo = x->audiooutlet2objoutlet[o];
            if (oo >= 0) {
                // are we inside a ramp?
                ramp = &x->outlet_ramp[oo];
                curr_segment = ramp->curr_segment;
                if (curr_segment >= 0) {
                    for (i = 0; i < n; i++) {
                        if (ramp->curr_sample > ramp->sample_end[curr_segment]) {
                            if (curr_segment == ramp->num_segments) {
                                // end of the ramp
                                curr_segment = -1;
                                break;
                            } else {
                                curr_segment = ramp->curr_segment = curr_segment + 1;
                            }
                        }
                        outL[i] = rescale_with_slope(ramp->curr_sample++, ramp->sample_start[curr_segment], ramp->sample_end[curr_segment], ramp->value_start[curr_segment], ramp->value_end[curr_segment], ramp->slope[curr_segment]);
                    }
                    
                    // some left over after the end of the ramp?
                    if (i < n) {
                        double end_val = ramp->sample_end[ramp->num_segments - 1];
                        for (; i < n; i++) {
                            outL[i] = end_val;
                        }
                    }
                } else {
                    double val = x->outlet_val[oo];
                    while (n--)
                        *outL++ = val;
                }
            }
        }
    } */
    
    if (numouts > 0) {
        t_double *outL = outs[0];
        long n = sampleframes;
        while (n--)
            *outL++ = 0.;
    }

}
