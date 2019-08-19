#include "llll_commons_ext.h" 
#include "llll_commons.h"
#include <ext_common.h>
#include <stdarg.h>
#include <string.h>
#include "llll_commonsyms.h"
#ifdef BACH_MAX
#include "ext_strings.h"
#endif 
#include "notation.h"

void tolower_strip_spaces_doublequotes_and_regular(const char *source, char *dest, long dest_size)
{
    long len = strlen(source), j = 0;
    for (long i = 0; i < len && j < dest_size-1; i++) {
        if (source[i] == ' ') {
            // nothing to do
        } else if (source[i] == '"' && (i == 0 || i == len -1)) {
            // nothing to do
        } else {
            dest[j++] = tolower(source[i]);
        }
    }
    dest[j] = 0;

    long L = strlen(dest);
    if (L > 9 && (strcmp(dest+L-8, " Regular") == 0 || strcmp(dest+L-8, " regular") == 0))
        dest[L-8] = 0;
}


// Test if font names are equal
// also accounts for case insensitive matching, starting and trailing double quotes, spaces mismatch, and "Regular" symbol being placed after the font name
int fontnameeq(const char * str1, const char * str2)
{
    char temp1[2048];
    char temp2[2048];
    
    tolower_strip_spaces_doublequotes_and_regular(str1, temp1, 2048);
    tolower_strip_spaces_doublequotes_and_regular(str2, temp2, 2048);

    // plain test (case insensitive)
    if (strcmp(temp1, temp2) == 0)
        return true;

    return false;
}






char true_hatom_eq(t_hatom *a, t_hatom *b)
{
    if (a->h_type != b->h_type)
        return 0;
    if (a->h_type == H_LLLL) {
        return llll_eq_ignoretype(hatom_getllll(a), hatom_getllll(b));
    } else {
        return hatom_eq(a, b);
    }
}

char is_hatom_in_llll_root_level(t_hatom *hatom, t_llll *ll)
{
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
        if (true_hatom_eq(hatom, &elem->l_hatom))
			return 1;
	}
	return 0;
}

char is_hatom_number(t_hatom *hatom)
{
	if (hatom_gettype(hatom) == H_LONG || hatom_gettype(hatom) == H_DOUBLE || hatom_gettype(hatom) == H_RAT)
		return true;
	return false;
}

t_symbol *atom_to_symbol(t_atom *atom){
	if (atom_gettype(atom) == A_SYM)
		return atom_getsym(atom);
	else if (atom_gettype(atom) == A_LONG) {
		char str[100];
		snprintf_zero(str, 100, "%ld", atom_getlong(atom));
		return gensym(str);
	} else if (atom_gettype(atom) == A_FLOAT) {
		char str[100];
		snprintf_zero(str, 100, "%f", atom_getfloat(atom));
		return gensym(str);
	} else
		return NULL;
}

char is_atom_number(t_atom *atom){
	if (atom_gettype(atom) == A_LONG || atom_gettype(atom) == A_FLOAT)
		return true;
	return false;
}

void clip_atom(t_atom *av, double min, double max){
	if (atom_gettype(av) == A_LONG)
		atom_setlong(av, CLAMP(atom_getlong(av), min, max));
	else if (atom_gettype(av) == A_FLOAT)
		atom_setfloat(av, CLAMP(atom_getfloat(av), min, max));
}

void atom_min(t_atom *av, double val){
	if (atom_gettype(av) == A_LONG)
		atom_setlong(av, MIN(atom_getlong(av), val));
	else if (atom_gettype(av) == A_FLOAT)
		atom_setfloat(av, MIN(atom_getfloat(av), val));
}

void atom_max(t_atom *av, double val){
	if (atom_gettype(av) == A_LONG)
		atom_setlong(av, MAX(atom_getlong(av), val));
	else if (atom_gettype(av) == A_FLOAT)
		atom_setfloat(av, MAX(atom_getfloat(av), val));
}


void llll_wrap_once(t_llll **inlist) {
	t_llll *outlist;
	if (inlist) {
		outlist = llll_get();
		llll_appendllll(outlist, *inlist, 0, WHITENULL_llll);
	} else {
		outlist = llll_get();
	}
	*inlist = outlist;
}

t_llll *llll_behead(t_llll *inlist) {
	if (inlist && (inlist->l_head)) {
		llll_destroyelem(inlist->l_head);
	}
	return inlist; // dummy but needed somewhere here and there
}

t_llll *llll_betail(t_llll *inlist) {
	if (inlist && (inlist->l_tail)) {
		llll_destroyelem(inlist->l_tail);
	}
	return inlist; // dummy but needed somewhere here and there
}

/*
long llllelem_get_depth(t_llllelem *elem){
	long d = 1;
	t_llllelem *temp = elem;
	while (temp->l_parent && temp->l_parent->l_owner) {
		d++;
		temp = temp->l_parent->l_owner;
	}
	return d;
}
*/

long llllelem_getpos(t_llllelem *elem){
	t_llllelem *temp = elem;
	long pos = 0;

	if (!elem)
		return -1;

	while (temp){
		pos++;
		temp = temp->l_prev;
	}
	return pos;
}

t_llll *llll_subllll(t_llllelem *from, t_llllelem *to) 
{
	t_llll *ll;
	t_llllelem *elem;
    
    if (!from || !to)
        return llll_get();

	if (from->l_parent != to->l_parent || !from->l_parent)
		return llll_get();
	
	ll = llll_get();
	for (elem = from; elem; elem = elem->l_next) {
		llll_appendhatom_clone(ll, &elem->l_hatom, 0, WHITENULL_llll);
		if (elem == to)
			break;
	}
	return ll;
}

void llll_trim(t_llll *in_llll, long num_elems) {
	// keeps just <num_elems> elements of the list

	if (!in_llll || !in_llll->l_head) 
		return;

	if (num_elems >= (long)in_llll->l_size)
		return;
		
	while ((long)in_llll->l_size > num_elems)
		llll_betail(in_llll);
}


t_llll *llll_abs_diff_of_plain_lllls_as_double(t_llll *llll1, t_llll *llll2)
{
    t_llll *out = llll_get();
    t_llllelem *elem1, *elem2;
    for (elem1 = llll1->l_head, elem2 = llll2->l_head; elem1 && elem2; elem1 = elem1->l_next, elem2 = elem2->l_next) {
        llll_appenddouble(out, fabs(hatom_getdouble(&elem1->l_hatom) - hatom_getdouble(&elem2->l_hatom)));
    }
    return out;
}


double llll_euclidean_distance_of_plain_rat_lllls(t_llll *llll1, t_llll *llll2) {
	t_llllelem *elem1, *elem2;
	double sum = 0.; 
	long count = 0; 
	for (elem1 = llll1->l_head, elem2 = llll2->l_head; elem1 && elem2; elem1 = elem1->l_next, elem2 = elem2->l_next) {
		double this_diff = rat2double(rat_rat_diff(hatom_getrational(&elem1->l_hatom), hatom_getrational(&elem2->l_hatom)));
		sum += this_diff * this_diff;
		count++;
	}
	return sqrt(sum);
}

char is_double_in_llll_first_level_with_tolerance(t_llll *list, double num, double tolerance){
	t_llllelem *elem;
	if (list && list->l_head)
		for (elem = list->l_head; elem; elem = elem->l_next)
			if (fabs(hatom_getdouble(&elem->l_hatom) - num) < tolerance)
				return true;

	return false;
}

void llll_chain_clone(t_llll *where, t_llll *what){
	t_llllelem *elem;
	if (!what) return;
	for (elem = what->l_head; elem; elem = elem->l_next)
		llll_appendhatom_clone(where, &elem->l_hatom, 0, WHITENULL_llll);
}

void llll_chain_clone_some_indices(t_llll *where, t_llll *what, t_llll *which_indices){
	t_llllelem *elem;
	long i;
	if (!what) 
		return;
	for (elem = what->l_head, i = 1; elem; elem = elem->l_next, i++)
		if (!which_indices || is_long_in_llll_first_level(which_indices, i))
			llll_appendhatom_clone(where, &elem->l_hatom, 0, WHITENULL_llll);
}


void llll_filter_zeros(t_llll *ll) {
	// we filter the zeros 
	t_llllelem *elem = ll->l_head; t_llllelem *tmpel;
	while (elem) {
		tmpel = elem->l_next;
		if (hatom_getrational(&elem->l_hatom).r_num == 0)
			llll_destroyelem(elem);
		elem = tmpel;
	}
}

t_rational llll_gcd_of_plain_rat_llll(t_llll *llll_of_rationals) {
	// we filter the zeros gcd
	if (!llll_of_rationals || !llll_of_rationals->l_head)
		return long2rat(1); 
	else {	
		t_rational gcd_out = long2rat(1);
		t_llllelem *elem = llll_of_rationals->l_head;
		while (elem) {
			gcd_out = rat_gcd(gcd_out, hatom_getrational(&elem->l_hatom));
			elem = elem->l_next;
		}
	  return gcd_out;
  }
}

void llll_filter_zeros_and_negatives(t_llll *ll) {
	// we filter the zeros (and the negatives, which - in turn - should never appear)
	t_llllelem *elem = ll->l_head; t_llllelem *tmpel;
	while (elem) {
		tmpel = elem->l_next;
		if (hatom_getrational(&elem->l_hatom).r_num <= 0)
			llll_destroyelem(elem);
		elem = tmpel;
	}
}

// ll must be plain, window_in_samples must be odd
t_llll *llll_meanfilter(t_llll *ll, long window_in_samples)
{
	t_llll *out = llll_get();
	t_llllelem *left, *right, *elem;
	long half_window = window_in_samples / 2;
	long j, i;
	for (i = 0, elem = ll->l_head; elem; elem = elem->l_next, i++) {
		double sum = 0;
		long count = 1;
		left = elem->l_prev;
		right = elem->l_next;
		sum += hatom_getdouble(&elem->l_hatom);
		for (j = 0; j < half_window && left; j++) {
			sum += hatom_getdouble(&left->l_hatom);
			count++;
			left = left->l_prev;
		}
		for (j = 0; j < half_window && right; j++) {
			sum += hatom_getdouble(&right->l_hatom);
			count++;
			right = right->l_next;
		}
		llll_appenddouble(out, sum/count, 0, WHITENULL_llll);
	} 
	return out;
}

t_llll *llll_medianfilter(t_llll *ll, long window_in_samples)
{
	// COULD BE FASTER!!!
	t_llll *out = llll_get();
	t_llllelem *left, *right, *elem, *okelem;
	long half_window = window_in_samples / 2;
	long j, i;
	for (i = 0, elem = ll->l_head; elem; elem = elem->l_next, i++) {
		long idx = 1;
		t_llll *sub = llll_get();
		left = elem->l_prev;
		right = elem->l_next;
		llll_appenddouble(sub, hatom_getdouble(&elem->l_hatom), 0, WHITENULL_llll);
		for (j = 0; j < half_window && left; j++, left = left->l_prev) 
			llll_appenddouble(sub, hatom_getdouble(&left->l_hatom), 0, WHITENULL_llll);
		for (j = 0; j < half_window && right; j++, right = right->l_next) 
			llll_appenddouble(sub, hatom_getdouble(&right->l_hatom), 0, WHITENULL_llll);
		llll_inplacesort(sub, (sort_fn)llll_leq_elem);
		idx = CLAMP((sub->l_size + 1)/2, 1, sub->l_size);
		okelem = llll_getindex(sub, idx, I_STANDARD);
		if (okelem)
			llll_appenddouble(out, hatom_getdouble(&okelem->l_hatom), 0, WHITENULL_llll);
		llll_free(sub);
	} 
	return out;
}

double llll_average_of_plain_double_llll(t_llll *ll)
{
    double av = 0;
    long count = 0;
    t_llllelem *elem;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        double this_val = hatom_getdouble(&elem->l_hatom);
        av += this_val;
        count ++;
    }
    av /= count;
    return av;
}


double llll_stdev_of_plain_double_llll(t_llll *ll, double *average)
{
	// find average
	double av = 0, stdev = 0;
	long count = 0;
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		double this_val = hatom_getdouble(&elem->l_hatom);
		av += this_val;
		count ++;
	}
	av /= count;
	
	if (average)
		*average = av;

	for (elem = ll->l_head; elem; elem = elem->l_next) {
		double this_val = hatom_getdouble(&elem->l_hatom);
		stdev += (this_val - av) * (this_val - av);
	}
	stdev /= count;
	stdev = sqrt(stdev);
	return stdev;
}

t_llll* llll_x2dx_of_plain_double_llll(t_llll *in_llll) {
// accept as input a llll of rationals, return the integrated list.
	t_llllelem *elem;
	t_llll *out_llll = llll_get();
	double cur = 0;
	
	if ((elem = in_llll->l_head)) {
		cur = hatom_getdouble(&elem->l_hatom);
		
		for (elem = elem->l_next; elem; elem = elem->l_next) {
			double old_cur = cur;
			cur = hatom_getdouble(&elem->l_hatom);
			llll_appenddouble(out_llll, cur - old_cur, 0, WHITENULL_llll);
		}
	}
	return out_llll;
}


t_llll* llll_dx2x_of_plain_double_llll(t_llll *in_llll, double start) {
// accept as input a llll of rationals, return the integrated list.
	t_llllelem *elem;
	t_llll *out_llll = llll_get();
	double sum = start;
	llll_appenddouble(out_llll, sum, 0, WHITENULL_llll);
	for (elem = in_llll->l_head; elem; elem = elem->l_next) {
		sum += hatom_getdouble(&elem->l_hatom);
		llll_appenddouble(out_llll, sum, 0, WHITENULL_llll);
	}
	return out_llll;
}


