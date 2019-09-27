/*
 *  collect.c
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
 collect.c
 
 @name 
 bach.collect
 
 @realname 
 bach.collect
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Collect elements into lllls
 
 @description
 Groups together data it receives, 
 and outputs them as lllls upon reception of an output command in the leftmost inlet.
 The structure of the resulting lllls can be controlled through messages in the right inlet.
 
 @discussion
 More lllls can be built in parallel through the use of the <m>collection</m> messages, 
 and/or by providing an optional argument to <o>bach.collect</o>.

 @category
 bach, bach objects, bach llll
 
 @keywords
 collect, gather, iteration, rebuild, element, address, command

 @seealso
 bach.iter, bach.step, bach.join, bach.drip, bach.mapelem, Iterations
 
 @owner
 Andrea Agostini
 */

#define C_MAX_COLLECTORS 16

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "foundation/collector.h"

typedef struct _collect
{
	struct llllobj_object 	n_ob;

	long				n_mode;
	long				n_proxies;

	void				**n_proxy;
	long				n_in;

	long				n_ncollectors;
	t_collector			**n_collector;
	long				n_nullmode;
	long				n_autoclear;
	long				n_inwrap;
	long				n_outwrap;
	long				n_size;
	long				n_autosize;
	long				n_bipolar;
} t_collect;


void collect_assist(t_collect *x, void *b, long m, long a, char *s);
void collect_inletinfo(t_collect *x, void *b, long a, char *t);

t_collect *collect_new(t_symbol *s, short ac, t_atom *av);
void collect_free(t_collect *x);

void collect_bang(t_collect *x);
void collect_int(t_collect *x, t_atom_long v);
void collect_float(t_collect *x, double v);
void collect_anything(t_collect *x, t_symbol *msg, long ac, t_atom *av);

