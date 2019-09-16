/*
 *  bach_cursors.h
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
	@file
	bach_cursors.h
	Cursor utilities header for bach library
 */

#ifndef _BACH_CURSORS_H_
#define _BACH_CURSORS_H_

#include "foundation/llllobj.h"
#include "jgraphics.h"

/** Mouse cursor types.
 @ingroup	interface
 */
typedef enum _bach_mouse_cursors {
	BACH_CURSOR_DEFAULT = 0,					///< Default
	BACH_CURSOR_COPY,							///< Copy cursor (arrow and plus)
	BACH_CURSOR_CROSSHAIR,						///< Selection "+" (crosshair)
	BACH_CURSOR_POINTINGHAND,					///< Pointing hand
	BACH_CURSOR_DRAGGINGHAND,					///< Open hand (for dragging)
	BACH_CURSOR_ROTATION,						///< Rotation cursor
	BACH_CURSOR_RESIZE_UPDOWN,					///< Up-down arrows
	BACH_CURSOR_RESIZE_LEFTRIGHT,				///< Left-right arrows
	BACH_CURSOR_RESIZE_FOURWAY,					///< Up-down-left-right arrows
	BACH_CURSOR_RESIZE_TOPLEFTCORNER,			///< Top-left corner arrows
	BACH_CURSOR_RESIZE_TOPRIGHTCORNER,			///< Top-right corner arrows
	BACH_CURSOR_RESIZE_BOTTOMLEFTCORNER,		///< Bottom-left corner arrows
	BACH_CURSOR_RESIZE_BOTTOMRIGHTCORNER,		///< Bottom-right corner arrows
	BACH_CURSOR_CHANGE_COLOR,					///< Color changer cursor
	BACH_CURSOR_CHANGE_VELOCITY,				///< Velocity changer cursor
    BACH_CURSOR_CHANGE_DYNAMICS,                ///< Dynamics changer cursor
	BACH_CURSOR_MOVE,							///< Move element cursor
	BACH_CURSOR_SCALE,							///< Scale element cursor
	BACH_CURSOR_DELETE,							///< Delete element cursor
	BACH_CURSOR_DUPLICATE,						///< Duplicate element cursor
	BACH_CURSOR_DELETE_POINT,					///< Delete point cursor
	BACH_CURSOR_ADD_POINT,						///< Add point cursor
	BACH_CURSOR_DUPLICATE_POINT,				///< Duplicate point cursor
	BACH_CURSOR_PENCIL,							///< Pencil cursor
	BACH_CURSOR_ERASER,							///< Eraser cursor
	BACH_CURSOR_GLUE,							///< Glue cursor
	BACH_CURSOR_CURVE,							///< Curve cursor
	BACH_CURSOR_NOTE,							///< Note cursor
    BACH_CURSOR_NOTE_SHARP,						///< Sharp note cursor
    BACH_CURSOR_NOTE_FLAT,						///< Flat note cursor
	BACH_CURSOR_NOTE_UPDOWN,					///< Pitch note changer cursor
	BACH_CURSOR_NOTE_LEFTRIGHT,					///< Onset note changer cursor
	BACH_CURSOR_NOTE_FOURWAY,					///< Onset and pitch note changer cursor
	BACH_CURSOR_MARKER_ADD,						///< Add marker
	BACH_CURSOR_MARKER_DELETE,					///< Delete marker
	BACH_CURSOR_REVERT,							///< Revert to default
	BACH_CURSOR_SWITCH,							///< Switch, change or swap something
    BACH_CURSOR_TRIM_END,						///< Trim end
    BACH_CURSOR_TRIM_START,						///< Trim start
    BACH_CURSOR_CUT,							///< Cut
	BACH_CURSOR_NONE,							///< No cursor
} e_bach_mouse_cursors;

typedef struct _bach_cursor_resources
{
	t_jsurface *s_cursor_changecolor;
	t_jsurface *s_cursor_rotate;
	t_jsurface *s_cursor_scale;
	t_jsurface *s_cursor_delete;
	t_jsurface *s_cursor_addpoint;
	t_jsurface *s_cursor_deletepoint;
	t_jsurface *s_cursor_duplicatepoint;
	t_jsurface *s_cursor_changevelocity;
    t_jsurface *s_cursor_changedynamics;
	t_jsurface *s_cursor_pencil;
	t_jsurface *s_cursor_eraser;
	t_jsurface *s_cursor_glue;
	t_jsurface *s_cursor_curve;
	t_jsurface *s_cursor_note;
    t_jsurface *s_cursor_note_sharp;
    t_jsurface *s_cursor_note_flat;
	t_jsurface *s_cursor_note_updown;
	t_jsurface *s_cursor_note_leftright;
	t_jsurface *s_cursor_note_fourway;
	t_jsurface *s_cursor_marker_add;
	t_jsurface *s_cursor_marker_delete;
	t_jsurface *s_cursor_revert;
	t_jsurface *s_cursor_switch;
    t_jsurface *s_cursor_trim_end;
    t_jsurface *s_cursor_trim_start;
    t_jsurface *s_cursor_cut;
	
	// additional icons
	t_jsurface *s_icon_marker;
	t_jsurface *s_icon_note;
	t_jsurface *s_icon_chord;
	t_jsurface *s_icon_measure;
	t_jsurface *s_icon_voice;
	t_jsurface *s_icon_slotinfo;
	t_jsurface *s_icon_mixedselection;
	t_jsurface *s_icon_pitchbreakpoint;
	t_jsurface *s_icon_tempo;
} t_bach_resources;



void load_cursors(t_bach_resources *manager, void *moduleRef);
void free_cursors(t_bach_resources *manager);
void bach_set_cursor(t_object *x, int *cursor, t_object *patcherview, e_bach_mouse_cursors new_cursor);

#endif // _BACH_CURSORS_H_

