/**
	@file	bach_math_utilities.h
	@brief	Mathematical utilities
	
	by Daniele Ghisi
*/

#ifndef _BACH_MATH_UTILITIES_H_
#define _BACH_MATH_UTILITIES_H_

// general mathematical utilities

#include "llll_math.h"
#include "lexpr.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif



/**	Swap two double numbers.
	@ingroup	miscellanea
	@param		d1	The first number
	@param		d2	The second number
 */
void swap_doubles(double *d1, double *d2);


/**	Reorder a triplet of double-precision numbers, by reassigning their values so that f1 < f2 < f3.
	@ingroup	miscellanea
	@param		f1	The first number
	@param		f2	The second number
	@param		f3	The third number
 */
void reorder_triplet_of_doubles(double *f1, double *f2, double *f3);


/**	Non-negative modulo for long numbers (yielding the solution >= 0 also for negative numbers).
	@ingroup	math
	@param		num	The number
	@param		mod	The modulo
	@return		The positive modulo
 */
long positive_mod(long num, long mod);


/**	Non-negative modulo for double numbers (yielding the solution >= 0 also for negative numbers).
	@ingroup	math
	@param		num	The number
	@param		mod	The modulo
	@return		The positive modulo
 */
double positive_fmod(double num, double mod);


/**	Solve the ax^3 + bx^2 + cx + d = 0 equation, yielding a real solution.
	@ingroup	math
	@param	a	The coefficient for x^3.
	@param	b	The coefficient for x^2.
	@param	c	The coefficient for x.
	@param	d	The degree-zero coefficient.
	@return		A real solution for the equation ax^3 + bx^2 + cx + d = 0.
 */
double solve_cubic(double a, double b, double c, double d);


/**	Linearly rescale a double (which ranged from a minimum and a maximum) to a new range. 
	@ingroup	math
	@param	value				The value to rescale.
	@param	min					The current minimum.
	@param	max					The current maximum.
	@param	new_min				The new minimum.
	@param	new_max				The new maximum.
	@return						The rescaled value.
	@see						rescale_with_slope()
 */
double rescale(double value, double min, double max, double new_min, double new_max);


/**	Rescale a double (which ranged from a minimum and a maximum) to a new range. Also takes into account a slope factor, corresponding to a
	sort of "exponent" for the rescaling.
	@ingroup	math
	@param	value				The value to rescale.
	@param	min					The current minimum.
	@param	max					The current maximum.
	@param	new_min				The new minimum.
	@param	new_max				The new maximum.
	@param	slope				The slope factor, ranging from -1 to 1. If slope is 0, the rescaling is linear, as slope increase towards 1 the 
								curve becomes "simil-exponential", as the slope decrease towards -1 the curve becomes "simil-logarithmic".
	@param	admit_mirroring		If this is 1, and the slope is positive, the algorithm will reverse the slope, rescale the value, and then mirror the value
								with respect to the new range. Let this to 0 if you don't want this mirroring-behavior.
	@return						The rescaled value.
	@remark						The -1 to 1 slope mapping is similar, but NOT identical, to the one used in Max by the [curve~] object.
	@see						rescale_same_boundaries_with_slope(), rescale()
 */
double rescale_with_slope(double value, double min, double max, double new_min, double new_max, double slope);


// Same as rescale_with_slope, but performs inverse mapping
double rescale_with_slope_inv(double value, double min, double max, double new_min, double new_max, double slope);

