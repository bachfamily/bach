/*
 *  mapelem.c
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
	mapelem.c
	
	@name
	bach.mapelem
	
	@realname
	bach.mapelem
 
	@type
	abstraction
	
	@module
	bach
 
	@author
	bachproject
	
	@digest
	Modify llll elements
	
	@description
	Takes an llll and operates a given transformation on each element.
	The transformation is defined via the lambda inlet and outlet.
	
	@discussion
	Elements are iterated (as in <o>bach.iter</o>) and passed to the lambda outlet (the rightmost one).
	They are supposed to be individually modified then by patching, and the modified element is expected
	to be received in the lambda inlet. <br />
	@copy BACH_DOC_LAMBDA
	
	@category
	bach, bach objects, bach llll
 
	@keywords
	map, element, modify, change, each, transform, lambda loop, iterate, iteration
 
	@seealso
	bach.iter, bach.collect, Iterations
	
	@owner
	Andrea Agostini
 */

#include "foundation/llllobj.h"
#include "ext_common.h"
#include "ext_globalsymbol.h"

typedef struct _mapelem
{
	t_llllobj_object 	n_ob;
	long				n_maxdepth;
	long				n_unwrap;
	void				*n_proxy;
	long				n_in;
	llll_cmp_fn			n_deffunc;
	//long				n_this_mapelem;
} t_mapelem;

void mapelem_assist(t_mapelem *x, void *b, long m, long a, char *s);
void mapelem_inletinfo(t_mapelem *x, void *b, long a, char *t);

t_mapelem *mapelem_new(t_symbol *s, short ac, t_atom *av);
void mapelem_free(t_mapelem *x);

void mapelem_bang(t_mapelem *x);
void mapelem_int(t_mapelem *x, t_atom_long v);
void mapelem_float(t_mapelem *x, double v);
void mapelem_anything(t_mapelem *x, t_symbol *msg, long ac, t_atom *av);

long mapelem_func(t_mapelem *x, t_llllelem *a, t_llllelem *b);

DEFINE_STANDARD_MAXDEPTH_SETTER(t_mapelem)

//long mapelem_count;

t_class *mapelem_class;

void C74_EXPORT ext_main(void *moduleRef)
{
	t_class *c;
	
	common_symbols_init();
	llllobj_common_symbols_init();
	
	if (llllobj_check_version(bach_get_current_llll_version()) || llllobj_test()) {
		error("bach: bad installation");
		return;
	}
	
    CLASS_NEW_CHECK_SIZE(c, "bach.mapelem", (method)mapelem_new, (method)mapelem_free, (long) sizeof(t_mapelem), 0L, A_GIMME, 0);
	
    // @method llll @digest Function depends on inlet
    // @description An llll in the first inlet will trigger the mapping via the lambda loop.
    // Elements re-injected in the lambda inlet are re-collected and substituted to the
    // output ones. If no element comes in the lambda inlet, the original element is dropped. <br />
    // An llll in the second inlet is considered to be the "answer" of the lambda loop.
    // Indeed second inlet is a lambda inlet. <br />
    // @copy BACH_DOC_LAMBDA_INLET_MODIFICATION
	class_addmethod(c, (method)mapelem_anything,	"anything",		A_GIMME,	0);
	class_addmethod(c, (method)mapelem_int,			"int",			A_LONG,		0);
	class_addmethod(c, (method)mapelem_float,		"float",		A_FLOAT,	0);
	class_addmethod(c, (method)mapelem_anything,	"list",			A_GIMME,	0);
	
    // @method bang @digest Modify llll
    // @description Performs the modification on the most recently received input llll.
	// @copy BACH_DOC_BANG_LAMBDA_CAVEAT
	class_addmethod(c, (method)mapelem_bang,		"bang",			0);
	
	class_addmethod(c, (method)mapelem_assist,		"assist",		A_CANT,		0);
	class_addmethod(c, (method)mapelem_inletinfo,	"inletinfo",	A_CANT,		0);

	CLASS_ATTR_LONG(c, "maxdepth",	0,	t_mapelem, n_maxdepth);
	CLASS_ATTR_LABEL(c, "maxdepth", 0, "Maximum Depth");
	CLASS_ATTR_BASIC(c, "maxdepth", 0);
	//CLASS_ATTR_STANDARD_MAXDEPTH_ACCESSORS(c, t_find);
    //	@description You can use a <m>maxdepth</m> attribute in order to decide until which level of depth
    //  	the element should be iterated and sent through the lambda outlet. The default is 0, meaning: all levels. <br />
    // 	@copy BACH_DOC_MAXDEPTH
	
	CLASS_ATTR_LONG(c, "unwrap",	0,	t_mapelem, n_unwrap);
	CLASS_ATTR_FILTER_CLIP(c, "unwrap", 0, 1);
	CLASS_ATTR_LABEL(c, "unwrap", 0, "Unwrap");
	CLASS_ATTR_STYLE(c, "unwrap", 0, "onoff");
    //	@description If the <m>unwrap</m> attribute is set to 1, the outermost level of
    // 	parentheses (if present) is removed from the lllls output from the lambda outlet, and is automatically restored
    //	in the lllls received by the lambda inlet. The default is 0.

	
	llllobj_class_add_default_bach_attrs_and_methods(c, LLLL_OBJ_VANILLA);
	
	
	class_register(CLASS_BOX, c);
	mapelem_class = c;
	
	dev_post("bach.mapelem compiled %s %s", __DATE__, __TIME__);
	
	return;
}

