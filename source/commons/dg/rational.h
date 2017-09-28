/**
	@file	rational.h
	@brief	Common tools for dealing with rationals.
	
	by Daniele Ghisi
*/

#include "bach.h"

#ifdef BACH_JUCE
#include "bach_jucewrapper.h"
#endif

#ifdef BACH_MAX
#include "ext.h"
#endif

#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#include "bach_128bit.h"
#include "bach_rat.hpp"

#ifdef C74_X64
/**	Declaration of type t_atom_longlong, 128-bit integer, used with 64-bit architecture  
 @ingroup datatypes
 */
typedef t_int128 t_atom_longlong;
/**	Declaration of type t_atom_ulong, 64-bit unsigned integer, used with 64-bit architecture  
 @ingroup datatypes
 */
typedef t_uint64 t_atom_ulong;

typedef t_int32 t_atom_short;
typedef t_uint32 t_atom_ushort;

#define ATOM_LONG_PRINTF_FMT "%lld"
#ifdef MAC_VERSION
#define ATOM_LONG_MAX LONG_MAX
#define ATOM_LONG_MIN LONG_MIN
#define ATOM_ULONG_MAX ULONG_MAX
#else
#define ATOM_LONG_MAX _I64_MAX
#define ATOM_LONG_MIN _I64_MIN
#define ATOM_ULONG_MAX _UI64_MAX
#endif

#define alabs(x) llabs(x)

#else
/**	Declaration of type t_atom_longlong, 64-bit integer, used with 32-bit architecture  
 @ingroup datatypes
 */
typedef t_int64 t_atom_longlong;
/**	Declaration of type t_atom_ulong, 32-bit unsigned integer, used with 32-bit architecture  
 @ingroup datatypes
 */
typedef t_uint32 t_atom_ulong;

typedef t_int16 t_atom_short;
typedef t_uint16 t_atom_ushort;

#define ATOM_LONG_PRINTF_FMT "%ld"
#define ATOM_LONG_MAX LONG_MAX
#define ATOM_LONG_MIN LONG_MIN
#define ATOM_ULONG_MAX ULONG_MAX

#define alabs(x) labs(x)

#endif

#define RAT_MIN_POSITIVE (genrat(1, ATOM_LONG_MAX))			///< Minimum positive rational
#define RAT_MAX_NEGATIVE (genrat(-1, ATOM_LONG_MIN))		///< Maximum negative rational
#define RAT_MIN (genrat(ATOM_LONG_MIN, 1))					///< Minimum rational
#define RAT_MAX (genrat(ATOM_LONG_MAX, 1))					///< Maximum rational

#define CONST_EPSILON_FOR_DOUBLE2RAT_APPROXIMATION (2 * FLT_EPSILON)	///< Multiplier for the machine epsilon #DBL_EPSILON used while approximating a double to a rational

#define RATIONAL_PRINTF_FMT ATOM_LONG_PRINTF_FMT "/" ATOM_LONG_PRINTF_FMT

/**	Declaration of type rational, implementing a number of the kind r/s, where r and s are #t_atom_long integers.
	A rational is said to be standard as long as s != 0.

	A few conventions are needed to operate with rationals:
	If the rational is negative, the element having the minus sign has to be the numerator (r)
	If the rational is positive, both r and s have to have the plus sign
	If the rational is null, numerator has to be 1 (so no 0/4, 0/5, 0/32 fractions should be considered)
	If the (nonstandard) rational is of the kind 0/n (n>0) then it has to be reduced to 1/0 
	If the (nonstandard) rational is of the kind 0/n (n<0) then it has to be reduced to -1/0 
	It is a good rule to keep every #t_rational reduced in lowest terms, by using the function rat_reduce()
 
	Notice that the only nonstandard rationals allowed with these conventions are 1/0, -1/0 and 0/0.
 
	You don't have to follow explicitely all these conventions when operating with rationals, as long
	as you use them with the API functions. For instance, performing a rat_rat_sum() always assures that
	the result will fulfill all these conventions.
 
	To create a rational, you should use the genrat() or the long2rat() functions.
 
	@ingroup datatypes
*/
/*typedef struct _rational
{
	t_atom_long r_num;		///< Numerator
	t_atom_long r_den;		///< Denominator
} t_rational;*/
typedef t_rat<t_atom_long> t_rational;
typedef t_rat<t_atom_short> t_shortRational;



