/*
 *  continuedfraction.c
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
 continuedfraction.c
 
 @name 
 bach.continuedfraction
 
 @realname 
 bach.continuedfraction
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Continued fractions
 
 @description
 Computes rationall approximations of the incoming number by
 producing its continued fraction and convergents.
 
 @discussion
 
 @category
 bach, bach objects, bach math
 
 @keywords
 fraction, continued, approximation, convergents

 @seealso
 bach.primeser, bach.geomser, bach.recurser
 
 @owner
 Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _continuedfraction
{
	t_llllobj_object 	n_ob;
    t_hatom             n_num;
    
    t_atom_long         n_numcoeffs;
    t_atom_long         n_remove_zero;
    t_atom_long         n_err_mode;
    t_atom_long         n_include_semiconvergents;

    
	long				n_in;
	t_bach_atomic_lock	n_lock;
} t_continuedfraction;


void continuedfraction_assist(t_continuedfraction *x, void *b, long m, long a, char *s);
void continuedfraction_inletinfo(t_continuedfraction *x, void *b, long a, char *t);

t_continuedfraction *continuedfraction_new(t_symbol *s, short ac, t_atom *av);
void continuedfraction_free(t_continuedfraction *x);

void continuedfraction_bang(t_continuedfraction *x);
void continuedfraction_int(t_continuedfraction *x, t_atom_long v);
void continuedfraction_float(t_continuedfraction *x, double v);

void continuedfraction_anything(t_continuedfraction *x, t_symbol *msg, short ac, t_atom *av);


t_class *continuedfraction_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.continuedfraction", (method)continuedfraction_new, (method)continuedfraction_free, (long) sizeof(t_continuedfraction), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)continuedfraction_int,		"int",			A_LONG, 0);

	// @method number @digest Set number and output continued fraction
	// @description
	// Any number in the first inlet prompts the calculation of the continued fraction and its output
	class_addmethod(c, (method)continuedfraction_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)continuedfraction_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)continuedfraction_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)continuedfraction_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the last computed continued fraction
	// @description A bang outputs the last computed continued fraction.
	class_addmethod(c, (method)continuedfraction_bang,		"bang",			0);
	class_addmethod(c, (method)continuedfraction_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)continuedfraction_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	continuedfraction_class = c;
	
    CLASS_ATTR_LONG(c, "numcoeffs",    0,    t_continuedfraction, n_numcoeffs);
    CLASS_ATTR_STYLE_LABEL(c, "numcoeffs", 0, "text", "Number of Coefficients to Compute");
    CLASS_ATTR_BASIC(c, "numcoeffs", 0);
    CLASS_ATTR_FILTER_MIN(c, "numcoeffs", 1);
    // @description Sets the number of coefficients of the continued fraction to compute.

    CLASS_ATTR_LONG(c, "removezeros",    0,    t_continuedfraction, n_remove_zero);
    CLASS_ATTR_STYLE_LABEL(c, "removezeros", 0, "onoff", "Remove Zeros");
    CLASS_ATTR_FILTER_CLIP(c, "removezeros", 0, 1);
    // @description Toggles the ability to remove zero convergents from the continued fraction

    CLASS_ATTR_LONG(c, "semiconvergents",    0,    t_continuedfraction, n_include_semiconvergents);
    CLASS_ATTR_STYLE_LABEL(c, "semiconvergents", 0, "onoff", "Include Semiconvergents");
    CLASS_ATTR_FILTER_CLIP(c, "semiconvergents", 0, 1);
    // @description Toggles the ability to also include semiconvergents in the output.
    
    CLASS_ATTR_LONG(c, "errmode",    0,    t_continuedfraction, n_err_mode);
    CLASS_ATTR_STYLE_LABEL(c, "errmode", 0, "enumindex", "Error Mode");
    CLASS_ATTR_ENUMINDEX(c,"errmode", 0, "Linear Cents");
    CLASS_ATTR_FILTER_CLIP(c, "errmode", 0, 1);
    // @description Chooses the algorithm for computing the error: either Linear (0) or logarithmic, as measured in Cents (1).


    
    
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	

	dev_post("bach.continuedfraction compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void continuedfraction_bang(t_continuedfraction *x)
{	
	if (x->n_ob.l_rebuild != 0) {
		x->n_ob.l_rebuild = 0;

        t_hatom h;
        const long STOP_AT_THIS_AN = 1000;
        const long MAX_ITER = 0;
        
        long numcoeffs = 0;
        bool remove_zero = false;
        double err_thresh = 0;
        bool includeSemiconvergents = 0;
        long log_error = 0;
        bach_atomic_lock(&x->n_lock);
        h = x->n_num;
        numcoeffs = x->n_numcoeffs;
        remove_zero = x->n_remove_zero;
        log_error = x->n_err_mode;
        includeSemiconvergents = x->n_include_semiconvergents;
        bach_atomic_unlock(&x->n_lock);
        
        t_llll *contfrac = llll_get();
        t_llll *convergents = llll_get();
        t_llll *errors = llll_get();
        std::vector<long> contfrac_v;
        std::vector<double> errors_v;
        if (hatom_gettype(&h) == H_LONG) {
            llll_appendlong(contfrac, hatom_getlong(&h));
            if (!remove_zero || hatom_getlong(&h) != 0) {
                llll_appendlong(convergents, hatom_getlong(&h));
                llll_appenddouble(errors, 0);
            }
        } else if (hatom_gettype(&h) == H_RAT || hatom_gettype(&h) == H_PITCH) {
            t_rational r = hatom_gettype(&h) == H_RAT ? hatom_getrational(&h) : hatom_getpitch(&h).getJIRatio();
            
            std::vector<t_rational> convergents_v = get_convergents_ext_and_continued_fraction(contfrac_v, errors_v, (double)r, numcoeffs, remove_zero, err_thresh, log_error, true, hatom_getrational(&h).r_den, includeSemiconvergents, {}, STOP_AT_THIS_AN, MAX_ITER, true);

            for (long i = 0; i < contfrac_v.size(); i++) {
                llll_appendlong(contfrac, contfrac_v[i]);
            }
            for (long i = 0; i < convergents_v.size(); i++) {
                llll_appendrat(convergents, convergents_v[i]);
            }
            for (long i = 0; i < errors_v.size(); i++) {
                llll_appenddouble(errors, errors_v[i]);
            }
        } else if (hatom_gettype(&h) == H_DOUBLE) {

            std::vector<t_rational> convergents_v = get_convergents_ext_and_continued_fraction(contfrac_v, errors_v, hatom_getdouble(&h), numcoeffs, remove_zero, err_thresh, log_error, false, 0, includeSemiconvergents, {}, STOP_AT_THIS_AN, MAX_ITER, true);
            
            for (long i = 0; i < contfrac_v.size(); i++) {
                llll_appendlong(contfrac, contfrac_v[i]);
            }
            for (long i = 0; i < convergents_v.size(); i++) {
                llll_appendrat(convergents, convergents_v[i]);
            }
            for (long i = 0; i < errors_v.size(); i++) {
                llll_appenddouble(errors, errors_v[i]);
            }

        } else {
            object_error((t_object *)x, "Trying to compute continued fraction of something that is not a number or pitch...");
        }
        
		llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, contfrac, 0);
        llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, convergents, 1);
        llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, errors, 2);
	}
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 2);
    llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 1);
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void continuedfraction_int(t_continuedfraction *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	continuedfraction_anything(x, _sym_int, 1, &outatom);
}

void continuedfraction_float(t_continuedfraction *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	continuedfraction_anything(x, _sym_float, 1, &outatom);
}

void continuedfraction_anything(t_continuedfraction *x, t_symbol *msg, short ac, t_atom *av)
{
	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);

	if (!inlist)
		return;
    if (inlist->l_head && hatom_gettype(&inlist->l_head->l_hatom) != H_LLLL)
        x->n_num = inlist->l_head->l_hatom;
	llll_free(inlist);
	x->n_ob.l_rebuild = 1;
    continuedfraction_bang(x);
}


void continuedfraction_assist(t_continuedfraction *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "number/pitch: Compute continued fraction");			break;	// @in 0 @type number @digest Compute continued fraction
            // @description A number in the left inlet prompts the computation and output of its continuous fraction, convergents and errors.
            // A pitch is interpreted as a just intonation ratio.
		}
	}
    else {
        char *type = NULL;
        llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
        switch (a) {
            case 0:    sprintf(s, "llll (%s): Coefficients", type);  break; // @out 0 @type llll @digest Continued fraction coefficients
            case 1:    sprintf(s, "llll (%s): Convergents", type);  break; // @out 0 @type llll @digest Continued fraction convergents
            case 2:    sprintf(s, "llll (%s): Errors", type);  break; // @out 0 @type llll @digest Convergent errors
        }
    }
}

void continuedfraction_inletinfo(t_continuedfraction *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void continuedfraction_free(t_continuedfraction *x)
{
	llllobj_obj_free((t_llllobj_object *) x);
}

t_continuedfraction *continuedfraction_new(t_symbol *s, short ac, t_atom *av)
{
	t_continuedfraction *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_continuedfraction *) object_alloc_debug(continuedfraction_class))) {
		// @arg 0 @name numcoeffs @optional 1 @type int @digest Number of Coefficients
		// @description The number of coefficiens to compute. Default is 10.

		long true_ac = attr_args_offset(ac, av);
		attr_args_process(x, ac, av);
        x->n_err_mode = 0;
        x->n_numcoeffs = 10;
        x->n_remove_zero = false;
        x->n_include_semiconvergents = false;
		if (true_ac) {
            x->n_numcoeffs = MAX(1, atom_getlong(av));
		}
		llllobj_obj_setup((t_llllobj_object *) x, 0, "444");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
