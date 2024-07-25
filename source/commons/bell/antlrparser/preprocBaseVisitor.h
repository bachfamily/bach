
    #include "ext.h"
    #include "llll_commons.h"


// Generated from preproc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "preprocVisitor.h"


/**
 * This class provides an empty implementation of preprocVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  preprocBaseVisitor : public preprocVisitor {
public:

  virtual std::any visitCode(preproc::CodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTranscribe(preproc::TranscribeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInclude(preproc::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }


};

