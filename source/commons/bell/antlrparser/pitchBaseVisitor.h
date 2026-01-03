
// Generated from pitch.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "pitchVisitor.h"


/**
 * This class provides an empty implementation of pitchVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  pitchBaseVisitor : public pitchVisitor {
public:

  virtual std::any visitPch(pitchParser::PchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDevInt(pitchParser::DevIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDevRat(pitchParser::DevRatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUrat(pitchParser::UratContext *ctx) override {
    return visitChildren(ctx);
  }


};

