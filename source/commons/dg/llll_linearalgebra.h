/**
	@file	llll_linearalgebra.h
	@brief	Tools for matrix calculus and linear algebra
	
	by Daniele Ghisi
*/

#ifndef _LLLL_LINEARALGEBRA_H_
#define _LLLL_LINEARALGEBRA_H_

#include "llll_files.h"
#include "bach_math_utilities.h"

#define CONST_LINEAR_ALGEBRA_EPSILON_APPROX_ZERO 0.0000001	///< @ingroup linear_algebra Smallest number considered different from zero while examining a matrix element

/** Way of performing gaussian elimination. @ingroup linear_algebra */
typedef enum _gausselim_modes {
	k_SIMPLE_ELIMINATION = 0,	///< Perform simple elimination (final matrix form is upper triangular) 
	k_DOUBLE_ELIMINATION		///< Perform double elimination: also step back eliminating upper elements (final form is pseudo-diagonal)
} e_gausselim_modes;

/** Type of solutions for linear systems. @ingroup linear_algebra */
typedef enum _solution_types {
	k_LINEAR_SYSTEM_WRONG = 0,						///< The linear system is badly defined, either because the matrix is not well shaped, or because sizes do not match
	k_LINEAR_SYSTEM_ONE_SOLUTION = 1,				///< The linear system has one and only one solution
	k_LINEAR_SYSTEM_INFINITELY_MANY_SOLUTIONS = 2,	///< The linear system has infinitely many solutions
	k_LINEAR_SYSTEM_NO_SOLUTION = 3					///< The linear system has no solution
} e_solution_types;


#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif
	

/**	Get the identity matrix
	@param	size	The size of the matrix
	@return	The identity matrix with #size columns and #size rows.
	@ingroup linear_algebra
 */ 
t_llll* llll_get_identity_matrix(long size);


/**	Get a diagonal matrix having a given llll as a main diagonal (or any other secondary diagonal)
	@ingroup linear_algebra
	@param	diagonal	The diagonal the matrix has to have
	@param	shift		The shift with respect to the main diagonal (0 = main diagonal, -1 = subdiagonal, etc.) 
	@return				The matrix having #diagonal as diagonal of position #shift.
 */ 
t_llll* llll_get_diagonal_matrix(t_llll *diagonal, long shift);


/**	Compute the scalar product of two vectors.
	@ingroup linear_algebra
	@param	vector1		The first vector
	@param	vector2		Ths second vector
	@return				The scalar product between the two vectors.
 */ 
t_hatom llll_vector_vector_product(t_llll *vector1, t_llll *vector2);


/**	Multiply a vector by a scalar.
	@ingroup linear_algebra
	@param	scalar		The scalar
	@param	vector		The vector
	@return				The multiplication of the vector by the scalar.
 */ 
t_llll* llll_scalar_vector_product(t_hatom *scalar, t_llll *vector);


/**	Multiply a matrix by a scalar.
	@ingroup linear_algebra
	@param	scalar		The scalar
	@param	matrix		The matrix
	@return				The multiplication of the matrix by the scalar.
 */ 
t_llll* llll_scalar_matrix_product(t_hatom *scalar, t_llll *matrix);


/**	Compute the matrix multiplication of two matrices.
	@ingroup linear_algebra
	@param	llll1		The first matrix
	@param	llll2		The second matrix
	@return				The matrix product of the two matrices.
 */ 
t_llll* llll_matrix_matrix_product(t_llll *llll1, t_llll *llll2);


/**	Compute the sum of two matrices.
	@ingroup linear_algebra
	@param	matrix1		The first matrix
	@param	matrix2		The second matrix
	@return				The sum of the two matrices.
 */ 
t_llll* llll_matrix_matrix_sum(t_llll *matrix1, t_llll *matrix2);


/**	Compute the difference of two matrices.
	@ingroup linear_algebra
	@param	matrix1		The first matrix
	@param	matrix2		The second matrix
	@return				The difference of the two matrices.
 */ 
t_llll* llll_matrix_matrix_diff(t_llll *matrix1, t_llll *matrix2);


/**	Compute an element-wise operation on two matrices.
	@param	matrix1		The first matrix
	@param	matrix2		The second matrix
	@param	operator	The operator as a #t_lexpr_token.
	@return				The matrix obtained by performing the element-wise operator on the two incoming matrices.
	@remark		For instance, to have a matrix element-wise product one can do the following:
				@code
				t_lexpr_token times = get_times_operator();
				return llll_matrix_matrix_elementwise_operation(matrix1, matrix2, &times);
				@endcode
	@ingroup linear_algebra
 */ 
t_llll* llll_matrix_matrix_elementwise_operation(t_llll *matrix1, t_llll *matrix2, t_lexpr_token *op);


