//
//  bellAntlrParserInfrastructure.cpp
//  lib_bach
//
//  Created by Andrea Agostini on 03/07/24.
//

#include "bellAntlrParserInfrastructure.hpp"

#include "antlr4-runtime.h"
#include "bellLexer.h"
#include "bellParser.h"
#include "bellBaseVisitor.h"
#include "ast.hpp"
#include "stringparser.h"

using namespace std;
using namespace antlr4;

/*
void addVariableToScope(t_parseParams *params, t_symbol *name)
{
    auto known = (*(params->localVariablesAuxMapStack))->find(name);
    if (known == (*(params->localVariablesAuxMapStack))->end()) { // yet unknown
        (**(params->localVariablesAuxMapStack))[name] = 1;
        
        if (params->liftedVariablesStack == params->liftedVariablesStackBase) {
            *(params->localVariablesStack) = new countedList<t_localVar> (t_localVar(name, true), *(params->localVariablesStack)); // if we're at the main function level, then everything is lifted (as it can be set from the outside)
        } else {
            t_bool lifted = (*(params->liftedVariablesStack))->find(name) != (*(params->liftedVariablesStack))->end();
            
            *(params->localVariablesStack) = new countedList<t_localVar> (t_localVar(name, lifted), *(params->localVariablesStack));


        }
    }
}
*/

template<typename T>
T safeAnyCast(const std::any a) {
    if (a.type() == typeid(T)) {
        return any_cast<T>(a);
    } else {
        return nullptr;
    }
}

class bellErrorListener: public BaseErrorListener {
public:

    bellErrorListener(): BaseErrorListener() { }
    virtual ~bellErrorListener() { }
    
    void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
                     const std::string &msg, std::exception_ptr e) {
        antlr4::Parser *p = dynamic_cast<antlr4::Parser*>(recognizer);
        auto v = p->getRuleInvocationStack();
        for (auto s : v) {
            post("%s\n", s.c_str());
        }
        post("at pos %ld:%ld %s:%s", line, charPositionInLine, offendingSymbol->getText().c_str(), msg.c_str());
    }
    
};

class everythingVisitor: public bellBaseVisitor {
    
private:

public:
    int visits;
    t_parseParams *params;
    
    everythingVisitor(t_parseParams *p) : visits(0), params(p) { } ;
    
    antlrcpp::Any visitEverything(bellParser::EverythingContext *ctx) override {
        auto r = safeAnyCast<astNode*>(visit(ctx->program()));
        return r;
    }
    
    antlrcpp::Any visitProgramEOF(bellParser::ProgramEOFContext *ctx) override {
        *params->codeac = -1;
        astNode* r = new astConst(llll_get(), params->owner);
        return r;
    }
    
    antlrcpp::Any visitProgramSequence(bellParser::ProgramSequenceContext *ctx) override {
        *params->codeac = -1;
        auto r = safeAnyCast<astNode*>(visit(ctx->sequence()));
        return r;
    }
    
    antlrcpp::Any visitProgramSequenceNamedparam (bellParser::ProgramSequenceNamedparamContext *ctx) override {
        auto r = safeAnyCast<astNode*>(visit(ctx->sequence()));
        --*params->codeac;
        return r;
    }
    
    antlrcpp::Any visitProgramNamedparam (bellParser::ProgramNamedparamContext *ctx) override {
        *params->codeac = 0;
        astNode* r = new astConst(llll_get(), params->owner);
        return r;
    }
    
    antlrcpp::Any visitSequence(bellParser::SequenceContext *ctx) override {
        auto v = new std::vector<astNode*>;
        for (auto child: ctx->children) {
            astNode* n = safeAnyCast<astNode*>(visit(child));
            if (n)
                v->push_back(n);
            else {
                delete v;
                return nullptr;
            }
        }
        astNode* n = new astConcat(v, params->owner);
        return n;
    }
    
