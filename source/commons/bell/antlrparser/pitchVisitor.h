
// Generated from pitch.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "pitchParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by pitchParser.
 */
class  pitchVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by pitchParser.
   */
    virtual std::any visitPch(pitchParser::PchContext *context) = 0;

    virtual std::any visitDevInt(pitchParser::DevIntContext *context) = 0;

    virtual std::any visitDevRat(pitchParser::DevRatContext *context) = 0;

    virtual std::any visitUrat(pitchParser::UratContext *context) = 0;


};

