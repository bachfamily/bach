/*
 *  llll_expr_commons.c
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

#include "ext.h"
#include "ext_obex.h"
#include "ext_systhread.h"
#include "ext_common.h"
#include "foundation/llll_commons.h"
#include "math/llll_math.h"
#include "parsers/exprparser/exprparser.h"

#define YY_HEADER_EXPORT_START_CONDITIONS
#define YY_NO_UNISTD_H
#include "bach_exprparser_lex.h"

#ifdef WIN_VERSION
#include <errno.h>
#endif


t_lexpr *lexpr_new(short ac, t_atom *av, long subs_count, const char **substitutions, t_object *culprit)
{
    t_lexpr *x;
    /*
     if (!(x = object_alloc_debug(lexpr_class))) {
     //		post("can't allocate lexpr");
     return NULL;
     }
     */
    x = lexpr_alloc();
    if (lexpr_init(x, ac, av, subs_count, substitutions, culprit) != MAX_ERR_NONE) {
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
t_max_err lexpr_init(t_lexpr *this_lexpr, short ac, t_atom *av, long subs_count, const char **substitutions, t_object *culprit)
{
    t_lexpr_lexeme *this_lex, **lexstack_ptr;
    t_lexpr_lexeme *lexs, **lexstack;
    t_lexpr_token *tokqueue, *tokqueue_ptr, *this_lex_token, *tokqueue_last, *nextarg, *nextarg2, *nextarg3, temp_tok;
    int i, lexc = 0;
    long chk = 0;
    short numvars = 0;
    char again;
    t_hatom result_hatom;
    t_atom_long err;
    t_exprparser_data exprparser_data;
    char *offending;
    
    //	post("creating lexpr");
    
    
    if (!(this_lexpr->l_tokens = (t_lexpr_token *) bach_newptrclear(L_MAX_TOKENS * sizeof(t_lexpr_token)))) {
        //		post("can't allocate tokens");
        return MAX_ERR_GENERIC;
    }
    if (!(lexs = (t_lexpr_lexeme *) bach_newptrclear((L_MAX_LEXEMES + 1) * sizeof(t_lexpr_lexeme)))) {
        return MAX_ERR_GENERIC;
    }
    if (!(lexstack = (t_lexpr_lexeme **) bach_newptrclear(L_MAX_LEXEMES * sizeof(t_lexpr_lexeme *)))) {
        bach_freeptr(lexs);
        return MAX_ERR_GENERIC;
    }
    
    
    
    exprparser_data.numvars = &numvars;
    exprparser_data.subs_count = subs_count;
    exprparser_data.substitutions = substitutions;
    exprparser_data.offending = &offending;
    
    t_exprParser exprParser(&exprparser_data);
    
    
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
            case A_SYM: {
                exprParser.setBuffer(atom_getsym(av)->s_name);
                exprparser_data.lexeme = this_lex;
                while (long err = exprParser.lex()) {
                    switch (err) {
                        case E_OK:
                            this_lex++;
                            lexc++;
                            exprparser_data.lexeme = this_lex;
                            break;
                        case E_BAD_VAR_TYPE:
                            object_error(culprit, "Bad variable: %s", exprparser_data.offending);
                            bach_freeptr(*exprparser_data.offending);
                            goto lexpr_new_error;
                            break;
                        case E_BAD_NAME:
                            object_error(culprit, "Bad name: %s", *exprparser_data.offending);
                            bach_freeptr(*exprparser_data.offending);
                            goto lexpr_new_error;
                            break;
                        case E_BAD_EXPR:
                            object_error(culprit, "Bad expression");
                            goto lexpr_new_error;
                            break;
                    }
                }
                exprParser.reset();
            }
        }
        
        long ltype = (this_lex - 1)->l_type;
        if (ltype == L_COMMA || ltype == L_OPEN ||
            (ltype == L_TOKEN && (this_lex - 1)->l_token.t_type == TT_OP))
            exprParser.setStartCondition(INITIAL);
        else
            exprParser.setStartCondition(BINARY);

        if (lexc >= L_MAX_LEXEMES) {
            object_error(culprit, "Expression is too long");
            goto lexpr_new_error;
        }
    }
    
    err = lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(this_lex - 1, subs_count, substitutions, &numvars, exprparser_data.offending);
    
    switch (err) {
            case E_OK:
                break;
            case E_BAD_VAR_TYPE:
                object_error(culprit, "Bad variable: %s", exprparser_data.offending);
                bach_freeptr(*exprparser_data.offending);
                goto lexpr_new_error;
                break;
            case E_BAD_NAME:
                object_error(culprit, "Bad name: %s", *exprparser_data.offending);
                bach_freeptr(*exprparser_data.offending);
                goto lexpr_new_error;
                break;
            case E_BAD_EXPR:
                object_error(culprit, "Bad expression");
                goto lexpr_new_error;
                break;
    }

    lexstack_ptr = lexstack - 1; // always points to the last valid argument
    tokqueue_ptr = tokqueue;
    //	post("SHUNTING-YARD:");
    
    // the shunting-yard algorithm! (plus some error checking)
    // http://en.wikipedia.org/wiki/Shunting-yard_algorithm
    
    for (i = 0, this_lex = lexs + 1, err = MAX_ERR_NONE;
         i < lexc && err == MAX_ERR_NONE;
         i++, this_lex++) {
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
                        err |= lexpr_eval_one(tokqueue_ptr, &nextarg->t_contents.c_hatom, NULL, NULL, &result_hatom); // then simply evaluate it
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
                            err |= lexpr_eval_one(tokqueue_ptr, &nextarg2->t_contents.c_hatom, &nextarg->t_contents.c_hatom, NULL, &result_hatom); // evaluate
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
                        
                    case 3: // if it has three operands (the only case for now is makepitch)
                        nextarg2 = nextarg - 1;
                        nextarg3 = nextarg - 2;
                        if (nextarg2->t_type == TT_HATOM && nextarg3->t_type == TT_HATOM) { // all three operands are hatoms
                            err |= lexpr_eval_one(tokqueue_ptr, &nextarg3->t_contents.c_hatom, &nextarg2->t_contents.c_hatom, &nextarg->t_contents.c_hatom, &result_hatom); // evaluate
                            nextarg3->t_type = TT_HATOM;
                            nextarg3->t_contents.c_hatom = result_hatom;
                            sysmem_copyptr(tokqueue_ptr + 1, nextarg, (tokqueue_last - tokqueue_ptr) * sizeof(t_lexpr_token)); // and substitute func/op and operands with the result
                            tokqueue_last -= 3;
                            tokqueue_ptr = nextarg3 - 1;
                            again = 1;
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
    t_hatom *stack = (t_hatom *) bach_newptr(L_MAX_TOKENS * sizeof(t_hatom));
    if (lexpr_eval_upon(expr, vars, stack)) {
        bach_freeptr(stack);
        return NULL;
    } else
        return stack;
}

// stack must be an allocated array of hatoms, of size L_MAX_TOKENS
t_bool lexpr_eval_upon(t_lexpr *expr, t_hatom *vars, t_hatom *stack)
{
    int i;
    t_lexpr_token *thistok;
    t_hatom *thisstack = stack;
    t_hatom *this_vars;
    t_bool err = false;
    for (i = 0, thistok = expr->l_tokens; !err && i < expr->l_size; i++, thistok++) {
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
                        case H_PITCH:
                            hatom_setpitch(thisstack++, hatom_getpitch(this_vars));
                            break;
                        case H_DOUBLE:
                            hatom_setdouble(thisstack++, hatom_getdouble(this_vars));
                            break;
                    }
                } else
                    err = true;
                break;
            case TT_OP:
            case TT_FUNC:
                switch (thistok->t_operands) {
                    case 1:
                        lexpr_eval_one(thistok, thisstack - 1, NULL, NULL, thisstack - 1);
                        break;
                    case 2:
                        lexpr_eval_one(thistok, thisstack - 2, thisstack - 1, NULL, thisstack - 2);
                        thisstack--;
                        break;
                    case 3:
                        lexpr_eval_one(thistok, thisstack - 3, thisstack - 2, thisstack - 1, thisstack - 3);
                        thisstack -= 2;
                        break;
                }
                break;
            default:
                break;
        }
    }
    return err;
}

