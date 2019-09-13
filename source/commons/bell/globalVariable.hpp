//
//  globalVariable.hpp
//  code
//
//  Created by Andrea Agostini on 19/08/2019.
//

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
