/*
 *  astNode.hpp
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

#ifndef ast_hpp
#define ast_hpp

#include "bell/globalVariable.hpp"
#include "bell/patcherVariable.hpp"
#include "bell/eval.h"
#include <set>

class astNode;

typedef std::unordered_map<t_symbol *, t_variable *> t_scope;


class symNodePair {
protected:
    t_symbol *sym;
    astNode *node;
public:
    symNodePair(t_symbol *sym = nullptr, astNode *node = nullptr) : sym(sym), node(node) { }
    t_symbol *getSym() { return sym; }
    astNode *getNode() { return node; }
    void set(t_symbol *s, astNode *n) { sym = s; node = n; }
};


template <typename T>
class countedList {
private:
    countedList<T>* getPrev() { return prev; }

protected:
    T item;
    countedList<T> *prev;
    countedList<T> *next;
    countedList<T> *head;
    int *count;
public:
    countedList<T>(T i, countedList<T> *p = nullptr) : item(i) {
        if (p == nullptr) {
            count = new int;
            *count = 1;
            prev = nullptr;
            head = this;
        } else {
            count = p->count;
            (*count)++;
            prev = p;
            p->next = this;
            head = p->head;
        }
        next = nullptr;
    }
    
    countedList<T>(countedList<T>&& that) // doesn't work: why?
    {
        item = that.item;
        prev = nullptr;
        next = that.next;
        next->prev = this;
        count = that.count;
        that.next = nullptr;
        that.count = nullptr;
    }
    
    countedList<T>(countedList<T> *that)
    {
        item = that->item;
        prev = that->prev;
        if (prev)
            prev->next = this;
        next = that->next;
        if (next)
            next->prev = this;
        if (that->head == that)
            head = this;
        else
            head = that->head;
        count = that->count;
        that->prev = nullptr;
        that->next = nullptr;
        that->count = nullptr;
        that->head = that;
    }
    
    
    virtual ~countedList<T>() {
        if (next)
            delete next;
        if (count) {
            if (*count == 1) {
                delete count;
            } else {
                --(*count);
            }
        }
    }
    
    int getCount() { return *count; }
    T getItem() { return item; }
    countedList<T>* getNext() { return next; }
    countedList<T>* getHead() { return head; }
    
    void copyIntoNullTerminatedArray(T** array)
    {
        *array = new T [*count + 1];
        countedList<T> *item;
        long idx;
        for (item = getHead(), idx = 0;
             item;
             item = item->getNext(), idx++) {
            (*array)[idx] = item->getItem();
        }
        (*array)[idx] = nullptr;
    };

/*
    countedList<T>* prune(t_bool (*check)(T* toCheck, void *data), void *data) {
        countedList<T> *previous, *current, *nextOne;
        for (previous = this, current = this->next; current; current = nextOne) {
            nextOne = current->next;
            if (!(check)(current->item, data)) {
                previous->next = nextOne;
                current->next = nullptr;
                delete current;
            }
        }
        if ((check)(item, data)) {
            return this;
        } else {
            countedList<T> *nextOne = next;
            delete this;
            return nextOne;
        }
    }
 */
};


class t_userFunction;
class t_mainFunction;

enum eLoopKinds {
    E_LOOP_DO,
    E_LOOP_COLLECT
};

template<eLoopKinds KIND> class astForLoop;

class t_execEnv
{
private:
    std::set<t_variable *> localVariables;
    t_llll *argvPool[512] { };

public:
    struct llllobj_object *obj;
    long argc;
    t_llll **argv;
    long functionStackDepth;
    t_mainFunction *mainFunc;
    t_function *owner;
    t_execEnv const * const parent;
    t_execEnv * const root;
    t_scope scope;
    t_uint32 stopTime;
    t_bool timeOver; // only used in the root environment

private:
    void setVariableFromArgByPosition(t_function *fn, long i);

public:
    // this constructor is only called for the root environment,
    // i.e., the parent of the actual context of main.
    // So we don't need a lot of stuff here.
    t_execEnv(struct llllobj_object *obj, t_mainFunction *mainFunc, t_uint32 stopTime = 0) : obj(obj), argc(0), argv(argvPool + 256), functionStackDepth(0), mainFunc(mainFunc), owner(reinterpret_cast<t_function*>(mainFunc)), parent(nullptr), root(this), stopTime(stopTime), timeOver(false) {
    };

