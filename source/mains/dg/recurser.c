/**
 @file
 recurser.c
 
 @name 
 bach.recurser
 
 @realname 
 bach.recurser
 
 @type
 object
 
 @module
 bach
 
 @author
 bachproject
 
 @digest 
 Series from recurrence relations
 
 @description
 Compute series starting from initial values and a recurrence relation
 
 @discussion
 
 @category
 bach, bach objects, bach math
 
 @keywords
 series, recurrence, calculate, fibonacci

 @seealso
 bach.primeser, bach.geomser, bach.arithmser
 
 @owner
 Daniele Ghisi
 */

#include "llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"
#include "llll_commons_ext.h"
#include "lexpr.h"

typedef struct _recurser
{
	t_llllobj_object 	n_ob;
    t_llll              *n_initial_values;
    t_hatom             n_max;
    t_lexpr             *n_recurrence_lexpr;
    t_atom_long         n_maxcount;


    
	long				n_in;
	void				*n_proxy[4];
	t_bach_atomic_lock	n_lock;
} t_recurser;


void recurser_assist(t_recurser *x, void *b, long m, long a, char *s);
void recurser_inletinfo(t_recurser *x, void *b, long a, char *t);

t_recurser *recurser_new(t_symbol *s, short ac, t_atom *av);
void recurser_free(t_recurser *x);

void recurser_bang(t_recurser *x);
void recurser_int(t_recurser *x, t_atom_long v);
void recurser_float(t_recurser *x, double v);

void recurser_anything(t_recurser *x, t_symbol *msg, short ac, t_atom *av);

t_max_err recurser_parse_llll(t_recurser *x, t_llll *inlist, long inlet, const char *err_str);


t_class *recurser_class;

int T_EXPORT main()
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return 1;
	}
	
	c = class_new("bach.recurser", (method)recurser_new, (method)recurser_free, (short)sizeof(t_recurser), 0L, A_GIMME, 0);
	
	class_addmethod(c, (method)recurser_int,		"int",			A_LONG, 0);

	
	
	
	// @method llll @digest Set initial values
	// @description
    // In first inlet: sets the starting values for the the recurrence, and triggers the output.
	// In second inlet: sets the ending value for the recurrence.<br />
	// In third inlet: sets the recurrence relation.<br />
	// In fourth inlet: sets the maximum number of items.<br />

	// @method number @digest Set start, end, step or maximum number of items
	// @description 
    // In first inlet: sets the starting value for the the recurrence (if a single number, otherwise see <m>llll</m>), and triggers the output.
    // In second inlet: sets the ending value for the recurrence.<br />
    // In third inlet: sets the recurrence relation.<br />
    // In fourth inlet: sets the maximum number of items.<br />
	// Values set to <m>none</m> are calculated according to the other values if possible.
	// If all the parameters are set, the stronger requirement between ending and maximum number of items is respected.
	
	class_addmethod(c, (method)recurser_anything,	"anything",		A_GIMME,	0);
	
	class_addmethod(c, (method)recurser_int,		"int",			A_LONG,		0);
	class_addmethod(c, (method)recurser_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)recurser_anything,	"list",			A_GIMME,	0);
	
	// @method bang @digest Output the series
	// @description A bang outputs the series according to the most recently received parameters.
	class_addmethod(c, (method)recurser_bang,		"bang",			0);
	class_addmethod(c, (method)recurser_assist,	"assist",		A_CANT,		0);
	class_addmethod(c, (method)recurser_inletinfo,	"inletinfo",	A_CANT,		0);
	
	class_register(CLASS_BOX, c);
	recurser_class = c;
	
	llllobj_class_add_default_bach_attrs(c, LLLL_OBJ_VANILLA);
	

	dev_post("bach.recurser compiled %s %s", __DATE__, __TIME__);
	
	return 0;
}