/**	Get the number of rows of a matrix.
	@ingroup linear_algebra
	@param	matrix		The matrix
	@return				The number of rows of #matrix
	@remark				This is just the size of the matrix as llll.
 */ 
long llll_get_matrix_num_rows(t_llll *matrix);


/**	Get the number of columns of a matrix.
	@ingroup linear_algebra
	@param	matrix		The matrix
	@param	well_shaped	A pointer to a char which will be filled with 1 if all the rows of #matrix have the same number of elements,
						or with 0 otherwise. Leave it NULL if you don't care.
	@return				The number of columns of #matrix
 */ 
long llll_get_matrix_num_cols(t_llll *matrix, char *well_shaped);


/**	Tell if a matrix is a square matrix.
	@ingroup linear_algebra
	@param	matrix		The matrix
	@return				1 if #matrix is a square matrix, 0 otherwise.
 */ 
char llll_is_matrix_square(t_llll *matrix);


/**	Tell if a matrix is a well-shaped (i.e. all the rows have the same number of elements).
	@ingroup linear_algebra
	@param	matrix		The matrix
	@return				1 if #matrix is well-shaped, 0 otherwise.
 */ 
char llll_is_matrix_well_shaped(t_llll *matrix);


/**	Tell if a matrix is symmetrical.
	@ingroup linear_algebra
	@param	matrix		The matrix
	@return				1 if #matrix is symmetrical, 0 otherwise.
 */ 
char llll_is_matrix_symmetrical(t_llll *matrix, char match_type);


/**	Retrieve a specific matrix cell (element)
	@ingroup linear_algebra
	@param	matrix		The matrix
	@param	row			The 1-based row number
	@param	col			The 1-based column number
	@return				The element at position (#row, #col).
 */ 
t_llllelem *llll_get_element_in_matrix(t_llll *matrix, long row, long col);


/**	Extract a submatrix from a matrix.
	@ingroup linear_algebra
	@param	matrix			The original matrix
	@param	start_row		The 1-based starting row number for the submatrix extraction
	@param	start_column	The 1-based starting column for the submatrix extraction
	@param	end_row			The 1-based ending row number for the submatrix extraction
	@param	end_column		The 1-based ending column for the submatrix extraction
	@return					The submatrix lying across the two elements (#start_row, #start_column) and (#end_row, #end_column).
 */ 
t_llll* llll_get_submatrix(t_llll *matrix, long start_row, long start_column, long end_row, long end_column);


/**	Juxtapose horizontally a matrix and a vector. If the matrix is A and the vector is v, this is often notated as A|v.
	Both A and v should have the same number of rows.
	@ingroup linear_algebra
	@param	matrix		The matrix
	@param	vector		The vector
	@return				The extended matrix, obtained by juxtaposing the matrix and the vector
 */ 
t_llll* llll_juxtapose_matrix_and_vector(t_llll *matrix, t_llll *vector);


/**	Juxtapose horizontally two matrices. If the two matrices are A and B, this is often notated as A|B.
	Both A and B should have the same number of rows.
	@ingroup linear_algebra
	@param	matrix1		The first matrix
	@param	matrix2		The second matrix
	@return				The extended matrix, obtained by juxtaposing the two matrices
 */ 
t_llll* llll_juxtapose_matrix_and_matrix(t_llll *matrix1, t_llll *matrix2);


/**	Obtain a new matrix by removing a given row and column from an original matrix
	@ingroup linear_algebra
	@param	matrix	The original matrix
	@param	row		The 1-based number of the row to remove 
	@param	col		The 1-based number of the column to remove 
	@return			The matrix obtained by removing the row and the column from the original matrix. 
 */ 
t_llll* llll_get_submatrix_by_removing_row_and_column(t_llll *matrix, long row, long col);


/**	Put to zero all elements in the matrix which are smaller (in absolute value) than #CONST_LINEAR_ALGEBRA_EPSILON_APPROX_ZERO.
	It is in-place: the operation is performed on the incoming matrix.
	@ingroup linear_algebra
	@param	matrix	The matrix.
 */ 
void llll_approx_for_zeros(t_llll *matrix);


/**	Swap two matrix rows.
	@ingroup linear_algebra
	@param	matrix	The matrix.
	@param	row1	The 1-based number of the first row
	@param	row2	The 1-based number of the second row
 */ 
void llll_matrix_swap_rows(t_llll *matrix, long row1, long row2); 


/**	Swap two matrix columns.
	@ingroup linear_algebra
	@param	matrix	The matrix.
	@param	col1	The 1-based number of the first column
	@param	col2	The 1-based number of the second columns
 */ 
void llll_matrix_swap_cols(t_llll **matrix, long col1, long col2); 


