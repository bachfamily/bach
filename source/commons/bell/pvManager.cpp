/*
 *  pvManager.cpp
 *
 * Copyright (C) 2010-2020 Andrea Agostini and Daniele Ghisi
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

#include "bell/pvManager.hpp"
#include "foundation/bach_maxutils.h"

class pvault : public variableClientManager 
{
private:
    
    class pvPatchNode {
    private:
        t_object* patcher;
        std::unordered_set<t_object *> objects;
        pvPatchNode* parent; // nullptr se è top
        
    public:
        std::unordered_set<pvPatchNode *> children;
        
        
        // also fixes the tree if child is actually a superpatch
        // of what was considered a child so far
        void introduceChild(pvPatchNode* child);
        
        // only adds the child and fixes the child's parent
        void addChild(pvPatchNode* child);
        
        void removeChild(pvPatchNode* child);
        
        void addObject(t_object *obj);
        
        // returns true if the node is now empty
        t_bool removeObject(t_object *obj);
        
        void adopt(pvPatchNode* child);
        
        t_object* getPatcher();
        
        pvPatchNode *findTop();
        
        pvPatchNode(t_object* firstObj, pvPatchNode* parent = nullptr);
        
        static void sendVariable(t_object* o, t_symbol *name, t_patcherVariable *var);
        
        // send the appropriate variable to all the objects in the hierarchy of this (which is supposed to be top)
        void sendVariableToHierarchy(t_symbol* name, t_patcherVariable* var);

        virtual ~pvPatchNode();
    };
    
    t_symbol *name;
    std::unordered_map<pvPatchNode *, t_patcherVariable *> top2var;
    //std::unordered_map<pvPatchNode*, pvPatchNode*> node2top; // i top puntano a sé stessi
    std::unordered_map<t_patcher*, pvPatchNode*> patcher2node;
    
    t_bool addTop(pvPatchNode* top); // aggiorna top2var, node2top, patcher2node. restituisce true se bisogna correggere le variabili dei nodi sotto il nuovo top.
    
    t_patcherVariable* getVar(pvPatchNode* top);
    
    // returns true if the node contains no objects anymore
    // also performs all the related housekeeping:
    // - if the node is invalidated, it gets deleted
    // - if the deleted node was top, the graph is rearranged,
    //   new variables are created if needed
    //   and they are propagated to the relevant objects
    // - if the graph is now empty, this is deleted
    t_bool removeObject(pvault::pvPatchNode *n, t_object* obj);
    
    void setTopInHierarchy(pvPatchNode* top);
    
    pvPatchNode* findPatchNode(t_patcher* p); // cerca in patcher2node
    
    pvault(t_symbol* name, pvPatchNode* firstNode);
    
    // if p has a registered super-patch, return its node
    pvPatchNode* findAncestor(t_patcher *p);
    
    pvPatchNode* insertChildOf(t_patcher *child, pvPatchNode *parent, t_object *firstObject);
    
    void registerPatch(pvPatchNode* n);
    
    void insertPatch(t_patcher *p);
    
    
    void addClient(t_object *obj, long priority = 0);
    
    ~pvault() { };
public:
    
    t_symbol* getName() { return name; }
    
    friend class pvManager;
    
};



//static pvManager* thePvManager = bach->b_thePvManager;

void pvault::pvPatchNode::introduceChild(pvPatchNode* child) {

    for (auto i = children.begin(); i != children.end(); ) {
        t_object *candidate = (*i)->patcher;
        t_object *patcher;
        
        for (patcher = patcher_getparentpatcher(candidate);
             patcher && patcher != child->patcher;
             patcher = patcher_getparentpatcher(patcher))
            ;
        
        if (patcher == child->patcher) {
            child->addChild(*i);
            i = children.erase(i);
        } else
            i++;
    }
    
    addChild(child);
}




void pvault::pvPatchNode::addChild(pvPatchNode* child) {
    children.insert(child);
    child->parent = this;
}



void pvault::pvPatchNode::removeChild(pvPatchNode* child) {
    children.erase(child);
}


void pvault::pvPatchNode::addObject(t_object *obj) {
    objects.insert(obj);
}


t_bool pvault::pvPatchNode::removeObject(t_object *obj) {
    objects.erase(obj);
    return objects.size() == 0;
}

t_object* pvault::pvPatchNode::getPatcher() {
    return patcher;
}

pvault::pvPatchNode* pvault::pvPatchNode::findTop()
{
    pvPatchNode* n = this;
    for ( ; n->parent; n = n->parent) ;
    return n;
}

pvault::pvPatchNode::pvPatchNode(t_object* firstObj, pvPatchNode* parent) : patcher(obj_getpatcher(firstObj)), parent(parent) {
    objects.insert(firstObj);
}

t_patcherVariable* pvault::getVar(pvPatchNode* top) {
    return top2var[top];
}

pvault::pvault(t_symbol* name, pvPatchNode* firstNode) : name(name) {
    addTop(firstNode);
    // which also creates the first variable
    // and links it to firstNode (which of course is top)
}

void pvault::registerPatch(pvPatchNode* n) {
    patcher2node[n->getPatcher()] = n;
}

t_bool pvault::addTop(pvPatchNode* top) {
    t_patcher *t = top->getPatcher();
    t_patcherVariable *topVar = nullptr;
    t_bool propagate = false;
    for (auto i = top2var.begin(); i != top2var.end(); ) {
        pvPatchNode *n = i->first;
        t_patcher *p = n->getPatcher();
        if (is_patcher_contained_in(p, t)) {
            if (!topVar) {
                topVar = top2var[n];
                //topVar->increase();
            } else {
                t_patcherVariable* old = top2var[n];
                for (auto i = old->clients.begin();
                     i != old->clients.end();
                     i++) {
                    // faster than addClient, since the insertion is safe
                    topVar->clients.insert(*i);
                }
                top2var[n]->decrease();
            }
            i = top2var.erase(i);
            top->addChild(n);
            propagate = true;
        } else
            i++;
    }
    
    if (!topVar)
        topVar = new t_patcherVariable(name);
    
    top2var[top] = topVar;
    registerPatch(top);
    return propagate;
}


pvault::pvPatchNode* pvault::findPatchNode(t_patcher* p) {
    if (auto found = patcher2node.find(p); found != patcher2node.end())
        return found->second;
    else
        return nullptr;
}


void pvault::pvPatchNode::sendVariable(t_object* o, t_symbol *name, t_patcherVariable *var) {
    object_method_direct_cpp(void, (t_object *, t_symbol *, t_patcherVariable *), o, gensym("setpatchervariable"), name, var);

}


void pvault::pvPatchNode::sendVariableToHierarchy(t_symbol *name, t_patcherVariable *var) {
    for (auto i = children.begin(); i != children.end(); i++) {
        (*i)->sendVariableToHierarchy(name, var);
    }
    for (auto j = objects.begin(); j != objects.end(); j++) {
        sendVariable(*j, name, var);
    }
}


pvault::pvPatchNode* pvault::findAncestor(t_patcher *p) {
    for (p = patcher_getparentpatcher(p);
         p;
         p = patcher_getparentpatcher(p)) {
        if (pvault::pvPatchNode* n = findPatchNode(p) ; n)
            return n;
    }
    return nullptr;
}

t_bool pvault::removeObject(pvault::pvPatchNode *n, t_object* obj) {
    
    removeClient(obj);

    if (!n->removeObject(obj)) {
        // obj is not the only object in its patcher
        pvPatchNode *top = n->findTop();
        t_patcherVariable *var = top2var[top];
        var->removeClient(obj);
        return false;
    }
    
    // obj is the only object in its patcher
    patcher2node.erase(n->getPatcher());
    auto found = top2var.find(n);
    
    if (found == top2var.end()) {
        // n is not top
        pvPatchNode *top = n->findTop();
        t_patcherVariable *var = top2var[top];
        var->removeClient(obj);
        delete n;
        return false;
    }
    
    // n is top: we must promote to top all its previous children
    t_patcherVariable *origV = found->second;
    origV->removeClient(obj);
    top2var.erase(found);
    
    if (auto i = n->children.begin(); i != n->children.end()) {
        // the first child gets the original variable
        top2var[*i] = origV;
        i++;
        // all the other children receive copies of the original variable
        for ( ; i != n->children.end(); i++) {
            t_patcherVariable* copy = new t_patcherVariable(origV);
            top2var[*i] = copy;
            (*i)->sendVariableToHierarchy(name, copy);
        }
    } else {
        
        // or, if the previous top had no children, we must delete its variable
        delete origV;
        origV = nullptr;
    }
    
    if (top2var.size() == 0) {
        // the vault is empty now
        delete n;
        delete this;
        return true;
    }
    
    // the vault is not empty:
    // the previous variable's clients must be redistributed among the new variables
    // to do so,
    delete n;
    if (origV) {
        std::set<t_object*> removeSet;
        for (auto i = origV->clients.begin(); i != origV->clients.end(); ) {
            t_patcher *p = obj_getpatcher((*i).obj);
            pvPatchNode *pnode = patcher2node[p];
            pvPatchNode *topnode = pnode->findTop();
            t_patcherVariable *newVar = top2var[topnode];
            if (newVar != origV) {
                newVar->addClient(*i);
                i = origV->removeClient(i);
            } else
                i++;
        }
    }
    return false;
}

pvault::pvPatchNode* pvault::insertChildOf(t_patcher *child, pvPatchNode *parent, t_object *firstObject) {
    pvPatchNode* n = new pvPatchNode(firstObject, parent);
    parent->introduceChild(n);
    registerPatch(n);
    return n;
}

pvault::pvPatchNode::~pvPatchNode() {
    if (parent) {
        parent->removeChild(this);
        for (auto i = children.begin(); i != children.end(); i++)
            parent->addChild(*i);
    } else {
        for (auto i = children.begin(); i != children.end(); i++)
            (*i)->parent = nullptr;
    }
}


void pvault::addClient(t_object *obj, long priority)
{
    variableClientManager::addClient(obj, priority);
    pvPatchNode *top = findPatchNode(obj_getpatcher(obj))->findTop();
    top2var[top]->addClient(obj, priority);
}



//pvManager* pvManager::self = nullptr;

t_patcherVariable* pvManager::getVariable(t_symbol* name, t_object* obj) {
    pvault *v;
    t_bool propagate = false;
    pvault::pvPatchNode* n;
    
    lock();
    
    if (auto found = name2pvault.find(name); found != name2pvault.end()) {
        v = found->second;
        t_patcher *p = obj_getpatcher(obj);
        n = v->findPatchNode(p);
        if (n) {
            n->addObject(obj);
        } else if (pvault::pvPatchNode* a = v->findAncestor(p) ; a) {
            n = v->insertChildOf(p, a, obj);
        } else {
            n = new pvault::pvPatchNode(obj);
            propagate = v->addTop(n);
        }
    } else {  
        n = new pvault::pvPatchNode(obj);
        v = new pvault(name, n);
        name2pvault[name] = v;
    }
    
    pvault::pvPatchNode* top = n->findTop();
    t_patcherVariable *var = v->getVar(top);
    
    if (!propagate)
        n->sendVariable(obj, name, var);
    else
        top->sendVariableToHierarchy(name, var);
    
    unlock();
    
    return var;
}

void pvManager::removeVariable(t_symbol* name, t_object* obj)
{
    lock();
    
    t_patcher *p = obj_getpatcher(obj);
    
    // v might not exist if the variable is deleted
    // before being actually created
    // (can happen when bach.eval loads the code from the dictionary)
    if (auto i = name2pvault.find(name); i != name2pvault.end()) {
        pvault *v = i->second;
        if (pvault::pvPatchNode* n = v->findPatchNode(p); n) {
            if (v->removeObject(n, obj)) { // if the vault has been deleted
                name2pvault.erase(name);
            }
        }
    }
    unlock();
}

void pvManager::addClient(t_symbol *name, t_object *obj, long priority)
{
    name2pvault[name]->addClient(obj, priority);
}

void pvManager::removeClient(t_symbol *name, t_object *obj)
{
    name2pvault[name]->removeClient(obj);
}

/*
pvManager* pvManager::getPvManager()
{
    if (self == nullptr)
        self = new pvManager();
    return self;
}
*/
