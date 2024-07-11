
// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "bellVisitor.h"


/**
 * This class provides an empty implementation of bellVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  bellBaseVisitor : public bellVisitor {
public:

  virtual std::any visitProgram(bellParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSequence(bellParser::SequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullified(bellParser::NullifiedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncall(bellParser::FuncallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemUint(bellParser::ItemUintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemUfloat(bellParser::ItemUfloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemInlet(bellParser::ItemInletContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemSequence(bellParser::ItemSequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemSublist(bellParser::ItemSublistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemFuncall(bellParser::ItemFuncallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarLocal(bellParser::VarLocalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarPatcher(bellParser::VarPatcherContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarGlobal(bellParser::VarGlobalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLvalueSpecs(bellParser::LvalueSpecsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLvalue(bellParser::LvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFakeLvalue(bellParser::FakeLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprFakeLvalue(bellParser::ExprFakeLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPlusMinus(bellParser::ExprPlusMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprVar(bellParser::ExprVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPow(bellParser::ExprPowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprUnary(bellParser::ExprUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprTimesDiv(bellParser::ExprTimesDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprLvalue(bellParser::ExprLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEexprPow(bellParser::EexprPowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEexprUnary(bellParser::EexprUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEexprTimesDiv(bellParser::EexprTimesDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEexprPlusMinus(bellParser::EexprPlusMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEexprLvalue(bellParser::EexprLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEexprFakeLvalue(bellParser::EexprFakeLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrueAssignment(bellParser::TrueAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFakeAssignment(bellParser::FakeAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfthen(bellParser::IfthenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfthenelse(bellParser::IfthenelseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListEnd(bellParser::ListEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList(bellParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }


};

