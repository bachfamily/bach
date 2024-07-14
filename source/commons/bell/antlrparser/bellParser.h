
// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellParser : public antlr4::Parser {
public:
  enum {
    UINT = 1, UFLOAT = 2, UPITCH = 3, IF = 4, THEN = 5, ELSE = 6, WHILE = 7, 
    FOR = 8, DO = 9, COLLECT = 10, FUNCTION = 11, INLET = 12, GLOBALVAR = 13, 
    PATCHERVAR = 14, LOCALVAR = 15, NAMEDPARAM = 16, PUSH = 17, POP = 18, 
    CLOSED = 19, NTH = 20, PICK = 21, KEY = 22, NULLIFY = 23, ASSIGN = 24, 
    WHITESPACE = 25, NEWATOM = 26, POW = 27, TIMES = 28, DIVDIV = 29, DIV = 30, 
    PLUS = 31, UPLUS = 32, MINUS = 33, UMINUS = 34, REM = 35, EQUAL = 36, 
    NEQ = 37, LOGNOT = 38, BITNOT = 39, LT = 40, GT = 41, LEQ = 42, GEQ = 43, 
    BITAND = 44, BITXOR = 45, BITOR = 46, LOGAND = 47, LOGANDEXT = 48, LOGXOR = 49, 
    LOGOR = 50, LOGOREXT = 51, LSHIFT = 52, RSHIFT = 53, RANGE = 54, REPEAT = 55, 
    OPEN = 56, PARAMS = 57, ANYTHING = 58
  };

  enum {
    RuleEverything = 0, RuleProgram = 1, RuleSequence = 2, RuleNullified = 3, 
    RuleWhileloop = 4, RuleFuncall = 5, RuleItem = 6, RuleVar = 7, RuleLvalueSpecs = 8, 
    RuleLvalue = 9, RuleFakeLvalue = 10, RuleEexpr = 11, RuleExpr = 12, 
    RuleAssignment = 13, RuleConditional = 14, RuleListEnd = 15, RuleList = 16
  };

  explicit bellParser(antlr4::TokenStream *input);

  bellParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~bellParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

   
      
      bool ending = false;



  class EverythingContext;
  class ProgramContext;
  class SequenceContext;
  class NullifiedContext;
  class WhileloopContext;
  class FuncallContext;
  class ItemContext;
  class VarContext;
  class LvalueSpecsContext;
  class LvalueContext;
  class FakeLvalueContext;
  class EexprContext;
  class ExprContext;
  class AssignmentContext;
  class ConditionalContext;
  class ListEndContext;
  class ListContext; 

  class  EverythingContext : public antlr4::ParserRuleContext {
  public:
    EverythingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EverythingContext* everything();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgramContext() = default;
    void copyFrom(ProgramContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ProgramSequenceContext : public ProgramContext {
  public:
    ProgramSequenceContext(ProgramContext *ctx);

    SequenceContext *sequence();
    antlr4::tree::TerminalNode *EOF();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ProgramNamedparamContext : public ProgramContext {
  public:
    ProgramNamedparamContext(ProgramContext *ctx);

    antlr4::tree::TerminalNode *NAMEDPARAM();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ProgramEOFContext : public ProgramContext {
  public:
    ProgramEOFContext(ProgramContext *ctx);

    antlr4::tree::TerminalNode *EOF();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ProgramSequenceNamedparamContext : public ProgramContext {
  public:
    ProgramSequenceNamedparamContext(ProgramContext *ctx);

    SequenceContext *sequence();
    antlr4::tree::TerminalNode *NAMEDPARAM();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgramContext* program();

  class  SequenceContext : public antlr4::ParserRuleContext {
  public:
    SequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListContext *list();
    std::vector<NullifiedContext *> nullified();
    NullifiedContext* nullified(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SequenceContext* sequence();

  class  NullifiedContext : public antlr4::ParserRuleContext {
  public:
    NullifiedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListContext *list();
    std::vector<antlr4::tree::TerminalNode *> NULLIFY();
    antlr4::tree::TerminalNode* NULLIFY(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NullifiedContext* nullified();

  class  WhileloopContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *kind = nullptr;
    WhileloopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    SequenceContext *sequence();
    ListContext *list();
    antlr4::tree::TerminalNode *DO();
    antlr4::tree::TerminalNode *COLLECT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileloopContext* whileloop();

  class  FuncallContext : public antlr4::ParserRuleContext {
  public:
    FuncallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTION();
    antlr4::tree::TerminalNode *PARAMS();
    SequenceContext *sequence();
    antlr4::tree::TerminalNode *CLOSED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncallContext* funcall();

  class  ItemContext : public antlr4::ParserRuleContext {
  public:
    ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ItemContext() = default;
    void copyFrom(ItemContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ItemUfloatContext : public ItemContext {
  public:
    ItemUfloatContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *UFLOAT();

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

  class  ItemUintContext : public ItemContext {
  public:
    ItemUintContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *UINT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemSublistContext : public ItemContext {
  public:
    ItemSublistContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *PUSH();
    SequenceContext *sequence();
    antlr4::tree::TerminalNode *POP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemInletContext : public ItemContext {
  public:
    ItemInletContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *INLET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemFuncallContext : public ItemContext {
  public:
    ItemFuncallContext(ItemContext *ctx);

    FuncallContext *funcall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemUpitchContext : public ItemContext {
  public:
    ItemUpitchContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *UPITCH();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ItemContext* item();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarContext() = default;
    void copyFrom(VarContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarLocalContext : public VarContext {
  public:
    VarLocalContext(VarContext *ctx);

    antlr4::tree::TerminalNode *LOCALVAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarPatcherContext : public VarContext {
  public:
    VarPatcherContext(VarContext *ctx);

    antlr4::tree::TerminalNode *PATCHERVAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarGlobalContext : public VarContext {
  public:
    VarGlobalContext(VarContext *ctx);

    antlr4::tree::TerminalNode *GLOBALVAR();

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
    ConditionalContext *conditional();


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

  class  EexprContext : public antlr4::ParserRuleContext {
  public:
    EexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EexprContext() = default;
    void copyFrom(EexprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EexprLvalueContext : public EexprContext {
  public:
    EexprLvalueContext(EexprContext *ctx);

    LvalueContext *lvalue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EexprSimpleContext : public EexprContext {
  public:
    EexprSimpleContext(EexprContext *ctx);

    ListEndContext *listEnd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EexprBinaryContext : public EexprContext {
  public:
    EexprBinaryContext(EexprContext *ctx);

    antlr4::Token *op = nullptr;
    ExprContext *expr();
    ListEndContext *listEnd();
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *DIVDIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *REPEAT();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *GEQ();
    antlr4::tree::TerminalNode *BITAND();
    antlr4::tree::TerminalNode *BITXOR();
    antlr4::tree::TerminalNode *BITOR();
    antlr4::tree::TerminalNode *LOGAND();
    antlr4::tree::TerminalNode *LOGANDEXT();
    antlr4::tree::TerminalNode *LOGXOR();
    antlr4::tree::TerminalNode *LOGOR();
    antlr4::tree::TerminalNode *LOGOREXT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EexprNotContext : public EexprContext {
  public:
    EexprNotContext(EexprContext *ctx);

    antlr4::Token *op = nullptr;
    EexprContext *eexpr();
    antlr4::tree::TerminalNode *LOGNOT();
    antlr4::tree::TerminalNode *BITNOT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EexprFakeLvalueContext : public EexprContext {
  public:
    EexprFakeLvalueContext(EexprContext *ctx);

    FakeLvalueContext *fakeLvalue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EexprUPlusMinusContext : public EexprContext {
  public:
    EexprUPlusMinusContext(EexprContext *ctx);

    EexprContext *eexpr();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EexprContext* eexpr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprFakeLvalueContext : public ExprContext {
  public:
    ExprFakeLvalueContext(ExprContext *ctx);

    FakeLvalueContext *fakeLvalue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprUPlusMinusContext : public ExprContext {
  public:
    ExprUPlusMinusContext(ExprContext *ctx);

    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprSimpleContext : public ExprContext {
  public:
    ExprSimpleContext(ExprContext *ctx);

    ItemContext *item();
    VarContext *var();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprNotContext : public ExprContext {
  public:
    ExprNotContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    ExprContext *expr();
    antlr4::tree::TerminalNode *LOGNOT();
    antlr4::tree::TerminalNode *BITNOT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprBinaryContext : public ExprContext {
  public:
    ExprBinaryContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PICK();
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *DIVDIV();
    antlr4::tree::TerminalNode *REM();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *REPEAT();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *GEQ();
    antlr4::tree::TerminalNode *BITAND();
    antlr4::tree::TerminalNode *BITXOR();
    antlr4::tree::TerminalNode *BITOR();
    antlr4::tree::TerminalNode *LOGAND();
    antlr4::tree::TerminalNode *LOGANDEXT();
    antlr4::tree::TerminalNode *LOGXOR();
    antlr4::tree::TerminalNode *LOGOR();
    antlr4::tree::TerminalNode *LOGOREXT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprLvalueContext : public ExprContext {
  public:
    ExprLvalueContext(ExprContext *ctx);

    LvalueContext *lvalue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AssignmentContext() = default;
    void copyFrom(AssignmentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FakeAssignmentContext : public AssignmentContext {
  public:
    FakeAssignmentContext(AssignmentContext *ctx);

    FakeLvalueContext *fakeLvalue();
    antlr4::tree::TerminalNode *ASSIGN();
    ListContext *list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueAssignmentContext : public AssignmentContext {
  public:
    TrueAssignmentContext(AssignmentContext *ctx);

    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *ASSIGN();
    ListContext *list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AssignmentContext* assignment();

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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfthenContext : public ConditionalContext {
  public:
    IfthenContext(ConditionalContext *ctx);

    antlr4::tree::TerminalNode *IF();
    SequenceContext *sequence();
    antlr4::tree::TerminalNode *THEN();
    ListContext *list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConditionalContext* conditional();

  class  ListEndContext : public antlr4::ParserRuleContext {
  public:
    ListEndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConditionalContext *conditional();
    AssignmentContext *assignment();
    WhileloopContext *whileloop();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListEndContext* listEnd();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    EexprContext *eexpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListContext* list();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool eexprSempred(EexprContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

