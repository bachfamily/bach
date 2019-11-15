/*
 *  builtInFunctionWithSortFn.hpp
 *
 * Copyright (C) 2010-2019 Andrea Agostini and Daniele Ghisi
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

#ifndef builtInFunctionWithSortFn_hpp
#define builtInFunctionWithSortFn_hpp

#include "bell/builtInFunction.hpp"

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
