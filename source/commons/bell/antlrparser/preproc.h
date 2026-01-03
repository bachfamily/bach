
    #include "ext.h"
    #include "llll_commons.h"


// Generated from preproc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  preproc : public antlr4::Parser {
public:
  enum {
    DONTLOOKHERE = 1, WHITESPACE = 2, INCLUDE = 3, ANY = 4, CLOSE = 5, FILENAME = 6
  };

  enum {
    RuleCode = 0, RuleTranscribe = 1, RuleInclude = 2
  };

  explicit preproc(antlr4::TokenStream *input);

  preproc(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~preproc() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


      std::string output;
      bool error = false;
      bool included = false;


  class CodeContext;
  class TranscribeContext;
  class IncludeContext; 

  class  CodeContext : public antlr4::ParserRuleContext {
  public:
    CodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<TranscribeContext *> transcribe();
    TranscribeContext* transcribe(size_t i);
    std::vector<IncludeContext *> include();
    IncludeContext* include(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeContext* code();

  class  TranscribeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *dontlookhereToken = nullptr;
    antlr4::Token *anyToken = nullptr;
    antlr4::Token *whitespaceToken = nullptr;
    TranscribeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DONTLOOKHERE();
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *WHITESPACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TranscribeContext* transcribe();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *filenameToken = nullptr;
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *FILENAME();
    antlr4::tree::TerminalNode *CLOSE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

