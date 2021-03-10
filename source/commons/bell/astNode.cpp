/*
 *  astNode.cpp
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

#include "bell/astNode.hpp"
#include "bell/function.hpp"
#include "bell/conditional.hpp"
#include "foundation/bach_maxutils.h"

t_execEnv::~t_execEnv()
{
    for (auto i = scope.begin(); i != scope.end(); i++) {
        t_variable *v = i->second;
        v->decrease();
    }
    if (parent && argv != parent->argv) {
        for (t_llll **thisAv = argv + 1; *thisAv; thisAv++)
            bell_release_llll(*thisAv);
        for (t_llll **thisAv = argv - 1; *thisAv; thisAv--)
            bell_release_llll(*thisAv);
    }
}

void t_execEnv::setVariableFromArgByPosition(t_function *fn, long i)
{
    funArg *thisANAD = fn->getArgNameAndDefault(i);
    t_symbol *name = thisANAD->getSym();
    t_variable *v = new t_variable(name);
    v->set(argv[i]);
    scope[name] = v;
}

long t_execEnv::setFnArgsByPosition(t_function *fn, long ac, t_llll **av)
{
    long nac = fn->getNamedArgumentsCount();
    for (long i = 1; i <= ac; i++) {
        argv[i] = bell_retain_llll(av[i - 1]);
        if (i <= nac) {
            setVariableFromArgByPosition(fn, i);
        }
    }
    return nac == 0 ? ac : 0;
    // if <...> is at the beginning of the argument list,
    // then the first named argument comes after all the arguments set by position,
    // otherwise it is the first argument in the list
}


long t_execEnv::setFnArgsByPosition(t_function *fn, t_llll *args)
{
    long nac = fn->getNamedArgumentsCount();
    long i;
    t_llllelem *argElem;
    for (argElem = args->l_head, i = 1; argElem; argElem = argElem->l_next, i++) {
        if (t_llll *subll = hatom_getllll(&argElem->l_hatom); subll)
            argv[i] = llll_clone(subll);
        else {
            llll_appendhatom(argv[i] = llll_get(), &argElem->l_hatom);
        }
        if (i <= nac) {
            setVariableFromArgByPosition(fn, i);
        }
    }
    return nac == 0 ? args->l_size : 0;
    // if <...> is at the beginning of the argument list,
    // then the first named argument comes after all the arguments set by position,
    // otherwise it is the first argument in the list
}

void t_execEnv::setFnArgsByName(t_function *fn, long ac, t_symbol **names, t_llll **values, long firstNamedArgumentOffset)
{
    for (long i = 0; i < ac; i++) {
        t_symbol *name = names[i];
        long idx = fn->getArgIdx(name);
        if (idx != 0) { // there are no args by name in right-variadic functions, so we don't have to deal with the negative case anyway
            t_llll **arg;
            if (idx > 0) { // comes before <...>
                arg = argv + firstNamedArgumentOffset + idx;
            } else { // comes after <...>
                arg = argv + idx;
            }
            if (*arg)
                bell_release_llll(*arg);
            
            *arg = bell_retain_llll(values[i]);
            createVariable(name, *arg);
        } else {
            createVariable(name, bell_retain_llll(values[i]));
        }
    }
}

t_variable* t_execEnv::createVariable(t_symbol *name)
{
    t_variable *v;
    auto found = scope.find(name);
    if (found != scope.end()) {
        v = found->second;
    } else {
        v = new t_variable(name);
        scope[name] = v;
    }
    return v;
}

t_variable* t_execEnv::createVariable(t_symbol *name, t_llll *ll)
{
    t_variable *v = createVariable(name);
    v->set(ll);
    return v;
}

void t_execEnv::setFnArgsByName(t_function *fn, t_llll *args, long firstNamedArgumentOffset)
{
    for (t_llllelem *argElem = args->l_head; argElem; argElem = argElem->l_next) {
        if (t_llll *argLl = hatom_getllll(&argElem->l_hatom); argLl && argLl->l_size) {
            if (t_symbol *name = hatom_getsym(&argLl->l_head->l_hatom); name) {
                long idx = fn->getArgIdx(name);
                if (idx != 0) { // there are no args by name in right-variadic functions, so we don't have to deal with the negative case anyway
                    t_llll **arg;
                    if (idx > 0) { // comes before <...>
                        arg = argv + firstNamedArgumentOffset + idx;
                    } else { // comes after <...>
                        arg = argv + idx;
                    }
                    if (*arg)
                        bell_release_llll(*arg);
                    *arg = llll_clone(argLl);
                    llll_destroyelem((*arg)->l_head);
                    t_variable *v;
                    auto found = scope.find(name);
                    if (found != scope.end()) {
                        v = found->second;
                    } else {
                        v = new t_variable(name);
                        scope[name] = v;
                    }
                    v->set(*arg);
                }
            } else {
                object_error((t_object *) parent->obj, "Bad named parameter in apply call");
            }
        } else {
            object_error((t_object *) parent->obj, "Bad named parameter list in apply call: discarding subsequent parameters");
            break;
        }
    }
}

void t_execEnv::setRootParams(long ac, t_symbol **names, t_llll **values)
{
    for (long i = 0; i < ac; i++) {
        t_variable *v;
        t_symbol *name = names[i];
        auto found = scope.find(name);
        if (found != scope.end()) {
            v = found->second;
        } else {
            v = new t_variable(name);
            scope[name] = v;
        }
        v->set(values[i]);
    }
}

// only called by built-in functions with lambdas
// sets the variables corresponding to the arguments passed by position by the caller
void t_execEnv::setFnArgNames(t_function *fn)
{
    long nac = fn->getNamedArgumentsCount();
    for (int i = 1; i <= nac; i++) {
        funArg *thisANAD = fn->getArgNameAndDefault(i);
        t_symbol *name = thisANAD->getSym();
        t_variable *v = new t_variable(name, bell_retain_llll(argv[i]));
        scope[name] = v;
    }
}

void t_execEnv::setFnDefaults(t_function *fn, long firstNamedArgumentOffset, long skip)
{
    long start = fn->getNamedArgumentsCountAfterEllipsis(); // <= 0
    long end = fn->getNamedArgumentsCount(); // >= 0
    long offset = start < 0 ? 0 : firstNamedArgumentOffset;
    for (long i = start; i <= end; i++) {
        if (i == 0) {
            i = skip;
            offset = firstNamedArgumentOffset;
            continue;
        }
        if (!argv[i + offset]) {
            funArg *thisANAD = fn->getArgNameAndDefault(i);
            t_llll *def = fn->retrieve(thisANAD->getSym());
            if (!def) {
                astNode *n = thisANAD->getNode();
                if (n) {
                    t_execEnv defContext(parent);
                    defContext.setLocalVariables(thisANAD->getVars());
                    def = bell_retain_llll(n->TCOEval(defContext));
                } else {
                    def = llll_get();
                }
            }
            t_symbol *name = thisANAD->getSym();
            auto found = scope.find(name);
            if (found != scope.end()) {
                t_variable *v = found->second;
                v->set(def);
            } else {
                t_variable *v = new t_variable(name, def);
                scope[name] = v;
            }
            argv[i + offset] = def;
        }
    }
}

void t_execEnv::resetFnNamedArgs(t_function *fn, long lambdaParams)
{
    long start = fn->getNamedArgumentsCountAfterEllipsis(); // <= 0
    long end = fn->getNamedArgumentsCount(); // >= 0
    long firstNamedArgumentOffset = end != 0 ? 0 : lambdaParams;
    long offset = start < 0 ? 0 : firstNamedArgumentOffset;
    for (long i = start; i <= end; i++) {
        if (i == 0) {
            offset = firstNamedArgumentOffset;
            continue;
        }
        funArg *thisANAD = fn->getArgNameAndDefault(i);
        t_symbol *name = thisANAD->getSym();
        t_llll *def = argv[i + offset];
        t_llll *old = scope[name]->get();
        if (old != def) { // which means it has changed
            scope[name]->set(def);
        }
        llll_release(old);
    }
}

void t_execEnv::setLocalVariables(t_localVar *vars, t_function *fn)
{
    if (!vars)
        return;
    for (t_localVar *thisVar = vars;
         thisVar->getName();
         thisVar++) {
        t_variable *v = nullptr;
        t_symbol *name = thisVar->getName();
        t_scope const *thisScope = &scope;
        if (thisScope->find(name) == thisScope->end()) {
            if (thisVar->isLifted()) {
                for (t_execEnv const *thisContext = parent;
                     thisContext && !v;
                     thisContext = thisContext->parent) {
                    thisScope = &thisContext->scope;
                    auto found = thisScope->find(name);
                    if (found != thisScope->end()) {
                        v = found->second;
                        v->increase();
                    }
                }
            }
            if (!v) {
                if (t_llll *def = fn->retrieve(name); def)
                    v = new t_variable(name, def);
                else
                    v = new t_variable(name);
                localVariables.insert(v);
            }
            scope[name] = v;
        }
    }
}

void t_execEnv::setFnLocalVariables(t_function *fn)
{
    setLocalVariables(fn->getLocalVariables(), fn);
}

void t_execEnv::resetLocalVariables()
{
    for (t_variable *v : localVariables) {
        t_llll *def = owner->retrieve(v->getName());
        if (!def)
            def = llll_get();
        v->set(def);
    }
}
    
void t_execEnv::adjustArgc(t_function *fn, long abpc)
{
    if (!fn->isVariadic())
        argc = fn->getNamedArgumentsCount();
    else
        argc = abpc;
}


/////////

// Eval with tail call optimization

inline t_llll* astNode::TCOEval(const t_execEnv &context)
{
    t_llll *all = llll_get();
    astNode *n = this;
    do {
        t_llll* res = n->eval(context);
        t_llllelem *t = res->l_tail;
        if (t && hatom_gettype(&t->l_hatom) == H_OBJ) {
            n = reinterpret_cast<astNode *>(hatom_getobj(&t->l_hatom));
            llll_destroyelem(t);
            llll_chain(all, res);
            // if we're here, then it means that res has been constructed especially for us
            // so we can as well alter it and let llll_chain destroy it
        } else {
            t_llll *g = llll_clone(res);
            llll_release(res);
            llll_chain(all, g);
            break;
        }
    } while(1);
    return all;
}


/////////


astConst::astConst(const long l, t_codableobj *owner) : astNode(owner) {
    t_llll *ll = llll_get();
    llll_appendlong(ll, l);
    v = ll;
}

astConst::astConst(const t_rational r, t_codableobj *owner) : astNode(owner) {
    t_llll *ll = llll_get();
    llll_appendrat(ll, r);
    v = ll;
}

astConst::astConst(const double d, t_codableobj *owner) : astNode(owner) {
    t_llll *ll = llll_get();
    llll_appenddouble(ll, d);
    v = ll;
}

astConst::astConst(const t_pitch &p, t_codableobj *owner) : astNode(owner) {
    t_llll *ll = llll_get();
    llll_appendpitch(ll, p);
    v = ll;
}

astConst::astConst(t_symbol *s, t_codableobj *owner) : astNode(owner) {
    t_llll *ll = llll_get();
    llll_appendsym(ll, s);
    v = ll;
}

astConst::astConst(t_function *f, t_codableobj *owner) : astNode(owner) {
    t_llll *ll = llll_get();
    llll_appendfunc(ll, f);
    v = ll;
}

void astConst::set(t_llll *ll) {
    llll_release(v);
    v = ll;
}

/////////


astGlobalVar::astGlobalVar(t_globalVariableTable *gvt, t_symbol *name, t_codableobj *owner) : astVar(owner) {
    gvt->lock();
    sv = gvt->lookup(name);
    if (sv == nullptr) {
        sv = new t_globalVariable(name, llll_get());
        gvt->insert(sv);
    }
    gvt->unlock();
}


//////////

t_variable* astLocalVar::getVar(t_execEnv const &context) {
    t_variable *v = context.scope.find(name)->second;
    return v;
}

//////////

t_llll* astInlet::eval(t_execEnv const &context) {
    if (idx > 0 && idx <= context.argc)
        return bell_retain_llll(context.argv[idx]);
    else
        return llll_get();
}


//////////

t_llll* astWrap::eval(t_execEnv const &context) {
    t_llll *orig = n1->TCOEval(context);
    t_llll *wrapped = llll_clone(orig);
    bell_release_llll(orig);
    llll_wrap(&wrapped);
    return wrapped;
}

////////////

t_llll* astConcat::eval(t_execEnv const &context) {
    t_llll *v1 = n1->TCOEval(context);
    t_llll *x = llll_clone(v1);
    llll_appendobj(x, n2);
    bell_release_llll(v1);
    return x;
}

////////////

t_llll* astConcatAssignOp::eval(t_execEnv const &context) {
    t_variable *v = varNode->getVar(context);
    t_llll *v1 = v->get();
    t_llll *v2 = dataNode->TCOEval(context);
    t_llll *x = llll_clone(v1);
    t_llll *giver = llll_clone(v2);
    llll_chain(x, giver);
    bell_release_llll(v1);
    bell_release_llll(v2);
    v->set(x);
    return x;
}

////////////

t_llll* astRevConcatAssignOp::eval(t_execEnv const &context) {
    t_variable *v = varNode->getVar(context);
    t_llll *v1 = dataNode->TCOEval(context);
    t_llll *v2 = v->get();
    t_llll *x = llll_clone(v1);
    t_llll *giver = llll_clone(v2);
    llll_chain(x, giver);
    bell_release_llll(v1);
    bell_release_llll(v2);
    v->set(x);
    return x;
}

////////////

t_llll* astNthOp::eval(t_execEnv const &context) {
    t_llll *data = dataNode->TCOEval(context);
    t_llll *address = addressNode->TCOEval(context);
    if (llllobj_check_llll_address((t_object *) context.obj, address, true, true) != MAX_ERR_NONE) {
        bell_release_llll(data);
        bell_release_llll(address);
        return llll_get();
    }
    t_llll *res = llll_nth(data, address, 0);
    bell_release_llll(data);
    bell_release_llll(address);
    return res;
}

////////////

t_llll* astNthAssignOp::eval(t_execEnv const &context) {
    t_variable *v = varNode->getVar(context);
    t_llll *data = v->get();
    t_llll *address = addressNode->TCOEval(context);
    if (llllobj_check_llll_address((t_object *) context.obj, address, true, true) != MAX_ERR_NONE) {
        bell_release_llll(data);
        bell_release_llll(address);
        return llll_get();
    }
    t_llll *res = llll_nth(data, address, 0);
    bell_release_llll(data);
    bell_release_llll(address);
    v->set(res);
    return res;
}

////////////

t_llll* astPickOp::eval(t_execEnv const &context) {
    t_llll *data = dataNode->TCOEval(context);
    t_llll *address = addressNode->TCOEval(context);
    if (llllobj_check_llll_address((t_object *) context.obj, address, false, false) != MAX_ERR_NONE) {
        bell_release_llll(data);
        bell_release_llll(address);
        return llll_get();
    }
    t_llllelem *res_elem = llll_nth_one(data, address);
    t_llll *res;
    if (res_elem) {
        t_hatom *res_hatom = &res_elem->l_hatom;
        t_llll *subll = hatom_getllll(res_hatom);
        if (subll) {
            res = llll_clone(subll);
        } else {
            res = llll_get();
            llll_appendhatom(res, res_hatom);
        }
    } else {
        res = llll_get();
    }
    bell_release_llll(data);
    bell_release_llll(address);
    return res;
}

////////////

t_llll* astRangeOp::eval(t_execEnv const &context) {
    const static t_hatom nothing = {{0}, H_NOTHING};
    const static t_hatom one = {{1}, H_LONG};

    //nothing.h_type = A_NOTHING;
    t_llll *startll = startNode->TCOEval(context);
    t_llll *endll = endNode->TCOEval(context);
    t_hatom start = startll->l_size ? startll->l_head->l_hatom : nothing;
    t_hatom end = endll->l_size ? endll->l_head->l_hatom : nothing;
    t_llll *res = llll_arithmser(start, end, one, 0);
    bell_release_llll(startll);
    bell_release_llll(endll);
    return res;
}


////////////

t_llll* astRepeatOp::eval(t_execEnv const &context) {
    t_llll *datall = dataNode->TCOEval(context);
    t_llll *repeatll = repeatNode->TCOEval(context);
    t_llll *res = llll_clone(datall);
    if (repeatll->l_depth == 1) {
        t_llll *current = datall;
        t_llllelem *prevelem;
        for (t_llllelem *relem = repeatll->l_tail; relem; relem = prevelem) {
            long n = hatom_getlong(&relem->l_hatom);
            if (n <= 0) {
                llll_free(res);
                res = llll_get();
            } else {
                for (int i = 1; i < n; i++) {
                    llll_chain(res, llll_clone(current));
                }
            }
            prevelem = relem->l_prev;
            if (current != datall)
                llll_free(current);
            if (prevelem) {
                llll_wrap(&res);
                current = llll_clone(res);
            }
        }
    } else {
        object_error((t_object *) context.obj, "Repeat operator: bad llll");
        res = llll_get();
    }
    bell_release_llll(datall);
    bell_release_llll(repeatll);
    return res;
}

//////////

t_llll* astAssign::eval(t_execEnv const &context) {
    t_llll *v = rNode->TCOEval(context);
    lNode->assign(v, context);
    return v;
}




//////////