/**	Rescale a double (which ranged from a minimum and a maximum) to a new range. 
	Also takes into account a slope factor, corresponding to a sort of "exponent" for the rescaling, and computes the derivative in the point.
	@ingroup	math
	@param	value				The value to rescale.
	@param	min					The current minimum.
	@param	max					The current maximum.
	@param	new_min				The new minimum.
	@param	new_max				The new maximum.
	@param	slope				The slope factor, ranging from -1 to 1. If slope is 0, the rescaling is linear, as slope increase towards 1 the 
								curve becomes "simil-exponential", as the slope decrease towards -1 the curve becomes "simil-logarithmic".
	@param	derivative			Pointer which will be filled with the derivative at #value; leave NULL if not needed
	@param	admit_mirroring		If this is 1, and the slope is positive, the algorithm will reverse the slope, rescale the value, and then mirror the value
								with respect to the new range. Let this to 0 if you don't want this mirroring-behavior.
	@return						The rescaled value.
	@remark						The -1 to 1 slope mapping is similar, but NOT identical, to the one used in Max by the [curve~] object.
	@see						rescale_same_boundaries_with_slope(), rescale()
 */
double rescale_with_slope_and_get_derivative(double value, double min, double max, double new_min, double new_max, double slope, double *derivative);


// Same, with inverse mapping
double rescale_with_slope_and_get_derivative_inv(double value, double min, double max, double new_min, double new_max, double slope, double *derivative);


/**	Rescale a double (which ranged from a minimum and a maximum) to the same range, but taking a slope factor into account, corresponding to a
	sort of "exponent" for the rescaling. It is essentially a wrapper for rescale_with_slope(), setting new_min = min and new_max = max.
	@ingroup	math
	@param	value				The value to rescale.
	@param	min					The current minimum.
	@param	max					The current maximum.
	@param	slope				The slope factor, ranging from -1 to 1. If slope is 0, the rescaling is linear, as slope increase towards 1 the 
								curve becomes "simil-exponential", as the slope decrease towards -1 the curve becomes "simil-logarithmic".
								with respect to the new range. Let this to 0 if you don't want this mirroring-behavior (adviced!)
	@return						The rescaled value.
	@remark						The -1 to 1 slope mapping is similar, but NOT identical, to the one used in Max by the [curve~] object.
	@see						rescale_with_slope()
 */
double rescale_same_boundaries_with_slope(double value, double min, double max, double slope);


/**	Calculate the determinant of a 3x3 matrix of doubles.
	@ingroup	math
	@param		a11		The matrix element in position (1, 1)
	@param		a12		The matrix element in position (1, 2)
	@param		a13		The matrix element in position (1, 3)
	@param		a21		The matrix element in position (2, 1)
	@param		a22		The matrix element in position (2, 2)
	@param		a23		The matrix element in position (2, 3)
	@param		a31		The matrix element in position (3, 1)
	@param		a32		The matrix element in position (3, 2)
	@param		a33		The matrix element in position (3, 3)
	@return				The determinant of the matrix.
 */
double compute_det_for_matrix_of_size_3(double a11, double a12, double a13, 
										double a21, double a22, double a23,
										double a31, double a32, double a33);

	
/**	Compare two doubles, with respect to a certain threshold.
	@ingroup	math
	@param		num1	The first value
	@param		num2	The second value
	@param		thresh	The threshold
	@return				0 if the num1 == num2 (up to the threshold); otherwise 1 if num1 > num2, -1 if num1 < num2.
 */
char double_double_cmp_with_threshold(double num1, double num2, double threshold);


/**	Convert a frequence into a midicents value.
	@ingroup	math
	@param		freq			The frequence (in Hz)
	@param		reference_freq	Frequence (in Hz) of the diapason A (e.g. 440)
	@return						The midicents value
 */
double f2mc(double freq, double reference_freq);

	
/**	Convert a midicents value into a frequence.
	@ingroup	math
	@param		mc				The midicents value
	@param		reference_freq	Frequence (in Hz) of the diapason A (e.g. 440)
	@return						The frequence value in Hz
 */
double mc2f(double mc, double reference_freq);


/**	Compute an integer power. Only works for non-negative exponents.
	@ingroup	math
	@param		base			A non-negative integer, as base
	@param		exponent		A non-negative integer, as exponent
	@return						The power base^exponent
 */
long iexp(long base, long exponent);


