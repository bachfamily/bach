/*
 *  llll_linearalgebra.c
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

#include "math/llll_linearalgebra.h"
#include <ext_common.h> 

// returns the matrix having 1's on the diagonal, and 0 elsewhere
t_llll* llll_get_identity_matrix(long size){
	long i, j;
	t_llll *out_llll;
	
	if (size < 0)
		return NULL;
	
	out_llll = llll_get();

	for (i = 0; i < size; i++) {
		t_llll *row_llll = llll_get();
		for (j = 0; j < size; j++)
			llll_appendlong(row_llll, (i == j) ? 1 : 0, 0, WHITENULL_llll);
		llll_appendllll(row_llll, out_llll, 0, WHITENULL_llll);
	}

	return out_llll;
}

// returns the matrix having as main diagonal the input llll
// if shift > 0, the object will be shifted on the other diagonals
t_llll* llll_get_diagonal_matrix(t_llll *diagonal, long shift){
	long i, j, size;
	t_llll *out_llll;
	t_llllelem *elem; 
	
	if (!diagonal || diagonal->l_size == 0)
		return NULL;
	
	out_llll = llll_get();
	size = diagonal->l_size;
	
	for (i = 0, elem = diagonal->l_head; elem && i < size; i++, elem = elem->l_next) {
		t_llll *row_llll = llll_get();
		for (j = 0; j < size; j++)
			if ((shift == 0 && i == j) || ((i + shift) % size == j || (i + shift) % size == j - size))
				llll_appendhatom_clone(row_llll, &elem->l_hatom, 0, WHITENULL_llll);
			else
				llll_appendlong(row_llll, 0, 0, WHITENULL_llll);
		llll_appendllll(out_llll, row_llll, 0, WHITENULL_llll);
	}

	return out_llll;
}

// perform a generic elementwise operation on matrices
t_llll* llll_matrix_matrix_elementwise_operation(t_llll *matrix1, t_llll *matrix2, t_lexpr_token *op){
	t_llllelem *row_elem1, *column_elem1, *row_elem2, *column_elem2;
	t_llll *outmatrix;
	long err;
	
	if (!matrix1 || !matrix2)
		return NULL;
	
	outmatrix = llll_get();
	for (row_elem1 = matrix1->l_head, row_elem2 = matrix2->l_head; row_elem1 && row_elem2; row_elem1 = row_elem1->l_next, row_elem2 = row_elem2->l_next) {
		if (hatom_gettype(&row_elem1->l_hatom) == H_LLLL && hatom_gettype(&row_elem2->l_hatom) == H_LLLL) {
			t_llll *row_llll = llll_get();
			for (column_elem1 = matrix1->l_head, column_elem2 = matrix2->l_head; column_elem1 && column_elem2; 
					column_elem1 = column_elem1->l_next, column_elem2 = column_elem2->l_next){
				t_hatom res;
				err = lexpr_eval_one(op, &column_elem1->l_hatom, &column_elem2->l_hatom, NULL, &res);
				if (!err)
					llll_appendhatom_clone(row_llll, &res, 0, WHITENULL_llll);
				else
					llll_appendlong(row_llll, 0, 0, WHITENULL_llll);
			}		
			llll_appendllll(outmatrix, row_llll, 0, WHITENULL_llll);
		} else {
			// we treat this as operation on two simple hatoms
			t_hatom res;
			err = lexpr_eval_one(op, &row_elem1->l_hatom, &row_elem2->l_hatom, NULL, &res);
			if (!err)
				llll_appendhatom_clone(outmatrix, &res, 0, WHITENULL_llll);
			else
				llll_appendlong(outmatrix, 0, 0, WHITENULL_llll);
		}
	}
	return outmatrix;
}

t_llll* llll_matrix_matrix_sum(t_llll *matrix1, t_llll *matrix2){
	t_lexpr_token plus = get_plus_operator();
	return llll_matrix_matrix_elementwise_operation(matrix1, matrix2, &plus);
}

t_llll* llll_matrix_matrix_diff(t_llll *matrix1, t_llll *matrix2){
	t_lexpr_token minus = get_minus_operator();
	return llll_matrix_matrix_elementwise_operation(matrix1, matrix2, &minus);
}

// perform the scalar products between two vectors <v,w> = v.w^T = sum_i v_i*w_i
t_hatom llll_vector_vector_product(t_llll *vector1, t_llll *vector2){
	t_llllelem *elem1, *elem2;
	t_hatom res_hatom, partial_res_hatom;
	long err;
	const t_lexpr_token times = get_times_operator();
	const t_lexpr_token plus = get_plus_operator();
		
	hatom_setlong(&res_hatom, 0);
	
	if (!vector1 || !vector2)
		return res_hatom;
		
	for (elem1 = vector1->l_head, elem2 = vector2->l_head; elem1 && elem2; elem1 = elem1->l_next, elem2 = elem2->l_next) {
		hatom_setlong(&partial_res_hatom, 0);
		err = lexpr_eval_one(&times, &elem1->l_hatom, &elem2->l_hatom, NULL, &partial_res_hatom);
		if (!err)
			err = lexpr_eval_one(&plus, &res_hatom, &partial_res_hatom, NULL, &res_hatom);
	}
	return res_hatom;
}

// perform the scalar-vector product
t_llll* llll_scalar_vector_product(t_hatom *scalar, t_llll *vector){
	return llll_scalar_matrix_product(scalar, vector);
}

// perform the scalar-vector product
// the function works on the structure of llll_clone
t_llll* llll_scalar_matrix_product(t_hatom *scalar, t_llll *matrix){
//void llll_clone(t_llll *inll, t_llll *outll, long legality, t_llll *adopter) {
	t_llll *outll = llll_get();
	t_llllelem *inelem;
	t_llll *templl;
	t_llll_stack *instack = llll_stack_new();
	t_llll_stack *outstack = llll_stack_new();
	t_hatom partial_res_hatom;
	long err;
//	long legality = 1;
	const t_lexpr_token times = get_times_operator();
	
	inelem = matrix->l_head;
//	outll->l_legal = legality < 0 ? matrix->l_legal : legality;
	outll->l_depth = matrix->l_depth;
	
	while (1) {
		while (inelem) {
			switch(inelem->l_hatom.h_type) {
				case H_LONG:
				case H_RAT:
				case H_DOUBLE:
					err = lexpr_eval_one(&times, &inelem->l_hatom, scalar, NULL, &partial_res_hatom);
					if (!err)
						llll_appendhatom(outll, &partial_res_hatom, 0, WHITENULL_llll);
					else
						llll_appendhatom(outll, &inelem->l_hatom, 0, WHITENULL_llll);
					inelem = inelem->l_next;
					break;
				case H_SYM:
                case H_FUNCTION:
				case H_OBJ:
					llll_appendhatom(outll, &inelem->l_hatom, 0, WHITENULL_llll);
					inelem = inelem->l_next;
					break;
				case H_LLLL:
//					if (legality == -2 && inelem->l_hatom.h_w.w_llll->l_legal == 0) {
//						llll_appendhatom(outll, &inelem->l_hatom, 0, WHITENULL_llll);
//						inelem = inelem->l_next;		
//					} else {
						llll_stack_push(outstack, outll);
						templl = llll_get();
						llll_stack_push(instack, inelem->l_next);
						matrix = inelem->l_hatom.h_w.w_llll;
						inelem = matrix->l_head;
						templl->l_depth = matrix->l_depth;		
						llll_appendllll(outll, templl, 0, WHITENULL_llll);
						outll = templl;
//					}
					break;
				default:
					inelem = inelem->l_next;
					break;
			}
		}
		if (!instack->s_items)
			break;
		inelem = (t_llllelem *) llll_stack_pop(instack);
		outll = (t_llll *) llll_stack_pop(outstack);
	}
	llll_stack_destroy(instack);
	llll_stack_destroy(outstack);
	return outll;
}


t_llll* llll_matrix_vector_product(t_llll *matrix, t_llll *vector) {
	t_llllelem *elem;
	t_llll *out_vector;
		
	if (!matrix || !vector || matrix->l_depth < 2 || vector->l_depth < 1)
		return NULL;
	
	out_vector = llll_get();
	for (elem = matrix->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_hatom part_res = llll_vector_vector_product(hatom_getllll(&elem->l_hatom), vector);
			llll_appendhatom_clone(out_vector, &part_res, 0, WHITENULL_llll);
		}
	}

	return out_vector;
}

// perform the products A*B (matrix), or A*v
// in order to perform the element-wise product, please refer to the [bach.expr object]
t_llll* llll_matrix_matrix_product(t_llll *llll1, t_llll *llll2){
	t_llll *out_llll = NULL;
	const t_lexpr_token times = get_times_operator();

	if (!llll1 || !llll2 || llll1->l_size == 0 || llll2->l_size == 0)
		return NULL;
		
	if (llll1->l_size == 1 && llll1->l_depth == 1 && llll2->l_size == 1 && llll2->l_depth == 1) { 
		// scalar times scalar
		t_hatom res_hatom;
		long err;

		out_llll = llll_get();
		err = lexpr_eval_one(&times, &llll1->l_head->l_hatom, &llll2->l_head->l_hatom, NULL, &res_hatom);
		if (err) 
			return NULL;
		llll_appendhatom_clone(out_llll, &res_hatom, 0, WHITENULL_llll);
		
	} else if (llll1->l_size == 1 && llll1->l_depth == 1 && llll2->l_size > 1 && llll2->l_depth == 1) {
		// scalar times vector 
		out_llll = llll_scalar_vector_product(&llll1->l_head->l_hatom, llll2);
	} else if (llll1->l_size > 1 && llll1->l_depth == 1 && llll2->l_size == 1 && llll2->l_depth == 1) {
		// vector times scalar 
		out_llll = llll_scalar_vector_product(&llll2->l_head->l_hatom, llll1);
	} else if (llll1->l_size > 1 && llll1->l_depth == 1 && llll2->l_size > 1 && llll2->l_depth == 1) {
		// vector times vector
		t_hatom res = llll_vector_vector_product(llll1, llll2);
		out_llll = llll_get();
		llll_appendhatom_clone(out_llll, &res, 0, WHITENULL_llll);
	} else if (llll1->l_size == 1 && llll1->l_depth == 1 && llll2->l_depth > 1) {
		// scalar times matrix
		out_llll = llll_scalar_matrix_product(&llll1->l_head->l_hatom, llll2);
	} else if (llll2->l_size == 1 && llll2->l_depth == 1 && llll1->l_depth > 1) {
		// matrix times scalar
		out_llll = llll_scalar_matrix_product(&llll2->l_head->l_hatom, llll1);
	} else if (llll1->l_size > 1 && llll1->l_depth == 1 && llll2->l_depth > 1) {
		// vector times matrix
		out_llll = llll_matrix_vector_product(llll2, llll1);
	} else if (llll2->l_size > 1 && llll2->l_depth == 1 && llll1->l_depth > 1) {
		// matrix times vector
		out_llll = llll_matrix_vector_product(llll1, llll2);
	} else if (llll1->l_depth > 1 && llll2->l_depth > 1) {
		// matrix times matrix
		t_llllelem *elem1, *elem2;
		t_llll *llll2cloned, *llll2trans;
		
		out_llll = llll_get();
		llll2cloned = llll_clone(llll2);
		llll2trans  = llll_trans(llll2cloned, 0);
		for (elem1 = llll1->l_head; elem1; elem1 = elem1->l_next) {
			t_llll *row_llll = llll_get();
			for (elem2 = llll2trans->l_head; elem2; elem2 = elem2->l_next) {
				if (hatom_gettype(&elem1->l_hatom) == H_LLLL && hatom_gettype(&elem2->l_hatom) == H_LLLL) {
					t_hatom part_res = llll_vector_vector_product(hatom_getllll(&elem1->l_hatom), hatom_getllll(&elem2->l_hatom)); // TODO: recursive? matrix-matrix product?? ^_^
					llll_appendhatom_clone(row_llll, &part_res, 0, WHITENULL_llll);
				}
			}
			llll_appendllll(out_llll, row_llll, 0, WHITENULL_llll);
		}
		llll_free(llll2trans);
	}
	
	return out_llll;
}

// calculates the trace of a matrix (sums of the elements on the main diagonal). 
// if shift!= 0 it takes a secondary diagonal 
t_hatom llll_trace(t_llll *matrix, long shift){
	t_llllelem *elem1, *elem2;
	t_llll *row_llll;
	t_hatom res_hatom;
	long i, err, index;
	const t_lexpr_token plus = get_plus_operator();
		
	hatom_setlong(&res_hatom, 0);
	
	if (!matrix)
		return res_hatom;
		
	for (i = 0, elem1 = matrix->l_head; elem1; i++, elem1 = elem1->l_next) {
		if (hatom_gettype(&elem1->l_hatom) == H_LLLL) {
			row_llll = hatom_getllll(&elem1->l_hatom);
			if (!shift || row_llll->l_size == 0)
				index = i;
			else {
				index = (i + shift) % row_llll->l_size;
				if (index < 0) index = row_llll->l_size + index;
			}
			elem2 = llll_getindex(row_llll, index + LLLL_IDX_BASE, I_NON_NEGATIVE); // 1-based
			if (elem2)
				err = lexpr_eval_one(&plus, &res_hatom, &elem2->l_hatom, NULL, &res_hatom);
		}
	}
	return res_hatom;
}

long llll_get_matrix_num_rows(t_llll *matrix){
	if (!matrix)
		return 0;
	
	return matrix->l_size;
}

// if *well_shaped, it puts 0 or 1 depending if the matrix is well shaped or not.
long llll_get_matrix_num_cols(t_llll *matrix, char *well_shaped){
	t_llllelem *elem;
	long these_cols, num_cols = -1;
	
	if (!matrix) {
		if (well_shaped) 
			*well_shaped = false;
		return 0;
	}
	
	if (well_shaped) 
		*well_shaped = true;
		
	for (elem = matrix->l_head; elem; elem = elem->l_next){
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			these_cols = hatom_getllll(&elem->l_hatom)->l_size;
			if (num_cols >= 0 && well_shaped && these_cols != num_cols)
				*well_shaped = false;
			if (these_cols > num_cols)
				num_cols = these_cols;
		}
	}
	return MAX(num_cols, 0);
}

char llll_is_matrix_well_shaped(t_llll *matrix){
	char ws = true;
	llll_get_matrix_num_cols(matrix, &ws);
	return ws;
}

char llll_is_matrix_square(t_llll *matrix){
	char ws = true;
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	return (ws && (llll_get_matrix_num_rows(matrix) == num_cols));
}

char llll_is_matrix_symmetrical(t_llll *matrix, char match_type){
	char ws = true;
	long num_rows = llll_get_matrix_num_rows(matrix);
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	long i, j;
	
	if (!ws || num_rows != num_cols) 
		return false;

	for (i = 1; i <= num_rows; i++)
		for (j = i+1; j <= num_cols; j++) 
			if (match_type) {
				if (!llll_eq_elem_matchtype(llll_get_element_in_matrix(matrix, i, j), llll_get_element_in_matrix(matrix, j, i)))
					return false;
			} else {
				if (!llll_eq_elem_ignoretype(llll_get_element_in_matrix(matrix, i, j), llll_get_element_in_matrix(matrix, j, i)))
					return false;
			}
	return true;
}

t_hatom llll_hatom_abs_if_number(t_hatom *hatom){
	t_hatom out;
	
	if (!hatom) {
		hatom_setlong(&out, 0);
		return out;
	}
		
	if (hatom->h_type == H_LONG) {
		long l = hatom_getlong(hatom);
		hatom_setlong(&out, l < 0 ? -l : l);
	} else if (hatom->h_type == H_RAT) {
		hatom_setrational(&out, rat_abs(hatom_getrational(hatom)));
	} else if (hatom->h_type == H_DOUBLE) {
		hatom_setdouble(&out, fabs(hatom_getdouble(hatom)));
	} else {
		hatom_setlong(&out, 0);
	}
	return out;
}

t_hatom llll_hatom_inverse_if_number(t_hatom *hatom){
	t_hatom out;

	if (!hatom) {
		hatom_setlong(&out, 1);
		return out;
	}
		
	if (hatom->h_type == H_LONG) {
		hatom_setrational(&out, genrat(1, hatom_getlong(hatom)));
	} else if (hatom->h_type == H_RAT) {
		hatom_setrational(&out, rat_inv(hatom_getrational(hatom)));
	} else if (hatom->h_type == H_DOUBLE) {
		hatom_setdouble(&out, 1./hatom_getdouble(hatom));
	} else {
		hatom_setlong(&out, 1);
	}
	return out;
}

t_llllelem *llll_get_element_in_matrix(t_llll *matrix, long row, long col){
	t_llllelem *row_el = llll_getindex(matrix, row, I_NON_NEGATIVE);
	if (row_el) {
		if (hatom_gettype(&row_el->l_hatom) == H_LLLL) {
			t_llllelem *elem;
			t_llll *row_llll = hatom_getllll(&row_el->l_hatom);
			if (!row_llll) 
				return NULL;
			elem = llll_getindex(row_llll, col, I_NON_NEGATIVE);
			return elem;
		}
		return NULL;
	}
	
	return NULL;
}

// put everything whose abs() is <= epsilon to 0
void llll_approx_for_zeros(t_llll *matrix) {
	t_llllelem *row_elem, *column_elem;
	t_hatom minus_epsilon, plus_epsilon;

	hatom_setdouble(&minus_epsilon, -CONST_LINEAR_ALGEBRA_EPSILON_APPROX_ZERO);
	hatom_setdouble(&plus_epsilon, CONST_LINEAR_ALGEBRA_EPSILON_APPROX_ZERO);

	if (!matrix) return;
	
	for (row_elem = matrix->l_head; row_elem; row_elem = row_elem->l_next) {
		if (hatom_gettype(&row_elem->l_hatom) == H_LLLL) {
			t_llll *row_llll = hatom_getllll(&row_elem->l_hatom);
			for (column_elem = row_llll->l_head; column_elem; column_elem = column_elem->l_next) {
				if (llll_leq_hatom(&column_elem->l_hatom, &plus_epsilon) && llll_geq_hatom(&column_elem->l_hatom, &minus_epsilon))
					hatom_setlong(&column_elem->l_hatom, 0);
			}
		} else // for vectors
			if (llll_leq_hatom(&row_elem->l_hatom, &plus_epsilon) && llll_geq_hatom(&row_elem->l_hatom, &minus_epsilon))
				hatom_setlong(&row_elem->l_hatom, 0);
	}
}

void llll_matrix_swap_rows(t_llll *matrix, long row1, long row2) {
	if (row1 != row2) {
		t_llllelem *row1_el = llll_getindex(matrix, row1, I_NON_NEGATIVE);
		t_llllelem *row2_el = llll_getindex(matrix, row2, I_NON_NEGATIVE);
		if (row1_el && row2_el)
			llll_swapelems(row1_el, row2_el);
	}
}

void llll_matrix_swap_cols(t_llll **matrix, long col1, long col2) {
	if (matrix && *matrix && col1 != col2) {
		t_llll *matrix_copy;
		t_llll *trans;
		t_llllelem *row1_el, *row2_el;
		
		matrix_copy = llll_clone(*matrix);
		
		trans = llll_trans(matrix_copy, 0);
		
		row1_el = llll_getindex(trans, col1, I_NON_NEGATIVE);
		row2_el = llll_getindex(trans, col2, I_NON_NEGATIVE);
		
		if (row1_el && row2_el)
			llll_swapelems(row1_el, row2_el);

		llll_trans_inplace(trans, 0);
		llll_free(*matrix);
		*matrix = trans;
	}
}

// has to be mutexed, if thread safety is needed 
// mode = k_SIMPLE_ELIMINATION -> simple reduction
// mode = k_DOUBLE_ELIMINATION -> double reduction
t_llll* llll_gauss_reduce_matrix(	t_llll *matrix_in, long *num_swaps, long *rank, t_hatom *det, char mode, 
									long max_column_for_reduced_rank, long *reduced_rank, t_llll **columns_having_pivots, 
									char admit_col_swaps, t_llll **new_column_order){
	char ws = true; // matrix well shaped?
	long num_rows = llll_get_matrix_num_rows(matrix_in);
	long num_cols = llll_get_matrix_num_cols(matrix_in, &ws);
	long num_nonzero_pivots = 0, swaps = 0, err = 0, num_nonzero_pivots_until = 0;
	long i = 0, j = 0, k = 0, h = 0, count_cols = 0;
	long pivot;
	t_llllelem *pivot_llllelem, *this_llllelem;
	t_hatom pivot_hatom, pivot_abs_hatom, this_hatom, this_abs_hatom;
	t_llll *matrix = llll_get(); 
	const t_lexpr_token plus = get_plus_operator();
	const t_lexpr_token times = get_times_operator();
	t_hatom zero, minusone; 
	
	if (columns_having_pivots) 
		*columns_having_pivots = llll_get();
	
	if (new_column_order) {
		*new_column_order = llll_get();
		for (k = 1; k <= num_cols; k++)
			llll_appendlong(*new_column_order, k, 0, WHITENULL_llll);
	}
		
	llll_clone_upon(matrix_in, matrix);
	
	if (!ws || num_cols <= 0 || num_rows <= 0) {
		if (num_swaps) 
			*num_swaps = 0; 
		if (rank) 
			*rank = (num_rows == 1 && num_cols == 0) ? 0 : -1;
		if (det) 
			hatom_setlong(det, 0);
		llll_free(matrix);
		return NULL; // matrix is NOT well shaped
	}

	hatom_setlong(&zero, 0);
	hatom_setlong(&minusone, -1);
	if (det) 
		hatom_setlong(det, 1);

//	char *debug;
	llll_approx_for_zeros(matrix);

	i = 1; j = 1; count_cols = 0;
	while (i <= num_rows && j <= num_cols) {
		t_hatom inverse_pivot;
		count_cols++;
		// find pivot (max abs) in column j, starting at row i
		pivot = i;
		pivot_llllelem = llll_get_element_in_matrix(matrix, i, j);
		pivot_hatom = pivot_llllelem->l_hatom;
		pivot_abs_hatom = llll_hatom_abs_if_number(&pivot_hatom);
		for (k = i+1; k <= num_rows; k++){
			this_llllelem = llll_get_element_in_matrix(matrix, k, j);
			this_hatom = this_llllelem->l_hatom;
			this_abs_hatom = llll_hatom_abs_if_number(&this_hatom);
			if (llll_gt_hatom(&this_abs_hatom, &pivot_abs_hatom)) {
				pivot = k;
				pivot_hatom = this_hatom;
				pivot_abs_hatom = this_abs_hatom;
				pivot_llllelem = this_llllelem;
			}
		}
		inverse_pivot = llll_hatom_inverse_if_number(&pivot_llllelem->l_hatom);

		if (det && !llll_eq_hatom_ignoretype(det, &zero)) 
			lexpr_eval_one(&times, det, &pivot_hatom, NULL, det);
		
		if (llll_gt_hatom(&pivot_abs_hatom, &zero)) {
			t_llllelem *row_i;
			t_llll *old_row, *new_row;
			// setting pivot's data
			num_nonzero_pivots++;
			if (columns_having_pivots)
				llll_appendlong(*columns_having_pivots, j, 0, WHITENULL_llll);
			if (j <= max_column_for_reduced_rank)
				num_nonzero_pivots_until++;

			// we swap rows i and maxi
			row_i = llll_getindex(matrix, i, I_NON_NEGATIVE);
			if (pivot != i) {
				t_llllelem *row_pivot = llll_getindex(matrix, pivot, I_NON_NEGATIVE);
				llll_swapelems(row_i, row_pivot);
				swaps++;
			}

			// now matrix[i, j] contains the old value of matrix[pivot, j]
			// we divide each entry in row i by matrix[i,j]
			row_i = llll_getindex(matrix, i, I_NON_NEGATIVE);
			old_row = hatom_getllll(&row_i->l_hatom);
			new_row = llll_scalar_matrix_product(&inverse_pivot, old_row);
			
			hatom_change_to_llll_and_free(&row_i->l_hatom, new_row);

			// now matrix[i, j] will be 1
			for (k = i+1; k <= num_rows; k++) {
				// we gotta subtract matrix[k, j] * row i from row k
				t_hatom multiplier = llll_get_element_in_matrix(matrix, k, j)->l_hatom;
				for (h = 1; h <= num_cols; h++) {
					t_llllelem *el_to_operate_on = llll_get_element_in_matrix(matrix, k, h); 
					t_llllelem *el_to_subtract = llll_get_element_in_matrix(matrix, i, h); 
					t_hatom to_sum;
					hatom_setlong(&to_sum, 0);
					err = lexpr_eval_one(&times, &multiplier, &el_to_subtract->l_hatom, NULL, &to_sum);
					err = lexpr_eval_one(&times, &to_sum, &minusone, NULL, &to_sum);
					err = lexpr_eval_one(&plus, &el_to_operate_on->l_hatom, &to_sum, NULL, &el_to_operate_on->l_hatom);
				}
				// now matrix[k, j] will be 0
			}

			llll_approx_for_zeros(matrix);
			i++;

		} else {

			if (admit_col_swaps && count_cols < num_cols) {
				llll_matrix_swap_cols(&matrix, j, num_cols); // now 1-based
				if (new_column_order && *new_column_order)
					llll_swapelems(llll_getindex(*new_column_order, j, I_NON_NEGATIVE), llll_getindex(*new_column_order, num_cols, I_NON_NEGATIVE));
				j--; // to prevent the next j++ to have any effect whatsoever
			}

		}

		j++;
	}
	
	if (det && (swaps % 2 != 0))
		lexpr_eval_one(&times, det, &minusone, NULL, det);

	if (det && llll_eq_hatom_ignoretype(det, &zero))
		hatom_setlong(det, 0); // if 0, we output a long

	if (num_swaps)
		*num_swaps = swaps;
	if (rank) 
		*rank = num_nonzero_pivots;
	if (reduced_rank) 
		*reduced_rank = num_nonzero_pivots_until;

	if (mode == k_DOUBLE_ELIMINATION) {
		// gotta complete the elimination
		i = MIN(num_rows, num_cols);
		while (i > 0) {
			for (k = i - 1; k > 0; k--) {
				// we gotta subtract matrix[k, j] * row_i from row k
				t_llllelem *k_i_elem = llll_get_element_in_matrix(matrix, k, i);
				if (k_i_elem) {
					t_hatom multiplier = k_i_elem->l_hatom;
					for (h = 1; h <= num_cols; h++) {
						t_llllelem *el_to_operate_on = llll_get_element_in_matrix(matrix, k, h); 
						t_llllelem *el_to_subtract = llll_get_element_in_matrix(matrix, i, h); 
						t_hatom to_sum;
						hatom_setlong(&to_sum, 0);
						err = lexpr_eval_one(&times, &multiplier, &el_to_subtract->l_hatom, NULL, &to_sum);
						err = lexpr_eval_one(&times, &to_sum, &minusone, NULL, &to_sum);
						err = lexpr_eval_one(&plus, &el_to_operate_on->l_hatom, &to_sum, NULL, &el_to_operate_on->l_hatom);
					}
				} else {
					post("Error in double gaussian elimination");
				}
				// now matrix[k, j] will be 0
			}
			i--;
		}
	}
	
	return matrix;
}

t_hatom llll_det(t_llll *matrix){
	t_llll *gauss_reduced;
	t_hatom det;
	
	hatom_setlong(&det, 0);

	if (!matrix)
		return det;

	gauss_reduced = llll_gauss_reduce_matrix(matrix, NULL, NULL, &det, 0, 0, NULL, NULL, false, NULL);

	llll_free(gauss_reduced);
	return det;
}

long llll_rank(t_llll *matrix){
	t_llll *gauss_reduced;
	long rank;
	
	if (!matrix)
		return -1;

	if (matrix->l_size == 0 && matrix->l_depth == 1) // null matrix
		return 0;

	gauss_reduced = llll_gauss_reduce_matrix(matrix, NULL, &rank, NULL, 0, 0, NULL, NULL, false, NULL);
	if (!gauss_reduced)
		return -1;
	return rank;
}

t_llll* llll_get_submatrix(t_llll *matrix, long start_row, long start_column, long end_row, long end_column){
	t_llll *submatrix;
	long i, j;

	submatrix = llll_get();
	
	// handling negative integers, meaning counting rows/cols "backward"
	if (end_row < 0)
		end_row = matrix->l_size + end_row + 1;
	if (end_column < 0) {
		// finding number of columns
		long num_cols = 0;
		t_llllelem *elem;
		for (elem = matrix->l_head; elem; elem = elem->l_next)
			if (hatom_gettype(&elem->l_hatom) == H_LLLL)
				num_cols = MAX(num_cols, (long)(hatom_getllll(&elem->l_hatom)->l_size));
		end_column = num_cols + end_column + 1;
	}
	
	t_llllelem *row_elem, *col_elem;
	for (i = start_row, row_elem = llll_getindex(matrix, start_row, I_NON_NEGATIVE); i <= end_row && row_elem; i++, row_elem = row_elem->l_next) {
		t_llll *row_llll = llll_get();
		for (j = start_column, col_elem = hatom_gettype(&row_elem->l_hatom) == H_LLLL ? llll_getindex(hatom_getllll(&row_elem->l_hatom), start_column, I_NON_NEGATIVE) : NULL; 
			 j <= end_column && col_elem; j++, col_elem = col_elem->l_next) {
			llll_appendhatom_clone(row_llll, &col_elem->l_hatom, 0, WHITENULL_llll);
		}
		llll_appendllll(submatrix, row_llll, 0, WHITENULL_llll);
	}
	return submatrix;
}


t_llll* llll_juxtapose_matrix_and_vector(t_llll *matrix, t_llll *vector){
	t_llllelem *elem, *elemv;
	t_llll *complete_matrix = llll_clone(matrix);
	for (elem = complete_matrix->l_head, elemv = vector->l_head; elem && elemv; elem = elem->l_next, elemv = elemv->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *row_llll = hatom_getllll(&elem->l_hatom);
			llll_appendhatom_clone(row_llll, &elemv->l_hatom, 0, WHITENULL_llll);
		}
	}
	return complete_matrix;
}

t_llll* llll_juxtapose_matrix_and_matrix(t_llll *matrix1, t_llll *matrix2){
	t_llll *complete_matrix;
	t_llllelem *elem1, *elem2, *subelem2;
	
	if (matrix2->l_depth == 1)
		return llll_juxtapose_matrix_and_vector(matrix1, matrix2);

	complete_matrix = llll_clone(matrix1);
	
	for (elem1 = complete_matrix->l_head, elem2 = matrix2->l_head; elem1 && elem2; elem1 = elem1->l_next, elem2 = elem2->l_next) {
		if (hatom_gettype(&elem1->l_hatom) == H_LLLL) {
			t_llll *row_llll = hatom_getllll(&elem1->l_hatom);
			if (hatom_gettype(&elem2->l_hatom) == H_LLLL) {
				t_llll *row2_llll = hatom_getllll(&elem2->l_hatom);
				for (subelem2 = row2_llll->l_head; subelem2; subelem2 = subelem2->l_next)
					llll_appendhatom_clone(row_llll, &subelem2->l_hatom, 0, WHITENULL_llll);
			} else 
				llll_appendhatom_clone(row_llll, &elem2->l_hatom, 0, WHITENULL_llll);
		}
	}
	return complete_matrix;
}

/*
t_llll* llll_matrix_from_blocks(t_llll *block_structure, t_llll *block_content){
	t_llllelem *elem;

	if (!block_structure || !block_content)
		return NULL;

	for (elem = block_structure->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
		
		} else if (hatom_gettype(&elem->l_hatom) == H_LONG) {
		
		}
	}

}*/