/** Convenience structure for unreduce rational (long couple). For clarity's sake it is good that in any case you need
	to keep unreduced rationals, you do this by using this structure and NOT the t_rational structure,
	which will be only used for real rationals. 

	To create a rational, you should use the genurrat() function.
	
	@ingroup datatypes
 */
/*typedef struct _urrational
{
	t_atom_long r_num;		///< Numerator
	t_atom_long r_den;		///< Denominator
} t_urrational;*/
typedef t_urrat<t_atom_long> t_urrational;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif


// -----------------  math utilities needed -------------------

/**	Utility to retrieve a sign of a double number. 
	@param	number		The number.
	@return				1 if number > 0, -1 if number < 0, 0 if number == 0.
	@ingroup			math
 */
char fsign(double number);


/**	Integer power
 	@ingroup	math
	@param		num		The base
	@param		power	The exponent
	@return		The integer power
 */
t_atom_long ipow(t_atom_long num, int power);


/**	Compute the greatest common divisor between two numbers.
	@ingroup	math
	@param	a	The first number.
	@param	b	The second number.
 */
t_atom_long gcd(t_atom_long a, t_atom_long b);


/**	Compute the least common multiple between two numbers.
	@ingroup	math
	@param	a	The first number.
	@param	b	The second number.
 */
t_atom_long lcm(t_atom_long a, t_atom_long b);



// -----------------  build and retrieve rationals  -------------------

/**	Build a rational starting from numerator and denominator.
	As all the API functions, also forces the #t_rational conventions to be matched on the result 
	(namely, the result is reduced to the lowest terms).
	@ingroup		rational
	@param	num		The numerator.
	@param	den		The denominator.
	@return			The build rational
 */
t_rational genrat(t_atom_long num, t_atom_long den);

// INTERNAL, don't use!
t_rational genrat_noreduce(t_atom_long num, t_atom_long den);


/**	Convert a long number into a rational (having denominator 1).
	@ingroup		rational
	@param	num		The number
	@return			The built rational (number/1).
 */
t_rational long2rat(t_atom_long num);


/**	Convert a #t_rational structure into a #t_urrational structure.
	@param	rat		The rational.
	@return			The rational as unreduced rational.
	@ingroup		rational
 */
t_urrational rat2urrat(t_rational rat);


/**	Convert a #t_urrational structure into a #t_rational structure, also
	reducing it to the lowest terms.
	@param	rat		The unreduced rational.
	@return			The standard (reduced) rational.
	@ingroup		rational
 */
t_rational urrat2rat(t_urrational urrat);




/**	Returns the numerator of a rational.
	@param	rat		The rational.
	@return			The numerator.
	@ingroup		rational
	@remark			You can of course access the numerator directly as rat->r_num
 */
long rat_num(t_rational rat);


/**	Returns the denominator of a rational.
	@param	rat		The rational.
	@return			The denominator.
	@remark			You can of course access the numerator directly as rat->r_den
	@ingroup		rational
 */
long rat_den(t_rational rat);


/**	Build an unreduced rational from a couple of longs.
	@ingroup		rational
	@param	num		The numerator.
	@param	den		The denominator.
	@return			The build unreduced rational
 */
t_urrational genurrat(t_atom_long num, t_atom_long den);



// -----------------  reduction functions  -------------------

/**	Reduce to the lowest terms a couple of numbers, meant as a rational num/den, but
	given separately, and NOT as a #t_rational. Also returns the gcd of the two numbers.
	Also forces all the #t_rational conventions to be matched (see #t_rational for more information).
 
	@ingroup	math
	@param	num	Pointer to the first number.
	@param	den	Pointer to the second number.
	@return		The greatest common divisor of the two numbers, with the sign of the denominator.
				If the fraction is nonstandard, 0 is returned. Use gcd() for other purposes.
				You're assured that the new value of #num times the returned gcd equals the old value of #num.
				And analogously for #den.
	@remark		To reduce a rational, use rat_reduce().
	@see		rat_reduce()
*/
t_atom_long long_long_reduce(t_atom_long *num, t_atom_long *den);


