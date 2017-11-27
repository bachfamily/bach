/**
	@file
	beatbox.c
	
	@name 
	bach.beatbox
	
	@realname 
	bach.beatbox

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Box voice-wise parameters into measure-wise information
	
	@description
	Adds a parenthesis level representing measures in a plain list of parameters. 
	More precisely, it formats plain lists of <o>bach.score</o> parameters into measure-wise packets, 
	according to the given time signature(s). 
	
	@discussion
	bach.beatbox is an useful tool if you don't want to think about your data (cents, durations...) measure-wise, 
	but just as a long plain sequence: you can enter the long sequence (actually, one long sequence for each voice 
	you want to create) and then let beatbox make the boxing.
	
	@category
	bach, bach objects, bach notation

	@keywords
	box, measure, parenthesis, wrap, measurewise, voicewise, format, flow, plain, measureinfo, beat

	@seealso
	bach.beatunbox, bach.score, bach.quantize, bach.score2roll, Through The Looking Glass
	
	@owner
	Daniele Ghisi
*/

#include "notation.h" // header with all the structures for the notation objects
#include "ext.h"
#include "ext_obex.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include <stdio.h>
#include <locale.h>
#include <time.h> 

typedef struct _beatbox
{
	struct llllobj_object 	n_ob;
	
	long				n_mode;
//	long				n_rebuild;
	long				n_proxies;
	
	void				*n_proxy[6];
	long				n_in;
	
	char				autoclear;
	char				output_separate; // < output separate parameters?
	
	t_systhread_mutex	n_mutex;
	
} t_beatbox;


void beatbox_assist(t_beatbox *x, void *b, long m, long a, char *s);
void beatbox_inletinfo(t_beatbox *x, void *b, long a, char *t);

t_beatbox *beatbox_new(t_symbol *s, short ac, t_atom *av);
void beatbox_free(t_beatbox *x);

void beatbox_bang(t_beatbox *x);
void beatbox_anything(t_beatbox *x, t_symbol *msg, long ac, t_atom *av);

t_class *beatbox_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.beatbox", (method)beatbox_new, (method)beatbox_free, (short)sizeof(t_beatbox), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description 
	// In first inlet: Sets the Measureinfo and output the boxed content. <br />
	// In second inlet: Sets the Cents parameter. <br />
	// In third inlet: Sets the Durations. <br />
	// In fourth inlet: Sets the Velocities. <br />
	// In fifth inlet: Sets the Ties. <br />
	// In sixth inlet: Sets the Extras. <br /> <br />  
	// @copy BACH_DOC_MEASUREINFO_SYNTAX
	class_addmethod(c, (method)beatbox_anything,		"anything",		A_GIMME,	0);
	class_addmethod(c, (method)beatbox_anything,		"list",			A_GIMME,	0);

	// @method bang @digest Perform the boxing operation.
	// @description Perform the boxing operation on the most recently received input data.
	class_addmethod(c, (method)beatbox_bang,			"bang",			0);
	
	class_addmethod(c, (method)beatbox_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)beatbox_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);


	CLASS_ATTR_CHAR(c, "autoclear", 0, t_beatbox, autoclear); 
	CLASS_ATTR_STYLE_LABEL(c,"autoclear",0,"onoff","Autoclear");
	CLASS_ATTR_BASIC(c, "autoclear",0);
	// @description Automatically clears the score before outputting the new data.


	class_register(CLASS_BOX, c);
	beatbox_class = c;
	
	dev_post("bach.beatbox compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void beatbox_bang(t_beatbox *x)
{
	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		beatbox_anything(x, _sym_bang, 0, NULL);
	else {
		if (x->output_separate) {
			if (x->autoclear)
				llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, 0, _llllobj_sym_clear, 0, NULL);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 6);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 5);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 4);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 3);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 2);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
			llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 0);
		} else {
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
		}
	}
}

/*
long debug_print_pointer_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_LLLL)
		dev_post("velocities – llll: %p", hatom_getllll(a));
	return 0;
}
*/

