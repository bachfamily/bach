/**
	@file	llll_commons_ext.h
	@brief	Advanced functions for dealing with lllls
	
	by Daniele Ghisi
*/

#ifndef _LLLL_COMMONS_EXT_H_
#define _LLLL_COMMONS_EXT_H_

// higher level llll functions

#include "bach.h"
#include "hatom.h"
#include "lexpr.h"


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif



typedef enum _pad_mode {
    BACH_PAD_REPEAT = 0,                                ///< Repeat first or last element, e.g. abccccccc...
    BACH_PAD_LOOP = 1,                                  ///< Loop elements, e.g. abcabcabcabc...
    BACH_PAD_LOOP_PALINDROME = 2,                       ///< Palindrome loop, e.g. abccbaabccbaabc...
    BACH_PAD_LOOP_PALINDROME_NO_REPEAT = 3,             ///< Palindrome loop without repetitions: abcbabcbabcba...
} e_pad_mode;


// called by llll_poset
typedef long (*poset_fn)(void *data, t_llllelem *a, t_llllelem *b);



// ------------------------------
// ARRAYS UTILITIES
// ------------------------------

/**	Find the number of zeros in a long array
	@ingroup		math
	@param	array	The array (pointer to the first element)
	@param	length	The length of the array
	@return			The number of zeros in <array>.
 */
long get_num_zeros_in_long_array(long *array, long length);


/**	Convenience function converting an array containing longs into a string. 
	@ingroup		miscellanea
	@param	array	The array (pointer to the first element)
	@param	length	The length of the array
	@param	wrapping_brackets	If this is 1, the algorithm also add wrapping brackets around the whole array
	@return			A pointer to an initialized string, filled with the text data
 */
char *long_array_to_string(long *array, long length, char wrapping_brackets);


/**	Convenience function converting an array containing chars into a string. 
	@ingroup		miscellanea
	@param	array	The array (pointer to the first element)
	@param	length	The length of the array
	@param	wrapping_brackets	If this is 1, the algorithm also add wrapping brackets around the whole array
	@return			A pointer to an initialized string, filled with the text data
 */
char *char_array_to_string(char *array, long length, char wrapping_brackets);


/**	Convenience function converting an array containing doubles into a string. 
	It automatically trims the 0's at the end of each double value.
	@ingroup		miscellanea
	@param	array	The array (pointer to the first element)
	@param	length	The length of the array
	@param	max_decimals		Maximum number of decimals for the doubles. Use -1 to have all possible decimals.
	@return			A pointer to an initialized string, filled with the text data
 */
char *double_array_to_string(double *array, long length, int max_decimals);


/**	Convenience function converting an array containing doubles into a plain llll. 
	@ingroup		llll_utilities
	@param	array	The array (pointer to the first element)
	@param	length	The length of the array
	@return			A plain llll with the same data set of the array 
 */
t_llll *double_array_to_llll(double *array, long length);


/**	Convenience function converting an array containing rationals into a plain llll. 
	@ingroup		llll_utilities
	@param	array	The array (pointer to the first element)
	@param	length	The length of the array
	@return			A plain llll with the same data set of the array 
 */
t_llll *rat_array_to_llll(t_rational *array, long length);


/**	Convenience function converting an array containing rationals into a string. 
	@ingroup		miscellanea
	@param	array	The array (pointer to the first element)
	@param	length	The length of the array
	@param	wrapping_brackets	If this is 1, the algorithm also add wrapping brackets around the whole array
	@return			A pointer to an initialized string, filled with the text data
 */
char *rat_array_to_string(t_rational *array, long length, char wrapping_brackets);


/**	Convenience function converting an llll into an array of doubles, which will be allocated
	@ingroup		miscellanea
	@param	ll		The llll
	@param	array	Pointer to the array. The memory will be properly allocated, so you need to free it yourself then.
					If the original llll is null, the pointer is not allocated and set to NULL.
	@return			The length of the allocated array (or 0 if not allocated)
 */
long llll_to_double_array(t_llll *ll, double **array);


/**	Convenience function converting an llll into an array of doubles (already allocated)
	@ingroup		miscellanea
	@param	ll		The llll
    @param  size    The array size
	@param	array	Pointer to the array.
 */
void llll_to_fixed_double_array(t_llll *ll, long size, double *array);

// To be documented
void llll_to_fixed_unicodeChar_array(t_llll *ll, long size, unsigned short *array);
void llll_to_fixed_char_array(t_llll *ll, long size, char *array);


/**	Convenience debug function converting a double into string, automatically trimming the 0's at the end.
	@ingroup		miscellanea
	@param	val		The value
	@param	max_decimals		Maximum number of decimals for the doubles. Use -1 to have all possible decimals.
	@return			A pointer to an initialized string, filled with the text data
	@see			double_array_to_string()
 */
char *double_to_string(double val, int max_decimals);


/**	Convenience debug function converting a pair of doubles into string, automatically trimming the 0's at the end of each double value.
	@ingroup		miscellanea
	@param	val1	The first value
	@param	val2	The second value
	@param	max_decimals		Maximum number of decimals for the doubles. Use -1 to have all possible decimals.
	@return			A pointer to an initialized string, filled with the text data
	@see			double_array_to_string()
 */
char *double_pair_to_string(double val1, double val2, int max_decimals);


// TBD
t_symbol *double_to_symbol(double val, int max_decimals);

// ------------------------------
// ATOMS UTILITIES
// ------------------------------


