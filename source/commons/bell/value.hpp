//
//  value.hpp
//  fux
//
//  Created by Andrea Agostini on 01/02/18.
//
//

#ifndef value_hpp
#define value_hpp


#include "llllobj.h"

#define bell_release_llll(x) llll_release_unsafe(x)
#define bell_retain_llll(x) llll_retain_unsafe(x)

//#define bell_release_llll(x) llll_release(x)
//#define bell_retain_llll(x) llll_retain(x)

class t_value // something with a value, such as a constant
{
private:
protected:
    t_llll *data;
public:
    virtual ~t_value() {
        //cpost("called t_value destructor: this = %p, data = %p", this, data);
        bell_release_llll(data);
    };
    
    t_value(t_llll *ll = nullptr) : data(bell_retain_llll(ll)) {
        //cpost("called t_value constructor: this = %p, data = %p", this, data);
    }
    
    t_llll *get() {
        if (!data)
            data = llll_get();
        return bell_retain_llll(data);
    }
};

class t_countable // something with reference counting
{
private:
    t_int32_atomic count;
protected:
    virtual ~t_countable() { };
public:
    t_countable() : count(1) {}
    virtual void increase() { ATOMIC_INCREMENT_BARRIER_32(&count); }
    virtual t_bool decrease() {
        if (ATOMIC_DECREMENT_BARRIER_32(&count) == 0) {
            delete this;
            return true;
        } else
            return false;
    }
};

class t_named : public t_countable // something with a name: named things are always subject to reference counting
{
private:
    t_symbol *name;
protected:
    t_named(t_symbol *n) : /*t_countable(),*/ name(n) {}
public:
    t_symbol *getName() const { return name; }
};

class t_namedValue : public t_named, public t_value // a value with a name, such as a pseudo-variable
{
protected:
public:
    t_namedValue(t_symbol *n, t_llll *ll = nullptr) : t_named(n), t_value(ll) {}
};


class t_variable : public t_namedValue // a variable is a mutable namedValue
{
private:
public:
    using t_namedValue::t_namedValue;
    void set(t_llll *ll) {
        if (data)
            bell_release_llll(data);
        data = bell_retain_llll(ll);
    }
};

template <typename T>
class t_table // a hash table
{
private:
    
protected:
    std::unordered_map<t_symbol*, T> t;

public:
    t_table() { }
    
    virtual ~t_table() { }
    
    void insert(T n) {
        t[n->getName()] = n;
        //cpost("insert: name = %s, item = %p", n->getName()->s_name, n);
    }
    
    T lookup(t_symbol *name) {
        //cpost("lookup: name = %s, item = %p", name->s_name, t[name]);
        if (auto found = t.find(name); found != t.end())
            return found->second;
        else
            return nullptr;
    }
};

template <typename T>
class t_freeingTable : public t_table<T>
{
public:
    ~t_freeingTable() {
        for(auto iter = t_table<T>::t.begin(); iter != t_table<T>::t.end(); ++iter){
            T* cur = iter->second; // pointer to Node
            delete cur;
        }
    }
};

class t_safe // something with a thread locking mechanism
{
private:
    t_bach_atomic_lock l;
protected:
    virtual ~t_safe() { bach_atomic_lock(&l); }
public:
    t_safe() : l(0) { }
    void lock() { bach_atomic_lock(&l); }
    void unlock() { bach_atomic_unlock(&l); }
    t_bool trylock() { return bach_atomic_trylock(&l); }
};

template <typename T>
class t_safeTable : public t_safe, public t_table<T>  // a table with a thread locking mechanism, which is never locked automatically
{
public:
    void insert(T n) { t_table<T>::insert(n); }
    T lookup(t_symbol *name) { return t_table<T>::lookup(name); }
    virtual ~t_safeTable() { }
};


#endif /* value_hpp */







