/*
 *  llll_settheory.h
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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
	@file	llll_settheory.h
	@brief	Common musical set theory tools.
*/

#ifndef _LLLL_SETTHEORY_H_
#define _LLLL_SETTHEORY_H_

#include "foundation/llll_files.h"
#include "notation/notation.h"
#include "math/llll_math.h"
#include "graphics/llll_modifiers.h"
#include "foundation/llll_commons_ext.h"

#define CONST_MAX_MODULO 1000				///< Maximum possible modulo



/** Computation modes for prime forms
	@ingroup	musical_set_theory
	@remark		This is crucial to decide what is a prime form. See pcset_get_primeform() to have some worked examples.
 */
typedef enum _primeform_modes {
	k_PRIMEFORM_MODE_LEXICOGRAPHIC = 0,		///< Prime form is the "smallest one" respect to lexicographical ordering 
											///  (we compare each pitch class one by one, left-to-right, and when two of them differ, 
											///  the "smallest" pcset is the one containing the smallest one).
											///  For instance, (0 1 8) < (0 2 5). 
	k_PRIMEFORM_MODE_COMPACTNESS_FIRST		///< Prime form is first of all the "most compact", and then (in case of a tie) 
											///  the "smallest one" lexicographically. For instance (0 2 5) < (0 1 8).
} e_primeform_modes;


/** Groups of transformations over the ring Z/nZ, and thus over pitch classes or pcsets. 
	@ingroup	musical_set_theory
 */
typedef enum _primeform_groups {
	k_GROUP_T = 0,		///< Groups of transpositions <T>
	k_GROUP_TI = 1,		///< Groups of transpositions and inversions <T, I>
	k_GROUP_AFF = 2,	///< Affine group Aff_n over Z/nZ of transpositions, inversion and multiplication (for p prime with n)
	k_GROUP_ID = 3,		///< Trivial group containing the identity only
	k_GROUP_CUSTOM = 4	///< (UNSUPPORTED) Custom group
} e_settheory_groups;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif



/** A diatonic interval in an equal temperament 
 @ingroup musical_set_theory
 */
typedef struct _tonnetz_diatonic_interval
{
	long		diatonic_steps;		///< Interval from the a fixed point in diatonic steps (if the point is middle C, e.g., C# is 0, D is 1, Eb or E or E# is 2, and so on)
	long		chromatic_steps;	///< Number of chromatic steps (e.g. semitones if modulo = 12, quartertones if modulo = 24, and so on) 
	///  of the interval from the fixed point to the note
	
	t_rational	frequency_ratio;	///< Frequency ratio for the diatonic interval (customizable)
	long		user_defined_ratio;	///< Flag telling if the ratio has been inserted by the user
} t_tonnetz_diatonic_interval;




/** Obtain the complement of a pcset
	@ingroup	musical_set_theory
	@param		pcset		The pcset
	@param		modulo		The modulo
	@return		An llll containing the complement of the pcset (i.e. all chromatic pitches not appearing in the original pcset) 
 */
t_llll *pcset_complement(t_llll *pcset, long modulo);


/** In-place inversion of a pcset (or a collection of pcsets)
	@ingroup	musical_set_theory
	@param		pcset		The pcset which will be changed (or any structured collection of pcsets, which will be individually changed)
	@param		modulo		The modulo
	@param		also_sort	If this is non-zero, the pcset (or each pcset inside the collection) will be sorted.
 */
void pcset_invert_inplace(t_llll **pcset, long modulo, char also_sort);


/** In-place transposition of a pcset (or a collection of pcsets)
	@ingroup	musical_set_theory
	@param		pcset		The pcset which will be changed (or any structured collection of pcsets, which will be individually changed)
	@param		transp_step	Number of step of transposition
	@param		modulo		The modulo
	@param		also_sort	If this is non-zero, the pcset (or each pcset inside the collection) will be sorted.
 */
void pcset_transpose_inplace(t_llll **pcset, long transp_step, long modulo, char also_sort);


/** In-place multiplication of a pcset (or a collection of pcsets)
	@ingroup	musical_set_theory
	@param		pcset		The pcset which will be changed (or any structured collection of pcsets, which will be individually changed)
	@param		factor		Factor of multiplication of any pitch class
	@param		modulo		The modulo
	@param		also_sort	If this is non-zero, the pcset (or each pcset inside the collection) will be sorted.
 */