/**	Tell if an atom is of numeric type (i.e. #A_LONG or #A_FLOAT)
	@ingroup		miscellanea
	@param	atom	Pointer to the #t_atom structure
	@return			1 if the atom is numeric, 0 otherwise
	@see			is_hatom_number()
 */
char is_atom_number(t_atom *atom);


/**	Translate an atom into a symbol (even if the atom is of type #A_LONG or #A_FLOAT)
	@ingroup		miscellanea
	@param	atom	Pointer to the #t_atom structure
	@return			The symbol representing the atom (if the atom is a symbol, the symbol itself; otherwise a gensym() of the numeric value)
 */
t_symbol *atom_to_symbol(t_atom *atom);


/**	Clip a (numeric) atom between two values
	@ingroup		miscellanea
	@param	atom	Pointer to the #t_atom structure
	@param	min		The minimum value the atom can assume
	@param	max		The maximum value the atom can assume
	@see			atom_max
	@see			atom_min
 */
void clip_atom(t_atom *atom, double min, double max);


/**	Force a (numeric) atom to be at least a given value
	@ingroup		miscellanea
	@param	atom	Pointer to the #t_atom structure
	@param	val		The minimum value the atom can assume
	@see			atom_min
 */
void atom_max(t_atom *atom, double val);


/**	Force a (numeric) atom to be at most a given value
	@ingroup		miscellanea
	@param	atom	Pointer to the #t_atom structure
	@param	val		The maximum value the atom can assume
	@see			atom_max
 */
void atom_min(t_atom *atom, double val);


/**	Copy an array of atoms.
	@ingroup		miscellanea
	@param	from	Source array of atoms
	@param	to		Destination array of atoms
	@param	size	Number of atoms to be copied
	@remark			The #to array must already be allocated.
*/
void copy_atomarrays(t_atom *from, t_atom *to, long size);


/**	Copy an array of atoms, but converting floats to longs.
	@ingroup		miscellanea
	@param	from	Source array of atoms
	@param	to		Destination array of atoms
	@param	size	Number of atoms to be copied
	@remark			The #to array must already be allocated.
*/
void copy_atomarrays_avoid_floats(t_atom *from, t_atom *to, long size);




// ------------------------------
// LLLL UTILITIES
// ------------------------------

/**	Tell if an hatom is of numeric type (i.e. #H_LONG or #H_RAT or #H_DOUBLE)
	@ingroup		llll_utilities
	@param	hatom	Pointer to the hatom
	@return			1 if the hatom is numeric, 0 otherwise
	@see			is_atom_number()
 */
char is_hatom_number(t_hatom *hatom);


/**	Wrap an llll with one more level of parenthesis. The address of the llll is changed
	accordingly to match the address of the outer list
	@ingroup		llll_utilities
	@param	inlist	Pointer to the llll
 */
void llll_wrap_once(t_llll **inlist);


/**	Destroy the first element of a llll
	@ingroup		llll_utilities
	@param	inlist	The llll
	@return			The same llll as the input one (dummy return, only needed to call functions in one-line-sequence here and there)
 */
t_llll *llll_behead(t_llll *inlist);


/**	Destroy the last element of a llll
	@ingroup		llll_utilities
	@param	inlist	The llll
	@return			The same llll as the input one (dummy return, only needed to call functions in one-line-sequence here and there)
 */
t_llll *llll_betail(t_llll *inlist);


/**	Return the 1-based position (simple path) of an llllelem inside its parent llll.
	For instance, inside (a (b c d) e (f g) h i), if elem = h, the function returns 5 (since it's the 5th element in the llll)
	@ingroup		llll_utilities
	@param	elem	The llllelem
	@return			The 1-based position of the element inside its parent llll.
 */
long llllelem_getpos(t_llllelem *elem);


/**	Only keep the first <num_elem> elements of a llll
	@ingroup			llll_utilities
	@param	inlist		The llll
	@param	num-elems	The number of elements to be kept
 */
void llll_trim(t_llll *in_llll, long num_elems);


/**	Returns a new llll containing a given range of elements of a given llll.
	@ingroup			llll_utilities
	@param	from		The starting element
	@param	to			The ending element
	@return				An llll with all elements from #from to #to.
 */
t_llll *llll_subllll(t_llllelem *from, t_llllelem *to);


/**	Substitute each element in a llll with its absolute value (destructive)
	@ingroup		llll_utilities
	@param	in_llll	The llll
 */
void llll_abs(t_llll *llll);


/**	Find the overall sum of an llll containing rationals (or longs).
	@ingroup			llll_utilities
	@param	in_llll		The llll
	@return				The sum of all the elements in the llll
 */
t_rational llll_sum_of_rat_llll(t_llll *in_llll);


/**	Find the overall sum of an llll containing doubles.
	@ingroup			llll_utilities
	@param	in_llll		The llll
	@return				The sum of all the elements in the llll
 */
double llll_sum_of_doubles_llll(t_llll *in_llll);


/**	Find the overall sum of the absolute values of the elements of an llll containing rationals (or longs).
	@ingroup			llll_utilities
	@param	in_llll		The llll
	@return				The sum of all the absolute values of the elements in the llll
 */
t_rational llll_sum_abs_of_rat_llll(t_llll *in_llll);


/**	Find the overall sum of the absolute values of the elements of an llll containing rationals (or longs), ignoring
	the sublists starting with a "g" symbol.
	@ingroup			llll_utilities
	@param	in_llll		The llll
	@return				The sum of all the absolute values of the elements in the llll, ignoring sublists starting with a "g" symbol
 */
