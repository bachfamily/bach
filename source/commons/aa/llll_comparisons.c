/*
 *  llll_comparisons.c
 *  bach
 *
 *  Created by andrea agostini on 25/4/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "llll_comparisons.h"

// <=
long llll_leq_elem(void *dummy, t_llllelem *a, t_llllelem *b) // dummy is never used, but it's there for llll_mergesort
{
	return a && b && llll_leq_hatom(&a->l_hatom, &b->l_hatom);	
}

long llll_leq_elem_matchtype(void *dummy, t_llllelem *a, t_llllelem *b) // dummy is never used, but it's there for llll_mergesort
{
	return a && b && llll_leq_hatom_matchtype(&a->l_hatom, &b->l_hatom);	
}


long llll_leq_hatom(t_hatom *a_hatom, t_hatom *b_hatom)
{
	long a_type, b_type; 
	
	if (!a_hatom || !b_hatom)
		return 0;
	
	a_type = a_hatom->h_type;
	b_type = b_hatom->h_type;
	
	if (hatom_type_is_number(a_type)) {
		if (hatom_type_is_number(b_type)) {
			switch (a_type) {
				case H_LONG:
					switch (b_type) {
						case H_LONG:
							return a_hatom->h_w.w_long <= b_hatom->h_w.w_long;
							break;
						case H_RAT:
							return ((t_atom_longlong) a_hatom->h_w.w_long) * b_hatom->h_w.w_rat.r_den <= b_hatom->h_w.w_rat.r_num;
							break;
						case H_DOUBLE:
							return a_hatom->h_w.w_long <= b_hatom->h_w.w_double;
							break;
                        case H_PITCH:
                            return a_hatom->h_w.w_long <= b_hatom->h_w.w_pitch.toMC();
                            break;
					}
					break;
				case H_RAT:
					switch (b_type) {
						case H_LONG:
							return a_hatom->h_w.w_rat.r_num <= ((t_atom_longlong) b_hatom->h_w.w_long) * a_hatom->h_w.w_rat.r_den;
							break;
						case H_RAT:
							return ((t_atom_longlong) a_hatom->h_w.w_rat.r_num) * b_hatom->h_w.w_rat.r_den <= ((t_atom_longlong) b_hatom->h_w.w_rat.r_num) * a_hatom->h_w.w_rat.r_den;
							break;
						case H_DOUBLE:
							return a_hatom->h_w.w_rat.r_num <= b_hatom->h_w.w_double * a_hatom->h_w.w_rat.r_den;
							break;
                        case H_PITCH:
                            return a_hatom->h_w.w_rat <= b_hatom->h_w.w_pitch.toMC();
                            break;
					}
					break;
				case H_DOUBLE:
					switch (b_type) {
						case H_LONG:
							return a_hatom->h_w.w_double <= b_hatom->h_w.w_long;
							break;
						case H_RAT:
							return a_hatom->h_w.w_double * b_hatom->h_w.w_rat.r_den <= b_hatom->h_w.w_rat.r_num;
							break;
						case H_DOUBLE:
							return a_hatom->h_w.w_double <= b_hatom->h_w.w_double;
							break;
                        case H_PITCH:
                            return a_hatom->h_w.w_double <= double(b_hatom->h_w.w_pitch.toMC());
                            break;
					}
					break;
                case H_PITCH:
                    switch (b_type) {
                        case H_LONG:
                            return a_hatom->h_w.w_pitch.toMC() <= b_hatom->h_w.w_long;
                            break;
                        case H_RAT:
                            return a_hatom->h_w.w_pitch.toMC() <= b_hatom->h_w.w_rat;
                            break;
                        case H_DOUBLE:
                            return double(a_hatom->h_w.w_pitch.toMC()) <= double(b_hatom->h_w.w_double);
                            break;
                        case H_PITCH:
                            return a_hatom->h_w.w_pitch <= b_hatom->h_w.w_pitch;
                            break;
                    }
			}
		} else
			return 1;
	}
	
	if (hatom_type_is_number(b_type)) // if a is not a number and b is a number, they must be swapped
		return 0;
	
	//if they're both non-numbers:
	
	if (a_type == H_SYM) {
		if (b_type == H_SYM)
			return strcmp(hatom_getsym(a_hatom)->s_name, hatom_getsym(b_hatom)->s_name) <= 0;
		return 1;
	} else if (b_type == H_SYM)
		return 0;
	
	if (a_type == H_LLLL) {
		if (b_type == H_LLLL)
			return llll_leq(a_hatom->h_w.w_llll, b_hatom->h_w.w_llll);
		else
			return 1;
	} else if (b_type == H_LLLL)
		return 0;
	
    if (a_type == H_FUNCTION) {
        if (b_type == H_FUNCTION)
            return ((t_ptr_size) a_hatom->h_w.w_func) <= ((t_ptr_size) b_hatom->h_w.w_func);
        else
            return 1;
    }
    
    if (a_type == H_OBJ && b_type == H_OBJ) // if we're here, this should be always the case
        return ((t_ptr_size) a_hatom->h_w.w_obj) <= ((t_ptr_size) b_hatom->h_w.w_obj);
    
	return 1; // this should never be reached
}

long llll_leq_hatom_matchtype(t_hatom *a_hatom, t_hatom *b_hatom)
{
	long a_type, b_type;
	
	if (!a_hatom || !b_hatom)
		return 0;
	
	a_type = a_hatom->h_type;
	b_type = b_hatom->h_type;
	
    switch (a_type) {
        case H_LONG:
            switch (b_type) {
                case H_LONG:
                    return a_hatom->h_w.w_long <= b_hatom->h_w.w_long;
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case H_RAT:
            switch (b_type) {
                case H_LONG:
                    return 0;
                    break;
                case H_RAT:
                    return ((t_atom_longlong) a_hatom->h_w.w_rat.r_num) * b_hatom->h_w.w_rat.r_den <= ((t_atom_longlong) b_hatom->h_w.w_rat.r_num) * a_hatom->h_w.w_rat.r_den;
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case H_DOUBLE:
            switch (b_type) {
                case H_LONG:
                case H_RAT:
                    return 0;
                    break;
                case H_DOUBLE:
                    return a_hatom->h_w.w_double <= b_hatom->h_w.w_double;
                    break;
                default:
                    return 1;
                    break;
            }
            break;
        case H_PITCH:
            switch (b_type) {
                case H_LONG:
                case H_RAT:
                case H_DOUBLE:
                    return 0;
                    break;
                case H_PITCH:
                    return a_hatom->h_w.w_pitch <= b_hatom->h_w.w_pitch;
                    break;
                default:
                    return 1;
                    break;
            }
        case H_SYM:
            switch (b_type) {
                case H_LONG:
                case H_RAT:
                case H_DOUBLE:
                case H_PITCH:
                    return 0;
                    break;
                case H_SYM:
                    return strcmp(hatom_getsym(a_hatom)->s_name, hatom_getsym(b_hatom)->s_name) <= 0;
                default:
                    break;
            }
        case H_LLLL:
            switch (b_type) {
                case H_LONG:
                case H_RAT:
                case H_DOUBLE:
                case H_PITCH:
                case H_SYM:
                    return 0;
                    break;
                case H_LLLL:
                    return llll_leq(a_hatom->h_w.w_llll, b_hatom->h_w.w_llll);
                default:
                    return 1;
            }
        case H_FUNCTION:
            switch (b_type) {
                case H_LONG:
                case H_RAT:
                case H_DOUBLE:
                case H_PITCH:
                case H_SYM:
                case H_LLLL:
                    return 0;
                    break;
                case H_FUNCTION:
                    return ((t_ptr_size) a_hatom->h_w.w_func) <= ((t_ptr_size) b_hatom->h_w.w_func);
                default:
                    return 1;
            }
        case H_OBJ:
            switch (b_type) {
                case H_OBJ:
                    return ((t_ptr_size) a_hatom->h_w.w_obj) <= ((t_ptr_size) b_hatom->h_w.w_obj);
                    break;
                default:
                    return 0;
            }
        default:
            return 1; // this one should never be reached
    }
}

long llll_geq_hatom(t_hatom *a_hatom, t_hatom *b_hatom)
{
	return llll_leq_hatom(b_hatom, a_hatom);
}

long llll_geq_hatom_matchtype(t_hatom *a_hatom, t_hatom *b_hatom)
{
	return llll_leq_hatom_matchtype(b_hatom, a_hatom);
}

// >=
long llll_geq_elem(void *dummy, t_llllelem *a, t_llllelem *b) 
{
	return a && b && llll_leq_hatom(&b->l_hatom, &a->l_hatom);
}

long llll_geq_elem_matchtype(void *dummy, t_llllelem *a, t_llllelem *b) 
{
	return a && b && llll_leq_hatom_matchtype(&b->l_hatom, &a->l_hatom);
}

long llll_gt_elem(void *dummy, t_llllelem *a, t_llllelem *b)
{
	return a && b && !llll_leq_hatom(&a->l_hatom, &b->l_hatom);
}

long llll_lt_elem(void *dummy, t_llllelem *a, t_llllelem *b)
{
	return a && b && !llll_leq_hatom(&b->l_hatom, &a->l_hatom);
}

long llll_gt_hatom(t_hatom *a_hatom, t_hatom *b_hatom)
{
	return !llll_leq_hatom(a_hatom, b_hatom);
}

long llll_lt_hatom(t_hatom *a_hatom, t_hatom *b_hatom)
{
	return !llll_leq_hatom(b_hatom, a_hatom);
}


// == (matchtype 1)
long llll_eq_matchtype(t_llll *ll1, t_llll *ll2)
{
	t_llllelem *el1, *el2;
	if (!ll1 || !ll2)
		return 0;
	
	for (el1 = ll1->l_head, el2 = ll2->l_head; el1 && el2; el1 = el1->l_next, el2 = el2->l_next) {
		if (!llll_eq_elem_matchtype(el1, el2))
			return 0;
	}
	if (el1 || el2)
		return 0;
	else
		return 1;
}

// == (matchtype 0)
long llll_eq_ignoretype(t_llll *ll1, t_llll *ll2)
{
	t_llllelem *el1, *el2;
	if (!ll1 || !ll2)
		return 0;
	
	for (el1 = ll1->l_head, el2 = ll2->l_head; el1 && el2; el1 = el1->l_next, el2 = el2->l_next) {
		if (!llll_eq_elem_ignoretype(el1, el2))
			return 0;
	}
	if (el1 || el2)
		return 0;
	else
		return 1;
}

long llll_neq_matchtype(t_llll *ll1, t_llll *ll2)
{
	return !llll_eq_matchtype(ll1, ll2);
}

long llll_neq_ignoretype(t_llll *ll1, t_llll *ll2)
{
	return !llll_eq_ignoretype(ll1, ll2);
}

// == (matchtype 0)
long llll_eq_hatom_ignoretype(t_hatom *h1, t_hatom *h2)
{
	if (!h1 || !h2)
		return 0;
	switch (h1->h_type) {
		case H_LLLL:
			if (h2->h_type != H_LLLL || !llll_eq_ignoretype(hatom_getllll(h1), hatom_getllll(h2))) 
				return 0;
			break;
		case H_SYM:
			if (h2->h_type != H_SYM || h1->h_w.w_sym != h2->h_w.w_sym) 
				return 0;
			break;
		case H_FUNCTION:
			if (h2->h_type != H_FUNCTION || h1->h_w.w_func != h2->h_w.w_func)
				return 0;
			break;
        case H_OBJ:
            if (h2->h_type != H_OBJ || h1->h_w.w_obj != h2->h_w.w_obj)
                return 0;
            break;
		default:
            if (!hatom_is_number(h2))
                return 0;
            switch (h1->h_type) {
                case H_LONG:
                    switch (h2->h_type) {
                        case H_LONG:
                            return h1->h_w.w_long == h2->h_w.w_long;
                            break;
                        case H_RAT:
                            return hatom_getrational(h1) == h2->h_w.w_rat;
                            break;
                        case H_DOUBLE:
                            return hatom_getdouble(h1) == h2->h_w.w_double;
                            break;
                        case H_PITCH:
                            return hatom_getrational(h1) == hatom_getrational(h2);
                            break;
                        default:
                            return 0;
                            break;
                    }
                    break;
                case H_RAT:
                    switch (h2->h_type) {
                        case H_LONG:
                            return h1->h_w.w_rat == hatom_getrational(h2);
                            break;
                        case H_RAT:
                            return h1->h_w.w_rat == h2->h_w.w_rat;
                            break;
                        case H_DOUBLE:
                            return hatom_getdouble(h1) == h2->h_w.w_double;
                            break;
                        case H_PITCH:
                            return h1->h_w.w_rat == hatom_getrational(h2);
                            break;
                    }
                    break;
                case H_DOUBLE:
                    switch (h2->h_type) {
                        case H_LONG:
                            return h1->h_w.w_double == hatom_getdouble(h2);
                            break;
                        case H_RAT:
                            return h1->h_w.w_double == hatom_getdouble(h2);
                            break;
                        case H_DOUBLE:
                            return h1->h_w.w_double == h2->h_w.w_double;
                            break;
                        case H_PITCH:
                            return h1->h_w.w_double == hatom_getdouble(h2);
                            break;
                    }
                    break;
                case H_PITCH:
                    switch (h2->h_type) {
                        case H_LONG:
                            return hatom_getlong(h1) == h2->h_w.w_long;
                            break;
                        case H_RAT:
                            return hatom_getrational(h1) == h2->h_w.w_rat;
                            break;
                        case H_DOUBLE:
                            return hatom_getdouble(h1) == h2->h_w.w_double;
                            break;
                        case H_PITCH:
                            return h1->h_w.w_pitch == h2->h_w.w_pitch;
                            break;
                    }
                default:
                    break;
            }
			break;
	}
	return 1;
}

// == (matchtype 0)
long llll_eq_elem_ignoretype(t_llllelem *el1, t_llllelem *el2)
{
	return el1 && el2 && llll_eq_hatom_ignoretype(&el1->l_hatom, &el2->l_hatom);
}

// == (matchtype 1)
long llll_eq_hatom_matchtype(t_hatom *h1, t_hatom *h2)
{
	if (!h1 || !h2 || h1->h_type != h2->h_type)
		return 0;
	if (h1->h_type == H_LLLL) {
		if (!llll_eq_matchtype(hatom_getllll(h1), hatom_getllll(h2)))
			return 0;
	} else switch (h1->h_type) {
		case H_LONG:
		case H_LLLL:
		case H_OBJ:
        case H_FUNCTION:
		case H_SYM:
			if (h1->h_w.w_long != h2->h_w.w_long)
				return 0;
			break;
		case H_DOUBLE:
			if (h1->h_w.w_double != h2->h_w.w_double)
				return 0;
			break;
		case H_RAT:
        case H_PITCH:
#ifdef C74_X64
			if (h1->h_w.w_rat.r_den != h2->h_w.w_rat.r_den || h1->h_w.w_rat.r_num != h2->h_w.w_rat.r_num)
				return 0;
#else
			if (h1->h_w.w_whole != h2->h_w.w_whole)
				return 0;
#endif
			break;
	}
	return 1;
}

// == (matchtype 1)
long llll_eq_elem_matchtype(t_llllelem *el1, t_llllelem *el2)
{
	return el1 && el2 && llll_eq_hatom_matchtype(&el1->l_hatom, &el2->l_hatom);
}


long llll_leq(t_llll *ll1, t_llll *ll2)
{
	t_llllelem *el1, *el2;
	if (!ll1 || !ll2)
		return 0;
	for (el1 = ll1->l_head, el2 = ll2->l_head; el1 && el2; el1 = el1->l_next, el2 = el2->l_next) {
		if (!llll_eq_elem_ignoretype(el1, el2))
			return llll_leq_elem(NULL, el1, el2);
	}
	return el1 ? 0 : 1;
}

long llll_geq(t_llll *ll1, t_llll *ll2)
{
	return llll_leq(ll2, ll1);
}

long llll_lt(t_llll *ll1, t_llll *ll2)
{
	return ll1 && ll2 && !llll_leq(ll2, ll1);
}

long llll_gt(t_llll *ll1, t_llll *ll2)
{
	return ll1 && ll2 && !llll_leq(ll1, ll2);
}