void beatbox_anything(t_beatbox *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);
	long i;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), inlet);
		return;
	} else 
	
	if (msg == _llllobj_sym_clearall) {
		for (i = 0; i < 6; i++)
			llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), i);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		x->n_ob.l_rebuild = 1;
	}
	
	if (inlet == 0) {
		// do calculations

		long i;
		t_llll *inlist[6];
		t_llll *measures, *cents, *durations, *velocities, *ties, *extras;
		t_llll *graphic = NULL, *breakpoints = NULL, *slots = NULL, *articulations = NULL;
		t_llllelem *extraselem;
		
		char need_free_graphic = false; 
		char need_free_breakpoints = false; 
		char need_free_slots = false; 
		char need_free_articulations = false;

		for (i = 0; i < 6; i++)
			inlist[i] = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 1);
		
		measures = inlist[0];
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
		if (extraselem && (hatom_gettype(&extraselem->l_hatom) == H_LLLL)
			&& (hatom_getllll(&extraselem->l_hatom)->l_size >= 2)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == H_SYM)
			&& (hatom_gettype(&hatom_getllll(&extraselem->l_hatom)->l_head->l_next->l_hatom) == H_LLLL)
			&& (hatom_getsym(&hatom_getllll(&extraselem->l_hatom)->l_head->l_hatom) == _llllobj_sym_articulations)) {
				articulations = hatom_getllll(&extraselem->l_hatom);
				llll_behead(articulations);
				extraselem = extraselem->l_next;
		}

		if (!graphic) { 
			need_free_graphic = true;
			graphic = llll_get(); 
		}
		if (!breakpoints) {
			breakpoints = llll_get(); 
			need_free_breakpoints = true;
		}
		if (!slots) {
			slots = llll_get(); 
			need_free_slots = true;
		}
		if (!articulations) {
			articulations = llll_get(); 
			need_free_articulations = true;
		}

		// then, we have a cycle on the different voices
		if (measures && measures->l_head) { // measures have to be defined!!!
			long num_voices, j, num_repetitions;
			t_llll *boxed_graphic, *boxed_breakpoints, *boxed_slots, *boxed_articulations, *boxed_ties, *boxed_velocities, *boxed_cents, *boxed_durations;
			t_llllelem *ties_elem, *measures_elem, *durations_elem, *cents_elem, *velocities_elem, *graphic_elem, *breakpoints_elem, *slots_elem, *articulations_elem;
			t_llll* boxed_extras;	
		// first: we set measures properly
			if (measures->l_depth <= 3) { // we just put 1 tempo for everything!
				llll_wrap_once(&measures);
				llll_wrap_once(&measures);
			}
			
			
			// detecting number of voices
			num_voices = measures->l_size;
			if (cents && ((long)cents->l_size > num_voices)) num_voices = cents->l_size;
			if (durations && ((long)durations->l_size > num_voices)) num_voices = durations->l_size;
			if (velocities && ((long)velocities->l_size > num_voices)) num_voices = velocities->l_size;
			if (ties && ((long)ties->l_size > num_voices)) num_voices = ties->l_size;
			if (graphic && ((long)graphic->l_size > num_voices)) num_voices = graphic->l_size;
			if (breakpoints && ((long)breakpoints->l_size > num_voices)) num_voices = breakpoints->l_size;
			if (slots && ((long)slots->l_size > num_voices)) num_voices = slots->l_size;
			if (articulations && ((long)articulations->l_size > num_voices)) num_voices = articulations->l_size;
			
			num_repetitions = num_voices - measures->l_size;
			if (measures && measures->l_tail) {
				for (j = 1; j <= num_repetitions; j++)
					llll_appendhatom_clone(measures, &measures->l_tail->l_hatom, 0, WHITENULL_llll);
			}
			
			boxed_graphic = llll_get();
			boxed_breakpoints = llll_get();
			boxed_slots = llll_get();
			boxed_articulations = llll_get();
			boxed_ties = llll_get();
			boxed_velocities = llll_get();
			boxed_cents = llll_get();
			boxed_durations = llll_get();
			
			for (cents_elem = cents->l_head, velocities_elem = velocities->l_head,
				 ties_elem = ties->l_head, measures_elem = measures->l_head, durations_elem = durations->l_head,
				 graphic_elem = graphic->l_head, breakpoints_elem = breakpoints->l_head, slots_elem = slots->l_head, articulations_elem = articulations->l_head;
				 cents_elem || velocities_elem || durations_elem || measures_elem || ties_elem || graphic_elem || breakpoints_elem || slots_elem || articulations_elem;
				 cents_elem = cents_elem ? cents_elem->l_next : NULL, 
				 velocities_elem = velocities_elem ? velocities_elem->l_next : NULL, 
				 ties_elem = ties_elem ? ties_elem->l_next : NULL, 
				 measures_elem = measures_elem ? measures_elem->l_next : NULL, 
				 durations_elem = durations_elem ? durations_elem->l_next : NULL, 
				 graphic_elem = graphic_elem ? graphic_elem->l_next : NULL, 
				 breakpoints_elem = breakpoints_elem ? breakpoints_elem->l_next : NULL, 
				 slots_elem = slots_elem ? slots_elem->l_next : NULL,
				 articulations_elem = articulations_elem ? articulations_elem->l_next : NULL) { //cycle on the VOICES
				
				t_llll *voice_graphic = (graphic_elem && (hatom_gettype(&graphic_elem->l_hatom) == H_LLLL))? hatom_getllll(&graphic_elem->l_hatom) : NULL;
				t_llll *voice_breakpoints = (breakpoints_elem && (hatom_gettype(&breakpoints_elem->l_hatom) == H_LLLL))? hatom_getllll(&breakpoints_elem->l_hatom) : NULL;
				t_llll *voice_slots = (slots_elem && (hatom_gettype(&slots_elem->l_hatom) == H_LLLL))? hatom_getllll(&slots_elem->l_hatom) : NULL;
				t_llll *voice_articulations = (articulations_elem && (hatom_gettype(&articulations_elem->l_hatom) == H_LLLL))? hatom_getllll(&articulations_elem->l_hatom) : NULL;
				t_llll *rough_voice_ties = (ties_elem && (hatom_gettype(&ties_elem->l_hatom) == H_LLLL))? hatom_getllll(&ties_elem->l_hatom) : NULL;
				t_llll *voice_velocities = (velocities_elem && (hatom_gettype(&velocities_elem->l_hatom) == H_LLLL))? hatom_getllll(&velocities_elem->l_hatom) : NULL;
				t_llll *voice_cents = (cents_elem && (hatom_gettype(&cents_elem->l_hatom) == H_LLLL))? hatom_getllll(&cents_elem->l_hatom) : NULL;
				t_llll *voice_measures = (measures_elem && (hatom_gettype(&measures_elem->l_hatom) == H_LLLL))? hatom_getllll(&measures_elem->l_hatom) : NULL;
				
				// cents, velocities and extras will have to be gathered in a single t_llll *infos list
				t_llll *voice_durations = NULL, *voice_infos = llll_get(); t_llll *voice_ties = llll_get();
				t_llllelem *voice_cents_elem, *voice_velocities_elem, *voice_graphic_elem, *voice_breakpoints_elem, *voice_slots_elem, *voice_articulations_elem, *voice_ties_elem;
				long voice_infos_size, voice_durations_size;
				t_rational global_voice_duration, curr_dur;
				t_llll *boxes;
				long num, den;
				t_llllelem *measures_elem;
				t_llll *boxed_voice_ties = NULL, *boxed_voice_durations = NULL, *boxed_voice_infos = NULL;
				t_llll *boxed_voice_cents, *boxed_voice_velocities, *boxed_voice_graphic, *boxed_voice_breakpoints, *boxed_voice_slots, *boxed_voice_articulations;
				t_llllelem *boxed_infos_elem, *boxed_dur_elem;
				t_llllelem *e1, *e2, *e3, *f1, *f2, *f3;

				if (durations_elem && (hatom_gettype(&durations_elem->l_hatom) == H_LLLL))
					voice_durations = llll_clone(hatom_getllll(&durations_elem->l_hatom));
				else
					voice_durations = llll_get();
					
				for (voice_cents_elem = (voice_cents) ? voice_cents->l_head : NULL, 
					 voice_velocities_elem = (voice_velocities) ? voice_velocities->l_head : NULL, 
					 voice_graphic_elem = (voice_graphic) ? voice_graphic->l_head : NULL,
					 voice_breakpoints_elem = (voice_breakpoints) ? voice_breakpoints->l_head : NULL,
					 voice_slots_elem = (voice_slots) ? voice_slots->l_head : NULL,
					 voice_articulations_elem = (voice_articulations) ? voice_articulations->l_head : NULL,
					 voice_ties_elem = (rough_voice_ties) ? rough_voice_ties->l_head : NULL;
					 voice_cents_elem || voice_velocities_elem || voice_graphic_elem || voice_breakpoints_elem || voice_articulations_elem || voice_slots_elem || voice_ties_elem;
					 voice_cents_elem = voice_cents_elem ? voice_cents_elem->l_next : NULL, 
					 voice_velocities_elem = voice_velocities_elem ? voice_velocities_elem->l_next : NULL, 
					 voice_graphic_elem = voice_graphic_elem ? voice_graphic_elem->l_next : NULL,
					 voice_breakpoints_elem = voice_breakpoints_elem ? voice_breakpoints_elem->l_next : NULL,
					 voice_slots_elem = voice_slots_elem ? voice_slots_elem->l_next : NULL,
					 voice_articulations_elem = voice_articulations_elem ? voice_articulations_elem->l_next : NULL,
					 voice_ties_elem = voice_ties_elem ? voice_ties_elem->l_next : NULL) {
					
					t_llll *singleinfo = llll_get();
					t_llll *thisextras = llll_get();
					long num_notes = 1;
					
					if (voice_cents_elem) {
						llll_appendhatom_clone(singleinfo, &voice_cents_elem->l_hatom, 0, WHITENULL_llll);
						if ((hatom_gettype(&voice_cents_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_cents_elem->l_hatom)->l_size) > num_notes))
							num_notes = hatom_getllll(&voice_cents_elem->l_hatom)->l_size;
					} else
						llll_appendllll(singleinfo, llll_get(), 0, WHITENULL_llll);
					
					if (voice_velocities_elem) {
						llll_appendhatom_clone(singleinfo, &voice_velocities_elem->l_hatom, 0, WHITENULL_llll);
						if ((hatom_gettype(&voice_velocities_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_velocities_elem->l_hatom)->l_size) > num_notes))
							num_notes = hatom_getllll(&voice_velocities_elem->l_hatom)->l_size;
					} else
						llll_appendllll(singleinfo, llll_get(), 0, WHITENULL_llll);
					
					if (voice_graphic_elem) {
						llll_appendhatom_clone(thisextras, &voice_graphic_elem->l_hatom, 0, WHITENULL_llll);
						if ((hatom_gettype(&voice_graphic_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_graphic_elem->l_hatom)->l_size) > num_notes))
							num_notes = hatom_getllll(&voice_graphic_elem->l_hatom)->l_size;
					} else
						llll_appendllll(thisextras, llll_get(), 0, WHITENULL_llll);
						
					if (voice_breakpoints_elem) {
						llll_appendhatom_clone(thisextras, &voice_breakpoints_elem->l_hatom, 0, WHITENULL_llll);
						if ((hatom_gettype(&voice_breakpoints_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_breakpoints_elem->l_hatom)->l_size) > num_notes))
							num_notes = hatom_getllll(&voice_breakpoints_elem->l_hatom)->l_size;
					} else 
						llll_appendllll(thisextras, llll_get(), 0, WHITENULL_llll);
					
					if (voice_slots_elem) {
						llll_appendhatom_clone(thisextras, &voice_slots_elem->l_hatom, 0, WHITENULL_llll);
						if ((hatom_gettype(&voice_slots_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_slots_elem->l_hatom)->l_size) > num_notes))
							num_notes = hatom_getllll(&voice_slots_elem->l_hatom)->l_size;
					} else 
						llll_appendllll(thisextras, llll_get(), 0, WHITENULL_llll);
					
					if (voice_articulations_elem) {
						llll_appendhatom_clone(thisextras, &voice_articulations_elem->l_hatom, 0, WHITENULL_llll);
						if ((hatom_gettype(&voice_articulations_elem->l_hatom) == H_LLLL) && ((long)(hatom_getllll(&voice_articulations_elem->l_hatom)->l_size) > num_notes))
							num_notes = hatom_getllll(&voice_articulations_elem->l_hatom)->l_size;
					} else 
						llll_appendllll(thisextras, llll_get(), 0, WHITENULL_llll);
					
					llll_appendllll(singleinfo, thisextras, 0, WHITENULL_llll);

					llll_appendllll(voice_infos, singleinfo, 0, WHITENULL_llll);
						
					// refining ties
					if (voice_ties_elem && (hatom_gettype(&voice_ties_elem->l_hatom) == H_LONG)) 
						llll_appendllll(voice_ties, repeat_long(hatom_getlong(&voice_ties_elem->l_hatom), num_notes), 0, WHITENULL_llll);
					else if (voice_ties_elem && (hatom_gettype(&voice_ties_elem->l_hatom) == H_LLLL) && (hatom_getllll(&voice_ties_elem->l_hatom)->l_size > 0)) {
						t_llll *thisllll = hatom_getllll(&voice_ties_elem->l_hatom);
						t_llll *inllll = llll_get(); t_llllelem *thiselem;
						for (i = 0, thiselem = thisllll->l_head; (i < num_notes); i++, thiselem = (thiselem) ? thiselem->l_next : NULL)
							llll_appendlong(inllll, (thiselem) ? hatom_getlong(&thiselem->l_hatom) : 0, 0, WHITENULL_llll);
						llll_appendllll(voice_ties, inllll, 0, WHITENULL_llll);
					} else 
						llll_appendllll(voice_ties, repeat_long(0, num_notes), 0, WHITENULL_llll);
				}

				// what if the infos are more than the durations?
				voice_infos_size = (voice_infos) ? voice_infos->l_size : 0;
				voice_durations_size = voice_durations->l_size;
				if (voice_infos_size > voice_durations_size) { 
					long j;
					t_rational pad_duration = voice_durations->l_tail && is_hatom_number(&voice_durations->l_tail->l_hatom) ? hatom_getrational(&voice_durations->l_tail->l_hatom) : RAT_1OVER4;
					for (j = voice_durations_size + 1; j <= voice_infos_size; j++)
						llll_appendrat(voice_durations, pad_duration, 0, WHITENULL_llll);  
				}
				
				// we create the measure-boxes, via the <measures> llll.
				global_voice_duration = llll_sum_abs_of_rat_llll_up_to_g_list(voice_durations);

				if (global_voice_duration.r_den == 0) 
					global_voice_duration = long2rat(0);
				boxes = llll_get(); 
				num = den = 4; // default time signature is 4/4
				measures_elem = (voice_measures) ? voice_measures->l_head : NULL;
				curr_dur = long2rat(0);
				while (measures_elem || (rat_rat_cmp(curr_dur, global_voice_duration) < 0)) {
					long loop_for_n_times = 1, j;
					if (measures_elem && (hatom_gettype(&measures_elem->l_hatom) == H_LLLL)) {
						t_llll *measurellll = hatom_getllll(&measures_elem->l_hatom);
						if (measurellll && (measurellll->l_size > 0)) {
							t_llll *ts = NULL;
							if (hatom_gettype(&measurellll->l_head->l_hatom) == H_LONG) {
								loop_for_n_times = hatom_getlong(&measurellll->l_head->l_hatom);
								if (measurellll->l_size > 1)
									ts = hatom_getllll(&measurellll->l_head->l_next->l_hatom);
							} else if (hatom_gettype(&measurellll->l_head->l_hatom) == H_LLLL) {
								ts = hatom_getllll(&measurellll->l_head->l_hatom);
							}
							
							if (ts && (ts->l_size > 0) && ts->l_head) {
								if (hatom_gettype(&ts->l_head->l_hatom) == H_LLLL) { // compound time signature, e.g. ((3 5) 8)
									num = llll_sum_abs_of_rat_llll(hatom_getllll(&ts->l_head->l_hatom)).r_num;
								} else if (hatom_gettype(&ts->l_head->l_hatom) == H_LONG) {
									num = hatom_getlong(&ts->l_head->l_hatom);
								}
							}
							if (ts && (ts->l_size > 1) && ts->l_head && ts->l_head->l_next && (hatom_gettype(&ts->l_head->l_next->l_hatom) == H_LONG)) {
								den = hatom_getlong(&ts->l_head->l_next->l_hatom);
							}

						}
						if (num <= 0) num = 4;
						if (den <= 0) den = 4;
					}
					for (j = 0; j < loop_for_n_times; j++) {
						t_rational this_measure_sym_duration = genrat(num, den);
						llll_appendrat(boxes, this_measure_sym_duration, 0, WHITENULL_llll);
						curr_dur = rat_rat_sum(curr_dur, this_measure_sym_duration);
					}
					if (measures_elem) measures_elem = measures_elem->l_next;
				}
			
				split_rhythm_to_boxes(voice_durations, voice_infos, voice_ties, boxes, &boxed_voice_durations, &boxed_voice_infos, &boxed_voice_ties, false, false);
				
				// now we split the boxed_infos into:
				boxed_voice_cents = llll_get(); boxed_voice_velocities = llll_get(); 
				boxed_voice_graphic = llll_get(); boxed_voice_breakpoints = llll_get(); boxed_voice_slots = llll_get(), boxed_voice_articulations = llll_get();
				for (	boxed_infos_elem = boxed_voice_infos->l_head, boxed_dur_elem = boxed_voice_durations->l_head; 
						boxed_infos_elem && boxed_dur_elem; 
						boxed_infos_elem = boxed_infos_elem ? boxed_infos_elem->l_next : NULL, boxed_dur_elem = boxed_dur_elem ? boxed_dur_elem->l_next : NULL ) {
						
					// this is a cycle on the boxes. For each box, we gotta create a box in each of our boxed_cents/vel/extras lllls
					t_llll *this_box_cents = llll_get(); 
					t_llll *this_box_velocities = llll_get(); 
					t_llll *this_box_graphic = llll_get(); 
					t_llll *this_box_breakpoints = llll_get(); 
					t_llll *this_box_slots = llll_get();
					t_llll *this_box_articulations = llll_get();
					
					t_llll *this_box_llll = boxed_infos_elem ? hatom_getllll(&boxed_infos_elem->l_hatom) : NULL;
					t_llll *this_durs_llll = boxed_dur_elem ? hatom_getllll(&boxed_dur_elem->l_hatom) : NULL;
					t_llllelem *this_box_llllelem, *this_dur_llllelem;
					for (	this_box_llllelem = this_box_llll ? this_box_llll->l_head : NULL, this_dur_llllelem = this_durs_llll ? this_durs_llll->l_head : NULL; 
							this_box_llllelem || this_dur_llllelem; 
							this_box_llllelem = this_box_llllelem ? this_box_llllelem->l_next : NULL, this_dur_llllelem = this_dur_llllelem ? this_dur_llllelem->l_next : NULL) {
						if (this_box_llllelem) {
							t_llll *singleinfo_llll = hatom_getllll(&this_box_llllelem->l_hatom);

							if (singleinfo_llll->l_head) 
								llll_appendhatom_clone(this_box_cents, &singleinfo_llll->l_head->l_hatom, 0, WHITENULL_llll);
							else
								llll_appendllll(this_box_cents, get_nilnil(), 0, WHITENULL_llll);

							if (singleinfo_llll->l_head && singleinfo_llll->l_head->l_next) {
								llll_appendhatom_clone(this_box_velocities, &singleinfo_llll->l_head->l_next->l_hatom, 0, WHITENULL_llll); // QUI LEAK
							} else
								llll_appendllll(this_box_velocities, get_nilnil(), 0, WHITENULL_llll);

							if (singleinfo_llll->l_head && singleinfo_llll->l_head->l_next && singleinfo_llll->l_head->l_next->l_next) {
								if (hatom_gettype(&singleinfo_llll->l_head->l_next->l_next->l_hatom) == H_LLLL) {
									t_llll *theseextras = hatom_getllll(&singleinfo_llll->l_head->l_next->l_next->l_hatom);
									
									if (theseextras->l_head)
										llll_appendhatom_clone(this_box_graphic, &theseextras->l_head->l_hatom, 0, WHITENULL_llll);
									else
										llll_appendllll(this_box_graphic, get_nilnil(), 0, WHITENULL_llll);
										
									if (theseextras->l_head && theseextras->l_head->l_next)
										llll_appendhatom_clone(this_box_breakpoints, &theseextras->l_head->l_next->l_hatom, 0, WHITENULL_llll);
									else
										llll_appendllll(this_box_breakpoints, get_nilnil(), 0, WHITENULL_llll);
									
									if (theseextras->l_head && theseextras->l_head->l_next && theseextras->l_head->l_next->l_next)
										llll_appendhatom_clone(this_box_slots, &theseextras->l_head->l_next->l_next->l_hatom, 0, WHITENULL_llll);
									else
										llll_appendllll(this_box_slots, get_nilnil(), 0, WHITENULL_llll);
										
									if (theseextras->l_head && theseextras->l_head->l_next && theseextras->l_head->l_next->l_next && theseextras->l_head->l_next->l_next->l_next)
										llll_appendhatom_clone(this_box_articulations, &theseextras->l_head->l_next->l_next->l_next->l_hatom, 0, WHITENULL_llll);
									else
										llll_appendllll(this_box_articulations, get_nilnil(), 0, WHITENULL_llll);
								} else {
									llll_appendllll(this_box_graphic, get_nilnil(), 0, WHITENULL_llll);
									llll_appendllll(this_box_breakpoints, get_nilnil(), 0, WHITENULL_llll);
									llll_appendllll(this_box_slots, get_nilnil(), 0, WHITENULL_llll);
									llll_appendllll(this_box_articulations, get_nilnil(), 0, WHITENULL_llll);
								}
							} else {
								llll_appendllll(this_box_graphic, get_nilnil(), 0, WHITENULL_llll);
								llll_appendllll(this_box_breakpoints, get_nilnil(), 0, WHITENULL_llll);
								llll_appendllll(this_box_slots, get_nilnil(), 0, WHITENULL_llll);
								llll_appendllll(this_box_articulations, get_nilnil(), 0, WHITENULL_llll);
							}
							if (!this_dur_llllelem && this_durs_llll) 
								llll_appendrat(this_durs_llll, RAT_1OVER4, 0, WHITENULL_llll);
						} else {
							llll_appendllll(this_box_cents, llll_get(), 0, WHITENULL_llll);
							llll_appendllll(this_box_velocities, llll_get(), 0, WHITENULL_llll);
							llll_appendllll(this_box_graphic, llll_get(), 0, WHITENULL_llll);
							llll_appendllll(this_box_breakpoints, llll_get(), 0, WHITENULL_llll);
							llll_appendllll(this_box_slots, llll_get(), 0, WHITENULL_llll);
							llll_appendllll(this_box_articulations, llll_get(), 0, WHITENULL_llll);
						}
					}
					
					llll_appendllll(boxed_voice_cents, this_box_cents, 0, WHITENULL_llll);
					llll_appendllll(boxed_voice_velocities, this_box_velocities, 0, WHITENULL_llll);
					llll_appendllll(boxed_voice_graphic, this_box_graphic, 0, WHITENULL_llll);
					llll_appendllll(boxed_voice_breakpoints, this_box_breakpoints, 0, WHITENULL_llll);
					llll_appendllll(boxed_voice_slots, this_box_slots, 0, WHITENULL_llll);
					llll_appendllll(boxed_voice_articulations, this_box_articulations, 0, WHITENULL_llll);
				}


				// setting note levels properly
				for (	e1 = boxed_voice_cents->l_head, e2 = boxed_voice_velocities->l_head, e3 = boxed_voice_durations->l_head; 
						e1 && e2; e1 = e1->l_next, e2 = e2->l_next, e3 = e3 ? e3->l_next : NULL) {
					if (hatom_gettype(&e1->l_hatom) == H_LLLL && hatom_gettype(&e2->l_hatom) == H_LLLL) {
						for (	f1 = hatom_getllll(&e1->l_hatom)->l_head, f2 = hatom_getllll(&e2->l_hatom)->l_head,
								f3 = e3 && hatom_gettype(&e3->l_hatom) == H_LLLL ? hatom_getllll(&e3->l_hatom)->l_head : NULL;
								f1 && f2; f1 = f1->l_next, f2 = f2->l_next, f3 = f3 ? f3->l_next : NULL) {
							long type_f1 = hatom_gettype(&f1->l_hatom), type_f2 = hatom_gettype(&f2->l_hatom);
							long num_notes = 0;
							if (type_f1 != H_LLLL || type_f2 != H_LLLL)
								num_notes = 1;
							if (type_f1 == H_LLLL)
								num_notes = MAX(num_notes, (long)(hatom_getllll(&f1->l_hatom)->l_size));
							if (type_f2 == H_LLLL)
								num_notes = MAX(num_notes, (long)(hatom_getllll(&f2->l_hatom)->l_size));
							
							// Up to bach 0.7.1, when somebody put a "nil" in correspondence to a 
							// non-rest duration element a default dummy note was created.
							// Starting from bach 0.7.2, both durations and cents are capable to define rests, thus
							// the following two lines are not used any more:

//							if (num_notes == 0 && f3 && is_hatom_number(&f3->l_hatom) && hatom_getrational(&f3->l_hatom).r_num > 0)
//								num_notes = 1; 

							
							if (hatom_gettype(&f1->l_hatom) != H_LLLL || (hatom_getllll(&f1->l_hatom)->l_size == 0 && num_notes > 0)) {
								t_llll *ll = repeat_hatom(&f1->l_hatom, num_notes);
								hatom_change_to_llll_and_free(&f1->l_hatom, ll);
							}

							if (hatom_gettype(&f2->l_hatom) != H_LLLL || (hatom_getllll(&f2->l_hatom)->l_size == 0 && num_notes > 0)) {
								t_llll *ll = repeat_hatom(&f2->l_hatom, num_notes);
								hatom_change_to_llll_and_free(&f2->l_hatom, ll);
							}
						}
					}
				}


				// lists which we don't need any more (we don't free the lists who have been put in the gunload_llll!)
				llll_free(boxes);
				if (boxed_voice_infos) 
					llll_free(boxed_voice_infos); // have been cloned-split into cents/vel/extras.
				llll_free(voice_infos);
				llll_free(voice_ties);
				llll_free(voice_durations);

				// we append the boxed_voice_things to the boxed_things
				llll_appendllll(boxed_graphic, boxed_voice_graphic, 0, WHITENULL_llll);
				llll_appendllll(boxed_breakpoints, boxed_voice_breakpoints, 0, WHITENULL_llll);
				llll_appendllll(boxed_slots, boxed_voice_slots, 0, WHITENULL_llll);
				llll_appendllll(boxed_articulations, boxed_voice_articulations, 0, WHITENULL_llll);
				llll_appendllll(boxed_ties, boxed_voice_ties, 0, WHITENULL_llll);
				llll_appendllll(boxed_velocities, boxed_voice_velocities, 0, WHITENULL_llll);
				llll_appendllll(boxed_cents, boxed_voice_cents, 0, WHITENULL_llll);
				llll_appendllll(boxed_durations, boxed_voice_durations, 0, WHITENULL_llll);
				
			}
			
			// setting new extras
			boxed_extras = llll_get();
			llll_prependsym(boxed_graphic, _llllobj_sym_graphic, 0, WHITENULL_llll);
			llll_prependsym(boxed_breakpoints, _llllobj_sym_breakpoints, 0, WHITENULL_llll);
			llll_prependsym(boxed_slots, _llllobj_sym_slots, 0, WHITENULL_llll);
			llll_prependsym(boxed_articulations, _llllobj_sym_articulations, 0, WHITENULL_llll);
			llll_appendllll(boxed_extras, boxed_graphic, 0, WHITENULL_llll);
			llll_appendllll(boxed_extras, boxed_breakpoints, 0, WHITENULL_llll);
			llll_appendllll(boxed_extras, boxed_slots, 0, WHITENULL_llll);
			llll_appendllll(boxed_extras, boxed_articulations, 0, WHITENULL_llll);
			
