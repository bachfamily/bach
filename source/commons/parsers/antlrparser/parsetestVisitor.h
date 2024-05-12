
// Generated from parsetest.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "parsetestParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by parsetestParser.
 */
class  parsetestVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by parsetestParser.
   */
    virtual std::any visitProgram(parsetestParser::ProgramContext *context) = 0;

    virtual std::any visitSequence(parsetestParser::SequenceContext *context) = 0;

    virtual std::any visitItemNumber(parsetestParser::ItemNumberContext *context) = 0;

    virtual std::any visitItemSequence(parsetestParser::ItemSequenceContext *context) = 0;

    virtual std::any visitItemFuncall(parsetestParser::ItemFuncallContext *context) = 0;

    virtual std::any visitVar(parsetestParser::VarContext *context) = 0;

    virtual std::any visitLvalueSpecs(parsetestParser::LvalueSpecsContext *context) = 0;

    virtual std::any visitLvalue(parsetestParser::LvalueContext *context) = 0;

    virtual std::any visitFakeLvalue(parsetestParser::FakeLvalueContext *context) = 0;

    virtual std::any visitAssignment(parsetestParser::AssignmentContext *context) = 0;

    virtual std::any visitReference(parsetestParser::ReferenceContext *context) = 0;

    virtual std::any visitItemTerm(parsetestParser::ItemTermContext *context) = 0;

    virtual std::any visitReferenceTerm(parsetestParser::ReferenceTermContext *context) = 0;

    virtual std::any visitExpression(parsetestParser::ExpressionContext *context) = 0;

    virtual std::any visitListOther(parsetestParser::ListOtherContext *context) = 0;

    virtual std::any visitListOnlyAssignment(parsetestParser::ListOnlyAssignmentContext *context) = 0;

    virtual std::any visitListOnlyConditional(parsetestParser::ListOnlyConditionalContext *context) = 0;

    virtual std::any visitFuncall(parsetestParser::FuncallContext *context) = 0;

    virtual std::any visitIfthen(parsetestParser::IfthenContext *context) = 0;

    virtual std::any visitIfthenelse(parsetestParser::IfthenelseContext *context) = 0;

    virtual std::any visitNullify(parsetestParser::NullifyContext *context) = 0;


};