t_llll *llll_recurser(t_llll *start_values, t_hatom end_hatom, t_lexpr *recurrence, t_atom_long maxcount, t_object *culprit)
{
    long recurrence_length = start_values->l_size;
    
    t_hatom vars[LEXPR_MAX_VARS];
    
    t_llll *out_ll = llll_clone(start_values);
    long i = out_ll->l_size;
    char end_direction = (is_hatom_number(&end_hatom) && start_values->l_tail && llll_leq_hatom(&end_hatom, &start_values->l_tail->l_hatom)) ? -1 : 1;
    char still_ok_for_maxcount = (maxcount == 0 || i < maxcount);
    char still_ok_for_end = ((!is_hatom_number(&end_hatom)) || (out_ll->l_tail && (end_direction > 0 ? llll_leq_hatom(&out_ll->l_tail->l_hatom, &end_hatom) : llll_geq_hatom(&out_ll->l_tail->l_hatom, &end_hatom))));
    
    if (maxcount == 0 && !is_hatom_number(&end_hatom)) {
        object_error(culprit, "Error: either the ending value or the maximum number of items must be defined!");
        return out_ll;
    }
        
    for (; still_ok_for_maxcount && still_ok_for_end; ) {
        t_hatom *new_res;
        long j = 0;
        for (t_llllelem *elem = out_ll->l_tail; j < recurrence_length; elem = elem ? elem->l_prev : NULL, j++) {
            if (elem)
                vars[j] = elem->l_hatom;
//                vars[recurrence_length - j - 1] = elem->l_hatom;
            else
                hatom_setlong(&(vars[recurrence_length - j - 1]), 0);
        }
        new_res = lexpr_eval(recurrence, vars);
        
        i++;
        still_ok_for_maxcount = (maxcount == 0 || i < maxcount);
        still_ok_for_end = ((!is_hatom_number(&end_hatom)) || (end_direction > 0 ? llll_leq_hatom(new_res, &end_hatom) : llll_geq_hatom(new_res, &end_hatom)));

        if (still_ok_for_end)
            llll_appendhatom_clone(out_ll, new_res);

        bach_freeptr(new_res);
    }
    
    if (maxcount > 0 && out_ll->l_size > maxcount)
        llll_free(llll_slice(out_ll, maxcount));
    
    pedantic_llll_check(out_ll);
    return out_ll;

/*
    
    double start, end, step, v;
    t_atom_long count;
    step = hatom_getdouble(&step_hatom);
    
    if (hatom_type_is_number(start_type)) {
        start = hatom_getdouble(&start_hatom);
    } else {
        if (!(hatom_type_is_number(end_type))) {
            return outll;
        } else if (maxcount == 1) {
            start = end = hatom_getdouble(&end_hatom);
        } else if (step == 0 || maxcount <= 0) {
            return outll;
        } else {
            end = hatom_getdouble(&end_hatom);
            start = end - step * (maxcount - 1);
        }
    }
    
    if (hatom_type_is_number(end_type)) {
        end = hatom_getdouble(&end_hatom);
    } else if (maxcount == 1) {
        end = start;
    } else {
        if (step == 0 || maxcount <= 0)
            return outll;
        else
            end = step > 0 ? DBL_MAX : -DBL_MAX;
    }
    
    if (step == 0) {
        if (maxcount <= 0) {
            step = start <= end ? 1 : -1;
            maxcount = ATOM_LONG_MAX;
            if (hatom_type_is_number(step_type))
                object_warn((t_object *) culprit, "Step is 0, setting to %lf", step);
        } else {
            maxcount_decides = true;
            step = (end - start) / (maxcount - 1);
            if (hatom_type_is_number(step_type))
                object_warn((t_object *) culprit, "Step is 0, setting to %lf", step);
        }
    } else if (maxcount <= 0)
        maxcount = ATOM_LONG_MAX;
    
    if (!maxcount_decides) {
        if (step > 0) {
            for (v = start, count = 0; v <= end && count < maxcount; v += step, count++)
                llll_appenddouble(outll, v, 0, WHITENULL_llll);
        } else {
            for (v = start, count = 0; v >= end && count < maxcount; v += step, count++)
                llll_appenddouble(outll, v, 0, WHITENULL_llll);
        }
    } else {
        //if (step > 0) {
        for (v = start, count = 0; count < maxcount; v += step, count++)
            llll_appenddouble(outll, v, 0, WHITENULL_llll);
        //} else {
        //    for (v = start, count = 0; count < maxcount; v += step, count++)
        //        llll_appenddouble(outll, v, 0, WHITENULL_llll);
        //}
        outll->l_tail->l_hatom.h_w.w_double = end;
    }
 
 */
}