t_llll* llll_dx2x_of_plain_rat_llll(t_llll *in_llll, t_rational start_rational) {
// accept as input a llll of rationals, return the integrated list.
	t_llllelem *elem;
	t_llll *out_llll = llll_get();
	t_rational sum = start_rational;
	llll_appendrat(out_llll, sum, 0, WHITENULL_llll);
	for (elem = in_llll->l_head; elem; elem = elem->l_next) {
		sum = rat_rat_sum(sum, hatom_getrational(&elem->l_hatom));
		llll_appendrat(out_llll, sum, 0, WHITENULL_llll);
	}
	return out_llll;
}




long sum_elems_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_RAT || hatom_gettype(a) == H_LONG){
		t_rational this_sum = rat_rat_sum(*((t_rational *)data), hatom_getrational(a));
		*((t_rational *)data) = this_sum;
		hatom_setrational(a, this_sum);
	}
	return 0;
}

t_llll* llll_dx2x_of_rat_llll(t_llll *in_llll, t_rational start_rational, t_rational *total_sum){
	t_rational current_sum = start_rational;
    t_llll *out = llll_clone(in_llll);
	llll_funall(out, sum_elems_fn, &current_sum, 1, -1, 0);
	if (total_sum)
		*total_sum = current_sum;
	return out;
}


long get_abs_value(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_RAT)
		hatom_setrational(a, rat_abs(hatom_getrational(a)));
	else if (hatom_gettype(a) == H_LONG)
		hatom_setlong(a, alabs(hatom_getlong(a)));
	else if (hatom_gettype(a) == H_DOUBLE)
		hatom_setdouble(a, fabs(hatom_getdouble(a)));
	return 0;
}

void llll_abs(t_llll *llll){
	llll_funall(llll, get_abs_value, NULL, 1, -1, 0);
}


long llll_num_zeros_in_plain_long_llll(t_llll *in_llll){
	long num_zeros = 0;
	t_llllelem *elem;
	if (in_llll) {
		for (elem = in_llll->l_head; elem; elem = elem->l_next)
			if (hatom_getlong(&elem->l_hatom) == 0)
				num_zeros++;
	}
	return num_zeros;
}

long llll_first_nonzero_entry_index_in_plain_long_llll(t_llll *in_llll){
	long count;
	t_llllelem *elem;
	if (in_llll) {
		for (count = 1, elem = in_llll->l_head; elem; count++, elem = elem->l_next)
			if (hatom_getlong(&elem->l_hatom) != 0)
				return count;
	}
	return 0;
}

long llll_sum_of_rat_llll_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_LONG || hatom_gettype(a) == H_RAT)
		*((t_rational *)data) = rat_rat_sum(*((t_rational *)data), hatom_getrational(a));
	return 0;
}


t_rational llll_sum_of_rat_llll(t_llll *in_llll){
	t_rational sum = long2rat(0);
	if (in_llll)
		llll_funall(in_llll, llll_sum_of_rat_llll_fn, &sum, 1, -1, 0);
	return sum;
}


long llll_sum_of_doubles_llll_fn(void *data, t_hatom *a, const t_llll *address){
	if (is_hatom_number(a))
		*((double *)data) += hatom_getdouble(a);
	return 0;
}

double llll_sum_of_doubles_llll(t_llll *in_llll){
	double sum = 0;
	if (in_llll)
		llll_funall(in_llll, llll_sum_of_doubles_llll_fn, &sum, 1, -1, 0);
	return sum;
}


long get_num_rationals_in_llll_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_LONG || hatom_gettype(a) == H_RAT)
		(*((long *)data))++;
	return 0;
}

long get_num_rationals_in_llll(t_llll *in_llll){
	long num = 0;
	if (in_llll)
		llll_funall(in_llll, get_num_rationals_in_llll_fn, &num, 1, -1, 0);
	return num;
}


t_rational llll_min_of_plain_rat_llll(t_llll *in_llll){
	t_rational min;
	t_llllelem *elem;
	
	if (!in_llll || !in_llll->l_head)
		return long2rat(0);
		
	min = hatom_getrational(&in_llll->l_head->l_hatom);
	for (elem = in_llll->l_head->l_next; elem; elem = elem->l_next) {
		t_rational thisrat = hatom_getrational(&elem->l_hatom);
		if (rat_rat_cmp(thisrat, min) < 0)
			min = thisrat;
	}
	return min;
}

long llll_sum_abs_of_rat_llll_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_LONG || hatom_gettype(a) == H_RAT)
		*((t_rational *)data) = rat_rat_sum(*((t_rational *)data), rat_abs(hatom_getrational(a)));
	return 0;
}

t_rational llll_sum_abs_of_rat_llll(t_llll *in_llll){
	t_rational sum = long2rat(0);
	if (in_llll)
		llll_funall(in_llll, llll_sum_abs_of_rat_llll_fn, &sum, 1, -1, 0);
	return sum;
}

long llll_sum_abs_of_double_llll_fn(void *data, t_hatom *a, const t_llll *address){
	if (is_hatom_number(a))
		*((double *)data) += fabs(hatom_getdouble(a));
	return 0;
}

double llll_sum_abs_of_double_llll(t_llll *in_llll){
	double sum = 0;
	if (in_llll)
		llll_funall(in_llll, llll_sum_abs_of_double_llll_fn, &sum, 1, -1, 0);
	return sum;
}


long llll_sum_abs_of_rat_llll_up_to_g_list_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_LLLL && hatom_getllll(a)->l_head && hatom_gettype(&hatom_getllll(a)->l_head->l_hatom) == H_SYM && hatom_getsym(&hatom_getllll(a)->l_head->l_hatom) == _llllobj_sym_g)
		return 1;
	else if (hatom_gettype(a) == H_LONG || hatom_gettype(a) == H_RAT)
		*((t_rational *)data) = rat_rat_sum(*((t_rational *)data), rat_abs(hatom_getrational(a)));
	return 0;
}

t_rational llll_sum_abs_of_rat_llll_up_to_g_list(t_llll *in_llll){
	t_rational sum = long2rat(0);
	if (in_llll)
		llll_funall(in_llll, llll_sum_abs_of_rat_llll_up_to_g_list_fn, &sum, 1, -1, FUNALL_PROCESS_WHOLE_SUBLISTS);
	return sum;
}

t_rational llll_sum_abs_of_rat_llll_not_too_high_rationals(t_llll *in_llll, long max_number){
	t_rational sum;
	t_llllelem *elem;
	if (!in_llll) return long2rat(0);
	sum = long2rat(0);
	for (elem = in_llll->l_head; elem; elem = elem->l_next) {
		sum = rat_rat_sum(sum, rat_abs(hatom_getrational(&elem->l_hatom)));
		if (alabs(sum.r_num) > max_number || sum.r_den > max_number) {
			// retranscribe
			sum = ceil_approx_rat_with_rat(sum, max_number, max_number);
		}
	}
	return sum;
}

t_llll *symbol2llll(t_symbol *sym) {
	t_llll *outllll = llll_get();
	llll_appendsym(outllll, sym, 0, WHITENULL_llll);
	return outllll;
}

t_symbol *nth_sym_of_a_plain_sym_llll(t_llll *in_llll, long index) {
	long count;
	t_llllelem *this_elem;
	
	if (index <= 0) 
		return _llllobj_sym_empty_symbol;
	
	if (index > (long)in_llll->l_size) 
		return _llllobj_sym_empty_symbol;
	
	this_elem = in_llll->l_head;
	for (count = 1; this_elem && (count < index); count++)
		this_elem = this_elem->l_next;

	if (!this_elem) 
		return _llllobj_sym_empty_symbol;

	if (hatom_gettype(&this_elem->l_hatom) == H_SYM)
		return hatom_getsym(&this_elem->l_hatom);
	
	return _llllobj_sym_empty_symbol;
}

void llll_to_char_array(t_llll *in_llll, char* char_array, long max_chars) {
//	return;
	t_atom *av = NULL;
	short ac = llll_deparse(in_llll, &av, 0, LLLL_D_QUOTE);
	long i, cur = 0; 
	char part_string[100];
	for (i = 0; i < ac && cur < 85; i++){   
		long len;
		switch (atom_gettype(av+i)) {
			case A_LONG:
				snprintf_zero(part_string, 100, " %ld ", atom_getlong(av+i)); break;
			case A_FLOAT:
				snprintf_zero(part_string, 100, " %.6f ", atom_getfloat(av+i)); break;
			case A_SYM: {
				if (atom_getsym(av+i) == _llllobj_sym_open_round_bracket)
					snprintf_zero(part_string, 100, "(");
				else if (atom_getsym(av+i) == _llllobj_sym_closed_round_bracket)
					snprintf_zero(part_string, 100, ")");
				else
					snprintf_zero(part_string, 100, " %s ", atom_getsym(av+i)->s_name);
				break;
			}
			case A_OBJ:
				snprintf_zero(part_string, 100, " obj%ld ", ((long)atom_getobj(av+i)) % 100); break;
		}
		len = strlen(part_string);
		if ( cur + len < max_chars - 1) {
			strncpy(char_array + cur, part_string, len);
			cur += len;
		} else
			return;
	}
	char_array[cur] = '\0';
	if (av) 
		bach_freeptr(av);
}


long get_num_llll_in_llll_first_level(t_llll *inllll) {
//returns the number of elements of a given llll which are also lllls
	long count = 0;
	if (inllll) {
		t_llllelem *elem;
		for (elem = inllll->l_head; elem; elem = elem->l_next)
			if (hatom_gettype(&elem->l_hatom) == H_LLLL)
				count++;
	}
	
	return count;
}

t_llllelem *get_next_llll_no_first_sym_elem(t_llllelem *elem){
	t_llllelem *res = elem->l_next;
	while (res && (hatom_gettype(&res->l_hatom) != H_LLLL || (res->l_hatom.h_w.w_llll->l_head && hatom_gettype(&res->l_hatom.h_w.w_llll->l_head->l_hatom) == H_SYM)))
		res = res->l_next;
	return res;
}


long get_num_llll_no_first_sym_in_llll(t_llll *inllll) {
//returns the number of elements of a given llll which are also lllls and DON't have a sym as head
	long count = 0;
	if (inllll) {
		t_llllelem *elem;
		for (elem = inllll->l_head; elem; elem = elem->l_next)
			if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
				t_llll *this_llll = hatom_getllll(&elem->l_hatom);
				if (this_llll && this_llll->l_head && hatom_gettype(&this_llll->l_head->l_hatom) != H_SYM)
					count++;
			}
	}
	
	return count;
}



t_llll *repeat_long_for_llllelem_len(long number, t_llllelem *elem) {
	char howmanytimes;
	if (elem) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			howmanytimes = hatom_getllll(&elem->l_hatom)->l_size;
		} else
			howmanytimes = 1;
	} else {
		howmanytimes = 0;
	}
	if (howmanytimes == 0) howmanytimes = 1;
	return repeat_long(number, howmanytimes);
}

t_llll *repeat_long(long number, long howmanytimes) {
	t_llll *outllll = llll_get();
	long i;
	for (i = 0; i < howmanytimes; i++)
		llll_appendlong(outllll, number, 0, WHITENULL_llll);
	return outllll;
}

t_llll *repeat_hatom(t_hatom *h, long howmanytimes) {
	t_llll *outllll = llll_get();
	long i;
	for (i = 0; i < howmanytimes; i++)
		llll_appendhatom_clone(outllll, h, 0, WHITENULL_llll);
	return outllll;
}

t_llll *repeat_rat_until_tot_duration(t_rational number, t_rational tot_duration) {
	t_llll *outllll = llll_get();
	t_rational sum = long2rat(0);
	number = rat_abs(number);
	tot_duration = rat_abs(tot_duration);
	while (rat_rat_cmp(rat_rat_sum(sum, number), tot_duration) <= 0) {
		llll_appendrat(outllll, number, 0, WHITENULL_llll);
		sum = rat_rat_sum(sum, number);
	}
	// last number
	if (rat_rat_cmp(sum, tot_duration) < 0)
		llll_appendrat(outllll, rat_rat_diff(tot_duration, sum), 0, WHITENULL_llll);

	return outllll;
}


void force_plain_rat_llll_to_have_a_given_abs_sum(t_llll *list, t_rational tot_duration) {
// TO DO: make it better
	if (list) {
		t_rational sum = long2rat(0);
		t_llllelem *elem = list->l_head;
		tot_duration = rat_abs(tot_duration);
		while (elem && rat_rat_cmp(rat_rat_sum(sum, rat_abs(hatom_getrational(&elem->l_hatom))), tot_duration) <= 0) {
			sum = rat_rat_sum(sum, rat_abs(hatom_getrational(&elem->l_hatom)));
			elem = elem->l_next; // nothing to do, the list is ok!
		}

		// deleting redundant elements
		while (elem) {
			t_llllelem *nextelem = elem->l_next;
			llll_destroyelem(elem);
			elem = nextelem;
		}
		
		// last number ?
		if (rat_rat_cmp(sum, tot_duration) < 0)
			llll_appendrat(list, rat_rat_diff(tot_duration, sum), 0, WHITENULL_llll);
	}
}



long get_num_zeros_in_long_array(long *array, long length) {
	long i, count = 0;
	for (i = 0; i < length; i++)
		if (array[i] == 0) count++;
	return count;
}

char *char_array_to_string(char *array, long length, char wrapping_brackets) {
	long i, cursor = 0;
	char *string = (char *) bach_newptr(length * 20 + 2);
	for (i = 0; i < length && cursor < length * 10 + 2; i++){
		char partial_str[10];
		if (i == 0 && length == 1)
			snprintf_zero(partial_str, 10, wrapping_brackets ? "( %d )" : "%d", array[0]);
		else if (i == 0)
			snprintf_zero(partial_str, 10, wrapping_brackets ? "( %d " : "%d", array[0]);
		else if (i == length - 1)
			snprintf_zero(partial_str, 10, wrapping_brackets ? "%d )" : "%d", array[length-1]);
		else
			snprintf_zero(partial_str, 10, "%d ", array[i]);
		strncpy_zero(string + cursor, partial_str, 10);
		cursor += strlen(partial_str);
	}
	string[cursor] = 0;
	return string;
}


