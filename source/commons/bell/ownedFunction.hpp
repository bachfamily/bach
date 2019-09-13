//
//  ownedFunctions.hpp
//  code
//
//  Created by Andrea Agostini on 22/06/2018.
//

#ifndef ownedFunctions_hpp
#define ownedFunctions_hpp

#include "builtInFunction.hpp"

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