    antlrcpp::Any visitNullified(bellParser::NullifiedContext *ctx) override {
        astNode* n = new astNullify(safeAnyCast<astNode*>(visit(ctx->list())), params->owner);
        return n;
    }
    
    antlrcpp::Any visitWhileloop(bellParser::WhileloopContext *ctx) override {
        astNode* s = safeAnyCast<astNode*>(visit(ctx->sequence()));
        if (!s)
            return nullptr;
        astNode* l = safeAnyCast<astNode*>(visit(ctx->list()));
        if (!l) {
            delete s;
            return nullptr;
        }
        astNode *r;
        switch(ctx->kind->getType()) {
            case bellParser::DO: r = new astWhileLoop<E_LOOP_DO>(s, l, params->owner); break;
            case bellParser::COLLECT: r = new astWhileLoop<E_LOOP_COLLECT>(s, l, params->owner); break;
            default: r = nullptr; break;
        }
        return r;
    }
    
    
    antlrcpp::Any visitFuncall(bellParser::FuncallContext *ctx) override {
        std::string name = ctx->FUNCTION()->getText();
        auto func = (*params->bifs)[name];
        auto fNode = new astConst(func, params->owner);
        auto abpl = new std::vector<astNode *>;
        auto arg = safeAnyCast<astNode *>(visit(ctx->sequence()));
        abpl->push_back(arg);
        astNode* n = new astFunctionCall(fNode, abpl, nullptr, params->owner);
        return n;
    }
    
    antlrcpp::Any visitItemUint(bellParser::ItemUintContext *context) override {
        long v = stol(context->UINT()->getText());
        astNode* r = new astConst(v, params->owner);
        return r;
    }

    antlrcpp::Any visitItemUfloat(bellParser::ItemUfloatContext *context) override {
        double v = stod(context->UFLOAT()->getText());
        astNode* r = new astConst(v, params->owner);
        return r;
    }
    
    antlrcpp::Any visitItemUpitch(bellParser::ItemUpitchContext *context) override {
        std::string ptxt = context->UPITCH()->getText();
        ANTLRInputStream input(ptxt);
        pitchLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        pitchParser parser(&tokens);
        pitchParser::PchContext* tree = parser.pch();
        pchListener visitor;
        t_pitch p = std::any_cast<t_pitch>(visitor.visit(tree));
        astNode *r = new astConst(p, params->owner);
        return r;
    }
    
    antlrcpp::Any visitItemInlet(bellParser::ItemInletContext *context) override {
        int i = stoi(context->INLET()->getText().erase(0,2));
        if (params->dataInlets && params->fnDepth == 0 && i > *params->dataInlets)
            *params->dataInlets = i;
        astNode* r = new astInlet(i, params->owner);
        return r;
    }
    
    antlrcpp::Any visitItemSequence(bellParser::ItemSequenceContext *context) override {
        astNode* r = safeAnyCast<astNode*>(visit(context->sequence()));
        return r;
    }
    
    antlrcpp::Any visitItemSublist(bellParser::ItemSublistContext *context) override {
        astNode* s = safeAnyCast<astNode*>(visit(context->sequence()));
        astNode* r = new astWrap(s, params->owner);
        return r;
    }

    antlrcpp::Any visitItemFuncall(bellParser::ItemFuncallContext *ctx) override {
        visits++;
        astNode* a = safeAnyCast<astNode*>(visit(ctx->funcall()));
        return a;
    }
    
    antlrcpp::Any visitVarLocal(bellParser::VarLocalContext *ctx) override {
        visits++;
        std::string name = ctx->LOCALVAR()->getText();
        t_symbol *s = gensym(name.erase(0, 1).c_str());
        astVar* v = new astLocalVar(s, params->owner);
        addVariableToScope(params, s);
        return static_cast<astNode*>(v);
    }
    
    antlrcpp::Any visitVarPatcher(bellParser::VarPatcherContext *ctx) override {
        visits++;
        std::string name = ctx->PATCHERVAR()->getText();
        t_symbol *s = gensym(name.erase(0, 1).c_str());
        astVar* v = new astLocalVar(s, params->owner);
        addVariableToScope(params, s);
        return static_cast<astNode*>(v);
    }
    
