
// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellParser : public antlr4::Parser {
public:
  enum {
    UINT = 1, UFLOAT = 2, UPITCH = 3, BTSYMBOL = 4, DQSYMBOL = 5, SQSYMBOL = 6, 
    BACHNULL = 7, BACHNIL = 8, IF = 9, THEN = 10, ELSE = 11, WHILE = 12, 
    FOR = 13, DO = 14, COLLECT = 15, FUNCTION = 16, INLET = 17, INTINLET = 18, 
    RATINLET = 19, FLOATINLET = 20, PITCHINLET = 21, OUTLET = 22, DIRINLET = 23, 
    DIROUTLET = 24, GLOBALVAR = 25, PATCHERVAR = 26, LOCALVAR = 27, NAMEDPARAM = 28, 
    PUSH = 29, POP = 30, CLOSED = 31, NTH = 32, PICK = 33, KEY = 34, ANTH = 35, 
    APICK = 36, NULLIFY = 37, ASSIGN = 38, WHITESPACE = 39, NEWATOM = 40, 
    POW = 41, APOW = 42, TIMES = 43, ATIMES = 44, DIVDIV = 45, ADIVDIV = 46, 
    DIV = 47, ADIV = 48, REM = 49, AREM = 50, PLUS = 51, APLUS = 52, UPLUS = 53, 
    MINUS = 54, AMINUS = 55, UMINUS = 56, EQUAL = 57, NEQ = 58, LOGNOT = 59, 
    BITNOT = 60, LT = 61, GT = 62, LEQ = 63, GEQ = 64, BITAND = 65, ABITAND = 66, 
    BITXOR = 67, ABITXOR = 68, BITOR = 69, ABITOR = 70, LOGAND = 71, LOGANDEXT = 72, 
    ALOGAND = 73, ALOGANDEXT = 74, LOGXOR = 75, ALOGXOR = 76, LOGOR = 77, 
    ALOGOR = 78, LOGOREXT = 79, ALOGOREXT = 80, LSHIFT = 81, ALSHIFT = 82, 
    RSHIFT = 83, ARSHIFT = 84, RANGE = 85, REPEAT = 86, AREPEAT = 87, AAPPLY = 88, 
    ACONCAT = 89, ARCONCAT = 90, OPEN = 91, PARAMS = 92, ANYTHING = 93
  };

  enum {
    RuleEverything = 0, RuleProgram = 1, RuleSequence = 2, RuleNullified = 3, 
    RuleWhileloop = 4, RuleFuncall = 5, RuleItem = 6, RuleVar = 7, RuleLvalueSpecs = 8, 
    RuleLvalue = 9, RuleFakeLvalue = 10, RuleExpr = 11, RuleAssignment = 12, 
    RuleConditional = 13, RuleListEnd = 14, RuleList = 15
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

  class  ItemBtSymbolContext : public ItemContext {
  public:
    ItemBtSymbolContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *BTSYMBOL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemInletContext : public ItemContext {
  public:
    ItemInletContext(ItemContext *ctx);

    antlr4::Token *type = nullptr;
    antlr4::tree::TerminalNode *INLET();
    antlr4::tree::TerminalNode *INTINLET();
    antlr4::tree::TerminalNode *FLOATINLET();
    antlr4::tree::TerminalNode *RATINLET();
    antlr4::tree::TerminalNode *PITCHINLET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemDirInletContext : public ItemContext {
  public:
    ItemDirInletContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *DIRINLET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemNullContext : public ItemContext {
  public:
    ItemNullContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *BACHNULL();

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

  class  ItemNilContext : public ItemContext {
  public:
    ItemNilContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *BACHNIL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemQSymbolContext : public ItemContext {
  public:
    ItemQSymbolContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *DQSYMBOL();
    antlr4::tree::TerminalNode *SQSYMBOL();

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
    ListEndContext *listEnd();
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
    ListEndContext *listEnd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprNotContext : public ExprContext {
  public:
    ExprNotContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::tree::TerminalNode *LOGNOT();
    antlr4::tree::TerminalNode *BITNOT();
    ExprContext *expr();
    ListEndContext *listEnd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprBinaryContext : public ExprContext {
  public:
    ExprBinaryContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PICK();
    ListEndContext *listEnd();
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

    antlr4::Token *op = nullptr;
    FakeLvalueContext *fakeLvalue();
    ListContext *list();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *APOW();
    antlr4::tree::TerminalNode *ATIMES();
    antlr4::tree::TerminalNode *ADIVDIV();
    antlr4::tree::TerminalNode *ADIV();
    antlr4::tree::TerminalNode *AREM();
    antlr4::tree::TerminalNode *APLUS();
    antlr4::tree::TerminalNode *AMINUS();
    antlr4::tree::TerminalNode *ALOGAND();
    antlr4::tree::TerminalNode *ALOGANDEXT();
    antlr4::tree::TerminalNode *ALOGXOR();
    antlr4::tree::TerminalNode *ALOGOR();
    antlr4::tree::TerminalNode *ALOGOREXT();
    antlr4::tree::TerminalNode *ABITAND();
    antlr4::tree::TerminalNode *ABITXOR();
    antlr4::tree::TerminalNode *ABITOR();
    antlr4::tree::TerminalNode *ALSHIFT();
    antlr4::tree::TerminalNode *ACONCAT();
    antlr4::tree::TerminalNode *ARCONCAT();
    antlr4::tree::TerminalNode *ARSHIFT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DirOutletAssignmentContext : public AssignmentContext {
  public:
    DirOutletAssignmentContext(AssignmentContext *ctx);

    antlr4::tree::TerminalNode *DIROUTLET();
    antlr4::tree::TerminalNode *ASSIGN();
    ListContext *list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueAssignmentContext : public AssignmentContext {
  public:
    TrueAssignmentContext(AssignmentContext *ctx);

    antlr4::Token *op = nullptr;
    LvalueContext *lvalue();
    ListContext *list();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *APOW();
    antlr4::tree::TerminalNode *ATIMES();
    antlr4::tree::TerminalNode *ADIVDIV();
    antlr4::tree::TerminalNode *ADIV();
    antlr4::tree::TerminalNode *AREM();
    antlr4::tree::TerminalNode *APLUS();
    antlr4::tree::TerminalNode *AMINUS();
    antlr4::tree::TerminalNode *ALOGAND();
    antlr4::tree::TerminalNode *ALOGANDEXT();
    antlr4::tree::TerminalNode *ALOGXOR();
    antlr4::tree::TerminalNode *ALOGOR();
    antlr4::tree::TerminalNode *ALOGOREXT();
    antlr4::tree::TerminalNode *ABITAND();
    antlr4::tree::TerminalNode *ABITXOR();
    antlr4::tree::TerminalNode *ABITOR();
    antlr4::tree::TerminalNode *ALSHIFT();
    antlr4::tree::TerminalNode *ARSHIFT();
    antlr4::tree::TerminalNode *ACONCAT();
    antlr4::tree::TerminalNode *ARCONCAT();
    antlr4::tree::TerminalNode *ANTH();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OutletAssignmentContext : public AssignmentContext {
  public:
    OutletAssignmentContext(AssignmentContext *ctx);

    antlr4::tree::TerminalNode *OUTLET();
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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListContext* list();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