t_llll* llll_solve_linear_system(t_llll *matrix, t_llll *vector, char *solution_type) {
	t_llll *complete_matrix, *gauss_reduced;
	long rank_matrix = -1, rank_complete_matrix = -1;
	char ws = true;
	long num_vars = llll_get_matrix_num_cols(matrix, &ws);
	
	if (!matrix || !ws || !vector || matrix->l_size != vector->l_size || num_vars < 0) {
		if (solution_type) 
			*solution_type = k_LINEAR_SYSTEM_WRONG;
		return NULL;
	}
	
	if (num_vars == 0)
		return llll_get();

	complete_matrix = llll_juxtapose_matrix_and_vector(matrix, vector);
	gauss_reduced = llll_gauss_reduce_matrix(complete_matrix, NULL, &rank_complete_matrix, NULL, k_DOUBLE_ELIMINATION, num_vars, &rank_matrix, NULL, false, NULL);

	if (rank_matrix == rank_complete_matrix) {
		if (rank_matrix == num_vars) {
			t_llll *submatrix; 
			if (solution_type) 
				*solution_type = k_LINEAR_SYSTEM_ONE_SOLUTION;
			submatrix = llll_get_submatrix(gauss_reduced, 1, num_vars + 1, num_vars, num_vars + 1);
			llll_flatten(submatrix, 2, 0);
			llll_free(complete_matrix);
			llll_free(gauss_reduced);
			return submatrix;
		} else {
			if (solution_type) 
				*solution_type = k_LINEAR_SYSTEM_INFINITELY_MANY_SOLUTIONS;
			llll_free(complete_matrix);
			llll_free(gauss_reduced);
			return NULL;
		}
	} else {
		if (solution_type) 
			*solution_type = k_LINEAR_SYSTEM_NO_SOLUTION;
		llll_free(complete_matrix);
		llll_free(gauss_reduced);
		return NULL;
	}
}


