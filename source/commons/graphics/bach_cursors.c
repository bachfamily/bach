/*
 *  bach_cursors.c
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

/**
	@file
	bach_cursors.c
	Cursor utilities for bach library
*/

#include "graphics/bach_cursors.h"


void load_cursors(t_bach_resources *resources, void *moduleRef)
{
	resources->s_cursor_note = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_note");
    resources->s_cursor_note_sharp = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_note_sharp");
    resources->s_cursor_note_flat = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_note_flat");
	resources->s_cursor_note_updown = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_note_updown");
	resources->s_cursor_note_leftright = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_note_leftright");
	resources->s_cursor_note_fourway = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_note_fourway");
	resources->s_cursor_curve = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_curve");
	resources->s_cursor_rotate = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_rotate");
	resources->s_cursor_changecolor = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_changecolor");
	resources->s_cursor_changevelocity = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_changevelocity");
    resources->s_cursor_changedynamics = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_changedynamics");
	resources->s_cursor_delete = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_delete");
	resources->s_cursor_addpoint = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_addpoint");
	resources->s_cursor_deletepoint = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_deletepoint");
	resources->s_cursor_duplicatepoint = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_duplicatepoint");
	resources->s_cursor_eraser = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_eraser");
	resources->s_cursor_glue = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_glue");
	resources->s_cursor_pencil = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_pencil");
	resources->s_cursor_rotate = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_rotate");
	resources->s_cursor_scale = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_scale");
	resources->s_cursor_marker_add = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_marker_add");
	resources->s_cursor_marker_delete = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_marker_delete");
	resources->s_cursor_revert = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_revert");
	resources->s_cursor_switch = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_switch");
    resources->s_cursor_trim_end = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_trim_end");
    resources->s_cursor_trim_start = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_trim_start");
    resources->s_cursor_cut = jgraphics_image_surface_create_from_resource(moduleRef, "cursor_cut");

	resources->s_icon_chord = jgraphics_image_surface_create_from_resource(moduleRef, "icon_chord");
	resources->s_icon_note = jgraphics_image_surface_create_from_resource(moduleRef, "icon_note");
	resources->s_icon_marker = jgraphics_image_surface_create_from_resource(moduleRef, "icon_marker");
	resources->s_icon_measure = jgraphics_image_surface_create_from_resource(moduleRef, "icon_measure");
	resources->s_icon_voice = jgraphics_image_surface_create_from_resource(moduleRef, "icon_voice");
	resources->s_icon_slotinfo = jgraphics_image_surface_create_from_resource(moduleRef, "icon_slotinfo");
	resources->s_icon_mixedselection = jgraphics_image_surface_create_from_resource(moduleRef, "icon_mixedselection");
	resources->s_icon_pitchbreakpoint = jgraphics_image_surface_create_from_resource(moduleRef, "icon_pitchbreakpoint");
	resources->s_icon_tempo = jgraphics_image_surface_create_from_resource(moduleRef, "icon_tempo");
}


