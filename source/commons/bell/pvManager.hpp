/*
 *  pvManager.hpp
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

#ifndef pvManager_hpp
#define pvManager_hpp

#include "bell/patcherVariable.hpp"


class pvManager final : private t_safe {
private:
    pvManager() { };
    std::unordered_map<t_symbol*, class pvault*> name2pvault;
    ~pvManager() { };
    
    static pvManager* self;
    
public:
    static pvManager* getPvManager();
    
    // call this at the end of ast creation
    t_patcherVariable* getVariable(t_symbol* name, t_object* obj);
    
    // call this at the end of ast destruction
    void removeVariable(t_symbol* name, t_object* obj);
    
    void addClient(t_symbol* name, t_object* obj, long priority);
    void removeClient(t_symbol* name, t_object* obj);

};



#endif /* pvManager_hpp */