void pcset_multiply_in_place(t_llll **pcset, long factor, long modulo, char also_sort);


/** In-place modulo of a pcset (or a collection of pcsets), useful to obtain standard representation of pcsets, where each pitch class 
	ranges from 0 to modulo - 1.
	@ingroup	musical_set_theory
	@remark		This is affine to the positive_mod() function, and NOT to the fmod() function: each element is always changed to a nonnegative element.
	@param		pcset		The pcset which will be changed (or any structured collection of pcsets, which will be individually changed)
	@param		modulo		The modulo
	@param		also_sort	If this is non-zero, the pcset (or each pcset inside the collection) will be sorted.
 */
void pcset_modulo_inplace(t_llll **pcset, long modulo, char also_sort);


/** Obtain the extension (in steps) of a pcset.
	@ingroup	musical_set_theory
	@remark		For instance, set (0 1 4 8 10) has extension 10-0 = 10.
	@param		pcset		The pcset
	@return		The extension of the pcset, i.e. the difference between the maximum and the minimum pitch class of the pcset.
 */
long pcset_get_extension(t_llll *pcset);


/** Get the interval structure of a pcset.
	@ingroup	musical_set_theory
	@param		pcset		The pcset
	@param		modulo		The modulo
	@return		An llll containing the interval structure of the set, i.e. a circular list of differences between the pitch classes
	@remark		For instance, for pcset = (2 4 9 10) and modulo = 12, the differences are: 4-2= 2, 9-4 = 5, 10-9 = 1, 
				and then the last circular one 2-10 = -8 = 4, thus the returned interval structure will be (2 5 1 4).
 */
t_llll* pcset_istruct(t_llll *pcset, long modulo);


/** Get the prime form of a pcset, i.e. a specific representative of a class of pcsets. This class of pcsets is the class of all the transformations
	of the original pcset by any element of a given #group. Typically, this group can be the group of transpositions (= all transposition are considered
	"the same" and the prime form will be the 'simplest one' according to a given property) or transposition/inversions (= all transpositions and inversions
	of the set are considered "the same" and the prime form will be the 'simplest one' according to a given property). The "given property" is defined by the
	#mode: which will tell, for instance, if we consider the "simplest representative" the one coming first in lexicographic order (#k_PRIMEFORM_MODE_LEXICOGRAPHIC, 
	i.e. whose numbers are the smallest, left to right, as letters in a dictionary, so (1 2 4) comes before (1 5 2) but after (1 2 1)) or we choose first the 
	most compact sets (the one with least set extension) and then we use the lexicographic order (#k_PRIMEFORM_MODE_COMPACTNESS_FIRST).
	@ingroup	musical_set_theory
	@param		pcset		The pcset
	@param		modulo		The modulo
	@param		mode		One of the #e_primeform_modes, determining the way the prime form is chosen.
	@param		group		One of the #e_settheory_groups, determining the group of transformations up to which the prime form has to be taken 
	@param		multipl_comp	Pointer which will be filled with the multiplication component which needs to be applied to the original pcset in order
								to obtain the prime form pcset (in combination with the #transl_comp, which needs to be applied afterwards).
								If no multiplication need to be done, this will be filled with 1. Inversion correspond to multiplication by modulo - 1. 
								Leave NULL if unneeded.
	@param		transp_comp		Pointer which will be filled with the transposition component which needs to be applied to the original pcset in order
								to obtain the prime form pcset (after also having applied the #multipl_comp).
								If no transposition need to be done, this will be filled with 0. Leave NULL if unneeded.
	@return		The prime form of the original pcset with respect to the mode and the group.
	@remark		For instance, if mode = #k_PRIMEFORM_MODE_LEXICOGRAPHIC and #group = k_GROUP_T, with modulo = 12 the prime form of (1 3 4 11) is
				(0 1 8 10), whereas if we choose mode = #k_PRIMEFORM_MODE_COMPACTNESS_FIRST, the prime form is (0 2 4 5). Indeed this latter comes AFTER
				the previous one in lexicographic order, but is more compact (extension = 5 vs. extension = 10), thus is preferred in the 
				#k_PRIMEFORM_MODE_COMPACTNESS_FIRST mode. In the #k_PRIMEFORM_MODE_LEXICOGRAPHIC, multipl_comp = 1, transp_comp = -3, because indeed
				({1 3 4 11} * 1) - 3 = {0 1 8 10}.
 */