// Internal version of long_long_reduce() working only with 32-bit ints, faster than long_long_reduce() 
t_int32 long_long_reduce_int32(t_int32 *num, t_int32 *den);


/**	Reduce to the lowest terms a #t_rational.
	Also forces all the #t_rational conventions to be matched (see #t_rational for more information).
 
	@param	rat	The rational number.
	@see		long_long_reduce()
	@ingroup	rational
 */
void rat_reduce(t_rational *rat);



// -----------------  rational arithmetic  -------------------

/**	Return the opposite of a rational number.
	@ingroup	rational
	@param	rat	The rational number (r/s).
	@return		The opposed rational (-r/s).
 */
t_rational rat_opp(t_rational rat);


/**	Return the inverse of a rational number.
 @ingroup	rational
 @param	rat	The rational number (r/s).
 @return	The inverse rational (s/r).
 */
t_rational rat_inv(t_rational rat);


/**	Return the sum of two rational numbers
	@ingroup		rational
	@param	rat1	The first rational number.
	@param	rat2	The second rational number.
	@return			The sum of the two rationals (rat1 + rat2).	
 */
t_rational rat_rat_sum(t_rational rat1, t_rational rat2);


/**	Return the different of two rational numbers
	@ingroup		rational
	@param	rat1	The first rational number.
 	@param	rat2	The second rational number.
	@return			The different of the two rationals (rat1 - rat2).	
 */
t_rational rat_rat_diff(t_rational rat1, t_rational rat2); 


/**	Return the product of two rational numbers
	@ingroup		rational
	@param	rat1	The first rational number.
	@param	rat2	The second rational number.
	@return			The product of the two rationals (rat1 * rat2).	
 */
t_rational rat_rat_prod(t_rational rat1, t_rational rat2); 


/**	Return the quotient of two rational numbers
	@ingroup		rational
	@param	rat1	The first rational number.
	@param	rat2	The second rational number.
	@return			The quotient of the two rationals (rat1 / rat2).	
	@remark			Beware: the quotient of two standard rationals might not be a standard rational if the second one is 0/1.
 */
t_rational rat_rat_div(t_rational rat1, t_rational rat2); 


/**	Return the sum of a rational and a long number
	@ingroup		rational
	@param	rat1	The rational number.
	@param	num		The long number.
	@return			The #t_rational sum of the two numbers (rat1 + num).	
 */
t_rational rat_long_sum(t_rational rat1, t_atom_long num);


/**	Return the difference of a rational and a long number
	@ingroup		rational
	@param	rat1	The rational number.
	@param	num		The long number.
	@return			The #t_rational difference of the two numbers (rat1 - num).	
 */
t_rational rat_long_diff(t_rational rat1, t_atom_long num);


/**	Raise a rational number to an integer exponent
	@ingroup		rational
	@param	rat1	The rational number.
	@param	num		The integer exponent.
	@return			The result of the exponentiation.	
 */
t_rational rat_long_pow(t_rational rat, t_atom_long num);


/**	Return the difference of a long number and a rational one
	@ingroup		rational
	@param	num		The long number.
	@param	rat1	The rational number.
	@return			The #t_rational difference of the two numbers (num - rat1).	
 */
t_rational long_rat_diff(t_atom_long num, t_rational rat1);


/**	Return the quotient of a rational number and a long one
 	@ingroup		rational
	@param	num		The long number.
	@param	rat		The rational number.
	@return			The #t_rational quotient of the two numbers (rat/num).	
	@remark			Beware: if the rational is a standard one, and num = 0, the result is a nonstandard rational.
 */
t_rational rat_long_div(t_rational rat, t_atom_long num);