long lexpr_eval_one(const t_lexpr_token *verb, t_hatom *h1, t_hatom *h2, t_hatom *h3, t_hatom *res)
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
        } else if (!h3) {
            if (!(hatom_is_number(h1)))
                *res = *h1;
            else if (!(hatom_is_number(h2)))
                *res = *h2;
            else
                switch (verb->t_contents.c_func.f_type) {
                    case H_DOUBLE:	hatom_setdouble(res, (verb->t_contents.c_func.f_ptrs.p_dptr_dd)(hatom_getdouble(h1), hatom_getdouble(h2)));	break;
                    case H_ALL:		(verb->t_contents.c_func.f_ptrs.p_vptr_hhh)(h1, h2, res);	break;
                }
        } else {
            if (!(hatom_is_number(h1)))
                *res = *h1;
            else if (!(hatom_is_number(h2)))
                *res = *h2;
            else if (!(hatom_is_number(h3)))
                *res = *h3;
            else
                switch (verb->t_contents.c_func.f_type) {
                    case H_DOUBLE:	hatom_setdouble(res, (verb->t_contents.c_func.f_ptrs.p_dptr_ddd)(hatom_getdouble(h1), hatom_getdouble(h2), hatom_getdouble(h3)));	break;
                    case H_ALL:		(verb->t_contents.c_func.f_ptrs.p_vptr_hhhh)(h1, h2, h3, res);	break;
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
 14	! ~ ++ -- + - (unary) * (type) sizeof right to left
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
                case H_PITCH:
                    arg2->t_contents.c_hatom.h_w.w_pitch *= -1;
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
                case H_PITCH:
                    hatom_setrational(&arg2->t_contents.c_hatom, arg2->t_contents.c_hatom.h_w.w_pitch.toMC().inv());
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






long lexpr_append_lexeme_OPEN(t_lexpr_lexeme *lex)
{
    lex->l_type = L_OPEN;
    return E_OK;
}

long lexpr_append_lexeme_CLOSED(t_lexpr_lexeme *lex)
{
    lex->l_type = L_CLOSED;
    return E_OK;
}

long lexpr_append_lexeme_COMMA(t_lexpr_lexeme *lex)
{
    lex->l_type = L_COMMA;
    return E_OK;
}

long lexpr_append_lexeme_VAR(t_lexpr_lexeme *lex, char type, long index, short *numvars, char *txt, char **offending)
{
    e_exprparser_err err = E_OK;
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_VAR;
    if (offending)
        *offending = NULL;
    switch (type) {
        case 'i':	lex->l_token.t_contents.c_var.v_type = H_LONG;		break;
        case 'f':	lex->l_token.t_contents.c_var.v_type = H_DOUBLE;	break;
        case 'r':	lex->l_token.t_contents.c_var.v_type = H_RAT;		break;
        case 'p':	lex->l_token.t_contents.c_var.v_type = H_PITCH;     break;
        case 'x':	lex->l_token.t_contents.c_var.v_type = H_ALL;		break;
        default:    lex->l_token.t_contents.c_var.v_type = H_NOTHING;
                    err = E_BAD_VAR_TYPE;
                    if (offending) {
                        *offending = (char *) bach_newptr(strlen(txt));
                        strcpy(*offending, txt);
                    }
                    break;
    }
    lex->l_token.t_contents.c_var.v_index = index;
    if (index >= *numvars)
        *numvars = index + 1;
    return err;
}

long lexpr_append_lexeme_VAR_substitution(t_lexpr_lexeme *lex, const char *txt, long subs_count, const char *substitutions[], short *numvars, char **offending)
{
    long idx;
    for (idx = 0; idx < subs_count; idx++) {
        if (!strcmp(txt, substitutions[idx])) {
            lexpr_append_lexeme_VAR(lex, 'x', idx, numvars, NULL, NULL);
            if (offending)
                *offending = NULL;
            return E_OK;
        }
    }
    if (offending) {
        *offending = (char *) bach_newptr(strlen(txt) + 1);
        strcpy(*offending, txt);
    }
    return E_BAD_NAME;
}

long lexpr_try_substitute_lexeme_FUNC_with_VAR_substitution(t_lexpr_lexeme *lex, long subs_count, const char *substitutions[], short *numvars, char **offending) {
    if (substitutions &&
        lex->l_type == L_TOKEN &&
        lex->l_token.t_type == TT_FUNC)
        return lexpr_append_lexeme_VAR_substitution(lex, lex->l_token.t_contents.c_func.f_name, subs_count, substitutions, numvars, offending);
    else
        return E_OK;
}

long lexpr_append_lexeme_BITOR(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_precedence = 5;
    lex->l_token.t_contents.c_op.o_op = O_BITOR;
    return E_OK;
}

long lexpr_append_lexeme_LOGOR(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_precedence = 2;
    lex->l_token.t_contents.c_op.o_op = O_LOGOR;
    return E_OK;
}

long lexpr_append_lexeme_BITAND(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_precedence = 7;
    lex->l_token.t_contents.c_op.o_op = O_BITAND;
    return E_OK;
}

long lexpr_append_lexeme_LOGAND(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_precedence = 4;
    lex->l_token.t_contents.c_op.o_op = O_LOGAND;
    return E_OK;
}

long lexpr_append_lexeme_BITXOR(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_precedence = 6;
    lex->l_token.t_contents.c_op.o_op = O_BITXOR;
    return E_OK;
}

long lexpr_append_lexeme_LOGXOR(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_precedence = 3;
    lex->l_token.t_contents.c_op.o_op = O_LOGXOR;
    return E_OK;
}

long lexpr_append_lexeme_BITNOT(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_precedence = 13;
    lex->l_order = O_R2L;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 1;
    lex->l_token.t_contents.c_op.o_op = O_BITNOT;
    return E_OK;
}

long lexpr_append_lexeme_LOGNOT(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 1;
    lex->l_precedence = 13;
    lex->l_order = O_R2L;
    lex->l_token.t_contents.c_op.o_op = O_LOGNOT;
    return E_OK;
}

long lexpr_append_lexeme_NEQ(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 8;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM;
    lex->l_token.t_contents.c_op.o_op = O_NEQ;
    return E_OK;
}

long lexpr_append_lexeme_NEQMATCH(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 8;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM;
    lex->l_token.t_contents.c_op.o_op = O_NEQMATCH;
    return E_OK;
}

long lexpr_append_lexeme_EQ(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 8;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM;
    lex->l_token.t_contents.c_op.o_op = O_EQ;
    return E_OK;
}

long lexpr_append_lexeme_EQMATCH(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 8;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM;
    lex->l_token.t_contents.c_op.o_op = O_EQMATCH;
    return E_OK;
}

long lexpr_append_lexeme_LT(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 9;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_LT;
    return E_OK;
}

long lexpr_append_lexeme_LSHIFT(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 10;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_LSHIFT;
    return E_OK;
}

long lexpr_append_lexeme_LE(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 9;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_LE;
    return E_OK;
}

long lexpr_append_lexeme_GT(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 9;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_GT;
    return E_OK;
}

long lexpr_append_lexeme_RSHIFT(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 10;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_RSHIFT;
    return E_OK;
}

long lexpr_append_lexeme_GE(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 9;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_GE;
    return E_OK;
}

long lexpr_append_lexeme_TIMES(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 12;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_token.t_contents.c_op.o_op = O_TIMES;
    return E_OK;
}

long lexpr_append_lexeme_POW(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 14;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_POW;
    return E_OK;
}

long lexpr_append_lexeme_MOD(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 12;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_MOD;
    return E_OK;
}

long lexpr_append_lexeme_DIV(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 12;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_INVERT;
    lex->l_token.t_contents.c_op.o_op = O_DIV;
    lex->l_token.t_contents.c_op.o_inv = O_TIMES;
    return E_OK;
}

long lexpr_append_lexeme_DIVDIV(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_precedence = 12;
    lex->l_order = O_L2R;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_DIVDIV;
    return E_OK;
}

long lexpr_append_lexeme_PLUS(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_precedence = 11;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_COMM | OP_ASSOC;
    lex->l_token.t_contents.c_op.o_op = O_PLUS;
    return E_OK;
}

long lexpr_append_lexeme_MINUS(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_precedence = 11;
    lex->l_order = O_L2R;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_op.o_properties = OP_INVERT;
    lex->l_token.t_contents.c_op.o_op = O_MINUS;
    lex->l_token.t_contents.c_op.o_inv = O_PLUS;
    return E_OK;
}

long lexpr_append_lexeme_UMINUS(t_lexpr_lexeme *lex)
{
    lex->l_type = L_TOKEN;
    lex->l_precedence = 13;
    lex->l_order = O_R2L;
    lex->l_token.t_type = TT_OP;
    lex->l_token.t_operands = 1;
    lex->l_token.t_contents.c_op.o_properties = OP_NONE;
    lex->l_token.t_contents.c_op.o_op = O_UMINUS;
    return E_OK;
}

long lexpr_append_lexeme_LONG(t_lexpr_lexeme *lex, t_atom_long l)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_HATOM;
    lex->l_token.t_contents.c_hatom.h_type = H_LONG;
    lex->l_token.t_contents.c_hatom.h_w.w_long = l;
    return E_OK;
}

long lexpr_append_lexeme_RATIONAL(t_lexpr_lexeme *lex, t_rational r)
{
    lex->l_type = L_TOKEN;    
    lex->l_token.t_type = TT_HATOM;
    lex->l_token.t_contents.c_hatom.h_type = H_RAT;
    lex->l_token.t_contents.c_hatom.h_w.w_rat = r;
    return E_OK;
}

long lexpr_append_lexeme_FLOAT(t_lexpr_lexeme *lex, double d)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_HATOM;
    lex->l_token.t_contents.c_hatom.h_type = H_DOUBLE;
    lex->l_token.t_contents.c_hatom.h_w.w_double = d;
    return E_OK;
}