// HAS NEVER BEEN TESTED: the object [bach.inv] is indeed an abstraction 
// answer is filled with 	-1 if matrix is not well shaped or not square
//							0 if matrix is singular
//							1 if matrix has inverse
t_llll* llll_inv(t_llll *matrix, char *answer){
	char ws = true;
	long num_rows = llll_get_matrix_num_rows(matrix);
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	t_llll *inverse_matrix = NULL, *id_matrix, *complete_matrix, *gauss_elim;
	t_hatom det, zero;

	hatom_setlong(&zero, 0);
	
	if (!ws || num_rows != num_cols) {
		if (answer) 
			*answer = -1;
		return NULL;
	}
	
	if (num_rows == 0) {
		if (answer) 
			*answer = 1;
		return llll_get();
	}
	
	id_matrix = llll_get_identity_matrix(num_rows);
	complete_matrix = llll_juxtapose_matrix_and_matrix(matrix, id_matrix);
	gauss_elim = llll_gauss_reduce_matrix(complete_matrix, NULL, NULL, &det, k_DOUBLE_ELIMINATION, 0, NULL, NULL, false, NULL);
	inverse_matrix = llll_get_submatrix(gauss_elim, 1, num_cols+1, num_cols, 2*num_cols);

	llll_free(gauss_elim);
	llll_free(complete_matrix);
	llll_free(id_matrix);
	
	if (llll_eq_hatom_ignoretype(&det, &zero)) {
		if (answer) 
			*answer = 0;
		llll_free(inverse_matrix);
		return NULL;
	} else if (!inverse_matrix) {
		if (answer) 
			*answer = -1;
		return NULL;
	}
	
	if (answer) *answer = 1;
	return inverse_matrix;
}