/**	Compute an integer power of two. Only works for non-negative exponents.
	@ingroup	math
	@param		exponent		A non-negative integer
	@return						The power 2^exponent
 */
long iexp2(long exponent);


/**	Conversion of an angle from degrees to radiants.
	@ingroup	math
	@param		deg		The angle in degrees
	@return				The angle in radiants
 */
double deg2rad(double deg);


/**	Conversion of an angle from radiants to degrees.
	@ingroup	math
	@param		deg		The angle in radiants
	@return				The angle in degrees
 */
double rad2deg(double rad);


/**	Tell if a long number is contained in a long array
	@ingroup			math
	@param	array		The pointer to the first element in the array
	@param	num_elem	The number of elements in the whole #array
	@param	num_to_find	The long number to be found
	@return				1 if #num_to_find was found in the #array, 0 otherwise 
 */
char is_long_in_long_array(long *array, long num_elems, long num_to_find);


/**	Tell if a double number is contained in a double array
	@ingroup			math
	@param	array		The pointer to the first element in the array
	@param	num_elem	The number of elements in the whole #array
	@param	num_to_find	The double number to be found
	@param	tolerance	A tolerance for the identification (set 0 if none)
	@return				1 if #num_to_find was found in the #array, 0 otherwise 
 */
char is_double_in_double_array(double *array, double num_elems, double num_to_find, double tolerance);


/**	Find the minimum value of an array of doubles, from a starting index to an ending index (both included).
	@ingroup			math
	@param	num_elem	The number of elements in the whole <array>
	@param	start		The starting index
	@param	end			The ending index
	@param	array		The pointer to the first element in the array
	@return			The minimum of the array between the chosen indices (both included).	
 */
double array_fmin(long num_elem, long start, long end, double *array);


/**	Find the maximum value of an array of doubles, from a starting index to an ending index (both included).
	@ingroup			math
	@param	num_elem	The number of elements in the whole <array>
	@param	start		The starting index
	@param	end			The ending index
	@param	array		The pointer to the first element in the array
	@return			The maximum of the array between the chosen indices (both included).	
 */
double array_fmax(long num_elem, long start, long end, double *array);


/**	Find the first index (within an array of longs) corresponding to a given element. 
	The function searches the array (from beginning to the end), and stops as it finds an element equal to 
	<elem_to_find>, and thus returns its index. If nothing is found, the function returns -1.
	@ingroup				math
	@param	num_elem		The number of elements in the whole <array>
	@param	elem_to_find	The element whose index need to be found.
	@param	array			The pointer to the first element in the array
	@return				The index of the first appearence of the <elem_to_find> in the <array>, or -1 if <elem_to_find> is not found. 	*/
long longarray_findidx(long num_elem, long elem_to_find, long *array);


/**	Find the maximum value of an array of doubles, from a starting index to an ending index (both included), and also return
	the index corresponding to the maximum.
	@ingroup			math
	@param	num_elem	The number of elements in the whole <array>
	@param	start		The starting index
	@param	end			The ending index
	@param	array		The pointer to the first element in the array
	@param	idx			A pointer which will be filled with the index of the maximum.
	@return				The maximum of the array between the chosen indices (both included).	*/
double array_fmax_and_idx(long num_elem, long min, long max, double *array, long *idx);


/**	Find the maximum value of the sequence of values <scalar> - <array_to_subtract>, i.e. of the sequence of elements obtained
	by taking each element x of the <array_to_subtract>, and then modifying it to <scalar> - x. The maximum of these values (only
	taking indices from <min> to <max>) is returned.
	@ingroup					math
 	@param	num_elem			The number of elements in the whole <array>
 	@param	start				The starting index
	@param	end					The ending index
	@param	scalar				The scalar to which will be subtracted the array
	@param	array_to_subtract	The pointer to the first element in the array (which will be subtracted from the scalar)
	@return						The maximum of the <scalar> - <array_to_subtract> sequence, between the chosen indices (both included).	*/