void free_cursors(t_bach_resources *resources)
{
	if (resources->s_cursor_note)
		jgraphics_surface_destroy(resources->s_cursor_note);
    if (resources->s_cursor_note_flat)
        jgraphics_surface_destroy(resources->s_cursor_note_flat);
    if (resources->s_cursor_note_sharp)
        jgraphics_surface_destroy(resources->s_cursor_note_sharp);
	if (resources->s_cursor_note_updown)
		jgraphics_surface_destroy(resources->s_cursor_note_updown);
	if (resources->s_cursor_note_leftright)
		jgraphics_surface_destroy(resources->s_cursor_note_leftright);
	if (resources->s_cursor_note_fourway)
		jgraphics_surface_destroy(resources->s_cursor_note_fourway);
	if (resources->s_cursor_curve)
		jgraphics_surface_destroy(resources->s_cursor_curve);
	if (resources->s_cursor_rotate)
		jgraphics_surface_destroy(resources->s_cursor_rotate);
	if (resources->s_cursor_changecolor)
		jgraphics_surface_destroy(resources->s_cursor_changecolor);
	if (resources->s_cursor_scale)
		jgraphics_surface_destroy(resources->s_cursor_scale);
	if (resources->s_cursor_delete) 
		jgraphics_surface_destroy(resources->s_cursor_delete);
	if (resources->s_cursor_addpoint)
		jgraphics_surface_destroy(resources->s_cursor_addpoint);
	if (resources->s_cursor_deletepoint)
		jgraphics_surface_destroy(resources->s_cursor_deletepoint);
	if (resources->s_cursor_duplicatepoint)
		jgraphics_surface_destroy(resources->s_cursor_duplicatepoint);
	if (resources->s_cursor_changevelocity)
		jgraphics_surface_destroy(resources->s_cursor_changevelocity);
    if (resources->s_cursor_changedynamics)
        jgraphics_surface_destroy(resources->s_cursor_changedynamics);
	if (resources->s_cursor_eraser)
		jgraphics_surface_destroy(resources->s_cursor_eraser);
	if (resources->s_cursor_pencil)
		jgraphics_surface_destroy(resources->s_cursor_pencil);
	if (resources->s_cursor_glue)
		jgraphics_surface_destroy(resources->s_cursor_glue);
	if (resources->s_cursor_marker_add)
		jgraphics_surface_destroy(resources->s_cursor_marker_add);
	if (resources->s_cursor_marker_delete)
		jgraphics_surface_destroy(resources->s_cursor_marker_delete);
	if (resources->s_cursor_revert)
		jgraphics_surface_destroy(resources->s_cursor_revert);
	if (resources->s_cursor_switch)
		jgraphics_surface_destroy(resources->s_cursor_switch);
    if (resources->s_cursor_trim_end)
        jgraphics_surface_destroy(resources->s_cursor_trim_end);
    if (resources->s_cursor_trim_start)
        jgraphics_surface_destroy(resources->s_cursor_trim_start);
    if (resources->s_cursor_cut)
        jgraphics_surface_destroy(resources->s_cursor_cut);
}

