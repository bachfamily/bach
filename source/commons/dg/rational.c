#include "math.h"
#include "stdlib.h"
#include "rational.h"
#include "llll_math.h"

char fsign(double number){
	return (number > 0 ? 1 : (number == 0 ? 0 : -1));
}


t_rational urrat2rat(t_urrational urrat)
{
	t_rational res;
	res.r_num = urrat.r_num;
	res.r_den = urrat.r_den;
	rat_reduce(&res);
	return res;
}

t_urrational rat2urrat(t_rational rat)
{
	t_urrational res;
	res.r_num = rat.r_num;
	res.r_den = rat.r_den;
	return res;
}


void rat_reduce(t_rational *rat) 
{
	long_long_reduce(&rat->r_num, &rat->r_den);
}

t_atom_long gcd(t_atom_long a, t_atom_long b) 
{
	long temp, m, a1, b1;
	a1 = a;	b1 = b;
	
	if (b1 > a1) { 
		temp = a1; 
		a1 = b1; 
		b1 = temp; 
	}
	
	while (b1) {
		m = a1 % b1;
		a1 = b1;
		b1 = m;
	}
	
	return a1;
}

t_atom_long lcm(t_atom_long a, t_atom_long b) 
{
#ifdef C74_X64
#ifdef BACH_USE_NATIVE_128BIT_INTEGER
	return (((t_atom_longlong) a) * ((t_atom_longlong) b) / (t_atom_long) gcd(a,b));
#else
	return (((t_atom_longlong) a) * ((t_atom_longlong) b) / gcd(a,b)).getLo();
#endif
#else
	return (t_atom_long) (((t_atom_longlong) a) * ((t_atom_longlong) b) / gcd(a,b));
#endif
}

t_rational rat_gcd(t_rational a, t_rational b) {
	return genrat(gcd(a.r_num, b.r_num), lcm(a.r_den, b.r_den));
}

t_atom_long long_long_reduce(t_atom_long *num, t_atom_long *den) 
{
	t_atom_longlong l_num, l_den;
	t_atom_longlong m, temp, a = 1, b;

	if ((*den == 0) && (*num == 0))
		return 0; // nothing to do, in this case (0/0 is a "normal" form, even if it's not a mathematically-valid rational...)

	if (*den == 0) {
		*num = (*num > 0 ? 1 : -1);
		return 0;
	}
	if (*num == 0) {
		*den = 1;
		return 0;
	}
	
	l_num = *num;
	l_den = *den;
	
    if (l_num != 1 && l_den != 1) { // if any of them is 1, we are done.
        a = l_num;
        b = l_den;
        
        if (b > a) {
            temp = a;
            a = b;
            b = temp;
        }
        
        while (b != 0) {
            m = a % b;
            a = b;
            b = m;
        }
        
        // now a contains the gcd!
        
        l_num /= a;
        l_den /= a;
    }
	
	if (l_den < 0) {
		l_den *= -1;
		l_num *= -1;
		a *= -1;
	}
#ifdef C74_X64
#ifdef BACH_USE_NATIVE_128BIT_INTEGER
	*num = (t_atom_long) l_num;
	*den = (t_atom_long) l_den;
	return ((t_atom_long)a);
#else
	*num = l_num.getLo();
	*den = l_den.getLo();
	return a.getLo();
#endif
#else
	*num = (t_atom_long) l_num;
	*den = (t_atom_long) l_den;
	return ((t_atom_long)a);
#endif
	

}



