//
//  mathUnaryFunction.hpp
//  code
//
//  Created by Andrea Agostini on 22/06/2018.
//

#ifndef mathUnaryFunction_hpp
#define mathUnaryFunction_hpp

#include "builtInFunction.hpp"
#include "llllIterator.hpp"
#include "llll_math.h"

template <int ARITY>
class t_mathFunction : public t_builtInFunction, public llllIterator<ARITY>
{
public:
    t_mathFunction(method fn, const char *n = nullptr) : t_builtInFunction(n), llllIterator<ARITY>(fn) { };
    t_llll* call(const t_execEnv &context) {
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
    t_mathUnaryFunctionDD(const char *pn1 = "x", const char *n = nullptr) :  t_mathFunction<1>((method) op, n) {
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
    t_mathBinaryFunctionDDD(const char *pn1 = "x", const char *pn2 = "y", const char *n = nullptr) : t_mathFunction<2>((method) op, n) {
        setArgument(pn1);
        setArgument(pn2);
    }
};


template <void (*FN)(t_hatom*, t_hatom*)>
class t_mathUnaryFunctionAA : public t_mathFunction<1>
{
public:
    t_mathUnaryFunctionAA(const char *pn1 = "x", const char *n = nullptr) : t_mathFunction<1>((method) FN, n) {
        setArgument(pn1);
    }
};

template <void (*FN)(t_hatom*, t_hatom*, t_hatom*)>
class t_mathBinaryFunctionAAA : public t_mathFunction<2>
{
public:
    t_mathBinaryFunctionAAA(const char *pn1 = "x", const char *pn2 = "y", const char *n = nullptr) : t_mathFunction<2>((method) FN, n) {
        setArgument(pn1);
        setArgument(pn2);
    }
};

template <void (*FN)(t_hatom*, t_hatom*, t_hatom*, t_hatom*)>
class t_mathTernaryFunctionAAAA : public t_mathFunction<3>
{
public:
    t_mathTernaryFunctionAAAA(const char *pn1 = "x", const char *pn2 = "y", const char *pn3 = "z", const char *n = nullptr) : t_mathFunction<3>((method) FN, n) {
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
    
    t_llll *eval(t_execEnv const &context) {
        if (idx > 0 && idx <= context.argc)
            return run(context.argv + idx);
        else
            return llll_get();
    }
};



#endif /* mathUnaryFunction_hpp */


