
// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "bellParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by bellParser.
 */
class  bellVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by bellParser.
   */
    virtual std::any visitProgram(bellParser::ProgramContext *context) = 0;

    virtual std::any visitSequence(bellParser::SequenceContext *context) = 0;

    virtual std::any visitNullified(bellParser::NullifiedContext *context) = 0;

    virtual std::any visitFuncall(bellParser::FuncallContext *context) = 0;

    virtual std::any visitItemNumber(bellParser::ItemNumberContext *context) = 0;

    virtual std::any visitItemSequence(bellParser::ItemSequenceContext *context) = 0;

    virtual std::any visitItemSublist(bellParser::ItemSublistContext *context) = 0;

    virtual std::any visitItemFuncall(bellParser::ItemFuncallContext *context) = 0;

    virtual std::any visitVar(bellParser::VarContext *context) = 0;

    virtual std::any visitLvalueSpecs(bellParser::LvalueSpecsContext *context) = 0;

    virtual std::any visitLvalue(bellParser::LvalueContext *context) = 0;

    virtual std::any visitFakeLvalue(bellParser::FakeLvalueContext *context) = 0;

    virtual std::any visitExprFakeLvalue(bellParser::ExprFakeLvalueContext *context) = 0;

    virtual std::any visitExprTimes(bellParser::ExprTimesContext *context) = 0;

    virtual std::any visitExprPlus(bellParser::ExprPlusContext *context) = 0;

    virtual std::any visitExprPow(bellParser::ExprPowContext *context) = 0;

    virtual std::any visitExprUnary(bellParser::ExprUnaryContext *context) = 0;

    virtual std::any visitExprLvalue(bellParser::ExprLvalueContext *context) = 0;

    virtual std::any visitEexprPow(bellParser::EexprPowContext *context) = 0;

    virtual std::any visitEexprUnary(bellParser::EexprUnaryContext *context) = 0;

    virtual std::any visitEexprTimes(bellParser::EexprTimesContext *context) = 0;

    virtual std::any visitEexprPlus(bellParser::EexprPlusContext *context) = 0;

    virtual std::any visitEexprLvalue(bellParser::EexprLvalueContext *context) = 0;

    virtual std::any visitEexprFakeLvalue(bellParser::EexprFakeLvalueContext *context) = 0;

    virtual std::any visitTrueAssignment(bellParser::TrueAssignmentContext *context) = 0;

    virtual std::any visitFakeAssignment(bellParser::FakeAssignmentContext *context) = 0;

    virtual std::any visitIfthen(bellParser::IfthenContext *context) = 0;

    virtual std::any visitIfthenelse(bellParser::IfthenelseContext *context) = 0;

    virtual std::any visitListEnd(bellParser::ListEndContext *context) = 0;

    virtual std::any visitList(bellParser::ListContext *context) = 0;


};

