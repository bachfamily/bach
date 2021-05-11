/*
 *  bach.h
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

#ifndef _BACH_H_
	#define _BACH_H_

	#define BACH_MAGIC_GOOD	3282844379u
	#define BACH_MAGIC_BAD	666 // hahaha!!!

    #ifdef __cplusplus_WEDONTNEEDTHIS
        #define BEGIN_CHECK_LINKAGE \
            extern "C" {
    #else
        #define BEGIN_CHECK_LINKAGE
    #endif // __cplusplus

    #ifdef __cplusplus_WEDONTNEEDTHIS
        #define END_CHECK_LINKAGE \
            }
    #else
        #define END_CHECK_LINKAGE
    #endif // __cplusplus
    #define C74_NO_CONST 0
#ifndef NO_TRANSLATION_SUPPORT
    #define NO_TRANSLATION_SUPPORT
#endif

	#define WHITENULL					((void *) -1)
	#define WHITENULL_llll				((t_llll *) WHITENULL)
	#define WHITENULL_llllelem			((t_llllelem *) WHITENULL)
	#define LLLL_IDX_BASE				1 // can be 0 or 1, also affects the behaviour of append @triggers, collector's collections and msort's base

	//#define BACH_SAFE_LLLLS

//#ifndef __clang__
    #define	BACH_PRELOAD_CURSORS
//#endif

#ifdef __clang__
	#define BACH_USE_NATIVE_128BIT_INTEGER
#endif

#define ___destructive

	#define dev_post(...) ((void) 0)
    #define dev_cpost(...) ((void) 0)
	#define dev_object_post(...) ((void) 0)
	#define dev_object_warn(...) ((void) 0)
	#define dev_llll_print(ll, cl, e, md, fn) ((void) 0)
	#define pedantic_llll_check(ll) ((void) 0)
    #define dev_llll_post(ll, mindepth, maxdepth, max_decimals, client, fn) ((void) 0)


	#define dev_cprintf(...) ((void) 0)

		#ifdef WIN_VERSION
			#ifdef _DEBUG
				#define CONFIGURATION_Development
			#else
				#define CONFIGURATION_Deployment
			#endif
			#define BACH_LLLL_VERSION "0.8.0.0"
			#define BACH_VERSION "0.8.1.4"

			#define MAXAPI_USE_MSCRT
		#endif
		
		#ifdef CONFIGURATION_Development
			//#define BACH_SHOW_POOL_USAGE
			//#define BACH_CHECK_LLLLS
			//#define BACH_PEDANTICALLY_CHECK_LLLLS
			//#define BACH_CHECK_PHONENUMBERS
			//#define BACH_USE_MAGIC_NUMBER

			//#define BACH_TRACK_MEMORY_ALLOCATION
            //#define BACH_SAVE_STACK_WITH_MEMORY_LOGS // useless if BACH_TRACK_MEMORY_ALLOCATION is undefined, and anyway only works on a Mac
			//#define BACH_BLOAT_FREED_MEMORY // useless if BACH_TRACK_MEMORY_ALLOCATION is undefined
			//#define BACH_SAVE_STACK_IN_LLLLS // useless if BACH_TRACK_MEMORY_ALLOCATION and BACH_SAVE_STACK_WITH_MEMORY_LOGS are undefined
			//#define BACH_ENABLE_BREAKPOINTS
			//#define BACH_POST_STUFF_TO_CONSOLE

			#undef dev_post
			#define dev_post(...) post(__VA_ARGS__)
            #undef dev_cpost
            #define dev_cpost(...) post(__VA_ARGS__)
            #undef dev_object_post
			#define dev_object_post(...) object_post(__VA_ARGS__)
			#undef dev_object_warn
			#define dev_object_warn(...) object_warn(__VA_ARGS__)
			#undef dev_llll_print
			#define dev_llll_print(...) llll_print(__VA_ARGS__)
            #undef dev_llll_post
            #define dev_llll_post(ll, mindepth, maxdepth, max_decimals, client, fn) llll_post(ll, mindepth, maxdepth, max_decimals, (t_object *) client, fn)



#ifdef BACH_PEDANTICALLY_CHECK_LLLLS
			#undef pedantic_llll_check
			#define pedantic_llll_check(ll) llll_check(llll_root(ll))
#endif
#ifdef BACH_POST_STUFF_TO_CONSOLE
			#undef dev_cprintf
			#define dev_cprintf(...) cpost(__VA_ARGS__)
#endif

		#endif // CONFIGURATION_Development

		#ifdef CONFIGURATION_Deployment
		#define C74_NO_DEPRECATION
		#endif


#ifndef BACH_SAVE_STACK_IN_LLLLS
		#define BACH_LLLL_PAGE_SIZE_EXPONENT 20 // I have pages of 10^6 lllls
#else
		#define BACH_LLLL_PAGE_SIZE_EXPONENT 8
#endif
		#define BACH_LLLL_MAX_NUMBER_EXPONENT 32 // and up to 10^9 lllls
		#define BACH_LLLL_PAGE_SIZE (2 << (BACH_LLLL_PAGE_SIZE_EXPONENT - 1)) // 4
		#define BACH_LLLL_BOOK_SIZE (2 << (BACH_LLLL_MAX_NUMBER_EXPONENT - BACH_LLLL_PAGE_SIZE_EXPONENT - 1))



#ifndef BACH_SAVE_STACK_IN_LLLLS
		#define BACH_LLLLELEM_PAGE_SIZE_EXPONENT 20 // I have pages of 10^6 llllelems
#else
		#define BACH_LLLLELEM_PAGE_SIZE_EXPONENT 8
#endif
		#define BACH_LLLLELEM_MAX_NUMBER_EXPONENT 32 // and up to 10^9 llllelems
		#define BACH_LLLLELEM_PAGE_SIZE (2 << (BACH_LLLLELEM_PAGE_SIZE_EXPONENT - 1)) // 4
		#define BACH_LLLLELEM_BOOK_SIZE (2 << (BACH_LLLLELEM_MAX_NUMBER_EXPONENT - BACH_LLLLELEM_PAGE_SIZE_EXPONENT - 1))


#define BACH_STATIC_ASSERT(e, m) typedef char __BACH_STATIC_ASSERT__[(e)?1:-1]

// A wrapper for class_new() also checking that the class size is acceptable
// Useful for debugging huge objects such as bach.score

#define CLASS_NEW_CHECK_SIZE(CLASS, name, mnew, mfree, size, mmenu, type, ...) \
{ \
    BACH_STATIC_ASSERT(size < 16384 - 16, "Class too large"); \
    { __BACH_STATIC_ASSERT__ dummy; dummy[0] = 0; }\
    if (size < 16384 - 16) \
        CLASS = class_new(name, mnew, mfree, size, mmenu, type, __VA_ARGS__); \
    else { \
        post("Class %s too large, size = %d", name, (int) size); \
        return 0; \
    } \
}

#define CLASS_NEW_DONT_CHECK_SIZE(CLASS, name, mnew, mfree, size, mmenu, type, ...) \
{ CLASS = class_new(name, mnew, mfree, size, mmenu, type, __VA_ARGS__); }


#include <assert.h>

// a macro to mark exported symbols in the code without requiring an external file to define them
#ifdef WIN_VERSION
// note that this is the required syntax on windows regardless of whether the compiler is msvc or gcc
#define T_EXPORT __declspec(dllexport)
//#define snprintf sprintf_s
#define strncasecmp _strnicmp
#else // MAC_VERSION
// the mac uses the standard gcc syntax, you should also set the -fvisibility=hidden flag to hide the non-marked symbols
#define T_EXPORT __attribute__((visibility("default")))
#endif

#define MAX_SYM_LENGTH 32768	// the supposed maximum length for a symbol name

extern struct _bach *bach;


#endif // _BACH_H_
