/*
 *  builtInFunctionWithFindFn.hpp
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

#ifndef builtInFunctionWithFindFn_hpp
#define builtInFunctionWithFindFn_hpp

#include "bell/builtInFunction.hpp"

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
