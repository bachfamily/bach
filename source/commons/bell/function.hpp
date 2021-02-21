/*
 *  function.hpp
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

#ifndef function_hpp
#define function_hpp

#include "bell/astNode.hpp"
#include <unordered_set>
#define BELL_MAX_RECURSION_DEPTH 1000

class funArg {
protected:
    t_symbol *sym;
    astNode *node;
    countedList<t_localVar> *varsList;
    t_localVar *vars;
    
public:
    funArg(t_symbol *sym, astNode *node = nullptr) : sym(sym), node(node), varsList(nullptr), vars(nullptr) { };
    
    funArg(t_symbol *sym, astNode *node, countedList<t_localVar> *v) : funArg(sym, node) {
        if (v) {
            varsList = new countedList<t_localVar>(v);
        } else
            varsList = nullptr;
    };
    
    virtual ~funArg() {
        if (varsList)
            delete varsList;
        if (vars)
            delete[] vars;
    }
    
    void conform() {
        if (varsList) {
            varsList->copyIntoNullTerminatedArray(&vars);
            delete varsList;
            varsList = nullptr;
        }
    };
    
    t_symbol* getSym() { return sym; };
    astNode* getNode() { return node; };
    countedList<t_localVar> *getVarsList() { return varsList; };
    t_localVar *getVars() { return vars; };
};

class t_function : public t_countable
{
private:
    funArg *idx2argNameAndDefaultPool[512] { }; // 1-based (thus [0] is left empty)

protected:
    int namedArgumentsCount;
    int namedArgumentsCountAfterEllipsis; // which can't be passed by position

    funArg **idx2argNameAndDefault; // 1-based (thus [0] is left empty)

public:
    std::unordered_map<t_symbol*, long> argName2idx;

protected:
    t_bool variadic;
    
    t_function() :  namedArgumentsCount(0),
                    namedArgumentsCountAfterEllipsis(0),
                    idx2argNameAndDefault(idx2argNameAndDefaultPool + 256) { }
    
    virtual ~t_function() {
        for (funArg** thisANAD = idx2argNameAndDefault + 1; *thisANAD; thisANAD++) delete *thisANAD;
        for (funArg** thisANAD = idx2argNameAndDefault - 1; *thisANAD; thisANAD--) delete *thisANAD;
    };
    t_symbol *name;
    
    void setArgument(const char *name, long def, t_codableobj *obj = nullptr);
    void setArgument(const char *name, t_llll* def, t_codableobj *obj = nullptr);
    void setArgument(const char *name, t_symbol* def, t_codableobj *obj = nullptr);
    void setArgument(const char *name, astConst *node);
    void setArgument(const char *name) { setArgument(name, (astConst *) 0); };
    
public:
    virtual t_llll* call(const t_execEnv &context) = 0;

    long getNamedArgumentsCount() { return namedArgumentsCount; };
    long getNamedArgumentsCountAfterEllipsis() { return namedArgumentsCountAfterEllipsis; };

    t_bool isVariadic() { return variadic; };


    funArg* getArgNameAndDefault(long const n);
    long getArgIdx(t_symbol *s);
    
    virtual void setOutletData(long outlet, t_llll *ll) { };
    t_symbol* getName() { return name; };
    
    virtual t_localVar* getLocalVariables() { return nullptr; };
    
    virtual void keep(t_symbol* name, t_llll* ll) { }
    virtual void unkeep(t_symbol *name) { }
    virtual t_llll *retrieve(t_symbol* name) { return nullptr; }
    

};

class t_userFunction : public t_function
{
protected:
    
    class keptTable : public t_safe {
    private:
        std::unordered_map <t_symbol*, t_llll*> t;
        t_llll *find(t_symbol *name) {
            if (auto found = t.find(name); found != t.end())
                return found->second;
            else
                return nullptr;
        }
        
    public:
        virtual ~keptTable() {
            for (auto i : t)
                llll_free(i.second);
        }
        
        void insert(t_symbol* name, t_llll* ll) {
            lock();
            llll_release(find(name));
            t[name] = llll_retain(ll);
            unlock();
        }
        
        void remove(t_symbol* name) {
            lock();
            if (auto found = t.find(name); found != t.end()) {
                t_llll *releaseme = found->second;
                llll_release(releaseme);
                t.erase(found);
            }
            unlock();
        }
        
        t_llll* lookup(t_symbol* name) {
            lock();
            t_llll *ll = llll_retain(find(name));
            unlock();
            return ll;
        }
        
    };
    
    t_localVar *localVariables;
    keptTable kept;

    astNode *ast;
    t_userFunction() { }
    
    virtual ~t_userFunction();

public:
    t_userFunction(countedList<funArg *> *argumentsList, countedList<t_localVar> *localVariablesList, astNode *ast, t_codableobj *culprit);
    
    virtual t_llll* call(const t_execEnv &context);
    virtual t_localVar* getLocalVariables() { return localVariables; };
    
    void keep(t_symbol* name, t_llll* ll) { return kept.insert(name, ll); }
    void unkeep(t_symbol *name) { kept.remove(name); }
    virtual t_llll *retrieve(t_symbol* name) { return kept.lookup(name); }
};

using pvMap = std::unordered_map<t_symbol*, std::unordered_set<astPatcherVar*>>;

class t_mainFunction : public t_userFunction
{
private:
    long outlets;
    t_llll *outletData[256] { };
    static t_function *outletFn;
    long inlet;
    pvMap *name2astVars;
    std::unordered_set<t_globalVariable*> *globalVars;
    t_codableobj *owner;
    
    void removePatcherVars();
    
protected:
    virtual ~t_mainFunction();
    
public:
    t_mainFunction(astNode *mainAst,
                   countedList<t_localVar> *localVariablesList,
                   std::unordered_set<t_globalVariable*> *globalVariables,
                   pvMap *name2astVars,
                   t_codableobj *caller);
    
    virtual t_llll* call(t_execEnv const &context);

    void setOutletData(long outlet, t_llll *ll);
    
    void setOutlets(long n) { outlets = n; };
    
    void setInlet(long n) { inlet = n; }
    long getInlet() { return inlet; }
    
    void resolvePatcherVars();
    
    void setPatcherVar(t_symbol* name, t_patcherVariable* var);
    
    void makeClientToAllGVs(long priority);

    void makeClientToAllPVs(long priority);
    
    void removeFromGlobalVarsClients();

    void clearOutletData();
    
    t_llll *getOutletData(long outlet) {
        return outletData[outlet];
    }
};



class astFunctionCall : public astNode
{
private:
    astNode *functionNode;
    long argsByPositionCount;
    astNode **argsByPosition;
    t_bool OopStyleCall;
    long argsByNameCount;
    astNode **argsByName;
    t_symbol **argsNames;
    
    // to be called by eval()
    t_llll *callFunction(t_function *fn, t_llll **argsByPositionLl, t_llll **argsByNameLl, t_execEnv const &context);
    
public:
    // to be called by apply
    static t_llll *callFunction(t_function *fn, t_llll *argsByPositionLl, t_llll *argsByNameLl, t_execEnv const &context);

    astFunctionCall(astNode *functionNode, countedList<astNode *> *argsByPositionList, countedList<symNodePair *> *argsByNameList, t_codableobj *owner);
    
    void addOopStyleArg(astNode *arg);
    
    void setOopStyleArgValue(t_llll *ll);
    
    void setOopStyleArg(t_llll *ll);
    
    ~astFunctionCall();
    
    t_llll *eval(t_execEnv const &context);
};


template <typename BASE>
class astRichAccessApplyOp : public BASE
{
private:
    astFunctionCall *functionCall;
public:
    astRichAccessApplyOp(typename BASE::firstType *lNode,
                 astFunctionCall *functionCall,
                 lvalueStepList *lvalueStepList,
                         t_codableobj *owner)  :
    BASE(lNode, nullptr, lvalueStepList, owner),
    functionCall(functionCall) { }
    
    ~astRichAccessApplyOp() {
        delete functionCall;
    }
    
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        t_llll *hereV = llll_get();
        llll_appendhatom_clone(hereV, &lookHere->l_hatom);
        functionCall->setOopStyleArgValue(hereV);
        t_llll *res = functionCall->eval(context);
        llll_replacewith<false>(current, lookHere, res);
    }
    
    void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        t_llll *v = llll_clone(subll);
        llll_destroyelem(v->l_head);
        functionCall->setOopStyleArgValue(v);
        t_llll *res = functionCall->eval(context);
        llll_destroy_everything_but_head(subll);
        llll_chain(subll, res);
    }
};


class astKeep : public astLocalVar
{
public:
    astKeep(t_symbol *name, t_codableobj *owner) : astLocalVar(name, owner) { }
    
    virtual ~astKeep() { }
    
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll = astLocalVar::eval(context);
        context.owner->keep(name, ll);
        return ll;
    }
    
    void assign(t_llll *ll, t_execEnv const &context) {
        astLocalVar::assign(ll, context);
        context.owner->keep(name, ll);
    }
};


class astUnkeep : public astLocalVar
{
public:
    astUnkeep(t_symbol *name, t_codableobj *owner) : astLocalVar(name, owner) { }
    
    virtual ~astUnkeep() { }
    
    t_llll *eval(t_execEnv const &context) {
        t_llll *ll = astLocalVar::eval(context);
        context.owner->unkeep(name);
        return ll;
    }
    
    void assign(t_llll *ll, t_execEnv const &context) {
        astLocalVar::assign(ll, context);
        context.owner->unkeep(name);
    }
};


class astInit : public astLocalVar
{
private:
    astNode *value;
public:
    astInit(t_symbol *name, astNode *value, t_codableobj *owner) : astLocalVar(name, owner), value(value) { }
    
    ~astInit() {
        delete value;
    }
    
    t_llll *eval(t_execEnv const &context) {
        if (context.owner->retrieve(name)) {
            return astLocalVar::eval(context);
        } else {
            t_llll *v = value->eval(context);
            assign(v, context);
            return v;
        }
    }
    
    void assign(t_llll *ll, t_execEnv const &context) {
        astLocalVar::assign(ll, context);
        context.owner->unkeep(name);
    }
};

#endif /* function_hpp */