t_rational llll_sum_abs_of_rat_llll_up_to_g_list(t_llll *in_llll);


/**	Find the overall sum of the absolute values of the elements of an llll containing doubles.
	@ingroup			llll_utilities
	@param	in_llll		The llll
	@return				The sum of all the absolute values of the elements in the llll
 */
double llll_sum_abs_of_double_llll(t_llll *in_llll);


/**	Find the minimum of a plain llll (depth = 1) containing rationals
	@ingroup		llll_utilities
	@param	in_llll	The llll
	@return			The value of the minimum 
 */
t_rational llll_min_of_plain_rat_llll(t_llll *in_llll);


/**	Tell how many zeros there are in a plain llll (depth = 1) containing longs
	@ingroup		llll_utilities
	@param	in_llll	The llll
	@return			The number of zeros in the llll
 */
long llll_num_zeros_in_plain_long_llll(t_llll *in_llll);


/**	Find the index of the first non-zero entry in a plain llll (depth = 1) containing longs
	@ingroup		llll_utilities
	@param	in_llll	The llll
	@return			The 1-based index of first non-zero element in the lllll
 */
long llll_first_nonzero_entry_index_in_plain_long_llll(t_llll *in_llll);


/**	Perform discrete integration on a llll containing rationals (or longs). This works on all levels, which means that, for instance,
	the list [1/2 (1/4 1/8 (-1/8))], with <start_rational> = 3/2, is mapped on [3/2 (2 9/4 (19/8))] with a <total_sum> of 9/8. 
	@ingroup				llll_utilities
	@param	in_llll			The llll
	@param	start_rational	The rational starting point for the integration
	@param	total_sum		Pointer to a rational which will be filled with the total sum of the elements in the llll. Levae NULL if you don't need it.
	@return					The llll containing the integrated values
	@see					llll_dx2x_of_plain_rat_llll()
 */
t_llll* llll_dx2x_of_rat_llll(t_llll *in_llll, t_rational start_rational, t_rational *total_sum);


/**	Perform discrete integration on a plain llll containing rationals (or longs).
	It is faster than llll_dx2x_of_rat_llll(), and you should consider using this function for plain lllls.
	@ingroup				llll_utilities
	@param	in_llll			The llll
	@param	start_rational	The rational starting point for the integration
	@return					The llll containing the integrated values
	@see					llll_dx2x_of_rat_llll()
	@see					llll_dx2x_of_plain_double_llll()
 */
t_llll* llll_dx2x_of_plain_rat_llll(t_llll *in_llll, t_rational start_rational);


/**	Perform discrete integration on a plain llll containing doubles (or longs).
	@ingroup				llll_utilities
	@param	in_llll			The llll
	@param	start_rational	The starting point for the integration
	@return					The llll containing the integrated values
	@see					llll_dx2x_of_plain_rat_llll()
	@see					llll_x2dx_of_plain_double_llll()
 */
t_llll* llll_dx2x_of_plain_double_llll(t_llll *in_llll, double start);


/**	Perform discrete derivation on a plain llll containing doubles (or longs).
	@ingroup				llll_utilities
	@param	in_llll			The llll
	@return					The llll containing the differences
	@see					llll_dx2x_of_plain_double_llll()
 */
t_llll* llll_x2dx_of_plain_double_llll(t_llll *in_llll);


/**	Find average of a a plain llll containing doubles (or longs).
	@ingroup				llll_utilities
	@param	in_llll			The llll
	@return					The average of the elements in the llll
 */
double get_average_of_plain_double_llll(t_llll *ll);


/**	Find standard deviation in a plain llll containing doubles (or longs).
	@ingroup				llll_utilities
	@param	in_llll			The llll
	@param	average			Pointer which will be filled with the average of the llll values (if needed, leave NULL if unwanted)
	@return					The standard deviation of the elements in the llll
 */
double get_stdev_of_plain_double_llll(t_llll *ll, double *average);


/**	Apply a mean filter on a plain llll
	@ingroup					llll_utilities
	@param	ll					The llll
	@param	window_in_samples	The size of the averaging window (in number of elements) – should be odd, if it is not, it is made odd
	@return						A new llll, the filtered one
 */
t_llll *llll_meanfilter(t_llll *ll, long window_in_samples);


/**	Apply a median filter on a plain llll
	@ingroup					llll_utilities
	@param	ll					The llll
	@param	window_in_samples	The size of the window (in number of elements) – should be odd, if it is not, it is made odd
	@return						A new llll, the filtered one
 */
t_llll *llll_medianfilter(t_llll *ll, long window_in_samples);


/**	Quick debug function to show the content of an llll in an array of chars.
	@ingroup			llll_utilities
	@param	in_llll		The llll
	@param	char_array	Pointer to the first elements in the array of chars
	@param	max_chars	Maximum number of chars to be shown (typically the size of <char_array>.
	@remark				VERY IMPORTANT: THIS FUNCTION IS DEPRECATED. Please use llll_to_text_buf() instead 
 */
void llll_to_char_array(t_llll *in_llll, char* char_array, long max_chars);


/**	Get the number of rationals in an llll
	@ingroup			llll_utilities
	@param	inllll		The llll
	@return				The number of rationals in the llll.
 */
long get_num_rationals_in_llll(t_llll *in_llll);


/**	Find the number of lllls at the base level of an llll 
	@ingroup			llll_utilities
	@param	inllll		The llll
	@return				The number of elements at the base level of llll which are in turn lllls
 */
long get_num_llll_in_llll_first_level(t_llll *inllll);