t_int32 long_long_reduce_int32(t_int32 *num, t_int32 *den) 
{
	t_int64 l_num, l_den;
	t_int64 m, temp, a, b;
	
	if ((*den == 0) && (*num == 0))
		return 0; // nothing to do, in this case (0/0 is a "normal" form, even if it's not a mathematically-valid rational...)
	
	if (*den == 0) {
		*num = (*num > 0 ? 1 : -1);
		return 0;
	}
	if (num == 0) {
		*den = 1;
		return 0;
	}
	
	l_num = *num;
	l_den = *den;
	
	a = l_num;
	b = l_den;
	
	if (b > a) { 
		temp = a; 
		a = b; 
		b = temp; 
	}
	
	while (b != 0) {
		m = a % b;
		a = b;
		b = m;
	}
	
	// now a contains the gcd!
	
	l_num /= a;
	l_den /= a;
	
	if (l_den < 0) {
		l_den *= -1;
		l_num *= -1;
		a *= -1;
	}
	return ((t_int32)a);
}



t_rational long2rat(t_atom_long num) 
{
	t_rational output;
	output.r_num = num; 
	output.r_den = 1;
	return output;
}

t_urrational genurrat(t_atom_long num, t_atom_long den) 
{
	t_urrational output;
	output.r_num = num; 
	output.r_den = den;
	return output;
}

t_rational genrat_noreduce(t_atom_long num, t_atom_long den)
{
    t_rational output;
    output.r_num = num;
    output.r_den = den;
    return output;
}

t_rational genrat(t_atom_long num, t_atom_long den) 
{
	t_rational output;
	output.r_num = num; 
	output.r_den = den;
	rat_reduce(&output);
	return output;
}


long rat_num(t_rational rat) 
{
	return rat.r_num;
}

long rat_den(t_rational rat) 
{
	return rat.r_den;
}

t_rational rat_opp(t_rational rat) 
{
	t_rational opposed;
	opposed.r_num = -rat.r_num;
	opposed.r_den = rat.r_den;
	// no need for rat_reducing... if the input is ok, the output is ok as well
	return opposed;
}

t_rational rat_rat_sum(t_rational rat1, t_rational rat2) 
{
	t_rational sum;

	t_atom_long den1 = rat1.r_den, den2 = rat2.r_den;
	t_atom_long gcd = long_long_reduce(&den1, &den2);
	
	if (gcd > 0) { // new way, working best with big numbers
		sum.r_num = rat1.r_num * den2 + den1 * rat2.r_num;
		sum.r_den = den1 * den2 * gcd;
	} else { // something wrong with the fractions. Let's stick with the old way, working badly with big numbers
		sum.r_num = rat1.r_num * rat2.r_den + rat1.r_den * rat2.r_num;
		sum.r_den = rat1.r_den * rat2.r_den;
	}

	rat_reduce(&sum);
	return sum;
}

t_rational rat_rat_diff(t_rational rat1, t_rational rat2) 
{
	return rat_rat_sum(rat1, rat_opp(rat2));
}

t_rational rat_rat_prod(t_rational rat1, t_rational rat2) 
{
	t_rational prod;
	prod.r_num = rat1.r_num * rat2.r_num;
	prod.r_den = rat1.r_den * rat2.r_den;
	rat_reduce(&prod);
	return prod;
}

t_rational rat_rat_div(t_rational rat1, t_rational rat2) 
{
	return rat_rat_prod(rat1, rat_inv(rat2));
}

// integer division between two rationals
long rat_rat_divdiv(t_rational rat1, t_rational rat2, char always_positive_mod)
{
    t_rational mod;
    t_rational div;
    rat2 = rat_abs(rat2);
    div  = rat_rat_div(rat1, rat2);
    long divdiv = div.r_num / div.r_den;
    if (always_positive_mod) {
        mod = rat_rat_diff(rat1, rat_long_prod(rat2, div.r_num / div.r_den));
        if (mod.r_num < 0)
            divdiv -= 1;
    }
    
    return divdiv;
}


t_rational rat_long_diff(t_rational rat1, t_atom_long num) 
{
	return(rat_long_sum(rat1, -num));
}

t_rational long_rat_diff(t_atom_long num, t_rational rat1) 
{
	return(rat_long_sum(rat_opp(rat1), num));
}

