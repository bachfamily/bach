//
//  builtInFunctionWithSortFn.hpp
//  code
//
//  Created by Andrea Agostini on 22/06/2018.
//

#ifndef builtInFunctionWithSortFn_hpp
#define builtInFunctionWithSortFn_hpp

#include "builtInFunction.hpp"

class t_builtInFunctionWithSortFn : public t_builtInFunction
{
protected:
    class t_fnData {
    public:
        t_function *func;
        t_execEnv context;
        
        t_fnData(t_function *fn, t_execEnv const * const parent, t_function *caller) : func(fn), context(parent, caller)
        {
            context.setFnArgNames(fn);
            context.setFnDefaults(fn, 0, 2);
            context.setFnLocalVariables(fn);
            context.adjustArgc(fn, 2);
        };
    };
    static long lambdaFunction(t_fnData *lambdaData, t_llllelem *a, t_llllelem *b);
    using t_builtInFunction::t_builtInFunction;
};

class t_fnSort : public t_builtInFunctionWithSortFn
{
public:
    t_fnSort();
    t_llll* call(t_execEnv const &context);
};

class t_fnThin : public t_builtInFunctionWithSortFn
{
public:
    t_fnThin();
    t_llll* call(t_execEnv const &context);
};

class t_fnClassify : public t_builtInFunctionWithSortFn
{
public:
    t_fnClassify();
    t_llll* call(t_execEnv const &context);
};

class t_fnUnion : public t_builtInFunctionWithSortFn
{
public:
    t_fnUnion();
    t_llll* call(t_execEnv const &context);
};

class t_fnIntersection : public t_builtInFunctionWithSortFn
{
public:
    t_fnIntersection();
    t_llll* call(t_execEnv const &context);
};

class t_fnSymdiff : public t_builtInFunctionWithSortFn
{
public:
    t_fnSymdiff();
    t_llll* call(t_execEnv const &context);
};

class t_fnDiff : public t_builtInFunctionWithSortFn
{
public:
    t_fnDiff();
    t_llll* call(t_execEnv const &context);
};


#endif /* builtInFunctionWithSortFn_hpp */
