
// Generated from parsetest.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "parsetestVisitor.h"


/**
 * This class provides an empty implementation of parsetestVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  parsetestBaseVisitor : public parsetestVisitor {
public:

  virtual std::any visitProgram(parsetestParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSequence(parsetestParser::SequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemNumber(parsetestParser::ItemNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemSequence(parsetestParser::ItemSequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemFuncall(parsetestParser::ItemFuncallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(parsetestParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLvalueSpecs(parsetestParser::LvalueSpecsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLvalue(parsetestParser::LvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFakeLvalue(parsetestParser::FakeLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(parsetestParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReference(parsetestParser::ReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemTerm(parsetestParser::ItemTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReferenceTerm(parsetestParser::ReferenceTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(parsetestParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListOther(parsetestParser::ListOtherContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListOnlyAssignment(parsetestParser::ListOnlyAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListOnlyConditional(parsetestParser::ListOnlyConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncall(parsetestParser::FuncallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfthen(parsetestParser::IfthenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfthenelse(parsetestParser::IfthenelseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullify(parsetestParser::NullifyContext *ctx) override {
    return visitChildren(ctx);
  }


};

