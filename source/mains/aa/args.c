/**
 @file
 args.c
 
 @name 
 bach.args
 
 @realname 
 bach.args
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Manage subpatcher arguments
 
 @description
 Parses and retrieves the subpatcher's "normal" and attribute-style arguments. 
 <o>bach.args</o> should be used in every subpatch or abstraction accepting arguments, 
 and all the patcher's inlets should be connected to it.
 
 @discussion
 The basic behavior of <m>bach.args</m> is similar to <m>patcherargs</m>'s, 
 with improved support for correct synchronization and order preservation of messages and arguments.
 Everytime the subpatch is loaded, all its arguments and attribute-style arguments are parsed and output, or substituted by specified defaults.
 If a patch containing nested subpatches or abstractions each with its own instance of <m>bach.args</m> is loaded,
 the various instances of <o>bach.args</o> will output their arguments in order of depth:
 that is, the deepest instances will output first, the less deep ones last.
 The output order of different <o>bach.args</o> objects at the same depth is undefined.
 <o>bach.args</o> also has a communication mechanism with <o>bach.portal</o>,
 assuring that each subpatcher's <o>bach.portal</o> is ready when the <o>bach.args</o> object in the same subpatch outputs its arguments.
 In this way, it is safe for the arguments of the patch to trigger messages to the outside of the patch itself.
 
 @category
 bach, bach objects, bach llll
 
 @keywords
 subpatcher, abstraction, argument, attribute, synchronize, manage

 @seealso
 bach.portal, patcherargs, Abstract Thinking
 
 @owner
 Andrea Agostini
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "ext_maxtypes.h"
#include "ext_linklist.h"
#include "ext_systhread.h"
#include "ext_dictionary.h"
#include "jpatcher_api.h"

#define MAX_ATTRS 256

typedef struct _args
{
	t_llllobj_object 	n_ob;
	long				n_proxies;
	long				n_ins;
	void				**n_proxy;
	long				n_in;
	long				n_nullmode;
	long				n_backtick;
	long				n_mode;
	long				n_done;
	t_symbol			*n_attrs[MAX_ATTRS];
	long				n_numattrs;
	long				n_outout;
	long				n_ready;
	long				n_boxac;
	long				n_processed;
	t_atom				*n_boxav;
	t_systhread_mutex	n_mutex;
	long				n_itsme;
	long				n_retrying;
	long				n_clone;
    t_object            *n_patcher;
} t_args;

void args_assist(t_args *x, void *b, long m, long a, char *s);

t_args *args_new(t_symbol *s, short ac, t_atom *av);
void args_free(t_args *x);

void args_bang(t_args *x);
void args_loadbang(t_args *x);
void args_int(t_args *x, t_atom_long v);
void args_float(t_args *x, double v);
void args_anything(t_args *x, t_symbol *msg, long ac, t_atom *av);

void args_dopargs(t_args *x, t_symbol *msg, long argc, t_atom *argv);

t_class *args_class;
t_class *cachedmess_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(BACH_LLLL_VERSION) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.args", (method)args_new, (method)args_free, (short)sizeof(t_args), 0L, A_GIMME, 0);
	
	// @method llll @digest lllls to the patch
	// @description
	// An llll received in any inlet except the rightmost one
	// (that is, any additional inlet specified through the <m>ins</m> attribute)
	// will be output unchanged from the corresponding outlet, unless before loadbang time - 
	// in which case the llll will not be output.
	// If the <m>ins</m> attribute is not present or it is set to 0, then lllls are not accepted in any inlet.
	class_addmethod(c, (method)args_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)args_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)args_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)args_anything,	"list",			A_GIMME,	0);
	class_addmethod(c, (method)args_bang,		"bang",			0);
	
	// @method bang @digest Output the patcher arguments
	// @description A bang in the rightmost inlet will cause all the patcher arguments to be re-output
	
	class_addmethod(c, (method)args_loadbang,	"loadbang",		0);
	class_addmethod(c, (method)args_assist,		"assist",		A_CANT,		0);

/*	
	CLASS_ATTR_LONG(c, "ins",	0,	t_args, n_ins);
	CLASS_ATTR_FILTER_CLIP(c, "ins", 0, LLLL_MAX_INLETS - 1);
	CLASS_ATTR_LABEL(c, "ins", 0, "Number of llll Inlets");
	CLASS_ATTR_BASIC(c, "ins", 0);
	// @description The number of llll inlets and outlets. In principle, it should match the number of inlets of the patcher. <br />
	// @copy BACH_DOC_STATIC_ATTR
	
	CLASS_ATTR_LONG(c, "nullmode",	0,	t_args, n_nullmode);
	CLASS_ATTR_FILTER_CLIP(c, "nullmode", 0, 1);
	CLASS_ATTR_STYLE(c, "nullmode", 0, "onoff");
	CLASS_ATTR_LABEL(c, "nullmode", 0, "Null Mode");
	// @description When set to 1, <b>null</b> is output if no patcher argument is provided. <br />
	// @copy BACH_DOC_STATIC_ATTR

	CLASS_ATTR_LONG(c, "backtick",	0,	t_args, n_backtick);
	CLASS_ATTR_FILTER_CLIP(c, "backtick", 0, 1);
	CLASS_ATTR_STYLE(c, "backtick", 0, "onoff");
	CLASS_ATTR_LABEL(c, "backtick", 0, "Backtick bach Object Arguments");
	// @description When set to 1, if the first element of the "normal arguments" llll is an attribute of any bach object,
	// then a backtick is prepended to it. In this way, it will not be interpreted as an attribute by any bach object you feed it into. <br />
	// @copy BACH_DOC_STATIC_ATTR

	CLASS_ATTR_LONG(c, "mode",	0,	t_args, n_mode);
	CLASS_ATTR_FILTER_CLIP(c, "mode", 0, 1);
	CLASS_ATTR_STYLE(c, "mode", 0, "onoff");
	CLASS_ATTR_LABEL(c, "mode", 0, "Mode");
	// @description When set to 1, the "normal arguments" llll is always at least the length of the typed-in arguments.
	// If not enough arguments are specified in the enclosing patcher, the missing ones will be taken from the <o>bach.args</o>' object box.
	// This is especially useful for providing an abstraction with a minimal set of default values. <br />
	// @copy BACH_DOC_STATIC_ATTR

	CLASS_ATTR_LONG(c, "done",	0,	t_args, n_done);
	CLASS_ATTR_FILTER_CLIP(c, "done", 0, 1);
	CLASS_ATTR_STYLE(c, "done", 0, "onoff");
	CLASS_ATTR_LABEL(c, "done", 0, "Output 'done' Message");
	// @description When set to 1, the message <m>done</m> is output after the last attribute-style argument, just like in <o>patcherargs</o>. <br />
	// @copy BACH_DOC_STATIC_ATTR

	CLASS_ATTR_LONG(c, "outout",	0,	t_args, n_backtick);
	CLASS_ATTR_FILTER_CLIP(c, "outout", 0, 1);
	CLASS_ATTR_STYLE(c, "outout", 0, "onoff");
	CLASS_ATTR_LABEL(c, "outout", 0, "Output \"out\" patcher attribute");
	// @description When set to 1, the <b>out</b> attribute of the containing patcher, if present, 
    // as well as any <m>out</m> message received by <o>bach.args</o>, is output as an attribute-style argument. <br />
    // When set to 0, which is the default, the <b>out</b> attribute of the containing patcher is ignored,
    // as it is assumed that it is meant for a <o>bach.portal</o> object in the same patcher.
    // Also, any <m>out</m> message received by <o>bach.args</o> will be passed to all the <o>bach.portal</o> objects
    // contained in the same patcher of <o>bach.args</o>.<br />
	// @copy BACH_DOC_STATIC_ATTR
	
	CLASS_ATTR_SYM_VARSIZE(c, "attrs", 0, t_args, n_attrs, n_numattrs, MAX_ATTRS);
	CLASS_ATTR_LABEL(c, "attrs", 0, "Known Attributes");
	// @description An optional set of keywords to be considered as attributes, and therefore output as attribute-style arguments. <br />
	// @copy BACH_DOC_STATIC_ATTR
 
	llllobj_class_add_out_attr(c, LLLL_OBJ_VANILLA);
	//llllobj_class_add_check_attr(c, LLLL_OBJ_VANILLA);
*/
	class_register(CLASS_BOX, c);
	args_class = c;
	
	if (!bach->b_initpargs)
		bach->b_initpargs = (t_object *) object_new_typed(CLASS_NOBOX, gensym("bach.initpargs"), 0, NULL);
	
	dev_post("bach.args compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void args_loadbang(t_args *x)
{
	object_method_typed(bach->b_initpargs, gensym("run"), 0, NULL, NULL);
	args_dopargs(x, NULL, 0, NULL);
}

void args_bang(t_args *x)
{
	long rightinlet = (proxy_getinlet((t_object *) x) == x->n_proxies);
	systhread_mutex_lock(x->n_mutex);
	if (rightinlet) {
		if (x->n_ready) {
			systhread_mutex_unlock(x->n_mutex);
			args_dopargs(x, NULL, 0, NULL);
		} else
			systhread_mutex_unlock(x->n_mutex);
	} else {
		systhread_mutex_unlock(x->n_mutex);
		args_anything(x, _sym_bang, 0, NULL);
	}
}

void args_int(t_args *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	args_anything(x, _sym_int, 1, &outatom);
}

void args_float(t_args *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	args_anything(x, _sym_float, 1, &outatom);
}

void args_anything(t_args *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist = NULL;
	long inlet = proxy_getinlet((t_object *) x);
	long outlet;

	if (inlet == x->n_proxies)
		return;
	
	if (x->n_ready) { // behave like bach.portal
		
		outlet = inlet + 1;
		if (msg == LLLL_NATIVE_MSG)
			inlist = llllobj_get_retained_native_llll_from_args(ac, av); // non-NULL if it's a valid native list
		else { // first check if it's a possible attribute
			long i;
            if (msg == _llllobj_sym_out && x->n_outout == 0) {
                t_llll *portals = NULL;
                if (hashtab_lookup(bach->b_portalpatchers, (t_symbol *) x->n_patcher, (t_object **) &portals) == MAX_ERR_NONE) {
                    t_llllelem *portals_elem;
                    for (portals_elem = portals->l_head; portals_elem; portals_elem = portals_elem->l_next) {
                        t_llllobj_object *this_portal = (t_llllobj_object *) hatom_getobj(&portals_elem->l_hatom);
                        llllobj_obj_setout(this_portal, NULL, ac, av);
                    }
                }
                return;
            }
			for (i = 0; i < x->n_numattrs; i++) {
				if (msg == x->n_attrs[i]) {
					llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 2, msg, ac, av);
					return;
				}
			}
		}
		if (inlist && (x->n_ob.l_out[outlet].b_type == LLLL_O_NATIVE)) { // native -> native
			if (!x->n_clone) {
				outlet_anything(x->n_ob.l_out[outlet].b_outlet, msg, ac, av);
				llll_release(inlist);
			} else {
				t_llll *cloned = llll_clone(inlist);
				llll_release(inlist);
				llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, outlet, cloned);
				llll_free(cloned);
			}
		} else if (!inlist && (x->n_ob.l_out[outlet].b_type == LLLL_O_TEXT)) { // text -> text
			if (msg != _sym_list)
				outlet_anything(x->n_ob.l_out[outlet].b_outlet, msg, ac, av);
			else
				outlet_list(x->n_ob.l_out[outlet].b_outlet, NULL, ac, av);
		} else if (inlist) { // native -> text
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, outlet, inlist);
			llll_release(inlist);
		}
		else { // text -> native
			if (msg == _sym_bang && ac == 0)
				llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, outlet);
			else {
				inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_RETAIN); // LLLL_PARSE_RETAIN is ignored as the llll is surely text
				if (inlist) {
					llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, outlet, inlist);
					llll_free(inlist);
				}
			}
		}
	}
}

