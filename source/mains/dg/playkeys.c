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

#include "playkeys_commons.h"


typedef struct _playkeys
{
    struct llllobj_object	n_ob;
    
    t_playkeys_settings   sett;

    t_llll					*n_empty;
} t_playkeys;


t_max_err playkeys_getattr_process(t_playkeys *x, t_object *attr, long *ac, t_atom **av);
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
    class_addmethod(c, (method)playkeys_anything,	"anything",		A_GIMME,	0);
    class_addmethod(c, (method)playkeys_int,		"int",			A_LONG,		0);
    class_addmethod(c, (method)playkeys_float,		"float",		A_FLOAT,	0);
    class_addmethod(c, (method)playkeys_anything,	"list",			A_GIMME,	0);
    
    // @method bang @digest Perform last operation
    // @description The playkeys are searched for in the most recently received llll.
    class_addmethod(c, (method)playkeys_bang,		"bang",			0);
    
    class_addmethod(c, (method)playkeys_assist,		"assist",		A_CANT,		0);
    class_addmethod(c, (method)playkeys_inletinfo,	"inletinfo",	A_CANT,		0);
    
    
    CLASS_STICKY_ATTR(c,"category",0,"Settings");

    CLASS_ATTR_LLLL_SUBSTRUCTURE(c, "routers", 0, t_playkeys, sett, t_playkeys_settings, n_process, playkeys_getattr_process, playkeys_setattr_process);
    CLASS_ATTR_LABEL(c, "routers", 0, "Routers To Accept");
    CLASS_ATTR_STYLE(c, "routers",		0, "text");
    CLASS_ATTR_BASIC(c, "routers", 0);
    // @description List of router symbols which will be accepted. Leave empty to process all possible routers.
    // E.g. <b>note tempo</b> will only accept "note"- and "tempo"-routed playout lllls. <br />
    // You can have <o>bach.playkeys</o> intercept commands as well, provided that you set aliases via an llll starting
    // with "note", "chord" or "rest" (depending on the type of alias). E.g. <b>@routers note (note mynotecommand1 mynotecommand2)</b>
    // will intercept <b>note</b> messages, as well as note commands <b>mynotecommand1</b> and <b>mynotecommand2</b>.
    // To only intercept commands, simply use something like <b>@routers (note mynotecommand1 mynotecommand2)</b>.
    // If you want to add some commands for acceptance (and to keep everything else accepted) use "+" as first element, such as in
    // <b>@routers + (rest myrestcommand)</b>.

    
    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "wrapmode",		0,	t_playkeys, sett, t_playkeys_settings, n_flattenfornotes);
    CLASS_ATTR_LABEL(c, "wrapmode",		0, "Only Wrap Chords llll Data");
    CLASS_ATTR_STYLE(c, "wrapmode",		0, "onoff");
    CLASS_ATTR_BASIC(c, "wrapmode", 0);
    // @description When set to 1, it only wraps llll parameters if the playout input is a chord.

    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "nullmode",		0,	t_playkeys, sett, t_playkeys_settings, n_nullmode);
    CLASS_ATTR_LABEL(c, "nullmode",		0, "Output null");
    CLASS_ATTR_STYLE(c, "nullmode",		0, "enumindex");
    CLASS_ATTR_ENUMINDEX(c,"nullmode", 0, "Never For Empty Keys For Unmatched Keys");
    CLASS_ATTR_BASIC(c, "nullmode", 0);
    // @description Handles when <b>null</b> is output from a given key outlet.
    // 0 = Never; 1 = only for keys without any content (default); 2 = also for unmatched keys (e.g. keys that has no meaning for the specific notation item,
    // such as velocity for markers, etc.).

    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "defaultbreakpoints",		0,	t_playkeys, sett, t_playkeys_settings, n_use_default_breakpoints);
    CLASS_ATTR_LABEL(c, "defaultbreakpoints",		0, "Use Default Breakpoints");
    CLASS_ATTR_STYLE(c, "defaultbreakpoints",		0, "onoff");
    // @description When set to 1, uses default breakpoints for notes without glissandi.

    
    CLASS_ATTR_LONG_SUBSTRUCTURE(c, "breakpointshavevelocity",		0,	t_playkeys, sett, t_playkeys_settings, n_breakpoints_have_velocity);
    CLASS_ATTR_LABEL(c, "breakpointshavevelocity",		0, "Breakpoints Have Velocity");
    CLASS_ATTR_STYLE(c, "breakpointshavevelocity",		0, "onoff");
    // @description Toggles the ability, for pitch breakpoints, to have their own independent velocity.
    
    CLASS_STICKY_ATTR_CLEAR(c, "category");

    
    CLASS_STICKY_ATTR(c,"category",0,"Slots");

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "dynamicsslot",		0,	t_playkeys, sett, t_playkeys_settings, n_dynamicsslot);
    CLASS_ATTR_STYLE_LABEL(c, "dynamicsslot", 0, "text", "Dynamics Slot Number");
    // @description Sets the number of the slot containing dynamics (0 if none).

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "lyricsslot",		0,	t_playkeys, sett, t_playkeys_settings, n_lyricsslot);
    CLASS_ATTR_STYLE_LABEL(c, "lyricsslot", 0, "text", "Lyrics Slot Number");
    // @description Sets the number of the slot containing lyrics (0 if none).

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "articulationsslot",		0,	t_playkeys, sett, t_playkeys_settings, n_articulationsslot);
    CLASS_ATTR_STYLE_LABEL(c, "articulationsslot", 0, "text", "Articulations Slot Number");
    // @description Sets the number of the slot containing articulations (0 if none).

    CLASS_ATTR_ATOM_SUBSTRUCTURE(c, "noteheadslot",		0,	t_playkeys, sett, t_playkeys_settings, n_noteheadslot);
    CLASS_ATTR_STYLE_LABEL(c, "noteheadslot", 0, "text", "Noteheads Slot Number");
    // @description Sets the number of the slot containing noteheads (0 if none).

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
    if (x->sett.n_must_iterate_on_output) {
        // gotta be complicated
        // To be implemented. No iteration for the time being.
    
    } else {
        for (i = x->n_ob.l_numouts - 1; i >= 0; i--) {
            if (x->sett.n_keys[i].property != k_PLAYKEYS_NONE && (x->sett.n_keys[i].exists || x->sett.n_nullmode == 2))
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

t_max_err playkeys_getattr_process(t_playkeys *x, t_object *attr, long *ac, t_atom **av)
{
    return playkeysobj_getattr_process((t_object *)x, &x->sett, attr, ac, av);
}

t_max_err playkeys_setattr_process(t_playkeys *x, t_object *attr, long ac, t_atom *av)
{
    return playkeysobj_setattr_process((t_object *)x, &x->sett, attr, ac, av);
}


void playkeys_anything(t_playkeys *x, t_symbol *msg, long ac, t_atom *av)
{
    t_llll *in_ll, *found;
    
    if (msg != _sym_bang) {
        in_ll = llllobj_parse_retain_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
        if (!in_ll)
            return;
    } else
        in_ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 0);
    
    
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
                        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, outlet);
                    } else {
                        x->sett.n_keys[outlet].exists = 1;
                        llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, found, outlet);
                    }
                } else {
                    llll_retain(x->n_empty);
                    llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_empty, outlet);
                }
            } else {
                if (x->sett.n_nullmode == 2) {
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
        if (a == 0)	sprintf(s, "llll from playout"); // @out 0 @type llll @digest llll from playout
                                                     // @description The llll coming from <o>bach.roll</o>'s or <o>bach.score</o>'s
                                                     // playout, containing note information in playout syntax
    } else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        switch (x->sett.n_keys[a].property) {
            case k_PLAYKEYS_SLOT:
                switch (x->sett.n_keys[a].specification.h_type) {
                    case H_LONG:
                        sprintf(s, "llll (%s): slot " ATOM_LONG_PRINTF_FMT, type, hatom_getlong(&x->sett.n_keys[a].specification));
                        break;
                    case H_SYM:
                        sprintf(s, "llll (%s): slot %s", type, hatom_getsym(&x->sett.n_keys[a].specification)->s_name);
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
                sprintf(s, "bang for key %s", property_to_symbol(x->sett.n_keys[a].property)->s_name);
                break;
            default:
                sprintf(s, "llll (%s): %s", type, property_to_symbol(x->sett.n_keys[a].property)->s_name);
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
    playkeyssettings_free(&x->sett);
    llll_free(x->n_empty);
    llllobj_obj_free((t_llllobj_object *) x);
}

t_playkeys *playkeys_new(t_symbol *s, short ac, t_atom *av)
{
    t_playkeys *x = NULL;
    t_max_err err = 0;
    long true_ac;
    char outlets[LLLL_MAX_OUTLETS];
    t_playkeys_key *this_keys;
    
    true_ac = MIN(attr_args_offset(ac, av), LLLL_MAX_OUTLETS - 1);
    
    if ((x = (t_playkeys *) object_alloc_debug(playkeys_class))) {
        // @arg 0 @name playkeys @type anything @digest parameters
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
        
        if (!args_ll->l_head) {
            object_error((t_object *)x, "No keys defined.");
            llll_free(args_ll);
            return NULL;
        }
        
        if (playkeysobj_parse_keys((t_object *)x, &x->sett, args_ll, outlets)) // llll_free(args_ll) is in here
            return NULL;
        
        llllobj_obj_setup((t_llllobj_object *) x, 1, outlets);
        
        x->n_empty = llll_get();
    } else
        error(BACH_CANT_INSTANTIATE);
    
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
        return x;
    
    object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
    return NULL;
}
