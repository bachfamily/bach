/**
	@file	playekeys_commons.h
	@brief	Common function for playkeys and playkeys~
	
	by Daniele Ghisi
*/

#ifndef _LLLL_PLAYKEYS_COMMONS_H_
#define _LLLL_PLAYKEYS_COMMONS_H_

// higher level llll functions

#include "bach.h"
#include "notation.h"


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif



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


typedef struct _playkeys_properties
{
    t_playkeys_key          *n_keys;
    
    long                    n_flattenfornotes;
    long                    n_nullmode;
    long                    n_use_default_breakpoints;
    long                    n_breakpoints_have_velocity;
    
    t_llll                  *n_process;
    long                    n_notationitems_to_process;
    t_bach_atomic_lock      n_process_lock;
    
    t_llll                  *n_note_commands;
    t_llll                  *n_chord_commands;
    t_llll                  *n_rest_commands;
    
    t_atom                  n_dynamicsslot;
    t_atom                  n_articulationsslot;
    t_atom                  n_lyricsslot;
    t_atom                  n_noteheadslot;
    
    char                    n_must_iterate_on_output;
} t_playkeys_settings;

long symbol_to_incoming(t_symbol *s);
long get_default_allowed_notationitems_for_property(long property);
long symbol_to_property(t_symbol *s);
t_symbol *property_to_symbol(long property);
t_llllelem *getindex_2levels(t_llll *ll, long pos1, long pos2);
t_bool can_llll_be_a_note(t_llll *ll);
t_llllelem *root_find_el_with_sym_router(t_llll *ll, t_symbol *router);
t_llllelem *root_find_el_with_long_router(t_llll *ll, long router);
long llll_count_elems(t_llll *ll);
double get_onset_from_llllelem(t_llllelem *el);
char incoming_is_from_roll(long incoming);


t_max_err playkeysobj_setattr_process(t_object *x, t_playkeys_settings *sett, t_object *attr, long ac, t_atom *av, char msp_obj);
t_max_err playkeysobj_getattr_process(t_object *x, t_playkeys_settings *sett, t_object *attr, long *ac, t_atom **av);

void playkeyssettings_init(t_playkeys_settings *sett, t_llll *args_ll);
void playkeyssettings_free(t_playkeys_settings *sett);
long playkeysobj_parse_keys(t_object *x, t_playkeys_settings *sett, t_llll *args_ll, char *outlets, char msp_outlets); // returns 1 if error, 0 otherwise

char playkeysobj_handle_incoming(t_object *x, t_playkeys_settings *sett, t_llll *in_ll, long *incoming_el, t_symbol **router_el);
t_llll *playkeysobj_get_values(t_object *x, t_playkeys_settings *sett, t_playkeys_key *this_key, long incoming, t_symbol *router, t_llll *in_ll);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _LLLL_PLAYKEYS_COMMONS_H_