t_llll* pcset_get_primeform(t_llll *pcset, long modulo, e_primeform_modes mode, e_settheory_groups group, long *multipl_comp, long *transp_comp);


/** Tell if a pcset is in prime form.
	@ingroup	musical_set_theory
	@see		pcset_get_primeform()
	@param		pcset		The pcset
	@param		modulo		The modulo
	@param		mode		One of the #e_primeform_modes, determining the way the prime form is chosen.
	@param		group		One of the #e_settheory_groups, determining the group of transformations up to which the prime form has to be taken 
	@return		1 if the pcset is in primeform with respect to the mode and the group; 0 otherwise.
	@remark		See pcset_get_primeform() for all the information about prime forms 
 */
char pcset_is_prime_form(t_llll *pcset, long modulo, e_primeform_modes mode, e_settheory_groups group);


/** Get all the prime forms in a given ring Z/nZ of a given cardinality.
	@ingroup	musical_set_theory
	@see		pcset_get_primeform()
	@param		set			The pcset
	@param		modulo		The modulo
	@param		mode		One of the #e_primeform_modes, determining the way the prime form is chosen.
	@param		group		One of the #e_settheory_groups, determining the group of transformations up to which the prime form has to be taken 
	@return		1 if the pcset is in primeform with respect to the mode and the group; 0 otherwise.
	@remark		See pcset_get_primeform() for all the information about prime forms 
 */
t_llll *get_all_prime_forms(long modulo, long cardinality, e_primeform_modes mode, e_settheory_groups group);


/** Tell if a given pcset is symmetrical (with respect to any axis).
	@ingroup	musical_set_theory
	@param		pcset		The pcset
	@param		modulo		The modulo
	@return		1 if the pcset is symmetrical, 0 otherwise
	@remark		For instance, with modulo = 12, (0 1 2 5 9) is symmetrical w.r. to the axis passing through 1 and 7.
 */
char pcset_is_symmetrical(t_llll *pcset, long modulo);


/** Find the period of a pcset in number of steps.
	@ingroup	musical_set_theory
	@see		llll_get_period()
	@param		pcset		The pcset
	@param		modulo		The modulo
	@return		The period of the set in number of steps
	@remark		For instance, with modulo = 12 (0 1 3 4 6 7 9 10) has a period of 3 steps, since has interval structure (1 2 1 2 1 2 1 2),
				having period (1 2), and the sum of these steps gives 3, indeed. If a pcset is not periodic, its period in steps will be the modulo.
 */
long pcset_find_period_in_steps(t_llll *pcset, long modulo);


/** Compares two pcsets lexicographically, i.e. by comparing numbers left-to-right (as letters on the dictionary).
	@ingroup	musical_set_theory
	@param		pcset1		The first pcset
	@param		pcset2		The second pcset
	@return		-1 if #set1 < #set2 lexicographically; 0 if #set1 == #set2; 1 if #set1 > #set2 lexicographically
	@remark		Both sets must already be properly ordered, and each element must be between 0 and modulo (that's why the modulo does not appear
				as parameter, use pcset_modulo_inplace() if you need).
	@remark		For instance, (1 2 4) < (1 5 3), since 1=1 (so we go on) and 2 < 5 (which settles the question, and tells that the first one comes before)
				Also, (1 2 4) > (1 2 3), since 1=1 (so we go on), 2=2 (so we go on) and 4 < 3 (which settles the question).
 */
char pcset_compare_lexicographically(t_llll *pcset1, t_llll *pcset2);


