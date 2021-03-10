/*
 *  comparator.hpp
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

#ifndef comparator_hpp
#define comparator_hpp

#include "bell/astNode.hpp"

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
        t_llll *ll1 = n1->TCOEval(context);
        t_llll *ll2 = n2->TCOEval(context);
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
        t_llll *ll1 = n1->TCOEval(context);
        t_llll *ll2 = n2->TCOEval(context);
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
        t_llll *ll1 = n1->TCOEval(context);
        t_llll *ll2 = n2->TCOEval(context);
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
        t_llll *ll1 = n1->TCOEval(context);
        t_llll *ll2 = n2->TCOEval(context);
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
        t_llll *ll1 = n1->TCOEval(context);
        t_llll *ll2 = n2->TCOEval(context);
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
        t_llll *ll1 = n1->TCOEval(context);
        t_llll *ll2 = n2->TCOEval(context);
        t_llll *res = llll_get();
        llll_appendlong(res, llll_neq_ignoretype(ll1, ll2));
        bell_release_llll(ll1);
        bell_release_llll(ll2);
        return res;
    }
};

#endif /* comparator_hpp */