t_class *collect_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.collect", (method)collect_new, (method)collect_free, (short)sizeof(t_collect), 0L, A_GIMME, 0);
	
	// @method llll @digest Append the llll
	// @description An llll in every inlet except the leftmost and rightmost is appended to the corresponding llll being built by <o>bach.collect</o>.
	class_addmethod(c, (method)collect_anything,	"anything",		A_GIMME,	0);
	
	// @method int @digest Function depends on inlet
	// @description
	// 0 in the first inlet will cause all the active collections to be output and optionally erased (according to the <m>autoclear</m> attribute). 
	// This is equivalent to a <m>bang</m>.<br />
	// A positive int in the leftmost inlet causes the corresponding number of levels of the destination lllls to be output, counting from the working level.
	// For instance, 1 outputs the working level; 2 outputs the working level's parent llll (the working level is output as a sublist). <br />
	// A negative int in the leftmost inlet will cause the destination llll minus the first -n levels (counting from the top level) to be output. 
	// For instance, -1 outputs the ancestor of the working level that is one level deeper than the root level. <br />
	
	// A positive int in the rightmost inlet (a "command") will cause the corresponding number of sublists to be opened in the llll being built.
	// All the elements received in the llll inlets from this time on will be added to the newly opened sublists.
	// This corresponds to opening one or more parentheses when typing an llll. <br />
	// A negative int will cause the corresponding numbeer of sublist (as long as they had been opened before) to be closed.
	// This corresponds to closing one or more parentheses when typing an llll. <br />
	// 0 has no effect.

	class_addmethod(c, (method)collect_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)collect_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)collect_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the active collections
	// @description A bang in the first inlet will cause the active collection for each inlet to be output and optionally erased (according to the <m>autoclear</m> attribute).
	// This is the same as <m>0</m>.
	class_addmethod(c, (method)collect_bang,		"bang",			0);

	// @method collection @digest Change collection
	// @description
	// The message <m>collection</m>, followed by a positive integer, when received in the rightmost inlet sets the currently active collection for each inlet
	// Collections are independent destination lllls:
	// each inlet works on its own set of collections but the index number of the active collection is always the same for each inlet.
	// At any time, the active collections can be changed and every subsequent command will be solely referred to them.
	// If the <m>autosize</m> attribute is set to 0 and a non-existing collection is requested, 
	// all the following data and commands will be ignored.
	// By default, the active collection is number 1.
	// @marg 0 @name active_collection @optional 0 @type int
	class_addmethod(c, (method)collect_anything,	"collection",	A_GIMME,	0);
	
	// @method size @digest Set the number of collections
	// @description
	// The message <m>size</m>, followed by a positive integer, when received in the rightmost inlet sets the number of allowed collections for each inlet.
	// Raising it doesn't alter the collected data; lowering it erases the data from the discarded collections.
	// Usually it is more convenient letting <o>bach.collect</o> manage the number of collections through the <m>autosize</m> attribute (active by default).
	// @marg 0 @name size @optional 0 @type int
	class_addmethod(c, (method)collect_anything,	"size",			A_GIMME,	0);

	// @method top @digest Close all the open sublists
	// @description
	// The message <m>top</m> in the rightmost inlet closes all the open sublists and makes the root level of the current active lllls the new working position.
	class_addmethod(c, (method)collect_anything,	"top",			A_GIMME,	0);
	
	// @method back @digest Erase last element
	// @description
	// The message <m>back</m> in the rightmost inlet erases the last element of the working level of the destination lllls.
	class_addmethod(c, (method)collect_anything,	"back",			A_GIMME,	0);
	
	// @method clear @digest Clear the active collections
	// @description
	// The message <m>clear</m> in the rightmost inlet clears the active collection for every inlet.
	class_addmethod(c, (method)collect_anything,	"clear",		A_GIMME,	0);
	
	// @method clearall @digest Clear all the collections
	// @description
	// The message <m>clearall</m> in the rightmost inlet clears all the collections for every inlet.
	class_addmethod(c, (method)collect_anything,	"clearall",		A_GIMME,	0);
	
	// @method all @digest Output all the collections
	// @description
	// The message <m>all</m> in the first inlet outputs all the collections of each inlet as a single llll, 
	// each collection being assigned to a sublist.
	// An optional non-zero argument will prevent empty collections from being included in the output llll.
	// @marg 0 @name exclude_empty_collections @optional 1 @type int
	class_addmethod(c, (method)collect_anything,	"all",			A_GIMME,	0);

	class_addmethod(c, (method)collect_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)collect_inletinfo,	"inletinfo",	A_CANT,		0);
	
	CLASS_ATTR_LONG(c, "nullmode",	0,	t_collect, n_nullmode);
	CLASS_ATTR_FILTER_CLIP(c, "nullmode", 0, 1);
	CLASS_ATTR_STYLE(c, "nullmode", 0, "onoff");
	CLASS_ATTR_LABEL(c, "nullmode", 0, "Null Mode");	
	// @description When set to 1, a <b>null</b> received in one of the llll inlets will result in an empty sublist being added to the collection.
	
	CLASS_ATTR_LONG(c, "autoclear",	0,	t_collect, n_autoclear);
	CLASS_ATTR_FILTER_CLIP(c, "autoclear", 0, 1);
	CLASS_ATTR_STYLE(c, "autoclear", 0, "onoff");
	CLASS_ATTR_LABEL(c, "autoclear", 0, "Auto Clear");	
	CLASS_ATTR_BASIC(c, "autoclear", 0);
	// @description When set to 1 (default), a <m>bang</m> or <m>0</m> in the left inlet will also clear the active collections, 
	// and a <m>all</m> message will clear all the collections.

	CLASS_ATTR_LONG(c, "autosize",	0,	t_collect, n_autosize);
	CLASS_ATTR_FILTER_CLIP(c, "autosize", 0, 1);
	CLASS_ATTR_STYLE(c, "autosize", 0, "onoff");
	CLASS_ATTR_LABEL(c, "autosize", 0, "Set Size Automatically");	
	CLASS_ATTR_BASIC(c, "autosize", 0);
	// @description When set to 1 (default), the number of allowed collections is automatically raised as soon as a non-existing collection is requested.
	// When a <m>clearall</m> message is received, the number of allowed collections is set to 1.
	
	CLASS_ATTR_LONG(c, "bipolar",	0,	t_collect, n_bipolar);
	CLASS_ATTR_FILTER_CLIP(c, "bipolar", 0, 1);
	CLASS_ATTR_STYLE(c, "bipolar", 0, "onoff");
	CLASS_ATTR_LABEL(c, "bipolar", 0, "Bipolar");	
	CLASS_ATTR_BASIC(c, "bipolar", 0);
	// @description When set to 1 (default), a <m>bang</m> or <m>0</m> in the left inlet will also clear the active collections, 
	// and a <m>all</m> message will clear all the collections.
	
	CLASS_ATTR_LONG(c, "inwrap",	0,	t_collect, n_inwrap);
	CLASS_ATTR_FILTER_MIN(c, "inwrap", 0);
	CLASS_ATTR_LABEL(c, "inwrap", 0, "Wrap Input");
	// @description @copy BACH_DOC_INWRAP
	
	CLASS_ATTR_LONG(c, "outwrap",	0,	t_collect, n_outwrap);
	CLASS_ATTR_FILTER_MIN(c, "outwrap", 0);
	CLASS_ATTR_LABEL(c, "outwrap", 0, "Wrap Output");
	// @description @copy BACH_DOC_OUTWRAP
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	class_register(CLASS_BOX, c);
	collect_class = c;
	
	dev_post("bach.collect compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void collect_bang(t_collect *x)
{	
	long r = x->n_ob.l_rebuild;
	long i;
	if (r || proxy_getinlet((t_object *) x) != 0) {
		collect_anything(x, _sym_bang, 0, NULL);
	} else {
		for (i = x->n_ncollectors - 1; i >= 0; i--)
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
	}
}

void collect_int(t_collect *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	collect_anything(x, _sym_int, 1, &outatom);
}

void collect_float(t_collect *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	collect_anything(x, _sym_float, 1, &outatom);
}

void collect_anything(t_collect *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *in_llll;
	long arg, i;
	long inlet = proxy_getinlet((t_object *) x);
	if (inlet == 0) {
		if (msg == _sym_bang || msg == _sym_int) {
			arg = ac ? atom_getlong(av) : 0;
			for (i = x->n_ncollectors - 1; i >= 0; i--) {
				llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, 
									 collector_output(x->n_collector[i], arg, x->n_outwrap), i);
			}
			x->n_ob.l_rebuild = 0;
			if (arg == 0 && x->n_autoclear) {
				for (i = x->n_ncollectors - 1; i >= 0; i--)
					collector_clear(x->n_collector[i]);
			}
			for (i = x->n_ncollectors - 1; i >= 0; i--)
				llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
			if (arg == 0 && x->n_autoclear)
				x->n_ob.l_rebuild = 1;
		} else if (msg == _sym_all) {
			arg = ac ? atom_getlong(av) : 0;
			for (i = x->n_ncollectors - 1; i >= 0; i--) {
				llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, 
									 collector_outputall(x->n_collector[i], arg, x->n_outwrap), i);
			}
			x->n_ob.l_rebuild = 0;
			if (x->n_autoclear) {
				for (i = x->n_ncollectors - 1; i >= 0; i--)
					collector_clearall(x->n_collector[i]);
			}
			for (i = x->n_ncollectors - 1; i >= 0; i--)
				llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, i);
			if (arg == 0 && x->n_autoclear)
				x->n_ob.l_rebuild = 1;
		} else			
			object_error((t_object *) x, "Invalid message %s", msg->s_name);
	} else if (inlet == x->n_proxies) {
		if ((msg == _sym_int || msg == _sym_float) && ac) {
			long lvls = atom_getlong(av);
			for (i = x->n_ncollectors - 1; i >= 0; i--)
				collector_change_level(x->n_collector[i], lvls);
			x->n_ob.l_rebuild = 1;
		} else if (msg == gensym("root")) { 
			for (i = x->n_ncollectors - 1; i >= 0; i--) {
				collector_set_root(x->n_collector[i]);
			}
		} else if (msg == _sym_size) {
			if (ac) {
				long size = atom_getlong(av);
				for (i = x->n_ncollectors - 1; i >= 0; i--)
					collector_size(x->n_collector[i], size);
				x->n_size = size;
			} else
				object_error((t_object *) x, "Insufficient arguments for message size");
			x->n_ob.l_rebuild = 1;
		} else if (msg == gensym("collection")) {
			if (ac) {
				long coll = atom_getlong(av) - 1;
				if (x->n_autosize && x->n_size <= coll) {
					long size = coll + 1;
					for (i = x->n_ncollectors - 1; i >= 0; i--)
						collector_size(x->n_collector[i], size);
					x->n_size = size;
				}
				for (i = x->n_ncollectors - 1; i >= 0; i--)
					collector_change_collection(x->n_collector[i], coll);
			} else
				object_error((t_object *) x, "Insufficient arguments for message collection");
			x->n_ob.l_rebuild = 1;
		} else if (msg == gensym("top")) {
			for (i = x->n_ncollectors - 1; i >= 0; i--)
				collector_top(x->n_collector[i]);
			x->n_ob.l_rebuild = 1;
		} else if (msg == _sym_back) {
			for (i = x->n_ncollectors - 1; i >= 0; i--)
				collector_back(x->n_collector[i]);
			x->n_ob.l_rebuild = 1;
		} else if (msg == _sym_clear) {
			for (i = x->n_ncollectors - 1; i >= 0; i--)
				collector_clear(x->n_collector[i]);
			x->n_ob.l_rebuild = 1;
		} else if (msg == gensym("clearall")) {
			for (i = x->n_ncollectors - 1; i >= 0; i--)
				collector_clearall(x->n_collector[i]);
			if (x->n_autosize) {
				for (i = x->n_ncollectors - 1; i >= 0; i--)
					collector_size(x->n_collector[i], 1);
				x->n_size = 1;
			}
			x->n_ob.l_rebuild = 1;
		} else if (msg != gensym("lambda")) {
			object_error((t_object *) x, "Unknown message %s", msg->s_name);
			x->n_ob.l_rebuild = 0;
		}
	} else {
		in_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);
		if (in_llll) {
			long inwrap = x->n_inwrap;
			while (inwrap--) {
				t_llll *wrapped = llll_get();
				llll_appendllll(wrapped, in_llll, 0, WHITENULL_llll);
				in_llll = wrapped;
			}
			collector_get(x->n_collector[inlet - 1], in_llll, x->n_nullmode, x->n_bipolar);
			x->n_ob.l_rebuild = 1;
		}
	}
}