/** Count the number of copies of a pcset (#contained) which are embedded in a pcset (#container).
	The meaning of "copy" depends on the chosen #group.
	@ingroup	musical_set_theory
	@param		container		The pcset to be searched for copies of #contained
	@param		contained		The pcset whose copies have to be searched inside #container
	@param		modulo			The modulo
	@param		group			One of the #e_settheory_groups, determining the group of transformations defining what a "copy" is.
								A copy of #contained will be any transformed pcset via a combination of transformations of this group.
	@param		count_periodic_subsets_once		If this is 0, periodic subsets will account for multiple matches. For instance: finding
												(0 4 8) inside the set (0 1 4 8) will yield three copies: {0 4 8}, T_4({0 4 8}) = {4 8 0} and 
												T_8({0 4 8}) = {8 0 4}. Of course it's the same copy which is repeated. On the other one, if this flag 
												is non-zero, the result counts only once the multiple copies deriving from the fact that #contained is 
												a periodic subset.
	@return		The number of copies of the pcset #contained embedded inside the pcset #container. 
	@remark		This function is the basis for building the pcset_mvector().
	@see		pcset_mvector();
 */
long pcset_num_copies(t_llll *container, t_llll *contained, long modulo, e_settheory_groups group, char count_periodic_subsets_once);

/** Obtain the M-vector of a given pcset, given a family of subsets. The M-vector is a vector whose i-th element is the number of copies of the 
	i-th subset of the family embedded in the original set. Usually M is the cardinality of all the subsets in the family. Yet, this algorithm
	works for any family of subsets. The M-vector is returned in llll form (a plain list of integers).
	@ingroup	musical_set_theory
	@param		pcset			The pcset
	@param		list_of_subsets	An llll containing all the pcsets whose copies need to be searched in the original set
	@param		modulo			The modulo
	@param		group			One of the #e_settheory_groups, determining the group of transformations defining what a "copy" is.
								A copy of #contained will be any transformed pcset via a combination of transformations of this group.
	@param		count_periodic_subsets_once		If this is 0, periodic subsets will account for multiple matches. For instance: finding
												(0 4 8) inside the set (0 1 4 8) will yield three copies: {0 4 8}, T_4({0 4 8}) = {4 8 0} and 
												T_8({0 4 8}) = {8 0 4}. Of course it's the same copy which is repeated. On the other one, if this flag 
												is non-zero, the result counts only once the multiple copies deriving from the fact that #contained is 
												a periodic subset.
	@return		An llll of integers containing at i-th entry the number of copies of the i-th subset (of #list_of_subsets) embedded in the original #set  
	@remark		The 2-vector, or interval vector (iv), is a specific case, when #list_of_subsets is the family {{0, 1}, {0, 2}, ..., {0, floor(modulo/2)}}
				and usually with #count_periodic_subsets_once = true.
				For more information, see http://en.wikipedia.org/wiki/Interval_vector
	@remark		Usually one may test the embedding of all prime forms of a given cardinality inside the set. This is what the [bach.iv] object does.
				For instance, to obtain the standard interval vector, one might do
		@code
				t_llll *primeforms = get_all_prime_forms(12, 2, k_PRIMEFORM_MODE_LEXICOGRAPHIC, k_GROUP_TI);
				t_llll *iv = pcset_mvector(inlist, x->pflist, 12, k_GROUP_TI, true);
				llll_free(primeforms);
		@endcode
 */
t_llll* pcset_mvector(t_llll *pcset, t_llll *list_of_subsets, long modulo, e_settheory_groups group, char count_periodic_subsets_once);


/** Tell if the M-vector of a given pcset is equal to a specific vector.
	This algorithm is faster than a simple checking of equality between pcset_mvector(set) and #vec.
	See pcset_mvector() to know more about the M-vector. 
	@see		pcset_mvector()
	@ingroup	musical_set_theory
	@param		pcset			The pcset
	@param		list_of_subsets	An llll containing all the pcsets whose copies need to be searched in the original set
	@param		vec				The specific vector, with respect to which the equality has to be tested.
	@param		modulo			The modulo
	@param		group			One of the #e_settheory_groups, determining the group of transformations defining what a "copy" is.
								A copy of #contained will be any transformed pcset via a combination of transformations of this group.
	@param		count_periodic_subsets_once		If this is 0, periodic subsets will account for multiple matches. For instance: finding
												(0 4 8) inside the set (0 1 4 8) will yield three copies: {0 4 8}, T_4({0 4 8}) = {4 8 0} and 
												T_8({0 4 8}) = {8 0 4}. Of course it's the same copy which is repeated. On the other one, if this flag 
												is non-zero, the result counts only once the multiple copies deriving from the fact that #contained is 
												a periodic subset.
	@return		An llll of integers containing at i-th entry the number of copies of the i-th subset (of #list_of_subsets) embedded in the original #set  
	@remark		This function is used for the tests inside find_zrelated_pcsets().
 */