    antlrcpp::Any visitVarGlobal(bellParser::VarGlobalContext *ctx) override {
        visits++;
        std::string name = ctx->GLOBALVAR()->getText();
        t_symbol *s = gensym(name.c_str());
        astVar* v = new astLocalVar(s, params->owner);
        addVariableToScope(params, s);
        return static_cast<astNode*>(v);
    }
    
    antlrcpp::Any visitLvalueSpecs(bellParser::LvalueSpecsContext *ctx) override {
        auto specs = new lvalueSpecs;
        for (auto i = ctx->children.begin(); i != ctx->children.end(); ) {
            char op = (*i++)->getText()[0];
            astNode* n = safeAnyCast<astNode*>(visit(*i++));
            auto step = new lvalueStep(op == ':' ? lvalueStep::E_LV_NTH : lvalueStep::E_LV_KEY, n);
            specs->addStep(step);
        }
        return specs;
    }
    
    class lvalue final {
    private:
        astVar *var;
        lvalueSpecs *specs;
    public:
        lvalue(astVar *v, lvalueSpecs *s) : var(v), specs(s) { }
        ~lvalue() { }
        astVar *getVar() { return var; }
        lvalueSpecs *getSpecs() { return specs; }
    };
    
    class fakeLvalue final {
    private:
        astNode *node;
        lvalueSpecs *specs;
    public:
        fakeLvalue(astNode *n, lvalueSpecs *s) : node(n), specs(s) { }
        ~fakeLvalue() { }
        astNode* getNode() { return node; }
        lvalueSpecs* getSpecs() { return specs; }
    };
    
    antlrcpp::Any visitLvalue(bellParser::LvalueContext *context) override {
        visits++;
        astVar* v = dynamic_cast<astVar*>(safeAnyCast<astNode*>(visit(context->var())));
        if (context->lvalueSpecs()) {
            auto s = safeAnyCast<lvalueSpecs*>(visit(context->lvalueSpecs()));
            auto l = new lvalue(v, s);
            return l;
        } else {
            auto l = new lvalue(v, nullptr);
            return l;
        }
    }
    
    antlrcpp::Any visitFakeLvalue(bellParser::FakeLvalueContext *context) override {
        visits++;
        auto v = safeAnyCast<astNode*>(visit(context->item()));
        auto s = safeAnyCast<lvalueSpecs*>(visit(context->lvalueSpecs()));
        auto l = new fakeLvalue(v, s);
        return l;
    }
    
    antlrcpp::Any visitExprSimple(bellParser::ExprSimpleContext *context) override {
        return visit(context->children[0]);
    }
    
    antlrcpp::Any visitExprLvalue(bellParser::ExprLvalueContext *context) override {
        lvalue *v = safeAnyCast<lvalue*>(visit(context->lvalue()));
        astNode *n = v->getVar();
        lvalueSpecs *s = v->getSpecs();
        if (s)
            n = s->toReadNode(n, params->owner);
        return n;
    }
    
    antlrcpp::Any visitExprFakeLvalue(bellParser::ExprFakeLvalueContext *context) override {
        fakeLvalue *v = safeAnyCast<fakeLvalue*>(visit(context->fakeLvalue()));
        astNode *n = v->getNode();
        lvalueSpecs *s = v->getSpecs();
        n = s->toReadNode(n, params->owner);
        return n;
    }
    
