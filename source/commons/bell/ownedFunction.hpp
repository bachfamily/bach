/*
 *  ownedFunction.hpp
 *
 * Copyright (C) 2010-2022 Andrea Agostini and Daniele Ghisi
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

#ifndef ownedFunctions_hpp
#define ownedFunctions_hpp

#include "bell/builtInFunction.hpp"

class t_ownedFunction : public t_builtInFunction
{
protected:
    t_object *owner;
public:
    t_ownedFunction(const char *n, t_bool variadic, t_object *owner) : t_builtInFunction(n, variadic), owner(owner) { }

};

class t_fnDirectout : public t_ownedFunction
{
public:
    t_fnDirectout(t_eval *owner);
    t_llll* call(t_execEnv const &context);
};

class t_fnDirectin : public t_ownedFunction
{
public:
    t_fnDirectin(t_eval *owner);
    t_llll* call(t_execEnv const &context);
};


class t_fnDirectout_dummy : public t_fnDirectout
{
public:
    t_fnDirectout_dummy(t_object *owner);
    t_llll* call(t_execEnv const &context);
};

class t_fnDirectin_dummy : public t_fnDirectin
{
public:
    t_fnDirectin_dummy(t_object *owner);
    t_llll* call(t_execEnv const &context);
};

class t_fnPrint : public t_ownedFunction
{
public:
    t_fnPrint(t_object *owner);
    t_llll* call(t_execEnv const &context);
};

#endif /* ownedFunctions_hpp */