char *long_array_to_string(long *array, long length, char wrapping_brackets) {
	long i, cursor = 0;
	char *string = (char *) bach_newptr(length * 20 + 5);
	for (i=0; i < length && cursor < length * 10 + 5; i++){
		char partial_str[10];
		if (i==0)
			snprintf_zero(partial_str, 10, wrapping_brackets ? "( %ld " : (i == length - 1 ? "%ld" : "%ld "), array[0]);
		else if (i==length-1)
			snprintf_zero(partial_str, 10, wrapping_brackets ? "%ld )" : "%ld", array[length-1]);
		else
			snprintf_zero(partial_str, 10, "%ld ", array[i]);

		if (cursor + (long) strlen(partial_str) > length * 10)
			break;

		strncpy_zero(string + cursor, partial_str, 10);
		cursor += MIN(10, strlen(partial_str));
	}
	string[cursor] = 0;
	return string;
}

char *rat_array_to_string(t_rational *array, long length, char wrapping_brackets) {
	long i, cursor = 0;
	char *string = (char *) bach_newptr(length * 40);
	for (i=0; i < length && cursor < length * 30; i++){
		char partial_str[10];
		if (i == 0)
			snprintf_zero(partial_str, 10, wrapping_brackets ? "( %ld/%ld " : "%ld/%ld ", array[0].r_num, array[0].r_den);
		else if (i == length-1)
			snprintf_zero(partial_str, 10, wrapping_brackets ? "%ld/%ld )" : "%ld/%ld", array[length-1].r_num, array[length-1].r_den);
		else
			snprintf_zero(partial_str, 10, "%ld/%ld ", array[i].r_num, array[i].r_den);
		strncpy_zero(string + cursor, partial_str, 10);
		cursor += strlen(partial_str);
	}
	return string;
}

t_llll *double_array_to_llll(double *array, long length) {
	t_llll *out = llll_get();
	long i;
	for (i = 0; i < length; i++)
		llll_appenddouble(out, array[i], 0, WHITENULL_llll);
	return out;
}

void llll_to_fixed_double_array(t_llll *ll, long size, double *array)
{
    t_llllelem *elem;
    long i;
    
    for (elem = ll->l_head, i = 0; i < size && elem; i++, elem = elem->l_next)
        array[i] = hatom_getdouble(&elem->l_hatom);
}

void llll_to_fixed_char_array(t_llll *ll, long size, char *array)
{
    t_llllelem *elem;
    long i;
    
    for (elem = ll->l_head, i = 0; i < size && elem; i++, elem = elem->l_next)
        array[i] = hatom_getlong(&elem->l_hatom);
}

void llll_to_fixed_unicodeChar_array(t_llll *ll, long size, unsigned short *array)
{
    t_llllelem *elem;
    long i;
    
    for (elem = ll->l_head, i = 0; i < size && elem; i++, elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_SYM) {
            t_symbol *sym = hatom_getsym(&elem->l_hatom);
            if (sym && sym->s_name[0]) {
                long dummy_len;
                unsigned short *uni_text = charset_utf8tounicode_debug(sym->s_name, &dummy_len);
                array[i] = uni_text[0];
                bach_freeptr(uni_text);
            }
        } else if (is_hatom_number(&elem->l_hatom))
            array[i] = hatom_getlong(&elem->l_hatom);
    }
}

// returns the length
long llll_to_double_array(t_llll *ll, double **array)
{
	long length = ll->l_size;
	t_llllelem *elem;
	long i;
	
	if (length == 0) {
		*array = NULL;
		return 0;
	} else 
		*array = (double *)bach_newptr(length * sizeof(double));

	for (elem = ll->l_head, i = 0; i < length && elem; i++, elem = elem->l_next) 
		(*array)[i] = hatom_getdouble(&elem->l_hatom);

	return length;
}

// returns the length
long llll_to_long_array(t_llll *ll, long **array)
{
    long length = ll->l_size;
    t_llllelem *elem;
    long i;
    
    if (length == 0) {
        *array = NULL;
        return 0;
    } else
        *array = (long *)bach_newptr(length * sizeof(long));
    
    for (elem = ll->l_head, i = 0; i < length && elem; i++, elem = elem->l_next)
        (*array)[i] = hatom_getlong(&elem->l_hatom);
    
    return length;
}


t_llll *rat_array_to_llll(t_rational *array, long length) {
	t_llll *out = llll_get();
	long i;
	for (i = 0; i < length; i++)
		llll_appendrat(out, array[i], 0, WHITENULL_llll);
	return out;
}

char *double_array_to_string(double *array, long length, int max_decimals) {
	long i, cursor = 0;
	char *string = (char *) bach_newptr(length * 16 + 5);
	for (i = 0; i < length; i++){
		char partial_str[16];
		char thisnum[32];
		long j;
        
		if (max_decimals == -1)
			snprintf_zero(thisnum, 32, "%f", array[i]);
		else
			snprintf_zero(thisnum, 32, "%.*f", max_decimals, array[i]);
        
        if (max_decimals > 0) {
            for (j = MIN(31, strlen(thisnum) - 1); j >= 0; j--) {
                if (thisnum[j] == '0')
                    thisnum[j] = 0;
                else 
                    break;
            }
        }

		snprintf_zero(partial_str, 16, "%s ", thisnum);
		
		if (cursor + (long) strlen(partial_str) > length * 16)
			break;

		strncpy(string + cursor, partial_str, 16);
		cursor += MIN(16, strlen(partial_str));
	}
	string[cursor] = 0;
	return string;
}



char *double_to_string(double val, int max_decimals) {
	return double_array_to_string(&val, 1, max_decimals);
}

char *double_pair_to_string(double val1, double val2, int max_decimals) {
	double arr[2];
	arr[0] = val1;
	arr[1] = val2;
	return double_array_to_string(arr, 2, max_decimals);
}

t_symbol *double_to_symbol(double val, int max_decimals)
{
    char *buf = double_to_string(val, max_decimals);
    t_symbol *res = gensym(buf);
    bach_freeptr(buf);
    
    return res;
}

// DEPRECATED
// not a real mergesort INPLACE in the sense that the list llll_in doesn't have the same address, nor the original llllelements.
// in fact, it's an old function: use llll_inplacesort instead!
void llll_mergesort_inplace(t_llll **llll_in, long (*cmpfn)(void *data, t_llllelem *a, t_llllelem *b), void *data) {
	// we sort the list
	if (llll_in && *llll_in && (*llll_in)->l_size > 0) {
		t_llll *out;
		llll_mergesort(*llll_in, &out, cmpfn, data); // frees llll_in
		*llll_in = out;
	}
}



long how_many_doubles_in_llll_first_level(t_llll *inllll, double num){
	t_llllelem *elem;
	long count = 0;
	if (!inllll || inllll->l_size == 0) 
		return 0;
	for (elem = inllll->l_head; elem; elem = elem->l_next)
		if (is_hatom_number(&elem->l_hatom) && hatom_getdouble(&elem->l_hatom) == num)
			count++;
	return count;
}


char is_double_in_llll_first_level(t_llll *inllll, double num){
	t_llllelem *elem;
	if (!inllll || inllll->l_size == 0) 
		return false;
	for (elem = inllll->l_head; elem; elem = elem->l_next)
		if (is_hatom_number(&elem->l_hatom) && hatom_getdouble(&elem->l_hatom) == num)
			return true;
	return false;
}

char is_long_in_llll_first_level(t_llll *inllll, long num){
	t_llllelem *elem;
	if (!inllll || inllll->l_size == 0) 
		return false;
	for (elem = inllll->l_head; elem; elem = elem->l_next)
		if ((hatom_gettype(&elem->l_hatom) == H_LONG || hatom_gettype(&elem->l_hatom) == H_RAT) && hatom_getlong(&elem->l_hatom) == num)
			return true;
	return false;
}

char is_symbol_in_llll_first_level(t_llll *inllll, t_symbol *sym){
	t_llllelem *elem;
	if (!inllll || inllll->l_size == 0) 
		return false;
	for (elem = inllll->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_SYM && hatom_getsym(&elem->l_hatom) == sym)
			return true;
	return false;
}

char is_obj_in_llll_first_level(t_llll *inllll, void *obj){
    t_llllelem *elem;
    if (!inllll || inllll->l_size == 0)
        return false;
    for (elem = inllll->l_head; elem; elem = elem->l_next)
        if (hatom_gettype(&elem->l_hatom) == H_OBJ && hatom_getobj(&elem->l_hatom) == obj)
            return true;
    return false;
}

char has_llll_symbols_in_first_level(t_llll *inllll){
	t_llllelem *elem;
	if (!inllll || inllll->l_size == 0) 
		return false;
	for (elem = inllll->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_SYM)
			return true;
	return false;
}

t_llll *get_nilnil(){
	t_llll *out = llll_get();
	llll_appendllll(out, llll_get(), 0, WHITENULL_llll);
	return out;
}

t_llll *get_arithmser(long from, long to, long step){
	t_llll *out = llll_get();
	long i;
	for (i=from; i<=to; i+=step)
		llll_appendlong(out, i, 0, WHITENULL_llll);
	return out;
}


t_llllelem *get_first_non_llll_elem(t_llll *llll){
	t_llllelem *res = llll->l_head;
	while (res && hatom_gettype(&res->l_hatom) == H_LLLL)
		res = hatom_getllll(&res->l_hatom)->l_head;
	return res;
}

t_llllelem *get_last_non_llll_elem(t_llll *llll){
	t_llllelem *res = llll->l_tail;
	while (res && hatom_gettype(&res->l_hatom) == H_LLLL)
		res = hatom_getllll(&res->l_hatom)->l_tail;
	return res;
}

t_llllelem *llllelem_get_prev_non_llll_elem(t_llllelem *elem){

	t_llllelem *pivot = elem;
	t_llllelem *candidate = pivot->l_prev;
	
	while (true) {
		if (!candidate) {
			pivot = pivot->l_parent->l_owner;
			candidate = pivot->l_prev;
		} else if (candidate && hatom_gettype(&candidate->l_hatom) == H_LLLL && !get_last_non_llll_elem(candidate->l_hatom.h_w.w_llll)) {
			pivot = pivot->l_prev ? pivot->l_prev : pivot->l_parent->l_owner;
			candidate = pivot->l_prev;
		} else {
			break;
		}
	}
	
	if (!candidate)
		return NULL;
	
	if (hatom_gettype(&candidate->l_hatom) == H_LLLL)
		return get_last_non_llll_elem(hatom_getllll(&candidate->l_hatom));
	else 
		return candidate;
}

void llll_cpost(t_llll *ll)
{
#ifdef CONFIGURATION_Development
    char *buf1 = NULL;
    llll_to_text_buf(ll, &buf1, 0, 6, LLLL_T_NULL, LLLL_TE_SMART, LLLL_TB_SMART, NULL);
    cpost(buf1);
    bach_freeptr(buf1);
#endif
}


t_llll *llllelem_root(const t_llllelem *elem){
	t_llllelem *tmp = (t_llllelem *)elem;
	while (tmp && tmp->l_parent->l_owner)
		tmp = tmp->l_parent->l_owner;
	return tmp->l_parent;
}


// finds the first list (going "backward") containing both elem1 and elem2 as "sons" or "grandsons" or "grandgrandsons"...
t_llll *llllelem_find_first_common_relative(t_llllelem *elem1, t_llllelem *elem2, long *depth_elem1, long *depth_elem2, long *depth_relative){
	t_llll *parent1 = elem1->l_parent;
	t_llll *parent2 = elem2->l_parent;
	long depth1 = llllelem_get_depth(elem1);
	long depth2 = llllelem_get_depth(elem2);
	*depth_elem1 = depth1;
	*depth_elem2 = depth2;
	while (parent1 != parent2){
		if (depth1 > depth2){
			if (!parent1->l_owner)
				return NULL;
			parent1 = parent1->l_owner->l_parent;
			depth1--;
		} else if (depth2 > depth1){
			if (!parent2->l_owner)
				return NULL;
			parent2 = parent2->l_owner->l_parent;
			depth2--;
		} else {
			if (!parent1->l_owner || !parent2->l_owner)
				return NULL;
			parent1 = parent1->l_owner->l_parent;
			parent2 = parent2->l_owner->l_parent;
			depth1--;
			depth2--;
		}
	}
	if (parent1 == parent2){
		*depth_relative = depth1 - 1;
		return parent1;
	}
	return NULL;
}


long llllelem_get_depth(t_llllelem *elem){
	long depth = 0;
	t_llllelem *elem2 = elem;
	while (elem2){
		depth ++;
		elem2 = elem2->l_parent->l_owner;
	}
	return depth;
}

t_llll *build_sym_long_llll(t_symbol *sym, long val) {
	t_llll *out = llll_get();
	llll_appendsym(out, sym, 0, WHITENULL_llll);
	llll_appendlong(out, val, 0, WHITENULL_llll);
	return out;
}


t_symbol *ac_av_to_single_symbol(long ac, t_atom *av){
	char *buf = NULL;
	long size;
	t_symbol *out;
	atom_gettext_debug(ac, av, &size, &buf, 0);
	out = gensym(buf);
	bach_freeptr(buf);
	return out;
}

t_llllelem *get_nearest_llllelem_to_double(t_llll *ll, double num)
{
	t_llllelem *elem, *elem2, *best_elem = NULL;
	double best_error = 0;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		if (is_hatom_number(&elem->l_hatom)) {
			double this_num = hatom_getdouble(&elem->l_hatom);
			double this_error = fabs(this_num - num);
			if (!best_elem || this_error < best_error) {
				best_elem = elem;
				best_error = this_error;
			}
		} else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			for (elem2 = hatom_getllll(&elem->l_hatom)->l_head; elem2; elem2 = elem2->l_next) {
				if (is_hatom_number(&elem2->l_hatom)) {
					double this_num = hatom_getdouble(&elem2->l_hatom);
					double this_error = fabs(this_num - num);
					if (!best_elem || this_error < best_error) {
						best_elem = elem2;
						best_error = this_error;
					}
				}
			}
		}
	}
	return best_elem;
}