/**	Tell if a hatom is in the root level of an llll 
	@ingroup			llll_utilities
	@param hatom		The hatom
	@param	ll			The llll
	@return				1 if hatom is contained in root level of ll, 0 otherwise
 */
char is_hatom_in_llll_root_level(t_hatom *hatom, t_llll *ll);


/**	Find, at the base level of an llll, the number of lllls NOT having a symbol as first element.
	This is useful since oftern lists like (<symbol> ...) specify attributes or properties for notation elements or other stuff.
	@ingroup			llll_utilities
	@param	inllll		The llll
	@return				The number of elements at the base level of llll which are in turn lllls, but do NOT have a symbol as first element
	@see				get_num_llll_no_first_attribute_sym_in_llll()
 */
long get_num_llll_no_first_sym_in_llll(t_llll *inllll);


/**	Find, at the base level of an llll, the first element, after a given element, which is an llll but which does NOT have a symbol as first element.
	@ingroup			llll_utilities
	@param	inllll		The element
	@return				The first element, after #elem, which is an llll but which does NOT have a symbol as first element
	@see				get_num_llll_no_first_sym_in_llll()
 */
t_llllelem *get_next_llll_no_first_sym_elem(t_llllelem *elem);



/**	Get a llll containing a single long number repeated a certain number of times.
	@ingroup				llll_utilities
	@param	number			The number to repeat
	@param	howmanytimes	The number of times <number> needs to be repeated
	@return					A llll containing [number number number...] <howmanytimes> times.
	@see					repeat_long_for_llllelem_len(), repeat_rat_until_tot_duration(), repeat_hatom()
 */
t_llll *repeat_long(long number, long howmanytimes);


/**	Get a llll containing a single hatom cloned and repeated a certain number of times.
	@ingroup				llll_utilities
	@param	h				The hatom to repeat
	@param	howmanytimes	The number of times <h> needs to be repeated
	@return					A llll containing [<h> <h> <h>...] <howmanytimes> times.
	@see					repeat_long()
 */
t_llll *repeat_hatom(t_hatom *h, long howmanytimes);


/**	Get a llll containing a single long number repeated n times, where n is either 1, if an input element is NOT an llll, or the size
	of the llll contained in the input element.
	@ingroup		llll_utilities
	@param	number	The number to repeat
	@param	elem	The element deciding the number of repetitions. If its hatom is an H_LLLL, the number of repetitions will be the size of the llll,
					otherwise it will be 1
	@return			A llll containing [number number number...], repeated as explained above.
 */
t_llll *repeat_long_for_llllelem_len(long number, t_llllelem *elem);


/**	Get a llll containing repetitions of a rational number, until a certain global sum is achieved.
	@ingroup				llll_utilities
	@param	number			The rational number to repeat
	@param	tot_duration	The global rational duration to achieve with the repetition of <number>
	@return					A llll containing [number number number...], repeated until the sum of the elements is AT LEAST <tot_duration>.
	@remark					The global sum of the output list might exceed the requested <total_duration>, if such duration cannot be divided by <number> 
 */
t_llll *repeat_rat_until_tot_duration(t_rational number, t_rational tot_duration);


/**	Force a plain llll containing rationals (or longs) to have a given global sum of absolute values. This is done by either trimming elements (if the sum was bigger than 
	the one requested), or by adding a necessary pad to reach the duration at the end. It works inplace, operating on the introduced llll.
	@ingroup				llll_utilities
	@param	list			The llll
	@param	tot_duration	The global rational duration that the llll must have
 */
void force_plain_rat_llll_to_have_a_given_abs_sum(t_llll *list, t_rational tot_duration);


/**	Convert a symbol into an llll containing only the symbol
	@ingroup		llll_utilities
	@param	sym		The symbol
	@return			An llll just containing [<sym>]
 */
t_llll *symbol2llll(t_symbol *sym);


/**	Retrieve the nth symbol in a plain llll (depth = 1) containing symbols 
	@ingroup		llll_utilities
	@param	in_llll	The llll
	@param	index	The 1-based index of the symbol to retrieve
	@return			The symbol situated at the <index> position in the llll, or gensym("") if none.
 */
t_symbol *nth_sym_of_a_plain_sym_llll(t_llll *in_llll, long index);


/**	Tell if a llll has at least one symbol among the elements in its base level 
	@ingroup		llll_utilities
	@param	inllll	The llll
	@return			1 if there is at least one symbol among the base-level-elements of <inllll>, 0 otherwise
 */
char has_llll_symbols_in_first_level(t_llll *inllll);


/**	Tell if a long is contained in an element at the base level of a llll.
	@ingroup		llll_utilities
	@param	inllll	The llll
	@param	num		The number to find
	@return			1 if the number is found, 0 otherwise
 */
char is_long_in_llll_first_level(t_llll *inllll, long num);


/**	Tell if a double is contained in an element at the base level of a llll (precisely!!! there's no threshold).
	@ingroup		llll_utilities
	@param	inllll	The llll
	@param	num		The number to find
	@return			1 if the number is found, 0 otherwise
 */
char is_double_in_llll_first_level(t_llll *inllll, double num);


/**	Tell how many matches of a given double are contained at the base level of an llll (precisely!!! there's no threshold).
	@ingroup		llll_utilities
	@param	inllll	The llll
	@param	num		The number to find
	@return			The number of occurrences of #num.
 */
long how_many_doubles_in_llll_first_level(t_llll *inllll, double num);


