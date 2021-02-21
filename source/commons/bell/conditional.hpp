/*
 *  conditional.hpp
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

#ifndef conditional_hpp
#define conditional_hpp

#include "bell/astNode.hpp"

t_bool astLogXor_core(t_llll *first, astNode *second, t_execEnv const &context);
t_bool astSCOr_core(t_llll *first, astNode *second, t_execEnv const &context);
t_bool astSCAnd_core(t_llll *first, astNode *second, t_execEnv const &context);

t_bool astLogXor_hatom(const t_hatom *first, astNode *second, t_execEnv const &context);
t_bool astSCOr_hatom(const t_hatom *first, astNode *second, t_execEnv const &context);
t_bool astSCAnd_hatom(const t_hatom *first, astNode *second, t_execEnv const &context);

t_llll* astLogXor_run(t_llll *first, astNode *second, t_execEnv const &context);
t_llll* astSCOr_run(t_llll *first, astNode *second, t_execEnv const &context);
t_llll* astSCAnd_run(t_llll *first, astNode *second, t_execEnv const &context);
t_llll* astSCOrExt_run(t_llll *first, astNode *second, t_execEnv const &context);
t_llll* astSCAndExt_run(t_llll *first, astNode *second, t_execEnv const &context);



class forArg {
protected:
    t_symbol *index;
    t_symbol *address;
    astNode *node;
public:
    forArg(t_symbol *index, t_symbol *address, astNode *node) : index(index), address(address), node(node) { };
    t_symbol *getIndex() { return index; };
    t_symbol *getAddress() { return address; };
    astNode *getNode() { return node; };
};

// ! and ^^ aren't really conditionals, but feels like they belong here
class astLogNot : public astNode
{
protected:
    astNode *n1;
    
public:
    astLogNot(astNode *n1, t_codableobj *owner) : astNode(owner), n1(n1) { }
    
    ~astLogNot() { delete n1; }
    
    t_llll *eval(t_execEnv const &context);
};

template <t_llll* (*FN)(t_llll*, astNode*, t_execEnv const &)>
class astSCLogOp : public astNode
{
protected:
    astNode *n1;
    astNode *n2;
    
public:
    ~astSCLogOp() {
        delete n1;
        delete n2;
    }
    
    astSCLogOp(astNode *n1, astNode *n2, t_codableobj *owner) : astNode(owner), n1(n1), n2(n2) { }
    
    t_llll *eval(t_execEnv const &context)
    {
        return (FN)(n1->eval(context), n2, context);
    }

};

typedef astSCLogOp<astLogXor_run> astLogXor;
typedef astSCLogOp<astSCOr_run> astSCOr;
typedef astSCLogOp<astSCAnd_run> astSCAnd;
typedef astSCLogOp<astSCOrExt_run> astSCOrExt;
typedef astSCLogOp<astSCAndExt_run> astSCAndExt;



template <t_llll* (*FN)(t_llll*, astNode*, t_execEnv const &)>
class astSCLogAssignOp : public astNode
{
protected:
    astVar *varNode;
    astNode *valueNode;
    
public:
    ~astSCLogAssignOp() {
        delete varNode;
        delete valueNode;
    }
    
    astSCLogAssignOp(astVar *varNode, astNode *valueNode, t_codableobj *owner) : astNode(owner), varNode(varNode), valueNode(valueNode) { }
    
    t_llll *eval(t_execEnv const &context)
    {
        t_variable *v = varNode->getVar(context);
        t_llll *first = v->get();
        t_llll *res = (FN)(first, valueNode, context);
        v->set(res);
        return res;
    }
};

typedef astSCLogAssignOp<astLogXor_run> astLogAXor;
typedef astSCLogAssignOp<astSCOr_run> astSCAOr;
typedef astSCLogAssignOp<astSCAnd_run> astSCAAnd;
typedef astSCLogAssignOp<astSCOrExt_run> astSCAOrExt;
typedef astSCLogAssignOp<astSCAndExt_run> astSCAAndExt;


template <
        typename BASE,
        t_bool (*FN_llll)(t_llll*, astNode*, t_execEnv const &),
        t_bool (*FN_hatom)(const t_hatom*, astNode*, t_execEnv const &)
>
class astSCLogRichAccessOp : public BASE
{
public:
    astSCLogRichAccessOp(typename BASE::firstType *lNode,
                       astNode *rNode,
                       lvalueStepList *lvalueStepList,
                         t_codableobj *owner) : BASE(lNode, rNode, lvalueStepList, owner) { }
    
    ~astSCLogRichAccessOp() { }
    
private:
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        static constexpr t_hatom zero = {{0}, H_LONG};
        t_bool v;
        if (created)
            v = (FN_hatom)(&zero, BASE::rNode, context);
        else
            v = (FN_hatom)(&lookHere->l_hatom, BASE::rNode, context);
        hatom_change_to_long(&lookHere->l_hatom, v);
    }

    void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        t_llll *currValues = llll_clone(subll);
        llll_destroyelem(currValues->l_head);
        t_bool v = (FN_llll)(currValues, BASE::rNode, context);
        llll_destroy_everything_but_head(subll);
        llll_appendlong(subll, v);
    }
};

typedef astSCLogRichAccessOp<astRichAssignment<E_RA_SHORTCIRCUIT>, astLogXor_core, astLogXor_hatom> astLogRAXor;
typedef astSCLogRichAccessOp<astRichAssignment<E_RA_SHORTCIRCUIT>, astSCOr_core, astSCOr_hatom> astLogRASCOr;
typedef astSCLogRichAccessOp<astRichAssignment<E_RA_SHORTCIRCUIT>, astSCAnd_core, astSCAnd_hatom> astLogRASCAnd;


typedef astSCLogRichAccessOp<astRichEdit<E_RA_SHORTCIRCUIT>, astLogXor_core, astLogXor_hatom> astLogREXor;
typedef astSCLogRichAccessOp<astRichEdit<E_RA_SHORTCIRCUIT>, astSCOr_core, astSCOr_hatom> astLogRESCOr;
typedef astSCLogRichAccessOp<astRichEdit<E_RA_SHORTCIRCUIT>, astSCAnd_core, astSCAnd_hatom> astLogRESCAnd;

template<typename BASE>
class astSCRichAccessOrExt : public BASE
{
public:
    astSCRichAccessOrExt(typename BASE::firstType *lNode,
                         astNode *rNode,
                         lvalueStepList *lvalueStepList,
                         t_codableobj *owner)  : BASE(lNode, rNode, lvalueStepList, owner) { }

    ~astSCRichAccessOrExt() { };
private:
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        if (created || !hatom_istrue(&lookHere->l_hatom)) {
            t_llll *v = BASE::rNode->eval(context);
            llll_replacewith(current, lookHere, v);
            llll_release(v);
        }
    }
    
    void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        switch(subll->l_size) {
                
            case 1: { // there's only the key
                t_llll *valuell = BASE::rNode->eval(context);
                llll_chain(subll, llll_clone(valuell));
                llll_release(valuell);
                break;
            }
                
            case 2: {
                t_llllelem *head = subll->l_head;
                t_hatom *head_hatom = &head->l_hatom;
                t_bool v = hatom_istrue(head_hatom);
                if (!v) {
                    llll_destroy_everything_but_head(subll);
                    t_llll *valuell = BASE::rNode->eval(context);
                    llll_chain(subll, llll_clone(valuell));
                    llll_release(valuell);
                }
                break;
            }
                
            default:
                break;
        }
    }
};

template<typename BASE>
class astSCRichAccessAndExt : public BASE
{
public:
    astSCRichAccessAndExt(typename BASE::firstType *lNode,
                         astNode *rNode,
                         lvalueStepList *lvalueStepList,
                         t_codableobj *owner)  : BASE(lNode, rNode, lvalueStepList, owner) { }
    
    ~astSCRichAccessAndExt() { };
private:
    void lastNthDo(t_llll *current, t_llllelem* &lookHere, t_llll* origV, t_bool created, t_execEnv const &context) {
        if (hatom_istrue(&lookHere->l_hatom)) {
            t_llll *v = BASE::rNode->eval(context);
            llll_replacewith(current, lookHere, v);
            llll_release(v);
        }
    }
    
    void lastKeyDo(t_llll *subll, t_llll *origV, t_execEnv const &context) {
        switch(subll->l_size) {
                
            case 1:  // there's only the key
                break;
            
            case 2: {
                t_llllelem *head = subll->l_head;
                t_hatom *head_hatom = &head->l_hatom;
                t_bool v = hatom_istrue(head_hatom);
                if (v) {
                    llll_destroy_everything_but_head(subll);
                    t_llll *valuell = BASE::rNode->eval(context);
                    llll_chain(subll, llll_clone(valuell));
                    llll_release(valuell);
                }
                break;
            }
                
            default: {
                llll_destroy_everything_but_head(subll);
                t_llll *valuell = BASE::rNode->eval(context);
                llll_chain(subll, llll_clone(valuell));
                llll_release(valuell);
                break;
            }
        }
    }
};





//////////////////

class astIfThenElse : public astNode
{
protected:
    astNode *ifNode;
    astNode *thenNode;
    astNode *elseNode;
public:
    
    astIfThenElse(astNode *ifNode, astNode *thenNode, astNode *elseNode, t_codableobj *owner) : astNode(owner), ifNode(ifNode), thenNode(thenNode), elseNode(elseNode) { }
    
    ~astIfThenElse();
    
    t_llll *eval(t_execEnv const &context);
};



template<eLoopKinds KIND>
class astWhileLoop : public astNode
{
protected:
    astNode *condNode;
    astNode *bodyNode;
public:
    astWhileLoop(astNode *condNode, astNode *bodyNode, t_codableobj *owner) : astNode(owner), condNode(condNode), bodyNode(bodyNode) { }
    
    ~astWhileLoop() {
        delete condNode;
        delete bodyNode;
    }
    
    t_llll *eval(t_execEnv const &context) {
        
        t_llll *cond = condNode->eval(context);
        t_llll *v = llll_get();
        while (llll_istrue(cond) && !context.stopTimeReached()) {
            bell_release_llll(cond);
            if constexpr (KIND == E_LOOP_DO) {
                bell_release_llll(v);
                v = bodyNode->eval(context);
            } else {
                t_llll *append = bodyNode->eval(context);
                llll_chain(v, llll_clone(append));
                bell_release_llll(append);
            }
            cond = condNode->eval(context);
        }
        bell_release_llll(cond);
        
        return v;
    }
    
};




template<eLoopKinds KIND>
class astForLoop : public astNode
{
private:
    int count;
    t_symbol **dataPseudovariables; // NULL-terminated
    t_symbol **addressPseudovariables; // NULL-terminated
    t_symbol **localVariableNames; // NULL-terminated
    astNode **inClauses; // NULL-terminated
    countedList<symNodePair *> *attributes;
    astNode *whileClause;
    astNode *body;
    
    static t_bool llll_getAttributeValue(countedList<symNodePair *> *attribute, t_execEnv const &context, t_symbol *sym, t_atom_long *v) {
        if (attribute->getItem()->getSym() == sym) {
            t_llll *attr_ll = attribute->getItem()->getNode()->eval(context);
            *v = hatom_getlong(&attr_ll->l_head->l_hatom);
            bell_release_llll(attr_ll);
            return true;
        } else
        return false;
    }
    
    
    
    typedef struct {
        astForLoop *me;
        const t_execEnv *context;
        t_llll *rv;
        t_bool evaluate;
    } t_auxiliaryData;
    
    static long dataFunc(t_auxiliaryData *data, long idx, t_llll *ll, char isAddress) {
        astForLoop *me = data->me;
        t_symbol *pseudovarName = me->dataPseudovariables[idx];
        t_variable *pseudovar = data->context->scope.find(pseudovarName)->second;
        pseudovar->set(ll);
        return 0;
    }
    
    
    static long addressFunc(t_auxiliaryData *data, long idx, t_llll *ll, char isAddress) {
        astForLoop *me = data->me;
        t_symbol *pseudovarName = me->addressPseudovariables[idx];
        if (!pseudovarName)
        return 0;
        t_variable *pseudovar = data->context->scope.find(pseudovarName)->second;
        pseudovar->set(ll);
        return 0;
    }
    
    
    static long cmdFunc(t_auxiliaryData *data, long cmd) {
        const t_execEnv *context = data->context;
        if (context->stopTimeReached()) {
            data->evaluate = false;
            return 1;
        }
        if (data->evaluate) {
            astForLoop *me = data->me;
            if (me->whileClause) {
                t_llll *res = me->whileClause->eval(*context);
                t_bool r = llll_istrue(res);
                bell_release_llll(res);
                if (!r) {
                    data->evaluate = false;
                    return 1;
                }
            }
            if constexpr (KIND == E_LOOP_DO) {
                bell_release_llll(data->rv);
                data->rv = me->body->eval(*context);
            } else { // KIND == E_LOOP_COLLECT
                t_llll *append = me->body->eval(*context);
                llll_chain(data->rv, llll_clone(append));
                bell_release_llll(append);
            }
        }
        data->evaluate = true;
        return 0;
    }
    
public:
    astForLoop(countedList<forArg *> *lists,
                 countedList<t_symbol *> *localVariableNamesList,
                 astNode *whileClause,
                 countedList<symNodePair *> *attributes,
                 astNode *body,
               t_codableobj *owner) :
    astNode(owner), attributes(attributes), whileClause(whileClause), body(body) {
        count = lists->getCount();
        
        // put all the local variables in the array of local variable names (for faster access at loop call)
        if (localVariableNamesList) {
            localVariableNamesList->copyIntoNullTerminatedArray(&localVariableNames);
            delete localVariableNamesList->getHead();
        } else {
            localVariableNames = new t_symbol* [1] { };
        }
        
        dataPseudovariables = new t_symbol*[count+1];
        addressPseudovariables = new t_symbol*[count+1];
        inClauses = new astNode*[count+1];
        countedList<forArg *> *thisList;
        if (attributes)
            attributes = attributes->getHead();
        int i;
        for (thisList = lists->getHead(), i = 0;
             thisList;
             thisList = thisList->getNext(), i++) {
            dataPseudovariables[i] = thisList->getItem()->getIndex();
            addressPseudovariables[i] = thisList->getItem()->getAddress();
            inClauses[i] = thisList->getItem()->getNode();
        }
        dataPseudovariables[i] = nullptr;
        addressPseudovariables[i] = nullptr;
        inClauses[i] = nullptr;
        delete lists;
    }
    
    
    
    ~astForLoop() {
        astNode **thisClause;
        for (thisClause = inClauses; *thisClause; thisClause++) {
            delete *thisClause;
        }
        delete whileClause;
        delete body;
        
        delete dataPseudovariables;
        delete addressPseudovariables;
        delete localVariableNames;
        delete attributes;
    }
    
    
    
    t_llll *eval(t_execEnv const &context) {
        t_llll **lists = (t_llll**) bach_newptr(count * sizeof(t_llll*));
        
        // t_int32 maxdepth, long scalarmode, long recursionmode, long iterationmode, long spikemode, long unwrap
        t_atom_long maxdepth = 1;
        t_atom_long scalarmode = 1;
        t_atom_long recursionmode = 0;
        t_atom_long iterationmode = 0;
        t_atom_long spikemode = 0;
        t_atom_long unwrap = 0;
        
        countedList<symNodePair *> *thisAttributes;
        
        if (attributes) {
            for (thisAttributes = attributes->getHead(); thisAttributes; thisAttributes = thisAttributes->getNext()) {
                llll_getAttributeValue(thisAttributes, context, gensym("maxdepth"), &maxdepth) ||
                llll_getAttributeValue(thisAttributes, context, gensym("scalarmode"), &scalarmode) ||
                llll_getAttributeValue(thisAttributes, context, gensym("recursionmode"), &recursionmode) ||
                llll_getAttributeValue(thisAttributes, context, gensym("iterationmode"), &iterationmode) ||
                llll_getAttributeValue(thisAttributes, context, gensym("spikemode"), &spikemode) ||
                llll_getAttributeValue(thisAttributes, context, gensym("unwrap"), &unwrap);
            }
        }
        t_auxiliaryData funcData;
        funcData.me = this;
        funcData.context = &context;
        funcData.rv = llll_get();
        funcData.evaluate = false;
        
        for (long i = 0; i < count; i++) {
            lists[i] = inClauses[i]->eval(context);
        }
        
        llll_iter(count, lists, maxdepth, scalarmode, recursionmode, iterationmode, spikemode, unwrap, nullptr,
                  (iter_datafn) dataFunc, &funcData, (iter_datafn) addressFunc, &funcData, (iter_cmdfn) cmdFunc, &funcData, nullptr, nullptr, nullptr, nullptr);
        
        for (long i = 0; i < count; i++) {
            bell_release_llll(lists[i]);
        }
        bach_freeptr(lists);
        
        
        cmdFunc(&funcData, 0);
        
        return funcData.rv;
    }
};

#endif /* conditional_hpp */
