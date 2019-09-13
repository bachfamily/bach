//
//  builtInFunctionWithFindFn.hpp
//  code
//
//  Created by Andrea Agostini on 22/06/2018.
//

#ifndef builtInFunctionWithFindFn_hpp
#define builtInFunctionWithFindFn_hpp

#include "builtInFunction.hpp"

class t_builtInFunctionWithFindFn : public t_builtInFunction
{
protected:
    class t_fnData
    {
    public:
        t_function *func;
        t_execEnv context;
        
        t_fnData(t_function *fn, t_execEnv const * const parent, t_function *caller, t_llll *items) : func(fn), context(parent, caller)
        {
            context.argv[2] = items;
            context.setFnArgNames(fn);
            context.setFnDefaults(fn, 0, 2);
            context.setFnLocalVariables(fn);
            context.adjustArgc(fn, 2);
        };
    };
    
    static long lambdaFunction(t_fnData *lambdaData, t_llll *ll);
    
public:
    using t_builtInFunction::t_builtInFunction;
};

class t_fnFind : public t_builtInFunctionWithFindFn
{
public:
    t_fnFind();
    t_llll* call(const t_execEnv &context);
};

class t_fnFinditems : public t_builtInFunctionWithFindFn
{
public:
    t_fnFinditems();
    t_llll* call(const t_execEnv &context);
};

class t_fnFindaddrs : public t_builtInFunctionWithFindFn
{
public:
    t_fnFindaddrs();
    t_llll* call(const t_execEnv &context);
};



#endif /* builtInFunctionWithFindFn_hpp */