/**	Tell if a double is contained in an element at the base level of a llll, within a given tolerance threshold
	@ingroup			llll_utilities
	@param	list		The llll
	@param	num			The number to find
	@param	tolerance	The tolerance threshold: all numbers distant from <num> less than <tolerance> are accepted.
	@return				1 if the number is found, 0 otherwise
 */
char is_double_in_llll_first_level_with_tolerance(t_llll *list, double num, double tolerance);


/**	Tell if a symbol is contained in an element at the base level of a llll.
	@ingroup		llll_utilities
	@param	inllll	The llll
	@param	num		The symbol to find
	@return			1 if the symbol is found, 0 otherwise
 */
char is_symbol_in_llll_first_level(t_llll *inllll, t_symbol *sym);


/**	Tell if the pointer to some object is contained in an element at the base level of a llll.
	@ingroup		llll_utilities
	@param	inllll	The llll
	@param	obj		The pointer to find
	@return			1 if the pointer is found, 0 otherwise
 */
char is_obj_in_llll_first_level(t_llll *inllll, void *obj);


/**	Perform a mergesort of an llll, such as llll_mergesort(), but fills the pointer to the llll with the address of the newly sorted llll.
	(Also frees the memory of the old llll.) 
	@remark				This funciton is usually deprecated, see llll_inplacesort() instead
	@ingroup			llll_utilities
	@param	llll_in		Pointer to the llll to be sorted. It'll then be filled with the result llll, so that the user might continue to use llll_in, and it'll be sorted.
	@param	cmpfn		The comparison function (see llll_mergesort())
	@see				llll_mergesort()
	@see				llll_inplacesort()
 */
void llll_mergesort_inplace(t_llll **llll_in, long (*cmpfn)(void *data, t_llllelem *a, t_llllelem *b), void *data);


/**	Compute the euclidean distance between two plain lllls containing rational (or long) values, i.e. sqrt(sum((el1-el2)^2)) as el1 and el2 range in parallel on the
	two input lllls
	@ingroup		llll_utilities
	@param	llll1	The first llll
	@param	llll2	The second llll
	@return			The euclidean distance between <llll1> and <llll2> 
 */
double llll_euclidean_distance_of_plain_rat_lllls(t_llll *llll1, t_llll *llll2);


/**	Chains two lllls by cloning the elements of the second one and appending them to the first one. The user is free to use the second list afterwards, if needed. 
	@ingroup		llll_utilities
	@param	where	The first llll (the one that will receive the cloned elements)
	@param	what	The second llll (the one whose elements will be cloned and appended to <where>)
 */
void llll_chain_clone(t_llll *where, t_llll *what);


/**	Chains two lllls by cloning SOME elements of the second one and appending them to the first one. The elements of the second llll that need to be cloned and 
	appended are specified by the <which_indices> input llll
	@ingroup				llll_utilities
	@param	where			The first llll (the one that will receive the cloned elements)
	@param	what			The second llll (the one whose elements will be cloned and appended to <where>)
	@param	which_indices	A plain llll containing the 1-based indices of the elements of <what> that need to be cloned and appended to <where>.
							You can leave this NULL to clone and append all elements.
 */
void llll_chain_clone_some_indices(t_llll *where, t_llll *what, t_llll *which_indices);


/**	Get a llll simply containing an empty llll, id est [()], or [nil]
	@ingroup	llll_utilities
	@return		A llll containing an empty llll
	@remark		Notice that this is NOT an empty list.
 */
t_llll *get_nilnil();


/**	Build a llll containing a given symbol and a given long number 
	@ingroup	llll_utilities
	@param	sym	The symbol
	@param	val	The long number
	@return		A llll with (#sym #val).
 */
t_llll *build_sym_long_llll(t_symbol *sym, long val);


/**	Get, as a plain llll containing longs, the arithmetic series from a given number, to a given number, by a given step.
	@ingroup		llll_utilities
	@param	from	The starting integer
	@param	to		The ending integer
	@param	step	The step
	@return			A llll containing the desired arithmetic series.
 */
t_llll *get_arithmser(long from, long to, long step);


/**	Get the first llllelem (by iterating on all levels from the beginning, as [bach.iter] does) which is NOT of type H_LLLL.
	@ingroup		llll_utilities
	@param	llll	The llll
	@return			The first llllelem in llll which is not of type H_LLLL, or NULL if none.
 */
t_llllelem *get_first_non_llll_elem(t_llll *llll);


/**	Get the last llllelem (by iterating on all levels from the end, the reverse of what as [bach.iter] does) which is NOT of type H_LLLL.
	@ingroup		llll_utilities
	@param	llll	The llll
	@return			The last llllelem in llll which is not of type H_LLLL, or NULL if none.
 */
t_llllelem *get_last_non_llll_elem(t_llll *llll);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/**	Get the non-llll-llllelem immediately before a given llllelem.
	@ingroup		llll_utilities
	@param	elem	The given llllelem
	@return			The llllelem at the left of #elem, which is nearest to elem but at the same time is NOT an llll (or NULL if none).
 */
t_llllelem *llllelem_get_prev_non_llll_elem(t_llllelem *elem);
#endif


/**	Get the depth of a llllelem. For instance, in the llll [1 (2 3 (4 (5 6)))] the element 4 is at depth 3 (third level of depth).
	@ingroup		llll_utilities
	@param	elem	The llllelem
	@return			The depth at which the llllelem is found.
 */
long llllelem_get_depth(t_llllelem *elem);