t_rational rat_long_sum(t_rational rat1, t_atom_long num) 
{
	t_rational sum;
	sum.r_num = rat1.r_num + rat1.r_den * num;
	sum.r_den = rat1.r_den;
	rat_reduce(&sum);
	return sum;
}

t_rational rat_long_div(t_rational rat, t_atom_long num) 
{
    if (num == 0) {
        error("Rational division by 0 detected");
        return {0, 1};
    }
	long_long_reduce(&rat.r_num, &num);
	rat.r_den *= num;
	return rat;
}

t_rational long_rat_div(t_atom_long num, t_rational rat) 
{
	t_atom_long temp = rat.r_num;
	rat.r_num = rat.r_den;
	rat.r_den = temp;
	long_long_reduce(&num, &rat.r_den);
	rat.r_num *= num;
	return rat;
}

t_rational rat_long_prod(t_rational rat, t_atom_long num) 
{
	long_long_reduce(&num, &rat.r_den);
	rat.r_num *= num;
	return rat;
}

char rat_is_integer(t_rational rat) 
{
	if ((rat.r_den == 1)  || (rat.r_den == -1)) // -1 should never happen: rationals are mapped as den>0
		return 1;
	else 
		return 0;
}

t_rational rat_long_mod(t_rational rat, t_atom_long num, char always_positive) 
{
	t_rational mod;
	
	mod.r_den = rat.r_den;
	mod.r_num = rat.r_num % (rat.r_den * num);
	rat_reduce(&mod);

	if (always_positive && mod.r_num < 0)
		mod = rat_long_sum(mod, num);

	return mod;
}

t_rational rat_rat_mod(t_rational rat1, t_rational rat2, char always_positive) 
{
	t_rational mod;
	t_rational div;
	rat2 = rat_abs(rat2);
	div  = rat_rat_div(rat1, rat2);
	mod = rat_rat_diff(rat1, rat_long_prod(rat2, div.r_num / div.r_den));
	if (always_positive && mod.r_num < 0)
		mod = rat_rat_sum(mod, rat2);
	return mod;
}


char rat_long_cmp(t_rational rat, t_atom_long num) // comparison between rat and num. 1 if rat > num, -1 if rat < num; 0 if rat == num. -2 if incomparable (invalid rational...)
{
	t_atom_longlong b;
	// check validity of denominator (one never knows...)
	if (rat.r_den < 0) {
		rat.r_den *= -1;
		rat.r_num *= -1;
	}
	b = ((t_atom_longlong) rat.r_den) * ((t_atom_longlong) num);
	if (rat.r_den == 0)	
		return -2;
	else if (((t_atom_longlong) rat.r_num) > b)
		return 1;
	else if (((t_atom_longlong) rat.r_num) == b)
		return 0;
	else
		return -1;
}

double rat2double(t_rational rat) // conversion rational->double
{
	return ((double)rat.r_num) / rat.r_den;
}


double urrat2double(t_urrational urrat) // conversion unreduced rational->double
{
	return ((double)urrat.r_num) / urrat.r_den;
}

float rat2float(t_rational rat) // conversion rational->float
{
	return ((float)rat.r_num) / rat.r_den;
}

t_rational force_standard_rational(t_rational rat) // if a rational has den = 0, returns 0
{
	if (rat.r_den == 0)
		return long2rat(0);
	
	return rat;
}
char rat_double_cmp(t_rational rat, double num, double epsilon) // comparison between rat and float. 1 if rat > num, -1 if rat < num; 0 if rat == num. -2 if incomparable (invalid rational...)
{
	double f;
	// check validity of denominator (one never knows...)
	if (rat.r_den < 0) {
		rat.r_den *= -1;
		rat.r_num *= -1;
	}
	if (rat.r_den == 0)	
		return -2;

	f = rat.r_num / rat.r_den;

	if (fabs(f - num) <= epsilon)
		return 0;
	
	if (f > num)
		return 1;
	
	return -1;
}

