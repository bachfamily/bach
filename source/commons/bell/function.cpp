/*
 *  function.cpp
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

#include "bell/function.hpp"
#include "bell/pvManager.hpp"

funArg* t_function::getArgNameAndDefault(long const n)  {
    if (n != 0 && n <= namedArgumentsCount && n >= namedArgumentsCountAfterEllipsis)
        return idx2argNameAndDefault[n];
    else
        return nullptr;
};

long t_function::getArgIdx(t_symbol *s) {
    auto found = argName2idx.find(s);
    if (found != argName2idx.end())
        return found->second;
    else
        return 0;
};

void t_function::setArgument(const char *name, astConst *node)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    ++namedArgumentsCount;
    idx2argNameAndDefault[namedArgumentsCount] = new funArg(sym, node);
    argName2idx[sym] = namedArgumentsCount;
}

void t_function::setArgument(const char *name, t_llll *def, t_codableobj *obj)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    ++namedArgumentsCount;
    idx2argNameAndDefault[namedArgumentsCount] = new funArg(sym, new astConst(def, obj));
    argName2idx[sym] = namedArgumentsCount;
}

void t_function::setArgument(const char *name, long def, t_codableobj *obj)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    ++namedArgumentsCount;
    idx2argNameAndDefault[namedArgumentsCount] = new funArg(sym, new astConst(def, obj));
    argName2idx[sym] = namedArgumentsCount;
}

void t_function::setArgument(const char *name, t_symbol *def, t_codableobj *obj)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    ++namedArgumentsCount;
    idx2argNameAndDefault[namedArgumentsCount] = new funArg(sym, new astConst(def, obj));
    argName2idx[sym] = namedArgumentsCount;
}

void t_function::setArgumentAfterEllipsis(const char *name, astConst *node)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    --namedArgumentsCountAfterEllipsis;
    idx2argNameAndDefault[namedArgumentsCountAfterEllipsis] = new funArg(sym, node);
    argName2idx[sym] = namedArgumentsCountAfterEllipsis;
}

void t_function::setArgumentAfterEllipsis(const char *name, t_llll *def, t_codableobj *obj)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    --namedArgumentsCountAfterEllipsis;
    idx2argNameAndDefault[namedArgumentsCountAfterEllipsis] = new funArg(sym, new astConst(def, obj));
    argName2idx[sym] = namedArgumentsCountAfterEllipsis;
}

void t_function::setArgumentAfterEllipsis(const char *name, long def, t_codableobj *obj)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    --namedArgumentsCountAfterEllipsis;
    idx2argNameAndDefault[namedArgumentsCountAfterEllipsis] = new funArg(sym, new astConst(def, obj));
    argName2idx[sym] = namedArgumentsCountAfterEllipsis;
}

void t_function::setArgumentAfterEllipsis(const char *name, t_symbol *def, t_codableobj *obj)
{
    t_symbol *sym = gensym(name);
    if (argName2idx.find(sym) != argName2idx.end()) {
        object_bug(nullptr, "duplicate function argument definition");
        return;
    }
    --namedArgumentsCountAfterEllipsis;
    idx2argNameAndDefault[namedArgumentsCountAfterEllipsis] = new funArg(sym, new astConst(def, obj));
    argName2idx[sym] = namedArgumentsCountAfterEllipsis;
}


t_userFunction::~t_userFunction()
{
    delete[] localVariables;
    delete ast;
}

t_userFunction::t_userFunction(countedList<funArg *> *argumentsList, countedList<t_localVar> *localVariablesList, astNode *ast, t_codableobj *culprit) : ast(ast)
{
    
    // put all the local variables in the array of local variable names (for faster access at function call)
    if (localVariablesList) {
        localVariablesList->copyIntoNullTerminatedArray(&localVariables);
        delete localVariablesList->getHead();
    } else {
        localVariables = new t_localVar [1] { (nullptr) };
    }
    
    variadic = false;
    //namedArgumentsCount = namedArgumentsCountAfterEllipsis = 0;
    // fill the double table of argument names and defaults
    if (argumentsList) {
        for (countedList<funArg *> *thisArg = argumentsList->getHead(); thisArg; thisArg = thisArg->getNext()) {
            funArg *item = thisArg->getItem();
            t_symbol *name = item->getSym();
            if (name == gensym("<...>")) {
                if (variadic) {
                    object_error((t_object *) culprit, "<...> can only appear once in a function definition");
                } else {
                    variadic = true;
                }
            } else if (argName2idx.find(name) == argName2idx.end()) {
                item->conform();
                if (!variadic) {
                    idx2argNameAndDefault[++namedArgumentsCount] = item;
                    argName2idx[name] = namedArgumentsCount;
                } else {
                    idx2argNameAndDefault[--namedArgumentsCountAfterEllipsis] = item;
                    argName2idx[name] = namedArgumentsCountAfterEllipsis;
                }
            } else {
                delete item;
                object_error((t_object *) culprit, "Duplicate argument name");

            }
        }
        //idx2argNameAndDefault[namedArgumentsCount + 1] = nullptr;
        //idx2argNameAndDefault[namedArgumentsCountAfterEllipsis - 1] = nullptr;
    }
    
    //idx2argNameAndDefault[0] = nullptr;

    delete argumentsList;
}

t_llll* t_userFunction::call(const t_execEnv &context) {
    t_llll *result = ast->eval(context);
    return llll_clone(result);
}

///////////////////////


t_maxFunction::t_maxFunction(std::string text) {
    std::string t;
    t_atom a[4], rv;
    int c;

    patcher = (t_object*) object_new_typed(CLASS_NOBOX, gensym("jpatcher"), 0, NULL);
    
    for (c = 0; c < text.length(); c++) {
        if (!isspace(text[c]))
            break;
    }
    t_symbol *defOut = _llllobj_sym_n;
    if (c < text.length()) {
        std::string ns = text.substr(c, 4);
        if (!ns.compare("max.")) {
            defOut = _llllobj_sym_m;
            text = text.substr(c + 4);
        }
    }
    
    t = "@maxclass newobj @text \"" + text + "\"";
    engine_box = newobject_sprintf(patcher, t.c_str());
    engine = jbox_get_object(engine_box);
    nInlets = object_attr_getlong(engine_box, gensym("numinlets"));
    nOutlets = object_attr_getlong(engine_box, gensym("numoutlets"));
    objText = t;
    
    t = "@maxclass newobj @text \"bach.bell.in " + std::to_string(nInlets) +
        " @out " +
        defOut->s_name +
        "\"";
    in_box = newobject_sprintf(patcher, t.c_str());
    in_obj = jbox_get_object(in_box);
    
    t = "@maxclass newobj @text \"bach.bell.out " + std::to_string(nOutlets) + "\"";
    out_box = newobject_sprintf(patcher, t.c_str());
    out_obj = jbox_get_object(out_box);
    
    for (int i = 0; i < nInlets; i++) {
        atom_setobj(a, in_box);       // source
        atom_setlong(a + 1, i);       // outlet number (0 is leftmost)
        atom_setobj(a + 2, engine_box);    // destination
        atom_setlong(a + 3, i);       // inlet number (0 is leftmost)
        object_method_typed(patcher, gensym("connect"), 4, a, &rv);
    }
    
    for (int i = 0; i < nOutlets; i++) {
        atom_setobj(a, engine_box);       // source
        atom_setlong(a + 1, i);       // outlet number (0 is leftmost)
        atom_setobj(a + 2, out_box);    // destination
        atom_setlong(a + 3, i);       // inlet number (0 is leftmost)
        object_method_typed(patcher, gensym("connect"), 4, a, &rv);
    }

    variadic = true;
    setArgumentAfterEllipsis("to");
    setArgumentAfterEllipsis("out", defOut);
    setArgumentAfterEllipsis("fetch");
}

t_maxFunction::~t_maxFunction() {
    object_free(patcher);
}

t_llll* t_maxFunction::call(t_execEnv const &context) {
    t_llll* order = context.scope.find(gensym("to"))->second->get();
    t_llll* outLl = context.scope.find(gensym("out"))->second->get();
    t_llll *fetchLl =
        context.scope.find(gensym("fetch"))->second->get();
    
    t_symbol *out = nullptr;
    if (outLl->l_size) {
        out = hatom_getsym(&outLl->l_head->l_hatom);
    }
    if (out) {
        object_attr_setsym(in_obj, _llllobj_sym_out, out);
    }
    if (order->l_size == 0) {
        for (int i = context.argc; i > 0; i--) {
            object_method(in_obj, gensym("pass"), i - 1, context.argv[i]);
        }
    } else {
        t_llllelem *el;
        int i;
        for (el = order->l_tail, i = order->l_size; el; el = el->l_prev, i--) {
            int n = hatom_getlong(&el->l_hatom);
            if (n > 0 && n <= nInlets) {
                if (t_llll *passed = context.argv[i]; passed) {
                    object_method(in_obj, gensym("pass"), n - 1, passed);
                }
            }
            else
                object_error((t_object *) context.obj, "Wrong order in Max object call");
        }
    }
    t_llll* res = (t_llll *) object_method(out_obj, gensym("fetch"), fetchLl, context.obj);
    return res;
}


///////////////////////


t_mainFunction::t_mainFunction(astNode *mainAst,
                               countedList<t_localVar> *localVariablesList,
                               std::unordered_set<t_globalVariable*> *globalVariables,
                               pvMap *name2astVars,
                               std::unordered_set<t_function*> *funcs,
                               t_codableobj *caller) :
inlet(0), name2astVars(name2astVars), globalVars(globalVariables), functions(funcs), owner(caller)
{
    ast = mainAst;
    if (!ast)
        return;
    if (localVariablesList) {
        localVariables = new t_localVar[localVariablesList->getCount() + 1];
        int i = 0;
        for (countedList<t_localVar> *thisLvnl = localVariablesList->getHead(); thisLvnl; thisLvnl = thisLvnl->getNext()) {
            localVariables[i] = thisLvnl->getItem();
            i++;
        }
        localVariables[i] = t_localVar();
        delete localVariablesList->getHead();
    } else {
        localVariables = new t_localVar[1] { };
    }
    
    variadic = true;
    
    namedArgumentsCount = 0;
    name = gensym("main");
    outlets = 0;
}

t_llll* t_mainFunction::call(t_execEnv const &context)
{
    
    if (!ast) {
        object_error((t_object *) context.obj, "no ast");
        return llll_get();
    }
    
    t_execEnv childContext(&context, this);
    
    childContext.setLocalVariables(localVariables, this);
    
    childContext.argc = context.argc;
    childContext.argv = context.argv;
    
    t_llll *result = ast->eval(childContext);
    return result;
    
}


t_mainFunction::~t_mainFunction() {
    clearOutletData();
    removePatcherVars();
    removeFromGlobalVarsClients();
    for (t_function* f: *functions) {
        f->decrease();
    }
    delete functions;
    delete name2astVars;
    delete globalVars;
}


void t_mainFunction::setOutletData(long outlet, t_llll *ll) {
    CLIP_ASSIGN(outlet, 0, 255);
    bell_release_llll(outletData[outlet]);
    outletData[outlet] = bell_retain_llll(ll);
};

void t_mainFunction::clearOutletData()
{
    for (int i = 0; i < outlets; i++) {
        bell_release_llll(outletData[i]);
        outletData[i] = nullptr;
    }
}

void t_mainFunction::resolvePatcherVars() {
    pvManager* pvm = bach->b_thePvManager;
    for (auto i : *name2astVars) {
        pvm->getVariable(i.first, reinterpret_cast<t_object*>(owner));
    }
}

void t_mainFunction::setPatcherVar(t_symbol *name, t_patcherVariable *v) {
    if (auto found = name2astVars->find(name); found != name2astVars->end()) {
        for (astPatcherVar* i : found->second) {
            i->setVar(v);
        }
    }
}

void t_mainFunction::makeClientToAllGVs(long priority) {
    for (auto var : *globalVars) {
        var->addClient((t_object *) owner, priority);
    }
}

void t_mainFunction::makeClientToAllPVs(long priority) {
    pvManager* pvm = bach->b_thePvManager;
    for (auto i: *name2astVars) {
        t_symbol *name = i.first;
        pvm->addClient(name, (t_object *) owner, priority);
    }
}

void t_mainFunction::removePatcherVars() {
    pvManager* pvm = bach->b_thePvManager;
    for (auto i : *name2astVars) {
        pvm->removeVariable(i.first, reinterpret_cast<t_object*>(owner));
    }
}

void t_mainFunction::removeFromGlobalVarsClients() {
    for (auto var : *globalVars) {
        var->removeClient((t_object *) owner);
    }
}

///////////////////////


astFunctionCall::astFunctionCall(astNode *functionNode, countedList<astNode *> *argsByPositionList, countedList<symNodePair *> *argsByNameList, t_codableobj *owner) : astNode(owner), functionNode(functionNode), OopStyleCall(false) {
    
    if (argsByPositionList) {
        argsByPositionCount = argsByPositionList->getCount();
        argsByPosition = new astNode* [argsByPositionCount + 1];
        argsByPosition += 1;
        countedList<astNode *> *thisABPL;
        int i;
        for (i = 0, thisABPL = argsByPositionList->getHead(); thisABPL; i++, thisABPL = thisABPL->getNext()) {
            argsByPosition[i] = thisABPL->getItem();
        }
    } else {
        argsByPositionCount = 0;
        argsByPosition = nullptr;
    }
    
    if (argsByNameList) {
        argsByNameCount = argsByNameList->getCount();
        argsByName = new astNode* [argsByNameCount];
        argsNames = new t_symbol* [argsByNameCount];
        countedList<symNodePair *> *thisABNL;
        int i;
        for (i = 0, thisABNL = argsByNameList->getHead(); thisABNL; i++, thisABNL = thisABNL->getNext()) {
            symNodePair *snp = thisABNL->getItem();
            argsByName[i] = snp->getNode();
            argsNames[i] = snp->getSym();
            delete snp;
        }
    } else {
        argsByNameCount = 0;
        argsByName = nullptr;
        argsNames = nullptr;
    }
}

astFunctionCall::~astFunctionCall() {
    delete functionNode;
    for (int i = 0; i < argsByPositionCount; i++)
        delete argsByPosition[i];
    if (argsByPosition)
        delete (OopStyleCall ? argsByPosition : argsByPosition - 1);
    for (int i = 0; i < argsByNameCount; i++)
        delete argsByName[i];
    delete argsByName;
    delete argsNames;
}

void astFunctionCall::addOopStyleArg(astNode *arg) {
    if (!OopStyleCall) {
        OopStyleCall = true;
        argsByPositionCount++;
        if (!argsByPosition) {
            argsByPosition = new astNode* [1];
        } else
            argsByPosition--;
        argsByPosition[0] = arg;
    }
}

t_llll *astFunctionCall::callFunction(t_function *fn, t_llll **argsByPositionLl, t_llll **argsByNameLl, t_execEnv const &context)
{
    t_execEnv childContext(&context, fn);
    
    const long offset = childContext.setFnArgsByPosition(fn, argsByPositionCount, argsByPositionLl);
    childContext.setFnArgsByName(fn, argsByNameCount, argsNames, argsByNameLl, offset);
    childContext.setFnDefaults(fn, offset, 0);
    childContext.setFnLocalVariables(fn);
    childContext.adjustArgc(fn, argsByPositionCount);
    
    t_llll *res = fn->call(childContext);
    //for (int argByPosIdx = 1; argByPosIdx <= childContext.argc; argByPosIdx++)
    //    bell_release_llll(childContext.argv[argByPosIdx]);
    return res;
}

t_llll *astFunctionCall::callFunction(t_function *fn, t_llll *argsByPositionLl, t_llll *argsByNameLl, t_execEnv const &context)
{
    t_execEnv childContext(&context, fn);
    
    const long offset = childContext.setFnArgsByPosition(fn, argsByPositionLl);
    childContext.setFnArgsByName(fn, argsByNameLl, offset);
    childContext.setFnDefaults(fn, offset, 0);
    childContext.setFnLocalVariables(fn);
    childContext.adjustArgc(fn, argsByPositionLl->l_size);
    
    t_llll *res = fn->call(childContext);
    //for (int argByPosIdx = 0; argByPosIdx < childContext.argc; argByPosIdx++)
    //    bell_release_llll(childContext.argv[argByPosIdx]);
    return res;
}

t_llll* astFunctionCall::eval(t_execEnv const &context)
{
    if (context.functionStackDepth > BELL_MAX_RECURSION_DEPTH) {
        object_error((t_object *) context.obj, "Stack overflow");
        return llll_get();
    }
    
    t_llll *fnll = functionNode->eval(context);
    t_llll **argsByPositionLl = (t_llll **) bach_newptr(argsByPositionCount * sizeof(t_llll *));
    t_llll **argsByNameLl = (t_llll **) bach_newptr(argsByNameCount * sizeof(t_llll *));
    t_llll *resultLl = llll_get();
    
    for (int i = 0; i < argsByPositionCount; i++) {
        argsByPositionLl[i] = argsByPosition[i]->eval(context);
    }
    
    for (int i = 0; i < argsByNameCount; i++) {
        argsByNameLl[i] = argsByName[i]->eval(context);
    }
    
    t_llllelem **elempile = (t_llllelem **) bach_newptr((fnll->l_depth - 1) * sizeof(t_llllelem *));
    t_llllelem **thisElempile = elempile;
    t_llllelem *fnelem = fnll->l_head;
    t_llll *newll = resultLl;
    
    while (1) {
        while (fnelem) {
            if (context.stopTimeReached())
                break;
            t_hatom *fnhatom = &fnelem->l_hatom;
            switch (hatom_gettype(fnhatom)) {
                case H_FUNCTION: {
                    t_function *fn = fnhatom->h_w.w_func;
                    t_llll *res = callFunction(fn, argsByPositionLl, argsByNameLl, context);
                    llll_chain(resultLl, res);
                    fnelem = fnelem->l_next;
                    break;
                }
                case H_LLLL: {
                    newll = llll_get();
                    llll_appendllll(resultLl, newll);
                    *thisElempile = fnelem;
                    thisElempile++;
                    fnelem = fnelem->l_hatom.h_w.w_llll->l_head;
                    resultLl = newll;
                    break;
                }
                default: {
                    llll_appendhatom(newll, fnhatom);
                    fnelem = fnelem->l_next;
                    break;
                }
            }
        }
        if (thisElempile == elempile)
            break;
        resultLl = resultLl->l_owner->l_parent;
        fnelem = (*--thisElempile)->l_next;
    }
    bell_release_llll(fnll);

    for (int i = 0; i < argsByPositionCount; i++) {
        llll_release(argsByPositionLl[i]);
    }
    bach_freeptr(argsByPositionLl);

    for (int i = 0; i < argsByNameCount; i++) {
        llll_release(argsByNameLl[i]);
    }

    bach_freeptr(argsByNameLl);
    bach_freeptr(elempile);
    return resultLl;
}

void astFunctionCall::setOopStyleArgValue(t_llll *ll) {
    astConst* k = dynamic_cast<astConst*>(argsByPosition[0]);
    k->set(ll);
}



