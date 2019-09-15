/*
 *  globalVariable.hpp
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

#ifndef globalVariable_hpp
#define globalVariable_hpp

#include "sharedVariable.hpp"


class t_globalVariable : public t_sharedVariable
{
public:
    using t_sharedVariable::t_sharedVariable;
    

};


class t_globalVariableTable : public t_safeTable<t_globalVariable *>
{
public:
    using t_safeTable<t_globalVariable *>::t_safeTable;
    
    void postNames() {
        post("EXISTING GLOBAL VARIABLES:");
        for (auto i = t.begin(); i != t.end(); i++) {
            post("- %s", i->first->s_name);
        }
        post("---------");
    }
    
    void postNamesAndValues() {
        post("EXISTING GLOBAL VARIABLES:");
        for (auto i = t.begin(); i != t.end(); i++) {
            char *buf = nullptr;
            llll_to_text_buf(i->second->get(), &buf, 0, 6, LLLL_T_NULL);
            post("- %s: %s", i->first->s_name, buf);
            bach_freeptr(buf);
        }
        post("---------");
    }
    
    void clearAll() {
        for (auto i = t.begin(); i != t.end(); i++) {
            i->second->set(llll_get(), nullptr);
        }
    }
    
};

#endif /* globalVariable_hpp */
