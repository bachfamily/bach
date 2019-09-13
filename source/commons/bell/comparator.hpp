//
//  comparator.hpp
//  fux
//
//  Created by Andrea Agostini on 06/03/18.
//
//

#ifndef comparator_hpp
#define comparator_hpp

#include "astNode.hpp"

class astComparator : public astNode
{
protected:
    astNode *n1;
    astNode *n2;
public:
    astComparator(astNode *n1, astNode *n2, t_codableobj *owner) : astNode(owner), n1(n1), n2(n2) { }
    ~astComparator() {
        delete n1;
        delete n2;
    }
};

class astComparatorLt : public astComparator
{
public:
    using astComparator::astComparator;
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll1 = n1->eval(context);
        t_llll *ll2 = n2->eval(context);
        t_llll *res = llll_get();
        llll_appendlong(res, llll_lt(ll1, ll2));
        bell_release_llll(ll1);
        bell_release_llll(ll2);
        return res;
    }
};

class astComparatorGt : public astComparator
{
public:
    using astComparator::astComparator;
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll1 = n1->eval(context);
        t_llll *ll2 = n2->eval(context);
        t_llll *res = llll_get();
        llll_appendlong(res, llll_gt(ll1, ll2));
        bell_release_llll(ll1);
        bell_release_llll(ll2);
        return res;
    }
};

class astComparatorLeq : public astComparator
{
public:
    using astComparator::astComparator;
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll1 = n1->eval(context);
        t_llll *ll2 = n2->eval(context);
        t_llll *res = llll_get();
        llll_appendlong(res, llll_leq(ll1, ll2));
        bell_release_llll(ll1);
        bell_release_llll(ll2);
        return res;
    }
};

class astComparatorGeq : public astComparator
{
public:
    using astComparator::astComparator;
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll1 = n1->eval(context);
        t_llll *ll2 = n2->eval(context);
        t_llll *res = llll_get();
        llll_appendlong(res, llll_geq(ll1, ll2));
        bell_release_llll(ll1);
        bell_release_llll(ll2);
        return res;
    }
};

class astComparatorEq : public astComparator
{
public:
    using astComparator::astComparator;
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll1 = n1->eval(context);
        t_llll *ll2 = n2->eval(context);
        t_llll *res = llll_get();
        llll_appendlong(res, llll_eq_ignoretype(ll1, ll2));
        bell_release_llll(ll1);
        bell_release_llll(ll2);
        return res;
    }
};

class astComparatorNeq : public astComparator
{
public:
    using astComparator::astComparator;
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll1 = n1->eval(context);
        t_llll *ll2 = n2->eval(context);
        t_llll *res = llll_get();
        llll_appendlong(res, llll_neq_ignoretype(ll1, ll2));
        bell_release_llll(ll1);
        bell_release_llll(ll2);
        return res;
    }
};

#endif /* comparator_hpp */
