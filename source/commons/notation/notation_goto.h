/*
 *  notation_goto.h
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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
	@file	notation_goto.h
*/

#ifndef _NOTATION_GOTO_H_
#define _NOTATION_GOTO_H_

#include "notation/notation.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif

typedef enum _goto_error
{
    k_GOTO_ERROR_NONE = 0,
    k_GOTO_ERROR_NOTFOUND = 1,
    k_GOTO_ERROR_WRONGCOMMAND = 2,
    k_GOTO_ERROR_WRONGARGUMENTS = 3,
    k_GOTO_ERROR_WRONGPARAMS = 4,
} e_goto_error;

typedef enum _goto_voicemode
{
    k_GOTO_VOICEMODE_LASTACTIVE = 0,
    k_GOTO_VOICEMODE_ANY = 1,
    k_GOTO_VOICEMODE_ALL = 2,
    k_GOTO_VOICEMODE_EACH = 3,
    k_GOTO_VOICEMODE_ANYACTIVE = 4,
    k_GOTO_VOICEMODE_ALLACTIVE = 5,
} e_goto_voicemode;

typedef enum _goto_tiemode
{
    k_GOTO_TIEMODE_EACH = 0,
    k_GOTO_TIEMODE_TO = 1,
    k_GOTO_TIEMODE_FROM = 2,
    k_GOTO_TIEMODE_ALL = 3,
} e_goto_tiemode;


typedef enum _goto_onsetpoints
{
    k_GOTO_ONSETPOINT_AUTO = 0,
    k_GOTO_ONSETPOINT_HEAD = 1,
    k_GOTO_ONSETPOINT_TAIL = 2,
} e_goto_onsetpoints;


typedef enum _goto_polymode
{
    k_GOTO_POLYMODE_NONE = 0,
    k_GOTO_POLYMODE_OVERLAP = 1,
    k_GOTO_POLYMODE_OVERHANG = 2,
} e_goto_polymode;

typedef enum _goto_untilmode
{
    k_GOTO_UNTILMODE_ALL = 0,
    k_GOTO_UNTILMODE_ANY = 1,
} e_goto_untilmode;




typedef struct _goto_params
{
    t_symbol    *command;                           ///< Symbolic command

// With any command:
    long        repeat;                             ///< Repeat command N times
    
    char        allowed_types[k_NUM_ELEMENT_TYPES]; ///< For each of the e_element_types we say if we consider it or not; All 0's means "the same"
    long        num_allowed_types;                  ///< Number of allowed types
    t_llll      *voicenumbers;                      ///< Voice numbers to be accounted for (0-based) (NULL means ALL, default)
    t_llll      *arguments;     ///< NULL means: "any" or "the same"
    
    t_lexpr     *where;         ///< Subselecting according to this condition
    t_lexpr     *until;         ///< Repeating the same command until this condition is met
    long        untilmode;      ///< Is 'until' clause applied to all new selection or at least one element? One of the e_goto_untilmode
    
    long        nullmode;       ///< If non-zero, notifies the null
    long        polymode;      ///< one of the e_goto_polymode, handling the keeping of selection across polyphony (doesn't work with up/down/left/right)
    long        force_inscreen;      ///< Also force new selected items to be in screen
    long        tiemode;        ///< one of the e_goto_tiemode handling tie sequences
    long        skiprests;      ///< Skip or ignore rests (don't select them)
    long        graces_have_duration;      ///< Grace notes have durations
    long        markershavevoices;      ///< Measure-attached markers undergo the same voice sieving behaviors as chords depending on voicemodes, etc.
    
// With the "next/prev" commands
    long        voicemode;      ///< Mode of operation, one of the e_goto_voicemode
    long        strictcmp;      ///< If nonzero, comparisons for next and prev are < and >, instead of <= and >=
    long        from;           ///< one of the e_goto_onsetpoints handling onset points: start searching "next/prev" element from the last head/tail
    long        to;             ///< one of the e_goto_onsetpoints handling onset points: stop searching "next/prev" element once you reach a head/tail

// With the "time" command:
    long        matchinclude;       ///< Used with the "time" command:
                                    ///< A combination of the e_goto_onsetpoints, determining whether head/tails should be included in the time matching search

    
/// INTERNAL STUFF
    char        activevoices[CONST_MAX_VOICES];
    t_notation_obj  *notation_obj;          ///< Useful to havefor a couple of hacks
} t_goto_params;




t_goto_params notationobj_goto_get_default_params(t_notation_obj *r_ob);

void notationobj_goto_parseargs(t_notation_obj *r_ob, t_llll *args);
e_goto_error notationobj_goto(t_notation_obj *r_ob, t_goto_params *par);
t_llll *notationobj_goto_do(t_notation_obj *r_ob, t_goto_params *par, long *error);





#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _NOTATION_GOTO_H_