long lexpr_append_lexeme_PITCH(t_lexpr_lexeme *lex, t_pitch p)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_HATOM;
    lex->l_token.t_contents.c_hatom.h_type = H_PITCH;
    lex->l_token.t_contents.c_hatom.h_w.w_pitch = p;
    return E_OK;
}





long lexpr_append_lexeme_FUNC_unary_DOUBLE(t_lexpr_lexeme *lex, double(*f)(double a), const char *name)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_FUNC;
    lex->l_token.t_operands = 1;
    lex->l_token.t_contents.c_func.f_ptrs.p_dptr_d = f;
    lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
    lex->l_token.t_contents.c_func.f_name = name;
    return E_OK;
}

long lexpr_append_lexeme_FUNC_binary_DOUBLE(t_lexpr_lexeme *lex, double(*f)(double a, double b), const char *name)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_FUNC;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_func.f_ptrs.p_dptr_dd = f;
    lex->l_token.t_contents.c_func.f_type = H_DOUBLE;
    lex->l_token.t_contents.c_func.f_name = name;
    return E_OK;
}

long lexpr_append_lexeme_FUNC_unary_ALL(t_lexpr_lexeme *lex, void(*f)(t_hatom *a, t_hatom *r), const char *name)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_FUNC;
    lex->l_token.t_operands = 1;
    lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hh = f;
    lex->l_token.t_contents.c_func.f_type = H_ALL;
    lex->l_token.t_contents.c_func.f_name = name;
    return E_OK;
}