/*			char debug1[1000], debug2[1000], debug3[1000], debug4[1000], debug5[1000], debug6[1000];
			llll_to_char_array(boxed_extras, debug1, 999);
			llll_to_char_array(boxed_ties, debug2, 999); //debug2 + 60
			llll_to_char_array(boxed_velocities, debug3, 999);
			llll_to_char_array(boxed_durations, debug4, 999); //debug2 + 60
			llll_to_char_array(boxed_cents, debug5, 999);
			llll_to_char_array(measures, debug6, 999);*/
			
			if (x->output_separate) {
				llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_extras, 6);
				llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_ties, 5);
				llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_velocities, 4);
				llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_durations, 3);
				llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, boxed_cents, 2);
				llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, measures, 1);
			} else {
				t_llll *gathered = score_separate2gathered_syntax(measures, boxed_cents, boxed_durations, boxed_velocities, boxed_ties, boxed_extras);
				
				t_llllelem *evoice, *emeas, *ech;
				// checking for grace chords in the form (g SOMETHING), and avoiding them
				// we might have gathered chords like ((g 1/8) (6000 100 1)) which we need to turn into (g (1/8 (6000 100 1)))
				for (evoice = gathered->l_head; evoice; evoice = evoice->l_next) {
					if (hatom_gettype(&evoice->l_hatom) == H_LLLL) {
						for (emeas = hatom_getllll(&evoice->l_hatom)->l_head; emeas; emeas = emeas->l_next) {
							if (hatom_gettype(&emeas->l_hatom) == H_LLLL) {
								for (ech = hatom_getllll(&emeas->l_hatom)->l_head; ech; ech = ech->l_next) {
									if (hatom_gettype(&ech->l_hatom) == H_LLLL) {
										t_llll *sll, *ll = hatom_getllll(&ech->l_hatom);
										if (ll && ll->l_head && hatom_gettype(&ll->l_head->l_hatom) == H_LLLL
											&& (sll = hatom_getllll(&ll->l_head->l_hatom)) && sll->l_head &&
											hatom_gettype(&sll->l_head->l_hatom) == H_SYM && hatom_getsym(&sll->l_head->l_hatom) == _llllobj_sym_g) {

											t_llll *new_ll = llll_clone(ll);
											t_llll *new_sll = hatom_getllll(&new_ll->l_head->l_hatom);
											llll_destroyelem(new_sll->l_head);
											llll_splatter(new_sll->l_owner, LLLL_FREETHING_DONT);
											llll_wrap_once(&new_ll);
											llll_prependsym(new_ll, _llllobj_sym_g, 0, WHITENULL_llll);
											hatom_change_to_llll_and_free(&ech->l_hatom, new_ll);
										}
									}
								}
							}
						}
					}
				}
				llll_free(boxed_extras);
				llll_free(boxed_ties);
				llll_free(boxed_velocities);
				llll_free(boxed_durations);	
				llll_free(boxed_cents);
				llll_free(measures);
                
                llll_prependsym(gathered, _llllobj_sym_score);
				llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, gathered, 0);
			}
			
		} else {
			llll_free(measures); // if measures were empty, we free the duplicate copy (we don't gunload it)
		}
		
		if (need_free_graphic) llll_free(graphic);
		if (need_free_breakpoints) llll_free(breakpoints);
		if (need_free_slots) llll_free(slots);
		if (need_free_articulations) llll_free(articulations);

		// lists which we don't need any more (we don't free the lists who have been put in the gunload_llll!)
		for (i = 1; i < 6; i++) // we don't free measures: they're directly gunloaded  if the there's no "separate" attribute (otherwise they have been freed before)
			llll_free(inlist[i]);
		
		x->n_ob.l_rebuild = 0;
		beatbox_bang(x);
	}
}


