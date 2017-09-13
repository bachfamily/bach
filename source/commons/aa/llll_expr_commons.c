/*
 *  llll_expr_commons.c
 *  bach
 *
 *  Created by andrea agostini on 13/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ext.h"
#include "ext_obex.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "llll_commons.h"
#include "lexpr.h"
#include "llll_math.h"

#ifdef WIN_VERSION
#include <errno.h>
#endif


t_lexpr *lexpr_new(short ac, t_atom *av, long subs_count, const char **substitutions)
{
	t_lexpr *x;
/*	
	if (!(x = object_alloc_debug(lexpr_class))) {
		//		post("can't allocate lexpr");
		return NULL;
	}
*/
	x = lexpr_alloc();
	if (lexpr_init(x, ac, av, subs_count, substitutions) != MAX_ERR_NONE) {
		lexpr_free(x);
		return NULL;
	}
	
	return x;
}

t_lexpr *lexpr_alloc(void)
{
	t_lexpr *x = (t_lexpr *) bach_newptrclear(sizeof(t_lexpr));
#ifdef BACH_USE_MAGIC_NUMBER
	x->l_magic = BACH_MAGIC_GOOD;
#endif
	x->l_count = 1;
	return x;
}

void lexpr_retain(t_lexpr *x)
{
	ATOMIC_INCREMENT(&x->l_count);
}

void lexpr_release(t_lexpr *x)
{
	lexpr_free(x);
}

void lexpr_free(t_lexpr *x)
{
	if (!x)
		return;
	if (ATOMIC_DECREMENT(&x->l_count))
		return;
#ifdef BACH_USE_MAGIC_NUMBER
	x->l_magic = BACH_MAGIC_BAD;
#endif	
    if (x->l_tokens)
		bach_freeptr(x->l_tokens);
	bach_freeptr(x);
}

/*
 av contains:
 atoms composing the string
 
 returns the compiled expression
 */
