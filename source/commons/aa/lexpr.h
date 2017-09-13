#ifndef _LEXPR_H_
#define _LEXPR_H_

#define LEXPR_MAX_VARS 255
#define LEXPR_MAX_SUBSTITUTION_LENGTH 31
#define	L_MAX_LEXEMES	4096
#define	L_MAX_TOKENS	L_MAX_LEXEMES // each lexeme corresponds to one token, or none. so we are sure to have enough space for tokens.

typedef enum _lexpr_lexeme_types {
	L_NONE = 0,
	L_OPEN,
	L_CLOSED,
	L_COMMA,
	L_TOKEN,
	L_SKIP
} e_lexpr_lexeme_types;

typedef enum _lexpr_token_types {
	TT_NONE = 0,
	TT_HATOM,
	TT_VAR,
	TT_OP,
	TT_FUNC,
} e_lexpr_token_types;

typedef enum _lexpr_op_properties {	// the properties are used in the constant folding phase
	OP_NONE = 0,
	OP_COMM = 0x1,		// operator is commutative
	OP_ASSOC = 0x2,		// operator is associative
	OP_INVERT = 0x4		// operator has a "simpler" inversion (e.g. - inverts to +, but not viceversa)
} e_lexpr_op_properties;

typedef enum _lexpr_ops {
//	O_UPLUS,
	O_UMINUS,
	O_PLUS,
	O_MINUS,
	O_TIMES,
	O_DIV,
	O_DIVDIV,	// always returns an integer even when call
	O_MOD,
	O_POW,
	O_LOGAND,
	O_BITAND,
	O_LOGOR,
	O_BITOR,
	O_LOGNOT,
	O_BITNOT,
	O_LOGXOR,
	O_BITXOR,
	O_EQ,
	O_EQMATCH,
	O_NEQ,
	O_NEQMATCH,
	O_GT,
	O_GE,
	O_LT,
	O_LE,
	O_LSHIFT,
	O_RSHIFT
} e_lexpr_operators;

typedef enum _exprparser_err {
    E_OK = 1,
    E_BAD_VAR_TYPE,
    E_BAD_NAME,
    E_BAD_EXPR
} e_exprparser_err;

typedef struct _lexpr_var {
	unsigned long v_index;	// the index number of the variable (0-LEXPR_MAX_VARS)
	unsigned long v_type;	// the type of the corresponding hatom
} t_lexpr_var;

typedef struct _lexpr_op {
	e_lexpr_operators o_op;				// the operator
	e_lexpr_operators o_inv;			// its inversion (you don't need to set this for using it with expr_eval_one)
	long o_properties;	// its properties (you don't need to set this for using it with expr_eval_one)
} t_lexpr_op;

typedef struct _lexpr_func {
	unsigned long f_type;		// currently, can be H_DOUBLE or H_ALL
	long f_dontfold;	// should be 1 only for "random"
	union {		// of course, the fields of the union are all the same. this is only useful to avoid some casting
		double		(*p_dptr_d)(double a);	// the function, if it will return a double (e.g. cos) - use it with f_type H_DOUBLE
		double		(*p_dptr_dd)(double a, double b);	// the function, if it will return a double (e.g. cos) - use it with f_type H_DOUBLE
		long		(*p_lptr)();	// the function, if it will return a long (unused)
		t_rational	(*p_rptr)();	// the function, if it will return a rational (unused)
		void		(*p_vptr_hh)(t_hatom *a, t_hatom *r);	// use this with H_ALL. the function returns void, but accepts a last *hatom parameter for storing the result (see lexpr_float or lexpr_pow)
		void		(*p_vptr_hhh)(t_hatom *a, t_hatom *b, t_hatom *r);	// use this with H_ALL. the function returns void, but accepts a last *hatom parameter for storing the result (see lexpr_float or lexpr_pow)
	} f_ptrs;
} t_lexpr_func;

typedef struct _lexpr_token {
	e_lexpr_token_types t_type;
	short t_operands;				// how many operands it has - you don't need to set this for using it with expr_eval_one
	union {
		t_hatom			c_hatom;	// if it contains an atom
		t_lexpr_var		c_var;		// if it contains a variable (index of that variable)
		t_lexpr_op		c_op;		// if it contains an operator
		t_lexpr_func	c_func;		// if it contains a function (function pointer)
	} t_contents;
} t_lexpr_token;

