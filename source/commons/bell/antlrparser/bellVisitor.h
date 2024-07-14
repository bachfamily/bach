
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
    virtual std::any visitEverything(bellParser::EverythingContext *context) = 0;

    virtual std::any visitProgramEOF(bellParser::ProgramEOFContext *context) = 0;

    virtual std::any visitProgramSequence(bellParser::ProgramSequenceContext *context) = 0;

    virtual std::any visitProgramSequenceNamedparam(bellParser::ProgramSequenceNamedparamContext *context) = 0;

    virtual std::any visitProgramNamedparam(bellParser::ProgramNamedparamContext *context) = 0;

    virtual std::any visitSequence(bellParser::SequenceContext *context) = 0;

    virtual std::any visitNullified(bellParser::NullifiedContext *context) = 0;

    virtual std::any visitWhileloop(bellParser::WhileloopContext *context) = 0;

    virtual std::any visitFuncall(bellParser::FuncallContext *context) = 0;

    virtual std::any visitItemUint(bellParser::ItemUintContext *context) = 0;

    virtual std::any visitItemUfloat(bellParser::ItemUfloatContext *context) = 0;

    virtual std::any visitItemUpitch(bellParser::ItemUpitchContext *context) = 0;

    virtual std::any visitItemInlet(bellParser::ItemInletContext *context) = 0;

    virtual std::any visitItemSequence(bellParser::ItemSequenceContext *context) = 0;

    virtual std::any visitItemSublist(bellParser::ItemSublistContext *context) = 0;

    virtual std::any visitItemFuncall(bellParser::ItemFuncallContext *context) = 0;

    virtual std::any visitVarLocal(bellParser::VarLocalContext *context) = 0;

    virtual std::any visitVarPatcher(bellParser::VarPatcherContext *context) = 0;

    virtual std::any visitVarGlobal(bellParser::VarGlobalContext *context) = 0;

    virtual std::any visitLvalueSpecs(bellParser::LvalueSpecsContext *context) = 0;

    virtual std::any visitLvalue(bellParser::LvalueContext *context) = 0;

    virtual std::any visitFakeLvalue(bellParser::FakeLvalueContext *context) = 0;

    virtual std::any visitExprFakeLvalue(bellParser::ExprFakeLvalueContext *context) = 0;

    virtual std::any visitExprPlusMinus(bellParser::ExprPlusMinusContext *context) = 0;

    virtual std::any visitExprVar(bellParser::ExprVarContext *context) = 0;

    virtual std::any visitExprPow(bellParser::ExprPowContext *context) = 0;

    virtual std::any visitExprUnary(bellParser::ExprUnaryContext *context) = 0;

    virtual std::any visitExprTimesDiv(bellParser::ExprTimesDivContext *context) = 0;

    virtual std::any visitExprLvalue(bellParser::ExprLvalueContext *context) = 0;

    virtual std::any visitEexprPow(bellParser::EexprPowContext *context) = 0;

    virtual std::any visitEexprUnary(bellParser::EexprUnaryContext *context) = 0;

    virtual std::any visitEexprTimesDiv(bellParser::EexprTimesDivContext *context) = 0;

    virtual std::any visitEexprPlusMinus(bellParser::EexprPlusMinusContext *context) = 0;

    virtual std::any visitEexprLvalue(bellParser::EexprLvalueContext *context) = 0;

    virtual std::any visitEexprFakeLvalue(bellParser::EexprFakeLvalueContext *context) = 0;

    virtual std::any visitTrueAssignment(bellParser::TrueAssignmentContext *context) = 0;

    virtual std::any visitFakeAssignment(bellParser::FakeAssignmentContext *context) = 0;

    virtual std::any visitIfthen(bellParser::IfthenContext *context) = 0;

    virtual std::any visitIfthenelse(bellParser::IfthenelseContext *context) = 0;

    virtual std::any visitListEnd(bellParser::ListEndContext *context) = 0;

    virtual std::any visitList(bellParser::ListContext *context) = 0;


};