/**	Return the quotient of a long number and a rational one
	@ingroup		rational
	@param	rat		The rational number.
	@param	num		The long number.
	@return			The #t_rational quotient of the two numbers (num/rat).	
	@remark			Notice that if rat is nonstandard, the result might be a standard rational, and viceversa.
 */
t_rational long_rat_div(t_atom_long num, t_rational rat);


/**	Return the product of a rational number and a long one
	@ingroup		rational
	@param	rat		The rational number.
	@param	num		The long number.
	@return			The #t_rational product of the two numbers (rat * num).	
 */
t_rational rat_long_prod(t_rational rat, t_atom_long num);


/**	Return the remainder of the division between a rational number and a long one.
	@ingroup		rational
	@param	rat		The rational number.
	@param	num		The long number.
	@param	always_positive	If this flag is non-zero, the modulo is always returned as positive, even for negative numbers.
							Of course this does not correspond to simply changing the sign of such modulo, but to summing #num to the negative result.
	@return			The #t_rational remainder #rat mod #num.
	@remark			For instance, rat_long_mod(15/2, 3, true) = 3/2, since 15/2 = 2 * 3 + 3/2. 
	@remark			The sign of #num is ignored (and always taken as positive)
 */
t_rational rat_long_mod(t_rational rat, t_atom_long num, char always_positive);


/**	Return the remainder of the division between a two rational numbers
	@ingroup		rational
	@param	rat1	The first rational number.
	@param	rat2	The second rational number (modulo).
	@param	always_positive	If this flag is non-zero, the modulo is always returned as positive, even for negative numbers.
							Of course this does not correspond to simply changing the sign of such modulo, but to summing #rat2 to the negative result.
	@return			The #t_rational remainder #rat1 mod #rat2.
	@remark			For instance, rat_long_mod(9/5, 1/3, true) = 2/15, since 9/5 = 2/15 * 5 + 1/3. 
	@remark			The sign of #rat2 is ignored (and always taken as positive)
    @seealso rat_rat_divdiv()
 */
t_rational rat_rat_mod(t_rational rat1, t_rational rat2, char always_positive);



/**	Return the integer division between two rational numbers
	@ingroup		rational
	@param	rat1	The first rational number.
	@param	rat2	The second rational number.
	@param	always_positive_mod	If this flag is non-zero, the division is carried out so that the modulo is always positive (i.e. as a floor).
	@return			The integer division between #rat1 and #rat2.
	@remark			The sign of #rat2 is ignored (and always taken as positive)
    @seealso rat_rat_mod()
 */
long rat_rat_divdiv(t_rational rat1, t_rational rat2, char always_positive_mod);



/**	Return the absoulte value of a rational.
	@ingroup		rational
	@param	rat		The rational number.
	@return			The #t_rational absolute value.
	@remark			It just needs to take the absolute value of the numerator. 
 */
t_rational rat_abs(t_rational rat);


/**	Return the square of a rational.
	@ingroup		rational
	@param	rat		The rational number.
	@return			The squared rational (rat * rat).
 */
t_rational rat_square(t_rational rat);


/**	Return the greatest common divisor of two rationals.
	@ingroup		rational
	@param	a		The first rational.
	@param	b		The second rational.
	@return			The greatest common divisor between #a and #b.
	@remark			The greatest common divisor (gcd) between two rationals is a rational having as numerator
					the gcd of the numerators, and as denominator the lcm (least common multiple) of the denominators.
 */
t_rational rat_gcd(t_rational a, t_rational b);


/**	Return a clipped rational
	@ingroup		rational
	@param	rat		The number
	@param	min		The minimum
	@param	max		The maximum
	@return			The number clipped between min and max
 */
t_rational rat_clip(t_rational rat, t_rational min, t_rational max);



// -----------------  rational conversions  -------------------

/**	Tell if a rational has denominator = 1 (i.e. is essentially an integer).
	@ingroup		rational
	@param	rat		The rational number.
	@return			1 if the rational is essentially an integer, 0 otherwise.
 */
char rat_is_integer(t_rational rat);