t_llll* llll_get_submatrix_by_removing_row_and_column(t_llll *matrix, long row, long col){
	char ws = true;
	long num_rows = llll_get_matrix_num_rows(matrix);
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	t_llll *submatrix;
	long i, j;
	t_llllelem *row_el, *col_el;
	
	submatrix = llll_clone(matrix);

	if (!ws || row > num_rows || col > num_cols || row <= 0 || col <= 0) {
		return submatrix;
	}
	
	for (i = 1, row_el = submatrix->l_head; i <= num_rows && row_el; row_el = row_el->l_next, i++) {
		if (i == row)
			llll_destroyelem(row_el);
		else if (hatom_gettype(&row_el->l_hatom) == H_LLLL) {
			t_llll *row_llll = hatom_getllll(&row_el->l_hatom);
			for (j = 1, col_el = row_llll->l_head; j <= num_cols && col_el; col_el = col_el->l_next, j++)
				if (j == col)
					llll_destroyelem(col_el);
		}
	}
	return submatrix;
}

t_hatom llll_get_minor(t_llll *matrix, long row, long col) {
	t_hatom matrix_minor;
	t_llll *submatrix = llll_get_submatrix_by_removing_row_and_column(matrix, row, col);

	hatom_setlong(&matrix_minor, 0);

	if (!submatrix || !llll_is_matrix_square(submatrix))
		return matrix_minor;
	
	matrix_minor = llll_det(submatrix);
	llll_free(submatrix);
	
	return matrix_minor;
}