long is_sym_equal_to_the_first_sym_of_llll(t_symbol *sym, t_llll *what)
{
	if (what && what->l_head && hatom_gettype(&what->l_head->l_hatom) == H_SYM)
		return sym == hatom_getsym(&what->l_head->l_hatom);
	
	return 0;
}

long find_long_argument_key(t_llll *ll, t_symbol *key, long default_value, char then_destroy_elem)
{
	long res = default_value;
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *subll = hatom_getllll(&elem->l_hatom);
			if (subll && subll->l_head && hatom_gettype(&subll->l_head->l_hatom) == H_SYM && hatom_getsym(&subll->l_head->l_hatom) == key) {
				if (subll->l_head->l_next && is_hatom_number(&subll->l_head->l_next->l_hatom)) {
					res = hatom_getlong(&subll->l_head->l_next->l_hatom);
					if (then_destroy_elem)
						llll_destroyelem(elem);
					return res;
				}
			}
		}
	}
	
	return res;
}

long find_long_arg_attr_key(t_llll *ll, t_symbol *key, long default_value, char then_destroy_elem)
{
    long res = default_value;
    t_llllelem *elem;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
            t_llll *subll = hatom_getllll(&elem->l_hatom);
            if (subll && subll->l_head && hatom_gettype(&subll->l_head->l_hatom) == H_SYM && hatom_getsym(&subll->l_head->l_hatom) == key) {
                if (subll->l_head->l_next && is_hatom_number(&subll->l_head->l_next->l_hatom)) {
                    res = hatom_getlong(&subll->l_head->l_next->l_hatom);
                    if (then_destroy_elem)
                        llll_destroyelem(elem);
                    return res;
                }
            }
        } else if (hatom_gettype(&elem->l_hatom) == H_SYM) {
            t_symbol *s = hatom_getsym(&elem->l_hatom);
            if (s && s->s_name && s->s_name[0] == '@' && gensym(s->s_name + 1) == key) {
                if (elem->l_next && is_hatom_number(&elem->l_next->l_hatom)) {
                    res = hatom_getlong(&elem->l_next->l_hatom);
                    if (then_destroy_elem) {
                        t_llllelem *nextelem = elem->l_next;
                        llll_destroyelem(elem);
                        llll_destroyelem(nextelem);
                    }
                    return res;
                }
            }
        }
    }
    
    return res;
}

t_symbol *find_symbol_arg_attr_key(t_llll *ll, t_symbol *key, t_symbol *default_value, char then_destroy_elem)
{
    t_symbol *res = default_value;
    t_llllelem *elem;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
            t_llll *subll = hatom_getllll(&elem->l_hatom);
            if (subll && subll->l_head && hatom_gettype(&subll->l_head->l_hatom) == H_SYM && hatom_getsym(&subll->l_head->l_hatom) == key) {
                if (subll->l_head->l_next && hatom_gettype(&subll->l_head->l_next->l_hatom) == H_SYM) {
                    res = hatom_getsym(&subll->l_head->l_next->l_hatom);
                    if (then_destroy_elem)
                        llll_destroyelem(elem);
                    return res;
                }
            }
        } else if (hatom_gettype(&elem->l_hatom) == H_SYM) {
            t_symbol *s = hatom_getsym(&elem->l_hatom);
            if (s && s->s_name && s->s_name[0] == '@' && gensym(s->s_name + 1) == key) {
                if (elem->l_next && hatom_gettype(&elem->l_next->l_hatom) == H_SYM) {
                    res = hatom_getsym(&elem->l_next->l_hatom);
                    if (then_destroy_elem) {
                        t_llllelem *nextelem = elem->l_next;
                        llll_destroyelem(elem);
                        llll_destroyelem(nextelem);
                    }
                    return res;
                }
            }
        }
    }
    
    return res;
}




double find_double_argument_key(t_llll *ll, t_symbol *key, double default_value, char then_destroy_elem)
{
	double res = default_value;
	t_llllelem *elem;
	for (elem = ll->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *subll = hatom_getllll(&elem->l_hatom);
			if (subll && subll->l_head && hatom_gettype(&subll->l_head->l_hatom) == H_SYM && hatom_getsym(&subll->l_head->l_hatom) == key) {
				if (subll->l_head->l_next && is_hatom_number(&subll->l_head->l_next->l_hatom)) {
					res = hatom_getdouble(&subll->l_head->l_next->l_hatom);
					if (then_destroy_elem)
						llll_destroyelem(elem);
					return res;
				}
			}
        } else if (hatom_gettype(&elem->l_hatom) == H_SYM) {
            t_symbol *s = hatom_getsym(&elem->l_hatom);
            if (s && s->s_name && s->s_name[0] == '@' && gensym(s->s_name + 1) == key) {
                if (elem->l_next && is_hatom_number(&elem->l_next->l_hatom)) {
                    res = hatom_getdouble(&elem->l_next->l_hatom);
                    if (then_destroy_elem) {
                        t_llllelem *nextelem = elem->l_next;
                        llll_destroyelem(elem);
                        llll_destroyelem(nextelem);
                    }
                    return res;
                }
            }
        }
    }
	return res;
}

double find_double_arg_attr_key(t_llll *ll, t_symbol *key, double default_value, char then_destroy_elem)
{
    double res = default_value;
    t_llllelem *elem;
    for (elem = ll->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
            t_llll *subll = hatom_getllll(&elem->l_hatom);
            if (subll && subll->l_head && hatom_gettype(&subll->l_head->l_hatom) == H_SYM && hatom_getsym(&subll->l_head->l_hatom) == key) {
                if (subll->l_head->l_next && is_hatom_number(&subll->l_head->l_next->l_hatom)) {
                    res = hatom_getdouble(&subll->l_head->l_next->l_hatom);
                    if (then_destroy_elem)
                        llll_destroyelem(elem);
                    return res;
                }
            }
        }
    }
    return res;
}


long llll_sort_by_first(void *dummy, t_llllelem *a, t_llllelem *b) {
	if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
		t_llll *llll1 = hatom_getllll(&a->l_hatom);
		t_llll *llll2 = hatom_getllll(&b->l_hatom);
        if (llll1 && llll2 && llll1->l_head && llll2->l_head) {
            if (llll_leq_hatom(&llll1->l_head->l_hatom, &llll2->l_head->l_hatom)) {
				return 1;
            } else {
				return 0;
            }
        }
        
		return 1;
	}
	return 1;
}


long llll_sort_by_second(void *dummy, t_llllelem *a, t_llllelem *b) {
    if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
        t_llll *llll1 = hatom_getllll(&a->l_hatom);
        t_llll *llll2 = hatom_getllll(&b->l_hatom);
        if (llll1 && llll2 && llll1->l_size >= 2 && llll2->l_size >= 2) {
            if (llll_leq_hatom(&llll1->l_head->l_next->l_hatom, &llll2->l_head->l_next->l_hatom)) {
                return 1;
            } else {
                return 0;
            }
        }
        
        return 1;
    }
    return 1;
}


long llll_sort_by_last(void *dummy, t_llllelem *a, t_llllelem *b) {
	if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
		t_llll *llll1 = hatom_getllll(&a->l_hatom);
        t_llll *llll2 = hatom_getllll(&b->l_hatom);
        if (llll1 && llll2 && llll1->l_tail && llll2->l_tail)  {
            if (llll_leq_hatom(&llll1->l_tail->l_hatom, &llll2->l_tail->l_hatom)) {
                return 1;
            } else {
                return 0;
            }
        }
		return 1;
	}
	return 1;
}

char are_atoms_equal(t_atom *a1, t_atom *a2)
{
	if (atom_gettype(a1) != atom_gettype(a2))
		return 0;
		
	if (atom_gettype(a1) == A_LONG)
		return atom_getlong(a1) == atom_getlong(a2);
	else if (atom_gettype(a1) == A_FLOAT)
		return atom_getfloat(a1) == atom_getfloat(a2);
	else if (atom_gettype(a1) == A_SYM)
		return atom_getsym(a1) == atom_getsym(a2);
	else if (atom_gettype(a1) == A_OBJ)
		return atom_getobj(a1) == atom_getobj(a2);
	return 0;
}

char are_atomarrays_equal(t_atom *a1, long size1, t_atom *a2, long size2)
{
	long i;
	if (size1 != size2)
		return 0;
	for (i = 0; i < size1; i++)
		if (!are_atoms_equal(a1 + i, a2 + i))
			return 0;
	return 1;
}

char is_atom_in_atomarray(t_atom *atom, t_atom *atomarray, long atomarray_size)
{
	long i;
	for (i = 0; i < atomarray_size; i++)
		if (are_atoms_equal(atom, atomarray + i))
			return true;
	return false;
}

void copy_atomarrays_avoid_floats(t_atom *from, t_atom *to, long size)
{
	long i;
	for (i = 0; i < size; i++) {
		if (atom_gettype(from + i) == A_SYM || atom_gettype(from + i) == A_LONG)
			to[i] = from[i];
		else if (atom_gettype(from + i) == A_FLOAT)
			atom_setlong(to + i, atom_getlong(from + i));
		else
			atom_setlong(to + i, 0);
	}
}


void copy_atomarrays(t_atom *from, t_atom *to, long size)
{
	long i;
	for (i = 0; i < size; i++)
		to[i] = from[i];
}


// beware: atom, not hatom!
t_llllelem *llll_appendatom(t_llll *where, t_atom *what, long flags, t_llll *adopter)
{
	if (atom_gettype(what) == A_LONG)
		return llll_appendlong(where, atom_getlong(what), 0, WHITENULL_llll);
	else if (atom_gettype(what) == A_FLOAT)
		return llll_appenddouble(where, atom_getfloat(what), 0, WHITENULL_llll);
	else if (atom_gettype(what) == A_SYM)
		return llll_appendsym(where, atom_getsym(what), 0, WHITENULL_llll);
	else if (atom_gettype(what) == A_OBJ)
		return llll_appendobj(where, atom_getobj(what), 0, WHITENULL_llll);
	return NULL;
}

void llll_median(t_llll *ll, t_hatom *h)
{
	long pos = floor((ll->l_size + 1)/2.);
	if (pos > 0 && pos <= (long)ll->l_size) {
		t_llllelem *elem = llll_getindex(ll, pos, I_STANDARD);
		*h = elem->l_hatom;
	}
}


t_llll *llll_get_period(t_llll *ll) {
	long i, found = -1;
	t_llll *candidate, *result;
	t_llllelem *elem;
	
	if (!ll) return NULL;
	
	candidate = llll_clone(ll);
	for (i = 1; i < (long)ll->l_size; i++){
		llll_rotatelevel(candidate, -1);
		if (llll_eq_ignoretype(ll, candidate)) {
			found = i;
			break;
		}
	}

	if (found == -1)
		found = ll->l_size;
	
	result = llll_get();
	for (elem = ll->l_head, i = 0; elem && i < found; elem = elem->l_next, i++)
		llll_appendhatom_clone(result, &elem->l_hatom, 0, WHITENULL_llll);
	
	llll_free(candidate);
	return result;
}



char llll_is_subset_of(t_llll *container, t_llll *contained){
	t_llllelem *elem1, *elem2;
	for (elem1 = contained->l_head; elem1; elem1 = elem1->l_next) {
		char cont = false;
		for (elem2 = container->l_head; elem2; elem2 = elem2->l_next) {
			if (llll_eq_elem_ignoretype(elem1, elem2)) {
				cont = true;
				break;
			}
		}
		if (!cont)
			return false;
	}
	return true;
}


void llll_force_matrix_size(t_llll *matrix, long num_rows, long num_cols, t_hatom *pad)
{
	if (matrix) {
		long i;
		t_llllelem *elem;
		
		if ((long)matrix->l_size > num_rows)
			llll_free(llll_slice(matrix, num_rows));
		
		for (i = matrix->l_size; i < num_rows; i++)
			llll_appendllll(matrix, llll_get(), 0, WHITENULL_llll);
		
		for (elem = matrix->l_head; elem; elem = elem->l_next) {
			if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
				t_llll *ll = hatom_getllll(&elem->l_hatom);
				
				if ((long)ll->l_size > num_cols)
					llll_free(llll_slice(ll, num_cols));
				
				for (i = ll->l_size; i < num_cols; i++) {
					if (!pad)
						llll_appendlong(ll, 0, 0, WHITENULL_llll);
					else
						llll_appendhatom_clone(ll, pad, 0, WHITENULL_llll);
				}
			}
		}
	}
}


void unpack_llll_to_double_triplet(t_llll *ll, double *num1, double *num2, double *num3)
{
	t_llllelem *elem = ll->l_head;
	if (elem) {
		*num1 = is_hatom_number(&elem->l_hatom) ? hatom_getdouble(&elem->l_hatom) : 0.;
		elem = elem->l_next;
		
		if (elem) {
			*num2 = is_hatom_number(&elem->l_hatom) ? hatom_getdouble(&elem->l_hatom) : 0.;
			elem = elem->l_next;

			if (elem) {
				*num3 = is_hatom_number(&elem->l_hatom) ? hatom_getdouble(&elem->l_hatom) : 0.;
				elem = elem->l_next;
			}
		}
	} else {
		*num1 = *num2 = *num3 = 0.;
	}
}