long lexpr_append_lexeme_FUNC_binary_ALL(t_lexpr_lexeme *lex, void(*f)(t_hatom *a, t_hatom *b, t_hatom *r), const char *name)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_FUNC;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hhh = f;
    lex->l_token.t_contents.c_func.f_type = H_ALL;
    lex->l_token.t_contents.c_func.f_name = name;
    return E_OK;
}

long lexpr_append_lexeme_FUNC_binary_ALL_dontfold(t_lexpr_lexeme *lex, void(*f)(t_hatom *a, t_hatom *b, t_hatom *r), const char *name)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_FUNC;
    lex->l_token.t_operands = 2;
    lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hhh = f;
    lex->l_token.t_contents.c_func.f_type = H_ALL;
    lex->l_token.t_contents.c_func.f_dontfold = 1;
    lex->l_token.t_contents.c_func.f_name = name;
    return E_OK;
}

long lexpr_append_lexeme_FUNC_ternary_ALL(t_lexpr_lexeme *lex, void(*f)(t_hatom *a, t_hatom *b, t_hatom *c, t_hatom *r), const char *name)
{
    lex->l_type = L_TOKEN;
    lex->l_token.t_type = TT_FUNC;
    lex->l_token.t_operands = 3;
    lex->l_token.t_contents.c_func.f_ptrs.p_vptr_hhhh = f;
    lex->l_token.t_contents.c_func.f_type = H_ALL;
    lex->l_token.t_contents.c_func.f_name = name;
    return E_OK;
}































