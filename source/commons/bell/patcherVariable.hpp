//
//  patcherVariable.hpp
//  code
//
//  Created by Andrea Agostini on 19/08/2019.
//

#ifndef patcherVariable_hpp
#define patcherVariable_hpp

#include "sharedVariable.hpp"
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