    // called for function calls
    t_execEnv(t_execEnv const * const parent, t_function *owner) : obj(parent->obj), argc(0), argv(argvPool + 256), functionStackDepth(parent->functionStackDepth + 1), mainFunc(parent->mainFunc), owner(owner), parent(parent), root(parent->root), stopTime(parent->stopTime), timeOver(false) { };

    // called for setting defaults
    t_execEnv(t_execEnv const * const parent) : obj(parent->obj), argc(parent->argc), argv(argvPool + 256), functionStackDepth(parent->functionStackDepth + 1), mainFunc(parent->mainFunc), owner(parent->owner), parent(parent), root(parent->root), stopTime(parent->stopTime), timeOver(false) { };
    
    ~t_execEnv();

    
    // returns the position of the first named argument in argv
    // (non-0 only if the function is left-variadic)
    long setFnArgsByPosition(t_function *fn, long argc, t_llll **argv);
    
    // variant for apply
    long setFnArgsByPosition(t_function *fn, t_llll *args);
    
    
    // offset is the return value of setFnArgsByPosition
    void setFnArgsByName(t_function *fn, long ac, t_symbol **names, t_llll **values, long firstNamedArgumentOffset);

    // variant for apply
    void setFnArgsByName(t_function *fn, t_llll *args, long firstNamedArgumentOffset);

    
    void setFnArgNames(t_function *fn);

    // offset is the return value of setFnArgsByPosition
    // skip is the number of arguments that will be passed by position by the lambda caller
    void setFnDefaults(t_function *fn, long firstNamedArgumentOffset, long skip);
    
    void setRootParams(long ac, t_symbol **names, t_llll **values);

    // to be called at every round of every lambda function
    void resetFnNamedArgs(t_function *fn, long lambdaParams);

    void setFnLocalVariables(t_function *fn);
    void resetLocalVariables();

    // abpc is the number of arguments passed by position to the function
    void adjustArgc(t_function *fn, long abpc);
    
    template <eLoopKinds kind> void setForLoopScope(astForLoop<kind> const &forLoop);
    void setUniquePseudovariables(t_symbol **names);
    void setLocalVariables(t_symbol **varNames, t_function *fn = nullptr);

    t_bool stopTimeReached() const {
        if (root->timeOver || (stopTime > 0 && systime_ms() > stopTime)) {
            if (!root->timeOver)
                object_warn((t_object *) obj, "Time limit exceeded");
            root->timeOver = true;
            return true;
        } else
            return false;
        
    };
    
};

class t_function;

class astNode
{
protected:
    t_codableobj *owner;
    astNode(t_codableobj *owner) : owner(owner) { }
public:
    virtual ~astNode() { }
    virtual t_llll *eval(t_execEnv const &context) = 0;
};

class astConst : public astNode
{
protected:
    t_llll *v;
public:
    
    astConst(t_codableobj *owner) : astNode(owner), v(nullptr) { }
    
    astConst(t_llll *ll, t_codableobj *owner) : astNode(owner), v(ll) { }

    ~astConst() { bell_release_llll(v); }
    
    astConst(const long l, t_codableobj *owner = nullptr);
    astConst(const t_rational r, t_codableobj *owner = nullptr);
    astConst(const double d, t_codableobj *owner = nullptr);
    astConst(const t_pitch &p, t_codableobj *owner = nullptr);
    astConst(t_symbol *s, t_codableobj *owner = nullptr);
    astConst(t_function *f, t_codableobj *owner = nullptr);
    
    void set(t_llll *ll);
    
    t_llll *eval(t_execEnv const &context) {
        return bell_retain_llll(v);
    }
};

class astVar : public astNode
{
protected:
    astVar(t_codableobj *owner) : astNode(owner) { }
public:
    virtual t_variable *getVar(t_execEnv const &context) = 0;
    virtual void assign(t_llll *ll, t_execEnv const &context) = 0;
};

