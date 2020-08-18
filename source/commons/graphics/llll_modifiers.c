/*
 *  llll_modifiers.c
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

#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "graphics/llll_modifiers.h"

void llll_format_modifiers(long *modifiers, long *keycode)
{
    
    if (keycode) {
        switch (*keycode) {
            case JKEY_NUMPAD0: *keycode = 0; break;
            case JKEY_NUMPAD1: *keycode = 1; break;
            case JKEY_NUMPAD2: *keycode = 2; break;
            case JKEY_NUMPAD3: *keycode = 3; break;
            case JKEY_NUMPAD4: *keycode = 4; break;
            case JKEY_NUMPAD5: *keycode = 5; break;
            case JKEY_NUMPAD6: *keycode = 6; break;
            case JKEY_NUMPAD7: *keycode = 7; break;
            case JKEY_NUMPAD8: *keycode = 8; break;
            case JKEY_NUMPAD9: *keycode = 9; break;
            default:  break;
        }
    }
    
	if (!modifiers)
		return;

	*modifiers &= 0x0F;	// to remove right and middle clicks, caps-lock etc.
						// because in a future release these might be checked,
						// we still care for the most significant half-bytes in the following sections

#ifdef WIN_VERSION
    
	if (!modifiers) // if no modifiers are pressed, that's it
		return;

	*modifiers &= ~eCommandKey; // if there is cmd, it's removed (Max adds it automatically to ctrl)

	if (keycode) {
		switch (*keycode) {
			case 'a':
				if ((*modifiers & 0x0F) == (eControlKey | eShiftKey)) {			// ctrl+shift+a
					*keycode = 'y';
					*modifiers = (*modifiers & 0xFFF0) | eCommandKey;				// becomes cmd+y
                    return;
                } else if ((*modifiers & 0x0F) == (eControlKey | eShiftKey | eAltKey)) { // ctrl+shift+alt+a
                    *modifiers = (*modifiers & 0xFFF0) | eControlKey;           // becomes ctrl+a
                    return;
                }
				break;
            case 'i':
                if ((*modifiers & 0x0F) == (eControlKey | eAltKey)) {       // ctrl+shift+i
                    *modifiers = (*modifiers & 0xFFF0) | eCommandKey;           // becomes cmd+y
                    return;
                }
                break;
			case 'y':
				if ((*modifiers & 0x0F) == eControlKey) {						// ctrl+y
					*keycode = 'z';
					*modifiers = (*modifiers & 0xFFFF0) | eCommandKey | eShiftKey;	// becomes cmd+shift+z
                    return;
                }
				break;
			case 'v':
				if ((*modifiers & 0x0F) == (eControlKey | eShiftKey)) {			// ctrl+shift+v
					*keycode = 'v';
					*modifiers = (*modifiers & 0xFFF0) | eCommandKey | eShiftKey;	// becomes cmd+shift+v;
                    return;
                }
				break;
		}
	}



	if (((*modifiers & 0x0F) & (eControlKey | eShiftKey)) == (eControlKey | eShiftKey)) {	// are ctrl+shift pressed?
		
//	if (aretheypressed == ctlshift) {
		*modifiers &= ~eShiftKey;														// remove shift, so ctrl+shift becomes ctrl, and ctrl+alt+shift becomes ctrl+alt
		return;
	}
	
	if ((*modifiers & 0x0F) & eControlKey) {					// is ctrl?
		*modifiers = (*modifiers & ~eControlKey) | eCommandKey;	// becomes cmd
		return;
	}
#endif // WIN_VERSION
}