// comparison between rat and num. 
// returns 1 if rat1 > rat2, 
// -1 if rat1 < rat2, 0 if rat1 == rat2, -2 if incomparable (invalid rational)
char rat_rat_cmp(t_rational rat1, t_rational rat2) 
{
	t_atom_longlong a, b;
	// check validity of denominators (one never knows...)
	if (rat1.r_den < 0) {
		rat1.r_den *= -1;
		rat1.r_num *= -1;
	}
	if (rat2.r_den < 0) {
		rat2.r_den *= -1;
		rat2.r_num *= -1;
	}
	
	a = ((t_atom_longlong)rat1.r_num) * ((t_atom_longlong) rat2.r_den);
	b = ((t_atom_longlong)rat1.r_den) * ((t_atom_longlong) rat2.r_num);
	
	if ((rat1.r_den == 0) || (rat2.r_den == 0))	
		return -2;
	else if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}

// compares the two rationals in the form int1+rem1 and int2+rem2.
// returns stuff like rat_rat_cmp
char rat_rat_cmp_integer_and_remainders(t_atom_long int1, t_rational rem1, t_atom_long int2, t_rational rem2){
	if (int1 < int2)
		return -1;
	else if (int1 > int2)
		return 1;
	else
		return rat_rat_cmp(rem1, rem2);
}


t_rational rat_rat_sum_integer_and_remainders(t_atom_long int1, t_rational rem1, t_atom_long int2, t_rational rem2){
	t_atom_long sum_int = int1+int2;
	t_rational sum_rem = rat_rat_sum(rem1, rem2);
	return rat_long_sum(sum_rem, sum_int);
}

t_rational rat_rat_diff_integer_and_remainders(t_atom_long int1, t_rational rem1, t_atom_long int2, t_rational rem2){
	t_atom_long diff_int = int1-int2;
	t_rational diff_rem = rat_rat_diff(rem1, rem2);
	return rat_long_sum(diff_rem, diff_int);
}


// leave direction = 0 and error = NULL for default approximation
// if direction = 1, it ceils, if direction = -1 it floors. 
// if (error), it puts into *error the error.
t_urrational approx_double_with_rat_fixed_den_no_reduce(double number, t_atom_long den, char direction, double *error) {
//	number \approx num/den; easy-bisy version...
	t_urrational outrat;
	outrat.r_den = den;
	if (direction == 1)
		outrat.r_num =  (t_atom_long) ceil(number * den);
	else if (direction == -1)
		outrat.r_num =  (t_atom_long) floor(number * den);
	else 
		outrat.r_num =  (t_atom_long) round(number * den);
	
	if (error)
		*error = number - urrat2double(outrat);
	
	return outrat;
}

t_rational approx_double_with_rat_fixed_den(double number, t_atom_long den, char direction, double *error) {
	t_urrational urrat = approx_double_with_rat_fixed_den_no_reduce(number, den, direction, error);
	return urrat2rat(urrat);
}

t_rational approx_double_with_rat_best_match(double number, t_atom_long max_den, char direction, double *error) {
	t_atom_long i;
	double local_error = 1., global_error = 1., abs_global_error = 1.;
	t_urrational global_candidate = rat2urrat(long2rat(1));
	for (i = 1; i <= max_den; i++) {
		t_urrational local_candidate = approx_double_with_rat_fixed_den_no_reduce(number, i, direction, &local_error);
		double fabs_local_error = fabs(local_error);
		if (fabs_local_error < abs_global_error) {
			global_error = local_error;
			abs_global_error = fabs_local_error;
			global_candidate = local_candidate;
		}
	}
	
	if (error)
		*error = global_error;
	
	return urrat2rat(global_candidate);
}

