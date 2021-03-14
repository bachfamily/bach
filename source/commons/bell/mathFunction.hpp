/*
 *  mathFunction.hpp
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

#ifndef mathUnaryFunction_hpp
#define mathUnaryFunction_hpp

#include "bell/builtInFunction.hpp"
#include "bell/llllIterator.hpp"
#include "math/llll_math.h"

template <int ARITY>
class t_mathFunction : public t_builtInFunction, public llllIterator<ARITY>
{
public:
    t_mathFunction(method fn, const char *n = nullptr) : t_builtInFunction(n), llllIterator<ARITY>(fn) { };
    t_llll* call(t_execEnv &context) {
        return llllIterator<ARITY>::run(context.argv + 1);
    }
};

template <double(*FN)(double)>
class t_mathUnaryFunctionDD : public t_mathFunction<1>
{
private:
    static void op(t_hatom *hatoms, t_hatom *res) {
        if (hatom_is_number(hatoms))
            hatom_setdouble(res, FN(hatom_getdouble(hatoms)));
        else
            *res = *hatoms;
    }
    
public:
    t_mathUnaryFunctionDD(const char *n = nullptr, const char *pn1 = "x") :  t_mathFunction<1>((method) op, n) {
        setArgument(pn1);
    }
};

template <double(*FN)(double, double)>
class t_mathBinaryFunctionDDD : public t_mathFunction<2>
{
private:
    static void op(t_hatom *h1, t_hatom *h2, t_hatom *res) {
        if (hatom_is_number(h1) && hatom_is_number(h2))
            hatom_setdouble(res, FN(hatom_getdouble(h1), hatom_getdouble(h2)));
        else
            *res = *h1;
    }
    
public:
    t_mathBinaryFunctionDDD(const char *n = nullptr, const char *pn1 = "x", const char *pn2 = "y") : t_mathFunction<2>((method) op, n) {
        setArgument(pn1);
        setArgument(pn2);
    }
};


template <void (*FN)(t_hatom*, t_hatom*)>
class t_mathUnaryFunctionAA : public t_mathFunction<1>
{
public:
    t_mathUnaryFunctionAA(const char *n = nullptr, const char *pn1 = "x") : t_mathFunction<1>((method) FN, n) {
        setArgument(pn1);
    }
};

template <void (*FN)(t_hatom*, t_hatom*, t_hatom*)>
class t_mathBinaryFunctionAAA : public t_mathFunction<2>
{
public:
    t_mathBinaryFunctionAAA(const char *n = nullptr, const char *pn1 = "x", const char *pn2 = "y") : t_mathFunction<2>((method) FN, n) {
        setArgument(pn1);
        setArgument(pn2);
    }
};

template <void (*FN)(t_hatom*, t_hatom*, t_hatom*, t_hatom*)>
class t_mathTernaryFunctionAAAA : public t_mathFunction<3>
{
public:
    t_mathTernaryFunctionAAAA(const char *n = nullptr, const char *pn1 = "x", const char *pn2 = "y", const char *pn3 = "z") : t_mathFunction<3>((method) FN, n) {
        setArgument(pn1);
        setArgument(pn2);
        setArgument(pn3);

    }
};

template<void (*FN)(t_hatom*, t_hatom*)>
class astConvInlet : public astInlet, public llllIterator<1>
{
public:
    astConvInlet(int idx, t_codableobj *owner) : astInlet(idx, owner), llllIterator<1>((method) FN) { };
    
    t_llll *eval(t_execEnv &context, t_bool tail = false) {
        if (idx > 0 && idx <= context.argc)
            return run(context.argv + idx);
        else
            return llll_get();
    }
};



#endif /* mathUnaryFunction_hpp */


