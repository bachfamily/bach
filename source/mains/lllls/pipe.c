/*
 *  pipe.c
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

/**
 @file
 pipe.c
 
 @name 
 bach.pipe
 
 @realname 
 bach.pipe
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Delay lllls.
 
 @description
 Delays one or more lllls by a specified amount of time.
 
 @discussion
 If the lllls come in the main thread, they are moved to the scheduler thread.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 delay, pipe

 @seealso
 bach.defer, bach.deferlow, pipe, delay
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_maxtypes.h"
#include "ext_atomic.h"

typedef struct _pipe
{
	struct llllobj_object 	n_ob;
	
	t_int32_atomic			n_id;
	long					n_proxies;	
	void					**n_proxy;
	long					n_in;
	double					n_time;
} t_pipe;

typedef struct _pipedata
{
	t_pipe			*p_pipe;
	t_clock			*p_clock;
	t_int32_atomic	p_id;
	long			p_ac;
	t_llll			*p_lllls[LLLL_MAX_INLETS];
} t_pipedata;

void pipe_assist(t_pipe *x, void *b, long m, long a, char *s);

t_pipe *pipe_new(t_symbol *s, short ac, t_atom *av);
void pipe_free(t_pipe *x);

void pipe_bang(t_pipe *x);
void pipe_int(t_pipe *x, t_atom_long v);
void pipe_float(t_pipe *x, double v);
void pipe_anything(t_pipe *x, t_symbol *msg, long ac, t_atom *av);
void pipe_dobang(t_pipedata *pipedata);

t_int32_atomic pipe_counter;
t_class *pipe_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.pipe", (method)pipe_new, (method)pipe_free, (long) sizeof(t_pipe), 0L, A_GIMME, 0);
	
	// @method llll @digest llll to delay
	// @description An llll received in any inlet except the rightmost is delayed by an amount of time 
	// set by the object's argument, or through the rightmost inlet.
	// lllls received in inlets other than the first are not immediately delayed.
	// The delay action is triggered by an llll or a bang received in the first inlet.
	// The various input lllls will be output virtually at once.
	// Several lllls received in the left inlet one after another will be delayed each with respect to its time of reception,
	// and the delay time for each can be set independently.
	class_addmethod(c, (method)pipe_anything,	"anything",		A_GIMME,	0);
	
	// @method int @digest Converted to float
	class_addmethod(c, (method)pipe_int,		"int",			A_LONG,		0);
	
	// @method float @digest Delay time
	// @description The delay time for the next incoming lllls, expressed in ms.
	class_addmethod(c, (method)pipe_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)pipe_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Trigger delay
	// A bang in the first inlet triggers the delay of the llll most recently received in each inlet. 
	class_addmethod(c, (method)pipe_bang,		"bang",			0);
	class_addmethod(c, (method)pipe_assist,		"assist",		A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	class_register(CLASS_BOX, c);
	pipe_class = c;
	pipe_counter = 0;
	
	dev_post("bach.pipe compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void pipe_bang(t_pipe *x)
{	
	long i;
	t_llll **this_lllls;
	t_pipedata *pipedata = (t_pipedata *) bach_newptr(sizeof(t_pipedata)); 
	long lists = pipedata->p_ac = x->n_proxies;
	pipedata->p_clock = (t_clock *) clock_new_debug(pipedata, (method) pipe_dobang);
	pipedata->p_id = x->n_id;
	pipedata->p_pipe = x;
	this_lllls = pipedata->p_lllls;
	for (i = 0; i < lists; i++, this_lllls++) {
		*this_lllls = llllobj_get_retained_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i);
//		object_post((t_object *) x, "scheduling list %p", *this_lllls);
	}
	clock_fdelay(pipedata->p_clock, x->n_time);
}

void pipe_dobang(t_pipedata *pipedata)
{
	t_pipe *x = pipedata->p_pipe;
	long ac = pipedata->p_ac;
	t_llll **this_lllls;
//	post("dobang: scheduled x = %p; ac = %ld", x, ac);
	if (NOGOOD(x) || object_class(x) != pipe_class || pipedata->p_id != x->n_id) {
		this_lllls = pipedata->p_lllls + ac - 1; 
		while (ac--) {
			llll_release(*this_lllls);
			this_lllls--;
		}		
	} else {
		this_lllls = pipedata->p_lllls + ac - 1; 
		while (ac--) {
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, ac, *this_lllls);
			llll_release(*this_lllls);
			this_lllls--;
		}
	}
	object_free_debug(pipedata->p_clock);
	bach_freeptr(pipedata);
}

void pipe_int(t_pipe *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	pipe_anything(x, _sym_int, 1, &outatom);
}

void pipe_float(t_pipe *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	pipe_anything(x, _sym_float, 1, &outatom);
}

void pipe_anything(t_pipe *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);

	if (ac && inlet == x->n_proxies) {
		if (msg == _sym_int || msg == _sym_float)
			x->n_time = atom_getfloat(av);
		else if (msg == _llllobj_sym_bach_llll) {
			t_llll *time_llll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
			if (!time_llll || time_llll->l_size == 0 || time_llll->l_size > 1 ||
                !hatom_is_number(&time_llll->l_head->l_hatom)) {
				object_error((t_object *) x, "Bad time");
			} else {
				x->n_time = hatom_getdouble(&time_llll->l_head->l_hatom);
			}
			llll_release(time_llll);
		} else
			object_error((t_object *) x, "Bad time");
	}

	else if (llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet) == NULL)
		return;

	if (inlet == 0)
		pipe_bang(x);
}

void pipe_assist(t_pipe *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == x->n_proxies)
			sprintf(s, "float/llll: Time"); // @in 1 @type float/llll @digest Delay time
		else
			sprintf(s, "llll %ld", a + 1); // @in 0 @loop 1 @type llll @digest llll to delay
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll %ld (%s)", a + 1, type); // @out 0 @loop 1 @type llll @digest Delayed llll
	}
}

void pipe_free(t_pipe *x)
{
	long i;
//	object_post((t_object *) x, "freeing %p", x);
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	bach_freeptr(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_pipe *pipe_new(t_symbol *s, short ac, t_atom *av)
{
	t_pipe *x = NULL;
	long i, proxies = 0;
	long true_ac;
	char outlets[LLLL_MAX_OUTLETS], *this_outlets;
	t_max_err err = MAX_ERR_NONE;

	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_pipe *) object_alloc_debug(pipe_class))) {
		// @arg 0 @name parameters @optional 1 @type list @digest Parameters
		// @description If one argument is present, it is considered the delay time.<br />
		// If two arguments are presents, the first is considered the number of inlets and llll outlets, the second the delay time.
		x->n_id = ATOMIC_INCREMENT(&pipe_counter);

		x->n_time = true_ac ? atom_getfloat(av + true_ac - 1) : 0;
		proxies = (true_ac > 1 && atom_gettype(av) == A_LONG) ? atom_getlong(av) + 1 : 2; // one for each list, plus one for time
		x->n_proxies = CLAMP(proxies, 1, LLLL_MAX_INLETS) - 1;
		
		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof(void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		
		attr_args_process(x, ac, av);
		this_outlets = outlets;
		for (i = x->n_proxies; i > 0; i--, this_outlets++)
			*this_outlets = '4';
		*this_outlets = 0;
		llllobj_obj_setup((t_llllobj_object *) x, x->n_proxies + 1, outlets);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
//	object_post((t_object *) x, "x = %p, id = %ld", x, x->n_id);

    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