t_hatom llll_get_cofactor(t_llll *matrix, long row, long col) {
	const t_lexpr_token times = get_times_operator();
	t_hatom cofactor = llll_get_minor(matrix, row, col);
	t_hatom minus_one;
	hatom_setlong(&minus_one, -1);

	if ((row + col) % 2 == 1)
		lexpr_eval_one(&times, &cofactor, &minus_one, NULL, &cofactor);
		
	return cofactor; 
}

t_llll* llll_get_cofactor_matrix(t_llll *matrix) {
	char ws = true;
	long num_rows = llll_get_matrix_num_rows(matrix);
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	long i, j;
	t_llll *cofactor_matrix;
	
	if (!ws || num_rows != num_cols)
		return NULL;
	
	cofactor_matrix = llll_get();
	for (i = 1; i <= num_rows; i++) {
		t_llll *row_llll = llll_get();
		for (j = 1; j <= num_cols; j++) {
			t_hatom this_cofactor = llll_get_cofactor(matrix, i, j);
			llll_appendhatom_clone(row_llll, &this_cofactor, 0, WHITENULL_llll);
		}
		llll_appendllll(cofactor_matrix, row_llll, 0, WHITENULL_llll);
	}
	
	return cofactor_matrix;
}

// duplicated, to be removed
char is_long_in_llll_first_level_new(t_llll *inllll, long num){
	t_llllelem *elem;
	if (!inllll || inllll->l_size == 0) 
		return false;
	for (elem = inllll->l_head; elem; elem = elem->l_next)
		if (hatom_getlong(&elem->l_hatom) == num)
			return true;
	return false;
}