class astGlobalVar : public astVar
{
protected:
    t_globalVariable *sv;
public:
    astGlobalVar(t_globalVariableTable *gvt, t_symbol *name, t_codableobj *owner);
    astGlobalVar(astGlobalVar *v) : astVar(v->owner), sv(v->sv) { };
    
    t_globalVariable *getVar(t_execEnv const &context) { return getVar(); }
    
    t_globalVariable *getVar() { return sv; }
    
    void assign(t_llll *ll, t_execEnv const &context) { assign(ll); }
    
    void assign(t_llll *ll) { sv->set(ll, (t_object *) owner); }
    
    t_llll *eval(t_execEnv const &context) { return eval(); }
    
    t_llll *eval() { return sv->get(); }
};

class astPatcherVar : public astVar
{
protected:
    t_patcherVariable *pv;
    t_symbol *name;
public:
    astPatcherVar(t_symbol *name, t_codableobj *owner) : astVar(owner), name(name) { }
    
    astPatcherVar(astPatcherVar *v) : astVar(v->owner), pv(v->pv) { }
    
    void setVar(t_patcherVariable *var) { pv = var; }
    
    t_patcherVariable* getVar(t_execEnv const &context) { return getVar(); }
    
    t_patcherVariable* getVar() { return pv; }
    
    t_symbol* getName() { return name; }
    
    void assign(t_llll *ll, t_execEnv const &context) { assign(ll); }
    
    void assign(t_llll *ll) { pv->set(ll, (t_object *) owner); }
    
    t_llll *eval(t_execEnv const &context) { return eval(); }
    
    t_llll *eval() { return pv->get(); }
};




class astLocalVar : public astVar
{
private:
protected:
    t_symbol *name;
public:
    astLocalVar(t_symbol *name, t_codableobj *owner) : astVar(owner), name(name) { }
    
    astLocalVar(astLocalVar *v) : astVar(v->owner), name(v->name) { };
    t_variable *getVar(t_execEnv const &context);
    
    void assign(t_llll *ll, t_execEnv const &context) { getVar(context)->set(ll); }
    
    t_symbol *getName() { return name; }

    t_llll *eval(t_execEnv const &context) { return getVar(context)->get(); }
};

class astInlet : public astNode
{
protected:
    int idx;
public:
    astInlet(int idx, t_codableobj *owner) : astNode(owner), idx(idx) { }

    t_llll *eval(t_execEnv const &context);
};


class astWrap : public astNode
{
protected:
    astNode *n1;
public:
    astWrap(astNode *n1, t_codableobj *owner) : astNode(owner), n1(n1) { }
    
    ~astWrap() {
        delete n1;
    }
    
    t_llll *eval(t_execEnv const &context);
};

class astConcat : public astNode
{
protected:
    astNode *n1;
    astNode *n2;
public:
    astConcat(astNode *n1, astNode *n2, t_codableobj *owner) : astNode(owner), n1(n1), n2(n2) { }
    
    ~astConcat() {
        delete n1;
        delete n2;
    }
    
    t_llll *eval(t_execEnv const &context);
};

class astConcatAssignOp : public astNode
{
protected:
    astVar *varNode;
    astNode *dataNode;
public:
    astConcatAssignOp(astVar *varNode, astNode *dataNode, t_codableobj *owner) : astNode(owner), varNode(varNode), dataNode(dataNode) { }
    
    ~astConcatAssignOp() {
        delete varNode;
        delete dataNode;
    }
    
    t_llll *eval(t_execEnv const &context);
};

class astRevConcatAssignOp : public astNode
{
protected:
    astVar *varNode;
    astNode *dataNode;
public:
    astRevConcatAssignOp(astVar *varNode, astNode *dataNode, t_codableobj *owner) : astNode(owner), varNode(varNode), dataNode(dataNode) { }
    
    ~astRevConcatAssignOp() {
        delete varNode;
        delete dataNode;
    }
    
    t_llll *eval(t_execEnv const &context);
};

class astSequence : public astNode
{
protected:
    astNode *n1;
    astNode *n2;
public:
    astSequence(astNode *n1, astNode *n2, t_codableobj *owner) : astNode(owner), n1(n1), n2(n2) { }

    ~astSequence() {
        delete n1;
        delete n2;
    }
    
