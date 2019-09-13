//
//  fnMap.hpp
//  code
//
//  Created by Andrea Agostini on 24/06/2018.
//

#ifndef fnMap_hpp
#define fnMap_hpp

#include "builtInFunction.hpp"

class t_fnMap : public t_builtInFunction
{
protected:
    class t_fnData {
    public:
        t_function *funcAsk;
        t_function *funcMod;
        t_execEnv fnAskContext;
        t_execEnv fnModContext;

        t_fnData(t_function *funcAsk, t_function *funcMod, t_execEnv const * const parent, t_function *caller) : funcAsk(funcAsk), funcMod(funcMod), fnAskContext(parent, caller), fnModContext(parent, caller)
        {
            fnModContext.setFnArgNames(funcMod);
            fnModContext.setFnDefaults(funcMod, 0, 3);
            fnModContext.setFnLocalVariables(funcMod);
            fnModContext.adjustArgc(funcMod, 3);

            if (funcAsk) {
                fnAskContext.setFnArgNames(funcAsk);
                fnAskContext.setFnDefaults(funcAsk, 0, 3);
                fnAskContext.setFnLocalVariables(funcAsk);
                fnAskContext.adjustArgc(funcAsk, 3);
            }
        };
    };
    
    static long lambdaAsk(t_fnData *lambdaData, t_llll *ll, t_llll *old_address, t_llll *new_address);
    static t_llll* lambdaMod(t_fnData *lambdaData, t_llll *ll, t_llll *old_address, t_llll *new_address);

public:
    t_fnMap();
    t_llll* call(const t_execEnv &context);
};

class t_fnReduce : public t_builtInFunction
{
protected:
    class t_fnData {
    public:
        t_function *fn;
        t_execEnv context;
        
    t_fnData(t_function *fn, t_execEnv const * const parent, t_function *caller) : fn(fn), context(parent, caller)
        {
            context.setFnArgNames(fn);
            context.setFnDefaults(fn, 0, 3);
            context.setFnLocalVariables(fn);
            context.adjustArgc(fn, 3);
        };
    };
    
    static t_llll *lambdaFunction(t_fnData *lambdaData, t_llll *accum, const t_hatom *h, t_atom_long address);

public:
    t_fnReduce();
    t_llll* call(const t_execEnv &context);
};

class t_fnApply : public t_builtInFunction
{
public:
    t_fnApply();
    t_llll* call(const t_execEnv &context);
};


#endif /* fnMap_hpp */