/**	Reduce a matrix via the Gaussian elimination process: http://en.wikipedia.org/wiki/Gaussian_elimination
	The original matrix is left untouched, and the triangulated one is returned.
	@ingroup linear_algebra
	@param	matrix_in	The original matrix
	@param	num_swaps	Pointer to a long which will be filled with the number of row swaps that were performed. Leave NULL if not needed
	@param	rank		Pointer to a long which will be filled with the rank of the #matrix_in. Leave NULL if not needed.
	@param	det			Pointer to a hatom which will be filled with the determinant of the #matrix_in. Leave NULL if not needed.
	@param	mode		One of the #e_gausselim_modes, specifying if we want to perform a simple or double elimination
	@param	max_columns_for_reduced_rank	1-based number of the column used as a rightmost boundary for computing the #reduced_rank.
											If you don't need to compute such reduced rank, just ignore this value (e.g. let 0).
	@param	reduced_rank	Pointer to a long which will be filled with the rank of the matrix obtained by trimming
							the #matrix_in up to its #max_columns_for_reduced_rank column. Leave NULL if not needed.
	@param	columns_having_pivots	Pointer to a (t_llll *) which will be filled with an llll containing the 1-based indices of the 
									columns having pivots. The memory is allocated inside the function, so you need to free this
									list later, if you want to get rid of it. Leave NULL if you don't need it.
	@param	admit_col_swap			If this is 1, the algorithm will be also allowed to swap columns.
	@param	new_column_order		Pointer to a (t_llll *) which will be filled with the 1-based indices of the columns reordered
									after the elimination process. Of course, if #admit_col_swap is 0, the reording will be trivial.
									Leave this to NULL if you don't need it. Otherwise, memory is allocated, and you'll need to free
									the llll when you don't need it any more.
	@return							The matrix obtained by Gaussian elimination from the original matrix
 */ 
t_llll* llll_gauss_reduce_matrix(t_llll *matrix_in, long *num_swaps, long *rank, t_hatom *det, char mode, 
									long max_column_for_reduced_rank, long *reduced_rank, t_llll **columns_having_pivots, 
									char admit_col_swaps, t_llll **new_column_order);

									
/**	Solve a linear system of the type Ax = v.
	@ingroup linear_algebra
	@param	matrix			The system matrix (A)
	@param	vector			The columns vector (v)
	@param	solution_type	A pointer to a char, which will be filled with one of the #e_solution_types, determining the type of solution that the system has.
	@return					The solution of the linear system, if unique. NULL otherwise.
*/								
t_llll* llll_solve_linear_system(t_llll *matrix, t_llll *vector, char *solution_type);


/**	Compute the trace of a matrix (sum of the elements on a diagonal, main or shifted)
	@ingroup linear_algebra
	@param	matrix	The matrix
	@param	shift	The shift with respect to the main diagonal for the trace computation (0 = main diagonal, 1 = 1 above, -1 = 1 below...)
	@return			The trace of the matrix
*/								
t_hatom llll_trace(t_llll *matrix, long shift); 


/**	Compute the determinant of a matrix.
	It actually performs a gauss elimination via llll_gauss_reduce_matrix(), and just keeps the determinant value.
	@ingroup linear_algebra
	@param	matrix	The matrix
	@return			The determinant of the matrix
*/								
t_hatom llll_det(t_llll *matrix); 


/**	Compute the rank of a matrix.
	It actually performs a gauss elimination via llll_gauss_reduce_matrix(), and just keeps the rank value.
	@ingroup linear_algebra
	@param	matrix	The matrix
	@return			The rank of the matrix
*/								
long llll_rank(t_llll *matrix); 


/**	(UNTESTED) Compute the inverse of a matrix.
	@ingroup linear_algebra
	@param	matrix	The matrix
	@param	answer	A pointer which will be filled with:
					-1 if matrix is not well shaped or not square,
					0 if matrix is singular,
					1 if matrix has inverse 
	@return			The inverse of the matrix if existing, otherwise NULL.
*/								
t_llll* llll_inv(t_llll *matrix, char *answer);


/**	Compute a minor. A minor is the determinant of a square matrix obtained by removing a given row and columns.
	@param	matrix	The original square matrix 
	@param	row		The 1-based number of the row to remove from the original matrix
	@param	col		The 1-based number of the columns to remove from the original matrix
	@return			The determinant of the matrix obtained by removing the row and the column from the original matrix.
	@ingroup linear_algebra
*/								
t_hatom llll_get_minor(t_llll *matrix, long row, long col);


/**	Compute a cofactor. A cofactor is \f$C_{i,j} = (-1)^{i+j} M_{i,j}\f$, where \f$M_{i,j}\f$ is the minor obtained by removing 
	row \f$i\f$ and column \f$j\f$ from the original matrix.
	@param	matrix	The original square matrix 
	@param	row		The 1-based number of the row to remove from the original matrix
	@param	col		The 1-based number of the columns to remove from the original matrix
	@return			The cofactor \f$C_{i,j}\f$.
	@ingroup linear_algebra
*/								
t_hatom llll_get_cofactor(t_llll *matrix, long row, long col); // now 1-based