t_max_err lexpr_init(t_lexpr *this_lexpr, short ac, t_atom *av, long subs_count, const char **substitutions)
{
	t_lexpr_lexeme *this_lex, **lexstack_ptr;
	t_lexpr_lexeme *lexs, **lexstack;
	t_lexpr_token *tokqueue, *tokqueue_ptr, *this_lex_token, *tokqueue_last, *nextarg, *nextarg2, temp_tok;
	int i, lexc = 0;
	long chk = 0;
	short numvars = 0;
	char *this_char, *next_char;
	char again;
	t_hatom result_hatom;
	t_max_err err = MAX_ERR_NONE;
	
	//	post("creating lexpr");
	

	if (!(this_lexpr->l_tokens = (t_lexpr_token *) bach_newptrclear(L_MAX_TOKENS * sizeof(t_lexpr_token)))) {
		//		post("can't allocate tokens");
		return MAX_ERR_GENERIC;
	}
	if (!(lexs = (t_lexpr_lexeme *) bach_newptrclear(L_MAX_LEXEMES * sizeof(t_lexpr_lexeme)))) {
		return MAX_ERR_GENERIC;
	}
	if (!(lexstack = (t_lexpr_lexeme **) bach_newptrclear(L_MAX_LEXEMES * sizeof(t_lexpr_lexeme *)))) {
		bach_freeptr(lexs);
		return MAX_ERR_GENERIC;
	}
	
	lexs[0].l_type = L_NONE;
	this_lex = lexs + 1;
	
	tokqueue = this_lexpr->l_tokens;
	// tokenization
	//	post("TOKENIZATION:");
	for (i = 0; i < ac; i++, av++) {
		switch (atom_gettype(av)) {
			case A_LONG:
				//				post("atom %ld: A_LONG %ld", i, atom_getlong(av));
				this_lex->l_type = L_TOKEN;
				this_lex->l_token.t_type = TT_HATOM;
				this_lex->l_token.t_contents.c_hatom.h_w.w_long = av->a_w.w_long;
				this_lex->l_token.t_contents.c_hatom.h_type = H_LONG;
				this_lex++;
				lexc++;
				break;
			case A_FLOAT:
				//				post("atom %ld: A_FLOAT %f", i, atom_getfloat(av));
				this_lex->l_type = L_TOKEN;
				this_lex->l_token.t_type = TT_HATOM;
				this_lex->l_token.t_contents.c_hatom.h_w.w_double = av->a_w.w_float;
				this_lex->l_token.t_contents.c_hatom.h_type = H_DOUBLE;
				this_lex++;
				lexc++;
				break;
			case A_SYM:
				//				post("atom %ld: A_SYM", i);
				this_char = atom_getsym(av)->s_name;
				do {
					//					post("-this_char: %s %c %d", this_char, *this_char, (int) *this_char);
					if (lexpr_lex(this_char, &next_char, this_lex, &numvars, subs_count, substitutions) != MAX_ERR_NONE) {
						//						post("problem with lex");
						goto lexpr_new_error;
					}
					this_char = next_char;
					//					post("-this_lex->l_type: %ld", this_lex->l_type);
					if (this_lex->l_type != L_SKIP) {
						//						post("-advancing to next lex");
						this_lex++;
						lexc++;
						if (lexc >= L_MAX_LEXEMES)
							goto lexpr_new_error;
					}
				} while (next_char && *next_char);
				//				post("-symbol end");
				//				lexc--;
				//				this_lex--;
				break;
			default:
				//				post("tokenization aborted");
				goto lexpr_new_error;
				break;
		}
		
		if (lexc >= L_MAX_LEXEMES)
			goto lexpr_new_error;
	}
	
	
	lexstack_ptr = lexstack - 1; // always points the last valid argument
	tokqueue_ptr = tokqueue;
	//	post("SHUNTING-YARD:");
	
	// the shunting-yard algorithm! (plus some error checking)
	// http://en.wikipedia.org/wiki/Shunting-yard_algorithm
	
	for (i = 0, this_lex = lexs + 1; i < lexc && err == MAX_ERR_NONE; i++, this_lex++) {
		switch (this_lex->l_type) {
			case L_COMMA:
				while (lexstack_ptr >= lexstack && (*lexstack_ptr)->l_type != L_OPEN) {
					//dev_post(",");
					*tokqueue_ptr = (*lexstack_ptr--)->l_token;
					chk = lexpr_check(tokqueue_ptr++, chk);
					if (chk < 1) {
						//						post("aiaiai");
						goto lexpr_new_error;
					}
				}
				if (lexstack_ptr < lexstack) {
					//					post("oioioi");
					goto lexpr_new_error;
				}
				break;
			case L_OPEN:
				//				post("(");
				*++lexstack_ptr = this_lex;
				break;
			case L_CLOSED:
				//				post(")");
				while (lexstack_ptr >= lexstack && (*lexstack_ptr)->l_type != L_OPEN) {
					*tokqueue_ptr = (*lexstack_ptr--)->l_token;
					chk = lexpr_check(tokqueue_ptr++, chk);
					if (chk < 1) {
						//						post("uiuiui");	
						goto lexpr_new_error;
					}
				}
				if (lexstack_ptr < lexstack) {
					//					post("hihihi");	
					goto lexpr_new_error;
				}
				lexstack_ptr--;
				if (lexstack_ptr >= lexstack && (*lexstack_ptr)->l_type == L_TOKEN && (*lexstack_ptr)->l_token.t_type == TT_FUNC) {
					*tokqueue_ptr = (*lexstack_ptr--)->l_token;
					chk = lexpr_check(tokqueue_ptr++, chk);
					if (chk < 1) {
						//						post("eieiei");
						goto lexpr_new_error;
					}
				}
				break;
			case L_TOKEN:
				this_lex_token = &this_lex->l_token;
				switch (this_lex_token->t_type) {
					case TT_HATOM:
					case TT_VAR:
						//						post("hatom / var %ld", this_lex_token->t_type);
						*tokqueue_ptr++ = this_lex->l_token;
						chk++;
						break;
					case TT_FUNC:
						//						post("function");
						*++lexstack_ptr = this_lex;				
						break;
					case TT_OP:
						//						post("operator");
						while (lexstack_ptr >= lexstack &&
							   (*lexstack_ptr)->l_type == L_TOKEN &&
							   (*lexstack_ptr)->l_token.t_type == TT_OP &&
							   ((this_lex->l_order == O_L2R && this_lex->l_precedence <= (*lexstack_ptr)->l_precedence) ||
								(this_lex->l_precedence < (*lexstack_ptr)->l_precedence))) {
								   *tokqueue_ptr = (*lexstack_ptr--)->l_token;
								   chk -= tokqueue_ptr++->t_operands - 1;
								   if (chk < 1) {
									   //									   post("iiiiii");
									   goto lexpr_new_error;
								   } 
							   }
						*++lexstack_ptr = this_lex;						
						break;
					default:
						//						post("bad token, type %ld", this_lex->l_type);
						goto lexpr_new_error;
						break;
				}
				break;
			default:
				//				post("bad lexeme");
				goto lexpr_new_error;
				break;
		}
	}
	
	while (lexstack_ptr >= lexstack) {
		if ((*lexstack_ptr)->l_type == L_OPEN || (*lexstack_ptr)->l_type == L_CLOSED) {
			//			post("we have a parenthesis after shunting yard");
			goto lexpr_new_error;
		} else {
			*tokqueue_ptr = (*lexstack_ptr--)->l_token;
			chk = lexpr_check(tokqueue_ptr++, chk);
			if (chk < 0) {
				//				post("checksum < 0");
				goto lexpr_new_error;
			}
		}
	}
	if (chk != 1) {
		//		post("checksum != 1");
		goto lexpr_new_error;
	}
	
	tokqueue_last = tokqueue_ptr - 1;
	
	// constant folding
	
	do {
		again = 0;
		tokqueue_ptr = tokqueue_last;
		while (tokqueue_ptr > tokqueue) {
			while (tokqueue_ptr > tokqueue && tokqueue_ptr->t_type != TT_OP && (tokqueue_ptr->t_type != TT_FUNC || tokqueue_ptr->t_contents.c_func.f_dontfold))
				tokqueue_ptr--;		// find the next function or operator (going backwards!)
			
			if (tokqueue_ptr == tokqueue)
				break;
			
			nextarg = tokqueue_ptr - 1;	// its first argument
			
			if (nextarg->t_type == TT_HATOM) {	// if its first argument is an atom
				switch(tokqueue_ptr->t_operands) {	
					case 1:	// and it has one only operand
						err |= lexpr_eval_one(tokqueue_ptr, &nextarg->t_contents.c_hatom, NULL, &result_hatom); // then simply evaluate it
						nextarg->t_type = TT_HATOM;
						nextarg->t_contents.c_hatom = result_hatom;
						sysmem_copyptr(tokqueue_ptr + 1, tokqueue_ptr, (tokqueue_last - tokqueue_ptr) * sizeof(t_lexpr_token)); // and substitute func/op and operand with the result 
						tokqueue_last--;
						tokqueue_ptr = nextarg - 1;
						again = 1;
						break;
						
					case 2:	// if it has two operands
						nextarg2 = nextarg - 1;
						if (nextarg2->t_type == TT_HATOM) { // both operands are atoms, as in 1 2 +
							err |= lexpr_eval_one(tokqueue_ptr, &nextarg2->t_contents.c_hatom, &nextarg->t_contents.c_hatom, &result_hatom); // evaluate
							nextarg2->t_type = TT_HATOM;
							nextarg2->t_contents.c_hatom = result_hatom;
							sysmem_copyptr(tokqueue_ptr + 1, nextarg, (tokqueue_last - tokqueue_ptr) * sizeof(t_lexpr_token)); // and substitute func/op and operands with the result
							tokqueue_last -= 2;
							tokqueue_ptr = nextarg2 - 1;
							again = 1;				
						} else if (nextarg2->t_type == TT_OP && (nextarg2->t_contents.c_op.o_properties & OP_ASSOC)) { // the second argument is an associative operator
							if (nextarg2->t_contents.c_op.o_op == tokqueue_ptr->t_contents.c_op.o_op) { // the two operators are the same
								if ((nextarg2-1)->t_type == TT_HATOM) { // the first argument of the second operator is an atom: x 2 + 3 + (we don't care about what x is)
									temp_tok = *nextarg;	// we swap the second operator and its first operand, so that it becomes x + 2 3 +
									*nextarg = *nextarg2;	
									*nextarg2 = temp_tok;
									again = 1;				// in this way, on the next tour 2 3 + will be folded
								} else if ((nextarg2-1)->t_type == TT_VAR && ((nextarg2-2)->t_type == TT_HATOM && (nextarg2->t_contents.c_op.o_properties & OP_COMM))) {
									// the first argument of the second operator is a variable, the second argument is an atom and the second operator is commutative: 2 $x1 + 3 +
									temp_tok = *(nextarg2-2);	// we swap the two operands, so that it becomes $x1 2 + 3 +
									*(nextarg2-2) = *(nextarg2-1);
									*(nextarg2-1) = temp_tok;
									again = 1;				// in this way, it will fall in the previous case on the next tour
								} else
									tokqueue_ptr = nextarg - 1;	// if none of these conditions is true, we have nothing to do for now
							} else if (tokqueue_ptr->t_contents.c_op.o_properties == OP_INVERT && nextarg2->t_contents.c_op.o_op == tokqueue_ptr->t_contents.c_op.o_inv) {
								// if the first operator is invertible, and it inverts to the second operator: x x + 2 - 
								lexpr_invert(tokqueue_ptr, nextarg); // we invert operator and operand (it becomes x x + -2 +)
								again = 1; // and we repeat
							} else
								tokqueue_ptr = nextarg - 1;
						} else
							tokqueue_ptr = nextarg - 1;
						break;
				}
			} else
				tokqueue_ptr = nextarg;
		}
	} while (again /* && !err*/);
	/*	
	 if (err) {
	 //		post("constant folding aborted");
	 goto lexpr_new_error;
	 }
	 */	
	/*
	 post("-----");
	 for (tokqueue_ptr = tokqueue; tokqueue_ptr <= tokqueue_last; tokqueue_ptr++) {
	 switch (tokqueue_ptr->t_type) {
	 case TT_OP:
	 post("operator %d with %d operands", tokqueue_ptr->t_contents.c_op.o_op, tokqueue_ptr->t_operands);
	 break;
	 case TT_FUNC:
	 post("function %p with %d operands", tokqueue_ptr->t_contents.c_func.f_ptrs.p_dptr, tokqueue_ptr->t_operands);
	 break;
	 case TT_HATOM:
	 switch (tokqueue_ptr->t_contents.c_hatom.h_type) {
	 case H_LONG:
	 post("long %ld", tokqueue_ptr->t_contents.c_hatom.h_w.w_long);
	 break;
	 case H_DOUBLE:
	 post("double %f", tokqueue_ptr->t_contents.c_hatom.h_w.w_double);
	 break;
	 case H_RAT:
	 post("rational %ld/%ld", tokqueue_ptr->t_contents.c_hatom.h_w.w_rat.r_num, tokqueue_ptr->t_contents.c_hatom.h_w.w_rat.r_den);
	 break;
	 }
	 break;
	 case TT_VAR:
	 post("var type %d num %d", tokqueue_ptr->t_contents.c_var.v_type, tokqueue_ptr->t_contents.c_var.v_index);
	 break;
	 case TT_NONE:
	 post("none");
	 break;
	 default:
	 post("unknown: %d", tokqueue_ptr->t_type);
	 break;
	 }
	 }
	 */	
	this_lexpr->l_size = tokqueue_last - tokqueue + 1;
	this_lexpr->l_numvars = numvars;
	this_lexpr->l_tokens = (t_lexpr_token *) bach_resizeptr(tokqueue, this_lexpr->l_size * sizeof(t_lexpr_token));
	bach_freeptr(lexs);
	bach_freeptr(lexstack);
	//	post("returning");
	return MAX_ERR_NONE;
	
lexpr_new_error:
	bach_freeptr(lexs);
	bach_freeptr(lexstack);
	return MAX_ERR_GENERIC;
}

