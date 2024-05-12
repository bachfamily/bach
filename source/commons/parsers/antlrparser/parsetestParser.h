
// Generated from parsetest.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  parsetestParser : public antlr4::Parser {
public:
  enum {
    NUMBER = 1, IF = 2, THEN = 3, ELSE = 4, FUNCTION = 5, VAR = 6, CLOSED = 7, 
    NTH = 8, TIMES = 9, NULLIFY = 10, ASSIGN = 11, EOL = 12, WHITESPACE = 13, 
    PLUS = 14, UPLUS = 15, MINUS = 16, UMINUS = 17, OPEN = 18, PARAMS = 19
  };

  enum {
    RuleProgram = 0, RuleSequence = 1, RuleItem = 2, RuleVar = 3, RuleLvalueSpecs = 4, 
    RuleLvalue = 5, RuleFakeLvalue = 6, RuleAssignment = 7, RuleReference = 8, 
    RuleTerm = 9, RuleExpression = 10, RuleList = 11, RuleFuncall = 12, 
    RuleConditional = 13, RuleNullify = 14
  };

  explicit parsetestParser(antlr4::TokenStream *input);

  parsetestParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~parsetestParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class SequenceContext;
  class ItemContext;
  class VarContext;
  class LvalueSpecsContext;
  class LvalueContext;
  class FakeLvalueContext;
  class AssignmentContext;
  class ReferenceContext;
  class TermContext;
  class ExpressionContext;
  class ListContext;
  class FuncallContext;
  class ConditionalContext;
  class NullifyContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SequenceContext *sequence();
    antlr4::tree::TerminalNode *EOF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  SequenceContext : public antlr4::ParserRuleContext {
  public:
    SequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ListContext *> list();
    ListContext* list(size_t i);
    std::vector<NullifyContext *> nullify();
    NullifyContext* nullify(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SequenceContext* sequence();

  class  ItemContext : public antlr4::ParserRuleContext {
  public:
    ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ItemContext() = default;
    void copyFrom(ItemContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ItemNumberContext : public ItemContext {
  public:
    ItemNumberContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemSequenceContext : public ItemContext {
  public:
    ItemSequenceContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *OPEN();
    SequenceContext *sequence();
    antlr4::tree::TerminalNode *CLOSED();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemFuncallContext : public ItemContext {
  public:
    ItemFuncallContext(ItemContext *ctx);

    FuncallContext *funcall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ItemContext* item();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarContext* var();

  class  LvalueSpecsContext : public antlr4::ParserRuleContext {
  public:
    LvalueSpecsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NTH();
    antlr4::tree::TerminalNode* NTH(size_t i);
    std::vector<ItemContext *> item();
    ItemContext* item(size_t i);
    std::vector<VarContext *> var();
    VarContext* var(size_t i);
    std::vector<ConditionalContext *> conditional();
    ConditionalContext* conditional(size_t i);
    std::vector<NullifyContext *> nullify();
    NullifyContext* nullify(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LvalueSpecsContext* lvalueSpecs();

  class  LvalueContext : public antlr4::ParserRuleContext {
  public:
    LvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    LvalueSpecsContext *lvalueSpecs();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LvalueContext* lvalue();

  class  FakeLvalueContext : public antlr4::ParserRuleContext {
  public:
    FakeLvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ItemContext *item();
    LvalueSpecsContext *lvalueSpecs();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FakeLvalueContext* fakeLvalue();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    ListContext *list();
    LvalueContext *lvalue();
    FakeLvalueContext *fakeLvalue();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ReferenceContext : public antlr4::ParserRuleContext {
  public:
    ReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LvalueContext *lvalue();
    FakeLvalueContext *fakeLvalue();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReferenceContext* reference();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ItemTermContext : public TermContext {
  public:
    ItemTermContext(TermContext *ctx);

    ItemContext *item();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReferenceTermContext : public TermContext {
  public:
    ReferenceTermContext(TermContext *ctx);

    ReferenceContext *reference();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TermContext* term();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    AssignmentContext *assignment();
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<NullifyContext *> nullify();
    NullifyContext* nullify(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ListContext() = default;
    void copyFrom(ListContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ListOnlyConditionalContext : public ListContext {
  public:
    ListOnlyConditionalContext(ListContext *ctx);

    ConditionalContext *conditional();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListOnlyAssignmentContext : public ListContext {
  public:
    ListOnlyAssignmentContext(ListContext *ctx);

    AssignmentContext *assignment();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListOtherContext : public ListContext {
  public:
    ListOtherContext(ListContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<LvalueContext *> lvalue();
    LvalueContext* lvalue(size_t i);
    AssignmentContext *assignment();
    ConditionalContext *conditional();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ListContext* list();

  class  FuncallContext : public antlr4::ParserRuleContext {
  public:
    FuncallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTION();
    antlr4::tree::TerminalNode *PARAMS();
    ListContext *list();
    antlr4::tree::TerminalNode *CLOSED();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncallContext* funcall();

  class  ConditionalContext : public antlr4::ParserRuleContext {
  public:
    ConditionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConditionalContext() = default;
    void copyFrom(ConditionalContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IfthenelseContext : public ConditionalContext {
  public:
    IfthenelseContext(ConditionalContext *ctx);

    antlr4::tree::TerminalNode *IF();
    std::vector<SequenceContext *> sequence();
    SequenceContext* sequence(size_t i);
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *ELSE();
    ListContext *list();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfthenContext : public ConditionalContext {
  public:
    IfthenContext(ConditionalContext *ctx);

    antlr4::tree::TerminalNode *IF();
    SequenceContext *sequence();
    antlr4::tree::TerminalNode *THEN();
    ListContext *list();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConditionalContext* conditional();

  class  NullifyContext : public antlr4::ParserRuleContext {
  public:
    NullifyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULLIFY();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NullifyContext* nullify();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