t_rational approx_double_with_rat_up_to_tolerance(double number, double tolerance, t_atom_long max_den, char direction, char tolerance_is_ratio,
												  double *error, char *found) {
	t_atom_long i = 1;
	double local_error = 1., global_error = 1.;
	t_urrational global_candidate = rat2urrat(long2rat(1));
	char something_has_been_found_within_tolerance = false;
	double local_tolerance = tolerance, fabs_global_error = 1.;
	
	while (((max_den > 0 && i <= max_den) || (max_den <= 0)) && (!something_has_been_found_within_tolerance || i == 1)) {
		
		if (tolerance_is_ratio) {
			local_tolerance = tolerance / i;
			local_tolerance = MAX(local_tolerance, CONST_EPSILON_FOR_DOUBLE2RAT_APPROXIMATION);
		}
		
		t_urrational local_candidate = approx_double_with_rat_fixed_den_no_reduce(number, i, direction, &local_error);
		double fabs_local_error = fabs(local_error);
		if (fabs_local_error < fabs_global_error) {
			global_error = local_error;
			fabs_global_error = fabs_local_error;
			global_candidate = local_candidate;
			if (fabs_local_error <= local_tolerance)
				something_has_been_found_within_tolerance = true;
		}
		
		i++;
	}
	
	if (found)
		*found = something_has_been_found_within_tolerance;
	
	if (error)
		*error = global_error;

	return urrat2rat(global_candidate);
}


/*
t_llll *approx_double_with_rat_and_get_approximation_list(double number, double max_error, t_atom_long max_den, char direction, 
														  t_llll *errors, t_llll *denominators, t_llll *permanences) {
	t_atom_long i;
	t_llll *out_llll = llll_get();
	double local_error = 1., global_error = 1.;
	long prev_i = 0;
	t_rational local_candidate = long2rat(1);
	for (i = 1; i <= max_den; i++) {
		local_candidate = approx_double_with_rat_fixed_den_no_reduce(number, i, direction, &local_error);
		rat_reduce(&local_candidate); // BTW: probably not even needed, since we scan all denominators 1 to max_den
		if (local_error <= global_error && local_error <= max_error) {
			llll_appendrat(out_llll, local_candidate, 0, WHITENULL_llll);
			if (errors)
				llll_appenddouble(errors, local_error, 0, WHITENULL_llll);
			if (denominators)
				llll_appendlong(denominators, i, 0, WHITENULL_llll);
			if (permanences)
				llll_appendlong(permanences, i - prev_i, 0, WHITENULL_llll);
			global_error = local_error;
			prev_i = i;
		}
	}
	
	if (permanences)
		llll_appendlong(permanences, i - prev_i, 0, WHITENULL_llll);
	llll_behead(permanences);
	
	return out_llll;
}

t_rational approx_double_with_rat_smart_permanence(double number, double max_error, t_atom_long max_den, char direction, double *error, char *found) {
	t_llll *errors = llll_get();
	t_llll *denominators = llll_get();
	t_llll *permanences = llll_get();
	t_llll *approximations = approx_double_with_rat_and_get_approximation_list(number, max_error, max_den, direction, errors, denominators, permanences);
	t_rational approx_result = long2rat(0);
	
	if (approximations->l_size == 0) {
		if (found)
			*found = false;
		
		// outputting a default solution, ignoring max_error
		llll_free(approximations);
		approximations = approx_double_with_rat_and_get_approximation_list(number, 1., max_den, direction, errors, denominators, permanences);
		
	} else {
		if (found)
			*found = true;
	}
	
	t_llllelem *denominators_elem, *permanences_elem, *approximations_elem, *errors_elem;
	double best_w = 0, local_w = 0;
	double best_error = 1.;
	t_rational best_approx = long2rat(0);
	for (denominators_elem = denominators->l_head, permanences_elem = permanences->l_head, 
		 approximations_elem = approximations->l_head, errors_elem = errors->l_head;
		 denominators_elem && permanences_elem && approximations_elem && errors_elem;
		 denominators_elem = denominators_elem->l_next, permanences_elem = permanences_elem->l_next,
		 approximations_elem = approximations_elem->l_next, errors_elem = errors_elem->l_next) {
		
		long this_den = hatom_getlong(&denominators_elem->l_hatom);
		long this_permanence = hatom_getlong(&permanences_elem->l_hatom);
		double this_error = hatom_getdouble(&errors_elem->l_hatom);
		t_rational this_approx = hatom_getrational(&approximations_elem->l_hatom);
		
		local_w = log(this_permanence)/log(this_den);
		if (local_w > best_w) {
			best_error = this_error;
			best_approx = this_approx;
			best_w = local_w;
		}
	}
	
	if (*error)
		*error = best_error;
	
	approx_result = best_approx;
	
	return approx_result;
}


*/