char is_mvector_of_pcset_equal_to_vec(t_llll *pcset, t_llll *list_of_subsets, t_llll *vec, long modulo, e_settheory_groups group, char count_periodic_subset_once);


/** Search for Z-related sets (or Z^M-related sets) of a given cardinality C inside a given ring Z/nZ (n being the modulo).
	Two sets are Z^M-related if they share the same M-vector, i.e. the same number of copies of any subset of cardinality M is embedded in both of them.
	(Actually, it suffice to test that the same number of copies of any prime form of cardinality M is embedded in both of them).
	Two sets are Z-related (= Z^2-related) if they share the same 2-vector, i.e. if they share the same standard interval vector.
	Z-related sets are output in families, as explained below.
	@remark		For instance, two sets are Z^3 related in Z/12Z (modulo = 12) if any 3-subsets of Z/12Z is found with the same number of copies in both sets.
	@ingroup	musical_set_theory
	@see		pcset_mvector()
	@param		modulo				The modulo
	@param		set_cardinality		The "C" in the function definition: we're searching Z-related sets having cardinality C inside Z/nZ (n being the modulo)
	@param		subset_cardinality	The "M" in the function definition, i.e. the cardinality of the testing subsets (if this is 2, we're testing for Z relation). 
									Of course, for all this to make sense, M < C.
	@param		mode			One of the #e_primeform_modes, determining the way the prime form are chosen.
								(This will not affect the search in itself, rather the representation primeforms that are output.)
	@param		group			One of the #e_settheory_groups, determining the group of transformations defining what a "copy" is.
								A copy of #contained will be any transformed pcset via a combination of transformations of this group.
	@param		count_periodic_subsets_once		If this is 0, periodic subsets will account for multiple matches. For instance: finding
												(0 4 8) inside the set (0 1 4 8) will yield three copies: {0 4 8}, T_4({0 4 8}) = {4 8 0} and 
												T_8({0 4 8}) = {8 0 4}. Of course it's the same copy which is repeated. On the other one, if this flag 
												is non-zero, the result counts only once the multiple copies deriving from the fact that #contained is 
												a periodic subset.
	@param		z_families_min_card		Minimum cardinality for a Z-family in order to be retained. If this is 1, of course all prime forms will be output,
	@param		ivecs					Pointer which will be with the corresponding M-vectors for each found family of Z-sets. Essentially, this list have
										the same structure as the returned list, except that each family of Z-sets is substituted with their M-vector.
										Leave NULL if unneeded.
	@return		All the Z^M-families of sets of cardinality C, organized in the following way:
				((pcset1 pcset2 pcset3 ...) (pcset7 pcset8 ...) (pcset12 pcset13 ...) ...) 
				where inside sublist all the pcsets share the same M-vector (i.e. are Z^M-related).
				If a set has no other Z^M-related primeform (Z^M-partner), it'll be alone in its sublist (very frequent case).
	@remark		NB: This algorithm is not optimized for the interval vector. If you need to achieve great speed, consider building your own algorithm
	@remark		See http://articles.ircam.fr/textes/Mandereau11a/index.pdf for more specific details about Z-relation.
 */
t_llll* find_zrelated_pcsets(long modulo, long set_cardinality, long subset_cardinality, e_primeform_modes mode, e_settheory_groups group, char count_periodic_subsets_once, long z_families_min_card, t_llll **ivecs);



/** Builds a diatonic interval from the diatonic steps and the chromatic steps (see #t_tonnetz_diatonic_interval)
	@ingroup	musical_set_theory
	@param		diatonic_steps		The number of diatonic steps from a fixed note (if the note is middle C, e.g., C# is 0, D or Db or D# is 1, E is 2, and so on).
	@param		chromatic_steps		The number of chromatic steps (whose width depends on the chosen modulo).
	@return		The #t_tonnetz_diatonic_interval structure
 */
t_tonnetz_diatonic_interval build_diatonic_interval(long diatonic_steps, long chromatic_steps);

	
/** Sum two diatonic intervals
	@ingroup	musical_set_theory
	@param		interval1			The first diatonic interval
	@param		interval2			The second diatonic interval
	@return		The sum of the diatonic intervals
 */