t_llll *get_subllll(t_llll *llll, t_llll *indices){ // indices are 1-based
	t_llll *out = llll_get();
	t_llllelem *elem;
	long i;
	
	for (i = 1, elem = llll->l_head; elem; elem = elem->l_next, i++)
		if (is_long_in_llll_first_level_new(indices, i))
			llll_appendhatom_clone(out, &elem->l_hatom, 0, WHITENULL_llll);
	  
	return out;
}

// get adjugate matrix
t_llll* llll_adj(t_llll *matrix) {
	// we can't just compute it from the inverse: what if the matrix has no inverse?
	t_llll *cof_matrix = llll_get_cofactor_matrix(matrix);
	t_llll *adj_matrix;
	if (!cof_matrix)
		return NULL;
		
	adj_matrix = llll_trans(cof_matrix, 0); 
	return adj_matrix;
}

// norm of a vector
double llll_norm(t_llll *vector) { 
	t_hatom norm_squared = llll_vector_vector_product(vector, vector);
	return sqrt(hatom_getdouble(&norm_squared));
}

t_llll* llll_normalize_vector(t_llll *vector, char *succeeded) {
	t_hatom scalar;
	double norm = llll_norm(vector);
	
	if (norm > 0.) {
		hatom_setdouble(&scalar, 1./norm);
		if (succeeded) 
			*succeeded = true;
		return llll_scalar_vector_product(&scalar, vector);
	} else {
		t_llll *out_vector;
		if (succeeded) 
			*succeeded = false;
		out_vector = llll_clone(vector);
		return out_vector;
	}
}

// projection of a vector on a direction
t_llll* llll_proj(t_llll *vector, t_llll *direction) { 
	const t_lexpr_token div = get_div_operator();
	t_hatom num = llll_vector_vector_product(vector, direction);
	t_hatom den = llll_vector_vector_product(direction, direction);
	t_hatom multiplier;
	lexpr_eval_one(&div, &num, &den, NULL, &multiplier);
	return llll_scalar_vector_product(&multiplier, direction);
}

void llll_make_vector_set_normalized(t_llll *vectors) {
	t_llllelem *elem;
	for (elem = vectors->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *non_normalized = hatom_getllll(&elem->l_hatom);
			t_llll *normalized = llll_normalize_vector(non_normalized, NULL);
			hatom_change_to_llll_and_free(&elem->l_hatom, normalized);
		}
	}
}

void llll_make_vector_set_orthogonal(t_llll *vectors) {
	// we use the Gram-Schmidt process
	t_llllelem *elem, *new_elem;
	for (elem = vectors->l_head; elem; elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *non_orthogonalized = hatom_getllll(&elem->l_hatom);
			t_llll *orthogonalized = llll_clone(non_orthogonalized);
			for (new_elem = vectors->l_head; new_elem && new_elem != elem; new_elem = new_elem->l_next) {
				if (hatom_gettype(&new_elem->l_hatom) == H_LLLL) {
					t_llll *direction = hatom_getllll(&new_elem->l_hatom);
					t_llll *projection = llll_proj(non_orthogonalized, direction);
					t_llll *diff = llll_matrix_matrix_diff(orthogonalized, projection);
					llll_free(projection);
					llll_free(orthogonalized);
					orthogonalized = diff;
				}
			}
			hatom_change_to_llll_and_free(&elem->l_hatom, orthogonalized);
		}
	}
}