void args_assist(t_args *x, void *b, long m, long a, char *s)
{
	char *type = NULL;
	switch (m) {
		case ASSIST_INLET:
			if (a == x->n_proxies)	
				sprintf(s, "(bang) Output Arguments"); // @in 1 @type bang @digest Bang to output all the arguments
			else
				sprintf(s, "llll %ld", a + 1); // @in 0 @loop 1 @digest Incoming lllls
			break;
		case ASSIST_OUTLET:
			llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
			if (a == 0)
				sprintf(s, "Bang after all the stored lllls have been output"); // @out 0 @type bang @digest Bang after all the stored lllls have been output
			else if (a == x->n_proxies + 1)
				sprintf(s, "llll (%s): Normal Arguments", type); // @out 2 @type llll @digest Normal arguments
			else if (a == x->n_proxies + 2)
				sprintf(s, "anything: Attribute-style Arguments"); // @out 3 @type anything @digest Attribute-style arguments
			else
				sprintf(s, "llll %ld (%s)", a, type); // @out 1 @loop 1 @type llll @digest Incoming lllls
			break;
	}
}

void args_free(t_args *x)
{
	long i;
	for (i = x->n_proxies; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
	//object_free_debug(x->n_cache);
	if (x->n_boxav)
		bach_freeptr(x->n_boxav);
	systhread_mutex_free_debug(x->n_mutex);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_args *args_new(t_symbol *s, short ac, t_atom *av)
{
	t_args *x = NULL;
	char outlets[LLLL_MAX_OUTLETS], *this_outlets;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_args *) object_alloc_debug(args_class))) {
		
		// @arg 0 @name arguments @optional 1 @type llll @digest Arguments
		// @description The default arguments (normal and attribute-style) 
		
		x->n_backtick = 0;
		//attr_args_process(x, ac, av);
		
		// hand-made processing of the attributes
		long i = attr_args_offset(ac, av);
		while (i < ac - 1) {
			t_symbol *symattr = atom_getsym(av + i);
			if (!symattr || *symattr->s_name != '@') {
				object_error((t_object *) x, "Bad argument at position %ld", i);
				i++;
				break;
			}
			const char *attrname = symattr->s_name + 1;
			i++;
			if (!strcmp(attrname, "ins")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_ins = CLAMP(val, 0, LLLL_MAX_INLETS - 4);
					i++;
				} else
					object_error((t_object *) x, "Bad value for ins attribute", i);
			} else if (!strcmp(attrname, "nullmode")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_nullmode = CLAMP(val, 0, 1);
					i++;
				} else
					object_error((t_object *) x, "Bad value for nullmode attribute", i);
			} else if (!strcmp(attrname, "backtick")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_backtick = CLAMP(val, 0, 1);
					i++;
				} else
					object_error((t_object *) x, "Bad value for backtick attribute", i);
			} else if (!strcmp(attrname, "mode")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_mode = CLAMP(val, 0, 1);
					i++;
				} else
					object_error((t_object *) x, "Bad value for mode attribute", i);
			} else if (!strcmp(attrname, "done")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_done = CLAMP(val, 0, 1);
					i++;
				} else
					object_error((t_object *) x, "Bad value for done attribute", i);
			} else if (!strcmp(attrname, "clone")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_clone = CLAMP(val, 0, 1);
					i++;
				} else
					object_error((t_object *) x, "Bad value for clone attribute", i);
			} else if (!strcmp(attrname, "outout")) {
				long type = atom_gettype(av + i);
				if (type == A_LONG || type == A_FLOAT) {
					t_atom_long val = atom_getlong(av + i);
					x->n_outout = CLAMP(val, 0, 1);
					i++;
				} else
					object_error((t_object *) x, "Bad value for outout attribute", i);
			} else if (!strcmp(attrname, "attrs")) {
				long numattrs = 0;
				t_symbol *this_attrs;
				while (i < ac && (this_attrs = atom_getsym(av + i)) != NULL && *this_attrs->s_name != '@') {
					x->n_attrs[numattrs] = this_attrs;
					i++;
					numattrs++;
				}
				x->n_numattrs = numattrs;
			} else if (!strcmp(attrname, "out")) {
				llllobj_obj_setout((t_llllobj_object *) x, NULL, 1, av + i);
				i++;
			} else
				object_error((t_object *) x, "Unknown attribute %s", attrname);
		}
		if (i < ac)
			object_error((t_object *) x, "Bad argument list");

		x->n_proxies = x->n_ins;
		this_outlets = outlets;
		*this_outlets++ = 'a';
		for (i = 0; i <= x->n_proxies; i++, this_outlets++)
			*this_outlets = '4';
		*this_outlets++ = 'b';
		*this_outlets = 0;
		llllobj_obj_setup((t_llllobj_object *) x, 0, outlets, NULL);
		x->n_proxy = (void **) sysmem_newptr((x->n_proxies + 1) * sizeof (void *));
		for (i = x->n_proxies; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		if (ac) {
			x->n_boxac = ac;
			x->n_boxav = (t_atom *) bach_newptr(ac * sizeof(t_atom));
			//x->n_cache = linklist_new_debug();
			bach_copyptr(av, x->n_boxav, ac * sizeof(t_atom));
		}
		systhread_mutex_new_debug(&x->n_mutex, 0);
		defer_low(x, (method) args_dopargs, NULL, 0, NULL);
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	//object_post((t_object *) x, "instantiated bach.args: %p", x);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

void args_dopargs(t_args *x, t_symbol *msg, long argc, t_atom *argv)
{
	t_object *patcher; // the patcher containing this bach.args
	t_jbox *pfftbox; 
	t_object *box; // the box containing the patcher
	t_atombuf *patcherargs;

	long i;
	long ac = 0;
	t_atom *av = NULL, *free_me = NULL, *this_p_av;
	t_max_err err = MAX_ERR_NONE;
	t_symbol *patcher_classname;
	t_llll *b_ll = NULL, *p_ll = NULL;
	long p_true_ac, b_true_ac, shootit;
	long outargsac;
	t_atom *outargsav;
	t_symbol *attrsym, **this_arg;

	long cm; 
	long cmdaltsh = (eShiftKey | eCommandKey | eAltKey);
	long doit = (((cm = jkeyboard_getcurrentmodifiers()) & cmdaltsh) != cmdaltsh);
	
	if (!doit) {
		x->n_ready = 1;
		return;
	}
	
	object_obex_lookup(x, gensym("#P"), (t_object **) &patcher);
	
    x->n_patcher = patcher;
    
	if (!(box = object_attr_getobj(patcher, _sym_box)))
		object_method(patcher, _sym_getassoc, &box);
	
	if (box) {
		patcher_classname = object_classname(box);

		if (patcher_classname == gensym("bpatcher")) {	
			object_attr_getvalueof(box, _sym_args, &ac, &av);
			free_me = av;
		}
		else {
			if (patcher_classname == gensym("pfft~") || 
				patcher_classname == gensym("poly~") ||
				patcher_classname == gensym("dynamicdsp~") ||
				patcher_classname == gensym("dynamicserial~")) {
				err = object_obex_lookup(box, gensym("#B"), (t_object **) &pfftbox);  // it's a poly
				patcherargs = (t_atombuf *) pfftbox->b_binbuf;
			} else
				patcherargs = (t_atombuf *) ((t_jbox *) box)->b_binbuf;
			ac = patcherargs->a_argc - 1;
			av = patcherargs->a_argv + 1;
		}
	} else if (!x->n_retrying) {
		x->n_retrying = 1;
		defer_low(x, (method) args_dopargs, NULL, 0, NULL);
		return;
	}
	x->n_retrying = 0;

	if (x->n_processed)
		return;
	x->n_processed = 1;
	
	// p attributes
	
	p_true_ac = attr_args_offset(ac, av);
	i = ac - 1;
	outargsav = av + i;
	while (i >= p_true_ac) {
		outargsac = 0;
		while (atom_gettype(outargsav) != A_SYM || *(atom_getsym(outargsav)->s_name) != '@') {
			outargsav--;
			outargsac++;
			i--;
		}
		attrsym = gensym((atom_getsym(outargsav)->s_name) + 1);
		
		if (x->n_outout || attrsym != _llllobj_sym_out) {
			if (x->n_backtick) {
				for (this_arg = _llllobj_attributes; *this_arg; this_arg++)
					if (attrsym == *this_arg)
						break;
				if (*this_arg)
					attrsym = sym_addquote(attrsym->s_name);
				else
					attrsym = llll_quoteme(attrsym);
			}
			llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 2, attrsym, outargsac, outargsav + 1);	
		}
		outargsav--;
		i--;
	}
	
	// b attributes
	
	b_true_ac = attr_args_offset(x->n_boxac, x->n_boxav);
	
	i = x->n_boxac - 1;
	outargsav = x->n_boxav + i;
	while (i >= b_true_ac) {
		outargsac = 0;
		while (atom_gettype(outargsav) != A_SYM || *((attrsym = atom_getsym(outargsav))->s_name) != '@') {
			outargsav--;
			outargsac++;
			i--;
		}
		
		if (attrsym != gensym("@out") && 
			attrsym != gensym("@ins") && 
			attrsym != gensym("@mode") &&
			attrsym != gensym("@done") &&
			attrsym != gensym("@nullmode") &&
			attrsym != gensym("@backtick") &&
			attrsym != gensym("@outout") &&
			attrsym != gensym("@attrs") &&
			attrsym != gensym("@clone")) {
			shootit = 1;
			for (this_p_av = av + p_true_ac; this_p_av < av + ac; this_p_av ++)
				if (atom_gettype(this_p_av) == A_SYM && this_p_av->a_w.w_sym == attrsym) {
					shootit = 0;
					break;
				}
			if (shootit) {
				attrsym = gensym(attrsym->s_name + 1);
				if (x->n_backtick) {
					for (this_arg = _llllobj_attributes; *this_arg; this_arg++)
						if (attrsym == *this_arg)
							break;
					if (*this_arg)
						attrsym = sym_addquote(attrsym->s_name);
					else
						attrsym = llll_quoteme(attrsym);
				}
				llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 2, attrsym, outargsac, outargsav + 1);	
			}
		}
		outargsav--;
		i--;
	}

	if (x->n_done)
		llllobj_outlet_anything((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 2, _sym_done, 0, NULL);

	if (p_true_ac)
		p_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, p_true_ac, av, LLLL_PARSE_RETAIN); // of course, because it's surely a text-based llll, LLLL_PARSE_RETAIN makes no difference

	if (b_true_ac)
		b_ll = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, NULL, b_true_ac, x->n_boxav, LLLL_PARSE_RETAIN); // of course, because it's surely a text-based llll, LLLL_PARSE_RETAIN makes no difference
	if (!b_ll && !p_ll && x->n_nullmode == 1) {
		b_ll = llll_get();
	}
	
	if (!p_ll && b_ll)
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 1, b_ll);
	else if (p_ll && !b_ll)
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 1, p_ll);
	else if (p_ll && b_ll && (x->n_mode == 0 || p_ll->l_size >= b_ll->l_size))
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 1, p_ll);
	else if (p_ll && b_ll) {
		t_llll *right_ll = llll_slice(b_ll, p_ll->l_size);
		llll_chain(p_ll, right_ll);
		llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, x->n_proxies + 1, p_ll);
	}
	
	llll_free(p_ll);
	llll_free(b_ll);

	x->n_ready = 1;
	
	if (free_me)
		bach_freeptr(free_me);
	llllobj_outlet_bang((t_object *) x, LLLL_OBJ_VANILLA, 0);
	return;
}