/**	Convert a rational into a float number.
	@ingroup		rational
	@param	rat		The rational number.
	@return			The float converted number.
 */
float rat2float(t_rational rat);


/**	Convert a rational into a double-precision floating number.
	@ingroup		rational
	@param	rat		The rational number.
	@return			The converted double-prevision floating point number.
 */
double rat2double(t_rational rat);


/**	Convert an unreduced rational into a double-precision floating number.
	@ingroup			rational
	@param	urrat		The unreduced rational number.
	@return				The converted double-prevision floating point number.
 */
double urrat2double(t_urrational urrat);



/**	Force a rational to be a standard one, by mapping each nonstandard rational to the standard rational 0/1.
	@ingroup		rational
	@param	rat		The rational number.
	@return			The same number as input (if the input rational was standard), the 0/1 rational otherwise.
 */
t_rational force_standard_rational(t_rational rat);



// -----------------  rational comparisons  -------------------

/**	Compare a #t_rational and a long. 
	@param	rat		The rational number.
	@param	num		The long number.
	@return			1 if rat > num; @n
					-1 if rat < num; @n
					0 if rat == num; @n
					-2 if rat and num are non-comparable (i.e.: rat is nonstandard).
	@ingroup		rational
 */
char rat_long_cmp(t_rational rat, t_atom_long num);


/**	Compare a #t_rational and a double. 
	@param	rat		The rational number.
	@param	num		The double number.
	@param	epsilon	A threshold for the comparison: num and rat will be said to be the same if their difference is lesser than epsilon (in absolute value).
	@return			0 if rat and num are the same (i.e. |rat - num| <= epsilon). @n
					1 if rat > num + epsilon; @n
					-1 if rat < num - epsilon; @n
					-2 if rat and num are non-comparable (i.e.: rat is nonstandard). 
	@ingroup		rational
 */
char rat_double_cmp(t_rational rat, double num, double epsilon);


/**	Compare two #t_rational numbers. 
	@param	rat1	The first rational number.
	@param	rat2	The second rational number.
	@return			0 if rat1 == rat2; @n
					1 if rat1 > rat2; @n
					-1 if rat1 < rat2; @n
					-2 if the two numbers are non-comparable (i.e.: at least one of them is nonstandard). 
	@ingroup		rational
 */
char rat_rat_cmp(t_rational rat1, t_rational rat2); // -1 if rat1 < rat2, 0 if rat1 == rat2, 1 if rat1 > rat 2, -2 if not comparable



/**	Compare two #t_rational numbers, but if any of them was previously approximated, the comparison is NOT done on the rational values
	but rather on the double precision floating point values, with respect to a threshold. 
	In this latter case, if the two rationals lied within the threshold, the second one is set equal to the first one (that's why
	in this function we pass pointers to the rationals, differently from rat_rat_cmp()).
	@param	rat1					Pointer to the first rational number.
	@param	rat2					Pointer to the second rational number.
	@param	needed_to_approximate	Flag telling if any of the previous rational were previously approximated
	@param	threshold				A threshold for considering two double precision values the same
	@return			If <needed_to_approximate> is 0, this operates exactly like rat_rat_cmp() and returns the same value;
					If <needed_to_approximate> is 1, this returns 0 if the double conversions of rat1 and rat2 lie within <threshold>
					(in which case rat2 is also set equal to rat1), returns -1 if the double conversion of rat2 is bigger, returns 1 
					if the double conversion of rat1 is bigger.
	@ingroup						rational
 */

char rat_rat_cmp_account_for_approximations(t_rational *rat1, t_rational *rat2, char needed_to_approximate, double threshold);



// -----------------  rational utilities  -------------------

/**	Approximate a double precision floating number with a rational having a fixed denominator, and also computes the error. 
	@param	num			The number (double) to approximate.
	@param	max_den		The fixed denominator.
	@param	direction	1 if you want the approximation to be above the original number; @n
						-1 if you want the approximation to be below the original number; @n
						0 if you just want to choose the closest approximation (either above or below the original number).
	@param	error		A pointer to a double *, to be filled with the difference between the (double) number and the rational approximation (num - rat).
						Leave NULL if you don't need it.
	@return				A rational approximating the double number.
	@ingroup			rational
 */