    antlrcpp::Any visitExprBinary(bellParser::ExprBinaryContext *context) override {
        astNode *n1 = safeAnyCast<astNode*>(visit(context->children[0]));
        if (!n1)
            return nullptr;
        astNode *n2 = safeAnyCast<astNode*>(visit(context->children[2]));
        if (!n2) {
            delete n1;
            return nullptr;
        }
        astNode *r;
        switch(context->op->getType()) {
            case bellParser::PICK: r = new astPickOp(n1, n2, params->owner); break;
            case bellParser::POW: r = new astOperatorPow(n1, n2, params->owner); break;
            case bellParser::PLUS: r = new astOperatorPlus(n1, n2, params->owner); break;
            case bellParser::MINUS: r = new astOperatorMinus(n1, n2, params->owner); break;
            case bellParser::TIMES: r = new astOperatorTimes(n1, n2, params->owner); break;
            case bellParser::DIV: r = new astOperatorDiv(n1, n2, params->owner); break;
            case bellParser::DIVDIV: r = new astOperatorDivdiv(n1, n2, params->owner); break;
            case bellParser::LSHIFT: r = new astOperatorLShift(n1, n2, params->owner); break;
            case bellParser::RSHIFT: r = new astOperatorDiv(n1, n2, params->owner); break;
            case bellParser::RANGE: r = new astRangeOp(n1, n2, params->owner); break;
            case bellParser::REPEAT: r = new astRepeatOp(n1, n2, params->owner); break;
            case bellParser::EQUAL: r = new astComparatorEq(n1, n2, params->owner); break;
            case bellParser::NEQ: r = new astComparatorNeq(n1, n2, params->owner); break;
            case bellParser::LT: r = new astComparatorLt(n1, n2, params->owner); break;
            case bellParser::LEQ: r = new astComparatorLt(n1, n2, params->owner); break;
            case bellParser::GT: r = new astComparatorGt(n1, n2, params->owner); break;
            case bellParser::GEQ: r = new astComparatorGeq(n1, n2, params->owner); break;
            case bellParser::BITAND: r = new astOperatorBitAnd(n1, n2, params->owner); break;
            case bellParser::BITOR: r = new astOperatorBitOr(n1, n2, params->owner); break;
            case bellParser::BITXOR: r = new astOperatorBitXor(n1, n2, params->owner); break;
            case bellParser::LOGAND: r = new astSCAnd(n1, n2, params->owner); break;
            case bellParser::LOGOR: r = new astSCOr(n1, n2, params->owner); break;
            case bellParser::LOGXOR: r = new astLogXor(n1, n2, params->owner); break;
            case bellParser::LOGANDEXT: r = new astSCAndExt(n1, n2, params->owner); break;
            case bellParser::LOGOREXT: r = new astSCOrExt(n1, n2, params->owner); break;
            default: r = nullptr; break;
        }
        return r;
    }
    
    antlrcpp::Any visitExprUPlusMinus(bellParser::ExprUPlusMinusContext *context) override {
        astNode *n = safeAnyCast<astNode*>(visit(context->children.back()));
        if (n && context->UMINUS().size() % 2)
            n = new astOperatorUMinus(n, params->owner);
        return n;
    }

    antlrcpp::Any visitExprNot(bellParser::ExprNotContext *context) override {
        astNode *n = safeAnyCast<astNode*>(visit(context->children.back()));
        if (!n) {
            return nullptr;
        }
        astNode *r;
        switch(context->op->getType()) {
            case bellParser::LOGNOT: r = new astLogNot(n, params->owner); break;
            case bellParser::BITNOT: r = new astOperatorBitNot(n, params->owner); break;
        }
        return r;
    }
    
    antlrcpp::Any visitTrueAssignment(bellParser::TrueAssignmentContext *context) override {
        lvalue *lv = safeAnyCast<lvalue*>(visit(context->lvalue()));
        astNode *rv = safeAnyCast<astNode*>(visit(context->list()));
        if (auto s = lv->getSpecs(); s == nullptr) {
            astNode* n = new astAssign(lv->getVar(), rv, params->owner);
            return n;
        } else {
            astNode* n = new astRichAssignment<E_RA_STANDARD>(lv->getVar(), rv, s, params->owner);
            return n;
        }
    }
    