// p = 0 is a shortcut for the for inf norm
double get_p_norm_for_point_sequence(t_pts *points, long num_points, long p)
{
	long i;
	
	if (p == 0) {
		// first we handle the inf-norm
		double max = 0;
		long max_i = -1;
		for (i = 0; i < num_points; i++) {
			double this_fabs = fabs(points[i].y);
			if (this_fabs > max) {
				max = this_fabs;
				max_i = i;
			}
		}	
		dev_post("      - max happens at i = %ld", max_i);
		return max;
	
	} else {
		// standard p-norm
		double res = 0;
		// compute integral of the function difference
		for (i = 1; i < num_points; i++) {
			double this_contribution = (pow(points[i].y, (double) p) + pow(points[i-1].y, (double) p)) * (points[i].x - points[i-1].x)/2.;
			res += this_contribution;
		}	
		return res;
	}
}


// slope is ignored, for now
double get_integral_distance_with_original(t_pts *points, char *taken, long num_points, long p)
{
	double res = 0;
	long i = 0, j = 0, i_fix = 0;
	t_pts *diff_with_interpolation;
	diff_with_interpolation = (t_pts *) bach_newptrclear(num_points * sizeof(t_pts));
	
	// finding first taken point
	while (i < num_points && !taken[i]) {
		diff_with_interpolation[i] = points[i];
		diff_with_interpolation[i].y = 0;
		i++;
	}
	
	if (i < num_points) {
		diff_with_interpolation[i] = points[i];
		diff_with_interpolation[i].y = 0;
		i_fix = i;
		i++;
	}

	while (i < num_points) {

		while (i < num_points && !taken[i]) 
			i++;

		if (i < num_points) {
			for (j = i_fix + 1; j <= i; j++) {
				double interp = rescale(points[j].x, points[i_fix].x, points[i].x, points[i_fix].y, points[i].y); // no slope
				diff_with_interpolation[j] = points[j];
				diff_with_interpolation[j].y = fabs(diff_with_interpolation[j].y - interp);
			}
		} else {
			for (j = i_fix + 1; j < num_points; j++) {
				diff_with_interpolation[j] = points[j];
				diff_with_interpolation[j].y = 0;
			}
		}
		
		i_fix = i;
		i++;
	}
	
	res = get_p_norm_for_point_sequence(diff_with_interpolation, num_points, p);
	bach_freeptr(diff_with_interpolation);
	return res;
}

long llll_sort_by_decreasing_length_and_then_by_increasing_sum(void *dummy, t_llllelem *a, t_llllelem *b) {
	if (hatom_gettype(&a->l_hatom) == H_LLLL && hatom_gettype(&b->l_hatom) == H_LLLL) {
		t_llll *llll1 = hatom_getllll(&a->l_hatom);
		t_llll *llll2 = hatom_getllll(&b->l_hatom);
		if (llll1 && llll2) {
			if (llll1->l_size > llll2->l_size)
				return 1;
			else if (llll1->l_size == llll2->l_size && llll_sum_of_doubles_llll(llll1) <= llll_sum_of_doubles_llll(llll2))
				return 1;
			else
				return 0;
		}
		return 1;
	}
	return 1;
}

t_llll *double_couple_to_llll(double d1, double d2)
{
	t_llll *this_ll = llll_get();
	llll_appenddouble(this_ll, d1, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d2, 0, WHITENULL_llll);
	return this_ll;
}

t_llll *double_triplet_to_llll(double d1, double d2, double d3)
{
	t_llll *this_ll = llll_get();
	llll_appenddouble(this_ll, d1, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d2, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d3, 0, WHITENULL_llll);
	return this_ll;
}

t_llll *double_quadruplet_to_llll(double d1, double d2, double d3, double d4)
{
	t_llll *this_ll = llll_get();
	llll_appenddouble(this_ll, d1, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d2, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d3, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d4, 0, WHITENULL_llll);
	return this_ll;
}

t_llll *double_triplet_and_long_to_llll(double d1, double d2, double d3, long d4)
{
	t_llll *this_ll = llll_get();
	llll_appenddouble(this_ll, d1, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d2, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d3, 0, WHITENULL_llll);
	llll_appendlong(this_ll, d4, 0, WHITENULL_llll);
	return this_ll;
}

t_llll *symbol_and_double_to_llll(t_symbol *sym, double d)
{
	t_llll *this_ll = llll_get();
	llll_appendsym(this_ll, sym, 0, WHITENULL_llll);
	llll_appenddouble(this_ll, d, 0, WHITENULL_llll);
	return this_ll;
}

t_llll *symbol_and_long_to_llll(t_symbol *sym, long n)
{
	t_llll *this_ll = llll_get();
	llll_appendsym(this_ll, sym, 0, WHITENULL_llll);
	llll_appendlong(this_ll, n, 0, WHITENULL_llll);
	return this_ll;
}

t_llll *symbol_and_symbol_to_llll(t_symbol *sym1, t_symbol *sym2)
{
    t_llll *this_ll = llll_get();
    llll_appendsym(this_ll, sym1, 0, WHITENULL_llll);
    llll_appendsym(this_ll, sym2, 0, WHITENULL_llll);
    return this_ll;
}

t_pt llll_to_pt(t_llll *ll)
{
	t_pt out;
	out.x = out.y = 0;
	
	if (ll && ll->l_size >= 2) {
		if (is_hatom_number(&ll->l_head->l_hatom))
			out.x = hatom_getdouble(&ll->l_head->l_hatom);
		if (is_hatom_number(&ll->l_head->l_next->l_hatom))
			out.y = hatom_getdouble(&ll->l_head->l_next->l_hatom);
	}
	return out;
}

t_rect llll_to_rect(t_llll *ll)
{
	t_rect out;
	out.x = out.y = out.width = out.height = 0;
	
	if (ll && ll->l_size >= 4) {
		t_llllelem *temp = ll->l_head;
		out.x = hatom_getdouble(&temp->l_hatom);
		temp = temp->l_next;
		out.y = hatom_getdouble(&temp->l_hatom);
		temp = temp->l_next;
		out.width = hatom_getdouble(&temp->l_hatom);
		temp = temp->l_next;
		out.height = hatom_getdouble(&temp->l_hatom);
	}
	return out;
}

t_llll *pt_to_llll(t_pt pt, char add_zero_slope)
{
	t_llll *this_point_llll = llll_get();
	llll_appenddouble(this_point_llll, pt.x, 0, WHITENULL_llll);
	llll_appenddouble(this_point_llll, pt.y, 0, WHITENULL_llll);
	if (add_zero_slope)
		llll_appenddouble(this_point_llll, 0, 0, WHITENULL_llll);
	return this_point_llll;
}


t_llll *rect_to_llll(t_rect rect)
{
	t_llll *ll = llll_get();
	llll_appenddouble(ll, rect.x, 0, WHITENULL_llll);
	llll_appenddouble(ll, rect.y, 0, WHITENULL_llll);
	llll_appenddouble(ll, rect.width, 0, WHITENULL_llll);
	llll_appenddouble(ll, rect.height, 0, WHITENULL_llll);
	return ll;
}