void collect_assist(t_collect *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0)
			sprintf(s, "bang / int / all: Output"); // @in 0 @type bang/int/all @digest Output the collected lllls
		else if (a == x->n_proxies)
			sprintf(s, "Command Inlet"); // @in 2 @type int/anything @digest Navigate, clear and manage the collection structure 
		else
			sprintf(s, "llll %ld to Collect", a); // @in 1 @loop 1 @type llll @digest Data to collect
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s) %ld", type, a + 1); // @out 0 @loop 1 @type llll @digest Collected data
	}
}

void collect_inletinfo(t_collect *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void collect_free(t_collect *x)
{
	long i;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	for (i = x->n_ncollectors - 1; i >= 0; i--)
		collector_free(x->n_collector[i]);
	bach_freeptr(x->n_proxy);
	bach_freeptr(x->n_collector);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_collect *collect_new(t_symbol *s, short ac, t_atom *av)
{
	t_collect *x = NULL;
	long i;
	long true_ac;
	t_max_err err = 0;
	char outtypes[C_MAX_COLLECTORS + 1];
	
	true_ac = attr_args_offset(ac, av);

	if ((x = (t_collect *) object_alloc_debug(collect_class))) {
		// @arg 0 @name collectors @optional 1 @type int 
		// @digest Number of collectors (outlets and llll inlets)
		// @description A collector is an inlet/outlet couple, not unlike a distinct <o>bach.collect</o> object, with the exception that 
		// all the collectors of a single object have the same attributes, and receive the same navigation and output commands. 
		
		if (true_ac >= 1)
			x->n_ncollectors = atom_getlong(av);
		if (true_ac >= 2)
			x->n_nullmode = atom_getlong(av + 1);
		x->n_ncollectors = CLAMP(x->n_ncollectors, 1, C_MAX_COLLECTORS);
		x->n_collector = (t_collector **) bach_newptr(x->n_ncollectors * sizeof(t_collector *));
		for (i = 0; i < x->n_ncollectors; i++) {
			x->n_collector[i] = collector_new(1, 1);
			outtypes[i] = '4';
		}
		outtypes[i] = 0;
		
		x->n_proxies = 1 + x->n_ncollectors;
	
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		
		x->n_autoclear = 1;
		x->n_autosize = 1;
		x->n_size = 1;
		
		attr_args_process(x, ac, av);

		llllobj_obj_setup((t_llllobj_object *) x, 0, outtypes);

	} else
		error(BACH_CANT_INSTANTIATE);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}
