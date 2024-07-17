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
    t_parseParams *params;
    
    everythingVisitor(t_parseParams *p) : params(p) { } ;
    
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
    
    antlrcpp::Any visitItemBtSymbol(bellParser::ItemBtSymbolContext *context) override {
        auto txt = context->BTSYMBOL()->getText();
        const char *cstr = txt.c_str() + 1;
        astNode* r = new astConst(gensym(cstr), params->owner);
        return r;
    }
    
    antlrcpp::Any visitItemQSymbol(bellParser::ItemQSymbolContext *context) override {
        auto txt = context->children[0]->getText();
        char cstr[MAX_SYM_LENGTH];
        const char *inPtr = txt.c_str() + 1;
        char *outPtr = cstr;
        int n = 0;
        while (*inPtr && n < MAX_SYM_LENGTH) {
            switch (*inPtr) {
                case 1:
                    *outPtr++ = ' ';
                    inPtr++;
                    break;
                case '\\':
                    inPtr++;
                default:
                    *outPtr++ = *inPtr++;
                    break;
            }
            n++;
        }
        *(outPtr - 1) = 0;
        astNode *r = new astConst(gensym(cstr), params->owner);
        return r;
    }
    
    antlrcpp::Any visitItemInlet(bellParser::ItemInletContext *context) override {
        auto txt = context->INLET()->getText();
        const char *cstr = txt.c_str();
        int i = atoi(cstr + (txt[0] == '\\' ? 3 : 2));
        if (params->dataInlets && params->fnDepth == 0 && i > *params->dataInlets)
            *params->dataInlets = i;
        astNode* r;
        switch(context->type->getType()) {
            case bellParser::INLET: r = new astInlet(i, params->owner); break;
            case bellParser::INTINLET: r = new astConvInlet<hatom_fn_int>(i, params->owner); break;
            case bellParser::FLOATINLET: r = new astConvInlet<hatom_fn_float>(i, params->owner); break;
            case bellParser::RATINLET: r = new astConvInlet<hatom_fn_rat>(i, params->owner); break;
            case bellParser::PITCHINLET: r = new astConvInlet<hatom_fn_pitch>(i, params->owner); break;
            default: r = nullptr;
        }
        return r;
    }
    
    antlrcpp::Any visitItemDirInlet(bellParser::ItemDirInletContext *context) override {
        auto txt = context->DIRINLET()->getText();
        const char *cstr = txt.c_str();
        long i = atol(cstr + (txt[0] == '\\' ? 4 : 3));
        if (params->directInlets && params->fnDepth == 0 && i > *params->directInlets)
            *params->directInlets = i;
        auto fnConst = new astConst((*(params->ofTable))["directin"], params->owner);
        auto numConst = new astConst(i, params->owner);
        auto v = new std::vector<astNode*>;
        v->push_back(numConst);
        astNode *r = new astFunctionCall(fnConst, v, nullptr, params->owner);
        return r;
    }
    
    antlrcpp::Any visitItemNull(bellParser::ItemNullContext *context) override {
        astNode *r = new astConst(llll_get(), params->owner);
        return r;
    }
    
    antlrcpp::Any visitItemNil(bellParser::ItemNilContext *context) override {
        t_llll *ll = llll_get();
        llll_appendllll(ll, llll_get());
        astNode *r = new astConst(ll, params->owner);
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
        astNode* a = safeAnyCast<astNode*>(visit(ctx->funcall()));
        return a;
    }
    
    antlrcpp::Any visitVarLocal(bellParser::VarLocalContext *ctx) override {
        std::string name = ctx->LOCALVAR()->getText();
        t_symbol *s = gensym(name.erase(0, name[0] == '\\' ? 2 : 1).c_str());
        astVar* v = new astLocalVar(s, params->owner);
        addVariableToScope(params, s);
        return static_cast<astNode*>(v);
    }
    
    antlrcpp::Any visitVarPatcher(bellParser::VarPatcherContext *ctx) override {
        std::string name = ctx->PATCHERVAR()->getText();
        t_symbol *s = gensym(name.erase(0, name[0] == '\\' ? 2 : 1).c_str());
        astVar* v = new astLocalVar(s, params->owner);
        addVariableToScope(params, s);
        return static_cast<astNode*>(v);
    }
    
    antlrcpp::Any visitVarGlobal(bellParser::VarGlobalContext *ctx) override {
        std::string name = ctx->GLOBALVAR()->getText();
        t_symbol *s = gensym(name.c_str());
        astGlobalVar *v = new astGlobalVar(params->gvt, s, params->owner);
        params->globalVariables->insert(v->getVar());
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
            astNode *n;
            switch(context->op->getType()) {
                case bellParser::ASSIGN: n = new astAssign(lv->getVar(), rv, params->owner); break;
                case bellParser::APOW: n = new astOperatorAPow(lv->getVar(), rv, params->owner); break;
                case bellParser::ATIMES: n = new astOperatorATimes(lv->getVar(), rv, params->owner); break;
                case bellParser::ADIVDIV: n = new astOperatorADivdiv(lv->getVar(), rv, params->owner); break;
                case bellParser::ADIV: n = new astOperatorADiv(lv->getVar(), rv, params->owner); break;
                case bellParser::AREM: n = new astOperatorARemainder(lv->getVar(), rv, params->owner); break;
                case bellParser::APLUS: n = new astOperatorAPlus(lv->getVar(), rv, params->owner); break;
                case bellParser::AMINUS: n = new astOperatorAMinus(lv->getVar(), rv, params->owner); break;
                case bellParser::ALOGAND: n = new astSCAAnd(lv->getVar(), rv, params->owner); break;
                case bellParser::ALOGANDEXT: n = new astSCAAndExt(lv->getVar(), rv, params->owner); break;
                case bellParser::ALOGXOR: n = new astLogAXor(lv->getVar(), rv, params->owner); break;
                case bellParser::ALOGOR: n = new astSCAOr(lv->getVar(), rv, params->owner); break;
                case bellParser::ALOGOREXT: n = new astSCAOrExt(lv->getVar(), rv, params->owner); break;
                case bellParser::ABITAND: n = new astOperatorABitAnd(lv->getVar(), rv, params->owner); break;
                case bellParser::ABITXOR: n = new astOperatorABitXor(lv->getVar(), rv, params->owner); break;
                case bellParser::ABITOR: n = new astOperatorABitOr(lv->getVar(), rv, params->owner); break;
                case bellParser::ALSHIFT: n = new astOperatorALShift(lv->getVar(), rv, params->owner); break;
                case bellParser::ARSHIFT: n = new astOperatorARShift(lv->getVar(), rv, params->owner); break;
                case bellParser::ANTH: n = new astNthAssignOp(lv->getVar(), rv, params->owner); break;
                case bellParser::ACONCAT: n = new astConcatAssignOp(lv->getVar(), rv, params->owner); break;
                default: n = nullptr; break;
            }
            return n;
        } else {
            astNode *n;
            switch(context->op->getType()) {
                case bellParser::ASSIGN: n = new astRichAssignment<E_RA_STANDARD>(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ATIMES: n = new astOperatorRATimes(lv->getVar(), rv, s, params->owner); break;
                case bellParser::APOW: n = new astOperatorRAPow(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ADIVDIV: n = new astOperatorRADivdiv(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ADIV: n = new astOperatorRADiv(lv->getVar(), rv, s, params->owner); break;
                case bellParser::AREM: n = new astOperatorRARemainder(lv->getVar(), rv, s, params->owner); break;
                case bellParser::APLUS: n = new astOperatorRAPlus(lv->getVar(), rv, s, params->owner); break;
                case bellParser::AMINUS: n = new astOperatorRAMinus(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ALOGAND: n = new astLogRASCAnd(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ALOGANDEXT: n = new astLogRASCAndExt(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ALOGXOR: n = new astLogRAXor(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ALOGOR: n = new astLogRASCAnd(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ALOGOREXT: n = new astLogRASCOrExt(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ABITAND: n = new astOperatorRABitAnd(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ABITXOR: n = new astOperatorRABitXor(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ABITOR: n = new astOperatorRABitOr(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ALSHIFT: n = new astOperatorRALShift(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ARSHIFT: n = new astOperatorRARShift(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ACONCAT: n = new astRAConcat(lv->getVar(), rv, s, params->owner); break;
                case bellParser::ARCONCAT: n = new astRARConcat(lv->getVar(), rv, s, params->owner); break;

            }
            return n;
        }
    }
    
    antlrcpp::Any visitFakeAssignment(bellParser::FakeAssignmentContext *context) override {
        fakeLvalue *lv = safeAnyCast<fakeLvalue*>(visit(context->fakeLvalue()));
        astNode *rv = safeAnyCast<astNode*>(visit(context->list()));
        auto s = lv->getSpecs();
        astNode* n;
        switch(context->op->getType()) {
            case bellParser::ASSIGN: n = new astRichEdit<E_RA_STANDARD>(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ATIMES: n = new astOperatorRETimes(lv->getNode(), rv, s, params->owner); break;
            case bellParser::APOW: n = new astOperatorREPow(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ADIVDIV: n = new astOperatorREDivdiv(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ADIV: n = new astOperatorREDiv(lv->getNode(), rv, s, params->owner); break;
            case bellParser::AREM: n = new astOperatorRERemainder(lv->getNode(), rv, s, params->owner); break;
            case bellParser::APLUS: n = new astOperatorREPlus(lv->getNode(), rv, s, params->owner); break;
            case bellParser::AMINUS: n = new astOperatorREMinus(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ALOGAND: n = new astLogRESCAnd(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ALOGANDEXT: n = new astLogRESCAndExt(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ALOGXOR: n = new astLogREXor(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ALOGOR: n = new astLogRESCAnd(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ALOGOREXT: n = new astLogRESCOrExt(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ABITAND: n = new astOperatorREBitAnd(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ABITXOR: n = new astOperatorREBitXor(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ABITOR: n = new astOperatorREBitOr(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ALSHIFT: n = new astOperatorRELShift(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ARSHIFT: n = new astOperatorRERShift(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ACONCAT: n = new astREConcat(lv->getNode(), rv, s, params->owner); break;
            case bellParser::ARCONCAT: n = new astRERConcat(lv->getNode(), rv, s, params->owner); break;
        }
        return n;
    }
    
    antlrcpp::Any visitOutletAssignment(bellParser::OutletAssignmentContext *ctx) override {
        auto l = safeAnyCast<astNode*>(visit(ctx->list()));
        if (!l)
            return nullptr;
        auto txt = ctx->OUTLET()->getText();
        const char *cstr = txt.c_str();
        long i = atol(cstr + (txt[0] == '\\' ? 3 : 2));
        if (params->dataOutlets && i > *(params->dataOutlets))
            *(params->dataOutlets) = i;
        auto fnConst = new astConst((*(params->bifs))["outlet"], params->owner);
        auto numConst = new astConst(i, params->owner);
        auto v = new std::vector<astNode*>;
        v->push_back(numConst);
        v->push_back(l);
        astNode *r = new astFunctionCall(fnConst, v, nullptr, params->owner);
        return r;
    }
    
    antlrcpp::Any visitDirOutletAssignment(bellParser::DirOutletAssignmentContext *ctx) override {
        auto l = safeAnyCast<astNode*>(visit(ctx->list()));
        if (!l)
            return nullptr;
        auto txt = ctx->DIROUTLET()->getText();
        const char *cstr = txt.c_str();
        long i = atol(cstr + (txt[0] == '\\' ? 4 : 3));
        if (params->directOutlets && i > *(params->directOutlets))
            *(params->directOutlets) = i;
        auto fnConst = new astConst((*(params->ofTable))["directout"], params->owner);
        auto numConst = new astConst(i, params->owner);
        auto v = new std::vector<astNode*>;
        v->push_back(numConst);
        v->push_back(l);
        astNode *r = new astFunctionCall(fnConst, v, nullptr, params->owner);
        return r;
    }

    antlrcpp::Any visitIfthen(bellParser::IfthenContext *ctx) override {
        auto i = safeAnyCast<astNode*>(visit(ctx->sequence()));
        auto t = safeAnyCast<astNode*>(visit(ctx->list()));
        astNode* n = new astIfThenElse(i, t, nullptr, params->owner);
        return n;
    }
    
    antlrcpp::Any visitIfthenelse(bellParser::IfthenelseContext *ctx) override {
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

