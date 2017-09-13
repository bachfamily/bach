#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "llllobj.h"
#include "ext_globalsymbol.h"
#include "collector.h"

t_max_err collector_get_method(t_collector *x, t_symbol *msg, long ac, t_atom *av);
t_max_err collector_command_method(t_collector *x, t_symbol *msg, long ac, t_atom *av);
t_max_err collector_output_method(t_collector *x, t_symbol *msg, long ac, t_atom *av, t_atom *rv);
t_max_err collector_outputall_method(t_collector *x, t_symbol *msg, long ac, t_atom *av, t_atom *rv);

t_class *collector_class = NULL;


int T_EXPORT main(void)
{
	/*
	t_class *c;
	
	if (llllobj_check_version(BACH_LLLL_VERSION)) {
		error("bach: bad installation");
		return 1;
	}
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	c = class_new("bach.collector", (method)collector_new, (method)collector_free, (short)sizeof(t_collector), 0L, A_GIMME, 0);
	class_addmethod(c, (method)collector_get_method,		"get",			A_GIMME,		0);
	class_addmethod(c, (method)collector_command_method,	"command",		A_GIMME,		0);
	class_addmethod(c, (method)collector_output_method,		"output",		A_GIMMEBACK,	0);
	class_addmethod(c, (method)collector_outputall_method,	"outputall",	A_GIMMEBACK,	0);
	class_addmethod(c, (method)collector_size,				"size",			A_LONG,			0);
	
	c->c_flags |= CLASS_FLAG_POLYGLOT;
	class_register(CLASS_NOBOX, c);
	collector_class = c;
	*/
	dev_post("bach.collector compiled %s %s", __DATE__, __TIME__);

	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
// av contains:
// - llll to append (DESTROYED!)
// - long: nullmode

t_max_err collector_get_method(t_collector *x, t_symbol *msg, long ac, t_atom *av)
{
	if (ac > 0)
		collector_get(x, (t_llll *) atom_getobj(av),  ac < 2 ? 0 : atom_getlong(av + 1), 0);
	return MAX_ERR_NONE;
}

// av contains long for steps to take, or symbol with other instructions
t_max_err collector_command_method(t_collector *x, t_symbol *msg, long ac, t_atom *av)
{
	t_symbol *command;
	
	if (ac == 0)
		return MAX_ERR_NONE;

	switch (atom_gettype(av)) {
		case A_LONG:
		case A_FLOAT:
			collector_change_level(x, atom_getlong(av));
			break;
		case A_SYM:
			command = atom_getsym(av);
			if (command == gensym("top"))
				collector_top(x);
			else if (command == _sym_back)
				collector_back(x);
			else if (command == _sym_clear)
				collector_clear(x);
			else if (command == gensym("clearall"))
				collector_clearall(x);			
			else if (command == gensym("collection"))
				collector_change_collection(x, ac > 1 ? atom_getlong(av + 1) - LLLL_IDX_BASE : 0);
			break;
	}
	return MAX_ERR_NONE;
}

/*
 av contains:
 - long: stack levels to output: 0 = all, 1 = only most recent, -1 = all minus oldest etc
 - long: outwrap
 rv contains:
 - llll with output
*/

t_max_err collector_output_method(t_collector *x, t_symbol *msg, long ac, t_atom *av, t_atom *rv)
{
	long lvls, outwrap;
	t_atom outatom;
	
	lvls = atom_getlong(av);
	outwrap = atom_getlong(av + 1);

	atom_setobj(&outatom, collector_output(x, lvls, outwrap));
	atom_setobj(rv, atomarray_new_debug(1, &outatom));
	return MAX_ERR_NONE;
}

/*
 av contains:
 - long: skipempty
 - long: outwrap
 rv contains:
 - llll with output
 */

t_max_err collector_outputall_method(t_collector *x, t_symbol *msg, long ac, t_atom *av, t_atom *rv)
{
	t_atom outatom;
	
	long skip_empty = ac ? atom_getlong(av) : 0;
	long outwrap = atom_getlong(av + 1);
	
	atom_setobj(&outatom, collector_outputall(x, skip_empty, outwrap));
	atom_setobj(rv, atomarray_new_debug(1, &outatom));
	return MAX_ERR_NONE;
}