double array_fmax_with_scalar_diff(long num_elem, long min, long max, double scalar, double *array_to_subtract);


/**	Find the maximum value of the difference of arrays <array> - <array_to_subtract>, i.e. of the sequence of elements obtained
 	by taking the i-th element x of <array> and y of <array-to_subtract>, and then computing x - y. 
	The maximum of these values (only taking indices from <min> to <max>) is returned.
	@ingroup					math
	@param	num_elem			The number of elements in the whole <array>
 	@param	start				The starting index
 	@param	end					The ending index
	@param	array				The pointer to the first element in the first array
	@param	array_to_subtract	The pointer to the first element in the array which will be subtracted from the first one
	@return						The maximum of the <array> - <array_to_subtract> sequence, between the chosen indices (both included).	
 
	@remark						The	two arrays must be equally sized! 
*/
double array_fmax_with_diff(long num_elem, long min, long max, double *array, double *array_to_subtract);


/**	Tell if a number is inside an array of numbers (modulo a certain number, and with a tolerance)
	@ingroup			miscellanea
	@param	number		The number
	@param	num_elem	Number of elements of the array
	@param	array		The array
	@param	tolerance	The tolerance
	@param	modulo		The modulo of the arithmetic
	@return				1 if the number was found, 0 otherwise
*/
char is_number_in_double_array_with_modulo(double number, double num_elem, double *array, double tolerance, double modulo);


/**	Fill an array of type char with a list of values.
	@ingroup		miscellanea
	@param	a		The pointer to the first element of the array.
	@param	count	The number of elements to fill

	@remark			<count> must be <= of the size of the array! 
	@remark			This is just a little wrapper to avoid using multiple lines to set each single element of the array. 
					For instance the following code fills the array <myarray> with 6 values: 0, 1, 2, 3, 4 and 5. 
					Functions fill_long_array(), fill_unicodeChar_array() and fill_double_array() operate in the same way.
	@code
	char myarray[6];
	fill_char_array(myarray, 6, 0, 1, 2, 3, 4, 5); 
	@endcode
 */
void fill_char_array(char *a, long count,...);


/**	Fill an array of type long with a list of values (see fill_char_array() for an example).
	@ingroup		miscellanea
	@param	a		The pointer to the first element of the array.
	@param	count	The number of elements to fill
 
	@remark			<count> must be <= of the size of the array! 
	@see			fill_char_array()
 */
void fill_long_array(long *a, long count,...);


/**	Fill an array of type double with a list of values (see fill_char_array() for an example).
	@ingroup		miscellanea
	@param	a		The pointer to the first element of the array.
	@param	count	The number of elements to fill
 
	@remark			<count> must be <= of the size of the array! 
	@see			fill_char_array()
 */
void fill_double_array(double *a, long count,...);


/**	Clip a long value (in place) between a minimum and a maximum
	@ingroup		math
	@param	num		Pointer to the number which will be clipped (the result will be put in this same pointer: in place!)
	@param	min		Minimum value for clipping
	@param	max		Maximum value for clipping
 */
void clip_long(long *num, long min, long max);


/**	Clip a rational value (in place) between a minimum and a maximum
	@ingroup		math
	@param	num		Pointer to the number which will be clipped (the result will be put in this same pointer: in place!)
	@param	min		Minimum value for clipping
	@param	max		Maximum value for clipping
 */
void clip_rat(t_rational *num, t_rational min, t_rational max);


/**	Clip a double value (in place) between a minimum and a maximum
 	@ingroup		math
	@param	num		Pointer to the number which will be clipped (the result will be put in this same pointer: in place!)
	@param	min		Minimum value for clipping
	@param	max		Maximum value for clipping
 */
void clip_double(double *num, double min, double max);


/**	Clip a #t_int32 value (in place) between a minimum and a maximum
	@ingroup		math
	@param	num		Pointer to the number which will be clipped (the result will be put in this same pointer: in place!)
	@param	min		Minimum value for clipping
	@param	max		Maximum value for clipping
 */