    t_llll *eval(t_execEnv const &context) {
        bell_release_llll(n1->eval(context));
        if (!context.stopTimeReached())
            return n2->eval(context);
        else
            return llll_get();
    }
};

class astNthOp : public astNode
{
protected:
    astNode *dataNode;
    astNode *addressNode;
public:
    astNthOp(astNode *dataNode, astNode *addressNode, t_codableobj *owner) : astNode(owner), dataNode(dataNode), addressNode(addressNode) { }
    
    ~astNthOp() {
        delete dataNode;
        delete addressNode;
    }
    
    t_llll *eval(t_execEnv const &context);
    
};

class astNthAssignOp : public astNode
{
protected:
    astVar *varNode;
    astNode *addressNode;
public:
    astNthAssignOp(astVar *varNode, astNode *addressNode, t_codableobj *owner) : astNode(owner), varNode(varNode), addressNode(addressNode) { }
    
    ~astNthAssignOp() {
        delete varNode;
        delete addressNode;
    }
    
    t_llll *eval(t_execEnv const &context);
    
};


class astPickOp : public astNode
{
protected:
    astNode *dataNode;
    astNode *addressNode;
public:
    astPickOp(astNode *dataNode, astNode *addressNode, t_codableobj *owner) : astNode(owner), dataNode(dataNode), addressNode(addressNode) { }
    
    ~astPickOp() {
        delete dataNode;
        delete addressNode;
    }
    
    t_llll *eval(t_execEnv const &context);
    
};


class astRangeOp : public astNode
{
protected:
    astNode *startNode;
    astNode *endNode;
public:
    astRangeOp(astNode *startNode, astNode *endNode, t_codableobj *owner) : astNode(owner), startNode(startNode), endNode(endNode) { }
    
    ~astRangeOp() {
        delete startNode;
        delete endNode;
    }
    
    t_llll *eval(t_execEnv const &context);
    
};






enum keyOpKind {
    e_keyOpStandard,
    e_keyOpUnwrapping
};

template <keyOpKind KIND>
class astKeyOp : public astNode
{
protected:
    astNode *dataNode;
    astNode *keyNode;
public:
    astKeyOp(astNode *dataNode, astNode *keyNode, t_codableobj *owner) : astNode(owner), dataNode(dataNode), keyNode(keyNode) { }
    
    ~astKeyOp() {
        delete dataNode;
        delete keyNode;
    }
    
    t_llll *eval(t_execEnv const &context) {
        
        t_llll *datall = dataNode->eval(context);
        t_llll *keysll = keyNode->eval(context);
        t_llll *resll = llll_get();

        
        t_llllelem **elempile = (t_llllelem **) bach_newptr((keysll->l_depth - 1) * sizeof(t_llllelem *));
        t_llllelem **thisElempile = elempile;
        t_llllelem *keysElem = keysll->l_head;
        
        while (1) {
            while (keysElem) {
                if (t_llll *subkeysll = hatom_getllll(&keysElem->l_hatom); subkeysll) {
                    t_llllelem *resElem = llll_appendllll(resll, llll_get());
                    *thisElempile = keysElem;
                    thisElempile++;
                    keysElem = keysElem->l_hatom.h_w.w_llll->l_head;
                    resll = resElem->l_hatom.h_w.w_llll;
                } else {
                    for (auto dataElem = datall->l_head; dataElem; dataElem = dataElem->l_next) {
                        if (t_llll *subdatall = hatom_getllll(&dataElem->l_hatom); subdatall && subdatall->l_size > 0) {
                            if (hatom_eq(&keysElem->l_hatom, &subdatall->l_head->l_hatom)) {
                                t_llll *value = llll_clone(subdatall);
                                llll_destroyelem(value->l_head);
                                if constexpr(KIND == e_keyOpStandard)
                                    llll_chain(resll, value);
                                else
                                    llll_appendllll(resll, value);
                                break;
                            }
                        }
                    }
                    keysElem = keysElem->l_next;
                }
            }
            if (thisElempile == elempile)
                break;
            resll = resll->l_owner->l_parent;
            keysElem = (*--thisElempile)->l_next;
        }
        
        bach_freeptr(elempile);
        bell_release_llll(datall);
        bell_release_llll(keysll);
        return resll;
    }
    
};


