#include "llll_commons_ext.h" 
#include "llll_commons.h"
#include <stdarg.h>
#include <string.h>
#include "llll_commonsyms.h"
#include "bach_math_utilities.h"

double solve_cubic(double a, double b, double c, double d){
	double bn = b/a; 
	double cn = c/a; 
	double dn = d/a;
	double f1 = - 2*bn*bn*bn + 9*bn*cn - 27*dn;
	double f2 = -bn*bn+3*cn; 
	double f3 = sqrt(f1*f1 + 4*f2*f2*f2);
	double real_sol = - (bn / 3) + cbrt((f1 + f3)/ 54) + cbrt((f1 - f3)/ 54);
	return real_sol;
}



// only for exponent >= 0
long iexp(long base, long exponent){
	long i;
	long res = 1;
	if (exponent > 0) {
		for (i = 1; i <= exponent; i++)
			res *= base;
	}
	return res;
}

// only for exponent >= 0
long iexp2(long exponent){
	return iexp(2, exponent);
}


double rescale(double value, double min, double max, double new_min, double new_max){
	return new_min + (new_max - new_min) * (value - min)/(max - min);
}

double rescale_with_slope(double value, double min, double max, double new_min, double new_max, double slope, char admit_mirroring){
	return rescale_with_slope_and_get_derivative(value, min, max, new_min, new_max, slope, NULL, admit_mirroring);
}

double rescale_with_slope_and_get_derivative(double value, double min, double max, double new_min, double new_max, double slope, double *derivative, char admit_mirroring){
	char mirrored;
	double res;
	// slope is between -1 and 1; 0 = linear; this function rescale a given value to new boundaries with a given slope.
    
    if (derivative) *derivative = 0;
    
    if (slope >= 1.) return new_min;
	if (slope <= -1.) return new_max;
	if (max == min) return new_min;
	
	mirrored = false;
	if (admit_mirroring && (slope > 0.)) {
		slope = -slope;
		mirrored = true;
	}
	
	if (slope == 0.)
		res = rescale(value, min, max, new_min, new_max); // faster (in most cases we need this)
	else {
		double base, exp, pow_val;
		value = CLAMP(value, min, max);
		base = (value - min)/(max - min);
		exp = (1+ slope) /(1 - slope);
		pow_val = pow(base, exp);
		res = new_min + (new_max - new_min) * pow_val;
		if (derivative)
			*derivative = ((new_max - new_min) / (max - min)) * exp * (pow_val / base);
	}
	
	if (mirrored) {
		res = new_min + new_max - res;
		if (derivative)
			*derivative *= -1;
	}
	
	//	if (res >= new_max) return new_max;
	//	if (res <= new_min) return new_min;
	return res;
}

double rescale_same_boundaries_with_slope(double value, double min, double max, double slope, char admit_mirroring){
	return rescale_with_slope(value, min, max, min, max, slope, admit_mirroring);
}


void swap_doubles(double *d1, double *d2){
	double temp = *d1;
	*d1 = *d2;
	*d2 = temp;
}

void swap_double_arrays(double **d1, double **d2){
	double *temp = *d1;
	*d1 = *d2;
	*d2 = temp;
}

void reorder_triplet_of_doubles(double *f1, double *f2, double *f3){
	// reordering so that f1 < f2 < f3
	if (*f1 <= *f2 && *f2 <= *f3) { 
		// nothing to do
	} else if (*f1 <= *f3 && *f3 <= *f2) {
		swap_doubles(f3, f2);
	} else if (*f2 <= *f1 && *f1 <= *f3) {
		swap_doubles(f2, f1);
	} else if (*f2 <= *f3 && *f3 <= *f1) {
		swap_doubles(f3, f1);
		swap_doubles(f2, f1);
	} else if (*f3 <= *f2 && *f2 <= *f1) {
		swap_doubles(f3, f1);
	} else if (*f3 <= *f1 && *f1 <= *f2) {
		swap_doubles(f3, f1);
		swap_doubles(f3, f2);
	}
}


void reorder_triplet_of_doubles_and_other_doubles_accordingly(double *f1, double *f2, double *f3, double *accord1, double *accord2, double *accord3){
	// reordering so that f1 < f2 < f3
	if (*f1 <= *f2 && *f2 <= *f3) { 
		// nothing to do
	} else if (*f1 <= *f3 && *f3 <= *f2) {
		swap_doubles(f3, f2);
		swap_doubles(accord3, accord2);
	} else if (*f2 <= *f1 && *f1 <= *f3) {
		swap_doubles(f2, f1);
		swap_doubles(accord2, accord1);
	} else if (*f2 <= *f3 && *f3 <= *f1) {
		swap_doubles(f3, f1);
		swap_doubles(f2, f1);
		swap_doubles(accord3, accord1);
		swap_doubles(accord2, accord1);
	} else if (*f3 <= *f2 && *f2 <= *f1) {
		swap_doubles(f3, f1);
		swap_doubles(accord3, accord1);
	} else if (*f3 <= *f1 && *f1 <= *f2) {
		swap_doubles(f3, f1);
		swap_doubles(f3, f2);
		swap_doubles(accord3, accord1);
		swap_doubles(accord3, accord2);
	}
}