t_rational approx_double_with_rat_smart_permanence(double number, double tolerance, t_atom_long max_den, 
												   char direction, char tolerance_is_ratio, double *error, char *found) {
	t_atom_long i;
	t_atom_long prev_i = 0;
	double local_error = 1., global_error = 1., fabs_global_error = 1.;
	t_urrational global_candidate = rat2urrat(long2rat(0)); // candidate with best approximation
	t_urrational global_best_weight_candidate = rat2urrat(long2rat(0)); // candidate with best weight
	double global_best_weight_error = 1.; // error of candidate with best weight
	double best_weight = 0;
	char we_went_break = false;
	
	if (found)
		*found = false;

	for (i = 1; i <= max_den; i++) {
		t_urrational local_candidate = approx_double_with_rat_fixed_den_no_reduce(number, i, direction, &local_error);
		double fabs_local_error = fabs(local_error);
		if (fabs_local_error < fabs_global_error) {
			// checking previous permanence denominator
			if (prev_i > 0) {
				double local_tolerance = tolerance;
				if (tolerance_is_ratio) {
					local_tolerance = tolerance / prev_i;
					local_tolerance = MAX(local_tolerance, CONST_EPSILON_FOR_DOUBLE2RAT_APPROXIMATION);
				}
				
//				dev_post("Approximation %ld/%ld, with error %.5f", global_candidate.r_num, global_candidate.r_den, global_error);
				if (fabs_global_error <= local_tolerance) {
					double this_weight = log((double)i - prev_i)/log((double)prev_i); // weight calculation
//					dev_post("   Within tolerance! With permanence %ld and weight %.4f", i - prev_i, this_weight);
					if (this_weight > best_weight) {
					
						best_weight = this_weight;
						global_best_weight_candidate = global_candidate;
						global_best_weight_error = global_error;

						if (found)
							*found = true;
					}
				}
			}
			
			// are we done already? 
			// to have a better solution one must have
			// log(next_i - i) / log(i) > best_weight
			// thus
			// next_i - i > i^(best_weight)
			// is it possible??
			if (max_den - i < pow(i, best_weight)) {
				// we are done
				we_went_break = true;
				break;
			}

			global_error = local_error;
			fabs_global_error = fabs_local_error;
			global_candidate = local_candidate;
			
			prev_i = i;
		}
	}

	// checking last permanence
	if (!we_went_break && prev_i > 0) { // if we went break, we're sure that the last permanence cannot have a better weight.
		double local_tolerance = tolerance; 
		if (tolerance_is_ratio) {
			local_tolerance = tolerance / prev_i;
			local_tolerance = MAX(local_tolerance, CONST_EPSILON_FOR_DOUBLE2RAT_APPROXIMATION);
		}
		
		dev_post("Approximation %ld/%ld, with error %.5f", global_candidate.r_num, global_candidate.r_den, global_error);
		if (fabs_global_error <= local_tolerance) {
			double this_weight = log((double)max_den + 1 - prev_i)/log((double)prev_i); // weight calculation
			dev_post("   Within tolerance! With permanence %ld and weight %.4f", 
				 global_candidate.r_num, global_candidate.r_den, global_error, max_den + 1 - prev_i, this_weight);
			if (this_weight > best_weight) {
				
				best_weight = this_weight;
				global_best_weight_candidate = global_candidate;
				global_best_weight_error = global_error;
				
				if (found)
					*found = true;
			}
		}	
	}
	
	
	if (!found) {
		if (error)
			*error = global_error;
		
		return urrat2rat(global_best_weight_candidate);
	}
	
	if (error)
		*error = global_best_weight_error;
	
	return urrat2rat(global_best_weight_candidate);
}