t_hatom *lexpr_eval(t_lexpr *expr, t_hatom *vars)
{
	long i = expr->l_size;
	t_hatom *stack = (t_hatom *) bach_newptr(L_MAX_TOKENS * sizeof(t_hatom));
	t_lexpr_token *thistok;
	t_hatom *thisstack = stack;
	t_hatom *this_vars;
	long stop_it = 0;
	for (i = 0, thistok = expr->l_tokens; !stop_it && i < expr->l_size; i++, thistok++) {
		switch (thistok->t_type) {
			case TT_HATOM:
				*thisstack++ = thistok->t_contents.c_hatom;
				break;
			case TT_VAR:
				this_vars = vars + thistok->t_contents.c_var.v_index;
				if (hatom_gettype(this_vars) != H_NOTHING) {
					switch (thistok->t_contents.c_var.v_type) {
						case H_ALL:
							*thisstack++ = *this_vars;
							break;
						case H_LONG:
							hatom_setlong(thisstack++, hatom_getlong(this_vars));
							break;
						case H_RAT:
							hatom_setrational(thisstack++, hatom_getrational(this_vars));
							break;
						case H_DOUBLE:
							hatom_setdouble(thisstack++, hatom_getdouble(this_vars));
							break;
					}
				} else
					stop_it = 1;
				break;
			case TT_OP:
			case TT_FUNC:
				if (thistok->t_operands == 1)
					lexpr_eval_one(thistok, thisstack - 1, NULL, thisstack - 1);
				else {
					lexpr_eval_one(thistok, thisstack - 2, thisstack - 1, thisstack - 2);
					thisstack--;
				}
				break;
			default:
				break;
		}
	}
	if (stop_it) {
		bach_freeptr(stack);
		return NULL;
	} else
		return stack;
}

