//
//  pvManager.hpp
//  code
//
//  Created by Andrea Agostini on 22/08/2019.
//

#ifndef pvManager_hpp
#define pvManager_hpp

#include "patcherVariable.hpp"


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