// the input llll is expected to be in the form (x y slope anything else...) (x y slope anything else...)
// the "anything else" is also merged with respect to the given input mode.
// slopehandling = 0: ignore them, slopehandling = 1: approximate
t_llll *llll_approximate_breakpoint_function(t_llll *in_ll, long num_points_to_keep, double thresh, long p, char algorithm, char slope_handling, char markmode, t_object *culprit)
{
	t_llll *ll = llll_get();
	t_llllelem *elem;
	
	
	// Convert slopes to linear, and if |slope| > threshold add a mid-point!
	for (elem = in_ll->l_head; elem; elem = elem->l_next) {
        if (hatom_gettype(&elem->l_hatom) != H_LLLL) {
            object_warn(culprit, "Warning: all function points must be lllls. A non-llll element has been dropped.");
            continue;
        }
        
		double pt_x, pt_y, pt_slope, prev_x, prev_y, prev_slope;
		double fabs_pt_slope = 0;
        t_llll *orig_ll = hatom_getllll(&elem->l_hatom);
		unpack_llll_to_double_triplet(orig_ll, &pt_x, &pt_y, &pt_slope);
		fabs_pt_slope = fabs(pt_slope);
		
		if (slope_handling) {
			if (!elem->l_prev || fabs_pt_slope < 0.1) {
				llll_appendllll(ll, double_triplet_to_llll(pt_x, pt_y, 0), 0, WHITENULL_llll);
			} else {
				t_pt ctrl1, ctrl2, middle, ctrl3, ctrl4;
				unpack_llll_to_double_triplet(hatom_getllll(&elem->l_prev->l_hatom), &prev_x, &prev_y, &prev_slope);
				paint_curve_and_get_bezier_control_points(NULL, get_grey(0), build_pt(prev_x, prev_y), build_pt(pt_x, pt_y), pt_slope, 1, 
														  &ctrl1, &ctrl2, &middle, &ctrl3, &ctrl4);
				
				if (fabs_pt_slope < 0.4) {
					// one mid-point
					llll_appendllll(ll, double_triplet_to_llll(middle.x, middle.y, 0), 0, WHITENULL_llll);
					llll_appendllll(ll, double_triplet_to_llll(pt_x, pt_y, 0), 0, WHITENULL_llll);
				} else {
					// three mid-points
					llll_appendllll(ll, pt_to_llll(get_single_bezier_subdivision_point(build_pt(prev_x, prev_y), ctrl1, ctrl2, middle, 0.5), true), 0, WHITENULL_llll)->l_thing.w_obj = WHITENULL; // in order to distinguish midpoints from standard points, later on
					llll_appendllll(ll, double_triplet_to_llll(middle.x, middle.y, 0), 0, WHITENULL_llll);
					llll_appendllll(ll, pt_to_llll(get_single_bezier_subdivision_point(middle, ctrl3, ctrl4, build_pt(pt_x, pt_y), 0.5), true), 0, WHITENULL_llll)->l_thing.w_obj = WHITENULL; // in order to distinguish midpoints from standard points, later on
					llll_appendllll(ll, double_triplet_to_llll(pt_x, pt_y, 0), 0, WHITENULL_llll);
				}
			}
        } else {
            t_llll *copied_ll = double_triplet_to_llll(pt_x, pt_y, 0);
            if (markmode)
                copied_ll->l_thing = orig_ll->l_thing;
			llll_appendllll(ll, copied_ll, 0, WHITENULL_llll);
        }
	}
	
	if (in_ll->l_size < 2) 
		return ll;
	
	
	if (algorithm == 0) { // clustering algorithm, not greedy
		
		double pivot_x, pivot_y, pivot_slope, left_x, left_y, left_slope, right_x, right_y, right_slope, temp_x, temp_y, temp_slope;
		t_llllelem *pivotelem, *temp;
		t_llll *elem_neighbour_dists = llll_get(), *elem_neighbour_idx = llll_get();
		long count_pivotelem = 0;
		long ll_size = 0;
		
		elem = ll->l_head;
		while (elem) {
			t_llllelem *nextel = elem->l_next;
			if (hatom_gettype(&elem->l_hatom) != H_LLLL)
				llll_destroyelem(elem);
			elem = nextel;
		}
		
		ll_size = ll->l_size;
		
		for (pivotelem = ll->l_head, count_pivotelem = 0; pivotelem; pivotelem = pivotelem->l_next, count_pivotelem++) {
			t_llll *this_elem_neighbour_dists = llll_get(), *this_elem_neighbour_idx = llll_get();

			llll_appenddouble(this_elem_neighbour_dists, 0, 0, WHITENULL_llll);
			llll_appendlong(this_elem_neighbour_idx, count_pivotelem, 0, WHITENULL_llll);
			
			unpack_llll_to_double_triplet(hatom_getllll(&pivotelem->l_hatom), &pivot_x, &pivot_y, &pivot_slope);	

			t_llllelem *left_elem = pivotelem, *right_elem = pivotelem;
			long left_count = 0, right_count = 0; 
			char doing_left = true;
			double tot_dist = 0, count = 0;
			
			left_x = right_x = pivot_x; 
			left_y = right_y = pivot_y;
			left_slope = right_slope = pivot_slope;
			while (left_elem && right_elem) {
				if (((left_count + right_count) % 2 == 0 && left_elem->l_prev) || (!right_elem->l_next)) {
					left_elem = left_elem->l_prev;
					if (!left_elem)
						break;
					left_count ++;
					doing_left = true;
					unpack_llll_to_double_triplet(hatom_getllll(&left_elem->l_hatom), &left_x, &left_y, &left_slope);	
				} else {
					right_elem = right_elem->l_next;
					if (!right_elem)
						break;
					right_count ++;
					doing_left = false;
					unpack_llll_to_double_triplet(hatom_getllll(&right_elem->l_hatom), &right_x, &right_y, &right_slope);	
				}
				
				tot_dist = 0;
				for (temp = left_elem->l_next, count = 0; temp; temp = temp->l_next) {
					if (temp == right_elem)
						break;
					else {
						unpack_llll_to_double_triplet(hatom_getllll(&temp->l_hatom), &temp_x, &temp_y, &temp_slope);	
						double this_dist = fabs(pt_line_distance_vertical(temp_x, temp_y, left_x, left_y, right_x, right_y));
						tot_dist += this_dist;
						count++;
					}
				}
				tot_dist = (count == 0 ? 0 : tot_dist/count);
				if (tot_dist > thresh) {
					break;
				} else {
					if (doing_left) {
						llll_prependdouble(this_elem_neighbour_dists, tot_dist, 0, WHITENULL_llll);
						llll_prependlong(this_elem_neighbour_idx, count_pivotelem-left_count, 0, WHITENULL_llll);
					} else {
						llll_appenddouble(this_elem_neighbour_dists, tot_dist, 0, WHITENULL_llll);
						llll_appendlong(this_elem_neighbour_idx, count_pivotelem+right_count, 0, WHITENULL_llll);
					}
				}

			}
	
			llll_appendllll(elem_neighbour_dists, this_elem_neighbour_dists, 0, WHITENULL_llll);
			llll_appendllll(elem_neighbour_idx, this_elem_neighbour_idx, 0, WHITENULL_llll);
		}
		
		t_llll **lists_to_order = (t_llll **) bach_newptr(2 * sizeof(t_llll *));
		char *pruned = (char *)bach_newptrclear(ll_size * sizeof(char));
		
		if (true) {
			t_llllelem *dist_elem = elem_neighbour_dists->l_head, *idx_elem = elem_neighbour_idx->l_head;
			while (dist_elem && idx_elem) {
				t_llllelem *nextdist = dist_elem->l_next, *nextidx = idx_elem->l_next;
				if (hatom_getllll(&dist_elem->l_hatom)->l_size <= 2) {
					llll_destroyelem(dist_elem);
					llll_destroyelem(idx_elem);
				}
				dist_elem = nextdist;
				idx_elem = nextidx;
			}

			lists_to_order[0] = elem_neighbour_dists; 
			lists_to_order[1] = elem_neighbour_idx; 
			llll_multisort(lists_to_order, lists_to_order, 2, (sort_fn)llll_sort_by_decreasing_length_and_then_by_increasing_sum);
			elem_neighbour_dists = lists_to_order[0];
			elem_neighbour_idx = lists_to_order[1];
			
			
/*			dev_post("-----");
			for (dist_elem = elem_neighbour_dists->l_head, idx_elem = elem_neighbour_idx->l_head; dist_elem && idx_elem; 
				 dist_elem = dist_elem->l_next, idx_elem = idx_elem->l_next) {
				llll_print_named(hatom_getllll(&dist_elem->l_hatom), gensym("dists"), 0, 2, NULL);
				llll_print_named(hatom_getllll(&idx_elem->l_hatom), gensym("idx"), 0, 2, NULL);
			}
*/			

			for (dist_elem = elem_neighbour_dists->l_head, idx_elem = elem_neighbour_idx->l_head;
				 dist_elem && idx_elem; dist_elem = dist_elem->l_next, idx_elem = idx_elem->l_next) {
				
				// pruning elements
				t_llll *this_dist_ll = hatom_getllll(&dist_elem->l_hatom);
				t_llll *this_idx_ll = hatom_getllll(&idx_elem->l_hatom);
				
				// modifying head and tail for alreadypruned elements
				while (this_idx_ll->l_head && pruned[hatom_getlong(&this_idx_ll->l_head->l_hatom)]) {
					llll_behead(this_idx_ll);
					llll_behead(this_dist_ll);
				}

				while (this_idx_ll->l_tail && pruned[hatom_getlong(&this_idx_ll->l_tail->l_hatom)]) {
					llll_betail(this_idx_ll);
					llll_betail(this_dist_ll);
				}
				
				if (this_dist_ll->l_size <= 2 || this_idx_ll->l_size <= 2)
					continue;
				
				
				char can_prune = true;
				t_llllelem *this_idx_elem, *this_dist_elem;
				for (this_idx_elem = this_idx_ll->l_head; this_idx_elem; this_idx_elem = this_idx_elem->l_next) {
					long idx = hatom_getlong(&this_idx_elem->l_hatom);
					if (idx >= 0 && idx < ll_size && pruned[idx]) {
						can_prune = false;
						break;
					}
				}
				
				if (can_prune) {
					this_dist_elem = this_dist_ll->l_head->l_next; 
					this_idx_elem = this_idx_ll->l_head->l_next; 
					while (this_dist_elem && this_idx_elem) { 
						if (!this_dist_elem->l_next || !this_idx_elem->l_next)
							break;
						
						long idx = hatom_getlong(&this_idx_elem->l_hatom);
						if (idx >= 0 && idx < ll_size)
							pruned[idx] = true;
						
						this_dist_elem = this_dist_elem->l_next;
						this_idx_elem = this_idx_elem->l_next;
					}
				}
				
			}
		}
		
		elem = ll->l_head;
		long i = 0;
		while (elem && i < ll_size) {
			t_llllelem *nextelem = elem->l_next; 
			if (pruned[i])
				llll_destroyelem(elem);
			elem = nextelem;
			i++;
		}
		
		llll_free(elem_neighbour_dists);
		llll_free(elem_neighbour_idx);
		bach_freeptr(lists_to_order);
		bach_freeptr(pruned);
		
	
	} else if (algorithm == 1) {
		// clustering algorithm, greedy
		
		double pivot_x = 0, pivot_y = 0, pivot_slope = 0, pt_x, pt_y, pt_slope;
		t_llllelem *elem, *pivotelem;
		
		elem = ll->l_head;
		while (elem) {
			t_llllelem *nextel = elem->l_next;
			if (hatom_gettype(&elem->l_hatom) != H_LLLL)
				llll_destroyelem(elem);
			elem = nextel;
		}
		
		elem = ll->l_head;
        
        if (elem && hatom_gettype(&elem->l_hatom) == H_LLLL) {
            unpack_llll_to_double_triplet(hatom_getllll(&elem->l_hatom), &pivot_x, &pivot_y, &pivot_slope);
            pivotelem = elem;
            elem = elem->l_next;
        } else {
            object_error(culprit, "Error: wrong function syntax found (three floats expected)!");
            goto end;
        }
		
		while (elem) {
			
			double dist = 0;
			while (elem) {
                
                if (!elem || hatom_gettype(&elem->l_hatom) != H_LLLL) {
                    object_error(culprit, "Error: wrong function syntax found (three floats expected)!");
                    goto end;
                } else {
                    
                    // clustering following points
                    unpack_llll_to_double_triplet(hatom_getllll(&elem->l_hatom), &pt_x, &pt_y, &pt_slope);
                    if (elem == pivotelem->l_next)
                        dist = 0;
                    else {
                        t_llllelem *temp;
                        double tot_dist = 0;
                        long count = 0;
                        double temp_x, temp_y, temp_slope;
                        for (temp = pivotelem->l_next; temp; temp = temp->l_next) {
                            if (temp == elem)
                                break;
                            else {
                                unpack_llll_to_double_triplet(hatom_getllll(&temp->l_hatom), &temp_x, &temp_y, &temp_slope);
                                tot_dist += fabs(pt_line_distance_vertical(temp_x, temp_y, pivot_x, pivot_y, pt_x, pt_y));
                                count++;
                            }
                        }
                        tot_dist /= count;
                        if (tot_dist > thresh)
                            break;
                    }
                }
				elem = elem->l_next;
			}
			
			if (!elem)
				elem = ll->l_tail;
			else
				elem = elem->l_prev;

            // pruning middle elements
            t_llllelem *temp, *next_el;
            for (temp = pivotelem->l_next; temp; temp = next_el) {
                next_el = temp->l_next;
                if (temp == elem)
                    break;
                else
                    llll_destroyelem(temp);
            }
            
            if (markmode) {
                double tempx1, tempx2, tempy1, tempy2, tempslope1, tempslope2;
                unpack_llll_to_double_triplet(hatom_getllll(&pivotelem->l_hatom), &tempx1, &tempy1, &tempslope1);
                unpack_llll_to_double_triplet(hatom_getllll(&elem->l_hatom), &tempx2, &tempy2, &tempslope2);
                double line_slope = (tempy2 - tempy1)/(tempx2 - tempx1);
                pivotelem->l_thing.w_double = line_slope;
            }
			
			pivotelem = elem;
			unpack_llll_to_double_triplet(hatom_getllll(&pivotelem->l_hatom), &pivot_x, &pivot_y, &pivot_slope);
			elem = pivotelem->l_next;
		}
		
	} else if (algorithm == 2) {
		// integral distance algorithm, not greedy
		
		// convert to t_pts structures
		long num_points = in_ll->l_size;
		t_pts *points;
		char *taken;
		long num_taken = 2;
		t_llllelem *elem;
		long i = 0;
		
		points = (t_pts *)bach_newptrclear(num_points * sizeof(t_pts));	// all the original points, constnantly
		taken = (char *)bach_newptrclear(num_points * sizeof(char));	// tells which of the points are considered for the current solution
		
		// converting llllelems to points
		for (elem = in_ll->l_head, i = 0; elem && i < num_points; elem = elem->l_next, i++)
			if (hatom_gettype(&elem->l_hatom) == H_LLLL)
				unpack_llll_to_double_triplet(hatom_getllll(&elem->l_hatom), &(points[i].x), &(points[i].y), &(points[i].slope));	
		
		
		taken[0] = taken[num_points - 1] = 1;
			
		double curr_error = get_integral_distance_with_original(points, taken, num_points, p);
		
		while ( ((num_points_to_keep <= 0) || (num_taken < num_points_to_keep)) &&
			    ((thresh <= 0) || (curr_error > thresh)) &&
			   num_taken < num_points) {
			
			dev_post("Searching for %ld-th point", num_taken + 1);

			// we add one point! which one? the one which lends a better integral distance ;)
			double best_dist = -1;
			double this_dist;
			long best_i = -1;
			for (i = 0; i < num_points; i++) {
				if (!taken[i]) {
					taken[i] = true;
					this_dist = get_integral_distance_with_original(points, taken, num_points, p);
					taken[i] = false;

					dev_post("    • i = %ld --> dist = %.2f", i, this_dist);
					
					if (best_dist < 0 || this_dist < best_dist) {
						best_dist = this_dist;
						best_i = i;
					}
				}
			}
			
			
			if (best_i < 0 || best_i >= num_points)
				break; // should never happen
			
			dev_post("best_i = %ld, best_dist = %.2f", best_i, best_dist);
			
			num_taken++;
			taken[best_i] = true;
			curr_error = best_dist;
		}
		
		
		llll_clear(ll);
		for (elem = in_ll->l_head, i = 0; elem && i < num_points; elem = elem->l_next, i++)
			if (taken[i])
				llll_appendhatom_clone(ll, &elem->l_hatom, 0, WHITENULL_llll);
		
		bach_freeptr(taken);
		bach_freeptr(points);
		
	} else {
	
		ll = llll_clone(in_ll);
		t_llllelem *elem;
		t_llll *malus_ll = llll_get();
		const long neighborhood_width = 3;
		double max_malus = thresh;
		
		
		// assigning importance weight to a given point
		for (elem = ll->l_head; elem; elem = elem->l_next) {
			double this_malus = 0.; // 0 = very important, higher numbers = negative points.
			
			if (!elem->l_prev || !elem->l_next || hatom_gettype(&elem->l_hatom) != H_LLLL)
				this_malus = -0.1; // first or last point are MORE than very important: can't miss! the weight must be greater than 1.
			else {
				double this_x, this_y, this_s;
				unpack_llll_to_double_triplet(hatom_getllll(&elem->l_hatom), &this_x, &this_y, &this_s);
				
				
				this_malus = 0.;
				
				t_llllelem *temp_L, *temp_R;
				long count;
				for (count = 1, temp_L = elem->l_prev, temp_R = elem->l_next; 
					 temp_L && temp_R && count <= neighborhood_width && hatom_gettype(&temp_L->l_hatom) == H_LLLL && hatom_gettype(&temp_R->l_hatom) == H_LLLL; 
					 temp_L = temp_L->l_prev, temp_R = temp_R->l_next, count++) {
					
					double temp_L_x, temp_L_y, temp_L_s, temp_R_x, temp_R_y, temp_R_s;
					unpack_llll_to_double_triplet(hatom_getllll(&temp_L->l_hatom), &temp_L_x, &temp_L_y, &temp_L_s);
					unpack_llll_to_double_triplet(hatom_getllll(&temp_R->l_hatom), &temp_R_x, &temp_R_y, &temp_R_s);
					
					double this_pt_line_distance = pt_line_distance(this_x, this_y, temp_L_x, temp_L_y, temp_R_x, temp_R_y) / count;
					this_malus += this_pt_line_distance;
				}
			}
			
			llll_appenddouble(malus_ll, this_malus, 0, WHITENULL_llll);
		}
		
		t_llll **lists_to_order = (t_llll **) bach_newptr(2 * sizeof(t_llll *));
		lists_to_order[0] = malus_ll; 
		lists_to_order[1] = ll; 
		llll_multisort(lists_to_order, lists_to_order, 2, (sort_fn)llll_leq_elem);
		malus_ll = lists_to_order[0];
		ll = lists_to_order[1];
		
		if (max_malus > 0) {
			// pruning stuff > max weight
			while (malus_ll->l_tail && hatom_getdouble(&malus_ll->l_tail->l_hatom) > max_malus){
				llll_betail(malus_ll);
				llll_betail(ll);
			}
		}
		
		if (num_points_to_keep > 0) {
			llll_free(llll_slice(malus_ll, num_points_to_keep));
			llll_free(llll_slice(ll, num_points_to_keep));
		}
		
		llll_inplacesort(ll, (sort_fn)llll_sort_by_first);
		
		bach_freeptr(lists_to_order);
		llll_free(malus_ll);
		
	}

end:
	return ll;
}

t_pts llllelem_to_pts(t_llllelem *incoming_el)
{
	t_pts out;
	out.x = out.y = out.slope = 0;
	
	if (hatom_gettype(&incoming_el->l_hatom) == H_LLLL) {
		t_llllelem *elem = hatom_getllll(&incoming_el->l_hatom)->l_head;
		
		if (elem) {
			out.x = hatom_getdouble(&elem->l_hatom);
			elem = elem->l_next;
			if (elem) {
				out.y = hatom_getdouble(&elem->l_hatom);
				elem = elem->l_next;
				if (elem) 
					out.slope = CLAMP(hatom_getdouble(&elem->l_hatom), -1., 1.);
			}
		}
	}
	return out;
}

