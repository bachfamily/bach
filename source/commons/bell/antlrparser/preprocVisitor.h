
    #include "ext.h"
    #include "llll_commons.h"


// Generated from preproc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "preproc.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by preproc.
 */
class  preprocVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by preproc.
   */
    virtual std::any visitCode(preproc::CodeContext *context) = 0;

    virtual std::any visitTranscribe(preproc::TranscribeContext *context) = 0;

    virtual std::any visitInclude(preproc::IncludeContext *context) = 0;


};