long lexpr_eval_one(const t_lexpr_token *verb, t_hatom *h1, t_hatom *h2, t_hatom *res)
{	
	if (verb->t_type == TT_FUNC) {
		if (!h2) {
			if (!(hatom_is_number(h1)))
				*res = *h1;
			else 
				switch (verb->t_contents.c_func.f_type) {
					case H_DOUBLE:	hatom_setdouble(res, (verb->t_contents.c_func.f_ptrs.p_dptr_d)(hatom_getdouble(h1)));	break;
					case H_ALL:		(verb->t_contents.c_func.f_ptrs.p_vptr_hh)(h1, res);	break;
				}
		} else { 
			if (!(hatom_is_number(h1)))
				*res = *h1;
			else if (!(hatom_is_number(h2)))
				*res = *h2;
			else 
				switch (verb->t_contents.c_func.f_type) {
					case H_DOUBLE:	hatom_setdouble(res, (verb->t_contents.c_func.f_ptrs.p_dptr_dd)(hatom_getdouble(h1), hatom_getdouble(h2)));	break;
					case H_ALL:		(verb->t_contents.c_func.f_ptrs.p_vptr_hhh)(h1, h2, res);	break;
				}
		} 
		return errno;
	}
	
	switch (verb->t_contents.c_op.o_op) {
		case O_UMINUS:
			hatom_op_uminus(h1, res);
			return 0;			
			break;
			
		case O_PLUS:
			hatom_op_plus(h1, h2, res);
			return 0;
			break;
			
		case O_MINUS:
			hatom_op_minus(h1, h2, res);
			return 0;
			break;	
			
		case O_TIMES:
			hatom_op_times(h1, h2, res);
			return 0;
			break;
			
		case O_DIVDIV:
			hatom_op_divdiv(h1, h2, res);
			return 0;
			break;	
			
		case O_DIV:
			hatom_op_div(h1, h2, res);
			return 0;
			break;
			
		case O_MOD:
            hatom_fn_remainder(h1, h2, res);
            return 0;
			break;
			
		case O_POW:
			hatom_op_pow(h1, h2, res);
			return 0;
			break;
			
		case O_LOGAND:
			hatom_op_logand(h1, h2, res);
			return 0;
			break;
			
		case O_LOGOR:
			hatom_op_logor(h1, h2, res);
			return 0;
			break;
			
		case O_LOGXOR:
			hatom_op_logxor(h1, h2, res);
			return 0;
			break;
			
		case O_LOGNOT:
			hatom_op_lognot(h1, res);
			return 0;
			break;
			
		case O_BITAND:
			hatom_op_bitand(h1, h2, res);
			return 0;
			break;
			
		case O_BITOR:
			hatom_op_bitor(h1, h2, res);
			return 0;
			break;
			
		case O_BITXOR:
			hatom_op_bitxor(h1, h2, res);
			return 0;
			break;
			
		case O_BITNOT:
			hatom_op_bitnot(h1, res);
			return 0;
			break;
			
		case O_LSHIFT:
			hatom_op_lshift(h1, h2, res);
			return 0;
			break;
			
		case O_RSHIFT:
			hatom_op_rshift(h1, h2, res);
			return 0;
			break;
			
		case O_EQ:
			hatom_op_eq(h1, h2, res);
			return 0;
			break;
			
		case O_EQMATCH:
			hatom_op_eqmatch(h1, h2, res);
			return 0;
			break;
			
		case O_NEQ:
			hatom_op_neq(h1, h2, res);
			return 0;
			break;
			
		case O_NEQMATCH:
			hatom_op_neqmatch(h1, h2, res);
			return 0;
			break;
			
		case O_GT:
			hatom_op_gt(h1, h2, res);
			return 0;
			break;
			
		case O_GE:
			hatom_op_ge(h1, h2, res);
			return 0;
			break;			
			
		case O_LT:
			hatom_op_lt(h1, h2, res);
			return 0;
			break;
			
			
		case O_LE:
			hatom_op_le(h1, h2, res);
			return 0;
			break;	
			
	}	
	return 0;
}


