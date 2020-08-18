/*
 *  fnMap.hpp
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

#ifndef fnMap_hpp
#define fnMap_hpp

#include "bell/builtInFunction.hpp"

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
