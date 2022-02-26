/*
 *  llll_settheory.c
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

#include "math/llll_settheory.h"
#include "ext_common.h"


// returns -1 if the first set1 < set2
// returns 0 if the first set1 == set2
// returns 1 if the first set1 > set2
// sets HAVE already to be ordered! (sorted by elements)
char pcset_compare_lexicographically(t_llll *pcset1, t_llll *pcset2) {
	t_llllelem *elem1, *elem2;
	for (elem1 = pcset1->l_head, elem2 = pcset2->l_head; elem1 && elem2; elem1 = elem1->l_next, elem2 = elem2->l_next) {
		long l1 = hatom_getlong(&elem1->l_hatom);
		long l2 = hatom_getlong(&elem2->l_hatom);
		
		if (l1 < l2)
			return -1;
		else if (l1 > l2)
			return 1;
	}

	if (elem1)
		return 1;
	else if (elem2)
		return -1;
	else
		return 0;
}

void pcset_modulo_inplace(t_llll **pcset, long modulo, char also_sort){
	t_llllelem *elem;
	if (!modulo) 
		return;
	for (elem = (*pcset)->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_LONG) {
			long a = hatom_getlong(&elem->l_hatom);
			a = a % modulo;
			if (a < 0) 
				a = modulo + a;
			hatom_setlong(&elem->l_hatom, a);
		} else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *this_llll = hatom_getllll(&elem->l_hatom);
			pcset_modulo_inplace(&this_llll, modulo, also_sort);
		}
	if (also_sort && (*pcset)->l_depth == 1) 
		llll_inplacesort(*pcset, (sort_fn)llll_leq_elem);
}

void pcset_transpose_inplace(t_llll **pcset, long transp_step, long modulo, char also_sort){
	t_llllelem *elem;
	if (!modulo) 
		return;
	for (elem = (*pcset)->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_LONG || hatom_gettype(&elem->l_hatom) == H_DOUBLE || hatom_gettype(&elem->l_hatom) == H_RAT) {
			long a = hatom_getlong(&elem->l_hatom);
			a = (a + transp_step) % modulo;
			if (a < 0) 
				a = modulo + a;
			hatom_setlong(&elem->l_hatom, a);
		} else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *this_llll = hatom_getllll(&elem->l_hatom);
			pcset_transpose_inplace(&this_llll, transp_step, modulo, also_sort);
		}
	if (also_sort && (*pcset)->l_depth == 1) 
		llll_inplacesort(*pcset, (sort_fn)llll_leq_elem);
}

void pcset_invert_inplace(t_llll **pcset, long modulo, char also_sort){
	t_llllelem *elem;
	if (!modulo) 
		return;
	for (elem = (*pcset)->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_LONG || hatom_gettype(&elem->l_hatom) == H_DOUBLE || hatom_gettype(&elem->l_hatom) == H_RAT) {
			long a = hatom_getlong(&elem->l_hatom);
			a = (-a) % modulo;
			if (a < 0) 
				a = modulo + a;
			hatom_setlong(&elem->l_hatom, a);
		} else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *this_llll = hatom_getllll(&elem->l_hatom);
			pcset_invert_inplace(&this_llll, modulo, also_sort);
		}
	if (also_sort && (*pcset)->l_depth == 1)
		llll_inplacesort(*pcset, (sort_fn)llll_leq_elem);
}

void pcset_multiply_in_place(t_llll **pcset, long factor, long modulo, char also_sort){
	t_llllelem *elem;
	if (!modulo) 
		return;
	for (elem = (*pcset)->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_LONG || hatom_gettype(&elem->l_hatom) == H_DOUBLE || hatom_gettype(&elem->l_hatom) == H_RAT) {
			long a = hatom_getlong(&elem->l_hatom);
			a = (a * factor) % modulo;
			if (a < 0) 
				a = modulo + a;
			hatom_setlong(&elem->l_hatom, a);
		} else if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *this_llll = hatom_getllll(&elem->l_hatom);
			pcset_multiply_in_place(&this_llll, factor, modulo, also_sort);
		}
	if (also_sort && (*pcset)->l_depth == 1) 
		llll_inplacesort(*pcset, (sort_fn)llll_leq_elem);
}

t_llll *pcset_complement(t_llll *pcset, long modulo){
	t_llllelem *elem;
	long i;
	t_llll *out_list;

	if (!modulo) return NULL;

	out_list = llll_get();
	for (i = 0; i < modulo; i++) {
		char found = false;
		for (elem = pcset->l_head; elem; elem = elem->l_next)
			if (hatom_gettype(&elem->l_hatom) == H_LONG || hatom_gettype(&elem->l_hatom) == H_DOUBLE || hatom_gettype(&elem->l_hatom) == H_RAT)
				if (hatom_getlong(&elem->l_hatom) == i) {
					found = true;
					break;
				}
		if (!found)
			llll_appendlong(out_list, i, 0, WHITENULL_llll);
	}
	return out_list;
}

long pcset_get_extension(t_llll *pcset){
	t_hatom *min = NULL, *max = NULL;
	t_llll *minaddress = llll_get(), *maxaddress = llll_get();
	long ext = 0;
	
	llll_minmax(pcset, &min, &max, minaddress, maxaddress, 1, 1);
	
	llll_free(minaddress);
	llll_free(maxaddress);
	
	ext = (max ? hatom_getlong(max) : 0) - (min ? hatom_getlong(min) : 0);
	
	return ext;
}


t_llll* pcset_get_primeform(t_llll *pcset, long modulo, e_primeform_modes mode, e_settheory_groups group, long *multipl_comp, long *transp_comp) {
	t_llll *candidate = llll_get();
	t_llll *best_candidate = NULL;
	t_llllelem *elem;
	long best_candidate_extension = -1, this_candidate_extension = 0, this_elem;
	long prev_elem = 0;

	if (!pcset || !pcset->l_head) {
		llll_free(candidate);
		return llll_get();
	}

	llll_clone_upon(pcset, candidate);
	pcset_modulo_inplace(&candidate, modulo, true);
	// proper sorting of last-depth-level lllls has already been done by pcset_modulo_inplace

	if (!candidate) 
		return llll_get();
		
//	char *buf;
	for (elem = pcset->l_head; elem; elem = elem->l_next) {
		this_elem = hatom_getlong(&elem->l_hatom);
		pcset_transpose_inplace(&candidate, prev_elem - this_elem, modulo, true);
		if (mode == k_PRIMEFORM_MODE_COMPACTNESS_FIRST) 
			this_candidate_extension = pcset_get_extension(candidate);
		
		if (!best_candidate || 
			(mode == k_PRIMEFORM_MODE_LEXICOGRAPHIC && pcset_compare_lexicographically(candidate, best_candidate) == -1) || 
			(mode == k_PRIMEFORM_MODE_COMPACTNESS_FIRST && 
					(this_candidate_extension < best_candidate_extension ||
					 (this_candidate_extension == best_candidate_extension && pcset_compare_lexicographically(candidate, best_candidate) == -1)))) {

			if (best_candidate) 
				llll_free(best_candidate);
			best_candidate = llll_clone(candidate);
			best_candidate_extension = this_candidate_extension;
			if (multipl_comp) 
				*multipl_comp = 1; 
			if (transp_comp) 
				*transp_comp = -this_elem;

		}
		prev_elem = this_elem;
	}
	

	if (group == k_GROUP_TI) {
		t_llll *inversion = llll_clone(pcset);
		pcset_invert_inplace(&inversion, modulo, true);
	
		llll_free(candidate);
		candidate = llll_clone(inversion);
		prev_elem = 0;

		for (elem = inversion->l_head; elem; elem = elem->l_next) {
			this_elem = hatom_getlong(&elem->l_hatom);
			pcset_transpose_inplace(&candidate, prev_elem - this_elem, modulo, true);
			if (mode == k_PRIMEFORM_MODE_COMPACTNESS_FIRST) 
				this_candidate_extension = pcset_get_extension(candidate);
			
			if (!best_candidate || 
				(mode == k_PRIMEFORM_MODE_LEXICOGRAPHIC && pcset_compare_lexicographically(candidate, best_candidate) == -1) || 
				(mode == k_PRIMEFORM_MODE_COMPACTNESS_FIRST && 
				 (this_candidate_extension < best_candidate_extension ||
				  (this_candidate_extension == best_candidate_extension && pcset_compare_lexicographically(candidate, best_candidate) == -1)))) {
				
				if (best_candidate) llll_free(best_candidate);
				best_candidate = llll_clone(candidate);
				best_candidate_extension = this_candidate_extension;
				if (multipl_comp) 
					*multipl_comp = modulo - 1; 
				if (transp_comp) 
					*transp_comp = -this_elem;
				
			}
			prev_elem = this_elem;
		}
		llll_free(inversion);
	}

	if (group == k_GROUP_AFF) {
		long i;
		for (i = 1; i < modulo; i++) {
			if (gcd(i, modulo) == 1) { // we only want multiplications M_p with p prime to n 
				t_llll *multipl_i = llll_clone(pcset);
				pcset_multiply_in_place(&multipl_i, i, modulo, true);
				
				llll_free(candidate);
				candidate = llll_clone(multipl_i);
				prev_elem = 0;
				
				for (elem = multipl_i->l_head; elem; elem = elem->l_next) {
					this_elem = hatom_getlong(&elem->l_hatom);
					pcset_transpose_inplace(&candidate, prev_elem - this_elem, modulo, true);
					if (mode == k_PRIMEFORM_MODE_COMPACTNESS_FIRST) 
						this_candidate_extension = pcset_get_extension(candidate);
					
					if (!best_candidate || 
						(mode == k_PRIMEFORM_MODE_LEXICOGRAPHIC && pcset_compare_lexicographically(candidate, best_candidate) == -1) || 
						(mode == k_PRIMEFORM_MODE_COMPACTNESS_FIRST && 
						 (this_candidate_extension < best_candidate_extension ||
						  (this_candidate_extension == best_candidate_extension && pcset_compare_lexicographically(candidate, best_candidate) == -1)))) {
						
						if (best_candidate) 
							llll_free(best_candidate);
						best_candidate = llll_clone(candidate);
						best_candidate_extension = this_candidate_extension;
						if (multipl_comp) 
							*multipl_comp = i; 
						if (transp_comp) 
							*transp_comp = -this_elem;
						
					}
					prev_elem = this_elem;
				}
				llll_free(multipl_i);
			}
		} 
	}
	
	llll_free(candidate);

	return best_candidate;
}

char pcset_is_prime_form(t_llll *pcset, long modulo, e_primeform_modes mode, e_settheory_groups group) {
	t_llll *primeform = pcset_get_primeform(pcset, modulo, mode, group, NULL, NULL);
	char res = llll_eq_ignoretype(pcset, primeform);
	llll_free(primeform);
	return res;
}

t_llll *long_array2llll(long *array, long size){
	t_llll *outllll = llll_get();
	long i;
	for (i = 0; i < size; i++)
		llll_appendlong(outllll, array[i], 0, WHITENULL_llll);
	return outllll;
}

t_llll *get_all_prime_forms(long modulo, long cardinality, e_primeform_modes mode, e_settheory_groups group) {
	long *pc;
	long i, c;
	char entered;
	t_llll *out_llll = llll_get();
	pc = (long *) bach_newptr(cardinality * sizeof(long));
	
	for (i = 0; i < cardinality; i++)
		pc[i] = i;
	
	c = cardinality - 1;
	while (true){
		t_llll *thisllll = long_array2llll(pc, cardinality);
		if (pcset_is_prime_form(thisllll, modulo, mode, group))
			llll_appendllll(out_llll, thisllll, 0, WHITENULL_llll);
		else
			llll_free(thisllll);
		
		pc[c]++;
		entered = false;
		while (pc[c] >= modulo - (cardinality - c - 1)) {
			c--;
 			entered = true;
			if (c < 1) 
				break;
			pc[c]++;
		}
		
		if (c < 1) 
			break;

		if (entered)
			for (i = c+1; i < cardinality; i++)
				pc[i] = pc[i-1]+1;

		c = cardinality - 1;
	}
	bach_freeptr(pc);
	return out_llll;
}



long llll_long_sum(t_llll *in_llll){
	long sum = 0;
	t_llllelem *elem;
	for (elem = in_llll->l_head; elem; elem = elem->l_next)
		sum += hatom_getlong(&elem->l_hatom);
	return sum;
}

long pcset_find_period_in_steps(t_llll *pcset, long modulo){
	t_llll *istruct = pcset_istruct(pcset, modulo);
	t_llll *period_struct = llll_get_period(istruct);
	long period = llll_long_sum(period_struct);
	llll_free(istruct);
	llll_free(period_struct);
	return period;
}

// tells us if an llll A is in a list of type (B C D E ...)
char llll_is_in_llll_list(t_llll *llll_to_search, t_llll *llll_list){
	t_llllelem *elem;
	for (elem = llll_list->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_LLLL)
			if (llll_eq_ignoretype(llll_to_search, hatom_getllll(&elem->l_hatom)))
				return true;
	return false;
}

long pcset_num_copies(t_llll *container, t_llll *contained, long modulo, e_settheory_groups group, char count_periodic_subsets_once) {
	t_llll *candidate;
	long i, count = 0, count_partial = 0;
	long period = modulo;
	
	if (!contained || !container) 
		return -1;

	candidate = llll_clone(contained);

	if (group == k_GROUP_ID) { // only IDENTITY group!
		char res = llll_is_subset_of(container, candidate);
		llll_free(candidate);
		return res; 
	}
	
	count_partial = 0;
	for (i = 0; i < modulo; i++){
		if (llll_is_subset_of(container, candidate))
			count_partial++;
		pcset_transpose_inplace(&candidate, 1, modulo, true);
	}
	
	// dealing with periodicity: if the subset is periodic, we have to count less times!
	if (count_periodic_subsets_once) {
		if (contained->l_size > 2) {
			period = pcset_find_period_in_steps(contained, modulo);
			if (period < modulo)
				count_partial /= (modulo / period);
		} else if (contained->l_size == 2 && (modulo % 2 == 0)) { 
			// computationally better way to deal with the case of simple interval embedding!
			long diff = hatom_getlong(&contained->l_tail->l_hatom) - hatom_getlong(&contained->l_head->l_hatom);
			diff = diff % modulo;
			if (diff < 0) diff = diff + modulo;
			if (diff * 2 == modulo)
				count_partial /= 2;
		}
	}
	count += count_partial;
	
	// dealing with inversion: if it is requested (and if the set is not symmetrical)
	if (group == k_GROUP_TI && contained->l_size > 2 && (!pcset_is_symmetrical(contained, modulo))) {
		pcset_invert_inplace(&candidate, modulo, true);
		
		count_partial = 0;
		for (i = 0; i < modulo; i++){
			if (llll_is_subset_of(container, candidate))
				count_partial++;
			pcset_transpose_inplace(&candidate, 1, modulo, true);
		}
		
		// dealing with periodicity: if the subset is periodic, we have to count less times!
		if (count_periodic_subsets_once && period < modulo)
			count_partial /= (modulo / period);
				
		count += count_partial;
	}

	// dealing with affine groups: if it is requested (and if the set is not symmetrical)
	if (group == k_GROUP_AFF) {
		long m;
		t_llll *multipl_m_collection = llll_get();
		t_llll *contained_trasp_primeform = pcset_get_primeform(contained, modulo, k_PRIMEFORM_MODE_LEXICOGRAPHIC, k_GROUP_T, NULL, NULL);
		llll_appendllll(multipl_m_collection, contained_trasp_primeform, 0, WHITENULL_llll);
		for (m = 2; m < modulo; m++) {
			if (gcd(m, modulo) == 1) { // we only want multiplications M_p with p prime to n 
				t_llll *multipl_m;
				t_llll *multipl_m_trasp_primeform;

				multipl_m = llll_clone(contained);
				pcset_multiply_in_place(&multipl_m, m, modulo, true);
				multipl_m_trasp_primeform = pcset_get_primeform(multipl_m, modulo, k_PRIMEFORM_MODE_LEXICOGRAPHIC, k_GROUP_T, NULL, NULL);
				
				if (!llll_is_in_llll_list(multipl_m_trasp_primeform, multipl_m_collection)) {
					llll_appendllll(multipl_m_collection, multipl_m_trasp_primeform, 0, WHITENULL_llll);
					
					llll_free(candidate);
					candidate = llll_clone(multipl_m);
					
					count_partial = 0;
					for (i = 0; i < modulo; i++){
						if (llll_is_subset_of(container, candidate))
							count_partial++;
						pcset_transpose_inplace(&candidate, 1, modulo, true);
					}
					
					if (count_periodic_subsets_once) {
						period = pcset_find_period_in_steps(multipl_m, modulo);
						if (period < modulo)
							count_partial /= (modulo / period);
					}
					
					count += count_partial;
				} else 
					llll_free(multipl_m_trasp_primeform);

				llll_free(multipl_m);
			}
		}
		llll_free(multipl_m_collection);
	}
	
	llll_free(candidate);
	return count;
}

t_llll* pcset_istruct(t_llll *pcset, long modulo) {
	t_llllelem *elem;
	t_llll *istruct;
	long this_elem, prev_elem = 0;
	
	if (!pcset) 
		return NULL;
	istruct = llll_get();
	
	if (pcset->l_head && pcset->l_head->l_next) {
		prev_elem = hatom_getlong(&pcset->l_head->l_hatom);
		for (elem = pcset->l_head->l_next; elem; elem = elem->l_next){
			this_elem = hatom_getlong(&elem->l_hatom);
			llll_appendlong(istruct, this_elem - prev_elem, 0, WHITENULL_llll);
			prev_elem = this_elem;
		}
	}
	llll_appendlong(istruct, modulo - prev_elem, 0, WHITENULL_llll);
	return istruct;
}


char pcset_is_symmetrical(t_llll *pcset, long modulo) {
	char res;
	t_llll *pf1, *pf2;
	t_llll *inverse = llll_clone(pcset);
	pcset_invert_inplace(&inverse, modulo, true);
	pf1 = pcset_get_primeform(pcset, modulo, k_PRIMEFORM_MODE_LEXICOGRAPHIC, k_GROUP_T, NULL, NULL);
	pf2 = pcset_get_primeform(inverse, modulo, k_PRIMEFORM_MODE_LEXICOGRAPHIC, k_GROUP_T, NULL, NULL);
	res = llll_eq_ignoretype(pf1, pf2);
	llll_free(inverse);
	llll_free(pf1);
	llll_free(pf2);
	return res;
}

t_llll* pcset_mvector(t_llll *pcset, t_llll *list_of_subsets, long modulo, e_settheory_groups group, char count_periodic_subsets_once) {
 	t_llll *mvector;
	t_llllelem *elem;

	if (!pcset || !list_of_subsets)
		return NULL;

	mvector = llll_get();
	for (elem = list_of_subsets->l_head; elem; elem = elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_LLLL)
			llll_appendlong(mvector, pcset_num_copies(pcset, hatom_getllll(&elem->l_hatom), modulo, group, count_periodic_subsets_once), 0, WHITENULL_llll);
	
	return mvector;
}

// 1 if mvector of set is equal to vec, 0 otherwise (faster than checking whole mvector computation!)
char is_mvector_of_pcset_equal_to_vec(t_llll *pcset, t_llll *list_of_subsets, t_llll *vec, long modulo, e_settheory_groups group, char count_periodic_subset_once) {
	t_llllelem *elem, *vec_elem;

	if (!pcset || !list_of_subsets)
		return 0;

	if (vec->l_size != list_of_subsets->l_size)
		return 0;
		
	for (elem = list_of_subsets->l_head, vec_elem = vec->l_head; elem && vec_elem; elem = elem->l_next, vec_elem = vec_elem->l_next)
		if (hatom_gettype(&elem->l_hatom) == H_LLLL && hatom_gettype(&vec_elem->l_hatom) == H_LONG)
			if (pcset_num_copies(pcset, hatom_getllll(&elem->l_hatom), modulo, group, count_periodic_subset_once) != hatom_getlong(&vec_elem->l_hatom))
				return 0;
	
	return 1;
}

t_llll* find_zrelated_pcsets(long modulo, long set_cardinality, long subset_cardinality, e_primeform_modes mode, e_settheory_groups group, char count_periodic_subsets_once, long z_families_min_card, t_llll **ivecs) {
	t_llllelem *pf_elem1, *pf_elem2, *temp;
	t_llll *pf = get_all_prime_forms(modulo, set_cardinality, mode, group);
	t_llll *pf_sub = get_all_prime_forms(modulo, subset_cardinality, mode, group);
	t_llll *zset = llll_get();
	
	if (ivecs)
		*ivecs = llll_get();
	
	for (pf_elem1 = pf->l_head; pf_elem1; pf_elem1 = pf_elem1->l_next){
		t_llll *set1 = hatom_getllll(&pf_elem1->l_hatom);
		t_llll *vec1 = pcset_mvector(set1, pf_sub, modulo, group, count_periodic_subsets_once);
		t_llll *zrel_to_set1 = llll_get();
		llll_appendhatom_clone(zrel_to_set1, &pf_elem1->l_hatom, 0, WHITENULL_llll);
		pf_elem2 = pf_elem1->l_next;
		while (pf_elem2){
			t_llll *set2 = hatom_getllll(&pf_elem2->l_hatom);
			if (is_mvector_of_pcset_equal_to_vec(set2, pf_sub, vec1, modulo, group, count_periodic_subsets_once)) {
				llll_appendhatom_clone(zrel_to_set1, &pf_elem2->l_hatom, 0, WHITENULL_llll);
				temp = pf_elem2->l_next;
				llll_destroyelem(pf_elem2);
				pf_elem2 = temp;
			} else
				pf_elem2 = pf_elem2->l_next;
		}
		
		if ((long)zrel_to_set1->l_size < z_families_min_card) {
			llll_free(zrel_to_set1);
			llll_free(vec1);
		} else {
			llll_appendllll(zset, zrel_to_set1, 0, WHITENULL_llll);
			if (ivecs)
				llll_appendllll(*ivecs, vec1, 0, WHITENULL_llll);
			else
				llll_free(vec1);
		}
	} 
	
	llll_free(pf);
	llll_free(pf_sub);

	return zset;
}

long mc_to_pitch_class(long mc, long modulo)
{
	return ((long)round((positive_mod(mc, 1200))/(1200./modulo))) % modulo;
}



t_tonnetz_diatonic_interval build_diatonic_interval(long diatonic_steps, long chromatic_steps)
{
	t_tonnetz_diatonic_interval interval;
	interval.diatonic_steps = diatonic_steps;
	interval.chromatic_steps = chromatic_steps;
	interval.frequency_ratio = long2rat(1);
    interval.user_defined_ratio = false;
	return interval;
}


t_tonnetz_diatonic_interval diatonic_interval_sum(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2)
{
	t_tonnetz_diatonic_interval interval;
	interval.diatonic_steps = interval1.diatonic_steps + interval2.diatonic_steps;
	interval.chromatic_steps = interval1.chromatic_steps + interval2.chromatic_steps;
	interval.user_defined_ratio = interval1.user_defined_ratio && interval2.user_defined_ratio;
	interval.frequency_ratio = rat_rat_prod(interval1.frequency_ratio, interval2.frequency_ratio);
	return interval;
}

t_tonnetz_diatonic_interval diatonic_interval_sum_no_freqratio(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2)
{
	t_tonnetz_diatonic_interval interval;
	interval.diatonic_steps = interval1.diatonic_steps + interval2.diatonic_steps;
	interval.chromatic_steps = interval1.chromatic_steps + interval2.chromatic_steps;
	interval.frequency_ratio = long2rat(1);
	interval.user_defined_ratio = false;
	return interval;
}


t_tonnetz_diatonic_interval diatonic_interval_diff(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2)
{
	t_tonnetz_diatonic_interval interval;
	interval.diatonic_steps = interval1.diatonic_steps - interval2.diatonic_steps;
	interval.chromatic_steps = interval1.chromatic_steps - interval2.chromatic_steps;
	interval.user_defined_ratio = interval1.user_defined_ratio | interval2.user_defined_ratio;
	interval.frequency_ratio = rat_rat_div(interval1.frequency_ratio, interval2.frequency_ratio);
	return interval;
}


t_tonnetz_diatonic_interval diatonic_interval_diff_no_freqratio(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2)
{
	t_tonnetz_diatonic_interval interval;
	interval.diatonic_steps = interval1.diatonic_steps - interval2.diatonic_steps;
	interval.chromatic_steps = interval1.chromatic_steps - interval2.chromatic_steps;
	interval.frequency_ratio = long2rat(1);
	interval.user_defined_ratio = false;
	return interval;
}


double freqratio_to_mc(t_rational freqratio)
{
	return 1200. * log(((double)freqratio.r_num)/freqratio.r_den)/log(2.0);
}

void diatonic_interval_to_screen_midicents_and_accidental(t_tonnetz_diatonic_interval interval, long *screen_midicents, t_rational *screen_accidental, long modulo)
{
	t_rational tone_division = genrat(modulo, 6);
	long diat = interval.diatonic_steps;
	long chrom = interval.chromatic_steps;
	long octave = (long)floor(diat/7.); // 0 = middle octave
	diat -= 7 * octave;
	chrom -= modulo * octave;
	
	octave += 5;
	*screen_midicents = diatonicstep2midicents(diat, octave);	
	
	long amount = 0;
	switch (diat) {
		case 0: amount = 0; break;
		case 1: amount = 2; break;
		case 2: amount = 4; break;
		case 3: amount = 5; break;
		case 4: amount = 7; break;
		case 5: amount = 9; break;
		case 6: amount = 11; break;
	}
	
	
	{
		t_rational sc_acc = tone_division;
		sc_acc.r_den *= 2;
		sc_acc.r_num *= amount;
		sc_acc.r_num -= chrom * sc_acc.r_den;
		sc_acc.r_num *= -1;
		sc_acc.r_num *= tone_division.r_den;
		sc_acc.r_den *= tone_division.r_num;
		
		if (true) {
			// faster 32-bit int version
			t_int32 num = (t_int32)sc_acc.r_num;
			t_int32 den = (t_int32)sc_acc.r_den;
			long_long_reduce_int32(&num, &den);
			screen_accidental->r_num = num;
			screen_accidental->r_den = den;
		} else {
			rat_reduce(&sc_acc);
			*screen_accidental = sc_acc;
		}

		// the above is an optimized version of 
		// *screen_accidental = rat_rat_div(long_rat_diff(chrom, rat_long_prod(rat_long_div(tone_division, 2), amount)), tone_division);
	}
}



t_tonnetz_diatonic_interval screen_midicents_and_accidental_to_diatonic_interval(long screen_midicents, t_rational screen_accidental, long modulo)
{
	long octave = (long)floor((screen_midicents - 6000)/1200.);
	long diat = midicents2diatonicstep(screen_midicents);
	
	long amount = 0;
	switch (diat) {
		case 0: amount = 0; break;
		case 1: amount = 2; break;
		case 2: amount = 4; break;
		case 3: amount = 5; break;
		case 4: amount = 7; break;
		case 5: amount = 9; break;
		case 6: amount = 11; break;
	}
	
	t_rational amount1 = rat_rat_prod(genrat(modulo, 12), rat_long_sum(rat_long_prod(screen_accidental, 2), amount + 12 * octave));
	diat += 7 * octave;
	
	t_tonnetz_diatonic_interval interval;
	interval.diatonic_steps = diat;
	interval.chromatic_steps = amount1.r_num/amount1.r_den;
	
	return interval;
}


t_tonnetz_diatonic_interval notename_to_diatonic_interval(long middleC_octave, char *name, long modulo)
{
	long screen_mc;
	t_rational screen_acc;
	notename2midicents(middleC_octave, NULL, name, &screen_mc, &screen_acc);
	return screen_midicents_and_accidental_to_diatonic_interval(screen_mc, screen_acc, modulo);
}

