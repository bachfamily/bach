/*
 *  sharedVariable.hpp
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

#ifndef sharedVariable_hpp
#define sharedVariable_hpp

#include <unordered_map>
#include <set>
#include "value.hpp"
#include "foundation/bach_maxutils.h"

class variableClientManager
{
    
public:
    class client {
    public:
        t_object *obj;
        long priority;
    public:
        client(t_object *obj, long priority = 0) : obj(obj), priority(priority) { };
        
        t_bool operator<(const client& b) const {
            if (priority != b.priority)
                return priority > b.priority;
            else
                return obj < b.obj;
        }
    };
    
    using clientSet = std::set<client>;
    
    clientSet clients;

    void addClient(t_object *obj, long priority = 0) {
        t_bool doit = true;
        for (auto i = clients.begin(); i != clients.end() ; i++) {
            if ((*i).obj == obj) {
                doit = false;
                break;
            }
        }
        if (doit)
            clients.emplace(obj, priority);
    }
    
    void addClient(const client& c) {
        addClient(c.obj, c.priority);
    }
    
    //void addClient(client& c) {
        //clients.insert((c));
    //}
    
    void removeClient(t_object *obj) {
        for (auto i : clients) {
            if (i.obj == obj) {
                clients.erase(i);
                break;
            }
        }
    }
    
    std::set<client>::iterator removeClient(const std::set<client>::iterator& i) {
        return clients.erase(i);
    }
    
};


class t_sharedVariable : public t_variable, public variableClientManager, public t_safe // a global variable, with a thread locking mechanism
{
protected:
    void triggerClientsAndUnlock(t_object *x) {
        t_object *objlist[4096];
        int o = 0;
        for (auto i = clients.begin(); i != clients.end() && o < 4096; i++, o++) {
            objlist[o] = (*i).obj;
        }
        unlock();
        for (int i = 0; i < o; i++) {
            if (t_object *obj = objlist[i]; obj != x) {
                object_method_direct_cpp(void, (t_object*, long), obj, gensym("triggerfromclient"), 0);
            }
                //object_method_typed(obj, gensym("triggerfromclient"), 0, nullptr, nullptr);
        }
    }


public:
    t_sharedVariable(t_symbol *n, t_llll *ll = nullptr) :
    t_variable(n, ll), variableClientManager(), t_safe() { }
    
    using t_variable::t_variable;
    
    void set(t_llll *ll, t_object *x) {
        llll_retain(ll);
        lock();
        t_llll *releaseme = data;
        data = ll;
        triggerClientsAndUnlock(x);
        llll_release(releaseme);
    }
    
    t_llll *get() {
        lock();
        if (!data)
            data = llll_get();
        llll_retain(data);
        unlock();
        return data;
    }
    
    void addClient(t_object *obj, long priority = 0) {
        lock();
        variableClientManager::addClient(obj, priority);
        unlock();
    }

    void addClient(const client& c) {
        lock();
        variableClientManager::addClient(c);
        unlock();
    }

};


#endif /* sharedVariable_hpp */
