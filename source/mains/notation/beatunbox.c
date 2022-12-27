/*
 *  beatunbox.c
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
	beatunbox.c
	
	@name 
	bach.beatunbox
	
	@realname 
	bach.beatunbox

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Flatten measure-wise parameters into plain voice-wise information
	
	@description
	Removes the measure parenthesis levels in the <o>bach.score</o> parameters syntax. 
	More specifically, it converts the measure-wise score syntax into a plain sequence of separate parameters 
	(boxed only voice-wise, and no longer measure-wise).
	
	@discussion
	bach.beatunbox is the complementary object with respect to bach.beatbox. It converts a measure-wise packets of 
	data into a continuous flow, gathering (where possible) the tied elements, and merging sequences of rests.
	The basic usage is by connecting its inlet with score's gathered syntax dump. 
	If you use the "separate" mode (by putting the "separate" argument), be sure that the score output of the 
	separate parameters be not in rhythmic-tree 
	form, by checking the @outputtrees bach.score attribute (by default it is not).
	
	@category
	bach, bach objects, bach notation

	@keywords
	unbox, measure, parenthesis, unwrap, flat, measurewise, voicewise, format, flow, plain, measureinfo

	@seealso
	bach.beatbox, bach.score, bach.quantize, bach.score2roll, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/


#include "notation/notation.h" // header with all the structures for the notation objects
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 

typedef struct _beatunbox
{
	struct llllobj_object 	n_ob;
	
	char				n_merge;
	long				n_proxies;
	
	char				measurewise; // UNUSED unbox measurewise?
	char				input_separate; // input separate parameters?

	void				*n_proxy[5];
	long				n_in;
	
	t_systhread_mutex	n_mutex;
	
} t_beatunbox;


void beatunbox_assist(t_beatunbox *x, void *b, long m, long a, char *s);
void beatunbox_inletinfo(t_beatunbox *x, void *b, long a, char *t);

t_beatunbox *beatunbox_new(t_symbol *s, short ac, t_atom *av);
void beatunbox_free(t_beatunbox *x);

void beatunbox_bang(t_beatunbox *x);
void beatunbox_anything(t_beatunbox *x, t_symbol *msg, long ac, t_atom *av);

t_class *beatunbox_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.beatunbox", (method)beatunbox_new, (method)beatunbox_free, (long) sizeof(t_beatunbox), 0L, A_GIMME, 0);
	
	// @method llll @digest Receive score syntax and remove the measure parenthesis level. 
	// @description 
	// The function by default receives the score gathered syntax (obtained via a "dump" message). In most cases this suffice. <br /> <br />
	// On the other hand, if the <m>separate</m> argument is needed, the function receives:
	// In first inlet: Pitches or cents. <br />
	// In second inlet: Durations, as output by bach.score' dump (measure-wise). <br />
	// In third inlet: Velocities. <br />
	// In fourth inlet: Ties. <br />
	// In fifth inlet: Extras. <br />
	// All parameters are expected as output by bach.score' dump (measure-wise), but NOT with rhythmic tree parenthesization (so be sure that
	// the @outputtrees attribute of bach score be set to Never or First Outlet Only.
	class_addmethod(c, (method)beatunbox_anything,		"anything",		A_GIMME,	0);
	class_addmethod(c, (method)beatunbox_anything,		"list",			A_GIMME,	0);

	// @method bang @digest Perform the unboxing
	// @description Perform the unboxing operation on the most recently received input data.
	class_addmethod(c, (method)beatunbox_bang,			"bang",			0);
	
	class_addmethod(c, (method)beatunbox_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)beatunbox_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);


    
    CLASS_ATTR_CHAR(c, "merge", 0, t_beatunbox, n_merge);
    CLASS_ATTR_STYLE_LABEL(c,"merge",0,"enumindex", "Merge Chords");
    CLASS_ATTR_ENUMINDEX(c,"merge", 0, "Never When Drawable Always");
    CLASS_ATTR_BASIC(c, "merge",0);
    // @description Sets the fashion in which chords inside each measure are merged: <br />
    // - Never: never merge chords <br />
    // - When Drawable (default): only always merge sequences of rests or tied chords when the global duration is representable by a single figure. <br />
    // - Always: always merge sequences of rests or tied chords <br />

    
	class_register(CLASS_BOX, c);
	beatunbox_class = c;
	
	dev_post("bach.beatunbox compiled %s %s", __DATE__, __TIME__);
	
	return;
}


void flat_up_to_for_graphic(t_llll *box){
    if (box) {
        t_llllelem *elem = NULL;
        for (elem = box->l_head; elem; elem = elem->l_next) {
            if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
                t_llll *ll = hatom_getllll(&elem->l_hatom);
                if (ll->l_depth >= 4) {
                    flat_up_to_for_graphic(ll);
                    llll_splatter(elem, LLLL_FREETHING_DONT);
                }
            }
        }
    }
}


void flat_up_to_for_breakpoints(t_llll *box){
	if (box) {
		t_llllelem *elem = NULL;
		for (elem = box->l_head; elem; elem = elem->l_next) {
			if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
				t_llll *ll = hatom_getllll(&elem->l_hatom);
				if (ll->l_depth >= 4) {
					flat_up_to_for_breakpoints(ll);
					llll_splatter(elem, LLLL_FREETHING_DONT);
				}
			}
		}
	}
}


void flat_up_to_for_slots(t_llll *box){
	if (box) {
		t_llllelem *elem = NULL;
		for (elem = box->l_head; elem; elem = elem->l_next) {
			if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
				t_llll *ll = hatom_getllll(&elem->l_hatom);
				t_llll *subll = NULL, *subsubll = NULL;
				if (ll->l_depth <= 2) {
					// nothing to do, we are done.
				} else if (hatom_gettype(&ll->l_head->l_hatom) == H_LLLL && (subll = hatom_getllll(&ll->l_head->l_hatom)) &&
						   subll->l_head && hatom_gettype(&subll->l_head->l_hatom) == H_LLLL && (subsubll = hatom_getllll(&subll->l_head->l_hatom)) &&
						   subsubll->l_head && hatom_gettype(&subsubll->l_head->l_hatom) != H_LLLL) {
					// nothing to do, we are done, we've reached a chord llll
				} else {
					flat_up_to_for_slots(ll);
					llll_splatter(elem, LLLL_FREETHING_DONT);
				}
			}
		}
	}
}


void beatunbox_bang(t_beatunbox *x)
{
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		beatunbox_anything(x, _sym_bang, 0, NULL);
	else {
		if (!x->input_separate)
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 5);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 4);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 3);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 2);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
	}
}

void beatunbox_anything(t_beatunbox *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	long i;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), inlet);
		return;
	}
	
	if (msg == _llllobj_sym_clearall) {
		for (i = 0; i < 5; i++)
			llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), i);
		return;
	}

	if (msg != _sym_bang) {
		if (x->input_separate) {
			llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet+1);
		} else {
			t_llll *measureinfo, *cents, *durations, *velocities, *ties, *extras;
			t_llll *gathered = llllobj_parse_llll((t_object *)x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
			score_gathered2separate_syntax(gathered, &measureinfo, &cents, &durations, &velocities, &ties, &extras, false); // ONLY FOR DEBUG
			llllobj_store_llll((t_object *)x, LLLL_OBJ_VANILLA, measureinfo, 0);
			llllobj_store_llll((t_object *)x, LLLL_OBJ_VANILLA, cents, 1);
			llllobj_store_llll((t_object *)x, LLLL_OBJ_VANILLA, durations, 2);
			llllobj_store_llll((t_object *)x, LLLL_OBJ_VANILLA, velocities, 3);
			llllobj_store_llll((t_object *)x, LLLL_OBJ_VANILLA, ties, 4);
			llllobj_store_llll((t_object *)x, LLLL_OBJ_VANILLA, extras, 5);
			llll_free(gathered);
		}
		x->n_ob.l_rebuild = 1;
	}
	
	if (inlet == 0) {
		// do calculations
		t_llll *measureinfo, *cents, *durations, *velocities, *ties, *extras;
		t_llll *graphic = NULL, *breakpoints = NULL, *slots = NULL;
		t_llll *unboxed_cents, *unboxed_durations, *unboxed_velocities, *unboxed_ties, *unboxed_graphic, *unboxed_breakpoints, *unboxed_slots;
		t_llllelem *extraselem;
		t_llllelem *ties_voice_elem, *durations_voice_elem, *cents_voice_elem, *velocities_voice_elem, *graphic_voice_elem, *breakpoints_voice_elem, *slots_voice_elem;
		long i, num_voices;
		t_llll *inlist[6];
		t_llll *unboxed_extras;

		for (i = 0; i < 6; i++) 
			inlist[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 1);
		
		// all incoming data are cloned
		measureinfo = inlist[0];
		cents = inlist[1];
		durations = inlist[2];
		velocities = inlist[3];
		ties = inlist[4];
		extras = inlist[5];
		
		// setting extras properly

		extraselem = extras->l_head;
		if (extraselem && (hatom_gettype(&extraselem->l_hatom) == H_LLLL)
			&& (hatom_getllll(&extraselem->l_hatom)->l_size >= 2)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == H_SYM)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_next->l_hatom) == H_LLLL)
			&& (hatom_getsym(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == _llllobj_sym_graphic)) {
				graphic = hatom_getllll(&extraselem->l_hatom);
				llll_behead(graphic);
				extraselem = extraselem->l_next;
		}
		if (extraselem && (hatom_gettype(&extraselem->l_hatom) == H_LLLL)
			&& (hatom_getllll(&extraselem->l_hatom)->l_size >= 2)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == H_SYM)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_next->l_hatom) == H_LLLL)
			&& (hatom_getsym(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == _llllobj_sym_breakpoints)) {
				breakpoints = hatom_getllll(&extraselem->l_hatom);
				llll_behead(breakpoints);
				extraselem = extraselem->l_next;
		}
		if (extraselem && (hatom_gettype(&extraselem->l_hatom) == H_LLLL)
			&& (hatom_getllll(&extraselem->l_hatom)->l_size >= 2)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == H_SYM)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_next->l_hatom) == H_LLLL)
			&& (hatom_getsym(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == _llllobj_sym_slots)) {
				slots = hatom_getllll(&extraselem->l_hatom);
				llll_behead(slots);
				extraselem = extraselem->l_next;
		}
//		char debug[1000];
//		llll_to_char_array(graphic, debug, 1000);

		num_voices = cents->l_size;
		if (durations && ((long)durations->l_size > num_voices)) num_voices = durations->l_size;
		if (velocities && ((long)velocities->l_size > num_voices)) num_voices = velocities->l_size;
		if (ties && ((long)ties->l_size > num_voices)) num_voices = ties->l_size;
		if (graphic && ((long)graphic->l_size > num_voices)) num_voices = graphic->l_size;
		if (breakpoints && ((long)breakpoints->l_size > num_voices)) num_voices = breakpoints->l_size;
		if (slots && ((long)slots->l_size > num_voices)) num_voices = slots->l_size;

		unboxed_cents = llll_get();
		unboxed_durations = llll_get();
		unboxed_velocities = llll_get();
		unboxed_ties = llll_get();
		unboxed_graphic = llll_get();
		unboxed_breakpoints = llll_get();
		unboxed_slots = llll_get();

		for (cents_voice_elem = (cents) ? cents->l_head : NULL, velocities_voice_elem = (velocities) ? velocities->l_head : NULL,
			 ties_voice_elem = (ties) ? ties->l_head : NULL, graphic_voice_elem = (graphic) ? graphic->l_head : NULL, durations_voice_elem = (durations) ? durations->l_head : NULL,
			 breakpoints_voice_elem = (breakpoints) ? breakpoints->l_head : NULL, slots_voice_elem = (slots) ? slots->l_head : NULL;
			 cents_voice_elem || velocities_voice_elem || durations_voice_elem || ties_voice_elem || graphic_voice_elem || breakpoints_voice_elem || slots_voice_elem ;
			 cents_voice_elem = (cents_voice_elem) ? cents_voice_elem->l_next : NULL, 
			 velocities_voice_elem = (velocities_voice_elem) ? velocities_voice_elem->l_next : NULL, 
			 ties_voice_elem = (ties_voice_elem) ? ties_voice_elem->l_next : NULL, 
			 durations_voice_elem = (durations_voice_elem) ? durations_voice_elem->l_next : NULL, 
			 breakpoints_voice_elem = (breakpoints_voice_elem) ? breakpoints_voice_elem->l_next : NULL, 
			 slots_voice_elem = (slots_voice_elem) ? slots_voice_elem->l_next : NULL, 
			 graphic_voice_elem = (graphic_voice_elem) ? graphic_voice_elem->l_next : NULL) { // cycle on the VOICES
			t_llll *voice_infos;
			t_llllelem *info_elem;
			t_llllelem *cents_elem, *velocities_elem, *graphic_elem, *breakpoints_elem, *slots_elem;
			t_llll *voice_cents = (cents_voice_elem && (hatom_gettype(&cents_voice_elem->l_hatom) == H_LLLL))? hatom_getllll(&cents_voice_elem->l_hatom) : NULL;
			t_llll *voice_durations = (durations_voice_elem && (hatom_gettype(&durations_voice_elem->l_hatom) == H_LLLL))? hatom_getllll(&durations_voice_elem->l_hatom) : NULL;
			t_llll *voice_velocities = (velocities_voice_elem && (hatom_gettype(&velocities_voice_elem->l_hatom) == H_LLLL))? hatom_getllll(&velocities_voice_elem->l_hatom) : NULL;
			t_llll *voice_ties = (ties_voice_elem && (hatom_gettype(&ties_voice_elem->l_hatom) == H_LLLL))? hatom_getllll(&ties_voice_elem->l_hatom) : NULL;
			t_llll *voice_graphic = (graphic_voice_elem && (hatom_gettype(&graphic_voice_elem->l_hatom) == H_LLLL))? hatom_getllll(&graphic_voice_elem->l_hatom) : NULL;
			t_llll *voice_breakpoints = (breakpoints_voice_elem && (hatom_gettype(&breakpoints_voice_elem->l_hatom) == H_LLLL))? hatom_getllll(&breakpoints_voice_elem->l_hatom) : NULL;
			t_llll *voice_slots = (slots_voice_elem && (hatom_gettype(&slots_voice_elem->l_hatom) == H_LLLL))? hatom_getllll(&slots_voice_elem->l_hatom) : NULL;

			t_llll *unboxed_voice_durations, *unboxed_voice_infos, *unboxed_voice_ties;
			t_llll *unboxed_voice_cents, *unboxed_voice_velocities, *unboxed_voice_graphic, *unboxed_voice_breakpoints, *unboxed_voice_slots;
			char debug1[1000], debug2[1000], debug3[1000], debug4[1000], debug5[1000], debug6[1000], debug7[1000];
//			llll_to_char_array(graphic, debug4, 1000);
//			llll_to_char_array(voice_graphic, debug5, 1000);


//			llll_to_char_array(voice_cents, debug1, 1000);
//			llll_to_char_array(voice_durations, debug2, 1000);
//			llll_to_char_array(voice_velocities, debug3, 1000);
//			llll_to_char_array(voice_ties, debug4, 1000);
//			llll_to_char_array(voice_graphic, debug5, 1000);
//			llll_to_char_array(voice_breakpoints, debug6, 1000);
//			llll_to_char_array(voice_slots, debug7, 1000);
 
			
			
			// These llll_flatten aren't simple llll_flatten(***, 1) because we have to take into account the possibility of data being formatted in rhythmic tree form for each outlet.
			// That is why we need to take care more subtly of some caveats (e.g. with slots: slots data can have variable depth; also with breakpoints since 
			// when there are no breakpoints there's a () list, while a breakpoint list has 1 more level of depth - and this isn't well handled by the nevative maxdepth of llll_flatten) 
			if (voice_cents) 
				llll_flatten(voice_cents, -2, 0);
			if (voice_durations) {
				llll_flatten(voice_durations, 1, 0);
				flat_up_to_level_starting_with_g(voice_durations);
			}
			if (voice_velocities)
				llll_flatten(voice_velocities, -2, 0);
			if (voice_ties) 
				llll_flatten(voice_ties, -2, 0);
            if (voice_graphic) {
                llll_flatten(voice_graphic, 1, 0);
                flat_up_to_for_graphic(voice_graphic);
            }
			if (voice_breakpoints) {
				llll_flatten(voice_breakpoints, 1, 0);
				flat_up_to_for_breakpoints(voice_breakpoints);
			}
            if (voice_slots) {
				llll_flatten(voice_slots, 1, 0);
				flat_up_to_for_slots(voice_slots);
			}
			
			llll_to_char_array(voice_cents, debug1, 1000);
			llll_to_char_array(voice_durations, debug2, 1000);
			llll_to_char_array(voice_velocities, debug3, 1000);
			llll_to_char_array(voice_ties, debug4, 1000);
			llll_to_char_array(voice_graphic, debug5, 1000);
			llll_to_char_array(voice_breakpoints, debug6, 1000);
			llll_to_char_array(voice_slots, debug6, 1000);


			// substituting 0s to grace levels

			
			// building the infos
			voice_infos = llll_get();

			for (cents_elem = (voice_cents) ? voice_cents->l_head : NULL, velocities_elem = (voice_velocities) ? voice_velocities->l_head : NULL, 
				graphic_elem = (voice_graphic) ? voice_graphic->l_head : NULL, breakpoints_elem = (voice_breakpoints) ? voice_breakpoints->l_head : NULL, 
				slots_elem = (voice_slots) ? voice_slots->l_head : NULL;
				cents_elem || velocities_elem || graphic_elem || breakpoints_elem || slots_elem;
				cents_elem = (cents_elem) ? cents_elem->l_next : NULL,
				velocities_elem = (velocities_elem) ? velocities_elem->l_next : NULL,
				graphic_elem = (graphic_elem) ? graphic_elem->l_next : NULL,
				breakpoints_elem = (breakpoints_elem) ? breakpoints_elem->l_next : NULL,
				slots_elem = (slots_elem) ? slots_elem->l_next : NULL) {
				
				t_llll *thisinlist = llll_get();
				if (cents_elem) 
					llll_appendhatom_clone(thisinlist, &cents_elem->l_hatom);
                else
                    llll_appendllll(thisinlist, llll_get());
				if (velocities_elem)
					llll_appendhatom_clone(thisinlist, &velocities_elem->l_hatom);
                else
                    llll_appendllll(thisinlist, llll_get());
				if (graphic_elem)
					llll_appendhatom_clone(thisinlist, &graphic_elem->l_hatom);
                else
                    llll_appendllll(thisinlist, llll_get());
				if (breakpoints_elem) 
					llll_appendhatom_clone(thisinlist, &breakpoints_elem->l_hatom);
                else
                    llll_appendllll(thisinlist, llll_get());
				if (slots_elem)
					llll_appendhatom_clone(thisinlist, &slots_elem->l_hatom);
                else
                    llll_appendllll(thisinlist, llll_get());

				llll_appendllll(voice_infos, thisinlist);
			}
			
            merge_rests_and_alltied_chords_from_separate_parameters(voice_durations, voice_infos, voice_ties, &unboxed_voice_durations, &unboxed_voice_infos, &unboxed_voice_ties, NULL, NULL, (e_merge_when)x->n_merge);
			
			// de-building the infos
			unboxed_voice_cents = llll_get();
			unboxed_voice_velocities = llll_get();
			unboxed_voice_graphic = llll_get();
			unboxed_voice_breakpoints = llll_get();
			unboxed_voice_slots = llll_get();
			for (info_elem = unboxed_voice_infos->l_head; info_elem; info_elem = info_elem->l_next) {
				t_llll *thiselemllll = hatom_getllll(&info_elem->l_hatom);
				if (thiselemllll->l_size >= 1) 
					llll_appendhatom_clone(unboxed_voice_cents, &thiselemllll->l_head->l_hatom, 0, WHITENULL_llll);
				if (thiselemllll->l_size >= 2) 
					llll_appendhatom_clone(unboxed_voice_velocities, &thiselemllll->l_head->l_next->l_hatom, 0, WHITENULL_llll);
				if (thiselemllll->l_size >= 3) 
					llll_appendhatom_clone(unboxed_voice_graphic, &thiselemllll->l_head->l_next->l_next->l_hatom, 0, WHITENULL_llll);
				if (thiselemllll->l_size >= 4) 
					llll_appendhatom_clone(unboxed_voice_breakpoints, &thiselemllll->l_head->l_next->l_next->l_next->l_hatom, 0, WHITENULL_llll);
				if (thiselemllll->l_size >= 5)
					llll_appendhatom_clone(unboxed_voice_slots, &thiselemllll->l_head->l_next->l_next->l_next->l_next->l_hatom, 0, WHITENULL_llll);
			}

			llll_free(unboxed_voice_infos);
			llll_free(voice_infos);
			
			// we append the boxed_voice_things to the boxed_things
			llll_appendllll(unboxed_cents, unboxed_voice_cents, 0, WHITENULL_llll);
			llll_appendllll(unboxed_durations, unboxed_voice_durations, 0, WHITENULL_llll);
			llll_appendllll(unboxed_ties, unboxed_voice_ties, 0, WHITENULL_llll);
			llll_appendllll(unboxed_velocities, unboxed_voice_velocities, 0, WHITENULL_llll);
			llll_appendllll(unboxed_graphic, unboxed_voice_graphic, 0, WHITENULL_llll);
			llll_appendllll(unboxed_breakpoints, unboxed_voice_breakpoints, 0, WHITENULL_llll);
			llll_appendllll(unboxed_slots, unboxed_voice_slots, 0, WHITENULL_llll);
		}
		
		// setting new extras
		unboxed_extras = llll_get();
		llll_prependsym(unboxed_graphic, _llllobj_sym_graphic, 0, WHITENULL_llll);
		llll_prependsym(unboxed_breakpoints, _llllobj_sym_breakpoints, 0, WHITENULL_llll);
		llll_prependsym(unboxed_slots, _llllobj_sym_slots, 0, WHITENULL_llll);
		llll_appendllll(unboxed_extras, unboxed_graphic, 0, WHITENULL_llll);
		llll_appendllll(unboxed_extras, unboxed_breakpoints, 0, WHITENULL_llll);
		llll_appendllll(unboxed_extras, unboxed_slots, 0, WHITENULL_llll);
		
		if (x->input_separate) {
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_extras, 4);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_ties, 3);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_velocities, 2);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_durations, 1);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_cents, 0);
		} else {
			t_llll *measureinfo_cloned = llll_clone(measureinfo);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_extras, 5);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_ties, 4);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_velocities, 3);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_durations, 2);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, unboxed_cents, 1);
			llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, measureinfo_cloned, 0);
		}
		
		// lists which we don't need any more (we don't free the lists who have been put in the gunload_llll!)
		for (i = 0; i < 6; i++) // we free measureinfo (if any), extras, ties, velocities, cents, durations
			llll_free(inlist[i]);

		x->n_ob.l_rebuild = 0;
		beatunbox_bang(x);
	}
}


void beatunbox_assist(t_beatunbox *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0)
			sprintf(s, x->input_separate ? "llll: Pitches or bang to trigger" : "llll: Score Gathered Syntax"); // @in 0 @type llll @digest Whole bach.score gathered syntax, or Measureinfo (in <m>separate</m> mode only), or bang
		else if (a == 1)
			sprintf(s, "llll: Durations"); // @in 1 @type llll @digest Durations (in <m>separate</m> mode only)
		else if (a == 2)
			sprintf(s, "llll: Velocities"); // @in 2 @type llll @digest Velocities (in <m>separate</m> mode only)
		else if (a == 3)
			sprintf(s, "llll: Ties");  // @in 3 @type llll @digest Ties (in <m>separate</m> mode only)
		else
			sprintf(s, "llll: Extras");  // @in 4 @type llll @digest Extras (in <m>separate</m> mode only)
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0)
			sprintf(s, x->input_separate ? "llll (%s): Pitches or Cents" : "llll (%s): Measureinfo", type);  // @out 0 @type llll @digest Measureinfo – in "separate" mode: Pitches or MIDIcents
		else if (a == 1)
			sprintf(s, x->input_separate ? "llll (%s): Durations" : "llll (%s): Pitches or Cents", type);  // @out 1 @type llll @digest Pitches or MIDIcents – in "separate" mode: Durations
		else if (a == 2)
			sprintf(s, x->input_separate ? "llll (%s): Velocities" : "llll (%s): Durations", type);  // @out 2 @type llll @digest Durations – in "separate" mode: Velocities
		else if (a == 3)
			sprintf(s, x->input_separate ? "llll (%s): Ties" : "llll (%s): Velocities", type);  // @out 3 @type llll @digest Velocities – in "separate" mode: Ties
		else if (a == 4)
			sprintf(s, x->input_separate ? "llll (%s): Extras" : "llll (%s): Ties", type);   // @out 4 @type llll @digest Ties – in "separate" mode: Extras
		else
			sprintf(s, "llll (%s): Extras", type);   // @out 5 @type llll @digest Extras (only existing when the mode is NOT "separate")
	}
}

void beatunbox_inletinfo(t_beatunbox *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void beatunbox_free(t_beatunbox *x) // we must free cache!!!
{
	long i;
	if (x->input_separate) {
		for (i = 1; i < 5; i++)
			object_free_debug(x->n_proxy[i]);
	}
	
	systhread_mutex_free_debug(x->n_mutex);

	llllobj_obj_free((t_llllobj_object *) x);
}

t_beatunbox *beatunbox_new(t_symbol *s, short ac, t_atom *av)
{
	t_beatunbox *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long true_ac = attr_args_offset(ac, av);

	if ((x = (t_beatunbox *) object_alloc_debug(beatunbox_class))) {
		// @arg 0 @name separate @optional 1 @type symbol @digest Separate parameters mode  
		// @description Put a "separate" symbol as argument if you want to input the separate parameters (and not the bach.score gathered syntax).
		x->input_separate = true_ac && atom_gettype(av) == A_SYM && atom_getsym(av) == _llllobj_sym_separate;
 		
        x->n_merge = k_MERGE_WHEN_ALWAYS; // k_MERGE_WHEN_DRAWABLE;
        
		if (x->input_separate) {
			x->n_proxy[4] = proxy_new_debug((t_object *) x, 4, &x->n_in);
			x->n_proxy[3] = proxy_new_debug((t_object *) x, 3, &x->n_in);
			x->n_proxy[2] = proxy_new_debug((t_object *) x, 2, &x->n_in);
			x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
		}
		
		attr_args_process(x, ac, av);
		systhread_mutex_new_debug(&x->n_mutex, 0);

 		llllobj_obj_setup((t_llllobj_object *) x, 6, x->input_separate ? "44444" : "444444");

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
