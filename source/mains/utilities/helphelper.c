/*
 *  helphelper.c
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

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _helphelper
{
	struct llllobj_object 	n_ob;
	t_patcher				*n_patcher;
} t_helphelper;

t_helphelper *helphelper_new(t_symbol *s, short ac, t_atom *av);
void helphelper_free(t_helphelper *x);

t_class *helphelper_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.helphelper", (method)helphelper_new, (method)helphelper_free, (short)sizeof(t_helphelper), 0L, A_GIMME, 0);
	
	class_register(CLASS_BOX, c);
	helphelper_class = c;
	
	dev_post("bach.helphelper compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}

void helphelper_free(t_helphelper *x)
{
	if (hashtab_chuckkey(bach->b_helppatches, (t_symbol *) x->n_patcher))
		object_warn((t_object *) x, "More than one bach.helphelper being freed in patch %p!", x->n_patcher);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_helphelper *helphelper_new(t_symbol *s, short ac, t_atom *av)
{
	t_helphelper *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if (x = (t_helphelper *) object_alloc_debug(helphelper_class)) {
		llllobj_obj_setup((t_llllobj_object *) x, 0, "");
		x->n_patcher = gensym("#P")->s_thing;
		if (hashtab_store_safe(bach->b_helppatches, (t_symbol *) x->n_patcher, (t_object *) x))
			object_warn((t_object *) x, "More than one bach.helphelper being created in patch %p!", x->n_patcher);
	}
    
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