t_rational approx_double_with_rat_fixed_den(double num, t_atom_long fixed_den, char direction, double *error);

t_urrational approx_double_with_rat_fixed_den_no_reduce(double num, t_atom_long fixed_den, char direction, double *error);


/**	Approximate a double precision floating number with a rational having at most a given denominator, and also computes the error. 
	@param	num			The number (double) to approximate.
	@param	max_den		The maximum denominator.
	@param	direction	1 if you want the approximation to be above the original number; @n
						-1 if you want the approximation to be below the original number; @n
						0 if you just want to choose the closest approximation (either above or below the original number).
	@param	error		A pointer to a double *, to be filled with the difference between the (double) number and the rational approximation (num - rat).
						Leave NULL if you don't need it.
	@return				A rational approximating the double number.
	@remark				This function is way slower than approx_double_with_rat_fixed_den(), since it tries all the possible denominators
						up to #max_den. You might want to use approx_double_with_rat_fixed_den() for fast purposes.
	@see				approx_double_with_rat_fixed_den()
	@ingroup			rational
 */
t_rational approx_double_with_rat_best_match(double num, t_atom_long max_den, char direction, double *error);


t_rational approx_double_with_rat_up_to_tolerance(double number, double tolerance, t_atom_long max_den, char direction, char tolerance_is_ratio, double *error, char *found);

t_rational approx_double_with_rat_smart_permanence(double number, double tolerance, t_atom_long max_den, char direction, char tolerance_is_ratio, double *error, char *found);



/**	Approximate a rational with another one having a specific denominator. 
	@param	rat		The rational number to approximate.
	@param	den		The denominator of the approximation.
	@return			The approximated rational.
	@remark			Since the approximated rational is automatically reduced, it might be that its denominator is no more den, but surely a divisor of den.
	@see			ceil_rat_with_rat_fixed_den()
	@ingroup		rational
 */
t_rational approx_rat_with_rat_fixed_den(t_rational rat, t_atom_long den);


/**	Approximate a rational with another one, *above* it, having a specific denominator. 
	@param	rat		The rational number to approximate.
	@param	den		The denominator of the approximation.
	@return			The ceiled rational (approximated rational above the original one)
	@remark			Since the approximated rational is automatically reduced, it might be that its denominator is no more den, but surely a divisor of den.
	@see			approx_rat_with_rat_fixed_den()
	@ingroup		rational
 */
t_rational ceil_rat_with_rat_fixed_den(t_rational rat, t_atom_long den);


/**	Utility to linearly rescale a rational, which ranged through a minimum and a maximum, to a new range. All boundaries are #t_rational.
	@param	value	The rational to rescale.
	@param	min		The current minimum for value.
	@param	max		The current maximum for value.
	@param	new_min	The new minimum.
	@param	new_max	The new maximum.
	@return			The rescaled rational, within the new range.
	@ingroup		rational
 */
t_rational rat_rescale(t_rational value, t_rational min, t_rational max, t_rational new_min, t_rational new_max);


/**	Perform the discrete integration of a list of rationals, starting from a list of (rational) differences. 
	@param	num_rational	The number of rational differences.
	@param	rationals		The array of rational differences.
	@param	start_rational	The rational starting point for the integration.
	@param	out_rationals	A pointer to a #t_rational ** to be filled with the result of the integration.
							The first element will always be start_rational, then 
	@remark					For instance, if rationals = (1/2, 1/4, 1/8) and start_rational = -3/2, then the result will be (-3/2, -1, -3/4, -5/8)
							so that the differences between consecutive elements in the result list yields the original rationals list.
	@ingroup				rational
 */
void rat_dx2x(long num_rationals, t_rational *rationals, t_rational start_rational, t_rational **out_rationals);



// -----------------  integer&remainders representation of rationals  -------------------