/**	Get the "first ancestor" of a llllelem, i.e. the so called root llll: the llll containing <elem> either as son or grandson or grandgrandson (etc.), but
	which is NOT contained in any other llll (i.e. its <owner> field is NULL).
	@ingroup		llll_utilities
	@param	elem	The llllelem
	@return			The root llll containing the element <elem>
 */
t_llll *llllelem_root(const t_llllelem *elem);


/**	Post an llll in the console (only in Development mode)
	@ingroup		llll_utilities
	@param	lll     The llll
 */
void llll_cpost(t_llll *ll);


/**	Find the first common relative of two llllelems, i.e. the first llll which contains them as sons or grandsons or grandgrandsons, etc.
	@ingroup				llll_utilities
	@param	elem1			The first llllelem
	@param	elem2			The second llllelem
	@param	depth_elem1		Pointer to a long which will be filled with the depth of <elem1> (with respect to the root llll, and NOT of the possibly found common relative)
	@param	depth_elem2		Pointer to a long which will be filled with the depth of <elem2> (with respect to the root llll, and NOT of the possibly found common relative)
	@param	depth_elem2		Pointer to a long which, if the common relative has been found, will be filled with its depth with respect to the root llll.
	@return					The llll containing both <elem1> and <elem2> either as sons or grandsons or grandgrandsons, etc. NULL if it could not be found.
 */
t_llll *llllelem_find_first_common_relative(t_llllelem *elem1, t_llllelem *elem2, long *depth_elem1, long *depth_elem2, long *depth_relative);


/**	Create a bracket-abyss after an element (i.e. creates a sequence of closed brackets and then the same number of open brackets), 
	dipping down until a certain <abyss_base_depth>. For instance, with <abyss_base_depth> = 0,
	if in the llll [a (b (c d e f))] we choose the <elem> d, this function will split the llll as [a (b (c d)) ((e f))]
	and the #t_llllelem corresponding to (b (c d)) is returned. 
	@ingroup					llll_utilities
	@param	in_llll				The llll
	@param	elem				The llllelem after which you want to create the abyss
	@param	abyss_base_depth	The depth to which you want to dip; more precisely the depth that the element containing the last-created-closed-bracket needs to have;
								Set this to 0 in order to build enough )))... to reach the base llll level; increase it if you need to reach higher depth levels.
	@return						The llllelem containing the left side of the abyss (i.e. the element containing the last-created-closed-bracket).
								If <elem> is already below or at level <abyss_base_depth>, <elem> is returned.
	@remark						When an llll is split, if it has an l_thing field, it is considered to be a #t_rhythm_level_properties structure
								used to handle rhythmic trees, and it is cloned.
 */
t_llllelem *llllelem_create_abyss(t_llllelem *elem, long abyss_base_depth); 


/**	Find the greater common divisor of all elements of a llll containing rationals. See rat_gcd() to know how the gcd of two rationals is defined.
	@ingroup			llll_utilities
	@param	rationals	The llll
	@return				The greatest common divisor of all rationals in the llll
	@see				llll_gcd_of_plain_rat_llll()
	@see				rat_gcd()
 */
t_rational llll_gcd_of_rat_llll(t_llll *rationals);


/**	Find the greater common divisor of all rational elements of the first level of an llll. If an element is an H_LLLL, its total rational sum is considered.
	@ingroup			llll_utilities
	@param	rationals	The llll
	@return				The greatest common divisor of all elements at first levels of the llll
	@see				llll_gcd_of_plain_rat_llll()
	@see				rat_gcd()
	@see				llll_gcd_of_rat_llll()
 */
t_rational llll_gcd_on_first_level(t_llll *rationals);


/**	Find the greater common divisor of all elements of a plain llll (depth = 1) containing rationals.
	This is faster than llll_gcd_of_rat_llll(), and you might want to use this function for plain lists
	@ingroup			llll_utilities
	@param	rationals	The llll
	@return				The greatest common divisor of all rationals in the llll
	@see				llll_gcd_of_rat_llll()
	@see				rat_gcd()
 */
t_rational llll_gcd_of_plain_rat_llll(t_llll *llll_of_rationals);


/**	Cloning function (llll_clone_fn) to be used when you want to ignore the <l_thing> fields while cloning or performing analogous operations (reshaping...) 
	@ingroup	llll_utilities
 */
void* ignore_l_thing_fn(void *x);


/**	Conveniene wrapper that returns the last but one level depth of an llll, but trimmed to the root level. More specifically, 
	it always returns (of course!) -2, EXCEPT IF the llll has depth 1, in which case, it simply returns 0.
	@ingroup		llll_utilities
	@param	llll	The llll
	@return			The long index of the last but one level of depth of llll
	@remark			This function is precious while iterating on lists, or using for instance llll_funall. 
					For instance, if you want to call llll_funall all the elements up to the last but one level, you might want to use

					@code
					llll_funall(llll, your_function_fn, NULL, 1, one_but_last_level(llll), 0);
					@endcode

					and NOT

					@code
					llll_funall(llll, your_function_fn, NULL, 1, -2, 0);
					@endcode
				
					since the latter will not iterate anything on plain lists.
	@see			two_but_last_level()
 */
long one_but_last_level(t_llll *llll);


/**	Conveniene wrapper that returns the two-but-last level depth of an llll, but trimmed to the root level. More specifically, 
	it always returns (of course!) -3, EXCEPT IF the llll has depth 2, in which case it returns -2, or IF the llll has depth 1, in which 
	case it simply returns 0.
	@ingroup		llll_utilities
	@param	llll	The llll
	@return			The long index of the two-but-last-level of depth of llll
	@see			one_but_last_level()
*/
long two_but_last_level(t_llll *llll);


