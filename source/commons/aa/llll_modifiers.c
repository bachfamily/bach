#ifdef BACH_MAX
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#endif

#include "llll_modifiers.h"

#ifdef BACH_JUCE
// key codes
// key/keyup objects fourth outlet and key message to objects uses
// the following values for keycodes
typedef enum _keycode {
    // keycode is ascii value with modifiers stripped
    // a-z keys thus report lowercase keycode regardless of shift key or capslock state
    JKEY_NONE                = -1,
    JKEY_SPACEBAR           = -2,
    JKEY_ESC                = -3,
    JKEY_RETURN             = -4,
    JKEY_ENTER                = -4,  // same as JKEY_RETURN
    JKEY_TAB                = -5,
    JKEY_DELETE             = -6,
    JKEY_BACKSPACE          = -7,
    JKEY_INSERT             = -8,
    JKEY_UPARROW            = -9,
    JKEY_DOWNARROW          = -10,
    JKEY_LEFTARROW          = -11,
    JKEY_RIGHTARROW         = -12,
    JKEY_PAGEUP             = -13,
    JKEY_PAGEDOWN           = -14,
    JKEY_HOME               = -15,
    JKEY_END                = -16,
    JKEY_F1                 = -17,
    JKEY_F2                 = -18,
    JKEY_F3                 = -19,
    JKEY_F4                 = -20,
    JKEY_F5                 = -21,
    JKEY_F6                 = -22,
    JKEY_F7                 = -23,
    JKEY_F8                 = -24,
    JKEY_F9                 = -25,
    JKEY_F10                = -26,
    JKEY_F11                = -27,
    JKEY_F12                = -28,
    JKEY_F13                = -29,
    JKEY_F14                = -30,
    JKEY_F15                = -31,
    JKEY_F16                = -32,
    JKEY_NUMPAD0            = -33,
    JKEY_NUMPAD1            = -34,
    JKEY_NUMPAD2            = -35,
    JKEY_NUMPAD3            = -36,
    JKEY_NUMPAD4            = -37,
    JKEY_NUMPAD5            = -38,
    JKEY_NUMPAD6            = -39,
    JKEY_NUMPAD7            = -40,
    JKEY_NUMPAD8            = -41,
    JKEY_NUMPAD9            = -42,
    JKEY_NUMPADADD          = -43,
    JKEY_NUMPADSUBTRACT     = -44,
    JKEY_NUMPADMULTIPLY     = -45,
    JKEY_NUMPADDIVIDE       = -46,
    JKEY_NUMPADSEPARATOR    = -47,
    JKEY_NUMPADDECIMALPOINT = -48,
    JKEY_NUMPADEQUALS       = -49,
    JKEY_NUMPADDELETE       = -50,
    JKEY_PLAYPAUSE            = -51,
    JKEY_STOP                = -52,
    JKEY_NEXTTRACK            = -53,
    JKEY_PREVTRACK            = -54,
    JKEY_HELP                = -55
} t_keycode;
#endif

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