class lvalueStep {
public:
    enum lvalueOpTypes {
        E_LV_NTH,
        E_LV_KEY
    };
    
    lvalueOpTypes type;
    astNode *value;
    
public:
    lvalueStep(lvalueOpTypes type, astNode *value) : type(type), value(value) { };
    virtual ~lvalueStep() {
        delete value;
    }
};

typedef countedList<lvalueStep*> lvalueStepList;

template<typename firstType>
class astTwoSided : public astNode
{
protected:
    firstType *lNode;
    astNode *rNode;
    
    astTwoSided(firstType *lNode,
              astNode *rNode,
              t_codableobj *owner) : astNode(owner), lNode(lNode), rNode(rNode) { }
    
};

class astAssign : public astTwoSided<astVar>
{
public:
    astAssign(astVar *lNode,
                astNode *rNode,
                t_codableobj *owner) : astTwoSided<astVar>(lNode, rNode, owner) { }
    ~astAssign() {
        delete rNode;
    };
    
    t_llll *eval(t_execEnv const &context);
};

class astNonAssign : public astTwoSided<astNode>
{
protected:
    using astTwoSided<astNode>::astTwoSided;
    ~astNonAssign() {
        delete lNode;
        delete rNode;
    }
};



enum richAssignTypes {
    E_RA_STANDARD,
    E_RA_SHORTCIRCUIT
};


template <
typename BASE,
richAssignTypes TYPE = E_RA_STANDARD
>
class AstRichAccessNode : public BASE
{
private:
    
    int nLvSteps;
    lvalueStep** lvStep;

protected:
    typedef typename std::conditional<std::is_same<BASE, astAssign>::value, astVar, astNode>::type firstType;
    
    void lastKey(lvalueStep** step, t_llllelem* &lookHere, t_llll* &current, t_llll* origV, t_execEnv const &context) {
        t_llll *key = (*step)->value->eval(context);
        switch (key->l_size) {
            case 0:
                object_warn((t_object *) context.obj, "rich variable assignment with null key");
                current = nullptr;
                break;
            default:
                object_warn((t_object *) context.obj, "rich variable assignment with more than one key: only the first will be considered");
            case 1:
            {
                t_hatom *keyHatom = &key->l_head->l_hatom;
                for ( ; lookHere ; lookHere = lookHere->l_next) {
                    if (t_llll *subll = hatom_getllll(&lookHere->l_hatom); subll && subll->l_size >= 1) {
                        t_llllelem *subHead = subll->l_head;
                        if (hatom_eq(&subHead->l_hatom, keyHatom)) {
                            lastKeyDo(subll, origV, context);
                            return;
                        }
                    }
                }
                break;
            }
        }
        llll_free(key);
    }
    
    
    
    void lastNth(lvalueStep** step, int nStep, t_llllelem* &lookHere, t_llll* &current, t_llll* origV, t_bool previousWasKey, t_execEnv const &context) {
        t_bool created = nonLastNth(step, nStep, lookHere, current, previousWasKey, context);
        if (current)
            lastNthDo(current, lookHere, origV, created, context);
    }
    
    static t_bool nonLastNth(lvalueStep** step, int nStep, t_llllelem* &lookHere, t_llll* &current, t_bool previousWasKey, t_execEnv const &context) {
        t_bool created = false;
        t_llll *address = (*step)->value->eval(context);
        if (address->l_depth > 1) {
            object_error((t_object *) context.obj, "rich variable assignment doesn't support multiple nth syntax");
            current = nullptr;
        } else if (address->l_size == 0) {
            object_error((t_object *) context.obj, "null term in rich variable assignment");
            current = nullptr;
        } else {
            t_llllelem *address_elem = address->l_head;
            
            long address_step = hatom_getlong(&address_elem->l_hatom);
            if (address_step == 0) {
                if (nStep > 0 && (*(step - 1))->type == lvalueStep::E_LV_KEY) {
                    lookHere = current->l_head;
                } else {
                    lookHere = nullptr;
                    current = nullptr;
                    return false;
                }
            } else
                created = consumeNthAddressLevel(lookHere, current, address_step, previousWasKey);
            
            if ((address_elem = address_elem->l_next)) {
                address_step = hatom_getlong(&address_elem->l_hatom);
                current = hatom_getllll(&lookHere->l_hatom);
                if (current)
                    lookHere = current->l_head;
                else {
                    lookHere = nullptr;
                    current = nullptr;
                    return false;
                }
            }
            
            // THIS DOES THE FIRST TERM OF THE ADDRESS, BUT WHAT ABOUT THE NEXT ONES?
            
            for (; address_elem; ) {
                created = consumeNthAddressLevel(lookHere, current, address_step, previousWasKey);
                
                if ((address_elem = address_elem->l_next)) {
                    address_step = hatom_getlong(&address_elem->l_hatom);
                    current = hatom_getllll(&lookHere->l_hatom);
                    if (current)
                        lookHere = current->l_head;
                    else {
                        lookHere = nullptr;
                        current = nullptr;
                        return false;
                    }
                }
            }
        }
        
        
        llll_free(address);
        return created;
    }
    