t_rational rat_abs(t_rational rat) {
	t_rational outrat;
	outrat.r_num = alabs(rat.r_num);
	outrat.r_den = alabs(rat.r_den);
	return outrat;
}


t_rational rat_square(t_rational rat) {
	t_rational outrat;
	outrat.r_num = rat.r_num * rat.r_num;
	outrat.r_den = rat.r_den * rat.r_den;
	rat_reduce(&outrat);
	return outrat;
}

t_rational rat_inv(t_rational rat) {
	t_rational outrat;
	outrat.r_num = rat.r_den;
	outrat.r_den = rat.r_num;
    if (outrat.r_den == 0) {
        error("Rational division by zero detected");
        outrat.r_num = 0;
        outrat.r_den = 1;
    } else if (outrat.r_den < 0) {
		outrat.r_num *= -1;
		outrat.r_den *= -1;
	}
	return outrat;
}

void rat_dx2x(long num_rationals, t_rational *rationals, t_rational start_rational, t_rational **out_rationals) {
// **out_rationals must be already sized num_rationals + 1!!!
//	bach_resizeptr(*out_rationals, num_rationals + 1);
	long i; t_rational sum = start_rational;
	*out_rationals[0] = start_rational;
	for (i=0; i<num_rationals; i++){
		sum = rat_rat_sum(sum, rationals[i]);
		*out_rationals[i+1] = sum;
	}
}

// rational "approximation"
t_rational approx_rat_with_rat(t_rational rat, t_atom_long max_num, t_atom_long max_den){
	return approx_rat_with_rat_notify(rat, max_num, max_den, NULL);
}

t_rational approx_rat_with_rat_notify(t_rational rat, t_atom_long max_num, t_atom_long max_den, char *changed){
	// not the best algorithm at all. to be changed

	t_rational rat_out;
	
	if (changed) 
		*changed = false;
	
	if (rat.r_den <= max_den && rat.r_num <= max_num)
		return rat;
	
	if (rat.r_den > max_den) {
		rat_out.r_den = max_den;
		rat_out.r_num =  (t_atom_long) round(rat2double(rat) * max_den);
		if (changed) 
			*changed = true;
	}

	if (rat.r_num > max_num) { 
		double factor = ((double) rat.r_num) / max_num; 
		rat_out.r_num = max_num;
		rat_out.r_den =  (t_atom_long) round(rat.r_den / factor);
		if (changed) 
			*changed = true;
	}
	
	return rat_out;

}

t_rational approx_rat_with_rat_fixed_den(t_rational rat, t_atom_long den){
	t_rational rat_out;

	rat_out.r_den = den;
	rat_out.r_num =  (t_atom_long) round(rat2double(rat) * den);
	
	return rat_out;
}

t_rational ceil_rat_with_rat_fixed_den(t_rational rat, t_atom_long den){
	t_rational rat_out;

	rat_out.r_den = den;
	rat_out.r_num = (t_atom_long) ceil(rat2double(rat) * den);
	
	return rat_out;
}