void mapelem_bang(t_mapelem *x)
{
//	if (x->n_ob.l_rebuild != 0 || proxy_getinlet((t_object *) x) != 0)
		mapelem_anything(x, _sym_bang, 0, NULL);
//	else {
//		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
//	}
}

void mapelem_int(t_mapelem *x, t_atom_long v)
{
	t_atom outatom;
	atom_setlong(&outatom, v);
	mapelem_anything(x, _sym_int, 1, &outatom);
}

void mapelem_float(t_mapelem *x, double v)
{
	t_atom outatom;
	atom_setfloat(&outatom, v);
	mapelem_anything(x, _sym_float, 1, &outatom);
}

void mapelem_anything(t_mapelem *x, t_symbol *msg, long ac, t_atom *av)
{
	long inlet = proxy_getinlet((t_object *) x);

	if (inlet == 0) {
		//x->n_this_mapelem = mapelem_count++;
		//fprintf(stderr, "mapelem %ld called\n", x->n_this_mapelem);
		
		t_llll *ll, *base_ll;
		t_llllelem **pile, **this_pile, *elem;
		long maxdepth = x->n_maxdepth;
		long depth;

        if (msg != _sym_bang) {
            base_ll = ll = llllobj_parse_clone_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 0);
            if (!ll)
                return;
        } else
            base_ll = ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 0, 1);
 
		
		if (maxdepth == 0) {
			t_llll *cloned = llll_clone(base_ll);
			llll_release(base_ll);
			if (!x->n_unwrap)
				llll_wrap(&cloned, 1);

			llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 1);
			llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, cloned);
			llll_free(cloned);
			
			t_llll *lambda_ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
			if (!x->n_unwrap)
				llll_flatten(lambda_ll, 1, 0);
			llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, lambda_ll, 0);
			llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
			return;
		}
		
		this_pile = pile = (t_llllelem **) bach_newptr(ll->l_depth * sizeof(t_llllelem *));
		elem = ll->l_head;
		depth = 1;
		while (1) {
			long downgrade = 0;
			long depth_guard;
			t_llll *deepest = NULL;
			depth_guard = ll->l_depth - 1;
			while (elem) {
				t_llll *subll = NULL;
				t_hatom *hatom = &elem->l_hatom;
				if ((subll = hatom_getllll(hatom)) &&
					(depth < maxdepth || (maxdepth < 0 && subll->l_depth >= -maxdepth))) {
					if (deepest) {
						llll_upgrade_depth(deepest);
					} else if (downgrade) {
						llll_downgrade_depth(ll);
					}
					*(this_pile++) = elem->l_next;
					depth++;
					ll = subll;
					elem = ll->l_head;
					depth_guard = ll->l_depth - 1;
					downgrade = 0;
					deepest = NULL;
					
					//fprintf(stderr, "mapelem %ld entering sublist - now depth is %ld\n", x->n_this_mapelem, depth);

				} else {
					
					//fprintf(stderr, "mapelem %ld advancing\n", x->n_this_mapelem);

					t_llll *lambda_ll;
					t_llllelem *nextelem = elem->l_next;
					t_llll *outll = llll_get();
                    t_bool unwrapped = false;
					llll_appendhatom_clone(outll, hatom);
                    if (hatom_gettype(&elem->l_hatom) == H_LLLL && x->n_unwrap) {
                        unwrapped = true;
						llll_flatten(outll, 1, 0);
                    }
					llllobj_store_llll((t_object *) x, LLLL_OBJ_VANILLA, llll_get(), 1);
					llllobj_outlet_llll((t_object *) x, LLLL_OBJ_VANILLA, 1, outll);
					lambda_ll = llllobj_get_store_contents((t_object *) x, LLLL_OBJ_VANILLA, 1, 1);
					llll_free(outll);
                    if (unwrapped) {
                        llll_wrap(&lambda_ll, 1);
                    }
					switch (lambda_ll->l_size) {
						case 0: // delete an element
							if (subll) {
								downgrade = !deepest && (downgrade || subll->l_depth == depth_guard);
								llll_free_nocheck(subll);
							}
							if (elem->l_prev) {
								elem->l_prev->l_next = nextelem;
							} else {
								ll->l_head = nextelem;
							}
							if (elem->l_next) {
								elem->l_next->l_prev = elem->l_prev;
							} else {
								ll->l_tail = elem->l_prev;
							}
							ll->l_size--;
							llllelem_chuck(elem);
							llll_free(lambda_ll);
							break;
							
						case 1: // substitute the hatom
							if (!subll) {
								if (lambda_ll->l_depth == 1) { // replace non-sublist with non-sublist
									*hatom = lambda_ll->l_head->l_hatom;
									llll_free(lambda_ll);
								} else { // replace non-sublist with sublist
									t_llll *repl_ll = lambda_ll->l_head->l_hatom.h_w.w_llll;
									hatom_setllll(hatom, repl_ll);
									repl_ll->l_owner = elem;
									if (repl_ll->l_depth > depth_guard) {
										deepest = repl_ll;
										depth_guard = repl_ll->l_depth;
									} else if (repl_ll->l_depth == depth_guard)
										depth_guard++;
									llllelem_chuck(lambda_ll->l_head);
									llll_chuck_nocheck(lambda_ll); // parenthood is broken
								}
							} else {
								if (lambda_ll->l_depth == 1) { // replace sublist with non-sublist
									downgrade = !deepest && (downgrade || subll->l_depth == depth_guard);
									*hatom = lambda_ll->l_head->l_hatom;
									llll_free(lambda_ll);
								} else { // replace sublist with sublist
									t_llll *repl_ll = lambda_ll->l_head->l_hatom.h_w.w_llll;
									hatom_setllll(hatom, repl_ll);
									repl_ll->l_owner = elem;
									if (repl_ll->l_depth > depth_guard) {
										deepest = repl_ll;
										depth_guard = repl_ll->l_depth;
									} else if (repl_ll->l_depth == depth_guard) {
										depth_guard++;
									} else {
										downgrade = downgrade || subll->l_depth == depth_guard; // if we're here, there is no deepest yet!
									}
									llllelem_chuck(lambda_ll->l_head);
									llll_chuck_nocheck(lambda_ll);
								}
								llll_free_nocheck(subll);
							}
							break;
							
						default:
							if (lambda_ll->l_depth - 1 > depth_guard) {
								t_llllelem *lambda_elem;
								long found = 0;
								for (lambda_elem = lambda_ll->l_head; !found &&  lambda_elem; lambda_elem = lambda_elem->l_next) {
									t_llll *lambda_subll = hatom_getllll(&lambda_elem->l_hatom);
									if (lambda_subll && lambda_subll->l_depth == lambda_ll->l_depth - 1) {
										depth_guard = lambda_ll->l_depth;
										deepest = lambda_subll;
										found = 1;
									}
									lambda_elem->l_parent = ll;
								}
								for ( ; lambda_elem; lambda_elem = lambda_elem->l_next)
									lambda_elem->l_parent = ll;
							} else {
								llll_adopt(lambda_ll, ll);
							}

							if (subll) {
								downgrade = !deepest && (downgrade || subll->l_depth == depth_guard);
								llll_free_nocheck(subll);
							}

							if (elem->l_prev) {
								elem->l_prev->l_next = lambda_ll->l_head;
								lambda_ll->l_head->l_prev = elem->l_prev;
							} else {
								ll->l_head = lambda_ll->l_head;
								lambda_ll->l_head->l_prev = NULL;
							}
							if (elem->l_next) {
								elem->l_next->l_prev = lambda_ll->l_tail;
								lambda_ll->l_tail->l_next = elem->l_next;
							} else {
								ll->l_tail = lambda_ll->l_tail;
								lambda_ll->l_tail->l_next = NULL;
							}
							ll->l_size += lambda_ll->l_size - 1;
							llllelem_chuck(elem);
							llll_chuck_nocheck(lambda_ll);
							break;
					}
					elem = nextelem;
				}
			}
			if (deepest) {
				llll_upgrade_depth(deepest);
			} else if (downgrade) {
				llll_downgrade_depth(ll);
			}
			while (!elem && this_pile > pile) {
				elem = *(--this_pile);
			}
			if (!elem)
				break;
			depth = this_pile - pile + 1;
			ll = elem->l_parent;
			
			//fprintf(stderr, "mapelem %ld exiting sublist - now depth is %ld\n", x->n_this_mapelem, depth);

		}

		bach_freeptr(pile);
		llllobj_gunload_llll((t_object *) x, LLLL_OBJ_VANILLA, base_ll, 0);
		llllobj_shoot_llll((t_object *) x, LLLL_OBJ_VANILLA, 0);
 		//mapelem_count--;

		//fprintf(stderr, "mapelem %ld finished\n", x->n_this_mapelem);

	} else {
		llllobj_parse_and_store((t_object *) x, LLLL_OBJ_VANILLA, msg, ac, av, 1);
	}
}