void bach_set_cursor(t_object *x, int *cursor, t_object *patcherview, e_bach_mouse_cursors new_cursor)
{
	t_bach_resources *resources = (t_bach_resources *)_llllobj_sym_bachcursors->s_thing;
	if (*cursor != new_cursor) {
		*cursor = new_cursor;
		switch (new_cursor) {
			case BACH_CURSOR_SCALE:
				if (resources && resources->s_cursor_scale)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_scale, 10, 10);
				break;
				
			case BACH_CURSOR_CHANGE_COLOR:
				if (resources && resources->s_cursor_changecolor)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_changecolor, 3, 3); 
				break;
				
			case BACH_CURSOR_CHANGE_VELOCITY:
				if (resources && resources->s_cursor_changevelocity)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_changevelocity, 11, 17); 
				break;
				
            case BACH_CURSOR_CHANGE_DYNAMICS:
                if (resources && resources->s_cursor_changedynamics)
                    jmouse_setcursor_surface(patcherview, x, resources->s_cursor_changedynamics, 11, 11);
                break;
                
			case BACH_CURSOR_ROTATION:
				if (resources && resources->s_cursor_rotate)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_rotate, 8, 8); 
				break;

			case BACH_CURSOR_CURVE:
				if (resources && resources->s_cursor_curve)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_curve, 11, 11); 
				break;

			case BACH_CURSOR_NOTE:
				if (resources && resources->s_cursor_note)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_note, 10, 10);
				break;

            case BACH_CURSOR_NOTE_SHARP:
                if (resources && resources->s_cursor_note_sharp)
                    jmouse_setcursor_surface(patcherview, x, resources->s_cursor_note_sharp, 14, 10);
                break;

            case BACH_CURSOR_NOTE_FLAT:
                if (resources && resources->s_cursor_note_flat)
                    jmouse_setcursor_surface(patcherview, x, resources->s_cursor_note_flat, 14, 10);
                break;

			case BACH_CURSOR_NOTE_UPDOWN:
				if (resources && resources->s_cursor_note_updown)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_note_updown, 11, 11); 
				break;
				
			case BACH_CURSOR_NOTE_LEFTRIGHT:
				if (resources && resources->s_cursor_note_leftright)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_note_leftright, 11, 11); 
				break;
				
			case BACH_CURSOR_NOTE_FOURWAY:
				if (resources && resources->s_cursor_note_fourway)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_note_fourway, 11, 11); 
				break;
				
			case BACH_CURSOR_MARKER_ADD:
				if (resources && resources->s_cursor_marker_add)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_marker_add, 5, 11);
				break;
				
			case BACH_CURSOR_MARKER_DELETE:
				if (resources && resources->s_cursor_marker_delete)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_marker_delete, 11, 11); 
				break;
				
			case BACH_CURSOR_DELETE:
				if (resources && resources->s_cursor_delete)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_delete, 11, 11); 
				break;

			case BACH_CURSOR_ADD_POINT:
				if (resources && resources->s_cursor_addpoint)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_addpoint, 3, 3); 
				break;
				
			case BACH_CURSOR_DELETE_POINT:
				if (resources && resources->s_cursor_deletepoint)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_deletepoint, 3, 3); 
				break;

			case BACH_CURSOR_DUPLICATE_POINT:
				if (resources && resources->s_cursor_duplicatepoint)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_duplicatepoint, 3, 3); 
				break;

			case BACH_CURSOR_PENCIL:
				if (resources && resources->s_cursor_pencil)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_pencil, 3, 3); 
				break;
			
			case BACH_CURSOR_ERASER:
				if (resources && resources->s_cursor_eraser)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_eraser, 3, 3); 
				break;

			case BACH_CURSOR_GLUE:
				if (resources && resources->s_cursor_glue)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_glue, 3, 3); 
				break;
				
			case BACH_CURSOR_REVERT:
				if (resources && resources->s_cursor_revert)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_revert, 3, 11); 
				break;
				
			case BACH_CURSOR_SWITCH:
				if (resources && resources->s_cursor_switch)
					jmouse_setcursor_surface(patcherview, x, resources->s_cursor_switch, 11, 11); 
				break;

            case BACH_CURSOR_TRIM_END:
                if (resources && resources->s_cursor_trim_end)
                    jmouse_setcursor_surface(patcherview, x, resources->s_cursor_trim_end, 13, 8);
                break;

            case BACH_CURSOR_TRIM_START:
                if (resources && resources->s_cursor_trim_start)
                    jmouse_setcursor_surface(patcherview, x, resources->s_cursor_trim_start, 7, 8);
                break;

            case BACH_CURSOR_CUT:
                if (resources && resources->s_cursor_cut)
                    jmouse_setcursor_surface(patcherview, x, resources->s_cursor_cut, 10, 10);
                break;

			case BACH_CURSOR_COPY:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_COPYING);
				break;

			case BACH_CURSOR_CROSSHAIR:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_CROSSHAIR);
				break;

			case BACH_CURSOR_POINTINGHAND:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_POINTINGHAND);
				break;
				
			case BACH_CURSOR_RESIZE_BOTTOMRIGHTCORNER:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_BOTTOMRIGHTCORNER);
				break;
				
			case BACH_CURSOR_RESIZE_BOTTOMLEFTCORNER:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_BOTTOMLEFTCORNER);
				break;

			case BACH_CURSOR_RESIZE_FOURWAY:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_FOURWAY);
				break;

			case BACH_CURSOR_RESIZE_LEFTRIGHT:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_LEFTRIGHT);
				break;

			case BACH_CURSOR_RESIZE_UPDOWN:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_UPDOWN);
				break;
				
			case BACH_CURSOR_RESIZE_TOPLEFTCORNER:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_TOPLEFTCORNER);
				break;

			case BACH_CURSOR_RESIZE_TOPRIGHTCORNER:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_TOPRIGHTCORNER);
				break;

			case BACH_CURSOR_MOVE:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_RESIZE_FOURWAY);
				break;

			case BACH_CURSOR_DUPLICATE:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_COPYING);
				break;

			case BACH_CURSOR_DRAGGINGHAND:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_DRAGGINGHAND);
				break;
				
			case BACH_CURSOR_NONE:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_NONE);
				break;
				
			default:
				jmouse_setcursor(patcherview, x, JMOUSE_CURSOR_ARROW);
				break;
		}
	}
}

