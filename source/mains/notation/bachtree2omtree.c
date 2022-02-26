/*
 *  bachtree2omtree.c
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
	bachtree2omtree.c
	
	@name 
	bach.bachtree2omtree
	
	@realname 
	bach.bachtree2omtree

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert a bach rhythmic tree into an OpenMusic rhythmic tree 
	
	@description
	Converts a the measureinfo and the duration rhythmic tree (in bach form, as outputted by <o>bach.score</o>) 
	into an OpenMusic-formatted rhythmic tree.
		
	@category
	bach, bach objects, bach notation

	@keywords
	rhythmic tree, tree, rhythm, convert, OpenMusic, measureinfo, duration

	@seealso
	bach.omtree2bachtree, bach.score, The World Outside
	
	@owner
	Daniele Ghisi
*/


#include "notation/notation.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"
#include "jpatcher_api.h"
#include "jgraphics.h"
#include "ext_systhread.h"
#include "foundation/llllobj.h"

typedef struct _bachtree2omtree
{
	struct llllobj_object 	n_ob;
	
	void					*m_proxy;	// proxy
	long					m_in;   
} t_bachtree2omtree;


void bachtree2omtree_assist(t_bachtree2omtree *x, void *b, long m, long a, char *s);
void bachtree2omtree_inletinfo(t_bachtree2omtree *x, void *b, long a, char *t);

t_bachtree2omtree *bachtree2omtree_new(t_symbol *s, short ac, t_atom *av);
void bachtree2omtree_free(t_bachtree2omtree *x);

void bachtree2omtree_bang(t_bachtree2omtree *x);
void bachtree2omtree_int(t_bachtree2omtree *x, t_atom_long num);
void bachtree2omtree_float(t_bachtree2omtree *x, double num);
void bachtree2omtree_anything(t_bachtree2omtree *x, t_symbol *msg, long ac, t_atom *av);

t_class *bachtree2omtree_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}	
	
    CLASS_NEW_CHECK_SIZE(c, "bach.bachtree2omtree", (method)bachtree2omtree_new, (method)bachtree2omtree_free, (long) sizeof(t_bachtree2omtree), 0L, A_GIMME, 0);
	
	// @method llll @digest Function depends on inlet
	// @description 
	// In first inlet: Sets the Measureinfo for the conversion and trigger the output of the OpenMusic-formatted tree. <br />
	// In second inlet: Sets the bach Duration tree to be converted.
	class_addmethod(c, (method)bachtree2omtree_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)bachtree2omtree_int,							"int",					A_LONG,		0);
	class_addmethod(c, (method)bachtree2omtree_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)bachtree2omtree_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the conversion
	// @description Perform the conversion on the most recently received input data.
	class_addmethod(c, (method)bachtree2omtree_bang,						"bang",		0);
	
	class_addmethod(c, (method)bachtree2omtree_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)bachtree2omtree_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

	
	class_register(CLASS_BOX, c);
	bachtree2omtree_class = c;
	
	dev_post("bach.bachtree2omtree compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void bachtree2omtree_bang(t_bachtree2omtree *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void bachtree2omtree_int(t_bachtree2omtree *x, t_atom_long num)
{
	t_atom argv[1]; 
	atom_setlong(argv, num);
	bachtree2omtree_anything(x, _llllobj_sym_list, 1, argv);
}

void bachtree2omtree_float(t_bachtree2omtree *x, double num){
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	bachtree2omtree_anything(x, _llllobj_sym_list, 1, argv);
}


void bachtree2omtree_anything(t_bachtree2omtree *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *measureinfo, *durs;
	
	long inlet = proxy_getinlet((t_object *) x);

	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 1);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, inlet);
		x->n_ob.l_rebuild = 1;
	}
	
	// do calculations
	if (inlet == 0) {
		measureinfo = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
		durs = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
		
		if (measureinfo && durs) {
			t_llll *omtree = bach_rhythmic_tree_to_om_rhythmic_tree(durs, measureinfo);
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, omtree, 0);
			
			llll_free(measureinfo);
			llll_free(durs);
		} else if (measureinfo)
			llll_free(measureinfo);
		else if (durs)
			llll_free(durs);
		
		x->n_ob.l_rebuild = 0;
		bachtree2omtree_bang(x);
	}
}


void bachtree2omtree_assist(t_bachtree2omtree *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		if (a == 0) 
			sprintf(s, "llll: Measureinfo"); // @in 0 @type llll @digest The bach Measureinfo
		else
			sprintf(s, "llll: Durations");  // @in 1 @type llll @digest The bach Durations tree (as symbolic rational values)
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s): OM Rhythmic Tree", type); // @out 0 @type llll @digest The OpenMusic-formatted rhythmic tree 
	}
}

void bachtree2omtree_inletinfo(t_bachtree2omtree *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void bachtree2omtree_free(t_bachtree2omtree *x)
{	
	object_free_debug(x->m_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_bachtree2omtree *bachtree2omtree_new(t_symbol *s, short ac, t_atom *av)
{
	t_bachtree2omtree *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_bachtree2omtree *) object_alloc_debug(bachtree2omtree_class))) {
	
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "4");
		x->m_proxy = proxy_new_debug((t_object *) x, 1, &x->m_in);
		
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