/**	Perform the sum of two rationals in their "integer and remainders"-representation (i&r, for short).
	This representation is such that each rational q is represented as q = i + r, where i is integer and r is rational.
	
	@param	int1	The integer part of the first rational.
	@param	rem1	The rational part of the first rational (rem says for "remainder"...).
	@param	int2	The integer part of the second rational.
	@param	rem2	The rational part of the second rational.
	@return			The sum of the two i&r rationals, i.e. int1+int2+rem1+rem2.
	@remark			This i&r representation is sometimes used in bach code (as in the quantize functions)
					in order to avoid a loss of precision for rationals when numerator >> denominator.
					The standard behaviour is to keep 0 <= r < 1, so that i = floor(q).
					Within this convention, we're sure that if we can represent, say, 7 + r, we can surely represent,
					say, 12932045 + r also. In general, if you can represent i + r, you can of course represent i' + r
					for any i' long.
	@ingroup		rational
*/
t_rational rat_rat_sum_integer_and_remainders(t_atom_long int1, t_rational rem1, t_atom_long int2, t_rational rem2);


/**	Perform the difference of two rationals in their "integer and remainders"-representation (i&r, for short).
	See rat_rat_sum_integer_and_remainders() for more information about the i&r representation.
 
	@param	int1	The integer part of the first rational.
	@param	rem1	The rational part of the first rational.
	@param	int2	The integer part of the second rational.
	@param	rem2	The rational part of the second rational.
	@return			The sum of the two i&r rationals, i.e. (int1-int2)+(rem1-rem2).
	@see			rat_rat_sum_integer_and_remainders()
	@ingroup		rational
 */
t_rational rat_rat_diff_integer_and_remainders(t_atom_long int1, t_rational rem1, t_atom_long int2, t_rational rem2);


/**	Compare two rationals in their "integer and remainders"-representation (i&r, for short).
	See rat_rat_sum_integer_and_remainders() for more information about the i&r representation.
 
	@param	int1	The integer part of the first rational.
	@param	rem1	The rational part of the first rational.
	@param	int2	The integer part of the second rational.
	@param	rem2	The rational part of the second rational.
	@return			0 if int1+rem1 == int2+rem2.
					1 if int1+rem1 > int2+rem2;
					-1 if int1+rem1 < int2+rem2;
					-2 if the two numbers are non-comparable (i.e.: at least a rational part is nonstandard).
	@see			rat_rat_sum_integer_and_remainders()
	@remark			VERY IMPORTANT!!! This ONLY works if each input undergoes the convention expressed in 
					rat_rat_sum_integer_and_remainders(), i.e. that each rational part r is such that
					0 <= r < 1, and thus the integer parts are the floor() of the complete rational.
					If this is NOT verified, the correct comparison is NOT assured.
	@ingroup		rational
 */
char rat_rat_cmp_integer_and_remainders(t_atom_long int1, t_rational rem1, t_atom_long int2, t_rational rem2);




// INTERNAL UNDOCUMENTED FUNCTIONS
#ifndef DOXYGEN_SHOULD_SKIP_THIS

// approximate a rational with another one having numerator < <max_num> and denominator < <max_den>
t_rational approx_rat_with_rat(t_rational rat, t_atom_long max_num, t_atom_long max_den);	 

// as the previous one, but also reports if the rational has been changed
t_rational approx_rat_with_rat_notify(t_rational rat, t_atom_long max_num, t_atom_long max_den, char *changed);

// as approx_rat_with_rat() but always ceils
t_rational ceil_approx_rat_with_rat(t_rational rat, t_atom_long max_num, t_atom_long max_den);

// tell if a sum/prod/div of rationals has SURELY num and den < <max_number> (it's a sufficient but not necessary condition)
char is_rat_rat_sum_safe(t_rational rat1, t_rational rat2, t_atom_long max_number);
char is_rat_rat_prod_safe(t_rational rat1, t_rational rat2, t_atom_long max_number);
char is_rat_rat_div_safe(t_rational rat1, t_rational rat2, t_atom_long max_number);

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _RATIONAL_H_