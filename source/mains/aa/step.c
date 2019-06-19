/**
 @file
 step.c
 
 @name 
 bach.step
 
 @realname 
 bach.step
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Iterate through lllls, driven by bangs
 
 @description 
 Traverses lllls depth-first, outputting their elements one by one as it receives bangs.
 
 @discussion
 At each step of the iteration, <o>bach.step</o> also report if it has entered or exited a sublist, 
 and the addresses of the elements corresponding to the step.<br />
 Beware: <o>bach.step</o> has a protection mechanism which can cause a bang to get lost in some cases. 
 A lost bang is harmless, but the step it should trigger does not happen, and a warning is displayed in the Max window instead.
 The cases in which a bang may get lost are the following: <br />
 1. bangs coming from the scheduler thread and the main thread are mixed. Some of the incoming bangs, for either thread, might get unpredictably lost.<br />
 2. One of the outlets of <o>bach.step</o> is connected to the first inlet. In this case, every bang triggered by an outlet gets lost.
 
 @category
 bach, bach objects, bach llll

 @keywords
 iterate, iteration, step, manual, traverse, element, address, command

 @seealso
 bach.iter, bach.collect, bach.drip, Iterations
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_strings.h"

typedef struct _step
{
	t_llllobj_object 	n_ob;
	long				n_proxies;
	void				**n_proxy;
	long				n_in;
	
	long				n_maxdepth;
	long				n_scalarmode;
	long				n_recursionmode;
	long				n_iterationmode;
	long				n_spikemode;
	long				n_unwrap;
	long				n_circular;
	
	long				n_lambda;
	long				n_enter;

	t_llll				**n_inlist;
	t_llll_itercache	*n_cache;
	long				n_lists;
	long				n_changed; // 0 = unchanged, 1 = changed, -1 = reset
	long				n_more;
	
	t_systhread_mutex	n_bangmutex; // prevents two bangs to overlap (it's never locked, it's always trylocked)
	t_systhread_mutex	n_storemutex; // prevents the store to be overwritten while being copied
	
} t_step;


void step_assist(t_step *x, void *b, long m, long a, char *s);
void step_inletinfo(t_step *x, void *b, long a, char *t);

t_step *step_new(t_symbol *s, short ac, t_atom *av);
void step_free(t_step *x);

void step_bang(t_step *x);
void step_int(t_step *x, t_atom_long v);
void step_float(t_step *x, double v);
void step_anything(t_step *x, t_symbol *msg, long ac, t_atom *av);

void step_reset(t_step *x);
void step_reset_cache(t_step *x);

long step_shoot_llll(t_step *x, long list, t_llll *ll, char isaddress);
long step_shoot_cmd(t_step *x, long cmd);
long step_shoot_root(t_step *x);
long step_lambda(t_step *x, t_llll *lambda_ll);

t_class *step_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.step", (method)step_new, (method)step_free, (short)sizeof(t_step), 0L, A_GIMME, 0);
	
	// @method llll @digest Iterate through the llll
	// @description
	// All the lllls received in every llll inlet (that is, all except the first and the rightmost one) are iterated in parallel, 
	// element by element, as bangs are received in the left inlet.
	// This means that the first bang outputs the first elements of all the lllls, the second bang outputs the second elements, and so on.
	// Along with each element, its address is output.
	// @copy BACH_DOC_ADDRESS_BASIC
	// Whenever a sublist is met, three scenarios are possible: <br/>
	// In the standard case, a positive integer is output from the rightmost inlet (according to the number of consecutive open parentheses),
	// then the sublist is entered and iterated through. <br/>
	// If the maximum depth has been reached (see the description of the <m>maxdeph</m> attribute),
	// then the sublist is treated as a "normal" element, that is it is output as a whole from the corresponding outlet and not entered.<br/>
	// If the <m>lambda</m> attribute is set to 1, a proposal is output from the rightmost outlet.
	// A proposal is an llll composed as follows: <br/>
	// <m>lambda ( &lt;element 1&gt; ( &lt;address 1 ) &gt; ) ( &lt;element 2&gt; ( &lt;address 2 ) &gt; ) ...</m><br/>
	// where at least one element is a sublist. When this happens, a 0 or 1 return value is expected in the rightmost inlet.
	// If the return value is 1, the behavior falls back to the standard case.
	// If the return value is 0, the sublist is treated as a "normal" element and not entered.
	// It must be remarked that the first proposal output in lambda mode, at the very beginning of the iteration process,
	// is composed by all the whole input lllls, each associated to an empty address. 
	// If a return value of 1 is not subsequently received, no actual iteration takes place. <br/>
	// Whenever a sublist that was entered ends,
	// a negative integer is output from the rightmost inlet (according to the number of consecutive closed parentheses),
	// after which the iteration of the parent llll is resumed where it was left when the sublist was entered.
	// If the input lllls don't have all the same structure, 
	// the details of <o>bach.iter</o>'s behavior are defined by the <m>iterationmode</m>, <m>scalarmode</m> and <m>recursionmode</m> attributes.	
	class_addmethod(c, (method)step_anything,	"anything",		A_GIMME,	0);
	
	// @method reset @digest Reset the iteration
	// @description In left inlet: resets the status of the iteration, so that the next bang will trigger the first elements of the lllls.
	class_addmethod(c, (method)step_reset,		"reset",		0);
	
	class_addmethod(c, (method)step_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)step_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)step_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Make a step
	// @description In first inlet: output one set of elements and move the iteration one step forward.
	// If there are no more elements to iterate to, a bang is output from the rightmost outlet.
	class_addmethod(c, (method)step_bang,		"bang",			0);
	
	class_addmethod(c, (method)step_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)step_inletinfo,	"inletinfo",	A_CANT,		0);
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);

	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_step, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	// @description
	// <m>maxdepth</m> sets the maximum depth level at which the iteration must be performed.
	// If negative, the depth level is counted from the innermost level of each branch of the tree.
	// A value of 0 is treated as a special case where only the whole input lllls are output, 
	// each associated to a <m>null</m> address, and no actual iteration takes place.
	// In this case, the symbol <b>root</b> is output from the rightmost outlet.
	// This can be useful in special situations where a series of iterations are triggered at different maximum depths,
	// in order to emulate recursive behaviors.
	// Defaults to -1, i.e. there is no limitation (stop at the innermost level).

	CLASS_ATTR_LONG(c, "scalarmode",	0,	t_step, n_scalarmode);
	CLASS_ATTR_FILTER_CLIP(c, "scalarmode", 0, 1);
	CLASS_ATTR_STYLE(c, "scalarmode", 0, "onoff");
	CLASS_ATTR_LABEL(c, "scalarmode", 0, "Scalar Mode");
	// @description @copy BACH_DOC_SCALARMODE

	CLASS_ATTR_LONG(c, "recursionmode",	0,	t_step, n_recursionmode);
	CLASS_ATTR_FILTER_CLIP(c, "recursionmode", 0, 1);
	CLASS_ATTR_STYLE(c, "recursionmode", 0, "onoff");
	CLASS_ATTR_LABEL(c, "recursionmode", 0, "Recursion Mode");
	// @description When set to 0 and a sublist and a plain element are met, both are output as they are.
	// When set to 1, the sublist is entered and iterated against the plain element, up to <m>maxdepth</m>.
	
	CLASS_ATTR_LONG(c, "iterationmode",	0,	t_step, n_iterationmode);
	CLASS_ATTR_STYLE_LABEL(c, "iterationmode", 0, "enumindex", "Iteration Mode");
	CLASS_ATTR_FILTER_CLIP(c, "iterationmode", 0, 2);
	CLASS_ATTR_ENUMINDEX(c, "iterationmode", 0, "Shortest Longest Nulls");
	// @description @copy BACH_DOC_ITERATIONMODE

	CLASS_ATTR_LONG(c, "spikemode",	0,	t_step, n_spikemode);
	CLASS_ATTR_FILTER_CLIP(c, "spikemode", 0, 3);
	CLASS_ATTR_STYLE_LABEL(c, "spikemode", 0, "enumindex", "Spike Mode");
	CLASS_ATTR_ENUMINDEX(c, "spikemode", 0, "Distinct Ignore Nulls Separate");
	// @description
	// A spike in an llll is a sequence of parentheses at least two of which are opposite:
	// for instance, <b>[]</b> or <b>[[[]</b> or <b>]][][</b>.
	// The <m>spikemode</m> attribute controls <o>bach.iter</o>'s behavior when a spike is met.
	// When set to 0 (the default), a distinct integer for each sequence of same-direction parentheses 
	// is output from the rightmost outlet:
	// for instance, <b>[]</b> will cause the sequence <m>1</m>, <m>-1</m> to be output;
	// <b>[[[]</b> will cause <m>3</m>, <m>-1</m> to be output;
	// <b>]][][</b> will cause <m>-2</m>, <m>1</m>, <m>-1</m>, <m>1</m> to be output.
	// The sequence of integers from the rightmost outlet is triggered by a single <m>bang</m> in the first inlet.
	// This setting is most useful in conjunction with <o>bach.collect</o>.
	// When the <m>spikemode</m> attribute is set to 1, a single integer is output from the rightmost outlet for the whole spike.
	// The integer represents the depth difference between the last element before the spike and the first element after it.
	// The integers output for the previous examples would then be 0, 2, -1.
	// When the <m>spikemode</m> attribute is set to 2, the values that are output are the same as for <m>spikemode 0</m>.
	// In addition, after each value a set of <b>null</b> addresses and data is output from the llll outlets.
	// When the <m>spikemode</m> attribute is set to 3, a distinct integer for each sequence of same-direction parentheses 
	// is output from the rightmost outlet, but - differently from what happens if the attribute is set to 0 - 
	// in this case each integer is triggered by a separate <m>bang</m> in the first inlet.
	// This is the only case in which a bang does not trigger a value from any of <o>bach.step</o>'s data outlets
	// during an iteration.

	
	CLASS_ATTR_LONG(c, "unwrap",	0,	t_step, n_unwrap);
	CLASS_ATTR_FILTER_CLIP(c, "unwrap", 0, 1);
	CLASS_ATTR_LABEL(c, "unwrap", 0, "Unwrap");
	CLASS_ATTR_STYLE(c, "unwrap", 0, "onoff");
	// @description 
	// When set to 1, every outgoing llll is flattened of its outermost level parentheses.
	
	CLASS_ATTR_LONG(c, "circular",	0,	t_step, n_circular);
	CLASS_ATTR_FILTER_CLIP(c, "circular", 0, 1);
	CLASS_ATTR_LABEL(c, "circular", 0, "Circular");
	CLASS_ATTR_STYLE(c, "circular", 0, "onoff");
	// @description 
	// When set to 1, lllls are iterated in a circular fashion - that is, when the end of all of them is met
	// a new bang restarts from the beginning, rather than outputting a bang from the rightmost outlet.
	
	CLASS_ATTR_LONG(c, "lambda",	0,	t_step, n_lambda);
	CLASS_ATTR_FILTER_CLIP(c, "lambda", 0, 1);
	CLASS_ATTR_LABEL(c, "lambda", 0, "Lambda Mode");
	CLASS_ATTR_STYLE(c, "lambda", 0, "onoff");
	// @description 
	// When set to 1, all sublists as well as the whole input llll are output as proposals, along with their addresses,
	// and a return value is expected to tell whether the sublists (or the whole input llll) should be entered or not. 
	// Please refer to the description of the <m>anything</m> message for more details.
	
	class_register(CLASS_BOX, c);
	step_class = c;
	
	dev_post("bach.step compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void step_bang(t_step *x)
{
	long i, more;
	t_llll_itercache *cache = x->n_cache;
	t_llll **this_inlist;
	
	if (proxy_getinlet((t_object *) x)) {
		step_anything(x, _sym_bang, 0, NULL);
		return;
	}
    
    more = x->n_more;
	if (!more && !x->n_changed) {
		if (x->n_circular) {
			step_reset(x);
		} else {
			llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1);
			return;
		}
	}
	
	if (systhread_mutex_trylock(x->n_bangmutex)) {
		object_warn((t_object *) x, "Lost bang");
		return;
	}

	systhread_mutex_lock(x->n_storemutex);

	if (x->n_changed != 0) {
		if (x->n_cache->i_active)
			step_reset_cache(x);

		if (x->n_changed == 1 || more == 0) {
			if (x->n_inlist[0])	// if it's not empty
				for (i = 0; i < x->n_lists; i++)
					llll_release(x->n_inlist[i]);
			for (i = 0, this_inlist = x->n_inlist; i < x->n_lists; i++, this_inlist++)
				*this_inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, i, 0);
		}
		x->n_changed = 0;
		more = 1;
	}
	
	systhread_mutex_unlock(x->n_storemutex);
	
	more = llll_iter(x->n_lists, x->n_inlist, x->n_maxdepth,
						  x->n_scalarmode, x->n_recursionmode, x->n_iterationmode, x->n_spikemode, x->n_unwrap, cache,
						  (iter_datafn) step_shoot_llll, x, (iter_datafn) step_shoot_llll, x, (iter_cmdfn) step_shoot_cmd, x, 
						  (iter_rootfn) step_shoot_root, x, x->n_lambda ? (iter_lambdafn) step_lambda : NULL, x);
    
	systhread_mutex_unlock(x->n_bangmutex);
    
    if (more == -1) {
        llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1);
        more = 0;
    }
    
    x->n_more = more;
}

void step_int(t_step *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	step_anything(x, _sym_int, 1, &outatom);
}

void step_float(t_step *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	step_anything(x, _sym_float, 1, &outatom);
}

void step_anything(t_step *x, t_symbol *msg, long ac, t_atom *av)
{
//	long i;
	long inlet = proxy_getinlet((t_object *) x);
//	t_llll_itercache *cache = x->n_cache;
	if (inlet == 0) {
		object_error((t_object *) x, "Invalid message %s", msg->s_name);
		return;
	}
	if (inlet < x->n_proxies) {
		systhread_mutex_lock(x->n_storemutex);
		if (!llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet - 1)) {
			systhread_mutex_unlock(x->n_storemutex);
			return;
		}
		x->n_changed = 1;
		systhread_mutex_unlock(x->n_storemutex);
	} else if (msg == _sym_reset) {
		step_reset(x);
		return;
	} else if (msg == _llllobj_sym_bach_llll) {
		t_llll *in_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN);
		if (in_ll && in_ll->l_size)
			x->n_enter = hatom_getlong(&in_ll->l_head->l_hatom);
		llll_free(in_ll);
		return;
	} else if (ac) {
		x->n_enter = atom_getlong(av);
		return;
	}	
}

void step_reset(t_step *x)
{
	systhread_mutex_lock(x->n_storemutex);
	if (!x->n_changed)
		x->n_changed = -1;
	systhread_mutex_unlock(x->n_storemutex);
}

long step_shoot_llll(t_step *x, long list, t_llll *ll, char isaddress)
{
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, list * 2 + isaddress, ll);
	return 0;
}

long step_shoot_cmd(t_step *x, long cmd)
{
	llllobj_outlet_int((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1, cmd);
	return 0;
}

long step_shoot_root(t_step *x)
{
	llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1, gensym("root"), 0, NULL);
	return 0;
}

long step_lambda(t_step *x, t_llll *lambda_ll)
{
	x->n_enter = 0;
	llll_prependsym(lambda_ll, gensym("lambda"), 0, WHITENULL_llll);
	llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_ob.l_numouts - 1, lambda_ll);
	return x->n_enter != 0;
}

void step_assist(t_step *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0)
			sprintf(s, "bang: Next Step / reset"); // @in 0 @type bang/reset @digest Advance one step/reset the iteration
		else if (a < x->n_proxies)
			sprintf(s, "llll %ld", a); // @in 1 @loop 1 @type llll @digest llll to be iterated
		else	// @in 2 @type int @digest lambda inlet
				// @description An integer (1 or 0) received as the response to a proposal from the lambda outlet
				// causes the proposed sublists (or the whole lllls) to be entered and iterated through or not.
			sprintf(s, "int: Lambda Inlet");
			

	} else {
		if (a == x->n_lists * 2)
			sprintf(s, "int/root: Depth Delta / bang: Finished / Lambda Outlet"); // @out 2 @type int/root/bang/llll @digest Depth Delta / Finished / Lambda Outlet
		// @description The difference between the depth of the previous and current elements, 
		// or the <m>root</m> symbol if the <m>maxdepth</m> attribute is set to 0.
		// This value can be fed into <o>bach.collect</o>'s rightmost inlet.
		// If there are no more elements to iterate upon, a bang is output unless the <m>circular</m> attribute is set.
		// If the <m>lambda</m> attribute is set, proposals are output from the rightmost outlet whenever one or more sublists are met,
		// as well as the very beginning of the iteration, and a return value is expected in the rightmost inlet
		// telling whether the proposed sublists (or the whole lllls) should be entered or not.
		// Please refer to the description of the <m>anything</m> message for more details.
		else {
			char *type = NULL;
			llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
			switch (a % 2) {
				case 0: sprintf(s, "llll %ld (%s): Data", a / 2 + 1, type);		break; // @out 0 @loop 1 @type llll @digest Current element
				case 1: sprintf(s, "llll %ld (%s): Address", a / 2 + 1, type);	break; // @out 1 @loop 2 @type llll @digest Current element's address
					// @description @copy BACH_DOC_ADDRESS_BASIC
			}
		}
	}
}

void step_inletinfo(t_step *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void step_reset_cache(t_step *x)
{
	long i;
	t_llll_itercache *cache = x->n_cache;
	t_llll **this_address = cache->i_address;
	t_llll **inlist, **this_inlist;
	long lastlist = x->n_lists - 1;
	long *temporaries = cache->i_temporaries, *this_temporaries;
	
	cache->i_active = 0;

	// first, get the last level and destroy the temporaries
	inlist = (t_llll **) cache->i_inlist_stack->s_current;

	for (this_temporaries = temporaries + lastlist, this_inlist = inlist + lastlist; this_temporaries >= temporaries; this_temporaries--, inlist--) {
		if (*this_temporaries)
			llll_free(*this_inlist);
	}
	
	// free the temporary lllls and the stuff in the stacks
	while (cache->i_inlist_stack->s_items > 1) { // no temporary llll can exist at the base of the stack
		this_inlist = inlist = (t_llll **) llll_stack_pop(cache->i_inlist_stack); // the first level of inlist is x->n_inlist, so we don't free it now
		bach_freeptr(inlist);
		bach_freeptr(llll_stack_pop(cache->i_elem_stack));
	}
	
	bach_freeptr(llll_stack_pop(cache->i_elem_stack)); // this one must be freed

	// free the address lllls
	for (i = 0; i < x->n_lists; i++)
		llll_free(*this_address++);
	
	bach_freeptr(cache->i_address);
	bach_freeptr(cache->i_len);
	bach_freeptr(temporaries);
	llll_stack_destroy(cache->i_elem_stack);
	llll_stack_destroy(cache->i_inlist_stack);
	llll_stack_destroy(cache->i_steps_stack);
}

void step_free(t_step *x) // we must free cache!!!
{
	long i;
	if (x->n_cache->i_active)
		step_reset_cache(x);
	if (x->n_inlist[0])	// if it's not empty
		for (i = 0; i < x->n_lists; i++)
			llll_release(x->n_inlist[i]);
	bach_freeptr(x->n_inlist);
	bach_freeptr(x->n_cache);
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	bach_freeptr(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
	systhread_mutex_free_debug(x->n_bangmutex);
	systhread_mutex_free_debug(x->n_storemutex);
}

t_step *step_new(t_symbol *s, short ac, t_atom *av)
{
	t_step *x = NULL;
	long i, proxies = 0;
	long true_ac;
	t_max_err err = MAX_ERR_NONE;
	char outlets[LLLL_MAX_OUTLETS];
	
	true_ac = attr_args_offset(ac, av);
	
	if ((x = (t_step *) object_alloc_debug(step_class))) {
		// @arg 0 @name count @optional 1 @type int @digest Number of parallel lllls
		// @description The number of lllls to be iterated in parallel.
		// Inlets and outlets are created accordingly.
		
  		proxies = x->n_lists = (true_ac && atom_gettype(av) == A_LONG) ? atom_getlong(av) : 1; // one for each list (plus one standard input for ctl inlet)

		strncpy_zero(outlets, "444", LLLL_MAX_OUTLETS);
		for (i = 1; i < x->n_lists; i++)
			strncat_zero(outlets, "44", LLLL_MAX_OUTLETS);
		x->n_maxdepth = -1;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, x->n_lists, outlets, NULL);
		x->n_proxies = MIN(proxies + 1, LLLL_MAX_INLETS);

		x->n_proxy = (void **) bach_newptr((x->n_proxies + 1) * sizeof (void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		
		x->n_cache = (t_llll_itercache *) bach_newptrclear(sizeof(t_llll_itercache));
		x->n_inlist = (t_llll **) bach_newptrclear(x->n_lists * sizeof(t_llll *));
		x->n_changed = 1;
		x->n_more = 1;

		systhread_mutex_new_debug(&x->n_bangmutex, 0);
		systhread_mutex_new_debug(&x->n_storemutex, 0);
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