long positive_mod(long num, long mod)
{
	if (num >= 0)
		return num % mod;
	
	return ((num % mod) + mod) % mod;
}


double positive_fmod(double num, double mod)
{
	if (num >= 0)
		return fmod(num, mod);
	
	return fmod(fmod(num, mod) + mod, mod);
}

void reorder_triplet_of_doubles_and_other_doubles_and_double_arrays_accordingly(double *f1, double *f2, double *f3, 
	double *accord1, double *accord2, double *accord3, double **aa1, double **aa2, double **aa3, double **ab1, double **ab2, double **ab3){
	// reordering so that f1 < f2 < f3
	if (*f1 <= *f2 && *f2 <= *f3) { 
		// nothing to do
	} else if (*f1 <= *f3 && *f3 <= *f2) {
		swap_doubles(f3, f2);
		swap_doubles(accord3, accord2);
		swap_double_arrays(aa3, aa2);
		swap_double_arrays(ab3, ab2);
	} else if (*f2 <= *f1 && *f1 <= *f3) {
		swap_doubles(f2, f1);
		swap_doubles(accord2, accord1);
		swap_double_arrays(aa2, aa1);
		swap_double_arrays(ab2, ab1);
	} else if (*f2 <= *f3 && *f3 <= *f1) {
		swap_doubles(f3, f1);
		swap_doubles(f2, f1);
		swap_doubles(accord3, accord1);
		swap_doubles(accord2, accord1);
		swap_double_arrays(aa3, aa1);
		swap_double_arrays(aa2, aa1);
		swap_double_arrays(ab3, ab1);
		swap_double_arrays(ab2, ab1);
	} else if (*f3 <= *f2 && *f2 <= *f1) {
		swap_doubles(f3, f1);
		swap_doubles(accord3, accord1);
		swap_double_arrays(aa3, aa1);
		swap_double_arrays(ab3, ab1);
	} else if (*f3 <= *f1 && *f1 <= *f2) {
		swap_doubles(f3, f1);
		swap_doubles(f3, f2);
		swap_doubles(accord3, accord1);
		swap_doubles(accord3, accord2);
		swap_double_arrays(aa3, aa1);
		swap_double_arrays(aa3, aa2);
		swap_double_arrays(ab3, ab1);
		swap_double_arrays(ab3, ab2);
	}
}


double find_mode_of_double_array_with_modulo(double *array, long array_size, double tolerance, double modulo)
{
	long i, j, num_mode = 0, mode_idx = -1;
	double *array_approx = (double *) bach_newptr(array_size * sizeof(double));
	for (i = 0; i < array_size; i++)
		array_approx[i] = positive_fmod(tolerance * round(array[i]/tolerance), modulo);
	
	for (i = 0; i < array_size; i++) {
		long count = 0;

		if (array_approx[i] < 0) 
			continue;
			
		for (j = i+1; j < array_size; j++) {
			if (array_approx[j] == array_approx[i]) {
				count++;
				array_approx[j] = -1;
			}
		}
		if (count > num_mode) {
			num_mode = count;
			mode_idx = i;
		}
	}
	bach_freeptr(array_approx);
	return (mode_idx > 0 ? array_approx[mode_idx] : (array_size > 0 ? array_approx[0] : 0));
}


// resample <array> (having size <array_size>) taking a subarray starting from a given (double) offset, and having a certain number of entries.
// degree = 0 > nearby point; 1 = segment interpolation
void resample(double *array, long array_size, double offset, double *resampled, double resampled_size, char degree){
	long i = 0, j = 0, k = 0;
	if (resampled_size <= array_size && resampled_size > 0) {
		for (i = 0; i < array_size && j < resampled_size; i++) {
			if (i >= offset) {
				if (i == offset) 
					resampled[j] = array[i];
				else if (i == 0)
					resampled[j] = array[0];	// we extend fixely at left and right
				else { // i-1 < onset < i
					// real resampling
					
					// TO DO: cubic resampling, not linear...
					// linear resampling
					resampled[j] = array[i-1] * (i - offset) + array[i] * (offset - (i-1));
				}
				j++;
			}
		}
		for (k = j; k < resampled_size; k++){
			if (k-1 >= 0)
				resampled[k] = resampled[k-1];
			else
				resampled[k] = resampled[0];
		}
	}
	
}