/**	Free with bach_freeptr() all the information contained in the <l_thing> fields of an llll.
	@ingroup		llll_utilities
	@param	llll	The llll
*/
void llll_free_all_l_things(t_llll *llll);


/**	Comparison function for sorting lllls containing sub-lllls by the first element of such sublllls.
	For instance, use it with llll_mergesort() as #sort_fn, in order to sort [(3 a) (1 b) (2 c)] to [(1 b) (2 c) (3 a)]
	@ingroup		llll_utilities
*/
long llll_sort_by_first(void *dummy, t_llllelem *a, t_llllelem *b);

/**	Comparison function for sorting lllls containing sub-lllls by the second element of such sublllls.
	For instance, use it with llll_mergesort() as #sort_fn, in order to sort [(a 3) (b 1) (c 2)] to [(b 1) (c 2) (a 3)]
	@ingroup		llll_utilities
 */
long llll_sort_by_second(void *dummy, t_llllelem *a, t_llllelem *b);

/**	Comparison function for sorting lllls containing sub-lllls by the last element of such sublllls.
	For instance, use it with llll_mergesort() as #sort_fn, in order to sort [(a x 3) (b s 1) (c w 2)] to [(b s 1) (c w 2) (a x 3)]
	@ingroup		llll_utilities
*/
long llll_sort_by_last(void *dummy, t_llllelem *a, t_llllelem *b);


/**	Find the long value of a key used as argument for a message. 
	Some messages sent to notation objects may have optional arguments; for instance: [exportmidi midi.foo (format 0)].
	The "midi.foo" argument is a standard argument, but the "(format 2)" argument is a standardized method to specify behaviour for the export system.
	This also works with messages such as importmidi, etc: [importmidi (chordthresh 10.5) (track2voice 0)].
	This function takes the whole input llll, the key to be searched for (e.g. track2voice), and returns the integer value it has (in the previous case, 0).
	@ingroup		llll_utilities
	@param	llll	The llll containing all message and attributes
	@param	key		The key to be searched for
	@param	default_value	The default value of the argument if the key was not found
	@param  then_destroy_elem	If non-zero, the found llll containing the key is then destroyed
    @remark         Deprecated: use find_long_arg_attr_key()
 	@return			The value the key has in the arguments of the message.
*/
long find_long_arg_attr_key(t_llll *ll, t_symbol *key, long default_value, char then_destroy_elem);


/**	DEPRECATED! Find the double precision value of a key used as argument for a message.
	See #find_long_arg_attr_key() for more information about arguments.
 	@ingroup		llll_utilities
	@param	llll	The llll containing all message and attributes
	@param	key		The key to be searched for
	@param	default_value	The default value of the argument if the key was not found
	@param  then_destroy_elem	If non-zero, the found llll containing the key is then destroyed
    @remark         Deprecated: use find_double_arg_attr_key()
	@return			The value the key has in the arguments of the message.
*/
double find_double_argument_key(t_llll *ll, t_symbol *key, double default_value, char then_destroy_elem);

long find_long_arg_attr_key(t_llll *ll, t_symbol *key, long default_value, char then_destroy_elem);
double find_double_arg_attr_key(t_llll *ll, t_symbol *key, long default_value, char then_destroy_elem);


/**	Translate a GIMME signature into a single symbol.
	@ingroup		miscellanea
	@param	ac		The number of atoms in the atom array
	@param	av		The atom array
	@return			A symbol representing the whole atom array
*/
t_symbol *ac_av_to_single_symbol(long ac, t_atom *av);


/**	Tell if two atoms have the same content
	@ingroup		miscellanea
	@param	a1		The first atom
	@param	a2		The second atom
	@return			1 if atoms have the same content, 0 otherwise
*/
char are_atoms_equal(t_atom *a1, t_atom *a2);


/**	Tell if two arrays of atoms have the same content
	@ingroup		miscellanea
	@param	a1		The first array
	@param	size1	The size of the first array
	@param	a2		The second array
	@param	size2	The size of the second array
	@return			1 if atom arrays have the same content, 0 otherwise
*/
char are_atomarrays_equal(t_atom *a1, long size1, t_atom *a2, long size2);


/**	Tell if an atom is contained in an atomarray
	@ingroup			miscellanea
	@param	atom		The atom
	@param	atomarray	The atomarray
	@param	atomarray_size	The size of the atomarray
	@return				1 if atom is found inside the atomarray, 0 otherwise
*/
char is_atom_in_atomarray(t_atom *atom, t_atom *atomarray, long atomarray_size);


/**	Append an atom to an llll. More specifically, calls the proper llll_appending function depending on the atom type.
	@ingroup		llll_utilities
	@param	where	The llll where to append
	@param	what	Pointer to the atom whose content must be appended
	@param	flags	Flags for appending, just like #llll_appendlong() or similars
	@param	adopter	Adopter for appending, just like #llll_appendlong() or similars
	@return			The appended llllelem, or NULL if none
*/
t_llllelem *llll_appendatom(t_llll *where, t_atom *what, long flags, t_llll *adopter);


/**	Find the llllelem, up to a depth of 2 (2 levels of depth), which approximates best a given number
	@ingroup		llll_utilities
	@param	ll		The llll
	@param	num		The number
	@return			The llllelem which approximates at best the number, or NULL if none.
*/
t_llllelem *get_nearest_llllelem_to_double(t_llll *ll, double num);