// extract a basis from a collection of vectors
t_llll* llll_extract_basis(t_llll *vectors_as_single_llll, char make_orthogonal, char make_normal) {
	t_llll *vectors_as_single_llll_copy;
	t_llll *vectors_as_single_llll_reduced;
	t_llll *columns_having_pivots, *out;
	long rank;
	
	if (!vectors_as_single_llll)
		return NULL;
	
	vectors_as_single_llll_copy = llll_clone(vectors_as_single_llll);
	
	llll_trans_inplace(vectors_as_single_llll_copy, 0);
	vectors_as_single_llll_reduced = llll_gauss_reduce_matrix(vectors_as_single_llll_copy, NULL, &rank, NULL, k_SIMPLE_ELIMINATION, 0, NULL, &columns_having_pivots, false, NULL);
	
	llll_trans_inplace(vectors_as_single_llll_copy, 0);
	out = get_subllll(vectors_as_single_llll_copy, columns_having_pivots);
	
	if (make_orthogonal) 
		llll_make_vector_set_orthogonal(out);
	
	if (make_normal)
		llll_make_vector_set_normalized(out);
	
	llll_free(vectors_as_single_llll_copy);
	llll_free(vectors_as_single_llll_reduced);
	llll_free(columns_having_pivots);
	return out;
}

t_llll* get_vector_orthogonal_to_a_vector_set(t_llll *vector_set, long dimension, long max_rand_coeff) {
	t_llll *res = llll_get();
	long count = 0, i;
	while (llll_norm(res) < 0.5 && count < 10 && dimension > 0) {
		t_llll *vector_set_clone;
		t_llll *random_seed = llll_get();
		count++;
		
		vector_set_clone = llll_clone(vector_set);

		srand(1);
		for (i = 0; i < dimension; i++)
			llll_appendlong(random_seed, (rand() % 2 == 0) ? (rand() % max_rand_coeff) : -1 *  (rand() % max_rand_coeff), 0, WHITENULL_llll);
		
		llll_appendllll(vector_set_clone, random_seed, 0, WHITENULL_llll);
		
		llll_make_vector_set_orthogonal(vector_set_clone);	
		llll_make_vector_set_normalized(vector_set_clone);
		
		llll_clear(res);
		llll_clone_upon(hatom_getllll(&vector_set_clone->l_tail->l_hatom), res);
		llll_free(vector_set_clone);
	}
	return res;
}

// get eigenvalues and eigenvectors: TO DO
char llll_get_eigenvalues_and_eigenvectors(t_llll *matrix, t_llll** eigenvalues, t_llll** eigenvectors, long num_iterations, long max_rand_coeff) {
	char ws = true;
	long num_rows = llll_get_matrix_num_rows(matrix);
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	
	*eigenvalues = llll_get();
	if (eigenvectors)
		*eigenvectors = llll_get();
	
	if (!ws || num_rows != num_cols)
		return -1;

	// special cases for n=2 (UNUSED!!!)
	if (num_rows == 2 && false) {
		double a = hatom_getdouble(&llll_get_element_in_matrix(matrix, 1, 1)->l_hatom);
		double b = hatom_getdouble(&llll_get_element_in_matrix(matrix, 1, 2)->l_hatom);
		double c = hatom_getdouble(&llll_get_element_in_matrix(matrix, 2, 1)->l_hatom);
		double d = hatom_getdouble(&llll_get_element_in_matrix(matrix, 2, 2)->l_hatom);
		double eig1, eig2;
		eig1 = (a+d)/2 + sqrt(4*b*c + (a-d)*(a-d))/2.;
		eig2 = (a+d)/2 - sqrt(4*b*c + (a-d)*(a-d))/2.;

		llll_appenddouble(*eigenvalues, eig1, 0, WHITENULL_llll);
		llll_appenddouble(*eigenvalues, eig2, 0, WHITENULL_llll);
		llll_approx_for_zeros(*eigenvalues);
	} else if (num_rows == 3 && false) {
		// they are the L solution of the equation
		// -L^3 + L^2 * tr(A) + L (tr(A^2) - tr(A)^2)/2 + det(A)
		t_hatom trace_hatom = llll_trace(matrix, 0);
		t_hatom det_hatom = llll_det(matrix);
		t_hatom trace_AtimesA_hatom = llll_trace(llll_matrix_matrix_product(matrix, matrix), 0);
		double trace = hatom_getdouble(&trace_hatom);
		double trace_AtimesA = hatom_getdouble(&trace_AtimesA_hatom);
		double det = hatom_getdouble(&det_hatom);

		double a = -1;
		double b = trace;
		double c = (trace_AtimesA - trace * trace) / 2;
		double d = det;
	
		double x = ((3 * c/a) - ((b*b)/(a*a)))/3;
		double y = ((2*b*b*b)/(a*a*a) - (9*b*c)/(a*a) + (27*d/a))/27.;
		double z = y*y/4 + x*x*x/27;

		double i = sqrt(y*y/4 - z);
		double j = -cbrt(i);
		double k = acos(-y/(2*i));
		double m = cos(k/3);
		double n = sqrt(3.) * sin(k/3);
		double p = b/(3*a);
		
		double eig1, eig2, eig3;

		eig1 = 2*j*m + p;
		eig2 = -j * (m+n) + p;
		eig3 = -j * (m-n) + p;

		llll_appenddouble(*eigenvalues, eig1, 0, WHITENULL_llll);
		llll_appenddouble(*eigenvalues, eig2, 0, WHITENULL_llll);
		llll_appenddouble(*eigenvalues, eig3, 0, WHITENULL_llll);
		llll_approx_for_zeros(*eigenvalues);
		
	} else { // power iteration method (the one ALWAYS used)
		
		long i, count = 0;
		
		t_llll *kernel = llll_ker(matrix);
		long nullity = kernel ? kernel->l_size : 0;

		while (count < num_rows - nullity) {
//			char *buf1, *buf2;
			t_llll *eigenvector;
			t_llll *matrix_eigenvector_prod;
			t_hatom h1, h2;
			double eigenvalue_norm, eigenvalue;
			eigenvector = get_vector_orthogonal_to_a_vector_set(*eigenvectors, num_rows, max_rand_coeff);
				
			count++;
				
			// getting main eigenvector
			for (i = 1; i <= num_iterations; i++) {
				t_llll *new_vector = llll_matrix_vector_product(matrix, eigenvector);
				t_hatom scalar;
				t_llll *new_vector_normalized;
				hatom_setdouble(&scalar, 1./llll_norm(new_vector));
				new_vector_normalized  = llll_scalar_vector_product(&scalar, new_vector);
			
				if ((*eigenvectors)->l_size > 0) { // make orthogonal to the already existing eigenvectors!
					t_llll *vectorset = llll_clone(*eigenvectors);
					t_llll *new_vector_normalized_clone = llll_clone(new_vector_normalized);
					llll_appendllll(vectorset, new_vector_normalized_clone, 0, WHITENULL_llll);
					llll_make_vector_set_orthogonal(vectorset);
					llll_clear(new_vector_normalized);
					llll_clone_upon(hatom_getllll(&vectorset->l_tail->l_hatom), new_vector_normalized);
					llll_free(vectorset);
				}

				llll_free(eigenvector);
				llll_free(new_vector);
				eigenvector = new_vector_normalized;
			}
			
			// getting eigenvalue
			matrix_eigenvector_prod = llll_matrix_vector_product(matrix, eigenvector);
			h1 = llll_vector_vector_product(eigenvector, matrix_eigenvector_prod);
			h2 = llll_vector_vector_product(eigenvector, eigenvector);
			eigenvalue_norm = sqrt(hatom_getdouble(&h2));
			eigenvalue = (eigenvalue_norm < 0.1) ? 0. : hatom_getdouble(&h1)/hatom_getdouble(&h2);
			llll_free(matrix_eigenvector_prod);
			
			llll_appenddouble(*eigenvalues, eigenvalue, 0, WHITENULL_llll);
			llll_appendllll(*eigenvectors, eigenvector, 0, WHITENULL_llll);
		}

		if (kernel && kernel->l_size > 0) {
			t_llllelem *elem;
			for (elem = kernel->l_head; elem; elem = elem->l_next) {
				llll_appendhatom_clone(*eigenvectors, &elem->l_hatom, 0, WHITENULL_llll);
				llll_appenddouble(*eigenvalues, 0., 1, WHITENULL_llll);
			}
		}
		
		if (kernel) 
			llll_free(kernel);
		
		return 1;
	}
	
/*	// eigenvectors!
	if (eigenvectors && *eigenvectors) {
		for (elem = (*eigenvalues)->l_head; elem; elem = elem->l_next) {
			t_llll *id = llll_get_identity_matrix(num_rows);
			t_llll *lambda_id = llll_scalar_matrix_product(&elem->l_hatom, id);
			t_llll *matrix_minus_lambda_id = llll_matrix_matrix_diff(matrix, lambda_id);
			t_llll *these_eigenvectors = llll_ker(matrix_minus_lambda_id);
			if (these_eigenvectors)
				llll_appendllll(*eigenvectors, these_eigenvectors, 0, WHITENULL_llll);
			else
				llll_appendllll(*eigenvectors, llll_get(), 0, WHITENULL_llll);
			llll_free(id);
			llll_free(lambda_id);
			llll_free(matrix_minus_lambda_id);
		}
	} */
	
	return 1;
}

