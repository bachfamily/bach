/*
 *  patcherVariable.hpp
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

#ifndef patcherVariable_hpp
#define patcherVariable_hpp

#include "bell/sharedVariable.hpp"
#include <unordered_set>
#include <unordered_map>

// a variable associated to a patcher hierarchy
class t_patcherVariable : public t_sharedVariable
{
public:
    t_patcherVariable(t_symbol *name, t_llll *ll = nullptr) : t_sharedVariable(name, ll) { }

    t_patcherVariable(t_patcherVariable* orig) : t_sharedVariable(orig->getName(), llll_clone(orig->get())) { }    
};



#endif /* patcherVariable_hpp */
