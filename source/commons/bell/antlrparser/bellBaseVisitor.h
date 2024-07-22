
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

  virtual std::any visitEverything(bellParser::EverythingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramEOF(bellParser::ProgramEOFContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramSequence(bellParser::ProgramSequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramSequenceNamedparam(bellParser::ProgramSequenceNamedparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramNamedparam(bellParser::ProgramNamedparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunargVar(bellParser::FunargVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunargEllipsis(bellParser::FunargEllipsisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunargList(bellParser::FunargListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiftedargList(bellParser::LiftedargListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFundef(bellParser::FundefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSequence(bellParser::SequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullified(bellParser::NullifiedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileloop(bellParser::WhileloopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForarg(bellParser::ForargContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForargList(bellParser::ForargListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForloop(bellParser::ForloopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgsByNameList(bellParser::ArgsByNameListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgsByPositionList(bellParser::ArgsByPositionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleFuncall(bellParser::SimpleFuncallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDataFlowAndLvalueSpecsUItem(bellParser::DataFlowAndLvalueSpecsUItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDataFlowAndLvalueSpecsItem(bellParser::DataFlowAndLvalueSpecsItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncall(bellParser::FuncallContext *ctx) override {
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

  virtual std::any visitLvalueSpecsUFinal(bellParser::LvalueSpecsUFinalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLvalueSpecsFinal(bellParser::LvalueSpecsFinalContext *ctx) override {
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

  virtual std::any visitListEnd(bellParser::ListEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprFakeLvalue(bellParser::ExprFakeLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprUPlusMinus(bellParser::ExprUPlusMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprSimple(bellParser::ExprSimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprNot(bellParser::ExprNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprBinary(bellParser::ExprBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprLvalue(bellParser::ExprLvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemUint(bellParser::ItemUintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemUfloat(bellParser::ItemUfloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemUpitch(bellParser::ItemUpitchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemBtSymbol(bellParser::ItemBtSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemQSymbol(bellParser::ItemQSymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemBIF(bellParser::ItemBIFContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemOF(bellParser::ItemOFContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemInlet(bellParser::ItemInletContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemDirInlet(bellParser::ItemDirInletContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemArgcount(bellParser::ItemArgcountContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemNull(bellParser::ItemNullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemNil(bellParser::ItemNilContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemSequence(bellParser::ItemSequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitItemSublist(bellParser::ItemSublistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitAssignment(bellParser::InitAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrueAssignment(bellParser::TrueAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFakeAssignment(bellParser::FakeAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOutletAssignment(bellParser::OutletAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDirOutletAssignment(bellParser::DirOutletAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfthen(bellParser::IfthenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfthenelse(bellParser::IfthenelseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList(bellParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }


};