void recurser_bang(t_recurser *x)
{	
	if (x->n_ob.l_rebuild != 0) {
		x->n_ob.l_rebuild = 0;
        if (x->n_recurrence_lexpr)
            llllobj_gunload_llll((t_object *)x, LLLL_OBJ_VANILLA, llll_recurser(x->n_initial_values, x->n_max, x->n_recurrence_lexpr, x->n_maxcount, (t_object *) x), 0);
	}
	llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
}


void recurser_int(t_recurser *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	recurser_anything(x, _sym_int, 1, &outatom);
}

void recurser_float(t_recurser *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	recurser_anything(x, _sym_float, 1, &outatom);
}

void recurser_anything(t_recurser *x, t_symbol *msg, short ac, t_atom *av)
{
	t_max_err err;
    long inlet = proxy_getinlet((t_object *) x);
	t_llll *inlist = llllobj_parse_llll((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, LLLL_PARSE_CLONE);

	if (!inlist)
		return;
	err = recurser_parse_llll(x, inlist, inlet, "Invalid input llll");
	llll_free_nocheck(inlist); // because it can contain A_NOTHING elements
	if (err)
		return;
	x->n_ob.l_rebuild = 1;
	if (inlet == 0)
		recurser_bang(x);
}

t_max_err recurser_parse_llll(t_recurser *x, t_llll *inlist, long inlet, const char *err_str)
{
	t_llllelem *elem;
	long i;
	t_hatom nothing;
	nothing.h_type = H_NOTHING;
	
	if ((inlist->l_depth > 1 || inlist->l_size < 1) && inlet != 2) {
		object_error((t_object *) x, "Invalid input llll: wrong structure");
		return MAX_ERR_GENERIC;
	}
	
	for (i = 0, elem = inlist->l_head; elem; elem = elem->l_next, i++) {
		if (!hatom_is_number(&elem->l_hatom) && hatom_getsym(&elem->l_hatom) != _sym_none && inlet != 2) {
			object_error((t_object *) x, "Invalid input llll: %s symbol unknown", hatom_getsym(&elem->l_hatom)->s_name);
			return MAX_ERR_GENERIC;
		}
	}
	
    bach_atomic_lock(&x->n_lock);
    switch (inlet) {
        case 0:
            llll_free(x->n_initial_values);
            x->n_initial_values = llll_clone(inlist);
            break;

        case 1:
            if (inlist->l_head)
                x->n_max = inlist->l_head->l_hatom;
            break;

        case 2:
        {
            t_atom *av = NULL;
            long ac = llll_deparse(inlist, &av, 0, LLLL_D_PARENS);
            if (x->n_recurrence_lexpr)
                lexpr_free(x->n_recurrence_lexpr);
            if (!(x->n_recurrence_lexpr = lexpr_new(ac, av, 0, NULL, (t_object *) x)))
                object_error((t_object *)x, "Error: wrong recurrence expression!");
            bach_freeptr(av);
        }
            break;

        case 3:
            if (inlist->l_head)
                x->n_maxcount = hatom_getlong(&inlist->l_head->l_hatom);
            break;

        default:
            break;
    }
    bach_atomic_unlock(&x->n_lock);

/*	for (i = 0; i < inlet; i++)
		llll_prependhatom(inlist, &nothing, 0, WHITENULL_llll);
	
	elem = inlist->l_head;
	bach_atomic_lock(&x->n_lock);
	if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
		x->n_min = elem->l_hatom;
	if ((elem = elem->l_next)) {
		if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
			x->n_max = elem->l_hatom;
		if ((elem = elem->l_next)) {
			if (hatom_gettype(&elem->l_hatom) != H_NOTHING)
				x->n_step = elem->l_hatom;
			if ((elem = elem->l_next))
				x->n_maxcount = hatom_getlong(&elem->l_hatom);
		}
	}
	bach_atomic_unlock(&x->n_lock);
*/
    return MAX_ERR_NONE;
}

void recurser_assist(t_recurser *x, void *b, long m, long a, char *s)
{	
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0: sprintf(s, "llll: Initial Values");			break;	// @in 0 @type llll @digest Initial values for recurrence
			case 1: sprintf(s, "number/pitch/none: Ending Value");			break;	// @in 1 @type number/pitch/none @digest Ending value for recurrence
			case 2: sprintf(s, "symbol/llll: Recurrence relation");					break;	// @in 2 @type symbol/llll @digest Recurrence relation
																				// @description The recurrence relation must be defined as in <o>bach.expr</o> argument syntax.
			case 3: sprintf(s, "int: Maximum Number of Elements");		break;	// @in 3 @type int/none @digest Maximum number of items
		}
	}
	else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		sprintf(s, "llll (%s)", type); // @out 0 @type llll @digest Series from recurrence relation
	}
}

