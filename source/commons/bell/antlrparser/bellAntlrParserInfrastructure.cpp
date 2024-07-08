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

typedef struct {
    int v[1000];
    int n;
} intarray;

typedef struct {
    intarray* a;
    int pos;
    bool nullified;
} reference;
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

class programVisitor: public bellBaseVisitor {
public:
    int visits;
    t_parseParams *params;
    
    programVisitor(t_parseParams *p) : visits(0), params(p) {
    } ;
    

    
    std::string ws = "";
    
    void push() {
        ws += ' ';
    }
    
    void pop() {
        ws.pop_back();
    }
    /*
    void post(std::string s) {
        cout << ws << s << std::endl;
    }*/
    
    antlrcpp::Any visitProgram(bellParser::ProgramContext *ctx) override {
        push();
        post("program");
        auto r = any_cast<astNode*>(visit(ctx->sequence()));
        pop();
        return r;
    }
    
    antlrcpp::Any visitSequence(bellParser::SequenceContext *ctx) override {
        push();
        post("sequence");
        auto v = new std::vector<astNode*>;
        for (auto child: ctx->children) {
            v->push_back(std::any_cast<astNode*>(visit(child)));
        }
        pop();
        astNode* n = new astConcat(v, params->owner);
        return n;
    }
    
    antlrcpp::Any visitNullified(bellParser::NullifiedContext *ctx) override {
        push();
        post("sequence");
        astNode* n = new astNullify(std::any_cast<astNode*>(visit(ctx->list())), params->owner);
        pop();
        return n;
    }
    
    antlrcpp::Any visitFuncall(bellParser::FuncallContext *ctx) override {
        visits++;
        std::string name = ctx->FUNCTION()->getText();
        auto func = (*params->bifs)[name];
        auto fNode = new astConst(func, params->owner);
        auto abpl = new std::vector<astNode *>;
        auto arg = any_cast<astNode *>(visit(ctx->sequence()));
        abpl->push_back(arg);
        astNode* n = new astFunctionCall(fNode, abpl, nullptr, params->owner);
        return n;
    }
    
    antlrcpp::Any visitItemNumber(bellParser::ItemNumberContext *context) override {
        push();
        post("item: number");
        long v = stol(context->NUMBER()->getText());
        astNode* r = new astConst(v, params->owner);
        //auto a = intarray_new();
        //a->n = 1;
        //a->v[0] = v;
        pop();
        return r;
    }

    antlrcpp::Any visitItemSequence(bellParser::ItemSequenceContext *context) override {
        push();
        post("item: sequence");
        astNode* r = any_cast<astNode*>(visit(context->sequence()));
        pop();
        return r;
    }
    
    antlrcpp::Any visitItemSublist(bellParser::ItemSublistContext *context) override {
        push();
        post("item: sublist");
        astNode* s = any_cast<astNode*>(visit(context->sequence()));
        astNode* r = new astWrap(s, params->owner);
        pop();
        return r;
    }
    
    /*
    antlrcpp::Any visitItemUPlus(bellParser::ItemUPlusContext *ctx) override {
        push();
        post("item: uPlus");
        auto r = visit(ctx->item()).any_cast<intarray*>();
        pop();
        return r;
    }
    
    antlrcpp::Any visitItemUMinus(bellParser::ItemUMinusContext *ctx) override {
        visits++;
        intarray *a = visit(ctx->item()).any_cast<intarray*>();
        intarray_uminus(a);
        return a;
    }
    */
    
    antlrcpp::Any visitItemFuncall(bellParser::ItemFuncallContext *ctx) override {
        visits++;
        astNode* a = any_cast<astNode*>(visit(ctx->funcall()));
        return a;
    }
    
    antlrcpp::Any visitVar(bellParser::VarContext *ctx) override {
        visits++;
        std::string name = ctx->VAR()->getText();
        t_symbol *s = gensym(name.c_str());
        astVar* n = new astLocalVar(s, params->owner);
        addVariableToScope(params, s);
        return n;
    }
    
