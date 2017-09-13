#include "ext.h"
#include "ext_obex.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "llllobj.h"
#include "ext_globalsymbol.h"
#include "lexpr.h"
#include "llll_math.h"
#include "errno.h"

t_max_err lexpr_eval_method(t_lexpr *expr, t_symbol *msg, short ac, t_atom *av, t_atom *rv);

t_class *lexpr_class = NULL;

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
	
	c = class_new("bach.lexpr", (method)lexpr_new, (method)lexpr_free, (short)sizeof(t_lexpr), 0L, A_GIMME, 0);
	class_addmethod(c, (method)lexpr_eval_method, "eval", A_GIMMEBACK, 0);
	
	c->c_flags |= CLASS_FLAG_POLYGLOT;
	class_register(CLASS_NOBOX, c);
	lexpr_class = c;
	*/
	dev_post("bach.lexpr compiled %s %s", __DATE__, __TIME__);

	return 0;
	
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////

/*
 av contains
 - pointer to array of LEXPR_MAX_VARS hatoms: arguments atoms
 rv contains:
 - hatom with result
 */

t_max_err lexpr_eval_method(t_lexpr *expr, t_symbol *msg, short ac, t_atom *av, t_atom *rv)
{
	t_atom outatom;
	atom_setobj(&outatom, lexpr_eval(expr, (t_hatom *) atom_getobj(av)));
	atom_setobj(rv, atomarray_new_debug(1, &outatom));
	return MAX_ERR_NONE;
}



