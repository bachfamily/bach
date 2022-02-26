/*
 *  operator.hpp
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

#ifndef operator_hpp
#define operator_hpp

#include "bell/astNode.hpp"
#include "bell/llllIterator.hpp"
#include "math/llll_math.h"

template <void (*FN)(t_hatom*, t_hatom*)>
class astUnaryOperator : public astNode, public llllIterator<1> {
private:
    astNode *n1;

public:
    astUnaryOperator(astNode *n1, t_codableobj *owner) : astNode(owner), llllIterator<1>((method) FN), n1(n1) { }
    
    ~astUnaryOperator() {
        delete n1;
    }
    
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll = n1->eval(context);
        t_llll *res = run(&ll);
        bell_release_llll(ll);
        return res;
    }
};

template <void (*FN)(t_hatom*, t_hatom*, t_hatom*)>
class astBinaryOperator : public astNode, public llllIterator<2> {
private:
    astNode *n1;
    astNode *n2;
    
public:
    astBinaryOperator(astNode *n1, astNode *n2, t_codableobj *owner) : astNode(owner), llllIterator<2>((method) FN), n1(n1), n2(n2) { };
    
    ~astBinaryOperator() {
        delete n1;
        delete n2;
    }
    
    t_llll *eval(t_execEnv const &context) {
        t_llll *lists[2];
        lists[0] = n1->eval(context);
        lists[1] = n2->eval(context);
        t_llll *res = run(lists);
        bell_release_llll(lists[0]);
        bell_release_llll(lists[1]);
        return res;
    }
};


template <void (*FN)(t_hatom*, t_hatom*, t_hatom*)>
class astAssigningOperator : public astNode, public llllIterator<2> {
private:
    astVar *varNode;
    astNode *valueNode;
    
public:
    astAssigningOperator(astVar *varNode, astNode *valueNode, t_codableobj *owner) : astNode(owner), llllIterator<2>((method) FN), varNode(varNode), valueNode(valueNode) { };
    
    astAssigningOperator() {
        delete varNode;
        delete valueNode;
    }
    
    t_llll *eval(t_execEnv const &context) {
        t_llll *lists[2];
        //t_variable *v = varNode->getVar(context);
        lists[0] = varNode->eval(context);
        lists[1] = valueNode->eval(context);
        t_llll *res = run(lists);
        varNode->assign(res, context);
        bell_release_llll(lists[0]);
        bell_release_llll(lists[1]);
        return res;
    }
};

typedef astUnaryOperator<hatom_op_uminus> astOperatorUMinus;
typedef astUnaryOperator<hatom_op_bitnot> astOperatorBitNot;

typedef astBinaryOperator<hatom_op_plus_with_symbols> astOperatorPlus;
typedef astBinaryOperator<hatom_op_minus> astOperatorMinus;
typedef astBinaryOperator<hatom_op_times_with_symbols> astOperatorTimes;
typedef astBinaryOperator<hatom_op_div> astOperatorDiv;
typedef astBinaryOperator<hatom_op_divdiv> astOperatorDivdiv;
typedef astBinaryOperator<hatom_fn_remainder> astOperatorRemainder;
typedef astBinaryOperator<hatom_op_pow> astOperatorPow;
typedef astBinaryOperator<hatom_op_bitand> astOperatorBitAnd;
typedef astBinaryOperator<hatom_op_bitor> astOperatorBitOr;
typedef astBinaryOperator<hatom_op_bitxor> astOperatorBitXor;
typedef astBinaryOperator<hatom_op_lshift> astOperatorLShift;
typedef astBinaryOperator<hatom_op_rshift> astOperatorRShift;


typedef astAssigningOperator<hatom_op_plus> astOperatorAPlus;
typedef astAssigningOperator<hatom_op_minus> astOperatorAMinus;
typedef astAssigningOperator<hatom_op_times> astOperatorATimes;
typedef astAssigningOperator<hatom_op_div> astOperatorADiv;
typedef astAssigningOperator<hatom_op_divdiv> astOperatorADivdiv;
typedef astAssigningOperator<hatom_fn_remainder> astOperatorARemainder;
typedef astAssigningOperator<hatom_op_pow> astOperatorAPow;
typedef astAssigningOperator<hatom_op_bitand> astOperatorABitAnd;
typedef astAssigningOperator<hatom_op_bitor> astOperatorABitOr;
typedef astAssigningOperator<hatom_op_bitxor> astOperatorABitXor;
typedef astAssigningOperator<hatom_op_lshift> astOperatorALShift;
typedef astAssigningOperator<hatom_op_rshift> astOperatorARShift;




template <
typename BASE,
void (*FN)(t_hatom*, t_hatom*, t_hatom*)
>
class astRichAccessOperator : public BASE, public llllIterator<2> {
    
public:
    astRichAccessOperator(typename BASE::firstType *lNode,
                             astNode *rNode,
                             lvalueStepList *lvalueStepList,
                             t_codableobj *owner) :
        BASE(lNode, rNode, lvalueStepList, owner),
        llllIterator<2>((method) FN) { };
    
    ~astRichAccessOperator() { };
    
private:
    t_llll *perform(t_llll* ll1, t_llll* ll2) {
        t_llll *lists[2];
        lists[0] = ll1;
        lists[1] = ll2;
        t_llll *res = run(lists);
        return res;
    }
    
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        t_llll *hereLlll = llll_get();
        llll_appendhatom_clone(hereLlll, &lookHere->l_hatom);
        t_llll *res = perform(hereLlll, origV);
        llll_replacewith<false>(current, lookHere, res);
    }

    void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        t_llll *currValues = llll_clone(subll);
        llll_destroyelem(currValues->l_head);
        t_llll *res = perform(currValues, origV);
        llll_destroy_everything_but_head(subll);
        llll_chain(subll, res);
        return;
    }
};


typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_plus> astOperatorRAPlus;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_minus> astOperatorRAMinus;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_times> astOperatorRATimes;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_div> astOperatorRADiv;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_divdiv> astOperatorRADivdiv;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_fn_remainder> astOperatorRARemainder;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_pow> astOperatorRAPow;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_bitand> astOperatorRABitAnd;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_bitor> astOperatorRABitOr;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_bitxor> astOperatorRABitXor;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_lshift> astOperatorRALShift;
typedef astRichAccessOperator<astRichAssignment<E_RA_STANDARD>, hatom_op_rshift> astOperatorRARShift;


typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_plus> astOperatorREPlus;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_minus> astOperatorREMinus;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_times> astOperatorRETimes;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_div> astOperatorREDiv;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_divdiv> astOperatorREDivdiv;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_fn_remainder> astOperatorRERemainder;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_pow> astOperatorREPow;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_bitand> astOperatorREBitAnd;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_bitor> astOperatorREBitOr;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_bitxor> astOperatorREBitXor;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_lshift> astOperatorRELShift;
typedef astRichAccessOperator<astRichEdit<E_RA_STANDARD>, hatom_op_rshift> astOperatorRERShift;


#endif /* operator_hpp */