t_llll *integrate_bpf_with_explicit_sampling(t_llll *incoming, t_llll *x_values, double starting_value)
{
	long size = incoming->l_size;
	long i;
	t_llllelem *elem;
	
	if (size <= 0 || x_values->l_size <= 0) 
		return llll_get();
	
	t_llll *cloned = llll_clone(incoming);
	llll_inplacesort(cloned, (sort_fn)llll_sort_by_first); // sorting by X value

	t_pts *pts = (t_pts *)bach_newptrclear(size * sizeof(t_pts));
	
	for (i = 0, elem = cloned->l_head; elem && i < size; elem = elem->l_next, i++)
		pts[i] = llllelem_to_pts(elem);
	
	llll_free(cloned);

	t_llll *out = llll_get();

	long left = 0, right = 0;
	double prev_x = 0, prev_y = 0;
	double res = starting_value;
	
	llll_appendllll(out, double_triplet_to_llll(hatom_getdouble(&x_values->l_head->l_hatom), starting_value, 0), 0, WHITENULL_llll);
	
	for (elem = x_values->l_head; elem; elem = elem->l_next) {
		double this_x, this_y;
		
		this_x = hatom_getdouble(&elem->l_hatom);
		
		// finding left and right element 
		while (left + 1 < size && pts[left+1].x < this_x)
			left++;
		while (right + 1 < size && pts[right].x < this_x)
			right ++;
		
		this_y = rescale_with_slope(this_x, pts[left].x, pts[right].x, pts[left].y, pts[right].y, pts[right].slope);
		
		if (elem->l_prev) {
			res += (this_y + prev_y) * (this_x - prev_x)/2.;
			llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
		}
		
		prev_x = this_x; 
		prev_y = this_y;
	}
	
	return out;
}


t_llll *integrate_bpf(t_llll *incoming, double domain_start, double domain_end, long num_samples, double starting_value,
					  char auto_domain)
{
	long size = incoming->l_size;
	t_llllelem *elem;
	long i;
	
	if (size <= 0) 
		return llll_get();
	
	t_llll *cloned = llll_clone(incoming);
	llll_inplacesort(cloned, (sort_fn)llll_sort_by_first); // sorting by X value
	
	t_pts *pts = (t_pts *)bach_newptrclear(size * sizeof(t_pts));
	
	for (i = 0, elem = cloned->l_head; elem && i < size; elem = elem->l_next, i++)
		pts[i] = llllelem_to_pts(elem);
	
	llll_free(cloned);
	
	if (auto_domain) {
		double min = pts[0].x, max = pts[0].x;
		for (i = 1; i < size; i++) {
			if (pts[i].x < min)
				min = pts[i].x;
			if (pts[i].x > min)
				max = pts[i].x;
		}
		domain_start = min;
		domain_end = max;
	}
	
	num_samples = MAX(num_samples, 2);
	
	t_llll *out = llll_get();

	if (true) { // sampling algorithm
	
		long left = 0, right = 0;
		double prev_x = 0, prev_y = 0;
		double res = starting_value;
		
		llll_appendllll(out, double_triplet_to_llll(domain_start, starting_value, 0), 0, WHITENULL_llll);

		for (i = 0; i < num_samples; i++) {
			double this_x, this_y;
			
			this_x = rescale_with_slope(i, 0, num_samples - 1, domain_start, domain_end, 0);
			
			// finding left and right element 
			while (left + 1 < size && pts[left+1].x < this_x)
				left++;
			while (right + 1 < size && pts[right].x < this_x)
				right ++;
			
			this_y = rescale_with_slope(this_x, pts[left].x, pts[right].x, pts[left].y, pts[right].y, pts[right].slope);
			
			if (i >= 1) {
				res += (this_y + prev_y) * (this_x - prev_x)/2.;
				llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
			}

			prev_x = this_x; 
			prev_y = this_y;
		}
	}
		
	bach_freeptr(pts);
	return out;
}


t_llll *derive_bpf_with_explicit_sampling(t_llll *incoming, t_llll *x_values, char discrete_derivative, char discrete_derivative_pad)
{
	long size = incoming->l_size;
	long i;
	t_llllelem *elem;
	
	if (size <= 0 || x_values->l_size <= 0) 
		return llll_get();
	
	t_llll *cloned = llll_clone(incoming);
	llll_inplacesort(cloned, (sort_fn)llll_sort_by_first); // sorting by X value
	
	t_pts *pts = (t_pts *)bach_newptrclear(size * sizeof(t_pts));
	
	for (i = 0, elem = cloned->l_head; elem && i < size; elem = elem->l_next, i++)
		pts[i] = llllelem_to_pts(elem);
	
	llll_free(cloned);
	
	t_llll *out = llll_get();
	
	long left = 0, right = 0;
	double prev_x = 0, prev_y = 0;
	double res = 0;
		
	for (elem = x_values->l_head; elem; elem = elem->l_next) {
		double this_x, this_y;
		
		this_x = hatom_getdouble(&elem->l_hatom);
		
		// finding left and right element 
		while (left + 1 < size && pts[left+1].x < this_x)
			left++;
		while (right + 1 < size && pts[right].x < this_x)
			right ++;
		
		this_y = rescale_with_slope(this_x, pts[left].x, pts[right].x, pts[left].y, pts[right].y, pts[right].slope);
		
		if (elem->l_prev) {
			res = (this_y - prev_y) / (this_x - prev_x);
			if (discrete_derivative) {
				if (!elem->l_prev->l_prev && (discrete_derivative_pad == 1 || discrete_derivative_pad == 3)) 
					llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
				
				if (discrete_derivative_pad == 1)
					llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
				else if (discrete_derivative_pad == 2)
					llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
				else
					llll_appendllll(out, double_triplet_to_llll((this_x + prev_x)/2., res, 0), 0, WHITENULL_llll);

				if (!elem->l_next && (discrete_derivative_pad == 2 || discrete_derivative_pad == 3)) 
					llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);

			} else {
				llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
				llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
			}
		}
		
		prev_x = this_x; 
		prev_y = this_y;
	}
	return out;
}

t_llll *derive_bpf(t_llll *incoming, double domain_start, double domain_end, long num_samples,
					  char auto_domain, char if_possible_dont_sample, char discrete_derivative, char discrete_derivative_pad)
{
	long size = incoming->l_size;
	t_llllelem *elem;
	long i;
	char use_sampling_algorithm = true;
	
	if (size <= 0) 
		return llll_get();
	
	t_llll *cloned = llll_clone(incoming);
	llll_inplacesort(cloned, (sort_fn)llll_sort_by_first); // sorting by X value
	
	t_pts *pts = (t_pts *)bach_newptrclear(size * sizeof(t_pts));
	
	for (i = 0, elem = cloned->l_head; elem && i < size; elem = elem->l_next, i++)
		pts[i] = llllelem_to_pts(elem);
	
	llll_free(cloned);
	
	if (auto_domain) {
		double min = pts[0].x, max = pts[0].x;
		for (i = 1; i < size; i++) {
			if (pts[i].x < min)
				min = pts[i].x;
			if (pts[i].x > min)
				max = pts[i].x;
		}
		domain_start = min;
		domain_end = max;
	}
	
	num_samples = MAX(num_samples, 2);
	
	t_llll *out = llll_get();
	
	if (if_possible_dont_sample) {
		char we_have_to_sample = false;
		for (i = 0; i < size; i++) {
			if (fabs(pts[i].slope) > 0.01) {
				we_have_to_sample = true;
				break;
			}
		}
		if (!we_have_to_sample)
			use_sampling_algorithm = false;
	}
	
	if (use_sampling_algorithm) { // sampling algorithm
		
		long left = 0, right = 0;
		double prev_x = 0, prev_y = 0;
		double res = 0;
		
		
		for (i = 0; i < num_samples; i++) {
			double this_x, this_y;
			
			this_x = rescale_with_slope(i, 0, num_samples - 1, domain_start, domain_end, 0);
			
			// finding left and right element 
			while (left + 1 < size && pts[left+1].x < this_x)
				left++;
			while (right + 1 < size && pts[right].x < this_x)
				right ++;
			
			this_y = rescale_with_slope(this_x, pts[left].x, pts[right].x, pts[left].y, pts[right].y, pts[right].slope);
			
			if (i >= 1)
				res = (this_y - prev_y) / (this_x - prev_x);
			
			if (i >= 1) {
				if (discrete_derivative) {
					if (i == 1 && (discrete_derivative_pad == 1 || discrete_derivative_pad == 3)) 
						llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);

					if (discrete_derivative_pad == 1)
						llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
					else if (discrete_derivative_pad == 2)
						llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
					else
						llll_appendllll(out, double_triplet_to_llll((prev_x + this_x)/2., res, 0), 0, WHITENULL_llll);

					if (i == num_samples - 1 && (discrete_derivative_pad == 2 || discrete_derivative_pad == 3)) 
						llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
				} else {
					llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
					llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
				}
			}
			
			prev_x = this_x; 
			prev_y = this_y;
		}
	} else {
		double res = 0;
		double prev_x = 0, prev_y = 0;
		
		for (i = 0; i < size; i++) {
			double this_x, this_y;
			
			this_x = pts[i].x;
			this_y = pts[i].y;
			
			if (i >= 1) 
				res = (this_y - prev_y) / (this_x - prev_x);
			
			if (i >= 1) {
				if (discrete_derivative) {
					if (i == 1 && (discrete_derivative_pad == 1 || discrete_derivative_pad == 3)) 
						llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);

					if (discrete_derivative_pad == 1)
						llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
					else if (discrete_derivative_pad == 2)
						llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
					else
						llll_appendllll(out, double_triplet_to_llll((prev_x + this_x)/2., res, 0), 0, WHITENULL_llll);

					if (i == size - 1 && (discrete_derivative_pad == 2 || discrete_derivative_pad == 3)) 
						llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
				} else {
					llll_appendllll(out, double_triplet_to_llll(prev_x, res, 0), 0, WHITENULL_llll);
					llll_appendllll(out, double_triplet_to_llll(this_x, res, 0), 0, WHITENULL_llll);
				}
			}
			
			prev_x = this_x; 
			prev_y = this_y;
		}		
	}
	
	bach_freeptr(pts);
	return out;
}

void llll_develop_ranges_inplace(t_llll **ll)
{
	t_llll *res = llll_develop_ranges(*ll);
	llll_free(*ll);
	*ll = res;
}

long parse_negative_indices_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_LONG){
		long v = hatom_getlong(a);
		long maxnum = *((long *)data);
		if (v < 0)
			hatom_setlong(a, maxnum + v + 1);
	}
	return 0;
}

long long_minus_one_fn(void *data, t_hatom *a, const t_llll *address){
	if (hatom_gettype(a) == H_LONG)
		hatom_setlong(a, hatom_getlong(a) - 1);
	return 0;
}