t_tonnetz_diatonic_interval diatonic_interval_sum(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2);


/** Substract two diatonic intervals
	@ingroup	musical_set_theory
	@param		interval1			The first diatonic interval
	@param		interval2			The second diatonic interval
	@return		The difference of the diatonic intervals
*/
t_tonnetz_diatonic_interval diatonic_interval_diff(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2);


/** Sum two diatonic intervals, but without filling the frequency ratio fields of the #t_tonnetz_diatonic_interval properly
	(#user_defined_ratio is set to false, while #frequency_ratio is set to 1).
	@remark		This is preferrable to diatonic_interval_sum() if you don't need the frequency ratios, so to improve efficiency.
	@ingroup	musical_set_theory
	@param		interval1			The first diatonic interval
	@param		interval2			The second diatonic interval
	@return		The sum of the diatonic intervals
	@see		diatonic_interval_sum()
 */
t_tonnetz_diatonic_interval diatonic_interval_sum_no_freqratio(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2);


/** Difference two diatonic intervals, but without filling the frequency ratio fields of the #t_tonnetz_diatonic_interval properly
	(#user_defined_ratio is set to false, while #frequency_ratio is set to 1).
	@remark		This is preferrable to diatonic_interval_diff() if you don't need the frequency ratios, so to improve efficiency.
	@ingroup	musical_set_theory
	@param		interval1			The first diatonic interval
	@param		interval2			The second diatonic interval
	@return		The sum of the diatonic intervals
	@see		diatonic_interval_diff()
 */
t_tonnetz_diatonic_interval diatonic_interval_diff_no_freqratio(t_tonnetz_diatonic_interval interval1, t_tonnetz_diatonic_interval interval2);


/** Convert a frequency ratio into midicents
	@ingroup	musical_set_theory
	@param		freqratio			The frequency ratio
	@return		The midicents corresponding to the frequency ratio
 */
double freqratio_to_mc(t_rational freqratio);


/** Convert a midicents value into a pitch class
	@ingroup	musical_set_theory
	@param	mc		The midicents
	@param	modulo	The modulo of the pitch space
	@return		The pitch class (as an integer from 0 to the #modulo - 1
 */
long mc_to_pitch_class(long mc, long modulo);




/**	Convert a screen midicent and accidental value into a diatonic interval with respect to the middle C
	@ingroup				conversions
	@param	screen_midicents	The midicents of the diatonic note (no accidental)
	@param	screen_accidental	The accidental
	@param	modulo				The modulo (equal to 6 times the tone division)
	@return						The diatonic interval of the note from the middle C
	@see		diatonic_interval_to_screen_midicents_and_accidental()
 */ 
t_tonnetz_diatonic_interval screen_midicents_and_accidental_to_diatonic_interval(long screen_midicents, t_rational screen_accidental, long modulo);


/**	Convert a diatonic interval with respect to the middle C into the screen midicent and accidental of the displayed note.
	@remark						The function doesn't need the frequency ration of the #t_tonnetz_diatonic_interval to be filled properly, so you can 
								just drop its calculation for efficiency's sake, if you need it.
	@ingroup					conversions
	@param	interval			The diatonic interval
	@param	screen_midicents	Pointer which will be filled with the midicents of the diatonic note (no accidental)
	@param	screen_accidental	Pointer which will be filled with the accidental
	@param	modulo				The modulo (equal to 6 times the tone division)
	@see	screen_midicents_and_accidental_to_diatonic_interval()
 */ 
void diatonic_interval_to_screen_midicents_and_accidental(t_tonnetz_diatonic_interval interval, long *screen_midicents, t_rational *screen_accidental, long modulo);


/**	Convert a note name into a diatonic interval with respect to the middle C
	@ingroup				conversions
	@param	middleC_octave	Octave of the middle C
	@param	name			The note name
	@param	modulo				The modulo (equal to 6 times the tone division)
	@return					The diatonic interval of the note from the middle C
 */ 
t_tonnetz_diatonic_interval notename_to_diatonic_interval(long middleC_octave, char *name, long modulo);


#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _LLLL_SETTHEORY_H_