void beatbox_assist(t_beatbox *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0)
			sprintf(s, "llll: Measureinfo or bang to Trigger"); // @in 0 @type llll @digest Measureinfo or bang
		else if (a == 1)										// @description Set Measureinfo and trigger the output. A bang outputs the last boxed result.
			sprintf(s, "llll: Pitches or cents");			// @in 1 @type llll @digest Pitches or MIDIcents
		else if (a == 2)						// @description A list of pitches or cents for each voice.
                                                //              The pitches can be assigned chord-wisely (a single element
												//				for each chord) or note-wisely (a plain list for each chord). Thus a 2-depth or 3-depth llll is expected.
			sprintf(s, "llll: Durations");		// @in 2 @type llll @digest Durations
		else if (a == 3)						// @description A plain list of rational durations for each voice (thus a 2-depth llll is expected).
			sprintf(s, "llll: Velocities");		// @in 3 @type llll @digest Velocities
		else if (a == 4)						// @description A list of velocities for each voice. The velocity can be assigned chord-wisely (a single element
												//				for each chord) or note-wisely (a plain list for each chord). Thus a 2-depth or 3-depth llll is expected.
			sprintf(s, "llll: Ties");			// @in 4 @type llll @digest Ties
		else									// @description A list of ties for each voice (1 corresponding to a starting tie, 0 to none).
												//				The ties can be assigned chord-wisely (a single element for each chord) or note-wisely 
												//				(a plain list for each chord). Thus a 2-depth or 3-depth llll is expected.
			sprintf(s, "llll: Extras");			// @in 5 @type llll @digest Extras
												// @description	A list of extras for each voice, assigned note-wisely.
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) {														// @out 0 @type anything @digest Messages for bach.score
			if (x->output_separate)											// @description	Unless the <m>separate</m> attribute is set, this sends
																			//				the score gathered-syntax which construct the boxed score.
																			//				If the <m>separate</m> attribute is set, this sends messages to score (such as "clear"
																			//				if <m>autoclear</m> is active) and a bang to properly build the score from
																			//				the separate parameters
				sprintf(s, "clear if Autoclear Active, bang When Done");
			else
				sprintf(s, "llll (%s): Score in Gathered Syntax", type);
		} else if (a == 1)									// @out 1 @type llll @digest Measureinfo (in <m>separate</m> mode only)
			sprintf(s, "llll (%s): Measureinfo", type);		// @description If the <m>separate</m> attribute is set, the measureinfo is output.
		else if (a == 2)									// @out 2 @type llll @digest Pitches or MIDIcents (in <m>separate</m> mode only)
			sprintf(s, "llll (%s): Pitches or Cents", type);			// @description If the <m>separate</m> attribute is set, the cents are output.
		else if (a == 3)									// @out 3 @type llll @digest Durations (in <m>separate</m> mode only)
			sprintf(s, "llll (%s): Durations", type);		// @description If the <m>separate</m> attribute is set, the durations are output.
		else if (a == 4)									// @out 4 @type llll @digest Velocities (in <m>separate</m> mode only)
			sprintf(s, "llll (%s): Velocities", type);		// @description If the <m>separate</m> attribute is set, the velocities are output.
		else if (a == 5)									// @out 5 @type llll @digest Ties (in <m>separate</m> mode only)
			sprintf(s, "llll (%s): Ties", type);			// @description If the <m>separate</m> attribute is set, the ties are output.
		else												// @out 6 @type llll @digest Extras (in <m>separate</m> mode only)
			sprintf(s, "llll (%s): Extras", type);			// @description If the <m>separate</m> attribute is set, the extras are output.
	}
}