/**	Get the median of an llll (the function fills the hatom given as argument)
	@ingroup		llll_utilities
	@param	ll		The llll
	@param	h		The hatom to be filled with the median of the llll
*/
void llll_median(t_llll *ll, t_hatom *h);


/**	Get the period of an llll
	@ingroup		llll_utilities
	@param	ll		The llll
	@return			The sub-llll being the period of the original llll.
	@remark			For instance, if ll = (0 2 4 0 2 4 0 2 4), one will have returned (0 2 4).
					If one needs the numeric period, it just suffice to take the length of the output llll.
*/
t_llll *llll_get_period(t_llll *ll);


/**	Tell if an llll is contained inside another one (ignoring the type of the elements)
	@ingroup		llll_utilities
	@param	container	The supposed container llll
	@param	contained	The supposedly contained llll
	@return			1 if all elements of #contained are present inside #container (ignoring element types), 0 otherwise 
*/
char llll_is_subset_of(t_llll *container, t_llll *contained);


/**	Destroy all the zero-elements from a plain llll containing rationals.
	@ingroup	llll_utilities
	@param	ll	The llll
 */
void llll_filter_zeros(t_llll *ll);


/**	Destroy all the zero-elements and negative elements from a plain llll containing rationals.
	@ingroup	llll_utilities
	@param	ll	The llll
 */
void llll_filter_zeros_and_negatives(t_llll *ll);


/**	Force a given matrix to have a specified size, by padding or trimming it.
	@ingroup linear_algebra
	@param	matrix		The matrix
	@param	num_rows	The number of rows it must have
	@param	num_cols	The number of columns it must have
	@param	pad			The padding element, leave null to append 0 (as long).
 */							
void llll_force_matrix_size(t_llll *matrix, long num_rows, long num_cols, t_hatom *pad);


// to be documented
t_llll *pt_to_llll(t_pt pt, char add_zero_slope);
t_llll *rect_to_llll(t_rect rect);
t_rect llll_to_rect(t_llll *ll);
t_pt llll_to_pt(t_llll *ll);
t_llll *llll_approximate_breakpoint_function(t_llll *in_ll, long num_points_to_keep, double thresh, long p, char algorithm, char slope_handling, char markmode = 0);
t_llll *double_triplet_to_llll(double d1, double d2, double d3);
t_llll *double_couple_to_llll(double d1, double d2);
t_llll *long_couple_to_llll(long c1, long c2);
t_llll *obj_couple_to_llll(void *v1, void *v2);
t_llll *double_quadruplet_to_llll(double d1, double d2, double d3, double d4);
t_llll *double_triplet_and_long_to_llll(double d1, double d2, double d3, long d4);
t_llll *symbol_and_double_to_llll(t_symbol *sym, double d);
t_llll *symbol_and_symbol_to_llll(t_symbol *sym1, t_symbol *sym2);
t_llll *symbol_and_long_to_llll(t_symbol *sym, long n);
t_llll *integrate_bpf(t_llll *incoming, double domain_start, double domain_end, long num_samples, double starting_value, char auto_domain);

t_llll *integrate_bpf_with_explicit_sampling(t_llll *incoming, t_llll *x_values, double starting_value);
t_llll *derive_bpf(t_llll *incoming, double domain_start, double domain_end, long num_samples,
				   char auto_domain, char if_possible_dont_sample, char discrete_derivative, char discrete_derivative_pad);
t_llll *derive_bpf_with_explicit_sampling(t_llll *incoming, t_llll *x_values, char discrete_derivative, char discrete_derivative_pad);
void llll_develop_ranges_inplace(t_llll **ll);
void llll_develop_ranges_and_parse_negative_indices_inplace(t_llll **ll, long maxnum, char convert_from_1based_to_0based);
long llllelem_retrieve_index(t_llll *ll, t_llllelem *elem);

t_symbol *hatom_to_symbol(t_hatom *h, long numdecimals = 3);
t_symbol *double_to_symbol_fixed(double d, long numdecimals = 3);
char llllelem_exists_and_is_sym(t_llllelem *elem, t_symbol *sym);

// DESTRUCTIVE: pads the incoming <ll> depending on the <mode> (= 0: repeat last element,
// = 1: loop, = 2: mirror back'n'forth loop) with <num_loopelems> elements taken from the
// <reservoir>, according to the <align> attribute (0 = align left, 1 = align center, 2 = align right).
// <rounding_direction> is ONLY used for centering align, when non-integer sized elements should be put at left or right
// 0 = round to left (= put one more element at left), 1 = round to right (= put one more element at right)
void llll_pad(t_llll *ll, long output_length, char align, e_pad_mode mode, long num_loop_elems, t_llll *reservoir, char allow_trimming, char rounding_direction);

void llll_poset(t_llll *ll, poset_fn cmpfn, void *data, t_llll **out_edges, t_llll **out_adjacency, t_llll **minima, t_llll **maxima);

t_llllelem *llll_appendelem_clone_preserve_lthing(t_llll *where, t_llllelem *elem, long flags, t_llll *adopter);


// THESE ONLY WORK FOR LLLL_UI OBJECTS!!!!!!!!!!
void send_sym_lllls_notification(t_object *x, long outlet_num, t_symbol *router, long count,...);
void send_sym_lllls_notification_and_free(t_object *x, long outlet_num, t_symbol *router, long count,...); // also frees the lllls given as argument
void send_sym_doubles_notification(t_object *x, long outlet_num, t_symbol *router, long count, ...);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _LLLL_COMMONS_EXT_H_