    virtual void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        llll_destroy_everything_but_head(subll);
        llll_chain(subll, llll_clone(origV));
        return;
    }
    
    virtual void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        llll_replacewith(current, lookHere, origV);
    }
    
private:
    static void nonLastKey(lvalueStep** step, t_llllelem* &lookHere, t_llll* &current, t_execEnv const &context) {
        t_llll *key = (*step)->value->eval(context);
        switch (key->l_size) {
            case 0:
                object_warn((t_object *) context.obj, "rich variable assignment with null key has no effect");
                lookHere = nullptr;
                current = nullptr;
                break;
            default:
                object_warn((t_object *) context.obj, "rich variable assignment with more than one key: only the first will be considered");
            case 1:
            {
                t_llllelem *subHead;
                t_hatom *keyHatom = &key->l_head->l_hatom;
                for ( ; lookHere ; lookHere = lookHere->l_next) {
                    if (t_llll *subll = hatom_getllll(&lookHere->l_hatom); subll && subll->l_size >= 2) {
                        subHead = subll->l_head;
                        if (hatom_eq(&subHead->l_hatom, keyHatom)) {
                            current = subll;
                            break;
                        }
                    }
                }
                if (!lookHere)
                    current = nullptr;
                else
                    lookHere = subHead->l_next;
                break;
            }
        }
        llll_free(key);
        ;
    }

    
    static t_bool consumeNthAddressLevel(t_llllelem* &lookHere, t_llll* &current, long& address_step, t_bool previousWasKey) {
        t_bool created = false;
        if (address_step > 0) {
            for ( ; lookHere && address_step > 1; address_step--) {
                lookHere = lookHere->l_next;
            }
            if (!lookHere) {
                for ( ; address_step > 0; address_step--) {
                    lookHere = llll_appendllll(current, llll_get());
                }
                created = true;
            }
        } else if (address_step < 0) {
            t_llllelem *keyElem = previousWasKey ? current->l_head : nullptr;
            for (lookHere = current->l_tail ; lookHere != keyElem && address_step < -1; address_step++) {
                lookHere = lookHere->l_prev;
            }
            if (lookHere == keyElem) {
                for ( ; address_step < 0; address_step++) {
                    lookHere = keyElem ?
                        llll_insertllll_after(llll_get(), keyElem):
                        llll_appendllll(current, llll_get());
                }
                created = true;
            }
        }
        return created;
    }

    