void beatbox_inletinfo(t_beatbox *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void beatbox_free(t_beatbox *x) // we must free cache!!!
{
	long i;
	for (i = 1; i < 6; i++)
		object_free_debug(x->n_proxy[i]);
		
	systhread_mutex_free_debug(x->n_mutex);

	llllobj_obj_free((t_llllobj_object *) x);
}

t_beatbox *beatbox_new(t_symbol *s, short ac, t_atom *av)
{
	t_beatbox *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long true_ac = attr_args_offset(ac, av);

	if ((x = (t_beatbox *) object_alloc_debug(beatbox_class))) {
		// @arg 0 @name separate @optional 1 @type symbol @digest Separate parameters mode  
		// @description Put a "separate" symbol as argument if you want to output the separate parameters (and not the bach.score gathered syntax).
		x->output_separate = true_ac && atom_gettype(av) == A_SYM && atom_getsym(av) == _llllobj_sym_separate;	
		object_attr_setdisabled((t_object *)x, gensym("autoclear"), !x->output_separate); 

		// if outputs are NOT separated, the score is of course always cleared

		x->n_proxy[5] = proxy_new_debug((t_object *) x, 5, &x->n_in);
		x->n_proxy[4] = proxy_new_debug((t_object *) x, 4, &x->n_in);
		x->n_proxy[3] = proxy_new_debug((t_object *) x, 3, &x->n_in);
		x->n_proxy[2] = proxy_new_debug((t_object *) x, 2, &x->n_in);
		x->n_proxy[1] = proxy_new_debug((t_object *) x, 1, &x->n_in);
		
		x->autoclear = true;
		
		attr_args_process(x, ac, av);
		systhread_mutex_new_debug(&x->n_mutex, 0);

  		llllobj_obj_setup((t_llllobj_object *) x, 6, x->output_separate ? "444444a" : "4", NULL);

	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}