// order of evaluation of the operator
typedef enum _lexpr_op_order {
	O_L2R,
	O_R2L
} t_lexpr_op_order;

// private
typedef struct _lexpr_lexeme {
	e_lexpr_lexeme_types l_type;	// the type of the lexeme
	short l_precedence;				// its precedence level
	short l_order;					// the evaluation order
	struct _lexpr_token l_token;	// the token
} t_lexpr_lexeme;

typedef struct _lexpr {
//	t_object l_ob;
#ifdef BACH_USE_MAGIC_NUMBER
	unsigned long	l_magic;
#endif
	t_int32_atomic	l_count;
	long			l_size;
	short			l_numvars;	// the index of the last variable
	t_lexpr_token	*l_tokens;
} t_lexpr;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
BEGIN_CHECK_LINKAGE
#endif
	
/*
 perform a single operation, set in *verb, on the hatoms *h1 and *h2, and put the result in *res
 if the operation is unary, h2 must be NULL
 returns 0 if successful, errno otherwise
 */
long lexpr_eval_one(const t_lexpr_token *verb, t_hatom *h1, t_hatom *h2, t_hatom *res);

/*
 evaluate an expression with a set of variables.
 returns a new *hatom with the result of the evaluation (you must free it)
 */
t_hatom *lexpr_eval(t_lexpr *expr, t_hatom *vars);

t_lexpr *lexpr_alloc(void);
t_lexpr *lexpr_new(short ac, t_atom *av, long subs_count, const char **substitutions, t_object *culprit);
t_max_err lexpr_init(t_lexpr *this_lexpr, short ac, t_atom *av, long subs_count, const char **substitutions, t_object *culprit);
long lexpr_invert(t_lexpr_token *verb, t_lexpr_token *arg2); 
long lexpr_check(t_lexpr_token *tok, long chk);
t_max_err lexpr_lex(char *this_pos, char **next_pos, t_lexpr_lexeme *lex, short *numvars, long subs_count, const char **substitutions);
void lexpr_free(t_lexpr *x);
void lexpr_retain(t_lexpr *x);
void lexpr_release(t_lexpr *x);



long lexpr_append_lexeme_OPEN(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_CLOSED(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_COMMA(t_lexpr_lexeme *lex);

long lexpr_append_lexeme_VAR(t_lexpr_lexeme *lex, char type, long index, short *numvars, char *txt, char **offending);
long lexpr_append_lexeme_VAR_substitution(t_lexpr_lexeme *lex, char *txt, long subs_count, const char *substitutions[], short *numvars, char **offending);

long lexpr_append_lexeme_BITOR(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LOGOR(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_BITAND(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LOGAND(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_BITXOR(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LOGXOR(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_BITNOT(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LOGNOT(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_NEQ(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_NEQMATCH(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_EQ(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_EQMATCH(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LT(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LSHIFT(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LE(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_GT(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_RSHIFT(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_GE(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_TIMES(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_POW(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_MOD(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_DIV(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_DIVDIV(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_PLUS(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_MINUS(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_UMINUS(t_lexpr_lexeme *lex);
long lexpr_append_lexeme_LONG(t_lexpr_lexeme *lex, t_atom_long l);
long lexpr_append_lexeme_RATIONAL(t_lexpr_lexeme *lex, t_rational r);
long lexpr_append_lexeme_FLOAT(t_lexpr_lexeme *lex, double d);
long lexpr_append_lexeme_PITCH(t_lexpr_lexeme *lex, t_pitch p);

long lexpr_append_lexeme_FUNC_unary_DOUBLE(t_lexpr_lexeme *lex, double(*f)(double a));
long lexpr_append_lexeme_FUNC_binary_DOUBLE(t_lexpr_lexeme *lex, double(*f)(double a, double b));
long lexpr_append_lexeme_FUNC_unary_ALL(t_lexpr_lexeme *lex, void(*f)(t_hatom *a, t_hatom *r));
long lexpr_append_lexeme_FUNC_binary_ALL(t_lexpr_lexeme *lex, void(*f)(t_hatom *a, t_hatom *b, t_hatom *r));
long lexpr_append_lexeme_FUNC_binary_ALL_dontfold(t_lexpr_lexeme *lex, void(*f)(t_hatom *a, t_hatom *b, t_hatom *r));



#ifndef DOXYGEN_SHOULD_SKIP_THIS
END_CHECK_LINKAGE
#endif

#endif // _LEXPR_H_