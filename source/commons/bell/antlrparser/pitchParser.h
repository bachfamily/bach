
// Generated from pitch.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  pitchParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, UINT = 3, NOTENAME = 4, ACCIDENTAL = 5, UPLUS = 6, 
    UMINUS = 7
  };

  enum {
    RulePch = 0, RuleDev = 1, RuleUrat = 2
  };

  explicit pitchParser(antlr4::TokenStream *input);

  pitchParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~pitchParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class PchContext;
  class DevContext;
  class UratContext; 

  class  PchContext : public antlr4::ParserRuleContext {
  public:
    PchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTENAME();
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *ACCIDENTAL();
    DevContext *dev();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PchContext* pch();

  class  DevContext : public antlr4::ParserRuleContext {
  public:
    DevContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DevContext() = default;
    void copyFrom(DevContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DevIntContext : public DevContext {
  public:
    DevIntContext(DevContext *ctx);

    antlr4::tree::TerminalNode *UINT();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DevRatContext : public DevContext {
  public:
    DevRatContext(DevContext *ctx);

    UratContext *urat();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DevContext* dev();

  class  UratContext : public antlr4::ParserRuleContext {
  public:
    UratContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> UINT();
    antlr4::tree::TerminalNode* UINT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UratContext* urat();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