t_rational ceil_approx_rat_with_rat(t_rational rat, t_atom_long max_num, t_atom_long max_den){
	// not the best algorithm at all. to be changed

	t_rational rat_out;

	if (rat.r_den <= max_den && rat.r_num <= max_num)
		return rat;
	
	if (rat.r_den > max_den) {
		rat_out.r_den = max_den;
		rat_out.r_num =  (t_atom_long) ceil(rat2double(rat) * max_den);
	}

	if (rat.r_num > max_num) { 
		double factor = ((double)rat.r_num) / max_num; 
		rat_out.r_num = max_num;
		rat_out.r_den =  (t_atom_long) ceil(rat.r_den / factor);
	}
	
	return rat_out;

}

t_rational rat_rescale(t_rational value, t_rational min, t_rational max, t_rational new_min, t_rational new_max) {
	return rat_rat_sum(new_min, rat_rat_prod(	rat_rat_diff(new_max, new_min),
												rat_rat_div(rat_rat_diff(value, min), rat_rat_diff(max, min))));
}


char is_rat_rat_sum_safe(t_rational rat1, t_rational rat2, t_atom_long max_number){
	long denlcm, num1, num2;

	if (rat1.r_num > max_number || rat2.r_num > max_number || rat1.r_den > max_number || rat2.r_den > max_number)
		return 0;
	
	denlcm = lcm(rat1.r_den, rat2.r_den);
	if (denlcm > max_number)
		return 0;
	
	num1 = rat1.r_num * denlcm/rat1.r_den;
	num2 = rat2.r_num * denlcm/rat2.r_den;
	if (num1 > max_number || num2 > max_number || num1 + num2 > max_number)
		return 0;
	
	return 1;
}


char is_rat_rat_prod_safe(t_rational rat1, t_rational rat2, t_atom_long max_number){
	
	if (rat1.r_num > max_number || rat2.r_num > max_number || rat1.r_den > max_number || rat2.r_den > max_number)
		return 0;
	
	if (((t_atom_longlong)rat1.r_den) * ((t_atom_longlong)rat2.r_den) > max_number || 
		((t_atom_longlong)rat1.r_num) * ((t_atom_longlong)rat2.r_num) > max_number)
		return 0;
	
	return 1;
}

char is_rat_rat_div_safe(t_rational rat1, t_rational rat2, t_atom_long max_number){
	return is_rat_rat_prod_safe(rat1, rat_inv(rat2), max_number);
}


char rat_rat_cmp_account_for_approximations(t_rational *rat1, t_rational *rat2, char needed_to_approximate, double threshold){
	if (needed_to_approximate) {
		// if we needed to approximate things, it makes no sense to compare rationals, and we compare doubles 
		double diff = rat2double(*rat1) - rat2double(*rat2);
		if (fabs(diff) < threshold) {
			rat2->r_num = rat1->r_num;
			rat2->r_den = rat1->r_den;
			return 0;
		} else if (diff > 0)
			return 1;
		else
			return -1;
	} else	// standard comparison of rationals
		return rat_rat_cmp(*rat1, *rat2);		
}

t_rational rat_clip(t_rational rat, t_rational min, t_rational max)
{
	if (rat_rat_cmp(rat, min) < 0)
		return min;
	if (rat_rat_cmp(rat, max) > 0)
		return max;
	return rat;
}

t_atom_long ipow(t_atom_long num, int power)
{
	if (power == 0 || num == 1) return 1;
	if (power == 1 || num == 0) return num;

	// ----------------------
	int n = 31;
	while ((power <<= 1) >= 0) n--;
	
	t_atom_long tmp = num;
	while (--n > 0)
		tmp = tmp * tmp * 
		(((power <<= 1) < 0)? num : 1);
	return tmp;
}

t_rational rat_long_pow(t_rational rat, t_atom_long num) 
{
	t_rational res;
	res.r_num = ipow(num > 0 ? rat.r_num : rat.r_den, num > 0 ? num : -num);
	res.r_den = ipow(num > 0 ? rat.r_den : rat.r_num, num > 0 ? num : -num);
    if (res.r_den == 0)
        res = t_rational(0, 1);
	// no need of reducing anything, if the incoming rational is already reduced
	return res;
}