void recurser_inletinfo(t_recurser *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void recurser_free(t_recurser *x)
{
	long i;
	for (i = 3; i > 0; i--)
		object_free_debug(x->n_proxy[i]);
    if (x->n_recurrence_lexpr)
        lexpr_free(x->n_recurrence_lexpr);
    if (x->n_initial_values)
        llll_free(x->n_initial_values);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_recurser *recurser_new(t_symbol *s, short ac, t_atom *av)
{
	t_recurser *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	long i;
	
	if ((x = (t_recurser *) object_alloc_debug(recurser_class))) {
		// @arg 0 @name wrapped_initial_values @optional 1 @type llll @digest Initial values for recurrence
		// @description The initial values for the recurrence, wrapped in a level of parenthesis. Default is <b>[0]</b>

		// @arg 1 @name end @optional 1 @type number/none @digest Ending value
		// @description The ending value for the series, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>none</m>.

		// @arg 2 @name recurrence @optional 1 @type symbol @digest Recurrence relation
		// @description The recurrence relation as a single symbol (use double quotes if needed). Default is <b>0</b>.

		// @arg 3 @name max_items @optional 1 @type int/none @digest Maximum number of items
		// @description The maximum number of items in the output llll, which can also be the <m>none</m> symbol (see <m>llll</m> message).
		// Default is <m>1000</m>.

		long true_ac = attr_args_offset(ac, av);
		attr_args_process(x, ac, av);
        x->n_maxcount = 1000;
		for (i = 3; i > 0; i--)
			x->n_proxy[i] = proxy_new_debug((t_object *) x, i, &x->n_in);
		if (true_ac) {
            long atom_idx = 0;

            bach_atomic_lock(&x->n_lock);

            if (atom_gettype(av) != A_SYM) {
                // easy case, it's a single number
                x->n_initial_values = llll_get();
                llll_appendatom(x->n_initial_values, av);
            } else {
                // finding the corresponding symbol with closed bracket
                for (; atom_idx < ac; atom_idx++) {
                    if (atom_gettype(av + atom_idx) == A_SYM && (strstr(atom_getsym(av+atom_idx)->s_name, ")") || strstr(atom_getsym(av+atom_idx)->s_name, "]")))
                        break;
                }
                x->n_initial_values = llll_parse(atom_idx + 1, av);
                llll_flat(x->n_initial_values, 0, 1);
            }

            atom_idx ++;
            if (atom_idx < ac)
                hatom_setatom(&x->n_max, av + atom_idx);

            atom_idx ++;
            if (atom_idx < ac) {
                if (!(x->n_recurrence_lexpr = lexpr_new(1, av + atom_idx, 0, NULL, (t_object *) x)))
                    object_error((t_object *)x, "Error: wrong recurrence expression!");
            }

            atom_idx ++;
            if (atom_idx < ac)
                x->n_maxcount = atom_gettype(av + atom_idx) == A_SYM ? 0 : atom_getlong(av + atom_idx);

            
            bach_atomic_unlock(&x->n_lock);
            
            x->n_ob.l_rebuild = 1;
		}
		llllobj_obj_setup((t_llllobj_object *) x, 0, "4");
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
