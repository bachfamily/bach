/*
 *  builtInFunction.hpp
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

#ifndef builtInFunction_hpp
#define builtInFunction_hpp

#include "function.hpp"


class t_builtInFunction : public t_function
{
public:
    t_builtInFunction(const char *n = nullptr, t_bool v = false) {
        variadic = v;
        namedArgumentsCount = 0;
        name = n ? gensym(n) : nullptr;
    }
    
    void getDepthsFromArguments(t_llll *depthArg, t_llll *minArg, t_llll *maxArg, t_atom_long *mindepth, t_atom_long *maxdepth) {
        if (depthArg->l_size == 1) {
            *maxdepth = hatom_getlong(&depthArg->l_head->l_hatom);
            *mindepth = llll_getlong(minArg);
        } else if (depthArg->l_size >= 2) {
            *mindepth = hatom_getlong(&depthArg->l_head->l_hatom);
            *maxdepth = hatom_getlong(&depthArg->l_head->l_next->l_hatom);
        } else {
            *mindepth = llll_getlong(minArg);
            *maxdepth = llll_getlong(maxArg);
        }
    }
    
    // with these, we disable reference counting for built in functions, thus preventing them from being deleted
    //virtual void increase() { }
    //virtual void decrease() { }
};

class t_fnLength : public t_builtInFunction
{
public:
    t_fnLength();
    t_llll* call(const t_execEnv &context);
};

class t_fnDepth : public t_builtInFunction
{
public:
    t_fnDepth();
    t_llll* call(const t_execEnv &context);
};

class t_fnIs : public t_builtInFunction
{
public:
    t_fnIs();
    t_llll* call(const t_execEnv &context);
};

class t_fnNth : public t_builtInFunction
{
public:
    t_fnNth();
    t_llll* call(const t_execEnv &context);
};

class t_fnArgs : public t_builtInFunction
{
public:
    t_fnArgs();
    t_llll* call(const t_execEnv &context);
};

class t_fnArgcount : public t_builtInFunction
{
public:
    t_fnArgcount();
    t_llll* call(const t_execEnv &context);
};

class t_fnOutlet : public t_builtInFunction
{
public:
    t_fnOutlet();
    t_llll* call(const t_execEnv &context);
};

class t_fnInlet : public t_builtInFunction
{
public:
    t_fnInlet();
    t_llll* call(const t_execEnv &context);
};

class t_fnRev : public t_builtInFunction
{
public:
    t_fnRev();
    t_llll* call(const t_execEnv &context);
};

class t_fnRot : public t_builtInFunction
{
public:
    t_fnRot();
    t_llll* call(const t_execEnv &context);
};

class t_fnContains : public t_builtInFunction
{
public:
    t_fnContains();
    t_llll* call(const t_execEnv &context);
};

class t_fnTrans : public t_builtInFunction
{
public:
    t_fnTrans();
    t_llll* call(const t_execEnv &context);
};

class t_fnFlat : public t_builtInFunction
{
public:
    t_fnFlat();
    t_llll* call(const t_execEnv &context);
};

class t_fnSlice : public t_builtInFunction
{
public:
    t_fnSlice();
    t_llll* call(const t_execEnv &context);
};

class t_fnLeft : public t_builtInFunction
{
public:
    t_fnLeft();
    t_llll* call(const t_execEnv &context);
};

class t_fnRight : public t_builtInFunction
{
public:
    t_fnRight();
    t_llll* call(const t_execEnv &context);
};

class t_fnSubs : public t_builtInFunction
{
public:
    t_fnSubs();
    t_llll* call(const t_execEnv &context);
};

class t_fnInsert : public t_builtInFunction
{
public:
    t_fnInsert();
    t_llll* call(const t_execEnv &context);
};

class t_fnKeysubs : public t_builtInFunction
{
public:
    t_fnKeysubs();
    t_llll* call(const t_execEnv &context);
};

class t_fnScramble : public t_builtInFunction
{
public:
    t_fnScramble();
    t_llll* call(const t_execEnv &context);
};

class t_fnMinmax : public t_builtInFunction
{
public:
    t_fnMinmax();
    t_llll* call(const t_execEnv &context);
};

class t_fnPerm : public t_builtInFunction
{
public:
    t_fnPerm();
    t_llll* call(const t_execEnv &context);
};

class t_fnComb : public t_builtInFunction
{
public:
    t_fnComb();
    t_llll* call(const t_execEnv &context);
};

class t_fnCartesianprod : public t_builtInFunction
{
public:
    t_fnCartesianprod();
    t_llll* call(const t_execEnv &context);
};

class t_fnWrap : public t_builtInFunction
{
public:
    t_fnWrap();
    t_llll* call(const t_execEnv &context);
};

class t_fnDelace : public t_builtInFunction
{
public:
    t_fnDelace();
    t_llll* call(const t_execEnv &context);
};

class t_fnGroup : public t_builtInFunction
{
public:
    t_fnGroup();
    t_llll* call(const t_execEnv &context);
};

class t_fnPrimeser : public t_builtInFunction
{
public:
    t_fnPrimeser();
    t_llll* call(const t_execEnv &context);
};

class t_fnArithmser : public t_builtInFunction
{
public:
    t_fnArithmser();
    t_llll* call(const t_execEnv &context);
};

class t_fnGeomser : public t_builtInFunction
{
public:
    t_fnGeomser();
    t_llll* call(const t_execEnv &context);
};


#endif /* builtInFunction_hpp */