double compute_det_for_matrix_of_size_3(double a11, double a12, double a13, 
										double a21, double a22, double a23,
										double a31, double a32, double a33) {
	return (a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - a13*a22*a31 - a23*a32*a11 - a33*a12*a21);
}


void fill_long_array(long *a, long count,...){
    long i; va_list ap;
    va_start(ap, count);
    for (i = 0; i < count; i++, a++)
        *a = va_arg(ap, long);
    va_end(ap);
}

void fill_char_array(char *a, long count,...){
       long i; va_list ap; 
	   va_start(ap, count);
       for (i = 0; i < count; i++, a++)
          *a = va_arg(ap, long);
    va_end(ap);
}

void fill_double_array(double *a, long count,...){
       long i; va_list ap; 
	   va_start(ap, count);
       for (i = 0; i < count; i++, a++)
          *a = va_arg(ap, double);
    va_end(ap);
}

// finds the first index having as element the given <elem>
long longarray_findidx(long num_elem, long elem_to_find, long *array){
	long i;
	for (i=0; i < num_elem; i++)
		if (array[i] == elem_to_find) 
			return i;
	return -1;
}

char is_long_in_long_array(long *array, long num_elems, long num_to_find){
	long i;
	for (i = 0; i < num_elems; i++)
		if (array[i] == num_to_find)
			return true;
	return false;
}


char is_double_in_double_array(double *array, double num_elems, double num_to_find, double tolerance){
	long i;
	for (i = 0; i < num_elems; i++)
		if (array[i] >= num_to_find - tolerance && array[i] <= num_to_find + tolerance)
			return true;
	return false;
}

char double_double_cmp_with_threshold(double num1, double num2, double thres){
	if (fabs(num1 - num2) < thres)
		return 0;
	else if (num1 > num2) 
		return 1;
	else 
		return -1;
}


double array_fmin(long num_elem, long start, long end, double *array){
// finds the minimum element between array[min] and array[max]. num_elem is the number of element in the array.
	long i;
	double min_val;
	if (start < 0) start = 0;
	if (end > num_elem - 1) end = num_elem - 1;
	if ((start > num_elem - 1) || (end < 0)) return 0; //actually, that's an error, but we're pretty careful, and it'll never be the case :-D
	min_val = array[start];
	for (i=start+1; i<=end; i++){
		if (array[i]<min_val) 
			min_val = array[i];
	}
	return min_val;
}

double array_fmax(long num_elem, long start, long end, double *array){
	return array_fmax_and_idx(num_elem, start, end, array, NULL);
}

char is_number_in_double_array_with_modulo(double number, double num_elem, double *array, double tolerance, double modulo) {
	long i;
	for (i = 0; i < num_elem; i++) {
		double diff = fabs(number - array[i]);
		if (diff < tolerance || diff > modulo - tolerance)
			return 1;
	}
	return 0;
}

double array_fmax_with_scalar_diff(long num_elem, long start, long end, double scalar, double *array_to_subtract){
	double *new_array = (double *) bach_newptr(num_elem * sizeof(double));
	double result;
	long i;
	for (i = 0; i < num_elem; i++)
		new_array[i] = scalar - array_to_subtract[i];
	result = array_fmax_and_idx(num_elem, start, end, new_array, NULL);
	bach_freeptr(new_array);
	return result;
}

double array_fmax_with_diff(long num_elem, long start, long end, double *array, double *array_to_subtract){
	double *new_array = (double *) bach_newptr(num_elem * sizeof(double));
	double result;
	long i;
	for (i = 0; i < num_elem; i++)
		new_array[i] = array[i] - array_to_subtract[i];
	result = array_fmax_and_idx(num_elem, start, end, new_array, NULL);
	bach_freeptr(new_array);
	return result;
}

double array_fmax_and_idx(long num_elem, long start, long end, double *array, long *idx){
	long i;
	double max_val;
// finds the maximum element between array[min] and array[max]. num_elem is the number of element in the array.
	
	if (idx) 
		*idx = -1;
	
	if (start < 0) 
		start = 0;
	
	if (end > num_elem - 1) 
		end = num_elem - 1;
	
	if (start > num_elem - 1 || end < 0) 
		return 0; //actually, that's an error, but we're pretty careful, and it'll never be the case :-D
	
	max_val = array[start];
	if (idx) 
		*idx = start;
	for (i = start+1; i <= end; i++){
		if (array[i]>max_val) {
			max_val = array[i];
			if (idx)
				*idx = i;
		}
	}
	return max_val;
}



double mc2f(double mc, double reference_freq){
	return pow(2, ((mc/100. - 69.) / 12)) * reference_freq;
}

double f2mc(double freq, double reference_freq){
	return (12 * log2(freq / reference_freq) + 69) * 100.;
}



