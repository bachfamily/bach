
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

    virtual std::any visitFunargVar(bellParser::FunargVarContext *context) = 0;

    virtual std::any visitFunargEllipsis(bellParser::FunargEllipsisContext *context) = 0;

    virtual std::any visitFunargList(bellParser::FunargListContext *context) = 0;

    virtual std::any visitLiftedargList(bellParser::LiftedargListContext *context) = 0;

    virtual std::any visitFundef(bellParser::FundefContext *context) = 0;

    virtual std::any visitSequence(bellParser::SequenceContext *context) = 0;

    virtual std::any visitNullified(bellParser::NullifiedContext *context) = 0;

    virtual std::any visitWhileloop(bellParser::WhileloopContext *context) = 0;

    virtual std::any visitForarg(bellParser::ForargContext *context) = 0;

    virtual std::any visitForargList(bellParser::ForargListContext *context) = 0;

    virtual std::any visitForloop(bellParser::ForloopContext *context) = 0;

    virtual std::any visitArgsByNameList(bellParser::ArgsByNameListContext *context) = 0;

    virtual std::any visitArgsByPositionList(bellParser::ArgsByPositionListContext *context) = 0;

    virtual std::any visitSimpleFuncall(bellParser::SimpleFuncallContext *context) = 0;

    virtual std::any visitDataFlowAndLvalueSpecsUItem(bellParser::DataFlowAndLvalueSpecsUItemContext *context) = 0;

    virtual std::any visitDataFlowAndLvalueSpecsItem(bellParser::DataFlowAndLvalueSpecsItemContext *context) = 0;

    virtual std::any visitFuncall(bellParser::FuncallContext *context) = 0;

    virtual std::any visitVarLocal(bellParser::VarLocalContext *context) = 0;

    virtual std::any visitVarPatcher(bellParser::VarPatcherContext *context) = 0;

    virtual std::any visitVarGlobal(bellParser::VarGlobalContext *context) = 0;

    virtual std::any visitLvalueSpecsUFinal(bellParser::LvalueSpecsUFinalContext *context) = 0;

    virtual std::any visitLvalueSpecsFinal(bellParser::LvalueSpecsFinalContext *context) = 0;

    virtual std::any visitLvalueSpecs(bellParser::LvalueSpecsContext *context) = 0;

    virtual std::any visitLvalue(bellParser::LvalueContext *context) = 0;

    virtual std::any visitFakeLvalue(bellParser::FakeLvalueContext *context) = 0;

    virtual std::any visitListEnd(bellParser::ListEndContext *context) = 0;

    virtual std::any visitExprFakeLvalue(bellParser::ExprFakeLvalueContext *context) = 0;

    virtual std::any visitExprUPlusMinus(bellParser::ExprUPlusMinusContext *context) = 0;

    virtual std::any visitExprSimple(bellParser::ExprSimpleContext *context) = 0;

    virtual std::any visitExprNot(bellParser::ExprNotContext *context) = 0;

    virtual std::any visitExprBinary(bellParser::ExprBinaryContext *context) = 0;

    virtual std::any visitExprTR(bellParser::ExprTRContext *context) = 0;

    virtual std::any visitExprLvalue(bellParser::ExprLvalueContext *context) = 0;

    virtual std::any visitItemUint(bellParser::ItemUintContext *context) = 0;

    virtual std::any visitItemUfloat(bellParser::ItemUfloatContext *context) = 0;

    virtual std::any visitItemETPitch(bellParser::ItemETPitchContext *context) = 0;

    virtual std::any visitItemJIPitch(bellParser::ItemJIPitchContext *context) = 0;

    virtual std::any visitItemPi(bellParser::ItemPiContext *context) = 0;

    virtual std::any visitItemBtSymbol(bellParser::ItemBtSymbolContext *context) = 0;

    virtual std::any visitItemQSymbol(bellParser::ItemQSymbolContext *context) = 0;

    virtual std::any visitItemEmptySymbol(bellParser::ItemEmptySymbolContext *context) = 0;

    virtual std::any visitItemBIF(bellParser::ItemBIFContext *context) = 0;

    virtual std::any visitItemOF(bellParser::ItemOFContext *context) = 0;

    virtual std::any visitItemInlet(bellParser::ItemInletContext *context) = 0;

    virtual std::any visitItemDirInlet(bellParser::ItemDirInletContext *context) = 0;

    virtual std::any visitItemArgcount(bellParser::ItemArgcountContext *context) = 0;

    virtual std::any visitItemNull(bellParser::ItemNullContext *context) = 0;

    virtual std::any visitItemNil(bellParser::ItemNilContext *context) = 0;

    virtual std::any visitItemSequence(bellParser::ItemSequenceContext *context) = 0;

    virtual std::any visitItemSublist(bellParser::ItemSublistContext *context) = 0;

    virtual std::any visitInitAssignment(bellParser::InitAssignmentContext *context) = 0;

    virtual std::any visitTrueAssignment(bellParser::TrueAssignmentContext *context) = 0;

    virtual std::any visitFakeAssignment(bellParser::FakeAssignmentContext *context) = 0;

    virtual std::any visitTrueAApply(bellParser::TrueAApplyContext *context) = 0;

    virtual std::any visitFakeAApply(bellParser::FakeAApplyContext *context) = 0;

    virtual std::any visitOutletAssignment(bellParser::OutletAssignmentContext *context) = 0;

    virtual std::any visitDirOutletAssignment(bellParser::DirOutletAssignmentContext *context) = 0;

    virtual std::any visitIfthen(bellParser::IfthenContext *context) = 0;

    virtual std::any visitIfthenelse(bellParser::IfthenelseContext *context) = 0;

    virtual std::any visitList(bellParser::ListContext *context) = 0;


};

