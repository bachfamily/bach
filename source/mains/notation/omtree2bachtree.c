/*
 *  omtree2bachtree.c
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
	omtree2bachtree.c
	
	@name 
	bach.omtree2bachtree
	
	@realname 
	bach.omtree2bachtree

	@type
	object
	
	@module
	bach

	@author
	bachproject
	
	@digest 
	Convert an OpenMusic rhythmic tree into a bach rhythmic tree
	
	@description
	Converts a rhythmic tree in OpenMusic form into the proper Measureinfo and Duration tree readable by <o>bach.score</o>.
		
	@discussion
	If you connect the object to bach.score, don't forget to set the bach.score @treehandling attribute to 0 
	(Take For Granted) and @maketreecompatiblewithts attribute to 0, if you wish all rhythmic levels to be kept 
	exactly the same as the OpenMusic levels! 
	Otherwise, as usual, bach will process the tree according to the mode you had defined via the @treehandling 
	attribute, and possibly reboxes your rhythm if your maketreecompatiblewithts is 1.
	
	@category
	bach, bach objects, bach notation

	@keywords
	rhythmic tree, tree, rhythm, convert, OpenMusic, measureinfo, duration

	@seealso
	bach.bachtree2omtree, bach.score, The World Outside
	
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

typedef struct _omtree2bachtree
{
	struct llllobj_object 	n_ob;
	
} t_omtree2bachtree;


void omtree2bachtree_assist(t_omtree2bachtree *x, void *b, long m, long a, char *s);
void omtree2bachtree_inletinfo(t_omtree2bachtree *x, void *b, long a, char *t);

t_omtree2bachtree *omtree2bachtree_new(t_symbol *s, short ac, t_atom *av);
void omtree2bachtree_free(t_omtree2bachtree *x);

void omtree2bachtree_bang(t_omtree2bachtree *x);
void omtree2bachtree_int(t_omtree2bachtree *x, t_atom_long num);
void omtree2bachtree_float(t_omtree2bachtree *x, double num);
void omtree2bachtree_anything(t_omtree2bachtree *x, t_symbol *msg, long ac, t_atom *av);

t_class *omtree2bachtree_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}	
	
    CLASS_NEW_CHECK_SIZE(c, "bach.omtree2bachtree", (method)omtree2bachtree_new, (method)omtree2bachtree_free, (long) sizeof(t_omtree2bachtree), 0L, A_GIMME, 0);
	
	// @method llll @digest Take the incoming OpenMusic-formatted rhythmic tree and convert it
	// @description The OpenMusic rhythmic tree
	class_addmethod(c, (method)omtree2bachtree_anything,					"anything",				A_GIMME,	0);
	class_addmethod(c, (method)omtree2bachtree_int,							"int",					A_LONG,		0);
	class_addmethod(c, (method)omtree2bachtree_float,						"float",				A_FLOAT,	0);
	class_addmethod(c, (method)omtree2bachtree_anything,					"list",					A_GIMME,	0);

	// @method bang @digest Perform the conversion
	// @description Perform the conversion on the most recently received input data.
	class_addmethod(c, (method)omtree2bachtree_bang,						"bang",		0);
	
	class_addmethod(c, (method)omtree2bachtree_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)omtree2bachtree_inletinfo,	"inletinfo",	A_CANT,		0);

	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);

	
	class_register(CLASS_BOX, c);
	omtree2bachtree_class = c;
	
	dev_post("bach.omtree2bachtree compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void omtree2bachtree_bang(t_omtree2bachtree *x)
{
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}

void omtree2bachtree_int(t_omtree2bachtree *x, t_atom_long num)
{
	t_atom argv[1]; 
	atom_setlong(argv, num);
	omtree2bachtree_anything(x, _llllobj_sym_list, 1, argv);
}

void omtree2bachtree_float(t_omtree2bachtree *x, double num)
{
	t_atom argv[1]; 
	atom_setfloat(argv, num);
	omtree2bachtree_anything(x, _llllobj_sym_list, 1, argv);
}


void omtree2bachtree_anything(t_omtree2bachtree *x, t_symbol *msg, long ac, t_atom *av)
{
	t_llll *inlist;
	
	if (msg == _sym_clear) {
		llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 0);
		return;
	}

	if (msg != _sym_bang) {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
		x->n_ob.l_rebuild = 1;
	}

	inlist = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
	
	if (inlist) {
		t_llll *measinfo;
		t_llll *bachtree = om_rhythmic_tree_to_bach_rhythmic_tree(inlist, &measinfo);
		
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, measinfo, 0);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, bachtree, 1);
		llll_free(inlist);
	}
	
	x->n_ob.l_rebuild = 0;
	omtree2bachtree_bang(x);
}


void omtree2bachtree_assist(t_omtree2bachtree *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		sprintf(s, "llll: OM Rhythmic Tree"); // @in 0 @type llll @digest The OpenMusic-formatted rhythmic tree 
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		if (a == 0) {
			sprintf(s, "llll (%s): Measureinfo", type); // @out 0 @type llll @digest The bach Measureinfo corresponding to the input tree 
		} else {
			sprintf(s, "llll (%s): Durations", type); // @out 1 @type llll @digest The bach Durations (in tree form) corresponding to the input tree 
		}
	}
}

void omtree2bachtree_inletinfo(t_omtree2bachtree *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}


void omtree2bachtree_free(t_omtree2bachtree *x)
{	
	llllobj_obj_free((t_llllobj_object *) x);
}

t_omtree2bachtree *omtree2bachtree_new(t_symbol *s, short ac, t_atom *av)
{
	t_omtree2bachtree *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_omtree2bachtree *) object_alloc_debug(omtree2bachtree_class))) {
	
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 1, "44");
	
	} else 
		error(BACH_CANT_INSTANTIATE);
	
	llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);
    if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x);
	return NULL;
}