void mapelem_assist(t_mapelem *x, void *b, long m, long a, char *s)
{
	if (m == ASSIST_INLET) {
		switch (a) {
			case 0:	sprintf(s, "llll to Modify");		break; // @in 0 @type llll @digest The llll to be modified
			case 1:	sprintf(s, "llll: Lambda Inlet");	break; // @in 1 @type llll @digest Lambda inlet
                    // @description @copy BACH_DOC_LAMBDA_INLET_MODIFICATION
		}
	} else {
		char *type = NULL;
		llllobj_get_llll_outlet_type_as_string((t_object *) x, LLLL_OBJ_VANILLA, a, &type);
		switch (a) {
			case 0: sprintf(s, "Modified llll (%s)", type);			break; // @out 0 @type llll @digest The modified llll
			case 1:	sprintf(s, "llll (%s): Lambda Outlet", type);	break; // @out 1 @type llll @digest Lambda Outlet
                // @description @copy BACH_DOC_LAMBDA_OUTLET_MODIFICATION
		}
	}
}

void mapelem_inletinfo(t_mapelem *x, void *b, long a, char *t)
{
	if (a)
		*t = 1;
}

void mapelem_free(t_mapelem *x)
{
	object_free_debug(x->n_proxy);
	llllobj_obj_free((t_llllobj_object *) x);
}

t_mapelem *mapelem_new(t_symbol *s, short ac, t_atom *av)
{
	t_mapelem *x = NULL;
	t_max_err err = MAX_ERR_NONE;
	
	if ((x = (t_mapelem *) object_alloc_debug(mapelem_class))) {
		x->n_deffunc = llll_eq_ignoretype;
		x->n_maxdepth = -1;
		attr_args_process(x, ac, av);
		llllobj_obj_setup((t_llllobj_object *) x, 2, "44");
		x->n_proxy = proxy_new_debug((t_object *) x, 1, &x->n_in);
	} else
		error(BACH_CANT_INSTANTIATE);
	
    llllobj_set_current_version_number_and_ss((t_object *) x, LLLL_OBJ_VANILLA);

	if (x && err == MAX_ERR_NONE)
		return x;
	
	object_free_debug(x); // unlike freeobject(), this works even if the argument is NULL
	return NULL;
}