// HAS NEVER BEEN TESTED!
t_llll* llll_matrix_power(t_llll *matrix, long exp) {
	char ws = true;
	long num_rows, num_cols, i;

	if (!matrix)
		return NULL;

	num_rows = llll_get_matrix_num_rows(matrix);
	num_cols = llll_get_matrix_num_cols(matrix, &ws);

	if (exp == 1) {
		t_llll *matrix_copy = llll_clone(matrix);
		return matrix_copy;
	} else if (!ws || num_rows != num_cols) {
		return NULL;
	} else if (exp == 0) {
		return llll_get_identity_matrix(num_rows);
	} else { // A^k = A * A * A ....
		t_llll *temp;
		t_llll *matrix_copy = llll_clone(matrix);
		for (i = 2; i <= labs(exp); i++) {
			temp = llll_matrix_matrix_product(matrix_copy, matrix);
			llll_free(matrix_copy);
			matrix_copy = temp;
		}
		if (exp < 0) {
			char answer = true;
			t_llll *temp = llll_inv(matrix_copy, &answer);
			llll_free(matrix_copy);
			if (!answer) {
				if (temp) llll_free(temp);
				return NULL;
			}
			matrix_copy = temp;
		}
		return matrix_copy;
	}
}



t_llll* llll_ker(t_llll *matrix){
	char ws = true;
	long num_rows = llll_get_matrix_num_rows(matrix);
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	long rank, i, j;
	t_llllelem *elem;
	t_llll *column_order, *gauss_elim, *submatrix, *submatrix2;
	t_hatom minus_one;
	t_llll **lists_to_order = (t_llll **) bach_newptr(2 * sizeof(t_llll *));

	hatom_setlong(&minus_one, -1);
	
	if (!ws || num_rows != num_cols) 
		return NULL;
	
	if (num_rows == 0) 
		return llll_get();
	
//	char *buf1, *buf2;
	gauss_elim = llll_gauss_reduce_matrix(matrix, NULL, &rank, NULL, k_DOUBLE_ELIMINATION, 0, NULL, NULL, true, &column_order);
	submatrix = llll_get_submatrix(gauss_elim, 1, rank+1, rank, num_cols);

	if (!submatrix || submatrix->l_size == 0 || rank > num_cols - 1 || 0 > rank - 1) {
		llll_free(column_order);
		llll_free(submatrix);
		llll_free(gauss_elim);
		bach_freeptr(lists_to_order);
		return NULL;
	}

	submatrix2 = llll_scalar_matrix_product(&minus_one, submatrix);
	llll_trans_inplace(submatrix2, 0);

	// sorting the columns by the column_order
	lists_to_order[0] = column_order;
	lists_to_order[1] = submatrix2;
	llll_multisort(lists_to_order, lists_to_order, 2, (sort_fn)llll_leq_elem);
	column_order = lists_to_order[0];
	submatrix2 = lists_to_order[1]; 

	for (i = rank + 1, elem = submatrix2->l_head; elem; i++, elem = elem->l_next) {
		if (hatom_gettype(&elem->l_hatom) == H_LLLL) {
			t_llll *thiscol = hatom_getllll(&elem->l_hatom);
			for (j = rank + 1; j <= num_cols; j++) {
				llll_appendlong(thiscol, i == j ? 1 : 0, 0, WHITENULL_llll);
			}
		}
	}

	llll_free(submatrix);
	llll_free(gauss_elim);
	llll_free(column_order);

	bach_freeptr(lists_to_order);
	return submatrix2;
}

// HAS NEVER BEEN TESTED: the object [bach.im] is indeed an abstraction 
t_llll* llll_im(t_llll *matrix){
	char ws = true;
	long num_rows = llll_get_matrix_num_rows(matrix);
	long num_cols = llll_get_matrix_num_cols(matrix, &ws);
	t_llll *matrix_copy, *im;
	
	if (!ws || num_rows != num_cols) {
		return NULL;
	}
	
	if (num_rows == 0) {
		return llll_get();
	}

	matrix_copy = llll_clone(matrix);
	llll_trans_inplace(matrix_copy, 0);
	im = llll_extract_basis(matrix_copy, 0, 0);

	llll_free(matrix_copy);
	return im;
}

								