// negative indices are folded with respect to max num (-1 = maxnum, -2 = maxnum - 1, and so on).
void llll_develop_ranges_and_parse_negative_indices_inplace(t_llll **ll, long maxnum, char convert_from_1based_to_0based)
{
	long maxnum_local = maxnum;
	llll_funall(*ll, parse_negative_indices_fn, &maxnum_local, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
	if (convert_from_1based_to_0based)
		llll_funall(*ll, long_minus_one_fn, NULL, 1, -1, FUNALL_ONLY_PROCESS_ATOMS);
	llll_develop_ranges_inplace(ll);
}

// ********************
// NOTIFICATIONS
// ********************

void send_sym_doubles_notification(t_object *x, long outlet_num, t_symbol *router, long count, ...){
	long i; 
	t_llll *notification = llll_get();

	va_list argptr;
	va_start(argptr,count);
	
	llll_appendsym(notification, router, 0, WHITENULL_llll);
	for (i = 0; i < count; i++) {
		double num = va_arg(argptr, double);
		llll_appenddouble(notification, num, 0, WHITENULL_llll);
	}
	llllobj_outlet_llll(x, LLLL_OBJ_UI, outlet_num, notification);
	llll_free(notification); 
	va_end(argptr);
}

void do_send_sym_lllls_notification(t_object *x, long outlet_num, long also_free_lllls, t_symbol *router, long count, va_list lllls){
	long i; 
	t_llll *notification = llll_get();
//	va_start(lllls, count);
	llll_appendsym(notification, router, 0, WHITENULL_llll);
	for (i = 0; i < count; i++) {
		t_llll *ll = va_arg(lllls, t_llll *);
		if (ll) {
			if (also_free_lllls) 
				llll_appendllll(notification, ll, 0, WHITENULL_llll);
			else
				llll_appendllll_clone(notification, ll, 0, WHITENULL_llll, NULL);
		}
	}
	llllobj_outlet_llll(x, LLLL_OBJ_UI, outlet_num, notification);
	llll_free(notification); 
}


void send_sym_lllls_notification(t_object *x, long outlet_num, t_symbol *router, long count,...){
	va_list argptr;
	va_start(argptr,count);
	do_send_sym_lllls_notification(x, outlet_num, false, router, count, argptr);
	va_end(argptr);
}

void send_sym_lllls_notification_and_free(t_object *x, long outlet_num, t_symbol *router, long count,...){
	va_list argptr;
	va_start(argptr,count);
	do_send_sym_lllls_notification(x, outlet_num, false, router, count, argptr);
	va_end(argptr);
}

t_llll *long_couple_to_llll(long c1, long c2)
{
	t_llll *ll = llll_get();
	llll_appendlong(ll, c1, 0, WHITENULL_llll);
	llll_appendlong(ll, c2, 0, WHITENULL_llll);
	return ll;
}


t_llll *obj_couple_to_llll(void *v1, void *v2)
{
	t_llll *ll = llll_get();
	llll_appendobj(ll, v1, 0, WHITENULL_llll);
	llll_appendobj(ll, v2, 0, WHITENULL_llll);
	return ll;
}

long llllelem_retrieve_index(t_llll *ll, t_llllelem *elem)
{
	t_llllelem *temp;
	long i = 1;
	for (temp = ll->l_head; temp; temp = temp->l_next, i++)
		if (elem == temp)
			return i;
	return 0; // not found
}


t_symbol *double_to_symbol_fixed(double d, long numdecimals)
{
    char txt[100];
    snprintf_zero(txt, 100, "%.*f", numdecimals, d);
    return gensym(txt);
}

t_symbol *hatom_to_symbol(t_hatom *h, long numdecimals)
{
	switch (h->h_type) {
		case H_SYM:
			return hatom_getsym(h);
		case H_LONG:
		{
			char txt[100];
			snprintf_zero(txt, 100, "%ld", hatom_getlong(h));
			return gensym(txt);
		}
		case H_DOUBLE:
		{
			char txt[100];
			snprintf_zero(txt, 100, "%.*f", numdecimals, hatom_getdouble(h));
			return gensym(txt);
		}
		case H_RAT:
		{
			char txt[200];
			t_rational r = hatom_getrational(h);
			snprintf_zero(txt, 200, "%ld/%ld", r.r_num, r.r_den);
			return gensym(txt);
		}
		default:
			return _llllobj_sym_empty_symbol;
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////
// --- DESTRUCTIVE --- 

char is_there_a_path(t_llll *adj_list, long idx_start, long idx_end, t_llll *visited, char only_nondirect)
{
	t_llllelem *elem = llll_getindex(adj_list, idx_start, I_NON_NEGATIVE);
	if (!elem || hatom_gettype(&elem->l_hatom) != H_LLLL)
		return 0;
	
	t_llll *ll = hatom_getllll(&elem->l_hatom);
	if (!ll || ll->l_size < 2)
		return 0;
	
	for (elem = ll->l_head->l_next; elem; elem = elem->l_next) {
		t_llll *ll2 = hatom_getllll(&elem->l_hatom);
		long n = hatom_getlong(&ll2->l_head->l_hatom);
		if (n == idx_end) {
			if (!only_nondirect)
				return 1;
		} else if (!is_long_in_llll_first_level(visited, n)) {
			llll_appendlong(visited, n, 0, WHITENULL_llll);
			if (is_there_a_path(adj_list, n, idx_end, visited, false))
				return 1;
		}
	}
	return 0;
}


void llll_poset(t_llll *ll, poset_fn cmpfn, void *data, t_llll **out_edges, t_llll **out_adjacency, t_llll **minima, t_llll **maxima)
{
	t_llllelem *elem1, *elem2;
	long i, j;

	*out_edges = llll_get();
	*out_adjacency = llll_get();
	if (maxima)
		*maxima = llll_get();
	if (minima)
		*minima = llll_get();
	
	if (!ll)
		return;
	
	if (ll->l_size == 0) 
		return;
	
	llll_put_elems_in_lllls_in_lthing(ll);
	
	// create adjacency list
	for (elem1 = ll->l_head, i = 1; elem1; elem1 = elem1->l_next, i++) {
		t_llll *adj_list = llll_get();
		t_llll *wrap = llll_get();
		llll_appendlong(wrap, i, 0, WHITENULL_llll);
		llll_appendhatom_clone(wrap, &elem1->l_hatom, 0, WHITENULL_llll);
		llll_appendllll(adj_list, wrap, 0, WHITENULL_llll);
		for (elem2 = ll->l_head, j = 1; elem2; elem2 = elem2->l_next, j++) {
			if (elem2 != elem1) {
				if ((cmpfn)(data, elem1, elem2)) {
					t_llll *wrap2 = llll_get();
					llll_appendlong(wrap2, j, 0, WHITENULL_llll);
					llll_appendhatom_clone(wrap2, &elem2->l_hatom, 0, WHITENULL_llll);
					llll_appendllll(adj_list, wrap2, 0, WHITENULL_llll);
				}
			}
		}
		llll_appendllll(*out_adjacency, adj_list, 0, WHITENULL_llll);
	}
	
	// refine adjacency list, by removing straight paths when indirect path are present.
	// For instance, if A --> D, but also A --> B and B--> C and C --> D, then A --> D must be removed
	// This algorithm could be improved, it is not a very efficient implementation.
	t_llllelem *next_el; 
	for (elem1 = (*out_adjacency)->l_head; elem1; elem1 = elem1->l_next) {
		t_llll *ll = hatom_getllll(&elem1->l_hatom);
		t_llllelem *start = ll->l_head;
		t_llll *start_ll = hatom_getllll(&start->l_hatom);
		long start_n = hatom_getlong(&start_ll->l_head->l_hatom);
		for (elem2 = start->l_next; elem2; elem2 = next_el) {
			next_el = elem2->l_next;
			// check if ref -> elem2 can be deleted
			t_llllelem *end = hatom_getllll(&elem2->l_hatom)->l_head;
			long end_n = hatom_getlong(&end->l_hatom);
			t_llll *visited = llll_get();
			if (is_there_a_path(*out_adjacency, start_n, end_n, visited, true))
				llll_destroyelem(elem2);
			llll_free(visited);
		}
	}
	
	// now we have the correct adjacency list
	
	/// fill maxima and minima
	if (maxima || minima) {
		for (elem1 = (*out_adjacency)->l_head, i = 1; elem1; elem1 = elem1->l_next, i++) {
			t_llll *ll = hatom_getllll(&elem1->l_hatom);
			// maximum ?
			if (maxima && ll->l_size == 1)
				llll_appendhatom_clone(*maxima, &hatom_getllll(&ll->l_head->l_hatom)->l_head->l_next->l_hatom, 0, WHITENULL_llll);
			// minimum?
			if (minima) {
				char found = false;
				for (elem2 = (*out_adjacency)->l_head; elem2; elem2 = elem2->l_next) {
					if (elem2 != elem1) {
						t_llll *ll = hatom_getllll(&elem2->l_hatom);
						t_llllelem *temp;
						for (temp = ll->l_head->l_next; temp; temp = temp->l_next) {
							if (hatom_getlong(&hatom_getllll(&temp->l_hatom)->l_head->l_hatom) == i) {
								found = true;
								break;
							}
						}
					}
				}
				if (!found)
					llll_appendhatom_clone(*minima, &hatom_getllll(&ll->l_head->l_hatom)->l_head->l_next->l_hatom, 0, WHITENULL_llll);
			}
		}
	}
	
	// let's clean up the adjacency list
	for (elem1 = (*out_adjacency)->l_head; elem1; elem1 = elem1->l_next) {
		t_llll *ll = hatom_getllll(&elem1->l_hatom);
		for (elem2 = ll->l_head; elem2; elem2 = next_el) {
			next_el = elem2->l_next;
			t_llll *ll2 = hatom_getllll(&elem2->l_hatom);
			llll_destroyelem(ll2->l_head);
			llll_splatter(elem2, LLLL_FREETHING_DONT);
		}
	}
	
	// and now let's build the edges llll
	for (elem1 = (*out_adjacency)->l_head; elem1; elem1 = elem1->l_next) {
		t_llll *ll = hatom_getllll(&elem1->l_hatom);
		t_llllelem *head_elem = ll->l_head;
		for (elem2 = head_elem->l_next; elem2; elem2 = elem2->l_next) {
			t_llll *edge = llll_get();
			llll_appendhatom_clone(edge, &head_elem->l_hatom, 0, WHITENULL_llll);
			llll_appendhatom_clone(edge, &elem2->l_hatom, 0, WHITENULL_llll);
			llll_appendllll(*out_edges, edge, 0, WHITENULL_llll);
		}
	}

	
	llll_remove_lllls_from_lthing(ll);
	llll_free(ll);
}




char llllelem_exists_and_is_sym(t_llllelem *elem, t_symbol *sym)
{
    if (elem && hatom_gettype(&elem->l_hatom) == H_SYM && hatom_getsym(&elem->l_hatom) == sym)
        return 1;
    return 0;
}





// DESTRUCTIVE: pads the incoming <ll> depending on the <mode> (= 0: repeat last element,
// = 1: loop, = 2: mirror back'n'forth loop) with <num_loopelems> elements taken from the
// <reservoir>, according to the <align> attribute (0 = align left, 1 = align center, 2 = align right).
// <rounding_direction> is ONLY used for centering align, when non-integer sized elements should be put at left or right
// 0 = round to left (= put one more element at right), 1 = round to right (= put one more element at left)
void llll_pad(t_llll *ll, long output_length, char align, e_pad_mode mode, long num_loop_elems, t_llll *reservoir, char allow_trimming, char rounding_direction)
{
    if (!ll)
        return;
    
    t_llllelem *elem, *temp;
    long i, count, size = ll->l_size;
    long num_left = 0, num_right = 0;

    if (size == output_length)
        return;
    
    if (size > output_length) {
        if (allow_trimming) {
            long num_to_delete =  size - output_length;
            switch (align) {
                case 2: // align right
                    num_left = num_to_delete;
                    num_right = 0;
                    break;
                case 1: // align center
                    if (rounding_direction == 0) {
                        num_right = num_to_delete/2;
                        num_left = num_to_delete - num_right;
                    } else {
                        num_left = num_to_delete/2;
                        num_right = num_to_delete - num_left;
                    }
                    break;
                default: // align left
                    num_left = 0;
                    num_right = num_to_delete;
                    break;
            }

            // deleting at left
            for (i = 0, elem = ll->l_head; elem && i < num_left; i++, elem = temp) {
                temp = elem->l_next;
                llll_destroyelem(elem);
            }

            // deleting at right
            for (i = 0, elem = ll->l_tail; elem && i < num_right; i++, elem = temp) {
                temp = elem->l_prev;
                llll_destroyelem(elem);
            }
        }
        return; // in any case
    }
    
    
    long num_to_add =  output_length - size;
    switch (align) {
        case 2: // align right
            num_left = num_to_add;
            num_right = 0;
            break;
        case 1: // align center
            if (rounding_direction == 0) {
                num_left = num_to_add/2;
                num_right = num_to_add - num_left;
            } else {
                num_right = num_to_add/2;
                num_left = num_to_add - num_right;
            }
            break;
        default: // align left
            num_left = 0;
            num_right = num_to_add;
            break;
    }
    
    // we keep them, since these might change later on when we pad
    t_llllelem *head = reservoir && reservoir->l_size > 0 ? reservoir->l_head : ll->l_head;
    t_llllelem *tail = reservoir && reservoir->l_size > 0 ? reservoir->l_tail : ll->l_tail;
    if (num_loop_elems == 0) num_loop_elems = num_to_add + 10; // doesn't matter, we'll never get there
    long curr_dir = -1, next_curr_dir = 0;
    
    // padding at left
    switch (mode) {
        case BACH_PAD_REPEAT: elem = head; count = 0; break;
        case BACH_PAD_LOOP_PALINDROME: elem = head; count = 0; curr_dir = 1; break;
        case BACH_PAD_LOOP_PALINDROME_NO_REPEAT: elem = (head != tail && num_loop_elems > 1 ? head->l_next : head); count = 1; curr_dir = 1; break;
        default: elem = tail; count = 0; break;
    }
    for (i = 0; i < num_left; i++) {
        llll_prependhatom_clone(ll, &elem->l_hatom);
        count++;
        
        if (mode == BACH_PAD_LOOP_PALINDROME || mode == BACH_PAD_LOOP_PALINDROME_NO_REPEAT) {
            if (count >= num_loop_elems || ((curr_dir < 0 && elem == head) || (curr_dir > 0 && elem == tail))) {
                count = (mode == BACH_PAD_LOOP_PALINDROME_NO_REPEAT ? 1 : 0);
                if (mode == BACH_PAD_LOOP_PALINDROME_NO_REPEAT)
                    curr_dir *= -1;
                else {
                    next_curr_dir = curr_dir * -1;
                    curr_dir = 0;
                }
            }
            elem = (curr_dir > 0 ? elem->l_next : (curr_dir < 0 ? elem->l_prev : elem));
            if (curr_dir == 0) curr_dir = next_curr_dir;
        } else if (mode == BACH_PAD_LOOP) {
            if (count >= num_loop_elems || elem == head || !elem) {
                count = 0;
                elem = tail;
            } else
                elem = elem->l_prev;
        }
    }

    // padding at right
    switch (mode) {
        case BACH_PAD_REPEAT: elem = tail; count = 0; break;
        case BACH_PAD_LOOP_PALINDROME: elem = tail; count = 0; curr_dir = -1; break;
        case BACH_PAD_LOOP_PALINDROME_NO_REPEAT: elem = (tail != head && num_loop_elems > 1 ? tail->l_prev : tail); count = 1; curr_dir = -1; break;
        default: elem = head; count = 0; break;
    }
    for (i = 0; i < num_right; i++) {
        llll_appendhatom_clone(ll, &elem->l_hatom);
        count++;
        
        if (mode == BACH_PAD_LOOP_PALINDROME || mode == BACH_PAD_LOOP_PALINDROME_NO_REPEAT) {
            if (count >= num_loop_elems || ((curr_dir < 0 && elem == head) || (curr_dir > 0 && elem == tail))) {
                count = (mode == BACH_PAD_LOOP_PALINDROME_NO_REPEAT ? 1 : 0);
                if (mode == BACH_PAD_LOOP_PALINDROME_NO_REPEAT)
                    curr_dir *= -1;
                else {
                    next_curr_dir = curr_dir * -1;
                    curr_dir = 0;
                }
            }
            elem = (curr_dir > 0 ? elem->l_next : (curr_dir < 0 ? elem->l_prev : elem));
            if (curr_dir == 0) curr_dir = next_curr_dir;
        } else if (mode == BACH_PAD_LOOP) {
            if (count >= num_loop_elems || elem == tail || !elem) {
                count = 0;
                elem = head;
            } else
                elem = elem->l_next;
        }
    }
}




t_llllelem *llll_appendelem_clone_preserve_lthing(t_llll *where, t_llllelem *elem, long flags, t_llll *adopter)
{
    t_llllelem *new_elem = llll_appendhatom_clone(where, &elem->l_hatom, flags, adopter);
    new_elem->l_thing = elem->l_thing;
    return new_elem;
}