void clip_int32(t_int32 *num, long min, long max);


/**	Get the sign of a long number.
	@ingroup			math
	@param	number		The number
	@return				1 if number > 0, 0 if number == 0, -1 if number < 0
 */
char isign(long number);


/**	Get the logarithm in base 2 of a given number, but only if the number is a power of two.
	Otherwise, -1 is obtained.
	@ingroup			math
	@param	number		The number whose logarithm needs to be found.
	@return				If <number> = 2^k for some k, the logarithm in base two of <number> (i.e. k); otherwise -1.
 
	@remark				For instance, perfect_log2(16) = 4, perfect_log2(1) = 0, perfec_log2(15) = -1.
 */
int perfect_log2(long number);


/**	Tell if a rational is non-standard (i.e. has denominator = 0).
	@ingroup		math
	@param	rat		The rational
	@return			1 if the rational is nonstandard (of the form k/0), 0 otherwise.
 */
char is_ratio_invalid(t_rational rat); //1 if the ratio is something/0

void change_long_from_llllelem(long *number, t_llllelem *modify, char convert_deg2rad);
void change_double_from_llllelem(double *number, t_llllelem *modify, char convert_deg2rad);


/**	Change the value of a double, by snapping it into the nearest number of a list (grid) of numbers.
 
	@param value				Pointer to the number to be modified
	@param ysnap_possibilities	An llll containing as elements the numbers of the grid. #value will be changed with the number of the grid nearest to it.
	@param force_snap_direction	Leave 0 for standard behavior. Any positive integer forces the snapping to be a "ceil"-like snapping (snapped values
								must be greater or equal than original value); any negative integer forces the snapping to be "floor"-like snapping
								(snapped values must be less or equal to the original value).
	@return						The llllelem of #ysnap_possibilities to which the value has been snapped (or NULL if none)
	@remark						This is used for the the slot y-snapping (and z-snapping)
	@ingroup					math
 */
t_llllelem *ysnap_double(double *value, t_llll *ysnap_possibilities, char force_snap_direction);



/**	Find distance between two angles
	@param	angle1	First angle
	@param	angle2	Second angle
	@param	modulo	The measure of the turn (e.g. 360 or 2 * PI)
	@return			The (positive) distance between the two angles
	@ingroup					math
 */
double angle_dist(double angle1, double angle2, double modulo);





/**	Obtain the plus "+" operator.
	@return	The plus operaton as a #t_lexpr_token.
 */
t_lexpr_token get_plus_operator();


/**	Obtain the minus "-" operator.
	@return	The minus operaton as a #t_lexpr_token.
 */
t_lexpr_token get_minus_operator();


/**	Obtain the times "*" operator.
	@return	The times operaton as a #t_lexpr_token.
	@ingroup linear_algebra
 */
t_lexpr_token get_times_operator();


/**	Obtain the division "/" operator.
	@return	The division operaton as a #t_lexpr_token.
 */
t_lexpr_token get_div_operator();

/**	Obtain the square root function.
	@return	The square root function as a #t_lexpr_token.
 */
t_lexpr_token get_sqrt_function();





// yet undocumented, somehow private
double random_double_in_range(double a, double b);
void resample(double *array, long array_size, double offset, double *resampled, double resampled_size, char degree);
double find_mode_of_double_array_with_modulo(double *array, long array_size, double tolerance, double modulo);
void reorder_triplet_of_doubles_and_other_doubles_accordingly(double *f1, double *f2, double *f3, double *accord1, double *accord2, double *accord3);
void reorder_triplet_of_doubles_and_other_doubles_and_double_arrays_accordingly(double *f1, double *f2, double *f3, 
																				double *accord1, double *accord2, double *accord3, double **aa1, double **aa2, double **aa3, double **ab1, double **ab2, double **ab3);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _BACH_MATH_UTILITIES_H_