    antlrcpp::Any visitLvalueSpecs(bellParser::LvalueSpecsContext *ctx) override {
        auto specs = new lvalueSpecs;
        for (auto i = ctx->children.begin(); i != ctx->children.end(); ) {
            char op = (*i++)->getText()[0];
            astNode* n = any_cast<astNode*>(visit(*i++));
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
        auto v = any_cast<astVar*>(visit(context->var()));
        if (context->lvalueSpecs()) {
            auto s = any_cast<lvalueSpecs*>(visit(context->lvalueSpecs()));
            auto l = new lvalue(v, s);
            return l;
        } else {
            auto l = new lvalue(v, nullptr);
            return l;
        }
    }
    
    antlrcpp::Any visitFakeLvalue(bellParser::FakeLvalueContext *context) override {
        visits++;
        auto v = any_cast<astNode*>(visit(context->item()));
        auto s = any_cast<lvalueSpecs*>(visit(context->lvalueSpecs()));
        auto l = new fakeLvalue(v, s);
        return l;
    }

    antlrcpp::Any visitPow(antlr4::ParserRuleContext *context) {
        astNode *n1 = any_cast<astNode*>(visit(context->children[0]));
        astNode *n2 = any_cast<astNode*>(visit(context->children[2]));
        astNode *r = new astOperatorPow(n1, n2, params->owner);
        return r;
    };
    
    antlrcpp::Any visitPlus(antlr4::ParserRuleContext *context) {
        astNode *n1 = any_cast<astNode*>(visit(context->children[0]));
        astNode *n2 = any_cast<astNode*>(visit(context->children[2]));
        astNode *r = new astOperatorPlus(n1, n2, params->owner);
        return r;
    };
    
    antlrcpp::Any visitTimes(antlr4::ParserRuleContext *context) {
        astNode *n1 = any_cast<astNode*>(visit(context->children[0]));
        astNode *n2 = any_cast<astNode*>(visit(context->children[2]));
        astNode *r = new astOperatorTimes(n1, n2, params->owner);
        return r;
    };
    
    antlrcpp::Any visitExprPow(bellParser::ExprPowContext *context) override {
        return visitPow(context);
    }
    
    antlrcpp::Any visitExprUnary(bellParser::ExprUnaryContext *context) override {
        astNode *n = any_cast<astNode*>(visit(context->item()));
        if (context->UMINUS().size() % 2)
            n = new astOperatorUMinus(n, params->owner);
        return n;
    }

    antlrcpp::Any visitExprTimes(bellParser::ExprTimesContext *context) override {
        return visitTimes(context);
    }

    antlrcpp::Any visitExprPlus(bellParser::ExprPlusContext *context) override {
        return visitPlus(context);
    }
    
    template <typename T>
    antlrcpp::Any visitLvalue(T *context)  {
        lvalue *v = any_cast<lvalue*>(visit(context->lvalue()));
        astNode *n = v->getVar();
        lvalueSpecs *s = v->getSpecs();
        if (s)
            n = s->toReadNode(n, params->owner);
        return n;
    }
    
    template <typename T>
    antlrcpp::Any visitFakeLvalue(T *context) {
        fakeLvalue *v = any_cast<fakeLvalue*>(visit(context->fakeLvalue()));
        astNode *n = v->getNode();
        lvalueSpecs *s = v->getSpecs();
        n = s->toReadNode(n, params->owner);
        return n;
    }
    
    antlrcpp::Any visitExprLvalue(bellParser::ExprLvalueContext *context) override {
        return visitLvalue<bellParser::ExprLvalueContext>(context);
    }
    
    antlrcpp::Any visitExprFakeLvalue(bellParser::ExprFakeLvalueContext *context) override {
        return visitFakeLvalue<bellParser::ExprFakeLvalueContext>(context);
    }
    
    antlrcpp::Any visitEexprPow(bellParser::EexprPowContext *context) override {
        return visitPow(context);
    }
    
    antlrcpp::Any visitEexprUnary(bellParser::EexprUnaryContext *context) override {
        astNode *n = any_cast<astNode*>(visit(context->listEnd()));
        if (context->UMINUS().size() % 2)
            n = new astOperatorUMinus(n, params->owner);
        return n;
    }

    antlrcpp::Any visitEexprTimes(bellParser::EexprTimesContext *context) override {
        return visitTimes(context);
    }

    antlrcpp::Any visitEexprPlus(bellParser::EexprPlusContext *context) override {
        return visitPlus(context);
    }
    
    antlrcpp::Any visitEexprLvalue(bellParser::EexprLvalueContext *context) override {
        return visitLvalue<bellParser::EexprLvalueContext>(context);
    }
    
    antlrcpp::Any visitEexprFakeLvalue(bellParser::EexprFakeLvalueContext *context) override {
        return visitFakeLvalue<bellParser::EexprFakeLvalueContext>(context);
    }
        
    antlrcpp::Any visitTrueAssignment(bellParser::TrueAssignmentContext *context) override {
        lvalue *lv = any_cast<lvalue*>(visit(context->lvalue()));
        astNode *rv = any_cast<astNode*>(visit(context->list()));
        if (auto s = lv->getSpecs(); s == nullptr) {
            astNode* n = new astAssign(lv->getVar(), rv, params->owner);
            return n;
        } else {
            astNode* n = new astRichAssignment<E_RA_STANDARD>(lv->getVar(), rv, s, params->owner);
            return n;
        }
    }
    
    antlrcpp::Any visitFakeAssignment(bellParser::FakeAssignmentContext *context) override {
        fakeLvalue *lv = any_cast<fakeLvalue*>(visit(context->fakeLvalue()));
        astNode *rv = any_cast<astNode*>(visit(context->list()));
        astNode* n = new astRichEdit<E_RA_STANDARD>(lv->getNode(), rv, lv->getSpecs(), params->owner);
        return n;
    }
    
    antlrcpp::Any visitIfthen(bellParser::IfthenContext *ctx) override {
        visits++;
        auto i = any_cast<astNode*>(visit(ctx->sequence()));
        auto t = any_cast<astNode*>(visit(ctx->list()));
        astNode* n = new astIfThenElse(i, t, nullptr, params->owner);
        return n;
    }
    
    antlrcpp::Any visitIfthenelse(bellParser::IfthenelseContext *ctx) override {
        visits++;
        auto i = any_cast<astNode*>(visit(ctx->sequence(0)));
        auto t = any_cast<astNode*>(visit(ctx->sequence(1)));
        auto e = any_cast<astNode*>(visit(ctx->list()));
        astNode* n = new astIfThenElse(i, t, e, params->owner);
        return n;
    }

    antlrcpp::Any visitListEnd(bellParser::ListEndContext *ctx) override {
        return visit(ctx->children[0]);
    }
    
    antlrcpp::Any visitList(bellParser::ListContext *ctx) override {
        auto v = new std::vector<astNode*>;
        for (auto child : ctx->children) {
            astNode* n = any_cast<astNode*>(visit(child));
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
    CommonTokenStream tokens(&lexer);
    bellParser parser(&tokens);
        
    bellParser::ProgramContext* tree = parser.program();
        
    programVisitor visitor(&params);
    auto r = any_cast<astNode*>(visitor.visit(tree));
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