public:
    AstRichAccessNode(firstType *varNode,
              astNode *valueNode,
              lvalueStepList *lvalueStepList,
                  t_codableobj *owner)  : BASE(varNode, valueNode, owner)
    {
        if (lvalueStepList) {
            nLvSteps = lvalueStepList->getCount();
            lvalueStepList->copyIntoNullTerminatedArray(&lvStep);
        } else
            nLvSteps = 0;
    }
    
    
    t_llll *eval(t_execEnv const &context) {
        
        t_llll *orig = BASE::lNode->eval(context);
        t_llll *base = llll_clone(orig);
        llll_free(orig);
        
        t_llll *origV;
        t_bool previousWasKey = false;
        if constexpr (TYPE == E_RA_STANDARD) {
            origV = BASE::rNode->eval(context);
        } else {
            origV = nullptr;
        }
        
        t_llll *current = base;
        t_llllelem *lookHere = current->l_head;
        int i;
        for (i = 0; current && i < nLvSteps - 1; i++) {
            switch(lvStep[i]->type) {
                    
                case lvalueStep::E_LV_KEY:
                    nonLastKey(lvStep + i, lookHere, current, context);
                    previousWasKey = true;
                    break;
                    
                case lvalueStep::E_LV_NTH:
                    nonLastNth(lvStep + i, i, lookHere, current, previousWasKey, context);
                    previousWasKey = false;
                    break;
            }
        }
        
        // last round with assignment
        if (current && lookHere) {
            switch(lvStep[i]->type) {
                case lvalueStep::E_LV_KEY:
                    lastKey(lvStep + i, lookHere, current, origV, context);
                    break;
                    
                case lvalueStep::E_LV_NTH: {
                    lastNth(lvStep + i, i, lookHere, current, origV, previousWasKey, context);
                    break;
                }
            }
        } else {
            for ( ; i < nLvSteps; i++) {
                llll_free(lvStep[i]->value->eval(context));
            }
        }
        
        llll_free(origV);
        if constexpr(std::is_same<BASE, astAssign>::value)
            BASE::lNode->assign(base, context);
        return base;
    }
    

    ~AstRichAccessNode() {
        for (int i = 0; i < nLvSteps; i++)
            delete lvStep[i];
        delete lvStep;
    }
};


template<richAssignTypes TYPE = E_RA_STANDARD>
using astRichAssignment = AstRichAccessNode<astAssign, TYPE>;

template<richAssignTypes TYPE = E_RA_STANDARD>
using astRichEdit = AstRichAccessNode<astNonAssign, TYPE>;

template <typename BASE>
class astRichAccessNthOp : public BASE
{
public:
    astRichAccessNthOp(typename BASE::firstType *lNode,
                          astNode *rNode,
                          lvalueStepList *lvalueStepList,
                          t_codableobj *owner)  : BASE(lNode, rNode, lvalueStepList, owner) { }
    
    ~astRichAccessNthOp() { };
private:
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* address, t_bool created, t_execEnv const &context) {
        if (llllobj_check_llll_address((t_object *) context.obj, address, true, true) != MAX_ERR_NONE)
            return;
        
        t_llll *v = llll_get();
        llll_appendhatom_clone(v, &lookHere->l_hatom);
        t_llll *replacement = llll_nth(v, address, 0);
        llll_replacewith<false>(current, lookHere, replacement);
    }
    
    void lastKeyDo(t_llll *subll, t_llll *address, t_execEnv const &context) {
        if (llllobj_check_llll_address((t_object *) context.obj, address, true, true) != MAX_ERR_NONE)
            return;
        
        t_llll *v = llll_clone(subll);
        llll_destroyelem(v->l_head);
        t_llll *replacement = llll_nth(v, address, 0);
        llll_destroy_everything_but_head(subll);
        llll_chain(subll, replacement);
    }
};

template <typename BASE>
class astRichAccessConcatOp : public BASE
{
public:
    astRichAccessConcatOp(typename BASE::firstType *lNode,
                          astNode *rNode,
                          lvalueStepList *lvalueStepList,
                          t_codableobj *owner)  : BASE(lNode, rNode, lvalueStepList, owner) { }

    ~astRichAccessConcatOp() { }

private:
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        llll_insert_one(lookHere, llll_clone(origV), -1);
    }
    
    void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        llll_chain(subll, llll_clone(origV));
    }
};

template <typename BASE>
class astRichAccessRConcatOp : public BASE
{
public:
    astRichAccessRConcatOp(typename BASE::firstType *lNode,
                          astNode *rNode,
                          lvalueStepList *lvalueStepList,
                          t_codableobj *owner)  : BASE(lNode, rNode, lvalueStepList, owner) { }
    
    ~astRichAccessRConcatOp() { };
private:
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        llll_insert_one(lookHere, llll_clone(origV), 1);
    }
    
    void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        llll_insert_one(subll->l_head, llll_clone(origV), -1);
    }
};


#endif /* ast_hpp */
