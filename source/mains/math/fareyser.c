/*
 *  fareyser.c
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
 fareyser.c
 
 @name 
 bach.fareyser
 
 @realname 
 bach.fareyser
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Farey series
 
 @description
 Computes sequences of rational numbers between 0 and 1 within given maximum terms
 
 @discussion
 
 @category
 bach, bach objects, bach math
 
 @keywords
 series, arithmetic, step, compute, calculate

 @seealso
 bach.primeser, bach.geomser, bach.recurser
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _fareyser
{
	t_llllobj_object 	n_ob;
    t_atom_long         n_order;
    t_atom_long         n_jilimit;
	t_atom				n_offset;
	long				n_in;
	t_bach_atomic_lock	n_lock;
} t_fareyser;


void fareyser_assist(t_fareyser *x, void *b, long m, long a, char *s);
void fareyser_inletinfo(t_fareyser *x, void *b, long a, char *t);

t_fareyser *fareyser_new(t_symbol *s, short ac, t_atom *av);
void fareyser_free(t_fareyser *x);

void fareyser_bang(t_fareyser *x);
void fareyser_int(t_fareyser *x, t_atom_long v);
void fareyser_float(t_fareyser *x, double v);

void fareyser_anything(t_fareyser *x, t_symbol *msg, short ac, t_atom *av);


t_class *fareyser_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.fareyser", (method)fareyser_new, (method)fareyser_free, (long) sizeof(t_fareyser), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)fareyser_int,		"int",			A_LONG, 0);

	// @method int @digest Set order, output series
	// @description
	// An integer in the first inlet sets the Farey series order and outputs the Farey series
	class_addmethod(c, (method)fareyser_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)fareyser_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)fareyser_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)fareyser_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the Farey series
	// @description A bang outputs the Farey series according to the most recently received parameters.
	class_addmethod(c, (method)fareyser_bang,		"bang",			0);
	class_addmethod(c, (method)fareyser_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)fareyser_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	fareyser_class = c;
	
    CLASS_ATTR_LONG(c, "order",    0,    t_fareyser, n_order);
    CLASS_ATTR_LABEL(c, "order", 0, "Order");
    CLASS_ATTR_BASIC(c, "order", 0);
    CLASS_ATTR_FILTER_MIN(c, "order", "1");
    // @description Sets the order of the Farey series, i.e. the largest term showing up.

    CLASS_ATTR_LONG(c, "jilimit",    0,    t_fareyser, n_jilimit);
    CLASS_ATTR_LABEL(c, "jilimit", 0, "JI Limit");
    // @description The <m>jilimit</m> attributes allows you to set a maximum just intonation limit
    // for a rational number showing up in the output. This allows filtering the whole Farey series.

    CLASS_ATTR_ATOM(c,"offset",0, t_fareyser, n_offset);
    CLASS_ATTR_STYLE_LABEL(c,"offset",0,"text","Offset");
    CLASS_ATTR_BASIC(c,"offset",0);
    // @description Sets a global offset for the Farey series.

    
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	dev_post("bach.fareyser compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void fareyser_bang(t_fareyser *x)
{	
	if (x->n_ob.l_rebuild != 0) {
		x->n_ob.l_rebuild = 0;

        const long jilimit = x->n_jilimit;
        t_llll *fareyout = llll_get();
        t_llll *offset_ll = llll_parse(1, &x->n_offset);
        t_rational offset = long2rat(0);
        if (offset_ll && offset_ll->l_head && (hatom_gettype(&offset_ll->l_head->l_hatom) == H_LONG || hatom_gettype(&offset_ll->l_head->l_hatom) == H_RAT))
            offset = hatom_getrational(&offset_ll->l_head->l_hatom);
        std::vector<t_rational> farey = get_farey_sequence(x->n_order, offset, jilimit);
        for (long i = 0; i < farey.size(); i++)
            llll_appendrat(fareyout, farey[i]);
        
        llll_free(offset_ll);
		llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, fareyout, 0);
	}
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void fareyser_int(t_fareyser *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	fareyser_anything(x, _sym_int, 1, &outatom);
}

void fareyser_float(t_fareyser *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	fareyser_anything(x, _sym_float, 1, &outatom);
}

void fareyser_anything(t_fareyser *x, t_symbol *msg, short ac, t_atom *av)
{
	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);

	if (!inlist)
		return;
    if (inlist->l_head && hatom_gettype(&inlist->l_head->l_hatom) == H_LONG)
        x->n_order = hatom_getlong(&inlist->l_head->l_hatom);
	llll_free(inlist);
	x->n_ob.l_rebuild = 1;
    fareyser_bang(x);
}


void fareyser_assist(t_fareyser *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "int/bang: Order or bang to Compute");			break;	// @in 0 @type int/bang @digest Order or bang to Compute
																				// @description If an integer is entered, it is considered as the order of the Farey series to be constructed and output.
                                                                                // A bang outputs the series
		}
	}
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Farey series
	}
}

void fareyser_inletinfo(t_fareyser *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void fareyser_free(t_fareyser *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_fareyser *fareyser_new(t_symbol *s, short ac, t_atom *av)
{
	t_fareyser *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_fareyser *) object_alloc_debug(fareyser_class))) {
		// @arg 0 @name order @optional 1 @type number @digest Order
		// @description The order of the farey series, corresponding to the maximum denominator.
		// Default is 1.

		long true_ac = attr_args_offset(ac, av);
		atom_setlong(&x->n_offset, 0);
        x->n_order = 1;
        x->n_jilimit = 0;
		attr_args_process(x, ac, av);
		if (true_ac) {
            x->n_order = MAX(1, atom_getlong(av));
		}
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