/*
 OPERATOR PRECEDENCE AND ORDER OF EVALUATION:
 14	! ~ ++ -- + - * (type) sizeof right to left
 13	** right to left
 12	* / % // left to right
 11	+ - left to right
 10	<< >> left to right
 9	< <= > >= left to right
 8	== != left to right
 7	& left to right
 6	^ left to right
 5	| left to right
 4	&& left to right
 3	^^ left to right
 2	|| left to right
 1	?: right to left
 0	= += -= *= /= %= &= ^= |= <<= >>= right to left
 */

// writes the new lexeme into lex
t_max_err lexpr_lex(char *this_pos, char **next_pos, t_lexpr_lexeme *lex, short *numvars, long subs_count, const char **substitutions)
{
	long len;
	long idx, vartype;
	
	while (isspace(*this_pos))
		this_pos++;

	*next_pos = this_pos;
	
	if (!*this_pos) {
		lex->l_type = L_SKIP;
		*next_pos = NULL;
		return MAX_ERR_NONE;
	}
	
	// parentheses	
	if (*this_pos == '(') {
		lex->l_type = L_OPEN;
		++*next_pos;
		return MAX_ERR_NONE;
		
	} else if (*this_pos == ')') {
		lex->l_type = L_CLOSED;
		++*next_pos;
		return MAX_ERR_NONE;
		
		// comma
	} else if (*this_pos == ',') {
		lex->l_type = L_COMMA;
		++*next_pos;
		return MAX_ERR_NONE;
		
		// variables
	} else if (*this_pos == '$') {
		lex->l_type = L_TOKEN;
		lex->l_token.t_type = TT_VAR;
		switch (*(this_pos + 1)) {
			case 'i':	vartype = H_LONG;		break;
			case 'f':	vartype = H_DOUBLE;		break;
			case 'r':	vartype = H_RAT;		break;
			case 'x':	vartype = H_ALL;		break;
			default:	dev_post("bad var type: %c", *(this_pos + 1));	return MAX_ERR_GENERIC;	break;
		}
		
		idx = strtol(this_pos + 2, next_pos, 10) - 1;
		if (idx == -1) {
			dev_post ("bad var index %ld", idx);
			return MAX_ERR_GENERIC;
		}
		
		lex->l_token.t_contents.c_var.v_index = idx;
		if (idx >= *numvars)
			*numvars = idx + 1;
		lex->l_token.t_contents.c_var.v_type = vartype;
		return MAX_ERR_NONE;
		
		// operators
	} else if (*this_pos == '|') {
		lex->l_type = L_TOKEN;
		lex->l_order = O_L2R;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 2; 
		lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
		if (*(this_pos + 1) == '|') {
			lex->l_precedence = 2;
			lex->l_token.t_contents.c_op.o_op = O_LOGOR;
			*next_pos = this_pos + 2;
		} else {
			lex->l_precedence = 5;
			lex->l_token.t_contents.c_op.o_op = O_BITOR;
			*next_pos = this_pos + 1;
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '&') {
		lex->l_type = L_TOKEN;
		lex->l_order = O_L2R;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 2;
		lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
		if (*(this_pos + 1) == '&') {
			lex->l_precedence = 4;
			lex->l_token.t_contents.c_op.o_op = O_LOGAND;
			*next_pos = this_pos + 2;
		} else {
			lex->l_precedence = 7;
			lex->l_token.t_contents.c_op.o_op = O_BITAND;
			*next_pos = this_pos + 1;
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '^') {
		lex->l_type = L_TOKEN;
		lex->l_order = O_L2R;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 2;
		lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
		if (*(this_pos + 1) == '^') {
			lex->l_precedence = 3;
			lex->l_token.t_contents.c_op.o_op = O_LOGXOR;
			*next_pos = this_pos + 2;
		} else {
			lex->l_precedence = 6;
			lex->l_token.t_contents.c_op.o_op = O_BITXOR;
			*next_pos = this_pos + 1;
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '~') {
		lex->l_type = L_TOKEN;
		lex->l_precedence = 14;
		lex->l_order = O_R2L;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 1;
		lex->l_token.t_contents.c_op.o_op = O_BITNOT;
		*next_pos = this_pos + 1;
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '!') {
		lex->l_type = L_TOKEN;
		lex->l_token.t_type = TT_OP;
		if (*(this_pos + 1) == '=') {
			lex->l_token.t_operands = 2;
			lex->l_precedence = 8;
			lex->l_order = O_L2R;
			lex->l_token.t_contents.c_op.o_properties = OP_COMM;
			if (*(this_pos + 2) == '=') {
				lex->l_token.t_contents.c_op.o_op = O_NEQMATCH;
				*next_pos = this_pos + 3;
			} else {
				lex->l_token.t_contents.c_op.o_op = O_NEQ;
				*next_pos = this_pos + 2;
			}
			return MAX_ERR_NONE;
		} else {
			lex->l_token.t_operands = 1;			
			lex->l_precedence = 14;
			lex->l_order = O_R2L;
			lex->l_token.t_contents.c_op.o_op = O_LOGNOT;
			*next_pos = this_pos + 1;
			return MAX_ERR_NONE;
		}
		
	} else if (*this_pos == '=' && *(this_pos + 1) == '=') {
		lex->l_type = L_TOKEN;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 2;
		lex->l_precedence = 8;
		lex->l_order = O_L2R;
		lex->l_token.t_contents.c_op.o_properties = OP_COMM;
		if (*(this_pos + 2) == '=') {
			lex->l_token.t_contents.c_op.o_op = O_EQMATCH;
			*next_pos = this_pos + 3;
		} else {
			lex->l_token.t_contents.c_op.o_op = O_EQ;
			*next_pos = this_pos + 2;
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '<') {
		lex->l_type = L_TOKEN;
		lex->l_token.t_type = TT_OP;	
		lex->l_token.t_operands = 2;
		lex->l_token.t_contents.c_op.o_properties = OP_NONE;
		lex->l_order = O_L2R;
		switch (*(this_pos + 1)) {
			case '<':
				lex->l_precedence = 10;
				lex->l_token.t_contents.c_op.o_op = O_LSHIFT;
				*next_pos = this_pos + 2;			
				break;
			case '=':
				lex->l_precedence = 9;
				lex->l_token.t_contents.c_op.o_op = O_LE;
				*next_pos = this_pos + 2;			
				break;
			default:
				lex->l_precedence = 9;
				lex->l_token.t_contents.c_op.o_op = O_LT;
				*next_pos = this_pos + 1;	
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '>') {
		lex->l_type = L_TOKEN;
		lex->l_token.t_type = TT_OP;	
		lex->l_token.t_operands = 2;
		lex->l_token.t_contents.c_op.o_properties = OP_NONE;
		lex->l_order = O_L2R;
		switch (*(this_pos + 1)) {
			case '>':
				lex->l_precedence = 10;
				lex->l_token.t_contents.c_op.o_op = O_RSHIFT;
				*next_pos = this_pos + 2;			
				break;
			case '=':
				lex->l_precedence = 9;
				lex->l_token.t_contents.c_op.o_op = O_GE;
				*next_pos = this_pos + 2;			
				break;
			default:
				lex->l_precedence = 9;
				lex->l_token.t_contents.c_op.o_op = O_GT;
				*next_pos = this_pos + 1;	
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '*') {
		lex->l_type = L_TOKEN;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 2;
		if (*(this_pos+1) == '*') {
			lex->l_precedence = 13;
			lex->l_order = O_L2R;			
			lex->l_token.t_contents.c_op.o_properties = OP_NONE;
			lex->l_token.t_contents.c_op.o_op = O_POW;
			*next_pos = this_pos + 2;
		} else {
			lex->l_precedence = 12;
			lex->l_order = O_L2R;		
			lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
			lex->l_token.t_contents.c_op.o_op = O_TIMES;
			*next_pos = this_pos + 1;
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '%') {
		lex->l_type = L_TOKEN;
		lex->l_precedence = 12;
		lex->l_order = O_L2R;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 2;
		lex->l_token.t_contents.c_op.o_properties = OP_NONE;
		lex->l_token.t_contents.c_op.o_op = O_MOD;
		*next_pos = this_pos + 1;
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '/') {
		lex->l_type = L_TOKEN;
		lex->l_precedence = 12;
		lex->l_order = O_L2R;
		lex->l_token.t_type = TT_OP;
		lex->l_token.t_operands = 2;
		
		if (*(this_pos + 1) == '/') {
			lex->l_token.t_contents.c_op.o_properties = OP_NONE;
			lex->l_token.t_contents.c_op.o_op = O_DIVDIV;
			*next_pos = this_pos + 2;
		} else {
			lex->l_token.t_contents.c_op.o_properties = OP_INVERT;
			lex->l_token.t_contents.c_op.o_op = O_DIV;
			lex->l_token.t_contents.c_op.o_inv = O_TIMES;
			*next_pos = this_pos + 1;
		}
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '+') {
		if ((lex-1)->l_type == L_CLOSED || ((lex-1)->l_type == L_TOKEN && (lex-1)->l_token.t_type != TT_OP && (lex-1)->l_token.t_type != TT_FUNC)) { // if it's a binary +
			lex->l_type = L_TOKEN;
			lex->l_precedence = 11;
			lex->l_order = O_L2R;
			lex->l_token.t_type = TT_OP;
			lex->l_token.t_operands = 2;
			lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
			lex->l_token.t_contents.c_op.o_op = O_PLUS;
		} else
			lex->l_type = L_SKIP;
		*next_pos = this_pos + 1;
		return MAX_ERR_NONE;
		
	} else if (*this_pos == '-') {
		lex->l_type = L_TOKEN;
		if ((lex-1)->l_type == L_CLOSED || ((lex-1)->l_type == L_TOKEN && (lex-1)->l_token.t_type != TT_OP && (lex-1)->l_token.t_type != TT_FUNC)) {
			lex->l_precedence = 11;
			lex->l_order = O_L2R;
			lex->l_token.t_type = TT_OP;
			lex->l_token.t_operands = 2;
			lex->l_token.t_contents.c_op.o_properties = OP_INVERT;
			lex->l_token.t_contents.c_op.o_op = O_MINUS;
			lex->l_token.t_contents.c_op.o_inv = O_PLUS;
			*next_pos = this_pos + 1;
			return MAX_ERR_NONE;
		} else {
			lex->l_precedence = 14;
			lex->l_order = O_R2L;
			lex->l_token.t_type = TT_OP;
			lex->l_token.t_operands = 1;
			lex->l_token.t_contents.c_op.o_properties = OP_NONE;
			lex->l_token.t_contents.c_op.o_op = O_UMINUS;
			*next_pos = this_pos + 1;
			return MAX_ERR_NONE;
		}
	}
	
	// substitutions and functions
	if (isalpha(*this_pos)) {
		char *temp;
		lex->l_type = L_TOKEN;
		lex->l_token.t_type = TT_FUNC;
		
		for (len = 0, temp = this_pos; 
			 len < LEXPR_MAX_SUBSTITUTION_LENGTH && *temp && (isalnum(*temp) || *temp == '_'); 
			 temp++)
			len++;
		
		if (len == LEXPR_MAX_SUBSTITUTION_LENGTH) { // why || !*temp?!? 
			dev_post("expr: bad token %s", this_pos);
			return MAX_ERR_GENERIC;
		}
		*next_pos = this_pos + len;
		
		
		// it's a substitution
		for (idx = 0; idx < subs_count; idx++) {
			if (!strncmp(this_pos, substitutions[idx], len)) {
				lex->l_type = L_TOKEN;
				lex->l_token.t_type = TT_VAR;
				lex->l_token.t_contents.c_var.v_type = H_ALL;
				lex->l_token.t_contents.c_var.v_index = idx;
				if (idx >= *numvars)
					*numvars = idx + 1;
				return MAX_ERR_NONE;
			}
		}
		
		switch (len) { // this should be a quite important optimization, by avoiding a lot of ifs and strcmps
			case 3:
				if (!strncmp(this_pos, "cos", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &cos;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "sin", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &sin;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "tan", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &tan;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "exp", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &exp;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "log", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &log;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "pow", 3)) {
					lex->l_token.t_operands = 2;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hhh = &hatom_fn_pow;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "int", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = &hatom_fn_int;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "rat", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = &hatom_fn_rat;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "num", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = &hatom_fn_num;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "den", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = &hatom_fn_den;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "abs", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = &hatom_fn_abs;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "sgn", 3)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = &hatom_fn_sgn;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "mod", 3)) {
					lex->l_token.t_operands = 2;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hhh = &hatom_fn_mod;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				dev_post("bad function: %s", this_pos);
				return MAX_ERR_GENERIC;
				break;				
				
			case 4:
				if (!strncmp(this_pos, "acos", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &acos;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "asin", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &asin;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "atan", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &atan;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "cosh", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &cosh;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "sinh", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &sinh;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "tanh", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &tanh;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "exp2", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &exp2;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "log2", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &log2;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				} 
				if (!strncmp(this_pos, "sqrt", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &sqrt;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "ceil", 4)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &ceil;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "fmod", 4)) {
					lex->l_token.t_operands = 2;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_dd = &fmod;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				dev_post("bad function: %s", this_pos);
				return MAX_ERR_GENERIC;
				break;					
				
			case 5:
				if (!strncmp(this_pos, "atan2", 5)) {
					lex->l_token.t_operands = 2;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_dd = &atan2;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "acosh", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &acosh;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "asinh", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &asinh;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "atanh", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &atanh;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "log10", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &log10;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "hypot", 5)) {
					lex->l_token.t_operands = 2;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_dd = &hypot;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "floor", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &floor;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "round", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &round;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "trunc", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = &trunc;
					lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "float", 5)) {
					lex->l_token.t_operands = 1;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = &hatom_fn_float;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				dev_post("bad function: %s", this_pos);
				return MAX_ERR_GENERIC;
				break;
				
			case 6:
				if (!strncmp(this_pos, "random", 6)) {
					lex->l_token.t_operands = 2;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hhh = &hatom_fn_random;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					lex->l_token.t_contents.c_func.f_dontfold = 1;
					return MAX_ERR_NONE;
				}
				if (!strncmp(this_pos, "bessel", 6)) {
					lex->l_token.t_operands = 2;
					lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hhh = &hatom_fn_jn;
					lex->l_token.t_contents.c_func.f_type = H_ALL;
					return MAX_ERR_NONE;
				}
				dev_post("bad function: %s", this_pos);
				return MAX_ERR_GENERIC;
				break;
			default:
				dev_post("bad function: %s", this_pos);
				return MAX_ERR_GENERIC;
				break;
		}
	}
	
	// constants
	
	if (*this_pos == '.' || isdigit(*this_pos)) {
		char is_float = 0;
		double d_res;
		char *temp;
		lex->l_type = L_TOKEN;
		errno = 0;
		d_res = strtod(this_pos, next_pos);
		if (*next_pos == this_pos) // this happens if it's only a .
			*next_pos = this_pos + 1;
		if (errno == EINVAL) {
			dev_post("bad constant: %s", this_pos);
			return MAX_ERR_GENERIC;
		}
		lex->l_token.t_type = TT_HATOM;
		for (temp = this_pos; temp < *next_pos && !is_float; temp ++)
			is_float = (*temp == '.') || (*temp == 'e') || (*temp == 'E');
		if (is_float) {
			lex->l_token.t_contents.c_hatom.h_type = H_DOUBLE;
			lex->l_token.t_contents.c_hatom.h_w.w_double = d_res;
		} else {
			lex->l_token.t_contents.c_hatom.h_type = H_LONG;
			lex->l_token.t_contents.c_hatom.h_w.w_long = strtol(this_pos, next_pos, 10);	
		}
		
		return MAX_ERR_NONE;
	}
	//	post("the end of lex");
	return MAX_ERR_GENERIC;
}

long lexpr_invert(t_lexpr_token *verb, t_lexpr_token *arg2) 
{
	long l;
	t_rational r;
	switch ((int)verb->t_contents.c_op.o_op) {
		case O_MINUS:
			verb->t_contents.c_op.o_op = O_PLUS;
			verb->t_contents.c_op.o_properties = OP_ASSOC | OP_COMM;
			switch (hatom_gettype(&arg2->t_contents.c_hatom)) {
				case H_LONG:
					arg2->t_contents.c_hatom.h_w.w_long *= -1;
					break;
				case H_RAT:
					arg2->t_contents.c_hatom.h_w.w_rat.r_num *= -1;
					break;
				case H_DOUBLE:
					arg2->t_contents.c_hatom.h_w.w_double *= -1.;
					break;
			}
			break;
		case O_DIV:
			verb->t_contents.c_op.o_op = O_TIMES;
			verb->t_contents.c_op.o_properties = OP_ASSOC | OP_COMM;
			switch (hatom_gettype(&arg2->t_contents.c_hatom)) {
				case H_LONG:
					l = arg2->t_contents.c_hatom.h_w.w_long;
					if (l > 1) {
						arg2->t_contents.c_hatom.h_type = H_RAT;
						arg2->t_contents.c_hatom.h_w.w_rat.r_num = 1;
						arg2->t_contents.c_hatom.h_w.w_rat.r_den = l;
					} else if (l < -1) {
						arg2->t_contents.c_hatom.h_type = H_RAT;
						arg2->t_contents.c_hatom.h_w.w_rat.r_num = -1;
						arg2->t_contents.c_hatom.h_w.w_rat.r_den = -l;				
					}
					break;
				case H_RAT:
					r = hatom_getrational(&arg2->t_contents.c_hatom);
					hatom_setrational_from_elems(&arg2->t_contents.c_hatom, r.r_den, r.r_num);
					break;
				case H_DOUBLE:
					arg2->t_contents.c_hatom.h_w.w_double = 1. / arg2->t_contents.c_hatom.h_w.w_double;
					break;
			}
			break;	
	}
	return MAX_ERR_NONE;
}

long lexpr_check(t_lexpr_token *tok, long chk) 
{
	if (tok->t_type == TT_HATOM || tok->t_type == TT_VAR)
		return chk;
	else 
		return chk - tok->t_operands + 1; // that is, it is an op or a func (no NULLS are put in)
}