/**	Get the cofactor matrix of an original square matrix. The cofactor matrix is the matrix having as element \f$(i,j)\f$ the cofactor
	\f$C_{i,j}\f$ (see #llll_get_cofactor()).
	@param	matrix	The original square matrix 
	@return			The cofactor matrix.
	@see			llll_get_cofactor()
	@ingroup linear_algebra
*/							
t_llll* llll_get_cofactor_matrix(t_llll *matrix);


/**	Get the adjugate matrix (or classical adjoint matrix). The adjugate matrix the transposed of the cofactor matrix.
	@param	matrix	The original square matrix 
	@return			The adjugate matrix.
	@see			llll_get_cofactor_matrix()
	@ingroup linear_algebra
*/								
t_llll* llll_adj(t_llll *matrix); 


/**	Find the eigenvalues and the eigenvectors of a given matrix, via the power iteration method: http://en.wikipedia.org/wiki/Power_iteration
	@ingroup linear_algebra
	@param	matrix			The matrix
	@param	eigenvalues		Pointer to a (t_llll *) that will be filled with a plain llll containing the eigenvalues of the matrix
	@param	eigenvalues		Pointer to a (t_llll *) that will be filled with an llll containing, for each eigenvalue, a corresponding eigenvector 
	@param	num_iterations	Maximum number of iterations for the algorithm
	@param	max_rand_coeff	Maximum random coefficient for the starting seed vector (e.g. 100)
	@return					-1 if the matrix is not well-shaped, 1 otherwise.
*/								
char llll_get_eigenvalues_and_eigenvectors(t_llll *matrix, t_llll** eigenvalues, t_llll** eigenvectors, long num_iterations, long max_rand_coeff);


/**	Compute the euclidean norm of a vector
	@ingroup linear_algebra
	@param	vector	The vector
	@return			The euclidean norm of the vector v, \f$|v| = \sqrt{\sum_i v_i}\f$.
*/								
double llll_norm(t_llll *vector); // norm of a vector


/**	Compute the normalized form of a vector. This latter remains untouched, and the normalization is returned.
	@ingroup linear_algebra
	@param	vector		The original vector
	@param	succeeded	Pointer to a char that will be filled with 1 if the normalization has succeeded, or with 0 otherwise (if the norm of the original vector was 0).
	@return				The normalized vector: pointing in the same direction and sense of the original vector, but having norm = 1.
 */								
t_llll* llll_normalize_vector(t_llll *vector, char *succeeded);


/**	Compute the projection of a vector onto a given direction.
	@ingroup linear_algebra
	@param	vector		The original vector
	@param	direction	The direction (the modulo of the vector is irrelevant, only the direction is meaningful)
	@return				The projection of the #vector along the #direction.
 */								
t_llll* llll_proj(t_llll *vector, t_llll *direction); 


/**	Extract a basis from a list of vectors.
	@ingroup linear_algebra
	@param	vectors_as_single_llll	An llll contaning the list of vectors
	@param	make_orthogonal			If this is 1, the basis is orthogonalized
	@param	make_normal				If this is 1, each vector of the basis is normalized
	@return							A subset of #vectors_as_single_llll constituing a base for the space
 */							
t_llll* llll_extract_basis(t_llll *vectors_as_single_llll, char make_orthogonal, char make_normal); 


/**	Obtain a base for the kernel of a matrix (the space of vectors sent to 0 via matrix multiplication).
	@ingroup linear_algebra
	@param	matrix		The matrix
	@return				A basis for the kernel of the matrix
 */							
t_llll* llll_ker(t_llll *matrix); // find kernel


/**	(UNTESTED) Obtain a base for the image of a matrix (the space spanned by matrix columns).
	@ingroup linear_algebra
	@param	matrix		The matrix
	@return				A basis for the image of the matrix
 */							
t_llll* llll_im(t_llll *matrix);


/**	Force a set of vectors to be orthogonal, via the Gram-Schmidt orthogonalization: http://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process
	The function is in-place, as it changes the existing vectors. If vectors are more than the space dimensions, some vectors
	will be necessarily left untouched (and the orthogonalization won't be achieved).
	@param	vectors		An llll containing the list of vectors
	@ingroup linear_algebra
 */							
void llll_make_vector_set_orthogonal(t_llll *vectors);


/**	Normalize a set of vectors. The function is in-place, as it changes the existing vectors.
	@ingroup linear_algebra
	@param	vectors		An llll containing the list of vectors
 */							
void llll_make_vector_set_normalized(t_llll *vectors);




#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif
	
// llll_trans is in llll_commons.h

#endif // _LLLL_LINEARALGEBRA_H_