    antlrcpp::Any visitFakeAssignment(bellParser::FakeAssignmentContext *context) override {
        fakeLvalue *lv = safeAnyCast<fakeLvalue*>(visit(context->fakeLvalue()));
        astNode *rv = safeAnyCast<astNode*>(visit(context->list()));
        astNode* n = new astRichEdit<E_RA_STANDARD>(lv->getNode(), rv, lv->getSpecs(), params->owner);
        return n;
    }
    
    antlrcpp::Any visitIfthen(bellParser::IfthenContext *ctx) override {
        visits++;
        auto i = safeAnyCast<astNode*>(visit(ctx->sequence()));
        auto t = safeAnyCast<astNode*>(visit(ctx->list()));
        astNode* n = new astIfThenElse(i, t, nullptr, params->owner);
        return n;
    }
    
    antlrcpp::Any visitIfthenelse(bellParser::IfthenelseContext *ctx) override {
        visits++;
        auto i = safeAnyCast<astNode*>(visit(ctx->sequence(0)));
        auto t = safeAnyCast<astNode*>(visit(ctx->sequence(1)));
        auto e = safeAnyCast<astNode*>(visit(ctx->list()));
        astNode* n = new astIfThenElse(i, t, e, params->owner);
        return n;
    }

    antlrcpp::Any visitListEnd(bellParser::ListEndContext *ctx) override {
        return visit(ctx->children[0]);
    }
    
    antlrcpp::Any visitList(bellParser::ListContext *ctx) override {
        auto v = new std::vector<astNode*>;
        for (auto child : ctx->children) {
            astNode* n = safeAnyCast<astNode*>(visit(child));
            v->push_back(n);
        }
        astNode* r = new astConcat(v, params->owner);
        return r;
    }
    
};

t_mainFunction *codableobj_parse_buffer_antlr(t_codableobj *x, long *codeac, t_atom_long *dataInlets, t_atom_long *dataOutlets, t_atom_long *directInlets, t_atom_long *directOutlets) {
    std::string pgm;
    
    t_parseParams params;
    params.ast = NULL;
    params.fnDepth = 0;
    params.localVariablesStack = params.localVariablesStackBase;
    params.localVariablesAuxMapStack = params.localVariablesAuxMapStackBase;
    params.localVariablesAuxMapStack[0] = new std::unordered_map<t_symbol *, int>;
    params.liftedVariablesStack = params.liftedVariablesStackBase;
    params.argumentsStack = params.argumentsStackBase;
    params.gvt = bach->b_gvt;
    params.bifs = bach->b_bifTable;
    params.codeac = codeac;
    *params.codeac = 0;
    params.dataInlets = dataInlets;
    params.dataOutlets = dataOutlets;
    params.directInlets = directInlets;
    params.directOutlets = directOutlets;
    params.owner = x;
    params.ofTable = x->c_ofTable;
    params.name2patcherVars = new pvMap;
    params.globalVariables = new std::unordered_set<t_globalVariable*>;
    params.funcs = new std::unordered_set<t_function*>;
    
    ANTLRInputStream input(x->c_text);
    bellLexer lexer(&input);
    lexer.setCodeac(params.codeac);
    CommonTokenStream tokens(&lexer);
    bellParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(new bellErrorListener());
        
    bellParser::ProgramContext* tree = parser.program();
        
    everythingVisitor visitor(&params);
    auto r = safeAnyCast<astNode*>(visitor.visit(tree));
    printf(" - with %d visits\n", visitor.visits);
    
    if (r) {
        t_mainFunction *mainFunction = new t_mainFunction(
            r,
            params.localVariablesStackBase[0],
            params.globalVariables,
            params.name2patcherVars,
            params.funcs,
            x
        );
        codableobj_clear_included_filewatchers(x);
        //codableobj_add_included_filewatchers(x, &lexparams.files);
        return mainFunction;
    } else {
        object_error((t_object *) x, "Syntax errors present — couldn't parse code");
        delete params.name2patcherVars;
        delete params.globalVariables;
        for (t_function* f: *params.funcs)
            f->decrease();
        delete params.funcs;
        return nullptr;
    }
    
}

