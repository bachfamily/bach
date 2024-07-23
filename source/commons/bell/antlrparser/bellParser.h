
// Generated from bell.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  bellParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, RANGE = 2, UINT = 3, UFLOAT = 4, UPITCH = 5, K_PI = 6, BTSYMBOL = 7, 
    DQSYMBOL = 8, SQSYMBOL = 9, EMPTYSYMBOL = 10, BACHNULL = 11, BACHNIL = 12, 
    IF = 13, THEN = 14, ELSE = 15, WHILE = 16, FOR = 17, IN = 18, AS = 19, 
    WITH = 20, DO = 21, COLLECT = 22, INLET = 23, INTINLET = 24, RATINLET = 25, 
    FLOATINLET = 26, PITCHINLET = 27, OUTLET = 28, DIRINLET = 29, DIROUTLET = 30, 
    BIF = 31, OF = 32, GLOBALVAR = 33, PATCHERVAR = 34, LOCALVAR = 35, NAMEDPARAM = 36, 
    KEEP = 37, UNKEEP = 38, INIT = 39, ARGCOUNT = 40, PUSH = 41, POP = 42, 
    CLOSED = 43, NTH = 44, PICK = 45, KEY = 46, ANTH = 47, APICK = 48, NULLIFY = 49, 
    ASSIGN = 50, WHITESPACE = 51, NEWATOM = 52, POW = 53, APOW = 54, TIMES = 55, 
    ATIMES = 56, DIVDIV = 57, ADIVDIV = 58, DIV = 59, ADIV = 60, REM = 61, 
    AREM = 62, PLUS = 63, APLUS = 64, UPLUS = 65, MINUS = 66, AMINUS = 67, 
    UMINUS = 68, EQUAL = 69, NEQ = 70, LOGNOT = 71, BITNOT = 72, LT = 73, 
    GT = 74, LEQ = 75, GEQ = 76, BITAND = 77, ABITAND = 78, BITXOR = 79, 
    ABITXOR = 80, BITOR = 81, ABITOR = 82, LOGAND = 83, LOGANDEXT = 84, 
    ALOGAND = 85, ALOGANDEXT = 86, LOGXOR = 87, ALOGXOR = 88, LOGOR = 89, 
    ALOGOR = 90, LOGOREXT = 91, ALOGOREXT = 92, LSHIFT = 93, ALSHIFT = 94, 
    RSHIFT = 95, ARSHIFT = 96, REPEAT = 97, AREPEAT = 98, AAPPLY = 99, ACONCAT = 100, 
    ARCONCAT = 101, OPEN = 102, PARAMS = 103, FUNDEF = 104, LIFT = 105, 
    ELLIPSIS = 106, BLOCKCOMMENT = 107, LINECOMMENT = 108, ANYTHING = 109
  };

  enum {
    RuleEverything = 0, RuleProgram = 1, RuleFunarg = 2, RuleFunargList = 3, 
    RuleLiftedargList = 4, RuleFundef = 5, RuleSequence = 6, RuleNullified = 7, 
    RuleWhileloop = 8, RuleForarg = 9, RuleForargList = 10, RuleForloop = 11, 
    RuleArgsByNameList = 12, RuleArgsByPositionList = 13, RuleSimpleFuncall = 14, 
    RuleDataFlowAndLvalueSpecsUItem = 15, RuleDataFlowAndLvalueSpecsItem = 16, 
    RuleFuncall = 17, RuleVar = 18, RuleLvalueSpecsUFinal = 19, RuleLvalueSpecsFinal = 20, 
    RuleLvalueSpecs = 21, RuleLvalue = 22, RuleFakeLvalue = 23, RuleListEnd = 24, 
    RuleExpr = 25, RuleItem = 26, RuleAssignment = 27, RuleConditional = 28, 
    RuleList = 29
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
  class FunargContext;
  class FunargListContext;
  class LiftedargListContext;
  class FundefContext;
  class SequenceContext;
  class NullifiedContext;
  class WhileloopContext;
  class ForargContext;
  class ForargListContext;
  class ForloopContext;
  class ArgsByNameListContext;
  class ArgsByPositionListContext;
  class SimpleFuncallContext;
  class DataFlowAndLvalueSpecsUItemContext;
  class DataFlowAndLvalueSpecsItemContext;
  class FuncallContext;
  class VarContext;
  class LvalueSpecsUFinalContext;
  class LvalueSpecsFinalContext;
  class LvalueSpecsContext;
  class LvalueContext;
  class FakeLvalueContext;
  class ListEndContext;
  class ExprContext;
  class ItemContext;
  class AssignmentContext;
  class ConditionalContext;
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

  class  FunargContext : public antlr4::ParserRuleContext {
  public:
    FunargContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FunargContext() = default;
    void copyFrom(FunargContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunargVarContext : public FunargContext {
  public:
    FunargVarContext(FunargContext *ctx);

    antlr4::tree::TerminalNode *LOCALVAR();
    antlr4::tree::TerminalNode *ASSIGN();
    ListContext *list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunargEllipsisContext : public FunargContext {
  public:
    FunargEllipsisContext(FunargContext *ctx);

    antlr4::tree::TerminalNode *ELLIPSIS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FunargContext* funarg();

  class  FunargListContext : public antlr4::ParserRuleContext {
  public:
    FunargListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FunargContext *> funarg();
    FunargContext* funarg(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunargListContext* funargList();

  class  LiftedargListContext : public antlr4::ParserRuleContext {
  public:
    LiftedargListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIFT();
    std::vector<antlr4::tree::TerminalNode *> LOCALVAR();
    antlr4::tree::TerminalNode* LOCALVAR(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiftedargListContext* liftedargList();

  class  FundefContext : public antlr4::ParserRuleContext {
  public:
    FundefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunargListContext *funargList();
    antlr4::tree::TerminalNode *FUNDEF();
    ListContext *list();
    LiftedargListContext *liftedargList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FundefContext* fundef();

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

  class  ForargContext : public antlr4::ParserRuleContext {
  public:
    ForargContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LOCALVAR();
    antlr4::tree::TerminalNode* LOCALVAR(size_t i);
    antlr4::tree::TerminalNode *IN();
    SequenceContext *sequence();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForargContext* forarg();

  class  ForargListContext : public antlr4::ParserRuleContext {
  public:
    ForargListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ForargContext *> forarg();
    ForargContext* forarg(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForargListContext* forargList();

  class  ForloopContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *kind = nullptr;
    ForloopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    ForargListContext *forargList();
    ListContext *list();
    antlr4::tree::TerminalNode *DO();
    antlr4::tree::TerminalNode *COLLECT();
    antlr4::tree::TerminalNode *AS();
    SequenceContext *sequence();
    antlr4::tree::TerminalNode *WITH();
    ArgsByNameListContext *argsByNameList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForloopContext* forloop();

  class  ArgsByNameListContext : public antlr4::ParserRuleContext {
  public:
    ArgsByNameListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAMEDPARAM();
    antlr4::tree::TerminalNode* NAMEDPARAM(size_t i);
    std::vector<SequenceContext *> sequence();
    SequenceContext* sequence(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsByNameListContext* argsByNameList();

  class  ArgsByPositionListContext : public antlr4::ParserRuleContext {
  public:
    ArgsByPositionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SequenceContext *> sequence();
    SequenceContext* sequence(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsByPositionListContext* argsByPositionList();

  class  SimpleFuncallContext : public antlr4::ParserRuleContext {
  public:
    SimpleFuncallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARAMS();
    antlr4::tree::TerminalNode *CLOSED();
    ItemContext *item();
    VarContext *var();
    ArgsByPositionListContext *argsByPositionList();
    ArgsByNameListContext *argsByNameList();
    SimpleFuncallContext *simpleFuncall();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleFuncallContext* simpleFuncall();
  SimpleFuncallContext* simpleFuncall(int precedence);
  class  DataFlowAndLvalueSpecsUItemContext : public antlr4::ParserRuleContext {
  public:
    DataFlowAndLvalueSpecsUItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ItemContext *item();
    VarContext *var();
    SimpleFuncallContext *simpleFuncall();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataFlowAndLvalueSpecsUItemContext* dataFlowAndLvalueSpecsUItem();

  class  DataFlowAndLvalueSpecsItemContext : public antlr4::ParserRuleContext {
  public:
    DataFlowAndLvalueSpecsItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataFlowAndLvalueSpecsUItemContext *dataFlowAndLvalueSpecsUItem();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataFlowAndLvalueSpecsItemContext* dataFlowAndLvalueSpecsItem();

  class  FuncallContext : public antlr4::ParserRuleContext {
  public:
    FuncallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimpleFuncallContext *> simpleFuncall();
    SimpleFuncallContext* simpleFuncall(size_t i);
    DataFlowAndLvalueSpecsItemContext *dataFlowAndLvalueSpecsItem();
    std::vector<antlr4::tree::TerminalNode *> KEY();
    antlr4::tree::TerminalNode* KEY(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncallContext* funcall();

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
    antlr4::tree::TerminalNode *KEEP();
    antlr4::tree::TerminalNode *UNKEEP();

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

  class  LvalueSpecsUFinalContext : public antlr4::ParserRuleContext {
  public:
    LvalueSpecsUFinalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConditionalContext *conditional();
    WhileloopContext *whileloop();
    ForloopContext *forloop();
    FundefContext *fundef();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LvalueSpecsUFinalContext* lvalueSpecsUFinal();

  class  LvalueSpecsFinalContext : public antlr4::ParserRuleContext {
  public:
    LvalueSpecsFinalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LvalueSpecsUFinalContext *lvalueSpecsUFinal();
    std::vector<antlr4::tree::TerminalNode *> UPLUS();
    antlr4::tree::TerminalNode* UPLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UMINUS();
    antlr4::tree::TerminalNode* UMINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LvalueSpecsFinalContext* lvalueSpecsFinal();

  class  LvalueSpecsContext : public antlr4::ParserRuleContext {
  public:
    LvalueSpecsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DataFlowAndLvalueSpecsItemContext *> dataFlowAndLvalueSpecsItem();
    DataFlowAndLvalueSpecsItemContext* dataFlowAndLvalueSpecsItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NTH();
    antlr4::tree::TerminalNode* NTH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> KEY();
    antlr4::tree::TerminalNode* KEY(size_t i);
    LvalueSpecsFinalContext *lvalueSpecsFinal();


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

  class  ListEndContext : public antlr4::ParserRuleContext {
  public:
    ListEndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConditionalContext *conditional();
    AssignmentContext *assignment();
    WhileloopContext *whileloop();
    ForloopContext *forloop();
    FundefContext *fundef();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListEndContext* listEnd();

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
    FuncallContext *funcall();
    ListEndContext *listEnd();

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

  class  ItemUintContext : public ItemContext {
  public:
    ItemUintContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *UINT();

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

  class  ItemBIFContext : public ItemContext {
  public:
    ItemBIFContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *BIF();

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

  class  ItemPiContext : public ItemContext {
  public:
    ItemPiContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *K_PI();

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

  class  ItemOFContext : public ItemContext {
  public:
    ItemOFContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *OF();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemNullContext : public ItemContext {
  public:
    ItemNullContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *BACHNULL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemEmptySymbolContext : public ItemContext {
  public:
    ItemEmptySymbolContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *EMPTYSYMBOL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemUpitchContext : public ItemContext {
  public:
    ItemUpitchContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *UPITCH();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ItemArgcountContext : public ItemContext {
  public:
    ItemArgcountContext(ItemContext *ctx);

    antlr4::tree::TerminalNode *ARGCOUNT();

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

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AssignmentContext() = default;
    void copyFrom(AssignmentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  InitAssignmentContext : public AssignmentContext {
  public:
    InitAssignmentContext(AssignmentContext *ctx);

    antlr4::tree::TerminalNode *INIT();
    antlr4::tree::TerminalNode *LOCALVAR();
    antlr4::tree::TerminalNode *ASSIGN();
    ListContext *list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FakeAApplyContext : public AssignmentContext {
  public:
    FakeAApplyContext(AssignmentContext *ctx);

    FakeLvalueContext *fakeLvalue();
    antlr4::tree::TerminalNode *AAPPLY();
    FuncallContext *funcall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueAApplyContext : public AssignmentContext {
  public:
    TrueAApplyContext(AssignmentContext *ctx);

    LvalueContext *lvalue();
    antlr4::tree::TerminalNode *AAPPLY();
    FuncallContext *funcall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
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

  bool simpleFuncallSempred(SimpleFuncallContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