double deg2rad(double deg) {
	return deg * M_PI / 180.;
}

double rad2deg(double rad) {
	return rad * 180. / M_PI;
}


void clip_double(double *num, double min, double max) {
	if (*num < min) *num = min;
	if (*num > max) *num = max;
}

void clip_long(long *num, long min, long max) {
	if (*num < min) *num = min;
	if (*num > max) *num = max;
}

void clip_rat(t_rational *num, t_rational min, t_rational max) {
    if (rat_rat_cmp(*num, min) < 0) *num = min;
    if (rat_rat_cmp(*num, max) > 0) *num = max;
}


void clip_int32(t_int32 *num, long min, long max) {
	if (*num < min) *num = min;
	if (*num > max) *num = max;
}

char isign(long number){
	return (number > 0 ? 1 : (number == 0 ? 0 : -1));
}

int perfect_log2(long number){ // computes the precise log2 logarithm (n) if number is 2^n, otherwise return -1 if number is not a perfect power of 2
	int n = 0;
	if (number > 0) {
		while (number > 1) {
			if (number % 2 == 0) {
				n++;
				number = number / 2;
			} else
				return -1;
		}
	} else 
		return -1;
	
	return n;
}


// snap a given *value to the nearest of the possibilities
t_llllelem *ysnap_double(double *value, t_llll *ysnap_possibilities, char force_snap_direction){
	double best_diff = -1, best_snapvalue = 0;
	t_llllelem *elem, *res = NULL;
	
	if (!value || !ysnap_possibilities || !ysnap_possibilities->l_head)
		return NULL;
	
	for (elem = ysnap_possibilities->l_head; elem; elem = elem->l_next) {
		if (is_hatom_number(&elem->l_hatom)) {
			double this_snapvalue = hatom_getdouble(&elem->l_hatom);
			if (!force_snap_direction || (force_snap_direction > 0 && this_snapvalue >= *value) || (force_snap_direction < 0 && this_snapvalue <= *value)) {
				double this_diff = fabs(this_snapvalue - *value);
				if (best_diff < 0 || this_diff < best_diff){
					best_diff = this_diff;
					best_snapvalue = this_snapvalue;
					res = elem;
				}
			}
		}
	}
	
	if (best_diff >= 0) {
		*value = best_snapvalue;
		return res; 
	} else {
		return NULL;
	}

}


double angle_dist(double angle1, double angle2, double modulo)
{
	double phase1_wk = positive_fmod(angle1, modulo);
	double phase2_wk = positive_fmod(angle2, modulo);
	if (phase1_wk > phase2_wk)
		swap_doubles(&phase1_wk, &phase2_wk);
	if (phase2_wk - phase1_wk < modulo/2.)
		return phase2_wk - phase1_wk;
	return modulo - (phase2_wk - phase1_wk);
}



double random_double_in_range(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
    
    
}

t_lexpr_token get_times_operator(){
    // defining times operator
    t_lexpr_token times;
    times.t_type = TT_OP;
    times.t_operands = 2;
    times.t_contents.c_op.o_op = O_TIMES;
    times.t_contents.c_op.o_inv = O_DIV;
    times.t_contents.c_op.o_properties = OP_COMM || OP_ASSOC || OP_INVERT;
    return times;
}

t_lexpr_token get_div_operator(){
    // defining times operator
    t_lexpr_token div;
    div.t_type = TT_OP;
    div.t_operands = 2;
    div.t_contents.c_op.o_op = O_DIV;
    div.t_contents.c_op.o_inv = O_TIMES;
    div.t_contents.c_op.o_properties = OP_INVERT;
    return div;
}

t_lexpr_token get_plus_operator(){
    // defining times operator
    t_lexpr_token plus;
    plus.t_type = TT_OP;
    plus.t_operands = 2;
    plus.t_contents.c_op.o_op = O_PLUS;
    plus.t_contents.c_op.o_inv = O_MINUS;
    plus.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC | OP_INVERT;
    return plus;
}

t_lexpr_token get_minus_operator(){
    // defining times operator
    t_lexpr_token minus;
    minus.t_type = TT_OP;
    minus.t_operands = 2;
    minus.t_contents.c_op.o_op = O_MINUS;
    minus.t_contents.c_op.o_inv = O_PLUS;
    minus.t_contents.c_op.o_properties = OP_ASSOC | OP_INVERT;
    return minus;
}

t_lexpr_token get_sqrt_function(){
    // defining times operator
    t_lexpr_token mysqrt;
    mysqrt.t_type = TT_FUNC;
    mysqrt.t_operands = 1;
    mysqrt.t_contents.c_func.f_ptrs.p_dptr_d = &sqrt;
    mysqrt.t_contents.c_func.f_type = H_DOUBLE;
    return mysqrt;
}
